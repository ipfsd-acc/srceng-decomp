// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/physpropclientside.cpp
// Functions: 45
// ============================================================

#include "game\client\physpropclientside.h"

//------------------------------------------------------------------------------
// Address: 0x1014B720
// Name: public: virtual C_PhysPropClientside::~C_PhysPropClientside(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::~C_PhysPropClientside(C_PhysPropClientside *this)
{
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PhysPropClientside_vtbl *)&C_PhysPropClientside::`vftable'{for `IClientUnknown'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PhysPropClientside::`vftable'{for `IClientRenderable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PhysPropClientside::`vftable'{for `IClientNetworkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PhysPropClientside::`vftable'{for `IClientThinkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PhysPropClientside::`vftable'{for `C_BaseAnimating'};
  this->C_BreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_PhysPropClientside::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&C_PhysPropClientside::`vftable'{for `IBreakableWithPropData'};
  this->IMultiplayerPhysics::__vftable = (IMultiplayerPhysics_vtbl *)&C_PhysPropClientside::`vftable'{for `IMultiplayerPhysics'};
  PhysCleanupFrictionSounds(pEntity: this);
  C_BaseEntity::VPhysicsDestroyObject(this);
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014B780
// Name: public: virtual void C_PhysPropClientside::SetHealth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetHealth(C_PhysPropClientside *this, int iHealth)
{
  this->m_iHealth = iHealth;
}

//------------------------------------------------------------------------------
// Address: 0x1014B790
// Name: public: virtual void C_PhysPropClientside::SetDmgModBullet(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetDmgModBullet(C_PhysPropClientside *this, VarMapEntry_t *flDmgMod)
{
  this->m_VarMap.m_Entries.m_Memory.m_pMemory = flDmgMod;
}

//------------------------------------------------------------------------------
// Address: 0x1014B7B0
// Name: public: virtual void C_PhysPropClientside::SetDmgModExplosive(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetDmgModExplosive(C_PhysPropClientside *this, int flDmgMod)
{
  this->m_VarMap.m_Entries.m_Memory.m_nGrowSize = flDmgMod;
}

//------------------------------------------------------------------------------
// Address: 0x1014B7D0
// Name: public: virtual float C_PhysPropClientside::GetDmgModBullet(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PhysPropClientside::GetDmgModBullet(C_PhysPropClientside *this)
{
  return *(float *)&this->m_VarMap.m_Entries.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1014B7E0
// Name: public: virtual float C_PhysPropClientside::GetDmgModClub(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PhysPropClientside::GetDmgModClub(C_PhysPropClientside *this)
{
  return *(float *)&this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x1014B800
// Name: public: virtual float C_PhysPropClientside::GetDmgModFire(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PhysPropClientside::GetDmgModFire(C_PhysPropClientside *this)
{
  return *(float *)&this->m_VarMap.m_Entries.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1014B810
// Name: public: virtual void C_PhysPropClientside::SetExplosiveRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetExplosiveRadius(C_PhysPropClientside *this, float flRadius)
{
  *((float *)&this->m_pfnTouch + 1) = flRadius;
}

//------------------------------------------------------------------------------
// Address: 0x1014B850
// Name: public: virtual float C_PhysPropClientside::GetExplosiveRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PhysPropClientside::GetExplosiveRadius(C_PhysPropClientside *this)
{
  return *((float *)&this->m_pfnTouch + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1014B860
// Name: public: virtual float C_PhysPropClientside::GetExplosiveDamage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PhysPropClientside::GetExplosiveDamage(C_PhysPropClientside *this)
{
  return *(float *)&this->m_pfnTouch;
}

//------------------------------------------------------------------------------
// Address: 0x1014B870
// Name: public: virtual void C_PhysPropClientside::SetPhysicsDamageTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetPhysicsDamageTable(C_PhysPropClientside *this, VarMapEntry_t *iszTableName)
{
  this->m_VarMap.m_Entries.m_pElements = iszTableName;
}

//------------------------------------------------------------------------------
// Address: 0x1014B880
// Name: public: virtual char const __near * C_PhysPropClientside::GetPhysicsDamageTable(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall C_PhysPropClientside::GetPhysicsDamageTable(CModelRenderSystem *this)
{
  return (IMaterial *)this->m_BoneToWorld.m_commitSize;
}

//------------------------------------------------------------------------------
// Address: 0x1014B8A0
// Name: public: virtual char const __near * C_PhysPropClientside::GetBreakableModel(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_PhysPropClientside::GetBreakableModel(C_PhysPropClientside *this)
{
  return (const char *)this->m_VarMap.m_nInterpolatedEntries;
}

//------------------------------------------------------------------------------
// Address: 0x1014B8B0
// Name: public: virtual void C_PhysPropClientside::SetBreakableSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetBreakableSkin(C_PhysPropClientside *this, int iSkin)
{
  LODWORD(this->m_VarMap.m_lastInterpolationTime) = iSkin;
}

//------------------------------------------------------------------------------
// Address: 0x1014B8C0
// Name: public: virtual int C_PhysPropClientside::GetBreakableSkin(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PhysPropClientside::GetBreakableSkin(C_PhysPropClientside *this)
{
  return LODWORD(this->m_VarMap.m_lastInterpolationTime);
}

//------------------------------------------------------------------------------
// Address: 0x1014B8D0
// Name: public: virtual void C_PhysPropClientside::SetBreakableCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetBreakableCount(C_PhysPropClientside *this, int iCount)
{
  *((_DWORD *)&this->m_VarMap + 7) = iCount;
}

//------------------------------------------------------------------------------
// Address: 0x1014B8E0
// Name: public: virtual void C_PhysPropClientside::SetMaxBreakableSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetMaxBreakableSize(C_PhysPropClientside *this, int iSize)
{
  LODWORD(this->m_pfnThink) = iSize;
}

//------------------------------------------------------------------------------
// Address: 0x1014B8F0
// Name: public: virtual int C_PhysPropClientside::GetMaxBreakableSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PhysPropClientside::GetMaxBreakableSize(C_PhysPropClientside *this)
{
  return this->m_pfnThink;
}

//------------------------------------------------------------------------------
// Address: 0x1014B900
// Name: public: virtual void C_PhysPropClientside::SetPropDataBlocksLOS(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetPropDataBlocksLOS(C_PhysPropClientside *this, bool bBlocksLOS)
{
  BYTE8(this->m_pfnTouch) = 1;
  C_BaseEntity::SetBlocksLOS(this: (C_PhysPropClientside *)((char *)this - 3280), bBlocksLOS);
}

//------------------------------------------------------------------------------
// Address: 0x1014B920
// Name: public: virtual void C_PhysPropClientside::SetPropDataIsAIWalkable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetPropDataIsAIWalkable(C_PhysPropClientside *this, bool b)
{
  BYTE9(this->m_pfnTouch) = 1;
  C_BaseEntity::SetAIWalkable(this: (C_PhysPropClientside *)((char *)this - 3280), bBlocksLOS: b);
}

//------------------------------------------------------------------------------
// Address: 0x1014B940
// Name: public: virtual void C_PhysPropClientside::SetBasePropData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetBasePropData(C_PhysPropClientside *this, const char *iszBase)
{
  DWORD1(this->m_pfnThink) = iszBase;
}

//------------------------------------------------------------------------------
// Address: 0x1014B950
// Name: public: virtual void C_PhysPropClientside::SetInteraction(enum propdata_interactions_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetInteraction(C_PhysPropClientside *this, propdata_interactions_t Interaction)
{
  DWORD2(this->m_pfnThink) |= 1 << Interaction;
}

//------------------------------------------------------------------------------
// Address: 0x1014B970
// Name: public: virtual bool C_PhysPropClientside::HasInteraction(enum propdata_interactions_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_PhysPropClientside::HasInteraction(C_PhysPropClientside *this, propdata_interactions_t Interaction)
{
  return ((1 << Interaction) & DWORD2(this->m_pfnThink)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014B990
// Name: public: virtual void C_PhysPropClientside::SetPhysicsMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::SetPhysicsMode(C_PhysPropClientside *this, IClientNetworkable_vtbl *iMode)
{
  if ( this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable == nullptr )
    this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = iMode;
}

//------------------------------------------------------------------------------
// Address: 0x1014B9B0
// Name: public: virtual void C_PhysPropClientside::StartTouch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::StartTouch(C_PhysPropClientside *this, C_BaseEntity *pOther)
{
  if ( *(float *)(gpGlobals.m_Index + 12) > this->m_flTouchDelta )
  {
    this->HitSurface(this, a2: pOther);
    this->m_flTouchDelta = *(float *)(gpGlobals.m_Index + 12) + 0.1;
  }
  CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: (int)pOther);
}

//------------------------------------------------------------------------------
// Address: 0x1014BA10
// Name: public: static void C_PhysPropClientside::DestroyAll(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
static void __thiscall C_PhysPropClientside::DestroyAll(void *this)
{
  C_BaseEntity *i; // eax
  _DWORD *v2; // eax
  void *iterator; // [esp+0h] [ebp-4h] OVERLAPPED BYREF

  iterator = this;
  C_BaseEntityIterator::C_BaseEntityIterator(this: (C_BaseEntityIterator *)&iterator);
  for ( i = C_BaseEntityIterator::Next(this: (C_BaseEntityIterator *)&iterator);
        i != nullptr;
        i = C_BaseEntityIterator::Next(this: (C_BaseEntityIterator *)&iterator) )
  {
    v2 = __RTDynamicCast(
           inptr: i,
           VfDelta: 0,
           SrcType: &C_BaseEntity `RTTI Type Descriptor',
           TargetType: &C_PhysPropClientside `RTTI Type Descriptor',
           isReference: 0);
    if ( v2 != nullptr )
      (*(void (__thiscall **)(_DWORD *))(v2[2] + 4))(a1: v2 + 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BA70
// Name: public: virtual void C_PhysPropClientside::OnTakeDamage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::OnTakeDamage(C_PhysPropClientside *this, int iDamage)
{
  if ( this->m_takedamage != 0 )
  {
    this->m_iHealth -= iDamage;
    if ( this->m_iHealth <= 0 )
      this->Break(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BAA0
// Name: public: virtual void C_PhysPropClientside::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_PhysPropClientside::ClientThink(C_PhysPropClientside *this@<ecx>, int a2@<esi>)
{
  IMultiplayerPhysics_vtbl *v2; // xmm0_4
  float v3; // xmm1_4
  C_BaseEntity *v4; // esi

  v2 = this->IMultiplayerPhysics::__vftable;
  if ( *(float *)&v2 >= 0.0 )
  {
    v3 = *(float *)(gpGlobals.m_Index + 12);
    if ( v3 < *(float *)&v2 )
    {
      v4 = (C_PhysPropClientside *)((char *)this - 12);
      C_BaseEntity::SetRenderMode(
        this: (C_PhysPropClientside *)((char *)this - 12),
        nRenderMode: kRenderTransTexture,
        bForceUpdate: false);
      C_BaseEntity::SetRenderAlpha(this: v4, a: (unsigned __int8)(int)(float)((float)(*(float *)&v2 - v3) * 256.0));
      ((void (__thiscall *)(C_BaseEntity *, int, int))v4->SetNextClientThink)(a1: v4, a2: -996040704, a3: a2);
    }
    else
    {
      (*(void (__thiscall **)(char *, C_PhysPropClientside *))(*((_DWORD *)this - 1) + 4))(
        a1: (char *)this - 4,
        a2: this);
    }
  }
  else
  {
    (*(void (__stdcall **)(int, C_PhysPropClientside *))(*((_DWORD *)this - 3) + 456))(a1: -1082130432, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BB50
// Name: public: virtual void C_PhysPropClientside::StartFadeOut(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::StartFadeOut(C_PhysPropClientside *this, float fDelay)
{
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // edx

  SetNextClientThink = this->SetNextClientThink;
  this->m_fDeathTime = (float)(*(float *)(gpGlobals.m_Index + 12) + fDelay) + 1.0;
  ((void (__stdcall *)(_DWORD))SetNextClientThink)(a1: *(float *)(gpGlobals.m_Index + 12) + fDelay);
}

//------------------------------------------------------------------------------
// Address: 0x1014BBA0
// Name: public: C_PhysPropClientside::C_PhysPropClientside(void)
// Source: json
//------------------------------------------------------------------------------
C_PhysPropClientside *__thiscall C_PhysPropClientside::C_PhysPropClientside(C_PhysPropClientside *this)
{
  C_BreakableProp::C_BreakableProp(this);
  this->IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&IBreakableWithPropData::`vftable';
  this->IMultiplayerPhysics::__vftable = (IMultiplayerPhysics_vtbl *)&IMultiplayerPhysics::`vftable';
  this->m_fDeathTime = -1.0;
  this->m_impactEnergyScale = 1.0;
  this->m_iHealth = 0;
  this->m_iPhysicsMode = 0;
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PhysPropClientside_vtbl *)&C_PhysPropClientside::`vftable'{for `IClientUnknown'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PhysPropClientside::`vftable'{for `IClientRenderable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PhysPropClientside::`vftable'{for `IClientNetworkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PhysPropClientside::`vftable'{for `IClientThinkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PhysPropClientside::`vftable'{for `C_BaseAnimating'};
  this->C_BreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_PhysPropClientside::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&C_PhysPropClientside::`vftable'{for `IBreakableWithPropData'};
  this->IMultiplayerPhysics::__vftable = (IMultiplayerPhysics_vtbl *)&C_PhysPropClientside::`vftable'{for `IMultiplayerPhysics'};
  this->m_flTouchDelta = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014BC70
// Name: public: virtual bool C_PhysPropClientside::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PhysPropClientside::KeyValue(C_PhysPropClientside *this, char *szKeyName, const char *szValue)
{
  bool result; // al
  const char *v5; // eax
  int v6; // eax
  float flMinDist; // [esp+0h] [ebp-10h]
  float flMaxDist; // [esp+4h] [ebp-Ch]
  float flMaxDista; // [esp+4h] [ebp-Ch]
  float flFadeMinDist; // [esp+1Ch] [ebp+Ch]
  float flFadeMinDista; // [esp+1Ch] [ebp+Ch]

  if ( _V_stricmp(s1: szKeyName, s2: "physdamagescale") == 0 )
  {
    this->m_impactEnergyScale = atof(nptr: szValue);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "health") == 0 )
  {
    this->m_iHealth = V_atoi(str: szValue);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "spawnflags") == 0 )
  {
    this->m_spawnflags = V_atoi(str: szValue);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "model") == 0 )
  {
    v5 = AllocPooledString(pszValue: szValue);
    C_BaseEntity::SetModelName(this, name: v5);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "fademaxdist") == 0 )
  {
    flFadeMinDist = V_atof(str: szValue);
    flMinDist = C_BaseEntity::GetMinFadeDist(this);
    C_BaseEntity::SetDistanceFade(this, flMinDist, flMaxDist: flFadeMinDist);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "fademindist") != 0 )
  {
    if ( _V_stricmp(s1: szKeyName, s2: "fadescale") != 0 )
    {
      if ( _V_stricmp(s1: szKeyName, s2: "inertiaScale") != 0 )
      {
        if ( _V_stricmp(s1: szKeyName, s2: "skin") != 0 )
        {
          if ( _V_stricmp(s1: szKeyName, s2: "physicsmode") != 0 )
          {
            result = C_BaseEntity::KeyValue(this, szKeyName, szValue);
            if ( result )
              return true;
          }
          else
          {
            this->m_iPhysicsMode = V_atoi(str: szValue);
            return true;
          }
        }
        else
        {
          v6 = V_atoi(str: szValue);
          C_BaseAnimating::SetSkin(this, iSkin: v6);
          return true;
        }
      }
      else
      {
        this->m_inertiaScale = V_atof(str: szValue);
        return true;
      }
    }
    else
    {
      flMaxDista = V_atof(str: szValue);
      C_BaseEntity::SetGlobalFadeScale(this, a2: (int)this, a3: (int)szKeyName, flFadeScale: flMaxDista);
      return true;
    }
  }
  else
  {
    flFadeMinDista = V_atof(str: szValue);
    flMaxDist = C_BaseEntity::GetMaxFadeDist(this);
    C_BaseEntity::SetDistanceFade(this, flMinDist: flFadeMinDista, flMaxDist);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014BE90
// Name: public: virtual float C_PhysPropClientside::GetMass(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PhysPropClientside::GetMass(C_PhysPropClientside *this)
{
  int v1; // ecx

  v1 = *((_DWORD *)this - 656);
  if ( v1 != 0 )
    return (*(float (__thiscall **)(int))(*(_DWORD *)v1 + 116))(a1: v1);
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1014BEB0
// Name: public: virtual bool C_PhysPropClientside::IsAsleep(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PhysPropClientside::IsAsleep(C_PhysPropClientside *this)
{
  int v1; // ecx

  v1 = *((_DWORD *)this - 656);
  return v1 == 0 || (*(bool (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1014BED0
// Name: public: virtual void C_PhysPropClientside::ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_PhysPropClientside::ImpactTrace(
        C_PhysPropClientside *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        CGameTrace *pTrace,
        int iDamageType,
        char *pCustomImpactName)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  __int128 v13; // xmm4
  void (__thiscall *ApplyForceCenter)(IPhysicsObject *, const Vector *); // eax
  C_PhysPropClientside *v15; // esi
  float fraction; // xmm1_4
  int hitbox; // edx
  float v18; // xmm0_4
  __int16 surfaceProps; // ax
  float v20; // xmm0_4
  C_PhysPropClientside_vtbl *v21; // eax
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct IClientUnknown *); // edx
  Vector endpos; // [esp-Ch] [ebp-A4h] BYREF
  _BYTE data[108]; // [esp+0h] [ebp-98h] OVERLAPPED BYREF
  IPhysicsObject *v25; // [esp+78h] [ebp-20h]
  C_PhysPropClientside *v26; // [esp+7Ch] [ebp-1Ch]
  float v27; // [esp+80h] [ebp-18h] BYREF
  IPhysicsObject *pPhysicsObject; // [esp+84h] [ebp-14h]
  float v29; // [esp+88h] [ebp-10h]
  Vector dir; // [esp+8Ch] [ebp-Ch]
  float retaddr; // [esp+98h] [ebp+0h]

  dir.x = a2;
  dir.y = retaddr;
  v26 = this;
  m_pPhysicsObject = this->m_pPhysicsObject;
  v25 = m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    x = pTrace->startpos.x;
    y = pTrace->startpos.y;
    z = pTrace->startpos.z;
    v10 = pTrace->endpos.x - pTrace->startpos.x;
    v11 = pTrace->endpos.y - y;
    v12 = pTrace->endpos.z - z;
    v27 = v10;
    *(float *)&pPhysicsObject = v11;
    v29 = v12;
    if ( (iDamageType & 0x40) != 0 )
    {
      v13 = 0;
      v27 = v10 * 500.0;
      *(float *)&pPhysicsObject = v11 * 500.0;
      v29 = v12 * 500.0;
      ApplyForceCenter = m_pPhysicsObject->ApplyForceCenter;
      *(float *)&v13 = fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10));
      *(_OWORD *)&data[92] = v13;
      ((void (__thiscall *)(IPhysicsObject *, float *, int))ApplyForceCenter)(a1: m_pPhysicsObject, a2: &v27, a3);
      v15 = v26;
    }
    else
    {
      fraction = pTrace->fraction;
      *(float *)&data[96] = (float)(fraction * v10) + x;
      *(float *)&data[100] = (float)(v11 * fraction) + y;
      *(float *)&data[104] = (float)(fraction * v12) + z;
      VectorNormalize(vec: (Vector *)&v27);
      v27 = v27 * 4000.0;
      *(float *)&pPhysicsObject = *(float *)&pPhysicsObject * 4000.0;
      v29 = v29 * 4000.0;
      ((void (__thiscall *)(IPhysicsObject *, float *, _BYTE *, int))v25->ApplyForceOffset)(
        a1: v25,
        a2: &v27,
        a3: &data[96],
        a4: a3);
      hitbox = pTrace->hitbox;
      memset(&data[12], 0, 28);
      memset(&data[48], 0, 12);
      endpos = pTrace->endpos;
      *(float *)data = pTrace->startpos.x;
      v18 = pTrace->startpos.y;
      *(_DWORD *)&data[64] = 0;
      data[80] = 0;
      *(_DWORD *)&data[76] = 0;
      surfaceProps = pTrace->surface.surfaceProps;
      *(float *)&data[4] = v18;
      v20 = pTrace->startpos.z;
      v15 = v26;
      *(_WORD *)&data[60] = surfaceProps;
      v21 = v26->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      *(_DWORD *)&data[68] = iDamageType;
      *(_DWORD *)&data[72] = hitbox;
      GetRefEHandle = v21->GetRefEHandle;
      *(_DWORD *)&data[40] = -1;
      *(_DWORD *)&data[44] = 1065353216;
      *(float *)&data[8] = v20;
      *(_DWORD *)&data[40] = GetRefEHandle(this: v26)->m_Index;
      if ( pCustomImpactName != nullptr )
        DispatchEffect(pName: pCustomImpactName, data: (const CEffectData *)&endpos);
      else
        DispatchEffect(pName: "Impact", data: (const CEffectData *)&endpos);
    }
    ((void (__thiscall *)(C_PhysPropClientside *))v15->OnTakeDamage)(a1: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C140
// Name: public: static class C_PhysPropClientside __near * C_PhysPropClientside::CreateNew(bool)
// Source: json
//------------------------------------------------------------------------------
C_PhysPropClientside *__cdecl C_PhysPropClientside::CreateNew()
{
  C_PhysPropClientside *v0; // eax

  v0 = (C_PhysPropClientside *)C_BaseEntity::operator new(stAllocateBlock: 0xD30u);
  if ( v0 != nullptr )
    return C_PhysPropClientside::C_PhysPropClientside(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014C160
// Name: public: bool C_PhysPropClientside::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_PhysPropClientside::Initialize(C_PhysPropClientside *this)
{
  unsigned __int8 (__thiscall **p_mins)(C_PhysPropClientside *, const char *, _DWORD); // edi
  const char *ModelName; // eax
  const struct model_t *v4; // eax
  int ModelIndex; // eax
  int v6; // eax
  IPhysicsObject *inited; // eax
  const char *v9; // eax
  unsigned __int16 v10; // ax
  Vector *v11; // edi
  float mass; // [esp+20h] [ebp-664h]
  solid_t tmpSolid; // [esp+2Ch] [ebp-658h] BYREF
  Vector maxs; // [esp+66Ch] [ebp-18h] BYREF
  Vector mins; // [esp+678h] [ebp-Ch] BYREF

  p_mins = (unsigned __int8 (__thiscall **)(C_PhysPropClientside *, const char *, _DWORD))this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  ModelName = C_BaseEntity::GetModelName(this);
  if ( p_mins[91](a1: this, a2: ModelName, a3: 0) == 0 )
    return 0;
  v4 = this->GetModel(this: &this->IClientRenderable);
  if ( v4 != nullptr )
  {
    p_mins = (unsigned __int8 (__thiscall **)(C_PhysPropClientside *, const char *, _DWORD))&mins;
    modelinfo->GetModelBounds(this: modelinfo, a2: v4, a3: &mins, a4: &maxs);
    CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, &mins, &maxs);
  }
  ModelIndex = C_BaseEntity::GetModelIndex(this);
  if ( !PhysModelParseSolid(a1: (int)p_mins, solid: &tmpSolid, pEntity: this, modelIndex: ModelIndex) )
  {
    v6 = C_BaseEntity::GetModelIndex(this);
    DevMsg(a1: "C_PhysPropClientside::Initialize: PhysModelParseSolid failed for entity %i.\n", v6);
    return 0;
  }
  inited = C_BaseEntity::VPhysicsInitNormal(
             this,
             solidType: SOLID_VPHYSICS,
             nSolidFlags: 0,
             createAsleep: this->m_spawnflags & 1,
             pSolid: &tmpSolid);
  this->m_pPhysicsObject = inited;
  if ( inited != nullptr )
  {
    v10 = inited->GetCallbackFlags(this: inited);
    this->m_pPhysicsObject->SetCallbackFlags(this: this->m_pPhysicsObject, a2: v10 | 8);
    if ( (this->m_spawnflags & 8) != 0 )
      this->m_pPhysicsObject->EnableMotion(this: this->m_pPhysicsObject, a2: false);
    this->Spawn(this);
    if ( this->m_iPhysicsMode == 0 )
    {
      v11 = AllocTempVector();
      v11->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
      v11->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
      v11->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
      mass = this->m_pPhysicsObject->GetMass(this: this->m_pPhysicsObject);
      this->m_iPhysicsMode = GetAutoMultiplayerPhysicsMode(size: *v11, mass);
    }
    if ( (this->m_spawnflags & 0x2000) != 0 || this->m_iPhysicsMode != 3 || engine->IsInEditMode(this: engine) )
      return 0;
    if ( C_BaseEntity::GetMinFadeDist(this) < 0.0 )
      C_BaseEntity::SetDistanceFade(
        this,
        flMinDist: r_propsmaxdist.m_pParent->m_Value.m_fValue * 0.75,
        flMaxDist: r_propsmaxdist.m_pParent->m_Value.m_fValue);
    C_BaseEntity::SetCollisionGroup(this, collisionGroup: 17);
    this->UpdatePartitionListEntry(this);
    CCollisionProperty::UpdatePartition(this: &this->m_Collision);
    C_BaseEntity::SetBlocksLOS(this, bBlocksLOS: false);
    C_BaseEntity::CreateShadow(this);
    C_BaseEntity::UpdateVisibility(this);
    ((void (__thiscall *)(C_PhysPropClientside *, int))this->SetNextClientThink)(a1: this, a2: -1082130432);
    return 1;
  }
  else
  {
    v9 = C_BaseEntity::GetModelName(this);
    DevMsg(a1: " C_PhysPropClientside::Initialize: VPhysicsInitNormal() failed for %s.\n", v9);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C3D0
// Name: public: virtual void C_PhysPropClientside::Break(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_PhysPropClientside::Break(C_PhysPropClientside *this@<ecx>, int a2@<ebx>)
{
  IPhysicsObject *m_pPhysicsObject; // edi
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // eax
  int v5; // eax
  C_PhysPropClientside_vtbl *v6; // edx
  float v7; // xmm0_4
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // eax
  float m_impactEnergyScale; // xmm0_4
  int m_CollisionGroup; // eax
  int ModelIndex; // eax
  breakablepropparams_t params; // [esp+8h] [ebp-4Ch] BYREF
  Vector angVelocity; // [esp+24h] [ebp-30h] BYREF
  Vector velocity; // [esp+30h] [ebp-24h] BYREF
  QAngle angles; // [esp+3Ch] [ebp-18h] BYREF
  Vector origin; // [esp+48h] [ebp-Ch] BYREF

  this->m_takedamage = 0;
  m_pPhysicsObject = this->m_pPhysicsObject;
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  if ( m_pPhysicsObject != nullptr )
  {
    m_pPhysicsObject->GetVelocity(this: m_pPhysicsObject, a2: &velocity, a3: &angVelocity);
    m_pPhysicsObject->GetPosition(this: m_pPhysicsObject, a2: &origin, a3: &angles);
    m_pPhysicsObject->RecheckCollisionFilter(this: m_pPhysicsObject);
  }
  else
  {
    C_BaseEntity::CalcAbsoluteVelocity(this);
    GetAbsOrigin = this->GetAbsOrigin;
    velocity = this->m_vecAbsVelocity;
    angVelocity.x = this->m_vecAngVelocity.z;
    angVelocity.y = this->m_vecAngVelocity.x;
    angVelocity.z = this->m_vecAngVelocity.y;
    v5 = (int)GetAbsOrigin(this);
    v6 = this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    origin.x = *(float *)v5;
    origin.y = *(float *)(v5 + 4);
    v7 = *(float *)(v5 + 8);
    GetAbsAngles = v6->GetAbsAngles;
    origin.z = v7;
    angles = *GetAbsAngles(this);
  }
  m_impactEnergyScale = this->m_impactEnergyScale;
  params.velocity = &velocity;
  m_CollisionGroup = this->m_CollisionGroup;
  params.origin = &origin;
  params.angles = &angles;
  params.angularVelocity = &angVelocity;
  params.impactEnergyScale = m_impactEnergyScale;
  params.defCollisionGroup = m_CollisionGroup;
  if ( m_CollisionGroup == 0 )
    params.defCollisionGroup = 4;
  params.defBurstScale = 100.0;
  ModelIndex = C_BaseEntity::GetModelIndex(this);
  PropBreakableCreateAll(
    a1: a2,
    a2: (int)this,
    modelindex: ModelIndex,
    pPhysics: m_pPhysicsObject,
    &params,
    pEntity: this,
    iPrecomputedBreakableCount: -1,
    bIgnoreGibLimit: false,
    defaultLocation: true);
  this->Release(this: &this->IClientNetworkable);
}

//------------------------------------------------------------------------------
// Address: 0x1014C550
// Name: public: virtual void C_PhysPropClientside::Clone(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::Clone(C_PhysPropClientside *this, Vector *velocity)
{
  C_PhysPropClientside *v3; // eax
  C_PhysPropClientside *v4; // esi
  unsigned int v5; // eax
  float (__thiscall *GetDmgModClub)(IBreakableWithPropData *); // eax
  float (__thiscall *GetDmgModExplosive)(IBreakableWithPropData *); // eax
  const char *ModelName; // eax
  const Vector *LocalOrigin; // eax
  const QAngle *LocalAngles; // eax
  int v11; // eax
  IUniformRandomStream *v12; // ecx
  int m_iHealth; // ebx
  IPhysicsObject *m_pPhysicsObject; // edi
  void (__thiscall *AddVelocity)(IPhysicsObject *, const Vector *, const Vector *); // edx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // [esp+14h] [ebp-20h]
  float v19; // [esp+14h] [ebp-20h]
  float v20; // [esp+14h] [ebp-20h]
  Vector rndVel; // [esp+24h] [ebp-10h] BYREF
  float rndf; // [esp+30h] [ebp-4h]

  v3 = (C_PhysPropClientside *)C_BaseEntity::operator new(stAllocateBlock: 0xD30u);
  if ( v3 != nullptr )
  {
    v4 = C_PhysPropClientside::C_PhysPropClientside(this: v3);
    if ( v4 != nullptr )
    {
      v5 = this->m_spawnflags & 0xFFFFFFF7;
      rndf = *(float *)&v4->IBreakableWithPropData::__vftable;
      v4->m_spawnflags = v5;
      v18 = this->GetDmgModBullet(this: &this->IBreakableWithPropData);
      (*(void (__thiscall **)(int, _DWORD))LODWORD(rndf))(a1: (int)&v4->IBreakableWithPropData, a2: LODWORD(v18));
      GetDmgModClub = this->GetDmgModClub;
      rndf = *(float *)&v4->IBreakableWithPropData::__vftable;
      v19 = GetDmgModClub(this: &this->IBreakableWithPropData);
      (*(void (__thiscall **)(IBreakableWithPropData *, _DWORD))(LODWORD(rndf) + 4))(
        a1: &v4->IBreakableWithPropData,
        a2: LODWORD(v19));
      GetDmgModExplosive = this->GetDmgModExplosive;
      rndf = *(float *)&v4->IBreakableWithPropData::__vftable;
      v20 = GetDmgModExplosive(this: &this->IBreakableWithPropData);
      (*(void (__thiscall **)(IBreakableWithPropData *, _DWORD))(LODWORD(rndf) + 8))(
        a1: &v4->IBreakableWithPropData,
        a2: LODWORD(v20));
      ModelName = C_BaseEntity::GetModelName(this);
      C_BaseEntity::SetModelName(this: v4, name: ModelName);
      LocalOrigin = C_BaseEntity::GetLocalOrigin(this);
      C_BaseEntity::SetLocalOrigin(this: v4, origin: LocalOrigin);
      LocalAngles = C_BaseEntity::GetLocalAngles(this);
      C_BaseEntity::SetLocalAngles(this: v4, angles: LocalAngles);
      C_BaseEntity::SetOwnerEntity(this: v4, pOwner: this);
      v4->SetPhysicsMode(this: &v4->IBreakableWithPropData, a2: 3);
      if ( C_PhysPropClientside::Initialize(this: v4) == 0 )
        goto LABEL_8;
      v11 = this->GetSkin(this: &this->IClientRenderable);
      C_BaseAnimating::SetSkin(this: v4, iSkin: v11);
      m_iHealth = this->m_iHealth;
      v4->m_iHealth = m_iHealth;
      if ( m_iHealth == 0 )
      {
        v4->m_takedamage = 0;
        C_BaseEntity::SetCollisionGroup(this: v4, collisionGroup: 0);
      }
      m_pPhysicsObject = v4->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr )
      {
        rndf = _RandomFloat(this: v12, a2: -0.025, a3: 0.025);
        AddVelocity = m_pPhysicsObject->AddVelocity;
        v16 = velocity->y + (float)(velocity->y * rndf);
        v17 = velocity->z + (float)(velocity->z * rndf);
        rndVel.x = velocity->x + (float)(velocity->x * rndf);
        rndVel.y = v16;
        rndVel.z = v17;
        AddVelocity(this: m_pPhysicsObject, a2: &rndVel, a3: nullptr);
      }
      else
      {
LABEL_8:
        v4->Release(this: &v4->IClientNetworkable);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C760
// Name: protected: static void C_PhysPropClientside::ParseAllEntities(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_PhysPropClientside::ParseAllEntities(const char *a1@<edi>, char *pMapData)
{
  char *v2; // esi
  IMDLCache *v3; // edi
  C_PhysPropClientside *v4; // eax
  C_PhysPropClientside *v5; // eax
  C_PhysPropClientside *v6; // esi
  const char *Entity; // eax
  const char *v8; // [esp-8h] [ebp-2818h]
  char pWorkBuffer[2048]; // [esp+4h] [ebp-280Ch] BYREF
  char keyName[2048]; // [esp+804h] [ebp-200Ch] BYREF
  char v11[2048]; // [esp+1004h] [ebp-180Ch] BYREF
  char newToken[2048]; // [esp+1804h] [ebp-100Ch] BYREF
  char value[2048]; // [esp+2004h] [ebp-80Ch] BYREF
  CEntityMapData mapData; // [esp+2804h] [ebp-Ch] BYREF

  v2 = (char *)MapEntity_ParseToken(data: pMapData, newToken);
  if ( v2 != nullptr )
  {
    v8 = a1;
    do
    {
      if ( newToken[0] == 123 )
      {
        v3 = mdlcache;
        mapData.m_pEntData = v2;
        mapData.m_nEntDataSize = -1;
        mapData.m_pCurrentKey = v2;
        mdlcache->BeginLock(this: mdlcache);
        if ( CEntityMapData::ExtractValue(this: &mapData, keyName: "classname", value) == 0 )
          _Error(this: (ISceneTokenProcessor *)&stru_10469AA0, a2: v8);
        if ( _V_strcmp(s1: value, s2: "prop_physics_multiplayer") == 0
          && (v4 = (C_PhysPropClientside *)C_BaseEntity::operator new(stAllocateBlock: 0xD30u)) != nullptr
          && (v5 = C_PhysPropClientside::C_PhysPropClientside(this: v4), v6 = v5, v5 != nullptr) )
        {
          C_BaseEntity::ParseMapData(this: v5, &mapData);
          if ( C_PhysPropClientside::Initialize(this: v6) == 0 )
            v6->Release(this: &v6->IClientNetworkable);
        }
        else
        {
          if ( _V_strcmp(s1: value, s2: "func_proprrespawnzone") == 0 && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
            __debugbreak();
          if ( CEntityMapData::GetFirstKey(this: &mapData, keyName, value: v11) != 0 )
          {
            while ( CEntityMapData::GetNextKey(this: &mapData, keyName, value: v11) != 0 )
              ;
          }
        }
        v2 = (char *)CEntityMapData::CurrentBufferPosition(this: (CBaseAchievement *)&mapData);
        v3->EndLock(this: v3);
      }
      else
      {
        _Error(this: (ISceneTokenProcessor *)&stru_10486E90, a2: newToken);
      }
      Entity = MapEntity_SkipToNextEntity(pMapData: v2, pWorkBuffer);
      v2 = (char *)MapEntity_ParseToken(data: Entity, newToken);
    }
    while ( v2 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C900
// Name: public: static void C_PhysPropClientside::RecreateAll(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall C_PhysPropClientside::RecreateAll(void *a1@<ecx>, const char *a2@<edi>)
{
  char *v2; // eax

  C_PhysPropClientside::DestroyAll(this: a1);
  v2 = (char *)engine->GetMapEntitiesString(this: engine);
  C_PhysPropClientside::ParseAllEntities(a1: a2, pMapData: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1014C920
// Name: public: virtual void C_PhysPropClientside::HitSurface(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysPropClientside::HitSurface(C_PhysPropClientside *this, C_BaseEntity *pOther)
{
  const CGameTrace *TouchTrace; // esi
  CGameTrace tr; // [esp+0h] [ebp-54h] BYREF

  if ( this->HasInteraction(this: &this->IBreakableWithPropData, a2: PROPINTER_WORLD_BLOODSPLAT) )
  {
    TouchTrace = C_BaseEntity::GetTouchTrace();
    CBaseTrace::operator=(this: &tr, __that: TouchTrace);
    tr.fractionleftsolid = TouchTrace->fractionleftsolid;
    tr.surface = TouchTrace->surface;
    tr.hitgroup = TouchTrace->hitgroup;
    tr.physicsbone = TouchTrace->physicsbone;
    tr.worldSurfaceIndex = TouchTrace->worldSurfaceIndex;
    tr.m_pEnt = TouchTrace->m_pEnt;
    tr.hitbox = TouchTrace->hitbox;
    if ( tr.m_pEnt != nullptr )
      UTIL_BloodDecalTrace(pTrace: &tr, bloodColor: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C9A0
// Name: class C_BaseAnimating __near * BreakModelCreate_Ragdoll(class C_BaseEntity __near *,struct breakmodel_t __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
C_ClientRagdoll *__usercall BreakModelCreate_Ragdoll@<eax>(
        int a1@<ebp>,
        C_BaseEntity *pOwnerEnt,
        breakmodel_t *pModel,
        const Vector *position,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angVelocity)
{
  void *v7; // esp
  C_BaseAnimating *v8; // edi
  C_ClientRagdoll *v9; // eax
  C_ClientRagdoll *v10; // esi
  unsigned __int8 r; // al
  unsigned __int8 b; // dl
  unsigned __int8 g; // cl
  unsigned __int8 RenderAlpha; // al
  int v16; // eax
  const char *v17; // eax
  ModelScaleType_t ModelScaleType; // eax
  CStudioHdr *ModelPtr; // eax
  CRagdoll *Ragdoll; // eax
  IUniformRandomStream *v21; // ecx
  IPhysicsObject *m_pPhysicsObject; // edi
  float y; // xmm1_4
  float z; // xmm2_4
  void (__thiscall *AddVelocity)(IPhysicsObject *, const Vector *, const Vector *); // edx
  float flForcedRetireTime; // xmm0_4
  float fadeTime; // xmm1_4
  void (__thiscall *UpdatePartitionListEntry)(C_BaseEntity *); // eax
  float flTime; // [esp+10h] [ebp-9030h]
  matrix3x4a_t v30[256]; // [esp+24h] [ebp-901Ch] BYREF
  matrix3x4a_t v31[256]; // [esp+3024h] [ebp-601Ch] BYREF
  matrix3x4a_t v32[256]; // [esp+6024h] [ebp-301Ch] BYREF
  float v33[3]; // [esp+9024h] [ebp-1Ch] BYREF
  float scale; // [esp+9030h] [ebp-10h]
  int v35; // [esp+9034h] [ebp-Ch]
  void *v36; // [esp+9038h] [ebp-8h]
  void *retaddr; // [esp+9040h] [ebp+0h]

  v35 = a1;
  v36 = retaddr;
  v7 = alloca(36888);
  v8 = (C_BaseAnimating *)__RTDynamicCast(
                            inptr: pOwnerEnt,
                            VfDelta: 0,
                            SrcType: &C_BaseEntity `RTTI Type Descriptor',
                            TargetType: &C_BaseAnimating `RTTI Type Descriptor',
                            isReference: 0);
  if ( v8 == nullptr )
    return nullptr;
  v9 = (C_ClientRagdoll *)C_BaseEntity::operator new(stAllocateBlock: 0xD58u);
  if ( v9 == nullptr )
    return nullptr;
  v10 = C_ClientRagdoll::C_ClientRagdoll(this: v9, bRestoring: false, fullInit: true);
  if ( v10 == nullptr )
    return nullptr;
  if ( !v10->InitializeAsClientEntity(this: v10, a2: pModel->modelName, a3: false) )
  {
    v10->Release(this: &v10->IClientNetworkable);
    return nullptr;
  }
  C_BaseEntity::SetAbsOrigin(this: v10, absOrigin: position);
  C_BaseEntity::SetAbsAngles(this: v10, absAngles: angles);
  C_BaseEntity::SetParent(this: v10, pParentEntity: v8, iParentAttachment: 0);
  C_BaseAnimating::ForceSetupBonesAtTime(
    this: v10,
    a2: (int)v10,
    pBonesOut: v30,
    flTime: *(float *)(gpGlobals.m_Index + 12) - 0.1);
  C_BaseAnimating::ForceSetupBonesAtTime(
    this: v10,
    a2: (int)v10,
    pBonesOut: v31,
    flTime: *(float *)(gpGlobals.m_Index + 12));
  C_BaseAnimating::ForceSetupBonesAtTime(
    this: v10,
    a2: (int)v10,
    pBonesOut: v32,
    flTime: *(float *)(gpGlobals.m_Index + 12));
  C_BaseEntity::SetParent(this: v10, pParentEntity: nullptr, iParentAttachment: 0);
  C_BaseAnimating::IgniteRagdoll(this: v10, pSource: v8);
  C_BaseAnimating::TransferDissolveFrom(this: v10, pSource: v8);
  C_BaseAnimating::InitModelEffects(this: v10);
  if ( (v8->m_fEffects & 0x10) != 0 )
    C_BaseEntity::AddEffects(this: v10, nEffects: 16);
  v10->m_bClientSideRagdoll = true;
  C_BaseEntity::SetRenderMode(this: v10, nRenderMode: (RenderMode_t)v8->m_nRenderMode, bForceUpdate: false);
  r = v8->m_clrRender.m_Value.r;
  b = v8->m_clrRender.m_Value.b;
  g = v8->m_clrRender.m_Value.g;
  if ( v10->m_clrRender.m_Value.r != r )
    v10->m_clrRender.m_Value.r = r;
  if ( v10->m_clrRender.m_Value.g != g )
    v10->m_clrRender.m_Value.g = g;
  if ( v10->m_clrRender.m_Value.b != b )
    v10->m_clrRender.m_Value.b = b;
  RenderAlpha = C_BaseEntity::GetRenderAlpha(this: v8);
  C_BaseEntity::SetRenderAlpha(this: v10, a: RenderAlpha);
  flTime = C_BaseEntity::GetGlobalFadeScale(this: v8);
  C_BaseEntity::SetGlobalFadeScale(this: v10, a2: (int)v8, a3: (int)v10, flFadeScale: flTime);
  v16 = v8->GetSkin(this: &v8->IClientRenderable);
  C_BaseAnimating::SetSkin(this: v10, iSkin: v16);
  ((void (__thiscall *)(C_ClientRagdoll *, int))v10->SetNextClientThink)(a1: v10, a2: -996040704);
  v17 = AllocPooledString(pszValue: pModel->modelName);
  C_BaseEntity::SetModelName(this: v10, name: v17);
  C_BaseAnimating::SetSequence(this: v10, nSequence: 0);
  C_BaseAnimating::ResetSequenceInfo(this: v10);
  scale = v8->m_flModelScale.m_Value;
  ModelScaleType = C_BaseAnimating::GetModelScaleType(this: v8);
  C_BaseAnimating::SetModelScale(this: v10, scale, scaleType: ModelScaleType);
  C_BaseEntity::SetCollisionGroup(this: v10, collisionGroup: 1);
  ModelPtr = C_BaseAnimating::GetModelPtr(this: v10);
  if ( ModelPtr != nullptr )
  {
    Ragdoll = CreateRagdoll(
                ent: v10,
                pstudiohdr: ModelPtr,
                forceVector: &vec3_origin,
                forceBone: 0,
                pDeltaBones0: &v30[0],
                pDeltaBones1: &v31[0],
                pCurrentBonePosition: &v32[0],
                dt: 0.1,
                bFixedConstraints: false);
    m_pPhysicsObject = v10->m_pPhysicsObject;
    v10->m_pRagdoll = Ragdoll;
    if ( m_pPhysicsObject != nullptr )
    {
      scale = _RandomFloat(this: v21, a2: -0.025, a3: 0.025);
      y = velocity->y;
      z = velocity->z;
      AddVelocity = m_pPhysicsObject->AddVelocity;
      v33[0] = velocity->x + (float)(velocity->x * scale);
      v33[1] = y + (float)(y * scale);
      v33[2] = z + (float)(z * scale);
      AddVelocity(this: m_pPhysicsObject, a2: (const Vector *)v33, a3: angVelocity);
    }
    C_BaseEntity::ApplyLocalAngularVelocityImpulse(this: v10, angImpulse: angVelocity);
    flForcedRetireTime = 0.0;
    if ( v10->m_pRagdoll != nullptr )
    {
      v10->m_bImportant = false;
      fadeTime = pModel->fadeTime;
      if ( fadeTime > 0.0 )
        flForcedRetireTime = *(float *)(gpGlobals.m_Index + 12) + fadeTime;
      CRagdollLRURetirement::MoveToTopOfLRU(this: &s_RagdollLRU, pRagdoll: v10, bImportant: false, flForcedRetireTime);
      v10->m_bFadeOut = true;
    }
    C_BaseEntity::DestroyShadow(this: v10);
    C_BaseEntity::CreateShadow(this: v10);
    C_BaseEntity::SetAbsOrigin(this: v10, absOrigin: position);
    C_BaseEntity::SetAbsAngles(this: v10, absAngles: angles);
    UpdatePartitionListEntry = v10->UpdatePartitionListEntry;
    v10->m_flPlaybackRate = 0.0;
    UpdatePartitionListEntry(this: v10);
    C_BaseEntity::MarkRenderHandleDirty(this: v10);
    return v10;
  }
  else
  {
    v10->Release(this: &v10->IClientNetworkable);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014CD70
// Name: class C_BaseEntity __near * BreakModelCreateSingle(class C_BaseEntity __near *,struct breakmodel_t __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,int,struct breakablepropparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
C_ClientRagdoll *__cdecl BreakModelCreateSingle(
        C_BaseEntity *pOwner,
        breakmodel_t *pModel,
        const Vector *position,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angVelocity,
        int nSkin)
{
  C_PhysPropClientside *v8; // eax
  C_PhysPropClientside *v9; // esi
  C_PhysPropClientside *v10; // ebx
  IBreakableWithPropData_vtbl *v11; // edx
  IBreakableWithPropData_vtbl *v12; // eax
  IBreakableWithPropData *v13; // ebx
  IBreakableWithPropData_vtbl *v14; // edx
  float (__thiscall *GetDmgModExplosive)(IBreakableWithPropData *); // eax
  const char *v16; // eax
  IUniformRandomStream *v17; // ecx
  bool v18; // zf
  float fadeMinDist; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // edi
  void (__thiscall *AddVelocity)(IPhysicsObject *, const Vector *, const Vector *); // edx
  float v22; // xmm1_4
  float v23; // xmm2_4
  float flMinDist; // [esp+14h] [ebp-24h]
  float flMinDista; // [esp+14h] [ebp-24h]
  float flMinDistb; // [esp+14h] [ebp-24h]
  Vector rndVel; // [esp+24h] [ebp-14h] BYREF
  C_PhysPropClientside *pBreakableOwner; // [esp+30h] [ebp-8h]
  IBreakableWithPropData_vtbl *v29; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF
  float rndf; // [esp+44h] [ebp+Ch]

  if ( pModel->isRagdoll )
    return BreakModelCreate_Ragdoll(
             a1: (int)&savedregs,
             pOwnerEnt: pOwner,
             pModel,
             position,
             angles,
             velocity,
             angVelocity);
  v8 = (C_PhysPropClientside *)C_BaseEntity::operator new(stAllocateBlock: 0xD30u);
  if ( v8 != nullptr )
  {
    v9 = C_PhysPropClientside::C_PhysPropClientside(this: v8);
    if ( v9 != nullptr )
    {
      v10 = (C_PhysPropClientside *)__RTDynamicCast(
                                      inptr: pOwner,
                                      VfDelta: 0,
                                      SrcType: &C_BaseEntity `RTTI Type Descriptor',
                                      TargetType: &C_PhysPropClientside `RTTI Type Descriptor',
                                      isReference: 0);
      pBreakableOwner = v10;
      if ( v10 != nullptr )
      {
        C_BaseEntity::SetEffects(this: v9, nEffects: v10->m_fEffects);
        v11 = v9->IBreakableWithPropData::__vftable;
        v9->m_spawnflags = v10->m_spawnflags & 0xFFFFFFF7;
        v12 = v10->IBreakableWithPropData::__vftable;
        v13 = &v10->IBreakableWithPropData;
        v29 = v11;
        flMinDist = v12->GetDmgModBullet(this: v13);
        ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v29->SetDmgModBullet)(
          a1: &v9->IBreakableWithPropData,
          a2: LODWORD(flMinDist));
        v14 = v13->__vftable;
        v29 = v9->IBreakableWithPropData::__vftable;
        flMinDista = v14->GetDmgModClub(this: v13);
        ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v29->SetDmgModClub)(
          a1: &v9->IBreakableWithPropData,
          a2: LODWORD(flMinDista));
        GetDmgModExplosive = v13->GetDmgModExplosive;
        v29 = v9->IBreakableWithPropData::__vftable;
        flMinDistb = GetDmgModExplosive(this: v13);
        ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v29->SetDmgModExplosive)(
          a1: &v9->IBreakableWithPropData,
          a2: LODWORD(flMinDistb));
        C_BreakableProp::CopyFadeFrom(this: v9, pSource: pBreakableOwner);
      }
      v16 = AllocPooledString(pszValue: pModel->modelName);
      C_BaseEntity::SetModelName(this: v9, name: v16);
      C_BaseEntity::SetLocalOrigin(this: v9, origin: position);
      C_BaseEntity::SetLocalAngles(this: v9, angles);
      C_BaseEntity::SetOwnerEntity(this: v9, pOwner);
      v9->SetPhysicsMode(this: &v9->IBreakableWithPropData, a2: 3);
      if ( C_PhysPropClientside::Initialize(this: v9) )
      {
        C_BaseAnimating::SetSkin(this: v9, iSkin: nSkin);
        v9->m_iHealth = (int)pModel->health;
        C_BaseEntity::SetCollisionGroup(this: v9, collisionGroup: 1);
        if ( pModel->health == 0.0 )
        {
          v18 = v9->m_CollisionGroup == 17;
          v9->m_takedamage = 0;
          if ( v18 )
            C_BaseEntity::SetCollisionGroup(this: v9, collisionGroup: 0);
        }
        if ( pModel->fadeTime > 0.0 )
          ((void (__thiscall *)(C_PhysPropClientside *, _DWORD))v9->StartFadeOut)(a1: v9, a2: LODWORD(pModel->fadeTime));
        fadeMinDist = pModel->fadeMinDist;
        if ( fadeMinDist > 0.0 && pModel->fadeMaxDist >= fadeMinDist )
          C_BaseEntity::SetDistanceFade(this: v9, flMinDist: fadeMinDist, flMaxDist: pModel->fadeMaxDist);
        m_pPhysicsObject = v9->m_pPhysicsObject;
        if ( m_pPhysicsObject != nullptr )
        {
          rndf = _RandomFloat(this: v17, a2: -0.025, a3: 0.025);
          AddVelocity = m_pPhysicsObject->AddVelocity;
          v22 = velocity->y + (float)(velocity->y * rndf);
          v23 = velocity->z + (float)(velocity->z * rndf);
          rndVel.x = velocity->x + (float)(velocity->x * rndf);
          rndVel.y = v22;
          rndVel.z = v23;
          AddVelocity(this: m_pPhysicsObject, a2: &rndVel, a3: angVelocity);
          return (C_ClientRagdoll *)v9;
        }
      }
      v9->Release(this: &v9->IClientNetworkable);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014D040
// Name: public: virtual void C_PhysPropClientside::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_PhysPropClientside::Spawn(C_PhysPropClientside *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  int ModelIndex; // eax
  int m_Size; // edi
  const struct model_t *(__thiscall *GetModel)(IClientRenderable *); // eax
  IVModelInfoClient_vtbl *v8; // edi
  int v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  KeyValues *Key; // eax
  CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > list; // [esp+14h] [ebp-14h] BYREF

  this->m_flDmgModBullet = 1.0;
  this->m_flDmgModClub = 1.0;
  this->m_flDmgModExplosive = 1.0;
  this->m_flDmgModFire = 1.0;
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  ModelIndex = C_BaseEntity::GetModelIndex(this);
  memset(&list, 0, sizeof(list));
  BreakModelList(a1: 0, &list, modelindex: ModelIndex, defBurstScale: 0.0, defCollisionGroup: 0);
  m_Size = list.m_Size;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
  GetModel = this->GetModel;
  this->m_iNumBreakableChunks = m_Size;
  v8 = modelinfo->__vftable;
  v9 = ((int (__thiscall *)(IClientRenderable *, int, int, int))GetModel)(
         a1: &this->IClientRenderable,
         a2: a3,
         a3: a4,
         a4: a2);
  v10 = v8->GetModelKeyValues(this: modelinfo, a2: (const struct model_t *)v9);
  v11 = v10;
  if ( v10 != nullptr )
  {
    Key = KeyValues::FindKey(this: v10, keyName: "prop_data", bCreate: false);
    if ( Key != nullptr )
      CPropData::ParsePropFromKV(
        this: &g_PropDataSystem,
        pProp: this,
        pBreakableInterface: &this->IBreakableWithPropData,
        pSection: Key,
        pInteractionSection: v11);
  }
  if ( this->m_iNumBreakableChunks == 0
    && this->GetBreakableModel(this: &this->IBreakableWithPropData) != nullptr
    && this->GetBreakableCount(this: &this->IBreakableWithPropData) != 0 )
  {
    this->m_iNumBreakableChunks = this->GetBreakableCount(this: &this->IBreakableWithPropData);
  }
  this->m_takedamage = this->m_iHealth != 0 ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x10170650
// Name: public: virtual int C_PhysPropClientside::GetBreakableCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PhysPropClientside::GetBreakableCount(C_PhysPropClientside *this)
{
  return *((_DWORD *)&this->m_VarMap + 7);
}
