// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/proxypupil.cpp
// Functions: 3
// ============================================================

#include "game\client\proxypupil.h"

//------------------------------------------------------------------------------
// Address: 0x10159FE0
// Name: public: virtual bool CPupilProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPupilProxy::Init(CPupilProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  char *String; // eax
  IMaterialVar *v7; // eax
  bool v8; // zf
  char *v9; // eax
  IMaterialVar *v10; // eax
  IMaterialVar *v11; // eax

  v3 = pKeyValues;
  String = KeyValues::GetString(this: pKeyValues, keyName: "TextureVar", defaultValue: prType);
  if ( String == nullptr )
    return 0;
  v7 = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 0);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_pAnimatedTextureVar = v7;
  if ( v8 )
    return 0;
  v9 = KeyValues::GetString(this: v3, keyName: "TextureFrameNumVar", defaultValue: prType);
  if ( v9 == nullptr )
    return 0;
  v10 = pMaterial->FindVar(this: pMaterial, a2: v9, a3: (char *)&pKeyValues + 3, a4: 0);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_pAnimatedTextureFrameNumVar = v10;
  if ( v8 )
    return 0;
  v11 = pMaterial->FindVar(this: pMaterial, a2: "$lighting", a3: (char *)&pKeyValues + 3, a4: 0);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_pLightingVar = v11;
  if ( v8 )
  {
    _Warning(a1: "Materials using the pupil proxy must have a field called $lighting which has a value of 0.5!\n");
    return 0;
  }
  CFloatInput::Init(
    this: &this->m_flPupilCloseRate,
    pMaterial,
    pKeyValues: v3,
    pKeyName: "PupilCloseRate",
    flDefault: 0.1);
  CFloatInput::Init(
    this: &this->m_flPupilOpenRate,
    pMaterial,
    pKeyValues: v3,
    pKeyName: "PupilOpenRate",
    flDefault: 0.029999999);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A0D0
// Name: public: virtual void CPupilProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPupilProxy::OnBind(CPupilProxy *this@<ecx>, int a2@<ebx>, C_BaseEntity *pBaseEntity)
{
  IMaterialVar *m_pAnimatedTextureVar; // eax
  int v5; // eax
  int v6; // ebx
  float v7; // xmm0_4
  int v8; // xmm1_4
  IMaterialVar *m_pLightingVar; // ecx
  float (__thiscall *GetFloatValueInternal)(IMaterialVar *); // eax
  double v11; // st7
  float v12; // xmm0_4
  bool v13; // cc
  int v14; // eax
  int v15; // ebx
  Vector eyePt; // [esp+2Ch] [ebp-30h] BYREF
  Vector forward; // [esp+38h] [ebp-24h] BYREF
  Vector color; // [esp+44h] [ebp-18h] BYREF
  float flMaxChange; // [esp+50h] [ebp-Ch]
  float flLastIntensity; // [esp+54h] [ebp-8h]
  float flIntensity; // [esp+58h] [ebp-4h]
  C_BaseEntity *pBaseEntitya; // [esp+64h] [ebp+8h]

  if ( pBaseEntity != nullptr )
  {
    m_pAnimatedTextureVar = this->m_pAnimatedTextureVar;
    if ( m_pAnimatedTextureVar != nullptr && (*((_BYTE *)m_pAnimatedTextureVar + 28) & 0xF) == 3 )
    {
      v5 = ((int (__thiscall *)(IMaterialVar *, int))this->m_pAnimatedTextureVar->GetTextureValue)(
             a1: this->m_pAnimatedTextureVar,
             a2);
      v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(a1: v5);
      C_BaseEntity::GetVectors(this: pBaseEntity, pForward: &forward, pRight: nullptr, pUp: nullptr);
      pBaseEntity->EyePosition(this: pBaseEntity, result: &eyePt);
      engine->ComputeLighting(this: engine, a2: &eyePt, a3: &forward, a4: false, a5: &color, a6: nullptr);
      v7 = (float)((float)((float)(color.y * 0.58700001) + (float)(color.x * 0.29899999)) + (float)(color.z * 0.114))
         * 0.5;
      v8 = 0;
      if ( v7 < 0.0 || (v8 = 1065353216, v7 > 1.0) )
        v7 = *(float *)&v8;
      m_pLightingVar = this->m_pLightingVar;
      GetFloatValueInternal = m_pLightingVar->GetFloatValueInternal;
      *(float *)&pBaseEntitya = v7;
      flIntensity = v7;
      v11 = ((double (__thiscall *)(IMaterialVar *))GetFloatValueInternal)(a1: m_pLightingVar);
      flLastIntensity = v11;
      if ( v7 <= v11 )
      {
        flMaxChange = CFloatInput::GetFloat(this: &this->m_flPupilOpenRate) * *(float *)(gpGlobals.m_Index + 16);
        v12 = flLastIntensity - flMaxChange;
        v13 = (float)(flLastIntensity - flMaxChange) <= *(float *)&pBaseEntitya;
      }
      else
      {
        flMaxChange = CFloatInput::GetFloat(this: &this->m_flPupilCloseRate) * *(float *)(gpGlobals.m_Index + 16);
        v12 = flMaxChange + flLastIntensity;
        v13 = *(float *)&pBaseEntitya <= (float)(flMaxChange + flLastIntensity);
      }
      if ( !v13 )
        flIntensity = v12;
      v14 = (int)(float)((float)v6 * flIntensity);
      v15 = v6 - 1;
      if ( v14 >= 0 )
      {
        if ( v14 > v15 )
          v14 = v15;
      }
      else
      {
        v14 = 0;
      }
      this->m_pAnimatedTextureFrameNumVar->SetIntValue(this: this->m_pAnimatedTextureFrameNumVar, a2: v14);
      ((void (__stdcall *)(_DWORD))this->m_pLightingVar->SetFloatValue)(a1: LODWORD(flIntensity));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A260
// Name: CCPupilProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCPupilProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CPupilProxy::`vftable';
  return result;
}
