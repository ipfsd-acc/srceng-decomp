// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_deagle.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_deagle.h"

//------------------------------------------------------------------------------
// Address: 0x1022DA90
// Name: public: virtual class ClientClass __near * C_DEagle::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_DEagle::GetClientClass(C_DEagle *this)
{
  return &__g_C_DEagleClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022DB10
// Name: public: virtual struct datamap_t __near * C_DEagle::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_DEagle::GetPredDescMap(C_DEagle *this)
{
  return &C_DEagle::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022DB20
// Name: public: virtual void weapon_deaglePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_deaglePrecache::CResourcePrecacher::Cache(
        weapon_deaglePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_deagle",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022DB50
// Name: public: virtual bool C_DEagle::SendWeaponAnim(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_DEagle::SendWeaponAnim(C_DEagle *this, Activity iActivity)
{
  Activity v2; // eax

  v2 = iActivity;
  if ( iActivity == ACT_VM_PRIMARYATTACK && this->m_iClip1.m_Value == 1 )
    v2 = ACT_VM_DRYFIRE;
  return C_WeaponCSBase::SendWeaponAnim(this, iActivity: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1022DBF0
// Name: CC_DEagleFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_DEagleFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_DEagle::`vftable'{for `IClientUnknown'};
  v1[1] = &C_DEagle::`vftable'{for `IClientRenderable'};
  v1[2] = &C_DEagle::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_DEagle::`vftable'{for `IClientThinkable'};
  v1[4] = &C_DEagle::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428570
// Name: DT_WeaponDEagle::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponDEagle::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponDEagle::g_RecvTable);
  return atexit(func: DT_WeaponDEagle::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428590
// Name: DT_WeaponDEagle::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponDEagle::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponDEagle::ignored>();
  DT_WeaponDEagle::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104285A0
// Name: C_DEagle_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_DEagle_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_DEagle::m_PredMap.dataNumFields = 1;
  C_DEagle::m_PredMap.dataDesc = (typedescription_t *)&unk_1066AEF4;
}

//------------------------------------------------------------------------------
// Address: 0x104285F0
// Name: weapon_deaglePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_deaglePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_deaglePrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_deaglePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436020
// Name: DT_WeaponDEagle::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponDEagle::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponDEagle::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022DB80
// Name: _C_DEagle_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_DEagle_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_DEagle::`vftable'{for `IClientUnknown'};
  v3[1] = &C_DEagle::`vftable'{for `IClientRenderable'};
  v3[2] = &C_DEagle::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_DEagle::`vftable'{for `IClientThinkable'};
  v3[4] = &C_DEagle::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104285C0
// Name: _dynamic_initializer_for__g_Cweapon_deagleFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_deagleFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_deagle",
             a3: "C_DEagle",
             a4: 3504,
             a5: CC_DEagleFactory);
  __g_C_DEagleClientClass.m_pMapClassname = "weapon_deagle";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428610
// Name: _dynamic_initializer_for____g_C_DecoyGrenadeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_DecoyGrenadeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_DecoyGrenadeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_DecoyGrenadeClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100B3140
// Name: public: virtual enum CSWeaponID CDEagle::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDEagle::GetCSWeaponID(CBaseCombatWeapon *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EAE30
// Name: public: virtual class ServerClass __near * CDEagle::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CDEagle::GetServerClass(CDEagle *this)
{
  return &g_CDEagle_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EAE40
// Name: public: virtual void weapon_deaglePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_deaglePrecache::CResourcePrecacher::Cache(
        weapon_deaglePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_deagle",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EAE70
// Name: public: virtual bool CDEagle::SendWeaponAnim(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDEagle::SendWeaponAnim(CDEagle *this, int iActivity)
{
  int v2; // eax

  v2 = iActivity;
  if ( iActivity == 190 && this->m_iClip1.m_Value == 1 )
    v2 = 193;
  return CWeaponCSBase::SendWeaponAnim(this, iActivity: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10412300
// Name: DT_WeaponDEagle::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponDEagle::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponDEagle::g_SendTable);
  return atexit(func: DT_WeaponDEagle::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412320
// Name: DT_WeaponDEagle::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponDEagle::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponDEagle::ignored>();
  DT_WeaponDEagle::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412350
// Name: weapon_deaglePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_deaglePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_deaglePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_deaglePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420940
// Name: DT_WeaponDEagle::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponDEagle::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponDEagle::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412370
// Name: _dynamic_initializer_for__g_CDecoyGrenade_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CDecoyGrenade_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CDecoyGrenade_ClassReg,
           pNetworkName: "CDecoyGrenade",
           pTable: &DT_DecoyGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420950
// Name: _ServerClassInit_DT_WeaponDEagle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponDEagle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_274;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
