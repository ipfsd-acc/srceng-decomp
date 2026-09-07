// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/baseentity_shared.cpp
// Functions: 85
// ============================================================

#include "game\shared\baseentity_shared.h"

//------------------------------------------------------------------------------
// Address: 0x1000DDA0
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(Ray_t *this, const Vector *start, const Vector *end)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.z = 0.0;
  this->m_Extents.y = 0.0;
  this->m_Extents.x = 0.0;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsRay = true;
  this->m_StartOffset.z = 0.0;
  this->m_StartOffset.y = 0.0;
  this->m_StartOffset.x = 0.0;
  this->m_Start.Vector = *start;
}

//------------------------------------------------------------------------------
// Address: 0x1000E420
// Name: void UTIL_TraceLine(class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceLine(
        int a1@<ebp>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        ITraceFilter *pFilter,
        CGameTrace *ptr)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  _DWORD v12[3]; // [esp+24h] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+80h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a1;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  x = vecAbsStart->x;
  y = vecAbsStart->y;
  z = vecAbsStart->z;
  v10 = vecAbsEnd->z;
  v11 = vecAbsEnd->x - vecAbsStart->x;
  ray.m_Start.z = vecAbsEnd->y - y;
  ray.m_Start.y = v11;
  ray.m_Start.w = v10 - z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z) + (float)(v11 * v11))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_Delta.y, 0, 12);
  *(float *)v12 = x;
  *(float *)&v12[1] = y;
  *(float *)&v12[2] = z;
  ((void (__thiscall *)(IEngineTrace *, _DWORD *, unsigned int, ITraceFilter *, CGameTrace *, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v12,
    a3: mask,
    a4: pFilter,
    a5: ptr,
    a6: a2);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &ptr->startpos, vecAbsEnd: &ptr->endpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10013940
// Name: public: virtual class QAngle const __near & C_BaseEntity::EyeAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BaseEntity::EyeAngles(C_BaseEntity *this)
{
  return this->GetAbsAngles(this);
}

//------------------------------------------------------------------------------
// Address: 0x10013950
// Name: public: virtual class QAngle const __near & C_BaseEntity::LocalEyeAngles(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const QAngle *__thiscall C_BaseEntity::LocalEyeAngles(C_BaseEntity *this)
{
  return C_BaseEntity::GetLocalAngles(this);
}

//------------------------------------------------------------------------------
// Address: 0x10013960
// Name: public: virtual class Vector C_BaseEntity::EarPosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BaseEntity::EarPosition(C_BaseEntity *this, Vector *result)
{
  this->EyePosition(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013980
// Name: public: virtual class Vector const __near & C_BaseEntity::GetViewOffset(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::GetViewOffset(C_BaseEntity *this)
{
  return &this->m_vecViewOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10013990
// Name: public: void C_BaseEntity::AddFlag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::AddFlag(C_BaseEntity *this, int flags)
{
  this->m_fFlags |= flags;
}

//------------------------------------------------------------------------------
// Address: 0x100139A0
// Name: public: void C_BaseEntity::RemoveFlag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::RemoveFlag(C_BaseEntity *this, int flagsToRemove)
{
  this->m_fFlags &= ~flagsToRemove;
}

//------------------------------------------------------------------------------
// Address: 0x100139C0
// Name: public: void C_BaseEntity::ClearFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ClearFlags(C_BaseEntity *this)
{
  this->m_fFlags = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100139D0
// Name: public: void C_BaseEntity::SetEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetEffects(C_BaseEntity *this, unsigned int nEffects)
{
  unsigned int m_fEffects; // ecx
  char v4; // bl

  m_fEffects = this->m_fEffects;
  if ( nEffects != m_fEffects )
  {
    v4 = ((m_fEffects >> 10) ^ (nEffects >> 10)) & 1;
    this->m_fEffects = nEffects;
    if ( (nEffects & 8) != 0 && this->IsPlayer(this) )
      C_BasePlayer::IncrementEFNoInterpParity((C_BasePlayer *)this);
    C_BaseEntity::UpdateVisibility(this);
    if ( v4 != 0 )
      C_BaseEntity::OnFastReflectionRenderingChanged(this);
    C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
    C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013A40
// Name: public: void C_BaseEntity::AddEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::AddEffects(C_BaseEntity *this, int nEffects)
{
  this->m_fEffects |= nEffects;
  if ( (this->m_fEffects & 4) != 0 )
    C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_PRERENDER);
  if ( (nEffects & 0x20) != 0 )
    C_BaseEntity::UpdateVisibility(this);
  if ( (nEffects & 0x400) != 0 )
    C_BaseEntity::OnFastReflectionRenderingChanged(this);
  C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
  C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x10013A90
// Name: public: void C_BaseEntity::ParseMapData(class CEntityMapData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ParseMapData(C_BaseEntity *this, CEntityMapData *mapData)
{
  char keyName[2048]; // [esp+8h] [ebp-1000h] BYREF
  char value[2048]; // [esp+808h] [ebp-800h] BYREF

  if ( CEntityMapData::GetFirstKey(this: mapData, keyName, value) )
  {
    do
      this->KeyValue(this, a2: keyName, a3: value);
    while ( CEntityMapData::GetNextKey(this: mapData, keyName, value) );
  }
  this->OnParseMapDataFinished(this);
}

//------------------------------------------------------------------------------
// Address: 0x10013B10
// Name: public: virtual bool C_BaseEntity::KeyValue(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __thiscall C_BaseEntity::KeyValue(C_BaseEntity *this, const char *szKeyName, float flValue)
{
  char string[256]; // [esp+Ch] [ebp-100h] BYREF

  V_snprintf(pDest: string, maxLen: 256, pFormat: "%f", flValue);
  return ((int (__thiscall *)(C_BaseEntity *, const char *, char *))this->KeyValue)(a1: this, a2: szKeyName, a3: string);
}

//------------------------------------------------------------------------------
// Address: 0x10013B70
// Name: public: virtual bool C_BaseEntity::KeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::KeyValue(C_BaseEntity *this, const char *szKeyName, int nValue)
{
  char string[256]; // [esp+4h] [ebp-100h] BYREF

  V_snprintf(pDest: string, maxLen: 256, pFormat: "%d", nValue);
  return this->KeyValue(this, a2: szKeyName, a3: string);
}

//------------------------------------------------------------------------------
// Address: 0x10013BC0
// Name: public: virtual bool C_BaseEntity::KeyValue(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __thiscall C_BaseEntity::KeyValue(C_BaseEntity *this, const char *szKeyName, const Vector *vecValue)
{
  char string[256]; // [esp+1Ch] [ebp-100h] BYREF

  V_snprintf(pDest: string, maxLen: 256, pFormat: "%f %f %f", vecValue->x, vecValue->y, vecValue->z);
  return ((int (__thiscall *)(C_BaseEntity *, const char *, char *))this->KeyValue)(a1: this, a2: szKeyName, a3: string);
}

//------------------------------------------------------------------------------
// Address: 0x10013C40
// Name: public: virtual bool C_BaseEntity::ShouldCollide(int,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::ShouldCollide(C_BaseEntity *this, int collisionGroup, int contentsMask)
{
  bool result; // al

  result = true;
  if ( this->m_CollisionGroup == 1 )
    return (contentsMask & 0x4000000) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013C60
// Name: public: static void C_BaseEntity::SetPredictionRandomSeed(class CUserCmd const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::SetPredictionRandomSeed(const CUserCmd *cmd)
{
  if ( cmd != nullptr )
    C_BaseEntity::m_nPredictionRandomSeed = cmd->random_seed;
  else
    C_BaseEntity::m_nPredictionRandomSeed = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10013C80
// Name: public: virtual char const __near * C_BaseEntity::DamageDecal(int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_BaseEntity::DamageDecal(C_BaseEntity *this, int bitsDamageType, int gameMaterial)
{
  unsigned __int8 m_nRenderMode; // al
  const char *result; // eax

  m_nRenderMode = this->m_nRenderMode;
  if ( m_nRenderMode == 4 )
    return prType;
  if ( m_nRenderMode != 0 && gameMaterial == 71 )
    return "BulletProof";
  result = "ManhackCut";
  if ( bitsDamageType != 4 )
    return "Impact.Concrete";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013CC0
// Name: public: void C_BaseEntity::VPhysicsSwapObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::VPhysicsSwapObject(C_BaseEntity *this, IPhysicsObject *pSwap)
{
  if ( pSwap == nullptr )
    PhysRemoveShadow(pEntity: this);
  if ( this->m_pPhysicsObject == nullptr )
    _Warning(a1: "Bad vphysics swap for %s\n", this->m_iClassname);
  this->m_pPhysicsObject = pSwap;
}

//------------------------------------------------------------------------------
// Address: 0x10013D00
// Name: public: virtual void C_BaseEntity::VPhysicsDestroyObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::VPhysicsDestroyObject(C_BaseEntity *this)
{
  IPhysicsObject *m_pPhysicsObject; // eax

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    PhysDestroyObject(pObject: m_pPhysicsObject, pEntity: this);
    this->m_pPhysicsObject = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013D30
// Name: public: bool C_BaseEntity::IsBSPModel(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsBSPModel(C_BaseEntity *this)
{
  SolidType_t v2; // eax
  IVModelInfoClient_vtbl *v3; // edi
  int ModelIndex; // eax
  const struct model_t *v5; // edi

  v2 = this->GetSolid(this);
  if ( v2 != SOLID_BSP )
  {
    v3 = modelinfo->__vftable;
    ModelIndex = C_BaseEntity::GetModelIndex(this);
    v5 = v3->GetModel(this: modelinfo, a2: ModelIndex);
    if ( this->GetSolid(this) != SOLID_VPHYSICS || (v2 = modelinfo->GetModelType(this: modelinfo, a2: v5)) != SOLID_BSP )
      LOBYTE(v2) = 0;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10013DA0
// Name: public: virtual void C_BaseEntity::DispatchTraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::DispatchTraceAttack(
        C_BaseEntity *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  this->TraceAttack(this, a2: info, a3: vecDir, a4: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10013DB0
// Name: public: virtual void C_BaseEntity::DoImpactEffect(class CGameTrace __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::DoImpactEffect(C_BaseEntity *this, CGameTrace *tr, int nDamageType)
{
  UTIL_ImpactTrace(pTrace: tr, iDamageType: nDamageType, pCustomImpactName: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10013DD0
// Name: public: virtual void C_BaseEntity::MakeTracer(class Vector const __near &,class CGameTrace const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::MakeTracer(
        C_BaseEntity *this,
        const Vector *vecTracerSrc,
        const CGameTrace *tr,
        int iTracerType)
{
  const char *v5; // eax
  C_BaseEntity_vtbl *v6; // edx
  const char *v7; // edi
  int (__thiscall *GetTracerAttachment)(C_BaseEntity *); // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-4h] [ebp-28h]
  int v13; // [esp-4h] [ebp-28h]
  Vector vNewSrc; // [esp+18h] [ebp-Ch] BYREF

  v5 = this->GetTracerType(this);
  v6 = this->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v7 = v5;
  vNewSrc.z = vecTracerSrc->z;
  GetTracerAttachment = v6->GetTracerAttachment;
  *(_QWORD *)&vNewSrc.x = *(_QWORD *)&vecTracerSrc->x;
  v9 = GetTracerAttachment(this);
  if ( iTracerType == 1 )
  {
    v13 = v9;
    v11 = this->entindex(this: &this->IClientNetworkable);
    UTIL_Tracer(
      vecStart: &vNewSrc,
      vecEnd: &tr->endpos,
      iEntIndex: v11,
      iAttachment: v13,
      flVelocity: 0.0,
      bWhiz: false,
      pCustomTracerName: v7,
      iParticleID: 0);
  }
  else if ( iTracerType == 4 )
  {
    v12 = v9;
    v10 = ((int (*)(void))this->entindex)();
    UTIL_Tracer(
      vecStart: &vNewSrc,
      vecEnd: &tr->endpos,
      iEntIndex: v10,
      iAttachment: v12,
      flVelocity: 0.0,
      bWhiz: true,
      pCustomTracerName: v7,
      iParticleID: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013E80
// Name: public: virtual int C_BaseEntity::GetTracerAttachment(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetTracerAttachment(C_BaseEntity *this)
{
  bool v1; // zf
  int result; // eax

  v1 = !g_pGameRules->IsMultiplayer(this: g_pGameRules);
  result = 1;
  if ( v1 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013EB0
// Name: public: int C_BaseEntity::GetWaterType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetWaterType(C_BaseEntity *this)
{
  unsigned __int8 m_nWaterType; // cl
  int result; // eax

  m_nWaterType = this->m_nWaterType;
  result = 0;
  if ( (m_nWaterType & 1) != 0 )
    result = 32;
  if ( (m_nWaterType & 2) != 0 )
    return result | 0x10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013ED0
// Name: public: void C_BaseEntity::SetWaterType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetWaterType(C_BaseEntity *this, char nType)
{
  this->m_nWaterType = 0;
  if ( (nType & 0x20) != 0 )
    this->m_nWaterType = 1;
  if ( (nType & 0x10) != 0 )
    this->m_nWaterType |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x10013F00
// Name: public: bool C_BaseEntity::IsToolRecording(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsToolRecording(C_BaseEntity *this)
{
  return this->m_bToolRecording;
}

//------------------------------------------------------------------------------
// Address: 0x10013F10
// Name: public: bool Vector::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector::IsValid(Vector *this)
{
  return (LODWORD(this->x) & 0x7F800000) != 0x7F800000
      && (LODWORD(this->y) & 0x7F800000) != 0x7F800000
      && (LODWORD(this->z) & 0x7F800000) != 0x7F800000;
}

//------------------------------------------------------------------------------
// Address: 0x10013F70
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(
        Ray_t *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.x = maxs->x - mins->x;
  this->m_Extents.y = maxs->y - mins->y;
  this->m_Extents.z = maxs->z - mins->z;
  this->m_Extents.x = this->m_Extents.x * 0.5;
  this->m_Extents.y = this->m_Extents.y * 0.5;
  this->m_Extents.z = this->m_Extents.z * 0.5;
  this->m_IsRay = (float)((float)((float)(this->m_Extents.x * this->m_Extents.x)
                                + (float)(this->m_Extents.y * this->m_Extents.y))
                        + (float)(this->m_Extents.z * this->m_Extents.z)) < 0.000001;
  this->m_StartOffset.x = mins->x + maxs->x;
  this->m_StartOffset.y = maxs->y + mins->y;
  this->m_StartOffset.z = mins->z + maxs->z;
  this->m_StartOffset.x = this->m_StartOffset.x * 0.5;
  this->m_StartOffset.y = this->m_StartOffset.y * 0.5;
  this->m_StartOffset.z = this->m_StartOffset.z * 0.5;
  this->m_Start.x = start->x + this->m_StartOffset.x;
  this->m_Start.y = this->m_StartOffset.y + start->y;
  this->m_Start.z = this->m_StartOffset.z + start->z;
  this->m_StartOffset.x = this->m_StartOffset.x * -1.0;
  this->m_StartOffset.y = this->m_StartOffset.y * -1.0;
  this->m_StartOffset.z = this->m_StartOffset.z * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10014140
// Name: public: class CBaseHandle CClientEntityList::EntIndexToHandle(int)
// Source: json
//------------------------------------------------------------------------------
CBaseHandle *__thiscall CClientEntityList::EntIndexToHandle(CClientEntityList *this, CBaseHandle *result, int entnum)
{
  IHandleEntity *m_pEntity; // eax
  unsigned int m_Index; // edx

  if ( entnum >= -1 )
  {
    if ( entnum >= 0 && (m_pEntity = this->m_EntPtrArray[entnum].m_pEntity) != nullptr )
    {
      m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
      result->m_Index = m_Index;
      return result;
    }
    else
    {
      result->m_Index = -1;
      return result;
    }
  }
  else
  {
    result->m_Index = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100141A0
// Name: public: CEffectData::CEffectData(void)
// Source: json
//------------------------------------------------------------------------------
CEffectData *__thiscall CEffectData::CEffectData(CEffectData *this)
{
  this->m_vOrigin.x = 0.0;
  this->m_vOrigin.y = 0.0;
  this->m_vOrigin.z = 0.0;
  this->m_vStart.x = 0.0;
  this->m_vStart.y = 0.0;
  this->m_vStart.z = 0.0;
  this->m_vNormal.x = 0.0;
  this->m_vNormal.y = 0.0;
  this->m_vNormal.z = 0.0;
  this->m_vAngles.x = 0.0;
  this->m_vAngles.y = 0.0;
  this->m_vAngles.z = 0.0;
  this->m_hEntity.m_Index = -1;
  this->m_fFlags = 0;
  this->m_flScale = 1.0;
  this->m_nAttachmentIndex = 0;
  this->m_nSurfaceProp = 0;
  this->m_flMagnitude = 0.0;
  this->m_flRadius = 0.0;
  this->m_nMaterial = 0;
  this->m_nDamageType = 0;
  this->m_nHitBox = 0;
  this->m_nColor = 0;
  this->m_nOtherEntIndex = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014220
// Name: public: class Vector const __near & CShotManipulator::ApplySpread(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CShotManipulator::ApplySpread(CShotManipulator *this, const Vector *vecSpread, float bias)
{
  float v3; // xmm2_4
  float v5; // xmm2_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v16; // xmm2_4
  float shotBias; // [esp+24h] [ebp-10h]
  float ya; // [esp+28h] [ebp-Ch]
  float yb; // [esp+28h] [ebp-Ch]
  float y; // [esp+28h] [ebp-Ch]
  float x; // [esp+2Ch] [ebp-8h]
  float flatness; // [esp+30h] [ebp-4h]
  float biasa; // [esp+40h] [ebp+Ch]

  v3 = bias;
  if ( bias <= 1.0 )
  {
    if ( bias < 0.0 )
      v3 = 0.0;
  }
  else
  {
    v3 = 1.0;
  }
  shotBias = (float)((float)(ai_shot_bias_max.m_pParent->m_Value.m_fValue - ai_shot_bias_min.m_pParent->m_Value.m_fValue)
                   * v3)
           + ai_shot_bias_min.m_pParent->m_Value.m_fValue;
  flatness = COERCE_FLOAT(LODWORD(shotBias) & _mask__AbsFloat_) * 0.5;
  biasa = 1.0 - flatness;
  do
  {
    ya = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: -1082130432,
           a3: 1065353216)
       * biasa;
    x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
          a1: random,
          a2: -1082130432,
          a3: 1065353216)
      * flatness
      + ya;
    yb = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: -1082130432,
           a3: 1065353216)
       * biasa;
    y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
          a1: random,
          a2: -1082130432,
          a3: 1065353216)
      * flatness
      + yb;
    if ( shotBias >= 0.0 )
    {
      v6 = x;
      v8 = y;
    }
    else
    {
      if ( x < 0.0 )
        v5 = -1.0;
      else
        v5 = 1.0;
      v6 = v5 - x;
      if ( y < 0.0 )
        v7 = -1.0;
      else
        v7 = 1.0;
      v8 = v7 - y;
    }
  }
  while ( (float)((float)(v8 * v8) + (float)(v6 * v6)) > 1.0 );
  v9 = vecSpread->y * v8;
  v10 = this->m_vecUp.y * v9;
  v11 = this->m_vecUp.z * v9;
  v12 = this->m_vecUp.x * v9;
  v13 = vecSpread->x * v6;
  v14 = this->m_vecShotDirection.y + (float)(this->m_vecRight.y * v13);
  v16 = (float)(this->m_vecShotDirection.z + (float)(this->m_vecRight.z * v13)) + v11;
  this->m_vecResult.x = (float)(this->m_vecShotDirection.x + (float)(this->m_vecRight.x * v13)) + v12;
  this->m_vecResult.y = v14 + v10;
  this->m_vecResult.z = v16;
  return &this->m_vecResult;
}

//------------------------------------------------------------------------------
// Address: 0x10014470
// Name: public: virtual class Vector C_BaseEntity::EyePosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BaseEntity::EyePosition(C_BaseEntity *this, Vector *result)
{
  const Vector *v3; // eax

  v3 = this->GetAbsOrigin(this);
  result->x = this->m_vecViewOffset.x + v3->x;
  result->y = this->m_vecViewOffset.y + v3->y;
  result->z = this->m_vecViewOffset.z + v3->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100144C0
// Name: public: virtual void C_BaseEntity::SetViewOffset(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetViewOffset(C_BaseEntity *this, const Vector *v)
{
  this->m_vecViewOffset = *v;
}

//------------------------------------------------------------------------------
// Address: 0x100144F0
// Name: public: void C_BaseEntity::SetBlocksLOS(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetBlocksLOS(C_BaseEntity *this, bool bBlocksLOS)
{
  if ( bBlocksLOS )
    this->m_iEFlags &= ~0x2000000u;
  else
    this->m_iEFlags |= 0x2000000u;
}

//------------------------------------------------------------------------------
// Address: 0x10014520
// Name: public: bool C_BaseEntity::BlocksLOS(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::BlocksLOS(C_BaseEntity *this)
{
  return (this->m_iEFlags & 0x2000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014530
// Name: public: void C_BaseEntity::SetAIWalkable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetAIWalkable(C_BaseEntity *this, bool bBlocksLOS)
{
  if ( bBlocksLOS )
    this->m_iEFlags &= ~0x4000000u;
  else
    this->m_iEFlags |= 0x4000000u;
}

//------------------------------------------------------------------------------
// Address: 0x10014560
// Name: public: virtual void C_BaseEntity::DecalTrace(class CGameTrace __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::DecalTrace(C_BaseEntity *this, CGameTrace *pTrace, const char *decalName)
{
  int v3; // esi
  ITempEntsSystem_vtbl *v4; // edi
  int EntityIndex; // eax
  int hitbox; // [esp+14h] [ebp-30h]
  CBroadcastRecipientFilter filter; // [esp+24h] [ebp-20h] BYREF

  v3 = decalsystem->GetDecalIndexForName(this: decalsystem, a2: decalName);
  if ( v3 >= 0 )
  {
    C_RecipientFilter::C_RecipientFilter(this: &filter);
    filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
    C_RecipientFilter::AddAllPlayers(this: &filter);
    v4 = te->__vftable;
    hitbox = pTrace->hitbox;
    EntityIndex = CGameTrace::GetEntityIndex(this: pTrace);
    ((void (__thiscall *)(ITempEntsSystem *, CBroadcastRecipientFilter *, _DWORD, Vector *, CGameTrace *, int, int, int))v4->Decal)(
      a1: te,
      a2: &filter,
      a3: 0,
      a4: &pTrace->endpos,
      a5: pTrace,
      a6: EntityIndex,
      a7: hitbox,
      a8: v3);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100145E0
// Name: public: virtual void C_BaseEntity::ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ImpactTrace(
        C_BaseEntity *this,
        CGameTrace *pTrace,
        int iDamageType,
        char *pCustomImpactName)
{
  __int16 surfaceProps; // dx
  struct CBaseEntity *m_pEnt; // ecx
  float z; // xmm0_4
  unsigned int m_Index; // esi
  int v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  CEffectData data; // [esp+8h] [ebp-64h] BYREF
  int pTracea; // [esp+74h] [ebp+8h]

  surfaceProps = pTrace->surface.surfaceProps;
  m_pEnt = pTrace->m_pEnt;
  memset((void *)&data.m_vNormal, 0, 28);
  memset(&data.m_flMagnitude, 0, 12);
  data.m_vOrigin = pTrace->endpos;
  data.m_vStart.x = pTrace->startpos.x;
  data.m_vStart.y = pTrace->startpos.y;
  z = pTrace->startpos.z;
  data.m_hEntity.m_Index = -1;
  data.m_flScale = 1.0;
  data.m_nMaterial = 0;
  data.m_nColor = 0;
  data.m_nOtherEntIndex = 0;
  data.m_vStart.z = z;
  data.m_nSurfaceProp = surfaceProps;
  if ( surfaceProps < 0 )
    data.m_nSurfaceProp = 0;
  m_Index = cl_entitylist.m_Index;
  data.m_nHitBox = pTrace->hitbox;
  data.m_nDamageType = iDamageType;
  v8 = (*(int (__thiscall **)(int))(*((_DWORD *)m_pEnt + 2) + 40))(a1: (int)m_pEnt + 8);
  if ( v8 >= -1 )
  {
    if ( v8 >= 0 && (v10 = *(_DWORD *)(m_Index + 16 * v8 + 4)) != 0 )
      pTracea = *(_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
    else
      pTracea = -1;
    v9 = pTracea;
  }
  else
  {
    v9 = -1;
  }
  data.m_hEntity.m_Index = v9;
  if ( pCustomImpactName != nullptr )
    DispatchEffect(pName: pCustomImpactName, &data);
  else
    DispatchEffect(pName: "Impact", &data);
}

//------------------------------------------------------------------------------
// Address: 0x10014720
// Name: public: bool C_BaseEntity::IsStandable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsStandable(C_BaseEntity *this)
{
  if ( (this->GetSolidFlags(this) & 0x10) != 0 )
    return false;
  if ( this->GetSolid(this) == SOLID_BSP || this->GetSolid(this) == SOLID_VPHYSICS || this->GetSolid(this) == SOLID_BBOX )
    return true;
  return C_BaseEntity::IsBSPModel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10014780
// Name: public: void C_BaseEntity::ComputeTracerStartPosition(class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ComputeTracerStartPosition(
        C_BaseEntity *this,
        const Vector *vecShotSrc,
        Vector *pVecTracerStart)
{
  bool v4; // al
  float x; // xmm7_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  C_BaseCombatCharacter *(__thiscall *MyCombatCharacterPointer)(C_BaseEntity *); // edx
  int v10; // eax
  int v11; // eax
  Vector vecMuzzle; // [esp+4h] [ebp-18h] BYREF
  QAngle vecMuzzleAngles; // [esp+10h] [ebp-Ch] BYREF

  if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    pVecTracerStart->x = 999.0;
    pVecTracerStart->y = 999.0;
    pVecTracerStart->z = 999.0;
  }
  else if ( this->IsPlayer(this) )
  {
    v4 = this->IsPlayer(this);
    C_BasePlayer::EyeVectors(
      this: v4 ? (C_BasePlayer *)this : nullptr,
      pForward: (Vector *)&vecMuzzleAngles,
      pRight: &vecMuzzle,
      pUp: nullptr);
    x = vecShotSrc->x;
    v6 = vecMuzzle.y * 2.0;
    vecMuzzle.y = vecShotSrc->y;
    v7 = (float)(vecMuzzle.y + v6) + (float)(vecMuzzleAngles.y * 16.0);
    v8 = (float)((float)(vecShotSrc->z - 4.0) + (float)(vecMuzzle.z * 2.0)) + (float)(vecMuzzleAngles.z * 16.0);
    pVecTracerStart->x = (float)(x + (float)(vecMuzzle.x * 2.0)) + (float)(vecMuzzleAngles.x * 16.0);
    pVecTracerStart->y = v7;
    pVecTracerStart->z = v8;
  }
  else
  {
    pVecTracerStart->x = vecShotSrc->x;
    pVecTracerStart->y = vecShotSrc->y;
    MyCombatCharacterPointer = this->MyCombatCharacterPointer;
    pVecTracerStart->z = vecShotSrc->z;
    v10 = (int)MyCombatCharacterPointer(this);
    if ( v10 != 0 )
    {
      v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 948))(a1: v10);
      if ( v11 != 0
        && (*(unsigned __int8 (__thiscall **)(int, int, Vector *, QAngle *))(*(_DWORD *)(v11 + 4) + 140))(
             a1: v11 + 4,
             a2: 1,
             a3: &vecMuzzle,
             a4: &vecMuzzleAngles) != 0 )
      {
        *pVecTracerStart = vecMuzzle;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014910
// Name: public: void C_BaseEntity::ApplyAbsVelocityImpulse(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ApplyAbsVelocityImpulse(C_BaseEntity *this, const Vector *vecImpulse)
{
  int v3; // ebx
  int i; // esi
  _DWORD v5[1024]; // [esp+0h] [ebp-100Ch] BYREF
  Vector vecAbsVelocity; // [esp+1000h] [ebp-Ch] BYREF

  if ( vec3_origin.x != vecImpulse->x || vec3_origin.y != vecImpulse->y || vec3_origin.z != vecImpulse->z )
  {
    if ( this->m_MoveType == 6 )
    {
      v3 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v5, a3: 1024);
      for ( i = 0; i < v3; ++i )
        (*(void (__thiscall **)(_DWORD, const Vector *, _DWORD))(*(_DWORD *)v5[i] + 212))(
          a1: v5[i],
          a2: vecImpulse,
          a3: 0);
    }
    else
    {
      C_BaseEntity::CalcAbsoluteVelocity(this);
      vecAbsVelocity.x = vecImpulse->x + this->m_vecAbsVelocity.x;
      vecAbsVelocity.y = this->m_vecAbsVelocity.y + vecImpulse->y;
      vecAbsVelocity.z = this->m_vecAbsVelocity.z + vecImpulse->z;
      C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014A00
// Name: public: void C_BaseEntity::ApplyLocalAngularVelocityImpulse(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ApplyLocalAngularVelocityImpulse(C_BaseEntity *this, const Vector *angImpulse)
{
  float x; // xmm2_4
  int v3; // ebx
  int i; // esi
  float v5; // xmm3_4
  float v6; // xmm0_4
  _DWORD v7[1024]; // [esp+0h] [ebp-100Ch] BYREF
  QAngle vecAngVelocity; // [esp+1000h] [ebp-Ch] BYREF

  x = angImpulse->x;
  if ( vec3_origin.x != angImpulse->x || vec3_origin.y != angImpulse->y || vec3_origin.z != angImpulse->z )
  {
    if ( this->m_MoveType == 6 )
    {
      v3 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v7, a3: 1024);
      for ( i = 0; i < v3; ++i )
        (*(void (__thiscall **)(_DWORD, _DWORD, const Vector *))(*(_DWORD *)v7[i] + 212))(
          a1: v7[i],
          a2: 0,
          a3: angImpulse);
    }
    else
    {
      v5 = this->m_vecAngVelocity.x + angImpulse->y;
      vecAngVelocity.y = this->m_vecAngVelocity.y + angImpulse->z;
      v6 = this->m_vecAngVelocity.z + x;
      vecAngVelocity.x = v5;
      vecAngVelocity.z = v6;
      C_BaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014AF0
// Name: public: void C_BaseEntity::CollisionRulesChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::CollisionRulesChanged(C_BaseEntity *this)
{
  int v2; // edi
  int i; // esi
  int v4; // ecx
  _DWORD v5[1024]; // [esp+4h] [ebp-1000h] BYREF

  if ( this->m_pPhysicsObject != nullptr )
  {
    if ( PhysIsInCallback() )
      _Warning(a1: "Changing collision rules within a callback is likely to cause crashes!\n");
    v2 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v5, a3: 1024);
    for ( i = 0; i < v2; ++i )
    {
      v4 = v5[i];
      if ( v4 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 104))(a1: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014B60
// Name: class Vector __near & AllocTempVector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl AllocTempVector()
{
  int v0; // eax
  volatile int m_value; // edx
  unsigned __int16 v2; // cx
  volatile int v3; // edx

  v0 = `AllocTempVector'::`2'::`local static guard';
  if ( (`AllocTempVector'::`2'::`local static guard' & 1) == 0 )
  {
    v0 = `AllocTempVector'::`2'::`local static guard' | 1;
    `AllocTempVector'::`2'::`local static guard' |= 1u;
  }
  if ( (v0 & 2) == 0 )
  {
    `AllocTempVector'::`2'::`local static guard' = v0 | 2;
    `AllocTempVector'::`2'::s_nIndex.m_value = 0;
  }
  m_value = `AllocTempVector'::`2'::s_nIndex.m_value;
  v2 = (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F;
  if ( _InterlockedCompareExchange(
         &`AllocTempVector'::`2'::s_nIndex.m_value,
         (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F,
         `AllocTempVector'::`2'::s_nIndex.m_value) != m_value )
  {
    do
    {
      _mm_pause();
      v3 = `AllocTempVector'::`2'::s_nIndex.m_value;
      v2 = (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F;
    }
    while ( _InterlockedCompareExchange(
              &`AllocTempVector'::`2'::s_nIndex.m_value,
              (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F,
              `AllocTempVector'::`2'::s_nIndex.m_value) != v3 );
  }
  return &`AllocTempVector'::`2'::s_vecTemp[v2];
}

//------------------------------------------------------------------------------
// Address: 0x10014BF0
// Name: void UTIL_TraceLine(class Vector const __near &,class Vector const __near &,unsigned int,class IHandleEntity const __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceLine(
        const IHandleEntity *a1@<ebp>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        const IHandleEntity *ignore,
        int collisionGroup,
        CGameTrace *ptr)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  _DWORD v13[3]; // [esp+24h] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-60h] BYREF
  CTraceFilterSimple traceFilter; // [esp+80h] [ebp-10h]
  int retaddr; // [esp+90h] [ebp+0h]

  traceFilter.m_pPassEnt = a1;
  traceFilter.m_collisionGroup = retaddr;
  x = vecAbsStart->x;
  y = vecAbsStart->y;
  z = vecAbsStart->z;
  v11 = vecAbsEnd->z;
  v12 = vecAbsEnd->x - vecAbsStart->x;
  ray.m_Start.z = vecAbsEnd->y - y;
  ray.m_Start.y = v12;
  ray.m_Start.w = v11 - z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z) + (float)(v12 * v12))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_Delta.y, 0, 12);
  *(float *)v13 = x;
  *(float *)&v13[1] = y;
  *(float *)&v13[2] = z;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&ray.m_IsRay,
    passedict: ignore,
    collisionGroup,
    pExtraShouldHitFunc: nullptr);
  ((void (__thiscall *)(IEngineTrace *, _DWORD *, unsigned int, bool *, CGameTrace *, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v13,
    a3: mask,
    a4: &ray.m_IsRay,
    a5: ptr,
    a6: a2);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &ptr->startpos, vecAbsEnd: &ptr->endpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10014DC0
// Name: public: class Vector const __near & CCollisionProperty::CollisionToWorldSpace(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCollisionProperty::CollisionToWorldSpace(
        CCollisionProperty *this,
        const Vector *in,
        Vector *pResult)
{
  unsigned __int8 m_Value; // al
  const QAngle *v5; // eax
  const matrix3x4_t *v6; // eax
  const Vector *v8; // eax

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0
    || (m_Value = this->m_nSolidType.m_Value) == 2
    || m_Value == 0
    || (v5 = this->GetCollisionAngles(this), vec3_angle.x == v5->x) && vec3_angle.y == v5->y && vec3_angle.z == v5->z )
  {
    v8 = this->GetCollisionOrigin(this);
    pResult->x = v8->x + in->x;
    pResult->y = v8->y + in->y;
    pResult->z = v8->z + in->z;
    return pResult;
  }
  else
  {
    v6 = this->CollisionToWorldTransform(this);
    VectorTransform(in1: &in->x, in2: v6, out: &pResult->x);
    return pResult;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014E80
// Name: public: bool C_BaseEntity::IsSolid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::IsSolid(C_BaseEntity *this)
{
  return this->m_Collision.m_nSolidType.m_Value != 0 && (this->m_Collision.m_usSolidFlags.m_Value & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014EA0
// Name: public: class C_BaseEntity __near * C_BaseEntity::FirstMoveChild(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::FirstMoveChild(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_pMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10014F00
// Name: public: virtual bool C_BaseEntity::GetKeyValue(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::GetKeyValue(C_BaseEntity *this, const char *szKeyName, char *szValue, int iMaxLen)
{
  int RenderAlpha; // eax
  const Vector *v7; // eax
  unsigned __int8 r; // bl
  unsigned __int8 v9; // al
  unsigned __int8 tmp_1; // [esp+35h] [ebp+9h]
  unsigned __int8 tmp_2; // [esp+36h] [ebp+Ah]

  if ( _V_stricmp(s1: szKeyName, s2: "rendercolor") != 0 && _V_stricmp(s1: szKeyName, s2: "rendercolor32") != 0 )
  {
    if ( _V_stricmp(s1: szKeyName, s2: "renderamt") == 0 )
    {
      RenderAlpha = C_BaseEntity::GetRenderAlpha(this);
LABEL_5:
      V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%d", RenderAlpha);
      return 1;
    }
    if ( _V_stricmp(s1: szKeyName, s2: "disableshadows") == 0 )
    {
      RenderAlpha = (this->m_fEffects & 0x10) != 0;
      goto LABEL_5;
    }
    if ( _V_stricmp(s1: szKeyName, s2: "mins") != 0 && _V_stricmp(s1: szKeyName, s2: "maxs") != 0 )
    {
      if ( _V_stricmp(s1: szKeyName, s2: "disablereceiveshadows") == 0 )
      {
        RenderAlpha = (this->m_fEffects & 0x40) != 0;
        goto LABEL_5;
      }
      if ( _V_stricmp(s1: szKeyName, s2: "disableflashlight") == 0 )
      {
        RenderAlpha = (this->m_fEffects & 0x2000) != 0;
        goto LABEL_5;
      }
      if ( _V_stricmp(s1: szKeyName, s2: "nodamageforces") == 0 )
      {
        RenderAlpha = this->m_fEffects < 0;
        goto LABEL_5;
      }
      if ( _V_stricmp(s1: szKeyName, s2: "angle") != 0 )
      {
        if ( _V_stricmp(s1: szKeyName, s2: "angles") == 0 )
        {
          v7 = (const Vector *)this->GetAbsAngles(this);
LABEL_20:
          V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%f %f %f", v7->x, v7->y, v7->z);
          return 1;
        }
        if ( _V_stricmp(s1: szKeyName, s2: "origin") == 0 )
        {
          v7 = this->GetAbsOrigin(this);
          goto LABEL_20;
        }
      }
    }
    return 0;
  }
  tmp_2 = this->m_clrRender.m_Value.b;
  r = this->m_clrRender.m_Value.r;
  tmp_1 = this->m_clrRender.m_Value.g;
  v9 = C_BaseEntity::GetRenderAlpha(this);
  V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%d %d %d %d", r, tmp_1, tmp_2, v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015130
// Name: protected: int C_BaseEntity::GetIndexForThinkContext(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetIndexForThinkContext(C_BaseEntity *this, const char *pszContext)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( this->m_aThinkFunctions.m_Size <= 0 )
    return -1;
  for ( i = 0;
        V_strncmp(s1: this->m_aThinkFunctions.m_Memory.m_pMemory[i].m_iszContext, s2: pszContext, count: 32) != 0;
        ++i )
  {
    if ( ++v3 >= this->m_aThinkFunctions.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10015190
// Name: public: int C_BaseEntity::GetNextThinkTick(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetNextThinkTick(C_BaseEntity *this, const char *szContext)
{
  int result; // eax
  int IndexForThinkContext; // eax

  if ( szContext == nullptr )
  {
    result = this->m_nNextThinkTick;
    if ( result != -1 )
      return result;
    return -1;
  }
  IndexForThinkContext = C_BaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
  if ( IndexForThinkContext == -1 )
    return -1;
  result = this->m_aThinkFunctions.m_Memory.m_pMemory[IndexForThinkContext].m_nNextThinkTick;
  if ( result == -1 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100151E0
// Name: public: bool C_BaseEntity::WillThink(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::WillThink(C_BaseEntity *this)
{
  int m_Size; // edx
  int v3; // eax
  int *i; // ecx

  if ( this->m_nNextThinkTick > 0 )
    return 1;
  m_Size = this->m_aThinkFunctions.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    for ( i = &this->m_aThinkFunctions.m_Memory.m_pMemory->m_nNextThinkTick; *i <= 0; i += 8 )
    {
      if ( ++v3 >= m_Size )
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015220
// Name: public: void C_BaseEntity::CheckHasThinkFunction(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::CheckHasThinkFunction(C_BaseEntity *this, bool isThinking)
{
  int m_iEFlags; // esi

  m_iEFlags = this->m_iEFlags;
  if ( (m_iEFlags & 0x400000) != 0 )
  {
    if ( isThinking )
    {
      this->m_iEFlags = m_iEFlags & 0xFFBFFFFF;
      return;
    }
  }
  else if ( isThinking )
  {
    return;
  }
  if ( (this->m_iEFlags & 0x400000) == 0 && C_BaseEntity::WillThink(this) == 0 )
    this->m_iEFlags = m_iEFlags | 0x400000;
}

//------------------------------------------------------------------------------
// Address: 0x10015280
// Name: private: void C_BaseEntity::SetLastThink(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetLastThink(C_BaseEntity *this, int nContextIndex, float thinkTime)
{
  int v3; // edx

  if ( thinkTime == -1.0 )
    v3 = -1;
  else
    v3 = (int)(float)((float)(thinkTime / *(float *)(gpGlobals.m_Index + 28)) + 0.5);
  if ( nContextIndex >= 0 )
    this->m_aThinkFunctions.m_Memory.m_pMemory[nContextIndex].m_nLastThinkTick = v3;
  else
    this->m_nLastThinkTick = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100152E0
// Name: private: int C_BaseEntity::GetNextThinkTick(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetNextThinkTick(C_BaseEntity *this, int nContextIndex)
{
  if ( nContextIndex >= 0 )
    return this->m_aThinkFunctions.m_Memory.m_pMemory[nContextIndex].m_nNextThinkTick;
  else
    return this->m_nNextThinkTick;
}

//------------------------------------------------------------------------------
// Address: 0x10015310
// Name: public: void C_BaseEntity::VPhysicsSetObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::VPhysicsSetObject(C_BaseEntity *this, IPhysicsObject *pPhysics)
{
  const char *Classname; // eax

  if ( this->m_pPhysicsObject != nullptr && pPhysics != nullptr )
  {
    Classname = C_BaseEntity::GetClassname(this);
    _Warning(a1: "Overwriting physics object for %s\n", Classname);
  }
  this->m_pPhysicsObject = pPhysics;
  if ( pPhysics != nullptr )
  {
    this->m_flNonShadowMass = pPhysics->GetMass(this: pPhysics);
    if ( this->m_pPhysicsObject == nullptr )
      C_BaseEntity::CollisionRulesChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015370
// Name: public: class IPhysicsObject __near * C_BaseEntity::VPhysicsInitNormal(enum SolidType_t,int,bool,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall C_BaseEntity::VPhysicsInitNormal(
        C_BaseEntity *this,
        SolidType_t solidType,
        int nSolidFlags,
        bool createAsleep,
        solid_t *pSolid)
{
  int ModelIndex; // eax
  IPhysicsObject *v8; // eax
  IPhysicsObject *v9; // edi
  const Vector *v10; // [esp-Ch] [ebp-18h]
  const QAngle *v11; // [esp-8h] [ebp-14h]

  this->VPhysicsDestroyObject(this);
  this->m_flNonShadowMass = -1.0;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: solidType);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: nSolidFlags);
  if ( solidType == SOLID_NONE )
    return nullptr;
  v11 = this->GetAbsAngles(this);
  v10 = this->GetAbsOrigin(this);
  ModelIndex = C_BaseEntity::GetModelIndex(this);
  v8 = PhysModelCreate(pEntity: this, modelIndex: ModelIndex, origin: v10, angles: v11, pSolid);
  v9 = v8;
  if ( v8 != nullptr )
  {
    C_BaseEntity::VPhysicsSetObject(this, pPhysics: v8);
    C_BaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
    if ( !createAsleep )
      v9->Wake(this: v9);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10015420
// Name: public: class IPhysicsObject __near * C_BaseEntity::VPhysicsInitShadow(bool,bool,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall C_BaseEntity::VPhysicsInitShadow(
        C_BaseEntity *this,
        int allowPhysicsMovement,
        int allowPhysicsRotation,
        solid_t *pSolid)
{
  SolidType_t (__thiscall *GetSolid)(C_BaseEntity *); // edx
  IPhysicsObject *result; // eax
  const Vector *v7; // ebx
  QAngle *v8; // eax
  C_BaseEntity_vtbl *v9; // edx
  const Vector *v10; // eax
  C_BaseEntity_vtbl *v11; // edx
  float z; // xmm1_4
  const Vector *(__thiscall *WorldAlignMaxs)(C_BaseEntity *); // eax
  float *v14; // eax
  const Vector *v15; // eax
  int ModelIndex; // eax
  IPhysicsObject *v17; // edi
  const Vector *v18; // [esp+4h] [ebp-40h]
  Vector mins; // [esp+20h] [ebp-24h] BYREF
  Vector maxs; // [esp+2Ch] [ebp-18h] BYREF
  QAngle angles; // [esp+38h] [ebp-Ch] BYREF

  this->VPhysicsDestroyObject(this);
  GetSolid = this->GetSolid;
  this->m_flNonShadowMass = -1.0;
  result = (IPhysicsObject *)GetSolid(this);
  if ( result != nullptr )
  {
    v7 = this->GetAbsOrigin(this);
    v8 = this->GetAbsAngles(this);
    v9 = this->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    angles = *v8;
    if ( v9->GetSolid(this) == SOLID_BBOX )
    {
      v10 = this->WorldAlignMins(this);
      v11 = this->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      mins.x = v10->x + 0.21875;
      mins.y = v10->y + 0.21875;
      z = v10->z;
      WorldAlignMaxs = v11->WorldAlignMaxs;
      mins.z = z + 0.21875;
      v14 = (float *)WorldAlignMaxs(this);
      maxs.x = *v14 - 0.21875;
      maxs.y = v14[1] - 0.21875;
      maxs.z = v14[2] - 0.21875;
      result = PhysModelCreateBox(pEntity: this, &mins, &maxs, origin: v7, isStatic: false);
      angles = vec3_angle;
    }
    else if ( this->GetSolid(this) == SOLID_OBB )
    {
      v18 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
      v15 = this->m_Collision.OBBMins(this: &this->m_Collision);
      result = PhysModelCreateOBB(pEntity: this, mins: v15, maxs: v18, origin: v7, angle: &angles, isStatic: false);
    }
    else
    {
      ModelIndex = C_BaseEntity::GetModelIndex(this);
      result = PhysModelCreate(pEntity: this, modelIndex: ModelIndex, origin: v7, &angles, pSolid);
    }
    v17 = result;
    if ( result != nullptr )
    {
      C_BaseEntity::VPhysicsSetObject(this, pPhysics: result);
      ((void (__thiscall *)(IPhysicsObject *, int, int, int, int))v17->SetShadow)(
        a1: v17,
        a2: 1176256512,
        a3: 1176256512,
        a4: allowPhysicsMovement,
        a5: allowPhysicsRotation);
      ((void (__thiscall *)(IPhysicsObject *, const Vector *, QAngle *, _DWORD, _DWORD))v17->UpdateShadow)(
        a1: v17,
        a2: v7,
        a3: &angles,
        a4: 0,
        a5: 0);
      return v17;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015610
// Name: public: void C_BaseEntity::InvalidatePhysicsRecursive(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::InvalidatePhysicsRecursive(C_BaseEntity *this, int nChangeFlags)
{
  unsigned __int16 m_Value; // ax
  unsigned __int8 v4; // al
  IClientShadowMgr_vtbl *v5; // edi
  unsigned __int16 v6; // ax
  IClientShadowMgr_vtbl *v7; // esi
  unsigned __int16 v8; // ax
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // esi
  unsigned int v11; // ecx
  IHandleEntity *v12; // eax
  C_BaseAnimating *v13; // eax
  int nDirtyFlags; // [esp+4h] [ebp-8h]
  bool bSurroundDirty; // [esp+Bh] [ebp-1h]
  bool bSurroundDirtya; // [esp+Bh] [ebp-1h]

  nDirtyFlags = 0;
  if ( (nChangeFlags & 4) != 0 )
    nDirtyFlags = 4096;
  bSurroundDirty = false;
  if ( (nChangeFlags & 1) != 0 )
  {
    nDirtyFlags |= 0x800u;
    if ( this->entindex(this: &this->IClientNetworkable) != 0 )
      CCollisionProperty::MarkPartitionHandleDirty(this: &this->m_Collision);
  }
  if ( (nChangeFlags & 2) != 0 )
  {
    m_Value = this->m_Collision.m_usSolidFlags.m_Value;
    nDirtyFlags |= 0x800u;
    if ( (m_Value & 0x100) != 0 )
    {
$LN112:
      CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
      bSurroundDirty = true;
    }
    else
    {
      switch ( this->m_Collision.m_nSurroundType.m_Value )
      {
        case 0u:
        case 1u:
        case 6u:
          if ( (m_Value & 0x40) == 0 )
          {
            v4 = this->m_Collision.m_nSolidType.m_Value;
            if ( v4 != 2 && v4 != 0 )
              goto $LN112;
          }
          break;
        case 3u:
        case 5u:
        case 7u:
          break;
        default:
          goto $LN112;
      }
    }
    nChangeFlags |= 5u;
  }
  if ( (nChangeFlags & 0x20) != 0 )
  {
    if ( !bSurroundDirty && this->m_Collision.m_nSurroundType.m_Value == 7 )
    {
      CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
      bSurroundDirty = true;
    }
    nChangeFlags &= ~0x20u;
  }
  if ( !bSurroundDirty && (nChangeFlags & 0x13) != 0 && this->entindex(this: &this->IClientNetworkable) != 0 )
  {
    C_BaseEntity::MarkRenderHandleDirty(this);
    g_pClientShadowMgr->AddToDirtyShadowList(this: g_pClientShadowMgr, a2: &this->IClientRenderable, a3: false);
    v5 = g_pClientShadowMgr->__vftable;
    v6 = this->GetShadowHandle(this: &this->IClientRenderable);
    v5->MarkRenderToTextureShadowDirty(this: g_pClientShadowMgr, a2: v6);
  }
  this->m_iEFlags |= nDirtyFlags;
  bSurroundDirtya = false;
  if ( (nChangeFlags & 0x18) != 0 )
  {
    if ( (nChangeFlags & 0x10) == 0 )
    {
      v7 = g_pClientShadowMgr->__vftable;
      v8 = this->GetShadowHandle(this: &this->IClientRenderable);
      v7->MarkRenderToTextureShadowDirty(this: g_pClientShadowMgr, a2: v8);
    }
    if ( (nChangeFlags & 7) == 0 )
      bSurroundDirtya = true;
    nChangeFlags = 7;
  }
  m_Index = this->m_pMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    do
    {
      if ( !bSurroundDirtya || m_pEntity->m_iParentAttachment != 0 || C_BaseEntity::IsFollowingEntity(this: m_pEntity) )
        C_BaseEntity::InvalidatePhysicsRecursive(this: m_pEntity, nChangeFlags);
      v11 = m_pEntity->m_pMovePeer.m_Index;
      if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
        v12 = nullptr;
      else
        v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      m_pEntity = (C_BaseEntity *)v12;
    }
    while ( v12 != nullptr );
  }
  if ( (nChangeFlags & 0xB) != 0 )
  {
    v13 = this->GetBaseAnimating(this);
    if ( v13 != nullptr )
      C_BaseAnimating::InvalidateBoneCache(this: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015840
// Name: public: class C_BaseEntity __near * C_BaseEntity::GetRootMoveParent(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::GetRootMoveParent(C_BaseEntity *this)
{
  C_BaseEntity *result; // eax
  unsigned int m_Index; // edx
  C_BaseEntity *m_pEntity; // edx
  unsigned int v4; // edx

  result = this;
  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index == -1 )
  {
    m_pEntity = nullptr;
  }
  else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  else
  {
    m_pEntity = nullptr;
  }
  while ( m_pEntity != nullptr )
  {
    result = m_pEntity;
    v4 = m_pEntity->m_pMoveParent.m_Index;
    if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100158B0
// Name: public: class CBaseTrace __near & CBaseTrace::operator=(class CBaseTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseTrace *__thiscall CBaseTrace::operator=(CBaseTrace *this, const CBaseTrace *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10015940
// Name: public: virtual bool C_BaseEntity::HandleShotImpactingWater(struct FireBulletsInfo_t const __near &,class Vector const __near &,class ITraceFilter __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::HandleShotImpactingWater(
        C_BaseEntity *this,
        const FireBulletsInfo_t *info,
        const Vector *vecEnd,
        ITraceFilter *pTraceFilter,
        Vector *pVecTracerDest)
{
  CCSAmmoDef *AmmoDef; // eax
  int v8; // eax
  int v9; // edi
  CCSAmmoDef *v10; // eax
  int v11; // eax
  int m_iAmmoType; // [esp+10h] [ebp-D4h]
  int v13; // [esp+10h] [ebp-D4h]
  CGameTrace waterTrace; // [esp+20h] [ebp-C4h] BYREF
  CEffectData data; // [esp+74h] [ebp-70h] BYREF
  float v16[3]; // [esp+D8h] [ebp-Ch] BYREF
  int savedregs; // [esp+E4h] [ebp+0h] BYREF

  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)info,
    vecAbsStart: &info->m_vecSrc,
    vecAbsEnd: vecEnd,
    mask: 0x46004033u,
    pFilter: pTraceFilter,
    ptr: &waterTrace);
  v16[0] = waterTrace.endpos.x;
  v16[1] = waterTrace.endpos.y;
  v16[2] = waterTrace.endpos.z - 0.1;
  if ( (enginetrace->GetPointContents(this: enginetrace, a2: (const Vector *)v16, a3: 16432, a4: nullptr) & 0x30) == 0 )
    return 0;
  if ( this->ShouldDrawWaterImpacts(this) )
  {
    m_iAmmoType = info->m_iAmmoType;
    AmmoDef = GetAmmoDef();
    v8 = CAmmoDef::MinSplashSize(this: AmmoDef, nAmmoIndex: m_iAmmoType);
    v13 = info->m_iAmmoType;
    v9 = v8;
    v10 = GetAmmoDef();
    v11 = CAmmoDef::MaxSplashSize(this: v10, nAmmoIndex: v13);
    memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
    memset((void *)&data.m_vAngles, 0, 16);
    memset(&data.m_flMagnitude, 0, 14);
    data.m_vOrigin = waterTrace.endpos;
    data.m_vNormal = waterTrace.plane.normal;
    data.m_hEntity.m_Index = -1;
    data.m_flScale = 1.0;
    memset(&data.m_nMaterial, 0, 17);
    data.m_flScale = ((double (__thiscall *)(_DWORD, _DWORD, _DWORD))random->RandomFloat)(
                       a1: random,
                       a2: (float)v9,
                       a3: (float)v11);
    if ( (waterTrace.contents & 0x10) != 0 )
      data.m_fFlags |= 1u;
    DispatchEffect(pName: "gunshotsplash", &data);
  }
  *pVecTracerDest = waterTrace.endpos;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015B20
// Name: public: void C_BaseEntity::TraceBleed(float,class Vector const __near &,class CGameTrace __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::TraceBleed(
        C_BaseEntity *this,
        float flDamage,
        const Vector *vecDir,
        CGameTrace *ptr,
        int bitsDamageType)
{
  int v6; // xmm1_4
  int v7; // ecx
  int v8; // eax
  int v10; // xmm0_4
  Vector *p_endpos; // esi
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  double v13; // st7
  float (__thiscall *v14)(IUniformRandomStream *, float, float); // edx
  double v15; // st7
  IUniformRandomStream_vtbl *v16; // eax
  double v17; // st7
  int v18; // eax
  CGameTrace Bloodtr; // [esp+24h] [ebp-7Ch] BYREF
  Vector vecAbsEnd; // [esp+78h] [ebp-28h] BYREF
  Vector vecTraceDir; // [esp+84h] [ebp-1Ch]
  float v22; // [esp+90h] [ebp-10h]
  float v23; // [esp+94h] [ebp-Ch]
  float v24; // [esp+98h] [ebp-8h]
  float v25; // [esp+9Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+A0h] [ebp+0h] BYREF
  int flNoise; // [esp+A8h] [ebp+8h]
  const Vector *vecDira; // [esp+ACh] [ebp+Ch]
  int bitsDamageTypea; // [esp+B4h] [ebp+14h]

  if ( this->BloodColor(this) != -1
    && this->BloodColor(this) != 3
    && flDamage != 0.0
    && (bitsDamageType & 0x20000C7) != 0 )
  {
    if ( flDamage >= 10.0 )
    {
      if ( flDamage >= 25.0 )
      {
        v6 = 1050253722;
        v7 = 4;
      }
      else
      {
        v6 = 1045220557;
        v7 = 2;
      }
    }
    else
    {
      v6 = 1036831949;
      v7 = 1;
    }
    v8 = (bitsDamageType & 0x2000000) != 0 ? 384 : 172;
    flNoise = v6;
    v10 = v6 ^ _mask__NegFloat_;
    bitsDamageTypea = v6 ^ _mask__NegFloat_;
    LODWORD(v25) = COERCE_UNSIGNED_INT((float)v8) ^ _mask__NegFloat_;
    p_endpos = &ptr->endpos;
    vecDira = (const Vector *)v7;
    while ( 1 )
    {
      RandomFloat = random->RandomFloat;
      v22 = vecDir->x * -1.0;
      v23 = vecDir->y * -1.0;
      v24 = -1.0 * vecDir->z;
      v13 = ((double (__stdcall *)(int, int))RandomFloat)(a1: v10, a2: v6);
      v14 = random->RandomFloat;
      vecTraceDir.x = v13 + v22;
      v15 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v14)(a1: random, a2: bitsDamageTypea, a3: flNoise);
      v16 = random->__vftable;
      vecTraceDir.y = v15 + v23;
      v17 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v16->RandomFloat)(
              a1: random,
              a2: bitsDamageTypea,
              a3: flNoise);
      vecTraceDir.z = v17 + v24;
      vecAbsEnd.x = (float)(v25 * vecTraceDir.x) + p_endpos->x;
      vecAbsEnd.y = ptr->endpos.y + (float)(v25 * vecTraceDir.y);
      vecAbsEnd.z = ptr->endpos.z + (float)(v25 * vecTraceDir.z);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)p_endpos,
        vecAbsStart: p_endpos,
        &vecAbsEnd,
        mask: 0x4003u,
        ignore: this,
        collisionGroup: 0,
        ptr: &Bloodtr);
      if ( Bloodtr.fraction != 1.0 )
      {
        v18 = this->BloodColor(this);
        UTIL_BloodDecalTrace(pTrace: &Bloodtr, bloodColor: v18);
      }
      vecDira = (const Vector *)((char *)vecDira - 1);
      if ( vecDira == nullptr )
        break;
      v10 = bitsDamageTypea;
      v6 = flNoise;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015D40
// Name: public: void C_BaseEntity::FollowEntity(class C_BaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::FollowEntity(C_BaseEntity *this, C_BaseEntity *pBaseEntity, bool bBoneMerge)
{
  if ( pBaseEntity != nullptr )
  {
    C_BaseEntity::SetParent(this, pParentEntity: pBaseEntity, iParentAttachment: 0);
    C_BaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    if ( bBoneMerge )
    {
      this->m_fEffects |= 1u;
      if ( (this->m_fEffects & 4) != 0 )
        C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_PRERENDER);
      C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
      C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
    }
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    C_BaseEntity::SetLocalOrigin(this, origin: &vec3_origin);
    C_BaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  }
  else
  {
    C_BaseEntity::StopFollowingEntity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015DD0
// Name: public: void C_BaseEntity::SetCollisionGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetCollisionGroup(C_BaseEntity *this, int collisionGroup)
{
  if ( this->m_CollisionGroup != collisionGroup )
  {
    this->m_CollisionGroup = collisionGroup;
    C_BaseEntity::CollisionRulesChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015DF0
// Name: public: static bool C_BaseEntity::IsSimulatingOnAlternateTicks(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl C_BaseEntity::IsSimulatingOnAlternateTicks()
{
  if ( *(_DWORD *)(gpGlobals.m_Index + 20) != 1 )
    return false;
  if ( sv_alternateticks.m_pParent != nullptr )
    return sv_alternateticks.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10015E20
// Name: public: void C_BaseEntity::PhysicsTouchTriggers(class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseEntity::PhysicsTouchTriggers(
        C_BaseEntity *this@<ecx>,
        int a2@<ebp>,
        const Vector *pPrevAbsOrigin)
{
  TouchTriggerPlayerMovement(a1: a2, pEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x10015E30
// Name: public: void C_BaseEntity::SetPlayerSimulated(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetPlayerSimulated(C_BaseEntity *this, C_BasePlayer *pOwner)
{
  this->m_bIsPlayerSimulated = true;
  C_BasePlayer::AddToPlayerSimulationList(this: pOwner, other: this);
  if ( pOwner != nullptr )
    this->m_hPlayerSimulationOwner.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
  else
    this->m_hPlayerSimulationOwner.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10015E80
// Name: public: void C_BaseEntity::UnsetPlayerSimulated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::UnsetPlayerSimulated(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  C_BasePlayer **v8; // eax
  C_BasePlayer *v9; // eax

  m_Index = this->m_hPlayerSimulationOwner.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (C_BasePlayer **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        v9 = *v8;
      else
        v9 = nullptr;
      C_BasePlayer::RemoveFromPlayerSimulationList(this: v9, other: this);
    }
  }
  this->m_hPlayerSimulationOwner.m_Index = -1;
  this->m_bIsPlayerSimulated = false;
}

//------------------------------------------------------------------------------
// Address: 0x10015EE0
// Name: public: virtual class Vector const __near & C_BaseEntity::WorldSpaceCenter(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::WorldSpaceCenter(C_BaseEntity *this)
{
  C_BaseEntity::NetworkVar_m_Collision *p_m_Collision; // esi
  Vector *v2; // edi
  Vector *v3; // eax

  p_m_Collision = &this->m_Collision;
  v2 = AllocTempVector();
  v3 = AllocTempVector();
  v3->x = (float)((float)(p_m_Collision->m_vecMaxs.m_Value.x - p_m_Collision->m_vecMins.m_Value.x) * 0.5)
        + p_m_Collision->m_vecMins.m_Value.x;
  v3->y = (float)((float)(p_m_Collision->m_vecMaxs.m_Value.y - p_m_Collision->m_vecMins.m_Value.y) * 0.5)
        + p_m_Collision->m_vecMins.m_Value.y;
  v3->z = (float)((float)(p_m_Collision->m_vecMaxs.m_Value.z - p_m_Collision->m_vecMins.m_Value.z) * 0.5)
        + p_m_Collision->m_vecMins.m_Value.z;
  CCollisionProperty::CollisionToWorldSpace(this: p_m_Collision, in: v3, pResult: v2);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10015F60
// Name: public: virtual void C_BaseEntity::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::VPhysicsUpdate(C_BaseEntity *this, IPhysicsObject *pPhysics)
{
  unsigned int m_Index; // ecx
  const char *DebugName; // eax
  int i; // esi
  const char *v6; // eax
  Vector origin; // [esp+18h] [ebp-18h] BYREF
  QAngle angles; // [esp+24h] [ebp-Ch] BYREF

  if ( this->m_MoveType == 6 )
  {
    m_Index = this->m_pMoveParent.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      pPhysics->GetPosition(this: pPhysics, a2: &origin, a3: &angles);
      if ( (LODWORD(angles.x) & 0x7F800000) == 0x7F800000
        || (LODWORD(angles.y) & 0x7F800000) == 0x7F800000
        || (LODWORD(angles.x) & 0x7F800000) == 0x7F800000 )
      {
        DebugName = C_BaseEntity::GetDebugName(this);
        _Msg(a1: "Infinite angles from vphysics! (entity %s)\n", DebugName);
        angles = vec3_angle;
      }
      for ( i = 0; i < 3; ++i )
        *(&angles.x + i) = AngleNormalize(angle: *(&angles.x + i));
      if ( (LODWORD(origin.x) & 0x7F800000) == 0x7F800000
        || (LODWORD(origin.y) & 0x7F800000) == 0x7F800000
        || (LODWORD(origin.z) & 0x7F800000) == 0x7F800000 )
      {
        v6 = C_BaseEntity::GetDebugName(this);
        _Msg(a1: "Infinite origin from vphysics! (entity %s)\n", v6);
      }
      else
      {
        C_BaseEntity::SetAbsOrigin(this, absOrigin: &origin);
      }
      C_BaseEntity::SetAbsAngles(this, absAngles: &angles);
      if ( pPhysics->IsAsleep(this: pPhysics) && this->m_CollisionGroup == 3 )
      {
        this->m_CollisionGroup = 1;
        C_BaseEntity::CollisionRulesChanged(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016120
// Name: public: class IPhysicsObject __near * C_BaseEntity::VPhysicsInitStatic(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall C_BaseEntity::VPhysicsInitStatic(C_BaseEntity *this)
{
  SolidType_t (__thiscall *GetSolid)(C_BaseEntity *); // edx
  IPhysicsObject *result; // eax
  bool v4; // zf
  C_BaseEntity_vtbl *v5; // eax
  const Vector *v6; // eax
  IPhysicsObject *Box; // edi
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // edx
  const Vector *v9; // eax
  IPhysicsObject *OBB; // edi
  int ModelIndex; // eax
  const Vector *v12; // [esp-14h] [ebp-18h]
  const Vector *v13; // [esp-10h] [ebp-14h]
  const Vector *v14; // [esp-10h] [ebp-14h]
  const Vector *v15; // [esp-Ch] [ebp-10h]
  const QAngle *v16; // [esp-Ch] [ebp-10h]
  const Vector *v17; // [esp-Ch] [ebp-10h]
  const QAngle *v18; // [esp-8h] [ebp-Ch]

  this->VPhysicsDestroyObject(this);
  GetSolid = this->GetSolid;
  this->m_flNonShadowMass = -1.0;
  result = (IPhysicsObject *)GetSolid(this);
  if ( result != nullptr )
  {
    v4 = this->GetSolid(this) == SOLID_BBOX;
    v5 = this->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( v4 )
    {
      v15 = v5->GetAbsOrigin(this);
      v13 = this->WorldAlignMaxs(this);
      v6 = this->WorldAlignMins(this);
      Box = PhysModelCreateBox(pEntity: this, mins: v6, maxs: v13, origin: v15, isStatic: true);
      C_BaseEntity::VPhysicsSetObject(this, pPhysics: Box);
      return Box;
    }
    else
    {
      v4 = v5->GetSolid(this) == SOLID_OBB;
      GetAbsAngles = this->GetAbsAngles;
      if ( v4 )
      {
        v16 = GetAbsAngles(this);
        v14 = this->GetAbsOrigin(this);
        v12 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
        v9 = this->m_Collision.OBBMins(this: &this->m_Collision);
        OBB = PhysModelCreateOBB(pEntity: this, mins: v9, maxs: v12, origin: v14, angle: v16, isStatic: true);
      }
      else
      {
        v18 = GetAbsAngles(this);
        v17 = this->GetAbsOrigin(this);
        ModelIndex = C_BaseEntity::GetModelIndex(this);
        OBB = PhysModelCreateUnmoveable(pEntity: this, modelIndex: ModelIndex, origin: v17, angles: v18);
      }
      C_BaseEntity::VPhysicsSetObject(this, pPhysics: OBB);
      return OBB;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016230
// Name: public: class CGameTrace __near & CGameTrace::operator=(class CGameTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CGameTrace *__thiscall CGameTrace::operator=(CGameTrace *this, const CGameTrace *__that)
{
  CBaseTrace::operator=(this, __that);
  this->fractionleftsolid = __that->fractionleftsolid;
  this->surface = __that->surface;
  this->hitgroup = __that->hitgroup;
  this->physicsbone = __that->physicsbone;
  this->worldSurfaceIndex = __that->worldSurfaceIndex;
  this->m_pEnt = __that->m_pEnt;
  this->hitbox = __that->hitbox;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016280
// Name: public: virtual void C_BaseEntity::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::TraceAttack(
        C_BaseEntity *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  bool v7; // zf
  float v8; // xmm0_4
  int v9; // eax
  int m_flDamage; // [esp+Ch] [ebp-28h]
  Vector origin; // [esp+1Ch] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+28h] [ebp-Ch]

  v4 = vecDir->z * 4.0;
  v5 = ptr->endpos.x - (float)(vecDir->x * 4.0);
  vecOrigin.y = ptr->endpos.y - (float)(vecDir->y * 4.0);
  v7 = this->m_takedamage == 0;
  v8 = ptr->endpos.z - v4;
  vecOrigin.x = v5;
  vecOrigin.z = v8;
  if ( !v7 )
  {
    AddMultiDamage(a1: (int)this, info, pEntity: this);
    v9 = this->BloodColor(this);
    if ( v9 != -1 )
    {
      m_flDamage = (int)info->m_flDamage;
      origin = vecOrigin;
      UTIL_BloodDrips(&origin, direction: vecDir, color: v9, amount: m_flDamage);
      C_BaseEntity::TraceBleed(this, flDamage: info->m_flDamage, vecDir, ptr, bitsDamageType: info->m_bitsDamageType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016350
// Name: public: void C_BaseEntity::SetEffectEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetEffectEntity(C_BaseEntity *this, C_BaseEntity *pEffectEnt)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax

  m_Index = this->m_hEffectEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != pEffectEnt )
  {
    if ( pEffectEnt != nullptr )
      this->m_hEffectEntity.m_Index = *(_DWORD *)((int (*)(void))pEffectEnt->GetRefEHandle)();
    else
      this->m_hEffectEntity.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100163B0
// Name: public: void C_BaseEntity::SetRenderColor(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetRenderColor(
        C_BaseEntity *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  if ( this->m_clrRender.m_Value.r != r )
    this->m_clrRender.m_Value.r = r;
  if ( this->m_clrRender.m_Value.g != g )
    this->m_clrRender.m_Value.g = g;
  if ( this->m_clrRender.m_Value.b != b )
    this->m_clrRender.m_Value.b = b;
}

//------------------------------------------------------------------------------
// Address: 0x100163E0
// Name: public: virtual bool C_BaseEntity::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::KeyValue(C_BaseEntity *this, char *szKeyName, const char *szValue)
{
  _BYTE *v5; // eax
  unsigned __int8 v6; // al
  int v8; // eax
  const Vector *v9; // eax
  const Vector *v10; // eax
  long double v11; // st7
  const QAngle *LocalAngles; // eax
  unsigned __int8 g; // ah
  int pVector; // [esp+20h] [ebp-Ch] BYREF
  color32_s tmp; // [esp+24h] [ebp-8h] BYREF
  float szKeyNamea; // [esp+34h] [ebp+8h]
  float y; // [esp+38h] [ebp+Ch]

  strchr(string: szKeyName, chr: 0x23u);
  if ( v5 != nullptr )
    *v5 = 0;
  if ( _V_stricmp(s1: szKeyName, s2: "rendercolor") == 0 || _V_stricmp(s1: szKeyName, s2: "rendercolor32") == 0 )
  {
    V_StringToColor32(color: &tmp, pString: szValue);
    g = tmp.g;
    if ( this->m_clrRender.m_Value.r != tmp.r )
      this->m_clrRender.m_Value.r = tmp.r;
    if ( this->m_clrRender.m_Value.g != g )
      this->m_clrRender.m_Value.g = g;
    if ( this->m_clrRender.m_Value.b != tmp.b )
      this->m_clrRender.m_Value.b = tmp.b;
    C_BaseEntity::SetRenderAlpha(this, a: tmp.a);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "renderamt") == 0 )
  {
    v6 = V_atoi(str: szValue);
    C_BaseEntity::SetRenderAlpha(this, a: v6);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "disableshadows") == 0 )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      this->m_fEffects |= 0x10u;
      goto LABEL_10;
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "drawinfastreflection") == 0 )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      this->m_fEffects |= 0x400u;
      if ( (this->m_fEffects & 4) != 0 )
        C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_PRERENDER);
      C_BaseEntity::OnFastReflectionRenderingChanged(this);
      C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
      C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
      return true;
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "disableshadowdepth") == 0 )
  {
    if ( atoi(nptr: szValue) == 0 )
      return true;
    this->m_fEffects |= 0x800u;
LABEL_10:
    if ( (this->m_fEffects & 4) != 0 )
      C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_PRERENDER);
    goto LABEL_12;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "shadowdepthnocache") == 0 )
  {
    v8 = atoi(nptr: szValue);
    if ( v8 != 1 )
    {
      if ( v8 == 2 )
      {
        this->m_fEffects &= ~0x1000u;
LABEL_12:
        C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
        C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
        return true;
      }
      return true;
    }
    this->m_fEffects |= 0x1000u;
    goto LABEL_10;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "mins") == 0 )
  {
    UTIL_StringToVector((float *)&pVector, pString: szValue);
    v9 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
    CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: (const Vector *)&pVector, maxs: v9);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "maxs") == 0 )
  {
    UTIL_StringToVector((float *)&pVector, pString: szValue);
    v10 = this->m_Collision.OBBMins(this: &this->m_Collision);
    CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: v10, maxs: (const Vector *)&pVector);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "disablereceiveshadows") == 0 )
  {
    if ( atoi(nptr: szValue) == 0 )
      return true;
    this->m_fEffects |= 0x40u;
    goto LABEL_10;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "disableflashlight") == 0 )
  {
    if ( atoi(nptr: szValue) == 0 )
      return true;
    this->m_fEffects |= 0x2000u;
    goto LABEL_10;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "nodamageforces") == 0 )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      this->m_iEFlags |= 0x80000000;
      return true;
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "angle") != 0 )
  {
    if ( _V_stricmp(s1: szKeyName, s2: "angles") != 0 )
    {
      if ( _V_stricmp(s1: szKeyName, s2: "origin") != 0 )
      {
        if ( _V_stricmp(s1: szKeyName, s2: "mincpulevel") != 0 )
        {
          if ( _V_stricmp(s1: szKeyName, s2: "maxcpulevel") != 0 )
          {
            if ( _V_stricmp(s1: szKeyName, s2: "mingpulevel") != 0 )
            {
              if ( _V_stricmp(s1: szKeyName, s2: "maxgpulevel") != 0 )
              {
                return false;
              }
              else
              {
                this->m_nMaxGPULevel = atoi(nptr: szValue);
                return true;
              }
            }
            else
            {
              this->m_nMinGPULevel = atoi(nptr: szValue);
              return true;
            }
          }
          else
          {
            this->m_nMaxCPULevel = atoi(nptr: szValue);
            return true;
          }
        }
        else
        {
          this->m_nMinCPULevel = atoi(nptr: szValue);
          return true;
        }
      }
      else
      {
        UTIL_StringToVector((float *)&pVector, pString: szValue);
        C_BaseEntity::SetAbsOrigin(this, absOrigin: (const Vector *)&pVector);
        return true;
      }
    }
    else
    {
      UTIL_StringToVector((float *)&pVector, pString: szValue);
      C_BaseEntity::SetAbsAngles(this, absAngles: (const QAngle *)&pVector);
      return true;
    }
  }
  else
  {
    v11 = atof(nptr: szValue);
    y = v11;
    if ( v11 < 0.0 )
    {
      if ( (int)y == -1 )
        V_strncpy(pDest: szBuf, pSrc: "-90 0 0", maxLen: 64);
      else
        V_strncpy(pDest: szBuf, pSrc: "90 0 0", maxLen: 64);
    }
    else
    {
      szKeyNamea = C_BaseEntity::GetLocalAngles(this)->z;
      LocalAngles = C_BaseEntity::GetLocalAngles(this);
      V_snprintf(pDest: szBuf, maxLen: 64, pFormat: "%f %f %f", LocalAngles->x, y, szKeyNamea);
    }
    return this->KeyValue(this, a2: szKeyName, a3: szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100169A0
// Name: public: int C_BaseEntity::RegisterThinkContext(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::RegisterThinkContext(C_BaseEntity *this, const char *szContext)
{
  int result; // eax
  thinkfunc_t sNewFunc; // [esp+8h] [ebp-30h] BYREF
  __int64 v5; // [esp+28h] [ebp-10h]
  unsigned __int64 v6; // [esp+30h] [ebp-8h]

  result = C_BaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
  if ( result == -1 )
  {
    _V_memset(dest: &sNewFunc, fill: 0, count: 32);
    v5 = 0;
    *(_QWORD *)&sNewFunc.m_pfnThink = 0;
    v6 = 0xFFFFFFFF00000000uLL;
    *((_QWORD *)&sNewFunc.m_pfnThink + 1) = 0xFFFFFFFF00000000uLL;
    sNewFunc.m_nNextThinkTick = 0;
    sNewFunc.m_iszContext = AllocPooledString(pszValue: szContext);
    return CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>::InsertBefore(
             this: &this->m_aThinkFunctions,
             elem: this->m_aThinkFunctions.m_Size,
             src: &sNewFunc);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016B00
// Name: public: void C_BaseEntity::SetNextThink(float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetNextThink(C_BaseEntity *this, float thinkTime, const char *szContext)
{
  int v4; // edi
  bool v5; // zf
  int m_iEFlags; // edi
  int IndexForThinkContext; // eax

  if ( thinkTime == -1.0 )
    v4 = -1;
  else
    v4 = (int)(float)((float)(thinkTime / *(float *)(gpGlobals.m_Index + 28)) + 0.5);
  if ( szContext != nullptr )
  {
    IndexForThinkContext = C_BaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
    if ( IndexForThinkContext == -1 )
      IndexForThinkContext = C_BaseEntity::RegisterThinkContext(this, szContext);
    this->m_aThinkFunctions.m_Memory.m_pMemory[IndexForThinkContext].m_nNextThinkTick = v4;
  }
  else
  {
    this->m_nNextThinkTick = v4;
  }
  v5 = v4 == -1;
  m_iEFlags = this->m_iEFlags;
  if ( (m_iEFlags & 0x400000) != 0 )
  {
    if ( !v5 )
    {
      this->m_iEFlags = m_iEFlags & 0xFFBFFFFF;
      return;
    }
  }
  else if ( !v5 )
  {
    return;
  }
  if ( (this->m_iEFlags & 0x400000) == 0 && C_BaseEntity::WillThink(this) == 0 )
    this->m_iEFlags = m_iEFlags | 0x400000;
}

//------------------------------------------------------------------------------
// Address: 0x10016BC0
// Name: private: void C_BaseEntity::SetNextThink(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetNextThink(C_BaseEntity *this, int nContextIndex, float thinkTime)
{
  int v4; // ebx
  int v5; // eax
  int m_iEFlags; // edi
  int v7; // edi

  if ( thinkTime == -1.0 )
    v4 = -1;
  else
    v4 = (int)(float)((float)(thinkTime / *(float *)(gpGlobals.m_Index + 28)) + 0.5);
  if ( nContextIndex >= 0 )
  {
    this->m_aThinkFunctions.m_Memory.m_pMemory[nContextIndex].m_nNextThinkTick = v4;
  }
  else
  {
    if ( thinkTime == -1.0 )
      v5 = -1;
    else
      v5 = (int)(float)((float)(thinkTime / *(float *)(gpGlobals.m_Index + 28)) + 0.5);
    m_iEFlags = this->m_iEFlags;
    this->m_nNextThinkTick = v5;
    if ( (m_iEFlags & 0x400000) != 0 )
    {
      if ( v5 != -1 )
      {
        this->m_iEFlags = m_iEFlags & 0xFFBFFFFF;
        goto LABEL_16;
      }
    }
    else if ( v5 != -1 )
    {
      goto LABEL_16;
    }
    if ( (m_iEFlags & 0x400000) == 0 && C_BaseEntity::WillThink(this) == 0 )
      this->m_iEFlags = m_iEFlags | 0x400000;
  }
LABEL_16:
  v7 = this->m_iEFlags;
  if ( (v7 & 0x400000) != 0 )
  {
    if ( v4 != -1 )
    {
      this->m_iEFlags = v7 & 0xFFBFFFFF;
      return;
    }
  }
  else if ( v4 != -1 )
  {
    return;
  }
  if ( (this->m_iEFlags & 0x400000) == 0 && C_BaseEntity::WillThink(this) == 0 )
    this->m_iEFlags = v7 | 0x400000;
}

//------------------------------------------------------------------------------
// Address: 0x10016CD0
// Name: public: virtual void C_BaseEntity::FireBullets(struct FireBulletsInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_BaseEntity::FireBullets(
        C_BaseEntity *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const FireBulletsInfo_t *info)
{
  float v5; // edi
  CCSAmmoDef *AmmoDef; // eax
  int v7; // eax
  char v8; // al
  unsigned __int8 (__thiscall *v9)(_DWORD, int, int); // eax
  unsigned __int8 (__thiscall *v10)(_DWORD); // eax
  int x_low; // xmm0_4
  float y; // xmm0_4
  bool v13; // cc
  unsigned __int8 (__thiscall *v14)(_DWORD, C_BaseEntity *); // eax
  int m_iObjectsPenetrated; // xmm4_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  const Vector *v18; // eax
  unsigned __int8 (__thiscall *v19)(_DWORD); // edx
  float m_flDistance; // xmm1_4
  int v21; // xmm2_4
  float v22; // xmm0_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  float x; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float m_flDamageForceScale; // xmm0_4
  int v28; // eax
  float m_flDamage; // xmm0_4
  C_BaseEntity *v30; // eax
  int v31; // eax
  int v32; // ecx
  float v33; // xmm0_4
  const char *v34; // eax
  int m_iTracerFreq; // ecx
  int v36; // edx
  int v37; // eax
  int v38; // edi
  int v39; // eax
  bool v40; // sf
  IHandleEntity *m_pPassEnt; // eax
  int m_iAmmoType; // [esp+44h] [ebp-270h]
  int v43; // [esp+44h] [ebp-270h]
  struct CBaseEntity *m_pAdditionalIgnoreEnt; // [esp+44h] [ebp-270h]
  float v46; // [esp+58h] [ebp-25Ch] BYREF
  float v47; // [esp+5Ch] [ebp-258h]
  float v48; // [esp+60h] [ebp-254h]
  CTakeDamageInfo triggerInfo; // [esp+64h] [ebp-250h] BYREF
  float z; // [esp+C0h] [ebp-1F4h]
  CShotManipulator Manipulator; // [esp+C4h] [ebp-1F0h] BYREF
  CEffectData data; // [esp+F4h] [ebp-1C0h] BYREF
  int v53; // [esp+158h] [ebp-15Ch]
  int v54; // [esp+15Ch] [ebp-158h]
  Vector v55; // [esp+160h] [ebp-154h] BYREF
  Vector v56; // [esp+16Ch] [ebp-148h] BYREF
  Vector vecTracerSrc; // [esp+178h] [ebp-13Ch] BYREF
  CGameTrace Tracer; // [esp+184h] [ebp-130h] BYREF
  Vector v59; // [esp+1E0h] [ebp-D4h] BYREF
  _BYTE tr[88]; // [esp+1ECh] [ebp-C8h] OVERLAPPED BYREF
  int nActualDamageType; // [esp+244h] [ebp-70h]
  Vector vecTracerDest; // [esp+248h] [ebp-6Ch] BYREF
  CTraceFilterSimpleList traceFilter; // [esp+254h] [ebp-60h] BYREF
  Vector vecEnd; // [esp+278h] [ebp-3Ch] BYREF
  float v65; // [esp+284h] [ebp-30h]
  Vector vecDir; // [esp+288h] [ebp-2Ch]
  CAmmoDef *pAmmoDef; // [esp+294h] [ebp-20h]
  float flActualDamage; // [esp+298h] [ebp-1Ch]
  int flPlayerDamage; // [esp+29Ch] [ebp-18h]
  int iShot; // [esp+2A0h] [ebp-14h]
  C_BaseEntity *pAttacker; // [esp+2A4h] [ebp-10h]
  int iSeed; // [esp+2A8h] [ebp-Ch]
  int nDamageType; // [esp+2ACh] [ebp-8h]
  int retaddr; // [esp+2B4h] [ebp+0h]

  iSeed = a2;
  nDamageType = retaddr;
  v5 = *(float *)&this;
  LODWORD(vecEnd.x) = this;
  AmmoDef = GetAmmoDef();
  m_iAmmoType = info->m_iAmmoType;
  LODWORD(vecDir.x) = AmmoDef;
  v7 = CAmmoDef::DamageType(this: AmmoDef, nAmmoIndex: m_iAmmoType);
  v43 = info->m_iAmmoType;
  iShot = v7;
  v8 = CAmmoDef::Flags(this: (CAmmoDef *)LODWORD(vecDir.x), nAmmoIndex: v43);
  vecDir.z = info->m_flPlayerDamage;
  if ( vecDir.z == 0.0 && (v8 & 2) != 0 )
    vecDir.z = (float)CAmmoDef::PlrDamage(this: (CAmmoDef *)LODWORD(vecDir.x), nAmmoIndex: info->m_iAmmoType);
  flActualDamage = *(float *)&info->m_pAttacker;
  if ( flActualDamage == 0.0 )
    flActualDamage = v5;
  if ( g_MultiDamage.m_hTarget.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber == HIWORD(g_MultiDamage.m_hTarget.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity != nullptr )
  {
    ApplyMultiDamage();
  }
  ClearMultiDamage();
  g_MultiDamage.m_bitsDamageType = iShot | 0x1000;
  CTraceFilterSimpleList::CTraceFilterSimpleList(this: (CTraceFilterSimpleList *)&vecTracerDest, collisionGroup: 0);
  m_pAdditionalIgnoreEnt = info->m_pAdditionalIgnoreEnt;
  vecTracerDest.y = v5;
  CTraceFilterSimpleList::AddEntityToIgnore(
    this: (CTraceFilterSimpleList *)&vecTracerDest,
    pEntity: (IHandleEntity *)m_pAdditionalIgnoreEnt);
  v9 = *(unsigned __int8 (__thiscall **)(_DWORD, int, int))(*(_DWORD *)LODWORD(v5) + 80);
  BYTE2(pAttacker) = 0;
  if ( v9(a1: LODWORD(v5), a2: a3, a3: a4) != 0 )
    BYTE2(pAttacker) = (enginetrace->GetPointContents(this: enginetrace, a2: &info->m_vecSrc, a3: 16432, a4: nullptr)
                      & 0x30) != 0;
  v10 = *(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(v5) + 584);
  flPlayerDamage = 0;
  if ( v10(a1: LODWORD(v5)) != 0 )
    flPlayerDamage = (unsigned __int8)C_BaseEntity::m_nPredictionRandomSeed;
  x_low = LODWORD(info->m_vecDirShooting.x);
  iShot = (int)&Manipulator.m_vecRight;
  triggerInfo.m_iObjectsPenetrated = x_low;
  y = info->m_vecDirShooting.y;
  flPlayerDamage = (int)&Manipulator;
  *(float *)&triggerInfo.m_uiBulletID = y;
  z = info->m_vecDirShooting.z;
  VectorVectors(
    forward: (const Vector *)&triggerInfo.m_iObjectsPenetrated,
    right: &Manipulator.m_vecShotDirection,
    up: &Manipulator.m_vecRight);
  v13 = info->m_iShots <= 0;
  pAmmoDef = nullptr;
  if ( !v13 )
  {
    do
    {
      v14 = *(unsigned __int8 (__thiscall **)(_DWORD, C_BaseEntity *))(*(_DWORD *)LODWORD(v5) + 584);
      HIBYTE(pAttacker) = 0;
      if ( v14(a1: LODWORD(v5), a2: pAttacker) != 0 )
        _RandomSeed(a1: flPlayerDamage);
      if ( pAmmoDef != nullptr || info->m_iShots <= 1 || (info->m_nFlags & 1) == 0 )
      {
        v18 = CShotManipulator::ApplySpread(
                this: (CShotManipulator *)&triggerInfo.m_iObjectsPenetrated,
                vecSpread: &info->m_vecSpread,
                bias: 1.0);
        m_iObjectsPenetrated = SLODWORD(v18->x);
        vecEnd.y = v18->x;
        v16 = v18->y;
        vecEnd.z = v16;
        v17 = v18->z;
      }
      else
      {
        m_iObjectsPenetrated = triggerInfo.m_iObjectsPenetrated;
        v16 = *(float *)&triggerInfo.m_uiBulletID;
        v17 = z;
        LODWORD(vecEnd.y) = triggerInfo.m_iObjectsPenetrated;
        LODWORD(vecEnd.z) = triggerInfo.m_uiBulletID;
      }
      v19 = *(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(v5) + 584);
      m_flDistance = info->m_flDistance;
      *(float *)&v21 = (float)(v16 * m_flDistance) + info->m_vecSrc.y;
      v22 = (float)(m_flDistance * v17) + info->m_vecSrc.z;
      v65 = v17;
      *(float *)&traceFilter.m_PassEntities.m_Memory.m_nGrowSize = info->m_vecSrc.x
                                                                 + (float)(m_flDistance * *(float *)&m_iObjectsPenetrated);
      traceFilter.m_PassEntities.m_Size = v21;
      *(float *)&traceFilter.m_PassEntities.m_pElements = v22;
      if ( v19(a1: LODWORD(v5)) != 0 && info->m_iShots > 1 && (int)pAmmoDef % 2 != 0 )
      {
        data.m_iEffectName = 1077936128;
        v53 = 1077936128;
        v54 = 1077936128;
        v55.x = -3.0;
        v55.y = -3.0;
        v55.z = -3.0;
        *(_DWORD *)&Tracer.dispFlags = 0;
        Ray_t::Init(
          this: (Ray_t *)&vecTracerSrc,
          start: &info->m_vecSrc,
          end: (const Vector *)&traceFilter.m_PassEntities.m_Memory.m_nGrowSize,
          mins: &v55,
          maxs: (const Vector *)&data.m_iEffectName);
        TraceRay = enginetrace->TraceRay;
        pAttacker = (C_BaseEntity *)&v59;
        ((void (__thiscall *)(IEngineTrace *, Vector *, int, Vector *))TraceRay)(
          a1: enginetrace,
          a2: &vecTracerSrc,
          a3: 1174421507,
          a4: &vecTracerDest);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        {
          iShot = -1082130432;
          flPlayerDamage = 1;
          flActualDamage = 0.0;
          pAmmoDef = (CAmmoDef *)255;
LABEL_31:
          DebugDrawLine(
            vecAbsStart: &v59,
            vecAbsEnd: (const Vector *)tr,
            r: 255,
            g: (int)pAmmoDef,
            b: SLODWORD(flActualDamage),
            test: flPlayerDamage,
            duration: *(float *)&iShot);
        }
      }
      else
      {
        x = info->m_vecSrc.x;
        v25 = info->m_vecSrc.y;
        v26 = info->m_vecSrc.z;
        Tracer.startpos.z = *(float *)&traceFilter.m_PassEntities.m_Size - v25;
        Tracer.startpos.y = *(float *)&traceFilter.m_PassEntities.m_Memory.m_nGrowSize - x;
        Tracer.endpos.x = *(float *)&traceFilter.m_PassEntities.m_pElements - v26;
        BYTE1(Tracer.fractionleftsolid) = (float)((float)((float)(Tracer.startpos.z * Tracer.startpos.z)
                                                        + (float)(Tracer.startpos.y * Tracer.startpos.y))
                                                + (float)(Tracer.endpos.x * Tracer.endpos.x)) != 0.0;
        pAttacker = (C_BaseEntity *)&v59;
        memset(&Tracer.plane.dist, 0, 12);
        *(_DWORD *)&Tracer.dispFlags = 0;
        LOBYTE(Tracer.fractionleftsolid) = 1;
        memset(&Tracer.endpos.z, 0, 12);
        vecTracerSrc.x = x;
        vecTracerSrc.y = v25;
        vecTracerSrc.z = v26;
        ((void (__thiscall *)(IEngineTrace *, Vector *, int, Vector *))enginetrace->TraceRay)(
          a1: enginetrace,
          a2: &vecTracerSrc,
          a3: 1174421507,
          a4: &vecTracerDest);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        {
          iShot = -1082130432;
          flPlayerDamage = 1;
          flActualDamage = 0.0;
          pAmmoDef = nullptr;
          goto LABEL_31;
        }
      }
      if ( tr[43] != 0 )
      {
        *(Vector *)tr = v59;
        *(_DWORD *)&tr[32] = 0;
      }
      if ( BYTE2(pAttacker) != 0 )
        HIBYTE(pAttacker) = 1;
      CTakeDamageInfo::CTakeDamageInfo(
        this: (CTakeDamageInfo *)&v46,
        pInflictor: (C_BaseEntity *)LODWORD(flActualDamage),
        pAttacker: (C_BaseEntity *)LODWORD(flActualDamage),
        flDamage: info->m_flDamage,
        bitsDamageType: iShot,
        iKillType: 0,
        iObjectsPenetrated: 0);
      CalculateBulletDamageForce(
        info: (CTakeDamageInfo *)&v46,
        iBulletType: info->m_iAmmoType,
        vecBulletDir: (Vector *)&vecEnd.y,
        vecForceOrigin: (const Vector *)tr,
        flScale: 1.0);
      m_flDamageForceScale = info->m_flDamageForceScale;
      v28 = info->m_iAmmoType;
      v46 = v46 * m_flDamageForceScale;
      v47 = v47 * m_flDamageForceScale;
      v48 = v48 * m_flDamageForceScale;
      triggerInfo.m_bitsDamageType = v28;
      if ( v28 == -1 )
      {
        DevMsg(a1: "ERROR: Undefined ammo type!\n");
        break;
      }
      *(_QWORD *)&tr[80] = *(_QWORD *)tr;
      nActualDamageType = *(_DWORD *)&tr[8];
      if ( *(float *)&tr[32] != 1.0 )
      {
        if ( HIBYTE(pAttacker) == 0
          && (enginetrace->GetPointContents(this: enginetrace, a2: (const Vector *)tr, a3: 16432, a4: nullptr) & 0x30) != 0 )
        {
          HIBYTE(pAttacker) = (*(int (__thiscall **)(float, const FireBulletsInfo_t *, int *, Vector *, _BYTE *))(*(_DWORD *)LODWORD(v5) + 88))(
                                a1: COERCE_FLOAT(LODWORD(v5)),
                                a2: info,
                                a3: &traceFilter.m_PassEntities.m_Memory.m_nGrowSize,
                                a4: &vecTracerDest,
                                a5: &tr[80]);
        }
        m_flDamage = info->m_flDamage;
        vecDir.y = m_flDamage;
        if ( vecDir.z != 0.0 )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&tr[64] + 584))(a1: *(_DWORD *)&tr[64]) != 0 )
            m_flDamage = vecDir.z;
          else
            m_flDamage = vecDir.y;
        }
        *(_DWORD *)&tr[76] = iShot;
        if ( m_flDamage == 0.0 )
        {
          vecDir.y = g_pGameRules->GetAmmoDamage(
                       this: g_pGameRules,
                       a2: (C_BaseEntity *)LODWORD(flActualDamage),
                       a3: *(C_BaseEntity **)&tr[64],
                       a4: info->m_iAmmoType);
          m_flDamage = vecDir.y;
          v30 = *(C_BaseEntity **)&tr[76];
        }
        else
        {
          v31 = 0x2000;
          if ( m_flDamage <= 16.0 )
            v31 = 4096;
          v30 = (C_BaseEntity *)(iShot | v31);
        }
        if ( HIBYTE(pAttacker) == 0 || (info->m_nFlags & 2) == 0 )
        {
          CTakeDamageInfo::CTakeDamageInfo(
            this: (CTakeDamageInfo *)&vecTracerSrc,
            pInflictor: (C_BaseEntity *)LODWORD(v5),
            pAttacker: v30,
            flDamage: m_flDamage,
            bitsDamageType: (int)v30,
            iKillType: 0,
            iObjectsPenetrated: 0);
          iShot = v32;
          CalculateBulletDamageForce(
            info: (CTakeDamageInfo *)&vecTracerSrc,
            iBulletType: info->m_iAmmoType,
            vecBulletDir: (Vector *)&vecEnd.y,
            vecForceOrigin: (const Vector *)tr,
            flScale: 1.0);
          v33 = info->m_flDamageForceScale;
          v34 = (const char *)info->m_iAmmoType;
          vecTracerSrc.x = vecTracerSrc.x * v33;
          Tracer.surface.name = v34;
          vecTracerSrc.y = vecTracerSrc.y * v33;
          iShot = (int)&v59;
          flPlayerDamage = (int)&vecEnd.y;
          vecTracerSrc.z = vecTracerSrc.z * v33;
          (*(void (__thiscall **)(_DWORD, Vector *, float *, Vector *))(**(_DWORD **)&tr[64] + 96))(
            a1: *(_DWORD *)&tr[64],
            a2: &vecTracerSrc,
            a3: &vecEnd.y,
            a4: &v59);
          if ( *(_DWORD *)&tr[64] != 0 )
            (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&tr[64] + 592))(a1: *(_DWORD *)&tr[64]);
          if ( BYTE2(pAttacker) != 0 || HIBYTE(pAttacker) == 0 || (info->m_nFlags & 4) != 0 )
          {
            (*(void (__thiscall **)(float, Vector *, int))(*(_DWORD *)LODWORD(v5) + 104))(
              a1: COERCE_FLOAT(LODWORD(v5)),
              a2: &v59,
              a3: iShot);
          }
          else
          {
            memset((void *)&data.m_vStart, 0, 28);
            memset(&data.m_fFlags, 0, 14);
            data.m_vOrigin = v59;
            data.m_flRadius = 0.0;
            memset(&data.m_nSurfaceProp, 0, 9);
            Manipulator.m_vecResult = *(Vector *)tr;
            data.m_vAngles.y = NAN;
            data.m_vAngles.z = 1.0;
            data.m_nAttachmentIndex = iShot;
            DispatchEffect(pName: "RagdollImpact", data: (const CEffectData *)&Manipulator.m_vecResult);
          }
        }
      }
      m_iTracerFreq = info->m_iTracerFreq;
      if ( m_iTracerFreq != 0 )
      {
        v36 = tracerCount % m_iTracerFreq;
        ++tracerCount;
        if ( v36 == 0 )
        {
          v56 = vec3_origin;
          C_BaseEntity::ComputeTracerStartPosition(
            this: (C_BaseEntity *)LODWORD(v5),
            vecShotSrc: &info->m_vecSrc,
            pVecTracerStart: &v56);
          CGameTrace::operator=(this: (CGameTrace *)&vecTracerSrc.z, __that: (const CGameTrace *)&v59);
          v37 = info->m_iAmmoType;
          v38 = *(_DWORD *)LODWORD(v5);
          Tracer.startpos.z = *(float *)&tr[80];
          Tracer.endpos.x = *(float *)&tr[84];
          LODWORD(Tracer.endpos.y) = nActualDamageType;
          v39 = CAmmoDef::TracerType(this: (CAmmoDef *)LODWORD(vecDir.x), nAmmoIndex: v37);
          (*(void (__thiscall **)(_DWORD, Vector *, float *, int))(v38 + 108))(
            a1: LODWORD(vecEnd.x),
            a2: &v56,
            a3: &vecTracerSrc.z,
            a4: v39);
          v5 = vecEnd.x;
        }
      }
      ++flPlayerDamage;
      pAmmoDef = (CAmmoDef *)((char *)pAmmoDef + 1);
    }
    while ( (int)pAmmoDef < info->m_iShots );
  }
  v40 = (int)traceFilter.m_pExtraShouldHitCheckFunction < 0;
  m_pPassEnt = (IHandleEntity *)traceFilter.m_pPassEnt;
  traceFilter.m_PassEntities.m_Memory.m_pMemory = nullptr;
  if ( (int)traceFilter.m_pExtraShouldHitCheckFunction >= 0 )
  {
    if ( traceFilter.m_pPassEnt != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)traceFilter.m_pPassEnt);
      m_pPassEnt = nullptr;
      traceFilter.m_pPassEnt = nullptr;
    }
    v40 = (int)traceFilter.m_pExtraShouldHitCheckFunction < 0;
    traceFilter.m_collisionGroup = 0;
  }
  traceFilter.m_PassEntities.m_Memory.m_nAllocationCount = (int)m_pPassEnt;
  if ( !v40 && m_pPassEnt != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pPassEnt);
}

//------------------------------------------------------------------------------
// Address: 0x100186C0
// Name: public: bool Vector::operator!=(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector::operator!=(Vector *this, const Vector *src)
{
  return src->x != this->x || src->y != this->y || src->z != this->z;
}

//------------------------------------------------------------------------------
// Address: 0x10016A20
// Name: public: void (C_BaseEntity::*C_BaseEntity::ThinkSet(void (C_BaseEntity::*)(void),float,char const __near *))(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::ThinkSet(
        C_BaseEntity *this,
        int a2,
        __int128 func,
        float thinkTime,
        const char *szContext)
{
  const char *v5; // edi
  __int64 v7; // xmm0_8
  __int64 v9; // xmm1_8
  int IndexForThinkContext; // eax
  int v11; // ecx
  int v12; // eax

  v5 = szContext;
  if ( szContext != nullptr )
  {
    IndexForThinkContext = C_BaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
    if ( IndexForThinkContext == -1 )
      IndexForThinkContext = C_BaseEntity::RegisterThinkContext(this, szContext: v5);
    v11 = IndexForThinkContext;
    this->m_aThinkFunctions.m_Memory.m_pMemory[IndexForThinkContext].m_pfnThink = func;
    if ( thinkTime != 0.0 )
    {
      if ( thinkTime == -1.0 )
        v12 = -1;
      else
        v12 = (int)(float)((float)(thinkTime / *(float *)(gpGlobals.m_Index + 28)) + 0.5);
      this->m_aThinkFunctions.m_Memory.m_pMemory[v11].m_nNextThinkTick = v12;
      C_BaseEntity::CheckHasThinkFunction(this, isThinking: v12 != -1);
    }
    *(_OWORD *)a2 = func;
    return a2;
  }
  else
  {
    v7 = func;
    v9 = *((_QWORD *)&func + 1);
    this->m_pfnThink = func;
    *(_QWORD *)a2 = v7;
    *(_QWORD *)(a2 + 8) = v9;
    return a2;
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100CAE60
// Name: void SpawnBlood(class Vector,class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpawnBlood(Vector vecSpot, const Vector *vecDir, int bloodColor, float flDamage)
{
  UTIL_BloodDrips(origin: &vecSpot, direction: vecDir, color: bloodColor, amount: (int)flDamage);
}

//------------------------------------------------------------------------------
// Address: 0x100CAE80
// Name: public: virtual class Vector CBaseEntity::EarPosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseEntity::EarPosition(CAI_BaseNPC *this, Vector *result)
{
  this->EyePosition(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CAEA0
// Name: public: void CBaseEntity::ParseMapData(class CEntityMapData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ParseMapData(CBaseEntity *this, CEntityMapData *mapData)
{
  char keyName[2048]; // [esp+8h] [ebp-1000h] BYREF
  char value[2048]; // [esp+808h] [ebp-800h] BYREF

  if ( CEntityMapData::GetFirstKey(this: mapData, keyName, value) )
  {
    do
      this->KeyValue_4(this, a2: keyName, a3: value);
    while ( CEntityMapData::GetNextKey(this: mapData, keyName, value) );
  }
  this->OnParseMapDataFinished(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CAF20
// Name: public: virtual bool CBaseEntity::KeyValue(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __thiscall CBaseEntity::KeyValue(CBaseEntity *this, const char *szKeyName, float flValue)
{
  char string[256]; // [esp+Ch] [ebp-100h] BYREF

  V_snprintf(pDest: string, maxLen: 256, pFormat: "%f", flValue);
  return ((int (__thiscall *)(CBaseEntity *, const char *, char *))this->KeyValue_4)(
           a1: this,
           a2: szKeyName,
           a3: string);
}

//------------------------------------------------------------------------------
// Address: 0x100CAF80
// Name: public: virtual bool CBaseEntity::KeyValue(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::KeyValue(CBaseEntity *this, const char *szKeyName, int nValue)
{
  char string[256]; // [esp+4h] [ebp-100h] BYREF

  V_snprintf(pDest: string, maxLen: 256, pFormat: "%d", nValue);
  return this->KeyValue_4(this, a2: szKeyName, a3: string);
}

//------------------------------------------------------------------------------
// Address: 0x100CAFD0
// Name: public: virtual bool CBaseEntity::KeyValue(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __thiscall CBaseEntity::KeyValue(CBaseEntity *this, const char *szKeyName, const Vector *vecValue)
{
  char string[256]; // [esp+1Ch] [ebp-100h] BYREF

  V_snprintf(pDest: string, maxLen: 256, pFormat: "%f %f %f", vecValue->x, vecValue->y, vecValue->z);
  return ((int (__thiscall *)(CBaseEntity *, const char *, char *))this->KeyValue_4)(
           a1: this,
           a2: szKeyName,
           a3: string);
}

//------------------------------------------------------------------------------
// Address: 0x100CB050
// Name: public: static void CBaseEntity::SetPredictionRandomSeed(class CUserCmd const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::SetPredictionRandomSeed(const CUserCmd *cmd)
{
  if ( cmd != nullptr )
    CBaseEntity::m_nPredictionRandomSeed = cmd->random_seed;
  else
    CBaseEntity::m_nPredictionRandomSeed = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100CB070
// Name: public: virtual void CBaseEntity::VPhysicsDestroyObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::VPhysicsDestroyObject(CBaseEntity *this)
{
  if ( this->m_pPhysicsObject != nullptr )
  {
    PhysRemoveShadow(pEntity: this);
    PhysDestroyObject(pObject: this->m_pPhysicsObject, pEntity: this);
    this->m_pPhysicsObject = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB0A0
// Name: public: static bool CBaseEntity::IsPrecacheAllowed(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBaseEntity::IsPrecacheAllowed()
{
  return CBaseEntity::m_bAllowPrecache;
}

//------------------------------------------------------------------------------
// Address: 0x100CB0B0
// Name: public: static void CBaseEntity::SetAllowPrecache(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::SetAllowPrecache(bool allow)
{
  CBaseEntity::m_bAllowPrecache = allow;
}

//------------------------------------------------------------------------------
// Address: 0x100CB0C0
// Name: public: void CBaseEntity::DispatchTraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DispatchTraceAttack(
        CBaseEntity *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  if ( this->PassesDamageFilter(this, a2: info) )
    this->TraceAttack(this, a2: info, a3: vecDir, a4: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x100CB100
// Name: public: virtual void CBaseEntity::DoImpactEffect(class CGameTrace __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DoImpactEffect(CBaseEntity *this, CGameTrace *tr, int nDamageType)
{
  UTIL_ImpactTrace(pTrace: tr, iDamageType: nDamageType, pCustomImpactName: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100CB120
// Name: public: virtual int CBaseEntity::GetTracerAttachment(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetTracerAttachment(CBaseEntity *this)
{
  bool v1; // zf
  int result; // eax

  v1 = !g_pGameRules->IsMultiplayer(this: g_pGameRules);
  result = 1;
  if ( v1 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB140
// Name: public: int CBaseEntity::GetWaterType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetWaterType(CBaseEntity *this)
{
  unsigned __int8 m_nWaterType; // cl
  int result; // eax

  m_nWaterType = this->m_nWaterType;
  result = 0;
  if ( (m_nWaterType & 1) != 0 )
    result = 32;
  if ( (m_nWaterType & 2) != 0 )
    return result | 0x10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB160
// Name: public: void CBaseEntity::SetWaterType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetWaterType(CBaseEntity *this, char nType)
{
  this->m_nWaterType = 0;
  if ( (nType & 0x20) != 0 )
    this->m_nWaterType = 1;
  if ( (nType & 0x10) != 0 )
    this->m_nWaterType |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x100CB190
// Name: public: virtual class Vector CBaseEntity::EyePosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseEntity::EyePosition(CBaseEntity *this, Vector *result)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  result->x = this->m_vecViewOffset.m_Value.x + this->m_vecAbsOrigin.x;
  result->y = this->m_vecViewOffset.m_Value.y + this->m_vecAbsOrigin.y;
  result->z = this->m_vecViewOffset.m_Value.z + this->m_vecAbsOrigin.z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB1F0
// Name: public: virtual class Vector const __near & CBaseEntity::GetViewOffset(void)const
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorXYZBase<Vector,CBaseEntity::NetworkVar_m_vecViewOffset> *__thiscall CBaseEntity::GetViewOffset(
        CBaseEntity *this)
{
  return &this->m_vecViewOffset;
}

//------------------------------------------------------------------------------
// Address: 0x100CB200
// Name: public: void CBaseEntity::SetBlocksLOS(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetBlocksLOS(CBaseEntity *this, bool bBlocksLOS)
{
  if ( bBlocksLOS )
    this->m_iEFlags &= ~0x2000000u;
  else
    this->m_iEFlags |= 0x2000000u;
}

//------------------------------------------------------------------------------
// Address: 0x100CB230
// Name: public: bool CBaseEntity::BlocksLOS(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::BlocksLOS(CBaseEntity *this)
{
  return (this->m_iEFlags & 0x2000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CB240
// Name: public: void CBaseEntity::SetAIWalkable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetAIWalkable(CBaseEntity *this, bool bBlocksLOS)
{
  if ( bBlocksLOS )
    this->m_iEFlags &= ~0x4000000u;
  else
    this->m_iEFlags |= 0x4000000u;
}

//------------------------------------------------------------------------------
// Address: 0x100CB270
// Name: public: bool CBaseEntity::IsAIWalkable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::IsAIWalkable(CBaseEntity *this)
{
  return (this->m_iEFlags & 0x4000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CB280
// Name: public: virtual bool CBaseEntity::ShouldCollide(int,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::ShouldCollide(CBaseEntity *this, int collisionGroup, int contentsMask)
{
  bool result; // al

  result = true;
  if ( this->m_CollisionGroup.m_Value == 1 )
    return (contentsMask & 0x4000000) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB2A0
// Name: public: virtual void CBaseEntity::DecalTrace(class CGameTrace __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DecalTrace(CBaseEntity *this, CGameTrace *pTrace, const char *decalName)
{
  int v3; // esi
  ITempEntsSystem_vtbl *v4; // edi
  int EntityIndex; // eax
  int hitbox; // [esp+14h] [ebp-30h]
  CBroadcastRecipientFilter filter; // [esp+24h] [ebp-20h] BYREF

  v3 = decalsystem->GetDecalIndexForName(this: decalsystem, a2: decalName);
  if ( v3 >= 0 )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
    CRecipientFilter::AddAllPlayers(this: &filter);
    v4 = te->__vftable;
    hitbox = pTrace->hitbox;
    EntityIndex = CGameTrace::GetEntityIndex(this: pTrace);
    ((void (__thiscall *)(ITempEntsSystem *, CBroadcastRecipientFilter *, _DWORD, Vector *, CGameTrace *, int, int, int))v4->Decal)(
      a1: te,
      a2: &filter,
      a3: 0,
      a4: &pTrace->endpos,
      a5: pTrace,
      a6: EntityIndex,
      a7: hitbox,
      a8: v3);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB320
// Name: public: virtual void CBaseEntity::ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ImpactTrace(
        CBaseEntity *this,
        CGameTrace *pTrace,
        int iDamageType,
        char *pCustomImpactName)
{
  CBaseEntity *m_pEnt; // edx
  __int16 surfaceProps; // si
  float z; // xmm0_4
  int hitbox; // eax
  edict_t *m_pPev; // eax
  signed int v9; // eax
  CEffectData data; // [esp+0h] [ebp-64h] BYREF

  m_pEnt = pTrace->m_pEnt;
  memset((void *)&data.m_vNormal, 0, 32);
  memset(&data.m_flMagnitude, 0, 12);
  data.m_vOrigin = pTrace->endpos;
  data.m_vStart.x = pTrace->startpos.x;
  surfaceProps = pTrace->surface.surfaceProps;
  data.m_vStart.y = pTrace->startpos.y;
  z = pTrace->startpos.z;
  data.m_flScale = 1.0;
  data.m_nMaterial = 0;
  data.m_nColor = 0;
  data.m_nOtherEntIndex = 0;
  data.m_vStart.z = z;
  data.m_nSurfaceProp = surfaceProps;
  if ( surfaceProps < 0 )
    data.m_nSurfaceProp = 0;
  hitbox = pTrace->hitbox;
  data.m_nDamageType = iDamageType;
  data.m_nHitBox = hitbox;
  m_pPev = m_pEnt->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v9 = m_pPev - gpGlobals->pEdicts;
  else
    v9 = 0;
  data.m_nEntIndex = v9;
  if ( pCustomImpactName != nullptr )
    DispatchEffect(pName: pCustomImpactName, &data);
  else
    DispatchEffect(pName: "Impact", &data);
}

//------------------------------------------------------------------------------
// Address: 0x100CB420
// Name: public: virtual char const __near * CBaseEntity::DamageDecal(int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseEntity::DamageDecal(CBaseEntity *this, int bitsDamageType, int gameMaterial)
{
  unsigned __int8 m_Value; // al
  const char *result; // eax

  m_Value = this->m_nRenderMode.m_Value;
  if ( m_Value == 4 )
    return locale;
  if ( m_Value != 0 && gameMaterial == 71 )
    return "BulletProof";
  result = "ManhackCut";
  if ( bitsDamageType != 4 )
    return "Impact.Concrete";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB460
// Name: public: void CBaseEntity::VPhysicsSwapObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::VPhysicsSwapObject(CBaseEntity *this, IPhysicsObject *pSwap)
{
  const char *pszValue; // eax

  if ( pSwap == nullptr )
    PhysRemoveShadow(pEntity: this);
  if ( this->m_pPhysicsObject == nullptr )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "Bad vphysics swap for %s\n", pszValue);
  }
  this->m_pPhysicsObject = pSwap;
}

//------------------------------------------------------------------------------
// Address: 0x100CB4B0
// Name: public: bool CBaseEntity::IsBSPModel(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::IsBSPModel(CBaseEntity *this)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // esi
  bool result; // al
  IVModelInfo_vtbl *v4; // ebx
  int v5; // eax
  const struct model_t *v6; // edi

  p_m_Collision = &this->m_Collision;
  result = true;
  if ( this->m_Collision.GetSolid(this: &this->m_Collision) != SOLID_BSP )
  {
    v4 = modelinfo->__vftable;
    v5 = this->GetModelIndex(this);
    v6 = v4->GetModel(this: modelinfo, a2: v5);
    if ( p_m_Collision->GetSolid(this: p_m_Collision) != SOLID_VPHYSICS
      || modelinfo->GetModelType(this: modelinfo, a2: v6) != 1 )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB520
// Name: protected: void CBaseEntity::ComputeTracerStartPosition(class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ComputeTracerStartPosition(
        CBaseEntity *this,
        const Vector *vecShotSrc,
        Vector *pVecTracerStart)
{
  bool v4; // al
  float x; // xmm7_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  CBaseCombatCharacter *(__thiscall *MyCombatCharacterPointer)(CBaseEntity *); // edx
  CBaseCombatCharacter *v10; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  Vector vecMuzzle; // [esp+4h] [ebp-18h] BYREF
  QAngle vecMuzzleAngles; // [esp+10h] [ebp-Ch] BYREF

  if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    pVecTracerStart->x = 999.0;
    pVecTracerStart->y = 999.0;
    pVecTracerStart->z = 999.0;
  }
  else if ( this->IsPlayer(this) )
  {
    v4 = this->IsPlayer(this);
    CBasePlayer::EyeVectors(
      this: v4 ? (CBasePlayer *)this : nullptr,
      pForward: (Vector *)&vecMuzzleAngles,
      pRight: &vecMuzzle,
      pUp: nullptr);
    x = vecShotSrc->x;
    v6 = vecMuzzle.y * 2.0;
    vecMuzzle.y = vecShotSrc->y;
    v7 = (float)(vecMuzzle.y + v6) + (float)(vecMuzzleAngles.y * 16.0);
    v8 = (float)((float)(vecShotSrc->z - 4.0) + (float)(vecMuzzle.z * 2.0)) + (float)(vecMuzzleAngles.z * 16.0);
    pVecTracerStart->x = (float)(x + (float)(vecMuzzle.x * 2.0)) + (float)(vecMuzzleAngles.x * 16.0);
    pVecTracerStart->y = v7;
    pVecTracerStart->z = v8;
  }
  else
  {
    pVecTracerStart->x = vecShotSrc->x;
    pVecTracerStart->y = vecShotSrc->y;
    MyCombatCharacterPointer = this->MyCombatCharacterPointer;
    pVecTracerStart->z = vecShotSrc->z;
    v10 = MyCombatCharacterPointer(this);
    if ( v10 != nullptr )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v10);
      if ( ActiveWeapon != nullptr
        && CBaseAnimating::GetAttachment(
             this: ActiveWeapon,
             iAttachment: 1,
             absOrigin: &vecMuzzle,
             absAngles: &vecMuzzleAngles) )
      {
        *pVecTracerStart = vecMuzzle;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB6A0
// Name: public: virtual void CBaseEntity::MakeTracer(class Vector const __near &,class CGameTrace const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::MakeTracer(
        CBaseEntity *this,
        const Vector *vecTracerSrc,
        const CGameTrace *tr,
        int iTracerType)
{
  const char *v5; // eax
  CBaseEntity_vtbl *v6; // edx
  const char *v7; // edi
  int (__thiscall *GetTracerAttachment)(CBaseEntity *); // eax
  int v9; // eax
  edict_t *v10; // esi
  edict_t *m_pPev; // esi
  Vector vNewSrc; // [esp+18h] [ebp-Ch] BYREF

  v5 = this->GetTracerType(this);
  v6 = this->__vftable;
  v7 = v5;
  vNewSrc.z = vecTracerSrc->z;
  GetTracerAttachment = v6->GetTracerAttachment;
  *(_QWORD *)&vNewSrc.x = *(_QWORD *)&vecTracerSrc->x;
  v9 = GetTracerAttachment(this);
  if ( iTracerType == 1 )
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    UTIL_Tracer(
      vecStart: &vNewSrc,
      vecEnd: &tr->endpos,
      iEntIndex: (int)m_pPev,
      iAttachment: v9,
      flVelocity: 0.0,
      bWhiz: false,
      pCustomTracerName: v7,
      iParticleID: 0);
  }
  else if ( iTracerType == 4 )
  {
    v10 = this->m_Network.m_pPev;
    if ( v10 != nullptr )
      v10 -= (int)gpGlobals->pEdicts;
    UTIL_Tracer(
      vecStart: &vNewSrc,
      vecEnd: &tr->endpos,
      iEntIndex: (int)v10,
      iAttachment: v9,
      flVelocity: 0.0,
      bWhiz: true,
      pCustomTracerName: v7,
      iParticleID: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB740
// Name: public: void CBaseEntity::CollisionRulesChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::CollisionRulesChanged(CBaseEntity *this)
{
  int v2; // edi
  int i; // esi
  int v4; // ecx
  _DWORD v5[1024]; // [esp+4h] [ebp-1000h] BYREF

  if ( this->m_pPhysicsObject != nullptr )
  {
    if ( PhysIsInCallback() )
      _Warning(a1: "Changing collision rules within a callback is likely to cause crashes!\n");
    v2 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v5, a3: 1024);
    for ( i = 0; i < v2; ++i )
    {
      v4 = v5[i];
      if ( v4 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 104))(a1: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB7B0
// Name: public: class Vector const __near & CCollisionProperty::CollisionToWorldSpace(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCollisionProperty::CollisionToWorldSpace(
        CCollisionProperty *this,
        const Vector *in,
        Vector *pResult)
{
  unsigned __int8 m_Value; // al
  const QAngle *v5; // eax
  const matrix3x4_t *v6; // eax
  const Vector *v8; // eax

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0
    || (m_Value = this->m_nSolidType.m_Value) == 2
    || m_Value == 0
    || (v5 = this->GetCollisionAngles(this), vec3_angle.x == v5->x) && vec3_angle.y == v5->y && vec3_angle.z == v5->z )
  {
    v8 = this->GetCollisionOrigin(this);
    pResult->x = v8->x + in->x;
    pResult->y = v8->y + in->y;
    pResult->z = v8->z + in->z;
    return pResult;
  }
  else
  {
    v6 = this->CollisionToWorldTransform(this);
    VectorTransform(in1: &in->x, in2: v6, out: &pResult->x);
    return pResult;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB870
// Name: public: virtual class QAngle const __near & CBaseEntity::LocalEyeAngles(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorXYZBase<QAngle,CBaseEntity::NetworkVar_m_angRotation> *__thiscall CBaseEntity::LocalEyeAngles(
        CBaseEntity *this)
{
  return &this->m_angRotation;
}

//------------------------------------------------------------------------------
// Address: 0x100CB880
// Name: public: virtual bool CBaseEntity::GetKeyValue(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::GetKeyValue(CBaseEntity *this, const char *szKeyName, char *szValue, int iMaxLen)
{
  int a; // eax
  const QAngle *AbsAngles; // eax
  const Vector *AbsOrigin; // eax
  const char *pszValue; // ebx
  datamap_t *v10; // esi

  if ( szKeyName == "rendercolor"
    || _V_stricmp(s1: szKeyName, s2: "rendercolor") == 0
    || szKeyName == "rendercolor32"
    || _V_stricmp(s1: szKeyName, s2: "rendercolor32") == 0 )
  {
    V_snprintf(
      pDest: szValue,
      maxLen: iMaxLen,
      pFormat: "%d %d %d %d",
      this->m_clrRender.m_Value.r,
      this->m_clrRender.m_Value.g,
      this->m_clrRender.m_Value.b,
      this->m_clrRender.m_Value.a);
  }
  else
  {
    if ( szKeyName == "renderamt" || _V_stricmp(s1: szKeyName, s2: "renderamt") == 0 )
    {
      a = this->m_clrRender.m_Value.a;
LABEL_8:
      V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%d", a);
      return 1;
    }
    if ( szKeyName == "disableshadows" || _V_stricmp(s1: szKeyName, s2: "disableshadows") == 0 )
    {
      a = (this->m_fEffects.m_Value & 0x10) != 0;
      goto LABEL_8;
    }
    if ( szKeyName == "mins" || _V_stricmp(s1: szKeyName, s2: "mins") == 0 || FStrEq(sz1: szKeyName, sz2: "maxs") )
      return 0;
    if ( FStrEq(sz1: szKeyName, sz2: "disablereceiveshadows") )
    {
      a = (this->m_fEffects.m_Value & 0x40) != 0;
      goto LABEL_8;
    }
    if ( FStrEq(sz1: szKeyName, sz2: "disableflashlight") )
    {
      a = (this->m_fEffects.m_Value & 0x2000) != 0;
      goto LABEL_8;
    }
    if ( FStrEq(sz1: szKeyName, sz2: "nodamageforces") )
    {
      a = this->m_fEffects.m_Value < 0;
      goto LABEL_8;
    }
    if ( FStrEq(sz1: szKeyName, sz2: "angle") )
      return 0;
    if ( FStrEq(sz1: szKeyName, sz2: "angles") )
    {
      AbsAngles = CBaseEntity::GetAbsAngles(this);
      V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%f %f %f", AbsAngles->x, AbsAngles->y, AbsAngles->z);
      return 1;
    }
    if ( FStrEq(sz1: szKeyName, sz2: "origin") )
    {
      AbsOrigin = CBaseEntity::GetAbsOrigin(this);
      V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%f %f %f", AbsOrigin->x, AbsOrigin->y, AbsOrigin->z);
      return 1;
    }
    if ( FStrEq(sz1: szKeyName, sz2: "targetname") )
    {
      pszValue = this->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
LABEL_29:
      V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%s", pszValue);
      return 1;
    }
    if ( FStrEq(sz1: szKeyName, sz2: "classname") )
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      goto LABEL_29;
    }
    v10 = this->GetDataDescMap(this);
    if ( v10 == nullptr )
      return 0;
    while ( !ExtractKeyvalue(
               pObject: (const char *)this,
               pFields: v10->dataDesc,
               iNumFields: v10->dataNumFields,
               szKeyName,
               szValue,
               iMaxLen) )
    {
      v10 = v10->baseMap;
      if ( v10 == nullptr )
        return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CBBE0
// Name: protected: int CBaseEntity::GetIndexForThinkContext(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetIndexForThinkContext(CBaseEntity *this, const char *pszContext)
{
  int v3; // ebx
  int i; // edi
  const char *pszValue; // eax

  v3 = 0;
  if ( this->m_aThinkFunctions.m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    pszValue = this->m_aThinkFunctions.m_Memory.m_pMemory[i].m_iszContext.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( V_strncmp(s1: pszValue, s2: pszContext, count: 32) == 0 )
      break;
    if ( ++v3 >= this->m_aThinkFunctions.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100CBC40
// Name: public: float CBaseEntity::GetNextThink(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseEntity::GetNextThink(CBaseEntity *this, const char *szContext)
{
  int IndexForThinkContext; // eax
  const char *szContexta; // [esp+Ch] [ebp+8h]
  const char *szContextb; // [esp+Ch] [ebp+8h]

  if ( szContext != nullptr )
  {
    IndexForThinkContext = CBaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
    if ( IndexForThinkContext == -1 )
      return -1.0;
    szContextb = (const char *)this->m_aThinkFunctions.m_Memory.m_pMemory[IndexForThinkContext].m_nNextThinkTick;
    if ( szContextb == (const char *)-1 )
      return -1.0;
    return (double)(int)szContextb * gpGlobals->interval_per_tick;
  }
  else
  {
    szContexta = (const char *)this->m_nNextThinkTick.m_Value;
    if ( szContexta == (const char *)-1 )
      return -1.0;
    return (double)(int)szContexta * gpGlobals->interval_per_tick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CBCB0
// Name: public: int CBaseEntity::GetNextThinkTick(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetNextThinkTick(CBaseEntity *this, const char *szContext)
{
  int result; // eax
  int IndexForThinkContext; // eax

  if ( szContext == nullptr )
  {
    result = this->m_nNextThinkTick.m_Value;
    if ( result != -1 )
      return result;
    return -1;
  }
  IndexForThinkContext = CBaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
  if ( IndexForThinkContext == -1 )
    return -1;
  result = this->m_aThinkFunctions.m_Memory.m_pMemory[IndexForThinkContext].m_nNextThinkTick;
  if ( result == -1 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CBCF0
// Name: public: float CBaseEntity::GetLastThink(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseEntity::GetLastThink(CBaseEntity *this, const char *szContext)
{
  if ( szContext != nullptr )
    return (double)this->m_aThinkFunctions.m_Memory.m_pMemory[CBaseEntity::GetIndexForThinkContext(
                                                                this,
                                                                pszContext: szContext)].m_nLastThinkTick
         * gpGlobals->interval_per_tick;
  else
    return (double)this->m_nLastThinkTick * gpGlobals->interval_per_tick;
}

//------------------------------------------------------------------------------
// Address: 0x100CBD30
// Name: private: bool CBaseEntity::WillThink(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::WillThink(CBaseEntity *this)
{
  int m_Size; // edx
  int v3; // eax
  int *i; // ecx

  if ( this->m_nNextThinkTick.m_Value > 0 )
    return 1;
  m_Size = this->m_aThinkFunctions.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    for ( i = &this->m_aThinkFunctions.m_Memory.m_pMemory->m_nNextThinkTick; *i <= 0; i += 4 )
    {
      if ( ++v3 >= m_Size )
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CBD60
// Name: public: int CBaseEntity::GetFirstThinkTick(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetFirstThinkTick(CBaseEntity *this)
{
  int result; // eax
  int m_Size; // edx
  int *p_m_nNextThinkTick; // ecx
  int i; // esi

  result = -1;
  if ( this->m_nNextThinkTick.m_Value > 0 )
    result = this->m_nNextThinkTick.m_Value;
  m_Size = this->m_aThinkFunctions.m_Size;
  if ( m_Size > 0 )
  {
    p_m_nNextThinkTick = &this->m_aThinkFunctions.m_Memory.m_pMemory->m_nNextThinkTick;
    for ( i = m_Size; i != 0; --i )
    {
      if ( *p_m_nNextThinkTick > 0 && (*p_m_nNextThinkTick < result || result == -1) )
        result = *p_m_nNextThinkTick;
      p_m_nNextThinkTick += 4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CBDA0
// Name: private: void CBaseEntity::CheckHasThinkFunction(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::CheckHasThinkFunction(CBaseEntity *this, bool isThinking)
{
  int m_iEFlags; // esi
  int v4; // esi

  m_iEFlags = this->m_iEFlags;
  if ( (m_iEFlags & 0x400000) != 0 )
  {
    if ( isThinking )
    {
      v4 = m_iEFlags & 0xFFBFFFFF;
LABEL_8:
      this->m_iEFlags = v4;
      goto LABEL_9;
    }
  }
  else if ( isThinking )
  {
    goto LABEL_9;
  }
  if ( (this->m_iEFlags & 0x400000) == 0 && CBaseEntity::WillThink(this) == 0 )
  {
    v4 = m_iEFlags | 0x400000;
    goto LABEL_8;
  }
LABEL_9:
  SimThink_EntityChanged(pEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x100CBE00
// Name: private: void CBaseEntity::CheckHasGamePhysicsSimulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::CheckHasGamePhysicsSimulation(CBaseEntity *this)
{
  int m_Value; // eax
  bool v3; // cl
  int m_iEFlags; // eax

  v3 = true;
  if ( !this->IsPlayer(this) )
  {
    m_Value = this->m_MoveType.m_Value;
    if ( this->m_MoveType.m_Value == 0 || m_Value == 6 || m_Value == 7 && CBaseEntity::GetMoveDoneTime(this) <= 0.0 )
      v3 = false;
  }
  m_iEFlags = this->m_iEFlags;
  if ( v3 == ((m_iEFlags & 0x800000) != 0) )
  {
    if ( v3 )
      this->m_iEFlags = m_iEFlags & 0xFF7FFFFF;
    else
      this->m_iEFlags = m_iEFlags | 0x800000;
    SimThink_EntityChanged(pEntity: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CBE80
// Name: private: void CBaseEntity::SetLastThink(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetLastThink(CBaseEntity *this, int nContextIndex, float thinkTime)
{
  int v3; // edx

  if ( thinkTime == -1.0 )
    v3 = -1;
  else
    v3 = (int)(float)((float)(thinkTime / gpGlobals->interval_per_tick) + 0.5);
  if ( nContextIndex >= 0 )
    this->m_aThinkFunctions.m_Memory.m_pMemory[nContextIndex].m_nLastThinkTick = v3;
  else
    this->m_nLastThinkTick = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100CBED0
// Name: private: int CBaseEntity::GetNextThinkTick(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetNextThinkTick(CBaseEntity *this, int nContextIndex)
{
  if ( nContextIndex >= 0 )
    return this->m_aThinkFunctions.m_Memory.m_pMemory[nContextIndex].m_nNextThinkTick;
  else
    return this->m_nNextThinkTick.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100CBF00
// Name: public: void CBaseEntity::VPhysicsSetObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::VPhysicsSetObject(CBaseEntity *this, IPhysicsObject *pPhysics)
{
  const char *pszValue; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx

  if ( this->m_pPhysicsObject != nullptr && pPhysics != nullptr )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "Overwriting physics object for %s\n", pszValue);
  }
  this->m_pPhysicsObject = pPhysics;
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xF7FF);
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    this->m_flNonShadowMass = m_pPhysicsObject->GetMass(this: m_pPhysicsObject);
    if ( this->m_pPhysicsObject->IsStatic(this: this->m_pPhysicsObject) )
      CCollisionProperty::SetSolidFlags(
        this: &this->m_Collision,
        flags: this->m_Collision.m_usSolidFlags.m_Value | 0x800);
  }
  if ( pPhysics != nullptr && this->m_pPhysicsObject == nullptr )
    CBaseEntity::CollisionRulesChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CBFB0
// Name: public: class IPhysicsObject __near * CBaseEntity::VPhysicsInitNormal(enum SolidType_t,int,bool,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CBaseEntity::VPhysicsInitNormal(
        CBaseEntity *this,
        SolidType_t solidType,
        int nSolidFlags,
        bool createAsleep,
        solid_t *pSolid)
{
  int v7; // eax
  IPhysicsObject *v8; // eax
  IPhysicsObject *v9; // edi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( this->m_Network.m_pPev == nullptr || (this->m_iEFlags & 1) != 0 )
    return nullptr;
  this->VPhysicsDestroyObject(this);
  this->m_flNonShadowMass = -1.0;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: solidType);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: nSolidFlags);
  if ( solidType == SOLID_NONE )
    return nullptr;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v7 = this->GetModelIndex(this);
  v8 = PhysModelCreate(
         pEntity: this,
         modelIndex: v7,
         origin: &this->m_vecAbsOrigin,
         angles: &this->m_angAbsRotation,
         pSolid);
  v9 = v8;
  if ( v8 != nullptr )
  {
    CBaseEntity::VPhysicsSetObject(this, pPhysics: v8);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
    if ( !createAsleep )
      v9->Wake(this: v9);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100CC0A0
// Name: public: class IPhysicsObject __near * CBaseEntity::VPhysicsInitShadow(bool,bool,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CBaseEntity::VPhysicsInitShadow(
        CBaseEntity *this,
        int allowPhysicsMovement,
        int allowPhysicsRotation,
        solid_t *pSolid)
{
  IPhysicsObject *result; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v6; // eax
  SolidType_t (__thiscall *GetSolid)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  int v8; // eax
  struct CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx
  const Vector *v10; // eax
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v12; // eax
  const Vector *v13; // eax
  int v14; // eax
  IPhysicsObject *v15; // esi
  const Vector *v16; // [esp+4h] [ebp-40h]
  Vector mins; // [esp+20h] [ebp-24h] BYREF
  Vector maxs; // [esp+2Ch] [ebp-18h] BYREF
  QAngle angles; // [esp+38h] [ebp-Ch] BYREF
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  if ( this->m_Network.m_pPev == nullptr || (this->m_iEFlags & 1) != 0 )
    return nullptr;
  this->VPhysicsDestroyObject(this);
  this->m_flNonShadowMass = -1.0;
  result = (IPhysicsObject *)this->m_Collision.GetSolid(this: &this->m_Collision);
  if ( result != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v6 = this->m_Collision.__vftable;
    angles.z = this->m_angAbsRotation.z;
    GetSolid = v6->GetSolid;
    *(_QWORD *)&angles.x = *(_QWORD *)&this->m_angAbsRotation.x;
    v8 = GetSolid(this: &this->m_Collision);
    p_m_Collision = &this->m_Collision;
    if ( v8 == 2 )
    {
      v10 = this->m_Collision.OBBMins(this: p_m_Collision);
      mins.x = v10->x + 0.21875;
      mins.y = v10->y + 0.21875;
      OBBMaxs = this->m_Collision.OBBMaxs;
      mins.z = v10->z + 0.21875;
      v12 = (float *)OBBMaxs(this: &this->m_Collision);
      maxs.x = *v12 - 0.21875;
      maxs.y = v12[1] - 0.21875;
      maxs.z = v12[2] - 0.21875;
      result = PhysModelCreateBox(pEntity: this, &mins, &maxs, origin: &this->m_vecAbsOrigin, isStatic: false);
      angles = vec3_angle;
    }
    else if ( this->m_Collision.GetSolid(this: p_m_Collision) == SOLID_OBB )
    {
      v16 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
      v13 = this->m_Collision.OBBMins(this: &this->m_Collision);
      result = PhysModelCreateOBB(
                 pEntity: this,
                 mins: v13,
                 maxs: v16,
                 origin: &this->m_vecAbsOrigin,
                 angle: &angles,
                 isStatic: false);
    }
    else
    {
      v14 = this->GetModelIndex(this);
      result = PhysModelCreate(pEntity: this, modelIndex: v14, origin: &this->m_vecAbsOrigin, &angles, pSolid);
    }
    v15 = result;
    if ( result != nullptr )
    {
      CBaseEntity::VPhysicsSetObject(this, pPhysics: result);
      ((void (__thiscall *)(IPhysicsObject *, int, int, int, int))v15->SetShadow)(
        a1: v15,
        a2: 1176256512,
        a3: 1176256512,
        a4: allowPhysicsMovement,
        a5: allowPhysicsRotation);
      ((void (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, _DWORD, _DWORD))v15->UpdateShadow)(
        a1: v15,
        a2: &this->m_vecAbsOrigin,
        a3: &angles,
        a4: 0,
        a5: 0);
      return v15;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CC2F0
// Name: public: bool CBaseEntity::IsStandable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::IsStandable(CBaseEntity *this)
{
  if ( (this->m_Collision.GetSolidFlags(this: &this->m_Collision) & 0x10) != 0 )
    return false;
  if ( this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_BSP
    || this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_VPHYSICS
    || this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_BBOX )
  {
    return true;
  }
  return CBaseEntity::IsBSPModel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CC360
// Name: protected: void CBaseEntity::InvalidatePhysicsRecursive(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InvalidatePhysicsRecursive(CBaseEntity *this, int nChangeFlags)
{
  int v2; // edx
  int v3; // esi
  char v5; // bl
  edict_t *m_pPev; // eax
  unsigned __int16 m_Value; // ax
  unsigned __int8 v8; // al
  bool v9; // bl
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // esi
  unsigned int v12; // eax
  IHandleEntity *v13; // eax
  CBaseAnimating *v14; // eax

  v2 = nChangeFlags;
  v3 = 0;
  if ( (nChangeFlags & 4) != 0 )
    v3 = 4096;
  v5 = 0;
  if ( (nChangeFlags & 1) != 0 )
  {
    v3 |= 0x800u;
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 )
    {
      CCollisionProperty::MarkPartitionHandleDirty(this: &this->m_Collision);
      v2 = nChangeFlags;
    }
  }
  if ( (v2 & 2) != 0 )
  {
    m_Value = this->m_Collision.m_usSolidFlags.m_Value;
    v3 |= 0x800u;
    if ( (m_Value & 0x100) != 0 )
    {
$LN117_0:
      CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
      v5 = 1;
    }
    else
    {
      switch ( this->m_Collision.m_nSurroundType.m_Value )
      {
        case 0u:
        case 1u:
        case 6u:
          if ( (m_Value & 0x40) == 0 )
          {
            v8 = this->m_Collision.m_nSolidType.m_Value;
            if ( v8 != 2 && v8 != 0 )
              goto $LN117_0;
          }
          break;
        case 3u:
        case 5u:
        case 7u:
          break;
        default:
          goto $LN117_0;
      }
    }
    nChangeFlags |= 5u;
    v2 = nChangeFlags;
  }
  if ( (v2 & 0x20) != 0 )
  {
    if ( v5 == 0 && this->m_Collision.m_nSurroundType.m_Value == 7 )
    {
      CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
      v2 = nChangeFlags;
    }
    v2 &= ~0x20u;
    nChangeFlags = v2;
  }
  this->m_iEFlags |= v3;
  if ( (v3 & 0x20080) != 0 )
  {
    CBaseEntity::DispatchUpdateTransmitState(this);
    v2 = nChangeFlags;
  }
  v9 = false;
  if ( (v2 & 0x18) != 0 )
  {
    v9 = (v2 & 7) == 0;
    nChangeFlags = 7;
    v2 = 7;
  }
  m_Index = this->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    do
    {
      if ( !v9 || m_pEntity->m_iParentAttachment.m_Value != 0 )
      {
        CBaseEntity::InvalidatePhysicsRecursive(this: m_pEntity, nChangeFlags: v2);
        v2 = nChangeFlags;
      }
      v12 = m_pEntity->m_hMovePeer.m_Index;
      if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
        v13 = nullptr;
      else
        v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
      m_pEntity = (CBaseEntity *)v13;
    }
    while ( v13 != nullptr );
  }
  if ( (v2 & 0xB) != 0 )
  {
    v14 = this->GetBaseAnimating(this);
    if ( v14 != nullptr )
      v14->InvalidateBoneCache(this: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC530
// Name: public: class CBaseEntity __near * CBaseEntity::GetRootMoveParent(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::GetRootMoveParent(CBaseEntity *this)
{
  CBaseEntity *result; // eax
  unsigned int m_Index; // edx
  CBaseEntity *m_pEntity; // edx
  unsigned int v4; // ecx

  result = this;
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1 )
  {
    m_pEntity = nullptr;
  }
  else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  else
  {
    m_pEntity = nullptr;
  }
  while ( m_pEntity != nullptr )
  {
    v4 = m_pEntity->m_hMoveParent.m_Value.m_Index;
    result = m_pEntity;
    if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CC5A0
// Name: protected: bool CBaseEntity::HandleShotImpactingWater(struct FireBulletsInfo_t const __near &,class Vector const __near &,class ITraceFilter __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::HandleShotImpactingWater(
        CBaseEntity *this,
        const FireBulletsInfo_t *info,
        const Vector *vecEnd,
        ITraceFilter *pTraceFilter,
        Vector *pVecTracerDest)
{
  CAmmoDef *AmmoDef; // eax
  int v8; // eax
  int v9; // edi
  CAmmoDef *v10; // eax
  int v11; // eax
  int m_iAmmoType; // [esp+10h] [ebp-D4h]
  int v13; // [esp+10h] [ebp-D4h]
  CGameTrace waterTrace; // [esp+20h] [ebp-C4h] BYREF
  CEffectData data; // [esp+74h] [ebp-70h] BYREF
  float v16[3]; // [esp+D8h] [ebp-Ch] BYREF
  int savedregs; // [esp+E4h] [ebp+0h] BYREF

  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)info,
    vecAbsStart: &info->m_vecSrc,
    vecAbsEnd: vecEnd,
    mask: 0x46004033u,
    pFilter: pTraceFilter,
    ptr: &waterTrace);
  v16[0] = waterTrace.endpos.x;
  v16[1] = waterTrace.endpos.y;
  v16[2] = waterTrace.endpos.z - 0.1;
  if ( (enginetrace->GetPointContents(this: enginetrace, a2: (const Vector *)v16, a3: 16432, a4: nullptr) & 0x30) == 0 )
    return 0;
  if ( this->ShouldDrawWaterImpacts(this) )
  {
    m_iAmmoType = info->m_iAmmoType;
    AmmoDef = GetAmmoDef();
    v8 = CAmmoDef::MinSplashSize(this: AmmoDef, nAmmoIndex: m_iAmmoType);
    v13 = info->m_iAmmoType;
    v9 = v8;
    v10 = GetAmmoDef();
    v11 = CAmmoDef::MaxSplashSize(this: v10, nAmmoIndex: v13);
    memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
    memset((void *)&data.m_vAngles, 0, 20);
    memset(&data.m_flMagnitude, 0, 14);
    data.m_vOrigin = waterTrace.endpos;
    data.m_vNormal = waterTrace.plane.normal;
    data.m_flScale = 1.0;
    memset(&data.m_nMaterial, 0, 17);
    data.m_flScale = ((double (__thiscall *)(_DWORD, _DWORD, _DWORD))random->RandomFloat)(
                       a1: random,
                       a2: (float)v9,
                       a3: (float)v11);
    if ( (waterTrace.contents & 0x10) != 0 )
      data.m_fFlags |= 1u;
    DispatchEffect(pName: "gunshotsplash", &data);
  }
  *pVecTracerDest = waterTrace.endpos;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CC780
// Name: public: void CBaseEntity::ApplyAbsVelocityImpulse(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ApplyAbsVelocityImpulse(CBaseEntity *this, const Vector *vecImpulse)
{
  int v3; // ebx
  int i; // esi
  _DWORD v5[1024]; // [esp+0h] [ebp-100Ch] BYREF
  Vector vecAbsVelocity; // [esp+1000h] [ebp-Ch] BYREF
  int savedregs; // [esp+100Ch] [ebp+0h] BYREF

  if ( vec3_origin.x != vecImpulse->x || vec3_origin.y != vecImpulse->y || vec3_origin.z != vecImpulse->z )
  {
    if ( this->m_MoveType.m_Value == 6 )
    {
      v3 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v5, a3: 1024);
      for ( i = 0; i < v3; ++i )
        (*(void (__thiscall **)(_DWORD, const Vector *, _DWORD))(*(_DWORD *)v5[i] + 212))(
          a1: v5[i],
          a2: vecImpulse,
          a3: 0);
    }
    else
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      vecAbsVelocity.x = this->m_vecAbsVelocity.x + vecImpulse->x;
      vecAbsVelocity.y = this->m_vecAbsVelocity.y + vecImpulse->y;
      vecAbsVelocity.z = this->m_vecAbsVelocity.z + vecImpulse->z;
      CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC880
// Name: public: void CBaseEntity::ApplyLocalAngularVelocityImpulse(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ApplyLocalAngularVelocityImpulse(CBaseEntity *this, const Vector *angImpulse)
{
  float x; // xmm2_4
  int v3; // ebx
  int i; // esi
  float v5; // xmm3_4
  float v6; // xmm0_4
  _DWORD v7[1024]; // [esp+0h] [ebp-100Ch] BYREF
  QAngle vecAngVelocity; // [esp+1000h] [ebp-Ch] BYREF

  x = angImpulse->x;
  if ( vec3_origin.x != angImpulse->x || vec3_origin.y != angImpulse->y || vec3_origin.z != angImpulse->z )
  {
    if ( this->m_MoveType.m_Value == 6 )
    {
      v3 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v7, a3: 1024);
      for ( i = 0; i < v3; ++i )
        (*(void (__thiscall **)(_DWORD, _DWORD, const Vector *))(*(_DWORD *)v7[i] + 212))(
          a1: v7[i],
          a2: 0,
          a3: angImpulse);
    }
    else
    {
      v5 = this->m_vecAngVelocity.x + angImpulse->y;
      vecAngVelocity.y = this->m_vecAngVelocity.y + angImpulse->z;
      v6 = this->m_vecAngVelocity.z + x;
      vecAngVelocity.x = v5;
      vecAngVelocity.z = v6;
      CBaseEntity::SetLocalAngularVelocity(this, &vecAngVelocity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC970
// Name: public: static bool CBaseEntity::IsSimulatingOnAlternateTicks(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBaseEntity::IsSimulatingOnAlternateTicks()
{
  if ( gpGlobals->maxClients != 1 )
    return false;
  if ( sv_alternateticks.m_pParent != nullptr )
    return sv_alternateticks.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100CC9A0
// Name: public: void CBaseEntity::PhysicsTouchTriggers(class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsTouchTriggers(CBaseEntity *this, const Vector *pPrevAbsOrigin)
{
  bool v3; // al
  bool v4; // zf
  char v5; // bl
  const char *v6; // eax
  const char *pszValue; // esi
  _BYTE v8[4]; // [esp+4h] [ebp-Ch] BYREF
  edict_t *pEntity; // [esp+8h] [ebp-8h]
  bool isTriggerCheckSolids; // [esp+Fh] [ebp-1h]

  pEntity = this->m_Network.m_pPev;
  if ( pEntity != nullptr && this != g_WorldEntity )
  {
    v3 = (this->m_Collision.m_usSolidFlags.m_Value & 8) != 0;
    v4 = this->m_Collision.m_nSolidType.m_Value == 0;
    isTriggerCheckSolids = v3;
    if ( v4 || (this->m_Collision.m_usSolidFlags.m_Value & 4) != 0 || v3 )
    {
      v5 = 0;
      if ( !v3 )
        return;
    }
    else
    {
      v5 = 1;
    }
    if ( this->m_Collision.GetSolid(this: &this->m_Collision) != SOLID_BSP || CBaseEntity::GetModel(this) != nullptr )
      goto LABEL_16;
    v6 = *(const char **)((int (__thiscall *)(CBaseEntity *, _BYTE *))this->GetModelName)(a1: this, a2: v8);
    if ( v6 == nullptr )
      v6 = locale;
    if ( _V_strlen(str: v6) != 0 )
    {
LABEL_16:
      CBaseEntity::SetCheckUntouch(this, check: true);
      if ( v5 != 0 )
        engine->SolidMoved(
          this: engine,
          a2: pEntity,
          a3: &this->m_Collision,
          a4: pPrevAbsOrigin,
          a5: CBaseEntity::sm_bAccurateTriggerBboxChecks);
      if ( isTriggerCheckSolids )
        engine->TriggerMoved(this: engine, a2: pEntity, a3: CBaseEntity::sm_bAccurateTriggerBboxChecks);
    }
    else
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      _Warning(a1: "Inserted %s with no model\n", pszValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CCAC0
// Name: public: class Vector const __near & CCollisionProperty::WorldSpaceCenter(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCollisionProperty::WorldSpaceCenter(CCollisionProperty *this)
{
  Vector *v2; // edi
  Vector *v3; // eax

  v2 = AllocTempVector();
  v3 = AllocTempVector();
  v3->x = (float)((float)(this->m_vecMaxs.m_Value.x - this->m_vecMins.m_Value.x) * 0.5) + this->m_vecMins.m_Value.x;
  v3->y = (float)((float)(this->m_vecMaxs.m_Value.y - this->m_vecMins.m_Value.y) * 0.5) + this->m_vecMins.m_Value.y;
  v3->z = (float)((float)(this->m_vecMaxs.m_Value.z - this->m_vecMins.m_Value.z) * 0.5) + this->m_vecMins.m_Value.z;
  CCollisionProperty::CollisionToWorldSpace(this, in: v3, pResult: v2);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100CCB30
// Name: public: virtual class Vector const __near & CBaseEntity::WorldSpaceCenter(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::WorldSpaceCenter(CBaseEntity *this)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // esi
  Vector *v2; // edi
  Vector *v3; // eax

  p_m_Collision = &this->m_Collision;
  v2 = AllocTempVector();
  v3 = AllocTempVector();
  v3->x = (float)((float)(p_m_Collision->m_vecMaxs.m_Value.x - p_m_Collision->m_vecMins.m_Value.x) * 0.5)
        + p_m_Collision->m_vecMins.m_Value.x;
  v3->y = (float)((float)(p_m_Collision->m_vecMaxs.m_Value.y - p_m_Collision->m_vecMins.m_Value.y) * 0.5)
        + p_m_Collision->m_vecMins.m_Value.y;
  v3->z = (float)((float)(p_m_Collision->m_vecMaxs.m_Value.z - p_m_Collision->m_vecMins.m_Value.z) * 0.5)
        + p_m_Collision->m_vecMins.m_Value.z;
  CCollisionProperty::CollisionToWorldSpace(this: p_m_Collision, in: v3, pResult: v2);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100CCBB0
// Name: public: class IPhysicsObject __near * CBaseEntity::VPhysicsInitStatic(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__usercall CBaseEntity::VPhysicsInitStatic@<eax>(CBaseEntity *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  CBaseEntity *RootMoveParent; // eax
  IPhysicsObject *result; // eax
  const Vector *v6; // ebx
  const Vector *v7; // eax
  IPhysicsObject *Box; // edi
  const Vector *v9; // eax
  IPhysicsObject *OBB; // edi
  int v11; // eax
  const Vector *v12; // [esp-14h] [ebp-18h]
  const Vector *AbsOrigin; // [esp-10h] [ebp-14h]
  const QAngle *AbsAngles; // [esp-Ch] [ebp-10h]
  const Vector *v15; // [esp-Ch] [ebp-10h]
  const QAngle *v16; // [esp-8h] [ebp-Ch]

  if ( this->m_Network.m_pPev == nullptr || (this->m_iEFlags & 1) != 0 )
    return nullptr;
  this->VPhysicsDestroyObject(this);
  this->m_flNonShadowMass = -1.0;
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_BSP )
    {
      RootMoveParent = CBaseEntity::GetRootMoveParent(this);
      if ( RootMoveParent->m_Collision.GetSolid(this: &RootMoveParent->m_Collision) != SOLID_BSP )
        CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
    }
    return CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
  }
  else
  {
    result = (IPhysicsObject *)this->m_Collision.GetSolid(this: &this->m_Collision);
    if ( result != nullptr )
    {
      if ( this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_BBOX )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2);
        v6 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
        v7 = this->m_Collision.OBBMins(this: &this->m_Collision);
        Box = PhysModelCreateBox(pEntity: this, mins: v7, maxs: v6, origin: &this->m_vecAbsOrigin, isStatic: true);
        CBaseEntity::VPhysicsSetObject(this, pPhysics: Box);
        return Box;
      }
      else
      {
        if ( this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_OBB )
        {
          AbsAngles = CBaseEntity::GetAbsAngles(this);
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          v12 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
          v9 = this->m_Collision.OBBMins(this: &this->m_Collision);
          OBB = PhysModelCreateOBB(
                  pEntity: this,
                  mins: v9,
                  maxs: v12,
                  origin: AbsOrigin,
                  angle: AbsAngles,
                  isStatic: true);
        }
        else
        {
          v16 = CBaseEntity::GetAbsAngles(this);
          v15 = CBaseEntity::GetAbsOrigin(this);
          v11 = this->GetModelIndex(this);
          OBB = PhysModelCreateUnmoveable(pEntity: this, modelIndex: v11, origin: v15, angles: v16);
        }
        CBaseEntity::VPhysicsSetObject(this, pPhysics: OBB);
        return OBB;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CCD80
// Name: public: void CBaseEntity::TraceBleed(float,class Vector const __near &,class CGameTrace __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::TraceBleed(
        CBaseEntity *this,
        float flDamage,
        const Vector *vecDir,
        CGameTrace *ptr,
        int bitsDamageType)
{
  int v7; // xmm1_4
  int v8; // eax
  int v10; // xmm0_4
  Vector *p_endpos; // esi
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v13; // st7
  float (__thiscall *v14)(IUniformRandomStream *, float, float); // eax
  double v15; // st7
  IUniformRandomStream_vtbl *v16; // edx
  double v17; // st7
  float x; // xmm3_4
  float v19; // xmm0_4
  int v20; // eax
  CGameTrace Bloodtr; // [esp+28h] [ebp-7Ch] BYREF
  Vector vecAbsEnd; // [esp+7Ch] [ebp-28h] BYREF
  Vector vecTraceDir; // [esp+88h] [ebp-1Ch]
  float v24; // [esp+94h] [ebp-10h]
  float v25; // [esp+98h] [ebp-Ch]
  float v26; // [esp+9Ch] [ebp-8h]
  float v27; // [esp+A0h] [ebp-4h]
  IHandleEntity savedregs; // [esp+A4h] [ebp+0h] BYREF
  int flNoise; // [esp+ACh] [ebp+8h]
  const Vector *vecDira; // [esp+B0h] [ebp+Ch]
  int bitsDamageTypeb; // [esp+B8h] [ebp+14h]
  int bitsDamageTypea; // [esp+B8h] [ebp+14h]

  if ( this->BloodColor(this) != -1
    && this->BloodColor(this) != 3
    && flDamage != 0.0
    && (bitsDamageType & 0x20000C7) != 0 )
  {
    if ( !this->IsAlive(this) )
    {
      if ( this->GetMaxHealth(this) <= 0 )
        return;
      bitsDamageTypeb = this->m_iMaxHealth.m_Value - 1;
      this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
      this->m_iMaxHealth.m_Value = bitsDamageTypeb;
    }
    if ( flDamage >= 10.0 )
    {
      if ( flDamage >= 25.0 )
      {
        v7 = 1050253722;
        v8 = 4;
      }
      else
      {
        v7 = 1045220557;
        v8 = 2;
      }
    }
    else
    {
      v7 = 1036831949;
      v8 = 1;
    }
    flNoise = v7;
    v10 = v7 ^ _mask__NegFloat_;
    bitsDamageTypea = v7 ^ _mask__NegFloat_;
    LODWORD(v27) = COERCE_UNSIGNED_INT((float)((bitsDamageType & 0x2000000) != 0 ? 384 : 172)) ^ _mask__NegFloat_;
    p_endpos = &ptr->endpos;
    vecDira = (const Vector *)v8;
    while ( 1 )
    {
      RandomFloat = random->RandomFloat;
      v24 = vecDir->x * -1.0;
      v25 = vecDir->y * -1.0;
      v26 = -1.0 * vecDir->z;
      v13 = ((double (__stdcall *)(int, int))RandomFloat)(a1: v10, a2: v7);
      v14 = random->RandomFloat;
      vecTraceDir.x = v13 + v24;
      v15 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v14)(a1: random, a2: bitsDamageTypea, a3: flNoise);
      v16 = random->__vftable;
      vecTraceDir.y = v15 + v25;
      v17 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v16->RandomFloat)(
              a1: random,
              a2: bitsDamageTypea,
              a3: flNoise);
      x = p_endpos->x;
      vecTraceDir.z = v17 + v26;
      vecAbsEnd.y = ptr->endpos.y + (float)(v27 * vecTraceDir.y);
      v19 = ptr->endpos.z + (float)(v27 * vecTraceDir.z);
      vecAbsEnd.x = x + (float)(v27 * vecTraceDir.x);
      vecAbsEnd.z = v19;
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)p_endpos,
        vecAbsStart: p_endpos,
        &vecAbsEnd,
        mask: 0x4003u,
        ignore: this,
        collisionGroup: 0,
        ptr: &Bloodtr);
      if ( Bloodtr.fraction != 1.0 )
      {
        v20 = this->BloodColor(this);
        UTIL_BloodDecalTrace(pTrace: &Bloodtr, bloodColor: v20);
      }
      vecDira = (const Vector *)((char *)vecDira - 1);
      if ( vecDira == nullptr )
        break;
      v10 = bitsDamageTypea;
      v7 = flNoise;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD010
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBaseEntity::NetworkVar_m_hEffectEntity>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hEffectEntity>::Set(
        CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hEffectEntity> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hEffectEntity> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 193;
    if ( *((_BYTE *)this - 688) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x304u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x100CD0A0
// Name: public: void CBaseEntity::AddFlag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AddFlag(CBaseEntity *this, int flags)
{
  unsigned int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_fFlags> *p_m_fFlags; // esi
  int v5; // edi
  unsigned int v6; // [esp+Ch] [ebp-4h]

  m_Value = this->m_fFlags.m_Value;
  p_m_fFlags = &this->m_fFlags;
  v5 = flags | m_Value;
  v6 = m_Value;
  if ( m_Value != (flags | m_Value) )
  {
    this->NetworkStateChanged_m_fFlags(this, a2: &this->m_fFlags);
    m_Value = v6;
    p_m_fFlags->m_Value = v5;
  }
  CGlobalEntityList::ReportEntityFlagsChanged(
    this: &gEntList,
    pEntity: this,
    flagsOld: m_Value,
    flagsNow: p_m_fFlags->m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x100CD100
// Name: public: void CBaseEntity::RemoveFlag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RemoveFlag(CBaseEntity *this, int flagsToRemove)
{
  unsigned int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_fFlags> *p_m_fFlags; // esi
  int v5; // edi
  unsigned int v6; // [esp+Ch] [ebp-4h]

  m_Value = this->m_fFlags.m_Value;
  p_m_fFlags = &this->m_fFlags;
  v5 = m_Value & ~flagsToRemove;
  v6 = m_Value;
  if ( m_Value != v5 )
  {
    this->NetworkStateChanged_m_fFlags(this, a2: &this->m_fFlags);
    m_Value = v6;
    p_m_fFlags->m_Value = v5;
  }
  CGlobalEntityList::ReportEntityFlagsChanged(
    this: &gEntList,
    pEntity: this,
    flagsOld: m_Value,
    flagsNow: p_m_fFlags->m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x100CD160
// Name: public: void CBaseEntity::ClearFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ClearFlags(CBaseEntity *this)
{
  unsigned int m_Value; // ebx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_fFlags> *p_m_fFlags; // esi

  m_Value = this->m_fFlags.m_Value;
  p_m_fFlags = &this->m_fFlags;
  if ( m_Value != 0 )
  {
    this->NetworkStateChanged_m_fFlags(this, a2: &this->m_fFlags);
    p_m_fFlags->m_Value = 0;
  }
  CGlobalEntityList::ReportEntityFlagsChanged(
    this: &gEntList,
    pEntity: this,
    flagsOld: m_Value,
    flagsNow: p_m_fFlags->m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x100CD1B0
// Name: public: void CBaseEntity::ToggleFlag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ToggleFlag(CBaseEntity *this, int flagToToggle)
{
  unsigned int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_fFlags> *p_m_fFlags; // esi
  int v5; // edi
  unsigned int v6; // [esp+Ch] [ebp-4h]

  m_Value = this->m_fFlags.m_Value;
  p_m_fFlags = &this->m_fFlags;
  v5 = flagToToggle ^ m_Value;
  v6 = m_Value;
  if ( m_Value != (flagToToggle ^ m_Value) )
  {
    this->NetworkStateChanged_m_fFlags(this, a2: &this->m_fFlags);
    m_Value = v6;
    p_m_fFlags->m_Value = v5;
  }
  CGlobalEntityList::ReportEntityFlagsChanged(
    this: &gEntList,
    pEntity: this,
    flagsOld: m_Value,
    flagsNow: p_m_fFlags->m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x100CD210
// Name: public: void CBaseEntity::SetEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetEffects(CBaseEntity *this, int nEffects)
{
  edict_t *m_pPev; // ecx

  if ( this->m_fEffects.m_Value != nEffects )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = nEffects;
    if ( (nEffects & 8) != 0 )
    {
      CGlobalEntityList::AddPostClientMessageEntity(this: &gEntList, pEntity: this);
      if ( this->IsPlayer(this) )
        CBasePlayer::IncrementEFNoInterpParity((CBasePlayer *)this);
    }
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD290
// Name: public: void CBaseEntity::AddEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AddEffects(CBaseEntity *this, int nEffects)
{
  int v3; // esi
  edict_t *m_pPev; // ecx

  v3 = nEffects | this->m_fEffects.m_Value;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  if ( (nEffects & 8) != 0 )
    CGlobalEntityList::AddPostClientMessageEntity(this: &gEntList, pEntity: this);
  if ( (nEffects & 0x20) != 0 )
    CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CD300
// Name: protected: virtual void CBaseEntity::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::TraceAttack(
        CBaseEntity *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  bool v7; // zf
  float v8; // xmm0_4
  int v9; // eax
  int m_flDamage; // [esp+Ch] [ebp-28h]
  Vector origin; // [esp+1Ch] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+28h] [ebp-Ch]

  v4 = vecDir->z * 4.0;
  v5 = ptr->endpos.x - (float)(vecDir->x * 4.0);
  vecOrigin.y = ptr->endpos.y - (float)(vecDir->y * 4.0);
  v7 = this->m_takedamage.m_Value == 0;
  v8 = ptr->endpos.z - v4;
  vecOrigin.x = v5;
  vecOrigin.z = v8;
  if ( !v7 )
  {
    AddMultiDamage(info, pEntity: this);
    v9 = this->BloodColor(this);
    if ( v9 != -1 )
    {
      m_flDamage = (int)info->m_flDamage;
      origin = vecOrigin;
      UTIL_BloodDrips(&origin, direction: vecDir, color: v9, amount: m_flDamage);
      CBaseEntity::TraceBleed(this, flDamage: info->m_flDamage, vecDir, ptr, bitsDamageType: info->m_bitsDamageType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD3D0
// Name: public: void CBaseEntity::FollowEntity(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::FollowEntity(CBaseEntity *this, CBaseEntity *pBaseEntity, bool bBoneMerge)
{
  int m_Value; // eax
  int v5; // edi
  edict_t *m_pPev; // ecx

  if ( pBaseEntity != nullptr )
  {
    this->SetParent(this, a2: pBaseEntity, a3: -1);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    if ( bBoneMerge )
    {
      m_Value = this->m_fEffects.m_Value;
      v5 = m_Value | 1;
      if ( m_Value != (m_Value | 1) )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
        }
        this->m_fEffects.m_Value = v5;
      }
    }
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    CBaseEntity::SetLocalOrigin(this, origin: &vec3_origin);
    CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  }
  else
  {
    CBaseEntity::StopFollowingEntity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD480
// Name: public: void CBaseEntity::UnsetPlayerSimulated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::UnsetPlayerSimulated(CBaseEntity *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBasePlayer **v8; // eax
  CBasePlayer *v9; // eax
  unsigned int v10; // eax
  edict_t *m_pPev; // ecx
  edict_t *v12; // ecx

  m_Index = this->m_hPlayerSimulationOwner.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (CBasePlayer **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        v9 = *v8;
      else
        v9 = nullptr;
      CBasePlayer::RemoveFromPlayerSimulationList(this: v9, other: this);
    }
  }
  v10 = this->m_hPlayerSimulationOwner.m_Value.m_Index;
  if ( v10 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x22Cu);
    }
    this->m_hPlayerSimulationOwner.m_Value.m_Index = -1;
  }
  if ( this->m_bIsPlayerSimulated.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bIsPlayerSimulated.m_Value = false;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x22Bu);
      this->m_bIsPlayerSimulated.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD570
// Name: public: void CBaseEntity::SetEffectEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetEffectEntity(CBaseEntity *this, CBaseEntity *pEffectEnt)
{
  unsigned int m_Index; // eax
  CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hEffectEntity> *p_m_hEffectEntity; // ecx
  CBaseEntity *m_pEntity; // edx

  m_Index = this->m_hEffectEntity.m_Value.m_Index;
  p_m_hEffectEntity = &this->m_hEffectEntity;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != pEffectEnt )
    CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hEffectEntity>::Set(
      this: p_m_hEffectEntity,
      val: pEffectEnt);
}

//------------------------------------------------------------------------------
// Address: 0x100CD5C0
// Name: public: void CBaseEntity::SetCollisionGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetCollisionGroup(CBaseEntity *this, int collisionGroup)
{
  edict_t *m_pPev; // ecx

  if ( this->m_CollisionGroup.m_Value != collisionGroup )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_CollisionGroup.m_Value = collisionGroup;
      CBaseEntity::CollisionRulesChanged(this);
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x144u);
      this->m_CollisionGroup.m_Value = collisionGroup;
      CBaseEntity::CollisionRulesChanged(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD620
// Name: public: virtual void CBaseEntity::SetViewOffset(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetViewOffset(CBaseEntity *this, const Vector *v)
{
  CNetworkVectorXYZBase<Vector,CBaseEntity::NetworkVar_m_vecViewOffset> *p_m_vecViewOffset; // esi
  float va; // [esp+8h] [ebp+8h]
  float vb; // [esp+8h] [ebp+8h]
  float vc; // [esp+8h] [ebp+8h]

  p_m_vecViewOffset = &this->m_vecViewOffset;
  va = v->x;
  if ( this->m_vecViewOffset.m_Value.x != va )
  {
    this->NetworkStateChanged_m_vecViewOffset(this, a2: &this->m_vecViewOffset);
    p_m_vecViewOffset->m_Value.x = va;
  }
  vb = v->y;
  if ( p_m_vecViewOffset->m_Value.y != vb )
  {
    (*(void (__thiscall **)(float *, float *))(LODWORD(p_m_vecViewOffset[-61].m_Value.y) + 764))(
      a1: &p_m_vecViewOffset[-61].m_Value.y,
      a2: &p_m_vecViewOffset->m_Value.y);
    p_m_vecViewOffset->m_Value.y = vb;
  }
  vc = v->z;
  if ( p_m_vecViewOffset->m_Value.z != vc )
  {
    (*(void (__thiscall **)(float *, float *))(LODWORD(p_m_vecViewOffset[-61].m_Value.y) + 764))(
      a1: &p_m_vecViewOffset[-61].m_Value.y,
      a2: &p_m_vecViewOffset->m_Value.z);
    p_m_vecViewOffset->m_Value.z = vc;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD6E0
// Name: public: virtual bool CBaseEntity::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::KeyValue(CBaseEntity *this, char *szKeyName, const char *szValue)
{
  _BYTE *v5; // eax
  unsigned __int8 v6; // al
  bool result; // al
  int v8; // eax
  const Vector *v9; // eax
  const Vector *v10; // eax
  long double v11; // st7
  string_t v12; // eax
  char *v13; // eax
  datamap_t *v14; // esi
  const char *v15; // edi
  char *v16; // eax
  const char *pszValue; // edx
  char *m_pszString; // eax
  datamap_t *v19; // esi
  char *v20; // eax
  char *v21; // eax
  const char *v22; // eax
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *p_m_clrRender; // esi
  unsigned __int8 a; // bl
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *v25; // eax
  CBaseEdict *v26; // ecx
  int pVector; // [esp+24h] [ebp-Ch] BYREF
  color32_s tmp; // [esp+28h] [ebp-8h] BYREF
  const char *debugName; // [esp+2Ch] [ebp-4h]
  char printKeyHits_3; // [esp+3Bh] [ebp+Bh]

  strchr(string: szKeyName, chr: 0x23u);
  if ( v5 != nullptr )
    *v5 = 0;
  if ( szKeyName == "rendercolor"
    || _V_stricmp(s1: szKeyName, s2: "rendercolor") == 0
    || szKeyName == "rendercolor32"
    || _V_stricmp(s1: szKeyName, s2: "rendercolor32") == 0 )
  {
    V_StringToColor32(color: &tmp, pString: szValue);
    p_m_clrRender = &this->m_clrRender;
    CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
      this: &this->m_clrRender,
      rVal: tmp.r,
      gVal: tmp.g,
      bVal: tmp.b);
    a = tmp.a;
    if ( p_m_clrRender->m_Value.a != tmp.a )
    {
      v25 = p_m_clrRender - 46;
      if ( p_m_clrRender[-25].m_Value.r != 0 )
      {
        v25[22].m_Value.r |= 1u;
        p_m_clrRender->m_Value.a = a;
        return true;
      }
      v26 = (CBaseEdict *)v25[6];
      if ( v26 != nullptr )
        CBaseEdict::StateChanged(this: v26, offset: 0xB8u);
      p_m_clrRender->m_Value.a = a;
    }
    return true;
  }
  if ( szKeyName == "renderamt" || _V_stricmp(s1: szKeyName, s2: "renderamt") == 0 )
  {
    v6 = V_atoi(str: szValue);
    CBaseEntity::SetRenderAlpha(this, a: v6);
    return true;
  }
  if ( szKeyName == "disableshadows" || _V_stricmp(s1: szKeyName, s2: "disableshadows") == 0 )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      CBaseEntity::AddEffects(this, nEffects: 16);
      return true;
    }
    return true;
  }
  if ( szKeyName == "drawinfastreflection" || _V_stricmp(s1: szKeyName, s2: "drawinfastreflection") == 0 )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      CBaseEntity::AddEffects(this, nEffects: 1024);
      return true;
    }
    return true;
  }
  if ( FStrEq(sz1: szKeyName, sz2: "disableshadowdepth") )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      CBaseEntity::AddEffects(this, nEffects: 2048);
      return true;
    }
    return true;
  }
  if ( FStrEq(sz1: szKeyName, sz2: "shadowdepthnocache") )
  {
    v8 = atoi(nptr: szValue);
    if ( v8 == 1 )
    {
      CBaseEntity::AddEffects(this, nEffects: 4096);
      return true;
    }
    if ( v8 == 2 )
    {
      CBaseEntity::RemoveEffects(this, nEffects: 4096);
      return true;
    }
    return true;
  }
  if ( FStrEq(sz1: szKeyName, sz2: "mins") )
  {
    UTIL_StringToVector((float *)&pVector, pString: szValue);
    v9 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
    CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: (const Vector *)&pVector, maxs: v9);
    return true;
  }
  if ( FStrEq(sz1: szKeyName, sz2: "maxs") )
  {
    UTIL_StringToVector((float *)&pVector, pString: szValue);
    v10 = this->m_Collision.OBBMins(this: &this->m_Collision);
    CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: v10, maxs: (const Vector *)&pVector);
    return true;
  }
  if ( FStrEq(sz1: szKeyName, sz2: "disablereceiveshadows") )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      CBaseEntity::AddEffects(this, nEffects: 64);
      return true;
    }
    return true;
  }
  if ( FStrEq(sz1: szKeyName, sz2: "disableflashlight") )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      CBaseEntity::AddEffects(this, nEffects: 0x2000);
      return true;
    }
    return true;
  }
  if ( FStrEq(sz1: szKeyName, sz2: "nodamageforces") )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      this->m_iEFlags |= 0x80000000;
      return true;
    }
    return true;
  }
  if ( !FStrEq(sz1: szKeyName, sz2: "angle") )
  {
    if ( FStrEq(sz1: szKeyName, sz2: "angles") )
    {
      UTIL_StringToVector((float *)&pVector, pString: szValue);
      CBaseEntity::SetAbsAngles(this, absAngles: (const QAngle *)&pVector);
      return true;
    }
    if ( FStrEq(sz1: szKeyName, sz2: "origin") )
    {
      UTIL_StringToVector((float *)&pVector, pString: szValue);
      CBaseEntity::SetAbsOrigin(this, absOrigin: (const Vector *)&pVector);
      return true;
    }
    if ( FStrEq(sz1: szKeyName, sz2: "targetname") )
    {
      v12.pszValue = AllocPooledString(pszValue: (const char *)&szValue).pszValue;
      CBaseEntity::SetName(this, newName: *(string_t *)v12.pszValue);
      return true;
    }
    if ( (ent_debugkeys.m_nFlags & 0x1000) != 0
      || (v13 = ent_debugkeys.m_pParent->m_Value.m_pszString) != nullptr && *v13 != 0 )
    {
      printKeyHits_3 = 0;
      debugName = locale;
      if ( (ent_debugkeys.m_nFlags & 0x1000) != 0
        || (v16 = ent_debugkeys.m_pParent->m_Value.m_pszString) != nullptr && *v16 != 0 )
      {
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        if ( (ent_debugkeys.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = ent_debugkeys.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)locale;
        }
        if ( _V_stricmp(s1: m_pszString, s2: pszValue) == 0 )
        {
          printKeyHits_3 = 1;
          debugName = this->m_iClassname.pszValue;
          if ( debugName == nullptr )
            debugName = locale;
        }
      }
      v19 = this->GetDataDescMap(this);
      if ( v19 != nullptr )
      {
        while ( 1 )
        {
          if ( printKeyHits_3 == 0
            && ((ent_debugkeys.m_nFlags & 0x1000) != 0
             || (v20 = ent_debugkeys.m_pParent->m_Value.m_pszString) != nullptr && *v20 != 0) )
          {
            if ( (ent_debugkeys.m_nFlags & 0x1000) != 0 )
            {
              v21 = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              v21 = ent_debugkeys.m_pParent->m_Value.m_pszString;
              if ( v21 == nullptr )
                v21 = (char *)locale;
            }
            if ( _V_stricmp(s1: v19->dataClassName, s2: v21) == 0 )
            {
              printKeyHits_3 = 1;
              debugName = v19->dataClassName;
            }
          }
          if ( ParseKeyvalue(pObject: this, pFields: v19->dataDesc, iNumFields: v19->dataNumFields, szKeyName, szValue) )
            break;
          v19 = v19->baseMap;
          if ( v19 == nullptr )
            goto LABEL_85;
        }
        if ( printKeyHits_3 != 0 )
        {
          _Msg(a1: "(%s) key: %-16s value: %s\n", debugName, szKeyName, szValue);
          return true;
        }
        return true;
      }
LABEL_85:
      if ( printKeyHits_3 != 0 )
      {
        v22 = this->m_iClassname.pszValue;
        if ( v22 == nullptr )
          v22 = locale;
        _Msg(a1: "!! (%s) key not handled: \"%s\" \"%s\"\n", v22, szKeyName, szValue);
      }
    }
    else
    {
      v14 = this->GetDataDescMap(this);
      if ( v14 != nullptr )
      {
        v15 = szValue;
        while ( 1 )
        {
          result = ParseKeyvalue(
                     pObject: this,
                     pFields: v14->dataDesc,
                     iNumFields: v14->dataNumFields,
                     szKeyName,
                     szValue: v15);
          if ( result )
            break;
          v14 = v14->baseMap;
          if ( v14 == nullptr )
            return result;
        }
        return true;
      }
    }
    return false;
  }
  v11 = atof(nptr: szValue);
  *(float *)&szValue = v11;
  if ( v11 < 0.0 )
  {
    if ( (int)*(float *)&szValue == -1 )
      V_strncpy(pDest: szBuf, pSrc: "-90 0 0", maxLen: 64);
    else
      V_strncpy(pDest: szBuf, pSrc: "90 0 0", maxLen: 64);
  }
  else
  {
    V_snprintf(
      pDest: szBuf,
      maxLen: 64,
      pFormat: "%f %f %f",
      this->m_angRotation.m_Value.x,
      *(float *)&szValue,
      this->m_angRotation.m_Value.z);
  }
  return this->KeyValue_4(this, a2: szKeyName, a3: szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x100CDD70
// Name: public: int CBaseEntity::RegisterThinkContext(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::RegisterThinkContext(CBaseEntity *this, const char *szContext)
{
  int result; // eax
  thinkfunc_t sNewFunc; // [esp+8h] [ebp-10h] BYREF

  result = CBaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
  if ( result == -1 )
  {
    _V_memset(dest: &sNewFunc, fill: 0, count: 16);
    sNewFunc.m_pfnThink = nullptr;
    sNewFunc.m_nNextThinkTick = 0;
    sNewFunc.m_iszContext.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szContext).pszValue;
    return CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(
             this: (CUtlVector<ResponseRules::CResponseSystem::ScriptEntry,CUtlMemory<ResponseRules::CResponseSystem::ScriptEntry,int> > *)&this->m_aThinkFunctions,
             elem: this->m_aThinkFunctions.m_Size,
             src: (const ResponseRules::CResponseSystem::ScriptEntry *)&sNewFunc);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CDE70
// Name: public: void CBaseEntity::SetNextThink(float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetNextThink(CBaseEntity *this, float thinkTime, const char *szContext)
{
  int v4; // edi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_nNextThinkTick> *p_m_nNextThinkTick; // ebx
  bool v6; // zf
  int m_iEFlags; // edi
  int v8; // edi
  int IndexForThinkContext; // eax

  if ( thinkTime == -1.0 )
    v4 = -1;
  else
    v4 = (int)(float)((float)(thinkTime / gpGlobals->interval_per_tick) + 0.5);
  if ( szContext != nullptr )
  {
    IndexForThinkContext = CBaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
    if ( IndexForThinkContext == -1 )
      IndexForThinkContext = CBaseEntity::RegisterThinkContext(this, szContext);
    this->m_aThinkFunctions.m_Memory.m_pMemory[IndexForThinkContext].m_nNextThinkTick = v4;
  }
  else
  {
    p_m_nNextThinkTick = &this->m_nNextThinkTick;
    if ( this->m_nNextThinkTick.m_Value != v4 )
    {
      this->NetworkStateChanged_m_nNextThinkTick(this, a2: &this->m_nNextThinkTick);
      p_m_nNextThinkTick->m_Value = v4;
    }
  }
  v6 = v4 == -1;
  m_iEFlags = this->m_iEFlags;
  if ( (m_iEFlags & 0x400000) != 0 )
  {
    if ( !v6 )
    {
      v8 = m_iEFlags & 0xFFBFFFFF;
LABEL_17:
      this->m_iEFlags = v8;
      goto LABEL_18;
    }
  }
  else if ( !v6 )
  {
    goto LABEL_18;
  }
  if ( (this->m_iEFlags & 0x400000) == 0 && CBaseEntity::WillThink(this) == 0 )
  {
    v8 = m_iEFlags | 0x400000;
    goto LABEL_17;
  }
LABEL_18:
  SimThink_EntityChanged(pEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x100CDF40
// Name: private: void CBaseEntity::SetNextThink(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetNextThink(CBaseEntity *this, int nContextIndex, float thinkTime)
{
  int v5; // esi
  bool v6; // zf
  int m_iEFlags; // esi
  int v8; // esi
  int v9; // esi
  int thinkTick; // [esp+Ch] [ebp+Ch]

  if ( thinkTime == -1.0 )
    thinkTick = -1;
  else
    thinkTick = (int)(float)((float)(thinkTime / gpGlobals->interval_per_tick) + 0.5);
  if ( nContextIndex < 0 )
  {
    if ( thinkTime == -1.0 )
      v5 = -1;
    else
      v5 = (int)(float)((float)(thinkTime / gpGlobals->interval_per_tick) + 0.5);
    if ( this->m_nNextThinkTick.m_Value != v5 )
    {
      this->NetworkStateChanged_m_nNextThinkTick(this, a2: &this->m_nNextThinkTick);
      this->m_nNextThinkTick.m_Value = v5;
    }
    v6 = v5 == -1;
    m_iEFlags = this->m_iEFlags;
    if ( (m_iEFlags & 0x400000) != 0 )
    {
      if ( !v6 )
      {
        this->m_iEFlags = m_iEFlags & 0xFFBFFFFF;
        SimThink_EntityChanged(pEntity: this);
        goto LABEL_19;
      }
    }
    else if ( !v6 )
    {
LABEL_17:
      SimThink_EntityChanged(pEntity: this);
      goto LABEL_19;
    }
    if ( (this->m_iEFlags & 0x400000) == 0 && CBaseEntity::WillThink(this) == 0 )
      this->m_iEFlags = m_iEFlags | 0x400000;
    goto LABEL_17;
  }
  this->m_aThinkFunctions.m_Memory.m_pMemory[nContextIndex].m_nNextThinkTick = thinkTick;
LABEL_19:
  v8 = this->m_iEFlags;
  if ( (v8 & 0x400000) != 0 )
  {
    if ( thinkTick != -1 )
    {
      v9 = v8 & 0xFFBFFFFF;
LABEL_26:
      this->m_iEFlags = v9;
      goto LABEL_27;
    }
  }
  else if ( thinkTick != -1 )
  {
    goto LABEL_27;
  }
  if ( (this->m_iEFlags & 0x400000) == 0 && CBaseEntity::WillThink(this) == 0 )
  {
    v9 = v8 | 0x400000;
    goto LABEL_26;
  }
LABEL_27:
  SimThink_EntityChanged(pEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x100CE090
// Name: public: virtual void CBaseEntity::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::VPhysicsUpdate(CBaseEntity *this, IPhysicsObject *pPhysics)
{
  unsigned int m_Index; // eax
  const char *DebugName; // eax
  float z; // edx
  int i; // esi
  const char *v7; // eax
  Vector prevOrigin; // [esp+18h] [ebp-24h] BYREF
  Vector origin; // [esp+24h] [ebp-18h] BYREF
  QAngle angles; // [esp+30h] [ebp-Ch] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  if ( this->m_MoveType.m_Value == 6 )
  {
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      pPhysics->GetPosition(this: pPhysics, a2: &origin, a3: &angles);
      if ( (LODWORD(angles.x) & 0x7F800000) == 0x7F800000
        || (LODWORD(angles.y) & 0x7F800000) == 0x7F800000
        || (LODWORD(angles.x) & 0x7F800000) == 0x7F800000 )
      {
        DebugName = CBaseEntity::GetDebugName(this);
        _Msg(a1: "Infinite angles from vphysics! (entity %s)\n", DebugName);
        angles = vec3_angle;
      }
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      z = this->m_vecAbsOrigin.z;
      *(_QWORD *)&prevOrigin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
      prevOrigin.z = z;
      for ( i = 0; i < 3; ++i )
        *(&angles.x + i) = AngleNormalize(angle: *(&angles.x + i));
      CBaseEntity::NetworkQuantize(this, org: &origin, &angles);
      if ( (LODWORD(origin.x) & 0x7F800000) == 0x7F800000
        || (LODWORD(origin.y) & 0x7F800000) == 0x7F800000
        || (LODWORD(origin.z) & 0x7F800000) == 0x7F800000 )
      {
        v7 = CBaseEntity::GetDebugName(this);
        _Msg(a1: "Infinite origin from vphysics! (entity %s)\n", v7);
      }
      else
      {
        CBaseEntity::SetAbsOrigin(this, absOrigin: &origin);
      }
      CBaseEntity::SetAbsAngles(this, absAngles: &angles);
      if ( pPhysics->IsAsleep(this: pPhysics) && this->m_CollisionGroup.m_Value == 3 )
        CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
      CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: &prevOrigin);
      CBaseEntity::PhysicsRelinkChildren(this, dt: gpGlobals->frametime);
    }
  }
  else if ( this->m_MoveType.m_Value == 7 )
  {
    CBaseEntity::VPhysicsUpdatePusher(this, pPhysics);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE2C0
// Name: public: virtual bool CBulletsTraceFilter::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBulletsTraceFilter::ShouldHitEntity(
        CBulletsTraceFilter *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  CBaseEntity *v4; // edi
  IHandleEntity *v5; // esi
  CBaseEntity *v6; // esi
  unsigned __int16 m_Value; // ax
  bool result; // al

  result = (this->m_PassEntities.m_Size == 0
         || (!staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity)
           ? (v4 = (CBaseEntity *)pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity))
           : (v4 = nullptr),
             (v5 = *this->m_PassEntities.m_Memory.m_pMemory, !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: v5))
           ? (v6 = (CBaseEntity *)v5->__vftable[1].GetRefEHandle(this: v5))
           : (v6 = nullptr),
             v4 == nullptr
          || v6 == nullptr
          || CBaseEntity::GetOwnerEntity(this: v4) != v6
          || ((m_Value = v6->m_Collision.m_usSolidFlags.m_Value) & 4) == 0
          || (m_Value & 2) == 0
          || (v6->m_Collision.m_usSolidFlags.m_Value & 1) == 0))
        && CTraceFilterSimpleList::ShouldHitEntity(this, pHandleEntity, contentsMask);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CE370
// Name: public: virtual void CBaseEntity::FireBullets(struct FireBulletsInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CBaseEntity::FireBullets(
        CBaseEntity *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const FireBulletsInfo_t *info)
{
  CAmmoDef *AmmoDef; // eax
  int v7; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  int v9; // eax
  bool (__thiscall *IsPlayer)(CBaseEntity *); // eax
  int x_low; // xmm0_4
  float y; // xmm0_4
  bool v13; // sf
  IHandleEntity *m_pPassEnt; // eax
  CBaseEntity_vtbl *v15; // edx
  int m_iObjectsPenetrated; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  const Vector *v19; // eax
  float m_flDistance; // xmm1_4
  bool (__thiscall *v21)(CBaseEntity *); // edx
  float v22; // xmm0_4
  float v23; // xmm3_4
  int v24; // xmm1_4
  float v25; // xmm2_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  float x; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float m_flDamageForceScale; // xmm0_4
  int v31; // edx
  float m_flDamage; // xmm0_4
  int (__thiscall ***v33)(_DWORD, _DWORD); // eax
  int (__thiscall ***v34)(_DWORD, _DWORD); // eax
  int v35; // eax
  CBaseEntity *v36; // ecx
  int v37; // eax
  CBaseEntity *v38; // ecx
  float v39; // xmm0_4
  const char *v40; // eax
  surfacedata_t *v41; // eax
  int v42; // ecx
  int m_iTracerFreq; // ecx
  int v44; // edx
  CBaseEntity_vtbl *v45; // eax
  void (__thiscall **v46)(CBaseEntity *, Vector *, float *, _DWORD); // eax
  int m_iAmmoType; // [esp+30h] [ebp-270h]
  int v48; // [esp+30h] [ebp-270h]
  float v50; // [esp+44h] [ebp-25Ch] BYREF
  float v51; // [esp+48h] [ebp-258h]
  float v52; // [esp+4Ch] [ebp-254h]
  CTakeDamageInfo dmgInfo; // [esp+50h] [ebp-250h] BYREF
  float z; // [esp+ACh] [ebp-1F4h]
  CShotManipulator Manipulator; // [esp+B0h] [ebp-1F0h] BYREF
  CEffectData data; // [esp+E0h] [ebp-1C0h] BYREF
  int v57; // [esp+144h] [ebp-15Ch]
  int v58; // [esp+148h] [ebp-158h]
  Vector v59; // [esp+14Ch] [ebp-154h] BYREF
  Vector v60; // [esp+158h] [ebp-148h] BYREF
  Vector vecTracerSrc; // [esp+164h] [ebp-13Ch] BYREF
  CGameTrace Tracer; // [esp+170h] [ebp-130h] BYREF
  Vector startpos; // [esp+1C8h] [ebp-D8h] BYREF
  Vector vecTracerDest; // [esp+1D4h] [ebp-CCh] BYREF
  CGameTrace tr; // [esp+1E0h] [ebp-C0h] BYREF
  CBulletsTraceFilter traceFilter; // [esp+238h] [ebp-68h] BYREF
  Vector vecEnd; // [esp+25Ch] [ebp-44h] BYREF
  Vector vecDir; // [esp+268h] [ebp-38h]
  CAmmoDef *pAmmoDef; // [esp+274h] [ebp-2Ch]
  float flCumulativeDamage; // [esp+278h] [ebp-28h]
  int flActualDamage; // [esp+27Ch] [ebp-24h]
  int iSeed; // [esp+280h] [ebp-20h]
  int flPlayerDamage; // [esp+284h] [ebp-1Ch]
  int iShot; // [esp+288h] [ebp-18h]
  CBaseEntity *pAttacker; // [esp+28Ch] [ebp-14h]
  int nAmmoFlags; // [esp+290h] [ebp-10h]
  int nDamageType; // [esp+294h] [ebp-Ch] BYREF
  int nActualDamageType; // [esp+298h] [ebp-8h]
  int retaddr; // [esp+2A0h] [ebp+0h]

  nDamageType = a2;
  nActualDamageType = retaddr;
  AmmoDef = GetAmmoDef();
  m_iAmmoType = info->m_iAmmoType;
  LODWORD(vecDir.x) = AmmoDef;
  v7 = CAmmoDef::DamageType(this: AmmoDef, nAmmoIndex: m_iAmmoType);
  v48 = info->m_iAmmoType;
  iShot = v7;
  flPlayerDamage = CAmmoDef::Flags(this: (CAmmoDef *)LODWORD(vecDir.x), nAmmoIndex: v48);
  if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, int, int))this->IsPlayer)(a1: this, a2: a3, a3: a4) != 0 )
  {
    pAttacker = (CBaseEntity *)__RTDynamicCast(
                                 inptr: this,
                                 VfDelta: 0,
                                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                                 TargetType: &CBasePlayer `RTTI Type Descriptor',
                                 isReference: 0);
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: (CBaseCombatCharacter *)pAttacker);
    v9 = ActiveWeapon->GetRumbleEffect(this: ActiveWeapon);
    if ( v9 != -1 )
    {
      if ( v9 == 5 && info->m_iShots == 12 )
        v9 = 6;
      ((void (__thiscall *)(CBaseEntity *, int, _DWORD, int))pAttacker->__vftable[1].NetworkStateChanged_m_iMaxHealth_2)(
        a1: pAttacker,
        a2: v9,
        a3: 0,
        a4: 4);
    }
  }
  flCumulativeDamage = info->m_flPlayerDamage;
  if ( flCumulativeDamage == 0.0 && (flPlayerDamage & 2) != 0 )
    flCumulativeDamage = (float)CAmmoDef::PlrDamage(this: (CAmmoDef *)LODWORD(vecDir.x), nAmmoIndex: info->m_iAmmoType);
  iSeed = (int)info->m_pAttacker;
  if ( iSeed == 0 )
    iSeed = (int)this;
  if ( g_MultiDamage.m_hTarget.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber == HIWORD(g_MultiDamage.m_hTarget.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity != nullptr )
  {
    ApplyMultiDamage();
  }
  ClearMultiDamage();
  g_MultiDamage.m_bitsDamageType = iShot | 0x1000;
  CTraceFilterSimpleList::CTraceFilterSimpleList(this: (CTraceFilterSimpleList *)&tr.m_pEnt, collisionGroup: 0);
  pAttacker = info->m_pAdditionalIgnoreEnt;
  tr.m_pEnt = (CBaseEntity *)&CBulletsTraceFilter::`vftable';
  tr.hitbox = (int)this;
  CTraceFilterSimpleList::AddEntityToIgnore(this: (CTraceFilterSimpleList *)&tr.m_pEnt, pEntity: pAttacker);
  IsPlayer = this->IsPlayer;
  pAmmoDef = nullptr;
  if ( IsPlayer(this) )
    pAmmoDef = (CAmmoDef *)(unsigned __int8)CBaseEntity::m_nPredictionRandomSeed;
  x_low = LODWORD(info->m_vecDirShooting.x);
  pAttacker = (CBaseEntity *)&Manipulator.m_vecRight;
  dmgInfo.m_iObjectsPenetrated = x_low;
  y = info->m_vecDirShooting.y;
  iShot = (int)&Manipulator;
  *(float *)&dmgInfo.m_uiBulletID = y;
  z = info->m_vecDirShooting.z;
  VectorVectors(
    forward: (const Vector *)&dmgInfo.m_iObjectsPenetrated,
    right: &Manipulator.m_vecShotDirection,
    up: &Manipulator.m_vecRight);
  vecDir.y = 0.0;
  for ( flActualDamage = 0; flActualDamage < info->m_iShots; ++flActualDamage )
  {
    v15 = this->__vftable;
    HIWORD(nAmmoFlags) = 0;
    if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, _DWORD))v15->IsPlayer)(
           a1: this,
           a2: (unsigned __int16)nAmmoFlags) != 0 )
      _RandomSeed(a1: pAmmoDef);
    if ( flActualDamage != 0 || info->m_iShots <= 1 || (info->m_nFlags & 1) == 0 )
    {
      v19 = CShotManipulator::ApplySpread(
              this: (CShotManipulator *)&dmgInfo.m_iObjectsPenetrated,
              vecSpread: &info->m_vecSpread,
              bias: 1.0);
      m_iObjectsPenetrated = SLODWORD(v19->x);
      vecEnd.x = v19->x;
      v17 = v19->y;
      vecEnd.y = v17;
      v18 = v19->z;
    }
    else
    {
      m_iObjectsPenetrated = dmgInfo.m_iObjectsPenetrated;
      v17 = *(float *)&dmgInfo.m_uiBulletID;
      v18 = z;
      LODWORD(vecEnd.x) = dmgInfo.m_iObjectsPenetrated;
      LODWORD(vecEnd.y) = dmgInfo.m_uiBulletID;
    }
    m_flDistance = info->m_flDistance;
    v21 = this->IsPlayer;
    v22 = m_flDistance;
    vecEnd.z = v18;
    v23 = v18 * m_flDistance;
    *(float *)&v24 = info->m_vecSrc.y + (float)(v17 * m_flDistance);
    v25 = info->m_vecSrc.z + v23;
    *(float *)&traceFilter.m_PassEntities.m_Memory.m_nGrowSize = (float)(v22 * *(float *)&m_iObjectsPenetrated)
                                                               + info->m_vecSrc.x;
    traceFilter.m_PassEntities.m_Size = v24;
    *(float *)&traceFilter.m_PassEntities.m_pElements = v25;
    if ( v21(this) && info->m_iShots > 1 && flActualDamage % 2 != 0 )
    {
      data.m_iEffectName = 1077936128;
      v57 = 1077936128;
      v58 = 1077936128;
      v59.x = -3.0;
      v59.y = -3.0;
      v59.z = -3.0;
      *(_DWORD *)&Tracer.dispFlags = 0;
      Ray_t::Init(
        this: (Ray_t *)&vecTracerSrc,
        start: &info->m_vecSrc,
        end: (const Vector *)&traceFilter.m_PassEntities.m_Memory.m_nGrowSize,
        mins: &v59,
        maxs: (const Vector *)&data.m_iEffectName);
      TraceRay = enginetrace->TraceRay;
      nAmmoFlags = (int)&vecTracerDest;
      ((void (__thiscall *)(IEngineTrace *, Vector *, int, CBaseEntity **))TraceRay)(
        a1: enginetrace,
        a2: &vecTracerSrc,
        a3: 1174421507,
        a4: &tr.m_pEnt);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      {
        pAttacker = (CBaseEntity *)-1082130432;
        iShot = 1;
        flPlayerDamage = 0;
        iSeed = 255;
LABEL_48:
        DebugDrawLine(
          vecAbsStart: &vecTracerDest,
          vecAbsEnd: &tr.startpos,
          r: 255,
          g: iSeed,
          b: flPlayerDamage,
          test: iShot,
          duration: *(float *)&pAttacker);
      }
    }
    else
    {
      x = info->m_vecSrc.x;
      v28 = info->m_vecSrc.y;
      v29 = info->m_vecSrc.z;
      Tracer.startpos.z = *(float *)&traceFilter.m_PassEntities.m_Size - v28;
      Tracer.startpos.y = *(float *)&traceFilter.m_PassEntities.m_Memory.m_nGrowSize - x;
      Tracer.endpos.x = *(float *)&traceFilter.m_PassEntities.m_pElements - v29;
      BYTE1(Tracer.fractionleftsolid) = (float)((float)((float)(Tracer.startpos.z * Tracer.startpos.z)
                                                      + (float)(Tracer.startpos.y * Tracer.startpos.y))
                                              + (float)(Tracer.endpos.x * Tracer.endpos.x)) != 0.0;
      nAmmoFlags = (int)&vecTracerDest;
      memset(&Tracer.plane.dist, 0, 12);
      *(_DWORD *)&Tracer.dispFlags = 0;
      LOBYTE(Tracer.fractionleftsolid) = 1;
      memset(&Tracer.endpos.z, 0, 12);
      vecTracerSrc.x = x;
      vecTracerSrc.y = v28;
      vecTracerSrc.z = v29;
      ((void (__thiscall *)(IEngineTrace *, Vector *, int, CBaseEntity **))enginetrace->TraceRay)(
        a1: enginetrace,
        a2: &vecTracerSrc,
        a3: 1174421507,
        a4: &tr.m_pEnt);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      {
        pAttacker = (CBaseEntity *)-1082130432;
        iShot = 1;
        flPlayerDamage = 0;
        iSeed = 0;
        goto LABEL_48;
      }
    }
    if ( tr.plane.pad[1] != 0 )
    {
      tr.startpos = vecTracerDest;
      tr.plane.normal.z = 0.0;
    }
    if ( ai_debug_shoot_positions.m_pParent != nullptr && ai_debug_shoot_positions.m_pParent->m_Value.m_nValue != 0 )
      NDebugOverlay::Line(
        origin: &info->m_vecSrc,
        target: (const Vector *)&traceFilter.m_PassEntities.m_Memory.m_nGrowSize,
        r: 255,
        g: 255,
        b: 255,
        noDepthTest: false,
        duration: 0.1);
    CTakeDamageInfo::CTakeDamageInfo(
      this: (CTakeDamageInfo *)&v50,
      pInflictor: (CBaseEntity *)iSeed,
      pAttacker: (CBaseEntity *)iSeed,
      flDamage: info->m_flDamage,
      bitsDamageType: iShot,
      iKillType: 0,
      iObjectsPenetrated: 0);
    CalculateBulletDamageForce(
      info: (CTakeDamageInfo *)&v50,
      iBulletType: info->m_iAmmoType,
      vecBulletDir: &vecEnd,
      vecForceOrigin: &tr.startpos,
      flScale: 1.0);
    m_flDamageForceScale = info->m_flDamageForceScale;
    v31 = info->m_iAmmoType;
    v50 = v50 * m_flDamageForceScale;
    dmgInfo.m_bitsDamageType = v31;
    v51 = v51 * m_flDamageForceScale;
    v52 = v52 * m_flDamageForceScale;
    CBaseEntity::TraceAttackToTriggers(
      this,
      a2: (int)&nDamageType,
      info: (const CTakeDamageInfo *)&v50,
      start: &vecTracerDest,
      end: &tr.startpos,
      dir: &vecEnd);
    if ( info->m_iAmmoType == -1 )
    {
      DevMsg(a1: "ERROR: Undefined ammo type!\n");
      goto LABEL_24;
    }
    startpos = tr.startpos;
    if ( tr.plane.normal.z != 1.0 )
    {
      CBaseEntity::UpdateShotStatistics(this, tr: (const CGameTrace *)&vecTracerDest);
      CSoundEnt::InsertSound(
        iType: 16,
        vecOrigin: &tr.startpos,
        iVolume: 200,
        flDuration: 0.5,
        pOwner: this,
        soundChannelIndex: (info->m_nFlags & 8) != 0 ? 6 : 0,
        pSoundTarget: nullptr);
      if ( (enginetrace->GetPointContents(this: enginetrace, a2: (const Vector *)&tr, a3: 16432, a4: nullptr) & 0x30) != 0 )
        BYTE2(nAmmoFlags) = CBaseEntity::HandleShotImpactingWater(
                              this,
                              info,
                              vecEnd: (const Vector *)&traceFilter.m_PassEntities.m_Memory.m_nGrowSize,
                              pTraceFilter: (ITraceFilter *)&tr.m_pEnt,
                              pVecTracerDest: &startpos);
      m_flDamage = info->m_flDamage;
      vecDir.z = m_flDamage;
      if ( flCumulativeDamage != 0.0 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps + 336))(a1: *(_DWORD *)&tr.surface.surfaceProps) != 0 )
        {
          m_flDamage = flCumulativeDamage;
        }
        else if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps + 364))(a1: *(_DWORD *)&tr.surface.surfaceProps) != 0
               && (v33 = (int (__thiscall ***)(_DWORD, _DWORD))(*(int (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps
                                                                                             + 364))(a1: *(_DWORD *)&tr.surface.surfaceProps),
                   (**v33)(a1: v33, a2: 0) != 0)
               && (v34 = (int (__thiscall ***)(_DWORD, _DWORD))(*(int (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps
                                                                                             + 364))(a1: *(_DWORD *)&tr.surface.surfaceProps),
                   v35 = (**v34)(a1: v34, a2: 0),
                   (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v35 + 336))(a1: v35) != 0) )
        {
          m_flDamage = flCumulativeDamage;
        }
        else
        {
          m_flDamage = vecDir.z;
        }
      }
      v36 = (CBaseEntity *)iShot;
      pAttacker = (CBaseEntity *)iShot;
      if ( m_flDamage == 0.0 )
      {
        vecDir.z = g_pGameRules->GetAmmoDamage(
                     this: g_pGameRules,
                     a2: (CBaseEntity *)iSeed,
                     a3: *(CBaseEntity **)&tr.surface.surfaceProps,
                     a4: info->m_iAmmoType);
        m_flDamage = vecDir.z;
      }
      else
      {
        v37 = 0x2000;
        if ( m_flDamage <= 16.0 )
          v37 = 4096;
        pAttacker = (CBaseEntity *)(iShot | v37);
      }
      if ( BYTE2(nAmmoFlags) == 0 || (info->m_nFlags & 2) == 0 )
      {
        CTakeDamageInfo::CTakeDamageInfo(
          this: (CTakeDamageInfo *)&vecTracerSrc,
          pInflictor: this,
          pAttacker: v36,
          flDamage: m_flDamage,
          bitsDamageType: (int)pAttacker,
          iKillType: 0,
          iObjectsPenetrated: 0);
        pAttacker = v38;
        CalculateBulletDamageForce(
          info: (CTakeDamageInfo *)&vecTracerSrc,
          iBulletType: info->m_iAmmoType,
          vecBulletDir: &vecEnd,
          vecForceOrigin: &tr.startpos,
          flScale: 1.0);
        v39 = info->m_flDamageForceScale;
        v40 = (const char *)info->m_iAmmoType;
        vecTracerSrc.x = vecTracerSrc.x * v39;
        vecTracerSrc.y = vecTracerSrc.y * v39;
        Tracer.surface.name = v40;
        vecTracerSrc.z = vecTracerSrc.z * v39;
        if ( (*(unsigned __int8 (__stdcall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps + 252))(a1: *(_DWORD *)&tr.surface.surfaceProps) != 0 )
          pAttacker->TraceAttack(
            this: pAttacker,
            a2: (const CTakeDamageInfo *)&vecTracerSrc,
            a3: &vecEnd,
            a4: (CGameTrace *)&vecTracerDest);
        if ( *(_DWORD *)&tr.surface.surfaceProps != 0
          && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps + 300))(a1: *(_DWORD *)&tr.surface.surfaceProps) != 0 )
        {
          vecDir.y = Tracer.plane.dist + vecDir.y;
        }
        if ( BYTE2(nAmmoFlags) == 0 || (info->m_nFlags & 4) != 0 )
        {
          this->DoImpactEffect(this, a2: (CGameTrace *)&vecTracerDest, a3: iShot);
        }
        else
        {
          memset((void *)&data.m_vStart, 0, 32);
          memset(&data.m_fFlags, 0, 14);
          data.m_vOrigin = vecTracerDest;
          data.m_flRadius = 0.0;
          memset(&data.m_nSurfaceProp, 0, 9);
          Manipulator.m_vecResult = tr.startpos;
          data.m_vAngles.z = 1.0;
          data.m_nAttachmentIndex = iShot;
          DispatchEffect(pName: "RagdollImpact", data: (const CEffectData *)&Manipulator.m_vecResult);
        }
        if ( (flPlayerDamage & 1) != 0 )
          Pickup_ForcePlayerToDropThisObject(pTarget: *(CBaseEntity **)&tr.surface.surfaceProps);
      }
    }
    if ( *(_DWORD *)&tr.surface.surfaceProps != 0 )
    {
      v41 = physprops->GetSurfaceData(this: physprops, a2: (__int16)tr.dispFlags);
      if ( v41 != nullptr && v41->game.material == 89 )
      {
        v42 = *(_DWORD *)&tr.surface.surfaceProps;
        if ( *(const char **)(*(_DWORD *)&tr.surface.surfaceProps + 92) != "func_breakable" )
        {
          if ( CBaseEntity::ClassMatchesComplex(
                 this: *(CBaseEntity **)&tr.surface.surfaceProps,
                 pszClassOrWildcard: "func_breakable") == 0 )
            goto LABEL_92;
          v42 = *(_DWORD *)&tr.surface.surfaceProps;
        }
        if ( (*(_DWORD *)(v42 + 760) & 0x800) == 0 )
          HIBYTE(nAmmoFlags) = 1;
      }
    }
LABEL_92:
    m_iTracerFreq = info->m_iTracerFreq;
    if ( m_iTracerFreq == 0 || (v44 = tracerCount % m_iTracerFreq, ++tracerCount, v44 != 0) )
    {
      if ( HIBYTE(nAmmoFlags) != 0 )
LABEL_97:
        CBaseEntity::HandleShotImpactingGlass(
          this,
          info,
          tr: (const CGameTrace *)&vecTracerDest,
          vecDir: &vecEnd,
          pTraceFilter: (ITraceFilter *)&tr.m_pEnt);
    }
    else
    {
      if ( HIBYTE(nAmmoFlags) != 0 )
        goto LABEL_97;
      v60 = vec3_origin;
      CBaseEntity::ComputeTracerStartPosition(this, vecShotSrc: &info->m_vecSrc, pVecTracerStart: &v60);
      CGameTrace::operator=(this: (CGameTrace *)&vecTracerSrc.z, __that: (const CGameTrace *)&vecTracerDest);
      v45 = this->__vftable;
      *(Vector *)&Tracer.startpos.z = startpos;
      v46 = (void (__thiscall **)(CBaseEntity *, Vector *, float *, _DWORD))CAmmoDef::TracerType(
                                                                              this: (CAmmoDef *)LODWORD(vecDir.x),
                                                                              nAmmoIndex: (int)&v45->MakeTracer);
      (*v46)(a1: this, a2: &v60, a3: &vecTracerSrc.z, a4: v46);
    }
    pAmmoDef = (CAmmoDef *)((char *)pAmmoDef + 1);
  }
  ApplyMultiDamage();
  if ( this->IsPlayer(this) && vecDir.y > 0.0 )
  {
    CTakeDamageInfo::CTakeDamageInfo(
      this: (CTakeDamageInfo *)&v50,
      pInflictor: this,
      pAttacker: (CBaseEntity *)iSeed,
      flDamage: vecDir.y,
      bitsDamageType: iShot,
      iKillType: 0,
      iObjectsPenetrated: 0);
    flPlayerDamage = (int)CBaseCombatCharacter::GetActiveWeapon((CBaseCombatCharacter *)this)->m_iClassname.pszValue;
    if ( flPlayerDamage == 0 )
      flPlayerDamage = (int)locale;
    ((void (__stdcall *)(CBaseEntity *, bool, int, float *))gamestats->Event_WeaponHit)(
      a1: this,
      a2: info->m_bPrimaryAttack,
      a3: flPlayerDamage,
      a4: &v50);
  }
LABEL_24:
  v13 = (int)traceFilter.m_pExtraShouldHitCheckFunction < 0;
  m_pPassEnt = (IHandleEntity *)traceFilter.m_pPassEnt;
  traceFilter.m_PassEntities.m_Memory.m_pMemory = nullptr;
  if ( (int)traceFilter.m_pExtraShouldHitCheckFunction >= 0 )
  {
    if ( traceFilter.m_pPassEnt != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)traceFilter.m_pPassEnt);
      m_pPassEnt = nullptr;
      traceFilter.m_pPassEnt = nullptr;
    }
    v13 = (int)traceFilter.m_pExtraShouldHitCheckFunction < 0;
    traceFilter.m_collisionGroup = 0;
  }
  traceFilter.m_PassEntities.m_Memory.m_nAllocationCount = (int)m_pPassEnt;
  if ( !v13 && m_pPassEnt != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pPassEnt);
}

//------------------------------------------------------------------------------
// Address: 0x100CDDD0
// Name: public: void (CBaseEntity::*CBaseEntity::ThinkSet(void (CBaseEntity::*)(void),float,char const __near *))(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__thiscall *__thiscall CBaseEntity::ThinkSet(
        CBaseEntity *this,
        void (__thiscall *func)(CBaseEntity *this),
        float thinkTime,
        const char *szContext))(CBaseEntity *this)
{
  int IndexForThinkContext; // eax
  int v7; // ecx
  int v8; // eax

  if ( szContext != nullptr )
  {
    IndexForThinkContext = CBaseEntity::GetIndexForThinkContext(this, pszContext: szContext);
    if ( IndexForThinkContext == -1 )
      IndexForThinkContext = CBaseEntity::RegisterThinkContext(this, szContext);
    v7 = IndexForThinkContext;
    this->m_aThinkFunctions.m_Memory.m_pMemory[IndexForThinkContext].m_pfnThink = func;
    if ( thinkTime != 0.0 )
    {
      if ( thinkTime == -1.0 )
        v8 = -1;
      else
        v8 = (int)(float)((float)(thinkTime / gpGlobals->interval_per_tick) + 0.5);
      this->m_aThinkFunctions.m_Memory.m_pMemory[v7].m_nNextThinkTick = v8;
      CBaseEntity::CheckHasThinkFunction(this, isThinking: v8 != -1);
    }
    return func;
  }
  else
  {
    this->m_pfnThink = func;
    return func;
  }
}

} // namespace server
