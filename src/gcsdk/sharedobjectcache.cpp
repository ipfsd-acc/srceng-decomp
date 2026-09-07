// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/sharedobjectcache.cpp
// Functions: 17
// ============================================================

#include "gcsdk\sharedobjectcache.h"

//------------------------------------------------------------------------------
// Address: 0x10019CD0
// Name: public: void GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t>::PacketDump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::PacketDump(GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *this)
{
  unsigned int m_cubStruct; // ecx
  unsigned int m_cubMsgHdr; // edx
  unsigned int m_cubPkt; // esi
  unsigned int v5; // eax
  const char *HeaderDescription; // eax
  unsigned int v7; // esi
  unsigned __int8 v8; // bl
  int v9; // esi
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // ebx
  int v14; // esi
  unsigned __int8 v15; // bl
  int v16; // esi
  char szLine[100]; // [esp+Ch] [ebp-8Ch] BYREF
  char szText[32]; // [esp+70h] [ebp-28h] BYREF
  int v19; // [esp+90h] [ebp-8h]
  unsigned int i; // [esp+94h] [ebp-4h]

  m_cubStruct = this->m_cubStruct;
  m_cubMsgHdr = this->m_cubMsgHdr;
  m_cubPkt = this->m_cubPkt;
  if ( m_cubPkt < m_cubMsgHdr + m_cubStruct )
    v5 = 0;
  else
    v5 = m_cubPkt - m_cubMsgHdr - m_cubStruct;
  GCSDK::EmitInfo(
    pchGroupName: SPEW_NETWORK_13,
    iSpewLevel: 5,
    iLevelLog: 1,
    pchMsg: "Packet dump: raw size %u, header size %u, body size %u, var size %u\n",
    m_cubPkt,
    m_cubMsgHdr,
    m_cubStruct,
    v5);
  HeaderDescription = GCSDK::GCMsgHdrEx_t::GetHeaderDescription(this: (GCSDK::GCMsgHdrEx_t *)this->m_pubPkt);
  GCSDK::EmitInfo(
    pchGroupName: SPEW_NETWORK_13,
    iSpewLevel: 5,
    iLevelLog: 1,
    pchMsg: "Header dump: %s\n",
    HeaderDescription);
  GCSDK::EmitInfo(
    pchGroupName: SPEW_NETWORK_13,
    iSpewLevel: 5,
    iLevelLog: 1,
    pchMsg: "Struct dump: %u bytes\n",
    this->m_cubStruct);
  v7 = 0;
  memset(szLine, 0, sizeof(szLine));
  memset(szText, 0, sizeof(szText));
  i = 0;
  if ( this->m_cubStruct != 0 )
  {
    while ( 1 )
    {
      v8 = this->m_pubBody[v7];
      v9 = v7 & 0xF;
      V_snprintf(pDest: &szLine[2 * v9 + v9], maxLen: 8, pFormat: "%02X ", v8);
      if ( v8 <= 0x1Fu || v8 == 37 )
        szText[v9] = 46;
      else
        szText[v9] = v8;
      if ( v9 == 15 || i == this->m_cubStruct - 1 )
      {
        szText[v9 + 1] = 10;
        szText[v9 + 2] = 0;
        V_strncat(pDest: szLine, pSrc: "; ", destBufferSize: 0x64u, max_chars_to_copy: -1);
        V_strncat(pDest: szLine, pSrc: szText, destBufferSize: 0x64u, max_chars_to_copy: -1);
        GCSDK::EmitInfo(pchGroupName: SPEW_NETWORK_13, iSpewLevel: 5, iLevelLog: 1, pchMsg: szLine);
        szLine[0] = 0;
      }
      if ( ++i >= this->m_cubStruct )
        break;
      v7 = i;
    }
  }
  v10 = this->m_cubStruct;
  v11 = this->m_cubMsgHdr;
  v12 = this->m_cubPkt;
  if ( v12 < v11 + v10 )
  {
LABEL_19:
    i = 0;
    goto LABEL_21;
  }
  if ( v12 - v11 - v10 < 0x400 )
  {
    if ( v12 >= v11 + v10 )
    {
      i = v12 - v11 - v10;
      goto LABEL_21;
    }
    goto LABEL_19;
  }
  i = 1024;
LABEL_21:
  v13 = i;
  GCSDK::EmitInfo(pchGroupName: SPEW_NETWORK_13, iSpewLevel: 5, iLevelLog: 1, pchMsg: "VarData dump: %u bytes\n", i);
  v14 = 0;
  v19 = 0;
  if ( v13 != 0 )
  {
    while ( 1 )
    {
      v15 = this->m_pubPkt[this->m_cubMsgHdr + v14 + this->m_cubStruct];
      v16 = v14 & 0xF;
      V_snprintf(pDest: &szLine[2 * v16 + v16], maxLen: 8, pFormat: "%02X ", v15);
      if ( v15 <= 0x1Fu || v15 == 37 )
        szText[v16] = 46;
      else
        szText[v16] = v15;
      if ( v16 == 15 || v19 == i - 1 )
      {
        szText[v16 + 1] = 10;
        szText[v16 + 2] = 0;
        V_strncat(pDest: szLine, pSrc: " ; ", destBufferSize: 0x64u, max_chars_to_copy: -1);
        V_strncat(pDest: szLine, pSrc: szText, destBufferSize: 0x64u, max_chars_to_copy: -1);
        GCSDK::EmitInfo(pchGroupName: SPEW_NETWORK_13, iSpewLevel: 5, iLevelLog: 1, pchMsg: szLine);
        szLine[0] = 0;
      }
      if ( ++v19 >= i )
        break;
      v14 = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A020
// Name: public: void GCSDK::CSharedObjectContext::SOCreated(class GCSDK::CSharedObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CSharedObjectContext::SOCreated(
        GCSDK::CSharedObjectContext *this,
        const GCSDK::CSharedObject *pObject)
{
  int i; // esi
  GCSDK::ISharedObjectListener *v4; // ecx

  for ( i = 0; i < this->m_vecListeners.m_Size; ++i )
  {
    v4 = this->m_vecListeners.m_Memory.m_pMemory[i];
    v4->SOCreated(this: v4, a2: &this->m_steamIDOwner, a3: pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A050
// Name: public: void GCSDK::CSharedObjectContext::SOUpdated(class GCSDK::CSharedObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CSharedObjectContext::SOUpdated(
        GCSDK::CSharedObjectContext *this,
        const GCSDK::CSharedObject *pObject)
{
  int i; // esi
  GCSDK::ISharedObjectListener *v4; // ecx

  for ( i = 0; i < this->m_vecListeners.m_Size; ++i )
  {
    v4 = this->m_vecListeners.m_Memory.m_pMemory[i];
    v4->SOUpdated(this: v4, a2: &this->m_steamIDOwner, a3: pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A090
// Name: private: int GCSDK::CSharedObjectTypeCache::FindSharedObjectIndex(class GCSDK::CSharedObject const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GCSDK::CSharedObjectTypeCache::FindSharedObjectIndex(
        GCSDK::CSharedObjectTypeCache *this,
        const GCSDK::CSharedObject *soIndex)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_vecObjects.m_Size <= 0 )
    return -1;
  while ( !GCSDK::CSharedObject::BIsKeyEqual(this: this->m_vecObjects.m_Memory.m_pMemory[v3], soRHS: soIndex) )
  {
    if ( ++v3 >= this->m_vecObjects.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001A0D0
// Name: public: void GCSDK::CSharedObjectCache::NotifyUnsubscribe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CSharedObjectCache::NotifyUnsubscribe(GCSDK::CSharedObjectCache *this)
{
  int i; // esi
  GCSDK::ISharedObjectListener *v3; // ecx

  for ( i = 0; i < this->m_context.m_vecListeners.m_Size; ++i )
  {
    v3 = this->m_context.m_vecListeners.m_Memory.m_pMemory[i];
    v3->SOCacheUnsubscribed(this: v3, a2: &this->m_context.m_steamIDOwner);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A5F0
// Name: public: void GCSDK::CSharedObjectTypeCache::RemoveObject(class GCSDK::CSharedObject const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CSharedObjectTypeCache::RemoveObject(
        GCSDK::CSharedObjectTypeCache *this,
        const GCSDK::CSharedObject *soIndex)
{
  int v3; // edi
  GCSDK::CSharedObject **m_pMemory; // ecx
  GCSDK::CSharedObject *v5; // ebx
  const GCSDK::CSharedObjectContext *m_context; // esi
  int i; // edi
  GCSDK::ISharedObjectListener *v8; // ecx

  v3 = 0;
  if ( this->m_vecObjects.m_Size > 0 )
  {
    while ( !GCSDK::CSharedObject::BIsKeyEqual(this: this->m_vecObjects.m_Memory.m_pMemory[v3], soRHS: soIndex) )
    {
      if ( ++v3 >= this->m_vecObjects.m_Size )
        return;
    }
    if ( v3 >= 0 && v3 < this->m_vecObjects.m_Size )
    {
      m_pMemory = this->m_vecObjects.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( this->m_vecObjects.m_Size - v3 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v3], src: &m_pMemory[v3 + 1], count: 4 * (this->m_vecObjects.m_Size - v3 - 1));
      --this->m_vecObjects.m_Size;
      m_context = this->m_context;
      for ( i = 0; i < m_context->m_vecListeners.m_Size; ++i )
      {
        v8 = m_context->m_vecListeners.m_Memory.m_pMemory[i];
        v8->SODestroyed(this: v8, a2: &m_context->m_steamIDOwner, a3: v5);
      }
      if ( v5 != nullptr )
        ((void (__thiscall *)(GCSDK::CSharedObject *, int))v5->dtr_CSharedObject)(a1: v5, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A690
// Name: public: class GCSDK::CSharedObject __near * GCSDK::CSharedObjectTypeCache::FindSharedObject(class GCSDK::CSharedObject const __near &)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CSharedObject *__thiscall GCSDK::CSharedObjectTypeCache::FindSharedObject(
        GCSDK::CSharedObjectTypeCache *this,
        const GCSDK::CSharedObject *soIndex)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_vecObjects.m_Size <= 0 )
    return nullptr;
  while ( !GCSDK::CSharedObject::BIsKeyEqual(this: this->m_vecObjects.m_Memory.m_pMemory[v3], soRHS: soIndex) )
  {
    if ( ++v3 >= this->m_vecObjects.m_Size )
      return nullptr;
  }
  if ( v3 < 0 || v3 >= this->m_vecObjects.m_Size )
    return nullptr;
  else
    return this->m_vecObjects.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x1001B1B0
// Name: public: bool GCSDK::CSharedObjectTypeCache::BUpdateFromMsg(class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CSharedObjectTypeCache::BUpdateFromMsg(
        GCSDK::CSharedObjectTypeCache *this,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *pMsg)
{
  const GCSDK::CSharedObject *v3; // edi
  bool result; // al
  const GCSDK::CSharedObject *SharedObject; // esi
  bool bRet; // [esp+Bh] [ebp-1h]

  v3 = GCSDK::CSharedObject::Create(nTypeID: this->m_nTypeID);
  result = v3->BParseKeyFromMessage(this: v3, a2: pMsg);
  if ( result )
  {
    SharedObject = GCSDK::CSharedObjectTypeCache::FindSharedObject(this, soIndex: v3);
    bRet = false;
    if ( SharedObject != nullptr )
    {
      bRet = SharedObject->BParseUpdateFromMessage(this: SharedObject, a2: pMsg);
      GCSDK::CSharedObjectContext::SOUpdated(
        this: (GCSDK::CSharedObjectContext *)this->m_context,
        pObject: SharedObject);
    }
    ((void (__thiscall *)(const GCSDK::CSharedObject *, int))v3->dtr_CSharedObject)(a1: v3, a2: 1);
    return bRet;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B2F0
// Name: public: bool GCSDK::CSharedObjectTypeCache::BCreateFromMsg(class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CSharedObjectTypeCache::BCreateFromMsg(
        GCSDK::CSharedObjectTypeCache *this,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *pMsg)
{
  const GCSDK::CSharedObject *v3; // ebx
  int SharedObjectIndex; // eax
  GCSDK::CSharedObject *v6; // ecx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  GCSDK::CSharedObject **m_pMemory; // ecx
  int v10; // eax
  GCSDK::CSharedObject **v11; // edi

  v3 = GCSDK::CSharedObject::Create(nTypeID: this->m_nTypeID);
  if ( v3 == nullptr )
  {
    GCSDK::EmitError(pchGroupName: SPEW_SHAREDOBJ_13, pchMsg: "Unable to create object of type %d\n", this->m_nTypeID);
    return 0;
  }
  if ( !v3->BParseCreateFromMessage(this: v3, a2: pMsg) )
    return 0;
  SharedObjectIndex = GCSDK::CSharedObjectTypeCache::FindSharedObjectIndex(this, soIndex: v3);
  if ( SharedObjectIndex < 0 || SharedObjectIndex >= this->m_vecObjects.m_Size )
  {
    m_nAllocationCount = this->m_vecObjects.m_Memory.m_nAllocationCount;
    m_Size = this->m_vecObjects.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<GCSDK::CLock *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_vecObjects,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_vecObjects.m_Size;
    m_pMemory = this->m_vecObjects.m_Memory.m_pMemory;
    v10 = this->m_vecObjects.m_Size - m_Size - 1;
    this->m_vecObjects.m_pElements = m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = &this->m_vecObjects.m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = v3;
    GCSDK::CSharedObjectContext::SOCreated(this: (GCSDK::CSharedObjectContext *)this->m_context, pObject: v3);
    return 1;
  }
  else
  {
    v6 = this->m_vecObjects.m_Memory.m_pMemory[SharedObjectIndex];
    v6->Copy(this: v6, a2: v3);
    ((void (__thiscall *)(const GCSDK::CSharedObject *, int))v3->dtr_CSharedObject)(a1: v3, a2: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B3E0
// Name: public: bool GCSDK::CSharedObjectTypeCache::BParseCacheSubscribedMsg(class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CSharedObjectTypeCache::BParseCacheSubscribedMsg(
        GCSDK::CSharedObjectTypeCache *this,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *pMsg)
{
  unsigned __int8 *m_pubPkt; // edx
  unsigned __int8 *m_pubVarRead; // eax
  const char *v4; // eax
  unsigned __int16 v6; // bx
  int v7; // edi

  m_pubPkt = pMsg->m_pubPkt;
  m_pubVarRead = pMsg->m_pubVarRead;
  if ( m_pubVarRead + 2 <= &m_pubPkt[pMsg->m_cubPkt] )
  {
    v6 = *(_WORD *)m_pubVarRead;
    v7 = 0;
    pMsg->m_pubVarRead = m_pubVarRead + 2;
    if ( v6 != 0 )
    {
      while ( GCSDK::CSharedObjectTypeCache::BCreateFromMsg(this, pMsg) != 0 )
      {
        if ( (unsigned __int16)++v7 >= v6 )
          return 1;
      }
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    v4 = GCSDK::PchMsgNameFromEMsg(eMsg: *(_DWORD *)m_pubPkt);
    GCSDK::EmitWarning(
      pchGroupName: SPEW_NETWORK_13,
      iLevel: 1,
      pchMsg: "Read buffer overflowed on incoming %s packet\n",
      v4);
    GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::PacketDump(this: pMsg);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B470
// Name: public: virtual GCSDK::CSharedObjectCache::~CSharedObjectCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CSharedObjectCache::~CSharedObjectCache(GCSDK::CSharedObjectCache *this)
{
  int i; // ebx
  GCSDK::CSharedObjectTypeCache *elem; // ecx
  GCSDK::CSharedObject **m_pMemory; // eax
  GCSDK::CSharedObject **v5; // eax
  GCSDK::ISharedObjectListener **v6; // eax
  CSteamID *v7; // eax

  this->__vftable = (GCSDK::CSharedObjectCache_vtbl *)&GCSDK::CSharedObjectCache::`vftable';
  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapObjects.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_mapObjects.m_Tree,
                                i) )
  {
    elem = this->m_mapObjects.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
    if ( elem != nullptr )
      ((void (__thiscall *)(GCSDK::CSharedObjectTypeCache *, int))elem->dtr_CSharedObjectTypeCache)(a1: elem, a2: 1);
  }
  CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapObjects.m_Tree);
  this->m_mapObjects.m_Tree.m_FirstFree = -1;
  if ( this->m_mapObjects.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_mapObjects.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_mapObjects.m_Tree.m_Elements.m_pMemory);
      this->m_mapObjects.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_mapObjects.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_mapObjects.m_Tree.m_LastAlloc.index = -1;
  this->m_vecDatabaseDirty.m_Size = 0;
  if ( this->m_vecDatabaseDirty.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecDatabaseDirty.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecDatabaseDirty.m_Memory.m_pMemory);
      this->m_vecDatabaseDirty.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecDatabaseDirty.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_vecDatabaseDirty.m_Memory.m_pMemory;
  this->m_vecDatabaseDirty.m_pElements = m_pMemory;
  if ( this->m_vecDatabaseDirty.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_vecDatabaseDirty.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecDatabaseDirty.m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecNetworkDirty.m_Size = 0;
  if ( this->m_vecNetworkDirty.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecNetworkDirty.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecNetworkDirty.m_Memory.m_pMemory);
      this->m_vecNetworkDirty.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecNetworkDirty.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_vecNetworkDirty.m_Memory.m_pMemory;
  this->m_vecNetworkDirty.m_pElements = v5;
  if ( this->m_vecNetworkDirty.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_vecNetworkDirty.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecNetworkDirty.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapObjects.m_Tree);
  this->m_mapObjects.m_Tree.m_FirstFree = -1;
  if ( this->m_mapObjects.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_mapObjects.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_mapObjects.m_Tree.m_Elements.m_pMemory);
      this->m_mapObjects.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_mapObjects.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_mapObjects.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_mapObjects.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_mapObjects.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_mapObjects.m_Tree.m_Elements.m_pMemory);
      this->m_mapObjects.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_mapObjects.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_context.m_vecListeners.m_Size = 0;
  if ( this->m_context.m_vecListeners.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_context.m_vecListeners.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_context.m_vecListeners.m_Memory.m_pMemory);
      this->m_context.m_vecListeners.m_Memory.m_pMemory = nullptr;
    }
    this->m_context.m_vecListeners.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_context.m_vecListeners.m_Memory.m_pMemory;
  this->m_context.m_vecListeners.m_pElements = v6;
  if ( this->m_context.m_vecListeners.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_context.m_vecListeners.m_Memory.m_pMemory = nullptr;
    }
    this->m_context.m_vecListeners.m_Memory.m_nAllocationCount = 0;
  }
  this->m_context.m_vecSubscribers.m_Size = 0;
  if ( this->m_context.m_vecSubscribers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_context.m_vecSubscribers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_context.m_vecSubscribers.m_Memory.m_pMemory);
      this->m_context.m_vecSubscribers.m_Memory.m_pMemory = nullptr;
    }
    this->m_context.m_vecSubscribers.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_context.m_vecSubscribers.m_Memory.m_pMemory;
  this->m_context.m_vecSubscribers.m_pElements = v7;
  if ( this->m_context.m_vecSubscribers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_context.m_vecSubscribers.m_Memory.m_pMemory = nullptr;
    }
    this->m_context.m_vecSubscribers.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B710
// Name: public: GCSDK::CSharedObjectCache::CSharedObjectCache(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CSharedObjectCache *__thiscall GCSDK::CSharedObjectCache::CSharedObjectCache(
        GCSDK::CSharedObjectCache *this,
        const CSteamID *steamIDOwner)
{
  this->__vftable = (GCSDK::CSharedObjectCache_vtbl *)&GCSDK::CSharedObjectCache::`vftable';
  this->m_context.m_vecSubscribers.m_Memory.m_pMemory = nullptr;
  this->m_context.m_vecSubscribers.m_Memory.m_nAllocationCount = 0;
  this->m_context.m_vecSubscribers.m_Memory.m_nGrowSize = 0;
  this->m_context.m_vecSubscribers.m_Size = 0;
  this->m_context.m_vecSubscribers.m_pElements = nullptr;
  this->m_context.m_steamIDOwner = (CSteamID)steamIDOwner->m_steamid.m_comp;
  this->m_context.m_vecListeners.m_Memory.m_pMemory = nullptr;
  this->m_context.m_vecListeners.m_Memory.m_nAllocationCount = 0;
  this->m_context.m_vecListeners.m_Memory.m_nGrowSize = 0;
  this->m_context.m_vecListeners.m_Size = 0;
  this->m_context.m_vecListeners.m_pElements = nullptr;
  this->m_mapObjects.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<enum GCSDK::ESchemaCatalog>::LessFunc;
  this->m_mapObjects.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapObjects.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapObjects.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_mapObjects.m_Tree.m_Root = -1;
  this->m_mapObjects.m_Tree.m_NumElements = 0;
  this->m_mapObjects.m_Tree.m_FirstFree = -1;
  this->m_mapObjects.m_Tree.m_LastAlloc.index = -1;
  this->m_mapObjects.m_Tree.m_pElements = this->m_mapObjects.m_Tree.m_Elements.m_pMemory;
  this->m_vecNetworkDirty.m_Memory.m_pMemory = nullptr;
  this->m_vecNetworkDirty.m_Memory.m_nAllocationCount = 0;
  this->m_vecNetworkDirty.m_Memory.m_nGrowSize = 0;
  this->m_vecNetworkDirty.m_Size = 0;
  this->m_vecNetworkDirty.m_pElements = nullptr;
  this->m_vecDatabaseDirty.m_Memory.m_pMemory = nullptr;
  this->m_vecDatabaseDirty.m_Memory.m_nAllocationCount = 0;
  this->m_vecDatabaseDirty.m_Memory.m_nGrowSize = 0;
  this->m_vecDatabaseDirty.m_Size = 0;
  this->m_vecDatabaseDirty.m_pElements = nullptr;
  *(_WORD *)&this->m_bInitialized = 0;
  this->m_unWritebackTime = 0;
  this->m_unLRUHandle = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001B7E0
// Name: public: class GCSDK::CSharedObjectTypeCache __near * GCSDK::CSharedObjectCache::GetTypeCache(int,bool)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CSharedObjectTypeCache *__thiscall GCSDK::CSharedObjectCache::GetTypeCache(
        GCSDK::CSharedObjectCache *this,
        int nClassID,
        bool bCreateIfMissing)
{
  CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short> *p_m_mapObjects; // ebx
  unsigned __int16 v4; // ax
  int v5; // edi
  GCSDK::CSharedObjectTypeCache *v7; // eax
  GCSDK::CSharedObjectTypeCache *v8; // esi
  GCSDK::CSharedObjectTypeCache *elem; // edx
  CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t insert; // [esp+14h] [ebp-8h] BYREF

  insert.elem = (GCSDK::CSharedObjectTypeCache *)this;
  p_m_mapObjects = &this->m_mapObjects;
  search.key = nClassID;
  v4 = CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapObjects.m_Tree,
         &search);
  v5 = v4;
  if ( v4 < p_m_mapObjects->m_Tree.m_Elements.m_nAllocationCount
    && v4 <= p_m_mapObjects->m_Tree.m_LastAlloc.index
    && CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &p_m_mapObjects->m_Tree,
         i: v4) != v4 )
  {
    return *(GCSDK::CSharedObjectTypeCache **)(insert.elem[1].m_nTypeID + 16 * v5 + 12);
  }
  if ( !bCreateIfMissing )
    return nullptr;
  v7 = (GCSDK::CSharedObjectTypeCache *)operator new(nSize: 0x20u);
  v8 = nullptr;
  if ( v7 != nullptr )
  {
    elem = insert.elem;
    v7->__vftable = (GCSDK::CSharedObjectTypeCache_vtbl *)&GCSDK::CSharedObjectTypeCache::`vftable';
    v7->m_vecObjects.m_Memory.m_pMemory = nullptr;
    v7->m_vecObjects.m_Memory.m_nAllocationCount = 0;
    v7->m_vecObjects.m_Memory.m_nGrowSize = 0;
    v7->m_vecObjects.m_Size = 0;
    v7->m_vecObjects.m_pElements = nullptr;
    v7->m_nTypeID = nClassID;
    v7->m_context = (const GCSDK::CSharedObjectContext *)&elem->m_vecObjects;
    v8 = v7;
  }
  insert.key = nClassID;
  insert.elem = v8;
  CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &p_m_mapObjects->m_Tree,
    &insert);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1001B8B0
// Name: public: bool GCSDK::CSharedObjectCache::BParseCacheSubscribedMsg(unsigned short,class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CSharedObjectCache::BParseCacheSubscribedMsg(
        GCSDK::CSharedObjectCache *this,
        unsigned __int16 cTypeCount,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *pMsg)
{
  int v3; // ebx
  unsigned __int8 *m_pubVarRead; // eax
  unsigned __int8 *v6; // ecx
  int v7; // eax
  GCSDK::CSharedObjectTypeCache *TypeCache; // eax
  int v9; // esi
  GCSDK::ISharedObjectListener *v10; // ecx
  const char *v12; // eax

  v3 = 0;
  if ( cTypeCount != 0 )
  {
    while ( 1 )
    {
      m_pubVarRead = pMsg->m_pubVarRead;
      v6 = m_pubVarRead + 4;
      if ( m_pubVarRead + 4 > &pMsg->m_pubPkt[pMsg->m_cubPkt] )
        break;
      v7 = *(_DWORD *)m_pubVarRead;
      pMsg->m_pubVarRead = v6;
      TypeCache = GCSDK::CSharedObjectCache::GetTypeCache(this, nClassID: v7, bCreateIfMissing: true);
      if ( TypeCache == nullptr || GCSDK::CSharedObjectTypeCache::BParseCacheSubscribedMsg(this: TypeCache, pMsg) == 0 )
        return 0;
      if ( (unsigned __int16)++v3 >= cTypeCount )
        goto LABEL_6;
    }
    v12 = GCSDK::PchMsgNameFromEMsg(eMsg: *(_DWORD *)pMsg->m_pubPkt);
    GCSDK::EmitWarning(
      pchGroupName: SPEW_NETWORK_13,
      iLevel: 1,
      pchMsg: "Read buffer overflowed on incoming %s packet\n",
      v12);
    GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::PacketDump(this: pMsg);
    return 0;
  }
  else
  {
LABEL_6:
    v9 = 0;
    for ( this->m_bInitialized = true; v9 < this->m_context.m_vecListeners.m_Size; ++v9 )
    {
      v10 = this->m_context.m_vecListeners.m_Memory.m_pMemory[v9];
      v10->SOCacheSubscribed(this: v10, a2: &this->m_context.m_steamIDOwner);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B960
// Name: public: bool GCSDK::CSharedObjectCache::BCreateFromMsg(int,class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CSharedObjectCache::BCreateFromMsg(
        GCSDK::CSharedObjectCache *this,
        int nTypeID,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *pMsg)
{
  GCSDK::CSharedObjectTypeCache *TypeCache; // eax

  TypeCache = GCSDK::CSharedObjectCache::GetTypeCache(this, nClassID: nTypeID, bCreateIfMissing: true);
  return GCSDK::CSharedObjectTypeCache::BCreateFromMsg(this: TypeCache, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1001B980
// Name: public: bool GCSDK::CSharedObjectCache::BDestroyFromMsg(int,class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CSharedObjectCache::BDestroyFromMsg(
        GCSDK::CSharedObjectCache *this,
        int nTypeID,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *pMsg)
{
  CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short> *p_m_mapObjects; // ebx
  unsigned __int16 v4; // di
  GCSDK::CSharedObjectTypeCache *elem; // esi
  const GCSDK::CSharedObject *v6; // edi
  CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  GCSDK::CSharedObjectCache *v9; // [esp+14h] [ebp-4h]

  v9 = this;
  p_m_mapObjects = &this->m_mapObjects;
  search.key = nTypeID;
  v4 = CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapObjects.m_Tree,
         &search);
  if ( v4 >= p_m_mapObjects->m_Tree.m_Elements.m_nAllocationCount )
    return 0;
  if ( v4 > p_m_mapObjects->m_Tree.m_LastAlloc.index )
    return 0;
  if ( CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &p_m_mapObjects->m_Tree,
         i: v4) == v4 )
    return 0;
  elem = v9->m_mapObjects.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  if ( elem == nullptr )
    return 0;
  v6 = GCSDK::CSharedObject::Create(nTypeID: elem->m_nTypeID);
  if ( !v6->BParseKeyFromMessage(this: v6, a2: pMsg) )
    return 0;
  GCSDK::CSharedObjectTypeCache::RemoveObject(this: elem, soIndex: v6);
  ((void (__thiscall *)(const GCSDK::CSharedObject *, int))v6->dtr_CSharedObject)(a1: v6, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001BA20
// Name: public: bool GCSDK::CSharedObjectCache::BUpdateFromMsg(int,class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CSharedObjectCache::BUpdateFromMsg(
        GCSDK::CSharedObjectCache *this,
        int nTypeID,
        GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *pMsg)
{
  CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short> *p_m_mapObjects; // ebx
  unsigned __int16 v4; // di
  GCSDK::CSharedObjectTypeCache *elem; // ecx
  CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  GCSDK::CSharedObjectCache *v8; // [esp+14h] [ebp-4h]

  v8 = this;
  p_m_mapObjects = &this->m_mapObjects;
  search.key = nTypeID;
  v4 = CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapObjects.m_Tree,
         &search);
  return v4 < p_m_mapObjects->m_Tree.m_Elements.m_nAllocationCount
      && v4 <= p_m_mapObjects->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObjectTypeCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_mapObjects->m_Tree,
           i: v4) != v4
      && (elem = v8->m_mapObjects.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem) != nullptr
      && GCSDK::CSharedObjectTypeCache::BUpdateFromMsg(this: elem, pMsg);
}
