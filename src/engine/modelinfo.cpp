// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/modelinfo.cpp
// Functions: 56
// ============================================================

#include "engine\modelinfo.h"

//------------------------------------------------------------------------------
// Address: 0x101A56B0
// Name: ModelFrameCount
// Source: json
//------------------------------------------------------------------------------
int __fastcall ModelFrameCount(int a1, model_t *model)
{
  int result; // eax
  modtype_t type; // ecx
  _DWORD *v4; // eax
  char *v5; // edx
  int v6; // eax
  int v7; // ecx
  _DWORD *v8; // edx

  result = 1;
  if ( model != nullptr )
  {
    type = model->type;
    if ( type == mod_sprite )
    {
      return model->sprite.numframes;
    }
    else if ( type == mod_studio )
    {
      v4 = modelloader->GetExtraData(this: modelloader, a2: model);
      if ( v4 == nullptr )
        return 1;
      v5 = (char *)v4 + v4[59];
      v6 = v4[58];
      v7 = 1;
      if ( v6 > 0 )
      {
        v8 = v5 + 4;
        do
        {
          v7 *= *v8;
          v8 += 4;
          --v6;
        }
        while ( v6 != 0 );
      }
      result = v7;
      if ( v7 < 1 )
        return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5720
// Name: public: virtual struct model_t const __near * CModelInfo::FindOrLoadModel(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const model_t *__thiscall CModelInfo::FindOrLoadModel(CModelInfo *this, const char *name)
{
  CModelInfo_vtbl *v3; // edi
  int v4; // eax
  const model_t *result; // eax

  v3 = this->__vftable;
  v4 = this->GetModelIndex(this, a2: name);
  result = v3->GetModel(this, a2: v4);
  if ( result == nullptr )
    return modelloader->GetModelForName(this: modelloader, a2: name, a3: FMODELLOADER_CLIENTDLL);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5760
// Name: public: virtual char const __near * CModelInfo::GetModelName(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CModelInfo::GetModelName(CModelInfo *this, const model_t *pModel)
{
  if ( pModel != nullptr )
    return modelloader->GetName(this: modelloader, a2: pModel);
  else
    return "?";
}

//------------------------------------------------------------------------------
// Address: 0x101A5790
// Name: public: virtual void CModelInfo::GetModelBounds(struct model_t const __near *,class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetModelBounds(CModelInfo *this, const model_t *model, Vector *mins, Vector *maxs)
{
  *mins = model->mins;
  *maxs = model->maxs;
}

//------------------------------------------------------------------------------
// Address: 0x101A57E0
// Name: public: virtual void CModelInfo::GetModelRenderBounds(struct model_t const __near *,class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetModelRenderBounds(CModelInfo *this, const model_t *model, Vector *mins, Vector *maxs)
{
  char *v4; // esi
  float v5; // xmm0_4

  if ( model == nullptr )
    goto LABEL_4;
  if ( model->type == mod_brush )
  {
    *mins = model->mins;
    *maxs = model->maxs;
  }
  else
  {
    if ( model->type != mod_studio )
    {
LABEL_4:
      mins->x = 0.0;
      mins->y = 0.0;
      mins->z = 0.0;
      maxs->x = 0.0;
      maxs->y = 0.0;
      maxs->z = 0.0;
      return;
    }
    v4 = (char *)modelloader->GetExtraData(this: modelloader, a2: model);
    v5 = *((float *)v4 + 32);
    if ( v5 == vec3_origin.x
      && *((float *)v4 + 33) == vec3_origin.y
      && *((float *)v4 + 34) == vec3_origin.z
      && VectorCompare(v1: &vec3_origin, v2: (const Vector *)(v4 + 140)) != 0 )
    {
      *mins = *(Vector *)(v4 + 104);
      *maxs = *(Vector *)(v4 + 116);
    }
    else
    {
      mins->x = v5;
      mins->y = *((float *)v4 + 33);
      mins->z = *((float *)v4 + 34);
      *maxs = *(Vector *)(v4 + 140);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A5940
// Name: public: virtual int CModelInfo::GetModelSpriteWidth(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetModelSpriteWidth(CModelInfo *this, const model_t *model)
{
  if ( model->type == mod_sprite )
    return model->brush.firstmodelsurface;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5960
// Name: public: virtual int CModelInfo::GetModelSpriteHeight(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetModelSpriteHeight(CModelInfo *this, const model_t *model)
{
  if ( model->type == mod_sprite )
    return model->brush.nummodelsurfaces;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5980
// Name: public: virtual int CModelInfo::GetModelFrameCount(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetModelFrameCount(CModelInfo *this, model_t *model)
{
  return ModelFrameCount(model);
}

//------------------------------------------------------------------------------
// Address: 0x101A5990
// Name: public: virtual int CModelInfo::GetModelType(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
modtype_t __thiscall CModelInfo::GetModelType(CModelInfo *this, const model_t *model)
{
  if ( model != nullptr )
    return model->type;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101A59B0
// Name: public: virtual void __near * CModelInfo::GetModelExtraData(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CModelInfo::GetModelExtraData(CModelInfo *this, model_t *model)
{
  return modelloader->GetExtraData(this: modelloader, a2: model);
}

//------------------------------------------------------------------------------
// Address: 0x101A59D0
// Name: public: virtual struct studiohdr_t const __near * CModelInfo::FindModel(struct studiohdr_t const __near *,void __near * __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall CModelInfo::FindModel(
        CModelInfo *this,
        const studiohdr_t *pStudioHdr,
        model_t **cache,
        const char *modelname)
{
  model_t *v4; // eax

  v4 = *cache;
  if ( *cache == nullptr )
  {
    v4 = modelloader->GetModelForName(this: modelloader, a2: modelname, a3: 2);
    *cache = v4;
  }
  return (const studiohdr_t *)modelloader->GetExtraData(this: modelloader, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101A5A10
// Name: public: virtual struct studiohdr_t const __near * CModelInfo::FindModel(void __near *)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall CModelInfo::FindModel(CModelInfo *this, void *cache)
{
  return g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: (unsigned __int16)cache);
}

//------------------------------------------------------------------------------
// Address: 0x101A5A30
// Name: public: virtual struct virtualmodel_t __near * CModelInfo::GetVirtualModel(struct studiohdr_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall CModelInfo::GetVirtualModel(CModelInfo *this, const studiohdr_t *pStudioHdr)
{
  return g_pMDLCache->GetVirtualModelFast(
           this: g_pMDLCache,
           a2: pStudioHdr,
           a3: (unsigned __int16)pStudioHdr->virtualModel);
}

//------------------------------------------------------------------------------
// Address: 0x101A5A60
// Name: public: virtual unsigned char __near * CModelInfo::GetAnimBlock(struct studiohdr_t const __near *,int,bool)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CModelInfo::GetAnimBlock(
        CModelInfo *this,
        const studiohdr_t *pStudioHdr,
        int nBlock,
        BOOL bPreloadIfMissing)
{
  return g_pMDLCache->GetAnimBlock(
           this: g_pMDLCache,
           a2: (unsigned __int16)pStudioHdr->virtualModel,
           a3: nBlock,
           a4: bPreloadIfMissing);
}

//------------------------------------------------------------------------------
// Address: 0x101A5A90
// Name: public: virtual bool CModelInfo::HasAnimBlockBeenPreloaded(struct studiohdr_t const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelInfo::HasAnimBlockBeenPreloaded(CModelInfo *this, const studiohdr_t *pStudioHdr, int nBlock)
{
  return g_pMDLCache->HasAnimBlockBeenPreloaded(
           this: g_pMDLCache,
           a2: (unsigned __int16)pStudioHdr->virtualModel,
           a3: nBlock);
}

//------------------------------------------------------------------------------
// Address: 0x101A5AC0
// Name: public: virtual int CModelInfo::GetAutoplayList(struct studiohdr_t const __near *,unsigned short __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetAutoplayList(
        CModelInfo *this,
        const studiohdr_t *pStudioHdr,
        unsigned __int16 **pAutoplayList)
{
  return g_pMDLCache->GetAutoplayList(
           this: g_pMDLCache,
           a2: (unsigned __int16)pStudioHdr->virtualModel,
           a3: pAutoplayList);
}

//------------------------------------------------------------------------------
// Address: 0x101A5AF0
// Name: public: virtual bool CModelInfo::ModelHasMaterialProxy(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModelInfo::ModelHasMaterialProxy(CModelInfo *this, const model_t *model)
{
  return model != nullptr && (model->flags & 1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5B20
// Name: public: virtual bool CModelInfo::IsTranslucent(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModelInfo::IsTranslucent(CModelInfo *this, const model_t *model)
{
  return model != nullptr && (model->flags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5B50
// Name: public: virtual bool CModelInfo::IsModelVertexLit(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModelInfo::IsModelVertexLit(CModelInfo *this, const model_t *model)
{
  return model != nullptr && (model->flags & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5B80
// Name: public: virtual bool CModelInfo::UsesEnvCubemap(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModelInfo::UsesEnvCubemap(CModelInfo *this, const model_t *model)
{
  return model != nullptr && (model->flags & 0x400) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5BB0
// Name: public: virtual bool CModelInfo::UsesStaticLighting(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelInfo::UsesStaticLighting(CModelInfo *this, const model_t *model)
{
  int m_nValue; // eax

  if ( model == nullptr || model->type != mod_studio || (model->flags & 0x2000) == 0 )
    return false;
  if ( r_staticlight_streams.m_pParent != nullptr )
    m_nValue = r_staticlight_streams.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  return (model->flags & 0x200) == 0 || m_nValue > 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A5C10
// Name: public: virtual bool CModelInfo::IsTranslucentTwoPass(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModelInfo::IsTranslucentTwoPass(CModelInfo *this, const model_t *model)
{
  return model != nullptr && (model->flags & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5C40
// Name: public: virtual enum RenderableTranslucencyType_t CModelInfo::ComputeTranslucencyType(struct model_t const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
RenderableTranslucencyType_t __thiscall CModelInfo::ComputeTranslucencyType(
        CModelInfo *this,
        model_t *model,
        int nSkin,
        int nBody)
{
  if ( model != nullptr )
    return Mod_ComputeTranslucencyType(mod: model, nSkin, nBody);
  else
    return RENDERABLE_IS_OPAQUE;
}

//------------------------------------------------------------------------------
// Address: 0x101A5C70
// Name: public: virtual int CModelInfo::GetModelMaterialCount(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelInfo::GetModelMaterialCount(CModelInfo *this, model_t *model)
{
  model_t *result; // eax

  result = model;
  if ( model != nullptr )
    return (model_t *)Mod_GetMaterialCount(mod: model);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5C90
// Name: public: virtual void CModelInfo::GetModelMaterials(struct model_t const __near *,int,class IMaterial __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetModelMaterials(CModelInfo *this, model_t *model, int count, IMaterial **ppMaterials)
{
  if ( model != nullptr )
    Mod_GetModelMaterials(pModel: model, count, ppMaterials);
}

//------------------------------------------------------------------------------
// Address: 0x101A5CB0
// Name: public: virtual void CModelInfo::GetIlluminationPoint(struct model_t const __near *,class IClientRenderable __near *,class Vector const __near &,class QAngle const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetIlluminationPoint(
        CModelInfo *this,
        const model_t *model,
        IClientRenderable *pRenderable,
        const Vector *origin,
        const QAngle *angles,
        Vector *pLightingOrigin)
{
  studiohdr_t *v6; // esi
  matrix3x4_t matrix; // [esp+4h] [ebp-30h] BYREF

  v6 = (studiohdr_t *)this->GetModelExtraData(this, a2: model);
  if ( v6 != nullptr )
  {
    AngleMatrix(angles, position: origin, &matrix);
    R_ComputeLightingOrigin(pRenderable, pStudioHdr: v6, &matrix, center: pLightingOrigin);
  }
  else
  {
    *pLightingOrigin = *origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A5D20
// Name: public: virtual int CModelInfo::GetModelContents(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetModelContents(CModelInfo *this, int modelIndex)
{
  const model_t *v2; // eax
  int v3; // eax

  v2 = this->GetModel(this, a2: modelIndex);
  if ( v2 != nullptr )
  {
    v3 = v2->type - 1;
    if ( v3 == 0 )
      return CM_InlineModelContents(index: modelIndex - 1);
    if ( v3 == 2 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5D70
// Name: public: virtual struct vcollide_t __near * CModelInfo::GetVCollide(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__thiscall CModelInfo::GetVCollide(CModelInfo *this, const model_t *pModel)
{
  int v3; // esi
  CStatTime *v4; // ecx
  double v5; // st7
  CModelInfo_vtbl *v7; // edi
  const char *v8; // eax
  int v9; // eax
  double t1; // [esp+8h] [ebp-8h]

  if ( pModel == nullptr )
    return nullptr;
  if ( pModel->type == mod_studio )
  {
    t1 = _Plat_FloatTime((CStatTime *)this);
    v3 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: pModel->studio);
    v5 = _Plat_FloatTime(this: v4);
    g_flAccumulatedModelLoadTimeVCollideSync = v5 - t1 + g_flAccumulatedModelLoadTimeVCollideSync;
    return (vcollide_t *)v3;
  }
  v7 = this->__vftable;
  v8 = this->GetModelName(this, a2: pModel);
  v9 = v7->GetModelIndex(this, a2: v8);
  if ( v9 >= 0 )
    return this->GetVCollide(this, a2: v9);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A5E00
// Name: public: virtual struct vcollide_t __near * CModelInfo::GetVCollide(int)const
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__thiscall CModelInfo::GetVCollide(CModelInfo *this, int modelIndex)
{
  const model_t *v2; // eax
  CStatTime *v3; // ecx
  const model_t *v4; // esi
  int v5; // eax
  int v6; // esi
  CStatTime *v7; // ecx
  double v8; // st7
  double t1; // [esp+8h] [ebp-8h]

  if ( modelIndex < 1024 )
  {
    v2 = this->GetModel(this, a2: modelIndex);
    v4 = v2;
    if ( v2 == nullptr )
      return CM_GetVCollide(modelIndex: modelIndex - 1);
    v5 = v2->type - 1;
    if ( v5 == 0 )
      return CM_GetVCollide(modelIndex: modelIndex - 1);
    if ( v5 == 2 )
    {
      t1 = _Plat_FloatTime(this: v3);
      v6 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: v4->studio);
      v8 = _Plat_FloatTime(this: v7);
      g_flAccumulatedModelLoadTimeVCollideSync = v8 - t1 + g_flAccumulatedModelLoadTimeVCollideSync;
      return (vcollide_t *)v6;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A5E90
// Name: public: virtual char const __near * CModelInfo::GetModelKeyValueText(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CModelInfo::GetModelKeyValueText(CModelInfo *this, const model_t *model)
{
  int v2; // eax

  if ( model == nullptr )
    return nullptr;
  if ( model->type != mod_studio )
    return nullptr;
  v2 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->studio);
  if ( v2 == 0 )
    return nullptr;
  if ( *(_DWORD *)(v2 + 316) != 0 )
    return (const char *)(v2 + *(_DWORD *)(v2 + 312));
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A5EF0
// Name: public: virtual float CModelInfo::GetModelRadius(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CModelInfo::GetModelRadius(CModelInfo *this, const model_t *model)
{
  if ( model != nullptr )
    return model->radius;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5F10
// Name: public: virtual struct studiohdr_t __near * CModelInfo::GetStudiomodel(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CModelInfo::GetStudiomodel(CModelInfo *this, const model_t *model)
{
  if ( model->type == mod_studio )
    return ((studiohdr_t *(__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->studio);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A5F40
// Name: public: virtual class CPhysCollide __near * CModelInfo::GetCollideForVirtualTerrain(int)
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__thiscall CModelInfo::GetCollideForVirtualTerrain(CModelInfo *this, int index)
{
  return CM_PhysCollideForDisp(index);
}

//------------------------------------------------------------------------------
// Address: 0x101A5F60
// Name: public: virtual int CModelInfo::GetBrushModelPlaneCount(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetBrushModelPlaneCount(CModelInfo *this, const model_t *model)
{
  if ( model != nullptr && model->type == mod_brush )
    return R_GetBrushModelPlaneCount(model);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5F90
// Name: public: virtual struct model_t const __near * CModelInfoServer::GetModel(int)const
// Source: json
//------------------------------------------------------------------------------
const model_t *__userpurge CModelInfoServer::GetModel@<eax>(CModelInfoServer *this@<ecx>, int a2@<ebx>, int modelindex)
{
  return CGameServer::GetModel(this: &sv, a2, index: modelindex);
}

//------------------------------------------------------------------------------
// Address: 0x101A5FA0
// Name: public: virtual int CModelInfoServer::GetModelIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfoServer::GetModelIndex(CModelInfoServer *this, const char *name)
{
  return CGameServer::LookupModelIndex(this: &sv, name);
}

//------------------------------------------------------------------------------
// Address: 0x101A5FB0
// Name: public: virtual void CModelInfoServer::GetModelMaterialColorAndLighting(struct model_t const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoServer::GetModelMaterialColorAndLighting(
        CModelInfoServer *this,
        const model_t *model,
        const model_t *origin,
        const Vector *angles,
        const QAngle *pTrace,
        CGameTrace *lighting,
        Vector *matColor)
{
  _Msg(a1: "GetModelMaterialColorAndLighting:  Available on client only!\n");
}

//------------------------------------------------------------------------------
// Address: 0x101A5FD0
// Name: public: virtual struct model_t const __near * CModelInfoClient::GetModel(int)const
// Source: json
//------------------------------------------------------------------------------
const model_t *__userpurge CModelInfoClient::GetModel@<eax>(
        CModelInfoClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int modelindex)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::GetModel(this: BaseLocalClient, a2, a3, index: modelindex);
}

//------------------------------------------------------------------------------
// Address: 0x101A5FF0
// Name: public: virtual int CModelInfoClient::GetModelIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfoClient::GetModelIndex(CModelInfoClient *this, const char *name)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::LookupModelIndex(this: BaseLocalClient, name);
}

//------------------------------------------------------------------------------
// Address: 0x101A6010
// Name: public: virtual void CModelInfoClient::SetLevelScreenFadeRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoClient::SetLevelScreenFadeRange(CModelInfoClient *this, float flMinSize, float flMaxSize)
{
  float m_flMaxScreenWidth; // xmm0_4

  this->m_LevelFade.m_flMinScreenWidth = flMinSize;
  this->m_LevelFade.m_flMaxScreenWidth = flMaxSize;
  if ( flMinSize >= flMaxSize )
    this->m_LevelFade.m_flMaxScreenWidth = flMinSize;
  m_flMaxScreenWidth = this->m_LevelFade.m_flMaxScreenWidth;
  if ( m_flMaxScreenWidth == flMinSize )
    this->m_LevelFade.m_flFalloffFactor = 255.0;
  else
    this->m_LevelFade.m_flFalloffFactor = 255.0 / (float)(m_flMaxScreenWidth - flMinSize);
}

//------------------------------------------------------------------------------
// Address: 0x101A6070
// Name: public: virtual void CModelInfoClient::GetLevelScreenFadeRange(float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoClient::GetLevelScreenFadeRange(CModelInfoClient *this, float *pMinArea, float *pMaxArea)
{
  *pMinArea = this->m_LevelFade.m_flMinScreenWidth;
  *pMaxArea = this->m_LevelFade.m_flMaxScreenWidth;
}

//------------------------------------------------------------------------------
// Address: 0x101A6090
// Name: public: virtual void CModelInfoClient::SetViewScreenFadeRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoClient::SetViewScreenFadeRange(CModelInfoClient *this, float flMinSize, float flMaxSize)
{
  float m_flMaxScreenWidth; // xmm0_4

  this->m_ViewFade.m_flMinScreenWidth = flMinSize;
  this->m_ViewFade.m_flMaxScreenWidth = flMaxSize;
  if ( flMinSize >= flMaxSize )
    this->m_ViewFade.m_flMaxScreenWidth = flMinSize;
  m_flMaxScreenWidth = this->m_ViewFade.m_flMaxScreenWidth;
  if ( m_flMaxScreenWidth == flMinSize )
    this->m_ViewFade.m_flFalloffFactor = 255.0;
  else
    this->m_ViewFade.m_flFalloffFactor = 255.0 / (float)(m_flMaxScreenWidth - flMinSize);
}

//------------------------------------------------------------------------------
// Address: 0x101A60F0
// Name: class IMaterial __near * BrushModel_GetLightingAndMaterial(class Vector const __near &,class Vector const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl BrushModel_GetLightingAndMaterial(
        const Vector *start,
        const Vector *end,
        Vector *diffuseLightColor,
        Vector *baseColor)
{
  msurface2_t *v4; // eax
  mtexinfo_t *v5; // eax
  IMaterial *material; // esi
  int v8; // [esp+10h] [ebp-8h] BYREF
  int v9; // [esp+14h] [ebp-4h] BYREF
  int _18; // [esp+18h] [ebp+0h] BYREF

  v8 = 0;
  v9 = 0;
  v4 = R_LightVec(
         a1: (int)&_18,
         start,
         end,
         bUseLightStyles: true,
         c: diffuseLightColor,
         textureS: (float *)&v8,
         textureT: (float *)&v9,
         lightmapS: nullptr,
         lightmapT: nullptr);
  if ( v4 == nullptr )
    return nullptr;
  v5 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)v4 + 11) >> 1];
  if ( v5 == nullptr )
    return nullptr;
  material = v5->material;
  ((void (__thiscall *)(IMaterial *, int, int, Vector *))material->GetLowResColorSample)(
    a1: material,
    a2: v8,
    a3: v9,
    a4: baseColor);
  return material;
}

//------------------------------------------------------------------------------
// Address: 0x101A6180
// Name: public: virtual void CModelInfoClient::GetModelMaterialColorAndLighting(struct model_t const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoClient::GetModelMaterialColorAndLighting(
        CModelInfoClient *this,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        CGameTrace *pTrace,
        Vector *lighting,
        Vector *matColor)
{
  model_t *v7; // esi
  Vector *v8; // eax
  CGameTrace *v9; // ebx
  int v10; // edi
  Vector *p_endpos; // ebx
  int v12; // esi
  LightDesc_t *v13; // ebx
  float y; // xmm4_4
  float z; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm5_4
  bool v21; // zf
  LightDesc_t desc[4]; // [esp+4h] [ebp-204h] BYREF
  LightingState_t lightingState; // [esp+164h] [ebp-A4h] BYREF
  Vector up; // [esp+1C0h] [ebp-48h] BYREF
  Vector forward; // [esp+1CCh] [ebp-3Ch] BYREF
  Vector end_l; // [esp+1D8h] [ebp-30h] BYREF
  Vector right; // [esp+1E4h] [ebp-24h] BYREF
  Vector delta; // [esp+1F0h] [ebp-18h]
  Vector origin_l; // [esp+1FCh] [ebp-Ch] BYREF

  v7 = model;
  if ( model->type == mod_brush )
  {
    y = pTrace->startpos.y;
    z = pTrace->startpos.z;
    v16 = pTrace->endpos.x - pTrace->startpos.x;
    v17 = pTrace->endpos.y - y;
    v18 = y - origin->y;
    v19 = pTrace->endpos.z - z;
    v20 = z - origin->z;
    origin_l.x = pTrace->startpos.x - origin->x;
    origin_l.y = v18;
    v21 = angles->x == 0.0;
    delta.x = v16;
    delta.y = v17;
    delta.z = v19;
    origin_l.z = v20;
    if ( !v21 || angles->y != 0.0 || angles->z != 0.0 )
    {
      AngleVectors(angles, &forward, &right, &up);
      v16 = (float)((float)(forward.y * delta.y) + (float)(forward.x * delta.x)) + (float)(forward.z * delta.z);
      LODWORD(v17) = COERCE_UNSIGNED_INT((float)((float)(right.y * delta.y) + (float)(right.x * delta.x)) + (float)(right.z * delta.z))
                   ^ _mask__NegFloat_;
      v19 = (float)((float)(up.y * delta.y) + (float)(up.x * delta.x)) + (float)(up.z * delta.z);
    }
    end_l.x = (float)(v16 * 1.1) + origin_l.x;
    end_l.y = (float)(v17 * 1.1) + origin_l.y;
    end_l.z = (float)(v19 * 1.1) + origin_l.z;
    R_LightVecUseModel(pModel: v7);
    BrushModel_GetLightingAndMaterial(start: &origin_l, end: &end_l, diffuseLightColor: lighting, baseColor: matColor);
    R_LightVecUseModel(pModel: nullptr);
  }
  else if ( model->type == mod_studio )
  {
    v8 = matColor;
    v9 = pTrace;
    v10 = 0;
    matColor->x = 0.5;
    v8->y = 0.5;
    v8->z = 0.5;
    p_endpos = &v9->endpos;
    memset(&lightingState, 0, 76);
    matColor = p_endpos;
    LightcacheGetDynamic(
      origin: p_endpos,
      &lightingState,
      stats: (LightcacheGetDynamic_Stats *)&model,
      pRenderable: nullptr,
      flags: 0xFu,
      bDebugModel: false);
    v12 = 0;
    if ( lightingState.numlights > 0 )
    {
      v13 = desc;
      do
      {
        if ( WorldLightToMaterialLight(pWorldLight: lightingState.locallight[v12], light: v13) )
        {
          ++v10;
          ++v13;
        }
        ++v12;
      }
      while ( v12 < lightingState.numlights );
      p_endpos = matColor;
    }
    g_pStudioRender->ComputeLighting(
      this: g_pStudioRender,
      a2: (const Vector *)&lightingState,
      a3: v10,
      a4: desc,
      a5: p_endpos,
      a6: (const Vector *)&pTrace->plane,
      a7: lighting);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6460
// Name: public: virtual class KeyValues __near * CModelInfo::GetModelKeyValues(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__userpurge CModelInfo::GetModelKeyValues@<eax>(CModelInfo *this@<ecx>, int a2@<ebx>, const model_t *pModel)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  const char *v8; // eax
  KeyValues *result; // eax
  IBaseFileSystem *pKeyValueText; // [esp+10h] [ebp+8h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_ModelKeyValueMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_ModelKeyValueMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_ModelKeyValueMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_ModelKeyValueMutex.m_depth;
  }
  if ( pModel->m_pKeyValues == nullptr )
  {
    pKeyValueText = (IBaseFileSystem *)((int (__thiscall *)(CModelInfo *, const model_t *, int))this->GetModelKeyValueText)(
                                         a1: this,
                                         a2: pModel,
                                         a3: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: defaultValue);
    else
      v7 = nullptr;
    v8 = (const char *)((int (__thiscall *)(CModelInfo *))this->GetModelName)(a1: this);
    if ( KeyValues::LoadFromBuffer(
           this: v7,
           resourceName: v8,
           pBuffer: (const char *)pModel,
           pFileSystem: pKeyValueText,
           pPathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      pModel->m_pKeyValues = v7;
    }
    else
    {
      KeyValues::deleteThis(this: v7);
    }
  }
  result = pModel->m_pKeyValues;
  if ( --g_ModelKeyValueMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_ModelKeyValueMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A6530
// Name: public: virtual void CModelInfo::GetBrushModelPlane(struct model_t const __near *,int,struct cplane_t __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetBrushModelPlane(
        CModelInfo *this,
        const model_t *model,
        int nIndex,
        cplane_t *plane,
        Vector *pOrigin)
{
  if ( model != nullptr && model->type == mod_brush )
    *plane = *R_GetBrushModelPlane(model, nIndex, pOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x101A6590
// Name: public: virtual bool CModelInfo::IsUsingFBTexture(struct model_t const __near *,int,int,void __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelInfo::IsUsingFBTexture(
        CModelInfo *this,
        const model_t *model,
        int nSkin,
        int nBody,
        void *pClientRenderable)
{
  int v5; // ebx
  int v6; // edi
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  int v10; // edi
  int v11; // ecx
  IMaterial *pMaterials[128]; // [esp+Ch] [ebp-200h] BYREF

  if ( model == nullptr || (model->flags & 0x100) == 0 )
    return 0;
  if ( model->type != mod_brush )
  {
    if ( model->type == mod_studio )
    {
      v5 = ((int (__stdcall *)(_DWORD, int, int, int, IMaterial **))g_pStudioRender->GetMaterialListFromBodyAndSkin)(
             a1: model->studio,
             a2: nSkin,
             a3: nBody,
             a4: 128,
             a5: pMaterials);
      v6 = 0;
      if ( v5 > 0 )
      {
        while ( 1 )
        {
          if ( pMaterials[v6] != nullptr )
          {
            v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
            v8 = v7;
            if ( v7 != nullptr )
              v7->BeginRender(this: v7);
            v8->Bind(this: v8, a2: pMaterials[v6], a3: pClientRenderable);
            if ( pMaterials[v6]->NeedsPowerOfTwoFrameBufferTexture(this: pMaterials[v6], a2: true) )
            {
              if ( v8 != nullptr )
              {
                v8->EndRender(this: v8);
                v8->Release(this: v8);
              }
              return 1;
            }
            v8->EndRender(this: v8);
            v8->Release(this: v8);
          }
          if ( ++v6 >= v5 )
            return 0;
        }
      }
    }
    return 0;
  }
  v10 = 0;
  if ( model->brush.nummodelsurfaces <= 0 )
    return 0;
  while ( 1 )
  {
    v11 = *(_DWORD *)(80
                    * (*(unsigned __int16 *)(32 * (v10 + model->brush.firstmodelsurface)
                                           + *(_DWORD *)(model->sprite.numframes + 124)
                                           + 22) >> 1)
                    + *(_DWORD *)(model->sprite.numframes + 96)
                    + 76);
    if ( v11 != 0 && (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v11 + 96))(a1: v11, a2: 1) != 0 )
      break;
    if ( ++v10 >= model->brush.nummodelsurfaces )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A6700
// Name: public: virtual bool CModelInfo::GetModelKeyValue(struct model_t const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelInfo::GetModelKeyValue(CModelInfo *this, const model_t *model, CUtlBuffer *buf)
{
  const studiohdr_t *v4; // eax
  virtualmodel_t *v6; // eax
  virtualmodel_t *v7; // esi
  int v8; // ebx
  int v9; // edi
  studiohdr_t *v10; // eax
  const char *v11; // eax

  if ( model == nullptr )
    return 0;
  if ( model->type != mod_studio )
    return 0;
  v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->studio);
  if ( v4 == nullptr )
    return 0;
  if ( v4->numincludemodels != 0 )
  {
    v6 = this->GetVirtualModel(this, a2: v4);
    v7 = v6;
    if ( v6 != nullptr )
    {
      v8 = 0;
      if ( v6->m_group.m_Size > 0 )
      {
        v9 = 0;
        do
        {
          v10 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: LOWORD(v7->m_group.m_Memory.m_pMemory[v9].cache));
          if ( v10 != nullptr && v10->keyvaluesize != 0 )
          {
            v11 = (char *)v10 + v10->keyvalueindex;
            if ( v11 != nullptr )
              CUtlBuffer::PutString(this: buf, pString: v11);
          }
          ++v8;
          ++v9;
        }
        while ( v8 < v7->m_group.m_Size );
      }
    }
    return 1;
  }
  else
  {
    if ( v4->keyvaluesize != 0 )
      CUtlBuffer::PutString(this: buf, pString: (const char *)v4 + v4->keyvalueindex);
    else
      CUtlBuffer::PutString(this: buf, pString: nullptr);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6800
// Name: public: virtual void CModelInfo::GetLevelScreenFadeRange(float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetLevelScreenFadeRange(CModelInfo *this, float *pMinArea, float *pMaxArea)
{
  *pMinArea = 0.0;
  *pMaxArea = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A6820
// Name: public: virtual int CModelInfo::GetSurfacepropsForVirtualTerrain(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetSurfacepropsForVirtualTerrain(CModelInfo *this, int index)
{
  return CM_SurfacepropsForDisp(index);
}

//------------------------------------------------------------------------------
// Address: 0x101A6840
// Name: public: virtual unsigned short CModelInfo::GetCacheHandle(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetCacheHandle(CModelInfo *this, const model_t *model)
{
  if ( model->type == mod_studio )
    return model->studio;
  else
    return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101A6870
// Name: private: unsigned char CModelInfoClient::ComputeScreenFade(class Vector const __near &,float,float,struct CModelInfoClient::ScreenFadeInfo_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge CModelInfoClient::ComputeScreenFade@<al>(
        CModelInfoClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const Vector *vecAbsOrigin,
        float flRadius,
        float flFadeScale,
        const CModelInfoClient::ScreenFadeInfo_t *fade)
{
  int v7; // esi
  char v8; // bl
  float m_flMaxScreenWidth; // xmm1_4
  int v10; // eax
  float v12; // [esp+18h] [ebp+10h]

  if ( fade->m_flMinScreenWidth <= 0.0 || flFadeScale <= 0.0 )
    return -1;
  v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
  if ( v7 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
  v8 = 0;
  v12 = ((double (__thiscall *)(int, const Vector *, _DWORD))*(_DWORD *)(*(_DWORD *)v7 + 312))(
          a1: v7,
          a2: vecAbsOrigin,
          a3: LODWORD(flRadius))
      / flFadeScale;
  if ( v12 > fade->m_flMinScreenWidth )
  {
    m_flMaxScreenWidth = fade->m_flMaxScreenWidth;
    if ( m_flMaxScreenWidth < 0.0 || m_flMaxScreenWidth <= v12 )
    {
      v8 = -1;
    }
    else
    {
      v10 = (int)(float)((float)(v12 - fade->m_flMinScreenWidth) * fade->m_flFalloffFactor);
      if ( v10 >= 0 )
      {
        if ( v10 > 255 )
          LOBYTE(v10) = -1;
        v8 = v10;
      }
      else
      {
        v8 = 0;
      }
    }
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101A6940
// Name: public: virtual unsigned char CModelInfoClient::ComputeLevelScreenFade(class Vector const __near &,float,float)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CModelInfoClient::ComputeLevelScreenFade(
        CModelInfoClient *this,
        const Vector *vecAbsOrigin,
        float flRadius,
        float flFadeScale)
{
  return CModelInfoClient::ComputeScreenFade(this, vecAbsOrigin, flRadius, flFadeScale, fade: &this->m_LevelFade);
}

//------------------------------------------------------------------------------
// Address: 0x101A6970
// Name: public: virtual unsigned char CModelInfoClient::ComputeViewScreenFade(class Vector const __near &,float,float)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CModelInfoClient::ComputeViewScreenFade(
        CModelInfoClient *this,
        const Vector *vecAbsOrigin,
        float flRadius,
        float flFadeScale)
{
  return CModelInfoClient::ComputeScreenFade(this, vecAbsOrigin, flRadius, flFadeScale, fade: &this->m_ViewFade);
}

//------------------------------------------------------------------------------
// Address: 0x101A5FC0
// Name: __CreateCModelInfoServerIVModelInfo_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CModelInfoServer *__cdecl _CreateCModelInfoServerIVModelInfo_interface()
{
  return &g_ModelInfoServer;
}

//------------------------------------------------------------------------------
// Address: 0x101A6450
// Name: __CreateCModelInfoClientIVModelInfoClient_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CModelInfoClient *__cdecl _CreateCModelInfoClientIVModelInfoClient_interface()
{
  return &g_ModelInfoClient;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101A5AA0
// Name: ModelFrameCount
// Source: json
//------------------------------------------------------------------------------
int __fastcall ModelFrameCount(int a1, model_t *model)
{
  int result; // eax
  modtype_t type; // ecx
  _DWORD *v4; // eax
  char *v5; // edx
  int v6; // eax
  int v7; // ecx
  _DWORD *v8; // edx

  result = 1;
  if ( model != nullptr )
  {
    type = model->type;
    if ( type == mod_sprite )
    {
      return model->sprite.numframes;
    }
    else if ( type == mod_studio )
    {
      v4 = modelloader->GetExtraData(this: modelloader, a2: model);
      if ( v4 == nullptr )
        return 1;
      v5 = (char *)v4 + v4[59];
      v6 = v4[58];
      v7 = 1;
      if ( v6 > 0 )
      {
        v8 = v5 + 4;
        do
        {
          v7 *= *v8;
          v8 += 4;
          --v6;
        }
        while ( v6 != 0 );
      }
      result = v7;
      if ( v7 < 1 )
        return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5B10
// Name: public: virtual struct model_t const __near * CModelInfo::FindOrLoadModel(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const model_t *__thiscall CModelInfo::FindOrLoadModel(CModelInfo *this, const char *name)
{
  CModelInfo_vtbl *v3; // edi
  int v4; // eax
  const model_t *result; // eax

  v3 = this->__vftable;
  v4 = this->GetModelIndex(this, a2: name);
  result = v3->GetModel(this, a2: v4);
  if ( result == nullptr )
    return modelloader->GetModelForName(this: modelloader, a2: name, a3: FMODELLOADER_CLIENTDLL);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5BD0
// Name: public: virtual void CModelInfo::GetModelRenderBounds(struct model_t const __near *,class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetModelRenderBounds(CModelInfo *this, const model_t *model, Vector *mins, Vector *maxs)
{
  char *v4; // esi
  float v5; // xmm0_4

  if ( model == nullptr )
    goto LABEL_4;
  if ( model->type == mod_brush )
  {
    *mins = model->mins;
    *maxs = model->maxs;
  }
  else
  {
    if ( model->type != mod_studio )
    {
LABEL_4:
      mins->x = 0.0;
      mins->y = 0.0;
      mins->z = 0.0;
      maxs->x = 0.0;
      maxs->y = 0.0;
      maxs->z = 0.0;
      return;
    }
    v4 = (char *)modelloader->GetExtraData(this: modelloader, a2: model);
    v5 = *((float *)v4 + 32);
    if ( v5 == vec3_origin.x
      && *((float *)v4 + 33) == vec3_origin.y
      && *((float *)v4 + 34) == vec3_origin.z
      && VectorCompare(v1: &vec3_origin, v2: (const Vector *)(v4 + 140)) != 0 )
    {
      *mins = *(Vector *)(v4 + 104);
      *maxs = *(Vector *)(v4 + 116);
    }
    else
    {
      mins->x = v5;
      mins->y = *((float *)v4 + 33);
      mins->z = *((float *)v4 + 34);
      *maxs = *(Vector *)(v4 + 140);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A5D30
// Name: public: virtual int CModelInfo::GetModelSpriteWidth(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetModelSpriteWidth(CModelInfo *this, const model_t *model)
{
  if ( model->type == mod_sprite )
    return model->brush.firstmodelsurface;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5D50
// Name: public: virtual int CModelInfo::GetModelSpriteHeight(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetModelSpriteHeight(CModelInfo *this, const model_t *model)
{
  if ( model->type == mod_sprite )
    return model->brush.nummodelsurfaces;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5D80
// Name: public: virtual int CModelInfo::GetModelType(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
modtype_t __thiscall CModelInfo::GetModelType(CModelInfo *this, const model_t *model)
{
  if ( model != nullptr )
    return model->type;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101A5DA0
// Name: public: virtual void __near * CModelInfo::GetModelExtraData(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CModelInfo::GetModelExtraData(CModelInfo *this, model_t *model)
{
  return modelloader->GetExtraData(this: modelloader, a2: model);
}

//------------------------------------------------------------------------------
// Address: 0x101A5DC0
// Name: public: virtual struct studiohdr_t const __near * CModelInfo::FindModel(struct studiohdr_t const __near *,void __near * __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const studiohdr_t *__thiscall CModelInfo::FindModel(
        CModelInfo *this,
        const studiohdr_t *pStudioHdr,
        model_t **cache,
        const char *modelname)
{
  model_t *v4; // eax

  v4 = *cache;
  if ( *cache == nullptr )
  {
    v4 = modelloader->GetModelForName(this: modelloader, a2: modelname, a3: 2);
    *cache = v4;
  }
  return (const studiohdr_t *)modelloader->GetExtraData(this: modelloader, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101A5E20
// Name: public: virtual struct virtualmodel_t __near * CModelInfo::GetVirtualModel(struct studiohdr_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
virtualmodel_t *__thiscall CModelInfo::GetVirtualModel(CModelInfo *this, const studiohdr_t *pStudioHdr)
{
  return g_pMDLCache->GetVirtualModelFast(
           this: g_pMDLCache,
           a2: pStudioHdr,
           a3: (unsigned __int16)pStudioHdr->virtualModel);
}

//------------------------------------------------------------------------------
// Address: 0x101A5E50
// Name: public: virtual unsigned char __near * CModelInfo::GetAnimBlock(struct studiohdr_t const __near *,int,bool)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CModelInfo::GetAnimBlock(
        CModelInfo *this,
        const studiohdr_t *pStudioHdr,
        int nBlock,
        BOOL bPreloadIfMissing)
{
  return g_pMDLCache->GetAnimBlock(
           this: g_pMDLCache,
           a2: (unsigned __int16)pStudioHdr->virtualModel,
           a3: nBlock,
           a4: bPreloadIfMissing);
}

//------------------------------------------------------------------------------
// Address: 0x101A5E80
// Name: public: virtual bool CModelInfo::HasAnimBlockBeenPreloaded(struct studiohdr_t const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelInfo::HasAnimBlockBeenPreloaded(CModelInfo *this, const studiohdr_t *pStudioHdr, int nBlock)
{
  return g_pMDLCache->HasAnimBlockBeenPreloaded(
           this: g_pMDLCache,
           a2: (unsigned __int16)pStudioHdr->virtualModel,
           a3: nBlock);
}

//------------------------------------------------------------------------------
// Address: 0x101A5EB0
// Name: public: virtual int CModelInfo::GetAutoplayList(struct studiohdr_t const __near *,unsigned short __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetAutoplayList(
        CModelInfo *this,
        const studiohdr_t *pStudioHdr,
        unsigned __int16 **pAutoplayList)
{
  return g_pMDLCache->GetAutoplayList(
           this: g_pMDLCache,
           a2: (unsigned __int16)pStudioHdr->virtualModel,
           a3: pAutoplayList);
}

//------------------------------------------------------------------------------
// Address: 0x101A5EE0
// Name: public: virtual bool CModelInfo::ModelHasMaterialProxy(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModelInfo::ModelHasMaterialProxy(CModelInfo *this, const model_t *model)
{
  return model != nullptr && (model->flags & 1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5F70
// Name: public: virtual bool CModelInfo::UsesEnvCubemap(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModelInfo::UsesEnvCubemap(CModelInfo *this, const model_t *model)
{
  return model != nullptr && (model->flags & 0x400) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A6000
// Name: public: virtual bool CModelInfo::IsTranslucentTwoPass(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModelInfo::IsTranslucentTwoPass(CModelInfo *this, const model_t *model)
{
  return model != nullptr && (model->flags & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A6030
// Name: public: virtual enum RenderableTranslucencyType_t CModelInfo::ComputeTranslucencyType(struct model_t const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
RenderableTranslucencyType_t __thiscall CModelInfo::ComputeTranslucencyType(
        CModelInfo *this,
        model_t *model,
        int nSkin,
        int nBody)
{
  if ( model != nullptr )
    return Mod_ComputeTranslucencyType(mod: model, nSkin, nBody);
  else
    return RENDERABLE_IS_OPAQUE;
}

//------------------------------------------------------------------------------
// Address: 0x101A6060
// Name: public: virtual int CModelInfo::GetModelMaterialCount(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelInfo::GetModelMaterialCount(CModelInfo *this, model_t *model)
{
  model_t *result; // eax

  result = model;
  if ( model != nullptr )
    return (model_t *)Mod_GetMaterialCount(mod: model);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A6080
// Name: public: virtual void CModelInfo::GetModelMaterials(struct model_t const __near *,int,class IMaterial __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetModelMaterials(CModelInfo *this, model_t *model, int count, IMaterial **ppMaterials)
{
  if ( model != nullptr )
    Mod_GetModelMaterials(pModel: model, count, ppMaterials);
}

//------------------------------------------------------------------------------
// Address: 0x101A60A0
// Name: public: virtual void CModelInfo::GetIlluminationPoint(struct model_t const __near *,class IClientRenderable __near *,class Vector const __near &,class QAngle const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetIlluminationPoint(
        CModelInfo *this,
        const model_t *model,
        IClientRenderable *pRenderable,
        const Vector *origin,
        const QAngle *angles,
        Vector *pLightingOrigin)
{
  studiohdr_t *v6; // esi
  matrix3x4_t matrix; // [esp+4h] [ebp-30h] BYREF

  v6 = (studiohdr_t *)this->GetModelExtraData(this, a2: model);
  if ( v6 != nullptr )
  {
    AngleMatrix(angles, position: origin, &matrix);
    R_ComputeLightingOrigin(pRenderable, pStudioHdr: v6, &matrix, center: pLightingOrigin);
  }
  else
  {
    *pLightingOrigin = *origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6110
// Name: public: virtual int CModelInfo::GetModelContents(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetModelContents(CModelInfo *this, int modelIndex)
{
  const model_t *v2; // eax
  int v3; // eax

  v2 = this->GetModel(this, a2: modelIndex);
  if ( v2 != nullptr )
  {
    v3 = v2->type - 1;
    if ( v3 == 0 )
      return CM_InlineModelContents(index: modelIndex - 1);
    if ( v3 == 2 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A6160
// Name: public: virtual struct vcollide_t __near * CModelInfo::GetVCollide(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__thiscall CModelInfo::GetVCollide(CModelInfo *this, const model_t *pModel)
{
  int v3; // esi
  CStatTime *v4; // ecx
  double v5; // st7
  CModelInfo_vtbl *v7; // edi
  const char *v8; // eax
  int v9; // eax
  double t1; // [esp+8h] [ebp-8h]

  if ( pModel == nullptr )
    return nullptr;
  if ( pModel->type == mod_studio )
  {
    t1 = _Plat_FloatTime((CStatTime *)this);
    v3 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: pModel->studio);
    v5 = _Plat_FloatTime(this: v4);
    g_flAccumulatedModelLoadTimeVCollideSync = v5 - t1 + g_flAccumulatedModelLoadTimeVCollideSync;
    return (vcollide_t *)v3;
  }
  v7 = this->__vftable;
  v8 = this->GetModelName(this, a2: pModel);
  v9 = v7->GetModelIndex(this, a2: v8);
  if ( v9 >= 0 )
    return this->GetVCollide(this, a2: v9);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A61F0
// Name: public: virtual struct vcollide_t __near * CModelInfo::GetVCollide(int)const
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__thiscall CModelInfo::GetVCollide(CModelInfo *this, int modelIndex)
{
  const model_t *v2; // eax
  CStatTime *v3; // ecx
  const model_t *v4; // esi
  int v5; // eax
  int v6; // esi
  CStatTime *v7; // ecx
  double v8; // st7
  double t1; // [esp+8h] [ebp-8h]

  if ( modelIndex < 1024 )
  {
    v2 = this->GetModel(this, a2: modelIndex);
    v4 = v2;
    if ( v2 == nullptr )
      return CM_GetVCollide(modelIndex: modelIndex - 1);
    v5 = v2->type - 1;
    if ( v5 == 0 )
      return CM_GetVCollide(modelIndex: modelIndex - 1);
    if ( v5 == 2 )
    {
      t1 = _Plat_FloatTime(this: v3);
      v6 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: v4->studio);
      v8 = _Plat_FloatTime(this: v7);
      g_flAccumulatedModelLoadTimeVCollideSync = v8 - t1 + g_flAccumulatedModelLoadTimeVCollideSync;
      return (vcollide_t *)v6;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A6280
// Name: public: virtual char const __near * CModelInfo::GetModelKeyValueText(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CModelInfo::GetModelKeyValueText(CModelInfo *this, const model_t *model)
{
  int v2; // eax

  if ( model == nullptr )
    return nullptr;
  if ( model->type != mod_studio )
    return nullptr;
  v2 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->studio);
  if ( v2 == 0 )
    return nullptr;
  if ( *(_DWORD *)(v2 + 316) != 0 )
    return (const char *)(v2 + *(_DWORD *)(v2 + 312));
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A62E0
// Name: public: virtual float CModelInfo::GetModelRadius(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CModelInfo::GetModelRadius(CModelInfo *this, const model_t *model)
{
  if ( model != nullptr )
    return model->radius;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A6300
// Name: public: virtual struct studiohdr_t __near * CModelInfo::GetStudiomodel(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
studiohdr_t *__thiscall CModelInfo::GetStudiomodel(CModelInfo *this, const model_t *model)
{
  if ( model->type == mod_studio )
    return ((studiohdr_t *(__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->studio);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A6330
// Name: public: virtual class CPhysCollide __near * CModelInfo::GetCollideForVirtualTerrain(int)
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__thiscall CModelInfo::GetCollideForVirtualTerrain(CModelInfo *this, int index)
{
  return CM_PhysCollideForDisp(index);
}

//------------------------------------------------------------------------------
// Address: 0x101A6350
// Name: public: virtual int CModelInfo::GetBrushModelPlaneCount(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetBrushModelPlaneCount(CModelInfo *this, const model_t *model)
{
  if ( model != nullptr && model->type == mod_brush )
    return R_GetBrushModelPlaneCount(model);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A6380
// Name: public: virtual struct model_t const __near * CModelInfoServer::GetModel(int)const
// Source: json
//------------------------------------------------------------------------------
const model_t *__thiscall CModelInfoServer::GetModel(CModelInfoServer *this, int modelindex)
{
  return CGameServer::GetModel(this: &sv, index: modelindex);
}

//------------------------------------------------------------------------------
// Address: 0x101A6390
// Name: public: virtual int CModelInfoServer::GetModelIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfoServer::GetModelIndex(CModelInfoServer *this, const char *name)
{
  return CGameServer::LookupModelIndex(this: &sv, name);
}

//------------------------------------------------------------------------------
// Address: 0x101A63A0
// Name: public: virtual void CModelInfoServer::GetModelMaterialColorAndLighting(struct model_t const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoServer::GetModelMaterialColorAndLighting(
        CModelInfoServer *this,
        const model_t *model,
        const model_t *origin,
        const Vector *angles,
        const QAngle *pTrace,
        CGameTrace *lighting,
        Vector *matColor)
{
  _Msg(a1: "GetModelMaterialColorAndLighting:  Available on client only!\n");
}

//------------------------------------------------------------------------------
// Address: 0x101A63C0
// Name: public: virtual struct model_t const __near * CModelInfoClient::GetModel(int)const
// Source: json
//------------------------------------------------------------------------------
const model_t *__thiscall CModelInfoClient::GetModel(CModelInfoClient *this, int modelindex)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::GetModel(this: BaseLocalClient, index: modelindex);
}

//------------------------------------------------------------------------------
// Address: 0x101A63E0
// Name: public: virtual int CModelInfoClient::GetModelIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfoClient::GetModelIndex(CModelInfoClient *this, const char *name)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::LookupModelIndex(this: BaseLocalClient, name);
}

//------------------------------------------------------------------------------
// Address: 0x101A6400
// Name: public: virtual void CModelInfoClient::SetLevelScreenFadeRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoClient::SetLevelScreenFadeRange(CModelInfoClient *this, float flMinSize, float flMaxSize)
{
  float m_flMaxScreenWidth; // xmm0_4

  this->m_LevelFade.m_flMinScreenWidth = flMinSize;
  this->m_LevelFade.m_flMaxScreenWidth = flMaxSize;
  if ( flMinSize >= flMaxSize )
    this->m_LevelFade.m_flMaxScreenWidth = flMinSize;
  m_flMaxScreenWidth = this->m_LevelFade.m_flMaxScreenWidth;
  if ( m_flMaxScreenWidth == flMinSize )
    this->m_LevelFade.m_flFalloffFactor = 255.0;
  else
    this->m_LevelFade.m_flFalloffFactor = 255.0 / (float)(m_flMaxScreenWidth - flMinSize);
}

//------------------------------------------------------------------------------
// Address: 0x101A6480
// Name: public: virtual void CModelInfoClient::SetViewScreenFadeRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoClient::SetViewScreenFadeRange(CModelInfoClient *this, float flMinSize, float flMaxSize)
{
  float m_flMaxScreenWidth; // xmm0_4

  this->m_ViewFade.m_flMinScreenWidth = flMinSize;
  this->m_ViewFade.m_flMaxScreenWidth = flMaxSize;
  if ( flMinSize >= flMaxSize )
    this->m_ViewFade.m_flMaxScreenWidth = flMinSize;
  m_flMaxScreenWidth = this->m_ViewFade.m_flMaxScreenWidth;
  if ( m_flMaxScreenWidth == flMinSize )
    this->m_ViewFade.m_flFalloffFactor = 255.0;
  else
    this->m_ViewFade.m_flFalloffFactor = 255.0 / (float)(m_flMaxScreenWidth - flMinSize);
}

//------------------------------------------------------------------------------
// Address: 0x101A64E0
// Name: class IMaterial __near * BrushModel_GetLightingAndMaterial(class Vector const __near &,class Vector const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl BrushModel_GetLightingAndMaterial(
        const Vector *start,
        const Vector *end,
        Vector *diffuseLightColor,
        Vector *baseColor)
{
  msurface2_t *v4; // eax
  mtexinfo_t *v5; // eax
  IMaterial *material; // esi
  int v8; // [esp+10h] [ebp-8h] BYREF
  int v9; // [esp+14h] [ebp-4h] BYREF

  v8 = 0;
  v9 = 0;
  v4 = R_LightVec(
         start,
         end,
         bUseLightStyles: true,
         c: diffuseLightColor,
         textureS: (float *)&v8,
         textureT: (float *)&v9,
         lightmapS: nullptr,
         lightmapT: nullptr);
  if ( v4 == nullptr )
    return nullptr;
  v5 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)v4 + 11) >> 1];
  if ( v5 == nullptr )
    return nullptr;
  material = v5->material;
  ((void (__thiscall *)(IMaterial *, int, int, Vector *))material->GetLowResColorSample)(
    a1: material,
    a2: v8,
    a3: v9,
    a4: baseColor);
  return material;
}

//------------------------------------------------------------------------------
// Address: 0x101A6570
// Name: public: virtual void CModelInfoClient::GetModelMaterialColorAndLighting(struct model_t const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfoClient::GetModelMaterialColorAndLighting(
        CModelInfoClient *this,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        CGameTrace *pTrace,
        Vector *lighting,
        Vector *matColor)
{
  model_t *v7; // esi
  Vector *v8; // eax
  CGameTrace *v9; // ebx
  int v10; // edi
  Vector *p_endpos; // ebx
  int v12; // esi
  LightDesc_t *v13; // ebx
  float y; // xmm4_4
  float z; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm5_4
  bool v21; // zf
  LightDesc_t desc[4]; // [esp+4h] [ebp-204h] BYREF
  LightingState_t lightingState; // [esp+164h] [ebp-A4h] BYREF
  Vector up; // [esp+1C0h] [ebp-48h] BYREF
  Vector forward; // [esp+1CCh] [ebp-3Ch] BYREF
  Vector end_l; // [esp+1D8h] [ebp-30h] BYREF
  Vector right; // [esp+1E4h] [ebp-24h] BYREF
  Vector delta; // [esp+1F0h] [ebp-18h]
  Vector origin_l; // [esp+1FCh] [ebp-Ch] BYREF

  v7 = model;
  if ( model->type == mod_brush )
  {
    y = pTrace->startpos.y;
    z = pTrace->startpos.z;
    v16 = pTrace->endpos.x - pTrace->startpos.x;
    v17 = pTrace->endpos.y - y;
    v18 = y - origin->y;
    v19 = pTrace->endpos.z - z;
    v20 = z - origin->z;
    origin_l.x = pTrace->startpos.x - origin->x;
    origin_l.y = v18;
    v21 = angles->x == 0.0;
    delta.x = v16;
    delta.y = v17;
    delta.z = v19;
    origin_l.z = v20;
    if ( !v21 || angles->y != 0.0 || angles->z != 0.0 )
    {
      AngleVectors(angles, &forward, &right, &up);
      v16 = (float)((float)(forward.y * delta.y) + (float)(forward.x * delta.x)) + (float)(forward.z * delta.z);
      LODWORD(v17) = COERCE_UNSIGNED_INT((float)((float)(right.y * delta.y) + (float)(right.x * delta.x)) + (float)(right.z * delta.z))
                   ^ _mask__NegFloat_;
      v19 = (float)((float)(up.y * delta.y) + (float)(up.x * delta.x)) + (float)(up.z * delta.z);
    }
    end_l.x = (float)(v16 * 1.1) + origin_l.x;
    end_l.y = (float)(v17 * 1.1) + origin_l.y;
    end_l.z = (float)(v19 * 1.1) + origin_l.z;
    R_LightVecUseModel(pModel: v7);
    BrushModel_GetLightingAndMaterial(start: &origin_l, end: &end_l, diffuseLightColor: lighting, baseColor: matColor);
    R_LightVecUseModel(pModel: nullptr);
  }
  else if ( model->type == mod_studio )
  {
    v8 = matColor;
    v9 = pTrace;
    v10 = 0;
    matColor->x = 0.5;
    v8->y = 0.5;
    v8->z = 0.5;
    p_endpos = &v9->endpos;
    memset(&lightingState, 0, 76);
    matColor = p_endpos;
    LightcacheGetDynamic(
      a1: 0.0,
      origin: p_endpos,
      &lightingState,
      stats: (LightcacheGetDynamic_Stats *)&model,
      pRenderable: nullptr,
      flags: 15,
      bDebugModel: false);
    v12 = 0;
    if ( lightingState.numlights > 0 )
    {
      v13 = desc;
      do
      {
        if ( WorldLightToMaterialLight(pWorldLight: lightingState.locallight[v12], light: v13) )
        {
          ++v10;
          ++v13;
        }
        ++v12;
      }
      while ( v12 < lightingState.numlights );
      p_endpos = matColor;
    }
    g_pStudioRender->ComputeLighting(
      this: g_pStudioRender,
      a2: (const Vector *)&lightingState,
      a3: v10,
      a4: desc,
      a5: p_endpos,
      a6: (const Vector *)&pTrace->plane,
      a7: lighting);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6850
// Name: public: virtual class KeyValues __near * CModelInfo::GetModelKeyValues(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__userpurge CModelInfo::GetModelKeyValues@<eax>(CModelInfo *this@<ecx>, int a2@<ebx>, const model_t *pModel)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  const char *v8; // eax
  KeyValues *result; // eax
  IBaseFileSystem *pKeyValueText; // [esp+10h] [ebp+8h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_ModelKeyValueMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_ModelKeyValueMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_ModelKeyValueMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_ModelKeyValueMutex.m_depth;
  }
  if ( pModel->m_pKeyValues == nullptr )
  {
    pKeyValueText = (IBaseFileSystem *)((int (__thiscall *)(CModelInfo *, const model_t *, int))this->GetModelKeyValueText)(
                                         a1: this,
                                         a2: pModel,
                                         a3: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: defaultValue);
    else
      v7 = nullptr;
    v8 = (const char *)((int (__thiscall *)(CModelInfo *))this->GetModelName)(a1: this);
    if ( KeyValues::LoadFromBuffer(
           this: v7,
           resourceName: v8,
           pBuffer: (const char *)pModel,
           pFileSystem: pKeyValueText,
           pPathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      pModel->m_pKeyValues = v7;
    }
    else
    {
      KeyValues::deleteThis(this: v7);
    }
  }
  result = pModel->m_pKeyValues;
  if ( --g_ModelKeyValueMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_ModelKeyValueMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A6920
// Name: public: virtual void CModelInfo::GetBrushModelPlane(struct model_t const __near *,int,struct cplane_t __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetBrushModelPlane(
        CModelInfo *this,
        const model_t *model,
        int nIndex,
        cplane_t *plane,
        Vector *pOrigin)
{
  if ( model != nullptr && model->type == mod_brush )
    *plane = *R_GetBrushModelPlane(model, nIndex, pOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x101A6980
// Name: public: virtual bool CModelInfo::IsUsingFBTexture(struct model_t const __near *,int,int,void __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelInfo::IsUsingFBTexture(
        CModelInfo *this,
        const model_t *model,
        int nSkin,
        int nBody,
        void *pClientRenderable)
{
  int v5; // ebx
  int v6; // edi
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  int v10; // edi
  int v11; // ecx
  IMaterial *pMaterials[128]; // [esp+Ch] [ebp-200h] BYREF

  if ( model == nullptr || (model->flags & 0x100) == 0 )
    return 0;
  if ( model->type != mod_brush )
  {
    if ( model->type == mod_studio )
    {
      v5 = ((int (__stdcall *)(_DWORD, int, int, int, IMaterial **))g_pStudioRender->GetMaterialListFromBodyAndSkin)(
             a1: model->studio,
             a2: nSkin,
             a3: nBody,
             a4: 128,
             a5: pMaterials);
      v6 = 0;
      if ( v5 > 0 )
      {
        while ( 1 )
        {
          if ( pMaterials[v6] != nullptr )
          {
            v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
            v8 = v7;
            if ( v7 != nullptr )
              v7->BeginRender(this: v7);
            v8->Bind(this: v8, a2: pMaterials[v6], a3: pClientRenderable);
            if ( pMaterials[v6]->NeedsPowerOfTwoFrameBufferTexture(this: pMaterials[v6], a2: true) )
            {
              if ( v8 != nullptr )
              {
                v8->EndRender(this: v8);
                v8->Release(this: v8);
              }
              return 1;
            }
            v8->EndRender(this: v8);
            v8->Release(this: v8);
          }
          if ( ++v6 >= v5 )
            return 0;
        }
      }
    }
    return 0;
  }
  v10 = 0;
  if ( model->brush.nummodelsurfaces <= 0 )
    return 0;
  while ( 1 )
  {
    v11 = *(_DWORD *)(80
                    * (*(unsigned __int16 *)(32 * (v10 + model->brush.firstmodelsurface)
                                           + *(_DWORD *)(model->sprite.numframes + 124)
                                           + 22) >> 1)
                    + *(_DWORD *)(model->sprite.numframes + 96)
                    + 76);
    if ( v11 != 0 && (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v11 + 96))(a1: v11, a2: 1) != 0 )
      break;
    if ( ++v10 >= model->brush.nummodelsurfaces )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A6AF0
// Name: public: virtual bool CModelInfo::GetModelKeyValue(struct model_t const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelInfo::GetModelKeyValue(CModelInfo *this, const model_t *model, CUtlBuffer *buf)
{
  const studiohdr_t *v4; // eax
  virtualmodel_t *v6; // eax
  virtualmodel_t *v7; // esi
  int v8; // ebx
  int v9; // edi
  studiohdr_t *v10; // eax
  const char *v11; // eax

  if ( model == nullptr )
    return 0;
  if ( model->type != mod_studio )
    return 0;
  v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->studio);
  if ( v4 == nullptr )
    return 0;
  if ( v4->numincludemodels != 0 )
  {
    v6 = this->GetVirtualModel(this, a2: v4);
    v7 = v6;
    if ( v6 != nullptr )
    {
      v8 = 0;
      if ( v6->m_group.m_Size > 0 )
      {
        v9 = 0;
        do
        {
          v10 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: LOWORD(v7->m_group.m_Memory.m_pMemory[v9].cache));
          if ( v10 != nullptr && v10->keyvaluesize != 0 )
          {
            v11 = (char *)v10 + v10->keyvalueindex;
            if ( v11 != nullptr )
              CUtlBuffer::PutString(this: buf, pString: v11);
          }
          ++v8;
          ++v9;
        }
        while ( v8 < v7->m_group.m_Size );
      }
    }
    return 1;
  }
  else
  {
    if ( v4->keyvaluesize != 0 )
      CUtlBuffer::PutString(this: buf, pString: (const char *)v4 + v4->keyvalueindex);
    else
      CUtlBuffer::PutString(this: buf, pString: nullptr);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6BF0
// Name: public: virtual void CModelInfo::GetLevelScreenFadeRange(float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelInfo::GetLevelScreenFadeRange(CModelInfo *this, float *pMinArea, float *pMaxArea)
{
  *pMinArea = 0.0;
  *pMaxArea = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A6C10
// Name: public: virtual int CModelInfo::GetSurfacepropsForVirtualTerrain(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetSurfacepropsForVirtualTerrain(CModelInfo *this, int index)
{
  return CM_SurfacepropsForDisp(index);
}

//------------------------------------------------------------------------------
// Address: 0x101A6C30
// Name: public: virtual unsigned short CModelInfo::GetCacheHandle(struct model_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelInfo::GetCacheHandle(CModelInfo *this, const model_t *model)
{
  if ( model->type == mod_studio )
    return model->studio;
  else
    return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101A6C60
// Name: private: unsigned char CModelInfoClient::ComputeScreenFade(class Vector const __near &,float,float,struct CModelInfoClient::ScreenFadeInfo_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge CModelInfoClient::ComputeScreenFade@<al>(
        CModelInfoClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const Vector *vecAbsOrigin,
        float flRadius,
        float flFadeScale,
        const CModelInfoClient::ScreenFadeInfo_t *fade)
{
  int v7; // esi
  char v8; // bl
  float m_flMaxScreenWidth; // xmm1_4
  int v10; // eax
  float v12; // [esp+18h] [ebp+10h]

  if ( fade->m_flMinScreenWidth <= 0.0 || flFadeScale <= 0.0 )
    return -1;
  v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
  if ( v7 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
  v8 = 0;
  v12 = ((double (__thiscall *)(int, const Vector *, _DWORD))*(_DWORD *)(*(_DWORD *)v7 + 312))(
          a1: v7,
          a2: vecAbsOrigin,
          a3: LODWORD(flRadius))
      / flFadeScale;
  if ( v12 > fade->m_flMinScreenWidth )
  {
    m_flMaxScreenWidth = fade->m_flMaxScreenWidth;
    if ( m_flMaxScreenWidth < 0.0 || m_flMaxScreenWidth <= v12 )
    {
      v8 = -1;
    }
    else
    {
      v10 = (int)(float)((float)(v12 - fade->m_flMinScreenWidth) * fade->m_flFalloffFactor);
      if ( v10 >= 0 )
      {
        if ( v10 > 255 )
          LOBYTE(v10) = -1;
        v8 = v10;
      }
      else
      {
        v8 = 0;
      }
    }
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101A6D30
// Name: public: virtual unsigned char CModelInfoClient::ComputeLevelScreenFade(class Vector const __near &,float,float)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge CModelInfoClient::ComputeLevelScreenFade@<al>(
        CModelInfoClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const Vector *vecAbsOrigin,
        float flRadius,
        float flFadeScale)
{
  return CModelInfoClient::ComputeScreenFade(
           this,
           a2,
           a3,
           vecAbsOrigin,
           flRadius,
           flFadeScale,
           fade: &this->m_LevelFade);
}

//------------------------------------------------------------------------------
// Address: 0x101A6D60
// Name: public: virtual unsigned char CModelInfoClient::ComputeViewScreenFade(class Vector const __near &,float,float)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge CModelInfoClient::ComputeViewScreenFade@<al>(
        CModelInfoClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const Vector *vecAbsOrigin,
        float flRadius,
        float flFadeScale)
{
  return CModelInfoClient::ComputeScreenFade(this, a2, a3, vecAbsOrigin, flRadius, flFadeScale, fade: &this->m_ViewFade);
}

//------------------------------------------------------------------------------
// Address: 0x101A63B0
// Name: __CreateCModelInfoServerIVModelInfo_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CModelInfoServer *__cdecl _CreateCModelInfoServerIVModelInfo_interface()
{
  return &g_ModelInfoServer;
}

} // namespace engine_xlsp
