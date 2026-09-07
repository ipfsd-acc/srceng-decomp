// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/coroutine.cpp
// Functions: 19
// ============================================================

#include "vstdlib\coroutine.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: class CGaussianRandomStream __near & CGaussianRandomStream::operator=(class CGaussianRandomStream const __near &)
// Source: json
//------------------------------------------------------------------------------
CGaussianRandomStream *__thiscall CGaussianRandomStream::operator=(
        CGaussianRandomStream *this,
        const CGaussianRandomStream *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001090
// Name: public: class CUniformRandomStream __near & CUniformRandomStream::operator=(class CUniformRandomStream const __near &)
// Source: json
//------------------------------------------------------------------------------
CUniformRandomStream *__thiscall CUniformRandomStream::operator=(
        CUniformRandomStream *this,
        const CUniformRandomStream *__that)
{
  CUniformRandomStream *result; // eax
  int *m_iv; // edx
  int v4; // ecx
  int i; // esi

  result = this;
  this->m_idum = __that->m_idum;
  this->m_iy = __that->m_iy;
  m_iv = this->m_iv;
  v4 = (char *)__that - (char *)this;
  for ( i = 32; i != 0; --i )
  {
    *m_iv = *(int *)((char *)m_iv + v4);
    ++m_iv;
  }
  result->m_mutex = __that->m_mutex;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001170
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CCoroutineMgr *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CCoroutineMgr **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CCoroutineMgr **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CCoroutineMgr **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100014A0
// Name: public: void CCoroutineMgr::DeleteCoroutine(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoroutineMgr::DeleteCoroutine(CCoroutineMgr *this, int hCoroutine)
{
  CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> > *p_m_ListCoroutines; // edi
  int v3; // esi

  p_m_ListCoroutines = &this->m_ListCoroutines;
  CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::Unlink(
    this: &this->m_ListCoroutines,
    elem: hCoroutine);
  v3 = (int)&p_m_ListCoroutines->m_Memory.m_pMemory[hCoroutine];
  if ( *(_DWORD *)(v3 + 72) != 0 )
    free(pMem: *(void **)(v3 + 72));
  *(_DWORD *)(v3 + 100) = p_m_ListCoroutines->m_FirstFree;
  p_m_ListCoroutines->m_FirstFree = hCoroutine;
}

//------------------------------------------------------------------------------
// Address: 0x10001560
// Name: public: CCoroutineMgr::CCoroutineMgr(void)
// Source: json
//------------------------------------------------------------------------------
CCoroutineMgr *__thiscall CCoroutineMgr::CCoroutineMgr(CCoroutineMgr *this)
{
  CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> > *p_m_ListCoroutines; // esi
  UtlLinkedListElem_t<CCoroutine,int> *m_pMemory; // eax
  CUtlMemory<CCoroutineMgr *,int> *p_m_VecCoroutineStack; // edi
  CCoroutineMgr **v4; // esi
  int m_nAllocationCount; // eax
  CCoroutineMgr **v6; // ecx
  int v7; // eax
  int *v8; // esi
  CCoroutineMgr *result; // eax
  int hMainCoroutine; // [esp+Ch] [ebp-8h]

  this->m_ListCoroutines.m_Memory.m_pMemory = nullptr;
  this->m_ListCoroutines.m_Memory.m_nAllocationCount = 0;
  this->m_ListCoroutines.m_Memory.m_nGrowSize = 0;
  this->m_ListCoroutines.m_LastAlloc.index = -1;
  p_m_ListCoroutines = &this->m_ListCoroutines;
  this->m_ListCoroutines.m_Head = -1;
  this->m_ListCoroutines.m_Tail = -1;
  this->m_ListCoroutines.m_FirstFree = -1;
  m_pMemory = this->m_ListCoroutines.m_Memory.m_pMemory;
  this->m_ListCoroutines.m_ElementCount = 0;
  this->m_ListCoroutines.m_NumAlloced = 0;
  this->m_ListCoroutines.m_pElements = m_pMemory;
  p_m_VecCoroutineStack = (CUtlMemory<CCoroutineMgr *,int> *)&this->m_VecCoroutineStack;
  this->m_VecCoroutineStack.m_Memory.m_pMemory = nullptr;
  this->m_VecCoroutineStack.m_Memory.m_nAllocationCount = 0;
  this->m_VecCoroutineStack.m_Memory.m_nGrowSize = 0;
  this->m_VecCoroutineStack.m_Size = 0;
  this->m_VecCoroutineStack.m_pElements = nullptr;
  this->m_topofexceptionchain = 0;
  hMainCoroutine = CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::AddToTail(this: &this->m_ListCoroutines);
  p_m_ListCoroutines->m_Memory.m_pMemory[hMainCoroutine].m_Element.m_pchName = "(main)";
  v4 = p_m_VecCoroutineStack[1].m_pMemory;
  m_nAllocationCount = p_m_VecCoroutineStack->m_nAllocationCount;
  if ( (int)v4 + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: p_m_VecCoroutineStack, num: (int)v4 - m_nAllocationCount + 1);
  ++p_m_VecCoroutineStack[1].m_pMemory;
  v6 = p_m_VecCoroutineStack->m_pMemory;
  v7 = (char *)p_m_VecCoroutineStack[1].m_pMemory - (char *)v4 - 1;
  p_m_VecCoroutineStack[1].m_nAllocationCount = (int)p_m_VecCoroutineStack->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &v6[(_DWORD)v4 + 1], src: &v6[(_DWORD)v4], count: 4 * v7);
  v8 = (int *)&p_m_VecCoroutineStack->m_pMemory[(_DWORD)v4];
  result = this;
  if ( v8 != nullptr )
    *v8 = hMainCoroutine;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001620
// Name: class CCoroutineMgr __near & GCoroutineMgr(void)
// Source: json
//------------------------------------------------------------------------------
CCoroutineMgr *__cdecl GCoroutineMgr()
{
  CCoroutineMgr *v0; // eax
  CCoroutineMgr *v1; // eax
  CCoroutineMgr *v2; // edi
  int m_Size; // eax
  int v4; // esi
  CCoroutineMgr **m_pMemory; // ecx
  int v6; // eax
  CCoroutineMgr **v7; // eax

  if ( GenericThreadLocals::CThreadLocalBase::Get(this: &g_ThreadLocalCoroutineMgr) == nullptr )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadMutexCoroutineMgr);
    v0 = (CCoroutineMgr *)operator new(nSize: 0x40u);
    if ( v0 != nullptr )
      v1 = CCoroutineMgr::CCoroutineMgr(this: v0);
    else
      v1 = nullptr;
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_ThreadLocalCoroutineMgr, a2: v1);
    v2 = (CCoroutineMgr *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_ThreadLocalCoroutineMgr);
    m_Size = g_VecPCoroutineMgr.m_Size;
    v4 = g_VecPCoroutineMgr.m_Size;
    if ( g_VecPCoroutineMgr.m_Size + 1 > g_VecPCoroutineMgr.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<int,int>::Grow(
        this: &g_VecPCoroutineMgr.m_Memory,
        num: g_VecPCoroutineMgr.m_Size - g_VecPCoroutineMgr.m_Memory.m_nAllocationCount + 1);
      m_Size = g_VecPCoroutineMgr.m_Size;
    }
    m_pMemory = g_VecPCoroutineMgr.m_Memory.m_pMemory;
    g_VecPCoroutineMgr.m_Size = m_Size + 1;
    v6 = m_Size - v4;
    g_VecPCoroutineMgr.m_pElements = g_VecPCoroutineMgr.m_Memory.m_pMemory;
    if ( v6 > 0 )
    {
      _V_memmove(
        dest: &g_VecPCoroutineMgr.m_Memory.m_pMemory[v4 + 1],
        src: &g_VecPCoroutineMgr.m_Memory.m_pMemory[v4],
        count: 4 * v6);
      m_pMemory = g_VecPCoroutineMgr.m_Memory.m_pMemory;
    }
    v7 = &m_pMemory[v4];
    if ( v7 != nullptr )
      *v7 = v2;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadMutexCoroutineMgr);
  }
  return (CCoroutineMgr *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_ThreadLocalCoroutineMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100016F0
// Name: _Coroutine_ReleaseThreadMemory
// Source: json
//------------------------------------------------------------------------------
void Coroutine_ReleaseThreadMemory()
{
  CCoroutineMgr *v0; // eax
  int m_Size; // edx
  CCoroutineMgr **m_pMemory; // esi
  int v3; // ecx
  int v4; // ebx
  CCoroutineMgr *v5; // edi

  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadMutexCoroutineMgr);
  if ( GenericThreadLocals::CThreadLocalBase::Get(this: &g_ThreadLocalCoroutineMgr) != nullptr )
  {
    v0 = (CCoroutineMgr *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_ThreadLocalCoroutineMgr);
    m_Size = g_VecPCoroutineMgr.m_Size;
    m_pMemory = g_VecPCoroutineMgr.m_Memory.m_pMemory;
    v3 = 0;
    if ( g_VecPCoroutineMgr.m_Size <= 0 )
    {
LABEL_5:
      v4 = -1;
    }
    else
    {
      while ( g_VecPCoroutineMgr.m_Memory.m_pMemory[v3] != v0 )
      {
        if ( ++v3 >= g_VecPCoroutineMgr.m_Size )
          goto LABEL_5;
      }
      v4 = v3;
    }
    v5 = g_VecPCoroutineMgr.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *,int> > *)&v5->m_VecCoroutineStack);
      CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::RemoveAll(this: &v5->m_ListCoroutines);
      if ( v5->m_ListCoroutines.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5->m_ListCoroutines.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_ListCoroutines.m_Memory.m_pMemory);
          v5->m_ListCoroutines.m_Memory.m_pMemory = nullptr;
        }
        v5->m_ListCoroutines.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v5);
      m_Size = g_VecPCoroutineMgr.m_Size;
      m_pMemory = g_VecPCoroutineMgr.m_Memory.m_pMemory;
    }
    if ( m_Size - v4 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * (m_Size - v4 - 1));
      m_Size = g_VecPCoroutineMgr.m_Size;
    }
    g_VecPCoroutineMgr.m_Size = m_Size - 1;
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadMutexCoroutineMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100017E0
// Name: _Coroutine_Create
// Source: json
//------------------------------------------------------------------------------
int __cdecl Coroutine_Create(void (__cdecl *pFunc)(void *), void *pvParam)
{
  CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> > *p_m_ListCoroutines; // esi
  int result; // eax
  int v4; // ecx

  p_m_ListCoroutines = &GCoroutineMgr()->m_ListCoroutines;
  result = CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::AddToTail(this: p_m_ListCoroutines);
  v4 = result;
  p_m_ListCoroutines->m_Memory.m_pMemory[v4].m_Element.m_pFunc = pFunc;
  p_m_ListCoroutines->m_Memory.m_pMemory[v4].m_Element.m_pvParam = pvParam;
  p_m_ListCoroutines->m_Memory.m_pMemory[v4].m_Element.m_pSavedStack = nullptr;
  p_m_ListCoroutines->m_Memory.m_pMemory[v4].m_Element.m_cubSavedStack = 0;
  p_m_ListCoroutines->m_Memory.m_pMemory[v4].m_Element.m_pStackLow = nullptr;
  p_m_ListCoroutines->m_Memory.m_pMemory[v4].m_Element.m_pStackHigh = nullptr;
  p_m_ListCoroutines->m_Memory.m_pMemory[v4].m_Element.m_pchName = "(no name set)";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001840
// Name: _Coroutine_Cancel
// Source: json
//------------------------------------------------------------------------------
void __cdecl Coroutine_Cancel(int hCoroutine)
{
  CCoroutineMgr *v1; // edi
  int v2; // esi

  v1 = GCoroutineMgr();
  CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::Unlink(
    this: &v1->m_ListCoroutines,
    elem: hCoroutine);
  v2 = (int)&v1->m_ListCoroutines.m_Memory.m_pMemory[hCoroutine];
  if ( *(_DWORD *)(v2 + 72) != 0 )
    free(pMem: *(void **)(v2 + 72));
  *(_DWORD *)(v2 + 100) = v1->m_ListCoroutines.m_FirstFree;
  v1->m_ListCoroutines.m_FirstFree = hCoroutine;
}

//------------------------------------------------------------------------------
// Address: 0x10001880
// Name: _Coroutine_IsActive
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Coroutine_IsActive()
{
  return GCoroutineMgr()->m_VecCoroutineStack.m_Size > 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: _Coroutine_GetCurrentlyActive
// Source: json
//------------------------------------------------------------------------------
int __cdecl Coroutine_GetCurrentlyActive()
{
  CCoroutineMgr *v0; // eax

  v0 = GCoroutineMgr();
  return v0->m_VecCoroutineStack.m_Memory.m_pMemory[v0->m_VecCoroutineStack.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x100018A0
// Name: _Coroutine_YieldToMain
// Source: json
//------------------------------------------------------------------------------
int Coroutine_YieldToMain()
{
  CCoroutineMgr *v0; // ecx
  int m_Size; // eax
  int *m_pMemory; // edx
  int v3; // edi
  UtlLinkedListElem_t<CCoroutine,int> *v4; // esi
  CCoroutine *p_m_Element; // edx
  int result; // eax
  CCoroutine *v7; // esi
  unsigned __int8 *v8; // eax
  CCoroutine *v9; // esi
  void *v10; // esp
  CCoroutineMgr *v11; // eax
  unsigned int v12; // [esp-4h] [ebp-24h]
  _DWORD v13[2]; // [esp+0h] [ebp-20h] BYREF
  _DWORD *v14; // [esp+8h] [ebp-18h]
  CCoroutine *coroutinePrev; // [esp+Ch] [ebp-14h]
  CCoroutine *coroutine; // [esp+10h] [ebp-10h]
  _DWORD *v17; // [esp+14h] [ebp-Ch]
  unsigned __int8 *pStackPtr; // [esp+18h] [ebp-8h]
  unsigned int topofexceptionchain; // [esp+1Ch] [ebp-4h]

  v0 = GCoroutineMgr();
  m_Size = v0->m_VecCoroutineStack.m_Size;
  m_pMemory = v0->m_VecCoroutineStack.m_Memory.m_pMemory;
  v3 = m_pMemory[m_Size - 2];
  v4 = v0->m_ListCoroutines.m_Memory.m_pMemory;
  p_m_Element = &v4[m_pMemory[m_Size - 1]].m_Element;
  coroutinePrev = &v4[v3].m_Element;
  coroutine = p_m_Element;
  topofexceptionchain = (unsigned int)NtCurrentTeb()->NtTib.ExceptionList;
  if ( v0->m_topofexceptionchain == 0 )
    v0->m_topofexceptionchain = topofexceptionchain;
  result = _setjmp3(a1: p_m_Element, a2: 0, a3: v13[0], a4: v13[1], a5: (char)v14);
  if ( result == 0 || result == 3 )
  {
    if ( result == 3 && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
      __debugbreak();
    v7 = coroutine;
    if ( coroutine->m_pSavedStack != nullptr )
      free(pMem: coroutine->m_pSavedStack);
    v17 = v13;
    coroutine->m_pStackLow = (unsigned __int8 *)v13;
    v12 = v7->m_pStackHigh - (unsigned __int8 *)v13;
    v7->m_cubSavedStack = v12;
    v8 = (unsigned __int8 *)operator new(nSize: v12);
    v7->m_pSavedStack = v8;
    memcpy(dst: v8, src: v7->m_pStackLow, count: v7->m_cubSavedStack);
    pStackPtr = (unsigned __int8 *)v13;
    v9 = coroutinePrev;
    if ( (unsigned __int8 *)v13 >= &coroutinePrev->m_pStackHigh[-coroutinePrev->m_cubSavedStack]
      && (unsigned __int8 *)v13 <= coroutinePrev->m_pStackHigh )
    {
      v10 = alloca(coroutinePrev->m_cubSavedStack);
    }
    if ( coroutinePrev->m_cubSavedStack != 0 )
    {
      v14 = v13;
      memcpy(dst: coroutinePrev->m_pStackLow, src: coroutinePrev->m_pSavedStack, count: coroutinePrev->m_cubSavedStack);
      v9->m_cubSavedStack = 0;
      free(pMem: v9->m_pSavedStack);
      v9->m_pSavedStack = nullptr;
      if ( v9->m_pFunc == nullptr )
      {
        v9->m_pStackHigh = nullptr;
        v9->m_pStackLow = nullptr;
      }
    }
    v11 = GCoroutineMgr();
    longjmp(
      Buf: v11->m_ListCoroutines.m_Memory.m_pMemory[v11->m_VecCoroutineStack.m_Memory.m_pMemory[v11->m_VecCoroutineStack.m_Size
                                                                                         - 2]].m_Element.m_Registers,
      Value: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: void Coroutine_Finish(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Coroutine_Finish()
{
  CCoroutineMgr *v0; // eax
  void *v1; // esp
  CCoroutineMgr *v2; // eax
  int v3; // esi
  CCoroutineMgr *v4; // eax
  void *v5; // [esp-10h] [ebp-1Ch]
  _DWORD v6[3]; // [esp+0h] [ebp-Ch] BYREF

  v0 = GCoroutineMgr();
  v1 = alloca(v0->m_ListCoroutines.m_Memory.m_pMemory[v0->m_VecCoroutineStack.m_Memory.m_pMemory[v0->m_VecCoroutineStack.m_Size
                                                                                               - 2]].m_Element.m_cubSavedStack);
  v2 = GCoroutineMgr();
  v3 = (int)&v2->m_ListCoroutines.m_Memory.m_pMemory[v2->m_VecCoroutineStack.m_Memory.m_pMemory[v2->m_VecCoroutineStack.m_Size
                                                                                              - 2]];
  if ( *(_DWORD *)(v3 + 76) != 0 )
  {
    v6[2] = v6;
    memcpy(dst: *(unsigned __int8 **)(v3 + 68), src: *(unsigned __int8 **)(v3 + 72), count: *(_DWORD *)(v3 + 76));
    v5 = *(void **)(v3 + 72);
    *(_DWORD *)(v3 + 76) = 0;
    free(pMem: v5);
    *(_DWORD *)(v3 + 72) = 0;
    if ( *(_DWORD *)(v3 + 88) == 0 )
    {
      *(_DWORD *)(v3 + 64) = 0;
      *(_DWORD *)(v3 + 68) = 0;
    }
  }
  v4 = GCoroutineMgr();
  longjmp(
    Buf: v4->m_ListCoroutines.m_Memory.m_pMemory[v4->m_VecCoroutineStack.m_Memory.m_pMemory[v4->m_VecCoroutineStack.m_Size
                                                                                     - 2]].m_Element.m_Registers,
    Value: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10001A70
// Name: _Coroutine_GetStackDepth
// Source: json
//------------------------------------------------------------------------------
int __cdecl Coroutine_GetStackDepth()
{
  CCoroutineMgr *v1; // eax
  unsigned __int8 *pLocal; // [esp+0h] [ebp-4h] BYREF

  if ( GCoroutineMgr()->m_VecCoroutineStack.m_Size <= 1 )
    return 0;
  pLocal = (unsigned __int8 *)&pLocal;
  v1 = GCoroutineMgr();
  return v1->m_ListCoroutines.m_Memory.m_pMemory[v1->m_VecCoroutineStack.m_Memory.m_pMemory[v1->m_VecCoroutineStack.m_Size
                                                                                          - 1]].m_Element.m_pStackHigh
       - pLocal;
}

//------------------------------------------------------------------------------
// Address: 0x10001AB0
// Name: void Coroutine_Launch(class CCoroutine __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Coroutine_Launch(CCoroutine *coroutine)
{
  void *m_pvParam; // edx
  unsigned __int8 *pEsp; // [esp+0h] [ebp-4h] BYREF

  pEsp = (unsigned __int8 *)&pEsp;
  m_pvParam = coroutine->m_pvParam;
  coroutine->m_pStackHigh = (unsigned __int8 *)&pEsp;
  coroutine->m_pFunc(a1: m_pvParam);
  Coroutine_Finish();
}

//------------------------------------------------------------------------------
// Address: 0x10001AE0
// Name: bool Internal_Coroutine_Continue(int,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Internal_Coroutine_Continue(int hCoroutine, bool bDebugBreak, const char *pchName)
{
  CCoroutineMgr *v3; // edi
  bool v4; // zf
  bool v5; // sf
  bool v6; // of
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v9; // ebx
  int v10; // ecx
  int *m_pMemory; // esi
  UtlLinkedListElem_t<CCoroutine,int> *v12; // edx
  CCoroutine *p_m_Element; // eax
  CCoroutine *v14; // ecx
  int v15; // eax
  CCoroutine *v16; // edi
  unsigned __int8 *v17; // eax
  CCoroutine *v18; // esi
  unsigned __int8 *v19; // eax
  unsigned __int8 *m_pStackLow; // ecx
  void *v21; // esp
  CCoroutineMgr *v22; // eax
  int v23; // esi
  CCoroutineMgr *v24; // eax
  void *v25; // esp
  CCoroutineMgr *v26; // eax
  unsigned int v28; // [esp-4h] [ebp-30h]
  _DWORD v29[3]; // [esp+0h] [ebp-2Ch] BYREF
  CCoroutineMgr *coroutineMgr; // [esp+Ch] [ebp-20h]
  _DWORD *v31; // [esp+10h] [ebp-1Ch]
  CCoroutine *coroutinePrev; // [esp+14h] [ebp-18h]
  CCoroutine *coroutine; // [esp+18h] [ebp-14h]
  _DWORD *v34; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *pStackSavePoint; // [esp+20h] [ebp-Ch]
  unsigned int topofexceptionchain; // [esp+24h] [ebp-8h]
  bool bInCoroutineAlready; // [esp+2Ah] [ebp-2h]
  bool bStillRunning; // [esp+2Bh] [ebp-1h]

  v3 = GCoroutineMgr();
  v6 = __OFSUB__(v3->m_VecCoroutineStack.m_Size, 1);
  v4 = v3->m_VecCoroutineStack.m_Size == 1;
  v5 = v3->m_VecCoroutineStack.m_Size - 1 < 0;
  coroutineMgr = v3;
  bInCoroutineAlready = !(v5 ^ v6 | v4);
  topofexceptionchain = (unsigned int)NtCurrentTeb()->NtTib.ExceptionList;
  if ( v3->m_topofexceptionchain == 0 )
    v3->m_topofexceptionchain = topofexceptionchain;
  m_Size = v3->m_VecCoroutineStack.m_Size;
  m_nAllocationCount = v3->m_VecCoroutineStack.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CCoroutineMgr *,int> *)&v3->m_VecCoroutineStack,
      num: m_Size - m_nAllocationCount + 1);
  ++v3->m_VecCoroutineStack.m_Size;
  v3->m_VecCoroutineStack.m_pElements = v3->m_VecCoroutineStack.m_Memory.m_pMemory;
  if ( v3->m_VecCoroutineStack.m_Size - m_Size - 1 > 0 )
    _V_memmove(
      dest: &v3->m_VecCoroutineStack.m_Memory.m_pMemory[m_Size + 1],
      src: &v3->m_VecCoroutineStack.m_Memory.m_pMemory[m_Size],
      count: 4 * (v3->m_VecCoroutineStack.m_Size - m_Size - 1));
  v9 = &v3->m_VecCoroutineStack.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = hCoroutine;
  v10 = v3->m_VecCoroutineStack.m_Size;
  m_pMemory = v3->m_VecCoroutineStack.m_Memory.m_pMemory;
  v12 = v3->m_ListCoroutines.m_Memory.m_pMemory;
  p_m_Element = &v12[m_pMemory[v10 - 2]].m_Element;
  v14 = &v12[m_pMemory[v10 - 1]].m_Element;
  coroutinePrev = p_m_Element;
  coroutine = v14;
  if ( pchName != nullptr )
    v14->m_pchName = pchName;
  bStillRunning = true;
  v15 = _setjmp3(a1: p_m_Element, a2: 0, a3: v29[0], a4: v29[1], a5: v29[2]);
  if ( v15 == 0 )
  {
    v16 = coroutine;
    if ( coroutine->m_pSavedStack != nullptr )
    {
      pStackSavePoint = (unsigned __int8 *)v29;
      v17 = (unsigned __int8 *)v29;
      if ( (unsigned __int8 *)v29 <= coroutine->m_pStackHigh )
      {
        v18 = coroutinePrev;
        if ( coroutinePrev->m_pStackHigh == nullptr )
          coroutinePrev->m_pStackHigh = coroutine->m_pStackHigh;
        if ( v18->m_pSavedStack != nullptr )
          free(pMem: v18->m_pSavedStack);
        v34 = v29;
        v18->m_pStackLow = (unsigned __int8 *)v29;
        v28 = v18->m_pStackHigh - (unsigned __int8 *)v29;
        v18->m_cubSavedStack = v28;
        v19 = (unsigned __int8 *)operator new(nSize: v28);
        v18->m_pSavedStack = v19;
        memcpy(dst: v19, src: v18->m_pStackLow, count: v18->m_cubSavedStack);
        v17 = pStackSavePoint;
      }
      if ( v16->m_pStackHigh > v17 - 2048 )
      {
        m_pStackLow = v16->m_pStackLow;
        if ( m_pStackLow < v17 )
          v21 = alloca(v17 - m_pStackLow + 256);
      }
      v16->m_iJumpCode = 2 * bDebugBreak + 1;
      if ( v16->m_cubSavedStack != 0 )
      {
        v31 = v29;
        memcpy(dst: v16->m_pStackLow, src: v16->m_pSavedStack, count: v16->m_cubSavedStack);
        v16->m_cubSavedStack = 0;
        free(pMem: v16->m_pSavedStack);
        v16->m_pSavedStack = nullptr;
        if ( v16->m_pFunc == nullptr )
        {
          v16->m_pStackHigh = nullptr;
          v16->m_pStackLow = nullptr;
        }
      }
      v22 = GCoroutineMgr();
      v23 = (int)&v22->m_ListCoroutines.m_Memory.m_pMemory[v22->m_VecCoroutineStack.m_Memory.m_pMemory[v22->m_VecCoroutineStack.m_Size - 1]];
      v24 = GCoroutineMgr();
      longjmp(
        Buf: v24->m_ListCoroutines.m_Memory.m_pMemory[v24->m_VecCoroutineStack.m_Memory.m_pMemory[v24->m_VecCoroutineStack.m_Size
                                                                                           - 1]].m_Element.m_Registers,
        Value: *(_DWORD *)(v23 + 84));
    }
    v25 = alloca(bInCoroutineAlready ? 64 : 0x10000);
    Coroutine_Launch(coroutine);
  }
  if ( v15 == 2 )
  {
    v26 = GCoroutineMgr();
    CCoroutineMgr::DeleteCoroutine(
      this: coroutineMgr,
      hCoroutine: v26->m_VecCoroutineStack.m_Memory.m_pMemory[v26->m_VecCoroutineStack.m_Size - 1]);
    bStillRunning = false;
  }
  --coroutineMgr->m_VecCoroutineStack.m_Size;
  return bStillRunning;
}

//------------------------------------------------------------------------------
// Address: 0x10001D30
// Name: _Coroutine_Continue
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Coroutine_Continue(int hCoroutine, const char *pchName)
{
  return Internal_Coroutine_Continue(hCoroutine, bDebugBreak: false, pchName);
}

//------------------------------------------------------------------------------
// Address: 0x10001D50
// Name: _Coroutine_DebugBreak
// Source: json
//------------------------------------------------------------------------------
void __cdecl Coroutine_DebugBreak(int hCoroutine)
{
  Internal_Coroutine_Continue(hCoroutine, bDebugBreak: true, pchName: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001D70
// Name: __CreateCCvarICvar_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCvar *__cdecl _CreateCCvarICvar_interface()
{
  return &s_Cvar;
}

// ============================================================
// Overlay from vstdlib_s (Missing functions)
// ============================================================
namespace vstdlib_s {

//------------------------------------------------------------------------------
// Address: 0x3F602AA0
// Name: protected: void CUtlLinkedList<class CCoroutine,int>::ConstructList(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlLinkedList<CCoroutine,int>::ConstructList(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<ecx>,
        _DWORD *_EAX@<eax>,
        void (__cdecl *a3)(const char *, _DWORD)@<ebx>)
{
  bool v3; // cf

  *_EAX += _EAX;
  v3 = __CFADD__(BYTE1(this), byte_3F654324[(_DWORD)_EAX - 1063600876]);
  byte_3F654324[(_DWORD)_EAX - 1063600876] += BYTE1(this);
  if ( v3 )
  {
    __asm { aas }
    a3(a1: "Assertion Failed: IsValidIndex(i)", a2: 0);
    JUMPOUT(0x3F602AB7);
  }
  JUMPOUT(0x3F602B0C);
}

//------------------------------------------------------------------------------
// Address: 0x3F602B50
// Name: public: void CUtlMemory<struct CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::ListElem_t>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlMemory<CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::ListElem_t>::Validate(
        CUtlMemory<CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::ListElem_t> *this@<edi>,
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *validator@<esi>,
        char a3@<zf>,
        int a4@<eax>,
        int a5@<ebx>,
        _DWORD *a6@<ebp>,
        char *pchName)
{
  int v7; // eax
  _BYTE v8[16]; // [esp-8h] [ebp-10h] BYREF

  if ( !a3 )
    (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a4, a3: a5);
  v7 = a6[16] - (_DWORD)v8;
  a6[17] = v8;
  a6[19] = v7;
  CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::operator[](this: validator, i: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F602EF0
// Name: public: void CUtlMemory<struct CUtlLinkedList<struct CCommandLine::CommandLineParam_t,int>::ListElem_t>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlMemory<CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::ListElem_t>::Grow(
        CUtlMemory<CUtlLinkedList<CCommandLine::CommandLineParam_t,int>::ListElem_t> *this@<ecx>,
        int a2@<eax>,
        int a3@<ebx>)
{
  *(char *)(a3 + a2 + 71) >>= 7;
}

//------------------------------------------------------------------------------
// Address: 0x3F603370
// Name: Coroutine_Create
// Source: json
//------------------------------------------------------------------------------
void __cdecl Coroutine_Create(int a1)
{
  ConVar *v1; // ecx

  ConVar::SetReplicated(this: v1);
  CoroutineTestFunc(pvRelaunch: (void *)0xFFFFFFFF);
  ConCommandBase::RevertFlaggedCvars(flag: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F603AD0
// Name: Coroutine_Continue
// Source: json
//------------------------------------------------------------------------------
int __cdecl Coroutine_Continue(int a1, int a2)
{
  return ((int (__cdecl *)(int, _DWORD, int))loc_3F6033D0)(a1, a2: 0, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F603B10
// Name: Coroutine_Cancel
// Source: json
//------------------------------------------------------------------------------
int __thiscall Coroutine_Cancel(ConVar *this)
{
  int v1; // eax

  ConVar::SetReplicated(this);
  return sub_3F605750(a1: v1 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F603B30
// Name: Coroutine_DebugBreak
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Coroutine_DebugBreak(int a1)
{
  ((void (__cdecl *)(int, int, _DWORD))loc_3F6033D0)(a1, a2: 1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F604AF0
// Name: public: CCoroutine::CCoroutine(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCoroutine::CCoroutine(CCoroutine *this@<ecx>, int _EAX@<eax>, int a3@<ebx>)
{
  __asm { aas }
  *(_DWORD *)((char *)this + 85) = a3;
  JUMPOUT(0x3F604AFF);
}

//------------------------------------------------------------------------------
// Address: 0x3F604B00
// Name: public: void CCoroutine::RestoreStack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCoroutine::RestoreStack(
        CCoroutine *this@<ecx>,
        int _EAX@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        int a5@<edi>)
{
  unsigned int v6; // eax

  LOBYTE(a3) = byte_3F653FFF[_EAX - 1063600239] + a3;
  __asm { aas }
  *(_DWORD *)(this->m_Registers[2] + _EAX + 92) = a3;
  *(_DWORD *)(this->m_Registers[2] + _EAX + 72) = a3;
  *(_DWORD *)(this->m_Registers[2] + _EAX + 76) = a3;
  *(_DWORD *)(this->m_Registers[2] + _EAX + 68) = a3;
  *(_DWORD *)(this->m_Registers[2] + _EAX + 64) = a3;
  *(_DWORD *)(this->m_Registers[2] + _EAX + 80) = "(no name set)";
  v6 = *(_DWORD *)(a4 - 43);
  *(_DWORD *)(a4 - 3) = a5;
  if ( a4 - 3 >= v6 )
    JUMPOUT(0x3F604B42);
  JUMPOUT(0x3F604B6E);
}

//------------------------------------------------------------------------------
// Address: 0x3F604B50
// Name: public: void CCoroutine::SaveStack(int __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CCoroutine::SaveStack(CCoroutine *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int *piLocal)
{
  int v5; // edi

  ((void (__cdecl *)(const char *, int, const char *, int, void *))AssertMsgImplementation)(
    a1: "Assertion Failed: (&src < Base()) || (&src >= (Base() + Count()) )",
    a2,
    a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
    a4: 623,
    a5: &unk_3F66573D);
  sub_3F605810(a1: a3 - 4);
  if ( (*(_DWORD *)(a3 - 8))-- == 1 )
  {
    v5 = *(_DWORD *)(a3 - 32);
    if ( v5 > a2 )
    {
      if ( a2 > 0 || v5 <= 0 )
        ((void (__cdecl *)(const char *, int, const char *, int, void *))AssertMsgImplementation)(
          a1: "Assertion Failed: IsValidIndex(i)",
          a2,
          a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
          a4: 292,
          a5: &unk_3F66573C);
      if ( (unsigned __int8)((int (__cdecl *)(_DWORD, int, int))loc_3F6033D0)(a1: **(_DWORD **)(a3 - 44), a2, a3: a2) != 1 )
        JUMPOUT(0x3F604BDC);
      JUMPOUT(0x3F604BEB);
    }
    JUMPOUT(0x3F604BF2);
  }
  JUMPOUT(0x3F604A4E);
}

//------------------------------------------------------------------------------
// Address: 0x3F604BE0
// Name: public: void CCoroutine::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CCoroutine::Validate(
        CCoroutine *this@<edi>,
        CValidator *validator@<esi>,
        int _EAX@<eax>,
        int a4@<ebx>,
        char *pchName)
{
  __asm { aas }
  ((void (__cdecl *)())AssertMsgImplementation)();
  if ( (int)((char *)&validator->m_pValObjectFirst + 1) >= (int)this )
  {
    if ( (int)this > a4 )
    {
      if ( a4 <= 0 && (int)this > 0 )
        JUMPOUT(0x3F604C1F);
      JUMPOUT(0x3F604C0B);
    }
    JUMPOUT(0x3F604C5A);
  }
  JUMPOUT(0x3F604B90);
}

//------------------------------------------------------------------------------
// Address: 0x3F604C10
// Name: public: CCoroutineMgr::CCoroutineMgr(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CCoroutineMgr::CCoroutineMgr(
        CCoroutineMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  int v5; // eax
  bool v6; // cc

  ((void (__cdecl *)(const char *))AssertMsgImplementation)(a1: "Assertion Failed: IsValidIndex(i)");
  if ( (unsigned __int8)((int (__cdecl *)(_DWORD, int, int))loc_3F6033D0)(
                          a1: *(_DWORD *)(*(_DWORD *)(a3 - 44) + 4 * a5),
                          a2,
                          a3: a2) != 0 )
    ((void (__cdecl *)(const char *))AssertMsgImplementation)(a1: "Assertion Failed: Coroutine_Continue( coroutines[i], 0 ) == false");
  if ( a5 + 1 >= a4 )
  {
    if ( *(_DWORD *)(a3 - 36) >= a2 )
    {
      v5 = *(_DWORD *)(a3 - 44);
      if ( v5 != a2 )
        (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v5, a3: a2);
    }
    v6 = *(_DWORD *)(a3 - 16) < a2;
    *(_DWORD *)(a3 - 12) = a2;
    if ( !v6 )
    {
      if ( *(_DWORD *)(a3 - 24) != a2 )
        JUMPOUT(0x3F604C8C);
      JUMPOUT(0x3F604C9C);
    }
    JUMPOUT(0x3F604CB9);
  }
  JUMPOUT(0x3F604BF8);
}

//------------------------------------------------------------------------------
// Address: 0x3F604C90
// Name: public: int CCoroutineMgr::CreateCoroutine(void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall CCoroutineMgr::CreateCoroutine@<al>(
        CCoroutineMgr *this@<ecx>,
        int a2@<eax>,
        int a3@<edx>,
        int a4@<ebx>,
        int a5@<ebp>)
{
  bool v5; // cc

  (*(void (__thiscall **)(CCoroutineMgr *, int))(a3 + 24))(a1: this, a2);
  *(_DWORD *)(a5 - 24) = 0;
  v5 = *(_DWORD *)(a5 - 16) < a4;
  *(_DWORD *)(a5 - 20) = a4;
  if ( !v5 && a4 != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: 0, a3: a4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F604CD0
// Name: Coroutine_GetStackDepth
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F604D00
// Name: public: int CCoroutineMgr::GetActiveCoroutineHandle(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall CCoroutineMgr::GetActiveCoroutineHandle@<eax>(
        CCoroutineMgr *this@<ecx>,
        int a2@<ebx>,
        void (__thiscall *a3)(CCoroutineMgr *)@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  ConVar *v5; // ecx
  ConVar *v6; // ecx
  int v7; // eax
  int v9; // eax
  _DWORD v10[5]; // [esp-14h] [ebp-14h] BYREF

  a3(a1: this);
  ConVar::SetReplicated(this: v5);
  if ( *(_DWORD *)(v7 + 60) > a2 )
  {
    v10[1] = a5;
    v10[0] = a4;
    v10[4] = v10;
    ConVar::SetReplicated(this: v6);
    if ( (unsigned __int8)sub_3F614FF0(a1: v9 + 44) == 0 )
      ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))a3)(
        a1: "Assertion Failed: IsValidIndex(i)",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
        a4: 292,
        a5: &unk_3F66573C,
        a6: 0);
    JUMPOUT(0x3F604D6D);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F604D70
// Name: public: class CCoroutine __near & CCoroutineMgr::GetActiveCoroutine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoroutineMgr::GetActiveCoroutine(CCoroutineMgr *this)
{
  CThreadMutex::Lock(this: &stru_3F6642BC);
  JUMPOUT(0x3F604D83);
}

//------------------------------------------------------------------------------
// Address: 0x3F604D90
// Name: public: class CCoroutine __near & CCoroutineMgr::GetPreviouslyActiveCoroutine(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CCoroutineMgr::GetPreviouslyActiveCoroutine(
        CCoroutineMgr *this@<ecx>,
        int a2@<eax>,
        CValidator *a3@<ebx>,
        _BYTE *a4@<edi>,
        int a5@<esi>)
{
  const char *v5; // eax

  *a4 = __ROR1__(*a4, 142);
  while ( 1 )
  {
    if ( a5 < 0 || a5 >= a2 )
    {
      AssertMsgImplementation(
        a1: "Assertion Failed: IsValidIndex(i)",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
        a4: 292,
        a5: &unk_3F66573E,
        a6: 0);
      a2 = dword_3F662AD4;
    }
    if ( *(_DWORD *)(dword_3F662AC8 + 4 * a5) != 0 )
    {
      if ( a5 < 0 || a5 >= a2 )
        AssertMsgImplementation(
          a1: "Assertion Failed: IsValidIndex(i)",
          a2: 0,
          a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
          a4: 292,
          a5: &unk_3F66573E,
          a6: 0);
      JUMPOUT(0x3F604DFB);
    }
    if ( ++a5 >= a2 )
    {
      v5 = (const char *)sub_3F62928F(a1: &output[968]);
      CValidator::Push(this: a3, a2: v5, a3: &dword_3F662AC4, a4: "g_VecPCoroutineMgr");
      JUMPOUT(0x3F604E7C);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F604E00
// Name: public: bool CCoroutineMgr::IsValidCoroutine(int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F604E20
// Name: public: void CCoroutineMgr::SetActiveCoroutine(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CCoroutineMgr::SetActiveCoroutine(
        CCoroutineMgr *this@<ecx>,
        int _EAX@<eax>,
        void (__cdecl *a3)(const char *, _DWORD)@<edi>,
        int hCoroutine)
{
  bool v4; // cf

  v4 = __CFADD__(BYTE1(this), byte_3F654324[_EAX - 1063600876]);
  byte_3F654324[_EAX - 1063600876] += BYTE1(this);
  if ( v4 )
  {
    __asm { aas }
    a3(a1: "Assertion Failed: IsValidIndex(i)", a2: 0);
    JUMPOUT(0x3F604E38);
  }
  JUMPOUT(0x3F604E8A);
}

//------------------------------------------------------------------------------
// Address: 0x3F604E80
// Name: public: bool CCoroutineMgr::IsAnyCoroutineActive(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCoroutineMgr::IsAnyCoroutineActive(
        CCoroutineMgr *this@<ecx>,
        int _EAX@<eax>,
        int a3@<ebx>,
        void (__thiscall *a4)(int, int)@<esi>)
{
  int v5; // eax

  __asm { aas }
  v5 = sub_3F62928F(a1: this);
  a4(a1: a3, a2: v5);
  JUMPOUT(0x3F604E8B);
}

//------------------------------------------------------------------------------
// Address: 0x3F604E90
// Name: public: void CCoroutineMgr::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CCoroutineMgr::Validate(
        int a1@<eax>,
        CValidator *a2@<ebx>,
        void (__thiscall *a3)(CValidator *, int)@<ebp>,
        CCoroutineMgr *this,
        CCoroutineMgr *pchName)
{
  if ( a1 != 0 )
    a3(a1: a2, a2: a1);
  CValidator::Pop(this: a2);
  CValidator::Pop(this: a2);
  CThreadMutex::Unlock(this: &stru_3F6642BC);
}

//------------------------------------------------------------------------------
// Address: 0x3F605000
// Name: public: CThreadLocalPtr<class CCoroutineMgr>::~CThreadLocalPtr<class CCoroutineMgr>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CThreadLocalPtr<CCoroutineMgr>::~CThreadLocalPtr<CCoroutineMgr>(
        CThreadLocalPtr<CCoroutineMgr> *this@<ecx>,
        int a2@<eax>)
{
  if ( a2 != 0 )
    JUMPOUT(0x3F60500C);
  JUMPOUT(0x3F60501D);
}

//------------------------------------------------------------------------------
// Address: 0x3F605010
// Name: class CCoroutineMgr __near & GCoroutineMgr(void)
// Source: json
//------------------------------------------------------------------------------
CCoroutineMgr *__usercall GCoroutineMgr@<eax>(int a1@<eax>, int a2@<edx>, int a3@<esi>)
{
  CCoroutineMgr *result; // eax

  result = (CCoroutineMgr *)(*(int (__stdcall **)(int))(a2 + 24))(a1);
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 8) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6050D0
// Name: _Coroutine_ReleaseThreadMemory
// Source: json
//------------------------------------------------------------------------------
int __userpurge Coroutine_ReleaseThreadMemory@<eax>(int a1@<eax>, int a2)
{
  const char *v3; // eax
  int v4; // eax

  if ( (unsigned __int8)((int (__thiscall *)(int))loc_3F605150)(a1: a2) == 0 )
  {
    v3 = (const char *)((int (*)(const char *, ...))loc_3F6027D0)(a1: "CUtlLinkedList::Next: invalid index %d\n", a1);
    v4 = ((int (*)(const char *, ...))loc_3F6027D0)(a1: "Assertion Failed: %s", v3);
    AssertMsgImplementation(
      a1: v4,
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
      a4: 284,
      a5: &unk_3F66573B,
      a6: 0);
  }
  return *(_DWORD *)(124 * a1 + *(_DWORD *)(a2 + 4) + 120);
}

//------------------------------------------------------------------------------
// Address: 0x3F605180
// Name: public: CCoroutineMgr::~CCoroutineMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCoroutineMgr::~CCoroutineMgr(CCoroutineMgr *this@<ecx>, _DWORD *a2@<eax>, CValidator *a3@<esi>)
{
  const char *v4; // eax
  const char *v5; // eax
  void *v6; // edi

  v4 = (const char *)sub_3F62928F(a1: &output[872]);
  CValidator::Push(this: a3, a2: v4, a3: a2, a4: "m_ListCoroutines");
  v5 = (const char *)sub_3F62928F(a1: &CUtlMemoryBase `RTTI Type Descriptor');
  CValidator::Push(this: a3, a2: v5, a3: a2, a4: "m_Memory");
  v6 = (void *)a2[1];
  if ( v6 != nullptr )
    CValidator::ClaimMemory(this: a3, a2: v6);
  CValidator::Pop(this: a3);
  CValidator::Pop(this: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F6051F0
// Name: _Coroutine_Create
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F605210
// Name: bool Internal_Coroutine_Continue(int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall Internal_Coroutine_Continue@<al>(char a1@<al>)
{
  return a1 + 61;
}

//------------------------------------------------------------------------------
// Address: 0x3F6053F0
// Name: _Coroutine_Continue
// Source: json
//------------------------------------------------------------------------------
int __cdecl Coroutine_Continue()
{
  return dword_3F662AD4;
}

//------------------------------------------------------------------------------
// Address: 0x3F605400
// Name: void Coroutine_Launch(class CCoroutine __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F605420
// Name: _Coroutine_Cancel
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F605430
// Name: _Coroutine_DebugBreak
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl Coroutine_DebugBreak()
{
  JUMPOUT(0x3F60543F);
}

//------------------------------------------------------------------------------
// Address: 0x3F605440
// Name: _Coroutine_IsActive
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F605460
// Name: _Coroutine_GetCurrentlyActive
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall Coroutine_GetCurrentlyActive@<eax>(int result@<eax>, int *a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
  int v4; // edx

  BYTE1(result) -= *(_BYTE *)(a4 + 63);
  v4 = *a2;
  while ( *(_DWORD *)(a3 + 4 * result) != v4 )
  {
    if ( ++result >= a4 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6054A0
// Name: _Coroutine_YieldToMain
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall Coroutine_YieldToMain@<eax>(int a1@<esi>)
{
  int result; // eax

  result = sub_3F605B60(a1);
  --dword_3F662AD4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6055C0
// Name: void Coroutine_Finish(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge Coroutine_Finish(
        int _EAX@<eax>,
        _DWORD *a2@<ebx>,
        void (__cdecl *a3)(const char *, _DWORD)@<ebp>,
        int a4@<edi>,
        _DWORD *a5@<esi>,
        int a6)
{
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // edx

  __asm { aas }
  a3(a1: "Assertion Failed: (elem == Count()) || IsValidIndex(elem)", a2: 0);
  v7 = a5[2];
  if ( a5[4] + 1 > v7 )
    sub_3F626080(a1: v7);
  ++a5[4];
  sub_3F605C70(a1: a4);
  if ( (unsigned __int8)sub_3F614FF0(a1: a5) == 0 )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))a3)(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 306,
      a5: &unk_3F66574B,
      a6: 0);
  v8 = (_DWORD *)(a5[1] + 12 * a4);
  if ( v8 != nullptr )
  {
    v9 = a2[1];
    *v8 = *a2;
    v10 = a2[2];
    v8[1] = v9;
    v8[2] = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F605670
// Name: void CoroutineTestFunc(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CoroutineTestFunc(int a1@<edi>, void *pvRelaunch)
{
  int v2; // esi
  _DWORD *v3; // eax

  v2 = ((int (*)(void))loc_3F605F40)();
  sub_3F605D70(a1: pvRelaunch, a2: v2);
  v3 = (_DWORD *)(*(_DWORD *)(a1 + 4) + 124 * v2);
  if ( v3 != nullptr )
  {
    v3[24] = 12;
    v3[25] = 0;
    v3[26] = 0;
    v3[27] = 0;
    v3[28] = 0;
    v3[18] = 0;
    v3[17] = 0;
    v3[16] = 0;
    v3[19] = 0;
    v3[22] = 0;
    v3[20] = "(none)";
    v3[21] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F605F20
// Name: _Coroutine_GetStackDepth
// Source: json
//------------------------------------------------------------------------------
void __cdecl Coroutine_GetStackDepth()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F605F90
// Name: _Coroutine_ValidateGlobals
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Coroutine_ValidateGlobals(char a1@<dh>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v4; // esi
  const char *v5; // eax
  int v6; // eax

  v4 = a4 - 1;
  *(_BYTE *)(a2 + 42) &= a1;
  v5 = (const char *)sub_3F62928F(a1: &output[872]);
  Error(a1: "%s overflow!\n", v5);
  v6 = 124 * a3;
  *(_DWORD *)(*(_DWORD *)(v4 + 4) + v6 + 116) = a3;
  *(_DWORD *)(*(_DWORD *)(v4 + 4) + v6 + 120) = a3;
  *(_DWORD *)(v4 + 36) = *(_DWORD *)(v4 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F606140
// Name: public: CThreadLocalPtr<class CCoroutineMgr>::CThreadLocalPtr<class CCoroutineMgr>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadLocalPtr<CCoroutineMgr>::CThreadLocalPtr<CCoroutineMgr>(CThreadLocalPtr<CCoroutineMgr> *this)
{
  dword_3F662AD4 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F606160
// Name: public: class CCoroutineMgr __near * CThreadLocalPtr<class CCoroutineMgr>::operator=(class CCoroutineMgr __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CThreadLocalPtr<CCoroutineMgr>::operator=(
        char a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        CThreadLocalPtr<CCoroutineMgr> *this)
{
  if ( !(a2 ^ a3 | a1) )
    JUMPOUT(0x3F60616D);
  JUMPOUT(0x3F60617B);
}

//------------------------------------------------------------------------------
// Address: 0x3F606170
// Name: public: bool CThreadLocalPtr<class CCoroutineMgr>::operator!(void)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_DWORD *__usercall CThreadLocalPtr<CCoroutineMgr>::operator!@<eax>(
        CThreadLocalPtr<CCoroutineMgr> *this@<ecx>,
        _DWORD *result@<eax>)
{
  *result += result;
  ++dword_3F662AD4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F606190
// Name: public: bool CThreadLocalPtr<class CCoroutineMgr>::operator!=(int)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F6061F0
// Name: public: CUtlLinkedList<class CCoroutine,int>::CUtlLinkedList<class CCoroutine,int>(int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *__usercall CUtlLinkedList<CCoroutine,int>::CUtlLinkedList<CCoroutine,int>@<eax>(
        CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *this@<ecx>,
        void *a2@<eax>)
{
  const void *v3; // [esp-14h] [ebp-14h]
  size_t v4; // [esp-10h] [ebp-10h]

  return (CUtlLinkedList<CCommandLine::CommandLineParam_t,int> *)memcpy_0(a1: a2, Src: v3, Size: v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F606210
// Name: public: CUtlLinkedList<class CCoroutine,int>::~CUtlLinkedList<class CCoroutine,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCoroutine,int>::~CUtlLinkedList<CCoroutine,int>(
        CUtlLinkedList<CCoroutine,int> *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>)
{
  if ( a3 < *(_DWORD *)(a2 + 32) && a3 >= 0 )
  {
    if ( (unsigned __int8)((int (__thiscall *)(int))loc_3F605150)(a1: a2) == 0 )
      AssertMsgImplementation(
        a1: "Assertion Failed: IsValidIndex(i)",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
        a4: 277,
        a5: &unk_3F665753,
        a6: 0);
    JUMPOUT(0x3F60624F);
  }
  JUMPOUT(0x3F60625B);
}

//------------------------------------------------------------------------------
// Address: 0x3F606250
// Name: public: int CUtlLinkedList<class CCoroutine,int>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlLinkedList<CCoroutine,int>::AddToTail@<eax>(
        CUtlLinkedList<CCoroutine,int> *this@<ecx>,
        char a2@<zf>)
{
  int result; // eax

  if ( !a2 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F606290
// Name: public: void CCoroutineMgr::DeleteCoroutine(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoroutineMgr::DeleteCoroutine(CCoroutineMgr *this)
{
  JUMPOUT(0x3F606297);
}

//------------------------------------------------------------------------------
// Address: 0x3F6062A0
// Name: public: int CUtlLinkedList<class CCoroutine,int>::Next(int)const
// Source: json
//------------------------------------------------------------------------------
void *__usercall CUtlLinkedList<CCoroutine,int>::Next@<eax>(
        size_t i@<eax>,
        const void *a2@<ecx>,
        CUtlLinkedList<CCoroutine,int> *this)
{
  return memcpy_0(a1: this, Src: a2, Size: i);
}

//------------------------------------------------------------------------------
// Address: 0x3F6063A0
// Name: public: bool CUtlLinkedList<class CCoroutine,int>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void *__thiscall CUtlLinkedList<CCoroutine,int>::IsValidIndex(CUtlLinkedList<CCoroutine,int> *this)
{
  return CThreadLocalBase::Get((CThreadLocalBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F606400
// Name: public: void CUtlLinkedList<class CCoroutine,int>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCoroutine,int>::Validate(CUtlLinkedList<CCoroutine,int> *this@<eax>)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F6068D0
// Name: public: struct CUtlLinkedList<class CCoroutine,int>::ListElem_t const __near & CUtlMemory<struct CUtlLinkedList<class CCoroutine,int>::ListElem_t>::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
const CUtlLinkedList<CCoroutine,int>::ListElem_t *__userpurge CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t>::operator[]@<eax>(
        CUtlLinkedList<CCoroutine,int> *this@<edi>,
        int i@<esi>,
        char a3@<cf>,
        int _EAX@<eax>,
        int a5@<ebx>,
        int a6)
{
  *(_BYTE *)(a5 + 101) += _EAX + a3;
  __asm { aas }
  (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*_EAX + 24))(a1: *_EAX, a2: i);
  return (const CUtlLinkedList<CCoroutine,int>::ListElem_t *)i;
}

//------------------------------------------------------------------------------
// Address: 0x3F606910
// Name: protected: void CUtlLinkedList<class CCoroutine,int>::ResetDbgInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCoroutine,int>::ResetDbgInfo(
        CUtlLinkedList<CCoroutine,int> *this@<ecx>,
        char a2@<zf>,
        int _EAX@<eax>,
        int a4@<esi>)
{
  __asm { aas }
  if ( !a2 )
  {
    if ( *(_DWORD *)(a4 + 16) != 0 )
      AssertMsgImplementation(
        a1: "Assertion Failed: pNode->m_RefCount == 0",
        a2: 0,
        a3: ".\\debugstatssystem.cpp",
        a4: 80,
        a5: &unk_3F665755,
        a6: 0);
    JUMPOUT(0x3F60694E);
  }
  JUMPOUT(0x3F606973);
}

//------------------------------------------------------------------------------
// Address: 0x3F606950
// Name: public: int CUtlLinkedList<class CCoroutine,int>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall CUtlLinkedList<CCoroutine,int>::InsertBefore@<eax>(
        CUtlLinkedList<CCoroutine,int> *this@<ecx>,
        char a2@<cf>,
        int a3@<eax>,
        void (__cdecl *a4)(int)@<edx>,
        int a5@<edi>,
        int a6@<esi>)
{
  int result; // eax
  int v7; // [esp-4h] [ebp-4h]

  *(_BYTE *)a4 -= a2 + BYTE1(this);
  a4(a1: a3);
  result = (*(int (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a6, a3: 1);
  if ( a5 != 0 )
    JUMPOUT(0x3F606920);
  *(_DWORD *)(v7 + 4) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F606990
// Name: public: void CUtlLinkedList<class CCoroutine,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlLinkedList<CCoroutine,int>::RemoveAll(
        CUtlLinkedList<CCoroutine,int> *this@<ecx>,
        const char *a2@<eax>,
        int a3)
{
  _DWORD *i; // esi

  strlen(a2);
  for ( i = (_DWORD *)this->m_Memory.m_nAllocationCount; i != nullptr; i = (_DWORD *)i[5] )
  {
    if ( sub_3F6066C0(a1: *i) == 0 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F606B70
// Name: public: void CUtlLinkedList<class CCoroutine,int>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCoroutine,int>::Free(
        CUtlLinkedList<CCoroutine,int> *this@<ecx>,
        int elem@<eax>,
        char *a3@<edi>)
{
  stru_3F664330.m_CreateFn = (void *(__cdecl *)())this;
  dword_3F6642E0 = (int)&CKeyValuesSystem::`vftable';
  dword_3F6642EC = 4;
  dword_3F6642F0 = (int)a3;
  dword_3F6642F4 = (int)a3;
  dword_3F6642F8 = (int)a3;
  dword_3F6642FC = (int)a3;
  dword_3F664304 = 256;
  dword_3F664308 = 1;
  word_3F664328 = (__int16)a3;
  dword_3F664320 = (int)a3;
  dword_3F66431C = (int)a3;
  dword_3F66430C = (unsigned int)&unk_3F664300 | elem;
  dword_3F664310 = (unsigned int)&unk_3F664300 | elem;
  dword_3F66432C = (int)a3;
  dword_3F664324 = (int)a3;
  stru_3F664330.m_pName = a3;
  stru_3F664330.m_pNext = (InterfaceReg *)a3;
  dword_3F66433C = (int)a3;
  pName = a3;
  CThreadSpinRWLock::CThreadSpinRWLock(this: &stru_3F664348);
  CThreadSpinRWLock::CThreadSpinRWLock(this: &stru_3F664358);
  dword_3F66437C = -1;
  dword_3F664384 = -1;
  dword_3F664370 = -1;
  dword_3F66436C = -1;
  dword_3F664368 = -1;
  dword_3F664380 = (int)a3;
  JUMPOUT(0x3F606C3E);
}

//------------------------------------------------------------------------------
// Address: 0x3F606C40
// Name: public: struct CUtlLinkedList<class CCoroutine,int>::ListElem_t __near & CUtlMemory<struct CUtlLinkedList<class CCoroutine,int>::ListElem_t>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t>::operator[](
        CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t> *this@<esi>,
        int i@<ebx>,
        int _EAX@<eax>,
        CThreadSpinRWLock *a4@<ecx>,
        int a5@<edi>)
{
  void *(__cdecl *v6)(); // edx

  *(_BYTE *)(i + 102) = _EAX;
  __asm { aas }
  dword_3F664374 = (int)this;
  byte_3F66438C = _EAX;
  dword_3F664390 = 24;
  dword_3F664394 = a5;
  dword_3F664398 = a5;
  dword_3F66439C = a5;
  dword_3F664378 = a5;
  CThreadSpinRWLock::LockForWrite(this: a4);
  sub_3F626140();
  InterfaceReg::InterfaceReg(this: &stru_3F664330, fn: v6, pName: pName);
  JUMPOUT(0x3F606C9D);
}

//------------------------------------------------------------------------------
// Address: 0x3F606CD0
// Name: public: void CUtlMemory<struct CUtlLinkedList<class CCoroutine,int>::ListElem_t>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t>::Validate(
        CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t> *this@<edi>,
        void (__cdecl *a2)(const char *)@<ebx>,
        int a3@<ebp>,
        char *pchName)
{
  a2(a1: "Assertion Failed: IsValidIndex(i)");
  *(_DWORD *)&stru_3F664330.m_pName[a3] = this;
  if ( (unsigned __int8)sub_3F614FF0(a1: &stru_3F664330) == 0 )
    JUMPOUT(0x3F606CFF);
  JUMPOUT(0x3F606D0F);
}

//------------------------------------------------------------------------------
// Address: 0x3F607030
// Name: public: void CUtlMemory<int>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlMemory<int>::Validate(
        CUtlMemory<int> *this@<edi>,
        CValidator *validator@<esi>,
        int a3@<ebx>,
        int a4@<ebp>,
        char *pchName)
{
  (*(void (__thiscall **)(_DWORD, _DWORD, CValidator *))(*g_pMemAllocSteam + 24))(
    a1: g_pMemAllocSteam,
    a2: *(_DWORD *)(*(_DWORD *)(a3 + 4) + 4 * (_DWORD)this),
    a3: validator);
  if ( (int)&this->m_pMemory + 1 < *(_DWORD *)(a4 + 28) )
    JUMPOUT(0x3F607010);
  CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>::Element(
    this: (CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *)pchName,
    i: (int)validator);
}

//------------------------------------------------------------------------------
// Address: 0x3F607420
// Name: protected: struct CUtlLinkedList<class CCoroutine,int>::ListElem_t __near & CUtlLinkedList<class CCoroutine,int>::InternalElement(int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CUtlLinkedList<CCoroutine,int>::InternalElement(
        CUtlLinkedList<CCoroutine,int> *this@<esi>,
        char a2@<zf>)
{
  if ( !a2 )
    JUMPOUT(0x3F607426);
  JUMPOUT(0x3F60759A);
}

//------------------------------------------------------------------------------
// Address: 0x3F607430
// Name: public: void CUtlLinkedList<class CCoroutine,int>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlLinkedList<CCoroutine,int>::LinkBefore(
        CUtlLinkedList<CCoroutine,int> *this@<ecx>,
        int a2@<ebp>,
        const char *before,
        CUtlLinkedList<CCoroutine,int>::ListElem_t *elem)
{
  unsigned int v4; // ebx
  _DWORD *i; // edi
  int v6; // esi
  int v7; // ebp
  CThreadSpinRWLock *v8; // [esp-8h] [ebp-10h]
  int v9; // [esp-4h] [ebp-Ch]
  unsigned int v10; // [esp+0h] [ebp-8h]
  int v11; // [esp+4h] [ebp-4h]

  v4 = ((int (__thiscall *)(CUtlLinkedList<CCoroutine,int> *))sub_3F619AD0)(a1: this);
  v10 = v4;
  v8 = (CThreadSpinRWLock *)(a2 + 104);
  CThreadSpinRWLock::LockForRead(this: (CThreadSpinRWLock *)(a2 + 104));
  if ( (unsigned __int8)sub_3F614FF0(a1: a2 + 80) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 292,
      a5: &unk_3F66575D,
      a6: 0);
  for ( i = (_DWORD *)(*(_DWORD *)(a2 + 84) + 12 * (v4 % 0x1001)); ; i = (_DWORD *)i[2] )
  {
    if ( *i == v4 )
    {
      v6 = i[1] >> 15;
      v7 = a2 + 12;
      v11 = i[1];
      if ( (unsigned __int8)sub_3F614FF0(a1: v7) == 0 )
        AssertMsgImplementation(
          a1: "Assertion Failed: IsValidIndex(i)",
          a2: 0,
          a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
          a4: 299,
          a5: &unk_3F665759,
          a6: 0);
      if ( Q_strnicmp(a1: before, a2: (v11 & 0x7FFF) + *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4 * v6), a3: 0x7FFFFFFF) == 0 )
        break;
      a2 = v9;
      v4 = v10;
    }
    if ( i[2] == 0 )
    {
      CThreadSpinRWLock::UnlockRead(this: v8);
      CThreadSpinRWLock::LockForWrite(this: v8);
      if ( i[1] != 0 )
        i[2] = ((int (__thiscall *)(int))sub_3F61FB60)(a1: a2 + 32);
      strlen(before);
      JUMPOUT(0x3F60756F);
    }
  }
  CThreadSpinRWLock::UnlockRead(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x3F607570
// Name: public: void CUtlLinkedList<class CCoroutine,int>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlLinkedList<CCoroutine,int>::Unlink(
        CUtlLinkedList<CCoroutine,int> *this@<edi>,
        CUtlLinkedList<CCoroutine,int>::ListElem_t *a2@<ebx>,
        int a3)
{
  this->m_Memory.m_nGrowSize = 0;
  this->m_Memory.m_pMemory = a2;
  this->m_Memory.m_nAllocationCount = ((int (__cdecl *)())sub_3F607270)();
  ((void (*)(void))CThreadSpinRWLock::UnlockWrite)();
}

//------------------------------------------------------------------------------
// Address: 0x3F6076A0
// Name: protected: int CUtlLinkedList<class CCoroutine,int>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlLinkedList<CCoroutine,int>::AllocInternal(
        CUtlLinkedList<CCoroutine,int> *this@<ecx>,
        CThreadSpinRWLock *a2@<ebp>,
        CUtlLinkedList<CCoroutine,int> *a3@<edi>,
        int a4@<esi>,
        bool multilist)
{
  if ( a4 == -1 )
    this = a3;
  if ( this->m_Memory.m_nAllocationCount != -1 )
    JUMPOUT(0x3F607686);
  AssertMsgImplementation(
    a1: "Assertion Failed: m_LeakTrack.Remove( pKV )",
    a2: 0,
    a3: ".\\keyvaluessystem.cpp",
    a4: 321,
    a5: &unk_3F665758,
    a6: 0);
  CThreadSpinRWLock::UnlockWrite(this: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F607A90
// Name: public: bool CUtlLinkedList<class CCoroutine,int>::IsInList(int)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlLinkedList<CCoroutine,int>::IsInList(CUtlLinkedList<CCoroutine,int> *this@<eax>)
{
  CThreadSpinRWLock::UnlockRead(this: (CThreadSpinRWLock *)this->m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x3F607AB0
// Name: public: void CUtlMemory<struct CUtlLinkedList<class CCoroutine,int>::ListElem_t>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t>::Grow(
        CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t> *this@<ecx>,
        void (__cdecl **a2)(ConVar *, const char *)@<eax>,
        int *a3@<edx>,
        int num)
{
  void (__cdecl *v4)(ConVar *, const char *); // ecx
  int v5; // eax
  CDefaultCvar v6; // [esp+0h] [ebp-Ch] BYREF
  int v7; // [esp+8h] [ebp-4h]

  v4 = *a2;
  v5 = *a3;
  v6.m_fnGlobalChangeCallback = v4;
  v7 = v5;
  ((void (__cdecl *)(void (__cdecl **)(ConVar *, const char *)))loc_3F607E00)(a1: &v6.m_fnGlobalChangeCallback);
}

//------------------------------------------------------------------------------
// Address: 0x3F607B50
// Name: public: void CUtlMemory<int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlMemory<int>::Grow(CUtlMemory<int> *this@<esi>, __int16 num@<ax>, int a3@<edi>)
{
  __asm { aas }
  ((void (__cdecl *)(const char *, _DWORD, const char *, int, int))AssertMsgImplementation)(
    a1: "Assertion Failed: IsValidIndex(i)",
    a2: 0,
    a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
    a4: 299,
    a5: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F607D00
// Name: public: int CUtlLinkedList<class CCoroutine,int>::Previous(int)const
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlLinkedList<CCoroutine,int>::Previous@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        CUtlLinkedList<CCoroutine,int> *this)
{
  if ( (unsigned __int8)sub_3F614FF0(a1) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 292,
      a5: &unk_3F66575D,
      a6: 0);
  return *(_DWORD *)(a1 + 4) + 12 * a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F607DE0
// Name: int Q_strcmp(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_strcmp(const char *s1@<eax>)
{
  *(_DWORD *)s1 += s1;
  JUMPOUT(0x3F607DE2);
}

//------------------------------------------------------------------------------
// Address: 0x3F607E90
// Name: private: void CUtlMemory<struct CUtlLinkedList<class CCoroutine,int>::ListElem_t>::ValidateGrowSize(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUtlMemory<CUtlLinkedList<CCoroutine,int>::ListElem_t>::ValidateGrowSize()
{
  JUMPOUT(0x3F607E93);
}

//------------------------------------------------------------------------------
// Address: 0x3F615810
// Name: __Q_strcmp
// Source: json
//------------------------------------------------------------------------------
void __usercall _Q_strcmp(int (*a1)(void)@<eax>, int a2@<edx>, char a3@<ch>, int a4@<ebx>, int a5@<ebp>, int a6@<edi>)
{
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // ecx

  *(_BYTE *)(a2 + 17) |= a3;
  v6 = (_DWORD *)a1();
  *(_DWORD *)a6 = v6;
  *v6 = a5;
  v7 = dword_3F66428C;
  *(_DWORD *)(*(_DWORD *)a6 + 4) = 0;
  v8 = dword_3F664280;
  for ( *(_DWORD *)(*(_DWORD *)a6 + 8) = a4; *(_BYTE *)(v7 + v8) == 32; v7 += a4 )
    ;
  dword_3F66428C = a4 + v7;
  JUMPOUT(0x3F615866);
}

//------------------------------------------------------------------------------
// Address: 0x3F6056D0
// Name: sub_3F6056D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_3F6056D0(_DWORD *a1)
{
  int v2; // edi
  int result; // eax
  bool v4; // sf
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // [esp+Ch] [ebp+4h]

  v2 = a1[8];
  if ( v2 != 0 )
  {
    result = -1;
    v4 = v2 - 1 < 0;
    v5 = v2 - 1;
    v8 = -1;
    if ( !v4 )
    {
      v6 = 124 * v5;
      do
      {
        if ( v5 < a1[8] && v5 >= 0 )
        {
          v7 = v6 + a1[1];
          if ( *(_DWORD *)(v7 + 116) != v5 || *(_DWORD *)(v7 + 120) == v5 )
            ((void (*)(void))loc_3F602850)();
        }
        *(_DWORD *)(v6 + a1[1] + 120) = v8;
        *(_DWORD *)(v6 + a1[1] + 116) = v5;
        v8 = v5--;
        v6 -= 124;
      }
      while ( v5 >= 0 );
      result = -1;
    }
    a1[6] = 0;
    a1[4] = -1;
    a1[5] = -1;
    a1[7] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F605750
// Name: sub_3F605750
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_3F605750@<eax>(int a1@<eax>, int a2)
{
  int v3; // esi
  int result; // eax

  if ( (unsigned __int8)((int (__thiscall *)(int))loc_3F605150)(a1: a2) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(elem)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
      a4: 407,
      a5: &unk_3F665742,
      a6: 0);
  ((void (*)(void))loc_3F605E70)();
  v3 = *(_DWORD *)(a2 + 4) + 124 * a1;
  ((void (*)(void))loc_3F602850)();
  result = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(v3 + 120) = result;
  *(_DWORD *)(a2 + 24) = a1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6057B0
// Name: sub_3F6057B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__usercall sub_3F6057B0@<eax>(_DWORD *result@<eax>)
{
  *result = 124;
  result[1] = 0;
  result[2] = 0;
  result[3] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F605810
// Name: sub_3F605810
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_3F605810@<eax>(_DWORD *a1@<eax>, int a2@<edi>, _DWORD *a3)
{
  unsigned int v4; // eax
  int v5; // ecx
  _DWORD *v6; // eax

  v4 = a1[1];
  if ( (unsigned int)a3 >= v4 && (unsigned int)a3 < v4 + 4 * a1[4] )
    AssertMsgImplementation(
      a1: "Assertion Failed: (&src < Base()) || (&src >= (Base() + Count()) )",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 639,
      a5: &unk_3F665744,
      a6: 0);
  if ( a2 != a1[4] && (unsigned __int8)sub_3F614FF0(a1) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: (elem == Count()) || IsValidIndex(elem)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 642,
      a5: &unk_3F665745,
      a6: 0);
  v5 = a1[2];
  if ( a1[4] + 1 > v5 )
    sub_3F626080(a1: v5);
  ++a1[4];
  ((void (__cdecl *)(int))loc_3F606050)(a1: a2);
  if ( (unsigned __int8)sub_3F614FF0(a1) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 306,
      a5: &unk_3F665743,
      a6: 0);
  v6 = (_DWORD *)(a1[1] + 4 * a2);
  if ( v6 != nullptr )
    *v6 = *a3;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F6059C0
// Name: sub_3F6059C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F6059C0@<eax>(int a1@<esi>)
{
  if ( (unsigned __int8)sub_3F605A00() == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 306,
      a5: &unk_3F665747,
      a6: 0);
  return dword_3F662AC8 + 4 * a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F605A00
// Name: sub_3F605A00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall sub_3F605A00@<eax>(int a1@<eax>)
{
  return a1 >= 0 && a1 < dword_3F662AD4;
}

//------------------------------------------------------------------------------
// Address: 0x3F605A20
// Name: sub_3F605A20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge sub_3F605A20@<eax>(int a1@<edi>, int a2)
{
  CThreadLocalPtr<CCoroutineMgr> *v2; // ecx
  _DWORD *v3; // eax
  int v5; // [esp-4h] [ebp-14h]
  _DWORD *retaddr; // [esp+10h] [ebp+0h]

  if ( (unsigned int)retaddr >= dword_3F662AC8 && (unsigned int)retaddr < dword_3F662AC8 + 4 * dword_3F662AD4 )
    AssertMsgImplementation(
      a1: "Assertion Failed: (&src < Base()) || (&src >= (Base() + Count()) )",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 639,
      a5: &unk_3F665748,
      a6: 0);
  if ( a1 != dword_3F662AD4 && !sub_3F605A00(a1) )
    AssertMsgImplementation(
      a1: "Assertion Failed: (elem == Count()) || IsValidIndex(elem)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 642,
      a5: &unk_3F665749,
      a6: 0);
  v2 = (CThreadLocalPtr<CCoroutineMgr> *)dword_3F662ACC;
  if ( dword_3F662AD4 + 1 > dword_3F662ACC )
    sub_3F626080(a1: dword_3F662ACC);
  ++dword_3F662AD4;
  CThreadLocalPtr<CCoroutineMgr>::operator!=(this: v2, i: v5);
  if ( !sub_3F605A00(a1) )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 306,
      a5: &unk_3F665747,
      a6: 0);
  v3 = (_DWORD *)(dword_3F662AC8 + 4 * a1);
  if ( v3 != nullptr )
    *v3 = *retaddr;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F605B60
// Name: sub_3F605B60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__stdcall sub_3F605B60(int a1)
{
  bool v1; // zf
  int v2; // eax
  void *result; // eax
  void *v4; // edi
  const void *v5; // ebp
  void *v6; // eax

  v1 = !sub_3F605A00(a1);
  v2 = dword_3F662AD4;
  if ( v1 && dword_3F662AD4 != 0 )
  {
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 561,
      a5: &unk_3F66574A,
      a6: 0);
    v2 = dword_3F662AD4;
  }
  result = (void *)(v2 - a1 - 1);
  v4 = result;
  if ( (int)result > 0 )
  {
    v5 = (const void *)sub_3F6059C0(a1: a1 + 1);
    v6 = (void *)sub_3F6059C0(a1);
    return memcpy_0(a1: v6, Src: v5, Size: 4 * (_DWORD)v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F605BE0
// Name: sub_3F605BE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *sub_3F605BE0()
{
  dword_3F662AC8 = 0;
  dword_3F662ACC = 0;
  dword_3F662AD0 = 0;
  dword_3F662AC4 = 4;
  return &dword_3F662AC4;
}

//------------------------------------------------------------------------------
// Address: 0x3F605C10
// Name: sub_3F605C10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F605C10()
{
  return dword_3F662AC8;
}

//------------------------------------------------------------------------------
// Address: 0x3F605C70
// Name: sub_3F605C70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__userpurge sub_3F605C70@<eax>(int a1@<esi>, int a2)
{
  void *result; // eax
  int v4; // edi
  int v5; // [esp+Ch] [ebp+4h]

  result = (void *)sub_3F614FF0(a1);
  if ( (_BYTE)result == 0 && *(_DWORD *)(a1 + 16) != 0 )
    result = (void *)AssertMsgImplementation(
                       a1: "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )",
                       a2: 0,
                       a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
                       a4: 552,
                       a5: &unk_3F66574C,
                       a6: 0);
  v4 = *(_DWORD *)(a1 + 16) - a2 - 1;
  if ( v4 > 0 )
  {
    if ( (unsigned __int8)sub_3F614FF0(a1) == 0 )
      AssertMsgImplementation(
        a1: "Assertion Failed: IsValidIndex(i)",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
        a4: 306,
        a5: &unk_3F66574B,
        a6: 0);
    v5 = *(_DWORD *)(a1 + 4);
    if ( (unsigned __int8)sub_3F614FF0(a1) == 0 )
      AssertMsgImplementation(
        a1: "Assertion Failed: IsValidIndex(i)",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
        a4: 306,
        a5: &unk_3F66574B,
        a6: 0);
    return memcpy_0(a1: (void *)(*(_DWORD *)(a1 + 4) + 12 * (a2 + 1)), Src: (const void *)(v5 + 12 * a2), Size: 12 * v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F605D70
// Name: sub_3F605D70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_3F605D70@<eax>(_DWORD *a1@<eax>, int a2, int a3)
{
  int v4; // edi
  int result; // eax
  int v6; // ebx
  int v7; // edi

  if ( (unsigned __int8)((int (__thiscall *)(_DWORD *))loc_3F605150)(a1) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(elem)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
      a4: 606,
      a5: &unk_3F66574D,
      a6: 0);
  ((void (*)(void))loc_3F605E70)();
  v4 = a1[1] + 124 * a3;
  *(_DWORD *)(v4 + 120) = a2;
  if ( a2 == -1 )
  {
    result = a1[5];
    *(_DWORD *)(v4 + 116) = result;
    a1[5] = a3;
  }
  else
  {
    if ( a2 >= a1[8] || a2 < 0 )
      goto LABEL_10;
    if ( (unsigned __int8)((int (__thiscall *)(_DWORD *))loc_3F605150)(a1) == 0 )
      AssertMsgImplementation(
        a1: "Assertion Failed: IsValidIndex(i)",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
        a4: 277,
        a5: &unk_3F665753,
        a6: 0);
    if ( *(_DWORD *)(124 * a2 + a1[1] + 116) == a2 )
LABEL_10:
      AssertMsgImplementation(
        a1: "Assertion Failed: IsInList(before)",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utllinkedlist.h",
        a4: 626,
        a5: &unk_3F66574E,
        a6: 0);
    v6 = a1[1] + 124 * a2;
    result = *(_DWORD *)(v6 + 116);
    *(_DWORD *)(v4 + 116) = result;
    *(_DWORD *)(v6 + 116) = a3;
  }
  v7 = *(_DWORD *)(v4 + 116);
  if ( v7 == -1 )
  {
    ++a1[7];
    a1[4] = a3;
  }
  else
  {
    *(_DWORD *)(124 * v7 + a1[1] + 120) = a3;
    ++a1[7];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6062B0
// Name: sub_3F6062B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F6062B0@<eax>(const char *a1@<eax>, const char *a2@<ecx>)
{
  return strcmp(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F6062E0
// Name: sub_3F6062E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F6062E0(CThreadMutex **a1@<eax>)
{
  CThreadMutex::Unlock(this: *a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F606310
// Name: sub_3F606310
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *sub_3F606310()
{
  void *VProfile; // eax
  struct CVProfile *v1; // edi
  _DWORD *v2; // ebx
  DWORD CurrentThreadId; // eax

  if ( CThreadLocalBase::Get(this: g_VProfile) == nullptr )
  {
    VProfile = (void *)CreateVProfile();
    CThreadLocalBase::Set(this: g_VProfile, a2: VProfile);
    v1 = (struct CVProfile *)CThreadLocalBase::Get(this: g_VProfile);
    v2 = CThreadLocalBase::Get(this: g_VProfile);
    CurrentThreadId = GetCurrentThreadId();
    v2[653] = CVProfManager::AddProfileForThread(this: g_VProfManager, a2: v1, a3: CurrentThreadId);
  }
  return CThreadLocalBase::Get(this: g_VProfile);
}

//------------------------------------------------------------------------------
// Address: 0x3F6068F0
// Name: sub_3F6068F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *sub_3F6068F0()
{
  dword_3F66587C = (int)&IDebugStatsSystem::`vftable';
  return &dword_3F66587C;
}

//------------------------------------------------------------------------------
// Address: 0x3F6069D0
// Name: sub_3F6069D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall sub_3F6069D0(_DWORD *this, void *Src)
{
  _DWORD *v3; // esi
  unsigned int v4; // kr00_4
  void *v5; // eax
  void *v6; // eax

  v3 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, void *))(*this + 12))(a1: this, a2: Src);
  if ( v3 == nullptr )
  {
    v3 = (_DWORD *)sub_3F609C70();
    v3[2] = 0;
    v3[3] = 0;
    v3[4] = 0;
    if ( Src != nullptr
      && (v4 = strlen((const char *)Src),
          (v5 = (void *)(*(int (__thiscall **)(_DWORD, unsigned int, const char *, int, _DWORD, _DWORD))(*g_pMemAllocSteam + 4))(
                          a1: g_pMemAllocSteam,
                          a2: v4 + 1,
                          a3: ".\\debugstatssystem.cpp",
                          a4: 125,
                          a5: 0,
                          a6: 0)) != nullptr) )
    {
      v6 = memcpy_1(a1: v5, Src, Size: v4 + 1);
    }
    else
    {
      v6 = nullptr;
    }
    *v3 = v6;
    v3[5] = *(this + 1);
    *(this + 1) = v3;
  }
  ++v3[4];
  return v3 + 2;
}

//------------------------------------------------------------------------------
// Address: 0x3F606A60
// Name: sub_3F606A60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall sub_3F606A60(_DWORD *this, int a2)
{
  int v2; // eax

  v2 = *(this + 1);
  if ( v2 == 0 )
    return 0;
  while ( a2 != v2 + 8 )
  {
    v2 = *(_DWORD *)(v2 + 20);
    if ( v2 == 0 )
      return 0;
  }
  --*(_DWORD *)(v2 + 16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F606A90
// Name: sub_3F606A90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F606A90(CValidator *a1)
{
  void **i; // esi

  if ( (dword_3F665884 & 1) == 0 )
  {
    dword_3F665884 |= 1u;
    dword_3F66587C = (int)&CDebugStatsSystem::`vftable';
    dword_3F665880 = 0;
    atexit_0(a1: sub_3F653B60);
  }
  for ( i = (void **)dword_3F665880; i != nullptr; i = (void **)i[5] )
  {
    CValidator::ClaimMemory(this: a1, a2: i);
    CValidator::ClaimMemory(this: a1, a2: *i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F606B00
// Name: sub_3F606B00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F606B00@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // esi
  int v3; // ebx
  int v4; // edi

  v2 = a1 >> 15;
  v3 = a1 & 0x7FFF;
  v4 = a2 + 12;
  if ( (unsigned __int8)sub_3F614FF0(a1: a2 + 12) == 0 )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      a4: 299,
      a5: &unk_3F665759,
      a6: 0);
  return v3 + *(_DWORD *)(*(_DWORD *)(v4 + 4) + 4 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x3F606B50
// Name: KeyValuesSystemSteam
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *KeyValuesSystemSteam()
{
  return &dword_3F6642E0;
}

//------------------------------------------------------------------------------
// Address: 0x3F607760
// Name: void Construct<class CCoroutine>(class CCoroutine __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Construct<CCoroutine>(void (__cdecl *a1)(const char *, _DWORD, const char *)@<ebp>)
{
  a1(
    a1: "Assertion Failed: IsValidIndex(i)",
    a2: 0,
    a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h");
  JUMPOUT(0x3F607776);
}

//------------------------------------------------------------------------------
// Address: 0x3F607780
// Name: void Destruct<class CCoroutine>(class CCoroutine __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F615870
// Name: __Q_wcscmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Q_wcscmp()
{
  JUMPOUT(0x3F615871);
}

} // namespace vstdlib_s
