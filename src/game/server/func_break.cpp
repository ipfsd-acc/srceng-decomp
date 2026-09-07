// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_break.cpp
// Functions: 52
// ============================================================

#include "game\server\func_break.h"

//------------------------------------------------------------------------------
// Address: 0x101317E0
// Name: public: virtual struct datamap_t __near * CBreakable::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBreakable::GetDataDescMap(CBreakable *this)
{
  return &CBreakable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10131800
// Name: public: bool CBreakable::IsBreakable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBreakable::IsBreakable(CBreakable *this)
{
  return this->m_Material != matUnbreakableGlass;
}

//------------------------------------------------------------------------------
// Address: 0x10131810
// Name: public: virtual char const __near * CBreakable::DamageDecal(int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBreakable::DamageDecal(CBreakable *this, int bitsDamageType, int gameMaterial)
{
  Materials m_Material; // eax

  m_Material = this->m_Material;
  if ( m_Material == matGlass )
    return "GlassBreak";
  if ( m_Material == matUnbreakableGlass )
    return "BulletProof";
  return CBaseEntity::DamageDecal(this, bitsDamageType, gameMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x10131840
// Name: public: virtual void CPushable::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPushable::Use(
        CPushable *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CBaseEntity::Use(this, pActivator, pCaller, useType, value);
}

//------------------------------------------------------------------------------
// Address: 0x10131870
// Name: public: virtual bool CBreakable::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBreakable::KeyValue(CBreakable *this, char *szKeyName, const char *szValue)
{
  Materials v4; // eax
  int v6; // eax
  const char *v7; // eax
  int v8; // eax
  bool v9; // zf
  const char *v10; // eax

  if ( szKeyName == "material" || _V_stricmp(s1: szKeyName, s2: "material") == 0 )
  {
    v4 = atoi(nptr: szValue);
    if ( (unsigned int)v4 > matNone )
      this->m_Material = matWood;
    else
      this->m_Material = v4;
    return true;
  }
  if ( szKeyName == "deadmodel"
    || _V_stricmp(s1: szKeyName, s2: "deadmodel") == 0
    || szKeyName == "shards"
    || _V_stricmp(s1: szKeyName, s2: "shards") == 0 )
  {
    return true;
  }
  if ( szKeyName == "gibmodel" || _V_stricmp(s1: szKeyName, s2: "gibmodel") == 0 )
  {
    this->m_iszGibModel.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szValue).pszValue;
    return true;
  }
  if ( szKeyName == "spawnobject" || _V_stricmp(s1: szKeyName, s2: "spawnobject") == 0 )
  {
    v6 = atoi(nptr: szValue);
    if ( v6 > 0 && (unsigned int)v6 < 0x1B )
    {
      v7 = CBreakable::pSpawnObjects[v6];
      if ( v7 == nullptr || *v7 == 0 )
        v7 = nullptr;
      this->m_iszSpawnObject.pszValue = v7;
      return true;
    }
    return true;
  }
  if ( !FStrEq(sz1: szKeyName, sz2: "propdata") )
  {
    if ( !FStrEq(sz1: szKeyName, sz2: "lip") )
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    return true;
  }
  v8 = atoi(nptr: szValue);
  v9 = v8 == 0;
  if ( v8 <= 0 )
  {
LABEL_30:
    if ( !v9 )
    {
      _Warning(a1: "func_breakable with invalid propdata %d.\n", v8);
      return true;
    }
    return true;
  }
  if ( (unsigned int)v8 >= 0x19 )
  {
    v9 = v8 == 0;
    goto LABEL_30;
  }
  v10 = pFGDPropData[v8];
  if ( v10 == nullptr || *v10 == 0 )
    v10 = nullptr;
  this->m_iszPropData.pszValue = v10;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10131A30
// Name: public: void CBreakable::ParsePropData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::ParsePropData(CBreakable *this)
{
  const char *pszValue; // eax
  const char *v3; // eax

  pszValue = this->m_iszPropData.pszValue;
  if ( pszValue != nullptr && V_strncmp(s1: pszValue, s2: "None", count: 4) != 0 )
  {
    v3 = this->m_iszPropData.pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    CPropData::ParsePropFromBase(
      this: &g_PropDataSystem,
      pProp: this,
      pBreakableInterface: &this->IBreakableWithPropData,
      pszPropData: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131A80
// Name: public: virtual void CBreakable::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBreakable::Precache(CBreakable *this@<ecx>, int a2@<ebp>)
{
  const char *v3; // eax
  const char *pszValue; // edi
  const char *DebugName; // eax
  ICommandLine *v6; // eax
  const char *v7; // esi
  unsigned int i; // esi
  int v9; // eax
  double x; // [esp+0h] [ebp-20h]
  double y; // [esp+8h] [ebp-18h]
  double z; // [esp+10h] [ebp-10h]

  switch ( this->m_Material )
  {
    case matGlass:
    case matUnbreakableGlass:
      v3 = "GlassChunks";
      break;
    case matWood:
      goto $LN16_5;
    case matMetal:
      v3 = "MetalChunks";
      break;
    case matCinderBlock:
    case matRocks:
      v3 = "ConcreteChunks";
      break;
    case matMetalPanel:
      v3 = "MetalPanelChunks";
      break;
    default:
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2);
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      z = this->m_vecAbsOrigin.z;
      y = this->m_vecAbsOrigin.y;
      x = this->m_vecAbsOrigin.x;
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(
        a1: "%s (%s) at (%.3f %.3f %.3f) using obsolete or unknown material type.\n",
        pszValue,
        DebugName,
        x,
        y,
        z);
$LN16_5:
      v3 = "WoodChunks";
      break;
  }
  if ( this->m_iszGibModel.pszValue != nullptr && (v3 = this->m_iszGibModel.pszValue) == nullptr
    || v3 == nullptr
    || *v3 == 0 )
  {
    v3 = nullptr;
  }
  this->m_iszModelName.pszValue = v3;
  v6 = _CommandLine((CResponseRulesToEngineInterface *)this);
  if ( v6->CheckParm(this: v6, a2: "-makereslists", a3: nullptr) != nullptr )
  {
    for ( i = 0; i < 27; ++i )
    {
      if ( CBreakable::pSpawnObjects[i] != nullptr )
      {
        v9 = _V_strlen(str: "unused");
        if ( V_strnicmp(s1: CBreakable::pSpawnObjects[i], s2: "unused", n: v9) != 0 )
          UTIL_PrecacheOther(szClassname: CBreakable::pSpawnObjects[i], modelName: nullptr);
      }
    }
  }
  else if ( this->m_iszSpawnObject.pszValue != nullptr )
  {
    v7 = this->m_iszSpawnObject.pszValue;
    if ( v7 == nullptr )
      v7 = locale;
    UTIL_PrecacheOther(szClassname: v7, modelName: nullptr);
  }
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.MatGlass");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.MatWood");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.MatMetal");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.MatFlesh");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.MatConcrete");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.Computer");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.Crate");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.Glass");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.Metal");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.Flesh");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.Concrete");
  CBaseEntity::PrecacheScriptSound(soundname: "Breakable.Ceiling");
}

//------------------------------------------------------------------------------
// Address: 0x10131CB0
// Name: public: void CBreakable::Break(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::Break(CBreakable *this, CBaseEntity *pBreaker)
{
  if ( this->m_Material != matUnbreakableGlass )
  {
    if ( pBreaker != nullptr )
      this->m_hBreaker.m_Index = pBreaker->GetRefEHandle(this: pBreaker)->m_Index;
    else
      this->m_hBreaker.m_Index = -1;
    this->Die(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131D10
// Name: public: virtual void CBreakable::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::TraceAttack(
        CBreakable *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  float v5[3]; // [esp+2Ch] [ebp-Ch] BYREF

  if ( random->RandomInt(this: random, a2: 0, a3: 1) != 0 )
  {
    if ( this->m_Material == matComputer )
    {
      g_pEffects->Sparks(this: g_pEffects, a2: &ptr->endpos, a3: 1, a4: 1, a5: nullptr);
      CBaseEntity::EmitSound(this, soundname: "Breakable.Computer", soundtime: 0.0, duration: nullptr);
    }
    else if ( this->m_Material == matUnbreakableGlass )
    {
      v5[0] = vecDir->x * -1.0;
      v5[1] = vecDir->y * -1.0;
      v5[2] = vecDir->z * -1.0;
      g_pEffects->Ricochet(this: g_pEffects, a2: &ptr->endpos, a3: (const Vector *)v5);
    }
  }
  CBaseEntity::TraceAttack(this, info, vecDir, ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10131DE0
// Name: public: virtual bool CPushable::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPushable::CreateVPhysics(CPushable *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  CBaseEntity::VPhysicsInitNormal(this, solidType: SOLID_VPHYSICS, nSolidFlags: 0, createAsleep: false, pSolid: nullptr);
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    ((void (__stdcall *)(int))m_pPhysicsObject->SetMass)(a1: 1106247680);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10131E30
// Name: public: void CBreakable::InputBreak(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::InputBreak(CBreakable *this, inputdata_t *inputdata)
{
  bool v3; // zf
  CBaseEntity *pActivator; // ecx

  v3 = this->m_Material == matUnbreakableGlass;
  pActivator = inputdata->pActivator;
  if ( !v3 )
  {
    if ( pActivator != nullptr )
      this->m_hBreaker.m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
    else
      this->m_hBreaker.m_Index = -1;
    this->Die(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131E90
// Name: public: void CBreakable::InputSetMass(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::InputSetMass(CBreakable *this, inputdata_t *inputdata)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  const char *pszValue; // eax

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    if ( inputdata->value.fieldType == FIELD_FLOAT )
      ((void (__stdcall *)(int))m_pPhysicsObject->SetMass)(a1: inputdata->value.iVal);
    else
      ((void (__stdcall *)(_DWORD))m_pPhysicsObject->SetMass)(a1: 0);
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "Tried to call SetMass() on %s but it has no physics.\n", pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131F00
// Name: public: virtual void CBreakable::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::VPhysicsCollision(CBreakable *this, float index, int pEvent)
{
  gamevcollisionevent_t *v3; // esi
  int v4; // edi
  double v6; // st7
  double v7; // st6
  IPhysicsObject *v8; // ecx
  IPhysicsObject_vtbl *v9; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  bool v12; // zf
  gamevcollisionevent_t *v13; // eax
  string_t (__thiscall *GetPhysicsDamageTable)(IBreakableWithPropData *); // edx
  string_t *v15; // eax
  double v16; // st7
  CTakeDamageInfo dmgInfo; // [esp+2Ch] [ebp-78h] BYREF
  Vector damagePos; // [esp+88h] [ebp-1Ch] BYREF
  Vector damageForce; // [esp+94h] [ebp-10h] BYREF
  CBaseEntity *pOther; // [esp+A0h] [ebp-4h]

  v3 = (gamevcollisionevent_t *)pEvent;
  v4 = LODWORD(index);
  CBaseEntity::VPhysicsCollision(this, index: (surfacedata_t *)LODWORD(index), (CBaseEntity *)pEvent);
  v3->pInternalData->GetContactPoint(this: v3->pInternalData, a2: &damagePos);
  v6 = ((double (__thiscall *)(IPhysicsObject *))v3->pObjects[v4]->GetMass)(a1: v3->pObjects[v4]);
  *(float *)&pEvent = v6;
  v7 = v3->postVelocity[v4].y * v6;
  damageForce.x = *(float *)&pEvent * v3->postVelocity[v4].x;
  damageForce.y = v7;
  damageForce.z = v6 * v3->postVelocity[v4].z;
  if ( vec3_origin.x == damageForce.x && vec3_origin.y == damageForce.y && vec3_origin.z == damageForce.z )
  {
    v8 = v3->pObjects[v4 == 0];
    v9 = v8->__vftable;
    pEvent = v4 == 0;
    index = v9->GetMass(this: v8);
    v10 = v3->postVelocity[pEvent].y * index;
    v11 = v3->postVelocity[pEvent].z * index;
    damageForce.x = v3->postVelocity[pEvent].x * index;
    damageForce.y = v10;
    damageForce.z = v11;
  }
  if ( (this->m_spawnflags.m_Value & 0x200) != 0 )
  {
    v12 = this->m_Material == matGlass;
    this->m_bTookPhysicsDamage = true;
    v13 = (gamevcollisionevent_t *)v3->pEntities[v4 == 0];
    pEvent = (int)v13;
    if ( v12 )
    {
      ((void (__stdcall *)(int))v3->pObjects[v4]->SetMass)(a1: 0x40000000);
      v13 = (gamevcollisionevent_t *)pEvent;
    }
    CTakeDamageInfo::CTakeDamageInfo(
      this: &dmgInfo,
      pInflictor: (CBaseEntity *)v13,
      pAttacker: (CBaseEntity *)v13,
      &damageForce,
      damagePosition: &damagePos,
      flDamage: (float)(this->m_iHealth.m_Value + 1),
      bitsDamageType: 1,
      iKillType: 0,
      reportedPosition: nullptr,
      iObjectsPenetrated: 0);
    PhysCallbackDamage(pEntity: this, info: &dmgInfo, event: v3, hurtIndex: v4);
  }
  else if ( (this->m_spawnflags.m_Value & 0x400) == 0 )
  {
    GetPhysicsDamageTable = this->GetPhysicsDamageTable;
    pOther = v3->pEntities[v4 == 0];
    v15 = (string_t *)((int (__thiscall *)(IBreakableWithPropData *, float *))GetPhysicsDamageTable)(
                        a1: &this->IBreakableWithPropData,
                        a2: &index);
    v16 = CalculateDefaultPhysicsDamage(
            index: v4,
            pEvent: v3,
            energyScale: this->m_impactEnergyScale,
            allowStaticDamage: true,
            damageType: &pEvent,
            iszDamageTableName: (string_t)v15->pszValue,
            bDamageFromHeldObjects: false);
    index = v16;
    if ( v16 > 0.0 )
    {
      if ( this->m_Material == matGlass )
        ((void (__stdcall *)(int))v3->pObjects[v4]->SetMass)(a1: 0x40000000);
      CTakeDamageInfo::CTakeDamageInfo(
        this: &dmgInfo,
        pInflictor: pOther,
        pAttacker: pOther,
        &damageForce,
        damagePosition: &damagePos,
        flDamage: index,
        bitsDamageType: pEvent,
        iKillType: 0,
        reportedPosition: nullptr,
        iObjectsPenetrated: 0);
      PhysCallbackDamage(pEntity: this, info: &dmgInfo, event: v3, hurtIndex: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132140
// Name: public: void CBreakable::ResetOnGroundFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::ResetOnGroundFlags(CBreakable *this)
{
  int v1; // eax
  int v2; // edi
  int v3; // esi
  CBaseEntity *pList[256]; // [esp+4h] [ebp-42Ch] BYREF
  CFlaggedEntitiesEnum pEnum; // [esp+404h] [ebp-2Ch] BYREF
  Vector maxs; // [esp+418h] [ebp-18h] BYREF
  Vector mins; // [esp+424h] [ebp-Ch] BYREF

  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &mins,
    pWorldMaxs: &maxs);
  mins.z = mins.z - 1.0;
  maxs.z = maxs.z + 8.0;
  CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &pEnum, pList, listMax: 256, flagMask: 1);
  v1 = UTIL_EntitiesInBox(&mins, &maxs, &pEnum);
  v2 = v1;
  if ( v1 != 0 )
  {
    v3 = 0;
    if ( v1 > 0 )
    {
      do
        CBaseEntity::SetGroundEntity(this: pList[v3++], ground: nullptr);
      while ( v3 < v2 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101321E0
// Name: public: virtual int CBreakable::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBreakable::DrawDebugTextOverlays(CBreakable *this)
{
  int result; // eax
  int v3; // edi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    if ( this->GetMaxHealth(this) != 0 )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Health: %i", this->m_iHealth.m_Value);
      CBaseEntity::EntityText(this, text_offset: v3++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    if ( this->m_iszBasePropData.pszValue != nullptr )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Base PropData: %s", this->m_iszBasePropData.pszValue);
      CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      return v3 + 1;
    }
    else
    {
      return v3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101322C0
// Name: public: virtual void CPushable::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPushable::VPhysicsCollision(CPushable *this, surfacedata_t *index, CBaseEntity *pEvent)
{
  CBaseEntity *v4; // ecx

  v4 = *((CBaseEntity **)&pEvent->m_flSimulationTime.m_Value + (index == nullptr));
  if ( v4->IsPlayer(this: v4) )
    CBaseEntity::VPhysicsCollision(this, index, pEvent);
  else
    CBreakable::VPhysicsCollision(this, index: *(float *)&index, (int)pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10132310
// Name: public: virtual void CBreakable::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::OnPhysGunPickup(CBreakable *this, CBasePlayer *pPhysGunUser, PhysGunDrop_t reason)
{
  if ( pPhysGunUser != nullptr )
    this->m_fEffects.m_Value = pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    this->m_fEffects.m_Value = -1;
  *(float *)&this->m_ModelName.pszValue = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10132360
// Name: public: virtual class CBasePlayer __near * CBreakable::HasPhysicsAttacker(float)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CBreakable::HasPhysicsAttacker(CBreakable *this, float dt)
{
  unsigned int m_Index; // ecx

  if ( this->m_flLastPhysicsInfluenceTime < (float)(gpGlobals->curtime - dt) )
    return nullptr;
  m_Index = this->m_hPhysicsAttacker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101323C0
// Name: public: CBreakable::CBreakable(void)
// Source: json
//------------------------------------------------------------------------------
CBreakable *__thiscall CBreakable::CBreakable(CBreakable *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&IBreakableWithPropData::`vftable';
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  this->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBreakable_vtbl *)&CBreakable::`vftable'{for `CBaseEntity'};
  this->IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CBreakable::`vftable'{for `IBreakableWithPropData'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CBreakable::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_hBreaker.m_Index = -1;
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_OnHealthChanged.m_Value.iVal = 0;
  this->m_OnHealthChanged.m_Value.eVal.m_Index = -1;
  this->m_OnHealthChanged.m_Value.fieldType = FIELD_VOID;
  this->m_hPhysicsAttacker.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10132440
// Name: public: virtual void CBreakable::SetDmgModBullet(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetDmgModBullet(CBreakable *this, thinkfunc_t *flDmgMod)
{
  this->m_aThinkFunctions.m_Memory.m_pMemory = flDmgMod;
}

//------------------------------------------------------------------------------
// Address: 0x10132460
// Name: public: virtual float CBreakable::GetDmgModBullet(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakable::GetDmgModBullet(CBreakable *this)
{
  return *(float *)&this->m_aThinkFunctions.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10132490
// Name: public: virtual void CBreakable::SetExplosiveDamage(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetExplosiveDamage(CBreakable *this, float flDamage)
{
  LODWORD(this->m_Network.m_PVSInfo.m_vCenter[0]) = (int)flDamage;
}

//------------------------------------------------------------------------------
// Address: 0x101324B0
// Name: public: virtual float CBreakable::GetExplosiveDamage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakable::GetExplosiveDamage(CBreakable *this)
{
  return (double)SLODWORD(this->m_Network.m_PVSInfo.m_vCenter[0]);
}

//------------------------------------------------------------------------------
// Address: 0x101324C0
// Name: public: virtual void CBreakable::SetPhysicsDamageTable(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetPhysicsDamageTable(CBreakable *this, string_t iszTableName)
{
  this->m_aThinkFunctions.m_pElements = (thinkfunc_t *)iszTableName.pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x101324D0
// Name: public: virtual struct string_t CBreakable::GetPhysicsDamageTable(void)
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CBreakable::GetPhysicsDamageTable(CBreakable *this, thinkfunc_t **a2)
{
  *a2 = this->m_aThinkFunctions.m_pElements;
  return (string_t)a2;
}

//------------------------------------------------------------------------------
// Address: 0x101324F0
// Name: public: virtual void CBreakable::SetBreakableModel(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetBreakableModel(CBreakable *this, string_t iszModel)
{
  this->m_ResponseContexts.m_Memory.m_pMemory = (ResponseContext_t *)iszModel.pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x10132520
// Name: public: virtual void CBreakable::SetBreakableSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetBreakableSkin(vgui::Panel *this, Color color)
{
  this->_fgColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x10132530
// Name: public: virtual int CBreakable::GetBreakableSkin(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBreakable::GetBreakableSkin(CBreakable *this)
{
  return this->m_ResponseContexts.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x10132540
// Name: public: virtual void CBreakable::SetBreakableCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetBreakableCount(vgui::Panel *this, Color color)
{
  this->_bgColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x10132560
// Name: public: virtual int CBreakable::GetMaxBreakableSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBreakable::GetMaxBreakableSize(CAI_Navigator *this)
{
  return this->m_nNavFailCounter;
}

//------------------------------------------------------------------------------
// Address: 0x10132570
// Name: public: virtual void CBreakable::SetPropDataBlocksLOS(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetPropDataBlocksLOS(CBreakable *this, bool bBlocksLOS)
{
  CBaseEntity::SetBlocksLOS(this: (CBreakable *)((char *)this - 852), bBlocksLOS);
}

//------------------------------------------------------------------------------
// Address: 0x10132580
// Name: public: virtual void CBreakable::SetPropDataIsAIWalkable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetPropDataIsAIWalkable(CBreakable *this, bool bBlocksLOS)
{
  CBaseEntity::SetAIWalkable(this: (CBreakable *)((char *)this - 852), bBlocksLOS);
}

//------------------------------------------------------------------------------
// Address: 0x101325A0
// Name: public: virtual struct string_t CBreakable::GetBasePropData(void)
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CBreakable::GetBasePropData(CBreakable *this, ResponseContext_t **a2)
{
  *a2 = this->m_ResponseContexts.m_pElements;
  return (string_t)a2;
}

//------------------------------------------------------------------------------
// Address: 0x101325C0
// Name: public: virtual void CBreakable::SetInteraction(enum propdata_interactions_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetInteraction(CBreakable *this, propdata_interactions_t Interaction)
{
  this->m_iszResponseContext.pszValue = (const char *)((int)this->m_iszResponseContext.pszValue | (1 << Interaction));
}

//------------------------------------------------------------------------------
// Address: 0x101325E0
// Name: public: virtual bool CBreakable::HasInteraction(enum propdata_interactions_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBreakable::HasInteraction(CBreakable *this, propdata_interactions_t Interaction)
{
  return ((1 << Interaction) & (int)this->m_iszResponseContext.pszValue) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10132600
// Name: public: virtual int CPushable::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPushable::ObjectCaps(CPushable *this)
{
  return CBaseEntity::ObjectCaps(this) | 4;
}

//------------------------------------------------------------------------------
// Address: 0x10132610
// Name: protected: bool CBreakable::UpdateHealth(int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBreakable::UpdateHealth(CBreakable *this, int iNewHealth, CBaseEntity *pActivator)
{
  int v3; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // ebx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iMaxHealth> *p_m_iMaxHealth; // esi
  float v7; // xmm0_4
  int v8; // xmm1_4
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi

  v3 = iNewHealth;
  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value != iNewHealth )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = v3;
    p_m_iMaxHealth = &this->m_iMaxHealth;
    if ( this->m_iMaxHealth.m_Value == 0 && p_m_iMaxHealth->m_Value != 1 )
    {
      this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
      p_m_iMaxHealth->m_Value = 1;
    }
    v7 = (float)p_m_iHealth->m_Value / (float)p_m_iMaxHealth->m_Value;
    v8 = 0;
    if ( v7 < 0.0 || (v8 = 1065353216, v7 > 1.0) )
      v7 = *(float *)&v8;
    iNewHealth = LODWORD(v7);
    variant_t::Set(
      this: &this->m_OnHealthChanged.m_Value,
      ftype: FIELD_FLOAT,
      data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&iNewHealth);
    CBaseEntityOutput::FireOutput(
      this: &this->m_OnHealthChanged,
      Value: this->m_OnHealthChanged.m_Value,
      pActivator,
      pCaller: this,
      fDelay: 0.0);
    if ( p_m_iHealth->m_Value <= 0 )
    {
      CBreakable::Break(this, pBreaker: pActivator);
      return 0;
    }
    p_m_takedamage = &this->m_takedamage;
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      if ( p_m_takedamage->m_Value != 0 )
      {
        this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
        p_m_takedamage->m_Value = 0;
        return 1;
      }
    }
    else if ( p_m_takedamage->m_Value != 2 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      p_m_takedamage->m_Value = 2;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10132800
// Name: public: void CBreakable::InputAddHealth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::InputAddHealth(CBreakable *this, inputdata_t *inputdata)
{
  const char *pszValue; // edx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  CBreakable::UpdateHealth(this, iNewHealth: (int)&pszValue[this->m_iHealth.m_Value], pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x10132830
// Name: public: void CBreakable::InputRemoveHealth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::InputRemoveHealth(CBreakable *this, inputdata_t *inputdata)
{
  const char *pszValue; // edx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  CBreakable::UpdateHealth(
    this,
    iNewHealth: this->m_iHealth.m_Value - (_DWORD)pszValue,
    pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x10132860
// Name: public: void CBreakable::InputSetHealth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::InputSetHealth(CBreakable *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    CBreakable::UpdateHealth(this, iNewHealth: inputdata->value.iVal, pActivator: inputdata->pActivator);
  else
    CBreakable::UpdateHealth(this, iNewHealth: 0, pActivator: inputdata->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x101328F0
// Name: public: static void CBreakable::MaterialSoundRandom(int,enum Materials,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBreakable::MaterialSoundRandom(int entindex, Materials soundMaterial, float volume)
{
  const char *v3; // eax
  CBaseEntity *v4; // eax
  soundlevel_t soundlevel; // [esp-10h] [ebp-12Ch]
  CPASAttenuationFilter filter; // [esp+0h] [ebp-11Ch] BYREF
  CSoundParameters params; // [esp+20h] [ebp-FCh] BYREF
  EmitSound_t ep; // [esp+D4h] [ebp-48h] BYREF

  switch ( soundMaterial )
  {
    case matGlass:
    case matUnbreakableGlass:
      v3 = "Breakable.MatGlass";
      goto LABEL_8;
    case matWood:
      v3 = "Breakable.MatWood";
      goto LABEL_8;
    case matMetal:
    case matMetalPanel:
      v3 = "Breakable.MatMetal";
      goto LABEL_8;
    case matFlesh:
      v3 = "Breakable.MatFlesh";
      goto LABEL_8;
    case matCinderBlock:
    case matRocks:
      v3 = "Breakable.MatConcrete";
      goto LABEL_8;
    case matComputer:
      v3 = "Breakable.Computer";
LABEL_8:
      params.channel = 0;
      params.volume = 1.0;
      params.pitch = 100;
      params.pitchlow = 100;
      params.pitchhigh = 100;
      params.soundlevel = SNDLVL_NORM;
      params.soundname[0] = 0;
      params.play_to_owner_only = false;
      params.count = 0;
      params.delay_msec = 0;
      params.m_nSoundEntryVersion = 1;
      params.m_hSoundScriptHandle = -1;
      params.m_pOperatorsKV = nullptr;
      params.m_nRandomSeed = -1;
      if ( CBaseEntity::GetParametersForSound(soundname: v3, &params, actormodel: nullptr) )
      {
        soundlevel = params.soundlevel;
        v4 = CBaseEntity::Instance(iEnt: entindex);
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v4, soundlevel);
        ep.m_nChannel = params.channel;
        ep.m_pSoundName = params.soundname;
        ep.m_hSoundScriptHandle = -1;
        ep.m_nFlags = 0;
        ep.m_nPitch = 100;
        memset(&ep.m_pOrigin, 0, 12);
        *(_WORD *)&ep.m_bEmitCloseCaption = 1;
        ep.m_bWarnOnDirectWaveReference = false;
        ep.m_nSpeakerEntity = -1;
        memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
        ep.m_nSoundEntryVersion = 1;
        ep.m_flVolume = volume;
        ep.m_SoundLevel = params.soundlevel;
        CBaseEntity::EmitSound(&filter, iEntIndex: entindex, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132A90
// Name: public: void CBreakable::DamageSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::DamageSound(CBreakable *this)
{
  Materials m_Material; // edi
  const char *v3; // eax
  edict_t *m_pPev; // eax
  signed int v5; // eax
  CPASAttenuationFilter filter; // [esp+28h] [ebp-124h] BYREF
  CSoundParameters params; // [esp+48h] [ebp-104h] BYREF
  EmitSound_t ep; // [esp+FCh] [ebp-50h] BYREF
  float fvol; // [esp+144h] [ebp-8h]
  int pitch; // [esp+148h] [ebp-4h]

  m_Material = this->m_Material;
  if ( random->RandomInt(this: random, a2: 0, a3: 2) != 0 )
    pitch = 100;
  else
    pitch = random->RandomInt(this: random, a2: 0, a3: 34) + 95;
  fvol = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: 1061158912,
           a3: 1065353216);
  if ( m_Material == matComputer && random->RandomInt(this: random, a2: 0, a3: 1) != 0 )
    m_Material = matMetal;
  switch ( m_Material )
  {
    case matGlass:
    case matUnbreakableGlass:
      v3 = "Breakable.MatGlass";
      goto LABEL_13;
    case matWood:
      v3 = "Breakable.MatWood";
      goto LABEL_13;
    case matMetal:
    case matMetalPanel:
      v3 = "Breakable.MatMetal";
      goto LABEL_13;
    case matCinderBlock:
    case matRocks:
      v3 = "Breakable.MatConcrete";
      goto LABEL_13;
    case matComputer:
      v3 = "Breakable.Computer";
LABEL_13:
      params.pitch = 100;
      params.pitchlow = 100;
      params.pitchhigh = 100;
      params.channel = 0;
      params.volume = 1.0;
      params.soundlevel = SNDLVL_NORM;
      params.soundname[0] = 0;
      params.play_to_owner_only = false;
      params.count = 0;
      params.delay_msec = 0;
      params.m_nSoundEntryVersion = 1;
      params.m_hSoundScriptHandle = -1;
      params.m_pOperatorsKV = nullptr;
      params.m_nRandomSeed = -1;
      if ( CBaseEntity::GetParametersForSound(soundname: v3, &params, actormodel: nullptr) )
      {
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
        ep.m_nChannel = params.channel;
        ep.m_nPitch = pitch;
        m_pPev = this->m_Network.m_pPev;
        ep.m_nFlags = 0;
        memset(&ep.m_pOrigin, 0, 12);
        *(_WORD *)&ep.m_bEmitCloseCaption = 1;
        ep.m_bWarnOnDirectWaveReference = false;
        ep.m_nSpeakerEntity = -1;
        memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
        ep.m_hSoundScriptHandle = -1;
        ep.m_nSoundEntryVersion = 1;
        ep.m_pSoundName = params.soundname;
        ep.m_flVolume = fvol;
        ep.m_SoundLevel = params.soundlevel;
        if ( m_pPev != nullptr )
          v5 = m_pPev - gpGlobals->pEdicts;
        else
          v5 = 0;
        CBaseEntity::EmitSound(&filter, iEntIndex: v5, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132CC0
// Name: public: void CBreakable::BreakTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CBreakable::BreakTouch(
        CBreakable *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseEntity *pOther)
{
  Vector *v6; // eax
  __m128i v7; // xmm1
  __int128 v8; // xmm0
  float v9; // xmm0_4
  CBreakable_vtbl *v10; // ecx
  CTakeDamageInfo *v11; // eax
  float m_flPressureDelay; // xmm0_4
  CTakeDamageInfo v14; // [esp+30h] [ebp-E8h] BYREF
  _BYTE v15[12]; // [esp+8Ch] [ebp-8Ch] BYREF
  __int128 info_84; // [esp+ECh] [ebp-2Ch] OVERLAPPED BYREF
  int v17; // [esp+FCh] [ebp-1Ch]
  int thinkTime; // [esp+100h] [ebp-18h]
  CBreakable_vtbl *flScale; // [esp+104h] [ebp-14h]
  float v20; // [esp+108h] [ebp-10h]
  _DWORD v21[2]; // [esp+10Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+118h] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, int, int))pOther->IsPlayer)(a1: pOther, a2: a3, a3: a4) != 0
    && this->m_Material != matUnbreakableGlass )
  {
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
    {
      v6 = pOther->GetSmoothedVelocity(this: pOther, result: (char *)&info_84 + 4);
      v7 = _mm_cvtsi32_si128(this->m_iHealth.m_Value);
      v8 = 0;
      *(float *)&v8 = fsqrt((float)((float)(v6->x * v6->x) + (float)(v6->y * v6->y)) + (float)(v6->z * v6->z));
      info_84 = v8;
      v9 = *(float *)&v8 * 0.01;
      v20 = v9;
      if ( v9 >= _mm_cvtepi32_ps(v7).m128_f32[0] )
      {
        if ( this->m_takedamage.m_Value != 2 )
        {
          this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
          v9 = v20;
          this->m_takedamage.m_Value = 2;
        }
        v10 = this->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        thinkTime = 0;
        v17 = 1;
        *((_QWORD *)&info_84 + 1) = __PAIR64__(LODWORD(v9), (unsigned int)pOther);
        flScale = v10;
        DWORD1(info_84) = pOther;
        this->m_pfnTouch = nullptr;
        v11 = CTakeDamageInfo::CTakeDamageInfo(
                this: &v14,
                pInflictor: (CBaseEntity *)DWORD1(info_84),
                pAttacker: (CBaseEntity *)DWORD2(info_84),
                flDamage: *((float *)&info_84 + 3),
                bitsDamageType: v17,
                iKillType: thinkTime,
                iObjectsPenetrated: (int)flScale);
        flScale->OnTakeDamage(this, a2: v11);
        CTakeDamageInfo::CTakeDamageInfo(
          this: (CTakeDamageInfo *)v15,
          pInflictor: pOther,
          pAttacker: pOther,
          flDamage: v20 * 0.25,
          bitsDamageType: 4,
          iKillType: 0,
          iObjectsPenetrated: 0);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v21);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v21);
        if ( (pOther->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: pOther, a2: (int)v21);
        *((float *)&info_84 + 1) = pOther->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
        *((float *)&info_84 + 2) = pOther->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
        CalculateMeleeDamageForce(
          info: (CTakeDamageInfo *)v15,
          vecMeleeDir: (const Vector *)((char *)&info_84 + 4),
          vecForceOrigin: &this->m_vecAbsOrigin,
          flScale: 1.0);
        CBaseEntity::TakeDamage(this: pOther, a2: (int)this, inputInfo: (const CTakeDamageInfo *)v15);
      }
    }
    if ( (this->m_spawnflags.m_Value & 4) != 0 && CBaseEntity::GetGroundEntity(this: pOther) == this )
    {
      CBreakable::DamageSound(this);
      CHandle<CBaseEntity>::operator=(this: &this->m_hBreaker, val: pOther);
      CBaseEntity::ThinkSet(
        this,
        func:  __thiscall CAI_BattleLine::`vcall'{776,{flat}},
        thinkTime: 0.0,
        szContext: nullptr);
      m_flPressureDelay = this->m_flPressureDelay;
      this->m_pfnTouch = nullptr;
      CBaseEntity::SetNextThink(this, thinkTime: m_flPressureDelay + gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132F30
// Name: public: virtual int CBreakable::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBreakable::OnTakeDamage(CBreakable *this, const CTakeDamageInfo *info)
{
  CBaseEntity *m_pEntity; // eax
  int m_Value; // ebx
  CBaseEntity *Attacker; // eax
  CTakeDamageInfo subInfo; // [esp+8h] [ebp-60h] BYREF
  int iNewHealth; // [esp+64h] [ebp-4h]
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  CTakeDamageInfo::CTakeDamageInfo(this: &subInfo, __that: info);
  if ( this->m_takedamage.m_Value == 0 || (float)this->m_iMinHealthDmg > info->m_flDamage )
    return 0;
  if ( !this->PassesDamageFilter(this, a2: &subInfo) )
  {
    this->m_bTookPhysicsDamage = false;
    return 1;
  }
  if ( subInfo.m_hInflictor.m_Index == -1
    || g_pEntityList->m_EntPtrArray[LOWORD(subInfo.m_hInflictor.m_Index)].m_SerialNumber != HIWORD(subInfo.m_hInflictor.m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(subInfo.m_hInflictor.m_Index)].m_pEntity;
  }
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
  this->WorldSpaceCenter(this);
  if ( this->m_Material == matUnbreakableGlass )
    return 0;
  subInfo.m_flDamage = GetBreakableDamage(inputInfo: &subInfo, pProp: &this->IBreakableWithPropData);
  m_Value = this->m_iHealth.m_Value;
  CBaseEntity::OnTakeDamage(this, info: &subInfo);
  iNewHealth = this->m_iHealth.m_Value;
  if ( iNewHealth != m_Value )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = m_Value;
  }
  Attacker = CTakeDamageInfo::GetAttacker(this: info);
  if ( CBreakable::UpdateHealth(this, iNewHealth, pActivator: Attacker) == 0 )
    return 1;
  if ( this->m_takedamage.m_Value == 2 && (subInfo.m_bitsDamageType & 8) == 0 )
    CBreakable::DamageSound(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10133080
// Name: public: virtual void CBreakable::Die(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::Die(CBreakable *this)
{
  CBreakable *v1; // esi
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  int v3; // eax
  double v4; // st7
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *v12; // eax
  IGameEvent *v13; // edi
  CBaseEntity *v14; // eax
  CBasePlayer *v15; // eax
  int v16; // eax
  signed int m_pPev; // eax
  edict_t *v18; // eax
  signed int v19; // eax
  Explosions m_Explosion; // eax
  __int32 v21; // eax
  float v22; // xmm0_4
  CCollisionProperty *p_m_Collision; // edi
  Vector *v24; // eax
  int v25; // ebx
  int m_nValue; // ecx
  PerformanceMode_t m_PerformanceMode; // eax
  int v28; // ebx
  const char *pszValue; // eax
  IVModelInfo_vtbl *v30; // esi
  const char *RandomChunkModel; // eax
  int v32; // eax
  int v33; // ecx
  ITempEntsSystem_vtbl *v34; // esi
  int v35; // eax
  CBaseEdict *v36; // ecx
  unsigned int v37; // eax
  CBaseEntity *m_pEntity; // ecx
  const char *v39; // ebx
  const QAngle *v40; // eax
  const QAngle *v41; // eax
  int v42; // [esp+64h] [ebp-19Ch]
  int v43; // [esp+68h] [ebp-198h]
  CPASAttenuationFilter filter; // [esp+8Ch] [ebp-174h] BYREF
  CSoundParameters params; // [esp+ACh] [ebp-154h] BYREF
  CPVSFilter filter2; // [esp+160h] [ebp-A0h] BYREF
  EmitSound_t ep; // [esp+180h] [ebp-80h] BYREF
  Vector vecSpot; // [esp+1C8h] [ebp-38h] BYREF
  Vector vSize; // [esp+1D4h] [ebp-2Ch] BYREF
  CBreakable *v50; // [esp+1E0h] [ebp-20h]
  Vector vecVelocity; // [esp+1E4h] [ebp-1Ch] BYREF
  int pitch; // [esp+1F0h] [ebp-10h]
  float fvol; // [esp+1F4h] [ebp-Ch]
  const char *soundname; // [esp+1F8h] [ebp-8h]
  char cFlag; // [esp+1FFh] [ebp-1h]

  v1 = this;
  RandomInt = random->RandomInt;
  v50 = this;
  cFlag = 0;
  v3 = RandomInt(this: random, a2: 0, a3: 29);
  pitch = v3 + 95;
  if ( (unsigned int)(v3 - 3) <= 4 )
    pitch = 100;
  v4 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: 1062836634,
         a3: 1065353216)
     + (double)(int)abs32(v1->m_iHealth.m_Value) * 0.01;
  fvol = v4;
  if ( v4 > 1.0 )
    fvol = 1.0;
  switch ( v1->m_Material )
  {
    case matGlass:
      soundname = "Breakable.Glass";
      cFlag = 1;
      goto LABEL_13;
    case matWood:
      soundname = "Breakable.Crate";
      cFlag = 8;
      goto LABEL_13;
    case matMetal:
    case matMetalPanel:
      soundname = "Breakable.Metal";
      cFlag = 2;
      goto LABEL_13;
    case matFlesh:
      soundname = "Breakable.Flesh";
      cFlag = 4;
      goto LABEL_13;
    case matCinderBlock:
    case matRocks:
      soundname = "Breakable.Concrete";
      cFlag = 64;
      goto LABEL_13;
    case matCeilingTile:
      soundname = "Breakable.Ceiling";
      goto LABEL_13;
    case matComputer:
      soundname = "Breakable.Computer";
      cFlag = 2;
LABEL_13:
      m_Index = v1->m_hBreaker.m_Index;
      if ( m_Index != -1 )
      {
        v6 = (unsigned __int16)m_Index;
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v8 = HIWORD(m_Index);
        if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
        {
          v9 = v6;
          v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
          v11 = &g_pEntityList->m_EntPtrArray[v9];
          v12 = v10 ? v11->m_pEntity : nullptr;
          if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v12->__vftable[28].dtr_IHandleEntity)(a1: v12) != 0 )
          {
            v13 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "break_breakable", a3: 0, a4: 0);
            if ( v13 != nullptr )
            {
              v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v1->m_hBreaker);
              v15 = ToBasePlayer(pEntity: v14);
              v16 = engine->GetPlayerUserId(this: engine, a2: v15->m_Network.m_pPev);
              v13->SetInt(this: v13, a2: "userid", a3: v16);
              m_pPev = (signed int)v1->m_Network.m_pPev;
              if ( m_pPev != 0 )
                m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
              v13->SetInt(this: v13, a2: "entindex", a3: m_pPev);
              v13->SetInt(this: v13, a2: "material", a3: cFlag);
              gameeventmanager->FireEvent(this: gameeventmanager, a2: v13, a3: false);
            }
          }
        }
      }
      params.pitch = 100;
      params.pitchlow = 100;
      params.pitchhigh = 100;
      params.channel = 0;
      params.volume = 1.0;
      params.soundlevel = SNDLVL_NORM;
      params.soundname[0] = 0;
      params.play_to_owner_only = false;
      params.count = 0;
      params.delay_msec = 0;
      params.m_nSoundEntryVersion = 1;
      params.m_hSoundScriptHandle = -1;
      params.m_pOperatorsKV = nullptr;
      params.m_nRandomSeed = -1;
      if ( CBaseEntity::GetParametersForSound(soundname, &params, actormodel: nullptr) )
      {
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v1, attenuation: 0.80000001);
        ep.m_hSoundScriptHandle = -1;
        ep.m_SoundLevel = params.soundlevel;
        v18 = v1->m_Network.m_pPev;
        ep.m_nChannel = params.channel;
        ep.m_nFlags = 0;
        memset(&ep.m_pOrigin, 0, 12);
        *(_WORD *)&ep.m_bEmitCloseCaption = 1;
        ep.m_bWarnOnDirectWaveReference = false;
        ep.m_nSpeakerEntity = -1;
        memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
        ep.m_nSoundEntryVersion = 1;
        ep.m_pSoundName = params.soundname;
        ep.m_flVolume = fvol;
        ep.m_nPitch = pitch;
        if ( v18 != nullptr )
          v19 = v18 - gpGlobals->pEdicts;
        else
          v19 = 0;
        CBaseEntity::EmitSound(&filter, iEntIndex: v19, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
      break;
    default:
      break;
  }
  m_Explosion = v1->m_Explosion;
  if ( m_Explosion != expRandom )
  {
    v21 = m_Explosion - 1;
    if ( v21 != 0 )
    {
      if ( v21 == 1 )
      {
        AngleVectors(angles: &v1->m_GibDir, forward: &vecVelocity, right: nullptr, up: nullptr);
        vecVelocity.x = vecVelocity.x * 200.0;
        vecVelocity.y = vecVelocity.y * 200.0;
        vecVelocity.z = vecVelocity.z * 200.0;
      }
      else
      {
        DevMsg(a1: "**ERROR - Unspecified gib dir method in func_breakable!\n");
      }
      goto LABEL_37;
    }
    v22 = g_vecAttackDir.x * -200.0;
    vecVelocity.y = g_vecAttackDir.y * -200.0;
    vecVelocity.z = g_vecAttackDir.z * -200.0;
  }
  else
  {
    v22 = 0.0;
    vecVelocity.y = 0.0;
    vecVelocity.z = 0.0;
  }
  vecVelocity.x = v22;
LABEL_37:
  vecSpot = *v1->WorldSpaceCenter(this: v1);
  CRecipientFilter::CRecipientFilter(this: &filter2);
  filter2.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter2, origin: &vecSpot);
  p_m_Collision = &v1->m_Collision;
  v24 = AllocTempVector();
  v24->x = v1->m_Collision.m_vecMaxs.m_Value.x - v1->m_Collision.m_vecMins.m_Value.x;
  v24->y = v1->m_Collision.m_vecMaxs.m_Value.y - v1->m_Collision.m_vecMins.m_Value.y;
  v24->z = v1->m_Collision.m_vecMaxs.m_Value.z - v1->m_Collision.m_vecMins.m_Value.z;
  vSize = *v24;
  v25 = (int)(float)((float)((float)((float)(vSize.z + vSize.x) * vSize.y) + (float)(vSize.z * vSize.x)) * 0.0023148148);
  soundname = (const char *)v25;
  if ( func_break_max_pieces.m_pParent != nullptr )
    m_nValue = func_break_max_pieces.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( v25 > m_nValue )
  {
    if ( func_break_max_pieces.m_pParent != nullptr )
    {
      soundname = (const char *)func_break_max_pieces.m_pParent->m_Value.m_nValue;
      v25 = (int)soundname;
    }
    else
    {
      soundname = nullptr;
      v25 = 0;
    }
  }
  if ( (breakable_disable_gib_limit.m_pParent == nullptr || breakable_disable_gib_limit.m_pParent->m_Value.m_nValue == 0)
    && v25 != 0 )
  {
    m_PerformanceMode = v1->m_PerformanceMode;
    if ( m_PerformanceMode == PM_NO_GIBS )
    {
      soundname = nullptr;
    }
    else if ( m_PerformanceMode == PM_REDUCED_GIBS )
    {
      soundname = (const char *)(int)(float)((float)v25 * func_break_reduction_factor.m_pParent->m_Value.m_fValue);
      if ( (int)soundname <= 1 )
        soundname = (const char *)1;
    }
  }
  if ( v1->m_iszModelName.pszValue != nullptr )
  {
    v28 = 0;
    if ( (int)soundname > 0 )
    {
      pitch = cFlag;
      do
      {
        pszValue = v1->m_iszModelName.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        v30 = modelinfo->__vftable;
        RandomChunkModel = CPropData::GetRandomChunkModel(
                             this: &g_PropDataSystem,
                             pszBreakableSection: pszValue,
                             iMaxSize: -1);
        v32 = v30->GetModelIndex(this: modelinfo, a2: RandomChunkModel);
        v33 = 0;
        if ( v28 != 0 )
          v33 = 128;
        v34 = te->__vftable;
        v35 = ((int (__thiscall *)(CCollisionProperty *, Vector *, Vector *, int, int, int, int, int))p_m_Collision->GetCollisionAngles)(
                a1: p_m_Collision,
                a2: &vSize,
                a3: &vecVelocity,
                a4: v32,
                a5: 100,
                a6: 1,
                a7: 1075838976,
                a8: pitch | v33);
        ((void (__thiscall *)(ITempEntsSystem *, CPVSFilter *, _DWORD, Vector *, int))v34->BreakModel)(
          a1: te,
          a2: &filter2,
          a3: 0,
          a4: &vecSpot,
          a5: v35);
        v1 = v50;
        ++v28;
      }
      while ( v28 < (int)soundname );
    }
  }
  CBreakable::ResetOnGroundFlags(this: v1);
  if ( v1->m_iName.m_Value.pszValue != nullptr )
  {
    if ( v1->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v1->m_Network + 76) |= 1u;
    }
    else
    {
      v36 = &v1->m_Network.m_pPev->CBaseEdict;
      if ( v36 != nullptr )
        CBaseEdict::StateChanged(this: v36, offset: 0xCCu);
    }
    v1->m_iName.m_Value.pszValue = nullptr;
  }
  CGlobalEntityList::UpdateName(this: &gEntList, pEnt: v1);
  CCollisionProperty::SetSolidFlags(this: p_m_Collision, flags: p_m_Collision->m_usSolidFlags.m_Value | 4);
  v37 = v1->m_hBreaker.m_Index;
  if ( v37 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v37].m_SerialNumber != HIWORD(v37) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v37].m_pEntity;
  COutputEvent::FireOutput(this: &v1->m_OnBreak, pActivator: m_pEntity, pCaller: v1, fDelay: 0.0);
  v1->VPhysicsDestroyObject(this: v1);
  CBaseEntity::ThinkSet(this: v1, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this: v1, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  v39 = v1->m_iszSpawnObject.pszValue;
  if ( v39 != nullptr )
  {
    v40 = p_m_Collision->GetCollisionAngles(this: p_m_Collision);
    CBaseEntity::Create(szName: v39, vecOrigin: &vecSpot, vecAngles: v40, pOwner: v1);
  }
  if ( ((double (__thiscall *)(IBreakableWithPropData *))v1->GetExplosiveRadius)(a1: &v1->IBreakableWithPropData) > 0.0 )
  {
    v43 = (int)v1->GetExplosiveRadius(this: &v1->IBreakableWithPropData);
    v42 = (int)v1->GetExplosiveDamage(this: &v1->IBreakableWithPropData);
    v41 = p_m_Collision->GetCollisionAngles(this: p_m_Collision);
    ExplosionCreate(
      center: &vecSpot,
      angles: v41,
      pOwner: v1,
      magnitude: v42,
      radius: v43,
      doDamage: true,
      flExplosionForce: 0.0,
      bSurfaceOnly: false,
      bSilent: false,
      iCustomDamageType: 0xFFFFFFFF);
  }
  CRecipientFilter::~CRecipientFilter(this: &filter2);
}

//------------------------------------------------------------------------------
// Address: 0x10133810
// Name: public: virtual int CPushable::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPushable::OnTakeDamage(CPushable *this, const CTakeDamageInfo *info)
{
  if ( SLOBYTE(this->m_spawnflags.m_Value) >= 0 )
    return 1;
  else
    return CBreakable::OnTakeDamage(this, info);
}

//------------------------------------------------------------------------------
// Address: 0x101340E0
// Name: public: virtual void CBreakable::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBreakable::Spawn(CBreakable *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  bool v5; // zf
  double m_fValue; // st7
  const char *pszValue; // eax
  const char *v8; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // ebx
  int m_Value; // ebx
  const char *v11; // eax
  CBreakable *v13; // [esp+0h] [ebp-4h] BYREF

  v13 = this;
  v5 = this->m_iszPropData.pszValue == nullptr;
  this->m_flDmgModBullet = func_breakdmg_bullet.m_pParent->m_Value.m_fValue;
  this->m_flDmgModClub = func_breakdmg_club.m_pParent->m_Value.m_fValue;
  m_fValue = func_breakdmg_explosive.m_pParent->m_Value.m_fValue;
  this->m_flDmgModFire = 1.0;
  this->m_flDmgModExplosive = m_fValue;
  if ( !v5 )
  {
    pszValue = this->m_iszPropData.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( V_strncmp(s1: pszValue, s2: "None", count: 4) != 0 )
    {
      v8 = this->m_iszPropData.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      CPropData::ParsePropFromBase(
        this: &g_PropDataSystem,
        pProp: this,
        pBreakableInterface: &this->IBreakableWithPropData,
        pszPropData: v8);
    }
  }
  ((void (__thiscall *)(CBreakable *, int, int, int))this->Precache)(a1: this, a2: a3, a3: a2, a4);
  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value == 0 || (this->m_spawnflags.m_Value & 1) != 0 )
  {
    if ( this->m_Material == matGlass && p_m_iHealth->m_Value != 1 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      p_m_iHealth->m_Value = 1;
    }
    if ( this->m_takedamage.m_Value != 0 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 0;
    }
  }
  else if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  m_Value = p_m_iHealth->m_Value;
  if ( m_Value <= 0 )
    m_Value = 1;
  if ( this->m_iMaxHealth.m_Value != m_Value )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    this->m_iMaxHealth.m_Value = m_Value;
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v11 = *(const char **)((int (__thiscall *)(CBreakable *, CBreakable **))this->GetModelName)(a1: this, a2: &v13);
  if ( v11 == nullptr )
    v11 = locale;
  this->SetModel(this, a2: v11);
  v5 = (this->m_spawnflags.m_Value & 1) == 0;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBreakable::BreakTouch;
  if ( !v5 )
    this->m_pfnTouch = nullptr;
  if ( this->m_Material == matUnbreakableGlass && this->m_nRenderMode.m_Value != 0 )
    CBaseEntity::AddFlag(this, flags: 0x2000000);
  if ( this->m_impactEnergyScale == 0.0 )
    this->m_impactEnergyScale = 1.0;
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x101342F0
// Name: public: virtual void CPushable::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPushable::Spawn(CPushable *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  const char *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  if ( (this->m_spawnflags.m_Value & 0x80) != 0 )
  {
    CBreakable::Spawn(this, a2, a3, a4: (int)this);
  }
  else
  {
    this->Precache(this);
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
    v4 = *(const char **)((int (__thiscall *)(CPushable *, _BYTE *))this->GetModelName)(a1: this, a2: v5);
    if ( v4 == nullptr )
      v4 = locale;
    this->SetModel(this, a2: v4);
    this->CreateVPhysics(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034B530
// Name: public: virtual void CBreakable::SetDmgModExplosive(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakable::SetDmgModExplosive(CChoreoScene *this, float t)
{
  this->m_flCurrentTime = t;
}

//------------------------------------------------------------------------------
// Address: 0x10403B10
// Name: CBreakable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBreakable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBreakable>(__formal: nullptr);
  CBreakable_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101327A0
// Name: class CPushable __near * _CreateEntityTemplate<class CPushable>(class CPushable __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPushable *__cdecl _CreateEntityTemplate<CPushable>(CPushable *newEnt, const char *className)
{
  CBreakable *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBreakable *)CBaseEntity::operator new(stAllocateBlock: 0x404u);
  v3 = &v2->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CBreakable::CBreakable(this: v2);
    *v3 = &CPushable::`vftable'{for `CBaseEntity'};
    v3[213] = &CPushable::`vftable'{for `IBreakableWithPropData'};
    v3[214] = &CPushable::`vftable'{for `CDefaultPlayerPickupVPhysics'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPushable *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133830
// Name: struct datamap_t __near * DataMapInit<class CBreakable>(class CBreakable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBreakable>()
{
  if ( (_S2_114 & 1) == 0 )
  {
    _S2_114 |= 1u;
    nameHolder_211.m_pszBase = "CBreakable";
    nameHolder_211.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_211.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_211.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_211.m_Names.m_Size = 0;
    nameHolder_211.m_Names.m_pElements = nullptr;
    nameHolder_211.m_nLenBase = 10;
    atexit(func: DataMapInit_CBreakable__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBreakable::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_114 & 2) == 0 )
  {
    _S2_114 |= 2u;
    dataDesc_201[19].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_211,
                                   pszIdentifier: "BreakTouch");
    dataDesc_201[19].flags = 32;
    dataDesc_201[19].fieldOffset = 0;
    dataDesc_201[19].fieldSize = 1;
    dataDesc_201[19].externalName = nullptr;
    dataDesc_201[19].pSaveRestoreOps = nullptr;
    dataDesc_201[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakable::BreakTouch;
    *(_QWORD *)&dataDesc_201[19].td = 0;
    *(_QWORD *)&dataDesc_201[19].override_field = 0;
    *(_QWORD *)&dataDesc_201[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_201[19].flatOffset[1] = 0;
    dataDesc_201[20].fieldType = FIELD_VOID;
    dataDesc_201[20].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_211, pszIdentifier: "Die");
    dataDesc_201[20].flags = 32;
    dataDesc_201[21].flags = 22;
    dataDesc_201[21].fieldType = FIELD_CUSTOM;
    dataDesc_201[22].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_201[20].td = 0;
    *(_QWORD *)&dataDesc_201[20].override_field = 0;
    *(_QWORD *)&dataDesc_201[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_201[20].flatOffset[1] = 0;
    dataDesc_201[21].pSaveRestoreOps = eventFuncs;
    dataDesc_201[22].pSaveRestoreOps = eventFuncs;
    dataDesc_201[20].fieldSize = 1;
    dataDesc_201[21].fieldSize = 1;
    dataDesc_201[22].fieldSize = 1;
    *(_QWORD *)&dataDesc_201[21].inputFunc = 0;
    *(_QWORD *)&dataDesc_201[21].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_201[21].override_count = 0;
    *(_QWORD *)dataDesc_201[21].flatOffset = 0;
    dataDesc_201[23].fieldSize = 1;
    dataDesc_201[20].fieldOffset = 0;
    dataDesc_201[20].externalName = nullptr;
    dataDesc_201[20].pSaveRestoreOps = nullptr;
    dataDesc_201[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CAI_BattleLine::`vcall'{776,{flat}};
    dataDesc_201[21].fieldName = "m_OnBreak";
    dataDesc_201[21].fieldOffset = 920;
    dataDesc_201[21].externalName = "OnBreak";
    *(_DWORD *)&dataDesc_201[21].flatGroup = 0;
    dataDesc_201[22].fieldName = "m_OnHealthChanged";
    dataDesc_201[22].fieldOffset = 944;
    dataDesc_201[22].flags = 22;
    dataDesc_201[22].externalName = "OnHealthChanged";
    *(_QWORD *)&dataDesc_201[22].inputFunc = 0;
    *(_QWORD *)&dataDesc_201[22].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_201[22].override_count = 0;
    *(_QWORD *)dataDesc_201[22].flatOffset = 0;
    *(_DWORD *)&dataDesc_201[22].flatGroup = 0;
    dataDesc_201[23].fieldType = FIELD_FLOAT;
    dataDesc_201[23].fieldName = "m_flDmgModBullet";
    dataDesc_201[23].fieldOffset = 968;
    dataDesc_201[23].flags = 2;
    dataDesc_201[23].externalName = nullptr;
    dataDesc_201[23].pSaveRestoreOps = nullptr;
    dataDesc_201[23].inputFunc = nullptr;
    dataDesc_201[23].td = nullptr;
    *(_QWORD *)dataDesc_201[23].flatOffset = 0;
    *(_QWORD *)dataDesc_201[24].flatOffset = 0;
    *(_QWORD *)dataDesc_201[25].flatOffset = 0;
    *(_QWORD *)dataDesc_201[26].flatOffset = 0;
    dataDesc_201[23].fieldSizeInBytes = 4;
    dataDesc_201[23].override_field = nullptr;
    dataDesc_201[23].override_count = 0;
    dataDesc_201[23].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_201[23].flatGroup = 0;
    dataDesc_201[24].fieldType = FIELD_FLOAT;
    dataDesc_201[24].fieldName = "m_flDmgModClub";
    dataDesc_201[24].fieldOffset = 972;
    dataDesc_201[24].fieldSize = 1;
    dataDesc_201[24].flags = 2;
    dataDesc_201[24].externalName = nullptr;
    dataDesc_201[24].pSaveRestoreOps = nullptr;
    dataDesc_201[24].inputFunc = nullptr;
    dataDesc_201[24].td = nullptr;
    dataDesc_201[24].fieldSizeInBytes = 4;
    dataDesc_201[24].override_field = nullptr;
    dataDesc_201[24].override_count = 0;
    dataDesc_201[24].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_201[24].flatGroup = 0;
    dataDesc_201[25].fieldType = FIELD_FLOAT;
    dataDesc_201[25].fieldName = "m_flDmgModExplosive";
    dataDesc_201[25].fieldOffset = 976;
    dataDesc_201[25].fieldSize = 1;
    dataDesc_201[25].flags = 2;
    dataDesc_201[25].externalName = nullptr;
    dataDesc_201[25].pSaveRestoreOps = nullptr;
    dataDesc_201[25].inputFunc = nullptr;
    dataDesc_201[25].td = nullptr;
    dataDesc_201[25].fieldSizeInBytes = 4;
    dataDesc_201[25].override_field = nullptr;
    dataDesc_201[25].override_count = 0;
    dataDesc_201[25].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_201[25].flatGroup = 0;
    dataDesc_201[26].fieldType = FIELD_FLOAT;
    dataDesc_201[26].fieldName = "m_flDmgModFire";
    dataDesc_201[26].fieldOffset = 980;
    dataDesc_201[26].fieldSize = 1;
    dataDesc_201[26].flags = 2;
    dataDesc_201[26].externalName = nullptr;
    dataDesc_201[26].pSaveRestoreOps = nullptr;
    dataDesc_201[26].inputFunc = nullptr;
    dataDesc_201[26].td = nullptr;
    dataDesc_201[26].fieldSizeInBytes = 4;
    dataDesc_201[26].override_field = nullptr;
    dataDesc_201[26].override_count = 0;
    dataDesc_201[26].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_201[26].flatGroup = 0;
    dataDesc_201[27].fieldType = FIELD_STRING;
    dataDesc_201[27].fieldName = "m_iszPhysicsDamageTableName";
    dataDesc_201[27].fieldOffset = 984;
    dataDesc_201[27].fieldSize = 1;
    dataDesc_201[27].flags = 2;
    dataDesc_201[27].externalName = nullptr;
    dataDesc_201[27].pSaveRestoreOps = nullptr;
    dataDesc_201[27].inputFunc = nullptr;
    dataDesc_201[27].td = nullptr;
    dataDesc_201[27].fieldSizeInBytes = 4;
    dataDesc_201[27].override_field = nullptr;
    dataDesc_201[27].override_count = 0;
    dataDesc_201[27].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_201[27].flatOffset = 0;
    *(_DWORD *)&dataDesc_201[27].flatGroup = 0;
    dataDesc_201[28].fieldType = FIELD_STRING;
    dataDesc_201[28].fieldName = "m_iszBreakableModel";
    dataDesc_201[28].fieldOffset = 988;
    dataDesc_201[28].fieldSize = 1;
    dataDesc_201[28].flags = 2;
    dataDesc_201[28].externalName = nullptr;
    dataDesc_201[28].pSaveRestoreOps = nullptr;
    dataDesc_201[28].inputFunc = nullptr;
    dataDesc_201[29].fieldSize = 1;
    dataDesc_201[29].flags = 2;
    dataDesc_201[30].fieldSize = 1;
    dataDesc_201[30].flags = 2;
    *(_QWORD *)dataDesc_201[28].flatOffset = 0;
    dataDesc_201[31].fieldSize = 1;
    *(_QWORD *)dataDesc_201[29].flatOffset = 0;
    dataDesc_201[31].flags = 2;
    *(_QWORD *)dataDesc_201[30].flatOffset = 0;
    dataDesc_201[32].fieldSize = 1;
    *(_QWORD *)dataDesc_201[31].flatOffset = 0;
    dataDesc_201[28].td = nullptr;
    dataDesc_201[28].fieldSizeInBytes = 4;
    dataDesc_201[28].override_field = nullptr;
    dataDesc_201[28].override_count = 0;
    dataDesc_201[28].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_201[28].flatGroup = 0;
    dataDesc_201[29].fieldType = FIELD_INTEGER;
    dataDesc_201[29].fieldName = "m_iBreakableSkin";
    dataDesc_201[29].fieldOffset = 992;
    dataDesc_201[29].externalName = nullptr;
    dataDesc_201[29].pSaveRestoreOps = nullptr;
    dataDesc_201[29].inputFunc = nullptr;
    dataDesc_201[29].td = nullptr;
    dataDesc_201[29].fieldSizeInBytes = 4;
    dataDesc_201[29].override_field = nullptr;
    dataDesc_201[29].override_count = 0;
    dataDesc_201[29].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_201[29].flatGroup = 0;
    dataDesc_201[30].fieldType = FIELD_INTEGER;
    dataDesc_201[30].fieldName = "m_iBreakableCount";
    dataDesc_201[30].fieldOffset = 996;
    dataDesc_201[30].externalName = nullptr;
    dataDesc_201[30].pSaveRestoreOps = nullptr;
    dataDesc_201[30].inputFunc = nullptr;
    dataDesc_201[30].td = nullptr;
    dataDesc_201[30].fieldSizeInBytes = 4;
    dataDesc_201[30].override_field = nullptr;
    dataDesc_201[30].override_count = 0;
    dataDesc_201[30].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_201[30].flatGroup = 0;
    dataDesc_201[31].fieldType = FIELD_INTEGER;
    dataDesc_201[31].fieldName = "m_iMaxBreakableSize";
    dataDesc_201[31].fieldOffset = 1000;
    dataDesc_201[31].externalName = nullptr;
    dataDesc_201[31].pSaveRestoreOps = nullptr;
    dataDesc_201[31].inputFunc = nullptr;
    dataDesc_201[31].td = nullptr;
    dataDesc_201[31].fieldSizeInBytes = 4;
    dataDesc_201[31].override_field = nullptr;
    dataDesc_201[31].override_count = 0;
    dataDesc_201[31].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_201[31].flatGroup = 0;
    dataDesc_201[32].fieldType = FIELD_STRING;
    dataDesc_201[32].fieldName = "m_iszBasePropData";
    dataDesc_201[32].fieldOffset = 1004;
    dataDesc_201[32].flags = 2;
    dataDesc_201[32].externalName = nullptr;
    dataDesc_201[32].pSaveRestoreOps = nullptr;
    dataDesc_201[32].inputFunc = nullptr;
    dataDesc_201[32].td = nullptr;
    dataDesc_201[32].fieldSizeInBytes = 4;
    dataDesc_201[32].override_field = nullptr;
    dataDesc_201[32].override_count = 0;
    dataDesc_201[32].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_201[32].flatOffset = 0;
    *(_DWORD *)&dataDesc_201[32].flatGroup = 0;
    dataDesc_201[33].fieldType = FIELD_INTEGER;
    *(_QWORD *)dataDesc_201[33].flatOffset = 0;
    *(_QWORD *)dataDesc_201[34].flatOffset = 0;
    dataDesc_201[33].fieldTolerance = 0.0;
    dataDesc_201[34].fieldTolerance = 0.0;
    dataDesc_201[35].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_201[35].flatOffset = 0;
    dataDesc_201[36].fieldTolerance = 0.0;
    dataDesc_201[37].fieldTolerance = 0.0;
    dataDesc_201[35].fieldType = FIELD_STRING;
    dataDesc_201[33].fieldName = "m_iInteractions";
    dataDesc_201[33].fieldOffset = 1008;
    *(_DWORD *)&dataDesc_201[33].fieldSize = 131073;
    dataDesc_201[33].externalName = nullptr;
    dataDesc_201[33].pSaveRestoreOps = nullptr;
    dataDesc_201[33].inputFunc = nullptr;
    dataDesc_201[33].td = nullptr;
    dataDesc_201[33].fieldSizeInBytes = 4;
    dataDesc_201[33].override_field = nullptr;
    dataDesc_201[33].override_count = 0;
    *(_DWORD *)&dataDesc_201[33].flatGroup = 0;
    dataDesc_201[34].fieldType = FIELD_FLOAT;
    dataDesc_201[34].fieldName = "m_explodeRadius";
    dataDesc_201[34].fieldOffset = 1016;
    *(_DWORD *)&dataDesc_201[34].fieldSize = 131073;
    dataDesc_201[34].externalName = nullptr;
    dataDesc_201[34].pSaveRestoreOps = nullptr;
    dataDesc_201[34].inputFunc = nullptr;
    dataDesc_201[34].td = nullptr;
    dataDesc_201[34].fieldSizeInBytes = 4;
    dataDesc_201[34].override_field = nullptr;
    dataDesc_201[34].override_count = 0;
    *(_DWORD *)&dataDesc_201[34].flatGroup = 0;
    dataDesc_201[35].fieldName = "m_iszModelName";
    dataDesc_201[35].fieldOffset = 912;
    *(_DWORD *)&dataDesc_201[35].fieldSize = 131073;
    dataDesc_201[35].externalName = nullptr;
    dataDesc_201[35].pSaveRestoreOps = nullptr;
    dataDesc_201[35].inputFunc = nullptr;
    dataDesc_201[35].td = nullptr;
    dataDesc_201[35].fieldSizeInBytes = 4;
    dataDesc_201[35].override_field = nullptr;
    dataDesc_201[35].override_count = 0;
    *(_DWORD *)&dataDesc_201[35].flatGroup = 0;
    dataDesc_201[36].fieldType = FIELD_EHANDLE;
    dataDesc_201[36].fieldName = "m_hPhysicsAttacker";
    dataDesc_201[36].fieldOffset = 1020;
    *(_DWORD *)&dataDesc_201[36].fieldSize = 131073;
    dataDesc_201[36].externalName = nullptr;
    dataDesc_201[36].pSaveRestoreOps = nullptr;
    dataDesc_201[36].inputFunc = nullptr;
    dataDesc_201[36].td = nullptr;
    dataDesc_201[36].fieldSizeInBytes = 4;
    dataDesc_201[36].override_field = nullptr;
    dataDesc_201[36].override_count = 0;
    *(_QWORD *)dataDesc_201[36].flatOffset = 0;
    *(_DWORD *)&dataDesc_201[36].flatGroup = 0;
    dataDesc_201[37].fieldType = FIELD_TIME;
    dataDesc_201[37].fieldName = "m_flLastPhysicsInfluenceTime";
    dataDesc_201[37].fieldOffset = 1024;
    *(_DWORD *)&dataDesc_201[37].fieldSize = 131073;
    dataDesc_201[37].externalName = nullptr;
    dataDesc_201[37].pSaveRestoreOps = nullptr;
    dataDesc_201[37].inputFunc = nullptr;
    dataDesc_201[37].td = nullptr;
    dataDesc_201[37].fieldSizeInBytes = 4;
    dataDesc_201[37].override_field = nullptr;
    dataDesc_201[37].override_count = 0;
    *(_QWORD *)dataDesc_201[37].flatOffset = 0;
    *(_DWORD *)&dataDesc_201[37].flatGroup = 0;
  }
  CBreakable::m_DataMap.dataNumFields = 37;
  CBreakable::m_DataMap.dataDesc = &dataDesc_201[1];
  return &CBreakable::m_DataMap;
}
