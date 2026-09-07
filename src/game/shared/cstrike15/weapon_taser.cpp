// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_taser.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_taser.h"

//------------------------------------------------------------------------------
// Address: 0x10234FF0
// Name: public: virtual class ClientClass __near * C_WeaponTaser::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponTaser::GetClientClass(C_WeaponTaser *this)
{
  return &__g_C_WeaponTaserClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10235070
// Name: public: virtual struct datamap_t __near * C_WeaponTaser::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponTaser::GetPredDescMap(C_WeaponTaser *this)
{
  return &C_WeaponTaser::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10235080
// Name: public: virtual void weapon_taserPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_taserPrecache::CResourcePrecacher::Cache(
        weapon_taserPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_taser",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102350B0
// Name: public: virtual void C_WeaponTaser::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponTaser::PrimaryAttack(C_WeaponTaser *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode) != 0 )
      this->m_fFireTime = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102350F0
// Name: public: virtual enum CSWeaponID C_WeaponTaser::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponTaser::GetCSWeaponID(C_WeaponTaser *this)
{
  return 22;
}

//------------------------------------------------------------------------------
// Address: 0x10235170
// Name: CC_WeaponTaserFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponTaserFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponTaser::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponTaser::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponTaser::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponTaser::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponTaser::`vftable';
  v1[876] = 0;
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429AC0
// Name: DT_WeaponTaser::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponTaser::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponTaser::g_RecvTable);
  return atexit(func: DT_WeaponTaser::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429AE0
// Name: DT_WeaponTaser::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponTaser::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponTaser::ignored>();
  DT_WeaponTaser::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429AF0
// Name: C_WeaponTaser_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponTaser_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponTaser::m_PredMap.dataNumFields = 1;
  C_WeaponTaser::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C814;
}

//------------------------------------------------------------------------------
// Address: 0x10429B40
// Name: weapon_taserPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_taserPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_taserPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_taserPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104361F0
// Name: DT_WeaponTaser::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponTaser::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponTaser::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10235100
// Name: _C_WeaponTaser_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponTaser_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponTaser::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponTaser::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponTaser::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponTaser::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponTaser::`vftable';
  v3[876] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429B10
// Name: _dynamic_initializer_for__g_Cweapon_taserFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_taserFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_taser",
             a3: "C_WeaponTaser",
             a4: 3512,
             a5: CC_WeaponTaserFactory);
  __g_C_WeaponTaserClientClass.m_pMapClassname = "weapon_taser";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429B60
// Name: _dynamic_initializer_for____g_C_WeaponTec9ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponTec9ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponTec9ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponTec9ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F3040
// Name: public: virtual class ServerClass __near * CWeaponTaser::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponTaser::GetServerClass(CWeaponTaser *this)
{
  return &g_CWeaponTaser_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F3050
// Name: public: virtual void weapon_taserPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_taserPrecache::CResourcePrecacher::Cache(
        weapon_taserPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_taser",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F3080
// Name: public: virtual void CWeaponTaser::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponTaser::PrimaryAttack(CWeaponTaser *this@<ecx>, int a2@<ebx>)
{
  const CCSWeaponInfo *CSWpnData; // eax

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode) != 0 )
      this->m_fFireTime = gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F30C0
// Name: public: virtual bool CWeaponTaser::Holster(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CWeaponTaser::Holster@<al>(CWeaponTaser *this@<ecx>, int a2@<ebx>, CBaseCombatWeapon *pSwitchingTo)
{
  CCSPlayer *PlayerOwner; // eax

  if ( !this->HasAmmo(this) )
  {
    PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
    CCSPlayer::CSWeaponDrop(this: PlayerOwner, a2, pWeapon: this, bDropShield: true, bThrowForward: false);
  }
  return CWeaponCSBase::Holster(this, pSwitchingTo);
}

//------------------------------------------------------------------------------
// Address: 0x102F3100
// Name: public: virtual void CWeaponTaser::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponTaser::ItemPostFrame(CWeaponTaser *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // eax

  CWeaponCSBaseGun::ItemPostFrame(this);
  if ( !this->HasAmmo(this) && gpGlobals->curtime >= (float)(this->m_fFireTime + 2.5) )
  {
    PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
    CCSPlayer::CSWeaponDrop(this: PlayerOwner, a2, pWeapon: this, bDropShield: true, bThrowForward: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F31E0
// Name: public: virtual enum CSWeaponID CWeaponTaser::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponTaser::GetCSWeaponID(CWeaponTaser *this)
{
  return 22;
}

//------------------------------------------------------------------------------
// Address: 0x10413390
// Name: DT_WeaponTaser::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponTaser::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponTaser::g_SendTable);
  return atexit(func: DT_WeaponTaser::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104133B0
// Name: DT_WeaponTaser::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponTaser::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponTaser::ignored>();
  DT_WeaponTaser::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104133E0
// Name: weapon_taserPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_taserPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_taserPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_taserPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420F20
// Name: DT_WeaponTaser::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponTaser::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponTaser::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10413400
// Name: _dynamic_initializer_for__g_CWeaponTec9_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponTec9_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponTec9_ClassReg,
           pNetworkName: "CWeaponTec9",
           pTable: &DT_WeaponTec9::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420F30
// Name: _ServerClassInit_DT_WeaponTaser::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponTaser::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_302;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
