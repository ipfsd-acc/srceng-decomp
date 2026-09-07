// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/ime/gasime.cpp
// Functions: 7
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\ime\gasime.h"

//------------------------------------------------------------------------------
// Address: 0x1012DCC0
// Name: private: static void GASImeCtorFunction::GetConversionMode(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASImeCtorFunction::GetConversionMode(
        const GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *fn,
        _CONNECTDLGSTRUCTW fna)
{
  unsigned int cbStructure; // esi
  GASEnvironment *v3; // ecx
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v5; // edi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v6; // eax
  int v7; // esi
  unsigned int v8; // eax

  cbStructure = fna.cbStructure;
  v3 = *(GASEnvironment **)(fna.cbStructure + 24);
  if ( v3 != nullptr )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: v3);
    v5 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                         a1: (int)MovieRoot + 8,
                         a2: 27);
    fna.cbStructure = (unsigned int)GASStringManager::CreateConstStringNode(
                                      this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 636),
                                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029EE3C,
                                      a3: 7u,
                                      a4: 0);
    ++*(_DWORD *)(fna.cbStructure + 8);
    if ( v5 != nullptr )
    {
      v6 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v5->GetSceneFogMode(this: v5);
      GASString::operator=(this: (int *)&fna, result: v6);
    }
    v7 = *(_DWORD *)(cbStructure + 4);
    if ( *(_BYTE *)v7 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v7, a2: (int)v5);
    *(_BYTE *)v7 = 5;
    *(_DWORD *)(v7 + 4) = fna.cbStructure;
    ++*(_DWORD *)(fna.cbStructure + 8);
    v8 = fna.cbStructure;
    if ( (*(_DWORD *)(fna.cbStructure + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: v8);
    if ( v5 != nullptr )
      GRefCountImpl::Release(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DD60
// Name: private: static void GASImeCtorFunction::SetCompositionString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASImeCtorFunction::SetCompositionString(
        const GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *fn,
        _CONNECTDLGSTRUCTW fna)
{
  unsigned int cbStructure; // edi
  GASEnvironment *v3; // ecx
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v5; // esi
  char v6; // bl
  tagRID_DEVICE_INFO_KEYBOARD *v7; // ebx
  unsigned __int8 *v8; // eax
  unsigned int v9; // eax
  int v11; // edi

  cbStructure = fna.cbStructure;
  v3 = *(GASEnvironment **)(fna.cbStructure + 24);
  if ( v3 != nullptr )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: v3);
    v5 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                         a1: (int)MovieRoot + 8,
                         a2: 27);
    v6 = 0;
    if ( v5 != nullptr )
    {
      v7 = *(tagRID_DEVICE_INFO_KEYBOARD **)(cbStructure + 24);
      v8 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
      GASValue::ToStringImpl(this: v8, a2: (int *)&fna, a3: v7, precision: -1, debug: false);
      v6 = ((int (__thiscall *)(IShaderAPI *, _DWORD))v5->GetCurrentRenderTargetDimensions)(
             a1: v5,
             a2: *(_DWORD *)fna.cbStructure);
      v9 = fna.cbStructure;
      if ( (*(_DWORD *)(fna.cbStructure + 8))-- == 1 )
        GASStringNode::ReleaseNode(a1: v9);
    }
    v11 = *(_DWORD *)(cbStructure + 4);
    GASValue::DropRefs(this: (GASValue *)v11, a2: v11);
    *(_BYTE *)v11 = 2;
    *(_BYTE *)(v11 + 4) = v6;
    if ( v5 != nullptr )
      GRefCountImpl::Release(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DDF0
// Name: private: static void GASImeCtorFunction::SetConversionMode(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASImeCtorFunction::SetConversionMode(long double a1@<st0>, int result)
{
  GASEnvironment *v4; // ecx
  struct GFxMovieRoot *MovieRoot; // eax
  int *v6; // eax
  IShaderAPI *v7; // esi
  int v8; // edi
  GASValue *v9; // eax
  int v10; // edi
  _SERVICE_STATUS *v11; // [esp-Ch] [ebp-18h]
  __int64 v12; // [esp+4h] [ebp-8h]
  char result_3; // [esp+17h] [ebp+Bh]

  v4 = *(GASEnvironment **)(result + 24);
  if ( v4 != nullptr )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: v4);
    v6 = (int *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(a1: (int)MovieRoot + 8, a2: 27);
    v7 = (IShaderAPI *)v6;
    result_3 = 0;
    if ( v6 != nullptr )
    {
      v8 = *v6;
      v11 = *(_SERVICE_STATUS **)(result + 24);
      v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)result, a2: 0);
      v12 = (__int64)GASValue::ToNumber(this: v9, a2: v8, a3: a1, result: v11);
      result_3 = (*(int (__thiscall **)(IShaderAPI *, _DWORD))(v8 + 4))(a1: v7, a2: v12);
    }
    v10 = *(_DWORD *)(result + 4);
    GASValue::DropRefs(this: (GASValue *)v10, a2: v10);
    *(_BYTE *)v10 = 2;
    *(_BYTE *)(v10 + 4) = result_3;
    if ( v7 != nullptr )
      GRefCountImpl::Release(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DE80
// Name: private: static void GASImeCtorFunction::SetEnabled(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASImeCtorFunction::SetEnabled(long double a1@<st0>, int result)
{
  GASEnvironment *v4; // ecx
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v6; // eax
  IShaderAPI *v7; // esi
  IShaderAPI v8; // edi
  char *v9; // eax
  unsigned __int8 v10; // al
  int v11; // edi
  tagPOLYTEXTW *v12; // [esp-Ch] [ebp-10h]
  char result_3; // [esp+Fh] [ebp+Bh]

  v4 = *(GASEnvironment **)(result + 24);
  if ( v4 != nullptr )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: v4);
    v6 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                         a1: (int)MovieRoot + 8,
                         a2: 27);
    v7 = v6;
    result_3 = 0;
    if ( v6 != nullptr )
    {
      v8.__vftable = v6->__vftable;
      v12 = *(tagPOLYTEXTW **)(result + 24);
      v9 = (char *)GASFnCall::Arg(this: (GASFnCall *)result, a2: 0);
      v10 = GASValue::ToBool(a1: v9, a2: a1, result: v12);
      result_3 = ((int (__thiscall *)(IShaderAPI *, _DWORD))v8.GetSceneFogColor)(a1: v7, a2: v10);
    }
    v11 = *(_DWORD *)(result + 4);
    GASValue::DropRefs(this: (GASValue *)v11, a2: v11);
    *(_BYTE *)v11 = 2;
    *(_BYTE *)(v11 + 4) = result_3;
    if ( v7 != nullptr )
      GRefCountImpl::Release(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DF00
// Name: private: static void GASImeCtorFunction::GetEnabled(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASImeCtorFunction::GetEnabled(const GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *fn, int fna)
{
  GASEnvironment *v2; // ecx
  struct GFxMovieRoot *MovieRoot; // eax
  int v4; // eax
  IShaderAPI *v5; // esi
  char v6; // al
  int v7; // edi
  char v8; // bl

  v2 = *(GASEnvironment **)(fna + 24);
  if ( v2 != nullptr )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: v2);
    v4 = (*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(a1: (int)MovieRoot + 8, a2: 27);
    v5 = (IShaderAPI *)v4;
    if ( v4 != 0 )
    {
      v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 16))(a1: v4);
      v7 = *(_DWORD *)(fna + 4);
      v8 = v6;
      GASValue::DropRefs(this: (GASValue *)v7, a2: v7);
      *(_BYTE *)(v7 + 4) = v8;
      *(_BYTE *)v7 = 2;
      GRefCountImpl::Release(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DF60
// Name: public: GASImeCtorFunction::GASImeCtorFunction(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *__thiscall GASImeCtorFunction::GASImeCtorFunction(
        GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *this,
        _REASON_CONTEXT *psc)
{
  HWND__ *v2; // edi
  char *v4; // esi
  void *v5; // ecx
  int v6; // eax
  const struct GASNameNumber *const *v7; // ecx
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v8; // edx
  int v9; // ecx
  GASStringManager *v10; // ecx
  int v11; // eax
  tagMSG v14; // [esp-8h] [ebp-34h] BYREF
  GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *v15; // [esp+1Ch] [ebp-10h]
  char *v16; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  struct GASStringNode *ConstStringNode; // [esp+28h] [ebp-4h] BYREF

  v2 = (HWND__ *)psc;
  v15 = this;
  GASCFunctionObject::GASCFunctionObject(
    (GASCFunctionObject *)this,
    func: psc,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASObjectProto::GlobalCtor);
  v4 = (char *)this + 16;
  v14.message = (unsigned int)this + 16;
  v14.hwnd = v2;
  this->Data.Data = (GPtr<GFxAmpMemItem> *)&GASImeCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
  GASAsBroadcaster::Initialize(pobj: v14);
  GASNameFunction::AddConstMembers(
    pobj: v5,
    psc: (int)this + 16,
    psca: (CTSQueue<CFunctor *,0,1>::Node_t *)v2,
    a4: (struct GASObject **)&GASImeCtorFunction::StaticFunctionTable,
    a5: 7);
  v6 = 0;
  i = 0;
  if ( "ALPHANUMERIC_FULL" == nullptr )
    return this;
  v7 = &GASImeCtorFunction::GASNumberConstTable;
  do
  {
    v8 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)*v7;
    v9 = *(_DWORD *)v2;
    v14.pt.y = dword_102A778C[v6];
    HIBYTE(psc) = 7;
    LOBYTE(v14.pt.x) = 4;
    v10 = *(GASStringManager **)(v9 + 636);
    v16 = (char *)&v8->m_Memory.m_pMemory + 1;
    ConstStringNode = GASStringManager::CreateConstStringNode(
                        this: v10,
                        result: v8,
                        a3: strlen((const char *)v8),
                        a4: 0);
    ++*((_DWORD *)ConstStringNode + 2);
    (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v4 + 40))(
      a1: v4,
      a2: v2,
      a3: &ConstStringNode,
      a4: &v14.pt,
      a5: (char *)&psc + 3);
    v11 = (int)ConstStringNode;
    if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
      GASStringNode::ReleaseNode(a1: v11);
    GASValue::~GASValue(this: (GASValue *)&v14.pt, a2: (int)v2);
    ++i;
    v6 = 2 * i;
    v7 = &GASImeCtorFunction::GASNumberConstTable + 2 * i;
  }
  while ( *v7 != nullptr );
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x1012E060
// Name: public: static class GASFunctionRef GASImeCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GASImeCtorFunction::Register(int constructor, int a2)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  GFxAmpMemItem *v3; // ecx
  void (__thiscall *dtr_GRefCountImplCore)(struct GFxAmpMemItem *); // eax
  GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *v5; // eax
  GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *v6; // eax
  unsigned int v7; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v9)(const char *, int, int *); // edx
  int v10; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  const char *MinVal; // edx
  GASValue *v13; // eax
  float v15; // [esp+0h] [ebp-28h]
  GASValue v16[4]; // [esp+Ch] [ebp-1Ch] BYREF
  GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> psc; // [esp+1Ch] [ebp-Ch] BYREF

  v2 = (vc_attributes::PreRangeAttribute *)a2;
  v3 = *(GFxAmpMemItem **)(a2 + 656);
  psc.Data.Data = (GPtr<GFxAmpMemItem> *)a2;
  LOBYTE(psc.Data.Size) = 8;
  dtr_GRefCountImplCore = v3->__vftable[10].dtr_GRefCountImplCore;
  a2 = 323;
  v5 = (GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *)((int (__thiscall *)(GFxAmpMemItem *, int, int *))dtr_GRefCountImplCore)(
                                                                a1: v3,
                                                                a2: 56,
                                                                a3: &a2);
  if ( v5 != nullptr )
    v6 = GASImeCtorFunction::GASImeCtorFunction(this: v5, (_REASON_CONTEXT *)&psc);
  else
    v6 = nullptr;
  v7 = constructor;
  *(_DWORD *)constructor = v6;
  *(_BYTE *)(v7 + 8) = 0;
  *(_DWORD *)(v7 + 4) = 0;
  MaxVal = v2[54].MaxVal;
  v9 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)MaxVal + 40);
  constructor = 323;
  v10 = v9(a1: MaxVal, a2: 84, a3: &constructor);
  if ( v10 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASIme,GASEnvironment>::GASPrototype<GASIme,GASEnvironment>(
      this: (D3DXCOLOR *)v10,
      (struct GASStringContext *)&psc,
      pprototype: Prototype,
      constructor: v7,
      psc_12: v15);
    *(_DWORD *)v10 = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v10 + 16) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v10 + 52) = &GASPrototype<GASObject,GASEnvironment>::`vftable';
    HIBYTE(a2) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v10 + 52),
      a2: v10,
      flags: (vc_attributes::PreRangeAttribute **)&psc,
      flags_4: (const struct GASNameFunction *)&GAS_ImeFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&a2 + 3));
  }
  else
  {
    v10 = 0;
  }
  if ( v10 != 0 )
    *(_DWORD *)(v10 + 8) = (*(_DWORD *)(v10 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 22, a4: v10);
  MinVal = v2[55].MinVal;
  HIBYTE(a2) = 0;
  psc.Data.Policy.Capacity = *((_DWORD *)MinVal + 4);
  v13 = GASValue::GASValue(this: v16, a2: (int)v2, a3: (const struct GASFunctionRef *)v7);
  (*(void (__thiscall **)(const char *, GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *, vc_attributes::PreRangeAttribute *, GASValue *, char *))(psc.Data.Policy.Capacity + 40))(
    a1: v2[55].MinVal + 16,
    a2: &psc,
    a3: v2 + 8,
    a4: v13,
    a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v16, a2: (int)v2);
  if ( v10 != 0 )
    GRefCountBaseGC<323>::Release(a1: v10, a2: (int)v2);
  return v7;
}
