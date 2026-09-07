// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/validator.cpp
// Functions: 17
// ============================================================

#include "tier0\validator.h"

//------------------------------------------------------------------------------
// Address: 0x3F009F70
// Name: public: CValidator::CValidator(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CValidator::CValidator(CValidator *this@<ecx>, int a2@<ebp>)
{
  CWorkerThread *v2; // ecx

  Error(a1: (int)"CatchAndWriteContext_t::Set w/o a function pointer!");
  CWorkerThread::Reply(this: v2, dw: a2 - 24);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A280
// Name: char __near * Q_pretifymem(float,int,bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall Q_pretifymem@<eax>(char *result@<eax>, char a2@<dh>, _BYTE *_EBX@<ebx>)
{
  *(_EBX - 998041880) += (_BYTE)result;
  BYTE1(_EBX) |= a2;
  __asm { fcomp   dword ptr [ebx] }
  *_EBX <<= 6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00A7F0
// Name: public: void CValidator::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CValidator::Validate(
        CValidator *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<ebx>,
        int a4@<ebp>,
        void *a5@<edi>,
        const void *a6@<esi>,
        CValidator *validator,
        char *pchName)
{
  int v8; // esi

  qmemcpy(a5, a6, 0x400u);
  a3[588] = *(_DWORD *)(a2 + 2352);
  qmemcpy(a3 + 589, (const void *)(a2 + 2356), 0x104u);
  *(_DWORD *)(a4 - 20) = a3 + 654;
  ((void (__cdecl *)(_DWORD *, int))loc_3F00C190)(a1: a3 + 654, a2: a2 + 2616);
  *(_DWORD *)(a4 - 4) = 1;
  v8 = *(_DWORD *)(a4 + 8);
  *(_DWORD *)(a4 - 20) = a3 + 657;
  sub_3F00C230(a1: a3 + 657, a2: v8 + 2628);
  *(_BYTE *)(a4 - 4) = 3;
  sub_3F00C2D0(a1: a3 + 660);
  *(_BYTE *)(a4 - 4) = 4;
  a3[664] = *(_DWORD *)(v8 + 2656);
  a3[665] = *(_DWORD *)(v8 + 2660);
  JUMPOUT(0x3F00A889);
}

//------------------------------------------------------------------------------
// Address: 0x3F011B70
// Name: public: void CValidator::Pop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValidator::Pop(CValidator *this)
{
  CValObject *m_pValObjectCur; // eax

  if ( *((_BYTE *)this + 2112) == 0 && BYTE1(this->m_threadMutexValidationLock[1]) == 0 )
  {
    if ( this->m_pValObjectCur == nullptr )
      ((void (__cdecl *)(errentry *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: &errtable[34],
        a2: 0,
        a3: &errtable[9],
        a4: 158,
        a5: &unk_3F041A88,
        a6: 0);
    m_pValObjectCur = this->m_pValObjectCur;
    this->m_pValObjectCur = m_pValObjectCur->m_pValObjectParent;
    if ( m_pValObjectCur->m_cubMemTree <= 0 )
      --this->m_cValObjectsUsed;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F011C10
// Name: public: void CValidator::ClaimMemory(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValidator::ClaimMemory(
        CValidator *this,
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *a2)
{
  if ( a2 == nullptr )
    goto LABEL_6;
  if ( *((_BYTE *)this + 2112) != 0 )
  {
    *((_QWORD *)this + 263) += (unsigned int)(*(int (__thiscall **)(int, std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *))(*(_DWORD *)g_pMemAllocSteam + 36))(
                                               a1: g_pMemAllocSteam,
                                               a2);
    return;
  }
  if ( BYTE1(this->m_threadMutexValidationLock[1]) != 0 )
LABEL_6:
    JUMPOUT(0x3F011C8B);
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::_Lrotate(
    (std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > *)this,
    _Wherenode: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F011EB0
// Name: public: void CValidator::RenderObjects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValidator::RenderObjects(
        CValidator *this,
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *a2)
{
  if ( *((_BYTE *)this + 2112) == 0 && BYTE1(this->m_threadMutexValidationLock[1]) == 0 )
  {
    if ( this->m_pValObjectFirst == nullptr )
      JUMPOUT(0x3F011F45);
    std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::_Lrotate(
      (std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > *)this,
      _Wherenode: a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F012140
// Name: public: class CValObject __near * CValidator::FindObject(void __near *)
// Source: json
//------------------------------------------------------------------------------
struct CValObject *__thiscall CValidator::FindObject(CValidator *this, void *a2)
{
  struct CValObject *result; // eax

  result = this->m_pValObjectFirst;
  if ( this->m_pValObjectFirst == nullptr )
    return nullptr;
  while ( a2 != result->m_pvObj )
  {
    result = result->m_pValObjectNext;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F012360
// Name: public: void CValidator::AddValidationLock(class CThreadMutex __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValidator::AddValidationLock(CValidator *this, struct CThreadMutex *lpCriticalSection)
{
  if ( *((_BYTE *)this + 2112) != 0 )
    ((void (__cdecl *)(const char *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: !m_bJustCount",
      a2: 0,
      a3: &errtable[9],
      a4: 683,
      a5: &unk_3F041A8B,
      a6: 0);
  if ( *((int *)this + 525) >= 512 )
    ((void (__cdecl *)(void *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &unk_3F032A00,
      a2: 0,
      a3: &errtable[9],
      a4: 684,
      a5: &unk_3F041A8C,
      a6: 0);
  this->m_threadMutexValidationLock[(*((_DWORD *)this + 525))++ + 2] = lpCriticalSection;
  EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F0123F0
// Name: public: void CValidator::UnlockValidationLocks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValidator::UnlockValidationLocks(CValidator *this)
{
  int v2; // esi
  LPCRITICAL_SECTION *v3; // edi

  if ( *((_BYTE *)this + 2112) != 0 )
    ((void (__cdecl *)(const char *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: !m_bJustCount",
      a2: 0,
      a3: &errtable[9],
      a4: 696,
      a5: &unk_3F041A8D,
      a6: 0);
  v2 = 0;
  if ( *((int *)this + 525) <= 0 )
  {
    *((_DWORD *)this + 525) = 0;
  }
  else
  {
    v3 = (LPCRITICAL_SECTION *)&this->m_threadMutexValidationLock[2];
    do
    {
      LeaveCriticalSection(lpCriticalSection: *v3);
      ++v2;
      ++v3;
    }
    while ( v2 < *((_DWORD *)this + 525) );
    *((_DWORD *)this + 525) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00A290
// Name: Plat_timegm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void Plat_timegm()
{
  JUMPOUT(0x3F01CE8E);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A2A0
// Name: Plat_localtime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Plat_localtime(int a1, int a2)
{
  return ((int (__cdecl *)(int, int))loc_3F01CE9B)(a1: a2, a2: a1) != 22 ? a2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F012460
// Name: sub_3F012460
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_3F012460@<eax>(int result@<eax>, int a2@<ecx>, int a3@<esi>, int a4, int a5, int a6)
{
  *(_DWORD *)a3 = a2;
  *(_DWORD *)(a3 + 36) = 0;
  *(_DWORD *)(a3 + 8) = a4;
  *(_DWORD *)(a3 + 4) = a5;
  *(_DWORD *)(a3 + 12) = result;
  if ( result != 0 )
    *(_WORD *)(a3 + 40) = *(_WORD *)(result + 40) + 1;
  else
    *(_WORD *)(a3 + 40) = 0;
  *(_DWORD *)(a3 + 20) = 0;
  *(_DWORD *)(a3 + 24) = 0;
  *(_DWORD *)(a3 + 28) = 0;
  *(_DWORD *)(a3 + 32) = 0;
  if ( a6 != 0 )
  {
    if ( *(_DWORD *)(a6 + 16) != 0 )
      result = ((int (__cdecl *)(__int64 *, _DWORD, void **, int, void *, _DWORD))AssertMsgImplementation)(
                 a1: &__badioinfo.startpos,
                 a2: 0,
                 a3: &__badioinfo.lock.OwningThread,
                 a4: 48,
                 a5: &unk_3F041A8E,
                 a6: 0);
    *(_DWORD *)(a6 + 16) = a3;
  }
  *(_DWORD *)(a3 + 16) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0124D0
// Name: sub_3F0124D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_3F0124D0@<al>(_DWORD *a1@<eax>, int a2@<edx>, int a3@<edi>)
{
  int v4; // eax
  int v5; // ecx
  _DWORD *v7; // esi
  int v8; // eax

  v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)g_pMemAllocSteam + 36))(a1: g_pMemAllocSteam, a2);
  v5 = v4;
  if ( a3 != 0 && a3 != v4 )
    return 0;
  ++a1[5];
  a1[6] += v4;
  ++a1[7];
  a1[8] += v4;
  v7 = (_DWORD *)a1[3];
  if ( v7 != nullptr )
  {
    v8 = v7[3];
    ++v7[7];
    v7[8] += v5;
    if ( v8 != 0 )
      sub_3F012520(a1: v5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F012520
// Name: sub_3F012520
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__usercall sub_3F012520@<eax>(_DWORD *a1@<eax>, int a2@<ecx>)
{
  _DWORD *result; // eax
  _DWORD *v3; // eax

  a1[8] += a2;
  ++a1[7];
  for ( result = a1 + 3; *result != 0; result = v3 + 3 )
  {
    v3 = (_DWORD *)*result;
    ++v3[7];
    v3[8] += a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F012550
// Name: sub_3F012550
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 sub_3F012550()
{
  DWORD CurrentThreadId; // esi
  int v1; // eax
  _DWORD *v2; // ecx

  CurrentThreadId = GetCurrentThreadId();
  v1 = 0;
  if ( dword_3F03D404 <= 0 )
  {
LABEL_5:
    Error(a1: (int)&rterrs[5].rterrtxt);
    LOWORD(v1) = 0;
  }
  else
  {
    v2 = (_DWORD *)dword_3F03D400;
    while ( *v2 != CurrentThreadId )
    {
      ++v1;
      v2 += 3;
      if ( v1 >= dword_3F03D404 )
        goto LABEL_5;
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F012590
// Name: sub_3F012590
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__usercall sub_3F012590@<eax>(_BYTE *a1@<esi>)
{
  size_t v1; // eax
  bool v2; // zf
  unsigned __int16 v4; // ax

  v1 = ElementSize;
  v2 = ElementSize == 1;
  *a1 = 0;
  if ( v2 )
  {
    EnterCriticalSection(lpCriticalSection: &stru_3F03D328);
    return a1;
  }
  else
  {
    if ( v1 == 2 )
    {
      v4 = sub_3F012550();
      WaitForSingleObject(hHandle: *(HANDLE *)(dword_3F03D400 + 12 * v4 + 4), dwMilliseconds: 0xFFFFFFFF);
    }
    return a1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0125E0
// Name: sub_3F0125E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F0125E0(_BYTE *a1)
{
  if ( ElementSize == 1 )
  {
    LeaveCriticalSection(lpCriticalSection: &stru_3F03D328);
  }
  else if ( ElementSize == 2 && *a1 == 0 )
  {
    ((void (*)(void))loc_3F0126F0)();
  }
}
