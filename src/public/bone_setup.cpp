// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/bone_setup.cpp
// Functions: 7
// ============================================================

#include "public\bone_setup.h"

//------------------------------------------------------------------------------
// Address: 0x00403940
// Name: void SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SinCos(float radians, float *sine, float *cosine)
{
  *cosine = cos(radians);
  *sine = sin(radians);
}

//------------------------------------------------------------------------------
// Address: 0x00403960
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: HIDWORD(this->m_Head.value64) & 0xFFFF0000,
                            a4: Next,
                            a5: HIDWORD(this->m_Head.value64)) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004039A0
// Name: public: virtual void CDataManager<class CBoneCache,struct bonecacheparams_t,class CBoneCache __near *,class CThreadFastMutex>::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::Lock(
        CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex> *this)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004039E0
// Name: public: virtual bool CDataManager<class CBoneCache,struct bonecacheparams_t,class CBoneCache __near *,class CThreadFastMutex>::TryLock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::TryLock(
        CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex> *this)
{
  DWORD CurrentThreadId; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_mutex, CurrentThreadId, 0) != 0 )
  {
    return 0;
  }
  ++this->m_mutex.m_depth;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403A10
// Name: public: virtual void CDataManager<class CBoneCache,struct bonecacheparams_t,class CBoneCache __near *,class CThreadFastMutex>::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::Unlock(
        CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex> *this)
{
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)&this->m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x00403A60
// Name: private: virtual void CDataManager<class CBoneCache,struct bonecacheparams_t,class CBoneCache __near *,class CThreadFastMutex>::DestroyResourceStorage(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::DestroyResourceStorage(
        CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex> *this,
        void *pStore)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pStore);
}

//------------------------------------------------------------------------------
// Address: 0x00403A70
// Name: private: virtual unsigned int CDataManager<class CBoneCache,struct bonecacheparams_t,class CBoneCache __near *,class CThreadFastMutex>::GetRealSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::GetRealSize(
        CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex> *this,
        _DWORD *pStore)
{
  return pStore[2];
}
