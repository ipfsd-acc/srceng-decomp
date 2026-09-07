// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_molotov.cpp
// Functions: 18
// ============================================================

#include "game\shared\cstrike15\weapon_molotov.h"

//------------------------------------------------------------------------------
// Address: 0x10232190
// Name: public: virtual class ClientClass __near * C_MolotovGrenade::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_MolotovGrenade::GetClientClass(C_MolotovGrenade *this)
{
  return &__g_C_MolotovGrenadeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10232210
// Name: public: virtual struct datamap_t __near * C_MolotovGrenade::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_MolotovGrenade::GetPredDescMap(C_MolotovGrenade *this)
{
  return &C_MolotovGrenade::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10232220
// Name: public: virtual void weapon_molotovPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_molotovPrecache::CResourcePrecacher::Cache(
        weapon_molotovPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_molotov",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10232250
// Name: public: virtual void C_MolotovGrenadePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MolotovGrenadePrecache::CResourcePrecacher::Cache(
        C_MolotovGrenadePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "weapon_molotov_held",
    a4: bPrecache,
    a5: hResourceList,
    a6: &s_nMolotovFire);
}

//------------------------------------------------------------------------------
// Address: 0x10232280
// Name: public: virtual bool C_MolotovGrenade::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_MolotovGrenade::Simulate(C_MolotovGrenade *this)
{
  this->UpdateParticles(this);
  return C_BaseAnimating::Simulate(this);
}

//------------------------------------------------------------------------------
// Address: 0x102322A0
// Name: public: virtual enum CSWeaponID C_MolotovGrenade::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_MolotovGrenade::GetCSWeaponID(C_MolotovGrenade *this)
{
  return 35;
}

//------------------------------------------------------------------------------
// Address: 0x10232330
// Name: CC_MolotovGrenadeFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_MolotovGrenadeFactory()
{
  C_BaseCSGrenade *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDD0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v0);
  *v1 = &C_MolotovGrenade::`vftable'{for `IClientUnknown'};
  v1[1] = &C_MolotovGrenade::`vftable'{for `IClientRenderable'};
  v1[2] = &C_MolotovGrenade::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_MolotovGrenade::`vftable'{for `IClientThinkable'};
  v1[4] = &C_MolotovGrenade::`vftable';
  v1[881] = 0;
  v1[880] = 0;
  v1[882] = 0;
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10232400
// Name: public: virtual void C_MolotovGrenade::UpdateParticles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MolotovGrenade::UpdateParticles(C_MolotovGrenade *this)
{
  C_BaseCombatCharacter *Owner; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  BOOL v6; // edi
  int v7; // eax
  int v8; // eax
  CNewParticleEffect *Precached; // ebx
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CNewParticleEffect> *p_m_molotovParticleEffect; // edi
  CUtlReference<CNewParticleEffect> *m_pHead; // eax
  CNewParticleEffect *v13; // esi
  CNewParticleEffect *v14; // eax
  CUtlReference<CSheet> *v15; // esi
  BOOL nRenderFlags; // [esp+1Ch] [ebp-4h]

  Owner = C_BaseCombatWeapon::GetOwner(this);
  if ( Owner != nullptr && Owner->IsPlayer(this: Owner) )
  {
    nRenderFlags = false;
    v3 = (int)Owner->GetActiveWeapon(this: Owner);
    if ( v3 != 0 )
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 1492))(a1: v3) == 35 )
      {
        v4 = (int)Owner->GetActiveWeapon(this: Owner);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 1036))(a1: v4) != 0 )
          nRenderFlags = ((int (__thiscall *)(C_BaseCombatCharacter *, _DWORD))Owner->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetSolid)(
                           a1: Owner,
                           a2: 0) == 2;
        if ( this->m_molotovParticleEffect.m_pObject != nullptr )
        {
          v5 = (int)Owner->GetActiveWeapon(this: Owner);
          CNewParticleEffect::SetDormant(
            this: this->m_molotovParticleEffect.m_pObject,
            bDormant: (*(_DWORD *)(v5 + 232) & 0x20) != 0);
        }
        v6 = nRenderFlags;
        if ( nRenderFlags && this->m_bPinPulled.m_Value )
        {
          if ( this->m_molotovParticleEffect.m_pObject == nullptr
            && (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 176))(a1: v3) != 0 )
          {
            v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 176))(a1: v3);
            v8 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)(v7 + 4) + 132))(a1: v7 + 4, a2: "Wick");
            if ( v8 >= 0 )
            {
              Precached = (CNewParticleEffect *)CParticleProperty::CreatePrecached(
                                                  this: &this->m_Particles,
                                                  nPrecacheIndex: s_nMolotovFire,
                                                  iAttachType: PATTACH_POINT_FOLLOW,
                                                  iAttachmentPoint: v8,
                                                  vecOriginOffset: vec3_origin,
                                                  matOffset: nullptr);
              m_pObject = this->m_molotovParticleEffect.m_pObject;
              p_m_molotovParticleEffect = &this->m_molotovParticleEffect;
              if ( m_pObject != Precached )
              {
                if ( m_pObject != nullptr )
                {
                  CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
                    this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
                    which: (CUtlReference<CSheet> *)&this->m_molotovParticleEffect);
                  this->m_molotovParticleEffect.m_pObject = nullptr;
                }
                this->m_molotovParticleEffect.m_pObject = Precached;
                if ( Precached != nullptr )
                {
                  p_m_molotovParticleEffect->m_pNext = Precached->m_References.m_pHead;
                  m_pHead = Precached->m_References.m_pHead;
                  if ( m_pHead != nullptr )
                    m_pHead->m_pPrev = p_m_molotovParticleEffect;
                  this->m_molotovParticleEffect.m_pPrev = nullptr;
                  Precached->m_References.m_pHead = p_m_molotovParticleEffect;
                }
              }
              C_BaseEntity::EmitSound(this, soundname: "Molotov.IdleLoop", soundtime: 0, duration: nullptr);
              v6 = nRenderFlags;
            }
          }
          v13 = this->m_molotovParticleEffect.m_pObject;
          if ( v13 != nullptr )
            CNewParticleEffect::SetDrawOnlyForSplitScreenUser(this: v13, nSlot: v6 - 1);
        }
      }
      else if ( this->m_molotovParticleEffect.m_pObject != nullptr )
      {
        C_BaseEntity::StopSound(this, soundname: "Molotov.IdleLoop");
        CNewParticleEffect::StopEmission(
          this: this->m_molotovParticleEffect.m_pObject,
          bInfiniteOnly: false,
          bRemoveAllParticles: false,
          bWakeOnStop: false,
          bPlayEndCap: false);
        *((_BYTE *)this->m_molotovParticleEffect.m_pObject + 944) |= 2u;
        v14 = this->m_molotovParticleEffect.m_pObject;
        v15 = (CUtlReference<CSheet> *)&this->m_molotovParticleEffect;
        if ( v14 != nullptr )
        {
          CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
            this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v14->m_References,
            which: v15);
          v15->m_pObject = nullptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10232650
// Name: public: virtual void C_MolotovGrenade::OnParticleEffectDeleted(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MolotovGrenade::OnParticleEffectDeleted(C_MolotovGrenade *this, CNewParticleEffect *pParticleEffect)
{
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CNewParticleEffect> *p_m_molotovParticleEffect; // esi

  if ( this->m_molotovParticleEffect.m_pObject == pParticleEffect )
  {
    m_pObject = this->m_molotovParticleEffect.m_pObject;
    p_m_molotovParticleEffect = &this->m_molotovParticleEffect;
    if ( m_pObject != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
        which: (CUtlReference<CSheet> *)&this->m_molotovParticleEffect);
      p_m_molotovParticleEffect->m_pObject = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104291A0
// Name: DT_MolotovGrenade::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MolotovGrenade::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_MolotovGrenade::g_RecvTable);
  return atexit(func: DT_MolotovGrenade::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104291C0
// Name: DT_MolotovGrenade::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MolotovGrenade::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_MolotovGrenade::ignored>();
  DT_MolotovGrenade::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104291D0
// Name: C_MolotovGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_MolotovGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_MolotovGrenade::m_PredMap.dataNumFields = 1;
  C_MolotovGrenade::m_PredMap.dataDesc = (typedescription_t *)&unk_1066BDF4;
}

//------------------------------------------------------------------------------
// Address: 0x10429220
// Name: weapon_molotovPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_molotovPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_molotovPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_molotovPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429240
// Name: C_MolotovGrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *C_MolotovGrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  C_MolotovGrenadePrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &C_MolotovGrenadePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436130
// Name: DT_MolotovGrenade::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MolotovGrenade::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_MolotovGrenade::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102322B0
// Name: _C_MolotovGrenade_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_MolotovGrenade_CreateObject(int entnum, int serialNum)
{
  C_BaseCSGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDD0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v2);
  *v3 = &C_MolotovGrenade::`vftable'{for `IClientUnknown'};
  v3[1] = &C_MolotovGrenade::`vftable'{for `IClientRenderable'};
  v3[2] = &C_MolotovGrenade::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_MolotovGrenade::`vftable'{for `IClientThinkable'};
  v3[4] = &C_MolotovGrenade::`vftable';
  v3[881] = 0;
  v3[880] = 0;
  v3[882] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104291F0
// Name: _dynamic_initializer_for__g_Cweapon_molotovFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_molotovFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_molotov",
             a3: "C_MolotovGrenade",
             a4: 3536,
             a5: CC_MolotovGrenadeFactory);
  __g_C_MolotovGrenadeClientClass.m_pMapClassname = "weapon_molotov";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429260
// Name: _dynamic_initializer_for____g_C_WeaponMP7ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponMP7ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponMP7ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponMP7ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EFE90
// Name: public: virtual class ServerClass __near * CMolotovGrenade::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CMolotovGrenade::GetServerClass(CMolotovGrenade *this)
{
  return &g_CMolotovGrenade_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EFEA0
// Name: public: virtual void weapon_molotovPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_molotovPrecache::CResourcePrecacher::Cache(
        weapon_molotovPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_molotov",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EFED0
// Name: public: virtual struct datamap_t __near * CMolotovGrenade::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMolotovGrenade::GetDataDescMap(CMolotovGrenade *this)
{
  return &CMolotovGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102EFEE0
// Name: public: virtual void CMolotovGrenade::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMolotovGrenade::Precache(CMolotovGrenade *this)
{
  CBaseCSGrenade::Precache(this);
  CBaseEntity::PrecacheScriptSound(soundname: "Molotov.IdleLoop");
}

//------------------------------------------------------------------------------
// Address: 0x102EFF80
// Name: public: virtual void CMolotovGrenade::EmitGrenade(class Vector,class QAngle,class Vector,class Vector,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMolotovGrenade::EmitGrenade(
        CMolotovGrenade *this,
        Vector vecSrc,
        QAngle vecAngles,
        Vector vecVel,
        Vector angImpulse,
        CBasePlayer *pPlayer)
{
  CBasePlayer *v6; // edi
  edict_t *m_pPev; // ecx

  v6 = pPlayer;
  if ( pPlayer != nullptr
    && pPlayer->IsPlayer(this: pPlayer)
    && __RTDynamicCast(
         inptr: v6,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CCSPlayer `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    CCSPlayer::StartNewBulletGroup();
  }
  if ( this->m_bLoopingSoundPlaying.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C8u);
    }
    this->m_bLoopingSoundPlaying.m_Value = false;
  }
  CBaseEntity::StopSound(this, soundname: "Molotov.IdleLoop");
  CMolotovProjectile::Create(
    position: &vecSrc,
    angles: &vecAngles,
    velocity: &vecVel,
    angVelocity: &angImpulse,
    owner: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102F0020
// Name: public: virtual enum CSWeaponID CMolotovGrenade::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMolotovGrenade::GetCSWeaponID(CMolotovGrenade *this)
{
  return 35;
}

//------------------------------------------------------------------------------
// Address: 0x10412CB0
// Name: DT_MolotovGrenade::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MolotovGrenade::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_MolotovGrenade::g_SendTable);
  return atexit(func: DT_MolotovGrenade::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412CD0
// Name: DT_MolotovGrenade::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MolotovGrenade::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_MolotovGrenade::ignored>();
  DT_MolotovGrenade::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412D00
// Name: weapon_molotovPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_molotovPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_molotovPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_molotovPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412D20
// Name: CMolotovGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMolotovGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMolotovGrenade>(__formal: nullptr);
  CMolotovGrenade_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420CC0
// Name: DT_MolotovGrenade::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MolotovGrenade::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_MolotovGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102F0030
// Name: struct datamap_t __near * DataMapInit<class CMolotovGrenade>(class CMolotovGrenade __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMolotovGrenade>()
{
  if ( (_S3_162 & 1) == 0 )
  {
    _S3_162 |= 1u;
    nameHolder_499.m_pszBase = "CMolotovGrenade";
    nameHolder_499.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_499.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_499.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_499.m_Names.m_Size = 0;
    nameHolder_499.m_Names.m_pElements = nullptr;
    nameHolder_499.m_nLenBase = 15;
    atexit(func: DataMapInit_CMolotovGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMolotovGrenade::m_DataMap.baseMap = &CBaseCSGrenade::m_DataMap;
  CMolotovGrenade::m_DataMap.dataNumFields = 1;
  CMolotovGrenade::m_DataMap.dataDesc = dataDesc_514;
  return &CMolotovGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10412D30
// Name: _dynamic_initializer_for__g_CWeaponMP7_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponMP7_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponMP7_ClassReg,
           pNetworkName: "CWeaponMP7",
           pTable: &DT_WeaponMP7::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420CD0
// Name: _ServerClassInit_DT_MolotovGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_MolotovGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_290;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420CF0
// Name: _DataMapInit_CMolotovGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMolotovGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_499);
}

} // namespace server
