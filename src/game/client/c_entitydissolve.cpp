// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_entitydissolve.cpp
// Functions: 24
// ============================================================

#include "game\client\c_entitydissolve.h"

//------------------------------------------------------------------------------
// Address: 0x10063460
// Name: public: virtual void PrecacheEffectBuildPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectBuildPrecache::CResourcePrecacher::Cache(
        PrecacheEffectBuildPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/tesla_glow_noz",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/spark",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/combinemuzzle2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "dissolve",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100634D0
// Name: public: virtual class ClientClass __near * C_EntityDissolve::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EntityDissolve::GetClientClass(C_EntityDissolve *this)
{
  return &__g_C_EntityDissolveClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10063670
// Name: public: virtual void C_EntityDissolve::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityDissolve::UpdateOnRemove(C_EntityDissolve *this)
{
  IPhysicsMotionController *m_pController; // eax

  m_pController = this->m_pController;
  if ( m_pController != nullptr )
  {
    physenv->DestroyMotionController(this: physenv, a2: m_pController);
    this->m_pController = nullptr;
  }
  C_BaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x100636A0
// Name: protected: float C_EntityDissolve::GetFadeInPercentage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_EntityDissolve::GetFadeInPercentage(C_EntityDissolve *this)
{
  float v1; // xmm1_4
  float m_flFadeInStart; // xmm2_4
  float m_flFadeInLength; // [esp+0h] [ebp-Ch]

  v1 = *(float *)(gpGlobals.m_Index + 12) - this->m_flStartTime;
  if ( v1 > this->m_flFadeOutStart )
    return 1.0;
  m_flFadeInStart = this->m_flFadeInStart;
  if ( m_flFadeInStart > v1 )
    return 0.0;
  if ( v1 <= m_flFadeInStart )
    return 1.0;
  m_flFadeInLength = this->m_flFadeInLength;
  if ( (float)(m_flFadeInLength + m_flFadeInStart) <= v1 )
    return 1.0;
  else
    return ((float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flStartTime) - this->m_flFadeInStart)
         / m_flFadeInLength;
}

//------------------------------------------------------------------------------
// Address: 0x10063710
// Name: protected: float C_EntityDissolve::GetFadeOutPercentage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_EntityDissolve::GetFadeOutPercentage(C_EntityDissolve *this)
{
  float v1; // xmm0_4
  float m_flFadeOutStart; // xmm1_4

  v1 = *(float *)(gpGlobals.m_Index + 12) - this->m_flStartTime;
  if ( this->m_flFadeInStart > v1 )
    return 1.0;
  m_flFadeOutStart = this->m_flFadeOutStart;
  if ( v1 <= m_flFadeOutStart )
    return 1.0;
  if ( (float)(v1 - m_flFadeOutStart) <= this->m_flFadeOutLength )
    return 1.0 - (float)(v1 - m_flFadeOutStart) / this->m_flFadeOutLength;
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10063780
// Name: float SimpleSplineRemapVal(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SimpleSplineRemapVal(float val, float A, float B, float C, float D)
{
  float cVal; // [esp+10h] [ebp+10h]

  if ( A == B )
  {
    if ( val < B )
      return C;
    else
      return D;
  }
  else
  {
    cVal = (float)(val - A) / (float)(B - A);
    return C + (D - C) * (3.0 * (float)(cVal * cVal) - ((float)(cVal * cVal) + (float)(cVal * cVal)) * cVal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063800
// Name: public: virtual enum IMotionEvent::simresult_e C_EntityDissolve::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_EntityDissolve::Simulate@<eax>(
        C_EntityDissolve *this@<ecx>,
        int a2@<esi>,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  void (__thiscall *GetVelocity)(IPhysicsObject *, Vector *, Vector *); // edx
  float y; // xmm1_4
  float z; // xmm2_4
  double v11; // st7
  float v12; // xmm0_4
  Vector angVel; // [esp+0h] [ebp-24h] BYREF
  Vector unitVel; // [esp+Ch] [ebp-18h] BYREF
  Vector vel; // [esp+18h] [ebp-Ch] BYREF
  float speed; // [esp+38h] [ebp+14h]

  GetVelocity = pObject->GetVelocity;
  linear->z = 0.0;
  linear->x = 0.0;
  linear->y = 0.0;
  angular->x = 0.0;
  angular->y = 0.0;
  angular->z = 0.0;
  linear->z = linear->z - sv_gravity.m_pParent->m_Value.m_fValue * -1.02;
  ((void (__thiscall *)(IPhysicsObject *, Vector *, Vector *, int))GetVelocity)(
    a1: pObject,
    a2: &vel,
    a3: &angVel,
    a4: a2);
  y = linear->y;
  z = linear->z;
  vel.x = (float)(linear->x * deltaTime) + vel.x;
  vel.y = vel.y + (float)(y * deltaTime);
  vel.z = vel.z + (float)(z * deltaTime);
  unitVel = vel;
  v11 = VectorNormalize(vec: &unitVel);
  if ( v11 > 50.0 )
  {
    speed = v11;
    v12 = (float)(50.0 - speed) * (float)(1.0 / deltaTime);
    if ( (float)((float)(1.0 / deltaTime) * -40.0) > v12 )
      v12 = (float)(1.0 / deltaTime) * -40.0;
    linear->x = (float)(unitVel.x * v12) + linear->x;
    linear->y = (float)(unitVel.y * v12) + linear->y;
    linear->z = (float)(unitVel.z * v12) + linear->z;
  }
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10063950
// Name: FX_BuildTesla
// Source: json
//------------------------------------------------------------------------------
void __usercall FX_BuildTesla(Vector *vecOrigin@<ecx>, Vector *vecEnd@<eax>, C_BaseEntity *pEntity)
{
  float z; // xmm0_4
  BeamInfo_t beamInfo; // [esp+14h] [ebp-90h] BYREF

  beamInfo.m_vecStart = *vecOrigin;
  beamInfo.m_vecEnd.x = vecEnd->x;
  beamInfo.m_vecEnd.y = vecEnd->y;
  z = vecEnd->z;
  beamInfo.m_nSegments = -1;
  beamInfo.m_nModelIndex = -1;
  beamInfo.m_nHaloIndex = -1;
  beamInfo.m_vecEnd.z = z;
  beamInfo.m_flHaloScale = 0.0;
  beamInfo.m_pStartEnt = pEntity;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_bRenderable = true;
  beamInfo.m_nFlags = 0;
  memset(&beamInfo.m_nStartAttachment, 0, 12);
  beamInfo.m_nType = 9;
  beamInfo.m_pszModelName = "sprites/lgtning.vmt";
  beamInfo.m_flLife = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 1048576000,
                        a3: 1065353216);
  beamInfo.m_flWidth = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                         a1: random,
                         a2: 1090519040,
                         a3: 1096810496);
  beamInfo.m_flEndWidth = 1.0;
  beamInfo.m_flFadeLength = 0.5;
  beamInfo.m_flAmplitude = 24.0;
  beamInfo.m_flSpeed = 150.0;
  beamInfo.m_flBrightness = 255.0;
  beamInfo.m_nStartFrame = 0;
  beamInfo.m_flFrameRate = 30.0;
  beamInfo.m_flRed = 255.0;
  beamInfo.m_flGreen = 255.0;
  beamInfo.m_flBlue = 255.0;
  beamInfo.m_nSegments = 18;
  beamInfo.m_bRenderable = true;
  beamInfo.m_nFlags = 0;
  beams->CreateBeamEntPoint_2(this: beams, a2: &beamInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10063AC0
// Name: protected: void C_EntityDissolve::ComputeRenderInfo(struct mstudiobbox_t __near *,struct matrix3x4_t const __near &,class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityDissolve::ComputeRenderInfo(
        C_EntityDissolve *this,
        mstudiobbox_t *pHitBox,
        const matrix3x4_t *hitboxToWorld,
        Vector *pVecAbsOrigin,
        Vector *pXVec,
        Vector *pYVec)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  const Vector *v8; // eax
  float y; // xmm1_4
  float x; // xmm3_4
  float v11; // xmm2_4
  int v12; // eax
  int v13; // eax
  Vector *v16; // eax
  double z; // st7
  int v18; // eax
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  Vector vec[3]; // [esp+0h] [ebp-54h] BYREF
  float v38; // [esp+24h] [ebp-30h]
  float v39; // [esp+28h] [ebp-2Ch]
  Vector boxSize; // [esp+30h] [ebp-24h] BYREF
  int vecIdx[3]; // [esp+3Ch] [ebp-18h]
  Vector2D size; // [esp+48h] [ebp-Ch] BYREF
  float v43; // [esp+50h] [ebp-4h]
  mstudiobbox_t *pHitBoxa; // [esp+5Ch] [ebp+8h]
  Vector *hitboxToWorlda; // [esp+60h] [ebp+Ch]
  Vector *pVecAbsOrigina; // [esp+64h] [ebp+10h]
  float pXVeca; // [esp+68h] [ebp+14h]

  v6 = (float)(pHitBox->bbmin.y + pHitBox->bbmax.y) * 0.5;
  v7 = (float)(pHitBox->bbmax.z + pHitBox->bbmin.z) * 0.5;
  boxSize.x = (float)(pHitBox->bbmin.x + pHitBox->bbmax.x) * 0.5;
  boxSize.y = v6;
  boxSize.z = v7;
  VectorTransform(in1: &boxSize.x, in2: hitboxToWorld, out: &pVecAbsOrigin->x);
  MatrixGetColumn(in: hitboxToWorld, column: 0, out: vec);
  MatrixGetColumn(in: hitboxToWorld, column: 1, out: &vec[1]);
  MatrixGetColumn(in: hitboxToWorld, column: 2, out: &vec[2]);
  v8 = CurrentViewOrigin();
  size.x = v8->x - pVecAbsOrigin->x;
  size.y = v8->y - pVecAbsOrigin->y;
  v43 = v8->z - pVecAbsOrigin->z;
  VectorNormalize(vec: (Vector *)&size);
  y = size.y;
  x = size.x;
  v11 = v43;
  vecIdx[0] = fabs((float)((float)(vec[0].y * size.y) + (float)(vec[0].x * size.x)) + (float)(vec[0].z * v43));
  vecIdx[1] = fabs((float)((float)(vec[1].y * size.y) + (float)(vec[1].x * size.x)) + (float)(vec[1].z * v43));
  vecIdx[2] = fabs((float)((float)(vec[2].y * size.y) + (float)(vec[2].x * size.x)) + (float)(vec[2].z * v43));
  v12 = *(float *)vecIdx <= *(float *)&vecIdx[1];
  if ( *(float *)&vecIdx[2] > *(float *)&vecIdx[v12] )
    v12 = 2;
  if ( v12 != 0 )
  {
    v13 = v12 - 1;
    if ( v13 != 0 )
    {
      if ( v13 == 1 )
      {
        vecIdx[0] = 0;
        vecIdx[1] = 1;
        vecIdx[2] = 2;
      }
    }
    else
    {
      vecIdx[0] = 2;
      vecIdx[1] = 0;
      vecIdx[2] = 1;
    }
  }
  else
  {
    vecIdx[0] = 1;
    vecIdx[1] = 2;
    vecIdx[2] = 0;
  }
  v16 = &vec[vecIdx[0]];
  pXVec->x = v16->x;
  pVecAbsOrigina = v16;
  pXVec->y = v16->y;
  z = v16->z;
  v18 = vecIdx[1];
  pXVec->z = z;
  hitboxToWorlda = &vec[v18];
  *pYVec = *hitboxToWorlda;
  v19 = pXVec->y;
  v20 = pXVec->x;
  v21 = pXVec->z;
  v22 = (float)((float)(pXVec->x * x) + (float)(v19 * y)) + (float)(v21 * v11);
  v38 = v22 * x;
  v39 = y * v22;
  pXVec->x = v20 - (float)(v22 * x);
  pXVec->y = v19 - (float)(y * v22);
  pXVec->z = v21 - (float)(v11 * v22);
  v23 = (float)((float)(pYVec->x * x) + (float)(pYVec->y * y)) + (float)(pYVec->z * v11);
  v24 = pYVec->y - (float)(y * v23);
  v25 = pYVec->z - (float)(v11 * v23);
  pYVec->x = pYVec->x - (float)(v23 * x);
  pYVec->y = v24;
  pYVec->z = v25;
  VectorNormalize(vec: pXVec);
  VectorNormalize(vec: pYVec);
  boxSize.x = pHitBox->bbmax.x - pHitBox->bbmin.x;
  boxSize.y = pHitBox->bbmax.y - pHitBox->bbmin.y;
  v26 = pXVec->y;
  v27 = pXVec->z;
  v28 = pYVec->z;
  boxSize.z = pHitBox->bbmax.z - pHitBox->bbmin.z;
  v29 = pVecAbsOrigina->y;
  v43 = *(&boxSize.x + vecIdx[1]);
  *(float *)&pHitBoxa = v27;
  pXVeca = pXVec->x;
  v30 = *(&boxSize.x + vecIdx[2]);
  v31 = (float)((float)(COERCE_FLOAT(
                          COERCE_UNSIGNED_INT(
                            (float)((float)(pXVec->x * vec[vecIdx[2]].x) + (float)(v26 * vec[vecIdx[2]].y))
                          + (float)(v27 * vec[vecIdx[2]].z))
                        & _mask__AbsFloat_)
                      * v30)
              + (float)(COERCE_FLOAT(
                          COERCE_UNSIGNED_INT(
                            (float)((float)(pXVec->x * pVecAbsOrigina->x) + (float)(v29 * v26))
                          + (float)(v27 * pVecAbsOrigina->z))
                        & _mask__AbsFloat_)
                      * *(&boxSize.x + vecIdx[0])))
      * 2.0;
  v32 = (float)((float)(COERCE_FLOAT(
                          COERCE_UNSIGNED_INT(
                            (float)((float)(pYVec->x * vec[vecIdx[2]].x) + (float)(pYVec->y * vec[vecIdx[2]].y))
                          + (float)(v28 * vec[vecIdx[2]].z))
                        & _mask__AbsFloat_)
                      * v30)
              + (float)(COERCE_FLOAT(
                          COERCE_UNSIGNED_INT(
                            (float)((float)(pYVec->x * hitboxToWorlda->x) + (float)(pYVec->y * hitboxToWorlda->y))
                          + (float)(hitboxToWorlda->z * v28))
                        & _mask__AbsFloat_)
                      * v43))
      * 2.0;
  if ( v31 <= 10.0 )
    v31 = 10.0;
  if ( v32 <= 10.0 )
    v32 = 10.0;
  v33 = v31 * 0.5;
  v34 = v32 * 0.5;
  pXVec->x = pXVeca * v33;
  pXVec->y = v26 * v33;
  pXVec->z = *(float *)&pHitBoxa * v33;
  pYVec->x = pYVec->x * v34;
  v35 = pYVec->y * v34;
  v36 = v34 * pYVec->z;
  pYVec->y = v35;
  pYVec->z = v36;
}

//------------------------------------------------------------------------------
// Address: 0x10063F40
// Name: public: C_EntityDissolve::C_EntityDissolve(void)
// Source: json
//------------------------------------------------------------------------------
C_EntityDissolve *__thiscall C_EntityDissolve::C_EntityDissolve(C_EntityDissolve *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->IMotionEvent::__vftable = (IMotionEvent_vtbl *)&IMotionEvent::`vftable';
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EntityDissolve_vtbl *)&C_EntityDissolve::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EntityDissolve::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EntityDissolve::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EntityDissolve::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EntityDissolve::`vftable'{for `C_BaseEntity'};
  this->IMotionEvent::__vftable = (IMotionEvent_vtbl *)&C_EntityDissolve::`vftable'{for `IMotionEvent'};
  this->m_pEmitter.m_pObj = nullptr;
  this->m_pController = nullptr;
  this->m_bCoreExplode = false;
  this->m_bLinkedToServerEnt = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063FA0
// Name: public: virtual void C_EntityDissolve::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityDissolve::OnDataChanged(C_EntityDissolve *this, DataUpdateType_t updateType)
{
  int v3; // eax
  unsigned int v4; // ecx
  C_BaseEntity *m_pEntity; // eax

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v3 = *((_DWORD *)this - 2);
    this->m_flFadeInLength = *((float *)&this->m_bIsBlurred + 1);
    (*(void (__stdcall **)(int))(v3 + 456))(a1: -996040704);
    if ( cl_portal_use_new_dissolve.m_pParent != nullptr && cl_portal_use_new_dissolve.m_pParent->m_Value.m_nValue != 0 )
    {
      v4 = *(_DWORD *)&this->m_bDisableCachedRenderBounds;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        m_pEntity = nullptr;
      else
        m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      DispatchParticleEffect(
        pszParticleName: "dissolve",
        iAttachType: PATTACH_ABSORIGIN_FOLLOW,
        pEntity: m_pEntity,
        iAttachmentPoint: -1,
        bResetAllParticlesOnEntity: false,
        nSplitScreenPlayerSlot: -1,
        filter: nullptr,
        bAllowDormantSpawn: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064040
// Name: protected: void C_EntityDissolve::BuildTeslaEffect(struct mstudiobbox_t __near *,struct matrix3x4_t const __near &,bool,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_EntityDissolve::BuildTeslaEffect(
        C_EntityDissolve *this@<ecx>,
        float a2@<ebp>,
        mstudiobbox_t *pHitBox,
        const matrix3x4_t *hitboxToWorld,
        bool bRandom,
        float flYawOffset)
{
  IUniformRandomStream *v7; // ecx
  unsigned int m_Index; // eax
  C_BaseEntity *v9; // edi
  int v10; // esi
  IUniformRandomStream *v11; // ecx
  double v12; // st7
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  const QAngle *v15; // eax
  float x; // esi
  CParticleSubTexture *PMaterial; // eax
  Particle *v18; // eax
  IUniformRandomStream *v19; // ecx
  Particle *v20; // esi
  IUniformRandomStream *v21; // ecx
  float z; // xmm0_4
  float v23; // xmm1_4
  IUniformRandomStream *v24; // ecx
  float v25; // xmm1_4
  char y_low; // al
  IUniformRandomStream *v27; // ecx
  Vector v28; // [esp+24h] [ebp-124h] BYREF
  CGameTrace tr; // [esp+30h] [ebp-118h] BYREF
  QAngle v30; // [esp+8Ch] [ebp-BCh] BYREF
  float v31; // [esp+9Ch] [ebp-ACh]
  float v32; // [esp+A0h] [ebp-A8h]
  float v33; // [esp+A4h] [ebp-A4h]
  int v34; // [esp+ACh] [ebp-9Ch]
  int v35; // [esp+B0h] [ebp-98h]
  int v36; // [esp+B4h] [ebp-94h]
  int v37; // [esp+BCh] [ebp-8Ch]
  int v38; // [esp+C0h] [ebp-88h]
  int v39; // [esp+C4h] [ebp-84h]
  int v40; // [esp+CCh] [ebp-7Ch]
  char v41; // [esp+D0h] [ebp-78h]
  bool v42; // [esp+D1h] [ebp-77h]
  Vector v43; // [esp+DCh] [ebp-6Ch] BYREF
  QAngle v44; // [esp+E8h] [ebp-60h] BYREF
  QAngle vecTemp; // [esp+F4h] [ebp-54h] BYREF
  QAngle v46; // [esp+100h] [ebp-48h] BYREF
  QAngle vecAngles; // [esp+10Ch] [ebp-3Ch] BYREF
  Vector vecOrigin; // [esp+118h] [ebp-30h] BYREF
  Vector vecForward; // [esp+124h] [ebp-24h] BYREF
  Vector pSimple; // [esp+130h] [ebp-18h] OVERLAPPED BYREF
  Vector vecFlash; // [esp+13Ch] [ebp-Ch]
  float retaddr; // [esp+148h] [ebp+0h]

  vecFlash.x = a2;
  vecFlash.y = retaddr;
  MatrixGetColumn(in: hitboxToWorld, column: 3, out: (Vector *)&vecAngles);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)hitboxToWorld, vAngles: &v46);
  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index == -1
    || (v7 = (IUniformRandomStream *)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
  {
    v9 = nullptr;
  }
  else
  {
    v9 = (C_BaseEntity *)v7->__vftable;
  }
  v10 = -1;
  do
  {
    ++v10;
    if ( bRandom )
    {
      pSimple.x = _RandomFloat(this: v7, a2: -1.0, a3: 1.0);
      pSimple.y = _RandomFloat(this: v13, a2: -1.0, a3: 1.0);
      v12 = _RandomFloat(this: v14, a2: -1.0, a3: 1.0);
      *(_QWORD *)&vecOrigin.x = *(_QWORD *)&pSimple.x;
    }
    else
    {
      v44.x = v46.x;
      v44.z = v46.z;
      v44.y = v46.y + flYawOffset;
      AngleVectors(angles: &v44, forward: &vecOrigin);
      v12 = _RandomFloat(this: v11, a2: -1.0, a3: 1.0);
    }
    vecOrigin.z = v12;
    v32 = (float)(vecAngles.y + (float)(vecOrigin.y * 192.0)) - vecAngles.y;
    v31 = (float)(vecAngles.x + (float)(vecOrigin.x * 192.0)) - vecAngles.x;
    v33 = (float)(vecAngles.z + (float)(vecOrigin.z * 192.0)) - vecAngles.z;
    v42 = (float)((float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v33 * v33)) != 0.0;
    v39 = 0;
    v38 = 0;
    v37 = 0;
    v40 = 0;
    v41 = 1;
    v36 = 0;
    v35 = 0;
    v34 = 0;
    v30 = vecAngles;
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)&tr.m_pEnt,
      passedict: v9,
      collisionGroup: 0,
      pExtraShouldHitFunc: nullptr);
    enginetrace->TraceRay(
      this: enginetrace,
      a2: (const Ray_t *)&v30,
      a3: 1174421507u,
      a4: (ITraceFilter *)&tr.m_pEnt,
      a5: (CGameTrace *)&v28);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(vecAbsStart: &v28, vecAbsEnd: &tr.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
  }
  while ( tr.plane.normal.z >= 1.0 && v10 < 3 );
  if ( tr.plane.normal.z < 1.0 && EffectOccluded(pos: &tr.startpos, queryHandle: nullptr) == 0 )
  {
    pSimple = tr.startpos;
    v15 = MainViewAngles(nSlot: 0);
    AngleVectors(angles: v15, forward: &v43);
    pSimple.y = pSimple.y - (float)(v43.y * 8.0);
    pSimple.z = pSimple.z - (float)(v43.z * 8.0);
    pSimple.x = pSimple.x - (float)(v43.x * 8.0);
    vecTemp.x = -v43.x;
    vecTemp.y = -v43.y;
    vecTemp.z = -v43.z;
    g_pEffects->EnergySplash(this: g_pEffects, a2: &pSimple, a3: (const Vector *)&vecTemp, a4: false);
    CSimpleEmitter::Create(result: (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&vecForward, pDebugName: "dust");
    CParticleEffect::SetSortOrigin(this: (CParticleEffect *)LODWORD(vecForward.x), vSortOrigin: &pSimple);
    x = vecForward.x;
    PMaterial = CParticleEffect::GetPMaterial(
                  this: (CParticleEffect *)LODWORD(vecForward.x),
                  name: "effects/tesla_glow_noz");
    v18 = CParticleEffect::AddParticle(
            this: (CParticleEffect *)LODWORD(x),
            particleSize: 0x3Cu,
            material: PMaterial,
            origin: &pSimple);
    v20 = v18;
    if ( v18 != nullptr )
    {
      v18[1].m_Pos.z = 0.0;
      v18[1].m_Pos.y = _RandomFloat(this: v19, a2: 0.5, a3: 1.0);
      *(Vector *)&v20[1].m_pPrev = vec3_origin;
      vecForward.z = _RandomFloat(this: v21, a2: 0.75, a3: 1.25);
      z = vecForward.z;
      if ( vecForward.z <= 1.0 )
        v23 = vecForward.z;
      else
        v23 = 1.0;
      v24 = (IUniformRandomStream *)(int)(float)(v23 * 255.0);
      LOBYTE(v20[2].m_pPrev) = (_BYTE)v24;
      if ( z <= 1.0 )
        v25 = z;
      else
        v25 = 1.0;
      BYTE1(v20[2].m_pPrev) = (int)(float)(v25 * 255.0);
      if ( z > 1.0 )
        z = 1.0;
      BYTE2(v20[2].m_pPrev) = (int)(float)(z * 255.0);
      LODWORD(vecForward.y) = (int)_RandomFloat(this: v24, a2: 6.0, a3: 13.0);
      y_low = LOBYTE(vecForward.y);
      BYTE1(v20[2].m_pNext) = LOBYTE(vecForward.y);
      BYTE2(v20[2].m_pNext) = y_low - 2;
      *(_WORD *)((char *)&v20[2].m_pPrev + 3) = 2815;
      v20[1].m_Pos.x = _RandomFloat(this: v27, a2: 0.0, a3: 360.0);
      v20[2].m_pSubTexture = nullptr;
    }
    if ( LODWORD(vecForward.x) != 0 )
      CParticleEffect::Release(this: (CParticleEffect *)LODWORD(vecForward.x));
  }
  FX_BuildTesla(vecOrigin: (Vector *)&vecAngles, vecEnd: &tr.startpos, pEntity: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10064590
// Name: protected: void C_EntityDissolve::DoSparks(struct mstudiohitboxset_t __near *,struct matrix3x4_t __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityDissolve::DoSparks(C_EntityDissolve *this, mstudiohitboxset_t *set, matrix3x4_t **hitboxbones)
{
  float v3; // xmm6_4
  float m_flFadeOutStart; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  int v7; // edi
  int i; // ebx
  float v9; // xmm0_4
  mstudiobbox_t *v10; // eax
  float flYawOffset; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v3 = *(float *)(gpGlobals.m_Index + 12);
  if ( this->m_flNextSparkTime <= v3 )
  {
    m_flFadeOutStart = this->m_flFadeOutStart;
    v5 = (float)(this->m_flStartTime + m_flFadeOutStart) - v3;
    if ( v5 >= 0.0 )
    {
      if ( v5 > this->m_flFadeOutStart )
        v5 = this->m_flFadeOutStart;
    }
    else
    {
      v5 = 0.0;
    }
    if ( this->m_nDissolveType == 1 )
    {
      if ( m_flFadeOutStart == 0.0 )
      {
        if ( v5 < 0.0 )
          v6 = *(float *)(gpGlobals.m_Index + 28) * 2.0;
        else
          v6 = 0.40000001;
      }
      else
      {
        v6 = (float)((float)((float)((float)((float)(v5 / m_flFadeOutStart) * (float)(v5 / m_flFadeOutStart)) * 3.0)
                           - (float)((float)((float)((float)(v5 / m_flFadeOutStart) * (float)(v5 / m_flFadeOutStart))
                                           * 2.0)
                                   * (float)(v5 / m_flFadeOutStart)))
                   * (float)(0.40000001 - (float)(*(float *)(gpGlobals.m_Index + 28) * 2.0)))
           + (float)(*(float *)(gpGlobals.m_Index + 28) * 2.0);
      }
    }
    else if ( m_flFadeOutStart == 0.0 )
    {
      if ( v5 < 0.0 )
        v6 = 0.30000001;
      else
        v6 = 1.0;
    }
    else
    {
      v6 = (float)((float)((float)((float)((float)(v5 / m_flFadeOutStart) * (float)(v5 / m_flFadeOutStart)) * 3.0)
                         - (float)((float)((float)((float)(v5 / m_flFadeOutStart) * (float)(v5 / m_flFadeOutStart)) * 2.0)
                                 * (float)(v5 / m_flFadeOutStart)))
                 * 0.69999999)
         + 0.30000001;
    }
    this->m_flNextSparkTime = v3 + v6;
    flYawOffset = _RandomFloat((IUniformRandomStream *)this, a2: 0.0, a3: 360.0);
    v7 = 0;
    for ( i = 0; i < 360; i += 120 )
    {
      v9 = 0.0;
      v10 = (mstudiobbox_t *)((char *)set
                            + 68 * random->RandomInt(this: random, a2: 0, a3: set->numhitboxes - 1)
                            + set->hitboxindex);
      if ( v7 < 2 )
        v9 = (float)(unsigned __int16)(int)(float)((float)((float)i + flYawOffset) * 182.04445) * 0.0054931641;
      C_EntityDissolve::BuildTeslaEffect(
        this,
        a2: COERCE_FLOAT(&savedregs),
        pHitBox: v10,
        hitboxToWorld: hitboxbones[v10->bone],
        bRandom: v7++ >= 2,
        flYawOffset: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064820
// Name: public: void C_EntityDissolve::SetupEmitter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityDissolve::SetupEmitter(C_EntityDissolve *this)
{
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v2; // eax
  CSimpleEmitter *m_pObj; // edi
  CSimpleEmitter *v4; // ecx
  CSimpleEmitter *v5; // edi
  const Vector *v6; // eax
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> result; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_pEmitter.m_pObj == nullptr )
  {
    v2 = CSimpleEmitter::Create(&result, pDebugName: "C_EntityDissolve");
    m_pObj = v2->m_pObj;
    if ( v2->m_pObj != this->m_pEmitter.m_pObj )
    {
      if ( m_pObj != nullptr )
        CParticleEffect::AddRef(this: v2->m_pObj);
      v4 = this->m_pEmitter.m_pObj;
      if ( v4 != nullptr )
        CParticleEffect::Release(this: v4);
      this->m_pEmitter.m_pObj = m_pObj;
    }
    if ( result.m_pObj != nullptr )
      CParticleEffect::Release(this: result.m_pObj);
    v5 = this->m_pEmitter.m_pObj;
    v6 = this->GetAbsOrigin(this);
    CParticleEffect::SetSortOrigin(this: v5, vSortOrigin: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100648A0
// Name: public: virtual int C_EntityDissolve::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_EntityDissolve::DrawModel(C_EntityDissolve *this, int flags, const RenderableInstance_t *instance)
{
  C_BaseEntity *MoveParent; // eax
  C_BaseAnimating *v5; // eax
  C_BaseAnimating *v6; // ebx
  IVModelInfoClient_vtbl *v7; // esi
  int v8; // eax
  int v9; // esi
  int v10; // ebx
  bool v11; // zf
  mstudiohitboxset_t *v12; // ebx
  double FadeInPercentage; // st7
  float m_flFadeInLength; // eax
  const Vector *v15; // eax
  float v16; // xmm1_4
  CParticleMgr *v17; // eax
  CParticleMgr *v18; // eax
  double v19; // st7
  float v20; // xmm0_4
  float v21; // xmm0_4
  float minVal; // xmm1_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  CParticleEffect *v24; // ecx
  Particle *v25; // esi
  double v26; // st7
  float v27; // xmm1_4
  float v28; // xmm2_4
  float z_low; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  double v32; // st7
  double v33; // st7
  int v34; // ebx
  float v35; // xmm0_4
  CParticleEffect *v36; // ecx
  Particle *v37; // esi
  double v38; // st7
  double v39; // st7
  double v40; // st7
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  matrix3x4_t *hitboxbones[256]; // [esp+30h] [ebp-4F4h] BYREF
  Vector yvec; // [esp+430h] [ebp-F4h] BYREF
  float v48; // [esp+43Ch] [ebp-E8h]
  float v49; // [esp+440h] [ebp-E4h]
  Vector xvec; // [esp+448h] [ebp-DCh] BYREF
  Vector v51; // [esp+454h] [ebp-D0h] BYREF
  float v52; // [esp+460h] [ebp-C4h]
  float v53; // [esp+464h] [ebp-C0h]
  Vector origin; // [esp+46Ch] [ebp-B8h] BYREF
  float v55; // [esp+478h] [ebp-ACh]
  float v56; // [esp+47Ch] [ebp-A8h]
  float v57; // [esp+480h] [ebp-A4h]
  float v58; // [esp+484h] [ebp-A0h]
  float v59; // [esp+488h] [ebp-9Ch]
  float v60; // [esp+48Ch] [ebp-98h]
  float v61; // [esp+490h] [ebp-94h]
  Vector vec; // [esp+494h] [ebp-90h] BYREF
  Vector vDirection; // [esp+4A0h] [ebp-84h] BYREF
  float xScale; // [esp+4ACh] [ebp-78h]
  mstudiohitboxset_t *set; // [esp+4B0h] [ebp-74h]
  float v66; // [esp+4B4h] [ebp-70h]
  float v67; // [esp+4B8h] [ebp-6Ch]
  float v68; // [esp+4BCh] [ebp-68h]
  int j; // [esp+4C0h] [ebp-64h]
  Vector xDir; // [esp+4C4h] [ebp-60h] BYREF
  Vector yDir; // [esp+4D0h] [ebp-54h] BYREF
  int v72; // [esp+4DCh] [ebp-48h]
  int iTempParts; // [esp+4E0h] [ebp-44h]
  float v74; // [esp+4E4h] [ebp-40h]
  float v75; // [esp+4E8h] [ebp-3Ch]
  float v76; // [esp+4ECh] [ebp-38h]
  float v77; // [esp+4F0h] [ebp-34h]
  Vector vecAbsOrigin; // [esp+4F4h] [ebp-30h] BYREF
  int numParticles; // [esp+500h] [ebp-24h]
  float yScale; // [esp+504h] [ebp-20h] BYREF
  Vector offset; // [esp+508h] [ebp-1Ch]
  float spriteScale; // [esp+514h] [ebp-10h] BYREF
  int i; // [esp+518h] [ebp-Ch] BYREF
  float v84; // [esp+51Ch] [ebp-8h]
  float fadePerc; // [esp+520h] [ebp-4h]

  if ( cl_portal_use_new_dissolve.m_pParent != nullptr && cl_portal_use_new_dissolve.m_pParent->m_Value.m_nValue != 0 )
    return 1;
  if ( *(float *)(gpGlobals.m_Index + 16) != 0.0
    && LOBYTE(this->m_VisibilityBits.m_Ints[0]) != 0
    && C_BaseEntity::GetMoveParent(this: (C_EntityDissolve *)((char *)this - 4)) != nullptr )
  {
    MoveParent = C_BaseEntity::GetMoveParent(this: (C_EntityDissolve *)((char *)this - 4));
    v5 = MoveParent->GetBaseAnimating(this: MoveParent);
    v6 = v5;
    if ( v5 != nullptr && C_BaseAnimating::HitboxToWorldTransforms(this: v5, pHitboxToWorld: hitboxbones) != 0 )
    {
      v7 = modelinfo->__vftable;
      v8 = (int)v6->GetModel(this: &v6->IClientRenderable);
      v9 = (int)v7->GetStudiomodel(this: modelinfo, a2: (const struct model_t *)v8);
      if ( v9 != 0 )
      {
        v10 = *(_DWORD *)(v9 + 176) + 12 * C_BaseAnimating::GetHitboxSet(this: v6);
        v11 = v9 + v10 == 0;
        v12 = (mstudiohitboxset_t *)(v9 + v10);
        set = v12;
        if ( !v11 )
        {
          C_EntityDissolve::SetupEmitter(this: (C_EntityDissolve *)((char *)this - 4));
          FadeInPercentage = C_EntityDissolve::GetFadeInPercentage(this: (C_EntityDissolve *)((char *)this - 4));
          *(float *)&i = FadeInPercentage;
          if ( FadeInPercentage < 1.0 )
            fadePerc = *(float *)&i;
          else
            fadePerc = C_EntityDissolve::GetFadeOutPercentage(this: (C_EntityDissolve *)((char *)this - 4));
          if ( fadePerc < 0.99000001 )
          {
            m_flFadeInLength = this->m_flFadeInLength;
            if ( LODWORD(m_flFadeInLength) == 1 || LODWORD(m_flFadeInLength) == 2 )
              C_EntityDissolve::DoSparks(this: (C_EntityDissolve *)((char *)this - 4), set: v12, hitboxbones);
          }
          *(float *)&i = 8.0 - (float)((float)(1.0 - fadePerc) * 32.0);
          v15 = CurrentViewForward();
          v66 = v15->x * *(float *)&i;
          v67 = v15->y * *(float *)&i;
          v16 = v15->z * *(float *)&i;
          spriteScale = (float)(*(float *)(gpGlobals.m_Index + 12) - *(float *)&this->IMotionEvent::__vftable)
                      / this->m_flFadeOutStart;
          *(float *)&i = 1.0;
          v68 = v16;
          yScale = 0.75;
          spriteScale = clamp<float,float,float>(val: &spriteScale, minVal: &yScale, maxVal: (const float *)&i);
          if ( g_Material_Spark == nullptr )
          {
            v17 = ParticleMgr();
            g_Material_Spark = CParticleMgr::GetPMaterial(this: v17, pMaterialName: "effects/spark");
          }
          if ( g_Material_AR2Glow == nullptr )
          {
            v18 = ParticleMgr();
            g_Material_AR2Glow = CParticleMgr::GetPMaterial(this: v18, pMaterialName: "effects/combinemuzzle2");
          }
          *(float *)&i = 0.0;
          if ( v12->numhitboxes <= 0 )
            return 1;
          v58 = fadePerc * 3.0;
          v72 = 0;
          while ( 2 )
          {
            C_EntityDissolve::ComputeRenderInfo(
              this: (C_EntityDissolve *)((char *)this - 4),
              pHitBox: (mstudiobbox_t *)((char *)v12 + v72 + v12->hitboxindex),
              hitboxToWorld: hitboxbones[*(int *)((char *)&v12->sznameindex + v72 + v12->hitboxindex)],
              pVecAbsOrigin: &vecAbsOrigin,
              pXVec: &xvec,
              pYVec: &yvec);
            xDir = xvec;
            v19 = VectorNormalize(vec: &xDir);
            yDir = yvec;
            xScale = v19 * 0.75;
            v20 = 0.0;
            yScale = VectorNormalize(vec: &yDir) * 0.75;
            if ( v58 >= 0.0 )
            {
              v20 = 3.0;
              if ( v58 <= 3.0 )
                v20 = v58;
            }
            v11 = LODWORD(this->m_flFadeInLength) == 3;
            numParticles = (int)v20;
            iTempParts = 2;
            if ( v11 && LOBYTE(this->m_nMagnitude) == 1 )
            {
              numParticles = 15;
              iTempParts = 20;
            }
            j = 0;
            v21 = yScale * 0.5;
            minVal = yScale * -0.5;
            v76 = yScale * 0.5;
            v77 = yScale * -0.5;
            v75 = xScale * 0.5;
            v74 = xScale * -0.5;
            while ( 1 )
            {
              fadePerc = Helper_RandomFloat(minVal, maxVal: v21);
              v59 = fadePerc * yDir.x;
              v60 = yDir.y * fadePerc;
              v61 = yDir.z * fadePerc;
              fadePerc = Helper_RandomFloat(minVal: v74, maxVal: v75);
              RandomInt = random->RandomInt;
              offset.x = (float)((float)(xDir.x * fadePerc) + v59) + v66;
              offset.y = (float)((float)(xDir.y * fadePerc) + v60) + v67;
              offset.z = (float)((float)(xDir.z * fadePerc) + v61) + v68;
              if ( RandomInt(this: random, a2: 0, a3: 2) != 0 )
                goto LABEL_47;
              v24 = *(CParticleEffect **)&this->m_bCoreExplode;
              origin.x = vecAbsOrigin.x + offset.x;
              origin.y = vecAbsOrigin.y + offset.y;
              origin.z = vecAbsOrigin.z + offset.z;
              v25 = CParticleEffect::AddParticle(this: v24, particleSize: 0x3Cu, material: g_Material_Spark, &origin);
              if ( v25 == nullptr )
                return 1;
              v52 = Helper_RandomFloat(minVal: -4.0, maxVal: 4.0);
              v53 = Helper_RandomFloat(minVal: -4.0, maxVal: 4.0);
              v26 = Helper_RandomFloat(minVal: 16.0, maxVal: 64.0);
              *(float *)&v25[1].m_pPrev = v52;
              *(float *)&v25[1].m_pNext = v53;
              *(float *)&v25[1].m_pSubTexture = v26;
              if ( LODWORD(this->m_flFadeInLength) == 3 && LOBYTE(this->m_nMagnitude) == 1 )
              {
                v27 = (float)(vecAbsOrigin.y + offset.y) - this->m_vDissolverOrigin.x;
                v28 = (float)(vecAbsOrigin.z + offset.z) - this->m_vDissolverOrigin.y;
                vDirection.x = (float)(vecAbsOrigin.x + offset.x) - this->m_flNextSparkTime;
                vDirection.y = v27;
                vDirection.z = v28;
                VectorNormalize(vec: &vDirection);
                z_low = (float)SLODWORD(this->m_vDissolverOrigin.z);
                v30 = vDirection.y * z_low;
                v31 = vDirection.z * z_low;
                *(float *)&v25[1].m_pPrev = vDirection.x * z_low;
                *(float *)&v25[1].m_pNext = v30;
                *(float *)&v25[1].m_pSubTexture = v31;
              }
              if ( *(float *)&v25[1].m_pSubTexture <= 0.0 )
              {
                BYTE1(v25[2].m_pNext) = (int)(float)(spriteScale * 2.0);
              }
              else
              {
                v32 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 1082130432,
                        a3: 1086324736);
                LODWORD(v84) = (int)(v32 * spriteScale);
                BYTE1(v25[2].m_pNext) = LOBYTE(v84);
              }
              v84 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1053609165,
                      a3: 1056964608);
              v25[1].m_Pos.y = v84;
              if ( numParticles != 0 )
              {
                v33 = Helper_RandomFloat(minVal: -8.0, maxVal: 8.0);
              }
              else
              {
                v25[1].m_Pos.y = v84 * 2.0;
                BYTE1(v25[2].m_pNext) = (int)(float)(spriteScale * 2.0);
                *(float *)&v25[2].m_pSubTexture = Helper_RandomFloat(minVal: -4.0, maxVal: 4.0);
                if ( LODWORD(this->m_flFadeInLength) != 3 || LOBYTE(this->m_nMagnitude) != 1 )
                  goto LABEL_46;
                v25[1].m_Pos.y = v25[1].m_Pos.y * 2.0;
                v33 = Helper_RandomFloat(minVal: -1.0, maxVal: 1.0);
              }
              *(float *)&v25[2].m_pSubTexture = v33;
LABEL_46:
              v25[1].m_Pos.z = 0.0;
              v25[1].m_Pos.x = (float)Helper_RandomInt(minVal: 0, maxVal: 360);
              v25[2].m_pPrev = (Particle *)-1;
              LOBYTE(v25[2].m_pNext) = 0;
              BYTE2(v25[2].m_pNext) = 0;
LABEL_47:
              if ( ++j >= iTempParts )
                break;
              v21 = v76;
              minVal = v77;
            }
            v34 = 0;
            if ( numParticles <= 0 )
            {
LABEL_56:
              v72 += 68;
              if ( ++i < set->numhitboxes )
              {
                v12 = set;
                continue;
              }
            }
            else
            {
              v35 = yScale * 0.5;
              v77 = yScale * -0.5;
              v76 = yScale * 0.5;
              v75 = xScale * 0.5;
              v74 = xScale * -0.5;
              while ( 1 )
              {
                v84 = Helper_RandomFloat(minVal: v77, maxVal: v35);
                v55 = v84 * yDir.x;
                v56 = yDir.y * v84;
                v57 = yDir.z * v84;
                v84 = Helper_RandomFloat(minVal: v74, maxVal: v75);
                v36 = *(CParticleEffect **)&this->m_bCoreExplode;
                offset.x = (float)((float)(v84 * xDir.x) + v55) + v66;
                v51.y = vecAbsOrigin.y + (float)((float)((float)(xDir.y * v84) + v56) + v67);
                offset.y = (float)((float)(xDir.y * v84) + v56) + v67;
                offset.z = (float)((float)(xDir.z * v84) + v57) + v68;
                v51.x = vecAbsOrigin.x + offset.x;
                v51.z = vecAbsOrigin.z + offset.z;
                v37 = CParticleEffect::AddParticle(
                        this: v36,
                        particleSize: 0x3Cu,
                        material: g_Material_AR2Glow,
                        origin: &v51);
                if ( v37 == nullptr )
                  break;
                v48 = Helper_RandomFloat(minVal: -4.0, maxVal: 4.0);
                v49 = Helper_RandomFloat(minVal: -4.0, maxVal: 4.0);
                v38 = Helper_RandomFloat(minVal: -64.0, maxVal: 128.0);
                *(float *)&v37[1].m_pPrev = v48;
                *(float *)&v37[1].m_pNext = v49;
                *(float *)&v37[1].m_pSubTexture = v38;
                v39 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 1090519040,
                        a3: 1094713344);
                v40 = v39 * spriteScale;
                v37[1].m_Pos.y = 0.1;
                v37[1].m_Pos.z = 0.0;
                LODWORD(v84) = (int)v40;
                BYTE1(v37[2].m_pNext) = (int)v40;
                v37[1].m_Pos.x = (float)Helper_RandomInt(minVal: 0, maxVal: 360);
                *(float *)&v37[2].m_pSubTexture = Helper_RandomFloat(minVal: -2.0, maxVal: 2.0);
                v37[2].m_pPrev = (Particle *)-1;
                LOBYTE(v37[2].m_pNext) = 0;
                BYTE2(v37[2].m_pNext) = 0;
                if ( LODWORD(this->m_flFadeInLength) == 3 && LOBYTE(this->m_nMagnitude) == 1 )
                {
                  v41 = (float)(vecAbsOrigin.y + offset.y) - this->m_vDissolverOrigin.x;
                  v42 = (float)(vecAbsOrigin.z + offset.z) - this->m_vDissolverOrigin.y;
                  vec.x = (float)(vecAbsOrigin.x + offset.x) - this->m_flNextSparkTime;
                  vec.y = v41;
                  vec.z = v42;
                  VectorNormalize(&vec);
                  v43 = vec.y * (float)SLODWORD(this->m_vDissolverOrigin.z);
                  v44 = vec.z * (float)SLODWORD(this->m_vDissolverOrigin.z);
                  *(float *)&v37[1].m_pPrev = vec.x * (float)SLODWORD(this->m_vDissolverOrigin.z);
                  *(float *)&v37[1].m_pNext = v43;
                  *(float *)&v37[1].m_pSubTexture = v44;
                  v37[1].m_Pos.y = 0.5;
                }
                if ( ++v34 >= numParticles )
                  goto LABEL_56;
                v35 = v76;
              }
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100653F0
// Name: public: virtual void C_EntityDissolve::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityDissolve::ClientThink(C_EntityDissolve *this)
{
  unsigned int v2; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *v9; // ecx
  C_BaseAnimating *v10; // eax
  C_BaseEntity *v11; // ebx
  int v12; // ebx
  int *p_m_depth; // eax
  int v14; // esi
  float v15; // xmm2_4
  float v16; // xmm1_4
  float m_flFadeOutLength; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float m_flStartTime; // xmm2_4
  float v22; // xmm0_4
  float m_flFadeOutStart; // xmm2_4
  unsigned __int8 v24; // al
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  IMotionEvent_vtbl *v32; // xmm1_4
  _BYTE *v33; // eax
  _DWORD v34[1024]; // [esp+4h] [ebp-1008h] BYREF
  int a[2]; // [esp+1004h] [ebp-8h]

  v2 = *(_DWORD *)&this->m_iParentAttachment;
  if ( v2 == -1 )
    return;
  v3 = (unsigned __int16)v2;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v2];
  v5 = HIWORD(v2);
  if ( v4->m_SerialNumber != v5 || v4->m_pEntity == nullptr )
    return;
  v6 = v3;
  v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
  v8 = &g_pEntityList->m_EntPtrArray[v6];
  v9 = v7 ? v8->m_pEntity : nullptr;
  v10 = (C_BaseAnimating *)v9->__vftable[14].GetRefEHandle(this: v9);
  v11 = v10;
  a[0] = (int)v10;
  if ( v10 == nullptr )
    return;
  if ( *(_DWORD *)&this->m_bCoreExplode == 0
    && LODWORD(this->m_flFadeOutModelLength) == 0
    && C_BaseAnimating::IsRagdoll(this: v10) )
  {
    v12 = v11->VPhysicsGetObjectList(this: v11, a2: (IPhysicsObject **)v34, a3: 1024);
    if ( v12 > 0 )
    {
      if ( this == (C_EntityDissolve *)12 )
        p_m_depth = nullptr;
      else
        p_m_depth = &this->m_CalcAbsoluteVelocityMutex.m_depth;
      v14 = 0;
      *(_DWORD *)&this->m_bCoreExplode = physenv->CreateMotionController(this: physenv, a2: p_m_depth);
      do
        (*(void (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)&this->m_bCoreExplode + 8))(
          a1: *(_DWORD *)&this->m_bCoreExplode,
          a2: v34[v14++],
          a3: 1);
      while ( v14 < v12 );
    }
    v11 = (C_BaseEntity *)a[0];
  }
  v15 = *(float *)(gpGlobals.m_Index + 12) - *(float *)&this->m_bIsBlurred;
  v16 = 1.0;
  if ( v15 > *((float *)&this->m_bIsBlurred + 1) )
    goto LABEL_24;
  m_flFadeOutLength = this->m_flFadeOutLength;
  if ( m_flFadeOutLength > v15 )
  {
    v18 = 0.0;
    goto LABEL_25;
  }
  if ( v15 <= m_flFadeOutLength || (float)(this->m_flFadeOutModelStart + m_flFadeOutLength) <= v15 )
LABEL_24:
    v18 = 1.0;
  else
    v18 = (float)(v15 - m_flFadeOutLength) / this->m_flFadeOutModelStart;
LABEL_25:
  v19 = 1.0 - v18;
  v20 = *(float *)(gpGlobals.m_Index + 12) - *(float *)&this->m_bIsBlurred;
  m_flStartTime = this->m_flStartTime;
  BYTE2(a[0]) = (int)(float)(v19 * 255.0);
  if ( m_flStartTime <= v20 && v20 > m_flStartTime )
  {
    v22 = v20 - m_flStartTime;
    m_flFadeOutStart = this->m_flFadeOutStart;
    if ( v22 <= m_flFadeOutStart )
      v16 = 1.0 - (float)(v22 / m_flFadeOutStart);
    else
      v16 = 0.0;
  }
  HIBYTE(a[0]) = (int)(float)(v16 * 255.0);
  C_BaseEntity::SetRenderMode(this: v11, nRenderMode: kRenderTransColor, bForceUpdate: false);
  v24 = BYTE2(a[0]);
  if ( v11->m_clrRender.m_Value.r != BYTE2(a[0]) )
    v11->m_clrRender.m_Value.r = BYTE2(a[0]);
  if ( v11->m_clrRender.m_Value.g != v24 )
    v11->m_clrRender.m_Value.g = v24;
  if ( v11->m_clrRender.m_Value.b != v24 )
    v11->m_clrRender.m_Value.b = v24;
  C_BaseEntity::SetRenderAlpha(this: v11, a: *(int *)((char *)a + 3));
  v25 = *(float *)(gpGlobals.m_Index + 12) - *(float *)&this->m_bIsBlurred;
  v26 = this->m_flStartTime;
  if ( v26 <= v25 && v25 > v26 )
  {
    v27 = v25 - v26;
    v28 = this->m_flFadeOutStart;
    if ( v27 > v28 || (float)(1.0 - (float)(v27 / v28)) <= 0.2 )
      LOBYTE(this->m_vDissolverOrigin.y) = 1;
  }
  v29 = *(float *)(gpGlobals.m_Index + 12) - *(float *)&this->m_bIsBlurred;
  if ( this->m_flFadeOutLength <= v29 )
  {
    v30 = *((float *)&this->m_bIsBlurred + 1);
    if ( v29 > v30 )
    {
      v31 = v29 - v30;
      v32 = this->IMotionEvent::__vftable;
      if ( v31 > *(float *)&v32 || (float)(1.0 - (float)(v31 / *(float *)&v32)) <= 0.0 )
      {
        ((void (__stdcall *)(int, _DWORD))partition->Remove_2)(
          a1: 140,
          a2: LOWORD(this->m_Collision.m_vecMaxs.m_Value.z));
        C_BaseEntity::RemoveFromLeafSystem(this: (C_EntityDissolve *)((char *)this - 12));
        if ( LOBYTE(this->m_nMagnitude) == 0 )
        {
          (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 4))(a1: (char *)this - 4);
          v33 = __RTDynamicCast(
                  inptr: v11,
                  VfDelta: 0,
                  SrcType: &C_BaseAnimating `RTTI Type Descriptor',
                  TargetType: &C_ClientRagdoll `RTTI Type Descriptor',
                  isReference: 0);
          if ( v33 != nullptr )
            v33[3292] = 1;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065E60
// Name: public: virtual void C_EntityDissolve::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityDissolve::GetRenderBounds(C_EntityDissolve *this, Vector *theMins, Vector *theMaxs)
{
  unsigned int m_nSplitUserPlayerPredictionSlot; // edx
  int v4; // eax
  CEntInfo *v5; // esi
  unsigned int v6; // edx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax

  m_nSplitUserPlayerPredictionSlot = this->m_nSplitUserPlayerPredictionSlot;
  if ( m_nSplitUserPlayerPredictionSlot != -1
    && (v4 = (unsigned __int16)m_nSplitUserPlayerPredictionSlot,
        v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nSplitUserPlayerPredictionSlot],
        v6 = HIWORD(m_nSplitUserPlayerPredictionSlot),
        v5->m_SerialNumber == v6)
    && v5->m_pEntity != nullptr )
  {
    v7 = v4;
    v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
    v9 = &g_pEntityList->m_EntPtrArray[v7];
    if ( v8 )
      m_pEntity = v9->m_pEntity;
    else
      m_pEntity = nullptr;
    ((void (__thiscall *)(IHandleEntity *, Vector *, Vector *))m_pEntity[1].__vftable[5].GetRefEHandle)(
      a1: &m_pEntity[1],
      a2: theMins,
      a3: theMaxs);
  }
  else
  {
    *theMins = *(Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411970
// Name: PrecacheEffectBuildPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectBuildPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectBuildPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectBuildPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104119B0
// Name: DT_EntityDissolve::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityDissolve::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EntityDissolve::g_RecvTable);
  return atexit(func: DT_EntityDissolve::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104119D0
// Name: DT_EntityDissolve::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityDissolve::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EntityDissolve::ignored>();
  DT_EntityDissolve::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430160
// Name: DT_EntityDissolve::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityDissolve::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EntityDissolve::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10064790
// Name: _C_EntityDissolve_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EntityDissolve_CreateObject(int entnum, int serialNum)
{
  C_EntityDissolve *v2; // eax
  C_EntityDissolve *v3; // eax
  C_EntityDissolve *v4; // esi

  v2 = (C_EntityDissolve *)C_BaseEntity::operator new(stAllocateBlock: 0x9C8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EntityDissolve::C_EntityDissolve(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411990
// Name: _dynamic_initializer_for____g_C_EntityDissolveClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EntityDissolveClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EntityDissolveClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EntityDissolveClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104119E0
// Name: _dynamic_initializer_for____g_C_EntityFlameClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EntityFlameClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EntityFlameClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EntityFlameClientClass;
  return result;
}
