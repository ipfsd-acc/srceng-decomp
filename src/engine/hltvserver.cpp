// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/hltvserver.cpp
// Functions: 80
// ============================================================

#include "engine\hltvserver.h"

//------------------------------------------------------------------------------
// Address: 0x1017DCA0
// Name: public: virtual char const __near * CHLTVServer::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHLTVServer::GetName(CHLTVClientState *this)
{
  char *result; // eax

  if ( (tv_name.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = tv_name.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10180420
// Name: tv_name_changed_f
// Source: json
//------------------------------------------------------------------------------
void __usercall tv_name_changed_f(int a1@<ebx>, int a2@<edi>)
{
  CSteam3Server *v2; // eax

  v2 = Steam3Server();
  CSteam3Server::NotifyOfServerNameChange(this: v2, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10180430
// Name: public: void CDeltaEntityCache::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaEntityCache::Flush(CDeltaEntityCache *this)
{
  int m_nMaxEntities; // eax
  int v3; // ebx
  void **m_Cache; // esi

  m_nMaxEntities = this->m_nMaxEntities;
  v3 = 0;
  if ( m_nMaxEntities != 0 )
  {
    if ( m_nMaxEntities > 0 )
    {
      m_Cache = (void **)this->m_Cache;
      do
      {
        if ( *m_Cache != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *m_Cache);
          *m_Cache = nullptr;
        }
        ++v3;
        ++m_Cache;
      }
      while ( v3 < this->m_nMaxEntities );
    }
    this->m_nMaxEntities = 0;
    this->m_nCacheSize = 0;
  }
  else
  {
    this->m_nCacheSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180480
// Name: public: void CDeltaEntityCache::SetTick(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaEntityCache::SetTick(CDeltaEntityCache *this, int nTick, int nMaxEntities)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax

  if ( nTick != this->m_nTick )
  {
    CDeltaEntityCache::Flush(this);
    v4 = tv_deltacache.m_pParent != nullptr ? tv_deltacache.m_pParent->m_Value.m_nValue : 0;
    v5 = v4 << 10;
    this->m_nCacheSize = v5;
    if ( v5 > 0 )
    {
      v6 = nMaxEntities;
      if ( nMaxEntities >= 2048 )
        v6 = 2048;
      this->m_nMaxEntities = v6;
      this->m_nTick = nTick;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101804D0
// Name: public: unsigned char __near * CDeltaEntityCache::FindDeltaBits(int,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
CDeltaEntityCache::DeltaEntityEntry_s *__thiscall CDeltaEntityCache::FindDeltaBits(
        CDeltaEntityCache *this,
        int nEntityIndex,
        int nDeltaTick,
        int *nBits)
{
  CDeltaEntityCache::DeltaEntityEntry_s *v4; // eax

  *nBits = -1;
  if ( nEntityIndex < 0 )
    return nullptr;
  if ( nEntityIndex >= this->m_nMaxEntities )
    return nullptr;
  v4 = this->m_Cache[nEntityIndex];
  if ( v4 == nullptr )
    return nullptr;
  while ( v4->nDeltaTick != nDeltaTick )
  {
    v4 = v4->pNext;
    if ( v4 == nullptr )
      return nullptr;
  }
  *nBits = v4->nBits;
  return v4 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10180510
// Name: public: void CDeltaEntityCache::AddDeltaBits(int,int,int,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaEntityCache::AddDeltaBits(
        CDeltaEntityCache *this,
        int nEntityIndex,
        int nDeltaTick,
        int nBits,
        bf_write *pBuffer)
{
  signed int m_nCacheSize; // ebx
  CDeltaEntityCache::DeltaEntityEntry_s *v7; // ecx
  int v8; // esi
  CDeltaEntityCache::DeltaEntityEntry_s *v9; // eax
  CDeltaEntityCache::DeltaEntityEntry_s *v10; // edi
  CDeltaEntityCache::DeltaEntityEntry_s *pNext; // eax
  unsigned int i; // ebx
  unsigned __int8 *m_pData; // [esp-18h] [ebp-58h]
  unsigned int m_nDataBytes; // [esp-14h] [ebp-54h]
  int m_iCurBit; // [esp-10h] [ebp-50h]
  bf_read inBuffer; // [esp+4h] [ebp-3Ch] BYREF
  bf_write outBuffer; // [esp+28h] [ebp-18h] BYREF

  if ( nEntityIndex >= 0 && nEntityIndex < this->m_nMaxEntities )
  {
    m_nCacheSize = this->m_nCacheSize;
    if ( m_nCacheSize > 0 )
    {
      v7 = this->m_Cache[nEntityIndex];
      v8 = 4 * ((((nBits + 7) >> 3) + 3) / 4);
      if ( v7 == nullptr )
      {
        if ( v8 + 12 > m_nCacheSize )
          return;
        v9 = (CDeltaEntityCache::DeltaEntityEntry_s *)MemAlloc_Alloc(nSize: m_nCacheSize);
        this->m_Cache[nEntityIndex] = v9;
        v10 = v9;
        goto LABEL_11;
      }
      pNext = v7->pNext;
      for ( i = (unsigned int)v7 + m_nCacheSize; pNext != nullptr; pNext = pNext->pNext )
        v7 = pNext;
      v10 = (CDeltaEntityCache::DeltaEntityEntry_s *)((char *)v7 + 4 * ((((v7->nBits + 7) >> 3) + 3) / 4) + 12);
      if ( (unsigned int)&v10[1] + v8 <= i )
      {
        v10->pNext = v10;
LABEL_11:
        v10->pNext = nullptr;
        v10->nDeltaTick = nDeltaTick;
        v10->nBits = nBits;
        if ( nBits > 0 )
        {
          inBuffer.m_bOverflow = false;
          inBuffer.m_pDebugName = nullptr;
          inBuffer.m_nDataBytes = 0;
          m_iCurBit = pBuffer->m_iCurBit;
          m_nDataBytes = pBuffer->m_nDataBytes;
          m_pData = pBuffer->m_pData;
          inBuffer.m_nDataBits = -1;
          CBitRead::StartReading(
            this: &inBuffer,
            pData: (const unsigned int *)m_pData,
            nBytes: m_nDataBytes,
            iStartBit: m_iCurBit,
            nBits: -1);
          bf_write::bf_write(this: &outBuffer, pData: &v10[1], nBytes: v8, nBits: -1);
          bf_write::WriteBitsFromBuffer(this: &outBuffer, pIn: &inBuffer, nBits);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180610
// Name: AddRecvTableR
// Source: json
//------------------------------------------------------------------------------
RecvTable *__cdecl AddRecvTableR(SendTable *sendt, RecvTable **pRecvTables, int *nRecvTables)
{
  char *m_pNetTableName; // ebx
  int v4; // edi
  int v5; // esi
  int m_nProps; // edi
  RecvProp *v7; // eax
  RecvProp *v8; // ebx
  int v9; // edi
  RecvProp *j; // esi
  RecvTable *v11; // esi
  RecvTable *result; // eax
  int v13; // ebx
  RecvProp *v14; // esi
  SendProp *v15; // eax
  int m_ElementStride; // ecx
  int m_nElements; // edx
  RecvTable *v18; // eax
  RecvTable *v19; // eax
  int i; // [esp+Ch] [ebp-8h]
  RecvProp *receiveProps; // [esp+10h] [ebp-4h]

  m_pNetTableName = sendt->m_pNetTableName;
  v4 = *nRecvTables;
  v5 = 0;
  if ( *nRecvTables > 0 )
  {
    while ( _V_strcmp(s1: m_pNetTableName, s2: pRecvTables[v5]->m_pNetTableName) != 0 )
    {
      if ( ++v5 >= v4 )
        goto LABEL_4;
    }
    v11 = pRecvTables[v5];
    if ( v11 != nullptr )
      return v11;
  }
LABEL_4:
  m_nProps = sendt->m_nProps;
  if ( m_nProps <= 0 )
  {
    v19 = (RecvTable *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v19 != nullptr )
    {
      result = RecvTable::RecvTable(this: v19, pProps: nullptr, nProps: 0, pNetTableName: sendt->m_pNetTableName);
      pRecvTables[(*nRecvTables)++] = result;
      return result;
    }
  }
  else
  {
    v7 = (RecvProp *)MemAlloc_Alloc(nSize: (60 * (unsigned __int64)(unsigned int)m_nProps) >> 32 != 0 ? -1 : 60 * m_nProps);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v9 = m_nProps - 1;
      for ( j = v7; v9 >= 0; --v9 )
        RecvProp::RecvProp(this: j++);
      receiveProps = v8;
    }
    else
    {
      receiveProps = nullptr;
    }
    v13 = 0;
    i = 0;
    if ( sendt->m_nProps > 0 )
    {
      v14 = receiveProps - 1;
      do
      {
        v15 = &sendt->m_pProps[v13];
        v14[1].m_pVarName = v15->m_pVarName;
        v14[1].m_RecvType = v15->m_Type;
        if ( (v15->m_Flags & 0x40) != 0 )
          v14[1].m_pVarName = "IsExcludedProp";
        if ( (v15->m_Flags & 0x100) != 0 )
        {
          v14[1].m_bInsideArray = true;
          v14[1].m_pVarName = "InsideArrayProp";
        }
        if ( v15->m_Type == DPT_Array )
        {
          v14[1].m_pArrayProp = v14;
          m_ElementStride = v15->m_ElementStride;
          m_nElements = v15->m_nElements;
          v14[1].m_RecvType = DPT_Array;
          v14[1].m_nElements = m_nElements;
          v14[1].m_ElementStride = m_ElementStride;
        }
        if ( v15->m_Type == DPT_DataTable )
          v14[1].m_pDataTable = AddRecvTableR(sendt: v15->m_pDataTable, pRecvTables, nRecvTables);
        ++v13;
        ++v14;
        ++i;
      }
      while ( i < sendt->m_nProps );
    }
    v18 = (RecvTable *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v18 != nullptr )
    {
      result = RecvTable::RecvTable(
                 this: v18,
                 pProps: receiveProps,
                 nProps: sendt->m_nProps,
                 pNetTableName: sendt->m_pNetTableName);
      pRecvTables[(*nRecvTables)++] = result;
      return result;
    }
  }
  pRecvTables[(*nRecvTables)++] = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101807D0
// Name: private: void CHLTVServer::InitClientRecvTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::InitClientRecvTables(CHLTVServer *this)
{
  CHLTVServer *v1; // edi
  ServerClass *i; // esi
  ServerClass *v3; // ebx
  bool j; // zf
  int m_nRecvTables; // edi
  int v6; // esi
  RecvTable *v7; // esi
  ClientClass *v8; // eax
  char *s1; // [esp+4h] [ebp-8h]

  v1 = this;
  if ( ClientDLL_GetAllClasses() == nullptr )
  {
    for ( i = serverGameDLL->GetAllServerClasses(this: serverGameDLL); i != nullptr; i = i->m_pNext )
    {
      AddRecvTableR(sendt: i->m_pTable, pRecvTables: v1->m_pRecvTables, nRecvTables: &v1->m_nRecvTables);
      if ( v1->m_nRecvTables >= 0x400u )
        _Error(a1: "AddRecvTableR: overflowed MAX_DATATABLES");
    }
    v3 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
    for ( j = v3 == nullptr; !j; j = v3 == nullptr )
    {
      if ( v1->m_nRecvTables >= 0x400u )
        _Error(a1: "ClientDLL_InitRecvTableMgr: overflowed MAX_DATATABLES");
      m_nRecvTables = v1->m_nRecvTables;
      v6 = 0;
      s1 = v3->m_pTable->m_pNetTableName;
      if ( m_nRecvTables <= 0 )
      {
LABEL_13:
        v7 = nullptr;
      }
      else
      {
        while ( _V_strcmp(s1, s2: this->m_pRecvTables[v6]->m_pNetTableName) != 0 )
        {
          if ( ++v6 >= m_nRecvTables )
            goto LABEL_13;
        }
        v7 = this->m_pRecvTables[v6];
      }
      v8 = (ClientClass *)MemAlloc_Alloc(nSize: 0x1Cu);
      if ( v8 == nullptr )
      {
        _Msg(a1: "HLTV_InitRecvTableMgr: failed to allocate client class %s.\n", v3->m_pNetworkName);
        return;
      }
      v1 = this;
      v8->m_pNetworkName = v3->m_pNetworkName;
      v8->m_pCreateFn = nullptr;
      v8->m_pCreateEventFn = nullptr;
      v8->m_pRecvTable = v7;
      v8->m_pMapClassname = nullptr;
      v8->m_pNext = g_pClientClassHead;
      g_pClientClassHead = v8;
      v3 = v3->m_pNext;
    }
    RecvTable_Init(pTables: v1->m_pRecvTables, nTables: v1->m_nRecvTables);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180930
// Name: public: void CHLTVFrame::AllocBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVFrame::AllocBuffers(CHLTVFrame *this)
{
  bf_write *m_Messages; // esi
  int i; // edi
  void *v3; // eax

  m_Messages = this->m_Messages;
  for ( i = 6; i != 0; --i )
  {
    v3 = MemAlloc_Alloc(nSize: 0x17700u);
    bf_write::StartWriting(this: m_Messages++, pData: v3, nBytes: 96000, iStartBit: 0, nBits: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180970
// Name: public: void CHLTVFrame::FreeBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVFrame::FreeBuffers(CHLTVFrame *this)
{
  bf_write *m_Messages; // esi
  int i; // edi

  m_Messages = this->m_Messages;
  for ( i = 6; i != 0; --i )
  {
    if ( m_Messages->m_pData != nullptr )
    {
      free(pMem: m_Messages->m_pData);
      bf_write::StartWriting(this: m_Messages, pData: nullptr, nBytes: 0, iStartBit: 0, nBits: -1);
    }
    ++m_Messages;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101809B0
// Name: public: void CHLTVServer::StartRelay(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVServer::StartRelay(CHLTVServer *this@<ecx>, int a2@<edi>)
{
  int m_nValue; // eax
  long double v4; // st7

  if ( this->m_ClientState.m_nSignonState >= 2 || this->IsPlayingBack(this: &this->IDemoPlayer) )
  {
    ((void (__thiscall *)(CBaseServer *, int))this->Clear)(a1: &this->CBaseServer, a2);
    if ( this->m_nRecvTables == 0 )
      CHLTVServer::InitClientRecvTables(this);
    CHLTVFrame::AllocBuffers(this: &this->m_HLTVFrame);
    this->m_StringTables = &this->m_NetworkStringTables;
    if ( tv_maxclients.m_pParent != nullptr )
      m_nValue = tv_maxclients.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    this->SetMaxClients(this: &this->CBaseServer, a2: m_nValue);
    this->m_bSignonState = true;
    v4 = net_time;
    ++this->m_nSpawnCount;
    this->m_flStartTime = v4;
    this->m_State = ss_loading;
  }
  else
  {
    DevMsg(a1: "StartRelay: not connected.\n");
    this->Shutdown(this: &this->CBaseServer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180A70
// Name: public: virtual int CHLTVServer::GetHLTVSlot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVServer::GetHLTVSlot(CHLTVServer *this)
{
  return *(_DWORD *)&this->m_DemoRecorder.m_DemoFile.m_DemoHeader.mapname[92];
}

//------------------------------------------------------------------------------
// Address: 0x10180A80
// Name: public: virtual float CHLTVServer::GetOnlineTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CHLTVServer::GetOnlineTime(CHLTVServer *this)
{
  long double result; // st7

  result = net_time - *(float *)&this->m_DemoRecorder.m_DemoFile.m_DemoHeader.playback_frames;
  if ( result < 0.0 )
    return 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10180AA0
// Name: public: virtual void CHLTVServer::GetLocalStats(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::GetLocalStats(CHLTVServer *this, int *proxies, int *slots, int *clients)
{
  char *v4; // esi

  v4 = (char *)this - 512;
  *proxies = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 128) + 12))(a1: (char *)this - 512);
  *clients = (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 8))(a1: v4);
  *slots = (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 20))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10180AE0
// Name: public: virtual struct netadr_s const __near * CHLTVServer::GetRelayAddress(void)
// Source: json
//------------------------------------------------------------------------------
const netadr_s *__thiscall CHLTVServer::GetRelayAddress(CHLTVServer *this)
{
  if ( (unsigned __int8)this->IGameEventListener2::__vftable[2].GetEventDebugID(this) != 0 )
    return &net_local_adr;
  if ( *(_DWORD *)&this->m_szMapname[8] != 0 )
    return (*(const netadr_s *(__thiscall **)(_DWORD))(**(_DWORD **)&this->m_szMapname[8] + 196))(a1: *(_DWORD *)&this->m_szMapname[8]);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10180B10
// Name: public: virtual bool CHLTVServer::IsMasterProxy(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHLTVServer::IsMasterProxy(CHLTVServer *this)
{
  return this->m_State != ss_dead;
}

//------------------------------------------------------------------------------
// Address: 0x10180B20
// Name: public: bool CHLTVServer::IsTVRelay(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVServer::IsTVRelay(CHLTVServer *this)
{
  return !this->IsMasterProxy(this: &this->IHLTVServer);
}

//------------------------------------------------------------------------------
// Address: 0x10180B40
// Name: public: virtual int CHLTVServer::GetEventDebugID(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall CHLTVServer::GetEventDebugID(vgui::TextEntry *this)
{
  return this->m_pEditMenu;
}

//------------------------------------------------------------------------------
// Address: 0x10180B50
// Name: protected: virtual bool CHLTVServer::ShouldUpdateMasterServer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVServer::ShouldUpdateMasterServer(CHLTVServer *this)
{
  return IsUsingMasterLegacyMode() || sv.m_State < ss_active;
}

//------------------------------------------------------------------------------
// Address: 0x10180B70
// Name: private: virtual class CBaseClient __near * CHLTVServer::CreateNewClient(int)
// Source: json
//------------------------------------------------------------------------------
CHLTVClient *__thiscall CHLTVServer::CreateNewClient(CHLTVServer *this, int slot)
{
  CHLTVClient *v3; // eax

  v3 = (CHLTVClient *)MemAlloc_Alloc(nSize: 0x1D7A0u);
  if ( v3 != nullptr )
    return CHLTVClient::CHLTVClient(this: v3, slot, pServer: this != (CHLTVServer *)8 ? (CBaseServer *)this : nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10180BB0
// Name: private: void CHLTVServer::InstallStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::InstallStringTables(CHLTVServer *this)
{
  int v2; // eax
  CNetworkStringTable *v3; // eax
  vgui::Panel *v4; // esi
  CNetworkStringTableContainer_vtbl *v5; // ebx
  int UserDataSize; // eax
  int v7; // eax
  int v8; // eax
  CNetworkStringTable *v9; // eax
  int v10; // ebx
  const char *v11; // eax
  vgui::DragDrop_t *UserDataSizeBits; // [esp-Ch] [ebp-1Ch]
  BOOL IsUsingDictionary; // [esp-8h] [ebp-18h]
  int numTables; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  numTables = this->m_Server->m_StringTables->GetNumTables(this: this->m_Server->m_StringTables);
  this->m_StringTables = &this->m_NetworkStringTables;
  CNetMessage::SetReliable(this: (CNetMessage *)&this->m_NetworkStringTables, state: true);
  CNetworkStringTableContainer::EnableRollback(this: this->m_StringTables, bState: true);
  v2 = 0;
  for ( i = 0; v2 < numTables; i = v2 )
  {
    v3 = (CNetworkStringTable *)this->m_Server->m_StringTables->GetTable(this: this->m_Server->m_StringTables, a2: v2);
    v4 = (vgui::Panel *)v3;
    if ( v3 != nullptr )
    {
      v5 = this->m_StringTables->CBaseServer::__vftable;
      IsUsingDictionary = CNetworkStringTable::IsUsingDictionary(this: v3);
      UserDataSizeBits = CNetworkStringTable::GetUserDataSizeBits(this: v4);
      UserDataSize = CNetworkStringTable::GetUserDataSize(this: (CVTFTexture *)v4);
      v7 = ((int (__thiscall *)(vgui::Panel *, int, vgui::DragDrop_t *, BOOL))v4->Repaint)(
             a1: v4,
             a2: UserDataSize,
             a3: UserDataSizeBits,
             a4: IsUsingDictionary);
      v8 = ((int (__thiscall *)(vgui::Panel *, int))v4->Think)(a1: v4, a2: v7);
      v9 = (CNetworkStringTable *)((int (__thiscall *)(CNetworkStringTableContainer *, int))v5->CreateStringTable)(
                                    a1: this->m_StringTables,
                                    a2: v8);
      v10 = (int)v9;
      if ( v9 != nullptr )
      {
        CNetworkStringTable::CopyStringTable(this: v9, table: (CNetworkStringTable *)v4);
        CNetworkStringTable::SetMirrorTable(this: (CAudioMixerWave *)v4, delaySamples: v10);
      }
      else
      {
        v11 = (const char *)((int (__thiscall *)(vgui::Panel *))v4->Think)(a1: v4);
        DevMsg(a1: "SV_InstallHLTVStringTableMirrors! Missing client table \"%s\".\n ", v11);
      }
    }
    v2 = i + 1;
  }
  CNetMessage::SetReliable(this: (CNetMessage *)this->m_StringTables, state: false);
}

//------------------------------------------------------------------------------
// Address: 0x10180CC0
// Name: private: void CHLTVServer::RestoreTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::RestoreTick(CHLTVServer *this, int tick)
{
  int v3; // edi
  int i; // esi
  CNetworkStringTable *v5; // eax

  if ( this->IsMasterProxy(this: &this->IHLTVServer) )
  {
    v3 = this->m_StringTables->GetNumTables(this: this->m_StringTables);
    for ( i = 0; i < v3; ++i )
    {
      v5 = (CNetworkStringTable *)this->m_StringTables->GetTable(this: this->m_StringTables, a2: i);
      CNetworkStringTable::RestoreTick(this: v5, tick);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180D20
// Name: class CHLTVEntityData __near * FindHLTVDataInSnapshot(class CFrameSnapshot __near *,int)
// Source: json
//------------------------------------------------------------------------------
CHLTVEntityData *__cdecl FindHLTVDataInSnapshot(CFrameSnapshot *pSnapshot, int iEntIndex)
{
  unsigned __int16 *m_pValidEntities; // edi
  int v3; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // edx

  m_pValidEntities = pSnapshot->m_pValidEntities;
  v3 = 0;
  v4 = pSnapshot->m_nValidEntities - 1;
  if ( iEntIndex < *m_pValidEntities || iEntIndex > m_pValidEntities[v4] || v4 <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = (v4 + v3) / 2;
    v6 = m_pValidEntities[v5];
    if ( iEntIndex == v6 )
      break;
    if ( iEntIndex <= v6 )
    {
      if ( m_pValidEntities[v3] == iEntIndex )
      {
        v5 = v3;
        return &pSnapshot->m_pHLTVEntityData[v5];
      }
      if ( v4 == v5 )
        return nullptr;
      v4 = (v4 + v3) / 2;
    }
    else
    {
      if ( m_pValidEntities[v4] == iEntIndex )
        return &pSnapshot->m_pHLTVEntityData[v4];
      if ( v3 == v5 )
        return nullptr;
      v3 = (v4 + v3) / 2;
    }
    if ( v3 >= v4 )
      return nullptr;
  }
  return &pSnapshot->m_pHLTVEntityData[v5];
}

//------------------------------------------------------------------------------
// Address: 0x10180DB0
// Name: public: bool CHLTVServer::SendNetMsg(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CHLTVServer::SendNetMsg@<al>(
        CHLTVServer *this@<ecx>,
        int a2@<edi>,
        INetMessage *msg,
        bool bForceReliable,
        bool bVoice)
{
  int v7; // edi

  if ( this->m_bSignonState )
    return msg->WriteToBuffer(this: msg, a2: &this->m_Signon);
  v7 = 2;
  if ( ((unsigned __int8 (__thiscall *)(INetMessage *, int))msg->IsReliable)(a1: msg, a2) != 0 )
  {
    v7 = 1;
  }
  else if ( msg->GetType(this: msg) == 17 )
  {
    v7 = 4;
  }
  else if ( msg->GetType(this: msg) == 15 )
  {
    v7 = 3;
  }
  else if ( msg->GetType(this: msg) == 27 )
  {
    v7 = 5;
  }
  return msg->WriteToBuffer(this: msg, a2: &this->m_HLTVFrame.m_Messages[v7]);
}

//------------------------------------------------------------------------------
// Address: 0x10180E50
// Name: public: class bf_write __near * CHLTVServer::GetBuffer(int)
// Source: json
//------------------------------------------------------------------------------
bf_write *__thiscall CHLTVServer::GetBuffer(CHLTVServer *this, unsigned int nBuffer)
{
  if ( nBuffer > 5 )
    return nullptr;
  else
    return &this->m_HLTVFrame.m_Messages[nBuffer];
}

//------------------------------------------------------------------------------
// Address: 0x10180E70
// Name: public: virtual class IServer __near * CHLTVServer::GetBaseServer(void)
// Source: json
//------------------------------------------------------------------------------
IServer *__thiscall CHLTVServer::GetBaseServer(CHLTVServer *this)
{
  if ( this == (CHLTVServer *)520 )
    return nullptr;
  else
    return (IServer *)((char *)this - 512);
}

//------------------------------------------------------------------------------
// Address: 0x10180E90
// Name: public: virtual class IHLTVDirector __near * CHLTVServer::GetDirector(void)
// Source: json
//------------------------------------------------------------------------------
IHLTVDirector *__thiscall CHLTVServer::GetDirector(CHLTVServer *this)
{
  return *(IHLTVDirector **)&this->m_DemoRecorder.m_DemoFile.m_DemoHeader.mapname[72];
}

//------------------------------------------------------------------------------
// Address: 0x10180EA0
// Name: public: virtual void CHLTVServer::FillServerInfo(class SVC_ServerInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::FillServerInfo(CHLTVServer *this, SVC_ServerInfo *serverinfo)
{
  CBaseServer::FillServerInfo((CBaseServer *)this, serverinfo);
  serverinfo->m_nPlayerSlot = (int)this->m_CurrentFrame;
  serverinfo->m_nMaxClients = LODWORD(this->m_flStartTime);
}

//------------------------------------------------------------------------------
// Address: 0x10180ED0
// Name: public: virtual void CHLTVServer::Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::Init(CHLTVServer *this, bool bIsDedicated)
{
  int v3; // eax

  CBaseServer::Init((CBaseServer *)this, bIsDedicated);
  this->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable = (CBaseServer_vtbl *)2;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-tvmasteronly") != 0 )
    LOBYTE(this->m_vPVSOrigin.y) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10180F10
// Name: public: void CHLTVServer::Changelevel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::Changelevel(CHLTVServer *this)
{
  this->m_DemoRecorder.StopRecording(this: &this->m_DemoRecorder);
  CBaseServer::InactivateClients(this: &this->CBaseServer);
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  this->m_CurrentFrame = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10180F50
// Name: public: virtual void CHLTVServer::GetNetStats(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::GetNetStats(CHLTVServer *this, float *avgIn, float *avgOut)
{
  CBaseServer::GetNetStats((CBaseServer *)this, avgIn, avgOut);
  if ( LODWORD(this->m_ClientState.m_ListenServerSteamID) == 6 )
  {
    *avgIn = ((double (__thiscall *)(IServerMessageHandler_vtbl *, int))*((_DWORD *)this->m_ClientState.dtr_INetMessageHandler
                                                                        + 13))(
               a1: this->m_ClientState.__vftable,
               a2: 1)
           + *avgIn;
    *avgOut = ((double (__thiscall *)(IServerMessageHandler_vtbl *, _DWORD))*((_DWORD *)this->m_ClientState.dtr_INetMessageHandler
                                                                            + 13))(
                a1: this->m_ClientState.__vftable,
                a2: 0)
            + *avgOut;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180FA0
// Name: public: virtual void CHLTVServer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::Shutdown(CHLTVServer *this)
{
  (*(void (__thiscall **)(CHLTVServer **))&this->m_ClientState.m_pHLTV->m_szMapname[4])(a1: &this->m_ClientState.m_pHLTV);
  if ( (*(unsigned __int8 (__thiscall **)(int *))(this->m_ClientFramePool.m_BlobHead.m_NumBytes + 32))(a1: &this->m_ClientFramePool.m_BlobHead.m_NumBytes) != 0 )
  {
    if ( this->IDemoPlayer::__vftable != nullptr )
      (*((void (__cdecl **)(CDemoFile *(__thiscall **)(IDemoPlayer *), const char *))this->GetDemoFile + 13))(
        a1: &this->GetDemoFile,
        a2: "SourceTV stop.");
    if ( this->m_DemoRecorder.m_MessageData.m_pDebugName != nullptr )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)this->m_DemoRecorder.m_MessageData.m_pDebugName + 8))(a1: 0);
  }
  else
  {
    CAddressList::RemoveAll(this: (CAddressList *)&this->m_ClientState.m_nRetryNumber);
    (*(void (__stdcall **)(int))(this->m_nDebugID + 64))(a1: 1);
  }
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: (CHLTVServer *)((char *)this - 8));
  CBaseServer::Shutdown((CBaseServer *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10181040
// Name: public: virtual class CDemoFile __near * CHLTVServer::GetDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
CDeltaEntityCache::DeltaEntityEntry_s **__thiscall CHLTVServer::GetDemoFile(CHLTVServer *this)
{
  return &this->m_DeltaCache.m_Cache[1922];
}

//------------------------------------------------------------------------------
// Address: 0x10181050
// Name: public: virtual bool CHLTVServer::IsPlayingBack(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVServer::IsPlayingBack(CHLTVServer *this)
{
  return this->m_DemoFile.m_DemoHeader.mapname[172];
}

//------------------------------------------------------------------------------
// Address: 0x10181060
// Name: public: virtual bool CHLTVServer::IsPlaybackPaused(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVServer::IsPlaybackPaused(CHLTVServer *this)
{
  return this->m_DemoFile.m_DemoHeader.mapname[173];
}

//------------------------------------------------------------------------------
// Address: 0x10181070
// Name: public: virtual float CHLTVServer::GetPlaybackTimeScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHLTVServer::GetPlaybackTimeScale(CHLTVServer *this)
{
  return *(float *)&this->m_DemoFile.m_DemoHeader.mapname[176];
}

//------------------------------------------------------------------------------
// Address: 0x10181080
// Name: public: virtual void CHLTVServer::SetPlaybackTimeScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::SetPlaybackTimeScale(CHLTVServer *this, float timescale)
{
  *(float *)&this->m_DemoFile.m_DemoHeader.mapname[176] = timescale;
}

//------------------------------------------------------------------------------
// Address: 0x101810A0
// Name: public: virtual int CHLTVServer::GetPlaybackStartTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVServer::GetPlaybackStartTick(CHLTVServer *this)
{
  return *(_DWORD *)&this->m_DemoFile.m_DemoHeader.mapname[16];
}

//------------------------------------------------------------------------------
// Address: 0x101810B0
// Name: public: virtual int CHLTVServer::GetPlaybackTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVServer::GetPlaybackTick(CHLTVServer *this)
{
  return host_tickcount - *(_DWORD *)&this->m_DemoFile.m_DemoHeader.mapname[16];
}

//------------------------------------------------------------------------------
// Address: 0x101810C0
// Name: public: virtual int CHLTVServer::GetTotalTicks(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVServer::GetTotalTicks(CHLTVServer *this)
{
  return *(_DWORD *)this->m_DemoFile.m_DemoHeader.mapname;
}

//------------------------------------------------------------------------------
// Address: 0x101810D0
// Name: public: virtual char const __near * CHLTVServer::GetPassword(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHLTVServer::GetPassword(CHLTVServer *this)
{
  char *v1; // esi
  char *m_pszString; // eax

  if ( (tv_password.m_nFlags & 0x1000) != 0 )
  {
    v1 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = tv_password.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      return nullptr;
    v1 = tv_password.m_pParent->m_Value.m_pszString;
    if ( *m_pszString == 0 )
      return nullptr;
  }
  if ( _V_stricmp(s1: v1, s2: "none") != 0 )
    return v1;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10181120
// Name: tv_status
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall tv_status(int a1@<edi>, int a2@<esi>)
{
  CHLTVServer *v2; // esi
  int v3; // eax
  double v4; // st7
  char *v5; // eax
  bool v6; // al
  IHLTVServer_vtbl *v7; // edx
  IHLTVServer *v8; // ecx
  int v9; // eax
  CHLTVServer *v10; // esi
  unsigned __int64 v11; // st7
  const char *v12; // eax
  CBaseServer *v13; // esi
  netadr_s *v14; // eax
  char *v15; // eax
  const char *v16; // eax
  CBaseServer *v17; // esi
  int v18; // eax
  int v19; // eax
  double v20; // st7
  char *v21; // eax
  char *v22; // eax
  CHLTVDemoRecorder *p_m_DemoRecorder; // esi
  int v24; // eax
  char *v25; // eax
  const char *v26; // eax
  double v27; // [esp+10h] [ebp-12Ch]
  double v28[5]; // [esp+18h] [ebp-124h] BYREF
  _BYTE gd_232[20]; // [esp+128h] [ebp-14h] OVERLAPPED BYREF

  V_FileBase(in: com_gamedir, out: (char *)&v28[1], maxlen: 260);
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    ((void (__thiscall *)(CBaseServer *, _BYTE *, _BYTE *, int, int))hltv->GetNetStats)(
      a1: &hltv->CBaseServer,
      a2: gd_232,
      a3: &gd_232[12],
      a4: a1,
      a5: a2);
    *(float *)gd_232 = *(float *)gd_232 * 0.0009765625;
    *(float *)&gd_232[12] = *(float *)&gd_232[12] * 0.0009765625;
    ConMsg(a1: "--- SourceTV Status ---\n");
    v2 = hltv;
    v3 = build_number();
    v4 = ((double (__thiscall *)(IHLTVServer *, _DWORD, _DWORD, int, const char *))v2->GetOnlineTime)(
           a1: &v2->IHLTVServer,
           a2: COERCE_UNSIGNED_INT64(hltv->m_flFPS),
           a3: HIDWORD(COERCE_UNSIGNED_INT64(hltv->m_flFPS)),
           a4: v3,
           a5: "Win32");
    v5 = COM_FormatSeconds(seconds: (int)v4);
    ConMsg(a1: "Online %s, FPS %.1f, Version %i (%s)\n", v5, v27, LODWORD(v28[0]), (const char *)HIDWORD(v28[0]));
    if ( hltv->IsDemoPlayback(this: &hltv->IHLTVServer) )
    {
      ConMsg(a1: "Playing Demo File \"%s\"\n", "TODO demo file name");
    }
    else
    {
      v6 = hltv->IsMasterProxy(this: &hltv->IHLTVServer);
      v7 = hltv->IHLTVServer::IBaseInterface::__vftable;
      v8 = &hltv->IHLTVServer;
      if ( v6 )
      {
        v9 = (int)v7->GetDirector(this: v8);
        v10 = hltv;
        *(double *)&v11 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v9 + 28))(a1: v9);
        v12 = (const char *)((int (__thiscall *)(CBaseServer *, _DWORD, _DWORD))v10->GetName)(
                              a1: &v10->CBaseServer,
                              a2: v11,
                              a3: HIDWORD(v11));
        ConMsg(a1: "Master \"%s\", delay %.0f\n", v12, v28[0]);
      }
      else if ( v7->GetRelayAddress(this: v8) != nullptr )
      {
        v13 = &hltv->CBaseServer;
        v14 = (netadr_s *)hltv->GetRelayAddress(this: &hltv->IHLTVServer);
        v15 = netadr_s::ToString(this: v14, baseOnly: false);
        v16 = (const char *)((int (__thiscall *)(CBaseServer *, char *))v13->GetName)(a1: v13, a2: v15);
        ConMsg(a1: "Relay \"%s\", connect to %s\n", v16, (const char *)HIDWORD(v28[0]));
      }
      else
      {
        HIDWORD(v28[0]) = hltv->GetName(this: &hltv->CBaseServer);
        ConMsg(a1: "Relay \"%s\", not connect.\n", HIDWORD(v28[0]));
      }
    }
    v17 = &hltv->CBaseServer;
    v18 = hltv->GetNumPlayers(this: &hltv->CBaseServer);
    v19 = ((int (__thiscall *)(CBaseServer *, int))v17->GetMapName)(a1: v17, a2: v18);
    v20 = ((double (__thiscall *)(CBaseServer *, double *, int))v17->GetTime)(a1: v17, a2: &v28[1], a3: v19);
    v21 = COM_FormatSeconds(seconds: (int)v20);
    ConMsg(
      a1: "Game Time %s, Mod \"%s\", Map \"%s\", Players %i\n",
      v21,
      (const char *)HIDWORD(v28[0]),
      (const char *)LODWORD(v28[1]),
      HIDWORD(v28[1]));
    v28[1] = *(float *)&gd_232[12];
    v28[0] = *(float *)gd_232;
    LODWORD(v28[0]) = ((int (__thiscall *)(CBaseServer *, _DWORD))hltv->GetUDPPort)(
                        a1: &hltv->CBaseServer,
                        a2: COERCE_UNSIGNED_INT64(*(float *)gd_232));
    v22 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
    ConMsg(
      a1: "Local IP %s:%i, KB/sec In %.1f, Out %.1f\n",
      v22,
      LODWORD(v28[0]),
      *(double *)((char *)v28 + 4),
      *(double *)((char *)&v28[1] + 4));
    hltv->GetLocalStats(this: &hltv->IHLTVServer, a2: (int *)&gd_232[4], a3: (int *)&gd_232[8], a4: (int *)&gd_232[16]);
    ConMsg(
      a1: "Local Slots %i, Spectators %i, Proxies %i\n",
      *(_DWORD *)&gd_232[8],
      *(_DWORD *)&gd_232[16] - *(_DWORD *)&gd_232[4],
      *(_DWORD *)&gd_232[4]);
    hltv->GetGlobalStats(this: &hltv->IHLTVServer, a2: (int *)&gd_232[4], a3: (int *)&gd_232[8], a4: (int *)&gd_232[16]);
    ConMsg(
      a1: "Total Slots %i, Spectators %i, Proxies %i\n",
      *(_DWORD *)&gd_232[8],
      *(_DWORD *)&gd_232[16] - *(_DWORD *)&gd_232[4],
      *(_DWORD *)&gd_232[4]);
    if ( hltv->m_DemoRecorder.IsRecording(this: &hltv->m_DemoRecorder) )
    {
      p_m_DemoRecorder = &hltv->m_DemoRecorder;
      v24 = hltv->m_DemoRecorder.GetRecordingTick(this: &hltv->m_DemoRecorder);
      v25 = COM_FormatSeconds(seconds: (int)(float)((float)v24 * host_state.interval_per_tick));
      v26 = (const char *)((int (__thiscall *)(CHLTVDemoRecorder *, char *))p_m_DemoRecorder->GetDemoFile)(
                            a1: p_m_DemoRecorder,
                            a2: v25);
      ConMsg(a1: "Recording to \"%s\", length %s.\n", v26, (const char *)HIDWORD(v28[0]));
    }
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181460
// Name: tv_stop
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_stop()
{
  int v0; // esi

  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v0 = hltv->GetNumClients(this: &hltv->CBaseServer);
    hltv->Shutdown(this: &hltv->CBaseServer);
    ConMsg(a1: "SourceTV stopped, %i clients disconnected.\n", v0);
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101814C0
// Name: tv_retry
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_retry()
{
  Remote_t *v0; // eax
  const char *v1; // eax
  Remote_t *v2; // eax
  const char *v3; // eax
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t TraceType; // eax
  char *v6; // [esp-8h] [ebp-8h]

  if ( hltv != nullptr )
  {
    if ( hltv->m_bMasterOnlyMode )
    {
      ConMsg(a1: "SourceTV in Master-Only mode.\n");
    }
    else if ( vgui::Image::GetWide(this: (CVTFTexture *)&hltv->m_ClientState.m_Remote) != 0 )
    {
      v0 = CAddressList::Get(this: &hltv->m_ClientState.m_Remote, index: 0);
      v1 = CUtlString::operator char const *(this: &v0->m_szRetryAddress);
      ConMsg(a1: "Commencing SourceTV connection retry to %s\n", v1);
      v2 = CAddressList::Get(this: &hltv->m_ClientState.m_Remote, index: 0);
      v3 = CUtlString::operator char const *(this: &v2->m_szRetryAddress);
      v6 = va(format: "tv_relay %s\n", v3);
      TraceType = CTraceFilter::GetTraceType(this: v4);
      Cbuf_AddText(eTarget: TraceType, pText: v6, nTickDelay: 0);
    }
    else
    {
      ConMsg(a1: "Can't retry, no previous SourceTV connection\n");
    }
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181580
// Name: tv_record
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_record(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  char name[260]; // [esp+4h] [ebp-104h] BYREF

  if ( args->m_nArgc >= 2 )
  {
    if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    {
      if ( hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
      {
        if ( hltv->m_DemoRecorder.IsRecording(this: &hltv->m_DemoRecorder) )
        {
          v1 = (const char *)hltv->m_DemoRecorder.GetDemoFile(this: &hltv->m_DemoRecorder);
          ConMsg(a1: "SourceTV already recording to %s.\n", v1);
        }
        else
        {
          v2 = defaultValue;
          if ( args->m_nArgc > 1 )
            v2 = args->m_ppArgv[1];
          if ( COM_IsValidPath(pszFilename: v2) )
          {
            v3 = defaultValue;
            if ( args->m_nArgc > 1 )
              v3 = args->m_ppArgv[1];
            V_strncpy(pDest: name, pSrc: v3, maxLen: 260);
            V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
            hltv->m_DemoRecorder.StartRecording(this: &hltv->m_DemoRecorder, a2: name, a3: false);
          }
          else if ( args->m_nArgc > 1 )
          {
            ConMsg(a1: "record %s: invalid path.\n", args->m_ppArgv[1]);
          }
          else
          {
            ConMsg(a1: "record %s: invalid path.\n", defaultValue);
          }
        }
      }
      else
      {
        ConMsg(a1: "Only SourceTV Master can record demos instantly.\n");
      }
    }
    else
    {
      ConMsg(a1: "SourceTV not active.\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  tv_record  <filename>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181700
// Name: tv_stoprecord
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_stoprecord()
{
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    hltv->m_DemoRecorder.StopRecording(this: &hltv->m_DemoRecorder);
  else
    ConMsg(a1: "SourceTV not active.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10181740
// Name: void EditDemo_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EditDemo_f(const CCommand *args)
{
  const char *v1; // eax
  char name[260]; // [esp+0h] [ebp-104h] BYREF

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc >= 2 )
    {
      if ( hltv != nullptr )
        demoplayer = &hltv->IDemoPlayer;
      else
        demoplayer = nullptr;
      v1 = defaultValue;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      V_strncpy(pDest: name, pSrc: v1, maxLen: 260);
      V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
      hltv->m_ClientState.m_bSaveMemory = true;
      demoplayer->StartPlayback(this: demoplayer, a2: name, a3: false);
    }
    else
    {
      _Msg(a1: "editdemo <demoname> : edits a demo\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181800
// Name: g_editdemo_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_editdemo_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S2_12 & 1) == 0 )
  {
    _S2_12 |= 1u;
    editdemoComplete.m_pszCommandName = "editdemo";
    editdemoComplete.m_pszSubDir = nullptr;
    editdemoComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &editdemoComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10181850
// Name: private: void CHLTVServer::FreeClientRecvTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::FreeClientRecvTables(CHLTVServer *this)
{
  CHLTVServer *v1; // ebx
  int v2; // edi
  void ***m_pRecvTables; // ebx
  vgui::PropertyPage *v4; // esi

  v1 = this;
  v2 = 0;
  if ( this->m_nRecvTables > 0 )
  {
    m_pRecvTables = (void ***)this->m_pRecvTables;
    do
    {
      v4 = (vgui::PropertyPage *)*m_pRecvTables;
      if ( **m_pRecvTables != nullptr )
        free(pMem: **m_pRecvTables);
      CColorBalanceUIPanel::Init(this: v4);
      free(pMem: v4);
      ++v2;
      ++m_pRecvTables;
    }
    while ( v2 < this->m_nRecvTables );
    v1 = this;
  }
  _V_memset(dest: v1->m_pRecvTables, fill: 0, count: 4096);
  v1->m_nRecvTables = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101818D0
// Name: public: void CHLTVFrame::CopyHLTVData(class CHLTVFrame __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVFrame::CopyHLTVData(CHLTVFrame *this, CHLTVFrame *frame)
{
  int m_iCurBit; // ebx
  int v3; // edi
  void *v4; // eax
  int v5; // eax
  int v6; // edi
  void *v7; // eax

  m_iCurBit = frame->m_Messages[1].m_iCurBit;
  if ( m_iCurBit > 0 )
  {
    v3 = 4 * ((((m_iCurBit + 7) >> 3) + 3) / 4);
    v4 = MemAlloc_Alloc(nSize: v3);
    bf_write::StartWriting(this: &this->m_Messages[1], pData: v4, nBytes: v3, iStartBit: m_iCurBit, nBits: -1);
    _V_memcpy(dest: this->m_Messages[1].m_pData, src: frame->m_Messages[1].m_pData, count: v3);
  }
  v5 = frame->m_Messages[2].m_iCurBit + frame->m_Messages[4].m_iCurBit + frame->m_Messages[5].m_iCurBit;
  if ( tv_relayvoice.m_pParent != nullptr && tv_relayvoice.m_pParent->m_Value.m_nValue != 0 )
    v5 += frame->m_Messages[3].m_iCurBit;
  if ( v5 > 0 )
  {
    v6 = 4 * ((((v5 + 7) >> 3) + 3) / 4);
    v7 = MemAlloc_Alloc(nSize: v6);
    bf_write::StartWriting(this: &this->m_Messages[2], pData: v7, nBytes: v6, iStartBit: 0, nBits: -1);
    bf_write::WriteBits(
      this: &this->m_Messages[2],
      pInData: frame->m_Messages[2].m_pData,
      nBits: frame->m_Messages[2].m_iCurBit);
    bf_write::WriteBits(
      this: &this->m_Messages[2],
      pInData: frame->m_Messages[5].m_pData,
      nBits: frame->m_Messages[5].m_iCurBit);
    bf_write::WriteBits(
      this: &this->m_Messages[2],
      pInData: frame->m_Messages[4].m_pData,
      nBits: frame->m_Messages[4].m_iCurBit);
    if ( tv_relayvoice.m_pParent != nullptr && tv_relayvoice.m_pParent->m_Value.m_nValue != 0 )
      bf_write::WriteBits(
        this: &this->m_Messages[2],
        pInData: frame->m_Messages[3].m_pData,
        nBits: frame->m_Messages[3].m_iCurBit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181A10
// Name: public: virtual void CHLTVServer::SetMaxClients(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::SetMaxClients(CHLTVServer *this, int number)
{
  int v2; // eax

  v2 = number;
  if ( number >= 0 )
  {
    if ( number > 64 )
      v2 = 64;
    this->serverclassbits = v2;
  }
  else
  {
    this->serverclassbits = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181A40
// Name: public: void CHLTVServer::StartMaster(class CGameClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::StartMaster(CHLTVServer *this, CGameClient *client)
{
  IHLTVDirector *v3; // ecx
  char *m_pszString; // eax
  int v5; // eax
  CGameClient *m_MasterClient; // ecx
  int v7; // eax
  CGameServer *m_Server; // ecx
  int v9; // eax
  CGameServer *v10; // ecx
  const char **v11; // eax
  const char **v12; // edi
  int i; // ebx
  CGameEventDescriptor *EventDescriptor; // eax
  int m_nValue; // eax
  int v16; // eax
  void (__thiscall *StopRecording)(struct CHLTVDemoRecorder *); // eax
  const char *eventname; // [esp+Ch] [ebp+8h]

  this->Clear(this: &this->CBaseServer);
  if ( client != nullptr )
  {
    v3 = serverGameDirector;
    this->m_Director = serverGameDirector;
    if ( v3 != nullptr )
    {
      this->m_MasterClient = client;
      client->m_bIsHLTV = true;
      serverGameClients->GetPlayerState(this: serverGameClients, a2: this->m_MasterClient->edict)->hltv = true;
      this->m_Server = (CGameServer *)this->m_MasterClient->GetServer(this: &this->m_MasterClient->IClient);
      if ( (tv_name.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = tv_name.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "name", value: m_pszString);
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "cl_team", value: "1");
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "rate", value: "30000");
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "cl_updaterate", value: "22");
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "cl_interp_ratio", value: "1.0");
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "cl_predict", value: "0");
      v5 = this->m_MasterClient->GetPlayerSlot(this: &this->m_MasterClient->IClient);
      m_MasterClient = this->m_MasterClient;
      this->m_nViewEntity = v5 + 1;
      v7 = m_MasterClient->GetPlayerSlot(this: &m_MasterClient->IClient);
      m_Server = this->m_Server;
      this->m_nPlayerSlot = v7;
      v9 = m_Server->GetMaxClients(this: m_Server);
      v10 = this->m_Server;
      this->m_nGameServerMaxClients = v9;
      this->serverclasses = v10->serverclasses;
      this->serverclassbits = v10->serverclassbits;
      this->worldmapCRC = v10->worldmapCRC;
      this->clientDllCRC = v10->clientDllCRC;
      this->m_flTickInterval = v10->GetTickInterval(this: v10);
      CHLTVFrame::AllocBuffers(this: &this->m_HLTVFrame);
      CHLTVServer::InstallStringTables(this);
      this->m_Director->SetHLTVServer(this: this->m_Director, a2: &this->IHLTVServer);
      v11 = this->m_Director->GetModEvents(this: this->m_Director);
      v12 = v11;
      for ( i = 0; *v11 != nullptr; v11 = &v12[i] )
      {
        eventname = *v11;
        EventDescriptor = CGameEventManager::GetEventDescriptor(this: g_GameEventManager, name: *v11, pCookie: nullptr);
        if ( EventDescriptor != nullptr )
          CGameEventManager::AddListener(
            this: g_GameEventManager,
            listener: this,
            descriptor: EventDescriptor,
            nListenerType: 2);
        else
          DevMsg(a1: "CHLTVServer::StartMaster: game event %s not found.\n", eventname);
        ++i;
      }
      bf_write::StartWriting(
        this: &this->m_Signon,
        pData: this->m_Server->m_Signon.m_pData,
        nBytes: this->m_Server->m_Signon.m_nDataBytes,
        iStartBit: this->m_Server->m_Signon.m_iCurBit,
        nBits: -1);
      V_strncpy(pDest: this->m_szMapname, pSrc: this->m_Server->m_szMapname, maxLen: 64);
      V_strncpy(pDest: this->m_szSkyname, pSrc: this->m_Server->m_szSkyname, maxLen: 64);
      NET_ListenSocket(sock: this->m_Socket, bListen: true);
      this->m_MasterClient->ExecuteStringCommand(this: &this->m_MasterClient->IClient, a2: "spectate");
      this->m_MasterClient->UpdateUserSettings(this: this->m_MasterClient);
      --this->m_MasterClient->m_nSignonTick;
      if ( this->m_bMasterOnlyMode )
      {
        if ( tv_maxclients.m_pParent != nullptr )
        {
          m_nValue = tv_maxclients.m_pParent->m_Value.m_nValue;
          if ( m_nValue > 1 )
            m_nValue = 1;
        }
        else
        {
          m_nValue = 0;
        }
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&tv_maxclients.IConVar, value: m_nValue);
      }
      if ( tv_maxclients.m_pParent != nullptr )
        v16 = tv_maxclients.m_pParent->m_Value.m_nValue;
      else
        v16 = 0;
      this->SetMaxClients(this: &this->CBaseServer, a2: v16);
      ++this->m_nSpawnCount;
      StopRecording = this->m_DemoRecorder.StopRecording;
      this->m_bSignonState = false;
      this->m_flStartTime = net_time;
      this->m_State = ss_active;
      StopRecording(this: &this->m_DemoRecorder);
      if ( tv_autorecord.m_pParent != nullptr && tv_autorecord.m_pParent->m_Value.m_nValue != 0 )
        CHLTVDemoRecorder::StartAutoRecording(this: &this->m_DemoRecorder);
      CBaseServer::ReconnectClients(this: &this->CBaseServer);
    }
    else
    {
      ConMsg(a1: "Mod doesn't support SourceTV. No director module found.\n");
    }
  }
  else
  {
    ConMsg(a1: "SourceTV client not found.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181DE0
// Name: public: void CHLTVServer::ConnectRelay(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::ConnectRelay(CHLTVServer *this, const char *address)
{
  if ( this->m_ClientState.m_nSignonState >= 2 )
  {
    CAddressList::RemoveAll(this: &this->m_ClientState.m_Remote);
    this->m_ClientState.Disconnect(this: &this->m_ClientState, a2: true);
    this->m_DemoRecorder.StopRecording(this: &this->m_DemoRecorder);
    CBaseServer::InactivateClients(this: &this->CBaseServer);
    CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
    this->m_CurrentFrame = nullptr;
  }
  this->m_ClientState.Connect(this: &this->m_ClientState, a2: address, a3: address);
}

//------------------------------------------------------------------------------
// Address: 0x10181E60
// Name: public: virtual void CHLTVServer::BroadcastEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::BroadcastEvent(CHLTVServer *this, IGameEvent *event)
{
  const char *v3; // eax
  const char *v4; // eax
  char buffer_data[1024]; // [esp+Ch] [ebp-450h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-50h] BYREF

  eventMsg.m_bReliable = true;
  eventMsg.m_NetChannel = nullptr;
  eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
  eventMsg.m_DataIn.m_bOverflow = false;
  eventMsg.m_DataIn.m_pDebugName = nullptr;
  eventMsg.m_DataIn.m_nDataBits = -1;
  eventMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &eventMsg.m_DataOut);
  bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
  if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventMsg.m_DataOut) )
  {
    (*(void (__thiscall **)(char *, SVC_GameEvent *, int, int))(*((_DWORD *)this - 128) + 136))(
      a1: (char *)this - 512,
      a2: &eventMsg,
      a3: 1,
      a4: 1);
    if ( tv_debug.m_pParent != nullptr && tv_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v4 = event->GetName(this: event);
      _Msg(a1: "SourceTV broadcast event: %s\n", v4);
    }
  }
  else
  {
    v3 = event->GetName(this: event);
    DevMsg(a1: "CHLTVServer: failed to serialize event '%s'.\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181F40
// Name: public: virtual void CHLTVServer::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::FireGameEvent(CHLTVServer *this, IGameEvent *event)
{
  const char *v3; // eax
  char buffer_data[1024]; // [esp+4h] [ebp-450h] BYREF
  SVC_GameEvent eventMsg; // [esp+404h] [ebp-50h] BYREF

  if ( this->IsActive(this: &this->CBaseServer) )
  {
    eventMsg.m_bReliable = true;
    eventMsg.m_NetChannel = nullptr;
    eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
    eventMsg.m_DataIn.m_bOverflow = false;
    eventMsg.m_DataIn.m_pDebugName = nullptr;
    eventMsg.m_DataIn.m_nDataBits = -1;
    eventMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &eventMsg.m_DataOut);
    bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
    if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventMsg.m_DataOut) )
    {
      CHLTVServer::SendNetMsg(this, msg: &eventMsg, bForceReliable: false, bVoice: false);
    }
    else
    {
      v3 = event->GetName(this: event);
      DevMsg(a1: "CHLTVServer::FireGameEvent: failed to serialize event '%s'.\n", v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181FF0
// Name: public: void CHLTVServer::LinkInstanceBaselines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::LinkInstanceBaselines(CHLTVServer *this)
{
  DWORD CurrentThreadId; // ecx
  ServerClass *i; // esi
  int v4; // eax
  char idString[36]; // [esp+8h] [ebp-24h] BYREF

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_svInstanceBaselineMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_svInstanceBaselineMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_svInstanceBaselineMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_svInstanceBaselineMutex.m_depth;
  }
  CBaseServer::GetInstanceBaselineTable(this: &this->CBaseServer);
  for ( i = serverGameDLL->GetAllServerClasses(this: serverGameDLL); i != nullptr; i = i->m_pNext )
  {
    V_snprintf(pDest: idString, maxLen: 32, pFormat: "%d", i->m_ClassID);
    v4 = this->m_pInstanceBaselineTable->FindStringIndex(this: this->m_pInstanceBaselineTable, a2: idString);
    if ( v4 == -1 )
      i->m_InstanceBaselineIndex = 0xFFFF;
    else
      i->m_InstanceBaselineIndex = v4;
  }
  if ( --g_svInstanceBaselineMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_svInstanceBaselineMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101820B0
// Name: public: void CHLTVServer::SignonComplete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::SignonComplete(CHLTVServer *this)
{
  this->m_bSignonState = false;
  CHLTVServer::LinkInstanceBaselines(this);
  if ( tv_debug.m_pParent != nullptr && tv_debug.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "SourceTV signon complete.\n");
}

//------------------------------------------------------------------------------
// Address: 0x101820E0
// Name: private: void CHLTVServer::UpdateStats(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVServer::UpdateStats(CHLTVServer *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  bool (__thiscall *IsMasterProxy)(IHLTVServer *); // edx
  int v5; // eax
  IGameEvent *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  int v9; // [esp-8h] [ebp-38h]
  int v10; // [esp-4h] [ebp-34h]
  char address[32]; // [esp+4h] [ebp-2Ch] BYREF
  int proxies; // [esp+24h] [ebp-Ch] BYREF
  int slots; // [esp+28h] [ebp-8h] BYREF
  int clients; // [esp+2Ch] [ebp-4h] BYREF

  if ( this->m_fNextSendUpdateTime <= net_time )
  {
    IsMasterProxy = this->IsMasterProxy;
    this->m_fNextSendUpdateTime = net_time + 8.0;
    if ( ((unsigned __int8 (__thiscall *)(IHLTVServer *, int, int))IsMasterProxy)(a1: &this->IHLTVServer, a2, a3) != 0
      || this->m_ClientState.m_nSignonState >= 2 )
    {
      ((void (__thiscall *)(IHLTVServer *, int *))this->GetGlobalStats)(a1: &this->IHLTVServer, a2: &proxies);
      v6 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "hltv_status", a3: 1, a4: 0);
      if ( v6 == nullptr )
        return;
      if ( ((unsigned __int8 (__thiscall *)(IHLTVServer *, int *, int *))this->IsMasterProxy)(
             a1: &this->IHLTVServer,
             a2: &slots,
             a3: &clients) != 0
        || tv_overridemaster.m_pParent != nullptr && tv_overridemaster.m_pParent->m_Value.m_nValue != 0 )
      {
        v10 = this->GetUDPPort(this: &this->CBaseServer);
        v8 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
        V_snprintf(pDest: address, maxLen: 32, pFormat: "%s:%u", v8, v10);
      }
      else
      {
        v7 = netadr_s::ToString(this: &this->m_RootServer, baseOnly: false);
        V_snprintf(pDest: address, maxLen: 32, pFormat: "%s", v7);
      }
      v6->SetString(this: v6, a2: "master", a3: address);
      v6->SetInt(this: v6, a2: "clients", a3: clients);
      v6->SetInt(this: v6, a2: "slots", a3: slots);
      ((void (__thiscall *)(IGameEvent *, const char *, int, int))v6->SetInt)(
        a1: v6,
        a2: "proxies",
        a3: proxies,
        a4: v9);
    }
    else
    {
      v5 = ((int (__thiscall *)(CGameEventManager *, const char *))g_GameEventManager->CreateEventA)(
             a1: g_GameEventManager,
             a2: "hltv_message");
      v6 = (IGameEvent *)v5;
      if ( v5 == 0 )
        return;
      (*(void (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)v5 + 56))(
        a1: v5,
        a2: "text",
        a3: "SourceTV reconnecting ...",
        a4: 1);
    }
    if ( this->IsMasterProxy(this: &this->IHLTVServer) )
      ((void (__thiscall *)(CGameEventManager *, IGameEvent *))g_GameEventManager->FireEvent)(
        a1: g_GameEventManager,
        a2: v6);
    else
      this->BroadcastEvent(this: &this->IHLTVServer, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101822B0
// Name: private: void CHLTVServer::ReadCompeleteDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::ReadCompeleteDemoFile(CHLTVServer *this)
{
  char *ConsoleCommand; // eax
  bool (__thiscall *ProcessStringCmd)(struct IServerMessageHandler *, NET_StringCmd *); // edx
  signed int RawData; // eax
  unsigned int v5[24000]; // [esp+Ch] [ebp-27C9Ch] BYREF
  unsigned int pData[16384]; // [esp+1770Ch] [ebp-1059Ch] BYREF
  char buffer[256]; // [esp+2770Ch] [ebp-59Ch] BYREF
  void **v8; // [esp+2780Ch] [ebp-49Ch] BYREF
  char v9; // [esp+27810h] [ebp-498h]
  int v10; // [esp+27814h] [ebp-494h]
  char *v11; // [esp+2781Ch] [ebp-48Ch]
  netadr_s dest; // [esp+27C20h] [ebp-88h] BYREF
  double v13; // [esp+27C30h] [ebp-78h]
  CBitRead v14; // [esp+27C3Ch] [ebp-6Ch] BYREF
  signed int v15; // [esp+27C60h] [ebp-48h]
  int nSeqNrIn; // [esp+27C70h] [ebp-38h] BYREF
  CBitRead v17; // [esp+27C74h] [ebp-34h] BYREF
  int tick; // [esp+27C98h] [ebp-10h] BYREF
  int nPlayerSlot; // [esp+27C9Ch] [ebp-Ch] BYREF
  int size; // [esp+27CA0h] [ebp-8h] BYREF
  unsigned __int8 cmd; // [esp+27CA7h] [ebp-1h] BYREF

  tick = 0;
  cmd = 1;
  netadr_s::SetIP(this: &dest, unIP: 0);
  netadr_s::SetPort(this: &dest, newport: 0);
  netadr_s::SetType(this: &dest, newtype: NA_IP);
  v14.m_bOverflow = false;
  v14.m_pDebugName = nullptr;
  v14.m_nDataBits = -1;
  v14.m_nDataBytes = 0;
  _V_memset(&dest, fill: 0, count: 80);
  netadr_s::SetType(this: &dest, newtype: NA_LOOPBACK);
  while ( 1 )
  {
    nPlayerSlot = 0;
    CDemoFile::ReadCmdHeader(this: &this->m_DemoFile, &cmd, &tick, &nPlayerSlot);
    switch ( cmd )
    {
      case 1u:
      case 2u:
        size = 0;
        CDemoFile::ReadCmdInfo(this: &this->m_DemoFile, info: &this->m_LastCmdInfo);
        CDemoFile::ReadSequenceInfo(this: &this->m_DemoFile, &nSeqNrIn, nSeqNrOut: &size);
        RawData = CDemoFile::ReadRawData(this: &this->m_DemoFile, buffer: (char *)v5, length: 96000);
        if ( RawData > 0 )
        {
          v13 = realtime;
          v15 = RawData;
          CBitRead::StartReading(this: &v14, pData: v5, nBytes: RawData, iStartBit: 0, nBits: -1);
          this->m_ClientState.m_NetChannel->ProcessPacket(
            this: this->m_ClientState.m_NetChannel,
            a2: (netpacket_s *)&dest,
            a3: false);
        }
        break;
      case 3u:
        this->m_nStartTick = host_tickcount;
        break;
      case 4u:
        ConsoleCommand = CDemoFile::ReadConsoleCommand(this: &this->m_DemoFile);
        ProcessStringCmd = this->m_ClientState.ProcessStringCmd;
        v11 = ConsoleCommand;
        v9 = 1;
        v10 = 0;
        v8 = &NET_StringCmd::`vftable';
        ProcessStringCmd(this: &this->m_ClientState.IServerMessageHandler, a2: (NET_StringCmd *)&v8);
        break;
      case 5u:
        size = 256;
        CDemoFile::ReadUserCmd(this: &this->m_DemoFile, buffer, &size);
        break;
      case 6u:
        v17.m_bOverflow = false;
        v17.m_nDataBits = -1;
        v17.m_nDataBytes = 0;
        v17.m_pDebugName = "dem_datatables";
        CBitRead::StartReading(this: &v17, pData, nBytes: 0x10000u, iStartBit: 0, nBits: -1);
        CDemoFile::ReadStringTables(this: &this->m_DemoFile, buf: (bf_read *)&v17);
        CBitRead::Seek(this: &v17, nPosition: 0);
        if ( !DataTable_LoadDataTablesFromBuffer(
                pBuf: (bf_read *)&v17,
                nDemoProtocol: this->m_DemoFile.m_DemoHeader.demoprotocol) )
          Host_Error(error: "Error parsing network data tables during demo playback.");
        break;
      case 7u:
        return;
      case 9u:
        size = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x80000);
        v17.m_bOverflow = false;
        v17.m_nDataBits = -1;
        v17.m_nDataBytes = 0;
        v17.m_pDebugName = "dem_stringtables";
        CBitRead::StartReading(this: &v17, pData: (const unsigned int *)size, nBytes: 0x80000u, iStartBit: 0, nBits: -1);
        CDemoFile::ReadStringTables(this: &this->m_DemoFile, buf: (bf_read *)&v17);
        CBitRead::Seek(this: &v17, nPosition: 0);
        if ( !CNetworkStringTableContainer::ReadStringTables(
                this: networkStringTableContainerClient,
                buf: (bf_read *)&v17) )
          Host_Error(error: "Error parsing string tables during demo playback.");
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)size);
        break;
      default:
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101825A0
// Name: public: bool CHLTVServer::DispatchToRelay(class CHLTVClient __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CHLTVServer::DispatchToRelay@<al>(CHLTVServer *this@<ecx>, int a2@<edi>, CHLTVClient *pClient)
{
  CHLTVServer *v3; // esi
  int (__thiscall *GetClientCount)(struct CBaseServer *); // edx
  CBaseServer *v6; // edi
  CHLTVClient *v7; // ebx
  bool (__thiscall *IsConnected)(IClient *); // eax
  IClient *v9; // esi
  const char *v10; // eax
  int v11; // ebx
  const char *v12; // eax
  int v13; // eax
  int (__thiscall *v14)(struct CBaseServer *); // eax
  CBaseClient *v15; // ebx
  int v16; // eax
  int (__thiscall *GetMaxClients)(struct CBaseServer *); // edx
  float v18; // xmm0_4
  int v19; // eax
  netadr_s *v20; // eax
  const char *v21; // eax
  void (__thiscall *FillServerInfo)(CBaseServer *, SVC_ServerInfo *); // edx
  const char *v23; // eax
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // edx
  const char *v25; // eax
  int v26; // eax
  CBaseClient *v27; // edi
  CBaseClient_vtbl *v28; // esi
  char *v29; // eax
  SVC_ServerInfo serverInfo; // [esp+4h] [ebp-880h] BYREF
  NET_StringCmd cmdMsg; // [esp+45Ch] [ebp-428h] BYREF
  CHLTVServer *v33; // [esp+870h] [ebp-14h]
  int i; // [esp+874h] [ebp-10h]
  CBaseClient *pProxy; // [esp+878h] [ebp-Ch]
  CBaseClient *pBestProxy; // [esp+87Ch] [ebp-8h]
  float fBestRatio; // [esp+880h] [ebp-4h]

  v3 = this;
  v33 = this;
  if ( tv_dispatchmode.m_pParent == nullptr || tv_dispatchmode.m_pParent->m_Value.m_nValue <= 0 )
    return 0;
  GetClientCount = this->GetClientCount;
  v6 = &this->CBaseServer;
  pBestProxy = nullptr;
  i = 0;
  fBestRatio = 1.0;
  if ( GetClientCount(this: &this->CBaseServer) > 0 )
  {
    while ( 1 )
    {
      v7 = (CHLTVClient *)v3->m_Clients.m_Memory.m_pMemory[i];
      IsConnected = v7->IsConnected;
      v9 = &v7->IClient;
      pProxy = v7;
      if ( IsConnected(this: &v7->IClient) && v9->IsHLTV(this: &v7->IClient) && pClient != v7 )
      {
        v10 = v9->GetUserSetting(this: &v7->IClient, a2: "hltv_slots");
        v11 = V_atoi(str: v10);
        v12 = v9->GetUserSetting(this: v9, a2: "hltv_clients");
        v13 = V_atoi(str: v12);
        if ( v13 <= v11 && v11 > 0 && fBestRatio > (float)((float)v13 / (float)v11) )
        {
          fBestRatio = (float)v13 / (float)v11;
          pBestProxy = pProxy;
        }
      }
      v14 = v6->GetClientCount;
      if ( ++i >= v14(this: v6) )
        break;
      v3 = v33;
    }
    v15 = pBestProxy;
    if ( pBestProxy != nullptr )
    {
      if ( tv_dispatchmode.m_pParent != nullptr
        && tv_dispatchmode.m_pParent->m_Value.m_nValue == 1
        && v6->GetMaxClients(this: v6) > 0 )
      {
        v16 = v6->GetNumClients(this: v6);
        GetMaxClients = v6->GetMaxClients;
        *(float *)&pProxy = (float)v16;
        v18 = (float)((float)v16 / (float)GetMaxClients(this: v6)) * 1.25;
        if ( v18 >= 1.0 )
          v18 = 1.0;
        if ( fBestRatio > v18 )
          return 0;
      }
      fBestRatio = COERCE_FLOAT((int)pBestProxy->GetUserSetting(this: &pBestProxy->IClient, a2: "hltv_addr"));
      if ( fBestRatio == 0.0 )
        return 0;
      v19 = ((int (__thiscall *)(IClient *, int))pClient->GetNetChannel)(a1: &pClient->IClient, a2);
      v20 = (netadr_s *)(*(int (__thiscall **)(int))(*(_DWORD *)v19 + 196))(a1: v19);
      v21 = netadr_s::ToString(this: v20, baseOnly: false);
      ConMsg(a1: "Redirecting spectator %s to SourceTV relay %s\n", v21, (const char *)LODWORD(fBestRatio));
      FillServerInfo = v6->FillServerInfo;
      serverInfo.m_bReliable = true;
      serverInfo.m_NetChannel = nullptr;
      serverInfo.__vftable = (SVC_ServerInfo_vtbl *)&SVC_ServerInfo::`vftable';
      FillServerInfo(this: v6, a2: &serverInfo);
      pClient->SendNetMsg(this: &pClient->IClient, a2: &serverInfo, a3: true, a4: false);
      v23 = va(format: "connect %s\n", (const char *)LODWORD(fBestRatio));
      SendNetMsg = pClient->SendNetMsg;
      cmdMsg.m_szCommand = v23;
      cmdMsg.m_bReliable = true;
      cmdMsg.m_NetChannel = nullptr;
      cmdMsg.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
      SendNetMsg(this: &pClient->IClient, a2: &cmdMsg, a3: true, a4: false);
      v25 = v15->GetUserSetting(this: &v15->IClient, a2: "hltv_clients");
      v26 = V_atoi(str: v25);
      v27 = pBestProxy;
      v28 = pBestProxy->IGameEventListener2::__vftable;
      v29 = va(format: "%d", v26 + 1);
      v28->SetUserCVar(this: v27, a2: "hltv_clients", a3: v29);
      return 1;
    }
  }
  if ( tv_dispatchmode.m_pParent != nullptr && tv_dispatchmode.m_pParent->m_Value.m_nValue == 2 )
  {
    pClient->Disconnect(this: &pClient->IClient, a2: "No SourceTV relay available");
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10182880
// Name: public: void CHLTVServer::GetRelayStats(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::GetRelayStats(CHLTVServer *this, int *proxies, int *slots, int *clients)
{
  CHLTVServer *v5; // esi
  CBaseClient *v6; // esi
  bool (__thiscall *IsConnected)(IClient *); // edx
  IClient *v8; // esi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int i; // [esp+20h] [ebp+10h]

  v5 = this;
  *clients = 0;
  *slots = 0;
  *proxies = 0;
  i = 0;
  if ( this->GetClientCount(this: &this->CBaseServer) > 0 )
  {
    while ( 1 )
    {
      v6 = v5->m_Clients.m_Memory.m_pMemory[i];
      IsConnected = v6->IsConnected;
      v8 = &v6->IClient;
      if ( IsConnected(this: v8) && v8->IsHLTV(this: v8) )
      {
        v9 = v8->GetUserSetting(this: v8, a2: "hltv_proxies");
        *proxies += V_atoi(str: v9);
        v10 = v8->GetUserSetting(this: v8, a2: "hltv_slots");
        *slots += V_atoi(str: v10);
        v11 = v8->GetUserSetting(this: v8, a2: "hltv_clients");
        *clients += V_atoi(str: v11);
      }
      if ( ++i >= this->GetClientCount(this: &this->CBaseServer) )
        break;
      v5 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182970
// Name: public: virtual void CHLTVServer::GetGlobalStats(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::GetGlobalStats(CHLTVServer *this, int *proxies, int *slots, int *clients)
{
  int v5; // eax
  int v6; // edx

  if ( (unsigned __int8)this->IGameEventListener2::__vftable[2].GetEventDebugID(this) != 0 )
  {
    CHLTVServer::GetRelayStats(
      this: (CHLTVServer *)((char *)this - 520),
      proxies: (int *)&this->m_pRecvTables[904],
      slots: (int *)&this->m_pRecvTables[902],
      clients: (int *)&this->m_pRecvTables[903]);
    v5 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 128) + 20))(a1: (char *)this - 512);
    v6 = *((_DWORD *)this - 128);
    this->m_pRecvTables[902] = (RecvTable *)((char *)this->m_pRecvTables[902] + v5);
    this->m_pRecvTables[903] = (RecvTable *)((char *)this->m_pRecvTables[903]
                                           + (*(int (__thiscall **)(char *))(v6 + 8))(a1: (char *)this - 512));
  }
  *proxies = (int)this->m_pRecvTables[904];
  *slots = (int)this->m_pRecvTables[902];
  *clients = (int)this->m_pRecvTables[903];
}

//------------------------------------------------------------------------------
// Address: 0x10182A00
// Name: public: void CHLTVServer::BroadcastLocalTitle(class CHLTVClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::BroadcastLocalTitle(CHLTVServer *this, CHLTVClient *client)
{
  CHLTVServer *v2; // esi
  IGameEvent *(__thiscall *CreateEventA)(struct CGameEventManager *, const char *, bool, int *); // edx
  int v4; // edi
  IGameEvent *v5; // ebx
  char *m_pszString; // eax
  const char *v7; // eax
  CBaseClient *v8; // esi
  bool (__thiscall *IsActive)(IClient *); // eax
  IClient *v10; // esi
  char buffer_data[1024]; // [esp+Ch] [ebp-454h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-54h] BYREF
  CHLTVServer *v13; // [esp+45Ch] [ebp-4h]

  v2 = this;
  CreateEventA = g_GameEventManager->CreateEventA;
  v4 = 0;
  v13 = this;
  v5 = CreateEventA(this: g_GameEventManager, a2: "hltv_title", a3: true, a4: nullptr);
  if ( v5 != nullptr )
  {
    if ( (tv_title.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = tv_title.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    v5->SetString(this: v5, a2: "text", a3: m_pszString);
    eventMsg.m_NetChannel = nullptr;
    eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
    eventMsg.m_DataIn.m_bOverflow = false;
    eventMsg.m_DataIn.m_pDebugName = nullptr;
    eventMsg.m_DataIn.m_nDataBits = -1;
    eventMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &eventMsg.m_DataOut);
    eventMsg.m_bReliable = true;
    bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
    if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: v5, a3: &eventMsg.m_DataOut) )
    {
      if ( client != nullptr )
      {
        client->SendNetMsg(this: &client->IClient, a2: &eventMsg, a3: false, a4: false);
      }
      else if ( v2->m_Clients.m_Size > 0 )
      {
        while ( 1 )
        {
          v8 = v2->m_Clients.m_Memory.m_pMemory[v4];
          IsActive = v8->IsActive;
          v10 = &v8->IClient;
          if ( IsActive(this: v10) && !v10->IsHLTV(this: v10) )
            v10->SendNetMsg(this: v10, a2: &eventMsg, a3: false, a4: false);
          if ( ++v4 >= v13->m_Clients.m_Size )
            break;
          v2 = v13;
        }
      }
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v5);
    }
    else
    {
      v7 = v5->GetName(this: v5);
      DevMsg(a1: "CHLTVServer: failed to serialize title '%s'.\n", v7);
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182B80
// Name: public: void CHLTVServer::BroadcastLocalChat(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::BroadcastLocalChat(CHLTVServer *this, const char *pszChat, const char *pszGroup)
{
  CHLTVServer *v3; // esi
  IGameEvent *(__thiscall *CreateEventA)(struct CGameEventManager *, const char *, bool, int *); // edx
  IGameEvent *v5; // ebx
  const char *v6; // eax
  CBaseClient *v7; // edi
  char buffer_data[1024]; // [esp+Ch] [ebp-454h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-54h] BYREF
  CHLTVServer *v10; // [esp+45Ch] [ebp-4h]
  int i; // [esp+468h] [ebp+8h]

  v3 = this;
  CreateEventA = g_GameEventManager->CreateEventA;
  v10 = this;
  v5 = CreateEventA(this: g_GameEventManager, a2: "hltv_chat", a3: true, a4: nullptr);
  if ( v5 != nullptr )
  {
    v5->SetString(this: v5, a2: "text", a3: pszChat);
    eventMsg.m_NetChannel = nullptr;
    eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
    eventMsg.m_DataIn.m_bOverflow = false;
    eventMsg.m_DataIn.m_pDebugName = nullptr;
    eventMsg.m_DataIn.m_nDataBits = -1;
    eventMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &eventMsg.m_DataOut);
    eventMsg.m_bReliable = false;
    bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
    if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: v5, a3: &eventMsg.m_DataOut) )
    {
      i = 0;
      if ( v3->m_Clients.m_Size > 0 )
      {
        while ( 1 )
        {
          v7 = v3->m_Clients.m_Memory.m_pMemory[i];
          if ( v7->IsActive(this: &v7->IClient)
            && v7->IsSpawned(this: &v7->IClient)
            && !v7->IsHLTV(this: &v7->IClient)
            && _V_strcmp(s1: &v7[1].m_GUID[5], s2: pszGroup) == 0
            && v7[1].m_GUID[4] == 0 )
          {
            v7->SendNetMsg(this: &v7->IClient, a2: &eventMsg, a3: false, a4: false);
          }
          if ( ++i >= v10->m_Clients.m_Size )
            break;
          v3 = v10;
        }
      }
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v5);
    }
    else
    {
      v6 = v5->GetName(this: v5);
      DevMsg(a1: "CHLTVServer: failed to serialize chat '%s'.\n", v6);
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182D10
// Name: public: void CHLTVServer::BroadcastEventLocal(class IGameEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::BroadcastEventLocal(CHLTVServer *this, IGameEvent *event, bool bReliable)
{
  int v3; // edi
  IGameEvent *v5; // esi
  const char *v6; // eax
  CBaseClient *v7; // esi
  bool (__thiscall *IsActive)(IClient *); // eax
  IClient *v9; // esi
  const char *v10; // eax
  const char *v11; // eax
  char buffer_data[1024]; // [esp+Ch] [ebp-450h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-50h] BYREF

  v3 = 0;
  eventMsg.m_NetChannel = nullptr;
  eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
  eventMsg.m_DataIn.m_bOverflow = false;
  eventMsg.m_DataIn.m_pDebugName = nullptr;
  eventMsg.m_DataIn.m_nDataBits = -1;
  eventMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &eventMsg.m_DataOut);
  eventMsg.m_bReliable = bReliable;
  bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
  v5 = event;
  if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventMsg.m_DataOut) )
  {
    if ( this->m_Clients.m_Size > 0 )
    {
      do
      {
        v7 = this->m_Clients.m_Memory.m_pMemory[v3];
        IsActive = v7->IsActive;
        v9 = &v7->IClient;
        if ( IsActive(this: v9)
          && v9->IsSpawned(this: v9)
          && !v9->IsHLTV(this: v9)
          && !v9->SendNetMsg(this: v9, a2: &eventMsg, a3: false, a4: false)
          && eventMsg.m_bReliable )
        {
          v10 = v9->GetClientName(this: v9);
          DevMsg(a1: "BroadcastMessage: Reliable broadcast message overflow for client %s", v10);
        }
        ++v3;
      }
      while ( v3 < this->m_Clients.m_Size );
      v5 = event;
    }
    if ( tv_debug.m_pParent != nullptr && tv_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v11 = v5->GetName(this: v5);
      _Msg(a1: "SourceTV broadcast local event: %s\n", v11);
    }
  }
  else
  {
    v6 = event->GetName(this: event);
    DevMsg(a1: "CHLTVServer: failed to serialize local event '%s'.\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182E60
// Name: private: void CHLTVServer::EntityPVSCheck(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::EntityPVSCheck(CHLTVServer *this, CClientFrame *pFrame)
{
  IHLTVDirector *m_Director; // ecx
  CFrameSnapshot *v4; // edi
  int (__thiscall *GetPVSEntity)(IHLTVDirector *); // eax
  int v6; // eax
  Vector *HLTVDataInSnapshot; // eax
  int v8; // esi
  int v9; // ecx
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int *v12; // edx
  int v13; // edi
  CHLTVEntityData *v14; // eax
  int m_nNodeCluster; // eax
  unsigned __int8 pvs[8192]; // [esp+Ch] [ebp-2014h] BYREF
  _BYTE v17[12]; // [esp+200Ch] [ebp-14h] BYREF
  CFrameSnapshot *pSnapshot; // [esp+2018h] [ebp-8h]
  int vissize; // [esp+201Ch] [ebp-4h]

  vissize = (g_BSPData.numclusters + 7) / 8;
  SV_ResetPVS(pvs, nPVSSize: vissize);
  m_Director = this->m_Director;
  GetPVSEntity = m_Director->GetPVSEntity;
  pSnapshot = pFrame->m_pSnapshot;
  v4 = pSnapshot;
  v6 = GetPVSEntity(this: m_Director);
  if ( v4 == nullptr || v6 <= 0 )
  {
    HLTVDataInSnapshot = this->m_Director->GetPVSOrigin(this: this->m_Director, result: v17);
LABEL_6:
    this->m_vPVSOrigin.x = HLTVDataInSnapshot->x;
    this->m_vPVSOrigin.y = HLTVDataInSnapshot->y;
    this->m_vPVSOrigin.z = HLTVDataInSnapshot->z;
    goto LABEL_7;
  }
  HLTVDataInSnapshot = (Vector *)FindHLTVDataInSnapshot(pSnapshot: v4, iEntIndex: v6);
  if ( HLTVDataInSnapshot != nullptr )
    goto LABEL_6;
LABEL_7:
  SV_AddOriginToPVS(vOrigin: &this->m_vPVSOrigin);
  v8 = -1;
  while ( 1 )
  {
    v9 = v8 + 1;
    if ( v8 + 1 >= 2048 )
      break;
    v10 = v9 >> 5;
    v11 = pFrame->transmit_entity.m_Ints[v9 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v9 & 0x1F];
    v12 = &pFrame->transmit_entity.m_Ints[v10];
    while ( v11 == 0 )
    {
      v11 = v12[1];
      ++v12;
      if ( ++v10 > 63 )
        return;
    }
    _BitScanForward(&v11, v11);
    v8 = v11 + 32 * v10;
    if ( v8 < 0 )
      break;
    v13 = 1 << (v8 & 0x1F);
    if ( (v13 & pFrame->transmit_always->m_Ints[(unsigned int)v8 >> 5]) != 0 )
    {
      pFrame->last_entity = v8;
    }
    else
    {
      v14 = FindHLTVDataInSnapshot(pSnapshot, iEntIndex: v8);
      if ( v14 != nullptr )
      {
        m_nNodeCluster = v14->m_nNodeCluster;
        if ( m_nNodeCluster >= 0 )
        {
          if ( ((unsigned __int8)(1 << (m_nNodeCluster & 7)) & pvs[(unsigned int)m_nNodeCluster >> 3]) != 0 )
            pFrame->last_entity = v8;
          else
LABEL_22:
            pFrame->transmit_entity.m_Ints[v8 >> 5] &= ~v13;
        }
        else
        {
          if ( !CM_HeadnodeVisible(nodenum: m_nNodeCluster & 0x7FFFFFFF, visbits: pvs, vissize) )
            goto LABEL_22;
          pFrame->last_entity = v8;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182FE0
// Name: public: virtual void CHLTVServer::SendClientMessages(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::SendClientMessages(CHLTVServer *this, bool bSendSnapshots)
{
  int i; // ebx
  long double *v4; // esi

  for ( i = 0; i < this->m_Clients.m_Memory.m_nAllocationCount; ++i )
  {
    v4 = *(long double **)(LODWORD(this->m_flTickInterval) + 4 * i);
    if ( (*(unsigned __int8 (__thiscall **)(long double *))(*(_DWORD *)v4 + 20))(a1: v4) != 0 )
    {
      if ( this->m_nFirstTick != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*((_DWORD *)v4 + 1) + 132))(a1: (int)v4 + 4) != 0 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 44))(a1: this->m_nFirstTick);
      }
      else
      {
        (*(void (__stdcall **)(_DWORD))(**((_DWORD **)v4 + 55) + 192))(a1: 0);
      }
      (*(void (__thiscall **)(long double *))(*(_DWORD *)v4 + 24))(a1: v4);
      v4[15073] = net_time;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183070
// Name: public: virtual bool CHLTVServer::StartPlayback(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVServer::StartPlayback(CHLTVServer *this, const char *filename, bool bAsTimeDemo)
{
  INetChannel *NetChannel; // eax
  CStatTime *v6; // ecx
  CStatTime *v7; // ecx
  double v8; // st7
  double v9; // [esp+10h] [ebp-8h]

  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 129) + 168))(a1: (char *)this - 516);
  if ( CDemoFile::Open(
         this: (CDemoFile *)&this->m_DeltaCache.m_Cache[1922],
         name: filename,
         bReadOnly: true,
         bMemoryBuffer: false) == 0 )
    return 0;
  if ( CDemoFile::ReadDemoHeader(this: (CDemoFile *)&this->m_DeltaCache.m_Cache[1922]) == nullptr )
  {
    ConMsg(a1: "Failed to read demo header.\n");
    CDemoFile::Close(this: (CDemoFile *)&this->m_DeltaCache.m_Cache[1922]);
    return 0;
  }
  NetChannel = NET_CreateNetChannel(
                 socket: 0,
                 adr: nullptr,
                 name: "DEMO",
                 handler: (INetChannelHandler *)&this->m_State,
                 bForceNewChannel: false);
  *(_DWORD *)&this->m_szMapname[4] = NetChannel;
  if ( NetChannel != nullptr )
  {
    ((void (__thiscall *)(INetChannel *, _DWORD, _DWORD))NetChannel->SetTimeout)(a1: NetChannel, a2: -1.0, a3: 0);
    this->m_DemoFile.m_DemoHeader.mapname[172] = 1;
    ConMsg(a1: "Reading complete demo file at once...\n");
    v9 = _Plat_FloatTime(this: v6);
    CHLTVServer::ReadCompeleteDemoFile(this: (CHLTVServer *)((char *)this - 524));
    v8 = _Plat_FloatTime(this: v7);
    ConMsg(a1: "Reading time :%.4f\n", v8 - v9);
    NET_RemoveNetChannel(netchan: *(INetChannel **)&this->m_szMapname[4], bDeleteNetChan: true);
    *(_DWORD *)&this->m_szMapname[4] = 0;
    return 1;
  }
  else
  {
    ConMsg(a1: "CDemo::Play: failed to create demo net channel\n");
    CDemoFile::Close(this: (CDemoFile *)&this->m_DeltaCache.m_Cache[1922]);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183190
// Name: tv_clients
// Source: json
//------------------------------------------------------------------------------
void __usercall tv_clients(int a1@<edi>, int a2@<esi>)
{
  int v2; // ebx
  CBaseClient *v3; // edi
  INetChannel *(__thiscall *GetNetChannel)(IClient *); // eax
  IClient *v5; // edi
  int v6; // esi
  const char *v7; // ebx
  double v8; // st7
  int v9; // eax
  double v10; // st7
  char *v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // [esp-10h] [ebp-34h]
  const char *v15; // [esp-Ch] [ebp-30h]
  const char *v16; // [esp-8h] [ebp-2Ch]
  const char *v17; // [esp-4h] [ebp-28h]
  double v18; // [esp+0h] [ebp-24h]
  _BYTE v19[12]; // [esp+8h] [ebp-1Ch]
  int v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]

  v2 = 0;
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v22 = 0;
    v21 = 0;
    if ( hltv->GetClientCount(this: &hltv->CBaseServer) > 0 )
    {
      *(_DWORD *)&v19[8] = a1;
      do
      {
        v3 = hltv->m_Clients.m_Memory.m_pMemory[v2];
        GetNetChannel = v3->GetNetChannel;
        v5 = &v3->IClient;
        v6 = (int)GetNetChannel(this: v5);
        if ( v6 != 0 )
        {
          v7 = "(Relay)";
          if ( ((unsigned __int8 (__thiscall *)(IClient *, _DWORD, int))v5->IsHLTV)(
                 a1: v5,
                 a2: *(_DWORD *)&v19[8],
                 a3: a2) == 0 )
            v7 = defaultValue;
          a2 = 0;
          *(double *)&v19[4] = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v6 + 52))(a1: v6) * 0.0009765625;
          v8 = ((double (__thiscall *)(int, int, _DWORD))*(_DWORD *)(*(_DWORD *)v6 + 52))(
                 a1: v6,
                 a2: 1,
                 a3: *(_DWORD *)&v19[4]);
          v9 = (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v6 + 4))(
                 a1: v6,
                 a2: COERCE_UNSIGNED_INT64(v8 * 0.0009765625),
                 a3: HIDWORD(COERCE_UNSIGNED_INT64(v8 * 0.0009765625)));
          v10 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v6 + 12))(a1: v6, a2: v9);
          v11 = COM_FormatSeconds(seconds: (int)v10);
          v12 = ((int (__thiscall *)(IClient *, const char *, char *))v5->GetClientName)(a1: v5, a2: v7, a3: v11);
          v13 = ((int (__thiscall *)(IClient *, int))v5->GetUserID)(a1: v5, a2: v12);
          ConMsg(
            a1: "ID: %i, \"%s\" %s, Time %s, %s, In %.1f, Out %.1f.\n",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            *(double *)v19);
          v2 = v21;
          ++v22;
        }
        v21 = ++v2;
      }
      while ( v2 < hltv->GetClientCount(this: &hltv->CBaseServer) );
    }
    ConMsg(a1: "--- Total %i connected clients ---\n", v22);
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101832F0
// Name: tv_msg
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_msg(const CCommand *args)
{
  IGameEvent *v1; // esi
  int m_nArgv0Size; // eax
  bool v3; // zf
  char *v4; // eax

  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v1 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "hltv_message", a3: 1, a4: 0);
    if ( v1 != nullptr )
    {
      m_nArgv0Size = args->m_nArgv0Size;
      v3 = m_nArgv0Size == 0;
      v4 = &args->m_pArgSBuffer[m_nArgv0Size];
      if ( v3 )
        v4 = (char *)defaultValue;
      v1->SetString(this: v1, a2: "text", a3: v4);
      CHLTVServer::BroadcastEventLocal(this: hltv, event: v1, bReliable: false);
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v1);
    }
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183380
// Name: tv_title_changed_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_title_changed_f()
{
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    CHLTVServer::BroadcastLocalTitle(this: hltv, client: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101833B0
// Name: private: void CHLTVServer::UpdateTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::UpdateTick(CHLTVServer *this)
{
  int m_nLastTick; // edi
  CHLTVFrame *ClientFrame; // eax
  IHLTVServer_vtbl *v4; // edx
  float v5; // xmm0_4

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CHLTVServer::UpdateTick",
    a3: 0,
    a4: "HLTV",
    a5: false,
    a6: 4);
  if ( this->m_nFirstTick >= 0 )
  {
    m_nLastTick = this->m_nLastTick;
    if ( this->IsMasterProxy(this: &this->IHLTVServer) )
    {
      m_nLastTick = this->m_nFirstTick;
      if ( m_nLastTick <= this->m_Director->GetDirectorTick(this: this->m_Director) )
        m_nLastTick = this->m_Director->GetDirectorTick(this: this->m_Director);
    }
    ClientFrame = (CHLTVFrame *)CClientFrameManager::GetClientFrame(
                                  this: &this->CClientFrameManager,
                                  nTick: m_nLastTick,
                                  bExact: false);
    if ( ClientFrame == nullptr || this->m_CurrentFrame == ClientFrame )
    {
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    else
    {
      v4 = this->IHLTVServer::IBaseInterface::__vftable;
      this->m_CurrentFrame = ClientFrame;
      this->m_nTickCount = ClientFrame->tick_count;
      if ( v4->IsMasterProxy(this: &this->IHLTVServer) )
      {
        CHLTVServer::RestoreTick(this, tick: this->m_nTickCount);
        if ( tv_transmitall.m_pParent == nullptr || tv_transmitall.m_pParent->m_Value.m_nValue == 0 )
          CHLTVServer::EntityPVSCheck(this, pFrame: this->m_CurrentFrame);
      }
      else
      {
        CDeltaEntityCache::SetTick(
          this: &this->m_DeltaCache,
          nTick: this->m_CurrentFrame->tick_count,
          nMaxEntities: this->m_CurrentFrame->last_entity + 1);
      }
      v5 = (float)this->m_nTickCount - (float)(16.0 / this->m_flTickInterval);
      if ( (int)v5 > 0 )
        CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: (int)v5);
      this->m_FrameCache.m_Size = 0;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
  }
  else
  {
    this->m_nTickCount = 0;
    this->m_CurrentFrame = nullptr;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183520
// Name: public: virtual void CHLTVServer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::Clear(CHLTVServer *this)
{
  void (__thiscall *v2)(int *); // edx

  CBaseServer::Clear((CBaseServer *)this);
  v2 = *(void (__thiscall **)(int *))(this->m_nDebugID + 44);
  this->m_DemoRecorder.m_MessageData.m_pDebugName = nullptr;
  this->IDemoPlayer::__vftable = nullptr;
  v2(a1: &this->m_nDebugID);
  *(_DWORD *)&this->m_DemoRecorder.m_MessageData.m_bOverflow = 0;
  this->m_Server = (CGameServer *)-1;
  this->m_Director = nullptr;
  this->m_State = ss_dead;
  this->m_nFirstTick = 0;
  this->m_CurrentFrame = nullptr;
  this->m_HLTVFrame.m_Messages[5].m_pDebugName = nullptr;
  this->m_nLastTick = 1;
  this->m_flStartTime = 0.0;
  this->m_flFPS = 0.0;
  CHLTVFrame::FreeBuffers(this: (CHLTVFrame *)&this->m_nViewEntity);
  this->m_pRecvTables[1023] = nullptr;
  this->m_nRecvTables = 0;
  this->m_vPVSOrigin.x = 0.0;
  CClientFrameManager::DeleteClientFrames(
    this: (CClientFrameManager *)&this->m_ReservationStatus.m_Remote.port,
    nTick: -1);
  CDeltaEntityCache::Flush(this: (CDeltaEntityCache *)&this->m_NetworkStringTables.m_Tables.m_Size);
  this->m_FrameCache.m_Memory.m_nAllocationCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101835E0
// Name: public: CHLTVServer::CHLTVServer(void)
// Source: json
//------------------------------------------------------------------------------
CHLTVServer *__thiscall CHLTVServer::CHLTVServer(CHLTVServer *this)
{
  bf_write *m_Messages; // edi
  democmdinfo_t *p_m_LastCmdInfo; // ecx
  int v4; // edx
  float *p_z; // eax
  int i; // [esp+Ch] [ebp-4h]

  this->IGameEventListener2::__vftable = (CHLTVServer_vtbl *)&IGameEventListener2::`vftable';
  CBaseServer::CBaseServer(this: &this->CBaseServer);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_ClientFramePool,
    blockSize: 284,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_Frames = nullptr;
  this->IHLTVServer::IBaseInterface::__vftable = (IHLTVServer_vtbl *)&IHLTVServer::`vftable';
  this->IDemoPlayer::__vftable = (IDemoPlayer_vtbl *)&IDemoPlayer::`vftable';
  this->IGameEventListener2::__vftable = (CHLTVServer_vtbl *)&CHLTVServer::`vftable'{for `IGameEventListener2'};
  this->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable = (CBaseServer_vtbl *)&CHLTVServer::`vftable'{for `CBaseServer'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CHLTVServer::`vftable'{for `CClientFrameManager'};
  this->IHLTVServer::IBaseInterface::__vftable = (IHLTVServer_vtbl *)&CHLTVServer::`vftable'{for `IHLTVServer'};
  this->IDemoPlayer::__vftable = (IDemoPlayer_vtbl *)&CHLTVServer::`vftable'{for `IDemoPlayer'};
  CHLTVClientState::CHLTVClientState(this: &this->m_ClientState);
  CHLTVDemoRecorder::CHLTVDemoRecorder(this: &this->m_DemoRecorder);
  CClientFrame::CClientFrame(this: &this->m_HLTVFrame);
  this->m_HLTVFrame.__vftable = (CHLTVFrame_vtbl *)&CHLTVFrame::`vftable';
  m_Messages = this->m_HLTVFrame.m_Messages;
  for ( i = 5; i >= 0; --i )
    bf_write::bf_write(this: m_Messages++);
  netadr_s::SetIP(this: &this->m_RootServer, unIP: 0);
  netadr_s::SetPort(this: &this->m_RootServer, newport: 0);
  netadr_s::SetType(this: &this->m_RootServer, newtype: NA_IP);
  CNetworkStringTableContainer::CNetworkStringTableContainer(this: &this->m_NetworkStringTables);
  _V_memset(dest: this->m_DeltaCache.m_Cache, fill: 0, count: 0x2000);
  this->m_DeltaCache.m_nTick = 0;
  this->m_DeltaCache.m_nMaxEntities = 0;
  this->m_DeltaCache.m_nCacheSize = 0;
  this->m_FrameCache.m_Memory.m_pMemory = nullptr;
  this->m_FrameCache.m_Memory.m_nAllocationCount = 0;
  this->m_FrameCache.m_Memory.m_nGrowSize = 0;
  this->m_FrameCache.m_Size = 0;
  this->m_FrameCache.m_pElements = nullptr;
  CDemoFile::CDemoFile(this: &this->m_DemoFile);
  p_m_LastCmdInfo = &this->m_LastCmdInfo;
  v4 = 1;
  p_z = &this->m_LastCmdInfo.u[0].viewOrigin.z;
  do
  {
    p_m_LastCmdInfo->u[0].flags = 0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_m_LastCmdInfo = (democmdinfo_t *)((char *)p_m_LastCmdInfo + 76);
    p_z += 19;
    --v4;
  }
  while ( v4 >= 0 );
  this->m_flTickInterval = 0.029999999;
  this->m_MasterClient = nullptr;
  this->m_Server = nullptr;
  this->m_Director = nullptr;
  this->m_nFirstTick = -1;
  this->m_nLastTick = 0;
  this->m_CurrentFrame = nullptr;
  this->m_nViewEntity = 0;
  this->m_nPlayerSlot = 0;
  this->m_bSignonState = false;
  this->m_flStartTime = 0.0;
  this->m_flFPS = 0.0;
  this->m_nGameServerMaxClients = 0;
  this->m_fNextSendUpdateTime = 0.0;
  _V_memset(dest: this->m_pRecvTables, fill: 0, count: 4096);
  this->m_nRecvTables = 0;
  this->m_vPVSOrigin.x = 0.0;
  this->m_vPVSOrigin.y = 0.0;
  this->m_vPVSOrigin.z = 0.0;
  this->m_nStartTick = 0;
  *(_WORD *)&this->m_bPlayingBack = 0;
  this->m_nSkipToTick = 0;
  this->m_bMasterOnlyMode = false;
  this->m_nGlobalSlots = 0;
  this->m_nGlobalClients = 0;
  this->m_nGlobalProxies = 0;
  this->m_flPlaybackRateModifier = 0.0;
  this->m_ClientState.m_pHLTV = this;
  this->m_nDebugID = 42;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101838D0
// Name: public: virtual CHLTVServer::~CHLTVServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::~CHLTVServer(CHLTVServer *this)
{
  bool v2; // zf
  bool v3; // sf

  v2 = this->m_nRecvTables == 0;
  v3 = this->m_nRecvTables < 0;
  this->IGameEventListener2::__vftable = (CHLTVServer_vtbl *)&CHLTVServer::`vftable'{for `IGameEventListener2'};
  this->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable = (CBaseServer_vtbl *)&CHLTVServer::`vftable'{for `CBaseServer'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CHLTVServer::`vftable'{for `CClientFrameManager'};
  this->IHLTVServer::IBaseInterface::__vftable = (IHLTVServer_vtbl *)&CHLTVServer::`vftable'{for `IHLTVServer'};
  this->IDemoPlayer::__vftable = (IDemoPlayer_vtbl *)&CHLTVServer::`vftable'{for `IDemoPlayer'};
  this->m_nDebugID = 13;
  if ( !v3 && !v2 )
  {
    RecvTable_Term(clearall: true);
    CHLTVServer::FreeClientRecvTables(this);
  }
  CDemoFile::~CDemoFile(this: &this->m_DemoFile);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_FrameCache);
  CDeltaEntityCache::Flush(this: &this->m_DeltaCache);
  CNetworkStringTableContainer::~CNetworkStringTableContainer(this: &this->m_NetworkStringTables);
  this->m_HLTVFrame.__vftable = (CHLTVFrame_vtbl *)&CHLTVFrame::`vftable';
  CHLTVFrame::FreeBuffers(this: &this->m_HLTVFrame);
  CClientFrame::~CClientFrame(this: &this->m_HLTVFrame);
  CHLTVDemoRecorder::~CHLTVDemoRecorder(this: &this->m_DemoRecorder);
  CHLTVClientState::~CHLTVClientState(this: &this->m_ClientState);
  this->IDemoPlayer::__vftable = (IDemoPlayer_vtbl *)&IDemoPlayer::`vftable';
  this->IHLTVServer::IBaseInterface::__vftable = (IHLTVServer_vtbl *)&IBaseInterface::`vftable';
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_ClientFramePool);
  CBaseServer::~CBaseServer(this: &this->CBaseServer);
  this->IGameEventListener2::__vftable = (CHLTVServer_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101839D0
// Name: public: class CClientFrame __near * CHLTVServer::AddNewFrame(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
CHLTVFrame *__thiscall CHLTVServer::AddNewFrame(CHLTVServer *this, CClientFrame *clientFrame)
{
  int tick_count; // eax
  CSteam3Server *v5; // eax
  CSteam3Server *v6; // eax
  CClientFrame *v7; // eax
  CClientFrame *v8; // ebx
  bf_write *v9; // ebx
  CHLTVFrame *v10; // ebx
  bf_write *m_Messages; // esi
  int j; // edi
  CFrameSnapshot *m_pSnapshot; // [esp-4h] [ebp-18h]
  CClientFrame *frame; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  CHLTVFrame *clientFramea; // [esp+1Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CHLTVServer::AddNewFrame",
    a3: 0,
    a4: "HLTV",
    a5: false,
    a6: 4);
  this->m_nLastTick = clientFrame->tick_count;
  m_pSnapshot = clientFrame->m_pSnapshot;
  clientFramea = &this->m_HLTVFrame;
  CClientFrame::SetSnapshot(this: &this->m_HLTVFrame, pSnapshot: m_pSnapshot);
  this->m_HLTVFrame.tick_count = clientFrame->tick_count;
  this->m_HLTVFrame.last_entity = clientFrame->last_entity;
  memcpy(
    dst: (unsigned __int8 *)&this->m_HLTVFrame.transmit_entity,
    src: (unsigned __int8 *)&clientFrame->transmit_entity,
    count: sizeof(this->m_HLTVFrame.transmit_entity));
  if ( this->m_nFirstTick < 0 )
  {
    tick_count = clientFrame->tick_count;
    this->m_nFirstTick = tick_count;
    this->m_nTickCount = tick_count;
    if ( this->IsMasterProxy(this: &this->IHLTVServer) )
    {
      ConMsg(a1: "SourceTV broadcast active.\n");
    }
    else
    {
      this->m_State = ss_active;
      CBaseServer::ReconnectClients(this: &this->CBaseServer);
      ConMsg(a1: "SourceTV relay active.\n");
      v5 = Steam3Server();
      CSteam3Server::Activate(this: v5);
      v6 = Steam3Server();
      CSteam3Server::SendUpdatedServerDetails(this: v6);
    }
  }
  v7 = (CClientFrame *)MemAlloc_Alloc(nSize: 0x1ACu);
  v8 = v7;
  frame = v7;
  if ( v7 != nullptr )
  {
    CClientFrame::CClientFrame(this: v7);
    v8->__vftable = (CClientFrame_vtbl *)&CHLTVFrame::`vftable';
    v9 = (bf_write *)&v8[1];
    for ( i = 5; i >= 0; --i )
      bf_write::bf_write(this: v9++);
    v10 = (CHLTVFrame *)frame;
  }
  else
  {
    v10 = nullptr;
  }
  CClientFrame::CopyFrame(this: v10, frame: clientFrame);
  CHLTVFrame::CopyHLTVData(this: v10, frame: clientFramea);
  CClientFrameManager::AddClientFrame(this: &this->CClientFrameManager, frame: v10);
  if ( this->IsMasterProxy(this: &this->IHLTVServer) && this->m_DemoRecorder.IsRecording(this: &this->m_DemoRecorder) )
    CHLTVDemoRecorder::WriteFrame(this: &this->m_DemoRecorder, pFrame: clientFramea);
  m_Messages = this->m_HLTVFrame.m_Messages;
  for ( j = 6; j != 0; --j )
    bf_write::Reset(this: m_Messages++);
  CClientFrame::SetSnapshot(this: clientFramea, pSnapshot: nullptr);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10183B90
// Name: public: void CHLTVServer::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVServer::RunFrame(CHLTVServer *this@<ecx>, int a2@<ebx>, CHLTVClientState *p_m_ClientState@<edi>)
{
  CStatTime *v4; // ecx
  long double v5; // st7
  IConnectionlessPacketHandler *v6; // eax
  CSteam3Server *v7; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CHLTVServer::RunFrame",
    a3: 0,
    a4: "HLTV",
    a5: false,
    a6: 4);
  v5 = _Plat_FloatTime(this: v4);
  NET_RunFrame(realtime: v5);
  if ( this->m_ClientState.m_nSignonState > 0 )
  {
    p_m_ClientState = &this->m_ClientState;
    if ( this == (CHLTVServer *)-536 )
      v6 = nullptr;
    else
      v6 = &this->m_ClientState.IConnectionlessPacketHandler;
    NET_ProcessSocket(sock: this->m_ClientState.m_Socket, handler: v6);
    p_m_ClientState->RunFrame(this: &this->m_ClientState);
    CHLTVClientState::SendPacket(this: &this->m_ClientState);
  }
  if ( !this->IsActive(this: &this->CBaseServer) )
    goto LABEL_7;
  if ( host_frametime > 0.0 )
    this->m_flFPS = (float)(this->m_flFPS * 0.99000001) + (float)(0.0099999998 / host_frametime);
  if ( this->IsPlayingBack(this: &this->IDemoPlayer) )
  {
LABEL_7:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CHLTVServer::UpdateTick(this);
    CBaseServer::RunFrame(this: &this->CBaseServer, a2);
    CHLTVServer::UpdateStats(this, a2: (int)p_m_ClientState, a3: (int)this);
    this->SendClientMessages(this: &this->CBaseServer, a2: true);
    if ( sv.m_State < ss_active )
    {
      v7 = Steam3Server();
      CSteam3Server::RunFrame(this: v7);
    }
    CBaseServer::UpdateMasterServer(this: &this->CBaseServer, a2);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183CD0
// Name: tv_relay
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_relay(const CCommand *args)
{
  int m_nArgv0Size; // eax
  const char *v2; // edi
  CHLTVServer *v3; // eax
  CHLTVServer *v4; // eax
  CBaseServer_vtbl *v5; // esi
  bool IsDedicated; // al

  if ( args->m_nArgc >= 2 )
  {
    m_nArgv0Size = args->m_nArgv0Size;
    v2 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( m_nArgv0Size == 0 )
      v2 = defaultValue;
    if ( V_strncmp(s1: v2, s2: "localhost", count: 9) != 0 )
    {
      if ( hltv == nullptr )
      {
        v3 = (CHLTVServer *)MemAlloc_Alloc(nSize: 0x89C0u);
        if ( v3 != nullptr )
          v4 = CHLTVServer::CHLTVServer(this: v3);
        else
          v4 = nullptr;
        hltv = v4;
        v5 = v4->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable;
        IsDedicated = NET_IsDedicated();
        v5->Init(this: &hltv->CBaseServer, a2: IsDedicated);
      }
      if ( hltv->m_bMasterOnlyMode )
      {
        ConMsg(a1: "SourceTV in Master-Only mode.\n");
      }
      else
      {
        Host_Disconnect(bShowMainMenu: false);
        NET_SetMultiplayer(multiplayer: true);
        CHLTVServer::ConnectRelay(this: hltv, address: v2);
      }
    }
    else
    {
      ConMsg(a1: "SourceTV can't connect to localhost.\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  tv_relay <ip:port>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183DE0
// Name: public: class CClientFrame __near * CHLTVServer::GetDeltaFrame(int)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CHLTVServer::GetDeltaFrame(CHLTVServer *this, int nTick)
{
  CClientFrame *result; // eax
  int m_Size; // ecx
  int v5; // eax
  CFrameCacheEntry_s *v6; // esi
  int *p_nTick; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  CFrameCacheEntry_s *m_pMemory; // ecx
  int v11; // eax
  CFrameCacheEntry_s *v12; // esi

  if ( tv_deltacache.m_pParent == nullptr || tv_deltacache.m_pParent->m_Value.m_nValue == 0 )
    return CClientFrameManager::GetClientFrame(this: &this->CClientFrameManager, nTick, bExact: true);
  m_Size = this->m_FrameCache.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
  {
LABEL_8:
    m_nAllocationCount = this->m_FrameCache.m_Memory.m_nAllocationCount;
    v9 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
        this: (CUtlMemory<ResourceEntryInfo,int> *)&this->m_FrameCache,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_FrameCache.m_Size;
    m_pMemory = this->m_FrameCache.m_Memory.m_pMemory;
    v11 = this->m_FrameCache.m_Size - v9 - 1;
    this->m_FrameCache.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 8 * v11);
    v12 = &this->m_FrameCache.m_Memory.m_pMemory[v9];
    v12->nTick = nTick;
    result = CClientFrameManager::GetClientFrame(this: &this->CClientFrameManager, nTick, bExact: true);
    v12->pFrame = result;
  }
  else
  {
    v6 = this->m_FrameCache.m_Memory.m_pMemory;
    p_nTick = &v6->nTick;
    while ( *p_nTick != nTick )
    {
      ++v5;
      p_nTick += 2;
      if ( v5 >= m_Size )
        goto LABEL_8;
    }
    return v6[v5].pFrame;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6CA0
// Name: public: virtual int CHLTVServer::GetChallengeType(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CHLTVServer::GetChallengeType(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 2;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101807B0
// Name: tv_name_changed_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_name_changed_f()
{
  CSteam3Server *v0; // eax

  v0 = Steam3Server();
  CSteam3Server::NotifyOfServerNameChange(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x101807C0
// Name: public: void CDeltaEntityCache::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaEntityCache::Flush(CDeltaEntityCache *this)
{
  int m_nMaxEntities; // eax
  int v3; // ebx
  void **m_Cache; // esi

  m_nMaxEntities = this->m_nMaxEntities;
  v3 = 0;
  if ( m_nMaxEntities != 0 )
  {
    if ( m_nMaxEntities > 0 )
    {
      m_Cache = (void **)this->m_Cache;
      do
      {
        if ( *m_Cache != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *m_Cache);
          *m_Cache = nullptr;
        }
        ++v3;
        ++m_Cache;
      }
      while ( v3 < this->m_nMaxEntities );
    }
    this->m_nMaxEntities = 0;
    this->m_nCacheSize = 0;
  }
  else
  {
    this->m_nCacheSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180810
// Name: public: void CDeltaEntityCache::SetTick(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaEntityCache::SetTick(CDeltaEntityCache *this, int nTick, int nMaxEntities)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax

  if ( nTick != this->m_nTick )
  {
    CDeltaEntityCache::Flush(this);
    v4 = tv_deltacache.m_pParent != nullptr ? tv_deltacache.m_pParent->m_Value.m_nValue : 0;
    v5 = v4 << 10;
    this->m_nCacheSize = v5;
    if ( v5 > 0 )
    {
      v6 = nMaxEntities;
      if ( nMaxEntities >= 2048 )
        v6 = 2048;
      this->m_nMaxEntities = v6;
      this->m_nTick = nTick;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180860
// Name: public: unsigned char __near * CDeltaEntityCache::FindDeltaBits(int,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
CDeltaEntityCache::DeltaEntityEntry_s *__thiscall CDeltaEntityCache::FindDeltaBits(
        CDeltaEntityCache *this,
        int nEntityIndex,
        int nDeltaTick,
        int *nBits)
{
  CDeltaEntityCache::DeltaEntityEntry_s *v4; // eax

  *nBits = -1;
  if ( nEntityIndex < 0 )
    return nullptr;
  if ( nEntityIndex >= this->m_nMaxEntities )
    return nullptr;
  v4 = this->m_Cache[nEntityIndex];
  if ( v4 == nullptr )
    return nullptr;
  while ( v4->nDeltaTick != nDeltaTick )
  {
    v4 = v4->pNext;
    if ( v4 == nullptr )
      return nullptr;
  }
  *nBits = v4->nBits;
  return v4 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101808A0
// Name: public: void CDeltaEntityCache::AddDeltaBits(int,int,int,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeltaEntityCache::AddDeltaBits(
        CDeltaEntityCache *this,
        int nEntityIndex,
        int nDeltaTick,
        int nBits,
        bf_write *pBuffer)
{
  signed int m_nCacheSize; // ebx
  CDeltaEntityCache::DeltaEntityEntry_s *v7; // ecx
  int v8; // esi
  CDeltaEntityCache::DeltaEntityEntry_s *v9; // eax
  CDeltaEntityCache::DeltaEntityEntry_s *v10; // edi
  CDeltaEntityCache::DeltaEntityEntry_s *pNext; // eax
  unsigned int i; // ebx
  unsigned __int8 *m_pData; // [esp-18h] [ebp-58h]
  int m_nDataBytes; // [esp-14h] [ebp-54h]
  int m_iCurBit; // [esp-10h] [ebp-50h]
  bf_read inBuffer; // [esp+4h] [ebp-3Ch] BYREF
  bf_write outBuffer; // [esp+28h] [ebp-18h] BYREF

  if ( nEntityIndex >= 0 && nEntityIndex < this->m_nMaxEntities )
  {
    m_nCacheSize = this->m_nCacheSize;
    if ( m_nCacheSize > 0 )
    {
      v7 = this->m_Cache[nEntityIndex];
      v8 = 4 * ((((nBits + 7) >> 3) + 3) / 4);
      if ( v7 == nullptr )
      {
        if ( v8 + 12 > m_nCacheSize )
          return;
        v9 = (CDeltaEntityCache::DeltaEntityEntry_s *)MemAlloc_Alloc(nSize: m_nCacheSize);
        this->m_Cache[nEntityIndex] = v9;
        v10 = v9;
        goto LABEL_11;
      }
      pNext = v7->pNext;
      for ( i = (unsigned int)v7 + m_nCacheSize; pNext != nullptr; pNext = pNext->pNext )
        v7 = pNext;
      v10 = (CDeltaEntityCache::DeltaEntityEntry_s *)((char *)v7 + 4 * ((((v7->nBits + 7) >> 3) + 3) / 4) + 12);
      if ( (unsigned int)&v10[1] + v8 <= i )
      {
        v10->pNext = v10;
LABEL_11:
        v10->pNext = nullptr;
        v10->nDeltaTick = nDeltaTick;
        v10->nBits = nBits;
        if ( nBits > 0 )
        {
          inBuffer.m_bOverflow = false;
          inBuffer.m_pDebugName = nullptr;
          inBuffer.m_nDataBytes = 0;
          m_iCurBit = pBuffer->m_iCurBit;
          m_nDataBytes = pBuffer->m_nDataBytes;
          m_pData = pBuffer->m_pData;
          inBuffer.m_nDataBits = -1;
          CBitRead::StartReading(this: &inBuffer, pData: m_pData, nBytes: m_nDataBytes, iStartBit: m_iCurBit, nBits: -1);
          bf_write::bf_write(this: &outBuffer, pData: &v10[1], nBytes: v8, nBits: -1);
          bf_write::WriteBitsFromBuffer(this: &outBuffer, pIn: &inBuffer, nBits);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101809A0
// Name: AddRecvTableR
// Source: json
//------------------------------------------------------------------------------
RecvTable *__cdecl AddRecvTableR(SendTable *sendt, RecvTable **pRecvTables, int *nRecvTables)
{
  char *m_pNetTableName; // ebx
  int v4; // edi
  int v5; // esi
  int m_nProps; // edi
  RecvProp *v7; // eax
  RecvProp *v8; // ebx
  int v9; // edi
  RecvProp *j; // esi
  RecvTable *v11; // esi
  RecvTable *result; // eax
  int v13; // ebx
  RecvProp *v14; // esi
  SendProp *v15; // eax
  int m_ElementStride; // ecx
  int m_nElements; // edx
  RecvTable *v18; // eax
  RecvTable *v19; // eax
  int i; // [esp+Ch] [ebp-8h]
  RecvProp *receiveProps; // [esp+10h] [ebp-4h]

  m_pNetTableName = sendt->m_pNetTableName;
  v4 = *nRecvTables;
  v5 = 0;
  if ( *nRecvTables > 0 )
  {
    while ( _V_strcmp(s1: m_pNetTableName, s2: pRecvTables[v5]->m_pNetTableName) != 0 )
    {
      if ( ++v5 >= v4 )
        goto LABEL_4;
    }
    v11 = pRecvTables[v5];
    if ( v11 != nullptr )
      return v11;
  }
LABEL_4:
  m_nProps = sendt->m_nProps;
  if ( m_nProps <= 0 )
  {
    v19 = (RecvTable *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v19 != nullptr )
    {
      result = RecvTable::RecvTable(this: v19, pProps: nullptr, nProps: 0, pNetTableName: sendt->m_pNetTableName);
      pRecvTables[(*nRecvTables)++] = result;
      return result;
    }
  }
  else
  {
    v7 = (RecvProp *)MemAlloc_Alloc(nSize: (60 * (unsigned __int64)(unsigned int)m_nProps) >> 32 != 0 ? -1 : 60 * m_nProps);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v9 = m_nProps - 1;
      for ( j = v7; v9 >= 0; --v9 )
        RecvProp::RecvProp(this: j++);
      receiveProps = v8;
    }
    else
    {
      receiveProps = nullptr;
    }
    v13 = 0;
    i = 0;
    if ( sendt->m_nProps > 0 )
    {
      v14 = receiveProps - 1;
      do
      {
        v15 = &sendt->m_pProps[v13];
        v14[1].m_pVarName = v15->m_pVarName;
        v14[1].m_RecvType = v15->m_Type;
        if ( (v15->m_Flags & 0x40) != 0 )
          v14[1].m_pVarName = "IsExcludedProp";
        if ( (v15->m_Flags & 0x100) != 0 )
        {
          v14[1].m_bInsideArray = true;
          v14[1].m_pVarName = "InsideArrayProp";
        }
        if ( v15->m_Type == DPT_Array )
        {
          v14[1].m_pArrayProp = v14;
          m_ElementStride = v15->m_ElementStride;
          m_nElements = v15->m_nElements;
          v14[1].m_RecvType = DPT_Array;
          v14[1].m_nElements = m_nElements;
          v14[1].m_ElementStride = m_ElementStride;
        }
        if ( v15->m_Type == DPT_DataTable )
          v14[1].m_pDataTable = AddRecvTableR(sendt: v15->m_pDataTable, pRecvTables, nRecvTables);
        ++v13;
        ++v14;
        ++i;
      }
      while ( i < sendt->m_nProps );
    }
    v18 = (RecvTable *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v18 != nullptr )
    {
      result = RecvTable::RecvTable(
                 this: v18,
                 pProps: receiveProps,
                 nProps: sendt->m_nProps,
                 pNetTableName: sendt->m_pNetTableName);
      pRecvTables[(*nRecvTables)++] = result;
      return result;
    }
  }
  pRecvTables[(*nRecvTables)++] = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10180B60
// Name: private: void CHLTVServer::InitClientRecvTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::InitClientRecvTables(CHLTVServer *this)
{
  CHLTVServer *v1; // edi
  ServerClass *i; // esi
  ServerClass *v3; // ebx
  bool j; // zf
  int m_nRecvTables; // edi
  int v6; // esi
  RecvTable *v7; // esi
  ClientClass *v8; // eax
  char *s1; // [esp+4h] [ebp-8h]

  v1 = this;
  if ( ClientDLL_GetAllClasses() == nullptr )
  {
    for ( i = serverGameDLL->GetAllServerClasses(this: serverGameDLL); i != nullptr; i = i->m_pNext )
    {
      AddRecvTableR(sendt: i->m_pTable, pRecvTables: v1->m_pRecvTables, nRecvTables: &v1->m_nRecvTables);
      if ( v1->m_nRecvTables >= 0x400u )
        _Error(a1: "AddRecvTableR: overflowed MAX_DATATABLES");
    }
    v3 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
    for ( j = v3 == nullptr; !j; j = v3 == nullptr )
    {
      if ( v1->m_nRecvTables >= 0x400u )
        _Error(a1: "ClientDLL_InitRecvTableMgr: overflowed MAX_DATATABLES");
      m_nRecvTables = v1->m_nRecvTables;
      v6 = 0;
      s1 = v3->m_pTable->m_pNetTableName;
      if ( m_nRecvTables <= 0 )
      {
LABEL_13:
        v7 = nullptr;
      }
      else
      {
        while ( _V_strcmp(s1, s2: this->m_pRecvTables[v6]->m_pNetTableName) != 0 )
        {
          if ( ++v6 >= m_nRecvTables )
            goto LABEL_13;
        }
        v7 = this->m_pRecvTables[v6];
      }
      v8 = (ClientClass *)MemAlloc_Alloc(nSize: 0x1Cu);
      if ( v8 == nullptr )
      {
        _Msg(a1: "HLTV_InitRecvTableMgr: failed to allocate client class %s.\n", v3->m_pNetworkName);
        return;
      }
      v1 = this;
      v8->m_pNetworkName = v3->m_pNetworkName;
      v8->m_pCreateFn = nullptr;
      v8->m_pCreateEventFn = nullptr;
      v8->m_pRecvTable = v7;
      v8->m_pMapClassname = nullptr;
      v8->m_pNext = g_pClientClassHead;
      g_pClientClassHead = v8;
      v3 = v3->m_pNext;
    }
    RecvTable_Init(pTables: v1->m_pRecvTables, nTables: v1->m_nRecvTables);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180D00
// Name: public: void CHLTVFrame::FreeBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVFrame::FreeBuffers(CHLTVFrame *this)
{
  bf_write *m_Messages; // esi
  int i; // edi

  m_Messages = this->m_Messages;
  for ( i = 6; i != 0; --i )
  {
    if ( m_Messages->m_pData != nullptr )
    {
      free(pMem: m_Messages->m_pData);
      bf_write::StartWriting(this: m_Messages, pData: nullptr, nBytes: 0, iStartBit: 0, nBits: -1);
    }
    ++m_Messages;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180D40
// Name: public: void CHLTVServer::StartRelay(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVServer::StartRelay(CHLTVServer *this@<ecx>, int a2@<edi>)
{
  int m_nValue; // eax
  long double v4; // st7

  if ( this->m_ClientState.m_nSignonState >= 2 || this->IsPlayingBack(this: &this->IDemoPlayer) )
  {
    ((void (__thiscall *)(CBaseServer *, int))this->Clear)(a1: &this->CBaseServer, a2);
    if ( this->m_nRecvTables == 0 )
      CHLTVServer::InitClientRecvTables(this);
    CHLTVFrame::AllocBuffers(this: &this->m_HLTVFrame);
    this->m_StringTables = &this->m_NetworkStringTables;
    if ( tv_maxclients.m_pParent != nullptr )
      m_nValue = tv_maxclients.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    this->SetMaxClients(this: &this->CBaseServer, a2: m_nValue);
    this->m_bSignonState = true;
    v4 = net_time;
    ++this->m_nSpawnCount;
    this->m_flStartTime = v4;
    this->m_State = ss_loading;
  }
  else
  {
    DevMsg(a1: "StartRelay: not connected.\n");
    this->Shutdown(this: &this->CBaseServer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180E00
// Name: public: virtual int CHLTVServer::GetHLTVSlot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVServer::GetHLTVSlot(CHLTVServer *this)
{
  return *(_DWORD *)&this->m_DemoRecorder.m_DemoFile.m_DemoHeader.mapname[92];
}

//------------------------------------------------------------------------------
// Address: 0x10180E10
// Name: public: virtual float CHLTVServer::GetOnlineTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CHLTVServer::GetOnlineTime(CHLTVServer *this)
{
  long double result; // st7

  result = net_time - *(float *)&this->m_DemoRecorder.m_DemoFile.m_DemoHeader.playback_frames;
  if ( result < 0.0 )
    return 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10180E30
// Name: public: virtual void CHLTVServer::GetLocalStats(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::GetLocalStats(CHLTVServer *this, int *proxies, int *slots, int *clients)
{
  char *v4; // esi

  v4 = (char *)this - 512;
  *proxies = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 128) + 12))(a1: (char *)this - 512);
  *clients = (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 8))(a1: v4);
  *slots = (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 20))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10180EB0
// Name: public: bool CHLTVServer::IsTVRelay(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVServer::IsTVRelay(CHLTVServer *this)
{
  return !this->IsMasterProxy(this: &this->IHLTVServer);
}

//------------------------------------------------------------------------------
// Address: 0x10180EF0
// Name: private: virtual class CBaseClient __near * CHLTVServer::CreateNewClient(int)
// Source: json
//------------------------------------------------------------------------------
CHLTVClient *__thiscall CHLTVServer::CreateNewClient(CHLTVServer *this, int slot)
{
  CHLTVClient *v3; // eax

  v3 = (CHLTVClient *)MemAlloc_Alloc(nSize: 0x1D7A0u);
  if ( v3 != nullptr )
    return CHLTVClient::CHLTVClient(this: v3, slot, pServer: this != (CHLTVServer *)8 ? (CBaseServer *)this : nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10180F30
// Name: private: void CHLTVServer::InstallStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::InstallStringTables(CHLTVServer *this)
{
  int v2; // eax
  CNetworkStringTable *v3; // eax
  vgui::Panel *v4; // esi
  CNetworkStringTableContainer_vtbl *v5; // ebx
  int UserDataSize; // eax
  int v7; // eax
  int v8; // eax
  CNetworkStringTable *v9; // eax
  int v10; // ebx
  const char *v11; // eax
  vgui::DragDrop_t *UserDataSizeBits; // [esp-Ch] [ebp-1Ch]
  BOOL v13; // [esp-8h] [ebp-18h]
  int numTables; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  numTables = this->m_Server->m_StringTables->GetNumTables(this: this->m_Server->m_StringTables);
  this->m_StringTables = &this->m_NetworkStringTables;
  CNetMessage::SetReliable(this: (CNetMessage *)&this->m_NetworkStringTables, state: true);
  CNetworkStringTableContainer::EnableRollback(this: this->m_StringTables, bState: true);
  v2 = 0;
  for ( i = 0; v2 < numTables; i = v2 )
  {
    v3 = (CNetworkStringTable *)this->m_Server->m_StringTables->GetTable(this: this->m_Server->m_StringTables, a2: v2);
    v4 = (vgui::Panel *)v3;
    if ( v3 != nullptr )
    {
      v5 = this->m_StringTables->CBaseServer::__vftable;
      v13 = (unsigned __int8)CNetworkStringTable::IsUsingDictionary(this: v3) != 0;
      UserDataSizeBits = CNetworkStringTable::GetUserDataSizeBits(this: v4);
      UserDataSize = CNetworkStringTable::GetUserDataSize(this: (CVTFTexture *)v4);
      v7 = ((int (__thiscall *)(vgui::Panel *, int, vgui::DragDrop_t *, BOOL))v4->Repaint)(
             a1: v4,
             a2: UserDataSize,
             a3: UserDataSizeBits,
             a4: v13);
      v8 = ((int (__thiscall *)(vgui::Panel *, int))v4->Think)(a1: v4, a2: v7);
      v9 = (CNetworkStringTable *)((int (__thiscall *)(CNetworkStringTableContainer *, int))v5->CreateStringTable)(
                                    a1: this->m_StringTables,
                                    a2: v8);
      v10 = (int)v9;
      if ( v9 != nullptr )
      {
        CNetworkStringTable::CopyStringTable(this: v9, table: (CNetworkStringTable *)v4);
        CNetworkStringTable::SetMirrorTable(this: (CAudioMixerWave *)v4, delaySamples: v10);
      }
      else
      {
        v11 = (const char *)((int (__thiscall *)(vgui::Panel *))v4->Think)(a1: v4);
        DevMsg(a1: "SV_InstallHLTVStringTableMirrors! Missing client table \"%s\".\n ", v11);
      }
    }
    v2 = i + 1;
  }
  CNetMessage::SetReliable(this: (CNetMessage *)this->m_StringTables, state: false);
}

//------------------------------------------------------------------------------
// Address: 0x10181130
// Name: public: bool CHLTVServer::SendNetMsg(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CHLTVServer::SendNetMsg@<al>(
        CHLTVServer *this@<ecx>,
        int a2@<edi>,
        INetMessage *msg,
        bool bForceReliable,
        bool bVoice)
{
  int v7; // edi

  if ( this->m_bSignonState )
    return msg->WriteToBuffer(this: msg, a2: &this->m_Signon);
  v7 = 2;
  if ( ((unsigned __int8 (__thiscall *)(INetMessage *, int))msg->IsReliable)(a1: msg, a2) != 0 )
  {
    v7 = 1;
  }
  else if ( msg->GetType(this: msg) == 17 )
  {
    v7 = 4;
  }
  else if ( msg->GetType(this: msg) == 15 )
  {
    v7 = 3;
  }
  else if ( msg->GetType(this: msg) == 27 )
  {
    v7 = 5;
  }
  return msg->WriteToBuffer(this: msg, a2: &this->m_HLTVFrame.m_Messages[v7]);
}

//------------------------------------------------------------------------------
// Address: 0x101811D0
// Name: public: class bf_write __near * CHLTVServer::GetBuffer(int)
// Source: json
//------------------------------------------------------------------------------
bf_write *__thiscall CHLTVServer::GetBuffer(CHLTVServer *this, unsigned int nBuffer)
{
  if ( nBuffer > 5 )
    return nullptr;
  else
    return &this->m_HLTVFrame.m_Messages[nBuffer];
}

//------------------------------------------------------------------------------
// Address: 0x101811F0
// Name: public: virtual class IServer __near * CHLTVServer::GetBaseServer(void)
// Source: json
//------------------------------------------------------------------------------
IServer *__thiscall CHLTVServer::GetBaseServer(CHLTVServer *this)
{
  if ( this == (CHLTVServer *)520 )
    return nullptr;
  else
    return (IServer *)((char *)this - 512);
}

//------------------------------------------------------------------------------
// Address: 0x10181210
// Name: public: virtual class IHLTVDirector __near * CHLTVServer::GetDirector(void)
// Source: json
//------------------------------------------------------------------------------
IHLTVDirector *__thiscall CHLTVServer::GetDirector(CHLTVServer *this)
{
  return *(IHLTVDirector **)&this->m_DemoRecorder.m_DemoFile.m_DemoHeader.mapname[72];
}

//------------------------------------------------------------------------------
// Address: 0x10181220
// Name: public: virtual char const __near * CHLTVServer::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHLTVServer::GetName(CHLTVClientState *this)
{
  char *result; // eax

  if ( (tv_name.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = tv_name.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10181250
// Name: public: virtual void CHLTVServer::FillServerInfo(class SVC_ServerInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::FillServerInfo(CHLTVServer *this, SVC_ServerInfo *serverinfo)
{
  CBaseServer::FillServerInfo((CBaseServer *)this, serverinfo);
  serverinfo->m_nPlayerSlot = (int)this->m_CurrentFrame;
  serverinfo->m_nMaxClients = LODWORD(this->m_flStartTime);
}

//------------------------------------------------------------------------------
// Address: 0x10181280
// Name: public: virtual void CHLTVServer::Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::Init(CHLTVServer *this, bool bIsDedicated)
{
  int v3; // eax
  int v4; // [esp+0h] [ebp-4h]

  CBaseServer::Init((CBaseServer *)this, bIsDedicated);
  this->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable = (CBaseServer_vtbl *)2;
  v3 = _CommandLine(a1: v4);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-tvmasteronly") != 0 )
    LOBYTE(this->m_vPVSOrigin.y) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101812C0
// Name: public: void CHLTVServer::Changelevel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::Changelevel(CHLTVServer *this)
{
  this->m_DemoRecorder.StopRecording(this: &this->m_DemoRecorder);
  CBaseServer::InactivateClients(this: &this->CBaseServer);
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  this->m_CurrentFrame = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10181300
// Name: public: virtual void CHLTVServer::GetNetStats(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::GetNetStats(CHLTVServer *this, float *avgIn, float *avgOut)
{
  CBaseServer::GetNetStats((CBaseServer *)this, avgIn, avgOut);
  if ( LODWORD(this->m_ClientState.m_ListenServerSteamID) == 6 )
  {
    *avgIn = ((double (__thiscall *)(IServerMessageHandler_vtbl *, int))*((_DWORD *)this->m_ClientState.dtr_INetMessageHandler
                                                                        + 13))(
               a1: this->m_ClientState.__vftable,
               a2: 1)
           + *avgIn;
    *avgOut = ((double (__thiscall *)(IServerMessageHandler_vtbl *, _DWORD))*((_DWORD *)this->m_ClientState.dtr_INetMessageHandler
                                                                            + 13))(
                a1: this->m_ClientState.__vftable,
                a2: 0)
            + *avgOut;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181350
// Name: public: virtual void CHLTVServer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::Shutdown(CHLTVServer *this)
{
  (*(void (__thiscall **)(CHLTVServer **))&this->m_ClientState.m_pHLTV->m_szMapname[4])(a1: &this->m_ClientState.m_pHLTV);
  if ( (*(unsigned __int8 (__thiscall **)(int *))(this->m_ClientFramePool.m_BlobHead.m_NumBytes + 32))(a1: &this->m_ClientFramePool.m_BlobHead.m_NumBytes) != 0 )
  {
    if ( this->IDemoPlayer::__vftable != nullptr )
      (*((void (__cdecl **)(CDemoFile *(__thiscall **)(IDemoPlayer *), const char *))this->GetDemoFile + 13))(
        a1: &this->GetDemoFile,
        a2: "SourceTV stop.");
    if ( this->m_DemoRecorder.m_MessageData.m_pDebugName != nullptr )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)this->m_DemoRecorder.m_MessageData.m_pDebugName + 8))(a1: 0);
  }
  else
  {
    CAddressList::RemoveAll(this: (CAddressList *)&this->m_ClientState.m_nRetryNumber);
    (*(void (__stdcall **)(int))(this->m_nDebugID + 64))(a1: 1);
  }
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: (CHLTVServer *)((char *)this - 8));
  CBaseServer::Shutdown((CBaseServer *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101813F0
// Name: public: virtual class CDemoFile __near * CHLTVServer::GetDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
CDeltaEntityCache::DeltaEntityEntry_s **__thiscall CHLTVServer::GetDemoFile(CHLTVServer *this)
{
  return &this->m_DeltaCache.m_Cache[1922];
}

//------------------------------------------------------------------------------
// Address: 0x10181400
// Name: public: virtual bool CHLTVServer::IsPlayingBack(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVServer::IsPlayingBack(CHLTVServer *this)
{
  return this->m_DemoFile.m_DemoHeader.mapname[172];
}

//------------------------------------------------------------------------------
// Address: 0x10181410
// Name: public: virtual bool CHLTVServer::IsPlaybackPaused(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVServer::IsPlaybackPaused(CHLTVServer *this)
{
  return this->m_DemoFile.m_DemoHeader.mapname[173];
}

//------------------------------------------------------------------------------
// Address: 0x10181420
// Name: public: virtual float CHLTVServer::GetPlaybackTimeScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CHLTVServer::GetPlaybackTimeScale(CHLTVServer *this)
{
  return *(float *)&this->m_DemoFile.m_DemoHeader.mapname[176];
}

//------------------------------------------------------------------------------
// Address: 0x10181430
// Name: public: virtual void CHLTVServer::SetPlaybackTimeScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::SetPlaybackTimeScale(CHLTVServer *this, float timescale)
{
  *(float *)&this->m_DemoFile.m_DemoHeader.mapname[176] = timescale;
}

//------------------------------------------------------------------------------
// Address: 0x10181450
// Name: public: virtual int CHLTVServer::GetPlaybackStartTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVServer::GetPlaybackStartTick(CHLTVServer *this)
{
  return *(_DWORD *)&this->m_DemoFile.m_DemoHeader.mapname[16];
}

//------------------------------------------------------------------------------
// Address: 0x10181470
// Name: public: virtual int CHLTVServer::GetTotalTicks(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVServer::GetTotalTicks(CHLTVServer *this)
{
  return *(_DWORD *)this->m_DemoFile.m_DemoHeader.mapname;
}

//------------------------------------------------------------------------------
// Address: 0x10181480
// Name: public: virtual int CHLTVServer::GetChallengeType(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CHLTVServer::GetChallengeType(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10181490
// Name: public: virtual char const __near * CHLTVServer::GetPassword(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHLTVServer::GetPassword(CHLTVServer *this)
{
  char *v1; // esi
  char *m_pszString; // eax

  if ( (tv_password.m_nFlags & 0x1000) != 0 )
  {
    v1 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = tv_password.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      return nullptr;
    v1 = tv_password.m_pParent->m_Value.m_pszString;
    if ( *m_pszString == 0 )
      return nullptr;
  }
  if ( _V_stricmp(s1: v1, s2: "none") != 0 )
    return v1;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101814E0
// Name: tv_status
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall tv_status(int a1@<edi>, int a2@<esi>)
{
  CHLTVServer *v2; // esi
  int v3; // eax
  double v4; // st7
  char *v5; // eax
  bool v6; // al
  IHLTVServer_vtbl *v7; // edx
  IHLTVServer *v8; // ecx
  int v9; // eax
  CHLTVServer *v10; // esi
  unsigned __int64 v11; // st7
  const char *v12; // eax
  CBaseServer *v13; // esi
  netadr_s *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  CBaseServer *v17; // esi
  int v18; // eax
  int v19; // eax
  double v20; // st7
  char *v21; // eax
  const char *v22; // eax
  CHLTVDemoRecorder *p_m_DemoRecorder; // esi
  int v24; // eax
  char *v25; // eax
  const char *v26; // eax
  double v27; // [esp+10h] [ebp-12Ch]
  double v28[5]; // [esp+18h] [ebp-124h] BYREF
  _BYTE gd_232[20]; // [esp+128h] [ebp-14h] OVERLAPPED BYREF

  V_FileBase(in: com_gamedir, out: (char *)&v28[1], maxlen: 260);
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    ((void (__thiscall *)(CBaseServer *, _BYTE *, _BYTE *, int, int))hltv->GetNetStats)(
      a1: &hltv->CBaseServer,
      a2: gd_232,
      a3: &gd_232[12],
      a4: a1,
      a5: a2);
    *(float *)gd_232 = *(float *)gd_232 * 0.0009765625;
    *(float *)&gd_232[12] = *(float *)&gd_232[12] * 0.0009765625;
    ConMsg(a1: "--- SourceTV Status ---\n");
    v2 = hltv;
    v3 = build_number();
    v4 = ((double (__thiscall *)(IHLTVServer *, _DWORD, _DWORD, int, const char *))v2->GetOnlineTime)(
           a1: &v2->IHLTVServer,
           a2: COERCE_UNSIGNED_INT64(hltv->m_flFPS),
           a3: HIDWORD(COERCE_UNSIGNED_INT64(hltv->m_flFPS)),
           a4: v3,
           a5: "Win32");
    v5 = COM_FormatSeconds(seconds: (int)v4);
    ConMsg(a1: "Online %s, FPS %.1f, Version %i (%s)\n", v5, v27, LODWORD(v28[0]), (const char *)HIDWORD(v28[0]));
    if ( hltv->IsDemoPlayback(this: &hltv->IHLTVServer) )
    {
      ConMsg(a1: "Playing Demo File \"%s\"\n", "TODO demo file name");
    }
    else
    {
      v6 = hltv->IsMasterProxy(this: &hltv->IHLTVServer);
      v7 = hltv->IHLTVServer::IBaseInterface::__vftable;
      v8 = &hltv->IHLTVServer;
      if ( v6 )
      {
        v9 = (int)v7->GetDirector(this: v8);
        v10 = hltv;
        *(double *)&v11 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v9 + 28))(a1: v9);
        v12 = (const char *)((int (__thiscall *)(CBaseServer *, _DWORD, _DWORD))v10->GetName)(
                              a1: &v10->CBaseServer,
                              a2: v11,
                              a3: HIDWORD(v11));
        ConMsg(a1: "Master \"%s\", delay %.0f\n", v12, v28[0]);
      }
      else if ( v7->GetRelayAddress(this: v8) != nullptr )
      {
        v13 = &hltv->CBaseServer;
        v14 = (netadr_s *)hltv->GetRelayAddress(this: &hltv->IHLTVServer);
        v15 = netadr_s::ToString(this: v14, baseOnly: false);
        v16 = (const char *)((int (__thiscall *)(CBaseServer *, const char *))v13->GetName)(a1: v13, a2: v15);
        ConMsg(a1: "Relay \"%s\", connect to %s\n", v16, (const char *)HIDWORD(v28[0]));
      }
      else
      {
        HIDWORD(v28[0]) = hltv->GetName(this: &hltv->CBaseServer);
        ConMsg(a1: "Relay \"%s\", not connect.\n", HIDWORD(v28[0]));
      }
    }
    v17 = &hltv->CBaseServer;
    v18 = hltv->GetNumPlayers(this: &hltv->CBaseServer);
    v19 = ((int (__thiscall *)(CBaseServer *, int))v17->GetMapName)(a1: v17, a2: v18);
    v20 = ((double (__thiscall *)(CBaseServer *, double *, int))v17->GetTime)(a1: v17, a2: &v28[1], a3: v19);
    v21 = COM_FormatSeconds(seconds: (int)v20);
    ConMsg(
      a1: "Game Time %s, Mod \"%s\", Map \"%s\", Players %i\n",
      v21,
      (const char *)HIDWORD(v28[0]),
      (const char *)LODWORD(v28[1]),
      HIDWORD(v28[1]));
    v28[1] = *(float *)&gd_232[12];
    v28[0] = *(float *)gd_232;
    LODWORD(v28[0]) = ((int (__thiscall *)(CBaseServer *, _DWORD))hltv->GetUDPPort)(
                        a1: &hltv->CBaseServer,
                        a2: COERCE_UNSIGNED_INT64(*(float *)gd_232));
    v22 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
    ConMsg(
      a1: "Local IP %s:%i, KB/sec In %.1f, Out %.1f\n",
      v22,
      LODWORD(v28[0]),
      *(double *)((char *)v28 + 4),
      *(double *)((char *)&v28[1] + 4));
    hltv->GetLocalStats(this: &hltv->IHLTVServer, a2: (int *)&gd_232[4], a3: (int *)&gd_232[8], a4: (int *)&gd_232[16]);
    ConMsg(
      a1: "Local Slots %i, Spectators %i, Proxies %i\n",
      *(_DWORD *)&gd_232[8],
      *(_DWORD *)&gd_232[16] - *(_DWORD *)&gd_232[4],
      *(_DWORD *)&gd_232[4]);
    hltv->GetGlobalStats(this: &hltv->IHLTVServer, a2: (int *)&gd_232[4], a3: (int *)&gd_232[8], a4: (int *)&gd_232[16]);
    ConMsg(
      a1: "Total Slots %i, Spectators %i, Proxies %i\n",
      *(_DWORD *)&gd_232[8],
      *(_DWORD *)&gd_232[16] - *(_DWORD *)&gd_232[4],
      *(_DWORD *)&gd_232[4]);
    if ( hltv->m_DemoRecorder.IsRecording(this: &hltv->m_DemoRecorder) )
    {
      p_m_DemoRecorder = &hltv->m_DemoRecorder;
      v24 = hltv->m_DemoRecorder.GetRecordingTick(this: &hltv->m_DemoRecorder);
      v25 = COM_FormatSeconds(seconds: (int)(float)((float)v24 * host_state.interval_per_tick));
      v26 = (const char *)((int (__thiscall *)(CHLTVDemoRecorder *, char *))p_m_DemoRecorder->GetDemoFile)(
                            a1: p_m_DemoRecorder,
                            a2: v25);
      ConMsg(a1: "Recording to \"%s\", length %s.\n", v26, (const char *)HIDWORD(v28[0]));
    }
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181820
// Name: tv_stop
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_stop()
{
  int v0; // esi

  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v0 = hltv->GetNumClients(this: &hltv->CBaseServer);
    hltv->Shutdown(this: &hltv->CBaseServer);
    ConMsg(a1: "SourceTV stopped, %i clients disconnected.\n", v0);
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181880
// Name: tv_retry
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_retry()
{
  Remote_t *v0; // eax
  const char *v1; // eax
  Remote_t *v2; // eax
  const char *v3; // eax
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v6; // [esp-8h] [ebp-8h]

  if ( hltv != nullptr )
  {
    if ( hltv->m_bMasterOnlyMode )
    {
      ConMsg(a1: "SourceTV in Master-Only mode.\n");
    }
    else if ( vgui::Image::GetWide(this: (CVTFTexture *)&hltv->m_ClientState.m_Remote) != 0 )
    {
      v0 = CAddressList::Get(this: &hltv->m_ClientState.m_Remote, index: 0);
      v1 = CUtlString::operator char const *(this: &v0->m_szRetryAddress);
      ConMsg(a1: "Commencing SourceTV connection retry to %s\n", v1);
      v2 = CAddressList::Get(this: &hltv->m_ClientState.m_Remote, index: 0);
      v3 = CUtlString::operator char const *(this: &v2->m_szRetryAddress);
      v6 = va(format: "tv_relay %s\n", v3);
      TraceType = CTraceFilter::GetTraceType(this: v4);
      Cbuf_AddText(eTarget: TraceType, pText: v6, nTickDelay: 0);
    }
    else
    {
      ConMsg(a1: "Can't retry, no previous SourceTV connection\n");
    }
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181940
// Name: tv_record
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_record(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  char name[260]; // [esp+4h] [ebp-104h] BYREF

  if ( args->m_nArgc >= 2 )
  {
    if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    {
      if ( hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
      {
        if ( hltv->m_DemoRecorder.IsRecording(this: &hltv->m_DemoRecorder) )
        {
          v1 = (const char *)hltv->m_DemoRecorder.GetDemoFile(this: &hltv->m_DemoRecorder);
          ConMsg(a1: "SourceTV already recording to %s.\n", v1);
        }
        else
        {
          v2 = defaultValue;
          if ( args->m_nArgc > 1 )
            v2 = args->m_ppArgv[1];
          if ( COM_IsValidPath(pszFilename: v2) )
          {
            v3 = defaultValue;
            if ( args->m_nArgc > 1 )
              v3 = args->m_ppArgv[1];
            V_strncpy(pDest: name, pSrc: v3, maxLen: 260);
            V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
            hltv->m_DemoRecorder.StartRecording(this: &hltv->m_DemoRecorder, a2: name, a3: false);
          }
          else if ( args->m_nArgc > 1 )
          {
            ConMsg(a1: "record %s: invalid path.\n", args->m_ppArgv[1]);
          }
          else
          {
            ConMsg(a1: "record %s: invalid path.\n", defaultValue);
          }
        }
      }
      else
      {
        ConMsg(a1: "Only SourceTV Master can record demos instantly.\n");
      }
    }
    else
    {
      ConMsg(a1: "SourceTV not active.\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  tv_record  <filename>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181AC0
// Name: tv_stoprecord
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_stoprecord()
{
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    hltv->m_DemoRecorder.StopRecording(this: &hltv->m_DemoRecorder);
  else
    ConMsg(a1: "SourceTV not active.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10181B00
// Name: void EditDemo_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EditDemo_f(const CCommand *args)
{
  const char *v1; // eax
  char name[260]; // [esp+0h] [ebp-104h] BYREF

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc >= 2 )
    {
      if ( hltv != nullptr )
        demoplayer = &hltv->IDemoPlayer;
      else
        demoplayer = nullptr;
      v1 = defaultValue;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      V_strncpy(pDest: name, pSrc: v1, maxLen: 260);
      V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
      hltv->m_ClientState.m_bSaveMemory = true;
      demoplayer->StartPlayback(this: demoplayer, a2: name, a3: false);
    }
    else
    {
      _Msg(a1: "editdemo <demoname> : edits a demo\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181BC0
// Name: g_editdemo_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_editdemo_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S2_12 & 1) == 0 )
  {
    _S2_12 |= 1u;
    editdemoComplete.m_pszCommandName = "editdemo";
    editdemoComplete.m_pszSubDir = nullptr;
    editdemoComplete.m_pszExtension = "dem";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &editdemoComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10181C10
// Name: private: void CHLTVServer::FreeClientRecvTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::FreeClientRecvTables(CHLTVServer *this)
{
  CHLTVServer *v1; // ebx
  int v2; // edi
  void ***m_pRecvTables; // ebx
  vgui::PropertyPage *v4; // esi

  v1 = this;
  v2 = 0;
  if ( this->m_nRecvTables > 0 )
  {
    m_pRecvTables = (void ***)this->m_pRecvTables;
    do
    {
      v4 = (vgui::PropertyPage *)*m_pRecvTables;
      if ( **m_pRecvTables != nullptr )
        free(pMem: **m_pRecvTables);
      CColorBalanceUIPanel::Init(this: v4);
      free(pMem: v4);
      ++v2;
      ++m_pRecvTables;
    }
    while ( v2 < this->m_nRecvTables );
    v1 = this;
  }
  _V_memset(dest: v1->m_pRecvTables, fill: 0, count: 4096);
  v1->m_nRecvTables = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10181C90
// Name: public: void CHLTVFrame::CopyHLTVData(class CHLTVFrame __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVFrame::CopyHLTVData(CHLTVFrame *this, CHLTVFrame *frame)
{
  int m_iCurBit; // ebx
  int v3; // edi
  void *v4; // eax
  int v5; // eax
  int v6; // edi
  void *v7; // eax

  m_iCurBit = frame->m_Messages[1].m_iCurBit;
  if ( m_iCurBit > 0 )
  {
    v3 = 4 * ((((m_iCurBit + 7) >> 3) + 3) / 4);
    v4 = MemAlloc_Alloc(nSize: v3);
    bf_write::StartWriting(this: &this->m_Messages[1], pData: v4, nBytes: v3, iStartBit: m_iCurBit, nBits: -1);
    _V_memcpy(dest: this->m_Messages[1].m_pData, src: frame->m_Messages[1].m_pData, count: v3);
  }
  v5 = frame->m_Messages[2].m_iCurBit + frame->m_Messages[4].m_iCurBit + frame->m_Messages[5].m_iCurBit;
  if ( tv_relayvoice.m_pParent != nullptr && tv_relayvoice.m_pParent->m_Value.m_nValue != 0 )
    v5 += frame->m_Messages[3].m_iCurBit;
  if ( v5 > 0 )
  {
    v6 = 4 * ((((v5 + 7) >> 3) + 3) / 4);
    v7 = MemAlloc_Alloc(nSize: v6);
    bf_write::StartWriting(this: &this->m_Messages[2], pData: v7, nBytes: v6, iStartBit: 0, nBits: -1);
    bf_write::WriteBits(
      this: &this->m_Messages[2],
      pInData: frame->m_Messages[2].m_pData,
      nBits: frame->m_Messages[2].m_iCurBit);
    bf_write::WriteBits(
      this: &this->m_Messages[2],
      pInData: frame->m_Messages[5].m_pData,
      nBits: frame->m_Messages[5].m_iCurBit);
    bf_write::WriteBits(
      this: &this->m_Messages[2],
      pInData: frame->m_Messages[4].m_pData,
      nBits: frame->m_Messages[4].m_iCurBit);
    if ( tv_relayvoice.m_pParent != nullptr && tv_relayvoice.m_pParent->m_Value.m_nValue != 0 )
      bf_write::WriteBits(
        this: &this->m_Messages[2],
        pInData: frame->m_Messages[3].m_pData,
        nBits: frame->m_Messages[3].m_iCurBit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181E00
// Name: public: virtual void CHLTVServer::SetMaxClients(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::SetMaxClients(CHLTVServer *this, int number)
{
  int v2; // eax

  v2 = number;
  if ( number >= 0 )
  {
    if ( number > 64 )
      v2 = 64;
    this->serverclassbits = v2;
  }
  else
  {
    this->serverclassbits = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181E30
// Name: public: void CHLTVServer::StartMaster(class CGameClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::StartMaster(CHLTVServer *this, CGameClient *client)
{
  IHLTVDirector *v3; // ecx
  char *m_pszString; // eax
  int v5; // eax
  CGameClient *m_MasterClient; // ecx
  int v7; // eax
  CGameServer *m_Server; // ecx
  int v9; // eax
  CGameServer *v10; // ecx
  const char **v11; // eax
  const char **v12; // edi
  int i; // ebx
  CGameEventDescriptor *EventDescriptor; // eax
  int m_nValue; // eax
  int v16; // eax
  void (__thiscall *StopRecording)(struct CHLTVDemoRecorder *); // eax
  const char *eventname; // [esp+Ch] [ebp+8h]

  this->Clear(this: &this->CBaseServer);
  if ( client != nullptr )
  {
    v3 = serverGameDirector;
    this->m_Director = serverGameDirector;
    if ( v3 != nullptr )
    {
      this->m_MasterClient = client;
      client->m_bIsHLTV = true;
      serverGameClients->GetPlayerState(this: serverGameClients, a2: this->m_MasterClient->edict)->hltv = true;
      this->m_Server = (CGameServer *)this->m_MasterClient->GetServer(this: &this->m_MasterClient->IClient);
      if ( (tv_name.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = tv_name.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "name", value: m_pszString);
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "cl_team", value: "1");
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "rate", value: "30000");
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "cl_updaterate", value: "22");
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "cl_interp_ratio", value: "1.0");
      KeyValues::SetString(this: this->m_MasterClient->m_ConVars, keyName: "cl_predict", value: "0");
      v5 = this->m_MasterClient->GetPlayerSlot(this: &this->m_MasterClient->IClient);
      m_MasterClient = this->m_MasterClient;
      this->m_nViewEntity = v5 + 1;
      v7 = m_MasterClient->GetPlayerSlot(this: &m_MasterClient->IClient);
      m_Server = this->m_Server;
      this->m_nPlayerSlot = v7;
      v9 = m_Server->GetMaxClients(this: m_Server);
      v10 = this->m_Server;
      this->m_nGameServerMaxClients = v9;
      this->serverclasses = v10->serverclasses;
      this->serverclassbits = v10->serverclassbits;
      this->worldmapCRC = v10->worldmapCRC;
      this->clientDllCRC = v10->clientDllCRC;
      this->m_flTickInterval = v10->GetTickInterval(this: v10);
      CHLTVFrame::AllocBuffers(this: &this->m_HLTVFrame);
      CHLTVServer::InstallStringTables(this);
      this->m_Director->SetHLTVServer(this: this->m_Director, a2: &this->IHLTVServer);
      v11 = this->m_Director->GetModEvents(this: this->m_Director);
      v12 = v11;
      for ( i = 0; *v11 != nullptr; v11 = &v12[i] )
      {
        eventname = *v11;
        EventDescriptor = CGameEventManager::GetEventDescriptor(this: g_GameEventManager, name: *v11, pCookie: nullptr);
        if ( EventDescriptor != nullptr )
          CGameEventManager::AddListener(
            this: g_GameEventManager,
            listener: this,
            descriptor: EventDescriptor,
            nListenerType: 2);
        else
          DevMsg(a1: "CHLTVServer::StartMaster: game event %s not found.\n", eventname);
        ++i;
      }
      bf_write::StartWriting(
        this: &this->m_Signon,
        pData: this->m_Server->m_Signon.m_pData,
        nBytes: this->m_Server->m_Signon.m_nDataBytes,
        iStartBit: this->m_Server->m_Signon.m_iCurBit,
        nBits: -1);
      V_strncpy(pDest: this->m_szMapname, pSrc: this->m_Server->m_szMapname, maxLen: 64);
      V_strncpy(pDest: this->m_szSkyname, pSrc: this->m_Server->m_szSkyname, maxLen: 64);
      NET_ListenSocket(sock: this->m_Socket, bListen: true);
      this->m_MasterClient->ExecuteStringCommand(this: &this->m_MasterClient->IClient, a2: "spectate");
      this->m_MasterClient->UpdateUserSettings(this: this->m_MasterClient);
      --this->m_MasterClient->m_nSignonTick;
      if ( this->m_bMasterOnlyMode )
      {
        if ( tv_maxclients.m_pParent != nullptr )
        {
          m_nValue = tv_maxclients.m_pParent->m_Value.m_nValue;
          if ( m_nValue > 1 )
            m_nValue = 1;
        }
        else
        {
          m_nValue = 0;
        }
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&tv_maxclients.IConVar, value: m_nValue);
      }
      if ( tv_maxclients.m_pParent != nullptr )
        v16 = tv_maxclients.m_pParent->m_Value.m_nValue;
      else
        v16 = 0;
      this->SetMaxClients(this: &this->CBaseServer, a2: v16);
      ++this->m_nSpawnCount;
      StopRecording = this->m_DemoRecorder.StopRecording;
      this->m_bSignonState = false;
      this->m_flStartTime = net_time;
      this->m_State = ss_active;
      StopRecording(this: &this->m_DemoRecorder);
      if ( tv_autorecord.m_pParent != nullptr && tv_autorecord.m_pParent->m_Value.m_nValue != 0 )
        CHLTVDemoRecorder::StartAutoRecording(this: &this->m_DemoRecorder);
      CBaseServer::ReconnectClients(this: &this->CBaseServer);
    }
    else
    {
      ConMsg(a1: "Mod doesn't support SourceTV. No director module found.\n");
    }
  }
  else
  {
    ConMsg(a1: "SourceTV client not found.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101821D0
// Name: public: void CHLTVServer::ConnectRelay(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::ConnectRelay(CHLTVServer *this, const char *address)
{
  if ( this->m_ClientState.m_nSignonState >= 2 )
  {
    CAddressList::RemoveAll(this: &this->m_ClientState.m_Remote);
    this->m_ClientState.Disconnect(this: &this->m_ClientState, a2: true);
    this->m_DemoRecorder.StopRecording(this: &this->m_DemoRecorder);
    CBaseServer::InactivateClients(this: &this->CBaseServer);
    CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
    this->m_CurrentFrame = nullptr;
  }
  this->m_ClientState.Connect(this: &this->m_ClientState, a2: address, a3: address);
}

//------------------------------------------------------------------------------
// Address: 0x10182250
// Name: public: virtual void CHLTVServer::BroadcastEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::BroadcastEvent(CHLTVServer *this, IGameEvent *event)
{
  const char *v3; // eax
  const char *v4; // eax
  char buffer_data[1024]; // [esp+Ch] [ebp-450h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-50h] BYREF

  eventMsg.m_bReliable = true;
  eventMsg.m_NetChannel = nullptr;
  eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
  eventMsg.m_DataIn.m_bOverflow = false;
  eventMsg.m_DataIn.m_pDebugName = nullptr;
  eventMsg.m_DataIn.m_nDataBits = -1;
  eventMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &eventMsg.m_DataOut);
  bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
  if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventMsg.m_DataOut) )
  {
    (*(void (__thiscall **)(char *, SVC_GameEvent *, int, int))(*((_DWORD *)this - 128) + 136))(
      a1: (char *)this - 512,
      a2: &eventMsg,
      a3: 1,
      a4: 1);
    if ( tv_debug.m_pParent != nullptr && tv_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v4 = event->GetName(this: event);
      _Msg(a1: "SourceTV broadcast event: %s\n", v4);
    }
  }
  else
  {
    v3 = event->GetName(this: event);
    DevMsg(a1: "CHLTVServer: failed to serialize event '%s'.\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182330
// Name: public: virtual void CHLTVServer::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::FireGameEvent(CHLTVServer *this, IGameEvent *event)
{
  const char *v3; // eax
  char buffer_data[1024]; // [esp+4h] [ebp-450h] BYREF
  SVC_GameEvent eventMsg; // [esp+404h] [ebp-50h] BYREF

  if ( this->IsActive(this: &this->CBaseServer) )
  {
    eventMsg.m_bReliable = true;
    eventMsg.m_NetChannel = nullptr;
    eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
    eventMsg.m_DataIn.m_bOverflow = false;
    eventMsg.m_DataIn.m_pDebugName = nullptr;
    eventMsg.m_DataIn.m_nDataBits = -1;
    eventMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &eventMsg.m_DataOut);
    bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
    if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventMsg.m_DataOut) )
    {
      CHLTVServer::SendNetMsg(this, a2: (int)this, msg: &eventMsg, bForceReliable: false, bVoice: false);
    }
    else
    {
      v3 = event->GetName(this: event);
      DevMsg(a1: "CHLTVServer::FireGameEvent: failed to serialize event '%s'.\n", v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101823E0
// Name: public: void CHLTVServer::LinkInstanceBaselines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::LinkInstanceBaselines(CHLTVServer *this)
{
  DWORD CurrentThreadId; // ecx
  ServerClass *i; // esi
  int v4; // eax
  char idString[36]; // [esp+8h] [ebp-24h] BYREF

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_svInstanceBaselineMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_svInstanceBaselineMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_svInstanceBaselineMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_svInstanceBaselineMutex.m_depth;
  }
  CBaseServer::GetInstanceBaselineTable(this: &this->CBaseServer);
  for ( i = serverGameDLL->GetAllServerClasses(this: serverGameDLL); i != nullptr; i = i->m_pNext )
  {
    V_snprintf(pDest: idString, maxLen: 32, pFormat: "%d", i->m_ClassID);
    v4 = this->m_pInstanceBaselineTable->FindStringIndex(this: this->m_pInstanceBaselineTable, a2: idString);
    if ( v4 == -1 )
      i->m_InstanceBaselineIndex = 0xFFFF;
    else
      i->m_InstanceBaselineIndex = v4;
  }
  if ( --g_svInstanceBaselineMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_svInstanceBaselineMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101824A0
// Name: public: void CHLTVServer::SignonComplete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::SignonComplete(CHLTVServer *this)
{
  this->m_bSignonState = false;
  CHLTVServer::LinkInstanceBaselines(this);
  if ( tv_debug.m_pParent != nullptr && tv_debug.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "SourceTV signon complete.\n");
}

//------------------------------------------------------------------------------
// Address: 0x101824D0
// Name: private: void CHLTVServer::UpdateStats(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVServer::UpdateStats(CHLTVServer *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  bool (__thiscall *IsMasterProxy)(IHLTVServer *); // edx
  int v5; // eax
  IGameEvent *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  int v9; // [esp-8h] [ebp-38h]
  int v10; // [esp-4h] [ebp-34h]
  char address[32]; // [esp+4h] [ebp-2Ch] BYREF
  int proxies; // [esp+24h] [ebp-Ch] BYREF
  int slots; // [esp+28h] [ebp-8h] BYREF
  int clients; // [esp+2Ch] [ebp-4h] BYREF

  if ( this->m_fNextSendUpdateTime <= net_time )
  {
    IsMasterProxy = this->IsMasterProxy;
    this->m_fNextSendUpdateTime = net_time + 8.0;
    if ( ((unsigned __int8 (__thiscall *)(IHLTVServer *, int, int))IsMasterProxy)(a1: &this->IHLTVServer, a2, a3) != 0
      || this->m_ClientState.m_nSignonState >= 2 )
    {
      ((void (__thiscall *)(IHLTVServer *, int *))this->GetGlobalStats)(a1: &this->IHLTVServer, a2: &proxies);
      v6 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "hltv_status", a3: 1, a4: 0);
      if ( v6 == nullptr )
        return;
      if ( ((unsigned __int8 (__thiscall *)(IHLTVServer *, int *, int *))this->IsMasterProxy)(
             a1: &this->IHLTVServer,
             a2: &slots,
             a3: &clients) != 0
        || tv_overridemaster.m_pParent != nullptr && tv_overridemaster.m_pParent->m_Value.m_nValue != 0 )
      {
        v10 = this->GetUDPPort(this: &this->CBaseServer);
        v8 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
        V_snprintf(pDest: address, maxLen: 32, pFormat: "%s:%u", v8, v10);
      }
      else
      {
        v7 = netadr_s::ToString(this: &this->m_RootServer, baseOnly: false);
        V_snprintf(pDest: address, maxLen: 32, pFormat: "%s", v7);
      }
      v6->SetString(this: v6, a2: "master", a3: address);
      v6->SetInt(this: v6, a2: "clients", a3: clients);
      v6->SetInt(this: v6, a2: "slots", a3: slots);
      ((void (__thiscall *)(IGameEvent *, const char *, int, int))v6->SetInt)(
        a1: v6,
        a2: "proxies",
        a3: proxies,
        a4: v9);
    }
    else
    {
      v5 = ((int (__thiscall *)(CGameEventManager *, const char *))g_GameEventManager->CreateEventA)(
             a1: g_GameEventManager,
             a2: "hltv_message");
      v6 = (IGameEvent *)v5;
      if ( v5 == 0 )
        return;
      (*(void (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)v5 + 56))(
        a1: v5,
        a2: "text",
        a3: "SourceTV reconnecting ...",
        a4: 1);
    }
    if ( this->IsMasterProxy(this: &this->IHLTVServer) )
      ((void (__thiscall *)(CGameEventManager *, IGameEvent *))g_GameEventManager->FireEvent)(
        a1: g_GameEventManager,
        a2: v6);
    else
      this->BroadcastEvent(this: &this->IHLTVServer, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101826A0
// Name: private: void CHLTVServer::ReadCompeleteDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::ReadCompeleteDemoFile(CHLTVServer *this)
{
  char *ConsoleCommand; // eax
  bool (__thiscall *ProcessStringCmd)(struct IServerMessageHandler *, NET_StringCmd *); // edx
  int RawData; // eax
  char v5[96000]; // [esp+Ch] [ebp-27C9Ch] BYREF
  _BYTE pData[65536]; // [esp+1770Ch] [ebp-1059Ch] BYREF
  char buffer[256]; // [esp+2770Ch] [ebp-59Ch] BYREF
  void **v8; // [esp+2780Ch] [ebp-49Ch] BYREF
  char v9; // [esp+27810h] [ebp-498h]
  int v10; // [esp+27814h] [ebp-494h]
  char *v11; // [esp+2781Ch] [ebp-48Ch]
  netadr_s dest; // [esp+27C20h] [ebp-88h] BYREF
  double v13; // [esp+27C30h] [ebp-78h]
  CBitRead v14; // [esp+27C3Ch] [ebp-6Ch] BYREF
  int v15; // [esp+27C60h] [ebp-48h]
  int nSeqNrIn; // [esp+27C70h] [ebp-38h] BYREF
  CBitRead v17; // [esp+27C74h] [ebp-34h] BYREF
  int tick; // [esp+27C98h] [ebp-10h] BYREF
  int nPlayerSlot; // [esp+27C9Ch] [ebp-Ch] BYREF
  int size; // [esp+27CA0h] [ebp-8h] BYREF
  unsigned __int8 cmd; // [esp+27CA7h] [ebp-1h] BYREF

  tick = 0;
  cmd = 1;
  netadr_s::SetIP(this: &dest, unIP: 0);
  netadr_s::SetPort(this: &dest, newport: 0);
  netadr_s::SetType(this: &dest, newtype: NA_IP);
  v14.m_bOverflow = false;
  v14.m_pDebugName = nullptr;
  v14.m_nDataBits = -1;
  v14.m_nDataBytes = 0;
  _V_memset(&dest, fill: 0, count: 80);
  netadr_s::SetType(this: &dest, newtype: NA_LOOPBACK);
  while ( 1 )
  {
    nPlayerSlot = 0;
    CDemoFile::ReadCmdHeader(this: &this->m_DemoFile, &cmd, &tick, &nPlayerSlot);
    switch ( cmd )
    {
      case 1u:
      case 2u:
        size = 0;
        CDemoFile::ReadCmdInfo(this: &this->m_DemoFile, info: &this->m_LastCmdInfo);
        CDemoFile::ReadSequenceInfo(this: &this->m_DemoFile, &nSeqNrIn, nSeqNrOut: &size);
        RawData = CDemoFile::ReadRawData(this: &this->m_DemoFile, buffer: v5, length: 96000);
        if ( RawData > 0 )
        {
          v13 = realtime;
          v15 = RawData;
          CBitRead::StartReading(this: &v14, pData: v5, nBytes: RawData, iStartBit: 0, nBits: -1);
          this->m_ClientState.m_NetChannel->ProcessPacket(
            this: this->m_ClientState.m_NetChannel,
            a2: (netpacket_s *)&dest,
            a3: false);
        }
        break;
      case 3u:
        this->m_nStartTick = host_tickcount;
        break;
      case 4u:
        ConsoleCommand = CDemoFile::ReadConsoleCommand(this: &this->m_DemoFile);
        ProcessStringCmd = this->m_ClientState.ProcessStringCmd;
        v11 = ConsoleCommand;
        v9 = 1;
        v10 = 0;
        v8 = &NET_StringCmd::`vftable';
        ProcessStringCmd(this: &this->m_ClientState.IServerMessageHandler, a2: (NET_StringCmd *)&v8);
        break;
      case 5u:
        size = 256;
        CDemoFile::ReadUserCmd(this: &this->m_DemoFile, buffer, &size);
        break;
      case 6u:
        v17.m_bOverflow = false;
        v17.m_nDataBits = -1;
        v17.m_nDataBytes = 0;
        v17.m_pDebugName = "dem_datatables";
        CBitRead::StartReading(this: &v17, pData, nBytes: 0x10000, iStartBit: 0, nBits: -1);
        CDemoFile::ReadStringTables(this: &this->m_DemoFile, buf: (bf_read *)&v17);
        CBitRead::Seek(this: &v17, nPosition: 0);
        if ( DataTable_LoadDataTablesFromBuffer(
               pBuf: (bf_read *)&v17,
               nDemoProtocol: this->m_DemoFile.m_DemoHeader.demoprotocol) == 0 )
          Host_Error(error: "Error parsing network data tables during demo playback.");
        break;
      case 7u:
        return;
      case 9u:
        size = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x80000);
        v17.m_bOverflow = false;
        v17.m_nDataBits = -1;
        v17.m_nDataBytes = 0;
        v17.m_pDebugName = "dem_stringtables";
        CBitRead::StartReading(this: &v17, pData: (const void *)size, nBytes: 0x80000, iStartBit: 0, nBits: -1);
        CDemoFile::ReadStringTables(this: &this->m_DemoFile, buf: (bf_read *)&v17);
        CBitRead::Seek(this: &v17, nPosition: 0);
        if ( CNetworkStringTableContainer::ReadStringTables(
               this: networkStringTableContainerClient,
               buf: (bf_read *)&v17) == 0 )
          Host_Error(error: "Error parsing string tables during demo playback.");
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)size);
        break;
      default:
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182990
// Name: public: bool CHLTVServer::DispatchToRelay(class CHLTVClient __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CHLTVServer::DispatchToRelay@<al>(CHLTVServer *this@<ecx>, int a2@<edi>, CHLTVClient *pClient)
{
  CHLTVServer *v3; // esi
  int (__thiscall *GetClientCount)(struct CBaseServer *); // edx
  CBaseServer *v6; // edi
  CHLTVClient *v7; // ebx
  bool (__thiscall *IsConnected)(IClient *); // eax
  IClient *v9; // esi
  const char *v10; // eax
  int v11; // ebx
  const char *v12; // eax
  int v13; // eax
  int (__thiscall *v14)(struct CBaseServer *); // eax
  CBaseClient *v15; // ebx
  int v16; // eax
  int (__thiscall *GetMaxClients)(struct CBaseServer *); // edx
  float v18; // xmm0_4
  int v19; // eax
  netadr_s *v20; // eax
  const char *v21; // eax
  void (__thiscall *FillServerInfo)(CBaseServer *, SVC_ServerInfo *); // edx
  const char *v23; // eax
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // edx
  const char *v25; // eax
  int v26; // eax
  CBaseClient *v27; // edi
  CBaseClient_vtbl *v28; // esi
  char *v29; // eax
  SVC_ServerInfo serverInfo; // [esp+4h] [ebp-880h] BYREF
  NET_StringCmd cmdMsg; // [esp+45Ch] [ebp-428h] BYREF
  CHLTVServer *v33; // [esp+870h] [ebp-14h]
  int i; // [esp+874h] [ebp-10h]
  CBaseClient *pProxy; // [esp+878h] [ebp-Ch]
  CBaseClient *pBestProxy; // [esp+87Ch] [ebp-8h]
  float fBestRatio; // [esp+880h] [ebp-4h]

  v3 = this;
  v33 = this;
  if ( tv_dispatchmode.m_pParent == nullptr || tv_dispatchmode.m_pParent->m_Value.m_nValue <= 0 )
    return 0;
  GetClientCount = this->GetClientCount;
  v6 = &this->CBaseServer;
  pBestProxy = nullptr;
  i = 0;
  fBestRatio = 1.0;
  if ( GetClientCount(this: &this->CBaseServer) > 0 )
  {
    while ( 1 )
    {
      v7 = (CHLTVClient *)v3->m_Clients.m_Memory.m_pMemory[i];
      IsConnected = v7->IsConnected;
      v9 = &v7->IClient;
      pProxy = v7;
      if ( IsConnected(this: &v7->IClient) && v9->IsHLTV(this: &v7->IClient) && pClient != v7 )
      {
        v10 = v9->GetUserSetting(this: &v7->IClient, a2: "hltv_slots");
        v11 = V_atoi(str: v10);
        v12 = v9->GetUserSetting(this: v9, a2: "hltv_clients");
        v13 = V_atoi(str: v12);
        if ( v13 <= v11 && v11 > 0 && fBestRatio > (float)((float)v13 / (float)v11) )
        {
          fBestRatio = (float)v13 / (float)v11;
          pBestProxy = pProxy;
        }
      }
      v14 = v6->GetClientCount;
      if ( ++i >= v14(this: v6) )
        break;
      v3 = v33;
    }
    v15 = pBestProxy;
    if ( pBestProxy != nullptr )
    {
      if ( tv_dispatchmode.m_pParent != nullptr
        && tv_dispatchmode.m_pParent->m_Value.m_nValue == 1
        && v6->GetMaxClients(this: v6) > 0 )
      {
        v16 = v6->GetNumClients(this: v6);
        GetMaxClients = v6->GetMaxClients;
        *(float *)&pProxy = (float)v16;
        v18 = (float)((float)v16 / (float)GetMaxClients(this: v6)) * 1.25;
        if ( v18 >= 1.0 )
          v18 = 1.0;
        if ( fBestRatio > v18 )
          return 0;
      }
      fBestRatio = COERCE_FLOAT((int)pBestProxy->GetUserSetting(this: &pBestProxy->IClient, a2: "hltv_addr"));
      if ( fBestRatio == 0.0 )
        return 0;
      v19 = ((int (__thiscall *)(IClient *, int))pClient->GetNetChannel)(a1: &pClient->IClient, a2);
      v20 = (netadr_s *)(*(int (__thiscall **)(int))(*(_DWORD *)v19 + 196))(a1: v19);
      v21 = netadr_s::ToString(this: v20, baseOnly: false);
      ConMsg(a1: "Redirecting spectator %s to SourceTV relay %s\n", v21, (const char *)LODWORD(fBestRatio));
      FillServerInfo = v6->FillServerInfo;
      serverInfo.m_bReliable = true;
      serverInfo.m_NetChannel = nullptr;
      serverInfo.__vftable = (SVC_ServerInfo_vtbl *)&SVC_ServerInfo::`vftable';
      FillServerInfo(this: v6, a2: &serverInfo);
      pClient->SendNetMsg(this: &pClient->IClient, a2: &serverInfo, a3: true, a4: false);
      v23 = va(format: "connect %s\n", (const char *)LODWORD(fBestRatio));
      SendNetMsg = pClient->SendNetMsg;
      cmdMsg.m_szCommand = v23;
      cmdMsg.m_bReliable = true;
      cmdMsg.m_NetChannel = nullptr;
      cmdMsg.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
      SendNetMsg(this: &pClient->IClient, a2: &cmdMsg, a3: true, a4: false);
      v25 = v15->GetUserSetting(this: &v15->IClient, a2: "hltv_clients");
      v26 = V_atoi(str: v25);
      v27 = pBestProxy;
      v28 = pBestProxy->IGameEventListener2::__vftable;
      v29 = va(format: "%d", v26 + 1);
      v28->SetUserCVar(this: v27, a2: "hltv_clients", a3: v29);
      return 1;
    }
  }
  if ( tv_dispatchmode.m_pParent != nullptr && tv_dispatchmode.m_pParent->m_Value.m_nValue == 2 )
  {
    pClient->Disconnect(this: &pClient->IClient, a2: "No SourceTV relay available");
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10182C70
// Name: public: void CHLTVServer::GetRelayStats(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::GetRelayStats(CHLTVServer *this, int *proxies, int *slots, int *clients)
{
  CHLTVServer *v5; // esi
  CBaseClient *v6; // esi
  bool (__thiscall *IsConnected)(IClient *); // edx
  IClient *v8; // esi
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int i; // [esp+20h] [ebp+10h]

  v5 = this;
  *clients = 0;
  *slots = 0;
  *proxies = 0;
  i = 0;
  if ( this->GetClientCount(this: &this->CBaseServer) > 0 )
  {
    while ( 1 )
    {
      v6 = v5->m_Clients.m_Memory.m_pMemory[i];
      IsConnected = v6->IsConnected;
      v8 = &v6->IClient;
      if ( IsConnected(this: v8) && v8->IsHLTV(this: v8) )
      {
        v9 = v8->GetUserSetting(this: v8, a2: "hltv_proxies");
        *proxies += V_atoi(str: v9);
        v10 = v8->GetUserSetting(this: v8, a2: "hltv_slots");
        *slots += V_atoi(str: v10);
        v11 = v8->GetUserSetting(this: v8, a2: "hltv_clients");
        *clients += V_atoi(str: v11);
      }
      if ( ++i >= this->GetClientCount(this: &this->CBaseServer) )
        break;
      v5 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182D60
// Name: public: virtual void CHLTVServer::GetGlobalStats(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::GetGlobalStats(CHLTVServer *this, int *proxies, int *slots, int *clients)
{
  int v5; // eax
  int v6; // edx

  if ( (unsigned __int8)this->IGameEventListener2::__vftable[2].GetEventDebugID(this) != 0 )
  {
    CHLTVServer::GetRelayStats(
      this: (CHLTVServer *)((char *)this - 520),
      proxies: (int *)&this->m_pRecvTables[904],
      slots: (int *)&this->m_pRecvTables[902],
      clients: (int *)&this->m_pRecvTables[903]);
    v5 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 128) + 20))(a1: (char *)this - 512);
    v6 = *((_DWORD *)this - 128);
    this->m_pRecvTables[902] = (RecvTable *)((char *)this->m_pRecvTables[902] + v5);
    this->m_pRecvTables[903] = (RecvTable *)((char *)this->m_pRecvTables[903]
                                           + (*(int (__thiscall **)(char *))(v6 + 8))(a1: (char *)this - 512));
  }
  *proxies = (int)this->m_pRecvTables[904];
  *slots = (int)this->m_pRecvTables[902];
  *clients = (int)this->m_pRecvTables[903];
}

//------------------------------------------------------------------------------
// Address: 0x10182DF0
// Name: public: void CHLTVServer::BroadcastLocalTitle(class CHLTVClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::BroadcastLocalTitle(CHLTVServer *this, CHLTVClient *client)
{
  CHLTVServer *v2; // esi
  IGameEvent *(__thiscall *CreateEventA)(struct CGameEventManager *, const char *, bool, int *); // edx
  int v4; // edi
  IGameEvent *v5; // ebx
  char *m_pszString; // eax
  const char *v7; // eax
  CBaseClient *v8; // esi
  bool (__thiscall *IsActive)(IClient *); // eax
  IClient *v10; // esi
  char buffer_data[1024]; // [esp+Ch] [ebp-454h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-54h] BYREF
  CHLTVServer *v13; // [esp+45Ch] [ebp-4h]

  v2 = this;
  CreateEventA = g_GameEventManager->CreateEventA;
  v4 = 0;
  v13 = this;
  v5 = CreateEventA(this: g_GameEventManager, a2: "hltv_title", a3: true, a4: nullptr);
  if ( v5 != nullptr )
  {
    if ( (tv_title.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = tv_title.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    v5->SetString(this: v5, a2: "text", a3: m_pszString);
    eventMsg.m_NetChannel = nullptr;
    eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
    eventMsg.m_DataIn.m_bOverflow = false;
    eventMsg.m_DataIn.m_pDebugName = nullptr;
    eventMsg.m_DataIn.m_nDataBits = -1;
    eventMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &eventMsg.m_DataOut);
    eventMsg.m_bReliable = true;
    bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
    if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: v5, a3: &eventMsg.m_DataOut) )
    {
      if ( client != nullptr )
      {
        client->SendNetMsg(this: &client->IClient, a2: &eventMsg, a3: false, a4: false);
      }
      else if ( v2->m_Clients.m_Size > 0 )
      {
        while ( 1 )
        {
          v8 = v2->m_Clients.m_Memory.m_pMemory[v4];
          IsActive = v8->IsActive;
          v10 = &v8->IClient;
          if ( IsActive(this: v10) && !v10->IsHLTV(this: v10) )
            v10->SendNetMsg(this: v10, a2: &eventMsg, a3: false, a4: false);
          if ( ++v4 >= v13->m_Clients.m_Size )
            break;
          v2 = v13;
        }
      }
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v5);
    }
    else
    {
      v7 = v5->GetName(this: v5);
      DevMsg(a1: "CHLTVServer: failed to serialize title '%s'.\n", v7);
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182F70
// Name: public: void CHLTVServer::BroadcastLocalChat(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::BroadcastLocalChat(CHLTVServer *this, const char *pszChat, const char *pszGroup)
{
  CHLTVServer *v3; // esi
  IGameEvent *(__thiscall *CreateEventA)(struct CGameEventManager *, const char *, bool, int *); // edx
  IGameEvent *v5; // ebx
  const char *v6; // eax
  CBaseClient *v7; // edi
  char buffer_data[1024]; // [esp+Ch] [ebp-454h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-54h] BYREF
  CHLTVServer *v10; // [esp+45Ch] [ebp-4h]
  int i; // [esp+468h] [ebp+8h]

  v3 = this;
  CreateEventA = g_GameEventManager->CreateEventA;
  v10 = this;
  v5 = CreateEventA(this: g_GameEventManager, a2: "hltv_chat", a3: true, a4: nullptr);
  if ( v5 != nullptr )
  {
    v5->SetString(this: v5, a2: "text", a3: pszChat);
    eventMsg.m_NetChannel = nullptr;
    eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
    eventMsg.m_DataIn.m_bOverflow = false;
    eventMsg.m_DataIn.m_pDebugName = nullptr;
    eventMsg.m_DataIn.m_nDataBits = -1;
    eventMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &eventMsg.m_DataOut);
    eventMsg.m_bReliable = false;
    bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
    if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: v5, a3: &eventMsg.m_DataOut) )
    {
      i = 0;
      if ( v3->m_Clients.m_Size > 0 )
      {
        while ( 1 )
        {
          v7 = v3->m_Clients.m_Memory.m_pMemory[i];
          if ( v7->IsActive(this: &v7->IClient)
            && v7->IsSpawned(this: &v7->IClient)
            && !v7->IsHLTV(this: &v7->IClient)
            && _V_strcmp(s1: &v7[1].m_GUID[5], s2: pszGroup) == 0
            && v7[1].m_GUID[4] == 0 )
          {
            v7->SendNetMsg(this: &v7->IClient, a2: &eventMsg, a3: false, a4: false);
          }
          if ( ++i >= v10->m_Clients.m_Size )
            break;
          v3 = v10;
        }
      }
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v5);
    }
    else
    {
      v6 = v5->GetName(this: v5);
      DevMsg(a1: "CHLTVServer: failed to serialize chat '%s'.\n", v6);
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183100
// Name: public: void CHLTVServer::BroadcastEventLocal(class IGameEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::BroadcastEventLocal(CHLTVServer *this, IGameEvent *event, bool bReliable)
{
  int v3; // edi
  IGameEvent *v5; // esi
  const char *v6; // eax
  CBaseClient *v7; // esi
  bool (__thiscall *IsActive)(IClient *); // eax
  IClient *v9; // esi
  const char *v10; // eax
  const char *v11; // eax
  char buffer_data[1024]; // [esp+Ch] [ebp-450h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-50h] BYREF

  v3 = 0;
  eventMsg.m_NetChannel = nullptr;
  eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
  eventMsg.m_DataIn.m_bOverflow = false;
  eventMsg.m_DataIn.m_pDebugName = nullptr;
  eventMsg.m_DataIn.m_nDataBits = -1;
  eventMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &eventMsg.m_DataOut);
  eventMsg.m_bReliable = bReliable;
  bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
  v5 = event;
  if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventMsg.m_DataOut) )
  {
    if ( this->m_Clients.m_Size > 0 )
    {
      do
      {
        v7 = this->m_Clients.m_Memory.m_pMemory[v3];
        IsActive = v7->IsActive;
        v9 = &v7->IClient;
        if ( IsActive(this: v9)
          && v9->IsSpawned(this: v9)
          && !v9->IsHLTV(this: v9)
          && !v9->SendNetMsg(this: v9, a2: &eventMsg, a3: false, a4: false)
          && eventMsg.m_bReliable )
        {
          v10 = v9->GetClientName(this: v9);
          DevMsg(a1: "BroadcastMessage: Reliable broadcast message overflow for client %s", v10);
        }
        ++v3;
      }
      while ( v3 < this->m_Clients.m_Size );
      v5 = event;
    }
    if ( tv_debug.m_pParent != nullptr && tv_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v11 = v5->GetName(this: v5);
      _Msg(a1: "SourceTV broadcast local event: %s\n", v11);
    }
  }
  else
  {
    v6 = event->GetName(this: event);
    DevMsg(a1: "CHLTVServer: failed to serialize local event '%s'.\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183250
// Name: private: void CHLTVServer::EntityPVSCheck(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::EntityPVSCheck(CHLTVServer *this, CClientFrame *pFrame)
{
  IHLTVDirector *m_Director; // ecx
  CFrameSnapshot *v4; // edi
  int (__thiscall *GetPVSEntity)(IHLTVDirector *); // eax
  int v6; // eax
  Vector *HLTVDataInSnapshot; // eax
  int v8; // esi
  int v9; // ecx
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int *v12; // edx
  int v13; // edi
  CHLTVEntityData *v14; // eax
  int m_nNodeCluster; // eax
  unsigned __int8 pvs[8192]; // [esp+Ch] [ebp-2014h] BYREF
  _BYTE v17[12]; // [esp+200Ch] [ebp-14h] BYREF
  CFrameSnapshot *pSnapshot; // [esp+2018h] [ebp-8h]
  int vissize; // [esp+201Ch] [ebp-4h]

  vissize = (g_BSPData.numclusters + 7) / 8;
  SV_ResetPVS(pvs, nPVSSize: vissize);
  m_Director = this->m_Director;
  GetPVSEntity = m_Director->GetPVSEntity;
  pSnapshot = pFrame->m_pSnapshot;
  v4 = pSnapshot;
  v6 = GetPVSEntity(this: m_Director);
  if ( v4 == nullptr || v6 <= 0 )
  {
    HLTVDataInSnapshot = this->m_Director->GetPVSOrigin(this: this->m_Director, result: v17);
LABEL_6:
    this->m_vPVSOrigin.x = HLTVDataInSnapshot->x;
    this->m_vPVSOrigin.y = HLTVDataInSnapshot->y;
    this->m_vPVSOrigin.z = HLTVDataInSnapshot->z;
    goto LABEL_7;
  }
  HLTVDataInSnapshot = (Vector *)FindHLTVDataInSnapshot(pSnapshot: v4, iEntIndex: v6);
  if ( HLTVDataInSnapshot != nullptr )
    goto LABEL_6;
LABEL_7:
  SV_AddOriginToPVS(vOrigin: &this->m_vPVSOrigin);
  v8 = -1;
  while ( 1 )
  {
    v9 = v8 + 1;
    if ( v8 + 1 >= 2048 )
      break;
    v10 = v9 >> 5;
    v11 = pFrame->transmit_entity.m_Ints[v9 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v9 & 0x1F];
    v12 = &pFrame->transmit_entity.m_Ints[v10];
    while ( v11 == 0 )
    {
      v11 = v12[1];
      ++v12;
      if ( ++v10 > 63 )
        return;
    }
    _BitScanForward(&v11, v11);
    v8 = v11 + 32 * v10;
    if ( v8 < 0 )
      break;
    v13 = 1 << (v8 & 0x1F);
    if ( (v13 & pFrame->transmit_always->m_Ints[(unsigned int)v8 >> 5]) != 0 )
    {
      pFrame->last_entity = v8;
    }
    else
    {
      v14 = FindHLTVDataInSnapshot(pSnapshot, iEntIndex: v8);
      if ( v14 != nullptr )
      {
        m_nNodeCluster = v14->m_nNodeCluster;
        if ( m_nNodeCluster >= 0 )
        {
          if ( ((unsigned __int8)(1 << (m_nNodeCluster & 7)) & pvs[(unsigned int)m_nNodeCluster >> 3]) != 0 )
            pFrame->last_entity = v8;
          else
LABEL_22:
            pFrame->transmit_entity.m_Ints[v8 >> 5] &= ~v13;
        }
        else
        {
          if ( !CM_HeadnodeVisible(nodenum: m_nNodeCluster & 0x7FFFFFFF, visbits: pvs, vissize) )
            goto LABEL_22;
          pFrame->last_entity = v8;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101833D0
// Name: public: virtual void CHLTVServer::SendClientMessages(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::SendClientMessages(CHLTVServer *this, bool bSendSnapshots)
{
  int i; // ebx
  long double *v4; // esi

  for ( i = 0; i < this->m_Clients.m_Memory.m_nAllocationCount; ++i )
  {
    v4 = *(long double **)(LODWORD(this->m_flTickInterval) + 4 * i);
    if ( (*(unsigned __int8 (__thiscall **)(long double *))(*(_DWORD *)v4 + 20))(a1: v4) != 0 )
    {
      if ( this->m_nFirstTick != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*((_DWORD *)v4 + 1) + 132))(a1: (int)v4 + 4) != 0 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 44))(a1: this->m_nFirstTick);
      }
      else
      {
        (*(void (__stdcall **)(_DWORD))(**((_DWORD **)v4 + 55) + 192))(a1: 0);
      }
      (*(void (__thiscall **)(long double *))(*(_DWORD *)v4 + 24))(a1: v4);
      v4[15073] = net_time;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183460
// Name: public: virtual bool CHLTVServer::StartPlayback(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVServer::StartPlayback(CHLTVServer *this, const char *filename, bool bAsTimeDemo)
{
  CNetChan *NetChannel; // eax
  CStatTime *v6; // ecx
  CStatTime *v7; // ecx
  double v8; // st7
  double v9; // [esp+10h] [ebp-8h]

  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 129) + 168))(a1: (char *)this - 516);
  if ( CDemoFile::Open(
         this: (CDemoFile *)&this->m_DeltaCache.m_Cache[1922],
         name: filename,
         bReadOnly: true,
         bMemoryBuffer: false) == 0 )
    return 0;
  if ( CDemoFile::ReadDemoHeader(this: (CDemoFile *)&this->m_DeltaCache.m_Cache[1922]) == nullptr )
  {
    ConMsg(a1: "Failed to read demo header.\n");
    CDemoFile::Close(this: (CDemoFile *)&this->m_DeltaCache.m_Cache[1922]);
    return 0;
  }
  NetChannel = NET_CreateNetChannel(
                 socket: 0,
                 adr: nullptr,
                 name: "DEMO",
                 handler: (INetChannelHandler *)&this->m_State,
                 bForceNewChannel: false);
  *(_DWORD *)&this->m_szMapname[4] = NetChannel;
  if ( NetChannel != nullptr )
  {
    ((void (__thiscall *)(CNetChan *, _DWORD, _DWORD))NetChannel->SetTimeout)(a1: NetChannel, a2: -1.0, a3: 0);
    this->m_DemoFile.m_DemoHeader.mapname[172] = 1;
    ConMsg(a1: "Reading complete demo file at once...\n");
    v9 = _Plat_FloatTime(this: v6);
    CHLTVServer::ReadCompeleteDemoFile(this: (CHLTVServer *)((char *)this - 524));
    v8 = _Plat_FloatTime(this: v7);
    ConMsg(a1: "Reading time :%.4f\n", v8 - v9);
    NET_RemoveNetChannel(netchan: *(CNetChan **)&this->m_szMapname[4], bDeleteNetChan: true);
    *(_DWORD *)&this->m_szMapname[4] = 0;
    return 1;
  }
  else
  {
    ConMsg(a1: "CDemo::Play: failed to create demo net channel\n");
    CDemoFile::Close(this: (CDemoFile *)&this->m_DeltaCache.m_Cache[1922]);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183580
// Name: tv_clients
// Source: json
//------------------------------------------------------------------------------
void __usercall tv_clients(int a1@<edi>, int a2@<esi>)
{
  int v2; // ebx
  CBaseClient *v3; // edi
  INetChannel *(__thiscall *GetNetChannel)(IClient *); // eax
  IClient *v5; // edi
  int v6; // esi
  const char *v7; // ebx
  double v8; // st7
  int v9; // eax
  double v10; // st7
  char *v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // [esp-10h] [ebp-34h]
  const char *v15; // [esp-Ch] [ebp-30h]
  const char *v16; // [esp-8h] [ebp-2Ch]
  const char *v17; // [esp-4h] [ebp-28h]
  double v18; // [esp+0h] [ebp-24h]
  _BYTE v19[12]; // [esp+8h] [ebp-1Ch]
  int v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]

  v2 = 0;
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v22 = 0;
    v21 = 0;
    if ( hltv->GetClientCount(this: &hltv->CBaseServer) > 0 )
    {
      *(_DWORD *)&v19[8] = a1;
      do
      {
        v3 = hltv->m_Clients.m_Memory.m_pMemory[v2];
        GetNetChannel = v3->GetNetChannel;
        v5 = &v3->IClient;
        v6 = (int)GetNetChannel(this: v5);
        if ( v6 != 0 )
        {
          v7 = "(Relay)";
          if ( ((unsigned __int8 (__thiscall *)(IClient *, _DWORD, int))v5->IsHLTV)(
                 a1: v5,
                 a2: *(_DWORD *)&v19[8],
                 a3: a2) == 0 )
            v7 = defaultValue;
          a2 = 0;
          *(double *)&v19[4] = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v6 + 52))(a1: v6) * 0.0009765625;
          v8 = ((double (__thiscall *)(int, int, _DWORD))*(_DWORD *)(*(_DWORD *)v6 + 52))(
                 a1: v6,
                 a2: 1,
                 a3: *(_DWORD *)&v19[4]);
          v9 = (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v6 + 4))(
                 a1: v6,
                 a2: COERCE_UNSIGNED_INT64(v8 * 0.0009765625),
                 a3: HIDWORD(COERCE_UNSIGNED_INT64(v8 * 0.0009765625)));
          v10 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v6 + 12))(a1: v6, a2: v9);
          v11 = COM_FormatSeconds(seconds: (int)v10);
          v12 = ((int (__thiscall *)(IClient *, const char *, char *))v5->GetClientName)(a1: v5, a2: v7, a3: v11);
          v13 = ((int (__thiscall *)(IClient *, int))v5->GetUserID)(a1: v5, a2: v12);
          ConMsg(
            a1: "ID: %i, \"%s\" %s, Time %s, %s, In %.1f, Out %.1f.\n",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            *(double *)v19);
          v2 = v21;
          ++v22;
        }
        v21 = ++v2;
      }
      while ( v2 < hltv->GetClientCount(this: &hltv->CBaseServer) );
    }
    ConMsg(a1: "--- Total %i connected clients ---\n", v22);
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101836E0
// Name: tv_msg
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_msg(const CCommand *args)
{
  IGameEvent *v1; // esi
  int m_nArgv0Size; // eax
  bool v3; // zf
  char *v4; // eax

  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v1 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "hltv_message", a3: 1, a4: 0);
    if ( v1 != nullptr )
    {
      m_nArgv0Size = args->m_nArgv0Size;
      v3 = m_nArgv0Size == 0;
      v4 = &args->m_pArgSBuffer[m_nArgv0Size];
      if ( v3 )
        v4 = (char *)defaultValue;
      v1->SetString(this: v1, a2: "text", a3: v4);
      CHLTVServer::BroadcastEventLocal(this: hltv, event: v1, bReliable: false);
      g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v1);
    }
  }
  else
  {
    ConMsg(a1: "SourceTV not active.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183770
// Name: tv_title_changed_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_title_changed_f()
{
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    CHLTVServer::BroadcastLocalTitle(this: hltv, client: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101837A0
// Name: private: void CHLTVServer::UpdateTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::UpdateTick(CHLTVServer *this)
{
  int m_nLastTick; // edi
  CHLTVFrame *ClientFrame; // eax
  IHLTVServer_vtbl *v4; // edx
  float v5; // xmm0_4

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CHLTVServer::UpdateTick",
    a3: 0,
    a4: "HLTV",
    a5: false,
    a6: 4);
  if ( this->m_nFirstTick >= 0 )
  {
    m_nLastTick = this->m_nLastTick;
    if ( this->IsMasterProxy(this: &this->IHLTVServer) )
    {
      m_nLastTick = this->m_nFirstTick;
      if ( m_nLastTick <= this->m_Director->GetDirectorTick(this: this->m_Director) )
        m_nLastTick = this->m_Director->GetDirectorTick(this: this->m_Director);
    }
    ClientFrame = (CHLTVFrame *)CClientFrameManager::GetClientFrame(
                                  this: &this->CClientFrameManager,
                                  nTick: m_nLastTick,
                                  bExact: false);
    if ( ClientFrame == nullptr || this->m_CurrentFrame == ClientFrame )
    {
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    else
    {
      v4 = this->IHLTVServer::IBaseInterface::__vftable;
      this->m_CurrentFrame = ClientFrame;
      this->m_nTickCount = ClientFrame->tick_count;
      if ( v4->IsMasterProxy(this: &this->IHLTVServer) )
      {
        CHLTVServer::RestoreTick(this, tick: this->m_nTickCount);
        if ( tv_transmitall.m_pParent == nullptr || tv_transmitall.m_pParent->m_Value.m_nValue == 0 )
          CHLTVServer::EntityPVSCheck(this, pFrame: this->m_CurrentFrame);
      }
      else
      {
        CDeltaEntityCache::SetTick(
          this: &this->m_DeltaCache,
          nTick: this->m_CurrentFrame->tick_count,
          nMaxEntities: this->m_CurrentFrame->last_entity + 1);
      }
      v5 = (float)this->m_nTickCount - (float)(16.0 / this->m_flTickInterval);
      if ( (int)v5 > 0 )
        CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: (int)v5);
      this->m_FrameCache.m_Size = 0;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
  }
  else
  {
    this->m_nTickCount = 0;
    this->m_CurrentFrame = nullptr;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183910
// Name: public: virtual void CHLTVServer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::Clear(CHLTVServer *this)
{
  void (__thiscall *v2)(int *); // edx

  CBaseServer::Clear((CBaseServer *)this);
  v2 = *(void (__thiscall **)(int *))(this->m_nDebugID + 44);
  this->m_DemoRecorder.m_MessageData.m_pDebugName = nullptr;
  this->IDemoPlayer::__vftable = nullptr;
  v2(a1: &this->m_nDebugID);
  *(_DWORD *)&this->m_DemoRecorder.m_MessageData.m_bOverflow = 0;
  this->m_Server = (CGameServer *)-1;
  this->m_Director = nullptr;
  this->m_State = ss_dead;
  this->m_nFirstTick = 0;
  this->m_CurrentFrame = nullptr;
  this->m_HLTVFrame.m_Messages[5].m_pDebugName = nullptr;
  this->m_nLastTick = 1;
  this->m_flStartTime = 0.0;
  this->m_flFPS = 0.0;
  CHLTVFrame::FreeBuffers(this: (CHLTVFrame *)&this->m_nViewEntity);
  this->m_pRecvTables[1023] = nullptr;
  this->m_nRecvTables = 0;
  this->m_vPVSOrigin.x = 0.0;
  CClientFrameManager::DeleteClientFrames(
    this: (CClientFrameManager *)&this->m_ReservationStatus.m_Remote.port,
    nTick: -1);
  CDeltaEntityCache::Flush(this: (CDeltaEntityCache *)&this->m_NetworkStringTables.m_Tables.m_Size);
  this->m_FrameCache.m_Memory.m_nAllocationCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10183CC0
// Name: public: virtual CHLTVServer::~CHLTVServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVServer::~CHLTVServer(CHLTVServer *this)
{
  bool v2; // zf
  bool v3; // sf

  v2 = this->m_nRecvTables == 0;
  v3 = this->m_nRecvTables < 0;
  this->IGameEventListener2::__vftable = (CHLTVServer_vtbl *)&CHLTVServer::`vftable'{for `IGameEventListener2'};
  this->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable = (CBaseServer_vtbl *)&CHLTVServer::`vftable'{for `CBaseServer'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CHLTVServer::`vftable'{for `CClientFrameManager'};
  this->IHLTVServer::IBaseInterface::__vftable = (IHLTVServer_vtbl *)&CHLTVServer::`vftable'{for `IHLTVServer'};
  this->IDemoPlayer::__vftable = (IDemoPlayer_vtbl *)&CHLTVServer::`vftable'{for `IDemoPlayer'};
  this->m_nDebugID = 13;
  if ( !v3 && !v2 )
  {
    RecvTable_Term(clearall: true);
    CHLTVServer::FreeClientRecvTables(this);
  }
  CDemoFile::~CDemoFile(this: &this->m_DemoFile);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_FrameCache);
  CDeltaEntityCache::Flush(this: &this->m_DeltaCache);
  CNetworkStringTableContainer::~CNetworkStringTableContainer(this: &this->m_NetworkStringTables);
  this->m_HLTVFrame.__vftable = (CHLTVFrame_vtbl *)&CHLTVFrame::`vftable';
  CHLTVFrame::FreeBuffers(this: &this->m_HLTVFrame);
  CClientFrame::~CClientFrame(this: &this->m_HLTVFrame);
  CHLTVDemoRecorder::~CHLTVDemoRecorder(this: &this->m_DemoRecorder);
  CHLTVClientState::~CHLTVClientState(this: &this->m_ClientState);
  this->IDemoPlayer::__vftable = (IDemoPlayer_vtbl *)&IDemoPlayer::`vftable';
  this->IHLTVServer::IBaseInterface::__vftable = (IHLTVServer_vtbl *)&IBaseInterface::`vftable';
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_ClientFramePool);
  CBaseServer::~CBaseServer(this: &this->CBaseServer);
  this->IGameEventListener2::__vftable = (CHLTVServer_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10183DC0
// Name: public: class CClientFrame __near * CHLTVServer::AddNewFrame(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
CHLTVFrame *__thiscall CHLTVServer::AddNewFrame(CHLTVServer *this, CClientFrame *clientFrame)
{
  int tick_count; // eax
  CSteam3Server *v5; // eax
  CSteam3Server *v6; // eax
  CClientFrame *v7; // eax
  CClientFrame *v8; // ebx
  bf_write *v9; // ebx
  CHLTVFrame *v10; // ebx
  bf_write *m_Messages; // esi
  int j; // edi
  CFrameSnapshot *m_pSnapshot; // [esp-4h] [ebp-18h]
  CClientFrame *frame; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  CHLTVFrame *clientFramea; // [esp+1Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CHLTVServer::AddNewFrame",
    a3: 0,
    a4: "HLTV",
    a5: false,
    a6: 4);
  this->m_nLastTick = clientFrame->tick_count;
  m_pSnapshot = clientFrame->m_pSnapshot;
  clientFramea = &this->m_HLTVFrame;
  CClientFrame::SetSnapshot(this: &this->m_HLTVFrame, pSnapshot: m_pSnapshot);
  this->m_HLTVFrame.tick_count = clientFrame->tick_count;
  this->m_HLTVFrame.last_entity = clientFrame->last_entity;
  memcpy(
    dst: (unsigned __int8 *)&this->m_HLTVFrame.transmit_entity,
    src: (unsigned __int8 *)&clientFrame->transmit_entity,
    count: sizeof(this->m_HLTVFrame.transmit_entity));
  if ( this->m_nFirstTick < 0 )
  {
    tick_count = clientFrame->tick_count;
    this->m_nFirstTick = tick_count;
    this->m_nTickCount = tick_count;
    if ( this->IsMasterProxy(this: &this->IHLTVServer) )
    {
      ConMsg(a1: "SourceTV broadcast active.\n");
    }
    else
    {
      this->m_State = ss_active;
      CBaseServer::ReconnectClients(this: &this->CBaseServer);
      ConMsg(a1: "SourceTV relay active.\n");
      v5 = Steam3Server();
      CSteam3Server::Activate(this: v5);
      v6 = Steam3Server();
      CSteam3Server::SendUpdatedServerDetails(this: v6);
    }
  }
  v7 = (CClientFrame *)MemAlloc_Alloc(nSize: 0x1ACu);
  v8 = v7;
  frame = v7;
  if ( v7 != nullptr )
  {
    CClientFrame::CClientFrame(this: v7);
    v8->__vftable = (CClientFrame_vtbl *)&CHLTVFrame::`vftable';
    v9 = (bf_write *)&v8[1];
    for ( i = 5; i >= 0; --i )
      bf_write::bf_write(this: v9++);
    v10 = (CHLTVFrame *)frame;
  }
  else
  {
    v10 = nullptr;
  }
  CClientFrame::CopyFrame(this: v10, frame: clientFrame);
  CHLTVFrame::CopyHLTVData(this: v10, frame: clientFramea);
  CClientFrameManager::AddClientFrame(this: &this->CClientFrameManager, frame: v10);
  if ( this->IsMasterProxy(this: &this->IHLTVServer) && this->m_DemoRecorder.IsRecording(this: &this->m_DemoRecorder) )
    CHLTVDemoRecorder::WriteFrame(this: &this->m_DemoRecorder, pFrame: clientFramea);
  m_Messages = this->m_HLTVFrame.m_Messages;
  for ( j = 6; j != 0; --j )
    bf_write::Reset(this: m_Messages++);
  CClientFrame::SetSnapshot(this: clientFramea, pSnapshot: nullptr);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10183F80
// Name: public: void CHLTVServer::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVServer::RunFrame(CHLTVServer *this@<ecx>, int a2@<ebx>, CHLTVClientState *p_m_ClientState@<edi>)
{
  CStatTime *v4; // ecx
  long double v5; // st7
  IConnectionlessPacketHandler *v6; // eax
  CSteam3Server *v7; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CHLTVServer::RunFrame",
    a3: 0,
    a4: "HLTV",
    a5: false,
    a6: 4);
  v5 = _Plat_FloatTime(this: v4);
  NET_RunFrame(realtime: v5);
  if ( this->m_ClientState.m_nSignonState > 0 )
  {
    p_m_ClientState = &this->m_ClientState;
    if ( this == (CHLTVServer *)-536 )
      v6 = nullptr;
    else
      v6 = &this->m_ClientState.IConnectionlessPacketHandler;
    NET_ProcessSocket(sock: this->m_ClientState.m_Socket, handler: v6);
    p_m_ClientState->RunFrame(this: &this->m_ClientState);
    CHLTVClientState::SendPacket(this: &this->m_ClientState);
  }
  if ( !this->IsActive(this: &this->CBaseServer) )
    goto LABEL_7;
  if ( host_frametime > 0.0 )
    this->m_flFPS = (float)(this->m_flFPS * 0.99000001) + (float)(0.0099999998 / host_frametime);
  if ( this->IsPlayingBack(this: &this->IDemoPlayer) )
  {
LABEL_7:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CHLTVServer::UpdateTick(this);
    CBaseServer::RunFrame(this: &this->CBaseServer, a2);
    CHLTVServer::UpdateStats(this, a2: (int)p_m_ClientState, a3: (int)this);
    this->SendClientMessages(this: &this->CBaseServer, a2: true);
    if ( sv.m_State < ss_active )
    {
      v7 = Steam3Server();
      CSteam3Server::RunFrame(this: v7);
    }
    CBaseServer::UpdateMasterServer(this: &this->CBaseServer, a2);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101840C0
// Name: tv_relay
// Source: json
//------------------------------------------------------------------------------
void __cdecl tv_relay(const CCommand *args)
{
  int m_nArgv0Size; // eax
  const char *v2; // edi
  CHLTVServer *v3; // eax
  CHLTVServer *v4; // eax
  CBaseServer_vtbl *v5; // esi
  bool IsDedicated; // al

  if ( args->m_nArgc >= 2 )
  {
    m_nArgv0Size = args->m_nArgv0Size;
    v2 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( m_nArgv0Size == 0 )
      v2 = defaultValue;
    if ( V_strncmp(s1: v2, s2: "localhost", count: 9) != 0 )
    {
      if ( hltv == nullptr )
      {
        v3 = (CHLTVServer *)MemAlloc_Alloc(nSize: 0x89C0u);
        if ( v3 != nullptr )
          v4 = CHLTVServer::CHLTVServer(this: v3);
        else
          v4 = nullptr;
        hltv = v4;
        v5 = v4->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable;
        IsDedicated = NET_IsDedicated();
        v5->Init(this: &hltv->CBaseServer, a2: IsDedicated);
      }
      if ( hltv->m_bMasterOnlyMode )
      {
        ConMsg(a1: "SourceTV in Master-Only mode.\n");
      }
      else
      {
        Host_Disconnect(bShowMainMenu: false);
        NET_SetMultiplayer(multiplayer: true);
        CHLTVServer::ConnectRelay(this: hltv, address: v2);
      }
    }
    else
    {
      ConMsg(a1: "SourceTV can't connect to localhost.\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  tv_relay <ip:port>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101841D0
// Name: public: class CClientFrame __near * CHLTVServer::GetDeltaFrame(int)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CHLTVServer::GetDeltaFrame(CHLTVServer *this, int nTick)
{
  CClientFrame *result; // eax
  int m_Size; // ecx
  int v5; // eax
  CFrameCacheEntry_s *v6; // esi
  int *p_nTick; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  CFrameCacheEntry_s *m_pMemory; // ecx
  int v11; // eax
  CFrameCacheEntry_s *v12; // esi

  if ( tv_deltacache.m_pParent == nullptr || tv_deltacache.m_pParent->m_Value.m_nValue == 0 )
    return CClientFrameManager::GetClientFrame(this: &this->CClientFrameManager, nTick, bExact: true);
  m_Size = this->m_FrameCache.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
  {
LABEL_8:
    m_nAllocationCount = this->m_FrameCache.m_Memory.m_nAllocationCount;
    v9 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
        this: (CUtlMemory<ResourceEntryInfo,int> *)&this->m_FrameCache,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_FrameCache.m_Size;
    m_pMemory = this->m_FrameCache.m_Memory.m_pMemory;
    v11 = this->m_FrameCache.m_Size - v9 - 1;
    this->m_FrameCache.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 8 * v11);
    v12 = &this->m_FrameCache.m_Memory.m_pMemory[v9];
    v12->nTick = nTick;
    result = CClientFrameManager::GetClientFrame(this: &this->CClientFrameManager, nTick, bExact: true);
    v12->pFrame = result;
  }
  else
  {
    v6 = this->m_FrameCache.m_Memory.m_pMemory;
    p_nTick = &v6->nTick;
    while ( *p_nTick != nTick )
    {
      ++v5;
      p_nTick += 2;
      if ( v5 >= m_Size )
        goto LABEL_8;
    }
    return v6[v5].pFrame;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029BDC0
// Name: public: virtual int CHLTVServer::GetEventDebugID(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall CHLTVServer::GetEventDebugID(vgui::TextEntry *this)
{
  return this->m_pEditMenu;
}

} // namespace engine_xlsp
