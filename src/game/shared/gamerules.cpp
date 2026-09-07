// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/gamerules.cpp
// Functions: 30
// ============================================================

#include "game\shared\gamerules.h"

//------------------------------------------------------------------------------
// Address: 0x100E84F0
// Name: public: virtual class ClientClass __near * C_GameRulesProxy::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_GameRulesProxy::GetClientClass(C_GameRulesProxy *this)
{
  return &__g_C_GameRulesProxyClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100E8500
// Name: public: C_GameRulesProxy::C_GameRulesProxy(void)
// Source: json
//------------------------------------------------------------------------------
C_GameRulesProxy *__thiscall C_GameRulesProxy::C_GameRulesProxy(C_GameRulesProxy *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_GameRulesProxy_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_GameRulesProxy::`vftable';
  C_GameRulesProxy::s_pGameRulesProxy = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E8540
// Name: public: virtual C_GameRulesProxy::~C_GameRulesProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameRulesProxy::~C_GameRulesProxy(C_GameRulesProxy *this)
{
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_GameRulesProxy_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_GameRulesProxy::`vftable';
  if ( C_GameRulesProxy::s_pGameRulesProxy == this )
    C_GameRulesProxy::s_pGameRulesProxy = nullptr;
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E8580
// Name: public: virtual class CViewVectors const __near * C_GameRules::GetViewVectors(void)const
// Source: json
//------------------------------------------------------------------------------
const CViewVectors *__thiscall C_GameRules::GetViewVectors(C_GameRules *this)
{
  return &g_DefaultViewVectors;
}

//------------------------------------------------------------------------------
// Address: 0x100E8590
// Name: public: virtual float C_GameRules::GetAmmoDamage(class C_BaseEntity __near *,class C_BaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_GameRules::GetAmmoDamage(
        C_GameRules *this,
        C_BaseEntity *pAttacker,
        C_BaseEntity *pVictim,
        int nAmmoType)
{
  CCSAmmoDef *AmmoDef; // esi

  AmmoDef = GetAmmoDef();
  if ( pAttacker->IsPlayer(this: pAttacker) )
    return (float)CAmmoDef::PlrDamage(this: AmmoDef, nAmmoIndex: nAmmoType);
  else
    return (float)CAmmoDef::NPCDamage(this: AmmoDef, nAmmoIndex: nAmmoType);
}

//------------------------------------------------------------------------------
// Address: 0x100E85F0
// Name: public: virtual int C_GameRulesProxy::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_GameRulesProxy::ObjectCaps(C_GameRulesProxy *this)
{
  return C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass((vgui::CTreeViewListControl *)this) & 0xFFFFFF7F;
}

//------------------------------------------------------------------------------
// Address: 0x100E86D0
// Name: public: virtual bool C_GameRules::ShouldCollide(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_GameRules::ShouldCollide(C_GameRules *this, int collisionGroup0, int collisionGroup1)
{
  int v3; // eax
  int v4; // ecx

  v3 = collisionGroup0;
  v4 = collisionGroup1;
  if ( collisionGroup0 > collisionGroup1 )
  {
    v3 = collisionGroup1;
    v4 = collisionGroup0;
  }
  if ( (v3 == 5 || v3 == 8) && v4 == 17 )
    return false;
  switch ( v3 )
  {
    case 1:
      if ( v4 == 17 )
        return true;
      break;
    case 13:
      if ( v4 == 21 )
        return true;
      goto LABEL_15;
    case 21:
      return false;
    default:
      break;
  }
  if ( v4 == 21 || v3 == 10 )
    return false;
LABEL_15:
  if ( v4 == 10 || v4 == 14 && v3 != 9 )
    return false;
  if ( v3 == 5 )
  {
    if ( v4 == 15 )
      return false;
LABEL_24:
    if ( v4 != 16 )
      goto LABEL_26;
    goto LABEL_25;
  }
  if ( v3 == 1 || v3 == 2 )
    return false;
  if ( v3 != 16 )
    goto LABEL_24;
LABEL_25:
  if ( v3 != 0 )
    return false;
LABEL_26:
  if ( v3 == 3 )
  {
    if ( v4 == 3 || v4 == 8 )
      return false;
    if ( v4 == 5 )
      return false;
  }
  else if ( v3 == 6 && v4 == 6 )
  {
    return false;
  }
  if ( v4 == 4 )
  {
    if ( v3 != 0 )
      return false;
  }
  else if ( v4 == 13 )
  {
    if ( v3 == 11 )
      return false;
    if ( v3 == 13 )
      return false;
  }
  else if ( v4 == 11 && (v3 == 7 || v3 == 5 || v3 == 9) )
  {
    return false;
  }
  if ( v3 != 12 && v4 != 12 )
    return true;
  return v3 == 7;
}

//------------------------------------------------------------------------------
// Address: 0x100E87D0
// Name: public: C_GameRules::C_GameRules(void)
// Source: json
//------------------------------------------------------------------------------
C_GameRules *__thiscall C_GameRules::C_GameRules(C_GameRules *this)
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name: "CGameRules");
  this->__vftable = (C_GameRules_vtbl *)&C_GameRules::`vftable';
  g_pGameRules = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E87F0
// Name: public: virtual char const __near * C_GameRules::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_GameRules::Name(C_GameRules *this)
{
  return "CGameRules";
}

//------------------------------------------------------------------------------
// Address: 0x100E8810
// Name: public: virtual C_GameRules::~C_GameRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_GameRules::~C_GameRules(C_GameRules *this)
{
  this->__vftable = (C_GameRules_vtbl *)&C_GameRules::`vftable';
  g_pGameRules = nullptr;
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x104164C0
// Name: DT_GameRulesProxy::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_GameRulesProxy::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_GameRulesProxy::g_RecvTable);
  return atexit(func: DT_GameRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104164E0
// Name: DT_GameRulesProxy::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
void DT_GameRulesProxy::_dynamic_initializer_for__g_RecvTableInit__()
{
  if ( ((int)_S5_99.m_pVarName & 1) == 0 )
  {
    _S5_99.m_pVarName = (char *)((int)_S5_99.m_pVarName | 1);
    RecvPropInt(
      result: &result,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_GameRulesProxy::g_RecvTable,
    pProps: &_S5_99,
    nProps: 0,
    pNetTableName: "DT_GameRulesProxy");
  DT_GameRulesProxy::g_RecvTableInit = 1;
}

//------------------------------------------------------------------------------
// Address: 0x104318A0
// Name: DT_GameRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_GameRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_GameRulesProxy::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100E8600
// Name: _C_GameRulesProxy_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_GameRulesProxy_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  C_GameRulesProxy *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v3 = (C_GameRulesProxy *)v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_GameRulesProxy_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientUnknown'};
  v3->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientRenderable'};
  v3->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientNetworkable'};
  v3->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_GameRulesProxy::`vftable'{for `IClientThinkable'};
  v3->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_GameRulesProxy::`vftable';
  C_GameRulesProxy::s_pGameRulesProxy = v3;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10416530
// Name: _dynamic_initializer_for__old_radius_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__old_radius_damage__()
{
  ConVar::ConVar(this: &old_radius_damage, pName: "old_radiusdamage", pDefaultValue: "0.0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__old_radius_damage__);
}

//------------------------------------------------------------------------------
// Address: 0x10416560
// Name: _dynamic_initializer_for__s_GameStats_Singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__s_GameStats_Singleton__()
{
  *((_BYTE *)&s_GameStats_Singleton + 4) &= 0xFCu;
}

//------------------------------------------------------------------------------
// Address: 0x10416570
// Name: _dynamic_initializer_for__CBGSDriver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBGSDriver__()
{
  CBaseGameStats_Driver::CBaseGameStats_Driver(this: &CBGSDriver);
  return atexit(func: dynamic_atexit_destructor_for__CBGSDriver__);
}

//------------------------------------------------------------------------------
// Address: 0x10416590
// Name: _dynamic_initializer_for__g_GameStringPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameStringPool__()
{
  CStringPool::CStringPool(this: &g_GameStringPool.CStringPool, caseSensitivity: StringPoolCaseInsensitive);
  g_GameStringPool.__vftable = (CGameStringPool_vtbl *)&CGameStringPool::`vftable';
  g_GameStringPool.m_DeferredDeleteList.m_Memory.m_pMemory = nullptr;
  g_GameStringPool.m_DeferredDeleteList.m_Memory.m_nAllocationCount = 0;
  g_GameStringPool.m_DeferredDeleteList.m_Memory.m_nGrowSize = 0;
  g_GameStringPool.m_DeferredDeleteList.m_Size = 0;
  g_GameStringPool.m_DeferredDeleteList.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_GameStringPool__);
}

//------------------------------------------------------------------------------
// Address: 0x104165E0
// Name: _dynamic_initializer_for__mp_forcecamera__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_forcecamera__()
{
  ConVar::ConVar(
    this: &mp_forcecamera,
    pName: "mp_forcecamera",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Restricts spectator modes for dead players");
  return atexit(func: dynamic_atexit_destructor_for__mp_forcecamera__);
}

//------------------------------------------------------------------------------
// Address: 0x10416610
// Name: _dynamic_initializer_for__mp_allowspectators__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_allowspectators__()
{
  ConVar::ConVar(
    this: &mp_allowspectators,
    pName: "mp_allowspectators",
    pDefaultValue: "1.0",
    flags: 0x2000,
    pHelpString: "toggles whether the server allows spectator mode or not");
  return atexit(func: dynamic_atexit_destructor_for__mp_allowspectators__);
}

//------------------------------------------------------------------------------
// Address: 0x10416640
// Name: _dynamic_initializer_for__friendlyfire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__friendlyfire__()
{
  ConVar::ConVar(
    this: &friendlyfire,
    pName: "mp_friendlyfire",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "Allows team members to injure other members of their team");
  return atexit(func: dynamic_atexit_destructor_for__friendlyfire__);
}

//------------------------------------------------------------------------------
// Address: 0x10416670
// Name: _dynamic_initializer_for__mp_fadetoblack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_fadetoblack__()
{
  ConVar::ConVar(
    this: &mp_fadetoblack,
    pName: "mp_fadetoblack",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "fade a player's screen to black when he dies");
  return atexit(func: dynamic_atexit_destructor_for__mp_fadetoblack__);
}

//------------------------------------------------------------------------------
// Address: 0x104166A0
// Name: _dynamic_initializer_for__g_CHudGeiger_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudGeiger_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudGeiger_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudGeiger,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104318B0
// Name: _dynamic_atexit_destructor_for__old_radius_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__old_radius_damage__()
{
  ConVar::~ConVar(this: &old_radius_damage);
}

//------------------------------------------------------------------------------
// Address: 0x104318C0
// Name: _dynamic_atexit_destructor_for__CBGSDriver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBGSDriver__()
{
  CBGSDriver.m_LastUserCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  CBGSDriver.m_PrevMapName.m_Storage.m_nActualLength = 0;
  if ( CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_pMemory);
      CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    CBGSDriver.m_PrevMapName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &CBGSDriver);
}

//------------------------------------------------------------------------------
// Address: 0x10431920
// Name: _dynamic_atexit_destructor_for__g_GameStringPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameStringPool__()
{
  g_GameStringPool.__vftable = (CGameStringPool_vtbl *)&CGameStringPool::`vftable';
  CGameStringPool::PurgeDeferredDeleteList(this: &g_GameStringPool);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_GameStringPool.m_DeferredDeleteList);
  IGameSystem::~IGameSystem(this: &g_GameStringPool);
  CStringPool::~CStringPool(this: &g_GameStringPool.CStringPool);
}

//------------------------------------------------------------------------------
// Address: 0x10431960
// Name: _dynamic_atexit_destructor_for__mp_forcecamera__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_forcecamera__()
{
  ConVar::~ConVar(this: &mp_forcecamera);
}

//------------------------------------------------------------------------------
// Address: 0x10431970
// Name: _dynamic_atexit_destructor_for__mp_allowspectators__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_allowspectators__()
{
  ConVar::~ConVar(this: &mp_allowspectators);
}

//------------------------------------------------------------------------------
// Address: 0x10431980
// Name: _dynamic_atexit_destructor_for__friendlyfire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__friendlyfire__()
{
  ConVar::~ConVar(this: &friendlyfire);
}

//------------------------------------------------------------------------------
// Address: 0x10431990
// Name: _dynamic_atexit_destructor_for__mp_fadetoblack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_fadetoblack__()
{
  ConVar::~ConVar(this: &mp_fadetoblack);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1014BE40
// Name: public: virtual class ServerClass __near * CGameRulesProxy::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CGameRulesProxy::GetServerClass(CGameRulesProxy *this)
{
  return &g_CGameRulesProxy_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1014BE50
// Name: public: CGameRulesProxy::CGameRulesProxy(void)
// Source: json
//------------------------------------------------------------------------------
CGameRulesProxy *__thiscall CGameRulesProxy::CGameRulesProxy(CGameRulesProxy *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CGameRulesProxy_vtbl *)&CGameRulesProxy::`vftable';
  if ( CGameRulesProxy::s_pGameRulesProxy != nullptr )
    UTIL_Remove(oldObj: CGameRulesProxy::s_pGameRulesProxy);
  CGameRulesProxy::s_pGameRulesProxy = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014BE80
// Name: public: virtual CGameRulesProxy::~CGameRulesProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRulesProxy::~CGameRulesProxy(CGameRulesProxy *this)
{
  this->__vftable = (CGameRulesProxy_vtbl *)&CGameRulesProxy::`vftable';
  if ( CGameRulesProxy::s_pGameRulesProxy == this )
    CGameRulesProxy::s_pGameRulesProxy = nullptr;
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014BEA0
// Name: public: virtual void CGameRules::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::Precache(CGameRules *this)
{
  PrecacheEffect(pEffectName: "ParticleEffect");
  PrecacheEffect(pEffectName: "ParticleEffectStop");
  PrecacheEffect(pEffectName: "GlassImpact");
  PrecacheEffect(pEffectName: "Impact");
  PrecacheEffect(pEffectName: "RagdollImpact");
  PrecacheEffect(pEffectName: "gunshotsplash");
  PrecacheEffect(pEffectName: "TracerSound");
  PrecacheEffect(pEffectName: "Tracer");
  PrecacheEffect(pEffectName: "watersplash");
  PrecacheEffect(pEffectName: "waterripple");
  PrecacheEffect(pEffectName: "bloodimpact");
}

//------------------------------------------------------------------------------
// Address: 0x1014BF20
// Name: public: virtual bool CGameRules::CanHaveAmmo(class CBaseCombatCharacter __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameRules::CanHaveAmmo(CGameRules *this, CBaseCombatCharacter *pPlayer, int iAmmoIndex)
{
  CAmmoDef *AmmoDef; // eax
  int v4; // ebx
  bool result; // al

  result = false;
  if ( iAmmoIndex > -1 )
  {
    AmmoDef = GetAmmoDef();
    v4 = CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: iAmmoIndex, owner: pPlayer);
    if ( CBaseCombatCharacter::GetAmmoCount(this: pPlayer, iAmmoIndex) < v4 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014BF60
// Name: public: virtual bool CGameRules::CanHaveAmmo(class CBaseCombatCharacter __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameRules::CanHaveAmmo(CGameRules *this, CBaseCombatCharacter *pPlayer, const char *szName)
{
  CGameRules_vtbl *v4; // edi
  CAmmoDef *AmmoDef; // eax
  int v6; // eax

  v4 = this->__vftable;
  AmmoDef = GetAmmoDef();
  v6 = CAmmoDef::Index(this: AmmoDef, psz: szName);
  return v4->CanHaveAmmo_2(this, a2: pPlayer, a3: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1014BF90
// Name: public: virtual bool CGameRules::ClientCommand(class CBaseEntity __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameRules::ClientCommand(CGameRules *this, CBasePlayer *pEdict, const CCommand *args)
{
  CVoiceGameMgr *VoiceGameMgr; // eax
  bool result; // al

  result = false;
  if ( pEdict->IsPlayer(this: pEdict) )
  {
    VoiceGameMgr = GetVoiceGameMgr();
    if ( CVoiceGameMgr::ClientCommand(this: VoiceGameMgr, pPlayer: pEdict, args) != 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014BFD0
// Name: public: virtual void CGameRules::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::FrameUpdatePostEntityThink(CGameRules *this)
{
  this->Think(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014BFE0
// Name: public: virtual float CGameRules::WeaponTraceEntity(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,unsigned int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameRules::WeaponTraceEntity(
        CGameRules *this,
        CBaseEntity *pEntity,
        const Vector *vecStart,
        const Vector *vecEnd,
        unsigned int mask,
        CGameTrace *ptr)
{
  UTIL_TraceEntity(pEntity, vecAbsStart: vecStart, vecAbsEnd: vecEnd, mask, ptr);
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1014C010
// Name: public: virtual void CGameRules::MarkAchievement(class IRecipientFilter __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::MarkAchievement(CGameRules *this, IRecipientFilter *filter, const char *pchAchievementName)
{
  ((void (__stdcall *)(Vector *, const char *, int))gamestats->Event_IncrementCountedStatistic)(
    a1: &vec3_origin,
    a2: pchAchievementName,
    a3: 1065353216);
}

//------------------------------------------------------------------------------
// Address: 0x1014C040
// Name: public: virtual struct edict_t __near * CGameRules::DoFindClientInPVS(struct edict_t __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CGameRules::DoFindClientInPVS(
        CGameRules *this,
        edict_t *pEdict,
        unsigned __int8 *pvs,
        unsigned int pvssize)
{
  return UTIL_FindClientInPVSGuts(pEdict, pvs, pvssize);
}

//------------------------------------------------------------------------------
// Address: 0x1014C060
// Name: public: virtual bool CGameRules::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameRules::Init(CGameRules *this)
{
  this->RefreshSkillData(this, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014C070
// Name: public: virtual class CViewVectors const __near * CGameRules::GetViewVectors(void)const
// Source: json
//------------------------------------------------------------------------------
const CViewVectors *__thiscall CGameRules::GetViewVectors(CGameRules *this)
{
  return &g_DefaultViewVectors;
}

//------------------------------------------------------------------------------
// Address: 0x1014C080
// Name: public: virtual float CGameRules::GetAmmoDamage(class CBaseEntity __near *,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameRules::GetAmmoDamage(
        CGameRules *this,
        CBaseEntity *pAttacker,
        CBaseEntity *pVictim,
        int nAmmoType)
{
  CAmmoDef *AmmoDef; // esi

  AmmoDef = GetAmmoDef();
  if ( pAttacker->IsPlayer(this: pAttacker) )
    return (float)CAmmoDef::PlrDamage(this: AmmoDef, nAmmoIndex: nAmmoType);
  else
    return (float)CAmmoDef::NPCDamage(this: AmmoDef, nAmmoIndex: nAmmoType);
}

//------------------------------------------------------------------------------
// Address: 0x1014C0E0
// Name: public: virtual char const __near * CGameRules::GetChatPrefix(bool,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameRules::GetChatPrefix(CGameRules *this, bool bTeamOnly, CBasePlayer *pPlayer)
{
  if ( pPlayer == nullptr || pPlayer->IsAlive(this: pPlayer) )
    return locale;
  if ( bTeamOnly )
    return "*DEAD*(TEAM)";
  return "*DEAD*";
}

//------------------------------------------------------------------------------
// Address: 0x1014C160
// Name: public: virtual bool CGameRules::IsSpawnPointValid(class CBaseEntity __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameRules::IsSpawnPointValid(CGameRules *this, CBaseEntity *pSpot, CBasePlayer *pPlayer)
{
  CBasePlayer *CurrentEntity; // esi
  CEntitySphereQuery sphere; // [esp+14h] [ebp-808h] BYREF
  int savedregs; // [esp+81Ch] [ebp+0h] BYREF

  if ( !pSpot->IsTriggered(this: pSpot, a2: pPlayer) )
    return 0;
  if ( (pSpot->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pSpot, a2: (int)&savedregs);
  CEntitySphereQuery::CEntitySphereQuery(this: &sphere, center: &pSpot->m_vecAbsOrigin, radius: 128.0, flagMask: 0);
  CurrentEntity = (CBasePlayer *)CEntitySphereQuery::GetCurrentEntity(this: &sphere);
  if ( CurrentEntity != nullptr )
  {
    while ( !CurrentEntity->IsPlayer(this: CurrentEntity) || CurrentEntity == pPlayer )
    {
      ++sphere.m_listIndex;
      CurrentEntity = (CBasePlayer *)CEntitySphereQuery::GetCurrentEntity(this: &sphere);
      if ( CurrentEntity == nullptr )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014C210
// Name: public: virtual void CGameRules::RefreshSkillData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::RefreshSkillData(CGameRules *this, bool forceUpdate)
{
  const char *pszValue; // eax
  int m_nValue; // eax
  int v5; // eax
  char szExec[256]; // [esp+4h] [ebp-108h] BYREF
  ConVarRef skill; // [esp+104h] [ebp-8h] BYREF

  if ( forceUpdate || GlobalEntity_GetIndex(pGlobalname: "skill.cfg") < 0 )
  {
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    GlobalEntity_Add(pGlobalname: "skill.cfg", pMapName: pszValue, state: GLOBAL_ON);
    ConVarRef::ConVarRef(this: &skill, pName: "skill");
    if ( ConVarRef::IsValid(this: &skill) )
      m_nValue = skill.m_pConVarState->m_Value.m_nValue;
    else
      m_nValue = 1;
    this->SetSkillLevel(this, a2: m_nValue);
    v5 = this->GetSkillLevel(this);
    V_snprintf(pDest: szExec, maxLen: 256, pFormat: "exec skill%d.cfg\n", v5);
    engine->ServerCommand(this: engine, a2: szExec);
    engine->ServerExecute(this: engine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C2E0
// Name: public: virtual void CGameRules::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::Think(CGameRules *this)
{
  CVoiceGameMgr *VoiceGameMgr; // eax
  long double frametime; // [esp+0h] [ebp-Ch]

  frametime = gpGlobals->frametime;
  VoiceGameMgr = GetVoiceGameMgr();
  CVoiceGameMgr::Update(this: VoiceGameMgr, frametime);
  if ( skill.m_pParent != nullptr )
    this->SetSkillLevel(this, a2: skill.m_pParent->m_Value.m_nValue);
  else
    this->SetSkillLevel(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014C330
// Name: public: virtual void CGameRules::CreateStandardEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::CreateStandardEntities(CGameRules *this)
{
  g_pPlayerResource = (CPlayerResource *)CBaseEntity::Create(
                                           szName: "player_manager",
                                           vecOrigin: &vec3_origin,
                                           vecAngles: &vec3_angle,
                                           pOwner: nullptr);
  g_pPlayerResource->m_iEFlags |= 0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x1014C360
// Name: public: virtual CGameRules::~CGameRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::~CGameRules(CGameRules *this)
{
  this->__vftable = (CGameRules_vtbl *)&CGameRules::`vftable';
  g_pGameRules = nullptr;
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014C380
// Name: public: virtual char const __near * CGameRules::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameRules::Name(CGameRules *this)
{
  return "CGameRules";
}

//------------------------------------------------------------------------------
// Address: 0x1014C3B0
// Name: public: virtual bool CGameRules::IsSkillLevel(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameRules::IsSkillLevel(CGameRules *this, int iLevel)
{
  return this->GetSkillLevel(this) == iLevel;
}

//------------------------------------------------------------------------------
// Address: 0x1014C3D0
// Name: public: virtual int CGameRules::GetSkillLevel(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameRules::GetSkillLevel(CGameRules *this)
{
  return g_iSkillLevel;
}

//------------------------------------------------------------------------------
// Address: 0x1014C3E0
// Name: public: virtual void CGameRules::SetSkillLevel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::SetSkillLevel(CGameRules *this, int iLevel)
{
  int v2; // eax
  int v3; // edx

  v2 = iLevel;
  v3 = g_iSkillLevel;
  if ( iLevel >= 1 )
  {
    if ( iLevel > 3 )
      v2 = 3;
  }
  else
  {
    v2 = 1;
  }
  g_iSkillLevel = v2;
  if ( v2 != v3 )
    this->OnSkillLevelChanged(this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1014C420
// Name: public: virtual char const __near * CGameRules::GetGameDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameRules::GetGameDescription(CGameRules *this)
{
  return "Half-Life 2";
}

//------------------------------------------------------------------------------
// Address: 0x1014C430
// Name: public: virtual float CGameRules::AdjustPlayerDamageInflicted(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameRules::AdjustPlayerDamageInflicted(CGameRules *this, float damage)
{
  return damage;
}

//------------------------------------------------------------------------------
// Address: 0x1014C440
// Name: public: virtual int CGameRules::NumEntityClasses(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameRules::NumEntityClasses(CGameRules *this)
{
  return 27;
}

//------------------------------------------------------------------------------
// Address: 0x1014C460
// Name: public: virtual char const __near * CGameRules::GetIndexedTeamName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameRules::GetIndexedTeamName(CGameRules *this, CBasePlayer *pPlayer)
{
  return locale;
}

//------------------------------------------------------------------------------
// Address: 0x1014C470
// Name: public: virtual class QAngle const __near & CGameRules::GetTopDownMovementAxis(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CGameRules::GetTopDownMovementAxis(CGameRules *this)
{
  return &vec3_angle;
}

//------------------------------------------------------------------------------
// Address: 0x1014C480
// Name: public: virtual bool CGameRules::ShouldCollide(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameRules::ShouldCollide(CGameRules *this, int collisionGroup0, int collisionGroup1)
{
  int v3; // eax
  int v4; // ecx

  v3 = collisionGroup0;
  v4 = collisionGroup1;
  if ( collisionGroup0 > collisionGroup1 )
  {
    v3 = collisionGroup1;
    v4 = collisionGroup0;
  }
  if ( (v3 == 5 || v3 == 8) && v4 == 17 )
    return false;
  switch ( v3 )
  {
    case 1:
      if ( v4 == 17 )
        return true;
      break;
    case 13:
      if ( v4 == 21 )
        return true;
      goto LABEL_15;
    case 21:
      return false;
    default:
      break;
  }
  if ( v4 == 21 || v3 == 10 )
    return false;
LABEL_15:
  if ( v4 == 10 || v4 == 14 && v3 != 9 )
    return false;
  if ( v3 == 5 )
  {
    if ( v4 == 15 )
      return false;
LABEL_24:
    if ( v4 != 16 )
      goto LABEL_26;
    goto LABEL_25;
  }
  if ( v3 == 1 || v3 == 2 )
    return false;
  if ( v3 != 16 )
    goto LABEL_24;
LABEL_25:
  if ( v3 != 0 )
    return false;
LABEL_26:
  if ( v3 == 3 )
  {
    if ( v4 == 3 || v4 == 8 )
      return false;
    if ( v4 == 5 )
      return false;
  }
  else if ( v3 == 6 && v4 == 6 )
  {
    return false;
  }
  if ( v4 == 4 )
  {
    if ( v3 != 0 )
      return false;
  }
  else if ( v4 == 13 )
  {
    if ( v3 == 11 )
      return false;
    if ( v3 == 13 )
      return false;
  }
  else if ( v4 == 11 && (v3 == 7 || v3 == 5 || v3 == 9) )
  {
    return false;
  }
  if ( v3 != 12 && v4 != 12 )
    return true;
  return v3 == 7;
}

//------------------------------------------------------------------------------
// Address: 0x1014C5E0
// Name: public: static void CGameRulesProxy::NotifyNetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CGameRulesProxy::NotifyNetworkStateChanged()
{
  edict_t *m_pPev; // ecx

  if ( CGameRulesProxy::s_pGameRulesProxy != nullptr )
  {
    if ( CGameRulesProxy::s_pGameRulesProxy->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&CGameRulesProxy::s_pGameRulesProxy->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = CGameRulesProxy::s_pGameRulesProxy->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        m_pPev->m_fStateFlags |= 0x101u;
        CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C610
// Name: public: CGameRules::CGameRules(void)
// Source: json
//------------------------------------------------------------------------------
CGameRules *__thiscall CGameRules::CGameRules(CGameRules *this)
{
  CVoiceGameMgr *VoiceGameMgr; // eax
  IVoiceGameMgrHelper *v4; // [esp-8h] [ebp-Ch]
  int maxClients; // [esp-4h] [ebp-8h]

  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name: "CGameRules");
  this->__vftable = (CGameRules_vtbl *)&CGameRules::`vftable';
  g_pGameRules = this;
  maxClients = gpGlobals->maxClients;
  v4 = g_pVoiceGameMgrHelper;
  VoiceGameMgr = GetVoiceGameMgr();
  CVoiceGameMgr::Init(this: VoiceGameMgr, pHelper: v4, maxClients);
  ClearMultiDamage();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014C690
// Name: bool IsExplosionTraceBlocked(class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsExplosionTraceBlocked(CGameTrace *ptr)
{
  bool result; // al
  CBaseEntity *m_pEnt; // ecx

  result = true;
  if ( !CGameTrace::DidHitWorld(this: ptr) )
  {
    m_pEnt = ptr->m_pEnt;
    if ( m_pEnt == nullptr
      || m_pEnt->m_MoveType.m_Value != 7
      || m_pEnt->m_iClassname.pszValue != "prop_door_rotating"
      && CBaseEntity::ClassMatchesComplex(this: m_pEnt, pszClassOrWildcard: "prop_door_rotating") == 0
      && !FClassnameIs(pEntity: ptr->m_pEnt, szClassname: "func_door")
      && !FClassnameIs(pEntity: ptr->m_pEnt, szClassname: "func_door_rotating") )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014C700
// Name: public: virtual void CGameRules::RadiusDamage(class CTakeDamageInfo const __near &,class Vector const __near &,float,int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CGameRules::RadiusDamage(
        CGameRules *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const CTakeDamageInfo *info,
        const Vector *vecSrcIn,
        float flRadius,
        int iClassIgnore,
        CBaseEntity *pEntityIgnore)
{
  const CTakeDamageInfo *v9; // edi
  float v10; // xmm0_4
  int (__thiscall *GetPointContents)(IEngineTrace *, const Vector *, int, IHandleEntity **); // edx
  __int16 v12; // ax
  CBaseEntity *i; // esi
  Vector *(__thiscall *BodyTarget)(CBaseEntity *, Vector *, const Vector *, bool); // edx
  CBaseEntity *Inflictor; // eax
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  CBaseEntity *v20; // eax
  CBaseEntity *v21; // eax
  int v22; // edi
  CBaseEntity *v23; // eax
  int v24; // ecx
  double v25; // st7
  float v26; // xmm0_4
  __int128 v27; // xmm1
  float m_flDamage; // xmm0_4
  CBaseEntity *Attacker; // eax
  __int128 v30; // xmm1
  CBaseEntity *v31; // eax
  CBaseEntity *v32; // eax
  CBasePlayer *v33; // esi
  CBaseCombatWeapon *ActiveWeapon; // eax
  const char *pszValue; // eax
  _DWORD v37[3]; // [esp+28h] [ebp-964h] BYREF
  CEntitySphereQuery sphere; // [esp+34h] [ebp-958h] BYREF
  float v39; // [esp+840h] [ebp-14Ch] BYREF
  float v40; // [esp+844h] [ebp-148h]
  float v41; // [esp+848h] [ebp-144h]
  _BYTE adjustedInfo[100]; // [esp+84Ch] [ebp-140h] OVERLAPPED
  Vector v43; // [esp+8BCh] [ebp-D0h] BYREF
  _BYTE v44[12]; // [esp+8C8h] [ebp-C4h] BYREF
  CGameTrace tr; // [esp+8D4h] [ebp-B8h] BYREF
  float v46; // [esp+928h] [ebp-64h]
  CGameRules *v47; // [esp+92Ch] [ebp-60h]
  int bInWater; // [esp+930h] [ebp-5Ch]
  float flAdjustedDamage; // [esp+934h] [ebp-58h]
  float v50; // [esp+938h] [ebp-54h] BYREF
  float flHalfRadiusSqr; // [esp+93Ch] [ebp-50h]
  float scale; // [esp+940h] [ebp-4Ch]
  Vector vecDeflect; // [esp+944h] [ebp-48h] BYREF
  Vector vecToTarget; // [esp+950h] [ebp-3Ch] BYREF
  float bIsPrimary; // [esp+95Ch] [ebp-30h] OVERLAPPED
  Vector dir; // [esp+960h] [ebp-2Ch] BYREF
  float falloff; // [esp+96Ch] [ebp-20h]
  float flBlockedDamagePercent; // [esp+970h] [ebp-1Ch]
  Vector vecSpot; // [esp+974h] [ebp-18h] BYREF
  Vector vecSrc; // [esp+980h] [ebp-Ch] BYREF
  float retaddr; // [esp+98Ch] [ebp+0h]

  vecSrc.x = a2;
  vecSrc.y = retaddr;
  vecSpot.z = vecSrcIn->z;
  v9 = info;
  v47 = this;
  *(_QWORD *)&vecSpot.x = *(_QWORD *)&vecSrcIn->x;
  if ( flRadius == 0.0 )
    v10 = 1.0;
  else
    v10 = info->m_flDamage / flRadius;
  GetPointContents = enginetrace->GetPointContents;
  dir.x = v10;
  v12 = ((int (__thiscall *)(IEngineTrace *, Vector *, int, _DWORD, int, int))GetPointContents)(
          a1: enginetrace,
          a2: &vecSpot,
          a3: 16432,
          a4: 0,
          a5: a3,
          a6: a4);
  vecSpot.z = vecSpot.z + 1.0;
  tr.hitbox = (v12 & 0x4030) != 0;
  *(float *)&bInWater = (float)(flRadius * 0.5) * (float)(flRadius * 0.5);
  CEntitySphereQuery::CEntitySphereQuery(
    this: (CEntitySphereQuery *)v37,
    center: &vecSpot,
    radius: flRadius,
    flagMask: 0);
  for ( i = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v37);
        i != nullptr;
        i = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v37) )
  {
    dir.y = 0.0;
    if ( i != pEntityIgnore
      && i->m_takedamage.m_Value != 0
      && (iClassIgnore == 0 || i->Classify(this: i) != iClassIgnore)
      && !(tr.hitbox != 0 ? i->m_nWaterLevel.m_Value == 0 : i->m_nWaterLevel.m_Value == 3) )
    {
      BodyTarget = i->BodyTarget;
      vecSpot.y = 0.0;
      LODWORD(vecSpot.x) = &vecSpot;
      ((void (__thiscall *)(CBaseEntity *, CBaseEntity **))BodyTarget)(a1: i, a2: &sphere.m_pList[510]);
      LODWORD(vecSpot.y) = v44;
      vecSpot.x = 0.0;
      Inflictor = CTakeDamageInfo::GetInflictor(this: v9);
      UTIL_TraceLine(
        a1: (const IHandleEntity *)&vecSrc,
        a2: (int)i,
        vecAbsStart: &vecSpot,
        vecAbsEnd: (Vector *)&dir.z,
        mask: 0x6004003u,
        ignore: Inflictor,
        collisionGroup: SLODWORD(vecSpot.x),
        ptr: (CGameTrace *)LODWORD(vecSpot.y));
      if ( old_radius_damage.m_pParent != nullptr && old_radius_damage.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( tr.plane.normal.z == 1.0 || *(CBaseEntity **)&tr.surface.surfaceProps == i )
          goto LABEL_34;
      }
      else
      {
        if ( tr.plane.normal.z == 1.0 )
          goto LABEL_34;
        if ( !IsExplosionTraceBlocked(ptr: (CGameTrace *)v44) )
          goto LABEL_24;
        if ( v47->ShouldUseRobustRadiusDamage(this: v47, a2: i)
          && (float)((float)((float)((float)(falloff - vecSpot.y) * (float)(falloff - vecSpot.y))
                           + (float)((float)(dir.z - vecSpot.x) * (float)(dir.z - vecSpot.x)))
                   + (float)((float)(flBlockedDamagePercent - vecSpot.z) * (float)(flBlockedDamagePercent - vecSpot.z))) <= *(float *)&bInWater )
        {
          vecDeflect.x = dir.z - tr.startpos.x;
          vecDeflect.y = falloff - tr.startpos.y;
          vecDeflect.z = flBlockedDamagePercent - tr.startpos.z;
          VectorNormalize(vec: &vecDeflect);
          v17 = (float)(tr.endpos.z * vecDeflect.y) - (float)(tr.endpos.y * vecDeflect.z);
          v18 = (float)(tr.endpos.x * vecDeflect.z) - (float)(tr.endpos.z * vecDeflect.x);
          v19 = (float)(tr.endpos.y * vecDeflect.x) - (float)(tr.endpos.x * vecDeflect.y);
          v50 = (float)(tr.endpos.y * v19) - (float)(tr.endpos.z * v18);
          flHalfRadiusSqr = (float)(tr.endpos.z * v17) - (float)(tr.endpos.x * v19);
          scale = (float)(tr.endpos.x * v18) - (float)(tr.endpos.y * v17);
          VectorNormalize(vec: (Vector *)&v50);
          v43.y = tr.startpos.y + (float)(flHalfRadiusSqr * 16.0);
          LODWORD(vecSpot.y) = v44;
          vecSpot.x = 0.0;
          v43.x = tr.startpos.x + (float)(v50 * 16.0);
          v43.z = tr.startpos.z + (float)(scale * 16.0);
          v20 = CTakeDamageInfo::GetInflictor(this: v9);
          UTIL_TraceLine(
            a1: (const IHandleEntity *)&vecSrc,
            a2: (int)i,
            vecAbsStart: &tr.startpos,
            vecAbsEnd: &v43,
            mask: 0x6004003u,
            ignore: v20,
            collisionGroup: SLODWORD(vecSpot.x),
            ptr: (CGameTrace *)LODWORD(vecSpot.y));
          LODWORD(vecSpot.y) = v44;
          vecSpot.x = 0.0;
          v21 = CTakeDamageInfo::GetInflictor(this: v9);
          UTIL_TraceLine(
            a1: (const IHandleEntity *)&vecSrc,
            a2: (int)i,
            vecAbsStart: &tr.startpos,
            vecAbsEnd: (Vector *)&dir.z,
            mask: 0x6004003u,
            ignore: v21,
            collisionGroup: SLODWORD(vecSpot.x),
            ptr: (CGameTrace *)LODWORD(vecSpot.y));
          if ( tr.plane.normal.z == 1.0 || !CGameTrace::DidHitWorld(this: (CGameTrace *)v44) )
          {
LABEL_24:
            v22 = *(_DWORD *)&tr.surface.surfaceProps;
            if ( *(_DWORD *)&tr.surface.surfaceProps == 0
              || *(CBaseEntity **)&tr.surface.surfaceProps == i
              || CBaseEntity::GetOwnerEntity(this: *(CBaseEntity **)&tr.surface.surfaceProps) == i )
            {
              goto LABEL_33;
            }
            LODWORD(vecSpot.y) = v44;
            vecSpot.x = 0.0;
            v23 = CTakeDamageInfo::GetInflictor(this: info);
            UTIL_TraceLine(
              a1: (const IHandleEntity *)&vecSrc,
              a2: (int)i,
              vecAbsStart: &vecSpot,
              vecAbsEnd: (Vector *)&dir.z,
              mask: 1u,
              ignore: v23,
              collisionGroup: SLODWORD(vecSpot.x),
              ptr: (CGameTrace *)LODWORD(vecSpot.y));
            if ( tr.plane.normal.z == 1.0 )
            {
              v24 = *(_DWORD *)(v22 + 328);
              if ( v24 == 0 )
              {
                v26 = 0.25;
                goto LABEL_32;
              }
              v25 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v24 + 116))(a1: v24) * 0.0028571428;
              flAdjustedDamage = v25;
              if ( v25 < 1.0 )
              {
                v26 = flAdjustedDamage;
LABEL_32:
                dir.y = v26;
LABEL_33:
                v9 = info;
LABEL_34:
                v27 = 0;
                m_flDamage = v9->m_flDamage;
                *(float *)&v27 = fsqrt(
                                   (float)((float)((float)(vecSpot.x - tr.startpos.x)
                                                 * (float)(vecSpot.x - tr.startpos.x))
                                         + (float)((float)(vecSpot.y - tr.startpos.y)
                                                 * (float)(vecSpot.y - tr.startpos.y)))
                                 + (float)((float)(vecSpot.z - tr.startpos.z) * (float)(vecSpot.z - tr.startpos.z)));
                *(_OWORD *)&adjustedInfo[84] = v27;
                v46 = m_flDamage - (float)(*(float *)&v27 * dir.x);
                if ( v46 > 0.0 )
                {
                  if ( tr.plane.pad[1] != 0 )
                  {
                    tr.startpos = vecSpot;
                    tr.plane.normal.z = 0.0;
                  }
                  CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&v39, __that: v9);
                  *(float *)&adjustedInfo[64] = flRadius;
                  *(float *)&adjustedInfo[36] = v46 - (float)(v46 * dir.y);
                  if ( CTakeDamageInfo::GetAttacker(this: v9) != nullptr )
                  {
                    Attacker = CTakeDamageInfo::GetAttacker(this: v9);
                    if ( Attacker->IsPlayer(this: Attacker) && i->IsNPC(this: i) )
                      CTakeDamageInfo::AdjustPlayerDamageInflictedForSkillLevel(this: (CTakeDamageInfo *)&v39);
                  }
                  vecToTarget.y = dir.z - vecSpot.x;
                  vecToTarget.z = falloff - vecSpot.y;
                  bIsPrimary = flBlockedDamagePercent - vecSpot.z;
                  VectorNormalize(vec: (Vector *)&vecToTarget.y);
                  if ( vec3_origin.x == *(float *)adjustedInfo
                    && vec3_origin.y == *(float *)&adjustedInfo[4]
                    && vec3_origin.z == *(float *)&adjustedInfo[8]
                    || vec3_origin.x == v39 && vec3_origin.y == v40 && vec3_origin.z == v41 )
                  {
                    if ( (*(_WORD *)&adjustedInfo[48] & 0x800) == 0 )
                      CalculateExplosiveDamageForce(
                        info: (CTakeDamageInfo *)&v39,
                        vecDir: (Vector *)&vecToTarget.y,
                        vecForceOrigin: &vecSpot,
                        flScale: 1.0);
                  }
                  else
                  {
                    v30 = 0;
                    *(float *)&v30 = fsqrt((float)((float)(v39 * v39) + (float)(v41 * v41)) + (float)(v40 * v40));
                    *(_OWORD *)&adjustedInfo[84] = v30;
                    *(Vector *)adjustedInfo = vecSpot;
                    v39 = vecToTarget.y * (float)(*(float *)&v30 * dir.x);
                    v40 = vecToTarget.z * (float)(*(float *)&v30 * dir.x);
                    v41 = bIsPrimary * (float)(*(float *)&v30 * dir.x);
                  }
                  if ( tr.plane.normal.z == 1.0 || i != *(CBaseEntity **)&tr.surface.surfaceProps )
                  {
                    CBaseEntity::TakeDamage(this: i, a2: (int)i, inputInfo: (const CTakeDamageInfo *)&v39);
                  }
                  else
                  {
                    ClearMultiDamage();
                    CBaseEntity::DispatchTraceAttack(
                      this: i,
                      info: (const CTakeDamageInfo *)&v39,
                      vecDir: (Vector *)&vecToTarget.y,
                      ptr: (CGameTrace *)v44);
                    ApplyMultiDamage();
                  }
                  CBaseEntity::TraceAttackToTriggers(
                    this: i,
                    a2: (int)&vecSrc,
                    info: (const CTakeDamageInfo *)&v39,
                    start: &vecSpot,
                    end: &tr.startpos,
                    dir: (Vector *)&vecToTarget.y);
                  if ( CTakeDamageInfo::GetAttacker(this: v9) != nullptr )
                  {
                    v31 = CTakeDamageInfo::GetAttacker(this: v9);
                    if ( v31->IsPlayer(this: v31)
                      && *(_DWORD *)&tr.surface.surfaceProps != 0
                      && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps + 300))(a1: *(_DWORD *)&tr.surface.surfaceProps) != 0 )
                    {
                      LOBYTE(vecToTarget.x) = 1;
                      v32 = CTakeDamageInfo::GetAttacker(this: v9);
                      v33 = ToBasePlayer(pEntity: v32);
                      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v33);
                      if ( ActiveWeapon != nullptr )
                      {
                        if ( FClassnameIs(pEntity: ActiveWeapon, szClassname: "weapon_smg1") )
                          LOBYTE(vecToTarget.x) = 0;
                        pszValue = CBaseCombatCharacter::GetActiveWeapon(this: v33)->m_iClassname.pszValue;
                        if ( pszValue == nullptr )
                          pszValue = locale;
                      }
                      else
                      {
                        pszValue = "NULL";
                      }
                      gamestats->Event_WeaponHit(
                        this: gamestats,
                        a2: v33,
                        a3: LODWORD(vecToTarget.x),
                        a4: pszValue,
                        a5: v9);
                    }
                  }
                }
                goto LABEL_66;
              }
            }
            v9 = info;
          }
        }
      }
    }
LABEL_66:
    ++v37[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014CF60
// Name: public: virtual void CGameRules::EndGameFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::EndGameFrame(CGameRules *this)
{
  CBaseEntity *m_pEntity; // ecx
  CBaseEntity *v2; // edi
  CBaseEntity *v3; // esi
  const char *v4; // eax
  const char *v5; // [esp-8h] [ebp-1Ch]
  const char *DebugName; // [esp-4h] [ebp-18h]
  double m_flDamage; // [esp+0h] [ebp-14h]

  if ( g_MultiDamage.m_hTarget.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber == HIWORD(g_MultiDamage.m_hTarget.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity != nullptr )
  {
    if ( g_MultiDamage.m_hAttacker.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hAttacker.m_Index)].m_SerialNumber != HIWORD(g_MultiDamage.m_hAttacker.m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hAttacker.m_Index)].m_pEntity;
    }
    if ( g_MultiDamage.m_hInflictor.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hInflictor.m_Index)].m_SerialNumber != HIWORD(g_MultiDamage.m_hInflictor.m_Index) )
    {
      v2 = nullptr;
    }
    else
    {
      v2 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hInflictor.m_Index)].m_pEntity;
    }
    if ( g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber == HIWORD(g_MultiDamage.m_hTarget.m_Index) )
      v3 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity;
    else
      v3 = nullptr;
    m_flDamage = g_MultiDamage.m_flDamage;
    DebugName = CBaseEntity::GetDebugName(this: m_pEntity);
    v5 = CBaseEntity::GetDebugName(this: v2);
    v4 = CBaseEntity::GetDebugName(this: v3);
    _Warning(
      a1: "Unapplied multidamage left in the system:\nTarget: %s\nInflictor: %s\nAttacker: %s\nDamage: %.2f\n",
      v4,
      v5,
      DebugName,
      m_flDamage);
    ApplyMultiDamage();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D050
// Name: public: virtual void CGameRules::ClientSettingsChanged(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRules::ClientSettingsChanged(CGameRules *this, CBasePlayer *pPlayer)
{
  CBasePlayer *v2; // esi
  edict_t *m_pPev; // eax
  const char *v4; // ebx
  const char *v5; // edi
  IGameEvent *v6; // esi
  int v7; // eax
  signed int v8; // eax
  const char *v9; // eax
  int v10; // eax

  v2 = pPlayer;
  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  v4 = engine->GetClientConVarValue(this: engine, a2: m_pPev, a3: "name");
  v5 = pPlayer->GetPlayerName(this: pPlayer);
  if ( _V_strcmp(s1: v5, s2: v4) != 0 )
  {
    if ( *v5 != 0 )
    {
      v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_changename", a3: 0, a4: 0);
      if ( v6 != nullptr )
      {
        v7 = engine->GetPlayerUserId(this: engine, a2: pPlayer->m_Network.m_pPev);
        v6->SetInt(this: v6, a2: "userid", a3: v7);
        v6->SetString(this: v6, a2: "oldname", a3: v5);
        v6->SetString(this: v6, a2: "newname", a3: v4);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v6, a3: false);
      }
      v2 = pPlayer;
    }
    CBasePlayer::SetPlayerName(this: v2, name: v4);
  }
  v8 = (signed int)v2->m_Network.m_pPev;
  if ( v8 != 0 )
    v8 = (signed int)(v8 - (unsigned int)gpGlobals->pEdicts) >> 4;
  v9 = engine->GetClientConVarValue(this: engine, a2: v8, a3: "fov_desired");
  if ( v9 != nullptr )
  {
    v10 = atoi(nptr: v9);
    if ( v10 >= 1 )
    {
      if ( v10 > 90 )
        v10 = 90;
      CBasePlayer::SetDefaultFOV(this: v2, FOV: v10);
    }
    else
    {
      CBasePlayer::SetDefaultFOV(this: v2, FOV: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D190
// Name: public: virtual class CBaseEntity __near * CGameRules::GetPlayerSpawnSpot(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGameRules::GetPlayerSpawnSpot(CGameRules *this, CBasePlayer *pPlayer)
{
  CBaseEntity *result; // eax
  CBaseEntity *v3; // ebx
  Vector origin; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  result = pPlayer->EntSelectSpawnPoint(this: pPlayer);
  v3 = result;
  if ( result != nullptr )
  {
    if ( (result->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: result, a2: (int)&savedregs);
    origin.x = v3->m_vecAbsOrigin.x;
    origin.y = v3->m_vecAbsOrigin.y;
    origin.z = v3->m_vecAbsOrigin.z + 1.0;
    CBaseEntity::SetLocalOrigin(this: pPlayer, &origin);
    CBaseEntity::SetAbsVelocity(this: pPlayer, vecAbsVelocity: &vec3_origin);
    CBaseEntity::SetLocalAngles(this: pPlayer, angles: &v3->m_angRotation.m_Value);
    if ( vec3_angle.x != pPlayer->m_Local.m_vecPunchAngle.m_Value.x
      || vec3_angle.y != pPlayer->m_Local.m_vecPunchAngle.m_Value.y
      || vec3_angle.z != pPlayer->m_Local.m_vecPunchAngle.m_Value.z )
    {
      pPlayer->m_Local.NetworkStateChanged(this: &pPlayer->m_Local, a2: &pPlayer->m_Local.m_vecPunchAngle);
      pPlayer->m_Local.m_vecPunchAngle.m_Value = vec3_angle;
    }
    if ( vec3_angle.x != pPlayer->m_Local.m_vecPunchAngleVel.m_Value.x
      || vec3_angle.y != pPlayer->m_Local.m_vecPunchAngleVel.m_Value.y
      || vec3_angle.z != pPlayer->m_Local.m_vecPunchAngleVel.m_Value.z )
    {
      pPlayer->m_Local.NetworkStateChanged(this: &pPlayer->m_Local, a2: &pPlayer->m_Local.m_vecPunchAngleVel);
      pPlayer->m_Local.m_vecPunchAngleVel.m_Value = vec3_angle;
    }
    CBasePlayer::SnapEyeAngles(this: pPlayer, viewAngles: &v3->m_angRotation.m_Value);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10252FA0
// Name: public: virtual bool CGameRules::FPlayerCanTakeDamage(class CBasePlayer __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameRules::FPlayerCanTakeDamage(CAI_BaseNPC *this, const Vector *vecSightDir, float sightDist)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10404B30
// Name: DT_GameRulesProxy::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_GameRulesProxy::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_GameRulesProxy::g_SendTable);
  return atexit(func: DT_GameRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10404B50
// Name: DT_GameRulesProxy::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_GameRulesProxy::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_GameRulesProxy::ignored>();
  DT_GameRulesProxy::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BCB0
// Name: DT_GameRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_GameRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_GameRulesProxy::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10404B60
// Name: _dynamic_initializer_for__old_radius_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__old_radius_damage__()
{
  ConVar::ConVar(this: &old_radius_damage, pName: "old_radiusdamage", pDefaultValue: "0.0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__old_radius_damage__);
}

//------------------------------------------------------------------------------
// Address: 0x10404B90
// Name: _dynamic_initializer_for__skill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__skill__()
{
  ConVar::ConVar(this: &skill, pName: "skill", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__skill__);
}

//------------------------------------------------------------------------------
// Address: 0x10404BC0
// Name: _dynamic_initializer_for__s_GameStats_Singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GameStats_Singleton__()
{
  BasicGameStats_t::BasicGameStats_t(this: &s_GameStats_Singleton.m_BasicStats);
  *((_BYTE *)&s_GameStats_Singleton + 84) &= 0xFCu;
  return atexit(func: dynamic_atexit_destructor_for__s_GameStats_Singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x10404BE0
// Name: _dynamic_initializer_for__CBGSDriver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBGSDriver__()
{
  CBaseGameStats_Driver::CBaseGameStats_Driver(this: &CBGSDriver);
  return atexit(func: dynamic_atexit_destructor_for__CBGSDriver__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BCC0
// Name: _dynamic_atexit_destructor_for__old_radius_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__old_radius_damage__()
{
  ConVar::~ConVar(this: &old_radius_damage);
}

//------------------------------------------------------------------------------
// Address: 0x1041BCD0
// Name: _dynamic_atexit_destructor_for__skill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__skill__()
{
  ConVar::~ConVar(this: &skill);
}

//------------------------------------------------------------------------------
// Address: 0x1041BCE0
// Name: _ServerClassInit_DT_GameRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_GameRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp::~SendProp(this: g_SendProps_63);
}

} // namespace server
