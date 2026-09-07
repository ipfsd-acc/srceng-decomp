// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/hltvdemo.cpp
// Functions: 17
// ============================================================

#include "engine\hltvdemo.h"

//------------------------------------------------------------------------------
// Address: 0x1017F7C0
// Name: public: void CHLTVDemoRecorder::StartAutoRecording(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::StartAutoRecording(CHLTVDemoRecorder *this)
{
  const char *v2; // eax
  char fileName[260]; // [esp+4h] [ebp-128h] BYREF
  tm today; // [esp+108h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &today);
  v2 = hltv->GetMapName(this: &hltv->CBaseServer);
  V_snprintf(
    pDest: fileName,
    maxLen: 260,
    pFormat: "auto-%04i%02i%02i-%02i%02i-%s.dem",
    today.tm_year + 1900,
    today.tm_mon + 1,
    today.tm_mday,
    today.tm_hour,
    today.tm_min,
    v2);
  this->StartRecording(this, a2: fileName, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017F840
// Name: public: virtual bool CHLTVDemoRecorder::IsRecording(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVDemoRecorder::IsRecording(CHLTVDemoRecorder *this)
{
  return this->m_bIsRecording;
}

//------------------------------------------------------------------------------
// Address: 0x1017F850
// Name: public: virtual void CHLTVDemoRecorder::StopRecording(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::StopRecording(CHLTVDemoRecorder *this)
{
  int v2; // eax
  float v3; // xmm0_4
  int m_nFrameCount; // eax
  unsigned __int8 *m_pData; // eax

  if ( this->m_bIsRecording )
  {
    v2 = ((int (*)(void))this->GetRecordingTick)();
    CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: 7, tick: v2, nPlayerSlot: 0);
    this->m_DemoFile.m_DemoHeader.playback_ticks = this->GetRecordingTick(this);
    v3 = (float)this->GetRecordingTick(this) * host_state.interval_per_tick;
    m_nFrameCount = this->m_nFrameCount;
    this->m_DemoFile.m_DemoHeader.playback_time = v3;
    this->m_DemoFile.m_DemoHeader.playback_frames = m_nFrameCount;
    CDemoFile::WriteDemoHeader(this: &this->m_DemoFile);
    CDemoFile::Close(this: &this->m_DemoFile);
    m_pData = this->m_MessageData.m_pData;
    this->m_bIsRecording = false;
    if ( m_pData != nullptr )
    {
      free(pMem: m_pData);
      bf_write::StartWriting(this: &this->m_MessageData, pData: nullptr, nBytes: 0, iStartBit: 0, nBits: -1);
    }
    ConMsg(
      a1: "Completed SourceTV demo \"%s\", recording time %.1f\n",
      this->m_DemoFile.m_szFileName,
      this->m_DemoFile.m_DemoHeader.playback_time);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F910
// Name: public: virtual int CHLTVDemoRecorder::GetRecordingTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVDemoRecorder::GetRecordingTick(CHLTVDemoRecorder *this)
{
  return (int)(float)((float)host_tickcount - this->m_nStartTick);
}

//------------------------------------------------------------------------------
// Address: 0x1017F930
// Name: public: virtual void CHLTVDemoRecorder::RecordCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordCommand(CHLTVDemoRecorder *this, const char *cmdstring)
{
  int v3; // eax

  if ( this->IsRecording(this) && cmdstring != nullptr && *cmdstring != 0 )
  {
    v3 = this->GetRecordingTick(this);
    CDemoFile::WriteConsoleCommand(this: &this->m_DemoFile, cmdstring, tick: v3, nPlayerSlot: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F970
// Name: public: virtual void CHLTVDemoRecorder::RecordServerClasses(class ServerClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordServerClasses(CHLTVDemoRecorder *this, ServerClass *pClasses)
{
  int v3; // eax
  _BYTE pData[96000]; // [esp+8h] [ebp-17718h] BYREF
  bf_write pBuf; // [esp+17708h] [ebp-18h] BYREF

  bf_write::bf_write(this: &pBuf, pData, nBytes: 96000, nBits: -1);
  DataTable_WriteSendTablesBuffer(pClasses, &pBuf);
  DataTable_WriteClassInfosBuffer(pClasses, &pBuf);
  v3 = this->GetRecordingTick(this);
  CDemoFile::WriteNetworkDataTables(this: &this->m_DemoFile, buf: &pBuf, tick: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1017F9D0
// Name: public: virtual void CHLTVDemoRecorder::RecordCustomData(int,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordCustomData(
        CHLTVDemoRecorder *this,
        int iCallbackIndex,
        const void *pData,
        unsigned int iDataLength)
{
  int v5; // eax

  v5 = this->GetRecordingTick(this);
  CDemoFile::WriteCustomData(this: &this->m_DemoFile, iCallbackIndex, pData, iDataSize: iDataLength, tick: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1017FA00
// Name: public: virtual void CHLTVDemoRecorder::RecordStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordStringTables(CHLTVDemoRecorder *this)
{
  int v2; // eax
  _BYTE pData[262144]; // [esp+4h] [ebp-40018h] BYREF
  bf_write buf; // [esp+40004h] [ebp-18h] BYREF

  bf_write::bf_write(this: &buf, pData, nBytes: 0x40000, nBits: -1);
  CNetworkStringTableContainer::WriteStringTables(this: networkStringTableContainerServer, &buf);
  v2 = this->GetRecordingTick(this);
  CDemoFile::WriteStringTables(this: &this->m_DemoFile, &buf, tick: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1017FA50
// Name: public: virtual void CHLTVDemoRecorder::RecordMessages(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordMessages(CHLTVDemoRecorder *this, bf_read *data, int bits)
{
  bf_write *p_m_MessageData; // esi
  void *v4; // eax

  p_m_MessageData = &this->m_MessageData;
  if ( this->m_MessageData.m_pData == nullptr )
  {
    v4 = MemAlloc_Alloc(nSize: 0x17700u);
    bf_write::StartWriting(this: p_m_MessageData, pData: v4, nBytes: 96000, iStartBit: 0, nBits: -1);
  }
  if ( bits > 0 )
    bf_write::WriteBitsFromBuffer(this: p_m_MessageData, pIn: data, nBits: bits);
}

//------------------------------------------------------------------------------
// Address: 0x1017FAA0
// Name: public: CHLTVDemoRecorder::CHLTVDemoRecorder(void)
// Source: json
//------------------------------------------------------------------------------
CHLTVDemoRecorder *__thiscall CHLTVDemoRecorder::CHLTVDemoRecorder(CHLTVDemoRecorder *this)
{
  this->__vftable = (CHLTVDemoRecorder_vtbl *)&CHLTVDemoRecorder::`vftable';
  CDemoFile::CDemoFile(this: &this->m_DemoFile);
  bf_write::bf_write(this: &this->m_MessageData);
  this->m_bIsRecording = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017FAD0
// Name: public: virtual CHLTVDemoRecorder::~CHLTVDemoRecorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::~CHLTVDemoRecorder(CHLTVDemoRecorder *this)
{
  this->__vftable = (CHLTVDemoRecorder_vtbl *)&CHLTVDemoRecorder::`vftable';
  CHLTVDemoRecorder::StopRecording(this);
  CDemoFile::~CDemoFile(this: &this->m_DemoFile);
  this->__vftable = (CHLTVDemoRecorder_vtbl *)&IDemoRecorder::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1017FAF0
// Name: public: void CHLTVDemoRecorder::WriteMessages(unsigned char,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::WriteMessages(CHLTVDemoRecorder *this, int cmd, bf_write *message)
{
  int m_iCurBit; // eax
  int v5; // ebx
  int v6; // eax
  unsigned int CurPos; // eax
  democmdinfo_t info; // [esp+8h] [ebp-98h] BYREF

  m_iCurBit = message->m_iCurBit;
  v5 = (m_iCurBit + 7) >> 3;
  if ( v5 > 0 )
  {
    if ( (unsigned int)(m_iCurBit % 8 - 1) <= 1 )
      bf_write::WriteUBitLong(this: message, curData: 0, numbits: 6, bCheckRange: true);
    if ( (_BYTE)cmd == 2 )
      ++this->m_nFrameCount;
    v6 = this->GetRecordingTick(this);
    CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd, tick: v6, nPlayerSlot: 0);
    democmdinfo_t::democmdinfo_t(this: &info);
    _V_memset(dest: &info, fill: 0, count: 152);
    CDemoFile::WriteCmdInfo(this: &this->m_DemoFile, &info);
    CDemoFile::WriteSequenceInfo(
      this: &this->m_DemoFile,
      nSeqNrIn: this->m_SequenceInfo,
      nSeqNrOut: this->m_SequenceInfo);
    ++this->m_SequenceInfo;
    CDemoFile::WriteRawData(this: &this->m_DemoFile, buffer: (const char *)message->m_pData, length: v5);
    if ( tv_debug.m_pParent != nullptr && tv_debug.m_pParent->m_Value.m_nValue > 1 )
    {
      CurPos = CDemoFile::GetCurPos(this: &this->m_DemoFile, bRead: false);
      _Msg(a1: "Writing SourceTV demo message %i bytes at file pos %i\n", v5, CurPos);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FBE0
// Name: public: virtual void CHLTVDemoRecorder::RecordPacket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordPacket(CHLTVDemoRecorder *this)
{
  bf_write *p_m_MessageData; // esi

  p_m_MessageData = &this->m_MessageData;
  if ( this->m_MessageData.m_pData != nullptr )
  {
    CHLTVDemoRecorder::WriteMessages(this, cmd: 2u, message: &this->m_MessageData);
    bf_write::Reset(this: p_m_MessageData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FC50
// Name: public: void CHLTVDemoRecorder::WriteFrame(class CHLTVFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::WriteFrame(CHLTVDemoRecorder *this, CHLTVFrame *pFrame)
{
  int tick_count; // edx
  int m_nSignonTick; // eax
  CClientFrame *ClientFrame; // edi
  CFrameSnapshot *m_pSnapshot; // edi
  _BYTE pData[96000]; // [esp+8h] [ebp-17734h] BYREF
  NET_Tick v8; // [esp+17708h] [ebp-34h] BYREF
  bf_write buffer; // [esp+17724h] [ebp-18h] BYREF

  bf_write::bf_write(this: &buffer, pDebugName: "CHLTVDemo::RecordFrame", pData, nBytes: 96000, nBits: -1);
  if ( pFrame->m_Messages[1].m_iCurBit != 0 )
    bf_write::WriteBits(this: &buffer, pInData: pFrame->m_Messages[1].m_pData, nBits: pFrame->m_Messages[1].m_iCurBit);
  tick_count = pFrame->tick_count;
  v8.m_flHostFrameTime = host_frametime_unbounded;
  v8.m_NetChannel = nullptr;
  v8.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  v8.m_bReliable = false;
  v8.m_nTick = tick_count;
  v8.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
  NET_Tick::WriteToBuffer(this: &v8, &buffer);
  m_nSignonTick = this->m_nSignonTick;
  if ( m_nSignonTick <= this->m_nDeltaTick )
    m_nSignonTick = this->m_nDeltaTick;
  CNetworkStringTableContainer::WriteUpdateMessage(
    this: sv.m_StringTables,
    client: nullptr,
    tick_ack: m_nSignonTick,
    buf: &buffer);
  ClientFrame = CClientFrameManager::GetClientFrame(
                  this: &hltv->CClientFrameManager,
                  nTick: this->m_nDeltaTick,
                  bExact: true);
  CBaseServer::WriteDeltaEntities(this: &sv, client: hltv->m_MasterClient, to: pFrame, from: ClientFrame, pBuf: &buffer);
  if ( ClientFrame != nullptr )
    m_pSnapshot = ClientFrame->m_pSnapshot;
  else
    m_pSnapshot = nullptr;
  CBaseServer::WriteTempEntities(
    this: &sv,
    client: hltv->m_MasterClient,
    pCurrentSnapshot: (unsigned int)pFrame->m_pSnapshot,
    pLastSnapshot: m_pSnapshot,
    buf: &buffer,
    ev_max: 255);
  if ( pFrame->m_Messages[4].m_iCurBit != 0 )
    bf_write::WriteBits(this: &buffer, pInData: pFrame->m_Messages[4].m_pData, nBits: pFrame->m_Messages[4].m_iCurBit);
  if ( pFrame->m_Messages[3].m_iCurBit != 0 )
    bf_write::WriteBits(this: &buffer, pInData: pFrame->m_Messages[3].m_pData, nBits: pFrame->m_Messages[3].m_iCurBit);
  if ( pFrame->m_Messages[2].m_iCurBit != 0 )
    bf_write::WriteBits(this: &buffer, pInData: pFrame->m_Messages[2].m_pData, nBits: pFrame->m_Messages[2].m_iCurBit);
  this->m_nDeltaTick = pFrame->tick_count;
  CHLTVDemoRecorder::WriteMessages(this, cmd: 2, message: &buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1017FDE0
// Name: public: void CHLTVDemoRecorder::WriteServerInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::WriteServerInfo(CHLTVDemoRecorder *this)
{
  CGameServer *v2; // esi
  const char *v3; // eax
  int v4; // eax
  _BYTE pData[96000]; // [esp+Ch] [ebp-17DFCh] BYREF
  SVC_ServerInfo v6; // [esp+1770Ch] [ebp-6FCh] BYREF
  NetMessageCvar_t pDest; // [esp+17B64h] [ebp-2A4h] BYREF
  NET_Tick v8; // [esp+17D6Ch] [ebp-9Ch] BYREF
  bf_write buffer; // [esp+17D88h] [ebp-80h] BYREF
  NET_SignonState v10; // [esp+17DA0h] [ebp-68h] BYREF
  NET_SetConVar v11; // [esp+17DE4h] [ebp-24h] BYREF

  bf_write::bf_write(this: &buffer, pDebugName: "CHLTVDemoRecorder::WriteServerInfo", pData, nBytes: 96000, nBits: -1);
  v6.m_bReliable = true;
  v6.m_NetChannel = nullptr;
  v6.__vftable = (SVC_ServerInfo_vtbl *)&SVC_ServerInfo::`vftable';
  if ( hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
  {
    v2 = &sv;
  }
  else if ( hltv != nullptr )
  {
    v2 = (CGameServer *)&hltv->CBaseServer;
  }
  else
  {
    v2 = nullptr;
  }
  hltv->FillServerInfo(this: &hltv->CBaseServer, a2: &v6);
  SVC_ServerInfo::WriteToBuffer(this: &v6, &buffer);
  v8.m_nTick = this->m_nSignonTick;
  v8.m_NetChannel = nullptr;
  v8.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  v8.m_bReliable = false;
  v8.m_flHostFrameTime = 0.0;
  v8.m_flHostFrameTimeStdDeviation = 0.0;
  NET_Tick::WriteToBuffer(this: &v8, &buffer);
  v11.m_bReliable = true;
  v11.m_NetChannel = nullptr;
  v11.__vftable = (NET_SetConVar_vtbl *)&NET_SetConVar::`vftable';
  memset(&v11.m_ConVars, 0, sizeof(v11.m_ConVars));
  Host_BuildConVarUpdateMessage(rCvarList: &v11.m_ConVars, flags: 0x2000, nonDefault: true);
  if ( hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
  {
    V_strncpy(pDest: pDest.name, pSrc: "tv_transmitall", maxLen: 260);
    V_strncpy(pDest: pDest.value, pSrc: "1", maxLen: 260);
    CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
      this: &v11.m_ConVars,
      elem: v11.m_ConVars.m_Size,
      src: &pDest);
  }
  NET_SetConVar::WriteToBuffer(this: &v11, &buffer);
  v3 = v2->GetMapName(this: v2);
  CNetworkStringTableContainer::WriteBaselines(this: hltv->m_StringTables, pchMapName: v3, buf: &buffer);
  v4 = v2->GetSpawnCount(this: v2);
  v10.m_bReliable = true;
  v10.m_NetChannel = nullptr;
  v10.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  v10.m_nSignonState = 3;
  v10.m_nSpawnCount = v4;
  memset(&v10.m_numServerPlayers, 0, 44);
  NET_SignonState::WriteToBuffer(this: &v10, &buffer);
  CHLTVDemoRecorder::WriteMessages(this, cmd: 1, message: &buffer);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v10.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v10.m_PlayersNetworkIds);
  v10.__vftable = (NET_SignonState_vtbl *)&INetMessage::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v11.m_ConVars);
}

//------------------------------------------------------------------------------
// Address: 0x10180000
// Name: public: int CHLTVDemoRecorder::WriteSignonData(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CHLTVDemoRecorder::WriteSignonData(CHLTVDemoRecorder *this)
{
  CGameServer *v2; // ebx
  IServerGameDLL_vtbl *v3; // edx
  int v4; // eax
  int serverclasses; // eax
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // esi
  char pData[96000]; // [esp+Ch] [ebp-177ECh] BYREF
  SVC_ClassInfo v11; // [esp+1770Ch] [ebp-ECh] BYREF
  NET_SignonState v12; // [esp+17738h] [ebp-C0h] BYREF
  NET_SignonState v13; // [esp+1777Ch] [ebp-7Ch] BYREF
  SVC_SetView v14; // [esp+177C0h] [ebp-38h] BYREF
  bf_write buffer; // [esp+177D4h] [ebp-24h] BYREF
  unsigned int CurPos; // [esp+177ECh] [ebp-Ch]
  void (__thiscall **p_RecordServerClasses)(struct CHLTVDemoRecorder *, ServerClass *); // [esp+177F0h] [ebp-8h]
  CDemoFile *p_m_DemoFile; // [esp+177F4h] [ebp-4h]

  p_m_DemoFile = &this->m_DemoFile;
  CurPos = CDemoFile::GetCurPos(this: &this->m_DemoFile, bRead: false);
  if ( hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
  {
    v2 = &sv;
  }
  else if ( hltv != nullptr )
  {
    v2 = (CGameServer *)&hltv->CBaseServer;
  }
  else
  {
    v2 = nullptr;
  }
  this->m_nSignonTick = v2->m_nTickCount;
  CHLTVDemoRecorder::WriteServerInfo(this);
  v3 = serverGameDLL->__vftable;
  p_RecordServerClasses = &this->RecordServerClasses;
  v4 = (int)v3->GetAllServerClasses(this: serverGameDLL);
  (*p_RecordServerClasses)(this, a2: (ServerClass *)v4);
  this->RecordStringTables(this);
  bf_write::bf_write(this: &buffer, pDebugName: "CHLTVDemo::WriteSignonData", pData, nBytes: 96000, nBits: -1);
  serverclasses = v2->serverclasses;
  v11.m_bReliable = true;
  v11.m_NetChannel = nullptr;
  v11.__vftable = (SVC_ClassInfo_vtbl *)&SVC_ClassInfo::`vftable';
  memset(&v11.m_Classes, 0, sizeof(v11.m_Classes));
  v11.m_bCreateOnClient = true;
  v11.m_nNumServerClasses = serverclasses;
  SVC_ClassInfo::WriteToBuffer(this: &v11, &buffer);
  bf_write::WriteBits(this: &buffer, pInData: hltv->m_Signon.m_pData, nBits: hltv->m_Signon.m_iCurBit);
  v12.m_nSpawnCount = v2->GetSpawnCount(this: v2);
  v12.m_bReliable = true;
  v12.m_NetChannel = nullptr;
  v12.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  v12.m_nSignonState = 4;
  memset(&v12.m_numServerPlayers, 0, 44);
  NET_SignonState::WriteToBuffer(this: &v12, &buffer);
  CHLTVDemoRecorder::WriteMessages(this, cmd: 1, message: &buffer);
  bf_write::Reset(this: &buffer);
  v14.m_nEntityIndex = hltv->m_nViewEntity;
  v14.m_bReliable = true;
  v14.m_NetChannel = nullptr;
  v14.__vftable = (SVC_SetView_vtbl *)&SVC_SetView::`vftable';
  SVC_SetView::WriteToBuffer(this: &v14, &buffer);
  v6 = v2->GetSpawnCount(this: v2);
  v13.m_bReliable = true;
  v13.m_NetChannel = nullptr;
  v13.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  v13.m_nSignonState = 5;
  v13.m_nSpawnCount = v6;
  memset(&v13.m_numServerPlayers, 0, 44);
  NET_SignonState::WriteToBuffer(this: &v13, &buffer);
  CHLTVDemoRecorder::WriteMessages(this, cmd: 1, message: &buffer);
  v7 = CDemoFile::GetCurPos(this: p_m_DemoFile, bRead: false);
  v8 = v7 - CurPos;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v13.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v13.m_PlayersNetworkIds);
  v13.__vftable = (NET_SignonState_vtbl *)&INetMessage::`vftable';
  v14.__vftable = (SVC_SetView_vtbl *)&INetMessage::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v12.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v12.m_PlayersNetworkIds);
  v12.__vftable = (NET_SignonState_vtbl *)&INetMessage::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v11.m_Classes);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10180290
// Name: public: virtual void CHLTVDemoRecorder::StartRecording(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::StartRecording(CHLTVDemoRecorder *this, const char *filename, bool bContinuously)
{
  const char *v4; // eax
  char *m_pszString; // eax
  char szGameDir[260]; // [esp+Ch] [ebp-104h] BYREF

  this->StopRecording(this);
  if ( CDemoFile::Open(this: &this->m_DemoFile, name: filename, bReadOnly: false, bMemoryBuffer: false) != 0 )
  {
    ConMsg(a1: "Recording SourceTV demo to %s...\n", filename);
    _V_memset(dest: &this->m_DemoFile.m_DemoHeader, fill: 0, count: 1072);
    V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.demofilestamp, pSrc: "HL2DEMO", maxLen: 8);
    this->m_DemoFile.m_DemoHeader.demoprotocol = 4;
    this->m_DemoFile.m_DemoHeader.networkprotocol = GetHostVersion();
    v4 = hltv->GetMapName(this: &hltv->CBaseServer);
    V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.mapname, pSrc: v4, maxLen: 260);
    V_strncpy(pDest: szGameDir, pSrc: com_gamedir, maxLen: 260);
    V_FileBase(in: szGameDir, out: this->m_DemoFile.m_DemoHeader.gamedirectory, maxlen: 260);
    if ( (host_name.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = host_name.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.servername, pSrc: m_pszString, maxLen: 260);
    V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.clientname, pSrc: "SourceTV Demo", maxLen: 260);
    CDemoFile::WriteDemoHeader(this: &this->m_DemoFile);
    this->m_DemoFile.m_DemoHeader.signonlength = CHLTVDemoRecorder::WriteSignonData(this);
    this->m_nFrameCount = 0;
    this->m_nStartTick = (float)host_tickcount;
    CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: 3, tick: 0, nPlayerSlot: 0);
    this->m_bIsRecording = true;
    this->m_SequenceInfo = 1;
    this->m_nDeltaTick = -1;
  }
  else
  {
    ConMsg(a1: "StartRecording: couldn't open demo file %s.\n", filename);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1017FB50
// Name: public: void CHLTVDemoRecorder::StartAutoRecording(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::StartAutoRecording(CHLTVDemoRecorder *this)
{
  const char *v2; // eax
  char fileName[260]; // [esp+4h] [ebp-128h] BYREF
  tm today; // [esp+108h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &today);
  v2 = hltv->GetMapName(this: &hltv->CBaseServer);
  V_snprintf(
    pDest: fileName,
    maxLen: 260,
    pFormat: "auto-%04i%02i%02i-%02i%02i-%s.dem",
    today.tm_year + 1900,
    today.tm_mon + 1,
    today.tm_mday,
    today.tm_hour,
    today.tm_min,
    v2);
  this->StartRecording(this, a2: fileName, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017FBD0
// Name: public: virtual bool CHLTVDemoRecorder::IsRecording(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVDemoRecorder::IsRecording(CHLTVDemoRecorder *this)
{
  return this->m_bIsRecording;
}

//------------------------------------------------------------------------------
// Address: 0x1017FCA0
// Name: public: virtual int CHLTVDemoRecorder::GetRecordingTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVDemoRecorder::GetRecordingTick(CHLTVDemoRecorder *this)
{
  return (int)(float)((float)host_tickcount - this->m_nStartTick);
}

//------------------------------------------------------------------------------
// Address: 0x1017FCC0
// Name: public: virtual void CHLTVDemoRecorder::RecordCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordCommand(CHLTVDemoRecorder *this, const char *cmdstring)
{
  int v3; // eax

  if ( this->IsRecording(this) && cmdstring != nullptr && *cmdstring != 0 )
  {
    v3 = this->GetRecordingTick(this);
    CDemoFile::WriteConsoleCommand(this: &this->m_DemoFile, cmdstring, tick: v3, nPlayerSlot: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FD00
// Name: public: virtual void CHLTVDemoRecorder::RecordServerClasses(class ServerClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordServerClasses(CHLTVDemoRecorder *this, ServerClass *pClasses)
{
  int v3; // eax
  _BYTE pData[96000]; // [esp+8h] [ebp-17718h] BYREF
  bf_write pBuf; // [esp+17708h] [ebp-18h] BYREF

  bf_write::bf_write(this: &pBuf, pData, nBytes: 96000, nBits: -1);
  DataTable_WriteSendTablesBuffer(pClasses, &pBuf);
  DataTable_WriteClassInfosBuffer(pClasses, &pBuf);
  v3 = this->GetRecordingTick(this);
  CDemoFile::WriteNetworkDataTables(this: &this->m_DemoFile, buf: &pBuf, tick: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1017FD60
// Name: public: virtual void CHLTVDemoRecorder::RecordCustomData(int,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordCustomData(
        CHLTVDemoRecorder *this,
        int iCallbackIndex,
        const void *pData,
        unsigned int iDataLength)
{
  int v5; // eax

  v5 = this->GetRecordingTick(this);
  CDemoFile::WriteCustomData(this: &this->m_DemoFile, iCallbackIndex, pData, iDataSize: iDataLength, tick: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1017FD90
// Name: public: virtual void CHLTVDemoRecorder::RecordStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordStringTables(CHLTVDemoRecorder *this)
{
  int v2; // eax
  _BYTE pData[262144]; // [esp+4h] [ebp-40018h] BYREF
  bf_write buf; // [esp+40004h] [ebp-18h] BYREF

  bf_write::bf_write(this: &buf, pData, nBytes: 0x40000, nBits: -1);
  CNetworkStringTableContainer::WriteStringTables(this: networkStringTableContainerServer, &buf);
  v2 = this->GetRecordingTick(this);
  CDemoFile::WriteStringTables(this: &this->m_DemoFile, &buf, tick: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1017FE30
// Name: public: CHLTVDemoRecorder::CHLTVDemoRecorder(void)
// Source: json
//------------------------------------------------------------------------------
CHLTVDemoRecorder *__thiscall CHLTVDemoRecorder::CHLTVDemoRecorder(CHLTVDemoRecorder *this)
{
  this->__vftable = (CHLTVDemoRecorder_vtbl *)&CHLTVDemoRecorder::`vftable';
  CDemoFile::CDemoFile(this: &this->m_DemoFile);
  bf_write::bf_write(this: &this->m_MessageData);
  this->m_bIsRecording = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017FE60
// Name: public: virtual CHLTVDemoRecorder::~CHLTVDemoRecorder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::~CHLTVDemoRecorder(CHLTVDemoRecorder *this)
{
  this->__vftable = (CHLTVDemoRecorder_vtbl *)&CHLTVDemoRecorder::`vftable';
  CHLTVDemoRecorder::StopRecording(this);
  CDemoFile::~CDemoFile(this: &this->m_DemoFile);
  this->__vftable = (CHLTVDemoRecorder_vtbl *)&IDemoRecorder::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1017FE80
// Name: public: void CHLTVDemoRecorder::WriteMessages(unsigned char,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::WriteMessages(CHLTVDemoRecorder *this, int cmd, bf_write *message)
{
  int m_iCurBit; // eax
  int v5; // ebx
  int v6; // eax
  unsigned int CurPos; // eax
  democmdinfo_t info; // [esp+8h] [ebp-98h] BYREF

  m_iCurBit = message->m_iCurBit;
  v5 = (m_iCurBit + 7) >> 3;
  if ( v5 > 0 )
  {
    if ( (unsigned int)(m_iCurBit % 8 - 1) <= 1 )
      bf_write::WriteUBitLong(this: message, curData: 0, numbits: 6, bCheckRange: true);
    if ( (_BYTE)cmd == 2 )
      ++this->m_nFrameCount;
    v6 = this->GetRecordingTick(this);
    CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd, tick: v6, nPlayerSlot: 0);
    democmdinfo_t::democmdinfo_t(this: &info);
    _V_memset(dest: &info, fill: 0, count: 152);
    CDemoFile::WriteCmdInfo(this: &this->m_DemoFile, &info);
    CDemoFile::WriteSequenceInfo(
      this: &this->m_DemoFile,
      nSeqNrIn: this->m_SequenceInfo,
      nSeqNrOut: this->m_SequenceInfo);
    ++this->m_SequenceInfo;
    CDemoFile::WriteRawData(this: &this->m_DemoFile, buffer: (const char *)message->m_pData, length: v5);
    if ( tv_debug.m_pParent != nullptr && tv_debug.m_pParent->m_Value.m_nValue > 1 )
    {
      CurPos = CDemoFile::GetCurPos(this: &this->m_DemoFile, bRead: false);
      _Msg(a1: "Writing SourceTV demo message %i bytes at file pos %i\n", v5, CurPos);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FF70
// Name: public: virtual void CHLTVDemoRecorder::RecordPacket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::RecordPacket(CHLTVDemoRecorder *this)
{
  bf_write *p_m_MessageData; // esi

  p_m_MessageData = &this->m_MessageData;
  if ( this->m_MessageData.m_pData != nullptr )
  {
    CHLTVDemoRecorder::WriteMessages(this, cmd: 2, message: &this->m_MessageData);
    bf_write::Reset(this: p_m_MessageData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FFE0
// Name: public: void CHLTVDemoRecorder::WriteFrame(class CHLTVFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::WriteFrame(CHLTVDemoRecorder *this, CHLTVFrame *pFrame)
{
  int tick_count; // edx
  int m_nSignonTick; // eax
  CClientFrame *ClientFrame; // edi
  CFrameSnapshot *m_pSnapshot; // edi
  _BYTE pData[96000]; // [esp+8h] [ebp-17734h] BYREF
  NET_Tick v8; // [esp+17708h] [ebp-34h] BYREF
  bf_write buffer; // [esp+17724h] [ebp-18h] BYREF

  bf_write::bf_write(this: &buffer, pDebugName: "CHLTVDemo::RecordFrame", pData, nBytes: 96000, nBits: -1);
  if ( pFrame->m_Messages[1].m_iCurBit != 0 )
    bf_write::WriteBits(this: &buffer, pInData: pFrame->m_Messages[1].m_pData, nBits: pFrame->m_Messages[1].m_iCurBit);
  tick_count = pFrame->tick_count;
  v8.m_flHostFrameTime = host_frametime_unbounded;
  v8.m_NetChannel = nullptr;
  v8.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  v8.m_bReliable = false;
  v8.m_nTick = tick_count;
  v8.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
  NET_Tick::WriteToBuffer(this: &v8, &buffer);
  m_nSignonTick = this->m_nSignonTick;
  if ( m_nSignonTick <= this->m_nDeltaTick )
    m_nSignonTick = this->m_nDeltaTick;
  CNetworkStringTableContainer::WriteUpdateMessage(
    this: sv.m_StringTables,
    client: nullptr,
    tick_ack: m_nSignonTick,
    buf: &buffer);
  ClientFrame = CClientFrameManager::GetClientFrame(
                  this: &hltv->CClientFrameManager,
                  nTick: this->m_nDeltaTick,
                  bExact: true);
  CBaseServer::WriteDeltaEntities(this: &sv, client: hltv->m_MasterClient, to: pFrame, from: ClientFrame, pBuf: &buffer);
  if ( ClientFrame != nullptr )
    m_pSnapshot = ClientFrame->m_pSnapshot;
  else
    m_pSnapshot = nullptr;
  CBaseServer::WriteTempEntities(
    this: &sv,
    client: hltv->m_MasterClient,
    pCurrentSnapshot: (unsigned int)pFrame->m_pSnapshot,
    pLastSnapshot: m_pSnapshot,
    buf: &buffer,
    ev_max: 255);
  if ( pFrame->m_Messages[4].m_iCurBit != 0 )
    bf_write::WriteBits(this: &buffer, pInData: pFrame->m_Messages[4].m_pData, nBits: pFrame->m_Messages[4].m_iCurBit);
  if ( pFrame->m_Messages[3].m_iCurBit != 0 )
    bf_write::WriteBits(this: &buffer, pInData: pFrame->m_Messages[3].m_pData, nBits: pFrame->m_Messages[3].m_iCurBit);
  if ( pFrame->m_Messages[2].m_iCurBit != 0 )
    bf_write::WriteBits(this: &buffer, pInData: pFrame->m_Messages[2].m_pData, nBits: pFrame->m_Messages[2].m_iCurBit);
  this->m_nDeltaTick = pFrame->tick_count;
  CHLTVDemoRecorder::WriteMessages(this, cmd: 2, message: &buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10180170
// Name: public: void CHLTVDemoRecorder::WriteServerInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::WriteServerInfo(CHLTVDemoRecorder *this)
{
  CGameServer *v2; // esi
  signed int v3; // eax
  int v4; // eax
  _BYTE pData[96000]; // [esp+Ch] [ebp-17DFCh] BYREF
  SVC_ServerInfo v6; // [esp+1770Ch] [ebp-6FCh] BYREF
  NetMessageCvar_t pDest; // [esp+17B64h] [ebp-2A4h] BYREF
  NET_Tick v8; // [esp+17D6Ch] [ebp-9Ch] BYREF
  bf_write buffer; // [esp+17D88h] [ebp-80h] BYREF
  NET_SignonState v10; // [esp+17DA0h] [ebp-68h] BYREF
  NET_SetConVar v11; // [esp+17DE4h] [ebp-24h] BYREF

  bf_write::bf_write(this: &buffer, pDebugName: "CHLTVDemoRecorder::WriteServerInfo", pData, nBytes: 96000, nBits: -1);
  v6.m_bReliable = true;
  v6.m_NetChannel = nullptr;
  v6.__vftable = (SVC_ServerInfo_vtbl *)&SVC_ServerInfo::`vftable';
  if ( hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
  {
    v2 = &sv;
  }
  else if ( hltv != nullptr )
  {
    v2 = (CGameServer *)&hltv->CBaseServer;
  }
  else
  {
    v2 = nullptr;
  }
  hltv->FillServerInfo(this: &hltv->CBaseServer, a2: &v6);
  SVC_ServerInfo::WriteToBuffer(this: &v6, &buffer);
  v8.m_nTick = this->m_nSignonTick;
  v8.m_NetChannel = nullptr;
  v8.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  v8.m_bReliable = false;
  v8.m_flHostFrameTime = 0.0;
  v8.m_flHostFrameTimeStdDeviation = 0.0;
  NET_Tick::WriteToBuffer(this: &v8, &buffer);
  v11.m_bReliable = true;
  v11.m_NetChannel = nullptr;
  v11.__vftable = (NET_SetConVar_vtbl *)&NET_SetConVar::`vftable';
  memset(&v11.m_ConVars, 0, sizeof(v11.m_ConVars));
  Host_BuildConVarUpdateMessage(rCvarList: &v11.m_ConVars, flags: 0x2000, nonDefault: true);
  if ( hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
  {
    V_strncpy(pDest: pDest.name, pSrc: "tv_transmitall", maxLen: 260);
    V_strncpy(pDest: pDest.value, pSrc: "1", maxLen: 260);
    CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
      this: &v11.m_ConVars,
      elem: v11.m_ConVars.m_Size,
      src: &pDest);
  }
  NET_SetConVar::WriteToBuffer(this: &v11, &buffer);
  v3 = (signed int)v2->GetMapName(this: v2);
  CNetworkStringTableContainer::WriteBaselines(this: hltv->m_StringTables, pchMapName: v3, buf: &buffer);
  v4 = v2->GetSpawnCount(this: v2);
  v10.m_bReliable = true;
  v10.m_NetChannel = nullptr;
  v10.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  v10.m_nSignonState = 3;
  v10.m_nSpawnCount = v4;
  memset(&v10.m_numServerPlayers, 0, 44);
  NET_SignonState::WriteToBuffer(this: &v10, &buffer);
  CHLTVDemoRecorder::WriteMessages(this, cmd: 1, message: &buffer);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v10.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v10.m_PlayersNetworkIds);
  v10.__vftable = (NET_SignonState_vtbl *)&INetMessage::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v11.m_ConVars);
}

//------------------------------------------------------------------------------
// Address: 0x10180390
// Name: public: int CHLTVDemoRecorder::WriteSignonData(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CHLTVDemoRecorder::WriteSignonData(CHLTVDemoRecorder *this)
{
  CGameServer *v2; // ebx
  IServerGameDLL_vtbl *v3; // edx
  int v4; // eax
  int serverclasses; // eax
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // esi
  char pData[96000]; // [esp+Ch] [ebp-177ECh] BYREF
  SVC_ClassInfo v11; // [esp+1770Ch] [ebp-ECh] BYREF
  NET_SignonState v12; // [esp+17738h] [ebp-C0h] BYREF
  NET_SignonState v13; // [esp+1777Ch] [ebp-7Ch] BYREF
  SVC_SetView v14; // [esp+177C0h] [ebp-38h] BYREF
  bf_write buffer; // [esp+177D4h] [ebp-24h] BYREF
  unsigned int CurPos; // [esp+177ECh] [ebp-Ch]
  void (__thiscall **p_RecordServerClasses)(struct CHLTVDemoRecorder *, ServerClass *); // [esp+177F0h] [ebp-8h]
  CDemoFile *p_m_DemoFile; // [esp+177F4h] [ebp-4h]

  p_m_DemoFile = &this->m_DemoFile;
  CurPos = CDemoFile::GetCurPos(this: &this->m_DemoFile, bRead: false);
  if ( hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
  {
    v2 = &sv;
  }
  else if ( hltv != nullptr )
  {
    v2 = (CGameServer *)&hltv->CBaseServer;
  }
  else
  {
    v2 = nullptr;
  }
  this->m_nSignonTick = v2->m_nTickCount;
  CHLTVDemoRecorder::WriteServerInfo(this);
  v3 = serverGameDLL->__vftable;
  p_RecordServerClasses = &this->RecordServerClasses;
  v4 = (int)v3->GetAllServerClasses(this: serverGameDLL);
  (*p_RecordServerClasses)(this, a2: (ServerClass *)v4);
  this->RecordStringTables(this);
  bf_write::bf_write(this: &buffer, pDebugName: "CHLTVDemo::WriteSignonData", pData, nBytes: 96000, nBits: -1);
  serverclasses = v2->serverclasses;
  v11.m_bReliable = true;
  v11.m_NetChannel = nullptr;
  v11.__vftable = (SVC_ClassInfo_vtbl *)&SVC_ClassInfo::`vftable';
  memset(&v11.m_Classes, 0, sizeof(v11.m_Classes));
  v11.m_bCreateOnClient = true;
  v11.m_nNumServerClasses = serverclasses;
  SVC_ClassInfo::WriteToBuffer(this: &v11, &buffer);
  bf_write::WriteBits(this: &buffer, pInData: hltv->m_Signon.m_pData, nBits: hltv->m_Signon.m_iCurBit);
  v12.m_nSpawnCount = v2->GetSpawnCount(this: v2);
  v12.m_bReliable = true;
  v12.m_NetChannel = nullptr;
  v12.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  v12.m_nSignonState = 4;
  memset(&v12.m_numServerPlayers, 0, 44);
  NET_SignonState::WriteToBuffer(this: &v12, &buffer);
  CHLTVDemoRecorder::WriteMessages(this, cmd: 1, message: &buffer);
  bf_write::Reset(this: &buffer);
  v14.m_nEntityIndex = hltv->m_nViewEntity;
  v14.m_bReliable = true;
  v14.m_NetChannel = nullptr;
  v14.__vftable = (SVC_SetView_vtbl *)&SVC_SetView::`vftable';
  SVC_SetView::WriteToBuffer(this: &v14, &buffer);
  v6 = v2->GetSpawnCount(this: v2);
  v13.m_bReliable = true;
  v13.m_NetChannel = nullptr;
  v13.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  v13.m_nSignonState = 5;
  v13.m_nSpawnCount = v6;
  memset(&v13.m_numServerPlayers, 0, 44);
  NET_SignonState::WriteToBuffer(this: &v13, &buffer);
  CHLTVDemoRecorder::WriteMessages(this, cmd: 1, message: &buffer);
  v7 = CDemoFile::GetCurPos(this: p_m_DemoFile, bRead: false);
  v8 = v7 - CurPos;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v13.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v13.m_PlayersNetworkIds);
  v13.__vftable = (NET_SignonState_vtbl *)&INetMessage::`vftable';
  v14.__vftable = (SVC_SetView_vtbl *)&INetMessage::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v12.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v12.m_PlayersNetworkIds);
  v12.__vftable = (NET_SignonState_vtbl *)&INetMessage::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v11.m_Classes);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10180620
// Name: public: virtual void CHLTVDemoRecorder::StartRecording(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDemoRecorder::StartRecording(CHLTVDemoRecorder *this, const char *filename, bool bContinuously)
{
  const char *v4; // eax
  char *m_pszString; // eax
  char szGameDir[260]; // [esp+Ch] [ebp-104h] BYREF

  this->StopRecording(this);
  if ( CDemoFile::Open(this: &this->m_DemoFile, name: filename, bReadOnly: false, bMemoryBuffer: false) != 0 )
  {
    ConMsg(a1: "Recording SourceTV demo to %s...\n", filename);
    _V_memset(dest: &this->m_DemoFile.m_DemoHeader, fill: 0, count: 1072);
    V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.demofilestamp, pSrc: "HL2DEMO", maxLen: 8);
    this->m_DemoFile.m_DemoHeader.demoprotocol = 4;
    this->m_DemoFile.m_DemoHeader.networkprotocol = GetHostVersion();
    v4 = hltv->GetMapName(this: &hltv->CBaseServer);
    V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.mapname, pSrc: v4, maxLen: 260);
    V_strncpy(pDest: szGameDir, pSrc: com_gamedir, maxLen: 260);
    V_FileBase(in: szGameDir, out: this->m_DemoFile.m_DemoHeader.gamedirectory, maxlen: 260);
    if ( (host_name.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = host_name.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.servername, pSrc: m_pszString, maxLen: 260);
    V_strncpy(pDest: this->m_DemoFile.m_DemoHeader.clientname, pSrc: "SourceTV Demo", maxLen: 260);
    CDemoFile::WriteDemoHeader(this: &this->m_DemoFile);
    this->m_DemoFile.m_DemoHeader.signonlength = CHLTVDemoRecorder::WriteSignonData(this);
    this->m_nFrameCount = 0;
    this->m_nStartTick = (float)host_tickcount;
    CDemoFile::WriteCmdHeader(this: &this->m_DemoFile, cmd: 3, tick: 0, nPlayerSlot: 0);
    this->m_bIsRecording = true;
    this->m_SequenceInfo = 1;
    this->m_nDeltaTick = -1;
  }
  else
  {
    ConMsg(a1: "StartRecording: couldn't open demo file %s.\n", filename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10312C30
// Name: _dynamic_initializer_for__demo_recordcommands__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_recordcommands__()
{
  ConVar::ConVar(
    this: &demo_recordcommands,
    pName: "demo_recordcommands",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Record commands typed at console into .dem files.");
  return atexit(func: dynamic_atexit_destructor_for__demo_recordcommands__);
}

//------------------------------------------------------------------------------
// Address: 0x10312C60
// Name: _dynamic_initializer_for__demo_quitafterplayback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_quitafterplayback__()
{
  ConVar::ConVar(
    this: &demo_quitafterplayback,
    pName: "demo_quitafterplayback",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Quits game after demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_quitafterplayback__);
}

//------------------------------------------------------------------------------
// Address: 0x10312C90
// Name: _dynamic_initializer_for__demo_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_debug__()
{
  ConVar::ConVar(this: &demo_debug, pName: "demo_debug", pDefaultValue: "0", flags: 0, pHelpString: "Demo debug info.");
  return atexit(func: dynamic_atexit_destructor_for__demo_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10312CC0
// Name: _dynamic_initializer_for__demo_interpolateview__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_interpolateview__()
{
  ConVar::ConVar(
    this: &demo_interpolateview,
    pName: "demo_interpolateview",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Do view interpolation during dem playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_interpolateview__);
}

//------------------------------------------------------------------------------
// Address: 0x10312CF0
// Name: _dynamic_initializer_for__demo_pauseatservertick__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_pauseatservertick__()
{
  ConVar::ConVar(
    this: &demo_pauseatservertick,
    pName: "demo_pauseatservertick",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Pauses demo playback at server tick");
  return atexit(func: dynamic_atexit_destructor_for__demo_pauseatservertick__);
}

//------------------------------------------------------------------------------
// Address: 0x10312D20
// Name: _dynamic_initializer_for__demo_enabledemos__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_enabledemos__()
{
  ConVar::ConVar(
    this: &demo_enabledemos,
    pName: "demo_enabledemos",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable recording demos (must be set true before loading a map)");
  return atexit(func: dynamic_atexit_destructor_for__demo_enabledemos__);
}

//------------------------------------------------------------------------------
// Address: 0x10312DC0
// Name: _dynamic_initializer_for__demo_interplimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_interplimit__()
{
  ConVar::ConVar(
    this: &demo_interplimit,
    pName: "demo_interplimit",
    pDefaultValue: "4000",
    flags: 0,
    pHelpString: "How much origin velocity before it's considered to have 'teleported' causing interpolation to reset.");
  return atexit(func: dynamic_atexit_destructor_for__demo_interplimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10312DF0
// Name: _dynamic_initializer_for__demo_avellimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_avellimit__()
{
  ConVar::ConVar(
    this: &demo_avellimit,
    pName: "demo_avellimit",
    pDefaultValue: "2000",
    flags: 0,
    pHelpString: "Angular velocity limit before eyes considered snapped for demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_avellimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E20
// Name: _dynamic_initializer_for__demo_fastforwardstartspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardstartspeed__()
{
  ConVar::ConVar(
    this: &demo_fastforwardstartspeed,
    pName: "demo_fastforwardstartspeed",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Go this fast when starting to hold FF button.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardstartspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E50
// Name: _dynamic_initializer_for__demo_fastforwardfinalspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardfinalspeed__()
{
  ConVar::ConVar(
    this: &demo_fastforwardfinalspeed,
    pName: "demo_fastforwardfinalspeed",
    pDefaultValue: "20",
    flags: 0,
    pHelpString: "Go this fast when starting to hold FF button.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E80
// Name: _dynamic_initializer_for__demo_fastforwardramptime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardramptime__()
{
  ConVar::ConVar(
    this: &demo_fastforwardramptime,
    pName: "demo_fastforwardramptime",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "How many seconds it takes to get to full FF speed.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardramptime__);
}

//------------------------------------------------------------------------------
// Address: 0x10312EF0
// Name: _dynamic_initializer_for__demo_legacy_rollback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_legacy_rollback__()
{
  ConVar::ConVar(
    this: &demo_legacy_rollback,
    pName: "demo_legacy_rollback",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use legacy view interpolation rollback amount in demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_legacy_rollback__);
}

//------------------------------------------------------------------------------
// Address: 0x10313100
// Name: _dynamic_initializer_for__demo_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_pause_command__()
{
  ConCommand::ConCommand(
    this: &demo_pause_command,
    pName: "demo_pause",
    callback: demo_pause,
    pHelpString: "Pauses demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_pause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313130
// Name: _dynamic_initializer_for__demo_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_resume_command__()
{
  ConCommand::ConCommand(
    this: &demo_resume_command,
    pName: "demo_resume",
    callback: demo_resume,
    pHelpString: "Resumes demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_resume_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313160
// Name: _dynamic_initializer_for__demo_togglepause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_togglepause_command__()
{
  ConCommand::ConCommand(
    this: &demo_togglepause_command,
    pName: "demo_togglepause",
    callback: demo_togglepause,
    pHelpString: "Toggles demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_togglepause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313190
// Name: _dynamic_initializer_for__demo_gototick_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_gototick_command__()
{
  ConCommand::ConCommand(
    this: &demo_gototick_command,
    pName: "demo_gototick",
    callback: demo_gototick,
    pHelpString: "Skips to a tick in demo.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_gototick_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103131C0
// Name: _dynamic_initializer_for__demo_timescale_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_timescale_command__()
{
  ConCommand::ConCommand(
    this: &demo_timescale_command,
    pName: "demo_timescale",
    callback: demo_timescale,
    pHelpString: "Sets demo replay speed.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_timescale_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322510
// Name: _dynamic_atexit_destructor_for__demo_recordcommands__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_recordcommands__()
{
  ConVar::~ConVar(this: &demo_recordcommands);
}

//------------------------------------------------------------------------------
// Address: 0x10322520
// Name: _dynamic_atexit_destructor_for__demo_quitafterplayback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_quitafterplayback__()
{
  ConVar::~ConVar(this: &demo_quitafterplayback);
}

//------------------------------------------------------------------------------
// Address: 0x10322530
// Name: _dynamic_atexit_destructor_for__demo_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_debug__()
{
  ConVar::~ConVar(this: &demo_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10322540
// Name: _dynamic_atexit_destructor_for__demo_interpolateview__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_interpolateview__()
{
  ConVar::~ConVar(this: &demo_interpolateview);
}

//------------------------------------------------------------------------------
// Address: 0x10322550
// Name: _dynamic_atexit_destructor_for__demo_pauseatservertick__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_pauseatservertick__()
{
  ConVar::~ConVar(this: &demo_pauseatservertick);
}

//------------------------------------------------------------------------------
// Address: 0x10322560
// Name: _dynamic_atexit_destructor_for__demo_enabledemos__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_enabledemos__()
{
  ConVar::~ConVar(this: &demo_enabledemos);
}

//------------------------------------------------------------------------------
// Address: 0x10322570
// Name: _dynamic_atexit_destructor_for__demo_interplimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_interplimit__()
{
  ConVar::~ConVar(this: &demo_interplimit);
}

//------------------------------------------------------------------------------
// Address: 0x10322580
// Name: _dynamic_atexit_destructor_for__demo_avellimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_avellimit__()
{
  ConVar::~ConVar(this: &demo_avellimit);
}

//------------------------------------------------------------------------------
// Address: 0x10322590
// Name: _dynamic_atexit_destructor_for__demo_fastforwardstartspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardstartspeed__()
{
  ConVar::~ConVar(this: &demo_fastforwardstartspeed);
}

//------------------------------------------------------------------------------
// Address: 0x103225A0
// Name: _dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__()
{
  ConVar::~ConVar(this: &demo_fastforwardfinalspeed);
}

//------------------------------------------------------------------------------
// Address: 0x103225B0
// Name: _dynamic_atexit_destructor_for__demo_fastforwardramptime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardramptime__()
{
  ConVar::~ConVar(this: &demo_fastforwardramptime);
}

//------------------------------------------------------------------------------
// Address: 0x103225D0
// Name: _dynamic_atexit_destructor_for__demo_legacy_rollback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_legacy_rollback__()
{
  ConVar::~ConVar(this: &demo_legacy_rollback);
}

//------------------------------------------------------------------------------
// Address: 0x10322680
// Name: _dynamic_atexit_destructor_for__demo_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_pause_command__()
{
  ConCommand::~ConCommand(this: &demo_pause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322690
// Name: _dynamic_atexit_destructor_for__demo_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_resume_command__()
{
  ConCommand::~ConCommand(this: &demo_resume_command);
}

//------------------------------------------------------------------------------
// Address: 0x103226A0
// Name: _dynamic_atexit_destructor_for__demo_togglepause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_togglepause_command__()
{
  ConCommand::~ConCommand(this: &demo_togglepause_command);
}

//------------------------------------------------------------------------------
// Address: 0x103226B0
// Name: _dynamic_atexit_destructor_for__demo_gototick_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_gototick_command__()
{
  ConCommand::~ConCommand(this: &demo_gototick_command);
}

//------------------------------------------------------------------------------
// Address: 0x103226C0
// Name: _dynamic_atexit_destructor_for__demo_timescale_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_timescale_command__()
{
  ConCommand::~ConCommand(this: &demo_timescale_command);
}

//------------------------------------------------------------------------------
// Address: 0x103131F0
// Name: _dynamic_initializer_for__g_FactoryCDemoActionSkipAhead__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionSkipAhead__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_SKIPAHEAD, func: FnCreateCDemoActionSkipAhead);
}

//------------------------------------------------------------------------------
// Address: 0x10313200
// Name: _dynamic_initializer_for__g_FactoryCDemoActionStopPlayback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionStopPlayback__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_STOPPLAYBACK, func: FnCreateCDemoActionStopPlayback);
}

//------------------------------------------------------------------------------
// Address: 0x10313210
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPlayCommands__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPlayCommands__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCOMMANDS, func: FnCreateCDemoActionPlayCommands);
}

//------------------------------------------------------------------------------
// Address: 0x10313220
// Name: _dynamic_initializer_for__g_FactoryCDemoActionScreenFadeStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionScreenFadeStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_SCREENFADE_START, func: FnCreateCDemoActionScreenFadeStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313230
// Name: _dynamic_initializer_for__g_FactoryCDemoActionTextMessageStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionTextMessageStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_TEXTMESSAGE_START, func: FnCreateCDemoActionTextMessageStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313240
// Name: _dynamic_initializer_for__g_FactoryCDemoActionCDTrackStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionCDTrackStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCDTRACK_START, func: FnCreateCDemoActionCDTrackStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313250
// Name: _dynamic_initializer_for__g_FactoryCDemoActionCDTrackStop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionCDTrackStop__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCDTRACK_STOP, func: FnCreateCDemoActionCDTrackStop);
}

//------------------------------------------------------------------------------
// Address: 0x10313260
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPlaySoundStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPlaySoundStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYSOUND_START, func: FnCreateCDemoActionPlaySoundStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313270
// Name: _dynamic_initializer_for__g_FactoryCDemoActionChangePlaybackRate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionChangePlaybackRate__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_CHANGEPLAYBACKRATE, func: FnCreateCDemoActionChangePlaybackRate);
}

//------------------------------------------------------------------------------
// Address: 0x10313280
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPausePlayback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPausePlayback__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PAUSE, func: FnCreateCDemoActionPausePlayback);
}

//------------------------------------------------------------------------------
// Address: 0x10313290
// Name: _dynamic_initializer_for__g_FactoryCDemoActionZoom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionZoom__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_ZOOM, func: FnCreateCDemoActionZoom);
}

//------------------------------------------------------------------------------
// Address: 0x103132A0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionSkipAheadDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionSkipAheadDialog__()
{
  CBaseDemoAction::AddEditorFactory(actionType: DEMO_ACTION_SKIPAHEAD, func: FnCreateEditorCBaseActionSkipAheadDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132B0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionStopPlaybackDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionStopPlaybackDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_STOPPLAYBACK,
    func: FnCreateEditorCBaseActionStopPlaybackDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132C0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionScreenFadeStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionScreenFadeStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_SCREENFADE_START,
    func: FnCreateEditorCBaseActionScreenFadeStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132D0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionTextMessageStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionTextMessageStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_TEXTMESSAGE_START,
    func: FnCreateEditorCBaseActionTextMessageStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132E0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPlayCommandsDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPlayCommandsDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYCOMMANDS,
    func: FnCreateEditorCBaseActionPlayCommandsDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132F0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionCDTrackStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionCDTrackStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYCDTRACK_START,
    func: FnCreateEditorCBaseActionCDTrackStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313300
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPlaySoundStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPlaySoundStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYSOUND_START,
    func: FnCreateEditorCBaseActionPlaySoundStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313310
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionChangePlaybackRateDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionChangePlaybackRateDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_CHANGEPLAYBACKRATE,
    func: FnCreateEditorCBaseActionChangePlaybackRateDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313320
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPauseDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPauseDialog__()
{
  CBaseDemoAction::AddEditorFactory(actionType: DEMO_ACTION_PAUSE, func: FnCreateEditorCBaseActionPauseDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313330
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionZoomDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionZoomDialog__()
{
  CBaseDemoAction::AddEditorFactory(actionType: DEMO_ACTION_ZOOM, func: FnCreateEditorCBaseActionZoomDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313340
// Name: _dynamic_initializer_for__g_DemoActionManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DemoActionManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DemoActionManager__);
}

//------------------------------------------------------------------------------
// Address: 0x103226D0
// Name: _dynamic_atexit_destructor_for__g_DemoOverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DemoOverlay__()
{
  ;
}

} // namespace engine_xlsp
