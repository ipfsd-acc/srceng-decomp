// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lightworld/lightworld.cpp
// Functions: 61
// ============================================================

#include "utils\lightworld\lightworld.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: bool CUniformSampler::InitSamples(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUniformSampler::InitSamples(CUniformSampler *this, int SqrtNumSamples, int NumVariations)
{
  int v3; // esi
  int v4; // edi
  Vector *v5; // eax
  CUniformSampler *v6; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // edi
  double v13; // xmm0_8
  Vector *m_pvDirections; // eax
  long double v15; // [esp+0h] [ebp-40h]
  long double v16; // [esp+0h] [ebp-40h]
  long double v17; // [esp+0h] [ebp-40h]
  long double v18; // [esp+0h] [ebp-40h]
  long double v19; // [esp+0h] [ebp-40h]
  int i; // [esp+14h] [ebp-2Ch]
  int v21; // [esp+20h] [ebp-20h]
  int v22; // [esp+24h] [ebp-1Ch]
  int n; // [esp+28h] [ebp-18h]
  float theta; // [esp+2Ch] [ebp-14h]
  float oneoverN; // [esp+38h] [ebp-8h]
  int a; // [esp+4Ch] [ebp+Ch]

  v3 = SqrtNumSamples;
  v4 = SqrtNumSamples * SqrtNumSamples;
  this->m_NumVariations = NumVariations;
  this->m_NumSamples = SqrtNumSamples * SqrtNumSamples;
  v5 = (Vector *)operator new(nSize: 12 * NumVariations * SqrtNumSamples * SqrtNumSamples);
  v6 = this;
  this->m_pvDirections = v5;
  if ( v5 == nullptr )
    return 0;
  v8 = 0;
  oneoverN = 1.0 / (float)SqrtNumSamples;
  n = 0;
  if ( this->m_NumVariations > 0 )
  {
    do
    {
      a = 0;
      if ( v3 > 0 )
      {
        v9 = 12 * v3;
        v10 = 12 * v8;
        v22 = 12 * v3;
        i = v4 + v8;
        while ( 1 )
        {
          v11 = 0;
          v12 = v10;
          v21 = v9 + v10;
          do
          {
            v13 = fsqrt(
                    1.0
                  - (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(rand() - 0x3FFF) * 0.000061038882) & _mask__AbsFloat_)
                                  + (float)a)
                          * oneoverN));
            __libm_sse2_acos(x: v15);
            *(float *)&v13 = v13;
            theta = *(float *)&v13 * 2.0;
            *(float *)&v13 = (float)((float)(COERCE_FLOAT(
                                               COERCE_UNSIGNED_INT((float)(rand() - 0x3FFF) * 0.000061038882)
                                             & _mask__AbsFloat_)
                                           + (float)v11)
                                   * oneoverN)
                           * 6.283185307179586;
            __libm_sse2_sin(x: v16);
            __libm_sse2_cos(x: v17);
            __libm_sse2_sin(x: v18);
            __libm_sse2_cos(x: v19);
            m_pvDirections = this->m_pvDirections;
            *(float *)((char *)&m_pvDirections->x + v12) = *(float *)&v13 * theta;
            *(float *)((char *)&m_pvDirections->y + v12) = *(float *)&v13 * theta;
            *(float *)((char *)&m_pvDirections->z + v12) = theta;
            ++v11;
            v12 += 12;
          }
          while ( v11 < SqrtNumSamples );
          if ( ++a >= SqrtNumSamples )
            break;
          v9 = v22;
          v10 = v21;
        }
        v4 = SqrtNumSamples * SqrtNumSamples;
        v8 = i;
        v3 = SqrtNumSamples;
        v6 = this;
      }
      ++n;
    }
    while ( n < v6->m_NumVariations );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401230
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  return AppMain(argc, (char **)argv, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x00401250
// Name: public: virtual bool CLightWorldApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLightWorldApp::Create(CLightWorldApp *this)
{
  AppSystemInfo_t appSystems[2]; // [esp+0h] [ebp-10h] BYREF

  appSystems[1].m_pModuleName = setName;
  appSystems[1].m_pInterfaceName = setName;
  appSystems[0].m_pModuleName = "worldrenderer";
  appSystems[0].m_pInterfaceName = "WorldRendererMgr001";
  return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
}

//------------------------------------------------------------------------------
// Address: 0x00401280
// Name: private: bool CLightWorldApp::SetupSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLightWorldApp::SetupSearchPaths(CLightWorldApp *this)
{
  bool result; // al
  IFileSystem_vtbl *v3; // esi
  const char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(
             this,
             pStartingDir: nullptr,
             bOnlyUseStartingDir: false,
             bIsTool: false);
  if ( result )
  {
    v3 = g_pFullFileSystem->IAppSystem::__vftable;
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    v3->AddSearchPath(this: g_pFullFileSystem, a2: GameInfoPath, a3: "SKIN", a4: PATH_ADD_TO_HEAD);
    g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "LOCAL", a4: PATH_ADD_TO_HEAD);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004012E0
// Name: public: virtual bool CLightWorldApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLightWorldApp::PreInit(CLightWorldApp *this)
{
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+4h] [ebp-4h] BYREF

  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pWorldRendererMgr == nullptr )
    return 0;
  if ( !CLightWorldApp::SetupSearchPaths(this) )
    _Warning(a1: "couldn't set paths - running with no paths.");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401350
// Name: public: virtual void CLightWorldApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightWorldApp::PostShutdown(CLightWorldApp *this)
{
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00401360
// Name: public: void CLightWorldApp::SetCanSeeSky(class IWorldRenderer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightWorldApp::SetCanSeeSky(
        CLightWorldApp *this,
        IWorldRenderer *pWorldRenderer,
        int nStartNode,
        bool bCanSeeSky)
{
  IBVHNode *v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ebx
  int i; // edi
  int v9; // eax

  v4 = pWorldRenderer->GetNode(this: pWorldRenderer, a2: nStartNode);
  v5 = v4->GetFlags(this: v4);
  if ( bCanSeeSky )
    v6 = v5 | 0x40;
  else
    v6 = v5 & 0xFFFFFFBF;
  v4->SetFlags(this: v4, a2: v6);
  v7 = v4->GetNumChildren(this: v4);
  for ( i = 0; i < v7; ++i )
  {
    v9 = v4->GetChild(this: v4, a2: i);
    CLightWorldApp::SetCanSeeSky(this, pWorldRenderer, nStartNode: v9, bCanSeeSky);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004013E0
// Name: public: SpotLightData_t::SpotLightData_t(struct SpotLightData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
SpotLightData_t *__thiscall SpotLightData_t::SpotLightData_t(SpotLightData_t *this, const SpotLightData_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401470
// Name: public: void CUtlMemory<class CPointLight,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPointLight,int>::Grow(CUtlMemory<CPointLight,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CPointLight *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CPointLight *)_g_pMemAlloc->Realloc_2(
                                         this: _g_pMemAlloc,
                                         a2: m_pMemory,
                                         a3: 60 * m_nAllocationCount);
    else
      this->m_pMemory = (CPointLight *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 60 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401520
// Name: public: void CUtlMemory<class CHemiLight,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CHemiLight,int>::Grow(CUtlMemory<CHemiLight,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CHemiLight *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 80 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CHemiLight *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CHemiLight *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004015C0
// Name: public: void CUtlMemory<class CSpotLight,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSpotLight,int>::Grow(CUtlMemory<CSpotLight,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSpotLight *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 88 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSpotLight *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CSpotLight *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401650
// Name: public: void CUtlMemory<class CBVHDictionaryEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBVHDictionaryEntry,int>::Grow(CUtlMemory<CBVHDictionaryEntry,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBVHDictionaryEntry *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 104 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBVHDictionaryEntry *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBVHDictionaryEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004016E0
// Name: float FindFarthestIntersection(class Vector __near &,class CUniformSampler __near &,class CUtlVector<class RayTracingEnvironment __near *,class CUtlMemory<class RayTracingEnvironment __near *,int>> __near &,class CUtlVector<class IWorldTraversal __near *,class CUtlMemory<class IWorldTraversal __near *,int>> __near *,float,class Vector __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
double __usercall FindFarthestIntersection@<st0>(
        int a1@<ebp>,
        Vector *vPoint,
        CUniformSampler *sampler,
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *kdTrees,
        CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *pTraversals,
        float flTraceLength,
        Vector *vDirection,
        float flCosAngle,
        bool bUseAngle)
{
  float v9; // esi
  RayTracingEnvironment *v10; // edi
  float v11; // eax
  IWorldTraversal *v12; // ecx
  Vector *(__thiscall *GetOrigin)(IWorldTraversal *, Vector *); // edx
  float *v14; // eax
  float v15; // xmm6_4
  float v16; // xmm5_4
  int v17; // xmm4_4
  RayTracingSingleResult *v18; // esi
  int v19; // edi
  float z; // edx
  float y; // xmm3_4
  float x; // xmm2_4
  float v23; // xmm7_4
  RayTracingSingleResult *v24; // esi
  int v25; // edi
  float v26; // edx
  int v27; // edi
  float *p_y; // ecx
  int v29; // eax
  unsigned int v30; // edx
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float *v35; // eax
  float v36; // xmm0_4
  RayTracingEnvironment *v37; // edi
  float *v38; // xmm0_4
  int v39; // edx
  unsigned int v40; // eax
  float *v41; // ecx
  float v42; // xmm1_4
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm1_4
  _BYTE v47[12]; // [esp-Ch] [ebp-41Ch] BYREF
  RayStream rayStream; // [esp+0h] [ebp-410h] BYREF
  Vector v49; // [esp+3A8h] [ebp-68h] BYREF
  Vector v50; // [esp+3B4h] [ebp-5Ch] BYREF
  Vector vEnd; // [esp+3C0h] [ebp-50h]
  __int64 v52; // [esp+3CCh] [ebp-44h]
  float v53; // [esp+3D4h] [ebp-3Ch]
  Vector vSampleDirection; // [esp+3D8h] [ebp-38h] BYREF
  int nTrees; // [esp+3E4h] [ebp-2Ch]
  Vector vShiftedOrigin; // [esp+3E8h] [ebp-28h]
  RayTracingEnvironment *pKDTree; // [esp+3F4h] [ebp-1Ch]
  int t; // [esp+3F8h] [ebp-18h]
  int nSamples; // [esp+3FCh] [ebp-14h]
  float *pMinDists; // [esp+400h] [ebp-10h]
  int v61; // [esp+404h] [ebp-Ch]
  void *v62; // [esp+408h] [ebp-8h]
  void *retaddr; // [esp+410h] [ebp+0h]

  v61 = a1;
  v62 = retaddr;
  v9 = *(float *)&sampler->m_NumSamples;
  *(float *)&pMinDists = -1.0;
  vShiftedOrigin.z = v9;
  nSamples = (int)operator new(nSize: 24 * LODWORD(v9));
  v10 = (RayTracingEnvironment *)operator new(nSize: 4 * LODWORD(v9));
  pKDTree = v10;
  if ( SLODWORD(v9) > 0 )
    memset32(v10, 2139095039, LODWORD(v9));
  v11 = 0.0;
  LODWORD(vSampleDirection.x) = kdTrees->m_Size;
  vShiftedOrigin.y = 0.0;
  if ( SLODWORD(vSampleDirection.x) > 0 )
  {
    while ( 1 )
    {
      v12 = pTraversals->m_Memory.m_pMemory[LODWORD(v11)];
      GetOrigin = v12->GetOrigin;
      LODWORD(vShiftedOrigin.x) = kdTrees->m_Memory.m_pMemory[LODWORD(v11)];
      v14 = (float *)GetOrigin(this: v12, result: (Vector *)&rayStream.PendingRays[7].direction.z.m128_u32[3]);
      v15 = *v14 + vPoint->x;
      vSampleDirection.y = v15;
      v16 = v14[1] + vPoint->y;
      vSampleDirection.z = v16;
      *(float *)&v17 = v14[2] + vPoint->z;
      nTrees = v17;
      memset(&rayStream.PendingStreamOutputs[7][1], 0, 32);
      if ( bUseAngle )
      {
        if ( SLODWORD(v9) <= 0 )
          goto LABEL_18;
        v18 = (RayTracingSingleResult *)nSamples;
        v19 = 0;
        t = LODWORD(vShiftedOrigin.z);
        do
        {
          z = sampler->m_pvDirections[v19].z;
          y = vDirection->y;
          x = vDirection->x;
          v23 = vDirection->z;
          v52 = *(_QWORD *)&sampler->m_pvDirections[v19].x;
          v53 = z;
          if ( (float)((float)((float)(y * *((float *)&v52 + 1)) + (float)(x * *(float *)&v52)) + (float)(v23 * z)) > flCosAngle )
          {
            v50.x = (float)(*(float *)&v52 * flTraceLength) + v15;
            v50.y = (float)(*((float *)&v52 + 1) * flTraceLength) + v16;
            v50.z = (float)(z * flTraceLength) + *(float *)&v17;
            RayTracingEnvironment::AddToRayStream(
              this: (RayTracingEnvironment *)LODWORD(vShiftedOrigin.x),
              s: (RayStream *)v47,
              start: (Vector *)&vSampleDirection.y,
              end: &v50,
              rslt_out: v18,
              cullMode: RTE_CULL_NONE);
            v17 = nTrees;
            v16 = vSampleDirection.z;
            v15 = vSampleDirection.y;
          }
          ++v19;
          ++v18;
          --t;
        }
        while ( t != 0 );
      }
      else
      {
        if ( SLODWORD(v9) <= 0 )
          goto LABEL_18;
        v24 = (RayTracingSingleResult *)nSamples;
        v25 = 0;
        t = LODWORD(vShiftedOrigin.z);
        while ( 1 )
        {
          v26 = sampler->m_pvDirections[v25].z;
          *(_QWORD *)&vEnd.x = *(_QWORD *)&sampler->m_pvDirections[v25].x;
          vEnd.z = v26;
          v49.x = (float)(vEnd.x * flTraceLength) + v15;
          v49.y = (float)(vEnd.y * flTraceLength) + v16;
          v49.z = (float)(v26 * flTraceLength) + *(float *)&v17;
          RayTracingEnvironment::AddToRayStream(
            this: (RayTracingEnvironment *)LODWORD(vShiftedOrigin.x),
            s: (RayStream *)v47,
            start: (Vector *)&vSampleDirection.y,
            end: &v49,
            rslt_out: v24,
            cullMode: RTE_CULL_NONE);
          ++v25;
          ++v24;
          if ( --t == 0 )
            break;
          v17 = nTrees;
          v16 = vSampleDirection.z;
          v15 = vSampleDirection.y;
        }
      }
      v9 = vShiftedOrigin.z;
LABEL_18:
      RayTracingEnvironment::FinishRayStream(
        this: (RayTracingEnvironment *)LODWORD(vShiftedOrigin.x),
        s: (RayStream *)v47,
        cullMode: RTE_CULL_NONE);
      v27 = 0;
      if ( SLODWORD(v9) >= 4 )
      {
        p_y = &pKDTree->m_MinBound.y;
        v29 = nSamples + 16;
        v30 = ((unsigned int)(LODWORD(v9) - 4) >> 2) + 1;
        v27 = 4 * v30;
        do
        {
          if ( *(int *)(v29 - 4) > -1 )
          {
            v31 = *(p_y - 2);
            if ( *(float *)v29 <= v31 )
              v31 = *(float *)v29;
            *(p_y - 2) = v31;
          }
          if ( *(int *)(v29 + 20) > -1 )
          {
            v32 = *(p_y - 1);
            if ( *(float *)(v29 + 24) <= v32 )
              v32 = *(float *)(v29 + 24);
            *(p_y - 1) = v32;
          }
          if ( *(int *)(v29 + 44) > -1 )
          {
            v33 = *p_y;
            if ( *(float *)(v29 + 48) <= *p_y )
              v33 = *(float *)(v29 + 48);
            *p_y = v33;
          }
          if ( *(int *)(v29 + 68) > -1 )
          {
            v34 = p_y[1];
            if ( *(float *)(v29 + 72) <= v34 )
              v34 = *(float *)(v29 + 72);
            p_y[1] = v34;
          }
          p_y += 4;
          v29 += 96;
          --v30;
        }
        while ( v30 != 0 );
      }
      if ( v27 < SLODWORD(v9) )
      {
        v35 = (float *)(nSamples + 24 * v27 + 16);
        do
        {
          if ( *((int *)v35 - 1) > -1 )
          {
            v36 = *((float *)&pKDTree->Flags + v27);
            if ( *v35 <= v36 )
              v36 = *v35;
            *((float *)&pKDTree->Flags + v27) = v36;
          }
          ++v27;
          v35 += 6;
        }
        while ( v27 < SLODWORD(v9) );
      }
      ++LODWORD(vShiftedOrigin.y);
      if ( SLODWORD(vShiftedOrigin.y) >= SLODWORD(vSampleDirection.x) )
        break;
      v11 = vShiftedOrigin.y;
    }
  }
  v37 = pKDTree;
  v38 = pMinDists;
  v39 = 0;
  if ( SLODWORD(v9) >= 4 )
  {
    v40 = ((unsigned int)(LODWORD(v9) - 4) >> 2) + 1;
    v41 = &pKDTree->m_MinBound.y;
    v39 = 4 * v40;
    do
    {
      v42 = *(v41 - 2);
      if ( v42 < 3.4028235e38 && *(float *)&v38 <= v42 )
        v38 = *((float **)v41 - 2);
      v43 = *(v41 - 1);
      if ( v43 < 3.4028235e38 && *(float *)&v38 <= v43 )
        v38 = *((float **)v41 - 1);
      if ( *v41 < 3.4028235e38 && *(float *)&v38 <= *v41 )
        v38 = *(float **)v41;
      v44 = v41[1];
      if ( v44 < 3.4028235e38 && *(float *)&v38 <= v44 )
        v38 = *((float **)v41 + 1);
      v41 += 4;
      --v40;
    }
    while ( v40 != 0 );
    pMinDists = v38;
  }
  if ( v39 < SLODWORD(v9) )
  {
    do
    {
      v45 = *((float *)&pKDTree->Flags + v39);
      if ( v45 < 3.4028235e38 && *(float *)&v38 <= v45 )
        v38 = *((float **)&pKDTree->Flags + v39);
      ++v39;
    }
    while ( v39 < SLODWORD(v9) );
    pMinDists = v38;
  }
  free(pMem: (void *)nSamples);
  free(pMem: v37);
  return *(float *)&pMinDists;
}

//------------------------------------------------------------------------------
// Address: 0x00401B00
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_446B3C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_446B3C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00401B60
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_446B3C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00401BC0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_446B3C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00401C20
// Name: public: CUtlVector<class RayTracingEnvironment __near *,class CUtlMemory<class RayTracingEnvironment __near *,int>>::~CUtlVector<class RayTracingEnvironment __near *,class CUtlMemory<class RayTracingEnvironment __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C90
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401D40
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_446B3C = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_446B3C = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401E10
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // si
  int v4; // edx
  int result; // eax
  int *v6; // ecx
  int v7; // edx
  int *v8; // ecx
  int v9; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402000
// Name: public: void CLightWorldApp::CreatePointLight(class IWorldRenderer __near *,class Vector __near &,float,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightWorldApp::CreatePointLight(
        CLightWorldApp *this,
        IWorldRenderer *pWorldRenderer,
        Vector *vOrigin,
        float flRadius,
        float flMaxDistance,
        Vector *vColor,
        Vector *vAttenuation)
{
  IWorldRenderer *v8; // edi
  int v9; // eax
  int v10; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPointLight *m_pMemory; // ecx
  int v14; // eax
  int v15; // eax
  CPointLight *v16; // eax
  __int64 pointLight; // [esp+8h] [ebp-44h]
  float pointLight_8; // [esp+10h] [ebp-3Ch]
  int nNode; // [esp+58h] [ebp+Ch]
  Vector pointLight_12; // 0:^24.12
  Vector pointLight_28; // 0:^34.12

  v8 = pWorldRenderer;
  v9 = pWorldRenderer->GetLeafNodeForPoint(this: pWorldRenderer, a2: vOrigin);
  nNode = v9;
  if ( v9 > -1 )
  {
    while ( 1 )
    {
      v10 = (int)v8->GetNode(this: v8, a2: v9);
      if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10) & 0x10) == 0 )
      {
        m_Size = this->m_pointLights.m_Size;
        pointLight = *(_QWORD *)&vOrigin->x;
        pointLight_8 = vOrigin->z;
        pointLight_12 = *vColor;
        pointLight_28 = *vAttenuation;
        m_nAllocationCount = this->m_pointLights.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CPointLight,int>::Grow(this: &this->m_pointLights.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++this->m_pointLights.m_Size;
        m_pMemory = this->m_pointLights.m_Memory.m_pMemory;
        v14 = this->m_pointLights.m_Size - m_Size - 1;
        this->m_pointLights.m_pElements = m_pMemory;
        if ( v14 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 60 * v14);
        v15 = m_Size;
        v8 = pWorldRenderer;
        v16 = &this->m_pointLights.m_Memory.m_pMemory[v15];
        if ( v16 != nullptr )
        {
          *(_QWORD *)&v16->m_instData.m_vOrigin.x = pointLight;
          v16->m_instData.m_vOrigin.z = pointLight_8;
          *(Vector *)&v16->m_instData.m_vColorNRadius.x = pointLight_12;
          v16->m_instData.m_vColorNRadius.w = flRadius;
          v16->m_instData.m_vAttenuation = pointLight_28;
          *(_QWORD *)&v16->m_vHitNormal.x = 0;
          v16->m_nNode = nNode;
          v16->m_vHitNormal.z = 0.0;
          v16->m_flMaxDistance = flMaxDistance;
        }
      }
      nNode = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 60))(a1: v10);
      if ( nNode <= -1 )
        break;
      v9 = nNode;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004021D0
// Name: public: void CLightWorldApp::CreateHemiLight(class IWorldRenderer __near *,class Vector __near &,float,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightWorldApp::CreateHemiLight(
        CLightWorldApp *this,
        IWorldRenderer *pWorldRenderer,
        Vector *vOrigin,
        float flRadius,
        Vector *vColor,
        Vector *vAttenuation,
        Vector *vDirection)
{
  Vector *v7; // esi
  IWorldRenderer *v8; // edi
  int (__thiscall *GetLeafNodeForPoint)(IWorldRenderer *, Vector *); // edx
  int v10; // eax
  float y; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  bool v18; // cc
  int v19; // edi
  float v20; // xmm0_4
  _DWORD *v21; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // edx
  float hemiLight; // [esp+Ch] [ebp-70h]
  float hemiLight_4; // [esp+10h] [ebp-6Ch]
  float hemiLight_8; // [esp+14h] [ebp-68h]
  float hemiLight_12; // [esp+18h] [ebp-64h]
  float hemiLight_16; // [esp+1Ch] [ebp-60h]
  float hemiLight_20; // [esp+20h] [ebp-5Ch]
  float hemiLight_24; // [esp+24h] [ebp-58h]
  float hemiLight_28; // [esp+28h] [ebp-54h]
  float hemiLight_32; // [esp+2Ch] [ebp-50h]
  float hemiLight_36; // [esp+30h] [ebp-4Ch]
  float hemiLight_40; // [esp+34h] [ebp-48h]
  Vector vRight; // [esp+5Ch] [ebp-20h] BYREF
  Vector vUp; // [esp+68h] [ebp-14h] BYREF
  CLightWorldApp *v41; // [esp+74h] [ebp-8h]
  int nNode; // [esp+78h] [ebp-4h]
  IBVHNode *pNode; // [esp+98h] [ebp+1Ch]
  Vector hemiLight_48; // 0:^48.12
  Vector hemiLight_64; // 0:^58.12

  v7 = vOrigin;
  v8 = pWorldRenderer;
  GetLeafNodeForPoint = pWorldRenderer->GetLeafNodeForPoint;
  v41 = this;
  v10 = GetLeafNodeForPoint(this: pWorldRenderer, a2: vOrigin);
  y = vDirection->y;
  x = vDirection->x;
  z = vDirection->z;
  v15 = 1.0;
  v16 = (float)((float)(vDirection->x * 0.0) + (float)(y * 0.0)) + z;
  v17 = 0.0;
  nNode = v10;
  vUp.y = 0.0;
  vUp.z = 1.0;
  if ( v16 > 0.94999999 )
  {
    v17 = 1.0;
    v15 = 0.0;
    vUp.y = 1.0;
    vUp.z = 0.0;
  }
  vRight.x = (float)(y * v15) - (float)(z * v17);
  vRight.y = (float)(z * 0.0) - (float)(x * vUp.z);
  vRight.z = (float)(x * vUp.y) - (float)(y * 0.0);
  vUp.x = (float)(z * vRight.y) - (float)(y * vRight.z);
  vUp.y = (float)(x * vRight.z) - (float)(z * vRight.x);
  vUp.z = (float)(y * vRight.x) - (float)(x * vRight.y);
  VectorNormalize(vec: &vRight);
  VectorNormalize(vec: &vUp);
  VectorNormalize(vec: vDirection);
  vRight.x = vRight.x * flRadius;
  vRight.y = vRight.y * flRadius;
  vRight.z = vRight.z * flRadius;
  vUp.x = vUp.x * flRadius;
  vUp.y = vUp.y * flRadius;
  vUp.z = vUp.z * flRadius;
  vDirection->x = vDirection->x * flRadius;
  vDirection->y = vDirection->y * flRadius;
  v18 = nNode <= -1;
  vDirection->z = vDirection->z * flRadius;
  if ( !v18 )
  {
    while ( 1 )
    {
      v19 = (int)v8->GetNode(this: v8, a2: nNode);
      pNode = (IBVHNode *)v19;
      if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v19 + 4))(a1: v19) & 0x10) == 0 )
      {
        hemiLight = vRight.x;
        hemiLight_4 = vUp.x;
        hemiLight_8 = vDirection->x;
        hemiLight_12 = v7->x;
        hemiLight_16 = vRight.y;
        hemiLight_20 = vUp.y;
        hemiLight_24 = vDirection->y;
        hemiLight_28 = v7->y;
        hemiLight_32 = vRight.z;
        hemiLight_36 = vUp.z;
        hemiLight_40 = vDirection->z;
        v20 = v7->z;
        v21 = &v41->__vftable;
        m_Size = v41->m_hemiLights.m_Size;
        hemiLight_48 = *vColor;
        hemiLight_64 = *vAttenuation;
        m_nAllocationCount = v41->m_hemiLights.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CHemiLight,int>::Grow(this: &v41->m_hemiLights.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++v21[99];
        v24 = v21[96];
        v25 = v21[99] - m_Size - 1;
        v21[100] = v24;
        if ( v25 > 0 )
          _V_memmove(dest: (void *)(80 * m_Size + v24 + 80), src: (const void *)(80 * m_Size + v24), count: 80 * v25);
        v26 = v21[96] + 80 * m_Size;
        if ( v26 != 0 )
        {
          *(float *)v26 = hemiLight;
          *(float *)(v26 + 4) = hemiLight_4;
          *(float *)(v26 + 8) = hemiLight_8;
          *(float *)(v26 + 12) = hemiLight_12;
          *(float *)(v26 + 16) = hemiLight_16;
          *(float *)(v26 + 20) = hemiLight_20;
          *(float *)(v26 + 24) = hemiLight_24;
          *(float *)(v26 + 28) = hemiLight_28;
          v27 = nNode;
          *(float *)(v26 + 32) = hemiLight_32;
          *(float *)(v26 + 36) = hemiLight_36;
          *(float *)(v26 + 40) = hemiLight_40;
          *(float *)(v26 + 44) = v20;
          *(Vector *)(v26 + 48) = hemiLight_48;
          *(float *)(v26 + 60) = flRadius;
          *(Vector *)(v26 + 64) = hemiLight_64;
          *(_DWORD *)(v26 + 76) = v27;
        }
        v7 = vOrigin;
        v19 = (int)pNode;
      }
      nNode = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 60))(a1: v19);
      if ( nNode <= -1 )
        break;
      v8 = pWorldRenderer;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025A0
// Name: public: void CLightWorldApp::CreateSpotLight(class IWorldRenderer __near *,class Vector __near &,float,float,float,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightWorldApp::CreateSpotLight(
        CLightWorldApp *this,
        IWorldRenderer *pWorldRenderer,
        Vector *vOrigin,
        float flRadius,
        float flMaxDistance,
        float flSpotAngle,
        Vector *vColor,
        Vector *vAttenuation,
        Vector *vDirection,
        IBVHNode *vRight,
        Vector *vUp)
{
  bool v11; // cc
  Vector *v13; // esi
  Vector *v14; // edi
  float v15; // xmm0_4
  _DWORD *v16; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // edi
  float m_flMaxDistance; // xmm0_4
  long double v23; // [esp+0h] [ebp-70h]
  long double v24; // [esp+0h] [ebp-70h]
  long double v25; // [esp+0h] [ebp-70h]
  CSpotLight spotLight; // [esp+Ch] [ebp-64h] BYREF
  CLightWorldApp *v27; // [esp+64h] [ebp-Ch]
  float v28; // [esp+68h] [ebp-8h]
  int nNode; // [esp+6Ch] [ebp-4h]
  IBVHNode *pNode; // [esp+98h] [ebp+28h]

  v27 = this;
  nNode = pWorldRenderer->GetLeafNodeForPoint(this: pWorldRenderer, a2: vOrigin);
  __libm_sse2_tan(x: v23);
  v28 = flSpotAngle;
  __libm_sse2_tan(x: v24);
  v11 = nNode <= -1;
  v13 = vUp;
  v14 = vDirection;
  v15 = (float)(flSpotAngle / (float)0.7853981852531433) * flRadius;
  *(float *)&vRight->__vftable = *(float *)&vRight->__vftable * v15;
  *(float *)&vRight[1].__vftable = *(float *)&vRight[1].__vftable * v15;
  *(float *)&vRight[2].__vftable = *(float *)&vRight[2].__vftable * v15;
  vUp->x = v15 * vUp->x;
  vUp->y = vUp->y * v15;
  vUp->z = vUp->z * v15;
  vDirection->x = vDirection->x * flRadius;
  vDirection->y = vDirection->y * flRadius;
  vDirection->z = vDirection->z * flRadius;
  if ( !v11 )
  {
    do
    {
      pNode = pWorldRenderer->GetNode(this: pWorldRenderer, a2: nNode);
      if ( (pNode->GetFlags(this: pNode) & 0x10) == 0 )
      {
        spotLight.m_flMaxDistance = flMaxDistance;
        LODWORD(spotLight.m_instData.m_vTransform0.x) = (IBVHNode)vRight->__vftable;
        spotLight.m_instData.m_vTransform0.y = v13->x;
        spotLight.m_instData.m_vTransform0.z = v14->x;
        spotLight.m_instData.m_vTransform0.w = vOrigin->x;
        LODWORD(spotLight.m_instData.m_vTransform1.x) = (IBVHNode)vRight[1].__vftable;
        spotLight.m_instData.m_vTransform1.y = v13->y;
        spotLight.m_instData.m_vTransform1.z = v14->y;
        spotLight.m_instData.m_vTransform1.w = vOrigin->y;
        LODWORD(spotLight.m_instData.m_vTransform2.x) = (IBVHNode)vRight[2].__vftable;
        spotLight.m_instData.m_vTransform2.y = v13->z;
        spotLight.m_instData.m_vTransform2.z = v14->z;
        spotLight.m_instData.m_vTransform2.w = vOrigin->z;
        spotLight.m_instData.m_vColorNRadius.x = vColor->x;
        spotLight.m_instData.m_vColorNRadius.y = vColor->y;
        spotLight.m_instData.m_vColorNRadius.z = vColor->z;
        spotLight.m_instData.m_vColorNRadius.w = flRadius;
        spotLight.m_instData.m_vAttenuationNCosSpot.x = vAttenuation->x;
        spotLight.m_instData.m_vAttenuationNCosSpot.y = vAttenuation->y;
        spotLight.m_instData.m_vAttenuationNCosSpot.z = vAttenuation->z;
        spotLight.m_nNode = nNode;
        __libm_sse2_cos(x: v25);
        v16 = &v27->__vftable;
        m_Size = v27->m_spotLights.m_Size;
        m_nAllocationCount = v27->m_spotLights.m_Memory.m_nAllocationCount;
        spotLight.m_instData.m_vAttenuationNCosSpot.w = flSpotAngle;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CSpotLight,int>::Grow(this: &v27->m_spotLights.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++v16[104];
        v19 = v16[101];
        v20 = v16[104] - m_Size - 1;
        v16[105] = v19;
        if ( v20 > 0 )
          _V_memmove(dest: (void *)(88 * m_Size + v19 + 88), src: (const void *)(88 * m_Size + v19), count: 88 * v20);
        v21 = v16[101] + 88 * m_Size;
        if ( v21 != 0 )
        {
          SpotLightData_t::SpotLightData_t(this: (SpotLightData_t *)v21, __that: &spotLight.m_instData);
          m_flMaxDistance = spotLight.m_flMaxDistance;
          *(_DWORD *)(v21 + 80) = spotLight.m_nNode;
          *(float *)(v21 + 84) = m_flMaxDistance;
        }
        v13 = vUp;
        v14 = vDirection;
      }
      nNode = pNode->GetParent(this: pNode);
    }
    while ( nNode > -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402840
// Name: public: void CLightWorldApp::ShootLights(class Vector __near &,class Vector __near &,class Vector __near &,class CUniformSampler __near &,int,class CUtlVector<class RayTracingEnvironment __near *,class CUtlMemory<class RayTracingEnvironment __near *,int>> __near &,class CUtlVector<class IWorldTraversal __near *,class CUtlMemory<class IWorldTraversal __near *,int>> __near *,float,float,class Vector __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CLightWorldApp::ShootLights(
        CLightWorldApp *this@<ecx>,
        float a2@<ebp>,
        Vector *vPoint,
        Vector *vColor,
        Vector *vAttenuation,
        CUniformSampler *sampler,
        int iVariation,
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *kdTrees,
        CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *pTraversals,
        float flTraceLength,
        float flPushBack,
        Vector *vDirection,
        float flCosAngle,
        bool bUseAngle)
{
  int m_NumSamples; // esi
  void *v15; // edi
  int v16; // eax
  IWorldTraversal *v17; // ecx
  Vector *(__thiscall *GetOrigin)(IWorldTraversal *, Vector *); // edx
  float *v19; // eax
  float v20; // xmm6_4
  float v21; // xmm5_4
  int v22; // xmm4_4
  int v23; // edi
  __int64 v25; // xmm0_8
  float z; // ecx
  float x; // xmm3_4
  float y; // xmm2_4
  float v29; // xmm7_4
  RayTracingSingleResult *v30; // esi
  float v31; // edx
  int v32; // edi
  float *v33; // edx
  float *v34; // ecx
  float *v35; // eax
  unsigned int v36; // esi
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  float *v41; // ecx
  float *v42; // eax
  int v43; // edx
  float v44; // eax
  float v45; // xmm1_4
  float v46; // xmm0_4
  __int64 v47; // xmm2_8
  int v48; // eax
  Vector *m_pvDirections; // ecx
  float v50; // xmm4_4
  float v51; // xmm5_4
  int v52; // eax
  __int64 v53; // xmm2_8
  float v54; // eax
  float v55; // xmm4_4
  float v56; // xmm5_4
  float v57; // xmm6_4
  float v58; // xmm1_4
  float v59; // xmm5_4
  float v60; // xmm3_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // xmm1_4
  float v64; // xmm4_4
  float v65; // xmm7_4
  _DWORD *v66; // edi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  float v69; // xmm5_4
  float v70; // xmm6_4
  int v71; // ecx
  int v72; // eax
  int v73; // eax
  int v74; // eax
  float v75; // ecx
  float v76; // xmm0_4
  float v77; // ecx
  unsigned __int64 v78; // xmm0_8
  __int64 v79; // xmm0_8
  int v80; // ecx
  _BYTE v81[12]; // [esp-Ch] [ebp-46Ch] BYREF
  RayStream rayStream; // [esp+0h] [ebp-460h] BYREF
  __int64 v83; // [esp+3A8h] [ebp-B8h]
  float v84; // [esp+3B0h] [ebp-B0h]
  unsigned __int64 v85; // [esp+3C4h] [ebp-9Ch]
  float v86; // [esp+3CCh] [ebp-94h]
  __int64 v87; // [esp+3D4h] [ebp-8Ch]
  int v88; // [esp+3DCh] [ebp-84h]
  int v89; // [esp+3E0h] [ebp-80h]
  Vector v90; // [esp+3E4h] [ebp-7Ch] BYREF
  float v91; // [esp+3F0h] [ebp-70h]
  float v92; // [esp+3F4h] [ebp-6Ch]
  float v93; // [esp+3F8h] [ebp-68h]
  CLightWorldApp *v94; // [esp+3FCh] [ebp-64h]
  float v95; // [esp+400h] [ebp-60h]
  __int64 v96; // [esp+404h] [ebp-5Ch]
  float flIntensity; // [esp+40Ch] [ebp-54h]
  Vector vOrigin; // [esp+410h] [ebp-50h]
  Vector vNewColor; // [esp+41Ch] [ebp-44h] BYREF
  Vector vSamplerDir; // [esp+428h] [ebp-38h]
  int nTrees; // [esp+434h] [ebp-2Ch]
  float *pMinDists; // [esp+438h] [ebp-28h]
  float v103; // [esp+43Ch] [ebp-24h]
  int nSamples; // [esp+440h] [ebp-20h]
  int v105; // [esp+444h] [ebp-1Ch]
  __int64 v106; // [esp+448h] [ebp-18h] OVERLAPPED BYREF
  int s; // [esp+450h] [ebp-10h]
  Vector vHitNormal; // [esp+454h] [ebp-Ch]
  float retaddr; // [esp+460h] [ebp+0h]

  vHitNormal.x = a2;
  vHitNormal.y = retaddr;
  m_NumSamples = sampler->m_NumSamples;
  v94 = this;
  nTrees = m_NumSamples;
  *(float *)&pMinDists = COERCE_FLOAT(operator new(nSize: 24 * m_NumSamples));
  v15 = operator new(nSize: 4 * m_NumSamples);
  LODWORD(vSamplerDir.y) = v15;
  LODWORD(vSamplerDir.z) = operator new(nSize: 12 * m_NumSamples);
  v95 = 1.0 / (float)m_NumSamples;
  if ( m_NumSamples > 0 )
    memset32(v15, 2139095039, m_NumSamples);
  v16 = 0;
  LODWORD(vSamplerDir.x) = kdTrees->m_Size;
  v105 = 0;
  if ( SLODWORD(vSamplerDir.x) > 0 )
  {
    while ( 1 )
    {
      v17 = pTraversals->m_Memory.m_pMemory[v16];
      GetOrigin = v17->GetOrigin;
      nSamples = (int)kdTrees->m_Memory.m_pMemory[v16];
      v19 = (float *)GetOrigin(this: v17, result: (Vector *)&rayStream.PendingRays[7].direction.z.m128_u32[3]);
      v20 = vPoint->x + *v19;
      *(float *)&v106 = v20;
      v21 = v19[1] + vPoint->y;
      *((float *)&v106 + 1) = v21;
      *(float *)&v22 = v19[2] + vPoint->z;
      v23 = 0;
      s = v22;
      memset(&rayStream.PendingStreamOutputs[7][1], 0, 32);
      if ( bUseAngle )
      {
        if ( m_NumSamples > 0 )
        {
          v103 = *(float *)&pMinDists;
          do
          {
            v25 = *(_QWORD *)&sampler->m_pvDirections[v23 + iVariation * sampler->m_NumSamples].x;
            z = sampler->m_pvDirections[v23 + iVariation * sampler->m_NumSamples].z;
            x = vDirection->x;
            y = vDirection->y;
            v29 = vDirection->z;
            *(_QWORD *)&vOrigin.x = v25;
            vOrigin.z = z;
            if ( (float)((float)((float)(x * *(float *)&v25) + (float)(y * *((float *)&v25 + 1))) + (float)(v29 * z)) > flCosAngle )
            {
              vNewColor.x = (float)(*(float *)&v25 * flTraceLength) + v20;
              vNewColor.y = (float)(*((float *)&v25 + 1) * flTraceLength) + v21;
              vNewColor.z = *(float *)&v22 + (float)(z * flTraceLength);
              RayTracingEnvironment::AddToRayStream(
                this: (RayTracingEnvironment *)nSamples,
                s: (RayStream *)v81,
                start: (const Vector *)&v106,
                end: &vNewColor,
                rslt_out: (RayTracingSingleResult *)LODWORD(v103),
                cullMode: RTE_CULL_NONE);
              v22 = s;
              v21 = *((float *)&v106 + 1);
              v20 = *(float *)&v106;
            }
            LODWORD(v103) += 24;
            ++v23;
          }
          while ( v23 < m_NumSamples );
        }
      }
      else if ( m_NumSamples > 0 )
      {
        v30 = (RayTracingSingleResult *)pMinDists;
        while ( 1 )
        {
          v31 = sampler->m_pvDirections[v23 + iVariation * sampler->m_NumSamples].z;
          v96 = *(_QWORD *)&sampler->m_pvDirections[v23 + iVariation * sampler->m_NumSamples].x;
          flIntensity = v31;
          v90.x = (float)(*(float *)&v96 * flTraceLength) + v20;
          v90.y = (float)(*((float *)&v96 + 1) * flTraceLength) + v21;
          v90.z = (float)(v31 * flTraceLength) + *(float *)&v22;
          RayTracingEnvironment::AddToRayStream(
            this: (RayTracingEnvironment *)nSamples,
            s: (RayStream *)v81,
            start: (const Vector *)&v106,
            end: &v90,
            rslt_out: v30,
            cullMode: RTE_CULL_NONE);
          ++v23;
          ++v30;
          if ( v23 >= nTrees )
            break;
          v22 = s;
          v21 = *((float *)&v106 + 1);
          v20 = *(float *)&v106;
        }
        m_NumSamples = nTrees;
      }
      RayTracingEnvironment::FinishRayStream(
        this: (RayTracingEnvironment *)nSamples,
        s: (RayStream *)v81,
        cullMode: RTE_CULL_NONE);
      v32 = 0;
      if ( m_NumSamples >= 4 )
      {
        v33 = (float *)(LODWORD(vSamplerDir.y) + 8);
        v34 = (float *)(LODWORD(vSamplerDir.z) + 20);
        v35 = pMinDists + 8;
        v36 = ((unsigned int)(m_NumSamples - 4) >> 2) + 1;
        v32 = 4 * v36;
        do
        {
          if ( *((int *)v35 - 5) > -1 )
          {
            v37 = *(v35 - 4);
            if ( *(v33 - 2) > v37 )
            {
              *(v33 - 2) = v37;
              *(v34 - 5) = *(v35 - 8);
              *(v34 - 4) = *(v35 - 7);
              *(v34 - 3) = *(v35 - 6);
            }
          }
          if ( *((int *)v35 + 1) > -1 )
          {
            v38 = v35[2];
            if ( *(v33 - 1) > v38 )
            {
              *(v33 - 1) = v38;
              *(v34 - 2) = *(v35 - 2);
              *(v34 - 1) = *(v35 - 1);
              *v34 = *v35;
            }
          }
          if ( *((int *)v35 + 7) > -1 )
          {
            v39 = v35[8];
            if ( *v33 > v39 )
            {
              *v33 = v39;
              v34[1] = v35[4];
              v34[2] = v35[5];
              v34[3] = v35[6];
            }
          }
          if ( *((int *)v35 + 13) > -1 )
          {
            v40 = v35[14];
            if ( v33[1] > v40 )
            {
              v33[1] = v40;
              v34[4] = v35[10];
              v34[5] = v35[11];
              v34[6] = v35[12];
            }
          }
          v33 += 4;
          v34 += 12;
          v35 += 24;
          --v36;
        }
        while ( v36 != 0 );
        m_NumSamples = nTrees;
      }
      if ( v32 < m_NumSamples )
      {
        v41 = (float *)(LODWORD(vSamplerDir.z) + 12 * v32 + 8);
        v42 = &pMinDists[6 * v32 + 4];
        do
        {
          if ( *((int *)v42 - 1) > -1 && *(float *)(LODWORD(vSamplerDir.y) + 4 * v32) > *v42 )
          {
            *(float *)(LODWORD(vSamplerDir.y) + 4 * v32) = *v42;
            *(v41 - 2) = *(v42 - 4);
            *(v41 - 1) = *(v42 - 3);
            *v41 = *(v42 - 2);
          }
          ++v32;
          v42 += 6;
          v41 += 3;
        }
        while ( v32 < m_NumSamples );
      }
      if ( ++v105 >= SLODWORD(vSamplerDir.x) )
        break;
      v16 = v105;
    }
  }
  v43 = 0;
  v105 = 0;
  if ( m_NumSamples > 0 )
  {
    v44 = vSamplerDir.z;
    v45 = flPushBack;
    v103 = vSamplerDir.z;
    do
    {
      v46 = *(float *)(LODWORD(vSamplerDir.y) + 4 * v43);
      if ( v46 < 3.4028235e38 && v46 > 30.0 )
      {
        v47 = *(_QWORD *)LODWORD(v44);
        s = *(int *)(LODWORD(v44) + 8);
        v48 = iVariation * sampler->m_NumSamples;
        m_pvDirections = sampler->m_pvDirections;
        v106 = v47;
        v50 = *(float *)&v47;
        v51 = *((float *)&v47 + 1);
        v52 = v43 + v48;
        v53 = *(_QWORD *)&m_pvDirections[v52].x;
        v54 = m_pvDirections[v52].z;
        *(_QWORD *)&vNewColor.x = v53;
        v55 = v50 * v45;
        v56 = v51 * v45;
        v57 = *(float *)&s * v45;
        vNewColor.z = v54;
        v58 = vPoint->x + (float)(*(float *)&v53 * v46);
        *(float *)&v53 = (float)(vPoint->y + (float)(*((float *)&v53 + 1) * v46)) + v56;
        v59 = vAttenuation->z;
        v60 = (float)(vPoint->z + (float)(v54 * v46)) + v57;
        HIDWORD(v96) = v53;
        v61 = flTraceLength - v46;
        flIntensity = v60;
        v62 = vAttenuation->y;
        *(float *)&v96 = v58 + v55;
        v63 = vAttenuation->x;
        v64 = 1.0 / (float)((float)((float)(v46 * v62) + vAttenuation->x) + (float)((float)(v46 * v46) * v59));
        vSamplerDir.x = -vNewColor.x;
        v93 = v59;
        v92 = -vNewColor.y;
        v91 = -v54;
        *(float *)&nSamples = flTraceLength - v46;
        if ( (float)((float)((float)((float)-vNewColor.y * *((float *)&v106 + 1))
                           + (float)((float)-vNewColor.x * *(float *)&v106))
                   + (float)((float)-v54 * *(float *)&s)) >= 0.0 )
          v65 = (float)((float)(v92 * *((float *)&v106 + 1)) + (float)(vSamplerDir.x * *(float *)&v106))
              + (float)(v91 * *(float *)&s);
        else
          v65 = 0.0;
        v66 = &v94->__vftable;
        m_Size = v94->m_virtualPointLights.m_Size;
        m_nAllocationCount = v94->m_virtualPointLights.m_Memory.m_nAllocationCount;
        v69 = vColor->y * v64;
        v70 = vColor->z * v64;
        vOrigin.x = (float)((float)(vColor->x * v64) * v65) * v95;
        v87 = v106;
        v88 = s;
        v83 = v96;
        v84 = flIntensity;
        vOrigin.y = (float)(v69 * v65) * v95;
        vOrigin.z = (float)(v70 * v65) * v95;
        v85 = __PAIR64__(LODWORD(v62), LODWORD(v63));
        v86 = v93;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CPointLight,int>::Grow(
            this: &v94->m_virtualPointLights.m_Memory,
            num: m_Size - m_nAllocationCount + 1);
          v61 = *(float *)&nSamples;
          v43 = v105;
        }
        ++v66[109];
        v71 = v66[106];
        v72 = v66[109] - m_Size - 1;
        v66[110] = v71;
        if ( v72 > 0 )
        {
          _V_memmove(dest: (void *)(v71 + 60 * m_Size + 60), src: (const void *)(v71 + 60 * m_Size), count: 60 * v72);
          v61 = *(float *)&nSamples;
          v43 = v105;
        }
        v45 = flPushBack;
        v73 = 15 * m_Size;
        m_NumSamples = nTrees;
        v74 = v66[106] + 4 * v73;
        if ( v74 != 0 )
        {
          v75 = v84;
          *(_QWORD *)v74 = v83;
          v76 = vOrigin.x;
          *(float *)(v74 + 8) = v75;
          v77 = v86;
          *(float *)(v74 + 12) = v76;
          *(float *)(v74 + 16) = vOrigin.y;
          *(float *)(v74 + 20) = vOrigin.z;
          v78 = v85;
          *(float *)(v74 + 24) = v61;
          *(_QWORD *)(v74 + 28) = v78;
          v79 = v87;
          *(float *)(v74 + 36) = v77;
          v80 = v88;
          *(_QWORD *)(v74 + 44) = v79;
          LODWORD(v79) = v89;
          *(_DWORD *)(v74 + 40) = -1;
          *(_DWORD *)(v74 + 52) = v80;
          *(_DWORD *)(v74 + 56) = v79;
        }
      }
      ++v43;
      LODWORD(v44) = LODWORD(v103) + 12;
      v105 = v43;
      LODWORD(v103) += 12;
    }
    while ( v43 < m_NumSamples );
  }
  free(pMem: pMinDists);
  free(pMem: (void *)LODWORD(vSamplerDir.y));
  free(pMem: (void *)LODWORD(vSamplerDir.z));
}

//------------------------------------------------------------------------------
// Address: 0x00402FF0
// Name: public: void CLightWorldApp::ShootVirtualPointLights(int,int,int,int,class CUtlVector<class RayTracingEnvironment __near *,class CUtlMemory<class RayTracingEnvironment __near *,int>> __near &,class CUtlVector<class IWorldTraversal __near *,class CUtlMemory<class IWorldTraversal __near *,int>> __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightWorldApp::ShootVirtualPointLights(
        CLightWorldApp *this,
        int nSqrtPointSamples,
        int nSqrtSpotSamples,
        int nSqrtBounceSamples,
        int nBounces,
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *kdTrees,
        CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *pTraversals,
        float flPushBack)
{
  int v9; // ebx
  int m_Size; // eax
  int v11; // edi
  CPointLight *m_pMemory; // eax
  float v13; // ecx
  float v14; // edx
  __int64 v15; // xmm1_8
  char *v16; // eax
  float v17; // ecx
  float v18; // xmm0_4
  __int64 v19; // xmm1_8
  int v20; // edi
  CSpotLight *v21; // eax
  float v22; // xmm0_4
  float v23; // ecx
  float *v24; // eax
  float v25; // edx
  __int64 v26; // xmm0_8
  int v27; // edx
  int v28; // edi
  CPointLight *v29; // eax
  __int64 v30; // xmm0_8
  float z; // ecx
  float v32; // edx
  CPointLight *v33; // eax
  __int64 v34; // xmm0_8
  __int64 v35; // xmm0_8
  bool v36; // zf
  float flTraceLength; // [esp+0h] [ebp-7Ch]
  float flCosAngle; // [esp+Ch] [ebp-70h]
  float flCosAnglea; // [esp+Ch] [ebp-70h]
  long double v40; // [esp+14h] [ebp-68h]
  Vector vOrigin; // [esp+20h] [ebp-5Ch] BYREF
  Vector vColor; // [esp+2Ch] [ebp-50h] BYREF
  Vector vAttenuation; // [esp+38h] [ebp-44h] BYREF
  Vector vDirection; // [esp+44h] [ebp-38h] BYREF
  CUniformSampler samplerPoint; // [esp+50h] [ebp-2Ch] BYREF
  CUniformSampler samplerCone; // [esp+5Ch] [ebp-20h] BYREF
  CUniformSampler samplerBounce; // [esp+68h] [ebp-14h] BYREF
  float flCosSpot; // [esp+74h] [ebp-8h]
  float flPassPercent; // [esp+78h] [ebp-4h]
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF
  int nVPLCount; // [esp+84h] [ebp+8h]
  int nVPLCounta; // [esp+84h] [ebp+8h]
  int nVPLCountb; // [esp+84h] [ebp+8h]
  int nBounceVar; // [esp+88h] [ebp+Ch]
  int nVPLStart; // [esp+8Ch] [ebp+10h]
  int nVPLStarta; // [esp+8Ch] [ebp+10h]
  int nBouncesa; // [esp+90h] [ebp+14h]

  v9 = 0;
  this->m_virtualPointLights.m_Memory.m_nGrowSize = 1024;
  memset(&samplerPoint, 0, sizeof(samplerPoint));
  CUniformSampler::InitSamples(this: &samplerPoint, SqrtNumSamples: nSqrtPointSamples, NumVariations: 64);
  memset(&samplerCone, 0, sizeof(samplerCone));
  CUniformSampler::InitSamples(this: &samplerCone, SqrtNumSamples: nSqrtSpotSamples, NumVariations: 64);
  memset(&samplerBounce, 0, sizeof(samplerBounce));
  CUniformSampler::InitSamples(this: &samplerBounce, SqrtNumSamples: nSqrtBounceSamples, NumVariations: 128);
  _Msg(a1: "\nShooting 1st bounce VPLs from point lights\n");
  m_Size = this->m_pointLights.m_Size;
  v11 = 0;
  if ( m_Size > 0 )
  {
    memset(&vDirection, 0, sizeof(vDirection));
    for ( nVPLCount = m_Size; nVPLCount != 0; --nVPLCount )
    {
      m_pMemory = this->m_pointLights.m_Memory.m_pMemory;
      v13 = *(float *)((char *)&m_pMemory->m_instData.m_vOrigin.z + v9);
      v14 = *(float *)((char *)&m_pMemory->m_instData.m_vColorNRadius.z + v9);
      v15 = *(_QWORD *)((char *)&m_pMemory->m_instData.m_vOrigin.x + v9);
      v16 = (char *)m_pMemory + v9;
      vOrigin.z = v13;
      v17 = *((float *)v16 + 9);
      vColor.z = v14;
      v18 = *((float *)v16 + 14);
      *(_QWORD *)&vOrigin.x = v15;
      *(_QWORD *)&vColor.x = *(_QWORD *)(v16 + 12);
      v19 = *(_QWORD *)(v16 + 28);
      vAttenuation.z = v17;
      *(_QWORD *)&vAttenuation.x = v19;
      CLightWorldApp::ShootLights(
        this,
        a2: COERCE_FLOAT(&savedregs),
        vPoint: &vOrigin,
        &vColor,
        &vAttenuation,
        sampler: &samplerPoint,
        iVariation: v11,
        kdTrees,
        pTraversals,
        flTraceLength: v18,
        flPushBack,
        &vDirection,
        flCosAngle: 0.0,
        bUseAngle: false);
      v11 = (v11 + 1) % 64;
      v9 += 60;
    }
    v9 = 0;
  }
  _Msg(a1: "\nShooting 1st bounce VPLs from spot lights\n");
  v20 = 0;
  if ( this->m_spotLights.m_Size > 0 )
  {
    nVPLCounta = this->m_spotLights.m_Size;
    do
    {
      v21 = this->m_spotLights.m_Memory.m_pMemory;
      v22 = *(float *)((char *)&v21->m_instData.m_vTransform0.w + v9);
      v23 = *(float *)((char *)&v21->m_instData.m_vColorNRadius.z + v9);
      v24 = (float *)((char *)&v21->m_instData.m_vTransform0.x + v9);
      v25 = v24[18];
      vAttenuation.x = v22;
      vAttenuation.y = v24[7];
      vAttenuation.z = v24[11];
      vDirection.x = v24[2];
      vDirection.y = v24[6];
      vDirection.z = v24[10];
      *(_QWORD *)&vColor.x = *((_QWORD *)v24 + 6);
      v26 = *((_QWORD *)v24 + 8);
      vColor.z = v23;
      *(_QWORD *)&vOrigin.x = v26;
      flCosAngle = v24[19];
      flTraceLength = v24[21];
      vOrigin.z = v25;
      CLightWorldApp::ShootLights(
        this,
        a2: COERCE_FLOAT(&savedregs),
        vPoint: &vAttenuation,
        &vColor,
        vAttenuation: &vOrigin,
        sampler: &samplerCone,
        iVariation: v20,
        kdTrees,
        pTraversals,
        flTraceLength,
        flPushBack,
        &vDirection,
        flCosAngle,
        bUseAngle: true);
      v20 = (v20 + 1) % 64;
      v9 += 88;
      --nVPLCounta;
    }
    while ( nVPLCounta != 0 );
    v9 = 0;
  }
  if ( nBounces > 1 )
  {
    _Msg(a1: "\nShooting bounces\n");
    v27 = this->m_virtualPointLights.m_Size;
    flPassPercent = 1.0 / (float)nBounces;
    nVPLCountb = v27;
    __libm_sse2_cos(x: v40);
    flCosSpot = 1.495996594429016;
    nBounceVar = 0;
    nBouncesa = nBounces - 1;
    while ( 1 )
    {
      if ( v9 < nVPLCountb )
      {
        v28 = v9;
        nVPLStart = nVPLCountb - v9;
        do
        {
          if ( flPassPercent > (float)((float)rand() * 0.000030518509) )
          {
            v29 = this->m_virtualPointLights.m_Memory.m_pMemory;
            v30 = *(_QWORD *)&v29[v28].m_instData.m_vOrigin.x;
            z = v29[v28].m_instData.m_vOrigin.z;
            v32 = v29[v28].m_vHitNormal.z;
            v33 = &v29[v28];
            *(_QWORD *)&vDirection.x = v30;
            *(_QWORD *)&vOrigin.x = *(_QWORD *)&v33->m_vHitNormal.x;
            v34 = *(_QWORD *)&v33->m_instData.m_vColorNRadius.x;
            vDirection.z = z;
            flCosAnglea = v33->m_instData.m_vColorNRadius.z;
            *(_QWORD *)&vAttenuation.x = v34;
            v35 = *(_QWORD *)&v33->m_instData.m_vAttenuation.x;
            vAttenuation.z = flCosAnglea;
            *(_QWORD *)&vColor.x = v35;
            *(float *)&v35 = v33->m_instData.m_vColorNRadius.w;
            vOrigin.z = v32;
            vColor.z = v33->m_instData.m_vAttenuation.z;
            CLightWorldApp::ShootLights(
              this,
              a2: COERCE_FLOAT(&savedregs),
              vPoint: &vDirection,
              vColor: &vAttenuation,
              vAttenuation: &vColor,
              sampler: &samplerBounce,
              iVariation: nBounceVar,
              kdTrees,
              pTraversals,
              flTraceLength: *(float *)&v35,
              flPushBack,
              vDirection: &vOrigin,
              flCosAngle: flCosSpot,
              bUseAngle: true);
            nBounceVar = (nBounceVar + 1) % 128;
          }
          ++v28;
          --nVPLStart;
        }
        while ( nVPLStart != 0 );
      }
      v36 = nBouncesa-- == 1;
      nVPLStarta = nVPLCountb;
      nVPLCountb = this->m_virtualPointLights.m_Size;
      if ( v36 )
        break;
      v9 = nVPLStarta;
    }
  }
  if ( samplerBounce.m_pvDirections != nullptr )
    free(pMem: samplerBounce.m_pvDirections);
  if ( samplerCone.m_pvDirections != nullptr )
    free(pMem: samplerCone.m_pvDirections);
  if ( samplerPoint.m_pvDirections != nullptr )
    free(pMem: samplerPoint.m_pvDirections);
}

//------------------------------------------------------------------------------
// Address: 0x004033D0
// Name: public: void CLightWorldApp::GridVPLs(class IWorldRenderer __near *,float,float,float,class CUtlVector<class RayTracingEnvironment __near *,class CUtlMemory<class RayTracingEnvironment __near *,int>> __near &,class CUtlVector<class IWorldTraversal __near *,class CUtlMemory<class IWorldTraversal __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CLightWorldApp::GridVPLs(
        CLightWorldApp *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IWorldRenderer *pWorldRenderer,
        float flGridSize,
        float flMaxRadius,
        float flBounceScale,
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *kdTrees,
        CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *pTraversals)
{
  float v10; // edi
  int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // esi
  float v15; // xmm1_4
  float v16; // xmm0_4
  int v17; // edx
  float *v18; // eax
  int v19; // ecx
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // eax
  float v23; // xmm7_4
  int v24; // edx
  __int128 v25; // xmm0
  int x_low; // eax
  float v27; // xmm1_4
  float v28; // xmm2_4
  __int128 v29; // xmm3
  _DWORD *v30; // edx
  _DWORD *v31; // ecx
  _DWORD *v32; // eax
  int i; // esi
  float v34; // ecx
  float *v35; // eax
  float v36; // xmm4_4
  float z; // xmm2_4
  float v38; // xmm1_4
  int v39; // edx
  float *v40; // eax
  CPointLight *v41; // ecx
  CPointLight *v42; // ecx
  CPointLight *v43; // eax
  float *v44; // edi
  float v45; // xmm0_4
  int v46; // ecx
  int v47; // eax
  int v48; // edx
  float v49; // xmm0_4
  float *v50; // eax
  float v51; // xmm0_4
  float *v52; // eax
  int v53; // esi
  float *v54; // ecx
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // edx
  char *v58; // eax
  float v59; // xmm1_4
  float *v60; // eax
  float v61; // ecx
  float v62; // xmm1_4
  __int64 v63; // xmm0_8
  float v64; // xmm1_4
  __int128 v65; // xmm2
  double v66; // st7
  float v67; // xmm0_4
  Vector v69; // [esp+20h] [ebp-E4h] BYREF
  Vector vDirection; // [esp+2Ch] [ebp-D8h] BYREF
  _BYTE v71[36]; // [esp+38h] [ebp-CCh] OVERLAPPED
  int v72; // [esp+5Ch] [ebp-A8h]
  int v73; // [esp+60h] [ebp-A4h]
  int v74; // [esp+64h] [ebp-A0h]
  int v75; // [esp+68h] [ebp-9Ch]
  Vector v76; // [esp+6Ch] [ebp-98h] BYREF
  __int128 vOrigin; // [esp+78h] [ebp-8Ch] OVERLAPPED BYREF
  int nLights; // [esp+88h] [ebp-7Ch]
  AABB_t bounds; // [esp+8Ch] [ebp-78h] BYREF
  Vector vPos; // [esp+A4h] [ebp-60h] BYREF
  Vector vColor; // [esp+B0h] [ebp-54h]
  float v82; // [esp+BCh] [ebp-48h]
  int flAttenDelta; // [esp+C0h] [ebp-44h]
  int v84; // [esp+C4h] [ebp-40h]
  float v85; // [esp+C8h] [ebp-3Ch]
  int nY; // [esp+CCh] [ebp-38h]
  int y; // [esp+D0h] [ebp-34h]
  float *flDrawRad; // [esp+D4h] [ebp-30h]
  float *v89; // [esp+D8h] [ebp-2Ch]
  int nX; // [esp+DCh] [ebp-28h]
  int v91; // [esp+E0h] [ebp-24h]
  __int64 x; // [esp+E4h] [ebp-20h] OVERLAPPED BYREF
  float flCosAngle; // [esp+ECh] [ebp-18h]
  Vector vAttenuation; // [esp+F0h] [ebp-14h] BYREF
  float flRadius; // [esp+FCh] [ebp-8h]
  float retaddr; // [esp+104h] [ebp+0h]

  vAttenuation.z = a2;
  flRadius = retaddr;
  v10 = *(float *)&this;
  v11 = ((int (__thiscall *)(IWorldRenderer *, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, CLightWorldApp *, _DWORD, _DWORD, int, int, _DWORD, int, int, float *, float *, int, int, _DWORD, _DWORD, _DWORD, _DWORD))pWorldRenderer->GetNode)(
          a1: pWorldRenderer,
          a2: 0,
          a3,
          a4,
          a5: LODWORD(v69.x),
          a6: LODWORD(v69.y),
          a7: LODWORD(v69.z),
          a8: LODWORD(vDirection.x),
          a9: LODWORD(vDirection.y),
          a10: LODWORD(vDirection.z),
          a11: *(_DWORD *)v71,
          a12: *(_DWORD *)&v71[4],
          a13: *(_DWORD *)&v71[8],
          a14: *(_DWORD *)&v71[12],
          a15: *(_DWORD *)&v71[16],
          a16: *(_DWORD *)&v71[20],
          a17: *(_DWORD *)&v71[24],
          a18: *(_DWORD *)&v71[28],
          a19: *(_DWORD *)&v71[32],
          a20: v72,
          a21: v73,
          a22: v74,
          a23: v75,
          a24: LODWORD(v76.x),
          a25: LODWORD(v76.y),
          a26: LODWORD(v76.z),
          a27: vOrigin,
          a28: DWORD1(vOrigin),
          a29: DWORD2(vOrigin),
          a30: HIDWORD(vOrigin),
          a31: nLights,
          a32: LODWORD(bounds.m_vMinBounds.x),
          a33: LODWORD(bounds.m_vMinBounds.y),
          a34: LODWORD(bounds.m_vMinBounds.z),
          a35: LODWORD(bounds.m_vMaxBounds.x),
          a36: LODWORD(bounds.m_vMaxBounds.y),
          a37: LODWORD(bounds.m_vMaxBounds.z),
          a38: LODWORD(vPos.x),
          a39: LODWORD(vPos.y),
          a40: LODWORD(vPos.z),
          a41: LODWORD(vColor.x),
          a42: this,
          a43: LODWORD(vColor.z),
          a44: LODWORD(v82),
          a45: flAttenDelta,
          a46: v84,
          a47: LODWORD(v85),
          a48: nY,
          a49: y,
          a50: flDrawRad,
          a51: v89,
          a52: nX,
          a53: v91,
          a54: x,
          a55: HIDWORD(x),
          a56: LODWORD(flCosAngle),
          a57: LODWORD(vAttenuation.x));
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v11 + 16))(a1: v11, a2: (char *)&vOrigin + 8);
  *((float *)&x + 1) = bounds.m_vMinBounds.y - *((float *)&vOrigin + 3);
  flCosAngle = bounds.m_vMinBounds.z - *(float *)&nLights;
  v12 = 1.0 / flGridSize;
  v13 = (float)(1.0 / flGridSize) * (float)(bounds.m_vMinBounds.x - *((float *)&vOrigin + 2));
  *(float *)&x = bounds.m_vMinBounds.x - *((float *)&vOrigin + 2);
  if ( v13 < 1.0 )
    v13 = 1.0;
  v14 = (int)v13;
  v15 = v12 * *((float *)&x + 1);
  y = v14;
  if ( (float)(v12 * *((float *)&x + 1)) < 1.0 )
    v15 = 1.0;
  v16 = v12 * flCosAngle;
  flAttenDelta = (int)v15;
  if ( v16 < 1.0 )
    v16 = 1.0;
  v17 = *(_DWORD *)(LODWORD(v10) + 436);
  nX = (int)v16;
  DWORD1(vOrigin) = v17;
  *((float *)&vOrigin + 2) = *((float *)&vOrigin + 2) - 0.0099999998;
  *((float *)&vOrigin + 3) = *((float *)&vOrigin + 3) - 0.0099999998;
  *(float *)&nLights = *(float *)&nLights - 0.0099999998;
  bounds.m_vMinBounds.x = bounds.m_vMinBounds.x + 0.0099999998;
  bounds.m_vMinBounds.y = bounds.m_vMinBounds.y + 0.0099999998;
  bounds.m_vMinBounds.z = bounds.m_vMinBounds.z + 0.0099999998;
  v18 = (float *)operator new(nSize: 336 * v14 * (int)v15 * (int)v16);
  v19 = nX;
  v20 = flCosAngle / (float)nX;
  v21 = *((float *)&x + 1) / (float)flAttenDelta;
  flDrawRad = v18;
  vPos.z = v20;
  vPos.y = v21;
  vPos.x = *(float *)&x / (float)v14;
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    vPlaneDirs[0].x = 1.0;
    dword_446B4C = 0;
    dword_446B50 = 0;
    dword_446B54 = -1082130432;
    dword_446B58 = 0;
    dword_446B5C = 0;
    dword_446B60 = 0;
    dword_446B64 = 1065353216;
    dword_446B68 = 0;
    dword_446B6C = 0;
    dword_446B70 = -1082130432;
    dword_446B74 = 0;
    dword_446B78 = 0;
    dword_446B7C = 0;
    dword_446B80 = 1065353216;
    dword_446B84 = 0;
    dword_446B88 = 0;
    dword_446B8C = -1082130432;
  }
  v22 = 0.0;
  vAttenuation.x = 0.0;
  x = *((_QWORD *)&vOrigin + 1);
  flCosAngle = *(float *)&nLights;
  vAttenuation.y = 0.0;
  if ( nX > 0 )
  {
    do
    {
      v23 = *((float *)&vOrigin + 3);
      HIDWORD(x) = HIDWORD(vOrigin);
      v84 = 0;
      if ( flAttenDelta > 0 )
      {
        v74 = 336 * v14;
        *(_DWORD *)&v71[32] = 28 * v14;
        v73 = 84 * v14;
        LODWORD(v82) = 28 * LODWORD(v22) + 20;
        v24 = 84 * LODWORD(v22) + 78;
        LODWORD(vColor.x) = &flDrawRad[84 * LODWORD(v22) + 62];
        do
        {
          v25 = DWORD2(vOrigin);
          LODWORD(x) = DWORD2(vOrigin);
          v89 = nullptr;
          if ( v14 > 0 )
          {
            x_low = LODWORD(vColor.x);
            LODWORD(vAttenuation.x) += v14;
            vColor.z = v82;
            v91 = v24;
            v27 = v23 + v21;
            v75 = -248 - (_DWORD)flDrawRad;
            LODWORD(v82) += *(_DWORD *)&v71[32];
            LODWORD(v85) = v73 + v24;
            LODWORD(vColor.x) += v74;
            v28 = flCosAngle + v20;
            v76.y = v27;
            v76.z = flCosAngle + v20;
            nY = x_low;
            do
            {
              v29 = v25;
              *(float *)&v29 = *(float *)&v25 + vPos.x;
              *(float *)&v71[12] = *(float *)&v25 + vPos.x;
              *(float *)&v71[16] = v27;
              *(float *)&v71[20] = v28;
              if ( v89 == (float *)(v14 - 1) )
                *(float *)&v71[12] = bounds.m_vMinBounds.x;
              if ( v84 == flAttenDelta - 1 )
                *(float *)&v71[16] = bounds.m_vMinBounds.y;
              if ( LODWORD(vAttenuation.y) == nX - 1 )
                *(float *)&v71[20] = bounds.m_vMinBounds.z;
              v30 = (_DWORD *)(nY + 64);
              v31 = (_DWORD *)nY;
              v32 = (_DWORD *)(nY - 228);
              for ( i = 6; i != 0; --i )
              {
                *v30 = 0;
                *(v31 - 2) = 0;
                *(v31 - 1) = 0;
                *v31 = 0;
                *(v32 - 5) = 0;
                *(v32 - 4) = 0;
                *(v32 - 3) = 0;
                *(v32 - 2) = 0;
                *(v32 - 1) = 0;
                *v32 = 0;
                v32[1] = 0;
                v32[2] = 0;
                v32[3] = 0;
                v32[4] = 0;
                ++v30;
                v31 += 3;
                v32 += 10;
              }
              if ( SDWORD1(vOrigin) > 0 )
              {
                v72 = nY + v75;
                LODWORD(vOrigin) = DWORD1(vOrigin);
                do
                {
                  v34 = *(float *)(*(_DWORD *)(LODWORD(v10) + 424) + i + 8);
                  v35 = (float *)(*(_DWORD *)(LODWORD(v10) + 424) + i);
                  *(_QWORD *)&bounds.m_vMaxBounds.x = *(_QWORD *)v35;
                  bounds.m_vMaxBounds.z = v34;
                  if ( bounds.m_vMaxBounds.x > *(float *)&v25 && *(float *)&v71[12] >= bounds.m_vMaxBounds.x )
                  {
                    v36 = bounds.m_vMaxBounds.y;
                    if ( bounds.m_vMaxBounds.y > v23 && *(float *)&v71[16] >= bounds.m_vMaxBounds.y )
                    {
                      z = bounds.m_vMaxBounds.z;
                      if ( bounds.m_vMaxBounds.z > flCosAngle && *(float *)&v71[20] >= bounds.m_vMaxBounds.z )
                      {
                        v38 = -1.0;
                        v39 = -1;
                        if ( (float)((float)((float)(v35[12] * *(float *)&dword_446B4C)
                                           + (float)(v35[11] * vPlaneDirs[0].x))
                                   + (float)(v35[13] * *(float *)&dword_446B50)) > -1.0 )
                        {
                          v38 = (float)((float)(v35[12] * *(float *)&dword_446B4C) + (float)(v35[11] * vPlaneDirs[0].x))
                              + (float)(v35[13] * *(float *)&dword_446B50);
                          v39 = 0;
                        }
                        if ( (float)((float)((float)(v35[12] * *(float *)&dword_446B58)
                                           + (float)(v35[11] * *(float *)&dword_446B54))
                                   + (float)(v35[13] * *(float *)&dword_446B5C)) > v38 )
                        {
                          v38 = (float)((float)(v35[12] * *(float *)&dword_446B58)
                                      + (float)(v35[11] * *(float *)&dword_446B54))
                              + (float)(v35[13] * *(float *)&dword_446B5C);
                          v39 = 1;
                        }
                        if ( (float)((float)((float)(v35[12] * *(float *)&dword_446B64)
                                           + (float)(v35[11] * *(float *)&dword_446B60))
                                   + (float)(v35[13] * *(float *)&dword_446B68)) > v38 )
                        {
                          v38 = (float)((float)(v35[12] * *(float *)&dword_446B64)
                                      + (float)(v35[11] * *(float *)&dword_446B60))
                              + (float)(v35[13] * *(float *)&dword_446B68);
                          v39 = 2;
                        }
                        if ( (float)((float)((float)(v35[12] * *(float *)&dword_446B70)
                                           + (float)(v35[11] * *(float *)&dword_446B6C))
                                   + (float)(v35[13] * *(float *)&dword_446B74)) > v38 )
                        {
                          v38 = (float)((float)(v35[12] * *(float *)&dword_446B70)
                                      + (float)(v35[11] * *(float *)&dword_446B6C))
                              + (float)(v35[13] * *(float *)&dword_446B74);
                          v39 = 3;
                        }
                        if ( (float)((float)((float)(v35[12] * *(float *)&dword_446B7C)
                                           + (float)(v35[11] * *(float *)&dword_446B78))
                                   + (float)(v35[13] * *(float *)&dword_446B80)) > v38 )
                        {
                          v38 = (float)((float)(v35[12] * *(float *)&dword_446B7C)
                                      + (float)(v35[11] * *(float *)&dword_446B78))
                              + (float)(v35[13] * *(float *)&dword_446B80);
                          v39 = 4;
                        }
                        if ( (float)((float)((float)(v35[12] * *(float *)&dword_446B88)
                                           + (float)(v35[11] * *(float *)&dword_446B84))
                                   + (float)(v35[13] * *(float *)&dword_446B8C)) > v38 )
                          v39 = 5;
                        v40 = (float *)((char *)&flDrawRad[10 * v39] + v72);
                        v23 = *((float *)&x + 1);
                        *v40 = *v40 + bounds.m_vMaxBounds.x;
                        v40[1] = v40[1] + v36;
                        v40[2] = v40[2] + z;
                        v41 = *(CPointLight **)(LODWORD(v10) + 424);
                        v40[3] = v40[3] + *(float *)((char *)&v41->m_instData.m_vColorNRadius.x + i);
                        v40[4] = *(float *)((char *)&v41->m_instData.m_vColorNRadius.y + i) + v40[4];
                        v40[5] = *(float *)((char *)&v41->m_instData.m_vColorNRadius.z + i) + v40[5];
                        v40[6] = *(float *)((char *)&v41->m_instData.m_vColorNRadius.w + i) + v40[6];
                        v42 = *(CPointLight **)(LODWORD(v10) + 424);
                        v40[7] = *(float *)((char *)&v42->m_instData.m_vAttenuation.x + i) + v40[7];
                        v40[8] = *(float *)((char *)&v42->m_instData.m_vAttenuation.y + i) + v40[8];
                        v40[9] = *(float *)((char *)&v42->m_instData.m_vAttenuation.z + i) + v40[9];
                        v43 = *(CPointLight **)(LODWORD(v10) + 424);
                        v44 = flDrawRad;
                        v45 = *(float *)((char *)&v43->m_vHitNormal.x + i);
                        v46 = (int)&v43->m_vHitNormal + i;
                        v47 = v39 + LODWORD(vColor.z);
                        v48 = v91 + v39;
                        v47 *= 3;
                        v49 = v45 + flDrawRad[v47];
                        v50 = &flDrawRad[v47];
                        *v50 = v49;
                        v50[1] = *(float *)(v46 + 4) + v50[1];
                        v50[2] = *(float *)(v46 + 8) + v50[2];
                        v51 = v44[v48] + 1.0;
                        v52 = &v44[v48];
                        v10 = vColor.y;
                        *v52 = v51;
                        LODWORD(v25) = x;
                      }
                    }
                  }
                  i += 60;
                  LODWORD(vOrigin) = vOrigin - 1;
                }
                while ( (_DWORD)vOrigin != 0 );
                v28 = v76.z;
                v27 = v76.y;
              }
              v14 = y;
              nY += 336;
              LODWORD(vColor.z) += 28;
              v91 += 84;
              v25 = v29;
              LODWORD(x) = v29;
              v89 = (float *)((char *)v89 + 1);
            }
            while ( (int)v89 < y );
            v20 = vPos.z;
            v21 = vPos.y;
            v24 = LODWORD(v85);
          }
          ++v84;
          v23 = v23 + v21;
          *((float *)&x + 1) = v23;
        }
        while ( v84 < flAttenDelta );
        v22 = vAttenuation.x;
        v19 = nX;
      }
      ++LODWORD(vAttenuation.y);
      flCosAngle = flCosAngle + v20;
    }
    while ( SLODWORD(vAttenuation.y) < v19 );
  }
  _Msg(a1: "\nAdding VPLs to scene\n");
  v53 = 0;
  memset(&bounds.m_vMaxBounds, 0, sizeof(bounds.m_vMaxBounds));
  CUniformSampler::InitSamples(this: (CUniformSampler *)&bounds.m_vMaxBounds, SqrtNumSamples: 64, NumVariations: 1);
  vColor.y = 256.0 / flBounceScale;
  if ( SLODWORD(vAttenuation.x) > 0 )
  {
    vAttenuation.y = 0.0;
    v91 = 20;
    for ( y = LODWORD(vAttenuation.x); y != 0; --y )
    {
      v54 = flDrawRad;
      nX = 0;
      v89 = (float *)((char *)flDrawRad + LODWORD(vAttenuation.y) + 312);
      while ( 1 )
      {
        v55 = *v89;
        if ( *v89 > 0.0 )
        {
          v56 = 1.0 / v55;
          v57 = *(float *)((char *)&v54[v53 + 5] + LODWORD(vAttenuation.y));
          v58 = (char *)&v54[v53] + LODWORD(vAttenuation.y);
          v76.x = *(float *)v58 * (float)(1.0 / v55);
          v76.y = *((float *)v58 + 1) * (float)(1.0 / v55);
          v76.z = *((float *)v58 + 2) * (float)(1.0 / v55);
          vAttenuation.x = *((float *)v58 + 6) * (float)(1.0 / v55);
          *(_QWORD *)&vPos.x = *(_QWORD *)(v58 + 12);
          *(float *)&x = (float)(1.0 / v55) * *((float *)v58 + 7);
          *((float *)&x + 1) = *((float *)v58 + 8) * (float)(1.0 / v55);
          v59 = *((float *)v58 + 9);
          vPos.z = v57;
          v60 = &v54[3 * nX + 3 * v91];
          v61 = v60[2];
          v62 = v59 * v56;
          v63 = *(_QWORD *)v60;
          flCosAngle = v62;
          *(_QWORD *)&v69.x = v63;
          v69.z = v61;
          VectorNormalize(vec: &v69);
          v64 = vAttenuation.x;
          if ( vAttenuation.x > 0.0 )
          {
            v85 = vPos.y * vPos.y;
            v65 = 0;
            *(float *)&v65 = fsqrt((float)((float)(vPos.y * vPos.y) + (float)(vPos.z * vPos.z)) + (float)(vPos.x * vPos.x));
            *(_OWORD *)v71 = v65;
            if ( flMaxRadius > 0.0 && vAttenuation.x > flMaxRadius )
            {
              v64 = flMaxRadius;
              vAttenuation.x = flMaxRadius;
            }
            memset(&vDirection, 0, sizeof(vDirection));
            v66 = FindFarthestIntersection(
                    a1: (int)&vAttenuation.z,
                    vPoint: &v76,
                    sampler: (CUniformSampler *)&bounds.m_vMaxBounds,
                    kdTrees,
                    pTraversals,
                    flTraceLength: 0.0,
                    vDirection: COERCE_VECTOR_((float)(*(float *)v71 * vColor.y) / v64),
                    flCosAngle: 0.0,
                    bUseAngle: false)
                + 10.0;
            v85 = v66;
            if ( vAttenuation.x <= v66 )
              v67 = vAttenuation.x;
            else
              v67 = v85;
            CLightWorldApp::CreateHemiLight(
              this: (CLightWorldApp *)LODWORD(v10),
              pWorldRenderer,
              vOrigin: &v76,
              flRadius: v67,
              vColor: &vPos,
              vAttenuation: (Vector *)&x,
              vDirection: &v69);
          }
        }
        ++nX;
        ++v89;
        v53 += 10;
        if ( v53 >= 60 )
          break;
        v54 = flDrawRad;
      }
      LODWORD(vAttenuation.y) += 336;
      v91 += 28;
      v53 = 0;
    }
  }
  free(pMem: flDrawRad);
  if ( LODWORD(bounds.m_vMaxBounds.x) != 0 )
    free(pMem: (void *)LODWORD(bounds.m_vMaxBounds.x));
}

//------------------------------------------------------------------------------
// Address: 0x00403E40
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403EB0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00403F10
// Name: public: virtual int CLightWorldApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __usercall CLightWorldApp::Main@<eax>(CLightWorldApp *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v4; // eax
  const char *v5; // esi
  char *v7; // edi
  void (*v8)(const char *, ...); // esi
  int v9; // edx
  int v10; // esi
  int v11; // eax
  int v12; // eax
  RayTracingEnvironment **v13; // eax
  RayTracingEnvironment **v14; // ecx
  int m_nGrowSize; // esi
  int v16; // eax
  _DWORD *v17; // esi
  int v18; // esi
  const char *String; // eax
  KeyValues *v20; // ecx
  unsigned int v21; // xmm0_4
  unsigned int v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  float z; // xmm3_4
  const char *v26; // eax
  KeyValues *v27; // ecx
  const char *v28; // eax
  float x2; // xmm2_4
  float x3; // xmm0_4
  __int128 v31; // xmm1
  int y3; // xmm1_4
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm4_4
  IBVHNode *v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm5_4
  __int128 v42; // xmm0
  const char *v43; // xmm0_4
  float v44; // xmm1_4
  double v45; // st7
  const char *v46; // xmm0_4
  int v47; // esi
  const char *v48; // eax
  KeyValues *v49; // ecx
  const char *v50; // eax
  KeyValues *v51; // ecx
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm2_4
  float v56; // xmm3_4
  KeyValues *v57; // ecx
  const char *v58; // eax
  KeyValues *v59; // ecx
  const char *v60; // eax
  float v61; // xmm2_4
  __int128 v62; // xmm1
  float v63; // xmm1_4
  CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *v64; // xmm5_4
  IWorldRenderer *v65; // xmm3_4
  float v66; // xmm0_4
  float v67; // xmm1_4
  float y; // xmm2_4
  float x; // xmm4_4
  const char *v70; // xmm0_4
  float v71; // xmm0_4
  float v72; // xmm3_4
  __int128 v73; // xmm0
  float v74; // xmm0_4
  float v75; // xmm1_4
  double v76; // xmm0_8
  double v77; // st7
  float v78; // xmm2_4
  float v79; // xmm0_4
  int v80; // edi
  int v81; // ecx
  int *v82; // eax
  int v83; // edi
  _DWORD *v84; // esi
  _DWORD *v85; // ecx
  _DWORD *v86; // eax
  int v87; // eax
  int v88; // esi
  int v89; // ecx
  CUtlMemory<CPointLight,int> *v90; // edi
  int v91; // eax
  char *v92; // eax
  int v93; // eax
  int v94; // eax
  int v95; // eax
  int v96; // esi
  int v97; // eax
  CUtlMemory<CHemiLight,int> *v98; // edi
  int v99; // ecx
  char *v100; // ecx
  int v101; // ecx
  int v102; // eax
  int v103; // eax
  int v104; // edi
  int v105; // eax
  CUtlMemory<CSpotLight,int> *v106; // esi
  int v107; // ecx
  char *v108; // ecx
  int v109; // ecx
  int v110; // eax
  int v111; // eax
  _DWORD *v112; // edi
  int v113; // esi
  int v114; // eax
  __int64 v115; // xmm0_8
  int v116; // eax
  int v117; // ecx
  int i; // edx
  float v119; // xmm0_4
  float v120; // xmm3_4
  float v121; // xmm2_4
  float *v122; // eax
  float v123; // xmm4_4
  float v124; // xmm7_4
  float v125; // xmm6_4
  float v126; // xmm5_4
  float v127; // xmm1_4
  double v128; // xmm2_8
  float v129; // xmm0_4
  float v130; // xmm2_4
  double v131; // xmm2_8
  float v132; // xmm2_4
  double v133; // xmm2_8
  float v134; // xmm2_4
  double v135; // xmm0_8
  float v136; // xmm0_4
  double v137; // xmm0_8
  CBVHDictionaryEntry *v138; // xmm0_4
  double v139; // xmm0_8
  int v140; // ecx
  int v141; // edx
  int v142; // eax
  float v143; // xmm0_4
  float v144; // xmm2_4
  float v145; // xmm1_4
  float *v146; // eax
  float v147; // xmm7_4
  float v148; // xmm0_4
  float v149; // xmm3_4
  float v150; // xmm4_4
  float v151; // xmm6_4
  float v152; // xmm5_4
  float v153; // xmm0_4
  double v154; // xmm1_8
  float v155; // xmm4_4
  float v156; // xmm1_4
  double v157; // xmm1_8
  float v158; // xmm1_4
  double v159; // xmm1_8
  float v160; // xmm1_4
  double v161; // xmm1_8
  float v162; // xmm1_4
  double v163; // xmm1_8
  CBVHDictionaryEntry *v164; // xmm1_4
  double v165; // xmm0_8
  int v166; // ecx
  int v167; // edx
  int v168; // eax
  float v169; // xmm0_4
  float v170; // xmm2_4
  float v171; // xmm1_4
  float *v172; // eax
  float v173; // xmm7_4
  float v174; // xmm0_4
  float v175; // xmm3_4
  float v176; // xmm4_4
  float v177; // xmm6_4
  float v178; // xmm5_4
  float v179; // xmm0_4
  double v180; // xmm1_8
  float v181; // xmm4_4
  float v182; // xmm1_4
  double v183; // xmm1_8
  float v184; // xmm1_4
  double v185; // xmm1_8
  float v186; // xmm1_4
  double v187; // xmm1_8
  float v188; // xmm1_4
  double v189; // xmm1_8
  CBVHDictionaryEntry *v190; // xmm1_4
  double v191; // xmm0_8
  int v192; // edx
  int *v193; // esi
  int v194; // eax
  int v195; // edx
  int v196; // eax
  int v197; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v198; // esi
  float v199; // eax
  int v200; // edx
  int v201; // eax
  int v202; // edx
  int v203; // edi
  int v204; // eax
  int v205; // eax
  float v206; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v209; // ecx
  int v210; // eax
  float *v211; // eax
  CUtlSymbolTable::StringPool_t **v212; // edi
  int v213; // eax
  CUtlSymbolTable::StringPool_t **v214; // ecx
  int v215; // eax
  CUtlSymbolTable::StringPool_t **v216; // eax
  int v217; // edi
  CBVHDictionaryEntry *v218; // edi
  int v219; // eax
  void *v220; // edi
  int v221; // edi
  int v222; // eax
  CUtlSymbolTable::StringPool_t **v223; // edi
  int v224; // ecx
  CUtlSymbolTable::StringPool_t **v225; // edx
  int v226; // ecx
  CUtlSymbolTable::StringPool_t **v227; // edi
  int v228; // edi
  CBVHDictionaryEntry *v229; // edi
  int v230; // eax
  void *v231; // edi
  int v232; // edi
  CUtlSymbolTable::StringPool_t **v233; // edi
  int v234; // eax
  CUtlSymbolTable::StringPool_t **v235; // ecx
  int v236; // eax
  CUtlSymbolTable::StringPool_t **v237; // edi
  int v238; // edi
  int v239; // ecx
  int v240; // eax
  void *v241; // eax
  IWorldRenderer *v242; // edi
  IWorldTraversal *v243; // esi
  IWorldTraversal v244; // edx
  int v245; // eax
  void *v246; // eax
  int v247; // edi
  IBaseFileSystem_vtbl *v248; // esi
  int v249; // eax
  void *v250; // esi
  int v251; // edi
  void *v252; // eax
  int v253; // esi
  bool v254; // cc
  IWorldRenderer *v255; // edi
  int v256; // eax
  bool (__thiscall *ReorderResourceFile)(IWorldRenderer *, IBVHNode **, int); // edx
  char v258[12]; // [esp+70h] [ebp-394h] BYREF
  char pWorldFile[264]; // [esp+7Ch] [ebp-388h] BYREF
  AABB_t worldbounds; // [esp+184h] [ebp-280h] BYREF
  _BYTE outBuffer_4[148]; // [esp+1A0h] [ebp-264h] OVERLAPPED BYREF
  int v262; // [esp+234h] [ebp-1D0h]
  QAngle angVector; // [esp+238h] [ebp-1CCh] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > light_spot_origins; // [esp+244h] [ebp-1C0h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > light_origins; // [esp+258h] [ebp-1ACh] BYREF
  CUniformSampler samplerCone; // [esp+26Ch] [ebp-198h] BYREF
  Vector vDirection; // [esp+278h] [ebp-18Ch] BYREF
  CUniformSampler samplerPoint; // [esp+284h] [ebp-180h] BYREF
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > lights; // [esp+290h] [ebp-174h] BYREF
  Vector vAngles; // [esp+2A4h] [ebp-160h] BYREF
  __int64 v271; // [esp+2B0h] [ebp-154h]
  __int64 v272; // [esp+2B8h] [ebp-14Ch] BYREF
  int v273; // [esp+2C0h] [ebp-144h]
  unsigned __int64 nSize; // [esp+2C4h] [ebp-140h] BYREF
  int v275; // [esp+2CCh] [ebp-138h] BYREF
  float flAngle; // [esp+2D0h] [ebp-134h]
  int v277; // [esp+2D4h] [ebp-130h]
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > light_spots; // [esp+2D8h] [ebp-12Ch] BYREF
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > kdTrees; // [esp+2ECh] [ebp-118h] BYREF
  const char *pInnerCone; // [esp+300h] [ebp-104h] BYREF
  int v281; // [esp+304h] [ebp-100h] BYREF
  Vector4D vLight4D; // [esp+308h] [ebp-FCh] BYREF
  IBVHNode flMaxDistance; // [esp+318h] [ebp-ECh] BYREF
  int nCurrentResources; // [esp+31Ch] [ebp-E8h] BYREF
  Vector vLightMin; // [esp+320h] [ebp-E4h] BYREF
  float v286; // [esp+32Ch] [ebp-D8h] BYREF
  _BYTE vUp[24]; // [esp+330h] [ebp-D4h] OVERLAPPED BYREF
  float v288; // [esp+348h] [ebp-BCh] BYREF
  Vector4D vHDRLight4D; // [esp+34Ch] [ebp-B8h] BYREF
  float v290; // [esp+35Ch] [ebp-A8h] BYREF
  float v291; // [esp+360h] [ebp-A4h] BYREF
  float v292; // [esp+364h] [ebp-A0h] BYREF
  const char *pLinear; // [esp+368h] [ebp-9Ch]
  const char *pCone; // [esp+36Ch] [ebp-98h]
  float d50; // [esp+370h] [ebp-94h] BYREF
  IWorldRenderer *pWorldRenderer; // [esp+374h] [ebp-90h] BYREF
  CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *pTraversals; // [esp+378h] [ebp-8Ch] BYREF
  const char *pAngles; // [esp+37Ch] [ebp-88h] BYREF
  __int128 vOrigin; // [esp+380h] [ebp-84h] OVERLAPPED BYREF
  const char *pConstant; // [esp+390h] [ebp-74h] BYREF
  Vector vNodeOrigin; // [esp+394h] [ebp-70h]
  const char *pQuad; // [esp+3A0h] [ebp-64h]
  float v303; // [esp+3A4h] [ebp-60h] BYREF
  unsigned __int64 p0Distance; // [esp+3A8h] [ebp-5Ch] OVERLAPPED BYREF
  IBVHNode *pNode; // [esp+3B0h] [ebp-54h] BYREF
  __int128 v306; // [esp+3B8h] [ebp-4Ch] BYREF
  CUtlVector<CBVHDictionaryEntry,CUtlMemory<CBVHDictionaryEntry,int> > newEntries; // [esp+3C8h] [ebp-3Ch]
  __int128 y2; // [esp+3E0h] [ebp-24h] BYREF
  int t; // [esp+3F0h] [ebp-14h]
  long double bCanSeeSky; // [esp+3F4h] [ebp-10h] OVERLAPPED BYREF
  int r; // [esp+3FCh] [ebp-8h]
  int retaddr; // [esp+404h] [ebp+0h]

  HIDWORD(bCanSeeSky) = a2;
  r = retaddr;
  LODWORD(vNodeOrigin.y) = this;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  v4 = _CommandLine(a1: a3, a2: a4);
  v5 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 32))(
                       a1: v4,
                       a2: "-world",
                       a3: 0);
  if ( v5 != nullptr )
  {
    v7 = (char *)g_pWorldRendererMgr->CreateWorldRenderer(this: g_pWorldRendererMgr);
    pLinear = v7;
    V_snprintf(pDest: v258, maxLen: 260, pFormat: "maps/%s.whf", v5);
    g_pWorldRendererMgr->SetHWInstancingEnabled(this: g_pWorldRendererMgr, a2: false);
    if ( (**(unsigned __int8 (__thiscall ***)(char *, char *, int))v7)(a1: v7, a2: v258, a3: 1) != 0 )
    {
      v8 = (void (*)(const char *, ...))_Msg;
      *(_DWORD *)&vUp[4] = (*(int (__thiscall **)(char *))(*(_DWORD *)v7 + 16))(a1: v7);
      _Msg(a1: "\nLoading kd-trees\n");
      v9 = *(_DWORD *)v7;
      memset(&light_spots.m_Memory.m_nGrowSize, 0, 12);
      kdTrees.m_Memory.m_pMemory = nullptr;
      kdTrees.m_Memory.m_nAllocationCount = 0;
      pCone = (const char *)(*(int (__thiscall **)(char *))(v9 + 96))(a1: v7);
      pQuad = *((const char **)pCone + 3);
      DWORD1(y2) = 0;
      if ( (int)pQuad <= 0 )
      {
LABEL_15:
        v8(a1: "\nInitializing sample positions\n");
        memset(&vDirection, 0, sizeof(vDirection));
        CUniformSampler::InitSamples(this: (CUniformSampler *)&vDirection, SqrtNumSamples: 128, NumVariations: 1);
        memset(&light_origins.m_Memory.m_nGrowSize, 0, 12);
        CUniformSampler::InitSamples(
          this: (CUniformSampler *)&light_origins.m_Memory.m_nGrowSize,
          SqrtNumSamples: 128,
          NumVariations: 1);
        v8(a1: "\nFinding point lights\n");
        memset(&samplerPoint, 0, sizeof(samplerPoint));
        lights.m_Memory.m_pMemory = nullptr;
        lights.m_Memory.m_nAllocationCount = 0;
        memset(&light_spot_origins.m_Memory.m_nGrowSize, 0, 12);
        light_origins.m_Memory.m_pMemory = nullptr;
        light_origins.m_Memory.m_nAllocationCount = 0;
        (*(void (__thiscall **)(char *, const char *, CUniformSampler *, int *, _DWORD))(*(_DWORD *)v7 + 92))(
          a1: v7,
          a2: "light",
          a3: &samplerPoint,
          a4: &light_spot_origins.m_Memory.m_nGrowSize,
          a5: LODWORD(bCanSeeSky));
        v18 = 0;
        t = (int)lights.m_Memory.m_pMemory;
        LODWORD(bCanSeeSky) = 0;
        if ( (int)lights.m_Memory.m_pMemory > 0 )
        {
          memset(&lights.m_Memory.m_nGrowSize, 0, 12);
          do
          {
            DWORD2(y2) = KeyValues::GetString(
                           this: *((KeyValues **)&samplerPoint.m_pvDirections->x + LODWORD(bCanSeeSky)),
                           keyName: "origin",
                           defaultValue: setName);
            String = KeyValues::GetString(
                       this: *((KeyValues **)&samplerPoint.m_pvDirections->x + LODWORD(bCanSeeSky)),
                       keyName: "_light",
                       defaultValue: setName);
            v20 = *((KeyValues **)&samplerPoint.m_pvDirections->x + LODWORD(bCanSeeSky));
            LODWORD(vOrigin) = String;
            LODWORD(vNodeOrigin.x) = KeyValues::GetString(this: v20, keyName: "_lightHDR", defaultValue: setName);
            sscanf(string: (const char *)DWORD2(y2), format: "%f %f %f", &pWorldRenderer, &pTraversals, &pAngles);
            *(float *)&pWorldRenderer = *(float *)&pWorldRenderer
                                      - *(float *)(v18 + light_spot_origins.m_Memory.m_nGrowSize);
            *(float *)&pTraversals = *(float *)&pTraversals
                                   - *(float *)(v18 + light_spot_origins.m_Memory.m_nGrowSize + 4);
            *(float *)&pAngles = *(float *)&pAngles - *(float *)(v18 + light_spot_origins.m_Memory.m_nGrowSize + 8);
            sscanf(
              string: (const char *)vOrigin,
              format: "%f %f %f %f",
              &vLight4D.w,
              &flMaxDistance,
              &nCurrentResources,
              &vLightMin);
            vLight4D.w = vLight4D.w * 0.0039215689;
            *(float *)&flMaxDistance.__vftable = *(float *)&flMaxDistance.__vftable * 0.0039215689;
            *(float *)&nCurrentResources = *(float *)&nCurrentResources * 0.0039215689;
            *(float *)&v21 = vLight4D.w * (float)(vLightMin.x * 0.0039215689);
            *(float *)&v22 = *(float *)&flMaxDistance.__vftable * (float)(vLightMin.x * 0.0039215689);
            v23 = *(float *)&nCurrentResources * (float)(vLightMin.x * 0.0039215689);
            vLightMin.x = vLightMin.x * 0.0039215689;
            p0Distance = __PAIR64__(v22, v21);
            *(float *)&pNode = v23;
            if ( LODWORD(vNodeOrigin.x) != 0 )
            {
              sscanf(
                string: (const char *)LODWORD(vNodeOrigin.x),
                format: "%f %f %f %f",
                &vLightMin.y,
                &vLightMin.z,
                &v286,
                vUp);
              v24 = v286;
              z = vLightMin.z;
              if ( vLightMin.y > -1.0 || vLightMin.z > -1.0 || v286 > -1.0 )
              {
                *(float *)&p0Distance = (float)(*(float *)vUp * 0.0039215689) * (float)(vLightMin.y * 0.0039215689);
                *(float *)vUp = *(float *)vUp * 0.0039215689;
                vLightMin.y = vLightMin.y * 0.0039215689;
                vLightMin.z = vLightMin.z * 0.0039215689;
                v286 = v286 * 0.0039215689;
                *((float *)&p0Distance + 1) = *(float *)vUp * (float)(z * 0.0039215689);
                *(float *)&pNode = *(float *)vUp * (float)(v24 * 0.0039215689);
              }
            }
            v26 = KeyValues::GetString(
                    this: *((KeyValues **)&samplerPoint.m_pvDirections->x + LODWORD(bCanSeeSky)),
                    keyName: "_zero_percent_distance",
                    defaultValue: setName);
            v27 = *((KeyValues **)&samplerPoint.m_pvDirections->x + LODWORD(bCanSeeSky));
            LODWORD(vNodeOrigin.x) = v26;
            v28 = KeyValues::GetString(this: v27, keyName: "_fifty_percent_distance", defaultValue: setName);
            LODWORD(vOrigin) = v28;
            v292 = 0.0;
            d50 = 0.0;
            if ( LODWORD(vNodeOrigin.x) != 0
              && v28 != nullptr
              && (sscanf(string: (const char *)LODWORD(vNodeOrigin.x), format: "%f", &d50),
                  sscanf(string: (const char *)vOrigin, format: "%f", &v292),
                  x2 = v292,
                  v292 != 0.0) )
            {
              x3 = d50;
              *((float *)&y2 + 2) = *((float *)&p0Distance + 1) * *((float *)&p0Distance + 1);
              v31 = 0;
              *(float *)&v31 = fsqrt(
                                 (float)((float)(*((float *)&p0Distance + 1) * *((float *)&p0Distance + 1))
                                       + (float)(*(float *)&pNode * *(float *)&pNode))
                               + (float)(*(float *)&p0Distance * *(float *)&p0Distance));
              *(_OWORD *)&vUp[8] = v31;
              *(float *)&y3 = *(float *)&v31 * 256.0;
              *((float *)&y2 + 1) = v292;
              vNodeOrigin.z = d50;
              kdTrees.m_Memory.m_nGrowSize = y3;
              if ( v292 > d50 )
              {
                _Warning(a1: "light has _fifty_percent_distance of %f but _zero_percent_distance of %f\n", v292, d50);
                x2 = *((float *)&y2 + 1);
                y3 = kdTrees.m_Memory.m_nGrowSize;
                x3 = *((float *)&y2 + 1) * 2.0;
                vNodeOrigin.z = *((float *)&y2 + 1) * 2.0;
              }
              v303 = 0.0;
              if ( !SolveInverseQuadraticMonotonic(
                      x1: 0.0,
                      y1: 1.0,
                      x2,
                      y2: 1.0,
                      x3,
                      y3: *(float *)&y3,
                      a: nullptr,
                      b: (float *)&y2,
                      c: (float *)&y2 + 3) )
                _Warning(a1: "can't solve quadratic for light %f %f\n", *((float *)&y2 + 1), vNodeOrigin.z);
              v33 = *((float *)&p0Distance + 1);
              LODWORD(v34) = p0Distance;
              v35 = 2.0
                  / (float)((float)((float)((float)(v303 * *((float *)&y2 + 1)) + *(float *)&y2) * *((float *)&y2 + 1))
                          + *((float *)&y2 + 3));
              v36 = v35 * v303;
              v37 = v35 * *(float *)&y2;
              v38 = v35 * *((float *)&y2 + 3);
              *((float *)&y2 + 3) = v38;
              v39 = pNode;
              v303 = v36;
              *(float *)&y2 = v37;
              *((_QWORD *)&vOrigin + 1) = __PAIR64__(LODWORD(v37), LODWORD(v38));
              *(float *)&pConstant = v36;
            }
            else
            {
              DWORD2(y2) = KeyValues::GetString(
                             this: *((KeyValues **)&samplerPoint.m_pvDirections->x + LODWORD(bCanSeeSky)),
                             keyName: "_constant_attn",
                             defaultValue: setName);
              LODWORD(vOrigin) = KeyValues::GetString(
                                   this: *((KeyValues **)&samplerPoint.m_pvDirections->x + LODWORD(bCanSeeSky)),
                                   keyName: "_linear_attn",
                                   defaultValue: setName);
              LODWORD(vNodeOrigin.x) = KeyValues::GetString(
                                         this: *((KeyValues **)&samplerPoint.m_pvDirections->x + LODWORD(bCanSeeSky)),
                                         keyName: "_quadratic_attn",
                                         defaultValue: setName);
              sscanf(string: (const char *)DWORD2(y2), format: "%f", (char *)&vOrigin + 8);
              sscanf(string: (const char *)vOrigin, format: "%f", (char *)&vOrigin + 12);
              sscanf(string: (const char *)LODWORD(vNodeOrigin.x), format: "%f", &pConstant);
              v37 = *((float *)&vOrigin + 3);
              v36 = *(float *)&pConstant;
              v38 = *((float *)&vOrigin + 2);
              v40 = (float)((float)(*((float *)&vOrigin + 3) * 100.0) + (float)(*(float *)&pConstant * 10000.0))
                  + *((float *)&vOrigin + 2);
              v34 = *(float *)&p0Distance * v40;
              v33 = *((float *)&p0Distance + 1) * v40;
              *(float *)&v39 = *(float *)&pNode * v40;
              p0Distance = __PAIR64__(LODWORD(v33), LODWORD(v34));
              pNode = v39;
            }
            v41 = (float)((float)(v33 * v33) + (float)(*(float *)&v39 * *(float *)&v39)) + (float)(v34 * v34);
            v42 = 0;
            *(float *)&v42 = fsqrt(v41);
            *(_OWORD *)&vUp[8] = v42;
            if ( *(float *)&v42 > 0.0
              && (*(_OWORD *)&vUp[8] = v42,
                  SolveQuadratic(
                    a: (float)(0.00390625 / *(float *)&vUp[8]) * v36,
                    b: (float)(0.00390625 / *(float *)&vUp[8]) * v37,
                    c: (float)((float)(0.00390625 / *(float *)&vUp[8]) * v38) - 1.0,
                    root1: &v291,
                    root2: &v290))
              && ((*(float *)&v43 = v291, v291 <= v290) ? (v44 = v290) : (v44 = v291), v44 >= 0.0) )
            {
              if ( v291 <= v290 )
                *(float *)&v43 = v290;
            }
            else
            {
              *(float *)&v43 = 0.0;
            }
            pQuad = v43;
            DWORD1(vOrigin) = v43;
            v45 = FindFarthestIntersection(
                    a1: (int)&bCanSeeSky + 4,
                    vPoint: (Vector *)&pWorldRenderer,
                    sampler: (CUniformSampler *)&vDirection,
                    kdTrees: (CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *)&light_spots.m_Memory.m_nGrowSize,
                    pTraversals: (CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *)pCone,
                    flTraceLength: 60000.0,
                    vDirection: (Vector *)&lights.m_Memory.m_nGrowSize,
                    flCosAngle: 0.0,
                    bUseAngle: false)
                + 50.0;
            *((float *)&y2 + 2) = v45;
            if ( *(float *)&pQuad <= v45 )
              v46 = pQuad;
            else
              v46 = (const char *)DWORD2(y2);
            CLightWorldApp::CreatePointLight(
              this: (CLightWorldApp *)LODWORD(vNodeOrigin.y),
              pWorldRenderer: (IWorldRenderer *)v7,
              vOrigin: (Vector *)&pWorldRenderer,
              flRadius: *(float *)&v46,
              flMaxDistance: *((float *)&vOrigin + 1),
              vColor: (Vector *)&p0Distance,
              vAttenuation: (Vector *)((char *)&vOrigin + 8));
            v18 += 12;
            ++LODWORD(bCanSeeSky);
          }
          while ( SLODWORD(bCanSeeSky) < t );
        }
        _Msg(a1: "\nFinding spot lights\n");
        v275 = 0;
        flAngle = 0.0;
        v277 = 0;
        light_spots.m_Memory.m_pMemory = nullptr;
        light_spots.m_Memory.m_nAllocationCount = 0;
        memset(&angVector, 0, sizeof(angVector));
        light_spot_origins.m_Memory.m_pMemory = nullptr;
        light_spot_origins.m_Memory.m_nAllocationCount = 0;
        (*(void (__thiscall **)(char *, const char *, int *, QAngle *))(*(_DWORD *)v7 + 92))(
          a1: v7,
          a2: "light_spot",
          a3: &v275,
          a4: &angVector);
        v47 = 0;
        t = (int)light_spots.m_Memory.m_pMemory;
        LODWORD(bCanSeeSky) = 0;
        if ( (int)light_spots.m_Memory.m_pMemory > 0 )
        {
          do
          {
            DWORD1(vOrigin) = KeyValues::GetString(
                                this: *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky)),
                                keyName: "origin",
                                defaultValue: setName);
            *(float *)&v48 = COERCE_FLOAT(
                               KeyValues::GetString(
                                 this: *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky)),
                                 keyName: "_light",
                                 defaultValue: setName));
            v49 = *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky));
            v290 = *(float *)&v48;
            LODWORD(vNodeOrigin.z) = KeyValues::GetString(this: v49, keyName: "_lightHDR", defaultValue: setName);
            v291 = COERCE_FLOAT(
                     KeyValues::GetString(
                       this: *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky)),
                       keyName: "_cone",
                       defaultValue: setName));
            v50 = KeyValues::GetString(
                    this: *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky)),
                    keyName: "_inner_cone",
                    defaultValue: setName);
            v51 = *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky));
            kdTrees.m_Memory.m_nGrowSize = (int)v50;
            d50 = COERCE_FLOAT(KeyValues::GetString(this: v51, keyName: "angles", defaultValue: setName));
            sscanf(
              string: (const char *)DWORD1(vOrigin),
              format: "%f %f %f",
              (char *)&vOrigin + 8,
              (char *)&vOrigin + 12,
              &pConstant);
            *((float *)&vOrigin + 2) = *((float *)&vOrigin + 2) - *(float *)(LODWORD(angVector.x) + v47);
            *((float *)&vOrigin + 3) = *((float *)&vOrigin + 3) - *(float *)(LODWORD(angVector.x) + v47 + 4);
            *(float *)&pConstant = *(float *)&pConstant - *(float *)(LODWORD(angVector.x) + v47 + 8);
            sscanf(
              string: (const char *)LODWORD(v290),
              format: "%f %f %f %f",
              &kdTrees.m_pElements,
              &pInnerCone,
              &v281,
              &vLight4D);
            *(float *)&kdTrees.m_pElements = *(float *)&kdTrees.m_pElements * 0.0039215689;
            *(float *)&pInnerCone = *(float *)&pInnerCone * 0.0039215689;
            *(float *)&v281 = *(float *)&v281 * 0.0039215689;
            v52 = *(float *)&kdTrees.m_pElements * (float)(vLight4D.x * 0.0039215689);
            v53 = *(float *)&pInnerCone * (float)(vLight4D.x * 0.0039215689);
            v54 = *(float *)&v281 * (float)(vLight4D.x * 0.0039215689);
            vLight4D.x = vLight4D.x * 0.0039215689;
            *(float *)&pWorldRenderer = v52;
            *(float *)&pTraversals = v53;
            *(float *)&pAngles = v54;
            if ( LODWORD(vNodeOrigin.z) != 0 )
            {
              sscanf(
                string: (const char *)LODWORD(vNodeOrigin.z),
                format: "%f %f %f %f",
                &vUp[16],
                &vUp[20],
                &v288,
                &vHDRLight4D);
              v55 = v288;
              v56 = *(float *)&vUp[20];
              if ( *(float *)&vUp[16] > -1.0 || *(float *)&vUp[20] > -1.0 || v288 > -1.0 )
              {
                *(float *)&pWorldRenderer = (float)(vHDRLight4D.x * 0.0039215689)
                                          * (float)(*(float *)&vUp[16] * 0.0039215689);
                vHDRLight4D.x = vHDRLight4D.x * 0.0039215689;
                *(float *)&vUp[16] = *(float *)&vUp[16] * 0.0039215689;
                *(float *)&vUp[20] = *(float *)&vUp[20] * 0.0039215689;
                v288 = v288 * 0.0039215689;
                *(float *)&pTraversals = vHDRLight4D.x * (float)(v56 * 0.0039215689);
                *(float *)&pAngles = vHDRLight4D.x * (float)(v55 * 0.0039215689);
              }
            }
            sscanf(string: (const char *)LODWORD(v291), format: "%f", &nSize);
            sscanf(string: (const char *)kdTrees.m_Memory.m_nGrowSize, format: "%f", &pNode);
            sscanf(
              string: (const char *)LODWORD(d50),
              format: "%f %f %f",
              &lights.m_Memory.m_nGrowSize,
              &lights.m_Size,
              &lights.m_pElements);
            *(_DWORD *)&outBuffer_4[140] = lights.m_Memory.m_nGrowSize ^ _mask__NegFloat_;
            *(_DWORD *)&outBuffer_4[144] = lights.m_Size;
            v262 = (__int128)lights.m_pElements ^ _mask__NegFloat_;
            AngleVectors(
              angles: (const QAngle *)&outBuffer_4[140],
              forward: (Vector *)&samplerCone,
              right: (Vector *)&flMaxDistance,
              up: (Vector *)&vLightMin.z);
            VectorNormalize(vec: (Vector *)&samplerCone);
            VectorNormalize(vec: (Vector *)&flMaxDistance);
            VectorNormalize(vec: (Vector *)&vLightMin.z);
            v57 = *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky));
            *((float *)&y2 + 2) = *(float *)&nSize * 0.017453292;
            v58 = KeyValues::GetString(this: v57, keyName: "_zero_percent_distance", defaultValue: setName);
            v59 = *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky));
            LODWORD(vNodeOrigin.z) = v58;
            *(float *)&v60 = COERCE_FLOAT(
                               KeyValues::GetString(
                                 this: v59,
                                 keyName: "_fifty_percent_distance",
                                 defaultValue: setName));
            d50 = *(float *)&v60;
            v292 = 0.0;
            LODWORD(vOrigin) = 0;
            if ( LODWORD(vNodeOrigin.z) == 0
              || *(float *)&v60 == 0.0
              || (sscanf(string: (const char *)LODWORD(vNodeOrigin.z), format: "%f", &vOrigin),
                  sscanf(string: (const char *)LODWORD(d50), format: "%f", &v292),
                  v61 = v292,
                  v292 == 0.0) )
            {
              DWORD1(vOrigin) = KeyValues::GetString(
                                  this: *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky)),
                                  keyName: "_constant_attn",
                                  defaultValue: setName);
              v290 = COERCE_FLOAT(
                       KeyValues::GetString(
                         this: *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky)),
                         keyName: "_linear_attn",
                         defaultValue: setName));
              v291 = COERCE_FLOAT(
                       KeyValues::GetString(
                         this: *(KeyValues **)(v275 + 4 * LODWORD(bCanSeeSky)),
                         keyName: "_quadratic_attn",
                         defaultValue: setName));
              sscanf(string: (const char *)DWORD1(vOrigin), format: "%f", &vAngles);
              sscanf(string: (const char *)LODWORD(v290), format: "%f", &vAngles.y);
              sscanf(string: (const char *)LODWORD(v291), format: "%f", &vAngles.z);
              y = vAngles.y;
              v67 = vAngles.z;
              x = vAngles.x;
              v71 = (float)((float)(vAngles.y * 100.0) + (float)(vAngles.z * 10000.0)) + vAngles.x;
              *(float *)&v65 = *(float *)&pWorldRenderer * v71;
              *(float *)&v64 = *(float *)&pTraversals * v71;
              *(float *)&v70 = *(float *)&pAngles * v71;
              pWorldRenderer = v65;
              pTraversals = v64;
              pAngles = v70;
            }
            else
            {
              *((float *)&vOrigin + 1) = *(float *)&pWorldRenderer * *(float *)&pWorldRenderer;
              v62 = 0;
              *(float *)&v62 = fsqrt(
                                 (float)((float)(*(float *)&pWorldRenderer * *(float *)&pWorldRenderer)
                                       + (float)(*(float *)&pTraversals * *(float *)&pTraversals))
                               + (float)(*(float *)&pAngles * *(float *)&pAngles));
              v306 = v62;
              v63 = *(float *)&v62 * 256.0;
              *(float *)&pQuad = v292;
              LODWORD(vNodeOrigin.x) = vOrigin;
              *((float *)&v271 + 1) = v63;
              if ( v292 > *(float *)&vOrigin )
              {
                _Warning(
                  a1: "light has _fifty_percent_distance of %f but _zero_percent_distance of %f\n",
                  v292,
                  *(float *)&vOrigin);
                v61 = *(float *)&pQuad;
                v63 = *((float *)&v271 + 1);
                vNodeOrigin.x = *(float *)&pQuad * 2.0;
              }
              v303 = 1.0;
              if ( !SolveInverseQuadraticMonotonic(
                      x1: 0.0,
                      y1: 1.0,
                      x2: v61,
                      y2: 0.0,
                      x3: 0.0,
                      y3: v63,
                      a: (float *)&y2 + 1,
                      b: &v303,
                      c: (float *)&y2) )
                _Warning(a1: "can't solve quadratic for light %f %f\n", *(float *)&pQuad, vNodeOrigin.x);
              v64 = pTraversals;
              v65 = pWorldRenderer;
              v66 = 2.0
                  / (float)((float)((float)((float)(*((float *)&y2 + 1) * *(float *)&pQuad) + v303) * *(float *)&pQuad)
                          + *(float *)&y2);
              v67 = v66 * *((float *)&y2 + 1);
              y = v66 * v303;
              x = v66 * *(float *)&y2;
              *(_QWORD *)&y2 = __PAIR64__(v66 * *((float *)&y2 + 1), v66 * *(float *)&y2);
              v70 = pAngles;
              v303 = y;
              vAngles.x = x;
              vAngles.y = y;
              vAngles.z = v67;
            }
            v72 = (float)((float)(*(float *)&v65 * *(float *)&v65) + (float)(*(float *)&v64 * *(float *)&v64))
                + (float)(*(float *)&v70 * *(float *)&v70);
            v73 = 0;
            *(float *)&v73 = fsqrt(v72);
            v306 = v73;
            if ( *(float *)&v73 > 0.0
              && (v306 = v73,
                  SolveQuadratic(
                    a: (float)(0.00390625 / *(float *)&v306) * v67,
                    b: (float)(0.00390625 / *(float *)&v306) * y,
                    c: (float)((float)(0.00390625 / *(float *)&v306) * x) - 1.0,
                    root1: (float *)&v272 + 1,
                    root2: &vLight4D.z)) )
            {
              v74 = vLight4D.z;
              if ( *((float *)&v272 + 1) <= vLight4D.z )
                v75 = vLight4D.z;
              else
                v75 = *((float *)&v272 + 1);
              if ( v75 >= 0.0 )
              {
                if ( *((float *)&v272 + 1) > vLight4D.z )
                  v74 = *((float *)&v272 + 1);
              }
              else
              {
                v74 = 0.0;
              }
            }
            else
            {
              v74 = 0.0;
            }
            vLight4D.y = v74;
            LODWORD(bCanSeeSky) = 1;
            v76 = *((float *)&y2 + 2);
            __libm_sse2_cos(x: bCanSeeSky);
            *(float *)&v76 = v76;
            v77 = FindFarthestIntersection(
                    a1: (int)&bCanSeeSky + 4,
                    vPoint: (Vector *)((char *)&vOrigin + 8),
                    sampler: (CUniformSampler *)&light_origins.m_Memory.m_nGrowSize,
                    kdTrees: (CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *)&light_spots.m_Memory.m_nGrowSize,
                    pTraversals: (CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *)pCone,
                    flTraceLength: 60000.0,
                    vDirection: (Vector *)&samplerCone,
                    flCosAngle: *(float *)&v76,
                    bUseAngle: SLOBYTE(bCanSeeSky))
                + 50.0;
            *((float *)&vOrigin + 1) = v77;
            if ( *((float *)&y2 + 3) <= v77 )
              v78 = *((float *)&y2 + 3);
            else
              v78 = *((float *)&vOrigin + 1);
            v79 = *((float *)&y2 + 2);
            if ( *((float *)&y2 + 2) > 1.3089969 )
              v79 = 1.3089969;
            CLightWorldApp::CreateSpotLight(
              this: (CLightWorldApp *)LODWORD(vNodeOrigin.y),
              pWorldRenderer: (IWorldRenderer *)v7,
              vOrigin: (Vector *)((char *)&vOrigin + 8),
              flRadius: v78,
              flMaxDistance: vLight4D.y,
              flSpotAngle: v79,
              vColor: (Vector *)&pWorldRenderer,
              vAttenuation: &vAngles,
              vDirection: (Vector *)&samplerCone,
              vRight: &flMaxDistance,
              vUp: (Vector *)&vLightMin.z);
            v47 += 12;
            ++LODWORD(bCanSeeSky);
          }
          while ( SLODWORD(bCanSeeSky) < t );
        }
        _Msg(a1: "\nShooting VPLs\n");
        CLightWorldApp::ShootVirtualPointLights(
          this: (CLightWorldApp *)LODWORD(vNodeOrigin.y),
          nSqrtPointSamples: 32,
          nSqrtSpotSamples: 32,
          nSqrtBounceSamples: 4,
          nBounces: 1,
          kdTrees: (CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *)&light_spots.m_Memory.m_nGrowSize,
          pTraversals: (CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *)pCone,
          flPushBack: 0.0);
        _Msg(a1: "\nGridding VPLs\n");
        CLightWorldApp::GridVPLs(
          this: (CLightWorldApp *)LODWORD(vNodeOrigin.y),
          a2: COERCE_FLOAT((long double *)((char *)&bCanSeeSky + 4)),
          a3: (int)v7,
          a4: (int)_Msg,
          pWorldRenderer: (IWorldRenderer *)v7,
          flGridSize: 300.0,
          flMaxRadius: 400.0,
          flBounceScale: 12.0,
          kdTrees: (CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *)&light_spots.m_Memory.m_nGrowSize,
          pTraversals: (CUtlVector<IWorldTraversal *,CUtlMemory<IWorldTraversal *,int> > *)pCone);
        _Msg(a1: "\nUpdating nodes\n");
        v80 = (*(int (__thiscall **)(char *))(*(_DWORD *)v7 + 32))(a1: v7);
        LODWORD(y2) = v80;
        v81 = (80 * (unsigned __int64)(unsigned int)v80) >> 32 != 0 ? -1 : 80 * v80;
        v82 = (int *)operator new(nSize: __CFADD__(v81, 4) ? -1 : v81 + 4);
        if ( v82 != nullptr )
        {
          *v82 = v80;
          v83 = v80 - 1;
          v84 = v82 + 1;
          v85 = v82 + 1;
          if ( v83 >= 0 )
          {
            v86 = v82 + 8;
            do
            {
              *v85 = 0;
              *(v86 - 6) = 0;
              *(v86 - 5) = 0;
              *(v86 - 4) = 0;
              *(v86 - 3) = 0;
              *(v86 - 2) = 0;
              *(v86 - 1) = 0;
              *v86 = 0;
              v86[1] = 0;
              v86[2] = 0;
              v86[3] = 0;
              v86[4] = 0;
              v86[5] = 0;
              v86[6] = 0;
              v86[7] = 0;
              v86[8] = 0;
              v86[9] = 0;
              v86[10] = 0;
              v86[11] = 0;
              v86[12] = 0;
              v85 += 20;
              v86 += 20;
              --v83;
            }
            while ( v83 >= 0 );
          }
          LODWORD(bCanSeeSky) = v84;
        }
        else
        {
          LODWORD(bCanSeeSky) = 0;
        }
        v87 = *(_DWORD *)(LODWORD(vNodeOrigin.y) + 376);
        if ( v87 > 0 )
        {
          t = 0;
          DWORD2(y2) = v87;
          do
          {
            v88 = t + *(_DWORD *)(LODWORD(vNodeOrigin.y) + 364);
            v89 = *(_DWORD *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v88 + 40) + 32);
            v90 = (CUtlMemory<CPointLight,int> *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v88 + 40) + 20);
            v91 = *(_DWORD *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v88 + 40) + 24);
            HIDWORD(y2) = v89;
            if ( v89 + 1 > v91 )
            {
              CUtlMemory<CPointLight,int>::Grow(this: v90, num: v89 - v91 + 1);
              v89 = HIDWORD(y2);
            }
            v92 = (char *)++v90[1].m_pMemory - v89;
            v90[1].m_nAllocationCount = (int)v90->m_pMemory;
            v93 = (int)(v92 - 1);
            if ( v93 > 0 )
            {
              _V_memmove(dest: &v90->m_pMemory[HIDWORD(y2) + 1], src: &v90->m_pMemory[HIDWORD(y2)], count: 60 * v93);
              v89 = HIDWORD(y2);
            }
            v94 = (int)&v90->m_pMemory[v89];
            if ( v94 != 0 )
            {
              *(_QWORD *)v94 = *(_QWORD *)v88;
              *(_DWORD *)(v94 + 8) = *(_DWORD *)(v88 + 8);
              *(float *)(v94 + 12) = *(float *)(v88 + 12);
              *(float *)(v94 + 16) = *(float *)(v88 + 16);
              *(float *)(v94 + 20) = *(float *)(v88 + 20);
              *(float *)(v94 + 24) = *(float *)(v88 + 24);
              *(_QWORD *)(v94 + 28) = *(_QWORD *)(v88 + 28);
              *(_DWORD *)(v94 + 36) = *(_DWORD *)(v88 + 36);
              *(_DWORD *)(v94 + 40) = *(_DWORD *)(v88 + 40);
              *(_QWORD *)(v94 + 44) = *(_QWORD *)(v88 + 44);
              *(_DWORD *)(v94 + 52) = *(_DWORD *)(v88 + 52);
              *(float *)(v94 + 56) = *(float *)(v88 + 56);
            }
            t += 60;
            --DWORD2(y2);
          }
          while ( DWORD2(y2) != 0 );
        }
        v95 = *(_DWORD *)(LODWORD(vNodeOrigin.y) + 396);
        if ( v95 > 0 )
        {
          t = 0;
          DWORD2(y2) = v95;
          do
          {
            v96 = t + *(_DWORD *)(LODWORD(vNodeOrigin.y) + 384);
            v97 = *(_DWORD *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v96 + 76) + 52);
            v98 = (CUtlMemory<CHemiLight,int> *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v96 + 76) + 40);
            v99 = *(_DWORD *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v96 + 76) + 44);
            HIDWORD(y2) = v97;
            if ( v97 + 1 > v99 )
            {
              CUtlMemory<CHemiLight,int>::Grow(this: v98, num: v97 - v99 + 1);
              v97 = HIDWORD(y2);
            }
            v100 = (char *)++v98[1].m_pMemory - v97;
            v98[1].m_nAllocationCount = (int)v98->m_pMemory;
            v101 = (int)(v100 - 1);
            if ( v101 > 0 )
            {
              _V_memmove(dest: &v98->m_pMemory[HIDWORD(y2) + 1], src: &v98->m_pMemory[HIDWORD(y2)], count: 80 * v101);
              v97 = HIDWORD(y2);
            }
            v102 = (int)&v98->m_pMemory[v97];
            if ( v102 != 0 )
            {
              *(float *)v102 = *(float *)v96;
              *(float *)(v102 + 4) = *(float *)(v96 + 4);
              *(float *)(v102 + 8) = *(float *)(v96 + 8);
              *(float *)(v102 + 12) = *(float *)(v96 + 12);
              *(float *)(v102 + 16) = *(float *)(v96 + 16);
              *(float *)(v102 + 20) = *(float *)(v96 + 20);
              *(float *)(v102 + 24) = *(float *)(v96 + 24);
              *(float *)(v102 + 28) = *(float *)(v96 + 28);
              *(float *)(v102 + 32) = *(float *)(v96 + 32);
              *(float *)(v102 + 36) = *(float *)(v96 + 36);
              *(float *)(v102 + 40) = *(float *)(v96 + 40);
              *(float *)(v102 + 44) = *(float *)(v96 + 44);
              *(float *)(v102 + 48) = *(float *)(v96 + 48);
              *(float *)(v102 + 52) = *(float *)(v96 + 52);
              *(float *)(v102 + 56) = *(float *)(v96 + 56);
              *(float *)(v102 + 60) = *(float *)(v96 + 60);
              *(_QWORD *)(v102 + 64) = *(_QWORD *)(v96 + 64);
              *(_DWORD *)(v102 + 72) = *(_DWORD *)(v96 + 72);
              *(_DWORD *)(v102 + 76) = *(_DWORD *)(v96 + 76);
            }
            t += 80;
            --DWORD2(y2);
          }
          while ( DWORD2(y2) != 0 );
        }
        v103 = *(_DWORD *)(LODWORD(vNodeOrigin.y) + 416);
        if ( v103 > 0 )
        {
          t = 0;
          DWORD2(y2) = v103;
          do
          {
            v104 = t + *(_DWORD *)(LODWORD(vNodeOrigin.y) + 404);
            v105 = *(_DWORD *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v104 + 80) + 72);
            v106 = (CUtlMemory<CSpotLight,int> *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v104 + 80) + 60);
            v107 = *(_DWORD *)(LODWORD(bCanSeeSky) + 80 * *(_DWORD *)(v104 + 80) + 64);
            HIDWORD(y2) = v105;
            if ( v105 + 1 > v107 )
            {
              CUtlMemory<CSpotLight,int>::Grow(this: v106, num: v105 - v107 + 1);
              v105 = HIDWORD(y2);
            }
            v108 = (char *)++v106[1].m_pMemory - v105;
            v106[1].m_nAllocationCount = (int)v106->m_pMemory;
            v109 = (int)(v108 - 1);
            if ( v109 > 0 )
            {
              _V_memmove(dest: &v106->m_pMemory[HIDWORD(y2) + 1], src: &v106->m_pMemory[HIDWORD(y2)], count: 88 * v109);
              v105 = HIDWORD(y2);
            }
            v110 = (int)&v106->m_pMemory[v105];
            if ( v110 != 0 )
            {
              *(float *)v110 = *(float *)v104;
              *(float *)(v110 + 4) = *(float *)(v104 + 4);
              *(float *)(v110 + 8) = *(float *)(v104 + 8);
              *(float *)(v110 + 12) = *(float *)(v104 + 12);
              *(float *)(v110 + 16) = *(float *)(v104 + 16);
              *(float *)(v110 + 20) = *(float *)(v104 + 20);
              *(float *)(v110 + 24) = *(float *)(v104 + 24);
              *(float *)(v110 + 28) = *(float *)(v104 + 28);
              *(float *)(v110 + 32) = *(float *)(v104 + 32);
              *(float *)(v110 + 36) = *(float *)(v104 + 36);
              *(float *)(v110 + 40) = *(float *)(v104 + 40);
              *(float *)(v110 + 44) = *(float *)(v104 + 44);
              *(float *)(v110 + 48) = *(float *)(v104 + 48);
              *(float *)(v110 + 52) = *(float *)(v104 + 52);
              *(float *)(v110 + 56) = *(float *)(v104 + 56);
              *(float *)(v110 + 60) = *(float *)(v104 + 60);
              *(float *)(v110 + 64) = *(float *)(v104 + 64);
              *(float *)(v110 + 68) = *(float *)(v104 + 68);
              *(float *)(v110 + 72) = *(float *)(v104 + 72);
              *(float *)(v110 + 76) = *(float *)(v104 + 76);
              *(_DWORD *)(v110 + 80) = *(_DWORD *)(v104 + 80);
              *(float *)(v110 + 84) = *(float *)(v104 + 84);
            }
            t += 88;
            --DWORD2(y2);
          }
          while ( DWORD2(y2) != 0 );
        }
        v111 = (*(int (__thiscall **)(const char *, _DWORD))(*(_DWORD *)pLinear + 24))(a1: pLinear, a2: 0);
        (*(void (__thiscall **)(int, char *))(*(_DWORD *)v111 + 16))(a1: v111, a2: &pWorldFile[252]);
        t = 0;
        if ( (int)y2 > 0 )
        {
          v112 = (_DWORD *)(LODWORD(bCanSeeSky) + 20);
          do
          {
            v113 = (*(int (__thiscall **)(const char *, int))(*(_DWORD *)pLinear + 24))(a1: pLinear, a2: t);
            (*(void (__thiscall **)(int, __int128 *))(*(_DWORD *)v113 + 16))(a1: v113, a2: &v306);
            v114 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v113 + 12))(a1: v113, a2: &vUp[8]);
            v115 = *(_QWORD *)(v114 + 12);
            pConstant = *(const char **)(v114 + 20);
            v116 = v112[3];
            *((_QWORD *)&vOrigin + 1) = v115;
            if ( v116 > 0 )
            {
              v117 = 0;
              for ( i = v116; i != 0; --i )
              {
                v119 = *((float *)&vOrigin + 2) + *(float *)(*v112 + v117);
                v120 = *(float *)(*v112 + v117 + 8) + *(float *)&pConstant;
                v121 = *(float *)(*v112 + v117 + 4) + *((float *)&vOrigin + 3);
                v122 = (float *)(v117 + *v112);
                v123 = v119 - v122[6];
                v124 = v122[6];
                vLightMin.x = v120 - v124;
                v122[1] = v121;
                *v122 = v119;
                v122[2] = v120;
                v125 = v121 - v124;
                v126 = v124 + v121;
                v127 = v124 + v120;
                v128 = v123;
                v129 = v119 + v124;
                if ( v123 > (double)*(float *)&v306 )
                  v128 = *(float *)&v306;
                v130 = v128;
                *(float *)&v306 = v130;
                v131 = v125;
                if ( v125 > (double)*((float *)&v306 + 1) )
                  v131 = *((float *)&v306 + 1);
                v132 = v131;
                *((float *)&v306 + 1) = v132;
                v133 = vLightMin.x;
                if ( vLightMin.x > (double)*((float *)&v306 + 2) )
                  v133 = *((float *)&v306 + 2);
                v134 = v133;
                *((float *)&v306 + 2) = v134;
                v135 = v129;
                if ( v135 < *((float *)&v306 + 3) )
                  v135 = *((float *)&v306 + 3);
                v136 = v135;
                *((float *)&v306 + 3) = v136;
                v137 = v126;
                if ( v126 < (double)*(float *)&newEntries.m_Memory.m_pMemory )
                  v137 = *(float *)&newEntries.m_Memory.m_pMemory;
                *(float *)&v138 = v137;
                newEntries.m_Memory.m_pMemory = v138;
                v139 = v127;
                if ( v127 < (double)*(float *)&newEntries.m_Memory.m_nAllocationCount )
                  v139 = *(float *)&newEntries.m_Memory.m_nAllocationCount;
                v117 += 60;
                *(float *)&newEntries.m_Memory.m_nAllocationCount = v139;
              }
            }
            if ( (int)v112[8] > 0 )
            {
              v140 = 0;
              v141 = v112[8];
              do
              {
                v142 = v112[5];
                v143 = *(float *)(v142 + v140 + 12) + *((float *)&vOrigin + 2);
                v144 = *(float *)(v142 + v140 + 44) + *(float *)&pConstant;
                v145 = *(float *)(v142 + v140 + 28) + *((float *)&vOrigin + 3);
                v146 = (float *)(v140 + v142);
                v147 = v143;
                v146[3] = v143;
                v148 = v146[15];
                v149 = v147 - v148;
                *(float *)vUp = v144 - v148;
                v146[7] = v145;
                v150 = v148;
                v146[11] = v144;
                v151 = v145 - v148;
                v152 = v148 + v145;
                v153 = v148 + v144;
                v154 = v149;
                v155 = v150 + v147;
                if ( v149 > (double)*(float *)&v306 )
                  v154 = *(float *)&v306;
                v156 = v154;
                *(float *)&v306 = v156;
                v157 = v151;
                if ( v151 > (double)*((float *)&v306 + 1) )
                  v157 = *((float *)&v306 + 1);
                v158 = v157;
                *((float *)&v306 + 1) = v158;
                v159 = *(float *)vUp;
                if ( *(float *)vUp > (double)*((float *)&v306 + 2) )
                  v159 = *((float *)&v306 + 2);
                v160 = v159;
                *((float *)&v306 + 2) = v160;
                v161 = v155;
                if ( v155 < (double)*((float *)&v306 + 3) )
                  v161 = *((float *)&v306 + 3);
                v162 = v161;
                *((float *)&v306 + 3) = v162;
                v163 = v152;
                if ( v152 < (double)*(float *)&newEntries.m_Memory.m_pMemory )
                  v163 = *(float *)&newEntries.m_Memory.m_pMemory;
                *(float *)&v164 = v163;
                newEntries.m_Memory.m_pMemory = v164;
                v165 = v153;
                if ( v165 < *(float *)&newEntries.m_Memory.m_nAllocationCount )
                  v165 = *(float *)&newEntries.m_Memory.m_nAllocationCount;
                v140 += 80;
                --v141;
                *(float *)&newEntries.m_Memory.m_nAllocationCount = v165;
              }
              while ( v141 != 0 );
            }
            if ( (int)v112[13] > 0 )
            {
              v166 = 0;
              v167 = v112[13];
              do
              {
                v168 = v112[10];
                v169 = *((float *)&vOrigin + 2) + *(float *)(v168 + v166 + 12);
                v170 = *(float *)&pConstant + *(float *)(v168 + v166 + 44);
                v171 = *((float *)&vOrigin + 3) + *(float *)(v168 + v166 + 28);
                v172 = (float *)(v166 + v168);
                v173 = v169;
                v172[3] = v169;
                v174 = v172[15];
                v175 = v173 - v174;
                *(float *)&samplerCone.m_NumVariations = v170 - v174;
                v172[7] = v171;
                v176 = v174;
                v172[11] = v170;
                v177 = v171 - v174;
                v178 = v174 + v171;
                v179 = v174 + v170;
                v180 = v175;
                v181 = v176 + v173;
                if ( v175 > (double)*(float *)&v306 )
                  v180 = *(float *)&v306;
                v182 = v180;
                *(float *)&v306 = v182;
                v183 = v177;
                if ( v177 > (double)*((float *)&v306 + 1) )
                  v183 = *((float *)&v306 + 1);
                v184 = v183;
                *((float *)&v306 + 1) = v184;
                v185 = *(float *)&samplerCone.m_NumVariations;
                if ( *(float *)&samplerCone.m_NumVariations > (double)*((float *)&v306 + 2) )
                  v185 = *((float *)&v306 + 2);
                v186 = v185;
                *((float *)&v306 + 2) = v186;
                v187 = v181;
                if ( v181 < (double)*((float *)&v306 + 3) )
                  v187 = *((float *)&v306 + 3);
                v188 = v187;
                *((float *)&v306 + 3) = v188;
                v189 = v178;
                if ( v178 < (double)*(float *)&newEntries.m_Memory.m_pMemory )
                  v189 = *(float *)&newEntries.m_Memory.m_pMemory;
                *(float *)&v190 = v189;
                newEntries.m_Memory.m_pMemory = v190;
                v191 = v179;
                if ( v191 < *(float *)&newEntries.m_Memory.m_nAllocationCount )
                  v191 = *(float *)&newEntries.m_Memory.m_nAllocationCount;
                v166 += 88;
                --v167;
                *(float *)&newEntries.m_Memory.m_nAllocationCount = v191;
              }
              while ( v167 != 0 );
            }
            v192 = *(_DWORD *)v113;
            y2 = v306;
            (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, CBVHDictionaryEntry *, int))(v192 + 20))(
              a1: v113,
              a2: v306,
              a3: DWORD1(v306),
              a4: DWORD2(v306),
              a5: HIDWORD(v306),
              a6: newEntries.m_Memory.m_pMemory,
              a7: newEntries.m_Memory.m_nAllocationCount);
            v112 += 20;
            ++t;
          }
          while ( t < (int)y2 );
        }
        _Msg(a1: "\nCreating light resources\n");
        v193 = *(int **)&vUp[4];
        v194 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&vUp[4] + 16))(a1: *(_DWORD *)&vUp[4]);
        v195 = *v193;
        HIDWORD(y2) = v194;
        v196 = (*(int (__thiscall **)(int *, int))(v195 + 20))(a1: v193, a2: v194 - 1);
        p0Distance = *(_QWORD *)(v196 + 8) + *(_QWORD *)(v196 + 16);
        *(_QWORD *)((char *)&v306 + 4) = 0;
        HIDWORD(v306) = 0;
        newEntries.m_Memory.m_pMemory = nullptr;
        newEntries.m_Memory.m_nAllocationCount = 0;
        CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&worldbounds.m_vMaxBounds, growSize: 0, initSize: 0, nFlags: 0);
        v197 = 0;
        vNodeOrigin.z = 0.0;
        if ( (int)y2 > 0 )
        {
          v198 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(LODWORD(bCanSeeSky) + 12);
          DWORD1(y2) = LODWORD(bCanSeeSky) + 12;
          do
          {
            v199 = COERCE_FLOAT((*(int (__thiscall **)(const char *, int))(*(_DWORD *)pLinear + 24))(a1: pLinear, a2: v197));
            v200 = *(_DWORD *)LODWORD(v199);
            v303 = v199;
            v201 = (*(int (__thiscall **)(float))(v200 + 32))(a1: COERCE_FLOAT(LODWORD(v199)));
            v202 = 0;
            LODWORD(vLight4D.z) = v201;
            t = 0;
            if ( v201 > 0 )
            {
              do
              {
                v203 = *(_DWORD *)&vUp[4];
                v204 = (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v303) + 68))(
                         a1: COERCE_FLOAT(LODWORD(v303)),
                         a2: v202);
                v205 = *(_DWORD *)((*(int (__thiscall **)(int, int))(*(_DWORD *)v203 + 20))(a1: v203, a2: v204) + 32);
                if ( v205 != 19 && v205 != 20 && v205 != 21 )
                {
                  v206 = COERCE_FLOAT(
                           (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v303) + 68))(
                             a1: COERCE_FLOAT(LODWORD(v303)),
                             a2: t));
                  m_pMemory = v198->m_pMemory;
                  vLight4D.y = v206;
                  m_nAllocationCount = v198[-1].m_nAllocationCount;
                  if ( (int)m_pMemory + 1 > m_nAllocationCount )
                    CUtlMemory<int,int>::Grow(this: v198 - 1, num: (int)m_pMemory - m_nAllocationCount + 1);
                  ++v198->m_pMemory;
                  v209 = v198[-1].m_pMemory;
                  v210 = (char *)v198->m_pMemory - (char *)m_pMemory - 1;
                  v198->m_nAllocationCount = (int)v209;
                  if ( v210 > 0 )
                    _V_memmove(dest: &v209[(_DWORD)m_pMemory + 1], src: &v209[(_DWORD)m_pMemory], count: 4 * v210);
                  v211 = (float *)&v198[-1].m_pMemory[(_DWORD)m_pMemory];
                  if ( v211 != nullptr )
                    *v211 = vLight4D.y;
                }
                v202 = t + 1;
                t = v202;
              }
              while ( v202 < SLODWORD(vLight4D.z) );
            }
            LODWORD(bCanSeeSky) = v198[1].m_nGrowSize;
            if ( SLODWORD(bCanSeeSky) > 0 )
            {
              v212 = v198->m_pMemory;
              v213 = v198[-1].m_nAllocationCount;
              if ( (int)v198->m_pMemory + 1 > v213 )
                CUtlMemory<int,int>::Grow(this: v198 - 1, num: (int)v212 - v213 + 1);
              ++v198->m_pMemory;
              v214 = v198[-1].m_pMemory;
              v215 = (char *)v198->m_pMemory - (char *)v212 - 1;
              v198->m_nAllocationCount = (int)v214;
              if ( v215 > 0 )
                _V_memmove(dest: &v214[(_DWORD)v212 + 1], src: &v214[(_DWORD)v212], count: 4 * v215);
              v216 = &v198[-1].m_pMemory[(_DWORD)v212];
              if ( v216 != nullptr )
                *v216 = (CUtlSymbolTable::StringPool_t *)HIDWORD(y2);
              v217 = 40 * LODWORD(bCanSeeSky) + 4;
              v272 = (unsigned int)v217;
              *(_DWORD *)&outBuffer_4[56] = 0;
              *(_WORD *)&outBuffer_4[132] = 2;
              V_strncpy(pDest: &outBuffer_4[68], pSrc: "_lightworld_points_", maxLen: 64);
              *(_DWORD *)&outBuffer_4[48] = v217;
              v218 = newEntries.m_Memory.m_pMemory;
              *(_QWORD *)&outBuffer_4[40] = p0Distance;
              *(_DWORD *)&outBuffer_4[64] = 19;
              *(_DWORD *)&outBuffer_4[52] = HIDWORD(v272);
              if ( (int)&newEntries.m_Memory.m_pMemory->m_ChunkDesc.m_nChunkType + 1 > SDWORD2(v306) )
                CUtlMemory<CBVHDictionaryEntry,int>::Grow(
                  this: (CUtlMemory<CBVHDictionaryEntry,int> *)((char *)&v306 + 4),
                  num: (int)&newEntries.m_Memory.m_pMemory->m_ChunkDesc.m_nChunkType - DWORD2(v306) + 1);
              v219 = (char *)++newEntries.m_Memory.m_pMemory - (char *)v218 - 1;
              newEntries.m_Memory.m_nAllocationCount = DWORD1(v306);
              if ( v219 > 0 )
                _V_memmove(
                  dest: (void *)(104 * (_DWORD)v218 + DWORD1(v306) + 104),
                  src: (const void *)(104 * (_DWORD)v218 + DWORD1(v306)),
                  count: 104 * v219);
              v220 = (void *)(DWORD1(v306) + 104 * (_DWORD)v218);
              if ( v220 != nullptr )
              {
                qmemcpy(v220, &outBuffer_4[32], 104);
                v198 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)DWORD1(y2);
              }
              CUtlBuffer::Put(this: (CUtlBuffer *)&worldbounds.m_vMaxBounds, pMem: &bCanSeeSky, size: 4);
              v221 = 0;
              if ( SLODWORD(bCanSeeSky) > 0 )
              {
                t = 0;
                do
                {
                  CUtlBuffer::Put(
                    this: (CUtlBuffer *)&worldbounds.m_vMaxBounds,
                    pMem: (const void *)(t + v198->m_nGrowSize),
                    size: 40);
                  t += 60;
                  ++v221;
                }
                while ( v221 < SLODWORD(bCanSeeSky) );
              }
              p0Distance += v272;
              ++HIDWORD(y2);
            }
            v222 = v198[3].m_nAllocationCount;
            LODWORD(bCanSeeSky) = v222;
            if ( v222 > 0 )
            {
              v223 = v198->m_pMemory;
              v224 = v198[-1].m_nAllocationCount;
              if ( (int)v198->m_pMemory + 1 > v224 )
              {
                CUtlMemory<int,int>::Grow(this: v198 - 1, num: (int)v223 - v224 + 1);
                v222 = LODWORD(bCanSeeSky);
              }
              ++v198->m_pMemory;
              v225 = v198[-1].m_pMemory;
              v226 = (char *)v198->m_pMemory - (char *)v223 - 1;
              v198->m_nAllocationCount = (int)v225;
              if ( v226 > 0 )
              {
                _V_memmove(dest: &v225[(_DWORD)v223 + 1], src: &v225[(_DWORD)v223], count: 4 * v226);
                v222 = LODWORD(bCanSeeSky);
              }
              v227 = &v198[-1].m_pMemory[(_DWORD)v223];
              if ( v227 != nullptr )
              {
                *v227 = (CUtlSymbolTable::StringPool_t *)HIDWORD(y2);
                v222 = LODWORD(bCanSeeSky);
              }
              *(_DWORD *)&outBuffer_4[56] = 0;
              v228 = 76 * v222 + 4;
              v271 = (unsigned int)v228;
              *(_WORD *)&outBuffer_4[132] = 2;
              V_strncpy(pDest: &outBuffer_4[68], pSrc: "_lightworld_hemis_", maxLen: 64);
              *(_DWORD *)&outBuffer_4[48] = v228;
              v229 = newEntries.m_Memory.m_pMemory;
              *(_QWORD *)&outBuffer_4[40] = p0Distance;
              *(_DWORD *)&outBuffer_4[64] = 20;
              *(_DWORD *)&outBuffer_4[52] = HIDWORD(v271);
              if ( (int)&newEntries.m_Memory.m_pMemory->m_ChunkDesc.m_nChunkType + 1 > SDWORD2(v306) )
                CUtlMemory<CBVHDictionaryEntry,int>::Grow(
                  this: (CUtlMemory<CBVHDictionaryEntry,int> *)((char *)&v306 + 4),
                  num: (int)&newEntries.m_Memory.m_pMemory->m_ChunkDesc.m_nChunkType - DWORD2(v306) + 1);
              v230 = (char *)++newEntries.m_Memory.m_pMemory - (char *)v229 - 1;
              newEntries.m_Memory.m_nAllocationCount = DWORD1(v306);
              if ( v230 > 0 )
                _V_memmove(
                  dest: (void *)(104 * (_DWORD)v229 + DWORD1(v306) + 104),
                  src: (const void *)(104 * (_DWORD)v229 + DWORD1(v306)),
                  count: 104 * v230);
              v231 = (void *)(DWORD1(v306) + 104 * (_DWORD)v229);
              if ( v231 != nullptr )
              {
                qmemcpy(v231, &outBuffer_4[32], 104);
                v198 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)DWORD1(y2);
              }
              CUtlBuffer::Put(this: (CUtlBuffer *)&worldbounds.m_vMaxBounds, pMem: &bCanSeeSky, size: 4);
              v232 = 0;
              if ( SLODWORD(bCanSeeSky) > 0 )
              {
                t = 0;
                do
                {
                  CUtlBuffer::Put(
                    this: (CUtlBuffer *)&worldbounds.m_vMaxBounds,
                    pMem: (const void *)(t + v198[2].m_nAllocationCount),
                    size: 76);
                  t += 80;
                  ++v232;
                }
                while ( v232 < SLODWORD(bCanSeeSky) );
              }
              p0Distance += v271;
              ++HIDWORD(y2);
            }
            LODWORD(bCanSeeSky) = v198[5].m_pMemory;
            if ( SLODWORD(bCanSeeSky) > 0 )
            {
              v233 = v198->m_pMemory;
              v234 = v198[-1].m_nAllocationCount;
              if ( (int)v198->m_pMemory + 1 > v234 )
                CUtlMemory<int,int>::Grow(this: v198 - 1, num: (int)v233 - v234 + 1);
              ++v198->m_pMemory;
              v235 = v198[-1].m_pMemory;
              v236 = (char *)v198->m_pMemory - (char *)v233 - 1;
              v198->m_nAllocationCount = (int)v235;
              if ( v236 > 0 )
                _V_memmove(dest: &v235[(_DWORD)v233 + 1], src: &v235[(_DWORD)v233], count: 4 * v236);
              v237 = &v198[-1].m_pMemory[(_DWORD)v233];
              if ( v237 != nullptr )
                *v237 = (CUtlSymbolTable::StringPool_t *)HIDWORD(y2);
              LODWORD(nSize) = 0;
              *(_DWORD *)&outBuffer_4[56] = 0;
              v238 = 80 * LODWORD(bCanSeeSky) + 4;
              v273 = v238;
              *(_WORD *)&outBuffer_4[132] = 2;
              V_strncpy(pDest: &outBuffer_4[68], pSrc: "_lightworld_spots_", maxLen: 64);
              *(_DWORD *)&outBuffer_4[52] = nSize;
              t = (int)newEntries.m_Memory.m_pMemory;
              *(_QWORD *)&outBuffer_4[40] = p0Distance;
              *(_DWORD *)&outBuffer_4[64] = 21;
              *(_DWORD *)&outBuffer_4[48] = v238;
              if ( (int)&newEntries.m_Memory.m_pMemory->m_ChunkDesc.m_nChunkType + 1 > SDWORD2(v306) )
                CUtlMemory<CBVHDictionaryEntry,int>::Grow(
                  this: (CUtlMemory<CBVHDictionaryEntry,int> *)((char *)&v306 + 4),
                  num: (int)&newEntries.m_Memory.m_pMemory->m_ChunkDesc.m_nChunkType - DWORD2(v306) + 1);
              v239 = t;
              v240 = (int)++newEntries.m_Memory.m_pMemory - t - 1;
              newEntries.m_Memory.m_nAllocationCount = DWORD1(v306);
              if ( v240 > 0 )
              {
                _V_memmove(
                  dest: (void *)(DWORD1(v306) + 104 * t + 104),
                  src: (const void *)(DWORD1(v306) + 104 * t),
                  count: 104 * v240);
                v239 = t;
              }
              v241 = (void *)(DWORD1(v306) + 104 * v239);
              if ( v241 != nullptr )
              {
                qmemcpy(v241, &outBuffer_4[32], 104);
                v238 = v273;
                v198 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)DWORD1(y2);
              }
              CUtlBuffer::Put(this: (CUtlBuffer *)&worldbounds.m_vMaxBounds, pMem: &bCanSeeSky, size: 4);
              DWORD2(y2) = 0;
              if ( SLODWORD(bCanSeeSky) > 0 )
              {
                t = 0;
                do
                {
                  CUtlBuffer::Put(
                    this: (CUtlBuffer *)&worldbounds.m_vMaxBounds,
                    pMem: (char *)v198[4].m_pMemory + t,
                    size: 80);
                  t += 88;
                  ++DWORD2(y2);
                }
                while ( SDWORD2(y2) < SLODWORD(bCanSeeSky) );
              }
              p0Distance += __PAIR64__(nSize, v238);
              ++HIDWORD(y2);
            }
            (*(void (__thiscall **)(float, CUtlSymbolTable::StringPool_t **, CUtlSymbolTable::StringPool_t **))(*(_DWORD *)LODWORD(v303) + 120))(
              a1: COERCE_FLOAT(LODWORD(v303)),
              a2: v198[-1].m_pMemory,
              a3: v198->m_pMemory);
            v197 = LODWORD(vNodeOrigin.z) + 1;
            v198 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)((char *)v198 + 80);
            LODWORD(vNodeOrigin.z) = v197;
            DWORD1(y2) = v198;
          }
          while ( v197 < (int)y2 );
        }
        _Msg(a1: "\nSetting CanSeeSky flags\n");
        pQuad = *((const char **)pCone + 3);
        t = 0;
        if ( (int)pQuad > 0 )
        {
          v242 = (IWorldRenderer *)pLinear;
          do
          {
            v243 = *(IWorldTraversal **)(*(_DWORD *)pCone + 4 * t);
            kdTrees.m_Size = 0;
            kdTrees.m_pElements = nullptr;
            *(float *)&pInnerCone = 0.0;
            *(float *)&v281 = 0.0;
            vLight4D.x = 0.0;
            memset(&vUp[12], 0, 12);
            v288 = 0.0;
            vHDRLight4D.x = 0.0;
            v242->GetEntities(
              this: v242,
              a2: "light_environment",
              a3: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&kdTrees.m_Size,
              a4: v243);
            v242->GetEntities(
              this: v242,
              a2: "sky_camera",
              a3: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&vUp[12],
              a4: v243);
            BYTE8(y2) = 0;
            if ( v281 <= 0 || SLODWORD(v288) <= 0 )
            {
              _Msg(a1: "Can see sky: No\n");
            }
            else
            {
              BYTE8(y2) = 1;
              _Msg(a1: "Can see sky: Yes\n");
            }
            v244.__vftable = v243->__vftable;
            LODWORD(bCanSeeSky) = DWORD2(y2);
            v245 = v244.GetStartNode(this: v243);
            CLightWorldApp::SetCanSeeSky(
              this: (CLightWorldApp *)LODWORD(vNodeOrigin.y),
              pWorldRenderer: v242,
              nStartNode: v245,
              bCanSeeSky: SLOBYTE(bCanSeeSky));
            v246 = *(void **)&vUp[12];
            v288 = 0.0;
            if ( *(int *)&vUp[20] >= 0 )
            {
              if ( *(_DWORD *)&vUp[12] != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&vUp[12]);
                v246 = nullptr;
                *(_DWORD *)&vUp[12] = 0;
              }
              *(_DWORD *)&vUp[16] = 0;
            }
            LODWORD(vHDRLight4D.x) = v246;
            if ( *(int *)&vUp[20] >= 0 )
            {
              if ( v246 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v246);
                *(_DWORD *)&vUp[12] = 0;
              }
              *(_DWORD *)&vUp[16] = 0;
            }
            CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&kdTrees.m_Size);
            ++t;
          }
          while ( t < (int)pQuad );
        }
        _Msg(a1: "\nUpdating world files\n");
        v247 = *(_DWORD *)&vUp[4];
        v248 = g_pFullFileSystem->IBaseFileSystem::__vftable;
        v249 = (***(int (__thiscall ****)(_DWORD, const char *, _DWORD))&vUp[4])(
                 a1: *(_DWORD *)&vUp[4],
                 a2: "ab",
                 a3: 0);
        v250 = (void *)((int (__thiscall *)(IBaseFileSystem *, int))v248->Open)(
                         a1: &g_pFullFileSystem->IBaseFileSystem,
                         a2: v249);
        g_pFullFileSystem->Write(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: (const void *)LODWORD(worldbounds.m_vMaxBounds.x),
          a3: *(_DWORD *)outBuffer_4,
          a4: v250);
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v250);
        (*(void (__thiscall **)(int, _DWORD, CBVHDictionaryEntry *))(*(_DWORD *)v247 + 72))(
          a1: v247,
          a2: DWORD1(v306),
          a3: newEntries.m_Memory.m_pMemory);
        v251 = y2;
        v252 = operator new(nSize: 4 * y2);
        v253 = 0;
        v254 = v251 <= 0;
        v255 = (IWorldRenderer *)pLinear;
        DWORD2(y2) = v252;
        if ( !v254 )
        {
          do
          {
            v256 = (int)v255->GetNode(this: v255, a2: v253);
            *(_DWORD *)(DWORD2(y2) + 4 * v253++) = v256;
          }
          while ( v253 < (int)y2 );
        }
        ReorderResourceFile = v255->ReorderResourceFile;
        LODWORD(bCanSeeSky) = y2;
        ((void (__thiscall *)(IWorldRenderer *, _DWORD))ReorderResourceFile)(a1: v255, a2: DWORD2(y2));
        v255->WriteHierarchyFile(this: v255, a2: "whf_lightworld_temp.tmp");
        g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: v258, a3: nullptr);
        g_pFullFileSystem->RenameFile(this: g_pFullFileSystem, a2: "whf_lightworld_temp.tmp", a3: v258, a4: nullptr);
        g_pWorldRendererMgr->DestroyWorldRenderer(this: g_pWorldRendererMgr, a2: v255);
        if ( worldbounds.m_vMaxBounds.z >= 0.0 )
        {
          if ( LODWORD(worldbounds.m_vMaxBounds.x) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(worldbounds.m_vMaxBounds.x));
            worldbounds.m_vMaxBounds.x = 0.0;
          }
          worldbounds.m_vMaxBounds.y = 0.0;
        }
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)((char *)&v306 + 4));
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&angVector);
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v275);
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&light_spot_origins.m_Memory.m_nGrowSize);
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&samplerPoint);
        if ( light_origins.m_Memory.m_nGrowSize != 0 )
          free(pMem: (void *)light_origins.m_Memory.m_nGrowSize);
        if ( LODWORD(vDirection.x) != 0 )
          free(pMem: (void *)LODWORD(vDirection.x));
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&light_spots.m_Memory.m_nGrowSize);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)pCone + 4 * DWORD1(y2));
          v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
          v12 = (*(int (__thiscall **)(char *, int))(*(_DWORD *)v7 + 24))(a1: v7, a2: v11);
          (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, int, _DWORD))(**(_DWORD **)&vUp[4] + 44))(
            a1: *(_DWORD *)&vUp[4],
            a2: 0,
            a3: 0,
            a4: v12,
            a5: 0);
          DWORD2(y2) = (*(int (__thiscall **)(char *, int))(*(_DWORD *)v7 + 100))(a1: v7, a2: v10);
          if ( DWORD2(y2) == 0 )
            break;
          v13 = kdTrees.m_Memory.m_pMemory;
          v14 = kdTrees.m_Memory.m_pMemory;
          t = (int)kdTrees.m_Memory.m_pMemory;
          if ( (int)kdTrees.m_Memory.m_pMemory + 1 > light_spots.m_Size )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&light_spots.m_Memory.m_nGrowSize,
              num: (int)kdTrees.m_Memory.m_pMemory - light_spots.m_Size + 1);
            v13 = kdTrees.m_Memory.m_pMemory;
            v14 = (RayTracingEnvironment **)t;
          }
          m_nGrowSize = light_spots.m_Memory.m_nGrowSize;
          kdTrees.m_Memory.m_pMemory = (RayTracingEnvironment **)((char *)v13 + 1);
          v16 = (char *)v13 - (char *)v14;
          kdTrees.m_Memory.m_nAllocationCount = light_spots.m_Memory.m_nGrowSize;
          if ( v16 > 0 )
          {
            _V_memmove(
              dest: (void *)(light_spots.m_Memory.m_nGrowSize + 4 * (_DWORD)v14 + 4),
              src: (const void *)(light_spots.m_Memory.m_nGrowSize + 4 * (_DWORD)v14),
              count: 4 * v16);
            v14 = (RayTracingEnvironment **)t;
          }
          v17 = (_DWORD *)(m_nGrowSize + 4 * (_DWORD)v14);
          if ( v17 != nullptr )
            *v17 = DWORD2(y2);
          ++DWORD1(y2);
          if ( SDWORD1(y2) >= (int)pQuad )
          {
            v8 = (void (*)(const char *, ...))_Msg;
            goto LABEL_15;
          }
        }
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&light_spots.m_Memory.m_nGrowSize);
        return 0;
      }
    }
    else
    {
      _Msg(a1: "Cannot load %s!\n", v258);
      return 0;
    }
  }
  else
  {
    _Msg(a1: "bakeworld usage:\n");
    _Msg(a1: "bakeworld.exe [options ] -world <worldfile>\n");
    _Msg(a1: "\n");
    _Msg(a1: "Options:\n");
    _Msg(a1: " -voxelsize <float>     : size of a texture voxel\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004064D0
// Name: public: CLightWorldApp::CLightWorldApp(void)
// Source: json
//------------------------------------------------------------------------------
CLightWorldApp *__thiscall CLightWorldApp::CLightWorldApp(CLightWorldApp *this)
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(this, pFileSystem: nullptr, pAppSystemParent: nullptr);
  this->__vftable = (CLightWorldApp_vtbl *)&CLightWorldApp::`vftable';
  this->m_pointLights.m_Memory.m_pMemory = nullptr;
  this->m_pointLights.m_Memory.m_nAllocationCount = 0;
  this->m_pointLights.m_Memory.m_nGrowSize = 0;
  this->m_pointLights.m_Size = 0;
  this->m_pointLights.m_pElements = nullptr;
  this->m_hemiLights.m_Memory.m_pMemory = nullptr;
  this->m_hemiLights.m_Memory.m_nAllocationCount = 0;
  this->m_hemiLights.m_Memory.m_nGrowSize = 0;
  this->m_hemiLights.m_Size = 0;
  this->m_hemiLights.m_pElements = nullptr;
  this->m_spotLights.m_Memory.m_pMemory = nullptr;
  this->m_spotLights.m_Memory.m_nAllocationCount = 0;
  this->m_spotLights.m_Memory.m_nGrowSize = 0;
  this->m_spotLights.m_Size = 0;
  this->m_spotLights.m_pElements = nullptr;
  this->m_virtualPointLights.m_Memory.m_pMemory = nullptr;
  this->m_virtualPointLights.m_Memory.m_nAllocationCount = 0;
  this->m_virtualPointLights.m_Memory.m_nGrowSize = 0;
  this->m_virtualPointLights.m_Size = 0;
  this->m_virtualPointLights.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406560
// Name: public: virtual char const __near * CLightWorldApp::GetAppName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLightWorldApp::GetAppName(CLightWorldApp *this)
{
  return "LightWorld";
}

//------------------------------------------------------------------------------
// Address: 0x00406570
// Name: public: virtual bool CLightWorldApp::AppUsesReadPixels(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLightWorldApp::AppUsesReadPixels(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00406580
// Name: public: CLightWorldApp::~CLightWorldApp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightWorldApp::~CLightWorldApp(CLightWorldApp *this)
{
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_virtualPointLights);
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_spotLights);
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_hemiLights);
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_pointLights);
  CUtlDict<int,unsigned short>::RemoveAll(this: &this->m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_SystemDict.m_Elements.m_Tree);
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_NonAppSystemFactories);
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Systems);
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::~CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x004069C0
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B20
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406C60
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406D50
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406E50
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00406F40
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00407220
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407290
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00407390
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00407450
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_446B3C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_446B3C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_446B3C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_446B3C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_446B3C = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_446B3C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_446B3C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_446B3C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_446B3C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_446B3C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_446B3C = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_446B3C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_446B3C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407A40
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00407A90
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407EB0
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x00407F90
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00411060
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411160
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_457DBC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_457DBC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004112E0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_457DBC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00411340
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_457DBC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004113B0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_457DBC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_457DBC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004114A0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x004115A0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x004116E0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_457DBC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_457DBC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004117E0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004118A0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_457DBC = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_457DBC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_457DBC = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_457DBC = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_457DBC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_457DBC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_457DBC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_457DBC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_457DBC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_457DBC = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_457DBC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_457DBC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_457DBC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_457DBC = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00411EB0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411FC0
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412050
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004065E0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
