// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_ssg08.cpp
// Functions: 15
// ============================================================

#include "game\shared\cstrike15\weapon_ssg08.h"

//------------------------------------------------------------------------------
// Address: 0x10234CB0
// Name: public: virtual class ClientClass __near * C_WeaponSSG08::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponSSG08::GetClientClass(C_WeaponSSG08 *this)
{
  return &__g_C_WeaponSSG08ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10234D30
// Name: public: virtual struct datamap_t __near * C_WeaponSSG08::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponSSG08::GetPredDescMap(C_WeaponSSG08 *this)
{
  return &C_WeaponSSG08::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10234D40
// Name: public: virtual void weapon_ssg08Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_ssg08Precache::CResourcePrecacher::Cache(
        weapon_ssg08Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_ssg08",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10234D70
// Name: public: virtual float C_WeaponSSG08::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_WeaponSSG08::GetMaxSpeed(C_WeaponSSG08 *this)
{
  int v2; // eax
  int v3; // esi
  float v5; // [esp+8h] [ebp-8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 == 0 )
    return C_WeaponCSBase::GetMaxSpeed(this);
  v5 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v2 + 1148))(a1: v2);
  if ( v5 == (double)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 1152))(a1: v3) )
    return C_WeaponCSBase::GetMaxSpeed(this);
  else
    return 220.0;
}

//------------------------------------------------------------------------------
// Address: 0x10234DD0
// Name: public: virtual void C_WeaponSSG08::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponSSG08::PrimaryAttack(C_WeaponSSG08 *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  C_BasePlayer *v4; // eax
  C_BasePlayer *v5; // esi
  double v6; // st7
  float (__thiscall *GetFOV)(C_BasePlayer *); // eax
  double v8; // st7
  int v9; // eax
  int v10; // eax
  CSWeaponMode m_Value; // [esp+8h] [ebp-18h]
  QAngle angle; // [esp+10h] [ebp-10h] BYREF
  float v13; // [esp+1Ch] [ebp-4h]

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0 )
    {
      C_WeaponCSBase::GetPlayerOwner(this);
      v5 = v4;
      if ( v4 != nullptr )
      {
        if ( this->m_weaponMode.m_Value == Secondary_Mode )
        {
          v6 = ((double (__thiscall *)(C_BasePlayer *))v4->GetFOV)(a1: v4);
          GetFOV = v5->GetFOV;
          v13 = fabs(v6 - 40.0);
          v8 = ((double (__thiscall *)(C_BasePlayer *))GetFOV)(a1: v5);
          v9 = 40;
          if ( fabs(v8 - 15.0) <= v13 )
            v9 = 15;
          if ( v5[1].m_VarMap.m_Entries.m_pElements != (VarMapEntry_t *)v9 )
            v5[1].m_VarMap.m_Entries.m_pElements = (VarMapEntry_t *)v9;
          if ( LOBYTE(v5[1].m_VarMap.m_Entries.m_Size) != 1 )
            LOBYTE(v5[1].m_VarMap.m_Entries.m_Size) = 1;
          v10 = v5->GetDefaultFOV(this: v5);
          C_BasePlayer::SetFOV(this: v5, pRequester: v5, FOV: v10, zoomRate: 0.050000001, iZoomStart: 0);
          if ( this->m_weaponMode.m_Value != Primary_Mode )
            this->m_weaponMode.m_Value = Primary_Mode;
        }
        if ( weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
        {
          angle = *v5->GetPunchAngle(this: v5);
          angle.x = angle.x - 2.0;
          C_BasePlayer::SetPunchAngle(this: v5, &angle);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234F20
// Name: public: virtual enum CSWeaponID C_WeaponSSG08::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponSSG08::GetCSWeaponID(C_WeaponSSG08 *this)
{
  return 30;
}

//------------------------------------------------------------------------------
// Address: 0x10234FA0
// Name: CC_WeaponSSG08Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponSSG08Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponSSG08::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponSSG08::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponSSG08::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponSSG08::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponSSG08::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429A00
// Name: DT_WeaponSSG08::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSSG08::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponSSG08::g_RecvTable);
  return atexit(func: DT_WeaponSSG08::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429A20
// Name: DT_WeaponSSG08::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSSG08::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponSSG08::ignored>();
  DT_WeaponSSG08::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429A30
// Name: C_WeaponSSG08_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponSSG08_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponSSG08::m_PredMap.dataNumFields = 1;
  C_WeaponSSG08::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C73C;
}

//------------------------------------------------------------------------------
// Address: 0x10429A80
// Name: weapon_ssg08Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_ssg08Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_ssg08Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_ssg08Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104361E0
// Name: DT_WeaponSSG08::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponSSG08::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponSSG08::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10234F30
// Name: _C_WeaponSSG08_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponSSG08_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponSSG08::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponSSG08::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponSSG08::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponSSG08::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponSSG08::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429A50
// Name: _dynamic_initializer_for__g_Cweapon_ssg08Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_ssg08Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_ssg08",
             a3: "C_WeaponSSG08",
             a4: 3504,
             a5: CC_WeaponSSG08Factory);
  __g_C_WeaponSSG08ClientClass.m_pMapClassname = "weapon_ssg08";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429AA0
// Name: _dynamic_initializer_for____g_C_WeaponTaserClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponTaserClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponTaserClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponTaserClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F2290
// Name: public: virtual bool CWeaponSSG08::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponSSG08::Deploy(CWeaponAug *this)
{
  edict_t *m_pPev; // ecx

  if ( this->m_weaponMode.m_Value != Primary_Mode )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_weaponMode.m_Value = Primary_Mode;
      return CWeaponCSBase::Deploy(this);
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x57Cu);
    this->m_weaponMode.m_Value = Primary_Mode;
  }
  return CWeaponCSBase::Deploy(this);
}

//------------------------------------------------------------------------------
// Address: 0x102F2A80
// Name: public: virtual class ServerClass __near * CWeaponSSG08::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponSSG08::GetServerClass(CWeaponSSG08 *this)
{
  return &g_CWeaponSSG08_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F2A90
// Name: public: virtual void weapon_ssg08Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_ssg08Precache::CResourcePrecacher::Cache(
        weapon_ssg08Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_ssg08",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F2AC0
// Name: public: virtual float CWeaponSSG08::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWeaponSSG08::GetMaxSpeed(CWeaponSSG08 *this)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v3; // esi
  int FOV; // ebx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner == nullptr )
    return CWeaponCSBase::GetMaxSpeed(this);
  FOV = CBasePlayer::GetFOV(this: PlayerOwner);
  if ( FOV == CBasePlayer::GetDefaultFOV(this: v3) )
    return CWeaponCSBase::GetMaxSpeed(this);
  else
    return 220.0;
}

//------------------------------------------------------------------------------
// Address: 0x102F2B80
// Name: public: virtual void CWeaponSSG08::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponSSG08::SecondaryAttack(CWeaponSSG08 *this)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v3; // edi
  int FOV; // esi
  edict_t *m_pPev; // ecx
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float v8; // xmm0_4
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  int DefaultFOV; // eax
  edict_t *v12; // ecx
  float v13; // xmm0_4
  edict_t *v14; // ecx
  IGameEvent *v15; // esi
  int v16; // eax

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner != nullptr )
  {
    FOV = CBasePlayer::GetFOV(this: PlayerOwner);
    if ( FOV == CBasePlayer::GetDefaultFOV(this: v3) )
    {
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 40, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x57Cu);
        }
        this->m_weaponMode.m_Value = Secondary_Mode;
      }
      CSWpnData = CWeaponCSBase::GetCSWpnData(this);
      m_Value = this->m_fAccuracyPenalty.m_Value;
      v8 = CSWpnData->m_fInaccuracyAltSwitch + m_Value;
      if ( m_Value != v8 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_fAccuracyPenalty.m_Value = v8;
        }
        else
        {
          v9 = this->m_Network.m_pPev;
          if ( v9 != nullptr )
            CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x580u);
          this->m_fAccuracyPenalty.m_Value = v8;
        }
      }
    }
    else if ( CBasePlayer::GetFOV(this: v3) == 40 )
    {
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 15, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_weaponMode.m_Value = Secondary_Mode;
        }
        else
        {
          v10 = this->m_Network.m_pPev;
          if ( v10 != nullptr )
            CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x57Cu);
          this->m_weaponMode.m_Value = Secondary_Mode;
        }
      }
    }
    else if ( CBasePlayer::GetFOV(this: v3) == 15 )
    {
      DefaultFOV = CBasePlayer::GetDefaultFOV(this: v3);
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: DefaultFOV, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Primary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = this->m_Network.m_pPev;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x57Cu);
        }
        this->m_weaponMode.m_Value = Primary_Mode;
      }
    }
    v13 = gpGlobals->curtime + 0.30000001;
    if ( this->m_flNextSecondaryAttack.m_Value != v13 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v14 = this->m_Network.m_pPev;
        if ( v14 != nullptr )
          CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x498u);
      }
      this->m_flNextSecondaryAttack.m_Value = v13;
    }
    CBaseEntity::EmitSound(this: v3, soundname: "Default.Zoom", soundtime: 0.0, duration: nullptr);
    v15 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "weapon_zoom", a3: 0, a4: 0);
    if ( v15 != nullptr )
    {
      v16 = engine->GetPlayerUserId(this: engine, a2: v3->m_Network.m_pPev);
      v15->SetInt(this: v15, a2: "userid", a3: v16);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v15, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2E00
// Name: public: virtual void CWeaponSSG08::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponSSG08::PrimaryAttack(CWeaponSSG08 *this@<ecx>, int a2@<ebx>)
{
  const CCSWeaponInfo *CSWpnData; // eax
  CCSPlayer *PlayerOwner; // eax
  CCSPlayer *v5; // edi
  CBaseEdict *v6; // ecx
  CBaseEdict *v7; // ecx
  CBaseEdict *v8; // ecx
  int DefaultFOV; // eax
  edict_t *m_pPev; // ecx
  CSWeaponMode m_Value; // [esp+8h] [ebp-1Ch]
  QAngle angle; // [esp+14h] [ebp-10h] BYREF
  float v13; // [esp+20h] [ebp-4h]

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0 )
    {
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      v5 = PlayerOwner;
      if ( PlayerOwner != nullptr )
      {
        if ( this->m_weaponMode.m_Value == Secondary_Mode )
        {
          LODWORD(v13) = COERCE_UNSIGNED_INT((float)CBasePlayer::GetFOV(this: PlayerOwner) - 40.0) & _mask__AbsFloat_;
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)CBasePlayer::GetFOV(this: v5) - 15.0) & _mask__AbsFloat_) <= v13 )
          {
            if ( v5->m_iLastZoom.m_Value != 15 )
            {
              if ( v5->m_Network.m_TimerEvent.m_bRegistered )
              {
                *((_BYTE *)&v5->m_Network + 76) |= 1u;
              }
              else
              {
                v7 = &v5->m_Network.m_pPev->CBaseEdict;
                if ( v7 != nullptr )
                  CBaseEdict::StateChanged(this: v7, offset: 0x130Cu);
              }
              v5->m_iLastZoom.m_Value = 15;
            }
          }
          else if ( v5->m_iLastZoom.m_Value != 40 )
          {
            if ( v5->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v5->m_Network + 76) |= 1u;
              v5->m_iLastZoom.m_Value = 40;
            }
            else
            {
              v6 = &v5->m_Network.m_pPev->CBaseEdict;
              if ( v6 != nullptr )
                CBaseEdict::StateChanged(this: v6, offset: 0x130Cu);
              v5->m_iLastZoom.m_Value = 40;
            }
          }
          if ( !v5->m_bResumeZoom.m_Value )
          {
            if ( v5->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v5->m_Network + 76) |= 1u;
            }
            else
            {
              v8 = &v5->m_Network.m_pPev->CBaseEdict;
              if ( v8 != nullptr )
                CBaseEdict::StateChanged(this: v8, offset: 0x1308u);
            }
            v5->m_bResumeZoom.m_Value = true;
          }
          DefaultFOV = CBasePlayer::GetDefaultFOV(this: v5);
          CBasePlayer::SetFOV(this: v5, pRequester: v5, FOV: DefaultFOV, zoomRate: 0.050000001, iZoomStart: 0);
          if ( this->m_weaponMode.m_Value != Primary_Mode )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x57Cu);
            }
            this->m_weaponMode.m_Value = Primary_Mode;
          }
        }
        if ( weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
        {
          angle = CBasePlayer::GetPunchAngle(this: v5)->m_Value;
          angle.x = angle.x - 2.0;
          CBasePlayer::SetPunchAngle(this: v5, punchAngle: &angle);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2FF0
// Name: public: virtual enum CSWeaponID CWeaponSSG08::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponSSG08::GetCSWeaponID(CWeaponSSG08 *this)
{
  return 30;
}

//------------------------------------------------------------------------------
// Address: 0x10413300
// Name: DT_WeaponSSG08::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSSG08::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponSSG08::g_SendTable);
  return atexit(func: DT_WeaponSSG08::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413320
// Name: DT_WeaponSSG08::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSSG08::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponSSG08::ignored>();
  DT_WeaponSSG08::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413350
// Name: weapon_ssg08Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_ssg08Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_ssg08Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_ssg08Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420EF0
// Name: DT_WeaponSSG08::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponSSG08::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponSSG08::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10413370
// Name: _dynamic_initializer_for__g_CWeaponTaser_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponTaser_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponTaser_ClassReg,
           pNetworkName: "CWeaponTaser",
           pTable: &DT_WeaponTaser::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420F00
// Name: _ServerClassInit_DT_WeaponSSG08::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponSSG08::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_301;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
