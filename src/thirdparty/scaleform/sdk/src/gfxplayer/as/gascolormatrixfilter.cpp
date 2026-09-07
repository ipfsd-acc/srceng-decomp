// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gascolormatrixfilter.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gascolormatrixfilter.h"

//------------------------------------------------------------------------------
// Address: 0x10133E10
// Name: public: virtual enum GASObjectInterface::ObjectType GASColorMatrixFilterObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASColorMatrixFilterObject::GetObjectType()
{
  return 42;
}

//------------------------------------------------------------------------------
// Address: 0x10133E80
// Name: public: virtual bool GASColorMatrixFilterObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASColorMatrixFilterObject::SetMember(
        GFxAmpMessageSwdRequest *this@<ecx>,
        long double a2@<st0>,
        struct GASEnvironment *a3,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *val,
        char *flags)
{
  struct GASObject *v6; // edi
  int v7; // esi
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  int v9; // edx
  float v11; // [esp+10h] [ebp-58h]
  _DWORD v12[20]; // [esp+14h] [ebp-54h]

  if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_102A69D8) == 0 )
  {
    v6 = GASValue::ToObject(this: (GASValue *)val, a2: (int)val, a3);
    v7 = 0;
    if ( v6 != nullptr )
    {
      Prototype = GASGlobalContext::GetPrototype(
                    this: *((vc_attributes::PreRangeAttribute **)a3 + 30),
                    result: (vc_attributes::InvalidCheckAttribute *)2);
      if ( ((unsigned __int8 (__thiscall *)(struct GASObject *, struct GASEnvironment *, vc_attributes::InvalidCheckAttribute *, int))v6[2].pNode[9].pNext)(
             a1: &v6[2],
             a2: a3,
             a3: Prototype,
             a4: 1) != 0 )
      {
        v12[0] = 0;
        v12[1] = 1;
        v12[2] = 2;
        v12[3] = 3;
        v12[4] = 16;
        v12[5] = 4;
        v12[6] = 5;
        v12[7] = 6;
        v12[8] = 7;
        v12[9] = 17;
        v12[10] = 8;
        v12[11] = 9;
        v12[12] = 10;
        v12[13] = 11;
        v12[14] = 18;
        v12[15] = 12;
        v12[16] = 13;
        v12[17] = 14;
        v12[18] = 15;
        v12[19] = 19;
        if ( v6[7].sequence > 0 )
        {
          do
          {
            v11 = GASValue::ToNumber(
                    this: (GASValue *)*((_DWORD *)&v6[7].pNode->pNext + v7),
                    a2: (int)v6,
                    a3: a2,
                    result: (_SERVICE_STATUS *)a3);
            v9 = v12[v7];
            a2 = v11;
            ++v7;
            *((float *)this + v9 + 28) = v11;
          }
          while ( v7 < v6[7].sequence );
        }
      }
    }
  }
  else
  {
    GASObject::SetMember(
      (CTSQueue<CFunctor *,0,1> *)this,
      a2: (GASEnvironment *)a3,
      name,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
      pmember: flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134000
// Name: public: virtual class GASObject __near * GASColorMatrixFilterCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASBitmapFilterObject *__stdcall GASColorMatrixFilterCtorFunction::CreateNewObject(int result)
{
  struct GASEnvironment *v1; // edi
  HRESULT (__stdcall *v2)(ID3D11DeviceChild *, const _GUID *, unsigned int *, void *); // ecx
  int (__thiscall *v3)(HRESULT (__stdcall *)(ID3D11DeviceChild *, const _GUID *, unsigned int *, void *), int, int *); // edx
  GASBitmapFilterObject *v4; // eax
  GASBitmapFilterObject *v5; // esi

  v1 = (struct GASEnvironment *)result;
  v2 = *(HRESULT (__stdcall **)(ID3D11DeviceChild *, const _GUID *, unsigned int *, void *))(*(_DWORD *)(result + 120)
                                                                                           + 656);
  v3 = *(int (__thiscall **)(HRESULT (__stdcall *)(ID3D11DeviceChild *, const _GUID *, unsigned int *, void *), int, int *))(*(_DWORD *)v2 + 40);
  result = 323;
  v4 = (GASBitmapFilterObject *)v3(a1: v2, a2: 208, a3: &result);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  GASBitmapFilterObject::GASBitmapFilterObject(this: v4, a2: v1, a3: FILTERSPEC_END, blurMode: nullptr);
  *v5 = (GASBitmapFilterObject)&GASColorMatrixFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v5[4] = (GASBitmapFilterObject)&GASColorMatrixFilterObject::`vftable'{for `GASObjectInterface'};
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10134060
// Name: protected: GASColorMatrixFilterObject::GASColorMatrixFilterObject(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
GASColorMatrixFilterObject *__userpurge GASColorMatrixFilterObject::GASColorMatrixFilterObject@<eax>(GASColorMatrixFilterObject *this@<ecx>, int a2@<edi>, CTSQueue<CFunctor *,0,1>::Node_t *psc, CTSQueue<CFunctor *,0,1>::Node_t *a4)
{
  GASObject::GASObject((GASObject *)this, a2, (GASGlobalContext **)psc);
  *(_DWORD *)this = &GASBitmapFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBitmapFilterObject::`vftable'{for `GASObjectInterface'};
  *((float *)this + 16) = 5.0;
  *((float *)this + 17) = 5.0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 18) = 1;
  *((float *)this + 19) = 0.0;
  *((float *)this + 20) = 0.0;
  *((float *)this + 23) = 1.0;
  GRenderer::Cxform::Cxform(this: (float *)this + 24);
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)((char *)this + 16), psc, psc_4: a4);
  *(_DWORD *)this = &GASColorMatrixFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASColorMatrixFilterObject::`vftable'{for `GASObjectInterface'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101340D0
// Name: public: virtual bool GASColorMatrixFilterObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __fastcall GASColorMatrixFilterObject::GetMember(
        HICON__ *a1,
        int a2,
        HBRUSH__ *result,
        HINSTANCE__ *name,
        HICON__ *a5)
{
  HICON__ *v5; // ebx
  const char *v6; // esi
  HBRUSH__ *hbrBackground; // esi
  int v8; // ecx
  int (__thiscall *v9)(int, int, HBRUSH__ **); // eax
  int v10; // eax
  GRenderer::CachedData *v11; // edi
  int i; // esi
  double v14; // st7
  bool v15; // cf
  double v16; // st7
  GMemoryHeap *v17; // [esp+8h] [ebp-80h]
  const char *v18; // [esp+Ch] [ebp-7Ch]
  int v19; // [esp+10h] [ebp-78h]
  tagWNDCLASSW v20; // [esp+14h] [ebp-74h] BYREF
  int v21; // [esp+3Ch] [ebp-4Ch]
  int v22; // [esp+40h] [ebp-48h]
  int v23; // [esp+44h] [ebp-44h]
  int v24; // [esp+48h] [ebp-40h]
  int v25; // [esp+4Ch] [ebp-3Ch]
  int v26; // [esp+50h] [ebp-38h]
  int v27; // [esp+54h] [ebp-34h]
  int v28; // [esp+58h] [ebp-30h]
  int v29; // [esp+5Ch] [ebp-2Ch]
  int v30; // [esp+60h] [ebp-28h]
  int v31; // [esp+64h] [ebp-24h]
  int v32; // [esp+68h] [ebp-20h]
  int v33; // [esp+6Ch] [ebp-1Ch]
  int v34; // [esp+70h] [ebp-18h]
  int v35; // [esp+74h] [ebp-14h]
  int v36; // [esp+78h] [ebp-10h]
  int v37; // [esp+7Ch] [ebp-Ch]
  int v38; // [esp+80h] [ebp-8h]

  v20.hbrBackground = result;
  v5 = a1;
  v6 = **(const char ***)name;
  v20.hInstance = name;
  v20.hCursor = a1;
  v20.hIcon = a5;
  if ( strcmp(v6, (const char *)&stru_102A69D8) != 0 )
  {
    if ( strcmp(v6, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
    {
      v14 = *((float *)v5 + 12);
LABEL_12:
      v15 = *(_BYTE *)a5 < 5u;
      *(float *)&v20.hCursor = v14;
      if ( !v15 )
        GASValue::DropRefs(this: (GASValue *)a5, a2: (int)a5);
      v16 = *(float *)&v20.hCursor;
      *(_BYTE *)a5 = 3;
      *(double *)(a5 + 1) = v16;
      return 1;
    }
    if ( strcmp(v6, (const char *)&stru_1029E0D4) == 0 )
    {
      v14 = *((float *)v5 + 13);
      goto LABEL_12;
    }
    if ( GASString::operator==(this: (const char ***)v20.hInstance, a2: "color") )
    {
      GASValue::SetInt(this: (int)a5, result: (tagCOMPAREITEMSTRUCT *)((_DWORD)v5[17] & 0xFFFFFF));
      return 1;
    }
    if ( GASString::operator==(this: (const char ***)v20.hInstance, a2: (const char *)&stru_102A7C54.m_Size) )
    {
      v5 = (HICON__ *)(*((_DWORD *)v5 + 11) >> 9);
    }
    else
    {
      if ( !GASString::operator==(this: (const char ***)v20.hInstance, a2: (const char *)&stru_102A7C54) )
      {
        if ( GASString::operator==(this: (const char ***)v20.hInstance, a2: (const char *)&stru_102A7C40.m_Size) )
        {
          GASValue::SetInt(this: (int)a5, result: *((tagCOMPAREITEMSTRUCT **)v5 + 14));
        }
        else
        {
          if ( !GASString::operator==(this: (const char ***)v20.hInstance, a2: (const char *)&stru_102A7C40) )
            return (unsigned __int8)GASObject::GetMember(
                                      this: (D3DXQUATERNION *)v5,
                                      result: (ID3DXFont *)v20.hbrBackground,
                                      penv: (_IMAGE_SYMBOL_EX *)v20.hInstance,
                                      val: (int *)a5);
          GASValue::SetNumber(this: (GASValue *)a5, a2: *((float *)v5 + 19));
        }
        return 1;
      }
      LOBYTE(v5) = *((_BYTE *)v5 + 36) >> 5;
    }
    GASValue::DropRefs(this: (GASValue *)a5, a2: (int)a5);
    *(_BYTE *)a5 = 2;
    *((_BYTE *)a5 + 4) = (unsigned __int8)v5 & 1;
    return 1;
  }
  hbrBackground = v20.hbrBackground;
  v8 = *(_DWORD *)(*((_DWORD *)v20.hbrBackground + 30) + 656);
  v20.lpszMenuName = nullptr;
  v9 = *(int (__thiscall **)(int, int, HBRUSH__ **))(*(_DWORD *)v8 + 40);
  v20.lpszClassName = (const wchar_t *)1;
  v21 = 2;
  v22 = 3;
  v23 = 16;
  v24 = 4;
  v25 = 5;
  v26 = 6;
  v27 = 7;
  v28 = 17;
  v29 = 8;
  v30 = 9;
  v31 = 10;
  v32 = 11;
  v33 = 18;
  v34 = 12;
  v35 = 13;
  v36 = 14;
  v37 = 15;
  v38 = 19;
  v20.hbrBackground = (HBRUSH__ *)323;
  v10 = v9(a1: v8, a2: 76, a3: &v20.hbrBackground);
  if ( v10 != 0 )
    v11 = (GRenderer::CachedData *)GASArrayObject::GASArrayObject(
                                     a1: v10,
                                     penv: (unsigned int)hbrBackground,
                                     a3: v17,
                                     a4: v18,
                                     a5: v19);
  else
    v11 = nullptr;
  GASArrayObject::Resize(a1: v11, size: 20, a3: v17);
  for ( i = 0; i < 20; ++i )
  {
    v20.hbrBackground = *((HBRUSH__ **)v20.hCursor + *((_DWORD *)&v20.lpszMenuName + i) + 28);
    *(double *)&v20.lpfnWndProc = *(float *)&v20.hbrBackground;
    LOBYTE(v20.style) = 3;
    GASArrayObject::SetElement(this: (GASArrayObject *)v11, a2: i, v: &v20);
    GASValue::~GASValue(this: (GASValue *)&v20, a2: (int)v11);
  }
  GASValue::SetAsObject(this: (GASValue *)v20.hIcon, a2: (struct GASObject *)v11);
  if ( v11 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v11, a2: (int)v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101343C0
// Name: public: static void GASColorMatrixFilterProto::Clone(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASColorMatrixFilterProto::Clone(GASFnCall *a1)
{
  GASFnCall v1; // ebx
  int *p_cxItem; // ebx
  struct GASObject *v3; // esi

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x2Au) )
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
               a4: (const struct GASString *)(a1[6][3].cbSize + 176),
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
    GASFnCall::ThisPtrError(this: a1, a2: "ColorMatrixFilter", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134440
// Name: public: static void GASColorMatrixFilterCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall GASColorMatrixFilterCtorFunction::GlobalCtor@<al>(int a1@<edi>, long double a2@<st0>, int fn)
{
  int v3; // eax
  struct GASObject *v4; // eax
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // edx
  GASValue *v7; // eax
  struct GASObject *v8; // ebx
  int v9; // edi
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  int v11; // eax
  int v12; // esi
  int v13; // edx
  struct GASObject *v14; // edi
  int v15; // eax
  const struct GASEnvironment *v18; // [esp-8h] [ebp-84h]
  GASValue v19[4]; // [esp+8h] [ebp-74h] BYREF
  int v20; // [esp+18h] [ebp-64h] BYREF
  float v21; // [esp+1Ch] [ebp-60h] BYREF
  struct GASObject *v22; // [esp+20h] [ebp-5Ch]
  char v23; // [esp+27h] [ebp-55h]
  _DWORD v24[20]; // [esp+28h] [ebp-54h]

  if ( *(_DWORD *)(fn + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fn + 8) + 8))(a1: *(_DWORD *)(fn + 8)) == 42 )
  {
    v3 = *(_DWORD *)(fn + 8);
    if ( v3 != 0 )
    {
      v4 = (struct GASObject *)(v3 - 16);
      if ( v4 != nullptr )
        v4[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v4[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v22 = v4;
    }
    else
    {
      v22 = nullptr;
    }
  }
  else
  {
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 120) + 656);
    v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
    v20 = 323;
    a1 = v6(a1: v5, a2: 208, a3: &v20);
    if ( a1 != 0 )
    {
      GASBitmapFilterObject::GASBitmapFilterObject(
        this: (GASBitmapFilterObject *)a1,
        a2: *(struct GASEnvironment **)(fn + 24),
        a3: FILTERSPEC_END,
        blurMode: nullptr);
      *(_DWORD *)a1 = &GASColorMatrixFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(a1 + 16) = &GASColorMatrixFilterObject::`vftable'{for `GASObjectInterface'};
    }
    else
    {
      a1 = 0;
    }
    v22 = (struct GASObject *)a1;
  }
  GASValue::SetAsObject(this: *(GASValue **)(fn + 4), a2: v22);
  if ( *(int *)(fn + 28) > 0 )
  {
    v18 = *(const struct GASEnvironment **)(fn + 24);
    v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    v8 = GASValue::ToObject(this: v7, a2: a1, a3: v18);
    v9 = 0;
    if ( v8 != nullptr )
    {
      Prototype = GASGlobalContext::GetPrototype(
                    this: *(vc_attributes::PreRangeAttribute **)(*(_DWORD *)(fn + 24) + 120),
                    result: (vc_attributes::InvalidCheckAttribute *)2);
      if ( ((unsigned __int8 (__thiscall *)(struct GASObject *, _DWORD, vc_attributes::InvalidCheckAttribute *, int))v8[2].pNode[9].pNext)(
             a1: &v8[2],
             a2: *(_DWORD *)(fn + 24),
             a3: Prototype,
             a4: 1) != 0 )
      {
        v24[0] = 0;
        v24[1] = 1;
        v24[2] = 2;
        v24[3] = 3;
        v24[4] = 16;
        v24[5] = 4;
        v24[6] = 5;
        v24[7] = 6;
        v24[8] = 7;
        v24[9] = 17;
        v24[10] = 8;
        v24[11] = 9;
        v24[12] = 10;
        v24[13] = 11;
        v24[14] = 18;
        v24[15] = 12;
        v24[16] = 13;
        v24[17] = 14;
        v24[18] = 15;
        v24[19] = 19;
        if ( v8[7].sequence > 0 )
        {
          do
          {
            v21 = GASValue::ToNumber(
                    this: (GASValue *)*((_DWORD *)&v8[7].pNode->pNext + v9),
                    a2: v9,
                    a3: a2,
                    result: (_SERVICE_STATUS *)*(_DWORD *)(fn + 24));
            v11 = v24[v9];
            a2 = v21;
            ++v9;
            *((float *)&v22[16].pNode + v11) = v21;
          }
          while ( v9 < v8[7].sequence );
        }
      }
    }
  }
  v12 = *(_DWORD *)(fn + 24);
  v13 = *(_DWORD *)(v12 + 120);
  v14 = v22;
  LOBYTE(v19[0]) = 10;
  v23 = 0;
  v21 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v13 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A69D8,
            a3: 6u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v21) + 8);
  ((void (__thiscall *)(struct GASObject *, int, float *))v14[2].pNode[5].pNext)(a1: &v14[2], a2: v12 + 120, a3: &v21);
  v15 = LODWORD(v21);
  if ( (*(_DWORD *)(LODWORD(v21) + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v15);
  GASValue::~GASValue(this: v19, a2: (int)v19);
  return GRefCountBaseGC<323>::Release(a1: (int)v22, a2: (int)v19);
}

//------------------------------------------------------------------------------
// Address: 0x10134670
// Name: public: GASColorMatrixFilterProto::GASColorMatrixFilterProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASColorMatrixFilterProto *__thiscall GASColorMatrixFilterProto::GASColorMatrixFilterProto(
        GASColorMatrixFilterProto *this,
        __int64 psc,
        const struct GASFunctionRef *psc_8)
{
  const struct GASFunctionRef *v4; // edx
  __int128 v6; // [esp-8h] [ebp-14h]

  GASColorMatrixFilterObject::GASColorMatrixFilterObject(
    (GASColorMatrixFilterObject *)this,
    a2: (int)this,
    (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    a4: (CTSQueue<CFunctor *,0,1>::Node_t *)HIDWORD(psc));
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
  *(_DWORD *)this = &GASPrototype<GASColorMatrixFilterObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASColorMatrixFilterObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 52) = &GASPrototype<GASColorMatrixFilterObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 208),
    a2: (int)this,
    pthis: (CMaterialVar *)this,
    psc: v6);
  *(_DWORD *)this = &GASPrototype<GASColorMatrixFilterObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASColorMatrixFilterObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 52) = &GASPrototype<GASColorMatrixFilterObject,GASEnvironment>::`vftable';
  HIBYTE(psc) = 0;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 52,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)GASColorMatrixFilterProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&psc + 7));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101347A0
// Name: public: static class GASFunctionRef GASColorMatrixFilterCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__usercall GASColorMatrixFilterCtorFunction::Register@<eax>(
        int a1@<edi>,
        struct GASFunctionRef *a2,
        vc_attributes::PreRangeAttribute *a3)
{
  vc_attributes::PreRangeAttribute *v3; // esi
  int v4; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v6)(const char *, int, vc_attributes::PreRangeAttribute **); // edx
  GASCFunctionObject *v7; // edi
  GASCFunctionObject *v8; // eax
  const char *v10; // ecx
  int (__thiscall *v11)(const char *, int, vc_attributes::PreRangeAttribute **); // edx
  GASColorMatrixFilterProto *v12; // ebx
  GASColorMatrixFilterProto *v13; // ebx
  const char *MinVal; // edx
  GASValue *v15; // eax
  __int64 v17; // [esp-Ch] [ebp-30h]
  unsigned int Deref; // [esp-4h] [ebp-28h]
  GASValue v19; // [esp+Ch] [ebp-18h] BYREF
  int v20; // [esp+10h] [ebp-14h] BYREF
  int v21; // [esp+14h] [ebp-10h]
  char v22; // [esp+18h] [ebp-Ch]
  vc_attributes::PreRangeAttribute *v23; // [esp+1Ch] [ebp-8h] BYREF
  char v24; // [esp+20h] [ebp-4h]
  struct GASFunctionRef *v25; // [esp+2Ch] [ebp+8h]

  v3 = a3;
  Deref = a3[13].Deref;
  ++*(_DWORD *)(Deref + 8);
  GASGlobalContext::GetBuiltinClassRegistrar(this: v3, a2: Deref);
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
  v6 = *(int (__thiscall **)(const char *, int, vc_attributes::PreRangeAttribute **))(*(_DWORD *)MaxVal + 40);
  a3 = (vc_attributes::PreRangeAttribute *)323;
  v7 = (GASCFunctionObject *)v6(a1: MaxVal, a2: 56, &a3);
  if ( v7 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v7,
      func: (_REASON_CONTEXT *)&v23,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASColorMatrixFilterCtorFunction::GlobalCtor);
    v7->dwSize = (unsigned int)&GASColorMatrixFilterCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v7->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  *(_DWORD *)a2 = v8;
  *((_BYTE *)a2 + 8) = 0;
  *((_DWORD *)a2 + 1) = 0;
  v10 = v3[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, vc_attributes::PreRangeAttribute **))(*(_DWORD *)v10 + 40);
  a3 = (vc_attributes::PreRangeAttribute *)323;
  v12 = (GASColorMatrixFilterProto *)v11(a1: v10, a2: 240, &a3);
  if ( v12 != nullptr )
  {
    HIDWORD(v17) = GASGlobalContext::GetPrototype(this: v3, result: (vc_attributes::InvalidCheckAttribute *)0x25);
    LODWORD(v17) = &v23;
    v13 = GASColorMatrixFilterProto::GASColorMatrixFilterProto(this: v12, psc: v17, psc_8: a2);
  }
  else
  {
    v13 = nullptr;
  }
  if ( v13 != nullptr )
    *((_DWORD *)v13 + 2) = (*((_DWORD *)v13 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v3, (int)a2, a3: 42, a4: (int)v13);
  MinVal = v3[56].MinVal;
  HIBYTE(a3) = 0;
  v25 = *((struct GASFunctionRef **)MinVal + 4);
  v15 = GASValue::GASValue(this: &v19, (int)a2, a3: a2);
  (*((void (__thiscall **)(const char *, vc_attributes::PreRangeAttribute **, const char **, GASValue *, char *))v25 + 10))(
    a1: v3[56].MinVal + 16,
    a2: &v23,
    a3: &v3[14].MaxVal,
    a4: v15,
    a5: (char *)&a3 + 3);
  GASValue::~GASValue(this: &v19, (int)a2);
  if ( v13 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v13, (int)a2);
  return a2;
}
