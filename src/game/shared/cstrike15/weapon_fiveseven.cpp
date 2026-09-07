// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_fiveseven.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_fiveseven.h"

//------------------------------------------------------------------------------
// Address: 0x1022E9E0
// Name: public: virtual class ClientClass __near * C_WeaponFiveSeven::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponFiveSeven::GetClientClass(C_WeaponFiveSeven *this)
{
  return &__g_C_WeaponFiveSevenClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022EA60
// Name: public: virtual struct datamap_t __near * C_WeaponFiveSeven::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponFiveSeven::GetPredDescMap(C_WeaponFiveSeven *this)
{
  return &C_WeaponFiveSeven::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022EA70
// Name: public: virtual void weapon_fivesevenPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_fivesevenPrecache::CResourcePrecacher::Cache(
        weapon_fivesevenPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_fiveseven",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022EAA0
// Name: public: virtual void C_WeaponFiveSeven::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponFiveSeven::PrimaryAttack(C_DEagle *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  CSWeaponMode m_Value; // [esp+4h] [ebp-18h]
  QAngle punchAngle; // [esp+10h] [ebp-Ch] BYREF

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0
      && weapon_recoil_legacy.m_pParent != nullptr
      && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      punchAngle = *v3->GetPunchAngle(this: v3);
      punchAngle.x = punchAngle.x - 2.0;
      C_BasePlayer::SetPunchAngle(this: v3, angle: &punchAngle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022EBA0
// Name: CC_WeaponFiveSevenFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponFiveSevenFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponFiveSeven::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponFiveSeven::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponFiveSeven::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponFiveSeven::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponFiveSeven::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428870
// Name: DT_WeaponFiveSeven::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponFiveSeven::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponFiveSeven::g_RecvTable);
  return atexit(func: DT_WeaponFiveSeven::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428890
// Name: DT_WeaponFiveSeven::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponFiveSeven::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponFiveSeven::ignored>();
  DT_WeaponFiveSeven::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104288A0
// Name: C_WeaponFiveSeven_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponFiveSeven_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponFiveSeven::m_PredMap.dataNumFields = 1;
  C_WeaponFiveSeven::m_PredMap.dataDesc = (typedescription_t *)&unk_1066B28C;
}

//------------------------------------------------------------------------------
// Address: 0x104288F0
// Name: weapon_fivesevenPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_fivesevenPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_fivesevenPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_fivesevenPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436060
// Name: DT_WeaponFiveSeven::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponFiveSeven::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponFiveSeven::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022EB30
// Name: _C_WeaponFiveSeven_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponFiveSeven_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponFiveSeven::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponFiveSeven::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponFiveSeven::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponFiveSeven::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponFiveSeven::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104288C0
// Name: _dynamic_initializer_for__g_Cweapon_fivesevenFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_fivesevenFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_fiveseven",
             a3: "C_WeaponFiveSeven",
             a4: 3504,
             a5: CC_WeaponFiveSevenFactory);
  __g_C_WeaponFiveSevenClientClass.m_pMapClassname = "weapon_fiveseven";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428910
// Name: _dynamic_initializer_for____g_C_FlashbangClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FlashbangClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FlashbangClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FlashbangClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EBE50
// Name: public: virtual class ServerClass __near * CWeaponFiveSeven::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponFiveSeven::GetServerClass(CWeaponFiveSeven *this)
{
  return &g_CWeaponFiveSeven_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EBE60
// Name: public: virtual void weapon_fivesevenPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_fivesevenPrecache::CResourcePrecacher::Cache(
        weapon_fivesevenPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_fiveseven",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EBF10
// Name: public: virtual void CWeaponFiveSeven::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponFiveSeven::PrimaryAttack(CDEagle *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  CSWeaponMode m_Value; // [esp+4h] [ebp-18h]
  QAngle punchAngle; // [esp+10h] [ebp-Ch] BYREF

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0
      && weapon_recoil_legacy.m_pParent != nullptr
      && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      punchAngle = CBasePlayer::GetPunchAngle(this: PlayerOwner)->m_Value;
      punchAngle.x = punchAngle.x - 2.0;
      CBasePlayer::SetPunchAngle(this: PlayerOwner, &punchAngle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBFA0
// Name: public: virtual enum CSWeaponID CWeaponFiveSeven::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponFiveSeven::GetCSWeaponID(CWeaponFiveSeven *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10412550
// Name: DT_WeaponFiveSeven::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponFiveSeven::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponFiveSeven::g_SendTable);
  return atexit(func: DT_WeaponFiveSeven::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412570
// Name: DT_WeaponFiveSeven::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponFiveSeven::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponFiveSeven::ignored>();
  DT_WeaponFiveSeven::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104125A0
// Name: weapon_fivesevenPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_fivesevenPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_fivesevenPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_fivesevenPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A10
// Name: DT_WeaponFiveSeven::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponFiveSeven::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponFiveSeven::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104125C0
// Name: _dynamic_initializer_for__g_CFlashbang_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFlashbang_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFlashbang_ClassReg,
           pNetworkName: "CFlashbang",
           pTable: &DT_Flashbang::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420A20
// Name: _ServerClassInit_DT_WeaponFiveSeven::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponFiveSeven::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_278;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
