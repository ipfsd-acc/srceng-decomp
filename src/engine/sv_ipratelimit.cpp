// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_ipratelimit.cpp
// Functions: 3
// ============================================================

#include "engine\sv_ipratelimit.h"

//------------------------------------------------------------------------------
// Address: 0x10122C40
// Name: public: bool CIPRateLimit::CheckIP(struct netadr_s)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPRateLimit::CheckIP(CIPRateLimit *this, netadr_s adr)
{
  double v3; // st7
  bool v4; // cc
  int v5; // ebx
  int Inorder; // edi
  int v7; // eax
  int m_nAllocationCount; // eax
  UtlRBTreeNode_t<CIPRateLimit::iprate_s,int> *v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  unsigned int v13; // edi
  unsigned int v14; // eax
  int *p_count; // ecx
  float m_fValue; // xmm0_4
  UtlRBTreeNode_t<CIPRateLimit::iprate_s,int> *m_pMemory; // ecx
  float v19; // xmm0_4
  CIPRateLimit::iprate_s newEntry; // [esp+Ch] [ebp-24h] BYREF
  CIPRateLimit::iprate_s findEntry; // [esp+18h] [ebp-18h] BYREF
  int curTime; // [esp+24h] [ebp-Ch]
  int clientIP; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  v3 = _Plat_FloatTime((CStatTime *)this);
  v4 = this->m_IPTree.m_NumElements <= 0x400u;
  v5 = (int)v3;
  curTime = (int)v3;
  clientIP = *(_DWORD *)adr.ip;
  if ( !v4 )
  {
    Inorder = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::LastInorder(this: &this->m_IPTree);
    v7 = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::FirstInorder(this: &this->m_IPTree);
    v4 = this->m_IPTree.m_NumElements <= 0x2AAu;
    i = v7;
    if ( !v4 )
    {
      do
      {
        m_nAllocationCount = this->m_IPTree.m_Elements.m_nAllocationCount;
        if ( i >= m_nAllocationCount )
          break;
        if ( Inorder < 0 || Inorder >= m_nAllocationCount || Inorder > this->m_IPTree.m_LastAlloc.index )
          goto LABEL_20;
        if ( (`CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10635F14 = -1;
          dword_10635F18 = -1;
          dword_10635F1C = 1;
        }
        if ( this->m_IPTree.m_Elements.m_pMemory[Inorder].m_Left == Inorder
          || (v9 = &this->m_IPTree.m_Elements.m_pMemory[Inorder], v5 - v9->m_Data.lastTime <= 120)
          || v9->m_Data.ip == clientIP )
        {
LABEL_20:
          ++i;
          Inorder = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::PrevInorder(
                      this: &this->m_IPTree,
                      i: Inorder);
        }
        else
        {
          v10 = Inorder;
          Inorder = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::PrevInorder(
                      this: &this->m_IPTree,
                      i: Inorder);
          CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Unlink(
            this: &this->m_IPTree,
            elem: v10);
          v11 = v10;
          this->m_IPTree.m_Elements.m_pMemory[v11].m_Left = v10;
          this->m_IPTree.m_Elements.m_pMemory[v11].m_Right = this->m_IPTree.m_FirstFree;
          --this->m_IPTree.m_NumElements;
          this->m_IPTree.m_FirstFree = v10;
          v5 = curTime;
        }
      }
      while ( this->m_IPTree.m_NumElements > 0x2AAu );
    }
  }
  findEntry.ip = clientIP;
  findEntry.lastTime = 0;
  findEntry.count = 0;
  v12 = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Find(
          this: &this->m_IPTree,
          search: &findEntry);
  v13 = v12;
  if ( v12 < 0
    || v12 >= this->m_IPTree.m_Elements.m_nAllocationCount
    || v12 > this->m_IPTree.m_LastAlloc.index
    || CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::LeftChild(
         this: &this->m_IPTree,
         i: v12) == v12 )
  {
    newEntry.ip = clientIP;
    newEntry.count = 1;
    newEntry.lastTime = v5;
    CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Insert(
      this: &this->m_IPTree,
      insert: &newEntry);
  }
  else
  {
    v14 = v13;
    p_count = &this->m_IPTree.m_Elements.m_pMemory[v13].m_Data.count;
    ++*p_count;
    m_fValue = sv_max_queries_window.m_pParent->m_Value.m_fValue;
    m_pMemory = this->m_IPTree.m_Elements.m_pMemory;
    if ( (float)(v5 - m_pMemory[v13].m_Data.lastTime) <= m_fValue )
    {
      if ( (float)((float)m_pMemory[v14].m_Data.count / m_fValue) > sv_max_queries_sec.m_pParent->m_Value.m_fValue )
        return false;
    }
    else
    {
      m_pMemory[v14].m_Data.lastTime = v5;
      this->m_IPTree.m_Elements.m_pMemory[v14].m_Data.count = 1;
    }
  }
  ++this->m_iGlobalCount;
  v19 = sv_max_queries_window.m_pParent->m_Value.m_fValue;
  if ( (float)(v5 - this->m_lLastTime) > v19 )
  {
    this->m_lLastTime = v5;
    this->m_iGlobalCount = 1;
    return true;
  }
  return (float)((float)this->m_iGlobalCount / v19) <= sv_max_queries_sec_global.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10122EC0
// Name: bool CheckConnectionLessRateLimits(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CheckConnectionLessRateLimits(netadr_s *adr)
{
  bool v1; // bl
  char *v2; // eax

  v1 = CIPRateLimit::CheckIP(this: &rateChecker, adr: *adr);
  if ( !v1 && sv_logblocks.m_pParent != nullptr && sv_logblocks.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = netadr_s::ToString(this: adr, baseOnly: false);
    CLog::Printf(this: &g_Log, fmt: "Traffic from %s was blocked for exceeding rate limits\n", v2);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101AEF20
// Name: private: static bool CIPRateLimit::LessIP(struct CIPRateLimit::iprate_s const __near &,struct CIPRateLimit::iprate_s const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CIPRateLimit::LessIP(const CKeyBindingsMgr::KBContext_t *lhs, const CKeyBindingsMgr::KBContext_t *rhs)
{
  return lhs->m_Handle < rhs->m_Handle;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10122CE0
// Name: public: bool CIPRateLimit::CheckIP(struct netadr_s)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPRateLimit::CheckIP(CIPRateLimit *this, netadr_s adr)
{
  double v3; // st7
  bool v4; // cc
  int v5; // ebx
  int Inorder; // edi
  int v7; // eax
  int m_nAllocationCount; // eax
  UtlRBTreeNode_t<CIPRateLimit::iprate_s,int> *v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  unsigned int v13; // edi
  unsigned int v14; // eax
  int *p_count; // ecx
  float m_fValue; // xmm0_4
  UtlRBTreeNode_t<CIPRateLimit::iprate_s,int> *m_pMemory; // ecx
  float v19; // xmm0_4
  CIPRateLimit::iprate_s newEntry; // [esp+Ch] [ebp-24h] BYREF
  CIPRateLimit::iprate_s findEntry; // [esp+18h] [ebp-18h] BYREF
  int curTime; // [esp+24h] [ebp-Ch]
  int clientIP; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  v3 = _Plat_FloatTime(a1: this);
  v4 = this->m_IPTree.m_NumElements <= 0x400u;
  v5 = (int)v3;
  curTime = (int)v3;
  clientIP = *(_DWORD *)adr.ip;
  if ( !v4 )
  {
    Inorder = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::LastInorder(this: &this->m_IPTree);
    v7 = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::FirstInorder(this: &this->m_IPTree);
    v4 = this->m_IPTree.m_NumElements <= 0x2AAu;
    i = v7;
    if ( !v4 )
    {
      do
      {
        m_nAllocationCount = this->m_IPTree.m_Elements.m_nAllocationCount;
        if ( i >= m_nAllocationCount )
          break;
        if ( Inorder < 0 || Inorder >= m_nAllocationCount || Inorder > this->m_IPTree.m_LastAlloc.index )
          goto LABEL_20;
        if ( (`CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10635F14 = -1;
          dword_10635F18 = -1;
          dword_10635F1C = 1;
        }
        if ( this->m_IPTree.m_Elements.m_pMemory[Inorder].m_Left == Inorder
          || (v9 = &this->m_IPTree.m_Elements.m_pMemory[Inorder], v5 - v9->m_Data.lastTime <= 120)
          || v9->m_Data.ip == clientIP )
        {
LABEL_20:
          ++i;
          Inorder = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::PrevInorder(
                      this: &this->m_IPTree,
                      i: Inorder);
        }
        else
        {
          v10 = Inorder;
          Inorder = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::PrevInorder(
                      this: &this->m_IPTree,
                      i: Inorder);
          CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Unlink(
            this: &this->m_IPTree,
            elem: v10);
          v11 = v10;
          this->m_IPTree.m_Elements.m_pMemory[v11].m_Left = v10;
          this->m_IPTree.m_Elements.m_pMemory[v11].m_Right = this->m_IPTree.m_FirstFree;
          --this->m_IPTree.m_NumElements;
          this->m_IPTree.m_FirstFree = v10;
          v5 = curTime;
        }
      }
      while ( this->m_IPTree.m_NumElements > 0x2AAu );
    }
  }
  findEntry.ip = clientIP;
  findEntry.lastTime = 0;
  findEntry.count = 0;
  v12 = CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Find(
          this: &this->m_IPTree,
          search: &findEntry);
  v13 = v12;
  if ( v12 < 0
    || v12 >= this->m_IPTree.m_Elements.m_nAllocationCount
    || v12 > this->m_IPTree.m_LastAlloc.index
    || CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::LeftChild(
         this: &this->m_IPTree,
         i: v12) == v12 )
  {
    newEntry.ip = clientIP;
    newEntry.count = 1;
    newEntry.lastTime = v5;
    CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::Insert(
      this: &this->m_IPTree,
      insert: &newEntry);
  }
  else
  {
    v14 = v13;
    p_count = &this->m_IPTree.m_Elements.m_pMemory[v13].m_Data.count;
    ++*p_count;
    m_fValue = sv_max_queries_window.m_pParent->m_Value.m_fValue;
    m_pMemory = this->m_IPTree.m_Elements.m_pMemory;
    if ( (float)(v5 - m_pMemory[v13].m_Data.lastTime) <= m_fValue )
    {
      if ( (float)((float)m_pMemory[v14].m_Data.count / m_fValue) > sv_max_queries_sec.m_pParent->m_Value.m_fValue )
        return false;
    }
    else
    {
      m_pMemory[v14].m_Data.lastTime = v5;
      this->m_IPTree.m_Elements.m_pMemory[v14].m_Data.count = 1;
    }
  }
  ++this->m_iGlobalCount;
  v19 = sv_max_queries_window.m_pParent->m_Value.m_fValue;
  if ( (float)(v5 - this->m_lLastTime) > v19 )
  {
    this->m_lLastTime = v5;
    this->m_iGlobalCount = 1;
    return true;
  }
  return (float)((float)this->m_iGlobalCount / v19) <= sv_max_queries_sec_global.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10122F60
// Name: bool CheckConnectionLessRateLimits(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CheckConnectionLessRateLimits(netadr_s *adr)
{
  bool v1; // bl
  const char *v2; // eax

  v1 = CIPRateLimit::CheckIP(this: &rateChecker, adr: *adr);
  if ( !v1 && sv_logblocks.m_pParent != nullptr && sv_logblocks.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = netadr_s::ToString(this: adr, baseOnly: false);
    CLog::Printf(this: &g_Log, fmt: "Traffic from %s was blocked for exceeding rate limits\n", v2);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101A6DF0
// Name: private: static bool CIPRateLimit::LessIP(struct CIPRateLimit::iprate_s const __near &,struct CIPRateLimit::iprate_s const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CIPRateLimit::LessIP(const CKeyBindingsMgr::KBContext_t *lhs, const CKeyBindingsMgr::KBContext_t *rhs)
{
  return lhs->m_Handle < rhs->m_Handle;
}

} // namespace engine_xlsp
