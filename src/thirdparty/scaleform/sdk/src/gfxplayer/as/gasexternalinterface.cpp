// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasexternalinterface.cpp
// Functions: 7
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasexternalinterface.h"

//------------------------------------------------------------------------------
// Address: 0x1012E190
// Name: public: virtual enum GASObjectInterface::ObjectType GASExternalInterface::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASExternalInterface::GetObjectType()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1012E260
// Name: public: virtual bool GASExternalInterfaceCtorFunction::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __userpurge GASExternalInterfaceCtorFunction::GetMember@<al>(
        D3DXQUATERNION *a1@<ecx>,
        ID3D11DeviceChild *this,
        _IMAGE_SYMBOL_EX *penv,
        GASValue *name,
        const void *val)
{
  bool v5; // bl
  int *ConstStringNode; // eax
  int v7; // esi
  _IMAGE_SYMBOL_EX *v8; // ebx
  bool v9; // zf
  int v10; // edi
  bool name_3; // [esp+1Fh] [ebp+Fh]

  v5 = *((_BYTE *)this + 124) > 6u;
  ConstStringNode = (int *)GASStringManager::CreateConstStringNode(
                             this: *(GASStringManager **)(*((_DWORD *)this + 30) + 636),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7884,
                             a3: 9u,
                             a4: 0);
  v7 = (int)ConstStringNode;
  ++ConstStringNode[2];
  if ( v5 )
  {
    v8 = penv;
    v9 = ConstStringNode == (int *)penv->N.Name.Short;
  }
  else
  {
    if ( ConstStringNode[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: ConstStringNode);
    v8 = penv;
    if ( *(_DWORD *)(penv->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)penv->N.Name.Short);
    v9 = *(_DWORD *)(v7 + 4) == *(_DWORD *)(penv->N.Name.Short + 4);
  }
  name_3 = v9;
  v9 = (*(_DWORD *)(v7 + 8))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v7);
  if ( !name_3 )
    return (unsigned __int8)GASObject::GetMember(this: a1, result: (ID3DXFont *)this, penv: v8, val: (int *)name);
  v10 = *((_DWORD *)GASEnvironment::GetMovieRoot((GASEnvironment *)this) + 65);
  GASValue::DropRefs(this: name, a2: v10);
  *((_BYTE *)name + 4) = v10 != 0;
  *(_BYTE *)name = 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012E350
// Name: public: GASExternalInterfaceCtorFunction::GASExternalInterfaceCtorFunction(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
ID3D11DeviceChild *__stdcall GASExternalInterfaceCtorFunction::GASExternalInterfaceCtorFunction(
        ID3D11DeviceChild *this,
        const _GUID *psc,
        unsigned int *psc_8,
        void *psc_12)
{
  GASCFunctionObject *v4; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *v5; // ebx
  ID3D11DeviceChild *v6; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // eax
  int v8; // eax
  void *v10; // ecx
  GASValue v12[4]; // [esp+Ch] [ebp-14h] BYREF
  struct GASStringNode *ConstStringNode; // [esp+1Ch] [ebp-4h] BYREF

  v5 = (CTSQueue<CFunctor *,0,1>::Node_t *)this;
  v6 = (ID3D11DeviceChild *)v4;
  GASCFunctionObject::GASCFunctionObject(
    this: v4,
    func: (_REASON_CONTEXT *)this,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASSoundProto::GetTransform);
  v6->__vftable = (ID3D11DeviceChild_vtbl *)&GASExternalInterfaceCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  v6[4].__vftable = (ID3D11DeviceChild_vtbl *)&stru_102A7884.m_Size;
  pNext = v5->pNext;
  LOBYTE(v12[0]) = 10;
  HIBYTE(this) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: (GASStringManager *)pNext[79].elem,
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7884,
                      a3: 9u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  ((void (__thiscall *)(ID3D11DeviceChild *, CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringNode **, GASValue *, char *))v6[4].__vftable[1].GetDevice)(
    a1: &v6[4],
    a2: v5,
    a3: &ConstStringNode,
    a4: v12,
    a5: (char *)&this + 3);
  v8 = (int)ConstStringNode;
  if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
    GASStringNode::ReleaseNode(a1: v8);
  GASValue::~GASValue(this: v12, a2: (int)&v6[4]);
  GASNameFunction::AddConstMembers(
    pobj: v10,
    psc: (int)&v6[4],
    psca: v5,
    a4: (struct GASObject **)&GASExternalInterfaceCtorFunction::StaticFunctionTable,
    a5: 7);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1012E3F0
// Name: public: static void GASExternalInterfaceCtorFunction::Call(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASExternalInterfaceCtorFunction::Call(int a1@<edi>, GASFnCall *result)
{
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *MovieRoot; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Iterator_t *v4; // ecx
  unsigned int v5; // ebx
  GFxAmpViewStats *pContainer; // ecx
  void *v7; // ecx
  __int64 v8; // rax
  _DWORD *v9; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v10; // ebx
  unsigned __int8 *v11; // eax
  int v12; // eax
  bool v13; // zf
  int v14; // ebx
  int v15; // eax
  IUnknown_vtbl *v16; // eax
  char *v17; // eax
  tagWNDCLASSW *v18; // eax
  char *v19; // edi
  tagWNDCLASSW *v20; // eax
  int v21; // ecx
  void *v22; // ecx
  StringPoolCase_t v23; // esi
  int v24; // esi
  __int64 v25; // rax
  IUnknown_vtbl *v26; // esi
  char v27; // [esp+0h] [ebp-D4h]
  char v28; // [esp+8h] [ebp-CCh] BYREF
  __int64 v29; // [esp+A8h] [ebp-2Ch]
  GFxAmpViewStats *v30; // [esp+B0h] [ebp-24h]
  int v31; // [esp+C0h] [ebp-14h] BYREF
  int v32; // [esp+C4h] [ebp-10h] BYREF
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *v33; // [esp+C8h] [ebp-Ch]
  _DWORD *v34; // [esp+CCh] [ebp-8h]
  tagWNDCLASSW *v; // [esp+D0h] [ebp-4h]
  char *fn; // [esp+DCh] [ebp+8h]

  MovieRoot = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result[6]);
  v5 = 0;
  v33 = MovieRoot;
  if ( MovieRoot[32].pContainer == nullptr )
  {
    GFxLogBase<GASFnCall>::LogScriptWarning(
      this: v4,
      pfmt: result,
      a3: (int)"Warning: ExternalInterface.call - handler is not installed.\n",
      a4: v27);
    v26 = (IUnknown_vtbl *)result[1];
    GASValue::DropRefs(this: (GASValue *)v26, a2: a1);
    LOBYTE(v26->QueryInterface) = 0;
    return;
  }
  pContainer = (GFxAmpViewStats *)MovieRoot[1288].pContainer;
  v30 = pContainer;
  if ( pContainer != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: pContainer, swdHandle: 1u, swfOffset: 0x22u);
    GTimer::GetRawTicks(li: v7);
    v29 = v8;
  }
  else
  {
    v29 = 0;
  }
  v9 = *(_DWORD **)(result[6][3].cbSize + 8);
  ++v9[2];
  v34 = v9;
  if ( (int)result[7] < 1 )
    goto LABEL_13;
  v10 = (tagRID_DEVICE_INFO_KEYBOARD *)result[6];
  v11 = (unsigned __int8 *)GASFnCall::Arg(this: result, a2: 0);
  GASValue::ToStringImpl(this: v11, a2: &v32, a3: v10, precision: -1, debug: false);
  v12 = v32;
  ++*(_DWORD *)(v32 + 8);
  v13 = v9[2]-- == 1;
  v14 = v12;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: (int)v9);
  v15 = v32;
  v13 = (*(_DWORD *)(v32 + 8))-- == 1;
  v34 = (_DWORD *)v14;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v15);
  v5 = (unsigned int)&result[7][-1].ptStart.y + 3;
  if ( v5 <= 0xA )
  {
    v9 = v34;
LABEL_13:
    v17 = &v28;
    goto LABEL_14;
  }
  v16 = (IUnknown_vtbl *)result[6];
  v31 = 323;
  v17 = (char *)(*(int (__thiscall **)(_DWORD, unsigned int, int *))(**((_DWORD **)v16[10].QueryInterface + 164) + 40))(
                  a1: *((_DWORD *)v16[10].QueryInterface + 164),
                  a2: 16 * v5,
                  a3: &v31);
  v9 = v34;
LABEL_14:
  fn = v17;
  v18 = nullptr;
  if ( v5 != 0 )
  {
    v19 = fn;
    do
    {
      v = (tagWNDCLASSW *)((char *)&v18->style + 1);
      v20 = (tagWNDCLASSW *)GASFnCall::Arg(this: result, a2: (int)&v18->style + 1);
      v21 = 0;
      if ( v19 != nullptr )
      {
        *(_DWORD *)v19 = 0;
        *((_DWORD *)v19 + 1) = 0;
        v21 = (int)v19;
      }
      GFxMovieRoot::ASValue2GFxValue(this: v33, result: (tagPOLYTEXTW *)result[6], value: v20, toType: v21);
      v18 = v;
      v19 += 16;
    }
    while ( (unsigned int)v < v5 );
    v9 = v34;
  }
  v = (tagWNDCLASSW *)&v33[1145].pContainer;
  GASValue::DropRefs(this: (GASValue *)&v33[1145].pContainer, a2: (int)v9);
  LOBYTE(v->style) = 0;
  if ( v9[4] != 0 )
    v34 = (_DWORD *)*v9;
  else
    v34 = nullptr;
  (*(void (__thiscall **)(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *, GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *, _DWORD *, char *, unsigned int))(v33[32].pContainer->Data[0] + 4))(
    a1: v33[32].pContainer,
    a2: v33,
    a3: v34,
    a4: fn,
    a5: v5);
  GASValue::operator=(this: (int)result[1], v);
  if ( v5 != 0 )
  {
    v23 = (StringPoolCase_t)fn;
    for ( v = (tagWNDCLASSW *)v5; v != nullptr; v = (tagWNDCLASSW *)((char *)v - 1) )
    {
      v22 = (void *)(*(_DWORD *)(v23 + 4) >> 6);
      if ( (*(_DWORD *)(v23 + 4) & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(
          this: *(CStringPool **)v23,
          a2: (int)v9,
          val: v23,
          pobj: *(IShaderAPI **)(v23 + 8));
        *(_DWORD *)v23 = 0;
      }
      v23 += 16;
    }
  }
  if ( v5 > 0x28 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: fn);
  v13 = v9[2]-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: (int)v9);
  v24 = (int)v30;
  if ( v30 != nullptr )
  {
    GTimer::GetRawTicks(li: v22);
    GFxAmpViewStats::PopCallstack(this: v24, result: (GImageInfo *)1, swfOffset: 0x22u, funcTime: v25 - v29);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E720
// Name: public: static void GASExternalInterfaceCtorFunction::AddCallback(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASExternalInterfaceCtorFunction::AddCallback(int a1@<ebx>, GASFnCall *result)
{
  IUnknown_vtbl *v2; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v4; // edi
  unsigned __int8 *v5; // eax
  struct GASValue *v6; // eax
  GMemoryHeap *v7; // edi
  GASValue *v8; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v9; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v10; // ebx
  GMemoryHeap *v11; // eax
  int v12; // ebx
  GASValue *v13; // eax
  struct GASObject *v14; // eax
  IUnknown_vtbl *v15; // esi
  unsigned int v16; // eax
  IUnknown_vtbl *v18; // [esp-8h] [ebp-24h]
  IUnknown_vtbl *v19; // [esp-8h] [ebp-24h]
  IUnknown_vtbl *v20; // [esp-8h] [ebp-24h]
  char func[4]; // [esp+8h] [ebp-14h] BYREF
  int v23; // [esp+Ch] [ebp-10h]
  char v24; // [esp+10h] [ebp-Ch]
  struct GFxMovieRoot *v25; // [esp+14h] [ebp-8h]
  unsigned int alias; // [esp+18h] [ebp-4h] BYREF

  v2 = (IUnknown_vtbl *)result[1];
  GASValue::DropRefs(this: (GASValue *)v2, a2: (int)v2);
  LOBYTE(v2->QueryInterface) = 0;
  if ( (int)result[7] >= 3 )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result[6]);
    v4 = (tagRID_DEVICE_INFO_KEYBOARD *)result[6];
    v25 = MovieRoot;
    v5 = (unsigned __int8 *)GASFnCall::Arg(this: result, a2: 0);
    GASValue::ToStringImpl(this: v5, a2: (int *)&alias, a3: v4, precision: -1, debug: false);
    v18 = (IUnknown_vtbl *)result[6];
    v6 = GASFnCall::Arg(this: result, a2: 2);
    GASValue::ToFunction(a1: (int)v6, a2: (int)v4, a3: (int)func, a4: (int)v18);
    v7 = nullptr;
    if ( *(_BYTE *)GASFnCall::Arg(this: result, a2: 1) == 7 )
    {
      v19 = (IUnknown_vtbl *)result[6];
      v8 = (GASValue *)GASFnCall::Arg(this: result, a2: 1);
      GASValue::ToASCharacter(this: v8, penv: (const struct GASEnvironment *)v19);
      v10 = v9;
      if ( v9 != nullptr )
      {
        ++DWORD1(v9->m_pfnProxied);
        v11 = (GMemoryHeap *)DWORD1(v9[6].m_pfnProxied);
        if ( v11 != nullptr || (GFxASCharacter::CreateCharacterHandle(this: v10), v11 != nullptr) )
          ++v11->__vftable;
        v7 = v11;
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v10);
        v12 = 0;
      }
      else
      {
        v12 = 0;
      }
    }
    else
    {
      v20 = (IUnknown_vtbl *)result[6];
      v13 = (GASValue *)GASFnCall::Arg(this: result, a2: 1);
      v14 = GASValue::ToObject(this: v13, a2: 0, a3: (const struct GASEnvironment *)v20);
      if ( v14 != nullptr )
        v14[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v14[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v12 = (int)v14;
    }
    GFxMovieRoot::AddInvokeAlias(a1: (int)v25, (_IMAGE_SYMBOL_EX *)&alias, pthisChar: v7, pthisObj: v12, func, a6: a1);
    v15 = (IUnknown_vtbl *)result[1];
    GASValue::DropRefs(this: (GASValue *)v15, a2: (int)v7);
    LOBYTE(v15->QueryInterface) = 2;
    LOBYTE(v15->AddRef) = 1;
    if ( v12 != 0 )
      GRefCountBaseGC<323>::Release(a1: v12, a2: (int)v7);
    if ( v7 != nullptr && (int)--v7->__vftable <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: (GFxCharacterHandle *)v7);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
    }
    if ( (v24 & 2) == 0 && *(_DWORD *)func != 0 )
      GRefCountBaseGC<323>::Release(a1: *(int *)func, a2: (int)v7);
    *(_DWORD *)func = 0;
    if ( (v24 & 1) == 0 && v23 != 0 )
      GRefCountBaseGC<323>::Release(a1: v23, a2: (int)v7);
    v16 = alias;
    v23 = 0;
    if ( (*(_DWORD *)(alias + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E8A0
// Name: public: virtual class GASObject __near * GASExternalInterfaceCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASObject *__stdcall GASExternalInterfaceCtorFunction::CreateNewObject(
        ID3D11DeviceChild *this,
        const _GUID *penv,
        const IUnknown *a3)
{
  ID3D11DeviceChild *v3; // ebx
  int v4; // ecx
  int (__thiscall *v5)(int, int, ID3D11DeviceChild **); // edx
  vc_attributes::PreRangeAttribute **v6; // edi
  GASObject *v7; // eax
  GASObject *v8; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  v3 = this;
  v4 = *(_DWORD *)(*((_DWORD *)this + 30) + 656);
  v5 = *(int (__thiscall **)(int, int, ID3D11DeviceChild **))(*(_DWORD *)v4 + 40);
  v6 = (vc_attributes::PreRangeAttribute **)(this + 30);
  this = (ID3D11DeviceChild *)323;
  v7 = (GASObject *)v5(a1: v4, a2: 52, a3: &this);
  v8 = v7;
  if ( v7 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v7, a2: (struct GASEnvironment *)v3);
  v8->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v8[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASObjectInterface'};
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *v6,
                                                    result: (vc_attributes::InvalidCheckAttribute *)0x1C);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v8[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v6,
    psc_4: Prototype);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1012E980
// Name: public: static class GASFunctionRef GASExternalInterfaceCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASExternalInterfaceCtorFunction::Register(
        struct GASFunctionRef *a1,
        _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  ID3D11DeviceChild *v5; // eax
  struct GASFunctionRef *v6; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v8)(const char *, int, struct GASFunctionRef **); // edx
  int v9; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  const char *v11; // edx
  GASValue *v12; // eax
  const _GUID *v14; // [esp+0h] [ebp-28h]
  unsigned int *v15; // [esp+4h] [ebp-24h]
  void *v16; // [esp+8h] [ebp-20h]
  GASValue v17[4]; // [esp+Ch] [ebp-1Ch] BYREF
  ID3D11DeviceChild v18; // [esp+1Ch] [ebp-Ch] BYREF
  char v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v18.__vftable = (ID3D11DeviceChild_vtbl *)pgc;
  v19 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  if ( v4(a1: VersionMajor, a2: 56, a3: &pgc) != 0 )
    v5 = GASExternalInterfaceCtorFunction::GASExternalInterfaceCtorFunction(
           this: &v18,
           psc: v14,
           psc_8: v15,
           psc_12: v16);
  else
    v5 = nullptr;
  v6 = a1;
  *(_DWORD *)a1 = v5;
  *((_BYTE *)v6 + 8) = 0;
  *((_DWORD *)v6 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v8 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a1 = (struct GASFunctionRef *)323;
  v9 = v8(a1: MaxVal, a2: 84, a3: &a1);
  if ( v9 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASStageObject,GASEnvironment>::GASPrototype<GASStageObject,GASEnvironment>(
      this: (vgui::IHTMLEvents *)v9,
      psc: (vgui::IHTMLEvents *)&v18,
      psc_4: Prototype,
      psc_8: (unsigned int)v6);
    *(_DWORD *)v9 = &GASPrototype<GASStageObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v9 + 16) = &GASPrototype<GASStageObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v9 + 52) = &GASPrototype<GASStageObject,GASEnvironment>::`vftable';
    HIBYTE(pgc) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v9 + 52),
      a2: v9,
      flags: (vc_attributes::PreRangeAttribute **)&v18,
      flags_4: (const struct GASNameFunction *)&GFx_EIFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgc + 3));
  }
  else
  {
    v9 = 0;
  }
  if ( v9 != 0 )
    *(_DWORD *)(v9 + 8) = (*(_DWORD *)(v9 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 28, a4: v9);
  v11 = v2[55].MaxVal;
  HIBYTE(pgc) = 0;
  v20 = *((_DWORD *)v11 + 4);
  v12 = GASValue::GASValue(this: v17, a2: (int)v2, a3: v6);
  (*(void (__thiscall **)(const char *, ID3D11DeviceChild *, vc_attributes::PreRangeAttribute *, GASValue *, char *))(v20 + 40))(
    a1: v2[55].MaxVal + 16,
    a2: &v18,
    a3: v2 + 10,
    a4: v12,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v17, a2: (int)v2);
  if ( v9 != 0 )
    GRefCountBaseGC<323>::Release(a1: v9, a2: (int)v2);
  return v6;
}
