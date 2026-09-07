// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vvis/mpivis.cpp
// Functions: 15
// ============================================================

#include "utils\vvis\mpivis.h"

//------------------------------------------------------------------------------
// Address: 0x1000E4E0
// Name: public: double CCycleCount::GetSeconds(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CCycleCount::GetSeconds(CCycleCount *this)
{
  return (double)this->m_Int64 * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1000E520
// Name: void VMPI_DeletePortalMCSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_DeletePortalMCSocket()
{
  if ( g_hMCThread != nullptr )
  {
    CEvent::SetEvent(this: &g_MCThreadExitEvent);
    WaitForSingleObject(hHandle: g_hMCThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: g_hMCThread);
    g_hMCThread = nullptr;
  }
  if ( g_pPortalMCSocket != nullptr )
  {
    g_pPortalMCSocket->Release(this: g_pPortalMCSocket);
    g_pPortalMCSocket = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E580
// Name: void VVIS_SetupMPI(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VVIS_SetupMPI(int *argc, char ***argv)
{
  const char *v2; // eax
  const char *ParamString; // eax
  VMPIRunMode v4; // esi

  if ( VMPI_FindArg(argc: *argc, argv: *argv, pName: "-mpi", pDefault: defaultValue) != nullptr
    || (v2 = VMPI_GetParamString(eParam: mpi_Worker),
        VMPI_FindArg(argc: *argc, argv: *argv, pName: v2, pDefault: defaultValue) != nullptr) )
  {
    CmdLib_AtCleanup(pFn: VMPI_Stats_Term);
    CmdLib_AtCleanup(pFn: VMPI_DeletePortalMCSocket);
    VMPI_Stats_InstallSpewHook();
    ParamString = VMPI_GetParamString(eParam: mpi_Local);
    v4 = VMPI_FindArg(argc: *argc, argv: *argv, pName: ParamString, pDefault: defaultValue) != nullptr;
    _Msg(a1: "Initializing VMPI...\n");
    if ( !VMPI_Init(
            argc,
            argv,
            pDependencyFilename: "dependency_info_vvis.txt",
            handler: HandleMPIDisconnect,
            runMode: v4,
            bConnectingAsService: false) )
      _Error(a1: "MPI_Init failed.");
    StatsDB_InitStatsDatabase(argc: *argc, argv: *argv, pDBInfoFilename: "dbinfo_vvis.txt");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E660
// Name: void ReceiveBasePortalVis(unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReceiveBasePortalVis(unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  portal_t *v2; // esi
  unsigned int Name; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax

  v2 = &portals[iWorkUnit];
  if ( *(_QWORD *)&v2->portalfront != 0 || v2->portalvis != nullptr )
    _Msg(a1: "Duplicate portal %d\n", (_DWORD)iWorkUnit);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf);
  if ( Name - MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf) != 2 * portalbytes )
    _Error(a1: "Invalid packet in ReceiveBasePortalVis.");
  v4 = (unsigned __int8 *)malloc(size: portalbytes);
  v2->portalfront = v4;
  MessageBuffer::read(this: pBuf, p: v4, bytes: portalbytes);
  v5 = (unsigned __int8 *)malloc(size: portalbytes);
  v2->portalflood = v5;
  MessageBuffer::read(this: pBuf, p: v5, bytes: portalbytes);
  v6 = (unsigned __int8 *)malloc(size: portalbytes);
  v2->portalvis = v6;
  memset(dst: v6, value: 0, count: portalbytes);
  v2->nummightsee = CountBits(bits: v2->portalflood, numbits: 2 * g_numportals);
}

//------------------------------------------------------------------------------
// Address: 0x1000E750
// Name: void ReceivePortalFlow(unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReceivePortalFlow(unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  portal_t *v2; // esi
  void *chunks[4]; // [esp+4h] [ebp-24h] BYREF
  int chunkLengths[4]; // [esp+14h] [ebp-14h] BYREF
  char cPacketID[2]; // [esp+24h] [ebp-4h] BYREF

  v2 = sorted_portals[(_DWORD)iWorkUnit];
  if ( v2->status != stat_done )
  {
    MessageBuffer::read(this: pBuf, p: v2->portalvis, bytes: portalbytes);
    v2->status = stat_done;
    if ( g_pPortalMCSocket != nullptr )
    {
      chunks[2] = &iWorkUnit;
      chunkLengths[3] = portalbytes;
      chunks[0] = cPacketID;
      chunks[3] = v2->portalvis;
      *(_WORD *)cPacketID = 2305;
      chunks[1] = &g_PortalMCThreadUniqueID;
      chunkLengths[0] = 2;
      chunkLengths[1] = 4;
      chunkLengths[2] = 8;
      g_pPortalMCSocket->SendChunksTo(
        this: g_pPortalMCSocket,
        a2: &g_PortalMCAddr,
        a3: (const void *const *)chunks,
        a4: chunkLengths,
        a5: 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E7F0
// Name: void MCThreadCleanupFn(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MCThreadCleanupFn()
{
  CEvent::SetEvent(this: &g_MCThreadExitEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1000E800
// Name: void CheckExitedEarly(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckExitedEarly()
{
  int i; // eax
  portal_t *v1; // ecx

  if ( g_VisDistributeWorkCallbacks.m_bExitedEarly )
  {
    _Warning(a1: "\nExited early, using fastvis results...\n");
    _Warning(a1: "Exited early, using fastvis results...\n");
    for ( i = 0; i < 2 * g_numportals; ++i )
    {
      v1 = sorted_portals[i];
      if ( v1->status != stat_done )
      {
        v1->portalvis = v1->portalflood;
        sorted_portals[i]->status = stat_done;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E870
// Name: public: virtual bool CVisDistributeWorkCallbacks::Update(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVisDistributeWorkCallbacks::Update(CVisDistributeWorkCallbacks *this)
{
  int v2; // eax
  int v3; // eax
  int m_iState; // ecx
  int v5; // esi
  IScratchPad3D *v7; // edi
  winding_t *winding; // eax
  Vector v9; // [esp-Ch] [ebp-34h]
  CSPColor faceColor; // [esp+Ch] [ebp-1Ch] BYREF
  __int64 v11; // [esp+1Ch] [ebp-Ch]
  int v12; // [esp+24h] [ebp-4h]

  if ( kbhit() == 0 )
    return 0;
  v2 = getch();
  v3 = toupper(c: v2);
  m_iState = this->m_iState;
  v5 = 0;
  if ( m_iState == 0 )
  {
    if ( v3 == 77 )
    {
      this->m_iState = 1;
      _Warning(
        a1: "\n"
        "\n"
        "----------------------\n"
        "1. Write scratchpad file.\n"
        "2. Exit early and use fast vis for remaining portals.\n"
        "\n"
        "0. Exit menu.\n"
        "----------------------\n"
        "\n");
      return 0;
    }
    return 0;
  }
  if ( m_iState != 1 )
    return 0;
  if ( v3 != 49 )
  {
    if ( v3 == 50 )
    {
      this->m_bExitedEarly = true;
      return 1;
    }
    if ( v3 == 48 )
    {
      this->m_iState = 0;
      _Warning(a1: "\n\nExited menu.\n\n");
    }
    return 0;
  }
  _Warning(
    a1: "\n"
    "\n"
    "Writing scratchpad file.\n"
    "Command line: scratchpad3dviewer -file scratch.pad\n"
    "\n"
    "Red portals are the portals that are fast vis'd.\n");
  this->m_iState = 0;
  v7 = ScratchPad3D_Create(pFilename: "scratch.pad");
  if ( v7 == nullptr )
    return 0;
  faceColor.m_vColor.x = 1.0;
  faceColor.m_vColor.y = 1.0;
  faceColor.m_vColor.z = 1.0;
  faceColor.m_flAlpha = 1.0;
  ScratchPad_DrawWorld(pPad: v7, bDrawFaceNumbers: false, &faceColor);
  if ( 2 * g_numportals > 0 )
  {
    v12 = 1050253722;
    v11 = 0x3E99999A3E99999ALL;
    faceColor.m_vColor.y = 1.0;
    faceColor.m_vColor.z = 0.0;
    faceColor.m_flAlpha = 0.0;
    do
    {
      winding = sorted_portals[v5]->winding;
      *(_QWORD *)&v9.x = v11;
      v9.z = 0.30000001;
      ScratchPad_DrawWinding(
        pPad: v7,
        nPoints: winding->numpoints,
        pPoints: winding->points,
        vColor: *(Vector *)&faceColor.m_vColor.y,
        vOffset: v9);
      ++v5;
    }
    while ( v5 < 2 * g_numportals );
  }
  v7->Release(this: v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000EA00
// Name: void ProcessBasePortalVis(int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessBasePortalVis(int iThread, unsigned __int64 iPortal, MessageBuffer *pBuf)
{
  int v3; // esi
  MessageBuffer *v4; // edi
  portal_t *v5; // esi
  bool v6; // cf
  CTimeAdder adder; // [esp+4h] [ebp-14h] BYREF
  CFastTimer *p_m_Timer; // [esp+14h] [ebp-4h]

  p_m_Timer = &adder.m_Timer;
  adder.m_Timer.m_Duration.m_Int64 = __rdtsc();
  v3 = iPortal;
  BasePortalVis(iThread, portalnum: iPortal);
  v4 = pBuf;
  if ( pBuf != nullptr )
  {
    v5 = &portals[v3];
    MessageBuffer::write(this: pBuf, p: v5->portalfront, bytes: portalbytes);
    MessageBuffer::write(this: v4, p: v5->portalflood, bytes: portalbytes);
  }
  if ( &g_CPUTime != nullptr )
  {
    pBuf = (MessageBuffer *)&iPortal;
    iPortal = __rdtsc();
    adder.m_Timer.m_Duration.m_Int64 = iPortal - adder.m_Timer.m_Duration.m_Int64;
    v6 = __CFADD__(adder.m_Timer.m_Duration.m_Int64, g_CPUTime.m_Int64);
    LODWORD(g_CPUTime.m_Int64) += LODWORD(adder.m_Timer.m_Duration.m_Int64);
    HIDWORD(g_CPUTime.m_Int64) += HIDWORD(adder.m_Timer.m_Duration.m_Int64) + v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EAC0
// Name: void ProcessPortalFlow(int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessPortalFlow(int iThread, unsigned __int64 iPortal, MessageBuffer *pBuf)
{
  int v3; // esi
  bool v4; // cf
  CTimeAdder adder; // [esp+0h] [ebp-14h] BYREF
  CFastTimer *p_m_Timer; // [esp+10h] [ebp-4h]

  p_m_Timer = &adder.m_Timer;
  adder.m_Timer.m_Duration.m_Int64 = __rdtsc();
  v3 = iPortal;
  PortalFlow(iThread, portalnum: iPortal);
  if ( pBuf != nullptr )
    MessageBuffer::write(this: pBuf, p: sorted_portals[v3]->portalvis, bytes: portalbytes);
  if ( &g_CPUTime != nullptr )
  {
    pBuf = (MessageBuffer *)&iPortal;
    iPortal = __rdtsc();
    adder.m_Timer.m_Duration.m_Int64 = iPortal - adder.m_Timer.m_Duration.m_Int64;
    v4 = __CFADD__(adder.m_Timer.m_Duration.m_Int64, g_CPUTime.m_Int64);
    LODWORD(g_CPUTime.m_Int64) += LODWORD(adder.m_Timer.m_Duration.m_Int64);
    HIDWORD(g_CPUTime.m_Int64) += HIDWORD(adder.m_Timer.m_Duration.m_Int64) + v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EBD0
// Name: bool VVIS_DispatchFn(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VVIS_DispatchFn(MessageBuffer *pBuf)
{
  bool result; // al

  switch ( pBuf->data[1] )
  {
    case 3:
      goto $LN5_2;
    case 7:
      CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        this: &g_BasePortalVisResultsFilename,
        pArray: (const char *)pBuf->data + 2,
        size: strlen((const char *)pBuf->data + 2) + 1);
$LN5_2:
      result = true;
      break;
    case 0xB:
      g_bBasePortalVisSync = true;
      result = true;
      break;
    case 0xC:
      g_bPortalFlowSync = true;
      result = true;
      break;
    case 0xD:
      MessageBuffer::setOffset(this: pBuf, noffset: 2);
      MessageBuffer::read(this: pBuf, p: (void *)&g_PortalMCAddr, bytes: 6);
      g_bGotMCAddr = true;
      result = true;
      break;
    default:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC80
// Name: void RunMPIBasePortalVis(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunMPIBasePortalVis()
{
  void (*v0)(const char *, ...); // edi
  int v1; // ebx
  unsigned __int8 *m_pMemory; // esi
  unsigned int v3; // eax
  unsigned __int8 **v4; // edi
  unsigned __int8 *v5; // esi
  void *v6; // edi
  char *v7; // esi
  void *v8; // eax
  void *v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // eax
  CUtlVector<char,CUtlMemory<char,int> > allPortalData; // [esp+3Ch] [ebp-28h] BYREF
  long double elapsed; // [esp+50h] [ebp-14h]
  unsigned __int64 v14; // [esp+58h] [ebp-Ch]
  char cPacketID[2]; // [esp+60h] [ebp-4h] BYREF

  v0 = (void (*)(const char *, ...))_Msg;
  _Msg(
    a1: "\n\nportalbytes: %d\nNum Work Units: %d\nTotal data size: %d\n",
    portalbytes,
    2 * g_numportals,
    2 * portalbytes * g_numportals);
  _Msg(a1: "%-20s ", "BasePortalVis:");
  if ( g_bMPIMaster )
    StartPacifier(pPrefix: defaultValue);
  VMPI_SetCurrentStage(pCurStage: "RunMPIBasePortalVis");
  g_CPUTime.m_Int64 = 0;
  elapsed = DistributeWork(
              nWorkUnits: 2 * g_numportals,
              processFn: ProcessBasePortalVis,
              receiveFn: (void (__cdecl *)(unsigned __int64, MessageBuffer *, int))ReceiveBasePortalVis);
  v1 = 0;
  if ( g_bMPIMaster && (EndPacifier(bCarriageReturn: false), _Msg(a1: " (%d)\n", (int)elapsed), g_bMPIMaster) )
  {
    if ( !fastvis )
    {
      VMPI_SetCurrentStage(pCurStage: "SendPortalResults");
      memset(&allPortalData, 0, sizeof(allPortalData));
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&allPortalData,
        size: 4 * portalbytes * g_numportals);
      m_pMemory = (unsigned __int8 *)allPortalData.m_Memory.m_pMemory;
      if ( 2 * g_numportals > 0 )
      {
        v3 = portalbytes;
        HIDWORD(v14) = 0;
        do
        {
          v4 = (unsigned __int8 **)((char *)portals + HIDWORD(v14));
          memcpy(dst: m_pMemory, src: *(unsigned __int8 **)((char *)&portals->portalfront + HIDWORD(v14)), count: v3);
          v5 = &m_pMemory[portalbytes];
          memcpy(dst: v5, src: v4[12], count: portalbytes);
          v3 = portalbytes;
          HIDWORD(v14) += 60;
          ++v1;
          m_pMemory = &v5[portalbytes];
        }
        while ( v1 < 2 * g_numportals );
        v0 = (void (*)(const char *, ...))_Msg;
      }
      VMPI_FileSystem_CreateVirtualFile(
        pFilename: "--portal-results--",
        pData: allPortalData.m_Memory.m_pMemory,
        fileLength: allPortalData.m_Size);
      *(_WORD *)cPacketID = 1793;
      VMPI_Send2Chunks(
        pChunk1: cPacketID,
        chunk1Len: 2,
        pChunk2: "--portal-results--",
        chunk2Len: 19,
        iDest: -3,
        fVMPISendFlags: 0);
      CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&allPortalData);
    }
  }
  else
  {
    VMPI_SetCurrentStage(pCurStage: "RecvPortalResults");
    while ( g_BasePortalVisResultsFilename.m_Size == 0 )
      VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
    v6 = g_pFileSystem->Open(
           this: g_pFileSystem,
           a2: g_BasePortalVisResultsFilename.m_Memory.m_pMemory,
           a3: "rb",
           a4: "VMPI_VIRTUAL_FILES_PATH_ID");
    if ( v6 == nullptr )
      _Error(a1: "Can't open '%s' to read portal info.", g_BasePortalVisResultsFilename.m_Memory.m_pMemory);
    if ( 2 * g_numportals > 0 )
    {
      HIDWORD(v14) = 0;
      do
      {
        v7 = (char *)portals + HIDWORD(v14);
        v8 = malloc(size: portalbytes);
        *((_DWORD *)v7 + 11) = v8;
        g_pFileSystem->Read(this: g_pFileSystem, a2: v8, a3: portalbytes, a4: v6);
        v9 = malloc(size: portalbytes);
        *((_DWORD *)v7 + 12) = v9;
        g_pFileSystem->Read(this: g_pFileSystem, a2: v9, a3: portalbytes, a4: v6);
        v10 = (unsigned __int8 *)malloc(size: portalbytes);
        *((_DWORD *)v7 + 13) = v10;
        memset(dst: v10, value: 0, count: portalbytes);
        v11 = CountBits(bits: *((unsigned __int8 **)v7 + 12), numbits: 2 * g_numportals);
        HIDWORD(v14) += 60;
        *((_DWORD *)v7 + 14) = v11;
        ++v1;
      }
      while ( v1 < 2 * g_numportals );
    }
    g_pFileSystem->Close(this: g_pFileSystem, a2: v6);
    v0 = (void (*)(const char *, ...))_Msg;
  }
  if ( !g_bMPIMaster && g_iVMPIVerboseLevel >= 1 )
  {
    v14 = g_CPUTime.m_Int64 & 0x8000000000000000uLL;
    v0(
      a1: "\n%% worker CPU utilization during BasePortalVis: %.1f\n",
      (double)((double)g_CPUTime.m_Int64 * _g_ClockSpeedSecondsMultiplier * 100.0 / elapsed / (double)(int)numthreads));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EFE0
// Name: unsigned long PortalMCThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall PortalMCThreadFn(void *p)
{
  DWORD v1; // ebx
  char *m_pMemory; // edi
  signed int v3; // esi
  void *UserData; // eax
  int v5; // eax
  int v6; // eax
  portal_t *v7; // esi
  void *v8; // eax
  CUtlVector<char,CUtlMemory<char,int> > data; // [esp+Ch] [ebp-1Ch] BYREF
  CIPAddr ipFrom; // [esp+20h] [ebp-8h] BYREF

  v1 = 0;
  m_pMemory = nullptr;
  v3 = portalbytes + 128;
  memset(&data, 0, sizeof(data));
  if ( portalbytes != -128 )
  {
    if ( (int)(portalbytes + 128) > 0 )
    {
      CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&data, num: portalbytes + 128);
      m_pMemory = data.m_Memory.m_pMemory;
    }
    data.m_Size += v3;
    data.m_pElements = m_pMemory;
    if ( data.m_Size - v3 > 0 && v3 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v3], src: m_pMemory, count: data.m_Size - v3);
      v1 = 0;
    }
  }
  UserData = CTCPPacket::GetUserData(this: &g_MCThreadExitEvent);
  if ( WaitForSingleObject(hHandle: UserData, dwMilliseconds: 0) != 0 )
  {
    do
    {
      CIPAddr::CIPAddr(this: &ipFrom);
      v5 = g_pPortalMCSocket->RecvFrom(this: g_pPortalMCSocket, a2: m_pMemory, a3: data.m_Size, a4: &ipFrom);
      if ( v5 == -1 )
      {
        v1 = 20;
      }
      else if ( v5 == portalbytes + 10
             && *m_pMemory == 1
             && m_pMemory[1] == 9
             && *(_DWORD *)(m_pMemory + 2) == g_PortalMCThreadUniqueID )
      {
        v6 = *(_DWORD *)(m_pMemory + 6);
        if ( v6 >= 0 && v6 < 2 * g_numportals )
        {
          v7 = sorted_portals[v6];
          if ( v7 != nullptr )
          {
            ++g_nMulticastPortalsReceived;
            memcpy(dst: v7->portalvis, src: (unsigned __int8 *)m_pMemory + 10, count: portalbytes);
            v7->status = stat_done;
            v1 = 0;
          }
        }
      }
      v8 = CTCPPacket::GetUserData(this: &g_MCThreadExitEvent);
    }
    while ( WaitForSingleObject(hHandle: v8, dwMilliseconds: v1) != 0 );
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&data);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F110
// Name: void RunMPIPortalFlow(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunMPIPortalFlow()
{
  void (*v0)(const char *, ...); // esi
  IUniformRandomStream *v1; // ecx
  IUniformRandomStream *v2; // ecx
  IUniformRandomStream *v3; // ecx
  IUniformRandomStream *v4; // ecx
  int i; // ebx
  ISocket_vtbl *v6; // esi
  int v7; // eax
  const CIPAddr *v8; // eax
  unsigned __int64 v9; // [esp-4h] [ebp-2BCh]
  char err[512]; // [esp+10h] [ebp-2A8h] BYREF
  CUniformRandomStream randomStream; // [esp+210h] [ebp-A8h] BYREF
  long double dwDummy; // [esp+2A4h] [ebp-14h] BYREF
  CCycleCount cnt; // [esp+2ACh] [ebp-Ch] BYREF
  char cPacketID[2]; // [esp+2B4h] [ebp-4h] BYREF

  v0 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "%-20s ", "MPIPortalFlow:");
  if ( g_bMPIMaster )
    StartPacifier(pPrefix: defaultValue);
  g_PortalMCThreadUniqueID = StatsDB_GetUniqueJobID();
  if ( g_bMPIMaster )
  {
    HIDWORD(dwDummy) = &cnt;
    cnt.m_Int64 = __rdtsc();
    CUniformRandomStream::CUniformRandomStream(this: &randomStream);
    HIDWORD(v9) = HIDWORD(_g_ClockSpeed);
    LODWORD(v9) = _g_ClockSpeed;
    CUniformRandomStream::SetSeed(this: &randomStream, a2: 1000000 * cnt.m_Int64 / v9);
    g_PortalMCAddr.port = CUniformRandomStream::RandomInt(this: &randomStream, a2: 22000, a3: 25000);
    g_PortalMCAddr.ip[0] = _RandomInt(this: v1, a2: 225, a3: 238);
    g_PortalMCAddr.ip[1] = _RandomInt(this: v2, a2: 0, a3: 255);
    g_PortalMCAddr.ip[2] = _RandomInt(this: v3, a2: 0, a3: 255);
    g_PortalMCAddr.ip[3] = _RandomInt(this: v4, a2: 3, a3: 255);
    g_pPortalMCSocket = CreateIPSocket();
    for ( i = 0; i < 5; ++i )
    {
      v6 = g_pPortalMCSocket->__vftable;
      v7 = CUniformRandomStream::RandomInt(this: &randomStream, a2: 20000, a3: 30000);
      if ( v6->BindToAny(this: g_pPortalMCSocket, a2: v7) )
        break;
    }
    if ( i == 5 )
      _Error(a1: "RunMPIPortalFlow: can't open a socket to multicast on.");
    *(_WORD *)cPacketID = 3329;
    VMPI_Send2Chunks(
      pChunk1: cPacketID,
      chunk1Len: 2,
      pChunk2: &g_PortalMCAddr,
      chunk2Len: 6,
      iDest: -3,
      fVMPISendFlags: 0);
    v0 = (void (*)(const char *, ...))_Msg;
  }
  else
  {
    VMPI_SetCurrentStage(pCurStage: "wait for MC address");
    while ( !g_bGotMCAddr )
      VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
    v8 = CIPAddr::CIPAddr(this: (CIPAddr *)((char *)&cnt.m_Int64 + 2));
    g_pPortalMCSocket = CreateMulticastListenSocket(addr: &g_PortalMCAddr, localInterface: v8);
    if ( g_pPortalMCSocket == nullptr )
    {
      IP_GetLastErrorString(pStr: err, maxLen: 512);
      _Error(a1: "RunMPIPortalFlow: CreateMulticastListenSocket failed. (%s).", err);
    }
    HIDWORD(dwDummy) = 0;
    CEvent::Init(this: &g_MCThreadExitEvent, bManualReset: false, bInitialState: false);
    CmdLib_AtCleanup(pFn: MCThreadCleanupFn);
    g_hMCThread = CreateThread(
                    lpThreadAttributes: nullptr,
                    dwStackSize: 0,
                    lpStartAddress: PortalMCThreadFn,
                    lpParameter: nullptr,
                    dwCreationFlags: 0,
                    lpThreadId: (LPDWORD)&dwDummy + 1);
    if ( g_hMCThread == nullptr )
      _Error(a1: "RunMPIPortalFlow: CreateThread failed for multicast receive thread.");
  }
  VMPI_SetCurrentStage(pCurStage: "RunMPIBasePortalFlow");
  g_pDistributeWorkCallbacks = &g_VisDistributeWorkCallbacks;
  g_CPUTime.m_Int64 = 0;
  dwDummy = DistributeWork(
              nWorkUnits: 2 * g_numportals,
              processFn: ProcessPortalFlow,
              receiveFn: (void (__cdecl *)(unsigned __int64, MessageBuffer *, int))ReceivePortalFlow);
  g_pDistributeWorkCallbacks = nullptr;
  CheckExitedEarly();
  if ( g_hMCThread != nullptr )
  {
    CEvent::SetEvent(this: &g_MCThreadExitEvent);
    WaitForSingleObject(hHandle: g_hMCThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: g_hMCThread);
    g_hMCThread = nullptr;
  }
  if ( g_pPortalMCSocket != nullptr )
  {
    g_pPortalMCSocket->Release(this: g_pPortalMCSocket);
    g_pPortalMCSocket = nullptr;
  }
  if ( g_bMPIMaster )
    goto LABEL_24;
  if ( g_iVMPIVerboseLevel >= 1 )
  {
    v0(a1: "Received %d (out of %d) portals from multicast.\n", g_nMulticastPortalsReceived, 2 * g_numportals);
    cnt.m_Int64 = g_CPUTime.m_Int64 & 0x8000000000000000uLL;
    v0(
      a1: "%.1f%% CPU utilization during PortalFlow\n",
      (double)((double)g_CPUTime.m_Int64 * _g_ClockSpeedSecondsMultiplier * 100.0 / dwDummy / (double)(int)numthreads));
  }
  v0(a1: "VVIS worker finished. Over and out.\n");
  VMPI_SetCurrentStage(pCurStage: "worker done");
  _Plat_ExitProcess(a1: 0);
  if ( g_bMPIMaster )
  {
LABEL_24:
    EndPacifier(bCarriageReturn: false);
    v0(a1: " (%d)\n", (int)dwDummy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100315B0
// Name: public: virtual void IWorkUnitDistributorCallbacks::OnWorkUnitsCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IWorkUnitDistributorCallbacks::OnWorkUnitsCompleted(
        CDistributor_DefaultWorker *this,
        unsigned __int64 iWU)
{
  ;
}
