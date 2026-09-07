// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/fx_cs_muzzleflash.cpp
// Functions: 11
// ============================================================

#include "game\client\cstrike15\fx_cs_muzzleflash.h"

//------------------------------------------------------------------------------
// Address: 0x101CB600
// Name: public: virtual void PrecacheEffect_CS_MuzzleFlashPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffect_CS_MuzzleFlashPrecache::CResourcePrecacher::Cache(
        PrecacheEffect_CS_MuzzleFlashPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflashX",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/muzzleflash4",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101CB640
// Name: void CS_MuzzleFlashCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CS_MuzzleFlashCallback(const CEffectData *data)
{
  C_BaseEntity *Entity; // eax
  float *v2; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  IClientRenderable *Renderable; // eax
  int i; // edi
  Particle *v8; // esi
  int v9; // eax
  const Vector *v10; // esi
  const Vector *v11; // eax
  CPVSFilter filter; // [esp+3Ch] [ebp-40h] BYREF
  Vector vecMins; // [esp+5Ch] [ebp-20h] BYREF
  Vector vecMaxs; // [esp+68h] [ebp-14h] BYREF
  CParticleSubTexture *hFlashMaterial; // [esp+74h] [ebp-8h]
  CSmartPtr<CLocalSpaceEmitter,CRefCountAccessor> pEmitter; // [esp+78h] [ebp-4h] BYREF

  CLocalSpaceEmitter::Create(
    result: &pEmitter,
    pDebugName: "CS_MuzzleFlash",
    hEntity: data->m_hEntity,
    nAttachment: data->m_nAttachmentIndex,
    fFlags: 0);
  if ( pEmitter.m_pObj != nullptr )
  {
    memset((void *)&vecMaxs, 0, sizeof(vecMaxs));
    Entity = CEffectData::GetEntity(this: data);
    if ( Entity != nullptr )
    {
      v2 = (float *)Entity->WorldSpaceCenter(this: Entity);
      x = *v2;
      y = v2[1];
      z = v2[2];
    }
    else
    {
      Renderable = CEffectData::GetRenderable(this: data);
      if ( Renderable != nullptr )
      {
        Renderable->GetRenderBoundsWorldspace(this: Renderable, a2: &vecMins, a3: &vecMaxs);
        x = (float)(vecMaxs.x + vecMins.x) * 0.5;
        y = (float)(vecMaxs.y + vecMins.y) * 0.5;
        z = (float)(vecMaxs.z + vecMins.z) * 0.5;
      }
      else
      {
        x = vecMaxs.x;
        y = vecMaxs.y;
        z = vecMaxs.z;
      }
    }
    vecMins.x = x + 3.0;
    vecMins.y = y + 3.0;
    vecMins.z = z + 3.0;
    vecMaxs.x = x - 3.0;
    vecMaxs.y = y - 3.0;
    vecMaxs.z = z - 3.0;
    CParticleEffectBinding::SetBBox(
      this: &pEmitter.m_pObj->m_ParticleEffect,
      bbMin: &vecMaxs,
      bbMax: &vecMins,
      bDisableAutoUpdate: true);
    CSimpleEmitter::SetNearClip(this: pEmitter.m_pObj, nearClipMin: 0.0, nearClipMax: 5.0);
    hFlashMaterial = CParticleEffect::GetPMaterial(this: pEmitter.m_pObj, name: "sprites/muzzleflash4");
    for ( i = 0; i < 3; ++i )
    {
      v8 = CParticleEffect::AddParticle(
             this: pEmitter.m_pObj,
             particleSize: 0x3Cu,
             material: hFlashMaterial,
             origin: &vec3_origin);
      if ( v8 != nullptr )
      {
        v8[1].m_Pos.z = 0.0;
        v8[1].m_Pos.y = 0.079999998;
        *(Vector *)&v8[1].m_pPrev = vec3_origin;
        v8[2].m_pPrev = (Particle *)1358954495;
        LOBYTE(v8[2].m_pNext) = 30;
        v9 = (int)(((double)i + 1.0) * 3.0 * data->m_flScale);
        BYTE2(v8[2].m_pNext) = (int)((double)(unsigned __int8)v9 * 0.8);
        BYTE1(v8[2].m_pNext) = v9;
        v8[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 3);
        v8[2].m_pSubTexture = nullptr;
      }
    }
    v10 = pEmitter.m_pObj->GetSortOrigin(this: pEmitter.m_pObj);
    C_RecipientFilter::C_RecipientFilter(this: &filter);
    filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
    C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: v10);
    v11 = pEmitter.m_pObj->GetSortOrigin(this: pEmitter.m_pObj);
    TE_DynamicLight(
      &filter,
      delay: 0.0,
      org: v11,
      r: 255,
      g: 192,
      b: 64,
      exponent: 5,
      radius: 70.0,
      time: 0.050000001,
      decay: 768.0,
      nLightIndex: 0x10000000);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
    if ( pEmitter.m_pObj != nullptr )
      CParticleEffect::Release(this: pEmitter.m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB920
// Name: void CS_MuzzleFlashXCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CS_MuzzleFlashXCallback(const CEffectData *data)
{
  C_BaseEntity *Entity; // eax
  int v2; // eax
  float v3; // ecx
  CParticleSubTexture *PMaterial; // eax
  Particle *v5; // eax
  Particle *v6; // esi
  char v7; // al
  const Vector *v8; // esi
  const Vector *v9; // eax
  CPVSFilter filter; // [esp+40h] [ebp-40h] BYREF
  Vector bbMax; // [esp+60h] [ebp-20h] BYREF
  Vector vCenter; // [esp+6Ch] [ebp-14h] BYREF
  int v13; // [esp+78h] [ebp-8h]
  CSmartPtr<CLocalSpaceEmitter,CRefCountAccessor> pEmitter; // [esp+7Ch] [ebp-4h] BYREF

  CLocalSpaceEmitter::Create(
    result: &pEmitter,
    pDebugName: "CS_MuzzleFlashX",
    hEntity: data->m_hEntity,
    nAttachment: data->m_nAttachmentIndex,
    fFlags: 0);
  Entity = CEffectData::GetEntity(this: data);
  if ( Entity != nullptr )
  {
    v2 = (int)Entity->WorldSpaceCenter(this: Entity);
    v3 = *(float *)(v2 + 8);
    *(_QWORD *)&vCenter.x = *(_QWORD *)v2;
    bbMax.x = vCenter.x + 3.0;
    bbMax.y = vCenter.y + 3.0;
    bbMax.z = v3 + 3.0;
    vCenter.x = vCenter.x - 3.0;
    vCenter.y = vCenter.y - 3.0;
    vCenter.z = v3 - 3.0;
    CParticleEffectBinding::SetBBox(
      this: &pEmitter.m_pObj->m_ParticleEffect,
      bbMin: &vCenter,
      &bbMax,
      bDisableAutoUpdate: true);
  }
  CSimpleEmitter::SetNearClip(this: pEmitter.m_pObj, nearClipMin: 0.0, nearClipMax: 5.0);
  PMaterial = CParticleEffect::GetPMaterial(this: pEmitter.m_pObj, name: "effects/muzzleflashX");
  v5 = CParticleEffect::AddParticle(
         this: pEmitter.m_pObj,
         particleSize: 0x3Cu,
         material: PMaterial,
         origin: &vec3_origin);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v5[1].m_Pos.z = 0.0;
    v5[1].m_Pos.y = 0.079999998;
    *(Vector *)&v5[1].m_pPrev = vec3_origin;
    v5[2].m_pPrev = (Particle *)-2097152001;
    LOBYTE(v5[2].m_pNext) = 80;
    v13 = (int)(((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1063675494,
                  a3: 1066192077)
              * (data->m_flScale
               * 6.0));
    v7 = v13;
    BYTE2(v6[2].m_pNext) = (int)((double)(unsigned __int8)v13 * 0.8);
    BYTE1(v6[2].m_pNext) = v7;
    v6[1].m_Pos.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: -1098907648,
                      a3: 1048576000);
    v6[2].m_pSubTexture = nullptr;
  }
  v8 = pEmitter.m_pObj->GetSortOrigin(this: pEmitter.m_pObj);
  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: v8);
  v9 = pEmitter.m_pObj->GetSortOrigin(this: pEmitter.m_pObj);
  TE_DynamicLight(
    &filter,
    delay: 0.0,
    org: v9,
    r: 255,
    g: 192,
    b: 64,
    exponent: 5,
    radius: 70.0,
    time: 0.050000001,
    decay: 768.0,
    nLightIndex: 0x10000000);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
  if ( pEmitter.m_pObj != nullptr )
    CParticleEffect::Release(this: pEmitter.m_pObj);
}

//------------------------------------------------------------------------------
// Address: 0x104236E0
// Name: PrecacheEffect_CS_MuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffect_CS_MuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffect_CS_MuzzleFlashPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffect_CS_MuzzleFlashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423720
// Name: CS_MuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int CS_MuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  CS_MuzzleFlashPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&CS_MuzzleFlashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423760
// Name: CS_MuzzleFlash_XPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int CS_MuzzleFlash_XPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  CS_MuzzleFlash_XPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&CS_MuzzleFlash_XPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042CF30
// Name: _dynamic_initializer_for__muzzleflash_light__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__muzzleflash_light__()
{
  ConVar::ConVar(this: &muzzleflash_light, pName: "muzzleflash_light", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__muzzleflash_light__);
}

//------------------------------------------------------------------------------
// Address: 0x10436F40
// Name: _dynamic_atexit_destructor_for__muzzleflash_light__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__muzzleflash_light__()
{
  ConVar::~ConVar(this: &muzzleflash_light);
}

//------------------------------------------------------------------------------
// Address: 0x10423700
// Name: _dynamic_initializer_for__ClientEffectReg_CS_MuzzleFlashCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CS_MuzzleFlashCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CS_MuzzleFlashCallback,
           pEffectName: "CS_MuzzleFlash",
           fn: CS_MuzzleFlashCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10423740
// Name: _dynamic_initializer_for__ClientEffectReg_CS_MuzzleFlashXCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CS_MuzzleFlashXCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CS_MuzzleFlashXCallback,
           pEffectName: "CS_MuzzleFlash_X",
           fn: CS_MuzzleFlashXCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1042CF60
// Name: _dynamic_initializer_for__ClientEffectReg_MuzzleFlashCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_MuzzleFlashCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_MuzzleFlashCallback,
           pEffectName: "MuzzleFlash",
           fn: MuzzleFlashCallback);
}
