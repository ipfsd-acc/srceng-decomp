// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/host_saverestore.cpp
// Functions: 143
// ============================================================

#include "engine\host_saverestore.h"

//------------------------------------------------------------------------------
// Address: 0x100E0250
// Name: public: virtual void CMemberFunctor1<class CModelRender __near *,int (CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>::*)(struct memhandle_t__ __near *),struct memhandle_t__ __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  CModelRender *m_pObject; // ecx

  m_pObject = this->m_Proxy.m_pObject;
  if ( m_pObject != nullptr )
    this->m_Proxy.m_pfnProxied(
      this: &m_pObject->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,
      a2: this->m_arg1);
  else
    this->m_Proxy.m_pfnProxied(this: nullptr, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100EF550
// Name: struct datamap_t __near * DataMapInit<struct BSPHeader_t>(struct BSPHeader_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<BSPHeader_t>()
{
  if ( (_S2_6 & 1) == 0 )
  {
    _S2_6 |= 1u;
    nameHolder.m_pszBase = "BSPHeader_t";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = 11;
    atexit(func: DataMapInit_BSPHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  BSPHeader_t::m_DataMap.baseMap = nullptr;
  BSPHeader_t::m_DataMap.dataNumFields = 4;
  BSPHeader_t::m_DataMap.dataDesc = &dataDesc[1];
  return &BSPHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EFEE0
// Name: struct datamap_t __near * DataMapInit<struct lump_t>(struct lump_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<lump_t>()
{
  if ( (_S1_10 & 1) == 0 )
  {
    _S1_10 |= 1u;
    nameHolder_0.m_pszBase = "lump_t";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = 6;
    atexit(func: DataMapInit_lump_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  lump_t::m_DataMap.baseMap = nullptr;
  lump_t::m_DataMap.dataNumFields = 4;
  lump_t::m_DataMap.dataDesc = &dataDesc_0[1];
  return &lump_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10126FD0
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1> __near *,void (CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1013F160
// Name: public: virtual void CMemberFunctor0<class CCallQueue __near *,void (CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1> >::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x1013F7E0
// Name: private: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueFunctorInternal(class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CFunctor *pFunctor)
{
  CTSQueue<loopback_t *,0,1>::Node_t *v3; // eax

  if ( this->m_bNoQueue )
  {
    pFunctor->operator()(this: pFunctor);
    pFunctor->Release(this: pFunctor);
  }
  else
  {
    v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_queue.m_FreeNodes);
    if ( v3 != nullptr || (v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
    {
      v3->elem = (loopback_t *)pFunctor;
      CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: v3);
    }
    else
    {
      CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FBA0
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::CallQueued(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(CCallQueueT<CTSQueue<CFunctor *,0,1> > *this)
{
  CTSQueue<loopback_t *,0,1>::Node_t *v2; // eax
  CTSQueue<int,0,1>::Node_t *v3; // eax
  int elem; // esi

  if ( this->m_queue.m_Count.m_value != 0 )
  {
    v2 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_queue.m_FreeNodes);
    if ( v2 != nullptr )
    {
      v2->elem = nullptr;
    }
    else
    {
      v2 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
      if ( v2 != nullptr )
        v2->elem = nullptr;
      else
        v2 = nullptr;
    }
    CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: v2);
    while ( 1 )
    {
      v3 = CTSQueue<loopback_t *,0,1>::Pop((CTSQueue<int,0,1> *)this);
      if ( v3 == nullptr )
        break;
      elem = v3->elem;
      CTSListBase::Push(this: &this->m_queue.m_FreeNodes, pNode: (TSLNodeBase_t *)v3);
      if ( elem == 0 )
        break;
      (*(void (__thiscall **)(int))(*(_DWORD *)elem + 12))(a1: elem);
      (*(void (__thiscall **)(int))(*(_DWORD *)elem + 4))(a1: elem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FCA0
// Name: public: CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *> const __near &,class CUtlEnvelope<char const __near *> const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this,
        CBugUIPanel *pObject,
        __int128 pfnProxied,
        const CUtlEnvelope<char const *> *arg1,
        const CUtlEnvelope<char const *> *arg2,
        bool *arg3)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  *(_QWORD *)&this->m_Proxy.m_pfnProxied = pfnProxied;
  this->m_Proxy.m_pObject = pObject;
  *((_QWORD *)&this->m_Proxy.m_pfnProxied + 1) = *((_QWORD *)&pfnProxied + 1);
  CUtlString::CUtlString(this: &this->m_arg1.m_string);
  CUtlString::operator=(this: &this->m_arg1.m_string, src: &arg1->m_string);
  CUtlString::CUtlString(this: &this->m_arg2.m_string);
  CUtlString::operator=(this: &this->m_arg2.m_string, src: &arg2->m_string);
  this->m_arg3 = *arg3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013FD30
// Name: public: virtual void CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  const char *v2; // edi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: &this->m_arg2.m_string);
  v3 = CUtlString::operator char const *(this: &this->m_arg1.m_string);
  ((void (__thiscall *)(char *, const char *, const char *, bool))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: v3,
    a3: v2,
    a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x1013FD60
// Name: public: virtual CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::~CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::~CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_arg2.m_string.m_Storage.m_nActualLength = 0;
  if ( this->m_arg2.m_string.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory);
      this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_arg2.m_string.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_arg1.m_string.m_Storage.m_nActualLength = 0;
  if ( this->m_arg1.m_string.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory);
      this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_arg1.m_string.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CFunctor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10140DB0
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueCall<class CBugUIPanel __near *,class CBugUIPanel,bool,char const __near *,char const __near *,bool,class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool>(class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *> const __near &,class CUtlEnvelope<char const __near *> const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CBugUIPanel *pObject,
        __int128 pfnProxied,
        const CUtlEnvelope<char const *> *arg1,
        const CUtlEnvelope<char const *> *arg2,
        bool *arg3)
{
  CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v7; // eax
  CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v8; // eax

  v7 = (CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v7 != nullptr )
  {
    v8 = CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
           this: v7,
           pObject,
           pfnProxied,
           arg1,
           arg2,
           arg3);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: v8);
  }
  else
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187AB0
// Name: public: virtual void CFunctor1<void (*)(int),int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor1<void (__cdecl *)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor1<void (__cdecl*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x1018A2A0
// Name: struct datamap_t __near * DataMapInit<struct player_info_s>(struct player_info_s __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<player_info_s>()
{
  if ( (_S2_13 & 1) == 0 )
  {
    _S2_13 |= 1u;
    nameHolder_1.m_pszBase = "player_info_s";
    nameHolder_1.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_1.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_1.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_1.m_Names.m_Size = 0;
    nameHolder_1.m_Names.m_pElements = nullptr;
    nameHolder_1.m_nLenBase = 13;
    atexit(func: DataMapInit_player_info_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  player_info_s::m_DataMap.baseMap = nullptr;
  player_info_s::m_DataMap.dataNumFields = 10;
  player_info_s::m_DataMap.dataDesc = &dataDesc_1[1];
  return &player_info_s::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1018FB40
// Name: public: bool CSaveRestoreSegment::DefineSymbol(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreSegment::DefineSymbol(CSaveRestoreSegment *this, char *pszToken, int token)
{
  char **pTokens; // eax
  bool v4; // zf
  char **v5; // eax

  pTokens = this->pTokens;
  v4 = pTokens[token] == nullptr;
  v5 = &pTokens[token];
  if ( !v4 )
    return 0;
  *v5 = pszToken;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018FB70
// Name: public: virtual char const __near * CSaveRestore::FindRecentSave(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestore::FindRecentSave(CSaveRestore *this, char *pNameBuf, int nameBufLen)
{
  char *m_szMostRecentSaveLoadGame; // esi

  m_szMostRecentSaveLoadGame = this->m_szMostRecentSaveLoadGame;
  V_strncpy(pDest: pNameBuf, pSrc: this->m_szMostRecentSaveLoadGame, maxLen: nameBufLen);
  return *m_szMostRecentSaveLoadGame != 0 ? pNameBuf : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1018FBA0
// Name: public: virtual void CSaveRestore::ForgetRecentSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::ForgetRecentSave(CSaveRestore *this)
{
  this->m_szMostRecentSaveLoadGame[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018FBB0
// Name: public: virtual char const __near * CSaveRestore::GetSaveDir(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestore::GetSaveDir(CSaveRestore *this)
{
  _V_memset(dest: szDirectory, fill: 0, count: 260);
  V_strncpy(pDest: szDirectory, pSrc: "SAVE/", maxLen: 260);
  return szDirectory;
}

//------------------------------------------------------------------------------
// Address: 0x1018FBE0
// Name: private: void CSaveRestore::AgeSaveFile(char const __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::AgeSaveFile(
        CSaveRestore *this,
        const char *pName,
        const char *ext,
        int count,
        bool bIsXSave)
{
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int m_nValue; // eax
  int v13; // [esp-14h] [ebp-228h]
  int v14; // [esp-14h] [ebp-228h]
  int v15; // [esp-10h] [ebp-224h]
  const char *v16; // [esp-Ch] [ebp-220h]
  const char *v17; // [esp-Ch] [ebp-220h]
  const char *v18; // [esp-8h] [ebp-21Ch]
  int v19; // [esp-8h] [ebp-21Ch]
  int v20; // [esp-8h] [ebp-21Ch]
  const char *v21; // [esp-4h] [ebp-218h]
  const char *v22; // [esp-4h] [ebp-218h]
  const char *v23; // [esp-4h] [ebp-218h]
  char newName[260]; // [esp+Ch] [ebp-208h] BYREF
  char oldName[260]; // [esp+110h] [ebp-104h] BYREF

  if ( this->IsXSave(this) )
  {
    oldName[0] = 0;
    if ( count == 1 )
    {
      v15 = 260 - _V_strlen(str: oldName);
      v9 = _V_strlen(str: oldName);
      V_snprintf(pDest: &oldName[v9], maxLen: v15, pFormat: "//mod/%s.%s", pName, ext);
    }
    else
    {
      v13 = 260 - _V_strlen(str: oldName);
      v10 = _V_strlen(str: oldName);
      V_snprintf(pDest: &oldName[v10], maxLen: v13, pFormat: "//mod/%s%02d.%s", pName, count - 1, ext);
    }
    newName[0] = 0;
    v14 = 260 - _V_strlen(str: newName);
    v11 = _V_strlen(str: newName);
    V_snprintf(pDest: &newName[v11], maxLen: v14, pFormat: "//mod/%s%02d.%s", pName, count, ext);
  }
  else
  {
    if ( count == 1 )
    {
      v6 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, const char *))this->GetSaveDir)(
                           a1: this,
                           a2: pName,
                           a3: ext);
      V_snprintf(pDest: oldName, maxLen: 260, pFormat: "//%s/%s%s.%s", "MOD", v6, v18, v21);
    }
    else
    {
      v7 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, int, const char *))this->GetSaveDir)(
                           a1: this,
                           a2: pName,
                           a3: count - 1,
                           a4: ext);
      V_snprintf(pDest: oldName, maxLen: 260, pFormat: "//%s/%s%s%02d.%s", "MOD", v7, v16, v19, v22);
    }
    v8 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, int, const char *))this->GetSaveDir)(
                         a1: this,
                         a2: pName,
                         a3: count,
                         a4: ext);
    V_snprintf(pDest: newName, maxLen: 260, pFormat: "//%s/%s%s%02d.%s", "MOD", v8, v17, v20, v23);
  }
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: oldName, a3: nullptr) )
  {
    if ( save_history_count.m_pParent != nullptr )
      m_nValue = save_history_count.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( count == m_nValue && g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: newName, a3: nullptr) )
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: newName, a3: nullptr);
    g_pFileSystem->RenameFile(this: g_pFileSystem, a2: oldName, a3: newName, a4: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018FE00
// Name: protected: bool CSaveRestore::CalcSaveGameName(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestore::CalcSaveGameName(
        CSaveRestore *this,
        const char *pName,
        char *output,
        int outputStringLength)
{
  char *v5; // esi
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  int v10; // [esp-Ch] [ebp-14h]
  const char *v11; // [esp-4h] [ebp-Ch]

  if ( pName == nullptr || *pName == 0 )
    return 0;
  if ( this->IsXSave(this) )
  {
    v5 = output;
    *output = 0;
    v6 = outputStringLength;
    v10 = outputStringLength - _V_strlen(str: output);
    v7 = _V_strlen(str: output);
    V_snprintf(pDest: &output[v7], maxLen: v10, pFormat: "//mod/%s", pName);
  }
  else
  {
    v8 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: pName);
    v6 = outputStringLength;
    v5 = output;
    V_snprintf(pDest: output, maxLen: outputStringLength, pFormat: "%s%s", v8, v11);
  }
  V_DefaultExtension(path: v5, extension: ".sav", pathStringLength: v6);
  V_FixSlashes(pname: v5, separator: 92);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018FEA0
// Name: public: virtual bool CSaveRestore::SaveFileExists(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::SaveFileExists(CSaveRestore *this, const char *pName)
{
  bool result; // al
  char name[256]; // [esp+4h] [ebp-100h] BYREF

  this->FinishAsyncSave(this);
  result = CSaveRestore::CalcSaveGameName(this, pName, output: name, outputStringLength: 256);
  if ( result )
  {
    if ( !this->IsXSave(this) || this->StorageDeviceValid(this) )
      return g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: name, a3: nullptr);
    else
      return g_pSaveRestoreFileSystem->FileExists(this: g_pSaveRestoreFileSystem, a2: name, a3: nullptr);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018FF40
// Name: public: virtual bool CSaveRestore::IsOverrideLoadGameEntsOn(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::IsOverrideLoadGameEntsOn(CSaveRestore *this)
{
  return this->m_bOverrideLoadGameEntsOn;
}

//------------------------------------------------------------------------------
// Address: 0x1018FF50
// Name: private: virtual void CSaveRestore::SetMostRecentSaveGame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SetMostRecentSaveGame(CSaveRestore *this, const char *pSaveName)
{
  char *m_szMostRecentSaveLoadGame; // esi

  m_szMostRecentSaveLoadGame = this->m_szMostRecentSaveLoadGame;
  if ( pSaveName != nullptr )
    V_strncpy(pDest: this->m_szMostRecentSaveLoadGame, pSrc: pSaveName, maxLen: 260);
  else
    *m_szMostRecentSaveLoadGame = 0;
  if ( *m_szMostRecentSaveLoadGame == 0 )
    DevWarning(a1: "Cleared most recent save!\n");
}

//------------------------------------------------------------------------------
// Address: 0x1018FF90
// Name: private: virtual int CSaveRestore::GetMostRecentElapsedMinutes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::GetMostRecentElapsedMinutes(CSaveRestore *this)
{
  return this->m_MostRecentElapsedMinutes;
}

//------------------------------------------------------------------------------
// Address: 0x1018FFA0
// Name: private: virtual int CSaveRestore::GetMostRecentElapsedSeconds(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::GetMostRecentElapsedSeconds(CSaveRestore *this)
{
  return this->m_MostRecentElapsedSeconds;
}

//------------------------------------------------------------------------------
// Address: 0x1018FFB0
// Name: private: virtual int CSaveRestore::GetMostRecentElapsedTimeSet(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::GetMostRecentElapsedTimeSet(CSaveRestore *this)
{
  return this->m_MostRecentElapsedTimeSet;
}

//------------------------------------------------------------------------------
// Address: 0x1018FFC0
// Name: private: virtual void CSaveRestore::SetMostRecentElapsedMinutes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SetMostRecentElapsedMinutes(CSaveRestore *this, int min)
{
  this->m_MostRecentElapsedMinutes = min;
  this->m_MostRecentElapsedTimeSet = (int)g_ServerGlobalVariables.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x1018FFE0
// Name: private: virtual void CSaveRestore::SetMostRecentElapsedSeconds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SetMostRecentElapsedSeconds(CSaveRestore *this, int sec)
{
  this->m_MostRecentElapsedSeconds = sec;
  this->m_MostRecentElapsedTimeSet = (int)g_ServerGlobalVariables.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10190000
// Name: public: bool SaveFileHeaderTag_t::operator!=(struct SaveFileHeaderTag_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall SaveFileHeaderTag_t::operator!=(SaveFileHeaderTag_t *this, const SaveFileHeaderTag_t *rhs)
{
  unsigned int v3; // eax

  v3 = 8;
  while ( this->id == rhs->id )
  {
    v3 -= 4;
    rhs = (const SaveFileHeaderTag_t *)((char *)rhs + 4);
    this = (SaveFileHeaderTag_t *)((char *)this + 4);
    if ( v3 < 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10190070
// Name: private: void CSaveRestore::SaveGameStateGlobals(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SaveGameStateGlobals(CSaveRestore *this, CSaveRestoreData *pSaveData)
{
  INetworkStringTable *LightStyleTable; // ebx
  int v3; // edi
  _BYTE *v4; // eax
  int v5; // edi
  levellist_t *levelList; // ebx
  int i; // edi
  const char *v8; // eax
  SAVELIGHTSTYLE light; // [esp+Ch] [ebp-ACh] BYREF
  SAVE_HEADER header; // [esp+50h] [ebp-68h] BYREF
  ConVarRef skyname; // [esp+ACh] [ebp-Ch] BYREF
  INetworkStringTable *table; // [esp+B4h] [ebp-4h]

  LightStyleTable = CBaseServer::GetLightStyleTable(this: &sv);
  table = LightStyleTable;
  header.version = build_number();
  v3 = 0;
  if ( skill.m_pParent != nullptr )
    header.skillLevel = skill.m_pParent->m_Value.m_nValue;
  else
    header.skillLevel = 0;
  header.connectionCount = pSaveData->levelInfo.connectionCount;
  header.time = CBaseServer::GetTime(this: &sv);
  ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname");
  if ( ConVarRef::IsValid(this: &skyname) )
    V_strncpy(pDest: header.skyName, pSrc: skyname.m_pConVarState->m_Value.m_pszString, maxLen: 32);
  else
    V_strncpy(pDest: header.skyName, pSrc: "unknown", maxLen: 32);
  V_strncpy(pDest: header.mapName, pSrc: sv.m_szMapname, maxLen: 32);
  header.lightStyleCount = 0;
  header.mapVersion = g_ServerGlobalVariables.mapversion;
  do
  {
    v4 = LightStyleTable->GetStringUserData(this: LightStyleTable, a2: v3, a3: nullptr);
    if ( v4 != nullptr && *v4 != 0 )
      ++header.lightStyleCount;
    ++v3;
  }
  while ( v3 < 64 );
  pSaveData->levelInfo.time = 0.0;
  serverGameDLL->SaveWriteFields(
    this: serverGameDLL,
    a2: pSaveData,
    a3: "Save Header",
    a4: &header,
    a5: nullptr,
    a6: SAVE_HEADER::m_DataMap.dataDesc,
    a7: SAVE_HEADER::m_DataMap.dataNumFields);
  v5 = 0;
  pSaveData->levelInfo.time = header.time;
  if ( pSaveData->levelInfo.connectionCount > 0 )
  {
    levelList = pSaveData->levelInfo.levelList;
    do
    {
      serverGameDLL->SaveWriteFields(
        this: serverGameDLL,
        a2: pSaveData,
        a3: "ADJACENCY",
        a4: levelList,
        a5: nullptr,
        a6: levellist_t::m_DataMap.dataDesc,
        a7: levellist_t::m_DataMap.dataNumFields);
      ++v5;
      ++levelList;
    }
    while ( v5 < pSaveData->levelInfo.connectionCount );
    LightStyleTable = table;
  }
  for ( i = 0; i < 64; ++i )
  {
    v8 = (const char *)LightStyleTable->GetStringUserData(this: LightStyleTable, a2: i, a3: nullptr);
    if ( v8 != nullptr && *v8 != 0 )
    {
      light.index = i;
      V_strncpy(pDest: light.style, pSrc: v8, maxLen: 64);
      serverGameDLL->SaveWriteFields(
        this: serverGameDLL,
        a2: pSaveData,
        a3: "LIGHTSTYLE",
        a4: &light,
        a5: nullptr,
        a6: SAVELIGHTSTYLE::m_DataMap.dataDesc,
        a7: SAVELIGHTSTYLE::m_DataMap.dataNumFields);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190220
// Name: public: virtual void CSaveRestore::RestoreAdjacenClientState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::RestoreAdjacenClientState(CSaveRestore *this, const char *map)
{
  const char *v3; // eax
  int v4; // eax
  int v5; // [esp-Ch] [ebp-110h]
  const char *v6; // [esp-4h] [ebp-108h]
  char name[256]; // [esp+4h] [ebp-100h] BYREF

  if ( this->IsXSave(this) )
  {
    name[0] = 0;
    V_FileBase(in: map, out: level, maxlen: 256);
    v5 = 256 - _V_strlen(str: name);
    v4 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v4], maxLen: v5, pFormat: "//mod/%s.HL2", level);
  }
  else
  {
    V_FileBase(in: map, out: level, maxlen: 256);
    v3 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))this->GetSaveDir)(a1: this, a2: level);
    V_snprintf(pDest: name, maxLen: 256, pFormat: "//%s/%s%s.HL2", "MOD", v3, v6);
  }
  COM_CreatePath(path: name);
  this->RestoreClientState(this, a2: name, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10190300
// Name: private: virtual int CSaveRestore::SaveReadNameAndComment(void __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::SaveReadNameAndComment(CSaveRestore *this, char *f, char *name, char *comment)
{
  void *v4; // esi
  char *v6; // edx
  char *v7; // edi
  char *v8; // eax
  __int16 *v9; // esi
  char **v10; // ebx
  int v11; // eax
  const char *v12; // eax
  int v13; // edi
  int v14; // eax
  const char *v15; // esi
  const char *v16; // ebx
  int v17; // edi
  const char *v18; // esi
  char *pSaveData; // [esp+4h] [ebp-18h]
  int i; // [esp+8h] [ebp-14h]
  int tokenSize; // [esp+Ch] [ebp-10h] BYREF
  int tag; // [esp+10h] [ebp-Ch] BYREF
  char **pTokenList; // [esp+14h] [ebp-8h]
  int tokenCount; // [esp+18h] [ebp-4h] BYREF

  v4 = f;
  if ( g_pSaveRestoreFileSystem->Size_2(this: g_pSaveRestoreFileSystem, a2: f) < 0x14 )
    return 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 4, a4: v4) != 4 )
    return 0;
  if ( tag != 1447121738 )
    return 0;
  v6 = comment;
  *name = 0;
  *v6 = 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 4, a4: v4) != 4 )
    return 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &f, a3: 4, a4: v4) != 4 )
    return 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tokenCount, a3: 4, a4: v4) != 4 )
    return 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tokenSize, a3: 4, a4: v4) != 4 )
    return 0;
  f += tokenSize;
  if ( (unsigned int)tokenCount > 0x2000000 || (unsigned int)tokenSize > 0xA00000 )
    return 0;
  v7 = (char *)MemAlloc_Alloc(nSize: (unsigned int)f);
  pSaveData = v7;
  v8 = (char *)g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: v7, a3: (int)f, a4: v4);
  if ( v8 != f )
  {
    free(pMem: v7);
    return 0;
  }
  v9 = (__int16 *)v7;
  if ( tokenSize <= 0 )
  {
    pTokenList = nullptr;
    v10 = nullptr;
  }
  else
  {
    v10 = (char **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)tokenCount >> 30 != 0 ? -1 : 4 * tokenCount);
    v11 = 0;
    for ( pTokenList = v10; v11 < tokenCount; ++v11 )
    {
      v10[v11] = *(_BYTE *)v9 != 0 ? (char *)v9 : nullptr;
      v9 = (__int16 *)((char *)v9 + strlen((const char *)v9) + 1);
    }
  }
  v12 = v10[v9[1]];
  v13 = *v9;
  if ( v12 == nullptr || _V_stricmp(s1: v12, s2: "GameHeader") != 0 )
  {
    free(pMem: pSaveData);
    free(pMem: v10);
  }
  else
  {
    v14 = *((_DWORD *)v9 + 1);
    v15 = (char *)v9 + v13 + 4;
    if ( v14 > 0 )
    {
      for ( i = v14; i != 0; --i )
      {
        v16 = v10[*((__int16 *)v15 + 1)];
        v17 = *(__int16 *)v15;
        v18 = v15 + 4;
        if ( _V_stricmp(s1: v16, s2: "comment") != 0 )
        {
          if ( _V_stricmp(s1: v16, s2: "mapName") == 0 )
            V_strncpy(pDest: name, pSrc: v18, maxLen: v17);
        }
        else
        {
          V_strncpy(pDest: comment, pSrc: v18, maxLen: v17);
        }
        v10 = pTokenList;
        v15 = &v18[v17];
      }
    }
    free(pMem: v10);
    free(pMem: pSaveData);
    if ( strlen(name) != 0 && strlen(comment) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10190570
// Name: private: void CSaveRestore::ParseSaveTables(class CSaveRestoreData __near *,struct SAVE_HEADER __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::ParseSaveTables(
        CSaveRestore *this,
        CSaveRestoreData *pSaveData,
        SAVE_HEADER *pHeader,
        int updateGlobals)
{
  INetworkStringTable *LightStyleTable; // eax
  SAVE_HEADER *v5; // ebx
  int v6; // edi
  levellist_t *levelList; // ebx
  int j; // edi
  INetworkStringTable_vtbl *v9; // edi
  int v10; // eax
  SAVELIGHTSTYLE light; // [esp+Ch] [ebp-48h] BYREF
  INetworkStringTable *table; // [esp+50h] [ebp-4h]
  int i; // [esp+60h] [ebp+Ch]

  LightStyleTable = CBaseServer::GetLightStyleTable(this: &sv);
  pSaveData->bufferSize -= pSaveData->size;
  v5 = pHeader;
  table = LightStyleTable;
  pSaveData->pBaseData = pSaveData->pCurrentData;
  v6 = 0;
  pSaveData->size = 0;
  serverGameDLL->SaveReadFields(
    this: serverGameDLL,
    a2: pSaveData,
    a3: "Save Header",
    a4: pHeader,
    a5: nullptr,
    a6: SAVE_HEADER::m_DataMap.dataDesc,
    a7: SAVE_HEADER::m_DataMap.dataNumFields);
  pSaveData->levelInfo.mapVersion = pHeader->mapVersion;
  pSaveData->levelInfo.connectionCount = pHeader->connectionCount;
  pSaveData->levelInfo.time = pHeader->time;
  pSaveData->levelInfo.fUseLandmark = 1;
  pSaveData->levelInfo.vecLandmarkOffset = vec3_origin;
  if ( pSaveData->levelInfo.connectionCount > 0 )
  {
    levelList = pSaveData->levelInfo.levelList;
    do
    {
      serverGameDLL->SaveReadFields(
        this: serverGameDLL,
        a2: pSaveData,
        a3: "ADJACENCY",
        a4: levelList,
        a5: nullptr,
        a6: levellist_t::m_DataMap.dataDesc,
        a7: levellist_t::m_DataMap.dataNumFields);
      ++v6;
      ++levelList;
    }
    while ( v6 < pSaveData->levelInfo.connectionCount );
    v5 = pHeader;
  }
  if ( updateGlobals != 0 )
  {
    for ( j = 0; j < 64; ++j )
      table->SetStringUserData(this: table, a2: j, a3: 1, a4: defaultValue);
  }
  for ( i = 0; i < v5->lightStyleCount; ++i )
  {
    serverGameDLL->SaveReadFields(
      this: serverGameDLL,
      a2: pSaveData,
      a3: "LIGHTSTYLE",
      a4: &light,
      a5: nullptr,
      a6: SAVELIGHTSTYLE::m_DataMap.dataDesc,
      a7: SAVELIGHTSTYLE::m_DataMap.dataNumFields);
    if ( updateGlobals != 0 )
    {
      v9 = table->__vftable;
      v10 = _V_strlen(str: light.style);
      v9->SetStringUserData(this: table, a2: light.index, a3: v10 + 1, a4: light.style);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101906F0
// Name: private: void CSaveRestore::EntityPatchRead(class CSaveRestoreData __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::EntityPatchRead(CSaveRestore *this, CSaveRestoreData *pSaveData, const char *level)
{
  const char *v4; // eax
  int v5; // eax
  void *v6; // edi
  int i; // esi
  int v8; // [esp-Ch] [ebp-120h]
  const char *v9; // [esp-4h] [ebp-118h]
  char name[260]; // [esp+8h] [ebp-10Ch] BYREF
  int entityId; // [esp+10Ch] [ebp-8h] BYREF
  int size; // [esp+110h] [ebp-4h] BYREF

  if ( this->IsXSave(this) )
  {
    name[0] = 0;
    V_FileBase(in: level, out: ::level, maxlen: 256);
    v8 = 260 - _V_strlen(str: name);
    v5 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v5], maxLen: v8, pFormat: "//mod/%s.HL3", ::level);
  }
  else
  {
    V_FileBase(in: level, out: ::level, maxlen: 256);
    v4 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))this->GetSaveDir)(a1: this, a2: ::level);
    V_snprintf(pDest: name, maxLen: 260, pFormat: "//%s/%s%s.HL3", "MOD", v4, v9);
  }
  v6 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: name, a3: "rb", a4: nullptr);
  if ( v6 != nullptr )
  {
    g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &size, a3: 4, a4: v6);
    for ( i = 0; i < size; pSaveData->pTable[entityId].flags = 0x40000000 )
    {
      g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &entityId, a3: 4, a4: v6);
      ++i;
    }
    g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190830
// Name: void LandmarkOrigin(class CSaveRestoreData __near *,class Vector __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LandmarkOrigin(CSaveRestoreData *pSaveData, Vector *output, const char *pLandmarkName)
{
  int v3; // esi
  char *landmarkName; // ebx

  v3 = 0;
  if ( pSaveData->levelInfo.connectionCount <= 0 )
  {
LABEL_5:
    *output = vec3_origin;
  }
  else
  {
    landmarkName = pSaveData->levelInfo.levelList[0].landmarkName;
    while ( _V_stricmp(s1: landmarkName, s2: pLandmarkName) != 0 )
    {
      ++v3;
      landmarkName += 80;
      if ( v3 >= pSaveData->levelInfo.connectionCount )
        goto LABEL_5;
    }
    *output = pSaveData->levelInfo.levelList[v3].vecLandmarkOrigin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101908B0
// Name: private: bool CSaveRestore::DirectoryExtract(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::DirectoryExtract(CSaveRestore *this, void *pFile, int fileCount)
{
  ISaveRestoreFileSystem_vtbl *v3; // esi
  bool v4; // al

  v3 = g_pSaveRestoreFileSystem->__vftable;
  v4 = this->IsXSave(this);
  return v3->DirectoryExtract(this: g_pSaveRestoreFileSystem, a2: pFile, a3: fileCount, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101908E0
// Name: public: virtual void CSaveRestore::RequestClearSaveDir(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::RequestClearSaveDir(CSaveRestore *this)
{
  this->m_bClearSaveDir = true;
}

//------------------------------------------------------------------------------
// Address: 0x101908F0
// Name: public: void CSaveRestore::DoClearSaveDir(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::DoClearSaveDir(CSaveRestore *this, bool bIsXSave)
{
  const char *v3; // eax
  int v4; // eax
  ISaveRestoreFileSystem_vtbl *v5; // edi
  bool v6; // al
  int v7; // [esp-8h] [ebp-114h]
  char szName[260]; // [esp+8h] [ebp-104h] BYREF

  if ( bIsXSave )
  {
    szName[0] = 0;
    v7 = 260 - _V_strlen(str: szName);
    v4 = _V_strlen(str: szName);
    V_snprintf(pDest: &szName[v4], maxLen: v7, pFormat: "//mod/");
  }
  else
  {
    v3 = this->GetSaveDir(this);
    V_snprintf(pDest: szName, maxLen: 260, pFormat: "%s", v3);
    V_FixSlashes(pname: szName, separator: 92);
    Sys_mkdir(path: szName);
  }
  V_strncat(pDest: szName, pSrc: "*.HL?", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v5 = g_pSaveRestoreFileSystem->__vftable;
  v6 = this->IsXSave(this);
  v5->DirectoryClear(this: g_pSaveRestoreFileSystem, a2: szName, a3: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101909D0
// Name: minisave
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall minisave(int a1@<edi>, const CCommand *args)
{
  int v2; // eax
  int v3; // edi
  int (__thiscall *GetMostRecentElapsedSeconds)(ISaveRestore *); // edx
  int v5; // eax
  void (__thiscall *GetSaveComment)(IServerGameDLL *, char *, int, float, float, bool); // edx
  const char *v7; // ebx
  float v8; // [esp+4h] [ebp-68h]
  _BYTE v9[24]; // [esp+14h] [ebp-58h] BYREF
  __int64 comment_56; // [esp+64h] [ebp-8h] OVERLAPPED

  if ( saverestore->IsValidSave(this: saverestore) != 0 )
  {
    if ( serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
    {
      if ( args->m_nArgc == 2 )
      {
        strstr(str1: (unsigned __int8 *)args->m_ppArgv[1], str2: "..");
        if ( v2 == 0 )
        {
          v3 = (int)(float)(g_ServerGlobalVariables.curtime
                          - (float)((int (__thiscall *)(ISaveRestore *, int))saverestore->GetMostRecentElapsedTimeSet)(
                                     a1: saverestore,
                                     a2: a1));
          HIDWORD(comment_56) = v3 / 60 + saverestore->GetMostRecentElapsedMinutes(this: saverestore);
          GetMostRecentElapsedSeconds = saverestore->GetMostRecentElapsedSeconds;
          *(float *)&comment_56 = (float)SHIDWORD(comment_56);
          v5 = GetMostRecentElapsedSeconds(this: saverestore);
          GetSaveComment = serverGameDLL->GetSaveComment;
          HIDWORD(comment_56) = v3 % 60 + v5;
          v8 = (float)SHIDWORD(comment_56);
          ((void (__thiscall *)(IServerGameDLL *, _BYTE *, int, _DWORD, _DWORD, _DWORD))GetSaveComment)(
            a1: serverGameDLL,
            a2: v9,
            a3: 80,
            a4: comment_56,
            a5: LODWORD(v8),
            a6: 0);
          LOBYTE(comment_56) = saverestore->IsXSave(this: saverestore);
          saverestore->SetIsXSave(this: saverestore, a2: false);
          if ( args->m_nArgc > 1 )
            v7 = args->m_ppArgv[1];
          else
            v7 = defaultValue;
          ((void (__thiscall *)(ISaveRestore *, const char *, _BYTE *, int, _DWORD, _DWORD))saverestore->SaveGameSlot)(
            a1: saverestore,
            a2: v7,
            a3: v9,
            a4: 1,
            a5: 0,
            a6: 0);
          saverestore->SetIsXSave(this: saverestore, a2: comment_56);
        }
      }
    }
    else
    {
      ConMsg(a1: "This game doesn't support save/restore.");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190B30
// Name: AutoSave_Silent
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall AutoSave_Silent(int a1@<edi>, int a2@<esi>, bool bDangerous)
{
  int v3; // edi
  int (__thiscall *GetMostRecentElapsedSeconds)(ISaveRestore *); // edx
  int v5; // eax
  void (__thiscall *GetSaveComment)(IServerGameDLL *, char *, int, float, float, bool); // edx
  float v7; // [esp+4h] [ebp-60h]
  _DWORD v8[5]; // [esp+Ch] [ebp-58h] BYREF
  __int64 comment_60; // [esp+5Ch] [ebp-8h] OVERLAPPED

  if ( !g_bInCommentaryMode
    && saverestore->IsValidSave(this: saverestore) != 0
    && serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
  {
    v3 = (int)(float)(g_ServerGlobalVariables.curtime
                    - (float)((int (__thiscall *)(ISaveRestore *, int, int))saverestore->GetMostRecentElapsedTimeSet)(
                               a1: saverestore,
                               a2: a1,
                               a3: a2));
    HIDWORD(comment_60) = v3 / 60 + saverestore->GetMostRecentElapsedMinutes(this: saverestore);
    GetMostRecentElapsedSeconds = saverestore->GetMostRecentElapsedSeconds;
    *(float *)&comment_60 = (float)SHIDWORD(comment_60);
    v5 = GetMostRecentElapsedSeconds(this: saverestore);
    GetSaveComment = serverGameDLL->GetSaveComment;
    HIDWORD(comment_60) = v3 % 60 + v5;
    v7 = (float)SHIDWORD(comment_60);
    ((void (__thiscall *)(IServerGameDLL *, _DWORD *, int, _DWORD, _DWORD, _DWORD))GetSaveComment)(
      a1: serverGameDLL,
      a2: v8,
      a3: 80,
      a4: comment_60,
      a5: LODWORD(v7),
      a6: 0);
    saverestore->SetIsXSave(this: saverestore, a2: false);
    v8[1] = 0;
    v8[0] = 0;
    if ( bDangerous )
      ((void (__thiscall *)(ISaveRestore *, const char *, _DWORD *, _DWORD, _DWORD))saverestore->SaveGameSlot)(
        a1: saverestore,
        a2: "autosavedangerous",
        a3: v8,
        a4: 0,
        a5: 0);
    else
      ((void (__thiscall *)(ISaveRestore *, const char *, _DWORD *, _DWORD, int))saverestore->SaveGameSlot)(
        a1: saverestore,
        a2: "autosave",
        a3: v8,
        a4: 0,
        a5: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190C60
// Name: _autosave
// Source: json
//------------------------------------------------------------------------------
void __usercall autosave(int a1@<edi>, int a2@<esi>)
{
  AutoSave_Silent(a1, a2, bDangerous: false);
}

//------------------------------------------------------------------------------
// Address: 0x10190C70
// Name: _autosavedangerous
// Source: json
//------------------------------------------------------------------------------
void __usercall autosavedangerous(int a1@<edi>, int a2@<esi>)
{
  if ( saverestore->StorageDeviceValid(this: saverestore) )
    AutoSave_Silent(a1, a2, bDangerous: true);
}

//------------------------------------------------------------------------------
// Address: 0x10190C90
// Name: autosavedangerousissafe
// Source: json
//------------------------------------------------------------------------------
void __cdecl autosavedangerousissafe()
{
  saverestore->AutoSaveDangerousIsSafe(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x10190CA0
// Name: LoadSaveGame
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSaveGame(const char *savename@<esi>, int a2@<edi>, bool bLetToolsOverrideLoadGameEnts)
{
  CStatTime *v3; // ecx
  IEngineVGuiInternal *v4; // eax

  if ( ((unsigned __int8 (__thiscall *)(ISaveRestore *))saverestore->SaveFileExists)(a1: saverestore) != 0 )
  {
    CTestScriptMgr::SetWaitCheckPoint(this: &g_TestScriptMgr, pCheckPointName: "load_game", bOnce: false);
    if ( sv.m_State < ss_active || sv.m_bIsLevelMainMenuBackground )
    {
      v4 = EngineVGui();
      v4->EnabledProgressBarForNextLoad(this: v4);
    }
    SCR_BeginLoadingPlaque(a1: v3, a2, levelName: nullptr);
    Host_Disconnect(bShowMainMenu: false);
    HostState_LoadGame(pSaveFileName: savename, remember_location: false, bLetToolsOverrideLoadGameEnts);
  }
  else
  {
    _Warning(a1: "Can't load '%s', file missing!\n", savename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190D20
// Name: void SetLoadLaunchOptions(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLoadLaunchOptions()
{
  KeyValues *v0; // eax
  KeyValues *v1; // eax

  if ( g_pLaunchOptions != nullptr )
    KeyValues::deleteThis(this: g_pLaunchOptions);
  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr )
    v1 = KeyValues::KeyValues(this: v0, setName: "LaunchOptions");
  else
    v1 = nullptr;
  g_pLaunchOptions = v1;
  KeyValues::SetString(this: v1, keyName: "Arg0", value: "load");
  KeyValues::SetString(this: g_pLaunchOptions, keyName: "Arg1", value: "reserved");
}

//------------------------------------------------------------------------------
// Address: 0x10190D80
// Name: g_load_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_load_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S12 & 1) == 0 )
  {
    _S12 |= 1u;
    loadComplete.m_pszCommandName = "load";
    loadComplete.m_pszSubDir = "save";
    loadComplete.m_pszExtension = "sav";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &loadComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10190DD0
// Name: public: virtual void CSaveRestore::SetIsXSave(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SetIsXSave(CSaveRestore *this, bool bIsXSave)
{
  this->m_bIsXSave = bIsXSave;
}

//------------------------------------------------------------------------------
// Address: 0x10190DE0
// Name: public: virtual void CSaveRestore::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::Shutdown(CSaveRestore *this)
{
  this->FinishAsyncSave(this);
  if ( g_pSaveThread != nullptr )
  {
    g_pSaveThread->Stop(this: g_pSaveThread, a2: -1);
    g_pSaveThread->Release(this: g_pSaveThread);
    g_pSaveThread = nullptr;
  }
  this->m_szSaveGameScreenshotFile[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10190E20
// Name: public: virtual char const __near * CSaveRestore::GetMostRecentlyLoadedFileName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestore::GetMostRecentlyLoadedFileName(CSaveRestore *this)
{
  return this->m_szMostRecentSaveLoadGame;
}

//------------------------------------------------------------------------------
// Address: 0x10190E30
// Name: public: virtual char const __near * CSaveRestore::GetSaveFileName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestore::GetSaveFileName(CSaveRestore *this)
{
  return this->m_szSaveGameName;
}

//------------------------------------------------------------------------------
// Address: 0x10190E40
// Name: public: virtual bool CSaveRestore::SaveGame(char const __near *,bool,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __thiscall CSaveRestore::SaveGame(
        CSaveRestore *this,
        const char *pSaveFilename,
        BOOL bIsXSave,
        char *pOutName,
        int nOutNameSize,
        char *pOutComment,
        int nOutCommentSize)
{
  int v9; // edi
  int (__thiscall *GetMostRecentElapsedSeconds)(ISaveRestore *); // eax
  float v11; // [esp+4h] [ebp-68h]
  char pSrc[24]; // [esp+18h] [ebp-54h] BYREF
  float comment_56; // [esp+68h] [ebp-4h] OVERLAPPED
  int comment_72; // [esp+78h] [ebp+Ch]

  if ( saverestore->IsValidSave(this: saverestore) == 0 || !serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
    return false;
  saverestore->SetIsXSave(this: saverestore, a2: bIsXSave);
  v9 = (int)(float)(g_ServerGlobalVariables.curtime - (float)saverestore->GetMostRecentElapsedTimeSet(this: saverestore));
  comment_72 = v9 / 60 + saverestore->GetMostRecentElapsedMinutes(this: saverestore);
  GetMostRecentElapsedSeconds = saverestore->GetMostRecentElapsedSeconds;
  comment_56 = (float)comment_72;
  v11 = (float)(v9 % 60 + GetMostRecentElapsedSeconds(this: saverestore));
  ((void (__thiscall *)(IServerGameDLL *, char *, int, _DWORD, _DWORD, _DWORD))serverGameDLL->GetSaveComment)(
    a1: serverGameDLL,
    a2: pSrc,
    a3: 80,
    a4: LODWORD(comment_56),
    a5: LODWORD(v11),
    a6: 0);
  CSaveRestore::CalcSaveGameName(this, pName: pSaveFilename, output: pOutName, outputStringLength: nOutNameSize);
  V_strncpy(pDest: pOutComment, pSrc, maxLen: nOutCommentSize);
  return saverestore->SaveGameSlot(
           this: saverestore,
           a2: pSaveFilename,
           a3: pSrc,
           a4: false,
           a5: true,
           a6: nullptr,
           a7: nullptr) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10190FB0
// Name: private: void CSaveRestore::AgeSaveList(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveRestore::AgeSaveList(
        CSaveRestore *this@<ecx>,
        int a2@<edi>,
        const char *pName,
        int count,
        bool bIsXSave)
{
  int i; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int m_nValue; // eax
  int v14; // [esp-14h] [ebp-224h]
  int v15; // [esp-14h] [ebp-224h]
  int v16; // [esp-10h] [ebp-220h]
  const char *v17; // [esp-Ch] [ebp-21Ch]
  const char *v18; // [esp-Ch] [ebp-21Ch]
  const char *v19; // [esp-8h] [ebp-218h]
  int v20; // [esp-8h] [ebp-218h]
  int v21; // [esp-8h] [ebp-218h]
  const char *v23; // [esp-4h] [ebp-214h]
  const char *v24; // [esp-4h] [ebp-214h]
  const char *v25; // [esp-4h] [ebp-214h]
  char str[260]; // [esp+8h] [ebp-208h] BYREF
  char pDest[260]; // [esp+10Ch] [ebp-104h] BYREF

  for ( i = count; i > 0; --i )
  {
    if ( ((unsigned __int8 (__thiscall *)(CSaveRestore *, int))this->IsXSave)(a1: this, a2) != 0 )
    {
      pDest[0] = 0;
      if ( i == 1 )
      {
        v16 = 260 - _V_strlen(str: pDest);
        v10 = _V_strlen(str: pDest);
        V_snprintf(pDest: &pDest[v10], maxLen: v16, pFormat: "//mod/%s.%s", pName, "sav");
      }
      else
      {
        v14 = 260 - _V_strlen(str: pDest);
        v11 = _V_strlen(str: pDest);
        V_snprintf(pDest: &pDest[v11], maxLen: v14, pFormat: "//mod/%s%02d.%s", pName, i - 1, "sav");
      }
      str[0] = 0;
      v15 = 260 - _V_strlen(str);
      v12 = _V_strlen(str);
      V_snprintf(pDest: &str[v12], maxLen: v15, pFormat: "//mod/%s%02d.%s", pName, i, "sav");
    }
    else
    {
      if ( i == 1 )
      {
        v7 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, const char *))this->GetSaveDir)(
                             a1: this,
                             a2: pName,
                             a3: "sav");
        V_snprintf(pDest, maxLen: 260, pFormat: "//%s/%s%s.%s", "MOD", v7, v19, v23);
      }
      else
      {
        v8 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, int, const char *))this->GetSaveDir)(
                             a1: this,
                             a2: pName,
                             a3: i - 1,
                             a4: "sav");
        V_snprintf(pDest, maxLen: 260, pFormat: "//%s/%s%s%02d.%s", "MOD", v8, v17, v20, v24);
      }
      v9 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, int, const char *))this->GetSaveDir)(
                           a1: this,
                           a2: pName,
                           a3: i,
                           a4: "sav");
      V_snprintf(pDest: str, maxLen: 260, pFormat: "//%s/%s%s%02d.%s", "MOD", v9, v18, v21, v25);
    }
    a2 = 0;
    if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))g_pFileSystem->FileExists)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: pDest) != 0 )
    {
      if ( save_history_count.m_pParent != nullptr )
        m_nValue = save_history_count.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( i == m_nValue && g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: str, a3: nullptr) )
        g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: str, a3: nullptr);
      g_pFileSystem->RenameFile(this: g_pFileSystem, a2: pDest, a3: str, a4: nullptr);
    }
    CSaveRestore::AgeSaveFile(this, pName, ext: "tga", count: i, bIsXSave);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101911F0
// Name: private: void CSaveRestore::DirectoryCopy(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::DirectoryCopy(
        CSaveRestore *this,
        const char *pPath,
        const char *pDestFileName,
        BOOL bIsXSave)
{
  const char *v4; // ebx
  const char *v5; // eax
  const char *v6; // edi
  void *v7; // esi

  v4 = pPath;
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Directory copy (%s)\n", pPath);
  g_pSaveRestoreFileSystem->AsyncFinishAllWrites(this: g_pSaveRestoreFileSystem);
  v5 = (const char *)g_pSaveRestoreFileSystem->DirectoryCount(this: g_pSaveRestoreFileSystem, a2: v4);
  v6 = pDestFileName;
  pPath = v5;
  v7 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: pDestFileName, a3: "ab+", a4: nullptr);
  if ( v7 != nullptr )
  {
    g_pSaveRestoreFileSystem->Write(this: g_pSaveRestoreFileSystem, a2: &pPath, a3: 4, a4: v7);
    g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v7);
    g_pSaveRestoreFileSystem->DirectoryCopy(this: g_pSaveRestoreFileSystem, a2: v4, a3: v6, a4: bIsXSave);
  }
  else
  {
    _Warning(a1: "Invalid save, failed to open file\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101912B0
// Name: void Host_Loadgame_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Loadgame_f(int a1@<edi>, const CCommand *args)
{
  bool bLetToolsOverrideLoadGameEnts; // [esp+0h] [ebp-4h]

  if ( cmd_source == src_command )
  {
    if ( sv.m_nMaxclients <= 1
      || save_multiplayer_override.m_pParent != nullptr && save_multiplayer_override.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
      {
        if ( args->m_nArgc >= 2 )
        {
          g_szMapLoadOverride[0] = 0;
          bLetToolsOverrideLoadGameEnts = false;
          if ( args->m_nArgc > 2 )
          {
            V_strncpy(pDest: g_szMapLoadOverride, pSrc: args->m_ppArgv[2], maxLen: 32);
            if ( g_szMapLoadOverride[0] == 42
              && args->m_nArgc > 3
              && _V_stricmp(s1: args->m_ppArgv[3], s2: "LetToolsOverrideLoadGameEnts") == 0 )
            {
              g_szMapLoadOverride[0] = 0;
              bLetToolsOverrideLoadGameEnts = true;
            }
          }
          saverestore->SetIsXSave(this: saverestore, a2: false);
          SetLoadLaunchOptions();
          if ( args->m_nArgc > 1 )
            LoadSaveGame(savename: args->m_ppArgv[1], a2: a1, bLetToolsOverrideLoadGameEnts);
          else
            LoadSaveGame(savename: defaultValue, a2: a1, bLetToolsOverrideLoadGameEnts);
        }
        else
        {
          ConMsg(a1: "load <savename>: load a game\n");
        }
      }
      else
      {
        ConMsg(a1: "This game doesn't support save/restore.");
      }
    }
    else
    {
      ConMsg(a1: "Can't load in multiplayer games.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101913D0
// Name: xload
// Source: json
//------------------------------------------------------------------------------
void __usercall xload(int a1@<edi>, const CCommand *args)
{
  if ( sv.m_nMaxclients <= 1
    || save_multiplayer_override.m_pParent != nullptr && save_multiplayer_override.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
    {
      if ( args->m_nArgc == 2 )
      {
        saverestore->SetIsXSave(this: saverestore, a2: false);
        SetLoadLaunchOptions();
        if ( args->m_nArgc > 1 )
          LoadSaveGame(savename: args->m_ppArgv[1], a2: a1, bLetToolsOverrideLoadGameEnts: false);
        else
          LoadSaveGame(savename: defaultValue, a2: a1, bLetToolsOverrideLoadGameEnts: false);
      }
      else
      {
        ConMsg(a1: "xload <savename>\n");
      }
    }
    else
    {
      ConMsg(a1: "This game doesn't support save/restore.");
    }
  }
  else
  {
    ConMsg(a1: "Can't load in multiplayer games.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191480
// Name: public: virtual bool CSaveRestore::IsSaveInProgress(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::IsSaveInProgress(CSaveRestore *this)
{
  return g_bSaveInProgress.m_value != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10191490
// Name: public: virtual bool CSaveRestore::IsAutoSaveDangerousInProgress(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSaveRestore::IsAutoSaveDangerousInProgress(CSaveRestore *this)
{
  return g_bAutoSaveDangerousInProgress.m_value != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101914A0
// Name: class CSaveMemory __near & GetSaveMemory(void)
// Source: json
//------------------------------------------------------------------------------
CSaveMemory *__cdecl GetSaveMemory()
{
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  return &g_SaveMemory;
}

//------------------------------------------------------------------------------
// Address: 0x101914F0
// Name: void __near * SaveAllocMemory(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl SaveAllocMemory(unsigned int num, unsigned int size, bool bClear)
{
  unsigned int m_alignment; // ecx
  unsigned int v4; // esi
  unsigned __int8 *v5; // edi
  unsigned __int8 *m_pNextAlloc; // ebx

  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  ++g_SaveMemory.m_nSaveAllocs;
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  m_alignment = size * num;
  if ( size * num <= g_SaveMemory.m_alignment )
    m_alignment = g_SaveMemory.m_alignment;
  v4 = ~(g_SaveMemory.m_alignment - 1) & (g_SaveMemory.m_alignment + m_alignment - 1);
  v5 = &g_SaveMemory.m_pNextAlloc[v4];
  m_pNextAlloc = g_SaveMemory.m_pNextAlloc;
  if ( &g_SaveMemory.m_pNextAlloc[v4] > g_SaveMemory.m_pCommitLimit
    && CMemoryStack::CommitTo(this: &g_SaveMemory, pNextAlloc: &g_SaveMemory.m_pNextAlloc[v4]) == 0 )
  {
    return nullptr;
  }
  if ( bClear )
    memset(dst: m_pNextAlloc, value: 0, count: v4);
  g_SaveMemory.m_pNextAlloc = v5;
  return m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x101915F0
// Name: void SaveFreeMemory(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveFreeMemory()
{
  CSaveMemory *SaveMemory; // eax

  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  --g_SaveMemory.m_nSaveAllocs;
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  if ( g_SaveMemory.m_nSaveAllocs == 0 )
  {
    SaveMemory = GetSaveMemory();
    CMemoryStack::FreeAll(this: SaveMemory, bDecommit: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101916A0
// Name: void SaveResetMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveResetMemory()
{
  CSaveMemory *SaveMemory; // eax
  int m_nSaveAllocs; // [esp-8h] [ebp-10h]
  int v2; // [esp+4h] [ebp-4h]

  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  if ( g_SaveMemory.m_pNextAlloc != g_SaveMemory.m_pBase )
  {
    SaveMemory = GetSaveMemory();
    v2 = SaveMemory->m_pNextAlloc - SaveMemory->m_pBase;
    m_nSaveAllocs = GetSaveMemory()->m_nSaveAllocs;
    _Msg(
      a1: "\n\n !!!! SAVEGAME: !!!! %3.1fMB(%d) remain in SaveResetMemory\n\n\n",
      (double)(unsigned int)v2 * 0.00000095367432,
      m_nSaveAllocs);
  }
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  g_SaveMemory.m_nSaveAllocs = 0;
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  CMemoryStack::FreeAll(this: &g_SaveMemory, bDecommit: true);
}

//------------------------------------------------------------------------------
// Address: 0x101917E0
// Name: public: virtual int CSaveRestore::IsValidSave(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::IsValidSave(CSaveRestore *this)
{
  IClient *v2; // ecx
  CPlayerState *v3; // eax

  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    return 0;
  if ( sv.m_State < ss_active )
  {
    ConMsg(a1: "Not playing a local game.\n");
    return 0;
  }
  if ( GetBaseLocalClient()->m_nSignonState != 6 )
  {
    ConMsg(a1: "Can't save if not active.\n");
    return 0;
  }
  if ( sv.m_nMaxclients > 1
    && (save_multiplayer_override.m_pParent == nullptr || save_multiplayer_override.m_pParent->m_Value.m_nValue == 0) )
  {
    ConMsg(a1: "Can't save multiplayer games.\n");
    return 0;
  }
  if ( sv.m_Clients.m_Size <= 0 )
    return 1;
  v2 = *sv.m_Clients.m_Memory.m_pMemory != nullptr ? &(*sv.m_Clients.m_Memory.m_pMemory)->IClient : nullptr;
  if ( !v2->IsActive(this: v2) )
    return 1;
  v3 = serverGameClients->GetPlayerState(
         this: serverGameClients,
         a2: *(_DWORD *)(*sv.m_Clients.m_Memory.m_pMemory)[1].m_GUID);
  if ( v3 == nullptr )
  {
    ConMsg(a1: "Can't savegame without a player!\n");
    return 0;
  }
  if ( !v3->deadflag.m_Value || bugreporter->IsVisible(this: bugreporter) )
    return 1;
  ConMsg(a1: "Can't savegame with a dead player\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101918E0
// Name: public: virtual void CSaveRestore::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::Init(CSaveRestore *this)
{
  CSaveRestore *v1; // esi
  int v2; // eax
  ThreadPoolStartParams_t threadPoolStartParams; // [esp+8h] [ebp-124h] BYREF
  int dummy2; // [esp+11Ch] [ebp-10h] BYREF
  CSaveRestore *v5; // [esp+120h] [ebp-Ch]
  int dummy; // [esp+124h] [ebp-8h] BYREF
  int minplayers; // [esp+128h] [ebp-4h] BYREF

  v1 = this;
  v5 = this;
  minplayers = 1;
  if ( serverGameClients == nullptr
    || (dummy = 1,
        dummy2 = 1,
        serverGameClients->GetPlayerLimits(this: serverGameClients, a2: &minplayers, a3: &dummy, a4: &dummy2),
        serverGameClients == nullptr)
    || minplayers == 1 )
  {
    if ( (_S3_5 & 1) == 0 )
    {
      _S3_5 |= 1u;
      CMemoryStack::CMemoryStack(this: &g_SaveMemory);
      CMemoryStack::Init(
        this: &g_SaveMemory,
        pszAllocOwner: "g_SaveMemory",
        maxSize: 0x2000000u,
        commitSize: 0x10000u,
        initialCommit: 0,
        alignment: 0x10u);
      atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
    }
    threadPoolStartParams.nStackSize = -1;
    threadPoolStartParams.iThreadPriority = -32768;
    *((_BYTE *)&threadPoolStartParams + 272) &= 0xFCu;
    if ( (*((_BYTE *)&threadPoolStartParams + 272) & 2) != 0 )
    {
      qmemcpy(threadPoolStartParams.iAffinityTable, nullptr, sizeof(threadPoolStartParams.iAffinityTable));
      v1 = v5;
    }
    threadPoolStartParams.nThreads = 1;
    threadPoolStartParams.fDistribute = TRS_FALSE;
    g_pSaveThread = (IThreadPool *)_CreateNewThreadPool();
    g_pSaveThread->Start(this: g_pSaveThread, a2: &threadPoolStartParams, a3: "SaveJob");
  }
  v1->m_nDeferredCommandFrames = 0;
  v1->m_szSaveGameScreenshotFile[0] = 0;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noclearsave") == 0 )
    v1->ClearSaveDir(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10191A10
// Name: public: virtual void CMemberFunctor1<class CSaveRestore __near *,void (CSaveRestore::*)(bool),bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CSaveRestore *,void (__thiscall CSaveRestore::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CSaveRestore *,void (__thiscall CSaveRestore::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10191A20
// Name: public: virtual void CMemberFunctor0<class IFileSystem __near *,void (IFileSystem::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<IFileSystem *,void (__thiscall IFileSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<IFileSystem *,void (__thiscall IFileSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + HIDWORD(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x10191A30
// Name: public: virtual void CMemberFunctor1<class IXboxSystem __near *,void (IXboxSystem::*)(int),int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<IXboxSystem *,void (__thiscall IXboxSystem::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<IXboxSystem *,void (__thiscall IXboxSystem::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x101920E0
// Name: private: void CSaveRestore::ReapplyDecal(bool,struct CSaveRestore::RestoreLookupTable __near *,struct decallist_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CSaveRestore::ReapplyDecal(
        CSaveRestore *this@<ecx>,
        CTraceFilterHitAll_vtbl *a2@<ebp>,
        bool adjacent,
        CSaveRestore::RestoreLookupTable *table,
        decallist_t *entry)
{
  decallist_t *v5; // edi
  float x; // ecx
  int z_low; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  const edict_t *Edict; // eax
  int v13; // eax
  IClientEntity *v14; // esi
  char *name; // edi
  CVEfx_vtbl *v16; // edi
  IClientEntity_vtbl *v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  __int16 entityIndex; // cx
  int m_Size; // esi
  int v23; // eax
  int v24; // edi
  CSaveRestore::SaveRestoreTranslate *m_pMemory; // ecx
  float v26; // esi
  IClientEntity *v27; // eax
  model_t *Model; // eax
  edict_t *v29; // eax
  IServerUnknown *m_pUnk; // ecx
  int v31; // eax
  char *v32; // edi
  int v33; // esi
  _BYTE v34[12]; // [esp-Ch] [ebp-F4h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-E8h] BYREF
  float v36; // [esp+54h] [ebp-94h]
  Ray_t ray; // [esp+58h] [ebp-90h] BYREF
  _BYTE v38[12]; // [esp+A8h] [ebp-40h] BYREF
  Vector vecOrigin; // [esp+B4h] [ebp-34h]
  int v40; // [esp+C0h] [ebp-28h]
  float oldlock; // [esp+C4h] [ebp-24h] OVERLAPPED BYREF
  int entityToHit; // [esp+C8h] [ebp-20h]
  int flags; // [esp+CCh] [ebp-1Ch]
  QAngle vecAngle; // [esp+D0h] [ebp-18h] BYREF
  CTraceFilterHitAll traceFilter; // [esp+DCh] [ebp-Ch]
  const model_t *pModel; // [esp+E0h] [ebp-8h]
  _BYTE v47[3]; // [esp+E4h] [ebp-4h] BYREF
  const model_t *retaddr; // [esp+E8h] [ebp+0h]

  traceFilter.__vftable = a2;
  pModel = retaddr;
  v5 = entry;
  v40 = entry->flags;
  if ( adjacent )
    v40 |= 0x800u;
  LOBYTE(vecOrigin.y) = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  if ( adjacent )
  {
    x = entry->position.x;
    z_low = SLODWORD(entry->position.z);
    v8 = entry->impactPlaneNormal.x * 5.0;
    v9 = entry->impactPlaneNormal.y * 5.0;
    v10 = entry->impactPlaneNormal.z * 5.0;
    v11 = v8 + entry->position.x;
    entityToHit = SLODWORD(entry->position.y);
    oldlock = x;
    flags = z_low;
    ray.m_Start.y = (float)(x - v8) - v11;
    ray.m_Start.z = (float)(*(float *)&entityToHit - v9) - (float)(v9 + *(float *)&entityToHit);
    ray.m_Start.w = (float)(*(float *)&z_low - v10) - (float)(v10 + *(float *)&z_low);
    vecAngle.y = (float)((float)(ray.m_Start.y * ray.m_Start.y) + (float)(ray.m_Start.z * ray.m_Start.z))
               + (float)(ray.m_Start.w * ray.m_Start.w);
    LODWORD(vecAngle.x) = &CTraceFilterHitAll::`vftable';
    BYTE1(ray.m_Extents.z) = vecAngle.y != 0.0;
    memset(&ray.m_StartOffset.y, 0, 12);
    ray.m_Extents.y = 0.0;
    LOBYTE(ray.m_Extents.z) = 1;
    memset(&ray.m_Delta.y, 0, 12);
    *(float *)&tr.m_pEnt = v11;
    *(float *)&tr.hitbox = v9 + *(float *)&entityToHit;
    v36 = v10 + *(float *)&z_low;
    g_pEngineTraceServer->TraceRay(
      this: g_pEngineTraceServer,
      a2: (const Ray_t *)&tr.m_pEnt,
      a3: 16513u,
      a4: (ITraceFilter *)&vecAngle,
      a5: (CGameTrace *)v34);
    if ( tr.plane.normal.z != 1.0
      && tr.plane.pad[0] == 0
      && entry->impactPlaneNormal.x * tr.endpos.x
       + entry->impactPlaneNormal.y * tr.endpos.y
       + tr.endpos.z * entry->impactPlaneNormal.z >= 0.99 )
    {
      Edict = CGameTrace::GetEdict(this: (CGameTrace *)v34);
      if ( Edict != nullptr )
      {
        v13 = NUM_FOR_EDICTINFO(e: Edict);
        LODWORD(vecOrigin.z) = v13;
        if ( v13 >= 0 )
        {
          v14 = entitylist->GetClientEntity(this: entitylist, a2: v13);
          if ( v14 == nullptr )
            return;
          name = entry->name;
          HIBYTE(vecAngle.z) = 0;
          LODWORD(vecAngle.y) = Draw_DecalIndexFromName(name: entry->name, found: (bool *)&vecAngle.z + 3);
          if ( HIBYTE(vecAngle.z) == 0 )
          {
            LODWORD(vecAngle.y) = CGameServer::PrecacheDecal(this: &sv, a2: (int)v47, a3: (int)v14, name, flags: 1);
            Draw_DecalSetName(decal: SLODWORD(vecAngle.y), name);
          }
          v16 = g_pEfx->__vftable;
          v17 = v14->IClientUnknown::IHandleEntity::__vftable;
          LODWORD(vecOrigin.x) = &v14->IClientRenderable;
          v18 = ((int (__thiscall *)(IClientEntity *, decallist_t *, _DWORD, int, Vector *))v17->GetAbsAngles)(
                  a1: v14,
                  a2: entry,
                  a3: 0,
                  a4: v40,
                  a5: &tr.endpos);
          v19 = ((int (__thiscall *)(IClientEntity *, int))v14->GetAbsOrigin)(a1: v14, a2: v18);
          v20 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)LODWORD(vecOrigin.x) + 32))(
                  a1: LODWORD(vecOrigin.x),
                  a2: v19);
          ((void (__thiscall *)(CVEfx *, _DWORD, _DWORD, int))v16->DecalShoot)(
            a1: g_pEfx,
            a2: LODWORD(vecAngle.y),
            a3: LODWORD(vecOrigin.z),
            a4: v20);
        }
      }
    }
    goto LABEL_34;
  }
  entityIndex = entry->entityIndex;
  if ( entityIndex == 0 )
  {
    vecAngle.x = 0.0;
    goto LABEL_22;
  }
  m_Size = table->lookup.m_Size;
  v23 = 0;
  if ( m_Size <= 0 )
  {
LABEL_19:
    vecAngle.x = NAN;
LABEL_22:
    v26 = vecAngle.x;
    goto LABEL_23;
  }
  v24 = entityIndex;
  m_pMemory = table->lookup.m_Memory.m_pMemory;
  while ( m_pMemory->savedindex != v24 )
  {
    ++v23;
    ++m_pMemory;
    if ( v23 >= m_Size )
    {
      v5 = entry;
      goto LABEL_19;
    }
  }
  v26 = *(float *)&m_pMemory->restoredindex;
  v5 = entry;
  vecAngle.x = v26;
LABEL_23:
  if ( v26 >= 0.0 )
  {
    memset(v38, 0, sizeof(v38));
    oldlock = 0.0;
    *(float *)&entityToHit = 0.0;
    flags = 0;
    v27 = entitylist->GetClientEntity(this: entitylist, a2: LODWORD(v26));
    if ( v27 != nullptr )
    {
      Model = (model_t *)v27->GetModel(this: &v27->IClientRenderable);
    }
    else
    {
      v29 = EDICT_NUM(n: SLODWORD(v26));
      if ( v29 == nullptr )
        goto LABEL_34;
      if ( (v29->m_fStateFlags & 4) == 0 )
        goto LABEL_34;
      m_pUnk = v29->m_pUnk;
      if ( m_pUnk == nullptr )
        goto LABEL_34;
      v31 = ((int (__thiscall *)(IServerUnknown *))m_pUnk->__vftable[1].dtr_IHandleEntity)(a1: m_pUnk);
      Model = CGameServer::GetModel(this: &sv, a2: (int)v47, index: v31);
    }
    LODWORD(vecAngle.y) = Model;
    if ( Model != nullptr )
    {
      v32 = v5->name;
      HIBYTE(vecAngle.z) = 0;
      v33 = Draw_DecalIndexFromName(name: v32, found: (bool *)&vecAngle.z + 3);
      if ( HIBYTE(vecAngle.z) == 0 )
      {
        v33 = CGameServer::PrecacheDecal(this: &sv, a2: (int)v47, a3: v33, name: v32, flags: 1);
        Draw_DecalSetName(decal: v33, name: v32);
      }
      g_pEfx->DecalShoot(
        this: g_pEfx,
        a2: v33,
        a3: LODWORD(vecAngle.x),
        a4: (const model_t *)LODWORD(vecAngle.y),
        a5: (const Vector *)v38,
        a6: (const QAngle *)&oldlock,
        a7: (const Vector *)entry,
        a8: nullptr,
        a9: v40,
        a10: nullptr);
    }
  }
LABEL_34:
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: SLODWORD(vecOrigin.y));
}

//------------------------------------------------------------------------------
// Address: 0x10192C60
// Name: public: virtual void CSaveRestore::OnFrameRendered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::OnFrameRendered(CSaveRestore *this)
{
  int m_nDeferredCommandFrames; // eax
  int v3; // eax
  int i; // edi
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  bool v7; // sf
  const char *v8; // [esp-Ch] [ebp-10h]

  m_nDeferredCommandFrames = this->m_nDeferredCommandFrames;
  if ( m_nDeferredCommandFrames > 0 )
  {
    v3 = m_nDeferredCommandFrames - 1;
    this->m_nDeferredCommandFrames = v3;
    if ( v3 == 0 )
    {
      for ( i = 0; i < this->m_sDeferredCommands.m_Size; ++i )
      {
        v8 = CUtlSymbol::String(this: &this->m_sDeferredCommands.m_Memory.m_pMemory[i]);
        TraceType = CTraceFilter::GetTraceType(this: v5);
        Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
      }
      v7 = this->m_sDeferredCommands.m_Memory.m_nGrowSize < 0;
      this->m_sDeferredCommands.m_Size = 0;
      if ( !v7 )
      {
        if ( this->m_sDeferredCommands.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sDeferredCommands.m_Memory.m_pMemory);
          this->m_sDeferredCommands.m_Memory.m_pMemory = nullptr;
        }
        this->m_sDeferredCommands.m_Memory.m_nAllocationCount = 0;
      }
      this->m_sDeferredCommands.m_pElements = this->m_sDeferredCommands.m_Memory.m_pMemory;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192D10
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueCall<class CSaveRestore __near *,class CSaveRestore,void,bool,bool>(class CSaveRestore __near *,void (CSaveRestore::*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CSaveRestore *,CSaveRestore,void,bool,bool>(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CSaveRestore *pObject,
        void (__thiscall *pfnProxied)(CSaveRestore *this, bool),
        const bool *arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CSaveRestore *,void (__thiscall CSaveRestore::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CSaveRestore *,void (__thiscall CSaveRestore::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    LOBYTE(v5[3].__vftable) = *arg1;
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: v5);
  }
  else
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192D70
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueCall<class IXboxSystem __near *,class IXboxSystem,void,int,int>(class IXboxSystem __near *,void (IXboxSystem::*)(int),int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<IXboxSystem *,IXboxSystem,void,int,int>(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        IXboxSystem *pObject,
        void (__thiscall *pfnProxied)(IXboxSystem *this, int),
        CFunctor_vtbl **arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<IXboxSystem *,void (__thiscall IXboxSystem::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<IXboxSystem *,void (__thiscall IXboxSystem::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    v5[3].__vftable = *arg1;
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: v5);
  }
  else
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192DD0
// Name: public: class CJob __near * IThreadPool::QueueCall<class CSaveRestore,class CSaveRestore,void>(class CSaveRestore __near *,void (CSaveRestore::*)(void))
// Source: json
//------------------------------------------------------------------------------
CJob *__thiscall IThreadPool::QueueCall<CSaveRestore,CSaveRestore,void>(
        IThreadPool *this,
        CSaveRestore *pObject,
        void (__thiscall *pfnProxied)(CSaveRestore *this))
{
  CFunctor *v4; // eax
  CJob *pJob; // [esp+4h] [ebp-4h] BYREF

  v4 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CSaveRestore *,void (__thiscall CSaveRestore::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CSaveRestore *,void (__thiscall CSaveRestore::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4[2].m_nUserID = (unsigned int)pObject;
  }
  else
  {
    v4 = nullptr;
  }
  this->AddFunctorInternal(this, a2: v4, a3: &pJob, a4: nullptr, a5: 8u);
  return pJob;
}

//------------------------------------------------------------------------------
// Address: 0x10192E30
// Name: public: virtual void CMemberFunctor3<class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,int,bool),class CUtlEnvelope<char const __near *>,int,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,int,bool),CUtlEnvelope<char const *>,int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,int,bool),CUtlEnvelope<char const *>,int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  const char *v2; // eax

  v2 = CUtlString::operator char const *(this: &this->m_arg1.m_string);
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: v2, a3: this->m_arg2, a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x10192E60
// Name: public: virtual void CMemberFunctor3<class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  const char *v2; // edi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: &this->m_arg2.m_string);
  v3 = CUtlString::operator char const *(this: &this->m_arg1.m_string);
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: v3, a3: v2, a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x10192E90
// Name: public: virtual CMemberFunctor3<class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::~CMemberFunctor3<class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::~CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_arg2.m_string.m_Storage.m_nActualLength = 0;
  if ( this->m_arg2.m_string.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory);
      this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_arg2.m_string.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_arg1.m_string.m_Storage.m_nActualLength = 0;
  if ( this->m_arg1.m_string.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory);
      this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_arg1.m_string.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CFunctor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10192EF0
// Name: public: virtual void CFunctor1<void (*)(char const __near *),class CUtlEnvelope<char const __near *>,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor1<void (__cdecl *)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor1<void (__cdecl*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  const char *v2; // eax

  v2 = CUtlString::Get(this: &this->m_arg1.m_string);
  this->m_pfnProxied(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10192F30
// Name: public: virtual void CMemberFunctor6<class ISaveRestoreFileSystem __near *,enum FSAsyncStatus_t (ISaveRestoreFileSystem::*)(char const __near *,void const __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *),class CUtlEnvelope<char const __near *>,void __near *,int,bool,bool,struct FSAsyncControl_t__ __near * __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,unsigned int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  const char *v2; // eax

  v2 = CUtlString::operator char const *(this: &this->m_arg1.m_string);
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: v2,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5,
    a7: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x101930C0
// Name: public: CSaveRestore::RestoreLookupTable::RestoreLookupTable(struct CSaveRestore::RestoreLookupTable const __near &)
// Source: json
//------------------------------------------------------------------------------
CSaveRestore::RestoreLookupTable *__thiscall CSaveRestore::RestoreLookupTable::RestoreLookupTable(
        CSaveRestore::RestoreLookupTable *this,
        const CSaveRestore::RestoreLookupTable *src)
{
  const CSaveRestore::RestoreLookupTable *v2; // edx
  int v4; // edi
  int m_nAllocationCount; // eax
  CSaveRestore::SaveRestoreTranslate *v6; // ebx
  CSaveRestore::SaveRestoreTranslate *m_pMemory; // ecx
  int v8; // eax
  CSaveRestore::SaveRestoreTranslate *v9; // eax
  int m_Size; // [esp+4h] [ebp-8h]
  int v12; // [esp+8h] [ebp-4h]

  v2 = src;
  this->lookup.m_Memory.m_pMemory = nullptr;
  this->lookup.m_Memory.m_nAllocationCount = 0;
  this->lookup.m_Memory.m_nGrowSize = 0;
  this->lookup.m_Size = 0;
  this->lookup.m_pElements = nullptr;
  if ( src->lookup.m_Size > 0 )
  {
    v12 = 0;
    m_Size = src->lookup.m_Size;
    do
    {
      v4 = this->lookup.m_Size;
      m_nAllocationCount = this->lookup.m_Memory.m_nAllocationCount;
      v6 = &v2->lookup.m_Memory.m_pMemory[v12];
      if ( v4 + 1 > m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
          num: v4 - m_nAllocationCount + 1);
        v2 = src;
      }
      ++this->lookup.m_Size;
      m_pMemory = this->lookup.m_Memory.m_pMemory;
      v8 = this->lookup.m_Size - v4 - 1;
      this->lookup.m_pElements = this->lookup.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v4 + 1], src: &m_pMemory[v4], count: 12 * v8);
        v2 = src;
      }
      v9 = &this->lookup.m_Memory.m_pMemory[v4];
      if ( v9 != nullptr )
      {
        v9->classname.pszValue = v6->classname.pszValue;
        v9->savedindex = v6->savedindex;
        v9->restoredindex = v6->restoredindex;
      }
      ++v12;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  this->m_vecLandMarkOffset.x = v2->m_vecLandMarkOffset.x;
  this->m_vecLandMarkOffset.y = v2->m_vecLandMarkOffset.y;
  this->m_vecLandMarkOffset.z = v2->m_vecLandMarkOffset.z;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10193190
// Name: void FinishAsyncSave(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FinishAsyncSave()
{
  DWORD CurrentThreadId; // ecx
  unsigned __int8 v1; // al
  DWORD v2; // [esp-8h] [ebp-Ch]

  if ( (_S2_14 & 1) == 0 )
  {
    _S2_14 |= 1u;
    autoMutex___0.m_ownerID = 0;
    autoMutex___0.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex___0.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex___0, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex___0, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex___0.m_depth;
  }
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = GetCurrentThreadId();
    v1 = _ThreadInMainThread();
    _Msg(a1: "FinishAsyncSave() (%d/%d)\n", v1, v2);
  }
  if ( g_AsyncSaveCallQueue.m_queue.m_Count.m_value != 0 )
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_AsyncSaveCallQueue);
    g_pFileSystem->AsyncFinishAllWrites(this: g_pFileSystem);
  }
  g_SaveRestore.m_MostRecentSaveInfo.m_bValid = false;
  _InterlockedExchange(&g_bAutoSaveDangerousInProgress.m_value, 0);
  _InterlockedExchange(&g_bSaveInProgress.m_value, 0);
  if ( --autoMutex___0.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&autoMutex___0, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10193290
// Name: void DispatchAsyncSave(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchAsyncSave()
{
  BOOL v0; // eax
  ISaveRestore *v1; // esi
  IThreadPool *v2; // edi
  CFunctor *v3; // eax
  CJob *v4; // [esp+0h] [ebp-4h] BYREF

  _InterlockedExchange(&g_bSaveInProgress.m_value, 1);
  v0 = g_SaveRestore.m_MostRecentSaveInfo.m_bValid
    && V_stristr(pStr: g_SaveRestore.m_MostRecentSaveInfo.m_MostRecentSavePath, pSearch: "autosavedangerous") != nullptr;
  _InterlockedExchange(&g_bAutoSaveDangerousInProgress.m_value, v0);
  if ( save_async.m_pParent != nullptr && save_async.m_pParent->m_Value.m_nValue != 0 )
  {
    v1 = saverestore;
    v2 = g_pSaveThread;
    v3 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v3 != nullptr )
    {
      v3[1].m_nUserID = 1;
      v3->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<ISaveRestore *,void (__thiscall ISaveRestore::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v3[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<ISaveRestore *,void (__thiscall ISaveRestore::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v3[2].__vftable = (CFunctor_vtbl *) __thiscall ISaveRestore::`vcall'{128,{flat}};
      v3[2].m_nUserID = (unsigned int)v1;
    }
    else
    {
      v3 = nullptr;
    }
    v2->AddFunctorInternal(this: v2, a2: v3, a3: &v4, a4: nullptr, a5: 8u);
  }
  else
  {
    saverestore->FinishAsyncSave(this: saverestore);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193360
// Name: struct datamap_t __near * DataMapInit<struct GAME_HEADER>(struct GAME_HEADER __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<GAME_HEADER>()
{
  if ( (_S4_2 & 1) == 0 )
  {
    _S4_2 |= 1u;
    nameHolder_2.m_pszBase = "GAME_HEADER";
    nameHolder_2.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_2.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_2.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_2.m_Names.m_Size = 0;
    nameHolder_2.m_Names.m_pElements = nullptr;
    nameHolder_2.m_nLenBase = 11;
    atexit(func: DataMapInit_GAME_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  GAME_HEADER::m_DataMap.baseMap = nullptr;
  GAME_HEADER::m_DataMap.dataNumFields = 5;
  GAME_HEADER::m_DataMap.dataDesc = &dataDesc_2[1];
  return &GAME_HEADER::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101933E0
// Name: struct datamap_t __near * DataMapInit<struct SAVE_HEADER>(struct SAVE_HEADER __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SAVE_HEADER>()
{
  if ( (_S5_2 & 1) == 0 )
  {
    _S5_2 |= 1u;
    nameHolder_3.m_pszBase = "SAVE_HEADER";
    nameHolder_3.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_3.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_3.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_3.m_Names.m_Size = 0;
    nameHolder_3.m_Names.m_pElements = nullptr;
    nameHolder_3.m_nLenBase = 11;
    atexit(func: DataMapInit_SAVE_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SAVE_HEADER::m_DataMap.baseMap = nullptr;
  SAVE_HEADER::m_DataMap.dataNumFields = 7;
  SAVE_HEADER::m_DataMap.dataDesc = &dataDesc_3[1];
  return &SAVE_HEADER::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193460
// Name: struct datamap_t __near * DataMapInit<struct levellist_t>(struct levellist_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<levellist_t>()
{
  if ( (_S6_1 & 1) == 0 )
  {
    _S6_1 |= 1u;
    nameHolder_4.m_pszBase = "levellist_t";
    nameHolder_4.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_4.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_4.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_4.m_Names.m_Size = 0;
    nameHolder_4.m_Names.m_pElements = nullptr;
    nameHolder_4.m_nLenBase = 11;
    atexit(func: DataMapInit_levellist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  levellist_t::m_DataMap.baseMap = nullptr;
  levellist_t::m_DataMap.dataNumFields = 4;
  levellist_t::m_DataMap.dataDesc = &dataDesc_4[1];
  return &levellist_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101934E0
// Name: struct datamap_t __near * DataMapInit<struct SAVELIGHTSTYLE>(struct SAVELIGHTSTYLE __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SAVELIGHTSTYLE>()
{
  if ( (_S7_1 & 1) == 0 )
  {
    _S7_1 |= 1u;
    nameHolder_5.m_pszBase = "SAVELIGHTSTYLE";
    nameHolder_5.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_5.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_5.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_5.m_Names.m_Size = 0;
    nameHolder_5.m_Names.m_pElements = nullptr;
    nameHolder_5.m_nLenBase = 14;
    atexit(func: DataMapInit_SAVELIGHTSTYLE__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SAVELIGHTSTYLE::m_DataMap.baseMap = nullptr;
  SAVELIGHTSTYLE::m_DataMap.dataNumFields = 2;
  SAVELIGHTSTYLE::m_DataMap.dataDesc = &dataDesc_5[1];
  return &SAVELIGHTSTYLE::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193560
// Name: public: virtual void CSaveRestore::UpdateSaveGameScreenshots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::UpdateSaveGameScreenshots(CSaveRestore *this)
{
  char *m_szSaveGameScreenshotFile; // esi

  if ( g_LostVideoMemory )
  {
    this->m_szSaveGameScreenshotFile[0] = 0;
  }
  else
  {
    m_szSaveGameScreenshotFile = this->m_szSaveGameScreenshotFile;
    if ( this->m_szSaveGameScreenshotFile[0] != 0 )
    {
      g_ClientGlobalVariables.framecount = ++host_framecount;
      g_ClientDLL->WriteSaveGameScreenshot(this: g_ClientDLL, a2: m_szSaveGameScreenshotFile);
      *m_szSaveGameScreenshotFile = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101935B0
// Name: struct datamap_t __near * DataMapInit<struct musicsave_t>(struct musicsave_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<musicsave_t>()
{
  if ( (_S8_0 & 1) == 0 )
  {
    _S8_0 |= 1u;
    nameHolder_6.m_pszBase = "musicsave_t";
    nameHolder_6.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_6.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_6.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_6.m_Names.m_Size = 0;
    nameHolder_6.m_Names.m_pElements = nullptr;
    nameHolder_6.m_nLenBase = 11;
    atexit(func: DataMapInit_musicsave_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  musicsave_t::m_DataMap.baseMap = nullptr;
  musicsave_t::m_DataMap.dataNumFields = 3;
  musicsave_t::m_DataMap.dataDesc = &dataDesc_6[1];
  return &musicsave_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193630
// Name: struct datamap_t __near * DataMapInit<struct channelsave>(struct channelsave __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<channelsave>()
{
  if ( (_S9 & 1) == 0 )
  {
    _S9 |= 1u;
    nameHolder_7.m_pszBase = "channelsave";
    nameHolder_7.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_7.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_7.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_7.m_Names.m_Size = 0;
    nameHolder_7.m_Names.m_pElements = nullptr;
    nameHolder_7.m_nLenBase = 11;
    atexit(func: DataMapInit_channelsave__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  channelsave::m_DataMap.baseMap = nullptr;
  channelsave::m_DataMap.dataNumFields = 9;
  channelsave::m_DataMap.dataDesc = &dataDesc_7[1];
  return &channelsave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101936B0
// Name: struct datamap_t __near * DataMapInit<struct decallist_t>(struct decallist_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<decallist_t>()
{
  if ( (_S10 & 1) == 0 )
  {
    _S10 |= 1u;
    nameHolder_8.m_pszBase = "decallist_t";
    nameHolder_8.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_8.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_8.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_8.m_Names.m_Size = 0;
    nameHolder_8.m_Names.m_pElements = nullptr;
    nameHolder_8.m_nLenBase = 11;
    atexit(func: DataMapInit_decallist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  decallist_t::m_DataMap.baseMap = nullptr;
  decallist_t::m_DataMap.dataNumFields = 5;
  decallist_t::m_DataMap.dataDesc = &dataDesc_8[1];
  return &decallist_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193730
// Name: public: virtual void CSaveRestore::AutoSaveDangerousIsSafe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::AutoSaveDangerousIsSafe(CSaveRestore *this)
{
  int m_nValue; // edi
  bool v3; // al
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  int v8; // eax
  int v9; // eax
  bool v10; // zf
  void (__thiscall *SetMostRecentSaveGame)(struct CSaveRestore *, const char *); // edx
  int v12; // [esp-Ch] [ebp-21Ch]
  int v13; // [esp-Ch] [ebp-21Ch]
  const char *v14; // [esp-4h] [ebp-214h]
  const char *v15; // [esp-4h] [ebp-214h]
  const char *v16; // [esp-4h] [ebp-214h]
  const char *v17; // [esp-4h] [ebp-214h]
  char szOldName[260]; // [esp+8h] [ebp-208h] BYREF
  char szNewName[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( save_async.m_pParent != nullptr
    && save_async.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread() != 0
    && g_pSaveThread != nullptr )
  {
    IThreadPool::QueueCall<CSaveRestore,CSaveRestore,void>(
      this: g_pSaveThread,
      pObject: this,
      pfnProxied:  __thiscall ISaveRestore::`vcall'{128,{flat}});
    IThreadPool::QueueCall<CSaveRestore,CSaveRestore,void>(
      this: g_pSaveThread,
      pObject: this,
      pfnProxied:  __thiscall CSaveRestore::`vcall'{108,{flat}});
  }
  else if ( this->m_bWaitingForSafeDangerousSave )
  {
    this->m_bWaitingForSafeDangerousSave = false;
    _ConDMsg(a1: "Committing AutoSaveDangerous...\n");
    memset(szOldName, 0, sizeof(szOldName));
    memset(szNewName, 0, sizeof(szNewName));
    if ( this->StorageDeviceValid(this) )
    {
      if ( save_history_count.m_pParent != nullptr )
        m_nValue = save_history_count.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v3 = this->IsXSave(this);
      CSaveRestore::AgeSaveList(this, pName: "autosave", count: m_nValue, bIsXSave: v3);
    }
    v4 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: defaultValue);
    V_snprintf(pDest: szOldName, maxLen: 260, pFormat: "//%s/%sautosavedangerous%s.tga", "MOD", v4, v14);
    v5 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: defaultValue);
    V_snprintf(pDest: szNewName, maxLen: 260, pFormat: "//%s/%sautosave%s.tga", "MOD", v5, v15);
    if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szNewName, a3: nullptr) )
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: szNewName, a3: nullptr);
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szOldName, a3: nullptr)
      || g_pFileSystem->RenameFile(this: g_pFileSystem, a2: szOldName, a3: szNewName, a4: nullptr) )
    {
      if ( this->IsXSave(this) )
      {
        szOldName[0] = 0;
        v12 = 260 - _V_strlen(str: szOldName);
        v8 = _V_strlen(str: szOldName);
        V_snprintf(pDest: &szOldName[v8], maxLen: v12, pFormat: "//mod/autosavedangerous%s.sav", defaultValue);
        szNewName[0] = 0;
        v13 = 260 - _V_strlen(str: szNewName);
        v9 = _V_strlen(str: szNewName);
        V_snprintf(pDest: &szNewName[v9], maxLen: v13, pFormat: "//mod/autosave%s.sav", defaultValue);
      }
      else
      {
        v6 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(
                             a1: this,
                             a2: defaultValue);
        V_snprintf(pDest: szOldName, maxLen: 260, pFormat: "//%s/%sautosavedangerous%s.sav", "MOD", v6, v16);
        v7 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(
                             a1: this,
                             a2: defaultValue);
        V_snprintf(pDest: szNewName, maxLen: 260, pFormat: "//%s/%sautosave%s.sav", "MOD", v7, v17);
      }
      if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szNewName, a3: nullptr) )
        g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: szNewName, a3: nullptr);
      v10 = !g_pFileSystem->RenameFile(this: g_pFileSystem, a2: szOldName, a3: szNewName, a4: nullptr);
      SetMostRecentSaveGame = this->SetMostRecentSaveGame;
      if ( v10 )
      {
        SetMostRecentSaveGame(this, a2: "autosavedangerous");
      }
      else
      {
        SetMostRecentSaveGame(this, a2: "autosave");
        if ( this->IsXSave(this) )
          g_pXboxSystem->FinishContainerWrites(this: g_pXboxSystem, a2: 0);
      }
    }
    else
    {
      this->SetMostRecentSaveGame(this, a2: "autosavedangerous");
    }
  }
  else
  {
    DevMsg(a1: "No AutoSaveDangerous Outstanding...Nothing to do.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193A90
// Name: SaveGame
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveGame(const CCommand *args)
{
  int m_nArgc; // eax
  int v3; // esi
  const char **v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int v9; // edi
  int v10; // eax
  ISaveRestore_vtbl *v11; // edx
  int (__thiscall *GetMostRecentElapsedSeconds)(ISaveRestore *); // eax
  int v13; // eax
  void (__thiscall *GetSaveComment)(IServerGameDLL *, char *, int, float, float, bool); // edx
  const char *v15; // ebx
  float v16; // [esp+4h] [ebp-178h]
  char pDest[12]; // [esp+18h] [ebp-164h] BYREF
  char szMapName[260]; // [esp+24h] [ebp-158h] BYREF
  char comment[80]; // [esp+128h] [ebp-54h]
  float v20; // [esp+178h] [ebp-4h]
  bool bFinishAsync; // [esp+187h] [ebp+Bh]

  m_nArgc = args->m_nArgc;
  HIBYTE(v20) = 0;
  comment[72] = 1;
  bFinishAsync = false;
  if ( m_nArgc > 2 )
  {
    v3 = 2;
    v4 = &args->m_ppArgv[2];
    do
    {
      if ( v3 < 0 || v3 >= m_nArgc )
        v5 = defaultValue;
      else
        v5 = *v4;
      if ( _V_stricmp(s1: v5, s2: "wait") != 0 )
      {
        if ( v3 < 0 || v3 >= args->m_nArgc )
          v6 = defaultValue;
        else
          v6 = *v4;
        if ( _V_stricmp(s1: v6, s2: "notmostrecent") != 0 )
        {
          if ( v3 < 0 || v3 >= args->m_nArgc )
            v7 = defaultValue;
          else
            v7 = *v4;
          if ( _V_stricmp(s1: v7, s2: "copymap") == 0 )
            bFinishAsync = true;
        }
        else
        {
          comment[72] = 0;
        }
      }
      else
      {
        HIBYTE(v20) = 1;
      }
      m_nArgc = args->m_nArgc;
      ++v3;
      ++v4;
    }
    while ( v3 < args->m_nArgc );
    if ( bFinishAsync )
    {
      V_strncpy(pDest, pSrc: sv.m_szMapname, maxLen: 260);
      v8 = defaultValue;
      if ( args->m_nArgc > 1 )
        v8 = args->m_ppArgv[1];
      V_strncpy(pDest: sv.m_szMapname, pSrc: v8, maxLen: 64);
    }
  }
  v9 = (int)(float)(g_ServerGlobalVariables.curtime - (float)saverestore->GetMostRecentElapsedTimeSet(this: saverestore));
  v10 = saverestore->GetMostRecentElapsedMinutes(this: saverestore);
  v11 = saverestore->__vftable;
  *(_DWORD *)&comment[76] = v9 / 60 + v10;
  GetMostRecentElapsedSeconds = v11->GetMostRecentElapsedSeconds;
  *(float *)&comment[68] = (float)*(int *)&comment[76];
  v13 = GetMostRecentElapsedSeconds(this: saverestore);
  GetSaveComment = serverGameDLL->GetSaveComment;
  *(_DWORD *)&comment[76] = v9 % 60 + v13;
  v16 = (float)*(int *)&comment[76];
  ((void (__thiscall *)(IServerGameDLL *, char *, int, _DWORD, _DWORD, _DWORD))GetSaveComment)(
    a1: serverGameDLL,
    a2: &szMapName[248],
    a3: 80,
    a4: *(_DWORD *)&comment[68],
    a5: LODWORD(v16),
    a6: 0);
  if ( args->m_nArgc > 1 )
    v15 = args->m_ppArgv[1];
  else
    v15 = defaultValue;
  saverestore->SaveGameSlot(
    this: saverestore,
    a2: v15,
    a3: &szMapName[248],
    a4: false,
    a5: *(_DWORD *)&comment[72],
    a6: nullptr,
    a7: nullptr);
  if ( HIBYTE(v20) != 0 )
    FinishAsyncSave();
  if ( bFinishAsync )
    V_strncpy(pDest: sv.m_szMapname, pSrc: pDest, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10193C80
// Name: xsave
// Source: json
//------------------------------------------------------------------------------
void __cdecl xsave(const CCommand *args)
{
  char *v1; // eax
  int v2; // eax
  int v3; // eax

  if ( cmd_source == src_command && saverestore->IsValidSave(this: saverestore) != 0 )
  {
    if ( serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
    {
      if ( args->m_nArgc >= 2 )
      {
        v1 = (char *)defaultValue;
        if ( args->m_nArgc > 1 )
          v1 = (char *)args->m_ppArgv[1];
        strstr(str1: (unsigned __int8 *)v1, str2: "..");
        if ( v2 != 0 )
        {
          _ConDMsg(a1: "Relative pathnames are not allowed.\n");
        }
        else
        {
          strstr(str1: (unsigned __int8 *)sv.m_szMapname, str2: "background");
          if ( v3 != 0 )
          {
            _ConDMsg(a1: "\"background\" is a reserved map name and cannot be saved or loaded.\n");
          }
          else
          {
            saverestore->SetIsXSave(this: saverestore, a2: false);
            SaveGame(args);
          }
        }
      }
      else
      {
        _ConDMsg(a1: "save <savename> [wait]: save a game\n");
      }
    }
    else
    {
      ConMsg(a1: "This game doesn't support save/restore.");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193D60
// Name: public: void CSaveRestore::AddDeferredCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::AddDeferredCommand(CSaveRestore *this, const char *pchCommand)
{
  int m_nValue; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax

  if ( save_huddelayframes.m_pParent != nullptr && (m_nValue = save_huddelayframes.m_pParent->m_Value.m_nValue) >= 0 )
  {
    if ( m_nValue > 10 )
      m_nValue = 10;
  }
  else
  {
    m_nValue = 0;
  }
  this->m_nDeferredCommandFrames = m_nValue;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pchCommand + 1, pStr: pchCommand);
  m_Size = this->m_sDeferredCommands.m_Size;
  m_nAllocationCount = this->m_sDeferredCommands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(
      this: (CUtlMemory<wchar_t,int> *)&this->m_sDeferredCommands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_sDeferredCommands.m_Size;
  m_pMemory = this->m_sDeferredCommands.m_Memory.m_pMemory;
  v7 = this->m_sDeferredCommands.m_Size - m_Size - 1;
  this->m_sDeferredCommands.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v7);
  v8 = &this->m_sDeferredCommands.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    v8->m_Id = *(_WORD *)((unsigned __int16)&pchCommand + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10193F80
// Name: autosave
// Source: json
//------------------------------------------------------------------------------
void __usercall autosave(int a1@<edi>, int a2@<esi>)
{
  if ( saverestore->IsValidSave(this: saverestore) != 0
    && sv_autosave.m_pParent != nullptr
    && sv_autosave.m_pParent->m_Value.m_nValue != 0
    && serverGameDLL->SupportsSaveRestore(this: serverGameDLL)
    && !g_bInCommentaryMode )
  {
    if ( save_console.m_pParent != nullptr && save_console.m_pParent->m_Value.m_nValue != 0 )
      CSaveRestore::AddDeferredCommand(this: g_pSaveRestore, pchCommand: "_autosave");
    else
      AutoSave_Silent(a1, a2, bDangerous: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193FF0
// Name: autosavedangerous
// Source: json
//------------------------------------------------------------------------------
void __usercall autosavedangerous(int a1@<edi>, int a2@<esi>)
{
  if ( cmd_source == src_command
    && saverestore->IsValidSave(this: saverestore) != 0
    && sv_autosave.m_pParent != nullptr
    && sv_autosave.m_pParent->m_Value.m_nValue != 0
    && saverestore->StorageDeviceValid(this: saverestore)
    && serverGameDLL->SupportsSaveRestore(this: serverGameDLL)
    && !g_bInCommentaryMode )
  {
    if ( save_console.m_pParent != nullptr && save_console.m_pParent->m_Value.m_nValue != 0 )
      CSaveRestore::AddDeferredCommand(this: g_pSaveRestore, pchCommand: "_autosavedangerous");
    else
      AutoSave_Silent(a1, a2, bDangerous: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194140
// Name: public: virtual int CSaveRestore::SaveGameSlot(char const __near *,char const __near *,bool,bool,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::SaveGameSlot(
        CSaveRestore *this,
        const char *pSaveName,
        const char *pSaveComment,
        bool onlyThisLevel,
        bool bSetMostRecent,
        const char *pszDestMap,
        const char *pszLandmark)
{
  CSaveRestore *v7; // edi
  int m_nValue; // eax
  int v10; // eax
  DWORD CurrentThreadId; // eax
  unsigned __int8 v12; // al
  int v13; // eax
  bool v14; // bl
  bool (__thiscall *IsXSave)(struct CSaveRestore *); // eax
  const char *(__thiscall *GetSaveDir)(struct CSaveRestore *); // eax
  const char *v17; // eax
  const char *v18; // eax
  int v19; // eax
  int v20; // eax
  char *v21; // eax
  char *v22; // esi
  int v23; // eax
  CSaveRestoreData *v24; // esi
  int v25; // ebx
  int tokenCount; // eax
  char **pTokens; // ecx
  char *v28; // edx
  signed int v29; // edi
  int v30; // eax
  int size; // ecx
  int v32; // eax
  bool v33; // zf
  int v34; // eax
  CSaveRestore *v35; // ebx
  int v36; // edx
  int v37; // edi
  const void *v38; // eax
  char *v39; // eax
  char *v40; // edi
  CFunctor *v41; // eax
  CFunctor *v42; // eax
  CFunctor *v43; // eax
  int v44; // eax
  char *v45; // esi
  const char *v46; // eax
  const char *v47; // [esp-10h] [ebp-41Ch]
  int v48; // [esp-Ch] [ebp-418h]
  const char *v49; // [esp-Ch] [ebp-418h]
  int v50; // [esp-8h] [ebp-414h]
  const char *v51; // [esp-4h] [ebp-410h]
  int v52; // [esp-4h] [ebp-410h]
  GAME_HEADER gameHeader; // [esp+4h] [ebp-408h] BYREF
  char name[260]; // [esp+198h] [ebp-274h] BYREF
  char hlPath[256]; // [esp+29Ch] [ebp-170h] BYREF
  CUtlBuffer saveHeader; // [esp+39Ch] [ebp-70h] BYREF
  CUtlString v57; // [esp+3CCh] [ebp-40h] BYREF
  int iX360controller; // [esp+3DCh] [ebp-30h] BYREF
  int v59; // [esp+3E0h] [ebp-2Ch]
  CSaveRestore *pObject; // [esp+3E4h] [ebp-28h]
  int tokenSize; // [esp+3E8h] [ebp-24h] BYREF
  CUtlString src; // [esp+3ECh] [ebp-20h] BYREF
  char *in; // [esp+3FCh] [ebp-10h]
  bool bIsQuick; // [esp+403h] [ebp-9h]
  int tag; // [esp+404h] [ebp-8h] BYREF
  bool arg1; // [esp+408h] [ebp-4h] BYREF
  bool bClearFile; // [esp+409h] [ebp-3h]
  bool bIsAutosave; // [esp+40Ah] [ebp-2h]
  bool bIsAutosaveDangerous; // [esp+40Bh] [ebp-1h]
  char *pTokenData; // [esp+41Ch] [ebp+10h]
  char *pTokenDataa; // [esp+41Ch] [ebp+10h]
  char *pTokenDatab; // [esp+41Ch] [ebp+10h]
  bool pTokenData_3; // [esp+41Fh] [ebp+13h]
  unsigned __int8 *bSetMostRecenta; // [esp+420h] [ebp+14h]
  const char *pszLandmarka; // [esp+428h] [ebp+1Ch]

  v7 = this;
  pObject = this;
  iX360controller = 0;
  if ( save_disable.m_pParent != nullptr && save_disable.m_pParent->m_Value.m_nValue != 0 )
    return 0;
  if ( save_asyncdelay.m_pParent != nullptr )
  {
    m_nValue = save_asyncdelay.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      if ( m_nValue > 3000 )
        m_nValue = 3000;
      Sys_Sleep(msec: m_nValue);
    }
  }
  bClearFile = true;
  v10 = _V_stricmp(s1: pSaveName, s2: "quick");
  bIsQuick = v10 == 0;
  if ( v10 != 0 && _V_stricmp(s1: pSaveName, s2: "autosave") == 0 )
  {
    bIsAutosave = true;
LABEL_12:
    bIsAutosaveDangerous = false;
    if ( !bIsAutosave
      && map_wants_save_disable.m_pParent != nullptr
      && map_wants_save_disable.m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(a1: "*** REJECTING: %s, due to map_wants_save_disable.\n", pSaveName);
      return 0;
    }
    goto LABEL_18;
  }
  bIsAutosave = false;
  if ( _V_stricmp(s1: pSaveName, s2: "autosavedangerous") != 0 )
    goto LABEL_12;
  bIsAutosaveDangerous = true;
LABEL_18:
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    CurrentThreadId = GetCurrentThreadId();
    v12 = _ThreadInMainThread(a1: CurrentThreadId);
    _Msg(a1: "Start save...\n", v12);
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SaveGameSlot",
    a3: 0,
    a4: "Save",
    a5: false,
    a6: 4);
  g_pSaveRestoreFileSystem->AsyncFinishAllWrites(this: g_pSaveRestoreFileSystem);
  S_ExtraUpdate();
  v7->FinishAsyncSave(this: v7);
  SaveResetMemory();
  S_ExtraUpdate();
  if ( save_async.m_pParent != nullptr )
    v13 = save_async.m_pParent->m_Value.m_nValue;
  else
    v13 = 0;
  v14 = v13 == 0;
  if ( g_AsyncSaveCallQueue.m_bNoQueue != (v13 == 0) )
  {
    if ( !g_AsyncSaveCallQueue.m_bNoQueue )
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_AsyncSaveCallQueue);
    g_AsyncSaveCallQueue.m_bNoQueue = v14;
  }
  CSaveRestore::CalcSaveGameName(this: v7, pName: pSaveName, output: name, outputStringLength: 260);
  _ConDMsg(a1: "Saving game to %s...\n", name);
  in = v7->m_szSaveGameName;
  V_strncpy(pDest: v7->m_szSaveGameName, pSrc: name, maxLen: 260);
  if ( v7->m_bClearSaveDir )
  {
    IsXSave = v7->IsXSave;
    v7->m_bClearSaveDir = false;
    arg1 = IsXSave(this: v7);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CSaveRestore *,CSaveRestore,void,bool,bool>(
      this: &g_AsyncSaveCallQueue,
      pObject: v7,
      pfnProxied: CSaveRestore::DoClearSaveDir,
      &arg1);
  }
  if ( v7->IsXSave(this: v7) )
  {
    hlPath[0] = 0;
    if ( onlyThisLevel )
    {
      v48 = 256 - _V_strlen(str: hlPath);
      v19 = _V_strlen(str: hlPath);
      V_snprintf(pDest: &hlPath[v19], maxLen: v48, pFormat: "//mod/%s*.HL?", sv.m_szMapname);
    }
    else
    {
      v50 = 256 - _V_strlen(str: hlPath);
      v20 = _V_strlen(str: hlPath);
      V_snprintf(pDest: &hlPath[v20], maxLen: v50, pFormat: "//mod/*.HL?");
    }
  }
  else
  {
    GetSaveDir = v7->GetSaveDir;
    if ( onlyThisLevel )
    {
      v17 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))GetSaveDir)(a1: v7, a2: sv.m_szMapname);
      V_snprintf(pDest: hlPath, maxLen: 256, pFormat: "%s%s*.HL?", v17, v51);
    }
    else
    {
      v18 = GetSaveDir(this: v7);
      V_snprintf(pDest: hlPath, maxLen: 256, pFormat: "%s*.HL?", v18);
    }
  }
  if ( bIsQuick || bIsAutosave || bIsAutosaveDangerous )
  {
    bClearFile = false;
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Queue AgeSaveList\n");
    if ( v7->StorageDeviceValid(this: v7) )
    {
      pTokenData_3 = v7->IsXSave(this: v7);
      v59 = save_history_count.m_pParent != nullptr ? save_history_count.m_pParent->m_Value.m_nValue : 0;
      CUtlString::CUtlString(this: &src);
      CUtlString::operator=(this: &src, src: pSaveName);
      v21 = (char *)MemAlloc_Alloc(nSize: 0x30u);
      v22 = v21;
      if ( v21 != nullptr )
      {
        *((_DWORD *)v21 + 3) = 1;
        *(_DWORD *)v21 = &CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,int,bool),CUtlEnvelope<char const *>,int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        *((_DWORD *)v21 + 2) = &CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,int,bool),CUtlEnvelope<char const *>,int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        *((_DWORD *)v21 + 4) = CSaveRestore::AgeSaveList;
        *((_DWORD *)v21 + 5) = v7;
        CUtlString::CUtlString(this: (CUtlString *)(v21 + 24));
        CUtlString::operator=(this: (CUtlString *)(v22 + 24), &src);
        *((_DWORD *)v22 + 10) = v59;
        v22[44] = pTokenData_3;
      }
      else
      {
        v22 = nullptr;
      }
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(
        this: &g_AsyncSaveCallQueue,
        pFunctor: (CFunctor *)v22);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
  S_ExtraUpdate();
  if ( bIsAutosave || bIsAutosaveDangerous )
    v23 = 1;
  else
    LOBYTE(v23) = 0;
  v52 = v23;
  if ( ((unsigned __int8 (__thiscall *)(CSaveRestore *, bool, _DWORD))v7->SaveGameState)(
         a1: v7,
         a2: pszDestMap != nullptr,
         a3: 0) == 0
    || (S_ExtraUpdate(), (v24 = serverGameDLL->SaveInit(this: serverGameDLL, a2: 0)) == nullptr) )
  {
    *in = 0;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  V_FixSlashes(pname: hlPath, separator: 92);
  V_strncpy(pDest: gameHeader.comment, pSrc: pSaveComment, maxLen: 80);
  if ( pszDestMap != nullptr && pszLandmark != nullptr && *pszDestMap != 0 && *pszLandmark != 0 )
  {
    V_strncpy(pDest: gameHeader.mapName, pSrc: pszDestMap, maxLen: 32);
    V_strncpy(pDest: gameHeader.originMapName, pSrc: sv.m_szMapname, maxLen: 32);
    V_strncpy(pDest: gameHeader.landmark, pSrc: pszLandmark, maxLen: 256);
  }
  else
  {
    V_strncpy(pDest: gameHeader.mapName, pSrc: sv.m_szMapname, maxLen: 32);
    gameHeader.originMapName[0] = 0;
    gameHeader.landmark[0] = 0;
  }
  v25 = 0;
  gameHeader.mapCount = 0;
  ((void (__thiscall *)(IServerGameDLL *, CSaveRestoreData *, const char *, GAME_HEADER *, _DWORD, typedescription_t *, int, _DWORD, int))serverGameDLL->SaveWriteFields)(
    a1: serverGameDLL,
    a2: v24,
    a3: "GameHeader",
    a4: &gameHeader,
    a5: 0,
    a6: GAME_HEADER::m_DataMap.dataDesc,
    a7: GAME_HEADER::m_DataMap.dataNumFields,
    a8: 0,
    a9: v52);
  serverGameDLL->SaveGlobalState(this: serverGameDLL, a2: v24);
  pTokenData = v24->pCurrentData;
  if ( v24->tokenCount <= 0 )
    goto LABEL_79;
  while ( 1 )
  {
    if ( v25 < 0 )
      goto LABEL_72;
    tokenCount = v24->tokenCount;
    if ( v25 >= tokenCount )
      goto LABEL_72;
    pTokens = v24->pTokens;
    if ( pTokens[v25] != nullptr )
    {
      if ( v25 < tokenCount )
      {
        v28 = pTokens[v25];
        goto LABEL_74;
      }
LABEL_72:
      v28 = "<<illegal>>";
      goto LABEL_74;
    }
    v28 = (char *)defaultValue;
LABEL_74:
    v29 = strlen(v28) + 1;
    if ( v29 > v24->bufferSize - v24->size )
      break;
    memcpy(dst: (unsigned __int8 *)v24->pCurrentData, src: (unsigned __int8 *)v28, count: v29);
    v24->pCurrentData += v29;
    v24->size += v29;
    if ( ++v25 >= v24->tokenCount )
      goto LABEL_78;
  }
  v24->size = v24->bufferSize;
  ConMsg(a1: "Token Table Save/Restore overflow!");
LABEL_78:
  v7 = pObject;
LABEL_79:
  v30 = v24->pCurrentData - pTokenData;
  tokenSize = v30;
  size = v24->size;
  if ( size < v30 )
    v30 = v24->size;
  v32 = -v30;
  v24->pCurrentData += v32;
  v33 = !bClearFile;
  v24->size = v32 + size;
  if ( !v33 )
  {
    v34 = ((int (__thiscall *)(ISaveRestoreFileSystem *, char *))g_pSaveRestoreFileSystem->Open)(
            a1: g_pSaveRestoreFileSystem,
            a2: name);
    if ( v34 == 0 )
    {
      _Msg(a1: "Save failed: invalid file name '%s'\n", pSaveName);
      *in = 0;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 0;
    }
    ((void (__thiscall *)(ISaveRestoreFileSystem *, int, const char *, _DWORD))g_pSaveRestoreFileSystem->Close)(
      a1: g_pSaveRestoreFileSystem,
      a2: v34,
      a3: "wb",
      a4: 0);
    S_ExtraUpdate();
  }
  if ( bSetMostRecent )
    v7->SetMostRecentSaveGame(this: v7, a2: pSaveName);
  v35 = pObject;
  v36 = tokenSize;
  pObject->m_bWaitingForSafeDangerousSave = bIsAutosaveDangerous;
  v37 = v24->size + v36 + 64;
  v38 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v37);
  CUtlBuffer::CUtlBuffer(this: &saveHeader, pBuffer: v38, nSize: v37, nFlags: 0);
  tag = 1447121738;
  CUtlBuffer::Put(this: &saveHeader, pMem: &tag, size: 4);
  tag = 116;
  CUtlBuffer::Put(this: &saveHeader, pMem: &tag, size: 4);
  tag = v24->size;
  CUtlBuffer::Put(this: &saveHeader, pMem: &tag, size: 4);
  tag = v24->tokenCount;
  CUtlBuffer::Put(this: &saveHeader, pMem: &tag, size: 4);
  CUtlBuffer::Put(this: &saveHeader, pMem: &tokenSize, size: 4);
  CUtlBuffer::Put(this: &saveHeader, pMem: pTokenData, size: tokenSize);
  CUtlBuffer::Put(this: &saveHeader, pMem: v24->pBaseData, size: v24->size);
  bSetMostRecenta = saveHeader.m_Memory.m_pMemory;
  pszLandmarka = (const char *)saveHeader.m_Put;
  CUtlString::CUtlString(this: &src);
  CUtlString::operator=(this: &src, src: name);
  pTokenDataa = (char *)g_pSaveRestoreFileSystem;
  v39 = (char *)MemAlloc_Alloc(nSize: 0x38u);
  v40 = v39;
  if ( v39 != nullptr )
  {
    *((_DWORD *)v39 + 3) = 1;
    *(_DWORD *)v39 = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    *((_DWORD *)v39 + 2) = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *((_DWORD *)v39 + 5) = pTokenDataa;
    *((_DWORD *)v39 + 4) =  __thiscall IToolSystem::`vcall'{52,{flat}};
    CUtlString::CUtlString(this: (CUtlString *)(v39 + 24));
    CUtlString::operator=(this: (CUtlString *)(v40 + 24), &src);
    *((_DWORD *)v40 + 10) = bSetMostRecenta;
    *((_DWORD *)v40 + 11) = pszLandmarka;
    *((_WORD *)v40 + 24) = 1;
    *((_DWORD *)v40 + 13) = 0;
    v41 = (CFunctor *)v40;
  }
  else
  {
    v41 = nullptr;
  }
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_AsyncSaveCallQueue, pFunctor: v41);
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  CUtlString::CUtlString(this: &v57);
  CUtlString::operator=(this: &v57, src: name);
  CUtlString::CUtlString(this: &src);
  CUtlString::operator=(this: &src, src: hlPath);
  v42 = CreateFunctor<CSaveRestore *,CSaveRestore,void,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
          pObject: v35,
          pfnProxied: CSaveRestore::DirectoryCopy,
          arg1: (const CUtlEnvelope<char const *> *)&src,
          arg2: (const CUtlEnvelope<char const *> *)&v57,
          arg3: &v35->m_bIsXSave);
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_AsyncSaveCallQueue, pFunctor: v42);
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
      src.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    src.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v57.m_Storage.m_nActualLength = 0;
  if ( v57.m_Storage.m_Memory.m_nGrowSize >= 0 && v57.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57.m_Storage.m_Memory.m_pMemory);
  pTokenDatab = (char *)g_pFileSystem;
  v43 = (CFunctor *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v43 != nullptr )
  {
    v43[1].m_nUserID = 1;
    v43->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IFileSystem *,void (__thiscall IFileSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v43[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IFileSystem *,void (__thiscall IFileSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v43[2].__vftable = (CFunctor_vtbl *) __thiscall IToolSystem::`vcall'{180,{flat}};
    v43[2].m_nUserID = 0;
    v43[3].__vftable = (CFunctor_vtbl *)pTokenDatab;
  }
  else
  {
    v43 = nullptr;
  }
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_AsyncSaveCallQueue, pFunctor: v43);
  if ( v35->IsXSave(this: v35) && v35->StorageDeviceValid(this: v35) )
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<IXboxSystem *,IXboxSystem,void,int,int>(
      this: &g_AsyncSaveCallQueue,
      pObject: g_pXboxSystem,
      pfnProxied:  __thiscall IXboxSystem::`vcall'{36,{flat}},
      arg1: &iX360controller);
  S_ExtraUpdate();
  v35->Finish(this: v35, a2: v24);
  S_ExtraUpdate();
  if ( save_screenshot.m_pParent == nullptr )
    goto LABEL_114;
  v44 = save_screenshot.m_pParent->m_Value.m_nValue;
  if ( (v44 == 0 || bIsAutosave || bIsAutosaveDangerous) && v44 != 2 )
    goto LABEL_114;
  if ( !v35->IsXSave(this: v35) )
  {
    v46 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, const char *))v35->GetSaveDir)(
                          a1: v35,
                          a2: pSaveName,
                          a3: defaultValue);
    V_snprintf(pDest: v35->m_szSaveGameScreenshotFile, maxLen: 260, pFormat: "%s%s%s.tga", v46, v47, v49);
LABEL_114:
    v45 = in;
    goto LABEL_115;
  }
  v45 = in;
  V_StripExtension(in, out: v35->m_szSaveGameScreenshotFile, outSize: 260);
  V_strncat(pDest: v35->m_szSaveGameScreenshotFile, pSrc: ".tga", destBufferSize: 0x104u, max_chars_to_copy: -1);
LABEL_115:
  V_strncpy(pDest: v35->m_MostRecentSaveInfo.m_MostRecentSavePath, pSrc: v45, maxLen: 260);
  V_strncpy(pDest: v35->m_MostRecentSaveInfo.m_MostRecentSaveComment, pSrc: pSaveComment, maxLen: 80);
  if ( V_stristr(pStr: v45, pSearch: "autosavedangerous") != nullptr )
    V_strncpy(pDest: v35->m_MostRecentSaveInfo.m_LastAutosaveDangerousComment, pSrc: pSaveComment, maxLen: 80);
  v35->m_MostRecentSaveInfo.m_bValid = true;
  DispatchAsyncSave();
  *v45 = 0;
  if ( saveHeader.m_Memory.m_nGrowSize >= 0 )
  {
    if ( saveHeader.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: saveHeader.m_Memory.m_pMemory);
      saveHeader.m_Memory.m_pMemory = nullptr;
    }
    saveHeader.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10194B60
// Name: private: bool CSaveRestore::SaveClientState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestore::SaveClientState(CSaveRestore *this, const char *name)
{
  int v2; // edi
  CSaveRestoreData *v3; // eax
  CSaveRestoreData *v4; // esi
  int v6; // eax
  decallist_t *v7; // ebx
  int v8; // ebx
  unsigned int channelsize; // ecx
  int v10; // ebx
  int tokenCount; // eax
  char **pTokens; // ecx
  char *v13; // edx
  signed int v14; // edi
  int v15; // eax
  int v16; // ebx
  char *v17; // eax
  char *v18; // edi
  void *v19; // eax
  const char *v20; // ebx
  TSLHead_t m_Head; // kr00_8
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v22; // eax
  channelsave *m_pMemory; // eax
  CUtlBuffer buffer; // [esp+8h] [ebp-9Ch] BYREF
  CUtlString src; // [esp+38h] [ebp-6Ch] BYREF
  void *pBuffer; // [esp+48h] [ebp-5Ch]
  CSaveRestore *v27; // [esp+4Ch] [ebp-58h]
  decallist_t *decalList; // [esp+50h] [ebp-54h]
  clientsections_t sections; // [esp+54h] [ebp-50h] BYREF
  CUtlVector<channelsave,CUtlMemory<channelsave,int> > channels; // [esp+88h] [ebp-1Ch] BYREF
  int sectionheaderversion; // [esp+9Ch] [ebp-8h] BYREF
  int magicnumber; // [esp+A0h] [ebp-4h] BYREF
  const char *namea; // [esp+ACh] [ebp+8h]
  const char *nameb; // [esp+ACh] [ebp+8h]

  v27 = this;
  v2 = 0;
  v3 = g_ClientDLL->SaveInit(this: g_ClientDLL, a2: 0);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  sections.entitydata = v3->pCurrentData;
  g_ClientDLL->PreSave(this: g_ClientDLL, a2: v3);
  g_ClientDLL->Save(this: g_ClientDLL, a2: v4);
  sections.entitysize = v4->pCurrentData - sections.entitydata;
  sections.headerdata = v4->pCurrentData;
  g_ClientDLL->WriteSaveHeaders(this: g_ClientDLL, a2: v4);
  sections.headersize = v4->pCurrentData - sections.headerdata;
  sections.decaldata = v4->pCurrentData;
  v6 = Draw_DecalMax();
  v7 = (decallist_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 156 * v6);
  decalList = v7;
  sections.decalcount = DecalListCreate(pList: v7);
  if ( sections.decalcount > 0 )
  {
    do
    {
      g_ClientDLL->SaveWriteFields(
        this: g_ClientDLL,
        a2: v4,
        a3: "DECALLIST",
        a4: v7,
        a5: nullptr,
        a6: decallist_t::m_DataMap.dataDesc,
        a7: decallist_t::m_DataMap.dataNumFields);
      ++v2;
      ++v7;
    }
    while ( v2 < sections.decalcount );
    v2 = 0;
  }
  sections.decalsize = v4->pCurrentData - sections.decaldata;
  memset(&channels, 0, sizeof(channels));
  S_GetActiveSaveRestoreChannels(channelSaves: &channels);
  sections.channelcount = channels.m_Size;
  sections.channeldata = v4->pCurrentData;
  if ( channels.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      g_ClientDLL->SaveWriteFields(
        this: g_ClientDLL,
        a2: v4,
        a3: "CHANNELLIST",
        a4: &channels.m_Memory.m_pMemory[v8],
        a5: nullptr,
        a6: channelsave::m_DataMap.dataDesc,
        a7: channelsave::m_DataMap.dataNumFields);
      ++v2;
      ++v8;
    }
    while ( v2 < sections.channelcount );
  }
  channelsize = v4->pCurrentData - sections.channeldata;
  v10 = 0;
  sections.channelsize = channelsize;
  sections.symboldata = v4->pCurrentData;
  if ( v4->tokenCount <= 0 )
    goto LABEL_22;
  while ( 1 )
  {
    if ( v10 < 0 )
      goto LABEL_15;
    tokenCount = v4->tokenCount;
    if ( v10 >= tokenCount )
      goto LABEL_15;
    pTokens = v4->pTokens;
    if ( pTokens[v10] != nullptr )
    {
      if ( v10 < tokenCount )
      {
        v13 = pTokens[v10];
        goto LABEL_17;
      }
LABEL_15:
      v13 = "<<illegal>>";
      goto LABEL_17;
    }
    v13 = (char *)defaultValue;
LABEL_17:
    v14 = strlen(v13) + 1;
    if ( v14 > v4->bufferSize - v4->size )
      break;
    memcpy(dst: (unsigned __int8 *)v4->pCurrentData, src: (unsigned __int8 *)v13, count: v14);
    v4->pCurrentData += v14;
    v4->size += v14;
    if ( ++v10 >= v4->tokenCount )
      goto LABEL_21;
  }
  v4->size = v4->bufferSize;
  ConMsg(a1: "Token Table Save/Restore overflow!");
LABEL_21:
  channelsize = sections.channelsize;
LABEL_22:
  sections.symbolcount = v4->tokenCount;
  v15 = v4->pCurrentData - sections.symboldata;
  magicnumber = 1414795828;
  sections.symbolsize = v15;
  sectionheaderversion = 2;
  v16 = sections.headersize + sections.decalsize + channelsize + v15 + sections.entitysize + 48;
  pBuffer = MemAlloc_Alloc(nSize: v16);
  CUtlBuffer::CUtlBuffer(this: &buffer, pBuffer, nSize: v16, nFlags: 0);
  CUtlBuffer::Put(this: &buffer, pMem: &CURRENT_SAVEFILE_HEADER_TAG, size: 8);
  CUtlBuffer::Put(this: &buffer, pMem: &magicnumber, size: 4);
  CUtlBuffer::Put(this: &buffer, pMem: &sectionheaderversion, size: 4);
  CUtlBuffer::Put(this: &buffer, pMem: &sections, size: 32);
  CUtlBuffer::Put(this: &buffer, pMem: sections.symboldata, size: sections.symbolsize);
  CUtlBuffer::Put(this: &buffer, pMem: sections.headerdata, size: sections.headersize);
  CUtlBuffer::Put(this: &buffer, pMem: sections.entitydata, size: sections.entitysize);
  CUtlBuffer::Put(this: &buffer, pMem: sections.decaldata, size: sections.decalsize);
  CUtlBuffer::Put(this: &buffer, pMem: sections.channeldata, size: sections.channelsize);
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Queue AsyncWrite (%s)\n", name);
  CUtlString::CUtlString(this: &src);
  CUtlString::operator=(this: &src, src: name);
  namea = (const char *)g_pSaveRestoreFileSystem;
  v17 = (char *)MemAlloc_Alloc(nSize: 0x38u);
  v18 = v17;
  if ( v17 != nullptr )
  {
    *((_DWORD *)v17 + 3) = 1;
    *(_DWORD *)v17 = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,unsigned int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    *((_DWORD *)v17 + 2) = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,unsigned int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *((_DWORD *)v17 + 5) = namea;
    *((_DWORD *)v17 + 4) =  __thiscall IToolSystem::`vcall'{52,{flat}};
    CUtlString::CUtlString(this: (CUtlString *)(v17 + 24));
    CUtlString::operator=(this: (CUtlString *)(v18 + 24), &src);
    v19 = pBuffer;
    *((_DWORD *)v18 + 11) = v16;
    v20 = v18;
    *((_DWORD *)v18 + 10) = v19;
    *((_WORD *)v18 + 24) = 1;
    *((_DWORD *)v18 + 13) = 0;
    nameb = v18;
  }
  else
  {
    nameb = nullptr;
    v20 = nullptr;
  }
  if ( g_AsyncSaveCallQueue.m_bNoQueue )
  {
    (*(void (__thiscall **)(const char *))(*(_DWORD *)v20 + 12))(a1: v20);
    (*(void (__thiscall **)(const char *))(*(_DWORD *)v20 + 4))(a1: v20);
  }
  else
  {
    m_Head = g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head;
    if ( g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head.value.Next != nullptr )
    {
      while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                 a1: &g_AsyncSaveCallQueue.m_queue.m_FreeNodes,
                                 a2: m_Head.value.Next->Next,
                                 a3: m_Head.value32.DepthAndSequence - 1,
                                 a4: m_Head.value.Next,
                                 a5: m_Head.value32.DepthAndSequence) == 0 )
      {
        _mm_pause();
        m_Head = g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head;
        if ( g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head.value.Next == nullptr )
        {
          v20 = nameb;
          goto LABEL_33;
        }
      }
      *((_DWORD *)&m_Head.value.Next->Next + 1) = nameb;
      CTSQueue<CFunctor *,0,1>::Push(
        this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue,
        pNode: (CTSQueue<StartSoundParams_t,0,1>::Node_t *)m_Head.value.Next);
    }
    else
    {
LABEL_33:
      v22 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
      if ( v22 != nullptr )
      {
        v22->elem.userdata = (int)v20;
        CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: v22);
      }
      else
      {
        CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: nullptr);
      }
    }
  }
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  v27->Finish(this: v27, a2: v4);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: decalList);
  if ( buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
      buffer.m_Memory.m_pMemory = nullptr;
    }
    buffer.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = channels.m_Memory.m_pMemory;
  channels.m_Size = 0;
  if ( channels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( channels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channels.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      channels.m_Memory.m_pMemory = nullptr;
    }
    channels.m_Memory.m_nAllocationCount = 0;
  }
  channels.m_pElements = m_pMemory;
  if ( channels.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10195050
// Name: private: void CSaveRestore::EntityPatchWrite(class CSaveRestoreData __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::EntityPatchWrite(
        CSaveRestore *this,
        CSaveRestoreData *pSaveData,
        const char *level,
        bool bAsync)
{
  const char *v5; // eax
  int v6; // eax
  int tableCount; // ecx
  int v8; // edx
  int v9; // eax
  entitytable_t *pTable; // edi
  int v11; // ebx
  void *v12; // edi
  int v13; // eax
  ISaveRestoreFileSystem *v14; // edi
  char *v15; // eax
  char *v16; // esi
  TSLHead_t m_Head; // kr00_8
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v18; // eax
  int v19; // [esp-Ch] [ebp-164h]
  const char *v20; // [esp-4h] [ebp-15Ch]
  char name[260]; // [esp+Ch] [ebp-14Ch] BYREF
  CUtlBuffer buffer; // [esp+110h] [ebp-48h] BYREF
  CUtlString src; // [esp+140h] [ebp-18h] BYREF
  int size; // [esp+150h] [ebp-8h] BYREF
  int i; // [esp+154h] [ebp-4h] BYREF
  void *pBuffer; // [esp+164h] [ebp+Ch]

  if ( this->IsXSave(this) )
  {
    name[0] = 0;
    v19 = 260 - _V_strlen(str: name);
    v6 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v6], maxLen: v19, pFormat: "//mod/%s.HL3", level);
  }
  else
  {
    v5 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: level);
    V_snprintf(pDest: name, maxLen: 260, pFormat: "//%s/%s%s.HL3", "MOD", v5, v20);
  }
  tableCount = pSaveData->tableCount;
  v8 = 0;
  v9 = 0;
  size = 0;
  i = 0;
  if ( tableCount > 0 )
  {
    pTable = pSaveData->pTable;
    do
    {
      if ( (pTable[v9].flags & 0x40000000) != 0 )
        size = ++v8;
      i = ++v9;
    }
    while ( v9 < tableCount );
  }
  v11 = 4 * v8 + 4;
  v12 = MemAlloc_Alloc(nSize: v11);
  pBuffer = v12;
  CUtlBuffer::CUtlBuffer(this: &buffer, pBuffer: v12, nSize: v11, nFlags: 0);
  CUtlBuffer::Put(this: &buffer, pMem: &size, size: 4);
  v13 = 0;
  for ( i = 0; v13 < pSaveData->tableCount; i = v13 )
  {
    if ( (pSaveData->pTable[v13].flags & 0x40000000) != 0 )
    {
      CUtlBuffer::Put(this: &buffer, pMem: &i, size: 4);
      v13 = i;
    }
    ++v13;
  }
  if ( bAsync )
  {
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Queue AsyncWrite (%s)\n", name);
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: name);
    v14 = g_pSaveRestoreFileSystem;
    v15 = (char *)MemAlloc_Alloc(nSize: 0x38u);
    v16 = v15;
    if ( v15 != nullptr )
    {
      *((_DWORD *)v15 + 3) = 1;
      *(_DWORD *)v15 = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      *((_DWORD *)v15 + 2) = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v15 + 4) =  __thiscall IToolSystem::`vcall'{52,{flat}};
      *((_DWORD *)v15 + 5) = v14;
      CUtlString::CUtlString(this: (CUtlString *)(v15 + 24));
      CUtlString::operator=(this: (CUtlString *)(v16 + 24), &src);
      *((_DWORD *)v16 + 10) = pBuffer;
      *((_DWORD *)v16 + 11) = v11;
      *((_WORD *)v16 + 24) = 1;
      *((_DWORD *)v16 + 13) = 0;
    }
    else
    {
      v16 = nullptr;
    }
    if ( g_AsyncSaveCallQueue.m_bNoQueue )
    {
      (*(void (__thiscall **)(char *))(*(_DWORD *)v16 + 12))(a1: v16);
      (*(void (__thiscall **)(char *))(*(_DWORD *)v16 + 4))(a1: v16);
    }
    else
    {
      m_Head = g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head;
      if ( g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head.value.Next != nullptr )
      {
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                   a1: &g_AsyncSaveCallQueue.m_queue.m_FreeNodes,
                                   a2: m_Head.value.Next->Next,
                                   a3: m_Head.value32.DepthAndSequence - 1,
                                   a4: m_Head.value.Next,
                                   a5: m_Head.value32.DepthAndSequence) == 0 )
        {
          _mm_pause();
          m_Head = g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head;
          if ( g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head.value.Next == nullptr )
            goto LABEL_25;
        }
        *((_DWORD *)&m_Head.value.Next->Next + 1) = v16;
        CTSQueue<CFunctor *,0,1>::Push(
          this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue,
          pNode: (CTSQueue<StartSoundParams_t,0,1>::Node_t *)m_Head.value.Next);
      }
      else
      {
LABEL_25:
        v18 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
        if ( v18 != nullptr )
        {
          v18->elem.userdata = (int)v16;
          CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: v18);
        }
        else
        {
          CTSQueue<CFunctor *,0,1>::Push(
            this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue,
            pNode: nullptr);
        }
      }
    }
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    g_pSaveRestoreFileSystem->AsyncWrite(
      this: g_pSaveRestoreFileSystem,
      a2: name,
      a3: v12,
      a4: v11,
      a5: true,
      a6: false,
      a7: nullptr);
    g_pSaveRestoreFileSystem->AsyncFinishAllWrites(this: g_pSaveRestoreFileSystem);
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10195420
// Name: public: virtual bool CSaveRestore::SaveGameState(bool,class ISaveRestoreDataCallback __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::SaveGameState(
        CSaveRestore *this,
        bool bTransition,
        ISaveRestoreDataCallback *pCallback,
        bool bOpenContainer,
        bool bIsAutosaveOrDangerous)
{
  IMDLCache *v5; // ebx
  void (__thiscall *BeginCoarseLock)(IMDLCache *); // edx
  CSaveRestore *v7; // edi
  bool (__thiscall *IsXSave)(struct CSaveRestore *); // edx
  bool v9; // al
  CSaveRestoreData *v10; // eax
  CSaveRestoreData *v11; // esi
  int pCurrentData; // ebx
  void (__thiscall *PreSave)(IServerGameDLL *, CSaveRestoreData *); // eax
  void (__thiscall *WriteSaveHeaders)(IServerGameDLL *, CSaveRestoreData *); // eax
  int nBytesDataHeaders; // ecx
  int v17; // ebx
  int tokenCount; // eax
  char **pTokens; // ecx
  char *v20; // edx
  signed int v21; // edi
  int v22; // ebx
  const char *v23; // eax
  char *v24; // eax
  char *v25; // edi
  int v26; // eax
  char *v27; // eax
  char *v28; // edi
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v29; // eax
  CSaveRestore *v30; // edi
  const char *v31; // eax
  int v32; // eax
  bool v33; // bl
  int v34; // [esp-Ch] [ebp-174h]
  int v35; // [esp-Ch] [ebp-174h]
  const char *v36; // [esp-4h] [ebp-16Ch]
  const char *v37; // [esp-4h] [ebp-16Ch]
  char name[256]; // [esp+Ch] [ebp-15Ch] BYREF
  CUtlBuffer buffer; // [esp+10Ch] [ebp-5Ch] BYREF
  void *pBuffer; // [esp+13Ch] [ebp-2Ch]
  CMDLCacheCoarseCriticalSection cacheCoarseCriticalSection; // [esp+140h] [ebp-28h]
  SaveFileSectionsInfo_t sectionsInfo; // [esp+144h] [ebp-24h] BYREF
  CSaveRestore *v43; // [esp+154h] [ebp-14h]
  CUtlString src; // [esp+158h] [ebp-10h] BYREF
  ISaveRestoreFileSystem *bIsAutosaveOrDangerousa; // [esp+17Ch] [ebp+14h]

  v5 = g_pMDLCache;
  BeginCoarseLock = g_pMDLCache->BeginCoarseLock;
  v7 = this;
  v43 = this;
  cacheCoarseCriticalSection.m_pCache = g_pMDLCache;
  BeginCoarseLock(this: g_pMDLCache);
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "SaveGameState...\n");
  if ( bTransition && v7->m_bClearSaveDir )
  {
    IsXSave = v7->IsXSave;
    v7->m_bClearSaveDir = false;
    v9 = IsXSave(this: v7);
    CSaveRestore::DoClearSaveDir(this: v7, bIsXSave: v9);
  }
  S_ExtraUpdate();
  v10 = serverGameDLL->SaveInit(this: serverGameDLL, a2: 0);
  v11 = v10;
  if ( v10 == nullptr )
  {
    v5->EndCoarseLock(this: v5);
    return false;
  }
  pCurrentData = (int)v10->pCurrentData;
  v10->bAsync = bIsAutosaveOrDangerous;
  PreSave = serverGameDLL->PreSave;
  src.m_Storage.m_nActualLength = pCurrentData;
  PreSave(this: serverGameDLL, a2: v11);
  if ( bTransition )
    serverGameDLL->BuildAdjacentMapList(this: serverGameDLL);
  else
    v11->levelInfo.connectionCount = 0;
  S_ExtraUpdate();
  CSaveRestore::SaveGameStateGlobals(this: v7, pSaveData: v11);
  S_ExtraUpdate();
  serverGameDLL->Save(this: serverGameDLL, a2: v11);
  S_ExtraUpdate();
  sectionsInfo.nBytesData = (int)&v11->pCurrentData[-pCurrentData];
  WriteSaveHeaders = serverGameDLL->WriteSaveHeaders;
  src.m_Storage.m_Memory.m_nGrowSize = (int)v11->pCurrentData;
  WriteSaveHeaders(this: serverGameDLL, a2: v11);
  nBytesDataHeaders = (int)&v11->pCurrentData[-src.m_Storage.m_Memory.m_nGrowSize];
  sectionsInfo.nBytesDataHeaders = nBytesDataHeaders;
  v17 = 0;
  src.m_Storage.m_Memory.m_nAllocationCount = (int)v11->pCurrentData;
  if ( v11->tokenCount <= 0 )
    goto LABEL_25;
  while ( 1 )
  {
    if ( v17 < 0 )
      goto LABEL_18;
    tokenCount = v11->tokenCount;
    if ( v17 >= tokenCount )
      goto LABEL_18;
    pTokens = v11->pTokens;
    if ( pTokens[v17] != nullptr )
    {
      if ( v17 < tokenCount )
      {
        v20 = pTokens[v17];
        goto LABEL_20;
      }
LABEL_18:
      v20 = "<<illegal>>";
      goto LABEL_20;
    }
    v20 = (char *)defaultValue;
LABEL_20:
    v21 = strlen(v20) + 1;
    if ( v21 > v11->bufferSize - v11->size )
      break;
    memcpy(dst: (unsigned __int8 *)v11->pCurrentData, src: (unsigned __int8 *)v20, count: v21);
    v11->pCurrentData += v21;
    v11->size += v21;
    if ( ++v17 >= v11->tokenCount )
      goto LABEL_24;
  }
  v11->size = v11->bufferSize;
LABEL_24:
  v7 = v43;
  nBytesDataHeaders = sectionsInfo.nBytesDataHeaders;
LABEL_25:
  sectionsInfo.nBytesSymbols = (int)&v11->pCurrentData[-src.m_Storage.m_Memory.m_nAllocationCount];
  v22 = nBytesDataHeaders + sectionsInfo.nBytesSymbols + sectionsInfo.nBytesData + 24;
  sectionsInfo.nSymbols = v11->tokenCount;
  pBuffer = MemAlloc_Alloc(nSize: v22);
  CUtlBuffer::CUtlBuffer(this: &buffer, pBuffer, nSize: v22, nFlags: 0);
  CUtlBuffer::Put(this: &buffer, pMem: &CURRENT_SAVEFILE_HEADER_TAG, size: 8);
  CUtlBuffer::Put(this: &buffer, pMem: &sectionsInfo, size: 16);
  CUtlBuffer::Put(
    this: &buffer,
    pMem: (const void *)src.m_Storage.m_Memory.m_nAllocationCount,
    size: sectionsInfo.nBytesSymbols);
  CUtlBuffer::Put(
    this: &buffer,
    pMem: (const void *)src.m_Storage.m_Memory.m_nGrowSize,
    size: sectionsInfo.nBytesDataHeaders);
  CUtlBuffer::Put(this: &buffer, pMem: (const void *)src.m_Storage.m_nActualLength, size: sectionsInfo.nBytesData);
  if ( v7->IsXSave(this: v7) )
  {
    name[0] = 0;
    V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
    v34 = 256 - _V_strlen(str: name);
    v26 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v26], maxLen: v34, pFormat: "//mod/%s.HL1", level);
  }
  else
  {
    V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
    v23 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))v7->GetSaveDir)(a1: v7, a2: level);
    V_snprintf(pDest: name, maxLen: 256, pFormat: "//%s/%s%s.HL1", "MOD", v23, v36);
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Queue COM_CreatePath\n");
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: name);
    v24 = (char *)MemAlloc_Alloc(nSize: 0x24u);
    v25 = v24;
    if ( v24 != nullptr )
    {
      *((_DWORD *)v24 + 3) = 1;
      *(_DWORD *)v24 = &CFunctor1<void (__cdecl *)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v24 + 2) = &CFunctor1<void (__cdecl *)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v24 + 4) = COM_CreatePath;
      CUtlString::CUtlString(this: (CUtlString *)(v24 + 20));
      CUtlString::operator=(this: (CUtlString *)(v25 + 20), &src);
    }
    else
    {
      v25 = nullptr;
    }
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_AsyncSaveCallQueue, pFunctor: (CFunctor *)v25);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  }
  S_ExtraUpdate();
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Queue AsyncWrite (%s)\n", name);
  CUtlString::CUtlString(this: &src);
  CUtlString::operator=(this: &src, src: name);
  bIsAutosaveOrDangerousa = g_pSaveRestoreFileSystem;
  v27 = (char *)MemAlloc_Alloc(nSize: 0x38u);
  v28 = v27;
  if ( v27 != nullptr )
  {
    *((_DWORD *)v27 + 3) = 1;
    *(_DWORD *)v27 = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    *((_DWORD *)v27 + 2) = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *((_DWORD *)v27 + 4) =  __thiscall IToolSystem::`vcall'{52,{flat}};
    *((_DWORD *)v27 + 5) = bIsAutosaveOrDangerousa;
    CUtlString::CUtlString(this: (CUtlString *)(v27 + 24));
    CUtlString::operator=(this: (CUtlString *)(v28 + 24), &src);
    *((_DWORD *)v28 + 10) = pBuffer;
    *((_DWORD *)v28 + 11) = v22;
    *((_WORD *)v28 + 24) = 1;
    *((_DWORD *)v28 + 13) = 0;
  }
  else
  {
    v28 = nullptr;
  }
  if ( g_AsyncSaveCallQueue.m_bNoQueue )
  {
    (*(void (__thiscall **)(char *))(*(_DWORD *)v28 + 12))(a1: v28);
    (*(void (__thiscall **)(char *))(*(_DWORD *)v28 + 4))(a1: v28);
  }
  else
  {
    v29 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)CTSListBase::Pop(this: &g_AsyncSaveCallQueue.m_queue.m_FreeNodes);
    if ( v29 != nullptr || (v29 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
    {
      v29->elem.userdata = (int)v28;
      CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: v29);
    }
    else
    {
      CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: nullptr);
    }
  }
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
  v30 = v43;
  CSaveRestore::EntityPatchWrite(this: v43, pSaveData: v11, level: level, bAsync: true);
  if ( pCallback != nullptr )
    pCallback->Execute(this: pCallback, a2: v11);
  v30->Finish(this: v30, a2: v11);
  if ( v30->IsXSave(this: v30) )
  {
    name[0] = 0;
    V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
    v35 = 256 - _V_strlen(str: name);
    v32 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v32], maxLen: v35, pFormat: "//mod/%s.HL2", level);
  }
  else
  {
    V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
    v31 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))v30->GetSaveDir)(a1: v30, a2: level);
    V_snprintf(pDest: name, maxLen: 256, pFormat: "//%s/%s%s.HL2", "MOD", v31, v37);
  }
  S_ExtraUpdate();
  v33 = CSaveRestore::SaveClientState(this: v30, name);
  S_ExtraUpdate();
  if ( bTransition )
    v30->FinishAsyncSave(this: v30);
  S_ExtraUpdate();
  if ( buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
      buffer.m_Memory.m_pMemory = nullptr;
    }
    buffer.m_Memory.m_nAllocationCount = 0;
  }
  cacheCoarseCriticalSection.m_pCache->EndCoarseLock(this: cacheCoarseCriticalSection.m_pCache);
  return v33;
}

//------------------------------------------------------------------------------
// Address: 0x10195A10
// Name: public: void CUtlDict<struct CSaveRestore::RestoreLookupTable,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CSaveRestore::RestoreLookupTable,int>::RemoveAll(
        CUtlDict<CSaveRestore::RestoreLookupTable,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10195A60
// Name: public: virtual void CSaveRestore::OnFinishedClientRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::OnFinishedClientRestore(CSaveRestore *this)
{
  void (__thiscall *FinishAsyncSave)(struct CSaveRestore *); // edx
  bool v3; // al

  g_ClientDLL->DispatchOnRestore(this: g_ClientDLL);
  CUtlDict<CSaveRestore::RestoreLookupTable,int>::RemoveAll(this: &this->m_RestoreLookup);
  if ( this->m_bClearSaveDir )
  {
    FinishAsyncSave = this->FinishAsyncSave;
    this->m_bClearSaveDir = false;
    FinishAsyncSave(this);
    v3 = this->IsXSave(this);
    CSaveRestore::DoClearSaveDir(this, bIsXSave: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195AB0
// Name: public: int CUtlDict<struct CSaveRestore::RestoreLookupTable,int>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CSaveRestore::RestoreLookupTable,int>::Insert(
        CUtlDict<CSaveRestore::RestoreLookupTable,int> *this,
        const char *pName)
{
  char *v2; // eax
  int v3; // esi
  CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t insert; // [esp+Ch] [ebp-28h] BYREF
  CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int> > *p_m_Tree; // [esp+30h] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v2, pName);
  else
    v2 = nullptr;
  memset(&insert.elem, 0, sizeof(insert.elem));
  insert.key = v2;
  v3 = CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         &insert);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&insert.elem);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10195B50
// Name: public: CSaveRestore::CSaveRestore(void)
// Source: json
//------------------------------------------------------------------------------
CSaveRestore *__thiscall CSaveRestore::CSaveRestore(CSaveRestore *this)
{
  CSaveRestore *result; // eax

  result = this;
  this->__vftable = (CSaveRestore_vtbl *)&CSaveRestore::`vftable';
  this->m_RestoreLookup.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_RestoreLookup.m_Elements.m_Tree.m_Root = -1;
  this->m_RestoreLookup.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_RestoreLookup.m_Elements.m_Tree.m_NumElements = 0;
  this->m_RestoreLookup.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_RestoreLookup.m_Elements.m_Tree.m_pElements = this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_RestoreLookup.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_RestoreLookup.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_sDeferredCommands.m_Memory.m_pMemory = nullptr;
  this->m_sDeferredCommands.m_Memory.m_nAllocationCount = 0;
  this->m_sDeferredCommands.m_Memory.m_nGrowSize = 0;
  this->m_sDeferredCommands.m_Size = 0;
  this->m_sDeferredCommands.m_pElements = nullptr;
  this->m_MostRecentSaveInfo.m_MostRecentSavePath[0] = 0;
  this->m_MostRecentSaveInfo.m_MostRecentSaveComment[0] = 0;
  this->m_MostRecentSaveInfo.m_LastAutosaveDangerousComment[0] = 0;
  this->m_MostRecentSaveInfo.m_bValid = false;
  this->m_bClearSaveDir = false;
  this->m_szSaveGameScreenshotFile[0] = 0;
  this->m_MostRecentElapsedMinutes = 0;
  this->m_MostRecentElapsedTimeSet = (int)g_ServerGlobalVariables.curtime;
  this->m_MostRecentElapsedSeconds = 0;
  this->m_MostRecentElapsedTimeSet = (int)g_ServerGlobalVariables.curtime;
  this->m_szMostRecentSaveLoadGame[0] = 0;
  this->m_szSaveGameName[0] = 0;
  *(_WORD *)&this->m_bIsXSave = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10195C10
// Name: public: virtual bool CSaveRestore::IsXSave(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSaveRestore::IsXSave(CSaveRestore *this)
{
  return this->m_bIsXSave && (save_noxsave.m_pParent == nullptr || save_noxsave.m_pParent->m_Value.m_nValue == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10195C40
// Name: public: virtual void CSaveRestore::FinishAsyncSave(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSaveRestore::FinishAsyncSave(CSaveRestore *this)
{
  FinishAsyncSave();
}

//------------------------------------------------------------------------------
// Address: 0x10195C50
// Name: private: struct CSaveRestore::RestoreLookupTable __near * CSaveRestore::FindOrAddRestoreLookupTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveRestore::RestoreLookupTable *__thiscall CSaveRestore::FindOrAddRestoreLookupTable(
        CSaveRestore *this,
        const char *mapname)
{
  int v3; // esi
  int v4; // eax
  CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t search; // [esp+8h] [ebp-24h] BYREF

  if ( mapname == nullptr
    || (memset(&search.elem, 0, sizeof(search.elem)),
        search.key = mapname,
        v3 = CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::Find(
               this: &this->m_RestoreLookup.m_Elements.m_Tree,
               &search),
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&search.elem),
        v4 = v3,
        v3 == -1) )
  {
    v4 = CUtlDict<CSaveRestore::RestoreLookupTable,int>::Insert(this: &this->m_RestoreLookup, pName: mapname);
  }
  return &this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10195CD0
// Name: private: void CSaveRestore::BuildRestoredIndexTranslationTable(char const __near *,class CSaveRestoreData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::BuildRestoredIndexTranslationTable(
        CSaveRestore *this,
        const char *mapname,
        CSaveRestoreData *pSaveData,
        bool verbose)
{
  int v5; // edi
  int v6; // eax
  CSaveRestoreData *v7; // edx
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *p_elem; // esi
  const char *v9; // eax
  CVTFTexture::ResourceMemorySection *m_pMemory; // edi
  int v11; // ecx
  int v12; // ebx
  int v13; // eax
  int m_nAllocationCount; // eax
  CVTFTexture::ResourceMemorySection *v15; // ecx
  int v16; // eax
  CVTFTexture::ResourceMemorySection *v17; // eax
  int savedindex; // ecx
  char name[256]; // [esp+Ch] [ebp-134h] BYREF
  CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t search; // [esp+10Ch] [ebp-34h] BYREF
  CSaveRestore::SaveRestoreTranslate slot; // [esp+130h] [ebp-10h]
  int tableCount; // [esp+13Ch] [ebp-4h]
  const char *mapnamea; // [esp+148h] [ebp+8h]

  V_FileBase(in: mapname, out: name, maxlen: 256);
  _V_strlower(start: name);
  memset(&search.elem, 0, sizeof(search.elem));
  search.key = name;
  v5 = CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::Find(
         this: &this->m_RestoreLookup.m_Elements.m_Tree,
         &search);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&search.elem);
  v6 = v5;
  if ( v5 == -1 )
    v6 = CUtlDict<CSaveRestore::RestoreLookupTable,int>::Insert(this: &this->m_RestoreLookup, pName: name);
  v7 = pSaveData;
  p_elem = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
  p_elem[1].m_pMemory = nullptr;
  p_elem[1].m_nGrowSize = 0;
  p_elem[2].m_pMemory = nullptr;
  p_elem[2].m_nAllocationCount = 0;
  if ( pSaveData->tableCount > 0 )
  {
    mapnamea = nullptr;
    tableCount = pSaveData->tableCount;
    do
    {
      v9 = &mapnamea[(unsigned int)v7->pTable];
      m_pMemory = p_elem[1].m_pMemory;
      v11 = *((_DWORD *)v9 + 2);
      v12 = *((_DWORD *)v9 + 8);
      v13 = *((_DWORD *)v9 + 3);
      slot.savedindex = v11;
      slot.restoredindex = v13;
      m_nAllocationCount = p_elem->m_nAllocationCount;
      if ( (int)&m_pMemory->m_nDataAllocSize + 1 > m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: p_elem,
          num: (int)&m_pMemory->m_nDataAllocSize - m_nAllocationCount + 1);
        v7 = pSaveData;
      }
      ++p_elem[1].m_pMemory;
      v15 = p_elem->m_pMemory;
      v16 = (char *)p_elem[1].m_pMemory - (char *)m_pMemory - 1;
      p_elem[1].m_nAllocationCount = (int)p_elem->m_pMemory;
      if ( v16 > 0 )
      {
        _V_memmove(dest: &v15[(int)m_pMemory + 1], src: &v15[(_DWORD)m_pMemory], count: 12 * v16);
        v7 = pSaveData;
      }
      v17 = &p_elem->m_pMemory[(_DWORD)m_pMemory];
      if ( v17 != nullptr )
      {
        savedindex = slot.savedindex;
        v17->m_nDataAllocSize = v12;
        v17->m_nDataLength = savedindex;
        v17->m_pData = (unsigned __int8 *)slot.restoredindex;
      }
      mapnamea += 56;
      --tableCount;
    }
    while ( tableCount != 0 );
  }
  *(float *)&p_elem[1].m_nGrowSize = v7->levelInfo.vecLandmarkOffset.x;
  *(float *)&p_elem[2].m_pMemory = v7->levelInfo.vecLandmarkOffset.y;
  *(float *)&p_elem[2].m_nAllocationCount = v7->levelInfo.vecLandmarkOffset.z;
}

//------------------------------------------------------------------------------
// Address: 0x10195E50
// Name: private: int CSaveRestore::SaveReadHeader(void __near *,struct GAME_HEADER __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge CSaveRestore::SaveReadHeader@<eax>(
        CSaveRestore *this@<ecx>,
        int a2@<edi>,
        void *pFile,
        GAME_HEADER *pHeader,
        int readGlobalState)
{
  void *v5; // ebx
  CSaveRestoreData *v7; // eax
  CSaveRestoreData *v8; // esi
  char *v9; // edi
  int v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // ecx
  int i; // ebx
  int v14; // eax
  int tokenSize; // [esp+4h] [ebp-14h] BYREF
  int tag; // [esp+8h] [ebp-10h] BYREF
  CSaveRestore *v18; // [esp+Ch] [ebp-Ch]
  int size; // [esp+10h] [ebp-8h] BYREF
  int tokenCount; // [esp+14h] [ebp-4h] BYREF

  v5 = pFile;
  v18 = this;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 4, a4: pFile) != 4 )
    return false;
  if ( tag != 1447121738 )
  {
    _Warning(a1: "Can't load saved game, incorrect FILEID\n");
    return false;
  }
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 4, a4: pFile) != 4 )
    return false;
  if ( tag != 116 )
  {
    _Warning(a1: "Can't load saved game, incorrect version (got %i expecting %i)\n", tag, 116);
    return false;
  }
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &size, a3: 4, a4: pFile) != 4 )
    return false;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tokenCount, a3: 4, a4: pFile) != 4 )
    return false;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tokenSize, a3: 4, a4: pFile) != 4 )
    return false;
  v7 = (CSaveRestoreData *)SaveAllocMemory(num: tokenSize + size + 1444, size: 1u, bClear: false);
  if ( v7 == nullptr )
    return false;
  v8 = CSaveRestoreData::CSaveRestoreData(this: v7);
  v8->levelInfo.connectionCount = 0;
  v9 = (char *)&v8[1];
  if ( tokenSize <= 0 )
  {
    v8->tokenCount = 0;
    v8->pTokens = nullptr;
  }
  else
  {
    v10 = g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &v8[1], a3: tokenSize, a4: pFile);
    if ( v10 != tokenSize )
      goto LABEL_21;
    v11 = (unsigned __int8 *)SaveAllocMemory(num: tokenCount, size: 4u, bClear: true);
    if ( v11 == nullptr )
      goto LABEL_21;
    v12 = tokenCount;
    v8->tokenCount = tokenCount;
    v8->pTokens = (char **)v11;
    memset(dst: v11, value: 0, count: 4 * v12);
    for ( i = 0; i < tokenCount; ++i )
    {
      if ( *v9 != 0 )
        CSaveRestoreSegment::DefineSymbol(this: v8, pszToken: v9, token: i);
      v9 += strlen(v9) + 1;
    }
    v5 = pFile;
  }
  v8->levelInfo.fUseLandmark = 0;
  v8->levelInfo.time = 0.0;
  v8->bufferSize = size;
  v8->pBaseData = v9;
  v8->pCurrentData = v9;
  v8->size = 0;
  v14 = g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: v9, a3: size, a4: v5);
  if ( v14 != size )
  {
LABEL_21:
    v18->Finish(this: v18, a2: v8);
    return false;
  }
  ((void (__thiscall *)(IServerGameDLL *, CSaveRestoreData *, const char *, GAME_HEADER *, _DWORD, typedescription_t *, int, int))serverGameDLL->SaveReadFields)(
    a1: serverGameDLL,
    a2: v8,
    a3: "GameHeader",
    a4: pHeader,
    a5: 0,
    a6: GAME_HEADER::m_DataMap.dataDesc,
    a7: GAME_HEADER::m_DataMap.dataNumFields,
    a8: a2);
  if ( g_szMapLoadOverride[0] != 0 )
  {
    V_strncpy(pDest: pHeader->mapName, pSrc: g_szMapLoadOverride, maxLen: 32);
    g_szMapLoadOverride[0] = 0;
  }
  if ( readGlobalState != 0 )
    serverGameDLL->RestoreGlobalState(this: serverGameDLL, a2: v8);
  v18->Finish(this: v18, a2: v8);
  return pHeader->mapCount != 0
      || g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &pHeader->mapCount, a3: 4, a4: v5) == 4;
}

//------------------------------------------------------------------------------
// Address: 0x101960C0
// Name: public: virtual bool CSaveRestore::LoadGame(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CSaveRestore::LoadGame@<al>(
        CSaveRestore *this@<ecx>,
        int a2@<ebx>,
        const char *pName,
        bool bLetToolsOverrideLoadGameEnts)
{
  void (__thiscall *FinishAsyncSave)(struct CSaveRestore *); // edx
  bool (__thiscall *IsXSave)(struct CSaveRestore *); // eax
  bool v8; // al
  void *(__thiscall *Open)(ISaveRestoreFileSystem *, const char *, const char *, const char *); // edx
  void *v10; // edi
  int v11; // kr00_4
  bool v12; // al
  int v13; // edx
  bool v14; // al
  void (__thiscall *SetMostRecentElapsedMinutes)(struct CSaveRestore *, const int); // edx
  bool v16; // bl
  char szDummyName[260]; // [esp+8h] [ebp-5ACh] BYREF
  char szComment[260]; // [esp+10Ch] [ebp-4A8h] BYREF
  char szElapsedTime[260]; // [esp+210h] [ebp-3A4h] BYREF
  char name[260]; // [esp+314h] [ebp-2A0h] BYREF
  GAME_HEADER gameHeader; // [esp+418h] [ebp-19Ch] BYREF
  int iElapsedSeconds; // [esp+5ACh] [ebp-8h]
  bool validload; // [esp+5B3h] [ebp-1h]
  int iElapsedMinutes; // [esp+5BCh] [ebp+8h]

  FinishAsyncSave = this->FinishAsyncSave;
  validload = false;
  FinishAsyncSave(this);
  SaveResetMemory();
  if ( CSaveRestore::CalcSaveGameName(this, pName, output: name, outputStringLength: 260) )
  {
    this->SetMostRecentSaveGame(this, a2: pName);
    ConMsg(a1: "Loading game from %s...\n", name);
    IsXSave = this->IsXSave;
    this->m_bClearSaveDir = false;
    v8 = IsXSave(this);
    CSaveRestore::DoClearSaveDir(this, bIsXSave: v8);
    Open = g_pSaveRestoreFileSystem->Open;
    iElapsedMinutes = 0;
    iElapsedSeconds = 0;
    v10 = Open(this: g_pSaveRestoreFileSystem, a2: name, a3: "rb", a4: "MOD");
    if ( v10 != nullptr )
    {
      if ( ((int (__thiscall *)(CSaveRestore *, void *, char *, char *, int))this->SaveReadNameAndComment)(
             a1: this,
             a2: v10,
             a3: szDummyName,
             a4: szComment,
             a5: a2) != 0 )
      {
        v11 = strlen(szComment);
        V_strncpy(pDest: szElapsedTime, pSrc: "??", maxLen: 260);
        if ( v11 >= 6 )
        {
          V_strncpy(pDest: szElapsedTime, pSrc: &szDummyName[v11 + 254], maxLen: 7);
          szElapsedTime[6] = 0;
          iElapsedMinutes = atoi(nptr: szElapsedTime);
          iElapsedSeconds = atoi(nptr: &szElapsedTime[4]);
        }
        ((void (__thiscall *)(ISaveRestoreFileSystem *))g_pSaveRestoreFileSystem->Seek)(a1: g_pSaveRestoreFileSystem);
        if ( CSaveRestore::SaveReadHeader(this, pFile: v10, pHeader: &gameHeader, readGlobalState: 1) != 0 )
          validload = CSaveRestore::DirectoryExtract(this, pFile: v10, fileCount: gameHeader.mapCount);
        if ( ((int (__thiscall *)(IVEngineServer *))g_pVEngineServer->IsMapValid)(a1: g_pVEngineServer) == 0 )
        {
          _Msg(a1: "Map '%s' missing or invalid\n", gameHeader.mapName);
          validload = false;
        }
        ((void (__thiscall *)(ISaveRestoreFileSystem *))g_pSaveRestoreFileSystem->Close)(a1: g_pSaveRestoreFileSystem);
        if ( validload )
        {
          GetBaseLocalClient()->demonum = -1;
          CLoaderMemAlloc::CrtIsValidPointer(
            this: (ConVar *)&deathmatch.IConVar,
            value: 0,
            a2: (unsigned int)v10,
            a3: (int)&gameHeader);
          CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&coop.IConVar, value: 0, a2: (unsigned int)v10, a3: 0);
          if ( CL_HL2Demo_MapCheck(name: gameHeader.mapName) && CL_PortalDemo_MapCheck(name: gameHeader.mapName) )
          {
            v12 = gameHeader.originMapName[0] != 0;
            v13 = -(gameHeader.originMapName[0] != 0);
            this->m_bOverrideLoadGameEntsOn = bLetToolsOverrideLoadGameEnts;
            v14 = Host_NewGame(
                    mapName: gameHeader.mapName,
                    loadGame: true,
                    bBackgroundLevel: false,
                    bSplitScreenConnect: false,
                    pszOldMap: v12 ? gameHeader.originMapName : nullptr,
                    pszLandmark: (const char *)((unsigned int)gameHeader.landmark & v13));
            SetMostRecentElapsedMinutes = this->SetMostRecentElapsedMinutes;
            v16 = v14;
            this->m_bOverrideLoadGameEntsOn = false;
            SetMostRecentElapsedMinutes(this, a2: iElapsedMinutes);
            this->SetMostRecentElapsedSeconds(this, a2: iElapsedSeconds);
            return v16;
          }
          else
          {
            _Warning(a1: "Save file %s is not valid\n", name);
            return false;
          }
        }
        else
        {
          _Msg(a1: "Save file %s is not valid\n", name);
          return false;
        }
      }
      else
      {
        g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v10);
        return false;
      }
    }
    else
    {
      ConMsg(a1: "File not found or failed to open.\n");
      return false;
    }
  }
  else
  {
    DevWarning(a1: "Loaded bad game %s\n", pName);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101963F0
// Name: public: virtual void CSaveRestore::Finish(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::Finish(CSaveRestore *this, CSaveRestoreData *save)
{
  char **pTokens; // eax
  entitytable_t *pTable; // eax

  _Msg(
    a1: "SAVEGAME: %6.1fkb, %6.1fkb used by %3d entities (%s)\n",
    0.0009765625 * (double)save->size,
    (double)save->m_nEntityDataSize * 0.0009765625,
    save->tableCount,
    sv.m_szMapname);
  pTokens = save->pTokens;
  save->tokenCount = 0;
  save->pTokens = nullptr;
  if ( pTokens != nullptr )
    SaveFreeMemory(pSaveMem: pTokens);
  pTable = save->pTable;
  save->pTable = nullptr;
  save->tableCount = 0;
  if ( pTable != nullptr )
    SaveFreeMemory(pSaveMem: pTable);
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &save->m_EntityToIndex);
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &save->m_EntityToIndex);
  CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::~CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>(this: &save->m_EntityToIndex.m_Buckets);
  DevMsg(a1: "Freeing %d bytes of save data\n", save->size);
  SaveFreeMemory(pSaveMem: save);
  g_ServerGlobalVariables.pSaveData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101964B0
// Name: public: virtual void CSaveRestore::RestoreClientState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveRestore::RestoreClientState(
        CSaveRestore *this@<ecx>,
        int a2@<esi>,
        const char *fileName,
        bool adjacent)
{
  void (__thiscall *FinishAsyncSave)(struct CSaveRestore *); // edx
  void *v5; // edi
  bool v6; // al
  ISaveRestoreFileSystem_vtbl *v7; // edx
  int v8; // esi
  ISaveRestoreFileSystem_vtbl *v9; // eax
  ISaveRestoreFileSystem_vtbl *v10; // edx
  CSaveRestoreData *v11; // eax
  CSaveRestoreData *v12; // esi
  const char *v13; // edi
  unsigned __int8 *v14; // eax
  int j; // ecx
  char **pTokens; // eax
  bool v17; // zf
  const char **v18; // eax
  int v19; // eax
  char *pCurrentData; // ecx
  CSaveRestore *v21; // edi
  CSaveRestore::RestoreLookupTable *v22; // ebx
  int tableCount; // eax
  int m_Size; // edi
  entitytable_t *v25; // eax
  int v26; // ecx
  CSaveRestore::SaveRestoreTranslate *m_pMemory; // edx
  int restoredindex; // edx
  const char *pszValue; // eax
  CClientState *BaseLocalClient; // eax
  int v31; // edi
  INetworkStringTable *ModelPrecacheTable; // eax
  INetworkStringTable *v33; // eax
  const char *v34; // eax
  const char *v35; // ebx
  INetworkStringTable *m_pModelPrecacheTable; // eax
  const char *v37; // ecx
  INetworkStringTable *v38; // eax
  int m; // edi
  int v40; // ecx
  int v41; // eax
  CSaveRestore::SaveRestoreTranslate *v42; // edx
  int v43; // edx
  unsigned int v44; // [esp-8h] [ebp-204h]
  void *v45; // [esp-4h] [ebp-200h]
  char name[256]; // [esp+8h] [ebp-1F4h] BYREF
  channelsave channel; // [esp+108h] [ebp-F4h] BYREF
  int v48; // [esp+18Ch] [ebp-70h]
  SaveFileHeaderTag_t tag; // [esp+1A4h] [ebp-58h] BYREF
  baseclientsectionsold_t oldsections; // [esp+1ACh] [ebp-50h] BYREF
  int magicnumber; // [esp+1C4h] [ebp-38h] BYREF
  int sectionheaderversion; // [esp+1C8h] [ebp-34h] BYREF
  int k; // [esp+1CCh] [ebp-30h]
  baseclientsections_t sections; // [esp+1D0h] [ebp-2Ch] BYREF
  unsigned int v55; // [esp+1F0h] [ebp-Ch]
  CSaveRestore *v56; // [esp+1F4h] [ebp-8h]
  CSaveRestore::RestoreLookupTable *table; // [esp+1F8h] [ebp-4h]
  int i; // [esp+204h] [ebp+8h]
  char i_3; // [esp+207h] [ebp+Bh]

  FinishAsyncSave = this->FinishAsyncSave;
  v56 = this;
  ((void (__fastcall *)(CSaveRestore *))FinishAsyncSave)(a1: this);
  v5 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: fileName, a3: "rb", a4: nullptr);
  if ( v5 == nullptr )
  {
    DevMsg(a1: "Failed to open client state file %s\n", fileName);
    return;
  }
  g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 8, a4: v5);
  v6 = SaveFileHeaderTag_t::operator!=(this: &tag, rhs: &CURRENT_SAVEFILE_HEADER_TAG);
  v7 = g_pSaveRestoreFileSystem->__vftable;
  if ( v6 )
  {
    ((void (__stdcall *)(void *))v7->Close)(a1: v5);
    return;
  }
  v8 = ((int (__stdcall *)(void *, int))v7->Tell)(a1: v5, a2);
  sectionheaderversion = 1;
  magicnumber = 0;
  g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &magicnumber, a3: 4, a4: v5);
  v9 = g_pSaveRestoreFileSystem->__vftable;
  if ( magicnumber == 1414795828 )
  {
    ((void (__stdcall *)(int *, int, void *))v9->Read)(a1: &sectionheaderversion, a2: 4, a3: v5);
    v10 = g_pSaveRestoreFileSystem->__vftable;
    v45 = v5;
    if ( sectionheaderversion != 2 )
    {
      ((void (*)(void))v10->Close)();
      return;
    }
    ((void (__stdcall *)(baseclientsections_t *, int))v10->Read)(a1: &sections, a2: 32);
  }
  else
  {
    v45 = nullptr;
    ((void (__stdcall *)(void *, int))v9->Seek)(a1: v5, a2: v8);
    g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &oldsections, a3: 24, a4: v5);
    _V_memset(dest: &sections, fill: 0, count: 32);
    sections.entitysize = oldsections.entitysize;
    sections.headersize = oldsections.headersize;
    sections.decalsize = oldsections.decalsize;
    sections.symbolsize = oldsections.symbolsize;
    sections.decalcount = oldsections.decalcount;
    sections.symbolcount = oldsections.symbolcount;
  }
  v11 = (CSaveRestoreData *)SaveAllocMemory(
                              num: sections.entitysize
                            + sections.headersize
                            + sections.decalsize
                            + sections.channelsize
                            + sections.symbolsize
                            + 1444,
                              size: 1u,
                              bClear: false);
  if ( v11 != nullptr )
  {
    v12 = CSaveRestoreData::CSaveRestoreData(this: v11);
    V_strncpy(pDest: v12->levelInfo.szCurrentMapName, pSrc: fileName, maxLen: 32);
    g_pSaveRestoreFileSystem->Read(
      this: g_pSaveRestoreFileSystem,
      a2: &v12[1],
      a3: sections.entitysize + sections.headersize + sections.decalsize + sections.symbolsize + sections.channelsize,
      a4: v5);
    g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v5);
    v13 = (const char *)&v12[1];
    if ( sections.symbolsize <= 0 )
    {
      v12->tokenCount = 0;
      v12->pTokens = nullptr;
    }
    else
    {
      v14 = (unsigned __int8 *)SaveAllocMemory(num: sections.symbolcount, size: 4u, bClear: true);
      if ( v14 == nullptr )
      {
        SaveFreeMemory(pSaveMem: v12);
        return;
      }
      v44 = 4 * sections.symbolcount;
      v12->tokenCount = sections.symbolcount;
      v12->pTokens = (char **)v14;
      memset(dst: v14, value: 0, count: v44);
      for ( j = 0; j < sections.symbolcount; ++j )
      {
        if ( *v13 != 0 )
        {
          pTokens = v12->pTokens;
          v17 = pTokens[j] == nullptr;
          v18 = (const char **)&pTokens[j];
          if ( v17 )
            *v18 = v13;
        }
        v13 += strlen(v13) + 1;
      }
    }
    v19 = sections.entitysize + sections.headersize + sections.channelsize + sections.decalsize;
    v12->pBaseData = (char *)v13;
    v12->bufferSize = v19;
    v12->pCurrentData = (char *)v13;
    v12->size = 0;
    ((void (__thiscall *)(IBaseClientDLL *, CSaveRestoreData *, void *))g_ClientDLL->ReadRestoreHeaders)(
      a1: g_ClientDLL,
      a2: v12,
      a3: v45);
    pCurrentData = v12->pCurrentData;
    v12->bufferSize -= v12->size;
    v21 = v56;
    v12->pBaseData = pCurrentData;
    v12->size = 0;
    v12->levelInfo.time = v21->m_flClientSaveRestoreTime;
    V_FileBase(in: fileName, out: name, maxlen: 256);
    _V_strlower(start: name);
    v22 = CSaveRestore::FindOrAddRestoreLookupTable(this: v21, mapname: name);
    table = v22;
    v12->levelInfo.fUseLandmark = adjacent;
    if ( adjacent )
    {
      v12->levelInfo.vecLandmarkOffset.x = v22->m_vecLandMarkOffset.x;
      v12->levelInfo.vecLandmarkOffset.y = v22->m_vecLandMarkOffset.y;
      v12->levelInfo.vecLandmarkOffset.z = v22->m_vecLandMarkOffset.z;
    }
    tableCount = v12->tableCount;
    i_3 = 0;
    if ( tableCount > 0 )
    {
      v55 = 0;
      for ( k = tableCount; k != 0; --k )
      {
        m_Size = v22->lookup.m_Size;
        v25 = &v12->pTable[v55 / 0x38];
        v26 = 0;
        if ( m_Size <= 0 )
        {
LABEL_30:
          restoredindex = -1;
        }
        else
        {
          m_pMemory = v22->lookup.m_Memory.m_pMemory;
          while ( m_pMemory->savedindex != v25->saveentityindex )
          {
            ++v26;
            ++m_pMemory;
            if ( v26 >= m_Size )
            {
              v22 = table;
              goto LABEL_30;
            }
          }
          restoredindex = m_pMemory->restoredindex;
          v22 = table;
        }
        v25->restoreentityindex = restoredindex;
        if ( restoredindex == -1 && v25->classname.pszValue != nullptr && v25->modelname.pszValue != nullptr )
        {
          pszValue = v25->modelname.pszValue;
          if ( pszValue == nullptr )
            pszValue = defaultValue;
          CGameServer::PrecacheModel(this: &sv, a2: (int)v22, a3: m_Size, name: pszValue, flags: 3, model: nullptr);
          i_3 = 1;
        }
        v55 += 56;
      }
      if ( i_3 == 1 )
      {
        BaseLocalClient = GetBaseLocalClient();
        v31 = BaseLocalClient->m_pModelPrecacheTable->GetNumStrings(this: BaseLocalClient->m_pModelPrecacheTable);
        ModelPrecacheTable = CGameServer::GetModelPrecacheTable(this: &sv);
        if ( v31 < ModelPrecacheTable->GetNumStrings(this: ModelPrecacheTable) )
        {
          do
          {
            v33 = CGameServer::GetModelPrecacheTable(this: &sv);
            v34 = v33->GetString(this: v33, a2: v31);
            if ( v34 != nullptr && *v34 != 0 )
              v35 = v34;
            else
              v35 = nullptr;
            m_pModelPrecacheTable = GetBaseLocalClient()->m_pModelPrecacheTable;
            v37 = v35;
            if ( v35 == nullptr )
              v37 = defaultValue;
            m_pModelPrecacheTable->AddString(this: m_pModelPrecacheTable, a2: true, a3: v37, a4: -1, a5: nullptr);
            ++v31;
            v38 = CGameServer::GetModelPrecacheTable(this: &sv);
          }
          while ( v31 < v38->GetNumStrings(this: v38) );
          v22 = table;
        }
      }
    }
    g_ClientDLL->Restore(this: g_ClientDLL, a2: v12, a3: false);
    if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
    {
      for ( m = 0; m < sections.decalcount; ++m )
      {
        g_ClientDLL->SaveReadFields(
          this: g_ClientDLL,
          a2: v12,
          a3: "DECALLIST",
          a4: &channel,
          a5: nullptr,
          a6: decallist_t::m_DataMap.dataDesc,
          a7: decallist_t::m_DataMap.dataNumFields);
        CSaveRestore::ReapplyDecal(this: v56, adjacent, table: v22, entry: (decallist_t *)&channel);
      }
    }
    for ( i = 0; i < sections.channelcount; ++i )
    {
      g_ClientDLL->SaveReadFields(
        this: g_ClientDLL,
        a2: v12,
        a3: "CHANNELLIST",
        a4: &channel.soundName[52],
        a5: nullptr,
        a6: channelsave::m_DataMap.dataDesc,
        a7: channelsave::m_DataMap.dataNumFields);
      v40 = v22->lookup.m_Size;
      v41 = 0;
      if ( v40 <= 0 )
      {
LABEL_58:
        v43 = -1;
      }
      else
      {
        v42 = v22->lookup.m_Memory.m_pMemory;
        while ( v42->savedindex != v48 )
        {
          ++v41;
          ++v42;
          if ( v41 >= v40 )
            goto LABEL_58;
        }
        v43 = v42->restoredindex;
      }
      v48 = v43;
      S_RestartChannel(channelSave: (const channelsave *)&channel.soundName[52]);
    }
    ((void (__thiscall *)(CSaveRestore *))v56->Finish)(a1: v56);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101969E0
// Name: private: class CSaveRestoreData __near * CSaveRestore::LoadSaveData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CSaveRestore::LoadSaveData(CSaveRestore *this, const char *level)
{
  bool (__thiscall *IsXSave)(struct CSaveRestore *); // edx
  const char *v4; // eax
  int v5; // eax
  void *v6; // eax
  void *v7; // ebx
  CSaveRestoreData *v9; // eax
  CSaveRestoreData *v10; // esi
  int v11; // edi
  int v12; // ebx
  const char *v13; // edi
  unsigned __int8 *v14; // eax
  int v15; // eax
  int v16; // [esp-Ch] [ebp-138h]
  const char *v17; // [esp-4h] [ebp-130h]
  unsigned int v18; // [esp-4h] [ebp-130h]
  char name[260]; // [esp+Ch] [ebp-120h] BYREF
  SaveFileHeaderTag_t tag; // [esp+110h] [ebp-1Ch] BYREF
  CSaveRestore *v21; // [esp+118h] [ebp-14h]
  SaveFileSectionsInfo_t sectionsInfo; // [esp+11Ch] [ebp-10h] BYREF

  IsXSave = this->IsXSave;
  v21 = this;
  if ( ((unsigned __int8 (__fastcall *)(CSaveRestore *))IsXSave)(a1: this) != 0 )
  {
    name[0] = 0;
    v16 = 260 - _V_strlen(str: name);
    v5 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v5], maxLen: v16, pFormat: "//mod/%s.HL1", level);
  }
  else
  {
    v4 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: level);
    V_snprintf(pDest: name, maxLen: 260, pFormat: "//%s/%s%s.HL1", "MOD", v4, v17);
  }
  ConMsg(a1: "Loading game from %s...\n", name);
  v6 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: name, a3: "rb", a4: nullptr);
  v7 = v6;
  if ( v6 == nullptr )
  {
    ConMsg(a1: "ERROR: couldn't open.\n");
    return nullptr;
  }
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 8, a4: v6) != 8 )
    return nullptr;
  if ( SaveFileHeaderTag_t::operator!=(this: &tag, rhs: &CURRENT_SAVEFILE_HEADER_TAG) )
    return nullptr;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &sectionsInfo, a3: 16, a4: v7) != 16 )
    return nullptr;
  v9 = (CSaveRestoreData *)SaveAllocMemory(
                             num: sectionsInfo.nBytesSymbols
                           + sectionsInfo.nBytesData
                           + sectionsInfo.nBytesDataHeaders
                           + 1444,
                             size: 1u,
                             bClear: false);
  if ( v9 == nullptr )
    return nullptr;
  v10 = CSaveRestoreData::CSaveRestoreData(this: v9);
  V_strncpy(pDest: v10->levelInfo.szCurrentMapName, pSrc: level, maxLen: 32);
  v11 = sectionsInfo.nBytesSymbols + sectionsInfo.nBytesData + sectionsInfo.nBytesDataHeaders;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &v10[1], a3: v11, a4: v7) != v11 )
  {
    v21->Finish(this: v21, a2: v10);
    return nullptr;
  }
  g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v7);
  v12 = 0;
  v13 = (const char *)&v10[1];
  if ( sectionsInfo.nBytesSymbols <= 0 )
  {
    v10->tokenCount = 0;
    v10->pTokens = nullptr;
  }
  else
  {
    v14 = (unsigned __int8 *)SaveAllocMemory(num: sectionsInfo.nSymbols, size: 4u, bClear: true);
    if ( v14 == nullptr )
    {
      SaveFreeMemory(pSaveMem: v10);
      return nullptr;
    }
    v18 = 4 * sectionsInfo.nSymbols;
    v10->tokenCount = sectionsInfo.nSymbols;
    v10->pTokens = (char **)v14;
    memset(dst: v14, value: 0, count: v18);
    if ( sectionsInfo.nSymbols > 0 )
    {
      do
      {
        if ( *v13 != 0 )
          CSaveRestoreSegment::DefineSymbol(this: v10, pszToken: v13, token: v12);
        v13 += strlen(v13) + 1;
        ++v12;
      }
      while ( v12 < sectionsInfo.nSymbols );
    }
  }
  v15 = sectionsInfo.nBytesData + sectionsInfo.nBytesDataHeaders;
  v10->levelInfo.connectionCount = 0;
  v10->pBaseData = (char *)v13;
  v10->pCurrentData = (char *)v13;
  v10->size = 0;
  v10->bufferSize = v15;
  v10->levelInfo.fUseLandmark = 1;
  v10->levelInfo.time = 0.0;
  v10->levelInfo.vecLandmarkOffset = vec3_origin;
  g_ServerGlobalVariables.pSaveData = v10;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10196C70
// Name: public: virtual int CSaveRestore::LoadGameState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CSaveRestore::LoadGameState(CSaveRestore *this, const char *level, BOOL createPlayers)
{
  CSaveRestoreData *result; // eax
  CSaveRestoreData *v5; // esi
  CSaveRestore_vtbl *v6; // eax
  int v7; // [esp+0h] [ebp-70h]
  SAVE_HEADER header; // [esp+Ch] [ebp-64h] BYREF
  ConVarRef skyname; // [esp+68h] [ebp-8h] BYREF

  V_FileBase(in: level, out: ::level, maxlen: 256);
  result = CSaveRestore::LoadSaveData(this, level: ::level);
  v5 = result;
  if ( result != nullptr )
  {
    ((void (__thiscall *)(IServerGameDLL *))serverGameDLL->ReadRestoreHeaders)(a1: serverGameDLL);
    CSaveRestore::ParseSaveTables(this, pSaveData: v5, pHeader: &header, updateGlobals: 1);
    CSaveRestore::EntityPatchRead(this, pSaveData: v5, level);
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&skill.IConVar,
      value: header.skillLevel,
      a2: (unsigned int)v5,
      a3: v7);
    V_strncpy(pDest: sv.m_szMapname, pSrc: header.mapName, maxLen: 64);
    ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname");
    if ( ConVarRef::IsValid(this: &skyname) )
      skyname.m_pConVar->SetValue_4(this: skyname.m_pConVar, a2: header.skyName);
    serverGameDLL->Restore(this: serverGameDLL, a2: v5, a3: createPlayers);
    CSaveRestore::BuildRestoredIndexTranslationTable(this, mapname: level, pSaveData: v5, verbose: false);
    v6 = this->__vftable;
    this->m_flClientSaveRestoreTime = v5->levelInfo.time;
    v6->Finish(this, a2: v5);
    sv.m_nTickCount = (int)(float)(header.time / host_state.interval_per_tick);
    return (CSaveRestoreData *)1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10196D70
// Name: public: virtual void CSaveRestore::LoadAdjacentEnts(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveRestore::LoadAdjacentEnts(
        CSaveRestore *this@<ecx>,
        CSaveRestoreData *a2@<edi>,
        const char *pOldLevel,
        const char *pLandmarkName)
{
  CSaveRestore *v4; // ebx
  void (__thiscall *FinishAsyncSave)(struct CSaveRestore *); // edx
  levellist_t *levelList; // edi
  int v7; // esi
  CSaveRestoreData *SaveData; // esi
  int v9; // edi
  float z; // xmm0_4
  char *v11; // ecx
  int j; // edi
  const char *mapName; // ebx
  vgui::CTreeViewListControl *v14; // ecx
  ECommandTarget_t TraceType; // eax
  CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> > *m_pMemory; // eax
  Vector *p_vecLandmarkOrigin; // eax
  char *m_szBuf; // [esp-8h] [ebp-744h]
  CFmtStrN<256> v20; // [esp+8h] [ebp-734h] BYREF
  SAVE_HEADER header; // [esp+114h] [ebp-628h] BYREF
  CSaveRestoreData currentLevelData; // [esp+170h] [ebp-5CCh] BYREF
  int movedCount; // [esp+714h] [ebp-28h]
  Vector landmarkOrigin; // [esp+718h] [ebp-24h]
  CSaveRestore *v25; // [esp+724h] [ebp-18h]
  char *s1; // [esp+728h] [ebp-14h]
  int i; // [esp+72Ch] [ebp-10h]
  char *in; // [esp+730h] [ebp-Ch]
  int flags; // [esp+734h] [ebp-8h]
  bool foundprevious; // [esp+73Bh] [ebp-1h]

  v4 = this;
  FinishAsyncSave = this->FinishAsyncSave;
  v25 = this;
  ((void (__fastcall *)(CSaveRestore *))FinishAsyncSave)(a1: this);
  CSaveRestoreData::CSaveRestoreData(this: &currentLevelData);
  movedCount = 0;
  memset(dst: (unsigned __int8 *)&currentLevelData, value: 0, count: sizeof(currentLevelData));
  g_ServerGlobalVariables.pSaveData = &currentLevelData;
  serverGameDLL->BuildAdjacentMapList(this: serverGameDLL);
  foundprevious = false;
  i = 0;
  if ( currentLevelData.levelInfo.connectionCount > 0 )
  {
    levelList = currentLevelData.levelInfo.levelList;
    in = currentLevelData.levelInfo.levelList[0].mapName;
    do
    {
      if ( _V_stricmp(s1: levelList->mapName, s2: pOldLevel) == 0 )
        foundprevious = true;
      v7 = 0;
      if ( i <= 0 )
        goto LABEL_11;
      flags = (int)currentLevelData.levelInfo.levelList;
      while ( _V_stricmp(s1: levelList->mapName, s2: (const char *)flags) != 0 )
      {
        flags += 80;
        if ( ++v7 >= i )
          goto LABEL_11;
      }
      if ( v7 >= i )
      {
LABEL_11:
        V_FileBase(in: levelList->mapName, out: level, maxlen: 256);
        SaveData = CSaveRestore::LoadSaveData(this: v4, level: level);
        if ( SaveData != nullptr )
        {
          ((void (__thiscall *)(IServerGameDLL *, CSaveRestoreData *, CSaveRestoreData *))serverGameDLL->ReadRestoreHeaders)(
            a1: serverGameDLL,
            a2: SaveData,
            a3: a2);
          CSaveRestore::ParseSaveTables(this: v4, pSaveData: SaveData, pHeader: &header, updateGlobals: 0);
          CSaveRestore::EntityPatchRead(this: v4, pSaveData: SaveData, level: levelList->mapName);
          SaveData->levelInfo.time = CBaseServer::GetTime(this: &sv);
          v9 = 0;
          SaveData->levelInfo.fUseLandmark = 1;
          flags = 0;
          if ( currentLevelData.levelInfo.connectionCount <= 0 )
          {
LABEL_16:
            landmarkOrigin.x = vec3_origin.x;
            landmarkOrigin.y = vec3_origin.y;
            z = vec3_origin.z;
          }
          else
          {
            s1 = currentLevelData.levelInfo.levelList[0].landmarkName;
            while ( _V_stricmp(s1, s2: pLandmarkName) != 0 )
            {
              s1 += 80;
              if ( ++v9 >= currentLevelData.levelInfo.connectionCount )
                goto LABEL_16;
            }
            p_vecLandmarkOrigin = &currentLevelData.levelInfo.levelList[v9].vecLandmarkOrigin;
            landmarkOrigin.x = p_vecLandmarkOrigin->x;
            landmarkOrigin.y = p_vecLandmarkOrigin->y;
            z = p_vecLandmarkOrigin->z;
          }
          landmarkOrigin.z = z;
          LandmarkOrigin(pSaveData: SaveData, output: &SaveData->levelInfo.vecLandmarkOffset, pLandmarkName);
          v11 = in;
          SaveData->levelInfo.vecLandmarkOffset.x = landmarkOrigin.x - SaveData->levelInfo.vecLandmarkOffset.x;
          SaveData->levelInfo.vecLandmarkOffset.y = landmarkOrigin.y - SaveData->levelInfo.vecLandmarkOffset.y;
          SaveData->levelInfo.vecLandmarkOffset.z = landmarkOrigin.z - SaveData->levelInfo.vecLandmarkOffset.z;
          if ( _V_stricmp(s1: v11, s2: pOldLevel) == 0 )
            flags = 0x80000000;
          for ( j = -1; ++j < SaveData->levelInfo.connectionCount; flags |= 1 << j )
          {
            mapName = SaveData->levelInfo.levelList[j].mapName;
            while ( _V_stricmp(s1: mapName, s2: sv.m_szMapname) != 0 )
            {
              ++j;
              mapName += 80;
              if ( j >= SaveData->levelInfo.connectionCount )
                goto LABEL_24;
            }
            if ( j < 0 )
            {
LABEL_24:
              v4 = v25;
              break;
            }
            v4 = v25;
          }
          if ( flags != 0 )
            movedCount = serverGameDLL->CreateEntityTransitionList(this: serverGameDLL, a2: SaveData, a3: flags);
          if ( movedCount != 0 )
          {
            V_FileBase(in, out: level, maxlen: 256);
            CSaveRestore::EntityPatchWrite(this: v4, pSaveData: SaveData, level: level, bAsync: false);
          }
          CSaveRestore::BuildRestoredIndexTranslationTable(this: v4, mapname: in, pSaveData: SaveData, verbose: true);
          a2 = SaveData;
          ((void (__thiscall *)(CSaveRestore *))v4->Finish)(a1: v4);
          levelList = (levellist_t *)in;
        }
      }
      ++levelList;
      ++i;
      in = (char *)levelList;
    }
    while ( i < currentLevelData.levelInfo.connectionCount );
  }
  g_ServerGlobalVariables.pSaveData = nullptr;
  if ( !foundprevious )
  {
    _Warning(
      a1: "\nLevel transition ERROR\nCan't find connection to %s from %s\nFalling back to 'map' command...\n\n",
      pOldLevel,
      sv.m_szMapname);
    m_szBuf = CFmtStrN<256>::CFmtStrN<256>(this: &v20, pszFormat: "disconnect; map %s\n", sv.m_szMapname)->m_szBuf;
    TraceType = CTraceFilter::GetTraceType(this: v14);
    Cbuf_AddText(eTarget: TraceType, pText: m_szBuf, nTickDelay: 0);
  }
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &currentLevelData.m_EntityToIndex);
  CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,int>>::RemoveAll(this: &currentLevelData.m_EntityToIndex.m_Buckets);
  m_pMemory = currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory;
  if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory = nullptr;
    }
    currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nAllocationCount = 0;
  }
  currentLevelData.m_EntityToIndex.m_Buckets.m_pElements = m_pMemory;
  if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x102757F0
// Name: public: virtual void CMemberFunctor6<class CSOAContainer __near *,void (CSOAContainer::*)(int,int,int,int,int,union __m128),int,int,int,int,int,union __m128,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor6<CSOAContainer *,void (__thiscall CSOAContainer::*)(int,int,int,int,int,__m128),int,int,int,int,int,__m128,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor6<CSOAContainer *,void (__thiscall CSOAContainer::*)(int,int,int,int,int,__m128),int,int,int,int,int,__m128,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(CSOAContainer *, int, int, int, int, int))this->m_Proxy.m_pfnProxied)(
    a1: this->m_Proxy.m_pObject,
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x10275820
// Name: private: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::ExecuteWrapper(int __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::ExecuteWrapper(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        int *nDummy)
{
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this);
}

//------------------------------------------------------------------------------
// Address: 0x10275950
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::ParallelCallQueued(class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::ParallelCallQueued(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        IThreadPool *pPool)
{
  IThreadPool *v2; // esi
  volatile int m_value; // ebx
  volatile int v5; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> v6; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = pPool;
  if ( pPool == nullptr )
  {
    v2 = _g_pThreadPool;
    if ( _g_pThreadPool == nullptr )
      goto LABEL_11;
  }
  if ( this->m_queue.m_Count.m_value >= 1 )
    m_value = this->m_queue.m_Count.m_value;
  else
    m_value = 1;
  if ( v2->NumThreads(this: v2) >= m_value )
  {
    if ( this->m_queue.m_Count.m_value < 1 )
    {
LABEL_11:
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this);
      return;
    }
    v5 = this->m_queue.m_Count.m_value;
  }
  else
  {
    v5 = v2->NumThreads(this: v2);
  }
  if ( v5 < 2 )
    goto LABEL_11;
  v6.m_pItems.m_value = nullptr;
  v6.m_pLimit = nullptr;
  _InterlockedExchange((volatile __int32 *)&v6.m_pItems, 0);
  v6.m_ItemProcessor.m_pfnBegin = nullptr;
  v6.m_ItemProcessor.m_pfnEnd = nullptr;
  v6.m_ItemProcessor.m_pObject = this;
  v6.m_ItemProcessor.m_pfnProcess = CCallQueueT<CTSQueue<CFunctor *,0,1>>::ExecuteWrapper;
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
    this: &v6,
    pItems: nullptr,
    nItems: v5,
    nChunkSize: 1,
    nMaxParallel: 0x7FFFFFFF,
    pThreadPool: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102E8F30
// Name: struct datamap_t __near * DataMapInit<struct VTFFileBaseHeader_t>(struct VTFFileBaseHeader_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileBaseHeader_t>()
{
  if ( (_S1_29 & 1) == 0 )
  {
    _S1_29 |= 1u;
    nameHolder_9.m_pszBase = "VTFFileBaseHeader_t";
    nameHolder_9.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_9.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_9.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_9.m_Names.m_Size = 0;
    nameHolder_9.m_Names.m_pElements = nullptr;
    nameHolder_9.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileBaseHeader_t::m_DataMap.baseMap = nullptr;
  VTFFileBaseHeader_t::m_DataMap.dataNumFields = 3;
  VTFFileBaseHeader_t::m_DataMap.dataDesc = &dataDesc_9[1];
  return &VTFFileBaseHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E8FB0
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderV7_1_t>(struct VTFFileHeaderV7_1_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderV7_1_t>()
{
  if ( (_S2_21 & 1) == 0 )
  {
    _S2_21 |= 1u;
    nameHolder_10.m_pszBase = "VTFFileHeaderV7_1_t";
    nameHolder_10.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_10.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_10.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_10.m_Names.m_Size = 0;
    nameHolder_10.m_Names.m_pElements = nullptr;
    nameHolder_10.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderV7_1_t::m_DataMap.baseMap = &VTFFileBaseHeader_t::m_DataMap;
  VTFFileHeaderV7_1_t::m_DataMap.dataNumFields = 12;
  VTFFileHeaderV7_1_t::m_DataMap.dataDesc = &dataDesc_10[1];
  return &VTFFileHeaderV7_1_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E9030
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderV7_2_t>(struct VTFFileHeaderV7_2_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderV7_2_t>()
{
  if ( (_S3_7 & 1) == 0 )
  {
    _S3_7 |= 1u;
    nameHolder_11.m_pszBase = "VTFFileHeaderV7_2_t";
    nameHolder_11.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_11.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_11.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_11.m_Names.m_Size = 0;
    nameHolder_11.m_Names.m_pElements = nullptr;
    nameHolder_11.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderV7_2_t::m_DataMap.baseMap = &VTFFileHeaderV7_1_t::m_DataMap;
  VTFFileHeaderV7_2_t::m_DataMap.dataNumFields = 1;
  VTFFileHeaderV7_2_t::m_DataMap.dataDesc = &dataDesc_11[1];
  return &VTFFileHeaderV7_2_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E90A0
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderV7_3_t>(struct VTFFileHeaderV7_3_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderV7_3_t>()
{
  if ( (_S4_4 & 1) == 0 )
  {
    _S4_4 |= 1u;
    nameHolder_12.m_pszBase = "VTFFileHeaderV7_3_t";
    nameHolder_12.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_12.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_12.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_12.m_Names.m_Size = 0;
    nameHolder_12.m_Names.m_pElements = nullptr;
    nameHolder_12.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderV7_3_t::m_DataMap.baseMap = &VTFFileHeaderV7_2_t::m_DataMap;
  VTFFileHeaderV7_3_t::m_DataMap.dataNumFields = 1;
  VTFFileHeaderV7_3_t::m_DataMap.dataDesc = &dataDesc_12[1];
  return &VTFFileHeaderV7_3_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E9110
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeader_t>(struct VTFFileHeader_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeader_t>()
{
  if ( (_S5_4 & 1) == 0 )
  {
    _S5_4 |= 1u;
    nameHolder_13.m_pszBase = "VTFFileHeader_t";
    nameHolder_13.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_13.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_13.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_13.m_Names.m_Size = 0;
    nameHolder_13.m_Names.m_pElements = nullptr;
    nameHolder_13.m_nLenBase = 15;
    atexit(func: DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeader_t::m_DataMap.baseMap = &VTFFileHeaderV7_2_t::m_DataMap;
  VTFFileHeader_t::m_DataMap.dataNumFields = 1;
  VTFFileHeader_t::m_DataMap.dataDesc = dataDesc_15;
  return &VTFFileHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E9180
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderX360_t>(struct VTFFileHeaderX360_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderX360_t>()
{
  if ( (_S6_3 & 1) == 0 )
  {
    _S6_3 |= 1u;
    nameHolder_14.m_pszBase = "VTFFileHeaderX360_t";
    nameHolder_14.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_14.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_14.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_14.m_Names.m_Size = 0;
    nameHolder_14.m_Names.m_pElements = nullptr;
    nameHolder_14.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderX360_t::m_DataMap.baseMap = &VTFFileBaseHeader_t::m_DataMap;
  VTFFileHeaderX360_t::m_DataMap.dataNumFields = 13;
  VTFFileHeaderX360_t::m_DataMap.dataDesc = &dataDesc_13[1];
  return &VTFFileHeaderX360_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E9200
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderPS3_t>(struct VTFFileHeaderPS3_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderPS3_t>()
{
  if ( (_S7_3 & 1) == 0 )
  {
    _S7_3 |= 1u;
    nameHolder_15.m_pszBase = "VTFFileHeaderPS3_t";
    nameHolder_15.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_15.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_15.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_15.m_Names.m_Size = 0;
    nameHolder_15.m_Names.m_pElements = nullptr;
    nameHolder_15.m_nLenBase = 18;
    atexit(func: DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderPS3_t::m_DataMap.baseMap = &VTFFileBaseHeader_t::m_DataMap;
  VTFFileHeaderPS3_t::m_DataMap.dataNumFields = 13;
  VTFFileHeaderPS3_t::m_DataMap.dataDesc = &dataDesc_14[1];
  return &VTFFileHeaderPS3_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1031BB50
// Name: GAME_HEADER_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *GAME_HEADER_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<GAME_HEADER>(__formal: nullptr);
  GAME_HEADER_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BB60
// Name: SAVE_HEADER_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SAVE_HEADER_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SAVE_HEADER>(__formal: nullptr);
  SAVE_HEADER_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BB70
// Name: levellist_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *levellist_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<levellist_t>(__formal: nullptr);
  levellist_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BB80
// Name: SAVELIGHTSTYLE_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SAVELIGHTSTYLE_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SAVELIGHTSTYLE>(__formal: nullptr);
  SAVELIGHTSTYLE_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BBC0
// Name: musicsave_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *musicsave_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<musicsave_t>(__formal: nullptr);
  musicsave_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BBD0
// Name: channelsave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *channelsave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<channelsave>(__formal: nullptr);
  channelsave_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BBE0
// Name: decallist_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *decallist_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<decallist_t>(__formal: nullptr);
  decallist_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10325C90
// Name: _GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__
// Source: semantic_dyn_global_var
//------------------------------------------------------------------------------
void __cdecl GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__()
{
  CMemoryStack::~CMemoryStack(this: &g_SaveMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10193E10
// Name: class CFunctor __near * CreateFunctor<class CSaveRestore __near *,class CSaveRestore,void,char const __near *,char const __near *,bool,class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool>(class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *> const __near &,class CUtlEnvelope<char const __near *> const __near &,bool const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<CSaveRestore *,CSaveRestore,void,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
        CSaveRestore *pObject,
        void (__thiscall *pfnProxied)(CSaveRestore *this, const char *, const char *, bool),
        const CUtlEnvelope<char const *> *arg1,
        const CUtlEnvelope<char const *> *arg2,
        const bool *arg3)
{
  char *v5; // esi

  v5 = (char *)MemAlloc_Alloc(nSize: 0x3Cu);
  if ( v5 == nullptr )
    return nullptr;
  *((_DWORD *)v5 + 3) = 1;
  *(_DWORD *)v5 = &CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)v5 + 2) = &CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  *((_DWORD *)v5 + 5) = pObject;
  *((_DWORD *)v5 + 4) = pfnProxied;
  CUtlString::CUtlString(this: (CUtlString *)(v5 + 24));
  CUtlString::operator=(this: (CUtlString *)(v5 + 24), src: &arg1->m_string);
  CUtlString::CUtlString(this: (CUtlString *)(v5 + 40));
  CUtlString::operator=(this: (CUtlString *)(v5 + 40), src: &arg2->m_string);
  v5[56] = *arg3;
  return (CFunctor *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10325CA0
// Name: _DataMapInit_GAME_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_GAME_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x10325CB0
// Name: _DataMapInit_SAVE_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SAVE_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x10325CC0
// Name: _DataMapInit_levellist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_levellist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_4);
}

//------------------------------------------------------------------------------
// Address: 0x10325CD0
// Name: _DataMapInit_SAVELIGHTSTYLE__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SAVELIGHTSTYLE__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_5);
}

//------------------------------------------------------------------------------
// Address: 0x10325CE0
// Name: _DataMapInit_musicsave_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_musicsave_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_6);
}

//------------------------------------------------------------------------------
// Address: 0x10325CF0
// Name: _DataMapInit_channelsave__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_channelsave__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_7);
}

//------------------------------------------------------------------------------
// Address: 0x10325D00
// Name: _DataMapInit_decallist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_decallist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_8);
}

//------------------------------------------------------------------------------
// Address: 0x10325D10
// Name: _dynamic_atexit_destructor_for__g_AsyncSaveCallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncSaveCallQueue__()
{
  CTSQueue<int,0,1>::Purge(this: (CTSQueue<int,0,1> *)&g_AsyncSaveCallQueue);
  free(pMem: g_AsyncSaveCallQueue.m_queue.m_Head.value.pNode);
  CTSListBase::Detach(this: &g_AsyncSaveCallQueue.m_queue.m_FreeNodes);
}

//------------------------------------------------------------------------------
// Address: 0x10325D40
// Name: _dynamic_atexit_destructor_for__g_SaveRestore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SaveRestore__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_SaveRestore.m_sDeferredCommands);
  CUtlDict<CSaveRestore::RestoreLookupTable,int>::RemoveAll(this: &g_SaveRestore.m_RestoreLookup);
  CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>(this: &g_SaveRestore.m_RestoreLookup.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10325D60
// Name: _dynamic_atexit_destructor_for__in_forceuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__in_forceuser__()
{
  ConVar::~ConVar(this: &in_forceuser);
}

//------------------------------------------------------------------------------
// Address: 0x10325D70
// Name: _dynamic_atexit_destructor_for__unbind_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__unbind_command__()
{
  ConCommand::~ConCommand(this: &unbind_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325D80
// Name: _dynamic_atexit_destructor_for__unbindall_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__unbindall_command__()
{
  ConCommand::~ConCommand(this: &unbindall_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325D90
// Name: _dynamic_atexit_destructor_for__escape_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__escape_command__()
{
  ConCommand::~ConCommand(this: &escape_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100DFFE0
// Name: public: virtual void CMemberFunctor1<class CModelRender __near *,int (CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>::*)(struct memhandle_t__ __near *),struct memhandle_t__ __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  CModelRender *m_pObject; // ecx

  m_pObject = this->m_Proxy.m_pObject;
  if ( m_pObject != nullptr )
    this->m_Proxy.m_pfnProxied(
      this: &m_pObject->CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,
      a2: this->m_arg1);
  else
    this->m_Proxy.m_pfnProxied(this: nullptr, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x100EFD20
// Name: struct datamap_t __near * DataMapInit<struct lump_t>(struct lump_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<lump_t>()
{
  if ( (_S1_10 & 1) == 0 )
  {
    _S1_10 |= 1u;
    nameHolder.m_pszBase = "lump_t";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = 6;
    atexit(func: DataMapInit_lump_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  lump_t::m_DataMap.baseMap = nullptr;
  lump_t::m_DataMap.dataNumFields = 4;
  lump_t::m_DataMap.dataDesc = &dataDesc[1];
  return &lump_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EFDA0
// Name: struct datamap_t __near * DataMapInit<struct BSPHeader_t>(struct BSPHeader_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<BSPHeader_t>()
{
  if ( (_S2_6 & 1) == 0 )
  {
    _S2_6 |= 1u;
    nameHolder_0.m_pszBase = "BSPHeader_t";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = 11;
    atexit(func: DataMapInit_BSPHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  BSPHeader_t::m_DataMap.baseMap = nullptr;
  BSPHeader_t::m_DataMap.dataNumFields = 4;
  BSPHeader_t::m_DataMap.dataDesc = &dataDesc_0[1];
  return &BSPHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10127090
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1> __near *,void (CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1013F2C0
// Name: public: virtual void CMemberFunctor0<class CCallQueue __near *,void (CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CCallQueue *,void (__thiscall CCallQueueT<CTSQueue<CFunctor *,0,1> >::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x1013F940
// Name: private: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueFunctorInternal(class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CFunctor *pFunctor)
{
  CTSQueue<loopback_t *,0,1>::Node_t *v3; // eax

  if ( this->m_bNoQueue )
  {
    pFunctor->operator()(this: pFunctor);
    pFunctor->Release(this: pFunctor);
  }
  else
  {
    v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_queue.m_FreeNodes);
    if ( v3 != nullptr || (v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
    {
      v3->elem = (loopback_t *)pFunctor;
      CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: v3);
    }
    else
    {
      CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FD00
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::CallQueued(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(CCallQueueT<CTSQueue<CFunctor *,0,1> > *this)
{
  CTSQueue<loopback_t *,0,1>::Node_t *v2; // eax
  CTSQueue<int,0,1>::Node_t *v3; // eax
  int elem; // esi

  if ( this->m_queue.m_Count.m_value != 0 )
  {
    v2 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_queue.m_FreeNodes);
    if ( v2 != nullptr )
    {
      v2->elem = nullptr;
    }
    else
    {
      v2 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
      if ( v2 != nullptr )
        v2->elem = nullptr;
      else
        v2 = nullptr;
    }
    CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: v2);
    while ( 1 )
    {
      v3 = CTSQueue<loopback_t *,0,1>::Pop((CTSQueue<int,0,1> *)this);
      if ( v3 == nullptr )
        break;
      elem = v3->elem;
      CTSListBase::Push(this: &this->m_queue.m_FreeNodes, pNode: (TSLNodeBase_t *)v3);
      if ( elem == 0 )
        break;
      (*(void (__thiscall **)(int))(*(_DWORD *)elem + 12))(a1: elem);
      (*(void (__thiscall **)(int))(*(_DWORD *)elem + 4))(a1: elem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FE00
// Name: public: CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *> const __near &,class CUtlEnvelope<char const __near *> const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this,
        CBugUIPanel *pObject,
        __int128 pfnProxied,
        const CUtlEnvelope<char const *> *arg1,
        const CUtlEnvelope<char const *> *arg2,
        bool *arg3)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  *(_QWORD *)&this->m_Proxy.m_pfnProxied = pfnProxied;
  this->m_Proxy.m_pObject = pObject;
  *((_QWORD *)&this->m_Proxy.m_pfnProxied + 1) = *((_QWORD *)&pfnProxied + 1);
  CUtlString::CUtlString(this: &this->m_arg1.m_string);
  CUtlString::operator=(this: &this->m_arg1.m_string, src: &arg1->m_string);
  CUtlString::CUtlString(this: &this->m_arg2.m_string);
  CUtlString::operator=(this: &this->m_arg2.m_string, src: &arg2->m_string);
  this->m_arg3 = *arg3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013FE90
// Name: public: virtual void CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  const char *v2; // edi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: &this->m_arg2.m_string);
  v3 = CUtlString::operator char const *(this: &this->m_arg1.m_string);
  ((void (__thiscall *)(char *, const char *, const char *, bool))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: v3,
    a3: v2,
    a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x1013FEC0
// Name: public: virtual CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::~CMemberFunctor3<class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::~CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_arg2.m_string.m_Storage.m_nActualLength = 0;
  if ( this->m_arg2.m_string.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory);
      this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_arg2.m_string.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_arg1.m_string.m_Storage.m_nActualLength = 0;
  if ( this->m_arg1.m_string.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory);
      this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_arg1.m_string.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CFunctor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10140F10
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueCall<class CBugUIPanel __near *,class CBugUIPanel,bool,char const __near *,char const __near *,bool,class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool>(class CBugUIPanel __near *,bool (CBugUIPanel::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *> const __near &,class CUtlEnvelope<char const __near *> const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBugUIPanel *,CBugUIPanel,bool,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CBugUIPanel *pObject,
        __int128 pfnProxied,
        const CUtlEnvelope<char const *> *arg1,
        const CUtlEnvelope<char const *> *arg2,
        bool *arg3)
{
  CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v7; // eax
  CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v8; // eax

  v7 = (CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v7 != nullptr )
  {
    v8 = CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor3<CBugUIPanel *,bool (__thiscall CBugUIPanel::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
           this: v7,
           pObject,
           pfnProxied,
           arg1,
           arg2,
           arg3);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: v8);
  }
  else
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187EC0
// Name: public: virtual void CFunctor1<void (*)(int),int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor1<void (__cdecl *)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor1<void (__cdecl*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x1018A6A0
// Name: struct datamap_t __near * DataMapInit<struct player_info_s>(struct player_info_s __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<player_info_s>()
{
  if ( (_S2_13 & 1) == 0 )
  {
    _S2_13 |= 1u;
    nameHolder_1.m_pszBase = "player_info_s";
    nameHolder_1.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_1.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_1.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_1.m_Names.m_Size = 0;
    nameHolder_1.m_Names.m_pElements = nullptr;
    nameHolder_1.m_nLenBase = 13;
    atexit(func: DataMapInit_player_info_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  player_info_s::m_DataMap.baseMap = nullptr;
  player_info_s::m_DataMap.dataNumFields = 10;
  player_info_s::m_DataMap.dataDesc = &dataDesc_1[1];
  return &player_info_s::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1018FF70
// Name: public: virtual char const __near * CSaveRestore::FindRecentSave(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestore::FindRecentSave(CSaveRestore *this, char *pNameBuf, int nameBufLen)
{
  char *m_szMostRecentSaveLoadGame; // esi

  m_szMostRecentSaveLoadGame = this->m_szMostRecentSaveLoadGame;
  V_strncpy(pDest: pNameBuf, pSrc: this->m_szMostRecentSaveLoadGame, maxLen: nameBufLen);
  return *m_szMostRecentSaveLoadGame != 0 ? pNameBuf : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10190200
// Name: protected: bool CSaveRestore::CalcSaveGameName(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestore::CalcSaveGameName(
        CSaveRestore *this,
        const char *pName,
        char *output,
        int outputStringLength)
{
  char *v5; // esi
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  int v10; // [esp-Ch] [ebp-14h]
  const char *v11; // [esp-4h] [ebp-Ch]

  if ( pName == nullptr || *pName == 0 )
    return 0;
  if ( this->IsXSave(this) )
  {
    v5 = output;
    *output = 0;
    v6 = outputStringLength;
    v10 = outputStringLength - _V_strlen(str: output);
    v7 = _V_strlen(str: output);
    V_snprintf(pDest: &output[v7], maxLen: v10, pFormat: "//mod/%s", pName);
  }
  else
  {
    v8 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: pName);
    v6 = outputStringLength;
    v5 = output;
    V_snprintf(pDest: output, maxLen: outputStringLength, pFormat: "%s%s", v8, v11);
  }
  V_DefaultExtension(path: v5, extension: ".sav", pathStringLength: v6);
  V_FixSlashes(pname: v5, separator: 92);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101902A0
// Name: public: virtual bool CSaveRestore::SaveFileExists(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestore::SaveFileExists(CSaveRestore *this, const char *pName)
{
  char result; // al
  char name[256]; // [esp+4h] [ebp-100h] BYREF

  this->FinishAsyncSave(this);
  result = CSaveRestore::CalcSaveGameName(this, pName, output: name, outputStringLength: 256);
  if ( result != 0 )
  {
    if ( !this->IsXSave(this) || this->StorageDeviceValid(this) )
      return g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: name, a3: nullptr);
    else
      return g_pSaveRestoreFileSystem->FileExists(this: g_pSaveRestoreFileSystem, a2: name, a3: nullptr);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10190340
// Name: public: virtual bool CSaveRestore::IsOverrideLoadGameEntsOn(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::IsOverrideLoadGameEntsOn(CSaveRestore *this)
{
  return this->m_bOverrideLoadGameEntsOn;
}

//------------------------------------------------------------------------------
// Address: 0x10190350
// Name: private: virtual void CSaveRestore::SetMostRecentSaveGame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SetMostRecentSaveGame(CSaveRestore *this, const char *pSaveName)
{
  char *m_szMostRecentSaveLoadGame; // esi

  m_szMostRecentSaveLoadGame = this->m_szMostRecentSaveLoadGame;
  if ( pSaveName != nullptr )
    V_strncpy(pDest: this->m_szMostRecentSaveLoadGame, pSrc: pSaveName, maxLen: 260);
  else
    *m_szMostRecentSaveLoadGame = 0;
  if ( *m_szMostRecentSaveLoadGame == 0 )
    DevWarning(a1: "Cleared most recent save!\n");
}

//------------------------------------------------------------------------------
// Address: 0x10190390
// Name: private: virtual int CSaveRestore::GetMostRecentElapsedMinutes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::GetMostRecentElapsedMinutes(CSaveRestore *this)
{
  return this->m_MostRecentElapsedMinutes;
}

//------------------------------------------------------------------------------
// Address: 0x101903A0
// Name: private: virtual int CSaveRestore::GetMostRecentElapsedSeconds(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::GetMostRecentElapsedSeconds(CSaveRestore *this)
{
  return this->m_MostRecentElapsedSeconds;
}

//------------------------------------------------------------------------------
// Address: 0x101903B0
// Name: private: virtual int CSaveRestore::GetMostRecentElapsedTimeSet(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::GetMostRecentElapsedTimeSet(CSaveRestore *this)
{
  return this->m_MostRecentElapsedTimeSet;
}

//------------------------------------------------------------------------------
// Address: 0x101903C0
// Name: private: virtual void CSaveRestore::SetMostRecentElapsedMinutes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SetMostRecentElapsedMinutes(CSaveRestore *this, int min)
{
  this->m_MostRecentElapsedMinutes = min;
  this->m_MostRecentElapsedTimeSet = (int)g_ServerGlobalVariables.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x101903E0
// Name: private: virtual void CSaveRestore::SetMostRecentElapsedSeconds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SetMostRecentElapsedSeconds(CSaveRestore *this, int sec)
{
  this->m_MostRecentElapsedSeconds = sec;
  this->m_MostRecentElapsedTimeSet = (int)g_ServerGlobalVariables.curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10190400
// Name: public: bool SaveFileHeaderTag_t::operator!=(struct SaveFileHeaderTag_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall SaveFileHeaderTag_t::operator!=(SaveFileHeaderTag_t *this, const SaveFileHeaderTag_t *rhs)
{
  unsigned int v3; // eax

  v3 = 8;
  while ( this->id == rhs->id )
  {
    v3 -= 4;
    rhs = (const SaveFileHeaderTag_t *)((char *)rhs + 4);
    this = (SaveFileHeaderTag_t *)((char *)this + 4);
    if ( v3 < 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10190470
// Name: private: void CSaveRestore::SaveGameStateGlobals(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SaveGameStateGlobals(CSaveRestore *this, CSaveRestoreData *pSaveData)
{
  INetworkStringTable *LightStyleTable; // ebx
  int v3; // edi
  _BYTE *v4; // eax
  int v5; // edi
  levellist_t *levelList; // ebx
  int i; // edi
  const char *v8; // eax
  SAVELIGHTSTYLE light; // [esp+Ch] [ebp-ACh] BYREF
  SAVE_HEADER header; // [esp+50h] [ebp-68h] BYREF
  ConVarRef skyname; // [esp+ACh] [ebp-Ch] BYREF
  INetworkStringTable *table; // [esp+B4h] [ebp-4h]

  LightStyleTable = CBaseServer::GetLightStyleTable(this: &sv);
  table = LightStyleTable;
  header.version = build_number();
  v3 = 0;
  if ( skill.m_pParent != nullptr )
    header.skillLevel = skill.m_pParent->m_Value.m_nValue;
  else
    header.skillLevel = 0;
  header.connectionCount = pSaveData->levelInfo.connectionCount;
  header.time = CBaseServer::GetTime(this: &sv);
  ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname");
  if ( ConVarRef::IsValid(this: &skyname) )
    V_strncpy(pDest: header.skyName, pSrc: skyname.m_pConVarState->m_Value.m_pszString, maxLen: 32);
  else
    V_strncpy(pDest: header.skyName, pSrc: "unknown", maxLen: 32);
  V_strncpy(pDest: header.mapName, pSrc: sv.m_szMapname, maxLen: 32);
  header.lightStyleCount = 0;
  header.mapVersion = g_ServerGlobalVariables.mapversion;
  do
  {
    v4 = LightStyleTable->GetStringUserData(this: LightStyleTable, a2: v3, a3: nullptr);
    if ( v4 != nullptr && *v4 != 0 )
      ++header.lightStyleCount;
    ++v3;
  }
  while ( v3 < 64 );
  pSaveData->levelInfo.time = 0.0;
  serverGameDLL->SaveWriteFields(
    this: serverGameDLL,
    a2: pSaveData,
    a3: "Save Header",
    a4: &header,
    a5: nullptr,
    a6: SAVE_HEADER::m_DataMap.dataDesc,
    a7: SAVE_HEADER::m_DataMap.dataNumFields);
  v5 = 0;
  pSaveData->levelInfo.time = header.time;
  if ( pSaveData->levelInfo.connectionCount > 0 )
  {
    levelList = pSaveData->levelInfo.levelList;
    do
    {
      serverGameDLL->SaveWriteFields(
        this: serverGameDLL,
        a2: pSaveData,
        a3: "ADJACENCY",
        a4: levelList,
        a5: nullptr,
        a6: levellist_t::m_DataMap.dataDesc,
        a7: levellist_t::m_DataMap.dataNumFields);
      ++v5;
      ++levelList;
    }
    while ( v5 < pSaveData->levelInfo.connectionCount );
    LightStyleTable = table;
  }
  for ( i = 0; i < 64; ++i )
  {
    v8 = (const char *)LightStyleTable->GetStringUserData(this: LightStyleTable, a2: i, a3: nullptr);
    if ( v8 != nullptr && *v8 != 0 )
    {
      light.index = i;
      V_strncpy(pDest: light.style, pSrc: v8, maxLen: 64);
      serverGameDLL->SaveWriteFields(
        this: serverGameDLL,
        a2: pSaveData,
        a3: "LIGHTSTYLE",
        a4: &light,
        a5: nullptr,
        a6: SAVELIGHTSTYLE::m_DataMap.dataDesc,
        a7: SAVELIGHTSTYLE::m_DataMap.dataNumFields);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190620
// Name: public: virtual void CSaveRestore::RestoreAdjacenClientState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::RestoreAdjacenClientState(CSaveRestore *this, const char *map)
{
  const char *v3; // eax
  int v4; // eax
  int v5; // [esp-Ch] [ebp-110h]
  const char *v6; // [esp-4h] [ebp-108h]
  char name[256]; // [esp+4h] [ebp-100h] BYREF

  if ( this->IsXSave(this) )
  {
    name[0] = 0;
    V_FileBase(in: map, out: level, maxlen: 256);
    v5 = 256 - _V_strlen(str: name);
    v4 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v4], maxLen: v5, pFormat: "//mod/%s.HL2", level);
  }
  else
  {
    V_FileBase(in: map, out: level, maxlen: 256);
    v3 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))this->GetSaveDir)(a1: this, a2: level);
    V_snprintf(pDest: name, maxLen: 256, pFormat: "//%s/%s%s.HL2", "MOD", v3, v6);
  }
  COM_CreatePath(path: name);
  this->RestoreClientState(this, a2: name, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10190700
// Name: private: virtual int CSaveRestore::SaveReadNameAndComment(void __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::SaveReadNameAndComment(CSaveRestore *this, char *f, char *name, char *comment)
{
  void *v4; // esi
  char *v6; // edx
  char *v7; // edi
  char *v8; // eax
  __int16 *v9; // esi
  char **v10; // ebx
  int v11; // eax
  const char *v12; // eax
  int v13; // edi
  int v14; // eax
  const char *v15; // esi
  const char *v16; // ebx
  int v17; // edi
  const char *v18; // esi
  char *pSaveData; // [esp+4h] [ebp-18h]
  int i; // [esp+8h] [ebp-14h]
  int tokenSize; // [esp+Ch] [ebp-10h] BYREF
  int tag; // [esp+10h] [ebp-Ch] BYREF
  char **pTokenList; // [esp+14h] [ebp-8h]
  int tokenCount; // [esp+18h] [ebp-4h] BYREF

  v4 = f;
  if ( g_pSaveRestoreFileSystem->Size_2(this: g_pSaveRestoreFileSystem, a2: f) < 0x14 )
    return 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 4, a4: v4) != 4 )
    return 0;
  if ( tag != 1447121738 )
    return 0;
  v6 = comment;
  *name = 0;
  *v6 = 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 4, a4: v4) != 4 )
    return 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &f, a3: 4, a4: v4) != 4 )
    return 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tokenCount, a3: 4, a4: v4) != 4 )
    return 0;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tokenSize, a3: 4, a4: v4) != 4 )
    return 0;
  f += tokenSize;
  if ( (unsigned int)tokenCount > 0x2000000 || (unsigned int)tokenSize > 0xA00000 )
    return 0;
  v7 = (char *)MemAlloc_Alloc(nSize: (unsigned int)f);
  pSaveData = v7;
  v8 = (char *)g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: v7, a3: (int)f, a4: v4);
  if ( v8 != f )
  {
    free(pMem: v7);
    return 0;
  }
  v9 = (__int16 *)v7;
  if ( tokenSize <= 0 )
  {
    pTokenList = nullptr;
    v10 = nullptr;
  }
  else
  {
    v10 = (char **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)tokenCount >> 30 != 0 ? -1 : 4 * tokenCount);
    v11 = 0;
    for ( pTokenList = v10; v11 < tokenCount; ++v11 )
    {
      v10[v11] = *(_BYTE *)v9 != 0 ? (char *)v9 : nullptr;
      v9 = (__int16 *)((char *)v9 + strlen((const char *)v9) + 1);
    }
  }
  v12 = v10[v9[1]];
  v13 = *v9;
  if ( v12 == nullptr || _V_stricmp(s1: v12, s2: "GameHeader") != 0 )
  {
    free(pMem: pSaveData);
    free(pMem: v10);
  }
  else
  {
    v14 = *((_DWORD *)v9 + 1);
    v15 = (char *)v9 + v13 + 4;
    if ( v14 > 0 )
    {
      for ( i = v14; i != 0; --i )
      {
        v16 = v10[*((__int16 *)v15 + 1)];
        v17 = *(__int16 *)v15;
        v18 = v15 + 4;
        if ( _V_stricmp(s1: v16, s2: "comment") != 0 )
        {
          if ( _V_stricmp(s1: v16, s2: "mapName") == 0 )
            V_strncpy(pDest: name, pSrc: v18, maxLen: v17);
        }
        else
        {
          V_strncpy(pDest: comment, pSrc: v18, maxLen: v17);
        }
        v10 = pTokenList;
        v15 = &v18[v17];
      }
    }
    free(pMem: v10);
    free(pMem: pSaveData);
    if ( strlen(name) != 0 && strlen(comment) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10190970
// Name: private: void CSaveRestore::ParseSaveTables(class CSaveRestoreData __near *,struct SAVE_HEADER __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::ParseSaveTables(
        CSaveRestore *this,
        CSaveRestoreData *pSaveData,
        SAVE_HEADER *pHeader,
        int updateGlobals)
{
  INetworkStringTable *LightStyleTable; // eax
  SAVE_HEADER *v5; // ebx
  int v6; // edi
  levellist_t *levelList; // ebx
  int j; // edi
  INetworkStringTable_vtbl *v9; // edi
  int v10; // eax
  SAVELIGHTSTYLE light; // [esp+Ch] [ebp-48h] BYREF
  INetworkStringTable *table; // [esp+50h] [ebp-4h]
  int i; // [esp+60h] [ebp+Ch]

  LightStyleTable = CBaseServer::GetLightStyleTable(this: &sv);
  pSaveData->bufferSize -= pSaveData->size;
  v5 = pHeader;
  table = LightStyleTable;
  pSaveData->pBaseData = pSaveData->pCurrentData;
  v6 = 0;
  pSaveData->size = 0;
  serverGameDLL->SaveReadFields(
    this: serverGameDLL,
    a2: pSaveData,
    a3: "Save Header",
    a4: pHeader,
    a5: nullptr,
    a6: SAVE_HEADER::m_DataMap.dataDesc,
    a7: SAVE_HEADER::m_DataMap.dataNumFields);
  pSaveData->levelInfo.mapVersion = pHeader->mapVersion;
  pSaveData->levelInfo.connectionCount = pHeader->connectionCount;
  pSaveData->levelInfo.time = pHeader->time;
  pSaveData->levelInfo.fUseLandmark = 1;
  pSaveData->levelInfo.vecLandmarkOffset = vec3_origin;
  if ( pSaveData->levelInfo.connectionCount > 0 )
  {
    levelList = pSaveData->levelInfo.levelList;
    do
    {
      serverGameDLL->SaveReadFields(
        this: serverGameDLL,
        a2: pSaveData,
        a3: "ADJACENCY",
        a4: levelList,
        a5: nullptr,
        a6: levellist_t::m_DataMap.dataDesc,
        a7: levellist_t::m_DataMap.dataNumFields);
      ++v6;
      ++levelList;
    }
    while ( v6 < pSaveData->levelInfo.connectionCount );
    v5 = pHeader;
  }
  if ( updateGlobals != 0 )
  {
    for ( j = 0; j < 64; ++j )
      table->SetStringUserData(this: table, a2: j, a3: 1, a4: defaultValue);
  }
  for ( i = 0; i < v5->lightStyleCount; ++i )
  {
    serverGameDLL->SaveReadFields(
      this: serverGameDLL,
      a2: pSaveData,
      a3: "LIGHTSTYLE",
      a4: &light,
      a5: nullptr,
      a6: SAVELIGHTSTYLE::m_DataMap.dataDesc,
      a7: SAVELIGHTSTYLE::m_DataMap.dataNumFields);
    if ( updateGlobals != 0 )
    {
      v9 = table->__vftable;
      v10 = _V_strlen(str: light.style);
      v9->SetStringUserData(this: table, a2: light.index, a3: v10 + 1, a4: light.style);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190AF0
// Name: private: void CSaveRestore::EntityPatchRead(class CSaveRestoreData __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::EntityPatchRead(CSaveRestore *this, CSaveRestoreData *pSaveData, const char *level)
{
  const char *v4; // eax
  int v5; // eax
  void *v6; // edi
  int i; // esi
  int v8; // [esp-Ch] [ebp-120h]
  const char *v9; // [esp-4h] [ebp-118h]
  char name[260]; // [esp+8h] [ebp-10Ch] BYREF
  int entityId; // [esp+10Ch] [ebp-8h] BYREF
  int size; // [esp+110h] [ebp-4h] BYREF

  if ( this->IsXSave(this) )
  {
    name[0] = 0;
    V_FileBase(in: level, out: ::level, maxlen: 256);
    v8 = 260 - _V_strlen(str: name);
    v5 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v5], maxLen: v8, pFormat: "//mod/%s.HL3", ::level);
  }
  else
  {
    V_FileBase(in: level, out: ::level, maxlen: 256);
    v4 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))this->GetSaveDir)(a1: this, a2: ::level);
    V_snprintf(pDest: name, maxLen: 260, pFormat: "//%s/%s%s.HL3", "MOD", v4, v9);
  }
  v6 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: name, a3: "rb", a4: nullptr);
  if ( v6 != nullptr )
  {
    g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &size, a3: 4, a4: v6);
    for ( i = 0; i < size; pSaveData->pTable[entityId].flags = 0x40000000 )
    {
      g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &entityId, a3: 4, a4: v6);
      ++i;
    }
    g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190C30
// Name: void LandmarkOrigin(class CSaveRestoreData __near *,class Vector __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LandmarkOrigin(CSaveRestoreData *pSaveData, Vector *output, const char *pLandmarkName)
{
  int v3; // esi
  char *landmarkName; // ebx

  v3 = 0;
  if ( pSaveData->levelInfo.connectionCount <= 0 )
  {
LABEL_5:
    *output = vec3_origin;
  }
  else
  {
    landmarkName = pSaveData->levelInfo.levelList[0].landmarkName;
    while ( _V_stricmp(s1: landmarkName, s2: pLandmarkName) != 0 )
    {
      ++v3;
      landmarkName += 80;
      if ( v3 >= pSaveData->levelInfo.connectionCount )
        goto LABEL_5;
    }
    *output = pSaveData->levelInfo.levelList[v3].vecLandmarkOrigin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190CB0
// Name: private: bool CSaveRestore::DirectoryExtract(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::DirectoryExtract(CSaveRestore *this, void *pFile, int fileCount)
{
  ISaveRestoreFileSystem_vtbl *v3; // esi
  bool v4; // al

  v3 = g_pSaveRestoreFileSystem->__vftable;
  v4 = this->IsXSave(this);
  return v3->DirectoryExtract(this: g_pSaveRestoreFileSystem, a2: pFile, a3: fileCount, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10190CE0
// Name: public: void CSaveRestore::DoClearSaveDir(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::DoClearSaveDir(CSaveRestore *this, bool bIsXSave)
{
  const char *v3; // eax
  int v4; // eax
  ISaveRestoreFileSystem_vtbl *v5; // edi
  bool v6; // al
  int v7; // [esp-8h] [ebp-114h]
  char szName[260]; // [esp+8h] [ebp-104h] BYREF

  if ( bIsXSave )
  {
    szName[0] = 0;
    v7 = 260 - _V_strlen(str: szName);
    v4 = _V_strlen(str: szName);
    V_snprintf(pDest: &szName[v4], maxLen: v7, pFormat: "//mod/");
  }
  else
  {
    v3 = this->GetSaveDir(this);
    V_snprintf(pDest: szName, maxLen: 260, pFormat: "%s", v3);
    V_FixSlashes(pname: szName, separator: 92);
    Sys_mkdir(path: szName);
  }
  V_strncat(pDest: szName, pSrc: "*.HL?", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v5 = g_pSaveRestoreFileSystem->__vftable;
  v6 = this->IsXSave(this);
  v5->DirectoryClear(this: g_pSaveRestoreFileSystem, a2: szName, a3: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10190DC0
// Name: public: virtual void CSaveRestore::RequestClearSaveDir(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::RequestClearSaveDir(CSaveRestore *this)
{
  this->m_bClearSaveDir = true;
}

//------------------------------------------------------------------------------
// Address: 0x10190F30
// Name: AutoSave_Silent
// Source: json
//------------------------------------------------------------------------------
void __usercall AutoSave_Silent(int a1@<edi>, int a2@<esi>, bool bDangerous)
{
  int v3; // edi
  int (__thiscall *GetMostRecentElapsedSeconds)(ISaveRestore *); // edx
  int v5; // eax
  void (__thiscall *GetSaveComment)(IServerGameDLL *, char *, int, float, float, bool); // edx
  float v7; // [esp+Ch] [ebp-60h]
  char comment[80]; // [esp+14h] [ebp-58h] BYREF
  float v9; // [esp+64h] [ebp-8h]
  int v10; // [esp+68h] [ebp-4h]

  if ( !g_bInCommentaryMode
    && saverestore->IsValidSave(this: saverestore) != 0
    && serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
  {
    v3 = (int)(float)(g_ServerGlobalVariables.curtime
                    - (float)((int (__thiscall *)(ISaveRestore *, int, int))saverestore->GetMostRecentElapsedTimeSet)(
                               a1: saverestore,
                               a2: a1,
                               a3: a2));
    v10 = v3 / 60 + saverestore->GetMostRecentElapsedMinutes(this: saverestore);
    GetMostRecentElapsedSeconds = saverestore->GetMostRecentElapsedSeconds;
    v9 = (float)v10;
    v5 = GetMostRecentElapsedSeconds(this: saverestore);
    GetSaveComment = serverGameDLL->GetSaveComment;
    v10 = v3 % 60 + v5;
    v7 = (float)v10;
    ((void (__thiscall *)(IServerGameDLL *, char *, int, _DWORD, _DWORD, _DWORD))GetSaveComment)(
      a1: serverGameDLL,
      a2: comment,
      a3: 80,
      a4: LODWORD(v9),
      a5: LODWORD(v7),
      a6: 0);
    saverestore->SetIsXSave(this: saverestore, a2: false);
    *(_DWORD *)&comment[4] = 0;
    *(_DWORD *)comment = 0;
    if ( bDangerous )
      ((void (__thiscall *)(ISaveRestore *, const char *, char *, _DWORD, _DWORD))saverestore->SaveGameSlot)(
        a1: saverestore,
        a2: "autosavedangerous",
        a3: comment,
        a4: 0,
        a5: 0);
    else
      ((void (__thiscall *)(ISaveRestore *, const char *, char *, _DWORD, int))saverestore->SaveGameSlot)(
        a1: saverestore,
        a2: "autosave",
        a3: comment,
        a4: 0,
        a5: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191060
// Name: _autosave
// Source: json
//------------------------------------------------------------------------------
void __usercall autosave(int a1@<edi>, int a2@<esi>)
{
  AutoSave_Silent(a1, a2, bDangerous: false);
}

//------------------------------------------------------------------------------
// Address: 0x10191070
// Name: _autosavedangerous
// Source: json
//------------------------------------------------------------------------------
void __usercall autosavedangerous(int a1@<edi>, int a2@<esi>)
{
  if ( saverestore->StorageDeviceValid(this: saverestore) )
    AutoSave_Silent(a1, a2, bDangerous: true);
}

//------------------------------------------------------------------------------
// Address: 0x10191090
// Name: autosavedangerousissafe
// Source: json
//------------------------------------------------------------------------------
void __cdecl autosavedangerousissafe()
{
  saverestore->AutoSaveDangerousIsSafe(this: saverestore);
}

//------------------------------------------------------------------------------
// Address: 0x101910A0
// Name: LoadSaveGame
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSaveGame(const char *savename@<esi>, int a2@<edi>, bool bLetToolsOverrideLoadGameEnts)
{
  int v3; // ecx
  IEngineVGuiInternal *v4; // eax

  if ( ((unsigned __int8 (__thiscall *)(ISaveRestore *))saverestore->SaveFileExists)(a1: saverestore) != 0 )
  {
    CTestScriptMgr::SetWaitCheckPoint(this: &g_TestScriptMgr, pCheckPointName: "load_game", bOnce: false);
    if ( sv.m_State < ss_active || sv.m_bIsLevelMainMenuBackground )
    {
      v4 = EngineVGui();
      v4->EnabledProgressBarForNextLoad(this: v4);
    }
    SCR_BeginLoadingPlaque(a1: v3, a2, levelName: nullptr);
    Host_Disconnect(bShowMainMenu: false);
    HostState_LoadGame(pSaveFileName: savename, remember_location: false, bLetToolsOverrideLoadGameEnts);
  }
  else
  {
    _Warning(a1: "Can't load '%s', file missing!\n", savename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191120
// Name: void SetLoadLaunchOptions(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLoadLaunchOptions()
{
  KeyValues *v0; // eax
  KeyValues *v1; // eax

  if ( g_pLaunchOptions != nullptr )
    KeyValues::deleteThis(this: g_pLaunchOptions);
  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr )
    v1 = KeyValues::KeyValues(this: v0, setName: "LaunchOptions");
  else
    v1 = nullptr;
  g_pLaunchOptions = v1;
  KeyValues::SetString(this: v1, keyName: "Arg0", value: "load");
  KeyValues::SetString(this: g_pLaunchOptions, keyName: "Arg1", value: "reserved");
}

//------------------------------------------------------------------------------
// Address: 0x10191180
// Name: g_load_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_load_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S12 & 1) == 0 )
  {
    _S12 |= 1u;
    loadComplete.m_pszCommandName = "load";
    loadComplete.m_pszSubDir = "save";
    loadComplete.m_pszExtension = "sav";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &loadComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x101911D0
// Name: public: virtual void CSaveRestore::SetIsXSave(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::SetIsXSave(CSaveRestore *this, bool bIsXSave)
{
  this->m_bIsXSave = bIsXSave;
}

//------------------------------------------------------------------------------
// Address: 0x101911E0
// Name: public: virtual void CSaveRestore::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::Shutdown(CSaveRestore *this)
{
  this->FinishAsyncSave(this);
  if ( g_pSaveThread != nullptr )
  {
    g_pSaveThread->Stop(this: g_pSaveThread, a2: -1);
    g_pSaveThread->Release(this: g_pSaveThread);
    g_pSaveThread = nullptr;
  }
  this->m_szSaveGameScreenshotFile[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10191220
// Name: public: virtual char const __near * CSaveRestore::GetMostRecentlyLoadedFileName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestore::GetMostRecentlyLoadedFileName(CSaveRestore *this)
{
  return this->m_szMostRecentSaveLoadGame;
}

//------------------------------------------------------------------------------
// Address: 0x10191230
// Name: public: virtual char const __near * CSaveRestore::GetSaveFileName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestore::GetSaveFileName(CSaveRestore *this)
{
  return this->m_szSaveGameName;
}

//------------------------------------------------------------------------------
// Address: 0x10191240
// Name: public: virtual bool CSaveRestore::SaveGame(char const __near *,bool,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::SaveGame(
        CSaveRestore *this,
        const char *pSaveFilename,
        BOOL bIsXSave,
        char *pOutName,
        int nOutNameSize,
        char *pOutComment,
        int nOutCommentSize)
{
  int v9; // edi
  int (__thiscall *GetMostRecentElapsedSeconds)(ISaveRestore *); // eax
  float v11; // [esp+8h] [ebp-68h]
  char comment[80]; // [esp+1Ch] [ebp-54h] BYREF
  float v13; // [esp+6Ch] [ebp-4h]
  int bIsXSavea; // [esp+7Ch] [ebp+Ch]

  if ( saverestore->IsValidSave(this: saverestore) == 0 || !serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
    return false;
  saverestore->SetIsXSave(this: saverestore, a2: bIsXSave);
  v9 = (int)(float)(g_ServerGlobalVariables.curtime - (float)saverestore->GetMostRecentElapsedTimeSet(this: saverestore));
  bIsXSavea = v9 / 60 + saverestore->GetMostRecentElapsedMinutes(this: saverestore);
  GetMostRecentElapsedSeconds = saverestore->GetMostRecentElapsedSeconds;
  v13 = (float)bIsXSavea;
  v11 = (float)(v9 % 60 + GetMostRecentElapsedSeconds(this: saverestore));
  ((void (__thiscall *)(IServerGameDLL *, char *, int, _DWORD, _DWORD, _DWORD))serverGameDLL->GetSaveComment)(
    a1: serverGameDLL,
    a2: comment,
    a3: 80,
    a4: LODWORD(v13),
    a5: LODWORD(v11),
    a6: 0);
  CSaveRestore::CalcSaveGameName(this, pName: pSaveFilename, output: pOutName, outputStringLength: nOutNameSize);
  V_strncpy(pDest: pOutComment, pSrc: comment, maxLen: nOutCommentSize);
  return saverestore->SaveGameSlot(
           this: saverestore,
           a2: pSaveFilename,
           a3: comment,
           a4: false,
           a5: true,
           a6: nullptr,
           a7: nullptr) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101913B0
// Name: private: void CSaveRestore::AgeSaveList(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveRestore::AgeSaveList(
        CSaveRestore *this@<ecx>,
        int a2@<edi>,
        const char *pName,
        int count,
        bool bIsXSave)
{
  int i; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int m_nValue; // eax
  int v14; // [esp-14h] [ebp-224h]
  int v15; // [esp-14h] [ebp-224h]
  int v16; // [esp-10h] [ebp-220h]
  const char *v17; // [esp-Ch] [ebp-21Ch]
  const char *v18; // [esp-Ch] [ebp-21Ch]
  const char *v19; // [esp-8h] [ebp-218h]
  int v20; // [esp-8h] [ebp-218h]
  int v21; // [esp-8h] [ebp-218h]
  const char *v23; // [esp-4h] [ebp-214h]
  const char *v24; // [esp-4h] [ebp-214h]
  const char *v25; // [esp-4h] [ebp-214h]
  char str[260]; // [esp+8h] [ebp-208h] BYREF
  char pDest[260]; // [esp+10Ch] [ebp-104h] BYREF

  for ( i = count; i > 0; --i )
  {
    if ( ((unsigned __int8 (__thiscall *)(CSaveRestore *, int))this->IsXSave)(a1: this, a2) != 0 )
    {
      pDest[0] = 0;
      if ( i == 1 )
      {
        v16 = 260 - _V_strlen(str: pDest);
        v10 = _V_strlen(str: pDest);
        V_snprintf(pDest: &pDest[v10], maxLen: v16, pFormat: "//mod/%s.%s", pName, "sav");
      }
      else
      {
        v14 = 260 - _V_strlen(str: pDest);
        v11 = _V_strlen(str: pDest);
        V_snprintf(pDest: &pDest[v11], maxLen: v14, pFormat: "//mod/%s%02d.%s", pName, i - 1, "sav");
      }
      str[0] = 0;
      v15 = 260 - _V_strlen(str);
      v12 = _V_strlen(str);
      V_snprintf(pDest: &str[v12], maxLen: v15, pFormat: "//mod/%s%02d.%s", pName, i, "sav");
    }
    else
    {
      if ( i == 1 )
      {
        v7 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, const char *))this->GetSaveDir)(
                             a1: this,
                             a2: pName,
                             a3: "sav");
        V_snprintf(pDest, maxLen: 260, pFormat: "//%s/%s%s.%s", "MOD", v7, v19, v23);
      }
      else
      {
        v8 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, int, const char *))this->GetSaveDir)(
                             a1: this,
                             a2: pName,
                             a3: i - 1,
                             a4: "sav");
        V_snprintf(pDest, maxLen: 260, pFormat: "//%s/%s%s%02d.%s", "MOD", v8, v17, v20, v24);
      }
      v9 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, int, const char *))this->GetSaveDir)(
                           a1: this,
                           a2: pName,
                           a3: i,
                           a4: "sav");
      V_snprintf(pDest: str, maxLen: 260, pFormat: "//%s/%s%s%02d.%s", "MOD", v9, v18, v21, v25);
    }
    a2 = 0;
    if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))g_pFileSystem->FileExists)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: pDest) != 0 )
    {
      if ( save_history_count.m_pParent != nullptr )
        m_nValue = save_history_count.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( i == m_nValue && g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: str, a3: nullptr) )
        g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: str, a3: nullptr);
      g_pFileSystem->RenameFile(this: g_pFileSystem, a2: pDest, a3: str, a4: nullptr);
    }
    CSaveRestore::AgeSaveFile(this, pName, ext: "tga", count: i, bIsXSave);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101916B0
// Name: void Host_Loadgame_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Loadgame_f(int a1@<edi>, const CCommand *args)
{
  bool bLetToolsOverrideLoadGameEnts; // [esp+0h] [ebp-4h]

  if ( cmd_source == src_command )
  {
    if ( sv.m_nMaxclients <= 1
      || save_multiplayer_override.m_pParent != nullptr && save_multiplayer_override.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
      {
        if ( args->m_nArgc >= 2 )
        {
          g_szMapLoadOverride[0] = 0;
          bLetToolsOverrideLoadGameEnts = false;
          if ( args->m_nArgc > 2 )
          {
            V_strncpy(pDest: g_szMapLoadOverride, pSrc: args->m_ppArgv[2], maxLen: 32);
            if ( g_szMapLoadOverride[0] == 42
              && args->m_nArgc > 3
              && _V_stricmp(s1: args->m_ppArgv[3], s2: "LetToolsOverrideLoadGameEnts") == 0 )
            {
              g_szMapLoadOverride[0] = 0;
              bLetToolsOverrideLoadGameEnts = true;
            }
          }
          saverestore->SetIsXSave(this: saverestore, a2: false);
          SetLoadLaunchOptions();
          if ( args->m_nArgc > 1 )
            LoadSaveGame(savename: args->m_ppArgv[1], a2: a1, bLetToolsOverrideLoadGameEnts);
          else
            LoadSaveGame(savename: defaultValue, a2: a1, bLetToolsOverrideLoadGameEnts);
        }
        else
        {
          ConMsg(a1: "load <savename>: load a game\n");
        }
      }
      else
      {
        ConMsg(a1: "This game doesn't support save/restore.");
      }
    }
    else
    {
      ConMsg(a1: "Can't load in multiplayer games.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101917D0
// Name: xload
// Source: json
//------------------------------------------------------------------------------
void __usercall xload(int a1@<edi>, const CCommand *args)
{
  if ( sv.m_nMaxclients <= 1
    || save_multiplayer_override.m_pParent != nullptr && save_multiplayer_override.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
    {
      if ( args->m_nArgc == 2 )
      {
        saverestore->SetIsXSave(this: saverestore, a2: false);
        SetLoadLaunchOptions();
        if ( args->m_nArgc > 1 )
          LoadSaveGame(savename: args->m_ppArgv[1], a2: a1, bLetToolsOverrideLoadGameEnts: false);
        else
          LoadSaveGame(savename: defaultValue, a2: a1, bLetToolsOverrideLoadGameEnts: false);
      }
      else
      {
        ConMsg(a1: "xload <savename>\n");
      }
    }
    else
    {
      ConMsg(a1: "This game doesn't support save/restore.");
    }
  }
  else
  {
    ConMsg(a1: "Can't load in multiplayer games.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191880
// Name: public: virtual bool CSaveRestore::IsSaveInProgress(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveRestore::IsSaveInProgress(CSaveRestore *this)
{
  return g_bSaveInProgress.m_value != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10191890
// Name: public: virtual bool CSaveRestore::IsAutoSaveDangerousInProgress(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSaveRestore::IsAutoSaveDangerousInProgress(CSaveRestore *this)
{
  return g_bAutoSaveDangerousInProgress.m_value != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101918A0
// Name: class CSaveMemory __near & GetSaveMemory(void)
// Source: json
//------------------------------------------------------------------------------
CSaveMemory *__cdecl GetSaveMemory()
{
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  return &g_SaveMemory;
}

//------------------------------------------------------------------------------
// Address: 0x101918F0
// Name: void __near * SaveAllocMemory(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl SaveAllocMemory(unsigned int num, unsigned int size, bool bClear)
{
  unsigned int m_alignment; // ecx
  unsigned int v4; // esi
  unsigned __int8 *v5; // edi
  unsigned __int8 *m_pNextAlloc; // ebx

  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  ++g_SaveMemory.m_nSaveAllocs;
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  m_alignment = size * num;
  if ( size * num <= g_SaveMemory.m_alignment )
    m_alignment = g_SaveMemory.m_alignment;
  v4 = ~(g_SaveMemory.m_alignment - 1) & (g_SaveMemory.m_alignment + m_alignment - 1);
  v5 = &g_SaveMemory.m_pNextAlloc[v4];
  m_pNextAlloc = g_SaveMemory.m_pNextAlloc;
  if ( &g_SaveMemory.m_pNextAlloc[v4] > g_SaveMemory.m_pCommitLimit
    && !CMemoryStack::CommitTo(this: &g_SaveMemory, pNextAlloc: &g_SaveMemory.m_pNextAlloc[v4]) )
  {
    return nullptr;
  }
  if ( bClear )
    memset(dst: m_pNextAlloc, value: 0, count: v4);
  g_SaveMemory.m_pNextAlloc = v5;
  return m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x101919F0
// Name: void SaveFreeMemory(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveFreeMemory()
{
  CSaveMemory *SaveMemory; // eax

  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  --g_SaveMemory.m_nSaveAllocs;
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  if ( g_SaveMemory.m_nSaveAllocs == 0 )
  {
    SaveMemory = GetSaveMemory();
    CMemoryStack::FreeAll(this: SaveMemory, bDecommit: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191AA0
// Name: void SaveResetMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveResetMemory()
{
  CSaveMemory *SaveMemory; // eax
  int m_nSaveAllocs; // [esp+8h] [ebp-10h]
  int v2; // [esp+14h] [ebp-4h]

  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  if ( g_SaveMemory.m_pNextAlloc != g_SaveMemory.m_pBase )
  {
    SaveMemory = GetSaveMemory();
    v2 = SaveMemory->m_pNextAlloc - SaveMemory->m_pBase;
    m_nSaveAllocs = GetSaveMemory()->m_nSaveAllocs;
    _Msg(
      a1: "\n\n !!!! SAVEGAME: !!!! %3.1fMB(%d) remain in SaveResetMemory\n\n\n",
      (double)(unsigned int)v2 * 0.00000095367432,
      m_nSaveAllocs);
  }
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  g_SaveMemory.m_nSaveAllocs = 0;
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    CMemoryStack::CMemoryStack(this: &g_SaveMemory);
    CMemoryStack::Init(
      this: &g_SaveMemory,
      pszAllocOwner: "g_SaveMemory",
      maxSize: 0x2000000u,
      commitSize: 0x10000u,
      initialCommit: 0,
      alignment: 0x10u);
    atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
  }
  CMemoryStack::FreeAll(this: &g_SaveMemory, bDecommit: true);
}

//------------------------------------------------------------------------------
// Address: 0x10191BE0
// Name: public: virtual int CSaveRestore::IsValidSave(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::IsValidSave(CSaveRestore *this)
{
  IClient *v2; // ecx
  CPlayerState *v3; // eax

  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    return 0;
  if ( sv.m_State < ss_active )
  {
    ConMsg(a1: "Not playing a local game.\n");
    return 0;
  }
  if ( GetBaseLocalClient()->m_nSignonState != 6 )
  {
    ConMsg(a1: "Can't save if not active.\n");
    return 0;
  }
  if ( sv.m_nMaxclients > 1
    && (save_multiplayer_override.m_pParent == nullptr || save_multiplayer_override.m_pParent->m_Value.m_nValue == 0) )
  {
    ConMsg(a1: "Can't save multiplayer games.\n");
    return 0;
  }
  if ( sv.m_Clients.m_Size <= 0 )
    return 1;
  v2 = *sv.m_Clients.m_Memory.m_pMemory != nullptr ? &(*sv.m_Clients.m_Memory.m_pMemory)->IClient : nullptr;
  if ( !v2->IsActive(this: v2) )
    return 1;
  v3 = serverGameClients->GetPlayerState(
         this: serverGameClients,
         a2: *(_DWORD *)(*sv.m_Clients.m_Memory.m_pMemory)[1].m_GUID);
  if ( v3 == nullptr )
  {
    ConMsg(a1: "Can't savegame without a player!\n");
    return 0;
  }
  if ( !v3->deadflag.m_Value || bugreporter->IsVisible(this: bugreporter) )
    return 1;
  ConMsg(a1: "Can't savegame with a dead player\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10191CE0
// Name: public: virtual void CSaveRestore::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::Init(CSaveRestore *this)
{
  CSaveRestore *v1; // esi
  int v2; // eax
  ThreadPoolStartParams_t threadPoolStartParams; // [esp+8h] [ebp-124h] BYREF
  int dummy2; // [esp+11Ch] [ebp-10h] BYREF
  CSaveRestore *v5; // [esp+120h] [ebp-Ch]
  int dummy; // [esp+124h] [ebp-8h] BYREF
  int minplayers; // [esp+128h] [ebp-4h] BYREF

  v1 = this;
  v5 = this;
  minplayers = 1;
  if ( serverGameClients == nullptr
    || (dummy = 1,
        dummy2 = 1,
        serverGameClients->GetPlayerLimits(this: serverGameClients, a2: &minplayers, a3: &dummy, a4: &dummy2),
        serverGameClients == nullptr)
    || minplayers == 1 )
  {
    if ( (_S3_5 & 1) == 0 )
    {
      _S3_5 |= 1u;
      CMemoryStack::CMemoryStack(this: &g_SaveMemory);
      CMemoryStack::Init(
        this: &g_SaveMemory,
        pszAllocOwner: "g_SaveMemory",
        maxSize: 0x2000000u,
        commitSize: 0x10000u,
        initialCommit: 0,
        alignment: 0x10u);
      atexit(func: GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__);
    }
    threadPoolStartParams.nStackSize = -1;
    threadPoolStartParams.iThreadPriority = -32768;
    *((_BYTE *)&threadPoolStartParams + 272) &= 0xFCu;
    if ( (*((_BYTE *)&threadPoolStartParams + 272) & 2) != 0 )
    {
      qmemcpy(threadPoolStartParams.iAffinityTable, nullptr, sizeof(threadPoolStartParams.iAffinityTable));
      v1 = v5;
    }
    threadPoolStartParams.nThreads = 1;
    threadPoolStartParams.fDistribute = TRS_FALSE;
    g_pSaveThread = (IThreadPool *)_CreateNewThreadPool();
    g_pSaveThread->Start(this: g_pSaveThread, a2: &threadPoolStartParams, a3: "SaveJob");
  }
  v1->m_nDeferredCommandFrames = 0;
  v1->m_szSaveGameScreenshotFile[0] = 0;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noclearsave") == 0 )
    v1->ClearSaveDir(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10191E10
// Name: public: virtual void CMemberFunctor1<class CSaveRestore __near *,void (CSaveRestore::*)(bool),bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CSaveRestore *,void (__thiscall CSaveRestore::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CSaveRestore *,void (__thiscall CSaveRestore::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10191E20
// Name: public: virtual void CMemberFunctor0<class IFileSystem __near *,void (IFileSystem::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<IFileSystem *,void (__thiscall IFileSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<IFileSystem *,void (__thiscall IFileSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + HIDWORD(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x10191E30
// Name: public: virtual void CMemberFunctor1<class IXboxSystem __near *,void (IXboxSystem::*)(int),int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<IXboxSystem *,void (__thiscall IXboxSystem::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<IXboxSystem *,void (__thiscall IXboxSystem::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10192500
// Name: private: void CSaveRestore::ReapplyDecal(bool,struct CSaveRestore::RestoreLookupTable __near *,struct decallist_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CSaveRestore::ReapplyDecal(
        CSaveRestore *this@<ecx>,
        CTraceFilterHitAll_vtbl *a2@<ebp>,
        bool adjacent,
        CSaveRestore::RestoreLookupTable *table,
        decallist_t *entry)
{
  decallist_t *v5; // edi
  float x; // ecx
  int z_low; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  const edict_t *Edict; // eax
  int v13; // eax
  IClientEntity *v14; // esi
  char *name; // edi
  CVEfx_vtbl *v16; // edi
  IClientEntity_vtbl *v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  __int16 entityIndex; // cx
  int m_Size; // esi
  int v23; // eax
  int v24; // edi
  CSaveRestore::SaveRestoreTranslate *m_pMemory; // ecx
  float v26; // esi
  IClientEntity *v27; // eax
  model_t *Model; // eax
  edict_t *v29; // eax
  IServerUnknown *m_pUnk; // ecx
  int v31; // eax
  char *v32; // edi
  int v33; // esi
  _BYTE v34[12]; // [esp-Ch] [ebp-F4h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-E8h] BYREF
  float v36; // [esp+54h] [ebp-94h]
  Ray_t ray; // [esp+58h] [ebp-90h] BYREF
  _BYTE v38[12]; // [esp+A8h] [ebp-40h] BYREF
  Vector vecOrigin; // [esp+B4h] [ebp-34h]
  int v40; // [esp+C0h] [ebp-28h]
  float oldlock; // [esp+C4h] [ebp-24h] OVERLAPPED BYREF
  int entityToHit; // [esp+C8h] [ebp-20h]
  int flags; // [esp+CCh] [ebp-1Ch]
  QAngle vecAngle; // [esp+D0h] [ebp-18h] BYREF
  CTraceFilterHitAll traceFilter; // [esp+DCh] [ebp-Ch]
  const model_t *pModel; // [esp+E0h] [ebp-8h]
  const model_t *retaddr; // [esp+E8h] [ebp+0h]

  traceFilter.__vftable = a2;
  pModel = retaddr;
  v5 = entry;
  v40 = entry->flags;
  if ( adjacent )
    v40 |= 0x800u;
  LOBYTE(vecOrigin.y) = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  if ( adjacent )
  {
    x = entry->position.x;
    z_low = SLODWORD(entry->position.z);
    v8 = entry->impactPlaneNormal.x * 5.0;
    v9 = entry->impactPlaneNormal.y * 5.0;
    v10 = entry->impactPlaneNormal.z * 5.0;
    v11 = v8 + entry->position.x;
    entityToHit = SLODWORD(entry->position.y);
    oldlock = x;
    flags = z_low;
    ray.m_Start.y = (float)(x - v8) - v11;
    ray.m_Start.z = (float)(*(float *)&entityToHit - v9) - (float)(v9 + *(float *)&entityToHit);
    ray.m_Start.w = (float)(*(float *)&z_low - v10) - (float)(v10 + *(float *)&z_low);
    vecAngle.y = (float)((float)(ray.m_Start.y * ray.m_Start.y) + (float)(ray.m_Start.z * ray.m_Start.z))
               + (float)(ray.m_Start.w * ray.m_Start.w);
    LODWORD(vecAngle.x) = &CTraceFilterHitAll::`vftable';
    BYTE1(ray.m_Extents.z) = vecAngle.y != 0.0;
    memset(&ray.m_StartOffset.y, 0, 12);
    ray.m_Extents.y = 0.0;
    LOBYTE(ray.m_Extents.z) = 1;
    memset(&ray.m_Delta.y, 0, 12);
    *(float *)&tr.m_pEnt = v11;
    *(float *)&tr.hitbox = v9 + *(float *)&entityToHit;
    v36 = v10 + *(float *)&z_low;
    g_pEngineTraceServer->TraceRay(
      this: g_pEngineTraceServer,
      a2: (const Ray_t *)&tr.m_pEnt,
      a3: 16513u,
      a4: (ITraceFilter *)&vecAngle,
      a5: (CGameTrace *)v34);
    if ( tr.plane.normal.z != 1.0
      && tr.plane.pad[0] == 0
      && entry->impactPlaneNormal.x * tr.endpos.x
       + entry->impactPlaneNormal.y * tr.endpos.y
       + tr.endpos.z * entry->impactPlaneNormal.z >= 0.99 )
    {
      Edict = CGameTrace::GetEdict(this: (CGameTrace *)v34);
      if ( Edict != nullptr )
      {
        v13 = NUM_FOR_EDICTINFO(e: Edict);
        LODWORD(vecOrigin.z) = v13;
        if ( v13 >= 0 )
        {
          v14 = entitylist->GetClientEntity(this: entitylist, a2: v13);
          if ( v14 == nullptr )
            return;
          name = entry->name;
          HIBYTE(vecAngle.z) = 0;
          LODWORD(vecAngle.y) = Draw_DecalIndexFromName(name: entry->name, found: (bool *)&vecAngle.z + 3);
          if ( HIBYTE(vecAngle.z) == 0 )
          {
            LODWORD(vecAngle.y) = CGameServer::PrecacheDecal(this: &sv, name, flags: 1);
            Draw_DecalSetName(decal: SLODWORD(vecAngle.y), name);
          }
          v16 = g_pEfx->__vftable;
          v17 = v14->IClientUnknown::IHandleEntity::__vftable;
          LODWORD(vecOrigin.x) = &v14->IClientRenderable;
          v18 = ((int (__thiscall *)(IClientEntity *, decallist_t *, _DWORD, int, Vector *))v17->GetAbsAngles)(
                  a1: v14,
                  a2: entry,
                  a3: 0,
                  a4: v40,
                  a5: &tr.endpos);
          v19 = ((int (__thiscall *)(IClientEntity *, int))v14->GetAbsOrigin)(a1: v14, a2: v18);
          v20 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)LODWORD(vecOrigin.x) + 32))(
                  a1: LODWORD(vecOrigin.x),
                  a2: v19);
          ((void (__thiscall *)(CVEfx *, _DWORD, _DWORD, int))v16->DecalShoot)(
            a1: g_pEfx,
            a2: LODWORD(vecAngle.y),
            a3: LODWORD(vecOrigin.z),
            a4: v20);
        }
      }
    }
    goto LABEL_34;
  }
  entityIndex = entry->entityIndex;
  if ( entityIndex == 0 )
  {
    vecAngle.x = 0.0;
    goto LABEL_22;
  }
  m_Size = table->lookup.m_Size;
  v23 = 0;
  if ( m_Size <= 0 )
  {
LABEL_19:
    vecAngle.x = NAN;
LABEL_22:
    v26 = vecAngle.x;
    goto LABEL_23;
  }
  v24 = entityIndex;
  m_pMemory = table->lookup.m_Memory.m_pMemory;
  while ( m_pMemory->savedindex != v24 )
  {
    ++v23;
    ++m_pMemory;
    if ( v23 >= m_Size )
    {
      v5 = entry;
      goto LABEL_19;
    }
  }
  v26 = *(float *)&m_pMemory->restoredindex;
  v5 = entry;
  vecAngle.x = v26;
LABEL_23:
  if ( v26 >= 0.0 )
  {
    memset(v38, 0, sizeof(v38));
    oldlock = 0.0;
    *(float *)&entityToHit = 0.0;
    flags = 0;
    v27 = entitylist->GetClientEntity(this: entitylist, a2: LODWORD(v26));
    if ( v27 != nullptr )
    {
      Model = (model_t *)v27->GetModel(this: &v27->IClientRenderable);
    }
    else
    {
      v29 = EDICT_NUM(n: SLODWORD(v26));
      if ( v29 == nullptr )
        goto LABEL_34;
      if ( (v29->m_fStateFlags & 4) == 0 )
        goto LABEL_34;
      m_pUnk = v29->m_pUnk;
      if ( m_pUnk == nullptr )
        goto LABEL_34;
      v31 = ((int (__thiscall *)(IServerUnknown *))m_pUnk->__vftable[1].dtr_IHandleEntity)(a1: m_pUnk);
      Model = CGameServer::GetModel(this: &sv, index: v31);
    }
    LODWORD(vecAngle.y) = Model;
    if ( Model != nullptr )
    {
      v32 = v5->name;
      HIBYTE(vecAngle.z) = 0;
      v33 = Draw_DecalIndexFromName(name: v32, found: (bool *)&vecAngle.z + 3);
      if ( HIBYTE(vecAngle.z) == 0 )
      {
        v33 = CGameServer::PrecacheDecal(this: &sv, name: v32, flags: 1);
        Draw_DecalSetName(decal: v33, name: v32);
      }
      g_pEfx->DecalShoot(
        this: g_pEfx,
        a2: v33,
        a3: LODWORD(vecAngle.x),
        a4: (const model_t *)LODWORD(vecAngle.y),
        a5: (const Vector *)v38,
        a6: (const QAngle *)&oldlock,
        a7: (const Vector *)entry,
        a8: nullptr,
        a9: v40,
        a10: nullptr);
    }
  }
LABEL_34:
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: SLODWORD(vecOrigin.y));
}

//------------------------------------------------------------------------------
// Address: 0x10193090
// Name: public: virtual void CSaveRestore::OnFrameRendered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::OnFrameRendered(CSaveRestore *this)
{
  int m_nDeferredCommandFrames; // eax
  int v3; // eax
  int i; // edi
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  bool v7; // sf
  const char *v8; // [esp-Ch] [ebp-10h]

  m_nDeferredCommandFrames = this->m_nDeferredCommandFrames;
  if ( m_nDeferredCommandFrames > 0 )
  {
    v3 = m_nDeferredCommandFrames - 1;
    this->m_nDeferredCommandFrames = v3;
    if ( v3 == 0 )
    {
      for ( i = 0; i < this->m_sDeferredCommands.m_Size; ++i )
      {
        v8 = CUtlSymbol::String(this: &this->m_sDeferredCommands.m_Memory.m_pMemory[i]);
        TraceType = CTraceFilter::GetTraceType(this: v5);
        Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
      }
      v7 = this->m_sDeferredCommands.m_Memory.m_nGrowSize < 0;
      this->m_sDeferredCommands.m_Size = 0;
      if ( !v7 )
      {
        if ( this->m_sDeferredCommands.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sDeferredCommands.m_Memory.m_pMemory);
          this->m_sDeferredCommands.m_Memory.m_pMemory = nullptr;
        }
        this->m_sDeferredCommands.m_Memory.m_nAllocationCount = 0;
      }
      this->m_sDeferredCommands.m_pElements = this->m_sDeferredCommands.m_Memory.m_pMemory;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193140
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueCall<class CSaveRestore __near *,class CSaveRestore,void,bool,bool>(class CSaveRestore __near *,void (CSaveRestore::*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CSaveRestore *,CSaveRestore,void,bool,bool>(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CSaveRestore *pObject,
        void (__thiscall *pfnProxied)(CSaveRestore *this, bool),
        const bool *arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CSaveRestore *,void (__thiscall CSaveRestore::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CSaveRestore *,void (__thiscall CSaveRestore::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    LOBYTE(v5[3].__vftable) = *arg1;
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: v5);
  }
  else
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101931A0
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueCall<class IXboxSystem __near *,class IXboxSystem,void,int,int>(class IXboxSystem __near *,void (IXboxSystem::*)(int),int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<IXboxSystem *,IXboxSystem,void,int,int>(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        IXboxSystem *pObject,
        void (__thiscall *pfnProxied)(IXboxSystem *this, int),
        CFunctor_vtbl **arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<IXboxSystem *,void (__thiscall IXboxSystem::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<IXboxSystem *,void (__thiscall IXboxSystem::*)(int),int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    v5[3].__vftable = *arg1;
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: v5);
  }
  else
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193200
// Name: public: class CJob __near * IThreadPool::QueueCall<class CSaveRestore,class CSaveRestore,void>(class CSaveRestore __near *,void (CSaveRestore::*)(void))
// Source: json
//------------------------------------------------------------------------------
CJob *__thiscall IThreadPool::QueueCall<CSaveRestore,CSaveRestore,void>(
        IThreadPool *this,
        CSaveRestore *pObject,
        void (__thiscall *pfnProxied)(CSaveRestore *this))
{
  CFunctor *v4; // eax
  CJob *pJob; // [esp+4h] [ebp-4h] BYREF

  v4 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CSaveRestore *,void (__thiscall CSaveRestore::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CSaveRestore *,void (__thiscall CSaveRestore::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4[2].m_nUserID = (unsigned int)pObject;
  }
  else
  {
    v4 = nullptr;
  }
  this->AddFunctorInternal(this, a2: v4, a3: &pJob, a4: nullptr, a5: 8u);
  return pJob;
}

//------------------------------------------------------------------------------
// Address: 0x10193270
// Name: public: virtual void CMemberFunctor3<class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,int,bool),class CUtlEnvelope<char const __near *>,int,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,int,bool),CUtlEnvelope<char const *>,int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,int,bool),CUtlEnvelope<char const *>,int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  const char *v2; // eax

  v2 = CUtlString::operator char const *(this: &this->m_arg1.m_string);
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: v2, a3: this->m_arg2, a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x101932A0
// Name: public: virtual void CMemberFunctor3<class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  const char *v2; // edi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: &this->m_arg2.m_string);
  v3 = CUtlString::operator char const *(this: &this->m_arg1.m_string);
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: v3, a3: v2, a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x101932D0
// Name: public: virtual CMemberFunctor3<class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::~CMemberFunctor3<class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::~CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_arg2.m_string.m_Storage.m_nActualLength = 0;
  if ( this->m_arg2.m_string.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory);
      this->m_arg2.m_string.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_arg2.m_string.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_arg1.m_string.m_Storage.m_nActualLength = 0;
  if ( this->m_arg1.m_string.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory);
      this->m_arg1.m_string.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_arg1.m_string.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CFunctor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10193330
// Name: public: virtual void CFunctor1<void (*)(char const __near *),class CUtlEnvelope<char const __near *>,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor1<void (__cdecl *)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor1<void (__cdecl*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  const char *v2; // eax

  v2 = CUtlString::Get(this: &this->m_arg1.m_string);
  this->m_pfnProxied(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101934F0
// Name: public: CSaveRestore::RestoreLookupTable::RestoreLookupTable(struct CSaveRestore::RestoreLookupTable const __near &)
// Source: json
//------------------------------------------------------------------------------
CSaveRestore::RestoreLookupTable *__thiscall CSaveRestore::RestoreLookupTable::RestoreLookupTable(
        CSaveRestore::RestoreLookupTable *this,
        const CSaveRestore::RestoreLookupTable *src)
{
  const CSaveRestore::RestoreLookupTable *v2; // edx
  int v4; // edi
  int m_nAllocationCount; // eax
  CSaveRestore::SaveRestoreTranslate *v6; // ebx
  CSaveRestore::SaveRestoreTranslate *m_pMemory; // ecx
  int v8; // eax
  CSaveRestore::SaveRestoreTranslate *v9; // eax
  int m_Size; // [esp+4h] [ebp-8h]
  int v12; // [esp+8h] [ebp-4h]

  v2 = src;
  this->lookup.m_Memory.m_pMemory = nullptr;
  this->lookup.m_Memory.m_nAllocationCount = 0;
  this->lookup.m_Memory.m_nGrowSize = 0;
  this->lookup.m_Size = 0;
  this->lookup.m_pElements = nullptr;
  if ( src->lookup.m_Size > 0 )
  {
    v12 = 0;
    m_Size = src->lookup.m_Size;
    do
    {
      v4 = this->lookup.m_Size;
      m_nAllocationCount = this->lookup.m_Memory.m_nAllocationCount;
      v6 = &v2->lookup.m_Memory.m_pMemory[v12];
      if ( v4 + 1 > m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
          num: v4 - m_nAllocationCount + 1);
        v2 = src;
      }
      ++this->lookup.m_Size;
      m_pMemory = this->lookup.m_Memory.m_pMemory;
      v8 = this->lookup.m_Size - v4 - 1;
      this->lookup.m_pElements = this->lookup.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v4 + 1], src: &m_pMemory[v4], count: 12 * v8);
        v2 = src;
      }
      v9 = &this->lookup.m_Memory.m_pMemory[v4];
      if ( v9 != nullptr )
      {
        v9->classname.pszValue = v6->classname.pszValue;
        v9->savedindex = v6->savedindex;
        v9->restoredindex = v6->restoredindex;
      }
      ++v12;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  this->m_vecLandMarkOffset.x = v2->m_vecLandMarkOffset.x;
  this->m_vecLandMarkOffset.y = v2->m_vecLandMarkOffset.y;
  this->m_vecLandMarkOffset.z = v2->m_vecLandMarkOffset.z;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101935C0
// Name: void FinishAsyncSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FinishAsyncSave(void *this)
{
  DWORD CurrentThreadId; // ecx
  DWORD v2; // eax
  unsigned __int8 v3; // al
  int v4; // [esp-Ch] [ebp-Ch]

  if ( (_S2_14 & 1) == 0 )
  {
    _S2_14 |= 1u;
    autoMutex___0.m_ownerID = 0;
    autoMutex___0.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex___0.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex___0, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex___0, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex___0.m_depth;
  }
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = GetCurrentThreadId();
    v3 = _ThreadInMainThread(a1: v2);
    _Msg(a1: "FinishAsyncSave() (%d/%d)\n", v3, v4);
  }
  if ( g_AsyncSaveCallQueue.m_queue.m_Count.m_value != 0 )
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_AsyncSaveCallQueue);
    ((void (__thiscall *)(IFileSystem *, void *))g_pFileSystem->AsyncFinishAllWrites)(a1: g_pFileSystem, a2: this);
  }
  g_SaveRestore.m_MostRecentSaveInfo.m_bValid = false;
  _InterlockedExchange(&g_bAutoSaveDangerousInProgress.m_value, 0);
  _InterlockedExchange(&g_bSaveInProgress.m_value, 0);
  if ( --autoMutex___0.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&autoMutex___0, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101936C0
// Name: void DispatchAsyncSave(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall DispatchAsyncSave(int a1@<ecx>, int a2@<edi>)
{
  BOOL v2; // eax
  ISaveRestore *v3; // esi
  IThreadPool *v4; // edi
  _DWORD *v5; // eax
  int v7; // [esp+0h] [ebp-4h] BYREF

  v7 = a1;
  _InterlockedExchange(&g_bSaveInProgress.m_value, 1);
  v2 = g_SaveRestore.m_MostRecentSaveInfo.m_bValid
    && V_stristr(pStr: g_SaveRestore.m_MostRecentSaveInfo.m_MostRecentSavePath, pSearch: "autosavedangerous") != nullptr;
  _InterlockedExchange(&g_bAutoSaveDangerousInProgress.m_value, v2);
  if ( save_async.m_pParent != nullptr && save_async.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = saverestore;
    v4 = g_pSaveThread;
    v5 = MemAlloc_Alloc(nSize: 0x18u);
    if ( v5 != nullptr )
    {
      v5[3] = 1;
      *v5 = &CMemberFunctor0<ISaveRestore *,void (__thiscall ISaveRestore::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v5[2] = &CMemberFunctor0<ISaveRestore *,void (__thiscall ISaveRestore::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v5[4] =  __thiscall ISaveRestore::`vcall'{128,{flat}};
      v5[5] = v3;
    }
    else
    {
      v5 = nullptr;
    }
    ((void (__thiscall *)(IThreadPool *, _DWORD *, int *, _DWORD, int, int))v4->AddFunctorInternal)(
      a1: v4,
      a2: v5,
      a3: &v7,
      a4: 0,
      a5: 8,
      a6: a2);
  }
  else
  {
    ((void (__thiscall *)(ISaveRestore *, int))saverestore->FinishAsyncSave)(a1: saverestore, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193790
// Name: struct datamap_t __near * DataMapInit<struct GAME_HEADER>(struct GAME_HEADER __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<GAME_HEADER>()
{
  if ( (_S4_2 & 1) == 0 )
  {
    _S4_2 |= 1u;
    nameHolder_2.m_pszBase = "GAME_HEADER";
    nameHolder_2.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_2.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_2.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_2.m_Names.m_Size = 0;
    nameHolder_2.m_Names.m_pElements = nullptr;
    nameHolder_2.m_nLenBase = 11;
    atexit(func: DataMapInit_GAME_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  GAME_HEADER::m_DataMap.baseMap = nullptr;
  GAME_HEADER::m_DataMap.dataNumFields = 5;
  GAME_HEADER::m_DataMap.dataDesc = &dataDesc_2[1];
  return &GAME_HEADER::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193810
// Name: struct datamap_t __near * DataMapInit<struct SAVE_HEADER>(struct SAVE_HEADER __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SAVE_HEADER>()
{
  if ( (_S5_2 & 1) == 0 )
  {
    _S5_2 |= 1u;
    nameHolder_3.m_pszBase = "SAVE_HEADER";
    nameHolder_3.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_3.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_3.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_3.m_Names.m_Size = 0;
    nameHolder_3.m_Names.m_pElements = nullptr;
    nameHolder_3.m_nLenBase = 11;
    atexit(func: DataMapInit_SAVE_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SAVE_HEADER::m_DataMap.baseMap = nullptr;
  SAVE_HEADER::m_DataMap.dataNumFields = 7;
  SAVE_HEADER::m_DataMap.dataDesc = &dataDesc_3[1];
  return &SAVE_HEADER::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193890
// Name: struct datamap_t __near * DataMapInit<struct levellist_t>(struct levellist_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<levellist_t>()
{
  if ( (_S6_1 & 1) == 0 )
  {
    _S6_1 |= 1u;
    nameHolder_4.m_pszBase = "levellist_t";
    nameHolder_4.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_4.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_4.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_4.m_Names.m_Size = 0;
    nameHolder_4.m_Names.m_pElements = nullptr;
    nameHolder_4.m_nLenBase = 11;
    atexit(func: DataMapInit_levellist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  levellist_t::m_DataMap.baseMap = nullptr;
  levellist_t::m_DataMap.dataNumFields = 4;
  levellist_t::m_DataMap.dataDesc = &dataDesc_4[1];
  return &levellist_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193910
// Name: struct datamap_t __near * DataMapInit<struct SAVELIGHTSTYLE>(struct SAVELIGHTSTYLE __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SAVELIGHTSTYLE>()
{
  if ( (_S7_1 & 1) == 0 )
  {
    _S7_1 |= 1u;
    nameHolder_5.m_pszBase = "SAVELIGHTSTYLE";
    nameHolder_5.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_5.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_5.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_5.m_Names.m_Size = 0;
    nameHolder_5.m_Names.m_pElements = nullptr;
    nameHolder_5.m_nLenBase = 14;
    atexit(func: DataMapInit_SAVELIGHTSTYLE__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SAVELIGHTSTYLE::m_DataMap.baseMap = nullptr;
  SAVELIGHTSTYLE::m_DataMap.dataNumFields = 2;
  SAVELIGHTSTYLE::m_DataMap.dataDesc = &dataDesc_5[1];
  return &SAVELIGHTSTYLE::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193990
// Name: public: virtual void CSaveRestore::UpdateSaveGameScreenshots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::UpdateSaveGameScreenshots(CSaveRestore *this)
{
  char *m_szSaveGameScreenshotFile; // esi

  if ( g_LostVideoMemory )
  {
    this->m_szSaveGameScreenshotFile[0] = 0;
  }
  else
  {
    m_szSaveGameScreenshotFile = this->m_szSaveGameScreenshotFile;
    if ( this->m_szSaveGameScreenshotFile[0] != 0 )
    {
      g_ClientGlobalVariables.framecount = ++host_framecount;
      g_ClientDLL->WriteSaveGameScreenshot(this: g_ClientDLL, a2: m_szSaveGameScreenshotFile);
      *m_szSaveGameScreenshotFile = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101939E0
// Name: struct datamap_t __near * DataMapInit<struct musicsave_t>(struct musicsave_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<musicsave_t>()
{
  if ( (_S8_0 & 1) == 0 )
  {
    _S8_0 |= 1u;
    nameHolder_6.m_pszBase = "musicsave_t";
    nameHolder_6.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_6.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_6.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_6.m_Names.m_Size = 0;
    nameHolder_6.m_Names.m_pElements = nullptr;
    nameHolder_6.m_nLenBase = 11;
    atexit(func: DataMapInit_musicsave_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  musicsave_t::m_DataMap.baseMap = nullptr;
  musicsave_t::m_DataMap.dataNumFields = 3;
  musicsave_t::m_DataMap.dataDesc = &dataDesc_6[1];
  return &musicsave_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193A60
// Name: struct datamap_t __near * DataMapInit<struct channelsave>(struct channelsave __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<channelsave>()
{
  if ( (_S9 & 1) == 0 )
  {
    _S9 |= 1u;
    nameHolder_7.m_pszBase = "channelsave";
    nameHolder_7.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_7.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_7.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_7.m_Names.m_Size = 0;
    nameHolder_7.m_Names.m_pElements = nullptr;
    nameHolder_7.m_nLenBase = 11;
    atexit(func: DataMapInit_channelsave__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  channelsave::m_DataMap.baseMap = nullptr;
  channelsave::m_DataMap.dataNumFields = 9;
  channelsave::m_DataMap.dataDesc = &dataDesc_7[1];
  return &channelsave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193AE0
// Name: struct datamap_t __near * DataMapInit<struct decallist_t>(struct decallist_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<decallist_t>()
{
  if ( (_S10 & 1) == 0 )
  {
    _S10 |= 1u;
    nameHolder_8.m_pszBase = "decallist_t";
    nameHolder_8.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_8.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_8.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_8.m_Names.m_Size = 0;
    nameHolder_8.m_Names.m_pElements = nullptr;
    nameHolder_8.m_nLenBase = 11;
    atexit(func: DataMapInit_decallist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  decallist_t::m_DataMap.baseMap = nullptr;
  decallist_t::m_DataMap.dataNumFields = 5;
  decallist_t::m_DataMap.dataDesc = &dataDesc_8[1];
  return &decallist_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10193B60
// Name: public: virtual void CSaveRestore::AutoSaveDangerousIsSafe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::AutoSaveDangerousIsSafe(CSaveRestore *this)
{
  int m_nValue; // edi
  bool v3; // al
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  int v8; // eax
  int v9; // eax
  bool v10; // zf
  void (__thiscall *SetMostRecentSaveGame)(struct CSaveRestore *, const char *); // edx
  int v12; // [esp-Ch] [ebp-21Ch]
  int v13; // [esp-Ch] [ebp-21Ch]
  const char *v14; // [esp-4h] [ebp-214h]
  const char *v15; // [esp-4h] [ebp-214h]
  const char *v16; // [esp-4h] [ebp-214h]
  const char *v17; // [esp-4h] [ebp-214h]
  char szOldName[260]; // [esp+8h] [ebp-208h] BYREF
  char szNewName[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( save_async.m_pParent != nullptr
    && save_async.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_ThreadInMainThread() != 0
    && g_pSaveThread != nullptr )
  {
    IThreadPool::QueueCall<CSaveRestore,CSaveRestore,void>(
      this: g_pSaveThread,
      pObject: this,
      pfnProxied:  __thiscall ISaveRestore::`vcall'{128,{flat}});
    IThreadPool::QueueCall<CSaveRestore,CSaveRestore,void>(
      this: g_pSaveThread,
      pObject: this,
      pfnProxied:  __thiscall CSaveRestore::`vcall'{108,{flat}});
  }
  else if ( this->m_bWaitingForSafeDangerousSave )
  {
    this->m_bWaitingForSafeDangerousSave = false;
    _ConDMsg(a1: "Committing AutoSaveDangerous...\n");
    memset(szOldName, 0, sizeof(szOldName));
    memset(szNewName, 0, sizeof(szNewName));
    if ( this->StorageDeviceValid(this) )
    {
      if ( save_history_count.m_pParent != nullptr )
        m_nValue = save_history_count.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v3 = this->IsXSave(this);
      CSaveRestore::AgeSaveList(this, a2: m_nValue, pName: "autosave", count: m_nValue, bIsXSave: v3);
    }
    v4 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: defaultValue);
    V_snprintf(pDest: szOldName, maxLen: 260, pFormat: "//%s/%sautosavedangerous%s.tga", "MOD", v4, v14);
    v5 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: defaultValue);
    V_snprintf(pDest: szNewName, maxLen: 260, pFormat: "//%s/%sautosave%s.tga", "MOD", v5, v15);
    if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szNewName, a3: nullptr) )
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: szNewName, a3: nullptr);
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szOldName, a3: nullptr)
      || g_pFileSystem->RenameFile(this: g_pFileSystem, a2: szOldName, a3: szNewName, a4: nullptr) )
    {
      if ( this->IsXSave(this) )
      {
        szOldName[0] = 0;
        v12 = 260 - _V_strlen(str: szOldName);
        v8 = _V_strlen(str: szOldName);
        V_snprintf(pDest: &szOldName[v8], maxLen: v12, pFormat: "//mod/autosavedangerous%s.sav", defaultValue);
        szNewName[0] = 0;
        v13 = 260 - _V_strlen(str: szNewName);
        v9 = _V_strlen(str: szNewName);
        V_snprintf(pDest: &szNewName[v9], maxLen: v13, pFormat: "//mod/autosave%s.sav", defaultValue);
      }
      else
      {
        v6 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(
                             a1: this,
                             a2: defaultValue);
        V_snprintf(pDest: szOldName, maxLen: 260, pFormat: "//%s/%sautosavedangerous%s.sav", "MOD", v6, v16);
        v7 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(
                             a1: this,
                             a2: defaultValue);
        V_snprintf(pDest: szNewName, maxLen: 260, pFormat: "//%s/%sautosave%s.sav", "MOD", v7, v17);
      }
      if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: szNewName, a3: nullptr) )
        g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: szNewName, a3: nullptr);
      v10 = !g_pFileSystem->RenameFile(this: g_pFileSystem, a2: szOldName, a3: szNewName, a4: nullptr);
      SetMostRecentSaveGame = this->SetMostRecentSaveGame;
      if ( v10 )
      {
        SetMostRecentSaveGame(this, a2: "autosavedangerous");
      }
      else
      {
        SetMostRecentSaveGame(this, a2: "autosave");
        if ( this->IsXSave(this) )
          g_pXboxSystem->FinishContainerWrites(this: g_pXboxSystem, a2: 0);
      }
    }
    else
    {
      this->SetMostRecentSaveGame(this, a2: "autosavedangerous");
    }
  }
  else
  {
    DevMsg(a1: "No AutoSaveDangerous Outstanding...Nothing to do.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193EC0
// Name: SaveGame
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveGame(const CCommand *args)
{
  int m_nArgc; // eax
  int v3; // esi
  const char **v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int v9; // edi
  int v10; // eax
  ISaveRestore_vtbl *v11; // edx
  int (__thiscall *GetMostRecentElapsedSeconds)(ISaveRestore *); // eax
  int v13; // eax
  void (__thiscall *GetSaveComment)(IServerGameDLL *, char *, int, float, float, bool); // edx
  const char *v15; // ebx
  void *v16; // ecx
  float v17; // [esp+4h] [ebp-178h]
  char szMapName[260]; // [esp+18h] [ebp-164h] BYREF
  char comment[80]; // [esp+11Ch] [ebp-60h] BYREF
  float v20; // [esp+16Ch] [ebp-10h]
  BOOL bSetMostRecent; // [esp+170h] [ebp-Ch]
  int v22; // [esp+174h] [ebp-8h]
  bool bFinishAsync; // [esp+17Bh] [ebp-1h]
  char bRenameMap_3; // [esp+187h] [ebp+Bh]

  m_nArgc = args->m_nArgc;
  bFinishAsync = false;
  LOBYTE(bSetMostRecent) = 1;
  bRenameMap_3 = 0;
  if ( m_nArgc > 2 )
  {
    v3 = 2;
    v4 = &args->m_ppArgv[2];
    do
    {
      if ( v3 < 0 || v3 >= m_nArgc )
        v5 = defaultValue;
      else
        v5 = *v4;
      if ( _V_stricmp(s1: v5, s2: "wait") != 0 )
      {
        if ( v3 < 0 || v3 >= args->m_nArgc )
          v6 = defaultValue;
        else
          v6 = *v4;
        if ( _V_stricmp(s1: v6, s2: "notmostrecent") != 0 )
        {
          if ( v3 < 0 || v3 >= args->m_nArgc )
            v7 = defaultValue;
          else
            v7 = *v4;
          if ( _V_stricmp(s1: v7, s2: "copymap") == 0 )
            bRenameMap_3 = 1;
        }
        else
        {
          LOBYTE(bSetMostRecent) = 0;
        }
      }
      else
      {
        bFinishAsync = true;
      }
      m_nArgc = args->m_nArgc;
      ++v3;
      ++v4;
    }
    while ( v3 < args->m_nArgc );
    if ( bRenameMap_3 != 0 )
    {
      V_strncpy(pDest: szMapName, pSrc: sv.m_szMapname, maxLen: 260);
      v8 = defaultValue;
      if ( args->m_nArgc > 1 )
        v8 = args->m_ppArgv[1];
      V_strncpy(pDest: sv.m_szMapname, pSrc: v8, maxLen: 64);
    }
  }
  v9 = (int)(float)(g_ServerGlobalVariables.curtime - (float)saverestore->GetMostRecentElapsedTimeSet(this: saverestore));
  v10 = saverestore->GetMostRecentElapsedMinutes(this: saverestore);
  v11 = saverestore->__vftable;
  v22 = v9 / 60 + v10;
  GetMostRecentElapsedSeconds = v11->GetMostRecentElapsedSeconds;
  v20 = (float)v22;
  v13 = GetMostRecentElapsedSeconds(this: saverestore);
  GetSaveComment = serverGameDLL->GetSaveComment;
  v22 = v9 % 60 + v13;
  v17 = (float)v22;
  ((void (__thiscall *)(IServerGameDLL *, char *, int, _DWORD, _DWORD, _DWORD))GetSaveComment)(
    a1: serverGameDLL,
    a2: comment,
    a3: 80,
    a4: LODWORD(v20),
    a5: LODWORD(v17),
    a6: 0);
  if ( args->m_nArgc > 1 )
    v15 = args->m_ppArgv[1];
  else
    v15 = defaultValue;
  saverestore->SaveGameSlot(
    this: saverestore,
    a2: v15,
    a3: comment,
    a4: false,
    a5: bSetMostRecent,
    a6: nullptr,
    a7: nullptr);
  if ( bFinishAsync )
    FinishAsyncSave(this: v16);
  if ( bRenameMap_3 != 0 )
    V_strncpy(pDest: sv.m_szMapname, pSrc: szMapName, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x101940B0
// Name: xsave
// Source: json
//------------------------------------------------------------------------------
void __cdecl xsave(const CCommand *args)
{
  char *v1; // eax
  int v2; // eax
  int v3; // eax

  if ( cmd_source == src_command && saverestore->IsValidSave(this: saverestore) != 0 )
  {
    if ( serverGameDLL->SupportsSaveRestore(this: serverGameDLL) )
    {
      if ( args->m_nArgc >= 2 )
      {
        v1 = (char *)defaultValue;
        if ( args->m_nArgc > 1 )
          v1 = (char *)args->m_ppArgv[1];
        strstr(str1: (unsigned __int8 *)v1, str2: "..");
        if ( v2 != 0 )
        {
          _ConDMsg(a1: "Relative pathnames are not allowed.\n");
        }
        else
        {
          strstr(str1: (unsigned __int8 *)sv.m_szMapname, str2: "background");
          if ( v3 != 0 )
          {
            _ConDMsg(a1: "\"background\" is a reserved map name and cannot be saved or loaded.\n");
          }
          else
          {
            saverestore->SetIsXSave(this: saverestore, a2: false);
            SaveGame(args);
          }
        }
      }
      else
      {
        _ConDMsg(a1: "save <savename> [wait]: save a game\n");
      }
    }
    else
    {
      ConMsg(a1: "This game doesn't support save/restore.");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194190
// Name: public: virtual void CSaveRestore::FinishAsyncSave(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSaveRestore::FinishAsyncSave(CSaveRestore *this)
{
  FinishAsyncSave(this);
}

//------------------------------------------------------------------------------
// Address: 0x101941A0
// Name: public: void CSaveRestore::AddDeferredCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::AddDeferredCommand(CSaveRestore *this, const char *pchCommand)
{
  int m_nValue; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax

  if ( save_huddelayframes.m_pParent != nullptr && (m_nValue = save_huddelayframes.m_pParent->m_Value.m_nValue) >= 0 )
  {
    if ( m_nValue > 10 )
      m_nValue = 10;
  }
  else
  {
    m_nValue = 0;
  }
  this->m_nDeferredCommandFrames = m_nValue;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pchCommand + 1, pStr: pchCommand);
  m_Size = this->m_sDeferredCommands.m_Size;
  m_nAllocationCount = this->m_sDeferredCommands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(
      this: (CUtlMemory<wchar_t,int> *)&this->m_sDeferredCommands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_sDeferredCommands.m_Size;
  m_pMemory = this->m_sDeferredCommands.m_Memory.m_pMemory;
  v7 = this->m_sDeferredCommands.m_Size - m_Size - 1;
  this->m_sDeferredCommands.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v7);
  v8 = &this->m_sDeferredCommands.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    v8->m_Id = *(_WORD *)((unsigned __int16)&pchCommand + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101943C0
// Name: autosave
// Source: json
//------------------------------------------------------------------------------
void __usercall autosave(int a1@<edi>, int a2@<esi>)
{
  if ( saverestore->IsValidSave(this: saverestore) != 0
    && sv_autosave.m_pParent != nullptr
    && sv_autosave.m_pParent->m_Value.m_nValue != 0
    && serverGameDLL->SupportsSaveRestore(this: serverGameDLL)
    && !g_bInCommentaryMode )
  {
    if ( save_console.m_pParent != nullptr && save_console.m_pParent->m_Value.m_nValue != 0 )
      CSaveRestore::AddDeferredCommand(this: g_pSaveRestore, pchCommand: "_autosave");
    else
      AutoSave_Silent(a1, a2, bDangerous: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194430
// Name: autosavedangerous
// Source: json
//------------------------------------------------------------------------------
void __usercall autosavedangerous(int a1@<edi>, int a2@<esi>)
{
  if ( cmd_source == src_command
    && saverestore->IsValidSave(this: saverestore) != 0
    && sv_autosave.m_pParent != nullptr
    && sv_autosave.m_pParent->m_Value.m_nValue != 0
    && saverestore->StorageDeviceValid(this: saverestore)
    && serverGameDLL->SupportsSaveRestore(this: serverGameDLL)
    && !g_bInCommentaryMode )
  {
    if ( save_console.m_pParent != nullptr && save_console.m_pParent->m_Value.m_nValue != 0 )
      CSaveRestore::AddDeferredCommand(this: g_pSaveRestore, pchCommand: "_autosavedangerous");
    else
      AutoSave_Silent(a1, a2, bDangerous: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194580
// Name: public: virtual int CSaveRestore::SaveGameSlot(char const __near *,char const __near *,bool,bool,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestore::SaveGameSlot(
        CSaveRestore *this,
        const char *pSaveName,
        const char *pSaveComment,
        bool onlyThisLevel,
        bool bSetMostRecent,
        const char *pszDestMap,
        const char *pszLandmark)
{
  CSaveRestore *v7; // edi
  int m_nValue; // eax
  int v10; // eax
  unsigned __int8 v11; // al
  void *v12; // ecx
  void *v13; // ecx
  int v14; // eax
  bool v15; // bl
  bool (__thiscall *IsXSave)(struct CSaveRestore *); // eax
  const char *(__thiscall *GetSaveDir)(struct CSaveRestore *); // eax
  const char *v18; // eax
  void *v19; // ecx
  const char *v20; // eax
  int v21; // eax
  int v22; // eax
  char *v23; // eax
  char *v24; // esi
  int v25; // eax
  void *v26; // ecx
  CSaveRestoreData *v27; // esi
  int v28; // ebx
  int tokenCount; // eax
  char **pTokens; // ecx
  char *v31; // edx
  signed int v32; // edi
  int v33; // eax
  int size; // ecx
  int v35; // eax
  bool v36; // zf
  int v37; // eax
  void *v38; // ecx
  CSaveRestore *v39; // ebx
  int v40; // edx
  int v41; // edi
  const void *v42; // eax
  char *v43; // eax
  char *v44; // edi
  CFunctor *v45; // eax
  CFunctor *v46; // eax
  CFunctor *v47; // eax
  void *v48; // ecx
  void *v49; // ecx
  int v50; // eax
  char *v51; // esi
  const char *v52; // eax
  int v53; // ecx
  const char *v54; // [esp-10h] [ebp-41Ch]
  int v55; // [esp-Ch] [ebp-418h]
  const char *v56; // [esp-Ch] [ebp-418h]
  DWORD CurrentThreadId; // [esp-8h] [ebp-414h]
  int v58; // [esp-8h] [ebp-414h]
  const char *v59; // [esp-4h] [ebp-410h]
  int v60; // [esp-4h] [ebp-410h]
  GAME_HEADER gameHeader; // [esp+4h] [ebp-408h] BYREF
  char name[260]; // [esp+198h] [ebp-274h] BYREF
  char hlPath[256]; // [esp+29Ch] [ebp-170h] BYREF
  CUtlBuffer saveHeader; // [esp+39Ch] [ebp-70h] BYREF
  CUtlString v65; // [esp+3CCh] [ebp-40h] BYREF
  int iX360controller; // [esp+3DCh] [ebp-30h] BYREF
  int v67; // [esp+3E0h] [ebp-2Ch]
  CSaveRestore *pObject; // [esp+3E4h] [ebp-28h]
  int tokenSize; // [esp+3E8h] [ebp-24h] BYREF
  CUtlString src; // [esp+3ECh] [ebp-20h] BYREF
  char *in; // [esp+3FCh] [ebp-10h]
  bool bIsQuick; // [esp+403h] [ebp-9h]
  int tag; // [esp+404h] [ebp-8h] BYREF
  bool arg1; // [esp+408h] [ebp-4h] BYREF
  bool bClearFile; // [esp+409h] [ebp-3h]
  bool bIsAutosave; // [esp+40Ah] [ebp-2h]
  bool bIsAutosaveDangerous; // [esp+40Bh] [ebp-1h]
  char *pTokenData; // [esp+41Ch] [ebp+10h]
  char *pTokenDataa; // [esp+41Ch] [ebp+10h]
  char *pTokenDatab; // [esp+41Ch] [ebp+10h]
  bool pTokenData_3; // [esp+41Fh] [ebp+13h]
  unsigned __int8 *bSetMostRecenta; // [esp+420h] [ebp+14h]
  const char *pszLandmarka; // [esp+428h] [ebp+1Ch]

  v7 = this;
  pObject = this;
  iX360controller = 0;
  if ( save_disable.m_pParent != nullptr && save_disable.m_pParent->m_Value.m_nValue != 0 )
    return 0;
  if ( save_asyncdelay.m_pParent != nullptr )
  {
    m_nValue = save_asyncdelay.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      if ( m_nValue > 3000 )
        m_nValue = 3000;
      Sys_Sleep(msec: m_nValue);
    }
  }
  bClearFile = true;
  v10 = _V_stricmp(s1: pSaveName, s2: "quick");
  bIsQuick = v10 == 0;
  if ( v10 != 0 && _V_stricmp(s1: pSaveName, s2: "autosave") == 0 )
  {
    bIsAutosave = true;
LABEL_12:
    bIsAutosaveDangerous = false;
    if ( !bIsAutosave
      && map_wants_save_disable.m_pParent != nullptr
      && map_wants_save_disable.m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(a1: "*** REJECTING: %s, due to map_wants_save_disable.\n", pSaveName);
      return 0;
    }
    goto LABEL_18;
  }
  bIsAutosave = false;
  if ( _V_stricmp(s1: pSaveName, s2: "autosavedangerous") != 0 )
    goto LABEL_12;
  bIsAutosaveDangerous = true;
LABEL_18:
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
  {
    CurrentThreadId = GetCurrentThreadId();
    v11 = _ThreadInMainThread();
    _Msg(a1: "Start save...\n", v11, CurrentThreadId);
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SaveGameSlot",
    a3: 0,
    a4: "Save",
    a5: false,
    a6: 4);
  g_pSaveRestoreFileSystem->AsyncFinishAllWrites(this: g_pSaveRestoreFileSystem);
  S_ExtraUpdate(this: v12);
  v7->FinishAsyncSave(this: v7);
  SaveResetMemory();
  S_ExtraUpdate(this: v13);
  if ( save_async.m_pParent != nullptr )
    v14 = save_async.m_pParent->m_Value.m_nValue;
  else
    v14 = 0;
  v15 = v14 == 0;
  if ( g_AsyncSaveCallQueue.m_bNoQueue != (v14 == 0) )
  {
    if ( !g_AsyncSaveCallQueue.m_bNoQueue )
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_AsyncSaveCallQueue);
    g_AsyncSaveCallQueue.m_bNoQueue = v15;
  }
  CSaveRestore::CalcSaveGameName(this: v7, pName: pSaveName, output: name, outputStringLength: 260);
  _ConDMsg(a1: "Saving game to %s...\n", name);
  in = v7->m_szSaveGameName;
  V_strncpy(pDest: v7->m_szSaveGameName, pSrc: name, maxLen: 260);
  if ( v7->m_bClearSaveDir )
  {
    IsXSave = v7->IsXSave;
    v7->m_bClearSaveDir = false;
    arg1 = IsXSave(this: v7);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CSaveRestore *,CSaveRestore,void,bool,bool>(
      this: &g_AsyncSaveCallQueue,
      pObject: v7,
      pfnProxied: CSaveRestore::DoClearSaveDir,
      &arg1);
  }
  if ( v7->IsXSave(this: v7) )
  {
    hlPath[0] = 0;
    if ( onlyThisLevel )
    {
      v55 = 256 - _V_strlen(str: hlPath);
      v21 = _V_strlen(str: hlPath);
      V_snprintf(pDest: &hlPath[v21], maxLen: v55, pFormat: "//mod/%s*.HL?", sv.m_szMapname);
    }
    else
    {
      v58 = 256 - _V_strlen(str: hlPath);
      v22 = _V_strlen(str: hlPath);
      V_snprintf(pDest: &hlPath[v22], maxLen: v58, pFormat: "//mod/*.HL?");
    }
  }
  else
  {
    GetSaveDir = v7->GetSaveDir;
    if ( onlyThisLevel )
    {
      v18 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))GetSaveDir)(a1: v7, a2: sv.m_szMapname);
      V_snprintf(pDest: hlPath, maxLen: 256, pFormat: "%s%s*.HL?", v18, v59);
    }
    else
    {
      v20 = GetSaveDir(this: v7);
      V_snprintf(pDest: hlPath, maxLen: 256, pFormat: "%s*.HL?", v20);
    }
  }
  if ( bIsQuick || bIsAutosave || bIsAutosaveDangerous )
  {
    bClearFile = false;
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Queue AgeSaveList\n");
    if ( v7->StorageDeviceValid(this: v7) )
    {
      pTokenData_3 = v7->IsXSave(this: v7);
      v67 = save_history_count.m_pParent != nullptr ? save_history_count.m_pParent->m_Value.m_nValue : 0;
      CUtlString::CUtlString(this: &src);
      CUtlString::operator=(this: &src, src: pSaveName);
      v23 = (char *)MemAlloc_Alloc(nSize: 0x30u);
      v24 = v23;
      if ( v23 != nullptr )
      {
        *((_DWORD *)v23 + 3) = 1;
        *(_DWORD *)v23 = &CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,int,bool),CUtlEnvelope<char const *>,int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        *((_DWORD *)v23 + 2) = &CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,int,bool),CUtlEnvelope<char const *>,int,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        *((_DWORD *)v23 + 4) = CSaveRestore::AgeSaveList;
        *((_DWORD *)v23 + 5) = v7;
        CUtlString::CUtlString(this: (CUtlString *)(v23 + 24));
        CUtlString::operator=(this: (CUtlString *)(v24 + 24), &src);
        *((_DWORD *)v24 + 10) = v67;
        v24[44] = pTokenData_3;
      }
      else
      {
        v24 = nullptr;
      }
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(
        this: &g_AsyncSaveCallQueue,
        pFunctor: (CFunctor *)v24);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
  S_ExtraUpdate(this: v19);
  if ( bIsAutosave || bIsAutosaveDangerous )
    v25 = 1;
  else
    LOBYTE(v25) = 0;
  v60 = v25;
  if ( ((unsigned __int8 (__thiscall *)(CSaveRestore *, bool, _DWORD))v7->SaveGameState)(
         a1: v7,
         a2: pszDestMap != nullptr,
         a3: 0) == 0
    || (S_ExtraUpdate(this: v26), (v27 = serverGameDLL->SaveInit(this: serverGameDLL, a2: 0)) == nullptr) )
  {
    *in = 0;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  V_FixSlashes(pname: hlPath, separator: 92);
  V_strncpy(pDest: gameHeader.comment, pSrc: pSaveComment, maxLen: 80);
  if ( pszDestMap != nullptr && pszLandmark != nullptr && *pszDestMap != 0 && *pszLandmark != 0 )
  {
    V_strncpy(pDest: gameHeader.mapName, pSrc: pszDestMap, maxLen: 32);
    V_strncpy(pDest: gameHeader.originMapName, pSrc: sv.m_szMapname, maxLen: 32);
    V_strncpy(pDest: gameHeader.landmark, pSrc: pszLandmark, maxLen: 256);
  }
  else
  {
    V_strncpy(pDest: gameHeader.mapName, pSrc: sv.m_szMapname, maxLen: 32);
    gameHeader.originMapName[0] = 0;
    gameHeader.landmark[0] = 0;
  }
  v28 = 0;
  gameHeader.mapCount = 0;
  ((void (__thiscall *)(IServerGameDLL *, CSaveRestoreData *, const char *, GAME_HEADER *, _DWORD, typedescription_t *, int, _DWORD, int))serverGameDLL->SaveWriteFields)(
    a1: serverGameDLL,
    a2: v27,
    a3: "GameHeader",
    a4: &gameHeader,
    a5: 0,
    a6: GAME_HEADER::m_DataMap.dataDesc,
    a7: GAME_HEADER::m_DataMap.dataNumFields,
    a8: 0,
    a9: v60);
  serverGameDLL->SaveGlobalState(this: serverGameDLL, a2: v27);
  pTokenData = v27->pCurrentData;
  if ( v27->tokenCount <= 0 )
    goto LABEL_79;
  while ( 1 )
  {
    if ( v28 < 0 )
      goto LABEL_72;
    tokenCount = v27->tokenCount;
    if ( v28 >= tokenCount )
      goto LABEL_72;
    pTokens = v27->pTokens;
    if ( pTokens[v28] != nullptr )
    {
      if ( v28 < tokenCount )
      {
        v31 = pTokens[v28];
        goto LABEL_74;
      }
LABEL_72:
      v31 = "<<illegal>>";
      goto LABEL_74;
    }
    v31 = (char *)defaultValue;
LABEL_74:
    v32 = strlen(v31) + 1;
    if ( v32 > v27->bufferSize - v27->size )
      break;
    memcpy(dst: (unsigned __int8 *)v27->pCurrentData, src: (unsigned __int8 *)v31, count: v32);
    v27->pCurrentData += v32;
    v27->size += v32;
    if ( ++v28 >= v27->tokenCount )
      goto LABEL_78;
  }
  v27->size = v27->bufferSize;
  ConMsg(a1: "Token Table Save/Restore overflow!");
LABEL_78:
  v7 = pObject;
LABEL_79:
  v33 = v27->pCurrentData - pTokenData;
  tokenSize = v33;
  size = v27->size;
  if ( size < v33 )
    v33 = v27->size;
  v35 = -v33;
  v27->pCurrentData += v35;
  v36 = !bClearFile;
  v27->size = v35 + size;
  if ( !v36 )
  {
    v37 = ((int (__thiscall *)(ISaveRestoreFileSystem *, char *))g_pSaveRestoreFileSystem->Open)(
            a1: g_pSaveRestoreFileSystem,
            a2: name);
    if ( v37 == 0 )
    {
      _Msg(a1: "Save failed: invalid file name '%s'\n", pSaveName);
      *in = 0;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 0;
    }
    ((void (__thiscall *)(ISaveRestoreFileSystem *, int, const char *, _DWORD))g_pSaveRestoreFileSystem->Close)(
      a1: g_pSaveRestoreFileSystem,
      a2: v37,
      a3: "wb",
      a4: 0);
    S_ExtraUpdate(this: v38);
  }
  if ( bSetMostRecent )
    v7->SetMostRecentSaveGame(this: v7, a2: pSaveName);
  v39 = pObject;
  v40 = tokenSize;
  pObject->m_bWaitingForSafeDangerousSave = bIsAutosaveDangerous;
  v41 = v27->size + v40 + 64;
  v42 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v41);
  CUtlBuffer::CUtlBuffer(this: &saveHeader, pBuffer: v42, nSize: v41, nFlags: 0);
  tag = 1447121738;
  CUtlBuffer::Put(this: &saveHeader, pMem: &tag, size: 4);
  tag = 116;
  CUtlBuffer::Put(this: &saveHeader, pMem: &tag, size: 4);
  tag = v27->size;
  CUtlBuffer::Put(this: &saveHeader, pMem: &tag, size: 4);
  tag = v27->tokenCount;
  CUtlBuffer::Put(this: &saveHeader, pMem: &tag, size: 4);
  CUtlBuffer::Put(this: &saveHeader, pMem: &tokenSize, size: 4);
  CUtlBuffer::Put(this: &saveHeader, pMem: pTokenData, size: tokenSize);
  CUtlBuffer::Put(this: &saveHeader, pMem: v27->pBaseData, size: v27->size);
  bSetMostRecenta = saveHeader.m_Memory.m_pMemory;
  pszLandmarka = (const char *)saveHeader.m_Put;
  CUtlString::CUtlString(this: &src);
  CUtlString::operator=(this: &src, src: name);
  pTokenDataa = (char *)g_pSaveRestoreFileSystem;
  v43 = (char *)MemAlloc_Alloc(nSize: 0x38u);
  v44 = v43;
  if ( v43 != nullptr )
  {
    *((_DWORD *)v43 + 3) = 1;
    *(_DWORD *)v43 = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    *((_DWORD *)v43 + 2) = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *((_DWORD *)v43 + 5) = pTokenDataa;
    *((_DWORD *)v43 + 4) =  __thiscall IToolSystem::`vcall'{52,{flat}};
    CUtlString::CUtlString(this: (CUtlString *)(v43 + 24));
    CUtlString::operator=(this: (CUtlString *)(v44 + 24), &src);
    *((_DWORD *)v44 + 10) = bSetMostRecenta;
    *((_DWORD *)v44 + 11) = pszLandmarka;
    *((_WORD *)v44 + 24) = 1;
    *((_DWORD *)v44 + 13) = 0;
    v45 = (CFunctor *)v44;
  }
  else
  {
    v45 = nullptr;
  }
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_AsyncSaveCallQueue, pFunctor: v45);
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  CUtlString::CUtlString(this: &v65);
  CUtlString::operator=(this: &v65, src: name);
  CUtlString::CUtlString(this: &src);
  CUtlString::operator=(this: &src, src: hlPath);
  v46 = CreateFunctor<CSaveRestore *,CSaveRestore,void,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
          pObject: v39,
          pfnProxied: CSaveRestore::DirectoryCopy,
          arg1: (const CUtlEnvelope<char const *> *)&src,
          arg2: (const CUtlEnvelope<char const *> *)&v65,
          arg3: &v39->m_bIsXSave);
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_AsyncSaveCallQueue, pFunctor: v46);
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
      src.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    src.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v65.m_Storage.m_nActualLength = 0;
  if ( v65.m_Storage.m_Memory.m_nGrowSize >= 0 && v65.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v65.m_Storage.m_Memory.m_pMemory);
  pTokenDatab = (char *)g_pFileSystem;
  v47 = (CFunctor *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v47 != nullptr )
  {
    v47[1].m_nUserID = 1;
    v47->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IFileSystem *,void (__thiscall IFileSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v47[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IFileSystem *,void (__thiscall IFileSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v47[2].__vftable = (CFunctor_vtbl *) __thiscall IToolSystem::`vcall'{180,{flat}};
    v47[2].m_nUserID = 0;
    v47[3].__vftable = (CFunctor_vtbl *)pTokenDatab;
  }
  else
  {
    v47 = nullptr;
  }
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_AsyncSaveCallQueue, pFunctor: v47);
  if ( v39->IsXSave(this: v39) && v39->StorageDeviceValid(this: v39) )
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<IXboxSystem *,IXboxSystem,void,int,int>(
      this: &g_AsyncSaveCallQueue,
      pObject: g_pXboxSystem,
      pfnProxied:  __thiscall IXboxSystem::`vcall'{36,{flat}},
      arg1: (CFunctor_vtbl **)&iX360controller);
  S_ExtraUpdate(this: v48);
  v39->Finish(this: v39, a2: v27);
  S_ExtraUpdate(this: v49);
  if ( save_screenshot.m_pParent == nullptr )
    goto LABEL_114;
  v50 = save_screenshot.m_pParent->m_Value.m_nValue;
  if ( (v50 == 0 || bIsAutosave || bIsAutosaveDangerous) && v50 != 2 )
    goto LABEL_114;
  if ( !v39->IsXSave(this: v39) )
  {
    v52 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *, const char *))v39->GetSaveDir)(
                          a1: v39,
                          a2: pSaveName,
                          a3: defaultValue);
    V_snprintf(pDest: v39->m_szSaveGameScreenshotFile, maxLen: 260, pFormat: "%s%s%s.tga", v52, v54, v56);
LABEL_114:
    v51 = in;
    goto LABEL_115;
  }
  v51 = in;
  V_StripExtension(in, out: v39->m_szSaveGameScreenshotFile, outSize: 260);
  V_strncat(pDest: v39->m_szSaveGameScreenshotFile, pSrc: ".tga", destBufferSize: 0x104u, max_chars_to_copy: -1);
LABEL_115:
  V_strncpy(pDest: v39->m_MostRecentSaveInfo.m_MostRecentSavePath, pSrc: v51, maxLen: 260);
  V_strncpy(pDest: v39->m_MostRecentSaveInfo.m_MostRecentSaveComment, pSrc: pSaveComment, maxLen: 80);
  if ( V_stristr(pStr: v51, pSearch: "autosavedangerous") != nullptr )
    V_strncpy(pDest: v39->m_MostRecentSaveInfo.m_LastAutosaveDangerousComment, pSrc: pSaveComment, maxLen: 80);
  v39->m_MostRecentSaveInfo.m_bValid = true;
  DispatchAsyncSave(a1: v53, a2: (int)pSaveComment);
  *v51 = 0;
  if ( saveHeader.m_Memory.m_nGrowSize >= 0 )
  {
    if ( saveHeader.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: saveHeader.m_Memory.m_pMemory);
      saveHeader.m_Memory.m_pMemory = nullptr;
    }
    saveHeader.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10194FA0
// Name: private: bool CSaveRestore::SaveClientState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestore::SaveClientState(CSaveRestore *this, const char *name)
{
  int v2; // edi
  CSaveRestoreData *v3; // eax
  CSaveRestoreData *v4; // esi
  int v6; // eax
  decallist_t *v7; // ebx
  int v8; // ebx
  unsigned int channelsize; // ecx
  int v10; // ebx
  int tokenCount; // eax
  char **pTokens; // ecx
  char *v13; // edx
  signed int v14; // edi
  int v15; // eax
  int v16; // ebx
  char *v17; // eax
  char *v18; // edi
  void *v19; // eax
  loopback_t *v20; // ebx
  TSLHead_t m_Head; // kr00_8
  CTSQueue<loopback_t *,0,1>::Node_t *v22; // eax
  channelsave *m_pMemory; // eax
  CUtlBuffer buffer; // [esp+8h] [ebp-9Ch] BYREF
  CUtlString src; // [esp+38h] [ebp-6Ch] BYREF
  void *pBuffer; // [esp+48h] [ebp-5Ch]
  CSaveRestore *v27; // [esp+4Ch] [ebp-58h]
  decallist_t *decalList; // [esp+50h] [ebp-54h]
  clientsections_t sections; // [esp+54h] [ebp-50h] BYREF
  CUtlVector<channelsave,CUtlMemory<channelsave,int> > channels; // [esp+88h] [ebp-1Ch] BYREF
  int sectionheaderversion; // [esp+9Ch] [ebp-8h] BYREF
  int magicnumber; // [esp+A0h] [ebp-4h] BYREF
  const char *namea; // [esp+ACh] [ebp+8h]
  const char *nameb; // [esp+ACh] [ebp+8h]

  v27 = this;
  v2 = 0;
  v3 = g_ClientDLL->SaveInit(this: g_ClientDLL, a2: 0);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  sections.entitydata = v3->pCurrentData;
  g_ClientDLL->PreSave(this: g_ClientDLL, a2: v3);
  g_ClientDLL->Save(this: g_ClientDLL, a2: v4);
  sections.entitysize = v4->pCurrentData - sections.entitydata;
  sections.headerdata = v4->pCurrentData;
  g_ClientDLL->WriteSaveHeaders(this: g_ClientDLL, a2: v4);
  sections.headersize = v4->pCurrentData - sections.headerdata;
  sections.decaldata = v4->pCurrentData;
  v6 = Draw_DecalMax();
  v7 = (decallist_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 156 * v6);
  decalList = v7;
  sections.decalcount = DecalListCreate(pList: v7);
  if ( sections.decalcount > 0 )
  {
    do
    {
      g_ClientDLL->SaveWriteFields(
        this: g_ClientDLL,
        a2: v4,
        a3: "DECALLIST",
        a4: v7,
        a5: nullptr,
        a6: decallist_t::m_DataMap.dataDesc,
        a7: decallist_t::m_DataMap.dataNumFields);
      ++v2;
      ++v7;
    }
    while ( v2 < sections.decalcount );
    v2 = 0;
  }
  sections.decalsize = v4->pCurrentData - sections.decaldata;
  memset(&channels, 0, sizeof(channels));
  S_GetActiveSaveRestoreChannels(channelSaves: &channels);
  sections.channelcount = channels.m_Size;
  sections.channeldata = v4->pCurrentData;
  if ( channels.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      g_ClientDLL->SaveWriteFields(
        this: g_ClientDLL,
        a2: v4,
        a3: "CHANNELLIST",
        a4: &channels.m_Memory.m_pMemory[v8],
        a5: nullptr,
        a6: channelsave::m_DataMap.dataDesc,
        a7: channelsave::m_DataMap.dataNumFields);
      ++v2;
      ++v8;
    }
    while ( v2 < sections.channelcount );
  }
  channelsize = v4->pCurrentData - sections.channeldata;
  v10 = 0;
  sections.channelsize = channelsize;
  sections.symboldata = v4->pCurrentData;
  if ( v4->tokenCount <= 0 )
    goto LABEL_22;
  while ( 1 )
  {
    if ( v10 < 0 )
      goto LABEL_15;
    tokenCount = v4->tokenCount;
    if ( v10 >= tokenCount )
      goto LABEL_15;
    pTokens = v4->pTokens;
    if ( pTokens[v10] != nullptr )
    {
      if ( v10 < tokenCount )
      {
        v13 = pTokens[v10];
        goto LABEL_17;
      }
LABEL_15:
      v13 = "<<illegal>>";
      goto LABEL_17;
    }
    v13 = (char *)defaultValue;
LABEL_17:
    v14 = strlen(v13) + 1;
    if ( v14 > v4->bufferSize - v4->size )
      break;
    memcpy(dst: (unsigned __int8 *)v4->pCurrentData, src: (unsigned __int8 *)v13, count: v14);
    v4->pCurrentData += v14;
    v4->size += v14;
    if ( ++v10 >= v4->tokenCount )
      goto LABEL_21;
  }
  v4->size = v4->bufferSize;
  ConMsg(a1: "Token Table Save/Restore overflow!");
LABEL_21:
  channelsize = sections.channelsize;
LABEL_22:
  sections.symbolcount = v4->tokenCount;
  v15 = v4->pCurrentData - sections.symboldata;
  magicnumber = 1414795828;
  sections.symbolsize = v15;
  sectionheaderversion = 2;
  v16 = sections.headersize + sections.decalsize + channelsize + v15 + sections.entitysize + 48;
  pBuffer = MemAlloc_Alloc(nSize: v16);
  CUtlBuffer::CUtlBuffer(this: &buffer, pBuffer, nSize: v16, nFlags: 0);
  CUtlBuffer::Put(this: &buffer, pMem: &CURRENT_SAVEFILE_HEADER_TAG, size: 8);
  CUtlBuffer::Put(this: &buffer, pMem: &magicnumber, size: 4);
  CUtlBuffer::Put(this: &buffer, pMem: &sectionheaderversion, size: 4);
  CUtlBuffer::Put(this: &buffer, pMem: &sections, size: 32);
  CUtlBuffer::Put(this: &buffer, pMem: sections.symboldata, size: sections.symbolsize);
  CUtlBuffer::Put(this: &buffer, pMem: sections.headerdata, size: sections.headersize);
  CUtlBuffer::Put(this: &buffer, pMem: sections.entitydata, size: sections.entitysize);
  CUtlBuffer::Put(this: &buffer, pMem: sections.decaldata, size: sections.decalsize);
  CUtlBuffer::Put(this: &buffer, pMem: sections.channeldata, size: sections.channelsize);
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Queue AsyncWrite (%s)\n", name);
  CUtlString::CUtlString(this: &src);
  CUtlString::operator=(this: &src, src: name);
  namea = (const char *)g_pSaveRestoreFileSystem;
  v17 = (char *)MemAlloc_Alloc(nSize: 0x38u);
  v18 = v17;
  if ( v17 != nullptr )
  {
    *((_DWORD *)v17 + 3) = 1;
    *(_DWORD *)v17 = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,unsigned int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    *((_DWORD *)v17 + 2) = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,unsigned int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *((_DWORD *)v17 + 5) = namea;
    *((_DWORD *)v17 + 4) =  __thiscall IToolSystem::`vcall'{52,{flat}};
    CUtlString::CUtlString(this: (CUtlString *)(v17 + 24));
    CUtlString::operator=(this: (CUtlString *)(v18 + 24), &src);
    v19 = pBuffer;
    *((_DWORD *)v18 + 11) = v16;
    v20 = (loopback_t *)v18;
    *((_DWORD *)v18 + 10) = v19;
    *((_WORD *)v18 + 24) = 1;
    *((_DWORD *)v18 + 13) = 0;
    nameb = v18;
  }
  else
  {
    nameb = nullptr;
    v20 = nullptr;
  }
  if ( g_AsyncSaveCallQueue.m_bNoQueue )
  {
    (*((void (__thiscall **)(loopback_t *))v20->data + 3))(a1: v20);
    (*((void (__thiscall **)(loopback_t *))v20->data + 1))(a1: v20);
  }
  else
  {
    m_Head = g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head;
    if ( g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head.value.Next != nullptr )
    {
      while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                 a1: &g_AsyncSaveCallQueue.m_queue.m_FreeNodes,
                                 a2: m_Head.value.Next->Next,
                                 a3: m_Head.value32.DepthAndSequence - 1,
                                 a4: m_Head.value.Next,
                                 a5: m_Head.value32.DepthAndSequence) == 0 )
      {
        _mm_pause();
        m_Head = g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head;
        if ( g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head.value.Next == nullptr )
        {
          v20 = (loopback_t *)nameb;
          goto LABEL_33;
        }
      }
      *((_DWORD *)&m_Head.value.Next->Next + 1) = nameb;
      CTSQueue<CFunctor *,0,1>::Push(
        this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue,
        pNode: (CTSQueue<loopback_t *,0,1>::Node_t *)m_Head.value.Next);
    }
    else
    {
LABEL_33:
      v22 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
      if ( v22 != nullptr )
      {
        v22->elem = v20;
        CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: v22);
      }
      else
      {
        CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: nullptr);
      }
    }
  }
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  v27->Finish(this: v27, a2: v4);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: decalList);
  if ( buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
      buffer.m_Memory.m_pMemory = nullptr;
    }
    buffer.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = channels.m_Memory.m_pMemory;
  channels.m_Size = 0;
  if ( channels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( channels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channels.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      channels.m_Memory.m_pMemory = nullptr;
    }
    channels.m_Memory.m_nAllocationCount = 0;
  }
  channels.m_pElements = m_pMemory;
  if ( channels.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10195490
// Name: private: void CSaveRestore::EntityPatchWrite(class CSaveRestoreData __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::EntityPatchWrite(
        CSaveRestore *this,
        CSaveRestoreData *pSaveData,
        const char *level,
        bool bAsync)
{
  const char *v5; // eax
  int v6; // eax
  int tableCount; // ecx
  int v8; // edx
  int v9; // eax
  entitytable_t *pTable; // edi
  int v11; // ebx
  void *v12; // edi
  int v13; // eax
  ISaveRestoreFileSystem *v14; // edi
  char *v15; // eax
  loopback_t *v16; // esi
  TSLHead_t m_Head; // kr00_8
  CTSQueue<loopback_t *,0,1>::Node_t *v18; // eax
  int v19; // [esp-Ch] [ebp-164h]
  const char *v20; // [esp-4h] [ebp-15Ch]
  char name[260]; // [esp+Ch] [ebp-14Ch] BYREF
  CUtlBuffer buffer; // [esp+110h] [ebp-48h] BYREF
  CUtlString src; // [esp+140h] [ebp-18h] BYREF
  int size; // [esp+150h] [ebp-8h] BYREF
  int i; // [esp+154h] [ebp-4h] BYREF
  void *pBuffer; // [esp+164h] [ebp+Ch]

  if ( this->IsXSave(this) )
  {
    name[0] = 0;
    v19 = 260 - _V_strlen(str: name);
    v6 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v6], maxLen: v19, pFormat: "//mod/%s.HL3", level);
  }
  else
  {
    v5 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: level);
    V_snprintf(pDest: name, maxLen: 260, pFormat: "//%s/%s%s.HL3", "MOD", v5, v20);
  }
  tableCount = pSaveData->tableCount;
  v8 = 0;
  v9 = 0;
  size = 0;
  i = 0;
  if ( tableCount > 0 )
  {
    pTable = pSaveData->pTable;
    do
    {
      if ( (pTable[v9].flags & 0x40000000) != 0 )
        size = ++v8;
      i = ++v9;
    }
    while ( v9 < tableCount );
  }
  v11 = 4 * v8 + 4;
  v12 = MemAlloc_Alloc(nSize: v11);
  pBuffer = v12;
  CUtlBuffer::CUtlBuffer(this: &buffer, pBuffer: v12, nSize: v11, nFlags: 0);
  CUtlBuffer::Put(this: &buffer, pMem: &size, size: 4);
  v13 = 0;
  for ( i = 0; v13 < pSaveData->tableCount; i = v13 )
  {
    if ( (pSaveData->pTable[v13].flags & 0x40000000) != 0 )
    {
      CUtlBuffer::Put(this: &buffer, pMem: &i, size: 4);
      v13 = i;
    }
    ++v13;
  }
  if ( bAsync )
  {
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Queue AsyncWrite (%s)\n", name);
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: name);
    v14 = g_pSaveRestoreFileSystem;
    v15 = (char *)MemAlloc_Alloc(nSize: 0x38u);
    v16 = (loopback_t *)v15;
    if ( v15 != nullptr )
    {
      *((_DWORD *)v15 + 3) = 1;
      *(_DWORD *)v15 = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      *((_DWORD *)v15 + 2) = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v15 + 4) =  __thiscall IToolSystem::`vcall'{52,{flat}};
      *((_DWORD *)v15 + 5) = v14;
      CUtlString::CUtlString(this: (CUtlString *)(v15 + 24));
      CUtlString::operator=(this: (CUtlString *)&v16->defbuffer[16], &src);
      *(_DWORD *)&v16->defbuffer[32] = pBuffer;
      *(_DWORD *)&v16->defbuffer[36] = v11;
      *(_WORD *)&v16->defbuffer[40] = 1;
      *(_DWORD *)&v16->defbuffer[44] = 0;
    }
    else
    {
      v16 = nullptr;
    }
    if ( g_AsyncSaveCallQueue.m_bNoQueue )
    {
      (*((void (__thiscall **)(loopback_t *))v16->data + 3))(a1: v16);
      (*((void (__thiscall **)(loopback_t *))v16->data + 1))(a1: v16);
    }
    else
    {
      m_Head = g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head;
      if ( g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head.value.Next != nullptr )
      {
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                   a1: &g_AsyncSaveCallQueue.m_queue.m_FreeNodes,
                                   a2: m_Head.value.Next->Next,
                                   a3: m_Head.value32.DepthAndSequence - 1,
                                   a4: m_Head.value.Next,
                                   a5: m_Head.value32.DepthAndSequence) == 0 )
        {
          _mm_pause();
          m_Head = g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head;
          if ( g_AsyncSaveCallQueue.m_queue.m_FreeNodes.m_Head.value.Next == nullptr )
            goto LABEL_25;
        }
        *((_DWORD *)&m_Head.value.Next->Next + 1) = v16;
        CTSQueue<CFunctor *,0,1>::Push(
          this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue,
          pNode: (CTSQueue<loopback_t *,0,1>::Node_t *)m_Head.value.Next);
      }
      else
      {
LABEL_25:
        v18 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
        if ( v18 != nullptr )
        {
          v18->elem = v16;
          CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: v18);
        }
        else
        {
          CTSQueue<CFunctor *,0,1>::Push(
            this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue,
            pNode: nullptr);
        }
      }
    }
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    g_pSaveRestoreFileSystem->AsyncWrite(
      this: g_pSaveRestoreFileSystem,
      a2: name,
      a3: v12,
      a4: v11,
      a5: true,
      a6: false,
      a7: nullptr);
    g_pSaveRestoreFileSystem->AsyncFinishAllWrites(this: g_pSaveRestoreFileSystem);
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10195860
// Name: public: virtual bool CSaveRestore::SaveGameState(bool,class ISaveRestoreDataCallback __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestore::SaveGameState(
        CSaveRestore *this,
        bool bTransition,
        ISaveRestoreDataCallback *pCallback,
        bool bOpenContainer,
        bool bIsAutosaveOrDangerous)
{
  IMDLCache *v5; // ebx
  void (__thiscall *BeginCoarseLock)(IMDLCache *); // edx
  CSaveRestore *v7; // edi
  void *v8; // ecx
  bool (__thiscall *IsXSave)(struct CSaveRestore *); // edx
  bool v10; // al
  CSaveRestoreData *v11; // eax
  CSaveRestoreData *v12; // esi
  int pCurrentData; // ebx
  void (__thiscall *PreSave)(IServerGameDLL *, CSaveRestoreData *); // eax
  void *v16; // ecx
  void *v17; // ecx
  void *v18; // ecx
  void (__thiscall *WriteSaveHeaders)(IServerGameDLL *, CSaveRestoreData *); // eax
  int nBytesDataHeaders; // ecx
  int v21; // ebx
  int tokenCount; // eax
  char **pTokens; // ecx
  char *v24; // edx
  signed int v25; // edi
  int v26; // ebx
  const char *v27; // eax
  char *v28; // eax
  char *v29; // edi
  void *v30; // ecx
  int v31; // eax
  char *v32; // eax
  loopback_t *v33; // edi
  CTSQueue<loopback_t *,0,1>::Node_t *v34; // eax
  CSaveRestore *v35; // edi
  const char *v36; // eax
  void *v37; // ecx
  int v38; // eax
  char v39; // bl
  void *v40; // ecx
  void *v41; // ecx
  int v42; // [esp-Ch] [ebp-174h]
  int v43; // [esp-Ch] [ebp-174h]
  const char *v44; // [esp-4h] [ebp-16Ch]
  const char *v45; // [esp-4h] [ebp-16Ch]
  char name[256]; // [esp+Ch] [ebp-15Ch] BYREF
  CUtlBuffer buffer; // [esp+10Ch] [ebp-5Ch] BYREF
  void *pBuffer; // [esp+13Ch] [ebp-2Ch]
  CMDLCacheCoarseCriticalSection cacheCoarseCriticalSection; // [esp+140h] [ebp-28h]
  SaveFileSectionsInfo_t sectionsInfo; // [esp+144h] [ebp-24h] BYREF
  CSaveRestore *v51; // [esp+154h] [ebp-14h]
  CUtlString src; // [esp+158h] [ebp-10h] BYREF
  ISaveRestoreFileSystem *bIsAutosaveOrDangerousa; // [esp+17Ch] [ebp+14h]

  v5 = g_pMDLCache;
  BeginCoarseLock = g_pMDLCache->BeginCoarseLock;
  v7 = this;
  v51 = this;
  cacheCoarseCriticalSection.m_pCache = g_pMDLCache;
  BeginCoarseLock(this: g_pMDLCache);
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "SaveGameState...\n");
  if ( bTransition && v7->m_bClearSaveDir )
  {
    IsXSave = v7->IsXSave;
    v7->m_bClearSaveDir = false;
    v10 = IsXSave(this: v7);
    CSaveRestore::DoClearSaveDir(this: v7, bIsXSave: v10);
  }
  S_ExtraUpdate(this: v8);
  v11 = serverGameDLL->SaveInit(this: serverGameDLL, a2: 0);
  v12 = v11;
  if ( v11 == nullptr )
  {
    v5->EndCoarseLock(this: v5);
    return 0;
  }
  pCurrentData = (int)v11->pCurrentData;
  v11->bAsync = bIsAutosaveOrDangerous;
  PreSave = serverGameDLL->PreSave;
  src.m_Storage.m_nActualLength = pCurrentData;
  PreSave(this: serverGameDLL, a2: v12);
  if ( bTransition )
    serverGameDLL->BuildAdjacentMapList(this: serverGameDLL);
  else
    v12->levelInfo.connectionCount = 0;
  S_ExtraUpdate(this: v16);
  CSaveRestore::SaveGameStateGlobals(this: v7, pSaveData: v12);
  S_ExtraUpdate(this: v17);
  serverGameDLL->Save(this: serverGameDLL, a2: v12);
  S_ExtraUpdate(this: v18);
  sectionsInfo.nBytesData = (int)&v12->pCurrentData[-pCurrentData];
  WriteSaveHeaders = serverGameDLL->WriteSaveHeaders;
  src.m_Storage.m_Memory.m_nGrowSize = (int)v12->pCurrentData;
  WriteSaveHeaders(this: serverGameDLL, a2: v12);
  nBytesDataHeaders = (int)&v12->pCurrentData[-src.m_Storage.m_Memory.m_nGrowSize];
  sectionsInfo.nBytesDataHeaders = nBytesDataHeaders;
  v21 = 0;
  src.m_Storage.m_Memory.m_nAllocationCount = (int)v12->pCurrentData;
  if ( v12->tokenCount <= 0 )
    goto LABEL_25;
  while ( 1 )
  {
    if ( v21 < 0 )
      goto LABEL_18;
    tokenCount = v12->tokenCount;
    if ( v21 >= tokenCount )
      goto LABEL_18;
    pTokens = v12->pTokens;
    if ( pTokens[v21] != nullptr )
    {
      if ( v21 < tokenCount )
      {
        v24 = pTokens[v21];
        goto LABEL_20;
      }
LABEL_18:
      v24 = "<<illegal>>";
      goto LABEL_20;
    }
    v24 = (char *)defaultValue;
LABEL_20:
    v25 = strlen(v24) + 1;
    if ( v25 > v12->bufferSize - v12->size )
      break;
    memcpy(dst: (unsigned __int8 *)v12->pCurrentData, src: (unsigned __int8 *)v24, count: v25);
    v12->pCurrentData += v25;
    v12->size += v25;
    if ( ++v21 >= v12->tokenCount )
      goto LABEL_24;
  }
  v12->size = v12->bufferSize;
LABEL_24:
  v7 = v51;
  nBytesDataHeaders = sectionsInfo.nBytesDataHeaders;
LABEL_25:
  sectionsInfo.nBytesSymbols = (int)&v12->pCurrentData[-src.m_Storage.m_Memory.m_nAllocationCount];
  v26 = nBytesDataHeaders + sectionsInfo.nBytesSymbols + sectionsInfo.nBytesData + 24;
  sectionsInfo.nSymbols = v12->tokenCount;
  pBuffer = MemAlloc_Alloc(nSize: v26);
  CUtlBuffer::CUtlBuffer(this: &buffer, pBuffer, nSize: v26, nFlags: 0);
  CUtlBuffer::Put(this: &buffer, pMem: &CURRENT_SAVEFILE_HEADER_TAG, size: 8);
  CUtlBuffer::Put(this: &buffer, pMem: &sectionsInfo, size: 16);
  CUtlBuffer::Put(
    this: &buffer,
    pMem: (const void *)src.m_Storage.m_Memory.m_nAllocationCount,
    size: sectionsInfo.nBytesSymbols);
  CUtlBuffer::Put(
    this: &buffer,
    pMem: (const void *)src.m_Storage.m_Memory.m_nGrowSize,
    size: sectionsInfo.nBytesDataHeaders);
  CUtlBuffer::Put(this: &buffer, pMem: (const void *)src.m_Storage.m_nActualLength, size: sectionsInfo.nBytesData);
  if ( v7->IsXSave(this: v7) )
  {
    name[0] = 0;
    V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
    v42 = 256 - _V_strlen(str: name);
    v31 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v31], maxLen: v42, pFormat: "//mod/%s.HL1", level);
  }
  else
  {
    V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
    v27 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))v7->GetSaveDir)(a1: v7, a2: level);
    V_snprintf(pDest: name, maxLen: 256, pFormat: "//%s/%s%s.HL1", "MOD", v27, v44);
    if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Queue COM_CreatePath\n");
    CUtlString::CUtlString(this: &src);
    CUtlString::operator=(this: &src, src: name);
    v28 = (char *)MemAlloc_Alloc(nSize: 0x24u);
    v29 = v28;
    if ( v28 != nullptr )
    {
      *((_DWORD *)v28 + 3) = 1;
      *(_DWORD *)v28 = &CFunctor1<void (__cdecl *)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v28 + 2) = &CFunctor1<void (__cdecl *)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v28 + 4) = COM_CreatePath;
      CUtlString::CUtlString(this: (CUtlString *)(v28 + 20));
      CUtlString::operator=(this: (CUtlString *)(v29 + 20), &src);
    }
    else
    {
      v29 = nullptr;
    }
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this: &g_AsyncSaveCallQueue, pFunctor: (CFunctor *)v29);
    src.m_Storage.m_nActualLength = 0;
    if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  }
  S_ExtraUpdate(this: v30);
  if ( save_spew.m_pParent != nullptr && save_spew.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Queue AsyncWrite (%s)\n", name);
  CUtlString::CUtlString(this: &src);
  CUtlString::operator=(this: &src, src: name);
  bIsAutosaveOrDangerousa = g_pSaveRestoreFileSystem;
  v32 = (char *)MemAlloc_Alloc(nSize: 0x38u);
  v33 = (loopback_t *)v32;
  if ( v32 != nullptr )
  {
    *((_DWORD *)v32 + 3) = 1;
    *(_DWORD *)v32 = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    *((_DWORD *)v32 + 2) = &CMemberFunctor6<ISaveRestoreFileSystem *,enum FSAsyncStatus_t (__thiscall ISaveRestoreFileSystem::*)(char const *,void const *,int,bool,bool,FSAsyncControl_t__ * *),CUtlEnvelope<char const *>,void *,int,bool,bool,FSAsyncControl_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *((_DWORD *)v32 + 4) =  __thiscall IToolSystem::`vcall'{52,{flat}};
    *((_DWORD *)v32 + 5) = bIsAutosaveOrDangerousa;
    CUtlString::CUtlString(this: (CUtlString *)(v32 + 24));
    CUtlString::operator=(this: (CUtlString *)&v33->defbuffer[16], &src);
    *(_DWORD *)&v33->defbuffer[32] = pBuffer;
    *(_DWORD *)&v33->defbuffer[36] = v26;
    *(_WORD *)&v33->defbuffer[40] = 1;
    *(_DWORD *)&v33->defbuffer[44] = 0;
  }
  else
  {
    v33 = nullptr;
  }
  if ( g_AsyncSaveCallQueue.m_bNoQueue )
  {
    (*((void (__thiscall **)(loopback_t *))v33->data + 3))(a1: v33);
    (*((void (__thiscall **)(loopback_t *))v33->data + 1))(a1: v33);
  }
  else
  {
    v34 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &g_AsyncSaveCallQueue.m_queue.m_FreeNodes);
    if ( v34 != nullptr || (v34 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
    {
      v34->elem = v33;
      CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: v34);
    }
    else
    {
      CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<StartSoundParams_t,0,1> *)&g_AsyncSaveCallQueue, pNode: nullptr);
    }
  }
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
  v35 = v51;
  CSaveRestore::EntityPatchWrite(this: v51, pSaveData: v12, level: level, bAsync: true);
  if ( pCallback != nullptr )
    pCallback->Execute(this: pCallback, a2: v12);
  v35->Finish(this: v35, a2: v12);
  if ( v35->IsXSave(this: v35) )
  {
    name[0] = 0;
    V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
    v43 = 256 - _V_strlen(str: name);
    v38 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v38], maxLen: v43, pFormat: "//mod/%s.HL2", level);
  }
  else
  {
    V_FileBase(in: sv.m_szMapname, out: level, maxlen: 256);
    v36 = (const char *)((int (__thiscall *)(CSaveRestore *, char *))v35->GetSaveDir)(a1: v35, a2: level);
    V_snprintf(pDest: name, maxLen: 256, pFormat: "//%s/%s%s.HL2", "MOD", v36, v45);
  }
  S_ExtraUpdate(this: v37);
  v39 = CSaveRestore::SaveClientState(this: v35, name);
  S_ExtraUpdate(this: v40);
  if ( bTransition )
    v35->FinishAsyncSave(this: v35);
  S_ExtraUpdate(this: v41);
  if ( buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
      buffer.m_Memory.m_pMemory = nullptr;
    }
    buffer.m_Memory.m_nAllocationCount = 0;
  }
  cacheCoarseCriticalSection.m_pCache->EndCoarseLock(this: cacheCoarseCriticalSection.m_pCache);
  return v39;
}

//------------------------------------------------------------------------------
// Address: 0x10195EA0
// Name: public: virtual void CSaveRestore::OnFinishedClientRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::OnFinishedClientRestore(CSaveRestore *this)
{
  void (__thiscall *FinishAsyncSave)(struct CSaveRestore *); // edx
  bool v3; // al

  g_ClientDLL->DispatchOnRestore(this: g_ClientDLL);
  CUtlDict<CSaveRestore::RestoreLookupTable,int>::RemoveAll(this: &this->m_RestoreLookup);
  if ( this->m_bClearSaveDir )
  {
    FinishAsyncSave = this->FinishAsyncSave;
    this->m_bClearSaveDir = false;
    FinishAsyncSave(this);
    v3 = this->IsXSave(this);
    CSaveRestore::DoClearSaveDir(this, bIsXSave: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195EF0
// Name: public: int CUtlDict<struct CSaveRestore::RestoreLookupTable,int>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CSaveRestore::RestoreLookupTable,int>::Insert(
        CUtlDict<CSaveRestore::RestoreLookupTable,int> *this,
        const char *pName)
{
  char *v2; // eax
  int v3; // esi
  CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t insert; // [esp+Ch] [ebp-28h] BYREF
  CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int> > *p_m_Tree; // [esp+30h] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v2, pName);
  else
    v2 = nullptr;
  memset(&insert.elem, 0, sizeof(insert.elem));
  insert.key = v2;
  v3 = CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         &insert);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&insert.elem);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10195F90
// Name: public: CSaveRestore::CSaveRestore(void)
// Source: json
//------------------------------------------------------------------------------
CSaveRestore *__thiscall CSaveRestore::CSaveRestore(CSaveRestore *this)
{
  CSaveRestore *result; // eax

  result = this;
  this->__vftable = (CSaveRestore_vtbl *)&CSaveRestore::`vftable';
  this->m_RestoreLookup.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_RestoreLookup.m_Elements.m_Tree.m_Root = -1;
  this->m_RestoreLookup.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_RestoreLookup.m_Elements.m_Tree.m_NumElements = 0;
  this->m_RestoreLookup.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_RestoreLookup.m_Elements.m_Tree.m_pElements = this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_RestoreLookup.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_RestoreLookup.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_sDeferredCommands.m_Memory.m_pMemory = nullptr;
  this->m_sDeferredCommands.m_Memory.m_nAllocationCount = 0;
  this->m_sDeferredCommands.m_Memory.m_nGrowSize = 0;
  this->m_sDeferredCommands.m_Size = 0;
  this->m_sDeferredCommands.m_pElements = nullptr;
  this->m_MostRecentSaveInfo.m_MostRecentSavePath[0] = 0;
  this->m_MostRecentSaveInfo.m_MostRecentSaveComment[0] = 0;
  this->m_MostRecentSaveInfo.m_LastAutosaveDangerousComment[0] = 0;
  this->m_MostRecentSaveInfo.m_bValid = false;
  this->m_bClearSaveDir = false;
  this->m_szSaveGameScreenshotFile[0] = 0;
  this->m_MostRecentElapsedMinutes = 0;
  this->m_MostRecentElapsedTimeSet = (int)g_ServerGlobalVariables.curtime;
  this->m_MostRecentElapsedSeconds = 0;
  this->m_MostRecentElapsedTimeSet = (int)g_ServerGlobalVariables.curtime;
  this->m_szMostRecentSaveLoadGame[0] = 0;
  this->m_szSaveGameName[0] = 0;
  *(_WORD *)&this->m_bIsXSave = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10196050
// Name: public: virtual bool CSaveRestore::IsXSave(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSaveRestore::IsXSave(CSaveRestore *this)
{
  return this->m_bIsXSave && (save_noxsave.m_pParent == nullptr || save_noxsave.m_pParent->m_Value.m_nValue == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10196080
// Name: private: struct CSaveRestore::RestoreLookupTable __near * CSaveRestore::FindOrAddRestoreLookupTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveRestore::RestoreLookupTable *__thiscall CSaveRestore::FindOrAddRestoreLookupTable(
        CSaveRestore *this,
        const char *mapname)
{
  int v3; // esi
  int v4; // eax
  CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t search; // [esp+8h] [ebp-24h] BYREF

  if ( mapname == nullptr
    || (memset(&search.elem, 0, sizeof(search.elem)),
        search.key = mapname,
        v3 = CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::Find(
               this: &this->m_RestoreLookup.m_Elements.m_Tree,
               &search),
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&search.elem),
        v4 = v3,
        v3 == -1) )
  {
    v4 = CUtlDict<CSaveRestore::RestoreLookupTable,int>::Insert(this: &this->m_RestoreLookup, pName: mapname);
  }
  return &this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10196100
// Name: private: void CSaveRestore::BuildRestoredIndexTranslationTable(char const __near *,class CSaveRestoreData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::BuildRestoredIndexTranslationTable(
        CSaveRestore *this,
        const char *mapname,
        CSaveRestoreData *pSaveData,
        bool verbose)
{
  int v5; // edi
  int v6; // eax
  CSaveRestoreData *v7; // edx
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *p_elem; // esi
  const char *v9; // eax
  CVTFTexture::ResourceMemorySection *m_pMemory; // edi
  int v11; // ecx
  int v12; // ebx
  int v13; // eax
  int m_nAllocationCount; // eax
  CVTFTexture::ResourceMemorySection *v15; // ecx
  int v16; // eax
  CVTFTexture::ResourceMemorySection *v17; // eax
  int savedindex; // ecx
  char name[256]; // [esp+Ch] [ebp-134h] BYREF
  CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t search; // [esp+10Ch] [ebp-34h] BYREF
  CSaveRestore::SaveRestoreTranslate slot; // [esp+130h] [ebp-10h]
  int tableCount; // [esp+13Ch] [ebp-4h]
  const char *mapnamea; // [esp+148h] [ebp+8h]

  V_FileBase(in: mapname, out: name, maxlen: 256);
  _V_strlower(start: name);
  memset(&search.elem, 0, sizeof(search.elem));
  search.key = name;
  v5 = CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::Find(
         this: &this->m_RestoreLookup.m_Elements.m_Tree,
         &search);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&search.elem);
  v6 = v5;
  if ( v5 == -1 )
    v6 = CUtlDict<CSaveRestore::RestoreLookupTable,int>::Insert(this: &this->m_RestoreLookup, pName: name);
  v7 = pSaveData;
  p_elem = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_RestoreLookup.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
  p_elem[1].m_pMemory = nullptr;
  p_elem[1].m_nGrowSize = 0;
  p_elem[2].m_pMemory = nullptr;
  p_elem[2].m_nAllocationCount = 0;
  if ( pSaveData->tableCount > 0 )
  {
    mapnamea = nullptr;
    tableCount = pSaveData->tableCount;
    do
    {
      v9 = &mapnamea[(unsigned int)v7->pTable];
      m_pMemory = p_elem[1].m_pMemory;
      v11 = *((_DWORD *)v9 + 2);
      v12 = *((_DWORD *)v9 + 8);
      v13 = *((_DWORD *)v9 + 3);
      slot.savedindex = v11;
      slot.restoredindex = v13;
      m_nAllocationCount = p_elem->m_nAllocationCount;
      if ( (int)&m_pMemory->m_nDataAllocSize + 1 > m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: p_elem,
          num: (int)&m_pMemory->m_nDataAllocSize - m_nAllocationCount + 1);
        v7 = pSaveData;
      }
      ++p_elem[1].m_pMemory;
      v15 = p_elem->m_pMemory;
      v16 = (char *)p_elem[1].m_pMemory - (char *)m_pMemory - 1;
      p_elem[1].m_nAllocationCount = (int)p_elem->m_pMemory;
      if ( v16 > 0 )
      {
        _V_memmove(dest: &v15[(int)m_pMemory + 1], src: &v15[(_DWORD)m_pMemory], count: 12 * v16);
        v7 = pSaveData;
      }
      v17 = &p_elem->m_pMemory[(_DWORD)m_pMemory];
      if ( v17 != nullptr )
      {
        savedindex = slot.savedindex;
        v17->m_nDataAllocSize = v12;
        v17->m_nDataLength = savedindex;
        v17->m_pData = (unsigned __int8 *)slot.restoredindex;
      }
      mapnamea += 56;
      --tableCount;
    }
    while ( tableCount != 0 );
  }
  *(float *)&p_elem[1].m_nGrowSize = v7->levelInfo.vecLandmarkOffset.x;
  *(float *)&p_elem[2].m_pMemory = v7->levelInfo.vecLandmarkOffset.y;
  *(float *)&p_elem[2].m_nAllocationCount = v7->levelInfo.vecLandmarkOffset.z;
}

//------------------------------------------------------------------------------
// Address: 0x10196280
// Name: private: int CSaveRestore::SaveReadHeader(void __near *,struct GAME_HEADER __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge CSaveRestore::SaveReadHeader@<eax>(
        CSaveRestore *this@<ecx>,
        int a2@<edi>,
        void *pFile,
        GAME_HEADER *pHeader,
        int readGlobalState)
{
  void *v5; // ebx
  unsigned __int8 *v7; // eax
  CSaveRestoreData *v8; // esi
  char *v9; // edi
  int v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // ecx
  int i; // ebx
  int v14; // eax
  int tokenSize; // [esp+4h] [ebp-14h] BYREF
  int tag; // [esp+8h] [ebp-10h] BYREF
  CSaveRestore *v18; // [esp+Ch] [ebp-Ch]
  int size; // [esp+10h] [ebp-8h] BYREF
  int tokenCount; // [esp+14h] [ebp-4h] BYREF

  v5 = pFile;
  v18 = this;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 4, a4: pFile) != 4 )
    return false;
  if ( tag != 1447121738 )
  {
    _Warning(a1: "Can't load saved game, incorrect FILEID\n");
    return false;
  }
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 4, a4: pFile) != 4 )
    return false;
  if ( tag != 116 )
  {
    _Warning(a1: "Can't load saved game, incorrect version (got %i expecting %i)\n", tag, 116);
    return false;
  }
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &size, a3: 4, a4: pFile) != 4 )
    return false;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tokenCount, a3: 4, a4: pFile) != 4 )
    return false;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tokenSize, a3: 4, a4: pFile) != 4 )
    return false;
  v7 = SaveAllocMemory(num: tokenSize + size + 1444, size: 1u, bClear: false);
  if ( v7 == nullptr )
    return false;
  v8 = CSaveRestoreData::CSaveRestoreData(this: (CSaveRestoreData *)v7);
  v8->levelInfo.connectionCount = 0;
  v9 = (char *)&v8[1];
  if ( tokenSize <= 0 )
  {
    v8->tokenCount = 0;
    v8->pTokens = nullptr;
  }
  else
  {
    v10 = g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &v8[1], a3: tokenSize, a4: pFile);
    if ( v10 != tokenSize )
      goto LABEL_21;
    v11 = SaveAllocMemory(num: tokenCount, size: 4u, bClear: true);
    if ( v11 == nullptr )
      goto LABEL_21;
    v12 = tokenCount;
    v8->tokenCount = tokenCount;
    v8->pTokens = (char **)v11;
    memset(dst: v11, value: 0, count: 4 * v12);
    for ( i = 0; i < tokenCount; ++i )
    {
      if ( *v9 != 0 )
        CSaveRestoreSegment::DefineSymbol(this: v8, pszToken: v9, token: i);
      v9 += strlen(v9) + 1;
    }
    v5 = pFile;
  }
  v8->levelInfo.fUseLandmark = 0;
  v8->levelInfo.time = 0.0;
  v8->bufferSize = size;
  v8->pBaseData = v9;
  v8->pCurrentData = v9;
  v8->size = 0;
  v14 = g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: v9, a3: size, a4: v5);
  if ( v14 != size )
  {
LABEL_21:
    v18->Finish(this: v18, a2: v8);
    return false;
  }
  ((void (__thiscall *)(IServerGameDLL *, CSaveRestoreData *, const char *, GAME_HEADER *, _DWORD, typedescription_t *, int, int))serverGameDLL->SaveReadFields)(
    a1: serverGameDLL,
    a2: v8,
    a3: "GameHeader",
    a4: pHeader,
    a5: 0,
    a6: GAME_HEADER::m_DataMap.dataDesc,
    a7: GAME_HEADER::m_DataMap.dataNumFields,
    a8: a2);
  if ( g_szMapLoadOverride[0] != 0 )
  {
    V_strncpy(pDest: pHeader->mapName, pSrc: g_szMapLoadOverride, maxLen: 32);
    g_szMapLoadOverride[0] = 0;
  }
  if ( readGlobalState != 0 )
    serverGameDLL->RestoreGlobalState(this: serverGameDLL, a2: v8);
  v18->Finish(this: v18, a2: v8);
  return pHeader->mapCount != 0
      || g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &pHeader->mapCount, a3: 4, a4: v5) == 4;
}

//------------------------------------------------------------------------------
// Address: 0x101964F0
// Name: public: virtual bool CSaveRestore::LoadGame(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CSaveRestore::LoadGame@<al>(
        CSaveRestore *this@<ecx>,
        int a2@<ebx>,
        const char *pName,
        bool bLetToolsOverrideLoadGameEnts)
{
  void (__thiscall *FinishAsyncSave)(struct CSaveRestore *); // edx
  bool (__thiscall *IsXSave)(struct CSaveRestore *); // eax
  bool v8; // al
  void *(__thiscall *Open)(ISaveRestoreFileSystem *, const char *, const char *, const char *); // edx
  void *v10; // edi
  int v11; // kr00_4
  bool v12; // al
  int v13; // edx
  bool v14; // al
  void (__thiscall *SetMostRecentElapsedMinutes)(struct CSaveRestore *, const int); // edx
  bool v16; // bl
  char szDummyName[260]; // [esp+8h] [ebp-5ACh] BYREF
  char szComment[260]; // [esp+10Ch] [ebp-4A8h] BYREF
  char szElapsedTime[260]; // [esp+210h] [ebp-3A4h] BYREF
  char name[260]; // [esp+314h] [ebp-2A0h] BYREF
  GAME_HEADER gameHeader; // [esp+418h] [ebp-19Ch] BYREF
  int iElapsedSeconds; // [esp+5ACh] [ebp-8h]
  bool validload; // [esp+5B3h] [ebp-1h]
  int iElapsedMinutes; // [esp+5BCh] [ebp+8h]

  FinishAsyncSave = this->FinishAsyncSave;
  validload = false;
  FinishAsyncSave(this);
  SaveResetMemory();
  if ( CSaveRestore::CalcSaveGameName(this, pName, output: name, outputStringLength: 260) != 0 )
  {
    this->SetMostRecentSaveGame(this, a2: pName);
    ConMsg(a1: "Loading game from %s...\n", name);
    IsXSave = this->IsXSave;
    this->m_bClearSaveDir = false;
    v8 = IsXSave(this);
    CSaveRestore::DoClearSaveDir(this, bIsXSave: v8);
    Open = g_pSaveRestoreFileSystem->Open;
    iElapsedMinutes = 0;
    iElapsedSeconds = 0;
    v10 = Open(this: g_pSaveRestoreFileSystem, a2: name, a3: "rb", a4: "MOD");
    if ( v10 != nullptr )
    {
      if ( ((int (__thiscall *)(CSaveRestore *, void *, char *, char *, int))this->SaveReadNameAndComment)(
             a1: this,
             a2: v10,
             a3: szDummyName,
             a4: szComment,
             a5: a2) != 0 )
      {
        v11 = strlen(szComment);
        V_strncpy(pDest: szElapsedTime, pSrc: "??", maxLen: 260);
        if ( v11 >= 6 )
        {
          V_strncpy(pDest: szElapsedTime, pSrc: &szDummyName[v11 + 254], maxLen: 7);
          szElapsedTime[6] = 0;
          iElapsedMinutes = atoi(nptr: szElapsedTime);
          iElapsedSeconds = atoi(nptr: &szElapsedTime[4]);
        }
        g_pSaveRestoreFileSystem->Seek(this: g_pSaveRestoreFileSystem, a2: v10, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
        if ( CSaveRestore::SaveReadHeader(this, a2: (int)v10, pFile: v10, pHeader: &gameHeader, readGlobalState: 1) )
          validload = CSaveRestore::DirectoryExtract(this, pFile: v10, fileCount: gameHeader.mapCount);
        if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: (const char *)&gameHeader) == 0 )
        {
          _Msg(a1: "Map '%s' missing or invalid\n", gameHeader.mapName);
          validload = false;
        }
        g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v10);
        if ( validload )
        {
          GetBaseLocalClient()->demonum = -1;
          CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&deathmatch.IConVar, value: 0);
          CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&coop.IConVar, value: 0);
          if ( CL_HL2Demo_MapCheck(name: gameHeader.mapName) && CL_PortalDemo_MapCheck(name: gameHeader.mapName) )
          {
            v12 = gameHeader.originMapName[0] != 0;
            v13 = -(gameHeader.originMapName[0] != 0);
            this->m_bOverrideLoadGameEntsOn = bLetToolsOverrideLoadGameEnts;
            v14 = Host_NewGame(
                    mapName: gameHeader.mapName,
                    loadGame: true,
                    bBackgroundLevel: false,
                    bSplitScreenConnect: false,
                    pszOldMap: v12 ? gameHeader.originMapName : nullptr,
                    pszLandmark: (const char *)((unsigned int)gameHeader.landmark & v13));
            SetMostRecentElapsedMinutes = this->SetMostRecentElapsedMinutes;
            v16 = v14;
            this->m_bOverrideLoadGameEntsOn = false;
            SetMostRecentElapsedMinutes(this, a2: iElapsedMinutes);
            this->SetMostRecentElapsedSeconds(this, a2: iElapsedSeconds);
            return v16;
          }
          else
          {
            _Warning(a1: "Save file %s is not valid\n", name);
            return false;
          }
        }
        else
        {
          _Msg(a1: "Save file %s is not valid\n", name);
          return false;
        }
      }
      else
      {
        g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v10);
        return false;
      }
    }
    else
    {
      ConMsg(a1: "File not found or failed to open.\n");
      return false;
    }
  }
  else
  {
    DevWarning(a1: "Loaded bad game %s\n", pName);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196820
// Name: public: virtual void CSaveRestore::Finish(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestore::Finish(CSaveRestore *this, CSaveRestoreData *save)
{
  char **pTokens; // eax
  entitytable_t *pTable; // eax

  _Msg(
    a1: "SAVEGAME: %6.1fkb, %6.1fkb used by %3d entities (%s)\n",
    0.0009765625 * (double)save->size,
    (double)save->m_nEntityDataSize * 0.0009765625,
    save->tableCount,
    sv.m_szMapname);
  pTokens = save->pTokens;
  save->tokenCount = 0;
  save->pTokens = nullptr;
  if ( pTokens != nullptr )
    SaveFreeMemory();
  pTable = save->pTable;
  save->pTable = nullptr;
  save->tableCount = 0;
  if ( pTable != nullptr )
    SaveFreeMemory();
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &save->m_EntityToIndex);
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &save->m_EntityToIndex);
  CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::~CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>(this: &save->m_EntityToIndex.m_Buckets);
  DevMsg(a1: "Freeing %d bytes of save data\n", save->size);
  SaveFreeMemory();
  g_ServerGlobalVariables.pSaveData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101968E0
// Name: public: virtual void CSaveRestore::RestoreClientState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveRestore::RestoreClientState(
        CSaveRestore *this@<ecx>,
        int a2@<esi>,
        const char *fileName,
        bool adjacent)
{
  void (__thiscall *FinishAsyncSave)(struct CSaveRestore *); // edx
  void *v5; // edi
  char v6; // al
  ISaveRestoreFileSystem_vtbl *v7; // edx
  int v8; // esi
  ISaveRestoreFileSystem_vtbl *v9; // eax
  ISaveRestoreFileSystem_vtbl *v10; // edx
  unsigned __int8 *v11; // eax
  CSaveRestoreData *v12; // esi
  const char *v13; // edi
  unsigned __int8 *v14; // eax
  int j; // ecx
  char **pTokens; // eax
  bool v17; // zf
  const char **v18; // eax
  int v19; // eax
  char *pCurrentData; // ecx
  CSaveRestore *v21; // edi
  CSaveRestore::RestoreLookupTable *v22; // ebx
  int tableCount; // eax
  int m_Size; // edi
  entitytable_t *v25; // eax
  int v26; // ecx
  CSaveRestore::SaveRestoreTranslate *m_pMemory; // edx
  int restoredindex; // edx
  const char *pszValue; // eax
  CClientState *BaseLocalClient; // eax
  int v31; // edi
  INetworkStringTable *ModelPrecacheTable; // eax
  INetworkStringTable *v33; // eax
  const char *v34; // eax
  const char *v35; // ebx
  INetworkStringTable *m_pModelPrecacheTable; // eax
  const char *v37; // ecx
  INetworkStringTable *v38; // eax
  int m; // edi
  int v40; // ecx
  int v41; // eax
  CSaveRestore::SaveRestoreTranslate *v42; // edx
  int v43; // edx
  unsigned int v44; // [esp-8h] [ebp-204h]
  void *v45; // [esp-4h] [ebp-200h]
  char name[256]; // [esp+8h] [ebp-1F4h] BYREF
  channelsave channel; // [esp+108h] [ebp-F4h] BYREF
  int v48; // [esp+18Ch] [ebp-70h]
  SaveFileHeaderTag_t tag; // [esp+1A4h] [ebp-58h] BYREF
  baseclientsectionsold_t oldsections; // [esp+1ACh] [ebp-50h] BYREF
  int magicnumber; // [esp+1C4h] [ebp-38h] BYREF
  int sectionheaderversion; // [esp+1C8h] [ebp-34h] BYREF
  int k; // [esp+1CCh] [ebp-30h]
  baseclientsections_t sections; // [esp+1D0h] [ebp-2Ch] BYREF
  unsigned int v55; // [esp+1F0h] [ebp-Ch]
  CSaveRestore *v56; // [esp+1F4h] [ebp-8h]
  CSaveRestore::RestoreLookupTable *table; // [esp+1F8h] [ebp-4h]
  int savedregs; // [esp+1FCh] [ebp+0h] BYREF
  int i; // [esp+204h] [ebp+8h]
  char i_3; // [esp+207h] [ebp+Bh]

  FinishAsyncSave = this->FinishAsyncSave;
  v56 = this;
  ((void (__fastcall *)(CSaveRestore *))FinishAsyncSave)(a1: this);
  v5 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: fileName, a3: "rb", a4: nullptr);
  if ( v5 == nullptr )
  {
    DevMsg(a1: "Failed to open client state file %s\n", fileName);
    return;
  }
  g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 8, a4: v5);
  v6 = SaveFileHeaderTag_t::operator!=(this: &tag, rhs: &CURRENT_SAVEFILE_HEADER_TAG);
  v7 = g_pSaveRestoreFileSystem->__vftable;
  if ( v6 != 0 )
  {
    ((void (__stdcall *)(void *))v7->Close)(a1: v5);
    return;
  }
  v8 = ((int (__stdcall *)(void *, int))v7->Tell)(a1: v5, a2);
  sectionheaderversion = 1;
  magicnumber = 0;
  g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &magicnumber, a3: 4, a4: v5);
  v9 = g_pSaveRestoreFileSystem->__vftable;
  if ( magicnumber == 1414795828 )
  {
    ((void (__stdcall *)(int *, int, void *))v9->Read)(a1: &sectionheaderversion, a2: 4, a3: v5);
    v10 = g_pSaveRestoreFileSystem->__vftable;
    v45 = v5;
    if ( sectionheaderversion != 2 )
    {
      ((void (*)(void))v10->Close)();
      return;
    }
    ((void (__stdcall *)(baseclientsections_t *, int))v10->Read)(a1: &sections, a2: 32);
  }
  else
  {
    v45 = nullptr;
    ((void (__stdcall *)(void *, int))v9->Seek)(a1: v5, a2: v8);
    g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &oldsections, a3: 24, a4: v5);
    _V_memset(dest: &sections, fill: 0, count: 32);
    sections.entitysize = oldsections.entitysize;
    sections.headersize = oldsections.headersize;
    sections.decalsize = oldsections.decalsize;
    sections.symbolsize = oldsections.symbolsize;
    sections.decalcount = oldsections.decalcount;
    sections.symbolcount = oldsections.symbolcount;
  }
  v11 = SaveAllocMemory(
          num: sections.entitysize
        + sections.headersize
        + sections.decalsize
        + sections.channelsize
        + sections.symbolsize
        + 1444,
          size: 1u,
          bClear: false);
  if ( v11 != nullptr )
  {
    v12 = CSaveRestoreData::CSaveRestoreData(this: (CSaveRestoreData *)v11);
    V_strncpy(pDest: v12->levelInfo.szCurrentMapName, pSrc: fileName, maxLen: 32);
    g_pSaveRestoreFileSystem->Read(
      this: g_pSaveRestoreFileSystem,
      a2: &v12[1],
      a3: sections.entitysize + sections.headersize + sections.decalsize + sections.symbolsize + sections.channelsize,
      a4: v5);
    g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v5);
    v13 = (const char *)&v12[1];
    if ( sections.symbolsize <= 0 )
    {
      v12->tokenCount = 0;
      v12->pTokens = nullptr;
    }
    else
    {
      v14 = SaveAllocMemory(num: sections.symbolcount, size: 4u, bClear: true);
      if ( v14 == nullptr )
      {
        SaveFreeMemory();
        return;
      }
      v44 = 4 * sections.symbolcount;
      v12->tokenCount = sections.symbolcount;
      v12->pTokens = (char **)v14;
      memset(dst: v14, value: 0, count: v44);
      for ( j = 0; j < sections.symbolcount; ++j )
      {
        if ( *v13 != 0 )
        {
          pTokens = v12->pTokens;
          v17 = pTokens[j] == nullptr;
          v18 = (const char **)&pTokens[j];
          if ( v17 )
            *v18 = v13;
        }
        v13 += strlen(v13) + 1;
      }
    }
    v19 = sections.entitysize + sections.headersize + sections.channelsize + sections.decalsize;
    v12->pBaseData = (char *)v13;
    v12->bufferSize = v19;
    v12->pCurrentData = (char *)v13;
    v12->size = 0;
    ((void (__thiscall *)(IBaseClientDLL *, CSaveRestoreData *, void *))g_ClientDLL->ReadRestoreHeaders)(
      a1: g_ClientDLL,
      a2: v12,
      a3: v45);
    pCurrentData = v12->pCurrentData;
    v12->bufferSize -= v12->size;
    v21 = v56;
    v12->pBaseData = pCurrentData;
    v12->size = 0;
    v12->levelInfo.time = v21->m_flClientSaveRestoreTime;
    V_FileBase(in: fileName, out: name, maxlen: 256);
    _V_strlower(start: name);
    v22 = CSaveRestore::FindOrAddRestoreLookupTable(this: v21, mapname: name);
    table = v22;
    v12->levelInfo.fUseLandmark = adjacent;
    if ( adjacent )
    {
      v12->levelInfo.vecLandmarkOffset.x = v22->m_vecLandMarkOffset.x;
      v12->levelInfo.vecLandmarkOffset.y = v22->m_vecLandMarkOffset.y;
      v12->levelInfo.vecLandmarkOffset.z = v22->m_vecLandMarkOffset.z;
    }
    tableCount = v12->tableCount;
    i_3 = 0;
    if ( tableCount > 0 )
    {
      v55 = 0;
      for ( k = tableCount; k != 0; --k )
      {
        m_Size = v22->lookup.m_Size;
        v25 = &v12->pTable[v55 / 0x38];
        v26 = 0;
        if ( m_Size <= 0 )
        {
LABEL_30:
          restoredindex = -1;
        }
        else
        {
          m_pMemory = v22->lookup.m_Memory.m_pMemory;
          while ( m_pMemory->savedindex != v25->saveentityindex )
          {
            ++v26;
            ++m_pMemory;
            if ( v26 >= m_Size )
            {
              v22 = table;
              goto LABEL_30;
            }
          }
          restoredindex = m_pMemory->restoredindex;
          v22 = table;
        }
        v25->restoreentityindex = restoredindex;
        if ( restoredindex == -1 && v25->classname.pszValue != nullptr && v25->modelname.pszValue != nullptr )
        {
          pszValue = v25->modelname.pszValue;
          if ( pszValue == nullptr )
            pszValue = defaultValue;
          CGameServer::PrecacheModel(this: &sv, name: pszValue, flags: 3, model: nullptr);
          i_3 = 1;
        }
        v55 += 56;
      }
      if ( i_3 == 1 )
      {
        BaseLocalClient = GetBaseLocalClient();
        v31 = BaseLocalClient->m_pModelPrecacheTable->GetNumStrings(this: BaseLocalClient->m_pModelPrecacheTable);
        ModelPrecacheTable = CGameServer::GetModelPrecacheTable(this: &sv);
        if ( v31 < ModelPrecacheTable->GetNumStrings(this: ModelPrecacheTable) )
        {
          do
          {
            v33 = CGameServer::GetModelPrecacheTable(this: &sv);
            v34 = v33->GetString(this: v33, a2: v31);
            if ( v34 != nullptr && *v34 != 0 )
              v35 = v34;
            else
              v35 = nullptr;
            m_pModelPrecacheTable = GetBaseLocalClient()->m_pModelPrecacheTable;
            v37 = v35;
            if ( v35 == nullptr )
              v37 = defaultValue;
            m_pModelPrecacheTable->AddString(this: m_pModelPrecacheTable, a2: true, a3: v37, a4: -1, a5: nullptr);
            ++v31;
            v38 = CGameServer::GetModelPrecacheTable(this: &sv);
          }
          while ( v31 < v38->GetNumStrings(this: v38) );
          v22 = table;
        }
      }
    }
    g_ClientDLL->Restore(this: g_ClientDLL, a2: v12, a3: false);
    if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
    {
      for ( m = 0; m < sections.decalcount; ++m )
      {
        g_ClientDLL->SaveReadFields(
          this: g_ClientDLL,
          a2: v12,
          a3: "DECALLIST",
          a4: &channel,
          a5: nullptr,
          a6: decallist_t::m_DataMap.dataDesc,
          a7: decallist_t::m_DataMap.dataNumFields);
        CSaveRestore::ReapplyDecal(
          this: v56,
          a2: (CTraceFilterHitAll_vtbl *)&savedregs,
          adjacent,
          table: v22,
          entry: (decallist_t *)&channel);
      }
    }
    for ( i = 0; i < sections.channelcount; ++i )
    {
      g_ClientDLL->SaveReadFields(
        this: g_ClientDLL,
        a2: v12,
        a3: "CHANNELLIST",
        a4: &channel.soundName[52],
        a5: nullptr,
        a6: channelsave::m_DataMap.dataDesc,
        a7: channelsave::m_DataMap.dataNumFields);
      v40 = v22->lookup.m_Size;
      v41 = 0;
      if ( v40 <= 0 )
      {
LABEL_58:
        v43 = -1;
      }
      else
      {
        v42 = v22->lookup.m_Memory.m_pMemory;
        while ( v42->savedindex != v48 )
        {
          ++v41;
          ++v42;
          if ( v41 >= v40 )
            goto LABEL_58;
        }
        v43 = v42->restoredindex;
      }
      v48 = v43;
      S_RestartChannel(channelSave: (const channelsave *)&channel.soundName[52]);
    }
    ((void (__thiscall *)(CSaveRestore *))v56->Finish)(a1: v56);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196E10
// Name: private: class CSaveRestoreData __near * CSaveRestore::LoadSaveData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CSaveRestore::LoadSaveData(CSaveRestore *this, const char *level)
{
  bool (__thiscall *IsXSave)(struct CSaveRestore *); // edx
  const char *v4; // eax
  int v5; // eax
  void *v6; // eax
  void *v7; // ebx
  unsigned __int8 *v9; // eax
  CSaveRestoreData *v10; // esi
  int v11; // edi
  int v12; // ebx
  const char *v13; // edi
  unsigned __int8 *v14; // eax
  int v15; // eax
  int v16; // [esp-Ch] [ebp-138h]
  const char *v17; // [esp-4h] [ebp-130h]
  unsigned int v18; // [esp-4h] [ebp-130h]
  char name[260]; // [esp+Ch] [ebp-120h] BYREF
  SaveFileHeaderTag_t tag; // [esp+110h] [ebp-1Ch] BYREF
  CSaveRestore *v21; // [esp+118h] [ebp-14h]
  SaveFileSectionsInfo_t sectionsInfo; // [esp+11Ch] [ebp-10h] BYREF

  IsXSave = this->IsXSave;
  v21 = this;
  if ( ((unsigned __int8 (__fastcall *)(CSaveRestore *))IsXSave)(a1: this) != 0 )
  {
    name[0] = 0;
    v16 = 260 - _V_strlen(str: name);
    v5 = _V_strlen(str: name);
    V_snprintf(pDest: &name[v5], maxLen: v16, pFormat: "//mod/%s.HL1", level);
  }
  else
  {
    v4 = (const char *)((int (__thiscall *)(CSaveRestore *, const char *))this->GetSaveDir)(a1: this, a2: level);
    V_snprintf(pDest: name, maxLen: 260, pFormat: "//%s/%s%s.HL1", "MOD", v4, v17);
  }
  ConMsg(a1: "Loading game from %s...\n", name);
  v6 = (void *)g_pSaveRestoreFileSystem->Open(this: g_pSaveRestoreFileSystem, a2: name, a3: "rb", a4: nullptr);
  v7 = v6;
  if ( v6 == nullptr )
  {
    ConMsg(a1: "ERROR: couldn't open.\n");
    return nullptr;
  }
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &tag, a3: 8, a4: v6) != 8 )
    return nullptr;
  if ( SaveFileHeaderTag_t::operator!=(this: &tag, rhs: &CURRENT_SAVEFILE_HEADER_TAG) != 0 )
    return nullptr;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &sectionsInfo, a3: 16, a4: v7) != 16 )
    return nullptr;
  v9 = SaveAllocMemory(
         num: sectionsInfo.nBytesSymbols + sectionsInfo.nBytesData + sectionsInfo.nBytesDataHeaders + 1444,
         size: 1u,
         bClear: false);
  if ( v9 == nullptr )
    return nullptr;
  v10 = CSaveRestoreData::CSaveRestoreData(this: (CSaveRestoreData *)v9);
  V_strncpy(pDest: v10->levelInfo.szCurrentMapName, pSrc: level, maxLen: 32);
  v11 = sectionsInfo.nBytesSymbols + sectionsInfo.nBytesData + sectionsInfo.nBytesDataHeaders;
  if ( g_pSaveRestoreFileSystem->Read(this: g_pSaveRestoreFileSystem, a2: &v10[1], a3: v11, a4: v7) != v11 )
  {
    v21->Finish(this: v21, a2: v10);
    return nullptr;
  }
  g_pSaveRestoreFileSystem->Close(this: g_pSaveRestoreFileSystem, a2: v7);
  v12 = 0;
  v13 = (const char *)&v10[1];
  if ( sectionsInfo.nBytesSymbols <= 0 )
  {
    v10->tokenCount = 0;
    v10->pTokens = nullptr;
  }
  else
  {
    v14 = SaveAllocMemory(num: sectionsInfo.nSymbols, size: 4u, bClear: true);
    if ( v14 == nullptr )
    {
      SaveFreeMemory();
      return nullptr;
    }
    v18 = 4 * sectionsInfo.nSymbols;
    v10->tokenCount = sectionsInfo.nSymbols;
    v10->pTokens = (char **)v14;
    memset(dst: v14, value: 0, count: v18);
    if ( sectionsInfo.nSymbols > 0 )
    {
      do
      {
        if ( *v13 != 0 )
          CSaveRestoreSegment::DefineSymbol(this: v10, pszToken: v13, token: v12);
        v13 += strlen(v13) + 1;
        ++v12;
      }
      while ( v12 < sectionsInfo.nSymbols );
    }
  }
  v15 = sectionsInfo.nBytesData + sectionsInfo.nBytesDataHeaders;
  v10->levelInfo.connectionCount = 0;
  v10->pBaseData = (char *)v13;
  v10->pCurrentData = (char *)v13;
  v10->size = 0;
  v10->bufferSize = v15;
  v10->levelInfo.fUseLandmark = 1;
  v10->levelInfo.time = 0.0;
  v10->levelInfo.vecLandmarkOffset = vec3_origin;
  g_ServerGlobalVariables.pSaveData = v10;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x101970A0
// Name: public: virtual int CSaveRestore::LoadGameState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CSaveRestore::LoadGameState(CSaveRestore *this, const char *level, BOOL createPlayers)
{
  CSaveRestoreData *result; // eax
  CSaveRestoreData *v5; // esi
  CSaveRestore_vtbl *v6; // eax
  SAVE_HEADER header; // [esp+Ch] [ebp-64h] BYREF
  ConVarRef skyname; // [esp+68h] [ebp-8h] BYREF

  V_FileBase(in: level, out: ::level, maxlen: 256);
  result = CSaveRestore::LoadSaveData(this, level: ::level);
  v5 = result;
  if ( result != nullptr )
  {
    serverGameDLL->ReadRestoreHeaders(this: serverGameDLL, a2: result);
    CSaveRestore::ParseSaveTables(this, pSaveData: v5, pHeader: &header, updateGlobals: 1);
    CSaveRestore::EntityPatchRead(this, pSaveData: v5, level);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&skill.IConVar, value: header.skillLevel);
    V_strncpy(pDest: sv.m_szMapname, pSrc: header.mapName, maxLen: 64);
    ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname");
    if ( ConVarRef::IsValid(this: &skyname) )
      skyname.m_pConVar->SetValue_4(this: skyname.m_pConVar, a2: header.skyName);
    serverGameDLL->Restore(this: serverGameDLL, a2: v5, a3: createPlayers);
    CSaveRestore::BuildRestoredIndexTranslationTable(this, mapname: level, pSaveData: v5, verbose: false);
    v6 = this->__vftable;
    this->m_flClientSaveRestoreTime = v5->levelInfo.time;
    v6->Finish(this, a2: v5);
    sv.m_nTickCount = (int)(float)(header.time / host_state.interval_per_tick);
    return (CSaveRestoreData *)1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101971A0
// Name: public: virtual void CSaveRestore::LoadAdjacentEnts(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveRestore::LoadAdjacentEnts(
        CSaveRestore *this@<ecx>,
        CSaveRestoreData *a2@<edi>,
        const char *pOldLevel,
        const char *pLandmarkName)
{
  CSaveRestore *v4; // ebx
  void (__thiscall *FinishAsyncSave)(struct CSaveRestore *); // edx
  levellist_t *levelList; // edi
  int v7; // esi
  CSaveRestoreData *SaveData; // esi
  int v9; // edi
  float z; // xmm0_4
  char *v11; // ecx
  int j; // edi
  const char *mapName; // ebx
  vgui::CTreeViewListControl *v14; // ecx
  ECommandTarget_t TraceType; // eax
  CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> > *m_pMemory; // eax
  Vector *p_vecLandmarkOrigin; // eax
  char *m_szBuf; // [esp-8h] [ebp-744h]
  CFmtStrN<256> v20; // [esp+8h] [ebp-734h] BYREF
  SAVE_HEADER header; // [esp+114h] [ebp-628h] BYREF
  CSaveRestoreData currentLevelData; // [esp+170h] [ebp-5CCh] BYREF
  int movedCount; // [esp+714h] [ebp-28h]
  Vector landmarkOrigin; // [esp+718h] [ebp-24h]
  CSaveRestore *v25; // [esp+724h] [ebp-18h]
  char *s1; // [esp+728h] [ebp-14h]
  int i; // [esp+72Ch] [ebp-10h]
  char *in; // [esp+730h] [ebp-Ch]
  int flags; // [esp+734h] [ebp-8h]
  bool foundprevious; // [esp+73Bh] [ebp-1h]

  v4 = this;
  FinishAsyncSave = this->FinishAsyncSave;
  v25 = this;
  ((void (__fastcall *)(CSaveRestore *))FinishAsyncSave)(a1: this);
  CSaveRestoreData::CSaveRestoreData(this: &currentLevelData);
  movedCount = 0;
  memset(dst: (unsigned __int8 *)&currentLevelData, value: 0, count: sizeof(currentLevelData));
  g_ServerGlobalVariables.pSaveData = &currentLevelData;
  serverGameDLL->BuildAdjacentMapList(this: serverGameDLL);
  foundprevious = false;
  i = 0;
  if ( currentLevelData.levelInfo.connectionCount > 0 )
  {
    levelList = currentLevelData.levelInfo.levelList;
    in = currentLevelData.levelInfo.levelList[0].mapName;
    do
    {
      if ( _V_stricmp(s1: levelList->mapName, s2: pOldLevel) == 0 )
        foundprevious = true;
      v7 = 0;
      if ( i <= 0 )
        goto LABEL_11;
      flags = (int)currentLevelData.levelInfo.levelList;
      while ( _V_stricmp(s1: levelList->mapName, s2: (const char *)flags) != 0 )
      {
        flags += 80;
        if ( ++v7 >= i )
          goto LABEL_11;
      }
      if ( v7 >= i )
      {
LABEL_11:
        V_FileBase(in: levelList->mapName, out: level, maxlen: 256);
        SaveData = CSaveRestore::LoadSaveData(this: v4, level: level);
        if ( SaveData != nullptr )
        {
          ((void (__thiscall *)(IServerGameDLL *, CSaveRestoreData *, CSaveRestoreData *))serverGameDLL->ReadRestoreHeaders)(
            a1: serverGameDLL,
            a2: SaveData,
            a3: a2);
          CSaveRestore::ParseSaveTables(this: v4, pSaveData: SaveData, pHeader: &header, updateGlobals: 0);
          CSaveRestore::EntityPatchRead(this: v4, pSaveData: SaveData, level: levelList->mapName);
          SaveData->levelInfo.time = CBaseServer::GetTime(this: &sv);
          v9 = 0;
          SaveData->levelInfo.fUseLandmark = 1;
          flags = 0;
          if ( currentLevelData.levelInfo.connectionCount <= 0 )
          {
LABEL_16:
            landmarkOrigin.x = vec3_origin.x;
            landmarkOrigin.y = vec3_origin.y;
            z = vec3_origin.z;
          }
          else
          {
            s1 = currentLevelData.levelInfo.levelList[0].landmarkName;
            while ( _V_stricmp(s1, s2: pLandmarkName) != 0 )
            {
              s1 += 80;
              if ( ++v9 >= currentLevelData.levelInfo.connectionCount )
                goto LABEL_16;
            }
            p_vecLandmarkOrigin = &currentLevelData.levelInfo.levelList[v9].vecLandmarkOrigin;
            landmarkOrigin.x = p_vecLandmarkOrigin->x;
            landmarkOrigin.y = p_vecLandmarkOrigin->y;
            z = p_vecLandmarkOrigin->z;
          }
          landmarkOrigin.z = z;
          LandmarkOrigin(pSaveData: SaveData, output: &SaveData->levelInfo.vecLandmarkOffset, pLandmarkName);
          v11 = in;
          SaveData->levelInfo.vecLandmarkOffset.x = landmarkOrigin.x - SaveData->levelInfo.vecLandmarkOffset.x;
          SaveData->levelInfo.vecLandmarkOffset.y = landmarkOrigin.y - SaveData->levelInfo.vecLandmarkOffset.y;
          SaveData->levelInfo.vecLandmarkOffset.z = landmarkOrigin.z - SaveData->levelInfo.vecLandmarkOffset.z;
          if ( _V_stricmp(s1: v11, s2: pOldLevel) == 0 )
            flags = 0x80000000;
          for ( j = -1; ++j < SaveData->levelInfo.connectionCount; flags |= 1 << j )
          {
            mapName = SaveData->levelInfo.levelList[j].mapName;
            while ( _V_stricmp(s1: mapName, s2: sv.m_szMapname) != 0 )
            {
              ++j;
              mapName += 80;
              if ( j >= SaveData->levelInfo.connectionCount )
                goto LABEL_24;
            }
            if ( j < 0 )
            {
LABEL_24:
              v4 = v25;
              break;
            }
            v4 = v25;
          }
          if ( flags != 0 )
            movedCount = serverGameDLL->CreateEntityTransitionList(this: serverGameDLL, a2: SaveData, a3: flags);
          if ( movedCount != 0 )
          {
            V_FileBase(in, out: level, maxlen: 256);
            CSaveRestore::EntityPatchWrite(this: v4, pSaveData: SaveData, level: level, bAsync: false);
          }
          CSaveRestore::BuildRestoredIndexTranslationTable(this: v4, mapname: in, pSaveData: SaveData, verbose: true);
          a2 = SaveData;
          ((void (__thiscall *)(CSaveRestore *))v4->Finish)(a1: v4);
          levelList = (levellist_t *)in;
        }
      }
      ++levelList;
      ++i;
      in = (char *)levelList;
    }
    while ( i < currentLevelData.levelInfo.connectionCount );
  }
  g_ServerGlobalVariables.pSaveData = nullptr;
  if ( !foundprevious )
  {
    _Warning(
      a1: "\nLevel transition ERROR\nCan't find connection to %s from %s\nFalling back to 'map' command...\n\n",
      pOldLevel,
      sv.m_szMapname);
    m_szBuf = CFmtStrN<256>::CFmtStrN<256>(this: &v20, pszFormat: "disconnect; map %s\n", sv.m_szMapname)->m_szBuf;
    TraceType = CTraceFilter::GetTraceType(this: v14);
    Cbuf_AddText(eTarget: TraceType, pText: m_szBuf, nTickDelay: 0);
  }
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &currentLevelData.m_EntityToIndex);
  CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,int>>::RemoveAll(this: &currentLevelData.m_EntityToIndex.m_Buckets);
  m_pMemory = currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory;
  if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory = nullptr;
    }
    currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nAllocationCount = 0;
  }
  currentLevelData.m_EntityToIndex.m_Buckets.m_pElements = m_pMemory;
  if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10275890
// Name: public: virtual void CMemberFunctor6<class CSOAContainer __near *,void (CSOAContainer::*)(int,int,int,int,int,union __m128),int,int,int,int,int,union __m128,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor6<CSOAContainer *,void (__thiscall CSOAContainer::*)(int,int,int,int,int,__m128),int,int,int,int,int,__m128,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor6<CSOAContainer *,void (__thiscall CSOAContainer::*)(int,int,int,int,int,__m128),int,int,int,int,int,__m128,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(CSOAContainer *, int, int, int, int, int))this->m_Proxy.m_pfnProxied)(
    a1: this->m_Proxy.m_pObject,
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x10275900
// Name: private: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::ExecuteWrapper(int __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::ExecuteWrapper(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        int *nDummy)
{
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this);
}

//------------------------------------------------------------------------------
// Address: 0x10275A30
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::ParallelCallQueued(class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::ParallelCallQueued(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        IThreadPool *pPool)
{
  IThreadPool *v2; // esi
  volatile int m_value; // ebx
  volatile int v5; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> v6; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = pPool;
  if ( pPool == nullptr )
  {
    v2 = _g_pThreadPool;
    if ( _g_pThreadPool == nullptr )
      goto LABEL_11;
  }
  if ( this->m_queue.m_Count.m_value >= 1 )
    m_value = this->m_queue.m_Count.m_value;
  else
    m_value = 1;
  if ( v2->NumThreads(this: v2) >= m_value )
  {
    if ( this->m_queue.m_Count.m_value < 1 )
    {
LABEL_11:
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this);
      return;
    }
    v5 = this->m_queue.m_Count.m_value;
  }
  else
  {
    v5 = v2->NumThreads(this: v2);
  }
  if ( v5 < 2 )
    goto LABEL_11;
  v6.m_pItems.m_value = nullptr;
  v6.m_pLimit = nullptr;
  _InterlockedExchange((volatile __int32 *)&v6.m_pItems, 0);
  v6.m_ItemProcessor.m_pfnBegin = nullptr;
  v6.m_ItemProcessor.m_pfnEnd = nullptr;
  v6.m_ItemProcessor.m_pObject = this;
  v6.m_ItemProcessor.m_pfnProcess = CCallQueueT<CTSQueue<CFunctor *,0,1>>::ExecuteWrapper;
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
    this: &v6,
    pItems: nullptr,
    nItems: v5,
    nChunkSize: 1,
    nMaxParallel: 0x7FFFFFFF,
    pThreadPool: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102E9190
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderV7_1_t>(struct VTFFileHeaderV7_1_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderV7_1_t>()
{
  if ( (_S2_21 & 1) == 0 )
  {
    _S2_21 |= 1u;
    nameHolder_10.m_pszBase = "VTFFileHeaderV7_1_t";
    nameHolder_10.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_10.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_10.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_10.m_Names.m_Size = 0;
    nameHolder_10.m_Names.m_pElements = nullptr;
    nameHolder_10.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderV7_1_t::m_DataMap.baseMap = &VTFFileBaseHeader_t::m_DataMap;
  VTFFileHeaderV7_1_t::m_DataMap.dataNumFields = 12;
  VTFFileHeaderV7_1_t::m_DataMap.dataDesc = &dataDesc_10[1];
  return &VTFFileHeaderV7_1_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E9210
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderV7_2_t>(struct VTFFileHeaderV7_2_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderV7_2_t>()
{
  if ( (_S3_7 & 1) == 0 )
  {
    _S3_7 |= 1u;
    nameHolder_11.m_pszBase = "VTFFileHeaderV7_2_t";
    nameHolder_11.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_11.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_11.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_11.m_Names.m_Size = 0;
    nameHolder_11.m_Names.m_pElements = nullptr;
    nameHolder_11.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderV7_2_t::m_DataMap.baseMap = &VTFFileHeaderV7_1_t::m_DataMap;
  VTFFileHeaderV7_2_t::m_DataMap.dataNumFields = 1;
  VTFFileHeaderV7_2_t::m_DataMap.dataDesc = &dataDesc_11[1];
  return &VTFFileHeaderV7_2_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E9280
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderV7_3_t>(struct VTFFileHeaderV7_3_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderV7_3_t>()
{
  if ( (_S4_4 & 1) == 0 )
  {
    _S4_4 |= 1u;
    nameHolder_12.m_pszBase = "VTFFileHeaderV7_3_t";
    nameHolder_12.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_12.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_12.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_12.m_Names.m_Size = 0;
    nameHolder_12.m_Names.m_pElements = nullptr;
    nameHolder_12.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderV7_3_t::m_DataMap.baseMap = &VTFFileHeaderV7_2_t::m_DataMap;
  VTFFileHeaderV7_3_t::m_DataMap.dataNumFields = 1;
  VTFFileHeaderV7_3_t::m_DataMap.dataDesc = &dataDesc_12[1];
  return &VTFFileHeaderV7_3_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E92F0
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeader_t>(struct VTFFileHeader_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeader_t>()
{
  if ( (_S5_4 & 1) == 0 )
  {
    _S5_4 |= 1u;
    nameHolder_13.m_pszBase = "VTFFileHeader_t";
    nameHolder_13.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_13.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_13.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_13.m_Names.m_Size = 0;
    nameHolder_13.m_Names.m_pElements = nullptr;
    nameHolder_13.m_nLenBase = 15;
    atexit(func: DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeader_t::m_DataMap.baseMap = &VTFFileHeaderV7_2_t::m_DataMap;
  VTFFileHeader_t::m_DataMap.dataNumFields = 1;
  VTFFileHeader_t::m_DataMap.dataDesc = dataDesc_15;
  return &VTFFileHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E9360
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderX360_t>(struct VTFFileHeaderX360_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderX360_t>()
{
  if ( (_S6_3 & 1) == 0 )
  {
    _S6_3 |= 1u;
    nameHolder_14.m_pszBase = "VTFFileHeaderX360_t";
    nameHolder_14.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_14.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_14.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_14.m_Names.m_Size = 0;
    nameHolder_14.m_Names.m_pElements = nullptr;
    nameHolder_14.m_nLenBase = 19;
    atexit(func: DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderX360_t::m_DataMap.baseMap = &VTFFileBaseHeader_t::m_DataMap;
  VTFFileHeaderX360_t::m_DataMap.dataNumFields = 13;
  VTFFileHeaderX360_t::m_DataMap.dataDesc = &dataDesc_13[1];
  return &VTFFileHeaderX360_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E93E0
// Name: struct datamap_t __near * DataMapInit<struct VTFFileHeaderPS3_t>(struct VTFFileHeaderPS3_t __near *)
// Source: semantic_datamap_guess
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<VTFFileHeaderPS3_t>()
{
  if ( (_S7_3 & 1) == 0 )
  {
    _S7_3 |= 1u;
    nameHolder_15.m_pszBase = "VTFFileHeaderPS3_t";
    nameHolder_15.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_15.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_15.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_15.m_Names.m_Size = 0;
    nameHolder_15.m_Names.m_pElements = nullptr;
    nameHolder_15.m_nLenBase = 18;
    atexit(func: DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  VTFFileHeaderPS3_t::m_DataMap.baseMap = &VTFFileBaseHeader_t::m_DataMap;
  VTFFileHeaderPS3_t::m_DataMap.dataNumFields = 13;
  VTFFileHeaderPS3_t::m_DataMap.dataDesc = &dataDesc_14[1];
  return &VTFFileHeaderPS3_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1031BD40
// Name: GAME_HEADER_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *GAME_HEADER_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<GAME_HEADER>();
  GAME_HEADER_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BD50
// Name: SAVE_HEADER_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SAVE_HEADER_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SAVE_HEADER>();
  SAVE_HEADER_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BD60
// Name: levellist_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *levellist_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<levellist_t>();
  levellist_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BD70
// Name: SAVELIGHTSTYLE_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SAVELIGHTSTYLE_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SAVELIGHTSTYLE>();
  SAVELIGHTSTYLE_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BDB0
// Name: musicsave_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *musicsave_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<musicsave_t>();
  musicsave_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BDC0
// Name: channelsave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *channelsave_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<channelsave>();
  channelsave_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BDD0
// Name: decallist_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *decallist_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<decallist_t>();
  decallist_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10325E80
// Name: _GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__
// Source: semantic_dyn_global_var
//------------------------------------------------------------------------------
void __cdecl GetSaveMemory_::_2_::_dynamic_atexit_destructor_for__g_SaveMemory__()
{
  CMemoryStack::~CMemoryStack(this: &g_SaveMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10194250
// Name: class CFunctor __near * CreateFunctor<class CSaveRestore __near *,class CSaveRestore,void,char const __near *,char const __near *,bool,class CUtlEnvelope<char const __near *>,class CUtlEnvelope<char const __near *>,bool>(class CSaveRestore __near *,void (CSaveRestore::*)(char const __near *,char const __near *,bool),class CUtlEnvelope<char const __near *> const __near &,class CUtlEnvelope<char const __near *> const __near &,bool const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<CSaveRestore *,CSaveRestore,void,char const *,char const *,bool,CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool>(
        CSaveRestore *pObject,
        void (__thiscall *pfnProxied)(CSaveRestore *this, const char *, const char *, bool),
        const CUtlEnvelope<char const *> *arg1,
        const CUtlEnvelope<char const *> *arg2,
        const bool *arg3)
{
  char *v5; // esi

  v5 = (char *)MemAlloc_Alloc(nSize: 0x3Cu);
  if ( v5 == nullptr )
    return nullptr;
  *((_DWORD *)v5 + 3) = 1;
  *(_DWORD *)v5 = &CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  *((_DWORD *)v5 + 2) = &CMemberFunctor3<CSaveRestore *,void (__thiscall CSaveRestore::*)(char const *,char const *,bool),CUtlEnvelope<char const *>,CUtlEnvelope<char const *>,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  *((_DWORD *)v5 + 5) = pObject;
  *((_DWORD *)v5 + 4) = pfnProxied;
  CUtlString::CUtlString(this: (CUtlString *)(v5 + 24));
  CUtlString::operator=(this: (CUtlString *)(v5 + 24), src: &arg1->m_string);
  CUtlString::CUtlString(this: (CUtlString *)(v5 + 40));
  CUtlString::operator=(this: (CUtlString *)(v5 + 40), src: &arg2->m_string);
  v5[56] = *arg3;
  return (CFunctor *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10325E90
// Name: _DataMapInit_GAME_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_GAME_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x10325EA0
// Name: _DataMapInit_SAVE_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SAVE_HEADER__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x10325EB0
// Name: _DataMapInit_levellist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_levellist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_4);
}

//------------------------------------------------------------------------------
// Address: 0x10325EC0
// Name: _DataMapInit_SAVELIGHTSTYLE__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SAVELIGHTSTYLE__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_5);
}

//------------------------------------------------------------------------------
// Address: 0x10325ED0
// Name: _DataMapInit_musicsave_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_musicsave_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_6);
}

//------------------------------------------------------------------------------
// Address: 0x10325EE0
// Name: _DataMapInit_channelsave__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_channelsave__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_7);
}

//------------------------------------------------------------------------------
// Address: 0x10325EF0
// Name: _DataMapInit_decallist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_decallist_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_8);
}

//------------------------------------------------------------------------------
// Address: 0x10325F00
// Name: _dynamic_atexit_destructor_for__g_AsyncSaveCallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncSaveCallQueue__()
{
  CTSQueue<int,0,1>::Purge(this: (CTSQueue<int,0,1> *)&g_AsyncSaveCallQueue);
  free(pMem: g_AsyncSaveCallQueue.m_queue.m_Head.value.pNode);
  CTSListBase::Detach(this: &g_AsyncSaveCallQueue.m_queue.m_FreeNodes);
}

//------------------------------------------------------------------------------
// Address: 0x10325F30
// Name: _dynamic_atexit_destructor_for__g_SaveRestore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SaveRestore__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_SaveRestore.m_sDeferredCommands);
  CUtlDict<CSaveRestore::RestoreLookupTable,int>::RemoveAll(this: &g_SaveRestore.m_RestoreLookup);
  CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int,CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>>(this: &g_SaveRestore.m_RestoreLookup.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10325F50
// Name: _dynamic_atexit_destructor_for__in_forceuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__in_forceuser__()
{
  ConVar::~ConVar(this: &in_forceuser);
}

//------------------------------------------------------------------------------
// Address: 0x10325F60
// Name: _dynamic_atexit_destructor_for__unbind_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__unbind_command__()
{
  ConCommand::~ConCommand(this: &unbind_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325F70
// Name: _dynamic_atexit_destructor_for__unbindall_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__unbindall_command__()
{
  ConCommand::~ConCommand(this: &unbindall_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325F80
// Name: _dynamic_atexit_destructor_for__escape_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__escape_command__()
{
  ConCommand::~ConCommand(this: &escape_command);
}

} // namespace engine_xlsp
