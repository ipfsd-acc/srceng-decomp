// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particlemgr.cpp
// Functions: 103
// ============================================================

#include "game\client\particlemgr.h"

//------------------------------------------------------------------------------
// Address: 0x10027250
// Name: private: void CParallelProcessor<class C_BaseAnimating __near *,class CFuncJobItemProcessor<class C_BaseAnimating __near *>,2>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute(
        CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *this)
{
  void (*m_pfnBegin)(void); // eax
  C_BaseAnimating **m_pLimit; // ecx
  unsigned int v4; // edx
  C_BaseAnimating **v5; // esi
  C_BaseAnimating **v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  C_BaseAnimating **pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (C_BaseAnimating **)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (C_BaseAnimating **)((char *)v5 + v4);
      if ( m_pLimit < (C_BaseAnimating **)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100318E0
// Name: public: void CParallelProcessor<class C_BaseAnimating __near *,class CFuncJobItemProcessor<class C_BaseAnimating __near *>,2>::Run(class C_BaseAnimating __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::Run(
        CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *this,
        C_BaseAnimating **pItems,
        int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  IThreadPool *v7; // esi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  void *v11; // esp
  CFunctor *v12; // eax
  CFunctor v13; // xmm0_8
  CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *v14; // ecx
  int i; // esi
  _DWORD v16[3]; // [esp+0h] [ebp-20h]
  CFunctor v17; // [esp+Ch] [ebp-14h]
  CFunctor v18; // [esp+14h] [ebp-Ch]
  CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *v19; // [esp+1Ch] [ebp-4h]
  int nJobs; // [esp+2Ch] [ebp+Ch]

  v19 = this;
  if ( nItems != 0 )
  {
    v7 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v7 == nullptr )
      v7 = _g_pThreadPool;
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v8 = nMaxParallel;
    v9 = nItems - 1;
    this->m_pLimit = &pItems[nItems];
    nJobs = v9;
    if ( v9 > v8 )
    {
      nJobs = v8;
      v9 = v8;
    }
    if ( v7 == nullptr )
      goto LABEL_18;
    v10 = v7->NumThreads(this: v7);
    if ( v9 > v10 )
    {
      nJobs = v10;
      v9 = v10;
    }
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      v17.__vftable = (CFunctor_vtbl *)CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute;
      v17.m_nUserID = 0;
      v18 = 0;
      do
      {
        --v9;
        v12 = (CFunctor *)MemAlloc_Alloc(nSize: 0x28u);
        if ( v12 != nullptr )
        {
          v13 = v17;
          v14 = v19;
          v12[1].m_nUserID = 1;
          v12->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *,void (__thiscall CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v12[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *,void (__thiscall CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v12[2] = v13;
          v12[3] = v18;
          v12[4].__vftable = (CFunctor_vtbl *)v14;
        }
        else
        {
          v12 = nullptr;
        }
        v7->AddFunctorInternal(this: v7, a2: v12, a3: (CJob **)&nChunkSize, a4: nullptr, a5: 8u);
        v16[v9] = nChunkSize;
      }
      while ( v9 != 0 );
      CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute(this: v19);
      for ( i = 0; i < nJobs; ++i )
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
      }
    }
    else
    {
LABEL_18:
      CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C82A0
// Name: ShouldDrawInWireFrameMode
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ShouldDrawInWireFrameMode()
{
  ConVar *v0; // eax

  v0 = (ConVar *)sv_cheats;
  if ( sv_cheats == nullptr )
  {
    v0 = cvar->FindVar_2(this: cvar, a2: "sv_cheats");
    sv_cheats = v0;
    if ( v0 == nullptr )
      return false;
  }
  if ( v0->m_pParent == nullptr || v0->m_pParent->m_Value.m_nValue == 0 )
    return false;
  if ( mat_wireframe.m_pParent != nullptr )
    return mat_wireframe.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100C8540
// Name: public: virtual class IClientUnknown __near * CDefaultClientRenderable::GetIClientUnknown(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CDefaultClientRenderable::GetIClientUnknown(C_BaseEntity *this)
{
  return (C_BaseEntity *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x100C8550
// Name: public: virtual class IClientRenderable __near * CDefaultClientRenderable::GetClientRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall CDefaultClientRenderable::GetClientRenderable(C_BaseEntity *this)
{
  if ( this != nullptr )
    return &this->IClientRenderable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C8560
// Name: public: virtual bool CDefaultClientRenderable::ShouldDrawForSplitScreenUser(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDefaultClientRenderable::ShouldDrawForSplitScreenUser(C_BasePlayer *this, C_BaseCombatWeapon *pWeapon)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012FF60
// Name: public: virtual class Vector const __near & CParticleEffectBinding::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CParticleEffectBinding::GetRenderOrigin(CParticleEffectBinding *this)
{
  return (*(const Vector *(__thiscall **)(_DWORD))(**(_DWORD **)&this->m_ListIndex + 36))(a1: *(_DWORD *)&this->m_ListIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1012FF70
// Name: public: virtual class QAngle const __near & CParticleEffectBinding::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CParticleEffectBinding::GetRenderAngles(C_GameRules *this)
{
  return &vec3_angle;
}

//------------------------------------------------------------------------------
// Address: 0x1012FF80
// Name: public: int CParticleEffectBinding::GetNumActiveParticles(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleEffectBinding::GetNumActiveParticles(CParticleEffectBinding *this)
{
  return this->m_nActiveParticles;
}

//------------------------------------------------------------------------------
// Address: 0x1012FF90
// Name: public: void CParticleMgr::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::LevelInit(CParticleMgr *this)
{
  CParticleSystemMgr::SetLastSimulationTime(this: g_pParticleSystemMgr, flTime: *(float *)(gpGlobals.m_Index + 12));
}

//------------------------------------------------------------------------------
// Address: 0x1012FFB0
// Name: public: void CParticleMgr::RenderParticleSystems(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::RenderParticleSystems(CParticleMgr *this, bool bEnable)
{
  this->m_bRenderParticleEffects = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1012FFC0
// Name: public: bool CParticleMgr::ShouldRenderParticleSystems(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleMgr::ShouldRenderParticleSystems(CParticleMgr *this)
{
  return this->m_bRenderParticleEffects;
}

//------------------------------------------------------------------------------
// Address: 0x1012FFD0
// Name: public: class CNewParticleEffect __near * CParticleMgr::NextNewEffect(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__thiscall CParticleMgr::NextNewEffect(CParticleMgr *this, CNewParticleEffect *pEffect)
{
  if ( pEffect != nullptr )
    return pEffect->m_pNext;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1012FFF0
// Name: int GetParticlePerformance(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetParticlePerformance()
{
  __int64 v0; // rax

  LODWORD(v0) = HIDWORD(g_nNumUSSpentSimulatingParticles) | g_nNumUSSpentSimulatingParticles;
  if ( g_nNumUSSpentSimulatingParticles != 0 )
    return 1000 * g_nNumParticlesSimulated / g_nNumUSSpentSimulatingParticles;
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x10130030
// Name: void ResetParticlePerformanceCounters(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResetParticlePerformanceCounters()
{
  g_nNumUSSpentSimulatingParticles = 0;
  g_nNumParticlesSimulated = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10130050
// Name: ProcessNonDrawingSystem
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessNonDrawingSystem(CParticleCollection **pNonDrawingEffect)
{
  CParticleCollection::Simulate(this: *pNonDrawingEffect, dt: s_flThreadedPSystemTimeStep);
}

//------------------------------------------------------------------------------
// Address: 0x10130070
// Name: private: static int CParticleMgr::RetireSort(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CParticleMgr::RetireSort(float *p1, float *p2)
{
  float v2; // xmm0_4

  v2 = p1[1] - p2[1];
  if ( v2 == 0.0 )
    return 0;
  if ( v2 <= 0.0 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101300B0
// Name: CountChildParticleSystems
// Source: json
//------------------------------------------------------------------------------
int __cdecl CountChildParticleSystems(CParticleCollection *p)
{
  CParticleCollection *m_pHead; // esi
  int i; // edi
  int v3; // eax

  m_pHead = p->m_Children.m_pHead;
  for ( i = 1; m_pHead != nullptr; i += v3 )
  {
    v3 = CountChildParticleSystems(p: m_pHead);
    m_pHead = m_pHead->m_pNext;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10130120
// Name: float Helper_RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
float __cdecl Helper_RandomFloat(float minVal, float maxVal)
{
  return ((float (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
           a1: random,
           a2: LODWORD(minVal),
           a3: LODWORD(maxVal));
}

//------------------------------------------------------------------------------
// Address: 0x10130150
// Name: int Helper_RandomInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Helper_RandomInt(int minVal, int maxVal)
{
  return random->RandomInt(this: random, a2: minVal, a3: maxVal);
}

//------------------------------------------------------------------------------
// Address: 0x10130170
// Name: float Helper_GetFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Helper_GetFrameTime()
{
  return *(float *)(gpGlobals.m_Index + 16);
}

//------------------------------------------------------------------------------
// Address: 0x10130230
// Name: public: void VMatrix::CopyFrom3x4(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::CopyFrom3x4(VMatrix *this, const matrix3x4_t *m3x4)
{
  *(matrix3x4_t *)&this->m[0][0] = *m3x4;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][0] = 0.0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101302A0
// Name: public: bool VMatrix::IsIdentity(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall VMatrix::IsIdentity(VMatrix *this)
{
  return this->m[0][0] == 1.0
      && this->m[0][1] == 0.0
      && this->m[0][2] == 0.0
      && this->m[0][3] == 0.0
      && this->m[1][0] == 0.0
      && this->m[1][1] == 1.0
      && this->m[1][2] == 0.0
      && this->m[1][3] == 0.0
      && this->m[2][0] == 0.0
      && this->m[2][1] == 0.0
      && this->m[2][2] == 1.0
      && this->m[2][3] == 0.0
      && this->m[3][0] == 0.0
      && this->m[3][1] == 0.0
      && this->m[3][2] == 0.0
      && this->m[3][3] == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101303B0
// Name: public: void CParticleEffectBinding::SetParticleCullRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::SetParticleCullRadius(CParticleEffectBinding *this, float flMaxParticleRadius)
{
  int m_hRenderHandle; // eax

  if ( this->m_flParticleCullRadius != flMaxParticleRadius )
  {
    m_hRenderHandle = this->m_hRenderHandle;
    this->m_flParticleCullRadius = flMaxParticleRadius;
    if ( (_WORD)m_hRenderHandle != 0xFFFF )
      g_pClientLeafSystem->RenderableChanged(this: g_pClientLeafSystem, a2: m_hRenderHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130400
// Name: public: virtual struct matrix3x4_t const __near & CParticleEffectBinding::RenderableToWorldTransform(void)
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall CParticleEffectBinding::RenderableToWorldTransform(CParticleEffectBinding *this)
{
  const Vector *v2; // eax

  if ( (_S6_33 & 1) == 0 )
    _S6_33 |= 1u;
  SetIdentityMatrix(matrix: &mat_0);
  v2 = (const Vector *)((int (__thiscall *)(CParticleEffectBinding *))this->SetRefEHandle)(a1: this);
  MatrixSetColumn(in: v2, column: 3, out: &mat_0);
  return &mat_0;
}

//------------------------------------------------------------------------------
// Address: 0x10130450
// Name: public: virtual void CParticleEffectBinding::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::GetRenderBounds(CParticleEffectBinding *this, Vector *mins, Vector *maxs)
{
  float *v4; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  v4 = (float *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_ListIndex + 36))(a1: *(_DWORD *)&this->m_ListIndex);
  v5 = *(float *)&this->m_bLocalSpaceTransformIdentity - *v4;
  v6 = this->m_Min.x - v4[1];
  v7 = this->m_Min.y - v4[2];
  mins->x = v5;
  mins->y = v6;
  mins->z = v7;
  mins->x = v5 - this->m_LastMax.z;
  mins->y = v6 - this->m_LastMax.z;
  mins->z = v7 - this->m_LastMax.z;
  v8 = this->m_Min.z - *v4;
  v9 = this->m_Max.x - v4[1];
  v10 = this->m_Max.y - v4[2];
  maxs->x = v8;
  maxs->y = v9;
  maxs->z = v10;
  maxs->x = this->m_LastMax.z + v8;
  maxs->y = this->m_LastMax.z + v9;
  maxs->z = this->m_LastMax.z + v10;
}

//------------------------------------------------------------------------------
// Address: 0x10130510
// Name: public: virtual bool CParticleEffectBinding::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CParticleEffectBinding::ShouldDraw(CParticleEffectBinding *this)
{
  return ((int)this->m_pParticleMgr & 0x100) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10130520
// Name: public: void CParticleEffectBinding::GetWorldspaceBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::GetWorldspaceBounds(CParticleEffectBinding *this, Vector *pMins, Vector *pMaxs)
{
  *pMins = this->m_Min;
  *pMaxs = this->m_Max;
}

//------------------------------------------------------------------------------
// Address: 0x10130550
// Name: public: void CParticleEffectBinding::SetLocalSpaceTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::SetLocalSpaceTransform(
        CParticleEffectBinding *this,
        const matrix3x4_t *transform)
{
  VMatrix *p_m_LocalSpaceTransform; // ecx

  p_m_LocalSpaceTransform = &this->m_LocalSpaceTransform;
  *(matrix3x4_t *)&p_m_LocalSpaceTransform->m[0][0] = *transform;
  p_m_LocalSpaceTransform->m[3][2] = 0.0;
  p_m_LocalSpaceTransform->m[3][1] = 0.0;
  p_m_LocalSpaceTransform->m[3][0] = 0.0;
  p_m_LocalSpaceTransform->m[3][3] = 1.0;
  this->m_bLocalSpaceTransformIdentity = VMatrix::IsIdentity(this: p_m_LocalSpaceTransform);
}

//------------------------------------------------------------------------------
// Address: 0x101305D0
// Name: public: bool CParticleEffectBinding::EnlargeBBoxToContain(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleEffectBinding::EnlargeBBoxToContain(CParticleEffectBinding *this, const Vector *pt)
{
  bool result; // al
  float y; // xmm0_4
  float z; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4

  if ( this->m_nActiveParticles != 0 )
  {
    result = false;
    if ( this->m_Min.x > pt->x )
    {
      this->m_Min.x = pt->x;
      result = true;
    }
    y = pt->y;
    if ( this->m_Min.y > y )
    {
      this->m_Min.y = y;
      result = true;
    }
    z = pt->z;
    if ( this->m_Min.z > z )
    {
      this->m_Min.z = z;
      result = true;
    }
    if ( pt->x > this->m_Max.x )
    {
      this->m_Max.x = pt->x;
      result = true;
    }
    v5 = pt->y;
    if ( v5 > this->m_Max.y )
    {
      this->m_Max.y = v5;
      result = true;
    }
    v6 = pt->z;
    if ( v6 > this->m_Max.z )
    {
      this->m_Max.z = v6;
      return true;
    }
  }
  else
  {
    this->m_Max = *pt;
    this->m_Min = this->m_Max;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10130690
// Name: public: void CParticleEffectBinding::DetectChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::DetectChanges(CParticleEffectBinding *this)
{
  int m_hRenderHandle; // edx

  m_hRenderHandle = this->m_hRenderHandle;
  if ( (_WORD)m_hRenderHandle != 0xFFFF
    && (this->m_LastMin.x != this->m_Min.x
     || this->m_LastMin.y != this->m_Min.y
     || this->m_LastMin.z != this->m_Min.z
     || this->m_LastMax.x != this->m_Max.x
     || this->m_LastMax.y != this->m_Max.y
     || this->m_LastMax.z != this->m_Max.z) )
  {
    g_pClientLeafSystem->RenderableChanged(this: g_pClientLeafSystem, a2: m_hRenderHandle);
    this->m_LastMin.x = this->m_Min.x;
    this->m_LastMin.y = this->m_Min.y;
    this->m_LastMin.z = this->m_Min.z;
    this->m_LastMax.x = this->m_Max.x;
    this->m_LastMax.y = this->m_Max.y;
    this->m_LastMax.z = this->m_Max.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130740
// Name: public: void CParticleEffectBinding::SetDrawThruLeafSystem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::SetDrawThruLeafSystem(CParticleEffectBinding *this, int bDraw)
{
  if ( bDraw != 0 )
    this->m_Flags |= 0x100u;
  else
    this->m_Flags &= ~0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x10130770
// Name: public: void CParticleEffectBinding::SetDrawBeforeViewModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::SetDrawBeforeViewModel(CParticleEffectBinding *this, int bDraw)
{
  if ( bDraw != 0 )
    this->m_Flags = this->m_Flags & 0xFFFFFCFF | 0x200;
  else
    this->m_Flags &= ~0x200u;
}

//------------------------------------------------------------------------------
// Address: 0x101307B0
// Name: private: void CParticleEffectBinding::DoBucketSort(class CEffectMaterial __near *,float __near *,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::DoBucketSort(
        CParticleEffectBinding *this,
        CEffectMaterial *pMaterial,
        float *zCoords,
        int nZCoords,
        float minZ,
        float maxZ)
{
  Particle *v6; // eax
  int i; // ecx
  Particle *m_pNext; // ecx
  Particle *p_m_Particles; // edx
  int v10; // edi
  Particle *v11; // esi
  float v12; // xmm0_4
  Particle *v13; // eax
  Particle *v14; // esi
  int j; // edi
  Particle *v16; // eax
  Particle *v17; // ecx
  Particle buckets[32]; // [esp+0h] [ebp-300h] BYREF

  v6 = buckets;
  for ( i = 32; i != 0; --i )
  {
    v6->m_pNext = v6;
    v6->m_pPrev = v6;
    ++v6;
  }
  m_pNext = pMaterial->m_Particles.m_pNext;
  p_m_Particles = &pMaterial->m_Particles;
  v10 = 0;
  if ( m_pNext != &pMaterial->m_Particles )
  {
    do
    {
      v11 = m_pNext->m_pNext;
      if ( v10 >= nZCoords )
        break;
      m_pNext->m_pPrev->m_pNext = v11;
      m_pNext->m_pNext->m_pPrev = m_pNext->m_pPrev;
      v12 = maxZ == minZ ? 0.0 : (float)(zCoords[v10] - minZ) / (float)(maxZ - minZ);
      v13 = &buckets[(int)(float)(v12 * -31.999901) + 31];
      m_pNext->m_pPrev = v13;
      m_pNext->m_pNext = v13->m_pNext;
      v13->m_pNext = m_pNext;
      ++v10;
      m_pNext->m_pNext->m_pPrev = m_pNext;
      m_pNext = v11;
    }
    while ( v11 != p_m_Particles );
  }
  v14 = buckets;
  for ( j = 32; j != 0; --j )
  {
    v16 = v14->m_pNext;
    if ( v16 != v14 )
    {
      do
      {
        v17 = v16->m_pNext;
        v16->m_pPrev = p_m_Particles;
        v16->m_pNext = pMaterial->m_Particles.m_pNext;
        pMaterial->m_Particles.m_pNext = v16;
        v16->m_pNext->m_pPrev = v16;
        v16 = v17;
      }
      while ( v17 != v14 );
    }
    ++v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130890
// Name: private: void CParticleEffectBinding::RemoveParticle(struct Particle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::RemoveParticle(CParticleEffectBinding *this, Particle *pParticle)
{
  pParticle->m_pPrev->m_pNext = pParticle->m_pNext;
  pParticle->m_pNext->m_pPrev = pParticle->m_pPrev;
  --this->m_nActiveParticles;
  this->m_pSim->NotifyDestroyParticle(this: this->m_pSim, a2: pParticle);
  --this->m_pParticleMgr->m_nCurrentParticlesAllocated;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pParticle);
}

//------------------------------------------------------------------------------
// Address: 0x101308F0
// Name: void EndSimulateParticles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EndSimulateParticles(void *this)
{
  long double v1; // st7
  int m_nValue; // eax
  float flETimea; // [esp+4h] [ebp-4h]
  float flETime; // [esp+4h] [ebp-4h]

  v1 = _Plat_FloatTime(a1: this) - g_flStartSimTime;
  if ( g_bMeasureParticlePerformance )
    g_nNumUSSpentSimulatingParticles = (unsigned __int64)(v1 * 1000000.0 + (double)g_nNumUSSpentSimulatingParticles);
  flETimea = v1;
  CParticleSystemMgr::SetLastSimulationDuration(this: g_pParticleSystemMgr, flDuration: flETimea);
  if ( r_particle_sim_spike_threshold_ms.m_pParent != nullptr )
    m_nValue = r_particle_sim_spike_threshold_ms.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( flETime <= (double)m_nValue * 0.001 )
    CParticleSystemMgr::CommitProfileInformation(this: g_pParticleSystemMgr, bCommit: false);
  else
    CParticleSystemMgr::CommitProfileInformation(this: g_pParticleSystemMgr, bCommit: true);
}

//------------------------------------------------------------------------------
// Address: 0x101309A0
// Name: ProcessPSystem
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessPSystem(CNewParticleEffect **pNewEffect)
{
  char v1; // al
  CNewParticleEffect *v2; // ecx

  if ( (*pNewEffect)->m_bQueuedStartEmission )
  {
    (*pNewEffect)->m_bQueuedStartEmission = false;
    CParticleCollection::StartEmission(this: &(*pNewEffect)->CParticleCollection, bInfiniteOnly: false);
  }
  v1 = *((_BYTE *)*pNewEffect + 944);
  if ( (v1 & 8) != 0 && ((v1 & 0x20) == 0 || CNewParticleEffect::RecalculateBoundingBox(this: *pNewEffect)) )
    *((_BYTE *)*pNewEffect + 944) &= ~8u;
  *((_BYTE *)*pNewEffect + 944) &= ~4u;
  v2 = *pNewEffect;
  if ( (*((_BYTE *)*pNewEffect + 944) & 0x10) != 0 )
  {
    CParticleCollection::Simulate(this: &v2->CParticleCollection, dt: 0.0);
    *((_BYTE *)*pNewEffect + 944) &= ~0x10u;
  }
  else if ( v2->ShouldSimulate(this: v2) )
  {
    CParticleCollection::Simulate(this: &(*pNewEffect)->CParticleCollection, dt: s_flThreadedPSystemTimeStep);
  }
  if ( CParticleCollection::IsFinished(this: &(*pNewEffect)->CParticleCollection) )
    *((_BYTE *)*pNewEffect + 944) |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x10130A50
// Name: private: bool CParticleMgr::RetireParticleCollections(class CParticleSystemDefinition __near *,int,struct CParticleMgr::RetireInfo_t __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleMgr::RetireParticleCollections(
        CParticleMgr *this,
        CParticleSystemDefinition *pDef,
        int nCount,
        CParticleMgr::RetireInfo_t *pInfo,
        float flScreenArea,
        float flMaxTotalArea)
{
  const char *v6; // eax
  int v8; // edi
  float v9; // xmm0_4
  float *p_m_flScreenArea; // esi
  int v11; // eax
  CNewParticleEffect *v12; // ecx
  CNewParticleEffect *v13; // eax
  bool bRetirementOccurred; // [esp+13h] [ebp-1h]
  const char *pReplacementDef; // [esp+1Ch] [ebp+8h]

  bRetirementOccurred = false;
  v6 = CUtlString::operator char const *(this: &pDef->m_CullReplacementName);
  pReplacementDef = v6;
  if ( (v6 == nullptr || *v6 == 0) && nCount <= 1 )
    return false;
  qsort(
    base: pInfo,
    num: nCount,
    width: 0xCu,
    comp: (int (__cdecl *)(const void *, const void *))CParticleMgr::RetireSort);
  v8 = 0;
  if ( nCount > 0 )
  {
    v9 = flScreenArea;
    p_m_flScreenArea = &pInfo->m_flScreenArea;
    do
    {
      if ( flMaxTotalArea >= v9 )
        break;
      if ( *((_BYTE *)p_m_flScreenArea + 4) != 0 )
      {
        v11 = *((_DWORD *)p_m_flScreenArea - 1);
        if ( v11 != 0 )
          v12 = (CNewParticleEffect *)(v11 - 16);
        else
          v12 = nullptr;
        v13 = CNewParticleEffect::ReplaceWith(this: v12, pParticleSystemName: pReplacementDef);
        if ( v13 != nullptr )
          ((void (__thiscall *)(CNewParticleEffect *, _DWORD))v13->Update)(
            a1: v13,
            a2: LODWORD(s_flThreadedPSystemTimeStep));
        v9 = flScreenArea - *p_m_flScreenArea;
        bRetirementOccurred = true;
        flScreenArea = v9;
      }
      ++v8;
      p_m_flScreenArea += 3;
    }
    while ( v8 < nCount );
  }
  return bRetirementOccurred;
}

//------------------------------------------------------------------------------
// Address: 0x10130B10
// Name: public: void CParticleMgr::SetRemoveAllParticleEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::SetRemoveAllParticleEffects(CParticleMgr *this)
{
  CNewParticleEffect *i; // esi

  for ( i = this->m_NewEffects.m_pHead; i != nullptr; i = i->m_pNext )
  {
    CNewParticleEffect::StopEmission(
      this: i,
      bInfiniteOnly: false,
      bRemoveAllParticles: true,
      bWakeOnStop: true,
      bPlayEndCap: false);
    *((_BYTE *)i + 944) |= 2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130B40
// Name: public: void CParticleMgr::GetDirectionalLightInfo(class CParticleLightInfo __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::GetDirectionalLightInfo(CParticleMgr *this, CParticleLightInfo *info)
{
  *info = this->m_DirectionalLight;
}

//------------------------------------------------------------------------------
// Address: 0x10130B80
// Name: public: void CParticleMgr::SetDirectionalLightInfo(class CParticleLightInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::SetDirectionalLightInfo(CParticleMgr *this, const CParticleLightInfo *info)
{
  this->m_DirectionalLight = *info;
}

//------------------------------------------------------------------------------
// Address: 0x10130BC0
// Name: void IntrusiveList::RemoveFromDList<class CNewParticleEffect>(class CNewParticleEffect __near * __near &,class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IntrusiveList::RemoveFromDList<CNewParticleEffect>(CNewParticleEffect **head, CNewParticleEffect *which)
{
  CNewParticleEffect *m_pPrev; // ecx
  CNewParticleEffect *m_pNext; // ecx
  CNewParticleEffect *v4; // ecx

  m_pPrev = which->m_pPrev;
  if ( m_pPrev != nullptr )
  {
    m_pPrev->m_pNext = which->m_pNext;
    m_pNext = which->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = which->m_pPrev;
  }
  else if ( *head == which )
  {
    v4 = which->m_pNext;
    *head = v4;
    if ( v4 != nullptr )
      v4->m_pPrev = nullptr;
  }
  which->m_pPrev = nullptr;
  which->m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10130C90
// Name: private: void CParticleEffectBinding::BBoxCalcEnd(bool,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::BBoxCalcEnd(
        CParticleEffectBinding *this,
        bool bboxSet,
        Vector *bbMin,
        Vector *bbMax)
{
  const Vector *v5; // eax
  Vector bbMaxWorld; // [esp+4h] [ebp-18h] BYREF
  Vector bbMinWorld; // [esp+10h] [ebp-Ch] BYREF

  if ( (this->m_Flags & 8) != 0 )
  {
    if ( this->m_bLocalSpaceTransformIdentity )
    {
      bbMinWorld = *bbMin;
      bbMaxWorld = *bbMax;
    }
    else
    {
      TransformAABB(
        transform: (const matrix3x4_t *)&this->m_LocalSpaceTransform,
        vecMinsIn: bbMin,
        vecMaxsIn: bbMax,
        vecMinsOut: &bbMinWorld,
        vecMaxsOut: &bbMaxWorld);
    }
    if ( bboxSet )
    {
      this->m_Min = bbMinWorld;
      this->m_Max = bbMaxWorld;
    }
    else
    {
      v5 = this->m_pSim->GetSortOrigin(this: this->m_pSim);
      this->m_Max.x = v5->x;
      this->m_Max.y = v5->y;
      this->m_Max.z = v5->z;
      this->m_Min.x = this->m_Max.x;
      this->m_Min.y = this->m_Max.y;
      this->m_Min.z = this->m_Max.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130D90
// Name: public: void CParticleEffectBinding::SetBBox(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::SetBBox(
        CParticleEffectBinding *this,
        const Vector *bbMin,
        const Vector *bbMax,
        bool bDisableAutoUpdate)
{
  this->m_Min = *bbMin;
  this->m_Max = *bbMax;
  if ( bDisableAutoUpdate )
    this->m_Flags &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x10130DD0
// Name: private: void CParticleEffectBinding::GrowBBoxFromParticlePositions(class CEffectMaterial __near *,bool __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::GrowBBoxFromParticlePositions(
        CParticleEffectBinding *this,
        CEffectMaterial *pMaterial,
        bool *bboxSet,
        Vector *bbMin,
        Vector *bbMax)
{
  Particle *i; // eax
  double x; // xmm0_8
  float v7; // xmm0_4
  double y; // xmm0_8
  float v9; // xmm0_4
  double z; // xmm0_8
  float v11; // xmm0_4
  double v12; // xmm0_8
  float v13; // xmm0_4
  double v14; // xmm0_8
  float v15; // xmm0_4
  double v16; // xmm0_8

  if ( (this->m_Flags & 8) != 0 )
  {
    for ( i = pMaterial->m_Particles.m_pNext; i != &pMaterial->m_Particles; i = i->m_pNext )
    {
      x = bbMin->x;
      if ( x > i->m_Pos.x )
        x = i->m_Pos.x;
      v7 = x;
      bbMin->x = v7;
      y = bbMin->y;
      if ( y > i->m_Pos.y )
        y = i->m_Pos.y;
      v9 = y;
      bbMin->y = v9;
      z = bbMin->z;
      if ( z > i->m_Pos.z )
        z = i->m_Pos.z;
      v11 = z;
      bbMin->z = v11;
      v12 = bbMax->x;
      if ( v12 < i->m_Pos.x )
        v12 = i->m_Pos.x;
      v13 = v12;
      bbMax->x = v13;
      v14 = bbMax->y;
      if ( v14 < i->m_Pos.y )
        v14 = i->m_Pos.y;
      v15 = v14;
      bbMax->y = v15;
      v16 = bbMax->z;
      if ( v16 < i->m_Pos.z )
        v16 = i->m_Pos.z;
      bbMax->z = v16;
      *bboxSet = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130EF0
// Name: private: int CParticleMgr::ComputeParticleDefScreenArea(int,struct CParticleMgr::RetireInfo_t __near *,float __near *,class CParticleSystemDefinition __near *,class CViewSetup const __near &,class VMatrix const __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleMgr::ComputeParticleDefScreenArea(
        CParticleMgr *this,
        int nInfoCount,
        CNewParticleEffect *pInfo,
        float *pTotalArea,
        CParticleSystemDefinition *pDef,
        const CViewSetup *view,
        const VMatrix *worldToPixels,
        float flFocalDist)
{
  CParticleSystemDefinition *v8; // eax
  CParticleCollection *m_pFirstCollection; // edi
  bool *v11; // esi
  int m_nCullControlPoint; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  int width; // eax
  float v16; // xmm6_4
  float v17; // xmm2_4
  float x; // xmm5_4
  float v19; // xmm7_4
  int v20; // ecx
  int y; // ecx
  float v22; // xmm0_4
  float v23; // xmm1_4
  int height; // eax
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  Vector vecScreenCenter; // [esp+0h] [ebp-28h] BYREF
  Vector vecCenter; // [esp+Ch] [ebp-1Ch] BYREF
  float flCullCost; // [esp+18h] [ebp-10h]
  float flCullRadius; // [esp+1Ch] [ebp-Ch]
  float flCullRadiusSqr; // [esp+20h] [ebp-8h]
  int nCollection; // [esp+24h] [ebp-4h]
  float flMaxX; // [esp+40h] [ebp+18h]

  v8 = pDef;
  flCullCost = pDef->m_flCullFillCost;
  flCullRadius = pDef->m_flCullRadius;
  flCullRadiusSqr = flCullRadius * flCullRadius;
  *pTotalArea = 0.0;
  m_pFirstCollection = pDef->m_pFirstCollection;
  nCollection = 0;
  if ( m_pFirstCollection == nullptr )
    return 0;
  v11 = (bool *)&pInfo->IClientRenderable;
  do
  {
    if ( (m_pFirstCollection[1].m_fl4CurTime.m128_i8[1] & 2) != 0 )
    {
      *((_DWORD *)v11 - 1) = 0;
      *((_DWORD *)v11 - 2) = m_pFirstCollection;
      *v11 = false;
      m_nCullControlPoint = v8->m_nCullControlPoint;
      if ( m_nCullControlPoint >= m_pFirstCollection->m_nNumControlPointsAllocated - 1 )
        m_nCullControlPoint = m_pFirstCollection->m_nNumControlPointsAllocated - 1;
      vecCenter = m_pFirstCollection->m_pCPInfo[m_nCullControlPoint].m_ControlPoint.m_Position;
      Vector3DMultiplyPositionProjective(src1: worldToPixels, src2: &vecCenter, dst: &vecScreenCenter);
      v13 = (float)((float)((float)(vecCenter.y - view->origin.y) * (float)(vecCenter.y - view->origin.y))
                  + (float)((float)(vecCenter.x - view->origin.x) * (float)(vecCenter.x - view->origin.x)))
          + (float)((float)(vecCenter.z - view->origin.z) * (float)(vecCenter.z - view->origin.z));
      if ( v13 <= flCullRadiusSqr )
        v14 = 1.0;
      else
        v14 = (float)((float)(flFocalDist * 0.5) * flCullRadius) / fsqrt(v13 - flCullRadiusSqr);
      width = view->width;
      v16 = (float)width;
      v17 = (float)width * v14;
      x = (float)view->x;
      if ( x <= (float)(vecScreenCenter.x - v17) )
        v19 = vecScreenCenter.x - v17;
      else
        v19 = (float)view->x;
      v20 = width + view->x;
      if ( (float)(vecScreenCenter.x + v17) <= (float)v20 )
        flMaxX = vecScreenCenter.x + v17;
      else
        flMaxX = (float)v20;
      y = view->y;
      v22 = (float)y;
      v23 = vecScreenCenter.y - v17;
      if ( (float)y > (float)(vecScreenCenter.y - v17) )
        v23 = (float)y;
      height = view->height;
      v25 = vecScreenCenter.y + v17;
      if ( (float)(vecScreenCenter.y + v17) > (float)(height + y) )
        v25 = (float)(height + y);
      if ( x <= v19 )
      {
        if ( v19 > v16 )
          v19 = v16;
      }
      else
      {
        v19 = (float)view->x;
      }
      v26 = flMaxX;
      if ( x <= flMaxX )
      {
        if ( flMaxX > v16 )
          v26 = v16;
      }
      else
      {
        v26 = (float)view->x;
      }
      if ( v22 <= v23 )
      {
        if ( v23 > (float)height )
          v23 = (float)height;
      }
      else
      {
        v23 = (float)y;
      }
      if ( v22 <= v25 )
      {
        v22 = (float)height;
        if ( v25 <= (float)height )
          v22 = v25;
      }
      ++nCollection;
      v27 = (float)((float)(v22 - v23) * (float)(v26 - v19)) * flCullCost;
      *pTotalArea = *pTotalArea + v27;
      *((float *)v11 - 1) = v27;
      *((_DWORD *)v11 - 2) = m_pFirstCollection;
      *v11 = (m_pFirstCollection[1].m_fl4CurTime.m128_i8[0] & 0x10) != 0;
      v8 = pDef;
      v11 += 12;
    }
    m_pFirstCollection = m_pFirstCollection->m_pNextDef;
  }
  while ( m_pFirstCollection != nullptr );
  return nCollection;
}

//------------------------------------------------------------------------------
// Address: 0x10131160
// Name: private: bool CParticleMgr::EarlyRetireParticleSystems(int,class CNewParticleEffect __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleMgr::EarlyRetireParticleSystems(
        CParticleMgr *this,
        int nCount,
        CNewParticleEffect **ppEffects)
{
  int j; // esi
  const CViewSetup *v4; // eax
  bool v5; // zf
  int v6; // esi
  int v7; // edi
  void *v8; // esp
  CParticleSystemDefinition **v9; // ebx
  CNewParticleEffect **v10; // ecx
  int v11; // esi
  int v12; // edx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  int v16; // eax
  CParticleSystemDefinition *m_pObject; // edx
  int v18; // eax
  CNewParticleEffect *v19; // esi
  CParticleSystemDefinition *v20; // edx
  int v21; // eax
  CNewParticleEffect *v22; // edx
  CParticleSystemDefinition *v23; // ecx
  int v24; // eax
  int v25; // edx
  int k; // eax
  __m128 fov_low; // xmm0
  double v28; // xmm0_8
  void *v29; // esp
  int v31; // esi
  VMatrix *v32; // ebx
  int v33; // eax
  int m; // eax
  _DWORD v35[3]; // [esp+8h] [ebp-130h] BYREF
  VMatrix dummy1; // [esp+14h] [ebp-124h] BYREF
  VMatrix dummy3; // [esp+54h] [ebp-E4h] BYREF
  VMatrix dummy2; // [esp+94h] [ebp-A4h] BYREF
  VMatrix worldToScreen[1]; // [esp+D4h] [ebp-64h] BYREF
  float flMaxScreenArea; // [esp+114h] [ebp-24h]
  CParticleSystemDefinition **ppDefs; // [esp+118h] [ebp-20h]
  float flScreenArea; // [esp+11Ch] [ebp-1Ch] BYREF
  int flFocalDist; // [esp+120h] [ebp-18h]
  CParticleMgr *v44; // [esp+124h] [ebp-14h]
  CParticleSystemDefinition *pDef; // [esp+128h] [ebp-10h]
  const CViewSetup *pViewSetup[1]; // [esp+12Ch] [ebp-Ch]
  CParticleMgr::RetireInfo_t *pInfo; // [esp+130h] [ebp-8h]
  int i; // [esp+134h] [ebp-4h]

  v44 = this;
  for ( j = 0; j == 0; ++j )
  {
    v4 = view->GetPlayerViewSetup(this: view, a2: j);
    v5 = v4->width == 0;
    pViewSetup[j] = v4;
    if ( v5 || v4->height == 0 )
      return 0;
  }
  flMaxScreenArea = cl_particle_retire_cost.m_pParent->m_Value.m_fValue * 1000.0;
  if ( flMaxScreenArea == 0.0 )
    return 0;
  v6 = nCount;
  v7 = 0;
  v8 = alloca(4 * nCount);
  v9 = (CParticleSystemDefinition **)v35;
  ppDefs = (CParticleSystemDefinition **)v35;
  i = 0;
  if ( nCount >= 4 )
  {
    v10 = ppEffects + 2;
    pInfo = (CParticleMgr::RetireInfo_t *)(((unsigned int)(nCount - 4) >> 2) + 1);
    i = 4 * (_DWORD)pInfo;
    do
    {
      v11 = (int)*(v10 - 2);
      v12 = *(_DWORD *)(v11 + 88);
      if ( *(float *)(v12 + 120) != 0.0 && (*(_BYTE *)(v11 + 944) & 0x10) != 0 )
      {
        v13 = *(_DWORD *)(gpGlobals.m_Index + 4);
        if ( *(_DWORD *)(v12 + 132) != v13 )
        {
          *(_DWORD *)(v12 + 132) = v13;
          v35[v7++] = (*(v10 - 2))->m_pDef.m_pObject;
        }
      }
      v14 = (int)*(v10 - 1);
      v15 = *(_DWORD *)(v14 + 88);
      if ( *(float *)(v15 + 120) != 0.0 && (*(_BYTE *)(v14 + 944) & 0x10) != 0 )
      {
        v16 = *(_DWORD *)(gpGlobals.m_Index + 4);
        if ( *(_DWORD *)(v15 + 132) != v16 )
        {
          *(_DWORD *)(v15 + 132) = v16;
          v35[v7++] = (*(v10 - 1))->m_pDef.m_pObject;
        }
      }
      m_pObject = (*v10)->m_pDef.m_pObject;
      if ( m_pObject->m_flCullRadius != 0.0 && (*((_BYTE *)*v10 + 944) & 0x10) != 0 )
      {
        v18 = *(_DWORD *)(gpGlobals.m_Index + 4);
        if ( m_pObject->m_nRetireCheckFrame != v18 )
        {
          m_pObject->m_nRetireCheckFrame = v18;
          v35[v7++] = (*v10)->m_pDef.m_pObject;
        }
      }
      v19 = v10[1];
      v20 = v19->m_pDef.m_pObject;
      if ( v20->m_flCullRadius != 0.0 && (*((_BYTE *)v19 + 944) & 0x10) != 0 )
      {
        v21 = *(_DWORD *)(gpGlobals.m_Index + 4);
        if ( v20->m_nRetireCheckFrame != v21 )
        {
          v20->m_nRetireCheckFrame = v21;
          v35[v7++] = v10[1]->m_pDef.m_pObject;
        }
      }
      v10 += 4;
      pInfo = (CParticleMgr::RetireInfo_t *)((char *)pInfo - 1);
    }
    while ( pInfo != nullptr );
    v6 = nCount;
  }
  for ( ; i < v6; ++i )
  {
    v22 = ppEffects[i];
    v23 = v22->m_pDef.m_pObject;
    if ( v23->m_flCullRadius != 0.0 && (*((_BYTE *)v22 + 944) & 0x10) != 0 )
    {
      v24 = *(_DWORD *)(gpGlobals.m_Index + 4);
      if ( v23->m_nRetireCheckFrame != v24 )
      {
        v25 = i;
        v23->m_nRetireCheckFrame = v24;
        v35[v7++] = ppEffects[v25]->m_pDef.m_pObject;
      }
    }
  }
  if ( v7 == 0 )
    return 0;
  for ( k = 0; k < v6; ++k )
    *((_BYTE *)ppEffects[k] + 945) |= 2u;
  render->GetMatricesForView(this: render, a2: pViewSetup[0], a3: &dummy1, a4: &dummy2, a5: &dummy3, a6: worldToScreen);
  fov_low = (__m128)LODWORD(pViewSetup[0]->fov);
  fov_low.m128_f32[0] = (float)(fov_low.m128_f32[0] * 0.5) * 0.017453292;
  __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(fov_low));
  *(float *)&v28 = v28;
  flFocalDist = LODWORD(v28);
  v29 = alloca(12 * v6);
  pInfo = (CParticleMgr::RetireInfo_t *)v35;
  i = 0;
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      pDef = v9[i];
      v31 = 0;
      v32 = worldToScreen;
      do
      {
        v33 = CParticleMgr::ComputeParticleDefScreenArea(
                this: v44,
                nInfoCount: nCount,
                (CNewParticleEffect *)pInfo,
                pTotalArea: &flScreenArea,
                pDef,
                view: pViewSetup[v31],
                worldToPixels: v32,
                flFocalDist: *((float *)&flFocalDist + v31));
        if ( flScreenArea > flMaxScreenArea
          && CParticleMgr::RetireParticleCollections(
               this: v44,
               pDef,
               nCount: v33,
               pInfo,
               flScreenArea,
               flMaxTotalArea: flMaxScreenArea) )
        {
          break;
        }
        ++v32;
        ++v31;
      }
      while ( v31 == 0 );
      if ( ++i >= v7 )
        break;
      v9 = ppDefs;
    }
    v6 = nCount;
  }
  for ( m = 0; m < v6; ++m )
    *((_BYTE *)ppEffects[m] + 945) &= ~2u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10131F60
// Name: public: virtual void CDefaultClientRenderable::GetColorModulation(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultClientRenderable::GetColorModulation(CDefaultClientRenderable *this, float *color)
{
  color[2] = 1.0;
  color[1] = 1.0;
  *color = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10131F80
// Name: public: virtual unsigned short CDefaultClientRenderable::GetShadowHandle(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDefaultClientRenderable::GetShadowHandle(CDetailModel *this)
{
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10131FA0
// Name: public: virtual unsigned char CDefaultClientRenderable::OverrideShadowAlphaModulation(unsigned char)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDefaultClientRenderable::OverrideShadowAlphaModulation(
        C_INIT_InitFromParentKilled *this,
        bool bApplyingParentKillList)
{
  return bApplyingParentKillList;
}

//------------------------------------------------------------------------------
// Address: 0x10131FC0
// Name: void UpdateRefractTexture(int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateRefractTexture(int a1@<edi>, int a2@<esi>)
{
  int v2; // esi
  ITexture *PowerOfTwoFrameBufferTexture; // edi

  if ( r_updaterefracttexture.m_pParent != nullptr && r_updaterefracttexture.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a1, a3: a2);
    if ( v2 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    PowerOfTwoFrameBufferTexture = GetPowerOfTwoFrameBufferTexture();
    (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v2 + 452))(
      a1: v2,
      a2: PowerOfTwoFrameBufferTexture,
      a3: 0);
    g_viewscene_refractUpdateFrame = *(_DWORD *)(gpGlobals.m_Index + 4);
    (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v2 + 72))(
      a1: v2,
      a2: PowerOfTwoFrameBufferTexture,
      a3: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(a1: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132070
// Name: void UpdateRefractTexture(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateRefractTexture(int a1@<edi>)
{
  IMatRenderContext *v1; // esi
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  v1 = materials->GetRenderContext(this: materials);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  v1->GetViewport(this: v1, a2: &x, a3: &y, a4: &w, a5: &h);
  UpdateRefractTexture(a1, a2: (int)v1);
  v1->EndRender(this: v1);
  v1->Release(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101320F0
// Name: void UpdateScreenEffectTexture(int,int,int,int,int,bool,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateScreenEffectTexture(
        int a1@<ebx>,
        int a2@<esi>,
        int textureIndex,
        __int64 x,
        __int64 w,
        bool bDestFullScreen,
        Rect_t *pActualRect)
{
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // edi
  ITexture *FullFrameFrameBufferTexture; // ebx
  int v10; // esi
  int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // esi
  int v18; // edx
  int v19; // eax
  Rect_t *v20; // eax
  __int64 srcRect; // [esp+4h] [ebp-20h]
  __int64 srcRect_8; // [esp+Ch] [ebp-18h]
  __int64 destRect; // [esp+14h] [ebp-10h]
  __int64 destRect_8; // [esp+1Ch] [ebp-8h]

  srcRect = x;
  srcRect_8 = w;
  v7 = materials->GetRenderContext(this: materials);
  v8 = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  FullFrameFrameBufferTexture = GetFullFrameFrameBufferTexture(textureIndex);
  ((void (__thiscall *)(IMatRenderContext *, __int64 *, char *, int, int))v8->GetRenderTargetDimensions)(
    a1: v8,
    a2: &x,
    a3: (char *)&x + 4,
    a4: a2,
    a5: a1);
  v10 = FullFrameFrameBufferTexture->GetActualWidth(this: FullFrameFrameBufferTexture);
  v11 = FullFrameFrameBufferTexture->GetActualHeight(this: FullFrameFrameBufferTexture);
  destRect = srcRect;
  destRect_8 = srcRect_8;
  if ( !bDestFullScreen && ((int)x > v10 || SHIDWORD(x) > v11) )
  {
    v12 = (float)v10 / (float)(int)x;
    v13 = (float)v11 / (float)SHIDWORD(x);
    v14 = (int)(float)((float)(int)srcRect * v12);
    HIDWORD(destRect) = (int)(float)((float)SHIDWORD(srcRect) * v13);
    LODWORD(destRect_8) = (int)(float)((float)(int)srcRect_8 * v12);
    HIDWORD(destRect_8) = (int)(float)((float)SHIDWORD(srcRect_8) * v13);
    if ( v14 >= 0 )
    {
      v15 = v10;
      if ( v14 <= v10 )
        v15 = (int)(float)((float)(int)srcRect * v12);
    }
    else
    {
      v15 = 0;
    }
    v16 = (int)(float)((float)SHIDWORD(srcRect) * v13);
    LODWORD(destRect) = v15;
    if ( destRect >= 0 )
    {
      if ( SHIDWORD(destRect) > v11 )
        v16 = v11;
    }
    else
    {
      v16 = 0;
    }
    v17 = v10 - v15;
    v18 = (int)(float)((float)(int)srcRect_8 * v12);
    HIDWORD(destRect) = v16;
    if ( (int)destRect_8 >= 0 )
    {
      if ( (int)destRect_8 > v17 )
        v18 = v17;
    }
    else
    {
      v18 = 0;
    }
    v19 = v11 - v16;
    LODWORD(destRect_8) = v18;
    if ( destRect_8 >= 0 )
    {
      if ( SHIDWORD(destRect_8) <= v19 )
        v19 = (int)(float)((float)SHIDWORD(srcRect_8) * v13);
    }
    else
    {
      v19 = 0;
    }
    HIDWORD(destRect_8) = v19;
  }
  ((void (__thiscall *)(IMatRenderContext *, ITexture *, _DWORD))v8->CopyRenderTargetToTextureEx)(
    a1: v8,
    a2: FullFrameFrameBufferTexture,
    a3: 0);
  v8->SetFrameBufferCopyTexture(this: v8, a2: FullFrameFrameBufferTexture, a3: textureIndex);
  v20 = pActualRect;
  if ( pActualRect != nullptr )
  {
    pActualRect->x = destRect;
    v20->y = HIDWORD(destRect);
    *(_QWORD *)&v20->width = destRect_8;
  }
  v8->EndRender(this: v8);
  v8->Release(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x101322C0
// Name: void UpdateScreenEffectTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateScreenEffectTexture(int a1@<ebx>, int a2@<esi>)
{
  __int64 *v2; // eax

  v2 = (__int64 *)view->GetViewSetup(this: view);
  UpdateScreenEffectTexture(a1, a2, textureIndex: 0, x: *v2, w: v2[1], bDestFullScreen: false, pActualRect: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101322F0
// Name: private: void CParticleEffectBinding::StartDrawMaterialParticles(class CEffectMaterial __near *,float,class IMesh __near * __near &,class CMeshBuilder __near &,class ParticleDraw __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::StartDrawMaterialParticles(
        CParticleEffectBinding *this,
        CEffectMaterial *pMaterial,
        float flTimeDelta,
        IMesh **pMesh,
        CMeshBuilder *builder,
        ParticleDraw *particleDraw,
        bool bWireframe)
{
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // edi
  IMaterial *v10; // eax
  IMesh *v12; // ebx

  v8 = this->m_pParticleMgr->m_pMaterialSystem->GetRenderContext(this: this->m_pParticleMgr->m_pMaterialSystem);
  v9 = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  if ( bWireframe )
  {
    v10 = this->m_pParticleMgr->m_pMaterialSystem->FindMaterial(
            this: this->m_pParticleMgr->m_pMaterialSystem,
            a2: "debug/debugparticlewireframe",
            a3: "Other textures",
            a4: 1,
            a5: 0);
    v9->Bind(this: v9, a2: v10, a3: nullptr);
  }
  else
  {
    v9->Bind(this: v9, a2: pMaterial->m_pGroup->m_pPageMaterial, a3: this->m_pParticleMgr);
  }
  v12 = v9->GetDynamicMesh(this: v9, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  *pMesh = v12;
  builder->m_pMesh = v12;
  builder->m_bGenerateIndices = true;
  builder->m_Type = MATERIAL_QUADS;
  v12->SetPrimitiveType(this: v12, a2: MATERIAL_TRIANGLES);
  builder->m_pMesh->LockMesh(this: builder->m_pMesh, a2: 3200, a3: 4800, a4: builder, a5: nullptr);
  builder->m_IndexBuilder.m_pIndexBuffer = &v12->IIndexBuffer;
  builder->m_IndexBuilder.m_nIndexCount = 0;
  builder->m_IndexBuilder.m_nMaxIndexCount = 4800;
  builder->m_IndexBuilder.m_bModify = false;
  builder->m_IndexBuilder.m_nIndexOffset = builder->m_nFirstVertex;
  builder->m_IndexBuilder.m_pIndices = builder->m_pIndices;
  builder->m_IndexBuilder.m_nIndexSize = builder->m_nIndexSize;
  builder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &builder->m_VertexBuilder, pMesh: v12, nMaxVertexCount: 3200, desc: builder);
  builder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &builder->m_VertexBuilder);
  particleDraw->m_pMaterial = pMaterial->m_pGroup->m_pPageMaterial;
  particleDraw->m_pMeshBuilder = builder;
  particleDraw->m_fTimeDelta = flTimeDelta;
  v9->EndRender(this: v9);
  v9->Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10132470
// Name: public: void CParticleEffectBinding::SimulateParticles(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::SimulateParticles(CParticleEffectBinding *this, float flTimeDelta)
{
  IParticleEffect *m_pSim; // esi
  bool v4; // cf
  bool v5; // zf
  int i; // eax
  int v7; // edi
  CEffectMaterial *m_Element; // ebx
  IParticleEffect *v9; // ecx
  CParticleSimulateIterator simulateIterator; // [esp+4h] [ebp-3Ch] BYREF
  Vector bbMin; // [esp+18h] [ebp-28h] BYREF
  int v12; // [esp+24h] [ebp-1Ch]
  int v13; // [esp+28h] [ebp-18h]
  Vector bbMax; // [esp+2Ch] [ebp-14h] BYREF
  BOOL bboxSet; // [esp+3Bh] [ebp-5h] BYREF
  bool bFullBBoxUpdate; // [esp+3Fh] [ebp-1h]

  if ( this->m_pSim->ShouldSimulate(this: this->m_pSim) )
  {
    if ( (this->m_Flags & 0x1000) != 0 )
    {
      LODWORD(bbMin.x) = this;
      m_pSim = this->m_pSim;
      v13 = 0;
      bbMin.y = 0.0;
      bbMin.z = flTimeDelta;
      m_pSim->SimulateParticles(this: m_pSim, a2: (CParticleSimulateIterator *)&bbMin);
    }
    else
    {
      v4 = ++this->m_UpdateBBoxCounter < 8u;
      bbMin.z = 0.0;
      v12 = 0;
      v13 = 0;
      memset((void *)&bbMax, 0, sizeof(bbMax));
      LOBYTE(bboxSet) = 0;
      bFullBBoxUpdate = false;
      if ( !v4 && random->RandomInt(this: random, a2: 0, a3: 8) == 0 || this->m_UpdateBBoxCounter >= 0x10u )
      {
        v5 = (this->m_Flags & 8) == 0;
        bFullBBoxUpdate = true;
        this->m_UpdateBBoxCounter = 0;
        if ( !v5 )
        {
          bbMin.z = 3.4028235e38;
          v12 = 2139095039;
          v13 = 2139095039;
          bbMax.x = -3.4028235e38;
          bbMax.y = -3.4028235e38;
          bbMax.z = -3.4028235e38;
        }
      }
      for ( i = this->m_Materials.m_Head; i != 0xFFFF; i = this->m_Materials.m_Memory.m_pMemory[v7].m_Next )
      {
        v7 = (unsigned __int16)i;
        m_Element = this->m_Materials.m_Memory.m_pMemory[v7].m_Element;
        v9 = this->m_pSim;
        simulateIterator.m_pNextParticle = nullptr;
        simulateIterator.m_pEffectBinding = this;
        simulateIterator.m_pMaterial = m_Element;
        simulateIterator.m_flTimeDelta = flTimeDelta;
        v9->SimulateParticles(this: v9, a2: &simulateIterator);
        if ( bFullBBoxUpdate )
          CParticleEffectBinding::GrowBBoxFromParticlePositions(
            this,
            pMaterial: m_Element,
            (bool *)&bboxSet,
            bbMin: (Vector *)&bbMin.z,
            &bbMax);
      }
      if ( bFullBBoxUpdate )
        CParticleEffectBinding::BBoxCalcEnd(this, bboxSet, bbMin: (Vector *)&bbMin.z, &bbMax);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132610
// Name: public: int CParticleEffectBinding::GetActiveParticleList(int,struct Particle __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleEffectBinding::GetActiveParticleList(
        CParticleEffectBinding *this,
        int nCount,
        Particle **ppParticleList)
{
  int m_Head; // edx
  int result; // eax
  int v5; // esi
  CEffectMaterial *m_Element; // edi
  Particle *m_pNext; // edx
  Particle *p_m_Particles; // edi

  m_Head = this->m_Materials.m_Head;
  result = 0;
  if ( m_Head != 0xFFFF )
  {
    while ( 1 )
    {
      v5 = (unsigned __int16)m_Head;
      m_Element = this->m_Materials.m_Memory.m_pMemory[v5].m_Element;
      m_pNext = m_Element->m_Particles.m_pNext;
      p_m_Particles = &m_Element->m_Particles;
      if ( m_pNext != p_m_Particles )
        break;
LABEL_5:
      m_Head = this->m_Materials.m_Memory.m_pMemory[v5].m_Next;
      if ( m_Head == 0xFFFF )
        return result;
    }
    while ( 1 )
    {
      ppParticleList[result++] = m_pNext;
      if ( result == nCount )
        break;
      m_pNext = m_pNext->m_pNext;
      if ( m_pNext == p_m_Particles )
        goto LABEL_5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10132680
// Name: private: int CParticleEffectBinding::DrawMaterialParticles(bool,class CEffectMaterial __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleEffectBinding::DrawMaterialParticles(
        CParticleEffectBinding *this,
        bool bBucketSort,
        CEffectMaterial *pMaterial,
        float flTimeDelta,
        bool bWireframe)
{
  const char *m_nActiveParticles; // eax
  IParticleEffect *m_pSim; // ecx
  int m_nVertexCount; // eax
  int v9; // esi
  _DWORD v11[5]; // [esp+20h] [ebp-2230h] BYREF
  bool v12; // [esp+34h] [ebp-221Ch]
  unsigned __int64 minZ; // [esp+38h] [ebp-2218h]
  float zCoords[2048]; // [esp+40h] [ebp-2210h] BYREF
  int nZCoords; // [esp+2040h] [ebp-210h]
  int v16; // [esp+2044h] [ebp-20Ch]
  char v17; // [esp+2048h] [ebp-208h]
  int v18; // [esp+204Ch] [ebp-204h]
  int v19; // [esp+2050h] [ebp-200h]
  CMeshBuilder builder; // [esp+2054h] [ebp-1FCh] BYREF
  ParticleDraw particleDraw; // [esp+223Ch] [ebp-14h] BYREF
  IMesh *pMesh; // [esp+224Ch] [ebp-4h] BYREF

  CMeshBuilder::CMeshBuilder(this: &builder);
  particleDraw.m_pMaterial = nullptr;
  pMesh = nullptr;
  CParticleEffectBinding::StartDrawMaterialParticles(
    this,
    pMaterial,
    flTimeDelta,
    &pMesh,
    &builder,
    &particleDraw,
    bWireframe);
  m_nActiveParticles = (const char *)this->m_nActiveParticles;
  if ( (unsigned __int16)m_nActiveParticles > 0x800u )
    _Error(this: (ISceneTokenProcessor *)&stru_104845F8, a2: m_nActiveParticles, 2048);
  v18 = 0;
  v11[2] = &particleDraw;
  minZ = 0xE753C21C6753C21CuLL;
  v11[3] = &builder;
  m_pSim = this->m_pSim;
  v11[4] = pMesh;
  v12 = bBucketSort;
  v16 = 0;
  v17 = 0;
  v19 = 0;
  nZCoords = 0;
  v11[0] = this;
  v11[1] = pMaterial;
  m_pSim->RenderParticles(this: m_pSim, a2: (CParticleRenderIterator *)v11);
  g_nParticlesDrawn += this->m_nActiveParticles;
  if ( bBucketSort )
    CParticleEffectBinding::DoBucketSort(
      this,
      pMaterial,
      zCoords,
      nZCoords,
      minZ: *(float *)&minZ,
      maxZ: *((float *)&minZ + 1));
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  builder.m_pMesh->UnlockMesh(
    this: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount,
    a4: &builder);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
  v9 = this->m_nActiveParticles;
  builder.m_pMesh = nullptr;
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x101328E0
// Name: private: void CParticleEffectBinding::RenderStart(class VMatrix __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleEffectBinding::RenderStart(
        CParticleEffectBinding *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        VMatrix *tempModel,
        VMatrix *tempView)
{
  CParticleMgr *m_pParticleMgr; // eax
  int v7; // eax
  int v8; // esi
  const VMatrix *v9; // eax
  VMatrix result; // [esp+4h] [ebp-40h] BYREF

  m_pParticleMgr = this->m_pParticleMgr;
  if ( SLOBYTE(this->m_Flags) >= 0 )
  {
    MatrixSetIdentity(dst: &m_pParticleMgr->m_mModelView);
  }
  else
  {
    v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))m_pParticleMgr->m_pMaterialSystem->GetRenderContext)(
           a1: m_pParticleMgr->m_pMaterialSystem,
           a2: a3,
           a3: a2);
    v8 = v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    (*(void (__thiscall **)(int, _DWORD, VMatrix *))(*(_DWORD *)v8 + 120))(a1: v8, a2: 0, a3: tempView);
    (*(void (__thiscall **)(int, int, VMatrix *))(*(_DWORD *)v8 + 120))(a1: v8, a2: 10, a3: tempModel);
    VMatrix::operator=(this: &this->m_pParticleMgr->m_mModelView, mOther: tempView);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 352))(a1: v8, a2: 1);
    (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v8 + 356))(a1: v8, a2: tempView);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 80))(a1: v8, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
  }
  if ( (this->m_Flags & 0x400) != 0 && !this->m_bLocalSpaceTransformIdentity )
  {
    v9 = VMatrix::operator*(this: &this->m_pParticleMgr->m_mModelView, &result, vm: &this->m_LocalSpaceTransform);
    VMatrix::operator=(this: &this->m_pParticleMgr->m_mModelView, mOther: v9);
  }
  this->m_pSim->StartRender(this: this->m_pSim, a2: &this->m_pParticleMgr->m_mModelView);
}

//------------------------------------------------------------------------------
// Address: 0x10132A10
// Name: private: void CParticleEffectBinding::RenderEnd(class VMatrix __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleEffectBinding::RenderEnd(
        CParticleEffectBinding *this@<ecx>,
        int a2@<esi>,
        VMatrix *tempModel,
        VMatrix *tempView)
{
  int v4; // eax
  int v5; // esi

  if ( SLOBYTE(this->m_Flags) < 0 )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))this->m_pParticleMgr->m_pMaterialSystem->GetRenderContext)(
           a1: this->m_pParticleMgr->m_pMaterialSystem,
           a2);
    v5 = v4;
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 352))(a1: v5, a2: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 10);
    (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v5 + 96))(a1: v5, a2: tempModel);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 80))(a1: v5, a2: 0);
    (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v5 + 96))(a1: v5, a2: tempView);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132AA0
// Name: private: bool CParticleEffectBinding::RecalculateBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleEffectBinding::RecalculateBoundingBox(CParticleEffectBinding *this)
{
  const Vector *v2; // eax
  int m_Head; // eax
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  UtlLinkedListElem_t<CEffectMaterial *,unsigned short> *m_pMemory; // edi
  CEffectMaterial *m_Element; // ecx
  UtlLinkedListElem_t<CEffectMaterial *,unsigned short> *v13; // edx
  Particle *m_pNext; // eax
  Particle *i; // ecx
  double x; // xmm0_8
  double y; // xmm0_8
  double z; // xmm0_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  double v21; // xmm0_8
  Vector bbMin; // [esp+4h] [ebp-18h] BYREF
  Vector bbMax; // [esp+10h] [ebp-Ch] BYREF

  if ( this->m_nActiveParticles != 0 )
  {
    m_Head = this->m_Materials.m_Head;
    v5 = 9.9999994e27;
    v6 = 9.9999994e27;
    v7 = 9.9999994e27;
    v8 = -9.9999994e27;
    v9 = -9.9999994e27;
    v10 = -9.9999994e27;
    bbMin.x = 9.9999994e27;
    bbMin.y = 9.9999994e27;
    bbMin.z = 9.9999994e27;
    bbMax.x = -9.9999994e27;
    bbMax.y = -9.9999994e27;
    bbMax.z = -9.9999994e27;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_Materials.m_Memory.m_pMemory;
      do
      {
        m_Element = m_pMemory[(unsigned __int16)m_Head].m_Element;
        v13 = &m_pMemory[(unsigned __int16)m_Head];
        m_pNext = m_Element->m_Particles.m_pNext;
        for ( i = &m_Element->m_Particles; m_pNext != i; m_pNext = m_pNext->m_pNext )
        {
          x = v5;
          if ( v5 > (double)m_pNext->m_Pos.x )
            x = m_pNext->m_Pos.x;
          v5 = x;
          bbMin.x = v5;
          y = v6;
          if ( v6 > (double)m_pNext->m_Pos.y )
            y = m_pNext->m_Pos.y;
          v6 = y;
          bbMin.y = v6;
          z = v7;
          if ( v7 > (double)m_pNext->m_Pos.z )
            z = m_pNext->m_Pos.z;
          v7 = z;
          bbMin.z = v7;
          v19 = v8;
          if ( v8 < (double)m_pNext->m_Pos.x )
            v19 = m_pNext->m_Pos.x;
          v8 = v19;
          bbMax.x = v8;
          v20 = v9;
          if ( v9 < (double)m_pNext->m_Pos.y )
            v20 = m_pNext->m_Pos.y;
          v9 = v20;
          bbMax.y = v9;
          v21 = v10;
          if ( v10 < (double)m_pNext->m_Pos.z )
            v21 = m_pNext->m_Pos.z;
          v10 = v21;
          bbMax.z = v10;
        }
        m_Head = v13->m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    if ( this->m_bLocalSpaceTransformIdentity )
    {
      this->m_Min.x = v5;
      this->m_Min.y = v6;
      this->m_Min.z = v7;
      this->m_Max.x = v8;
      this->m_Max.y = v9;
      this->m_Max.z = v10;
    }
    else
    {
      TransformAABB(
        transform: (const matrix3x4_t *)&this->m_LocalSpaceTransform,
        vecMinsIn: &bbMin,
        vecMaxsIn: &bbMax,
        vecMinsOut: &this->m_Min,
        vecMaxsOut: &this->m_Max);
    }
    return 1;
  }
  else
  {
    v2 = this->m_pSim->GetSortOrigin(this: this->m_pSim);
    this->m_Min.x = v2->x;
    this->m_Min.y = v2->y;
    this->m_Min.z = v2->z;
    this->m_Max.x = this->m_Min.x;
    this->m_Max.y = this->m_Min.y;
    this->m_Max.z = this->m_Min.z;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132CB0
// Name: public: void CParticleMgr::AddEffect(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleMgr::AddEffect(
        CParticleMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CNewParticleEffect *pEffect)
{
  CNewParticleEffect *m_pHead; // eax
  CParticleSystemDefinition *m_pObject; // eax
  int v7; // eax
  IClientRenderable *v8; // edi
  IClientLeafSystem *v9; // ebx
  unsigned __int16 *v10; // eax
  unsigned int m_Index; // esi
  C_BaseEntity *m_pEntity; // eax
  IClientLeafSystem *v13; // esi
  IClientLeafSystem_vtbl *v14; // ebx
  unsigned __int16 *v15; // eax
  CNewParticleEffect *pEffecta; // [esp+Ch] [ebp+8h]

  pEffect->m_pNext = this->m_NewEffects.m_pHead;
  m_pHead = this->m_NewEffects.m_pHead;
  if ( m_pHead != nullptr )
    m_pHead->m_pPrev = pEffect;
  pEffect->m_pPrev = nullptr;
  this->m_NewEffects.m_pHead = pEffect;
  m_pObject = pEffect->m_pDef.m_pObject;
  if ( m_pObject != nullptr && m_pObject->m_bDrawThroughLeafSystem )
  {
    if ( CParticleCollection::IsTranslucent(this: &pEffect->CParticleCollection) )
      v7 = CParticleCollection::IsTwoPass(this: &pEffect->CParticleCollection) + 1;
    else
      v7 = 0;
    v8 = &pEffect->IClientRenderable;
    ((void (__stdcall *)(IClientRenderable *, bool, int, _DWORD, int, int, int))g_pClientLeafSystem->CreateRenderableHandle)(
      a1: &pEffect->IClientRenderable,
      a2: pEffect->m_pDef.m_pObject->m_bViewModelEffect,
      a3: v7,
      a4: 0,
      a5: -1,
      a6: a3,
      a7: a2);
    v9 = g_pClientLeafSystem;
    pEffecta = (CNewParticleEffect *)g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v10 = pEffect->RenderHandle(this: &pEffect->IClientRenderable);
    ((void (__thiscall *)(IClientLeafSystem *, _DWORD, int))pEffecta->CParticleCollection::m_pNext)(
      a1: v9,
      a2: *v10,
      a3: 1);
    m_Index = pEffect->m_hOwner.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
    {
      LOBYTE(pEffecta) = C_BaseEntity::IsRenderingInFastReflections(this: m_pEntity);
    }
    else
    {
      LOBYTE(pEffecta) = 0;
    }
    v13 = g_pClientLeafSystem;
    v14 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v15 = v8->RenderHandle(this: v8);
    v14->RenderInFastReflections(this: v13, a2: *v15, a3: (bool)pEffecta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132DC0
// Name: public: void CParticleMgr::RemoveEffect(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::RemoveEffect(CParticleMgr *this, CNewParticleEffect *pEffect)
{
  ((void (__stdcall *)(_DWORD))g_pClientLeafSystem->RemoveRenderable)(a1: pEffect->m_hRenderHandle);
  IntrusiveList::RemoveFromDList<CNewParticleEffect>(head: &this->m_NewEffects.m_pHead, which: pEffect);
  pEffect->NotifyRemove(this: pEffect);
}

//------------------------------------------------------------------------------
// Address: 0x10132E00
// Name: public: void CParticleMgr::RemoveAllNewEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::RemoveAllNewEffects(CParticleMgr *this)
{
  CNewParticleEffect *m_pHead; // esi
  CNewParticleEffect *m_pNext; // ebx
  C_BaseEntity *i; // eax
  CNewParticleEffect *m_pPrev; // eax
  CNewParticleEffect *v5; // eax
  CNewParticleEffect *v6; // eax
  void (__thiscall *NotifyRemove)(struct CNewParticleEffect *); // edx
  C_BaseEntityIterator iterator; // [esp+Ch] [ebp-4h] BYREF

  m_pHead = this->m_NewEffects.m_pHead;
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      C_BaseEntityIterator::C_BaseEntityIterator(this: &iterator);
      for ( i = C_BaseEntityIterator::Next(this: &iterator); i != nullptr; i = C_BaseEntityIterator::Next(this: &iterator) )
      {
        if ( i != (C_BaseEntity *)-872 )
          CParticleProperty::OnParticleSystemDeleted(this: &i->m_Particles, pEffect: m_pHead);
      }
      ((void (__stdcall *)(_DWORD))g_pClientLeafSystem->RemoveRenderable)(a1: m_pHead->m_hRenderHandle);
      m_pPrev = m_pHead->m_pPrev;
      if ( m_pPrev != nullptr )
      {
        m_pPrev->m_pNext = m_pHead->m_pNext;
        v5 = m_pHead->m_pNext;
        if ( v5 != nullptr )
          v5->m_pPrev = m_pHead->m_pPrev;
      }
      else if ( this->m_NewEffects.m_pHead == m_pHead )
      {
        v6 = m_pHead->m_pNext;
        this->m_NewEffects.m_pHead = v6;
        if ( v6 != nullptr )
          v6->m_pPrev = nullptr;
      }
      NotifyRemove = m_pHead->NotifyRemove;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pNext = nullptr;
      NotifyRemove(this: m_pHead);
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132EE0
// Name: public: void CParticleMgr::IncrementFrameCode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::IncrementFrameCode(CParticleMgr *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *m_pMemory; // edx
  int v4; // eax

  if ( this->m_FrameCode++ == 0xFFFF )
  {
    m_Head = this->m_Effects.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_Effects.m_Memory.m_pMemory;
      do
      {
        v4 = (unsigned __int16)m_Head;
        m_pMemory[v4].m_Element->m_FrameCode = 0;
        m_pMemory = this->m_Effects.m_Memory.m_pMemory;
        m_Head = m_pMemory[v4].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_FrameCode = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132F30
// Name: public: void CParticleMgr::PostRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::PostRender(CParticleMgr *this)
{
  int i; // eax
  int v2; // esi
  CParticleEffectBinding *m_Element; // eax
  int m_Flags; // edx
  unsigned int v5; // edx

  for ( i = this->m_Effects.m_Head; i != 0xFFFF; i = this->m_Effects.m_Memory.m_pMemory[v2].m_Next )
  {
    v2 = (unsigned __int16)i;
    m_Element = this->m_Effects.m_Memory.m_pMemory[v2].m_Element;
    m_Flags = m_Element->m_Flags;
    if ( (m_Flags & 0x20) != 0 )
      v5 = m_Flags | 0x40;
    else
      v5 = m_Flags & 0xFFFFFFBF;
    m_Element->m_Flags = v5;
    m_Element->m_Flags &= ~0x800u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132F90
// Name: public: class CNonDrawingParticleSystem __near * CParticleMgr::CreateNonDrawingEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNonDrawingParticleSystem *__thiscall CParticleMgr::CreateNonDrawingEffect(CParticleMgr *this, const char *pEffectName)
{
  CNonDrawingParticleSystem *v3; // esi
  CNonDrawingParticleSystem *m_pHead; // eax

  v3 = (CNonDrawingParticleSystem *)MemAlloc_Alloc(nSize: 0xCu);
  v3->m_pSystem = CParticleSystemMgr::CreateParticleCollection(
                    this: g_pParticleSystemMgr,
                    pParticleSystemName: pEffectName,
                    flDelay: 0.0,
                    nRandomSeed: 0);
  v3->m_pNext = this->m_NonDrawingParticleSystems.m_pHead;
  m_pHead = this->m_NonDrawingParticleSystems.m_pHead;
  if ( m_pHead != nullptr )
    m_pHead->m_pPrev = v3;
  v3->m_pPrev = nullptr;
  this->m_NonDrawingParticleSystems.m_pHead = v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10132FF0
// Name: public: void CParticleMgr::SpewInfo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::SpewInfo(CParticleMgr *this, bool bDetail)
{
  int m_Head; // edi
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *m_pMemory; // eax
  unsigned int v5; // esi
  const char *v6; // eax
  CParticleEffectBinding *m_Element; // ecx
  const char *v8; // edx

  DevMsg(a1: "Particle Effect Systems:\n");
  m_Head = this->m_Effects.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_Effects.m_Memory.m_pMemory;
    do
    {
      v5 = (unsigned __int16)m_Head;
      v6 = m_pMemory[v5].m_Element->m_pSim->GetEffectName(this: m_pMemory[v5].m_Element->m_pSim);
      m_Element = this->m_Effects.m_Memory.m_pMemory[v5].m_Element;
      v8 = "on";
      if ( (m_Element->m_Flags & 8) == 0 )
        v8 = "off";
      DevMsg(a1: "%3d: NumActive: %3d, AutoBBox: %3s \"%s\" \n", m_Head, m_Element->m_nActiveParticles, v8, v6);
      m_pMemory = this->m_Effects.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101336A0
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<class CNewParticleEffect __near *,class CFuncJobItemProcessor<class CNewParticleEffect __near *>,1> __near *,void (CParallelProcessor<class CNewParticleEffect __near *,class CFuncJobItemProcessor<class CNewParticleEffect __near *>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1> *,void (__thiscall CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *,void (__thiscall CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x101342A0
// Name: public: CParticleEffectBinding::CParticleEffectBinding(void)
// Source: json
//------------------------------------------------------------------------------
CParticleEffectBinding *__thiscall CParticleEffectBinding::CParticleEffectBinding(CParticleEffectBinding *this)
{
  UtlLinkedListElem_t<CEffectMaterial *,unsigned short> *m_pMemory; // ecx
  int m_hRenderHandle; // eax

  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&IClientRenderable::`vftable';
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CParticleEffectBinding_vtbl *)&CParticleEffectBinding::`vftable'{for `IClientUnknown'};
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CParticleEffectBinding::`vftable'{for `IClientRenderable'};
  this->m_hRenderHandle = -1;
  this->m_Materials.m_Memory.m_pMemory = nullptr;
  this->m_Materials.m_Memory.m_nAllocationCount = 0;
  this->m_Materials.m_Memory.m_nGrowSize = 0;
  this->m_Materials.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Materials.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_Materials.m_Memory.m_pMemory;
  this->m_Materials.m_NumAlloced = 0;
  *(_DWORD *)&this->m_Materials.m_Head = -1;
  this->m_Materials.m_pElements = m_pMemory;
  this->m_pParticleMgr = nullptr;
  this->m_pSim = nullptr;
  MatrixSetIdentity(dst: &this->m_LocalSpaceTransform);
  this->m_bLocalSpaceTransformIdentity = true;
  this->m_Flags = 3484;
  this->m_Min.x = -50.0;
  this->m_Min.y = -50.0;
  this->m_Min.z = -50.0;
  this->m_Max.x = 50.0;
  this->m_Max.y = 50.0;
  this->m_Max.z = 50.0;
  this->m_LastMin = this->m_Min;
  this->m_LastMax = this->m_Max;
  if ( this->m_flParticleCullRadius != 0.0 )
  {
    m_hRenderHandle = this->m_hRenderHandle;
    this->m_flParticleCullRadius = 0.0;
    if ( (_WORD)m_hRenderHandle != 0xFFFF )
      g_pClientLeafSystem->RenderableChanged(this: g_pClientLeafSystem, a2: m_hRenderHandle);
  }
  *(_DWORD *)&this->m_nActiveParticles = 0;
  this->m_UpdateBBoxCounter = 0;
  this->m_ListIndex = -1;
  *(_QWORD *)this->m_EffectMaterialHash = 0;
  *(_QWORD *)&this->m_EffectMaterialHash[2] = 0;
  *(_QWORD *)&this->m_EffectMaterialHash[4] = 0;
  *(_QWORD *)&this->m_EffectMaterialHash[6] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10134400
// Name: public: virtual int CParticleEffectBinding::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CParticleEffectBinding::DrawModel@<eax>(
        CParticleEffectBinding *this@<ecx>,
        int a2@<ebx>,
        int flags,
        const RenderableInstance_t *instance)
{
  IClientMode *ClientMode; // eax
  CParticleEffectBinding *v7; // edi
  int v8; // eax
  IParticleEffect *m_pSim; // ecx
  __int16 v10; // ax
  int m_nGrowSize_low; // eax
  unsigned int v12; // edi
  CEffectMaterial *v13; // ebx
  int v14; // eax
  CEffectMaterial *v15; // ecx
  int v16; // edi
  bool v17; // zf
  float y; // xmm7_4
  float z; // xmm4_4
  float v20; // xmm3_4
  float x; // xmm6_4
  float v22; // xmm5_4
  int v23; // ebx
  IVDebugOverlay_vtbl *v24; // edi
  int v25; // eax
  VMatrix mTempModel; // [esp+74h] [ebp-B8h] BYREF
  VMatrix mTempView; // [esp+B4h] [ebp-78h] BYREF
  Vector maxs; // [esp+F4h] [ebp-38h] BYREF
  Vector mins; // [esp+100h] [ebp-2Ch] BYREF
  _DWORD v30[3]; // [esp+10Ch] [ebp-20h] BYREF
  Vector center; // [esp+118h] [ebp-14h] BYREF
  BOOL bBucketSort; // [esp+124h] [ebp-8h]
  int g; // [esp+128h] [ebp-4h]
  CParticleEffectBinding *flagsa; // [esp+134h] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CParticleEffectBinding::DrawModel",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  if ( r_DrawParticles.m_pParent != nullptr
    && r_DrawParticles.m_pParent->m_Value.m_nValue != 0
    && (ClientMode = GetClientMode(), ClientMode->ShouldDrawParticles(this: ClientMode))
    && (flags & 0x40000000) == 0 )
  {
    this->m_pParticleMgr = (CParticleMgr *)((int)this->m_pParticleMgr | 0x20);
    v7 = (CParticleEffectBinding *)((char *)this - 4);
    flagsa = (CParticleEffectBinding *)((char *)this - 4);
    if ( LOWORD(this->m_flParticleCullRadius) != 0 )
    {
      CParticleEffectBinding::RenderStart(
        this: (CParticleEffectBinding *)((char *)this - 4),
        a2,
        a3: (int)this,
        tempModel: &mTempModel,
        tempView: &mTempView);
      v8 = random->RandomInt(this: random, a2: 0, a3: 8);
      m_pSim = this->m_pSim;
      LOBYTE(bBucketSort) = v8 == 0;
      v10 = (__int16)m_pSim[9].__vftable;
      *(float *)&g = 0.0;
      if ( HIWORD(this->m_flParticleCullRadius) != v10 )
      {
        HIWORD(this->m_flParticleCullRadius) = v10;
        g = *(int *)(gpGlobals.m_Index + 16);
      }
      m_nGrowSize_low = LOWORD(this->m_Materials.m_Memory.m_nGrowSize);
      if ( m_nGrowSize_low != 0xFFFF )
      {
        do
        {
          v12 = 8 * (unsigned __int16)m_nGrowSize_low;
          v13 = (CEffectMaterial *)(&this->m_EffectMaterialHash[7]->m_pGroup)[v12 / 4];
          if ( v13->m_pGroup->m_pPageMaterial != nullptr
            && v13->m_pGroup->m_pPageMaterial->NeedsPowerOfTwoFrameBufferTexture(
                 this: v13->m_pGroup->m_pPageMaterial,
                 a2: true) )
          {
            UpdateRefractTexture(a1: v12);
          }
          if ( v13->m_pGroup->m_pPageMaterial != nullptr
            && v13->m_pGroup->m_pPageMaterial->NeedsFullFrameBufferTexture(
                 this: v13->m_pGroup->m_pPageMaterial,
                 a2: true) )
          {
            UpdateScreenEffectTexture(a1: (int)v13, a2: (int)this);
          }
          CParticleEffectBinding::DrawMaterialParticles(
            this: flagsa,
            bBucketSort,
            pMaterial: v13,
            flTimeDelta: *(float *)&g,
            bWireframe: false);
          m_nGrowSize_low = *(unsigned __int16 *)((char *)&this->m_EffectMaterialHash[7]->m_Particles.m_pPrev + v12 + 2);
        }
        while ( m_nGrowSize_low != 0xFFFF );
        v7 = (CParticleEffectBinding *)((char *)this - 4);
      }
      if ( ShouldDrawInWireFrameMode() )
      {
        v14 = LOWORD(this->m_Materials.m_Memory.m_nGrowSize);
        if ( v14 != 0xFFFF )
        {
          v15 = this->m_EffectMaterialHash[7];
          do
          {
            v16 = 2 * (unsigned __int16)v14;
            CParticleEffectBinding::DrawMaterialParticles(
              this: flagsa,
              bBucketSort,
              pMaterial: (CEffectMaterial *)(&v15->m_pGroup)[v16],
              flTimeDelta: *(float *)&g,
              bWireframe: true);
            v15 = this->m_EffectMaterialHash[7];
            v14 = *(unsigned __int16 *)((char *)&v15->m_Particles.m_pPrev + v16 * 4 + 2);
          }
          while ( v14 != 0xFFFF );
          v7 = (CParticleEffectBinding *)((char *)this - 4);
        }
      }
      if ( cl_particles_show_bbox.m_pParent != nullptr && cl_particles_show_bbox.m_pParent->m_Value.m_nValue != 0 )
      {
        v17 = ((int)this->m_pParticleMgr & 8) == 0;
        y = this->m_Min.y;
        z = this->m_Min.z;
        v20 = *(float *)&this->m_bLocalSpaceTransformIdentity;
        x = this->m_Max.x;
        v22 = this->m_Min.x;
        g = SLODWORD(this->m_Max.y);
        bBucketSort = LODWORD(y);
        center.x = (float)(z + v20) * 0.5;
        mins.x = v20 - center.x;
        center.y = (float)(x + v22) * 0.5;
        center.z = (float)(*(float *)&g + y) * 0.5;
        mins.y = v22 - center.y;
        mins.z = y - center.z;
        maxs.x = z - center.x;
        maxs.y = x - center.y;
        maxs.z = *(float *)&g - center.z;
        if ( v17 )
        {
          v23 = 0;
          g = 255;
        }
        else
        {
          v23 = 255;
          *(float *)&g = 0.0;
        }
        memset(v30, 0, sizeof(v30));
        ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, _DWORD *, int, int, _DWORD, int, _DWORD))debugoverlay->AddBoxOverlay)(
          a1: debugoverlay,
          a2: &center,
          a3: &mins,
          a4: &maxs,
          a5: v30,
          a6: v23,
          a7: g,
          a8: 0,
          a9: 16,
          a10: 0);
        v24 = debugoverlay->__vftable;
        v25 = (*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)&this->m_ListIndex + 44))(
                a1: *(_DWORD *)&this->m_ListIndex,
                a2: LOWORD(this->m_flParticleCullRadius));
        ((void (__cdecl *)(IVDebugOverlay *, Vector *, _DWORD, _DWORD, int, int, _DWORD, int, const char *, int))v24->AddTextOverlayRGB)(
          a1: debugoverlay,
          a2: &center,
          a3: 0,
          a4: 0,
          a5: v23,
          a6: g,
          a7: 0,
          a8: 64,
          a9: "%s:(%d)",
          a10: v25);
        v7 = (CParticleEffectBinding *)((char *)this - 4);
      }
      CParticleEffectBinding::RenderEnd(this: v7, a2: (int)this, tempModel: &mTempModel, tempView: &mTempView);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 1;
    }
    else
    {
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 1;
    }
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134770
// Name: private: void CParticleEffectBinding::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::Term(CParticleEffectBinding *this)
{
  int i; // eax
  int v3; // ebx
  CEffectMaterial *v4; // eax
  Particle *m_pNext; // esi
  Particle *v6; // ebx
  UtlLinkedListElem_t<CEffectMaterial *,unsigned short> *m_pMemory; // ecx
  int v8; // [esp+4h] [ebp-8h]
  CEffectMaterial *pMaterial; // [esp+8h] [ebp-4h]

  if ( this->m_pParticleMgr != nullptr )
  {
    for ( i = this->m_Materials.m_Head;
          i != 0xFFFF;
          i = *(unsigned __int16 *)((char *)&this->m_Materials.m_Memory.m_pMemory->m_Next + v3) )
    {
      v3 = 8 * (unsigned __int16)i;
      v4 = *(CEffectMaterial **)((char *)&this->m_Materials.m_Memory.m_pMemory->m_Element + v3);
      m_pNext = v4->m_Particles.m_pNext;
      v8 = v3;
      pMaterial = v4;
      if ( m_pNext != &v4->m_Particles )
      {
        do
        {
          v6 = m_pNext->m_pNext;
          m_pNext->m_pPrev->m_pNext = v6;
          m_pNext->m_pNext->m_pPrev = m_pNext->m_pPrev;
          --this->m_nActiveParticles;
          this->m_pSim->NotifyDestroyParticle(this: this->m_pSim, a2: m_pNext);
          --this->m_pParticleMgr->m_nCurrentParticlesAllocated;
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
          m_pNext = v6;
        }
        while ( v6 != &pMaterial->m_Particles );
        v3 = v8;
        v4 = pMaterial;
      }
      C_BaseEntity::operator delete(pMem: v4);
    }
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_Materials);
    if ( this->m_Materials.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_Materials.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Materials.m_Memory.m_pMemory);
        this->m_Materials.m_Memory.m_pMemory = nullptr;
      }
      this->m_Materials.m_Memory.m_nAllocationCount = 0;
    }
    this->m_Materials.m_FirstFree = -1;
    m_pMemory = this->m_Materials.m_Memory.m_pMemory;
    *(_DWORD *)&this->m_Materials.m_NumAlloced = -65536;
    this->m_Materials.m_pElements = m_pMemory;
    *(_QWORD *)this->m_EffectMaterialHash = 0;
    *(_QWORD *)&this->m_EffectMaterialHash[2] = 0;
    *(_QWORD *)&this->m_EffectMaterialHash[4] = 0;
    *(_QWORD *)&this->m_EffectMaterialHash[6] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134AA0
// Name: private: void CParticleMgr::BuildParticleSimList(class CUtlVector<class CNewParticleEffect __near *,class CUtlMemory<class CNewParticleEffect __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::BuildParticleSimList(
        CParticleMgr *this,
        CUtlVector<CNewParticleEffect *,CUtlMemory<CNewParticleEffect *,int> > *list)
{
  CNewParticleEffect *i; // ebx
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *v11; // ecx
  IClientLeafSystem_vtbl *v12; // esi
  int v13; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CNewParticleEffect **m_pMemory; // ecx
  int v17; // eax
  CNewParticleEffect **v18; // eax
  float flNow; // [esp+8h] [ebp-4h]

  flNow = CParticleSystemMgr::GetLastSimulationTime(this: g_pParticleSystemMgr);
  for ( i = this->m_NewEffects.m_pHead; i != nullptr; i = i->m_pNext )
  {
    if ( flNow < i->m_flNextSleepTime )
      goto LABEL_11;
    if ( i->m_nActiveParticles <= 0 )
      goto LABEL_11;
    m_Index = i->m_hOwner.m_Index;
    if ( m_Index == -1 )
      goto LABEL_11;
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber != v7 || v6->m_pEntity == nullptr )
      goto LABEL_11;
    v8 = v5;
    v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
    v10 = &g_pEntityList->m_EntPtrArray[v8];
    v11 = v9 ? v10->m_pEntity : nullptr;
    v12 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v13 = (int)v11->__vftable[1].GetRefEHandle(this: v11);
    if ( v12->IsRenderableInPVS(this: g_pClientLeafSystem, a2: (IClientRenderable *)v13) )
    {
LABEL_11:
      if ( (*((_BYTE *)i + 944) & 2) == 0 )
      {
        if ( g_bMeasureParticlePerformance )
          g_nNumParticlesSimulated += i->m_nActiveParticles;
        m_Size = list->m_Size;
        m_nAllocationCount = list->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)list,
            num: m_Size - m_nAllocationCount + 1);
        ++list->m_Size;
        m_pMemory = list->m_Memory.m_pMemory;
        v17 = list->m_Size - m_Size - 1;
        list->m_pElements = list->m_Memory.m_pMemory;
        if ( v17 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
        v18 = &list->m_Memory.m_pMemory[m_Size];
        if ( v18 != nullptr )
          *v18 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134BC0
// Name: private: class CParticleSubTextureGroup __near * CParticleMgr::FindOrAddSubTextureGroup(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSubTextureGroup *__thiscall CParticleMgr::FindOrAddSubTextureGroup(
        CParticleMgr *this,
        IMaterial *pPageMaterial)
{
  int m_Size; // ecx
  int v4; // eax
  CParticleSubTextureGroup **v5; // edx
  CParticleSubTextureGroup *v6; // eax
  CParticleSubTextureGroup *v7; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CParticleSubTextureGroup **m_pMemory; // ecx
  int v12; // eax
  CParticleSubTextureGroup **v13; // eax

  m_Size = this->m_SubTextureGroups.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v6 = (CParticleSubTextureGroup *)MemAlloc_Alloc(nSize: 4u);
    if ( v6 != nullptr )
    {
      v6->m_pPageMaterial = nullptr;
      v7 = v6;
    }
    else
    {
      v7 = nullptr;
    }
    v9 = this->m_SubTextureGroups.m_Size;
    m_nAllocationCount = this->m_SubTextureGroups.m_Memory.m_nAllocationCount;
    if ( v9 + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SubTextureGroups,
        num: v9 - m_nAllocationCount + 1);
    ++this->m_SubTextureGroups.m_Size;
    m_pMemory = this->m_SubTextureGroups.m_Memory.m_pMemory;
    v12 = this->m_SubTextureGroups.m_Size - v9 - 1;
    this->m_SubTextureGroups.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * v12);
    v13 = &this->m_SubTextureGroups.m_Memory.m_pMemory[v9];
    if ( v13 != nullptr )
      *v13 = v7;
    v7->m_pPageMaterial = pPageMaterial;
    pPageMaterial->IncrementReferenceCount(this: pPageMaterial);
    return v7;
  }
  else
  {
    v5 = this->m_SubTextureGroups.m_Memory.m_pMemory;
    while ( (*v5)->m_pPageMaterial != pPageMaterial )
    {
      ++v4;
      ++v5;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    return this->m_SubTextureGroups.m_Memory.m_pMemory[v4];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134D80
// Name: public: void CParticleMgr::Term(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::Term(CParticleMgr *this, bool bCanReferenceOtherStaticObjects)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *m_pMemory; // ecx
  int m_Next; // edi
  IParticleEffect *m_pSim; // ecx
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *v7; // ecx
  CNewParticleEffect *m_pHead; // ecx
  CNewParticleEffect *m_pNext; // edi
  int i; // edi
  IMaterial *m_pMaterial; // ecx
  int j; // edi
  IMaterial *m_pPageMaterial; // ecx
  IMaterialSystem *m_pMaterialSystem; // ecx
  IThreadPool *v15; // ecx
  IThreadPool *v16; // ecx

  m_Head = this->m_Effects.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_pMemory = this->m_Effects.m_Memory.m_pMemory;
      m_Next = m_pMemory[(unsigned __int16)m_Head].m_Next;
      m_pSim = m_pMemory[(unsigned __int16)m_Head].m_Element->m_pSim;
      m_pSim->NotifyRemove(this: m_pSim);
      LOWORD(m_Head) = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_Effects);
  if ( this->m_Effects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Effects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Effects.m_Memory.m_pMemory);
      this->m_Effects.m_Memory.m_pMemory = nullptr;
    }
    this->m_Effects.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Effects.m_FirstFree = -1;
  v7 = this->m_Effects.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Effects.m_NumAlloced = -65536;
  this->m_Effects.m_pElements = v7;
  if ( this->m_NewEffects.m_pHead != nullptr )
  {
    do
    {
      m_pHead = this->m_NewEffects.m_pHead;
      m_pNext = m_pHead->m_pNext;
      if ( m_pHead != nullptr )
        ((void (__thiscall *)(CNewParticleEffect *, int))m_pHead->dtr_IParticleEffect)(a1: m_pHead, a2: 1);
      this->m_NewEffects.m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_SubTextures.m_Elements.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_SubTextures.m_Elements.m_Tree,
                                i) )
  {
    m_pMaterial = this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem->m_pMaterial;
    if ( m_pMaterial != nullptr )
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
  }
  CUtlDict<CParticleSubTexture *,unsigned short>::PurgeAndDeleteElements(this: &this->m_SubTextures);
  for ( j = this->m_SubTextureGroups.m_Size - 1; j >= 0; --j )
  {
    m_pPageMaterial = this->m_SubTextureGroups.m_Memory.m_pMemory[j]->m_pPageMaterial;
    if ( m_pPageMaterial != nullptr )
      m_pPageMaterial->DecrementReferenceCount(this: m_pPageMaterial);
  }
  CUtlVector<CParticleSubTextureGroup *,CUtlMemory<CParticleSubTextureGroup *,int>>::PurgeAndDeleteElements(this: &this->m_SubTextureGroups);
  if ( bCanReferenceOtherStaticObjects )
    CParticleSystemMgr::UncacheAllParticleSystems(this: g_pParticleSystemMgr);
  m_pMaterialSystem = this->m_pMaterialSystem;
  if ( m_pMaterialSystem != nullptr )
    m_pMaterialSystem->UncacheUnusedMaterials(this: m_pMaterialSystem, a2: false);
  v15 = this->m_pThreadPool[0];
  this->m_pMaterialSystem = nullptr;
  if ( v15 != nullptr )
  {
    v15->Stop(this: v15, a2: -1);
    _DestroyThreadPool(a1: this->m_pThreadPool[0]);
    this->m_pThreadPool[0] = nullptr;
  }
  v16 = this->m_pThreadPool[1];
  if ( v16 != nullptr )
  {
    v16->Stop(this: v16, a2: -1);
    _DestroyThreadPool(a1: this->m_pThreadPool[1]);
    this->m_pThreadPool[1] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134F40
// Name: public: void CParticleMgr::RemoveEffect(class CParticleEffectBinding __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::RemoveEffect(CParticleMgr *this, CParticleEffectBinding *pEffect)
{
  int m_Flags; // eax
  int m_Size; // ebx
  int v4; // esi
  IClientParticleListener *v5; // ecx
  IParticleEffect *m_pSim; // ecx
  int m_ListIndex; // ebx
  CParticleMgr *v8; // [esp+4h] [ebp-4h]

  m_Flags = pEffect->m_Flags;
  v8 = this;
  if ( (m_Flags & 2) == 0 )
  {
    pEffect->m_Flags = m_Flags | 2;
    m_Size = this->m_effectListeners.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        v5 = this->m_effectListeners.m_Memory.m_pMemory[v4];
        v5->OnParticleEffectRemoved(this: v5, a2: pEffect->m_pSim);
        if ( ++v4 >= m_Size )
          break;
        this = v8;
      }
    }
    ((void (__stdcall *)(_DWORD))g_pClientLeafSystem->RemoveRenderable)(a1: pEffect->m_hRenderHandle);
    m_pSim = pEffect->m_pSim;
    m_ListIndex = pEffect->m_ListIndex;
    if ( m_pSim != nullptr )
    {
      m_pSim->NotifyRemove(this: m_pSim);
      CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&v8->m_Effects,
        elem: m_ListIndex);
      v8->m_Effects.m_Memory.m_pMemory[m_ListIndex].m_Next = v8->m_Effects.m_FirstFree;
      v8->m_Effects.m_FirstFree = m_ListIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134FE0
// Name: public: void CParticleMgr::RemoveAllEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::RemoveAllEffects(CParticleMgr *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *m_pMemory; // ecx
  int m_Next; // edi
  int i; // edi
  IMaterial *m_pMaterial; // ecx
  int j; // edi
  IMaterial *m_pPageMaterial; // ecx

  m_Head = this->m_Effects.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_pMemory = this->m_Effects.m_Memory.m_pMemory;
      m_Next = m_pMemory[(unsigned __int16)m_Head].m_Next;
      CParticleMgr::RemoveEffect(this, pEffect: m_pMemory[(unsigned __int16)m_Head].m_Element);
      LOWORD(m_Head) = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CParticleMgr::RemoveAllNewEffects(this);
  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_SubTextures.m_Elements.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_SubTextures.m_Elements.m_Tree,
                                i) )
  {
    m_pMaterial = this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem->m_pMaterial;
    if ( m_pMaterial != nullptr )
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem->m_pMaterial = nullptr;
  }
  for ( j = this->m_SubTextureGroups.m_Size - 1;
        j >= 0;
        this->m_SubTextureGroups.m_Memory.m_pMemory[j + 1]->m_pPageMaterial = nullptr )
  {
    m_pPageMaterial = this->m_SubTextureGroups.m_Memory.m_pMemory[j]->m_pPageMaterial;
    if ( m_pPageMaterial != nullptr )
      m_pPageMaterial->DecrementReferenceCount(this: m_pPageMaterial);
    --j;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101350B0
// Name: public: void CParticleMgr::RepairPMaterial(class CParticleSubTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleMgr::RepairPMaterial(
        CParticleMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        CParticleSubTexture *hMaterial)
{
  const char *key; // ebx
  unsigned __int16 Inorder; // ax
  UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  IMaterial *v8; // eax
  IMaterial *v9; // esi
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // ebx
  int v12; // edi
  CParticleSubTextureGroup *m_pGroup; // eax

  if ( hMaterial->m_pMaterial == nullptr )
  {
    key = nullptr;
    Inorder = CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_SubTextures.m_Elements.m_Tree);
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory;
        if ( m_pMemory[Inorder].m_Data.elem == hMaterial )
          break;
        Inorder = CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: &this->m_SubTextures.m_Elements.m_Tree,
                    i: Inorder);
        if ( Inorder == 0xFFFF )
        {
          key = nullptr;
          goto LABEL_7;
        }
      }
      key = m_pMemory[Inorder].m_Data.key;
    }
LABEL_7:
    v8 = this->m_pMaterialSystem->FindMaterial(
           this: this->m_pMaterialSystem,
           a2: key,
           a3: "Particle textures",
           a4: 1,
           a5: 0);
    v9 = v8;
    hMaterial->m_pMaterial = v8;
    if ( v8 != nullptr )
    {
      ((void (__thiscall *)(IMaterial *, int, int))v8->IncrementReferenceCount)(a1: v8, a2: a3, a3: a2);
      v10 = this->m_pMaterialSystem->GetRenderContext(this: this->m_pMaterialSystem);
      v11 = v10;
      if ( v10 != nullptr )
        v10->BeginRender(this: v10);
      ((void (__thiscall *)(IMatRenderContext *))v11->Bind)(a1: v11);
      v12 = (int)v9->GetMaterialPage(this: v9);
      if ( v9->InMaterialPage(this: v9) && v12 != 0 )
      {
        m_pGroup = hMaterial->m_pGroup;
        if ( m_pGroup->m_pPageMaterial == nullptr )
        {
          m_pGroup->m_pPageMaterial = (IMaterial *)v12;
          (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 48))(a1: v12);
        }
      }
      else
      {
        hMaterial->m_pGroup->m_pPageMaterial = v9;
      }
      v11->EndRender(this: v11);
      v11->Release(this: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101351D0
// Name: public: class IMaterial __near * CParticleMgr::PMaterialToIMaterial(class CParticleSubTexture __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__userpurge CParticleMgr::PMaterialToIMaterial@<eax>(
        CParticleMgr *this@<ecx>,
        int a2@<ebx>,
        CParticleSubTexture *hMaterial)
{
  if ( hMaterial == nullptr )
    return nullptr;
  CParticleMgr::RepairPMaterial(this, a2, a3: (int)hMaterial, hMaterial);
  return hMaterial->m_pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x10135260
// Name: public: void CParallelProcessor<class CNewParticleEffect __near *,class CFuncJobItemProcessor<class CNewParticleEffect __near *>,1>::Run(class CNewParticleEffect __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1>::Run(
        CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1> *this,
        CNewParticleEffect **pItems,
        int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  IThreadPool *v7; // esi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  void *v11; // esp
  CFunctor *v12; // eax
  CFunctor v13; // xmm0_8
  CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *v14; // ecx
  int i; // esi
  _DWORD v16[3]; // [esp+0h] [ebp-20h]
  CFunctor v17; // [esp+Ch] [ebp-14h]
  CFunctor v18; // [esp+14h] [ebp-Ch]
  CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *v19; // [esp+1Ch] [ebp-4h]
  int nJobs; // [esp+2Ch] [ebp+Ch]

  v19 = (CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *)this;
  if ( nItems != 0 )
  {
    v7 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v7 == nullptr )
      v7 = _g_pThreadPool;
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v8 = nMaxParallel;
    v9 = nItems - 1;
    this->m_pLimit = &pItems[nItems];
    nJobs = v9;
    if ( v9 > v8 )
    {
      nJobs = v8;
      v9 = v8;
    }
    if ( v7 == nullptr )
      goto LABEL_18;
    v10 = v7->NumThreads(this: v7);
    if ( v9 > v10 )
    {
      nJobs = v10;
      v9 = v10;
    }
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      v17.__vftable = (CFunctor_vtbl *)CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute;
      v17.m_nUserID = 0;
      v18 = 0;
      do
      {
        --v9;
        v12 = (CFunctor *)MemAlloc_Alloc(nSize: 0x28u);
        if ( v12 != nullptr )
        {
          v13 = v17;
          v14 = v19;
          v12[1].m_nUserID = 1;
          v12->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1> *,void (__thiscall CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v12[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1> *,void (__thiscall CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v12[2] = v13;
          v12[3] = v18;
          v12[4].__vftable = (CFunctor_vtbl *)v14;
        }
        else
        {
          v12 = nullptr;
        }
        v7->AddFunctorInternal(this: v7, a2: v12, a3: (CJob **)&nChunkSize, a4: nullptr, a5: 8u);
        v16[v9] = nChunkSize;
      }
      while ( v9 != 0 );
      CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute(this: v19);
      for ( i = 0; i < nJobs; ++i )
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
      }
    }
    else
    {
LABEL_18:
      CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute((CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *)this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101353A0
// Name: public: void CParallelProcessor<class CParticleCollection __near *,class CFuncJobItemProcessor<class CParticleCollection __near *>,1>::Run(class CParticleCollection __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CParticleCollection *,CFuncJobItemProcessor<CParticleCollection *>,1>::Run(
        CParallelProcessor<CParticleCollection *,CFuncJobItemProcessor<CParticleCollection *>,1> *this,
        CParticleCollection **pItems,
        int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  IThreadPool *v7; // esi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  void *v11; // esp
  CFunctor *v12; // eax
  CFunctor v13; // xmm0_8
  CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *v14; // ecx
  int i; // esi
  _DWORD v16[3]; // [esp+0h] [ebp-20h]
  CFunctor v17; // [esp+Ch] [ebp-14h]
  CFunctor v18; // [esp+14h] [ebp-Ch]
  CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *v19; // [esp+1Ch] [ebp-4h]
  int nJobs; // [esp+2Ch] [ebp+Ch]

  v19 = (CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *)this;
  if ( nItems != 0 )
  {
    v7 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v7 == nullptr )
      v7 = _g_pThreadPool;
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v8 = nMaxParallel;
    v9 = nItems - 1;
    this->m_pLimit = &pItems[nItems];
    nJobs = v9;
    if ( v9 > v8 )
    {
      nJobs = v8;
      v9 = v8;
    }
    if ( v7 == nullptr )
      goto LABEL_18;
    v10 = v7->NumThreads(this: v7);
    if ( v9 > v10 )
    {
      nJobs = v10;
      v9 = v10;
    }
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      v17.__vftable = (CFunctor_vtbl *)CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute;
      v17.m_nUserID = 0;
      v18 = 0;
      do
      {
        --v9;
        v12 = (CFunctor *)MemAlloc_Alloc(nSize: 0x28u);
        if ( v12 != nullptr )
        {
          v13 = v17;
          v14 = v19;
          v12[1].m_nUserID = 1;
          v12->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CParticleCollection *,CFuncJobItemProcessor<CParticleCollection *>,1> *,void (__thiscall CParallelProcessor<CParticleCollection *,CFuncJobItemProcessor<CParticleCollection *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v12[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CParticleCollection *,CFuncJobItemProcessor<CParticleCollection *>,1> *,void (__thiscall CParallelProcessor<CParticleCollection *,CFuncJobItemProcessor<CParticleCollection *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v12[2] = v13;
          v12[3] = v18;
          v12[4].__vftable = (CFunctor_vtbl *)v14;
        }
        else
        {
          v12 = nullptr;
        }
        v7->AddFunctorInternal(this: v7, a2: v12, a3: (CJob **)&nChunkSize, a4: nullptr, a5: 8u);
        v16[v9] = nChunkSize;
      }
      while ( v9 != 0 );
      CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute(this: v19);
      for ( i = 0; i < nJobs; ++i )
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
      }
    }
    else
    {
LABEL_18:
      CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::DoExecute((CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> *)this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135550
// Name: public: virtual CParticleEffectBinding::~CParticleEffectBinding(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffectBinding::~CParticleEffectBinding(CParticleEffectBinding *this)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CParticleEffectBinding_vtbl *)&CParticleEffectBinding::`vftable'{for `IClientUnknown'};
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CParticleEffectBinding::`vftable'{for `IClientRenderable'};
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: this);
  CParticleEffectBinding::Term(this);
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_Materials);
  if ( this->m_Materials.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Materials.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Materials.m_Memory.m_pMemory);
      this->m_Materials.m_Memory.m_pMemory = nullptr;
    }
    this->m_Materials.m_Memory.m_nAllocationCount = 0;
  }
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (CParticleEffectBinding_vtbl *)&IHandleEntity::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101355D0
// Name: private: class CEffectMaterial __near * CParticleEffectBinding::GetEffectMaterial(class CParticleSubTexture __near *)
// Source: json
//------------------------------------------------------------------------------
CEffectMaterial *__thiscall CParticleEffectBinding::GetEffectMaterial(
        CParticleEffectBinding *this,
        CParticleSubTexture *pSubTexture)
{
  unsigned int v3; // esi
  CEffectMaterial *result; // eax
  CEffectMaterial *v5; // eax
  CEffectMaterial *v6; // ebx
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *p_m_Materials; // esi
  unsigned __int16 v8; // ax
  int v9; // edi
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *m_pMemory; // eax
  int v11; // ecx
  _DWORD *p_m_Element; // esi
  unsigned __int16 pSubTexturea; // [esp+10h] [ebp+8h]

  v3 = ((unsigned int)pSubTexture->m_pGroup >> 6) & 7;
  result = this->m_EffectMaterialHash[v3];
  if ( result != nullptr )
  {
    while ( result->m_pGroup != pSubTexture->m_pGroup )
    {
      result = result->m_pHashedNext;
      if ( result == nullptr )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v5 = (CEffectMaterial *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v5 != nullptr )
    {
      v5->m_Particles.m_pPrev = &v5->m_Particles;
      v5->m_Particles.m_pNext = &v5->m_Particles;
      v5->m_pGroup = nullptr;
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    v6->m_pGroup = pSubTexture->m_pGroup;
    v6->m_pHashedNext = this->m_EffectMaterialHash[v3];
    this->m_EffectMaterialHash[v3] = v6;
    p_m_Materials = (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_Materials;
    v8 = CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_Materials,
           multilist: false);
    v9 = v8;
    if ( v8 != 0xFFFF )
    {
      CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
        this: p_m_Materials,
        elem: v8);
      m_pMemory = p_m_Materials->m_Memory.m_pMemory;
      v11 = v9;
      m_pMemory[v11].m_Next = -1;
      pSubTexturea = p_m_Materials->m_Tail;
      m_pMemory[v11].m_Previous = pSubTexturea;
      p_m_Materials->m_Tail = v9;
      if ( pSubTexturea == 0xFFFF )
        p_m_Materials->m_Head = v9;
      else
        p_m_Materials->m_Memory.m_pMemory[pSubTexturea].m_Next = v9;
      ++p_m_Materials->m_ElementCount;
      p_m_Element = &p_m_Materials->m_Memory.m_pMemory[v11].m_Element;
      if ( p_m_Element != nullptr )
        *p_m_Element = v6;
    }
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101356C0
// Name: public: CParticleMgr::CParticleMgr(void)
// Source: json
//------------------------------------------------------------------------------
CParticleMgr *__thiscall CParticleMgr::CParticleMgr(CParticleMgr *this)
{
  CParticleMgr *result; // eax

  result = this;
  this->__vftable = (CParticleMgr_vtbl *)&CParticleMgr::`vftable';
  this->m_Effects.m_Memory.m_pMemory = nullptr;
  this->m_Effects.m_Memory.m_nAllocationCount = 0;
  this->m_Effects.m_Memory.m_nGrowSize = 0;
  this->m_Effects.m_LastAlloc.index = -1;
  this->m_Effects.m_Head = -1;
  this->m_Effects.m_Tail = -1;
  this->m_Effects.m_FirstFree = -1;
  this->m_Effects.m_ElementCount = 0;
  this->m_Effects.m_NumAlloced = 0;
  this->m_Effects.m_pElements = this->m_Effects.m_Memory.m_pMemory;
  this->m_NewEffects.m_pHead = nullptr;
  this->m_NonDrawingParticleSystems.m_pHead = nullptr;
  this->m_effectListeners.m_Memory.m_pMemory = nullptr;
  this->m_effectListeners.m_Memory.m_nAllocationCount = 0;
  this->m_effectListeners.m_Memory.m_nGrowSize = 0;
  this->m_effectListeners.m_Size = 0;
  this->m_effectListeners.m_pElements = nullptr;
  this->m_SubTextureGroups.m_Memory.m_pMemory = nullptr;
  this->m_SubTextureGroups.m_Memory.m_nAllocationCount = 0;
  this->m_SubTextureGroups.m_Memory.m_nGrowSize = 0;
  this->m_SubTextureGroups.m_Size = 0;
  this->m_SubTextureGroups.m_pElements = nullptr;
  this->m_SubTextures.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_SubTextures.m_Elements.m_Tree.m_Root = -1;
  this->m_SubTextures.m_Elements.m_Tree.m_NumElements = 0;
  this->m_SubTextures.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_SubTextures.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_SubTextures.m_Elements.m_Tree.m_pElements = this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_SubTextures.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_SubTextures.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_DefaultInvalidSubTexture.m_DefaultGroup.m_pPageMaterial = nullptr;
  this->m_DefaultInvalidSubTexture.m_tCoordMins[0] = 0.0;
  this->m_DefaultInvalidSubTexture.m_tCoordMaxs[0] = 1.0;
  this->m_DefaultInvalidSubTexture.m_pMaterial = nullptr;
  this->m_DefaultInvalidSubTexture.m_pGroup = &this->m_DefaultInvalidSubTexture.m_DefaultGroup;
  this->m_effectFactories.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_effectFactories.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_effectFactories.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_effectFactories.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_effectFactories.m_Tree.m_Root = -1;
  this->m_effectFactories.m_Tree.m_NumElements = 0;
  this->m_effectFactories.m_Tree.m_FirstFree = -1;
  this->m_effectFactories.m_Tree.m_LastAlloc.index = -1;
  this->m_effectFactories.m_Tree.m_pElements = this->m_effectFactories.m_Tree.m_Elements.m_pMemory;
  this->m_nToolParticleEffectId = 0;
  *(_WORD *)&this->m_bUpdatingEffects = 256;
  this->m_pMaterialSystem = nullptr;
  this->m_pThreadPool[0] = nullptr;
  this->m_pThreadPool[1] = nullptr;
  *(_QWORD *)&this->m_DirectionalLight.m_vPos.x = 0;
  *(_QWORD *)&this->m_DirectionalLight.m_vPos.z = 0;
  *(_QWORD *)&this->m_DirectionalLight.m_vColor.y = 0;
  this->m_DirectionalLight.m_flIntensity = 0.0;
  this->m_FrameCode = 1;
  this->m_DefaultInvalidSubTexture.m_pGroup = &this->m_DefaultInvalidSubTexture.m_DefaultGroup;
  this->m_DefaultInvalidSubTexture.m_pMaterial = nullptr;
  *(_QWORD *)this->m_DefaultInvalidSubTexture.m_tCoordMins = 0;
  this->m_DefaultInvalidSubTexture.m_tCoordMaxs[1] = 1.0;
  this->m_DefaultInvalidSubTexture.m_tCoordMaxs[0] = 1.0;
  this->m_nCurrentParticlesAllocated = 0;
  if ( this->m_effectFactories.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_effectFactories.m_Tree.m_LessFunc.m_LessFunc = CDefOps<char const *>::LessFunc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10135890
// Name: public: virtual CParticleMgr::~CParticleMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::~CParticleMgr(CParticleMgr *this)
{
  this->__vftable = (CParticleMgr_vtbl *)&CParticleMgr::`vftable';
  CParticleMgr::Term(this, bCanReferenceOtherStaticObjects: false);
  CUtlRBTree<CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_effectFactories.m_Tree);
  CUtlDict<CParticleSubTexture *,unsigned short>::RemoveAll(this: &this->m_SubTextures);
  CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_SubTextures.m_Elements.m_Tree);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SubTextureGroups);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_effectListeners);
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_Effects);
  if ( this->m_Effects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Effects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Effects.m_Memory.m_pMemory);
      this->m_Effects.m_Memory.m_pMemory = nullptr;
    }
    this->m_Effects.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135910
// Name: public: bool CParticleMgr::Init(unsigned long,class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleMgr::Init(CParticleMgr *this, unsigned int count, IMaterialSystem *pMaterials)
{
  bool bPrecacheParticles; // [esp+10h] [ebp+Ch]

  CParticleMgr::Term(this, bCanReferenceOtherStaticObjects: true);
  this->m_pMaterialSystem = pMaterials;
  bPrecacheParticles = !engine->IsCreatingXboxReslist(this: engine);
  CParticleSystemMgr::Init(
    this: g_pParticleSystemMgr,
    pQuery: g_pParticleSystemQuery,
    bAllowPrecache: bPrecacheParticles);
  CParticleSystemMgr::AddBuiltinSimulationOperators(this: g_pParticleSystemMgr);
  CParticleSystemMgr::AddBuiltinRenderingOperators(this: g_pParticleSystemMgr);
  ParseParticleEffects(bLoadSheets: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10135980
// Name: public: bool CParticleMgr::AddEffect(class CParticleEffectBinding __near *,class IParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleMgr::AddEffect(CParticleMgr *this, CParticleEffectBinding *pEffect, IParticleEffect *pSim)
{
  IClientLeafSystem_vtbl *v4; // edi
  unsigned __int16 *v5; // eax
  int v6; // esi
  unsigned __int16 v7; // ax
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *v8; // eax
  int m_Size; // edi
  int i; // esi
  IClientParticleListener *v11; // ecx
  IClientLeafSystem *v13; // [esp+Ch] [ebp-4h]

  pEffect->m_pSim = pSim;
  pEffect->m_pParticleMgr = this;
  g_pClientLeafSystem->CreateRenderableHandle(
    this: g_pClientLeafSystem,
    a2: &pEffect->IClientRenderable,
    a3: false,
    a4: RENDERABLE_IS_TRANSLUCENT,
    a5: RENDERABLE_MODEL_ENTITY,
    a6: -1);
  v4 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
  v13 = g_pClientLeafSystem;
  v5 = pEffect->RenderHandle(this: &pEffect->IClientRenderable);
  v4->EnableBloatedBounds(this: v13, a2: *v5, a3: true);
  v6 = (unsigned __int16)CUtlLinkedList<CParticleEffectBinding *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>>::AllocInternal(
                           this: &this->m_Effects,
                           multilist: false);
  v7 = -1;
  if ( (_WORD)v6 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_Effects,
      before: 0xFFFFu,
      elem: v6);
    v8 = &this->m_Effects.m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = pEffect;
    v7 = v6;
  }
  pEffect->m_ListIndex = v7;
  m_Size = this->m_effectListeners.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v11 = this->m_effectListeners.m_Memory.m_pMemory[i];
    v11->OnParticleEffectAdded(this: v11, a2: pSim);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10135A40
// Name: private: void CParticleMgr::SpewActiveParticleSystems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::SpewActiveParticleSystems(CParticleMgr *this)
{
  int v1; // esi
  CNewParticleEffect *m_pHead; // edi
  CParticleCollection *v4; // ebx
  const char *Name; // eax
  int m_Id; // esi
  ParticleInfo_t *m_pMemory; // ecx
  CParticleCollection *v8; // ecx
  int i; // edi
  int v10; // eax
  int v11; // ecx
  const char *v12; // eax
  int v13; // esi
  ParticleInfo_t *v14; // edi
  const char *v15; // eax
  ParticleInfo_t *v16; // eax
  CUtlStringMap<ParticleInfo_t> histo; // [esp+Ch] [ebp-58h] BYREF
  CNewParticleEffect *pNewEffect; // [esp+58h] [ebp-Ch]
  CUtlSymbol v19; // [esp+5Ch] [ebp-8h] BYREF
  CUtlSymbol result; // [esp+60h] [ebp-4h] BYREF

  v1 = 0;
  histo.m_Vector.m_Memory.m_pMemory = nullptr;
  histo.m_Vector.m_Memory.m_nAllocationCount = 0;
  histo.m_Vector.m_Memory.m_nGrowSize = 32;
  histo.m_Vector.m_Size = 0;
  histo.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &histo.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  m_pHead = this->m_NewEffects.m_pHead;
  pNewEffect = m_pHead;
  if ( m_pHead != nullptr )
  {
    while ( 1 )
    {
      v4 = &m_pHead->CParticleCollection;
      Name = CParticleCollection::GetName(this: &m_pHead->CParticleCollection);
      CUtlSymbolTable::AddString(this: &histo.m_SymbolTable, &result, pString: Name);
      m_Id = result.m_Id;
      if ( histo.m_Vector.m_Size <= result.m_Id && histo.m_Vector.m_Size < result.m_Id + 1 )
        CUtlVector<ParticleInfo_t,CUtlMemory<ParticleInfo_t,int>>::InsertMultipleBefore(
          this: &histo.m_Vector,
          elem: histo.m_Vector.m_Size,
          num: result.m_Id + 1 - histo.m_Vector.m_Size);
      m_pMemory = histo.m_Vector.m_Memory.m_pMemory;
      ++histo.m_Vector.m_Memory.m_pMemory[m_Id].m_nCount;
      if ( m_pMemory[m_Id].m_nCount == 1 )
      {
        v8 = (m_pHead != nullptr ? &v4->m_Children : (CUtlIntrusiveDList<CParticleCollection> *)140)->m_pHead;
        for ( i = 1; v8 != nullptr; i += v10 )
        {
          v10 = CountChildParticleSystems(p: v8);
          v8 = *(CParticleCollection **)(v11 + 112);
        }
        v12 = CParticleCollection::GetName(this: v4);
        CUtlSymbolTable::AddString(this: &histo.m_SymbolTable, result: &v19, pString: v12);
        v13 = v19.m_Id;
        if ( histo.m_Vector.m_Size <= v19.m_Id && histo.m_Vector.m_Size < v19.m_Id + 1 )
          CUtlVector<ParticleInfo_t,CUtlMemory<ParticleInfo_t,int>>::InsertMultipleBefore(
            this: &histo.m_Vector,
            elem: histo.m_Vector.m_Size,
            num: v19.m_Id + 1 - histo.m_Vector.m_Size);
        histo.m_Vector.m_Memory.m_pMemory[v13].m_nChildCount = i;
        m_pHead = pNewEffect;
      }
      pNewEffect = m_pHead->m_pNext;
      if ( pNewEffect == nullptr )
        break;
      m_pHead = pNewEffect;
    }
    v1 = 0;
  }
  _Msg(a1: "Too many simultaneously active particle systems!\n");
  _Msg(a1: "Name\t\t\t\t\tCount\t\tChild Count Per Instance\n");
  pNewEffect = (CNewParticleEffect *)histo.m_SymbolTable.m_Lookup.m_NumElements;
  if ( histo.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v14 = &histo.m_Vector.m_Memory.m_pMemory[(unsigned __int16)v1];
      v15 = CUtlSymbolTable::String(this: &histo.m_SymbolTable, id: (CUtlSymbol)v1);
      _Msg(a1: "%30s\t\t%d\t\t%d\n", v15, v14->m_nCount, v14->m_nChildCount);
      ++v1;
    }
    while ( v1 < (int)pNewEffect );
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &histo.m_SymbolTable);
  v16 = histo.m_Vector.m_Memory.m_pMemory;
  histo.m_Vector.m_Size = 0;
  if ( histo.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( histo.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: histo.m_Vector.m_Memory.m_pMemory);
      v16 = nullptr;
      histo.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    histo.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  histo.m_Vector.m_pElements = v16;
  if ( histo.m_Vector.m_Memory.m_nGrowSize >= 0 && v16 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
}

//------------------------------------------------------------------------------
// Address: 0x10135C20
// Name: public: struct Particle __near * CParticleEffectBinding::AddParticle(int,class CParticleSubTexture __near *)
// Source: json
//------------------------------------------------------------------------------
Particle *__userpurge CParticleEffectBinding::AddParticle@<eax>(
        CParticleEffectBinding *this@<ecx>,
        int a2@<esi>,
        int sizeInBytes,
        CParticleSubTexture *hMaterial)
{
  IUniformRandomStream *v6; // ecx
  Particle *v8; // esi
  Particle *p_m_Particles; // eax
  CParticleMgr *hMateriala; // [esp+14h] [ebp+Ch]

  CParticleMgr::RepairPMaterial(this: this->m_pParticleMgr, a2: (int)hMaterial, a3: a2, hMaterial);
  if ( sizeInBytes > 96
    || particle_simulateoverflow.m_pParent != nullptr
    && particle_simulateoverflow.m_pParent->m_Value.m_nValue != 0
    && rand(this: v6) % 10 <= 6 )
  {
    return nullptr;
  }
  hMateriala = this->m_pParticleMgr;
  if ( hMateriala->m_nCurrentParticlesAllocated >= 2048 )
    return nullptr;
  v8 = (Particle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96);
  if ( v8 == nullptr )
    return nullptr;
  ++hMateriala->m_nCurrentParticlesAllocated;
  p_m_Particles = &CParticleEffectBinding::GetEffectMaterial(this, pSubTexture: hMaterial)->m_Particles;
  v8->m_pPrev = p_m_Particles;
  v8->m_pNext = p_m_Particles->m_pNext;
  p_m_Particles->m_pNext = v8;
  v8->m_pNext->m_pPrev = v8;
  if ( hMaterial != nullptr )
    v8->m_pSubTexture = hMaterial;
  else
    v8->m_pSubTexture = &this->m_pParticleMgr->m_DefaultInvalidSubTexture;
  ++this->m_nActiveParticles;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10135D20
// Name: public: void CParticleMgr::RegisterEffect(char const __near *,class IParticleEffect __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleMgr::RegisterEffect(
        CParticleMgr *this@<ecx>,
        const char *a2@<edi>,
        const char *pEffectType,
        IParticleEffect *(__cdecl *func)())
{
  CUtlMap<char const *,IParticleEffect * (__cdecl*)(void),unsigned short>::Node_t insert; // [esp+0h] [ebp-8h] BYREF

  insert.key = pEffectType;
  insert.elem = func;
  CUtlRBTree<CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IParticleEffect * (__cdecl *)(void),unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_effectFactories.m_Tree,
    a2,
    &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10135D50
// Name: private: void CParticleMgr::UpdateNewEffects(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::UpdateNewEffects(CParticleMgr *this, float flTimeDelta)
{
  float v2; // xmm0_4
  int v4; // esi
  CNewParticleEffect **m_pMemory; // ebx
  CNewParticleEffect *v6; // eax
  CParticleCollection *v7; // eax
  CParticleCollection *m_pHead; // ecx
  int j; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  CNewParticleEffect **v13; // ebx
  int m_Size; // esi
  CNewParticleEffect **v15; // esi
  int v16; // ebx
  CParticleCollection **m_pFixedMemory; // edx
  CParticleMgr *m_pNext; // ecx
  CNonDrawingParticleSystem *v19; // edi
  int v20; // eax
  int m_nAllocationCount; // esi
  int v22; // ebx
  unsigned int v23; // esi
  unsigned __int8 *v24; // edi
  CParticleCollection **v25; // ecx
  int v26; // edi
  int k; // esi
  CParticleCollection **v28; // eax
  CUtlVectorFixedGrowable<CParticleCollection *,128> nonDrawingSimulateList; // [esp+24h] [ebp-26Ch] BYREF
  CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1> v30; // [esp+23Ch] [ebp-54h] BYREF
  CParallelProcessor<CParticleCollection *,CFuncJobItemProcessor<CParticleCollection *>,1> v31; // [esp+254h] [ebp-3Ch] BYREF
  int num; // [esp+26Ch] [ebp-24h]
  int nMaxParticleCount; // [esp+270h] [ebp-20h]
  CParticleMgr *v34; // [esp+274h] [ebp-1Ch]
  int nParticleSystemCount; // [esp+278h] [ebp-18h]
  CUtlVector<CNewParticleEffect *,CUtlMemory<CNewParticleEffect *,int> > particlesToSimulate; // [esp+27Ch] [ebp-14h] BYREF
  CNonDrawingParticleSystem *i; // [esp+298h] [ebp+8h]

  v2 = r_particle_timescale.m_pParent->m_Value.m_fValue * flTimeDelta;
  v34 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CParticleMSG::UpdateNewEffects",
    a3: 0,
    a4: "Particle Simulation",
    a5: false,
    a6: 4);
  CParticleSystemMgr::SetLastSimulationTime(this: g_pParticleSystemMgr, flTime: *(float *)(gpGlobals.m_Index + 12));
  nParticleSystemCount = 0;
  if ( cl_particle_max_count.m_pParent != nullptr )
    nMaxParticleCount = cl_particle_max_count.m_pParent->m_Value.m_nValue;
  else
    nMaxParticleCount = 0;
  g_flStartSimTime = _Plat_FloatTime(a1: nonDrawingSimulateList.m_Memory.m_pMemory);
  memset(&particlesToSimulate, 0, sizeof(particlesToSimulate));
  CParticleMgr::BuildParticleSimList(this, list: &particlesToSimulate);
  v4 = 0;
  for ( s_flThreadedPSystemTimeStep = v2; v4 < particlesToSimulate.m_Size; ++v4 )
  {
    m_pMemory = particlesToSimulate.m_Memory.m_pMemory;
    ((void (__stdcall *)(_DWORD))particlesToSimulate.m_Memory.m_pMemory[v4]->Update)(a1: LODWORD(s_flThreadedPSystemTimeStep));
    if ( nMaxParticleCount > 0 )
    {
      v6 = m_pMemory[v4];
      if ( v6 != nullptr )
        v7 = &v6->CParticleCollection;
      else
        v7 = nullptr;
      m_pHead = v7->m_Children.m_pHead;
      for ( j = 1; m_pHead != nullptr; j = v10 + v12 )
      {
        v10 = CountChildParticleSystems(p: m_pHead);
        m_pHead = *(CParticleCollection **)(v11 + 112);
      }
      nParticleSystemCount += j;
    }
  }
  v13 = particlesToSimulate.m_Memory.m_pMemory;
  if ( CParticleMgr::EarlyRetireParticleSystems(
         this: v34,
         nCount: particlesToSimulate.m_Size,
         ppEffects: particlesToSimulate.m_Memory.m_pMemory) != 0 )
  {
    particlesToSimulate.m_Size = 0;
    CParticleMgr::BuildParticleSimList(this: v34, list: &particlesToSimulate);
    v13 = particlesToSimulate.m_Memory.m_pMemory;
  }
  m_Size = particlesToSimulate.m_Size;
  if ( particlesToSimulate.m_Size != 0 )
  {
    UpdateDirtySpatialPartitionEntities();
    if ( r_threaded_particles.m_pParent != nullptr && r_threaded_particles.m_pParent->m_Value.m_nValue != 0 )
    {
      v30.m_pItems.m_value = nullptr;
      v30.m_pLimit = nullptr;
      _InterlockedExchange((volatile __int32 *)&v30.m_pItems, 0);
      v30.m_ItemProcessor.m_pfnProcess = ProcessPSystem;
      v30.m_ItemProcessor.m_pfnBegin = (void (__cdecl *)())PreThreadedBoneSetup;
      v30.m_ItemProcessor.m_pfnEnd = (void (__cdecl *)())PostThreadedBoneSetup;
      CParallelProcessor<CNewParticleEffect *,CFuncJobItemProcessor<CNewParticleEffect *>,1>::Run(
        this: &v30,
        pItems: v13,
        nItems: m_Size,
        nChunkSize: 1,
        nMaxParallel: 0x7FFFFFFF,
        pThreadPool: nullptr);
    }
    else if ( m_Size > 0 )
    {
      v15 = v13;
      v16 = particlesToSimulate.m_Size;
      do
      {
        ProcessPSystem(pNewEffect: v15++);
        --v16;
      }
      while ( v16 != 0 );
      v13 = particlesToSimulate.m_Memory.m_pMemory;
    }
  }
  m_pFixedMemory = nonDrawingSimulateList.m_Memory.m_pFixedMemory;
  nonDrawingSimulateList.m_pElements = nonDrawingSimulateList.m_Memory.m_pFixedMemory;
  m_pNext = v34;
  nonDrawingSimulateList.m_Memory.m_nMallocGrowSize = 0;
  v19 = v34->m_NonDrawingParticleSystems.m_pHead;
  v20 = 0;
  m_nAllocationCount = 128;
  nonDrawingSimulateList.m_Memory.m_pMemory = nonDrawingSimulateList.m_Memory.m_pFixedMemory;
  nonDrawingSimulateList.m_Memory.m_nAllocationCount = 128;
  nonDrawingSimulateList.m_Memory.m_nGrowSize = -1;
  nonDrawingSimulateList.m_Size = 0;
  i = v19;
  if ( v19 != nullptr )
  {
    while ( 1 )
    {
      v22 = v20;
      if ( v20 + 1 > m_nAllocationCount )
      {
        num = v20 - m_nAllocationCount + 1;
        if ( nonDrawingSimulateList.m_Memory.m_nGrowSize < 0 )
        {
          nonDrawingSimulateList.m_Memory.m_nGrowSize = nonDrawingSimulateList.m_Memory.m_nMallocGrowSize;
          if ( m_nAllocationCount != 0 )
          {
            v23 = 4 * m_nAllocationCount;
            v24 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
            memcpy(dst: v24, src: (unsigned __int8 *)nonDrawingSimulateList.m_Memory.m_pMemory, count: v23);
            nonDrawingSimulateList.m_Memory.m_pMemory = (CParticleCollection **)v24;
            v19 = i;
          }
          else
          {
            nonDrawingSimulateList.m_Memory.m_pMemory = nullptr;
          }
        }
        CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&nonDrawingSimulateList, num);
        v20 = nonDrawingSimulateList.m_Size;
        m_nAllocationCount = nonDrawingSimulateList.m_Memory.m_nAllocationCount;
        m_pFixedMemory = nonDrawingSimulateList.m_Memory.m_pMemory;
      }
      nonDrawingSimulateList.m_Size = ++v20;
      nonDrawingSimulateList.m_pElements = m_pFixedMemory;
      if ( v20 - v22 - 1 > 0 )
      {
        _V_memmove(dest: &m_pFixedMemory[v22 + 1], src: &m_pFixedMemory[v22], count: 4 * (v20 - v22 - 1));
        v20 = nonDrawingSimulateList.m_Size;
        m_nAllocationCount = nonDrawingSimulateList.m_Memory.m_nAllocationCount;
        m_pFixedMemory = nonDrawingSimulateList.m_Memory.m_pMemory;
      }
      v25 = &m_pFixedMemory[v22];
      if ( v25 != nullptr )
      {
        *v25 = v19->m_pSystem;
        v20 = nonDrawingSimulateList.m_Size;
        m_nAllocationCount = nonDrawingSimulateList.m_Memory.m_nAllocationCount;
        m_pFixedMemory = nonDrawingSimulateList.m_Memory.m_pMemory;
      }
      m_pNext = (CParticleMgr *)v19->m_pNext;
      i = v19->m_pNext;
      if ( v19->m_pNext == nullptr )
        break;
      v19 = v19->m_pNext;
    }
    if ( v20 != 0 )
    {
      v31.m_pItems.m_value = nullptr;
      v31.m_pLimit = nullptr;
      _InterlockedExchange((volatile __int32 *)&v31.m_pItems, 0);
      v31.m_ItemProcessor.m_pfnProcess = ProcessNonDrawingSystem;
      v31.m_ItemProcessor.m_pfnBegin = (void (__cdecl *)())PreThreadedBoneSetup;
      v31.m_ItemProcessor.m_pfnEnd = (void (__cdecl *)())PostThreadedBoneSetup;
      CParallelProcessor<CParticleCollection *,CFuncJobItemProcessor<CParticleCollection *>,1>::Run(
        this: &v31,
        pItems: m_pFixedMemory,
        nItems: v20,
        nChunkSize: 1,
        nMaxParallel: 0x7FFFFFFF,
        pThreadPool: nullptr);
    }
    v13 = particlesToSimulate.m_Memory.m_pMemory;
  }
  v26 = particlesToSimulate.m_Size;
  for ( k = 0; k < v26; ++k )
    CNewParticleEffect::DetectChanges(this: v13[k]);
  EndSimulateParticles(this: m_pNext);
  if ( nMaxParticleCount > 0 && nParticleSystemCount >= nMaxParticleCount )
    CParticleMgr::SpewActiveParticleSystems(this: v34);
  v28 = nonDrawingSimulateList.m_Memory.m_pMemory;
  nonDrawingSimulateList.m_Size = 0;
  if ( nonDrawingSimulateList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( nonDrawingSimulateList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: nonDrawingSimulateList.m_Memory.m_pMemory);
      v28 = nullptr;
      nonDrawingSimulateList.m_Memory.m_pMemory = nullptr;
    }
    nonDrawingSimulateList.m_Memory.m_nAllocationCount = 0;
  }
  nonDrawingSimulateList.m_pElements = v28;
  if ( nonDrawingSimulateList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      nonDrawingSimulateList.m_Memory.m_pMemory = nullptr;
    }
    nonDrawingSimulateList.m_Memory.m_nAllocationCount = 0;
  }
  if ( particlesToSimulate.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10136110
// Name: private: void CParticleMgr::UpdateAllEffects(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::UpdateAllEffects(CParticleMgr *this, float flTimeDelta)
{
  CPULevel_t ActualCPULevel; // eax
  float v4; // xmm1_4
  int m_Head; // eax
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *m_pMemory; // ecx
  unsigned int v7; // edi
  CParticleEffectBinding *m_Element; // esi
  int m_Flags; // eax
  IParticleEffect *m_pSim; // ecx
  int v11; // eax
  bool v12; // cf
  int v13; // eax
  int v14; // edx
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *v15; // eax
  int m_Next; // esi
  CParticleEffectBinding *v17; // eax
  CNewParticleEffect *m_pHead; // esi
  CNewParticleEffect *m_pNext; // eax
  CNewParticleEffect *m_pPrev; // eax
  CNewParticleEffect *v21; // eax
  CNewParticleEffect *v22; // eax
  void (__thiscall *NotifyRemove)(struct CNewParticleEffect *); // edx
  GPULevel_t flSimThresholdMs; // [esp+Ch] [ebp-14h]
  float dt; // [esp+1Ch] [ebp-4h]
  CNewParticleEffect *pNextEffect; // [esp+28h] [ebp+8h]

  this->m_bUpdatingEffects = true;
  g_pParticleSystemQuery->PreSimulate(this: g_pParticleSystemQuery);
  CParticleSystemMgr::SetFallbackParameters(
    this: g_pParticleSystemMgr,
    flBase: cl_particle_fallback_base.m_pParent->m_Value.m_fValue,
    flMultiplier: cl_particle_fallback_multiplier.m_pParent->m_Value.m_fValue,
    flSimFallbackBaseMultiplier: cl_particle_sim_fallback_base_multiplier.m_pParent->m_Value.m_fValue,
    flSimThresholdMs: cl_particle_sim_fallback_threshold_ms.m_pParent->m_Value.m_fValue);
  flSimThresholdMs = GetGPULevel();
  ActualCPULevel = GetActualCPULevel();
  CParticleSystemMgr::SetSystemLevel(this: g_pParticleSystemMgr, nCPULevel: ActualCPULevel, nGPULevel: flSimThresholdMs);
  v4 = flTimeDelta;
  if ( flTimeDelta > 0.1 )
  {
    v4 = 0.1;
    flTimeDelta = 0.1;
  }
  m_Head = this->m_Effects.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_pMemory = this->m_Effects.m_Memory.m_pMemory;
      v7 = (unsigned __int16)m_Head;
      m_Element = m_pMemory[v7].m_Element;
      m_Flags = m_Element->m_Flags;
      if ( (m_Flags & 1) == 0 )
      {
        if ( (m_Flags & 4) != 0
          && ((m_Flags & 8) == 0 || CParticleEffectBinding::RecalculateBoundingBox(this: m_pMemory[v7].m_Element)) )
        {
          m_Element->m_Flags &= ~4u;
        }
        m_pSim = m_Element->m_pSim;
        m_Element->m_Flags &= ~0x20u;
        ((void (__stdcall *)(_DWORD))m_pSim->Update)(a1: LODWORD(flTimeDelta));
        v11 = m_Element->m_Flags;
        if ( (v11 & 0x800) != 0 )
          m_Element->m_Flags = v11 & 0xFFFFF7FF;
        else
          CParticleEffectBinding::SimulateParticles(this: m_Element, flTimeDelta);
        CParticleEffectBinding::DetectChanges(this: m_Element);
      }
      m_Head = this->m_Effects.m_Memory.m_pMemory[v7].m_Next;
    }
    while ( m_Head != 0xFFFF );
    v4 = flTimeDelta;
  }
  if ( g_bMeasureParticlePerformance )
  {
    dt = 0.0;
    if ( v4 >= 0.0 )
    {
      do
      {
        CParticleMgr::UpdateNewEffects(this, flTimeDelta: 0.0099999998);
        v12 = flTimeDelta < (float)(dt + 0.0099999998);
        dt = dt + 0.0099999998;
      }
      while ( !v12 );
    }
  }
  else
  {
    CParticleMgr::UpdateNewEffects(this, flTimeDelta: v4);
  }
  v13 = this->m_Effects.m_Head;
  this->m_bUpdatingEffects = false;
  if ( v13 != 0xFFFF )
  {
    do
    {
      v14 = (unsigned __int16)v13;
      v15 = this->m_Effects.m_Memory.m_pMemory;
      m_Next = v15[v14].m_Next;
      v17 = v15[v14].m_Element;
      if ( (v17->m_Flags & 1) != 0 )
        CParticleMgr::RemoveEffect(this, pEffect: v17);
      LOWORD(v13) = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  m_pHead = this->m_NewEffects.m_pHead;
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      pNextEffect = m_pNext;
      if ( (*((_BYTE *)m_pHead + 944) & 2) != 0 )
      {
        ((void (__stdcall *)(_DWORD))g_pClientLeafSystem->RemoveRenderable)(a1: m_pHead->m_hRenderHandle);
        m_pPrev = m_pHead->m_pPrev;
        if ( m_pPrev != nullptr )
        {
          m_pPrev->m_pNext = m_pHead->m_pNext;
          v21 = m_pHead->m_pNext;
          if ( v21 != nullptr )
            v21->m_pPrev = m_pHead->m_pPrev;
        }
        else if ( this->m_NewEffects.m_pHead == m_pHead )
        {
          v22 = m_pHead->m_pNext;
          this->m_NewEffects.m_pHead = v22;
          if ( v22 != nullptr )
            v22->m_pPrev = nullptr;
        }
        NotifyRemove = m_pHead->NotifyRemove;
        m_pHead->m_pPrev = nullptr;
        m_pHead->m_pNext = nullptr;
        NotifyRemove(this: m_pHead);
        m_pNext = pNextEffect;
      }
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  g_pParticleSystemQuery->PostSimulate(this: g_pParticleSystemQuery);
}

//------------------------------------------------------------------------------
// Address: 0x10136430
// Name: class CParticleMgr __near * ParticleMgr(void)
// Source: json
//------------------------------------------------------------------------------
CParticleMgr *__cdecl ParticleMgr()
{
  if ( (_S5_107 & 1) == 0 )
  {
    _S5_107 |= 1u;
    CParticleMgr::CParticleMgr(this: &s_ParticleMgr);
    atexit(func: ParticleMgr_::_2_::_dynamic_atexit_destructor_for__s_ParticleMgr__);
  }
  return &s_ParticleMgr;
}

//------------------------------------------------------------------------------
// Address: 0x10136460
// Name: public: void CParticleMgr::Simulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleMgr::Simulate(CParticleMgr *this, float flTimeDelta)
{
  bool v2; // zf

  v2 = this->m_pMaterialSystem == nullptr;
  g_nParticlesDrawn = 0;
  if ( !v2 )
    CParticleMgr::UpdateAllEffects(this, flTimeDelta);
}

//------------------------------------------------------------------------------
// Address: 0x10136490
// Name: public: class CParticleSubTexture __near * CParticleMgr::GetPMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSubTexture *__thiscall CParticleMgr::GetPMaterial(CParticleMgr *this, const char *pMaterialName)
{
  bool v3; // zf
  unsigned __int16 v5; // ax
  IMaterial *v6; // eax
  IMaterial *v7; // esi
  CParticleSubTexture *v8; // eax
  CParticleSubTexture *v9; // edi
  IMaterial *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  CParticleMgr *v15; // ecx
  int v16; // esi
  CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t flScale; // [esp+4h] [ebp-14h] BYREF
  float flOffset[2]; // [esp+Ch] [ebp-Ch] BYREF
  CParticleMgr *v19; // [esp+14h] [ebp-4h]
  unsigned __int16 hMat; // [esp+20h] [ebp+8h]
  float hMata; // [esp+20h] [ebp+8h]
  float hMatb; // [esp+20h] [ebp+8h]
  float hMatc; // [esp+20h] [ebp+8h]
  float hMatd; // [esp+20h] [ebp+8h]

  v3 = this->m_pMaterialSystem == nullptr;
  v19 = this;
  if ( v3 )
    return nullptr;
  if ( pMaterialName != nullptr )
  {
    flScale.key = pMaterialName;
    v5 = CUtlRBTree<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CParticleSubTexture *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CParticleSubTexture *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_SubTextures.m_Elements.m_Tree,
           search: &flScale);
  }
  else
  {
    v5 = -1;
  }
  if ( v5 == 0xFFFF )
  {
    v6 = this->m_pMaterialSystem->FindMaterial(
           this: this->m_pMaterialSystem,
           a2: pMaterialName,
           a3: "Particle textures",
           a4: 1,
           a5: 0);
    v7 = v6;
    if ( v6 != nullptr )
    {
      v6->IncrementReferenceCount(this: v6);
      hMat = CUtlDict<CParticleSubTexture *,unsigned short>::Insert(this: &this->m_SubTextures, pName: pMaterialName);
      v8 = (CParticleSubTexture *)MemAlloc_Alloc(nSize: 0x1Cu);
      v9 = nullptr;
      if ( v8 != nullptr )
      {
        v8->m_DefaultGroup.m_pPageMaterial = nullptr;
        v8->m_tCoordMins[0] = 0.0;
        v8->m_pMaterial = nullptr;
        v8->m_tCoordMaxs[0] = 1.0;
        v8->m_pGroup = &v8->m_DefaultGroup;
        v9 = v8;
      }
      this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory[hMat].m_Data.elem = v9;
      v9->m_pMaterial = v7;
      v10 = v7->GetMaterialPage(this: v7);
      if ( v7->InMaterialPage(this: v7) && v10 != nullptr )
      {
        v7->GetMaterialOffset(this: v7, a2: flOffset);
        v7->GetMaterialScale(this: v7, a2: (float *)&flScale);
        v11 = v10->GetMappingWidth(this: v10);
        v9->m_tCoordMins[0] = (float)v11 * (float)((float)(*(float *)&flScale.key * 0.0) + flOffset[0]);
        v12 = v10->GetMappingWidth(this: v10);
        v9->m_tCoordMaxs[0] = (float)v12 * (float)(flOffset[0] + *(float *)&flScale.key);
        v13 = v10->GetMappingHeight(this: v10);
        v9->m_tCoordMins[1] = (float)v13 * (float)((float)(*(float *)&flScale.elem * 0.0) + flOffset[1]);
        v14 = v10->GetMappingHeight(this: v10);
        v15 = v19;
        v9->m_tCoordMaxs[1] = (float)v14 * (float)(flOffset[1] + *(float *)&flScale.elem);
        v9->m_pGroup = CParticleMgr::FindOrAddSubTextureGroup(this: v15, pPageMaterial: v10);
      }
      else
      {
        v9->m_pGroup = &v9->m_DefaultGroup;
        v9->m_DefaultGroup.m_pPageMaterial = v7;
        *(_QWORD *)v9->m_tCoordMins = 0;
        v10 = v7;
        v9->m_tCoordMaxs[0] = (float)v7->GetMappingWidth(this: v7);
        v9->m_tCoordMaxs[1] = (float)v7->GetMappingHeight(this: v7);
      }
      hMata = v9->m_tCoordMins[0] + 0.5;
      v9->m_tCoordMins[0] = hMata / (float)v10->GetMappingWidth(this: v10);
      hMatb = v9->m_tCoordMins[1] + 0.5;
      v9->m_tCoordMins[1] = hMatb / (float)v10->GetMappingHeight(this: v10);
      hMatc = v9->m_tCoordMaxs[0] - 0.5;
      v9->m_tCoordMaxs[0] = hMatc / (float)v10->GetMappingWidth(this: v10);
      hMatd = v9->m_tCoordMaxs[1] - 0.5;
      v9->m_tCoordMaxs[1] = hMatd / (float)v10->GetMappingHeight(this: v10);
      return v9;
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    v16 = v5;
    CParticleMgr::RepairPMaterial(
      this,
      a2: (int)this,
      a3: v16 * 2,
      hMaterial: this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem);
    return this->m_SubTextures.m_Elements.m_Tree.m_Elements.m_pMemory[v16].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136790
// Name: public: CNonDrawingParticleSystem::~CNonDrawingParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNonDrawingParticleSystem::~CNonDrawingParticleSystem(CNonDrawingParticleSystem *this)
{
  CNonDrawingParticleSystem *m_pPrev; // eax
  CNonDrawingParticleSystem *m_pNext; // eax
  CParticleCollection *m_pSystem; // esi

  if ( (_S5_107 & 1) == 0 )
  {
    _S5_107 |= 1u;
    CParticleMgr::CParticleMgr(this: &s_ParticleMgr);
    atexit(func: ParticleMgr_::_2_::_dynamic_atexit_destructor_for__s_ParticleMgr__);
  }
  m_pPrev = this->m_pPrev;
  if ( m_pPrev != nullptr )
  {
    m_pPrev->m_pNext = this->m_pNext;
    if ( this->m_pNext != nullptr )
      this->m_pNext->m_pPrev = this->m_pPrev;
  }
  else if ( s_ParticleMgr.m_NonDrawingParticleSystems.m_pHead == this )
  {
    m_pNext = this->m_pNext;
    s_ParticleMgr.m_NonDrawingParticleSystems.m_pHead = m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = nullptr;
  }
  this->m_pPrev = nullptr;
  this->m_pNext = nullptr;
  m_pSystem = this->m_pSystem;
  if ( m_pSystem != nullptr )
  {
    CParticleCollection::~CParticleCollection(this: m_pSystem);
    CParticleOperatorInstance::operator delete(pData: m_pSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136810
// Name: cl_particles_dump_effects
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_particles_dump_effects()
{
  if ( (_S5_107 & 1) == 0 )
  {
    _S5_107 |= 1u;
    CParticleMgr::CParticleMgr(this: &s_ParticleMgr);
    atexit(func: ParticleMgr_::_2_::_dynamic_atexit_destructor_for__s_ParticleMgr__);
  }
  CParticleMgr::SpewInfo(this: &s_ParticleMgr, bDetail: true);
}

//------------------------------------------------------------------------------
// Address: 0x10136850
// Name: public: class CParticleSubTexture __near * CParticleEffectBinding::FindOrAddMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSubTexture *__thiscall CParticleEffectBinding::FindOrAddMaterial(
        CParticleEffectBinding *this,
        const char *pMaterialName)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  if ( m_pParticleMgr != nullptr )
    return CParticleMgr::GetPMaterial(this: m_pParticleMgr, pMaterialName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10369B30
// Name: private: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this)
{
  void (__thiscall *m_pfnBegin)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  int *m_pLimit; // ecx
  unsigned int v4; // edx
  int *v5; // esi
  int *v6; // ebx
  void (__thiscall *m_pfnEnd)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  unsigned int v8; // [esp+4h] [ebp-8h]
  int *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin(this: this->m_ItemProcessor.m_pObject);
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (int *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (int *)((char *)v5 + v4);
      if ( m_pLimit < (int *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(this: this->m_ItemProcessor.m_pObject, a2: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd(this: this->m_ItemProcessor.m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369C20
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1> __near *,void (CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10369CC0
// Name: public: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::Run(int __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this,
        int *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  int *v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10374110
// Name: public: class CNewParticleEffect __near * CParticleMgr::FirstNewEffect(void)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall CParticleMgr::FirstNewEffect(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x10031A20
// Name: void ScriptDeduceFunctionSignature<class C_BaseAnimating __near *,class C_BaseAnimating,void,char const __near *,float>(struct ScriptFuncDescriptor_t __near *,class C_BaseAnimating __near *,void (C_BaseAnimating::*)(char const __near *,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<C_BaseAnimating *,C_BaseAnimating,void,char const *,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 1;
}
