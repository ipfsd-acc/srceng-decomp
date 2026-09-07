// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cycleproxy.cpp
// Functions: 3
// ============================================================

#include "game\client\cycleproxy.h"

//------------------------------------------------------------------------------
// Address: 0x100C54B0
// Name: public: virtual bool CCycleMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCycleMaterialProxy::Init(CCycleMaterialProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  KeyValues *v5; // ecx
  const char *String; // edi
  IMaterialVar *v7; // eax
  bool v8; // zf
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax

  v3 = pKeyValues;
  v5 = pKeyValues;
  this->m_pMaterial = pMaterial;
  String = KeyValues::GetString(this: v5, keyName: "resultVar", defaultValue: nullptr);
  if ( String == nullptr )
    return 0;
  v7 = this->m_pMaterial->FindVar(this: this->m_pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 1);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_pResult = v7;
  if ( v8 )
  {
    this->m_pResult = nullptr;
    return 0;
  }
  if ( _V_stricmp(s1: String, s2: "$alpha") == 0 )
    pMaterial->SetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_ALPHA_MODIFIED_BY_PROXY, a3: true);
  v10 = KeyValues::GetString(this: v3, keyName: "easein", defaultValue: nullptr);
  if ( v10 != nullptr && (unsigned int)V_atoi(str: v10) != 0 )
    this->m_bEaseIn = true;
  v11 = KeyValues::GetString(this: v3, keyName: "easeout", defaultValue: nullptr);
  if ( v11 != nullptr && (unsigned int)V_atoi(str: v11) != 0 )
    this->m_bEaseOut = true;
  v12 = KeyValues::GetString(this: v3, keyName: "start", defaultValue: nullptr);
  if ( v12 != nullptr )
    this->m_fStart = V_atof(str: v12);
  v13 = KeyValues::GetString(this: v3, keyName: "end", defaultValue: nullptr);
  if ( v13 != nullptr )
    this->m_fEnd = V_atof(str: v13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C55B0
// Name: public: virtual void CCycleMaterialProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCycleMaterialProxy::OnBind(CCycleMaterialProxy *this, C_BaseEntity *pC_BaseEntity)
{
  C_BaseAnimating *v3; // eax
  float m_fStart; // xmm2_4
  float m_fEnd; // xmm1_4
  __m128 m_Val_low; // xmm0
  float v7; // xmm0_4
  __m128 v8; // xmm1
  __m128i v9; // xmm0
  __m128i v10; // xmm0
  IMaterialVar *m_pResult; // ecx
  int v12; // esi
  int v13; // eax
  IMaterialVar *v14; // ecx
  Vector4D vec; // [esp+8h] [ebp-10h] BYREF
  int f; // [esp+20h] [ebp+8h]

  if ( pC_BaseEntity == nullptr )
    return;
  v3 = pC_BaseEntity->GetBaseAnimating(this: pC_BaseEntity);
  if ( v3 == nullptr )
    return;
  m_fStart = this->m_fStart;
  m_fEnd = this->m_fEnd;
  m_Val_low = (__m128)LODWORD(v3->m_flCycle.m_Val);
  if ( m_fStart == m_fEnd )
  {
    v7 = m_Val_low.m128_f32[0] - m_fEnd;
    v8 = 0;
    if ( v7 >= 0.0 )
    {
      m_Val_low = (__m128)0x3F800000u;
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  m_Val_low.m128_f32[0] = (float)(m_Val_low.m128_f32[0] - m_fStart) / (float)(m_fEnd - m_fStart);
  v8 = 0;
  if ( m_Val_low.m128_f32[0] < 0.0 || (v8 = (__m128)0x3F800000u, m_Val_low.m128_f32[0] > 1.0) )
LABEL_8:
    m_Val_low = v8;
LABEL_9:
  f = m_Val_low.m128_i32[0];
  if ( this->m_bEaseIn )
  {
    if ( this->m_bEaseOut )
    {
      m_Val_low.m128_f32[0] = (float)((float)(m_Val_low.m128_f32[0] * m_Val_low.m128_f32[0]) * 3.0)
                            - (float)((float)((float)(m_Val_low.m128_f32[0] * m_Val_low.m128_f32[0]) * 2.0)
                                    * m_Val_low.m128_f32[0]);
    }
    else
    {
      v9 = (__m128i)_mm_cvtps_pd(m_Val_low);
      *(double *)v9.m128i_i64 = *(double *)v9.m128i_i64 * 3.141592653589793 * 0.5;
      __libm_sse2_sin(X: v9);
      m_Val_low.m128_f32[0] = *(double *)m_Val_low.m128_u64;
    }
    goto LABEL_15;
  }
  if ( this->m_bEaseOut )
  {
    v10 = (__m128i)_mm_cvtps_pd(m_Val_low);
    *(double *)v10.m128i_i64 = *(double *)v10.m128i_i64 * 3.141592653589793 * 0.5 + 1.570796326794897;
    __libm_sse2_sin(X: v10);
    m_Val_low.m128_f32[0] = 1.0 - *(double *)m_Val_low.m128_u64;
LABEL_15:
    f = m_Val_low.m128_i32[0];
  }
  m_pResult = this->m_pResult;
  v12 = *((_BYTE *)m_pResult + 28) & 0xF;
  v13 = 1;
  if ( v12 == 2 )
  {
    v13 = m_pResult->VectorSizeInternal(this: m_pResult);
    m_Val_low.m128_i32[0] = f;
  }
  v14 = this->m_pResult;
  if ( v12 == 2 )
  {
    LODWORD(vec.x) = m_Val_low.m128_i32[0];
    LODWORD(vec.y) = m_Val_low.m128_i32[0];
    LODWORD(vec.z) = m_Val_low.m128_i32[0];
    LODWORD(vec.w) = m_Val_low.m128_i32[0];
    v14->SetVecValue_4(this: v14, a2: &vec.x, a3: v13);
  }
  else
  {
    ((void (__stdcall *)(int))v14->SetFloatValue)(a1: m_Val_low.m128_i32[0]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5730
// Name: CCCycleMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCCycleMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result[4].__vftable = nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CCycleMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  LOWORD(result[3].__vftable) = 0;
  result[5].__vftable = (IMaterialProxy_vtbl *)1065353216;
  return result;
}
