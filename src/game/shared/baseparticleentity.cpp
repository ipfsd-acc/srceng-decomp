// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/baseparticleentity.cpp
// Functions: 33
// ============================================================

#include "game\shared\baseparticleentity.h"

//------------------------------------------------------------------------------
// Address: 0x10017CB0
// Name: public: virtual class ClientClass __near * C_BaseParticleEntity::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseParticleEntity::GetClientClass(C_BaseParticleEntity *this)
{
  return &__g_C_BaseParticleEntityClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10017D30
// Name: public: virtual struct datamap_t __near * C_BaseParticleEntity::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseParticleEntity::GetPredDescMap(C_BaseParticleEntity *this)
{
  return &C_BaseParticleEntity::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10017D40
// Name: public: virtual void C_BaseParticleEntity::Think(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_BaseParticleEntity::Think(C_BaseParticleEntity *this)
{
  C_BaseEntity::Remove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10017D50
// Name: public: virtual class Vector const __near & C_BaseParticleEntity::GetSortOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseParticleEntity::GetSortOrigin(C_BaseParticleEntity *this)
{
  C_BaseEntity *RootMoveParent; // eax

  RootMoveParent = C_BaseEntity::GetRootMoveParent(this: (C_BaseParticleEntity *)((char *)this - 2432));
  return RootMoveParent->GetAbsOrigin(this: RootMoveParent);
}

//------------------------------------------------------------------------------
// Address: 0x10017D70
// Name: public: virtual class Vector const __near * IParticleEffect::GetParticlePosition(struct Particle __near *)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall IParticleEffect::GetParticlePosition(IParticleEffect *this, Particle *pParticle)
{
  return &pParticle->m_Pos;
}

//------------------------------------------------------------------------------
// Address: 0x10017D80
// Name: public: virtual char const __near * IParticleEffect::GetEffectName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IParticleEffect::GetEffectName(IParticleEffect *this)
{
  return "???";
}

//------------------------------------------------------------------------------
// Address: 0x10017DC0
// Name: public: C_BaseParticleEntity::C_BaseParticleEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseParticleEntity *__thiscall C_BaseParticleEntity::C_BaseParticleEntity(C_BaseParticleEntity *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->IParticleEffect::__vftable = (IParticleEffect_vtbl *)&IParticleEffect::`vftable';
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseParticleEntity_vtbl *)&C_BaseParticleEntity::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseParticleEntity::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseParticleEntity::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseParticleEntity::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseParticleEntity::`vftable'{for `C_BaseEntity'};
  this->IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_BaseParticleEntity::`vftable'{for `IParticleEffect'};
  CParticleEffectBinding::CParticleEffectBinding(this: &this->m_ParticleEffect);
  this->m_bSimulate = true;
  this->m_nToolParticleEffectId = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017E20
// Name: public: virtual bool C_BaseParticleEntity::ShouldSimulate(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseParticleEntity::ShouldSimulate(C_BaseParticleEntity *this)
{
  return this->m_iEFlags;
}

//------------------------------------------------------------------------------
// Address: 0x10017E30
// Name: public: virtual void C_BaseParticleEntity::SetShouldSimulate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseParticleEntity::SetShouldSimulate(C_BaseParticleEntity *this, bool bSim)
{
  LOBYTE(this->m_iEFlags) = bSim;
}

//------------------------------------------------------------------------------
// Address: 0x10017E60
// Name: public: virtual C_BaseParticleEntity::~C_BaseParticleEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseParticleEntity::~C_BaseParticleEntity(C_BaseParticleEntity *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseParticleEntity_vtbl *)&C_BaseParticleEntity::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseParticleEntity::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseParticleEntity::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseParticleEntity::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseParticleEntity::`vftable'{for `C_BaseEntity'};
  this->IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_BaseParticleEntity::`vftable'{for `IParticleEffect'};
  if ( ToolsEnabled() && this->m_nToolParticleEffectId != -1 && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OldParticleSystem_Destroy");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "id", value: this->m_nToolParticleEffectId);
    this->m_nToolParticleEffectId = -1;
  }
  CParticleEffectBinding::~CParticleEffectBinding(this: &this->m_ParticleEffect);
  this->IParticleEffect::__vftable = (IParticleEffect_vtbl *)&IParticleEffect::`vftable';
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10017F60
// Name: class IParticleEffect __near * CBaseParticleEntity_Factory(void)
// Source: json
//------------------------------------------------------------------------------
IParticleEffect *__cdecl CBaseParticleEntity_Factory()
{
  C_BaseParticleEntity *v0; // eax
  C_BaseParticleEntity *v1; // eax

  v0 = (C_BaseParticleEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xA68u);
  if ( v0 != nullptr && (v1 = C_BaseParticleEntity::C_BaseParticleEntity(this: v0)) != nullptr )
    return &v1->IParticleEffect;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1040FEF0
// Name: DT_BaseParticleEntity::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseParticleEntity::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseParticleEntity::g_RecvTable);
  return atexit(func: DT_BaseParticleEntity::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FF10
// Name: DT_BaseParticleEntity::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseParticleEntity::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseParticleEntity::ignored>();
  DT_BaseParticleEntity::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FF20
// Name: C_BaseParticleEntity_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseParticleEntity_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseParticleEntity::m_PredMap.dataNumFields = 1;
  C_BaseParticleEntity::m_PredMap.dataDesc = (typedescription_t *)&unk_105F8A54;
}

//------------------------------------------------------------------------------
// Address: 0x1042F8B0
// Name: DT_BaseParticleEntity::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseParticleEntity::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseParticleEntity::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10017F10
// Name: _C_BaseParticleEntity_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseParticleEntity_CreateObject(int entnum, int serialNum)
{
  C_BaseParticleEntity *v2; // eax
  C_BaseParticleEntity *v3; // eax
  C_BaseParticleEntity *v4; // esi

  v2 = (C_BaseParticleEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xA68u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseParticleEntity::C_BaseParticleEntity(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1040FF40
// Name: _dynamic_initializer_for__g_CBaseParticleEntity_RegistrationHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__g_CBaseParticleEntity_RegistrationHelper__(const char *a1@<edi>)
{
  CParticleMgr *v1; // eax
  const char *v2; // [esp-8h] [ebp-8h]

  v2 = type_info::name(this: &C_BaseParticleEntity `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v1 = ParticleMgr();
  CParticleMgr::RegisterEffect(this: v1, a2: a1, pEffectType: v2, func: CBaseParticleEntity_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x1040FF70
// Name: _dynamic_initializer_for__physicsshadowupdate_render__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__physicsshadowupdate_render__()
{
  ConVar::ConVar(
    this: &physicsshadowupdate_render,
    pName: "cl_physicsshadowupdate_render",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__physicsshadowupdate_render__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FFA0
// Name: _dynamic_initializer_for__cl_shadowupdatespacing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_shadowupdatespacing__()
{
  ConVar::ConVar(this: &cl_shadowupdatespacing, pName: "cl_shadowupdatespacing", pDefaultValue: "10.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_shadowupdatespacing__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FFD0
// Name: _dynamic_initializer_for__cl_predict_motioncontrol__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predict_motioncontrol__()
{
  ConVar::ConVar(this: &cl_predict_motioncontrol, pName: "cl_predict_motioncontrol", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_predict_motioncontrol__);
}

//------------------------------------------------------------------------------
// Address: 0x10410000
// Name: _dynamic_initializer_for__mp_usehwmmodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_usehwmmodels__()
{
  ConVar::ConVar(
    this: &mp_usehwmmodels,
    pName: "mp_usehwmmodels",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable the use of the hw morph models. (-1 = never, 1 = always, 0 = based upon GPU)");
  return atexit(func: dynamic_atexit_destructor_for__mp_usehwmmodels__);
}

//------------------------------------------------------------------------------
// Address: 0x10410030
// Name: _dynamic_initializer_for__sv_debug_player_use__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_debug_player_use__()
{
  ConVar::ConVar(
    this: &sv_debug_player_use,
    pName: "sv_debug_player_use",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Visualizes +use logic. Green cross=trace success, Red cross=trace too far, Green box=radius success");
  return atexit(func: dynamic_atexit_destructor_for__sv_debug_player_use__);
}

//------------------------------------------------------------------------------
// Address: 0x10410060
// Name: _dynamic_initializer_for__sv_suppress_viewpunch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_suppress_viewpunch__()
{
  ConVar::ConVar(this: &sv_suppress_viewpunch, pName: "sv_suppress_viewpunch", pDefaultValue: "0", flags: 24578);
  return atexit(func: dynamic_atexit_destructor_for__sv_suppress_viewpunch__);
}

//------------------------------------------------------------------------------
// Address: 0x10410090
// Name: _dynamic_initializer_for__smoothstairs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__smoothstairs__()
{
  ConVar::ConVar(
    this: &smoothstairs,
    pName: "smoothstairs",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Smooth player eye z coordinate when traversing stairs.");
  return atexit(func: dynamic_atexit_destructor_for__smoothstairs__);
}

//------------------------------------------------------------------------------
// Address: 0x104100C0
// Name: _dynamic_initializer_for__cl_headbob_land_dip_amt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_headbob_land_dip_amt__()
{
  ConVar::ConVar(this: &cl_headbob_land_dip_amt, pName: "cl_headbob_land_dip_amt", pDefaultValue: "4", flags: 8);
  return atexit(func: dynamic_atexit_destructor_for__cl_headbob_land_dip_amt__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F8C0
// Name: _dynamic_atexit_destructor_for__physicsshadowupdate_render__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__physicsshadowupdate_render__()
{
  ConVar::~ConVar(this: &physicsshadowupdate_render);
}

//------------------------------------------------------------------------------
// Address: 0x1042F8D0
// Name: _dynamic_atexit_destructor_for__cl_shadowupdatespacing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_shadowupdatespacing__()
{
  ConVar::~ConVar(this: &cl_shadowupdatespacing);
}

//------------------------------------------------------------------------------
// Address: 0x1042F8E0
// Name: _dynamic_atexit_destructor_for__cl_predict_motioncontrol__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predict_motioncontrol__()
{
  ConVar::~ConVar(this: &cl_predict_motioncontrol);
}

//------------------------------------------------------------------------------
// Address: 0x1042F8F0
// Name: _dynamic_atexit_destructor_for__mp_usehwmmodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_usehwmmodels__()
{
  ConVar::~ConVar(this: &mp_usehwmmodels);
}

//------------------------------------------------------------------------------
// Address: 0x1042F900
// Name: _dynamic_atexit_destructor_for__sv_debug_player_use__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_debug_player_use__()
{
  ConVar::~ConVar(this: &sv_debug_player_use);
}

//------------------------------------------------------------------------------
// Address: 0x1042F910
// Name: _dynamic_atexit_destructor_for__sv_suppress_viewpunch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_suppress_viewpunch__()
{
  ConVar::~ConVar(this: &sv_suppress_viewpunch);
}

//------------------------------------------------------------------------------
// Address: 0x1042F920
// Name: _dynamic_atexit_destructor_for__smoothstairs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__smoothstairs__()
{
  ConVar::~ConVar(this: &smoothstairs);
}

//------------------------------------------------------------------------------
// Address: 0x1042F930
// Name: _dynamic_atexit_destructor_for__cl_headbob_land_dip_amt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_headbob_land_dip_amt__()
{
  ConVar::~ConVar(this: &cl_headbob_land_dip_amt);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100D7F10
// Name: public: virtual class ServerClass __near * CBaseParticleEntity::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseParticleEntity::GetServerClass(CBaseParticleEntity *this)
{
  return &g_CBaseParticleEntity_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100D7F20
// Name: public: CBaseParticleEntity::CBaseParticleEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseParticleEntity *__thiscall CBaseParticleEntity::CBaseParticleEntity(CBaseParticleEntity *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CBaseParticleEntity_vtbl *)&CBaseParticleEntity::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D7F40
// Name: public: virtual CBaseParticleEntity::~CBaseParticleEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseParticleEntity::~CBaseParticleEntity(CBaseParticleEntity *this)
{
  this->__vftable = (CBaseParticleEntity_vtbl *)&CBaseParticleEntity::`vftable';
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7F50
// Name: public: virtual void CBaseParticleEntity::Think(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CBaseParticleEntity::Think(CBaseParticleEntity *this)
{
  CNullEntity::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D7F60
// Name: public: void CBaseParticleEntity::FollowEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseParticleEntity::FollowEntity(CBaseParticleEntity *this, CBaseEntity *pEntity)
{
  CBaseEntity::FollowEntity(this, pBaseEntity: pEntity, bBoneMerge: true);
  CBaseEntity::SetLocalOrigin(this, origin: &vec3_origin);
}

//------------------------------------------------------------------------------
// Address: 0x10115530
// Name: public: virtual int CBaseParticleEntity::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseParticleEntity::UpdateTransmitState(CBaseParticleEntity *this)
{
  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
  if ( (this->m_iEFlags & 0x20000) != 0 )
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
  return CBaseEntity::SetTransmitState(this, nFlag: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10400610
// Name: DT_BaseParticleEntity::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseParticleEntity::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseParticleEntity::g_SendTable);
  return atexit(func: DT_BaseParticleEntity::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10400630
// Name: DT_BaseParticleEntity::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseParticleEntity::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseParticleEntity::ignored>();
  DT_BaseParticleEntity::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419F40
// Name: DT_BaseParticleEntity::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseParticleEntity::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseParticleEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10400640
// Name: _dynamic_initializer_for__physicsshadowupdate_render__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__physicsshadowupdate_render__()
{
  ConVar::ConVar(this: &physicsshadowupdate_render, pName: "physicsshadowupdate_render", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__physicsshadowupdate_render__);
}

//------------------------------------------------------------------------------
// Address: 0x10400670
// Name: _dynamic_initializer_for__sv_infinite_ammo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_infinite_ammo__()
{
  ConVar::ConVar(
    this: &sv_infinite_ammo,
    pName: "sv_infinite_ammo",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Player's active weapon will never run out of ammo");
  return atexit(func: dynamic_atexit_destructor_for__sv_infinite_ammo__);
}

//------------------------------------------------------------------------------
// Address: 0x104006A0
// Name: _dynamic_initializer_for__sv_debug_player_use__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_debug_player_use__()
{
  ConVar::ConVar(
    this: &sv_debug_player_use,
    pName: "sv_debug_player_use",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Visualizes +use logic. Green cross=trace success, Red cross=trace too far, Green box=radius success");
  return atexit(func: dynamic_atexit_destructor_for__sv_debug_player_use__);
}

//------------------------------------------------------------------------------
// Address: 0x104006D0
// Name: _dynamic_initializer_for__sv_suppress_viewpunch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_suppress_viewpunch__()
{
  ConVar::ConVar(this: &sv_suppress_viewpunch, pName: "sv_suppress_viewpunch", pDefaultValue: "0", flags: 24578);
  return atexit(func: dynamic_atexit_destructor_for__sv_suppress_viewpunch__);
}

//------------------------------------------------------------------------------
// Address: 0x10400700
// Name: _dynamic_initializer_for__smoothstairs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__smoothstairs__()
{
  ConVar::ConVar(
    this: &smoothstairs,
    pName: "smoothstairs",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Smooth player eye z coordinate when traversing stairs.");
  return atexit(func: dynamic_atexit_destructor_for__smoothstairs__);
}

//------------------------------------------------------------------------------
// Address: 0x10419F50
// Name: _ServerClassInit_DT_BaseParticleEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseParticleEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_52;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419F70
// Name: _dynamic_atexit_destructor_for__physicsshadowupdate_render__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__physicsshadowupdate_render__()
{
  ConVar::~ConVar(this: &physicsshadowupdate_render);
}

//------------------------------------------------------------------------------
// Address: 0x10419F80
// Name: _dynamic_atexit_destructor_for__sv_infinite_ammo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_infinite_ammo__()
{
  ConVar::~ConVar(this: &sv_infinite_ammo);
}

//------------------------------------------------------------------------------
// Address: 0x10419F90
// Name: _dynamic_atexit_destructor_for__sv_debug_player_use__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_debug_player_use__()
{
  ConVar::~ConVar(this: &sv_debug_player_use);
}

//------------------------------------------------------------------------------
// Address: 0x10419FA0
// Name: _dynamic_atexit_destructor_for__sv_suppress_viewpunch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_suppress_viewpunch__()
{
  ConVar::~ConVar(this: &sv_suppress_viewpunch);
}

//------------------------------------------------------------------------------
// Address: 0x10419FB0
// Name: _dynamic_atexit_destructor_for__smoothstairs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__smoothstairs__()
{
  ConVar::~ConVar(this: &smoothstairs);
}

//------------------------------------------------------------------------------
// Address: 0x10419FC0
// Name: _DataMapInit_CBaseViewModel__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseViewModel__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_98);
}

} // namespace server
