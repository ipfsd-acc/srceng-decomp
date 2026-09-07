// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/staticpropmgr.cpp
// Functions: 85
// ============================================================

#include "engine\staticpropmgr.h"

//------------------------------------------------------------------------------
// Address: 0x101DE910
// Name: private: void CStaticProp::InitModelRenderInfo(struct ModelRenderInfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::InitModelRenderInfo(CStaticProp *this, ModelRenderInfo_t *sInfo, int flags)
{
  IClientRenderable *v3; // edx

  sInfo->origin = this->m_Origin;
  sInfo->angles = this->m_Angles;
  if ( this != nullptr )
    v3 = &this->IClientRenderable;
  else
    v3 = nullptr;
  sInfo->pRenderable = v3;
  sInfo->pModel = this->m_pModel;
  sInfo->pModelToWorld = &this->m_ModelToWorld;
  sInfo->pLightingOrigin = &this->m_LightingOrigin;
  sInfo->pLightingOffset = nullptr;
  sInfo->flags = flags;
  sInfo->entity_index = -1;
  sInfo->skin = this->m_Skin;
  sInfo->body = 0;
  sInfo->hitboxset = 0;
  sInfo->instance = this->m_ModelInstance;
}

//------------------------------------------------------------------------------
// Address: 0x101DE9C0
// Name: public: virtual unsigned short __near & CStaticProp::RenderHandle(void)
// Source: json
//------------------------------------------------------------------------------
CBaseHandle *__thiscall CStaticProp::RenderHandle(CStaticProp *this)
{
  return &this->m_EntHandle;
}

//------------------------------------------------------------------------------
// Address: 0x101DE9D0
// Name: public: virtual void CStaticProp::WorldSpaceSurroundingBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::WorldSpaceSurroundingBounds(
        CStaticProp *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  *pVecWorldMins = *(Vector *)&this->m_ModelToWorld.m_flMatVal[2][3];
  *pVecWorldMaxs = *(Vector *)&this->m_WorldRenderBBoxMin.y;
}

//------------------------------------------------------------------------------
// Address: 0x101DEA20
// Name: public: virtual class Vector const __near & CStaticProp::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
IClientModelRenderable *__thiscall CStaticProp::GetRenderOrigin(CStaticProp *this)
{
  return &this->IClientModelRenderable;
}

//------------------------------------------------------------------------------
// Address: 0x101DEA30
// Name: public: virtual class QAngle const __near & CStaticProp::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CStaticProp::GetRenderAngles(CStaticProp *this)
{
  return (const QAngle *)&this->m_Origin.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DEA40
// Name: public: virtual bool CStaticProp::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticProp::GetAttachment(CStaticProp *this, int number, Vector *origin, QAngle *angles)
{
  origin->x = *(float *)&this->IClientModelRenderable::__vftable;
  origin->y = this->m_Origin.x;
  origin->z = this->m_Origin.y;
  *angles = *(QAngle *)&this->m_Origin.z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEA80
// Name: public: virtual bool CStaticProp::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticProp::GetAttachment(CStaticProp *this, int number, matrix3x4_t *matrix)
{
  const matrix3x4_t *v3; // eax

  v3 = (const matrix3x4_t *)((int (__thiscall *)(CStaticProp *))this->IClientUnknown::IHandleEntity::__vftable[2].ShouldCacheRenderInfo)(a1: this);
  MatrixCopy(in: v3, out: matrix);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEAA0
// Name: public: virtual bool CStaticProp::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStaticProp::ShouldDraw(CStaticProp *this)
{
  return LOWORD(this->m_EntHandle.m_Index) != 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101DEAB0
// Name: public: virtual bool CStaticProp::SetupBones(class matrix3x4a_t __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticProp::SetupBones(
        CStaticProp *this,
        matrix3x4a_t *pBoneToWorldOut,
        int nMaxBones,
        int boneMask,
        float currentTime)
{
  if ( LODWORD(this->m_Angles.z) == 0 )
    return 0;
  MatrixCopy(in: (const matrix3x4_t *)&this->m_RenderBBoxMax.z, out: pBoneToWorldOut);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEAE0
// Name: public: virtual bool CStaticProp::GetRenderData(void __near *,enum ModelDataCategory_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticProp::GetRenderData(CStaticProp *this, _DWORD *pData, ModelDataCategory_t nCategory)
{
  if ( nCategory != MODEL_DATA_LIGHTING_MODEL )
    return 0;
  *pData = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEB00
// Name: public: virtual void CStaticProp::GetColorModulation(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::GetColorModulation(CStaticProp *this, float *color)
{
  *color = this->m_LightingOrigin.z;
  color[1] = this->m_DiffuseModulation.x;
  color[2] = this->m_DiffuseModulation.y;
}

//------------------------------------------------------------------------------
// Address: 0x101DEB60
// Name: public: virtual class QAngle const __near & CStaticProp::GetCollisionAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CStaticProp::GetCollisionAngles(CStaticProp *this)
{
  bool v2; // zf
  const QAngle *result; // eax

  v2 = ((int (__thiscall *)(CStaticProp *))this->IClientUnknown::IHandleEntity::__vftable[1].dtr_IHandleEntity)(a1: this) == 6;
  result = (const QAngle *)&this->m_Origin.y;
  if ( !v2 )
    return &vec3_angle;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DEB80
// Name: public: virtual struct matrix3x4_t const __near & CStaticProp::CollisionToWorldTransform(void)const
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall CStaticProp::CollisionToWorldTransform(CStaticProp *this)
{
  return (const matrix3x4_t *)&this->m_RenderBBoxMax.y;
}

//------------------------------------------------------------------------------
// Address: 0x101DEB90
// Name: public: virtual enum SolidType_t CStaticProp::GetSolid(void)const
// Source: json
//------------------------------------------------------------------------------
SolidType_t __thiscall CStaticProp::GetSolid(CStaticProp *this)
{
  return BYTE1(this->m_pModel);
}

//------------------------------------------------------------------------------
// Address: 0x101DEBA0
// Name: public: virtual int CStaticProp::GetRenderFlags(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStaticProp::GetRenderFlags(CStaticProp *this)
{
  float z; // ecx
  BOOL result; // eax

  z = this->m_Angles.z;
  result = false;
  if ( z != 0.0 )
    return (*(_DWORD *)(LODWORD(z) + 276) & 0x100) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DEBC0
// Name: public: virtual void CStaticProp::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::GetRenderBounds(CStaticProp *this, Vector *mins, Vector *maxs)
{
  *mins = *(Vector *)&this->m_pClientAlphaProperty;
  *maxs = *(Vector *)&this->m_RenderBBoxMin.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DEBF0
// Name: public: virtual void CStaticProp::GetRenderBoundsWorldspace(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::GetRenderBoundsWorldspace(CStaticProp *this, Vector *mins, Vector *maxs)
{
  *mins = *(Vector *)&this->m_flRadius;
  *maxs = *(Vector *)&this->m_WorldRenderBBoxMin.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DEC40
// Name: public: virtual bool CStaticProp::ShouldReceiveProjectedTextures(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStaticProp::ShouldReceiveProjectedTextures(CStaticProp *this, char flags)
{
  return (this->m_ModelInstance & 0x400) == 0 && (flags & 5) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DEC60
// Name: public: void CStaticProp::InsertPropIntoKDTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::InsertPropIntoKDTree(CStaticProp *this)
{
  vcollide_t *v2; // eax
  ISpatialPartitionInternal *v3; // eax
  const char *v4; // eax
  char szModel[260]; // [esp+4h] [ebp-14Ch] BYREF
  matrix3x4_t propToWorld; // [esp+108h] [ebp-48h] BYREF
  Vector maxs; // [esp+138h] [ebp-18h] BYREF
  Vector mins; // [esp+144h] [ebp-Ch] BYREF

  if ( this->m_nSolidType != 0 )
  {
    AngleMatrix(angles: &this->m_Angles, position: &this->m_Origin, matrix: &propToWorld);
    TransformAABB(
      transform: &propToWorld,
      vecMinsIn: &this->m_pModel->mins,
      vecMaxsIn: &this->m_pModel->maxs,
      vecMinsOut: &mins,
      vecMaxsOut: &maxs);
    if ( this->m_nSolidType != 6 )
    {
LABEL_6:
      v3 = SpatialPartition();
      this->m_Partition = v3->CreateHandle(this: v3, a2: this, a3: 101, a4: &mins, a5: &maxs);
      return;
    }
    v2 = CM_VCollideForModel(modelindex: -1, pModel: this->m_pModel);
    if ( v2 != nullptr && (*(_WORD *)v2 & 0x7FFF) != 0 )
    {
      physcollision->CollideGetAABB(
        this: physcollision,
        a2: &mins,
        a3: &maxs,
        a4: *v2->solids,
        a5: &this->m_Origin,
        a6: &this->m_Angles);
      goto LABEL_6;
    }
    if ( this->m_pModel != nullptr )
      v4 = modelloader->GetName(this: modelloader, a2: this->m_pModel);
    else
      v4 = "unknown model";
    V_strncpy(pDest: szModel, pSrc: v4, maxLen: 260);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_StaticPropManager,
        a2: 1,
        a3: "SOLID_VPHYSICS static prop with no vphysics model! (%s)\n",
        szModel);
    this->m_nSolidType = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DED80
// Name: class IStaticPropMgrEngine __near * StaticPropMgr(void)
// Source: json
//------------------------------------------------------------------------------
CStaticPropMgr *__cdecl StaticPropMgr()
{
  return &s_StaticPropMgr;
}

//------------------------------------------------------------------------------
// Address: 0x101DED90
// Name: public: virtual void CStaticPropMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::Shutdown(CStaticPropMgr *this)
{
  if ( this->m_bLevelInitialized )
    this->LevelShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DEDA0
// Name: public: virtual bool CStaticPropMgr::IsStaticProp(class IHandleEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStaticPropMgr::IsStaticProp(CStaticPropMgr *this, IHandleEntity *pHandleEntity)
{
  return pHandleEntity == nullptr
      || (pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index & 0xFFFF0000) == 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x101DEDD0
// Name: public: virtual bool CStaticPropMgr::IsStaticProp(class CBaseHandle)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStaticPropMgr::IsStaticProp(CStaticPropMgr *this, CBaseHandle handle)
{
  return (handle.m_Index & 0xFFFF0000) == 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x101DEDF0
// Name: public: virtual int CStaticPropMgr::GetStaticPropIndex(class IHandleEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CStaticPropMgr::GetStaticPropIndex(CStaticPropMgr *this, IHandleEntity *pHandleEntity)
{
  unsigned int result; // eax

  result = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( result == -1 )
    return 0x1FFF;
  else
    return (unsigned __int16)result;
}

//------------------------------------------------------------------------------
// Address: 0x101DEE20
// Name: public: virtual void CStaticPropMgr::GetLightingOrigins(class Vector __near *,int,int,class IClientRenderable __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetLightingOrigins(
        CStaticPropMgr *this,
        Vector *pLightingOrigins,
        int nOriginStride,
        int nCount,
        IClientRenderable **ppRenderable,
        int nRenderableStride)
{
  int v6; // ebx
  float *p_z; // esi
  float *v9; // eax

  v6 = nCount;
  if ( nCount > 0 )
  {
    p_z = &pLightingOrigins->z;
    do
    {
      v9 = (float *)(*ppRenderable)->GetIClientUnknown(this: *ppRenderable);
      ppRenderable = (IClientRenderable **)((char *)ppRenderable + nRenderableStride);
      *(p_z - 2) = v9[43];
      *(p_z - 1) = v9[44];
      *p_z = v9[45];
      p_z = (float *)((char *)p_z + nOriginStride);
      --v6;
    }
    while ( v6 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DEE70
// Name: public: void CStaticPropMgr::DrawStaticProps_FastPipeline(class IClientRenderable __near * __near *,struct RenderableInstance_t const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::DrawStaticProps_FastPipeline(
        CStaticPropMgr *this,
        IClientRenderable **pProps,
        const RenderableInstance_t *pInstances,
        int count,
        BOOL bShadowDepth)
{
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  char *v8; // eax
  IClientRenderable *v9; // ecx
  IClientRenderable *v10; // ecx
  _BYTE v11[4]; // [esp+Ch] [ebp-A000h] BYREF
  char v12; // [esp+10h] [ebp-9FFCh] BYREF

  v5 = count;
  v6 = 0;
  if ( count > 2048 )
  {
    CStaticPropMgr::DrawStaticProps_FastPipeline(
      this,
      pProps: pProps + 2048,
      pInstances,
      count: count - 2048,
      bShadowDepth);
    v5 = 2048;
  }
  v7 = 0;
  if ( v5 > 0 )
  {
    v8 = &v12;
    do
    {
      v9 = pProps[v7];
      if ( v9 != nullptr )
        v10 = v9 - 1;
      else
        v10 = nullptr;
      if ( v10[10].__vftable != nullptr )
      {
        *((_DWORD *)v8 - 1) = v10 + 24;
        *(IClientRenderable *)v8 = v10[10];
        *((_WORD *)v8 + 6) = HIWORD(v10[11].__vftable);
        v8[14] = BYTE2(v10[12].__vftable);
        *((_DWORD *)v8 + 2) = v10 + 43;
        *((_DWORD *)v8 + 1) = v10 + 1;
        v8[15] = pInstances[v7].m_nAlpha;
        ++v6;
        v8 += 20;
      }
      ++v7;
    }
    while ( v7 < v5 );
  }
  modelrender->DrawStaticPropArrayFast(this: modelrender, a2: (StaticPropRenderInfo_t *)v11, a3: v6, a4: bShadowDepth);
}

//------------------------------------------------------------------------------
// Address: 0x101DEF40
// Name: public: virtual void CStaticPropMgr::AddShadowToStaticProp(unsigned short,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::AddShadowToStaticProp(
        CStaticPropMgr *this,
        int shadowHandle,
        IClientRenderable *pRenderable)
{
  IClientRenderable *v3; // eax
  IShadowMgrInternal_vtbl *v4; // esi
  unsigned __int16 v5; // ax

  if ( pRenderable != nullptr )
    v3 = pRenderable - 1;
  else
    v3 = nullptr;
  v4 = g_pShadowMgr->__vftable;
  v5 = v3[1].GetModelInstance(this: v3 + 1);
  v4->AddShadowToModel(this: g_pShadowMgr, a2: shadowHandle, a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101DEF80
// Name: public: virtual void CStaticPropMgr::RemoveAllShadowsFromStaticProp(class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::RemoveAllShadowsFromStaticProp(CStaticPropMgr *this, IClientRenderable *pRenderable)
{
  IClientRenderable *v2; // eax
  IClientRenderable *v3; // esi
  IShadowMgrInternal_vtbl *v4; // edi
  unsigned __int16 v5; // ax

  if ( pRenderable != nullptr )
    v2 = pRenderable - 1;
  else
    v2 = nullptr;
  v3 = v2 + 1;
  if ( v2[1].GetModelInstance(this: v2 + 1) != 0xFFFF )
  {
    v4 = g_pShadowMgr->__vftable;
    v5 = v3->GetModelInstance(this: v3);
    v4->RemoveAllShadowsFromModel(this: g_pShadowMgr, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF070
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
// Address: 0x101DF100
// Name: ShouldDrawInWireFrameMode
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ShouldDrawInWireFrameMode()
{
  if ( (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0) && !Cmd_IsRptActive() )
    return false;
  if ( mat_wireframe.m_pParent != nullptr )
    return mat_wireframe.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101DF140
// Name: bool IsUsingStaticPropDebugModes(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsUsingStaticPropDebugModes()
{
  return r_drawstaticprops.m_pParent == nullptr
      || r_drawstaticprops.m_pParent->m_Value.m_nValue != 1
      || r_DrawSpecificStaticProp.m_pParent == nullptr
      || r_DrawSpecificStaticProp.m_pParent->m_Value.m_nValue >= 0
      || r_colorstaticprops.m_pParent != nullptr && r_colorstaticprops.m_pParent->m_Value.m_nValue != 0
      || r_staticpropinfo.m_pParent != nullptr && r_staticpropinfo.m_pParent->m_Value.m_nValue != 0
      || mat_fullbright.m_pParent != nullptr && mat_fullbright.m_pParent->m_Value.m_nValue != 0
      || r_drawmodellightorigin.m_pParent != nullptr && r_drawmodellightorigin.m_pParent->m_Value.m_nValue != 0
      || ShouldDrawInWireFrameMode()
      || r_drawmodelstatsoverlay.m_pParent != nullptr && r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DF1C0
// Name: public: virtual class IClientUnknown __near * CStaticProp::GetIClientUnknown(void)
// Source: json
//------------------------------------------------------------------------------
CStaticProp *__thiscall CStaticProp::GetIClientUnknown(CStaticProp *this)
{
  return (CStaticProp *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x101DF1D0
// Name: public: virtual class ICollideable __near * CStaticProp::GetCollideable(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CStaticProp::GetCollideable(CStaticProp *this)
{
  if ( this != nullptr )
    return &this->ICollideable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DF1E0
// Name: public: virtual class IClientRenderable __near * CStaticProp::GetClientRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall CStaticProp::GetClientRenderable(CStaticProp *this)
{
  if ( this != nullptr )
    return &this->IClientRenderable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DF1F0
// Name: public: virtual class IHandleEntity __near * CStaticProp::GetEntityHandle(void)
// Source: json
//------------------------------------------------------------------------------
CStaticProp *__thiscall CStaticProp::GetEntityHandle(CStaticProp *this)
{
  return (CStaticProp *)((char *)this - 8);
}

//------------------------------------------------------------------------------
// Address: 0x101DF200
// Name: public: virtual int CStaticProp::GetSkin(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::GetSkin(CStaticProp *this)
{
  return LOBYTE(this->m_ModelInstance);
}

//------------------------------------------------------------------------------
// Address: 0x101DF210
// Name: public: virtual unsigned char CStaticProp::OverrideShadowAlphaModulation(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CStaticProp::OverrideShadowAlphaModulation(CStaticProp *this, unsigned __int8 nAlpha)
{
  return nAlpha;
}

//------------------------------------------------------------------------------
// Address: 0x101DF220
// Name: public: virtual unsigned short CStaticProp::GetShadowHandle(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::GetShadowHandle(CShadowMgr *this)
{
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101DF230
// Name: public: virtual void CStaticProp::GetShadowRenderBounds(class Vector __near &,class Vector __near &,enum ShadowType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::GetShadowRenderBounds(
        CStaticProp *this,
        Vector *mins,
        Vector *maxs,
        ShadowType_t shadowType)
{
  ((void (__thiscall *)(CStaticProp *, Vector *, Vector *))this->IClientUnknown::IHandleEntity::__vftable[1].GetIClientEntity)(
    a1: this,
    a2: mins,
    a3: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x101DF250
// Name: public: virtual int CStaticProp::LookupAttachment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::LookupAttachment(CStaticProp *this, const char *pAttachmentName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101DF260
// Name: public: virtual struct matrix3x4_t const __near & CStaticProp::RenderableToWorldTransform(void)
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall CStaticProp::RenderableToWorldTransform(CStaticProp *this)
{
  return (const matrix3x4_t *)&this->m_RenderBBoxMax.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DF270
// Name: public: virtual unsigned short CStaticProp::GetModelInstance(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CStaticProp::GetModelInstance(CStaticProp *this)
{
  return HIWORD(this->m_pModel);
}

//------------------------------------------------------------------------------
// Address: 0x101DF290
// Name: public: virtual CStaticProp::~CStaticProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::~CStaticProp(CStaticProp *this)
{
  IClientAlphaProperty *m_pClientAlphaProperty; // eax
  ISpatialPartitionInternal *v3; // eax

  m_pClientAlphaProperty = this->m_pClientAlphaProperty;
  this->IClientUnknown::IHandleEntity::__vftable = (CStaticProp_vtbl *)&CStaticProp::`vftable'{for `IClientUnknown'};
  this->IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CStaticProp::`vftable'{for `IClientRenderable'};
  this->ICollideable::__vftable = (ICollideable_vtbl *)&CStaticProp::`vftable'{for `ICollideable'};
  this->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CStaticProp::`vftable'{for `IClientModelRenderable'};
  if ( m_pClientAlphaProperty != nullptr )
  {
    g_pClientAlphaPropertyMgr->DestroyClientAlphaProperty(this: g_pClientAlphaPropertyMgr, a2: m_pClientAlphaProperty);
    this->m_pClientAlphaProperty = nullptr;
  }
  if ( this->m_Partition != 0xFFFF )
  {
    v3 = SpatialPartition();
    v3->DestroyHandle(this: v3, a2: this->m_Partition);
    this->m_Partition = -1;
  }
  if ( this->m_ModelInstance != 0xFFFF )
    modelrender->DestroyInstance(this: modelrender, a2: this->m_ModelInstance);
  this->IClientUnknown::IHandleEntity::__vftable = (CStaticProp_vtbl *)&IHandleEntity::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101DF320
// Name: public: bool CStaticProp::Init(int,struct StaticPropLump_t __near &,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CStaticProp::Init@<al>(
        CStaticProp *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int index,
        StaticPropLump_t *lump,
        model_t *pModel)
{
  void (__thiscall *BeginLock)(IMDLCache *); // eax
  studiohdr_t *v9; // eax
  const char *v10; // eax
  IClientAlphaProperty *v11; // eax
  bool v12; // zf
  const char *v13; // eax
  unsigned __int8 m_nMinGPULevel; // cl
  unsigned __int8 m_nMaxGPULevel; // dl
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  __int128 v20; // xmm0
  int v21; // eax
  char v24[92]; // [esp-Ch] [ebp-134h] BYREF
  _BYTE szModel_172[40]; // [esp+FCh] [ebp-2Ch] OVERLAPPED
  int szModel_216; // [esp+128h] [ebp+0h]

  *(_DWORD *)&szModel_172[32] = a2;
  *(_DWORD *)&szModel_172[36] = szModel_216;
  this->m_EntHandle.m_Index = index | 0x40000000;
  this->m_Partition = -1;
  this->m_Origin = lump->m_Origin;
  this->m_Angles = lump->m_Angles;
  this->m_pModel = pModel;
  this->m_FirstLeaf = lump->m_FirstLeaf;
  this->m_LeafCount = lump->m_LeafCount;
  this->m_nSolidType = lump->m_Solid;
  this->m_DiffuseModulation.x = (float)lump->m_DiffuseModulation.r * 0.0039215689;
  this->m_DiffuseModulation.y = (float)lump->m_DiffuseModulation.g * 0.0039215689;
  this->m_DiffuseModulation.z = (float)lump->m_DiffuseModulation.b * 0.0039215689;
  this->m_DiffuseModulation.w = (float)lump->m_DiffuseModulation.a * 0.0039215689;
  BeginLock = g_pMDLCache->BeginLock;
  *(_DWORD *)&szModel_172[20] = g_pMDLCache;
  ((void (__cdecl *)(int, int))BeginLock)(a1: a3, a2: a4);
  v9 = modelinfo->GetStudiomodel(this: modelinfo, a2: this->m_pModel);
  *(_DWORD *)&szModel_172[28] = v9;
  if ( v9 != nullptr && (v9->flags & 0x10) == 0 && nBitchCount < 100 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
    {
      v10 = studiohdr_t::pszName(this: *(studiohdr_t **)&szModel_172[28]);
      _LoggingSystem_Log(
        a1: LOG_StaticPropManager,
        a2: 1,
        a3: "model %s used as a static prop, but not compiled as a static prop\n",
        v10);
    }
    ++nBitchCount;
  }
  if ( !sv.m_bIsDedicated )
  {
    if ( this->m_pClientAlphaProperty != nullptr )
    {
      g_pClientAlphaPropertyMgr->DestroyClientAlphaProperty(
        this: g_pClientAlphaPropertyMgr,
        a2: this->m_pClientAlphaProperty);
      this->m_pClientAlphaProperty = nullptr;
    }
    v11 = (IClientAlphaProperty *)g_pClientAlphaPropertyMgr->CreateClientAlphaProperty(
                                    this: g_pClientAlphaPropertyMgr,
                                    a2: this);
    this->m_pClientAlphaProperty = v11;
    v11->SetAlphaModulation(this: v11, a2: lump->m_DiffuseModulation.a);
    this->m_pClientAlphaProperty->SetDesyncOffset(this: this->m_pClientAlphaProperty, a2: index);
    ((void (__thiscall *)(IClientAlphaProperty *, _DWORD, int, _DWORD, _DWORD))this->m_pClientAlphaProperty->SetRenderFX)(
      a1: this->m_pClientAlphaProperty,
      a2: 0,
      a3: 2,
      a4: 3.4028235e38,
      a5: 0.0);
    v12 = (*(_DWORD *)(*(_DWORD *)&szModel_172[28] + 152) & 0x800) == 0;
    *(float *)&szModel_172[24] = lump->m_flForcedFadeScale;
    if ( !v12 )
      *(_DWORD *)&szModel_172[24] = 0;
    ((void (__thiscall *)(IClientAlphaProperty *, _DWORD, _DWORD, _DWORD))this->m_pClientAlphaProperty->SetFade)(
      a1: this->m_pClientAlphaProperty,
      a2: 0.0,
      a3: 0.0,
      a4: 0.0);
    if ( (lump->m_Flags & 1) != 0 )
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pClientAlphaProperty->SetFade)(
        a1: this->m_pClientAlphaProperty,
        a2: lump->m_FadeMinDist,
        a3: lump->m_FadeMinDist,
        a4: lump->m_FadeMaxDist);
  }
  if ( this->m_nSolidType != 0 && this->m_nSolidType != 2 && this->m_nSolidType != 6 )
  {
    if ( this->m_pModel != nullptr )
      v13 = modelloader->GetName(this: modelloader, a2: this->m_pModel);
    else
      v13 = "unknown model";
    V_strncpy(pDest: v24, pSrc: v13, maxLen: 260);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_StaticPropManager,
        a2: 1,
        a3: "CStaticProp::Init:  Map error, static_prop with bogus SOLID_ flag (%d)! (%s)\n",
        this->m_nSolidType,
        v24);
    this->m_nSolidType = 0;
  }
  this->m_Alpha = -1;
  this->m_Skin = lump->m_Skin;
  this->m_Flags = lump->m_Flags & 0x24;
  this->m_nMinCPULevel = lump->m_nMinCPULevel;
  this->m_nMaxCPULevel = lump->m_nMaxCPULevel;
  m_nMinGPULevel = lump->m_nMinGPULevel;
  *(_DWORD *)&szModel_172[28] = &this->m_ModelToWorld;
  this->m_nMinGPULevel = m_nMinGPULevel;
  m_nMaxGPULevel = lump->m_nMaxGPULevel;
  *(_DWORD *)&szModel_172[24] = lump;
  *(_DWORD *)&szModel_172[20] = &lump->m_Angles;
  this->m_nMaxGPULevel = m_nMaxGPULevel;
  AngleMatrix(
    angles: *(const QAngle **)&szModel_172[20],
    position: *(const Vector **)&szModel_172[24],
    matrix: *(matrix3x4_t **)&szModel_172[28]);
  modelinfo->GetModelRenderBounds(
    this: modelinfo,
    a2: this->m_pModel,
    a3: &this->m_RenderBBoxMin,
    a4: &this->m_RenderBBoxMax);
  v16 = this->m_RenderBBoxMin.x - this->m_RenderBBoxMax.x;
  v17 = this->m_RenderBBoxMin.y - this->m_RenderBBoxMax.y;
  v18 = this->m_RenderBBoxMin.z - this->m_RenderBBoxMax.z;
  *(_DWORD *)&szModel_172[28] = &this->m_WorldRenderBBoxMax;
  v19 = (float)((float)(v17 * v17) + (float)(v18 * v18)) + (float)(v16 * v16);
  v20 = 0;
  *(_DWORD *)&szModel_172[24] = &this->m_WorldRenderBBoxMin;
  *(float *)&v20 = fsqrt(v19);
  *(_DWORD *)&szModel_172[20] = &this->m_RenderBBoxMax;
  *(_OWORD *)szModel_172 = v20;
  *(_DWORD *)&szModel_172[16] = &this->m_RenderBBoxMin;
  *(_DWORD *)&szModel_172[12] = &this->m_ModelToWorld;
  this->m_flRadius = *(float *)&v20 * 0.5;
  TransformAABB(
    transform: *(const matrix3x4_t **)&szModel_172[12],
    vecMinsIn: *(const Vector **)&szModel_172[16],
    vecMaxsIn: *(const Vector **)&szModel_172[20],
    vecMinsOut: *(Vector **)&szModel_172[24],
    vecMaxsOut: *(Vector **)&szModel_172[28]);
  if ( (lump->m_Flags & 2) != 0 )
    this->m_LightingOrigin = lump->m_LightingOrigin;
  else
    modelinfo->GetIlluminationPoint(
      this: modelinfo,
      a2: this->m_pModel,
      a3: &this->IClientRenderable,
      a4: &this->m_Origin,
      a5: &this->m_Angles,
      a6: &this->m_LightingOrigin);
  v21 = _CommandLine();
  g_MakingDevShots = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v21 + 40))(a1: v21, a2: "-makedevshots") != 0;
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&szModel_172[20] + 124))(a1: *(_DWORD *)&szModel_172[20]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DF720
// Name: public: virtual class Vector const __near & CStaticProp::OBBMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CStaticProp::OBBMins(CStaticProp *this)
{
  Vector *v3; // edi
  float *v4; // eax

  if ( ((int (__thiscall *)(CStaticProp *))this->IClientUnknown::IHandleEntity::__vftable[1].dtr_IHandleEntity)(a1: this) == 6 )
    return (const Vector *)(LODWORD(this->m_Angles.y) + 280);
  v3 = AllocTempVector();
  v4 = (float *)this->GetClientThinkable(this);
  v3->x = this->m_ModelToWorld.m_flMatVal[2][3] - *v4;
  v3->y = this->m_flRadius - v4[1];
  v3->z = this->m_WorldRenderBBoxMin.x - v4[2];
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101DF790
// Name: public: virtual class Vector const __near & CStaticProp::OBBMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CStaticProp::OBBMaxs(CStaticProp *this)
{
  Vector *v3; // edi
  float *v4; // eax

  if ( ((int (__thiscall *)(CStaticProp *))this->IClientUnknown::IHandleEntity::__vftable[1].dtr_IHandleEntity)(a1: this) == 6 )
    return (const Vector *)(LODWORD(this->m_Angles.y) + 292);
  v3 = AllocTempVector();
  v4 = (float *)this->GetClientThinkable(this);
  v3->x = this->m_WorldRenderBBoxMin.y - *v4;
  v3->y = this->m_WorldRenderBBoxMin.z - v4[1];
  v3->z = this->m_WorldRenderBBoxMax.x - v4[2];
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101DF800
// Name: public: virtual class IClientModelRenderable __near * CStaticProp::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CStaticProp::GetClientModelRenderable(CStaticProp *this)
{
  float z; // eax

  z = this->m_Angles.z;
  if ( z == 0.0
    || modelinfoclient->ModelHasMaterialProxy(this: modelinfoclient, a2: (const model_t *)LODWORD(z))
    || IsUsingStaticPropDebugModes()
    || this == (CStaticProp *)4 )
  {
    return nullptr;
  }
  else
  {
    return &this->ICollideable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF870
// Name: private: void CStaticProp::DisplayStaticPropInfo(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CStaticProp::DisplayStaticPropInfo(
        CStaticProp *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int nInfoType)
{
  const char *v6; // eax
  const Vector *v7; // eax
  __int128 v8; // xmm0
  int v9; // eax
  int v10; // esi
  double m_flRadius; // st7
  IClientRenderable_vtbl *v12; // edx
  int v13; // eax
  double v14; // st7
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v18; // [esp+Ch] [ebp-238h]
  char v19[20]; // [esp+18h] [ebp-22Ch] BYREF
  _BYTE buf_456[40]; // [esp+218h] [ebp-2Ch] OVERLAPPED BYREF
  int buf_500; // [esp+244h] [ebp+0h]

  *(_DWORD *)&buf_456[32] = a2;
  *(_DWORD *)&buf_456[36] = buf_500;
  switch ( nInfoType )
  {
    case 1:
      v6 = modelloader->GetName(this: modelloader, a2: this->m_pModel);
      V_snprintf(pDest: v19, maxLen: 512, pFormat: v6);
      break;
    case 2:
      V_snprintf(pDest: v19, maxLen: 512, pFormat: "%d", this->m_EntHandle.m_Index & 0xBFFFFFFF);
      break;
    case 3:
      v7 = this->GetRenderOrigin(this: &this->IClientRenderable);
      v8 = 0;
      *(float *)&v8 = fsqrt(
                        (float)((float)((float)(v7->y - s_StaticPropMgr.m_vecLastViewOrigin.y)
                                      * (float)(v7->y - s_StaticPropMgr.m_vecLastViewOrigin.y))
                              + (float)((float)(v7->z - s_StaticPropMgr.m_vecLastViewOrigin.z)
                                      * (float)(v7->z - s_StaticPropMgr.m_vecLastViewOrigin.z)))
                      + (float)((float)(v7->x - s_StaticPropMgr.m_vecLastViewOrigin.x)
                              * (float)(v7->x - s_StaticPropMgr.m_vecLastViewOrigin.x)));
      *(_OWORD *)buf_456 = v8;
      V_snprintf(pDest: v19, maxLen: 512, pFormat: "%.1f", *(float *)&v8);
      break;
    case 4:
      v9 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a4);
      v10 = v9;
      if ( v9 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
      m_flRadius = this->m_flRadius;
      v12 = this->IClientRenderable::__vftable;
      *(_DWORD *)&buf_456[28] = *(_DWORD *)v10 + 312;
      v18 = m_flRadius;
      v13 = ((int (__cdecl *)(_DWORD))v12->GetRenderOrigin)(a1: LODWORD(v18));
      v14 = ((double (__thiscall *)(int, int))**(_DWORD **)&buf_456[28])(a1: v10, a2: v13);
      V_snprintf(pDest: v19, maxLen: 512, pFormat: "%.1f", v14);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 12))(a1: v10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
      break;
    default:
      break;
  }
  v15 = (float)(this->m_WorldRenderBBoxMin.y + this->m_WorldRenderBBoxMax.y) * 0.5;
  *(float *)&buf_456[16] = (float)(this->m_WorldRenderBBoxMin.x + this->m_WorldRenderBBoxMax.x) * 0.5;
  v16 = this->m_WorldRenderBBoxMax.z + 10.0;
  *(float *)&buf_456[20] = v15;
  *(float *)&buf_456[24] = v16;
  CDebugOverlay::AddTextOverlay(textPos: (const Vector *)&buf_456[16], duration: 0.0, text: v19);
}

//------------------------------------------------------------------------------
// Address: 0x101DFA70
// Name: public: int CStaticProp::DrawModelSlow(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CStaticProp::DrawModelSlow@<eax>(
        CStaticProp *this@<ecx>,
        int a2@<esi>,
        int flags,
        const RenderableInstance_t *instance)
{
  int m_nValue; // eax
  unsigned __int16 v6; // ax
  int v7; // eax
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // esi
  unsigned __int8 m_nSolidType; // cl
  vcollide_t *v11; // eax
  ModelRenderInfo_t sInfo; // [esp+Ch] [ebp-4Ch] BYREF
  unsigned __int16 v14; // [esp+50h] [ebp-8h] BYREF
  _WORD v15[3]; // [esp+52h] [ebp-6h] BYREF
  int _58; // [esp+58h] [ebp+0h] BYREF
  int v17; // [esp+60h] [ebp+8h]
  int v18; // [esp+64h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStaticProp::DrawModel",
    a3: 0,
    a4: "Static_Prop_Rendering",
    a5: false,
    a6: 4);
  if ( r_drawstaticprops.m_pParent == nullptr )
    goto LABEL_29;
  m_nValue = r_drawstaticprops.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    goto LABEL_29;
  if ( m_nValue == 2 || r_slowpathwireframe.m_pParent != nullptr && r_slowpathwireframe.m_pParent->m_Value.m_nValue != 0 )
    flags |= 0x20u;
  if ( instance->m_nAlpha != 0 && this->m_pModel != nullptr )
  {
    if ( r_colorstaticprops.m_pParent != nullptr && r_colorstaticprops.m_pParent->m_Value.m_nValue != 0 )
    {
      v14 = HashBlock(pKey: &this->m_ModelInstance, size: 2u);
      v15[0] = HashBlock(pKey: &v14, size: 2u);
      v6 = HashBlock(pKey: v15, size: 2u);
      r_colormod.x = (float)v14 * 0.000015259022;
      v15[1] = v6;
      r_colormod.y = (float)v15[0] * 0.000015259022;
      r_colormod.z = (float)v6 * 0.000015259022;
      VectorNormalize(vec: &r_colormod);
    }
    v17 = flags | 0x10;
    if ( r_staticpropinfo.m_pParent != nullptr )
    {
      v7 = r_staticpropinfo.m_pParent->m_Value.m_nValue;
      if ( v7 != 0 )
        CStaticProp::DisplayStaticPropInfo(this, a2: (int)&_58, a3: (int)this, a4: (int)instance, nInfoType: v7);
    }
    memset(&sInfo.pModelToWorld, 0, 12);
    CStaticProp::InitModelRenderInfo(this, &sInfo, flags: v17);
    ((void (__thiscall *)(IStudioRender *, Vector *, int))g_pStudioRender->SetColorModulation)(
      a1: g_pStudioRender,
      a2: &r_colormod,
      a3: a2);
    ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: (float)instance->m_nAlpha * 0.0039215689);
    v8 = materials->GetRenderContext(this: materials);
    v9 = v8;
    if ( v8 != nullptr )
      v8->BeginRender(this: v8);
    v9->MatrixMode(this: v9, a2: MATERIAL_MODEL);
    v9->PushMatrix(this: v9);
    v9->LoadIdentity(this: v9);
    v18 = modelrender->DrawModelEx(this: modelrender, a2: &sInfo);
    v9->MatrixMode(this: v9, a2: MATERIAL_MODEL);
    v9->PopMatrix(this: v9);
    if ( this->m_pModel != nullptr && (v17 & 0x100) != 0 )
    {
      m_nSolidType = this->m_nSolidType;
      if ( m_nSolidType == 6 )
      {
        v11 = CM_VCollideForModel(modelindex: -1, pModel: this->m_pModel);
        if ( v11 != nullptr && (*(_WORD *)v11 & 0x7FFF) == 1 )
          DebugDrawPhysCollide(
            pCollide: *v11->solids,
            pMaterial: nullptr,
            transform: &this->m_ModelToWorld,
            color: &debugColor,
            drawAxes: false);
      }
      else if ( m_nSolidType == 2 )
      {
        if ( (_S1_19 & 1) == 0 )
        {
          _S1_19 |= 1u;
          debugColor_0 = (Color)-256;
        }
        RenderWireframeBox(
          vOrigin: &this->m_Origin,
          angles: &vec3_angle,
          vMins: &this->m_pModel->mins,
          vMaxs: &this->m_pModel->maxs,
          c: debugColor_0,
          bZBuffer: true);
      }
    }
    v9->EndRender(this: v9);
    v9->Release(this: v9);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return v18;
  }
  else
  {
LABEL_29:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DFD50
// Name: public: virtual int CStaticProp::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::DrawModel(CStaticProp *this, int flags, const RenderableInstance_t *instance)
{
  IMatRenderContext *v4; // esi
  int v5; // edi
  int v7; // esi
  ModelRenderInfo_t sInfo; // [esp+Ch] [ebp-44h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStaticProp::DrawModel",
    a3: 0,
    a4: "Static_Prop_Rendering",
    a5: false,
    a6: 4);
  if ( instance->m_nAlpha != 0 && LODWORD(this->m_Angles.z) != 0 )
  {
    if ( IsUsingStaticPropDebugModes() || (flags & 0x120) != 0 )
    {
      v7 = CStaticProp::DrawModelSlow(this: (CStaticProp *)((char *)this - 4), flags, instance);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return v7;
    }
    else
    {
      memset(&sInfo.pModelToWorld, 0, 12);
      CStaticProp::InitModelRenderInfo(this: (CStaticProp *)((char *)this - 4), &sInfo, flags: flags | 0x10);
      g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)&r_colormod);
      ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: (float)instance->m_nAlpha * 0.0039215689);
      v4 = materials->GetRenderContext(this: materials);
      if ( v4 != nullptr )
        v4->BeginRender(this: v4);
      v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
      v4->PushMatrix(this: v4);
      v4->LoadIdentity(this: v4);
      v5 = modelrender->DrawModelExStaticProp(this: modelrender, a2: v4, a3: &sInfo);
      v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
      v4->PopMatrix(this: v4);
      v4->EndRender(this: v4);
      v4->Release(this: v4);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return v5;
    }
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DFED0
// Name: private: void CStaticPropMgr::UpdatePropVisibility(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::UpdatePropVisibility(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        BOOL a4@<esi>,
        int nCPULevel,
        int nGPULevel)
{
  CStaticProp *v6; // edi
  bool v7; // al
  unsigned __int8 m_nMinCPULevel; // al
  unsigned __int8 m_nMaxCPULevel; // al
  unsigned __int8 m_nMinGPULevel; // al
  unsigned __int8 m_nMaxGPULevel; // al
  IVModelInfo_vtbl *v12; // ebx
  IClientRenderable *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  IClientLeafSystemEngine_vtbl *v17; // ebx
  IClientLeafSystemEngine_vtbl *v18; // ebx
  unsigned __int16 *v19; // eax
  unsigned __int16 *v20; // eax
  RenderableTranslucencyType_t nType; // [esp+0h] [ebp-10h]
  int m_Size; // [esp+4h] [ebp-Ch]
  CStaticPropMgr *v26; // [esp+8h] [ebp-8h]
  int v27; // [esp+Ch] [ebp-4h]

  v26 = this;
  if ( this->m_bClientInitialized && this->m_StaticProps.m_Size > 0 )
  {
    v27 = 0;
    m_Size = this->m_StaticProps.m_Size;
    while ( 1 )
    {
      v6 = &this->m_StaticProps.m_Memory.m_pMemory[v27];
      v7 = false;
      if ( nCPULevel >= 0 )
      {
        m_nMinCPULevel = v6->m_nMinCPULevel;
        v7 = true;
        if ( m_nMinCPULevel == 0 || m_nMinCPULevel - 1 <= nCPULevel )
        {
          m_nMaxCPULevel = v6->m_nMaxCPULevel;
          if ( m_nMaxCPULevel == 0 || m_nMaxCPULevel - 1 >= nCPULevel )
            v7 = false;
        }
      }
      if ( nGPULevel < 0 )
      {
        if ( v7 )
          goto LABEL_18;
      }
      else if ( v7
             || (m_nMinGPULevel = v6->m_nMinGPULevel) != 0 && m_nMinGPULevel - 1 > nGPULevel
             || (m_nMaxGPULevel = v6->m_nMaxGPULevel) != 0 && m_nMaxGPULevel - 1 < nGPULevel )
      {
LABEL_18:
        if ( v6->m_RenderHandle != 0xFFFF )
        {
          clientleafsystem->RemoveRenderable(this: clientleafsystem, a2: v6->m_RenderHandle);
          v6->m_RenderHandle = -1;
        }
        goto LABEL_20;
      }
      if ( v6->m_LeafCount == 0 )
        goto LABEL_18;
      v12 = modelinfo->__vftable;
      v13 = &v6->IClientRenderable;
      v14 = ((int (__thiscall *)(IClientRenderable *, int, BOOL, int))v6->GetBody)(
              a1: &v6->IClientRenderable,
              a2: a3,
              a3: a4,
              a4: a2);
      v15 = ((int (__thiscall *)(IClientRenderable *, int))v6->GetSkin)(a1: &v6->IClientRenderable, a2: v14);
      v16 = ((int (__thiscall *)(IVModelInfo *, model_t *, int))v12->ComputeTranslucencyType)(
              a1: modelinfo,
              a2: v6->m_pModel,
              a3: v15);
      if ( *(_WORD *)((int (__thiscall *)(IClientRenderable *, int))v6->RenderHandle)(
                       a1: &v6->IClientRenderable,
                       a2: v16) == 0xFFFF )
      {
        a2 = -1;
        ((void (__thiscall *)(IClientLeafSystemEngine *, IClientRenderable *, _DWORD, int, int))clientleafsystem->CreateRenderableHandle)(
          a1: clientleafsystem,
          a2: &v6->IClientRenderable,
          a3: 0,
          a4: v16,
          a5: 2);
        v20 = v13->RenderHandle(this: &v6->IClientRenderable);
        clientleafsystem->AddRenderableToLeaves(
          this: clientleafsystem,
          a2: *v20,
          a3: v6->m_LeafCount,
          a4: (unsigned __int16 *)&v26->m_StaticPropLeaves.m_Memory.m_pMemory[v6->m_FirstLeaf]);
      }
      else
      {
        v17 = clientleafsystem->__vftable;
        a2 = *(unsigned __int16 *)((int (__thiscall *)(IClientRenderable *, RenderableTranslucencyType_t))v13->RenderHandle)(
                                    a1: &v6->IClientRenderable,
                                    a2: nType);
        ((void (__thiscall *)(IClientLeafSystemEngine *))v17->SetTranslucencyType)(a1: clientleafsystem);
      }
      v18 = clientleafsystem->__vftable;
      v19 = v13->RenderHandle(this: &v6->IClientRenderable);
      a4 = (v6->m_Flags & 0x20) != 0;
      a3 = *v19;
      ((void (__thiscall *)(IClientLeafSystemEngine *))v18->RenderInFastReflections)(a1: clientleafsystem);
LABEL_20:
      ++v27;
      if ( --m_Size == 0 )
        return;
      this = v26;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E00A0
// Name: public: virtual void CStaticPropMgr::LevelShutdownClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::LevelShutdownClient(CStaticPropMgr *this)
{
  int v2; // edi
  unsigned int v3; // edi
  CStaticProp *m_pMemory; // esi
  CStaticProp *v5; // esi
  IVModelRender_vtbl *v6; // esi
  unsigned __int16 v7; // ax
  int i; // [esp+4h] [ebp-4h]

  if ( this->m_bClientInitialized )
  {
    v2 = this->m_StaticProps.m_Size - 1;
    i = v2;
    if ( v2 >= 0 )
    {
      v3 = v2;
      do
      {
        m_pMemory = this->m_StaticProps.m_Memory.m_pMemory;
        if ( m_pMemory[v3].m_pClientAlphaProperty != nullptr )
        {
          g_pClientAlphaPropertyMgr->DestroyClientAlphaProperty(
            this: g_pClientAlphaPropertyMgr,
            a2: m_pMemory[v3].m_pClientAlphaProperty);
          m_pMemory[v3].m_pClientAlphaProperty = nullptr;
        }
        v5 = this->m_StaticProps.m_Memory.m_pMemory;
        if ( v5[v3].m_RenderHandle != 0xFFFF )
        {
          clientleafsystem->RemoveRenderable(this: clientleafsystem, a2: v5[v3].m_RenderHandle);
          v5[v3].m_RenderHandle = -1;
        }
        v6 = modelrender->__vftable;
        v7 = ((int (__thiscall *)(IClientRenderable *, _DWORD))this->m_StaticProps.m_Memory.m_pMemory[v3].GetModelInstance)(
               a1: &this->m_StaticProps.m_Memory.m_pMemory[v3].IClientRenderable,
               a2: 0);
        ((void (__thiscall *)(IVModelRender *, _DWORD))v6->SetStaticLighting)(a1: modelrender, a2: v7);
        --v3;
        --i;
      }
      while ( i >= 0 );
    }
    ClearStaticLightingCache();
    this->m_bClientInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0160
// Name: public: virtual void CStaticPropMgr::CreateVPhysicsRepresentations(class IPhysicsEnvironment __near *,class IVPhysicsKeyHandler __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::CreateVPhysicsRepresentations(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        struct CPhysCollide *a3@<esi>,
        IPhysicsEnvironment *pPhysEnv,
        IVPhysicsKeyHandler *pDefaults,
        void *pGameData)
{
  int v6; // edi
  int v7; // eax
  CStaticPropMgr::StaticPropDict_t *m_pElements; // ebx
  char v9; // cl
  char *v10; // ebx
  const model_t *v11; // eax
  vcollide_t *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  struct CPhysCollide *v16; // edi
  IVPhysicsKeyParser *v17; // esi
  const char *v18; // eax
  int v19; // eax
  IVPhysicsKeyParser_vtbl *v20; // edx
  int v21; // eax
  const char *v22; // eax
  int v23; // eax
  int v24; // eax
  IPhysicsEnvironment_vtbl *v25; // edx
  int v26; // eax
  char v27; // bl
  int v28; // esi
  char *v31; // [esp+0h] [ebp-75Ch]
  char *v32; // [esp+4h] [ebp-758h] BYREF
  objectparams_t *v33; // [esp+8h] [ebp-754h]
  char v34[532]; // [esp+404h] [ebp-358h] BYREF
  objectparams_t v35; // [esp+618h] [ebp-144h] BYREF
  char pDest[260]; // [esp+644h] [ebp-118h] BYREF
  int v37; // [esp+748h] [ebp-14h]
  CStaticPropMgr *v38; // [esp+74Ch] [ebp-10h]
  int v39; // [esp+750h] [ebp-Ch]
  int contents; // [esp+754h] [ebp-8h]
  int i; // [esp+758h] [ebp-4h]

  v6 = this->m_StaticProps.m_Memory.m_nGrowSize - 1;
  v38 = this;
  i = v6;
  if ( v6 >= 0 )
  {
    v7 = 200 * v6;
    v39 = 200 * v6;
    while ( 1 )
    {
      m_pElements = this->m_StaticPropDict.m_pElements;
      v9 = *((_BYTE *)&m_pElements[12].m_pModel + v7 + 1);
      v10 = (char *)m_pElements + v7;
      if ( v9 == 0 )
        goto LABEL_31;
      v11 = *((const model_t **)v10 + 10);
      v12 = nullptr;
      contents = -1;
      if ( v11 != nullptr )
      {
        if ( v9 == 6 )
          v12 = CM_VCollideForModel(modelindex: -1, pModel: v11);
        v13 = *((_DWORD *)v10 + 10);
        v14 = *(_DWORD *)(v13 + 272);
        if ( v14 == 3 )
        {
          v15 = *(unsigned __int16 *)(v13 + 312);
          if ( (_WORD)v15 != 0xFFFF )
            contents = mdlcache->GetStudioHdr(this: mdlcache, a2: v15)->contents;
        }
        else if ( v14 == 1 )
        {
          contents = *(_DWORD *)((*(unsigned __int16 *)(v13 + 334) << 6) + *(_DWORD *)(*(_DWORD *)(v13 + 312) + 84));
        }
        if ( v12 != nullptr )
          break;
      }
      v21 = *((_DWORD *)v10 + 10);
      if ( v10[49] == 2 )
      {
        v23 = ((int (__thiscall *)(IPhysicsCollision *, int, int, struct CPhysCollide *, int))physcollision->BBoxToCollide)(
                a1: physcollision,
                a2: v21 + 280,
                a3: v21 + 292,
                a4: a3,
                a5: a2);
        v35 = g_PhysDefaultObjectParams;
        v37 = v23;
        v16 = (struct CPhysCollide *)v23;
LABEL_28:
        v35.pGameData = pGameData;
        v35.enableCollisions = true;
        v35.pName = "prop_static";
        v24 = ((int (__thiscall *)(IPhysicsSurfaceProps *, char *, char *, char *, objectparams_t *))physprops->GetSurfaceIndex)(
                a1: physprops,
                a2: v34,
                a3: v31,
                a4: v32,
                a5: v33);
        v25 = pPhysEnv->__vftable;
        v33 = &v35;
        v32 = v10 + 28;
        v31 = v10 + 16;
        a2 = v24;
        a3 = v16;
        v26 = ((int (__thiscall *)(IPhysicsEnvironment *))v25->CreatePolyObjectStatic)(a1: pPhysEnv);
        v27 = contents;
        v28 = v26;
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v26 + 164))(a1: v26, a2: contents);
        if ( (v27 & 1) != 0 )
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v28 + 336))(a1: v28, a2: 2);
        v6 = i;
        goto LABEL_31;
      }
      if ( v21 != 0 )
        v22 = modelloader->GetName(this: modelloader, a2: *((_DWORD *)v10 + 10));
      else
        v22 = "unknown model";
      V_strncpy(pDest, pSrc: v22, maxLen: 260);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_StaticPropManager,
          a2: 1,
          a3: "Map Error:  Static prop with bogus solid type %d! (%s)\n",
          (unsigned __int8)v10[49],
          pDest);
      v10[49] = 0;
LABEL_31:
      --v6;
      v7 = v39 - 200;
      i = v6;
      v39 -= 200;
      if ( v6 < 0 )
        return;
      this = v38;
    }
    v16 = *v12->solids;
    v17 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, struct CPhysCollide *, int))physcollision->VPhysicsKeyParserCreate)(
                                  a1: physcollision,
                                  a2: v12,
                                  a3,
                                  a4: a2);
    if ( !v17->Finished(this: v17) )
    {
      while ( 1 )
      {
        v18 = v17->GetCurrentBlockName(this: v17);
        v19 = _V_stricmp(s1: v18, s2: "solid");
        v20 = v17->__vftable;
        if ( v19 == 0 )
          break;
        v20->SkipBlock(this: v17);
        if ( v17->Finished(this: v17) )
          goto LABEL_19;
      }
      v20->ParseSolid(this: v17, a2: (solid_t *)&v32, a3: pDefaults);
    }
LABEL_19:
    physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v17);
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E03F0
// Name: public: virtual class ICollideable __near * CStaticPropMgr::GetStaticProp(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CStaticPropMgr::GetStaticProp(CStaticPropMgr *this, IHandleEntity *pHandleEntity)
{
  signed int m_Index; // eax
  CStaticProp *v4; // eax

  if ( pHandleEntity != nullptr )
  {
    if ( (pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index & 0xFFFF0000) != 0x40000000 )
      return nullptr;
    m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
    if ( m_Index == -1 )
      m_Index = 0x1FFF;
    else
      m_Index = (unsigned __int16)m_Index;
  }
  else
  {
    m_Index = -1;
  }
  if ( m_Index >= 0 && m_Index <= this->m_StaticProps.m_Size )
  {
    v4 = &this->m_StaticProps.m_Memory.m_pMemory[m_Index];
    if ( v4 != nullptr )
      return &v4->ICollideable;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E0460
// Name: public: virtual class ICollideable __near * CStaticPropMgr::GetStaticPropByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CStaticPropMgr::StaticPropDict_t *__thiscall CStaticPropMgr::GetStaticPropByIndex(CStaticPropMgr *this, int propIndex)
{
  CStaticPropMgr::StaticPropDict_t *v2; // eax

  if ( propIndex < this->m_StaticProps.m_Memory.m_nGrowSize
    && (v2 = &this->m_StaticPropDict.m_pElements[50 * propIndex]) != nullptr )
  {
    return v2 + 2;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0490
// Name: private: void CStaticPropMgr::PrecacheLighting(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStaticPropMgr::PrecacheLighting(CStaticPropMgr *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CStaticPropMgr *v3; // esi
  int v4; // ebx
  IMDLCache *v5; // edi
  CStaticProp *v6; // esi
  IEngineVGuiInternal *v7; // eax
  LightCacheHandle_t__ *StaticLightingCache; // [esp+4h] [ebp-Ch] BYREF
  CStaticPropMgr *v11; // [esp+8h] [ebp-8h]
  int m_Size; // [esp+Ch] [ebp-4h]

  v3 = this;
  v11 = this;
  _COM_TimestampedLog(a1: "CStaticPropMgr::PrecacheLighting - start");
  if ( v3->m_StaticProps.m_Size > 0 )
  {
    v4 = 0;
    m_Size = v3->m_StaticProps.m_Size;
    while ( 1 )
    {
      v5 = g_pMDLCache;
      ((void (__thiscall *)(IMDLCache *, int, int))g_pMDLCache->BeginLock)(a1: g_pMDLCache, a2: a3, a3: a2);
      v6 = &v3->m_StaticProps.m_Memory.m_pMemory[v4];
      if ( v6->m_ModelInstance == 0xFFFF )
      {
        StaticLightingCache = CreateStaticLightingCache(
                                origin: &v6->m_LightingOrigin,
                                mins: &v6->m_WorldRenderBBoxMin,
                                maxs: &v6->m_WorldRenderBBoxMax);
        v6->m_ModelInstance = modelrender->CreateInstance(
                                this: modelrender,
                                a2: &v6->IClientRenderable,
                                a3: &StaticLightingCache);
      }
      v7 = EngineVGui();
      a2 = 1;
      a3 = 24;
      ((void (__thiscall *)(IEngineVGuiInternal *))v7->UpdateProgressBar)(a1: v7);
      v5->EndLock(this: v5);
      ++v4;
      if ( --m_Size == 0 )
        break;
      v3 = v11;
    }
  }
  _COM_TimestampedLog(a1: "CStaticPropMgr::PrecacheLighting - end");
}

//------------------------------------------------------------------------------
// Address: 0x101E0560
// Name: public: virtual void CStaticPropMgr::RecomputeStaticLighting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::RecomputeStaticLighting(CStaticPropMgr *this)
{
  int v2; // edi
  int v3; // esi

  v2 = this->m_StaticProps.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      if ( *this->m_StaticProps.m_Memory.m_pMemory[v3].RenderHandle(this: &this->m_StaticProps.m_Memory.m_pMemory[v3].IClientRenderable) != 0xFFFF )
        ((void (__stdcall *)(_DWORD))modelrender->RecomputeStaticLighting)(a1: this->m_StaticProps.m_Memory.m_pMemory[v3].m_ModelInstance);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E05B0
// Name: public: virtual bool CStaticPropMgr::IsPropInPVS(class IHandleEntity __near *,unsigned char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticPropMgr::IsPropInPVS(
        CStaticPropMgr *this,
        IHandleEntity *pHandleEntity,
        const unsigned __int8 *pVis)
{
  unsigned int m_Index; // eax
  CStaticProp *v5; // eax
  unsigned int m_FirstLeaf; // esi
  unsigned int v7; // edi
  int v8; // eax

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index == -1 )
    m_Index = 0x1FFF;
  else
    m_Index = (unsigned __int16)m_Index;
  v5 = &this->m_StaticProps.m_Memory.m_pMemory[m_Index];
  m_FirstLeaf = v5->m_FirstLeaf;
  v7 = m_FirstLeaf + v5->m_LeafCount;
  if ( m_FirstLeaf >= v7 )
    return 0;
  while ( 1 )
  {
    v8 = CM_LeafCluster(leafnum: this->m_StaticPropLeaves.m_Memory.m_pMemory[m_FirstLeaf].m_Leaf);
    if ( ((unsigned __int8)(1 << (v8 & 7)) & pVis[v8 >> 3]) != 0 )
      break;
    if ( (int)++m_FirstLeaf >= (int)v7 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E0640
// Name: public: void CStaticPropMgr::DrawStaticProps_Slow(class IClientRenderable __near * __near *,struct RenderableInstance_t const __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::DrawStaticProps_Slow(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        IClientRenderable **pProps,
        const RenderableInstance_t *pInstances,
        int count,
        bool bShadowDepth,
        bool drawVCollideWireframe)
{
  IMDLCache *v7; // edi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  IClientRenderable *v9; // edi
  CStaticProp *v10; // edi
  int v11; // ebx
  int m_nValue; // eax
  unsigned __int16 v13; // ax
  int v14; // ebx
  int v15; // eax
  IMatRenderContext *v16; // esi
  unsigned __int8 m_nSolidType; // cl
  vcollide_t *v18; // eax
  ModelRenderInfo_t sInfo; // [esp+Ch] [ebp-54h] BYREF
  unsigned __int16 v21; // [esp+50h] [ebp-10h] BYREF
  _WORD v22[3]; // [esp+52h] [ebp-Eh] BYREF
  IMDLCache *v23; // [esp+58h] [ebp-8h]
  int v24; // [esp+5Ch] [ebp-4h]
  int _60; // [esp+60h] [ebp+0h] BYREF
  int v26; // [esp+74h] [ebp+14h]

  v7 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  v23 = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  v24 = 1;
  if ( bShadowDepth )
    v24 = 1073741825;
  if ( drawVCollideWireframe )
    v24 |= 0x100u;
  v26 = 0;
  if ( count > 0 )
  {
    do
    {
      v9 = pProps[v26];
      if ( v9 != nullptr )
        v10 = (CStaticProp *)&v9[-1];
      else
        v10 = nullptr;
      v11 = v24;
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "CStaticProp::DrawModel",
        a3: 0,
        a4: "Static_Prop_Rendering",
        a5: false,
        a6: 4);
      if ( r_drawstaticprops.m_pParent == nullptr )
        goto LABEL_36;
      m_nValue = r_drawstaticprops.m_pParent->m_Value.m_nValue;
      if ( m_nValue == 0 )
        goto LABEL_36;
      if ( m_nValue == 2
        || r_slowpathwireframe.m_pParent != nullptr && r_slowpathwireframe.m_pParent->m_Value.m_nValue != 0 )
      {
        v11 = v24 | 0x20;
      }
      if ( pInstances[v26].m_nAlpha != 0 && v10->m_pModel != nullptr )
      {
        if ( r_colorstaticprops.m_pParent != nullptr && r_colorstaticprops.m_pParent->m_Value.m_nValue != 0 )
        {
          v21 = HashBlock(pKey: &v10->m_ModelInstance, size: 2u);
          v22[0] = HashBlock(pKey: &v21, size: 2u);
          v13 = HashBlock(pKey: v22, size: 2u);
          r_colormod.x = (float)v21 * 0.000015259022;
          v22[1] = v13;
          r_colormod.y = (float)v22[0] * 0.000015259022;
          r_colormod.z = (float)v13 * 0.000015259022;
          VectorNormalize(vec: &r_colormod);
        }
        v14 = v11 | 0x10;
        if ( r_staticpropinfo.m_pParent != nullptr )
        {
          v15 = r_staticpropinfo.m_pParent->m_Value.m_nValue;
          if ( v15 != 0 )
            CStaticProp::DisplayStaticPropInfo(this: v10, a2: (int)&_60, a3: (int)v10, a4: 0, nInfoType: v15);
        }
        memset(&sInfo.pModelToWorld, 0, 12);
        CStaticProp::InitModelRenderInfo(this: v10, &sInfo, flags: v14);
        ((void (__thiscall *)(IStudioRender *, Vector *, int))g_pStudioRender->SetColorModulation)(
          a1: g_pStudioRender,
          a2: &r_colormod,
          a3: a2);
        ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: (float)pInstances[v26].m_nAlpha * 0.0039215689);
        v16 = materials->GetRenderContext(this: materials);
        if ( v16 != nullptr )
          v16->BeginRender(this: v16);
        a2 = 10;
        ((void (__thiscall *)(IMatRenderContext *))v16->MatrixMode)(a1: v16);
        v16->PushMatrix(this: v16);
        v16->LoadIdentity(this: v16);
        modelrender->DrawModelEx(this: modelrender, a2: &sInfo);
        v16->MatrixMode(this: v16, a2: MATERIAL_MODEL);
        v16->PopMatrix(this: v16);
        if ( v10->m_pModel != nullptr && (v14 & 0x100) != 0 )
        {
          m_nSolidType = v10->m_nSolidType;
          if ( m_nSolidType == 6 )
          {
            v18 = CM_VCollideForModel(modelindex: -1, pModel: v10->m_pModel);
            if ( v18 != nullptr && (*(_WORD *)v18 & 0x7FFF) == 1 )
              DebugDrawPhysCollide(
                pCollide: *v18->solids,
                pMaterial: nullptr,
                transform: &v10->m_ModelToWorld,
                color: &debugColor,
                drawAxes: false);
          }
          else if ( m_nSolidType == 2 )
          {
            if ( (_S1_19 & 1) == 0 )
            {
              _S1_19 |= 1u;
              debugColor_0 = (Color)-256;
            }
            RenderWireframeBox(
              vOrigin: &v10->m_Origin,
              angles: &vec3_angle,
              vMins: &v10->m_pModel->mins,
              vMaxs: &v10->m_pModel->maxs,
              c: debugColor_0,
              bZBuffer: true);
          }
        }
        v16->EndRender(this: v16);
        v16->Release(this: v16);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      else
      {
LABEL_36:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      ++v26;
    }
    while ( v26 < count );
    v7 = v23;
  }
  v7->EndLock(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101E0980
// Name: public: void CStaticPropMgr::DrawStaticProps_Fast(class IClientRenderable __near * __near *,struct RenderableInstance_t const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::DrawStaticProps_Fast(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IClientRenderable **pProps,
        const RenderableInstance_t *pInstances,
        int count,
        bool bShadowDepth)
{
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // edi
  int v9; // ebx
  IMDLCache *v10; // esi
  IClientRenderable *v11; // ecx
  IClientRenderable *v12; // eax
  IClientRenderable_vtbl *v13; // [esp+4h] [ebp-50h] BYREF
  IClientRenderable_vtbl *v14; // [esp+8h] [ebp-4Ch]
  IClientRenderable_vtbl *v15; // [esp+Ch] [ebp-48h]
  IClientRenderable_vtbl *v16; // [esp+10h] [ebp-44h]
  ModelRenderInfo_t sInfo; // [esp+14h] [ebp-40h] BYREF

  sInfo.hitboxset = 1065353216;
  sInfo.body = 1065353216;
  sInfo.skin = 1065353216;
  ((void (__thiscall *)(IStudioRender *, int *, int, int))g_pStudioRender->SetColorModulation)(
    a1: g_pStudioRender,
    a2: &sInfo.skin,
    a3,
    a4: a2);
  ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: 1.0);
  g_pStudioRender->SetViewState(
    this: g_pStudioRender,
    a2: &g_CurrentViewOrigin,
    a3: &g_CurrentViewRight,
    a4: &g_CurrentViewUp,
    a5: &g_CurrentViewForward);
  v7 = materials->GetRenderContext(this: materials);
  v8 = v7;
  v9 = 0;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v8->MatrixMode(this: v8, a2: MATERIAL_MODEL);
  v8->PushMatrix(this: v8);
  v8->LoadIdentity(this: v8);
  sInfo.angles.y = 0.0;
  sInfo.pRenderable = nullptr;
  sInfo.pModel = (const model_t *)17;
  if ( bShadowDepth )
    sInfo.pModel = (const model_t *)1073741841;
  sInfo.pModelToWorld = (const matrix3x4_t *)-1;
  sInfo.pLightingOrigin = nullptr;
  sInfo.flags = 0;
  sInfo.angles.z = 0.0;
  if ( count > 0 )
  {
    do
    {
      v10 = g_pMDLCache;
      g_pMDLCache->BeginLock(this: g_pMDLCache);
      v11 = pProps[v9];
      if ( v11 != nullptr )
        v12 = v11 - 1;
      else
        v12 = nullptr;
      if ( v12[10].__vftable != nullptr )
      {
        LOWORD(sInfo.entity_index) = HIWORD(v12[11].__vftable);
        LODWORD(sInfo.angles.x) = (IClientRenderable)v12[10].__vftable;
        v13 = v12[4].__vftable;
        v14 = v12[5].__vftable;
        v15 = v12[6].__vftable;
        v16 = v12[7].__vftable;
        LODWORD(sInfo.origin.x) = (IClientRenderable)v12[8].__vftable;
        LODWORD(sInfo.origin.y) = (IClientRenderable)v12[9].__vftable;
        sInfo.pLightingOffset = (const matrix3x4_t *)BYTE2(v12[12].__vftable);
        sInfo.pRenderable = v12 + 43;
        LODWORD(sInfo.origin.z) = v11;
        LODWORD(sInfo.angles.y) = &v12[24];
        modelrender->DrawModelExStaticProp(this: modelrender, a2: v8, a3: (ModelRenderInfo_t *)&v13);
      }
      v10->EndLock(this: v10);
      ++v9;
    }
    while ( v9 < count );
  }
  ((void (__thiscall *)(IMatRenderContext *, int, IClientRenderable_vtbl *, IClientRenderable_vtbl *, IClientRenderable_vtbl *, IClientRenderable_vtbl *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IClientRenderable *, const model_t *, const matrix3x4_t *, const matrix3x4_t *, const Vector *, int, int, int))v8->MatrixMode)(
    a1: v8,
    a2: 10,
    a3: v13,
    a4: v14,
    a5: v15,
    a6: v16,
    a7: LODWORD(sInfo.origin.x),
    a8: LODWORD(sInfo.origin.y),
    a9: LODWORD(sInfo.origin.z),
    a10: LODWORD(sInfo.angles.x),
    a11: LODWORD(sInfo.angles.y),
    a12: LODWORD(sInfo.angles.z),
    a13: sInfo.pRenderable,
    a14: sInfo.pModel,
    a15: sInfo.pModelToWorld,
    a16: sInfo.pLightingOffset,
    a17: sInfo.pLightingOrigin,
    a18: sInfo.flags,
    a19: sInfo.entity_index,
    a20: sInfo.skin);
  v8->PopMatrix(this: v8);
  v8->EndRender(this: v8);
  v8->Release(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x101E0B40
// Name: public: virtual void CStaticPropMgr::DrawStaticProps(class IClientRenderable __near * __near *,struct RenderableInstance_t const __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::DrawStaticProps(
        CStaticPropMgr *this,
        IClientRenderable **pProps,
        const RenderableInstance_t *pInstances,
        int count,
        bool bShadowDepth,
        bool drawVCollideWireframe)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStaticPropMgr::DrawStaticProps",
    a3: 0,
    a4: "Static_Prop_Rendering",
    a5: false,
    a6: 4);
  if ( r_drawstaticprops.m_pParent == nullptr
    || r_drawstaticprops.m_pParent->m_Value.m_nValue == 0
    || cl_skipslowpath.m_pParent != nullptr && cl_skipslowpath.m_pParent->m_Value.m_nValue != 0 )
  {
    goto LABEL_14;
  }
  if ( IsUsingStaticPropDebugModes()
    || drawVCollideWireframe
    || r_slowpathwireframe.m_pParent != nullptr && r_slowpathwireframe.m_pParent->m_Value.m_nValue != 0 )
  {
    CStaticPropMgr::DrawStaticProps_Slow(
      this: (CStaticPropMgr *)((char *)this - 4),
      pProps,
      pInstances,
      count,
      bShadowDepth,
      drawVCollideWireframe);
LABEL_14:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  if ( pipeline_static_props.m_pParent != nullptr && pipeline_static_props.m_pParent->m_Value.m_nValue != 0 )
  {
    CStaticPropMgr::DrawStaticProps_FastPipeline(
      this: (CStaticPropMgr *)((char *)this - 4),
      pProps,
      pInstances,
      count,
      bShadowDepth);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CStaticPropMgr::DrawStaticProps_Fast(
      this: (CStaticPropMgr *)((char *)this - 4),
      pProps,
      pInstances,
      count,
      bShadowDepth);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0C40
// Name: public: virtual struct LightCacheHandle_t__ __near * CStaticPropMgr::GetLightCacheHandleForStaticProp(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
LightCacheHandle_t__ *__thiscall CStaticPropMgr::GetLightCacheHandleForStaticProp(
        CStaticPropMgr *this,
        IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CStaticProp *m_pMemory; // ecx
  IVModelRender_vtbl *v5; // esi
  unsigned __int16 v6; // ax

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index == -1 )
    m_Index = 0x1FFF;
  else
    m_Index = (unsigned __int16)m_Index;
  m_pMemory = this->m_StaticProps.m_Memory.m_pMemory;
  v5 = modelrender->__vftable;
  v6 = m_pMemory[m_Index].GetModelInstance(this: &m_pMemory[m_Index].IClientRenderable);
  return v5->GetStaticLighting(this: modelrender, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101E0CA0
// Name: public: virtual void CStaticPropMgr::TraceRayAgainstStaticProp(struct Ray_t const __near &,int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CStaticPropMgr::TraceRayAgainstStaticProp(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        int staticPropIndex,
        CGameTrace *tr)
{
  _BYTE v7[92]; // [esp-Ch] [ebp-6Ch] OVERLAPPED BYREF
  CStaticPropMgr::StaticPropDict_t *v8; // [esp+50h] [ebp-10h]
  int v9; // [esp+54h] [ebp-Ch]
  void *v10; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v9 = a2;
  v10 = retaddr;
  v8 = &this->m_StaticPropDict.m_pElements[50 * staticPropIndex];
  if ( (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, int, int))&v8[2].m_pModel->szPathName[40])(
         a1: v8 + 2,
         a2: a3,
         a3: a4) != 0 )
  {
    *(Ray_t *)v7 = *ray;
    *(float *)&v7[16] = *(float *)&v7[16] * 1.1;
    *(_DWORD *)&v7[88] = tr;
    *(float *)&v7[20] = *(float *)&v7[20] * 1.1;
    *(_DWORD *)&v7[84] = v8;
    *(float *)&v7[24] = *(float *)&v7[24] * 1.1;
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, int))g_pEngineTraceClient->ClipRayToEntity)(
      a1: g_pEngineTraceClient,
      a2: v7,
      a3: -1);
  }
  else
  {
    tr->fraction = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0D60
// Name: public: virtual void CStaticPropMgr::AddDecalToStaticProp(class Vector const __near &,class Vector const __near &,int,int,bool,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::AddDecalToStaticProp(
        CStaticPropMgr *this@<ecx>,
        float a2@<ebp>,
        const Vector *rayStart,
        const Vector *rayEnd,
        int staticPropIndex,
        int decalIndex,
        bool doTrace,
        CGameTrace *tr)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  CStaticPropMgr::StaticPropDict_t *v13; // esi
  IVModelRender_vtbl *v14; // edi
  unsigned __int16 v15; // ax
  _DWORD v16[3]; // [esp-Ch] [ebp-7Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-70h] BYREF
  int v18; // [esp+50h] [ebp-20h]
  Vector up; // [esp+54h] [ebp-1Ch] BYREF
  Vector temp; // [esp+60h] [ebp-10h]
  float retaddr; // [esp+70h] [ebp+0h]

  temp.y = a2;
  temp.z = retaddr;
  LODWORD(temp.x) = this;
  if ( staticPropIndex >= this->m_StaticProps.m_Memory.m_nGrowSize )
  {
    memset(dst: (unsigned __int8 *)tr, value: 0, count: sizeof(CGameTrace));
    tr->fraction = 1.0;
    return;
  }
  x = rayStart->x;
  y = rayStart->y;
  z = rayStart->z;
  v11 = rayEnd->z;
  v12 = rayEnd->x - rayStart->x;
  ray.m_Start.z = rayEnd->y - y;
  ray.m_Start.y = v12;
  ray.m_Start.w = v11 - z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z) + (float)(v12 * v12))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_Delta.y, 0, 12);
  *(float *)v16 = x;
  *(float *)&v16[1] = y;
  *(float *)&v16[2] = z;
  if ( doTrace )
  {
    ((void (__thiscall *)(CStaticPropMgr *, _DWORD *, int, CGameTrace *))this->Shutdown)(
      a1: this,
      a2: v16,
      a3: staticPropIndex,
      a4: tr);
    if ( tr->fraction == 1.0 )
      return;
    this = (CStaticPropMgr *)LODWORD(temp.x);
  }
  if ( r_drawmodeldecals.m_pParent != nullptr && r_drawmodeldecals.m_pParent->m_Value.m_nValue != 0 )
  {
    v13 = &this->m_StaticPropDict.m_pElements[50 * staticPropIndex];
    LOBYTE(temp.x) = 0;
    if ( doTrace
      && (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *))&v13[2].m_pModel->szPathName[40])(a1: v13 + 2) == 6
      && !tr->startsolid
      && !tr->allsolid )
    {
      up.x = tr->endpos.x - tr->plane.normal.x;
      up.y = tr->endpos.y - tr->plane.normal.y;
      up.z = tr->endpos.z - tr->plane.normal.z;
      Ray_t::Init(this: (Ray_t *)v16, start: &tr->endpos, end: &up);
      LOBYTE(temp.x) = 1;
    }
    *(_DWORD *)(&ray.m_IsSwept + 3) = 0;
    *(_DWORD *)(&ray.m_IsSwept + 7) = 0;
    v18 = 1065353216;
    v14 = modelrender->__vftable;
    v15 = (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, _DWORD *, bool *, int, _DWORD, _DWORD, int))&v13[1].m_pModel->szPathName[120])(
            a1: v13 + 1,
            a2: v16,
            a3: &ray.m_IsSwept + 3,
            a4: decalIndex,
            a5: 0,
            a6: LODWORD(temp.x),
            a7: -1);
    ((void (__thiscall *)(IVModelRender *, _DWORD))v14->AddDecal)(a1: modelrender, a2: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0F60
// Name: public: virtual void CStaticPropMgr::GetStaticPropMaterialColorAndLighting(class CGameTrace __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetStaticPropMaterialColorAndLighting(
        CStaticPropMgr *this,
        CGameTrace *pTrace,
        int staticPropIndex,
        Vector *lighting,
        Vector *matColor)
{
  IVModelInfoClient_vtbl *v5; // edi
  CStaticPropMgr::StaticPropDict_t *v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax

  if ( staticPropIndex < this->m_StaticProps.m_Memory.m_nGrowSize )
  {
    v5 = modelinfoclient->__vftable;
    v6 = &this->m_StaticPropDict.m_pElements[50 * staticPropIndex + 1];
    v7 = (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, CGameTrace *, Vector *, Vector *))&v6->m_pModel->szPathName[4])(
           a1: v6,
           a2: pTrace,
           a3: lighting,
           a4: matColor);
    v8 = (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, int))v6->m_pModel->szPathName)(a1: v6, a2: v7);
    v9 = (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, int))&v6->m_pModel->szPathName[28])(a1: v6, a2: v8);
    ((void (__thiscall *)(IVModelInfoClient *, int))v5->GetModelMaterialColorAndLighting)(a1: modelinfoclient, a2: v9);
  }
  else
  {
    lighting->x = 0.0;
    lighting->y = 0.0;
    lighting->z = 0.0;
    matColor->x = 1.0;
    matColor->y = 1.0;
    matColor->z = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0FF0
// Name: void Cmd_PropCrosshair_f(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Cmd_PropCrosshair_f(int a1@<ebp>)
{
  int v1; // [esp-Ch] [ebp-C4h] BYREF
  _BYTE tr_68[20]; // [esp+44h] [ebp-74h] OVERLAPPED BYREF
  Ray_t ray; // [esp+58h] [ebp-60h] BYREF
  _DWORD v4[3]; // [esp+A8h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+B8h] [ebp+0h]

  v4[1] = a1;
  v4[2] = retaddr;
  ray.m_Start.z = (float)((float)(*(float *)&dword_104F1BF8 * 57016.32) + g_MainViewOrigin[0].y) - g_MainViewOrigin[0].y;
  ray.m_Start.y = (float)((float)(g_MainViewForward[0].x * 57016.32) + g_MainViewOrigin[0].x) - g_MainViewOrigin[0].x;
  ray.m_Start.w = (float)((float)(*(float *)&dword_104F1BFC * 57016.32) + g_MainViewOrigin[0].z) - g_MainViewOrigin[0].z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                         + (float)(ray.m_Start.y * ray.m_Start.y))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  memset(&ray.m_Delta.y, 0, 12);
  *(Vector *)&tr_68[8] = g_MainViewOrigin[0];
  v4[0] = &CTraceFilterWorldAndPropsOnly::`vftable';
  g_pEngineTraceServer->TraceRay(
    this: g_pEngineTraceServer,
    a2: (const Ray_t *)&tr_68[8],
    a3: -1u,
    a4: (ITraceFilter *)v4,
    a5: (CGameTrace *)&v1);
  if ( *(int *)tr_68 <= 0 )
    _Msg(a1: "didn't hit a prop\n");
  else
    _Msg(a1: "hit prop %d\n", *(_DWORD *)tr_68 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x101E1130
// Name: public: virtual void CStaticPropMgr::ConfigureSystemLevel(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::ConfigureSystemLevel(CStaticPropMgr *this, int nCPULevel, int nGPULevel)
{
  bool v3; // zf

  if ( nCPULevel != this->m_nLastCPULevel || nGPULevel != this->m_nLastGPULevel )
  {
    v3 = !this->m_bClientInitialized;
    this->m_nLastCPULevel = nCPULevel;
    this->m_nLastGPULevel = nGPULevel;
    if ( !v3 )
      CStaticPropMgr::UpdatePropVisibility(this, nCPULevel, nGPULevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1160
// Name: public: virtual void CStaticPropMgr::RestoreStaticProps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::RestoreStaticProps(CStaticPropMgr *this)
{
  CStaticPropMgr::UpdatePropVisibility(this, nCPULevel: this->m_nLastCPULevel, nGPULevel: this->m_nLastGPULevel);
  this->RecomputeStaticLighting(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E1180
// Name: public: virtual void CStaticPropMgr::LevelInitClient(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStaticPropMgr::LevelInitClient(CStaticPropMgr *this@<ecx>, int a2@<edi>)
{
  int m_nValue; // eax
  int m_Size; // eax
  char *v5; // edi
  float *v6; // eax
  IModelLoader_vtbl *v7; // esi
  int v8; // eax
  const char *v9; // eax
  double v10; // [esp-4h] [ebp-3Ch]
  double v11; // [esp+4h] [ebp-34h]
  _BYTE v12[12]; // [esp+Ch] [ebp-2Ch]
  int m_nLastCPULevel; // [esp+14h] [ebp-24h]
  int m_nLastGPULevel; // [esp+18h] [ebp-20h]
  float v15; // [esp+20h] [ebp-18h]
  float v16; // [esp+24h] [ebp-14h]
  float v17; // [esp+28h] [ebp-10h]
  __int64 v18; // [esp+2Ch] [ebp-Ch]
  bool v19; // [esp+37h] [ebp-1h]

  if ( !sv.m_bIsDedicated )
  {
    if ( r_proplightingfromdisk.m_pParent != nullptr )
      m_nValue = r_proplightingfromdisk.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v19 = m_nValue != 0;
    if ( m_nValue != 0 )
      g_pFileSystem->BeginMapAccess(this: g_pFileSystem);
    m_Size = this->m_StaticProps.m_Size;
    if ( m_Size > 0 )
    {
      v18 = (unsigned int)m_Size;
      *(_DWORD *)&v12[8] = a2;
      do
      {
        v5 = (char *)this->m_StaticProps.m_Memory.m_pMemory + HIDWORD(v18);
        if ( *((_WORD *)v5 + 29) == 0 )
        {
          v6 = (float *)(*(int (__thiscall **)(char *, _DWORD))(*((_DWORD *)v5 + 2) + 32))(
                          a1: v5 + 8,
                          a2: *(_DWORD *)&v12[8]);
          v16 = v6[1];
          v15 = *v6;
          v17 = v6[2];
          (*(void (__thiscall **)(char *))(*((_DWORD *)v5 + 2) + 4))(a1: v5 + 8);
          (*(void (__thiscall **)(char *))(*((_DWORD *)v5 + 2) + 8))(a1: v5 + 8);
          v7 = modelloader->__vftable;
          *(double *)&v12[4] = v17;
          v8 = (*(int (__thiscall **)(char *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*((_DWORD *)v5 + 1) + 32))(
                 a1: v5 + 4,
                 a2: COERCE_UNSIGNED_INT64(v15),
                 a3: HIDWORD(COERCE_UNSIGNED_INT64(v15)),
                 a4: COERCE_UNSIGNED_INT64(v16),
                 a5: HIDWORD(COERCE_UNSIGNED_INT64(v16)),
                 a6: COERCE_UNSIGNED_INT64(v17));
          v9 = v7->GetName(this: modelloader, a2: (const model_t *)v8);
          _DevMsg(a1: 1, a2: "Static prop in 0 leaves! %s, @ %.1f, %.1f, %.1f\n", v9, v10, v11, *(double *)v12);
        }
        HIDWORD(v18) += 200;
        LODWORD(v18) = v18 - 1;
      }
      while ( (_DWORD)v18 != 0 );
    }
    m_nLastGPULevel = this->m_nLastGPULevel;
    m_nLastCPULevel = this->m_nLastCPULevel;
    this->m_bClientInitialized = true;
    CStaticPropMgr::UpdatePropVisibility(this, nCPULevel: m_nLastCPULevel, nGPULevel: m_nLastGPULevel);
    CStaticPropMgr::PrecacheLighting(this);
    if ( v19 )
      g_pFileSystem->EndMapAccess(this: g_pFileSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1370
// Name: private: void CStaticPropMgr::UnserializeLeafList(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::UnserializeLeafList(CStaticPropMgr *this, CUtlBuffer *buf)
{
  int Int; // eax
  bool v4; // sf
  int v5; // edi

  Int = CUtlBuffer::GetInt(this: buf);
  v4 = this->m_StaticPropLeaves.m_Memory.m_nGrowSize < 0;
  v5 = Int;
  this->m_StaticPropLeaves.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_StaticPropLeaves.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StaticPropLeaves.m_Memory.m_pMemory);
      this->m_StaticPropLeaves.m_Memory.m_pMemory = nullptr;
    }
    this->m_StaticPropLeaves.m_Memory.m_nAllocationCount = 0;
  }
  this->m_StaticPropLeaves.m_pElements = this->m_StaticPropLeaves.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&this->m_StaticPropLeaves,
      elem: this->m_StaticPropLeaves.m_Size,
      num: v5);
    CUtlBuffer::Get(this: buf, pMem: this->m_StaticPropLeaves.m_Memory.m_pMemory, size: 2 * v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E13E0
// Name: public: virtual void CStaticPropMgr::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::LevelShutdown(CStaticPropMgr *this)
{
  if ( this->m_bLevelInitialized )
  {
    if ( this->m_bClientInitialized )
      this->LevelShutdownClient(this);
    this->m_bLevelInitialized = false;
    CUtlVector<CStaticProp,CUtlMemory<CStaticProp,int>>::Purge(this: &this->m_StaticProps);
    this->m_StaticPropDict.m_Size = 0;
    if ( this->m_StaticPropDict.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_StaticPropDict.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StaticPropDict.m_Memory.m_pMemory);
        this->m_StaticPropDict.m_Memory.m_pMemory = nullptr;
      }
      this->m_StaticPropDict.m_Memory.m_nAllocationCount = 0;
    }
    this->m_StaticPropDict.m_pElements = this->m_StaticPropDict.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E14A0
// Name: public: virtual CStaticPropMgr::~CStaticPropMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::~CStaticPropMgr(CStaticPropMgr *this)
{
  this->IStaticPropMgrEngine::__vftable = (CStaticPropMgr_vtbl *)&CStaticPropMgr::`vftable'{for `IStaticPropMgrEngine'};
  this->IStaticPropMgrClient::IStaticPropMgr::__vftable = (IStaticPropMgrClient_vtbl *)&CStaticPropMgr::`vftable'{for `IStaticPropMgrClient'};
  this->IStaticPropMgrServer::IStaticPropMgr::__vftable = (IStaticPropMgrServer_vtbl *)&CStaticPropMgr::`vftable'{for `IStaticPropMgrServer'};
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_StaticPropLeaves);
  CUtlVector<CStaticProp,CUtlMemory<CStaticProp,int>>::Purge(this: &this->m_StaticProps);
  if ( this->m_StaticProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_StaticProps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StaticProps.m_Memory.m_pMemory);
      this->m_StaticProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_StaticProps.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_StaticPropDict);
}

//------------------------------------------------------------------------------
// Address: 0x101E1500
// Name: private: void CStaticPropMgr::UnserializeModelDict(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::UnserializeModelDict(CStaticPropMgr *this, CUtlBuffer *buf)
{
  int Int; // edi
  int m_Size; // eax
  CUtlVector<CStaticPropMgr::StaticPropDict_t,CUtlMemory<CStaticPropMgr::StaticPropDict_t,int> > *p_m_StaticPropDict; // ebx
  int v6; // esi
  IEngineVGuiInternal *v7; // eax
  CStaticPropMgr::StaticPropDict_t *v8; // ebx
  StaticPropDictLump_t lump; // [esp+Ch] [ebp-84h] BYREF
  CUtlVector<CStaticPropMgr::StaticPropDict_t,CUtlMemory<CStaticPropMgr::StaticPropDict_t,int> > *v10; // [esp+8Ch] [ebp-4h]

  Int = CUtlBuffer::GetInt(this: buf);
  m_Size = this->m_StaticPropDict.m_Size;
  p_m_StaticPropDict = &this->m_StaticPropDict;
  v10 = p_m_StaticPropDict;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)p_m_StaticPropDict,
    elem: m_Size,
    num: Int);
  _COM_TimestampedLog(a1: "Starting UnserializeModelDict for %d models\n", Int);
  v6 = 0;
  if ( Int > 0 )
  {
    while ( 1 )
    {
      if ( v6 % 0xAu == 0 )
      {
        v7 = EngineVGui();
        v7->UpdateProgressBar(this: v7, a2: PROGRESS_DEFAULT, a3: true);
      }
      CUtlBuffer::Get(this: buf, pMem: &lump, size: 128);
      v8 = &p_m_StaticPropDict->m_Memory.m_pMemory[v6++];
      v8->m_pModel = (model_t *)((int (__stdcall *)(StaticPropDictLump_t *, int))modelloader->GetModelForName)(
                                  a1: &lump,
                                  a2: 16);
      if ( v6 >= Int )
        break;
      p_m_StaticPropDict = v10;
    }
  }
  _COM_TimestampedLog(a1: "Finished UnserializeModelDict\n");
}

//------------------------------------------------------------------------------
// Address: 0x101E15C0
// Name: private: void CStaticPropMgr::UnserializeModels(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::UnserializeModels(CStaticPropMgr *this, CUtlBuffer *buf)
{
  CUtlBuffer *v3; // edi
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CStaticProp *m_pMemory; // ecx
  int v8; // eax
  CStaticProp *v9; // eax
  bool v10; // zf
  CStaticProp *v11; // eax
  int v12; // edi
  IEngineVGuiInternal *v13; // eax
  StaticPropLump_t lump; // [esp+4h] [ebp-5Ch] BYREF
  unsigned int v15; // [esp+4Ch] [ebp-14h]
  int nLumpVersion; // [esp+54h] [ebp-Ch]
  int count; // [esp+58h] [ebp-8h]
  int i; // [esp+5Ch] [ebp-4h]
  int savedregs; // [esp+60h] [ebp+0h] BYREF

  nLumpVersion = Mod_GameLumpVersion(lumpId: 1936749168);
  if ( nLumpVersion >= 4 )
  {
    v3 = buf;
    count = CUtlBuffer::GetInt(this: buf);
    CUtlVector<CStaticProp,CUtlMemory<CStaticProp,int>>::EnsureCapacity(this: &this->m_StaticProps, num: count);
    i = 0;
    if ( count > 0 )
    {
      v4 = nLumpVersion - 4;
      nLumpVersion -= 4;
      while ( 1 )
      {
        switch ( v4 )
        {
          case 0:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 56);
            lump.m_flForcedFadeScale = 1.0;
            *(_DWORD *)&lump.m_nMinCPULevel = 0;
            lump.m_DiffuseModulation = (color32_s)-1;
            lump.m_bDisableX360 = false;
            break;
          case 1:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 60);
            *(_DWORD *)&lump.m_nMinCPULevel = 0;
            lump.m_DiffuseModulation = (color32_s)-1;
            lump.m_bDisableX360 = false;
            break;
          case 2:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 64);
            *(_DWORD *)&lump.m_nMinCPULevel = 0;
            lump.m_DiffuseModulation = (color32_s)-1;
            lump.m_bDisableX360 = false;
            break;
          case 3:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 68);
            *(_DWORD *)&lump.m_nMinCPULevel = 0;
            lump.m_bDisableX360 = false;
            break;
          case 4:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 68);
            lump.m_bDisableX360 = false;
            break;
          case 5:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 72);
            break;
          default:
            break;
        }
        m_Size = this->m_StaticProps.m_Size;
        m_nAllocationCount = this->m_StaticProps.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CStaticProp,int>::Grow(this: &this->m_StaticProps.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++this->m_StaticProps.m_Size;
        m_pMemory = this->m_StaticProps.m_Memory.m_pMemory;
        v8 = this->m_StaticProps.m_Size - m_Size - 1;
        this->m_StaticProps.m_pElements = m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 200 * v8);
        v9 = this->m_StaticProps.m_Memory.m_pMemory;
        v10 = &v9[m_Size] == nullptr;
        v11 = &v9[m_Size];
        v15 = 200 * m_Size;
        if ( !v10 )
        {
          v11->IClientRenderable::__vftable = (IClientRenderable_vtbl *)&IClientRenderable::`vftable';
          v11->ICollideable::__vftable = (ICollideable_vtbl *)&ICollideable::`vftable';
          v11->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&IClientModelRenderable::`vftable';
          v11->IClientUnknown::IHandleEntity::__vftable = (CStaticProp_vtbl *)&CStaticProp::`vftable'{for `IClientUnknown'};
          v11->IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CStaticProp::`vftable'{for `IClientRenderable'};
          v11->ICollideable::__vftable = (ICollideable_vtbl *)&CStaticProp::`vftable'{for `ICollideable'};
          v11->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CStaticProp::`vftable'{for `IClientModelRenderable'};
          v11->m_pModel = nullptr;
          v11->m_Alpha = -1;
          v11->m_EntHandle.m_Index = -1;
          v11->m_ModelInstance = -1;
          v11->m_Partition = -1;
          v11->m_EntHandle.m_Index = -1;
          v11->m_RenderHandle = -1;
          v11->m_pClientAlphaProperty = nullptr;
        }
        CStaticProp::Init(
          this: &this->m_StaticProps.m_Memory.m_pMemory[m_Size],
          a2: (int)&savedregs,
          a3: m_Size,
          a4: (int)this,
          index: m_Size,
          &lump,
          pModel: this->m_StaticPropDict.m_Memory.m_pMemory[lump.m_PropType].m_pModel);
        CStaticProp::InsertPropIntoKDTree(this: &this->m_StaticProps.m_Memory.m_pMemory[v15 / 0xC8]);
        v12 = i;
        if ( i % 0xAu == 0 )
        {
          v13 = EngineVGui();
          v13->UpdateProgressBar(this: v13, a2: PROGRESS_DEFAULT, a3: true);
        }
        i = v12 + 1;
        if ( v12 + 1 >= count )
          break;
        v4 = nLumpVersion;
        v3 = buf;
      }
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_StaticPropManager, a2: 1, a3: "Really old map format! Static props can't be loaded...\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1830
// Name: private: void CStaticPropMgr::UnserializeStaticProps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::UnserializeStaticProps(CStaticPropMgr *this)
{
  int v2; // esi
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  v2 = Mod_GameLumpSize(lumpId: 1936749168);
  if ( v2 != 0 )
  {
    _COM_TimestampedLog(a1: "UnserializeStaticProps - start");
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: v2, nFlags: 0);
    if ( Mod_LoadGameLump(lumpId: 1936749168, pOutBuffer: &buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset], size: v2) )
    {
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v2);
      _COM_TimestampedLog(a1: "UnserializeModelDict");
      CStaticPropMgr::UnserializeModelDict(this, &buf);
      _COM_TimestampedLog(a1: "UnserializeLeafList");
      CStaticPropMgr::UnserializeLeafList(this, &buf);
      _COM_TimestampedLog(a1: "UnserializeModels");
      CStaticPropMgr::UnserializeModels(this, &buf);
    }
    _COM_TimestampedLog(a1: "UnserializeStaticProps - end");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1910
// Name: public: virtual void CStaticPropMgr::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::LevelInit(CStaticPropMgr *this)
{
  if ( !this->m_bLevelInitialized )
  {
    this->m_bLevelInitialized = true;
    if ( disableStaticPropLoading.m_pParent == nullptr || disableStaticPropLoading.m_pParent->m_Value.m_nValue == 0 )
      CStaticPropMgr::UnserializeStaticProps(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1960
// Name: public: virtual void CStaticPropMgr::GetAllStaticProps(class CUtlVector<class ICollideable __near *,class CUtlMemory<class ICollideable __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetAllStaticProps(
        CStaticPropMgr *this,
        CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutput)
{
  CStaticPropMgr::StaticPropDict_t *v3; // eax
  ICollideable *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ICollideable **m_pMemory; // ecx
  int v8; // eax
  ICollideable **v9; // eax
  CStaticPropMgr *v10; // [esp+4h] [ebp-8h]
  int m_nGrowSize; // [esp+8h] [ebp-4h]
  CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutputa; // [esp+14h] [ebp+8h]

  v10 = this;
  if ( pOutput != nullptr && this->m_StaticProps.m_Memory.m_nGrowSize != 0 )
  {
    pOutputa = nullptr;
    m_nGrowSize = this->m_StaticProps.m_Memory.m_nGrowSize;
    while ( 1 )
    {
      v3 = (CStaticPropMgr::StaticPropDict_t *)((char *)pOutputa + (unsigned int)this->m_StaticPropDict.m_pElements);
      if ( v3 != nullptr )
        v4 = (ICollideable *)&v3[2];
      else
        v4 = nullptr;
      m_Size = pOutput->m_Size;
      m_nAllocationCount = pOutput->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)pOutput,
          num: m_Size - m_nAllocationCount + 1);
      ++pOutput->m_Size;
      m_pMemory = pOutput->m_Memory.m_pMemory;
      v8 = pOutput->m_Size - m_Size - 1;
      pOutput->m_pElements = pOutput->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = &pOutput->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = v4;
      pOutputa += 10;
      if ( --m_nGrowSize == 0 )
        break;
      this = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1A10
// Name: public: virtual void CStaticPropMgr::GetAllStaticPropsInAABB(class Vector const __near &,class Vector const __near &,class CUtlVector<class ICollideable __near *,class CUtlMemory<class ICollideable __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetAllStaticPropsInAABB(
        CStaticPropMgr *this,
        const Vector *vMins,
        const Vector *vMaxs,
        CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutput)
{
  CStaticPropMgr::StaticPropDict_t *v5; // ebx
  void (__thiscall *v6)(ICollideable *, Vector *, Vector *); // eax
  ICollideable *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ICollideable **m_pMemory; // ecx
  int v11; // eax
  ICollideable **v12; // eax
  Vector vPropMins; // [esp+4h] [ebp-20h] BYREF
  Vector vPropMaxs; // [esp+10h] [ebp-14h] BYREF
  CStaticPropMgr *v15; // [esp+1Ch] [ebp-8h]
  int m_nGrowSize; // [esp+20h] [ebp-4h]
  CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutputa; // [esp+34h] [ebp+10h]

  v15 = this;
  if ( pOutput != nullptr && this->m_StaticProps.m_Memory.m_nGrowSize != 0 )
  {
    pOutputa = nullptr;
    m_nGrowSize = this->m_StaticProps.m_Memory.m_nGrowSize;
    while ( 1 )
    {
      v5 = (CStaticPropMgr::StaticPropDict_t *)((char *)pOutputa + (unsigned int)this->m_StaticPropDict.m_pElements);
      v6 = *(void (__thiscall **)(ICollideable *, Vector *, Vector *))&v5[2].m_pModel->szPathName[56];
      v7 = (ICollideable *)&v5[2];
      v6(a1: v7, a2: &vPropMins, a3: &vPropMaxs);
      if ( vMins->x <= vPropMaxs.x
        && vMins->y <= vPropMaxs.y
        && vMins->z <= vPropMaxs.z
        && vPropMins.x <= vMaxs->x
        && vPropMins.y <= vMaxs->y
        && vPropMins.z <= vMaxs->z )
      {
        m_Size = pOutput->m_Size;
        m_nAllocationCount = pOutput->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)pOutput,
            num: m_Size - m_nAllocationCount + 1);
        ++pOutput->m_Size;
        m_pMemory = pOutput->m_Memory.m_pMemory;
        v11 = pOutput->m_Size - m_Size - 1;
        pOutput->m_pElements = pOutput->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
        v12 = &pOutput->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = v7;
      }
      pOutputa += 10;
      if ( --m_nGrowSize == 0 )
        break;
      this = v15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1B10
// Name: public: virtual void CStaticPropMgr::GetAllStaticPropsInOBB(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class CUtlVector<class ICollideable __near *,class CUtlMemory<class ICollideable __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetAllStaticPropsInOBB(
        CStaticPropMgr *this,
        const Vector *ptOrigin,
        const Vector *vExtent1,
        const Vector *vExtent2,
        const Vector *vExtent3,
        CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutput)
{
  float v7; // xmm0_4
  float z; // xmm1_4
  float x; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm6_4
  int v14; // ecx
  float *p_z; // eax
  float v16; // xmm2_4
  float v17; // xmm2_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float y; // xmm1_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  const Vector *m_nGrowSize; // eax
  float v29; // xmm0_4
  ICollideable *v30; // edi
  void (__thiscall *WorldSpaceSurroundingBounds)(ICollideable *, Vector *, Vector *); // edx
  ICollideable *v32; // edi
  int v33; // eax
  float v34; // edx
  float v35; // ecx
  float v36; // eax
  ICollideable_vtbl *v37; // edx
  int v38; // eax
  float v39; // ecx
  float v40; // edx
  float v41; // eax
  ICollideable_vtbl *v42; // edx
  const QAngle *v43; // eax
  int v44; // ebx
  Vector *v45; // esi
  float v46; // xmm0_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // esi
  float *v50; // edx
  int v51; // eax
  float *v52; // ecx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  ICollideable **m_pMemory; // ecx
  int v56; // eax
  ICollideable **v57; // esi
  const Vector *v58; // [esp-14h] [ebp-160h]
  Vector ptPropExtents[8]; // [esp+0h] [ebp-14Ch] BYREF
  matrix3x4_t matPropWorld; // [esp+60h] [ebp-ECh] BYREF
  float fOBBPlaneDists[6]; // [esp+90h] [ebp-BCh]
  Vector vPropMaxs; // [esp+A8h] [ebp-A4h] BYREF
  Vector vPropMins; // [esp+B4h] [ebp-98h] BYREF
  Vector vOBBPlaneNormals[6]; // [esp+C0h] [ebp-8Ch] BYREF
  Vector vPropOBBMaxs; // [esp+108h] [ebp-44h]
  float v66; // [esp+114h] [ebp-38h]
  Vector vPropOBBMins; // [esp+118h] [ebp-34h]
  Vector ptTemp; // [esp+124h] [ebp-28h] BYREF
  CStaticPropMgr *v69; // [esp+130h] [ebp-1Ch]
  Vector vAABBMaxs; // [esp+134h] [ebp-18h]
  Vector vAABBMins; // [esp+140h] [ebp-Ch]
  float ptOrigina; // [esp+154h] [ebp+8h]
  const Vector *ptOriginb; // [esp+154h] [ebp+8h]
  const Vector *vExtent1a; // [esp+158h] [ebp+Ch]

  v69 = this;
  if ( pOutput != nullptr )
  {
    z = ptOrigin->z;
    x = ptOrigin->x;
    ptOrigina = ptOrigin->y;
    v7 = ptOrigina;
    v10 = x;
    v11 = ptOrigina;
    v12 = z;
    v13 = x;
    vAABBMins.x = x;
    vAABBMins.y = ptOrigina;
    vAABBMins.z = z;
    vAABBMaxs.x = x;
    vAABBMaxs.y = ptOrigina;
    vAABBMaxs.z = z;
    v14 = 0;
    v66 = z;
    p_z = &ptPropExtents[0].z;
    do
    {
      *(p_z - 1) = ptOrigina;
      v16 = v66;
      *(p_z - 2) = x;
      *p_z = v16;
      if ( (v14 & 1) != 0 )
      {
        *(p_z - 2) = vExtent1->x + x;
        *(p_z - 1) = vExtent1->y + *(p_z - 1);
        *p_z = vExtent1->z + *p_z;
      }
      if ( (v14 & 2) != 0 )
      {
        *(p_z - 2) = vExtent2->x + *(p_z - 2);
        *(p_z - 1) = vExtent2->y + *(p_z - 1);
        *p_z = vExtent2->z + *p_z;
      }
      if ( (v14 & 4) != 0 )
      {
        *(p_z - 2) = vExtent3->x + *(p_z - 2);
        *(p_z - 1) = vExtent3->y + *(p_z - 1);
        *p_z = vExtent3->z + *p_z;
      }
      v17 = *(p_z - 2);
      if ( v10 > v17 )
        v10 = *(p_z - 2);
      if ( v17 > v13 )
        v13 = *(p_z - 2);
      v18 = *(p_z - 1);
      if ( v11 > v18 )
        v11 = *(p_z - 1);
      if ( v18 > v7 )
        v7 = *(p_z - 1);
      if ( v12 > *p_z )
        v12 = *p_z;
      if ( *p_z > z )
        z = *p_z;
      ++v14;
      p_z += 3;
    }
    while ( v14 != 8 );
    vAABBMaxs.y = v7;
    vOBBPlaneNormals[0].x = vExtent1->x;
    vOBBPlaneNormals[0].y = vExtent1->y;
    v19 = vExtent1->z;
    vAABBMaxs.z = z;
    vAABBMins.z = v12;
    vAABBMins.y = v11;
    vAABBMaxs.x = v13;
    vAABBMins.x = v10;
    vOBBPlaneNormals[0].z = v19;
    VectorNormalize(vec: vOBBPlaneNormals);
    v20 = ptOrigin->x;
    y = ptOrigin->y;
    v22 = ptOrigin->z;
    fOBBPlaneDists[0] = (float)((float)((float)(y + vExtent1->y) * vOBBPlaneNormals[0].y)
                              + (float)((float)(ptOrigin->x + vExtent1->x) * vOBBPlaneNormals[0].x))
                      + (float)((float)(v22 + vExtent1->z) * vOBBPlaneNormals[0].z);
    vOBBPlaneNormals[2].x = vExtent2->x;
    vOBBPlaneNormals[2].y = vExtent2->y;
    v23 = vExtent2->z;
    vOBBPlaneNormals[1].x = -vOBBPlaneNormals[0].x;
    vOBBPlaneNormals[1].y = -vOBBPlaneNormals[0].y;
    vOBBPlaneNormals[1].z = -vOBBPlaneNormals[0].z;
    fOBBPlaneDists[1] = (float)((float)(y * (float)-vOBBPlaneNormals[0].y) + (float)(v20 * (float)-vOBBPlaneNormals[0].x))
                      + (float)(v22 * (float)-vOBBPlaneNormals[0].z);
    vOBBPlaneNormals[2].z = v23;
    VectorNormalize(vec: &vOBBPlaneNormals[2]);
    v24 = ptOrigin->y;
    v25 = ptOrigin->x;
    v26 = ptOrigin->z;
    fOBBPlaneDists[2] = (float)((float)(vOBBPlaneNormals[2].y * (float)(v24 + vExtent2->y))
                              + (float)(vOBBPlaneNormals[2].x * (float)(ptOrigin->x + vExtent2->x)))
                      + (float)(vOBBPlaneNormals[2].z * (float)(v26 + vExtent2->z));
    fOBBPlaneDists[3] = (float)((float)(v24 * (float)-vOBBPlaneNormals[2].y)
                              + (float)(v25 * (float)-vOBBPlaneNormals[2].x))
                      + (float)(v26 * (float)-vOBBPlaneNormals[2].z);
    vOBBPlaneNormals[4].x = vExtent3->x;
    vOBBPlaneNormals[4].y = vExtent3->y;
    v27 = vExtent3->z;
    vOBBPlaneNormals[3].x = -vOBBPlaneNormals[2].x;
    vOBBPlaneNormals[3].y = -vOBBPlaneNormals[2].y;
    vOBBPlaneNormals[3].z = -vOBBPlaneNormals[2].z;
    vOBBPlaneNormals[4].z = v27;
    VectorNormalize(vec: &vOBBPlaneNormals[4]);
    m_nGrowSize = (const Vector *)v69->m_StaticProps.m_Memory.m_nGrowSize;
    v29 = (float)((float)(ptOrigin->y * (float)-vOBBPlaneNormals[4].y)
                + (float)(ptOrigin->x * (float)-vOBBPlaneNormals[4].x))
        + (float)(ptOrigin->z * (float)-vOBBPlaneNormals[4].z);
    fOBBPlaneDists[4] = (float)((float)(vOBBPlaneNormals[4].y * (float)(ptOrigin->y + vExtent3->y))
                              + (float)(vOBBPlaneNormals[4].x * (float)(ptOrigin->x + vExtent3->x)))
                      + (float)(vOBBPlaneNormals[4].z * (float)(ptOrigin->z + vExtent3->z));
    vOBBPlaneNormals[5].x = -vOBBPlaneNormals[4].x;
    vOBBPlaneNormals[5].y = -vOBBPlaneNormals[4].y;
    vOBBPlaneNormals[5].z = -vOBBPlaneNormals[4].z;
    fOBBPlaneDists[5] = v29;
    if ( m_nGrowSize != nullptr )
    {
      vExtent1a = nullptr;
      for ( ptOriginb = m_nGrowSize; ptOriginb != nullptr; ptOriginb = (const Vector *)((char *)ptOriginb - 1) )
      {
        v30 = (ICollideable *)((char *)vExtent1a + (unsigned int)v69->m_StaticPropDict.m_pElements);
        WorldSpaceSurroundingBounds = v30[2].WorldSpaceSurroundingBounds;
        v32 = v30 + 2;
        WorldSpaceSurroundingBounds(this: v32, a2: &vPropMins, a3: &vPropMaxs);
        if ( vAABBMins.x <= vPropMaxs.x
          && vAABBMins.y <= vPropMaxs.y
          && vAABBMins.z <= vPropMaxs.z
          && vPropMins.x <= vAABBMaxs.x
          && vPropMins.y <= vAABBMaxs.y
          && vPropMins.z <= vAABBMaxs.z )
        {
          v33 = (int)v32->OBBMins(this: v32);
          v34 = *(float *)(v33 + 4);
          v35 = *(float *)v33;
          v36 = *(float *)(v33 + 8);
          vPropOBBMins.y = v34;
          v37 = v32->__vftable;
          vPropOBBMins.x = v35;
          vPropOBBMins.z = v36;
          v38 = (int)v37->OBBMaxs(this: v32);
          v39 = *(float *)v38;
          v40 = *(float *)(v38 + 4);
          v41 = *(float *)(v38 + 8);
          vPropOBBMaxs.x = v39;
          vPropOBBMaxs.y = v40;
          v42 = v32->__vftable;
          vPropOBBMaxs.z = v41;
          v58 = v42->GetCollisionOrigin(this: v32);
          v43 = v32->GetCollisionAngles(this: v32);
          AngleMatrix(angles: v43, position: v58, matrix: &matPropWorld);
          v44 = 0;
          v45 = ptPropExtents;
          do
          {
            if ( (v44 & 1) != 0 )
              v46 = vPropOBBMaxs.x;
            else
              v46 = vPropOBBMins.x;
            ptTemp.x = v46;
            if ( (v44 & 2) != 0 )
              v47 = vPropOBBMaxs.y;
            else
              v47 = vPropOBBMins.y;
            ptTemp.y = v47;
            if ( (v44 & 4) != 0 )
              v48 = vPropOBBMaxs.z;
            else
              v48 = vPropOBBMins.z;
            ptTemp.z = v48;
            VectorTransform(in1: &ptTemp.x, in2: &matPropWorld, out: &v45->x);
            ++v44;
            ++v45;
          }
          while ( v44 != 8 );
          v49 = 0;
          v50 = &vOBBPlaneNormals[0].z;
          do
          {
            v51 = 0;
            v52 = &ptPropExtents[0].z;
            while ( (float)((float)((float)((float)(*(v52 - 2) * *(v50 - 2)) + (float)(*(v52 - 1) * *(v50 - 1)))
                                  + (float)(*v52 * *v50))
                          - fOBBPlaneDists[v49]) >= 0.0 )
            {
              ++v51;
              v52 += 3;
              if ( v51 == 8 )
                goto LABEL_52;
            }
            ++v49;
            v50 += 3;
          }
          while ( v49 != 6 );
          m_Size = pOutput->m_Size;
          m_nAllocationCount = pOutput->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)pOutput,
              num: m_Size - m_nAllocationCount + 1);
          ++pOutput->m_Size;
          m_pMemory = pOutput->m_Memory.m_pMemory;
          v56 = pOutput->m_Size - m_Size - 1;
          pOutput->m_pElements = pOutput->m_Memory.m_pMemory;
          if ( v56 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v56);
          v57 = &pOutput->m_Memory.m_pMemory[m_Size];
          if ( v57 != nullptr )
            *v57 = v32;
        }
LABEL_52:
        vExtent1a = (const Vector *)((char *)vExtent1a + 200);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10287E50
// Name: public: virtual bool CStaticProp::GetShadowCastDirection(class Vector __near *,enum ShadowType_t)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStaticProp::GetShadowCastDirection(vgui::Panel *this, vgui::Menu *menu, vgui::Menu *msglist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x102E58A0
// Name: public: virtual struct model_t const __near * CStaticProp::GetCollisionModel(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::GetCollisionModel(CVTFTexture *this)
{
  return this->m_nFaceCount;
}

//------------------------------------------------------------------------------
// Address: 0x1031D9A0
// Name: _dynamic_initializer_for__prop_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__prop_crosshair__()
{
  ConCommand::ConCommand(
    this: &prop_crosshair,
    pName: "prop_crosshair",
    callback: (void (__cdecl *)())Cmd_PropCrosshair_f,
    pHelpString: "Shows name for prop looking at",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__prop_crosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x10326800
// Name: _dynamic_atexit_destructor_for__prop_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__prop_crosshair__()
{
  ConCommand::~ConCommand(this: &prop_crosshair);
}

//------------------------------------------------------------------------------
// Address: 0x101DE9A0
// Name: __CreateCStaticPropMgrIStaticPropMgrClient_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IStaticPropMgrClient *__cdecl _CreateCStaticPropMgrIStaticPropMgrClient_interface()
{
  return &s_StaticPropMgr.IStaticPropMgrClient;
}

//------------------------------------------------------------------------------
// Address: 0x101DE9B0
// Name: __CreateCStaticPropMgrIStaticPropMgrServer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IStaticPropMgrServer *__cdecl _CreateCStaticPropMgrIStaticPropMgrServer_interface()
{
  return &s_StaticPropMgr.IStaticPropMgrServer;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1006E040
// Name: public: virtual bool CStaticProp::GetShadowCastDirection(class Vector __near *,enum ShadowType_t)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStaticProp::GetShadowCastDirection(vgui::Panel *this, vgui::Menu *menu, vgui::Menu *msglist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101DEC30
// Name: public: virtual unsigned short __near & CStaticProp::RenderHandle(void)
// Source: json
//------------------------------------------------------------------------------
CBaseHandle *__thiscall CStaticProp::RenderHandle(CStaticProp *this)
{
  return &this->m_EntHandle;
}

//------------------------------------------------------------------------------
// Address: 0x101DEC90
// Name: public: virtual class Vector const __near & CStaticProp::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
IClientModelRenderable *__thiscall CStaticProp::GetRenderOrigin(CStaticProp *this)
{
  return &this->IClientModelRenderable;
}

//------------------------------------------------------------------------------
// Address: 0x101DECA0
// Name: public: virtual class QAngle const __near & CStaticProp::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CStaticProp::GetRenderAngles(CStaticProp *this)
{
  return (const QAngle *)&this->m_Origin.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DECB0
// Name: public: virtual bool CStaticProp::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticProp::GetAttachment(CStaticProp *this, int number, Vector *origin, QAngle *angles)
{
  origin->x = *(float *)&this->IClientModelRenderable::__vftable;
  origin->y = this->m_Origin.x;
  origin->z = this->m_Origin.y;
  *angles = *(QAngle *)&this->m_Origin.z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DECF0
// Name: public: virtual bool CStaticProp::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticProp::GetAttachment(CStaticProp *this, int number, matrix3x4_t *matrix)
{
  const matrix3x4_t *v3; // eax

  v3 = (const matrix3x4_t *)((int (__thiscall *)(CStaticProp *))this->IClientUnknown::IHandleEntity::__vftable[2].ShouldCacheRenderInfo)(a1: this);
  MatrixCopy(in: v3, out: matrix);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DED10
// Name: public: virtual bool CStaticProp::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStaticProp::ShouldDraw(CStaticProp *this)
{
  return LOWORD(this->m_EntHandle.m_Index) != 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101DED20
// Name: public: virtual bool CStaticProp::SetupBones(class matrix3x4a_t __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticProp::SetupBones(
        CStaticProp *this,
        matrix3x4a_t *pBoneToWorldOut,
        int nMaxBones,
        int boneMask,
        float currentTime)
{
  if ( LODWORD(this->m_Angles.z) == 0 )
    return 0;
  MatrixCopy(in: (const matrix3x4_t *)&this->m_RenderBBoxMax.z, out: pBoneToWorldOut);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DED60
// Name: public: virtual bool CStaticProp::GetRenderData(void __near *,enum ModelDataCategory_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticProp::GetRenderData(CStaticProp *this, _DWORD *pData, ModelDataCategory_t nCategory)
{
  if ( nCategory != MODEL_DATA_LIGHTING_MODEL )
    return 0;
  *pData = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEDB0
// Name: public: virtual struct model_t const __near * CStaticProp::GetCollisionModel(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::GetCollisionModel(CVTFTexture *this)
{
  return this->m_nFaceCount;
}

//------------------------------------------------------------------------------
// Address: 0x101DEE00
// Name: public: virtual enum SolidType_t CStaticProp::GetSolid(void)const
// Source: json
//------------------------------------------------------------------------------
SolidType_t __thiscall CStaticProp::GetSolid(CStaticProp *this)
{
  return BYTE1(this->m_pModel);
}

//------------------------------------------------------------------------------
// Address: 0x101DEE10
// Name: public: virtual int CStaticProp::GetRenderFlags(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStaticProp::GetRenderFlags(CStaticProp *this)
{
  float z; // ecx
  BOOL result; // eax

  z = this->m_Angles.z;
  result = false;
  if ( z != 0.0 )
    return (*(_DWORD *)(LODWORD(z) + 276) & 0x100) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DEE30
// Name: public: virtual void CStaticProp::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::GetRenderBounds(CStaticProp *this, Vector *mins, Vector *maxs)
{
  *mins = *(Vector *)&this->m_pClientAlphaProperty;
  *maxs = *(Vector *)&this->m_RenderBBoxMin.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DEE60
// Name: public: virtual void CStaticProp::GetRenderBoundsWorldspace(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::GetRenderBoundsWorldspace(CStaticProp *this, Vector *mins, Vector *maxs)
{
  *mins = *(Vector *)&this->m_flRadius;
  *maxs = *(Vector *)&this->m_WorldRenderBBoxMin.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DEEB0
// Name: public: virtual bool CStaticProp::ShouldReceiveProjectedTextures(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStaticProp::ShouldReceiveProjectedTextures(CStaticProp *this, char flags)
{
  return (this->m_ModelInstance & 0x400) == 0 && (flags & 5) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DEED0
// Name: public: void CStaticProp::InsertPropIntoKDTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::InsertPropIntoKDTree(CStaticProp *this)
{
  vcollide_t *v2; // eax
  ISpatialPartitionInternal *v3; // eax
  const char *v4; // eax
  char szModel[260]; // [esp+4h] [ebp-14Ch] BYREF
  matrix3x4_t propToWorld; // [esp+108h] [ebp-48h] BYREF
  Vector maxs; // [esp+138h] [ebp-18h] BYREF
  Vector mins; // [esp+144h] [ebp-Ch] BYREF

  if ( this->m_nSolidType != 0 )
  {
    AngleMatrix(angles: &this->m_Angles, position: &this->m_Origin, matrix: &propToWorld);
    TransformAABB(
      transform: &propToWorld,
      vecMinsIn: &this->m_pModel->mins,
      vecMaxsIn: &this->m_pModel->maxs,
      vecMinsOut: &mins,
      vecMaxsOut: &maxs);
    if ( this->m_nSolidType != 6 )
    {
LABEL_6:
      v3 = SpatialPartition();
      this->m_Partition = v3->CreateHandle(this: v3, a2: this, a3: 101, a4: &mins, a5: &maxs);
      return;
    }
    v2 = CM_VCollideForModel(modelindex: -1, pModel: this->m_pModel);
    if ( v2 != nullptr && (*(_WORD *)v2 & 0x7FFF) != 0 )
    {
      physcollision->CollideGetAABB(
        this: physcollision,
        a2: &mins,
        a3: &maxs,
        a4: *v2->solids,
        a5: &this->m_Origin,
        a6: &this->m_Angles);
      goto LABEL_6;
    }
    if ( this->m_pModel != nullptr )
      v4 = modelloader->GetName(this: modelloader, a2: this->m_pModel);
    else
      v4 = "unknown model";
    V_strncpy(pDest: szModel, pSrc: v4, maxLen: 260);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_StaticPropManager,
        a2: 1,
        a3: "SOLID_VPHYSICS static prop with no vphysics model! (%s)\n",
        szModel);
    this->m_nSolidType = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DEFF0
// Name: class IStaticPropMgrEngine __near * StaticPropMgr(void)
// Source: json
//------------------------------------------------------------------------------
CStaticPropMgr *__cdecl StaticPropMgr()
{
  return &s_StaticPropMgr;
}

//------------------------------------------------------------------------------
// Address: 0x101DF000
// Name: public: virtual void CStaticPropMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::Shutdown(CStaticPropMgr *this)
{
  if ( this->m_bLevelInitialized )
    this->LevelShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DF010
// Name: public: virtual bool CStaticPropMgr::IsStaticProp(class IHandleEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStaticPropMgr::IsStaticProp(CStaticPropMgr *this, IHandleEntity *pHandleEntity)
{
  return pHandleEntity == nullptr
      || (pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index & 0xFFFF0000) == 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x101DF040
// Name: public: virtual bool CStaticPropMgr::IsStaticProp(class CBaseHandle)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStaticPropMgr::IsStaticProp(CStaticPropMgr *this, CBaseHandle handle)
{
  return (handle.m_Index & 0xFFFF0000) == 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x101DF060
// Name: public: virtual int CStaticPropMgr::GetStaticPropIndex(class IHandleEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CStaticPropMgr::GetStaticPropIndex(CStaticPropMgr *this, IHandleEntity *pHandleEntity)
{
  unsigned int result; // eax

  result = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( result == -1 )
    return 0x1FFF;
  else
    return (unsigned __int16)result;
}

//------------------------------------------------------------------------------
// Address: 0x101DF090
// Name: public: virtual void CStaticPropMgr::GetLightingOrigins(class Vector __near *,int,int,class IClientRenderable __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetLightingOrigins(
        CStaticPropMgr *this,
        Vector *pLightingOrigins,
        int nOriginStride,
        int nCount,
        IClientRenderable **ppRenderable,
        int nRenderableStride)
{
  int v6; // ebx
  float *p_z; // esi
  float *v9; // eax

  v6 = nCount;
  if ( nCount > 0 )
  {
    p_z = &pLightingOrigins->z;
    do
    {
      v9 = (float *)(*ppRenderable)->GetIClientUnknown(this: *ppRenderable);
      ppRenderable = (IClientRenderable **)((char *)ppRenderable + nRenderableStride);
      *(p_z - 2) = v9[43];
      *(p_z - 1) = v9[44];
      *p_z = v9[45];
      p_z = (float *)((char *)p_z + nOriginStride);
      --v6;
    }
    while ( v6 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF0E0
// Name: public: void CStaticPropMgr::DrawStaticProps_FastPipeline(class IClientRenderable __near * __near *,struct RenderableInstance_t const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::DrawStaticProps_FastPipeline(
        CStaticPropMgr *this,
        IClientRenderable **pProps,
        const RenderableInstance_t *pInstances,
        int count,
        BOOL bShadowDepth)
{
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  char *v8; // eax
  IClientRenderable *v9; // ecx
  IClientRenderable *v10; // ecx
  _BYTE v11[4]; // [esp+Ch] [ebp-A000h] BYREF
  char v12; // [esp+10h] [ebp-9FFCh] BYREF

  v5 = count;
  v6 = 0;
  if ( count > 2048 )
  {
    CStaticPropMgr::DrawStaticProps_FastPipeline(
      this,
      pProps: pProps + 2048,
      pInstances,
      count: count - 2048,
      bShadowDepth);
    v5 = 2048;
  }
  v7 = 0;
  if ( v5 > 0 )
  {
    v8 = &v12;
    do
    {
      v9 = pProps[v7];
      if ( v9 != nullptr )
        v10 = v9 - 1;
      else
        v10 = nullptr;
      if ( v10[10].__vftable != nullptr )
      {
        *((_DWORD *)v8 - 1) = v10 + 24;
        *(IClientRenderable *)v8 = v10[10];
        *((_WORD *)v8 + 6) = HIWORD(v10[11].__vftable);
        v8[14] = BYTE2(v10[12].__vftable);
        *((_DWORD *)v8 + 2) = v10 + 43;
        *((_DWORD *)v8 + 1) = v10 + 1;
        v8[15] = pInstances[v7].m_nAlpha;
        ++v6;
        v8 += 20;
      }
      ++v7;
    }
    while ( v7 < v5 );
  }
  modelrender->DrawStaticPropArrayFast(this: modelrender, a2: (StaticPropRenderInfo_t *)v11, a3: v6, a4: bShadowDepth);
}

//------------------------------------------------------------------------------
// Address: 0x101DF1B0
// Name: public: virtual void CStaticPropMgr::AddShadowToStaticProp(unsigned short,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::AddShadowToStaticProp(
        CStaticPropMgr *this,
        int shadowHandle,
        IClientRenderable *pRenderable)
{
  IClientRenderable *v3; // eax
  IShadowMgrInternal_vtbl *v4; // esi
  unsigned __int16 v5; // ax

  if ( pRenderable != nullptr )
    v3 = pRenderable - 1;
  else
    v3 = nullptr;
  v4 = g_pShadowMgr->__vftable;
  v5 = v3[1].GetModelInstance(this: v3 + 1);
  v4->AddShadowToModel(this: g_pShadowMgr, a2: shadowHandle, a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101DF370
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
// Address: 0x101DF400
// Name: ShouldDrawInWireFrameMode
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ShouldDrawInWireFrameMode()
{
  if ( (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0) && !Cmd_IsRptActive() )
    return false;
  if ( mat_wireframe.m_pParent != nullptr )
    return mat_wireframe.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101DF440
// Name: bool IsUsingStaticPropDebugModes(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsUsingStaticPropDebugModes()
{
  return r_drawstaticprops.m_pParent == nullptr
      || r_drawstaticprops.m_pParent->m_Value.m_nValue != 1
      || r_DrawSpecificStaticProp.m_pParent == nullptr
      || r_DrawSpecificStaticProp.m_pParent->m_Value.m_nValue >= 0
      || r_colorstaticprops.m_pParent != nullptr && r_colorstaticprops.m_pParent->m_Value.m_nValue != 0
      || r_staticpropinfo.m_pParent != nullptr && r_staticpropinfo.m_pParent->m_Value.m_nValue != 0
      || mat_fullbright.m_pParent != nullptr && mat_fullbright.m_pParent->m_Value.m_nValue != 0
      || r_drawmodellightorigin.m_pParent != nullptr && r_drawmodellightorigin.m_pParent->m_Value.m_nValue != 0
      || ShouldDrawInWireFrameMode()
      || r_drawmodelstatsoverlay.m_pParent != nullptr && r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DF4C0
// Name: public: virtual class IClientUnknown __near * CStaticProp::GetIClientUnknown(void)
// Source: json
//------------------------------------------------------------------------------
CStaticProp *__thiscall CStaticProp::GetIClientUnknown(CStaticProp *this)
{
  return (CStaticProp *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x101DF4D0
// Name: public: virtual class ICollideable __near * CStaticProp::GetCollideable(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CStaticProp::GetCollideable(CStaticProp *this)
{
  if ( this != nullptr )
    return &this->ICollideable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DF4E0
// Name: public: virtual class IClientRenderable __near * CStaticProp::GetClientRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall CStaticProp::GetClientRenderable(CStaticProp *this)
{
  if ( this != nullptr )
    return &this->IClientRenderable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DF500
// Name: public: virtual class IHandleEntity __near * CStaticProp::GetEntityHandle(void)
// Source: json
//------------------------------------------------------------------------------
CStaticProp *__thiscall CStaticProp::GetEntityHandle(CStaticProp *this)
{
  return (CStaticProp *)((char *)this - 8);
}

//------------------------------------------------------------------------------
// Address: 0x101DF510
// Name: public: virtual int CStaticProp::GetSkin(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::GetSkin(CStaticProp *this)
{
  return LOBYTE(this->m_ModelInstance);
}

//------------------------------------------------------------------------------
// Address: 0x101DF520
// Name: public: virtual unsigned char CStaticProp::OverrideShadowAlphaModulation(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CStaticProp::OverrideShadowAlphaModulation(CStaticProp *this, unsigned __int8 nAlpha)
{
  return nAlpha;
}

//------------------------------------------------------------------------------
// Address: 0x101DF530
// Name: public: virtual unsigned short CStaticProp::GetShadowHandle(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::GetShadowHandle(CShadowMgr *this)
{
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101DF540
// Name: public: virtual void CStaticProp::GetShadowRenderBounds(class Vector __near &,class Vector __near &,enum ShadowType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::GetShadowRenderBounds(
        CStaticProp *this,
        Vector *mins,
        Vector *maxs,
        ShadowType_t shadowType)
{
  ((void (__thiscall *)(CStaticProp *, Vector *, Vector *))this->IClientUnknown::IHandleEntity::__vftable[1].GetIClientEntity)(
    a1: this,
    a2: mins,
    a3: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x101DF560
// Name: public: virtual int CStaticProp::LookupAttachment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::LookupAttachment(CStaticProp *this, const char *pAttachmentName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101DF570
// Name: public: virtual struct matrix3x4_t const __near & CStaticProp::RenderableToWorldTransform(void)
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall CStaticProp::RenderableToWorldTransform(CStaticProp *this)
{
  return (const matrix3x4_t *)&this->m_RenderBBoxMax.z;
}

//------------------------------------------------------------------------------
// Address: 0x101DF580
// Name: public: virtual unsigned short CStaticProp::GetModelInstance(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CStaticProp::GetModelInstance(CStaticProp *this)
{
  return HIWORD(this->m_pModel);
}

//------------------------------------------------------------------------------
// Address: 0x101DF5A0
// Name: public: virtual CStaticProp::~CStaticProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticProp::~CStaticProp(CStaticProp *this)
{
  IClientAlphaProperty *m_pClientAlphaProperty; // eax
  ISpatialPartitionInternal *v3; // eax

  m_pClientAlphaProperty = this->m_pClientAlphaProperty;
  this->IClientUnknown::IHandleEntity::__vftable = (CStaticProp_vtbl *)&CStaticProp::`vftable'{for `IClientUnknown'};
  this->IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CStaticProp::`vftable'{for `IClientRenderable'};
  this->ICollideable::__vftable = (ICollideable_vtbl *)&CStaticProp::`vftable'{for `ICollideable'};
  this->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CStaticProp::`vftable'{for `IClientModelRenderable'};
  if ( m_pClientAlphaProperty != nullptr )
  {
    g_pClientAlphaPropertyMgr->DestroyClientAlphaProperty(this: g_pClientAlphaPropertyMgr, a2: m_pClientAlphaProperty);
    this->m_pClientAlphaProperty = nullptr;
  }
  if ( this->m_Partition != 0xFFFF )
  {
    v3 = SpatialPartition();
    v3->DestroyHandle(this: v3, a2: this->m_Partition);
    this->m_Partition = -1;
  }
  if ( this->m_ModelInstance != 0xFFFF )
    modelrender->DestroyInstance(this: modelrender, a2: this->m_ModelInstance);
  this->IClientUnknown::IHandleEntity::__vftable = (CStaticProp_vtbl *)&IHandleEntity::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101DF630
// Name: public: bool CStaticProp::Init(int,struct StaticPropLump_t __near &,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CStaticProp::Init@<al>(
        CStaticProp *this@<ecx>,
        IMDLCache *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int index,
        StaticPropLump_t *lump,
        model_t *pModel)
{
  void (__thiscall *BeginLock)(IMDLCache *); // eax
  studiohdr_t *v9; // eax
  const char *v10; // eax
  IClientAlphaProperty *v11; // eax
  bool v12; // zf
  const char *v13; // eax
  unsigned __int8 m_nMinGPULevel; // cl
  unsigned __int8 m_nMaxGPULevel; // dl
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  __int128 v20; // xmm0
  int v21; // eax
  char v24[12]; // [esp+44h] [ebp-134h] BYREF
  __int128 szModel_252; // [esp+14Ch] [ebp-2Ch] OVERLAPPED
  const Vector *p_m_RenderBBoxMin; // [esp+15Ch] [ebp-1Ch]
  const QAngle *p_m_Angles; // [esp+160h] [ebp-18h]
  float m_flForcedFadeScale; // [esp+164h] [ebp-14h]
  studiohdr_t *p_m_ModelToWorld; // [esp+168h] [ebp-10h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+16Ch] [ebp-Ch]
  float flForcedFadeScale; // [esp+170h] [ebp-8h]
  float retaddr; // [esp+178h] [ebp+0h]

  cacheCriticalSection.m_pCache = a2;
  flForcedFadeScale = retaddr;
  this->m_EntHandle.m_Index = index | 0x40000000;
  this->m_Partition = -1;
  this->m_Origin = lump->m_Origin;
  this->m_Angles = lump->m_Angles;
  this->m_pModel = pModel;
  this->m_FirstLeaf = lump->m_FirstLeaf;
  this->m_LeafCount = lump->m_LeafCount;
  this->m_nSolidType = lump->m_Solid;
  this->m_DiffuseModulation.x = (float)lump->m_DiffuseModulation.r * 0.0039215689;
  this->m_DiffuseModulation.y = (float)lump->m_DiffuseModulation.g * 0.0039215689;
  this->m_DiffuseModulation.z = (float)lump->m_DiffuseModulation.b * 0.0039215689;
  this->m_DiffuseModulation.w = (float)lump->m_DiffuseModulation.a * 0.0039215689;
  BeginLock = g_pMDLCache->BeginLock;
  p_m_Angles = (const QAngle *)g_pMDLCache;
  ((void (__cdecl *)(int, int))BeginLock)(a1: a3, a2: a4);
  v9 = modelinfo->GetStudiomodel(this: modelinfo, a2: this->m_pModel);
  p_m_ModelToWorld = v9;
  if ( v9 != nullptr && (v9->flags & 0x10) == 0 && nBitchCount < 100 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
    {
      v10 = studiohdr_t::pszName(this: p_m_ModelToWorld);
      _LoggingSystem_Log(
        a1: LOG_StaticPropManager,
        a2: 1,
        a3: "model %s used as a static prop, but not compiled as a static prop\n",
        v10);
    }
    ++nBitchCount;
  }
  if ( !sv.m_bIsDedicated )
  {
    if ( this->m_pClientAlphaProperty != nullptr )
    {
      g_pClientAlphaPropertyMgr->DestroyClientAlphaProperty(
        this: g_pClientAlphaPropertyMgr,
        a2: this->m_pClientAlphaProperty);
      this->m_pClientAlphaProperty = nullptr;
    }
    v11 = (IClientAlphaProperty *)g_pClientAlphaPropertyMgr->CreateClientAlphaProperty(
                                    this: g_pClientAlphaPropertyMgr,
                                    a2: this);
    this->m_pClientAlphaProperty = v11;
    v11->SetAlphaModulation(this: v11, a2: lump->m_DiffuseModulation.a);
    this->m_pClientAlphaProperty->SetDesyncOffset(this: this->m_pClientAlphaProperty, a2: index);
    ((void (__thiscall *)(IClientAlphaProperty *, _DWORD, int, _DWORD, _DWORD))this->m_pClientAlphaProperty->SetRenderFX)(
      a1: this->m_pClientAlphaProperty,
      a2: 0,
      a3: 2,
      a4: 3.4028235e38,
      a5: 0.0);
    v12 = (p_m_ModelToWorld->flags & 0x800) == 0;
    m_flForcedFadeScale = lump->m_flForcedFadeScale;
    if ( !v12 )
      m_flForcedFadeScale = 0.0;
    ((void (__thiscall *)(IClientAlphaProperty *, _DWORD, _DWORD, _DWORD))this->m_pClientAlphaProperty->SetFade)(
      a1: this->m_pClientAlphaProperty,
      a2: 0.0,
      a3: 0.0,
      a4: 0.0);
    if ( (lump->m_Flags & 1) != 0 )
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->m_pClientAlphaProperty->SetFade)(
        a1: this->m_pClientAlphaProperty,
        a2: lump->m_FadeMinDist,
        a3: lump->m_FadeMinDist,
        a4: lump->m_FadeMaxDist);
  }
  if ( this->m_nSolidType != 0 && this->m_nSolidType != 2 && this->m_nSolidType != 6 )
  {
    if ( this->m_pModel != nullptr )
      v13 = modelloader->GetName(this: modelloader, a2: this->m_pModel);
    else
      v13 = "unknown model";
    V_strncpy(pDest: v24, pSrc: v13, maxLen: 260);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_StaticPropManager,
        a2: 1,
        a3: "CStaticProp::Init:  Map error, static_prop with bogus SOLID_ flag (%d)! (%s)\n",
        this->m_nSolidType,
        v24);
    this->m_nSolidType = 0;
  }
  this->m_Alpha = -1;
  this->m_Skin = lump->m_Skin;
  this->m_Flags = lump->m_Flags & 0x24;
  this->m_nMinCPULevel = lump->m_nMinCPULevel;
  this->m_nMaxCPULevel = lump->m_nMaxCPULevel;
  m_nMinGPULevel = lump->m_nMinGPULevel;
  p_m_ModelToWorld = (studiohdr_t *)&this->m_ModelToWorld;
  this->m_nMinGPULevel = m_nMinGPULevel;
  m_nMaxGPULevel = lump->m_nMaxGPULevel;
  m_flForcedFadeScale = *(float *)&lump;
  p_m_Angles = &lump->m_Angles;
  this->m_nMaxGPULevel = m_nMaxGPULevel;
  AngleMatrix(
    angles: p_m_Angles,
    position: (const Vector *)LODWORD(m_flForcedFadeScale),
    matrix: (matrix3x4_t *)p_m_ModelToWorld);
  modelinfo->GetModelRenderBounds(
    this: modelinfo,
    a2: this->m_pModel,
    a3: &this->m_RenderBBoxMin,
    a4: &this->m_RenderBBoxMax);
  v16 = this->m_RenderBBoxMin.x - this->m_RenderBBoxMax.x;
  v17 = this->m_RenderBBoxMin.y - this->m_RenderBBoxMax.y;
  v18 = this->m_RenderBBoxMin.z - this->m_RenderBBoxMax.z;
  p_m_ModelToWorld = (studiohdr_t *)&this->m_WorldRenderBBoxMax;
  v19 = (float)((float)(v17 * v17) + (float)(v18 * v18)) + (float)(v16 * v16);
  v20 = 0;
  LODWORD(m_flForcedFadeScale) = &this->m_WorldRenderBBoxMin;
  *(float *)&v20 = fsqrt(v19);
  p_m_Angles = (const QAngle *)&this->m_RenderBBoxMax;
  szModel_252 = v20;
  p_m_RenderBBoxMin = &this->m_RenderBBoxMin;
  HIDWORD(szModel_252) = &this->m_ModelToWorld;
  this->m_flRadius = *(float *)&v20 * 0.5;
  TransformAABB(
    transform: (const matrix3x4_t *)HIDWORD(szModel_252),
    vecMinsIn: p_m_RenderBBoxMin,
    vecMaxsIn: (const Vector *)p_m_Angles,
    vecMinsOut: (Vector *)LODWORD(m_flForcedFadeScale),
    vecMaxsOut: (Vector *)p_m_ModelToWorld);
  if ( (lump->m_Flags & 2) != 0 )
    this->m_LightingOrigin = lump->m_LightingOrigin;
  else
    modelinfo->GetIlluminationPoint(
      this: modelinfo,
      a2: this->m_pModel,
      a3: &this->IClientRenderable,
      a4: &this->m_Origin,
      a5: &this->m_Angles,
      a6: &this->m_LightingOrigin);
  v21 = _CommandLine();
  g_MakingDevShots = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v21 + 40))(a1: v21, a2: "-makedevshots") != 0;
  (*(void (__thiscall **)(const QAngle *))(LODWORD(p_m_Angles->x) + 124))(a1: p_m_Angles);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DFA30
// Name: public: virtual class Vector const __near & CStaticProp::OBBMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CStaticProp::OBBMins(CStaticProp *this)
{
  Vector *v3; // edi
  float *v4; // eax

  if ( ((int (__thiscall *)(CStaticProp *))this->IClientUnknown::IHandleEntity::__vftable[1].dtr_IHandleEntity)(a1: this) == 6 )
    return (const Vector *)(LODWORD(this->m_Angles.y) + 280);
  v3 = AllocTempVector();
  v4 = (float *)this->GetClientThinkable(this);
  v3->x = this->m_ModelToWorld.m_flMatVal[2][3] - *v4;
  v3->y = this->m_flRadius - v4[1];
  v3->z = this->m_WorldRenderBBoxMin.x - v4[2];
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101DFAA0
// Name: public: virtual class Vector const __near & CStaticProp::OBBMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CStaticProp::OBBMaxs(CStaticProp *this)
{
  Vector *v3; // edi
  float *v4; // eax

  if ( ((int (__thiscall *)(CStaticProp *))this->IClientUnknown::IHandleEntity::__vftable[1].dtr_IHandleEntity)(a1: this) == 6 )
    return (const Vector *)(LODWORD(this->m_Angles.y) + 292);
  v3 = AllocTempVector();
  v4 = (float *)this->GetClientThinkable(this);
  v3->x = this->m_WorldRenderBBoxMin.y - *v4;
  v3->y = this->m_WorldRenderBBoxMin.z - v4[1];
  v3->z = this->m_WorldRenderBBoxMax.x - v4[2];
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101DFB10
// Name: public: virtual class IClientModelRenderable __near * CStaticProp::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CStaticProp::GetClientModelRenderable(CStaticProp *this)
{
  float z; // eax

  z = this->m_Angles.z;
  if ( z == 0.0
    || modelinfoclient->ModelHasMaterialProxy(this: modelinfoclient, a2: (const model_t *)LODWORD(z))
    || IsUsingStaticPropDebugModes()
    || this == (CStaticProp *)4 )
  {
    return nullptr;
  }
  else
  {
    return &this->ICollideable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DFB80
// Name: private: void CStaticProp::DisplayStaticPropInfo(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CStaticProp::DisplayStaticPropInfo(
        CStaticProp *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int nInfoType)
{
  const char *v6; // eax
  const Vector *v7; // eax
  __int128 v8; // xmm0
  int v9; // eax
  int v10; // esi
  double m_flRadius; // st7
  IClientRenderable_vtbl *v12; // edx
  int v13; // eax
  double v14; // st7
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v18; // [esp+14h] [ebp-238h]
  char v19[12]; // [esp+20h] [ebp-22Ch] BYREF
  __int128 buf_500; // [esp+220h] [ebp-2Ch] OVERLAPPED
  Vector v21; // [esp+230h] [ebp-1Ch] BYREF
  Vector vecTextBox; // [esp+23Ch] [ebp-10h]
  float retaddr; // [esp+24Ch] [ebp+0h]

  vecTextBox.y = a2;
  vecTextBox.z = retaddr;
  switch ( nInfoType )
  {
    case 1:
      v6 = modelloader->GetName(this: modelloader, a2: this->m_pModel);
      V_snprintf(pDest: v19, maxLen: 512, pFormat: v6);
      break;
    case 2:
      V_snprintf(pDest: v19, maxLen: 512, pFormat: "%d", this->m_EntHandle.m_Index & 0xBFFFFFFF);
      break;
    case 3:
      v7 = this->GetRenderOrigin(this: &this->IClientRenderable);
      v8 = 0;
      *(float *)&v8 = fsqrt(
                        (float)((float)((float)(v7->y - s_StaticPropMgr.m_vecLastViewOrigin.y)
                                      * (float)(v7->y - s_StaticPropMgr.m_vecLastViewOrigin.y))
                              + (float)((float)(v7->z - s_StaticPropMgr.m_vecLastViewOrigin.z)
                                      * (float)(v7->z - s_StaticPropMgr.m_vecLastViewOrigin.z)))
                      + (float)((float)(v7->x - s_StaticPropMgr.m_vecLastViewOrigin.x)
                              * (float)(v7->x - s_StaticPropMgr.m_vecLastViewOrigin.x)));
      buf_500 = v8;
      V_snprintf(pDest: v19, maxLen: 512, pFormat: "%.1f", *(float *)&v8);
      break;
    case 4:
      v9 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a4);
      v10 = v9;
      if ( v9 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
      m_flRadius = this->m_flRadius;
      v12 = this->IClientRenderable::__vftable;
      LODWORD(vecTextBox.x) = *(_DWORD *)v10 + 312;
      v18 = m_flRadius;
      v13 = ((int (__cdecl *)(_DWORD))v12->GetRenderOrigin)(a1: LODWORD(v18));
      v14 = ((double (__thiscall *)(int, int))*(_DWORD *)LODWORD(vecTextBox.x))(a1: v10, a2: v13);
      V_snprintf(pDest: v19, maxLen: 512, pFormat: "%.1f", v14);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 12))(a1: v10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
      break;
    default:
      break;
  }
  v15 = (float)(this->m_WorldRenderBBoxMin.y + this->m_WorldRenderBBoxMax.y) * 0.5;
  v21.x = (float)(this->m_WorldRenderBBoxMin.x + this->m_WorldRenderBBoxMax.x) * 0.5;
  v16 = this->m_WorldRenderBBoxMax.z + 10.0;
  v21.y = v15;
  v21.z = v16;
  CDebugOverlay::AddTextOverlay(textPos: &v21, duration: 0.0, text: v19);
}

//------------------------------------------------------------------------------
// Address: 0x101DFD80
// Name: public: int CStaticProp::DrawModelSlow(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CStaticProp::DrawModelSlow@<eax>(
        CStaticProp *this@<ecx>,
        int a2@<esi>,
        int flags,
        const RenderableInstance_t *instance)
{
  int m_nValue; // eax
  unsigned __int16 v6; // ax
  int v7; // eax
  IMatRenderContext *v8; // eax
  int v9; // esi
  unsigned __int8 m_nSolidType; // cl
  vcollide_t *v11; // eax
  ModelRenderInfo_t sInfo; // [esp+28h] [ebp-4Ch] BYREF
  unsigned __int16 hash[4]; // [esp+6Ch] [ebp-8h] BYREF
  int savedregs; // [esp+74h] [ebp+0h] BYREF
  int flagsa; // [esp+7Ch] [ebp+8h]
  int drawn; // [esp+80h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStaticProp::DrawModel",
    a3: 0,
    a4: "Static_Prop_Rendering",
    a5: false,
    a6: 4);
  if ( r_drawstaticprops.m_pParent == nullptr )
    goto LABEL_29;
  m_nValue = r_drawstaticprops.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    goto LABEL_29;
  if ( m_nValue == 2 || r_slowpathwireframe.m_pParent != nullptr && r_slowpathwireframe.m_pParent->m_Value.m_nValue != 0 )
    flags |= 0x20u;
  if ( instance->m_nAlpha != 0 && this->m_pModel != nullptr )
  {
    if ( r_colorstaticprops.m_pParent != nullptr && r_colorstaticprops.m_pParent->m_Value.m_nValue != 0 )
    {
      hash[0] = HashBlock(pKey: &this->m_ModelInstance, size: 2u);
      hash[1] = HashBlock(pKey: hash, size: 2u);
      v6 = HashBlock(pKey: &hash[1], size: 2u);
      r_colormod.x = (float)hash[0] * 0.000015259022;
      hash[2] = v6;
      r_colormod.y = (float)hash[1] * 0.000015259022;
      r_colormod.z = (float)v6 * 0.000015259022;
      VectorNormalize(vec: &r_colormod);
    }
    flagsa = flags | 0x10;
    if ( r_staticpropinfo.m_pParent != nullptr )
    {
      v7 = r_staticpropinfo.m_pParent->m_Value.m_nValue;
      if ( v7 != 0 )
        CStaticProp::DisplayStaticPropInfo(
          this,
          a2: COERCE_FLOAT(&savedregs),
          a3: (int)this,
          a4: (int)instance,
          nInfoType: v7);
    }
    memset(&sInfo.pModelToWorld, 0, 12);
    CStaticProp::InitModelRenderInfo(this, &sInfo, flags: flagsa);
    ((void (__thiscall *)(IStudioRender *, Vector *, int))g_pStudioRender->SetColorModulation)(
      a1: g_pStudioRender,
      a2: &r_colormod,
      a3: a2);
    ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: (float)instance->m_nAlpha * 0.0039215689);
    v8 = materials->GetRenderContext(this: materials);
    v9 = (int)v8;
    if ( v8 != nullptr )
      v8->BeginRender(this: v8);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 80))(a1: v9, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 84))(a1: v9);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9);
    drawn = modelrender->DrawModelEx(this: modelrender, a2: &sInfo);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 80))(a1: v9, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 88))(a1: v9);
    if ( this->m_pModel != nullptr && (flagsa & 0x100) != 0 )
    {
      m_nSolidType = this->m_nSolidType;
      if ( m_nSolidType == 6 )
      {
        v11 = CM_VCollideForModel(modelindex: -1, pModel: this->m_pModel);
        if ( v11 != nullptr && (*(_WORD *)v11 & 0x7FFF) == 1 )
          DebugDrawPhysCollide(
            a1: 0,
            a2: (int)&this->m_ModelToWorld,
            a3: v9,
            pCollide: *v11->solids,
            pMaterial: nullptr,
            transform: &this->m_ModelToWorld,
            color: &debugColor,
            drawAxes: false);
      }
      else if ( m_nSolidType == 2 )
      {
        if ( (_S1_19 & 1) == 0 )
        {
          _S1_19 |= 1u;
          debugColor_0 = (Color)-256;
        }
        RenderWireframeBox(
          vOrigin: &this->m_Origin,
          angles: &vec3_angle,
          vMins: &this->m_pModel->mins,
          vMaxs: &this->m_pModel->maxs,
          c: debugColor_0,
          bZBuffer: true);
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return drawn;
  }
  else
  {
LABEL_29:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0060
// Name: public: virtual int CStaticProp::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticProp::DrawModel(CStaticProp *this, int flags, const RenderableInstance_t *instance)
{
  IMatRenderContext *v4; // esi
  int v5; // edi
  int v7; // esi
  ModelRenderInfo_t sInfo; // [esp+24h] [ebp-44h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStaticProp::DrawModel",
    a3: 0,
    a4: "Static_Prop_Rendering",
    a5: false,
    a6: 4);
  if ( instance->m_nAlpha != 0 && LODWORD(this->m_Angles.z) != 0 )
  {
    if ( IsUsingStaticPropDebugModes() || (flags & 0x120) != 0 )
    {
      v7 = CStaticProp::DrawModelSlow(this: (CStaticProp *)((char *)this - 4), a2: (int)this, flags, instance);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return v7;
    }
    else
    {
      memset(&sInfo.pModelToWorld, 0, 12);
      CStaticProp::InitModelRenderInfo(this: (CStaticProp *)((char *)this - 4), &sInfo, flags: flags | 0x10);
      g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: (const float *)&r_colormod);
      ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: (float)instance->m_nAlpha * 0.0039215689);
      v4 = materials->GetRenderContext(this: materials);
      if ( v4 != nullptr )
        v4->BeginRender(this: v4);
      v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
      v4->PushMatrix(this: v4);
      v4->LoadIdentity(this: v4);
      v5 = modelrender->DrawModelExStaticProp(this: modelrender, a2: v4, a3: &sInfo);
      v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
      v4->PopMatrix(this: v4);
      v4->EndRender(this: v4);
      v4->Release(this: v4);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return v5;
    }
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E01E0
// Name: private: void CStaticPropMgr::UpdatePropVisibility(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::UpdatePropVisibility(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        BOOL a4@<esi>,
        int nCPULevel,
        int nGPULevel)
{
  CStaticProp *v6; // edi
  bool v7; // al
  unsigned __int8 m_nMinCPULevel; // al
  unsigned __int8 m_nMaxCPULevel; // al
  unsigned __int8 m_nMinGPULevel; // al
  unsigned __int8 m_nMaxGPULevel; // al
  IVModelInfo_vtbl *v12; // ebx
  IClientRenderable *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  IClientLeafSystemEngine_vtbl *v17; // ebx
  IClientLeafSystemEngine_vtbl *v18; // ebx
  unsigned __int16 *v19; // eax
  unsigned __int16 *v20; // eax
  RenderableTranslucencyType_t nType; // [esp+0h] [ebp-10h]
  int m_Size; // [esp+4h] [ebp-Ch]
  CStaticPropMgr *v26; // [esp+8h] [ebp-8h]
  int v27; // [esp+Ch] [ebp-4h]

  v26 = this;
  if ( this->m_bClientInitialized && this->m_StaticProps.m_Size > 0 )
  {
    v27 = 0;
    m_Size = this->m_StaticProps.m_Size;
    while ( 1 )
    {
      v6 = &this->m_StaticProps.m_Memory.m_pMemory[v27];
      v7 = false;
      if ( nCPULevel >= 0 )
      {
        m_nMinCPULevel = v6->m_nMinCPULevel;
        v7 = true;
        if ( m_nMinCPULevel == 0 || m_nMinCPULevel - 1 <= nCPULevel )
        {
          m_nMaxCPULevel = v6->m_nMaxCPULevel;
          if ( m_nMaxCPULevel == 0 || m_nMaxCPULevel - 1 >= nCPULevel )
            v7 = false;
        }
      }
      if ( nGPULevel < 0 )
      {
        if ( v7 )
          goto LABEL_18;
      }
      else if ( v7
             || (m_nMinGPULevel = v6->m_nMinGPULevel) != 0 && m_nMinGPULevel - 1 > nGPULevel
             || (m_nMaxGPULevel = v6->m_nMaxGPULevel) != 0 && m_nMaxGPULevel - 1 < nGPULevel )
      {
LABEL_18:
        if ( v6->m_RenderHandle != 0xFFFF )
        {
          clientleafsystem->RemoveRenderable(this: clientleafsystem, a2: v6->m_RenderHandle);
          v6->m_RenderHandle = -1;
        }
        goto LABEL_20;
      }
      if ( v6->m_LeafCount == 0 )
        goto LABEL_18;
      v12 = modelinfo->__vftable;
      v13 = &v6->IClientRenderable;
      v14 = ((int (__thiscall *)(IClientRenderable *, int, BOOL, int))v6->GetBody)(
              a1: &v6->IClientRenderable,
              a2: a3,
              a3: a4,
              a4: a2);
      v15 = ((int (__thiscall *)(IClientRenderable *, int))v6->GetSkin)(a1: &v6->IClientRenderable, a2: v14);
      v16 = ((int (__thiscall *)(IVModelInfo *, model_t *, int))v12->ComputeTranslucencyType)(
              a1: modelinfo,
              a2: v6->m_pModel,
              a3: v15);
      if ( *(_WORD *)((int (__thiscall *)(IClientRenderable *, int))v6->RenderHandle)(
                       a1: &v6->IClientRenderable,
                       a2: v16) == 0xFFFF )
      {
        a2 = -1;
        ((void (__thiscall *)(IClientLeafSystemEngine *, IClientRenderable *, _DWORD, int, int))clientleafsystem->CreateRenderableHandle)(
          a1: clientleafsystem,
          a2: &v6->IClientRenderable,
          a3: 0,
          a4: v16,
          a5: 2);
        v20 = v13->RenderHandle(this: &v6->IClientRenderable);
        clientleafsystem->AddRenderableToLeaves(
          this: clientleafsystem,
          a2: *v20,
          a3: v6->m_LeafCount,
          a4: (unsigned __int16 *)&v26->m_StaticPropLeaves.m_Memory.m_pMemory[v6->m_FirstLeaf]);
      }
      else
      {
        v17 = clientleafsystem->__vftable;
        a2 = *(unsigned __int16 *)((int (__thiscall *)(IClientRenderable *, RenderableTranslucencyType_t))v13->RenderHandle)(
                                    a1: &v6->IClientRenderable,
                                    a2: nType);
        ((void (__thiscall *)(IClientLeafSystemEngine *))v17->SetTranslucencyType)(a1: clientleafsystem);
      }
      v18 = clientleafsystem->__vftable;
      v19 = v13->RenderHandle(this: &v6->IClientRenderable);
      a4 = (v6->m_Flags & 0x20) != 0;
      a3 = *v19;
      ((void (__thiscall *)(IClientLeafSystemEngine *))v18->RenderInFastReflections)(a1: clientleafsystem);
LABEL_20:
      ++v27;
      if ( --m_Size == 0 )
        return;
      this = v26;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E03B0
// Name: public: virtual void CStaticPropMgr::LevelShutdownClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::LevelShutdownClient(CStaticPropMgr *this)
{
  int v2; // edi
  unsigned int v3; // edi
  CStaticProp *m_pMemory; // esi
  CStaticProp *v5; // esi
  IVModelRender_vtbl *v6; // esi
  unsigned __int16 v7; // ax
  int i; // [esp+4h] [ebp-4h]

  if ( this->m_bClientInitialized )
  {
    v2 = this->m_StaticProps.m_Size - 1;
    i = v2;
    if ( v2 >= 0 )
    {
      v3 = v2;
      do
      {
        m_pMemory = this->m_StaticProps.m_Memory.m_pMemory;
        if ( m_pMemory[v3].m_pClientAlphaProperty != nullptr )
        {
          g_pClientAlphaPropertyMgr->DestroyClientAlphaProperty(
            this: g_pClientAlphaPropertyMgr,
            a2: m_pMemory[v3].m_pClientAlphaProperty);
          m_pMemory[v3].m_pClientAlphaProperty = nullptr;
        }
        v5 = this->m_StaticProps.m_Memory.m_pMemory;
        if ( v5[v3].m_RenderHandle != 0xFFFF )
        {
          clientleafsystem->RemoveRenderable(this: clientleafsystem, a2: v5[v3].m_RenderHandle);
          v5[v3].m_RenderHandle = -1;
        }
        v6 = modelrender->__vftable;
        v7 = ((int (__thiscall *)(IClientRenderable *, _DWORD))this->m_StaticProps.m_Memory.m_pMemory[v3].GetModelInstance)(
               a1: &this->m_StaticProps.m_Memory.m_pMemory[v3].IClientRenderable,
               a2: 0);
        ((void (__thiscall *)(IVModelRender *, _DWORD))v6->SetStaticLighting)(a1: modelrender, a2: v7);
        --v3;
        --i;
      }
      while ( i >= 0 );
    }
    ClearStaticLightingCache();
    this->m_bClientInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0470
// Name: public: virtual void CStaticPropMgr::CreateVPhysicsRepresentations(class IPhysicsEnvironment __near *,class IVPhysicsKeyHandler __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::CreateVPhysicsRepresentations(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        struct CPhysCollide *a3@<esi>,
        IPhysicsEnvironment *pPhysEnv,
        IVPhysicsKeyHandler *pDefaults,
        void *pGameData)
{
  int v6; // edi
  int v7; // eax
  CStaticPropMgr::StaticPropDict_t *m_pElements; // ebx
  char v9; // cl
  char *v10; // ebx
  const model_t *v11; // eax
  vcollide_t *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  struct CPhysCollide *v16; // edi
  IVPhysicsKeyParser *v17; // esi
  const char *v18; // eax
  int v19; // eax
  IVPhysicsKeyParser_vtbl *v20; // edx
  int v21; // eax
  const char *v22; // eax
  int v23; // eax
  int v24; // eax
  IPhysicsEnvironment_vtbl *v25; // edx
  int v26; // eax
  char v27; // bl
  int v28; // esi
  char *v31; // [esp+0h] [ebp-75Ch]
  char *v32; // [esp+4h] [ebp-758h] BYREF
  objectparams_t *v33; // [esp+8h] [ebp-754h]
  char v34[532]; // [esp+404h] [ebp-358h] BYREF
  objectparams_t v35; // [esp+618h] [ebp-144h] BYREF
  char pDest[260]; // [esp+644h] [ebp-118h] BYREF
  int v37; // [esp+748h] [ebp-14h]
  CStaticPropMgr *v38; // [esp+74Ch] [ebp-10h]
  int v39; // [esp+750h] [ebp-Ch]
  int contents; // [esp+754h] [ebp-8h]
  int i; // [esp+758h] [ebp-4h]

  v6 = this->m_StaticProps.m_Memory.m_nGrowSize - 1;
  v38 = this;
  i = v6;
  if ( v6 >= 0 )
  {
    v7 = 200 * v6;
    v39 = 200 * v6;
    while ( 1 )
    {
      m_pElements = this->m_StaticPropDict.m_pElements;
      v9 = *((_BYTE *)&m_pElements[12].m_pModel + v7 + 1);
      v10 = (char *)m_pElements + v7;
      if ( v9 == 0 )
        goto LABEL_31;
      v11 = *((const model_t **)v10 + 10);
      v12 = nullptr;
      contents = -1;
      if ( v11 != nullptr )
      {
        if ( v9 == 6 )
          v12 = CM_VCollideForModel(modelindex: -1, pModel: v11);
        v13 = *((_DWORD *)v10 + 10);
        v14 = *(_DWORD *)(v13 + 272);
        if ( v14 == 3 )
        {
          v15 = *(unsigned __int16 *)(v13 + 312);
          if ( (_WORD)v15 != 0xFFFF )
            contents = mdlcache->GetStudioHdr(this: mdlcache, a2: v15)->contents;
        }
        else if ( v14 == 1 )
        {
          contents = *(_DWORD *)((*(unsigned __int16 *)(v13 + 334) << 6) + *(_DWORD *)(*(_DWORD *)(v13 + 312) + 84));
        }
        if ( v12 != nullptr )
          break;
      }
      v21 = *((_DWORD *)v10 + 10);
      if ( v10[49] == 2 )
      {
        v23 = ((int (__thiscall *)(IPhysicsCollision *, int, int, struct CPhysCollide *, int))physcollision->BBoxToCollide)(
                a1: physcollision,
                a2: v21 + 280,
                a3: v21 + 292,
                a4: a3,
                a5: a2);
        v35 = g_PhysDefaultObjectParams;
        v37 = v23;
        v16 = (struct CPhysCollide *)v23;
LABEL_28:
        v35.pGameData = pGameData;
        v35.enableCollisions = true;
        v35.pName = "prop_static";
        v24 = ((int (__thiscall *)(IPhysicsSurfaceProps *, char *, char *, char *, objectparams_t *))physprops->GetSurfaceIndex)(
                a1: physprops,
                a2: v34,
                a3: v31,
                a4: v32,
                a5: v33);
        v25 = pPhysEnv->__vftable;
        v33 = &v35;
        v32 = v10 + 28;
        v31 = v10 + 16;
        a2 = v24;
        a3 = v16;
        v26 = ((int (__thiscall *)(IPhysicsEnvironment *))v25->CreatePolyObjectStatic)(a1: pPhysEnv);
        v27 = contents;
        v28 = v26;
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v26 + 164))(a1: v26, a2: contents);
        if ( (v27 & 1) != 0 )
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v28 + 336))(a1: v28, a2: 2);
        v6 = i;
        goto LABEL_31;
      }
      if ( v21 != 0 )
        v22 = modelloader->GetName(this: modelloader, a2: *((_DWORD *)v10 + 10));
      else
        v22 = "unknown model";
      V_strncpy(pDest, pSrc: v22, maxLen: 260);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_StaticPropManager,
          a2: 1,
          a3: "Map Error:  Static prop with bogus solid type %d! (%s)\n",
          (unsigned __int8)v10[49],
          pDest);
      v10[49] = 0;
LABEL_31:
      --v6;
      v7 = v39 - 200;
      i = v6;
      v39 -= 200;
      if ( v6 < 0 )
        return;
      this = v38;
    }
    v16 = *v12->solids;
    v17 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, struct CPhysCollide *, int))physcollision->VPhysicsKeyParserCreate)(
                                  a1: physcollision,
                                  a2: v12,
                                  a3,
                                  a4: a2);
    if ( !v17->Finished(this: v17) )
    {
      while ( 1 )
      {
        v18 = v17->GetCurrentBlockName(this: v17);
        v19 = _V_stricmp(s1: v18, s2: "solid");
        v20 = v17->__vftable;
        if ( v19 == 0 )
          break;
        v20->SkipBlock(this: v17);
        if ( v17->Finished(this: v17) )
          goto LABEL_19;
      }
      v20->ParseSolid(this: v17, a2: (solid_t *)&v32, a3: pDefaults);
    }
LABEL_19:
    physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v17);
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0700
// Name: public: virtual class ICollideable __near * CStaticPropMgr::GetStaticProp(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CStaticPropMgr::GetStaticProp(CStaticPropMgr *this, IHandleEntity *pHandleEntity)
{
  signed int m_Index; // eax
  CStaticProp *v4; // eax

  if ( pHandleEntity != nullptr )
  {
    if ( (pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index & 0xFFFF0000) != 0x40000000 )
      return nullptr;
    m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
    if ( m_Index == -1 )
      m_Index = 0x1FFF;
    else
      m_Index = (unsigned __int16)m_Index;
  }
  else
  {
    m_Index = -1;
  }
  if ( m_Index >= 0 && m_Index <= this->m_StaticProps.m_Size )
  {
    v4 = &this->m_StaticProps.m_Memory.m_pMemory[m_Index];
    if ( v4 != nullptr )
      return &v4->ICollideable;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E0770
// Name: public: virtual class ICollideable __near * CStaticPropMgr::GetStaticPropByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CStaticPropMgr::StaticPropDict_t *__thiscall CStaticPropMgr::GetStaticPropByIndex(CStaticPropMgr *this, int propIndex)
{
  CStaticPropMgr::StaticPropDict_t *v2; // eax

  if ( propIndex < this->m_StaticProps.m_Memory.m_nGrowSize
    && (v2 = &this->m_StaticPropDict.m_pElements[50 * propIndex]) != nullptr )
  {
    return v2 + 2;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E07A0
// Name: private: void CStaticPropMgr::PrecacheLighting(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStaticPropMgr::PrecacheLighting(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        float a4@<xmm0>)
{
  CStaticPropMgr *v4; // esi
  int v5; // ebx
  IMDLCache *v6; // edi
  CStaticProp *v7; // esi
  IEngineVGuiInternal *v8; // eax
  PropLightcache_t *StaticLightingCache; // [esp+4h] [ebp-Ch] BYREF
  CStaticPropMgr *v12; // [esp+8h] [ebp-8h]
  int m_Size; // [esp+Ch] [ebp-4h]

  v4 = this;
  v12 = this;
  _COM_TimestampedLog(a1: "CStaticPropMgr::PrecacheLighting - start");
  if ( v4->m_StaticProps.m_Size > 0 )
  {
    v5 = 0;
    m_Size = v4->m_StaticProps.m_Size;
    while ( 1 )
    {
      v6 = g_pMDLCache;
      ((void (__thiscall *)(IMDLCache *, int, int))g_pMDLCache->BeginLock)(a1: g_pMDLCache, a2: a3, a3: a2);
      v7 = &v4->m_StaticProps.m_Memory.m_pMemory[v5];
      if ( v7->m_ModelInstance == 0xFFFF )
      {
        StaticLightingCache = CreateStaticLightingCache(
                                a1: a4,
                                origin: &v7->m_LightingOrigin,
                                mins: &v7->m_WorldRenderBBoxMin,
                                maxs: &v7->m_WorldRenderBBoxMax);
        v7->m_ModelInstance = modelrender->CreateInstance(
                                this: modelrender,
                                a2: &v7->IClientRenderable,
                                a3: (LightCacheHandle_t__ **)&StaticLightingCache);
      }
      v8 = EngineVGui();
      a2 = 1;
      a3 = 24;
      ((void (__thiscall *)(IEngineVGuiInternal *))v8->UpdateProgressBar)(a1: v8);
      v6->EndLock(this: v6);
      ++v5;
      if ( --m_Size == 0 )
        break;
      v4 = v12;
    }
  }
  _COM_TimestampedLog(a1: "CStaticPropMgr::PrecacheLighting - end");
}

//------------------------------------------------------------------------------
// Address: 0x101E0870
// Name: public: virtual void CStaticPropMgr::RecomputeStaticLighting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::RecomputeStaticLighting(CStaticPropMgr *this)
{
  int v2; // edi
  int v3; // esi

  v2 = this->m_StaticProps.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      if ( *this->m_StaticProps.m_Memory.m_pMemory[v3].RenderHandle(this: &this->m_StaticProps.m_Memory.m_pMemory[v3].IClientRenderable) != 0xFFFF )
        ((void (__stdcall *)(_DWORD))modelrender->RecomputeStaticLighting)(a1: this->m_StaticProps.m_Memory.m_pMemory[v3].m_ModelInstance);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E08C0
// Name: public: virtual bool CStaticPropMgr::IsPropInPVS(class IHandleEntity __near *,unsigned char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStaticPropMgr::IsPropInPVS(
        CStaticPropMgr *this,
        IHandleEntity *pHandleEntity,
        const unsigned __int8 *pVis)
{
  unsigned int m_Index; // eax
  CStaticProp *v5; // eax
  unsigned int m_FirstLeaf; // esi
  unsigned int v7; // edi
  int v8; // eax

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index == -1 )
    m_Index = 0x1FFF;
  else
    m_Index = (unsigned __int16)m_Index;
  v5 = &this->m_StaticProps.m_Memory.m_pMemory[m_Index];
  m_FirstLeaf = v5->m_FirstLeaf;
  v7 = m_FirstLeaf + v5->m_LeafCount;
  if ( m_FirstLeaf >= v7 )
    return 0;
  while ( 1 )
  {
    v8 = CM_LeafCluster(leafnum: this->m_StaticPropLeaves.m_Memory.m_pMemory[m_FirstLeaf].m_Leaf);
    if ( ((unsigned __int8)(1 << (v8 & 7)) & pVis[v8 >> 3]) != 0 )
      break;
    if ( (int)++m_FirstLeaf >= (int)v7 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E0950
// Name: public: void CStaticPropMgr::DrawStaticProps_Slow(class IClientRenderable __near * __near *,struct RenderableInstance_t const __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::DrawStaticProps_Slow(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        IClientRenderable **pProps,
        const RenderableInstance_t *pInstances,
        int count,
        bool bShadowDepth,
        bool drawVCollideWireframe)
{
  IMDLCache *m_pCache; // edi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  IClientRenderable *v9; // edi
  CStaticProp *v10; // edi
  int v11; // ebx
  int m_nValue; // eax
  unsigned __int16 v13; // ax
  int v14; // ebx
  int v15; // eax
  IMatRenderContext *v16; // esi
  unsigned __int8 m_nSolidType; // cl
  vcollide_t *v18; // eax
  ModelRenderInfo_t sInfo; // [esp+28h] [ebp-54h] BYREF
  unsigned __int16 pKey; // [esp+6Ch] [ebp-10h] BYREF
  _WORD v22[3]; // [esp+6Eh] [ebp-Eh] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+74h] [ebp-8h]
  int flags; // [esp+78h] [ebp-4h]
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF
  int i; // [esp+90h] [ebp+14h]

  m_pCache = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  flags = 1;
  if ( bShadowDepth )
    flags = 1073741825;
  if ( drawVCollideWireframe )
    flags |= 0x100u;
  i = 0;
  if ( count > 0 )
  {
    do
    {
      v9 = pProps[i];
      if ( v9 != nullptr )
        v10 = (CStaticProp *)&v9[-1];
      else
        v10 = nullptr;
      v11 = flags;
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "CStaticProp::DrawModel",
        a3: 0,
        a4: "Static_Prop_Rendering",
        a5: false,
        a6: 4);
      if ( r_drawstaticprops.m_pParent == nullptr )
        goto LABEL_36;
      m_nValue = r_drawstaticprops.m_pParent->m_Value.m_nValue;
      if ( m_nValue == 0 )
        goto LABEL_36;
      if ( m_nValue == 2
        || r_slowpathwireframe.m_pParent != nullptr && r_slowpathwireframe.m_pParent->m_Value.m_nValue != 0 )
      {
        v11 = flags | 0x20;
      }
      if ( pInstances[i].m_nAlpha != 0 && v10->m_pModel != nullptr )
      {
        if ( r_colorstaticprops.m_pParent != nullptr && r_colorstaticprops.m_pParent->m_Value.m_nValue != 0 )
        {
          pKey = HashBlock(pKey: &v10->m_ModelInstance, size: 2u);
          v22[0] = HashBlock(&pKey, size: 2u);
          v13 = HashBlock(pKey: v22, size: 2u);
          r_colormod.x = (float)pKey * 0.000015259022;
          v22[1] = v13;
          r_colormod.y = (float)v22[0] * 0.000015259022;
          r_colormod.z = (float)v13 * 0.000015259022;
          VectorNormalize(vec: &r_colormod);
        }
        v14 = v11 | 0x10;
        if ( r_staticpropinfo.m_pParent != nullptr )
        {
          v15 = r_staticpropinfo.m_pParent->m_Value.m_nValue;
          if ( v15 != 0 )
            CStaticProp::DisplayStaticPropInfo(
              this: v10,
              a2: COERCE_FLOAT(&savedregs),
              a3: (int)v10,
              a4: 0,
              nInfoType: v15);
        }
        memset(&sInfo.pModelToWorld, 0, 12);
        CStaticProp::InitModelRenderInfo(this: v10, &sInfo, flags: v14);
        ((void (__thiscall *)(IStudioRender *, Vector *, int))g_pStudioRender->SetColorModulation)(
          a1: g_pStudioRender,
          a2: &r_colormod,
          a3: a2);
        ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: (float)pInstances[i].m_nAlpha * 0.0039215689);
        v16 = materials->GetRenderContext(this: materials);
        if ( v16 != nullptr )
          v16->BeginRender(this: v16);
        a2 = 10;
        ((void (__thiscall *)(IMatRenderContext *))v16->MatrixMode)(a1: v16);
        v16->PushMatrix(this: v16);
        v16->LoadIdentity(this: v16);
        modelrender->DrawModelEx(this: modelrender, a2: &sInfo);
        v16->MatrixMode(this: v16, a2: MATERIAL_MODEL);
        v16->PopMatrix(this: v16);
        if ( v10->m_pModel != nullptr && (v14 & 0x100) != 0 )
        {
          m_nSolidType = v10->m_nSolidType;
          if ( m_nSolidType == 6 )
          {
            v18 = CM_VCollideForModel(modelindex: -1, pModel: v10->m_pModel);
            if ( v18 != nullptr && (*(_WORD *)v18 & 0x7FFF) == 1 )
              DebugDrawPhysCollide(
                a1: v14,
                a2: (int)&v10->m_ModelToWorld,
                a3: (int)v16,
                pCollide: *v18->solids,
                pMaterial: nullptr,
                transform: &v10->m_ModelToWorld,
                color: &debugColor,
                drawAxes: false);
          }
          else if ( m_nSolidType == 2 )
          {
            if ( (_S1_19 & 1) == 0 )
            {
              _S1_19 |= 1u;
              debugColor_0 = (Color)-256;
            }
            RenderWireframeBox(
              vOrigin: &v10->m_Origin,
              angles: &vec3_angle,
              vMins: &v10->m_pModel->mins,
              vMaxs: &v10->m_pModel->maxs,
              c: debugColor_0,
              bZBuffer: true);
          }
        }
        v16->EndRender(this: v16);
        v16->Release(this: v16);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      else
      {
LABEL_36:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      ++i;
    }
    while ( i < count );
    m_pCache = cacheCriticalSection.m_pCache;
  }
  m_pCache->EndLock(this: m_pCache);
}

//------------------------------------------------------------------------------
// Address: 0x101E0C90
// Name: public: void CStaticPropMgr::DrawStaticProps_Fast(class IClientRenderable __near * __near *,struct RenderableInstance_t const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::DrawStaticProps_Fast(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IClientRenderable **pProps,
        const RenderableInstance_t *pInstances,
        int count,
        bool bShadowDepth)
{
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // edi
  int v9; // ebx
  IMDLCache *v10; // esi
  IClientRenderable *v11; // ecx
  IClientRenderable *v12; // eax
  ModelRenderInfo_t sInfo; // [esp+10h] [ebp-50h] BYREF
  float color[3]; // [esp+54h] [ebp-Ch] BYREF

  color[2] = 1.0;
  color[1] = 1.0;
  color[0] = 1.0;
  ((void (__thiscall *)(IStudioRender *, float *, int, int))g_pStudioRender->SetColorModulation)(
    a1: g_pStudioRender,
    a2: color,
    a3,
    a4: a2);
  ((void (__stdcall *)(_DWORD))g_pStudioRender->SetAlphaModulation)(a1: 1.0);
  g_pStudioRender->SetViewState(
    this: g_pStudioRender,
    a2: &g_CurrentViewOrigin,
    a3: &g_CurrentViewRight,
    a4: &g_CurrentViewUp,
    a5: &g_CurrentViewForward);
  v7 = materials->GetRenderContext(this: materials);
  v8 = v7;
  v9 = 0;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v8->MatrixMode(this: v8, a2: MATERIAL_MODEL);
  v8->PushMatrix(this: v8);
  v8->LoadIdentity(this: v8);
  sInfo.pModelToWorld = nullptr;
  sInfo.pLightingOrigin = nullptr;
  sInfo.flags = 17;
  if ( bShadowDepth )
    sInfo.flags = 1073741841;
  sInfo.entity_index = -1;
  sInfo.body = 0;
  sInfo.hitboxset = 0;
  sInfo.pLightingOffset = nullptr;
  if ( count > 0 )
  {
    do
    {
      v10 = g_pMDLCache;
      g_pMDLCache->BeginLock(this: g_pMDLCache);
      v11 = pProps[v9];
      if ( v11 != nullptr )
        v12 = v11 - 1;
      else
        v12 = nullptr;
      if ( v12[10].__vftable != nullptr )
      {
        sInfo.instance = HIWORD(v12[11].__vftable);
        sInfo.pModel = (const model_t *)v12[10].__vftable;
        sInfo.origin = *(Vector *)&v12[4].__vftable;
        sInfo.angles = *(QAngle *)&v12[7].__vftable;
        sInfo.skin = BYTE2(v12[12].__vftable);
        sInfo.pLightingOrigin = (const Vector *)&v12[43];
        sInfo.pRenderable = v11;
        sInfo.pModelToWorld = (const matrix3x4_t *)&v12[24];
        modelrender->DrawModelExStaticProp(this: modelrender, a2: v8, a3: &sInfo);
      }
      v10->EndLock(this: v10);
      ++v9;
    }
    while ( v9 < count );
  }
  ((void (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IClientRenderable *, const model_t *, const matrix3x4_t *, const matrix3x4_t *, const Vector *, int, int, int, int, int, _DWORD, _DWORD))v8->MatrixMode)(
    a1: v8,
    a2: 10,
    a3: LODWORD(sInfo.origin.x),
    a4: LODWORD(sInfo.origin.y),
    a5: LODWORD(sInfo.origin.z),
    a6: LODWORD(sInfo.angles.x),
    a7: LODWORD(sInfo.angles.y),
    a8: LODWORD(sInfo.angles.z),
    a9: sInfo.pRenderable,
    a10: sInfo.pModel,
    a11: sInfo.pModelToWorld,
    a12: sInfo.pLightingOffset,
    a13: sInfo.pLightingOrigin,
    a14: sInfo.flags,
    a15: sInfo.entity_index,
    a16: sInfo.skin,
    a17: sInfo.body,
    a18: sInfo.hitboxset,
    a19: *(_DWORD *)&sInfo.instance,
    a20: LODWORD(color[0]));
  v8->PopMatrix(this: v8);
  v8->EndRender(this: v8);
  v8->Release(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x101E0E50
// Name: public: virtual void CStaticPropMgr::DrawStaticProps(class IClientRenderable __near * __near *,struct RenderableInstance_t const __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::DrawStaticProps(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IClientRenderable **pProps,
        const RenderableInstance_t *pInstances,
        int count,
        BOOL bShadowDepth,
        bool drawVCollideWireframe)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStaticPropMgr::DrawStaticProps",
    a3: 0,
    a4: "Static_Prop_Rendering",
    a5: false,
    a6: 4);
  if ( r_drawstaticprops.m_pParent == nullptr
    || r_drawstaticprops.m_pParent->m_Value.m_nValue == 0
    || cl_skipslowpath.m_pParent != nullptr && cl_skipslowpath.m_pParent->m_Value.m_nValue != 0 )
  {
    goto LABEL_14;
  }
  if ( IsUsingStaticPropDebugModes()
    || drawVCollideWireframe
    || r_slowpathwireframe.m_pParent != nullptr && r_slowpathwireframe.m_pParent->m_Value.m_nValue != 0 )
  {
    CStaticPropMgr::DrawStaticProps_Slow(
      this: (CStaticPropMgr *)((char *)this - 4),
      a2,
      pProps,
      pInstances,
      count,
      bShadowDepth,
      drawVCollideWireframe);
LABEL_14:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  if ( pipeline_static_props.m_pParent != nullptr && pipeline_static_props.m_pParent->m_Value.m_nValue != 0 )
  {
    CStaticPropMgr::DrawStaticProps_FastPipeline(
      this: (CStaticPropMgr *)((char *)this - 4),
      pProps,
      pInstances,
      count,
      bShadowDepth);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CStaticPropMgr::DrawStaticProps_Fast(
      this: (CStaticPropMgr *)((char *)this - 4),
      a2,
      a3,
      pProps,
      pInstances,
      count,
      bShadowDepth);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E0F50
// Name: public: virtual struct LightCacheHandle_t__ __near * CStaticPropMgr::GetLightCacheHandleForStaticProp(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
LightCacheHandle_t__ *__thiscall CStaticPropMgr::GetLightCacheHandleForStaticProp(
        CStaticPropMgr *this,
        IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CStaticProp *m_pMemory; // ecx
  IVModelRender_vtbl *v5; // esi
  unsigned __int16 v6; // ax

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index == -1 )
    m_Index = 0x1FFF;
  else
    m_Index = (unsigned __int16)m_Index;
  m_pMemory = this->m_StaticProps.m_Memory.m_pMemory;
  v5 = modelrender->__vftable;
  v6 = m_pMemory[m_Index].GetModelInstance(this: &m_pMemory[m_Index].IClientRenderable);
  return v5->GetStaticLighting(this: modelrender, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101E0FB0
// Name: public: virtual void CStaticPropMgr::TraceRayAgainstStaticProp(struct Ray_t const __near &,int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CStaticPropMgr::TraceRayAgainstStaticProp(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        int staticPropIndex,
        CGameTrace *tr)
{
  _BYTE v7[92]; // [esp-Ch] [ebp-6Ch] OVERLAPPED BYREF
  CStaticPropMgr::StaticPropDict_t *v8; // [esp+50h] [ebp-10h]
  int v9; // [esp+54h] [ebp-Ch]
  void *v10; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v9 = a2;
  v10 = retaddr;
  v8 = &this->m_StaticPropDict.m_pElements[50 * staticPropIndex];
  if ( (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, int, int))&v8[2].m_pModel->szPathName[40])(
         a1: v8 + 2,
         a2: a3,
         a3: a4) != 0 )
  {
    *(Ray_t *)v7 = *ray;
    *(float *)&v7[16] = *(float *)&v7[16] * 1.1;
    *(_DWORD *)&v7[88] = tr;
    *(float *)&v7[20] = *(float *)&v7[20] * 1.1;
    *(_DWORD *)&v7[84] = v8;
    *(float *)&v7[24] = *(float *)&v7[24] * 1.1;
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, int))g_pEngineTraceClient->ClipRayToEntity)(
      a1: g_pEngineTraceClient,
      a2: v7,
      a3: -1);
  }
  else
  {
    tr->fraction = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1070
// Name: public: virtual void CStaticPropMgr::AddDecalToStaticProp(class Vector const __near &,class Vector const __near &,int,int,bool,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::AddDecalToStaticProp(
        CStaticPropMgr *this@<ecx>,
        float a2@<ebp>,
        const Vector *rayStart,
        const Vector *rayEnd,
        int staticPropIndex,
        int decalIndex,
        bool doTrace,
        CGameTrace *tr)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  CStaticPropMgr::StaticPropDict_t *v13; // esi
  IVModelRender_vtbl *v14; // edi
  unsigned __int16 v15; // ax
  _DWORD v16[3]; // [esp-Ch] [ebp-7Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-70h] BYREF
  int v18; // [esp+50h] [ebp-20h]
  Vector up; // [esp+54h] [ebp-1Ch] BYREF
  Vector temp; // [esp+60h] [ebp-10h]
  float retaddr; // [esp+70h] [ebp+0h]

  temp.y = a2;
  temp.z = retaddr;
  LODWORD(temp.x) = this;
  if ( staticPropIndex >= this->m_StaticProps.m_Memory.m_nGrowSize )
  {
    memset(dst: (unsigned __int8 *)tr, value: 0, count: sizeof(CGameTrace));
    tr->fraction = 1.0;
    return;
  }
  x = rayStart->x;
  y = rayStart->y;
  z = rayStart->z;
  v11 = rayEnd->z;
  v12 = rayEnd->x - rayStart->x;
  ray.m_Start.z = rayEnd->y - y;
  ray.m_Start.y = v12;
  ray.m_Start.w = v11 - z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z) + (float)(v12 * v12))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_Delta.y, 0, 12);
  *(float *)v16 = x;
  *(float *)&v16[1] = y;
  *(float *)&v16[2] = z;
  if ( doTrace )
  {
    ((void (__thiscall *)(CStaticPropMgr *, _DWORD *, int, CGameTrace *))this->Shutdown)(
      a1: this,
      a2: v16,
      a3: staticPropIndex,
      a4: tr);
    if ( tr->fraction == 1.0 )
      return;
    this = (CStaticPropMgr *)LODWORD(temp.x);
  }
  if ( r_drawmodeldecals.m_pParent != nullptr && r_drawmodeldecals.m_pParent->m_Value.m_nValue != 0 )
  {
    v13 = &this->m_StaticPropDict.m_pElements[50 * staticPropIndex];
    LOBYTE(temp.x) = 0;
    if ( doTrace
      && (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *))&v13[2].m_pModel->szPathName[40])(a1: v13 + 2) == 6
      && !tr->startsolid
      && !tr->allsolid )
    {
      up.x = tr->endpos.x - tr->plane.normal.x;
      up.y = tr->endpos.y - tr->plane.normal.y;
      up.z = tr->endpos.z - tr->plane.normal.z;
      Ray_t::Init(this: (Ray_t *)v16, start: &tr->endpos, end: &up);
      LOBYTE(temp.x) = 1;
    }
    *(_DWORD *)(&ray.m_IsSwept + 3) = 0;
    *(_DWORD *)(&ray.m_IsSwept + 7) = 0;
    v18 = 1065353216;
    v14 = modelrender->__vftable;
    v15 = (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, _DWORD *, bool *, int, _DWORD, _DWORD, int))&v13[1].m_pModel->szPathName[120])(
            a1: v13 + 1,
            a2: v16,
            a3: &ray.m_IsSwept + 3,
            a4: decalIndex,
            a5: 0,
            a6: LODWORD(temp.x),
            a7: -1);
    ((void (__thiscall *)(IVModelRender *, _DWORD))v14->AddDecal)(a1: modelrender, a2: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1270
// Name: public: virtual void CStaticPropMgr::GetStaticPropMaterialColorAndLighting(class CGameTrace __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetStaticPropMaterialColorAndLighting(
        CStaticPropMgr *this,
        CGameTrace *pTrace,
        int staticPropIndex,
        Vector *lighting,
        Vector *matColor)
{
  IVModelInfoClient_vtbl *v5; // edi
  CStaticPropMgr::StaticPropDict_t *v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax

  if ( staticPropIndex < this->m_StaticProps.m_Memory.m_nGrowSize )
  {
    v5 = modelinfoclient->__vftable;
    v6 = &this->m_StaticPropDict.m_pElements[50 * staticPropIndex + 1];
    v7 = (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, CGameTrace *, Vector *, Vector *))&v6->m_pModel->szPathName[4])(
           a1: v6,
           a2: pTrace,
           a3: lighting,
           a4: matColor);
    v8 = (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, int))v6->m_pModel->szPathName)(a1: v6, a2: v7);
    v9 = (*(int (__thiscall **)(CStaticPropMgr::StaticPropDict_t *, int))&v6->m_pModel->szPathName[28])(a1: v6, a2: v8);
    ((void (__thiscall *)(IVModelInfoClient *, int))v5->GetModelMaterialColorAndLighting)(a1: modelinfoclient, a2: v9);
  }
  else
  {
    lighting->x = 0.0;
    lighting->y = 0.0;
    lighting->z = 0.0;
    matColor->x = 1.0;
    matColor->y = 1.0;
    matColor->z = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1300
// Name: void Cmd_PropCrosshair_f(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Cmd_PropCrosshair_f(int a1@<ebp>)
{
  int v1; // [esp-Ch] [ebp-C4h] BYREF
  _BYTE tr_68[20]; // [esp+44h] [ebp-74h] OVERLAPPED BYREF
  Ray_t ray; // [esp+58h] [ebp-60h] BYREF
  _DWORD v4[3]; // [esp+A8h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+B8h] [ebp+0h]

  v4[1] = a1;
  v4[2] = retaddr;
  ray.m_Start.z = (float)((float)(*(float *)&dword_104F1BF8 * 57016.32) + g_MainViewOrigin[0].y) - g_MainViewOrigin[0].y;
  ray.m_Start.y = (float)((float)(g_MainViewForward[0].x * 57016.32) + g_MainViewOrigin[0].x) - g_MainViewOrigin[0].x;
  ray.m_Start.w = (float)((float)(*(float *)&dword_104F1BFC * 57016.32) + g_MainViewOrigin[0].z) - g_MainViewOrigin[0].z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                         + (float)(ray.m_Start.y * ray.m_Start.y))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  memset(&ray.m_Delta.y, 0, 12);
  *(Vector *)&tr_68[8] = g_MainViewOrigin[0];
  v4[0] = &CTraceFilterWorldAndPropsOnly::`vftable';
  g_pEngineTraceServer->TraceRay(
    this: g_pEngineTraceServer,
    a2: (const Ray_t *)&tr_68[8],
    a3: -1u,
    a4: (ITraceFilter *)v4,
    a5: (CGameTrace *)&v1);
  if ( *(int *)tr_68 <= 0 )
    _Msg(a1: "didn't hit a prop\n");
  else
    _Msg(a1: "hit prop %d\n", *(_DWORD *)tr_68 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x101E1440
// Name: public: virtual void CStaticPropMgr::ConfigureSystemLevel(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStaticPropMgr::ConfigureSystemLevel(
        CStaticPropMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        BOOL a4@<esi>,
        int nCPULevel,
        int nGPULevel)
{
  bool v6; // zf

  if ( nCPULevel != this->m_nLastCPULevel || nGPULevel != this->m_nLastGPULevel )
  {
    v6 = !this->m_bClientInitialized;
    this->m_nLastCPULevel = nCPULevel;
    this->m_nLastGPULevel = nGPULevel;
    if ( !v6 )
      CStaticPropMgr::UpdatePropVisibility(this, a2, a3, a4, nCPULevel, nGPULevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1470
// Name: public: virtual void CStaticPropMgr::RestoreStaticProps(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStaticPropMgr::RestoreStaticProps(CStaticPropMgr *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CStaticPropMgr::UpdatePropVisibility(
    this,
    a2,
    a3,
    a4: (BOOL)this,
    nCPULevel: this->m_nLastCPULevel,
    nGPULevel: this->m_nLastGPULevel);
  this->RecomputeStaticLighting(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E1490
// Name: public: virtual void CStaticPropMgr::LevelInitClient(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStaticPropMgr::LevelInitClient(
        CStaticPropMgr *this@<ecx>,
        int a2@<edi>,
        BOOL a3@<esi>,
        float a4@<xmm0>)
{
  int m_nValue; // eax
  CStaticProp *v6; // edi
  float *v7; // eax
  IModelLoader_vtbl *v8; // esi
  int v9; // eax
  const char *v10; // eax
  double v11; // [esp+0h] [ebp-3Ch]
  double v12; // [esp+8h] [ebp-34h]
  _BYTE v13[12]; // [esp+10h] [ebp-2Ch]
  int m_nLastCPULevel; // [esp+18h] [ebp-24h]
  BOOL v15; // [esp+1Ch] [ebp-20h]
  int m_nLastGPULevel; // [esp+1Ch] [ebp-20h]
  float origin; // [esp+24h] [ebp-18h]
  float origin_4; // [esp+28h] [ebp-14h]
  float origin_8; // [esp+2Ch] [ebp-10h]
  int m_Size; // [esp+30h] [ebp-Ch]
  int v21; // [esp+34h] [ebp-8h]
  bool bNeedsMapAccess; // [esp+3Bh] [ebp-1h]

  if ( !sv.m_bIsDedicated )
  {
    if ( r_proplightingfromdisk.m_pParent != nullptr )
      m_nValue = r_proplightingfromdisk.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    bNeedsMapAccess = m_nValue != 0;
    if ( m_nValue != 0 )
      g_pFileSystem->BeginMapAccess(this: g_pFileSystem);
    if ( this->m_StaticProps.m_Size > 0 )
    {
      v15 = a3;
      v21 = 0;
      m_Size = this->m_StaticProps.m_Size;
      *(_DWORD *)&v13[8] = a2;
      do
      {
        v6 = &this->m_StaticProps.m_Memory.m_pMemory[v21];
        if ( v6->m_LeafCount == 0 )
        {
          v7 = (float *)((int (__thiscall *)(ICollideable *, _DWORD))v6->GetCollisionOrigin)(
                          a1: &v6->ICollideable,
                          a2: *(_DWORD *)&v13[8]);
          origin_4 = v7[1];
          origin = *v7;
          origin_8 = v7[2];
          v6->OBBMins(this: &v6->ICollideable);
          v6->OBBMaxs(this: &v6->ICollideable);
          v8 = modelloader->__vftable;
          *(double *)&v13[4] = origin_8;
          v9 = ((int (__thiscall *)(IClientRenderable *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v6->GetModel)(
                 a1: &v6->IClientRenderable,
                 a2: COERCE_UNSIGNED_INT64(origin),
                 a3: HIDWORD(COERCE_UNSIGNED_INT64(origin)),
                 a4: COERCE_UNSIGNED_INT64(origin_4),
                 a5: HIDWORD(COERCE_UNSIGNED_INT64(origin_4)),
                 a6: COERCE_UNSIGNED_INT64(origin_8));
          v10 = v8->GetName(this: modelloader, a2: (const model_t *)v9);
          _DevMsg(a1: 1, a2: "Static prop in 0 leaves! %s, @ %.1f, %.1f, %.1f\n", v10, v11, v12, *(double *)v13);
        }
        ++v21;
        --m_Size;
      }
      while ( m_Size != 0 );
      a2 = *(_DWORD *)&v13[8];
      a3 = v15;
    }
    m_nLastGPULevel = this->m_nLastGPULevel;
    m_nLastCPULevel = this->m_nLastCPULevel;
    this->m_bClientInitialized = true;
    CStaticPropMgr::UpdatePropVisibility(
      this,
      a2: (int)this,
      a3: a2,
      a4: a3,
      nCPULevel: m_nLastCPULevel,
      nGPULevel: m_nLastGPULevel);
    CStaticPropMgr::PrecacheLighting(this, a2: (int)this, a3: a2, a4);
    if ( bNeedsMapAccess )
      g_pFileSystem->EndMapAccess(this: g_pFileSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1680
// Name: private: void CStaticPropMgr::UnserializeLeafList(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::UnserializeLeafList(CStaticPropMgr *this, CUtlBuffer *buf)
{
  int Int; // eax
  bool v4; // sf
  int v5; // edi

  Int = CUtlBuffer::GetInt(this: buf);
  v4 = this->m_StaticPropLeaves.m_Memory.m_nGrowSize < 0;
  v5 = Int;
  this->m_StaticPropLeaves.m_Size = 0;
  if ( !v4 )
  {
    if ( this->m_StaticPropLeaves.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StaticPropLeaves.m_Memory.m_pMemory);
      this->m_StaticPropLeaves.m_Memory.m_pMemory = nullptr;
    }
    this->m_StaticPropLeaves.m_Memory.m_nAllocationCount = 0;
  }
  this->m_StaticPropLeaves.m_pElements = this->m_StaticPropLeaves.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&this->m_StaticPropLeaves,
      elem: this->m_StaticPropLeaves.m_Size,
      num: v5);
    CUtlBuffer::Get(this: buf, pMem: this->m_StaticPropLeaves.m_Memory.m_pMemory, size: 2 * v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E16F0
// Name: public: virtual void CStaticPropMgr::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::LevelShutdown(CStaticPropMgr *this)
{
  if ( this->m_bLevelInitialized )
  {
    if ( this->m_bClientInitialized )
      this->LevelShutdownClient(this);
    this->m_bLevelInitialized = false;
    CUtlVector<CStaticProp,CUtlMemory<CStaticProp,int>>::Purge(this: &this->m_StaticProps);
    this->m_StaticPropDict.m_Size = 0;
    if ( this->m_StaticPropDict.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_StaticPropDict.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StaticPropDict.m_Memory.m_pMemory);
        this->m_StaticPropDict.m_Memory.m_pMemory = nullptr;
      }
      this->m_StaticPropDict.m_Memory.m_nAllocationCount = 0;
    }
    this->m_StaticPropDict.m_pElements = this->m_StaticPropDict.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E17B0
// Name: public: virtual CStaticPropMgr::~CStaticPropMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::~CStaticPropMgr(CStaticPropMgr *this)
{
  this->IStaticPropMgrEngine::__vftable = (CStaticPropMgr_vtbl *)&CStaticPropMgr::`vftable'{for `IStaticPropMgrEngine'};
  this->IStaticPropMgrClient::IStaticPropMgr::__vftable = (IStaticPropMgrClient_vtbl *)&CStaticPropMgr::`vftable'{for `IStaticPropMgrClient'};
  this->IStaticPropMgrServer::IStaticPropMgr::__vftable = (IStaticPropMgrServer_vtbl *)&CStaticPropMgr::`vftable'{for `IStaticPropMgrServer'};
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_StaticPropLeaves);
  CUtlVector<CStaticProp,CUtlMemory<CStaticProp,int>>::Purge(this: &this->m_StaticProps);
  if ( this->m_StaticProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_StaticProps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StaticProps.m_Memory.m_pMemory);
      this->m_StaticProps.m_Memory.m_pMemory = nullptr;
    }
    this->m_StaticProps.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_StaticPropDict);
}

//------------------------------------------------------------------------------
// Address: 0x101E1810
// Name: private: void CStaticPropMgr::UnserializeModelDict(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::UnserializeModelDict(CStaticPropMgr *this, CUtlBuffer *buf)
{
  int Int; // edi
  int m_Size; // eax
  CUtlVector<CStaticPropMgr::StaticPropDict_t,CUtlMemory<CStaticPropMgr::StaticPropDict_t,int> > *p_m_StaticPropDict; // ebx
  int v6; // esi
  IEngineVGuiInternal *v7; // eax
  CStaticPropMgr::StaticPropDict_t *v8; // ebx
  StaticPropDictLump_t lump; // [esp+Ch] [ebp-84h] BYREF
  CUtlVector<CStaticPropMgr::StaticPropDict_t,CUtlMemory<CStaticPropMgr::StaticPropDict_t,int> > *v10; // [esp+8Ch] [ebp-4h]

  Int = CUtlBuffer::GetInt(this: buf);
  m_Size = this->m_StaticPropDict.m_Size;
  p_m_StaticPropDict = &this->m_StaticPropDict;
  v10 = p_m_StaticPropDict;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)p_m_StaticPropDict,
    elem: m_Size,
    num: Int);
  _COM_TimestampedLog(a1: "Starting UnserializeModelDict for %d models\n", Int);
  v6 = 0;
  if ( Int > 0 )
  {
    while ( 1 )
    {
      if ( v6 % 0xAu == 0 )
      {
        v7 = EngineVGui();
        v7->UpdateProgressBar(this: v7, a2: PROGRESS_DEFAULT, a3: true);
      }
      CUtlBuffer::Get(this: buf, pMem: &lump, size: 128);
      v8 = &p_m_StaticPropDict->m_Memory.m_pMemory[v6++];
      v8->m_pModel = (model_t *)((int (__stdcall *)(StaticPropDictLump_t *, int))modelloader->GetModelForName)(
                                  a1: &lump,
                                  a2: 16);
      if ( v6 >= Int )
        break;
      p_m_StaticPropDict = v10;
    }
  }
  _COM_TimestampedLog(a1: "Finished UnserializeModelDict\n");
}

//------------------------------------------------------------------------------
// Address: 0x101E18D0
// Name: private: void CStaticPropMgr::UnserializeModels(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::UnserializeModels(CStaticPropMgr *this, CUtlBuffer *buf)
{
  CUtlBuffer *v3; // edi
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CStaticProp *m_pMemory; // ecx
  int v8; // eax
  CStaticProp *v9; // eax
  bool v10; // zf
  CStaticProp *v11; // eax
  int v12; // edi
  IEngineVGuiInternal *v13; // eax
  StaticPropLump_t lump; // [esp+4h] [ebp-5Ch] BYREF
  unsigned int v15; // [esp+4Ch] [ebp-14h]
  int nLumpVersion; // [esp+54h] [ebp-Ch]
  int count; // [esp+58h] [ebp-8h]
  int i; // [esp+5Ch] [ebp-4h]
  IMDLCache savedregs; // [esp+60h] [ebp+0h] BYREF

  nLumpVersion = Mod_GameLumpVersion(lumpId: 1936749168);
  if ( nLumpVersion >= 4 )
  {
    v3 = buf;
    count = CUtlBuffer::GetInt(this: buf);
    CUtlVector<CStaticProp,CUtlMemory<CStaticProp,int>>::EnsureCapacity(this: &this->m_StaticProps, num: count);
    i = 0;
    if ( count > 0 )
    {
      v4 = nLumpVersion - 4;
      nLumpVersion -= 4;
      while ( 1 )
      {
        switch ( v4 )
        {
          case 0:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 56);
            lump.m_flForcedFadeScale = 1.0;
            *(_DWORD *)&lump.m_nMinCPULevel = 0;
            lump.m_DiffuseModulation = (color32_s)-1;
            lump.m_bDisableX360 = false;
            break;
          case 1:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 60);
            *(_DWORD *)&lump.m_nMinCPULevel = 0;
            lump.m_DiffuseModulation = (color32_s)-1;
            lump.m_bDisableX360 = false;
            break;
          case 2:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 64);
            *(_DWORD *)&lump.m_nMinCPULevel = 0;
            lump.m_DiffuseModulation = (color32_s)-1;
            lump.m_bDisableX360 = false;
            break;
          case 3:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 68);
            *(_DWORD *)&lump.m_nMinCPULevel = 0;
            lump.m_bDisableX360 = false;
            break;
          case 4:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 68);
            lump.m_bDisableX360 = false;
            break;
          case 5:
            CUtlBuffer::Get(this: v3, pMem: &lump, size: 72);
            break;
          default:
            break;
        }
        m_Size = this->m_StaticProps.m_Size;
        m_nAllocationCount = this->m_StaticProps.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CStaticProp,int>::Grow(this: &this->m_StaticProps.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++this->m_StaticProps.m_Size;
        m_pMemory = this->m_StaticProps.m_Memory.m_pMemory;
        v8 = this->m_StaticProps.m_Size - m_Size - 1;
        this->m_StaticProps.m_pElements = m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 200 * v8);
        v9 = this->m_StaticProps.m_Memory.m_pMemory;
        v10 = &v9[m_Size] == nullptr;
        v11 = &v9[m_Size];
        v15 = 200 * m_Size;
        if ( !v10 )
        {
          v11->IClientRenderable::__vftable = (IClientRenderable_vtbl *)&IClientRenderable::`vftable';
          v11->ICollideable::__vftable = (ICollideable_vtbl *)&ICollideable::`vftable';
          v11->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&IClientModelRenderable::`vftable';
          v11->IClientUnknown::IHandleEntity::__vftable = (CStaticProp_vtbl *)&CStaticProp::`vftable'{for `IClientUnknown'};
          v11->IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CStaticProp::`vftable'{for `IClientRenderable'};
          v11->ICollideable::__vftable = (ICollideable_vtbl *)&CStaticProp::`vftable'{for `ICollideable'};
          v11->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CStaticProp::`vftable'{for `IClientModelRenderable'};
          v11->m_pModel = nullptr;
          v11->m_Alpha = -1;
          v11->m_EntHandle.m_Index = -1;
          v11->m_ModelInstance = -1;
          v11->m_Partition = -1;
          v11->m_EntHandle.m_Index = -1;
          v11->m_RenderHandle = -1;
          v11->m_pClientAlphaProperty = nullptr;
        }
        CStaticProp::Init(
          this: &this->m_StaticProps.m_Memory.m_pMemory[m_Size],
          a2: &savedregs,
          a3: m_Size,
          a4: (int)this,
          index: m_Size,
          &lump,
          pModel: this->m_StaticPropDict.m_Memory.m_pMemory[lump.m_PropType].m_pModel);
        CStaticProp::InsertPropIntoKDTree(this: &this->m_StaticProps.m_Memory.m_pMemory[v15 / 0xC8]);
        v12 = i;
        if ( i % 0xAu == 0 )
        {
          v13 = EngineVGui();
          v13->UpdateProgressBar(this: v13, a2: PROGRESS_DEFAULT, a3: true);
        }
        i = v12 + 1;
        if ( v12 + 1 >= count )
          break;
        v4 = nLumpVersion;
        v3 = buf;
      }
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_StaticPropManager, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_StaticPropManager, a2: 1, a3: "Really old map format! Static props can't be loaded...\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1B40
// Name: private: void CStaticPropMgr::UnserializeStaticProps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::UnserializeStaticProps(CStaticPropMgr *this)
{
  int v2; // esi
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  v2 = Mod_GameLumpSize(lumpId: 1936749168);
  if ( v2 != 0 )
  {
    _COM_TimestampedLog(a1: "UnserializeStaticProps - start");
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: v2, nFlags: 0);
    if ( Mod_LoadGameLump(lumpId: 1936749168, pOutBuffer: &buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset], size: v2) )
    {
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v2);
      _COM_TimestampedLog(a1: "UnserializeModelDict");
      CStaticPropMgr::UnserializeModelDict(this, &buf);
      _COM_TimestampedLog(a1: "UnserializeLeafList");
      CStaticPropMgr::UnserializeLeafList(this, &buf);
      _COM_TimestampedLog(a1: "UnserializeModels");
      CStaticPropMgr::UnserializeModels(this, &buf);
    }
    _COM_TimestampedLog(a1: "UnserializeStaticProps - end");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1C20
// Name: public: virtual void CStaticPropMgr::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::LevelInit(CStaticPropMgr *this)
{
  if ( !this->m_bLevelInitialized )
  {
    this->m_bLevelInitialized = true;
    if ( disableStaticPropLoading.m_pParent == nullptr || disableStaticPropLoading.m_pParent->m_Value.m_nValue == 0 )
      CStaticPropMgr::UnserializeStaticProps(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1C70
// Name: public: virtual void CStaticPropMgr::GetAllStaticProps(class CUtlVector<class ICollideable __near *,class CUtlMemory<class ICollideable __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetAllStaticProps(
        CStaticPropMgr *this,
        CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutput)
{
  CStaticPropMgr::StaticPropDict_t *v3; // eax
  ICollideable *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ICollideable **m_pMemory; // ecx
  int v8; // eax
  ICollideable **v9; // eax
  CStaticPropMgr *v10; // [esp+4h] [ebp-8h]
  int m_nGrowSize; // [esp+8h] [ebp-4h]
  CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutputa; // [esp+14h] [ebp+8h]

  v10 = this;
  if ( pOutput != nullptr && this->m_StaticProps.m_Memory.m_nGrowSize != 0 )
  {
    pOutputa = nullptr;
    m_nGrowSize = this->m_StaticProps.m_Memory.m_nGrowSize;
    while ( 1 )
    {
      v3 = (CStaticPropMgr::StaticPropDict_t *)((char *)pOutputa + (unsigned int)this->m_StaticPropDict.m_pElements);
      if ( v3 != nullptr )
        v4 = (ICollideable *)&v3[2];
      else
        v4 = nullptr;
      m_Size = pOutput->m_Size;
      m_nAllocationCount = pOutput->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)pOutput,
          num: m_Size - m_nAllocationCount + 1);
      ++pOutput->m_Size;
      m_pMemory = pOutput->m_Memory.m_pMemory;
      v8 = pOutput->m_Size - m_Size - 1;
      pOutput->m_pElements = pOutput->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v9 = &pOutput->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = v4;
      pOutputa += 10;
      if ( --m_nGrowSize == 0 )
        break;
      this = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1D20
// Name: public: virtual void CStaticPropMgr::GetAllStaticPropsInAABB(class Vector const __near &,class Vector const __near &,class CUtlVector<class ICollideable __near *,class CUtlMemory<class ICollideable __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetAllStaticPropsInAABB(
        CStaticPropMgr *this,
        const Vector *vMins,
        const Vector *vMaxs,
        CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutput)
{
  CStaticPropMgr::StaticPropDict_t *v5; // ebx
  void (__thiscall *v6)(ICollideable *, Vector *, Vector *); // eax
  ICollideable *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  ICollideable **m_pMemory; // ecx
  int v11; // eax
  ICollideable **v12; // eax
  Vector vPropMins; // [esp+4h] [ebp-20h] BYREF
  Vector vPropMaxs; // [esp+10h] [ebp-14h] BYREF
  CStaticPropMgr *v15; // [esp+1Ch] [ebp-8h]
  int m_nGrowSize; // [esp+20h] [ebp-4h]
  CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutputa; // [esp+34h] [ebp+10h]

  v15 = this;
  if ( pOutput != nullptr && this->m_StaticProps.m_Memory.m_nGrowSize != 0 )
  {
    pOutputa = nullptr;
    m_nGrowSize = this->m_StaticProps.m_Memory.m_nGrowSize;
    while ( 1 )
    {
      v5 = (CStaticPropMgr::StaticPropDict_t *)((char *)pOutputa + (unsigned int)this->m_StaticPropDict.m_pElements);
      v6 = *(void (__thiscall **)(ICollideable *, Vector *, Vector *))&v5[2].m_pModel->szPathName[56];
      v7 = (ICollideable *)&v5[2];
      v6(a1: v7, a2: &vPropMins, a3: &vPropMaxs);
      if ( vMins->x <= vPropMaxs.x
        && vMins->y <= vPropMaxs.y
        && vMins->z <= vPropMaxs.z
        && vPropMins.x <= vMaxs->x
        && vPropMins.y <= vMaxs->y
        && vPropMins.z <= vMaxs->z )
      {
        m_Size = pOutput->m_Size;
        m_nAllocationCount = pOutput->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)pOutput,
            num: m_Size - m_nAllocationCount + 1);
        ++pOutput->m_Size;
        m_pMemory = pOutput->m_Memory.m_pMemory;
        v11 = pOutput->m_Size - m_Size - 1;
        pOutput->m_pElements = pOutput->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
        v12 = &pOutput->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = v7;
      }
      pOutputa += 10;
      if ( --m_nGrowSize == 0 )
        break;
      this = v15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E1E20
// Name: public: virtual void CStaticPropMgr::GetAllStaticPropsInOBB(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class CUtlVector<class ICollideable __near *,class CUtlMemory<class ICollideable __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropMgr::GetAllStaticPropsInOBB(
        CStaticPropMgr *this,
        const Vector *ptOrigin,
        const Vector *vExtent1,
        const Vector *vExtent2,
        const Vector *vExtent3,
        CUtlVector<ICollideable *,CUtlMemory<ICollideable *,int> > *pOutput)
{
  float v7; // xmm0_4
  float z; // xmm1_4
  float x; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm6_4
  int v14; // ecx
  float *p_z; // eax
  float v16; // xmm2_4
  float v17; // xmm2_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float y; // xmm1_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  const Vector *m_nGrowSize; // eax
  float v29; // xmm0_4
  ICollideable *v30; // edi
  void (__thiscall *WorldSpaceSurroundingBounds)(ICollideable *, Vector *, Vector *); // edx
  ICollideable *v32; // edi
  int v33; // eax
  float v34; // edx
  float v35; // ecx
  float v36; // eax
  ICollideable_vtbl *v37; // edx
  int v38; // eax
  float v39; // ecx
  float v40; // edx
  float v41; // eax
  ICollideable_vtbl *v42; // edx
  const QAngle *v43; // eax
  int v44; // ebx
  Vector *v45; // esi
  float v46; // xmm0_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  int v49; // esi
  float *v50; // edx
  int v51; // eax
  float *v52; // ecx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  ICollideable **m_pMemory; // ecx
  int v56; // eax
  ICollideable **v57; // esi
  const Vector *v58; // [esp-14h] [ebp-160h]
  Vector ptPropExtents[8]; // [esp+0h] [ebp-14Ch] BYREF
  matrix3x4_t matPropWorld; // [esp+60h] [ebp-ECh] BYREF
  float fOBBPlaneDists[6]; // [esp+90h] [ebp-BCh]
  Vector vPropMaxs; // [esp+A8h] [ebp-A4h] BYREF
  Vector vPropMins; // [esp+B4h] [ebp-98h] BYREF
  Vector vOBBPlaneNormals[6]; // [esp+C0h] [ebp-8Ch] BYREF
  Vector vPropOBBMaxs; // [esp+108h] [ebp-44h]
  float v66; // [esp+114h] [ebp-38h]
  Vector vPropOBBMins; // [esp+118h] [ebp-34h]
  Vector ptTemp; // [esp+124h] [ebp-28h] BYREF
  CStaticPropMgr *v69; // [esp+130h] [ebp-1Ch]
  Vector vAABBMaxs; // [esp+134h] [ebp-18h]
  Vector vAABBMins; // [esp+140h] [ebp-Ch]
  float ptOrigina; // [esp+154h] [ebp+8h]
  const Vector *ptOriginb; // [esp+154h] [ebp+8h]
  const Vector *vExtent1a; // [esp+158h] [ebp+Ch]

  v69 = this;
  if ( pOutput != nullptr )
  {
    z = ptOrigin->z;
    x = ptOrigin->x;
    ptOrigina = ptOrigin->y;
    v7 = ptOrigina;
    v10 = x;
    v11 = ptOrigina;
    v12 = z;
    v13 = x;
    vAABBMins.x = x;
    vAABBMins.y = ptOrigina;
    vAABBMins.z = z;
    vAABBMaxs.x = x;
    vAABBMaxs.y = ptOrigina;
    vAABBMaxs.z = z;
    v14 = 0;
    v66 = z;
    p_z = &ptPropExtents[0].z;
    do
    {
      *(p_z - 1) = ptOrigina;
      v16 = v66;
      *(p_z - 2) = x;
      *p_z = v16;
      if ( (v14 & 1) != 0 )
      {
        *(p_z - 2) = vExtent1->x + x;
        *(p_z - 1) = vExtent1->y + *(p_z - 1);
        *p_z = vExtent1->z + *p_z;
      }
      if ( (v14 & 2) != 0 )
      {
        *(p_z - 2) = vExtent2->x + *(p_z - 2);
        *(p_z - 1) = vExtent2->y + *(p_z - 1);
        *p_z = vExtent2->z + *p_z;
      }
      if ( (v14 & 4) != 0 )
      {
        *(p_z - 2) = vExtent3->x + *(p_z - 2);
        *(p_z - 1) = vExtent3->y + *(p_z - 1);
        *p_z = vExtent3->z + *p_z;
      }
      v17 = *(p_z - 2);
      if ( v10 > v17 )
        v10 = *(p_z - 2);
      if ( v17 > v13 )
        v13 = *(p_z - 2);
      v18 = *(p_z - 1);
      if ( v11 > v18 )
        v11 = *(p_z - 1);
      if ( v18 > v7 )
        v7 = *(p_z - 1);
      if ( v12 > *p_z )
        v12 = *p_z;
      if ( *p_z > z )
        z = *p_z;
      ++v14;
      p_z += 3;
    }
    while ( v14 != 8 );
    vAABBMaxs.y = v7;
    vOBBPlaneNormals[0].x = vExtent1->x;
    vOBBPlaneNormals[0].y = vExtent1->y;
    v19 = vExtent1->z;
    vAABBMaxs.z = z;
    vAABBMins.z = v12;
    vAABBMins.y = v11;
    vAABBMaxs.x = v13;
    vAABBMins.x = v10;
    vOBBPlaneNormals[0].z = v19;
    VectorNormalize(vec: vOBBPlaneNormals);
    v20 = ptOrigin->x;
    y = ptOrigin->y;
    v22 = ptOrigin->z;
    fOBBPlaneDists[0] = (float)((float)((float)(y + vExtent1->y) * vOBBPlaneNormals[0].y)
                              + (float)((float)(ptOrigin->x + vExtent1->x) * vOBBPlaneNormals[0].x))
                      + (float)((float)(v22 + vExtent1->z) * vOBBPlaneNormals[0].z);
    vOBBPlaneNormals[2].x = vExtent2->x;
    vOBBPlaneNormals[2].y = vExtent2->y;
    v23 = vExtent2->z;
    vOBBPlaneNormals[1].x = -vOBBPlaneNormals[0].x;
    vOBBPlaneNormals[1].y = -vOBBPlaneNormals[0].y;
    vOBBPlaneNormals[1].z = -vOBBPlaneNormals[0].z;
    fOBBPlaneDists[1] = (float)((float)(y * (float)-vOBBPlaneNormals[0].y) + (float)(v20 * (float)-vOBBPlaneNormals[0].x))
                      + (float)(v22 * (float)-vOBBPlaneNormals[0].z);
    vOBBPlaneNormals[2].z = v23;
    VectorNormalize(vec: &vOBBPlaneNormals[2]);
    v24 = ptOrigin->y;
    v25 = ptOrigin->x;
    v26 = ptOrigin->z;
    fOBBPlaneDists[2] = (float)((float)(vOBBPlaneNormals[2].y * (float)(v24 + vExtent2->y))
                              + (float)(vOBBPlaneNormals[2].x * (float)(ptOrigin->x + vExtent2->x)))
                      + (float)(vOBBPlaneNormals[2].z * (float)(v26 + vExtent2->z));
    fOBBPlaneDists[3] = (float)((float)(v24 * (float)-vOBBPlaneNormals[2].y)
                              + (float)(v25 * (float)-vOBBPlaneNormals[2].x))
                      + (float)(v26 * (float)-vOBBPlaneNormals[2].z);
    vOBBPlaneNormals[4].x = vExtent3->x;
    vOBBPlaneNormals[4].y = vExtent3->y;
    v27 = vExtent3->z;
    vOBBPlaneNormals[3].x = -vOBBPlaneNormals[2].x;
    vOBBPlaneNormals[3].y = -vOBBPlaneNormals[2].y;
    vOBBPlaneNormals[3].z = -vOBBPlaneNormals[2].z;
    vOBBPlaneNormals[4].z = v27;
    VectorNormalize(vec: &vOBBPlaneNormals[4]);
    m_nGrowSize = (const Vector *)v69->m_StaticProps.m_Memory.m_nGrowSize;
    v29 = (float)((float)(ptOrigin->y * (float)-vOBBPlaneNormals[4].y)
                + (float)(ptOrigin->x * (float)-vOBBPlaneNormals[4].x))
        + (float)(ptOrigin->z * (float)-vOBBPlaneNormals[4].z);
    fOBBPlaneDists[4] = (float)((float)(vOBBPlaneNormals[4].y * (float)(ptOrigin->y + vExtent3->y))
                              + (float)(vOBBPlaneNormals[4].x * (float)(ptOrigin->x + vExtent3->x)))
                      + (float)(vOBBPlaneNormals[4].z * (float)(ptOrigin->z + vExtent3->z));
    vOBBPlaneNormals[5].x = -vOBBPlaneNormals[4].x;
    vOBBPlaneNormals[5].y = -vOBBPlaneNormals[4].y;
    vOBBPlaneNormals[5].z = -vOBBPlaneNormals[4].z;
    fOBBPlaneDists[5] = v29;
    if ( m_nGrowSize != nullptr )
    {
      vExtent1a = nullptr;
      for ( ptOriginb = m_nGrowSize; ptOriginb != nullptr; ptOriginb = (const Vector *)((char *)ptOriginb - 1) )
      {
        v30 = (ICollideable *)((char *)vExtent1a + (unsigned int)v69->m_StaticPropDict.m_pElements);
        WorldSpaceSurroundingBounds = v30[2].WorldSpaceSurroundingBounds;
        v32 = v30 + 2;
        WorldSpaceSurroundingBounds(this: v32, a2: &vPropMins, a3: &vPropMaxs);
        if ( vAABBMins.x <= vPropMaxs.x
          && vAABBMins.y <= vPropMaxs.y
          && vAABBMins.z <= vPropMaxs.z
          && vPropMins.x <= vAABBMaxs.x
          && vPropMins.y <= vAABBMaxs.y
          && vPropMins.z <= vAABBMaxs.z )
        {
          v33 = (int)v32->OBBMins(this: v32);
          v34 = *(float *)(v33 + 4);
          v35 = *(float *)v33;
          v36 = *(float *)(v33 + 8);
          vPropOBBMins.y = v34;
          v37 = v32->__vftable;
          vPropOBBMins.x = v35;
          vPropOBBMins.z = v36;
          v38 = (int)v37->OBBMaxs(this: v32);
          v39 = *(float *)v38;
          v40 = *(float *)(v38 + 4);
          v41 = *(float *)(v38 + 8);
          vPropOBBMaxs.x = v39;
          vPropOBBMaxs.y = v40;
          v42 = v32->__vftable;
          vPropOBBMaxs.z = v41;
          v58 = v42->GetCollisionOrigin(this: v32);
          v43 = v32->GetCollisionAngles(this: v32);
          AngleMatrix(angles: v43, position: v58, matrix: &matPropWorld);
          v44 = 0;
          v45 = ptPropExtents;
          do
          {
            if ( (v44 & 1) != 0 )
              v46 = vPropOBBMaxs.x;
            else
              v46 = vPropOBBMins.x;
            ptTemp.x = v46;
            if ( (v44 & 2) != 0 )
              v47 = vPropOBBMaxs.y;
            else
              v47 = vPropOBBMins.y;
            ptTemp.y = v47;
            if ( (v44 & 4) != 0 )
              v48 = vPropOBBMaxs.z;
            else
              v48 = vPropOBBMins.z;
            ptTemp.z = v48;
            VectorTransform(in1: &ptTemp.x, in2: &matPropWorld, out: &v45->x);
            ++v44;
            ++v45;
          }
          while ( v44 != 8 );
          v49 = 0;
          v50 = &vOBBPlaneNormals[0].z;
          do
          {
            v51 = 0;
            v52 = &ptPropExtents[0].z;
            while ( (float)((float)((float)((float)(*(v52 - 2) * *(v50 - 2)) + (float)(*(v52 - 1) * *(v50 - 1)))
                                  + (float)(*v52 * *v50))
                          - fOBBPlaneDists[v49]) >= 0.0 )
            {
              ++v51;
              v52 += 3;
              if ( v51 == 8 )
                goto LABEL_52;
            }
            ++v49;
            v50 += 3;
          }
          while ( v49 != 6 );
          m_Size = pOutput->m_Size;
          m_nAllocationCount = pOutput->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)pOutput,
              num: m_Size - m_nAllocationCount + 1);
          ++pOutput->m_Size;
          m_pMemory = pOutput->m_Memory.m_pMemory;
          v56 = pOutput->m_Size - m_Size - 1;
          pOutput->m_pElements = pOutput->m_Memory.m_pMemory;
          if ( v56 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v56);
          v57 = &pOutput->m_Memory.m_pMemory[m_Size];
          if ( v57 != nullptr )
            *v57 = v32;
        }
LABEL_52:
        vExtent1a = (const Vector *)((char *)vExtent1a + 200);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DEC10
// Name: __CreateCStaticPropMgrIStaticPropMgrClient_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IStaticPropMgrClient *__cdecl _CreateCStaticPropMgrIStaticPropMgrClient_interface()
{
  return &s_StaticPropMgr.IStaticPropMgrClient;
}

//------------------------------------------------------------------------------
// Address: 0x101DEC20
// Name: __CreateCStaticPropMgrIStaticPropMgrServer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IStaticPropMgrServer *__cdecl _CreateCStaticPropMgrIStaticPropMgrServer_interface()
{
  return &s_StaticPropMgr.IStaticPropMgrServer;
}

} // namespace engine_xlsp
