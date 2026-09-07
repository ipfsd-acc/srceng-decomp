// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_hkp2000.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_hkp2000.h"

//------------------------------------------------------------------------------
// Address: 0x1022FDB0
// Name: public: virtual class ClientClass __near * C_WeaponHKP2000::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponHKP2000::GetClientClass(C_WeaponHKP2000 *this)
{
  return &__g_C_WeaponHKP2000ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022FE30
// Name: public: virtual struct datamap_t __near * C_WeaponHKP2000::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponHKP2000::GetPredDescMap(C_WeaponHKP2000 *this)
{
  return &C_WeaponHKP2000::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022FE40
// Name: public: virtual void weapon_hkp2000Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_hkp2000Precache::CResourcePrecacher::Cache(
        weapon_hkp2000Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_hkp2000",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022FE70
// Name: public: virtual void C_WeaponHKP2000::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponHKP2000::PrimaryAttack(C_WeaponHKP2000 *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  C_BasePlayer *v4; // eax
  C_BasePlayer *v5; // esi
  CSWeaponMode m_Value; // [esp+4h] [ebp-14h]
  QAngle angle; // [esp+Ch] [ebp-Ch] BYREF

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0 )
    {
      C_WeaponCSBase::GetPlayerOwner(this);
      v5 = v4;
      if ( v4 != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        angle = *v4->GetPunchAngle(this: v4);
        angle.x = angle.x - 2.0;
        C_BasePlayer::SetPunchAngle(this: v5, &angle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022FF10
// Name: public: virtual enum CSWeaponID C_WeaponHKP2000::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponHKP2000::GetCSWeaponID(C_WeaponHKP2000 *this)
{
  return 23;
}

//------------------------------------------------------------------------------
// Address: 0x1022FF90
// Name: CC_WeaponHKP2000Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponHKP2000Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponHKP2000::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponHKP2000::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponHKP2000::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponHKP2000::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponHKP2000::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428CF0
// Name: DT_WeaponHKP2000::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponHKP2000::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponHKP2000::g_RecvTable);
  return atexit(func: DT_WeaponHKP2000::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428D10
// Name: DT_WeaponHKP2000::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponHKP2000::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponHKP2000::ignored>();
  DT_WeaponHKP2000::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428D20
// Name: C_WeaponHKP2000_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponHKP2000_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponHKP2000::m_PredMap.dataNumFields = 1;
  C_WeaponHKP2000::m_PredMap.dataDesc = (typedescription_t *)&unk_1066B7D4;
}

//------------------------------------------------------------------------------
// Address: 0x10428D70
// Name: weapon_hkp2000Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_hkp2000Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_hkp2000Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_hkp2000Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104360C0
// Name: DT_WeaponHKP2000::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponHKP2000::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponHKP2000::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022FF20
// Name: _C_WeaponHKP2000_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponHKP2000_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponHKP2000::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponHKP2000::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponHKP2000::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponHKP2000::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponHKP2000::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10428D40
// Name: _dynamic_initializer_for__g_Cweapon_hkp2000Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_hkp2000Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_hkp2000",
             a3: "C_WeaponHKP2000",
             a4: 3504,
             a5: CC_WeaponHKP2000Factory);
  __g_C_WeaponHKP2000ClientClass.m_pMapClassname = "weapon_hkp2000";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428D90
// Name: _dynamic_initializer_for____g_C_KnifeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_KnifeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_KnifeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_KnifeClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102ED540
// Name: public: virtual class ServerClass __near * CWeaponHKP2000::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponHKP2000::GetServerClass(CWeaponHKP2000 *this)
{
  return &g_CWeaponHKP2000_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102ED550
// Name: public: virtual void weapon_hkp2000Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_hkp2000Precache::CResourcePrecacher::Cache(
        weapon_hkp2000Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_hkp2000",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102ED690
// Name: public: virtual enum CSWeaponID CWeaponHKP2000::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponHKP2000::GetCSWeaponID(CWeaponHKP2000 *this)
{
  return 23;
}

//------------------------------------------------------------------------------
// Address: 0x104128D0
// Name: DT_WeaponHKP2000::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponHKP2000::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponHKP2000::g_SendTable);
  return atexit(func: DT_WeaponHKP2000::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104128F0
// Name: DT_WeaponHKP2000::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponHKP2000::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponHKP2000::ignored>();
  DT_WeaponHKP2000::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412920
// Name: weapon_hkp2000Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_hkp2000Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_hkp2000Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_hkp2000Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420B50
// Name: DT_WeaponHKP2000::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponHKP2000::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponHKP2000::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420B60
// Name: _ServerClassInit_DT_WeaponHKP2000::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponHKP2000::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_284;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
