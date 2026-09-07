// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_c4.cpp
// Functions: 26
// ============================================================

#include "game\shared\cstrike15\weapon_c4.h"

//------------------------------------------------------------------------------
// Address: 0x10229FD0
// Name: public: virtual class ClientClass __near * C_C4::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_C4::GetClientClass(C_C4 *this)
{
  return &__g_C_C4ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022A0C0
// Name: public: virtual struct datamap_t __near * C_C4::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_C4::GetPredDescMap(C_C4 *this)
{
  return &C_C4::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022A0D0
// Name: public: virtual void weapon_c4Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_c4Precache::CResourcePrecacher::Cache(
        weapon_c4Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_c4",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022A100
// Name: public: virtual void C_C4::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_C4::Spawn(C_C4 *this)
{
  C_BaseCombatWeapon::Spawn(this);
  C_BaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  this->m_takedamage = 0;
  this->m_bBombPlanted = false;
}

//------------------------------------------------------------------------------
// Address: 0x1022A130
// Name: public: virtual void C_C4::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_C4::ItemPostFrame(C_C4 *this)
{
  int v2; // eax
  bool v3; // zf
  C_C4_vtbl *v4; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    v3 = (*(_BYTE *)(v2 + 5304) & 0x21) == 0;
    v4 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( v3 )
      v4->WeaponIdle(this);
    else
      v4->PrimaryAttack(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022A160
// Name: public: virtual bool C_C4::OnFireEvent(class C_BaseViewModel __near *,class Vector const __near &,class QAngle const __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_C4::OnFireEvent(
        C_C4 *this,
        C_BaseViewModel *pViewModel,
        const Vector *origin,
        const QAngle *angles,
        int event,
        char *options)
{
  if ( event != 7001 )
    return C_WeaponCSBase::OnFireEvent(this, pViewModel, origin, angles, event, options);
  V_strncpy(pDest: this->m_szScreenText, pSrc: options, maxLen: 16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022A1B0
// Name: public: virtual void C_C4::UpdateShieldState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_C4::UpdateShieldState(C_C4 *this)
{
  int v2; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
    C_WeaponCSBase::GetPlayerOwner(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022A1D0
// Name: public: char __near * C_C4::GetScreenText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_C4::GetScreenText(C_C4 *this)
{
  char *result; // eax

  result = this->m_szScreenText;
  if ( !this->m_bStartedArming.m_Value )
    return (char *)prType;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022A1F0
// Name: public: virtual float C_C4::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_C4::GetMaxSpeed(C_C4 *this)
{
  if ( this->m_bStartedArming.m_Value )
    return 1.0;
  else
    return C_WeaponCSBase::GetMaxSpeed(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022A210
// Name: public: void C_C4::AbortBombPlant(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_C4::AbortBombPlant(C_C4 *this)
{
  int v1; // eax
  int v2; // esi
  int v3; // eax
  const Vector *v4; // [esp-Ch] [ebp-18h]
  _BYTE v5[12]; // [esp+0h] [ebp-Ch] BYREF

  if ( this->m_bStartedArming.m_Value )
    this->m_bStartedArming.m_Value = false;
  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v1 != 0 )
  {
    v2 = v1 + 8;
    v4 = (const Vector *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v1 + 988))(a1: v1, a2: v5);
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 40))(a1: v2);
    FX_PlantBomb(iPlayerIndex: v3, vOrigin: v4, option: PLANTBOMB_ABORT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022A260
// Name: public: virtual enum CSWeaponID C_C4::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_C4::GetCSWeaponID(C_C4 *this)
{
  return 37;
}

//------------------------------------------------------------------------------
// Address: 0x1022A270
// Name: public: virtual void C_C4::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_C4::PrimaryAttack(C_C4 *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax
  vgui::PropertyPage *v4; // ecx
  int v5; // edi
  bool v6; // zf
  int v7; // eax
  C_BaseEntity *GroundEntity; // ebx
  float v9; // xmm0_4
  int v10; // eax
  float v11; // xmm0_4
  C_C4_vtbl *v12; // edi
  float v13; // xmm1_4
  float m_Value; // xmm0_4
  float v15; // xmm0_4
  bool (__thiscall *SendWeaponAnim)(C_BaseCombatWeapon *, int); // eax
  const Vector *flMaxVal; // [esp+Ch] [ebp-24h]
  float v18; // [esp+10h] [ebp-20h]
  PlantBombOption_t option[3]; // [esp+20h] [ebp-10h] BYREF
  int onGround; // [esp+2Ch] [ebp-4h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v5 = v3;
  if ( v3 == 0 )
    return;
  v7 = *(_DWORD *)(v3 + 248) & 1;
  v6 = (*(_DWORD *)(v5 + 248) & 1) == 0;
  onGround = v7;
  if ( !v6 )
  {
    GroundEntity = C_BaseEntity::GetGroundEntity(this: (C_BaseEntity *)v5);
    if ( GroundEntity != nullptr
      && (GroundEntity->IsPlayer(this: GroundEntity)
       || IsPushableEntity(pEnt: GroundEntity)
       || IsPushAwayEntity(pEnt: GroundEntity)) )
    {
      onGround = 0;
    }
    v7 = onGround;
  }
  LOBYTE(v4) = this->m_bStartedArming.m_Value;
  if ( (_BYTE)v4 != 0 || this->m_bBombPlanted )
  {
    if ( v7 == 0 || *(_BYTE *)(v5 + 6792) == 0 )
    {
      C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v4);
      C_C4::AbortBombPlant(this);
      SendWeaponAnim = this->SendWeaponAnim;
      if ( this->m_bBombPlacedAnimation.m_Value )
        SendWeaponAnim(this, a2: 181);
      else
        SendWeaponAnim(this, a2: 183);
      return;
    }
    v13 = *(float *)(gpGlobals.m_Index + 12);
    m_Value = this->m_fArmedTime.m_Value;
    if ( v13 < m_Value )
    {
      if ( v13 >= (float)(m_Value - 0.75) && !this->m_bBombPlacedAnimation.m_Value )
      {
        if ( !this->m_bBombPlacedAnimation.m_Value )
          this->m_bBombPlacedAnimation.m_Value = true;
        this->SendWeaponAnim(this, a2: 191);
      }
      goto LABEL_20;
    }
    if ( (_BYTE)v4 == 0 )
    {
LABEL_20:
      v11 = *(float *)(gpGlobals.m_Index + 12) + 0.3;
      if ( this->m_flNextPrimaryAttack.m_Value != v11 )
        this->m_flNextPrimaryAttack.m_Value = v11;
      v12 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v18 = SharedRandomFloat(sharedname: "C4IdleTime", flMinVal: 10.0, flMaxVal: 15.0, additionalSeed: 0)
          + *(float *)(gpGlobals.m_Index + 12);
      ((void (__thiscall *)(C_C4 *, _DWORD))v12->SetWeaponIdleTime)(a1: this, a2: LODWORD(v18));
      return;
    }
    if ( this->m_bStartedArming.m_Value )
      this->m_bStartedArming.m_Value = false;
    if ( this->m_fArmedTime.m_Value != 0.0 )
      this->m_fArmedTime.m_Value = 0.0;
    if ( *(_BYTE *)(v5 + 6792) != 0 )
    {
      this->m_bBombPlanted = true;
      return;
    }
  }
  else
  {
    LOBYTE(v4) = *(_BYTE *)(v5 + 6792);
    if ( (_BYTE)v4 != 0 && v7 != 0 )
    {
      if ( !this->m_bStartedArming.m_Value )
        this->m_bStartedArming.m_Value = true;
      v9 = *(float *)(gpGlobals.m_Index + 12) + 3.0;
      if ( this->m_fArmedTime.m_Value != v9 )
        this->m_fArmedTime.m_Value = v9;
      if ( this->m_bBombPlacedAnimation.m_Value )
        this->m_bBombPlacedAnimation.m_Value = false;
      ((void (__thiscall *)(C_C4 *, int, int))this->SendWeaponAnim)(a1: this, a2: 190, a3: a2);
      flMaxVal = (const Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 988))(a1: v5);
      v10 = (*(int (__thiscall **)(int))(*(_DWORD *)(v5 + 8) + 40))(a1: v5 + 8);
      FX_PlantBomb(iPlayerIndex: v10, vOrigin: flMaxVal, (PlantBombOption_t)option);
      goto LABEL_20;
    }
  }
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v4);
  v15 = *(float *)(gpGlobals.m_Index + 12) + 1.0;
  if ( this->m_flNextPrimaryAttack.m_Value != v15 )
    this->m_flNextPrimaryAttack.m_Value = v15;
}

//------------------------------------------------------------------------------
// Address: 0x1022A5B0
// Name: public: virtual void C_C4::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_C4::WeaponIdle(C_C4 *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // edi
  bool (__thiscall *SendWeaponAnim)(C_BaseCombatWeapon *, int); // eax
  const Vector *v8; // [esp-Ch] [ebp-1Ch]
  _BYTE v9[12]; // [esp+4h] [ebp-Ch] BYREF

  if ( this->m_bStartedArming.m_Value )
  {
    this->m_bStartedArming.m_Value = false;
    C_WeaponCSBase::GetPlayerOwner(this);
    if ( v2 != 0 )
    {
      v3 = v2 + 8;
      v8 = (const Vector *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v2 + 988))(a1: v2, a2: v9);
      v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 40))(a1: v3);
      FX_PlantBomb(iPlayerIndex: v4, vOrigin: v8, option: PLANTBOMB_ABORT);
    }
    C_WeaponCSBase::GetPlayerOwner(this);
    v6 = v5;
    if ( v5 != 0 )
    {
      this->SendWeaponAnim(this, a2: 183);
      *(float *)(v6 + 4256) = *(float *)(gpGlobals.m_Index + 12);
    }
    SendWeaponAnim = this->SendWeaponAnim;
    if ( this->m_bBombPlacedAnimation.m_Value )
      SendWeaponAnim(this, a2: 181);
    else
      SendWeaponAnim(this, a2: 183);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022A660
// Name: public: virtual void C_C4::Drop(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_C4::Drop(C_C4 *this, C_BaseCombatCharacter *vecVelocity)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  const Vector *v6; // [esp-Ch] [ebp-1Ch]
  _BYTE v7[12]; // [esp+4h] [ebp-Ch] BYREF

  if ( this->m_bStartedArming.m_Value )
  {
    this->m_bStartedArming.m_Value = false;
    C_WeaponCSBase::GetPlayerOwner(this);
    if ( v3 != 0 )
    {
      v4 = v3 + 8;
      v6 = (const Vector *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v3 + 988))(a1: v3, a2: v7);
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 40))(a1: v4);
      FX_PlantBomb(iPlayerIndex: v5, vOrigin: v6, option: PLANTBOMB_ABORT);
    }
  }
  C_C4::OnPickedUp(this, pNewOwner: vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x1022A6C0
// Name: public: C_C4::C_C4(void)
// Source: json
//------------------------------------------------------------------------------
C_C4 *__thiscall C_C4::C_C4(C_C4 *this)
{
  int m_Size; // eax
  int v3; // edi
  C_C4 **m_pMemory; // ecx
  int v5; // eax
  C_C4 **v6; // eax

  C_WeaponCSBase::C_WeaponCSBase(this);
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_C4_vtbl *)&C_C4::`vftable'{for `IClientUnknown'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_C4::`vftable'{for `IClientRenderable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_C4::`vftable'{for `IClientNetworkable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_C4::`vftable'{for `IClientThinkable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_C4::`vftable';
  m_Size = g_C4s.m_Size;
  v3 = g_C4s.m_Size;
  if ( g_C4s.m_Size + 1 > g_C4s.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_C4s,
      num: g_C4s.m_Size - g_C4s.m_Memory.m_nAllocationCount + 1);
    m_Size = g_C4s.m_Size;
  }
  m_pMemory = g_C4s.m_Memory.m_pMemory;
  g_C4s.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_C4s.m_pElements = g_C4s.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_C4s.m_Memory.m_pMemory[v3 + 1],
      src: (unsigned __int8 *)&g_C4s.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = g_C4s.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  this->m_bDroppedFromDeath = false;
  this->m_szScreenText[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022A830
// Name: CC_C4Factory
// Source: json
//------------------------------------------------------------------------------
C_C4 *__cdecl CC_C4Factory()
{
  C_C4 *v0; // eax

  v0 = (C_C4 *)C_BaseEntity::operator new(stAllocateBlock: 0xDE8u);
  if ( v0 != nullptr )
    return C_C4::C_C4(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1022AC90
// Name: public: virtual void C_C4::OnPickedUp(class C_BaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_C4::OnPickedUp(C_C4 *this, C_BaseCombatCharacter *pNewOwner)
{
  CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: (int)pNewOwner);
}

//------------------------------------------------------------------------------
// Address: 0x10427ED0
// Name: DT_WeaponC4::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponC4::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponC4::g_RecvTable);
  return atexit(func: DT_WeaponC4::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10427EF0
// Name: DT_WeaponC4::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponC4::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponC4::ignored>();
  DT_WeaponC4::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427F00
// Name: C_C4_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_C4_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_C4::m_PredMap.dataNumFields = 3;
  C_C4::m_PredMap.dataDesc = (typedescription_t *)&unk_105B5574;
}

//------------------------------------------------------------------------------
// Address: 0x10427F50
// Name: weapon_c4Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_c4Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_c4Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_c4Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435E60
// Name: DT_WeaponC4::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponC4::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponC4::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022A7E0
// Name: _C_C4_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_C4_CreateObject(int entnum, int serialNum)
{
  C_C4 *v2; // eax
  C_C4 *v3; // eax
  C_C4 *v4; // esi

  v2 = (C_C4 *)C_BaseEntity::operator new(stAllocateBlock: 0xDE8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_C4::C_C4(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10427F20
// Name: _dynamic_initializer_for__g_Cweapon_c4Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_c4Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_C4 *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_c4",
             a3: "C_C4",
             a4: 3560,
             a5: CC_C4Factory);
  __g_C_C4ClientClass.m_pMapClassname = "weapon_c4";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427F70
// Name: _dynamic_initializer_for__g_C4s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_C4s__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_C4s__);
}

//------------------------------------------------------------------------------
// Address: 0x10435E70
// Name: _dynamic_atexit_destructor_for__g_C4s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_C4s__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_C4s);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10175EA0
// Name: public: virtual int CPlantedC4::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlantedC4::ShouldTransmit(CMultiplayRules *this, CBasePlayer *pPlayer)
{
  return 8;
}

//------------------------------------------------------------------------------
// Address: 0x102E4CE0
// Name: public: virtual void planted_c4Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall planted_c4Precache::CResourcePrecacher::Cache(
        planted_c4Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "planted_c4",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E4D10
// Name: public: virtual struct datamap_t __near * CPlantedC4::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPlantedC4::GetDataDescMap(CPlantedC4 *this)
{
  return &CPlantedC4::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E4D20
// Name: public: virtual class ServerClass __near * CPlantedC4::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPlantedC4::GetServerClass(CPlantedC4 *this)
{
  return &g_CPlantedC4_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102E4D30
// Name: public: virtual void CPlantedC4::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPlantedC4::Precache(CPlantedC4 *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  _DWORD v2[3]; // [esp+0h] [ebp-18h] BYREF
  _DWORD v3[3]; // [esp+Ch] [ebp-Ch] BYREF

  g_sModelIndexC4Glow = CBaseEntity::PrecacheModel(a1: a2, name: "sprites/ledglow.vmt", bPreload: true);
  CBaseEntity::PrecacheModel(a1: a2, name: "models/weapons/w_c4_planted.mdl", bPreload: true);
  PrecacheVGuiScreen(pScreenType: "c4_panel");
  v3[0] = 1091567616;
  v3[1] = 1094713344;
  v3[2] = 1093664768;
  v2[0] = -1059061760;
  v2[1] = -1051721728;
  v2[2] = -1069547520;
  engine->ForceModelBounds(
    this: engine,
    a2: "models/weapons/w_c4_planted.mdl",
    a3: (const Vector *)v2,
    a4: (const Vector *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x102E4DD0
// Name: public: static class CPlantedC4 __near * CPlantedC4::ShootSatchelCharge(class CCSPlayer __near *,class Vector,class QAngle)
// Source: json
//------------------------------------------------------------------------------
CPlantedC4 *__cdecl CPlantedC4::ShootSatchelCharge(CCSPlayer *pevOwner, Vector vecStart, QAngle vecAngles)
{
  IServerNetworkable *EntityByName; // eax
  void *v4; // eax
  IServerNetworkable *v5; // eax
  void *v6; // esi
  char bTrainingPlacedByPlayer; // [esp+4h] [ebp-4h]

  bTrainingPlacedByPlayer = 0;
  if ( CCSGameRules::IsPlayingTraining(this: (CCSGameRules *)g_pGameRules) )
  {
    EntityByName = CreateEntityByName(className: "planted_c4_training", iForceEdictIndex: -1, bNotify: true);
    v4 = __RTDynamicCast(
           inptr: EntityByName,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CPlantedC4Training `RTTI Type Descriptor',
           isReference: 0);
    bTrainingPlacedByPlayer = 1;
  }
  else
  {
    v5 = CreateEntityByName(className: "planted_c4", iForceEdictIndex: -1, bNotify: true);
    v4 = __RTDynamicCast(
           inptr: v5,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CPlantedC4 `RTTI Type Descriptor',
           isReference: 0);
  }
  v6 = v4;
  if ( v4 != nullptr )
  {
    vecAngles.z = 0.0;
    vecAngles.x = 0.0;
    (*(void (__thiscall **)(void *, CCSPlayer *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, char))(*(_DWORD *)v4 + 916))(
      a1: v4,
      a2: pevOwner,
      a3: LODWORD(vecStart.x),
      a4: LODWORD(vecStart.y),
      a5: LODWORD(vecStart.z),
      a6: 0,
      a7: LODWORD(vecAngles.y),
      a8: 0,
      a9: bTrainingPlacedByPlayer);
    return (CPlantedC4 *)v6;
  }
  else
  {
    _Warning(a1: "Can't create planted_c4 entity!\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4EB0
// Name: public: virtual void planted_c4_trainingPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall planted_c4_trainingPrecache::CResourcePrecacher::Cache(
        planted_c4_trainingPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "planted_c4_training",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E4EE0
// Name: public: virtual struct datamap_t __near * CPlantedC4Training::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPlantedC4Training::GetDataDescMap(CPlantedC4Training *this)
{
  return &CPlantedC4Training::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E4EF0
// Name: public: virtual class ServerClass __near * CC4::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CC4::GetServerClass(CC4 *this)
{
  return &g_CC4_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102E4F00
// Name: public: virtual void weapon_c4Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_c4Precache::CResourcePrecacher::Cache(
        weapon_c4Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_c4",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E4F30
// Name: public: virtual void CC4::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::ItemPostFrame(CC4 *this)
{
  CCSPlayer *PlayerOwner; // eax
  bool v3; // zf
  CC4_vtbl *v4; // eax

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    v3 = (PlayerOwner->m_nButtons & 0x21) == 0;
    v4 = this->__vftable;
    if ( v3 )
      v4->WeaponIdle(this);
    else
      v4->PrimaryAttack(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4F60
// Name: public: virtual unsigned int CC4::PhysicsSolidMaskForEntity(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CC4::PhysicsSolidMaskForEntity(CC4 *this)
{
  return CCSGameMovement::LadderMask(this) | 0x10000;
}

//------------------------------------------------------------------------------
// Address: 0x102E4F70
// Name: public: virtual void CC4::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::Precache(CC4 *this)
{
  PrecacheVGuiScreen(pScreenType: "c4_view_panel");
  CBaseEntity::PrecacheScriptSound(soundname: "c4.disarmfinish");
  CBaseEntity::PrecacheScriptSound(soundname: "c4.explode");
  CBaseEntity::PrecacheScriptSound(soundname: "c4.disarmstart");
  CBaseEntity::PrecacheScriptSound(soundname: "c4.plant");
  CBaseEntity::PrecacheScriptSound(soundname: "C4.PlantSound");
  PrecacheParticleSystem(pParticleSystemName: "c4_train_ground_effect");
  CBaseEntity::PrecacheScriptSound(soundname: "tr.C4Explode");
  CWeaponCSBase::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E4FD0
// Name: public: virtual void CC4::GetControlPanelInfo(int,char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::GetControlPanelInfo(CC4 *this, int nPanelIndex, const char **pPanelName)
{
  *pPanelName = "c4_view_panel";
}

//------------------------------------------------------------------------------
// Address: 0x102E4FE0
// Name: public: virtual void CC4::UpdateShieldState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::UpdateShieldState(CC4 *this)
{
  vgui::ToggleButton *PlayerOwner; // eax
  vgui::TreeView *v3; // esi
  CBaseViewModel *ViewModel; // eax

  PlayerOwner = (vgui::ToggleButton *)CWeaponCSBase::GetPlayerOwner(this);
  v3 = (vgui::TreeView *)PlayerOwner;
  if ( PlayerOwner != nullptr )
  {
    if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: PlayerOwner) )
    {
      CNavMesh::SaveCustomData(this: v3, itemIndex: 0);
      ViewModel = CBasePlayer::GetViewModel(this: (CBasePlayer *)v3, index: 1);
      if ( ViewModel != nullptr )
        ViewModel->AddEffects(this: ViewModel, a2: 32);
    }
    else
    {
      CWeaponCSBase::UpdateShieldState(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E5030
// Name: public: void CPlantedC4Training::InputActivateSetTimerLength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlantedC4Training::InputActivateSetTimerLength(CPlantedC4Training *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    ((void (__stdcall *)(int))this->ActivateSetTimerLength)(a1: inputdata->value.iVal);
  else
    ((void (__stdcall *)(_DWORD))this->ActivateSetTimerLength)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102E5160
// Name: public: void CC4::PlayArmingBeeps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::PlayArmingBeeps(CC4 *this)
{
  CC4 *v1; // ebx
  float v2; // xmm1_4
  int v3; // eax
  CCSPlayer *PlayerOwner; // eax
  float *v5; // esi
  CGlobalVars *v6; // ecx
  int i; // edi
  CBasePlayer *v8; // eax
  signed int v9; // esi
  CBaseCombatCharacter *Owner; // eax
  int m_pPev; // eax
  CPASAttenuationFilter filter; // [esp+10h] [ebp-34h] BYREF
  Vector soundPosition; // [esp+30h] [ebp-14h] BYREF
  int v14; // [esp+3Ch] [ebp-8h]
  CC4 *v15; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  v1 = this;
  v2 = (float)((float)(gpGlobals->curtime - (float)(this->m_fArmedTime.m_Value - 3.0)) * 0.44444445)
     * (float)iNumArmingAnimFrames;
  v15 = this;
  v3 = 0;
  while ( (int)v2 > m_iBeepFrames[v3] )
  {
    if ( !this->m_bPlayedArmingBeeps[v3] )
    {
      this->m_bPlayedArmingBeeps[v3] = true;
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      v5 = (float *)PlayerOwner;
      if ( (PlayerOwner->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: PlayerOwner, a2: (int)&savedregs);
      soundPosition.x = v5[115];
      soundPosition.y = v5[116];
      soundPosition.z = v5[117] + 5.0;
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &soundPosition);
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
      CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: &soundPosition, attenuation: 0.80000001);
      CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)v5);
      v6 = gpGlobals;
      for ( i = 1; i <= gpGlobals->maxClients; ++i )
      {
        v8 = UTIL_PlayerByIndex(playerIndex: i);
        v9 = (signed int)v8;
        if ( v8 != nullptr && v8->GetObserverMode(this: v8) == 4 )
        {
          v14 = (*(int (__thiscall **)(signed int))(*(_DWORD *)v9 + 1620))(a1: v9);
          Owner = CBaseCombatWeapon::GetOwner(this: v1);
          if ( (CBaseCombatCharacter *)v14 == Owner )
            CRecipientFilter::RemoveRecipient(this: &filter, player: v9);
          v1 = v15;
        }
        v6 = gpGlobals;
      }
      m_pPev = (int)v1->m_Network.m_pPev;
      if ( m_pPev != 0 )
        m_pPev = (signed int)(m_pPev - (unsigned int)v6->pEdicts) >> 4;
      CBaseEntity::EmitSound(
        &filter,
        iEntIndex: m_pPev,
        soundname: "c4.click",
        pOrigin: nullptr,
        soundtime: 0.0,
        duration: nullptr);
      CRecipientFilter::~CRecipientFilter(this: &filter);
      return;
    }
    if ( ++v3 >= 7 )
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E5310
// Name: public: virtual float CC4::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CC4::GetMaxSpeed(CC4 *this)
{
  if ( this->m_bStartedArming.m_Value )
    return 1.0;
  else
    return CWeaponCSBase::GetMaxSpeed(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E54E0
// Name: public: virtual void CPlantedC4::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlantedC4::SetTransmit(CPlantedC4 *this, CCheckTransmitInfo *pInfo, BOOL bAlways)
{
  edict_t *m_pPev; // eax
  int i; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseAnimating::SetTransmit(this, pInfo, bAlways);
    for ( i = 0; i < this->m_hScreens.m_Size; ++i )
    {
      m_Index = this->m_hScreens.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))m_pEntity->__vftable[7].SetRefEHandle)(
        a1: m_pEntity,
        a2: pInfo,
        a3: bAlways);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E5580
// Name: public: virtual bool CC4::ShouldRemoveOnRoundRestart(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CC4::ShouldRemoveOnRoundRestart(CC4 *this)
{
  CCSPlayer *PlayerOwner; // eax
  CCSPlayer *v3; // esi

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner != nullptr && CBaseCombatCharacter::GetActiveWeapon(this: PlayerOwner) == this )
    engine->ClientCommand(this: engine, a2: v3->m_Network.m_pPev, a3: "lastinv reset\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E55C0
// Name: public: virtual void CC4::OnPickedUp(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::OnPickedUp(CC4 *this, CBaseCombatCharacter *pNewOwner)
{
  CBasePlayer *v2; // edi
  IGameEvent *v3; // esi
  int v4; // eax

  CWeaponCSBase::OnPickedUp(this, pNewOwner);
  v2 = (CBasePlayer *)__RTDynamicCast(
                        inptr: pNewOwner,
                        VfDelta: 0,
                        SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_pickup", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v4 = engine->GetPlayerUserId(this: engine, a2: v2->m_Network.m_pPev);
    v3->SetInt(this: v3, a2: "userid", a3: v4);
    v3->SetInt(this: v3, a2: "priority", a3: 6);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
  }
  ClientPrint(
    player: v2,
    msg_dest: 4,
    msg_name: "#SFUI_Notice_Got_Bomb",
    param1: nullptr,
    param2: nullptr,
    param3: nullptr,
    param4: nullptr);
  *(float *)&v2[1].m_hMyWeapons.m_Value[4].m_Index = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102E5670
// Name: public: virtual void CC4::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::Spawn(CC4 *this)
{
  CWeaponCSBase::Spawn(this);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  this->m_bBombPlanted = false;
}

//------------------------------------------------------------------------------
// Address: 0x102E56C0
// Name: public: virtual CPlantedC4::~CPlantedC4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlantedC4::~CPlantedC4(CPlantedC4 *this)
{
  int i; // edi
  unsigned int m_Index; // eax
  CVGuiScreen *m_pEntity; // ecx
  vgui::TreeNode *src; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (CPlantedC4_vtbl *)&CPlantedC4::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_PlantedC4s,
    &src);
  for ( i = this->m_hScreens.m_Size - 1; i >= 0; --i )
  {
    m_Index = this->m_hScreens.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CVGuiScreen *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    DestroyVGuiScreen(pVGuiScreen: m_pEntity);
  }
  this->m_hScreens.m_Size = 0;
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hScreens);
  CBaseAnimating::~CBaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E5750
// Name: public: virtual int CPlantedC4::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlantedC4::ObjectCaps(CPlantedC4 *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x22;
}

//------------------------------------------------------------------------------
// Address: 0x102E5760
// Name: protected: virtual void CPlantedC4::Init(class CCSPlayer __near *,class Vector,class QAngle,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlantedC4::Init(
        CPlantedC4 *this,
        CCSPlayer *pevOwner,
        Vector vecStart,
        QAngle vecAngles,
        bool bTrainingPlacedByPlayer)
{
  edict_t *m_pPev; // ecx

  CBaseEntity::SetAbsOrigin(this, absOrigin: &vecStart);
  CBaseEntity::SetAbsAngles(this, absAngles: &vecAngles);
  this->SetOwnerEntity(this, a2: pevOwner);
  if ( pevOwner != nullptr )
    this->m_pPlanter.m_Index = pevOwner->GetRefEHandle(this: pevOwner)->m_Index;
  else
    this->m_pPlanter.m_Index = -1;
  if ( !this->m_bTrainingPlacedByPlayer && !this->m_bBombTicking.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x48Cu);
    }
    this->m_bBombTicking.m_Value = true;
  }
  this->Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E5800
// Name: protected: void CPlantedC4::C4Think(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPlantedC4::C4Think(CPlantedC4 *this@<ecx>, int a2@<edi>)
{
  unsigned int m_Index; // eax
  CBaseEntity *v4; // eax
  CBaseEntity *v5; // esi
  CBaseEdict *v6; // ecx
  IGameEvent *v7; // esi
  edict_t *v8; // eax
  CBaseEntity *OwnerEntity; // eax
  CCSPlayer *v10; // edi
  float z; // edx
  IGameEvent *v12; // esi
  int UserID; // eax
  float m_Value; // xmm1_4
  CHandle<CBaseEntity> *p_m_pBombDefuser; // ecx
  int v16; // eax
  CBaseEntity *v17; // eax
  CBasePlayer *v18; // eax
  CBaseEntity *v19; // eax
  CBaseEntity *v20; // edi
  CBaseEdict *v21; // ecx
  IGameEvent *v22; // edi
  CBasePlayer *v23; // eax
  int v24; // eax
  CCSPlayer *v25; // eax
  CCSPlayer *v26; // eax
  edict_t *m_pPev; // ecx
  edict_t *v28; // ecx
  CBasePlayer *v29; // eax
  CCSPlayer *v30; // eax
  CCSPlayer *v31; // eax
  IGameEvent *v32; // edi
  CBasePlayer *v33; // eax
  int v34; // eax
  CBaseMultiplayerPlayer *v35; // eax
  CBaseMultiplayerPlayer *v36; // eax
  CCSPlayer *v37; // eax
  CBaseMultiplayerPlayer *v38; // eax
  CBaseEntity *v39; // eax
  const Vector *AbsOrigin; // eax
  edict_t *v41; // eax
  edict_t *v42; // ecx
  CBaseEntity *v43; // eax
  CBaseEntity *v44; // edi
  CBaseEdict *v45; // ecx
  CCSPlayer *v46; // eax
  CBaseEntity *v47; // eax
  CCSPlayer *v48; // eax
  edict_t *v49; // ecx
  IGameEvent *v50; // edi
  CBasePlayer *v51; // eax
  int v52; // eax
  CBaseEntity *v53; // eax
  CBaseEntity *v54; // edi
  CBaseEdict *v55; // ecx
  CGameTrace tr; // [esp+94h] [ebp-94h] BYREF
  CPASAttenuationFilter filter; // [esp+E8h] [ebp-40h] BYREF
  Vector vecSpot; // [esp+108h] [ebp-20h] BYREF
  Vector soundPosition; // [esp+114h] [ebp-14h] BYREF
  bool roundWasAlreadyWon; // [esp+123h] [ebp-5h]
  float timeToDetonation; // [esp+124h] [ebp-4h]
  IHandleEntity savedregs; // [esp+128h] [ebp+0h] BYREF

  if ( !CBaseEntity::IsInWorld(this, a2: (int)&savedregs) )
  {
    UTIL_Remove(oldObj: this);
    return;
  }
  if ( this->m_bHasExploded )
  {
    if ( !CCSGameRules::IsPlayingTraining(this: (CCSGameRules *)g_pGameRules) )
      return;
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
    m_Index = this->m_pBombDefuser.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      goto LABEL_49;
    }
    v4 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
    v5 = v4;
    if ( LOBYTE(v4[5].m_OnUser3.m_Value.eVal.m_Index) != 0 )
    {
      if ( v4->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v4->m_Network + 76) |= 1u;
        LOBYTE(v4[5].m_OnUser3.m_Value.eVal.m_Index) = 0;
      }
      else
      {
        v6 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: v6, offset: 0x1310u);
        LOBYTE(v5[5].m_OnUser3.m_Value.eVal.m_Index) = 0;
      }
    }
LABEL_48:
    v25 = (CCSPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
    CCSPlayer::SetProgressBarTime(this: v25, barTime: 0);
    v26 = (CCSPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
    CCSPlayer::OnCanceledDefuse(this: v26);
    this->m_pBombDefuser.m_Index = -1;
LABEL_49:
    this->m_bStartDefuse = false;
    if ( this->m_flDefuseCountDown.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
      }
      this->m_flDefuseCountDown.m_Value = 0.0;
    }
    if ( this->m_flDefuseLength.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flDefuseLength.m_Value = 0.0;
      }
      else
      {
        v28 = this->m_Network.m_pPev;
        if ( v28 != nullptr )
          CBaseEdict::StateChanged(this: &v28->CBaseEdict, offset: 0x4ACu);
        this->m_flDefuseLength.m_Value = 0.0;
      }
    }
    return;
  }
  if ( !this->m_bBombTicking.m_Value )
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    return;
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.12, szContext: nullptr);
  v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_beep", a3: 0, a4: 0);
  if ( v7 != nullptr )
  {
    v8 = this->m_Network.m_pPev;
    if ( v8 != nullptr )
      v8 -= (int)gpGlobals->pEdicts;
    v7->SetInt(this: v7, a2: "entindex", a3: (int)v8);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
  }
  if ( gpGlobals->curtime >= this->m_flC4Blow.m_Value )
  {
    OwnerEntity = CBaseEntity::GetOwnerEntity(this);
    v10 = ToCSPlayer(pEntity: OwnerEntity);
    if ( v10 != nullptr && g_pGameRules[130].m_pszName == nullptr )
      v10->IncrementFragCount(this: v10, a2: 3);
    HIBYTE(g_pGameRules[144].__vftable) = 0;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    z = this->m_vecAbsOrigin.z;
    *(_QWORD *)&vecSpot.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    vecSpot.z = z + 8.0;
    *(_QWORD *)&soundPosition.x = *(_QWORD *)&vecSpot.x;
    soundPosition.z = (float)(z + 8.0) - 40.0;
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)v7,
      vecAbsStart: &vecSpot,
      vecAbsEnd: &soundPosition,
      mask: 0x200400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    this->Explode(this, a2: &tr, a3: 64);
    LOBYTE(g_pGameRules[144].m_pNext) = 0;
    CCSGameStats::Event_BombExploded(this: &CCS_GameStats, pPlayer: v10);
    v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_exploded", a3: 0, a4: 0);
    if ( v12 != nullptr )
    {
      if ( v10 != nullptr )
        UserID = CBasePlayer::GetUserID(this: v10);
      else
        UserID = -1;
      v12->SetInt(this: v12, a2: "userid", a3: UserID);
      v12->SetInt(this: v12, a2: "site", a3: this->m_iBombSiteIndex);
      v12->SetInt(this: v12, a2: "priority", a3: 9);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v12, a3: false);
    }
  }
  if ( this->m_bStartDefuse
    && CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser, val: nullptr) )
  {
    m_Value = this->m_flDefuseCountDown.m_Value;
    timeToDetonation = gpGlobals->curtime;
    p_m_pBombDefuser = (CHandle<CBaseEntity> *)&this->m_pBombDefuser;
    if ( m_Value > timeToDetonation )
    {
      v16 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_pBombDefuser)->m_fFlags.m_Value & 1;
      if ( timeToDetonation > this->m_flNextDefuse )
      {
        if ( v16 != 0 )
        {
LABEL_40:
          v19 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
          v20 = v19;
          if ( LOBYTE(v19[5].m_OnUser3.m_Value.eVal.m_Index) != 0 )
          {
            if ( v19->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v19->m_Network + 76) |= 1u;
            }
            else
            {
              v21 = &v19->m_Network.m_pPev->CBaseEdict;
              if ( v21 != nullptr )
                CBaseEdict::StateChanged(this: v21, offset: 0x1310u);
            }
            LOBYTE(v20[5].m_OnUser3.m_Value.eVal.m_Index) = 0;
          }
          v22 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_abortdefuse", a3: 0, a4: 0);
          if ( v22 != nullptr )
          {
            LODWORD(timeToDetonation) = &v22->SetInt;
            v23 = (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
            v24 = CBasePlayer::GetUserID(this: v23);
            (*(void (__thiscall **)(IGameEvent *, const char *, int))LODWORD(timeToDetonation))(
              a1: v22,
              a2: "userid",
              a3: v24);
            v22->SetInt(this: v22, a2: "priority", a3: 6);
            gameeventmanager->FireEvent(this: gameeventmanager, a2: v22, a3: false);
          }
          goto LABEL_48;
        }
      }
      else if ( v16 != 0 )
      {
        return;
      }
      v17 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
      if ( v17->IsAlive(this: v17) )
      {
        v18 = (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
        ClientPrint(
          player: v18,
          msg_dest: 4,
          msg_name: "#SFUI_Notice_C4_Defuse_Must_Be_On_Ground",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
      goto LABEL_40;
    }
    v29 = (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_pBombDefuser);
    if ( CBasePlayer::IsDead(this: v29) )
    {
      v50 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_abortdefuse", a3: 0, a4: 0);
      if ( v50 != nullptr )
      {
        LODWORD(timeToDetonation) = &v50->SetInt;
        v51 = (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
        v52 = CBasePlayer::GetUserID(this: v51);
        (*(void (__thiscall **)(IGameEvent *, const char *, int))LODWORD(timeToDetonation))(
          a1: v50,
          a2: "userid",
          a3: v52);
        v50->SetInt(this: v50, a2: "priority", a3: 6);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v50, a3: false);
      }
      v53 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
      v54 = v53;
      if ( LOBYTE(v53[5].m_OnUser3.m_Value.eVal.m_Index) != 0 )
      {
        if ( v53->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v53->m_Network + 76) |= 1u;
        }
        else
        {
          v55 = &v53->m_Network.m_pPev->CBaseEdict;
          if ( v55 != nullptr )
            CBaseEdict::StateChanged(this: v55, offset: 0x1310u);
        }
        LOBYTE(v54[5].m_OnUser3.m_Value.eVal.m_Index) = 0;
      }
      this->m_bStartDefuse = false;
      this->m_pBombDefuser.m_Index = -1;
    }
    else
    {
      v30 = (CCSPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
      CCSGameStats::Event_BombDefused(this: &CCS_GameStats, pPlayer: v30);
      v31 = (CCSPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
      CCSGameRules::ScoreBombDefuse(this: (CCSGameRules *)g_pGameRules, pPlayer: v31);
      v32 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD, _DWORD, int))gameeventmanager->CreateEventA)(
                            a1: gameeventmanager,
                            a2: "bomb_defused",
                            a3: 0,
                            a4: 0,
                            a5: a2);
      if ( v32 != nullptr )
      {
        LODWORD(timeToDetonation) = &v32->SetInt;
        v33 = (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
        v34 = CBasePlayer::GetUserID(this: v33);
        (*(void (__thiscall **)(IGameEvent *, const char *, int))LODWORD(timeToDetonation))(
          a1: v32,
          a2: "userid",
          a3: v34);
        v32->SetInt(this: v32, a2: "site", a3: this->m_iBombSiteIndex);
        v32->SetInt(this: v32, a2: "priority", a3: 9);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v32, a3: false);
        v35 = (CBaseMultiplayerPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
        CBaseMultiplayerPlayer::AwardAchievement(this: v35, iAchievement: 1002, iCount: 1);
        timeToDetonation = this->m_flC4Blow.m_Value - gpGlobals->curtime;
        if ( timeToDetonation > 0.0 )
        {
          if ( timeToDetonation <= 1.0 )
          {
            v36 = (CBaseMultiplayerPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
            CBaseMultiplayerPlayer::AwardAchievement(this: v36, iAchievement: 1004, iCount: 1);
          }
          v37 = (CCSPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
          if ( CCSPlayer::HasDefuser(this: v37) && timeToDetonation < 5.0 )
          {
            v38 = (CBaseMultiplayerPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
            CBaseMultiplayerPlayer::AwardAchievement(this: v38, iAchievement: 1003, iCount: 1);
          }
        }
        if ( BYTE1(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser)[7].m_Collision.m_pOuter) != 0 )
          BYTE2(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser)[7].m_Collision.m_pOuter) = 1;
      }
      v39 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
      AbsOrigin = CBaseEntity::GetAbsOrigin(this: v39);
      soundPosition.x = AbsOrigin->x;
      soundPosition.y = AbsOrigin->y;
      soundPosition.z = AbsOrigin->z + 5.0;
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, origin: &soundPosition, attenuation: 0.80000001);
      v41 = CBaseEntity::entindex(this);
      CBaseEntity::EmitSound(
        &filter,
        iEntIndex: (int)v41,
        soundname: "c4.disarmfinish",
        pOrigin: nullptr,
        soundtime: 0.0,
        duration: nullptr);
      if ( this->m_bBombTicking.m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v42 = this->m_Network.m_pPev;
          if ( v42 != nullptr )
            CBaseEdict::StateChanged(this: &v42->CBaseEdict, offset: 0x48Cu);
        }
        this->m_bBombTicking.m_Value = false;
      }
      v43 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
      v44 = v43;
      if ( LOBYTE(v43[5].m_OnUser3.m_Value.eVal.m_Index) != 0 )
      {
        if ( v43->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v43->m_Network + 76) |= 1u;
        }
        else
        {
          v45 = &v43->m_Network.m_pPev->CBaseEdict;
          if ( v45 != nullptr )
            CBaseEdict::StateChanged(this: v45, offset: 0x1310u);
        }
        LOBYTE(v44[5].m_OnUser3.m_Value.eVal.m_Index) = 0;
      }
      BYTE1(g_pGameRules[144].__vftable) = 1;
      roundWasAlreadyWon = g_pGameRules[130].m_pszName != nullptr;
      if ( CCSGameRules::CheckWinConditions(this: (CCSGameRules *)g_pGameRules) && !roundWasAlreadyWon )
      {
        v46 = (CCSPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
        CCSPlayer::IncrementNumMVPs(this: v46, mvpReason: CSMVP_BOMBDEFUSE);
      }
      v47 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
      ((void (__thiscall *)(CBaseEntity *, int))v47->__vftable[2].ImpactTrace)(a1: v47, a2: 3);
      HIBYTE(g_pGameRules[144].__vftable) = 0;
      LOBYTE(g_pGameRules[144].m_pNext) = 0;
      v48 = (CCSPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser);
      CCSPlayer::SetProgressBarTime(this: v48, barTime: 0);
      this->m_pBombDefuser.m_Index = -1;
      this->m_bStartDefuse = false;
      if ( this->m_flDefuseLength.m_Value != 10.0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v49 = this->m_Network.m_pPev;
          if ( v49 != nullptr )
            CBaseEdict::StateChanged(this: &v49->CBaseEdict, offset: 0x4ACu);
        }
        this->m_flDefuseLength.m_Value = 10.0;
      }
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E6150
// Name: private: virtual void CPlantedC4::Explode(class CGameTrace __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPlantedC4::Explode(CPlantedC4 *this, CGameTrace *pTrace, int bitsDamageType)
{
  edict_t *m_pPev; // ecx
  bool v5; // bl
  unsigned int m_Index; // eax
  CEntInfo *v7; // ecx
  IHandleEntity *m_pEntity; // edi
  CBaseMultiplayerPlayer *v9; // eax
  CCSPlayer *v10; // edi
  float v11; // xmm0_4
  CBaseEntity *EntityByClassname; // eax
  edict_t *v13; // ecx
  signed int v14; // ecx
  float v15; // xmm2_4
  float v16; // xmm3_4
  float z; // xmm0_4
  edict_t *v18; // eax
  unsigned int v19; // eax
  CBaseEntity *v20; // eax
  CCSGameRules *v21; // ebx
  const CTakeDamageInfo *v22; // eax
  float flRadius; // [esp+3Ch] [ebp-ACh]
  CTakeDamageInfo v24; // [esp+54h] [ebp-94h] BYREF
  CBroadcastRecipientFilter filter; // [esp+B0h] [ebp-38h] BYREF
  _BYTE vecAngles[20]; // [esp+D0h] [ebp-18h] OVERLAPPED BYREF
  float flBombRadius; // [esp+E4h] [ebp-4h]
  int savedregs; // [esp+E8h] [ebp+0h] BYREF

  LOBYTE(g_pGameRules[144].__vftable) = 1;
  if ( this->m_bBombTicking.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x48Cu);
    }
    this->m_bBombTicking.m_Value = false;
  }
  this->m_bHasExploded = true;
  v5 = g_pGameRules[130].m_pszName != nullptr;
  if ( CCSGameRules::CheckWinConditions(this: (CCSGameRules *)g_pGameRules) )
  {
    m_Index = this->m_hOwnerEntity.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = v7->m_pEntity;
        if ( v7->m_pEntity != nullptr
          && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v7->m_pEntity) != 0 )
        {
          v9 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                           inptr: m_pEntity,
                                           VfDelta: 0,
                                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                                           isReference: 0);
          v10 = (CCSPlayer *)v9;
          if ( v9 != nullptr )
          {
            CBaseMultiplayerPlayer::AwardAchievement(this: v9, iAchievement: 1001, iCount: 1);
            if ( this->m_bPlantedAfterPickup )
              CBaseMultiplayerPlayer::AwardAchievement(this: v10, iAchievement: 1010, iCount: 1);
            if ( !v5 )
              CCSPlayer::IncrementNumMVPs(this: v10, mvpReason: CSMVP_BOMBPLANT);
          }
        }
      }
    }
  }
  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    v11 = 300.0;
  else
    v11 = 500.0;
  flBombRadius = v11;
  if ( g_pMapInfo != nullptr )
    flBombRadius = g_pMapInfo->m_flBombRadius;
  EntityByClassname = nullptr;
  *(_DWORD *)vecAngles = 0;
  while ( 1 )
  {
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: EntityByClassname,
                          szName: "func_bomb_target");
    if ( EntityByClassname == nullptr )
      break;
    v13 = EntityByClassname->m_Network.m_pPev;
    if ( v13 != nullptr )
      v14 = v13 - gpGlobals->pEdicts;
    else
      v14 = 0;
    if ( v14 == this->m_iBombSiteIndex )
    {
      ((void (__thiscall *)(CBaseEntity *, const char *, CPlantedC4 *, CPlantedC4 *, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))EntityByClassname->AcceptInput)(
        a1: EntityByClassname,
        a2: "BombExplode",
        a3: this,
        a4: this,
        a5: 0,
        a6: *(_DWORD *)&vecAngles[4],
        a7: *(_DWORD *)&vecAngles[8],
        a8: -1,
        a9: 0,
        a10: 0);
      break;
    }
  }
  if ( pTrace->fraction != 1.0 )
  {
    v15 = pTrace->plane.normal.z * 0.60000002;
    v16 = pTrace->endpos.x + (float)(pTrace->plane.normal.x * 0.60000002);
    *(float *)&vecAngles[12] = pTrace->endpos.y + (float)(pTrace->plane.normal.y * 0.60000002);
    z = pTrace->endpos.z;
    *(float *)&vecAngles[8] = v16;
    *(float *)&vecAngles[16] = z + v15;
    CBaseEntity::SetAbsOrigin(this, absOrigin: (const Vector *)&vecAngles[8]);
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  *(_QWORD *)&vecAngles[8] = *(_QWORD *)&this->m_vecAbsOrigin.x;
  *(float *)&vecAngles[16] = this->m_vecAbsOrigin.z + 8.0;
  DispatchParticleEffect(
    pszParticleName: "explosion_c4_500",
    vecOrigin: *(Vector *)&vecAngles[8],
    vecAngles: *(QAngle *)&vecAngles[8],
    pEntity: nullptr,
    nSplitScreenPlayerSlot: -1,
    filter: nullptr);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  v18 = this->m_Network.m_pPev;
  if ( v18 != nullptr )
    v18 -= (int)gpGlobals->pEdicts;
  CBaseEntity::EmitSound(
    &filter,
    iEntIndex: (int)v18,
    soundname: "c4.explode",
    pOrigin: nullptr,
    soundtime: 0.0,
    duration: nullptr);
  UTIL_DecalTrace(pTrace, decalName: "Scorch");
  UTIL_ScreenShake(
    center: &pTrace->endpos,
    amplitude: 25.0,
    frequency: 150.0,
    duration: 1.0,
    radius: 3000.0,
    eCommand: SHAKE_START,
    bAirShake: false,
    ignore: nullptr);
  this->SetOwnerEntity(this, a2: nullptr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v19 = this->m_hOwnerEntity.m_Value.m_Index;
  if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
    v20 = nullptr;
  else
    v20 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
  v21 = (CCSGameRules *)g_pGameRules;
  flRadius = flBombRadius * 3.5;
  v22 = CTakeDamageInfo::CTakeDamageInfo(
          this: &v24,
          pInflictor: this,
          pAttacker: v20,
          flDamage: flBombRadius,
          bitsDamageType,
          iKillType: 0,
          iObjectsPenetrated: 0);
  CCSGameRules::RadiusDamage(
    this: v21,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)&this->m_vecAbsOrigin,
    a4: (int)this,
    info: v22,
    vecSrcIn: &this->m_vecAbsOrigin,
    flRadius,
    iClassIgnore: 0,
    bIgnoreWorld: true);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x102E6540
// Name: private: virtual void CPlantedC4::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPlantedC4::Use(
        CPlantedC4 *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CBaseEntity *v8; // eax
  CBaseEntity *v9; // edi
  IGameEvent *v10; // esi
  int v11; // eax
  bool v12; // zf
  void (__thiscall *SetInt)(IGameEvent *, const char *, int); // eax
  edict_t *m_pPev; // eax
  float v15; // xmm0_4
  edict_t *v16; // ecx
  CBaseEdict *v17; // ecx
  float v18; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *v20; // ecx
  CPASAttenuationFilter filter; // [esp+44h] [ebp-30h] BYREF
  Vector soundPosition; // [esp+64h] [ebp-10h] BYREF
  float v25; // [esp+70h] [ebp-4h]
  int savedregs; // [esp+74h] [ebp+0h] BYREF
  CNetworkVarBase<float,CPlantedC4::NetworkVar_m_flDefuseLength> *pActivatora; // [esp+7Ch] [ebp+8h]

  if ( this->m_bBombTicking.m_Value )
  {
    v8 = (CBaseEntity *)__RTDynamicCast(
                          inptr: pActivator,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
    v9 = v8;
    if ( v8 != nullptr && CBaseEntity::GetTeamNumber(this: v8) == 3 )
    {
      if ( this->m_bStartDefuse )
      {
        if ( v9 == CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser) )
        {
          this->m_flNextDefuse = gpGlobals->curtime + 0.5;
        }
        else if ( gpGlobals->curtime > (float)v9[5].m_OnKilled.m_Value.fieldType )
        {
          ClientPrint(
            player: (CBasePlayer *)v9,
            msg_dest: 4,
            msg_name: "#SFUI_Notice_Bomb_Already_Being_Defused",
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
          v9[5].m_OnKilled.m_Value.fieldType = (int)(float)(gpGlobals->curtime + 1.0);
        }
      }
      else
      {
        v10 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_begindefuse", a3: 0, a4: 0);
        if ( v10 != nullptr )
        {
          v11 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int, int))engine->GetPlayerUserId)(
                  a1: engine,
                  a2: v9->m_Network.m_pPev,
                  a3,
                  a4: a2);
          v10->SetInt(this: v10, a2: "userid", a3: v11);
          v12 = !CCSPlayer::HasDefuser(this: (CCSPlayer *)v9);
          SetInt = v10->SetInt;
          if ( v12 )
          {
            SetInt(this: v10, a2: "haskit", a3: 0);
            ClientPrint(
              player: (CBasePlayer *)v9,
              msg_dest: 4,
              msg_name: "#SFUI_Notice_Defusing_Bomb_Without_Defuse_Kit",
              param1: nullptr,
              param2: nullptr,
              param3: nullptr,
              param4: nullptr);
          }
          else
          {
            SetInt(this: v10, a2: "haskit", a3: 1);
            ClientPrint(
              player: (CBasePlayer *)v9,
              msg_dest: 4,
              msg_name: "#SFUI_Notice_Defusing_Bomb_With_Defuse_Kit",
              param1: nullptr,
              param2: nullptr,
              param3: nullptr,
              param4: nullptr);
          }
          v10->SetInt(this: v10, a2: "priority", a3: 8);
          ((void (__thiscall *)(IGameEventManager2 *))gameeventmanager->FireEvent)(a1: gameeventmanager);
        }
        if ( (v9->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
        soundPosition.x = v9->m_vecAbsOrigin.x;
        soundPosition.y = v9->m_vecAbsOrigin.y;
        soundPosition.z = v9->m_vecAbsOrigin.z + 5.0;
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, origin: &soundPosition, attenuation: 0.80000001);
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        CBaseEntity::EmitSound(
          &filter,
          iEntIndex: (int)m_pPev,
          soundname: "c4.disarmstart",
          pOrigin: nullptr,
          soundtime: 0.0,
          duration: nullptr);
        pActivatora = &this->m_flDefuseLength;
        v15 = (float)(CCSPlayer::HasDefuser(this: (CCSPlayer *)v9) ? 5 : 10);
        v12 = this->m_flDefuseLength.m_Value == v15;
        v25 = v15;
        if ( !v12 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v16 = this->m_Network.m_pPev;
            if ( v16 != nullptr )
            {
              CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x4ACu);
              v15 = v25;
            }
          }
          this->m_flDefuseLength.m_Value = v15;
        }
        this->m_flNextDefuse = gpGlobals->curtime + 0.5;
        CHandle<CBaseEntity>::operator=(this: (CHandle<CBaseEntity> *)&this->m_pBombDefuser, val: v9);
        this->m_bStartDefuse = true;
        if ( LOBYTE(v9[5].m_OnUser3.m_Value.eVal.m_Index) != 1 )
        {
          if ( v9->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v9->m_Network + 76) |= 1u;
          }
          else
          {
            v17 = &v9->m_Network.m_pPev->CBaseEdict;
            if ( v17 != nullptr )
              CBaseEdict::StateChanged(this: v17, offset: 0x1310u);
          }
          LOBYTE(v9[5].m_OnUser3.m_Value.eVal.m_Index) = 1;
        }
        m_Value = this->m_flDefuseCountDown.m_Value;
        v25 = gpGlobals->curtime + pActivatora->m_Value;
        v18 = v25;
        if ( m_Value != v25 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v20 = this->m_Network.m_pPev;
            if ( v20 != nullptr )
            {
              CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 0x4B0u);
              v18 = v25;
            }
          }
          this->m_flDefuseCountDown.m_Value = v18;
        }
        CCSPlayer::SetProgressBarTime(this: (CCSPlayer *)v9, barTime: (int)pActivatora->m_Value);
        CCSPlayer::OnStartedDefuse(this: (CCSPlayer *)v9);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
    }
  }
  else
  {
    this->m_pfnUse = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E68B0
// Name: protected: virtual void CPlantedC4::ActivateSetTimerLength(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPlantedC4::ActivateSetTimerLength(CPlantedC4 *this@<ecx>, const char *a2@<edi>, float flTimerLength)
{
  float v3; // xmm0_4
  edict_t *m_pPev; // ecx
  float v6; // xmm0_4
  edict_t *v7; // ecx
  edict_t *v8; // ecx

  v3 = flTimerLength;
  if ( flTimerLength >= 0.0 )
  {
    if ( this->m_flTimerLength.m_Value != flTimerLength )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x498u);
          v3 = flTimerLength;
        }
      }
      this->m_flTimerLength.m_Value = v3;
    }
    v6 = gpGlobals->curtime + this->m_flTimerLength.m_Value;
    if ( this->m_flC4Blow.m_Value != v6 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x490u);
      }
      this->m_flC4Blow.m_Value = v6;
    }
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CPlantedC4::C4Think,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
    if ( !this->m_bBombTicking.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bBombTicking.m_Value = true;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x48Cu);
        this->m_bBombTicking.m_Value = true;
      }
    }
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_104EFDE0, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E69F0
// Name: protected: virtual void CPlantedC4Training::Explode(class CGameTrace __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlantedC4Training::Explode(CPlantedC4Training *this, CGameTrace *pTrace, int bitsDamageType)
{
  edict_t *m_pPev; // ecx
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  edict_t *v8; // eax
  CBroadcastRecipientFilter filter; // [esp+10h] [ebp-2Ch] BYREF
  QAngle vecAngles; // [esp+30h] [ebp-Ch] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  LOBYTE(g_pGameRules[144].__vftable) = 1;
  if ( this->m_bBombTicking.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x48Cu);
    }
    this->m_bBombTicking.m_Value = false;
  }
  this->m_bHasExploded = true;
  if ( pTrace->fraction != 1.0 )
  {
    v5 = pTrace->plane.normal.z * 0.60000002;
    v6 = pTrace->endpos.x + (float)(pTrace->plane.normal.x * 0.60000002);
    vecAngles.y = pTrace->endpos.y + (float)(pTrace->plane.normal.y * 0.60000002);
    v7 = pTrace->endpos.z + v5;
    vecAngles.x = v6;
    vecAngles.z = v7;
    CBaseEntity::SetAbsOrigin(this, absOrigin: (const Vector *)&vecAngles);
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  DispatchParticleEffect(
    pszParticleName: "c4_train_ground_effect",
    vecOrigin: this->m_vecAbsOrigin,
    vecAngles,
    pEntity: nullptr,
    nSplitScreenPlayerSlot: -1,
    filter: nullptr);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  v8 = this->m_Network.m_pPev;
  if ( v8 != nullptr )
    v8 -= (int)gpGlobals->pEdicts;
  CBaseEntity::EmitSound(
    &filter,
    iEntIndex: (int)v8,
    soundname: "tr.C4Explode",
    pOrigin: nullptr,
    soundtime: 0.0,
    duration: nullptr);
  this->SetOwnerEntity(this, a2: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x102E6B70
// Name: public: void CC4::AbortBombPlant(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::AbortBombPlant(CC4 *this)
{
  edict_t *m_pPev; // ecx
  CCSPlayer *PlayerOwner; // edi
  float v4; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *v6; // ecx
  IGameEvent *v7; // esi
  int v8; // eax
  CBaseViewModel *ViewModel; // eax
  edict_t *v10; // eax
  signed int v11; // esi
  const Vector *v12; // eax
  Vector v13; // [esp+Ch] [ebp-10h] BYREF
  float v14; // [esp+18h] [ebp-4h]

  if ( this->m_bStartedArming.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C0u);
    }
    this->m_bStartedArming.m_Value = false;
  }
  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    m_Value = this->m_flNextPrimaryAttack.m_Value;
    v14 = gpGlobals->curtime + 1.0;
    v4 = v14;
    if ( m_Value != v14 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x494u);
          v4 = v14;
        }
      }
      this->m_flNextPrimaryAttack.m_Value = v4;
    }
    CCSPlayer::SetProgressBarTime(this: PlayerOwner, barTime: 0);
    v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_abortplant", a3: 0, a4: 0);
    if ( v7 != nullptr )
    {
      v8 = engine->GetPlayerUserId(this: engine, a2: PlayerOwner->m_Network.m_pPev);
      v7->SetInt(this: v7, a2: "userid", a3: v8);
      v7->SetInt(this: v7, a2: "site", a3: PlayerOwner->m_iBombSiteIndex);
      v7->SetInt(this: v7, a2: "priority", a3: 8);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
    }
    if ( PlayerOwner->m_lastWeaponBeforeC4AutoSwitch != nullptr )
    {
      ViewModel = CBasePlayer::GetViewModel(this: PlayerOwner, index: 0);
      if ( ViewModel != nullptr )
        ViewModel->AddEffects(this: ViewModel, a2: 32);
      PlayerOwner->Weapon_Switch(this: PlayerOwner, a2: PlayerOwner->m_lastWeaponBeforeC4AutoSwitch, a3: 0);
      PlayerOwner->m_lastWeaponBeforeC4AutoSwitch = nullptr;
    }
    v10 = PlayerOwner->m_Network.m_pPev;
    if ( v10 != nullptr )
      v11 = v10 - gpGlobals->pEdicts;
    else
      v11 = 0;
    v12 = PlayerOwner->Weapon_ShootPosition(this: PlayerOwner, result: &v13);
    FX_PlantBomb(iPlayerIndex: v11, vOrigin: v12, option: PLANTBOMB_ABORT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E6E00
// Name: public: CPlantedC4::CPlantedC4(void)
// Source: json
//------------------------------------------------------------------------------
CPlantedC4 *__thiscall CPlantedC4::CPlantedC4(CPlantedC4 *this)
{
  int m_Size; // eax
  int v3; // edi
  CPlantedC4 **m_pMemory; // ecx
  int v5; // eax
  CPlantedC4 **v6; // eax

  CBaseAnimating::CBaseAnimating(this);
  this->__vftable = (CPlantedC4_vtbl *)&CPlantedC4::`vftable';
  this->m_pBombDefuser.m_Index = -1;
  this->m_hScreens.m_Memory.m_pMemory = nullptr;
  this->m_hScreens.m_Memory.m_nAllocationCount = 0;
  this->m_hScreens.m_Memory.m_nGrowSize = 0;
  this->m_hScreens.m_Size = 0;
  this->m_hScreens.m_pElements = nullptr;
  this->m_pPlanter.m_Index = -1;
  m_Size = g_PlantedC4s.m_Size;
  v3 = g_PlantedC4s.m_Size;
  if ( g_PlantedC4s.m_Size + 1 > g_PlantedC4s.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_PlantedC4s,
      num: g_PlantedC4s.m_Size - g_PlantedC4s.m_Memory.m_nAllocationCount + 1);
    m_Size = g_PlantedC4s.m_Size;
  }
  m_pMemory = g_PlantedC4s.m_Memory.m_pMemory;
  g_PlantedC4s.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_PlantedC4s.m_pElements = g_PlantedC4s.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(dest: &g_PlantedC4s.m_Memory.m_pMemory[v3 + 1], src: &g_PlantedC4s.m_Memory.m_pMemory[v3], count: 4 * v5);
    m_pMemory = g_PlantedC4s.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  this->m_pPlanter.m_Index = -1;
  this->m_bPlantedAfterPickup = false;
  this->m_bTrainingPlacedByPlayer = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102E6EC0
// Name: private: void CPlantedC4::SpawnControlPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlantedC4::SpawnControlPanels(CPlantedC4 *this)
{
  int v1; // ebx
  int v3; // edi
  int v4; // ebx
  CVGuiScreen *VGuiScreen; // edi
  CVGuiScreen_vtbl *v6; // ebx
  int TeamNumber; // eax
  CHandle<CVGuiScreen> *v8; // ebx
  unsigned int m_Index; // ecx
  matrix3x4_t worldToPanel; // [esp+28h] [ebp-C4h] BYREF
  matrix3x4_t panelToWorld; // [esp+58h] [ebp-94h] BYREF
  char buf[64]; // [esp+88h] [ebp-64h] BYREF
  Vector lr; // [esp+C8h] [ebp-24h] BYREF
  Vector lrlocal; // [esp+D4h] [ebp-18h] BYREF
  float flWidth; // [esp+E0h] [ebp-Ch]
  float flHeight; // [esp+E4h] [ebp-8h]
  int nPanel; // [esp+E8h] [ebp-4h]

  v1 = 0;
  for ( nPanel = 0; ; v1 = nPanel )
  {
    V_snprintf(pDest: buf, maxLen: 64, pFormat: "controlpanel%d_ll", v1);
    v3 = CBaseAnimating::LookupAttachment(this, szName: buf);
    if ( v3 <= 0 )
    {
      V_snprintf(pDest: buf, maxLen: 64, pFormat: "controlpanel%d_ll", v1);
      v3 = CBaseAnimating::LookupAttachment(this, szName: buf);
      if ( v3 <= 0 )
        break;
    }
    V_snprintf(pDest: buf, maxLen: 64, pFormat: "controlpanel%d_ur", v1);
    v4 = CBaseAnimating::LookupAttachment(this, szName: buf);
    if ( v4 <= 0 )
    {
      V_snprintf(pDest: buf, maxLen: 64, pFormat: "controlpanel%d_ur", nPanel);
      v4 = CBaseAnimating::LookupAttachment(this, szName: buf);
      if ( v4 <= 0 )
        break;
    }
    this->GetAttachment(this, a2: v3, a3: &panelToWorld);
    MatrixInvert(in: &panelToWorld, out: &worldToPanel);
    this->GetAttachment(this, a2: v4, a3: &panelToWorld);
    MatrixGetColumn(in: &panelToWorld, column: 3, out: &lr);
    VectorTransform(in1: &lr.x, in2: &worldToPanel, out: &lrlocal.x);
    flWidth = lrlocal.x;
    flHeight = lrlocal.y;
    VGuiScreen = CreateVGuiScreen(
                   pScreenClassname: "vgui_screen",
                   pScreenType: "c4_panel",
                   pAttachedTo: this,
                   pOwner: this,
                   nAttachmentIndex: v3);
    v6 = VGuiScreen->__vftable;
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    v6->ChangeTeam(this: VGuiScreen, a2: TeamNumber);
    CVGuiScreen::SetActualSize(this: VGuiScreen, flWidth, flHeight);
    CVGuiScreen::SetActive(this: VGuiScreen, bActive: true);
    CVGuiScreen::MakeVisibleOnlyToTeammates(this: VGuiScreen, bActive: false);
    v8 = &this->m_hScreens.m_Memory.m_pMemory[CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>::InsertBefore(
                                                this: &this->m_hScreens,
                                                elem: this->m_hScreens.m_Size)];
    m_Index = VGuiScreen->GetRefEHandle(this: VGuiScreen)->m_Index;
    ++nPanel;
    v8->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E70F0
// Name: public: virtual enum CSWeaponID CC4::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CC4::GetCSWeaponID(CC4 *this)
{
  return 37;
}

//------------------------------------------------------------------------------
// Address: 0x102E7100
// Name: public: virtual bool CC4::Holster(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CC4::Holster(CC4 *this, CBaseCombatWeapon *pSwitchingTo)
{
  CCSPlayer *PlayerOwner; // eax

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
    CCSPlayer::SetProgressBarTime(this: PlayerOwner, barTime: 0);
  if ( this->m_bStartedArming.m_Value )
    CC4::AbortBombPlant(this);
  return CWeaponCSBase::Holster(this, pSwitchingTo);
}

//------------------------------------------------------------------------------
// Address: 0x102E7140
// Name: public: virtual void CC4::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::PrimaryAttack(CC4 *this)
{
  char *v1; // ebx
  CCSPlayer *PlayerOwner; // esi
  CBaseEntity *GroundEntity; // edi
  CBaseEdict *v4; // ecx
  IGameEvent *v5; // xmm0_4
  float v6; // xmm1_4
  CBaseEdict *v7; // ecx
  CBaseEdict *v8; // ecx
  IGameEvent *v9; // xmm0_4
  float m_Value; // xmm1_4
  CBaseEdict *v11; // ecx
  IGameEvent *v12; // edi
  int v13; // eax
  edict_t *m_pPev; // eax
  signed int v15; // edi
  const Vector *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm0_4
  IGameEvent *v19; // xmm0_4
  float v20; // xmm1_4
  CBaseEdict *v21; // ecx
  float curtime; // xmm1_4
  float v23; // xmm0_4
  CBaseEdict *v24; // ecx
  CBaseEdict *v25; // ecx
  CBaseEdict *v26; // ecx
  const QAngle *AbsAngles; // edi
  const Vector *AbsOrigin; // eax
  float z; // edx
  __int64 v30; // xmm0_8
  float v31; // eax
  CPlantedC4 *v32; // eax
  CPlantedC4 *v33; // edi
  const Vector *v34; // eax
  float x; // xmm0_4
  unsigned int y_low; // xmm0_4
  const Vector *v37; // eax
  CBombTarget *v38; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  CBaseEntity *v41; // ebx
  const Vector *v42; // eax
  const QAngle *v43; // eax
  CBombTarget_vtbl *v44; // ebx
  double RoundStartTime; // st7
  double v46; // st7
  double v47; // st7
  IGameEvent *v48; // eax
  IGameEvent *v49; // edi
  IGameEvent_vtbl *v50; // ebx
  int v51; // eax
  const Vector *v52; // eax
  IGameEvent_vtbl *v53; // ebx
  const Vector *v54; // eax
  IGameEvent *v55; // eax
  edict_t *v56; // eax
  IGameEvent *v57; // edi
  const Vector *v58; // eax
  edict_t *v59; // eax
  IGameEvent *v60; // eax
  IGameEvent *v61; // edi
  IGameEvent_vtbl *v62; // ebx
  int UserID; // eax
  CBaseEdict *v64; // ecx
  int v65; // esi
  double v66; // st7
  void (__thiscall *v67)(char *, _DWORD); // edx
  void (__thiscall *v68)(char *, int); // edx
  Vector v69; // [esp+74h] [ebp-C0h] BYREF
  QAngle flMinVal[2]; // [esp+80h] [ebp-B4h] BYREF
  CGameTrace tr; // [esp+98h] [ebp-9Ch] BYREF
  CPASAttenuationFilter filter; // [esp+ECh] [ebp-48h] BYREF
  variant_t emptyVariant; // [esp+10Ch] [ebp-28h] BYREF
  Vector plantPosition; // [esp+120h] [ebp-14h] BYREF
  CBombTarget *pBombTarget; // [esp+12Ch] [ebp-8h]
  IGameEvent *event; // [esp+130h] [ebp-4h]

  v1 = (char *)this;
  event = (IGameEvent *)this;
  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner == nullptr )
    return;
  pBombTarget = (CBombTarget *)(PlayerOwner->m_fFlags.m_Value & 1);
  if ( *(float *)&pBombTarget != 0.0 )
  {
    GroundEntity = CBaseEntity::GetGroundEntity(this: PlayerOwner);
    if ( GroundEntity != nullptr
      && (GroundEntity->IsPlayer(this: GroundEntity)
       || IsPushableEntity(pEnt: GroundEntity)
       || IsBreakableEntity(pEnt: GroundEntity)
       || IsPushAwayEntity(pEnt: GroundEntity)) )
    {
      *(float *)&pBombTarget = 0.0;
    }
  }
  if ( v1[1472] == 0 && v1[1488] == 0 )
  {
    if ( PlayerOwner->m_bInBombZone.m_Value )
    {
      if ( *(float *)&pBombTarget != 0.0 )
      {
        if ( v1[1472] != 1 )
        {
          if ( v1[84] != 0 )
          {
            v1[88] |= 1u;
          }
          else
          {
            v4 = *((CBaseEdict **)v1 + 6);
            if ( v4 != nullptr )
              CBaseEdict::StateChanged(this: v4, offset: 0x5C0u);
          }
          v1[1472] = 1;
        }
        v6 = *((float *)v1 + 369);
        *(float *)&event = gpGlobals->curtime + 3.0;
        v5 = event;
        if ( v6 != *(float *)&event )
        {
          if ( v1[84] != 0 )
          {
            v1[88] |= 1u;
          }
          else
          {
            v7 = *((CBaseEdict **)v1 + 6);
            if ( v7 != nullptr )
            {
              CBaseEdict::StateChanged(this: v7, offset: 0x5C4u);
              v5 = event;
            }
          }
          *((float *)v1 + 369) = *(float *)&v5;
        }
        if ( v1[1480] != 0 )
        {
          if ( v1[84] != 0 )
          {
            v1[88] |= 1u;
          }
          else
          {
            v8 = *((CBaseEdict **)v1 + 6);
            if ( v8 != nullptr )
              CBaseEdict::StateChanged(this: v8, offset: 0x5C8u);
          }
          v1[1480] = 0;
        }
        PlayerOwner->m_attemptedBombPlace = true;
        *(_DWORD *)(v1 + 1481) = 0;
        *(_WORD *)(v1 + 1485) = 0;
        v1[1487] = 0;
        PlayerOwner->SetAnimation(this: PlayerOwner, a2: PLAYER_ATTACK1);
        m_Value = PlayerOwner->m_flNextAttack.m_Value;
        event = (IGameEvent *)LODWORD(gpGlobals->curtime);
        v9 = event;
        if ( m_Value != *(float *)&event )
        {
          if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
          }
          else
          {
            v11 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
            if ( v11 != nullptr )
            {
              CBaseEdict::StateChanged(this: v11, offset: 0x684u);
              v9 = event;
            }
          }
          LODWORD(PlayerOwner->m_flNextAttack.m_Value) = v9;
        }
        v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_beginplant", a3: 0, a4: 0);
        if ( v12 != nullptr )
        {
          v13 = engine->GetPlayerUserId(this: engine, a2: PlayerOwner->m_Network.m_pPev);
          v12->SetInt(this: v12, a2: "userid", a3: v13);
          v12->SetInt(this: v12, a2: "site", a3: PlayerOwner->m_iBombSiteIndex);
          v12->SetInt(this: v12, a2: "priority", a3: 8);
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v12, a3: false);
        }
        (*(void (__thiscall **)(char *, int))(*(_DWORD *)v1 + 1000))(a1: v1, a2: 190);
        m_pPev = PlayerOwner->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          v15 = m_pPev - gpGlobals->pEdicts;
        else
          v15 = 0;
        v16 = PlayerOwner->Weapon_ShootPosition(this: PlayerOwner, result: &plantPosition);
        FX_PlantBomb(iPlayerIndex: v15, vOrigin: v16, option: PLANTBOMB_PLANT);
        goto LABEL_43;
      }
      memset((void *)flMinVal, 0, 12);
      v69.z = 0.0;
      LODWORD(v69.y) = "#SFUI_Notice_C4_Plant_Must_Be_On_Ground";
    }
    else
    {
      memset((void *)flMinVal, 0, 12);
      v69.z = 0.0;
      LODWORD(v69.y) = "#SFUI_Notice_C4_Plant_At_Bomb_Spot";
    }
    ClientPrint(
      player: PlayerOwner,
      msg_dest: 4,
      msg_name: (const char *)LODWORD(v69.y),
      param1: (const char *)LODWORD(v69.z),
      param2: (const char *)LODWORD(flMinVal[0].x),
      param3: (const char *)LODWORD(flMinVal[0].y),
      param4: (const char *)LODWORD(flMinVal[0].z));
    goto LABEL_49;
  }
  if ( *(float *)&pBombTarget == 0.0 )
  {
    if ( PlayerOwner->m_bInBombZone.m_Value )
    {
      memset((void *)flMinVal, 0, 12);
      v69.z = 0.0;
      LODWORD(v69.y) = "#SFUI_Notice_C4_Plant_Must_Be_On_Ground";
LABEL_104:
      ClientPrint(
        player: PlayerOwner,
        msg_dest: 4,
        msg_name: (const char *)LODWORD(v69.y),
        param1: (const char *)LODWORD(v69.z),
        param2: (const char *)LODWORD(flMinVal[0].x),
        param3: (const char *)LODWORD(flMinVal[0].y),
        param4: (const char *)LODWORD(flMinVal[0].z));
      CC4::AbortBombPlant(this: (CC4 *)v1);
      v68 = *(void (__thiscall **)(char *, int))(*(_DWORD *)v1 + 1000);
      if ( v1[1480] == 1 )
        v68(a1: v1, a2: 181);
      else
        v68(a1: v1, a2: 183);
      return;
    }
LABEL_102:
    memset((void *)flMinVal, 0, 12);
    v69.z = 0.0;
    LODWORD(v69.y) = "#SFUI_Notice_C4_Arming_Cancelled";
    goto LABEL_104;
  }
  if ( !PlayerOwner->m_bInBombZone.m_Value )
    goto LABEL_102;
  CC4::PlayArmingBeeps(this: (CC4 *)v1);
  curtime = gpGlobals->curtime;
  v23 = *((float *)v1 + 369);
  if ( curtime < v23 )
  {
    if ( curtime >= (float)(v23 - 0.75) && v1[1480] == 0 )
    {
      if ( v1[1480] != 1 )
      {
        if ( v1[84] != 0 )
        {
          v1[88] |= 1u;
        }
        else
        {
          v24 = *((CBaseEdict **)v1 + 6);
          if ( v24 != nullptr )
            CBaseEdict::StateChanged(this: v24, offset: 0x5C8u);
        }
        v1[1480] = 1;
      }
      (*(void (__thiscall **)(char *, int))(*(_DWORD *)v1 + 1000))(a1: v1, a2: 191);
    }
    goto LABEL_43;
  }
  if ( v1[1472] == 0 )
  {
LABEL_43:
    v17 = *((float *)v1 + 293);
    v18 = gpGlobals->curtime + 0.3;
    *(float *)&event = v18;
    if ( v17 != v18 )
    {
      if ( v1[84] != 0 )
      {
        v1[88] |= 1u;
      }
      else
      {
        v64 = *((CBaseEdict **)v1 + 6);
        if ( v64 != nullptr )
        {
          CBaseEdict::StateChanged(this: v64, offset: 0x494u);
          v18 = *(float *)&event;
        }
      }
      *((float *)v1 + 293) = v18;
    }
    v65 = *(_DWORD *)v1;
    v66 = SharedRandomFloat(sharedname: "C4IdleTime", flMinVal: 10.0, flMaxVal: 15.0, additionalSeed: 0);
    v67 = *(void (__thiscall **)(char *, _DWORD))(v65 + 1016);
    flMinVal[0].z = v66 + gpGlobals->curtime;
    v67(a1: v1, a2: LODWORD(flMinVal[0].z));
    return;
  }
  if ( v1[84] != 0 )
  {
    v1[88] |= 1u;
  }
  else
  {
    v25 = *((CBaseEdict **)v1 + 6);
    if ( v25 != nullptr )
      CBaseEdict::StateChanged(this: v25, offset: 0x5C0u);
  }
  v1[1472] = 0;
  if ( *((float *)v1 + 369) != 0.0 )
  {
    if ( v1[84] != 0 )
    {
      v1[88] |= 1u;
    }
    else
    {
      v26 = *((CBaseEdict **)v1 + 6);
      if ( v26 != nullptr )
        CBaseEdict::StateChanged(this: v26, offset: 0x5C4u);
    }
    *((_DWORD *)v1 + 369) = 0;
  }
  if ( !PlayerOwner->m_bInBombZone.m_Value )
  {
    ClientPrint(
      player: PlayerOwner,
      msg_dest: 4,
      msg_name: "#SFUI_Notice_C4_Activated_At_Bomb_Spot",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    v60 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_abortplant", a3: 0, a4: 0);
    v61 = v60;
    if ( v60 != nullptr )
    {
      v62 = v60->__vftable;
      UserID = CBasePlayer::GetUserID(this: PlayerOwner);
      v62->SetInt(this: v61, a2: "userid", a3: UserID);
      v61->SetInt(this: v61, a2: "site", a3: PlayerOwner->m_iBombSiteIndex);
      v61->SetInt(this: v61, a2: "priority", a3: 8);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v61, a3: false);
      v1 = (char *)event;
    }
LABEL_49:
    v20 = *((float *)v1 + 293);
    *(float *)&event = gpGlobals->curtime + 1.0;
    v19 = event;
    if ( v20 != *(float *)&event )
    {
      if ( v1[84] != 0 )
      {
        v1[88] |= 1u;
        *((float *)v1 + 293) = *(float *)&v19;
      }
      else
      {
        v21 = *((CBaseEdict **)v1 + 6);
        if ( v21 != nullptr )
        {
          CBaseEdict::StateChanged(this: v21, offset: 0x494u);
          v19 = event;
        }
        *((float *)v1 + 293) = *(float *)&v19;
      }
    }
    return;
  }
  AbsAngles = CBaseEntity::GetAbsAngles(this: PlayerOwner);
  AbsOrigin = CBaseEntity::GetAbsOrigin(this: PlayerOwner);
  z = AbsAngles->z;
  *(_QWORD *)&flMinVal[0].x = *(_QWORD *)&AbsAngles->x;
  v30 = *(_QWORD *)&AbsOrigin->x;
  v31 = AbsOrigin->z;
  flMinVal[0].z = z;
  *(_QWORD *)&v69.x = v30;
  v69.z = v31;
  v32 = CPlantedC4::ShootSatchelCharge(pevOwner: PlayerOwner, vecStart: v69, vecAngles: flMinVal[0]);
  v33 = v32;
  if ( v32 != nullptr )
  {
    v32->m_iBombSiteIndex = PlayerOwner->m_iBombSiteIndex;
    v34 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)v1);
    x = v34->x;
    LODWORD(flMinVal[0].z) = &tr;
    emptyVariant.vecVal[2] = x;
    y_low = LODWORD(v34->y);
    flMinVal[0].y = 0.0;
    emptyVariant.eVal.m_Index = y_low;
    *(float *)&emptyVariant.fieldType = v34->z - 200.0;
    v37 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)v1);
    UTIL_TraceEntity(
      pEntity: v33,
      vecAbsStart: v37,
      vecAbsEnd: (const Vector *)(&emptyVariant.rgbaVal + 2),
      mask: 0x200400Bu,
      pIgnore: (const IHandleEntity *)v1,
      nCollisionGroup: 0,
      ptr: &tr);
    CBaseEntity::SetAbsOrigin(this: v33, absOrigin: &tr.endpos);
    *(float *)&v38 = COERCE_FLOAT(UTIL_EntityByIndex(entityIndex: PlayerOwner->m_iBombSiteIndex));
    pBombTarget = v38;
    if ( *(float *)&v38 != 0.0 )
    {
      pszValue = v38->m_szMountTarget.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      v41 = EntityByName;
      if ( EntityByName != nullptr )
      {
        v42 = CBaseEntity::GetAbsOrigin(this: EntityByName);
        CBaseEntity::SetAbsOrigin(this: v33, absOrigin: v42);
        v43 = CBaseEntity::GetAbsAngles(this: v41);
        CBaseEntity::SetAbsAngles(this: v33, absAngles: v43);
        v33->SetParent(this: v33, a2: v41, a3: -1);
      }
      v44 = pBombTarget->__vftable;
      flMinVal[0].z = 0.0;
      emptyVariant.iVal = 0;
      emptyVariant.eVal.m_Index = -1;
      emptyVariant.fieldType = FIELD_VOID;
      variant_t::variant_t(this: (variant_t *)&v69, __that: &emptyVariant);
      ((void (__thiscall *)(CBombTarget *, const char *, CPlantedC4 *, CPlantedC4 *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v44->AcceptInput)(
        a1: pBombTarget,
        a2: "BombPlanted",
        a3: v33,
        a4: v33,
        a5: LODWORD(v69.x),
        a6: LODWORD(v69.y),
        a7: LODWORD(v69.z),
        a8: LODWORD(flMinVal[0].x),
        a9: LODWORD(flMinVal[0].y),
        a10: LODWORD(flMinVal[0].z));
      v1 = (char *)event;
    }
    v33->m_bPlantedAfterPickup = v1[1489];
  }
  pBombTarget = (CBombTarget *)LODWORD(gpGlobals->curtime);
  RoundStartTime = CCSGameRules::GetRoundStartTime(this: (CCSGameRules *)g_pGameRules);
  v46 = *(float *)&pBombTarget - RoundStartTime;
  *(float *)&pBombTarget = v46;
  if ( v46 > 0.0 && *(float *)&pBombTarget <= 25.0 )
    CBaseMultiplayerPlayer::AwardAchievement(this: PlayerOwner, iAchievement: 1006, iCount: 1);
  PlayerOwner->m_lastWeaponBeforeC4AutoSwitch = nullptr;
  v47 = gpGlobals->curtime;
  LODWORD(flMinVal[0].z) = PlayerOwner;
  PlayerOwner->m_bombPlacedTime = v47;
  CCSGameStats::Event_BombPlanted(this: &CCS_GameStats, pPlayer: (CCSPlayer *)LODWORD(flMinVal[0].z));
  CCSGameRules::ScoreBombPlant(this: (CCSGameRules *)g_pGameRules, pPlayer: PlayerOwner);
  v48 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_planted", a3: 0, a4: 0);
  v49 = v48;
  if ( v48 != nullptr )
  {
    v50 = v48->__vftable;
    v51 = CBasePlayer::GetUserID(this: PlayerOwner);
    v50->SetInt(this: v49, a2: "userid", a3: v51);
    v49->SetInt(this: v49, a2: "site", a3: PlayerOwner->m_iBombSiteIndex);
    v52 = CBaseEntity::GetAbsOrigin(this: PlayerOwner);
    v49->SetInt(this: v49, a2: "posx", a3: (int)v52->x);
    v53 = v49->__vftable;
    v54 = CBaseEntity::GetAbsOrigin(this: PlayerOwner);
    v53->SetInt(this: v49, a2: "posy", a3: (int)v54->y);
    v49->SetInt(this: v49, a2: "priority", a3: 8);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v49, a3: false);
    v1 = (char *)event;
  }
  *(float *)&v55 = COERCE_FLOAT((int)gameeventmanager->CreateEventA(
                                       this: gameeventmanager,
                                       a2: "bomb_beep",
                                       a3: 0,
                                       a4: 0));
  event = v55;
  if ( *(float *)&v55 != 0.0 )
  {
    pBombTarget = (CBombTarget *)v55->__vftable;
    v56 = CBaseEntity::entindex(this: (CBaseEntity *)v1);
    v57 = event;
    ((void (__thiscall *)(IGameEvent *, const char *, edict_t *))LODWORD(pBombTarget->m_Network.m_PVSInfo.m_vCenter[1]))(
      a1: event,
      a2: "entindex",
      a3: v56);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v57, a3: false);
  }
  CCSPlayer::SetProgressBarTime(this: PlayerOwner, barTime: 0);
  HIBYTE(g_pGameRules[144].__vftable) = 0;
  LOBYTE(g_pGameRules[144].m_pNext) = 1;
  v58 = CBaseEntity::GetAbsOrigin(this: PlayerOwner);
  plantPosition.x = v58->x;
  plantPosition.y = v58->y;
  plantPosition.z = v58->z + 5.0;
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, origin: &plantPosition, attenuation: 0.80000001);
  memset((void *)flMinVal, 0, 12);
  LODWORD(v69.z) = "c4.plant";
  v59 = CBaseEntity::entindex(this: (CBaseEntity *)v1);
  CBaseEntity::EmitSound(
    &filter,
    iEntIndex: (int)v59,
    soundname: (const char *)LODWORD(v69.z),
    pOrigin: (const Vector *)LODWORD(flMinVal[0].x),
    soundtime: flMinVal[0].y,
    duration: (float *)LODWORD(flMinVal[0].z));
  PlayerOwner->Weapon_Drop(this: PlayerOwner, a2: (CBaseCombatWeapon *)v1, a3: nullptr, a4: nullptr);
  UTIL_Remove(oldObj: (CBaseEntity *)v1);
  v1[1488] = 1;
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x102E7AD0
// Name: public: virtual void CC4::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CC4::WeaponIdle(CC4 *this)
{
  CCSPlayer *PlayerOwner; // edi
  float curtime; // xmm0_4
  CBaseEdict *v4; // ecx
  bool (__thiscall *SendWeaponAnim)(CBaseCombatWeapon *, int); // edx

  if ( this->m_bStartedArming.m_Value )
  {
    CC4::AbortBombPlant(this);
    PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
    if ( PlayerOwner != nullptr )
    {
      this->SendWeaponAnim(this, a2: 183);
      curtime = gpGlobals->curtime;
      if ( PlayerOwner->m_flNextAttack.m_Value != curtime )
      {
        if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
        }
        else
        {
          v4 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
          if ( v4 != nullptr )
            CBaseEdict::StateChanged(this: v4, offset: 0x684u);
        }
        PlayerOwner->m_flNextAttack.m_Value = curtime;
      }
    }
    SendWeaponAnim = this->SendWeaponAnim;
    if ( this->m_bBombPlacedAnimation.m_Value )
      SendWeaponAnim(this, a2: 181);
    else
      SendWeaponAnim(this, a2: 183);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E7B90
// Name: public: virtual void CC4::Drop(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CC4::Drop(CC4 *this@<ecx>, int a2@<edi>, int a3@<esi>, const Vector *vecVelocity)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  IGameEvent *v9; // esi
  int v10; // eax
  edict_t *m_pPev; // eax

  if ( LOBYTE(g_pGameRules[144].m_pNext) == 0 )
  {
    CCSBotManager::SetLooseBomb(this: (CCSBotManager *)TheBots, bomb: this);
    m_Index = this->m_hOwnerEntity.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v7 = __RTDynamicCast(
           inptr: m_pEntity,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBasePlayer `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr )
    {
      *((float *)__RTDynamicCast(
                   inptr: v7,
                   VfDelta: 0,
                   SrcType: &CBasePlayer `RTTI Type Descriptor',
                   TargetType: &CCSPlayer `RTTI Type Descriptor',
                   isReference: 0)
      + 1673) = gpGlobals->curtime;
      v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "bomb_dropped", a3: 0, a4: 0);
      if ( v9 != nullptr )
      {
        v10 = ((int (__thiscall *)(IVEngineServer *, _DWORD, int, int))engine->GetPlayerUserId)(
                a1: engine,
                a2: v8[6],
                a3,
                a4: a2);
        v9->SetInt(this: v9, a2: "userid", a3: v10);
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        v9->SetInt(this: v9, a2: "entindex", a3: (int)m_pPev);
        v9->SetInt(this: v9, a2: "priority", a3: 6);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v9, a3: false);
      }
    }
  }
  if ( this->m_bStartedArming.m_Value )
    CC4::AbortBombPlant(this);
  CWeaponCSBase::Drop(this, vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x102E7D00
// Name: public: virtual void CPlantedC4::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlantedC4::Spawn(CPlantedC4 *this)
{
  int m_nValue; // eax
  float m_Value; // xmm1_4
  float v4; // xmm0_4
  edict_t *m_pPev; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  Vector mins; // [esp+18h] [ebp-1Ch] BYREF
  Vector maxs; // [esp+24h] [ebp-10h] BYREF
  float v12; // [esp+30h] [ebp-4h]

  vgui::ListViewPanel::Paint((vgui::ListViewPanel *)this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  this->SetModel(this, a2: "models/weapons/w_c4_planted.mdl");
  maxs.x = 8.0;
  maxs.y = 8.0;
  maxs.z = 8.0;
  memset((void *)&mins, 0, sizeof(mins));
  CBaseEntity::SetCollisionBounds(this, &mins, &maxs);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CPlantedC4::C4Think,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  if ( mp_c4timer.m_pParent != nullptr )
    m_nValue = mp_c4timer.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_Value = this->m_flTimerLength.m_Value;
  v4 = (float)m_nValue;
  v12 = (float)m_nValue;
  if ( m_Value != (float)m_nValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x498u);
        v4 = v12;
      }
    }
    this->m_flTimerLength.m_Value = v4;
  }
  v7 = this->m_flC4Blow.m_Value;
  v12 = gpGlobals->curtime + this->m_flTimerLength.m_Value;
  v6 = v12;
  if ( v7 != v12 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x490u);
        v6 = v12;
      }
    }
    this->m_flC4Blow.m_Value = v6;
  }
  this->m_flNextDefuse = 0.0;
  this->m_bStartDefuse = false;
  this->m_bHasExploded = false;
  CBaseEntity::SetFriction(this, flFriction: 0.89999998);
  if ( this->m_flDefuseLength.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x4ACu);
    }
    this->m_flDefuseLength.m_Value = 0.0;
  }
  CPlantedC4::SpawnControlPanels(this);
  VisibilityMonitor_AddEntity(pEntity: this, flMinDist: 600.0, pfnCallback: nullptr, pfnEvaluator: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E7F00
// Name: public: CC4::CC4(void)
// Source: json
//------------------------------------------------------------------------------
CC4 *__thiscall CC4::CC4(CC4 *this)
{
  int m_Size; // eax
  int v3; // edi
  CC4 **m_pMemory; // ecx
  int v5; // eax
  CC4 **v6; // eax

  CWeaponCSBase::CWeaponCSBase(this);
  this->__vftable = (CC4_vtbl *)&CC4::`vftable';
  m_Size = g_C4s.m_Size;
  v3 = g_C4s.m_Size;
  if ( g_C4s.m_Size + 1 > g_C4s.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_C4s,
      num: g_C4s.m_Size - g_C4s.m_Memory.m_nAllocationCount + 1);
    m_Size = g_C4s.m_Size;
  }
  m_pMemory = g_C4s.m_Memory.m_pMemory;
  g_C4s.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_C4s.m_pElements = g_C4s.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(dest: &g_C4s.m_Memory.m_pMemory[v3 + 1], src: &g_C4s.m_Memory.m_pMemory[v3], count: 4 * v5);
    m_pMemory = g_C4s.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  this->m_bDroppedFromDeath = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10411FC0
// Name: planted_c4Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int planted_c4Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  planted_c4Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&planted_c4Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411FE0
// Name: CPlantedC4_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPlantedC4_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPlantedC4>(__formal: nullptr);
  CPlantedC4_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412010
// Name: DT_PlantedC4::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PlantedC4::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PlantedC4::g_SendTable);
  return atexit(func: DT_PlantedC4::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412030
// Name: DT_PlantedC4::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PlantedC4::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PlantedC4::ignored>();
  DT_PlantedC4::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412070
// Name: planted_c4_trainingPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int planted_c4_trainingPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  planted_c4_trainingPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&planted_c4_trainingPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412090
// Name: CPlantedC4Training_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPlantedC4Training_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPlantedC4Training>(__formal: nullptr);
  CPlantedC4Training_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104120C0
// Name: DT_WeaponC4::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponC4::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponC4::g_SendTable);
  return atexit(func: DT_WeaponC4::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104120E0
// Name: DT_WeaponC4::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponC4::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponC4::ignored>();
  DT_WeaponC4::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412110
// Name: weapon_c4Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_c4Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_c4Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_c4Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420800
// Name: DT_PlantedC4::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PlantedC4::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PlantedC4::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420810
// Name: DT_WeaponC4::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponC4::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponC4::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102E6D10
// Name: struct datamap_t __near * DataMapInit<class CPlantedC4>(class CPlantedC4 __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPlantedC4>()
{
  if ( (_S2_271 & 1) == 0 )
  {
    _S2_271 |= 1u;
    nameHolder_492.m_pszBase = "CPlantedC4";
    nameHolder_492.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_492.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_492.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_492.m_Names.m_Size = 0;
    nameHolder_492.m_Names.m_pElements = nullptr;
    nameHolder_492.m_nLenBase = 10;
    atexit(func: DataMapInit_CPlantedC4__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPlantedC4::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2_271 & 2) == 0 )
  {
    _S2_271 |= 2u;
    dataDesc_508[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_492,
                                  pszIdentifier: "C4Think");
    dataDesc_508[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_508[1].fieldSize = 2097153;
    dataDesc_508[1].externalName = nullptr;
    dataDesc_508[1].pSaveRestoreOps = nullptr;
    dataDesc_508[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPlantedC4::C4Think;
    *(_QWORD *)&dataDesc_508[1].td = 0;
    *(_QWORD *)&dataDesc_508[1].override_field = 0;
    *(_QWORD *)&dataDesc_508[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_508[1].flatOffset[1] = 0;
  }
  CPlantedC4::m_DataMap.dataNumFields = 1;
  CPlantedC4::m_DataMap.dataDesc = &dataDesc_508[1];
  return &CPlantedC4::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E7080
// Name: struct datamap_t __near * DataMapInit<class CPlantedC4Training>(class CPlantedC4Training __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPlantedC4Training>()
{
  if ( (_S4_72 & 1) == 0 )
  {
    _S4_72 |= 1u;
    nameHolder_493.m_pszBase = "CPlantedC4Training";
    nameHolder_493.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_493.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_493.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_493.m_Names.m_Size = 0;
    nameHolder_493.m_Names.m_pElements = nullptr;
    nameHolder_493.m_nLenBase = 18;
    atexit(func: DataMapInit_CPlantedC4Training__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPlantedC4Training::m_DataMap.baseMap = &CPlantedC4::m_DataMap;
  CPlantedC4Training::m_DataMap.dataNumFields = 1;
  CPlantedC4Training::m_DataMap.dataDesc = &dataDesc_451[1];
  return &CPlantedC4Training::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10411FF0
// Name: _dynamic_initializer_for__g_CPlantedC4_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPlantedC4_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPlantedC4_ClassReg,
           pNetworkName: "CPlantedC4",
           pTable: &DT_PlantedC4::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412040
// Name: _dynamic_initializer_for__g_PlantedC4s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PlantedC4s__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PlantedC4s__);
}

//------------------------------------------------------------------------------
// Address: 0x10412050
// Name: _dynamic_initializer_for__planted_c4_training__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__planted_c4_training__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPlantedC4Training> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &planted_c4_training,
           a3: "planted_c4_training");
}

//------------------------------------------------------------------------------
// Address: 0x104120A0
// Name: _dynamic_initializer_for__g_CC4_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CC4_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CC4_ClassReg, pNetworkName: "CC4", pTable: &DT_WeaponC4::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412130
// Name: _dynamic_initializer_for__g_C4s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_C4s__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_C4s__);
}

//------------------------------------------------------------------------------
// Address: 0x10420820
// Name: _ServerClassInit_DT_WeaponC4::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponC4::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_40;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420840
// Name: _ServerClassInit_DT_PlantedC4::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PlantedC4::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_156;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420860
// Name: _DataMapInit_CPlantedC4__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPlantedC4__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_492);
}

//------------------------------------------------------------------------------
// Address: 0x10420870
// Name: _dynamic_atexit_destructor_for__g_PlantedC4s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PlantedC4s__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PlantedC4s);
}

//------------------------------------------------------------------------------
// Address: 0x10420880
// Name: _DataMapInit_CPlantedC4Training__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPlantedC4Training__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_493);
}

//------------------------------------------------------------------------------
// Address: 0x10420890
// Name: _dynamic_atexit_destructor_for__g_C4s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_C4s__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_C4s);
}

} // namespace server
