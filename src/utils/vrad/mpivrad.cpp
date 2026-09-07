// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/mpivrad.cpp
// Functions: 19
// ============================================================

#include "utils\vrad\mpivrad.h"

//------------------------------------------------------------------------------
// Address: 0x10013AE0
// Name: public: double CCycleCount::GetSeconds(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CCycleCount::GetSeconds(CCycleCount *this)
{
  return (double)this->m_Int64 * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x10013B20
// Name: void VRAD_SetupMPI(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VRAD_SetupMPI(int *argc, char ***argv)
{
  const char *v2; // eax
  const char *ParamString; // eax
  VMPIRunMode v4; // esi

  CmdLib_AtCleanup(pFn: VMPI_Stats_Term);
  if ( VMPI_FindArg(argc: *argc, argv: *argv, pName: "-mpi", pDefault: defaultValue) != nullptr
    || (v2 = VMPI_GetParamString(eParam: mpi_Worker),
        VMPI_FindArg(argc: *argc, argv: *argv, pName: v2, pDefault: defaultValue) != nullptr) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_Local);
    v4 = VMPI_FindArg(argc: *argc, argv: *argv, pName: ParamString, pDefault: defaultValue) != nullptr;
    VMPI_Stats_InstallSpewHook();
    _Msg(a1: "Initializing VMPI...\n");
    if ( !VMPI_Init(
            argc,
            argv,
            pDependencyFilename: "dependency_info_vrad.txt",
            handler: HandleMPIDisconnect,
            runMode: v4,
            bConnectingAsService: false) )
      _Error(a1: "MPI_Init failed.");
    StatsDB_InitStatsDatabase(argc: *argc, argv: *argv, pDBInfoFilename: "dbinfo_vrad.txt");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013BF0
// Name: void MPI_AddPatchData(int,int,struct CPatch __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MPI_AddPatchData(int iThread, int patchnum, CPatch *patch)
{
  MessageBuffer *m_pVisLeafsMB; // ecx
  CVMPIVisLeafsData *v4; // esi
  CPatch *v5; // ebx
  int *p_numtransfers; // edi

  m_pVisLeafsMB = g_VMPIVisLeafsData[iThread].m_pVisLeafsMB;
  v4 = &g_VMPIVisLeafsData[iThread];
  if ( m_pVisLeafsMB != nullptr )
  {
    ++v4->m_nPatchesInCluster;
    MessageBuffer::write(this: m_pVisLeafsMB, p: &patchnum, bytes: 4);
    v5 = patch;
    p_numtransfers = &patch->numtransfers;
    MessageBuffer::write(this: v4->m_pVisLeafsMB, p: &patch->numtransfers, bytes: 4);
    MessageBuffer::write(this: v4->m_pVisLeafsMB, p: v5->transfers, bytes: 8 * *p_numtransfers);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013C50
// Name: void SerializeFace(class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SerializeFace(MessageBuffer *pmb, int facenum)
{
  facelight_t *v2; // esi
  const void **v3; // edi
  Vector *luxel; // ecx
  Vector *luxelNormals; // eax
  int i; // [esp+Ch] [ebp-4h]
  int facenuma; // [esp+1Ch] [ebp+Ch]

  v2 = &facelight[facenum];
  MessageBuffer::write(this: pmb, p: &g_pFaces[facenum], bytes: 56);
  MessageBuffer::write(this: pmb, p: v2, bytes: 88);
  MessageBuffer::write(this: pmb, p: v2->sample, bytes: v2->numsamples << 6);
  v3 = (const void **)v2->light[0];
  for ( i = 4; i != 0; --i )
  {
    for ( facenuma = 4; facenuma != 0; --facenuma )
    {
      if ( *v3 != nullptr )
        MessageBuffer::write(this: pmb, p: *v3, bytes: 16 * v2->numsamples);
      ++v3;
    }
  }
  luxel = v2->luxel;
  if ( luxel != nullptr )
    MessageBuffer::write(this: pmb, p: luxel, bytes: 12 * v2->numluxels);
  luxelNormals = v2->luxelNormals;
  if ( luxelNormals != nullptr )
    MessageBuffer::write(this: pmb, p: luxelNormals, bytes: 12 * v2->numluxels);
}

//------------------------------------------------------------------------------
// Address: 0x10013D20
// Name: void UnSerializeFace(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnSerializeFace(MessageBuffer *pmb, int facenum, int iSource)
{
  facelight_t *v3; // edi
  const char *MachineName; // eax
  const char *v5; // eax
  int numsamples; // ebx
  unsigned __int8 *v7; // eax
  const char *v8; // eax
  unsigned __int8 **light; // ebx
  unsigned __int8 *v10; // eax
  const char *v11; // eax
  unsigned int numluxels; // ebx
  unsigned __int8 *v13; // eax
  const char *v14; // eax
  unsigned int v15; // ebx
  unsigned __int8 *v16; // eax
  const char *v17; // eax
  int v18; // [esp-Ch] [ebp-1Ch]
  int Name; // [esp-8h] [ebp-18h]
  int v20; // [esp-8h] [ebp-18h]
  unsigned int v21; // [esp-8h] [ebp-18h]
  int v22; // [esp-8h] [ebp-18h]
  int v23; // [esp-8h] [ebp-18h]
  int v24; // [esp-8h] [ebp-18h]
  unsigned int Offset; // [esp-4h] [ebp-14h]
  unsigned int v26; // [esp-4h] [ebp-14h]
  int v27; // [esp-4h] [ebp-14h]
  unsigned int v28; // [esp-4h] [ebp-14h]
  unsigned int v29; // [esp-4h] [ebp-14h]
  unsigned int v30; // [esp-4h] [ebp-14h]
  int i; // [esp+Ch] [ebp-4h]
  int facenuma; // [esp+1Ch] [ebp+Ch]

  v3 = &facelight[facenum];
  if ( MessageBuffer::read(this: pmb, p: &g_pFaces[facenum], bytes: 56) < 0 )
  {
    Offset = MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pmb);
    Name = ConCommandBase::GetName(this: (CVTFTexture *)pmb);
    MachineName = VMPI_GetMachineName(iProc: iSource);
    _Error(a1: "UnSerializeFace - invalid dface_t from %s (mb len: %d, offset: %d)", MachineName, Name, Offset);
  }
  if ( MessageBuffer::read(this: pmb, p: v3, bytes: 88) < 0 )
  {
    v26 = MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pmb);
    v20 = ConCommandBase::GetName(this: (CVTFTexture *)pmb);
    v5 = VMPI_GetMachineName(iProc: iSource);
    _Error(a1: "UnSerializeFace - invalid facelight_t from %s (mb len: %d, offset: %d)", v5, v20, v26);
  }
  numsamples = v3->numsamples;
  v7 = calloc(count: v3->numsamples, size: 0x40u);
  v3->sample = (sample_t *)v7;
  if ( MessageBuffer::read(this: pmb, p: v7, bytes: numsamples << 6) < 0 )
  {
    v27 = v3->numsamples;
    v21 = MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pmb);
    v18 = ConCommandBase::GetName(this: (CVTFTexture *)pmb);
    v8 = VMPI_GetMachineName(iProc: iSource);
    _Error(
      a1: "UnSerializeFace - invalid sample_t from %s (mb len: %d, offset: %d, fl->numsamples: %d)",
      v8,
      v18,
      v21,
      v27);
  }
  light = (unsigned __int8 **)v3->light;
  for ( i = 4; i != 0; --i )
  {
    for ( facenuma = 4; facenuma != 0; --facenuma )
    {
      if ( *light != nullptr )
      {
        v10 = calloc(count: v3->numsamples, size: 0x10u);
        *light = v10;
        if ( MessageBuffer::read(this: pmb, p: v10, bytes: 16 * v3->numsamples) < 0 )
        {
          v28 = MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pmb);
          v22 = ConCommandBase::GetName(this: (CVTFTexture *)pmb);
          v11 = VMPI_GetMachineName(iProc: iSource);
          _Error(a1: "UnSerializeFace - invalid fl->light from %s (mb len: %d, offset: %d)", v11, v22, v28);
        }
      }
      ++light;
    }
  }
  if ( v3->luxel != nullptr )
  {
    numluxels = v3->numluxels;
    v13 = calloc(count: numluxels, size: 0xCu);
    v3->luxel = (Vector *)v13;
    if ( MessageBuffer::read(this: pmb, p: v13, bytes: 12 * numluxels) < 0 )
    {
      v29 = MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pmb);
      v23 = ConCommandBase::GetName(this: (CVTFTexture *)pmb);
      v14 = VMPI_GetMachineName(iProc: iSource);
      _Error(a1: "UnSerializeFace - invalid fl->luxel from %s (mb len: %d, offset: %d)", v14, v23, v29);
    }
  }
  if ( v3->luxelNormals != nullptr )
  {
    v15 = v3->numluxels;
    v16 = calloc(count: v15, size: 0xCu);
    v3->luxelNormals = (Vector *)v16;
    if ( MessageBuffer::read(this: pmb, p: v16, bytes: 12 * v15) < 0 )
    {
      v30 = MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pmb);
      v24 = ConCommandBase::GetName(this: (CVTFTexture *)pmb);
      v17 = VMPI_GetMachineName(iProc: iSource);
      _Error(a1: "UnSerializeFace - invalid fl->luxelNormals from %s (mb len: %d, offset: %d)", v17, v24, v30);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013F40
// Name: void MPI_ReceiveFaceResults(unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MPI_ReceiveFaceResults(unsigned __int64 iWorkUnit, MessageBuffer *pBuf, int iWorker)
{
  UnSerializeFace(pmb: pBuf, facenum: iWorkUnit, iSource: iWorker);
}

//------------------------------------------------------------------------------
// Address: 0x10013FF0
// Name: void MPI_ReceiveVisLeafsResults(unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MPI_ReceiveVisLeafsResults(unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  int v2; // ebx
  CPatch *v3; // esi
  int v4; // eax
  transfer_t *v5; // eax
  int patchnum; // [esp+8h] [ebp-Ch] BYREF
  int patchesInCluster; // [esp+Ch] [ebp-8h] BYREF
  int numtransfers; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  patchesInCluster = 0;
  MessageBuffer::read(this: pBuf, p: &patchesInCluster, bytes: 4);
  if ( patchesInCluster > 0 )
  {
    do
    {
      patchnum = 0;
      MessageBuffer::read(this: pBuf, p: &patchnum, bytes: 4);
      v3 = &g_Patches.m_Memory.m_pMemory[patchnum];
      MessageBuffer::read(this: pBuf, p: &numtransfers, bytes: 4);
      v3->numtransfers = numtransfers;
      v4 = numtransfers;
      if ( numtransfers != 0 )
      {
        v5 = (transfer_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)numtransfers >> 29 != 0 ? -1 : 8 * numtransfers);
        v3->transfers = v5;
        MessageBuffer::read(this: pBuf, p: v5, bytes: 8 * numtransfers);
        v4 = numtransfers;
      }
      total_transfer += v4;
      if ( max_transfer < v4 )
        max_transfer = v4;
      ++v2;
    }
    while ( v2 < patchesInCluster );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100140B0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100140F0
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014130
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (unsigned int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: (unsigned int *)&src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100141A0
// Name: public: char CUtlBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100141D0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014220
// Name: void MPI_ProcessFaces(int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MPI_ProcessFaces(int iThread, unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  int v3; // esi
  bool v4; // cf
  CTimeAdder adder; // [esp+0h] [ebp-14h] BYREF
  CFastTimer *p_m_Timer; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  p_m_Timer = &adder.m_Timer;
  adder.m_Timer.m_Duration.m_Int64 = __rdtsc();
  v3 = iWorkUnit;
  BuildFacelights(a1: (dface_t *)&savedregs, iThread, facenum: iWorkUnit);
  if ( pBuf != nullptr )
    SerializeFace(pmb: pBuf, facenum: v3);
  if ( &g_CPUTime != nullptr )
  {
    pBuf = (MessageBuffer *)&iWorkUnit;
    iWorkUnit = __rdtsc();
    adder.m_Timer.m_Duration.m_Int64 = iWorkUnit - adder.m_Timer.m_Duration.m_Int64;
    v4 = __CFADD__(adder.m_Timer.m_Duration.m_Int64, g_CPUTime.m_Int64);
    LODWORD(g_CPUTime.m_Int64) += LODWORD(adder.m_Timer.m_Duration.m_Int64);
    HIDWORD(g_CPUTime.m_Int64) += HIDWORD(adder.m_Timer.m_Duration.m_Int64) + v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100142B0
// Name: void RunMPIBuildFacelights(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunMPIBuildFacelights()
{
  int i; // esi
  double v1; // [esp-4h] [ebp-18h]
  double elapsed; // [esp+4h] [ebp-10h]

  g_CPUTime.m_Int64 = 0;
  _Msg(a1: "%-20s ", "BuildFaceLights:");
  if ( g_bMPIMaster )
    StartPacifier(pPrefix: defaultValue);
  VMPI_SetCurrentStage(pCurStage: "RunMPIBuildFaceLights");
  elapsed = DistributeWork(nWorkUnits: (int)numfaces, processFn: MPI_ProcessFaces, receiveFn: MPI_ReceiveFaceResults);
  if ( g_bMPIMaster && (EndPacifier(bCarriageReturn: false), _Msg(a1: " (%d)\n", (int)elapsed), g_bMPIMaster) )
  {
    for ( i = 0; i < (int)numfaces; ++i )
      BuildPatchLights(facenum: i);
  }
  else if ( g_iVMPIVerboseLevel >= 1 )
  {
    LODWORD(v1) = (int)((double)g_CPUTime.m_Int64 * _g_ClockSpeedSecondsMultiplier * 100.0 / elapsed);
    _Msg(a1: "\n\n%.1f%% CPU utilization during BuildFaceLights\n\n", v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100143C0
// Name: void MPI_ProcessVisLeafs(int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MPI_ProcessVisLeafs(int iThread, unsigned __int64 iWorkUnit, CVTFTexture *pBuf)
{
  int v3; // eax
  CVMPIVisLeafsData *v5; // edi
  bool v6; // cf
  CTimeAdder adder; // [esp+8h] [ebp-14h] BYREF
  CFastTimer *p_m_Timer; // [esp+18h] [ebp-4h]
  int iSavePos; // [esp+30h] [ebp+14h]

  p_m_Timer = &adder.m_Timer;
  adder.m_Timer.m_Duration.m_Int64 = __rdtsc();
  v3 = iThread;
  v5 = &g_VMPIVisLeafsData[iThread];
  v5->m_nPatchesInCluster = 0;
  v5->m_pVisLeafsMB = (MessageBuffer *)pBuf;
  iSavePos = 0;
  if ( pBuf != nullptr )
  {
    iSavePos = ConCommandBase::GetName(this: pBuf);
    MessageBuffer::write(this: (MessageBuffer *)pBuf, p: &v5->m_nPatchesInCluster, bytes: 4);
    v3 = iThread;
  }
  BuildVisLeafs_Cluster(
    threadnum: v3,
    transfers: v5->m_pBuildVisLeafsTransfers,
    iCluster: iWorkUnit,
    PatchCB: MPI_AddPatchData);
  if ( pBuf != nullptr )
  {
    MessageBuffer::update(this: (MessageBuffer *)pBuf, loc: iSavePos, p: &v5->m_nPatchesInCluster, bytes: 4);
    v5->m_pVisLeafsMB = nullptr;
  }
  if ( &g_CPUTime != nullptr )
  {
    adder.m_Timer.m_Duration.m_Int64 = __rdtsc() - adder.m_Timer.m_Duration.m_Int64;
    v6 = __CFADD__(adder.m_Timer.m_Duration.m_Int64, g_CPUTime.m_Int64);
    LODWORD(g_CPUTime.m_Int64) += LODWORD(adder.m_Timer.m_Duration.m_Int64);
    HIDWORD(g_CPUTime.m_Int64) += HIDWORD(adder.m_Timer.m_Duration.m_Int64) + v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100144A0
// Name: void RunMPIBuildVisLeafs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunMPIBuildVisLeafs()
{
  signed int v0; // edi
  _DWORD *v1; // esi
  signed int v2; // esi
  transfer_t **v3; // edi
  double elapsed; // [esp+Ch] [ebp-10h]

  g_CPUTime.m_Int64 = 0;
  _Msg(a1: "%-20s ", "BuildVisLeafs  :");
  if ( g_bMPIMaster )
    StartPacifier(pPrefix: defaultValue);
  memset(dst: (unsigned __int8 *)g_VMPIVisLeafsData, value: 0, count: sizeof(g_VMPIVisLeafsData));
  if ( !g_bMPIMaster || VMPI_GetActiveWorkUnitDistributor() == k_eWorkUnitDistributor_SDK )
  {
    v0 = 0;
    if ( (int)numthreads > 0 )
    {
      v1 = &unk_111CF4A0;
      do
      {
        *v1 = BuildVisLeafs_Start();
        ++v0;
        v1 += 3;
      }
      while ( v0 < (int)numthreads );
    }
  }
  VMPI_SetCurrentStage(pCurStage: "RunMPIBuildVisLeafs");
  v2 = 0;
  elapsed = DistributeWork(
              nWorkUnits: dvis->numclusters,
              processFn: (void (__cdecl *)(int, unsigned __int64, MessageBuffer *))MPI_ProcessVisLeafs,
              receiveFn: (void (__cdecl *)(unsigned __int64, MessageBuffer *, int))MPI_ReceiveVisLeafsResults);
  if ( (int)numthreads > 0 )
  {
    v3 = (transfer_t **)&unk_111CF4A0;
    do
    {
      if ( *v3 != nullptr )
        BuildVisLeafs_End(transfers: *v3);
      ++v2;
      v3 += 3;
    }
    while ( v2 < (int)numthreads );
  }
  if ( g_bMPIMaster )
  {
    EndPacifier(bCarriageReturn: false);
    _Msg(a1: " (%d)\n", (int)elapsed);
  }
  else if ( g_iVMPIVerboseLevel >= 1 )
  {
    _Msg(
      a1: "%.1f%% CPU utilization during PortalFlow\n",
      (double)((double)g_CPUTime.m_Int64 * _g_ClockSpeedSecondsMultiplier * 100.0 / elapsed / (double)(int)numthreads));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014610
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned int *)&i,
          inputBuffer: (unsigned int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014710
// Name: void VMPI_DistributeLightData(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VMPI_DistributeLightData(int a1@<edi>)
{
  int v1; // edi
  int j; // esi
  unsigned __int8 v3; // bl
  int lightofs; // esi
  void *v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // ebx
  int v9; // ebx
  int v10; // edi
  int k; // esi
  unsigned __int8 v12; // al
  CUtlBuffer faceData; // [esp+0h] [ebp-3Ch] BYREF
  unsigned int inputBuffer; // [esp+30h] [ebp-Ch] BYREF
  int i; // [esp+34h] [ebp-8h]
  char cPacketID[2]; // [esp+38h] [ebp-4h] BYREF

  if ( !g_bUseMPI )
    return;
  if ( g_bMPIMaster )
  {
    v1 = 0;
    CUtlBuffer::CUtlBuffer(this: &faceData, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::EnsureCapacity(this: &faceData, num: pdlightdata->m_Size + 8 * numfaces);
    _V_memcpy(
      dest: &faceData.m_Memory.m_pMemory[faceData.m_Put - faceData.m_nOffset],
      src: pdlightdata->m_Memory.m_pMemory,
      count: pdlightdata->m_Size);
    CUtlBuffer::SeekPut(this: &faceData, type: SEEK_HEAD, offset: pdlightdata->m_Size);
    for ( i = 0; i < (int)numfaces; ++i )
    {
      for ( j = 0; j < 4; ++j )
      {
        v3 = g_pFaces[v1].styles[j];
        if ( (faceData.m_Flags & 1) != 0
          && faceData.m_Put != 0
          && faceData.m_Memory.m_pMemory[faceData.m_Put - faceData.m_nOffset - 1] == 10 )
        {
          CUtlBuffer::PutTabs(this: &faceData);
        }
        if ( CUtlBuffer::CheckPut(this: &faceData, nSize: 1) )
        {
          faceData.m_Memory.m_pMemory[faceData.m_Put - faceData.m_nOffset] = v3;
          CUtlBuffer::AddNullTermination(this: &faceData, nPut: ++faceData.m_Put);
        }
      }
      lightofs = g_pFaces[v1].lightofs;
      if ( (faceData.m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: &faceData, pFmt: "%d", g_pFaces[v1].lightofs);
      }
      else
      {
        inputBuffer = g_pFaces[v1].lightofs;
        if ( CUtlBuffer::CheckPut(this: &faceData, nSize: 4) )
        {
          if ( (*(_BYTE *)&faceData.m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: &faceData.m_Byteswap,
              outputBuffer: (unsigned int *)&faceData.m_Memory.m_pMemory[faceData.m_Put - faceData.m_nOffset],
              &inputBuffer,
              count: 1);
          else
            *(_DWORD *)&faceData.m_Memory.m_pMemory[faceData.m_Put - faceData.m_nOffset] = lightofs;
          faceData.m_Put += 4;
          CUtlBuffer::AddNullTermination(this: &faceData, nPut: faceData.m_Put);
        }
      }
      ++v1;
    }
    VMPI_FileSystem_CreateVirtualFile(
      pFilename: "--plightdata--",
      pData: faceData.m_Memory.m_pMemory,
      fileLength: faceData.m_nMaxPut);
    *(_WORD *)cPacketID = 513;
    VMPI_Send2Chunks(
      pChunk1: cPacketID,
      chunk1Len: 2,
      pChunk2: "--plightdata--",
      chunk2Len: 15,
      iDest: -3,
      fVMPISendFlags: 0);
LABEL_34:
    if ( faceData.m_Memory.m_nGrowSize >= 0 && faceData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceData.m_Memory.m_pMemory);
    return;
  }
  VMPI_SetCurrentStage(pCurStage: "VMPI_DistributeLightData");
  while ( g_LightResultsFilename.m_Size == 0 )
    VMPI_DispatchNextMessage(timeout: 0xFFFFFFFF);
  v5 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, const char *, int))g_pFileSystem->Open)(
                 a1: g_pFileSystem,
                 a2: g_LightResultsFilename.m_Memory.m_pMemory,
                 a3: "rb",
                 a4: "VMPI_VIRTUAL_FILES_PATH_ID",
                 a5: a1);
  if ( v5 == nullptr )
    _Error(a1: "Can't open '%s' to read lighting info.", g_LightResultsFilename.m_Memory.m_pMemory);
  v6 = ((int (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Size_2)(a1: g_pFileSystem);
  v7 = 8 * numfaces;
  if ( v6 > 8 * (int)numfaces )
  {
    v8 = v6 - v7;
    CUtlBuffer::CUtlBuffer(this: &faceData, growSize: 0, initSize: 0, nFlags: 0);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::EnsureCount(this: pdlightdata, num: v8);
    CUtlBuffer::EnsureCapacity(this: &faceData, num: v7);
    g_pFileSystem->Read(this: g_pFileSystem, a2: pdlightdata->m_Memory.m_pMemory, a3: v8, a4: v5);
    g_pFileSystem->Read(this: g_pFileSystem, a2: faceData.m_Memory.m_pMemory, a3: v7, a4: v5);
    g_pFileSystem->Close(this: g_pFileSystem, a2: v5);
    CUtlBuffer::SeekPut(this: &faceData, type: SEEK_HEAD, offset: v7);
    v9 = 0;
    if ( (int)numfaces > 0 )
    {
      v10 = 0;
      do
      {
        for ( k = 0; k < 4; ++k )
        {
          if ( CUtlBuffer::CheckGet(this: &faceData, nSize: 1) )
          {
            v12 = faceData.m_Memory.m_pMemory[faceData.m_Get - faceData.m_nOffset];
            ++faceData.m_Get;
          }
          else
          {
            v12 = 0;
          }
          g_pFaces[v10].styles[k] = v12;
        }
        g_pFaces[v10].lightofs = CUtlBuffer::GetInt(this: &faceData);
        ++v9;
        ++v10;
      }
      while ( v9 < (int)numfaces );
    }
    goto LABEL_34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014AB0
// Name: bool VRAD_DispatchFn(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VRAD_DispatchFn(MessageBuffer *pBuf)
{
  if ( pBuf->data[1] != 2 )
    return 0;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&g_LightResultsFilename,
    pArray: (const unsigned __int8 *)pBuf->data + 2,
    size: strlen((const char *)pBuf->data + 2) + 1);
  return 1;
}
