// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_dynamiclight.cpp
// Functions: 12
// ============================================================

#include "game\client\c_te_dynamiclight.h"

//------------------------------------------------------------------------------
// Address: 0x10258080
// Name: public: virtual class ClientClass __near * C_TEDynamicLight::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEDynamicLight::GetClientClass(C_TEDynamicLight *this)
{
  return &__g_C_TEDynamicLightClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10258210
// Name: void TE_DynamicLight(class IRecipientFilter __near &,float,class Vector const __near *,int,int,int,int,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_DynamicLight(
        IRecipientFilter *filter,
        float delay,
        const Vector *org,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        int exponent,
        float radius,
        float time,
        float decay,
        int nLightIndex)
{
  dlight_t *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  Color clr; // [esp+14h] [ebp-4h]

  v11 = effects->CL_AllocDlight(this: effects, a2: nLightIndex);
  if ( v11 != nullptr )
  {
    v11->origin = *org;
    v11->color.g = g;
    v11->radius = radius;
    v11->color.r = r;
    v11->color.b = b;
    v11->color.exponent = exponent;
    v11->die = *(float *)(gpGlobals.m_Index + 12) + time;
    v11->decay = decay;
    if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
    {
      clr._color[0] = r;
      clr._color[1] = g;
      clr._color[2] = b;
      clr._color[3] = -1;
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: "TempEntity");
      else
        v13 = nullptr;
      KeyValues::SetInt(this: v13, keyName: "te", value: 0);
      KeyValues::SetString(this: v13, keyName: "name", value: "TE_DynamicLight");
      KeyValues::SetFloat(this: v13, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
      KeyValues::SetFloat(this: v13, keyName: "duration", value: time);
      KeyValues::SetFloat(this: v13, keyName: "originx", value: org->x);
      KeyValues::SetFloat(this: v13, keyName: "originy", value: org->y);
      KeyValues::SetFloat(this: v13, keyName: "originz", value: org->z);
      KeyValues::SetFloat(this: v13, keyName: "radius", value: radius);
      KeyValues::SetFloat(this: v13, keyName: "decay", value: decay);
      KeyValues::SetColor(this: v13, keyName: "color", value: clr);
      KeyValues::SetInt(this: v13, keyName: "exponent", value: exponent);
      KeyValues::SetInt(this: v13, keyName: "lightindex", value: nLightIndex);
      ToolFramework_PostToolMessage(hEntity: 0, msg: v13);
      KeyValues::deleteThis(this: v13);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102583F0
// Name: public: virtual void C_TEDynamicLight::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEDynamicLight::PostDataUpdate(C_TEDynamicLight *this, DataUpdateType_t updateType)
{
  CBroadcastRecipientFilter filter; // [esp+2Ch] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  C_RecipientFilter::AddAllPlayers(this: &filter);
  TE_DynamicLight(
    &filter,
    delay: 0.0,
    org: (const Vector *)&this->m_pNextDynamic,
    r: LODWORD(this->m_fRadius),
    g: this->r,
    b: this->g,
    exponent: this->b,
    radius: this->m_vecOrigin.z,
    time: *(float *)&this->exponent,
    decay: this->m_fTime,
    nLightIndex: 0x10000000);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10258470
// Name: void TE_DynamicLight(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_DynamicLight(IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  int Int; // edi
  int v4; // eax
  Vector vecOrigin; // [esp+34h] [ebp-1Ch] BYREF
  float flRadius; // [esp+40h] [ebp-10h]
  float flDuration; // [esp+44h] [ebp-Ch]
  Color c; // [esp+48h] [ebp-8h] BYREF
  float flDecay; // [esp+4Ch] [ebp-4h] BYREF

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  flDuration = KeyValues::GetFloat(this: pKeyValues, keyName: "duration", defaultValue: 0.0);
  flDecay = 0.0;
  KeyValues::GetColor(this: pKeyValues, result: &c, keyName: "color", defaultColor: (const Color *)&flDecay);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "exponent", defaultValue: 0);
  flRadius = KeyValues::GetFloat(this: pKeyValues, keyName: "radius", defaultValue: 0.0);
  flDecay = KeyValues::GetFloat(this: pKeyValues, keyName: "decay", defaultValue: 0.0);
  v4 = KeyValues::GetInt(this: pKeyValues, keyName: "lightindex", defaultValue: 0x10000000);
  TE_DynamicLight(
    filter,
    delay: 0.0,
    org: &vecOrigin,
    r: c._color[0],
    g: c._color[1],
    b: c._color[2],
    exponent: Int,
    radius: flRadius,
    time: flDuration,
    decay: flDecay,
    nLightIndex: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1042BD40
// Name: DT_TEDynamicLight::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDynamicLight::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEDynamicLight::g_RecvTable);
  return atexit(func: DT_TEDynamicLight::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BD60
// Name: DT_TEDynamicLight::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDynamicLight::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEDynamicLight::ignored>();
  DT_TEDynamicLight::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436A70
// Name: DT_TEDynamicLight::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEDynamicLight::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEDynamicLight::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10258090
// Name: _C_TEDynamicLight_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEDynamicLight_CreateObject()
{
  return &_g_C_TEDynamicLight.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042BD70
// Name: _dynamic_initializer_for____g_C_TEEffectDispatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEEffectDispatch__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEEffectDispatch);
  _g_C_TEEffectDispatch.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEEffectDispatch_vtbl *)&C_TEEffectDispatch::`vftable'{for `IClientUnknown'};
  _g_C_TEEffectDispatch.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEEffectDispatch::`vftable'{for `IClientNetworkable'};
  _g_C_TEEffectDispatch.m_EffectData.m_vOrigin.x = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vOrigin.y = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vOrigin.z = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vStart.x = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vStart.y = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vStart.z = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vNormal.x = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vNormal.y = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vNormal.z = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vAngles.x = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vAngles.y = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_vAngles.z = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_fFlags = 0;
  _g_C_TEEffectDispatch.m_EffectData.m_hEntity.m_Index = -1;
  _g_C_TEEffectDispatch.m_EffectData.m_flScale = 1.0;
  _g_C_TEEffectDispatch.m_EffectData.m_nAttachmentIndex = 0;
  _g_C_TEEffectDispatch.m_EffectData.m_nSurfaceProp = 0;
  _g_C_TEEffectDispatch.m_EffectData.m_flMagnitude = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_flRadius = 0.0;
  _g_C_TEEffectDispatch.m_EffectData.m_nMaterial = 0;
  _g_C_TEEffectDispatch.m_EffectData.m_nDamageType = 0;
  _g_C_TEEffectDispatch.m_EffectData.m_nHitBox = 0;
  _g_C_TEEffectDispatch.m_EffectData.m_nColor = 0;
  _g_C_TEEffectDispatch.m_EffectData.m_nOtherEntIndex = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEEffectDispatch__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BE60
// Name: _dynamic_initializer_for____g_C_TEEffectDispatchClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEEffectDispatchClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEEffectDispatchClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEEffectDispatchClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436A80
// Name: _dynamic_atexit_destructor_for____g_C_TEDynamicLight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEDynamicLight__()
{
  _g_C_TEDynamicLight.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEDynamicLight_vtbl *)&C_TEDynamicLight::`vftable'{for `IClientUnknown'};
  _g_C_TEDynamicLight.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEDynamicLight::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEDynamicLight);
}

//------------------------------------------------------------------------------
// Address: 0x10436AA0
// Name: _dynamic_atexit_destructor_for____g_C_TEEffectDispatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEEffectDispatch__()
{
  _g_C_TEEffectDispatch.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEEffectDispatch_vtbl *)&C_TEEffectDispatch::`vftable'{for `IClientUnknown'};
  _g_C_TEEffectDispatch.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEEffectDispatch::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEEffectDispatch);
}
