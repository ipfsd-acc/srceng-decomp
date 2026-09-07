// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasdropshadowfilter.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasdropshadowfilter.h"

//------------------------------------------------------------------------------
// Address: 0x1012FC40
// Name: public: virtual enum GASObjectInterface::ObjectType GASDropShadowFilterObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GASDropShadowFilterObject::GetObjectType(GFxAmpServer *this)
{
  return 38;
}

//------------------------------------------------------------------------------
// Address: 0x1012FC50
// Name: public: virtual bool GASDropShadowFilterObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASDropShadowFilterObject::GetMember(
        GFxAmpServer *this,
        GString *result,
        unsigned __int64 penv)
{
  const char *v3; // edi
  unsigned __int8 CurveTolerance_high; // al
  double v6; // st7
  int v8; // edi
  double v9; // st7
  unsigned int v10; // ebx

  v3 = **(const char ***)penv;
  if ( strcmp(v3, (const char *)&stru_1029DF5C) == 0 )
  {
    CurveTolerance_high = HIBYTE(this->CurrentState.CurveTolerance);
    if ( CurveTolerance_high != 0 )
      v6 = (double)CurveTolerance_high / 255.0;
    else
      v6 = 0.0;
    if ( *(_BYTE *)HIDWORD(penv) >= 5u )
      GASValue::DropRefs(this: (GASValue *)HIDWORD(penv), a2: (int)v3);
    *(float *)&penv = v6;
    *(double *)(HIDWORD(penv) + 4) = *(float *)&penv;
    *(_BYTE *)HIDWORD(penv) = 3;
    return 1;
  }
  else if ( strcmp(**(const char ***)penv, (const char *)&stru_102A7C68.m_Size) == 0 )
  {
    v8 = SHIWORD(this->CurrentState.ConnectedApp.HeapTypeBits) / 10;
    if ( *(_BYTE *)HIDWORD(penv) >= 5u )
      GASValue::DropRefs(this: (GASValue *)HIDWORD(penv), a2: v8);
    *(_DWORD *)(HIDWORD(penv) + 4) = v8;
    *(_BYTE *)HIDWORD(penv) = 4;
    return 1;
  }
  else
  {
    if ( strcmp(**(const char ***)penv, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
    {
      v9 = *(float *)&this->CurrentState.StrokeType.pData;
    }
    else
    {
      if ( !GASString::operator==(this: (const char ***)penv, a2: (const char *)&stru_1029E0D4) )
      {
        if ( GASString::operator==(this: (const char ***)penv, a2: "color") )
        {
          GASValue::SetInt(
            this: SHIDWORD(penv),
            result: (tagCOMPAREITEMSTRUCT *)(LODWORD(this->CurrentState.CurveTolerance) & 0xFFFFFF));
          return 1;
        }
        if ( GASString::operator==(this: (const char ***)penv, a2: (const char *)&stru_102A6D0C) )
        {
          GASValue::SetInt(
            this: SHIDWORD(penv),
            result: (tagCOMPAREITEMSTRUCT *)(SLOWORD(this->CurrentState.ConnectedFile.pData) / 20));
          return 1;
        }
        if ( GASString::operator==(this: (const char ***)penv, a2: (const char *)&stru_102A7C68) )
        {
          LOBYTE(v10) = LOBYTE(this->CurrentState.ConnectedApp.pData) >> 6;
        }
        else if ( GASString::operator==(this: (const char ***)penv, a2: (const char *)&stru_102A7C54.m_Size) )
        {
          v10 = this->CurrentState.AaMode.HeapTypeBits >> 9;
        }
        else
        {
          if ( !GASString::operator==(this: (const char ***)penv, a2: (const char *)&stru_102A7C54) )
          {
            if ( GASString::operator==(this: (const char ***)penv, a2: (const char *)&stru_102A7C40.m_Size) )
            {
              GASValue::SetInt(
                this: SHIDWORD(penv),
                result: (tagCOMPAREITEMSTRUCT *)this->CurrentState.Locales.Data.Data);
              return 1;
            }
            else if ( GASString::operator==(this: (const char ***)penv, a2: (const char *)&stru_102A7C40) )
            {
              GASValue::SetNumber(this: (GASValue *)HIDWORD(penv), a2: this->CurrentState.CurveToleranceMax);
              return 1;
            }
            else
            {
              return (unsigned __int8)GASObject::GetMember(
                                        (D3DXQUATERNION *)this,
                                        (ID3DXFont *)result,
                                        (_IMAGE_SYMBOL_EX *)penv,
                                        val: (int *)HIDWORD(penv));
            }
          }
          LOBYTE(v10) = LOBYTE(this->CurrentState.ConnectedApp.pData) >> 5;
        }
        GASValue::DropRefs(this: (GASValue *)HIDWORD(penv), a2: (int)v3);
        *(_BYTE *)(HIDWORD(penv) + 4) = v10 & 1;
        *(_BYTE *)HIDWORD(penv) = 2;
        return 1;
      }
      v9 = *(float *)&this->CurrentState.CurrentLocale.pData;
    }
    if ( *(_BYTE *)HIDWORD(penv) >= 5u )
      GASValue::DropRefs(this: (GASValue *)HIDWORD(penv), a2: (int)v3);
    *(float *)&penv = v9;
    *(double *)(HIDWORD(penv) + 4) = *(float *)&penv;
    *(_BYTE *)HIDWORD(penv) = 3;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130080
// Name: public: virtual class GASObject __near * GASDropShadowFilterCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASBitmapFilterObject *__stdcall GASDropShadowFilterCtorFunction::CreateNewObject(int result)
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
    a3: (enum FilterType)0,
    blurMode: (struct GFxSocketImplFactory *)2);
  *v5 = (GASBitmapFilterObject)&GASDropShadowFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v5[4] = (GASBitmapFilterObject)&GASDropShadowFilterObject::`vftable'{for `GASObjectInterface'};
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101300E0
// Name: public: virtual bool GASDropShadowFilterObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASDropShadowFilterObject::SetMember(
        GFxAmpServer *this@<ecx>,
        long double a2@<st0>,
        _SERVICE_STATUS *result,
        const char ***penv,
        tagWNDCLASSW *val,
        char *flags)
{
  const char *v6; // edi
  __int16 v8; // ax
  double v9; // st7
  int v10; // eax
  char CurveTolerance_high; // cl
  __int16 v12; // dx
  double pData_low; // [esp+Ch] [ebp-10h]
  double v14; // [esp+Ch] [ebp-10h]
  float v15; // [esp+14h] [ebp-8h]
  unsigned int v16; // [esp+18h] [ebp-4h]
  float v17; // [esp+24h] [ebp+8h]
  float v18; // [esp+24h] [ebp+8h]
  float vala; // [esp+2Ch] [ebp+10h]
  float valb; // [esp+2Ch] [ebp+10h]
  float valc; // [esp+2Ch] [ebp+10h]
  float vald; // [esp+2Ch] [ebp+10h]
  float vale; // [esp+2Ch] [ebp+10h]

  v6 = **penv;
  if ( strcmp(v6, (const char *)&stru_1029DF5C) == 0 )
  {
    vala = GASValue::ToNumber(this: (GASValue *)val, a2: (int)v6, a3: a2, result);
    HIBYTE(this->CurrentState.CurveTolerance) = (int)(vala * 255.0);
    return;
  }
  if ( strcmp(**penv, (const char *)&stru_102A7C68.m_Size) == 0 )
  {
    v8 = GASValue::ToInt32(this: (GASValue *)val, a2: (int)v6, a3: a2, a4: result);
    HIWORD(this->CurrentState.ConnectedApp.HeapTypeBits) = 10 * v8;
    valb = (double)(__int16)(10 * v8) * 3.141592741012573 / 1800.0;
    pData_low = (double)SLOWORD(this->CurrentState.ConnectedFile.pData);
    v17 = cos(valb);
    v15 = v17 * pData_low * 0.05000000074505806;
    valc = sin(valb);
    v9 = valc * pData_low;
LABEL_5:
    *(float *)&v16 = v9 * 0.05000000074505806;
    *(float *)&this->CurrentState.Locales.Data.Size = v15;
    this->CurrentState.Locales.Data.Policy.Capacity = v16;
    return;
  }
  if ( strcmp(**penv, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
  {
    *(float *)&this->CurrentState.StrokeType.pData = GASValue::ToNumber(
                                                       this: (GASValue *)val,
                                                       a2: (int)v6,
                                                       a3: a2,
                                                       result);
  }
  else if ( GASString::operator==(this: penv, a2: (const char *)&stru_1029E0D4) )
  {
    *(float *)&this->CurrentState.CurrentLocale.pData = GASValue::ToNumber(
                                                          this: (GASValue *)val,
                                                          a2: (int)v6,
                                                          a3: a2,
                                                          result);
  }
  else if ( GASString::operator==(this: penv, a2: "color") )
  {
    v10 = GASValue::ToUInt32(this: (GASValue *)val, a2: (int)v6, a3: a2, a4: result);
    CurveTolerance_high = HIBYTE(this->CurrentState.CurveTolerance);
    LODWORD(this->CurrentState.CurveTolerance) = v10;
    HIBYTE(this->CurrentState.CurveTolerance) = CurveTolerance_high;
  }
  else
  {
    if ( GASString::operator==(this: penv, a2: (const char *)&stru_102A6D0C) )
    {
      v12 = 20 * GASValue::ToInt32(this: (GASValue *)val, a2: (int)v6, a3: a2, a4: result);
      LOWORD(this->CurrentState.ConnectedFile.pData) = v12;
      vald = (double)SHIWORD(this->CurrentState.ConnectedApp.HeapTypeBits) * 3.141592741012573 / 1800.0;
      v14 = (double)v12;
      v18 = cos(vald);
      v15 = v18 * v14 * 0.05000000074505806;
      vale = sin(vald);
      v9 = vale * v14;
      goto LABEL_5;
    }
    if ( GASString::operator==(this: penv, a2: (const char *)&stru_102A7C68) )
    {
      if ( GASValue::ToBool(a1: (char *)val, a2, (tagPOLYTEXTW *)result) != 0 )
      {
        LOBYTE(this->CurrentState.ConnectedApp.pData) |= 0x40u;
        this->CurrentState.AaMode.HeapTypeBits |= 0x400u;
      }
      else
      {
        LOBYTE(this->CurrentState.ConnectedApp.pData) &= ~0x40u;
        this->CurrentState.AaMode.HeapTypeBits &= ~0x400u;
      }
    }
    else if ( GASString::operator==(this: penv, a2: (const char *)&stru_102A7C54.m_Size) )
    {
      if ( GASValue::ToBool(a1: (char *)val, a2, (tagPOLYTEXTW *)result) != 0 )
        this->CurrentState.AaMode.HeapTypeBits |= 0x200u;
      else
        this->CurrentState.AaMode.HeapTypeBits &= ~0x200u;
    }
    else if ( GASString::operator==(this: penv, a2: (const char *)&stru_102A7C54) )
    {
      if ( GASValue::ToBool(a1: (char *)val, a2, (tagPOLYTEXTW *)result) != 0 )
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
    else if ( GASString::operator==(this: penv, a2: (const char *)&stru_102A7C40.m_Size) )
    {
      this->CurrentState.Locales.Data.Data = (GString *)(__int64)GASValue::ToNumber(
                                                                   this: (GASValue *)val,
                                                                   a2: (int)v6,
                                                                   a3: a2,
                                                                   result);
    }
    else if ( GASString::operator==(this: penv, a2: (const char *)&stru_102A7C40) )
    {
      this->CurrentState.CurveToleranceMax = GASValue::ToNumber(this: (GASValue *)val, a2: (int)v6, a3: a2, result);
    }
    else
    {
      GASObject::SetMember(
        (CTSQueue<CFunctor *,0,1> *)this,
        a2: (GASEnvironment *)result,
        name: (_IMAGE_SYMBOL_EX *)penv,
        pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
        pmember: flags);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101304B0
// Name: protected: GASDropShadowFilterObject::GASDropShadowFilterObject(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
GASDropShadowFilterObject *__userpurge GASDropShadowFilterObject::GASDropShadowFilterObject@<eax>(
        GASDropShadowFilterObject *this@<ecx>,
        int a2@<edi>,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *a4)
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
  *(_DWORD *)this = &GASDropShadowFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASDropShadowFilterObject::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 15) = 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10130530
// Name: public: static void GASDropShadowFilterProto::Clone(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASDropShadowFilterProto::Clone(GASFnCall *a1)
{
  GASFnCall v1; // ebx
  int *p_cxItem; // ebx
  struct GASObject *v3; // esi

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x26u) )
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
               a4: (const struct GASString *)(a1[6][3].cbSize + 160),
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
    GASFnCall::ThisPtrError(this: a1, a2: "DropShadowFilter", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101305B0
// Name: public: static void GASDropShadowFilterCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASDropShadowFilterCtorFunction::GlobalCtor(unsigned __int16 fn, _CONNECTDLGSTRUCTW fna)
{
  unsigned int cbStructure; // esi
  int v3; // eax
  int v4; // edi
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // eax
  GASBitmapFilterObject *v7; // eax
  double v8; // st7
  GASValue *v9; // eax
  __int16 v10; // ax
  long double v11; // st7
  GASValue *v12; // eax
  __int16 v13; // ax
  long double v14; // st7
  GASValue *v15; // eax
  int v16; // eax
  long double v17; // st7
  char v18; // cl
  GASValue *v19; // eax
  long double v20; // st7
  GASValue *v21; // eax
  double v22; // st7
  GASValue *v23; // eax
  double v24; // st7
  GASValue *v25; // eax
  double v26; // st7
  GASValue *v27; // eax
  double v28; // st7
  char *v29; // eax
  long double v30; // st7
  char *v31; // eax
  long double v32; // st7
  char *v33; // eax
  int v34; // esi
  int v35; // eax
  int *v36; // esi
  int v37; // eax
  bool v38; // zf
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  _SERVICE_STATUS *v60; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v61; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v62; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v63; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v64; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v65; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v66; // [esp-4h] [ebp-2Ch]
  _SERVICE_STATUS *v67; // [esp-4h] [ebp-2Ch]
  tagPOLYTEXTW *v68; // [esp-4h] [ebp-2Ch]
  tagPOLYTEXTW *v69; // [esp-4h] [ebp-2Ch]
  tagPOLYTEXTW *v70; // [esp-4h] [ebp-2Ch]
  GASValue v71[2]; // [esp+Ch] [ebp-1Ch] BYREF
  double v72; // [esp+14h] [ebp-14h]
  int v73; // [esp+1Ch] [ebp-Ch] BYREF
  float v74; // [esp+20h] [ebp-8h]
  float v75; // [esp+24h] [ebp-4h] BYREF

  cbStructure = fna.cbStructure;
  if ( *(_DWORD *)(fna.cbStructure + 8) == 0
    || (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fna.cbStructure + 8) + 8))(a1: *(_DWORD *)(fna.cbStructure + 8)) != 38 )
  {
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 656);
    v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
    v73 = 323;
    v7 = (GASBitmapFilterObject *)v6(a1: v5, a2: 208, a3: &v73);
    v4 = (int)v7;
    if ( v7 != nullptr )
    {
      GASBitmapFilterObject::GASBitmapFilterObject(
        this: v7,
        a2: *(struct GASEnvironment **)(cbStructure + 24),
        a3: (enum FilterType)0,
        blurMode: (struct GFxSocketImplFactory *)2);
      *(_DWORD *)v4 = &GASDropShadowFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(v4 + 16) = &GASDropShadowFilterObject::`vftable'{for `GASObjectInterface'};
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  v3 = *(_DWORD *)(cbStructure + 8);
  if ( v3 == 0 )
  {
LABEL_8:
    v4 = 0;
    goto LABEL_9;
  }
  v4 = v3 - 16;
  if ( v3 != 16 )
    *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
LABEL_9:
  GASValue::SetAsObject(this: *(GASValue **)(cbStructure + 4), a2: (struct GASObject *)v4);
  *(_WORD *)(v4 + 56) = 80;
  *(_DWORD *)(v4 + 72) = 1;
  fna.cbStructure = *(__int16 *)(v4 + 54);
  *(float *)&fna.cbStructure = (double)(int)fna.cbStructure * 3.141592741012573 / 1800.0;
  v72 = (double)80;
  v75 = cos(*(float *)&fna.cbStructure);
  v74 = v75 * v72 * 0.05000000074505806;
  *(float *)&fna.cbStructure = sin(*(float *)&fna.cbStructure);
  v8 = *(float *)&fna.cbStructure * v72;
  fna.cbStructure = 450;
  v75 = v8 * 0.05000000074505806;
  *(float *)(v4 + 76) = v74;
  *(float *)(v4 + 80) = v75;
  *(_WORD *)(v4 + 54) = 450;
  LODWORD(v75) = *(__int16 *)(v4 + 56);
  *(float *)&fna.cbStructure = (double)(int)fna.cbStructure * 3.141592741012573 / 1800.0;
  v72 = (double)SLODWORD(v75);
  v75 = cos(*(float *)&fna.cbStructure);
  v74 = v75 * v72 * 0.05000000074505806;
  *(float *)&fna.cbStructure = sin(*(float *)&fna.cbStructure);
  v75 = *(float *)&fna.cbStructure * v72 * 0.05000000074505806;
  *(float *)(v4 + 76) = v74;
  *(float *)(v4 + 80) = v75;
  *(_DWORD *)(v4 + 84) = 0;
  *(_BYTE *)(v4 + 52) &= 0x9Fu;
  *(_DWORD *)(v4 + 60) &= 0xFFFFFAFF;
  *(float *)(v4 + 64) = 4.0;
  *(float *)(v4 + 68) = 4.0;
  *(_BYTE *)(v4 + 87) = -1;
  *(float *)(v4 + 92) = 1.0;
  if ( *(int *)(cbStructure + 28) > 0 )
  {
    v60 = *(_SERVICE_STATUS **)(cbStructure + 24);
    v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
    v10 = 20 * GASValue::ToInt32(this: v9, a2: v4, a3: 1.0, a4: v60);
    *(_WORD *)(v4 + 56) = v10;
    fna.cbStructure = *(__int16 *)(v4 + 54);
    *(float *)&fna.cbStructure = (double)(int)fna.cbStructure * 3.141592741012573 / 1800.0;
    v72 = (double)v10;
    v75 = cos(*(float *)&fna.cbStructure);
    v74 = v75 * v72 * 0.05000000074505806;
    *(float *)&fna.cbStructure = sin(*(float *)&fna.cbStructure);
    v75 = *(float *)&fna.cbStructure * v72 * 0.05000000074505806;
    *(float *)(v4 + 76) = v74;
    v11 = v75;
    *(float *)(v4 + 80) = v75;
    if ( *(int *)(cbStructure + 28) > 1 )
    {
      v61 = *(_SERVICE_STATUS **)(cbStructure + 24);
      v12 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 1);
      v13 = GASValue::ToInt32(this: v12, a2: v4, a3: v11, a4: v61);
      fna.cbStructure = (__int16)(10 * v13);
      *(_WORD *)(v4 + 54) = 10 * v13;
      LODWORD(v75) = *(__int16 *)(v4 + 56);
      *(float *)&fna.cbStructure = (double)(int)fna.cbStructure * 3.141592741012573 / 1800.0;
      v72 = (double)SLODWORD(v75);
      v75 = cos(*(float *)&fna.cbStructure);
      v74 = v75 * v72 * 0.05000000074505806;
      *(float *)&fna.cbStructure = sin(*(float *)&fna.cbStructure);
      v75 = *(float *)&fna.cbStructure * v72 * 0.05000000074505806;
      *(float *)(v4 + 76) = v74;
      v14 = v75;
      *(float *)(v4 + 80) = v75;
      if ( *(int *)(cbStructure + 28) > 2 )
      {
        v62 = *(_SERVICE_STATUS **)(cbStructure + 24);
        v15 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 2);
        v16 = GASValue::ToUInt32(this: v15, a2: v4, a3: v14, a4: v62);
        v18 = *(_BYTE *)(v4 + 87);
        *(_DWORD *)(v4 + 84) = v16;
        *(_BYTE *)(v4 + 87) = v18;
        if ( *(int *)(cbStructure + 28) > 3 )
        {
          v63 = *(_SERVICE_STATUS **)(cbStructure + 24);
          v19 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 3);
          *(float *)&fna.cbStructure = GASValue::ToNumber(this: v19, a2: v4, a3: v17, result: v63);
          v20 = *(float *)&fna.cbStructure * 255.0;
          LODWORD(v75) = (int)v20;
          *(_BYTE *)(v4 + 87) = (int)v20;
          if ( *(int *)(cbStructure + 28) > 4 )
          {
            v64 = *(_SERVICE_STATUS **)(cbStructure + 24);
            v21 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 4);
            v22 = GASValue::ToNumber(this: v21, a2: v4, a3: v20, result: v64);
            *(float *)(v4 + 64) = v22;
            if ( *(int *)(cbStructure + 28) > 5 )
            {
              v65 = *(_SERVICE_STATUS **)(cbStructure + 24);
              v23 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 5);
              v24 = GASValue::ToNumber(this: v23, a2: v4, a3: v22, result: v65);
              *(float *)(v4 + 68) = v24;
              if ( *(int *)(cbStructure + 28) > 6 )
              {
                v66 = *(_SERVICE_STATUS **)(cbStructure + 24);
                v25 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 6);
                v26 = GASValue::ToNumber(this: v25, a2: v4, a3: v24, result: v66);
                *(float *)(v4 + 92) = v26;
                if ( *(int *)(cbStructure + 28) > 7 )
                {
                  v67 = *(_SERVICE_STATUS **)(cbStructure + 24);
                  v27 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 7);
                  v28 = GASValue::ToNumber(this: v27, a2: v4, a3: v26, result: v67);
                  LODWORD(v75) = HIWORD(fna.cbStructure) | 0xC00;
                  *(_QWORD *)&v72 = (__int64)v28;
                  *(_DWORD *)(v4 + 72) = (__int64)v28;
                  if ( *(int *)(cbStructure + 28) > 8 )
                  {
                    v68 = *(tagPOLYTEXTW **)(cbStructure + 24);
                    v29 = (char *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 8);
                    if ( GASValue::ToBool(a1: v29, a2: v28, result: v68) != 0 )
                      *(_DWORD *)(v4 + 60) |= 0x200u;
                    else
                      *(_DWORD *)(v4 + 60) &= ~0x200u;
                    if ( *(int *)(cbStructure + 28) > 9 )
                    {
                      v69 = *(tagPOLYTEXTW **)(cbStructure + 24);
                      v31 = (char *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 9);
                      if ( GASValue::ToBool(a1: v31, a2: v30, result: v69) != 0 )
                      {
                        *(_BYTE *)(v4 + 52) |= 0x20u;
                        *(_DWORD *)(v4 + 60) |= 0x100u;
                      }
                      else
                      {
                        *(_BYTE *)(v4 + 52) &= ~0x20u;
                        *(_DWORD *)(v4 + 60) &= ~0x100u;
                      }
                      if ( *(int *)(cbStructure + 28) > 10 )
                      {
                        v70 = *(tagPOLYTEXTW **)(cbStructure + 24);
                        v33 = (char *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 10);
                        if ( GASValue::ToBool(a1: v33, a2: v32, result: v70) != 0 )
                        {
                          *(_BYTE *)(v4 + 52) |= 0x40u;
                          *(_DWORD *)(v4 + 60) |= 0x400u;
                        }
                        else
                        {
                          *(_BYTE *)(v4 + 52) &= ~0x40u;
                          *(_DWORD *)(v4 + 60) &= ~0x400u;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v34 = *(_DWORD *)(cbStructure + 24);
  v35 = *(_DWORD *)(v34 + 120);
  v36 = (int *)(v34 + 120);
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v35 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A6D0C,
            a3: 8u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v37 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v37);
  GASValue::~GASValue(this: v71, a2: v4);
  v39 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v39 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C68.m_Size,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v40 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v40);
  GASValue::~GASValue(this: v71, a2: v4);
  v41 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v41 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"color",
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v42 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v42);
  GASValue::~GASValue(this: v71, a2: v4);
  v43 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v43 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DF5C,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v44 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v44);
  GASValue::~GASValue(this: v71, a2: v4);
  v45 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v45 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E0D4.m_Memory.m_nGrowSize,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v46 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v46);
  GASValue::~GASValue(this: v71, a2: v4);
  v47 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v47 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E0D4,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v48 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v48);
  GASValue::~GASValue(this: v71, a2: v4);
  v49 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v49 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C40,
            a3: 8u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v50 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v50);
  GASValue::~GASValue(this: v71, a2: v4);
  v51 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v51 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C54,
            a3: 8u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v52 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v52);
  GASValue::~GASValue(this: v71, a2: v4);
  v53 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v53 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C68,
            a3: 0xAu,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v54 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v54);
  GASValue::~GASValue(this: v71, a2: v4);
  v55 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v55 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C54.m_Size,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v56 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v56);
  GASValue::~GASValue(this: v71, a2: v4);
  v57 = *v36;
  LOBYTE(v71[0]) = 10;
  HIBYTE(fna.cbStructure) = 0;
  v75 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v57 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C40.m_Size,
            a3: 7u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v75) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v4 + 16) + 40))(
    a1: v4 + 16,
    a2: v36,
    a3: &v75,
    a4: v71,
    a5: (char *)&fna.cbStructure + 3);
  v58 = LODWORD(v75);
  v38 = (*(_DWORD *)(LODWORD(v75) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v58);
  GASValue::~GASValue(this: v71, a2: v4);
  return GRefCountBaseGC<323>::Release(a1: v4, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10130DC0
// Name: public: GASDropShadowFilterProto::GASDropShadowFilterProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASDropShadowFilterProto *__thiscall GASDropShadowFilterProto::GASDropShadowFilterProto(
        GASDropShadowFilterProto *this,
        __int64 psc,
        const struct GASFunctionRef *psc_8)
{
  const struct GASFunctionRef *v4; // edx
  __int128 v6; // [esp-8h] [ebp-14h]

  GASDropShadowFilterObject::GASDropShadowFilterObject(
    this,
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
  *(_DWORD *)this = &GASDropShadowFilterProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A7C80;
  *((_DWORD *)this + 52) = off_102A7C7C;
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 208),
    a2: (int)this,
    pthis: (CMaterialVar *)this,
    psc: v6);
  *(_DWORD *)this = &GASDropShadowFilterProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A7C80;
  *((_DWORD *)this + 52) = off_102A7C7C;
  HIBYTE(psc) = 0;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 52,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)GASDropShadowFilterProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&psc + 7));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10130E80
// Name: public: static class GASFunctionRef GASDropShadowFilterCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__usercall GASDropShadowFilterCtorFunction::Register@<eax>(
        int a1@<edi>,
        struct GASFunctionRef *a2,
        _KCRM_MARSHAL_HEADER *pgca)
{
  vc_attributes::PreRangeAttribute *v4; // esi
  int v5; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v7)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASCFunctionObject *v8; // edi
  GASCFunctionObject *v9; // eax
  const char *v11; // ecx
  int (__thiscall *v12)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASDropShadowFilterProto *v13; // ebx
  GASDropShadowFilterProto *v14; // ebx
  const char *MinVal; // edx
  GASValue *v16; // eax
  __int64 v18; // [esp-Ch] [ebp-30h]
  unsigned int Unused; // [esp-4h] [ebp-28h]
  GASValue v20; // [esp+Ch] [ebp-18h] BYREF
  int v21; // [esp+10h] [ebp-14h] BYREF
  int v22; // [esp+14h] [ebp-10h]
  char v23; // [esp+18h] [ebp-Ch]
  vc_attributes::PreRangeAttribute *v24; // [esp+1Ch] [ebp-8h] BYREF
  char v25; // [esp+20h] [ebp-4h]
  struct GASFunctionRef *v26; // [esp+2Ch] [ebp+8h]

  v4 = (vc_attributes::PreRangeAttribute *)pgca;
  Unused = pgca[9].Unused;
  ++*(_DWORD *)(Unused + 8);
  GASGlobalContext::GetBuiltinClassRegistrar(this: v4, a2: Unused);
  if ( v5 == 0 )
  {
    GASBitmapFilterCtorFunction::Register(a1: (struct GASFunctionRef *)&v21, pgc: (_KCRM_MARSHAL_HEADER *)v4);
    if ( (v23 & 2) == 0 && v21 != 0 )
      GRefCountBaseGC<323>::Release(a1: v21, a2: a1);
    v21 = 0;
    if ( (v23 & 1) == 0 && v22 != 0 )
      GRefCountBaseGC<323>::Release(a1: v22, a2: a1);
  }
  MaxVal = v4[54].MaxVal;
  v24 = v4;
  v25 = 8;
  v7 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v8 = (GASCFunctionObject *)v7(a1: MaxVal, a2: 56, a3: &pgca);
  if ( v8 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v8,
      func: (_REASON_CONTEXT *)&v24,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASDropShadowFilterCtorFunction::GlobalCtor);
    v8->dwSize = (unsigned int)&GASDropShadowFilterCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v8->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v9 = v8;
  }
  else
  {
    v9 = nullptr;
  }
  *(_DWORD *)a2 = v9;
  *((_BYTE *)a2 + 8) = 0;
  *((_DWORD *)a2 + 1) = 0;
  v11 = v4[54].MaxVal;
  v12 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)v11 + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v13 = (GASDropShadowFilterProto *)v12(a1: v11, a2: 240, a3: &pgca);
  if ( v13 != nullptr )
  {
    HIDWORD(v18) = GASGlobalContext::GetPrototype(this: v4, result: (vc_attributes::InvalidCheckAttribute *)0x25);
    LODWORD(v18) = &v24;
    v14 = GASDropShadowFilterProto::GASDropShadowFilterProto(this: v13, psc: v18, psc_8: a2);
  }
  else
  {
    v14 = nullptr;
  }
  if ( v14 != nullptr )
    *((_DWORD *)v14 + 2) = (*((_DWORD *)v14 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v4, (int)a2, a3: 38, a4: (int)v14);
  MinVal = v4[56].MinVal;
  HIBYTE(pgca) = 0;
  v26 = *((struct GASFunctionRef **)MinVal + 4);
  v16 = GASValue::GASValue(this: &v20, (int)a2, a3: a2);
  (*((void (__thiscall **)(const char *, vc_attributes::PreRangeAttribute **, const char **, GASValue *, char *))v26 + 10))(
    a1: v4[56].MinVal + 16,
    a2: &v24,
    a3: &v4[13].MinVal,
    a4: v16,
    a5: (char *)&pgca + 3);
  GASValue::~GASValue(this: &v20, (int)a2);
  if ( v14 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v14, (int)a2);
  return a2;
}
