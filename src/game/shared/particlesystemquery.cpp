// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/particlesystemquery.cpp
// Functions: 37
// ============================================================

#include "game\shared\particlesystemquery.h"

//------------------------------------------------------------------------------
// Address: 0x1003DE00
// Name: public: CTSQueue<class CFunctor __near *,0,1>::CTSQueue<class CFunctor __near *,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctor *,0,1> *__thiscall CTSQueue<CFunctor *,0,1>::CTSQueue<CFunctor *,0,1>(CTSQueue<CFunctor *,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // eax
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+0h] [ebp-Ch]

  p_m_FreeNodes = &this->m_FreeNodes;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1044E7B0, a2: v5);
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  p_m_FreeNodes->m_Head.value32.DepthAndSequence = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1044E9DC, a2: v5);
    __debugbreak();
    _Error(this: (ISceneTokenProcessor *)&stru_1044E9DC, a2: v6);
    __debugbreak();
  }
  _InterlockedExchange(&this->m_Count.m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v3 = (CTSQueue<CFunctor *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
  this->m_Tail.value.pNode = v3;
  this->m_Head.value.pNode = v3;
  v3->pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003DE90
// Name: public: struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near * CTSQueue<class CFunctor __near *,0,1>::Push(struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctor *,0,1>::Node_t *__thiscall CTSQueue<CFunctor *,0,1>::Push(
        CTSQueue<CFunctor *,0,1> *this,
        CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *pNode)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // edi
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *)this;
  v3 = this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<CFunctor *,0,1> *)_InterlockedCompareExchange(
                                      (volatile signed __int32 *)v3,
                                      (signed __int32)pNode,
                                      (signed __int32)this) != this;
        i = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: v3->pNext, a3: i + 1, a4: v3, a5: i);
    v3 = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: i + 1, a4: v3, a5: i);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101229B0
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(
        CMatRenderData<CModelRenderSystem::RenderModelInfo_t> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(CModelRenderSystem::RenderModelInfo_t *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x10139C10
// Name: public: virtual int CParticleSystemQuery::GetRayTraceEnvironmentFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSystemQuery::GetRayTraceEnvironmentFromName(
        CParticleSystemQuery *this,
        const char *pszRtEnvName)
{
  int v2; // esi

  v2 = 0;
  while ( _V_stricmp(s1: s_RtEnvNameMap[v2].m_pszGroupName, s2: pszRtEnvName) != 0 )
  {
    if ( (unsigned int)++v2 >= 2 )
      return 0;
  }
  return s_RtEnvNameMap[v2].m_nGroupID;
}

//------------------------------------------------------------------------------
// Address: 0x10139C50
// Name: public: virtual int CParticleSystemQuery::GetCollisionGroupFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSystemQuery::GetCollisionGroupFromName(
        CParticleSystemQuery *this,
        const char *pszCollisionGroupName)
{
  int v2; // esi

  v2 = 0;
  while ( _V_stricmp(s1: s_NameMap[v2].m_pszGroupName, s2: pszCollisionGroupName) != 0 )
  {
    if ( (unsigned int)++v2 >= 6 )
      return 0;
  }
  return s_NameMap[v2].m_nGroupID;
}

//------------------------------------------------------------------------------
// Address: 0x10139C90
// Name: public: virtual class Vector CParticleSystemQuery::GetLocalPlayerPos(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CParticleSystemQuery::GetLocalPlayerPos(CParticleSystemQuery *this, Vector *result)
{
  C_BasePlayer *LocalPlayer; // eax
  int v4; // eax
  float v5; // edx

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v4 = (int)LocalPlayer->WorldSpaceCenter(this: LocalPlayer);
    v5 = *(float *)(v4 + 8);
    *(_QWORD *)&result->x = *(_QWORD *)v4;
    result->z = v5;
  }
  else
  {
    *result = vec3_origin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139CE0
// Name: public: virtual class Vector CParticleSystemQuery::GetCurrentViewOrigin(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CParticleSystemQuery::GetCurrentViewOrigin(CParticleSystemQuery *this, Vector *result)
{
  const Vector *v2; // eax
  __int64 v3; // xmm0_8
  float z; // eax

  v2 = CurrentViewOrigin();
  v3 = *(_QWORD *)&v2->x;
  z = v2->z;
  *(_QWORD *)&result->x = v3;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139D00
// Name: public: virtual void CParticleSystemQuery::DebugDrawLine(class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::DebugDrawLine(
        CParticleSystemQuery *this,
        const Vector *origin,
        const Vector *target,
        int r,
        int g,
        int b,
        int noDepthTest,
        float duration)
{
  ((void (__stdcall *)(const Vector *, const Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
    a1: origin,
    a2: target,
    a3: r,
    a4: g,
    a5: b,
    a6: noDepthTest,
    a7: LODWORD(duration));
}

//------------------------------------------------------------------------------
// Address: 0x10139D50
// Name: public: float CParticleCollection::RandomFloat(int,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CParticleCollection::RandomFloat(
        CParticleCollection *this,
        __int16 nRandomSampleId,
        float flMin,
        float flMax)
{
  return (flMax - flMin) * s_pRandomFloats[(nRandomSampleId + (unsigned __int16)this->m_nRandomSeed) & 0xFFF] + flMin;
}

//------------------------------------------------------------------------------
// Address: 0x10139D80
// Name: public: virtual bool IParticleSystemQuery::MovePointInsideControllingObject(class CParticleCollection __near *,void __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall IParticleSystemQuery::MovePointInsideControllingObject(
        C_BaseFlex *this,
        CSceneEventInfo *info,
        bool fastKill,
        bool canceled)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10139D90
// Name: public: virtual bool IParticleSystemQuery::IsPointInControllingObjectHitBox(class CParticleCollection __near *,int,class Vector,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall IParticleSystemQuery::IsPointInControllingObjectHitBox(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        Vector vecPos,
        bool bBBoxOnly)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10139DA0
// Name: public: virtual int IParticleSystemQuery::GetControllingObjectHitBoxInfo(class CParticleCollection __near *,int,int,struct ModelHitBoxInfo_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IParticleSystemQuery::GetControllingObjectHitBoxInfo(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        int nBufSize,
        ModelHitBoxInfo_t *pHitBoxOutputBuffer,
        ModelHitBoxInfo_t *pszHitboxSetName)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10139DB0
// Name: public: virtual void IParticleSystemQuery::GetControllingObjectOBBox(class CParticleCollection __near *,int,class Vector,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IParticleSystemQuery::GetControllingObjectOBBox(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        Vector vecMin,
        Vector vecMax)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10139DE0
// Name: public: virtual void IParticleSystemQuery::GetLocalPlayerEyeVectors(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IParticleSystemQuery::GetLocalPlayerEyeVectors(
        IParticleSystemQuery *this,
        Vector *pForward,
        Vector *pRight,
        Vector *pUp)
{
  *pForward = vec3_origin;
  *pRight = vec3_origin;
  *pUp = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x10139E70
// Name: public: virtual void CParticleSystemQuery::GetLightingAtPoint(class Vector const __near &,class Color __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::GetLightingAtPoint(
        CParticleSystemQuery *this,
        const Vector *vecOrigin,
        Color *cTint)
{
  DWORD CurrentThreadId; // ecx
  int v4; // edx
  float z; // xmm1_4
  Vector totalColor; // [esp+0h] [ebp-Ch] BYREF

  if ( engine->IsInGame(this: engine) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_LightMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_LightMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_LightMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_LightMutex.m_depth;
    }
    engine->GetLightForPoint(this: engine, result: &totalColor, a3: vecOrigin, a4: true);
    if ( --s_LightMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_LightMutex, 0);
    v4 = (int)(float)(totalColor.y * 255.0);
    z = totalColor.z;
    cTint->_color[0] = (int)(float)(totalColor.x * 255.0);
    cTint->_color[1] = v4;
    *(_WORD *)&cTint->_color[2] = (unsigned __int8)(int)(float)(z * 255.0);
  }
  else
  {
    *cTint = (Color)-1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139F50
// Name: public: virtual void CParticleSystemQuery::SetUpLightingEnvironment(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::SetUpLightingEnvironment(CParticleSystemQuery *this, const Vector *pos)
{
  DWORD CurrentThreadId; // ecx

  if ( engine->IsInGame(this: engine) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_LightMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_LightMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_LightMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_LightMutex.m_depth;
    }
    modelrender->SetupLighting(this: modelrender, a2: pos);
    if ( --s_LightMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_LightMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139FD0
// Name: public: virtual bool CParticleSystemQuery::IsPointInSolid(class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleSystemQuery::IsPointInSolid(
        CParticleSystemQuery *this,
        const Vector *vecPos,
        int nContentsMask)
{
  return engine->IsInGame(this: engine)
      && (nContentsMask & enginetrace->GetPointContents(this: enginetrace, a2: vecPos, a3: nContentsMask, a4: nullptr)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013A010
// Name: public: virtual int CParticleSystemQuery::GetControllingObjectHitBoxInfo(class CParticleCollection __near *,int,int,struct ModelHitBoxInfo_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSystemQuery::GetControllingObjectHitBoxInfo(
        CParticleSystemQuery *this,
        CParticleCollection *pParticles,
        int nControlPointNumber,
        int nBufSize,
        ModelHitBoxInfo_t *pHitBoxOutputBuffer,
        const char *pszHitboxSetName)
{
  DWORD CurrentThreadId; // ecx
  int v7; // eax
  unsigned int *m_pObject; // eax
  unsigned int v9; // ecx
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // edi
  C_BaseAnimating *v12; // eax
  IVModelInfoClient_vtbl *v13; // ebx
  int v14; // eax
  int v15; // ebx
  CStudioHdr *ModelPtr; // eax
  int HitboxSetByName; // eax
  int v18; // edx
  int v19; // eax
  float *p_z; // ecx
  int v21; // eax
  float *v22; // ebx
  matrix3x4_t *v23; // eax
  __int64 v24; // xmm2_8
  int v25; // eax
  __int64 v26; // xmm0_8
  __int64 v27; // xmm1_8
  __int64 v28; // xmm2_8
  __int64 v29; // xmm3_8
  __int64 v30; // xmm4_8
  __int64 v31; // xmm5_8
  matrix3x4_t *hitboxbones[256]; // [esp+4h] [ebp-41Ch] BYREF
  Vector vecMax; // [esp+404h] [ebp-1Ch] BYREF
  Vector vecMin; // [esp+410h] [ebp-10h] BYREF
  int nRet; // [esp+41Ch] [ebp-4h]
  int savedregs; // [esp+420h] [ebp+0h] BYREF
  C_BaseAnimating *i; // [esp+428h] [ebp+8h]
  int ia; // [esp+428h] [ebp+8h]
  int nControlPointNumbera; // [esp+42Ch] [ebp+Ch]

  nRet = 0;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_BoneMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_BoneMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_BoneMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_BoneMutex.m_depth;
  }
  v7 = pParticles->m_nNumControlPointsAllocated - 1;
  if ( nControlPointNumber < v7 )
    v7 = nControlPointNumber;
  m_pObject = (unsigned int *)pParticles->m_pCPInfo[v7].m_ControlPoint.m_pObject;
  if ( m_pObject != nullptr )
  {
    v9 = *m_pObject;
    if ( *m_pObject != -1 )
    {
      v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v9];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber == HIWORD(v9) )
      {
        m_pEntity = v10->m_pEntity;
        if ( v10->m_pEntity != nullptr )
        {
          v12 = (C_BaseAnimating *)m_pEntity->__vftable[14].GetRefEHandle(this: m_pEntity);
          i = v12;
          if ( v12 != nullptr && C_BaseAnimating::HitboxToWorldTransforms(this: v12, pHitboxToWorld: hitboxbones) != 0 )
          {
            v13 = modelinfo->__vftable;
            v14 = (int)i->GetModel(this: &i->IClientRenderable);
            v15 = (int)v13->GetStudiomodel(this: modelinfo, a2: (const struct model_t *)v14);
            if ( v15 != 0 )
            {
              ModelPtr = C_BaseAnimating::GetModelPtr(this: i);
              HitboxSetByName = FindHitboxSetByName(pstudiohdr: ModelPtr, name: pszHitboxSetName);
              if ( HitboxSetByName == -1 )
                HitboxSetByName = C_BaseAnimating::GetHitboxSet(this: i);
              v18 = v15 + *(_DWORD *)(v15 + 176) + 12 * HitboxSetByName;
              if ( v18 != 0 )
              {
                v19 = 0;
                ia = 0;
                if ( *(int *)(v18 + 4) > 0 )
                {
                  nControlPointNumbera = 0;
                  p_z = &pHitBoxOutputBuffer->m_vecBoxMins.z;
                  do
                  {
                    v21 = *(_DWORD *)(v18 + 8) + v18 + v19;
                    v22 = (float *)hitboxbones[*(_DWORD *)v21];
                    if ( fabs(v22[3]) >= 0.1 || fabs(v22[7]) >= 0.1 || fabs(v22[11]) >= 0.1 )
                    {
                      p_z += 18;
                      *(p_z - 20) = *(float *)(v21 + 8);
                      *(p_z - 19) = *(float *)(v21 + 12);
                      *(p_z - 18) = *(float *)(v21 + 16);
                      *(p_z - 17) = *(float *)(v21 + 20);
                      *(p_z - 16) = *(float *)(v21 + 24);
                      *(p_z - 15) = *(float *)(v21 + 28);
                      v23 = hitboxbones[*(_DWORD *)v21];
                      *((_QWORD *)p_z - 7) = *(_QWORD *)&v23->m_flMatVal[0][0];
                      *((_QWORD *)p_z - 6) = *(_QWORD *)&v23->m_flMatVal[0][2];
                      *((_QWORD *)p_z - 5) = *(_QWORD *)&v23->m_flMatVal[1][0];
                      *((_QWORD *)p_z - 4) = *(_QWORD *)&v23->m_flMatVal[1][2];
                      *((_QWORD *)p_z - 3) = *(_QWORD *)&v23->m_flMatVal[2][0];
                      v24 = *(_QWORD *)&v23->m_flMatVal[2][2];
                      v25 = nRet + 1;
                      *((_QWORD *)p_z - 2) = v24;
                      nRet = v25;
                      if ( v25 >= nBufSize )
                        break;
                    }
                    v19 = nControlPointNumbera + 68;
                    ++ia;
                    nControlPointNumbera += 68;
                  }
                  while ( ia < *(_DWORD *)(v18 + 4) );
                }
              }
            }
          }
          if ( C_BaseEntity::IsBrushModel(this: (C_BaseEntity *)m_pEntity) )
          {
            ((void (__thiscall *)(IHandleEntity_vtbl **, Vector *, Vector *))m_pEntity[1].__vftable[5].GetRefEHandle)(
              a1: &m_pEntity[1].__vftable,
              a2: &vecMin,
              a3: &vecMax);
            C_BaseEntity::CalcAbsolutePosition(this: (C_BaseEntity *)m_pEntity, a2: (int)&savedregs);
            v26 = *(_QWORD *)&m_pEntity[269].__vftable;
            v27 = *(_QWORD *)&m_pEntity[271].__vftable;
            v28 = *(_QWORD *)&m_pEntity[273].__vftable;
            v29 = *(_QWORD *)&m_pEntity[275].__vftable;
            v30 = *(_QWORD *)&m_pEntity[277].__vftable;
            v31 = *(_QWORD *)&m_pEntity[279].__vftable;
            pHitBoxOutputBuffer->m_vecBoxMins = vecMin;
            pHitBoxOutputBuffer->m_vecBoxMaxes = vecMax;
            *(_QWORD *)&pHitBoxOutputBuffer->m_Transform.m_flMatVal[0][0] = v26;
            *(_QWORD *)&pHitBoxOutputBuffer->m_Transform.m_flMatVal[0][2] = v27;
            *(_QWORD *)&pHitBoxOutputBuffer->m_Transform.m_flMatVal[1][0] = v28;
            *(_QWORD *)&pHitBoxOutputBuffer->m_Transform.m_flMatVal[1][2] = v29;
            *(_QWORD *)&pHitBoxOutputBuffer->m_Transform.m_flMatVal[2][0] = v30;
            *(_QWORD *)&pHitBoxOutputBuffer->m_Transform.m_flMatVal[2][2] = v31;
            nRet = 1;
          }
        }
      }
    }
  }
  if ( --s_BoneMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_BoneMutex, 0);
  return nRet;
}

//------------------------------------------------------------------------------
// Address: 0x1013A310
// Name: public: virtual void CParticleSystemQuery::GetControllingObjectOBBox(class CParticleCollection __near *,int,class Vector,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::GetControllingObjectOBBox(
        CParticleSystemQuery *this,
        CParticleCollection *pParticles,
        int nControlPointNumber,
        Vector vecMin,
        Vector vecMax)
{
  int v5; // eax
  unsigned int *m_pObject; // eax
  unsigned int v7; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity *v9; // esi

  v5 = pParticles->m_nNumControlPointsAllocated - 1;
  if ( nControlPointNumber < v5 )
    v5 = nControlPointNumber;
  m_pObject = (unsigned int *)pParticles->m_pCPInfo[v5].m_ControlPoint.m_pObject;
  if ( m_pObject != nullptr )
  {
    v7 = *m_pObject;
    if ( *m_pObject != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      if ( m_pEntity != nullptr )
      {
        v9 = m_pEntity + 195;
        ((void (__thiscall *)(IHandleEntity *))m_pEntity[195].SetRefEHandle)(a1: &m_pEntity[195]);
        v9->GetRefEHandle(this: v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A3D0
// Name: public: virtual void CParticleSystemQuery::GetLocalPlayerEyeVectors(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::GetLocalPlayerEyeVectors(
        CParticleSystemQuery *this,
        Vector *pForward,
        Vector *pRight,
        Vector *pUp)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    C_BasePlayer::EyeVectors(this: LocalPlayer, pForward, pRight, pUp);
  }
  else
  {
    *pForward = vec3_origin;
    *pRight = vec3_origin;
    *pUp = vec3_origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A470
// Name: public: virtual float CParticleSystemQuery::GetPixelVisibility(int __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CParticleSystemQuery::GetPixelVisibility(
        CParticleSystemQuery *this,
        int *pQueryHandle,
        const Vector *vecOrigin,
        float flScale)
{
  double result; // st7
  pixelvis_queryparams_t params; // [esp+0h] [ebp-1Ch] BYREF

  params.position = *vecOrigin;
  params.proxySize = flScale;
  params.proxyAspect = 1.0;
  params.fadeTime = 0.0625;
  *(_WORD *)&params.bSetup = 1;
  result = PixelVisibility_FractionVisible(&params, queryHandle: pQueryHandle);
  if ( result < 0.0 )
    return 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013A4F0
// Name: public: virtual void CBaseAppSystem<class IParticleSystemQuery>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IParticleSystemQuery>::Reconnect(
        CBaseAppSystem<IParticleSystemQuery> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1013A510
// Name: public: virtual void CParticleSystemQuery::TraceLine(class Vector const __near &,class Vector const __near &,unsigned int,class IHandleEntity const __near *,int,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleSystemQuery::TraceLine(
        CParticleSystemQuery *this@<ecx>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        const IHandleEntity *ignore,
        int collisionGroup,
        CBaseTrace *ptr)
{
  CGameTrace tempTrace; // [esp+0h] [ebp-54h] BYREF
  IHandleEntity savedregs; // [esp+54h] [ebp+0h] BYREF

  if ( engine->IsInGame(this: engine) )
  {
    UTIL_TraceLine(a1: &savedregs, a2, vecAbsStart, vecAbsEnd, mask, ignore, collisionGroup, ptr: &tempTrace);
    *ptr = tempTrace.CBaseTrace;
  }
  else
  {
    ptr->startsolid = false;
    ptr->fraction = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A580
// Name: public: virtual bool CParticleSystemQuery::MovePointInsideControllingObject(class CParticleCollection __near *,void __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __userpurge CParticleSystemQuery::MovePointInsideControllingObject@<al>(
        CParticleSystemQuery *this@<ecx>,
        int a2@<ebp>,
        CParticleCollection *pParticles,
        IHandleEntity *pObject,
        Vector *pPnt)
{
  float z; // xmm0_4
  int v7; // [esp-Ch] [ebp-B4h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-A8h] BYREF
  float v9; // [esp+54h] [ebp-54h]
  Ray_t ray; // [esp+58h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+A8h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a2;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  if ( pObject == nullptr )
    return 1;
  ray.m_Extents.y = 0.0;
  memset(&ray.m_Start.y, 0, 12);
  memset(&ray.m_StartOffset.y, 0, 12);
  memset(&ray.m_Delta.y, 0, 12);
  tr.m_pEnt = (struct CBaseEntity *)LODWORD(pPnt->x);
  tr.hitbox = LODWORD(pPnt->y);
  z = pPnt->z;
  LOWORD(ray.m_Extents.z) = 1;
  v9 = z;
  enginetrace->ClipRayToEntity(
    this: enginetrace,
    a2: (const Ray_t *)&tr.m_pEnt,
    a3: -1u,
    a4: pObject,
    a5: (CGameTrace *)&v7);
  return tr.plane.pad[1];
}

//------------------------------------------------------------------------------
// Address: 0x1013A640
// Name: public: virtual void CParticleSystemQuery::GetRandomPointsOnControllingObjectHitBox(class CParticleCollection __near *,int,int,float,int,class Vector __near *,class Vector,class Vector __near *,int __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CParticleSystemQuery::GetRandomPointsOnControllingObjectHitBox(
        CParticleSystemQuery *this@<ecx>,
        float a2@<ebp>,
        CParticleCollection *pParticles,
        int nControlPointNumber,
        float nNumPtsOut,
        float flBBoxScale,
        int nNumTrysToGetAPointInsideTheModel,
        Vector *pPntsOut,
        Vector vecDirectionalBias,
        Vector *pHitBoxRelativeCoordOut,
        int *pHitBoxIndexOut,
        float nDesiredHitbox,
        const char *pszHitboxSetName)
{
  int v13; // eax
  unsigned int *m_pObject; // eax
  unsigned int v15; // ecx
  int v16; // edi
  DWORD CurrentThreadId; // eax
  C_BaseAnimating *v18; // edi
  IClientRenderable_vtbl *v19; // eax
  IClientRenderable *v20; // ecx
  IVModelInfoClient_vtbl *v21; // edi
  int v22; // eax
  int v23; // edi
  CStudioHdr *ModelPtr; // eax
  int HitboxSetByName; // eax
  int v26; // edi
  bool v27; // zf
  float v28; // edi
  int v29; // eax
  int m_nRandomQueryCount; // ecx
  int m_nRandomSeed; // eax
  int v32; // edx
  int v33; // edi
  float *v34; // ecx
  float v35; // xmm2_4
  __int16 v36; // cx
  float v37; // xmm1_4
  int v38; // edx
  double ModelHierarchyScale; // st7
  double v40; // st7
  double v41; // st7
  int v42; // eax
  float v43; // xmm5_4
  float v44; // xmm0_4
  float x; // xmm0_4
  int v46; // edx
  Vector *v47; // eax
  Vector *v48; // ecx
  int *v49; // eax
  int v50; // edi
  float v51; // xmm4_4
  float v52; // xmm3_4
  int v53; // edx
  int v54; // ecx
  __int16 v55; // ax
  float v56; // xmm0_4
  int v57; // xmm1_4
  float v58; // xmm2_4
  int v59; // eax
  float v60; // xmm5_4
  float y; // xmm4_4
  float z; // xmm3_4
  float v63; // xmm0_4
  int v64; // edx
  float v65; // xmm2_4
  float v66; // xmm0_4
  int v67; // ecx
  Vector *v68; // eax
  Vector *v69; // ecx
  int *v70; // eax
  float v71; // edx
  float *p_z; // ecx
  int v73; // eax
  CParticleCPInfo *v74; // eax
  double v75; // st7
  int *v76; // eax
  float v77; // eax
  const char *tolerance; // [esp+Ch] [ebp-660h]
  matrix3x4_t *v79[3]; // [esp+20h] [ebp-64Ch] BYREF
  matrix3x4_t *hitboxbones[256]; // [esp+2Ch] [ebp-640h] BYREF
  char v81; // [esp+457h] [ebp-215h]
  int v82; // [esp+478h] [ebp-1F4h] BYREF
  CGameTrace tr; // [esp+484h] [ebp-1E8h] BYREF
  _BYTE v84[52]; // [esp+4D8h] [ebp-194h] OVERLAPPED BYREF
  int v85; // [esp+510h] [ebp-15Ch]
  int v86; // [esp+514h] [ebp-158h]
  int v87; // [esp+518h] [ebp-154h]
  int v88; // [esp+520h] [ebp-14Ch]
  __int64 v89; // [esp+524h] [ebp-148h]
  int v90; // [esp+530h] [ebp-13Ch]
  __int64 v91; // [esp+534h] [ebp-138h]
  int v92; // [esp+540h] [ebp-12Ch]
  __int16 v93; // [esp+544h] [ebp-128h]
  _DWORD v94[3]; // [esp+550h] [ebp-11Ch] BYREF
  Ray_t ray; // [esp+55Ch] [ebp-110h] BYREF
  float v96[3]; // [esp+5ACh] [ebp-C0h] BYREF
  float v97[3]; // [esp+5B8h] [ebp-B4h] BYREF
  Vector vecLocalPosition; // [esp+5C4h] [ebp-A8h] BYREF
  Vector vecMin; // [esp+5D0h] [ebp-9Ch] BYREF
  Vector vecMax; // [esp+5DCh] [ebp-90h] BYREF
  float v101[3]; // [esp+5E8h] [ebp-84h] BYREF
  Vector vecTryWorldPosition; // [esp+5F4h] [ebp-78h]
  float flPointGoodness; // [esp+600h] [ebp-6Ch] BYREF
  float flTryU; // [esp+604h] [ebp-68h]
  int nNumIters; // [esp+608h] [ebp-64h]
  Vector vecBasePos; // [esp+60Ch] [ebp-60h]
  mstudiohitboxset_t *set; // [esp+618h] [ebp-54h]
  float v108; // [esp+61Ch] [ebp-50h]
  Vector vecWorldPosition; // [esp+620h] [ebp-4Ch]
  int nHitboxMin; // [esp+62Ch] [ebp-40h]
  float w; // [esp+630h] [ebp-3Ch]
  int nHitbox; // [esp+634h] [ebp-38h]
  float flBestPointGoodness; // [esp+638h] [ebp-34h]
  float v; // [esp+63Ch] [ebp-30h]
  float flTryW; // [esp+640h] [ebp-2Ch]
  float flTryV; // [esp+644h] [ebp-28h]
  int nTryCnt; // [esp+648h] [ebp-24h]
  int u; // [esp+64Ch] [ebp-20h]
  int nTryHitbox; // [esp+650h] [ebp-1Ch]
  float v120; // [esp+654h] [ebp-18h]
  C_BaseAnimating *v121; // [esp+658h] [ebp-14h]
  studiohdr_t *pStudioHdr; // [esp+65Ch] [ebp-10h]
  float flRandMin; // [esp+660h] [ebp-Ch] BYREF
  C_BaseAnimating *pAnimating; // [esp+664h] [ebp-8h]
  C_BaseAnimating *retaddr; // [esp+66Ch] [ebp+0h]

  flRandMin = a2;
  pAnimating = retaddr;
  v13 = pParticles->m_nNumControlPointsAllocated - 1;
  HIBYTE(pStudioHdr) = 0;
  if ( nControlPointNumber < v13 )
    v13 = nControlPointNumber;
  m_pObject = (unsigned int *)pParticles->m_pCPInfo[v13].m_ControlPoint.m_pObject;
  if ( m_pObject == nullptr )
    goto LABEL_71;
  v15 = *m_pObject;
  if ( *m_pObject == -1 )
    goto LABEL_71;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
    goto LABEL_71;
  nTryCnt = (int)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
  v16 = nTryCnt;
  if ( nTryCnt == 0 )
    goto LABEL_71;
  v120 = 1.0 - flBBoxScale;
  CParticleCollection::GetControlPointAtTime(
    this: pParticles,
    nControlPoint: nControlPointNumber,
    flTime: pParticles->m_flCurTime,
    pControlPoint: (Vector *)&flPointGoodness);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_BoneMutex.m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)&s_BoneMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_BoneMutex, a2: CurrentThreadId, a3: 0);
      v16 = nTryCnt;
      goto LABEL_12;
    }
    v16 = nTryCnt;
  }
  ++s_BoneMutex.m_depth;
LABEL_12:
  v18 = (C_BaseAnimating *)(*(int (__thiscall **)(int))(*(_DWORD *)v16 + 176))(a1: v16);
  v121 = v18;
  if ( v18 != nullptr && C_BaseAnimating::HitboxToWorldTransforms(this: v18, pHitboxToWorld: v79) != 0 )
  {
    v19 = v18->C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
    v20 = &v18->IClientRenderable;
    v21 = modelinfo->__vftable;
    v22 = (int)v19->GetModel(this: v20);
    v23 = (int)v21->GetStudiomodel(this: modelinfo, a2: (const struct model_t *)v22);
    nTryHitbox = v23;
    if ( v23 != 0 )
    {
      tolerance = pszHitboxSetName;
      ModelPtr = C_BaseAnimating::GetModelPtr(this: v121);
      HitboxSetByName = FindHitboxSetByName(pstudiohdr: ModelPtr, name: tolerance);
      if ( HitboxSetByName == -1 )
        HitboxSetByName = C_BaseAnimating::GetHitboxSet(this: v121);
      v26 = *(_DWORD *)(v23 + 176) + 12 * HitboxSetByName;
      v27 = nTryHitbox + v26 == 0;
      LODWORD(v28) = nTryHitbox + v26;
      vecBasePos.x = v28;
      if ( !v27 )
      {
        flTryW = 0.0;
        w = 0.0;
        vecWorldPosition.y = 0.0;
        LODWORD(vecTryWorldPosition.z) = nNumTrysToGetAPointInsideTheModel;
        HIBYTE(pStudioHdr) = 1;
        vecWorldPosition.z = 0.0;
        if ( !Vector::IsZero(this: &vecDirectionalBias, tolerance: 0.000099999997)
          && nNumTrysToGetAPointInsideTheModel <= 5 )
        {
          LODWORD(vecTryWorldPosition.z) = 5;
        }
        v29 = *(_DWORD *)(LODWORD(v28) + 4) - 1;
        vecWorldPosition.x = 0.0;
        if ( nDesiredHitbox >= 0.0 )
        {
          LODWORD(vecWorldPosition.x) = v29;
          if ( v29 >= SLODWORD(nDesiredHitbox) )
          {
            vecWorldPosition.x = nDesiredHitbox;
            v29 = LODWORD(nDesiredHitbox);
          }
        }
        if ( SLODWORD(nNumPtsOut) > 0 )
        {
          vecBasePos.y = (float)(v29 - LODWORD(vecWorldPosition.x) + 1);
          for ( nTryHitbox = LODWORD(nNumPtsOut); nTryHitbox != 0; --nTryHitbox )
          {
            v = vecTryWorldPosition.z;
            *(float *)&nHitboxMin = -1.0e20;
            do
            {
              m_nRandomQueryCount = pParticles->m_nRandomQueryCount;
              m_nRandomSeed = pParticles->m_nRandomSeed;
              v32 = m_nRandomQueryCount + 1;
              pParticles->m_nRandomQueryCount = m_nRandomQueryCount + 1;
              LODWORD(flTryV) = LODWORD(vecWorldPosition.x)
                              + (int)(float)(s_pRandomFloats[((_WORD)m_nRandomSeed + (_WORD)m_nRandomQueryCount) & 0xFFF]
                                           * vecBasePos.y);
              v33 = LODWORD(vecBasePos.x) + *(_DWORD *)(LODWORD(vecBasePos.x) + 8) + 68 * LODWORD(flTryV);
              v34 = (float *)v79[*(_DWORD *)v33];
              if ( fabs(v34[3]) >= 0.1 || fabs(v34[7]) >= 0.1 || fabs(v34[11]) >= 0.1 )
              {
                v35 = v120;
                v36 = v32 + 1;
                pParticles->m_nRandomQueryCount = v32 + 1;
                v37 = s_pRandomFloats[((_WORD)m_nRandomSeed + (_WORD)v32) & 0xFFF];
                v38 = v32 + 2;
                vecTryWorldPosition.y = (float)(v37 * (float)(flBBoxScale - v35)) + v35;
                pParticles->m_nRandomQueryCount = v38;
                flBestPointGoodness = (float)(s_pRandomFloats[((_WORD)m_nRandomSeed + v36) & 0xFFF]
                                            * (float)(flBBoxScale - v35))
                                    + v35;
                pParticles->m_nRandomQueryCount = v38 + 1;
                *(float *)&nHitbox = (float)(s_pRandomFloats[((_WORD)m_nRandomSeed + (_WORD)v38) & 0xFFF]
                                           * (float)(flBBoxScale - v35))
                                   + v35;
                *(float *)&u = C_BaseAnimating::GetModelHierarchyScale(this: v121) * *(float *)(v33 + 8);
                ModelHierarchyScale = C_BaseAnimating::GetModelHierarchyScale(this: v121);
                v97[0] = *(float *)&u
                       + (ModelHierarchyScale * *(float *)(v33 + 20) - *(float *)&u) * vecTryWorldPosition.y;
                *(float *)&u = C_BaseAnimating::GetModelHierarchyScale(this: v121) * *(float *)(v33 + 12);
                v40 = C_BaseAnimating::GetModelHierarchyScale(this: v121);
                v97[1] = *(float *)&u + (v40 * *(float *)(v33 + 24) - *(float *)&u) * flBestPointGoodness;
                *(float *)&u = C_BaseAnimating::GetModelHierarchyScale(this: v121) * *(float *)(v33 + 16);
                v41 = C_BaseAnimating::GetModelHierarchyScale(this: v121);
                v97[2] = *(float *)&u + (v41 * *(float *)(v33 + 28) - *(float *)&u) * *(float *)&nHitbox;
                VectorTransform(in1: v97, in2: v79[*(_DWORD *)v33], out: v101);
                v42 = pParticles->m_nRandomQueryCount;
                v43 = v101[0];
                v44 = v101[0] - flPointGoodness;
                pParticles->m_nRandomQueryCount = v42 + 1;
                x = (float)((float)((float)(v44 * vecDirectionalBias.x)
                                  + (float)(vecDirectionalBias.y * (float)(v101[1] - flTryU)))
                          + (float)(vecDirectionalBias.z * (float)(v101[2] - *(float *)&nNumIters)))
                  + (float)(s_pRandomFloats[((_WORD)v42 + (unsigned __int16)pParticles->m_nRandomSeed) & 0xFFF] * 72.0);
                vecTryWorldPosition.x = x;
                if ( nNumTrysToGetAPointInsideTheModel != 0 )
                {
                  ray.m_Extents.y = 0.0;
                  memset(&ray.m_Start.y, 0, 12);
                  memset(&ray.m_StartOffset.y, 0, 12);
                  LOWORD(ray.m_Extents.z) = 1;
                  memset(&ray.m_Delta.y, 0, 12);
                  *(float *)v94 = v43;
                  *(float *)&v94[1] = v101[1];
                  *(float *)&v94[2] = v101[2];
                  enginetrace->ClipRayToEntity(
                    this: enginetrace,
                    a2: (const Ray_t *)v94,
                    a3: -1u,
                    a4: (IHandleEntity *)nTryCnt,
                    a5: (CGameTrace *)&v82);
                  if ( tr.plane.pad[1] != 0 )
                    x = vecTryWorldPosition.x + 1000.0;
                  else
                    x = vecTryWorldPosition.x;
                }
                if ( x > *(float *)&nHitboxMin )
                {
                  flTryW = vecTryWorldPosition.y;
                  w = flBestPointGoodness;
                  LODWORD(vecWorldPosition.y) = nHitbox;
                  vecBasePos.z = v101[0];
                  set = (mstudiohitboxset_t *)LODWORD(v101[1]);
                  v108 = v101[2];
                  vecWorldPosition.z = flTryV;
                  *(float *)&nHitboxMin = x;
                }
              }
              v46 = LODWORD(v)--;
            }
            while ( v46 != 0 );
            v47 = pPntsOut;
            pPntsOut->x = vecBasePos.z;
            ++pPntsOut;
            v48 = pHitBoxRelativeCoordOut;
            LODWORD(v47->y) = set;
            v47->z = v108;
            if ( v48 != nullptr )
            {
              v48->x = flTryW;
              v48->y = w;
              pHitBoxRelativeCoordOut = v48 + 1;
              v48->z = vecWorldPosition.y;
            }
            v49 = pHitBoxIndexOut;
            if ( pHitBoxIndexOut != nullptr )
            {
              *pHitBoxIndexOut = LODWORD(vecWorldPosition.z);
              pHitBoxIndexOut = v49 + 1;
            }
          }
        }
      }
    }
  }
  v50 = nTryCnt;
  if ( C_BaseEntity::IsBrushModel(this: (C_BaseEntity *)nTryCnt) )
  {
    (*(void (__thiscall **)(int, Vector *, Vector *))(*(_DWORD *)(v50 + 4) + 68))(
      a1: v50 + 4,
      a2: &vecLocalPosition,
      a3: &vecMin);
    (*(void (__thiscall **)(int))(*(_DWORD *)(v50 + 4) + 4))(a1: v50 + 4);
    C_BaseEntity::CalcAbsolutePosition(this: (C_BaseEntity *)v50, a2: (int)&flRandMin);
    *(_QWORD *)&tr.m_pEnt = *(_QWORD *)(v50 + 1076);
    qmemcpy(v84, (const void *)(v50 + 1084), 40);
    v = 0.0;
    *(float *)&nHitboxMin = 0.0;
    *(float *)&nHitbox = 0.0;
    nTryHitbox = nNumTrysToGetAPointInsideTheModel;
    if ( (vecDirectionalBias.x <= -0.000099999997
       || vecDirectionalBias.x >= 0.000099999997
       || vecDirectionalBias.y <= -0.000099999997
       || vecDirectionalBias.y >= 0.000099999997
       || vecDirectionalBias.z <= -0.000099999997
       || vecDirectionalBias.z >= 0.000099999997)
      && nNumTrysToGetAPointInsideTheModel <= 5 )
    {
      nTryHitbox = 5;
    }
    if ( SLODWORD(nNumPtsOut) > 0 )
    {
      v51 = v120;
      v52 = flBBoxScale - v120;
      vecWorldPosition.z = flBBoxScale - v120;
      flBestPointGoodness = nNumPtsOut;
      while ( 1 )
      {
        LODWORD(flTryW) = nTryHitbox;
        w = -1.0e20;
        while ( 1 )
        {
          v53 = pParticles->m_nRandomQueryCount;
          v54 = pParticles->m_nRandomSeed;
          v55 = v53 + 1;
          pParticles->m_nRandomQueryCount = v53 + 1;
          v56 = s_pRandomFloats[((_WORD)v54 + (_WORD)v53) & 0xFFF];
          v53 += 2;
          pParticles->m_nRandomQueryCount = v53;
          *(float *)&v57 = (float)(s_pRandomFloats[((_WORD)v54 + v55) & 0xFFF] * v52) + v51;
          pParticles->m_nRandomQueryCount = v53 + 1;
          v58 = (float)(s_pRandomFloats[((_WORD)v54 + (_WORD)v53) & 0xFFF] * v52) + v51;
          u = v57;
          flTryV = (float)(v56 * v52) + v51;
          vecBasePos.y = v58;
          v96[0] = (float)((float)(vecMin.x - vecLocalPosition.x) * flTryV) + vecLocalPosition.x;
          v96[1] = (float)((float)(vecMin.y - vecLocalPosition.y) * *(float *)&v57) + vecLocalPosition.y;
          v96[2] = (float)((float)(vecMin.z - vecLocalPosition.z) * v58) + vecLocalPosition.z;
          VectorTransform(in1: v96, in2: (const matrix3x4_t *)&tr.m_pEnt, out: &vecMax.x);
          v59 = pParticles->m_nRandomQueryCount;
          v60 = vecMax.x;
          y = vecMax.y;
          z = vecMax.z;
          v63 = (float)((float)(vecMax.x - flPointGoodness) * vecDirectionalBias.x)
              + (float)((float)(vecMax.y - flTryU) * vecDirectionalBias.y);
          v64 = ((_WORD)v59 + (unsigned __int16)pParticles->m_nRandomSeed) & 0xFFF;
          v65 = (float)(vecMax.z - *(float *)&nNumIters) * vecDirectionalBias.z;
          pParticles->m_nRandomQueryCount = v59 + 1;
          v66 = (float)(v63 + v65) + (float)(s_pRandomFloats[v64] * 72.0);
          vecWorldPosition.y = v66;
          if ( nNumTrysToGetAPointInsideTheModel != 0 )
          {
            v92 = 0;
            v85 = 0;
            v86 = 0;
            v87 = 0;
            v91 = 0;
            v90 = 0;
            v93 = 1;
            v89 = 0;
            v88 = 0;
            *(float *)&v84[40] = v60;
            *(float *)&v84[44] = y;
            *(float *)&v84[48] = z;
            enginetrace->ClipRayToEntity(
              this: enginetrace,
              a2: (const Ray_t *)&v84[40],
              a3: -1u,
              a4: (IHandleEntity *)nTryCnt,
              a5: (CGameTrace *)&hitboxbones[253]);
            if ( v81 != 0 )
              v66 = vecWorldPosition.y + 1000.0;
            else
              v66 = vecWorldPosition.y;
          }
          if ( v66 > w )
          {
            v = flTryV;
            nHitboxMin = u;
            nHitbox = SLODWORD(vecBasePos.y);
            vecBasePos.z = vecMax.x;
            set = (mstudiohitboxset_t *)LODWORD(vecMax.y);
            v108 = vecMax.z;
            w = v66;
          }
          v67 = LODWORD(flTryW)--;
          if ( v67 == 0 )
            break;
          v52 = vecWorldPosition.z;
          v51 = v120;
        }
        v68 = pPntsOut;
        pPntsOut->x = vecBasePos.z;
        ++pPntsOut;
        v69 = pHitBoxRelativeCoordOut;
        LODWORD(v68->y) = set;
        v68->z = v108;
        if ( v69 != nullptr )
        {
          v69->x = v;
          v69->y = *(float *)&nHitboxMin;
          pHitBoxRelativeCoordOut = v69 + 1;
          v69->z = *(float *)&nHitbox;
        }
        v70 = pHitBoxIndexOut;
        if ( pHitBoxIndexOut != nullptr )
        {
          *pHitBoxIndexOut = 0;
          pHitBoxIndexOut = v70 + 1;
        }
        --LODWORD(flBestPointGoodness);
        if ( flBestPointGoodness == 0.0 )
          break;
        v52 = vecWorldPosition.z;
        v51 = v120;
      }
    }
  }
  if ( --s_BoneMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_BoneMutex, 0);
  if ( HIBYTE(pStudioHdr) == 0 )
  {
LABEL_71:
    v71 = 0.0;
    if ( SLODWORD(nNumPtsOut) > 0 )
    {
      v120 = *(float *)&pHitBoxRelativeCoordOut;
      LODWORD(flTryV) = (char *)pHitBoxRelativeCoordOut - (char *)pPntsOut;
      p_z = &pPntsOut->z;
      do
      {
        v73 = pParticles->m_nNumControlPointsAllocated - 1;
        if ( nControlPointNumber < v73 )
          v73 = nControlPointNumber;
        v74 = &pParticles->m_pCPInfo[v73];
        *(p_z - 2) = v74->m_ControlPoint.m_Position.x;
        *(p_z - 1) = v74->m_ControlPoint.m_Position.y;
        v75 = v74->m_ControlPoint.m_Position.z;
        v76 = pHitBoxIndexOut;
        *p_z = v75;
        if ( v76 != nullptr )
          v76[LODWORD(v71)] = 0;
        if ( *(float *)&pHitBoxRelativeCoordOut != 0.0 )
        {
          v77 = v120;
          *(_DWORD *)LODWORD(v120) = 0;
          *(_DWORD *)(LODWORD(v77) + 4) = 0;
          *(float *)((char *)p_z + LODWORD(flTryV)) = 0.0;
        }
        LODWORD(v120) += 12;
        ++LODWORD(v71);
        p_z += 3;
      }
      while ( SLODWORD(v71) < SLODWORD(nNumPtsOut) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B130
// Name: public: virtual void CParticleSystemQuery::GetClosestControllingObjectHitBox(class CParticleCollection __near *,int,int,float,class Vector __near *,class Vector __near *,int __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CParticleSystemQuery::GetClosestControllingObjectHitBox(
        CParticleSystemQuery *this@<ecx>,
        int a2@<ebp>,
        CParticleCollection *pParticles,
        int nControlPointNumber,
        int nNumPtsIn,
        float flBBoxScale,
        Vector *pPntsIn,
        Vector *pHitBoxRelativeCoordOut,
        int *pHitBoxIndexOut,
        int nDesiredHitbox,
        const char *pszHitboxSetName)
{
  int v11; // eax
  unsigned int *m_pObject; // eax
  unsigned int v13; // ecx
  int v14; // esi
  DWORD CurrentThreadId; // eax
  C_BaseAnimating *v16; // eax
  IVModelInfoClient_vtbl *v17; // esi
  const struct model_t *v18; // eax
  int v19; // esi
  CStudioHdr *ModelPtr; // eax
  int HitboxSetByName; // eax
  int v22; // ecx
  bool v23; // zf
  float v24; // ecx
  int v25; // edx
  int v26; // eax
  int *v27; // esi
  Vector *v28; // eax
  __int64 v29; // xmm1_8
  float z; // eax
  mstudiohitboxset_t *v31; // xmm1_4
  int v32; // eax
  float x; // xmm0_4
  int m_nRandomQueryCount; // edx
  int v35; // esi
  int m_nRandomSeed; // ecx
  __int16 v37; // ax
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float m_Value; // xmm0_4
  float v44; // xmm4_4
  const matrix3x4_t *v45; // edx
  float v46; // xmm1_4
  float v47; // xmm2_4
  __int128 v48; // xmm0
  bool v49; // cc
  Vector *v50; // eax
  int v51; // eax
  float *p_z; // ecx
  const matrix3x4_t *flTime; // [esp+0h] [ebp-4D4h]
  matrix3x4_t *v54[3]; // [esp+18h] [ebp-4BCh] BYREF
  float hitboxbones[257]; // [esp+24h] [ebp-4B0h] BYREF
  __int128 vecTryWorldPosition; // [esp+428h] [ebp-ACh] OVERLAPPED
  Vector v57; // [esp+444h] [ebp-90h] BYREF
  Vector vecBasePos; // [esp+450h] [ebp-84h] BYREF
  Vector vecLocalPosition; // [esp+45Ch] [ebp-78h] BYREF
  __int64 v60; // [esp+468h] [ebp-6Ch]
  float v61; // [esp+470h] [ebp-64h]
  Vector vecCurrentPoint; // [esp+474h] [ebp-60h]
  float v63; // [esp+480h] [ebp-54h] BYREF
  float flTryV; // [esp+484h] [ebp-50h]
  float flTryU; // [esp+488h] [ebp-4Ch]
  Vector vecBoxDistance; // [esp+48Ch] [ebp-48h]
  int flTryW; // [esp+498h] [ebp-3Ch]
  float flBestPointGoodness; // [esp+49Ch] [ebp-38h]
  mstudiohitboxset_t *set; // [esp+4A0h] [ebp-34h]
  int v70; // [esp+4A4h] [ebp-30h]
  unsigned __int64 u; // [esp+4A8h] [ebp-2Ch] OVERLAPPED
  float v72; // [esp+4B0h] [ebp-24h]
  int w; // [esp+4B4h] [ebp-20h]
  C_BaseAnimating *v; // [esp+4B8h] [ebp-1Ch]
  int nHitbox; // [esp+4BCh] [ebp-18h]
  int j; // [esp+4C0h] [ebp-14h]
  C_BaseAnimating *pAnimating; // [esp+4C4h] [ebp-10h]
  int nHitboxMax; // [esp+4C8h] [ebp-Ch]
  int nHitboxMin; // [esp+4CCh] [ebp-8h]
  int retaddr; // [esp+4D4h] [ebp+0h]

  nHitboxMax = a2;
  nHitboxMin = retaddr;
  v11 = pParticles->m_nNumControlPointsAllocated - 1;
  HIBYTE(pAnimating) = 0;
  if ( nControlPointNumber < v11 )
    v11 = nControlPointNumber;
  m_pObject = (unsigned int *)pParticles->m_pCPInfo[v11].m_ControlPoint.m_pObject;
  if ( m_pObject == nullptr
    || (v13 = *m_pObject, *m_pObject == -1)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13)
    || (j = (int)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity, v14 = j, j == 0) )
  {
    v27 = pHitBoxIndexOut;
LABEL_45:
    v51 = 0;
    if ( nNumPtsIn > 0 )
    {
      p_z = &pHitBoxRelativeCoordOut->z;
      do
      {
        if ( v27 != nullptr )
          v27[v51] = 0;
        if ( pHitBoxRelativeCoordOut != nullptr )
        {
          *(p_z - 2) = 0.0;
          *(p_z - 1) = 0.0;
          *p_z = 0.0;
        }
        ++v51;
        p_z += 3;
      }
      while ( v51 < nNumPtsIn );
    }
    return;
  }
  *(float *)&set = 1.0 - flBBoxScale;
  CParticleCollection::GetControlPointAtTime(
    this: pParticles,
    nControlPoint: nControlPointNumber,
    flTime: pParticles->m_flCurTime,
    pControlPoint: &v57);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == s_BoneMutex.m_ownerID )
    goto LABEL_10;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)&s_BoneMutex, CurrentThreadId, 0) == 0 )
  {
    v14 = j;
LABEL_10:
    ++s_BoneMutex.m_depth;
    goto LABEL_12;
  }
  _mm_pause();
  CThreadFastMutex::Lock(a1: &s_BoneMutex, a2: CurrentThreadId, a3: 0);
  v14 = j;
LABEL_12:
  v16 = (C_BaseAnimating *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 176))(a1: v14);
  v = v16;
  if ( v16 == nullptr )
    goto LABEL_39;
  if ( C_BaseAnimating::HitboxToWorldTransforms(this: v16, pHitboxToWorld: v54) == 0 )
    goto LABEL_39;
  v17 = modelinfo->__vftable;
  v18 = v->GetModel(this: &v->IClientRenderable);
  v19 = (int)v17->GetStudiomodel(this: modelinfo, a2: v18);
  if ( v19 == 0 )
    goto LABEL_39;
  ModelPtr = C_BaseAnimating::GetModelPtr(this: v);
  HitboxSetByName = FindHitboxSetByName(pstudiohdr: ModelPtr, name: pszHitboxSetName);
  if ( HitboxSetByName == -1 )
    HitboxSetByName = C_BaseAnimating::GetHitboxSet(this: v);
  v22 = *(_DWORD *)(v19 + 176) + 12 * HitboxSetByName;
  v23 = v19 + v22 == 0;
  LODWORD(v24) = v19 + v22;
  vecBoxDistance.z = v24;
  if ( v23 )
    goto LABEL_39;
  v25 = 0;
  v26 = *(_DWORD *)(LODWORD(v24) + 4) - 1;
  HIBYTE(pAnimating) = 1;
  flBestPointGoodness = 0.0;
  u = 0;
  v72 = 0.0;
  j = 0;
  nHitbox = v26;
  if ( nDesiredHitbox >= 0 )
  {
    if ( v26 >= nDesiredHitbox )
    {
      v25 = nDesiredHitbox;
      j = nDesiredHitbox;
    }
    else
    {
      v25 = v26;
      j = v26;
    }
    nHitbox = v26;
    if ( v26 >= nDesiredHitbox )
      nHitbox = nDesiredHitbox;
  }
  if ( nNumPtsIn > 0 )
  {
    v27 = pHitBoxIndexOut;
    for ( flTryW = nNumPtsIn; flTryW != 0; --flTryW )
    {
      v28 = pPntsIn++;
      vecBoxDistance.y = 3.4028235e38;
      v29 = *(_QWORD *)&v28->x;
      z = v28->z;
      v60 = v29;
      v61 = z;
      w = v25;
      if ( v25 < nHitbox )
      {
        v31 = set;
        v32 = 68 * v25;
        x = flBBoxScale - *(float *)&set;
        vecCurrentPoint.x = flBBoxScale - *(float *)&set;
        v70 = 68 * v25;
        while ( 1 )
        {
          m_nRandomQueryCount = pParticles->m_nRandomQueryCount;
          v35 = LODWORD(v24) + v32 + *(_DWORD *)(LODWORD(v24) + 8);
          m_nRandomSeed = pParticles->m_nRandomSeed;
          v37 = m_nRandomQueryCount + 1;
          pParticles->m_nRandomQueryCount = m_nRandomQueryCount + 1;
          v38 = s_pRandomFloats[((_WORD)m_nRandomSeed + (_WORD)m_nRandomQueryCount) & 0xFFF];
          m_nRandomQueryCount += 2;
          pParticles->m_nRandomQueryCount = m_nRandomQueryCount;
          v39 = s_pRandomFloats[((_WORD)m_nRandomSeed + v37) & 0xFFF];
          pParticles->m_nRandomQueryCount = m_nRandomQueryCount + 1;
          v40 = s_pRandomFloats[((_WORD)m_nRandomQueryCount + (_WORD)m_nRandomSeed) & 0xFFF];
          vecCurrentPoint.z = (float)(v38 * x) + *(float *)&v31;
          v41 = (float)(v39 * x) + *(float *)&v31;
          v42 = v40 * x;
          m_Value = v->m_flModelScale.m_Value;
          v44 = v42 + *(float *)&v31;
          vecBasePos.x = (float)((float)((float)(m_Value * *(float *)(v35 + 20)) - (float)(m_Value * *(float *)(v35 + 8)))
                               * vecCurrentPoint.z)
                       + (float)(m_Value * *(float *)(v35 + 8));
          vecBasePos.y = (float)((float)((float)(*(float *)(v35 + 24) * m_Value)
                                       - (float)(*(float *)(v35 + 12) * m_Value))
                               * v41)
                       + (float)(*(float *)(v35 + 12) * m_Value);
          vecBasePos.z = (float)((float)((float)(*(float *)(v35 + 28) * m_Value)
                                       - (float)(*(float *)(v35 + 16) * m_Value))
                               * v44)
                       + (float)(*(float *)(v35 + 16) * m_Value);
          flTime = v54[*(_DWORD *)v35];
          vecCurrentPoint.y = v41;
          vecBoxDistance.x = v44;
          VectorTransform(in1: &vecBasePos.x, in2: flTime, out: &hitboxbones[254]);
          v45 = v54[*(_DWORD *)v35];
          v46 = (float)(*(float *)(v35 + 24) + *(float *)(v35 + 12)) * 0.5;
          v47 = (float)(*(float *)(v35 + 28) + *(float *)(v35 + 16)) * 0.5;
          vecLocalPosition.x = (float)(*(float *)(v35 + 8) + *(float *)(v35 + 20)) * 0.5;
          vecLocalPosition.y = v46;
          vecLocalPosition.z = v47;
          VectorTransform(in1: &vecLocalPosition.x, in2: v45, out: &v63);
          v63 = v63 - *(float *)&v60;
          flTryV = flTryV - *((float *)&v60 + 1);
          flTryU = flTryU - v61;
          v48 = 0;
          *(float *)&v48 = fsqrt((float)((float)(flTryV * flTryV) + (float)(flTryU * flTryU)) + (float)(v63 * v63));
          vecTryWorldPosition = v48;
          if ( vecBoxDistance.y > *(float *)&v48 )
          {
            flBestPointGoodness = vecCurrentPoint.z;
            u = __PAIR64__(LODWORD(vecCurrentPoint.y), LODWORD(vecBoxDistance.x));
            v72 = *(float *)&w;
            LODWORD(vecBoxDistance.y) = vecTryWorldPosition;
          }
          v32 = v70 + 68;
          v49 = ++w < nHitbox;
          v24 = vecBoxDistance.z;
          v70 += 68;
          if ( !v49 )
            break;
          v31 = set;
          x = vecCurrentPoint.x;
        }
        v27 = pHitBoxIndexOut;
        v25 = j;
      }
      if ( pHitBoxRelativeCoordOut != nullptr )
      {
        v50 = pHitBoxRelativeCoordOut;
        pHitBoxRelativeCoordOut->x = flBestPointGoodness;
        pHitBoxRelativeCoordOut->y = *((float *)&u + 1);
        ++pHitBoxRelativeCoordOut;
        v27 = pHitBoxIndexOut;
        LODWORD(v50->z) = u;
      }
      if ( v27 != nullptr )
      {
        *(float *)v27++ = v72;
        pHitBoxIndexOut = v27;
      }
    }
  }
  else
  {
LABEL_39:
    v27 = pHitBoxIndexOut;
  }
  if ( --s_BoneMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_BoneMutex, 0);
  if ( HIBYTE(pAnimating) == 0 )
    goto LABEL_45;
}

//------------------------------------------------------------------------------
// Address: 0x1013B650
// Name: public: virtual bool CParticleSystemQuery::IsPointInControllingObjectHitBox(class CParticleCollection __near *,int,class Vector,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CParticleSystemQuery::IsPointInControllingObjectHitBox@<al>(
        CParticleSystemQuery *this@<ecx>,
        float a2@<ebp>,
        CParticleCollection *pParticles,
        int nControlPointNumber,
        Vector vecPos,
        bool bBBoxOnly,
        const char *pszHitboxSetName)
{
  bool result; // al
  int v8; // ecx
  unsigned int *m_pObject; // ecx
  unsigned int v10; // edx
  CEntInfo *v11; // ecx
  IHandleEntity *m_pEntity; // edi
  DWORD CurrentThreadId; // ecx
  void (__thiscall *SetRefEHandle)(IHandleEntity *, const CBaseHandle *); // edx
  int v15; // eax
  const CBaseHandle *(__thiscall *GetRefEHandle)(IHandleEntity *); // edx
  Vector *v17; // eax
  char v18; // al
  float x; // esi
  IClientRenderable_vtbl *v20; // edx
  int v21; // eax
  CStudioHdr *ModelPtr; // eax
  int HitboxSetByName; // eax
  bool v24; // zf
  const char *v25; // [esp-20h] [ebp-5D0h]
  matrix3x4_t *v26; // [esp-Ch] [ebp-5BCh] BYREF
  matrix3x4_t *hitboxbones[256]; // [esp+0h] [ebp-5B0h] BYREF
  char v28; // [esp+42Bh] [ebp-185h]
  int v29; // [esp+44Ch] [ebp-164h] BYREF
  CGameTrace tr; // [esp+458h] [ebp-158h] BYREF
  int v31; // [esp+4E4h] [ebp-CCh]
  _BYTE v32[12]; // [esp+4F4h] [ebp-BCh] BYREF
  Ray_t ray; // [esp+500h] [ebp-B0h] BYREF
  _BYTE v34[52]; // [esp+550h] [ebp-60h] OVERLAPPED BYREF
  Vector vecBBoxMin; // [esp+584h] [ebp-2Ch] BYREF
  Vector vecBBoxMax; // [esp+590h] [ebp-20h] BYREF
  Vector vecLocalPos; // [esp+59Ch] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+5A8h] [ebp-8h]
  studiohdr_t *retaddr; // [esp+5B0h] [ebp+0h]

  vecLocalPos.z = a2;
  pStudioHdr = retaddr;
  result = false;
  v8 = pParticles->m_nNumControlPointsAllocated - 1;
  HIBYTE(vecLocalPos.y) = 0;
  if ( nControlPointNumber < v8 )
    v8 = nControlPointNumber;
  m_pObject = (unsigned int *)pParticles->m_pCPInfo[v8].m_ControlPoint.m_pObject;
  if ( m_pObject != nullptr )
  {
    v10 = *m_pObject;
    if ( *m_pObject != -1 )
    {
      v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v10];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10) )
      {
        m_pEntity = v11->m_pEntity;
        if ( v11->m_pEntity != nullptr )
        {
          CurrentThreadId = GetCurrentThreadId();
          if ( CurrentThreadId != s_BoneMutex.m_ownerID
            && _InterlockedCompareExchange((volatile signed __int32 *)&s_BoneMutex, CurrentThreadId, 0) != 0 )
          {
            _mm_pause();
            CThreadFastMutex::Lock(a1: &s_BoneMutex, a2: CurrentThreadId, a3: 0);
          }
          else
          {
            ++s_BoneMutex.m_depth;
          }
          LODWORD(vecLocalPos.x) = m_pEntity->__vftable[14].GetRefEHandle(this: m_pEntity);
          SetRefEHandle = m_pEntity[195].SetRefEHandle;
          BYTE2(vecLocalPos.y) = 0;
          v15 = ((int (__thiscall *)(IHandleEntity *))SetRefEHandle)(a1: &m_pEntity[195]);
          *(_QWORD *)&v34[40] = *(_QWORD *)v15;
          GetRefEHandle = m_pEntity[195].GetRefEHandle;
          *(_DWORD *)&v34[48] = *(_DWORD *)(v15 + 8);
          v17 = (Vector *)GetRefEHandle(this: m_pEntity + 195);
          v24 = ((int)m_pEntity[203].__vftable & 0x40) == 0;
          vecBBoxMin = *v17;
          vecBBoxMax = vecPos;
          if ( v24 )
          {
            v18 = BYTE2(m_pEntity[203].__vftable);
            if ( v18 != 2 && v18 != 0 )
            {
              C_BaseEntity::CalcAbsolutePosition(this: (C_BaseEntity *)m_pEntity, a2: (int)&vecLocalPos.z);
              *(_QWORD *)(&ray.m_IsSwept + 3) = *(_QWORD *)&m_pEntity[269].__vftable;
              qmemcpy(v34, &m_pEntity[271], 40);
              VectorITransform(in1: &vecPos.x, in2: (const matrix3x4_t *)(&ray.m_IsSwept + 3), out: &vecBBoxMax.x);
            }
          }
          if ( IsPointInBox(pt: &vecBBoxMax, boxMin: (const Vector *)&v34[40], boxMax: &vecBBoxMin) )
          {
            BYTE2(vecLocalPos.y) = 1;
            if ( bBBoxOnly )
            {
              HIBYTE(vecLocalPos.y) = 1;
              goto LABEL_31;
            }
          }
          x = vecLocalPos.x;
          if ( LODWORD(vecLocalPos.x) != 0 && BYTE2(vecLocalPos.y) != 0 )
          {
            if ( C_BaseAnimating::HitboxToWorldTransforms(
                   this: (C_BaseAnimating *)LODWORD(vecLocalPos.x),
                   pHitboxToWorld: &v26) == 0 )
              goto LABEL_31;
            v20 = *(IClientRenderable_vtbl **)(LODWORD(x) + 4);
            LODWORD(vecLocalPos.x) = (IVModelInfoClient)modelinfo->__vftable;
            v21 = (int)v20->GetModel(this: (IClientRenderable *)(LODWORD(x) + 4));
            LODWORD(vecLocalPos.x) = (*(int (__thiscall **)(IVModelInfoClient *, int))(LODWORD(vecLocalPos.x) + 120))(
                                       a1: modelinfo,
                                       a2: v21);
            if ( LODWORD(vecLocalPos.x) == 0 )
              goto LABEL_31;
            v25 = pszHitboxSetName;
            ModelPtr = C_BaseAnimating::GetModelPtr(this: (C_BaseAnimating *)LODWORD(x));
            HitboxSetByName = FindHitboxSetByName(pstudiohdr: ModelPtr, name: v25);
            if ( HitboxSetByName == -1 )
              HitboxSetByName = C_BaseAnimating::GetHitboxSet(this: (C_BaseAnimating *)LODWORD(x));
            if ( LODWORD(vecLocalPos.x) + *(_DWORD *)(LODWORD(vecLocalPos.x) + 176) + 12 * HitboxSetByName == 0 )
              goto LABEL_31;
            ray.m_Extents.y = 0.0;
            Ray_t::Init(this: (Ray_t *)v32, start: &vecPos, end: &vecPos);
            enginetrace->ClipRayToEntity(
              this: enginetrace,
              a2: (const Ray_t *)v32,
              a3: -1u,
              a4: m_pEntity,
              a5: (CGameTrace *)&v29);
            v24 = tr.plane.pad[1] == 0;
          }
          else
          {
            if ( !C_BaseEntity::IsBrushModel(this: (C_BaseEntity *)m_pEntity) || BYTE2(vecLocalPos.y) == 0 )
            {
LABEL_31:
              if ( --s_BoneMutex.m_depth == 0 )
                _InterlockedExchange((volatile __int32 *)&s_BoneMutex, 0);
              return HIBYTE(vecLocalPos.y);
            }
            v31 = 0;
            Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: &vecPos, end: &vecPos);
            enginetrace->ClipRayToEntity(
              this: enginetrace,
              a2: (const Ray_t *)&tr.m_pEnt,
              a3: -1u,
              a4: m_pEntity,
              a5: (CGameTrace *)&hitboxbones[253]);
            v24 = v28 == 0;
          }
          if ( !v24 )
            HIBYTE(vecLocalPos.y) = 1;
          goto LABEL_31;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013B980
// Name: public: virtual void CParticleSystemQuery::TraceAgainstRayTraceEnv(int,class FourRays const __near &,union __m128,union __m128,struct RayTracingResult __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleSystemQuery::TraceAgainstRayTraceEnv(
        CParticleSystemQuery *this@<ecx>,
        __m128 TMin@<xmm0>,
        __m128 TMax@<xmm1>,
        int envnumber,
        const FourRays *rays,
        RayTracingResult *rslt_out,
        int skip_id)
{
  if ( envnumber >= 0 && envnumber < g_RayTraceEnvironments.m_Size )
    RayTracingEnvironment::Trace4Rays(this: g_RayTraceEnvironments.m_Memory.m_pMemory[envnumber], TMin, TMax);
}

//------------------------------------------------------------------------------
// Address: 0x1013B9C0
// Name: public: virtual void CParticleSystemQuery::PreSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::PreSimulate(CParticleSystemQuery *this)
{
  int i; // eax
  SProjectedTextureInfo *v2; // esi

  for ( i = 0; i < this->m_ActiveProjectedInfos.m_Size; v2->m_bUsedThisFrame = false )
    v2 = this->m_ActiveProjectedInfos.m_Memory.m_pMemory[i++];
}

//------------------------------------------------------------------------------
// Address: 0x1013B9F0
// Name: public: struct CTSQueue<struct SProjectedTextureInfo __near *,0,1>::Node_t __near * CTSQueue<struct SProjectedTextureInfo __near *,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctor *,0,1>::Node_t *__thiscall CTSQueue<SProjectedTextureInfo *,0,1>::Pop(CTSQueue<CFunctor *,0,1> *this)
{
  CTSQueue<CFunctor *,0,1> *v1; // esi
  CTSQueue<CFunctor *,0,1> *pNext; // eax
  CFunctor *sequence; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // [esp-Ch] [ebp-2Ch]
  CTSQueue<CFunctor *,0,1>::NodeLink_t *head_4; // [esp+4h] [ebp-1Ch]
  int *pHead; // [esp+Ch] [ebp-14h]
  CTSQueue<CFunctor *,0,1>::NodeLink_t *pTailNode; // [esp+10h] [ebp-10h]

  v1 = this;
  pTailNode = &this->m_Tail;
  pHead = &this->m_Head.value.sequence;
  head_4 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = (CTSQueue<CFunctor *,0,1> *)v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != head_4->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: pTailNode->value.sequence + 1,
          a4: pNode,
          a5: pTailNode->value.sequence);
      }
    }
    while ( pNext == v1 );
    sequence = (CFunctor *)pNext->m_Head.value.sequence;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNext, a3: *pHead + 1, a4: pNode, a5: *pHead) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem = sequence;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x1013BAD0
// Name: public: virtual void CParticleSystemQuery::DrawModel(void __near *,struct matrix3x4_t const __near &,class CParticleCollection __near *,int,int,int,int,int,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CParticleSystemQuery::DrawModel(
        CParticleSystemQuery *this,
        const struct model_t *pModel,
        const matrix3x4_t *DrawMatrix,
        CParticleCollection *pParticles,
        int nParticleNumber,
        int nBodyPart,
        int nSubModel,
        int nSkin,
        int nAnimationSequence,
        float flAnimationRate,
        float r,
        float g,
        float b,
        float a)
{
  int v14; // esi
  studiohdr_t *v15; // edi
  int v16; // eax
  int v17; // ebx
  float m_flCurTime; // xmm0_4
  IMatRenderContext *v19; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  int v21; // eax
  const matrix3x4_t *v22; // ebx
  int numbones; // eax
  CMDL MDL; // [esp+0h] [ebp-65Ch] BYREF
  CMatRenderData<matrix3x4_t> rdBoneToWorld; // [esp+64Ch] [ebp-10h] BYREF
  void *pModela; // [esp+664h] [ebp+8h]

  if ( pModel != nullptr )
  {
    v14 = modelinfo->GetCacheHandle(this: modelinfo, a2: pModel);
    v15 = mdlcache->GetStudioHdr(this: mdlcache, a2: v14);
    CMDL::CMDL(this: &MDL);
    CMDL::SetMDL(this: &MDL, h: v14);
    if ( v15 != nullptr && nBodyPart < v15->numbodyparts )
    {
      v16 = 16 * nBodyPart + v15->bodypartindex;
      v17 = *(int *)((char *)&v15->version + v16);
      if ( nSubModel < v17 )
        MDL.m_nBody += *(int *)((char *)&v15->checksum + v16)
                     * (nSubModel - MDL.m_nBody / *(int *)((char *)&v15->checksum + v16) % v17);
    }
    LOBYTE(pModela) = (int)(float)(r * 255.0);
    BYTE1(pModela) = (int)(float)(g * 255.0);
    BYTE2(pModela) = (int)(float)(b * 255.0);
    HIBYTE(pModela) = (int)(float)(a * 255.0);
    MDL.m_Color = (Color)pModela;
    MDL.m_flPlaybackRate = flAnimationRate;
    m_flCurTime = pParticles->m_flCurTime;
    MDL.m_nSkin = nSkin;
    MDL.m_nSequence = nAnimationSequence;
    MDL.m_flTime = m_flCurTime;
    if ( v15 != nullptr )
    {
      v19 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
      if ( v19 != nullptr )
        v19->BeginRender(this: v19);
      LockRenderData = v19->LockRenderData;
      rdBoneToWorld.m_nCount = v15->numbones;
      rdBoneToWorld.m_pRenderContext = v19;
      v21 = (int)LockRenderData(this: v19, a2: 48 * rdBoneToWorld.m_nCount);
      rdBoneToWorld.m_pRenderContext = nullptr;
      MDL.m_pProxyData = nullptr;
      v22 = (const matrix3x4_t *)v21;
      numbones = v15->numbones;
      rdBoneToWorld.m_pRenderData = v22;
      rdBoneToWorld.m_bNeedsUnlock = true;
      CMDL::SetUpBones(
        this: &MDL,
        rootToWorld: DrawMatrix,
        nMaxBoneCount: numbones,
        pBoneToWorld: v22,
        pPoseParameters: nullptr,
        pSequenceLayers: nullptr,
        nNumSequenceLayers: 0);
      CMDL::Draw(this: &MDL, rootToWorld: DrawMatrix, pBoneToWorld: v22, flags: 32);
      CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<CModelRenderSystem::RenderModelInfo_t> *)&rdBoneToWorld);
      v19->EndRender(this: v19);
      v19->Release(this: v19);
      CMDL::~CMDL(this: &MDL);
    }
    else
    {
      CMDL::Draw(this: &MDL, rootToWorld: DrawMatrix);
      CMDL::~CMDL(this: &MDL);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BCB0
// Name: public: void CTSQueue<class CFunctor __near *,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<CFunctor *,0,1>::Purge(CTSQueue<CFunctor *,0,1> *this)
{
  CTSQueue<CFunctor *,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  for ( i = CTSQueue<SProjectedTextureInfo *,0,1>::Pop(this);
        i != nullptr;
        i = CTSQueue<SProjectedTextureInfo *,0,1>::Pop(this) )
  {
    C_BaseEntity::operator delete(pMem: i);
  }
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: p_m_FreeNodes,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    C_BaseEntity::operator delete(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013BD40
// Name: public: virtual void __near * CParticleSystemQuery::GetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const struct model_t *__thiscall CParticleSystemQuery::GetModel(CParticleSystemQuery *this, char *pMdlName)
{
  IVEngineClient_vtbl *v2; // esi
  const char *v3; // eax
  const struct model_t *result; // eax
  const struct model_t *v5; // esi
  CUtlString ModelName; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &ModelName, pString: "models/");
  CUtlString::operator+=(this: &ModelName, rhs: pMdlName);
  v2 = engine->__vftable;
  v3 = CUtlString::operator char const *(this: &ModelName);
  result = v2->LoadModel(this: engine, a2: v3, a3: false);
  v5 = result;
  ModelName.m_Storage.m_nActualLength = 0;
  if ( ModelName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( ModelName.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: ModelName.m_Storage.m_Memory.m_pMemory);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013BDB0
// Name: public: virtual void CParticleSystemQuery::UpdateProjectedTexture(int,class IMaterial __near *,class Vector __near &,float,float,float,float,float,float,void __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::UpdateProjectedTexture(
        CParticleSystemQuery *this,
        int nParticleID,
        IMaterial *pMaterial,
        Vector *vOrigin,
        float flRadius,
        float flRotation,
        float r,
        float g,
        float b,
        float a,
        SProjectedTextureInfo **pUserVar)
{
  SProjectedTextureInfo *v11; // esi
  CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *v13; // eax

  v11 = *pUserVar;
  if ( *pUserVar == nullptr )
  {
    v11 = (SProjectedTextureInfo *)MemAlloc_Alloc(nSize: 0x34u);
    *pUserVar = v11;
    memset(dst: (int)v11, value: nullptr, count: sizeof(SProjectedTextureInfo));
    v13 = (CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_ProjectedInfoAdds.m_FreeNodes);
    if ( v13 != nullptr || (v13 = (CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
      v13->elem = v11;
    else
      v13 = nullptr;
    CTSQueue<CFunctor *,0,1>::Push(this: (CTSQueue<CFunctor *,0,1> *)&this->m_ProjectedInfoAdds, pNode: v13);
  }
  v11->m_nParticleID = nParticleID;
  v11->m_pMaterial = pMaterial;
  v11->m_vOrigin = *vOrigin;
  v11->m_flSize = flRadius;
  v11->m_flRotation = flRotation;
  v11->m_r = r;
  v11->m_g = g;
  v11->m_b = b;
  v11->m_a = a;
  v11->m_bUsedThisFrame = true;
}

//------------------------------------------------------------------------------
// Address: 0x1013BE70
// Name: public: virtual void CParticleSystemQuery::PostSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::PostSimulate(CParticleSystemQuery *this)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v2; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  SProjectedTextureInfo **m_pMemory; // ecx
  int v6; // eax
  SProjectedTextureInfo **v7; // ebx
  int i; // esi
  SProjectedTextureInfo **v9; // edx
  SProjectedTextureInfo *v10; // eax
  C_EnvProjectedTexture *m_pEntity; // eax
  SProjectedTextureInfo *v12; // eax
  SProjectedTextureInfo *v13; // eax
  SProjectedTextureInfo *v14; // eax
  SProjectedTextureInfo *v15; // eax
  SProjectedTextureInfo *v16; // eax
  SProjectedTextureInfo *pInfo; // [esp+10h] [ebp-4h]

  while ( 1 )
  {
    v2 = CTSQueue<SProjectedTextureInfo *,0,1>::Pop(this: (CTSQueue<CFunctor *,0,1> *)&this->m_ProjectedInfoAdds);
    if ( v2 == nullptr )
      break;
    pInfo = (SProjectedTextureInfo *)v2->elem;
    CTSListBase::Push(this: &this->m_ProjectedInfoAdds.m_FreeNodes, pNode: (TSLNodeBase_t *)v2);
    m_Size = this->m_ActiveProjectedInfos.m_Size;
    m_nAllocationCount = this->m_ActiveProjectedInfos.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ActiveProjectedInfos,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ActiveProjectedInfos.m_Size;
    m_pMemory = this->m_ActiveProjectedInfos.m_Memory.m_pMemory;
    v6 = this->m_ActiveProjectedInfos.m_Size - m_Size - 1;
    this->m_ActiveProjectedInfos.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v7 = &this->m_ActiveProjectedInfos.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = pInfo;
  }
  for ( i = 0; i < this->m_ActiveProjectedInfos.m_Size; ++i )
  {
    v9 = this->m_ActiveProjectedInfos.m_Memory.m_pMemory;
    v10 = v9[i];
    if ( v10->m_bUsedThisFrame )
    {
      if ( v10->m_pEntity == nullptr )
        v9[i]->m_pEntity = C_EnvProjectedTexture::Create();
      v12 = this->m_ActiveProjectedInfos.m_Memory.m_pMemory[i];
      C_BaseEntity::SetAbsOrigin(this: v12->m_pEntity, absOrigin: &v12->m_vOrigin);
      v13 = this->m_ActiveProjectedInfos.m_Memory.m_pMemory[i];
      C_EnvProjectedTexture::SetMaterial(this: v13->m_pEntity, pMaterial: v13->m_pMaterial);
      v14 = this->m_ActiveProjectedInfos.m_Memory.m_pMemory[i];
      C_EnvProjectedTexture::SetLightColor(
        this: v14->m_pEntity,
        r: (int)(float)(v14->m_r * 255.0),
        g: (int)(float)(v14->m_g * 255.0),
        b: (int)(float)(v14->m_b * 255.0),
        a: (int)(float)(v14->m_a * 255.0));
      v15 = this->m_ActiveProjectedInfos.m_Memory.m_pMemory[i];
      C_EnvProjectedTexture::SetSize(this: v15->m_pEntity, flSize: v15->m_flSize);
      v16 = this->m_ActiveProjectedInfos.m_Memory.m_pMemory[i];
      C_EnvProjectedTexture::SetRotation(this: v16->m_pEntity, flRotation: v16->m_flRotation);
    }
    else
    {
      m_pEntity = v10->m_pEntity;
      if ( m_pEntity != nullptr )
        ((void (__thiscall *)(C_EnvProjectedTexture *, int))m_pEntity->dtr_IHandleEntity)(a1: m_pEntity, a2: 1);
      if ( this->m_ActiveProjectedInfos.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&this->m_ActiveProjectedInfos.m_Memory.m_pMemory[i],
          src: (unsigned __int8 *)&this->m_ActiveProjectedInfos.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_ActiveProjectedInfos.m_Size - i - 1));
      --this->m_ActiveProjectedInfos.m_Size;
      --i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C020
// Name: public: virtual int CParticleSystemQuery::GetActivityNumber(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSystemQuery::GetActivityNumber(
        CParticleSystemQuery *this,
        const struct model_t *pModel,
        const char *m_pszActivityName)
{
  const studiohdr_t *v3; // eax
  int v4; // eax
  int v5; // esi
  CStudioHdr studioHdr; // [esp+0h] [ebp-64h] BYREF

  if ( pModel == nullptr )
    return -1;
  v3 = modelinfo->GetStudiomodel(this: modelinfo, a2: pModel);
  if ( v3 == nullptr )
    return -1;
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v3, mdlcache: mdlcache);
  v4 = LookupActivity(pstudiohdr: &studioHdr, label: m_pszActivityName);
  v5 = SelectWeightedSequence(pstudiohdr: &studioHdr, activity: v4, curSequence: -1);
  CStudioHdr::Term(this: &studioHdr);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x102DE620
// Name: public: virtual void IParticleSystemQuery::BeginDrawModels(int,class Vector const __near &,class CParticleCollection __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IParticleSystemQuery::BeginDrawModels(vgui::TreeView *this, int itemIndex, int x, int y)
{
  ;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1017CD60
// Name: public: virtual bool CParticleSystemQuery::MovePointInsideControllingObject(class CParticleCollection __near *,void __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleSystemQuery::MovePointInsideControllingObject(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *pObject,
        Vector *pPnt)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017CD70
// Name: public: virtual void CParticleSystemQuery::GetRandomPointsOnControllingObjectHitBox(class CParticleCollection __near *,int,int,float,int,class Vector __near *,class Vector,class Vector __near *,int __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::GetRandomPointsOnControllingObjectHitBox(
        CParticleSystemQuery *this,
        CParticleCollection *pParticles,
        int nControlPointNumber,
        int nNumPtsOut,
        float flBBoxScale,
        int nNumTrysToGetAPointInsideTheModel,
        Vector *pPntsOut,
        Vector vecDirectionalBias,
        Vector *pHitBoxRelativeCoordOut,
        int *pHitBoxIndexOut,
        int nDesiredHitbox,
        const char *pszHitboxSetName)
{
  int v12; // edx
  Vector *v13; // esi
  float *p_z; // ecx
  int v15; // eax
  CParticleCPInfo *v16; // eax

  v12 = 0;
  if ( nNumPtsOut > 0 )
  {
    v13 = pHitBoxRelativeCoordOut;
    p_z = &pPntsOut->z;
    do
    {
      v15 = pParticles->m_nNumControlPointsAllocated - 1;
      if ( nControlPointNumber < v15 )
        v15 = nControlPointNumber;
      v16 = &pParticles->m_pCPInfo[v15];
      *(p_z - 2) = v16->m_ControlPoint.m_Position.x;
      *(p_z - 1) = v16->m_ControlPoint.m_Position.y;
      *p_z = v16->m_ControlPoint.m_Position.z;
      if ( pHitBoxIndexOut != nullptr )
        pHitBoxIndexOut[v12] = 0;
      if ( pHitBoxRelativeCoordOut != nullptr )
      {
        v13->x = 0.0;
        v13->y = 0.0;
        *(float *)((char *)p_z + (char *)pHitBoxRelativeCoordOut - (char *)pPntsOut) = 0.0;
      }
      ++v12;
      p_z += 3;
      ++v13;
    }
    while ( v12 < nNumPtsOut );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CE00
// Name: public: virtual bool CParticleSystemQuery::IsPointInControllingObjectHitBox(class CParticleCollection __near *,int,class Vector,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleSystemQuery::IsPointInControllingObjectHitBox(
        CParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        Vector vecPos,
        bool bBBoxOnly,
        const char *pszHitboxSetName)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1017CE10
// Name: public: virtual void CParticleSystemQuery::GetControllingObjectOBBox(class CParticleCollection __near *,int,class Vector,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::GetControllingObjectOBBox(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        Vector vecMin,
        Vector vecMax)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1017CE20
// Name: public: virtual int CParticleSystemQuery::GetRayTraceEnvironmentFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSystemQuery::GetRayTraceEnvironmentFromName(
        CParticleSystemQuery *this,
        const char *pszRtEnvName)
{
  int v2; // esi

  v2 = 0;
  while ( _V_stricmp(s1: s_RtEnvNameMap[v2].m_pszGroupName, s2: pszRtEnvName) != 0 )
  {
    if ( (unsigned int)++v2 >= 2 )
      return 0;
  }
  return s_RtEnvNameMap[v2].m_nGroupID;
}

//------------------------------------------------------------------------------
// Address: 0x1017CE60
// Name: public: virtual int CParticleSystemQuery::GetCollisionGroupFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSystemQuery::GetCollisionGroupFromName(
        CParticleSystemQuery *this,
        const char *pszCollisionGroupName)
{
  int v2; // esi

  v2 = 0;
  while ( _V_stricmp(s1: s_NameMap[v2].m_pszGroupName, s2: pszCollisionGroupName) != 0 )
  {
    if ( (unsigned int)++v2 >= 6 )
      return 0;
  }
  return s_NameMap[v2].m_nGroupID;
}

//------------------------------------------------------------------------------
// Address: 0x1017CEA0
// Name: public: virtual void CParticleSystemQuery::DebugDrawLine(class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::DebugDrawLine(
        CParticleSystemQuery *this,
        const Vector *origin,
        const Vector *target,
        int r,
        int g,
        int b,
        int noDepthTest,
        float duration)
{
  ((void (__stdcall *)(const Vector *, const Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
    a1: origin,
    a2: target,
    a3: r,
    a4: g,
    a5: b,
    a6: noDepthTest,
    a7: LODWORD(duration));
}

//------------------------------------------------------------------------------
// Address: 0x1017CEF0
// Name: public: virtual bool IParticleSystemQuery::IsPointInControllingObjectHitBox(class CParticleCollection __near *,int,class Vector,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall IParticleSystemQuery::IsPointInControllingObjectHitBox(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        Vector vecPos,
        bool bBBoxOnly)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017CF10
// Name: public: virtual int IParticleSystemQuery::GetControllingObjectHitBoxInfo(class CParticleCollection __near *,int,int,struct ModelHitBoxInfo_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IParticleSystemQuery::GetControllingObjectHitBoxInfo(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        int nBufSize,
        ModelHitBoxInfo_t *pHitBoxOutputBuffer,
        ModelHitBoxInfo_t *pszHitboxSetName)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017CF20
// Name: public: virtual void IParticleSystemQuery::GetLocalPlayerEyeVectors(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IParticleSystemQuery::GetLocalPlayerEyeVectors(
        IParticleSystemQuery *this,
        Vector *pForward,
        Vector *pRight,
        Vector *pUp)
{
  *pForward = vec3_origin;
  *pRight = vec3_origin;
  *pUp = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x1017CFC0
// Name: public: virtual class Vector CParticleSystemQuery::GetLocalPlayerPos(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CParticleSystemQuery::GetLocalPlayerPos(CParticleSystemQuery *this, Vector *result)
{
  CBasePlayer *LocalPlayer; // eax
  int v4; // eax
  float v5; // edx

  if ( gpGlobals->maxClients <= 1 && (LocalPlayer = UTIL_GetLocalPlayer()) != nullptr )
  {
    v4 = (int)LocalPlayer->WorldSpaceCenter(this: LocalPlayer);
    v5 = *(float *)(v4 + 8);
    *(_QWORD *)&result->x = *(_QWORD *)v4;
    result->z = v5;
    return result;
  }
  else
  {
    *result = vec3_origin;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D020
// Name: public: virtual void CParticleSystemQuery::GetLocalPlayerEyeVectors(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::GetLocalPlayerEyeVectors(
        CParticleSystemQuery *this,
        Vector *pForward,
        Vector *pRight,
        Vector *pUp)
{
  CBasePlayer *LocalPlayer; // eax

  if ( gpGlobals->maxClients <= 1 && (LocalPlayer = UTIL_GetLocalPlayer()) != nullptr )
  {
    CBasePlayer::EyeVectors(this: LocalPlayer, pForward, pRight, pUp);
  }
  else
  {
    *pForward = vec3_origin;
    *pRight = vec3_origin;
    *pUp = vec3_origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D0C0
// Name: public: virtual void CBaseAppSystem<class IParticleSystemQuery>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IParticleSystemQuery>::Reconnect(
        CBaseAppSystem<IParticleSystemQuery> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1017D0E0
// Name: public: virtual void CParticleSystemQuery::TraceLine(class Vector const __near &,class Vector const __near &,unsigned int,class IHandleEntity const __near *,int,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::TraceLine(
        CParticleSystemQuery *this,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        const IHandleEntity *ignore,
        int collisionGroup,
        CBaseTrace *ptr)
{
  ptr->startsolid = false;
  ptr->fraction = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1017D100
// Name: public: virtual int CParticleSystemQuery::GetActivityNumber(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSystemQuery::GetActivityNumber(
        CParticleSystemQuery *this,
        const struct model_t *pModel,
        const char *m_pszActivityName)
{
  const studiohdr_t *v3; // eax
  int v4; // eax
  int v5; // esi
  CStudioHdr studioHdr; // [esp+0h] [ebp-64h] BYREF

  if ( pModel == nullptr )
    return -1;
  v3 = modelinfo->GetStudiomodel(this: modelinfo, a2: pModel);
  if ( v3 == nullptr )
    return -1;
  CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v3, mdlcache: mdlcache);
  v4 = LookupActivity(pstudiohdr: &studioHdr, label: m_pszActivityName);
  v5 = SelectWeightedSequence(pstudiohdr: &studioHdr, activity: v4, curSequence: -1);
  CStudioHdr::Term(this: &studioHdr);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x102671D0
// Name: public: virtual void CParticleSystemQuery::TraceAgainstRayTraceEnv(int,class FourRays const __near &,union __m128,union __m128,struct RayTracingResult __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::TraceAgainstRayTraceEnv(
        vgui::MenuButton *this,
        int tx0,
        int ty0,
        int tx1,
        int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1035BCF0
// Name: public: virtual void CParticleSystemQuery::GetLightingAtPoint(class Vector const __near &,class Color __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::GetLightingAtPoint(
        CDefaultParticleSystemQuery *this,
        const Vector *vecOrigin,
        Color *tint)
{
  *tint = (Color)-1;
}

//------------------------------------------------------------------------------
// Address: 0x1035BD60
// Name: public: virtual void CParticleSystemQuery::GetClosestControllingObjectHitBox(class CParticleCollection __near *,int,int,float,class Vector __near *,class Vector __near *,int __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemQuery::GetClosestControllingObjectHitBox(
        CDefaultParticleSystemQuery *this,
        CParticleCollection *pParticles,
        int nControlPointNumber,
        int nNumPtsIn,
        float flBBoxScale,
        Vector *pPntsIn,
        Vector *pHitBoxRelativeCoordOut,
        int *pHitBoxIndexOut,
        int nDesiredHitbox,
        const char *pszHitboxSetName)
{
  int v10; // eax
  float *p_z; // ecx

  v10 = 0;
  if ( nNumPtsIn > 0 )
  {
    p_z = &pHitBoxRelativeCoordOut->z;
    do
    {
      if ( pHitBoxIndexOut != nullptr )
        pHitBoxIndexOut[v10] = 0;
      if ( pHitBoxRelativeCoordOut != nullptr )
      {
        *(p_z - 2) = 0.0;
        *(p_z - 1) = 0.0;
        *p_z = 0.0;
      }
      ++v10;
      p_z += 3;
    }
    while ( v10 < nNumPtsIn );
  }
}

} // namespace server
