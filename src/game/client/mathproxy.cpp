// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/mathproxy.cpp
// Functions: 42
// ============================================================

#include "game\client\mathproxy.h"

//------------------------------------------------------------------------------
// Address: 0x1011C790
// Name: public: virtual bool CSubtractProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSubtractProxy::Init(CDivideProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CFunctionProxy::Init(this, pMaterial, pKeyValues) != 0 && this->m_pSrc2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011C7C0
// Name: public: virtual bool CClampProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClampProxy::Init(CClampProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CFunctionProxy::Init(this, pMaterial, pKeyValues) != 0
      && CFloatInput::Init(this: &this->m_Min, pMaterial, pKeyValues, pKeyName: "min", flDefault: 0.0)
      && CFloatInput::Init(this: &this->m_Max, pMaterial, pKeyValues, pKeyName: "max", flDefault: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011C830
// Name: public: virtual bool CSineProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSineProxy::Init(CSineProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CResultProxy::Init(this, pMaterial, pKeyValues) != 0
      && CFloatInput::Init(this: &this->m_SinePeriod, pMaterial, pKeyValues, pKeyName: "sinePeriod", flDefault: 1.0)
      && CFloatInput::Init(this: &this->m_SineMax, pMaterial, pKeyValues, pKeyName: "sineMax", flDefault: 1.0)
      && CFloatInput::Init(this: &this->m_SineMin, pMaterial, pKeyValues, pKeyName: "sineMin", flDefault: 0.0)
      && CFloatInput::Init(this: &this->m_SineTimeOffset, pMaterial, pKeyValues, pKeyName: "timeOffset", flDefault: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011C8E0
// Name: public: virtual void CSineProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSineProxy::OnBind(CSineProxy *this, void *pC_BaseEntity)
{
  double Float; // st7
  float v4; // xmm1_4
  __m128 v5; // xmm0
  __m128i v6; // xmm0
  double v7; // xmm0_8
  float flSineMin; // [esp+8h] [ebp-10h]
  float flSineMax; // [esp+Ch] [ebp-Ch]
  float flSineTimeOffset; // [esp+10h] [ebp-8h]
  float flSinePeriod; // [esp+14h] [ebp-4h]

  flSineTimeOffset = CFloatInput::GetFloat(this: &this->m_SineTimeOffset);
  flSineMax = CFloatInput::GetFloat(this: &this->m_SineMax);
  flSineMin = CFloatInput::GetFloat(this: &this->m_SineMin);
  Float = CFloatInput::GetFloat(this: &this->m_SinePeriod);
  if ( Float == 0.0 )
  {
    v4 = 1.0;
  }
  else
  {
    flSinePeriod = Float;
    v4 = flSinePeriod;
  }
  v5 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
  v5.m128_f32[0] = v5.m128_f32[0] - flSineTimeOffset;
  v6 = (__m128i)_mm_cvtps_pd(v5);
  *(double *)v6.m128i_i64 = *(double *)v6.m128i_i64 * 6.283185307179586 / v4;
  __libm_sse2_sin(X: v6);
  CResultProxy::SetFloatResult(
    this,
    result: COERCE_INT((float)((float)(v7 * 0.5 + 0.5) * (float)(flSineMax - flSineMin)) + flSineMin));
}

//------------------------------------------------------------------------------
// Address: 0x1011C9A0
// Name: public: virtual bool CLinearRampProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLinearRampProxy::Init(CLinearRampProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CResultProxy::Init(this, pMaterial, pKeyValues) != 0
      && CFloatInput::Init(this: &this->m_Rate, pMaterial, pKeyValues, pKeyName: "rate", flDefault: 1.0)
      && CFloatInput::Init(this: &this->m_InitialValue, pMaterial, pKeyValues, pKeyName: "initialValue", flDefault: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011CA10
// Name: public: virtual void CLinearRampProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLinearRampProxy::OnBind(CLinearRampProxy *this, void *pC_BaseEntity)
{
  float flValue; // [esp+8h] [ebp-4h]
  int flValuea; // [esp+8h] [ebp-4h]

  flValue = CFloatInput::GetFloat(this: &this->m_Rate) * *(float *)(gpGlobals.m_Index + 12);
  *(float *)&flValuea = CFloatInput::GetFloat(this: &this->m_InitialValue) + flValue;
  CResultProxy::SetFloatResult(this, result: flValuea);
}

//------------------------------------------------------------------------------
// Address: 0x1011CA60
// Name: public: virtual bool CUniformNoiseProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUniformNoiseProxy::Init(CUniformNoiseProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CResultProxy::Init(this, pMaterial, pKeyValues) != 0
      && CFloatInput::Init(this: &this->m_flMinVal, pMaterial, pKeyValues, pKeyName: "minVal", flDefault: 0.0)
      && CFloatInput::Init(this: &this->m_flMaxVal, pMaterial, pKeyValues, pKeyName: "maxVal", flDefault: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011CAD0
// Name: public: virtual void CUniformNoiseProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUniformNoiseProxy::OnBind(CUniformNoiseProxy *this, void *pC_BaseEntity)
{
  IUniformRandomStream_vtbl *v3; // edi
  float Float; // [esp+4h] [ebp-10h]
  float result; // [esp+8h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-Ch]

  v3 = random->__vftable;
  result = CFloatInput::GetFloat(this: &this->m_flMaxVal);
  Float = CFloatInput::GetFloat(this: &this->m_flMinVal);
  *(float *)&v6 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))v3->RandomFloat)(
                    a1: random,
                    a2: LODWORD(Float),
                    a3: LODWORD(result));
  CResultProxy::SetFloatResult(this, result: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1011CB10
// Name: public: virtual bool CGaussianNoiseProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGaussianNoiseProxy::Init(CGaussianNoiseProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CResultProxy::Init(this, pMaterial, pKeyValues) != 0
      && CFloatInput::Init(this: &this->m_Mean, pMaterial, pKeyValues, pKeyName: "mean", flDefault: 0.0)
      && CFloatInput::Init(this: &this->m_StdDev, pMaterial, pKeyValues, pKeyName: "halfwidth", flDefault: 1.0)
      && CFloatInput::Init(this: &this->m_flMinVal, pMaterial, pKeyValues, pKeyName: "minVal", flDefault: -3.4028235e38)
      && CFloatInput::Init(this: &this->m_flMaxVal, pMaterial, pKeyValues, pKeyName: "maxVal", flDefault: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x1011CBC0
// Name: public: virtual void CGaussianNoiseProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGaussianNoiseProxy::OnBind(CGaussianNoiseProxy *this, void *pC_BaseEntity)
{
  double Float; // st7
  float v4; // xmm2_4
  int result; // xmm1_4
  int v6; // xmm0_4
  float flVal; // [esp+10h] [ebp-Ch]
  float flStdDev; // [esp+14h] [ebp-8h]
  float flMeana; // [esp+18h] [ebp-4h]
  float flMean; // [esp+18h] [ebp-4h]

  flMeana = CFloatInput::GetFloat(this: &this->m_Mean);
  flStdDev = CFloatInput::GetFloat(this: &this->m_StdDev);
  flVal = CGaussianRandomStream::RandomFloat(this: randomgaussian, a2: flMeana, a3: flStdDev);
  flMean = CFloatInput::GetFloat(this: &this->m_flMaxVal);
  Float = CFloatInput::GetFloat(this: &this->m_flMinVal);
  if ( Float <= flMean )
  {
    v4 = flMean;
    *(float *)&result = Float;
  }
  else
  {
    v4 = Float;
    *(float *)&result = flMean;
  }
  v6 = LODWORD(flVal);
  if ( *(float *)&result <= flVal )
  {
    if ( flVal > v4 )
      v6 = LODWORD(v4);
    CResultProxy::SetFloatResult(this, result: v6);
  }
  else
  {
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CC80
// Name: public: virtual bool CExponentialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExponentialProxy::Init(CExponentialProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CFunctionProxy::Init(this, pMaterial, pKeyValues) != 0
      && CFloatInput::Init(this: &this->m_Scale, pMaterial, pKeyValues, pKeyName: "scale", flDefault: 1.0)
      && CFloatInput::Init(this: &this->m_Offset, pMaterial, pKeyValues, pKeyName: "offset", flDefault: 0.0)
      && CFloatInput::Init(this: &this->m_flMinVal, pMaterial, pKeyValues, pKeyName: "minVal", flDefault: -3.4028235e38)
      && CFloatInput::Init(this: &this->m_flMaxVal, pMaterial, pKeyValues, pKeyName: "maxVal", flDefault: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x1011CD30
// Name: public: virtual void CExponentialProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExponentialProxy::OnBind(CExponentialProxy *this, void *pC_BaseEntity)
{
  long double v3; // st7
  long double v4; // rt0
  double Float; // st7
  float v6; // xmm2_4
  int result; // xmm1_4
  int v8; // xmm0_4
  float flVal; // [esp+8h] [ebp-Ch]
  float flMinVal; // [esp+Ch] [ebp-8h]
  float flMinVala; // [esp+Ch] [ebp-8h]
  float flMaxVal; // [esp+10h] [ebp-4h]

  flMinVal = this->m_pSrc1->GetFloatValueInternal(this: this->m_pSrc1);
  v3 = (CFloatInput::GetFloat(this: &this->m_Offset) + flMinVal) * 1.442695040888963407;
  v4 = rint(v3);
  flMinVala = __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
  flVal = CFloatInput::GetFloat(this: &this->m_Scale) * flMinVala;
  flMaxVal = CFloatInput::GetFloat(this: &this->m_flMaxVal);
  Float = CFloatInput::GetFloat(this: &this->m_flMinVal);
  if ( Float <= flMaxVal )
  {
    v6 = flMaxVal;
    *(float *)&result = Float;
  }
  else
  {
    v6 = Float;
    *(float *)&result = flMaxVal;
  }
  v8 = LODWORD(flVal);
  if ( *(float *)&result <= flVal )
  {
    if ( flVal > v6 )
      v8 = LODWORD(v6);
    CResultProxy::SetFloatResult(this, result: v8);
  }
  else
  {
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CDF0
// Name: public: virtual void CAbsProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAbsProxy::OnBind(CAbsProxy *this, void *pC_BaseEntity)
{
  int result; // [esp+0h] [ebp-8h]

  *(float *)&result = fabs(((double (__thiscall *)(IMaterialVar *))this->m_pSrc1->GetFloatValueInternal)(a1: this->m_pSrc1));
  CResultProxy::SetFloatResult(this, result);
}

//------------------------------------------------------------------------------
// Address: 0x1011CE10
// Name: public: virtual bool CLessOrEqualProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLessOrEqualProxy::Init(CLessOrEqualProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *String; // eax
  bool result; // al
  IMaterialVar *v7; // eax
  bool v8; // zf
  const char *v9; // eax
  IMaterialVar *v10; // eax

  v3 = pKeyValues;
  String = KeyValues::GetString(this: pKeyValues, keyName: "lessEqualVar", defaultValue: prType);
  if ( String == nullptr )
    return false;
  v7 = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 1);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_pLessVar = v7;
  result = false;
  if ( !v8 )
  {
    v9 = KeyValues::GetString(this: v3, keyName: "greaterVar", defaultValue: prType);
    if ( v9 != nullptr )
    {
      v10 = pMaterial->FindVar(this: pMaterial, a2: v9, a3: (char *)&pKeyValues + 3, a4: 1);
      v8 = HIBYTE(pKeyValues) == 0;
      this->m_pGreaterVar = v10;
      if ( !v8 && CFunctionProxy::Init(this, pMaterial, pKeyValues: v3) != 0 && this->m_pSrc2 != nullptr )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011CEB0
// Name: public: virtual bool CWrapMinMaxProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWrapMinMaxProxy::Init(CWrapMinMaxProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CFunctionProxy::Init(this, pMaterial, pKeyValues) != 0
      && CFloatInput::Init(this: &this->m_flMinVal, pMaterial, pKeyValues, pKeyName: "minVal", flDefault: 0.0)
      && CFloatInput::Init(this: &this->m_flMaxVal, pMaterial, pKeyValues, pKeyName: "maxVal", flDefault: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1011CF20
// Name: public: virtual void CWrapMinMaxProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWrapMinMaxProxy::OnBind(CWrapMinMaxProxy *this, void *pC_BaseEntity)
{
  double v3; // st7
  float v4; // xmm1_4
  int result; // [esp+0h] [ebp-18h]
  float v6; // [esp+10h] [ebp-8h]
  float Float; // [esp+10h] [ebp-8h]
  float flResulta; // [esp+14h] [ebp-4h]
  float flResultb; // [esp+14h] [ebp-4h]
  float flResultc; // [esp+14h] [ebp-4h]
  float flResult; // [esp+14h] [ebp-4h]
  float flResultd; // [esp+14h] [ebp-4h]
  int flResulte; // [esp+14h] [ebp-4h]

  flResulta = CFloatInput::GetFloat(this: &this->m_flMaxVal);
  if ( CFloatInput::GetFloat(this: &this->m_flMinVal) < flResulta )
  {
    flResultb = this->m_pSrc1->GetFloatValueInternal(this: this->m_pSrc1);
    v6 = flResultb - CFloatInput::GetFloat(this: &this->m_flMinVal);
    flResultc = CFloatInput::GetFloat(this: &this->m_flMaxVal);
    v3 = v6 / (flResultc - CFloatInput::GetFloat(this: &this->m_flMinVal));
    flResult = v3;
    if ( v3 < 0.0 )
      v4 = (float)((int)flResult - 1);
    else
      v4 = (float)(int)flResult;
    Float = CFloatInput::GetFloat(this: &this->m_flMaxVal);
    flResultd = (Float - CFloatInput::GetFloat(this: &this->m_flMinVal)) * (float)(flResult - v4);
    *(float *)&flResulte = CFloatInput::GetFloat(this: &this->m_flMinVal) + flResultd;
    CResultProxy::SetFloatResult(this, result: flResulte);
  }
  else
  {
    *(float *)&result = CFloatInput::GetFloat(this: &this->m_flMinVal);
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D010
// Name: public: virtual void CAddProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddProxy::OnBind(CAddProxy *this, void *pC_BaseEntity)
{
  int v3; // edi
  int v4; // eax
  IMaterialVar *m_pResult; // ecx
  int result; // [esp+4h] [ebp-38h]
  Vector c; // [esp+Ch] [ebp-30h] BYREF
  Vector a; // [esp+18h] [ebp-24h] BYREF
  Vector b; // [esp+24h] [ebp-18h] BYREF
  float v10; // [esp+30h] [ebp-Ch]
  MaterialVarType_t resultType; // [esp+34h] [ebp-8h] BYREF
  int vecSize; // [esp+38h] [ebp-4h] BYREF

  CFunctionProxy::ComputeResultType(this, &resultType, &vecSize);
  if ( resultType != MATERIAL_VAR_TYPE_FLOAT )
  {
    if ( resultType == MATERIAL_VAR_TYPE_VECTOR )
    {
      this->m_pSrc1->GetVecValueInternal(this: this->m_pSrc1, a2: (float *)&a, a3: vecSize);
      this->m_pSrc2->GetVecValueInternal(this: this->m_pSrc2, a2: (float *)&b, a3: vecSize);
      m_pResult = this->m_pResult;
      c.x = b.x + a.x;
      c.y = b.y + a.y;
      c.z = b.z + a.z;
      m_pResult->SetVecValue_4(this: m_pResult, a2: &c.x, a3: vecSize);
    }
    else if ( resultType == MATERIAL_VAR_TYPE_INT )
    {
      v3 = this->m_pSrc1->GetIntValueInternal(this: this->m_pSrc1);
      v4 = this->m_pSrc2->GetIntValueInternal(this: this->m_pSrc2);
      ((void (__stdcall *)(_DWORD))this->m_pResult->SetFloatValue)(a1: (float)(v3 + v4));
    }
  }
  else
  {
    v10 = this->m_pSrc1->GetFloatValueInternal(this: this->m_pSrc1);
    *(float *)&result = ((double (__thiscall *)(IMaterialVar *))this->m_pSrc2->GetFloatValueInternal)(a1: this->m_pSrc2)
                      + v10;
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D110
// Name: CCAddProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCAddProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CAddProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011D140
// Name: public: virtual void CSubtractProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubtractProxy::OnBind(CSubtractProxy *this, void *pC_BaseEntity)
{
  int v3; // edi
  int v4; // eax
  IMaterialVar *m_pResult; // ecx
  int result; // [esp+4h] [ebp-38h]
  Vector c; // [esp+Ch] [ebp-30h] BYREF
  Vector b; // [esp+18h] [ebp-24h] BYREF
  Vector a; // [esp+24h] [ebp-18h] BYREF
  float v10; // [esp+30h] [ebp-Ch]
  MaterialVarType_t resultType; // [esp+34h] [ebp-8h] BYREF
  int vecSize; // [esp+38h] [ebp-4h] BYREF

  CFunctionProxy::ComputeResultType(this, &resultType, &vecSize);
  if ( resultType != MATERIAL_VAR_TYPE_FLOAT )
  {
    if ( resultType == MATERIAL_VAR_TYPE_VECTOR )
    {
      this->m_pSrc1->GetVecValueInternal(this: this->m_pSrc1, a2: (float *)&a, a3: vecSize);
      this->m_pSrc2->GetVecValueInternal(this: this->m_pSrc2, a2: (float *)&b, a3: vecSize);
      m_pResult = this->m_pResult;
      c.x = a.x - b.x;
      c.y = a.y - b.y;
      c.z = a.z - b.z;
      m_pResult->SetVecValue_4(this: m_pResult, a2: &c.x, a3: vecSize);
    }
    else if ( resultType == MATERIAL_VAR_TYPE_INT )
    {
      v3 = this->m_pSrc1->GetIntValueInternal(this: this->m_pSrc1);
      v4 = this->m_pSrc2->GetIntValueInternal(this: this->m_pSrc2);
      ((void (__stdcall *)(_DWORD))this->m_pResult->SetFloatValue)(a1: (float)(v3 - v4));
    }
  }
  else
  {
    v10 = this->m_pSrc1->GetFloatValueInternal(this: this->m_pSrc1);
    *(float *)&result = v10
                      - ((double (__thiscall *)(IMaterialVar *))this->m_pSrc2->GetFloatValueInternal)(a1: this->m_pSrc2);
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D240
// Name: CCSubtractProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCSubtractProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CSubtractProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011D270
// Name: public: virtual void CMultiplyProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplyProxy::OnBind(CMultiplyProxy *this, void *pC_BaseEntity)
{
  int v3; // edi
  int v4; // eax
  IMaterialVar *m_pResult; // ecx
  int result; // [esp+4h] [ebp-38h]
  Vector c; // [esp+Ch] [ebp-30h] BYREF
  Vector a; // [esp+18h] [ebp-24h] BYREF
  Vector b; // [esp+24h] [ebp-18h] BYREF
  float v10; // [esp+30h] [ebp-Ch]
  MaterialVarType_t resultType; // [esp+34h] [ebp-8h] BYREF
  int vecSize; // [esp+38h] [ebp-4h] BYREF

  CFunctionProxy::ComputeResultType(this, &resultType, &vecSize);
  if ( resultType != MATERIAL_VAR_TYPE_FLOAT )
  {
    if ( resultType == MATERIAL_VAR_TYPE_VECTOR )
    {
      this->m_pSrc1->GetVecValueInternal(this: this->m_pSrc1, a2: (float *)&a, a3: vecSize);
      this->m_pSrc2->GetVecValueInternal(this: this->m_pSrc2, a2: (float *)&b, a3: vecSize);
      m_pResult = this->m_pResult;
      c.x = b.x * a.x;
      c.y = b.y * a.y;
      c.z = b.z * a.z;
      m_pResult->SetVecValue_4(this: m_pResult, a2: &c.x, a3: vecSize);
    }
    else if ( resultType == MATERIAL_VAR_TYPE_INT )
    {
      v3 = this->m_pSrc1->GetIntValueInternal(this: this->m_pSrc1);
      v4 = this->m_pSrc2->GetIntValueInternal(this: this->m_pSrc2);
      ((void (__stdcall *)(_DWORD))this->m_pResult->SetFloatValue)(a1: (float)(v3 * v4));
    }
  }
  else
  {
    v10 = this->m_pSrc1->GetFloatValueInternal(this: this->m_pSrc1);
    *(float *)&result = ((double (__thiscall *)(IMaterialVar *))this->m_pSrc2->GetFloatValueInternal)(a1: this->m_pSrc2)
                      * v10;
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D380
// Name: CCMultiplyProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCMultiplyProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CMultiplyProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011D3B0
// Name: public: virtual void CDivideProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDivideProxy::OnBind(CDivideProxy *this, void *pC_BaseEntity)
{
  int v3; // eax
  IMaterialVar *m_pSrc1; // ecx
  int v5; // edi
  int v6; // ebx
  float v7; // xmm0_4
  IMaterialVar *m_pResult; // ecx
  double v9; // st7
  double (*GetFloatValueInternal)(void); // edx
  int result; // [esp+8h] [ebp-38h]
  Vector c; // [esp+10h] [ebp-30h] BYREF
  Vector b; // [esp+1Ch] [ebp-24h] BYREF
  Vector a; // [esp+28h] [ebp-18h] BYREF
  float v15; // [esp+34h] [ebp-Ch]
  MaterialVarType_t resultType; // [esp+38h] [ebp-8h] BYREF
  int vecSize; // [esp+3Ch] [ebp-4h] BYREF

  CFunctionProxy::ComputeResultType(this, &resultType, &vecSize);
  if ( resultType != MATERIAL_VAR_TYPE_FLOAT )
  {
    if ( resultType == MATERIAL_VAR_TYPE_VECTOR )
    {
      this->m_pSrc1->GetVecValueInternal(this: this->m_pSrc1, a2: (float *)&a, a3: vecSize);
      this->m_pSrc2->GetVecValueInternal(this: this->m_pSrc2, a2: (float *)&b, a3: vecSize);
      m_pResult = this->m_pResult;
      c.x = a.x / b.x;
      c.y = a.y / b.y;
      c.z = a.z / b.z;
      m_pResult->SetVecValue_4(this: m_pResult, a2: &c.x, a3: vecSize);
    }
    else if ( resultType == MATERIAL_VAR_TYPE_INT )
    {
      v3 = this->m_pSrc2->GetIntValueInternal(this: this->m_pSrc2);
      m_pSrc1 = this->m_pSrc1;
      if ( v3 != 0 )
      {
        v5 = m_pSrc1->GetIntValueInternal(this: m_pSrc1);
        v6 = this->m_pSrc2->GetIntValueInternal(this: this->m_pSrc2);
        ((void (__stdcall *)(_DWORD))this->m_pResult->SetFloatValue)(a1: (float)(v5 / v6));
      }
      else
      {
        v7 = (float)m_pSrc1->GetIntValueInternal(this: m_pSrc1);
        ((void (__stdcall *)(_DWORD))this->m_pResult->SetFloatValue)(a1: LODWORD(v7));
      }
    }
  }
  else
  {
    v9 = ((double (__thiscall *)(IMaterialVar *))this->m_pSrc2->GetFloatValueInternal)(a1: this->m_pSrc2);
    GetFloatValueInternal = (double (*)(void))this->m_pSrc1->GetFloatValueInternal;
    if ( v9 == 0.0 )
    {
      *(float *)&result = GetFloatValueInternal();
    }
    else
    {
      v15 = GetFloatValueInternal();
      *(float *)&result = v15
                        / ((double (__thiscall *)(IMaterialVar *))this->m_pSrc2->GetFloatValueInternal)(a1: this->m_pSrc2);
    }
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D520
// Name: CCDivideProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCDivideProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CDivideProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011D550
// Name: public: virtual void CClampProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClampProxy::OnBind(CClampProxy *this, void *pC_BaseEntity)
{
  double Float; // st7
  float v4; // xmm0_4
  int v5; // eax
  float v6; // xmm1_4
  int v7; // edx
  int v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  double v12; // st7
  float result; // xmm0_4
  Vector a; // [esp+8h] [ebp-20h] BYREF
  float src; // [esp+14h] [ebp-14h]
  MaterialVarType_t resultType; // [esp+18h] [ebp-10h] BYREF
  int vecSize; // [esp+1Ch] [ebp-Ch] BYREF
  float flMax; // [esp+20h] [ebp-8h]
  float flMin; // [esp+24h] [ebp-4h]

  CFunctionProxy::ComputeResultType(this, &resultType, &vecSize);
  flMin = CFloatInput::GetFloat(this: &this->m_Min);
  Float = CFloatInput::GetFloat(this: &this->m_Max);
  flMax = Float;
  if ( flMin > Float )
  {
    v4 = flMin;
    flMin = flMax;
    flMax = v4;
  }
  if ( resultType != MATERIAL_VAR_TYPE_FLOAT )
  {
    if ( resultType == MATERIAL_VAR_TYPE_VECTOR )
    {
      this->m_pSrc1->GetVecValueInternal(this: this->m_pSrc1, a2: (float *)&a, a3: vecSize);
      v7 = vecSize;
      v8 = 0;
      if ( vecSize > 0 )
      {
        v9 = flMin;
        v10 = flMax;
        do
        {
          v11 = *(&a.x + v8);
          if ( v9 <= v11 )
          {
            if ( v11 > v10 )
              *(&a.x + v8) = v10;
          }
          else
          {
            *(&a.x + v8) = v9;
          }
          ++v8;
        }
        while ( v8 < v7 );
      }
      this->m_pResult->SetVecValue_4(this: this->m_pResult, a2: (const float *)&a, a3: v7);
    }
    else if ( resultType == MATERIAL_VAR_TYPE_INT )
    {
      v5 = this->m_pSrc1->GetIntValueInternal(this: this->m_pSrc1);
      v6 = flMin;
      if ( flMin > (float)v5 || (v6 = flMax, (float)v5 > flMax) )
        v5 = (int)v6;
      this->m_pResult->SetIntValue(this: this->m_pResult, a2: v5);
    }
  }
  else
  {
    v12 = ((double (__thiscall *)(IMaterialVar *))this->m_pSrc1->GetFloatValueInternal)(a1: this->m_pSrc1);
    src = v12;
    if ( flMin <= v12 )
    {
      result = src;
      if ( src > flMax )
        result = flMax;
      CResultProxy::SetFloatResult(this, result: SLODWORD(result));
    }
    else
    {
      CResultProxy::SetFloatResult(this, result: SLODWORD(flMin));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D6B0
// Name: CCClampProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCClampProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x2Cu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CClampProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011D6E0
// Name: CCSineProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCSineProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x3Cu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CSineProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011D710
// Name: public: virtual void CEqualsProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEqualsProxy::OnBind(CEqualsProxy *this, void *pC_BaseEntity)
{
  int v3; // eax
  int result; // [esp+0h] [ebp-1Ch]
  Vector a; // [esp+8h] [ebp-14h] BYREF
  MaterialVarType_t resultType; // [esp+14h] [ebp-8h] BYREF
  int vecSize; // [esp+18h] [ebp-4h] BYREF

  CFunctionProxy::ComputeResultType(this, &resultType, &vecSize);
  if ( resultType != MATERIAL_VAR_TYPE_FLOAT )
  {
    if ( resultType == MATERIAL_VAR_TYPE_VECTOR )
    {
      this->m_pSrc1->GetVecValueInternal(this: this->m_pSrc1, a2: (float *)&a, a3: vecSize);
      this->m_pResult->SetVecValue_4(this: this->m_pResult, a2: (const float *)&a, a3: vecSize);
    }
    else if ( resultType == MATERIAL_VAR_TYPE_INT )
    {
      v3 = this->m_pSrc1->GetIntValueInternal(this: this->m_pSrc1);
      this->m_pResult->SetIntValue(this: this->m_pResult, a2: v3);
    }
  }
  else
  {
    *(float *)&result = this->m_pSrc1->GetFloatValueInternal(this: this->m_pSrc1);
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D7A0
// Name: CCEqualsProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCEqualsProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CEqualsProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011D7D0
// Name: public: virtual void CFracProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFracProxy::OnBind(CFracProxy *this, void *pC_BaseEntity)
{
  int v3; // eax
  IMaterialVar *m_pResult; // ecx
  double v5; // st7
  int result; // [esp+0h] [ebp-20h]
  Vector a; // [esp+8h] [ebp-18h] BYREF
  float v8; // [esp+14h] [ebp-Ch]
  MaterialVarType_t resultType; // [esp+18h] [ebp-8h] BYREF
  int vecSize; // [esp+1Ch] [ebp-4h] BYREF

  CFunctionProxy::ComputeResultType(this, &resultType, &vecSize);
  if ( resultType != MATERIAL_VAR_TYPE_FLOAT )
  {
    if ( resultType == MATERIAL_VAR_TYPE_VECTOR )
    {
      this->m_pSrc1->GetVecValueInternal(this: this->m_pSrc1, a2: (float *)&a, a3: vecSize);
      a.x = a.x - (float)(int)a.x;
      m_pResult = this->m_pResult;
      a.y = a.y - (float)(int)a.y;
      a.z = a.z - (float)(int)a.z;
      m_pResult->SetVecValue_4(this: m_pResult, a2: &a.x, a3: vecSize);
    }
    else if ( resultType == MATERIAL_VAR_TYPE_INT )
    {
      v3 = this->m_pSrc1->GetIntValueInternal(this: this->m_pSrc1);
      this->m_pResult->SetIntValue(this: this->m_pResult, a2: v3);
    }
  }
  else
  {
    v5 = ((double (__thiscall *)(IMaterialVar *))this->m_pSrc1->GetFloatValueInternal)(a1: this->m_pSrc1);
    v8 = v5;
    *(float *)&result = v5 - (double)(int)v8;
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D8C0
// Name: CCFracProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCFracProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CFracProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011D8F0
// Name: public: virtual void CIntProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIntProxy::OnBind(CIntProxy *this, void *pC_BaseEntity)
{
  int v3; // eax
  IMaterialVar *m_pResult; // ecx
  int result; // xmm0_4
  Vector a; // [esp+8h] [ebp-14h] BYREF
  MaterialVarType_t resultType; // [esp+14h] [ebp-8h] BYREF
  int vecSize; // [esp+18h] [ebp-4h] BYREF

  CFunctionProxy::ComputeResultType(this, &resultType, &vecSize);
  if ( resultType != MATERIAL_VAR_TYPE_FLOAT )
  {
    if ( resultType == MATERIAL_VAR_TYPE_VECTOR )
    {
      this->m_pSrc1->GetVecValueInternal(this: this->m_pSrc1, a2: (float *)&a, a3: vecSize);
      a.x = (float)(int)a.x;
      m_pResult = this->m_pResult;
      a.y = (float)(int)a.y;
      a.z = (float)(int)a.z;
      m_pResult->SetVecValue_4(this: m_pResult, a2: &a.x, a3: vecSize);
    }
    else if ( resultType == MATERIAL_VAR_TYPE_INT )
    {
      v3 = this->m_pSrc1->GetIntValueInternal(this: this->m_pSrc1);
      this->m_pResult->SetIntValue(this: this->m_pResult, a2: v3);
    }
  }
  else
  {
    *(float *)&result = (float)(int)this->m_pSrc1->GetFloatValueInternal(this: this->m_pSrc1);
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D9D0
// Name: CCIntProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCIntProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CIntProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011DA00
// Name: CCLinearRampProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCLinearRampProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x24u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CLinearRampProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011DA30
// Name: CCUniformNoiseProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCUniformNoiseProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x24u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CUniformNoiseProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011DA60
// Name: CCGaussianNoiseProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCGaussianNoiseProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x3Cu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CGaussianNoiseProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011DA90
// Name: CCExponentialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCExponentialProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x44u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CExponentialProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011DAF0
// Name: CCAbsProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCAbsProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CAbsProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011DB20
// Name: CCEmptyProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCEmptyProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 4u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CEmptyProxy::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011DB40
// Name: public: virtual void CLessOrEqualProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLessOrEqualProxy::OnBind(CLessOrEqualProxy *this, void *pC_BaseEntity)
{
  IMaterialVar *m_pGreaterVar; // ebx
  IMaterialVar *m_pResult; // ecx
  int v5; // esi
  IMaterialVar_vtbl *v6; // eax
  int v7; // esi
  float v8; // xmm0_4
  int result; // [esp+0h] [ebp-20h]
  Vector src; // [esp+10h] [ebp-10h] BYREF
  int vecSize; // [esp+1Ch] [ebp-4h]

  *(float *)&vecSize = this->m_pSrc1->GetFloatValueInternal(this: this->m_pSrc1);
  if ( ((double (__thiscall *)(IMaterialVar *))this->m_pSrc2->GetFloatValueInternal)(a1: this->m_pSrc2) < *(float *)&vecSize )
    m_pGreaterVar = this->m_pGreaterVar;
  else
    m_pGreaterVar = this->m_pLessVar;
  m_pResult = this->m_pResult;
  v5 = *((_BYTE *)m_pResult + 28) & 0xF;
  *(float *)&vecSize = 0.0;
  if ( v5 == 2 )
  {
    if ( this->m_ResultVecComp >= 0 )
      v5 = 0;
    v6 = m_pResult->__vftable;
  }
  else
  {
    if ( v5 != 6 )
      goto LABEL_12;
    v5 = *((_BYTE *)m_pGreaterVar + 28) & 0xF;
    if ( v5 != 2 )
      goto LABEL_12;
    v6 = m_pGreaterVar->__vftable;
  }
  *(float *)&vecSize = COERCE_FLOAT(((int (*)(void))v6->VectorSizeInternal)());
LABEL_12:
  if ( v5 != 0 )
  {
    v7 = v5 - 2;
    if ( v7 != 0 )
    {
      if ( v7 == 2 )
      {
        v8 = (float)m_pGreaterVar->GetIntValueInternal(this: m_pGreaterVar);
        ((void (__stdcall *)(_DWORD))this->m_pResult->SetFloatValue)(a1: LODWORD(v8));
      }
    }
    else
    {
      m_pGreaterVar->GetVecValueInternal(this: m_pGreaterVar, a2: &src.x, a3: vecSize);
      this->m_pResult->SetVecValue_4(this: this->m_pResult, a2: (const float *)&src, a3: vecSize);
    }
  }
  else
  {
    *(float *)&result = m_pGreaterVar->GetFloatValueInternal(this: m_pGreaterVar);
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011DC40
// Name: CCLessOrEqualProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCLessOrEqualProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x1Cu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CLessOrEqualProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011DC70
// Name: CCWrapMinMaxProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCWrapMinMaxProxyFactory()
{
  CFunctionProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CFunctionProxy *)MemAlloc_Alloc(nSize: 0x2Cu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CFunctionProxy::CFunctionProxy(this: v0);
  *v1 = &CWrapMinMaxProxy::`vftable';
  return (IMaterialProxy *)v1;
}
