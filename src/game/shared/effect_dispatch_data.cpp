// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/effect_dispatch_data.cpp
// Functions: 18
// ============================================================

#include "game\shared\effect_dispatch_data.h"

//------------------------------------------------------------------------------
// Address: 0x100D09B0
// Name: bool SuppressingParticleEffects(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SuppressingParticleEffects()
{
  return g_bSuppressParticleEffects;
}

//------------------------------------------------------------------------------
// Address: 0x100D09C0
// Name: void SuppressParticleEffects(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SuppressParticleEffects(bool bSuppress)
{
  g_bSuppressParticleEffects = bSuppress;
}

//------------------------------------------------------------------------------
// Address: 0x100D09D0
// Name: RecvProxy_EntIndex
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_EntIndex(int pData, _DWORD *pStruct)
{
  CBaseHandle *v2; // eax

  if ( *(int *)(pData + 8) >= 0 )
  {
    v2 = CClientEntityList::EntIndexToHandle(
           this: (CClientEntityList *)cl_entitylist.m_Index,
           result: (CBaseHandle *)&pData,
           entnum: *(_DWORD *)(pData + 8));
    pStruct[13] = v2->m_Index;
  }
  else
  {
    pData = -1;
    pStruct[13] = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0C80
// Name: public: class IClientRenderable __near * CEffectData::GetRenderable(void)const
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall CEffectData::GetRenderable(CEffectData *this)
{
  return CClientEntityList::GetClientRenderableFromHandle(
           this: (CClientEntityList *)cl_entitylist.m_Index,
           hEnt: this->m_hEntity);
}

//------------------------------------------------------------------------------
// Address: 0x100D0CA0
// Name: public: class C_BaseEntity __near * CEffectData::GetEntity(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CEffectData::GetEntity(CEffectData *this)
{
  return CClientEntityList::GetBaseEntityFromHandle(
           this: (CClientEntityList *)cl_entitylist.m_Index,
           hEnt: this->m_hEntity);
}

//------------------------------------------------------------------------------
// Address: 0x100D0CC0
// Name: public: int CEffectData::entindex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEffectData::entindex(CEffectData *this)
{
  C_BaseEntity *BaseEntityFromHandle; // eax

  BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           hEnt: this->m_hEntity);
  if ( BaseEntityFromHandle != nullptr )
    return BaseEntityFromHandle->entindex(this: &BaseEntityFromHandle->IClientNetworkable);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10415470
// Name: DT_EffectData::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EffectData::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EffectData::g_RecvTable);
  return atexit(func: DT_EffectData::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415490
// Name: DT_EffectData::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EffectData::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EffectData::ignored>();
  DT_EffectData::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431500
// Name: DT_EffectData::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EffectData::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EffectData::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100D0CF0
// Name: __CreateCEffectsClientIEffects_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEffectsClient *__cdecl _CreateCEffectsClientIEffects_interface()
{
  return &s_EffectClient;
}

//------------------------------------------------------------------------------
// Address: 0x104154A0
// Name: _dynamic_initializer_for__s_EffectClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EffectClient__()
{
  s_EffectClient.m_pNextSystem = IPredictionSystem::g_pPredictionSystems;
  IPredictionSystem::g_pPredictionSystems = &s_EffectClient;
  return atexit(func: dynamic_atexit_destructor_for__s_EffectClient__);
}

//------------------------------------------------------------------------------
// Address: 0x104154C0
// Name: _dynamic_initializer_for____g_CreateCEffectsClientIEffects_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEffectsClientIEffects_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEffectsClientIEffects_reg,
           fn: (void *(__cdecl *)())_CreateCEffectsClientIEffects_interface,
           pName: "IEffects001");
}

//------------------------------------------------------------------------------
// Address: 0x104154E0
// Name: _dynamic_initializer_for__r_decals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_decals__()
{
  ConVar::ConVar(this: &r_decals, pName: "r_decals", pDefaultValue: "2048", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_decals__);
}

//------------------------------------------------------------------------------
// Address: 0x10415510
// Name: _dynamic_initializer_for__g_CEntityOriginFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CEntityOriginFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "EntityOrigin",
           a3: CCEntityOriginMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10415530
// Name: _dynamic_initializer_for__g_CEntityOriginAlyxFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CEntityOriginAlyxFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "EntityOriginAlyx",
           a3: CCEntityOriginAlyxMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10415550
// Name: _dynamic_initializer_for__g_CEp1IntroVortRefractFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CEp1IntroVortRefractFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "Ep1IntroVortRefract",
           a3: CCEp1IntroVortRefractMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10431510
// Name: _dynamic_atexit_destructor_for__r_decals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_decals__()
{
  ConVar::~ConVar(this: &r_decals);
}

//------------------------------------------------------------------------------
// Address: 0x10431520
// Name: _dynamic_atexit_destructor_for__s_EffectClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EffectClient__()
{
  s_EffectClient.__vftable = (CEffectsClient_vtbl *)&IPredictionSystem::`vftable';
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10401A40
// Name: DT_EffectData::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EffectData::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EffectData::g_SendTable);
  return atexit(func: DT_EffectData::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401A60
// Name: DT_EffectData::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EffectData::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EffectData::ignored>();
  DT_EffectData::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A830
// Name: DT_EffectData::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EffectData::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EffectData::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401A70
// Name: _dynamic_initializer_for__env_bubbles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_bubbles__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CBubbling> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_bubbles,
           a3: "env_bubbles");
}

//------------------------------------------------------------------------------
// Address: 0x1041A840
// Name: _ServerClassInit_DT_EffectData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EffectData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_72;
  for ( i = 21; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
