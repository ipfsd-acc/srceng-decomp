// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasglowfilter.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasglowfilter.h"

//------------------------------------------------------------------------------
// Address: 0x10130FF0
// Name: public: virtual enum GASObjectInterface::ObjectType GASGlowFilterObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASGlowFilterObject::GetObjectType()
{
  return 39;
}

//------------------------------------------------------------------------------
// Address: 0x10131000
// Name: public: virtual bool GASGlowFilterObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASGlowFilterObject::GetMember(
        GFxAmpServer *this,
        GStringHash<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,GAllocatorGH<GArray<GPtr<GFxResource>,2,GArrayDefaultPolicy>,2> > *penv,
        const char ***name,
        GASValue *a4)
{
  unsigned __int8 CurveTolerance_high; // al
  double v6; // st7
  double v7; // st7
  unsigned int v8; // ebx
  float namea; // [esp+28h] [ebp+Ch]
  float nameb; // [esp+28h] [ebp+Ch]

  if ( strcmp(**name, (const char *)&stru_1029DF5C) == 0 )
  {
    CurveTolerance_high = HIBYTE(this->CurrentState.CurveTolerance);
    if ( CurveTolerance_high != 0 )
      v6 = (double)CurveTolerance_high / 255.0;
    else
      v6 = 0.0;
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: (int)this);
    namea = v6;
    *(double *)(a4 + 1) = namea;
    *(_BYTE *)a4 = 3;
  }
  else
  {
    if ( strcmp(**name, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
    {
      v7 = *(float *)&this->CurrentState.StrokeType.pData;
    }
    else
    {
      if ( strcmp(**name, (const char *)&stru_1029E0D4) != 0 )
      {
        if ( GASString::operator==(this: name, a2: "color") )
        {
          GASValue::SetInt(
            this: (int)a4,
            result: (tagCOMPAREITEMSTRUCT *)(LODWORD(this->CurrentState.CurveTolerance) & 0xFFFFFF));
          return;
        }
        if ( GASString::operator==(this: name, a2: (const char *)&stru_102A7C54.m_Size) )
        {
          v8 = this->CurrentState.AaMode.HeapTypeBits >> 9;
        }
        else
        {
          if ( !GASString::operator==(this: name, a2: (const char *)&stru_102A7C54) )
          {
            if ( GASString::operator==(this: name, a2: (const char *)&stru_102A7C40.m_Size) )
            {
              GASValue::SetInt(this: (int)a4, result: (tagCOMPAREITEMSTRUCT *)this->CurrentState.Locales.Data.Data);
            }
            else if ( GASString::operator==(this: name, a2: (const char *)&stru_102A7C40) )
            {
              GASValue::SetNumber(this: a4, a2: this->CurrentState.CurveToleranceMax);
            }
            else
            {
              GASObject::GetMember(
                (D3DXQUATERNION *)this,
                result: (ID3DXFont *)penv,
                penv: (_IMAGE_SYMBOL_EX *)name,
                val: (int *)a4);
            }
            return;
          }
          LOBYTE(v8) = LOBYTE(this->CurrentState.ConnectedApp.pData) >> 5;
        }
        GASValue::DropRefs(this: a4, a2: (int)this);
        *((_BYTE *)a4 + 4) = v8 & 1;
        *(_BYTE *)a4 = 2;
        return;
      }
      v7 = *(float *)&this->CurrentState.CurrentLocale.pData;
    }
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: (int)this);
    nameb = v7;
    *(double *)(a4 + 1) = nameb;
    *(_BYTE *)a4 = 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131250
// Name: public: virtual bool GASGlowFilterObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASGlowFilterObject::SetMember(
        GASGlowFilterObject *this@<ecx>,
        long double a2@<st0>,
        tagPOLYTEXTW *result,
        _IMAGE_SYMBOL_EX *a4,
        GASValue *a5,
        const struct GASPropFlags *a6)
{
  int v7; // eax
  char CurveTolerance_high; // cl
  float v9; // [esp+24h] [ebp+10h]

  if ( strcmp(*(const char **)a4->N.Name.Short, (const char *)&stru_1029DF5C) == 0 )
  {
    v9 = GASValue::ToNumber(this: a5, a2: (int)this, a3: a2, (_SERVICE_STATUS *)result);
    HIBYTE(this->CurrentState.CurveTolerance) = (int)(v9 * 255.0);
  }
  else if ( strcmp(*(const char **)a4->N.Name.Short, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
  {
    *(float *)&this->CurrentState.StrokeType.pData = GASValue::ToNumber(
                                                       this: a5,
                                                       a2: (int)this,
                                                       a3: a2,
                                                       (_SERVICE_STATUS *)result);
  }
  else if ( strcmp(*(const char **)a4->N.Name.Short, (const char *)&stru_1029E0D4) == 0 )
  {
    *(float *)&this->CurrentState.CurrentLocale.pData = GASValue::ToNumber(
                                                          this: a5,
                                                          a2: (int)this,
                                                          a3: a2,
                                                          (_SERVICE_STATUS *)result);
  }
  else if ( GASString::operator==(this: (const char ***)a4, a2: "color") )
  {
    v7 = GASValue::ToUInt32(this: a5, a2: (int)this, a3: a2, a4: (_SERVICE_STATUS *)result);
    CurveTolerance_high = HIBYTE(this->CurrentState.CurveTolerance);
    LODWORD(this->CurrentState.CurveTolerance) = v7;
    HIBYTE(this->CurrentState.CurveTolerance) = CurveTolerance_high;
  }
  else if ( GASString::operator==(this: (const char ***)a4, a2: (const char *)&stru_102A7C54.m_Size) )
  {
    if ( GASValue::ToBool(a1: (char *)a5, a2, result) != 0 )
      this->CurrentState.AaMode.HeapTypeBits |= 0x200u;
    else
      this->CurrentState.AaMode.HeapTypeBits &= ~0x200u;
  }
  else if ( GASString::operator==(this: (const char ***)a4, a2: (const char *)&stru_102A7C54) )
  {
    if ( GASValue::ToBool(a1: (char *)a5, a2, result) != 0 )
    {
      LOBYTE(this->CurrentState.ConnectedApp.pData) |= 0x20u;
      this->CurrentState.AaMode.HeapTypeBits |= 0x100u;
    }
    else
    {
      LOBYTE(this->CurrentState.ConnectedApp.pData) &= ~0x20u;
      this->CurrentState.AaMode.HeapTypeBits &= ~0x100u;
    }
  }
  else if ( GASString::operator==(this: (const char ***)a4, a2: (const char *)&stru_102A7C40.m_Size) )
  {
    this->CurrentState.Locales.Data.Data = (GString *)(__int64)GASValue::ToNumber(
                                                                 this: a5,
                                                                 a2: (int)this,
                                                                 a3: a2,
                                                                 (_SERVICE_STATUS *)result);
  }
  else if ( GASString::operator==(this: (const char ***)a4, a2: (const char *)&stru_102A7C40) )
  {
    this->CurrentState.CurveToleranceMax = GASValue::ToNumber(
                                             this: a5,
                                             a2: (int)this,
                                             a3: a2,
                                             (_SERVICE_STATUS *)result);
  }
  else
  {
    GASObject::SetMember(
      (CTSQueue<CFunctor *,0,1> *)this,
      a2: (GASEnvironment *)result,
      name: a4,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)a5,
      pmember: (char *)a6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101314C0
// Name: public: virtual class GASObject __near * GASGlowFilterCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASBitmapFilterObject *__stdcall GASGlowFilterCtorFunction::CreateNewObject(int result)
{
  struct GASEnvironment *v1; // edi
  int v2; // ecx
  int (__thiscall *v3)(int, int, int *); // edx
  GASBitmapFilterObject *v4; // eax
  GASBitmapFilterObject *v5; // esi

  v1 = (struct GASEnvironment *)result;
  v2 = *(_DWORD *)(*(_DWORD *)(result + 120) + 656);
  v3 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v2 + 40);
  result = 323;
  v4 = (GASBitmapFilterObject *)v3(a1: v2, a2: 208, a3: &result);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  GASBitmapFilterObject::GASBitmapFilterObject(
    this: v4,
    a2: v1,
    a3: FILTERSPECV6,
    blurMode: (struct GFxSocketImplFactory *)2);
  *v5 = (GASBitmapFilterObject)&GASGlowFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v5[4] = (GASBitmapFilterObject)&GASGlowFilterObject::`vftable'{for `GASObjectInterface'};
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101315C0
// Name: protected: GASGlowFilterObject::GASGlowFilterObject(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASGlowFilterObject::GASGlowFilterObject(
        GFxAmpServer *this@<ecx>,
        int a2@<edi>,
        GASGlobalContext **psc,
        CTSQueue<CFunctor *,0,1>::Node_t *pprototype)
{
  GASObject::GASObject((GASObject *)this, a2, psc);
  this->__vftable = (GFxAmpServer_vtbl *)&GASBitmapFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  this->RecvName.HeapTypeBits = (unsigned int)&GASBitmapFilterObject::`vftable'{for `GASObjectInterface'};
  *(float *)&this->CurrentState.Locales.Data.Policy.Capacity = 5.0;
  this->CurrentState.CurveTolerance = 5.0;
  this->CurrentState.Locales.Data.Size = 0;
  LODWORD(this->CurrentState.CurveToleranceMin) = 1;
  this->CurrentState.CurveToleranceMax = 0.0;
  this->CurrentState.CurveToleranceStep = 0.0;
  *((float *)&this->CurrentState.CurrentFileId + 1) = 1.0;
  GRenderer::Cxform::Cxform(this: (float *)&this->CurrentState.CurrentLineNumber);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&this->RecvName,
    (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    psc_4: pprototype);
  this->__vftable = (GFxAmpServer_vtbl *)&GASGlowFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  this->RecvName.HeapTypeBits = (unsigned int)&GASGlowFilterObject::`vftable'{for `GASObjectInterface'};
}

//------------------------------------------------------------------------------
// Address: 0x10131630
// Name: public: static void GASGlowFilterProto::Clone(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASGlowFilterProto::Clone(GASFnCall *a1)
{
  GASFnCall v1; // ebx
  int *p_cxItem; // ebx
  struct GASObject *v3; // esi

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x27u) )
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
               a4: (const struct GASString *)(a1[6][3].cbSize + 164),
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
    GASFnCall::ThisPtrError(this: a1, a2: "GlowFilter", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101316B0
// Name: public: static void GASGlowFilterCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASGlowFilterCtorFunction::GlobalCtor(GASBitmapFilterObject *a1@<edi>, float fn)
{
  float v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // eax
  GASBitmapFilterObject *v7; // eax
  double v8; // st7
  GASValue *v9; // eax
  int v10; // eax
  long double v11; // st7
  char v12; // cl
  GASValue *v13; // eax
  long double v14; // st7
  GASValue *v15; // eax
  double v16; // st7
  GASValue *v17; // eax
  double v18; // st7
  GASValue *v19; // eax
  double v20; // st7
  GASValue *v21; // eax
  double v22; // st7
  char *v23; // eax
  long double v24; // st7
  char *v25; // eax
  int v26; // esi
  int v27; // eax
  int *v28; // esi
  int v29; // eax
  bool v30; // zf
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  _SERVICE_STATUS *v45; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v46; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v47; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v48; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v49; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v50; // [esp-4h] [ebp-2Ch]
  tagPOLYTEXTW *v51; // [esp-4h] [ebp-2Ch]
  tagPOLYTEXTW *v52; // [esp-4h] [ebp-2Ch]
  GASValue v53[2]; // [esp+Ch] [ebp-1Ch] BYREF
  double v54; // [esp+14h] [ebp-14h]
  int v55; // [esp+1Ch] [ebp-Ch] BYREF
  float v56; // [esp+20h] [ebp-8h]
  float v57; // [esp+24h] [ebp-4h] BYREF

  v2 = fn;
  if ( *(_DWORD *)(LODWORD(fn) + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(fn) + 8) + 8))(a1: *(_DWORD *)(LODWORD(fn) + 8)) == 39 )
  {
    v3 = *(_DWORD *)(LODWORD(v2) + 8);
    if ( v3 != 0 )
    {
      v4 = v3 - 16;
      if ( v3 != 16 )
        *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v2) + 24) + 120) + 656);
    v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
    v55 = 323;
    v7 = (GASBitmapFilterObject *)v6(a1: v5, a2: 208, a3: &v55);
    a1 = v7;
    if ( v7 != nullptr )
    {
      GASBitmapFilterObject::GASBitmapFilterObject(
        this: v7,
        a2: *(struct GASEnvironment **)(LODWORD(v2) + 24),
        a3: FILTERSPECV6,
        blurMode: (struct GFxSocketImplFactory *)2);
      *a1 = (GASBitmapFilterObject)&GASGlowFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
      a1[4] = (GASBitmapFilterObject)&GASGlowFilterObject::`vftable'{for `GASObjectInterface'};
    }
    else
    {
      a1 = nullptr;
    }
    v4 = (int)a1;
  }
  GASValue::SetAsObject(this: *(GASValue **)(LODWORD(v2) + 4), a2: (struct GASObject *)v4);
  *(_WORD *)(v4 + 56) = 0;
  fn = (double)*(__int16 *)(v4 + 54) * 3.141592741012573 / 1800.0;
  v54 = (double)0;
  v57 = cos(fn);
  v56 = v57 * v54 * 0.05000000074505806;
  fn = sin(fn);
  v8 = fn * v54;
  fn = 0.0;
  v57 = v8 * 0.05000000074505806;
  *(float *)(v4 + 76) = v56;
  *(float *)(v4 + 80) = v57;
  *(_WORD *)(v4 + 54) = 0;
  LODWORD(v57) = *(__int16 *)(v4 + 56);
  fn = (double)SLODWORD(fn) * 3.141592741012573 / 1800.0;
  v54 = (double)SLODWORD(v57);
  v57 = cos(fn);
  v56 = v57 * v54 * 0.05000000074505806;
  fn = sin(fn);
  v57 = fn * v54 * 0.05000000074505806;
  *(float *)(v4 + 76) = v56;
  *(float *)(v4 + 80) = v57;
  *(_DWORD *)(v4 + 84) = 16711680;
  *(_BYTE *)(v4 + 52) &= 0x9Fu;
  *(_DWORD *)(v4 + 60) &= 0xFFFFFAFF;
  *(float *)(v4 + 64) = 6.0;
  *(float *)(v4 + 68) = 6.0;
  *(_BYTE *)(v4 + 87) = -1;
  *(float *)(v4 + 92) = 2.0;
  if ( *(int *)(LODWORD(v2) + 28) > 0 )
  {
    v45 = *(_SERVICE_STATUS **)(LODWORD(v2) + 24);
    v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v2), a2: 0);
    v10 = GASValue::ToUInt32(this: v9, a2: (int)a1, a3: 2.0, a4: v45);
    v12 = *(_BYTE *)(v4 + 87);
    *(_DWORD *)(v4 + 84) = v10;
    *(_BYTE *)(v4 + 87) = v12;
    if ( *(int *)(LODWORD(v2) + 28) > 1 )
    {
      v46 = *(_SERVICE_STATUS **)(LODWORD(v2) + 24);
      v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v2), a2: 1);
      fn = GASValue::ToNumber(this: v13, a2: (int)a1, a3: v11, result: v46);
      v14 = fn * 255.0;
      LODWORD(v57) = (int)v14;
      *(_BYTE *)(v4 + 87) = (int)v14;
      if ( *(int *)(LODWORD(v2) + 28) > 2 )
      {
        v47 = *(_SERVICE_STATUS **)(LODWORD(v2) + 24);
        v15 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v2), a2: 2);
        v16 = GASValue::ToNumber(this: v15, a2: (int)a1, a3: v14, result: v47);
        *(float *)(v4 + 64) = v16;
        if ( *(int *)(LODWORD(v2) + 28) > 3 )
        {
          v48 = *(_SERVICE_STATUS **)(LODWORD(v2) + 24);
          v17 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v2), a2: 3);
          v18 = GASValue::ToNumber(this: v17, a2: (int)a1, a3: v16, result: v48);
          *(float *)(v4 + 68) = v18;
          if ( *(int *)(LODWORD(v2) + 28) > 4 )
          {
            v49 = *(_SERVICE_STATUS **)(LODWORD(v2) + 24);
            v19 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v2), a2: 4);
            v20 = GASValue::ToNumber(this: v19, a2: (int)a1, a3: v18, result: v49);
            *(float *)(v4 + 92) = v20;
            if ( *(int *)(LODWORD(v2) + 28) > 5 )
            {
              v50 = *(_SERVICE_STATUS **)(LODWORD(v2) + 24);
              v21 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v2), a2: 5);
              v22 = GASValue::ToNumber(this: v21, a2: (int)a1, a3: v20, result: v50);
              LODWORD(v57) = HIWORD(fn) | 0xC00;
              *(_QWORD *)&v54 = (__int64)v22;
              *(_DWORD *)(v4 + 72) = (__int64)v22;
              if ( *(int *)(LODWORD(v2) + 28) > 6 )
              {
                v51 = *(tagPOLYTEXTW **)(LODWORD(v2) + 24);
                v23 = (char *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v2), a2: 6);
                if ( GASValue::ToBool(a1: v23, a2: v22, result: v51) != 0 )
                  *(_DWORD *)(v4 + 60) |= 0x200u;
                else
                  *(_DWORD *)(v4 + 60) &= ~0x200u;
                if ( *(int *)(LODWORD(v2) + 28) > 7 )
                {
                  v52 = *(tagPOLYTEXTW **)(LODWORD(v2) + 24);
                  v25 = (char *)GASFnCall::Arg(this: (GASFnCall *)LODWORD(v2), a2: 7);
                  if ( GASValue::ToBool(a1: v25, a2: v24, result: v52) != 0 )
                  {
                    *(_BYTE *)(v4 + 52) |= 0x20u;
                    *(_DWORD *)(v4 + 60) |= 0x100u;
                  }
                  else
                  {
                    *(_BYTE *)(v4 + 52) &= ~0x20u;
                    *(_DWORD *)(v4 + 60) &= ~0x100u;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v26 = *(_DWORD *)(LODWORD(v2) + 24);
  v27 = *(_DWORD *)(v26 + 120);
  v28 = (int *)(v26 + 120);
  LOBYTE(v53[0]) = 10;
  HIBYTE(fn) = 0;
  v57 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v27 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"color",
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v57) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v28,
    a3: &v57,
    a4: v53,
    a5: (char *)&fn + 3);
  v29 = LODWORD(v57);
  v30 = (*(_DWORD *)(LODWORD(v57) + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode(a1: v29);
  GASValue::~GASValue(this: v53, a2: (int)a1);
  v31 = *v28;
  LOBYTE(v53[0]) = 10;
  HIBYTE(fn) = 0;
  v57 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v31 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DF5C,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v57) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v28,
    a3: &v57,
    a4: v53,
    a5: (char *)&fn + 3);
  v32 = LODWORD(v57);
  v30 = (*(_DWORD *)(LODWORD(v57) + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode(a1: v32);
  GASValue::~GASValue(this: v53, a2: (int)a1);
  v33 = *v28;
  LOBYTE(v53[0]) = 10;
  HIBYTE(fn) = 0;
  v57 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v33 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E0D4.m_Memory.m_nGrowSize,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v57) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v28,
    a3: &v57,
    a4: v53,
    a5: (char *)&fn + 3);
  v34 = LODWORD(v57);
  v30 = (*(_DWORD *)(LODWORD(v57) + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode(a1: v34);
  GASValue::~GASValue(this: v53, a2: (int)a1);
  v35 = *v28;
  LOBYTE(v53[0]) = 10;
  HIBYTE(fn) = 0;
  v57 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v35 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E0D4,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v57) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v28,
    a3: &v57,
    a4: v53,
    a5: (char *)&fn + 3);
  v36 = LODWORD(v57);
  v30 = (*(_DWORD *)(LODWORD(v57) + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode(a1: v36);
  GASValue::~GASValue(this: v53, a2: (int)a1);
  v37 = *v28;
  LOBYTE(v53[0]) = 10;
  HIBYTE(fn) = 0;
  v57 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v37 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C40,
            a3: 8u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v57) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v28,
    a3: &v57,
    a4: v53,
    a5: (char *)&fn + 3);
  v38 = LODWORD(v57);
  v30 = (*(_DWORD *)(LODWORD(v57) + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode(a1: v38);
  GASValue::~GASValue(this: v53, a2: (int)a1);
  v39 = *v28;
  LOBYTE(v53[0]) = 10;
  HIBYTE(fn) = 0;
  v57 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v39 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C54,
            a3: 8u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v57) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v28,
    a3: &v57,
    a4: v53,
    a5: (char *)&fn + 3);
  v40 = LODWORD(v57);
  v30 = (*(_DWORD *)(LODWORD(v57) + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode(a1: v40);
  GASValue::~GASValue(this: v53, a2: (int)a1);
  v41 = *v28;
  LOBYTE(v53[0]) = 10;
  HIBYTE(fn) = 0;
  v57 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v41 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C54.m_Size,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v57) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v28,
    a3: &v57,
    a4: v53,
    a5: (char *)&fn + 3);
  v42 = LODWORD(v57);
  v30 = (*(_DWORD *)(LODWORD(v57) + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode(a1: v42);
  GASValue::~GASValue(this: v53, a2: (int)a1);
  v43 = *v28;
  LOBYTE(v53[0]) = 10;
  HIBYTE(fn) = 0;
  v57 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v43 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C40.m_Size,
            a3: 7u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v57) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v28,
    a3: &v57,
    a4: v53,
    a5: (char *)&fn + 3);
  v44 = LODWORD(v57);
  v30 = (*(_DWORD *)(LODWORD(v57) + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode(a1: v44);
  GASValue::~GASValue(this: v53, a2: (int)a1);
  GRefCountBaseGC<323>::Release(a1: v4, a2: (int)a1);
}

//------------------------------------------------------------------------------
// Address: 0x10131C70
// Name: public: GASGlowFilterProto::GASGlowFilterProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall GASGlowFilterProto::GASGlowFilterProto(
        CMaterialVar *pthis,
        GASGlobalContext **psc,
        CTSQueue<CFunctor *,0,1>::Node_t *pprototype,
        const struct GASFunctionRef *a4)
{
  const struct GASFunctionRef *v5; // edx
  __int128 v7; // [esp-8h] [ebp-14h]

  GASGlowFilterObject::GASGlowFilterObject(this: (GFxAmpServer *)pthis, a2: (int)pthis, psc, pprototype);
  v5 = a4;
  *((_DWORD *)pthis + 52) = &GASPrototypeBase::`vftable';
  *((_BYTE *)pthis + 220) = 0;
  *((_DWORD *)pthis + 53) = 0;
  *((_DWORD *)pthis + 54) = 0;
  *((_BYTE *)pthis + 232) = 0;
  *((_DWORD *)pthis + 56) = 0;
  *((_DWORD *)pthis + 57) = 0;
  *((_DWORD *)pthis + 59) = 0;
  *(_QWORD *)&v7 = __PAIR64__((unsigned int)v5, (unsigned int)psc);
  pthis->__vftable = (CMaterialVar_vtbl *)&GASPrototype<GASGlowFilterObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(pthis->m_VecVal.y) = &GASGlowFilterProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)pthis + 52) = &GASGlowFilterProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)pthis + 208),
    a2: (int)pthis,
    pthis,
    psc: v7);
  pthis->__vftable = (CMaterialVar_vtbl *)&GASPrototype<GASGlowFilterObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(pthis->m_VecVal.y) = &GASGlowFilterProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)pthis + 52) = &GASGlowFilterProto::`vftable';
  HIBYTE(pprototype) = 0;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)pthis + 52,
    a2: (int)pthis,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)GASGlowFilterProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&pprototype + 3));
  return pthis;
}

//------------------------------------------------------------------------------
// Address: 0x10131DB0
// Name: public: static class GASFunctionRef GASGlowFilterCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__usercall GASGlowFilterCtorFunction::Register@<eax>(
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
  CMaterialVar *v12; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  CMaterialVar *v14; // ebx
  const char *MinVal; // edx
  GASValue *v16; // eax
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
      a3: (void (__cdecl *)(const struct GASFnCall *))GASGlowFilterCtorFunction::GlobalCtor);
    v7->dwSize = (unsigned int)&GASGlowFilterCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
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
  v12 = (CMaterialVar *)v11(a1: v10, a2: 240, &a3);
  if ( v12 != nullptr )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v3,
                                                      result: (vc_attributes::InvalidCheckAttribute *)0x25);
    v14 = GASGlowFilterProto::GASGlowFilterProto(
            pthis: v12,
            psc: (GASGlobalContext **)&v23,
            pprototype: Prototype,
            a4: a2);
  }
  else
  {
    v14 = nullptr;
  }
  if ( v14 != nullptr )
    v14->m_intVal = (v14->m_intVal + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v3, (int)a2, a3: 39, a4: (int)v14);
  MinVal = v3[56].MinVal;
  HIBYTE(a3) = 0;
  v25 = *((struct GASFunctionRef **)MinVal + 4);
  v16 = GASValue::GASValue(this: &v19, (int)a2, a3: a2);
  (*((void (__thiscall **)(const char *, vc_attributes::PreRangeAttribute **, const char **, GASValue *, char *))v25 + 10))(
    a1: v3[56].MinVal + 16,
    a2: &v23,
    a3: &v3[13].MaxVal,
    a4: v16,
    a5: (char *)&a3 + 3);
  GASValue::~GASValue(this: &v19, (int)a2);
  if ( v14 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v14, (int)a2);
  return a2;
}
