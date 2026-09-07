// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasblurfilter.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasblurfilter.h"

//------------------------------------------------------------------------------
// Address: 0x10131F20
// Name: public: virtual enum GASObjectInterface::ObjectType GASBlurFilterObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASBlurFilterObject::GetObjectType()
{
  return 40;
}

//------------------------------------------------------------------------------
// Address: 0x10131F30
// Name: public: virtual bool GASBlurFilterObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASBlurFilterObject::SetMember(
        GASBlurFilterObject *this@<ecx>,
        long double a2@<st0>,
        _SERVICE_STATUS *a3,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *val,
        const struct GASPropFlags *flags)
{
  if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
  {
    *((float *)this + 12) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: a3);
  }
  else if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_1029E0D4) == 0 )
  {
    *((float *)this + 13) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: a3);
  }
  else if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_102A7C40.m_Size) == 0 )
  {
    *((_DWORD *)this + 14) = (__int16)(int)GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: a3);
  }
  else
  {
    GASObject::SetMember(
      (CTSQueue<CFunctor *,0,1> *)this,
      a2: (GASEnvironment *)a3,
      name,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
      pmember: (char *)flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132040
// Name: public: virtual bool GASBlurFilterObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASBlurFilterObject::GetMember(
        int this,
        GFxAmpServer::SourceFileInfo *result,
        const char ***name,
        GASValue *a4)
{
  double v4; // st7
  int v6; // edi
  float namea; // [esp+18h] [ebp+Ch]

  if ( strcmp(**name, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
  {
    v4 = *(float *)(this + 48);
LABEL_3:
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: (int)name);
    namea = v4;
    *(double *)(a4 + 1) = namea;
    *(_BYTE *)a4 = 3;
    return 1;
  }
  if ( strcmp(**name, (const char *)&stru_1029E0D4) == 0 )
  {
    v4 = *(float *)(this + 52);
    goto LABEL_3;
  }
  if ( strcmp(**name, (const char *)&stru_102A7C40.m_Size) != 0 )
    return (unsigned __int8)GASObject::GetMember(
                              (D3DXQUATERNION *)this,
                              (ID3DXFont *)result,
                              penv: (_IMAGE_SYMBOL_EX *)name,
                              val: (int *)a4);
  v6 = *(_DWORD *)(this + 56);
  if ( *(_BYTE *)a4 >= 5u )
    GASValue::DropRefs(this: a4, a2: v6);
  *((_DWORD *)a4 + 1) = v6;
  *(_BYTE *)a4 = 4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10132230
// Name: public: virtual class GASObject __near * GASBlurFilterCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASBitmapFilterObject *__thiscall GASBlurFilterCtorFunction::CreateNewObject(GASBlurFilterCtorFunction *this, int a2)
{
  struct GASEnvironment *v2; // edi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GASBitmapFilterObject *v5; // eax
  GASBitmapFilterObject *v6; // esi

  v2 = (struct GASEnvironment *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASBitmapFilterObject *)v4(a1: v3, a2: 208, a3: &a2);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  GASBitmapFilterObject::GASBitmapFilterObject(
    this: v5,
    a2: v2,
    a3: FILTERSPECV4,
    blurMode: (struct GFxSocketImplFactory *)1);
  *v6 = (GASBitmapFilterObject)&GASBlurFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v6[4] = (GASBitmapFilterObject)&GASBlurFilterObject::`vftable'{for `GASObjectInterface'};
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10132290
// Name: protected: GASBlurFilterObject::GASBlurFilterObject(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASBlurFilterObject::GASBlurFilterObject(
        GFxAmpServer::ViewStats *this@<ecx>,
        int a2@<edi>,
        GASGlobalContext **psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4)
{
  GASObject::GASObject((GASObject *)this, a2, psc);
  this->__vftable = (GFxAmpServer::ViewStats_vtbl *)&GASBitmapFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBitmapFilterObject::`vftable'{for `GASObjectInterface'};
  *((float *)this + 16) = 5.0;
  *((float *)this + 17) = 5.0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 18) = 1;
  *((float *)this + 19) = 0.0;
  *((float *)this + 20) = 0.0;
  *((float *)this + 23) = 1.0;
  GRenderer::Cxform::Cxform(this: (float *)this + 24);
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 1), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  this->__vftable = (GFxAmpServer::ViewStats_vtbl *)&GASBlurFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBlurFilterObject::`vftable'{for `GASObjectInterface'};
}

//------------------------------------------------------------------------------
// Address: 0x10132300
// Name: public: static void GASBlurFilterProto::Clone(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASBlurFilterProto::Clone(GASFnCall *a1)
{
  GASFnCall v1; // ebx
  int *p_cxItem; // ebx
  struct GASObject *v3; // esi

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x28u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
    {
      p_cxItem = &v1[-1].cxItem;
      if ( p_cxItem != nullptr )
      {
        v3 = GASEnvironment::OperatorNew(
               this: (__vc_attributes::idl_quoteAttribute *)a1[6],
               a2: (int)a1,
               a3: *(struct GASObject **)(a1[6][3].cbSize + 676),
               a4: (const struct GASString *)(a1[6][3].cbSize + 168),
               nargs: 0,
               argsTopOff: -1);
        GFxFilterDesc::operator=(this: &v3[6].sequence, a2: (int)(p_cxItem + 13));
        GASValue::SetAsObject(this: (GASValue *)a1[1], a2: v3);
        if ( v3 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v3, a2: (int)a1);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "BlurFilter", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132380
// Name: public: static void GASBlurFilterCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASBlurFilterCtorFunction::GlobalCtor(GASBitmapFilterObject *a1@<edi>, _CONNECTDLGSTRUCTW fna)
{
  unsigned int cbStructure; // esi
  int v4; // eax
  int v5; // ebx
  int v6; // ecx
  int (__thiscall *v7)(int, int, int *); // eax
  GASBitmapFilterObject *v8; // eax
  GASValue *v9; // eax
  double v10; // st7
  GASValue *v11; // eax
  double v12; // st7
  GASValue *v13; // eax
  int v14; // esi
  int v15; // eax
  int *v16; // esi
  int v17; // eax
  bool v18; // zf
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  _SERVICE_STATUS *v23; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v24; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v25; // [esp-4h] [ebp-2Ch]
  GASValue v26[4]; // [esp+Ch] [ebp-1Ch] BYREF
  int v27; // [esp+1Ch] [ebp-Ch] BYREF
  __int64 v28; // [esp+20h] [ebp-8h] BYREF

  cbStructure = fna.cbStructure;
  if ( *(_DWORD *)(fna.cbStructure + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fna.cbStructure + 8) + 8))(a1: *(_DWORD *)(fna.cbStructure + 8)) == 40 )
  {
    v4 = *(_DWORD *)(cbStructure + 8);
    if ( v4 != 0 )
    {
      v5 = v4 - 16;
      if ( v4 != 16 )
        *(_DWORD *)(v5 + 8) = (*(_DWORD *)(v5 + 8) + 1) & 0x8FFFFFFF;
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 656);
    v7 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
    v27 = 323;
    v8 = (GASBitmapFilterObject *)v7(a1: v6, a2: 208, a3: &v27);
    a1 = v8;
    if ( v8 != nullptr )
    {
      GASBitmapFilterObject::GASBitmapFilterObject(
        this: v8,
        a2: *(struct GASEnvironment **)(cbStructure + 24),
        a3: FILTERSPECV4,
        blurMode: (struct GFxSocketImplFactory *)1);
      *a1 = (GASBitmapFilterObject)&GASBlurFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
      a1[4] = (GASBitmapFilterObject)&GASBlurFilterObject::`vftable'{for `GASObjectInterface'};
    }
    else
    {
      a1 = nullptr;
    }
    v5 = (int)a1;
  }
  GASValue::SetAsObject(this: *(GASValue **)(cbStructure + 4), a2: (struct GASObject *)v5);
  *(float *)(v5 + 64) = 4.0;
  *(_BYTE *)(v5 + 87) = -1;
  *(float *)(v5 + 68) = 4.0;
  *(float *)(v5 + 92) = 1.0;
  if ( *(int *)(cbStructure + 28) > 0 )
  {
    v23 = *(_SERVICE_STATUS **)(cbStructure + 24);
    v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
    v10 = GASValue::ToNumber(this: v9, a2: (int)a1, a3: 1.0, result: v23);
    *(float *)(v5 + 64) = v10;
    if ( *(int *)(cbStructure + 28) > 1 )
    {
      v24 = *(_SERVICE_STATUS **)(cbStructure + 24);
      v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 1);
      v12 = GASValue::ToNumber(this: v11, a2: (int)a1, a3: v10, result: v24);
      *(float *)(v5 + 68) = v12;
      if ( *(int *)(cbStructure + 28) > 2 )
      {
        v25 = *(_SERVICE_STATUS **)(cbStructure + 24);
        v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 2);
        v28 = (__int64)GASValue::ToNumber(this: v13, a2: (int)a1, a3: v12, result: v25);
        *(_DWORD *)(v5 + 72) = v28;
      }
    }
  }
  v14 = *(_DWORD *)(cbStructure + 24);
  v15 = *(_DWORD *)(v14 + 120);
  v16 = (int *)(v14 + 120);
  LOBYTE(v26[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  HIDWORD(v28) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(v15 + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E0D4.m_Memory.m_nGrowSize,
                   a3: 5u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v28) + 8);
  (*(void (__thiscall **)(int, int *, char *, GASValue *, char *))(*(_DWORD *)(v5 + 16) + 40))(
    a1: v5 + 16,
    a2: v16,
    a3: (char *)&v28 + 4,
    a4: v26,
    a5: (char *)&fna.cbStructure + 3);
  v17 = HIDWORD(v28);
  v18 = (*(_DWORD *)(HIDWORD(v28) + 8))-- == 1;
  if ( v18 )
    GASStringNode::ReleaseNode(a1: v17);
  GASValue::~GASValue(this: v26, a2: (int)a1);
  v19 = *v16;
  LOBYTE(v26[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  HIDWORD(v28) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(v19 + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E0D4,
                   a3: 5u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v28) + 8);
  (*(void (__thiscall **)(int, int *, char *, GASValue *, char *))(*(_DWORD *)(v5 + 16) + 40))(
    a1: v5 + 16,
    a2: v16,
    a3: (char *)&v28 + 4,
    a4: v26,
    a5: (char *)&fna.cbStructure + 3);
  v20 = HIDWORD(v28);
  v18 = (*(_DWORD *)(HIDWORD(v28) + 8))-- == 1;
  if ( v18 )
    GASStringNode::ReleaseNode(a1: v20);
  GASValue::~GASValue(this: v26, a2: (int)a1);
  v21 = *v16;
  LOBYTE(v26[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  HIDWORD(v28) = GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(v21 + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C40.m_Size,
                   a3: 7u,
                   a4: 0);
  ++*(_DWORD *)(HIDWORD(v28) + 8);
  (*(void (__thiscall **)(int, int *, char *, GASValue *, char *))(*(_DWORD *)(v5 + 16) + 40))(
    a1: v5 + 16,
    a2: v16,
    a3: (char *)&v28 + 4,
    a4: v26,
    a5: (char *)&fna.cbStructure + 3);
  v22 = HIDWORD(v28);
  v18 = (*(_DWORD *)(HIDWORD(v28) + 8))-- == 1;
  if ( v18 )
    GASStringNode::ReleaseNode(a1: v22);
  GASValue::~GASValue(this: v26, a2: (int)a1);
  GRefCountBaseGC<323>::Release(a1: v5, a2: (int)a1);
}

//------------------------------------------------------------------------------
// Address: 0x101325B0
// Name: public: GASBlurFilterProto::GASBlurFilterProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASBlurFilterProto *__thiscall GASBlurFilterProto::GASBlurFilterProto(
        GASBlurFilterProto *this,
        __int64 psc,
        const struct GASFunctionRef *psc_8)
{
  const struct GASFunctionRef *v4; // edx
  __int128 v6; // [esp-8h] [ebp-14h]

  GASBlurFilterObject::GASBlurFilterObject(
    (GFxAmpServer::ViewStats *)this,
    a2: (int)this,
    (GASGlobalContext **)psc,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)HIDWORD(psc));
  v4 = psc_8;
  *((_DWORD *)this + 52) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 220) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_BYTE *)this + 232) = 0;
  *((_DWORD *)this + 56) = 0;
  *((_DWORD *)this + 57) = 0;
  *((_DWORD *)this + 59) = 0;
  *(_QWORD *)&v6 = __PAIR64__((unsigned int)v4, psc);
  *(_DWORD *)this = &GASBlurFilterProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASBlurFilterObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 52) = &GASPrototype<GASBlurFilterObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 208),
    a2: (int)this,
    pthis: (CMaterialVar *)this,
    psc: v6);
  *(_DWORD *)this = &GASBlurFilterProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASBlurFilterObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 52) = &GASPrototype<GASBlurFilterObject,GASEnvironment>::`vftable';
  HIBYTE(psc) = 0;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 52,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)GASBlurFilterProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&psc + 7));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10132670
// Name: public: static class GASFunctionRef GASBlurFilterCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
ID3D11DepthStencilView *__usercall GASBlurFilterCtorFunction::Register@<eax>(
        int a1@<edi>,
        ID3D11DepthStencilView *result,
        _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v3; // esi
  int v4; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v6)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASCFunctionObject *v7; // edi
  ID3D11DepthStencilView_vtbl *v8; // eax
  const char *v10; // ecx
  int (__thiscall *v11)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASBlurFilterProto *v12; // ebx
  GASBlurFilterProto *v13; // ebx
  const char *MinVal; // edx
  GASValue *v15; // eax
  __int64 v17; // [esp-Ch] [ebp-30h]
  unsigned int Unused; // [esp-4h] [ebp-28h]
  GASValue v19; // [esp+Ch] [ebp-18h] BYREF
  int v20; // [esp+10h] [ebp-14h] BYREF
  int v21; // [esp+14h] [ebp-10h]
  char v22; // [esp+18h] [ebp-Ch]
  vc_attributes::PreRangeAttribute *v23; // [esp+1Ch] [ebp-8h] BYREF
  char v24; // [esp+20h] [ebp-4h]
  ID3D11DepthStencilView *v25; // [esp+2Ch] [ebp+8h]

  v3 = (vc_attributes::PreRangeAttribute *)pgc;
  Unused = pgc[9].Unused;
  ++*(_DWORD *)(Unused + 8);
  GASGlobalContext::GetBuiltinClassRegistrar(this: v3, a2: Unused);
  if ( v4 == 0 )
  {
    GASBitmapFilterCtorFunction::Register(a1: (struct GASFunctionRef *)&v20, pgc: (_KCRM_MARSHAL_HEADER *)v3);
    if ( (v22 & 2) == 0 && v20 != 0 )
      GRefCountBaseGC<323>::Release(a1: v20, a2: a1);
    v20 = 0;
    if ( (v22 & 1) == 0 && v21 != 0 )
      GRefCountBaseGC<323>::Release(a1: v21, a2: a1);
  }
  MaxVal = v3[54].MaxVal;
  v23 = v3;
  v24 = 8;
  v6 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v7 = (GASCFunctionObject *)v6(a1: MaxVal, a2: 56, a3: &pgc);
  if ( v7 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v7,
      func: (_REASON_CONTEXT *)&v23,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASBlurFilterCtorFunction::GlobalCtor);
    v7->dwSize = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v7->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v8 = (ID3D11DepthStencilView_vtbl *)v7;
  }
  else
  {
    v8 = nullptr;
  }
  result->__vftable = v8;
  LOBYTE(result[2].__vftable) = 0;
  result[1].__vftable = nullptr;
  v10 = v3[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)v10 + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v12 = (GASBlurFilterProto *)v11(a1: v10, a2: 240, a3: &pgc);
  if ( v12 != nullptr )
  {
    HIDWORD(v17) = GASGlobalContext::GetPrototype(this: v3, result: (vc_attributes::InvalidCheckAttribute *)0x25);
    LODWORD(v17) = &v23;
    v13 = GASBlurFilterProto::GASBlurFilterProto(this: v12, psc: v17, psc_8: (const struct GASFunctionRef *)result);
  }
  else
  {
    v13 = nullptr;
  }
  if ( v13 != nullptr )
    *((_DWORD *)v13 + 2) = (*((_DWORD *)v13 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v3, a2: (int)result, a3: 40, a4: (int)v13);
  MinVal = v3[56].MinVal;
  HIBYTE(pgc) = 0;
  v25 = *((ID3D11DepthStencilView **)MinVal + 4);
  v15 = GASValue::GASValue(this: &v19, a2: (int)result, a3: (const struct GASFunctionRef *)result);
  ((void (__thiscall *)(const char *, vc_attributes::PreRangeAttribute **, vc_attributes::PreRangeAttribute *, GASValue *, char *))v25[10].__vftable)(
    a1: v3[56].MinVal + 16,
    a2: &v23,
    a3: &v3[14],
    a4: v15,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: &v19, a2: (int)result);
  if ( v13 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v13, a2: (int)result);
  return result;
}
