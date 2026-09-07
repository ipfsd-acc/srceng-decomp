// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmatqueuedrendercontext.cpp
// Functions: 343
// ============================================================

#include "materialsystem\cmatqueuedrendercontext.h"

//------------------------------------------------------------------------------
// Address: 0x1001B9A0
// Name: public: virtual void CMemberFunctor2<class CMaterial __near *,void (CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, MaterialVarFlags_t, bool))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x1001BA50
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterial __near *,class CMaterial,void>(class CMaterial __near *,void (CMaterial::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterial *,CMaterial,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterial *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1001BAD0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterial __near *,class CMaterial,void,enum MaterialVarFlags_t,bool,enum MaterialVarFlags_t,bool>(class CMaterial __near *,void (CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterial *,CMaterial,void,enum MaterialVarFlags_t,bool,enum MaterialVarFlags_t,bool>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterial *pObject,
        __int128 pfnProxied,
        const MaterialVarFlags_t *arg1,
        const bool *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const MaterialVarFlags_t *v11; // ecx
  __int64 v12; // xmm0_8
  const bool *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((MaterialVarFlags_t *)m_pNextAlloc + 10) = *v11;
  m_pNextAlloc[44] = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1001BB60
// Name: public: void CMatCallQueue::QueueCall<class CMaterial __near *,class CMaterial,void>(class CMaterial __near *,void (CMaterial::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterial *,CMaterial,void>(
        CMatCallQueue *this,
        CMaterial *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterial *,CMaterial,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001BBF0
// Name: public: void CMatCallQueue::QueueCall<class CMaterial __near *,class CMaterial,void,enum MaterialVarFlags_t,bool,enum MaterialVarFlags_t,bool>(class CMaterial __near *,void (CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterial *,CMaterial,void,enum MaterialVarFlags_t,bool,enum MaterialVarFlags_t,bool>(
        CMatCallQueue *this,
        CMaterial *pObject,
        __int128 pfnProxied,
        const MaterialVarFlags_t *arg1,
        const bool *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterial *,CMaterial,void,enum MaterialVarFlags_t,bool,enum MaterialVarFlags_t,bool>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001E1E0
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1> __near *,void (CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1001E210
// Name: public: virtual void CMemberFunctor3<class IMaterialInternal __near *,void (IMaterial::*)(float,float,float),float,float,float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<IMaterialInternal *,void (__thiscall IMaterial::*)(float,float,float),float,float,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(IMaterialInternal *, _DWORD, _DWORD, _DWORD))this->m_Proxy.m_pfnProxied)(
    a1: this->m_Proxy.m_pObject,
    a2: LODWORD(this->m_arg1),
    a3: LODWORD(this->m_arg2),
    a4: LODWORD(this->m_arg3));
}

//------------------------------------------------------------------------------
// Address: 0x1001E240
// Name: public: virtual void CMemberFunctor2<class IMaterialInternal __near *,void (IMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<IMaterialInternal *,void (__thiscall IMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<IMaterialInternal *,void (__thiscall IMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1, a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x10026790
// Name: public: virtual void CMemberFunctor0<class IShaderAPI __near *,void (IShaderAPI::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x10027D40
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IShaderAPI __near *,class IShaderAPI,void>(class IShaderAPI __near *,void (IShaderAPI::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IShaderAPI *,IShaderAPI,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IShaderAPI *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x100294A0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateRefCountingFunctor<class CFunctor __near *,class CFunctor,void>(class CFunctor __near *,void (CFunctor::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateRefCountingFunctor<CFunctor *,CFunctor,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CFunctor *pObject,
        void (__thiscall *pfnProxied)(CFunctor *this))
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // ebx
  int v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // esi
  CFunctor *result; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 24;
  if ( m_alignment >= 0x18 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 <= m_pAllocator->m_pCommitLimit || CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v7]) )
  {
    m_pAllocator->m_pNextAlloc = v8;
    v9 = m_pNextAlloc;
  }
  else
  {
    v9 = nullptr;
  }
  result = nullptr;
  if ( v9 != nullptr )
  {
    *((_DWORD *)v9 + 3) = 1;
    *(_DWORD *)v9 = &CMemberFunctor0<CFunctor *,void (__thiscall CFunctor::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyRefCount<CFunctor *>>::`vftable'{for `CFunctor'};
    *((_DWORD *)v9 + 2) = &CMemberFunctor0<CFunctor *,void (__thiscall CFunctor::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyRefCount<CFunctor *>>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
    *((_DWORD *)v9 + 4) = pfnProxied;
    *((_DWORD *)v9 + 5) = pObject;
    pObject->AddRef(this: pObject);
    return (CFunctor *)v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029550
// Name: public: void CMatCallQueue::QueueCall<class IShaderAPI __near *,class IShaderAPI,void>(class IShaderAPI __near *,void (IShaderAPI::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IShaderAPI *,IShaderAPI,void>(
        CMatCallQueue *this,
        IShaderAPI *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IShaderAPI *,IShaderAPI,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002B600
// Name: public: virtual void CMemberFunctor2<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(float,float),float,float,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, _DWORD, _DWORD))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: LODWORD(this->m_arg1),
    a3: LODWORD(this->m_arg2));
}

//------------------------------------------------------------------------------
// Address: 0x1002B630
// Name: public: virtual void CMemberFunctor3<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, _DWORD, _DWORD, _DWORD))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x1002B650
// Name: public: virtual void CMemberFunctor4<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,unsigned char,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, _DWORD, _DWORD, _DWORD, _DWORD))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x1002B680
// Name: public: virtual void CMemberFunctor2<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(bool,bool),bool,bool,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, bool, bool))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x1002B6F0
// Name: public: virtual void CMemberFunctor2<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,float),int,float,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,float),int,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,float),unsigned int,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, unsigned int, _DWORD))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: LODWORD(this->m_arg2));
}

//------------------------------------------------------------------------------
// Address: 0x1002B740
// Name: public: virtual void CMemberFunctor3<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near *),struct FlashlightState_t,class VMatrix,class ITexture __near *,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &,ITexture *),FlashlightState_t,VMatrix,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &,ITexture *),FlashlightState_t,VMatrix,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, FlashlightState_t *, VMatrix *, ITexture *))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: &this->m_arg1,
    a3: &this->m_arg2,
    a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x1002B7C0
// Name: public: virtual void CMemberFunctor4<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,float,float,float),class ITexture __near *,float,float,float,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float),ITexture *,float,float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float),ITexture *,float,float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, ITexture *, _DWORD, _DWORD, _DWORD))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: LODWORD(this->m_arg2),
    a4: LODWORD(this->m_arg3),
    a5: LODWORD(this->m_arg4));
}

//------------------------------------------------------------------------------
// Address: 0x1002B800
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,bool,bool>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const bool *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const bool *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  m_pNextAlloc[40] = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002B890
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContextInternal,void>(class CMatRenderContextBase __near *,void (IMatRenderContextInternal::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContextInternal,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002B910
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,class ITexture __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *),class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  ITexture *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *),ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((ITexture **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002B9A0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int),int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const int *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((_DWORD *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BA30
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,float,float,float,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(float,float),float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,float,float,float,float>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        float *arg1,
        float *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  float *v11; // ecx
  float *v12; // edx
  __int64 v13; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  v12 = arg2;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  *((float *)m_pNextAlloc + 10) = *v11;
  *((float *)m_pNextAlloc + 11) = *v12;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BAC0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,bool,bool,bool,bool,bool,bool>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(bool,bool,bool),bool const __near &,bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool,bool,bool>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const bool *arg1,
        const bool *arg2,
        const bool *arg3)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v8; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v10; // eax
  unsigned __int8 *v11; // ebx
  const bool *v12; // ecx
  __int64 v13; // xmm0_8
  const bool *v14; // eax
  const bool *v15; // edx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v8 = 48;
  if ( m_alignment >= 0x30 )
    v8 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v10 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v11 = &m_pAllocator->m_pNextAlloc[v10];
  if ( v11 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v10]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v11;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v12 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(bool,bool,bool),bool,bool,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(bool,bool,bool),bool,bool,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v14 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  m_pNextAlloc[40] = *v12;
  v15 = arg3;
  m_pNextAlloc[41] = *v14;
  m_pNextAlloc[42] = *v15;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BB60
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,int,class ITexture __near *,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,int),class ITexture __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,ITexture *,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        const int *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  ITexture *const *v11; // ecx
  __int64 v12; // xmm0_8
  const int *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((ITexture **)m_pNextAlloc + 10) = *v11;
  *((_DWORD *)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BBF0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialCullMode_t,enum MaterialCullMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialCullMode_t),enum MaterialCullMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialCullMode_t,enum MaterialCullMode_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialCullMode_t *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const MaterialCullMode_t *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialCullMode_t),enum MaterialCullMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialCullMode_t),enum MaterialCullMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((MaterialCullMode_t *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BC80
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BD00
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMesh __near *,class IMesh __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMesh __near *),class IMesh __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMesh *,IMesh *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  IMesh *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),IMesh *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),IMesh *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((IMesh **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BD90
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char const __near &,unsigned char const __near &,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const unsigned __int8 *arg1,
        const unsigned __int8 *arg2,
        const unsigned __int8 *arg3)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v8; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v10; // eax
  unsigned __int8 *v11; // ebx
  const unsigned __int8 *v12; // ecx
  __int64 v13; // xmm0_8
  const unsigned __int8 *v14; // eax
  const unsigned __int8 *v15; // edx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v8 = 48;
  if ( m_alignment >= 0x30 )
    v8 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v10 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v11 = &m_pAllocator->m_pNextAlloc[v10];
  if ( v11 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v10]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v11;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v12 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v14 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  m_pNextAlloc[40] = *v12;
  v15 = arg3;
  m_pNextAlloc[41] = *v14;
  m_pNextAlloc[42] = *v15;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BE30
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),unsigned char const __near &,unsigned char const __near &,unsigned char const __near &,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const unsigned __int8 *arg1,
        const unsigned __int8 *arg2,
        const unsigned __int8 *arg3,
        const unsigned __int8 *arg4)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v9; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  const unsigned __int8 *v13; // ecx
  __int64 v14; // xmm0_8
  const unsigned __int8 *v15; // eax
  const unsigned __int8 *v16; // edx
  const unsigned __int8 *v17; // ecx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v9 = 48;
  if ( m_alignment >= 0x30 )
    v9 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v11 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v12 = &m_pAllocator->m_pNextAlloc[v11];
  if ( v12 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v11]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v12;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v13 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),unsigned char,unsigned char,unsigned char,unsigned char,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v14 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v15 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v14;
  m_pNextAlloc[40] = *v13;
  v16 = arg3;
  m_pNextAlloc[41] = *v15;
  v17 = arg4;
  m_pNextAlloc[42] = *v16;
  m_pNextAlloc[43] = *v17;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BED0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,bool,bool,bool,bool>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(bool,bool),bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const bool *arg1,
        const bool *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const bool *v11; // ecx
  __int64 v12; // xmm0_8
  const bool *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  m_pNextAlloc[40] = *v11;
  m_pNextAlloc[41] = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BF60
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMaterial __near *,class IMaterial __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *),class IMaterial __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,IMaterial *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterial *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  IMaterial *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((IMaterial **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002BFF0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct OcclusionQueryObjectHandle_t__ __near *,struct OcclusionQueryObjectHandle_t__ __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct OcclusionQueryObjectHandle_t__ __near *),struct OcclusionQueryObjectHandle_t__ __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        OcclusionQueryObjectHandle_t__ *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  OcclusionQueryObjectHandle_t__ *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((OcclusionQueryObjectHandle_t__ **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C080
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialHeightClipMode_t,enum MaterialHeightClipMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialHeightClipMode_t),enum MaterialHeightClipMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialHeightClipMode_t,enum MaterialHeightClipMode_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialHeightClipMode_t *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const MaterialHeightClipMode_t *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialHeightClipMode_t),enum MaterialHeightClipMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialHeightClipMode_t),enum MaterialHeightClipMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((MaterialHeightClipMode_t *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C110
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,float,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(float),float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        float *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  float *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((float *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C1A0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMorph __near *,class IMorph __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMorph __near *),class IMorph __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMorph *,IMorph *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMorph *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  IMorph *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((IMorph **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C230
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,int,int,int,int,class ITexture __near *,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,int,int,int,int),class ITexture __near * const __near &,int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,int,int,int,ITexture *,int,int,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        const int *arg2,
        const int *arg3,
        const int *arg4,
        const int *arg5)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v11; // eax
  int v12; // eax
  unsigned __int8 *v13; // ebx
  ITexture *const *v14; // ecx
  __int64 v15; // xmm0_8
  const int *v16; // eax
  const int *v17; // edx
  const int *v18; // ecx
  const int *v19; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v11 = 64;
  if ( m_alignment >= 0x40 )
    v11 = m_alignment;
  v12 = ~(m_alignment - 1) & (m_alignment + v11 - 1);
  v13 = &m_pNextAlloc[v12];
  if ( &m_pNextAlloc[v12] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v12]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v13;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v14 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,int,int,int),ITexture *,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,int,int,int),ITexture *,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v15 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v16 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v15;
  *((ITexture **)m_pNextAlloc + 10) = *v14;
  v17 = arg3;
  *((_DWORD *)m_pNextAlloc + 11) = *v16;
  v18 = arg4;
  *((_DWORD *)m_pNextAlloc + 12) = *v17;
  v19 = arg5;
  *((_DWORD *)m_pNextAlloc + 13) = *v18;
  *((_DWORD *)m_pNextAlloc + 14) = *v19;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C2E0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,class ITexture __near *,int,int,int,int,class ITexture __near *,class ITexture __near *,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,class ITexture __near *,int,int,int,int),class ITexture __near * const __near &,class ITexture __near * const __near &,int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *,int,int,int,int,ITexture *,ITexture *,int,int,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        ITexture *const *arg2,
        const int *arg3,
        const int *arg4,
        const int *arg5,
        const int *arg6)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v12; // eax
  int v13; // eax
  unsigned __int8 *v14; // ebx
  ITexture *const *v15; // ecx
  __int64 v16; // xmm0_8
  ITexture *const *v17; // eax
  const int *v18; // edx
  const int *v19; // ecx
  const int *v20; // eax
  const int *v21; // edx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v12 = 64;
  if ( m_alignment >= 0x40 )
    v12 = m_alignment;
  v13 = ~(m_alignment - 1) & (m_alignment + v12 - 1);
  v14 = &m_pNextAlloc[v13];
  if ( &m_pNextAlloc[v13] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v13]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v14;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v15 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor6<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,ITexture *,int,int,int,int),ITexture *,ITexture *,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor6<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,ITexture *,int,int,int,int),ITexture *,ITexture *,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v16 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v17 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v16;
  *((ITexture **)m_pNextAlloc + 10) = *v15;
  v18 = arg3;
  *((ITexture **)m_pNextAlloc + 11) = *v17;
  v19 = arg4;
  *((_DWORD *)m_pNextAlloc + 12) = *v18;
  v20 = arg5;
  *((_DWORD *)m_pNextAlloc + 13) = *v19;
  v21 = arg6;
  *((_DWORD *)m_pNextAlloc + 14) = *v20;
  *((_DWORD *)m_pNextAlloc + 15) = *v21;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C390
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,float,int,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,float),int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,float,int,float>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        float *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const int *v11; // ecx
  __int64 v12; // xmm0_8
  float *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,float),int,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,float),int,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((float *)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C420
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,int),int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const int *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const int *v11; // ecx
  __int64 v12; // xmm0_8
  const int *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((_DWORD *)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C4B0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,class ITexture __near *,int,class ITexture __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,class ITexture __near *),int const __near &,class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,ITexture *,int,ITexture *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        ITexture *const *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const int *v11; // ecx
  __int64 v12; // xmm0_8
  ITexture *const *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,ITexture *),int,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,ITexture *),int,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((ITexture **)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C540
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,class Vector const __near &,int,class Vector>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,class Vector const __near &),int const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,Vector const &,int,Vector>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const Vector *arg2)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // ebx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = 56;
  if ( m_alignment >= 0x38 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &m_pNextAlloc[v9];
  if ( &m_pNextAlloc[v9] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,Vector const &),int,Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,Vector const &),int,Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 10) = *arg1;
  *(Vector *)(m_pNextAlloc + 44) = *arg2;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C5E0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct ShaderStencilState_t const __near &,struct ShaderStencilState_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct ShaderStencilState_t const __near &),struct ShaderStencilState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ShaderStencilState_t const &,ShaderStencilState_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const ShaderStencilState_t *arg1)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // ebx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 72;
  if ( m_alignment >= 0x48 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ShaderStencilState_t const &),ShaderStencilState_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ShaderStencilState_t const &),ShaderStencilState_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = *((_QWORD *)&pfnProxied + 1);
  *(ShaderStencilState_t *)(m_pNextAlloc + 40) = *arg1;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C690
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,int,int,int,int,int,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,int,int,int,int),int const __near &,int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const int *arg2,
        const int *arg3,
        const int *arg4,
        const int *arg5)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v11; // eax
  int v12; // eax
  unsigned __int8 *v13; // ebx
  const int *v14; // ecx
  __int64 v15; // xmm0_8
  const int *v16; // eax
  const int *v17; // edx
  const int *v18; // ecx
  const int *v19; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v11 = 64;
  if ( m_alignment >= 0x40 )
    v11 = m_alignment;
  v12 = ~(m_alignment - 1) & (m_alignment + v11 - 1);
  v13 = &m_pNextAlloc[v12];
  if ( &m_pNextAlloc[v12] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v12]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v13;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v14 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int,int),int,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int,int),int,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v15 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v16 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v15;
  *((_DWORD *)m_pNextAlloc + 10) = *v14;
  v17 = arg3;
  *((_DWORD *)m_pNextAlloc + 11) = *v16;
  v18 = arg4;
  *((_DWORD *)m_pNextAlloc + 12) = *v17;
  v19 = arg5;
  *((_DWORD *)m_pNextAlloc + 13) = *v18;
  *((_DWORD *)m_pNextAlloc + 14) = *v19;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C740
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,float const __near *,float const __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(float const __near *),float const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,float const *,float const *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const float *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const float *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float const *),float const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float const *),float const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((const float **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C7D0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near *,struct FlashlightState_t,class VMatrix,class ITexture __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near *),struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,FlashlightState_t const &,VMatrix const &,ITexture *,FlashlightState_t,VMatrix,ITexture *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const FlashlightState_t *arg1,
        const VMatrix *arg2,
        ITexture *const *arg3)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // ebx
  int v9; // eax
  int v10; // eax
  unsigned __int8 *v11; // edi
  const FlashlightState_t *v12; // esi
  __int64 v13; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = 360;
  if ( m_alignment >= 0x168 )
    v9 = m_alignment;
  v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v11 = &m_pNextAlloc[v10];
  if ( &m_pNextAlloc[v10] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v10]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v11;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v12 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &,ITexture *),FlashlightState_t,VMatrix,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &,ITexture *),FlashlightState_t,VMatrix,ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  qmemcpy(m_pNextAlloc + 40, v12, 0xFCu);
  qmemcpy(m_pNextAlloc + 292, arg2, 0x40u);
  *((ITexture **)m_pNextAlloc + 89) = *arg3;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C880
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,int,int,int,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,int,int,int),int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const int *arg2,
        const int *arg3,
        const int *arg4)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v9; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  const int *v13; // ecx
  __int64 v14; // xmm0_8
  const int *v15; // eax
  const int *v16; // edx
  const int *v17; // ecx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v9 = 56;
  if ( m_alignment >= 0x38 )
    v9 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v11 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v12 = &m_pAllocator->m_pNextAlloc[v11];
  if ( v12 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v11]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v12;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v13 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int),int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int),int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v14 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v15 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v14;
  *((_DWORD *)m_pNextAlloc + 10) = *v13;
  v16 = arg3;
  *((_DWORD *)m_pNextAlloc + 11) = *v15;
  v17 = arg4;
  *((_DWORD *)m_pNextAlloc + 12) = *v16;
  *((_DWORD *)m_pNextAlloc + 13) = *v17;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C920
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,unsigned long,char const __near *,unsigned long,char const __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(unsigned long,char const __near *),unsigned long const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,unsigned long,char const *,unsigned long,char const *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const unsigned int *arg1,
        const char *const *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const unsigned int *v11; // ecx
  __int64 v12; // xmm0_8
  const char *const *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned long,char const *),unsigned long,char const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(unsigned long,char const *),unsigned long,char const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((const char **)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002C9B0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContextInternal,void,class IMaterialInternal __near *,class IMaterialInternal __near *>(class CMatRenderContextBase __near *,void (IMatRenderContextInternal::*)(class IMaterialInternal __near *),class IMaterialInternal __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContextInternal,void,IMaterialInternal *,IMaterialInternal *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterialInternal *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  IMaterialInternal *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((IMaterialInternal **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CA40
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContextInternal,void,void __near *,void __near *>(class CMatRenderContextBase __near *,void (IMatRenderContextInternal::*)(void __near *),void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContextInternal,void,void *,void *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        void *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  void *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void *),void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void *),void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((void **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CAD0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IColorCorrectionSystem __near *,class IColorCorrectionSystem,void,bool,bool>(class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IColorCorrectionSystem *,IColorCorrectionSystem,void,bool,bool>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IColorCorrectionSystem *pObject,
        __int128 pfnProxied,
        const bool *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const bool *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  m_pNextAlloc[40] = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CB60
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IColorCorrectionSystem __near *,class IColorCorrectionSystem,void>(class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IColorCorrectionSystem *,IColorCorrectionSystem,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IColorCorrectionSystem *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CBE0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IColorCorrectionSystem __near *,class IColorCorrectionSystem,void,unsigned int,float,unsigned int,float>(class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(unsigned int,float),unsigned int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IColorCorrectionSystem *,IColorCorrectionSystem,void,unsigned int,float,unsigned int,float>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IColorCorrectionSystem *pObject,
        __int128 pfnProxied,
        const unsigned int *arg1,
        float *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const unsigned int *v11; // ecx
  __int64 v12; // xmm0_8
  float *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,float),unsigned int,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,float),unsigned int,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((float *)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CC70
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IColorCorrectionSystem __near *,class IColorCorrectionSystem,void,unsigned int,bool,unsigned int,bool>(class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(unsigned int,bool),unsigned int const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IColorCorrectionSystem *,IColorCorrectionSystem,void,unsigned int,bool,unsigned int,bool>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IColorCorrectionSystem *pObject,
        __int128 pfnProxied,
        const unsigned int *arg1,
        const bool *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const unsigned int *v11; // ecx
  __int64 v12; // xmm0_8
  const bool *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,bool),unsigned int,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(unsigned int,bool),unsigned int,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  m_pNextAlloc[44] = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CD00
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class Vector const __near &,class Vector>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class Vector const __near &),class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,Vector const &,Vector>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const Vector *arg1)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // ebx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 56;
  if ( m_alignment >= 0x38 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector const &),Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector const &),Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = *((_QWORD *)&pfnProxied + 1);
  *(Vector *)(m_pNextAlloc + 40) = *arg1;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CD90
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,float,float,float,float,class ITexture __near *,float,float,float,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,float,float,float,float),class ITexture __near * const __near &,float const __near &,float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,float,float,float,float,ITexture *,float,float,float,float>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        float *arg2,
        float *arg3,
        float *arg4,
        float *arg5)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v11; // eax
  int v12; // eax
  unsigned __int8 *v13; // ebx
  ITexture *const *v14; // ecx
  __int64 v15; // xmm0_8
  float *v16; // eax
  ITexture *v17; // edx
  float *v18; // ecx
  float *v19; // edx
  float *v20; // eax
  double v21; // st7

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v11 = 64;
  if ( m_alignment >= 0x40 )
    v11 = m_alignment;
  v12 = ~(m_alignment - 1) & (m_alignment + v11 - 1);
  v13 = &m_pNextAlloc[v12];
  if ( &m_pNextAlloc[v12] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v12]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v13;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v14 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v15 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v16 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v15;
  v17 = *v14;
  v18 = arg3;
  *((_DWORD *)m_pNextAlloc + 10) = v17;
  v19 = arg4;
  *((float *)m_pNextAlloc + 11) = *v16;
  v20 = arg5;
  *((float *)m_pNextAlloc + 12) = *v18;
  *((float *)m_pNextAlloc + 13) = *v19;
  v21 = *v20;
  *((float *)m_pNextAlloc + 14) = v21;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CE40
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,float,float,float,class ITexture __near *,float,float,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,float,float,float),class ITexture __near * const __near &,float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,float,float,float,ITexture *,float,float,float>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        float *arg2,
        float *arg3,
        float *arg4)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v9; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  ITexture *const *v13; // ecx
  __int64 v14; // xmm0_8
  float *v15; // eax
  ITexture *v16; // edx
  float *v17; // ecx
  float *v18; // edx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v9 = 56;
  if ( m_alignment >= 0x38 )
    v9 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v11 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v12 = &m_pAllocator->m_pNextAlloc[v11];
  if ( v12 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v11]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v12;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v13 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float),ITexture *,float,float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float),ITexture *,float,float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v14 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v15 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v14;
  v16 = *v13;
  v17 = arg3;
  *((_DWORD *)m_pNextAlloc + 10) = v16;
  v18 = arg4;
  *((float *)m_pNextAlloc + 11) = *v15;
  *((float *)m_pNextAlloc + 12) = *v17;
  *((float *)m_pNextAlloc + 13) = *v18;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CEE0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,enum MaterialNonInteractiveMode_t,class ITexture __near *,enum MaterialNonInteractiveMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,enum MaterialNonInteractiveMode_t),class ITexture __near * const __near &,enum MaterialNonInteractiveMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,enum MaterialNonInteractiveMode_t,ITexture *,enum MaterialNonInteractiveMode_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        const MaterialNonInteractiveMode_t *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  ITexture *const *v11; // ecx
  __int64 v12; // xmm0_8
  const MaterialNonInteractiveMode_t *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,enum MaterialNonInteractiveMode_t),ITexture *,enum MaterialNonInteractiveMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,enum MaterialNonInteractiveMode_t),ITexture *,enum MaterialNonInteractiveMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((ITexture **)m_pNextAlloc + 10) = *v11;
  *((MaterialNonInteractiveMode_t *)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002CF70
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialNonInteractiveMode_t,enum MaterialNonInteractiveMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialNonInteractiveMode_t,enum MaterialNonInteractiveMode_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialNonInteractiveMode_t *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const MaterialNonInteractiveMode_t *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((MaterialNonInteractiveMode_t *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1002D000
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,bool,bool>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const bool *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D090
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContextInternal,void>(class CMatRenderContextBase __near *,void (IMatRenderContextInternal::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContextInternal,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D120
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,class ITexture __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *),class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D1B0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int),int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D240
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,float,float,float,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(float,float),float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float,float,float>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        float *arg1,
        float *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,float,float,float,float>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D2E0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,bool,bool,bool,bool,bool,bool>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(bool,bool,bool),bool const __near &,bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool,bool,bool>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const bool *arg1,
        const bool *arg2,
        const bool *arg3)
{
  unsigned int m_alignment; // eax
  int v8; // ecx
  int v9; // ecx
  unsigned __int8 *v10; // edi
  CFunctor *v11; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v8 = 4;
  if ( m_alignment >= 4 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &this->m_Allocator.m_pNextAlloc[v9];
  if ( v10 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v9]) )
  {
    this->m_Allocator.m_pNextAlloc = v10;
  }
  v11 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool,bool,bool>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v11[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D380
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,int,class ITexture __near *,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,int),class ITexture __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,ITexture *,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        const int *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,ITexture *,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D420
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialCullMode_t,enum MaterialCullMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialCullMode_t),enum MaterialCullMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialCullMode_t,enum MaterialCullMode_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialCullMode_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialCullMode_t,enum MaterialCullMode_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D4B0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D540
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMesh __near *,class IMesh __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMesh __near *),class IMesh __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMesh *,IMesh *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMesh *,IMesh *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D5D0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(unsigned char,unsigned char,unsigned char),unsigned char const __near &,unsigned char const __near &,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const unsigned __int8 *arg1,
        const unsigned __int8 *arg2,
        const unsigned __int8 *arg3)
{
  unsigned int m_alignment; // eax
  int v8; // ecx
  int v9; // ecx
  unsigned __int8 *v10; // edi
  CFunctor *v11; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v8 = 4;
  if ( m_alignment >= 4 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &this->m_Allocator.m_pNextAlloc[v9];
  if ( v10 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v9]) )
  {
    this->m_Allocator.m_pNextAlloc = v10;
  }
  v11 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v11[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D670
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(unsigned char,unsigned char,unsigned char,unsigned char),unsigned char const __near &,unsigned char const __near &,unsigned char const __near &,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const unsigned __int8 *arg1,
        const unsigned __int8 *arg2,
        const unsigned __int8 *arg3,
        const unsigned __int8 *arg4)
{
  unsigned int m_alignment; // eax
  int v9; // ecx
  int v10; // ecx
  unsigned __int8 *v11; // edi
  CFunctor *v12; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v9 = 4;
  if ( m_alignment >= 4 )
    v9 = m_alignment;
  v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v11 = &this->m_Allocator.m_pNextAlloc[v10];
  if ( v11 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v10]) )
  {
    this->m_Allocator.m_pNextAlloc = v11;
  }
  v12 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v12[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D710
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,bool,bool,bool,bool>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(bool,bool),bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const bool *arg1,
        const bool *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D7B0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMaterial __near *,class IMaterial __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *),class IMaterial __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,IMaterial *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterial *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,IMaterial *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D840
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct OcclusionQueryObjectHandle_t__ __near *,struct OcclusionQueryObjectHandle_t__ __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct OcclusionQueryObjectHandle_t__ __near *),struct OcclusionQueryObjectHandle_t__ __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        OcclusionQueryObjectHandle_t__ *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D8D0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialHeightClipMode_t,enum MaterialHeightClipMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialHeightClipMode_t),enum MaterialHeightClipMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialHeightClipMode_t,enum MaterialHeightClipMode_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialHeightClipMode_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialHeightClipMode_t,enum MaterialHeightClipMode_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D960
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,float,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(float),float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        float *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D9F0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMorph __near *,class IMorph __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMorph __near *),class IMorph __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMorph *,IMorph *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMorph *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMorph *,IMorph *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA80
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,int,int,int,int,class ITexture __near *,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,int,int,int,int),class ITexture __near * const __near &,int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,int,int,int,ITexture *,int,int,int,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        const int *arg2,
        const int *arg3,
        const int *arg4,
        const int *arg5)
{
  unsigned int m_alignment; // eax
  int v10; // ecx
  int v11; // ecx
  unsigned __int8 *v12; // edi
  CFunctor *v13; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v10 = 4;
  if ( m_alignment >= 4 )
    v10 = m_alignment;
  v11 = ~(m_alignment - 1) & (m_alignment + v10 - 1);
  v12 = &this->m_Allocator.m_pNextAlloc[v11];
  if ( v12 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v11]) )
  {
    this->m_Allocator.m_pNextAlloc = v12;
  }
  v13 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,int,int,int,ITexture *,int,int,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4,
          arg5);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v13[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DB20
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,class ITexture __near *,int,int,int,int,class ITexture __near *,class ITexture __near *,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,class ITexture __near *,int,int,int,int),class ITexture __near * const __near &,class ITexture __near * const __near &,int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *,int,int,int,int,ITexture *,ITexture *,int,int,int,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        ITexture *const *arg2,
        const int *arg3,
        const int *arg4,
        const int *arg5,
        const int *arg6)
{
  unsigned int m_alignment; // eax
  int v11; // ecx
  int v12; // ecx
  unsigned __int8 *v13; // edi
  CFunctor *v14; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v11 = 4;
  if ( m_alignment >= 4 )
    v11 = m_alignment;
  v12 = ~(m_alignment - 1) & (m_alignment + v11 - 1);
  v13 = &this->m_Allocator.m_pNextAlloc[v12];
  if ( v13 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v12]) )
  {
    this->m_Allocator.m_pNextAlloc = v13;
  }
  v14 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *,int,int,int,int,ITexture *,ITexture *,int,int,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4,
          arg5,
          arg6);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v14[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DBD0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,float,int,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,float),int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,float,int,float>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        float *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,float,int,float>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DC70
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,int),int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const int *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DD10
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,class ITexture __near *,int,class ITexture __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,class ITexture __near *),int const __near &,class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,ITexture *,int,ITexture *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        ITexture *const *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,ITexture *,int,ITexture *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DDB0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,class Vector const __near &,int,class Vector>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,class Vector const __near &),int const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,Vector const &,int,Vector>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const Vector *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,Vector const &,int,Vector>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DE50
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct ShaderStencilState_t const __near &,struct ShaderStencilState_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct ShaderStencilState_t const __near &),struct ShaderStencilState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ShaderStencilState_t const &,ShaderStencilState_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const ShaderStencilState_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ShaderStencilState_t const &,ShaderStencilState_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DEE0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,int,int,int,int,int,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,int,int,int,int),int const __near &,int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int,int,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const int *arg2,
        const int *arg3,
        const int *arg4,
        const int *arg5)
{
  unsigned int m_alignment; // eax
  int v10; // ecx
  int v11; // ecx
  unsigned __int8 *v12; // edi
  CFunctor *v13; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v10 = 4;
  if ( m_alignment >= 4 )
    v10 = m_alignment;
  v11 = ~(m_alignment - 1) & (m_alignment + v10 - 1);
  v12 = &this->m_Allocator.m_pNextAlloc[v11];
  if ( v12 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v11]) )
  {
    this->m_Allocator.m_pNextAlloc = v12;
  }
  v13 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4,
          arg5);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v13[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002DF80
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,float const __near *,float const __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(float const __near *),float const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float const *,float const *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const float *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,float const *,float const *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E010
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near *,struct FlashlightState_t,class VMatrix,class ITexture __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near *),struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,FlashlightState_t const &,VMatrix const &,ITexture *,FlashlightState_t,VMatrix,ITexture *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const FlashlightState_t *arg1,
        const VMatrix *arg2,
        ITexture *const *arg3)
{
  unsigned int m_alignment; // eax
  int v8; // ecx
  int v9; // ecx
  unsigned __int8 *v10; // edi
  CFunctor *v11; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v8 = 4;
  if ( m_alignment >= 4 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &this->m_Allocator.m_pNextAlloc[v9];
  if ( v10 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v9]) )
  {
    this->m_Allocator.m_pNextAlloc = v10;
  }
  v11 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,FlashlightState_t const &,VMatrix const &,ITexture *,FlashlightState_t,VMatrix,ITexture *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v11[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E0B0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,int,int,int,int,int,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,int,int,int),int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const int *arg2,
        const int *arg3,
        const int *arg4)
{
  unsigned int m_alignment; // eax
  int v9; // ecx
  int v10; // ecx
  unsigned __int8 *v11; // edi
  CFunctor *v12; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v9 = 4;
  if ( m_alignment >= 4 )
    v9 = m_alignment;
  v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v11 = &this->m_Allocator.m_pNextAlloc[v10];
  if ( v11 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v10]) )
  {
    this->m_Allocator.m_pNextAlloc = v11;
  }
  v12 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v12[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E150
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,unsigned long,char const __near *,unsigned long,char const __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(unsigned long,char const __near *),unsigned long const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,unsigned long,char const *,unsigned long,char const *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const unsigned int *arg1,
        const char *const *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,unsigned long,char const *,unsigned long,char const *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E1F0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContextInternal,void,class IMaterialInternal __near *,class IMaterialInternal __near *>(class CMatRenderContextBase __near *,void (IMatRenderContextInternal::*)(class IMaterialInternal __near *),class IMaterialInternal __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void,IMaterialInternal *,IMaterialInternal *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterialInternal *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContextInternal,void,IMaterialInternal *,IMaterialInternal *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E280
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContextInternal,void,void __near *,void __near *>(class CMatRenderContextBase __near *,void (IMatRenderContextInternal::*)(void __near *),void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void,void *,void *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        void *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContextInternal,void,void *,void *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E310
// Name: public: void CMatCallQueue::QueueCall<class IColorCorrectionSystem __near *,class IColorCorrectionSystem,void,bool,bool>(class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IColorCorrectionSystem *,IColorCorrectionSystem,void,bool,bool>(
        CMatCallQueue *this,
        IColorCorrectionSystem *pObject,
        __int128 pfnProxied,
        const bool *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IColorCorrectionSystem *,IColorCorrectionSystem,void,bool,bool>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E3A0
// Name: public: void CMatCallQueue::QueueCall<class IColorCorrectionSystem __near *,class IColorCorrectionSystem,void>(class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IColorCorrectionSystem *,IColorCorrectionSystem,void>(
        CMatCallQueue *this,
        IColorCorrectionSystem *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IColorCorrectionSystem *,IColorCorrectionSystem,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E430
// Name: public: void CMatCallQueue::QueueCall<class IColorCorrectionSystem __near *,class IColorCorrectionSystem,void,unsigned int,float,unsigned int,float>(class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(unsigned int,float),unsigned int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IColorCorrectionSystem *,IColorCorrectionSystem,void,unsigned int,float,unsigned int,float>(
        CMatCallQueue *this,
        IColorCorrectionSystem *pObject,
        __int128 pfnProxied,
        const unsigned int *arg1,
        float *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IColorCorrectionSystem *,IColorCorrectionSystem,void,unsigned int,float,unsigned int,float>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E4D0
// Name: public: void CMatCallQueue::QueueCall<class IColorCorrectionSystem __near *,class IColorCorrectionSystem,void,unsigned int,bool,unsigned int,bool>(class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(unsigned int,bool),unsigned int const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IColorCorrectionSystem *,IColorCorrectionSystem,void,unsigned int,bool,unsigned int,bool>(
        CMatCallQueue *this,
        IColorCorrectionSystem *pObject,
        __int128 pfnProxied,
        const unsigned int *arg1,
        const bool *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IColorCorrectionSystem *,IColorCorrectionSystem,void,unsigned int,bool,unsigned int,bool>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E570
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class Vector const __near &,class Vector>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class Vector const __near &),class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,Vector const &,Vector>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const Vector *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,Vector const &,Vector>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E600
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,float,float,float,float,class ITexture __near *,float,float,float,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,float,float,float,float),class ITexture __near * const __near &,float const __near &,float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,float,float,float,float,ITexture *,float,float,float,float>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        float *arg2,
        float *arg3,
        float *arg4,
        float *arg5)
{
  unsigned int m_alignment; // eax
  int v10; // ecx
  int v11; // ecx
  unsigned __int8 *v12; // edi
  CFunctor *v13; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v10 = 4;
  if ( m_alignment >= 4 )
    v10 = m_alignment;
  v11 = ~(m_alignment - 1) & (m_alignment + v10 - 1);
  v12 = &this->m_Allocator.m_pNextAlloc[v11];
  if ( v12 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v11]) )
  {
    this->m_Allocator.m_pNextAlloc = v12;
  }
  v13 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,float,float,float,float,ITexture *,float,float,float,float>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4,
          arg5);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v13[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E6A0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,float,float,float,class ITexture __near *,float,float,float>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,float,float,float),class ITexture __near * const __near &,float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,float,float,float,ITexture *,float,float,float>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        float *arg2,
        float *arg3,
        float *arg4)
{
  unsigned int m_alignment; // eax
  int v9; // ecx
  int v10; // ecx
  unsigned __int8 *v11; // edi
  CFunctor *v12; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v9 = 4;
  if ( m_alignment >= 4 )
    v9 = m_alignment;
  v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v11 = &this->m_Allocator.m_pNextAlloc[v10];
  if ( v11 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v10]) )
  {
    this->m_Allocator.m_pNextAlloc = v11;
  }
  v12 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,float,float,float,ITexture *,float,float,float>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v12[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E740
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,enum MaterialNonInteractiveMode_t,class ITexture __near *,enum MaterialNonInteractiveMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,enum MaterialNonInteractiveMode_t),class ITexture __near * const __near &,enum MaterialNonInteractiveMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,enum MaterialNonInteractiveMode_t,ITexture *,enum MaterialNonInteractiveMode_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        const MaterialNonInteractiveMode_t *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,enum MaterialNonInteractiveMode_t,ITexture *,enum MaterialNonInteractiveMode_t>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E7E0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialNonInteractiveMode_t,enum MaterialNonInteractiveMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialNonInteractiveMode_t,enum MaterialNonInteractiveMode_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialNonInteractiveMode_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialNonInteractiveMode_t,enum MaterialNonInteractiveMode_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033860
// Name: public: virtual void CMemberFunctor2<class CMaterialVar __near *,void (CMaterialVar::*)(class Vector4D const __near &,int),class Vector4D,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(Vector4D const &,int),Vector4D,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(Vector4D const &,int),Vector4D,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, Vector4D *, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: &this->m_arg1,
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x10033880
// Name: public: virtual void CMemberFunctor2<class CMaterialVar __near *,void (CMaterialVar::*)(float,int),float,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(float,int),float,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(float,int),float,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, _DWORD, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: LODWORD(this->m_arg1),
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x100338A0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,float,float>(class CMaterialVar __near *,void (CMaterialVar::*)(float),float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,float,float>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        float *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  float *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((float *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033930
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,int,int>(class CMaterialVar __near *,void (CMaterialVar::*)(int),int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const int *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const int *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((_DWORD *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x100339C0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,unsigned long,void __near *,unsigned long,void __near *>(class CMaterialVar __near *,void (CMaterialVar::*)(unsigned long,void __near *),unsigned long const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,unsigned long,void *,unsigned long,void *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const unsigned int *arg1,
        void *const *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const unsigned int *v11; // ecx
  __int64 v12; // xmm0_8
  void *const *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((void **)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033A50
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,class ITexture __near *,class ITexture __near *>(class CMaterialVar __near *,void (CMaterialVar::*)(class ITexture __near *),class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,ITexture *,ITexture *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  ITexture *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(ITexture *),ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(ITexture *),ITexture *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((ITexture **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033AE0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,class IMaterial __near *,class IMaterial __near *>(class CMaterialVar __near *,void (CMaterialVar::*)(class IMaterial __near *),class IMaterial __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,IMaterial *,IMaterial *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        IMaterial *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  IMaterial *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((IMaterial **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033B70
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,class Vector4D const __near &,int,class Vector4D,int>(class CMaterialVar __near *,void (CMaterialVar::*)(class Vector4D const __near &,int),class Vector4D const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,Vector4D const &,int,Vector4D,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const Vector4D *arg1,
        const int *arg2)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const int *v11; // ecx
  __int64 v12; // xmm0_8
  const Vector4D *v13; // eax
  double w; // st7

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = 64;
  if ( m_alignment >= 0x40 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &m_pNextAlloc[v9];
  if ( &m_pNextAlloc[v9] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  v11 = arg2;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(Vector4D const &,int),Vector4D,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(Vector4D const &,int),Vector4D,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg1;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((float *)m_pNextAlloc + 10) = v13->x;
  *((float *)m_pNextAlloc + 11) = v13->y;
  *((float *)m_pNextAlloc + 12) = v13->z;
  w = v13->w;
  *((float *)m_pNextAlloc + 13) = w;
  *((_DWORD *)m_pNextAlloc + 14) = *v11;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033C10
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,float,int,float,int>(class CMaterialVar __near *,void (CMaterialVar::*)(float,int),float const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,float,int,float,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        float *arg1,
        const int *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  float *v11; // ecx
  const int *v12; // edx
  __int64 v13; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  v12 = arg2;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(float,int),float,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(float,int),float,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  *((float *)m_pNextAlloc + 10) = *v11;
  *((_DWORD *)m_pNextAlloc + 11) = *v12;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033CA0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,class VMatrix const __near &,class VMatrix>(class CMaterialVar __near *,void (CMaterialVar::*)(class VMatrix const __near &),class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,VMatrix const &,VMatrix>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const VMatrix *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // ebx
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  const VMatrix *v10; // esi
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 104;
  if ( m_alignment >= 0x68 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  qmemcpy(m_pNextAlloc + 40, v10, 0x40u);
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033D30
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void>(class CMaterialVar __near *,void (CMaterialVar::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<CMaterialVar *,void (__thiscall CMaterialVar::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<CMaterialVar *,void (__thiscall CMaterialVar::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033DB0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMaterialVar __near *,class CMaterialVar,void,class IMaterialVar __near *,class IMaterialVar __near *>(class CMaterialVar __near *,void (CMaterialVar::*)(class IMaterialVar __near *),class IMaterialVar __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,IMaterialVar *,IMaterialVar *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        IMaterialVar *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  IMaterialVar *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((IMaterialVar **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10033E40
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,float,float>(class CMaterialVar __near *,void (CMaterialVar::*)(float),float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,float,float>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        float *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,float,float>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033ED0
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,int,int>(class CMaterialVar __near *,void (CMaterialVar::*)(int),int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,int,int>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const int *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,int,int>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033F60
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,unsigned long,void __near *,unsigned long,void __near *>(class CMaterialVar __near *,void (CMaterialVar::*)(unsigned long,void __near *),unsigned long const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,unsigned long,void *,unsigned long,void *>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const unsigned int *arg1,
        void *const *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,unsigned long,void *,unsigned long,void *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10034000
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,class ITexture __near *,class ITexture __near *>(class CMaterialVar __near *,void (CMaterialVar::*)(class ITexture __near *),class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,ITexture *,ITexture *>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,ITexture *,ITexture *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10034090
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,class IMaterial __near *,class IMaterial __near *>(class CMaterialVar __near *,void (CMaterialVar::*)(class IMaterial __near *),class IMaterial __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,IMaterial *,IMaterial *>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        IMaterial *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,IMaterial *,IMaterial *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10034120
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,class Vector4D const __near &,int,class Vector4D,int>(class CMaterialVar __near *,void (CMaterialVar::*)(class Vector4D const __near &,int),class Vector4D const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,Vector4D const &,int,Vector4D,int>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const Vector4D *arg1,
        const int *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,Vector4D const &,int,Vector4D,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100341C0
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,float,int,float,int>(class CMaterialVar __near *,void (CMaterialVar::*)(float,int),float const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,float,int,float,int>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        float *arg1,
        const int *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,float,int,float,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10034260
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,class VMatrix const __near &,class VMatrix>(class CMaterialVar __near *,void (CMaterialVar::*)(class VMatrix const __near &),class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,VMatrix const &,VMatrix>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const VMatrix *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,VMatrix const &,VMatrix>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100342F0
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void>(class CMaterialVar __near *,void (CMaterialVar::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10034380
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,class IMaterialVar __near *,class IMaterialVar __near *>(class CMaterialVar __near *,void (CMaterialVar::*)(class IMaterialVar __near *),class IMaterialVar __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,IMaterialVar *,IMaterialVar *>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        IMaterialVar *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMaterialVar *,CMaterialVar,void,IMaterialVar *,IMaterialVar *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10035590
// Name: public: void CMatCallQueue::QueueCall<class CMaterialVar __near *,class CMaterialVar,void,char const __near *,class CUtlEnvelope<char const __near *>>(class CMaterialVar __near *,void (CMaterialVar::*)(char const __near *),class CUtlEnvelope<char const __near *> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,char const *,CUtlEnvelope<char const *>>(
        CMatCallQueue *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const CUtlEnvelope<char const *> *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  unsigned __int8 *v7; // esi
  CMemoryStack *m_pAllocator; // esi
  unsigned int v9; // ecx
  CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *m_pNextAlloc; // ebx
  int v11; // eax
  int v12; // eax
  unsigned __int8 *v13; // edi
  CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v14; // eax
  CMatCallQueue::Elem_t *m_pTail; // edx
  int *p_m_nActualLength; // eax
  CMatCallQueue *v17; // [esp+8h] [ebp-14h]

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = &this->m_Allocator.m_pNextAlloc[~(m_alignment - 1) & (m_alignment + v6 - 1)];
  v17 = this;
  if ( v7 <= this->m_Allocator.m_pCommitLimit || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: v7) )
    this->m_Allocator.m_pNextAlloc = v7;
  m_pAllocator = this->m_FunctorFactory.m_pAllocator;
  v9 = m_pAllocator->m_alignment;
  m_pNextAlloc = (CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)m_pAllocator->m_pNextAlloc;
  v11 = 56;
  if ( v9 >= 0x38 )
    v11 = m_pAllocator->m_alignment;
  v12 = ~(v9 - 1) & (v9 + v11 - 1);
  v13 = (unsigned __int8 *)m_pNextAlloc + v12;
  if ( (unsigned __int8 *)((unsigned int)m_pNextAlloc + v12) <= m_pAllocator->m_pCommitLimit
    || CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: (unsigned __int8 *)m_pNextAlloc + v12) )
  {
    m_pAllocator->m_pNextAlloc = v13;
  }
  else
  {
    m_pNextAlloc = nullptr;
  }
  if ( m_pNextAlloc != nullptr )
    v14 = CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
            this: m_pNextAlloc,
            pObject,
            pfnProxied,
            arg1);
  else
    v14 = nullptr;
  m_pTail = v17->m_pTail;
  p_m_nActualLength = &v14[-1].m_arg1.m_string.m_Storage.m_nActualLength;
  if ( m_pTail != nullptr )
    m_pTail->pNext = (CMatCallQueue::Elem_t *)p_m_nActualLength;
  else
    v17->m_pHead = (CMatCallQueue::Elem_t *)p_m_nActualLength;
  v17->m_pTail = (CMatCallQueue::Elem_t *)p_m_nActualLength;
  *p_m_nActualLength = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003AA60
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatLightmaps __near *,class CMatLightmaps,void>(class CMatLightmaps __near *,void (CMatLightmaps::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatLightmaps *,CMatLightmaps,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatLightmaps *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<CMatLightmaps *,void (__thiscall CMatLightmaps::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<CMatLightmaps *,void (__thiscall CMatLightmaps::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003ADB0
// Name: public: void CMatCallQueue::QueueCall<class CMatLightmaps __near *,class CMatLightmaps,void>(class CMatLightmaps __near *,void (CMatLightmaps::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatLightmaps *,CMatLightmaps,void>(
        CMatCallQueue *this,
        CMatLightmaps *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatLightmaps *,CMatLightmaps,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003C380
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatPaintmaps __near *,class CMatPaintmaps,void>(class CMatPaintmaps __near *,void (CMatPaintmaps::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatPaintmaps *,CMatPaintmaps,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatPaintmaps *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<CMatPaintmaps *,void (__thiscall CMatPaintmaps::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003C450
// Name: public: void CMatCallQueue::QueueCall<class CMatPaintmaps __near *,class CMatPaintmaps,void>(class CMatPaintmaps __near *,void (CMatPaintmaps::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatPaintmaps *,CMatPaintmaps,void>(
        CMatCallQueue *this,
        CMatPaintmaps *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatPaintmaps *,CMatPaintmaps,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003C8D0
// Name: void FastCopy(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FastCopy(float *pDest, unsigned __int8 *pSrc, unsigned int nBytes)
{
  unsigned int v3; // esi
  unsigned __int8 *v4; // eax
  int v5; // edx
  unsigned __int8 *v6; // ecx
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm7

  v3 = nBytes;
  if ( nBytes != 0 )
  {
    v4 = (unsigned __int8 *)pDest;
    if ( ((unsigned __int8)pDest & 0xF) == 0 && ((unsigned __int8)pSrc & 0xF) == 0 )
    {
      v5 = nBytes - (nBytes & 0x7F);
      v6 = (unsigned __int8 *)pDest + v5;
      if ( pDest < (float *)((char *)pDest + v5) )
      {
        do
        {
          v7 = *((__m128 *)pSrc + 1);
          v8 = *((__m128 *)pSrc + 2);
          v9 = *((__m128 *)pSrc + 3);
          v10 = *((__m128 *)pSrc + 4);
          v11 = *((__m128 *)pSrc + 5);
          v12 = *((__m128 *)pSrc + 6);
          v13 = *((__m128 *)pSrc + 7);
          _mm_stream_ps(pDest, *(__m128 *)pSrc);
          _mm_stream_ps(pDest + 4, v7);
          _mm_stream_ps(pDest + 8, v8);
          _mm_stream_ps(pDest + 12, v9);
          _mm_stream_ps(pDest + 16, v10);
          _mm_stream_ps(pDest + 20, v11);
          _mm_stream_ps(pDest + 24, v12);
          _mm_stream_ps(pDest + 28, v13);
          pSrc += 128;
          v4 += 128;
          pDest = (float *)v4;
        }
        while ( v4 < v6 );
        v3 = nBytes;
      }
      v3 -= v5;
    }
    if ( v3 != 0 )
      memcpy(dst: v4, src: pSrc, count: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C970
// Name: public: class IMesh __near * CMatQueuedMesh::MST_SetupDynamicMesh(struct CMatQueuedMesh::MST_MeshInfo_t const __near &,class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
IMesh *__userpurge CMatQueuedMesh::MST_SetupDynamicMesh@<eax>(
        CMatQueuedMesh *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const CMatQueuedMesh::MST_MeshInfo_t *info,
        IMesh *pExternalMesh)
{
  int m_nVertexCount; // eax
  bool v8; // zf
  IMatRenderContextInternal *m_pHardwareContext; // ecx
  IMesh *result; // eax
  int m_VertexSize_TangentT; // eax
  float *m_pTangentT; // edx
  unsigned int m_ActualVertexSize; // eax
  unsigned __int8 *m_pIndexData; // eax
  signed int m_nIndexSize; // esi
  int v16; // edi
  int v17; // esi
  int v18; // eax
  unsigned __int8 *v19; // ecx
  IMesh *v20; // esi
  _DWORD *v21; // ecx
  void (__thiscall *UnlockMesh)(IMesh *, int, int, MeshDesc_t *); // edx
  _BYTE v24[2]; // [esp-2Eh] [ebp-FEh]
  int v25; // [esp-2Ch] [ebp-FCh] BYREF
  _DWORD v26[3]; // [esp-Ch] [ebp-DCh] BYREF
  MeshDesc_t desc; // [esp+0h] [ebp-D0h]
  unsigned __int8 *v28; // [esp+B4h] [ebp-1Ch]
  int v29; // [esp+B8h] [ebp-18h]
  IMesh *v30; // [esp+BCh] [ebp-14h]
  _DWORD *m_nIndexCount; // [esp+C0h] [ebp-10h]
  int nVerticesToLock; // [esp+C4h] [ebp-Ch]
  IMesh *pDynamicMesh; // [esp+C8h] [ebp-8h]
  IMesh *retaddr; // [esp+D0h] [ebp+0h]

  nVerticesToLock = a2;
  pDynamicMesh = retaddr;
  m_nVertexCount = info->m_nVertexCount;
  v8 = !this->m_bFlexMesh;
  m_nIndexCount = (_DWORD *)info->m_nIndexCount;
  m_pHardwareContext = this->m_pHardwareContext;
  v29 = m_nVertexCount;
  if ( v8 )
    result = (IMesh *)((int (__thiscall *)(IMatRenderContextInternal *, _DWORD, _DWORD, int, IMesh *, IMesh *, IMaterial *, int, int))m_pHardwareContext->GetDynamicMeshEx)(
                        a1: m_pHardwareContext,
                        a2: info->m_VertexFormat,
                        a3: HIDWORD(info->m_VertexFormat),
                        a4: info->m_nFlags & 1,
                        a5: info->m_pVertexOverride,
                        a6: info->m_pIndexOverride,
                        a7: info->m_pMaterial,
                        a8: a3,
                        a9: a4);
  else
    result = (IMesh *)((int (__thiscall *)(IMatRenderContextInternal *, int, int))m_pHardwareContext->GetFlexMesh)(
                        a1: m_pHardwareContext,
                        a2: a3,
                        a3: a4);
  v30 = result;
  if ( v29 != 0 || m_nIndexCount != nullptr )
  {
    ((void (__thiscall *)(IMesh *, MaterialPrimitiveType_t, _DWORD *))result->SetPrimitiveType)(
      a1: result,
      a2: info->m_nPrimitiveType,
      a3: m_nIndexCount);
    v30->LockMesh(this: v30, a2: 0, a3: 0, a4: (MeshDesc_t *)v26, a5: nullptr);
    m_VertexSize_TangentT = desc.m_VertexSize_TangentT;
    m_pTangentT = desc.m_pTangentT;
    v8 = v29 == 0;
    this->m_nMSTActualVertexOffsetInBytes = (int)desc.m_pTangentT * desc.m_VertexSize_TangentT;
    if ( !v8 && m_VertexSize_TangentT != 0 )
    {
      if ( v26[0] != 0 )
      {
        m_ActualVertexSize = desc.m_ActualVertexSize;
      }
      else
      {
        m_ActualVertexSize = -1;
        if ( v26[1] != 0 )
          m_ActualVertexSize = desc.m_CompressionType;
        if ( v26[2] != 0 && m_ActualVertexSize >= desc.m_NumBoneWeights )
          m_ActualVertexSize = desc.m_NumBoneWeights;
        if ( desc.m_VertexSize_Position != 0 && (float *)m_ActualVertexSize >= desc.m_pPosition )
          m_ActualVertexSize = (unsigned int)desc.m_pPosition;
        if ( desc.m_VertexSize_BoneWeight != 0 && (float *)m_ActualVertexSize >= desc.m_pBoneWeight )
          m_ActualVertexSize = (unsigned int)desc.m_pBoneWeight;
        if ( desc.m_VertexSize_BoneMatrixIndex != 0 && (unsigned __int8 *)m_ActualVertexSize >= desc.m_pBoneMatrixIndex )
          m_ActualVertexSize = (unsigned int)desc.m_pBoneMatrixIndex;
        if ( desc.m_VertexSize_TexCoord[5] != 0 && (float *)m_ActualVertexSize >= desc.m_pTexCoord[5] )
          m_ActualVertexSize = (unsigned int)desc.m_pTexCoord[5];
        if ( desc.m_VertexSize_TexCoord[6] != 0 && (float *)m_ActualVertexSize >= desc.m_pTexCoord[6] )
          m_ActualVertexSize = (unsigned int)desc.m_pTexCoord[6];
        if ( desc.m_VertexSize_TexCoord[7] != 0 && (float *)m_ActualVertexSize >= desc.m_pTexCoord[7] )
          m_ActualVertexSize = (unsigned int)desc.m_pTexCoord[7];
        if ( desc.m_VertexSize_Normal != 0 && desc.m_pNormal < (float *)m_ActualVertexSize )
          m_ActualVertexSize = (unsigned int)desc.m_pNormal;
        if ( desc.m_VertexSize_Color != 0 && desc.m_pColor < (unsigned __int8 *)m_ActualVertexSize )
          m_ActualVertexSize = (unsigned int)desc.m_pColor;
        if ( desc.m_VertexSize_Specular != 0 && desc.m_pSpecular < (unsigned __int8 *)m_ActualVertexSize )
          m_ActualVertexSize = (unsigned int)desc.m_pSpecular;
        if ( desc.m_VertexSize_TexCoord[0] != 0 && desc.m_pTexCoord[0] < (float *)m_ActualVertexSize )
          m_ActualVertexSize = (unsigned int)desc.m_pTexCoord[0];
        if ( desc.m_VertexSize_TexCoord[1] != 0 && desc.m_pTexCoord[1] < (float *)m_ActualVertexSize )
          m_ActualVertexSize = (unsigned int)desc.m_pTexCoord[1];
        if ( desc.m_VertexSize_TexCoord[2] != 0 && desc.m_pTexCoord[2] < (float *)m_ActualVertexSize )
          m_ActualVertexSize = (unsigned int)desc.m_pTexCoord[2];
        if ( desc.m_VertexSize_TexCoord[3] != 0 && desc.m_pTexCoord[3] < (float *)m_ActualVertexSize )
          m_ActualVertexSize = (unsigned int)desc.m_pTexCoord[3];
        if ( desc.m_VertexSize_TexCoord[4] != 0 && desc.m_pTexCoord[4] < (float *)m_ActualVertexSize )
          m_ActualVertexSize = (unsigned int)desc.m_pTexCoord[4];
      }
      if ( m_ActualVertexSize != 0 )
      {
        FastCopy(
          pDest: (float *)m_ActualVertexSize,
          pSrc: info->m_pVertexData,
          nBytes: info->m_nVertexCount * info->m_nVertexSizeInBytes);
        m_pTangentT = desc.m_pTangentT;
      }
    }
    if ( m_nIndexCount != nullptr )
    {
      m_pIndexData = (unsigned __int8 *)info->m_pIndexData;
      v28 = m_pIndexData;
      if ( m_pIndexData != (unsigned __int8 *)&CMatQueuedMesh::gm_ScratchIndexBuffer && desc.m_pIndices != nullptr )
      {
        m_nIndexSize = info->m_nIndexCount;
        desc.m_nIndexSize = m_nIndexSize;
        if ( m_pTangentT != nullptr )
        {
          v16 = 0;
          if ( ((int)desc.m_pUserData & 3) == 2 )
          {
            *(_WORD *)desc.m_pUserData = (_WORD)m_pTangentT + *(_WORD *)v28;
            v16 = 1;
          }
          if ( v16 < m_nIndexSize )
          {
            while ( 1 )
            {
              v17 = (unsigned int)(m_nIndexSize - v16) <= 0x10 ? m_nIndexSize - v16 : 16;
              v18 = 0;
              if ( v17 > 0 )
              {
                v19 = &v28[2 * v16];
                do
                {
                  ++v18;
                  *(_WORD *)&v24[2 * v18] = LOWORD(desc.m_pTangentT) + *(_WORD *)v19;
                  v19 += 2;
                }
                while ( v18 < v17 );
              }
              FastCopy(
                pDest: (float *)((char *)desc.m_pUserData + 2 * v16),
                pSrc: (unsigned __int8 *)&v25,
                nBytes: 2 * v17);
              v16 += v17;
              if ( v16 >= (int)desc.m_nIndexSize )
                break;
              m_nIndexSize = desc.m_nIndexSize;
            }
          }
        }
        else
        {
          FastCopy(pDest: desc.m_pUserData, pSrc: m_pIndexData, nBytes: 2 * m_nIndexSize);
        }
      }
    }
    v20 = v30;
    v21 = m_nIndexCount;
    UnlockMesh = v30->UnlockMesh;
    m_nIndexCount = v26;
    ((void (__thiscall *)(IMesh *, int, _DWORD *))UnlockMesh)(a1: v30, a2: v29, a3: v21);
    return v20;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003CC80
// Name: public: void CMatQueuedMesh::MST_Draw(struct CMatQueuedMesh::MST_DrawInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::MST_Draw(CMatQueuedMesh *this, const CMatQueuedMesh::MST_DrawInfo_t *info)
{
  this->m_pMSTActualMesh->SetPrimitiveType(this: this->m_pMSTActualMesh, a2: info->m_Type);
  this->m_pMSTActualMesh->Draw_2(this: this->m_pMSTActualMesh, a2: info->m_nFirstIndex, a3: info->m_nIndexCount);
}

//------------------------------------------------------------------------------
// Address: 0x1003CCB0
// Name: public: void CMatQueuedMesh::MST_DrawModulated(struct CMatQueuedMesh::MST_DrawModulatedInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::MST_DrawModulated(
        CMatQueuedMesh *this,
        const CMatQueuedMesh::MST_DrawModulatedInfo_t *info)
{
  this->m_pMSTActualMesh->SetPrimitiveType(this: this->m_pMSTActualMesh, a2: info->m_Type);
  this->m_pMSTActualMesh->DrawModulated(
    this: this->m_pMSTActualMesh,
    a2: &info->m_vecDiffuseModulation,
    a3: info->m_nFirstIndex,
    a4: info->m_nIndexCount);
}

//------------------------------------------------------------------------------
// Address: 0x1003CCF0
// Name: public: virtual int CMatQueuedMesh::VertexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedMesh::VertexCount(CMatQueuedMesh *this)
{
  if ( this->m_VertexSize != 0 )
    return this->m_nVerts;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003CD00
// Name: public: virtual void CMatQueuedMesh::SetPrimitiveType(enum MaterialPrimitiveType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::SetPrimitiveType(CMatQueuedMesh *this, MaterialPrimitiveType_t type)
{
  this->m_Type = type;
}

//------------------------------------------------------------------------------
// Address: 0x1003CD10
// Name: public: virtual unsigned __int64 CMatQueuedMesh::GetVertexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMatQueuedMesh::GetVertexFormat(CMatQueuedMesh *this)
{
  return this->m_VertexFormat;
}

//------------------------------------------------------------------------------
// Address: 0x1003CD20
// Name: public: virtual int CMatQueuedIndexBuffer::GetRoomRemaining(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedIndexBuffer::GetRoomRemaining(CMatQueuedIndexBuffer *this)
{
  return this->m_pOwner->GetMaxIndicesToRender(this: this->m_pOwner) - this->m_nIndices;
}

//------------------------------------------------------------------------------
// Address: 0x1003CD40
// Name: private: void CMatQueuedIndexBuffer::RT_CopyIndexData(int,enum MaterialIndexFormat_t,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedIndexBuffer::RT_CopyIndexData(
        CMatQueuedIndexBuffer *this,
        int nIndexCount,
        MaterialIndexFormat_t fmt,
        unsigned __int8 *pIndexData,
        bool bIsExternal)
{
  IIndexBuffer *v6; // eax
  unsigned int m_nIndexSize; // ebx
  unsigned int v8; // ecx
  IndexDesc_t desc; // [esp+8h] [ebp-10h] BYREF

  v6 = this->m_pHardwareContext->GetDynamicIndexBuffer(this: this->m_pHardwareContext);
  this->m_pRTDynamicIndexBuffer = v6;
  if ( v6->Lock(this: v6, a2: nIndexCount, a3: false, a4: &desc) )
  {
    m_nIndexSize = desc.m_nIndexSize;
    v8 = 2 * desc.m_nIndexSize;
    this->m_nRTStartIndex = desc.m_nOffset / (2 * desc.m_nIndexSize);
    if ( pIndexData != nullptr && m_nIndexSize != 0 )
      FastCopy(pDest: (float *)desc.m_pIndices, pSrc: pIndexData, nBytes: nIndexCount * v8);
    this->m_pRTDynamicIndexBuffer->Unlock(this: this->m_pRTDynamicIndexBuffer, a2: nIndexCount, a3: &desc);
  }
  else
  {
    this->m_pRTDynamicIndexBuffer = nullptr;
    this->m_nRTStartIndex = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CDD0
// Name: public: virtual void CMatQueuedIndexBuffer::ModifyBegin(bool,int,int,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedIndexBuffer::ModifyBegin(
        CMatQueuedIndexBuffer *this,
        bool bReadOnly,
        int nFirstIndex,
        int nIndexCount,
        IndexDesc_t *desc)
{
  if ( _executeCount_3 < 1 )
  {
    ++_executeCount_3;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( _executeCount_2 < 1 )
  {
    ++_executeCount_2;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CE10
// Name: public: virtual void CMatQueuedIndexBuffer::ModifyEnd(struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedIndexBuffer::ModifyEnd(CMatQueuedIndexBuffer *this, IndexDesc_t *desc)
{
  if ( _executeCount_5 < 1 )
  {
    ++_executeCount_5;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( _executeCount_4 < 1 )
  {
    ++_executeCount_4;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CE50
// Name: public: void CMatQueuedRenderContext::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Shutdown(CMatQueuedRenderContext *this)
{
  CMatQueuedIndexBuffer *m_pQueuedIndexBuffer; // ecx

  if ( this->m_pHardwareContext != nullptr )
  {
    free(pMem: this->m_pQueuedMesh);
    free(pMem: this->m_pQueuedFlexMesh);
    m_pQueuedIndexBuffer = this->m_pQueuedIndexBuffer;
    if ( m_pQueuedIndexBuffer != nullptr )
      ((void (__thiscall *)(CMatQueuedIndexBuffer *, int))m_pQueuedIndexBuffer->dtr_CMatQueuedIndexBuffer)(
        a1: m_pQueuedIndexBuffer,
        a2: 1);
    this->m_pMaterialSystem = nullptr;
    this->m_pHardwareContext = nullptr;
    this->m_pQueuedMesh = nullptr;
    this->m_pQueuedFlexMesh = nullptr;
    this->m_pQueuedIndexBuffer = nullptr;
    CMemoryStack::Term(this: &this->m_Vertices);
    CMemoryStack::Term(this: &this->m_Indices);
    CMatRenderContextBase::Shutdown(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CED0
// Name: public: void CMatQueuedRenderContext::CompactMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::CompactMemory(CMatQueuedRenderContext *this)
{
  CMatRenderContextBase::CompactMemory(this);
  CMemoryStack::FreeAll(this: &this->m_Vertices, bDecommit: true);
  CMemoryStack::FreeAll(this: &this->m_Indices, bDecommit: true);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF00
// Name: public: void CMatQueuedRenderContext::BeginQueue(class CMatRenderContextBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BeginQueue(
        CMatQueuedRenderContext *this,
        CMatRenderContextBase *pInitialState)
{
  CMatRenderContextBase *m_pHardwareContext; // edi

  m_pHardwareContext = pInitialState;
  if ( pInitialState == nullptr )
    m_pHardwareContext = this->m_pHardwareContext;
  CMatRenderContextBase::InitializeFrom(this, pInitialState: m_pHardwareContext);
  g_pShaderAPI->GetBackBufferDimensions(this: g_pShaderAPI, a2: &this->m_WidthBackBuffer, a3: &this->m_HeightBackBuffer);
  this->m_FogMode = m_pHardwareContext->GetFogMode(this: m_pHardwareContext);
  this->m_nBoneCount = m_pHardwareContext->GetCurrentNumBones(this: m_pHardwareContext);
  m_pHardwareContext->GetFogDistances(
    this: m_pHardwareContext,
    a2: &this->m_flFogStart,
    a3: &this->m_flFogEnd,
    a4: &this->m_flFogZ);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF80
// Name: public: virtual class ICallQueue __near * CMatQueuedRenderContext::GetCallQueue(void)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedRenderContext::CCallQueueExternal *__thiscall CMatQueuedRenderContext::GetCallQueue(
        CMatQueuedRenderContext *this)
{
  return &this->m_CallQueueExternal;
}

//------------------------------------------------------------------------------
// Address: 0x1003CF90
// Name: public: virtual int CMatQueuedRenderContext::GetCurrentNumBones(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedRenderContext::GetCurrentNumBones(CMatQueuedRenderContext *this)
{
  return this->m_nBoneCount;
}

//------------------------------------------------------------------------------
// Address: 0x1003CFA0
// Name: public: virtual enum MaterialFogMode_t CMatQueuedRenderContext::GetFogMode(void)
// Source: json
//------------------------------------------------------------------------------
MaterialFogMode_t __thiscall CMatQueuedRenderContext::GetFogMode(CMatQueuedRenderContext *this)
{
  return this->m_FogMode;
}

//------------------------------------------------------------------------------
// Address: 0x1003CFB0
// Name: public: virtual void CMatQueuedRenderContext::FogColor3ubv(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FogColor3ubv(CMatQueuedRenderContext *this, unsigned __int8 *rgb)
{
  this->FogColor3ub(this, a2: *rgb, a3: rgb[1], a4: rgb[2]);
}

//------------------------------------------------------------------------------
// Address: 0x1003CFE0
// Name: public: virtual void CMatQueuedRenderContext::GetFogColor(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::GetFogColor(CMatQueuedRenderContext *this, color24 *rgb)
{
  *rgb = this->m_FogColor;
}

//------------------------------------------------------------------------------
// Address: 0x1003D010
// Name: public: virtual void CMatQueuedRenderContext::GetFogDistances(float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::GetFogDistances(
        CMatQueuedRenderContext *this,
        float *fStart,
        float *fEnd,
        float *fFogZ)
{
  if ( fStart != nullptr )
    *fStart = this->m_flFogStart;
  if ( fEnd != nullptr )
    *fEnd = this->m_flFogEnd;
  if ( fFogZ != nullptr )
    *fFogZ = this->m_flFogZ;
}

//------------------------------------------------------------------------------
// Address: 0x1003D050
// Name: public: virtual class IIndexBuffer __near * CMatQueuedRenderContext::GetDynamicIndexBuffer(void)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedIndexBuffer *__thiscall CMatQueuedRenderContext::GetDynamicIndexBuffer(CMatQueuedRenderContext *this)
{
  return this->m_pQueuedIndexBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x1003D060
// Name: public: virtual class IMesh __near * CMatQueuedRenderContext::GetDynamicMesh(bool,class IMesh __near *,class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CMatQueuedRenderContext::GetDynamicMesh(
        CMatQueuedRenderContext *this,
        int buffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride,
        IMaterial *pAutoBind)
{
  return ((IMesh *(__thiscall *)(CMatQueuedRenderContext *, _DWORD, _DWORD, int, IMesh *, IMesh *, IMaterial *))this->GetDynamicMeshEx)(
           a1: this,
           a2: 0,
           a3: 0,
           a4: buffered,
           a5: pVertexOverride,
           a6: pIndexOverride,
           a7: pAutoBind);
}

//------------------------------------------------------------------------------
// Address: 0x1003D090
// Name: public: virtual int CMatQueuedRenderContext::GetMaxVerticesToRender(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedRenderContext::GetMaxVerticesToRender(CMatQueuedRenderContext *this, IMaterial *pMaterial)
{
  int v2; // esi
  __int64 v3; // rax
  int v4; // edi
  const char *v5; // eax
  int result; // eax

  v2 = ((int (__thiscall *)(IMaterial *))pMaterial->__vftable[1].Refresh)(a1: pMaterial);
  v3 = ((__int64 (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v2 + 80))(a1: v2);
  v4 = ((int (__thiscall *)(IShaderAPI *, _DWORD, _DWORD))g_pShaderAPI->VertexFormatSize)(
         a1: g_pShaderAPI,
         a2: v3 & 0xFFFFFBFF,
         a3: HIDWORD(v3));
  if ( v4 != 0 )
  {
    result = g_pShaderAPI->GetCurrentDynamicVBSize(this: g_pShaderAPI) / v4;
    if ( result > 0xFFFF )
      return 0xFFFF;
  }
  else
  {
    v5 = (const char *)(**(int (__thiscall ***)(int))v2)(a1: v2);
    _Warning(a1: "bad vertex size for material %s\n", v5);
    return 0xFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003D130
// Name: public: virtual void CMatQueuedRenderContext::GetMaxToRender(class IMesh __near *,bool,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::GetMaxToRender(
        CMatQueuedRenderContext *this,
        IMesh *pMesh,
        bool bMaxUntilFlush,
        int *pMaxVerts,
        int *pMaxIndices)
{
  int v5; // eax

  v5 = g_pShaderAPI->GetCurrentDynamicVBSize(this: g_pShaderAPI) / this->m_pQueuedMesh->m_VertexSize;
  *pMaxVerts = v5;
  if ( v5 > 0xFFFF )
    *pMaxVerts = 0xFFFF;
  *pMaxIndices = 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x1003D180
// Name: public: virtual void CMatQueuedRenderContext::GetWindowSize(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::GetWindowSize(CMatQueuedRenderContext *this, int *width, int *height)
{
  *width = this->m_WidthBackBuffer;
  *height = this->m_HeightBackBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x1003D1A0
// Name: public: void CMatQueuedRenderContext::DeferredDrawPrimList(class IMesh __near *,class CPrimList __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DeferredDrawPrimList(
        CMatQueuedRenderContext *this,
        IMesh *pMesh,
        CPrimList *pLists,
        int nLists)
{
  pMesh->Draw(this: pMesh, a2: pLists, a3: nLists);
}

//------------------------------------------------------------------------------
// Address: 0x1003D1C0
// Name: public: void CMatQueuedRenderContext::DeferredSetFlexMesh(class IMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DeferredSetFlexMesh(
        CMatQueuedRenderContext *this,
        IMesh *pStaticMesh,
        int nVertexOffsetInBytes)
{
  pStaticMesh->SetFlexMesh(
    this: pStaticMesh,
    a2: this->m_pQueuedFlexMesh->m_pMSTActualMesh,
    a3: this->m_pQueuedFlexMesh->m_nMSTActualVertexOffsetInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x1003D1F0
// Name: public: void CMatQueuedRenderContext::DeferredBeginBatch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DeferredBeginBatch(CMatQueuedRenderContext *this)
{
  CMatQueuedMesh *m_pQueuedMesh; // eax
  IMesh *m_pMSTActualMesh; // edx

  m_pQueuedMesh = this->m_pQueuedMesh;
  m_pMSTActualMesh = m_pQueuedMesh->m_pMSTActualMesh;
  m_pQueuedMesh->m_pMSTActualMesh = nullptr;
  this->m_pHardwareContext->BeginBatch(this: this->m_pHardwareContext, a2: m_pMSTActualMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1003D220
// Name: private: void CMatQueuedRenderContext::DeferredDrawInstances(int,struct MeshInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DeferredDrawInstances(
        CMatQueuedRenderContext *this,
        int nInstanceCount,
        const MeshInstanceData_t *pConstInstance)
{
  CMatQueuedIndexBuffer *m_pQueuedIndexBuffer; // eax
  int m_nRTStartIndex; // ebx
  int v5; // edi
  const IIndexBuffer **p_m_pIndexBuffer; // esi
  CMatQueuedRenderContext *v7; // [esp+4h] [ebp-8h]
  IIndexBuffer *pDynamicIndexBuffer; // [esp+8h] [ebp-4h]

  m_pQueuedIndexBuffer = this->m_pQueuedIndexBuffer;
  m_nRTStartIndex = m_pQueuedIndexBuffer->m_nRTStartIndex;
  v7 = this;
  pDynamicIndexBuffer = m_pQueuedIndexBuffer->m_pRTDynamicIndexBuffer;
  if ( m_nRTStartIndex >= 0 && m_pQueuedIndexBuffer->m_pRTDynamicIndexBuffer != nullptr )
  {
    v5 = nInstanceCount;
    if ( nInstanceCount > 0 )
    {
      p_m_pIndexBuffer = &pConstInstance->m_pIndexBuffer;
      do
      {
        if ( (*p_m_pIndexBuffer)->IsDynamic(this: (IIndexBuffer *)*p_m_pIndexBuffer) )
        {
          *(p_m_pIndexBuffer - 10) = (const IIndexBuffer *)((char *)*(p_m_pIndexBuffer - 10) + m_nRTStartIndex);
          *p_m_pIndexBuffer = pDynamicIndexBuffer;
        }
        p_m_pIndexBuffer += 19;
        --v5;
      }
      while ( v5 != 0 );
      v5 = nInstanceCount;
      this = v7;
    }
    this->m_pHardwareContext->DrawInstances(this: this->m_pHardwareContext, a2: v5, a3: pConstInstance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D290
// Name: public: virtual unsigned int CMatQueuedRenderContext::AddLookup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMatQueuedRenderContext::AddLookup(CMatQueuedRenderContext *this, const char *pName)
{
  MaterialLock_t__ *v3; // edi
  unsigned int v4; // ebx

  v3 = this->m_pMaterialSystem->Lock(this: this->m_pMaterialSystem);
  v4 = g_pColorCorrectionSystem->AddLookup(this: g_pColorCorrectionSystem, a2: pName);
  this->m_pMaterialSystem->Unlock(this: this->m_pMaterialSystem, a2: v3);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1003D2E0
// Name: public: virtual bool CMatQueuedRenderContext::RemoveLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::RemoveLookup(CMatQueuedRenderContext *this, unsigned int handle)
{
  MaterialLock_t__ *v3; // edi
  bool v4; // bl

  v3 = this->m_pMaterialSystem->Lock(this: this->m_pMaterialSystem);
  v4 = g_pColorCorrectionSystem->RemoveLookup(this: g_pColorCorrectionSystem, a2: handle);
  this->m_pMaterialSystem->Unlock(this: this->m_pMaterialSystem, a2: v3);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1003D330
// Name: public: virtual void CMatQueuedRenderContext::LockLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::LockLookup(CMatQueuedRenderContext *this, unsigned int handle)
{
  MaterialLock_t__ *v3; // edi

  v3 = this->m_pMaterialSystem->Lock(this: this->m_pMaterialSystem);
  g_pColorCorrectionSystem->LockLookup(this: g_pColorCorrectionSystem, a2: handle);
  this->m_pMaterialSystem->Unlock(this: this->m_pMaterialSystem, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1003D380
// Name: public: virtual void CMatQueuedRenderContext::LoadLookup(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::LoadLookup(
        CMatQueuedRenderContext *this,
        unsigned int handle,
        const char *pLookupName)
{
  MaterialLock_t__ *v4; // edi

  v4 = this->m_pMaterialSystem->Lock(this: this->m_pMaterialSystem);
  g_pColorCorrectionSystem->LoadLookup(this: g_pColorCorrectionSystem, a2: handle, a3: pLookupName);
  this->m_pMaterialSystem->Unlock(this: this->m_pMaterialSystem, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1003D3D0
// Name: public: virtual void CMatQueuedRenderContext::UnlockLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::UnlockLookup(CMatQueuedRenderContext *this, unsigned int handle)
{
  MaterialLock_t__ *v3; // edi

  v3 = this->m_pMaterialSystem->Lock(this: this->m_pMaterialSystem);
  g_pColorCorrectionSystem->UnlockLookup(this: g_pColorCorrectionSystem, a2: handle, a3: true);
  this->m_pMaterialSystem->Unlock(this: this->m_pMaterialSystem, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1003D420
// Name: public: virtual void CMatQueuedRenderContext::ReadPixels(int,int,int,int,unsigned char __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ReadPixels(
        CMatQueuedRenderContext *this,
        int x,
        int y,
        int width,
        int height,
        unsigned __int8 *data,
        ImageFormat dstFormat)
{
  MaterialLock_t__ *v8; // edi

  v8 = this->m_pMaterialSystem->Lock(this: this->m_pMaterialSystem);
  g_pShaderAPI->ReadPixels_2(this: g_pShaderAPI, a2: x, a3: y, a4: width, a5: height, a6: data, a7: dstFormat);
  this->m_pMaterialSystem->Unlock(this: this->m_pMaterialSystem, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x1003D480
// Name: public: virtual void CMatQueuedRenderContext::ReadPixelsAndStretch(struct Rect_t __near *,struct Rect_t __near *,unsigned char __near *,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ReadPixelsAndStretch(
        CMatQueuedRenderContext *this,
        Rect_t *pSrcRect,
        Rect_t *pDstRect,
        unsigned __int8 *pBuffer,
        ImageFormat dstFormat,
        int nDstStride)
{
  MaterialLock_t__ *v7; // edi

  v7 = this->m_pMaterialSystem->Lock(this: this->m_pMaterialSystem);
  g_pShaderAPI->ReadPixels(this: g_pShaderAPI, a2: pSrcRect, a3: pDstRect, a4: pBuffer, a5: dstFormat, a6: nDstStride);
  this->m_pMaterialSystem->Unlock(this: this->m_pMaterialSystem, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1003D6A0
// Name: public: void CMatCallQueue::CallQueued(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::CallQueued(CMatCallQueue *this)
{
  CMatCallQueue::Elem_t *m_pHead; // edi

  m_pHead = this->m_pHead;
  if ( this->m_pHead != nullptr )
  {
    do
    {
      ((void (__thiscall *)(CMatCallQueue::Elem_t *))m_pHead[1].pNext[3].pNext)(a1: &m_pHead[1]);
      ((void (__thiscall *)(CMatCallQueue::Elem_t *, _DWORD))m_pHead[1].pNext[2].pNext)(a1: &m_pHead[1], a2: 0);
      m_pHead = m_pHead->pNext;
    }
    while ( m_pHead != nullptr );
    CMemoryStack::FreeAll(this: &this->m_Allocator, bDecommit: false);
    this->m_pTail = nullptr;
    this->m_pHead = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D6E0
// Name: public: virtual void CCachedPerFrameMeshData::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedPerFrameMeshData::Free(CCachedPerFrameMeshData *this)
{
  if ( this != nullptr )
  {
    this->__vftable = (CCachedPerFrameMeshData_vtbl *)&CCachedPerFrameMeshData::`vftable';
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D700
// Name: public: void CMatQueuedMesh::MST_BuildDynamicBuffers(struct CMatQueuedMesh::MST_MeshInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::MST_BuildDynamicBuffers(
        CMatQueuedMesh *this,
        const CMatQueuedMesh::MST_MeshInfo_t *info)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  this->m_pMSTActualMesh = CMatQueuedMesh::MST_SetupDynamicMesh(
                             this,
                             a2: (int)&savedregs,
                             a3: (int)info,
                             a4: (int)this,
                             info,
                             pExternalMesh: nullptr);
  if ( info->m_pMaterial != nullptr )
    info->m_pMaterial->DecrementReferenceCount(this: info->m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x1003D730
// Name: public: virtual class ICachedPerFrameMeshData __near * CMatQueuedMesh::GetCachedPerFrameMeshData(void)
// Source: json
//------------------------------------------------------------------------------
ICachedPerFrameMeshData *__thiscall CMatQueuedMesh::GetCachedPerFrameMeshData(CMatQueuedMesh *this)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi

  if ( this->m_nVerts == 0 )
    return nullptr;
  v3 = MemAlloc_Alloc(nSize: 0x40u);
  if ( v3 != nullptr )
  {
    *v3 = &CCachedPerFrameMeshData::`vftable';
    v3[2] = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v4[2] = this->m_pOwner->GetCurrentMaterialInternal(this: this->m_pOwner);
  *((_BYTE *)v4 + 24) = 0;
  v4[9] = this->m_pVertexData;
  v4[10] = this->m_nVerts;
  v4[4] = this->m_VertexFormat;
  v4[5] = HIDWORD(this->m_VertexFormat);
  v4[11] = this->m_VertexSize;
  v4[7] = this->m_pVertexOverride;
  *((_BYTE *)v4 + 25) ^= (*((_BYTE *)v4 + 25) ^ this->m_bExternalVB) & 1;
  v4[12] = this->m_pIndexData;
  v4[13] = this->m_nIndices;
  *((_BYTE *)v4 + 25) ^= (*((_BYTE *)v4 + 25) ^ (2 * this->m_bExternalIB)) & 2;
  v4[8] = this->m_pIndexOverride;
  v4[14] = this->m_Type;
  return (ICachedPerFrameMeshData *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1003D7D0
// Name: private: void CMatQueuedIndexBuffer::RT_FreeIndexData(int,enum MaterialIndexFormat_t,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedIndexBuffer::RT_FreeIndexData(
        CMatQueuedIndexBuffer *this,
        int nIndexCount,
        int fmt,
        MaterialIndexFormat_t pIndexData)
{
  this->m_pRTDynamicIndexBuffer = nullptr;
  this->m_nRTStartIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003D7F0
// Name: public: void CMatQueuedRenderContext::CallQueued(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::CallQueued(CMatQueuedRenderContext *this, bool bTermAfterCall)
{
  int v3; // ebx
  int v4; // edi
  CMatCallQueue::Elem_t *m_pHead; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  if ( mat_report_queue_status.m_pParent != nullptr && mat_report_queue_status.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = this->m_Vertices.m_pNextAlloc - this->m_Vertices.m_pBase;
    v4 = this->m_Indices.m_pNextAlloc - this->m_Indices.m_pBase;
    v8 = this->m_queue.m_Allocator.m_pNextAlloc - this->m_queue.m_Allocator.m_pBase;
    m_pHead = this->m_queue.m_pHead;
    v6 = 0;
    v9 = 0;
    if ( m_pHead != nullptr )
    {
      do
      {
        m_pHead = m_pHead->pNext;
        ++v6;
      }
      while ( m_pHead != nullptr );
      v9 = v6;
    }
    v7 = CMatRenderContextBase::RenderDataSizeUsed(this);
    _Msg(
      a1: "%d calls queued for %d bytes in parameters and overhead, %d bytes verts, %d bytes indices, %d bytes other\n",
      v9,
      v8,
      v3,
      v4,
      v7);
  }
  CMatCallQueue::CallQueued(this: &this->m_queue);
  CMemoryStack::FreeAll(this: &this->m_Vertices, bDecommit: false);
  CMemoryStack::FreeAll(this: &this->m_Indices, bDecommit: false);
  if ( bTermAfterCall )
    CMatQueuedRenderContext::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003D8B0
// Name: public: virtual void CMatQueuedRenderContext::FogColor3f(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FogColor3f(CMatQueuedRenderContext *this, float r, float g, float b)
{
  int v4; // eax
  int v5; // esi
  int v6; // edx

  v4 = (int)(float)(b * 255.0);
  v5 = (int)(float)(g * 255.0);
  v6 = (int)(float)(r * 255.0);
  if ( v4 >= 0 )
  {
    if ( v4 > 255 )
      v4 = 255;
  }
  else
  {
    v4 = 0;
  }
  if ( v5 >= 0 )
  {
    if ( v5 > 255 )
      v5 = 255;
  }
  else
  {
    v5 = 0;
  }
  if ( v6 >= 0 )
  {
    if ( v6 > 255 )
      v6 = 255;
    this->FogColor3ub(this, a2: v6, a3: v5, a4: v4);
  }
  else
  {
    this->FogColor3ub(this, a2: 0, a3: v5, a4: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D950
// Name: public: virtual void CMatQueuedRenderContext::FogColor3fv(float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FogColor3fv(CMatQueuedRenderContext *this, const float *rgb)
{
  int v2; // edx
  int v3; // esi
  int v4; // eax

  v2 = (int)(float)(rgb[2] * 255.0);
  v3 = (int)(float)(rgb[1] * 255.0);
  v4 = (int)(float)(*rgb * 255.0);
  if ( v2 >= 0 )
  {
    if ( v2 > 255 )
      v2 = 255;
  }
  else
  {
    v2 = 0;
  }
  if ( v3 >= 0 )
  {
    if ( v3 > 255 )
      v3 = 255;
  }
  else
  {
    v3 = 0;
  }
  if ( v4 >= 0 )
  {
    if ( v4 > 255 )
      v4 = 255;
    this->FogColor3ub(this, a2: v4, a3: v3, a4: v2);
  }
  else
  {
    this->FogColor3ub(this, a2: 0, a3: v3, a4: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D9F0
// Name: public: CMatRenderData<class CPrimList>::~CMatRenderData<class CPrimList>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<CPrimList>::~CMatRenderData<CPrimList>(CMatRenderData<MeshInstanceData_t> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(MeshInstanceData_t *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x1003DA50
// Name: public: class CPrimList __near * CMatRenderData<class CPrimList>::Lock(int,class CPrimList const __near *)
// Source: json
//------------------------------------------------------------------------------
CPrimList *__thiscall CMatRenderData<CPrimList>::Lock(CMatRenderData<CPrimList> *this, int nCount, CPrimList *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  CPrimList *result; // eax
  unsigned int v6; // ebx
  CPrimList *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(CPrimList *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 8 * nCount;
    result = (CPrimList *)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: 8 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003DAD0
// Name: public: CMatQueuedMesh::CMatQueuedMesh(class CMatQueuedRenderContext __near *,class IMatRenderContextInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__thiscall CMatQueuedMesh::CMatQueuedMesh(
        CMatQueuedMesh *this,
        CMatQueuedRenderContext *pOwner,
        IMatRenderContextInternal *pHardwareContext,
        bool bFlexMesh)
{
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&IIndexBuffer::`vftable';
  this->IMesh::IVertexBuffer::__vftable = (CMatQueuedMesh_vtbl *)&CMatQueuedMesh::`vftable'{for `IVertexBuffer'};
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CMatQueuedMesh::`vftable'{for `IIndexBuffer'};
  this->m_nMSTActualVertexOffsetInBytes = 0;
  this->m_pMSTActualMesh = nullptr;
  this->m_pLateBoundMesh.m_ppObject = &this->m_pMSTActualMesh;
  this->m_pOwner = pOwner;
  this->m_pCallQueue = pOwner->GetCallQueueInternal(this: pOwner);
  this->m_pHardwareContext = pHardwareContext;
  this->m_VertexFormat = 0;
  this->m_pVertexData = nullptr;
  this->m_pIndexData = nullptr;
  this->m_nVerts = 0;
  this->m_nIndices = 0;
  this->m_bExternalIB = false;
  this->m_bCanSetAuxMeshes = false;
  this->m_pVertexOverride = nullptr;
  this->m_pIndexOverride = nullptr;
  *(_DWORD *)&this->m_VertexSize = 0;
  this->m_bFlexMesh = bFlexMesh;
  this->m_Type = MATERIAL_TRIANGLES;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003DB50
// Name: public: virtual void CMatQueuedMesh::BeginCastBuffer(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::BeginCastBuffer(CMatQueuedMesh *this, unsigned __int64 format)
{
  if ( `CMatQueuedMesh::BeginCastBuffer'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::BeginCastBuffer'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::BeginCastBuffer'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::BeginCastBuffer'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DB90
// Name: public: virtual void CMatQueuedMesh::EndCastBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::EndCastBuffer(CMatQueuedMesh *this)
{
  if ( `CMatQueuedMesh::EndCastBuffer'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::EndCastBuffer'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::EndCastBuffer'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::EndCastBuffer'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DBD0
// Name: public: virtual int CMatQueuedMesh::GetRoomRemaining(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedMesh::GetRoomRemaining(CMatQueuedMesh *this)
{
  if ( `CMatQueuedMesh::GetRoomRemaining'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::GetRoomRemaining'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::GetRoomRemaining'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::GetRoomRemaining'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003DC10
// Name: public: virtual void __near * CMatQueuedMesh::AccessRawHardwareDataStream(unsigned char,unsigned int,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMatQueuedMesh::AccessRawHardwareDataStream(
        CMatQueuedMesh *this,
        unsigned __int8 nRawStreamIndex,
        unsigned int numBytes,
        unsigned int uiFlags,
        unsigned int pvContext)
{
  if ( `CMatQueuedMesh::AccessRawHardwareDataStream'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::AccessRawHardwareDataStream'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::AccessRawHardwareDataStream'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::AccessRawHardwareDataStream'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003DC60
// Name: public: virtual bool CMatQueuedMesh::Lock(int,bool,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedMesh::Lock(CMatQueuedMesh *this, int nVertexCount, bool bAppend, VertexDesc_t *desc)
{
  if ( `CMatQueuedMesh::Lock'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Lock'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::Lock'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Lock'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1003DCB0
// Name: public: virtual void CMatQueuedMesh::Unlock(int,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::Unlock(CMatQueuedMesh *this, int nVertexCount, VertexDesc_t *desc)
{
  if ( `CMatQueuedMesh::Unlock'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Unlock'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::Unlock'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Unlock'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DCF0
// Name: public: virtual enum MaterialIndexFormat_t CMatQueuedMesh::IndexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
MaterialIndexFormat_t __thiscall CMatQueuedMesh::IndexFormat(CMatQueuedMesh *this)
{
  if ( `CMatQueuedMesh::IndexFormat'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::IndexFormat'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::IndexFormat'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::IndexFormat'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return MATERIAL_INDEX_FORMAT_16BIT;
}

//------------------------------------------------------------------------------
// Address: 0x1003DD30
// Name: public: virtual void CMatQueuedMesh::BeginCastBuffer(enum MaterialIndexFormat_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::BeginCastBuffer(CMatQueuedMesh *this, MaterialIndexFormat_t format)
{
  if ( `CMatQueuedMesh::BeginCastBuffer'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::BeginCastBuffer'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::BeginCastBuffer'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::BeginCastBuffer'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DD70
// Name: public: virtual bool CMatQueuedMesh::Lock(int,bool,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedMesh::Lock(CMatQueuedMesh *this, int nMaxIndexCount, bool bAppend, IndexDesc_t *desc)
{
  if ( `CMatQueuedMesh::Lock'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Lock'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::Lock'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Lock'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1003DDC0
// Name: public: virtual void CMatQueuedMesh::Unlock(int,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::Unlock(CMatQueuedMesh *this, int nWrittenIndexCount, IndexDesc_t *desc)
{
  if ( `CMatQueuedMesh::Unlock'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Unlock'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::Unlock'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Unlock'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DE00
// Name: public: virtual void CMatQueuedMesh::ModifyBegin(bool,int,int,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::ModifyBegin(
        CMatQueuedMesh *this,
        bool bReadOnly,
        int nFirstIndex,
        int nIndexCount,
        IndexDesc_t *desc)
{
  if ( `CMatQueuedMesh::ModifyBegin'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyBegin'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::ModifyBegin'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyBegin'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DE40
// Name: public: virtual void CMatQueuedMesh::ModifyEnd(struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::ModifyEnd(CMatQueuedMesh *this, IndexDesc_t *desc)
{
  if ( `CMatQueuedMesh::ModifyEnd'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyEnd'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::ModifyEnd'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyEnd'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DE80
// Name: public: virtual void CMatQueuedMesh::Draw(class CPrimList __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::Draw(CMatQueuedMesh *this, CPrimList *pLists, CPrimList *nLists)
{
  if ( `CMatQueuedMesh::Draw'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Draw'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::Draw'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::Draw'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DEC0
// Name: public: virtual void CMatQueuedMesh::CopyToMeshBuilder(int,int,int,int,int,class CMeshBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::CopyToMeshBuilder(
        CMatQueuedMesh *this,
        int iStartVert,
        int nVerts,
        int iStartIndex,
        int nIndices,
        int indexOffset,
        CMeshBuilder *builder)
{
  if ( `CMatQueuedMesh::CopyToMeshBuilder'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::CopyToMeshBuilder'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::CopyToMeshBuilder'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::CopyToMeshBuilder'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DF00
// Name: public: virtual void CMatQueuedMesh::ModifyBegin(int,int,int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::ModifyBegin(
        CMatQueuedMesh *this,
        int firstVertex,
        int numVerts,
        int firstIndex,
        int numIndices,
        MeshDesc_t *desc)
{
  if ( `CMatQueuedMesh::ModifyBegin'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyBegin'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::ModifyBegin'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyBegin'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DF40
// Name: public: virtual void CMatQueuedMesh::ModifyEnd(struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::ModifyEnd(CMatQueuedMesh *this, MeshDesc_t *desc)
{
  if ( `CMatQueuedMesh::ModifyEnd'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyEnd'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::ModifyEnd'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyEnd'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DF80
// Name: public: virtual void CMatQueuedMesh::ModifyBeginEx(bool,int,int,int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::ModifyBeginEx(
        CMatQueuedMesh *this,
        bool bReadOnly,
        int firstVertex,
        int numVerts,
        int firstIndex,
        int numIndices,
        MeshDesc_t *desc)
{
  if ( `CMatQueuedMesh::ModifyBeginEx'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyBeginEx'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedMesh::ModifyBeginEx'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedMesh::ModifyBeginEx'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DFF0
// Name: public: bool CMatQueuedMesh::OnGetDynamicMesh(unsigned __int64,unsigned int,class IMesh __near *,class IMesh __near *,class IMaterialInternal __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatQueuedMesh::OnGetDynamicMesh(
        CMatQueuedMesh *this,
        unsigned __int64 vertexFormat,
        unsigned __int8 flags,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride,
        IMaterialInternal *pMaterial,
        int nHWSkinBoneCount)
{
  unsigned __int64 v8; // rax
  int v9; // ecx
  int v10; // eax
  int m_VertexFormat_high; // ecx

  this->m_VertexSize = 0;
  this->m_pIndexOverride = pIndexOverride;
  this->m_nIndices = 0;
  this->m_pIndexData = nullptr;
  this->m_nVerts = 0;
  this->m_VertexFormat = 0;
  this->m_pVertexData = nullptr;
  this->m_bCanSetAuxMeshes = false;
  *(_WORD *)&this->m_bExternalVB = 0;
  this->m_pVertexOverride = pVertexOverride;
  this->m_nFlags = flags;
  if ( this->m_bFlexMesh )
  {
    this->m_VertexFormat = 515;
    if ( g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 92 )
    {
      m_VertexFormat_high = HIDWORD(this->m_VertexFormat);
      LODWORD(this->m_VertexFormat) |= 0x40u;
      HIDWORD(this->m_VertexFormat) = m_VertexFormat_high;
    }
  }
  else if ( pVertexOverride != nullptr )
  {
    this->m_VertexFormat = pVertexOverride->GetVertexFormat(this: pVertexOverride);
  }
  else
  {
    LODWORD(v8) = pMaterial->GetVertexFormat(this: pMaterial) & 0xFFFFFBFF;
    if ( vertexFormat != 0 )
      v8 = vertexFormat;
    this->m_VertexFormat = v8;
    if ( vertexFormat != 0 )
    {
      v9 = nHWSkinBoneCount;
      if ( nHWSkinBoneCount < (unsigned __int8)((vertexFormat >> 12) & 7) )
        v9 = (vertexFormat >> 12) & 7;
    }
    else
    {
      v9 = nHWSkinBoneCount;
    }
    LODWORD(this->m_VertexFormat) &= 0xFFFF8FFF;
    HIDWORD(this->m_VertexFormat) = HIDWORD(v8);
    this->m_VertexFormat |= v9 << 12;
    if ( v9 > 0 )
    {
      v10 = HIDWORD(this->m_VertexFormat);
      LODWORD(this->m_VertexFormat) |= 0x80u;
      HIDWORD(this->m_VertexFormat) = v10;
    }
  }
  this->m_VertexSize = ((int (__thiscall *)(IShaderAPI *, _DWORD, _DWORD))g_pShaderAPI->VertexFormatSize)(
                         a1: g_pShaderAPI,
                         a2: this->m_VertexFormat,
                         a3: HIDWORD(this->m_VertexFormat));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003E110
// Name: public: virtual void CMatQueuedMesh::LockMesh(int,int,struct MeshDesc_t __near &,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::LockMesh(
        CMatQueuedMesh *this,
        int numVerts,
        int numIndices,
        MeshDesc_t *desc,
        MeshBuffersAllocationSettings_t *pSettings)
{
  int v6; // ecx
  int v7; // ebx
  CMatQueuedRenderContext *m_pOwner; // edi
  unsigned int v9; // eax
  unsigned int m_alignment; // ecx
  int v11; // eax
  unsigned __int8 *m_pNextAlloc; // ecx
  unsigned __int8 *v13; // ebx
  MeshDesc_t *v14; // edi
  unsigned int v15; // eax
  CMatQueuedRenderContext *v16; // ebx
  unsigned int v17; // ecx
  int v18; // eax
  unsigned __int16 *v19; // ecx
  unsigned __int8 *v20; // eax
  int numVertsa; // [esp+14h] [ebp+8h]
  int numIndicesa; // [esp+18h] [ebp+Ch]
  MeshDesc_t *desca; // [esp+1Ch] [ebp+10h]

  if ( this->m_pVertexOverride != nullptr )
    v6 = 0;
  else
    v6 = numVerts;
  if ( this->m_pIndexOverride != nullptr )
  {
    v7 = 0;
    numIndices = 0;
  }
  else
  {
    v7 = numIndices;
  }
  this->m_nVerts = v6;
  this->m_nIndices = v7;
  if ( v6 <= 0 )
  {
    v14 = desc;
    this->m_bExternalVB = false;
    desc->m_nFirstVertex = 0;
    desc->VertexDesc_t::m_nOffset = 0;
    ((void (__thiscall *)(IShaderAPI *, _DWORD, _DWORD, _DWORD, MeshDesc_t *))g_pShaderAPI->ComputeVertexDescription)(
      a1: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: 0,
      a5: desc);
    goto LABEL_17;
  }
  m_pOwner = this->m_pOwner;
  v9 = v6 * this->m_VertexSize;
  m_alignment = m_pOwner->m_Vertices.m_alignment;
  if ( v9 <= m_alignment )
    v9 = m_pOwner->m_Vertices.m_alignment;
  v11 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  m_pNextAlloc = m_pOwner->m_Vertices.m_pNextAlloc;
  v13 = &m_pNextAlloc[v11];
  numVertsa = (int)m_pNextAlloc;
  if ( &m_pNextAlloc[v11] <= m_pOwner->m_Vertices.m_pCommitLimit )
    goto LABEL_14;
  if ( CMemoryStack::CommitTo(this: &m_pOwner->m_Vertices, pNextAlloc: &m_pNextAlloc[v11]) )
  {
    m_pNextAlloc = (unsigned __int8 *)numVertsa;
LABEL_14:
    m_pOwner->m_Vertices.m_pNextAlloc = v13;
    goto LABEL_15;
  }
  m_pNextAlloc = nullptr;
LABEL_15:
  v14 = desc;
  this->m_pVertexData = m_pNextAlloc;
  this->m_bExternalVB = false;
  desc->m_nFirstVertex = 0;
  desc->VertexDesc_t::m_nOffset = 0;
  ((void (__thiscall *)(IShaderAPI *, unsigned __int8 *, _DWORD, _DWORD, MeshDesc_t *))g_pShaderAPI->ComputeVertexDescription)(
    a1: g_pShaderAPI,
    a2: this->m_pVertexData,
    a3: this->m_VertexFormat,
    a4: HIDWORD(this->m_VertexFormat),
    a5: desc);
  v7 = numIndices;
LABEL_17:
  if ( this->m_Type != MATERIAL_POINTS && v7 > 0 )
  {
    v15 = 2 * v7;
    v16 = this->m_pOwner;
    v17 = v16->m_Indices.m_alignment;
    if ( v15 <= v17 )
      v15 = v16->m_Indices.m_alignment;
    v18 = ~(v17 - 1) & (v17 + v15 - 1);
    v19 = (unsigned __int16 *)v16->m_Indices.m_pNextAlloc;
    v20 = (unsigned __int8 *)v19 + v18;
    numIndicesa = (int)v19;
    desca = (MeshDesc_t *)v20;
    if ( v20 > v16->m_Indices.m_pCommitLimit )
    {
      if ( !CMemoryStack::CommitTo(this: &v16->m_Indices, pNextAlloc: v20) )
      {
        v19 = nullptr;
LABEL_26:
        this->m_bExternalIB = false;
        this->m_pIndexData = v19;
        v14->m_pIndices = v19;
        v14->m_nIndexSize = 1;
        v14->m_nFirstIndex = 0;
        v14->IndexDesc_t::m_nOffset = 0;
        return;
      }
      v19 = (unsigned __int16 *)numIndicesa;
      v20 = (unsigned __int8 *)desca;
    }
    v16->m_Indices.m_pNextAlloc = v20;
    goto LABEL_26;
  }
  this->m_bExternalIB = false;
  v14->m_pIndices = &CMatQueuedMesh::gm_ScratchIndexBuffer;
  v14->m_nIndexSize = 0;
  v14->m_nFirstIndex = 0;
  v14->IndexDesc_t::m_nOffset = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E2B0
// Name: public: void CMatQueuedRenderContext::Init(class CMaterialSystem __near *,class CMatRenderContextBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Init(
        CMatQueuedRenderContext *this,
        CMaterialSystem *pMaterialSystem,
        CMatRenderContextBase *pHardwareContext)
{
  CMatQueuedMesh *v4; // eax
  CMatQueuedMesh *v5; // eax
  CMatQueuedMesh *v6; // eax
  CMatQueuedMesh *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // edi

  CMatRenderContextBase::Init(this);
  this->m_pMaterialSystem = pMaterialSystem;
  this->m_pHardwareContext = pHardwareContext;
  v4 = (CMatQueuedMesh *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v4 != nullptr )
    v5 = CMatQueuedMesh::CMatQueuedMesh(this: v4, pOwner: this, pHardwareContext, bFlexMesh: false);
  else
    v5 = nullptr;
  this->m_pQueuedMesh = v5;
  v6 = (CMatQueuedMesh *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v6 != nullptr )
    v7 = CMatQueuedMesh::CMatQueuedMesh(this: v6, pOwner: this, pHardwareContext, bFlexMesh: true);
  else
    v7 = nullptr;
  this->m_pQueuedFlexMesh = v7;
  v8 = MemAlloc_Alloc(nSize: 0x28u);
  v9 = v8;
  if ( v8 != nullptr )
  {
    *v8 = &CMatQueuedIndexBuffer::`vftable';
    v8[1] = this;
    v8[2] = this->GetCallQueueInternal(this);
    v9[3] = pHardwareContext;
    v9[4] = 0;
    v9[5] = 0;
    *((_BYTE *)v9 + 24) = 0;
    v9[7] = -1;
    v9[8] = -1;
    v9[9] = 0;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pQueuedIndexBuffer = (CMatQueuedIndexBuffer *)v9;
  CMemoryStack::Init(
    this: &this->m_Vertices,
    pszAllocOwner: "CMatQueuedRenderContext::m_Vertices",
    maxSize: 0x1000000u,
    commitSize: 0x20000u,
    initialCommit: 0,
    alignment: 0x10u);
  CMemoryStack::Init(
    this: &this->m_Indices,
    pszAllocOwner: "CMatQueuedRenderContext::m_Indices",
    maxSize: 0x1000000u,
    commitSize: 0x20000u,
    initialCommit: 0,
    alignment: 0x10u);
}

//------------------------------------------------------------------------------
// Address: 0x1003E400
// Name: public: virtual class IMesh __near * CMatQueuedRenderContext::GetDynamicMeshEx(unsigned __int64,bool,class IMesh __near *,class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__thiscall CMatQueuedRenderContext::GetDynamicMeshEx(
        CMatQueuedRenderContext *this,
        unsigned __int64 vertexFormat,
        unsigned __int8 bBuffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride,
        IMaterial *pAutoBind)
{
  int v8; // eax
  IMaterialInternal *v9; // eax
  int v10; // [esp-4h] [ebp-10h]

  if ( pAutoBind != nullptr )
    this->Bind(this, a2: pAutoBind, a3: nullptr);
  if ( pVertexOverride != nullptr
    && (pIndexOverride != nullptr || (pVertexOverride->GetVertexFormat(this: pVertexOverride) & 0x400) != 0) )
  {
    __debugbreak();
    return nullptr;
  }
  else
  {
    v8 = this->GetCurrentNumBones(this);
    if ( v8 > 1 )
      --v8;
    v10 = v8;
    v9 = this->GetCurrentMaterialInternal(this);
    CMatQueuedMesh::OnGetDynamicMesh(
      this: this->m_pQueuedMesh,
      vertexFormat,
      flags: bBuffered != 0,
      pVertexOverride,
      pIndexOverride,
      pMaterial: v9,
      nHWSkinBoneCount: v10);
    return this->m_pQueuedMesh;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E4A0
// Name: public: virtual class IMesh __near * CMatQueuedRenderContext::GetFlexMesh(void)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__thiscall CMatQueuedRenderContext::GetFlexMesh(CMatQueuedRenderContext *this)
{
  CMatQueuedMesh *m_pQueuedFlexMesh; // esi
  __int64 v3; // rax
  int m_VertexFormat_high; // ecx

  m_pQueuedFlexMesh = this->m_pQueuedFlexMesh;
  m_pQueuedFlexMesh->m_nIndices = 0;
  m_pQueuedFlexMesh->m_pIndexData = nullptr;
  m_pQueuedFlexMesh->m_nVerts = 0;
  m_pQueuedFlexMesh->m_VertexFormat = 0;
  m_pQueuedFlexMesh->m_VertexSize = 0;
  m_pQueuedFlexMesh->m_pVertexData = nullptr;
  m_pQueuedFlexMesh->m_bCanSetAuxMeshes = false;
  *(_WORD *)&m_pQueuedFlexMesh->m_bExternalVB = 0;
  m_pQueuedFlexMesh->m_pVertexOverride = nullptr;
  m_pQueuedFlexMesh->m_pIndexOverride = nullptr;
  m_pQueuedFlexMesh->m_nFlags = 0;
  if ( m_pQueuedFlexMesh->m_bFlexMesh )
  {
    HIDWORD(m_pQueuedFlexMesh->m_VertexFormat) = 0;
    LODWORD(m_pQueuedFlexMesh->m_VertexFormat) = 515;
    if ( g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 92 )
    {
      m_VertexFormat_high = HIDWORD(m_pQueuedFlexMesh->m_VertexFormat);
      LODWORD(m_pQueuedFlexMesh->m_VertexFormat) |= 0x40u;
      HIDWORD(m_pQueuedFlexMesh->m_VertexFormat) = m_VertexFormat_high;
    }
  }
  else
  {
    v3 = ((__int64 (*)(void))*(_DWORD *)(MEMORY[0] + 80))();
    LODWORD(m_pQueuedFlexMesh->m_VertexFormat) = v3 & 0xFFFFFBFF;
    LODWORD(m_pQueuedFlexMesh->m_VertexFormat) &= 0xFFFF8FFF;
    LODWORD(m_pQueuedFlexMesh->m_VertexFormat) = m_pQueuedFlexMesh->m_VertexFormat;
    HIDWORD(m_pQueuedFlexMesh->m_VertexFormat) = HIDWORD(v3);
  }
  m_pQueuedFlexMesh->m_VertexSize = ((int (__thiscall *)(IShaderAPI *, _DWORD, _DWORD))g_pShaderAPI->VertexFormatSize)(
                                      a1: g_pShaderAPI,
                                      a2: m_pQueuedFlexMesh->m_VertexFormat,
                                      a3: HIDWORD(m_pQueuedFlexMesh->m_VertexFormat));
  return this->m_pQueuedFlexMesh;
}

//------------------------------------------------------------------------------
// Address: 0x1003E580
// Name: public: virtual void CMemberFunctor4<class CMatQueuedIndexBuffer __near *,void (CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void __near *,bool),int,enum MaterialIndexFormat_t,void __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, int, MaterialIndexFormat_t, void *, bool))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x1003E5D0
// Name: public: virtual void CMemberFunctor2<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct FlashlightState_t const __near &,class VMatrix const __near &),struct FlashlightState_t,class VMatrix,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, FlashlightState_t *, VMatrix *))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: &this->m_arg1,
    a3: &this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x1003E5F0
// Name: public: CMemberFunctor14<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int),class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor14<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int),class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int),class IMaterial __near * const __near &,int const __near &,int const __near &,int const __near &,int const __near &,float const __near &,float const __near &,float const __near &,float const __near &,int const __near &,int const __near &,void __near * const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterial **arg1,
        int *arg2,
        int *arg3,
        int *arg4,
        int *arg5,
        float *arg6,
        float *arg7,
        float *arg8,
        float *arg9,
        int *arg10,
        int *arg11,
        void **arg12,
        int *arg13,
        int *arg14)
{
  CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result; // eax
  IMaterial **v18; // edx
  __int64 v19; // xmm0_8
  IMaterial *v20; // ecx
  int *v21; // edx
  int v22; // ecx
  int *v23; // edx
  int v24; // ecx
  int *v25; // edx
  int v26; // ecx
  int *v27; // edx
  int v28; // ecx
  float *v29; // edx
  float *v30; // ecx
  double v31; // st7
  float *v32; // edx
  float *v33; // ecx
  double v34; // st7
  int *v35; // edx
  int v36; // ecx
  int *v37; // edx
  int v38; // ecx
  void **v39; // edx
  void *v40; // ecx
  int *v41; // edx
  int v42; // ecx
  int *v43; // edx

  result = this;
  this->m_iRefs = 1;
  v18 = arg1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *(_QWORD *)&this->m_Proxy.m_pfnProxied = pfnProxied;
  v19 = *((_QWORD *)&pfnProxied + 1);
  this->m_Proxy.m_pObject = pObject;
  *((_QWORD *)&this->m_Proxy.m_pfnProxied + 1) = v19;
  v20 = *v18;
  v21 = arg2;
  result->m_arg1 = v20;
  v22 = *v21;
  v23 = arg3;
  result->m_arg2 = v22;
  v24 = *v23;
  v25 = arg4;
  result->m_arg3 = v24;
  v26 = *v25;
  v27 = arg5;
  result->m_arg4 = v26;
  v28 = *v27;
  v29 = arg6;
  result->m_arg5 = v28;
  v30 = arg7;
  result->m_arg6 = *v29;
  v31 = *v30;
  v32 = arg8;
  v33 = arg9;
  result->m_arg7 = v31;
  v34 = *v32;
  v35 = arg10;
  result->m_arg8 = v34;
  result->m_arg9 = *v33;
  v36 = *v35;
  v37 = arg11;
  result->m_arg10 = v36;
  v38 = *v37;
  v39 = arg12;
  result->m_arg11 = v38;
  v40 = *v39;
  v41 = arg13;
  result->m_arg12 = v40;
  v42 = *v41;
  v43 = arg14;
  result->m_arg13 = v42;
  result->m_arg14 = *v43;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E6A0
// Name: public: virtual void CMemberFunctor14<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int),class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, IMaterial *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, void *, int, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5,
    a7: LODWORD(this->m_arg6),
    a8: LODWORD(this->m_arg7),
    a9: LODWORD(this->m_arg8),
    a10: LODWORD(this->m_arg9),
    a11: this->m_arg10,
    a12: this->m_arg11,
    a13: this->m_arg12,
    a14: this->m_arg13,
    a15: this->m_arg14);
}

//------------------------------------------------------------------------------
// Address: 0x1003E710
// Name: public: CMemberFunctor2<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,struct matrix3x4_t const __near &),int,struct matrix3x4_t,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor2<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,struct matrix3x4_t const __near &),int,struct matrix3x4_t,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,struct matrix3x4_t const __near &),int const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        int *arg1,
        const matrix3x4_t *arg2)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *(_QWORD *)&this->m_Proxy.m_pfnProxied = pfnProxied;
  this->m_Proxy.m_pObject = pObject;
  *((_QWORD *)&this->m_Proxy.m_pfnProxied + 1) = *((_QWORD *)&pfnProxied + 1);
  this->m_arg1 = *arg1;
  this->m_arg2 = *arg2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003E790
// Name: public: virtual void CMemberFunctor2<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,class Vector const __near &),int,class Vector,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,Vector const &),int,Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,Vector const &),int,Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, int, Vector *))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: &this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x1003E7B0
// Name: public: virtual void CMemberFunctor4<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *),class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int),int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, int, int, int, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x1003E7D0
// Name: public: virtual void CMemberFunctor3<class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(class IMesh __near *,class CPrimList __near *,int),class IMesh __near *,class CPrimList __near *,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, MaterialPrimitiveType_t, int, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x1003E7F0
// Name: public: virtual void CMemberFunctor3<class IMesh __near *,void (IMesh::*)(class Vector4D const __near &,int,int),class Vector4D,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<IMesh *,void (__thiscall IMesh::*)(Vector4D const &,int,int),Vector4D,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<IMesh *,void (__thiscall IMesh::*)(Vector4D const &,int,int),Vector4D,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, Vector4D *, int, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: &this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x1003E810
// Name: public: virtual void CMemberFunctor2<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,void __near *),class IMaterial __near *,void __near *,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,enum MaterialNonInteractiveMode_t),ITexture *,enum MaterialNonInteractiveMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, ITexture *, MaterialNonInteractiveMode_t))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x1003E860
// Name: public: void CMatQueuedRenderContext::EndQueue(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EndQueue(CMatQueuedRenderContext *this, bool bCallQueued)
{
  int v3; // edx
  int v4; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // ecx
  CMatRenderContextBase::RenderTargetStackElement_t *v6; // ecx
  bool v7; // zf
  ITexture **v8; // ecx
  CMatRenderContextBase::RenderTargetStackElement_t *v9; // ecx
  ITexture **v10; // ecx
  CMatRenderContextBase::RenderTargetStackElement_t *v11; // ecx
  ITexture **v12; // ecx

  if ( bCallQueued )
    CMatQueuedRenderContext::CallQueued(this, bTermAfterCall: false);
  if ( this->m_pCurrentMaterial != nullptr )
    this->m_pCurrentMaterial = nullptr;
  if ( this->m_pUserDefinedLightmap != nullptr )
    this->m_pUserDefinedLightmap = nullptr;
  if ( this->m_pLocalCubemapTexture != nullptr )
    this->m_pLocalCubemapTexture = nullptr;
  if ( this->m_pCurrentFrameBufferCopyTexture[0] != nullptr )
    this->m_pCurrentFrameBufferCopyTexture[0] = nullptr;
  if ( this->m_pCurrentFrameBufferCopyTexture[1] != nullptr )
    this->m_pCurrentFrameBufferCopyTexture[1] = nullptr;
  if ( this->m_pCurrentFrameBufferCopyTexture[2] != nullptr )
    this->m_pCurrentFrameBufferCopyTexture[2] = nullptr;
  if ( this->m_pCurrentFrameBufferCopyTexture[3] != nullptr )
    this->m_pCurrentFrameBufferCopyTexture[3] = nullptr;
  v3 = 0;
  if ( this->m_RenderTargetStack.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
      if ( m_pMemory[v4].m_pRenderTargets[0] != nullptr )
        m_pMemory[v4].m_pRenderTargets[0] = nullptr;
      v6 = this->m_RenderTargetStack.m_Memory.m_pMemory;
      v7 = v6[v4].m_pRenderTargets[1] == nullptr;
      v8 = &v6[v4].m_pRenderTargets[1];
      if ( !v7 )
        *v8 = nullptr;
      v9 = this->m_RenderTargetStack.m_Memory.m_pMemory;
      v7 = v9[v4].m_pRenderTargets[2] == nullptr;
      v10 = &v9[v4].m_pRenderTargets[2];
      if ( !v7 )
        *v10 = nullptr;
      v11 = this->m_RenderTargetStack.m_Memory.m_pMemory;
      v7 = v11[v4].m_pRenderTargets[3] == nullptr;
      v12 = &v11[v4].m_pRenderTargets[3];
      if ( !v7 )
        *v12 = nullptr;
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_RenderTargetStack.m_Size );
  }
  this->m_RenderTargetStack.m_Size = 0;
  this->m_ScissorRectStack.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E910
// Name: public: virtual void CMatQueuedRenderContext::GetRenderTargetDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::GetRenderTargetDimensions(
        CMatQueuedRenderContext *this,
        int *width,
        int *height)
{
  ITexture *v3; // esi

  v3 = this->m_RenderTargetStack.m_Memory.m_pMemory[this->m_RenderTargetStack.m_Size - 1].m_pRenderTargets[0];
  if ( v3 != nullptr )
  {
    *width = v3->GetActualWidth(this: this->m_RenderTargetStack.m_Memory.m_pMemory[this->m_RenderTargetStack.m_Size - 1].m_pRenderTargets[0]);
    *height = v3->GetActualHeight(this: v3);
  }
  else
  {
    *width = this->m_WidthBackBuffer;
    *height = this->m_HeightBackBuffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E970
// Name: public: virtual void CMatQueuedRenderContext::GetViewport(int __near &,int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::GetViewport(
        CMatQueuedRenderContext *this,
        int *x,
        int *y,
        int *width,
        int *height)
{
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // edx
  CMatRenderContextBase::RenderTargetStackElement_t *v6; // esi

  m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
  v6 = &m_pMemory[this->m_RenderTargetStack.m_Size - 1];
  if ( m_pMemory[this->m_RenderTargetStack.m_Size - 1].m_nViewW < 0 || v6->m_nViewH < 0 )
  {
    *y = 0;
    *x = 0;
    if ( v6->m_pRenderTargets[0] != nullptr )
    {
      *width = v6->m_pRenderTargets[0]->GetActualWidth(this: v6->m_pRenderTargets[0]);
      *height = v6->m_pRenderTargets[0]->GetActualHeight(this: v6->m_pRenderTargets[0]);
    }
    else
    {
      *width = this->m_WidthBackBuffer;
      *height = this->m_HeightBackBuffer;
    }
  }
  else
  {
    *x = v6->m_nViewX;
    *y = v6->m_nViewY;
    *width = v6->m_nViewW;
    *height = v6->m_nViewH;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EA10
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedMesh __near *,class CMatQueuedMesh,void,struct CMatQueuedMesh::MST_MeshInfo_t const __near &,struct CMatQueuedMesh::MST_MeshInfo_t>(class CMatQueuedMesh __near *,void (CMatQueuedMesh::*)(struct CMatQueuedMesh::MST_MeshInfo_t const __near &),struct CMatQueuedMesh::MST_MeshInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_MeshInfo_t const &,CMatQueuedMesh::MST_MeshInfo_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedMesh *pObject,
        __int128 pfnProxied,
        const CMatQueuedMesh::MST_MeshInfo_t *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // ebx
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  const CMatQueuedMesh::MST_MeshInfo_t *v10; // esi
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 96;
  if ( m_alignment >= 0x60 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  qmemcpy(m_pNextAlloc + 40, v10, 0x38u);
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EAA0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedMesh __near *,class CMatQueuedMesh,void,struct CMatQueuedMesh::MST_DrawInfo_t const __near &,struct CMatQueuedMesh::MST_DrawInfo_t>(class CMatQueuedMesh __near *,void (CMatQueuedMesh::*)(struct CMatQueuedMesh::MST_DrawInfo_t const __near &),struct CMatQueuedMesh::MST_DrawInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_DrawInfo_t const &,CMatQueuedMesh::MST_DrawInfo_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedMesh *pObject,
        __int128 pfnProxied,
        const CMatQueuedMesh::MST_DrawInfo_t *arg1)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // ebx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 56;
  if ( m_alignment >= 0x38 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CMatQueuedMesh::MST_DrawInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CMatQueuedMesh::MST_DrawInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = *((_QWORD *)&pfnProxied + 1);
  *(CMatQueuedMesh::MST_DrawInfo_t *)(m_pNextAlloc + 40) = *arg1;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EB30
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedMesh __near *,class CMatQueuedMesh,void,struct CMatQueuedMesh::MST_DrawModulatedInfo_t const __near &,struct CMatQueuedMesh::MST_DrawModulatedInfo_t>(class CMatQueuedMesh __near *,void (CMatQueuedMesh::*)(struct CMatQueuedMesh::MST_DrawModulatedInfo_t const __near &),struct CMatQueuedMesh::MST_DrawModulatedInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_DrawModulatedInfo_t const &,CMatQueuedMesh::MST_DrawModulatedInfo_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedMesh *pObject,
        __int128 pfnProxied,
        const CMatQueuedMesh::MST_DrawModulatedInfo_t *arg1)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // ebx
  __int64 v10; // xmm0_8
  CMatQueuedMesh::MST_DrawModulatedInfo_t *v11; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 72;
  if ( m_alignment >= 0x48 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawModulatedInfo_t const &),CMatQueuedMesh::MST_DrawModulatedInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawModulatedInfo_t const &),CMatQueuedMesh::MST_DrawModulatedInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v10 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v11 = arg1;
  *((_QWORD *)m_pNextAlloc + 3) = v10;
  *(CMatQueuedMesh::MST_DrawModulatedInfo_t *)(m_pNextAlloc + 40) = *v11;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EBE0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedIndexBuffer __near *,class CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void __near *,int,enum MaterialIndexFormat_t,void __near *>(class CMatQueuedIndexBuffer __near *,void (CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void __near *),int const __near &,enum MaterialIndexFormat_t const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedIndexBuffer *,CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void *,int,enum MaterialIndexFormat_t,void *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedIndexBuffer *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const MaterialIndexFormat_t *arg2,
        void *const *arg3)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v8; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v10; // eax
  unsigned __int8 *v11; // ebx
  const int *v12; // ecx
  __int64 v13; // xmm0_8
  const MaterialIndexFormat_t *v14; // eax
  void *const *v15; // edx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v8 = 56;
  if ( m_alignment >= 0x38 )
    v8 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v10 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v11 = &m_pAllocator->m_pNextAlloc[v10];
  if ( v11 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v10]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v11;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v12 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v14 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  *((_DWORD *)m_pNextAlloc + 10) = *v12;
  v15 = arg3;
  *((MaterialIndexFormat_t *)m_pNextAlloc + 11) = *v14;
  *((void **)m_pNextAlloc + 12) = *v15;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EC80
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedIndexBuffer __near *,class CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void __near *,bool,int,enum MaterialIndexFormat_t,void __near *,bool>(class CMatQueuedIndexBuffer __near *,void (CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void __near *,bool),int const __near &,enum MaterialIndexFormat_t const __near &,void __near * const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedIndexBuffer *,CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void *,bool,int,enum MaterialIndexFormat_t,void *,bool>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedIndexBuffer *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const MaterialIndexFormat_t *arg2,
        void *const *arg3,
        const bool *arg4)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v9; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  const int *v13; // ecx
  __int64 v14; // xmm0_8
  const MaterialIndexFormat_t *v15; // eax
  void *const *v16; // edx
  const bool *v17; // ecx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v9 = 56;
  if ( m_alignment >= 0x38 )
    v9 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v11 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v12 = &m_pAllocator->m_pNextAlloc[v11];
  if ( v12 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v11]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v12;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v13 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v14 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v15 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v14;
  *((_DWORD *)m_pNextAlloc + 10) = *v13;
  v16 = arg3;
  *((MaterialIndexFormat_t *)m_pNextAlloc + 11) = *v15;
  v17 = arg4;
  *((void **)m_pNextAlloc + 12) = *v16;
  m_pNextAlloc[52] = *v17;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003ED20
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMaterial __near *,void __near *,class IMaterial __near *,void __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,void __near *),class IMaterial __near * const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,void *,IMaterial *,void *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterial *const *arg1,
        void *const *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  IMaterial *const *v11; // ecx
  __int64 v12; // xmm0_8
  void *const *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((IMaterial **)m_pNextAlloc + 10) = *v11;
  *((void **)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EDB0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,struct LightDesc_t const __near *,int,struct LightDesc_t const __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,struct LightDesc_t const __near *),int const __near &,struct LightDesc_t const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,LightDesc_t const *,int,LightDesc_t const *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const LightDesc_t *const *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const int *v11; // ecx
  __int64 v12; // xmm0_8
  const LightDesc_t *const *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((const LightDesc_t **)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EE40
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct MaterialLightingState_t const __near &,struct MaterialLightingState_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct MaterialLightingState_t const __near &),struct MaterialLightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,MaterialLightingState_t const &,MaterialLightingState_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialLightingState_t *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // ebx
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  const MaterialLightingState_t *v10; // esi
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 480;
  if ( m_alignment >= 0x1E0 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(MaterialLightingState_t const &),MaterialLightingState_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(MaterialLightingState_t const &),MaterialLightingState_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  qmemcpy(m_pNextAlloc + 40, v10, 0x1B8u);
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EED0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class Vector,class Vector>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class Vector),class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,Vector,Vector>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const Vector *arg1)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // ebx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 56;
  if ( m_alignment >= 0x38 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = *((_QWORD *)&pfnProxied + 1);
  *(Vector *)(m_pNextAlloc + 40) = *arg1;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EF60
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class Vector4D __near *,class Vector4D __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class Vector4D __near *),class Vector4D __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,Vector4D *,Vector4D *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        Vector4D *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  Vector4D *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector4D *),Vector4D *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector4D *),Vector4D *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((Vector4D **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003EFF0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialFogMode_t,enum MaterialFogMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialFogMode_t,enum MaterialFogMode_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialFogMode_t *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const MaterialFogMode_t *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((MaterialFogMode_t *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F080
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,char const __near *,char const __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(char const __near *),char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,char const *,char const *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const char *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const char *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),char const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),char const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((const char **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F110
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class COcclusionQueryMgr __near *,class COcclusionQueryMgr,void,struct OcclusionQueryObjectHandle_t__ __near *,struct OcclusionQueryObjectHandle_t__ __near *>(class COcclusionQueryMgr __near *,void (COcclusionQueryMgr::*)(struct OcclusionQueryObjectHandle_t__ __near *),struct OcclusionQueryObjectHandle_t__ __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<COcclusionQueryMgr *,COcclusionQueryMgr,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        COcclusionQueryMgr *pObject,
        __int128 pfnProxied,
        OcclusionQueryObjectHandle_t__ *const *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  OcclusionQueryObjectHandle_t__ *const *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((OcclusionQueryObjectHandle_t__ **)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F1A0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct FlashlightState_t const __near &,class VMatrix const __near &,struct FlashlightState_t,class VMatrix>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct FlashlightState_t const __near &,class VMatrix const __near &),struct FlashlightState_t const __near &,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,FlashlightState_t const &,VMatrix const &,FlashlightState_t,VMatrix>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const FlashlightState_t *arg1,
        const VMatrix *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // ebx
  int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // edi
  const FlashlightState_t *v11; // esi
  __int64 v12; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = 360;
  if ( m_alignment >= 0x168 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &m_pNextAlloc[v9];
  if ( &m_pNextAlloc[v9] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  qmemcpy(m_pNextAlloc + 40, v11, 0xFCu);
  qmemcpy(m_pNextAlloc + 292, arg2, 0x40u);
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F240
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,bool,bool,bool>(class CMatRenderContextBase __near *,bool (IMatRenderContext::*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,bool,bool,bool>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const bool *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const bool *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  m_pNextAlloc[40] = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F2D0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class VMatrix const __near &,class VMatrix>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class VMatrix const __near &),class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const VMatrix *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // ebx
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  const VMatrix *v10; // esi
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = 104;
  if ( m_alignment >= 0x68 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  if ( &m_pNextAlloc[v8] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  qmemcpy(m_pNextAlloc + 40, v10, 0x40u);
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F360
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int,class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int),class IMaterial __near * const __near &,int const __near &,int const __near &,int const __near &,int const __near &,float const __near &,float const __near &,float const __near &,float const __near &,int const __near &,int const __near &,void __near * const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterial **arg1,
        int *arg2,
        int *arg3,
        int *arg4,
        int *arg5,
        float *arg6,
        float *arg7,
        float *arg8,
        float *arg9,
        int *arg10,
        int *arg11,
        void **arg12,
        int *arg13,
        int *arg14)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v19; // eax
  CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *m_pNextAlloc; // edi
  int v21; // eax
  unsigned __int8 *v22; // ebx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v19 = 96;
  if ( m_alignment >= 0x60 )
    v19 = m_alignment;
  m_pNextAlloc = (CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)m_pAllocator->m_pNextAlloc;
  v21 = ~(m_alignment - 1) & (m_alignment + v19 - 1);
  v22 = &m_pAllocator->m_pNextAlloc[v21];
  if ( (v22 <= m_pAllocator->m_pCommitLimit
     || CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v21]))
    && (m_pAllocator->m_pNextAlloc = v22, m_pNextAlloc != nullptr) )
  {
    return CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
             this: m_pNextAlloc,
             pObject,
             pfnProxied,
             arg1,
             arg2,
             arg3,
             arg4,
             arg5,
             arg6,
             arg7,
             arg8,
             arg9,
             arg10,
             arg11,
             arg12,
             arg13,
             arg14);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F410
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *,class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *),class ITexture __near * const __near &,int const __near &,struct Rect_t __near * const __near &,struct Rect_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,Rect_t *,Rect_t *,ITexture *,int,Rect_t *,Rect_t *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        const int *arg2,
        Rect_t *const *arg3,
        Rect_t *const *arg4)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v9; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  ITexture *const *v13; // ecx
  __int64 v14; // xmm0_8
  const int *v15; // eax
  Rect_t *const *v16; // edx
  Rect_t *const *v17; // ecx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v9 = 56;
  if ( m_alignment >= 0x38 )
    v9 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v11 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v12 = &m_pAllocator->m_pNextAlloc[v11];
  if ( v12 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v11]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v12;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v13 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v14 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v15 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v14;
  *((ITexture **)m_pNextAlloc + 10) = *v13;
  v16 = arg3;
  *((_DWORD *)m_pNextAlloc + 11) = *v15;
  v17 = arg4;
  *((Rect_t **)m_pNextAlloc + 12) = *v16;
  *((Rect_t **)m_pNextAlloc + 13) = *v17;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F4B0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IMesh __near *,class IMesh,void,int,int,int,int>(class IMesh __near *,void (IMesh::*)(int,int),int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IMesh *,IMesh,void,int,int,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IMesh *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const int *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const int *v11; // ecx
  __int64 v12; // xmm0_8
  const int *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((_DWORD *)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F540
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext,void,class IMesh __near *,class CPrimList __near *,int,class IMesh __near *,class CPrimList __near *,int>(class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(class IMesh __near *,class CPrimList __near *,int),class IMesh __near * const __near &,class CPrimList __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,IMesh *,CPrimList *,int,IMesh *,CPrimList *,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedRenderContext *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        CPrimList *const *arg2,
        const int *arg3)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v8; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v10; // eax
  unsigned __int8 *v11; // ebx
  IMesh *const *v12; // ecx
  __int64 v13; // xmm0_8
  CPrimList *const *v14; // eax
  const int *v15; // edx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v8 = 56;
  if ( m_alignment >= 0x38 )
    v8 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v10 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v11 = &m_pAllocator->m_pNextAlloc[v10];
  if ( v11 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v10]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v11;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v12 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v14 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  *((IMesh **)m_pNextAlloc + 10) = *v12;
  v15 = arg3;
  *((CPrimList **)m_pNextAlloc + 11) = *v14;
  *((_DWORD *)m_pNextAlloc + 12) = *v15;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F5E0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IMesh __near *,class IMesh,void,class Vector4D const __near &,int,int,class Vector4D,int,int>(class IMesh __near *,void (IMesh::*)(class Vector4D const __near &,int,int),class Vector4D const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IMesh *,IMesh,void,Vector4D const &,int,int,Vector4D,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IMesh *pObject,
        __int128 pfnProxied,
        const Vector4D *arg1,
        const int *arg2,
        const int *arg3)
{
  CMemoryStack *m_pAllocator; // edi
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // esi
  int v9; // eax
  int v10; // eax
  unsigned __int8 *v11; // ebx
  const int *v12; // ecx
  __int64 v13; // xmm0_8
  const Vector4D *v14; // eax
  double w; // st7
  const int *v16; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = 64;
  if ( m_alignment >= 0x40 )
    v9 = m_alignment;
  v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v11 = &m_pNextAlloc[v10];
  if ( &m_pNextAlloc[v10] > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pNextAlloc[v10]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v11;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  v12 = arg2;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor3<IMesh *,void (__thiscall IMesh::*)(Vector4D const &,int,int),Vector4D,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor3<IMesh *,void (__thiscall IMesh::*)(Vector4D const &,int,int),Vector4D,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v14 = arg1;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  *((float *)m_pNextAlloc + 10) = v14->x;
  *((float *)m_pNextAlloc + 11) = v14->y;
  *((float *)m_pNextAlloc + 12) = v14->z;
  w = v14->w;
  v16 = arg3;
  *((float *)m_pNextAlloc + 13) = w;
  *((_DWORD *)m_pNextAlloc + 14) = *v12;
  *((_DWORD *)m_pNextAlloc + 15) = *v16;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F690
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext,void,class IMesh __near *,int,class IMesh __near *,int>(class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(class IMesh __near *,int),class IMesh __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,IMesh *,int,IMesh *,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedRenderContext *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        const int *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  IMesh *const *v11; // ecx
  __int64 v12; // xmm0_8
  const int *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((IMesh **)m_pNextAlloc + 10) = *v11;
  *((_DWORD *)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F720
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IMesh __near *,class IMesh,void,class IMesh __near *,int,class IMesh __near *,int>(class IMesh __near *,void (IMesh::*)(class IMesh __near *,int),class IMesh __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IMesh *,IMesh,void,IMesh *,int,IMesh *,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IMesh *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        const int *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  IMesh *const *v11; // ecx
  __int64 v12; // xmm0_8
  const int *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((IMesh **)m_pNextAlloc + 10) = *v11;
  *((_DWORD *)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F7B0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class IMesh __near *,class IMesh,void,enum MaterialPrimitiveType_t,enum MaterialPrimitiveType_t>(class IMesh __near *,void (IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IMesh *,IMesh,void,enum MaterialPrimitiveType_t,enum MaterialPrimitiveType_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        IMesh *pObject,
        __int128 pfnProxied,
        const MaterialPrimitiveType_t *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const MaterialPrimitiveType_t *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<IMesh *,void (__thiscall IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<IMesh *,void (__thiscall IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((MaterialPrimitiveType_t *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F840
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialMatrixMode_t,enum MaterialMatrixMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialMatrixMode_t),enum MaterialMatrixMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialMatrixMode_t,enum MaterialMatrixMode_t>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialMatrixMode_t *arg1)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v6; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v8; // eax
  unsigned __int8 *v9; // ebx
  const MaterialMatrixMode_t *v10; // ecx
  __int64 v11; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v6 = 48;
  if ( m_alignment >= 0x30 )
    v6 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v8 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v9 = &m_pAllocator->m_pNextAlloc[v8];
  if ( v9 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v8]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v9;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v10 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialMatrixMode_t),enum MaterialMatrixMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialMatrixMode_t),enum MaterialMatrixMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v11 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v11;
  *((MaterialMatrixMode_t *)m_pNextAlloc + 10) = *v10;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F8D0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext,void>(class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedRenderContext *,CMatQueuedRenderContext,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedRenderContext *pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx
  __int64 v9; // xmm0_8

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v9 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  *((_QWORD *)m_pNextAlloc + 3) = v9;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F950
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMesh __near *,class IMaterial __near *,class IMesh __near *,class IMaterial __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMesh __near *,class IMaterial __near *),class IMesh __near * const __near &,class IMaterial __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMesh *,IMaterial *,IMesh *,IMaterial *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        IMaterial *const *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  IMesh *const *v11; // ecx
  __int64 v12; // xmm0_8
  IMaterial *const *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((IMesh **)m_pNextAlloc + 10) = *v11;
  *((IMaterial **)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003F9E0
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialPrimitiveType_t,int,int,enum MaterialPrimitiveType_t,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialPrimitiveType_t,int,int,enum MaterialPrimitiveType_t,int,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialPrimitiveType_t *arg1,
        const int *arg2,
        const int *arg3)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v8; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v10; // eax
  unsigned __int8 *v11; // ebx
  const MaterialPrimitiveType_t *v12; // ecx
  __int64 v13; // xmm0_8
  const int *v14; // eax
  const int *v15; // edx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v8 = 56;
  if ( m_alignment >= 0x38 )
    v8 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v10 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v11 = &m_pAllocator->m_pNextAlloc[v10];
  if ( v11 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v10]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v11;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v12 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v13 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v14 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v13;
  *((MaterialPrimitiveType_t *)m_pNextAlloc + 10) = *v12;
  v15 = arg3;
  *((_DWORD *)m_pNextAlloc + 11) = *v14;
  *((_DWORD *)m_pNextAlloc + 12) = *v15;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003FA80
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext,void,int,struct MeshInstanceData_t const __near *,int,struct MeshInstanceData_t const __near *>(class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(int,struct MeshInstanceData_t const __near *),int const __near &,struct MeshInstanceData_t const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,int,MeshInstanceData_t const *,int,MeshInstanceData_t const *>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CMatQueuedRenderContext *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const MeshInstanceData_t *const *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx
  const int *v11; // ecx
  __int64 v12; // xmm0_8
  const MeshInstanceData_t *const *v13; // eax

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  v11 = arg1;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_QWORD *)m_pNextAlloc + 2) = pfnProxied;
  v12 = *((_QWORD *)&pfnProxied + 1);
  *((_DWORD *)m_pNextAlloc + 8) = pObject;
  v13 = arg2;
  *((_QWORD *)m_pNextAlloc + 3) = v12;
  *((_DWORD *)m_pNextAlloc + 10) = *v11;
  *((const MeshInstanceData_t **)m_pNextAlloc + 11) = *v13;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1003FB10
// Name: public: virtual void CMemberFunctor2<class CLateBoundPtr<class IMesh>,void (IMesh::*)(class IMesh __near *,int),class IMesh __near *,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, IMesh *, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)*this->m_Proxy.m_pObject.m_ppObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x1003FB30
// Name: public: virtual void CMemberFunctor0<class CLateBoundPtr<class IMesh>,void (IMesh::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)*this->m_Proxy.m_pObject.m_ppObject + DWORD1(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x1003FB40
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedMesh __near *,class CMatQueuedMesh,void,struct CMatQueuedMesh::MST_MeshInfo_t const __near &,struct CMatQueuedMesh::MST_MeshInfo_t>(class CMatQueuedMesh __near *,void (CMatQueuedMesh::*)(struct CMatQueuedMesh::MST_MeshInfo_t const __near &),struct CMatQueuedMesh::MST_MeshInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_MeshInfo_t const &,CMatQueuedMesh::MST_MeshInfo_t>(
        CMatCallQueue *this,
        CMatQueuedMesh *pObject,
        __int128 pfnProxied,
        const CMatQueuedMesh::MST_MeshInfo_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_MeshInfo_t const &,CMatQueuedMesh::MST_MeshInfo_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003FBD0
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedMesh __near *,class CMatQueuedMesh,void,struct CMatQueuedMesh::MST_DrawInfo_t const __near &,struct CMatQueuedMesh::MST_DrawInfo_t>(class CMatQueuedMesh __near *,void (CMatQueuedMesh::*)(struct CMatQueuedMesh::MST_DrawInfo_t const __near &),struct CMatQueuedMesh::MST_DrawInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_DrawInfo_t const &,CMatQueuedMesh::MST_DrawInfo_t>(
        CMatCallQueue *this,
        CMatQueuedMesh *pObject,
        __int128 pfnProxied,
        const CMatQueuedMesh::MST_DrawInfo_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_DrawInfo_t const &,CMatQueuedMesh::MST_DrawInfo_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003FC60
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedMesh __near *,class CMatQueuedMesh,void,struct CMatQueuedMesh::MST_DrawModulatedInfo_t const __near &,struct CMatQueuedMesh::MST_DrawModulatedInfo_t>(class CMatQueuedMesh __near *,void (CMatQueuedMesh::*)(struct CMatQueuedMesh::MST_DrawModulatedInfo_t const __near &),struct CMatQueuedMesh::MST_DrawModulatedInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_DrawModulatedInfo_t const &,CMatQueuedMesh::MST_DrawModulatedInfo_t>(
        CMatCallQueue *this,
        CMatQueuedMesh *pObject,
        __int128 pfnProxied,
        const CMatQueuedMesh::MST_DrawModulatedInfo_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_DrawModulatedInfo_t const &,CMatQueuedMesh::MST_DrawModulatedInfo_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003FCF0
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedIndexBuffer __near *,class CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void __near *,int,enum MaterialIndexFormat_t,void __near *>(class CMatQueuedIndexBuffer __near *,void (CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void __near *),int const __near &,enum MaterialIndexFormat_t const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedIndexBuffer *,CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void *,int,enum MaterialIndexFormat_t,void *>(
        CMatCallQueue *this,
        CMatQueuedIndexBuffer *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const MaterialIndexFormat_t *arg2,
        void *const *arg3)
{
  unsigned int m_alignment; // eax
  int v8; // ecx
  int v9; // ecx
  unsigned __int8 *v10; // edi
  CFunctor *v11; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v8 = 4;
  if ( m_alignment >= 4 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &this->m_Allocator.m_pNextAlloc[v9];
  if ( v10 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v9]) )
  {
    this->m_Allocator.m_pNextAlloc = v10;
  }
  v11 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedIndexBuffer *,CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void *,int,enum MaterialIndexFormat_t,void *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v11[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003FD90
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedIndexBuffer __near *,class CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void __near *,bool,int,enum MaterialIndexFormat_t,void __near *,bool>(class CMatQueuedIndexBuffer __near *,void (CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void __near *,bool),int const __near &,enum MaterialIndexFormat_t const __near &,void __near * const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedIndexBuffer *,CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void *,bool,int,enum MaterialIndexFormat_t,void *,bool>(
        CMatCallQueue *this,
        CMatQueuedIndexBuffer *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const MaterialIndexFormat_t *arg2,
        void *const *arg3,
        const bool *arg4)
{
  unsigned int m_alignment; // eax
  int v9; // ecx
  int v10; // ecx
  unsigned __int8 *v11; // edi
  CFunctor *v12; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v9 = 4;
  if ( m_alignment >= 4 )
    v9 = m_alignment;
  v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v11 = &this->m_Allocator.m_pNextAlloc[v10];
  if ( v11 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v10]) )
  {
    this->m_Allocator.m_pNextAlloc = v11;
  }
  v12 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedIndexBuffer *,CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void *,bool,int,enum MaterialIndexFormat_t,void *,bool>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v12[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003FE30
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMaterial __near *,void __near *,class IMaterial __near *,void __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,void __near *),class IMaterial __near * const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,void *,IMaterial *,void *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterial *const *arg1,
        void *const *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,void *,IMaterial *,void *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003FED0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,struct LightDesc_t const __near *,int,struct LightDesc_t const __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,struct LightDesc_t const __near *),int const __near &,struct LightDesc_t const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,LightDesc_t const *,int,LightDesc_t const *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const LightDesc_t *const *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,int,LightDesc_t const *,int,LightDesc_t const *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003FF70
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct MaterialLightingState_t const __near &,struct MaterialLightingState_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct MaterialLightingState_t const __near &),struct MaterialLightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,MaterialLightingState_t const &,MaterialLightingState_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialLightingState_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,MaterialLightingState_t const &,MaterialLightingState_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040000
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class Vector,class Vector>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class Vector),class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,Vector,Vector>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const Vector *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,Vector,Vector>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040090
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class Vector4D __near * const,class Vector4D __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class Vector4D __near *),class Vector4D __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,Vector4D * const,Vector4D *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        Vector4D *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,Vector4D *,Vector4D *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040120
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialFogMode_t,enum MaterialFogMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialFogMode_t,enum MaterialFogMode_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialFogMode_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialFogMode_t,enum MaterialFogMode_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100401B0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,char const __near *,char const __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(char const __near *),char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,char const *,char const *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const char *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,char const *,char const *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040240
// Name: public: void CMatCallQueue::QueueCall<class COcclusionQueryMgr __near *,class COcclusionQueryMgr,void,struct OcclusionQueryObjectHandle_t__ __near *,struct OcclusionQueryObjectHandle_t__ __near *>(class COcclusionQueryMgr __near *,void (COcclusionQueryMgr::*)(struct OcclusionQueryObjectHandle_t__ __near *),struct OcclusionQueryObjectHandle_t__ __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<COcclusionQueryMgr *,COcclusionQueryMgr,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
        CMatCallQueue *this,
        COcclusionQueryMgr *pObject,
        __int128 pfnProxied,
        OcclusionQueryObjectHandle_t__ *const *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<COcclusionQueryMgr *,COcclusionQueryMgr,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100402D0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,struct FlashlightState_t const __near &,class VMatrix const __near &,struct FlashlightState_t,class VMatrix>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(struct FlashlightState_t const __near &,class VMatrix const __near &),struct FlashlightState_t const __near &,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,FlashlightState_t const &,VMatrix const &,FlashlightState_t,VMatrix>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const FlashlightState_t *arg1,
        const VMatrix *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,FlashlightState_t const &,VMatrix const &,FlashlightState_t,VMatrix>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040370
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,bool,bool,bool>(class CMatRenderContextBase __near *,bool (IMatRenderContext::*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,bool,bool,bool>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const bool *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,bool,bool,bool>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040400
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class VMatrix const __near &,class VMatrix>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class VMatrix const __near &),class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const VMatrix *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040490
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int,class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int),class IMaterial __near * const __near &,int const __near &,int const __near &,int const __near &,int const __near &,float const __near &,float const __near &,float const __near &,float const __near &,int const __near &,int const __near &,void __near * const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMaterial **arg1,
        int *arg2,
        int *arg3,
        int *arg4,
        int *arg5,
        float *arg6,
        float *arg7,
        float *arg8,
        float *arg9,
        int *arg10,
        int *arg11,
        void **arg12,
        int *arg13,
        int *arg14)
{
  unsigned int m_alignment; // eax
  int v19; // ecx
  int v20; // ecx
  unsigned __int8 *v21; // edi
  CMemberFunctor14<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int),IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v22; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_arg14; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v19 = 4;
  if ( m_alignment >= 4 )
    v19 = m_alignment;
  v20 = ~(m_alignment - 1) & (m_alignment + v19 - 1);
  v21 = &this->m_Allocator.m_pNextAlloc[v20];
  if ( v21 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v20]) )
  {
    this->m_Allocator.m_pNextAlloc = v21;
  }
  v22 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4,
          arg5,
          arg6,
          arg7,
          arg8,
          arg9,
          arg10,
          arg11,
          arg12,
          arg13,
          arg14);
  m_pTail = this->m_pTail;
  p_m_arg14 = (CMatCallQueue::Elem_t *)&v22[-1].m_arg14;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_arg14;
  else
    this->m_pHead = p_m_arg14;
  this->m_pTail = p_m_arg14;
  p_m_arg14->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040560
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,int,struct matrix3x4_t const __near &,int,struct matrix3x4_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(int,struct matrix3x4_t const __near &),int const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,matrix3x4_t const &,int,matrix3x4_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        int *arg1,
        const matrix3x4_t *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  unsigned __int8 *v8; // esi
  CMemoryStack *m_pAllocator; // esi
  unsigned int v10; // ecx
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *m_pNextAlloc; // edi
  int v12; // eax
  int v13; // eax
  unsigned __int8 *v14; // ebx
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v15; // eax
  CMatCallQueue::Elem_t *m_pTail; // edx
  CMatCallQueue::Elem_t *v17; // eax
  CMatCallQueue *v18; // [esp+4h] [ebp-4h]

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = &this->m_Allocator.m_pNextAlloc[~(m_alignment - 1) & (m_alignment + v7 - 1)];
  v18 = this;
  if ( v8 <= this->m_Allocator.m_pCommitLimit || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: v8) )
    this->m_Allocator.m_pNextAlloc = v8;
  m_pAllocator = this->m_FunctorFactory.m_pAllocator;
  v10 = m_pAllocator->m_alignment;
  m_pNextAlloc = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)m_pAllocator->m_pNextAlloc;
  v12 = 96;
  if ( v10 >= 0x60 )
    v12 = m_pAllocator->m_alignment;
  v13 = ~(v10 - 1) & (v10 + v12 - 1);
  v14 = (unsigned __int8 *)m_pNextAlloc + v13;
  if ( ((unsigned __int8 *)((unsigned int)m_pNextAlloc + v13) <= m_pAllocator->m_pCommitLimit
     || CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: (unsigned __int8 *)m_pNextAlloc + v13))
    && (m_pAllocator->m_pNextAlloc = v14, m_pNextAlloc != nullptr) )
  {
    v15 = CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
            this: m_pNextAlloc,
            pObject,
            pfnProxied,
            arg1,
            arg2);
  }
  else
  {
    v15 = nullptr;
  }
  m_pTail = v18->m_pTail;
  v17 = (CMatCallQueue::Elem_t *)(&v15[-1].m_arg2 + 1);
  if ( m_pTail != nullptr )
    m_pTail->pNext = v17;
  else
    v18->m_pHead = v17;
  v18->m_pTail = v17;
  v17->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040640
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *,class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *),class ITexture __near * const __near &,int const __near &,struct Rect_t __near * const __near &,struct Rect_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,Rect_t *,Rect_t *,ITexture *,int,Rect_t *,Rect_t *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1,
        const int *arg2,
        Rect_t *const *arg3,
        Rect_t *const *arg4)
{
  unsigned int m_alignment; // eax
  int v9; // ecx
  int v10; // ecx
  unsigned __int8 *v11; // edi
  CFunctor *v12; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v9 = 4;
  if ( m_alignment >= 4 )
    v9 = m_alignment;
  v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  v11 = &this->m_Allocator.m_pNextAlloc[v10];
  if ( v11 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v10]) )
  {
    this->m_Allocator.m_pNextAlloc = v11;
  }
  v12 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,Rect_t *,Rect_t *,ITexture *,int,Rect_t *,Rect_t *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3,
          arg4);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v12[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100406E0
// Name: public: void CMatCallQueue::QueueCall<class IMesh __near *,class IMesh,void,int,int,int,int>(class IMesh __near *,void (IMesh::*)(int,int),int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IMesh *,IMesh,void,int,int,int,int>(
        CMatCallQueue *this,
        IMesh *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const int *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IMesh *,IMesh,void,int,int,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040780
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext,void,class IMesh __near *,class CPrimList __near *,int,class IMesh __near *,class CPrimList __near *,int>(class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(class IMesh __near *,class CPrimList __near *,int),class IMesh __near * const __near &,class CPrimList __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,IMesh *,CPrimList *,int,IMesh *,CPrimList *,int>(
        CMatCallQueue *this,
        CMatQueuedRenderContext *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        CPrimList *const *arg2,
        const int *arg3)
{
  unsigned int m_alignment; // eax
  int v8; // ecx
  int v9; // ecx
  unsigned __int8 *v10; // edi
  CFunctor *v11; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v8 = 4;
  if ( m_alignment >= 4 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &this->m_Allocator.m_pNextAlloc[v9];
  if ( v10 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v9]) )
  {
    this->m_Allocator.m_pNextAlloc = v10;
  }
  v11 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,IMesh *,CPrimList *,int,IMesh *,CPrimList *,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v11[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040820
// Name: public: void CMatCallQueue::QueueCall<class IMesh __near *,class IMesh,void,class Vector4D const __near &,int,int,class Vector4D,int,int>(class IMesh __near *,void (IMesh::*)(class Vector4D const __near &,int,int),class Vector4D const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IMesh *,IMesh,void,Vector4D const &,int,int,Vector4D,int,int>(
        CMatCallQueue *this,
        IMesh *pObject,
        __int128 pfnProxied,
        const Vector4D *arg1,
        const int *arg2,
        const int *arg3)
{
  unsigned int m_alignment; // eax
  int v8; // ecx
  int v9; // ecx
  unsigned __int8 *v10; // edi
  CFunctor *v11; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v8 = 4;
  if ( m_alignment >= 4 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &this->m_Allocator.m_pNextAlloc[v9];
  if ( v10 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v9]) )
  {
    this->m_Allocator.m_pNextAlloc = v10;
  }
  v11 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IMesh *,IMesh,void,Vector4D const &,int,int,Vector4D,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v11[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100408C0
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext,void,class IMesh __near *,int,class IMesh __near *,int>(class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(class IMesh __near *,int),class IMesh __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,IMesh *,int,IMesh *,int>(
        CMatCallQueue *this,
        CMatQueuedRenderContext *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        const int *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,IMesh *,int,IMesh *,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040960
// Name: public: void CMatCallQueue::QueueCall<class IMesh __near *,class IMesh,void,class IMesh __near *,int,class IMesh __near *,int>(class IMesh __near *,void (IMesh::*)(class IMesh __near *,int),class IMesh __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IMesh *,IMesh,void,IMesh *,int,IMesh *,int>(
        CMatCallQueue *this,
        IMesh *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        const int *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IMesh *,IMesh,void,IMesh *,int,IMesh *,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040A00
// Name: public: void CMatCallQueue::QueueCall<class IMesh __near *,class IMesh,void,enum MaterialPrimitiveType_t,enum MaterialPrimitiveType_t>(class IMesh __near *,void (IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<IMesh *,IMesh,void,enum MaterialPrimitiveType_t,enum MaterialPrimitiveType_t>(
        CMatCallQueue *this,
        IMesh *pObject,
        __int128 pfnProxied,
        const MaterialPrimitiveType_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<IMesh *,IMesh,void,enum MaterialPrimitiveType_t,enum MaterialPrimitiveType_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040A90
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialMatrixMode_t,enum MaterialMatrixMode_t>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialMatrixMode_t),enum MaterialMatrixMode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialMatrixMode_t,enum MaterialMatrixMode_t>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialMatrixMode_t *arg1)
{
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  CFunctor *v9; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &this->m_Allocator.m_pNextAlloc[v7];
  if ( v8 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v7]) )
  {
    this->m_Allocator.m_pNextAlloc = v8;
  }
  v9 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialMatrixMode_t,enum MaterialMatrixMode_t>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied,
         arg1);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v9[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040B20
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext,void>(class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedRenderContext *,CMatQueuedRenderContext,void>(
        CMatCallQueue *this,
        CMatQueuedRenderContext *pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedRenderContext *,CMatQueuedRenderContext,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040BB0
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,class IMesh __near *,class IMaterial __near *,class IMesh __near *,class IMaterial __near *>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class IMesh __near *,class IMaterial __near *),class IMesh __near * const __near &,class IMaterial __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMesh *,IMaterial *,IMesh *,IMaterial *>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        IMaterial *const *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,IMesh *,IMaterial *,IMesh *,IMaterial *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040C50
// Name: public: void CMatCallQueue::QueueCall<class CMatRenderContextBase __near *,class IMatRenderContext,void,enum MaterialPrimitiveType_t,int,int,enum MaterialPrimitiveType_t,int,int>(class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialPrimitiveType_t,int,int,enum MaterialPrimitiveType_t,int,int>(
        CMatCallQueue *this,
        CMatRenderContextBase *pObject,
        __int128 pfnProxied,
        const MaterialPrimitiveType_t *arg1,
        const int *arg2,
        const int *arg3)
{
  unsigned int m_alignment; // eax
  int v8; // ecx
  int v9; // ecx
  unsigned __int8 *v10; // edi
  CFunctor *v11; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v8 = 4;
  if ( m_alignment >= 4 )
    v8 = m_alignment;
  v9 = ~(m_alignment - 1) & (m_alignment + v8 - 1);
  v10 = &this->m_Allocator.m_pNextAlloc[v9];
  if ( v10 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v9]) )
  {
    this->m_Allocator.m_pNextAlloc = v10;
  }
  v11 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialPrimitiveType_t,int,int,enum MaterialPrimitiveType_t,int,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2,
          arg3);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v11[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040CF0
// Name: public: void CMatCallQueue::QueueCall<class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext,void,int,struct MeshInstanceData_t const __near *,int,struct MeshInstanceData_t const __near *>(class CMatQueuedRenderContext __near *,void (CMatQueuedRenderContext::*)(int,struct MeshInstanceData_t const __near *),int const __near &,struct MeshInstanceData_t const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,int,MeshInstanceData_t const *,int,MeshInstanceData_t const *>(
        CMatCallQueue *this,
        CMatQueuedRenderContext *pObject,
        __int128 pfnProxied,
        const int *arg1,
        const MeshInstanceData_t *const *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,int,MeshInstanceData_t const *,int,MeshInstanceData_t const *>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10040D90
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CLateBoundPtr<class IMesh>,class IMesh,void,class IMesh __near *,int,class IMesh __near *,int>(class CLateBoundPtr<class IMesh>,void (IMesh::*)(class IMesh __near *,int),class IMesh __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CLateBoundPtr<IMesh>,IMesh,void,IMesh *,int,IMesh *,int>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CLateBoundPtr<IMesh> pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        const int *arg2)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v9; // eax
  unsigned __int8 *v10; // ebx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v7 = 48;
  if ( m_alignment >= 0x30 )
    v7 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v9 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v10 = &m_pAllocator->m_pNextAlloc[v9];
  if ( v10 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v9]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v10;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor2<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor2<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_OWORD *)m_pNextAlloc + 1) = pfnProxied;
  *((CLateBoundPtr<IMesh> *)m_pNextAlloc + 8) = pObject;
  *((IMesh **)m_pNextAlloc + 10) = *arg1;
  *((_DWORD *)m_pNextAlloc + 11) = *arg2;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10040E20
// Name: public: class CFunctor __near * CCustomizedFunctorFactory<class CMemoryStack,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>>::CreateFunctor<class CLateBoundPtr<class IMesh>,class IMesh,void>(class CLateBoundPtr<class IMesh>,void (IMesh::*)(void))
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CLateBoundPtr<IMesh>,IMesh,void>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this,
        CLateBoundPtr<IMesh> pObject,
        __int128 pfnProxied)
{
  CMemoryStack *m_pAllocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  unsigned __int8 *m_pNextAlloc; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebx

  m_pAllocator = this->m_pAllocator;
  m_alignment = this->m_pAllocator->m_alignment;
  v5 = 40;
  if ( m_alignment >= 0x28 )
    v5 = m_alignment;
  m_pNextAlloc = m_pAllocator->m_pNextAlloc;
  v7 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v8 = &m_pAllocator->m_pNextAlloc[v7];
  if ( v8 > m_pAllocator->m_pCommitLimit
    && !CMemoryStack::CommitTo(this: m_pAllocator, pNextAlloc: &m_pAllocator->m_pNextAlloc[v7]) )
  {
    return nullptr;
  }
  m_pAllocator->m_pNextAlloc = v8;
  if ( m_pNextAlloc == nullptr )
    return nullptr;
  *((_DWORD *)m_pNextAlloc + 3) = 1;
  *(_DWORD *)m_pNextAlloc = &CMemberFunctor0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)m_pNextAlloc + 2) = &CMemberFunctor0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  *((_OWORD *)m_pNextAlloc + 1) = pfnProxied;
  *((CLateBoundPtr<IMesh> *)m_pNextAlloc + 8) = pObject;
  return (CFunctor *)m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10040EA0
// Name: public: void CMatQueuedMesh::QueueBuild(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::QueueBuild(CMatQueuedMesh *this)
{
  IMaterialInternal *v2; // eax
  int m_nVerts; // edx
  int m_VertexSize; // ecx
  int m_VertexFormat_high; // edx
  MaterialPrimitiveType_t m_Type; // ecx
  IMesh *m_pIndexOverride; // edx
  CMatCallQueue *m_pCallQueue; // ecx
  CMatQueuedMesh::MST_MeshInfo_t info; // [esp+8h] [ebp-48h] BYREF
  void (__thiscall *v10)(CMatQueuedMesh *, const CMatQueuedMesh::MST_MeshInfo_t *); // [esp+40h] [ebp-10h]
  int v11; // [esp+44h] [ebp-Ch]
  __int64 v12; // [esp+48h] [ebp-8h]

  if ( this->m_pVertexOverride != nullptr
    || this->m_nVerts != 0
    || this->m_pIndexOverride != nullptr
    || this->m_nIndices != 0 )
  {
    v2 = this->m_pOwner->GetCurrentMaterialInternal(this: this->m_pOwner);
    m_nVerts = this->m_nVerts;
    info.m_pVertexData = this->m_pVertexData;
    LODWORD(info.m_VertexFormat) = this->m_VertexFormat;
    m_VertexSize = this->m_VertexSize;
    info.m_nVertexCount = m_nVerts;
    m_VertexFormat_high = HIDWORD(this->m_VertexFormat);
    info.m_nVertexSizeInBytes = m_VertexSize;
    LOBYTE(m_VertexSize) = this->m_bExternalVB;
    HIDWORD(info.m_VertexFormat) = m_VertexFormat_high;
    info.m_pVertexOverride = this->m_pVertexOverride;
    info.m_pIndexData = this->m_pIndexData;
    info.m_nIndexCount = this->m_nIndices;
    LOBYTE(m_VertexFormat_high) = ((*((_BYTE *)&info + 17)
                                  ^ m_VertexSize)
                                 & 1
                                 ^ *((_BYTE *)&info + 17)
                                 ^ (2 * this->m_bExternalIB))
                                & 2
                                ^ (*((_BYTE *)&info + 17)
                                 ^ m_VertexSize)
                                & 1
                                ^ *((_BYTE *)&info + 17);
    m_Type = this->m_Type;
    *((_BYTE *)&info + 17) = m_VertexFormat_high;
    m_pIndexOverride = this->m_pIndexOverride;
    info.m_pMaterial = v2;
    info.m_nFlags = 0;
    info.m_pIndexOverride = m_pIndexOverride;
    info.m_nPrimitiveType = m_Type;
    if ( v2 != nullptr )
      v2->IncrementReferenceCount(this: v2);
    m_pCallQueue = this->m_pCallQueue;
    v10 = CMatQueuedMesh::MST_BuildDynamicBuffers;
    v11 = 0;
    v12 = 0;
    CMatCallQueue::QueueCall<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_MeshInfo_t const &,CMatQueuedMesh::MST_MeshInfo_t>(
      this: m_pCallQueue,
      pObject: this,
      pfnProxied: (unsigned int)CMatQueuedMesh::MST_BuildDynamicBuffers,
      arg1: &info);
    this->m_bCanSetAuxMeshes = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040F80
// Name: public: virtual void CMatQueuedMesh::Draw(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::Draw(CMatQueuedMesh *this, int firstIndex, int numIndices)
{
  int m_nVerts; // esi
  MaterialPrimitiveType_t m_Type; // eax
  CMatQueuedMesh::MST_DrawInfo_t info; // [esp+14h] [ebp-Ch] BYREF

  m_nVerts = this->m_nVerts;
  if ( (m_nVerts != 0 || this->m_pVertexOverride != nullptr
                      || this->m_nIndices != 0
                      || this->m_pIndexOverride != nullptr)
    && ((m_Type = this->m_Type) != MATERIAL_INSTANCED_QUADS && m_Type != MATERIAL_POINTS
     || m_nVerts != 0
     || this->m_pVertexOverride != nullptr) )
  {
    info.m_Type = this->m_Type;
    info.m_nFirstIndex = firstIndex;
    info.m_nIndexCount = numIndices;
    CMatCallQueue::QueueCall<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_DrawInfo_t const &,CMatQueuedMesh::MST_DrawInfo_t>(
      this: this->m_pCallQueue,
      pObject: this,
      pfnProxied: (unsigned int)CMatQueuedMesh::MST_Draw,
      arg1: &info);
  }
  else
  {
    this->MarkAsDrawn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041010
// Name: public: virtual void CMatQueuedMesh::DrawModulated(class Vector4D const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::DrawModulated(
        CMatQueuedMesh *this,
        const Vector4D *vecDiffuseModulation,
        int firstIndex,
        int numIndices)
{
  int m_nVerts; // esi
  MaterialPrimitiveType_t m_Type; // eax
  float w; // xmm0_4
  CMatQueuedMesh::MST_DrawModulatedInfo_t info; // [esp+4h] [ebp-2Ch] BYREF
  __int64 v8; // [esp+20h] [ebp-10h]
  __int64 v9; // [esp+28h] [ebp-8h]

  m_nVerts = this->m_nVerts;
  if ( (m_nVerts != 0 || this->m_pVertexOverride != nullptr
                      || this->m_nIndices != 0
                      || this->m_pIndexOverride != nullptr)
    && ((m_Type = this->m_Type) != MATERIAL_INSTANCED_QUADS && m_Type != MATERIAL_POINTS
     || m_nVerts != 0
     || this->m_pVertexOverride != nullptr) )
  {
    info.m_Type = this->m_Type;
    info.m_vecDiffuseModulation.x = vecDiffuseModulation->x;
    info.m_vecDiffuseModulation.y = vecDiffuseModulation->y;
    info.m_vecDiffuseModulation.z = vecDiffuseModulation->z;
    w = vecDiffuseModulation->w;
    v9 = 0;
    info.m_nFirstIndex = firstIndex;
    info.m_vecDiffuseModulation.w = w;
    info.m_nIndexCount = numIndices;
    v8 = (unsigned int)CMatQueuedMesh::MST_DrawModulated;
    CMatCallQueue::QueueCall<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_DrawModulatedInfo_t const &,CMatQueuedMesh::MST_DrawModulatedInfo_t>(
      this: this->m_pCallQueue,
      pObject: this,
      pfnProxied: (unsigned int)CMatQueuedMesh::MST_DrawModulated,
      arg1: &info);
  }
  else
  {
    this->MarkAsDrawn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100410D0
// Name: public: virtual void CMatQueuedMesh::ReconstructFromCachedPerFrameMeshData(class ICachedPerFrameMeshData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::ReconstructFromCachedPerFrameMeshData(
        CMatQueuedMesh *this,
        ICachedPerFrameMeshData *pData)
{
  const CMatQueuedMesh::MST_MeshInfo_t *v3; // edi

  this->m_pVertexData = (unsigned __int8 *)pData[9].__vftable;
  this->m_nVerts = (int)pData[10].__vftable;
  this->m_VertexFormat = *(_QWORD *)&pData[4].__vftable;
  this->m_pVertexOverride = (IMesh *)pData[7].__vftable;
  this->m_bExternalVB = BYTE1(pData[6].__vftable) & 1;
  this->m_pIndexData = (unsigned __int16 *)pData[12].__vftable;
  this->m_nIndices = (int)pData[13].__vftable;
  this->m_bExternalIB = (BYTE1(pData[6].__vftable) & 2) != 0;
  this->m_pIndexOverride = (IMesh *)pData[8].__vftable;
  this->m_Type = (MaterialPrimitiveType_t)pData[14].__vftable;
  if ( pData[7].__vftable != nullptr
    || pData[10].__vftable != nullptr
    || pData[8].__vftable != nullptr
    || pData[13].__vftable != nullptr )
  {
    v3 = (const CMatQueuedMesh::MST_MeshInfo_t *)&pData[2];
    if ( pData[2].__vftable != nullptr )
      v3->m_pMaterial->IncrementReferenceCount(this: v3->m_pMaterial);
    CMatCallQueue::QueueCall<CMatQueuedMesh *,CMatQueuedMesh,void,CMatQueuedMesh::MST_MeshInfo_t const &,CMatQueuedMesh::MST_MeshInfo_t>(
      this: this->m_pCallQueue,
      pObject: this,
      pfnProxied: (unsigned int)CMatQueuedMesh::MST_BuildDynamicBuffers,
      arg1: v3);
    this->m_bCanSetAuxMeshes = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100411A0
// Name: private: void CMatQueuedIndexBuffer::ReleaseBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedIndexBuffer::ReleaseBuffer(CMatQueuedIndexBuffer *this)
{
  void **p_m_pIndexData; // edi

  p_m_pIndexData = &this->m_pIndexData;
  if ( this->m_pIndexData != nullptr )
  {
    CMatCallQueue::QueueCall<CMatQueuedIndexBuffer *,CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void *,int,enum MaterialIndexFormat_t,void *>(
      this: this->m_pCallQueue,
      pObject: this,
      pfnProxied: (unsigned int)CMatQueuedIndexBuffer::RT_FreeIndexData,
      arg1: &this->m_nIndices,
      arg2: &this->m_nIndexFormat,
      arg3: p_m_pIndexData);
    *p_m_pIndexData = nullptr;
    this->m_nIndices = 0;
    this->m_bExternalIB = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041210
// Name: public: virtual bool CMatQueuedIndexBuffer::Lock(int,bool,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedIndexBuffer::Lock(
        CMatQueuedIndexBuffer *this,
        int nMaxIndexCount,
        bool bAppend,
        IndexDesc_t *desc)
{
  bool v6; // zf
  CMatQueuedRenderContext *m_pOwner; // esi
  int v8; // ebx
  int v9; // eax
  unsigned int m_alignment; // ecx
  int v11; // eax
  unsigned __int8 *m_pNextAlloc; // ecx
  unsigned __int8 *v13; // eax
  int nMaxIndexCounta; // [esp+Ch] [ebp+8h]
  unsigned __int8 *bAppenda; // [esp+10h] [ebp+Ch]

  CMatQueuedIndexBuffer::ReleaseBuffer(this);
  if ( bAppend )
    return false;
  v6 = this->m_nIndexFormat == MATERIAL_INDEX_FORMAT_16BIT;
  this->m_nIndices = nMaxIndexCount;
  m_pOwner = this->m_pOwner;
  v8 = 2 * !v6 + 2;
  v9 = nMaxIndexCount * v8;
  m_alignment = m_pOwner->m_Indices.m_alignment;
  if ( nMaxIndexCount * v8 <= m_alignment )
    v9 = m_pOwner->m_Indices.m_alignment;
  v11 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  m_pNextAlloc = m_pOwner->m_Indices.m_pNextAlloc;
  v13 = &m_pNextAlloc[v11];
  bAppenda = m_pNextAlloc;
  nMaxIndexCounta = (int)v13;
  if ( v13 <= m_pOwner->m_Indices.m_pCommitLimit )
    goto LABEL_9;
  if ( CMemoryStack::CommitTo(this: &m_pOwner->m_Indices, pNextAlloc: v13) )
  {
    m_pNextAlloc = bAppenda;
    v13 = (unsigned __int8 *)nMaxIndexCounta;
LABEL_9:
    m_pOwner->m_Indices.m_pNextAlloc = v13;
    goto LABEL_10;
  }
  m_pNextAlloc = nullptr;
LABEL_10:
  this->m_pIndexData = m_pNextAlloc;
  this->m_bExternalIB = false;
  desc->m_pIndices = (unsigned __int16 *)m_pNextAlloc;
  desc->m_nIndexSize = v8 >> 1;
  desc->m_nFirstIndex = 0;
  desc->m_nOffset = 0;
  return this->m_pIndexData != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100412C0
// Name: public: virtual void CMatQueuedIndexBuffer::Unlock(int,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedIndexBuffer::Unlock(CMatQueuedIndexBuffer *this, int nWrittenIndexCount, IndexDesc_t *desc)
{
  void *m_pIndexData; // ebx
  void **p_m_pIndexData; // edi
  int m_nIndices; // eax

  m_pIndexData = this->m_pIndexData;
  p_m_pIndexData = &this->m_pIndexData;
  if ( m_pIndexData != nullptr )
  {
    m_nIndices = this->m_nIndices;
    if ( nWrittenIndexCount < m_nIndices )
    {
      CMemoryStack::FreeToAllocPoint(
        this: &this->m_pOwner->m_Indices,
        mark: &this->m_pOwner->m_Indices.m_pNextAlloc[-2 * desc->m_nIndexSize * (m_nIndices - nWrittenIndexCount)]
      - this->m_pOwner->m_Indices.m_pBase,
        bDecommit: false);
      *p_m_pIndexData = m_pIndexData;
    }
  }
  this->m_nIndices = nWrittenIndexCount;
  if ( *p_m_pIndexData != nullptr )
    CMatCallQueue::QueueCall<CMatQueuedIndexBuffer *,CMatQueuedIndexBuffer,void,int,enum MaterialIndexFormat_t,void *,bool,int,enum MaterialIndexFormat_t,void *,bool>(
      this: this->m_pCallQueue,
      pObject: this,
      pfnProxied: (unsigned int)CMatQueuedIndexBuffer::RT_CopyIndexData,
      arg1: &this->m_nIndices,
      arg2: &this->m_nIndexFormat,
      arg3: p_m_pIndexData,
      arg4: &this->m_bExternalIB);
}

//------------------------------------------------------------------------------
// Address: 0x10041360
// Name: public: virtual void CMatQueuedRenderContext::Bind(class IMaterial __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Bind(
        CMatQueuedRenderContext *this,
        IMaterialInternal *iMaterial,
        void *proxyData)
{
  IMaterialInternal *v4; // eax
  void *v5; // ecx
  IMaterialInternal v6; // edx

  if ( iMaterial != nullptr )
  {
    v4 = iMaterial->GetRealTimeVersion(this: iMaterial);
  }
  else
  {
    v4 = g_pErrorMaterial;
    if ( g_pErrorMaterial == nullptr )
      return;
  }
  v5 = proxyData;
  this->m_pCurrentMaterial = v4;
  this->m_pCurrentProxyData = v5;
  v6.__vftable = v4->__vftable;
  iMaterial = v4;
  v6.CallBindProxy(this: v4, a2: v5, a3: &this->m_CallQueueExternal);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,void *,IMaterial *,void *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{36,{flat}},
    arg1: &iMaterial,
    arg2: &proxyData);
}

//------------------------------------------------------------------------------
// Address: 0x10041400
// Name: public: virtual void CMatQueuedRenderContext::BeginRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BeginRender(CMatQueuedRenderContext *this)
{
  if ( ++this->m_iRenderDepth == 1 )
    CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
      this: &this->m_queue,
      pObject: this->m_pHardwareContext,
      pfnProxied: (unsigned int) __thiscall CMatPaintmaps::`vcall'{8,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10041460
// Name: public: virtual void CMatQueuedRenderContext::EndRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EndRender(CMatQueuedRenderContext *this)
{
  if ( this->m_iRenderDepth-- == 1 )
    CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
      this: &this->m_queue,
      pObject: this->m_pHardwareContext,
      pfnProxied: (unsigned int) __thiscall CFunctor::operator(){12,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x100414B0
// Name: public: virtual void CMatQueuedRenderContext::SetRenderTargetEx(int,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetRenderTargetEx(
        CMatQueuedRenderContext *this,
        int nRenderTargetID,
        ITexture *pNewTarget)
{
  CMatRenderContextBase::SetRenderTargetEx(this, nRenderTargetID, pNewTarget);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,ITexture *,int,ITexture *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{480,{flat}},
    arg1: &nRenderTargetID,
    arg2: &pNewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x10041520
// Name: public: virtual void CMatQueuedRenderContext::Viewport(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Viewport(CMatQueuedRenderContext *this, int x, int y, int width, int height)
{
  CMatRenderContextBase::Viewport(this, x, y, width, height);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{152,{flat}},
    arg1: &x,
    arg2: &y,
    arg3: &width,
    arg4: &height);
}

//------------------------------------------------------------------------------
// Address: 0x100415A0
// Name: public: virtual void CMatQueuedRenderContext::SetLights(int,struct LightDesc_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetLights(
        CMatQueuedRenderContext *this,
        int nCount,
        const LightDesc_t *pLights)
{
  unsigned int v3; // edx
  unsigned __int8 *m_pNextAlloc; // ebx
  CMemoryStack *p_m_Allocator; // esi
  unsigned int m_alignment; // ecx
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  bool v10; // al
  CMatRenderContextBase *m_pHardwareContext; // [esp-20h] [ebp-40h]
  unsigned int count; // [esp+1Ch] [ebp-4h]

  v3 = 88 * nCount;
  m_pNextAlloc = this->m_queue.m_Allocator.m_pNextAlloc;
  p_m_Allocator = &this->m_queue.m_Allocator;
  m_alignment = this->m_queue.m_Allocator.m_alignment;
  v7 = 88 * nCount;
  if ( 88 * nCount <= m_alignment )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &m_pNextAlloc[v8];
  count = 88 * nCount;
  if ( &m_pNextAlloc[v8] <= p_m_Allocator->m_pCommitLimit
    || (v10 = CMemoryStack::CommitTo(this: p_m_Allocator, pNextAlloc: &m_pNextAlloc[v8]), v3 = count, v10) )
  {
    p_m_Allocator->m_pNextAlloc = v9;
  }
  else
  {
    m_pNextAlloc = nullptr;
  }
  memcpy(dst: m_pNextAlloc, src: (unsigned __int8 *)pLights, count: v3);
  m_pHardwareContext = this->m_pHardwareContext;
  pLights = (const LightDesc_t *)m_pNextAlloc;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,LightDesc_t const *,int,LightDesc_t const *>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall CMaterialVar::`vcall'{60,{flat}},
    arg1: &nCount,
    arg2: &pLights);
}

//------------------------------------------------------------------------------
// Address: 0x10041660
// Name: public: virtual void CMatQueuedRenderContext::SetLightingState(struct MaterialLightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetLightingState(
        CMatQueuedRenderContext *this,
        const MaterialLightingState_t *state)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  MaterialLightingState_t arg1; // [esp+8h] [ebp-1C8h] BYREF
  __int64 v4; // [esp+1C0h] [ebp-10h]
  __int64 v5; // [esp+1C8h] [ebp-8h]

  m_pHardwareContext = this->m_pHardwareContext;
  v5 = 0;
  arg1 = *state;
  v4 = (unsigned int) __thiscall IMatRenderContext::`vcall'{56,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,MaterialLightingState_t const &,MaterialLightingState_t>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{56,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100416D0
// Name: public: virtual void CMatQueuedRenderContext::SetLightingOrigin(class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetLightingOrigin(CMatQueuedRenderContext *this, Vector vLightingOrigin)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,Vector,Vector>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{592,{flat}},
    arg1: &vLightingOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x10041720
// Name: public: virtual void CMatQueuedRenderContext::SetAmbientLightCube(class Vector4D __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetAmbientLightCube(CMatQueuedRenderContext *this, Vector4D *cube)
{
  unsigned __int8 *m_pNextAlloc; // ebx
  CMemoryStack *p_m_Allocator; // esi
  unsigned int m_alignment; // ecx
  int v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // edi
  CMatRenderContextBase *m_pHardwareContext; // [esp-1Ch] [ebp-38h]

  m_pNextAlloc = this->m_queue.m_Allocator.m_pNextAlloc;
  p_m_Allocator = &this->m_queue.m_Allocator;
  m_alignment = this->m_queue.m_Allocator.m_alignment;
  v5 = 96;
  if ( m_alignment >= 0x60 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &m_pNextAlloc[v6];
  if ( &m_pNextAlloc[v6] <= p_m_Allocator->m_pCommitLimit
    || CMemoryStack::CommitTo(this: p_m_Allocator, pNextAlloc: &m_pNextAlloc[v6]) )
  {
    p_m_Allocator->m_pNextAlloc = v7;
  }
  else
  {
    m_pNextAlloc = nullptr;
  }
  memcpy(dst: m_pNextAlloc, src: (unsigned __int8 *)cube, count: 0x60u);
  m_pHardwareContext = this->m_pHardwareContext;
  cube = (Vector4D *)m_pNextAlloc;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,Vector4D * const,Vector4D *>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMaterial::`vcall'{64,{flat}},
    arg1: &cube);
}

//------------------------------------------------------------------------------
// Address: 0x100417D0
// Name: public: virtual void CMatQueuedRenderContext::SetNumBoneWeights(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetNumBoneWeights(CMatQueuedRenderContext *this, int nBoneCount)
{
  this->m_nBoneCount = nBoneCount;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{216,{flat}},
    arg1: &nBoneCount);
}

//------------------------------------------------------------------------------
// Address: 0x10041830
// Name: public: virtual void CMatQueuedRenderContext::FogMode(enum MaterialFogMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FogMode(CMatQueuedRenderContext *this, MaterialFogMode_t fogMode)
{
  this->m_FogMode = fogMode;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialFogMode_t,enum MaterialFogMode_t>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{176,{flat}},
    arg1: &fogMode);
}

//------------------------------------------------------------------------------
// Address: 0x10041890
// Name: public: virtual void CMatQueuedRenderContext::FogStart(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FogStart(CMatQueuedRenderContext *this, float fStart)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  __int128 v3; // [esp-14h] [ebp-24h]
  __int64 v4; // [esp+8h] [ebp-8h]

  m_pHardwareContext = this->m_pHardwareContext;
  v4 = 0;
  this->m_flFogStart = fStart;
  *(_QWORD *)&v3 = (unsigned int) __thiscall IMatRenderContext::`vcall'{180,{flat}};
  *((_QWORD *)&v3 + 1) = v4;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: v3,
    arg1: &fStart);
}

//------------------------------------------------------------------------------
// Address: 0x100418F0
// Name: public: virtual void CMatQueuedRenderContext::FogEnd(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FogEnd(CMatQueuedRenderContext *this, float fEnd)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  __int128 v3; // [esp-14h] [ebp-24h]
  __int64 v4; // [esp+8h] [ebp-8h]

  m_pHardwareContext = this->m_pHardwareContext;
  v4 = 0;
  this->m_flFogEnd = fEnd;
  *(_QWORD *)&v3 = (unsigned int) __thiscall IMatRenderContext::`vcall'{184,{flat}};
  *((_QWORD *)&v3 + 1) = v4;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: v3,
    arg1: &fEnd);
}

//------------------------------------------------------------------------------
// Address: 0x10041950
// Name: public: virtual void CMatQueuedRenderContext::FogMaxDensity(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FogMaxDensity(CMatQueuedRenderContext *this, float flMaxDensity)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  __int128 v3; // [esp-14h] [ebp-24h]
  __int64 v4; // [esp+8h] [ebp-8h]

  m_pHardwareContext = this->m_pHardwareContext;
  v4 = 0;
  this->m_flFogMaxDensity = flMaxDensity;
  *(_QWORD *)&v3 = (unsigned int) __thiscall IMatRenderContext::`vcall'{636,{flat}};
  *((_QWORD *)&v3 + 1) = v4;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: v3,
    arg1: &flMaxDensity);
}

//------------------------------------------------------------------------------
// Address: 0x100419B0
// Name: public: virtual void CMatQueuedRenderContext::SetFogZ(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetFogZ(CMatQueuedRenderContext *this, float fogZ)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  __int128 v3; // [esp-14h] [ebp-24h]
  __int64 v4; // [esp+8h] [ebp-8h]

  m_pHardwareContext = this->m_pHardwareContext;
  v4 = 0;
  this->m_flFogZ = fogZ;
  *(_QWORD *)&v3 = (unsigned int) __thiscall IMatRenderContext::`vcall'{188,{flat}};
  *((_QWORD *)&v3 + 1) = v4;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: v3,
    arg1: &fogZ);
}

//------------------------------------------------------------------------------
// Address: 0x10041A10
// Name: public: virtual void CMatQueuedRenderContext::FogColor3ub(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FogColor3ub(
        CMatQueuedRenderContext *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  unsigned __int8 v4; // dl

  v4 = g;
  this->m_FogColor.r = r;
  this->m_FogColor.b = b;
  this->m_FogColor.g = v4;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{204,{flat}},
    arg1: &r,
    arg2: &g,
    arg3: &b);
}

//------------------------------------------------------------------------------
// Address: 0x10041A80
// Name: public: virtual void CMatQueuedRenderContext::SyncToken(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SyncToken(CMatQueuedRenderContext *this, const char *p)
{
  CMatQueuedRenderContext *v2; // edx
  const char **m_pNextAlloc; // ebx
  CMemoryStack *p_m_Allocator; // esi
  unsigned int m_alignment; // eax
  int v6; // ecx
  int v7; // ecx
  unsigned __int8 *v8; // edi
  bool v9; // al
  __int128 v10; // [esp+8h] [ebp-14h]
  CMatQueuedRenderContext *v11; // [esp+18h] [ebp-4h]

  v2 = this;
  m_pNextAlloc = (const char **)this->m_queue.m_Allocator.m_pNextAlloc;
  p_m_Allocator = &this->m_queue.m_Allocator;
  DWORD1(v10) = 0;
  *((_QWORD *)&v10 + 1) = 0;
  m_alignment = this->m_queue.m_Allocator.m_alignment;
  v6 = 4;
  if ( m_alignment >= 4 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = (unsigned __int8 *)m_pNextAlloc + v7;
  v11 = v2;
  LODWORD(v10) =  __thiscall IMatRenderContext::`vcall'{308,{flat}};
  if ( (unsigned __int8 *)((unsigned int)m_pNextAlloc + v7) <= p_m_Allocator->m_pCommitLimit
    || (v9 = CMemoryStack::CommitTo(this: p_m_Allocator, pNextAlloc: (unsigned __int8 *)m_pNextAlloc + v7), v2 = v11, v9) )
  {
    p_m_Allocator->m_pNextAlloc = v8;
  }
  else
  {
    m_pNextAlloc = nullptr;
  }
  *m_pNextAlloc = p;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,char const *,char const *>(
    this: &v2->m_queue,
    pObject: v2->m_pHardwareContext,
    pfnProxied: v10,
    arg1: m_pNextAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10041B20
// Name: public: virtual struct OcclusionQueryObjectHandle_t__ __near * CMatQueuedRenderContext::CreateOcclusionQueryObject(void)
// Source: json
//------------------------------------------------------------------------------
OcclusionQueryObjectHandle_t__ *__thiscall CMatQueuedRenderContext::CreateOcclusionQueryObject(
        CMatQueuedRenderContext *this)
{
  OcclusionQueryObjectHandle_t__ *OcclusionQueryObject; // edi
  __int128 v4; // [esp-14h] [ebp-30h]
  __int64 v5; // [esp+10h] [ebp-Ch]
  OcclusionQueryObjectHandle_t__ *h; // [esp+18h] [ebp-4h] BYREF

  OcclusionQueryObject = COcclusionQueryMgr::CreateOcclusionQueryObject(this: g_pOcclusionQueryMgr);
  v5 = 0;
  *(_QWORD *)&v4 = (unsigned int)COcclusionQueryMgr::OnCreateOcclusionQueryObject;
  h = OcclusionQueryObject;
  *((_QWORD *)&v4 + 1) = 0;
  CMatCallQueue::QueueCall<COcclusionQueryMgr *,COcclusionQueryMgr,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
    this: &this->m_queue,
    pObject: g_pOcclusionQueryMgr,
    pfnProxied: v4,
    arg1: &h);
  return OcclusionQueryObject;
}

//------------------------------------------------------------------------------
// Address: 0x10041B90
// Name: public: virtual int CMatQueuedRenderContext::OcclusionQuery_GetNumPixelsRendered(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedRenderContext::OcclusionQuery_GetNumPixelsRendered(
        CMatQueuedRenderContext *this,
        OcclusionQueryObjectHandle_t__ *h)
{
  CMatCallQueue::QueueCall<COcclusionQueryMgr *,COcclusionQueryMgr,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
    this: &this->m_queue,
    pObject: g_pOcclusionQueryMgr,
    pfnProxied: (unsigned int)COcclusionQueryMgr::OcclusionQuery_IssueNumPixelsRenderedQuery,
    arg1: &h);
  return COcclusionQueryMgr::OcclusionQuery_GetNumPixelsRendered(this: g_pOcclusionQueryMgr, h, bDoQuery: false);
}

//------------------------------------------------------------------------------
// Address: 0x10041C00
// Name: public: virtual void CMatQueuedRenderContext::SetFlashlightState(struct FlashlightState_t const __near &,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetFlashlightState(
        CMatQueuedRenderContext *this,
        const FlashlightState_t *s,
        const VMatrix *m)
{
  FlashlightState_t arg1; // [esp+8h] [ebp-14Ch] BYREF
  VMatrix arg2; // [esp+104h] [ebp-50h] BYREF
  __int64 v5; // [esp+144h] [ebp-10h]
  __int64 v6; // [esp+14Ch] [ebp-8h]

  v6 = 0;
  arg2 = *m;
  arg1 = *s;
  v5 = (unsigned int) __thiscall IMatRenderContext::`vcall'{340,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,FlashlightState_t const &,VMatrix const &,FlashlightState_t,VMatrix>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{340,{flat}},
    &arg1,
    &arg2);
}

//------------------------------------------------------------------------------
// Address: 0x10041C80
// Name: public: virtual bool CMatQueuedRenderContext::EnableClipping(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::EnableClipping(CMatQueuedRenderContext *this, bool bEnable)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,bool,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{528,{flat}},
    arg1: &bEnable);
  return CMatRenderContextBase::EnableClipping(this, bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x10041CE0
// Name: public: virtual void CMatQueuedRenderContext::UserClipTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::UserClipTransform(CMatQueuedRenderContext *this, const VMatrix *m)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  VMatrix arg1; // [esp+8h] [ebp-50h] BYREF
  __int64 v4; // [esp+48h] [ebp-10h]
  __int64 v5; // [esp+50h] [ebp-8h]

  m_pHardwareContext = this->m_pHardwareContext;
  v5 = 0;
  arg1 = *m;
  v4 = (unsigned int) __thiscall IMatRenderContext::`vcall'{356,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{356,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10041D40
// Name: public: virtual void CMatQueuedRenderContext::DrawScreenSpaceRectangle(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DrawScreenSpaceRectangle(
        CMatQueuedRenderContext *this,
        IMaterial *pMaterial,
        int destx,
        int desty,
        int width,
        int height,
        float src_texture_x0,
        float src_texture_y0,
        float src_texture_x1,
        float src_texture_y1,
        int src_texture_width,
        int src_texture_height,
        void *pClientRenderable,
        int nXDice,
        int nYDice)
{
  int v16; // eax

  v16 = ((int (__thiscall *)(IMaterial *))pMaterial->__vftable[1].Refresh)(a1: pMaterial);
  (*(void (__thiscall **)(int, void *, CMatQueuedRenderContext::CCallQueueExternal *))(*(_DWORD *)v16 + 208))(
    a1: v16,
    a2: pClientRenderable,
    a3: &this->m_CallQueueExternal);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int,IMaterial *,int,int,int,int,float,float,float,float,int,int,void *,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{420,{flat}},
    arg1: &pMaterial,
    arg2: &destx,
    arg3: &desty,
    arg4: &width,
    arg5: &height,
    arg6: &src_texture_x0,
    arg7: &src_texture_y0,
    arg8: &src_texture_x1,
    arg9: &src_texture_y1,
    arg10: &src_texture_width,
    arg11: &src_texture_height,
    arg12: &pClientRenderable,
    arg13: &nXDice,
    arg14: &nYDice);
}

//------------------------------------------------------------------------------
// Address: 0x10041DF0
// Name: public: virtual void CMatQueuedRenderContext::LoadBoneMatrix(int,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::LoadBoneMatrix(CMatQueuedRenderContext *this, int i, const matrix3x4_t *m)
{
  matrix3x4_t arg2; // [esp+0h] [ebp-40h] BYREF
  __int64 v4; // [esp+30h] [ebp-10h]
  __int64 v5; // [esp+38h] [ebp-8h]

  HIDWORD(v4) = 0;
  v5 = 0;
  arg2 = *m;
  v4 = (unsigned int) __thiscall IMatRenderContext::`vcall'{424,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,matrix3x4_t const &,int,matrix3x4_t>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{424,{flat}},
    arg1: &i,
    &arg2);
}

//------------------------------------------------------------------------------
// Address: 0x10041E80
// Name: public: virtual void CMatQueuedRenderContext::CopyRenderTargetToTextureEx(class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::CopyRenderTargetToTextureEx(
        CMatQueuedRenderContext *this,
        ITexture *pTexture,
        int i,
        Rect_t *pSrc,
        Rect_t *pDst)
{
  CMatQueuedRenderContext *v5; // edx
  unsigned int m_alignment; // ecx
  Rect_t *m_pNextAlloc; // ebx
  CMemoryStack *p_m_Allocator; // esi
  int v9; // eax
  int v10; // eax
  unsigned __int8 *v11; // edi
  bool v12; // al
  unsigned int v13; // ecx
  Rect_t *v14; // ebx
  CMemoryStack *v15; // esi
  int v16; // eax
  int v17; // eax
  unsigned __int8 *v18; // edi

  v5 = this;
  if ( pDst != nullptr )
  {
    m_alignment = this->m_queue.m_Allocator.m_alignment;
    m_pNextAlloc = (Rect_t *)v5->m_queue.m_Allocator.m_pNextAlloc;
    p_m_Allocator = &v5->m_queue.m_Allocator;
    v9 = 16;
    if ( m_alignment >= 0x10 )
      v9 = v5->m_queue.m_Allocator.m_alignment;
    v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
    v11 = (unsigned __int8 *)m_pNextAlloc + v10;
    if ( (unsigned __int8 *)((unsigned int)m_pNextAlloc + v10) <= v5->m_queue.m_Allocator.m_pCommitLimit
      || (v12 = CMemoryStack::CommitTo(
                  this: &v5->m_queue.m_Allocator,
                  pNextAlloc: (unsigned __int8 *)m_pNextAlloc + v10),
          v5 = this,
          v12) )
    {
      p_m_Allocator->m_pNextAlloc = v11;
    }
    else
    {
      m_pNextAlloc = nullptr;
    }
    *m_pNextAlloc = *pDst;
    pDst = m_pNextAlloc;
  }
  else
  {
    pDst = nullptr;
  }
  if ( pSrc != nullptr )
  {
    v13 = v5->m_queue.m_Allocator.m_alignment;
    v14 = (Rect_t *)v5->m_queue.m_Allocator.m_pNextAlloc;
    v15 = &v5->m_queue.m_Allocator;
    v16 = 16;
    if ( v13 >= 0x10 )
      v16 = v5->m_queue.m_Allocator.m_alignment;
    v17 = ~(v13 - 1) & (v13 + v16 - 1);
    v18 = (unsigned __int8 *)v14 + v17;
    if ( (unsigned __int8 *)((unsigned int)v14 + v17) <= v5->m_queue.m_Allocator.m_pCommitLimit
      || CMemoryStack::CommitTo(this: &v5->m_queue.m_Allocator, pNextAlloc: (unsigned __int8 *)v14 + v17) )
    {
      v15->m_pNextAlloc = v18;
    }
    else
    {
      v14 = nullptr;
    }
    v5 = this;
    *v14 = *pSrc;
    pSrc = v14;
  }
  else
  {
    pSrc = nullptr;
  }
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,Rect_t *,Rect_t *,ITexture *,int,Rect_t *,Rect_t *>(
    this: &v5->m_queue,
    pObject: v5->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{452,{flat}},
    arg1: &pTexture,
    arg2: &i,
    arg3: &pSrc,
    arg4: &pDst);
}

//------------------------------------------------------------------------------
// Address: 0x10041FB0
// Name: public: virtual bool CMatQueuedRenderContext::OnDrawMesh(class IMesh __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::OnDrawMesh(
        CMatQueuedRenderContext *this,
        IMesh *pMesh,
        int firstIndex,
        int numIndices)
{
  CMatCallQueue::QueueCall<IMesh *,IMesh,void,int,int,int,int>(
    this: &this->m_queue,
    pObject: pMesh,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{48,{flat}},
    arg1: &firstIndex,
    arg2: &numIndices);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10042000
// Name: public: virtual bool CMatQueuedRenderContext::OnDrawMesh(class IMesh __near *,class CPrimList __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::OnDrawMesh(
        CMatQueuedRenderContext *this,
        IMesh *pMesh,
        CPrimList *pLists,
        int nLists)
{
  CPrimList *m_pRenderData; // edi
  IMatRenderContext_vtbl *v6; // edx
  __int128 v8; // [esp-1Ch] [ebp-54h]
  __int64 v9; // [esp+14h] [ebp-24h]
  CMatRenderData<CPrimList> rdPrimList; // [esp+1Ch] [ebp-1Ch] BYREF
  int v11; // [esp+34h] [ebp-4h]

  rdPrimList.m_pRenderContext = this;
  memset(&rdPrimList.m_pRenderData, 0, 9);
  CMatRenderData<CPrimList>::Lock(this: &rdPrimList, nCount: nLists, pSrcData: pLists);
  m_pRenderData = rdPrimList.m_pRenderData;
  *(_QWORD *)&v8 = (unsigned int)CMatQueuedRenderContext::DeferredDrawPrimList;
  v9 = 0;
  v11 = 0;
  pLists = rdPrimList.m_pRenderData;
  *((_QWORD *)&v8 + 1) = 0;
  CMatCallQueue::QueueCall<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,IMesh *,CPrimList *,int,IMesh *,CPrimList *,int>(
    this: &this->m_queue,
    pObject: this,
    pfnProxied: v8,
    arg1: &pMesh,
    arg2: &pLists,
    arg3: &nLists);
  v11 = -1;
  if ( rdPrimList.m_pRenderContext != nullptr && m_pRenderData != nullptr )
  {
    v6 = rdPrimList.m_pRenderContext->__vftable;
    if ( rdPrimList.m_bNeedsUnlock )
      ((void (__stdcall *)(CPrimList *))v6->UnlockRenderData)(a1: m_pRenderData);
    else
      ((void (*)(void))v6->ReleaseRenderData)();
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100420D0
// Name: public: virtual bool CMatQueuedRenderContext::OnDrawMeshModulated(class IMesh __near *,class Vector4D const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::OnDrawMeshModulated(
        CMatQueuedRenderContext *this,
        IMesh *pMesh,
        const Vector4D *vecDiffuseModulation,
        int firstIndex,
        int numIndices)
{
  CMatCallQueue::QueueCall<IMesh *,IMesh,void,Vector4D const &,int,int,Vector4D,int,int>(
    this: &this->m_queue,
    pObject: pMesh,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{100,{flat}},
    arg1: vecDiffuseModulation,
    arg2: &firstIndex,
    arg3: &numIndices);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10042130
// Name: public: virtual bool CMatQueuedRenderContext::OnSetFlexMesh(class IMesh __near *,class IMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::OnSetFlexMesh(
        CMatQueuedRenderContext *this,
        IMesh *pStaticMesh,
        IMesh *pMesh,
        int nVertexOffsetInBytes)
{
  __int128 v5; // [esp-18h] [ebp-28h]
  __int128 v6; // [esp-18h] [ebp-28h]

  if ( pMesh != nullptr )
  {
    *(_QWORD *)&v5 = (unsigned int)CMatQueuedRenderContext::DeferredSetFlexMesh;
    *((_QWORD *)&v5 + 1) = 0;
    CMatCallQueue::QueueCall<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,IMesh *,int,IMesh *,int>(
      this: &this->m_queue,
      pObject: this,
      pfnProxied: v5,
      arg1: &pStaticMesh,
      arg2: &nVertexOffsetInBytes);
  }
  else
  {
    pMesh = nullptr;
    nVertexOffsetInBytes = 0;
    *(_QWORD *)&v6 = (unsigned int) __thiscall IMesh::`vcall'{88,{flat}};
    *((_QWORD *)&v6 + 1) = 0;
    CMatCallQueue::QueueCall<IMesh *,IMesh,void,IMesh *,int,IMesh *,int>(
      this: &this->m_queue,
      pObject: pStaticMesh,
      pfnProxied: v6,
      arg1: (IMesh *const *)&nVertexOffsetInBytes,
      arg2: (const int *)&pMesh);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100421D0
// Name: public: virtual bool CMatQueuedRenderContext::OnSetColorMesh(class IMesh __near *,class IMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::OnSetColorMesh(
        CMatQueuedRenderContext *this,
        IMesh *pStaticMesh,
        IMesh *pMesh,
        int nVertexOffsetInBytes)
{
  CMatCallQueue::QueueCall<IMesh *,IMesh,void,IMesh *,int,IMesh *,int>(
    this: &this->m_queue,
    pObject: pStaticMesh,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{52,{flat}},
    arg1: &pMesh,
    arg2: &nVertexOffsetInBytes);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10042220
// Name: public: virtual bool CMatQueuedRenderContext::OnSetPrimitiveType(class IMesh __near *,enum MaterialPrimitiveType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::OnSetPrimitiveType(
        CMatQueuedRenderContext *this,
        IMesh *pMesh,
        MaterialPrimitiveType_t type)
{
  CMatCallQueue::QueueCall<IMesh *,IMesh,void,enum MaterialPrimitiveType_t,enum MaterialPrimitiveType_t>(
    this: &this->m_queue,
    pObject: pMesh,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{40,{flat}},
    arg1: &type);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10042270
// Name: public: virtual void CMatQueuedRenderContext::MatrixMode(enum MaterialMatrixMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::MatrixMode(CMatQueuedRenderContext *this, MaterialMatrixMode_t mode)
{
  CMatRenderContextBase::MatrixMode(this, mode);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialMatrixMode_t,enum MaterialMatrixMode_t>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{80,{flat}},
    arg1: &mode);
}

//------------------------------------------------------------------------------
// Address: 0x100422D0
// Name: public: virtual void CMatQueuedRenderContext::PushMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushMatrix(CMatQueuedRenderContext *this)
{
  CMatRenderContextBase::PushMatrix(this);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{84,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10042320
// Name: public: virtual void CMatQueuedRenderContext::PopMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PopMatrix(CMatQueuedRenderContext *this)
{
  CMatRenderContextBase::PopMatrix(this);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{88,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10042370
// Name: public: virtual void CMatQueuedRenderContext::LoadMatrix(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::LoadMatrix(CMatQueuedRenderContext *this, const VMatrix *matrix)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  VMatrix arg1; // [esp+Ch] [ebp-50h] BYREF
  __int64 v5; // [esp+4Ch] [ebp-10h]
  __int64 v6; // [esp+54h] [ebp-8h]

  CMatRenderContextBase::LoadMatrix(this, matrix);
  m_pHardwareContext = this->m_pHardwareContext;
  arg1 = this->m_pCurMatrixItem->matrix;
  v6 = 0;
  v5 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100423E0
// Name: public: virtual void CMatQueuedRenderContext::LoadMatrix(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::LoadMatrix(CMatQueuedRenderContext *this, const matrix3x4_t *matrix)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  VMatrix arg1; // [esp+Ch] [ebp-50h] BYREF
  __int64 v5; // [esp+4Ch] [ebp-10h]
  __int64 v6; // [esp+54h] [ebp-8h]

  CMatRenderContextBase::LoadMatrix(this, matrix);
  m_pHardwareContext = this->m_pHardwareContext;
  arg1 = this->m_pCurMatrixItem->matrix;
  v6 = 0;
  v5 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10042450
// Name: public: virtual void CMatQueuedRenderContext::MultMatrix(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::MultMatrix(CMatQueuedRenderContext *this, const VMatrix *matrix)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  VMatrix arg1; // [esp+Ch] [ebp-50h] BYREF
  __int64 v5; // [esp+4Ch] [ebp-10h]
  __int64 v6; // [esp+54h] [ebp-8h]

  CMatRenderContextBase::MultMatrix(this, matrix);
  m_pHardwareContext = this->m_pHardwareContext;
  arg1 = this->m_pCurMatrixItem->matrix;
  v6 = 0;
  v5 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100424C0
// Name: public: virtual void CMatQueuedRenderContext::MultMatrix(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::MultMatrix(CMatQueuedRenderContext *this, const matrix3x4_t *matrix)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  VMatrix arg1; // [esp+0h] [ebp-50h] BYREF
  __int64 v5; // [esp+40h] [ebp-10h]
  __int64 v6; // [esp+48h] [ebp-8h]

  *(matrix3x4_t *)&arg1.m[0][0] = *matrix;
  *(_QWORD *)&arg1.m[3][0] = 0;
  *(_QWORD *)&arg1.m[3][2] = 0x3F80000000000000LL;
  CMatRenderContextBase::MultMatrix(this, matrix: &arg1);
  m_pHardwareContext = this->m_pHardwareContext;
  arg1 = this->m_pCurMatrixItem->matrix;
  v6 = 0;
  v5 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10042590
// Name: public: virtual void CMatQueuedRenderContext::MultMatrixLocal(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::MultMatrixLocal(CMatQueuedRenderContext *this, const VMatrix *matrix)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  VMatrix arg1; // [esp+Ch] [ebp-50h] BYREF
  __int64 v5; // [esp+4Ch] [ebp-10h]
  __int64 v6; // [esp+54h] [ebp-8h]

  CMatRenderContextBase::MultMatrixLocal(this, matrix);
  m_pHardwareContext = this->m_pHardwareContext;
  arg1 = this->m_pCurMatrixItem->matrix;
  v6 = 0;
  v5 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10042600
// Name: public: virtual void CMatQueuedRenderContext::MultMatrixLocal(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::MultMatrixLocal(CMatQueuedRenderContext *this, const matrix3x4_t *matrix)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  VMatrix arg1; // [esp+0h] [ebp-50h] BYREF
  __int64 v5; // [esp+40h] [ebp-10h]
  __int64 v6; // [esp+48h] [ebp-8h]

  *(matrix3x4_t *)&arg1.m[0][0] = *matrix;
  *(_QWORD *)&arg1.m[3][0] = 0;
  *(_QWORD *)&arg1.m[3][2] = 0x3F80000000000000LL;
  CMatRenderContextBase::MultMatrixLocal(this, matrix: &arg1);
  m_pHardwareContext = this->m_pHardwareContext;
  arg1 = this->m_pCurMatrixItem->matrix;
  v6 = 0;
  v5 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100426D0
// Name: public: virtual void CMatQueuedRenderContext::LoadIdentity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::LoadIdentity(CMatQueuedRenderContext *this)
{
  CMatRenderContextBase::LoadIdentity(this);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall CTexture_MultipleRenderTarget::`vcall'{124,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10042720
// Name: public: virtual void CMatQueuedRenderContext::Ortho(double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Ortho(
        CMatQueuedRenderContext *this,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // esi
  CMatRenderContextBase *m_pHardwareContext; // ecx
  VMatrix arg1; // [esp+3Ch] [ebp-50h] BYREF
  __int64 v11; // [esp+7Ch] [ebp-10h]
  __int64 v12; // [esp+84h] [ebp-8h]

  CMatRenderContextBase::Ortho(this, left, top, right, bottom, zNear, zFar);
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  HIDWORD(v11) = 0;
  v12 = 0;
  arg1 = m_pCurMatrixItem->matrix;
  m_pHardwareContext = this->m_pHardwareContext;
  v11 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100427D0
// Name: public: virtual void CMatQueuedRenderContext::PerspectiveX(double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PerspectiveX(
        CMatQueuedRenderContext *this,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // esi
  CMatRenderContextBase *m_pHardwareContext; // ecx
  VMatrix arg1; // [esp+2Ch] [ebp-50h] BYREF
  __int64 v9; // [esp+6Ch] [ebp-10h]
  __int64 v10; // [esp+74h] [ebp-8h]

  CMatRenderContextBase::PerspectiveX(this, flFovX, flAspect, flZNear, flZFar);
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  HIDWORD(v9) = 0;
  v10 = 0;
  arg1 = m_pCurMatrixItem->matrix;
  m_pHardwareContext = this->m_pHardwareContext;
  v9 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10042870
// Name: public: virtual void CMatQueuedRenderContext::PerspectiveOffCenterX(double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PerspectiveOffCenterX(
        CMatQueuedRenderContext *this,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // esi
  CMatRenderContextBase *m_pHardwareContext; // ecx
  VMatrix arg1; // [esp+4Ch] [ebp-50h] BYREF
  __int64 v13; // [esp+8Ch] [ebp-10h]
  __int64 v14; // [esp+94h] [ebp-8h]

  CMatRenderContextBase::PerspectiveOffCenterX(this, flFovX, flAspect, flZNear, flZFar, bottom, top, left, right);
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  HIDWORD(v13) = 0;
  v14 = 0;
  arg1 = m_pCurMatrixItem->matrix;
  m_pHardwareContext = this->m_pHardwareContext;
  v13 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10042930
// Name: public: virtual void CMatQueuedRenderContext::PickMatrix(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PickMatrix(
        CMatQueuedRenderContext *this,
        int x,
        int y,
        int nWidth,
        int nHeight)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  VMatrix arg1; // [esp+Ch] [ebp-50h] BYREF
  __int64 v8; // [esp+4Ch] [ebp-10h]
  __int64 v9; // [esp+54h] [ebp-8h]

  CMatRenderContextBase::PickMatrix(this, x, y, nWidth, nHeight);
  m_pHardwareContext = this->m_pHardwareContext;
  arg1 = this->m_pCurMatrixItem->matrix;
  v9 = 0;
  v8 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100429B0
// Name: public: virtual void CMatQueuedRenderContext::Rotate(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Rotate(
        CMatQueuedRenderContext *this,
        float flAngle,
        float x,
        float y,
        float z)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // esi
  CMatRenderContextBase *m_pHardwareContext; // ecx
  VMatrix arg1; // [esp+1Ch] [ebp-50h] BYREF
  __int64 v9; // [esp+5Ch] [ebp-10h]
  __int64 v10; // [esp+64h] [ebp-8h]

  CMatRenderContextBase::Rotate(this, flAngle, x, y, z);
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  HIDWORD(v9) = 0;
  v10 = 0;
  arg1 = m_pCurMatrixItem->matrix;
  m_pHardwareContext = this->m_pHardwareContext;
  v9 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10042A50
// Name: public: virtual void CMatQueuedRenderContext::Translate(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Translate(CMatQueuedRenderContext *this, float x, float y, float z)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // esi
  CMatRenderContextBase *m_pHardwareContext; // ecx
  VMatrix arg1; // [esp+18h] [ebp-50h] BYREF
  __int64 v8; // [esp+58h] [ebp-10h]
  __int64 v9; // [esp+60h] [ebp-8h]

  CMatRenderContextBase::Translate(this, x, y, z);
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  HIDWORD(v8) = 0;
  v9 = 0;
  arg1 = m_pCurMatrixItem->matrix;
  m_pHardwareContext = this->m_pHardwareContext;
  v8 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10042AE0
// Name: public: virtual void CMatQueuedRenderContext::Scale(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Scale(CMatQueuedRenderContext *this, float x, float y, float z)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // esi
  CMatRenderContextBase *m_pHardwareContext; // ecx
  VMatrix arg1; // [esp+18h] [ebp-50h] BYREF
  __int64 v8; // [esp+58h] [ebp-10h]
  __int64 v9; // [esp+60h] [ebp-8h]

  CMatRenderContextBase::Scale(this, x, y, z);
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  HIDWORD(v8) = 0;
  v9 = 0;
  arg1 = m_pCurMatrixItem->matrix;
  m_pHardwareContext = this->m_pHardwareContext;
  v8 = (unsigned int) __thiscall IMesh::`vcall'{96,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,VMatrix const &,VMatrix>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10042B70
// Name: public: virtual void CMatQueuedRenderContext::BeginBatch(class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BeginBatch(CMatQueuedRenderContext *this, IMesh *pIndices)
{
  CMatQueuedMesh *m_pQueuedMesh; // edx
  __int128 v3; // [esp-10h] [ebp-20h]
  __int64 v4; // [esp+8h] [ebp-8h]

  m_pQueuedMesh = this->m_pQueuedMesh;
  v4 = 0;
  m_pQueuedMesh->m_bCanSetAuxMeshes = false;
  *(_QWORD *)&v3 = (unsigned int)CMatQueuedRenderContext::DeferredBeginBatch;
  *((_QWORD *)&v3 + 1) = v4;
  CMatCallQueue::QueueCall<CMatQueuedRenderContext *,CMatQueuedRenderContext,void>(
    this: &this->m_queue,
    pObject: this,
    pfnProxied: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10042BC0
// Name: public: virtual void CMatQueuedRenderContext::BindBatch(class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BindBatch(
        CMatQueuedRenderContext *this,
        IMesh *pVertices,
        IMaterial *pAutoBind)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMesh *,IMaterial *,IMesh *,IMaterial *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{552,{flat}},
    arg1: &pVertices,
    arg2: &pAutoBind);
}

//------------------------------------------------------------------------------
// Address: 0x10042C10
// Name: public: virtual void CMatQueuedRenderContext::DrawBatch(enum MaterialPrimitiveType_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DrawBatch(
        CMatQueuedRenderContext *this,
        MaterialPrimitiveType_t primType,
        int firstIndex,
        int numIndices)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialPrimitiveType_t,int,int,enum MaterialPrimitiveType_t,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{556,{flat}},
    arg1: &primType,
    arg2: &firstIndex,
    arg3: &numIndices);
}

//------------------------------------------------------------------------------
// Address: 0x10042C70
// Name: public: virtual void CMatQueuedRenderContext::EndBatch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EndBatch(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{560,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10042CC0
// Name: public: virtual void CMatQueuedRenderContext::DrawInstances(int,struct MeshInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DrawInstances(
        CMatQueuedRenderContext *this,
        int nInstanceCount,
        const MeshInstanceData_t *pInstance)
{
  unsigned __int8 *v3; // ebx
  unsigned int v5; // edi
  CMatQueuedRenderContext_vtbl *v6; // eax
  char renderData_12; // [esp+28h] [ebp-10h]

  v3 = nullptr;
  renderData_12 = 0;
  if ( !this->IsRenderData(this, a2: pInstance) )
  {
    v5 = 76 * nInstanceCount;
    v3 = (unsigned __int8 *)this->LockRenderData(this, a2: 76 * nInstanceCount);
    renderData_12 = 1;
    memcpy(dst: v3, src: (unsigned __int8 *)pInstance, count: v5);
    pInstance = (const MeshInstanceData_t *)v3;
  }
  CMatCallQueue::QueueCall<CMatQueuedRenderContext *,CMatQueuedRenderContext,void,int,MeshInstanceData_t const *,int,MeshInstanceData_t const *>(
    this: &this->m_queue,
    pObject: this,
    pfnProxied: (unsigned int)CMatQueuedRenderContext::DeferredDrawInstances,
    arg1: &nInstanceCount,
    arg2: &pInstance);
  if ( v3 != nullptr )
  {
    v6 = this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable;
    if ( renderData_12 != 0 )
      v6->UnlockRenderData(this, a2: v3);
    else
      v6->ReleaseRenderData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042DD0
// Name: public: void CMatCallQueue::QueueCall<class CLateBoundPtr<class IMesh>,class IMesh,void,class IMesh __near *,int,class IMesh __near *,int>(class CLateBoundPtr<class IMesh>,void (IMesh::*)(class IMesh __near *,int),class IMesh __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CLateBoundPtr<IMesh>,IMesh,void,IMesh *,int,IMesh *,int>(
        CMatCallQueue *this,
        CLateBoundPtr<IMesh> pObject,
        __int128 pfnProxied,
        IMesh *const *arg1,
        const int *arg2)
{
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  CFunctor *v10; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = &this->m_Allocator.m_pNextAlloc[v8];
  if ( v9 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v8]) )
  {
    this->m_Allocator.m_pNextAlloc = v9;
  }
  v10 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CLateBoundPtr<IMesh>,IMesh,void,IMesh *,int,IMesh *,int>(
          this: &this->m_FunctorFactory,
          pObject,
          pfnProxied,
          arg1,
          arg2);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v10[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10042E70
// Name: public: void CMatCallQueue::QueueCall<class CLateBoundPtr<class IMesh>,class IMesh,void>(class CLateBoundPtr<class IMesh>,void (IMesh::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueCall<CLateBoundPtr<IMesh>,IMesh,void>(
        CMatCallQueue *this,
        CLateBoundPtr<IMesh> pObject,
        __int128 pfnProxied)
{
  unsigned int m_alignment; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int8 *v7; // edi
  CFunctor *v8; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v5 = 4;
  if ( m_alignment >= 4 )
    v5 = m_alignment;
  v6 = ~(m_alignment - 1) & (m_alignment + v5 - 1);
  v7 = &this->m_Allocator.m_pNextAlloc[v6];
  if ( v7 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v6]) )
  {
    this->m_Allocator.m_pNextAlloc = v7;
  }
  v8 = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateFunctor<CLateBoundPtr<IMesh>,IMesh,void>(
         this: &this->m_FunctorFactory,
         pObject,
         pfnProxied);
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&v8[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10042F00
// Name: public: virtual void CMatQueuedMesh::UnlockMesh(int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::UnlockMesh(CMatQueuedMesh *this, int numVerts, int numIndices, MeshDesc_t *desc)
{
  unsigned __int8 *m_pVertexData; // ebx
  int m_nVerts; // eax
  unsigned __int16 *m_pIndexData; // ebx
  int m_nIndices; // eax

  m_pVertexData = this->m_pVertexData;
  if ( m_pVertexData != nullptr )
  {
    m_nVerts = this->m_nVerts;
    if ( numVerts < m_nVerts )
    {
      CMemoryStack::FreeToAllocPoint(
        this: &this->m_pOwner->m_Vertices,
        mark: &this->m_pOwner->m_Vertices.m_pNextAlloc[-(this->m_VertexSize * (m_nVerts - numVerts))]
      - this->m_pOwner->m_Vertices.m_pBase,
        bDecommit: false);
      this->m_pVertexData = m_pVertexData;
      this->m_nVerts = numVerts;
    }
  }
  m_pIndexData = this->m_pIndexData;
  if ( m_pIndexData != nullptr )
  {
    m_nIndices = this->m_nIndices;
    if ( numIndices < m_nIndices )
    {
      CMemoryStack::FreeToAllocPoint(
        this: &this->m_pOwner->m_Indices,
        mark: (unsigned int)&this->m_pOwner->m_Indices.m_pNextAlloc[2 * (numIndices - m_nIndices)
                                                            - (unsigned int)this->m_pOwner->m_Indices.m_pBase],
        bDecommit: false);
      this->m_pIndexData = m_pIndexData;
      this->m_nIndices = numIndices;
    }
  }
  CMatQueuedMesh::QueueBuild(this);
}

//------------------------------------------------------------------------------
// Address: 0x10042F90
// Name: public: virtual void CMatQueuedMesh::SetColorMesh(class IMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::SetColorMesh(CMatQueuedMesh *this, IMesh *pColorMesh, int nVertexOffset)
{
  CMatCallQueue::QueueCall<CLateBoundPtr<IMesh>,IMesh,void,IMesh *,int,IMesh *,int>(
    this: this->m_pCallQueue,
    pObject: this->m_pLateBoundMesh,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{52,{flat}},
    arg1: &pColorMesh,
    arg2: &nVertexOffset);
}

//------------------------------------------------------------------------------
// Address: 0x10042FE0
// Name: public: virtual void CMatQueuedMesh::SetFlexMesh(class IMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::SetFlexMesh(CMatQueuedMesh *this, IMesh *pMesh, int nVertexOffset)
{
  CMatCallQueue::QueueCall<CLateBoundPtr<IMesh>,IMesh,void,IMesh *,int,IMesh *,int>(
    this: this->m_pCallQueue,
    pObject: this->m_pLateBoundMesh,
    pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{88,{flat}},
    arg1: &pMesh,
    arg2: &nVertexOffset);
}

//------------------------------------------------------------------------------
// Address: 0x10043030
// Name: public: virtual void CMatQueuedMesh::DisableFlexMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::DisableFlexMesh(CMatQueuedMesh *this)
{
  CMatCallQueue::QueueCall<CLateBoundPtr<IMesh>,IMesh,void>(
    this: this->m_pCallQueue,
    pObject: this->m_pLateBoundMesh,
    pfnProxied: (unsigned int) __thiscall IColorCorrectionSystem::`vcall'{92,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10043070
// Name: public: virtual void CMatQueuedMesh::MarkAsDrawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedMesh::MarkAsDrawn(CMatQueuedMesh *this)
{
  if ( this->m_bCanSetAuxMeshes )
    CMatCallQueue::QueueCall<CLateBoundPtr<IMesh>,IMesh,void>(
      this: this->m_pCallQueue,
      pObject: this->m_pLateBoundMesh,
      pfnProxied: (unsigned int) __thiscall IMesh::`vcall'{96,{flat}});
  this->m_nIndices = 0;
  this->m_pIndexData = nullptr;
  this->m_nVerts = 0;
  LODWORD(this->m_VertexFormat) = 0;
  HIDWORD(this->m_VertexFormat) = 0;
  this->m_pVertexData = nullptr;
  this->m_bCanSetAuxMeshes = false;
  this->m_nFlags = 0;
  *(_WORD *)&this->m_bExternalVB = 0;
  this->m_VertexSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100430E0
// Name: public: virtual void CMatQueuedIndexBuffer::BeginCastBuffer(enum MaterialIndexFormat_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedIndexBuffer::BeginCastBuffer(CMatQueuedIndexBuffer *this, MaterialIndexFormat_t format)
{
  CMatQueuedIndexBuffer::ReleaseBuffer(this);
  this->m_nIndexFormat = format;
}

//------------------------------------------------------------------------------
// Address: 0x10043100
// Name: public: virtual void CMatQueuedIndexBuffer::EndCastBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedIndexBuffer::EndCastBuffer(CMatQueuedIndexBuffer *this)
{
  CMatQueuedIndexBuffer::ReleaseBuffer(this);
  this->m_nIndexFormat = MATERIAL_INDEX_FORMAT_UNKNOWN;
}

//------------------------------------------------------------------------------
// Address: 0x10049210
// Name: public: virtual enum MaterialIndexFormat_t CMatQueuedIndexBuffer::IndexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedIndexBuffer::IndexFormat(CVTFTexture *this)
{
  return this->m_nMipCount;
}
