// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_breakablesurf.cpp
// Functions: 43
// ============================================================

#include "game\server\func_breakablesurf.h"

//------------------------------------------------------------------------------
// Address: 0x10134360
// Name: public: virtual struct datamap_t __near * CWindowPane::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWindowPane::GetDataDescMap(CWindowPane *this)
{
  return &CWindowPane::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10134370
// Name: class QAngle RandomAngle(float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
QAngle *__cdecl RandomAngle(QAngle *result, float minVal, float maxVal)
{
  IUniformRandomStream *v3; // ecx
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx
  double v6; // st7
  float random; // [esp+8h] [ebp-Ch]
  float random_4; // [esp+Ch] [ebp-8h]

  _RandomFloat(this: v3, a2: minVal, a3: maxVal);
  _RandomFloat(this: v4, a2: minVal, a3: maxVal);
  v6 = _RandomFloat(this: v5, a2: minVal, a3: maxVal);
  result->x = random;
  result->y = random_4;
  result->z = v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101343F0
// Name: public: virtual void CWindowPane::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWindowPane::Precache(CWindowPane *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/brokenglass_piece.mdl", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10134400
// Name: private: virtual struct datamap_t __near * CBreakableSurface::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBreakableSurface::GetDataDescMap(CBreakableSurface *this)
{
  return &CBreakableSurface::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10134410
// Name: public: virtual class ServerClass __near * CBreakableSurface::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBreakableSurface::GetServerClass(CBreakableSurface *this)
{
  return &g_CBreakableSurface_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10134420
// Name: public: void CWindowPane::Die(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWindowPane::Die(CWindowPane *this)
{
  CPASFilter filter; // [esp+44h] [ebp-20h] BYREF
  int savedregs; // [esp+64h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &this->m_vecAbsOrigin);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  ((void (__stdcall *)(CPASFilter *, _DWORD, Vector *, QAngle *, Vector *, Vector *, int, int, int, _DWORD, int, int, int, int, int, int))te->ShatterSurface)(
    a1: &filter,
    a2: 0,
    a3: &this->m_vecAbsOrigin,
    a4: &this->m_angAbsRotation,
    a5: &this->m_vecAbsVelocity,
    a6: &this->m_vecAbsOrigin,
    a7: 1094713344,
    a8: 1094713344,
    a9: 1082130432,
    a10: 0,
    a11: 255,
    a12: 255,
    a13: 255,
    a14: 255,
    a15: 255,
    a16: 255);
  UTIL_Remove(oldObj: this);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10134550
// Name: public: virtual void CBreakableSurface::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBreakableSurface::Precache(CBreakableSurface *this@<ecx>, int a2@<ebp>)
{
  UTIL_PrecacheOther(szClassname: "window_pane", modelName: nullptr);
  if ( this->m_nSurfaceType.m_Value == SHATTERSURFACE_TILE )
  {
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_03a");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_03b");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_03c");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_03d");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_02a");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_02b");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_02c");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_02d");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_01a");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_01b");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_01c");
    PrecacheMaterial(pMaterialName: "models/brokentile/tilebroken_01d");
  }
  else
  {
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_solid");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_01a");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_01b");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_01c");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_01d");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_02a");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_02b");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_02c");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_02d");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_03a");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_03b");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_03c");
    PrecacheMaterial(pMaterialName: "models/brokenglass/glassbroken_03d");
  }
  PrecacheEffect(pEffectName: "GlassImpact");
  PrecacheEffect(pEffectName: "Impact");
  CBreakable::Precache(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101346A0
// Name: public: bool CBreakableSurface::IsBroken(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBreakableSurface::IsBroken(CBreakableSurface *this, int nWidth, int nHeight)
{
  return nWidth < 0
      || nWidth >= this->m_nNumWide.m_Value
      || nHeight < 0
      || nHeight >= this->m_nNumHigh.m_Value
      || this->m_flSupport[nWidth][nHeight] == -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10134700
// Name: public: float CBreakableSurface::RecalcSupport(int,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakableSurface::RecalcSupport(CBreakableSurface *this, int nWidth, int nHeight)
{
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  int v9; // ebx
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  int v20; // [esp+0h] [ebp-4h]

  v20 = this->m_nNumHigh.m_Value - 1;
  if ( nHeight == v20 )
  {
    v3 = 1.01;
  }
  else
  {
    v4 = *((float *)&this->m_pfnMoveDone + 16 * nWidth + nHeight + 270);
    if ( v4 < 0.0 )
      v4 = 0.0;
    v3 = v4 + 0.0099999998;
  }
  if ( nHeight != 0 )
  {
    v6 = this->m_flSupport[nWidth - 1][nHeight + 15];
    if ( v6 < 0.0 )
      v6 = 0.0;
    v5 = (float)(v6 * 1.25) + v3;
  }
  else
  {
    v5 = v3 + 1.25;
  }
  if ( nWidth != 0 )
  {
    v8 = *(&this->m_explodeRadius + 16 * nWidth + nHeight);
    if ( v8 < 0.0 )
      v8 = 0.0;
    v7 = v8 + v5;
  }
  else
  {
    v7 = v5 + 1.0;
  }
  v9 = this->m_nNumWide.m_Value - 1;
  if ( nWidth == v9 )
  {
    v10 = v7 + 1.0;
  }
  else
  {
    v11 = *((float *)&this->m_Network + 16 * nWidth + nHeight + 283);
    if ( v11 < 0.0 )
      v11 = 0.0;
    v10 = v11 + v7;
  }
  if ( nHeight != 0 && nWidth != 0 )
  {
    v12 = *((float *)&this->m_PerformanceMode + 16 * nWidth + nHeight);
    if ( v12 < 0.0 )
      v12 = 0.0;
    v13 = v12 + v10;
  }
  else
  {
    v13 = v10 + 1.0;
  }
  if ( nHeight == 0 || nWidth == v9 )
  {
    v15 = v13 + 1.0;
  }
  else
  {
    v14 = *((float *)&this->m_Network + 16 * nWidth + nHeight + 282);
    if ( v14 < 0.0 )
      v14 = 0.0;
    v15 = v14 + v13;
  }
  if ( nHeight == v20 || nWidth == v9 )
  {
    v17 = v15 + 0.25;
  }
  else
  {
    v16 = *((float *)&this->m_Network + 16 * nWidth + nHeight + 284);
    if ( v16 < 0.0 )
      v16 = 0.0;
    v17 = (float)(v16 * 0.25) + v15;
  }
  if ( nHeight == v20 || nWidth == 0 )
    return (float)(v17 + 0.25);
  v18 = *((float *)&this->m_pfnMoveDone + 16 * nWidth + nHeight + 254);
  if ( v18 < 0.0 )
    v18 = 0.0;
  return (float)((float)(v18 * 0.25) + v17);
}

//------------------------------------------------------------------------------
// Address: 0x101348E0
// Name: public: void CBreakableSurface::PanePos(class Vector const __near &,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::PanePos(
        CBreakableSurface *this,
        const Vector *vPos,
        float *flWidth,
        float *flHeight)
{
  float x; // xmm1_4
  float v6; // xmm0_4
  QAngle vAngles; // [esp+0h] [ebp-3Ch] BYREF
  Vector vHeightDir; // [esp+Ch] [ebp-30h] BYREF
  Vector vWidthDir; // [esp+18h] [ebp-24h] BYREF
  Vector forward; // [esp+24h] [ebp-18h] BYREF
  Vector vAttackVec; // [esp+30h] [ebp-Ch]

  x = this->m_vNormal.m_Value.x;
  vAttackVec.x = vPos->x - this->m_vCorner.m_Value.x;
  vAttackVec.y = vPos->y - this->m_vCorner.m_Value.y;
  vAttackVec.z = vPos->z - this->m_vCorner.m_Value.z;
  forward.x = x * -1.0;
  forward.y = this->m_vNormal.m_Value.y * -1.0;
  forward.z = this->m_vNormal.m_Value.z * -1.0;
  VectorAngles(&forward, angles: &vAngles);
  AngleVectors(angles: &vAngles, forward: nullptr, right: &vWidthDir, up: &vHeightDir);
  v6 = vHeightDir.y * vAttackVec.y;
  *flWidth = (float)((float)((float)(vAttackVec.x * vWidthDir.x) + (float)(vWidthDir.y * vAttackVec.y))
                   + (float)(vWidthDir.z * vAttackVec.z))
           / this->m_flPanelWidth.m_Value;
  *flHeight = (float)((float)((float)(vHeightDir.x * vAttackVec.x) + v6) + (float)(vHeightDir.z * vAttackVec.z))
            / this->m_flPanelHeight.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101349F0
// Name: public: void CBreakableSurface::CreateShards(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::CreateShards(
        CBreakableSurface *this,
        const Vector *vBreakPos,
        const QAngle *vAngles,
        const Vector *vForce,
        const Vector *vForcePos,
        float flWidth,
        float flHeight,
        int nShardSize)
{
  __int64 v8; // xmm0_8
  bool v10; // zf
  float z; // ecx
  float v12; // xmm2_4
  float v13; // xmm3_4
  float y; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float x; // xmm0_4
  int v18; // edi
  int v19; // ebx
  CPASFilter filter; // [esp+48h] [ebp-40h] BYREF
  Vector vAdjustedForce; // [esp+68h] [ebp-20h] BYREF
  Vector vAdjustedBreakPos; // [esp+74h] [ebp-14h] BYREF
  int front_b; // [esp+80h] [ebp-8h]
  int back_r; // [esp+84h] [ebp-4h]
  int back_b; // [esp+90h] [ebp+8h]
  int back_g; // [esp+98h] [ebp+10h]

  v8 = *(_QWORD *)&vBreakPos->x;
  vAdjustedBreakPos.z = vBreakPos->z;
  v10 = this->m_nSurfaceType.m_Value == SHATTERSURFACE_TILE;
  z = vForce->z;
  *(_QWORD *)&vAdjustedBreakPos.x = v8;
  *(_QWORD *)&vAdjustedForce.x = *(_QWORD *)&vForce->x;
  vAdjustedForce.z = z;
  if ( v10 )
  {
    v12 = this->m_vNormal.m_Value.z * 8.0;
    v13 = vAdjustedBreakPos.x - (float)(this->m_vNormal.m_Value.x * 8.0);
    y = vForce->y;
    vAdjustedBreakPos.y = vAdjustedBreakPos.y - (float)(this->m_vNormal.m_Value.y * 8.0);
    v15 = vAdjustedBreakPos.z - v12;
    v16 = vForce->z;
    vAdjustedBreakPos.z = v15;
    x = vForce->x;
    vAdjustedBreakPos.x = v13;
    v18 = 89;
    vAdjustedForce.x = x * -0.75;
    vAdjustedForce.y = y * -0.75;
    vAdjustedForce.z = v16 * -0.75;
    v19 = 120;
    front_b = 83;
    back_r = 99;
    back_g = 76;
    back_b = 21;
  }
  else
  {
    v18 = 255;
    v19 = 255;
    front_b = 255;
    back_r = 255;
    back_g = 255;
    back_b = 255;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &vAdjustedBreakPos);
  ((void (__stdcall *)(CPASFilter *, _DWORD, Vector *, const QAngle *, Vector *, const Vector *, _DWORD, _DWORD, int, ShatterSurface_t, int, int, int, int, int, int))te->ShatterSurface)(
    a1: &filter,
    a2: 0,
    a3: &vAdjustedBreakPos,
    a4: vAngles,
    a5: &vAdjustedForce,
    a6: vForcePos,
    a7: LODWORD(flWidth),
    a8: LODWORD(flHeight),
    a9: 1082130432,
    a10: this->m_nSurfaceType.m_Value,
    a11: v18,
    a12: v19,
    a13: front_b,
    a14: back_r,
    a15: back_g,
    a16: back_b);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10134BA0
// Name: public: void CWindowPane::PaneTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWindowPane::PaneTouch(CWindowPane *this, CBaseEntity *pOther)
{
  if ( pOther != nullptr && pOther->m_CollisionGroup.m_Value != 6 )
    CWindowPane::Die(this);
}

//------------------------------------------------------------------------------
// Address: 0x10134E20
// Name: public: void CBreakableSurface::SetSupport(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::SetSupport(CBreakableSurface *this, int w, int h, float support)
{
  int v4; // esi
  CBreakableSurface::NetworkVar_m_RawPanelBitVec *p_m_RawPanelBitVec; // edi
  edict_t *m_pPev; // ecx
  bool *v7; // eax
  CBaseEdict *v8; // ecx

  this->m_flSupport[w][h] = support;
  v4 = w + h * this->m_nNumWide.m_Value;
  if ( support >= 0.0 != this->m_RawPanelBitVec.m_Value[v4] )
  {
    p_m_RawPanelBitVec = &this->m_RawPanelBitVec;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: v4 + 2160);
    }
    p_m_RawPanelBitVec->m_Value[v4] = support >= 0.0;
    v7 = &p_m_RawPanelBitVec[-9].m_Value[144];
    if ( p_m_RawPanelBitVec[-9].m_Value[228] )
    {
      v7[88] |= 1u;
    }
    else
    {
      v8 = *((CBaseEdict **)v7 + 6);
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: v8, offset: v4 + 2160);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134EE0
// Name: public: virtual void CBreakableSurface::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::VPhysicsCollision(CBreakableSurface *this, int index, gamevcollisionevent_t *pEvent)
{
  gamevcollisionevent_t *v3; // esi
  double v6; // st7
  CBaseEntity *v7; // [esp-4h] [ebp-120h]
  CEffectData data; // [esp+2Ch] [ebp-F0h] BYREF
  CGameTrace tr; // [esp+90h] [ebp-8Ch] BYREF
  CBreakableSurface *v10; // [esp+E4h] [ebp-38h]
  int v11; // [esp+E8h] [ebp-34h]
  float v12; // [esp+ECh] [ebp-30h] BYREF
  float v13; // [esp+F0h] [ebp-2Ch]
  float v14; // [esp+F4h] [ebp-28h]
  Vector vecAbsEnd; // [esp+F8h] [ebp-24h] BYREF
  Vector damagePos; // [esp+104h] [ebp-18h] BYREF
  Vector normal; // [esp+110h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+11Ch] [ebp+0h] BYREF
  const char *bDamageFromHeldObjects; // [esp+124h] [ebp+8h]
  float bDamageFromHeldObjectsa; // [esp+124h] [ebp+8h]

  v3 = pEvent;
  if ( this->m_bIsBroken.m_Value )
  {
LABEL_15:
    CBreakable::VPhysicsCollision(this, index: *(float *)&index, pEvent: (int)v3);
    return;
  }
  pEvent = nullptr;
  bDamageFromHeldObjects = "glass";
  if ( this->m_nSurfaceType.m_Value != SHATTERSURFACE_GLASS )
    bDamageFromHeldObjects = nullptr;
  v6 = CalculateDefaultPhysicsDamage(
         index,
         pEvent: v3,
         energyScale: 1.0,
         allowStaticDamage: false,
         damageType: (int *)&pEvent,
         iszDamageTableName: (string_t)bDamageFromHeldObjects,
         bDamageFromHeldObjects: (this->m_spawnflags.m_Value & 2) != 0);
  bDamageFromHeldObjectsa = v6;
  if ( v6 <= 10.0 )
  {
    if ( bDamageFromHeldObjectsa > 0.0 && (this->m_spawnflags.m_Value & 1) != 0 )
    {
      v3->pInternalData->GetSurfaceNormal(this: v3->pInternalData, a2: &normal);
      if ( index == 0 )
      {
        normal.x = normal.x * -1.0;
        normal.y = normal.y * -1.0;
        normal.z = normal.z * -1.0;
      }
      v3->pInternalData->GetContactPoint(this: v3->pInternalData, a2: (Vector *)&v12);
      vecAbsEnd.x = v12 + normal.x;
      vecAbsEnd.y = v13 + normal.y;
      vecAbsEnd.z = v14 + normal.z;
      damagePos.x = v12 - normal.x;
      damagePos.y = v13 - normal.y;
      damagePos.z = v14 - normal.z;
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)v3,
        vecAbsStart: &damagePos,
        &vecAbsEnd,
        mask: 0x400Bu,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: (CGameTrace *)&tr.startpos.z);
      if ( v10 != nullptr && v10 == this )
      {
        CEffectData::CEffectData(this: &data);
        data.m_vOrigin = *(Vector *)&tr.endpos.z;
        data.m_vStart = *(Vector *)&tr.startpos.z;
        data.m_nSurfaceProp = tr.physicsbone;
        data.m_nDamageType = 128;
        data.m_nHitBox = v11;
        data.m_nEntIndex = (int)CBaseEntity::entindex(this);
        DispatchEffect(pName: "Impact", &data);
      }
    }
    goto LABEL_15;
  }
  ((void (__stdcall *)(int))v3->pObjects[index]->SetMass)(a1: 0x40000000);
  v3->pInternalData->GetSurfaceNormal(this: v3->pInternalData, a2: &normal);
  if ( index == 0 )
  {
    normal.x = normal.x * -1.0;
    normal.y = normal.y * -1.0;
    normal.z = normal.z * -1.0;
  }
  v3->pInternalData->GetContactPoint(this: v3->pInternalData, a2: &damagePos);
  v7 = v3->pEntities[index == 0];
  CTakeDamageInfo::CTakeDamageInfo(
    this: (CTakeDamageInfo *)&tr,
    pInflictor: v7,
    pAttacker: v7,
    damageForce: &normal,
    damagePosition: &damagePos,
    flDamage: bDamageFromHeldObjectsa,
    bitsDamageType: (int)pEvent,
    iKillType: 0,
    reportedPosition: nullptr,
    iObjectsPenetrated: 0);
  PhysCallbackDamage(pEntity: this, info: (const CTakeDamageInfo *)&tr, event: v3, hurtIndex: index);
  CBreakable::VPhysicsCollision(this, index: *(float *)&index, pEvent: (int)v3);
}

//------------------------------------------------------------------------------
// Address: 0x10135210
// Name: public: virtual void CWindowPane::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWindowPane::Spawn(CWindowPane *this)
{
  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 6);
  this->SetModel(this, a2: "models/brokenglass_piece.mdl");
}

//------------------------------------------------------------------------------
// Address: 0x10135280
// Name: public: static class CWindowPane __near * CWindowPane::CreateWindowPane(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
CWindowPane *__usercall CWindowPane::CreateWindowPane@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        const Vector *vecOrigin,
        const QAngle *vecAngles)
{
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v5; // esi
  CWindowPane *result; // eax
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  IUniformRandomStream *v9; // ecx
  int v10; // ebx
  CBaseEdict *v11; // ecx
  float vecAngVelocity_8; // [esp+1Ch] [ebp-10h]

  EntityByName = CreateEntityByName(className: "window_pane", iForceEdictIndex: -1, bNotify: true);
  v5 = EntityByName;
  if ( EntityByName == nullptr )
  {
    _Msg(a1: "NULL Ent in CreateWindowPane!\n");
    return nullptr;
  }
  if ( EntityByName->m_Network.m_pPev != nullptr )
  {
    CBaseEntity::SetLocalOrigin(this: EntityByName, origin: vecOrigin);
    CBaseEntity::SetLocalAngles(this: v5, angles: vecAngles);
    ((void (__thiscall *)(CBaseEntity *, int, int))v5->Spawn)(a1: v5, a2, a3: a1);
    v5->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CWindowPane::PaneTouch;
    _RandomFloat(this: v7, a2: -50.0, a3: 50.0);
    _RandomFloat(this: v8, a2: -50.0, a3: 50.0);
    vecAngVelocity_8 = _RandomFloat(this: v9, a2: -50.0, a3: 50.0);
    CBaseEntity::SetLocalAngularVelocity(this: v5, vecAngVelocity: (const QAngle *)LODWORD(vecAngVelocity_8));
    v10 = random->RandomInt(this: random, a2: 0, a3: 2);
    if ( *(_DWORD *)&v5[1].m_Network.m_PVSInfo.m_nHeadNode != v10 )
    {
      result = (CWindowPane *)v5;
      if ( v5->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v5->m_Network + 76) |= 1u;
        *(_DWORD *)&v5[1].m_Network.m_PVSInfo.m_nHeadNode = v10;
        return result;
      }
      v11 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: v11, offset: 0x370u);
      *(_DWORD *)&v5[1].m_Network.m_PVSInfo.m_nHeadNode = v10;
    }
  }
  return (CWindowPane *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x101353D0
// Name: public: void CBreakableSurface::DropPane(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::DropPane(CBreakableSurface *this, int nWidth, int nHeight)
{
  CBreakableSurface *v4; // ecx
  float m_Value; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  CWindowPane *v14; // esi
  const QAngle *v15; // eax
  QAngle vAngles; // [esp+18h] [ebp-3Ch] BYREF
  Vector vWidthDir; // [esp+24h] [ebp-30h] BYREF
  Vector vHeightDir; // [esp+30h] [ebp-24h] BYREF
  Vector forward; // [esp+3Ch] [ebp-18h] BYREF
  Vector vBreakPos; // [esp+48h] [ebp-Ch] BYREF

  if ( nWidth >= 0
    && nWidth < this->m_nNumWide.m_Value
    && nHeight >= 0
    && nHeight < this->m_nNumHigh.m_Value
    && !CBreakableSurface::IsBroken(this, nWidth, nHeight) )
  {
    CBreakableSurface::BreakPane(this: v4, nWidth, nHeight);
    forward.x = this->m_vNormal.m_Value.x * -1.0;
    forward.y = this->m_vNormal.m_Value.y * -1.0;
    forward.z = this->m_vNormal.m_Value.z * -1.0;
    VectorAngles(&forward, angles: &vAngles);
    AngleVectors(angles: &vAngles, forward: nullptr, right: &vWidthDir, up: &vHeightDir);
    m_Value = this->m_flPanelHeight.m_Value;
    v6 = (float)(vHeightDir.z * (float)nHeight) * m_Value;
    v7 = (float)(vHeightDir.y * (float)nHeight) * m_Value;
    v8 = this->m_flPanelWidth.m_Value;
    v9 = (float)(vWidthDir.y * (float)nWidth) * v8;
    v10 = (float)(vWidthDir.z * (float)nWidth) * v8;
    v11 = (float)(this->m_vCorner.m_Value.x + (float)((float)(vWidthDir.x * (float)nWidth) * v8))
        + (float)((float)(vHeightDir.x * (float)nHeight) * m_Value);
    v12 = this->m_vCorner.m_Value.y + v9;
    v13 = (float)(this->m_vCorner.m_Value.z + v10) + v6;
    vBreakPos.x = v11;
    vBreakPos.y = v12 + v7;
    vBreakPos.z = v13;
    CBreakableSurface::CreateShards(
      this,
      &vBreakPos,
      &vAngles,
      vForce: &vec3_origin,
      vForcePos: &vec3_origin,
      flWidth: 12.0,
      flHeight: 12.0,
      nShardSize: 4);
    CBreakable::DamageSound(this);
    v14 = CWindowPane::CreateWindowPane(a1: nWidth, a2: nHeight, vecOrigin: &vBreakPos, vecAngles: &vAngles);
    if ( v14 != nullptr )
    {
      v15 = RandomAngle(result: (QAngle *)&forward, minVal: -120.0, maxVal: 120.0);
      CBaseEntity::SetLocalAngularVelocity(this: v14, vecAngVelocity: v15);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101355C0
// Name: public: virtual void CBreakableSurface::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBreakableSurface::Spawn(CBreakableSurface *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  edict_t *m_pPev; // ecx
  int m_nQuadError; // eax
  const Vector *v6; // eax
  const Vector *v7; // eax
  IVModelInfo_vtbl *v8; // ebx
  model_t *Model; // eax
  const Vector *v10; // eax
  IVModelInfo_vtbl *v11; // edi
  model_t *v12; // eax
  IMaterialVar *v13; // edi
  const char *v14; // eax
  int v15; // edi
  CBreakableSurface::NetworkVar_m_RawPanelBitVec *p_m_RawPanelBitVec; // esi
  bool *v17; // eax
  CBaseEdict *v18; // ecx
  IMaterial *pMaterial; // [esp+34h] [ebp-8h] BYREF
  bool foundVar; // [esp+3Bh] [ebp-1h] BYREF

  CBreakable::Spawn(this, a2, a3, a4: (int)this);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 6);
  if ( this->m_bIsBroken.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x42Cu);
    }
    this->m_bIsBroken.m_Value = false;
  }
  m_nQuadError = this->m_nQuadError;
  if ( m_nQuadError == 1 )
  {
    v6 = this->WorldSpaceCenter(this);
    _Warning(
      a1: "Rejecting func_breakablesurf at (%2.2f, %2.2f, %2.2f).  Has multiple faces that aren't NODRAW.\n",
      v6->x,
      v6->y,
      v6->z);
  }
  else
  {
    if ( m_nQuadError != 2 )
      goto LABEL_12;
    v7 = this->WorldSpaceCenter(this);
    _Warning(
      a1: "Rejecting func_breakablesurf at (%2.2f, %2.2f, %2.2f).  Drawn face isn't a quad.\n",
      v7->x,
      v7->y,
      v7->z);
  }
  UTIL_Remove(oldObj: this);
LABEL_12:
  v8 = modelinfo->__vftable;
  Model = CBaseEntity::GetModel(this);
  if ( v8->GetModelMaterialCount(this: modelinfo, a2: Model) != 1 )
  {
    v10 = this->WorldSpaceCenter(this);
    _Warning(
      a1: "Encountered func_breakablesurf at (%2.2f, %2.2f, %2.2f) that has a material applied to more than one surface!\n",
      v10->x,
      v10->y,
      v10->z);
    UTIL_Remove(oldObj: this);
  }
  v11 = modelinfo->__vftable;
  v12 = CBaseEntity::GetModel(this);
  v11->GetModelMaterials(this: modelinfo, a2: v12, a3: 1, a4: &pMaterial);
  v13 = pMaterial->FindVar(this: pMaterial, a2: "$crackmaterial", a3: &foundVar, a4: 0);
  if ( foundVar && CBaseEntity::IsPrecacheAllowed() )
  {
    v14 = v13->GetStringValue(this: v13);
    PrecacheMaterial(pMaterialName: v14);
  }
  v15 = 0;
  p_m_RawPanelBitVec = &this->m_RawPanelBitVec;
  do
  {
    if ( !p_m_RawPanelBitVec->m_Value[v15] )
    {
      v17 = &p_m_RawPanelBitVec[-9].m_Value[144];
      if ( p_m_RawPanelBitVec[-9].m_Value[228] )
      {
        v17[88] |= 1u;
      }
      else
      {
        v18 = *((CBaseEdict **)v17 + 6);
        if ( v18 != nullptr )
          CBaseEdict::StateChanged(this: v18, offset: v15 + 2160);
      }
      p_m_RawPanelBitVec->m_Value[v15] = true;
    }
    ++v15;
  }
  while ( v15 < 256 );
}

//------------------------------------------------------------------------------
// Address: 0x10135830
// Name: public: void CBreakableSurface::BreakThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::BreakThink(CBreakableSurface *this)
{
  int m_Value; // eax
  int v3; // ebx
  int v4; // ecx
  int i; // esi
  double v6; // st7
  int v7; // ecx
  float v8; // xmm0_4
  int v9; // edx
  int v10; // eax
  int j; // esi
  float *v12; // ebx
  float v13[265]; // [esp+0h] [ebp-844h]
  float support; // [esp+428h] [ebp-41Ch]
  float flSupport[16][16]; // [esp+438h] [ebp-40Ch]
  float flBreakValue; // [esp+838h] [ebp-Ch]
  int v17; // [esp+83Ch] [ebp-8h]
  int w; // [esp+840h] [ebp-4h]

  if ( this->m_nSurfaceType.m_Value != SHATTERSURFACE_TILE )
  {
    m_Value = this->m_nNumWide.m_Value;
    v3 = 0;
    if ( m_Value > 0 )
    {
      v4 = this->m_nNumHigh.m_Value;
      w = 0;
      do
      {
        for ( i = 0; i < v4; ++i )
        {
          if ( v3 >= 0 && v3 < this->m_nNumWide.m_Value && i >= 0 && i < v4 && this->m_flSupport[0][i + w] != -1.0 )
          {
            v6 = CBreakableSurface::RecalcSupport(this, nWidth: v3, nHeight: i);
            flSupport[0][i + w] = v6;
          }
          v4 = this->m_nNumHigh.m_Value;
        }
        m_Value = this->m_nNumWide.m_Value;
        w += 16;
        ++v3;
      }
      while ( v3 < m_Value );
    }
    v7 = 0;
    v8 = (double)this->m_nFragility * 0.01 * 0.2;
    flBreakValue = v8;
    w = 0;
    if ( m_Value > 0 )
    {
      v9 = 270;
      v17 = 270;
      do
      {
        v10 = this->m_nNumHigh.m_Value;
        for ( j = 0; j < v10; ++j )
        {
          if ( v7 >= 0 && v7 < this->m_nNumWide.m_Value && j >= 0 && j < v10 )
          {
            v12 = (float *)(&this->CBreakable::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable
                          + v9
                          + j);
            if ( *v12 != -1.0 )
            {
              support = v13[j + v9] * 0.1481481481481481;
              CBreakableSurface::SetSupport(this, w: v7, h: j, support);
              if ( flBreakValue > *v12 )
              {
                if ( random->RandomInt(this: random, a2: 0, a3: 1) != 0 )
                  CBreakableSurface::DropPane(this, nWidth: w, nHeight: j);
                else
                  CBreakableSurface::ShatterPane(
                    this,
                    nWidth: w,
                    nHeight: j,
                    vForce: &vec3_origin,
                    vForcePos: &vec3_origin);
                CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
              }
              v7 = w;
            }
          }
          v10 = this->m_nNumHigh.m_Value;
          v9 = v17;
        }
        ++v7;
        v9 += 16;
        w = v7;
        v17 = v9;
      }
      while ( v7 < this->m_nNumWide.m_Value );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135A10
// Name: public: void CBreakableSurface::BreakPane(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::BreakPane(CBreakableSurface *this, int nWidth, int nHeight)
{
  if ( nWidth >= 0 && nWidth < this->m_nNumWide.m_Value && nHeight >= 0 && nHeight < this->m_nNumHigh.m_Value )
  {
    ++this->m_nNumBrokenPanes;
    CBreakableSurface::SetSupport(this, w: nWidth, h: nHeight, support: -1.0);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CBreakableSurface::BreakThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135A90
// Name: public: bool CBreakableSurface::ShatterPane(int,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBreakableSurface::ShatterPane(
        CBreakableSurface *this,
        int nWidth,
        int nHeight,
        const Vector *vForce,
        const Vector *vForcePos)
{
  CBreakableSurface *v6; // ecx
  float flHeight; // xmm7_4
  float flWidth; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  QAngle vAngles; // [esp+24h] [ebp-30h] BYREF
  Vector vWidthDir; // [esp+30h] [ebp-24h] BYREF
  Vector vHeightDir; // [esp+3Ch] [ebp-18h] BYREF
  Vector vBreakPos; // [esp+48h] [ebp-Ch] BYREF

  if ( nWidth < 0 || nWidth >= this->m_nNumWide.m_Value )
    return 0;
  if ( nHeight < 0 || nHeight >= this->m_nNumHigh.m_Value || CBreakableSurface::IsBroken(this, nWidth, nHeight) )
    return 0;
  CBreakableSurface::BreakPane(this: v6, nWidth, nHeight);
  vBreakPos.x = this->m_vNormal.m_Value.x * -1.0;
  vBreakPos.y = this->m_vNormal.m_Value.y * -1.0;
  vBreakPos.z = this->m_vNormal.m_Value.z * -1.0;
  VectorAngles(forward: &vBreakPos, angles: &vAngles);
  AngleVectors(angles: &vAngles, forward: nullptr, right: &vWidthDir, up: &vHeightDir);
  flHeight = this->m_flPanelHeight.m_Value;
  flWidth = this->m_flPanelWidth.m_Value;
  v9 = this->m_vCorner.m_Value.y + (float)((float)(vWidthDir.y * (float)nWidth) * flWidth);
  v10 = (float)(this->m_vCorner.m_Value.z + (float)((float)(vWidthDir.z * (float)nWidth) * flWidth))
      + (float)((float)(vHeightDir.z * (float)nHeight) * flHeight);
  vBreakPos.x = (float)(this->m_vCorner.m_Value.x + (float)((float)(vWidthDir.x * (float)nWidth) * flWidth))
              + (float)((float)(vHeightDir.x * (float)nHeight) * flHeight);
  vBreakPos.y = v9 + (float)((float)(vHeightDir.y * (float)nHeight) * flHeight);
  vBreakPos.z = v10;
  CBreakableSurface::CreateShards(this, &vBreakPos, &vAngles, vForce, vForcePos, flWidth, flHeight, nShardSize: 4);
  CBreakable::DamageSound(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10135E00
// Name: public: void CBreakableSurface::SurfaceTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBreakableSurface::SurfaceTouch(
        CBreakableSurface *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseEntity *pOther)
{
  CBaseEntity *v6; // edi
  __int128 v7; // xmm0
  float y; // xmm2_4
  float x; // xmm3_4
  float v10; // xmm7_4
  float z; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm7_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm5_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  double m_Value; // xmm0_8
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  double v27; // xmm0_8
  bool v28; // zf
  int i; // edi
  __int128 v32; // [esp-40h] [ebp-8Ch] BYREF
  Vector v33; // [esp-30h] [ebp-7Ch] BYREF
  Vector v34; // [esp-24h] [ebp-70h] BYREF
  Vector v35; // [esp-18h] [ebp-64h] BYREF
  float v36; // [esp-Ch] [ebp-58h] BYREF
  float v37; // [esp-8h] [ebp-54h]
  float v38; // [esp-4h] [ebp-50h]
  Vector vVel; // [esp+0h] [ebp-4Ch] BYREF
  Vector vecAbsMaxs; // [esp+Ch] [ebp-40h] BYREF
  Vector vecAbsMins; // [esp+18h] [ebp-34h] BYREF
  Vector vHitVel; // [esp+24h] [ebp-28h]
  int v43; // [esp+30h] [ebp-1Ch]
  int flMinsWidth; // [esp+34h] [ebp-18h]
  int flMinsHeight; // [esp+38h] [ebp-14h]
  float v46; // [esp+3Ch] [ebp-10h]
  int v47; // [esp+40h] [ebp-Ch]
  void *v48; // [esp+44h] [ebp-8h]
  void *retaddr; // [esp+4Ch] [ebp+0h]

  v47 = a2;
  v48 = retaddr;
  v6 = pOther;
  if ( this->m_nSurfaceType.m_Value != SHATTERSURFACE_TILE
    || (pOther->GetVelocity(this: pOther, a2: (Vector *)&v36, a3: nullptr),
        vHitVel.y = v38 * v38,
        v7 = 0,
        *(float *)&v7 = fsqrt((float)((float)(v38 * v38) + (float)(v37 * v37)) + (float)(v36 * v36)),
        v32 = v7,
        *(float *)&v7 >= 500.0) )
  {
    CCollisionProperty::CollisionAABBToWorldAABB(
      this: &pOther->m_Collision,
      entityMins: &pOther->m_Collision.m_vecMins.m_Value,
      entityMaxs: &pOther->m_Collision.m_vecMaxs.m_Value,
      pWorldMins: &vecAbsMaxs,
      pWorldMaxs: &vVel);
    y = this->m_vNormal.m_Value.y;
    x = this->m_vNormal.m_Value.x;
    v10 = this->m_vCorner.m_Value.x;
    z = this->m_vNormal.m_Value.z;
    v12 = (float)((float)(y * (float)(vVel.y - this->m_vCorner.m_Value.y)) + (float)(x * (float)(vVel.x - v10)))
        + (float)((float)(vVel.z - this->m_vCorner.m_Value.z) * z);
    v13 = (float)((float)(y * v12) + vVel.y) - this->m_vCorner.m_Value.y;
    v38 = (float)((float)(v12 * z) + vVel.z) - this->m_vCorner.m_Value.z;
    v36 = (float)((float)(x * v12) + vVel.x) - v10;
    v37 = v13;
    v35.x = x * -1.0;
    v35.y = y * -1.0;
    v35.z = z * -1.0;
    VectorAngles(forward: &v35, angles: (QAngle *)((char *)&v32 + 4));
    AngleVectors(angles: (const QAngle *)((char *)&v32 + 4), forward: nullptr, right: &v34, up: &v33);
    vHitVel.y = (float)((float)((float)(v34.y * v37) + (float)(v36 * v34.x)) + (float)(v34.z * v38))
              / this->m_flPanelWidth.m_Value;
    vHitVel.z = (float)((float)((float)(v33.y * v37) + (float)(v33.x * v36)) + (float)(v33.z * v38))
              / this->m_flPanelHeight.m_Value;
    v14 = this->m_vNormal.m_Value.y;
    v15 = this->m_vNormal.m_Value.x;
    v16 = this->m_vCorner.m_Value.x;
    v17 = this->m_vNormal.m_Value.z;
    v18 = (float)((float)(v14 * (float)(vecAbsMaxs.y - this->m_vCorner.m_Value.y))
                + (float)(v15 * (float)(vecAbsMaxs.x - v16)))
        + (float)((float)(vecAbsMaxs.z - this->m_vCorner.m_Value.z) * v17);
    v19 = (float)((float)(v14 * v18) + vecAbsMaxs.y) - this->m_vCorner.m_Value.y;
    v38 = (float)((float)(v18 * v17) + vecAbsMaxs.z) - this->m_vCorner.m_Value.z;
    v36 = (float)((float)(v15 * v18) + vecAbsMaxs.x) - v16;
    v37 = v19;
    v33.x = v15 * -1.0;
    v33.y = v14 * -1.0;
    v33.z = v17 * -1.0;
    VectorAngles(forward: &v33, angles: (QAngle *)((char *)&v32 + 4));
    AngleVectors(angles: (const QAngle *)((char *)&v32 + 4), forward: nullptr, right: &v34, up: &v35);
    v20 = (float)((float)((float)(v34.y * v37) + (float)(v36 * v34.x)) + (float)(v34.z * v38))
        / this->m_flPanelWidth.m_Value;
    v21 = (float)((float)((float)(v35.y * v37) + (float)(v35.x * v36)) + (float)(v35.z * v38))
        / this->m_flPanelHeight.m_Value;
    if ( v20 <= vHitVel.y )
      v22 = (float)((float)((float)(v34.y * v37) + (float)(v36 * v34.x)) + (float)(v34.z * v38))
          / this->m_flPanelWidth.m_Value;
    else
      v22 = vHitVel.y;
    if ( v22 >= 0.0 )
    {
      if ( v20 <= vHitVel.y )
        *(float *)&flMinsWidth = (float)((float)((float)(v34.y * v37) + (float)(v36 * v34.x)) + (float)(v34.z * v38))
                               / this->m_flPanelWidth.m_Value;
      else
        flMinsWidth = SLODWORD(vHitVel.y);
    }
    else
    {
      *(float *)&flMinsWidth = 0.0;
    }
    v43 = LOBYTE(v46) | 0x400;
    flMinsHeight = (int)*(float *)&flMinsWidth;
    if ( vHitVel.y > v20 )
      v20 = vHitVel.y;
    m_Value = v20;
    if ( (double)this->m_nNumWide.m_Value <= m_Value )
      m_Value = (double)this->m_nNumWide.m_Value;
    v24 = m_Value;
    vHitVel.y = v24;
    v43 = LOBYTE(v46) | 0x800;
    flMinsWidth = (int)v24;
    v25 = vHitVel.z;
    if ( v21 <= vHitVel.z )
      v26 = v21;
    else
      v26 = vHitVel.z;
    if ( v26 >= 0.0 )
    {
      if ( v21 <= vHitVel.z )
        v46 = v21;
      else
        v46 = vHitVel.z;
    }
    else
    {
      v46 = 0.0;
    }
    v43 = LOBYTE(vHitVel.z) | 0x400;
    LODWORD(vHitVel.y) = (int)v46;
    if ( vHitVel.z <= v21 )
      v25 = v21;
    v27 = v25;
    if ( (double)this->m_nNumHigh.m_Value <= v27 )
      v27 = (double)this->m_nNumHigh.m_Value;
    vHitVel.x = v27;
    LODWORD(vHitVel.z) = LOBYTE(v46) | 0x800;
    v43 = (int)vHitVel.x;
    pOther->GetVelocity(this: pOther, a2: &vecAbsMins, a3: nullptr);
    v28 = !this->m_bIsBroken.m_Value;
    vecAbsMins.x = vecAbsMins.x * 5.0;
    vecAbsMins.y = vecAbsMins.y * 5.0;
    vecAbsMins.z = vecAbsMins.z * 5.0;
    if ( v28 )
      CBreakableSurface::Die(this, pBreaker: pOther, vAttackDir: &vecAbsMins);
    v46 = vHitVel.y;
    if ( SLODWORD(vHitVel.y) < v43 )
    {
      while ( 1 )
      {
        if ( ((int (__thiscall *)(IUniformRandomStream *, _DWORD, int, int, int))random->RandomInt)(
               a1: random,
               a2: 0,
               a3: 1,
               a4: a3,
               a5: a4) != 0 )
          CBreakableSurface::ShatterPane(
            this,
            nWidth: flMinsHeight - 1,
            nHeight: SLODWORD(v46),
            vForce: &vecAbsMins,
            vForcePos: &v6->m_vecOrigin.m_Value);
        for ( i = flMinsHeight; i < flMinsWidth; ++i )
          CBreakableSurface::ShatterPane(
            this,
            nWidth: i,
            nHeight: SLODWORD(v46),
            vForce: &vecAbsMins,
            vForcePos: &pOther->m_vecOrigin.m_Value);
        a4 = 1;
        a3 = 0;
        if ( ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random) != 0 )
          CBreakableSurface::ShatterPane(
            this,
            nWidth: flMinsWidth + 1,
            nHeight: SLODWORD(v46),
            vForce: &vecAbsMins,
            vForcePos: &pOther->m_vecOrigin.m_Value);
        ++LODWORD(v46);
        if ( SLODWORD(v46) >= v43 )
          break;
        v6 = pOther;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136390
// Name: public: void CBreakableSurface::Die(class CBaseEntity __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBreakableSurface::Die(
        CBreakableSurface *this@<ecx>,
        float a2@<ebp>,
        CBaseEntity *pBreaker,
        const Vector *vAttackDir)
{
  edict_t *m_pPev; // ecx
  COutputEvent *p_m_OnBreak; // ecx
  float x; // xmm0_4
  double v8; // xmm1_8
  float v9; // xmm1_4
  float v10; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  edict_t *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm2_4
  bool v23; // zf
  edict_t *v24; // ecx
  edict_t *v25; // ecx
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // edx
  float v30; // edx
  Vector *p_m_vURVertex; // eax
  edict_t *v32; // ecx
  __int128 v33; // xmm0
  __int128 v34; // xmm0
  float v35; // edx
  edict_t *v36; // ecx
  float v37; // edx
  edict_t *v38; // ecx
  edict_t *v39; // ecx
  edict_t *v40; // ecx
  float v41; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *v43; // ecx
  float v44; // xmm0_4
  float v45; // xmm1_4
  edict_t *v46; // ecx
  int i; // edi
  QAngle v48; // [esp+14h] [ebp-60h] BYREF
  QAngle vAngles; // [esp+20h] [ebp-54h] BYREF
  Vector vHeightDir; // [esp+2Ch] [ebp-48h] BYREF
  __int128 vWidthDir; // [esp+38h] [ebp-3Ch] OVERLAPPED BYREF
  __int128 vSaveHeight; // [esp+48h] [ebp-2Ch] OVERLAPPED
  Vector vHeight; // [esp+58h] [ebp-1Ch]
  Vector vWidth; // [esp+64h] [ebp-10h] BYREF
  float retaddr; // [esp+74h] [ebp+0h]

  vWidth.y = a2;
  vWidth.z = retaddr;
  if ( this->m_bIsBroken.m_Value )
    return;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vWidth.y);
  PhysBreakSound(pEntity: this, pPhysObject: this->m_pPhysicsObject, vecOrigin: this->m_vecAbsOrigin);
  if ( !this->m_bIsBroken.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x42Cu);
    }
    this->m_bIsBroken.m_Value = true;
  }
  if ( this->m_iHealth.m_Value != 0 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 0;
  }
  p_m_OnBreak = &this->m_OnBreak;
  if ( pBreaker != nullptr )
    COutputEvent::FireOutput(this: p_m_OnBreak, pActivator: pBreaker, pCaller: this, fDelay: 0.0);
  else
    COutputEvent::FireOutput(this: p_m_OnBreak, pActivator: this, pCaller: this, fDelay: 0.0);
  x = vAttackDir->x;
  v8 = (float)((float)((float)(x * x) + (float)(vAttackDir->y * vAttackDir->y)) + (float)(vAttackDir->z * vAttackDir->z));
  vWidth.x = -1.0;
  if ( v8 > 0.001 )
  {
    v9 = this->m_vNormal.m_Value.x;
    if ( (float)((float)((float)(x * v9) + (float)(this->m_vNormal.m_Value.y * vAttackDir->y))
               + (float)(this->m_vNormal.m_Value.z * vAttackDir->z)) < 0.0 )
    {
      this->m_vLLVertex.x = this->m_vLLVertex.x + v9;
      this->m_vLLVertex.y = this->m_vNormal.m_Value.y + this->m_vLLVertex.y;
      this->m_vLLVertex.z = this->m_vNormal.m_Value.z + this->m_vLLVertex.z;
      this->m_vLRVertex.x = this->m_vLRVertex.x + this->m_vNormal.m_Value.x;
      this->m_vLRVertex.y = this->m_vNormal.m_Value.y + this->m_vLRVertex.y;
      this->m_vLRVertex.z = this->m_vNormal.m_Value.z + this->m_vLRVertex.z;
      this->m_vULVertex.x = this->m_vULVertex.x + this->m_vNormal.m_Value.x;
      this->m_vULVertex.y = this->m_vNormal.m_Value.y + this->m_vULVertex.y;
      this->m_vULVertex.z = this->m_vULVertex.z + this->m_vNormal.m_Value.z;
      this->m_vURVertex.x = this->m_vURVertex.x + this->m_vNormal.m_Value.x;
      this->m_vURVertex.y = this->m_vNormal.m_Value.y + this->m_vURVertex.y;
      this->m_vURVertex.z = this->m_vNormal.m_Value.z + this->m_vURVertex.z;
      v10 = this->m_vNormal.m_Value.x;
      y = this->m_vNormal.m_Value.y;
      z = this->m_vNormal.m_Value.z;
      v14 = y * -1.0;
      v15 = z * -1.0;
      *((float *)&vSaveHeight + 1) = v10 * -1.0;
      v13 = v10 * -1.0;
      *((float *)&vSaveHeight + 2) = y * -1.0;
      *((float *)&vSaveHeight + 3) = z * -1.0;
      if ( (float)(v10 * -1.0) != v10 || v14 != y || v15 != z )
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
            CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x414u);
            v15 = *((float *)&vSaveHeight + 3);
            v14 = *((float *)&vSaveHeight + 2);
            v13 = *((float *)&vSaveHeight + 1);
          }
        }
        this->m_vNormal.m_Value.x = v13;
        this->m_vNormal.m_Value.y = v14;
        this->m_vNormal.m_Value.z = v15;
      }
      vWidth.x = 1.0;
    }
  }
  v17 = this->m_vLLVertex.x - this->m_vLRVertex.x;
  v18 = this->m_vLLVertex.x - this->m_vULVertex.x;
  v19 = this->m_vLLVertex.y - this->m_vLRVertex.y;
  v20 = this->m_vLLVertex.y - this->m_vULVertex.y;
  v21 = this->m_vLLVertex.z - this->m_vLRVertex.z;
  v22 = this->m_vLLVertex.z - this->m_vULVertex.z;
  v23 = !this->m_Network.m_TimerEvent.m_bRegistered;
  vHeight.x = v17;
  vHeight.y = v19;
  vHeight.z = v21;
  *(_QWORD *)((char *)&vSaveHeight + 4) = __PAIR64__(LODWORD(v20), LODWORD(v18));
  *((float *)&vSaveHeight + 3) = v22;
  if ( v23 )
  {
    v24 = this->m_Network.m_pPev;
    if ( v24 != nullptr )
    {
      CBaseEdict::StateChanged(this: &v24->CBaseEdict, offset: 0x414u);
      v20 = *((float *)&vSaveHeight + 2);
      v22 = *((float *)&vSaveHeight + 3);
      v19 = vHeight.y;
      v21 = vHeight.z;
      v18 = *((float *)&vSaveHeight + 1);
      v17 = vHeight.x;
    }
  }
  else
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  this->m_vNormal.m_Value.x = (float)(v22 * v19) - (float)(v20 * v21);
  this->m_vNormal.m_Value.y = (float)(v21 * v18) - (float)(v22 * v17);
  this->m_vNormal.m_Value.z = (float)(v20 * v17) - (float)(v19 * v18);
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v25 = this->m_Network.m_pPev;
    if ( v25 != nullptr )
      CBaseEdict::StateChanged(this: &v25->CBaseEdict, offset: 0x414u);
  }
  VectorNormalize(vec: &this->m_vNormal.m_Value);
  *((float *)&vWidthDir + 1) = this->m_vNormal.m_Value.x * -1.0;
  *((float *)&vWidthDir + 2) = this->m_vNormal.m_Value.y * -1.0;
  *((float *)&vWidthDir + 3) = this->m_vNormal.m_Value.z * -1.0;
  VectorAngles(forward: (const Vector *)((char *)&vWidthDir + 4), angles: &v48);
  AngleVectors(angles: &v48, forward: nullptr, right: &vHeightDir, up: (Vector *)&vAngles);
  v26 = vHeight.x;
  v27 = vHeight.y;
  v28 = vHeight.z;
  if ( COERCE_FLOAT(
         COERCE_UNSIGNED_INT(
           (float)((float)(vHeightDir.x * vHeight.x) + (float)(vHeightDir.y * vHeight.y))
         + (float)(vHeightDir.z * vHeight.z))
       & _mask__AbsFloat_) < 0.5 )
  {
    v29 = *((float *)&vSaveHeight + 3);
    *(_QWORD *)((char *)&vWidthDir + 4) = *(_QWORD *)((char *)&vSaveHeight + 4);
    *((float *)&vSaveHeight + 1) = vHeight.x * vWidth.x;
    *((float *)&vSaveHeight + 2) = vHeight.y * vWidth.x;
    *((float *)&vSaveHeight + 3) = vHeight.z * vWidth.x;
    *((float *)&vWidthDir + 3) = v29;
    v26 = *((float *)&vWidthDir + 1) * vWidth.x;
    v27 = *((float *)&vWidthDir + 2) * vWidth.x;
    v28 = v29 * vWidth.x;
    vHeight.x = *((float *)&vWidthDir + 1) * vWidth.x;
    vHeight.y = *((float *)&vWidthDir + 2) * vWidth.x;
    vHeight.z = v29 * vWidth.x;
  }
  if ( (float)((float)((float)(vHeightDir.x * v26) + (float)(vHeightDir.y * v27)) + (float)(vHeightDir.z * v28)) >= 0.0 )
  {
    if ( (float)((float)((float)(vAngles.x * *((float *)&vSaveHeight + 1))
                       + (float)(vAngles.y * *((float *)&vSaveHeight + 2)))
               + (float)(vAngles.z * *((float *)&vSaveHeight + 3))) < 0.0 )
    {
      LODWORD(v30) = &this->m_vLRVertex;
      LODWORD(vWidth.x) = &this->m_vLRVertex;
      goto LABEL_44;
    }
    p_m_vURVertex = &this->m_vURVertex;
  }
  else
  {
    if ( (float)((float)((float)(vAngles.x * *((float *)&vSaveHeight + 1))
                       + (float)(vAngles.y * *((float *)&vSaveHeight + 2)))
               + (float)(vAngles.z * *((float *)&vSaveHeight + 3))) < 0.0 )
    {
      LODWORD(v30) = &this->m_vLLVertex;
      LODWORD(vWidth.x) = &this->m_vLLVertex;
      goto LABEL_44;
    }
    p_m_vURVertex = &this->m_vULVertex;
  }
  LODWORD(vWidth.x) = p_m_vURVertex;
  v30 = *(float *)&p_m_vURVertex;
LABEL_44:
  if ( *(float *)LODWORD(v30) != this->m_vCorner.m_Value.x
    || *(float *)(LODWORD(v30) + 4) != this->m_vCorner.m_Value.y
    || *(float *)(LODWORD(v30) + 8) != this->m_vCorner.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v32 = this->m_Network.m_pPev;
      if ( v32 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v32->CBaseEdict, offset: 0x420u);
        v27 = vHeight.y;
        v30 = vWidth.x;
        v26 = vHeight.x;
        v28 = vHeight.z;
      }
    }
    this->m_vCorner.m_Value.x = *(float *)LODWORD(v30);
    this->m_vCorner.m_Value.y = *(float *)(LODWORD(v30) + 4);
    this->m_vCorner.m_Value.z = *(float *)(LODWORD(v30) + 8);
  }
  v33 = 0;
  *(float *)&v33 = fsqrt((float)((float)(v26 * v26) + (float)(v27 * v27)) + (float)(v28 * v28));
  vWidthDir = v33;
  v34 = 0;
  *(float *)&v34 = fsqrt(
                     (float)((float)(*((float *)&vSaveHeight + 2) * *((float *)&vSaveHeight + 2))
                           + (float)(*((float *)&vSaveHeight + 3) * *((float *)&vSaveHeight + 3)))
                   + (float)(*((float *)&vSaveHeight + 1) * *((float *)&vSaveHeight + 1)));
  vSaveHeight = v34;
  LODWORD(v35) = (int)(float)(*(float *)&vWidthDir * 0.083333336);
  vWidth.x = v35;
  if ( this->m_nNumWide.m_Value != LODWORD(v35) )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v36 = this->m_Network.m_pPev;
      if ( v36 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v36->CBaseEdict, offset: 0x404u);
        v35 = vWidth.x;
      }
    }
    *(float *)&this->m_nNumWide.m_Value = v35;
  }
  LODWORD(v37) = (int)(float)(*(float *)&vSaveHeight * 0.083333336);
  vWidth.x = v37;
  if ( this->m_nNumHigh.m_Value != LODWORD(v37) )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v38 = this->m_Network.m_pPev;
      if ( v38 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v38->CBaseEdict, offset: 0x408u);
        v37 = vWidth.x;
      }
    }
    *(float *)&this->m_nNumHigh.m_Value = v37;
  }
  if ( this->m_nNumWide.m_Value > 16 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v39 = this->m_Network.m_pPev;
      if ( v39 != nullptr )
        CBaseEdict::StateChanged(this: &v39->CBaseEdict, offset: 0x404u);
    }
    this->m_nNumWide.m_Value = 16;
  }
  if ( this->m_nNumHigh.m_Value > 16 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v40 = this->m_Network.m_pPev;
      if ( v40 != nullptr )
        CBaseEdict::StateChanged(this: &v40->CBaseEdict, offset: 0x408u);
    }
    this->m_nNumHigh.m_Value = 16;
  }
  m_Value = this->m_flPanelWidth.m_Value;
  vWidth.x = *(float *)&vWidthDir / (float)this->m_nNumWide.m_Value;
  v41 = vWidth.x;
  if ( m_Value != vWidth.x )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v43 = this->m_Network.m_pPev;
      if ( v43 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v43->CBaseEdict, offset: 0x40Cu);
        v41 = vWidth.x;
      }
    }
    this->m_flPanelWidth.m_Value = v41;
  }
  v45 = this->m_flPanelHeight.m_Value;
  vWidth.x = *(float *)&vSaveHeight / (float)this->m_nNumHigh.m_Value;
  v44 = vWidth.x;
  if ( v45 != vWidth.x )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v46 = this->m_Network.m_pPev;
      if ( v46 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v46->CBaseEdict, offset: 0x410u);
        v44 = vWidth.x;
      }
    }
    this->m_flPanelHeight.m_Value = v44;
  }
  vWidth.x = 0.0;
  do
  {
    for ( i = 0; i < 16; ++i )
      CBreakableSurface::SetSupport(this, w: SLODWORD(vWidth.x), h: i, support: 1.0);
    ++LODWORD(vWidth.x);
  }
  while ( SLODWORD(vWidth.x) < 16 );
  CBreakable::ResetOnGroundFlags(this);
  this->VPhysicsDestroyObject(this);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBreakableSurface::SurfaceTouch;
}

//------------------------------------------------------------------------------
// Address: 0x10136C90
// Name: public: void CBreakableSurface::InputShatter(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::InputShatter(CBreakableSurface *this, inputdata_t *inputdata)
{
  _fieldtypes fieldType; // eax
  float z; // xmm3_4
  float y; // xmm0_4
  bool v6; // zf
  int m_Value; // ecx
  int v8; // edx
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  int v12; // edi
  float v13; // xmm0_4
  int i; // ebx
  int v15; // edi
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm7_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  QAngle vAngles; // [esp+Ch] [ebp-68h] BYREF
  Vector vForce; // [esp+18h] [ebp-5Ch] BYREF
  Vector vBreakPos; // [esp+24h] [ebp-50h] BYREF
  Vector vWidthDir; // [esp+30h] [ebp-44h] BYREF
  Vector vHeightDir; // [esp+3Ch] [ebp-38h] BYREF
  Vector vecShatterInfo; // [esp+48h] [ebp-2Ch]
  Vector forward; // [esp+54h] [ebp-20h] BYREF
  float v38; // [esp+60h] [ebp-14h]
  float flCenterY; // [esp+64h] [ebp-10h]
  float flCenterX; // [esp+68h] [ebp-Ch]
  int nMinY; // [esp+6Ch] [ebp-8h]
  int nMaxX; // [esp+70h] [ebp-4h]
  int savedregs; // [esp+74h] [ebp+0h] BYREF
  int nMaxY; // [esp+7Ch] [ebp+8h]

  fieldType = inputdata->value.fieldType;
  if ( fieldType == FIELD_VECTOR || fieldType == FIELD_POSITION_VECTOR )
  {
    z = inputdata->value.vecVal[2];
    LODWORD(vecShatterInfo.x) = inputdata->value.iVal;
    y = inputdata->value.vecVal[1];
  }
  else
  {
    z = vec3_origin.z;
    vecShatterInfo.x = vec3_origin.x;
    y = vec3_origin.y;
  }
  v6 = !this->m_bIsBroken.m_Value;
  vecShatterInfo.z = z;
  vecShatterInfo.y = y;
  if ( v6 )
  {
    CBreakableSurface::Die(this, a2: COERCE_FLOAT(&savedregs), pBreaker: nullptr, vAttackDir: &vec3_origin);
    z = vecShatterInfo.z;
  }
  m_Value = this->m_nNumWide.m_Value;
  v8 = this->m_nNumHigh.m_Value;
  v9 = (float)m_Value * vecShatterInfo.x;
  v10 = z / this->m_flPanelWidth.m_Value;
  v11 = (float)v8 * vecShatterInfo.y;
  v12 = (int)(float)(v9 - v10);
  flCenterX = v9;
  flCenterY = v11;
  nMaxX = (int)(float)(v10 + v9) + 1;
  if ( v12 < 0 )
    v12 = 0;
  if ( (int)(float)(v10 + v9) + 1 > m_Value )
    nMaxX = m_Value;
  v13 = z / this->m_flPanelHeight.m_Value;
  nMinY = (int)(float)(v11 - v13);
  nMaxY = (int)(float)(v13 + v11) + 1;
  if ( nMinY < 0 )
    nMinY = 0;
  if ( (int)(float)(v13 + v11) + 1 > v8 )
    nMaxY = v8;
  forward.x = this->m_vNormal.m_Value.x * -1.0;
  forward.y = this->m_vNormal.m_Value.y * -1.0;
  forward.z = this->m_vNormal.m_Value.z * -1.0;
  VectorAngles(&forward, angles: &vAngles);
  AngleVectors(angles: &vAngles, forward: nullptr, right: &vWidthDir, up: &vHeightDir);
  forward.y = flCenterX * this->m_flPanelWidth.m_Value;
  forward.z = flCenterY * this->m_flPanelHeight.m_Value;
  for ( i = v12; i < nMaxX; ++i )
  {
    v15 = nMinY;
    if ( nMinY < nMaxY )
    {
      v16 = (float)i;
      v17 = (float)i + 0.5;
      v38 = (float)i;
      flCenterX = v17;
      flCenterY = vecShatterInfo.z * vecShatterInfo.z;
      do
      {
        v18 = (float)v15;
        if ( flCenterY >= (float)((float)((float)((float)((float)((float)v15 + 0.5) * this->m_flPanelWidth.m_Value)
                                                - forward.z)
                                        * (float)((float)((float)((float)v15 + 0.5) * this->m_flPanelWidth.m_Value)
                                                - forward.z))
                                + (float)((float)((float)(this->m_flPanelWidth.m_Value * v17) - forward.y)
                                        * (float)((float)(this->m_flPanelWidth.m_Value * v17) - forward.y))) )
        {
          v19 = this->m_flPanelHeight.m_Value;
          v20 = this->m_flPanelWidth.m_Value;
          v21 = (float)(v18 * vHeightDir.z) * v19;
          v22 = (float)(v18 * vHeightDir.x) * v19;
          v23 = (float)(v18 * vHeightDir.y) * v19;
          v24 = (float)(v16 * vWidthDir.x) * v20;
          v25 = (float)(v16 * vWidthDir.y) * v20;
          v26 = (float)(v16 * vWidthDir.z) * v20;
          v27 = this->m_vCorner.m_Value.x + v24;
          v28 = this->m_vCorner.m_Value.y + v25;
          v29 = this->m_vCorner.m_Value.z;
          vBreakPos.y = v28 + v23;
          vForce.x = this->m_vNormal.m_Value.x * 500.0;
          vForce.y = this->m_vNormal.m_Value.y * 500.0;
          v30 = this->m_vNormal.m_Value.z * 500.0;
          vBreakPos.x = v27 + v22;
          vBreakPos.z = (float)(v29 + v26) + v21;
          vForce.z = v30;
          CBreakableSurface::ShatterPane(this, nWidth: i, nHeight: v15, &vForce, vForcePos: &vBreakPos);
          v17 = flCenterX;
          v16 = v38;
        }
        ++v15;
      }
      while ( v15 < nMaxY );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136FE0
// Name: public: void CBreakableSurface::BreakAllPanes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::BreakAllPanes(CBreakableSurface *this)
{
  int i; // ebx
  int j; // edi

  for ( i = 0; i < this->m_nNumWide.m_Value; ++i )
  {
    for ( j = 0; j < this->m_nNumHigh.m_Value; ++j )
    {
      if ( i >= 0 && i < this->m_nNumWide.m_Value && j >= 0 && j < this->m_nNumHigh.m_Value )
      {
        ++this->m_nNumBrokenPanes;
        CBreakableSurface::SetSupport(this, w: i, h: j, support: -1.0);
        CBaseEntity::ThinkSet(
          this,
          func: (void (__thiscall *)(CBaseEntity *))CBreakableSurface::BreakThink,
          thinkTime: 0.0,
          szContext: nullptr);
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      }
    }
  }
  this->m_nNumBrokenPanes = this->m_nNumWide.m_Value * this->m_nNumHigh.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10137290
// Name: public: virtual int CBreakableSurface::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBreakableSurface::OnTakeDamage(CBreakableSurface *this, const CTakeDamageInfo *info)
{
  unsigned int v3; // eax
  CBaseEntity *v4; // esi
  const Vector *v5; // eax
  unsigned int v6; // eax
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  Vector vecDir; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( !this->m_bIsBroken.m_Value && info->m_bitsDamageType == 1 )
  {
    vecDir.z = info->m_vecDamageForce.z;
    goto LABEL_18;
  }
  if ( this->m_nSurfaceType.m_Value != SHATTERSURFACE_GLASS )
    return 0;
  if ( (info->m_bitsDamageType & 0x40) == 0 )
  {
    if ( (info->m_bitsDamageType & 4) != 0 )
    {
      vecDir.z = info->m_vecDamageForce.z;
LABEL_18:
      m_Index = info->m_hAttacker.m_Index;
      *(_QWORD *)&vecDir.x = *(_QWORD *)&info->m_vecDamageForce.x;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      CBreakableSurface::Die(this, a2: COERCE_FLOAT(&savedregs), pBreaker: m_pEntity, vAttackDir: &vecDir);
      return 0;
    }
    return 0;
  }
  v3 = info->m_hInflictor.m_Index;
  if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
    v4 = nullptr;
  else
    v4 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
  if ( (v4->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
  v5 = this->WorldSpaceCenter(this);
  vecDir.x = v4->m_vecAbsOrigin.x - v5->x;
  vecDir.y = v4->m_vecAbsOrigin.y - v5->y;
  vecDir.z = v4->m_vecAbsOrigin.z - v5->z;
  VectorNormalize(vec: &vecDir);
  v6 = info->m_hAttacker.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
  {
    CBreakableSurface::Die(this, a2: COERCE_FLOAT(&savedregs), pBreaker: nullptr, vAttackDir: &vecDir);
    return 0;
  }
  else
  {
    CBreakableSurface::Die(
      this,
      a2: COERCE_FLOAT(&savedregs),
      pBreaker: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity,
      vAttackDir: &vecDir);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137410
// Name: public: virtual void CBreakableSurface::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurface::TraceAttack(
        CBreakableSurface *this,
        int info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  int v5; // edx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // ebx
  int m_Value; // eax
  int v8; // edi
  unsigned int v9; // eax
  CGameTrace *v10; // ebx
  CTakeDamageInfo *v11; // edi
  unsigned int v12; // eax
  CBaseEntity *m_pEntity; // ecx
  int m_bitsDamageType; // eax
  Vector *p_endpos; // ebx
  const Vector *v16; // edi
  float z; // xmm1_4
  unsigned int v18; // eax
  IHandleEntity *v19; // ecx
  float v20; // xmm0_4
  int v21; // eax
  int v22; // ecx
  float v23; // xmm0_4
  int v24; // eax
  int v25; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *Attacker; // edi
  int v28; // edx
  int v29; // ecx
  int v30; // ebx
  int v31; // eax
  int v32; // edi
  int v33; // ebx
  CEntInfo *v34; // ecx
  CBasePlayer *v35; // edi
  float y; // xmm1_4
  float x; // xmm2_4
  float v38; // xmm3_4
  float m_flDamage; // xmm0_4
  float v40; // xmm0_4
  int v41; // eax
  int m_nNumBrokenPanes; // ecx
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm3_4
  int v46; // ebx
  int v47; // eax
  int v48; // ecx
  int v49; // edi
  float v50; // xmm7_4
  float v51; // xmm5_4
  float v52; // xmm0_4
  float v53; // xmm3_4
  float v54; // xmm7_4
  float v55; // xmm5_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  CPASFilter filter; // [esp+50h] [ebp-E8h] BYREF
  CEffectData data; // [esp+70h] [ebp-C8h] BYREF
  QAngle angles; // [esp+D4h] [ebp-64h] BYREF
  QAngle vAngles; // [esp+E0h] [ebp-58h] BYREF
  unsigned int v62; // [esp+ECh] [ebp-4Ch]
  int v63; // [esp+F0h] [ebp-48h]
  Vector vHeightDir; // [esp+F4h] [ebp-44h] BYREF
  Vector vBreakPos; // [esp+100h] [ebp-38h] BYREF
  Vector vBlastDir; // [esp+10Ch] [ebp-2Ch] BYREF
  int flWidth; // [esp+118h] [ebp-20h] BYREF
  int nHeight; // [esp+11Ch] [ebp-1Ch]
  int flHeight; // [esp+120h] [ebp-18h] BYREF
  bool bWasBroken; // [esp+127h] [ebp-11h]
  int width; // [esp+128h] [ebp-10h]
  Vector vWidthDir; // [esp+12Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+138h] [ebp+0h] BYREF

  v5 = (int)*(float *)(info + 48);
  p_m_iHealth = &this->m_iHealth;
  bWasBroken = this->m_bIsBroken.m_Value;
  m_Value = this->m_iHealth.m_Value;
  v8 = m_Value - v5;
  if ( m_Value != m_Value - v5 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = v8;
  }
  v9 = *(_DWORD *)(info + 40);
  if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
    width = 0;
  else
    width = (int)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
  *(float *)&flHeight = (float)p_m_iHealth->m_Value;
  variant_t::Set(
    this: &this->m_OnHealthChanged.m_Value,
    ftype: FIELD_FLOAT,
    data: ($3B1CACFA647AB85A7D70EA6016B49717 *)&flHeight);
  CBaseEntityOutput::FireOutput(
    this: &this->m_OnHealthChanged,
    Value: this->m_OnHealthChanged.m_Value,
    pActivator: (CBaseEntity *)width,
    pCaller: this,
    fDelay: 0.0);
  v10 = ptr;
  v11 = (CTakeDamageInfo *)info;
  if ( !this->m_bIsBroken.m_Value )
  {
    v12 = *(_DWORD *)(info + 40);
    vWidthDir.x = ptr->endpos.x - ptr->startpos.x;
    vWidthDir.y = ptr->endpos.y - ptr->startpos.y;
    vWidthDir.z = ptr->endpos.z - ptr->startpos.z;
    if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
    CBreakableSurface::Die(this, a2: COERCE_FLOAT(&savedregs), pBreaker: m_pEntity, vAttackDir: &vWidthDir);
  }
  m_bitsDamageType = v11->m_bitsDamageType;
  if ( (m_bitsDamageType & 0x82) != 0 )
  {
    p_endpos = &v10->endpos;
    CBreakableSurface::PanePos(this, vPos: p_endpos, (float *)&flWidth, (float *)&flHeight);
    v16 = vecDir;
    vWidthDir.x = vecDir->x * 500.0;
    vWidthDir.y = vecDir->y * 500.0;
    z = vecDir->z;
    nHeight = (int)*(float *)&flHeight;
    width = (int)*(float *)&flWidth;
    vWidthDir.z = z * 500.0;
    if ( CBreakableSurface::ShatterPane(
           this,
           nWidth: (int)*(float *)&flWidth,
           nHeight: (int)*(float *)&flHeight,
           vForce: &vWidthDir,
           vForcePos: p_endpos) != 0 )
    {
      v18 = *(_DWORD *)(info + 40);
      if ( v18 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber == HIWORD(v18) )
      {
        v19 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
        info = (int)v19;
        if ( *(float *)&v19 != 0.0
          && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v19->__vftable[28].dtr_IHandleEntity)(a1: v19) != 0
          && !bWasBroken )
        {
          gamestats->Event_WindowShattered(this: gamestats, a2: (CBasePlayer *)info);
        }
      }
      memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
      memset((void *)&data.m_vAngles, 0, 20);
      memset(&data.m_flMagnitude, 0, 14);
      memset(&data.m_nMaterial, 0, 17);
      data.m_vNormal = ptr->plane.normal;
      data.m_vOrigin.x = p_endpos->x;
      data.m_vOrigin.y = p_endpos->y;
      v20 = p_endpos->z;
      data.m_flScale = 1.0;
      data.m_vOrigin.z = v20;
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &data.m_vOrigin);
      CRecipientFilter::SetIgnorePredictionCull(this: &filter, ignore: true);
      DispatchEffect(&filter, flDelay: 0.0, pName: "GlassImpact", &data);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
    if ( this->m_nSurfaceType.m_Value == SHATTERSURFACE_GLASS )
    {
      v21 = width;
      v22 = nHeight;
      v23 = *(float *)&flWidth - (float)width;
      *(float *)&info = *(float *)&flHeight - (float)nHeight;
      if ( v23 <= 0.8 || width == this->m_nNumWide.m_Value - 1 )
      {
        if ( v23 >= 0.2 || width == 0 )
        {
LABEL_30:
          if ( *(float *)&info <= 0.8 || v22 == this->m_nNumHigh.m_Value - 1 )
          {
            if ( *(float *)&info >= 0.2 || v22 == 0 )
            {
LABEL_37:
              if ( random->RandomInt(this: random, a2: 0, a3: 1) == 0 )
              {
                vWidthDir.x = v16->x * 1000.0;
                vWidthDir.y = v16->y * 1000.0;
                vWidthDir.z = v16->z * 1000.0;
                CBreakableSurface::ShatterPane(
                  this,
                  nWidth: width,
                  nHeight: nHeight + 1,
                  vForce: &vWidthDir,
                  vForcePos: p_endpos);
                if ( random->RandomInt(this: random, a2: 0, a3: 1) == 0 )
                {
                  vWidthDir.x = v16->x * 1000.0;
                  vWidthDir.y = v16->y * 1000.0;
                  vWidthDir.z = v16->z * 1000.0;
                  CBreakableSurface::ShatterPane(
                    this,
                    nWidth: width,
                    nHeight: nHeight + 2,
                    vForce: &vWidthDir,
                    vForcePos: p_endpos);
                }
              }
              return;
            }
            v25 = v22 - 1;
          }
          else
          {
            v25 = v22 + 1;
          }
          vWidthDir.x = v16->x * 500.0;
          vWidthDir.y = v16->y * 500.0;
          vWidthDir.z = v16->z * 500.0;
          CBreakableSurface::ShatterPane(this, nWidth: v21, nHeight: v25, vForce: &vWidthDir, vForcePos: p_endpos);
          goto LABEL_37;
        }
        v24 = width - 1;
      }
      else
      {
        v24 = width + 1;
      }
      vWidthDir.x = v16->x * 500.0;
      vWidthDir.y = v16->y * 500.0;
      vWidthDir.z = v16->z * 500.0;
      CBreakableSurface::ShatterPane(this, nWidth: v24, nHeight, vForce: &vWidthDir, vForcePos: p_endpos);
      v21 = width;
      v22 = nHeight;
      goto LABEL_30;
    }
  }
  else if ( (m_bitsDamageType & 0x240) != 0 )
  {
    m_Index = v11->m_hAttacker.m_Index;
    if ( this->m_nSurfaceType.m_Value == SHATTERSURFACE_TILE )
    {
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        Attacker = CTakeDamageInfo::GetAttacker(this: v11);
        if ( (Attacker->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: Attacker, a2: (int)&savedregs);
        CBreakableSurface::PanePos(
          this,
          vPos: &Attacker->m_vecAbsOrigin,
          flWidth: (float *)&flHeight,
          flHeight: (float *)&info);
      }
      else
      {
        CBreakableSurface::PanePos(this, vPos: &v10->endpos, flWidth: (float *)&flHeight, flHeight: (float *)&info);
      }
      v28 = (int)*(float *)&info;
      v29 = (int)*(float *)&flHeight - 4;
      v30 = (int)*(float *)&flHeight + 4;
      width = v29;
      v63 = v30;
      if ( v29 < v30 )
      {
        v31 = (int)*(float *)&flHeight - v29;
        nHeight = v28 - 4;
        flHeight = v28 + 4;
        flWidth = v31;
        do
        {
          v32 = nHeight;
          if ( nHeight < flHeight )
          {
            v62 = abs32(v31);
            v33 = (int)*(float *)&info - nHeight;
            do
            {
              if ( (int)(v62 + abs32(v33)) < random->RandomInt(this: random, a2: 2, a3: 5) )
              {
                vWidthDir.x = vecDir->x * 500.0;
                vWidthDir.y = vecDir->y * 500.0;
                vWidthDir.z = vecDir->z * 500.0;
                CBreakableSurface::ShatterPane(
                  this,
                  nWidth: width,
                  nHeight: v32,
                  vForce: &vWidthDir,
                  vForcePos: &ptr->endpos);
              }
              ++v32;
              --v33;
            }
            while ( v32 < flHeight );
            v30 = v63;
            v29 = width;
          }
          ++v29;
          v31 = flWidth - 1;
          width = v29;
          --flWidth;
        }
        while ( v29 < v30 );
      }
    }
    else
    {
      if ( m_Index != -1 )
      {
        v34 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          v35 = (CBasePlayer *)v34->m_pEntity;
          if ( v34->m_pEntity != nullptr && v35->IsPlayer(this: (CBaseEntity *)v34->m_pEntity) && !bWasBroken )
            gamestats->Event_WindowShattered(this: gamestats, a2: v35);
          v11 = (CTakeDamageInfo *)info;
        }
      }
      y = this->m_vNormal.m_Value.y;
      x = this->m_vNormal.m_Value.x;
      v38 = this->m_vNormal.m_Value.z;
      m_flDamage = v11->m_flDamage;
      if ( (float)((float)((float)(vecDir->y * y) + (float)(vecDir->x * x)) + (float)(vecDir->z * v38)) <= 0.0 )
        v40 = m_flDamage * -3000.0;
      else
        v40 = m_flDamage * 3000.0;
      v41 = this->m_nNumHigh.m_Value * this->m_nNumWide.m_Value;
      m_nNumBrokenPanes = this->m_nNumBrokenPanes;
      vBlastDir.z = v40 * v38;
      vBlastDir.y = v40 * y;
      vBlastDir.x = v40 * x;
      if ( m_nNumBrokenPanes < v41 )
      {
        v43 = x * -1.0;
        v44 = y * -1.0;
        v45 = v38 * -1.0;
        if ( (double)v41 * 0.1 <= (double)m_nNumBrokenPanes )
        {
          vBreakPos.x = v43;
          vBreakPos.y = v44;
          vBreakPos.z = v45;
          VectorAngles(forward: &vBreakPos, &angles);
          AngleVectors(&angles, forward: nullptr, right: &vWidthDir, up: &vHeightDir);
          v46 = 0;
          if ( this->m_nNumWide.m_Value > 0 )
          {
            info = 270;
            do
            {
              v47 = this->m_nNumHigh.m_Value;
              v48 = 0;
              v49 = 0;
              if ( v47 > 0 )
              {
                do
                {
                  if ( v46 < 0
                    || v46 >= this->m_nNumWide.m_Value
                    || v49 < 0
                    || v49 >= v47
                    || *((float *)&this->CBreakable::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable
                       + v49
                       + info) == -1.0 )
                  {
                    if ( v48 > 0 )
                    {
                      v50 = this->m_flPanelHeight.m_Value;
                      v51 = this->m_flPanelWidth.m_Value;
                      v52 = (float)(v49 - v48);
                      vBreakPos.y = (float)(this->m_vCorner.m_Value.y + (float)((float)((float)v46 * vWidthDir.y) * v51))
                                  + (float)((float)(v52 * vHeightDir.y) * v50);
                      v53 = (float)(this->m_vCorner.m_Value.z + (float)((float)((float)v46 * vWidthDir.z) * v51))
                          + (float)((float)(v52 * vHeightDir.z) * v50);
                      vBreakPos.x = (float)((float)((float)((float)v46 * vWidthDir.x) * v51) + this->m_vCorner.m_Value.x)
                                  + (float)((float)(v52 * vHeightDir.x) * v50);
                      vBreakPos.z = v53;
                      CBreakableSurface::CreateShards(
                        this,
                        &vBreakPos,
                        vAngles: &angles,
                        vForce: &vBlastDir,
                        vForcePos: &ptr->endpos,
                        flWidth: v51,
                        flHeight: (float)v48 * v50,
                        nShardSize: 7);
                      v48 = 0;
                    }
                  }
                  else
                  {
                    ++v48;
                  }
                  v47 = this->m_nNumHigh.m_Value;
                  ++v49;
                }
                while ( v49 < v47 );
                if ( v48 != 0 )
                {
                  v54 = this->m_flPanelHeight.m_Value;
                  v55 = this->m_flPanelWidth.m_Value;
                  v56 = (float)(v49 - v48);
                  vAngles.y = (float)(this->m_vCorner.m_Value.y + (float)((float)((float)v46 * vWidthDir.y) * v55))
                            + (float)((float)(v56 * vHeightDir.y) * v54);
                  v57 = (float)(this->m_vCorner.m_Value.z + (float)((float)((float)v46 * vWidthDir.z) * v55))
                      + (float)((float)(v56 * vHeightDir.z) * v54);
                  vAngles.x = (float)((float)((float)((float)v46 * vWidthDir.x) * v55) + this->m_vCorner.m_Value.x)
                            + (float)((float)(v56 * vHeightDir.x) * v54);
                  vAngles.z = v57;
                  CBreakableSurface::CreateShards(
                    this,
                    vBreakPos: (const Vector *)&vAngles,
                    vAngles: &angles,
                    vForce: &vBlastDir,
                    vForcePos: &ptr->endpos,
                    flWidth: v55,
                    flHeight: (float)v48 * v54,
                    nShardSize: 7);
                }
              }
              info += 16;
              ++v46;
            }
            while ( v46 < this->m_nNumWide.m_Value );
          }
          CBreakableSurface::BreakAllPanes(this);
        }
        else
        {
          vWidthDir.x = v43;
          vWidthDir.y = v44;
          vWidthDir.z = v45;
          VectorAngles(forward: &vWidthDir, angles: &vAngles);
          CBreakableSurface::CreateShards(
            this,
            vBreakPos: &this->m_vCorner.m_Value,
            &vAngles,
            vForce: &vBlastDir,
            vForcePos: &v10->endpos,
            flWidth: (float)this->m_nNumWide.m_Value * this->m_flPanelWidth.m_Value,
            flHeight: (float)this->m_nNumHigh.m_Value * this->m_flPanelHeight.m_Value,
            nShardSize: 7);
          CBreakableSurface::BreakAllPanes(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403B60
// Name: CWindowPane_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWindowPane_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWindowPane>(__formal: nullptr);
  CWindowPane_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403B90
// Name: CBreakableSurface_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBreakableSurface_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBreakableSurface>();
  CBreakableSurface_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403BC0
// Name: DT_BreakableSurface::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BreakableSurface::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BreakableSurface::g_SendTable);
  return atexit(func: DT_BreakableSurface::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403BE0
// Name: DT_BreakableSurface::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BreakableSurface::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BreakableSurface::ignored>();
  DT_BreakableSurface::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408B90
// Name: _dynamic_initializer_for__breakable_disable_gib_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__breakable_disable_gib_limit__()
{
  ConVar::ConVar(this: &breakable_disable_gib_limit, pName: "breakable_disable_gib_limit", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__breakable_disable_gib_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x10408BC0
// Name: _dynamic_initializer_for__breakable_multiplayer__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__breakable_multiplayer__()
{
  ConVar::ConVar(this: &breakable_multiplayer, pName: "breakable_multiplayer", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__breakable_multiplayer__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B6B0
// Name: DT_BreakableSurface::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BreakableSurface::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BreakableSurface::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D6E0
// Name: _dynamic_atexit_destructor_for__breakable_disable_gib_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__breakable_disable_gib_limit__()
{
  ConVar::~ConVar(this: &breakable_disable_gib_limit);
}

//------------------------------------------------------------------------------
// Address: 0x1041D6F0
// Name: _dynamic_atexit_destructor_for__breakable_multiplayer__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__breakable_multiplayer__()
{
  ConVar::~ConVar(this: &breakable_multiplayer);
}

//------------------------------------------------------------------------------
// Address: 0x10135C50
// Name: class CBreakableSurface __near * _CreateEntityTemplate<class CBreakableSurface>(class CBreakableSurface __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBreakableSurface *__cdecl _CreateEntityTemplate<CBreakableSurface>(CBreakableSurface *newEnt, const char *className)
{
  CBreakable *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBreakable *)CBaseEntity::operator new(stAllocateBlock: 0x970u);
  v3 = &v2->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CBreakable::CBreakable(this: v2);
    *v3 = &CBreakableSurface::`vftable'{for `CBaseEntity'};
    v3[213] = &CBreakableSurface::`vftable'{for `IBreakableWithPropData'};
    v3[214] = &CBreakableSurface::`vftable'{for `CDefaultPlayerPickupVPhysics'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CBreakableSurface *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135CB0
// Name: struct datamap_t __near * DataMapInit<class CWindowPane>(class CWindowPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWindowPane>()
{
  if ( (_S2_115 & 1) == 0 )
  {
    _S2_115 |= 1u;
    nameHolder_212.m_pszBase = "CWindowPane";
    nameHolder_212.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_212.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_212.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_212.m_Names.m_Size = 0;
    nameHolder_212.m_Names.m_pElements = nullptr;
    nameHolder_212.m_nLenBase = 11;
    atexit(func: DataMapInit_CWindowPane__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWindowPane::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2_115 & 2) == 0 )
  {
    _S2_115 |= 2u;
    dataDesc_477[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_212, pszIdentifier: "Die");
    dataDesc_477[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_477[1].fieldSize = 2097153;
    dataDesc_477[1].externalName = nullptr;
    dataDesc_477[1].pSaveRestoreOps = nullptr;
    dataDesc_477[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CWindowPane::Die;
    *(_QWORD *)&dataDesc_477[1].td = 0;
    *(_QWORD *)&dataDesc_477[1].override_field = 0;
    *(_QWORD *)&dataDesc_477[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_477[1].flatOffset[1] = 0;
    dataDesc_477[2].fieldType = FIELD_VOID;
    dataDesc_477[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_212,
                                  pszIdentifier: "PaneTouch");
    dataDesc_477[2].fieldOffset = 0;
    *(_DWORD *)&dataDesc_477[2].fieldSize = 2097153;
    dataDesc_477[2].externalName = nullptr;
    dataDesc_477[2].pSaveRestoreOps = nullptr;
    dataDesc_477[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CWindowPane::PaneTouch;
    *(_QWORD *)&dataDesc_477[2].td = 0;
    *(_QWORD *)&dataDesc_477[2].override_field = 0;
    *(_QWORD *)&dataDesc_477[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_477[2].flatOffset[1] = 0;
  }
  CWindowPane::m_DataMap.dataNumFields = 2;
  CWindowPane::m_DataMap.dataDesc = &dataDesc_477[1];
  return &CWindowPane::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10403BA0
// Name: _dynamic_initializer_for__g_CBreakableSurface_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBreakableSurface_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBreakableSurface_ClassReg,
           pNetworkName: "CBreakableSurface",
           pTable: &DT_BreakableSurface::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10403BF0
// Name: _dynamic_initializer_for__g_CFunc_Dust_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFunc_Dust_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFunc_Dust_ClassReg,
           pNetworkName: "CFunc_Dust",
           pTable: &DT_Func_Dust::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B6C0
// Name: _ServerClassInit_DT_BreakableSurface::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BreakableSurface::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_34;
  for ( i = 10; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B6E0
// Name: _DataMapInit_CWindowPane__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWindowPane__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_212);
}

//------------------------------------------------------------------------------
// Address: 0x1041B6F0
// Name: _DataMapInit_CBreakableSurface__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBreakableSurface__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_213);
}
