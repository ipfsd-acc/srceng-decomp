// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_p250.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_p250.h"

//------------------------------------------------------------------------------
// Address: 0x10233570
// Name: public: virtual class ClientClass __near * C_WeaponP250::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponP250::GetClientClass(C_WeaponP250 *this)
{
  return &__g_C_WeaponP250ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102335F0
// Name: public: virtual struct datamap_t __near * C_WeaponP250::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponP250::GetPredDescMap(C_WeaponP250 *this)
{
  return &C_WeaponP250::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10233600
// Name: public: virtual void weapon_p250Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_p250Precache::CResourcePrecacher::Cache(
        weapon_p250Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_p250",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10233630
// Name: public: virtual enum CSWeaponID C_WeaponP250::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponP250::GetCSWeaponID(C_WeaponP250 *this)
{
  return 27;
}

//------------------------------------------------------------------------------
// Address: 0x102336B0
// Name: CC_WeaponP250Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponP250Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponP250::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponP250::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponP250::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponP250::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponP250::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429580
// Name: DT_WeaponP250::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponP250::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponP250::g_RecvTable);
  return atexit(func: DT_WeaponP250::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104295A0
// Name: DT_WeaponP250::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponP250::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponP250::ignored>();
  DT_WeaponP250::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104295B0
// Name: C_WeaponP250_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponP250_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponP250::m_PredMap.dataNumFields = 1;
  C_WeaponP250::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C22C;
}

//------------------------------------------------------------------------------
// Address: 0x10429600
// Name: weapon_p250Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_p250Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_p250Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_p250Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436180
// Name: DT_WeaponP250::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponP250::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponP250::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10233640
// Name: _C_WeaponP250_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponP250_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponP250::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponP250::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponP250::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponP250::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponP250::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104295D0
// Name: _dynamic_initializer_for__g_Cweapon_p250Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_p250Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_p250",
             a3: "C_WeaponP250",
             a4: 3504,
             a5: CC_WeaponP250Factory);
  __g_C_WeaponP250ClientClass.m_pMapClassname = "weapon_p250";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429620
// Name: _dynamic_initializer_for____g_C_WeaponP90ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponP90ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponP90ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponP90ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102ED600
// Name: public: virtual void CWeaponP250::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponP250::PrimaryAttack(CWeaponHKP2000 *this@<ecx>, int a2@<ebx>)
{
  const CCSWeaponInfo *CSWpnData; // eax
  CCSPlayer *PlayerOwner; // esi
  CSWeaponMode m_Value; // [esp+4h] [ebp-14h]
  QAngle angle; // [esp+Ch] [ebp-Ch] BYREF

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0 )
    {
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      if ( PlayerOwner != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        angle = CBasePlayer::GetPunchAngle(this: PlayerOwner)->m_Value;
        angle.x = angle.x - 2.0;
        CBasePlayer::SetPunchAngle(this: PlayerOwner, punchAngle: &angle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F1040
// Name: public: virtual class ServerClass __near * CWeaponP250::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponP250::GetServerClass(CWeaponP250 *this)
{
  return &g_CWeaponP250_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F1050
// Name: public: virtual void weapon_p250Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_p250Precache::CResourcePrecacher::Cache(
        weapon_p250Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_p250",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10412F90
// Name: DT_WeaponP250::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponP250::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponP250::g_SendTable);
  return atexit(func: DT_WeaponP250::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412FB0
// Name: DT_WeaponP250::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponP250::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponP250::ignored>();
  DT_WeaponP250::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412FE0
// Name: weapon_p250Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_p250Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_p250Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_p250Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420DC0
// Name: DT_WeaponP250::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponP250::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponP250::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10413000
// Name: _dynamic_initializer_for__g_CWeaponP90_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponP90_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponP90_ClassReg,
           pNetworkName: "CWeaponP90",
           pTable: &DT_WeaponP90::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420DD0
// Name: _ServerClassInit_DT_WeaponP250::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponP250::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_295;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
