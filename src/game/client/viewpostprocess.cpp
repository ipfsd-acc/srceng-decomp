// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/viewpostprocess.cpp
// Functions: 48
// ============================================================

#include "game\client\viewpostprocess.h"

//------------------------------------------------------------------------------
// Address: 0x1006C0A0
// Name: public: virtual class IMaterial __near * CMotionBlurMaterialProxy::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CMotionBlurMaterialProxy::GetMaterial(CBreakableSurfaceProxy *this)
{
  if ( this->m_BaseTextureVar != nullptr )
    return this->m_BaseTextureVar->GetOwningMaterial(this: this->m_BaseTextureVar);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100CB990
// Name: public: void ICallQueue::QueueCall<void,class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short> const __near &,class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short>>(void (*)(class CDetailObjectSystem __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class CUtlEnvelope<unsigned short> const __near &),class CDetailObjectSystem __near * const __near &,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int const __near &,class CUtlEnvelope<unsigned short> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &,CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(CDetailObjectSystem *, DistanceFadeInfo_t, Vector, Vector, Vector, Vector, int, const CUtlEnvelope<unsigned short> *),
        CDetailObjectSystem **arg1,
        const DistanceFadeInfo_t *arg2,
        const Vector *arg3,
        const Vector *arg4,
        const Vector *arg5,
        const Vector *arg6,
        int *arg7,
        const CUtlEnvelope<unsigned short> *arg8)
{
  CFunctor8<void (__cdecl*)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *v11; // eax
  CFunctor8<void (__cdecl*)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *v12; // eax

  v11 = (CFunctor8<void (__cdecl*)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *)MemAlloc_Alloc(nSize: 0x60u);
  if ( v11 != nullptr )
  {
    v12 = CFunctor8<void (__cdecl *)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::CFunctor8<void (__cdecl *)(CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short> const &),CDetailObjectSystem *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,CUtlEnvelope<unsigned short>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>(
            this: v11,
            pfnProxied,
            arg1,
            arg2,
            arg3,
            arg4,
            arg5,
            arg6,
            arg7,
            arg8);
    this->QueueFunctorInternal(this, a2: v12);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB9F0
// Name: public: void ICallQueue::QueueCall<class CDetailObjectSystem __near *,class CDetailObjectSystem,void,class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class Vector const __near &,bool,class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t,class Vector,class Vector,class Vector,class Vector,int,class Vector,bool>(class CDetailObjectSystem __near *,void (CDetailObjectSystem::*)(class CFastDetailLeafSpriteList __near *,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class Vector const __near &,bool),class CFastDetailLeafSpriteList __near * const __near &,struct DistanceFadeInfo_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int const __near &,class Vector const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CDetailObjectSystem *,CDetailObjectSystem,void,CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool,CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool>(
        ICallQueue *this,
        CDetailObjectSystem *pObject,
        __int128 pfnProxied,
        CFastDetailLeafSpriteList **arg1,
        const DistanceFadeInfo_t *arg2,
        const Vector *arg3,
        const Vector *arg4,
        const Vector *arg5,
        const Vector *arg6,
        int *arg7,
        const Vector *arg8,
        bool *arg9)
{
  CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v13; // eax
  CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v14; // eax

  v13 = (CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v13 != nullptr )
  {
    v14 = CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor9<CDetailObjectSystem *,void (__thiscall CDetailObjectSystem::*)(CFastDetailLeafSpriteList *,DistanceFadeInfo_t const &,Vector const &,Vector const &,Vector const &,Vector const &,int,Vector const &,bool),CFastDetailLeafSpriteList *,DistanceFadeInfo_t,Vector,Vector,Vector,Vector,int,Vector,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
            this: v13,
            pObject,
            pfnProxied,
            arg1,
            arg2,
            arg3,
            arg4,
            arg5,
            arg6,
            arg7,
            arg8,
            arg9);
    this->QueueFunctorInternal(this, a2: v14);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195500
// Name: void SetPostProcessParams(struct PostProcessParameters_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPostProcessParams(const PostProcessParameters_t *pPostProcessParameters)
{
  s_LocalPostProcessParameters[0] = *pPostProcessParameters;
}

//------------------------------------------------------------------------------
// Address: 0x10195550
// Name: public: virtual bool CBloomAddMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBloomAddMaterialProxy::Init(CBloomAddMaterialProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  bool bFoundVar; // [esp+7h] [ebp-1h] BYREF

  FindVar = pMaterial->FindVar;
  bFoundVar = false;
  this->m_pMaterialParam_BloomAmount = FindVar(this: pMaterial, a2: "$c0_x", a3: &bFoundVar, a4: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10195580
// Name: public: virtual void CBloomAddMaterialProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBloomAddMaterialProxy::OnBind(CBloomAddMaterialProxy *this, C_BaseEntity *pEnt)
{
  if ( this->m_pMaterialParam_BloomAmount != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_BloomAmount->SetFloatValue)(a1: LODWORD(CBloomAddMaterialProxy::s_flBloomAmount));
}

//------------------------------------------------------------------------------
// Address: 0x101955B0
// Name: public: virtual bool CEnginePostMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEnginePostMaterialProxy::Init(
        CEnginePostMaterialProxy *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // edx
  bool bFoundVar; // [esp+Bh] [ebp-1h] BYREF

  FindVar = pMaterial->FindVar;
  bFoundVar = false;
  this->m_pMaterialParam_AAValues = FindVar(this: pMaterial, a2: "$AAInternal1", a3: &bFoundVar, a4: false);
  this->m_pMaterialParam_AAValues2 = pMaterial->FindVar(this: pMaterial, a2: "$AAInternal3", a3: &bFoundVar, a4: 0);
  this->m_pMaterialParam_BloomUVTransform = pMaterial->FindVar(
                                              this: pMaterial,
                                              a2: "$AAInternal2",
                                              a3: &bFoundVar,
                                              a4: 0);
  this->m_pMaterialParam_BloomEnable = pMaterial->FindVar(this: pMaterial, a2: "$bloomEnable", a3: &bFoundVar, a4: 0);
  this->m_pMaterialParam_BloomAmount = pMaterial->FindVar(this: pMaterial, a2: "$bloomAmount", a3: &bFoundVar, a4: 0);
  this->m_pMaterialParam_ColCorrectEnable = pMaterial->FindVar(
                                              this: pMaterial,
                                              a2: "$colCorrectEnable",
                                              a3: &bFoundVar,
                                              a4: 0);
  this->m_pMaterialParam_ColCorrectNumLookups = pMaterial->FindVar(
                                                  this: pMaterial,
                                                  a2: "$colCorrect_NumLookups",
                                                  a3: &bFoundVar,
                                                  a4: 0);
  this->m_pMaterialParam_ColCorrectDefaultWeight = pMaterial->FindVar(
                                                     this: pMaterial,
                                                     a2: "$colCorrect_DefaultWeight",
                                                     a3: &bFoundVar,
                                                     a4: 0);
  this->m_pMaterialParam_ColCorrectLookupWeights = pMaterial->FindVar(
                                                     this: pMaterial,
                                                     a2: "$colCorrect_LookupWeights",
                                                     a3: &bFoundVar,
                                                     a4: 0);
  this->m_pMaterialParam_LocalContrastStrength = pMaterial->FindVar(
                                                   this: pMaterial,
                                                   a2: "$localContrastScale",
                                                   a3: &bFoundVar,
                                                   a4: 0);
  this->m_pMaterialParam_LocalContrastEdgeStrength = pMaterial->FindVar(
                                                       this: pMaterial,
                                                       a2: "$localContrastEdgeScale",
                                                       a3: &bFoundVar,
                                                       a4: 0);
  this->m_pMaterialParam_VignetteStart = pMaterial->FindVar(
                                           this: pMaterial,
                                           a2: "$localContrastVignetteStart",
                                           a3: &bFoundVar,
                                           a4: 0);
  this->m_pMaterialParam_VignetteEnd = pMaterial->FindVar(
                                         this: pMaterial,
                                         a2: "$localContrastVignetteEnd",
                                         a3: &bFoundVar,
                                         a4: 0);
  this->m_pMaterialParam_VignetteBlurEnable = pMaterial->FindVar(
                                                this: pMaterial,
                                                a2: "$blurredVignetteEnable",
                                                a3: &bFoundVar,
                                                a4: 0);
  this->m_pMaterialParam_VignetteBlurStrength = pMaterial->FindVar(
                                                  this: pMaterial,
                                                  a2: "$blurredVignetteScale",
                                                  a3: &bFoundVar,
                                                  a4: 0);
  this->m_pMaterialParam_FadeToBlackStrength = pMaterial->FindVar(
                                                 this: pMaterial,
                                                 a2: "$fadeToBlackScale",
                                                 a3: &bFoundVar,
                                                 a4: 0);
  this->m_pMaterialParam_DepthBlurFocalDistance = pMaterial->FindVar(
                                                    this: pMaterial,
                                                    a2: "$depthBlurFocalDistance",
                                                    a3: &bFoundVar,
                                                    a4: 0);
  this->m_pMaterialParam_DepthBlurStrength = pMaterial->FindVar(
                                               this: pMaterial,
                                               a2: "$depthBlurStrength",
                                               a3: &bFoundVar,
                                               a4: 0);
  this->m_pMaterialParam_ScreenBlurStrength = pMaterial->FindVar(
                                                this: pMaterial,
                                                a2: "$screenBlurStrength",
                                                a3: &bFoundVar,
                                                a4: 0);
  this->m_pMaterialParam_FilmGrainStrength = pMaterial->FindVar(
                                               this: pMaterial,
                                               a2: "$noiseScale",
                                               a3: &bFoundVar,
                                               a4: 0);
  this->m_pMaterialParam_VomitEnable = pMaterial->FindVar(this: pMaterial, a2: "$vomitEnable", a3: &bFoundVar, a4: 0);
  this->m_pMaterialParam_VomitColor1 = pMaterial->FindVar(this: pMaterial, a2: "$vomitColor1", a3: &bFoundVar, a4: 0);
  this->m_pMaterialParam_VomitColor2 = pMaterial->FindVar(this: pMaterial, a2: "$vomitColor2", a3: &bFoundVar, a4: 0);
  this->m_pMaterialParam_FadeColor = pMaterial->FindVar(this: pMaterial, a2: "$fadeColor", a3: &bFoundVar, a4: 0);
  this->m_pMaterialParam_FadeType = pMaterial->FindVar(this: pMaterial, a2: "$fade", a3: &bFoundVar, a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10195810
// Name: public: static void CEnginePostMaterialProxy::SetupEnginePostMaterialTextureTransform(class Vector4D const __near &,class Vector4D const __near &,class Vector2D)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEnginePostMaterialProxy::SetupEnginePostMaterialTextureTransform(
        const Vector4D *fullViewportBloomUVs,
        const Vector4D *fullViewportFBUVs,
        Vector2D fbSize)
{
  int v3; // xmm3_4
  int v4; // xmm4_4
  int v5; // xmm0_4
  float uvStart1; // [esp+8h] [ebp-18h]
  float uvStart1_4; // [esp+Ch] [ebp-14h]

  uvStart1 = (float)(1.0 / (float)(fbSize.x * 0.25)) * (float)(fullViewportBloomUVs->x + 0.5);
  uvStart1_4 = (float)(1.0 / (float)(fbSize.y * 0.25)) * (float)(fullViewportBloomUVs->y + 0.5);
  *(float *)&v3 = (float)((float)(1.0 / fbSize.x) * (float)(fullViewportFBUVs->z - fullViewportFBUVs->x))
                / (float)((float)(1.0 / (float)(fbSize.x * 0.25))
                        * (float)(fullViewportBloomUVs->z - fullViewportBloomUVs->x));
  *(float *)&v4 = (float)((float)(1.0 / fbSize.y) * (float)(fullViewportFBUVs->w - fullViewportFBUVs->y))
                / (float)((float)(1.0 / (float)(fbSize.y * 0.25))
                        * (float)(fullViewportBloomUVs->w - fullViewportBloomUVs->y));
  *(float *)&v5 = (float)((float)(1.0 - *(float *)&v4) * uvStart1_4)
                + (float)((float)((float)(1.0 / fbSize.y) * (float)(fullViewportFBUVs->y + 0.5)) - uvStart1_4);
  CEnginePostMaterialProxy::s_vBloomUVTransform[0] = (float)((float)(1.0 - *(float *)&v3) * uvStart1)
                                                   + (float)((float)((float)(1.0 / fbSize.x)
                                                                   * (float)(fullViewportFBUVs->x + 0.5))
                                                           - uvStart1);
  dword_10654698 = v5;
  dword_1065469C = v3;
  dword_106546A0 = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10195980
// Name: DrawBloomDebugBoxes
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawBloomDebugBoxes(
        IMatRenderContext *pRenderContext@<esi>,
        int nX@<edi>,
        int nY,
        int nWidth,
        int nHeight)
{
  int nWidtha; // [esp+10h] [ebp+Ch]

  pRenderContext->PushRenderTargetAndViewport_4(this: pRenderContext);
  pRenderContext->SetRenderTarget(this: pRenderContext, a2: nullptr);
  pRenderContext->Viewport(this: pRenderContext, a2: nX, a3: nY, a4: nWidth, a5: nHeight);
  pRenderContext->ClearColor3ub(this: pRenderContext, a2: 0, a3: 0, a4: 0);
  pRenderContext->ClearBuffers(this: pRenderContext, a2: true, a3: true, a4: false);
  wx = ((_BYTE)wx + 1) & 0x3F;
  pRenderContext->Viewport(this: pRenderContext, a2: nX + wx + nWidth / 2, a3: nY + nHeight / 2, a4: 32, a5: 32);
  pRenderContext->ClearColor3ub(this: pRenderContext, a2: 255u, a3: 255u, a4: 255u);
  pRenderContext->ClearBuffers(this: pRenderContext, a2: true, a3: true, a4: false);
  pRenderContext->Viewport(this: pRenderContext, a2: nX + 64, a3: nY + 64, a4: 32, a5: 32);
  pRenderContext->ClearBuffers(this: pRenderContext, a2: true, a3: true, a4: false);
  nWidtha = nX + nWidth - 96;
  pRenderContext->Viewport(this: pRenderContext, a2: nWidtha, a3: nY + 64, a4: 32, a5: 32);
  pRenderContext->ClearBuffers(this: pRenderContext, a2: true, a3: true, a4: false);
  pRenderContext->Viewport(this: pRenderContext, a2: nWidtha, a3: nY + nHeight - 96, a4: 32, a5: 32);
  pRenderContext->ClearBuffers(this: pRenderContext, a2: true, a3: true, a4: false);
  pRenderContext->Viewport(this: pRenderContext, a2: nX + 64, a3: nX + nHeight - 96, a4: 32, a5: 32);
  pRenderContext->ClearBuffers(this: pRenderContext, a2: true, a3: true, a4: false);
  ((void (__thiscall *)(IMatRenderContext *, int, int, int))pRenderContext->PopRenderTargetAndViewport)(
    a1: pRenderContext,
    a2: nY,
    a3: nWidtha,
    a4: nX + 64);
}

//------------------------------------------------------------------------------
// Address: 0x10195B00
// Name: public: virtual bool CMotionBlurMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMotionBlurMaterialProxy::Init(
        CMotionBlurMaterialProxy *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // edx
  IMaterialVar *v5; // eax
  bool v6; // zf
  IMaterialVar *v8; // eax
  bool bFoundVar; // [esp+Bh] [ebp-1h] BYREF

  FindVar = pMaterial->FindVar;
  bFoundVar = false;
  v5 = FindVar(this: pMaterial, a2: "$MotionBlurInternal", a3: &bFoundVar, a4: false);
  v6 = !bFoundVar;
  this->m_pMaterialParam = v5;
  if ( v6 )
    return false;
  v8 = pMaterial->FindVar(this: pMaterial, a2: "$MotionBlurViewportInternal", a3: &bFoundVar, a4: 0);
  v6 = !bFoundVar;
  this->m_pMaterialParamViewport = v8;
  return !v6;
}

//------------------------------------------------------------------------------
// Address: 0x10195B60
// Name: public: virtual void CMotionBlurMaterialProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMotionBlurMaterialProxy::OnBind(CMotionBlurMaterialProxy *this, C_BaseEntity *pEnt)
{
  if ( this->m_pMaterialParam != nullptr )
    this->m_pMaterialParam->SetVecValue_4(this: this->m_pMaterialParam, a2: g_vMotionBlurValues, a3: 4);
  if ( this->m_pMaterialParamViewport != nullptr )
    this->m_pMaterialParamViewport->SetVecValue_4(
      this: this->m_pMaterialParamViewport,
      a2: g_vMotionBlurViewportValues,
      a3: 4);
}

//------------------------------------------------------------------------------
// Address: 0x10195BA0
// Name: SetMaterialVarFloat
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall SetMaterialVarFloat@<al>(
        IMaterial *pMat@<ecx>,
        const char *pVarName@<eax>,
        int a3@<esi>,
        float flValue)
{
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int *v5; // eax
  char v6; // ecx^3
  int v7; // edx
  IMaterial *v10; // [esp+10h] [ebp-4h] OVERLAPPED BYREF

  v10 = pMat;
  if ( pMat == nullptr || pVarName == nullptr )
    return false;
  FindVar = pMat->FindVar;
  HIBYTE(v10) = 0;
  v5 = (int *)((int (__thiscall *)(IMaterial *, const char *, char *, int, int))FindVar)(
                a1: pMat,
                a2: pVarName,
                a3: (char *)&v10 + 3,
                a4: 1,
                a5: a3);
  if ( HIBYTE(v10) != 0 )
  {
    v7 = *v5;
    HIBYTE(v10) = v6;
    (*(void (__thiscall **)(int *, _DWORD))(v7 + 16))(a1: v5, a2: LODWORD(flValue));
  }
  return HIBYTE(v10);
}

//------------------------------------------------------------------------------
// Address: 0x10195BF0
// Name: SetMaterialVarInt
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall SetMaterialVarInt@<al>(IMaterial *pMat@<ecx>, const char *pVarName@<eax>, int a3@<esi>, int nValue)
{
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v5; // eax
  IMaterial *v8; // [esp-2h] [ebp-4h] OVERLAPPED BYREF

  v8 = pMat;
  if ( pMat == nullptr || pVarName == nullptr )
    return false;
  FindVar = pMat->FindVar;
  HIBYTE(v8) = 0;
  v5 = ((int (__thiscall *)(IMaterial *, const char *, char *, int, int))FindVar)(
         a1: pMat,
         a2: pVarName,
         a3: (char *)&v8 + 3,
         a4: 1,
         a5: a3);
  if ( HIBYTE(v8) != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 20))(a1: v5, a2: nValue);
  return HIBYTE(v8);
}

//------------------------------------------------------------------------------
// Address: 0x10195C30
// Name: public: float CTonemapSystem::FindLocationOfPercentBrightPixels(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTonemapSystem::FindLocationOfPercentBrightPixels(
        CTonemapSystem *this,
        float flPercentBrightPixels,
        float flPercentTargetToSnapToIfInSameBin)
{
  int v3; // edi
  CHistogramBucket *v4; // eax
  int i; // esi
  HistogramEntryState_t m_state; // edx
  HistogramEntryState_t v7; // edx
  HistogramEntryState_t v8; // edx
  float v9; // xmm4_4
  float v10; // xmm3_4
  int v11; // edx
  float *p_m_flMaxLuminance; // eax
  int v13; // esi
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v18; // xmm3_4
  int v19; // edx
  float v20; // xmm1_4
  float m_flMaxLuminance; // xmm0_4
  float v22; // xmm2_4
  float m_flMinLuminance; // xmm3_4
  float flPercentLocationOfBorder; // [esp+8h] [ebp+8h]

  if ( mat_tonemap_algorithm.m_pParent == nullptr || mat_tonemap_algorithm.m_pParent->m_Value.m_nValue != 1 )
    return -1.0;
  v3 = 0;
  v4 = &this->m_histogramBucketArray[1];
  for ( i = 4; i != 0; --i )
  {
    m_state = v4[-1].m_state;
    if ( m_state == HESTATE_QUERY_DONE || m_state == HESTATE_QUERY_IN_FLIGHT )
      v3 += v4[-1].m_nPixelsInRange;
    if ( v4->m_state == HESTATE_QUERY_DONE || v4->m_state == HESTATE_QUERY_IN_FLIGHT )
      v3 += v4->m_nPixelsInRange;
    v7 = v4[1].m_state;
    if ( v7 == HESTATE_QUERY_DONE || v7 == HESTATE_QUERY_IN_FLIGHT )
      v3 += v4[1].m_nPixelsInRange;
    v8 = v4[2].m_state;
    if ( v8 == HESTATE_QUERY_DONE || v8 == HESTATE_QUERY_IN_FLIGHT )
      v3 += v4[2].m_nPixelsInRange;
    v4 += 4;
  }
  if ( v3 != 0 )
  {
    v9 = 0.0;
    v10 = 0.0;
    v11 = 15;
    p_m_flMaxLuminance = &this->m_histogramBucketArray[15].m_flMaxLuminance;
    do
    {
      v13 = *((_DWORD *)p_m_flMaxLuminance - 6);
      if ( v13 != 3 && v13 != 2 )
        break;
      v14 = (float)*((int *)p_m_flMaxLuminance - 2) / (float)v3;
      v15 = *p_m_flMaxLuminance - *(p_m_flMaxLuminance - 1);
      v16 = (float)(flPercentBrightPixels * 0.0099999998) - v10;
      if ( v14 >= v16 )
      {
        if ( flPercentTargetToSnapToIfInSameBin >= 0.0 )
        {
          v18 = flPercentTargetToSnapToIfInSameBin * 0.0099999998;
          if ( (float)(flPercentTargetToSnapToIfInSameBin * 0.0099999998) >= this->m_histogramBucketArray[v11].m_flMinLuminance
            && this->m_histogramBucketArray[v11].m_flMaxLuminance >= v18 )
          {
            return v18;
          }
        }
        v19 = v11;
        v20 = 1.0 - (float)((float)((float)(v16 / v14) * v15) + v9);
        m_flMaxLuminance = this->m_histogramBucketArray[v19].m_flMaxLuminance;
        flPercentLocationOfBorder = v20;
        if ( v20 <= m_flMaxLuminance )
          v22 = v20;
        else
          v22 = this->m_histogramBucketArray[v19].m_flMaxLuminance;
        m_flMinLuminance = this->m_histogramBucketArray[v19].m_flMinLuminance;
        if ( m_flMinLuminance > v22 )
          return m_flMinLuminance;
        if ( v20 > m_flMaxLuminance )
          return this->m_histogramBucketArray[v19].m_flMaxLuminance;
        return flPercentLocationOfBorder;
      }
      p_m_flMaxLuminance -= 11;
      --v11;
      v10 = v10 + v14;
      v9 = v9 + v15;
    }
    while ( v11 >= 0 );
  }
  return -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10195DC0
// Name: GetExposureRange
// Source: json
//------------------------------------------------------------------------------
void __usercall GetExposureRange(float *pflAutoExposureMin@<edx>, float *pflAutoExposureMax@<eax>)
{
  if ( g_bUseCustomAutoExposureMin && g_flCustomAutoExposureMin > 0.0 )
    *pflAutoExposureMin = g_flCustomAutoExposureMin;
  else
    *pflAutoExposureMin = mat_autoexposure_min.m_pParent->m_Value.m_fValue;
  if ( g_bUseCustomAutoExposureMax && g_flCustomAutoExposureMax > 0.0 )
    *pflAutoExposureMax = g_flCustomAutoExposureMax;
  else
    *pflAutoExposureMax = mat_autoexposure_max.m_pParent->m_Value.m_fValue;
  *pflAutoExposureMax = mat_autoexposure_max_multiplier.m_pParent->m_Value.m_fValue * *pflAutoExposureMax;
  if ( mat_hdr_uncapexposure.m_pParent != nullptr && mat_hdr_uncapexposure.m_pParent->m_Value.m_nValue != 0 )
  {
    *pflAutoExposureMax = 100.0;
    *pflAutoExposureMin = 0.0;
  }
  if ( *pflAutoExposureMin > *pflAutoExposureMax )
    *pflAutoExposureMax = *pflAutoExposureMin;
}

//------------------------------------------------------------------------------
// Address: 0x10195E60
// Name: public: void CTonemapSystem::UpdateBucketRanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapSystem::UpdateBucketRanges(CTonemapSystem *this)
{
  CTonemapSystem *v1; // edx
  int m_nValue; // ecx
  int v3; // eax
  IVEngineClient *v4; // ecx
  int v5; // esi
  unsigned int v6; // eax
  const char *v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // ebx
  const char *v10; // eax
  int v11; // eax
  CTonemapSystem *v12; // ecx
  int v13; // edi
  int v14; // ebx
  float *p_m_flMinLuminance; // esi
  int v16; // eax
  double v17; // xmm0_8
  double v18; // xmm0_8
  __m128d v19; // xmm0
  double v20; // xmm0_8
  __m128 v21; // xmm0
  double v22; // xmm0_8
  float v23; // xmm0_4
  float v24; // xmm1_4
  const char *sModsForOriginalAlgorithm[3]; // [esp+0h] [ebp-24h]
  float v26; // [esp+Ch] [ebp-18h]
  float v27; // [esp+10h] [ebp-14h]
  float v28; // [esp+14h] [ebp-10h]
  float v29; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  CTonemapSystem *v31; // [esp+20h] [ebp-4h]

  v1 = this;
  v31 = this;
  if ( mat_tonemap_algorithm.m_pParent != nullptr )
    m_nValue = mat_tonemap_algorithm.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( v1->m_nCurrentAlgorithm == m_nValue )
    return;
  if ( mat_tonemap_algorithm.m_pParent != nullptr )
    v3 = mat_tonemap_algorithm.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  v1->m_nCurrentAlgorithm = v3;
  v4 = engine;
  if ( engine == nullptr )
  {
    v1->m_nCurrentAlgorithm = -1;
    goto LABEL_22;
  }
  if ( !s_bFirstTime )
    goto LABEL_22;
  *(float *)&v5 = 0.0;
  s_bFirstTime = false;
  sModsForOriginalAlgorithm[0] = "dod";
  sModsForOriginalAlgorithm[1] = "cstrike";
  sModsForOriginalAlgorithm[2] = "lostcoast";
  *(float *)&i = 0.0;
  while ( 1 )
  {
    v6 = strlen(v4->GetGameDirectory(this: v4));
    v7 = sModsForOriginalAlgorithm[v5];
    if ( v6 >= strlen(v7) )
    {
      v8 = strlen(engine->GetGameDirectory(this: engine));
      v9 = strlen(v7);
      v10 = engine->GetGameDirectory(this: engine);
      if ( _V_stricmp(s1: &v10[v8 - v9], s2: v7) == 0 )
        break;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= 3 )
    {
      v1 = v31;
      goto LABEL_22;
    }
    v4 = engine;
  }
  ConVar::SetValue(this: (ConVar *)&mat_tonemap_algorithm.IConVar, value: 0);
  if ( mat_tonemap_algorithm.m_pParent != nullptr )
    v11 = mat_tonemap_algorithm.m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  v12 = v31;
  v31->m_nCurrentAlgorithm = v11;
  v1 = v12;
LABEL_22:
  v13 = 0;
  v14 = 31;
  if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1 )
    v14 = 17;
  v1->m_nCurrentQueryFrame = 0;
  p_m_flMinLuminance = &v31->m_histogramBucketArray[0].m_flMinLuminance;
  do
  {
    v16 = v14 - 1;
    *(p_m_flMinLuminance - 5) = 0.0;
    p_m_flMinLuminance[2] = 0.0;
    p_m_flMinLuminance[4] = 1.0;
    p_m_flMinLuminance[3] = 0.0;
    p_m_flMinLuminance[5] = 1.0;
    if ( v13 == v14 - 1 )
    {
      v23 = 100000.0;
      *p_m_flMinLuminance = 0.0;
    }
    else if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue != 0 )
    {
      v24 = (float)v13 / (float)v16;
      v23 = (float)(v13 + 1) / (float)v16;
      *p_m_flMinLuminance = v24;
      v26 = v23;
      p_m_flMinLuminance[1] = v23;
      if ( v24 > 0.0 )
      {
        __libm_sse2_pow();
        v23 = v26;
      }
      *p_m_flMinLuminance = v24;
      if ( v23 > 0.0 )
        __libm_sse2_pow();
    }
    else
    {
      __libm_sse2_log(a1: (__m128d)0x3F847AE140000000uLL);
      *(float *)&v17 = v17;
      v31 = (CTonemapSystem *)LODWORD(v17);
      i = SLODWORD(v17);
      __libm_sse2_log(a1: (__m128d)0x3FF028F5C0000000uLL);
      *(float *)&v18 = v18;
      v28 = *(float *)&v18 - *(float *)&i;
      v29 = (float)v13;
      v27 = (float)v14 - 1.0;
      v19.m128d_f64[0] = (float)((float)((float)((float)(*(float *)&v18 - *(float *)&i) * (float)v13) / v27)
                               + *(float *)&i);
      __libm_sse2_exp(a1: v19);
      *(float *)&v20 = v20;
      *p_m_flMinLuminance = *(float *)&v20 - 0.0099999998;
      v21 = (__m128)LODWORD(v29);
      v21.m128_f32[0] = (float)((float)((float)(v29 + 1.0) * v28) / v27) + *(float *)&v31;
      __libm_sse2_exp(a1: _mm_cvtps_pd(v21));
      *(float *)&v22 = v22;
      v23 = *(float *)&v22 - 0.0099999998;
    }
    p_m_flMinLuminance[1] = v23;
    ++v13;
    p_m_flMinLuminance += 11;
  }
  while ( v13 < v14 );
}

//------------------------------------------------------------------------------
// Address: 0x10196170
// Name: public: void CTonemapSystem::ResetTonemappingScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapSystem::ResetTonemappingScale(CTonemapSystem *this, float flTonemapScale)
{
  float v2; // xmm0_4
  int v4; // xmm1_4
  float flAutoExposureMin; // [esp+0h] [ebp-4h] BYREF

  flAutoExposureMin = *(float *)&this;
  v2 = flTonemapScale;
  if ( flTonemapScale <= 0.0 )
  {
    flAutoExposureMin = 0.0;
    flTonemapScale = 0.0;
    GetExposureRange(pflAutoExposureMin: &flAutoExposureMin, pflAutoExposureMax: &flTonemapScale);
    v2 = (float)(flTonemapScale + flAutoExposureMin) * 0.5;
    *(float *)&v4 = 1.0;
    if ( v2 < 1.0 || (*(float *)&v4 = 10.0, v2 > 10.0) )
      v2 = *(float *)&v4;
  }
  this->m_flCurrentTonemapScale = v2;
  this->m_flTargetTonemapScale = v2;
  this->m_nNumMovingAverageValid = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101961F0
// Name: public: void CTonemapSystem::SetTonemapScale(class IMatRenderContext __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapSystem::SetTonemapScale(
        CTonemapSystem *this,
        IMatRenderContext *pRenderContext,
        float flTargetTonemapScalar,
        float flMinValue,
        float flMaxValue)
{
  float v5; // xmm0_4
  unsigned int m_nNumMovingAverageValid; // eax
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  bool v10; // zf
  float v11; // xmm4_4
  float m_fValue; // xmm1_4
  float m_flTargetTonemapScale; // xmm3_4
  float m_flCurrentTonemapScale; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float flTargetTonemapScalara; // [esp+Ch] [ebp+Ch]

  v5 = flTargetTonemapScalar;
  if ( (LODWORD(flTargetTonemapScalar) & 0x7F800000) != 0x7F800000 )
  {
    m_nNumMovingAverageValid = this->m_nNumMovingAverageValid;
    if ( m_nNumMovingAverageValid >= 0xA )
    {
      qmemcpy(this->m_movingAverageTonemapScale, &this->m_movingAverageTonemapScale[1], 36);
      this->m_movingAverageTonemapScale[9] = flTargetTonemapScalar;
    }
    else
    {
      this->m_movingAverageTonemapScale[m_nNumMovingAverageValid] = flTargetTonemapScalar;
      ++this->m_nNumMovingAverageValid;
    }
    if ( this->m_nNumMovingAverageValid == 10 )
    {
      v7 = (float)0 * 0.2;
      v8 = (float)3 * 0.2;
      v9 = flMinValue;
      v5 = (float)(1.0
                 / (float)((float)((float)4 * 0.2)
                         + (float)(v8
                                 + (float)((float)((float)2 * 0.2)
                                         + (float)((float)((float)1 * 0.2)
                                                 + (float)(v7
                                                         + (float)((float)((float)1 * 0.2)
                                                                 + (float)((float)((float)2 * 0.2)
                                                                         + (float)(v8
                                                                                 + (float)((float)((float)4 * 0.2)
                                                                                         + (float)((float)5 * 0.2)))))))))))
         * (float)((float)(this->m_movingAverageTonemapScale[9] * (float)((float)4 * 0.2))
                 + (float)((float)(this->m_movingAverageTonemapScale[8] * v8)
                         + (float)((float)(this->m_movingAverageTonemapScale[7] * (float)((float)2 * 0.2))
                                 + (float)((float)(this->m_movingAverageTonemapScale[6] * (float)((float)1 * 0.2))
                                         + (float)((float)(this->m_movingAverageTonemapScale[5] * v7)
                                                 + (float)((float)(this->m_movingAverageTonemapScale[4]
                                                                 * (float)((float)1 * 0.2))
                                                         + (float)((float)(this->m_movingAverageTonemapScale[3]
                                                                         * (float)((float)2 * 0.2))
                                                                 + (float)((float)(this->m_movingAverageTonemapScale[2]
                                                                                 * v8)
                                                                         + (float)((float)(this->m_movingAverageTonemapScale[1]
                                                                                         * (float)((float)4 * 0.2))
                                                                                 + (float)(this->m_movingAverageTonemapScale[0]
                                                                                         * (float)((float)5 * 0.2)))))))))));
      if ( flMinValue > v5 || (v9 = flMaxValue, v5 > flMaxValue) )
        v5 = v9;
      v10 = (LODWORD(v5) & 0x7F800000) == 2139095040;
    }
    else
    {
      v10 = (LODWORD(flTargetTonemapScalar) & 0x7F800000) == 2139095040;
    }
    if ( !v10 )
      this->m_flTargetTonemapScale = v5;
    if ( *(float *)(gpGlobals.m_Index + 16) <= 0.0 )
      v11 = 0.0;
    else
      v11 = *(float *)(gpGlobals.m_Index + 16);
    m_fValue = mat_hdr_manual_tonemap_rate.m_pParent->m_Value.m_fValue;
    if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1 )
      m_fValue = m_fValue * 2.0;
    if ( m_fValue == 0.0 )
    {
      this->m_flCurrentTonemapScale = this->m_flTargetTonemapScale;
    }
    else
    {
      m_flTargetTonemapScale = this->m_flTargetTonemapScale;
      m_flCurrentTonemapScale = this->m_flCurrentTonemapScale;
      if ( m_flCurrentTonemapScale > m_flTargetTonemapScale )
      {
        v15 = mat_accelerate_adjust_exposure_down.m_pParent->m_Value.m_fValue * m_fValue;
        v16 = (float)((float)((float)(m_flCurrentTonemapScale - m_flTargetTonemapScale) * (float)(v15 - m_fValue))
                    * 0.66666669)
            + m_fValue;
        if ( v16 <= v15 )
          m_fValue = v16;
        else
          m_fValue = mat_accelerate_adjust_exposure_down.m_pParent->m_Value.m_fValue * m_fValue;
      }
      v17 = m_fValue * v11;
      if ( mat_tonemap_algorithm.m_pParent != nullptr
        && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1
        && v17 >= 0.015625 )
      {
        v17 = 0.015625;
      }
      else if ( v17 >= 0.0 )
      {
        if ( v17 > 1.0 )
          v17 = 1.0;
      }
      else
      {
        v17 = 0.0;
      }
      flTargetTonemapScalara = (float)((float)(1.0 - v17) * this->m_flCurrentTonemapScale)
                             + (float)(m_flTargetTonemapScale * v17);
      this->m_flCurrentTonemapScale = flTargetTonemapScalara;
      if ( (LODWORD(flTargetTonemapScalara) & 0x7F800000) == 0x7F800000 )
        this->m_flCurrentTonemapScale = m_flTargetTonemapScale;
    }
    v18 = mat_force_tonemap_scale.m_pParent->m_Value.m_fValue;
    if ( v18 > 0.0 )
    {
      this->m_flCurrentTonemapScale = v18;
      this->m_flTargetTonemapScale = v18;
      this->m_nNumMovingAverageValid = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196600
// Name: void SetViewFadeParams(unsigned char,unsigned char,unsigned char,unsigned char,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetViewFadeParams(
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a,
        bool bModulate)
{
  s_viewFadeColor[0].x = (float)r * 0.0039215689;
  s_viewFadeColor[0].y = (float)g * 0.0039215689;
  s_viewFadeColor[0].z = (float)b * 0.0039215689;
  s_viewFadeColor[0].w = (float)a * 0.0039215689;
  s_bViewFadeModulate[0] = bModulate;
}

//------------------------------------------------------------------------------
// Address: 0x10196680
// Name: public: virtual void CEnginePostMaterialProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnginePostMaterialProxy::OnBind(CEnginePostMaterialProxy *this, C_BaseEntity *pEnt)
{
  int v3; // eax

  if ( this->m_pMaterialParam_AAValues != nullptr )
    this->m_pMaterialParam_AAValues->SetVecValue_4(
      this: this->m_pMaterialParam_AAValues,
      a2: CEnginePostMaterialProxy::s_vBloomAAValues,
      a3: 4);
  if ( this->m_pMaterialParam_AAValues2 != nullptr )
    this->m_pMaterialParam_AAValues2->SetVecValue_4(
      this: this->m_pMaterialParam_AAValues2,
      a2: CEnginePostMaterialProxy::s_vBloomAAValues2,
      a3: 4);
  if ( this->m_pMaterialParam_BloomUVTransform != nullptr )
    this->m_pMaterialParam_BloomUVTransform->SetVecValue_4(
      this: this->m_pMaterialParam_BloomUVTransform,
      a2: CEnginePostMaterialProxy::s_vBloomUVTransform,
      a3: 4);
  if ( this->m_pMaterialParam_BloomEnable != nullptr )
    this->m_pMaterialParam_BloomEnable->SetIntValue(
      this: this->m_pMaterialParam_BloomEnable,
      a2: CEnginePostMaterialProxy::s_PostBloomEnable);
  if ( this->m_pMaterialParam_BloomAmount != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_BloomAmount->SetFloatValue)(a1: LODWORD(CEnginePostMaterialProxy::s_PostBloomAmount));
  if ( this->m_pMaterialParam_LocalContrastStrength != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_LocalContrastStrength->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[1]));
  if ( this->m_pMaterialParam_LocalContrastEdgeStrength != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_LocalContrastEdgeStrength->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[2]));
  if ( this->m_pMaterialParam_VignetteStart != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_VignetteStart->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[3]));
  if ( this->m_pMaterialParam_VignetteEnd != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_VignetteEnd->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[4]));
  if ( this->m_pMaterialParam_VignetteBlurEnable != nullptr )
    this->m_pMaterialParam_VignetteBlurEnable->SetIntValue(
      this: this->m_pMaterialParam_VignetteBlurEnable,
      a2: s_LocalPostProcessParameters[0].m_flParameters[5] > 0.0);
  if ( this->m_pMaterialParam_VignetteBlurStrength != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_VignetteBlurStrength->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[5]));
  if ( this->m_pMaterialParam_FadeToBlackStrength != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_FadeToBlackStrength->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[6]));
  if ( this->m_pMaterialParam_DepthBlurFocalDistance != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_DepthBlurFocalDistance->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[7]));
  if ( this->m_pMaterialParam_DepthBlurStrength != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_DepthBlurStrength->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[8]));
  if ( this->m_pMaterialParam_ScreenBlurStrength != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_ScreenBlurStrength->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[9]));
  if ( this->m_pMaterialParam_FilmGrainStrength != nullptr )
    ((void (__stdcall *)(_DWORD))this->m_pMaterialParam_FilmGrainStrength->SetFloatValue)(a1: LODWORD(s_LocalPostProcessParameters[0].m_flParameters[10]));
  if ( this->m_pMaterialParam_FadeType != nullptr )
  {
    v3 = s_bViewFadeModulate[0] + 1;
    if ( s_viewFadeColor[0].w <= 0.0 )
      v3 = 0;
    this->m_pMaterialParam_FadeType->SetIntValue(this: this->m_pMaterialParam_FadeType, a2: v3);
  }
  if ( this->m_pMaterialParam_FadeColor != nullptr )
    this->m_pMaterialParam_FadeColor->SetVecValue_4(
      this: this->m_pMaterialParam_FadeColor,
      a2: (const float *)s_viewFadeColor,
      a3: 4);
}

//------------------------------------------------------------------------------
// Address: 0x101968A0
// Name: public: static void CEnginePostMaterialProxy::SetupEnginePostMaterialAA(bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEnginePostMaterialProxy::SetupEnginePostMaterialAA(bool bPerformSoftwareAA, float flAAStrength)
{
  int m_nValue; // eax
  int v3; // eax

  if ( bPerformSoftwareAA )
  {
    CEnginePostMaterialProxy::s_vBloomAAValues[0] = flAAStrength;
    *(float *)&dword_10654678 = 1.0 - mat_software_aa_blur_one_pixel_lines.m_pParent->m_Value.m_fValue;
    if ( mat_software_aa_quality.m_pParent != nullptr )
      m_nValue = mat_software_aa_quality.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    *(float *)&dword_1065467C = (float)m_nValue;
    if ( mat_software_aa_debug.m_pParent != nullptr )
      v3 = mat_software_aa_debug.m_pParent->m_Value.m_nValue;
    else
      v3 = 0;
    *(float *)&dword_10654680 = (float)v3;
    CEnginePostMaterialProxy::s_vBloomAAValues2[0] = mat_software_aa_edge_threshold.m_pParent->m_Value.m_fValue;
    dword_10654688 = LODWORD(mat_software_aa_tap_offset.m_pParent->m_Value.m_fValue);
  }
  else
  {
    CEnginePostMaterialProxy::s_vBloomAAValues[0] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196950
// Name: public: static void CEnginePostMaterialProxy::SetupEnginePostMaterial(class Vector4D const __near &,class Vector4D const __near &,class Vector2D const __near &,bool,bool,bool,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEnginePostMaterialProxy::SetupEnginePostMaterial(
        const Vector4D *fullViewportBloomUVs,
        const Vector4D *fullViewportFBUVs,
        const Vector2D *destTexSize,
        bool bPerformSoftwareAA,
        bool bPerformBloom,
        bool bPerformColCorrect,
        float flAAStrength,
        float flBloomAmount)
{
  CEnginePostMaterialProxy::s_PostBloomAmount = flBloomAmount;
  CEnginePostMaterialProxy::s_PostBloomEnable = bPerformBloom;
  CEnginePostMaterialProxy::SetupEnginePostMaterialAA(bPerformSoftwareAA, flAAStrength);
  CEnginePostMaterialProxy::SetupEnginePostMaterialTextureTransform(
    fullViewportBloomUVs,
    fullViewportFBUVs,
    fbSize: *destTexSize);
}

//------------------------------------------------------------------------------
// Address: 0x101969B0
// Name: CCEnginePostMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCEnginePostMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0x68u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CEnginePostMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result[5].__vftable = nullptr;
  result[3].__vftable = nullptr;
  result[4].__vftable = nullptr;
  result[6].__vftable = nullptr;
  result[7].__vftable = nullptr;
  result[8].__vftable = nullptr;
  result[9].__vftable = nullptr;
  result[10].__vftable = nullptr;
  result[11].__vftable = nullptr;
  result[12].__vftable = nullptr;
  result[13].__vftable = nullptr;
  result[14].__vftable = nullptr;
  result[15].__vftable = nullptr;
  result[16].__vftable = nullptr;
  result[17].__vftable = nullptr;
  result[18].__vftable = nullptr;
  result[19].__vftable = nullptr;
  result[20].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10196A10
// Name: CCMotionBlurMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCMotionBlurMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CMotionBlurMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10196A30
// Name: public: CTonemapSystem::CTonemapSystem(void)
// Source: json
//------------------------------------------------------------------------------
CTonemapSystem *__thiscall CTonemapSystem::CTonemapSystem(CTonemapSystem *this)
{
  CTonemapSystem *v1; // ebx
  int v2; // edi
  int m_nValue; // ecx
  int v4; // eax
  IVEngineClient *v5; // ecx
  unsigned int v6; // eax
  const char *v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // ebx
  const char *v10; // eax
  int v11; // eax
  CTonemapSystem *v12; // ecx
  int v13; // eax
  float *p_m_flMinLuminance; // esi
  int v15; // eax
  double v16; // xmm0_8
  double v17; // xmm0_8
  __m128d v18; // xmm0
  double v19; // xmm0_8
  __m128 v20; // xmm0
  double v21; // xmm0_8
  float v22; // xmm0_4
  float v23; // xmm1_4
  char *s2[3]; // [esp+0h] [ebp-28h]
  float v26; // [esp+Ch] [ebp-1Ch]
  float v27; // [esp+10h] [ebp-18h]
  float v28; // [esp+14h] [ebp-14h]
  float v29; // [esp+18h] [ebp-10h]
  float v30; // [esp+1Ch] [ebp-Ch]
  CTonemapSystem *v31; // [esp+20h] [ebp-8h]
  int v32; // [esp+24h] [ebp-4h]

  v1 = this;
  this->m_flTargetTonemapScale = 1.0;
  this->m_flCurrentTonemapScale = 1.0;
  v2 = 0;
  this->m_nCurrentQueryFrame = 0;
  this->m_nNumMovingAverageValid = 0;
  this->m_nCurrentAlgorithm = -1;
  this->m_movingAverageTonemapScale[0] = 1.0;
  this->m_movingAverageTonemapScale[1] = 1.0;
  this->m_movingAverageTonemapScale[2] = 1.0;
  this->m_movingAverageTonemapScale[3] = 1.0;
  this->m_movingAverageTonemapScale[4] = 1.0;
  this->m_movingAverageTonemapScale[5] = 1.0;
  this->m_movingAverageTonemapScale[6] = 1.0;
  this->m_movingAverageTonemapScale[7] = 1.0;
  this->m_movingAverageTonemapScale[8] = 1.0;
  this->m_bOverrideTonemapScaleEnabled = false;
  this->m_flOverrideTonemapScale = 1.0;
  v31 = this;
  if ( mat_tonemap_algorithm.m_pParent != nullptr )
    m_nValue = mat_tonemap_algorithm.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( v1->m_nCurrentAlgorithm == m_nValue )
    return v1;
  if ( mat_tonemap_algorithm.m_pParent != nullptr )
    v4 = mat_tonemap_algorithm.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  v1->m_nCurrentAlgorithm = v4;
  v5 = engine;
  if ( engine == nullptr )
  {
    v1->m_nCurrentAlgorithm = -1;
    goto LABEL_23;
  }
  if ( !s_bFirstTime )
    goto LABEL_23;
  s_bFirstTime = false;
  s2[0] = "dod";
  s2[1] = "cstrike";
  s2[2] = "lostcoast";
  v32 = 0;
  while ( 1 )
  {
    v6 = strlen(v5->GetGameDirectory(this: v5));
    v7 = s2[v32];
    if ( v6 >= strlen(v7) )
    {
      v8 = strlen(engine->GetGameDirectory(this: engine));
      v9 = strlen(v7);
      v10 = engine->GetGameDirectory(this: engine);
      if ( _V_stricmp(s1: &v10[v8 - v9], s2: v7) == 0 )
        break;
      v1 = v31;
    }
    if ( ++v32 >= 3 )
      goto LABEL_22;
    v5 = engine;
  }
  ConVar::SetValue(this: (ConVar *)&mat_tonemap_algorithm.IConVar, value: 0);
  if ( mat_tonemap_algorithm.m_pParent != nullptr )
    v11 = mat_tonemap_algorithm.m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  v12 = v31;
  v31->m_nCurrentAlgorithm = v11;
  v1 = v12;
LABEL_22:
  v2 = 0;
LABEL_23:
  v32 = 31;
  if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1 )
    v32 = 17;
  v13 = v32;
  v1->m_nCurrentQueryFrame = 0;
  p_m_flMinLuminance = &v1->m_histogramBucketArray[0].m_flMinLuminance;
  do
  {
    v15 = v13 - 1;
    *(p_m_flMinLuminance - 5) = 0.0;
    p_m_flMinLuminance[2] = 0.0;
    p_m_flMinLuminance[4] = 1.0;
    p_m_flMinLuminance[3] = 0.0;
    p_m_flMinLuminance[5] = 1.0;
    if ( v2 == v15 )
    {
      v22 = 100000.0;
      *p_m_flMinLuminance = 0.0;
    }
    else if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue != 0 )
    {
      v23 = (float)v2 / (float)v15;
      v22 = (float)(v2 + 1) / (float)v15;
      *p_m_flMinLuminance = v23;
      v26 = v22;
      p_m_flMinLuminance[1] = v22;
      if ( v23 > 0.0 )
      {
        __libm_sse2_pow();
        v22 = v26;
      }
      *p_m_flMinLuminance = v23;
      if ( v22 > 0.0 )
        __libm_sse2_pow();
    }
    else
    {
      __libm_sse2_log(a1: (__m128d)0x3F847AE140000000uLL);
      *(float *)&v16 = v16;
      v30 = *(float *)&v16;
      v31 = (CTonemapSystem *)LODWORD(v16);
      __libm_sse2_log(a1: (__m128d)0x3FF028F5C0000000uLL);
      *(float *)&v17 = v17;
      v28 = *(float *)&v17 - *(float *)&v31;
      v29 = (float)v2;
      v27 = (float)v32 - 1.0;
      v18.m128d_f64[0] = (float)((float)((float)((float)(*(float *)&v17 - *(float *)&v31) * (float)v2) / v27)
                               + *(float *)&v31);
      __libm_sse2_exp(a1: v18);
      *(float *)&v19 = v19;
      *p_m_flMinLuminance = *(float *)&v19 - 0.0099999998;
      v20 = (__m128)LODWORD(v29);
      v20.m128_f32[0] = (float)((float)((float)(v29 + 1.0) * v28) / v27) + v30;
      __libm_sse2_exp(a1: _mm_cvtps_pd(v20));
      *(float *)&v21 = v21;
      v22 = *(float *)&v21 - 0.0099999998;
    }
    v13 = v32;
    p_m_flMinLuminance[1] = v22;
    ++v2;
    p_m_flMinLuminance += 11;
  }
  while ( v2 < v13 );
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10196DF0
// Name: class CTonemapSystem __near * GetCurrentTonemappingSystem(void)
// Source: json
//------------------------------------------------------------------------------
CTonemapSystem *__cdecl GetCurrentTonemappingSystem()
{
  if ( (_S5_127 & 1) == 0 )
  {
    _S5_127 |= 1u;
    CTonemapSystem::CTonemapSystem(this: s_HDR_HistogramSystem);
  }
  return s_HDR_HistogramSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10196E20
// Name: CCBloomAddMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCBloomAddMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CBloomAddMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10196E40
// Name: GetBloomAmount
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBloomAmount()
{
  int m_nValue; // eax
  bool v1; // bl
  float m_fValue; // xmm1_4

  g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig);
  if ( mat_hdr_level.m_pParent != nullptr )
    m_nValue = mat_hdr_level.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v1 = m_nValue >= 1;
  if ( !engine->MapHasHDRLighting(this: engine) )
    v1 = false;
  if ( mat_force_bloom.m_pParent != nullptr && mat_force_bloom.m_pParent->m_Value.m_nValue != 0 )
    v1 = true;
  if ( mat_disable_bloom.m_pParent != nullptr && mat_disable_bloom.m_pParent->m_Value.m_nValue != 0 )
    v1 = false;
  if ( building_cubemaps.m_pParent != nullptr && building_cubemaps.m_pParent->m_Value.m_nValue != 0 )
    v1 = false;
  if ( mat_fullbright.m_pParent != nullptr && mat_fullbright.m_pParent->m_Value.m_nValue == 1 )
    v1 = false;
  if ( v1 )
  {
    if ( g_bUseCustomBloomScale )
      m_fValue = g_flCustomBloomScale;
    else
      m_fValue = mat_bloomscale.m_pParent->m_Value.m_fValue;
    currentBloomAmount = (float)((float)(1.0 - mat_bloomamount_rate.m_pParent->m_Value.m_fValue) * currentBloomAmount)
                       + (float)(m_fValue * mat_bloomamount_rate.m_pParent->m_Value.m_fValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196F40
// Name: bool IsDepthOfFieldEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsDepthOfFieldEnabled()
{
  const CViewSetup *v0; // esi
  bool result; // al

  v0 = view->GetViewSetup(this: view);
  if ( v0 != nullptr
    && g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT
    && g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 92 )
  {
    if ( (*((_BYTE *)v0 + 240) & 8) != 0 )
      return true;
    if ( mat_dof_enabled.m_pParent != nullptr && mat_dof_enabled.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( mat_dof_override.m_pParent == nullptr )
        return g_bDOFEnabled;
      result = true;
      if ( mat_dof_override.m_pParent->m_Value.m_nValue == 0 )
        return g_bDOFEnabled;
      return result;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10196FC0
// Name: public: virtual void CFunctor6<bool (*)(int,int,int,int,bool,bool),int,int,int,int,bool,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<bool (__cdecl *)(int,int,int,int,bool,bool),int,int,int,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<bool (__cdecl*)(int,int,int,int,bool,bool),int,int,int,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(
    a1: this->m_arg1,
    a2: this->m_arg2,
    a3: this->m_arg3,
    a4: this->m_arg4,
    a5: this->m_arg5,
    a6: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x10196FF0
// Name: SetRenderTargetAndViewPort
// Source: json
//------------------------------------------------------------------------------
void __usercall SetRenderTargetAndViewPort(ITexture *rt@<edi>)
{
  IMatRenderContext *v1; // esi
  IMatRenderContext_vtbl *v2; // ebx
  int v3; // eax
  int v4; // eax

  v1 = materials->GetRenderContext(this: materials);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  v1->SetRenderTarget(this: v1, a2: rt);
  if ( rt != nullptr )
  {
    v2 = v1->__vftable;
    v3 = rt->GetActualHeight(this: rt);
    v4 = ((int (__thiscall *)(ITexture *, int))rt->GetActualWidth)(a1: rt, a2: v3);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, int))v2->Viewport)(a1: v1, a2: 0, a3: 0, a4: v4);
  }
  v1->EndRender(this: v1);
  v1->Release(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10197060
// Name: public: void CHistogramBucket::IssueQuery(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistogramBucket::IssueQuery(CHistogramBucket *this, int nFrameNum)
{
  IMatRenderContext *v3; // esi
  float m_flMinLuminance; // xmm0_4
  float m_flMaxLuminance; // xmm0_4
  IMaterial *(__thiscall *FindMaterial)(IMaterialSystem *, const char *, const char *, bool, const char *); // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  int v13; // ecx
  float v14; // xmm2_4
  float v15; // xmm2_4
  int v16; // eax
  int v17; // ecx
  float v18; // xmm2_4
  int v19; // eax
  float v20; // xmm0_4
  int v21; // xmm0_4
  void (__thiscall *DrawScreenSpaceRectangle)(IMatRenderContext *, IMaterial *, int, int, int, int, float, float, float, float, int, int, void *, int, int); // eax
  IMaterial *v23; // eax
  void (__thiscall *SetStencilState)(IMatRenderContext *, const ShaderStencilState_t *); // edx
  bool v25; // zf
  int v26; // [esp+A4h] [ebp-A0h]
  ShaderStencilState_t stateDisable; // [esp+CCh] [ebp-78h] BYREF
  ShaderStencilState_t state; // [esp+ECh] [ebp-58h] BYREF
  float v29; // [esp+10Ch] [ebp-38h]
  float v30; // [esp+110h] [ebp-34h]
  int nBorderHeight; // [esp+114h] [ebp-30h]
  int nBorderWidth; // [esp+118h] [ebp-2Ch]
  int nViewportHeight; // [esp+11Ch] [ebp-28h] BYREF
  int nViewportWidth; // [esp+120h] [ebp-24h] BYREF
  int nViewportX; // [esp+124h] [ebp-20h] BYREF
  int nViewportY; // [esp+128h] [ebp-1Ch] BYREF
  int nScreenMaxY; // [esp+12Ch] [ebp-18h]
  int nScreenMaxX; // [esp+130h] [ebp-14h]
  int nWindowWidth; // [esp+134h] [ebp-10h] BYREF
  int nWindowHeight; // [esp+138h] [ebp-Ch] BYREF
  int flTestRangeMin; // [esp+13Ch] [ebp-8h]
  int nScreenMinX; // [esp+140h] [ebp-4h]

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( this->m_hOcclusionQueryHandle == nullptr )
    this->m_hOcclusionQueryHandle = v3->CreateOcclusionQueryObject(this: v3);
  v3->GetViewport(this: v3, a2: &nViewportX, a3: &nViewportY, a4: &nViewportWidth, a5: &nViewportHeight);
  m_flMinLuminance = this->m_flMinLuminance;
  if ( m_flMinLuminance == 0.0 )
    m_flMinLuminance = -1.0e20;
  flTestRangeMin = LODWORD(m_flMinLuminance);
  m_flMaxLuminance = this->m_flMaxLuminance;
  if ( m_flMaxLuminance == 1.0 )
    m_flMaxLuminance = 1.0e20;
  FindMaterial = materials->FindMaterial;
  nScreenMinX = LODWORD(m_flMaxLuminance);
  v7 = (int)FindMaterial(this: materials, a2: "dev/lumcompare", a3: "Other textures", a4: true, a5: nullptr);
  v8 = (*(int (__thiscall **)(int, const char *, _DWORD, int))(*(_DWORD *)v7 + 44))(a1: v7, a2: "$C0_X", a3: 0, a4: 1);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 16))(a1: v8, a2: flTestRangeMin);
  v9 = (*(int (__thiscall **)(int, const char *, _DWORD, int))(*(_DWORD *)v7 + 44))(a1: v7, a2: "$C0_Y", a3: 0, a4: 1);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: nScreenMinX);
  v10 = (float)(nViewportX + nViewportWidth - 1);
  v11 = (float)(v10 - (float)nViewportX) * this->m_flScreenMaxX;
  v12 = (float)((float)(v10 - (float)nViewportX) * this->m_flScreenMinX) + (float)nViewportX;
  nScreenMaxX = (int)(float)(v11 + (float)nViewportX);
  v13 = (int)v12;
  v14 = (float)(nViewportY + nViewportHeight - 1);
  nScreenMaxY = (int)(float)((float)((float)(v14 - (float)nViewportY) * this->m_flScreenMaxY) + (float)nViewportY);
  v15 = (float)((float)(v14 - (float)nViewportY) * this->m_flScreenMinY) + (float)nViewportY;
  nScreenMinX = v13;
  v16 = (int)v15;
  v17 = nScreenMaxX - v13 + 1;
  v18 = 1.0 - mat_exposure_center_region_x.m_pParent->m_Value.m_fValue;
  flTestRangeMin = v16;
  nBorderWidth = (int)(float)((float)(v18 * 0.5) * (float)v17);
  v19 = nScreenMaxY - v16 + 1;
  v20 = (float)((float)(1.0 - mat_exposure_center_region_y.m_pParent->m_Value.m_fValue) * 0.5) * (float)v19;
  this->m_nPixels = v17 * v19;
  state.m_nWriteMask = -1;
  state.m_nTestMask = -1;
  nBorderHeight = (int)v20;
  state.m_bEnable = false;
  state.m_ZFailOp = SHADER_STENCILOP_KEEP;
  state.m_FailOp = SHADER_STENCILOP_KEEP;
  state.m_PassOp = SHADER_STENCILOP_KEEP;
  state.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
  state.m_nReferenceValue = 0;
  if ( mat_tonemapping_occlusion_use_stencil.m_pParent != nullptr
    && mat_tonemapping_occlusion_use_stencil.m_pParent->m_Value.m_nValue != 0 )
  {
    state.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
    state.m_nWriteMask = 1;
    state.m_bEnable = true;
    state.m_PassOp = SHADER_STENCILOP_SET_TO_REFERENCE;
    state.m_FailOp = SHADER_STENCILOP_KEEP;
    state.m_ZFailOp = SHADER_STENCILOP_KEEP;
    state.m_nReferenceValue = 1;
    v3->SetStencilState(this: v3, a2: &state);
  }
  else
  {
    v3->BeginOcclusionQueryDrawing(this: v3, a2: this->m_hOcclusionQueryHandle);
  }
  nWindowWidth = 0;
  nWindowHeight = 0;
  v3->GetWindowSize(this: v3, a2: &nWindowWidth, a3: &nWindowHeight);
  nScreenMinX += nBorderWidth;
  flTestRangeMin += nBorderHeight;
  *(float *)&v21 = (float)(nScreenMaxY - nBorderHeight);
  nScreenMaxY = nScreenMaxY - nBorderHeight - flTestRangeMin + 1;
  *(float *)&v26 = (float)(nScreenMaxX - nBorderWidth);
  nScreenMaxX = nScreenMaxX - nBorderWidth - nScreenMinX + 1;
  DrawScreenSpaceRectangle = v3->DrawScreenSpaceRectangle;
  nBorderHeight = v21;
  nBorderWidth = v26;
  v30 = (float)flTestRangeMin;
  v29 = (float)nScreenMinX;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))DrawScreenSpaceRectangle)(
    a1: v3,
    a2: v7,
    a3: nScreenMinX - nViewportX,
    a4: flTestRangeMin - nViewportY,
    a5: nScreenMaxX,
    a6: nScreenMaxY,
    a7: (float)nScreenMinX,
    a8: (float)flTestRangeMin,
    a9: v26,
    a10: v21,
    a11: nWindowWidth,
    a12: nWindowHeight,
    a13: 0,
    a14: 1,
    a15: 1);
  if ( mat_tonemapping_occlusion_use_stencil.m_pParent != nullptr
    && mat_tonemapping_occlusion_use_stencil.m_pParent->m_Value.m_nValue != 0 )
  {
    v3->BeginOcclusionQueryDrawing(this: v3, a2: this->m_hOcclusionQueryHandle);
    state.m_bEnable = true;
    state.m_nTestMask = 1;
    state.m_PassOp = SHADER_STENCILOP_KEEP;
    state.m_CompareFunc = SHADER_STENCILFUNC_EQUAL;
    state.m_FailOp = SHADER_STENCILOP_KEEP;
    state.m_ZFailOp = SHADER_STENCILOP_KEEP;
    state.m_nReferenceValue = 1;
    v3->SetStencilState(this: v3, a2: &state);
    v23 = materials->FindMaterial(this: materials, a2: "dev/no_pixel_write", a3: "Other textures", a4: 1, a5: 0);
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, int, int, int, int, float, float, int, int, int, int, _DWORD, int, int))v3->DrawScreenSpaceRectangle)(
      a1: v3,
      a2: v23,
      a3: nScreenMinX,
      a4: flTestRangeMin,
      a5: nScreenMaxX,
      a6: nScreenMaxY,
      a7: COERCE_FLOAT(LODWORD(v29)),
      a8: COERCE_FLOAT(LODWORD(v30)),
      a9: nBorderWidth,
      a10: nBorderHeight,
      a11: nWindowWidth,
      a12: nWindowHeight,
      a13: 0,
      a14: 1,
      a15: 1);
    stateDisable.m_nWriteMask = -1;
    stateDisable.m_nTestMask = -1;
    SetStencilState = v3->SetStencilState;
    stateDisable.m_ZFailOp = SHADER_STENCILOP_KEEP;
    stateDisable.m_FailOp = SHADER_STENCILOP_KEEP;
    stateDisable.m_PassOp = SHADER_STENCILOP_KEEP;
    stateDisable.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
    stateDisable.m_nReferenceValue = 0;
    stateDisable.m_bEnable = false;
    SetStencilState(this: v3, a2: &stateDisable);
  }
  v3->EndOcclusionQueryDrawing(this: v3, a2: this->m_hOcclusionQueryHandle);
  v25 = this->m_state == HESTATE_INITIAL;
  this->m_nFrameQueued = nFrameNum;
  this->m_state = !v25 + 1;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101974C0
// Name: public: void CTonemapSystem::IssueAndReceiveBucketQueries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapSystem::IssueAndReceiveBucketQueries(CTonemapSystem *this)
{
  int v2; // esi
  int v3; // ecx
  CTonemapSystem *v4; // edi
  int v5; // eax
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // esi
  int v12; // eax
  int nNumHistogramBuckets; // [esp+Ch] [ebp-8h]
  int nNumHistogramBucketsa; // [esp+Ch] [ebp-8h]
  int nQueriesIssuedThisFrame; // [esp+10h] [ebp-4h]

  CTonemapSystem::UpdateBucketRanges(this);
  ++this->m_nCurrentQueryFrame;
  v2 = 0;
  nQueriesIssuedThisFrame = 0;
  v3 = 31;
  if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1 )
    v3 = 17;
  v4 = this;
  for ( nNumHistogramBuckets = v3; nNumHistogramBuckets != 0; --nNumHistogramBuckets )
  {
    if ( v4->m_histogramBucketArray[0].m_state != HESTATE_INITIAL )
    {
      if ( (unsigned int)(v4->m_histogramBucketArray[0].m_state - 1) <= 1 )
      {
        v5 = mat_tonemap_query_lag.m_pParent != nullptr ? mat_tonemap_query_lag.m_pParent->m_Value.m_nValue : 0;
        if ( this->m_nCurrentQueryFrame > v5 + v4->m_histogramBucketArray[0].m_nFrameQueued )
        {
          v6 = materials->GetRenderContext(this: materials);
          v7 = v6;
          if ( v6 != nullptr )
            v6->BeginRender(this: v6);
          v8 = v7->OcclusionQuery_GetNumPixelsRendered(
                 this: v7,
                 a2: v4->m_histogramBucketArray[0].m_hOcclusionQueryHandle);
          if ( v8 != -1 )
          {
            v4->m_histogramBucketArray[0].m_nPixelsInRange = v8;
            v4->m_histogramBucketArray[0].m_state = HESTATE_QUERY_DONE;
          }
          v7->EndRender(this: v7);
          v7->Release(this: v7);
          v2 = nQueriesIssuedThisFrame;
        }
      }
    }
    else if ( v2 < 1 )
    {
      CHistogramBucket::IssueQuery(this: v4->m_histogramBucketArray, nFrameNum: this->m_nCurrentQueryFrame);
      nQueriesIssuedThisFrame = ++v2;
    }
    v4 = (CTonemapSystem *)((char *)v4 + 44);
  }
  if ( v2 < 1 )
  {
    do
    {
      nNumHistogramBucketsa = 31;
      if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1 )
        nNumHistogramBucketsa = 17;
      v9 = -1;
      v10 = 0;
      v11 = -44;
      v12 = 0;
      do
      {
        if ( this->m_histogramBucketArray[v12].m_state == HESTATE_QUERY_DONE
          && (v9 == -1
           || this->m_histogramBucketArray[v12].m_nFrameQueued < *(int *)((char *)&this->m_histogramBucketArray[0].m_nFrameQueued
                                                                        + v11)) )
        {
          v9 = v10;
          v11 = v12 * 44;
        }
        ++v10;
        ++v12;
      }
      while ( v10 < nNumHistogramBucketsa );
      if ( v9 == -1 )
        break;
      CHistogramBucket::IssueQuery(this: &this->m_histogramBucketArray[v9], nFrameNum: this->m_nCurrentQueryFrame);
      ++nQueriesIssuedThisFrame;
    }
    while ( nQueriesIssuedThisFrame < 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197630
// Name: public: float CTonemapSystem::ComputeTargetTonemapScalar(bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTonemapSystem::ComputeTargetTonemapScalar(CTonemapSystem *this, bool bGetIdealTargetForDebugMode)
{
  float m_fValue; // xmm0_4
  float flPercentTargetToSnapToIfInSameBin; // xmm3_4
  float v5; // xmm0_4
  float flPercentBrightPixels; // xmm2_4
  float v7; // xmm0_4
  double LocationOfPercentBrightPixels; // st7
  float v9; // xmm0_4
  double v10; // st7
  IMatRenderContext *v11; // edi
  HistogramEntryState_t m_state; // eax
  float v14; // xmm1_4
  float v15; // xmm0_4
  int v16; // ecx
  float *p_m_flMinLuminance; // eax
  int i; // esi
  int v19; // edx
  int v20; // edx
  int v21; // edx
  int v22; // edx
  int v23; // edx
  int v24; // edx
  int v25; // edx
  int v26; // edx
  int v27; // edx
  int v28; // edx
  float flTonemapMinAvgLum; // [esp+Ch] [ebp-8h]
  float flTonemapPercentTarget; // [esp+10h] [ebp-4h]
  float flAverageLuminancec; // [esp+1Ch] [ebp+8h]
  float flAverageLuminance; // [esp+1Ch] [ebp+8h]
  float flAverageLuminancea; // [esp+1Ch] [ebp+8h]
  float flAverageLuminanceb; // [esp+1Ch] [ebp+8h]

  if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1 )
  {
    m_fValue = mat_force_tonemap_percent_target.m_pParent->m_Value.m_fValue;
    if ( m_fValue < 0.0 )
      m_fValue = g_flTonemapPercentTarget;
    flPercentTargetToSnapToIfInSameBin = m_fValue;
    v5 = mat_force_tonemap_percent_bright_pixels.m_pParent->m_Value.m_fValue;
    if ( v5 < 0.0 )
      v5 = g_flTonemapPercentBrightPixels;
    flPercentBrightPixels = v5;
    v7 = mat_force_tonemap_min_avglum.m_pParent->m_Value.m_fValue;
    if ( v7 < 0.0 )
      v7 = g_flTonemapMinAvgLum;
    flTonemapMinAvgLum = v7;
    if ( bGetIdealTargetForDebugMode )
      LocationOfPercentBrightPixels = CTonemapSystem::FindLocationOfPercentBrightPixels(
                                        this,
                                        flPercentBrightPixels,
                                        flPercentTargetToSnapToIfInSameBin: -1.0);
    else
      LocationOfPercentBrightPixels = CTonemapSystem::FindLocationOfPercentBrightPixels(
                                        this,
                                        flPercentBrightPixels,
                                        flPercentTargetToSnapToIfInSameBin);
    flAverageLuminancec = LocationOfPercentBrightPixels;
    v9 = flAverageLuminancec;
    if ( flAverageLuminancec < 0.0 )
      v9 = flPercentTargetToSnapToIfInSameBin * 0.0099999998;
    if ( v9 < 0.000099999997 )
      v9 = 0.000099999997;
    flAverageLuminance = (float)(flPercentTargetToSnapToIfInSameBin * 0.0099999998) / v9;
    v10 = CTonemapSystem::FindLocationOfPercentBrightPixels(
            this,
            flPercentBrightPixels: 50.0,
            flPercentTargetToSnapToIfInSameBin: -1.0);
    flTonemapPercentTarget = v10;
    if ( v10 > 0.0
      && (float)((float)(flTonemapMinAvgLum * 0.0099999998) / flTonemapPercentTarget) > (float)((float)(flPercentTargetToSnapToIfInSameBin * 0.0099999998)
                                                                                              / v9) )
    {
      flAverageLuminance = (float)(flTonemapMinAvgLum * 0.0099999998) / flTonemapPercentTarget;
    }
    v11 = materials->GetRenderContext(this: materials);
    if ( v11 != nullptr )
      v11->BeginRender(this: v11);
    flAverageLuminancea = this->m_flCurrentTonemapScale * flAverageLuminance;
    if ( flAverageLuminancea < 0.001 )
      flAverageLuminancea = 0.001;
    if ( v11 != nullptr )
    {
      v11->EndRender(this: v11);
      v11->Release(this: v11);
    }
    return flAverageLuminancea;
  }
  else
  {
    m_state = this->m_histogramBucketArray[30].m_state;
    v14 = 1.0;
    if ( m_state == HESTATE_QUERY_DONE || m_state == HESTATE_QUERY_IN_FLIGHT )
      v14 = (float)(1.0 / (float)this->m_histogramBucketArray[30].m_nPixelsInRange)
          * (float)this->m_histogramBucketArray[30].m_nPixels;
    if ( (LODWORD(v14) & 0x7F800000) == 0x7F800000 )
      v14 = 1.0;
    v15 = 0.0;
    v16 = 0;
    p_m_flMinLuminance = &this->m_histogramBucketArray[0].m_flMinLuminance;
    for ( i = 3; i != 0; --i )
    {
      v19 = *((_DWORD *)p_m_flMinLuminance - 5);
      if ( v19 == 3 || v19 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance - 2);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[1] + *p_m_flMinLuminance) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance - 1) * v14));
      }
      v20 = *((_DWORD *)p_m_flMinLuminance + 6);
      if ( v20 == 3 || v20 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 9);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[12] + p_m_flMinLuminance[11]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 10) * v14));
      }
      v21 = *((_DWORD *)p_m_flMinLuminance + 17);
      if ( v21 == 3 || v21 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 20);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[23] + p_m_flMinLuminance[22]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 21) * v14));
      }
      v22 = *((_DWORD *)p_m_flMinLuminance + 28);
      if ( v22 == 3 || v22 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 31);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[34] + p_m_flMinLuminance[33]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 32) * v14));
      }
      v23 = *((_DWORD *)p_m_flMinLuminance + 39);
      if ( v23 == 3 || v23 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 42);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[45] + p_m_flMinLuminance[44]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 43) * v14));
      }
      v24 = *((_DWORD *)p_m_flMinLuminance + 50);
      if ( v24 == 3 || v24 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 53);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[56] + p_m_flMinLuminance[55]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 54) * v14));
      }
      v25 = *((_DWORD *)p_m_flMinLuminance + 61);
      if ( v25 == 3 || v25 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 64);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[67] + p_m_flMinLuminance[66]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 65) * v14));
      }
      v26 = *((_DWORD *)p_m_flMinLuminance + 72);
      if ( v26 == 3 || v26 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 75);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[78] + p_m_flMinLuminance[77]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 76) * v14));
      }
      v27 = *((_DWORD *)p_m_flMinLuminance + 83);
      if ( v27 == 3 || v27 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 86);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[89] + p_m_flMinLuminance[88]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 87) * v14));
      }
      v28 = *((_DWORD *)p_m_flMinLuminance + 94);
      if ( v28 == 3 || v28 == 2 )
      {
        v16 += *((_DWORD *)p_m_flMinLuminance + 97);
        v15 = v15
            + (float)((float)((float)(p_m_flMinLuminance[100] + p_m_flMinLuminance[99]) * 0.5)
                    * (float)((float)*((int *)p_m_flMinLuminance + 98) * v14));
      }
      p_m_flMinLuminance += 110;
    }
    if ( v16 <= 0 )
    {
      return 0.0049999999 / 0.5;
    }
    else
    {
      flAverageLuminanceb = v15 * (float)(1.0 / (float)v16);
      if ( flAverageLuminanceb < 0.000099999997 )
        flAverageLuminanceb = 0.000099999997;
      return 0.0049999999 / flAverageLuminanceb;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197AF0
// Name: public: void CTonemapSystem::DisplayHistogram(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTonemapSystem::DisplayHistogram(CTonemapSystem *this@<ecx>, int a2@<esi>)
{
  CTonemapSystem *v2; // ebx
  int v3; // esi
  int v4; // edx
  int *p_m_nPixelsInRange; // eax
  int i; // edi
  int v7; // ecx
  int v8; // ecx
  float v9; // xmm0_4
  float v10; // edx
  ConVar *m_pParent; // eax
  float m_fValue; // xmm0_4
  void (*Con_NPrintf)(IVEngineClient *, int, const char *, ...); // eax
  const char *v14; // edi
  CTonemapSystem *v15; // ecx
  float v16; // xmm0_4
  float v17; // xmm2_4
  int v18; // ecx
  int v19; // edi
  float *p_m_flMaxLuminance; // ecx
  int v21; // eax
  int v22; // edx
  float v23; // xmm0_4
  int v24; // ebx
  float v25; // xmm0_4
  bool v26; // zf
  float v27; // xmm3_4
  float v28; // xmm1_4
  float flPercentBrightPixels; // xmm0_4
  double LocationOfPercentBrightPixels; // st7
  CTonemapSystem *v31; // ecx
  double v32; // st7
  void (__thiscall *v33)(int, int, int, int, int); // edx
  int v34; // ebx
  int v35; // edi
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  void (__thiscall *v42)(int, int, int, int, int); // edx
  CTonemapSystem *v43; // edi
  void (__thiscall *v44)(int, int, int, int, int); // eax
  float v45; // xmm3_4
  int v46; // ecx
  int nViewportHeight; // [esp+1ECh] [ebp-34h] BYREF
  float flTargetPixelStart; // [esp+1F0h] [ebp-30h]
  int nViewportWidth; // [esp+1F4h] [ebp-2Ch] BYREF
  int nViewportX; // [esp+1F8h] [ebp-28h] BYREF
  CTonemapSystem *v51; // [esp+1FCh] [ebp-24h]
  int xpStart; // [esp+200h] [ebp-20h]
  float flBarWidth; // [esp+204h] [ebp-1Ch]
  int flBarStart; // [esp+208h] [ebp-18h]
  int nMaxValidPixels; // [esp+20Ch] [ebp-14h]
  float flAutoExposureMax; // [esp+210h] [ebp-10h]
  int nViewportY; // [esp+214h] [ebp-Ch] BYREF
  int flAutoExposureMin; // [esp+218h] [ebp-8h]
  int nTotalGraphPixelsWide; // [esp+21Ch] [ebp-4h]

  v2 = this;
  v51 = this;
  if ( mat_show_histogram.m_pParent == nullptr
    || mat_show_histogram.m_pParent->m_Value.m_nValue == 0
    || mat_dynamic_tonemapping.m_pParent == nullptr
    || mat_dynamic_tonemapping.m_pParent->m_Value.m_nValue == 0
    || g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
  {
    return;
  }
  v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 440))(a1: v3);
  (*(void (__thiscall **)(int, int *, int *, int *, int *))(*(_DWORD *)v3 + 156))(
    a1: v3,
    a2: &nViewportX,
    a3: &nViewportY,
    a4: &nViewportWidth,
    a5: &nViewportHeight);
  v4 = 30;
  flAutoExposureMin = 30;
  if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1 )
  {
    flAutoExposureMin = 16;
    v4 = 16;
  }
  *(float *)&nMaxValidPixels = 0.0;
  flAutoExposureMax = 0.0;
  nTotalGraphPixelsWide = 0;
  p_m_nPixelsInRange = &v2->m_histogramBucketArray[0].m_nPixelsInRange;
  for ( i = v4; i != 0; --i )
  {
    v7 = *(p_m_nPixelsInRange - 4);
    if ( v7 == 3 || v7 == 2 )
    {
      v8 = *p_m_nPixelsInRange;
      LODWORD(flAutoExposureMax) += *p_m_nPixelsInRange;
      if ( v8 > nMaxValidPixels )
        nMaxValidPixels = v8;
    }
    v9 = (float)(*((float *)p_m_nPixelsInRange + 2) - *((float *)p_m_nPixelsInRange + 1)) * 500.0;
    if ( v9 < 1.0 )
      v9 = 1.0;
    p_m_nPixelsInRange += 11;
    nTotalGraphPixelsWide += (int)v9 + 2;
  }
  v10 = *(float *)&flAutoExposureMin;
  m_pParent = mat_show_histogram.m_pParent;
  if ( mat_show_histogram.m_pParent != nullptr && mat_show_histogram.m_pParent->m_Value.m_nValue == 1 )
  {
    m_fValue = mat_force_tonemap_min_avglum.m_pParent->m_Value.m_fValue;
    if ( m_fValue < 0.0 )
      m_fValue = g_flTonemapMinAvgLum;
    Con_NPrintf = engine->Con_NPrintf;
    flBarWidth = m_fValue;
    Con_NPrintf(this: engine, a2: nViewportY / 10 + 23, a3: "(Histogram luminance is in linear space)");
    v14 = "On";
    if ( !v2->m_bOverrideTonemapScaleEnabled )
      v14 = "Off";
    if ( CTonemapSystem::FindLocationOfPercentBrightPixels(
           this: v2,
           flPercentBrightPixels: 50.0,
           flPercentTargetToSnapToIfInSameBin: -1.0) >= 0.0 )
    {
      *(float *)&xpStart = CTonemapSystem::FindLocationOfPercentBrightPixels(
                             this: v15,
                             flPercentBrightPixels: 50.0,
                             flPercentTargetToSnapToIfInSameBin: -1.0);
      v16 = *(float *)&xpStart;
    }
    else
    {
      v16 = 0.0;
    }
    engine->Con_NPrintf(
      this: engine,
      a2: nViewportY / 10 + 27,
      a3: "AvgLum @ %4.2f%%  flTonemapMinAvgLum = %4.2f%%  Using %d pixels  Override(%s): %4.2f",
      (float)(v16 * 100.0),
      flBarWidth,
      flAutoExposureMax,
      v14,
      v2->m_flOverrideTonemapScale);
    if ( g_bUseCustomBloomScale )
      v17 = g_flCustomBloomScale;
    else
      v17 = mat_bloomscale.m_pParent->m_Value.m_fValue;
    engine->Con_NPrintf(
      this: engine,
      a2: nViewportY / 10 + 29,
      a3: "BloomScale = %4.2f  mat_hdr_manual_tonemap_rate = %4.2f  mat_accelerate_adjust_exposure_down = %4.2f",
      v17,
      mat_hdr_manual_tonemap_rate.m_pParent->m_Value.m_fValue,
      mat_accelerate_adjust_exposure_down.m_pParent->m_Value.m_fValue);
    m_pParent = mat_show_histogram.m_pParent;
    v10 = *(float *)&flAutoExposureMin;
  }
  v18 = nViewportX - nTotalGraphPixelsWide + nViewportWidth - 10;
  v19 = nViewportY + 4;
  xpStart = v18;
  flBarStart = nViewportY + 4;
  if ( m_pParent == nullptr || m_pParent->m_Value.m_nValue != 1 )
    goto LABEL_63;
  flAutoExposureMin = nViewportX - nTotalGraphPixelsWide + nViewportWidth - 10;
  if ( SLODWORD(v10) <= 0 )
    goto LABEL_54;
  p_m_flMaxLuminance = &v2->m_histogramBucketArray[0].m_flMaxLuminance;
  LODWORD(flAutoExposureMax) = &v2->m_histogramBucketArray[0].m_flMaxLuminance;
  flBarWidth = v10;
  while ( 1 )
  {
    v21 = *((_DWORD *)p_m_flMaxLuminance - 6);
    v22 = 0;
    if ( v21 == 3 || v21 == 2 )
      v22 = *((_DWORD *)p_m_flMaxLuminance - 2);
    v23 = (float)(*p_m_flMaxLuminance - *(p_m_flMaxLuminance - 1)) * 500.0;
    if ( v23 < 1.0 )
      v23 = 1.0;
    v24 = (int)v23;
    if ( v22 != 0 )
    {
      v25 = (float)((float)v22 / (float)nMaxValidPixels) * 200.0;
      if ( v25 <= 200.0 )
      {
        if ( v25 < 1.0 )
        {
          v25 = 1.0;
LABEL_50:
          (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 255, a3: 0, a4: 0);
          (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
            a1: v3,
            a2: flAutoExposureMin,
            a3: flBarStart - (int)v25 + 200,
            a4: v24,
            a5: (int)v25);
          (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
          v19 = flBarStart;
          goto LABEL_52;
        }
        if ( v25 <= 200.0 )
          goto LABEL_50;
      }
      v25 = 200.0;
      goto LABEL_50;
    }
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 0, a4: 0);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
      a1: v3,
      a2: flAutoExposureMin,
      a3: v19 + 199,
      a4: v24,
      a5: 1);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
LABEL_52:
    LODWORD(flAutoExposureMax) += 44;
    v26 = LODWORD(flBarWidth)-- == 1;
    flAutoExposureMin += v24 + 2;
    if ( v26 )
      break;
    p_m_flMaxLuminance = (float *)LODWORD(flAutoExposureMax);
  }
  m_pParent = mat_show_histogram.m_pParent;
  v18 = xpStart;
  v2 = v51;
LABEL_54:
  if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue == 1 )
  {
    v27 = mat_force_tonemap_percent_target.m_pParent->m_Value.m_fValue;
    if ( v27 < 0.0 )
      v27 = g_flTonemapPercentTarget;
    flAutoExposureMax = (float)((float)((float)nTotalGraphPixelsWide * v27) * 0.0099999998) + (float)v18;
    v28 = mat_force_tonemap_min_avglum.m_pParent->m_Value.m_fValue;
    flBarWidth = (float)nTotalGraphPixelsWide;
    *(float *)&nMaxValidPixels = (float)v18;
    if ( v28 < 0.0 )
      v28 = g_flTonemapMinAvgLum;
    *(float *)&flAutoExposureMin = (float)((float)((float)nTotalGraphPixelsWide * v28) * 0.0099999998) + (float)v18;
    flPercentBrightPixels = mat_force_tonemap_percent_bright_pixels.m_pParent->m_Value.m_fValue;
    if ( flPercentBrightPixels < 0.0 )
      flPercentBrightPixels = g_flTonemapPercentBrightPixels;
    LocationOfPercentBrightPixels = CTonemapSystem::FindLocationOfPercentBrightPixels(
                                      this: v2,
                                      flPercentBrightPixels,
                                      flPercentTargetToSnapToIfInSameBin: v27);
    flTargetPixelStart = LocationOfPercentBrightPixels * flBarWidth + *(float *)&nMaxValidPixels;
    v32 = CTonemapSystem::FindLocationOfPercentBrightPixels(
            this: v31,
            flPercentBrightPixels: 50.0,
            flPercentTargetToSnapToIfInSameBin: -1.0);
    v33 = *(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152);
    v34 = v19 + 23;
    flBarWidth = v32 * flBarWidth + *(float *)&nMaxValidPixels;
    v33(a1: v3, a2: (int)(float)(flAutoExposureMax - 1.0), a3: v19 + 23, a4: 8, a5: 154);
    (*(void (__thiscall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 127, a4: 0);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
    v35 = v19 + 25;
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
      a1: v3,
      a2: (int)(float)(flAutoExposureMax + 1.0),
      a3: v35,
      a4: 4,
      a5: 150);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 0, a4: 0);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
      a1: v3,
      a2: (int)(float)(flTargetPixelStart + 1.0),
      a3: v35,
      a4: 4,
      a5: 150);
    (*(void (__thiscall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 255, a4: 0);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
      a1: v3,
      a2: (int)(float)(*(float *)&flAutoExposureMin - 1.0),
      a3: v34,
      a4: 8,
      a5: 154);
    (*(void (__thiscall **)(int, _DWORD, int, int))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 114, a4: 188);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
      a1: v3,
      a2: (int)(float)(*(float *)&flAutoExposureMin + 1.0),
      a3: v35,
      a4: 4,
      a5: 150);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 0, a4: 0);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
      a1: v3,
      a2: (int)(float)(flBarWidth + 1.0),
      a3: v35,
      a4: 4,
      a5: 150);
    (*(void (__thiscall **)(int, _DWORD, int, int))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 191, a4: 243);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
    m_pParent = mat_show_histogram.m_pParent;
    v19 = flBarStart;
    v18 = xpStart;
  }
LABEL_63:
  if ( g_bUseCustomAutoExposureMin && g_flCustomAutoExposureMin > 0.0 )
    v36 = g_flCustomAutoExposureMin;
  else
    v36 = mat_autoexposure_min.m_pParent->m_Value.m_fValue;
  *(float *)&flAutoExposureMin = v36;
  if ( !g_bUseCustomAutoExposureMax || (v37 = g_flCustomAutoExposureMax, g_flCustomAutoExposureMax <= 0.0) )
    v37 = mat_autoexposure_max.m_pParent->m_Value.m_fValue;
  v38 = mat_autoexposure_max_multiplier.m_pParent->m_Value.m_fValue * v37;
  flAutoExposureMax = v38;
  if ( mat_hdr_uncapexposure.m_pParent != nullptr && mat_hdr_uncapexposure.m_pParent->m_Value.m_nValue != 0 )
  {
    flAutoExposureMax = 100.0;
    *(float *)&flAutoExposureMin = 0.0;
  }
  else if ( v36 > v38 )
  {
    flAutoExposureMax = v36;
  }
  v39 = (float)nTotalGraphPixelsWide;
  v40 = (float)v18;
  flBarWidth = (float)nTotalGraphPixelsWide;
  *(float *)&flBarStart = (float)v18;
  v41 = 200.0;
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue == 2 )
    v41 = 0.0;
  v42 = *(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152);
  *(float *)&xpStart = (float)((float)((float)v19 + v41) - 4.0) + 20.0;
  v42(a1: v3, a2: (int)v40, a3: (int)*(float *)&xpStart, a4: (int)v39, a5: 4);
  (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v3 + 292))(a1: v3, a2: 200, a3: 200, a4: 200);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
  (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
    a1: v3,
    a2: (int)v40,
    a3: (int)(float)(*(float *)&xpStart + 1.0),
    a4: (int)v39,
    a5: 2);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 0, a4: 0);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
  v43 = v51;
  v44 = *(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152);
  v45 = (float)((float)((float)((float)(v51->m_flCurrentTonemapScale - *(float *)&flAutoExposureMin)
                              / (float)(flAutoExposureMax - *(float *)&flAutoExposureMin))
                      * flBarWidth)
              + *(float *)&flBarStart)
      - 1.0;
  flTargetPixelStart = *(float *)&xpStart - 6.0;
  *(float *)&xpStart = flAutoExposureMax - *(float *)&flAutoExposureMin;
  v44(a1: v3, a2: (int)v45, a3: (int)(float)(flTargetPixelStart - 1.0), a4: 6, a5: 18);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 0, a4: 0);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
  (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v3 + 152))(
    a1: v3,
    a2: (int)(float)((float)((float)((float)(v43->m_flCurrentTonemapScale - *(float *)&flAutoExposureMin)
                               / *(float *)&xpStart)
                       * flBarWidth)
               + *(float *)&flBarStart),
    a3: (int)flTargetPixelStart,
    a4: 4,
    a5: 16);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 255, a3: 255, a4: 0);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
  v46 = 21;
  if ( mat_show_histogram.m_pParent != nullptr && mat_show_histogram.m_pParent->m_Value.m_nValue == 2 )
    v46 = 1;
  engine->Con_NPrintf(
    this: engine,
    a2: v46 + nViewportY / 10,
    a3: "%.2f                                                                             %.2f                               "
    "                                            %.2f",
    *(float *)&flAutoExposureMin,
    (float)((float)(*(float *)&flAutoExposureMin + flAutoExposureMax) * 0.5),
    flAutoExposureMax);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v3 + 152))(a1: v3, a2: 0, a3: 0, a4: 1);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 292))(a1: v3, a2: 0, a3: 0, a4: 0);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 1, a3: 1, a4: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 444))(a1: v3);
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10198540
// Name: public: void CTonemapSystem::UpdateMaterialSystemTonemapScalar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTonemapSystem::UpdateMaterialSystemTonemapScalar(CTonemapSystem *this)
{
  float m_fValue; // xmm0_4
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  float m_flCurrentTonemapScale; // xmm0_4
  void (__thiscall *SetToneMappingScaleLinear)(IMatRenderContext *, const Vector *); // edx
  float flTonemapScale; // xmm0_4
  float v8; // xmm1_4
  _DWORD v9[3]; // [esp+Ch] [ebp-14h] BYREF
  float flAutoExposureMax; // [esp+18h] [ebp-8h] BYREF
  float flAutoExposureMin; // [esp+1Ch] [ebp-4h] BYREF

  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
  {
    v4 = materials->GetRenderContext(this: materials);
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    m_flCurrentTonemapScale = 1.0;
    goto LABEL_20;
  }
  m_fValue = mat_force_tonemap_scale.m_pParent->m_Value.m_fValue;
  if ( mat_fullbright.m_pParent == nullptr || mat_fullbright.m_pParent->m_Value.m_nValue != 1 )
  {
    if ( m_fValue > 0.0 )
      goto LABEL_6;
    if ( this->m_bOverrideTonemapScaleEnabled )
    {
      GetExposureRange(pflAutoExposureMin: &flAutoExposureMin, pflAutoExposureMax: &flAutoExposureMax);
      flTonemapScale = this->m_flOverrideTonemapScale;
      v8 = flAutoExposureMin;
      if ( flAutoExposureMin > flTonemapScale || (v8 = flAutoExposureMax, flTonemapScale > flAutoExposureMax) )
        flTonemapScale = v8;
      CTonemapSystem::ResetTonemappingScale(this, flTonemapScale);
    }
    v4 = materials->GetRenderContext(this: materials);
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    m_flCurrentTonemapScale = this->m_flCurrentTonemapScale;
LABEL_20:
    SetToneMappingScaleLinear = v4->SetToneMappingScaleLinear;
    goto LABEL_21;
  }
  m_fValue = 1.0;
LABEL_6:
  this->m_flCurrentTonemapScale = m_fValue;
  this->m_flTargetTonemapScale = m_fValue;
  this->m_nNumMovingAverageValid = 0;
  v3 = materials->GetRenderContext(this: materials);
  v4 = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  m_flCurrentTonemapScale = this->m_flCurrentTonemapScale;
  SetToneMappingScaleLinear = v4->SetToneMappingScaleLinear;
LABEL_21:
  *(float *)v9 = m_flCurrentTonemapScale;
  *(float *)&v9[1] = m_flCurrentTonemapScale;
  *(float *)&v9[2] = m_flCurrentTonemapScale;
  SetToneMappingScaleLinear(this: v4, a2: (const Vector *)v9);
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101986B0
// Name: void ResetToneMapping(float)
// Source: json
//------------------------------------------------------------------------------
void __usercall ResetToneMapping(int a1@<esi>, float flTonemappingScale)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  int v4; // xmm1_4
  int v5; // esi
  void (__thiscall *v6)(int, _DWORD *); // edx
  _DWORD v7[3]; // [esp+0h] [ebp-14h] BYREF
  float pflAutoExposureMin; // [esp+Ch] [ebp-8h] BYREF
  float pflAutoExposureMax; // [esp+10h] [ebp-4h] BYREF

  if ( (_S5_127 & 1) == 0 )
  {
    _S5_127 |= 1u;
    CTonemapSystem::CTonemapSystem(this: s_HDR_HistogramSystem);
  }
  v2 = flTonemappingScale;
  if ( flTonemappingScale <= 0.0 )
  {
    pflAutoExposureMin = 0.0;
    pflAutoExposureMax = 0.0;
    GetExposureRange(&pflAutoExposureMin, &pflAutoExposureMax);
    v3 = (float)(pflAutoExposureMax + pflAutoExposureMin) * 0.5;
    *(float *)&v4 = 1.0;
    if ( v3 < 1.0 || (*(float *)&v4 = 10.0, v3 > 10.0) )
      v3 = *(float *)&v4;
    v2 = v3;
  }
  s_HDR_HistogramSystem[0].m_flCurrentTonemapScale = v2;
  s_HDR_HistogramSystem[0].m_flTargetTonemapScale = v2;
  s_HDR_HistogramSystem[0].m_nNumMovingAverageValid = 0;
  v5 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: a1);
  if ( v5 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
  v6 = *(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v5 + 576);
  *(float *)v7 = flTonemappingScale;
  *(float *)&v7[1] = flTonemappingScale;
  *(float *)&v7[2] = flTonemappingScale;
  v6(a1: v5, a2: v7);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101987A0
// Name: DoTonemapping
// Source: json
//------------------------------------------------------------------------------
void __usercall DoTonemapping(
        int nY@<edi>,
        IMatRenderContext *pRenderContext,
        int nX,
        int nWidth,
        int nHeight,
        float flAutoExposureMin,
        float flAutoExposureMax)
{
  double v7; // st7
  float v8; // xmm0_4
  float flMaxValue; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  int m_nValue; // eax
  float m_fValue; // xmm0_4
  float flPercentBrightPixels; // xmm0_4
  CTonemapSystem *v15; // eax
  CTonemapSystem *CurrentTonemappingSystem; // eax
  IVEngineClient_vtbl *v17; // esi
  CTonemapSystem *v18; // eax
  CTonemapSystem *v19; // eax
  double LocationOfPercentBrightPixels; // st7
  double v21; // [esp+14h] [ebp-34h]
  double flTargetTonemapScalar; // [esp+2Ch] [ebp-1Ch]
  float flTargetScalar; // [esp+40h] [ebp-8h]
  int flTonemapPercentTarget; // [esp+44h] [ebp-4h]
  float flTonemapPercentTargeta; // [esp+44h] [ebp-4h]

  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE
    && mat_dynamic_tonemapping.m_pParent != nullptr
    && mat_dynamic_tonemapping.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( !s_bScreenEffectTextureIsUpdated )
    {
      UpdateScreenEffectTexture(
        textureIndex: 0,
        x: nX,
        y: nY,
        w: nWidth,
        h: nHeight,
        bDestFullScreen: false,
        pActualRect: nullptr);
      s_bScreenEffectTextureIsUpdated = true;
    }
    if ( (_S5_127 & 1) == 0 )
    {
      _S5_127 |= 1u;
      CTonemapSystem::CTonemapSystem(this: s_HDR_HistogramSystem);
    }
    CTonemapSystem::IssueAndReceiveBucketQueries(this: s_HDR_HistogramSystem);
    if ( (_S5_127 & 1) == 0 )
    {
      _S5_127 |= 1u;
      CTonemapSystem::CTonemapSystem(this: s_HDR_HistogramSystem);
    }
    v7 = CTonemapSystem::ComputeTargetTonemapScalar(this: s_HDR_HistogramSystem, bGetIdealTargetForDebugMode: false);
    flTargetScalar = v7;
    v8 = flTargetScalar;
    flMaxValue = flAutoExposureMax;
    if ( v7 <= flAutoExposureMax )
      v10 = v7;
    else
      v10 = flAutoExposureMax;
    v11 = flAutoExposureMin;
    if ( flAutoExposureMin <= v10 )
    {
      if ( flTargetScalar > flAutoExposureMax )
        v8 = flAutoExposureMax;
    }
    else
    {
      v8 = flAutoExposureMin;
    }
    *(float *)&flTonemapPercentTarget = v8;
    if ( v8 < 0.001 )
    {
      v8 = 0.001;
      *(float *)&flTonemapPercentTarget = 0.001;
    }
    if ( (_S5_127 & 1) == 0 )
    {
      _S5_127 |= 1u;
      CTonemapSystem::CTonemapSystem(this: s_HDR_HistogramSystem);
      flMaxValue = flAutoExposureMax;
      v11 = flAutoExposureMin;
      v8 = *(float *)&flTonemapPercentTarget;
    }
    CTonemapSystem::SetTonemapScale(
      this: s_HDR_HistogramSystem,
      pRenderContext,
      flTargetTonemapScalar: v8,
      flMinValue: v11,
      flMaxValue);
    if ( mat_show_histogram.m_pParent != nullptr )
    {
      m_nValue = mat_show_histogram.m_pParent->m_Value.m_nValue;
      if ( m_nValue != 0 )
      {
        m_fValue = mat_force_tonemap_percent_target.m_pParent->m_Value.m_fValue;
        if ( m_fValue < 0.0 )
          m_fValue = g_flTonemapPercentTarget;
        flTonemapPercentTargeta = m_fValue;
        flPercentBrightPixels = mat_force_tonemap_percent_bright_pixels.m_pParent->m_Value.m_fValue;
        if ( flPercentBrightPixels < 0.0 )
          flPercentBrightPixels = g_flTonemapPercentBrightPixels;
        if ( m_nValue == 1 )
        {
          if ( mat_tonemap_algorithm.m_pParent != nullptr && mat_tonemap_algorithm.m_pParent->m_Value.m_nValue != 0 )
          {
            CurrentTonemappingSystem = GetCurrentTonemappingSystem();
            v17 = engine->__vftable;
            flTargetTonemapScalar = CurrentTonemappingSystem->m_flCurrentTonemapScale;
            v18 = GetCurrentTonemappingSystem();
            v21 = CTonemapSystem::ComputeTargetTonemapScalar(this: v18, bGetIdealTargetForDebugMode: true);
            v19 = GetCurrentTonemappingSystem();
            LocationOfPercentBrightPixels = CTonemapSystem::FindLocationOfPercentBrightPixels(
                                              this: v19,
                                              flPercentBrightPixels,
                                              flPercentTargetToSnapToIfInSameBin: flTonemapPercentTargeta);
            v17->Con_NPrintf(
              this: engine,
              a2: nY / 10 + 25,
              a3: "%.2f%% of pixels above %d%% target @ %4.2f%%  Target Scalar = %4.2f  Min/Max( %4.2f, %4.2f )  Final Scalar: %4.2f",
              flPercentBrightPixels,
              (int)flTonemapPercentTargeta,
              LocationOfPercentBrightPixels * 100.0,
              v21,
              flAutoExposureMin,
              flAutoExposureMax,
              flTargetTonemapScalar);
          }
          else
          {
            v15 = GetCurrentTonemappingSystem();
            engine->Con_NPrintf(
              this: engine,
              a2: nY / 10 + 25,
              a3: "(Original algorithm) Target Scalar = %4.2f  Min/Max( %4.2f, %4.2f )  Current Scalar: %4.2f",
              flTargetScalar,
              flAutoExposureMin,
              flAutoExposureMax,
              v15->m_flCurrentTonemapScale);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198A90
// Name: void UpdateMaterialSystemTonemapScalar(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateMaterialSystemTonemapScalar()
{
  if ( (_S5_127 & 1) == 0 )
  {
    _S5_127 |= 1u;
    CTonemapSystem::CTonemapSystem(this: s_HDR_HistogramSystem);
  }
  CTonemapSystem::UpdateMaterialSystemTonemapScalar(this: s_HDR_HistogramSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10198AC0
// Name: DumpTGAofRenderTarget
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DumpTGAofRenderTarget(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        int width,
        int height,
        const char *pFilename)
{
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // ebx
  unsigned __int8 *v8; // edi
  int v9; // esi
  void *v10; // ebx
  void *v11; // esi
  IMatRenderContext *m_pObject; // esi
  int v13; // [esp-Ch] [ebp-14Ch]
  char szPathedFileName[260]; // [esp+0h] [ebp-140h] BYREF
  CUtlBuffer buffer; // [esp+104h] [ebp-3Ch] BYREF
  ConVarRef mat_queue_mode; // [esp+134h] [ebp-Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+13Ch] [ebp-4h]

  ConVarRef::ConVarRef(this: &mat_queue_mode, pName: "mat_queue_mode");
  if ( mat_queue_mode.m_pConVarState->m_Value.m_nValue != 0 )
  {
    DevMsg(a1: "Error: mat_queue_mode must be 0 to dump debug rendertargets\n");
    ConVar::SetValue(this: (ConVar *)&mat_dump_rts.IConVar, value: 0);
  }
  else
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
                                a1: materials,
                                a2,
                                a3,
                                a4: a1);
    v7 = v6;
    pRenderContext.m_pObject = v6;
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    v8 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * height * width);
    v7->ReadPixels(this: v7, a2: 0, a3: 0, a4: width, a5: height, a6: v8, a7: IMAGE_FORMAT_RGBA8888);
    v9 = 4 * height * width + 1024;
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v9);
    CUtlBuffer::CUtlBuffer(this: &buffer, pBuffer: v10, nSize: v9, nFlags: 0);
    if ( !TGAWriter::WriteToBuffer(
            pImageData: v8,
            &buffer,
            width,
            height,
            srcFormat: IMAGE_FORMAT_RGBA8888,
            dstFormat: IMAGE_FORMAT_RGBA8888) )
      _Error(this: (ISceneTokenProcessor *)&stru_10494564, a2: *(const char **)szPathedFileName);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
    v13 = s_nRTIndex++;
    V_snprintf(pDest: szPathedFileName, maxLen: 260, pFormat: "//MOD/%d_%s_%s.tga", v13, pFilename, "PC");
    v11 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: szPathedFileName, a3: "wb", a4: 0);
    filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buffer.m_Memory.m_pMemory, a3: buffer.m_Put, a4: v11);
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v11);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
    if ( buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
        buffer.m_Memory.m_pMemory = nullptr;
      }
      buffer.m_Memory.m_nAllocationCount = 0;
    }
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198C90
// Name: DownsampleFBQuarterSize
// Source: json
//------------------------------------------------------------------------------
void __usercall DownsampleFBQuarterSize(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IMatRenderContext *pRenderContext,
        int nSrcWidth,
        int nSrcHeight,
        ITexture *pDest,
        int bFloatHDR)
{
  const char *v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // eax

  v8 = "dev/downsample";
  if ( (_BYTE)bFloatHDR == 0 )
    v8 = "dev/downsample_non_hdr";
  v9 = ((int (__thiscall *)(IMaterialSystem *, const char *, const char *, int, _DWORD, int, int, int))materials->FindMaterial)(
         a1: materials,
         a2: v8,
         a3: "Other textures",
         a4: 1,
         a5: 0,
         a6: a2,
         a7: a3,
         a8: a1);
  v10 = (*(int (__thiscall **)(int, const char *, char *, _DWORD))(*(_DWORD *)v9 + 44))(
          a1: v9,
          a2: "$bloomexp",
          a3: (char *)&bFloatHDR + 3,
          a4: 0);
  if ( HIBYTE(bFloatHDR) != 0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 16))(a1: v10, a2: LODWORD(g_flBloomExponent));
  v11 = (*(int (__thiscall **)(int, const char *, char *, _DWORD))(*(_DWORD *)v9 + 44))(
          a1: v9,
          a2: "$bloomsaturation",
          a3: (char *)&bFloatHDR + 3,
          a4: 0);
  if ( HIBYTE(bFloatHDR) != 0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v11 + 16))(a1: v11, a2: LODWORD(g_flBloomSaturation));
  SetRenderTargetAndViewPort(rt: pDest);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pRenderContext->DrawScreenSpaceRectangle)(
    a1: pRenderContext,
    a2: v9,
    a3: 0,
    a4: 0,
    a5: nSrcWidth / 4,
    a6: nSrcHeight / 4,
    a7: 0,
    a8: 0,
    a9: (float)(nSrcWidth - 2),
    a10: (float)(nSrcHeight - 2),
    a11: nSrcWidth,
    a12: nSrcHeight);
  if ( s_bDumpRenderTargets )
    DumpTGAofRenderTarget(
      a1: nSrcWidth / 4,
      a2: nSrcHeight / 4,
      a3: v9,
      width: nSrcWidth / 4,
      height: nSrcHeight / 4,
      pFilename: "QuarterSizeFB");
}

//------------------------------------------------------------------------------
// Address: 0x10198DC0
// Name: Generate8BitBloomTexture
// Source: json
//------------------------------------------------------------------------------
void __cdecl Generate8BitBloomTexture(IMatRenderContext *pRenderContext, char x, char y)
{
  ITexture *v3; // esi
  int v4; // ebx
  int v5; // esi
  IMaterial *(__thiscall *FindMaterial)(IMaterialSystem *, const char *, const char *, bool, const char *); // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // eax
  IMaterial *xblur_mat; // [esp+C8h] [ebp-Ch]
  ITexture *dest_rt1; // [esp+CCh] [ebp-8h]
  IMaterial *yblur_mat; // [esp+D0h] [ebp-4h]
  float bExtractBloomRangea; // [esp+E0h] [ebp+Ch]
  ITexture *dest_rt0; // [esp+E4h] [ebp+10h]

  pRenderContext->PushRenderTargetAndViewport_4(this: pRenderContext);
  v3 = materials->FindTexture(this: materials, a2: "_rt_FullFrameFB", a3: "RenderTargets", a4: 1, a5: 0);
  v4 = v3->GetActualWidth(this: v3);
  v5 = v3->GetActualHeight(this: v3);
  xblur_mat = materials->FindMaterial(this: materials, a2: "dev/blurfilterx_nohdr", a3: "Other textures", a4: 1, a5: 0);
  FindMaterial = materials->FindMaterial;
  if ( y != 0 )
    v7 = ((int (__stdcall *)(const char *))FindMaterial)(a1: "dev/blurfiltery_nohdr_clear");
  else
    v7 = ((int (__stdcall *)(const char *))FindMaterial)(a1: "dev/blurfiltery_nohdr");
  yblur_mat = (IMaterial *)v7;
  dest_rt0 = materials->FindTexture(this: materials, a2: "_rt_SmallFB0", a3: "RenderTargets", a4: 1, a5: 0);
  dest_rt1 = materials->FindTexture(this: materials, a2: "_rt_SmallFB1", a3: "RenderTargets", a4: 1, a5: 0);
  if ( x != 0 )
    DownsampleFBQuarterSize(pRenderContext, nSrcWidth: v4, nSrcHeight: v5, pDest: dest_rt0, bFloatHDR: false);
  else
    DownsampleFBQuarterSize(pRenderContext, nSrcWidth: v4, nSrcHeight: v5, pDest: dest_rt0, bFloatHDR: true);
  SetRenderTargetAndViewPort(rt: dest_rt1);
  v8 = v5 / 4;
  v9 = v4 / 4;
  bExtractBloomRangea = (float)(v8 - 1);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pRenderContext->DrawScreenSpaceRectangle)(
    a1: pRenderContext,
    a2: xblur_mat,
    a3: 0,
    a4: 0,
    a5: v9,
    a6: v8,
    a7: 0,
    a8: 0,
    a9: (float)(v9 - 1),
    a10: LODWORD(bExtractBloomRangea),
    a11: v9,
    a12: v8,
    a13: 0,
    a14: 1,
    a15: 1);
  if ( s_bDumpRenderTargets )
    DumpTGAofRenderTarget(width: v9, height: v8, pFilename: "BlurX");
  SetRenderTargetAndViewPort(rt: dest_rt0);
  v10 = (int)yblur_mat->FindVar(this: yblur_mat, a2: "$bloomamount", a3: nullptr, a4: true);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 16))(a1: v10, a2: 1065353216);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pRenderContext->DrawScreenSpaceRectangle)(
    a1: pRenderContext,
    a2: yblur_mat,
    a3: 0,
    a4: 0,
    a5: v9,
    a6: v8,
    a7: 0,
    a8: 0,
    a9: (float)(v9 - 1),
    a10: LODWORD(bExtractBloomRangea),
    a11: v9,
    a12: v8,
    a13: 0,
    a14: 1,
    a15: 1);
  if ( s_bDumpRenderTargets )
    DumpTGAofRenderTarget(width: v9, height: v8, pFilename: "BlurYAndBloom");
  ((void (__thiscall *)(IMatRenderContext *, const char *, int, _DWORD))pRenderContext->PopRenderTargetAndViewport)(
    a1: pRenderContext,
    a2: "Other textures",
    a3: 1,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10199000
// Name: bool DoImageSpaceMotionBlur(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall DoImageSpaceMotionBlur@<al>(int a1@<ebp>, const CViewSetup *view)
{
  MotionBlurMode_t m_nMotionBlurMode; // eax
  int v3; // edi
  char v4; // al
  int v5; // xmm0_4
  int v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  __int64 v9; // xmm0_8
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float m_flAspectRatio; // xmm4_4
  float fov; // xmm3_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  int *p_flCurrentPitch; // edx
  int *p_nSrcWidth; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  const float *v22; // edx
  const float *p_flCurrentYaw; // eax
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  double v28; // st7
  ITexture *v29; // esi
  float v30; // xmm0_4
  int (__thiscall *GetActualHeight)(ITexture *); // eax
  float v32; // xmm2_4
  float v33; // xmm1_4
  int v34; // eax
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  int v38; // ecx
  float v39; // xmm4_4
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v41; // edi
  ITexture *(__thiscall *FindTexture)(IMaterialSystem *, const char *, const char *, bool, int); // edx
  int v43; // esi
  int v44; // eax
  IMaterial *v45; // esi
  void (__thiscall *v46)(int, float *); // eax
  C_World *ClientWorldEntity; // eax
  int v48; // esi
  __int64 v50; // [esp+88h] [ebp-98h] BYREF
  _BYTE v51[56]; // [esp+90h] [ebp-90h] OVERLAPPED
  int x; // [esp+C8h] [ebp-58h]
  Vector vCurrentPosition; // [esp+CCh] [ebp-54h]
  int y; // [esp+D8h] [ebp-48h]
  int w; // [esp+DCh] [ebp-44h]
  IMaterial *pMatMotionBlur; // [esp+E0h] [ebp-40h] BYREF
  int flMotionBlurFallingMax; // [esp+E4h] [ebp-3Ch]
  int h; // [esp+E8h] [ebp-38h] BYREF
  int nSrcHeight; // [esp+ECh] [ebp-34h]
  float flCurrentYaw; // [esp+F0h] [ebp-30h] BYREF
  float flMotionBlurGlobalStrength; // [esp+F4h] [ebp-2Ch]
  int nSrcWidth; // [esp+F8h] [ebp-28h] BYREF
  float flHorizontalFov; // [esp+FCh] [ebp-24h]
  float flTimeElapsed; // [esp+100h] [ebp-20h] BYREF
  float m_fValue; // [esp+104h] [ebp-1Ch] BYREF
  int flCurrentPitch; // [esp+108h] [ebp-18h] BYREF
  int nViewportHeight; // [esp+10Ch] [ebp-14h] BYREF
  int nDummy; // [esp+110h] [ebp-10h]
  int nViewportWidth; // [esp+114h] [ebp-Ch]
  float flPitchDiffAdjusted; // [esp+118h] [ebp-8h]
  int v71; // [esp+11Ch] [ebp-4h] BYREF
  float retaddr; // [esp+120h] [ebp+0h]

  nViewportWidth = a1;
  flPitchDiffAdjusted = retaddr;
  if ( mat_motion_blur_enabled.m_pParent == nullptr )
    return false;
  if ( mat_motion_blur_enabled.m_pParent->m_Value.m_nValue == 0 )
    return false;
  m_nMotionBlurMode = view->m_nMotionBlurMode;
  if ( m_nMotionBlurMode == MOTION_BLUR_DISABLE )
    return false;
  v3 = view->x;
  LODWORD(vCurrentPosition.x) = view->y;
  LODWORD(vCurrentPosition.y) = view->width;
  w = view->height;
  *(float *)&pMatMotionBlur = mat_motion_blur_rotation_intensity.m_pParent->m_Value.m_fValue * 0.15000001;
  m_fValue = mat_motion_blur_falling_intensity.m_pParent->m_Value.m_fValue;
  vCurrentPosition.z = mat_motion_blur_falling_min.m_pParent->m_Value.m_fValue;
  y = SLODWORD(mat_motion_blur_falling_max.m_pParent->m_Value.m_fValue);
  v4 = m_nMotionBlurMode == MOTION_BLUR_SFM;
  h = SLODWORD(mat_motion_blur_strength.m_pParent->m_Value.m_fValue);
  *(_DWORD *)&v51[44] = v3;
  HIBYTE(nDummy) = v4;
  if ( (_S6_48 & 1) == 0 )
  {
    _S6_48 |= 1u;
    s_History[0].m_flLastTimeUpdate = 0.0;
    dword_1065635C = 0;
    dword_10656360 = 0;
    *(_DWORD *)byte_10656364 = 0;
    *(_DWORD *)&byte_10656364[4] = 0;
    *(_DWORD *)&byte_10656364[8] = 0;
    dword_106563A0 = 0;
    SetIdentityMatrix(matrix: &matrix);
    v4 = HIBYTE(nDummy);
  }
  if ( v4 != 0 )
  {
    s_History[0].m_flLastTimeUpdate = 0.0;
    dword_106563A0 = 0;
    flMotionBlurGlobalStrength = view->m_flShutterTime;
    *(Vector *)byte_10656364 = view->m_vShutterOpenPosition;
    AngleMatrix(angles: &view->m_shutterOpenAngles, matrix: &matrix);
    dword_1065635C = LODWORD(view->m_shutterOpenAngles.x);
    v5 = dword_1065635C;
    if ( *(float *)&dword_1065635C > 180.0 )
    {
      do
        *(float *)&v5 = *(float *)&v5 - 360.0;
      while ( *(float *)&v5 > 180.0 );
      dword_1065635C = v5;
    }
    if ( *(float *)&v5 < -180.0 )
    {
      do
        *(float *)&v5 = *(float *)&v5 + 360.0;
      while ( *(float *)&v5 < -180.0 );
      dword_1065635C = v5;
    }
    dword_10656360 = LODWORD(view->m_shutterOpenAngles.y);
    v6 = dword_10656360;
    if ( *(float *)&dword_10656360 > 180.0 )
    {
      do
        *(float *)&v6 = *(float *)&v6 - 360.0;
      while ( *(float *)&v6 > 180.0 );
      dword_10656360 = v6;
    }
    if ( *(float *)&v6 < -180.0 )
    {
      do
        *(float *)&v6 = *(float *)&v6 + 360.0;
      while ( *(float *)&v6 < -180.0 );
      dword_10656360 = v6;
    }
    v4 = HIBYTE(nDummy);
  }
  else
  {
    flMotionBlurGlobalStrength = *(float *)gpGlobals.m_Index - s_History[0].m_flLastTimeUpdate;
  }
  v7 = view->angles.x;
  flHorizontalFov = v7;
  if ( v4 != 0 )
  {
    v7 = view->m_shutterCloseAngles.x;
    flHorizontalFov = v7;
  }
  if ( v7 > 180.0 )
  {
    do
      v7 = v7 - 360.0;
    while ( v7 > 180.0 );
    flHorizontalFov = v7;
  }
  if ( v7 < -180.0 )
  {
    do
      v7 = v7 + 360.0;
    while ( v7 < -180.0 );
    flHorizontalFov = v7;
  }
  v8 = view->angles.y;
  *(float *)&flMotionBlurFallingMax = v8;
  if ( v4 != 0 )
  {
    v8 = view->m_shutterCloseAngles.y;
    *(float *)&flMotionBlurFallingMax = v8;
  }
  if ( v8 > 180.0 )
  {
    do
      v8 = v8 - 360.0;
    while ( v8 > 180.0 );
    *(float *)&flMotionBlurFallingMax = v8;
  }
  if ( v8 < -180.0 )
  {
    do
      v8 = v8 + 360.0;
    while ( v8 < -180.0 );
    *(float *)&flMotionBlurFallingMax = v8;
  }
  if ( v4 != 0 )
    AngleMatrix(angles: &view->m_shutterCloseAngles, matrix: (matrix3x4_t *)&v50);
  else
    AngleMatrix(angles: &view->angles, matrix: (matrix3x4_t *)&v50);
  v9 = *(_QWORD *)&view->origin.x;
  x = SLODWORD(view->origin.z);
  *(_QWORD *)&v51[48] = v9;
  if ( HIBYTE(nDummy) != 0 )
  {
    *(float *)&v51[48] = view->m_vShutterClosePosition.x;
    *(float *)&v51[52] = view->m_vShutterClosePosition.y;
    x = SLODWORD(view->m_vShutterClosePosition.z);
  }
  v10 = *(float *)&byte_10656364[4] - *(float *)&v51[52];
  v11 = *(float *)&byte_10656364[8] - *(float *)&x;
  v12 = *(float *)byte_10656364 - *(float *)&v51[48];
  v13 = fsqrt((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v12 * v12));
  if ( (v13 <= 30.0 || flMotionBlurGlobalStrength < 0.5 || HIBYTE(nDummy) != 0)
    && (flMotionBlurGlobalStrength <= 0.06666667 || HIBYTE(nDummy) != 0) )
  {
    if ( v13 <= 50.0 || HIBYTE(nDummy) != 0 )
    {
      m_flAspectRatio = view->m_flAspectRatio;
      fov = view->fov;
      flCurrentYaw = fov;
      if ( m_flAspectRatio > 0.0 )
        fov = fov / m_flAspectRatio;
      *(float *)&nSrcHeight = fov;
      flTimeElapsed = (float)((float)(*(float *)&v51[8] * v10) + (float)(*(float *)&v50 * v12))
                    + (float)(*(float *)&v51[24] * v11);
      if ( mat_motion_blur_forward_enabled.m_pParent != nullptr
        && mat_motion_blur_forward_enabled.m_pParent->m_Value.m_nValue != 0 )
      {
        g_vMotionBlurValues[2] = (float)((float)(*(float *)&v51[8] * v10) + (float)(*(float *)&v50 * v12))
                               + (float)(*(float *)&v51[24] * v11);
      }
      else
      {
        g_vMotionBlurValues[2] = fabs(*(float *)&v51[24])
                               * (float)((float)((float)(*(float *)&v51[8] * v10) + (float)(*(float *)&v50 * v12))
                                       + (float)(*(float *)&v51[24] * v11));
      }
      v16 = (float)((float)(*(float *)&v51[12] * v10) + (float)(*((float *)&v50 + 1) * v12))
          + (float)(*(float *)&v51[28] * v11);
      v17 = *(float *)&dword_10656360 - *(float *)&flMotionBlurFallingMax;
      *(float *)&flCurrentPitch = *(float *)&dword_10656360 - *(float *)&flMotionBlurFallingMax;
      if ( ((float)(*(float *)&dword_10656360 - *(float *)&flMotionBlurFallingMax) > 180.0 || v17 < -180.0)
        && (float)(*(float *)&dword_10656360 + *(float *)&flMotionBlurFallingMax) > -180.0
        && (float)(*(float *)&dword_10656360 + *(float *)&flMotionBlurFallingMax) < 180.0 )
      {
        v17 = *(float *)&dword_10656360 + *(float *)&flMotionBlurFallingMax;
        *(float *)&flCurrentPitch = *(float *)&dword_10656360 + *(float *)&flMotionBlurFallingMax;
      }
      *(float *)&nViewportHeight = (float)(v16 * 0.33333334) + v17;
      *(float *)&nSrcWidth = 0.0;
      if ( v17 >= 0.0 )
      {
        p_flCurrentPitch = &flCurrentPitch;
        p_nSrcWidth = &nSrcWidth;
      }
      else
      {
        p_flCurrentPitch = &nSrcWidth;
        p_nSrcWidth = &flCurrentPitch;
      }
      *(float *)&nViewportHeight = clamp<float,float,float>(
                                     val: (const float *)&nViewportHeight,
                                     minVal: (const float *)p_nSrcWidth,
                                     maxVal: (const float *)p_flCurrentPitch);
      nSrcWidth = LODWORD(flHorizontalFov) & _mask__AbsFloat_;
      *(float *)&v51[40] = *(float *)&nViewportHeight / flCurrentYaw;
      g_vMotionBlurValues[0] = (float)(1.0
                                     - (float)(COERCE_FLOAT(LODWORD(flHorizontalFov) & _mask__AbsFloat_) * 0.011111111))
                             * (float)(*(float *)&nViewportHeight / flCurrentYaw);
      v20 = *(float *)&dword_1065635C - flHorizontalFov;
      *(float *)&flCurrentPitch = *(float *)&dword_1065635C - flHorizontalFov;
      v21 = (float)(flTimeElapsed * 0.5)
          * (float)(1.0
                  - (float)((float)(1.0 - COERCE_FLOAT(*(_DWORD *)&v51[24] & _mask__AbsFloat_))
                          * (float)(1.0 - COERCE_FLOAT(*(_DWORD *)&v51[24] & _mask__AbsFloat_))));
      if ( flHorizontalFov <= 0.0 )
        *(float *)&nViewportHeight = v21 + v20;
      else
        *(float *)&nViewportHeight = v20 - v21;
      flCurrentYaw = 0.0;
      if ( v20 >= 0.0 )
      {
        v22 = (const float *)&flCurrentPitch;
        p_flCurrentYaw = &flCurrentYaw;
      }
      else
      {
        v22 = &flCurrentYaw;
        p_flCurrentYaw = (const float *)&flCurrentPitch;
      }
      *(float *)&nViewportHeight = clamp<float,float,float>(
                                     val: (const float *)&nViewportHeight,
                                     minVal: p_flCurrentYaw,
                                     maxVal: v22);
      if ( flMotionBlurGlobalStrength <= 0.0 )
        v24 = 0.0;
      else
        v24 = g_vMotionBlurValues[2] / (float)(flMotionBlurGlobalStrength * 30.0);
      v25 = (float)(COERCE_FLOAT(LODWORD(v24) & _mask__AbsFloat_) - vCurrentPosition.z)
          / (float)(*(float *)&y - vCurrentPosition.z);
      if ( v24 < 0.0 )
        v26 = -1.0;
      else
        v26 = 1.0;
      if ( v25 >= 0.0 )
      {
        if ( v25 > 1.0 )
          v25 = 1.0;
      }
      else
      {
        v25 = 0.0;
      }
      g_vMotionBlurValues[1] = (float)(*(float *)&h * *(float *)&pMatMotionBlur)
                             * (float)(*(float *)&nViewportHeight / *(float *)&nSrcHeight);
      g_vMotionBlurValues[0] = (float)(*(float *)&h * *(float *)&pMatMotionBlur) * g_vMotionBlurValues[0];
      g_vMotionBlurValues[2] = (float)(*(float *)&h * m_fValue) * (float)((float)(v26 * v25) * 0.033333335);
      g_vMotionBlurValues[3] = (float)(*(float *)&h * 0.30000001)
                             * (float)((float)((float)((float)(*(float *)&nSrcWidth * 0.011111111)
                                                     * (float)(*(float *)&nSrcWidth * 0.011111111))
                                             * (float)(*(float *)&nSrcWidth * 0.011111111))
                                     * *(float *)&v51[40]);
      if ( HIBYTE(nDummy) != 0 )
        goto LABEL_88;
      if ( flMotionBlurGlobalStrength <= 0.0 )
        v27 = 0.0;
      else
        v27 = 1.0 / flMotionBlurGlobalStrength;
      m_fValue = 1.0;
      *(float *)&pMatMotionBlur = 0.0;
      *(float *)&h = (float)(v27 - 30.0) * 0.050000001;
      v28 = clamp<float,float,float>(val: (const float *)&h, minVal: (const float *)&pMatMotionBlur, maxVal: &m_fValue);
      g_vMotionBlurValues[0] = g_vMotionBlurValues[0] * v28;
      g_vMotionBlurValues[1] = g_vMotionBlurValues[1] * v28;
      g_vMotionBlurValues[2] = g_vMotionBlurValues[2] * v28;
      g_vMotionBlurValues[3] = v28 * g_vMotionBlurValues[3];
    }
    else
    {
      *(float *)&dword_106563A0 = *(float *)gpGlobals.m_Index + 1.0;
    }
  }
  else
  {
    g_vMotionBlurValues[0] = 0.0;
    g_vMotionBlurValues[1] = 0.0;
    g_vMotionBlurValues[2] = 0.0;
    g_vMotionBlurValues[3] = 0.0;
  }
  if ( *(float *)&dword_106563A0 <= *(float *)gpGlobals.m_Index )
  {
LABEL_88:
    dword_106563A0 = 0;
    goto LABEL_89;
  }
  g_vMotionBlurValues[0] = 0.0;
  g_vMotionBlurValues[1] = 0.0;
  g_vMotionBlurValues[3] = 0.0;
LABEL_89:
  if ( engine->IsSplitScreenActive(this: engine) )
  {
    g_vMotionBlurValues[0] = g_vMotionBlurValues[0] * 0.25;
    g_vMotionBlurValues[1] = g_vMotionBlurValues[1] * 0.25;
    g_vMotionBlurValues[2] = 0.0;
    g_vMotionBlurValues[3] = 0.0;
  }
  *(_DWORD *)byte_10656364 = *(_DWORD *)&v51[48];
  *(_DWORD *)&byte_10656364[4] = *(_DWORD *)&v51[52];
  *(_DWORD *)&byte_10656364[8] = x;
  *(_QWORD *)&matrix.m_flMatVal[0][0] = v50;
  qmemcpy(&matrix.m_flMatVal[0][2], v51, 40);
  dword_1065635C = LODWORD(flHorizontalFov);
  nDummy = 0;
  dword_10656360 = flMotionBlurFallingMax;
  s_History[0].m_flLastTimeUpdate = *(float *)gpGlobals.m_Index;
  v29 = materials->FindTexture(this: materials, a2: "_rt_FullFrameFB", a3: "RenderTargets", a4: 1, a5: 0);
  v30 = (float)v29->GetActualWidth(this: v29);
  GetActualHeight = v29->GetActualHeight;
  m_fValue = v30;
  v32 = (float)GetActualHeight(this: v29);
  v33 = (float)(v3 + (v3 > 0)) / (float)(m_fValue - 1.0);
  g_vMotionBlurViewportValues[0] = v33;
  *(float *)&y = (float)v3;
  if ( (float)(m_fValue - 1.0) <= (float)v3 )
    v34 = 0;
  else
    v34 = -1;
  v35 = (float)(v3 + LODWORD(vCurrentPosition.y) + v34) / (float)(m_fValue - 1.0);
  v36 = v32 - 1.0;
  g_vMotionBlurViewportValues[3] = v35;
  v37 = (float)(LODWORD(vCurrentPosition.x) + (SLODWORD(vCurrentPosition.x) > 0)) / v36;
  g_vMotionBlurViewportValues[1] = v37;
  *(float *)&h = (float)SLODWORD(vCurrentPosition.x);
  if ( v36 <= (float)SLODWORD(vCurrentPosition.x) )
    v38 = 0;
  else
    v38 = -1;
  v39 = (float)(LODWORD(vCurrentPosition.x) + w + v38) / v36;
  g_vMotionBlurViewportValues[2] = v39;
  if ( v33 > 0.0 )
  {
    if ( v33 >= 1.0 )
      g_vMotionBlurViewportValues[0] = 2.0;
  }
  else
  {
    g_vMotionBlurViewportValues[0] = -1.0;
  }
  if ( v37 > 0.0 )
  {
    if ( v37 >= 1.0 )
      g_vMotionBlurViewportValues[1] = 2.0;
  }
  else
  {
    g_vMotionBlurViewportValues[1] = -1.0;
  }
  if ( v39 > 0.0 )
  {
    if ( v39 >= 1.0 )
      g_vMotionBlurViewportValues[2] = 2.0;
  }
  else
  {
    g_vMotionBlurViewportValues[2] = -1.0;
  }
  if ( v35 > 0.0 )
  {
    if ( v35 >= 1.0 )
      g_vMotionBlurViewportValues[3] = 2.0;
  }
  else
  {
    g_vMotionBlurViewportValues[3] = -1.0;
  }
  GetRenderContext = materials->GetRenderContext;
  HIBYTE(nDummy) = 0;
  v41 = (int)GetRenderContext(this: materials);
  if ( v41 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v41 + 8))(a1: v41);
  FindTexture = materials->FindTexture;
  nDummy = 0;
  v43 = ((int (__thiscall *)(IMaterialSystem *, const char *, const char *, int))FindTexture)(
          a1: materials,
          a2: "_rt_FullFrameFB",
          a3: "RenderTargets",
          a4: 1);
  *(float *)&nSrcHeight = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v43 + 12))(a1: v43));
  v44 = (*(int (__thiscall **)(int))(*(_DWORD *)v43 + 16))(a1: v43);
  *(float *)&nViewportHeight = COERCE_FLOAT(&flTimeElapsed);
  *(float *)&flCurrentPitch = COERCE_FLOAT(&flCurrentPitch);
  v45 = (IMaterial *)v44;
  v46 = *(void (__thiscall **)(int, float *))(*(_DWORD *)v41 + 156);
  m_fValue = COERCE_FLOAT(&m_fValue);
  pMatMotionBlur = v45;
  v46(a1: v41, a2: &m_fValue);
  UpdateScreenEffectTexture(
    textureIndex: 0,
    x: *(int *)&v51[44],
    y: SLODWORD(vCurrentPosition.x),
    w: SLODWORD(vCurrentPosition.y),
    h: w,
    bDestFullScreen: false,
    pActualRect: nullptr);
  LODWORD(vCurrentPosition.z) = materials->FindMaterial(
                                  this: materials,
                                  a2: "dev/motion_blur",
                                  a3: "Other textures",
                                  a4: 1,
                                  a5: 0);
  if ( LODWORD(vCurrentPosition.z) != 0 && nSrcHeight > 0 && (int)v45 > 0 )
  {
    ClientWorldEntity = GetClientWorldEntity();
    v48 = *(_DWORD *)v41;
    *(float *)&nViewportHeight = COERCE_FLOAT(
                                   ((int (__thiscall *)(C_World *, int, int))ClientWorldEntity->GetClientRenderable)(
                                     a1: ClientWorldEntity,
                                     a2: 1,
                                     a3: 1));
    flCurrentPitch = (int)pMatMotionBlur;
    m_fValue = *(float *)&nSrcHeight;
    flTimeElapsed = (float)(w + LODWORD(vCurrentPosition.x) - 1);
    flHorizontalFov = (float)(LODWORD(vCurrentPosition.y) + *(_DWORD *)&v51[44] - 1);
    nSrcWidth = h;
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, IMaterial *, float, int, int, float, float, int, IMaterial *, int))(v48 + 420))(
      a1: v41,
      a2: LODWORD(vCurrentPosition.z),
      a3: 0,
      a4: 0,
      a5: pMatMotionBlur,
      a6: COERCE_FLOAT(LODWORD(flTimeElapsed)),
      a7: y,
      a8: h,
      a9: COERCE_FLOAT(LODWORD(flHorizontalFov)),
      a10: COERCE_FLOAT(LODWORD(flTimeElapsed)),
      a11: nSrcHeight,
      a12: pMatMotionBlur,
      a13: nViewportHeight);
    HIBYTE(nDummy) = 1;
    if ( s_bDumpRenderTargets )
      DumpTGAofRenderTarget(
        a1: (int)&v71,
        a2: v41,
        a3: v48,
        width: flCurrentPitch,
        height: SLODWORD(flTimeElapsed),
        pFilename: "MotionBlur");
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v41 + 12))(a1: v41);
  (*(void (__thiscall **)(int))(*(_DWORD *)v41 + 4))(a1: v41);
  return HIBYTE(nDummy);
}

//------------------------------------------------------------------------------
// Address: 0x10199C10
// Name: void DoDepthOfField(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall DoDepthOfField(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CViewSetup *view)
{
  const CViewSetup *v4; // edi
  int v5; // eax
  IMatRenderContext *v6; // ebx
  int v7; // esi
  int v8; // eax
  int v9; // edx
  ITexture *v10; // esi
  IMaterial *v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  float v15; // xmm1_4
  ITexture *v16; // eax
  IMatRenderContext v17; // edi
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  IMaterial *v22; // eax
  IMaterial *v23; // esi
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // edx
  int v25; // eax
  IMaterialVar *(__thiscall *v26)(IMaterial *, const char *, bool *, bool); // edx
  int v27; // eax
  float m_fValue; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  int m_nValue; // eax
  C_World *ClientWorldEntity; // eax
  IMatRenderContext v36; // edi
  void (__thiscall *DrawScreenSpaceRectangle)(IMatRenderContext *, IMaterial *, int, int, int, int, float, float, float, float, int, int, void *, int, int); // eax
  IMaterial *pMat; // [esp+E8h] [ebp-1Ch]
  IMaterial *pMata; // [esp+E8h] [ebp-1Ch]
  IMaterial *pMatb; // [esp+E8h] [ebp-1Ch]
  int nViewportWidth; // [esp+ECh] [ebp-18h] BYREF
  int nViewportHeight; // [esp+F0h] [ebp-14h] BYREF
  int nDummy; // [esp+F4h] [ebp-10h] BYREF
  int nSrcWidth; // [esp+F8h] [ebp-Ch]
  int nSrcHeight; // [esp+FCh] [ebp-8h]
  int v47; // [esp+100h] [ebp-4h] BYREF
  int savedregs; // [esp+104h] [ebp+0h]

  if ( IsDepthOfFieldEnabled() )
  {
    v4 = view;
    UpdateScreenEffectTexture(
      textureIndex: 0,
      x: view->x,
      y: view->y,
      w: view->width,
      h: view->height,
      bDestFullScreen: false,
      pActualRect: nullptr);
    v5 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2, a3: a1);
    v6 = (IMatRenderContext *)v5;
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    v7 = ((int (__thiscall *)(IMaterialSystem *, const char *, const char *, int, _DWORD, int))materials->FindTexture)(
           a1: materials,
           a2: "_rt_FullFrameFB",
           a3: "RenderTargets",
           a4: 1,
           a5: 0,
           a6: a3);
    *(float *)&v8 = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7));
    v9 = *(_DWORD *)v7;
    nSrcWidth = v8;
    nSrcHeight = (*(int (__thiscall **)(int))(v9 + 16))(a1: v7);
    if ( mat_dof_quality.m_pParent == nullptr || mat_dof_quality.m_pParent->m_Value.m_nValue < 2 )
    {
      v6->PushRenderTargetAndViewport_4(this: v6);
      v10 = materials->FindTexture(this: materials, a2: "_rt_SmallFB0", a3: "RenderTargets", a4: 1, a5: 0);
      DownsampleFBQuarterSize(
        a1: (int)v6,
        a2: (int)view,
        a3: (int)v10,
        pRenderContext: v6,
        nSrcWidth,
        nSrcHeight,
        pDest: v10,
        bFloatHDR: 1);
      v11 = materials->FindMaterial(this: materials, a2: "dev/blurgaussian_3x3", a3: "Other textures", a4: 1, a5: 0);
      pMat = v11;
      if ( v11 == nullptr )
      {
        v6->EndRender(this: v6);
        v6->Release(this: v6);
        return;
      }
      v12 = v10->GetActualWidth(this: v10);
      SetMaterialVarFloat(pMat: v11, pVarName: "$c0_x", a3: (int)v10, flValue: 0.5 / (float)v12);
      v13 = v10->GetActualHeight(this: v10);
      SetMaterialVarFloat(pMat: v11, pVarName: "$c0_y", a3: (int)v10, flValue: 0.5 / (float)v13);
      v14 = v10->GetActualWidth(this: v10);
      SetMaterialVarFloat(pMat: v11, pVarName: "$c1_x", a3: (int)v10, flValue: -0.5 / (float)v14);
      v15 = (float)v10->GetActualHeight(this: v10);
      SetMaterialVarFloat(pMat: v11, pVarName: "$c1_y", a3: (int)v10, flValue: 0.5 / v15);
      v16 = materials->FindTexture(this: materials, a2: "_rt_SmallFB1", a3: "RenderTargets", a4: 1, a5: 0);
      SetRenderTargetAndViewPort(rt: v16);
      v17.__vftable = v6->__vftable;
      v18 = ((int (__thiscall *)(ITexture *, _DWORD, int, int))v10->GetActualHeight)(a1: v10, a2: 0, a3: 1, a4: 1);
      v19 = ((int (__thiscall *)(ITexture *, int))v10->GetActualWidth)(a1: v10, a2: v18);
      v20 = ((int (__thiscall *)(ITexture *, int))v10->GetActualHeight)(a1: v10, a2: v19);
      v21 = ((int (__thiscall *)(ITexture *, float))v10->GetActualWidth)(a1: v10, a2: (float)(v20 - 1));
      ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, _DWORD, int, int, _DWORD, _DWORD, float))v17.DrawScreenSpaceRectangle)(
        a1: v6,
        a2: pMat,
        a3: 0,
        a4: 0,
        a5: nSrcWidth / 4,
        a6: nSrcHeight / 4,
        a7: 0,
        a8: 0,
        a9: (float)(v21 - 1));
      v6->PopRenderTargetAndViewport(this: v6);
      v4 = view;
    }
    nViewportWidth = 0;
    nViewportHeight = 0;
    *(float *)&nDummy = 0.0;
    ((void (__thiscall *)(IMatRenderContext *, int *))v6->GetViewport)(a1: v6, a2: &nDummy);
    v22 = materials->FindMaterial(this: materials, a2: "dev/depth_of_field", a3: "Other textures", a4: 1, a5: 0);
    v23 = v22;
    if ( v22 != nullptr )
    {
      FindVar = v22->FindVar;
      pMata = (IMaterial *)LODWORD(v4->zNear);
      HIBYTE(v47) = 0;
      v25 = ((int (__thiscall *)(IMaterial *, const char *, char *, int, int *, int *, int *))FindVar)(
              a1: v22,
              a2: "$nearPlane",
              a3: (char *)&v47 + 3,
              a4: 1,
              a5: &nDummy,
              a6: &nViewportWidth,
              a7: &nViewportHeight);
      if ( HIBYTE(v47) != 0 )
        (*(void (__thiscall **)(int, IMaterial *))(*(_DWORD *)v25 + 16))(a1: v25, a2: pMata);
      v26 = v23->FindVar;
      pMatb = (IMaterial *)LODWORD(v4->zFar);
      HIBYTE(v47) = 0;
      v27 = (int)v26(this: v23, a2: "$farPlane", a3: (bool *)&v47 + 3, a4: true);
      if ( HIBYTE(v47) != 0 )
        (*(void (__thiscall **)(int, IMaterial *))(*(_DWORD *)v27 + 16))(a1: v27, a2: pMatb);
      if ( (*((_BYTE *)v4 + 240) & 8) != 0 )
      {
        SetMaterialVarFloat(pMat: v23, pVarName: "$nearBlurDepth", a3: (int)v23, flValue: v4->m_flNearBlurDepth);
        SetMaterialVarFloat(pMat: v23, pVarName: "$nearFocusDepth", a3: (int)v23, flValue: v4->m_flNearFocusDepth);
        SetMaterialVarFloat(pMat: v23, pVarName: "$farFocusDepth", a3: (int)v23, flValue: v4->m_flFarFocusDepth);
        SetMaterialVarFloat(pMat: v23, pVarName: "$farBlurDepth", a3: (int)v23, flValue: v4->m_flFarBlurDepth);
        SetMaterialVarFloat(pMat: v23, pVarName: "$nearBlurRadius", a3: (int)v23, flValue: v4->m_flNearBlurRadius);
        SetMaterialVarFloat(pMat: v23, pVarName: "$farBlurRadius", a3: (int)v23, flValue: v4->m_flFarBlurRadius);
        SetMaterialVarInt(pMat: v23, pVarName: "$quality", a3: (int)v23, nValue: v4->m_nDoFQuality);
      }
      else
      {
        if ( mat_dof_override.m_pParent != nullptr && mat_dof_override.m_pParent->m_Value.m_nValue != 0 )
          m_fValue = mat_dof_near_blur_depth.m_pParent->m_Value.m_fValue;
        else
          m_fValue = g_flDOFNearBlurDepth;
        SetMaterialVarFloat(pMat: v23, pVarName: "$nearBlurDepth", a3: (int)v23, flValue: m_fValue);
        if ( mat_dof_override.m_pParent != nullptr && mat_dof_override.m_pParent->m_Value.m_nValue != 0 )
          v29 = mat_dof_near_focus_depth.m_pParent->m_Value.m_fValue;
        else
          v29 = g_flDOFNearFocusDepth;
        SetMaterialVarFloat(pMat: v23, pVarName: "$nearFocusDepth", a3: (int)v23, flValue: v29);
        if ( mat_dof_override.m_pParent != nullptr && mat_dof_override.m_pParent->m_Value.m_nValue != 0 )
          v30 = mat_dof_far_focus_depth.m_pParent->m_Value.m_fValue;
        else
          v30 = g_flDOFFarFocusDepth;
        SetMaterialVarFloat(pMat: v23, pVarName: "$farFocusDepth", a3: (int)v23, flValue: v30);
        if ( mat_dof_override.m_pParent != nullptr && mat_dof_override.m_pParent->m_Value.m_nValue != 0 )
          v31 = mat_dof_far_blur_depth.m_pParent->m_Value.m_fValue;
        else
          v31 = g_flDOFFarBlurDepth;
        SetMaterialVarFloat(pMat: v23, pVarName: "$farBlurDepth", a3: (int)v23, flValue: v31);
        if ( mat_dof_override.m_pParent != nullptr && mat_dof_override.m_pParent->m_Value.m_nValue != 0 )
          v32 = mat_dof_near_blur_radius.m_pParent->m_Value.m_fValue;
        else
          v32 = g_flDOFNearBlurRadius;
        SetMaterialVarFloat(pMat: v23, pVarName: "$nearBlurRadius", a3: (int)v23, flValue: v32);
        if ( mat_dof_override.m_pParent != nullptr && mat_dof_override.m_pParent->m_Value.m_nValue != 0 )
          v33 = mat_dof_far_blur_radius.m_pParent->m_Value.m_fValue;
        else
          v33 = g_flDOFFarBlurRadius;
        SetMaterialVarFloat(pMat: v23, pVarName: "$farBlurRadius", a3: (int)v23, flValue: v33);
        if ( mat_dof_quality.m_pParent != nullptr )
          m_nValue = mat_dof_quality.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        SetMaterialVarInt(pMat: v23, pVarName: "$quality", a3: (int)v23, nValue: m_nValue);
      }
      ClientWorldEntity = GetClientWorldEntity();
      v36.__vftable = v6->__vftable;
      savedregs = ((int (__thiscall *)(C_World *, int, int))ClientWorldEntity->GetClientRenderable)(
                    a1: ClientWorldEntity,
                    a2: 1,
                    a3: 1);
      v47 = nSrcHeight;
      nSrcHeight = nSrcWidth;
      *(float *)&nSrcWidth = (float)(v47 - 1);
      DrawScreenSpaceRectangle = v36.DrawScreenSpaceRectangle;
      *(float *)&nDummy = (float)(nSrcHeight - 1);
      nViewportHeight = 0;
      nViewportWidth = 0;
      ((void (__thiscall *)(IMatRenderContext *))DrawScreenSpaceRectangle)(a1: v6);
    }
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A230
// Name: public: void ICallQueue::QueueCall<bool,int,int,int,int,bool,bool,int,int,int,int,bool,bool>(bool (*)(int,int,int,int,bool,bool),int const __near &,int const __near &,int const __near &,int const __near &,bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<bool,int,int,int,int,bool,bool,int,int,int,int,bool,bool>(
        ICallQueue *this,
        bool (__cdecl *pfnProxied)(int, int, int, int, bool, bool),
        unsigned int *arg1,
        CFunctor_vtbl **arg2,
        unsigned int *arg3,
        CFunctor_vtbl **arg4,
        const bool *arg5,
        const bool *arg6)
{
  CFunctor *v9; // eax

  v9 = (CFunctor *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v9 != nullptr )
  {
    v9[1].m_nUserID = 1;
    v9[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v9->__vftable = (CFunctor_vtbl *)&CFunctor6<bool (__cdecl *)(int,int,int,int,bool,bool),int,int,int,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v9[1].__vftable = (CFunctor_vtbl *)&CFunctor6<bool (__cdecl *)(int,int,int,int,bool,bool),int,int,int,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v9[2].m_nUserID = *arg1;
    v9[3].__vftable = *arg2;
    v9[3].m_nUserID = *arg3;
    v9[4].__vftable = *arg4;
    LOBYTE(v9[4].m_nUserID) = *arg5;
    BYTE1(v9[4].m_nUserID) = *arg6;
    this->QueueFunctorInternal(this, a2: v9);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A2B0
// Name: bool DoEnginePostProcessing(int,int,int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall DoEnginePostProcessing@<al>(
        int a1@<esi>,
        int x,
        int y,
        int w,
        int h,
        bool bFlashlightIsOn,
        bool bPostVGui)
{
  int v7; // edi
  int v8; // ebx
  IMatRenderContext *v9; // esi
  ICallQueue *v10; // eax
  CTonemapSystem *CurrentTonemappingSystem; // eax
  float v13; // xmm0_4
  bool v14; // zf
  bool (__thiscall *IsSplitScreenActive)(IVEngineClient *); // edx
  IMaterial *(__thiscall *FindMaterial)(IMaterialSystem *, const char *, const char *, bool, const char *); // edx
  IMaterial *v17; // eax
  int v18; // eax
  ITexture *(__thiscall *FindTexture)(IMaterialSystem *, const char *, const char *, bool, int); // eax
  int v20; // edi
  int v21; // ebx
  float v22; // eax
  IMaterialSystem_vtbl *v23; // edx
  int v24; // esi
  float v25; // xmm0_4
  int v26; // eax
  int v27; // edi
  float v28; // xmm3_4
  int v29; // ebx
  float v30; // xmm2_4
  C_World *ClientWorldEntity; // eax
  int m_nValue; // ecx
  IMatRenderContext_vtbl *v33; // edi
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int height; // esi
  IMatRenderContext *m_pObject; // ebx
  CTonemapSystem *v39; // eax
  Vector4D v4dFullViewportPostDestRect; // [esp+7Ch] [ebp-60h] BYREF
  Rect_t partialViewportPostDestRect; // [esp+8Ch] [ebp-50h]
  Vector4D fullViewportPostSrcRect; // [esp+9Ch] [ebp-40h] BYREF
  float flBloomScale; // [esp+ACh] [ebp-30h]
  float v45; // [esp+B0h] [ebp-2Ch]
  float flFbWidth; // [esp+B4h] [ebp-28h]
  BOOL bPerformSoftwareAA; // [esp+B8h] [ebp-24h] BYREF
  float flAAStrength; // [esp+BCh] [ebp-20h] BYREF
  Vector2D destTexSize; // [esp+C0h] [ebp-1Ch] BYREF
  IMaterial *pPostMat; // [esp+C8h] [ebp-14h]
  BOOL bPerformBloom; // [esp+CCh] [ebp-10h]
  BOOL bPerformColCorrect; // [esp+D0h] [ebp-Ch]
  CMatRenderContextPtr pRenderContext; // [esp+D4h] [ebp-8h] BYREF
  bool bPerformedPostProcessPass; // [esp+DAh] [ebp-2h]
  bool bPerformLocalContrastEnhancement; // [esp+DBh] [ebp-1h]

  if ( s_bOverridePostProcessingDisable )
    return false;
  v7 = w;
  if ( w <= 0 )
    return false;
  v8 = h;
  if ( h <= 0 )
    return false;
  if ( s_bDumpRenderTargets )
    s_bDumpRenderTargets = false;
  if ( mat_dump_rts.m_pParent != nullptr && mat_dump_rts.m_pParent->m_Value.m_nValue != 0 )
  {
    s_bDumpRenderTargets = true;
    s_nRTIndex = 0;
    ConVar::SetValue(this: (ConVar *)&mat_dump_rts.IConVar, value: 0);
  }
  v9 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v9;
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  if ( r_queued_post_processing.m_pParent != nullptr && r_queued_post_processing.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = v9->GetCallQueue(this: v9);
    if ( v10 != nullptr )
    {
      ICallQueue::QueueCall<bool,int,int,int,int,bool,bool,int,int,int,int,bool,bool>(
        this: v10,
        pfnProxied: DoEnginePostProcessing,
        arg1: &x,
        arg2: &y,
        arg3: &w,
        arg4: &h,
        arg5: &bFlashlightIsOn,
        arg6: &bPostVGui);
      CMatRenderContextPtr::~CMatRenderContextPtr(this: &pRenderContext);
      return false;
    }
  }
  GetTonemapSettingsFromEnvTonemapController();
  g_bFlashlightIsOn = bFlashlightIsOn;
  GetExposureRange(pflAutoExposureMin: &flAAStrength, pflAutoExposureMax: (float *)&bPerformSoftwareAA);
  if ( mat_debug_bloom.m_pParent != nullptr && mat_debug_bloom.m_pParent->m_Value.m_nValue == 1 )
  {
    DrawBloomDebugBoxes(pRenderContext: v9, nX: x, nY: y, nWidth: v7, nHeight: v8);
    v7 = w;
  }
  s_bScreenEffectTextureIsUpdated = false;
  DoTonemapping(
    nY: y,
    pRenderContext: v9,
    nX: x,
    nWidth: v7,
    nHeight: v8,
    flAutoExposureMin: flAAStrength,
    flAutoExposureMax: *(float *)&bPerformSoftwareAA);
  if ( mat_postprocess_enable.m_pParent == nullptr || mat_postprocess_enable.m_pParent->m_Value.m_nValue == 0 )
  {
    CurrentTonemappingSystem = GetCurrentTonemappingSystem();
    CTonemapSystem::DisplayHistogram(this: CurrentTonemappingSystem);
    CMatRenderContextPtr::~CMatRenderContextPtr(this: &pRenderContext);
    return false;
  }
  if ( mat_software_aa_strength.m_pParent->m_Value.m_fValue == -1.0 )
    ConVar::SetValue(this: (ConVar *)&mat_software_aa_strength.IConVar, value: 0.0);
  if ( mat_software_aa_strength_vgui.m_pParent->m_Value.m_fValue == -1.0 )
    ConVar::SetValue(this: (ConVar *)&mat_software_aa_strength_vgui.IConVar, value: 1.0);
  flAAStrength = mat_software_aa_strength.m_pParent->m_Value.m_fValue;
  v13 = flAAStrength;
  GetBloomAmount();
  flBloomScale = v13;
  LOBYTE(bPerformSoftwareAA) = flAAStrength != 0.0;
  if ( bPostVGui || v13 <= 0.0 )
  {
    LOBYTE(bPerformBloom) = 0;
    if ( bPostVGui )
    {
LABEL_32:
      LOBYTE(bPerformColCorrect) = 0;
      goto LABEL_33;
    }
  }
  else
  {
    LOBYTE(bPerformBloom) = 1;
  }
  if ( !CColorCorrectionMgr::HasNonZeroColorCorrectionWeights(this: g_pColorCorrectionMgr) )
    goto LABEL_32;
  if ( mat_colorcorrection.m_pParent == nullptr )
    goto LABEL_32;
  v14 = mat_colorcorrection.m_pParent->m_Value.m_nValue == 0;
  LOBYTE(bPerformColCorrect) = 1;
  if ( v14 )
    goto LABEL_32;
LABEL_33:
  ((void (__thiscall *)(IMatRenderContext *, BOOL, int))v9->EnableColorCorrection)(
    a1: v9,
    a2: bPerformColCorrect,
    a3: a1);
  IsSplitScreenActive = engine->IsSplitScreenActive;
  bPerformLocalContrastEnhancement = false;
  v4dFullViewportPostDestRect.x = 0.0;
  v14 = !IsSplitScreenActive(this: engine);
  FindMaterial = materials->FindMaterial;
  if ( v14 )
    v17 = (IMaterial *)((int (__stdcall *)(const char *))FindMaterial)(a1: "dev/engine_post");
  else
    v17 = (IMaterial *)((int (__stdcall *)(const char *))FindMaterial)(a1: "dev/engine_post_splitscreen");
  pPostMat = v17;
  if ( v17 != nullptr )
  {
    v18 = (int)v17->FindVar(this: v17, a2: "$localcontrastenable", a3: nullptr, a4: false);
    if ( v18 != 0 )
    {
      if ( (*(int (__thiscall **)(int, const char *, int, _DWORD))(*(_DWORD *)v18 + 108))(
             a1: v18,
             a2: "Other textures",
             a3: 1,
             a4: LODWORD(v4dFullViewportPostDestRect.x)) == 0
        || mat_local_contrast_enable.m_pParent == nullptr
        || (v14 = mat_local_contrast_enable.m_pParent->m_Value.m_nValue == 0,
            bPerformLocalContrastEnhancement = true,
            v14) )
      {
        bPerformLocalContrastEnhancement = false;
      }
    }
  }
  FindTexture = materials->FindTexture;
  bPerformedPostProcessPass = false;
  v20 = ((int (__thiscall *)(IMaterialSystem *, const char *, const char *, int))FindTexture)(
          a1: materials,
          a2: "_rt_FullFrameFB",
          a3: "RenderTargets",
          a4: 1);
  v21 = (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 12))(a1: v20);
  v22 = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v20 + 16))(a1: v20));
  v23 = materials->__vftable;
  destTexSize.y = v22;
  v24 = (int)v23->FindTexture(this: materials, a2: "_rt_SmallFB1", a3: "RenderTargets", a4: true, a5: 0);
  if ( !s_bScreenEffectTextureIsUpdated )
  {
    UpdateScreenEffectTexture(textureIndex: 0, x, y, w, h, bDestFullScreen: false, pActualRect: nullptr);
    s_bScreenEffectTextureIsUpdated = true;
  }
  if ( s_bDumpRenderTargets )
    DumpTGAofRenderTarget(
      a1: v21,
      a2: v20,
      a3: v24,
      width: v21,
      height: SLODWORD(destTexSize.y),
      pFilename: "FullFrameFB");
  if ( bPerformBloom || bPerformLocalContrastEnhancement )
    Generate8BitBloomTexture(pRenderContext: pRenderContext.m_pObject, x: 1, y: 0);
  v25 = (float)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 12))(a1: v20);
  v26 = (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 16))(a1: v20);
  v27 = w + x;
  flFbWidth = (float)x;
  v28 = (float)v21;
  fullViewportPostSrcRect.x = (float)((float)((float)x * (float)(1.0 / v25)) * (float)v21) * 0.25;
  v29 = h + y;
  v45 = (float)y;
  v30 = 1.0 / (float)v26;
  fullViewportPostSrcRect.y = (float)((float)((float)((float)y * v30) * (float)SLODWORD(destTexSize.y)) * 0.25) - 0.5;
  fullViewportPostSrcRect.z = (float)((float)((float)((float)(w + x) * (float)(1.0 / v25)) * v28) * 0.25) - 1.0;
  fullViewportPostSrcRect.w = (float)((float)((float)((float)(h + y) * v30) * (float)SLODWORD(destTexSize.y)) * 0.25)
                            - 1.0;
  *(_QWORD *)&v4dFullViewportPostDestRect.x = __PAIR64__(y, x);
  *(_QWORD *)&v4dFullViewportPostDestRect.z = __PAIR64__(h, w);
  *(_QWORD *)&partialViewportPostDestRect.x = __PAIR64__(y, x);
  destTexSize.x = v28;
  destTexSize.y = (float)SLODWORD(destTexSize.y);
  *(_QWORD *)&partialViewportPostDestRect.width = __PAIR64__(h, w);
  if ( debug_postproc.m_pParent != nullptr && debug_postproc.m_pParent->m_Value.m_nValue == 2 )
  {
    partialViewportPostDestRect.width = (int)(float)((float)w - (float)((float)w * 0.5));
    partialViewportPostDestRect.height = (int)(float)((float)partialViewportPostDestRect.height - (float)((float)h * 0.5));
  }
  if ( bFirstFrame && bPerformColCorrect )
  {
    LOBYTE(m_pObject) = bPerformedPostProcessPass;
  }
  else
  {
    if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, _DWORD))g_pMaterialSystemHardwareConfig->GetHDRType)(
           a1: g_pMaterialSystemHardwareConfig,
           a2: 0) == 2 )
    {
      pRenderContext.m_pObject->SetIntRenderingParameter(this: pRenderContext.m_pObject, a2: 11, a3: 0);
      pRenderContext.m_pObject->SetRenderTarget(this: pRenderContext.m_pObject, a2: nullptr);
    }
    v4dFullViewportPostDestRect.x = flFbWidth;
    v4dFullViewportPostDestRect.y = v45;
    v4dFullViewportPostDestRect.z = (float)(v27 - 1);
    v4dFullViewportPostDestRect.w = (float)(v29 - 1);
    CEnginePostMaterialProxy::SetupEnginePostMaterial(
      fullViewportBloomUVs: &fullViewportPostSrcRect,
      fullViewportFBUVs: &v4dFullViewportPostDestRect,
      &destTexSize,
      bPerformSoftwareAA,
      bPerformBloom,
      bPerformColCorrect,
      flAAStrength,
      flBloomAmount: flBloomScale);
    ClientWorldEntity = GetClientWorldEntity();
    if ( mat_postprocess_x.m_pParent != nullptr )
      m_nValue = mat_postprocess_x.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    m_pObject = pRenderContext.m_pObject;
    v33 = pRenderContext.m_pObject->__vftable;
    v34 = ((int (__thiscall *)(C_World *, int))ClientWorldEntity->GetClientRenderable)(
            a1: ClientWorldEntity,
            a2: m_nValue);
    v35 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v24 + 16))(a1: v24, a2: v34);
    v36 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v24 + 12))(a1: v24, a2: v35);
    height = partialViewportPostDestRect.height;
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int))v33->DrawScreenSpaceRectangle)(
      a1: m_pObject,
      a2: pPostMat,
      a3: 0,
      a4: 0,
      a5: partialViewportPostDestRect.width,
      a6: partialViewportPostDestRect.height,
      a7: LODWORD(fullViewportPostSrcRect.x),
      a8: LODWORD(fullViewportPostSrcRect.y),
      a9: LODWORD(fullViewportPostSrcRect.z),
      a10: LODWORD(fullViewportPostSrcRect.w),
      a11: v36);
    LOBYTE(m_pObject) = 1;
    if ( s_bDumpRenderTargets )
      DumpTGAofRenderTarget(
        a1: (int)m_pObject,
        a2: (int)v33,
        a3: height,
        width: partialViewportPostDestRect.width,
        height,
        pFilename: "EnginePost");
  }
  bFirstFrame = false;
  v39 = GetCurrentTonemappingSystem();
  CTonemapSystem::DisplayHistogram(this: v39);
  CMatRenderContextPtr::~CMatRenderContextPtr(this: &pRenderContext);
  return (char)m_pObject;
}

//------------------------------------------------------------------------------
// Address: 0x10370D70
// Name: public: virtual void CFunctor6<void (*)(class Vector const __near &,float,int,int,class Color,bool),class Vector,float,int,int,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, _DWORD, int, int, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: LODWORD(this->m_arg2),
    a3: this->m_arg3,
    a4: this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x10370DB0
// Name: public: virtual void CFunctor6<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool),class Vector,class QAngle,class Vector,class Vector,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6);
}
