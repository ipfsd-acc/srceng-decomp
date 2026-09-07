// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/fx_cs_blood.cpp
// Functions: 7
// ============================================================

#include "game\client\cstrike15\fx_cs_blood.h"

//------------------------------------------------------------------------------
// Address: 0x101CB120
// Name: public: virtual void PrecacheEffectCSBloodSprayPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectCSBloodSprayPrecache::CResourcePrecacher::Cache(
        PrecacheEffectCSBloodSprayPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "blood_impact_basic",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101CB150
// Name: void FX_CS_BloodSpray(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __cdecl FX_CS_BloodSpray(const Vector *origin, const Vector *normal, float flDamage)
{
  IUniformRandomStream *v3; // ecx
  ConVar *v4; // eax
  ConVar *m_pParent; // eax
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  const char *v13; // ecx
  QAngle vecAngles_4; // [esp+Ch] [ebp-24h] BYREF
  Vector dir; // [esp+18h] [ebp-18h] BYREF
  Vector offset; // [esp+24h] [ebp-Ch]

  if ( !UTIL_IsLowViolence() )
  {
    if ( (_S5_141 & 1) != 0 )
    {
      v4 = violence_hblood_2;
    }
    else
    {
      _S5_141 |= 1u;
      v4 = cvar->FindVar_2(this: cvar, a2: "violence_hblood");
      violence_hblood_2 = v4;
    }
    if ( v4 == nullptr || (m_pParent = v4->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      offset.x = _RandomFloat(this: v3, a2: -0.5, a3: 0.5);
      offset.y = _RandomFloat(this: v6, a2: -0.5, a3: 0.5);
      offset.z = _RandomFloat(this: v7, a2: -0.5, a3: 0.5);
      x = normal->x;
      dir.x = normal->x * offset.x;
      y = normal->y;
      dir.y = y * offset.y;
      z = normal->z;
      dir.z = z * offset.z;
      v11 = origin->x + (float)(x * 2.0);
      offset.y = origin->y + (float)(y * 2.0);
      v12 = origin->z;
      offset.x = v11;
      offset.z = v12 + (float)(z * 2.0);
      VectorAngles(forward: &dir, angles: &vecAngles_4);
      if ( flDamage <= 45.0 )
      {
        v13 = "blood_impact_medium";
        if ( flDamage < 30.0 )
          v13 = "blood_impact_light";
      }
      else
      {
        v13 = "blood_impact_heavy";
      }
      DispatchParticleEffect(
        pszParticleName: v13,
        vecOrigin: offset,
        vecAngles: vecAngles_4,
        pEntity: nullptr,
        nSplitScreenPlayerSlot: -1,
        filter: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB310
// Name: void CSBloodSprayCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSBloodSprayCallback(const CEffectData *data)
{
  FX_CS_BloodSpray(origin: &data->m_vOrigin, normal: &data->m_vNormal, flDamage: data->m_flMagnitude);
}

//------------------------------------------------------------------------------
// Address: 0x10423600
// Name: PrecacheEffectCSBloodSprayPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectCSBloodSprayPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectCSBloodSprayPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectCSBloodSprayPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423640
// Name: csbloodPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int csbloodPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  csbloodPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&csbloodPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423620
// Name: _dynamic_initializer_for__ClientEffectReg_CSBloodSprayCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CSBloodSprayCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CSBloodSprayCallback,
           pEffectName: "csblood",
           fn: CSBloodSprayCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10423660
// Name: _dynamic_initializer_for__ClientEffectReg_ImpactCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ImpactCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ImpactCallback,
           pEffectName: "Impact",
           fn: (void (__cdecl *)(const CEffectData *))ImpactCallback);
}
