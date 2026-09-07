// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/texturescrollmaterialproxy.cpp
// Functions: 3
// ============================================================

#include "game\client\texturescrollmaterialproxy.h"

//------------------------------------------------------------------------------
// Address: 0x1017A110
// Name: public: virtual bool CTextureScrollMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextureScrollMaterialProxy::Init(
        CTextureScrollMaterialProxy *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  char *String; // eax
  IMaterialVar *v7; // eax
  bool v8; // zf

  v3 = pKeyValues;
  String = KeyValues::GetString(this: pKeyValues, keyName: "textureScrollVar", defaultValue: prType);
  if ( String == nullptr )
    return 0;
  v7 = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 0);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_pTextureScrollVar = v7;
  if ( v8 )
    return 0;
  CFloatInput::Init(
    this: &this->m_TextureScrollRate,
    pMaterial,
    pKeyValues: v3,
    pKeyName: "textureScrollRate",
    flDefault: 1.0);
  CFloatInput::Init(
    this: &this->m_TextureScrollAngle,
    pMaterial,
    pKeyValues: v3,
    pKeyName: "textureScrollAngle",
    flDefault: 0.0);
  CFloatInput::Init(this: &this->m_TextureScale, pMaterial, pKeyValues: v3, pKeyName: "textureScale", flDefault: 1.0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017A1C0
// Name: CCTextureScrollMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCTextureScrollMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0x2Cu);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CTextureScrollMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A1E0
// Name: public: virtual void CTextureScrollMaterialProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureScrollMaterialProxy::OnBind(CTextureScrollMaterialProxy *this, void *pC_BaseEntity)
{
  float v3; // xmm1_4
  __m128i v4; // xmm0
  double v5; // xmm0_8
  float v6; // xmm2_4
  double v7; // xmm0_8
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  IMaterialVar *m_pTextureScrollVar; // ecx
  VMatrix mat; // [esp+10h] [ebp-58h] BYREF
  unsigned __int64 v13; // [esp+50h] [ebp-18h]
  unsigned int scale; // [esp+58h] [ebp-10h]
  float sOffset; // [esp+5Ch] [ebp-Ch]
  float rate; // [esp+60h] [ebp-8h]
  unsigned int angle; // [esp+64h] [ebp-4h]

  if ( this->m_pTextureScrollVar != nullptr )
  {
    rate = CFloatInput::GetFloat(this: &this->m_TextureScrollRate);
    *(float *)&angle = CFloatInput::GetFloat(this: &this->m_TextureScrollAngle);
    *(float *)&scale = CFloatInput::GetFloat(this: &this->m_TextureScale);
    v3 = *(float *)(gpGlobals.m_Index + 12);
    v4 = (__m128i)_mm_cvtps_pd((__m128)angle);
    *(double *)v4.m128i_i64 = *(double *)v4.m128i_i64 * 0.0174532925199433;
    v13 = v4.m128i_i64[0];
    *(float *)&angle = v3;
    __libm_sse2_cos(X: v4);
    *(float *)&v5 = v5 * v3 * rate;
    sOffset = *(float *)&v5;
    __libm_sse2_sin(X: (__m128i)v13);
    v6 = sOffset;
    v8 = v7 * v3 * rate;
    if ( sOffset < 0.0 )
      v6 = sOffset + (float)(1.0 - (float)(int)sOffset);
    if ( v8 < 0.0 )
      v8 = v8 + (float)(1.0 - (float)(int)v8);
    v9 = v6 - (float)(int)v6;
    v10 = v8 - (float)(int)v8;
    m_pTextureScrollVar = this->m_pTextureScrollVar;
    if ( (*((_BYTE *)m_pTextureScrollVar + 28) & 0xF) == 7 )
    {
      *(_QWORD *)&mat.m[0][0] = scale;
      mat.m[0][2] = 0.0;
      mat.m[0][3] = v9;
      mat.m[1][0] = 0.0;
      *(_QWORD *)&mat.m[1][1] = scale;
      mat.m[1][3] = v10;
      *(_QWORD *)&mat.m[2][0] = 0;
      *(_QWORD *)&mat.m[2][2] = 1065353216;
      *(_QWORD *)&mat.m[3][0] = 0;
      *(_QWORD *)&mat.m[3][2] = 0x3F80000000000000LL;
      m_pTextureScrollVar->SetMatrixValue(this: m_pTextureScrollVar, a2: &mat);
    }
    else
    {
      ((void (__thiscall *)(IMaterialVar *, float, float, _DWORD))m_pTextureScrollVar->SetVecValue_2)(
        a1: m_pTextureScrollVar,
        a2: COERCE_FLOAT(LODWORD(v9)),
        a3: COERCE_FLOAT(LODWORD(v10)),
        a4: 0);
    }
  }
}
