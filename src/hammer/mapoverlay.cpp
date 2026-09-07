// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapoverlay.cpp
// Functions: 65
// ============================================================

#include "hammer\mapoverlay.h"

//------------------------------------------------------------------------------
// Address: 0x10134070
// Name: public: virtual char const __near * CMapOverlay::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapOverlay::GetType(CMapOverlay *this)
{
  return CMapOverlay::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10134080
// Name: public: virtual int CMapOverlay::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapOverlay::IsMapClass(CMapOverlay *this, const char *Type)
{
  return Type == CMapOverlay::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101340A0
// Name: private: void CMapOverlay::Basis_Copy(struct CMapOverlay::Basis_t __near *,struct CMapOverlay::Basis_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Basis_Copy(CMapOverlay *this, CMapOverlay::Basis_t *pSrc, CMapOverlay::Basis_t *pDst)
{
  double y; // st7

  pDst->m_vecOrigin.x = pSrc->m_vecOrigin.x;
  y = pSrc->m_vecOrigin.y;
  pDst->m_pFace = pSrc->m_pFace;
  pDst->m_vecOrigin.y = y;
  pDst->m_vecOrigin.z = pSrc->m_vecOrigin.z;
  pDst->m_vecAxes[0].x = pSrc->m_vecAxes[0].x;
  pDst->m_vecAxes[0].y = pSrc->m_vecAxes[0].y;
  pDst->m_vecAxes[0].z = pSrc->m_vecAxes[0].z;
  pDst->m_nAxesFlip[0] = pSrc->m_nAxesFlip[0];
  pDst->m_vecAxes[1] = pSrc->m_vecAxes[1];
  pDst->m_nAxesFlip[1] = pSrc->m_nAxesFlip[1];
  pDst->m_vecAxes[2] = pSrc->m_vecAxes[2];
  pDst->m_nAxesFlip[2] = pSrc->m_nAxesFlip[2];
}

//------------------------------------------------------------------------------
// Address: 0x10134110
// Name: private: void CMapOverlay::Basis_UpdateParentKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Basis_UpdateParentKey(CMapOverlay *this)
{
  CMapEntity *v2; // edi
  char string[8]; // [esp+8h] [ebp-50h] BYREF

  v2 = (CMapEntity *)this->GetParent(this);
  if ( v2 != nullptr )
  {
    sprintf(
      string,
      format: "%g %g %g",
      this->m_Basis.m_vecOrigin.x,
      this->m_Basis.m_vecOrigin.y,
      this->m_Basis.m_vecOrigin.z);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "BasisOrigin", szValue: string);
    sprintf(
      string,
      format: "%g %g %g",
      this->m_Basis.m_vecAxes[0].x,
      this->m_Basis.m_vecAxes[0].y,
      this->m_Basis.m_vecAxes[0].z);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "BasisU", szValue: string);
    sprintf(
      string,
      format: "%g %g %g",
      this->m_Basis.m_vecAxes[1].x,
      this->m_Basis.m_vecAxes[1].y,
      this->m_Basis.m_vecAxes[1].z);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "BasisV", szValue: string);
    sprintf(
      string,
      format: "%g %g %g",
      this->m_Basis.m_vecAxes[2].x,
      this->m_Basis.m_vecAxes[2].y,
      this->m_Basis.m_vecAxes[2].z);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "BasisNormal", szValue: string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134290
// Name: private: void CMapOverlay::Handles_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Handles_Clear(CMapOverlay *this)
{
  this->m_Handles.m_iHit = -1;
  this->m_Handles.m_vec3D[0].x = 0.0;
  this->m_Handles.m_vec3D[1].x = 0.0;
  this->m_Handles.m_vec3D[0].y = 0.0;
  this->m_Handles.m_vec3D[0].z = 0.0;
  this->m_Handles.m_vec3D[1].y = 0.0;
  this->m_Handles.m_vec3D[1].z = 0.0;
  this->m_Handles.m_vec3D[2].x = 0.0;
  this->m_Handles.m_vec3D[2].y = 0.0;
  this->m_Handles.m_vec3D[2].z = 0.0;
  this->m_Handles.m_vec3D[3].x = 0.0;
  this->m_Handles.m_vec3D[3].y = 0.0;
  this->m_Handles.m_vec3D[3].z = 0.0;
  this->m_Handles.m_vecBasisCoords[0].x = -25.0;
  this->m_Handles.m_vecBasisCoords[0].y = -25.0;
  this->m_Handles.m_vecBasisCoords[1].x = -25.0;
  this->m_Handles.m_vecBasisCoords[1].y = 25.0;
  this->m_Handles.m_vecBasisCoords[2].x = 25.0;
  this->m_Handles.m_vecBasisCoords[2].y = 25.0;
  this->m_Handles.m_vecBasisCoords[3].x = 25.0;
  this->m_Handles.m_vecBasisCoords[3].y = -25.0;
}

//------------------------------------------------------------------------------
// Address: 0x10134350
// Name: private: void CMapOverlay::Handles_Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Handles_Render3D(CMapOverlay *this, CRender3D *pRender)
{
  int v3; // edi
  Vector *m_vec3D; // ebx

  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_FLAT);
  CRender::SetHandleStyle(this: pRender, size: 4, type: 1);
  v3 = 0;
  m_vec3D = this->m_Handles.m_vec3D;
  do
  {
    CRender3D::BeginRenderHitTarget(this: pRender, pObject: (CMapInstance *)this, uHandle: (CMatRenderContextPtr)v3);
    if ( this->m_Handles.m_iHit == v3 )
      CRender::SetHandleColor(this: pRender, r: 0xFFu, g: 0, b: 0);
    else
      CRender::SetHandleColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0xFFu);
    CRender::DrawHandle(this: pRender, vCenter: m_vec3D, vOffset: nullptr);
    CRender3D::EndRenderHitTarget(this: pRender, a2: v3++);
    ++m_vec3D;
  }
  while ( v3 < 4 );
  CRender::PopRenderMode(this: pRender);
}

//------------------------------------------------------------------------------
// Address: 0x101343E0
// Name: private: void CMapOverlay::Handles_Copy(struct CMapOverlay::Handles_t __near *,struct CMapOverlay::Handles_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Handles_Copy(
        CMapOverlay *this,
        CMapOverlay::Handles_t *pSrc,
        CMapOverlay::Handles_t *pDst)
{
  *pDst = *pSrc;
}

//------------------------------------------------------------------------------
// Address: 0x10134470
// Name: private: void CMapOverlay::Handles_UpdateParentKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Handles_UpdateParentKey(CMapOverlay *this)
{
  CMapEntity *v2; // edi
  char string[8]; // [esp+8h] [ebp-50h] BYREF

  v2 = (CMapEntity *)this->GetParent(this);
  if ( v2 != nullptr )
  {
    sprintf(
      string,
      format: "%g %g %g",
      this->m_Handles.m_vecBasisCoords[0].x,
      this->m_Handles.m_vecBasisCoords[0].y,
      (float)this->m_Basis.m_nAxesFlip[0]);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "uv0", szValue: string);
    sprintf(
      string,
      format: "%g %g %g",
      this->m_Handles.m_vecBasisCoords[1].x,
      this->m_Handles.m_vecBasisCoords[1].y,
      (float)this->m_Basis.m_nAxesFlip[1]);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "uv1", szValue: string);
    sprintf(
      string,
      format: "%g %g %g",
      this->m_Handles.m_vecBasisCoords[2].x,
      this->m_Handles.m_vecBasisCoords[2].y,
      (float)this->m_Basis.m_nAxesFlip[2]);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "uv2", szValue: string);
    sprintf(
      string,
      format: "%g %g %g",
      this->m_Handles.m_vecBasisCoords[3].x,
      this->m_Handles.m_vecBasisCoords[3].y,
      0.0);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "uv3", szValue: string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134600
// Name: private: void CMapOverlay::Material_UpdateParentKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Material_UpdateParentKey(CMapOverlay *this)
{
  CMapEntity *v2; // edi
  char string[8]; // [esp+8h] [ebp-50h] BYREF

  v2 = (CMapEntity *)this->GetParent(this);
  if ( v2 != nullptr )
  {
    sprintf(string, format: "%g", this->m_Material.m_vecTextureU.x);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "StartU", szValue: string);
    sprintf(string, format: "%g", this->m_Material.m_vecTextureU.y);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "EndU", szValue: string);
    sprintf(string, format: "%g", this->m_Material.m_vecTextureV.x);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "StartV", szValue: string);
    sprintf(string, format: "%g", this->m_Material.m_vecTextureV.y);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "EndV", szValue: string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134700
// Name: private: void CMapOverlay::Handles_FixOrder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Handles_FixOrder(CMapOverlay *this)
{
  const Vector *NormalFromPoints; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm7_4

  NormalFromPoints = GetNormalFromPoints(
                       p0: this->m_Handles.m_vec3D,
                       p1: &this->m_Handles.m_vec3D[1],
                       p2: &this->m_Handles.m_vec3D[2]);
  if ( (float)((float)((float)(this->m_Basis.m_vecAxes[2].y * NormalFromPoints->y)
                     + (float)(this->m_Basis.m_vecAxes[2].x * NormalFromPoints->x))
             + (float)(this->m_Basis.m_vecAxes[2].z * NormalFromPoints->z)) < 0.5
    && !s_FixingHandles )
  {
    x = this->m_Handles.m_vecBasisCoords[0].x;
    y = this->m_Handles.m_vecBasisCoords[0].y;
    v5 = this->m_Handles.m_vecBasisCoords[1].x;
    v6 = this->m_Handles.m_vecBasisCoords[1].y;
    v7 = this->m_Handles.m_vecBasisCoords[2].x;
    v8 = this->m_Handles.m_vecBasisCoords[2].y;
    v9 = this->m_Handles.m_vecBasisCoords[3].y;
    this->m_Handles.m_vecBasisCoords[0].x = this->m_Handles.m_vecBasisCoords[3].x;
    this->m_Handles.m_vecBasisCoords[1].x = v7;
    this->m_Handles.m_vecBasisCoords[0].y = v9;
    this->m_Handles.m_vecBasisCoords[1].y = v8;
    this->m_Handles.m_vecBasisCoords[2].x = v5;
    this->m_Handles.m_vecBasisCoords[2].y = v6;
    this->m_Handles.m_vecBasisCoords[3].x = x;
    s_FixingHandles = true;
    this->m_Handles.m_vecBasisCoords[3].y = y;
    CMapOverlay::Handles_Build3D(this);
    s_FixingHandles = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134820
// Name: public: virtual class CMapClass __near * CMapOverlay::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapOverlay *__thiscall CMapOverlay::CopyFrom(CMapOverlay *this, CMapClass *pObject, bool bUpdateDependencies)
{
  float z; // edx
  double y; // st7

  if ( pObject != nullptr )
  {
    CMapSideList::CopyFrom(this, pOther: pObject, bUpdateDependencies);
    CMapOverlay::Basis_Copy(this, pSrc: (CMapOverlay::Basis_t *)&pObject[1].m_Render2DBox.bmaxs.z, pDst: &this->m_Basis);
    CMapOverlay::Handles_Copy(this, pSrc: (CMapOverlay::Handles_t *)&pObject[1].m_VisGroups, pDst: &this->m_Handles);
    z = pObject[2].m_CullBox.bmins.z;
    this->m_Material.m_vecTextureU.x = pObject[2].m_CullBox.bmaxs.x;
    y = pObject[2].m_CullBox.bmaxs.y;
    *(float *)&this->m_Material.m_pTexture = z;
    this->m_Material.m_vecTextureU.y = y;
    this->m_Material.m_vecTextureV.x = pObject[2].m_CullBox.bmaxs.z;
    this->m_Material.m_vecTextureV.y = *(float *)&pObject[2].m_BoundingBox.__vftable;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101348B0
// Name: private: bool CMapOverlay::BuildEdgePlanes(class Vector const __near *,int,struct cplane_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapOverlay::BuildEdgePlanes(
        CMapOverlay *this,
        const Vector *pPoints,
        int nPointCount,
        cplane_t *pEdgePlanes,
        int nEdgePlaneCount)
{
  int v5; // ecx
  float *p_z; // esi
  int v7; // ebx
  float *v8; // edi
  int v9; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm7_4
  float v15; // xmm1_4
  float v16; // xmm7_4
  float v17; // xmm0_4
  Vector vecEdge; // [esp+0h] [ebp-10h] BYREF
  float *v20; // [esp+Ch] [ebp-4h]
  cplane_t *pEdgePlanesa; // [esp+20h] [ebp+10h]

  v20 = (float *)this;
  v5 = nPointCount;
  if ( nPointCount > 0 )
  {
    p_z = &pEdgePlanes->normal.z;
    v7 = 2;
    v8 = &pPoints->z;
    pEdgePlanesa = (cplane_t *)nPointCount;
    while ( 1 )
    {
      v9 = (v7 - 1) % v5;
      v10 = pPoints[v9].y - *(v8 - 1);
      v11 = pPoints[v9].z - *v8;
      vecEdge.x = pPoints[v9].x - *(v8 - 2);
      vecEdge.y = v10;
      vecEdge.z = v11;
      VectorNormalize(vec: &vecEdge);
      v12 = (float)(v20[95] * vecEdge.z) - (float)(v20[96] * vecEdge.y);
      v13 = v20[96] * vecEdge.x;
      v14 = v20[94];
      v15 = v14 * vecEdge.y;
      v16 = v14 * vecEdge.z;
      *p_z = v15 - (float)(v20[95] * vecEdge.x);
      *(p_z - 2) = v12;
      *(p_z - 1) = v13 - v16;
      v17 = (float)((float)(*(v8 - 1) * *(p_z - 1)) + (float)(*(v8 - 2) * v12)) + (float)(*v8 * *p_z);
      p_z[1] = v17;
      if ( (float)((float)((float)((float)(pPoints[v7 % nPointCount].y * *(p_z - 1))
                                 + (float)(pPoints[v7 % nPointCount].x * *(p_z - 2)))
                         + (float)(pPoints[v7 % nPointCount].z * *p_z))
                 - v17) > 0.0 )
      {
        *(p_z - 2) = -*(p_z - 2);
        *(p_z - 1) = -*(p_z - 1);
        *p_z = -*p_z;
        p_z[1] = -p_z[1];
      }
      v8 += 3;
      ++v7;
      p_z += 5;
      pEdgePlanesa = (cplane_t *)((char *)pEdgePlanesa - 1);
      if ( pEdgePlanesa == nullptr )
        break;
      v5 = nPointCount;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10134A50
// Name: public: void CMapOverlay::HandlesReset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::HandlesReset(CMapOverlay *this)
{
  this->m_Handles.m_iHit = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10134A60
// Name: public: bool CMapOverlay::HandlesHitTest(class CMapView __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapOverlay::HandlesHitTest(CMapOverlay *this, CMapView *pView, const Vector2D *vPoint)
{
  int v3; // esi
  Vector *i; // edi
  float y; // xmm2_4
  Vector2D vHandle; // [esp+Ch] [ebp-Ch] BYREF
  CMapOverlay *v8; // [esp+14h] [ebp-4h]

  v8 = this;
  v3 = 0;
  for ( i = this->m_Handles.m_vec3D; ; ++i )
  {
    pView->WorldToClient(this: pView, a2: &vHandle, a3: i);
    if ( (float)(vHandle.x - 8.0) <= vPoint->x && vPoint->x <= (float)(vHandle.x + 8.0) )
    {
      y = vPoint->y;
      if ( (float)(vHandle.y - 8.0) <= y && y <= (float)(vHandle.y + 8.0) )
        break;
    }
    if ( ++v3 >= 4 )
      return 0;
  }
  v8->m_Handles.m_iHit = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10134B00
// Name: public: void CMapOverlay::SetTexCoords(class Vector2D __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::SetTexCoords(CMapOverlay *this, Vector2D *vecTexCoords)
{
  this->m_Material.m_vecTextureU.x = vecTexCoords->x;
  this->m_Material.m_vecTextureV.x = vecTexCoords->y;
  this->m_Material.m_vecTextureV.y = vecTexCoords[1].y;
  this->m_Material.m_vecTextureU.y = vecTexCoords[2].x;
}

//------------------------------------------------------------------------------
// Address: 0x10134B30
// Name: public: void CMapOverlay::GetHandlePos(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::GetHandlePos(CMapOverlay *this, int iHandle, Vector *vecPos)
{
  *vecPos = this->m_Handles.m_vec3D[iHandle];
}

//------------------------------------------------------------------------------
// Address: 0x10134B60
// Name: private: void CMapOverlay::GetTriVerts(class CMapDisp __near *,class Vector2D const __near &,int __near *,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::GetTriVerts(
        CMapOverlay *this,
        CMapDisp *pDisp,
        const Vector2D *vecSurfUV,
        int *pTris,
        Vector2D *pVertsUV)
{
  int v5; // edx
  float v6; // xmm0_4
  float v7; // xmm1_4
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  float v11; // xmm3_4
  float v12; // xmm2_4
  int v13; // esi
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  int i; // ecx

  v5 = (1 << pDisp->m_CoreDispInfo.m_Power) + 1;
  v6 = (float)((float)v5 - 1.000001) * vecSurfUV->x;
  v7 = (float)((float)v5 - 1.000001) * vecSurfUV->y;
  v8 = (int)v6;
  v9 = (int)v7;
  if ( (int)v6 == 1 << pDisp->m_CoreDispInfo.m_Power )
    --v8;
  if ( v9 == 1 << pDisp->m_CoreDispInfo.m_Power )
    --v9;
  v10 = v9 + 1;
  v11 = (float)v9;
  v12 = (float)v8;
  v13 = v8 + 1;
  v14 = v6 - (float)v8;
  v15 = v7 - (float)v9;
  pVertsUV->x = (float)v8;
  if ( (v8 + v5 * v9) % 2 != 1 )
  {
    if ( v15 > v14 )
    {
      pVertsUV[1].x = v12;
      pVertsUV[1].y = (float)v10;
      pVertsUV[2].x = (float)v13;
      pVertsUV[2].y = (float)v10;
LABEL_13:
      pVertsUV->y = v11;
      goto LABEL_14;
    }
    v16 = (float)v13;
    pVertsUV[1].x = (float)v13;
    pVertsUV[1].y = (float)v10;
    pVertsUV[2].y = v11;
LABEL_12:
    pVertsUV[2].x = v16;
    goto LABEL_13;
  }
  pVertsUV[2].y = v11;
  pVertsUV[1].y = (float)v10;
  if ( (float)(v15 + v14) < 1.000001 )
  {
    pVertsUV[1].x = v12;
    v16 = (float)v13;
    goto LABEL_12;
  }
  pVertsUV->y = (float)v10;
  pVertsUV[1].x = (float)v13;
  pVertsUV[2].x = (float)v13;
LABEL_14:
  for ( i = 0; i < 3; ++i )
    pTris[i] = (int)(float)((float)(pVertsUV[i].y * (float)v5) + pVertsUV[i].x);
}

//------------------------------------------------------------------------------
// Address: 0x10134CB0
// Name: public: void CMapOverlay::SetMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::SetMaterial(CMapOverlay *this, const char *szMaterialName)
{
  IEditorTexture *ActiveTexture; // eax

  ActiveTexture = CTextureSystem::FindActiveTexture(
                    this: &g_Textures,
                    pszInputName: szMaterialName,
                    piIndex: nullptr,
                    bDummy: 1);
  if ( ActiveTexture != nullptr )
    this->m_Material.m_pTexture = ActiveTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10134CE0
// Name: public: enum ChunkFileResult_t CMapOverlay::SaveDataToVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapOverlay::SaveDataToVMF(CMapOverlay *this, CChunkFile *pFile, CChunkFile *pSaveInfo)
{
  ChunkFileResult_t result; // eax
  const char *v5; // eax
  char pszList[4]; // [esp+8h] [ebp-20Ch] BYREF
  char szSetValue[512]; // [esp+Ch] [ebp-208h] BYREF
  Vector vecTmp; // [esp+20Ch] [ebp-8h]

  result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "overlaydata");
  if ( result == ChunkFile_Ok )
  {
    v5 = this->m_Material.m_pTexture->GetName(this: this->m_Material.m_pTexture);
    result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "material", pszValue: v5);
    if ( result == ChunkFile_Ok )
    {
      result = CChunkFile::WriteKeyValueFloat(this: pFile, pszKey: "StartU", fValue: this->m_Material.m_vecTextureU.x);
      if ( result == ChunkFile_Ok )
      {
        result = CChunkFile::WriteKeyValueFloat(this: pFile, pszKey: "EndU", fValue: this->m_Material.m_vecTextureU.y);
        if ( result == ChunkFile_Ok )
        {
          result = CChunkFile::WriteKeyValueFloat(
                     this: pFile,
                     pszKey: "StartV",
                     fValue: this->m_Material.m_vecTextureV.x);
          if ( result == ChunkFile_Ok )
          {
            result = CChunkFile::WriteKeyValueFloat(
                       this: pFile,
                       pszKey: "EndV",
                       fValue: this->m_Material.m_vecTextureV.y);
            if ( result == ChunkFile_Ok )
            {
              result = CChunkFile::WriteKeyValueVector3(
                         this: pFile,
                         pszKey: "BasisOrigin",
                         vec: &this->m_Basis.m_vecOrigin);
              if ( result == ChunkFile_Ok )
              {
                result = CChunkFile::WriteKeyValueVector3(this: pFile, pszKey: "BasisU", vec: this->m_Basis.m_vecAxes);
                if ( result == ChunkFile_Ok )
                {
                  result = CChunkFile::WriteKeyValueVector3(
                             this: pFile,
                             pszKey: "BasisV",
                             vec: &this->m_Basis.m_vecAxes[1]);
                  if ( result == ChunkFile_Ok )
                  {
                    result = CChunkFile::WriteKeyValueVector3(
                               this: pFile,
                               pszKey: "BasisNormal",
                               vec: &this->m_Basis.m_vecAxes[2]);
                    if ( result == ChunkFile_Ok )
                    {
                      *(float *)&szSetValue[508] = this->m_Handles.m_vecBasisCoords[0].x;
                      vecTmp.x = this->m_Handles.m_vecBasisCoords[0].y;
                      vecTmp.y = (float)this->m_Basis.m_nAxesFlip[0];
                      result = CChunkFile::WriteKeyValueVector3(
                                 this: pFile,
                                 pszKey: "uv0",
                                 vec: (const Vector *)&szSetValue[508]);
                      if ( result == ChunkFile_Ok )
                      {
                        *(float *)&szSetValue[508] = this->m_Handles.m_vecBasisCoords[1].x;
                        vecTmp.x = this->m_Handles.m_vecBasisCoords[1].y;
                        vecTmp.y = (float)this->m_Basis.m_nAxesFlip[1];
                        result = CChunkFile::WriteKeyValueVector3(
                                   this: pFile,
                                   pszKey: "uv1",
                                   vec: (const Vector *)&szSetValue[508]);
                        if ( result == ChunkFile_Ok )
                        {
                          *(float *)&szSetValue[508] = this->m_Handles.m_vecBasisCoords[2].x;
                          vecTmp.x = this->m_Handles.m_vecBasisCoords[2].y;
                          vecTmp.y = (float)this->m_Basis.m_nAxesFlip[2];
                          result = CChunkFile::WriteKeyValueVector3(
                                     this: pFile,
                                     pszKey: "uv2",
                                     vec: (const Vector *)&szSetValue[508]);
                          if ( result == ChunkFile_Ok )
                          {
                            *(float *)&szSetValue[508] = this->m_Handles.m_vecBasisCoords[3].x;
                            vecTmp.x = this->m_Handles.m_vecBasisCoords[3].y;
                            vecTmp.y = 0.0;
                            result = CChunkFile::WriteKeyValueVector3(
                                       this: pFile,
                                       pszKey: "uv3",
                                       vec: (const Vector *)&szSetValue[508]);
                            if ( result == ChunkFile_Ok )
                            {
                              CMapWorld::FaceID_FaceListsToString(
                                pszList,
                                nSize: 512,
                                pFullFaceList: &this->m_Faces,
                                pPartialFaceList: nullptr);
                              result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "sides", pszValue: pszList);
                              if ( result == ChunkFile_Ok )
                                return CChunkFile::EndChunk(this: pFile);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10134F60
// Name: private: void CMapOverlay::Handles_SurfToOverlayPlane(class CMapFace __near *,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Handles_SurfToOverlayPlane(
        CMapOverlay *this,
        CMapFace *pFace,
        const Vector *vecSurf,
        Vector *vecPoint)
{
  int m_DispHandle; // edi
  CEditDispMgr *v6; // eax
  int v7; // eax
  float y; // xmm5_4
  float x; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float z; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  Vector vecWorld; // [esp+10h] [ebp-Ch] BYREF

  if ( pFace->m_DispHandle == 0xFFFF )
  {
    x = vecSurf->x;
    y = vecSurf->y;
    vecWorld.z = vecSurf->z;
  }
  else
  {
    m_DispHandle = pFace->m_DispHandle;
    v6 = EditDispMgr();
    v7 = (int)v6->GetDisp(this: v6, a2: m_DispHandle);
    CCoreDispInfo::SurfToBaseFacePlane(this: (CCoreDispInfo *)(v7 + 24), surfPt: vecSurf, planePt: &vecWorld);
    y = vecWorld.y;
    x = vecWorld.x;
  }
  v10 = this->m_Basis.m_vecAxes[2].x;
  v11 = this->m_Basis.m_vecAxes[2].y;
  z = this->m_Basis.m_vecAxes[2].z;
  v13 = (float)((float)(v10 * (float)(x - this->m_Basis.m_vecOrigin.x))
              + (float)(v11 * (float)(y - this->m_Basis.m_vecOrigin.y)))
      + (float)(z * (float)(vecWorld.z - this->m_Basis.m_vecOrigin.z));
  v14 = v10 * v13;
  v15 = v11 * v13;
  v16 = vecWorld.z - (float)(z * v13);
  vecPoint->x = x - v14;
  vecPoint->y = y - v15;
  vecPoint->z = v16;
}

//------------------------------------------------------------------------------
// Address: 0x10135060
// Name: private: void CMapOverlay::Material_TexCoordInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Material_TexCoordInit(CMapOverlay *this)
{
  int v1; // eax
  int v2; // edx
  bool v3; // bl
  bool v4; // al

  v1 = fabs(this->m_Basis.m_vecAxes[0].y) > fabs(this->m_Basis.m_vecAxes[0].x);
  if ( fabs(this->m_Basis.m_vecAxes[0].z) > fabs(*(&this->m_Basis.m_vecAxes[0].x + v1)) )
    v1 = 2;
  v2 = fabs(this->m_Basis.m_vecAxes[1].y) > fabs(this->m_Basis.m_vecAxes[1].x);
  if ( fabs(this->m_Basis.m_vecAxes[1].z) > fabs(*(&this->m_Basis.m_vecAxes[1].x + v2)) )
    v2 = 2;
  v3 = *(&this->m_Basis.m_vecAxes[0].x + v1) >= 0.0;
  v4 = *(&this->m_Basis.m_vecAxes[1].x + v2) >= 0.0;
  this->m_Material.m_vecTextureU.x = 0.0;
  this->m_Material.m_vecTextureU.y = 1.0;
  this->m_Material.m_vecTextureV.x = 1.0;
  this->m_Material.m_vecTextureV.y = 0.0;
  if ( !v3 )
  {
    if ( !v4 )
      goto LABEL_7;
LABEL_9:
    this->m_Material.m_vecTextureU.x = 1.0;
    this->m_Material.m_vecTextureU.y = 0.0;
    this->m_Material.m_vecTextureV.x = 0.0;
    this->m_Material.m_vecTextureV.y = 1.0;
    goto LABEL_7;
  }
  if ( !v4 )
    goto LABEL_9;
LABEL_7:
  CMapOverlay::Material_UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x10135180
// Name: public: virtual void CMapOverlay::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::CalcBounds(CMapOverlay *this, int bFullUpdate)
{
  int v3; // ebx
  Vector *m_vecAxes; // edi
  int v5; // ecx
  float *p_x; // edx
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  float x; // xmm3_4
  float z; // xmm6_4
  float v15; // xmm4_4
  float v16; // xmm2_4
  float *p_y; // eax
  int i; // ecx
  float v19; // xmm0_4
  float v20; // xmm0_4
  Vector vecMins; // [esp+Ch] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+18h] [ebp-Ch] BYREF

  CMapSideList::CalcBounds(this, bFullUpdate);
  v3 = 0;
  m_vecAxes = this->m_Basis.m_vecAxes;
LABEL_2:
  v5 = 0;
  p_x = &m_vecAxes->x;
  while ( *p_x != -99999.898 )
  {
    ++v5;
    ++p_x;
    if ( v5 >= 3 )
    {
      ++v3;
      ++m_vecAxes;
      if ( v3 < 3 )
        goto LABEL_2;
      v7 = this->m_Origin.y - 2.0;
      v8 = this->m_Origin.z - 2.0;
      v9 = this->m_Origin.x + 2.0;
      v10 = this->m_Origin.y + 2.0;
      v11 = this->m_Origin.z + 2.0;
      vecMins.x = this->m_Origin.x - 2.0;
      vecMins.y = v7;
      vecMins.z = v8;
      vecMaxs.x = v9;
      vecMaxs.y = v10;
      vecMaxs.z = v11;
      BoundBox::ResetBounds(this: &this->m_CullBox);
      BoundBox::ResetBounds(this: &this->m_Render2DBox);
      v12 = v8;
      x = vecMins.x;
      z = vecMaxs.z;
      v15 = v10;
      v16 = v9;
      p_y = &this->m_Handles.m_vec3D[0].y;
      for ( i = 4; i != 0; --i )
      {
        v19 = *(p_y - 1);
        if ( x > v19 )
          x = *(p_y - 1);
        if ( v19 > v16 )
          v16 = *(p_y - 1);
        if ( v7 > *p_y )
          v7 = *p_y;
        if ( *p_y > v15 )
          v15 = *p_y;
        v20 = p_y[1];
        if ( v12 > v20 )
          v12 = p_y[1];
        if ( v20 > z )
          z = p_y[1];
        p_y += 3;
      }
      vecMaxs.z = z;
      vecMins.z = v12;
      vecMaxs.y = v15;
      vecMins.y = v7;
      vecMaxs.x = v16;
      vecMins.x = x;
      if ( (float)(v16 - x) == 0.0 )
      {
        vecMins.x = x - 0.5;
        vecMaxs.x = v16 + 0.5;
      }
      if ( (float)(v15 - v7) == 0.0 )
      {
        vecMins.y = v7 - 0.5;
        vecMaxs.y = v15 + 0.5;
      }
      if ( (float)(z - v12) == 0.0 )
      {
        vecMins.z = v12 - 0.5;
        vecMaxs.z = z + 0.5;
      }
      BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &vecMins, maxs: &vecMaxs);
      this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
      this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
      this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
      this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
      this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
      this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
      BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &vecMins, maxs: &vecMaxs);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135380
// Name: public: void CMapOverlay::HandlesDragTo(class Vector __near &,class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::HandlesDragTo(CMapOverlay *this, Vector *vecImpact, CMapFace *pFace)
{
  unsigned int m_iHit; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  Vector2D *v8; // eax
  float v9; // xmm1_4
  Vector vecOverlay; // [esp+4h] [ebp-Ch] BYREF

  m_iHit = this->m_Handles.m_iHit;
  if ( m_iHit < 4 )
  {
    this->m_Handles.m_vec3D[m_iHit] = *vecImpact;
    CMapOverlay::Handles_SurfToOverlayPlane(this, pFace, vecSurf: vecImpact, vecPoint: &vecOverlay);
    v5 = vecOverlay.x - this->m_Basis.m_vecOrigin.x;
    v6 = vecOverlay.y - this->m_Basis.m_vecOrigin.y;
    v7 = vecOverlay.z - this->m_Basis.m_vecOrigin.z;
    v8 = &this->m_Handles.m_vecBasisCoords[this->m_Handles.m_iHit];
    v9 = (float)((float)(this->m_Basis.m_vecAxes[1].y * v6) + (float)(this->m_Basis.m_vecAxes[1].x * v5))
       + (float)(this->m_Basis.m_vecAxes[1].z * v7);
    v8->x = (float)((float)(this->m_Basis.m_vecAxes[0].y * v6) + (float)(this->m_Basis.m_vecAxes[0].x * v5))
          + (float)(this->m_Basis.m_vecAxes[0].z * v7);
    v8->y = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135470
// Name: public: void CMapOverlay::HandleMoveTo(int,class Vector __near &,class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::HandleMoveTo(CMapOverlay *this, unsigned int iHandle, Vector *vecPoint, CMapFace *pFace)
{
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  Vector vecOverlay; // [esp+8h] [ebp-Ch] BYREF

  if ( iHandle <= 3 )
  {
    this->m_Handles.m_vec3D[iHandle] = *vecPoint;
    CMapOverlay::Handles_SurfToOverlayPlane(this, pFace, vecSurf: vecPoint, vecPoint: &vecOverlay);
    v5 = vecOverlay.x - this->m_Basis.m_vecOrigin.x;
    v6 = vecOverlay.y - this->m_Basis.m_vecOrigin.y;
    v7 = vecOverlay.z - this->m_Basis.m_vecOrigin.z;
    v8 = (float)((float)(this->m_Basis.m_vecAxes[0].y * v6) + (float)(this->m_Basis.m_vecAxes[0].x * v5))
       + (float)(this->m_Basis.m_vecAxes[0].z * v7);
    v9 = (float)(this->m_Basis.m_vecAxes[1].y * v6) + (float)(v5 * this->m_Basis.m_vecAxes[1].x);
    v10 = this->m_Basis.m_vecAxes[1].z * v7;
    this->m_Handles.m_vecBasisCoords[iHandle].x = v8;
    this->m_Handles.m_vecBasisCoords[iHandle].y = v9 + v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135550
// Name: private: void CMapOverlay::Basis_BuildAxes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Basis_BuildAxes(CMapOverlay *this)
{
  CMapFace *m_pFace; // eax
  float x; // xmm0_4
  float y; // xmm4_4
  float z; // xmm3_4
  float v6; // xmm1_4
  int v7; // eax
  Vector *m_vecAxes; // edi
  float v9; // xmm6_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  Vector vecFaceNormal; // [esp+4h] [ebp-10h] BYREF

  m_pFace = this->m_Basis.m_pFace;
  if ( m_pFace != nullptr )
  {
    vecFaceNormal = m_pFace->plane.normal;
    VectorNormalize(vec: &vecFaceNormal);
    x = vecFaceNormal.x;
    y = vecFaceNormal.y;
    z = vecFaceNormal.z;
    this->m_Basis.m_vecAxes[2] = vecFaceNormal;
    v6 = x;
    v7 = 0;
    if ( fabs(y) > fabs(x) )
    {
      v7 = 1;
      v6 = y;
    }
    if ( fabs(z) > fabs(v6) || v7 == 1 )
    {
      m_vecAxes = this->m_Basis.m_vecAxes;
      this->m_Basis.m_vecAxes[0].x = 1.0;
      this->m_Basis.m_vecAxes[0].y = 0.0;
    }
    else
    {
      m_vecAxes = this->m_Basis.m_vecAxes;
      this->m_Basis.m_vecAxes[0].x = 0.0;
      this->m_Basis.m_vecAxes[0].y = 1.0;
    }
    m_vecAxes->z = 0.0;
    v9 = this->m_Basis.m_vecAxes[2].z;
    v10 = this->m_Basis.m_vecAxes[2].y;
    v11 = (float)(m_vecAxes->x * v9) - (float)(this->m_Basis.m_vecAxes[2].x * m_vecAxes->z);
    v12 = (float)(this->m_Basis.m_vecAxes[2].x * m_vecAxes->y) - (float)(m_vecAxes->x * v10);
    this->m_Basis.m_vecAxes[1].x = (float)(0.0 * v10) - (float)(m_vecAxes->y * v9);
    this->m_Basis.m_vecAxes[1].y = v11;
    this->m_Basis.m_vecAxes[1].z = v12;
    VectorNormalize(vec: &this->m_Basis.m_vecAxes[1]);
    v13 = this->m_Basis.m_vecAxes[2].z;
    v14 = this->m_Basis.m_vecAxes[2].y;
    v15 = this->m_Basis.m_vecAxes[2].x;
    v16 = (float)(this->m_Basis.m_vecAxes[1].z * v15) - (float)(this->m_Basis.m_vecAxes[1].x * v13);
    v17 = (float)(this->m_Basis.m_vecAxes[1].x * v14) - (float)(this->m_Basis.m_vecAxes[1].y * v15);
    m_vecAxes->x = (float)(this->m_Basis.m_vecAxes[1].y * v13) - (float)(this->m_Basis.m_vecAxes[1].z * v14);
    m_vecAxes->y = v16;
    m_vecAxes->z = v17;
    VectorNormalize(vec: m_vecAxes);
    if ( (this->m_Basis.m_nAxesFlip[0] & 1) != 0 )
      m_vecAxes->x = -m_vecAxes->x;
    if ( (this->m_Basis.m_nAxesFlip[0] & 2) != 0 )
      this->m_Basis.m_vecAxes[0].y = -this->m_Basis.m_vecAxes[0].y;
    if ( (this->m_Basis.m_nAxesFlip[0] & 4) != 0 )
      this->m_Basis.m_vecAxes[0].z = -this->m_Basis.m_vecAxes[0].z;
    if ( (this->m_Basis.m_nAxesFlip[1] & 1) != 0 )
      this->m_Basis.m_vecAxes[1].x = -this->m_Basis.m_vecAxes[1].x;
    if ( (this->m_Basis.m_nAxesFlip[1] & 2) != 0 )
      this->m_Basis.m_vecAxes[1].y = -this->m_Basis.m_vecAxes[1].y;
    if ( (this->m_Basis.m_nAxesFlip[1] & 4) != 0 )
      this->m_Basis.m_vecAxes[1].z = -this->m_Basis.m_vecAxes[1].z;
    if ( (this->m_Basis.m_nAxesFlip[2] & 1) != 0 )
      this->m_Basis.m_vecAxes[2].x = -this->m_Basis.m_vecAxes[2].x;
    if ( (this->m_Basis.m_nAxesFlip[2] & 2) != 0 )
      this->m_Basis.m_vecAxes[2].y = -this->m_Basis.m_vecAxes[2].y;
    if ( (this->m_Basis.m_nAxesFlip[2] & 4) != 0 )
      this->m_Basis.m_vecAxes[2].z = -this->m_Basis.m_vecAxes[2].z;
    CMapOverlay::Basis_UpdateParentKey(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135830
// Name: private: void CMapOverlay::ClipFace_ResolveBarycentricClip(class CMapDisp __near *,struct CMapOverlay::ClipFace_t __near *,int,class Vector2D const __near &,float __near *,int __near *,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapOverlay::ClipFace_ResolveBarycentricClip(
        CMapOverlay *this@<ecx>,
        int a2@<ebp>,
        CMapDisp *pDisp,
        CMapOverlay::ClipFace_t *pClipFace,
        int iClipFacePoint,
        const Vector2D *vecPointUV,
        float *pCoefs,
        int *pTris,
        Vector2D *pVertsUV)
{
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  int v12; // ecx
  int i; // eax
  float v14; // xmm4_4
  int v15; // ecx
  int v16; // eax
  CMapOverlay::BlendData_t *v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  CMapOverlay::BlendData_t *m_pMemory; // eax
  int v23; // edx
  float v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm1_4
  int v28; // [esp-8h] [ebp-14h]
  _DWORD v29[2]; // [esp-4h] [ebp-10h]
  int iVert; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v29[1] = a2;
  iVert = retaddr;
  v9 = (float)((1 << pDisp->m_CoreDispInfo.m_Power) + 1) - 1.000001;
  v10 = vecPointUV->x * v9;
  v11 = vecPointUV->y * v9;
  v12 = 0;
  for ( i = 0; i < 3; ++i )
  {
    v14 = fabs(pCoefs[i]);
    *((_BYTE *)v29 + i) = 0;
    if ( v14 < 0.001 )
    {
      ++v12;
      *((_BYTE *)v29 + i) = 1;
    }
  }
  if ( v12 == 2 )
  {
    v15 = 0;
    while ( *((_BYTE *)v29 + v15) != 0 )
    {
      if ( ++v15 >= 3 )
        goto LABEL_9;
    }
    v18 = iClipFacePoint;
    pClipFace->m_aBlends.m_Memory.m_pMemory[v18].m_nType = 0;
    pClipFace->m_aBlends.m_Memory.m_pMemory[v18].m_iPoints[0] = pTris[v15];
  }
  else if ( v12 == 1 )
  {
    v19 = 0;
    while ( *((_BYTE *)v29 + v19) == 0 )
    {
      if ( ++v19 >= 3 )
        goto LABEL_9;
    }
    v28 = v19;
    v20 = iClipFacePoint;
    pClipFace->m_aBlends.m_Memory.m_pMemory[v20].m_nType = 1;
    v21 = (v19 + 1) % 3;
    m_pMemory = pClipFace->m_aBlends.m_Memory.m_pMemory;
    v29[0] = v21;
    m_pMemory[v20].m_iPoints[0] = pTris[v21];
    v23 = (v28 + 2) % 3;
    pClipFace->m_aBlends.m_Memory.m_pMemory[v20].m_iPoints[1] = pTris[v23];
    v24 = v10 - pVertsUV[v29[0]].x;
    v25 = pVertsUV[v23].x - pVertsUV[v29[0]].x;
    v26 = v11 - pVertsUV[v29[0]].y;
    v27 = pVertsUV[v23].y - pVertsUV[v29[0]].y;
    pClipFace->m_aBlends.m_Memory.m_pMemory[v20].m_flBlends[0] = fsqrt((float)(v26 * v26) + (float)(v24 * v24))
                                                               / fsqrt((float)(v27 * v27) + (float)(v25 * v25));
  }
  else
  {
LABEL_9:
    v16 = iClipFacePoint;
    pClipFace->m_aBlends.m_Memory.m_pMemory[v16].m_nType = 2;
    pClipFace->m_aBlends.m_Memory.m_pMemory[v16].m_iPoints[0] = *(_WORD *)pTris;
    pClipFace->m_aBlends.m_Memory.m_pMemory[v16].m_iPoints[1] = *((_WORD *)pTris + 2);
    pClipFace->m_aBlends.m_Memory.m_pMemory[v16].m_iPoints[2] = *((_WORD *)pTris + 4);
    v17 = &pClipFace->m_aBlends.m_Memory.m_pMemory[iClipFacePoint];
    v17->m_flBlends[0] = *pCoefs;
    v17->m_flBlends[1] = pCoefs[1];
    v17->m_flBlends[2] = pCoefs[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135A60
// Name: private: void CMapOverlay::ClipFace_BuildBlend(struct CMapOverlay::ClipFace_t __near *,class CMapDisp __near *,struct cplane_t __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::ClipFace_BuildBlend(
        CMapOverlay *this,
        CMapOverlay::ClipFace_t *pClipFace,
        CMapDisp *pDisp,
        cplane_t *pClipPlane,
        __int16 iClip,
        const Vector *vecUV,
        const Vector *vecPoint)
{
  int v7; // esi
  float v8; // xmm0_4
  float v9; // xmm1_4
  int v10; // ebx
  int v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float x; // xmm2_4
  __int16 v15; // dx
  int v16; // eax
  float y; // xmm4_4
  CMapOverlay::ClipFace_t *v18; // eax
  __int16 v19; // si
  CMapOverlay::BlendData_t *m_pMemory; // edx
  __int16 v21; // cx
  int nSnapU; // [esp+14h] [ebp+Ch]
  __int16 nNextU; // [esp+20h] [ebp+18h]

  v7 = (1 << pDisp->m_CoreDispInfo.m_Power) + 1;
  v8 = (float)((float)v7 - 1.000001) * vecUV->x;
  v9 = (float)((float)v7 - 1.000001) * vecUV->y;
  v10 = (int)v8;
  nSnapU = (int)v8;
  v11 = (int)v9;
  if ( (int)v8 == v7 - 1 )
    LOWORD(nSnapU) = --v10;
  if ( v11 == v7 - 1 )
    --v11;
  v12 = v8 - (float)v10;
  v13 = v9 - (float)v11;
  x = pClipPlane->normal.x;
  nNextU = v10 + 1;
  v15 = v11 + 1;
  if ( pClipPlane->normal.x == 1.0 )
  {
    v16 = 3;
    goto LABEL_14;
  }
  y = pClipPlane->normal.y;
  if ( y == 1.0 )
    goto LABEL_13;
  if ( x == 0.70700002 && y == 0.70700002 )
  {
    v16 = 2;
    goto LABEL_14;
  }
  if ( x != -0.70700002 || (v16 = 4, y != 0.70700002) )
LABEL_13:
    v16 = 1;
LABEL_14:
  switch ( v16 )
  {
    case 1:
      v18 = pClipFace;
      v19 = iClip * v7;
      m_pMemory = pClipFace->m_aBlends.m_Memory.m_pMemory;
      if ( COERCE_FLOAT(LODWORD(v12) & _mask__AbsFloat_) >= 0.000001 )
      {
        m_pMemory[pClipFace->m_nPointCount].m_nType = 1;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[0] = v19 + v10;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[1] = v10 + 1 + v19;
        goto LABEL_28;
      }
      m_pMemory[pClipFace->m_nPointCount].m_nType = 0;
      pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[0] = v10 + v19;
      break;
    case 2:
      if ( fabs(v12) < 0.000001 && fabs(v13) < 0.000001 )
        goto LABEL_26;
      pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_nType = 1;
      pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[0] = nSnapU + v7 * v15;
      pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[1] = nNextU + v7 * v11;
      pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_flBlends[0] = v12;
      break;
    case 3:
      v21 = iClip + v7 * v11;
      if ( COERCE_FLOAT(LODWORD(v13) & _mask__AbsFloat_) >= 0.000001 )
      {
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_nType = 1;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[0] = v21;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[1] = iClip + v7 * v15;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_flBlends[0] = v13;
      }
      else
      {
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_nType = 0;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[0] = v21;
      }
      break;
    case 4:
      if ( fabs(v12) >= 0.000001 || fabs(v13) >= 0.000001 )
      {
        v18 = pClipFace;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_nType = 1;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[0] = nSnapU + v7 * v11;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[1] = nNextU + v7 * v15;
LABEL_28:
        v18->m_aBlends.m_Memory.m_pMemory[v18->m_nPointCount].m_flBlends[0] = v12;
      }
      else
      {
LABEL_26:
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_nType = 0;
        pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount].m_iPoints[0] = v10 + v7 * v11;
      }
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135D90
// Name: private: void CMapOverlay::ClipFace_CopyBlendFrom(struct CMapOverlay::ClipFace_t __near *,struct CMapOverlay::BlendData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::ClipFace_CopyBlendFrom(
        CMapOverlay *this,
        CMapOverlay::ClipFace_t *pClipFace,
        CMapOverlay::BlendData_t *pBlendFrom)
{
  pClipFace->m_aBlends.m_Memory.m_pMemory[pClipFace->m_nPointCount] = *pBlendFrom;
}

//------------------------------------------------------------------------------
// Address: 0x10135E20
// Name: private: void CMapOverlay::ClipFace_BuildFacesFromBlendedData(struct CMapOverlay::ClipFace_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::ClipFace_BuildFacesFromBlendedData(CMapOverlay *this, CMapDisp *pClipFace)
{
  int SetRenderColor_2_low; // edi
  CEditDispMgr *v4; // eax
  int v5; // eax
  int v6; // edi
  CMapDisp *v7; // edx
  int v8; // eax
  CMapOverlay::BlendData_t *x_low; // ecx
  int v10; // ebx
  CoreDispVert_t *v11; // ebx
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  CoreDispVert_t *m_pVerts; // ebx
  int v17; // edx
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v21; // xmm3_4
  int v22; // edx
  CoreDispVert_t *v23; // edx
  int v24; // ebx
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float *v28; // ecx
  int v29; // edi
  float v30; // xmm1_4
  int v31; // ebx
  float v32; // xmm2_4
  float v33; // xmm7_4
  float v34; // xmm6_4
  float v35; // xmm5_4
  float v36; // xmm7_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  float v39; // xmm7_4
  float v40; // xmm0_4
  Vector *m_pParent; // ecx
  float v42; // [esp+28h] [ebp-20h]
  float v43; // [esp+38h] [ebp-10h]
  int v44; // [esp+40h] [ebp-8h]
  int iPoint; // [esp+44h] [ebp-4h]
  CMapDisp *pDisp; // [esp+50h] [ebp+8h]

  if ( LOWORD(pClipFace->__vftable[5].SetRenderColor_2) != 0xFFFF )
  {
    SetRenderColor_2_low = LOWORD(pClipFace->__vftable[5].SetRenderColor_2);
    v4 = EditDispMgr();
    v5 = (int)v4->GetDisp(this: v4, a2: SetRenderColor_2_low);
    v6 = 0;
    v7 = (CMapDisp *)v5;
    pDisp = (CMapDisp *)v5;
    iPoint = 0;
    if ( pClipFace->m_nObjectID > 0 )
    {
      v8 = 0;
      v44 = 0;
      while ( 1 )
      {
        x_low = (CMapOverlay::BlendData_t *)LODWORD(pClipFace->m_CoreDispInfo.m_Surf.m_Normals[1].x);
        v10 = *(int *)((char *)&x_low->m_nType + v6);
        if ( v10 == 0 )
          break;
        if ( v10 == 1 )
        {
          m_pVerts = v7->m_CoreDispInfo.m_pVerts;
          v17 = *(__int16 *)((char *)x_low->m_iPoints + v6);
          x = m_pVerts[v17].m_Vert.x;
          y = m_pVerts[v17].m_Vert.y;
          z = m_pVerts[v17].m_Vert.z;
          v21 = *(float *)((char *)x_low->m_flBlends + v6);
          v22 = *(__int16 *)((char *)&x_low->m_iPoints[1] + v6);
          v13 = (float)((float)(m_pVerts[v22].m_Vert.x - x) * v21) + x;
          v14 = (float)((float)(m_pVerts[v22].m_Vert.y - y) * v21) + y;
          v15 = (float)((float)(m_pVerts[v22].m_Vert.z - z) * v21) + z;
          goto LABEL_10;
        }
        if ( v10 == 2 )
        {
          v23 = v7->m_CoreDispInfo.m_pVerts;
          v24 = *(__int16 *)((char *)&x_low->m_iPoints[1] + v6);
          v25 = v23[v24].m_Vert.x;
          v26 = v23[v24].m_Vert.y;
          v27 = v23[v24].m_Vert.z;
          v28 = (float *)((char *)&x_low->m_nType + v6);
          v29 = *((__int16 *)v28 + 2);
          v30 = v23[v29].m_Vert.y;
          v31 = *((__int16 *)v28 + 4);
          v32 = v23[v29].m_Vert.z;
          v33 = v28[5];
          v43 = v23[v31].m_Vert.y * v33;
          v34 = v23[v31].m_Vert.z * v33;
          v35 = v23[v31].m_Vert.x * v33;
          v36 = v28[4];
          v42 = v25 * v36;
          v37 = v26 * v36;
          v38 = v27 * v36;
          v39 = v28[3];
          v40 = (float)(v39 * v23[v29].m_Vert.x) + v42;
          v6 = v44;
          v14 = (float)((float)(v30 * v39) + v37) + v43;
          v13 = v40 + v35;
          v15 = (float)((float)(v32 * v39) + v38) + v34;
LABEL_10:
          v7 = pDisp;
LABEL_11:
          m_pParent = (Vector *)pClipFace->m_pParent;
          m_pParent[v8].z = v15;
          m_pParent[v8].y = v14;
          m_pParent[v8].x = v13;
        }
        v6 += 24;
        ++v8;
        ++iPoint;
        v44 = v6;
        if ( iPoint >= pClipFace->m_nObjectID )
          return;
      }
      v11 = v7->m_CoreDispInfo.m_pVerts;
      v12 = *(__int16 *)((char *)x_low->m_iPoints + v6);
      v13 = v11[v12].m_Vert.x;
      v14 = v11[v12].m_Vert.y;
      v15 = v11[v12].m_Vert.z;
      goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136040
// Name: public: virtual void CMapOverlay::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Render3D(CMapOverlay *this, CRender3D *pRender)
{
  CMapOverlay *v2; // ebx
  int m_Size; // esi
  int v4; // edi
  IEditorTexture *m_pTexture; // eax
  int v6; // eax
  CMapOverlay::ClipFace_t *v7; // esi
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // ebx
  IMesh *v10; // eax
  int v11; // ebx
  Vector2D *m_pMemory; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float *v15; // eax
  Vector2D *v16; // ecx
  float v17; // xmm1_4
  float *v18; // eax
  Vector *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float z; // xmm2_4
  float *m_pCurrPosition; // eax
  Vector *v24; // ecx
  float v25; // xmm1_4
  float v26; // xmm2_4
  float *m_pCurrNormal; // eax
  int m_nVertexCount; // eax
  int v29; // eax
  CMapOverlay::ClipFace_t *v30; // esi
  IMesh *v31; // eax
  IMesh *v32; // edi
  IMesh *v33; // eax
  int v34; // ebx
  int v35; // edi
  Vector *v36; // eax
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float *v40; // eax
  Vector *v41; // ecx
  float v42; // xmm1_4
  float v43; // xmm2_4
  float *v44; // eax
  int v45; // eax
  CToolManager *v46; // eax
  Vector *m_vecAxes; // esi
  int v48; // ecx
  float *p_x; // edx
  int m_nPointCount; // [esp-4h] [ebp-220h]
  int v51; // [esp-4h] [ebp-220h]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-210h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-28h]
  int nFaceCount; // [esp+1F8h] [ebp-24h]
  IMesh *pMesh; // [esp+1FCh] [ebp-20h]
  IMatRenderContext *v56; // [esp+200h] [ebp-1Ch]
  CMapOverlay *v57; // [esp+204h] [ebp-18h]
  int iFace; // [esp+208h] [ebp-14h]
  bool bTextured; // [esp+20Fh] [ebp-Dh]
  int v60; // [esp+218h] [ebp-4h]

  v2 = this;
  m_Size = this->m_aRenderFaces.m_Size;
  v4 = 0;
  v57 = this;
  nFaceCount = m_Size;
  if ( m_Size != 0 )
  {
    if ( this->GetSelectionState(this) != SELECT_MODIFY )
    {
      m_pTexture = v2->m_Material.m_pTexture;
      bTextured = false;
      if ( m_pTexture != nullptr )
      {
        CRender::BindTexture(this: pRender, pTexture: m_pTexture);
        CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TEXTURED);
        bTextured = true;
      }
      else
      {
        CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_FLAT);
      }
      v6 = 0;
      iFace = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = v2->m_aRenderFaces.m_Memory.m_pMemory[v6];
          if ( v7 != nullptr )
          {
            CMeshBuilder::CMeshBuilder(this: &meshBuilder);
            v60 = 0;
            v8 = materials->GetRenderContext(this: materials);
            v9 = v8;
            v56 = v8;
            pRenderContext.m_pObject = v8;
            LOBYTE(v60) = 1;
            if ( v8 != nullptr )
              v8->BeginRender(this: v8);
            LOBYTE(v60) = 2;
            v10 = v9->GetDynamicMesh(this: v9, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
            m_nPointCount = v7->m_nPointCount;
            pMesh = v10;
            CMeshBuilder::Begin(this: &meshBuilder, pMesh: v10, type: MATERIAL_POLYGON, numPrimitives: m_nPointCount);
            if ( v7->m_nPointCount > 0 )
            {
              v11 = 0;
              do
              {
                if ( bTextured )
                {
                  m_pMemory = v7->m_aTexCoords[0].m_Memory.m_pMemory;
                  x = m_pMemory[v4].x;
                  y = m_pMemory[v4].y;
                  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = x;
                  v15[1] = y;
                  v16 = v7->m_aTexCoords[1].m_Memory.m_pMemory;
                  v17 = v16[v4].y;
                  v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v16[v4].x;
                  v18[1] = v17;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
                }
                else
                {
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16744448;
                }
                v19 = v7->m_aPoints.m_Memory.m_pMemory;
                v20 = v19[v11].x;
                v21 = v19[v11].y;
                z = v19[v11].z;
                m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
                m_pCurrPosition[1] = v21;
                m_pCurrPosition[2] = z;
                v24 = v7->m_aNormals.m_Memory.m_pMemory;
                v25 = v24[v11].y;
                v26 = v24[v11].z;
                m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = v24[v11].x;
                m_pCurrNormal[1] = v25;
                m_pCurrNormal[2] = v26;
                CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                ++v4;
                ++v11;
              }
              while ( v4 < v7->m_nPointCount );
              v9 = v56;
            }
            if ( meshBuilder.m_bGenerateIndices )
            {
              switch ( meshBuilder.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  m_nVertexCount = 0;
                  break;
                default:
                  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(
                this: &meshBuilder.m_IndexBuilder,
                primitiveType: meshBuilder.m_Type,
                nIndexCount: m_nVertexCount);
            }
            meshBuilder.m_pMesh->UnlockMesh(
              this: meshBuilder.m_pMesh,
              a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
              a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
              a4: &meshBuilder);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            meshBuilder.m_pMesh = nullptr;
            pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
            LOBYTE(v60) = 3;
            v9->EndRender(this: v9);
            LOBYTE(v60) = 0;
            v9->Release(this: v9);
            v60 = 4;
            if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
              && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
            {
              meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
            }
            v60 = -1;
            if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
              && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
            {
              meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
            }
            v2 = v57;
            v4 = 0;
          }
          v6 = iFace + 1;
          iFace = v6;
        }
        while ( v6 < nFaceCount );
        m_Size = nFaceCount;
      }
      CRender::PopRenderMode(this: pRender);
    }
    if ( v2->GetSelectionState(this: v2) != SELECT_NONE )
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
      v29 = 0;
      iFace = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v30 = v2->m_aRenderFaces.m_Memory.m_pMemory[v29];
          if ( v30 != nullptr )
          {
            meshBuilder.m_pMesh = nullptr;
            meshBuilder.m_bGenerateIndices = false;
            memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
            meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
            meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
            memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
            meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v60 = 8;
            v31 = (IMesh *)materials->GetRenderContext(this: materials);
            v32 = v31;
            pMesh = v31;
            pRenderContext.m_pObject = (IMatRenderContext *)v31;
            LOBYTE(v60) = 9;
            if ( v31 != nullptr )
              v31->IsDynamic(this: v31);
            LOBYTE(v60) = 10;
            v33 = (IMesh *)v32->IVertexBuffer::__vftable[1].AccessRawHardwareDataStream(
                             this: v32,
                             a2: 1u,
                             a3: 0,
                             a4: 0,
                             a5: nullptr);
            v51 = v30->m_nPointCount;
            v56 = (IMatRenderContext *)v33;
            CMeshBuilder::Begin(this: &meshBuilder, pMesh: v33, type: MATERIAL_LINE_LOOP, numPrimitives: v51);
            v34 = 0;
            if ( v30->m_nPointCount > 0 )
            {
              v35 = 0;
              do
              {
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
                v36 = v30->m_aPoints.m_Memory.m_pMemory;
                v37 = v36[v35].x;
                v38 = v36[v35].y;
                v39 = v36[v35].z;
                v40 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = v37;
                v40[1] = v38;
                v40[2] = v39;
                v41 = v30->m_aNormals.m_Memory.m_pMemory;
                v42 = v41[v35].y;
                v43 = v41[v35].z;
                v44 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = v41[v35].x;
                v44[1] = v42;
                v44[2] = v43;
                CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                ++v34;
                ++v35;
              }
              while ( v34 < v30->m_nPointCount );
              v32 = pMesh;
            }
            if ( meshBuilder.m_bGenerateIndices )
            {
              switch ( meshBuilder.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  v45 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  v45 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  v45 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  v45 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  v45 = 0;
                  break;
                default:
                  v45 = meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(
                this: &meshBuilder.m_IndexBuilder,
                primitiveType: meshBuilder.m_Type,
                nIndexCount: v45);
            }
            meshBuilder.m_pMesh->UnlockMesh(
              this: meshBuilder.m_pMesh,
              a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
              a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
              a4: &meshBuilder);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            meshBuilder.m_pMesh = nullptr;
            ((void (__thiscall *)(IMatRenderContext *, int, _DWORD))v56->ClearBuffers)(a1: v56, a2: -1, a3: 0);
            LOBYTE(v60) = 11;
            ((void (__thiscall *)(IMesh *))v32->BeginCastBuffer)(a1: v32);
            LOBYTE(v60) = 8;
            v32->GetVertexFormat(this: v32);
            v60 = 12;
            if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
              && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
            {
              meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
            }
            v60 = -1;
            if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
              && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
            {
              meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
            }
            v2 = v57;
          }
          v29 = iFace + 1;
          iFace = v29;
        }
        while ( v29 < nFaceCount );
      }
      CRender::PopRenderMode(this: pRender);
    }
  }
  v46 = ToolManager();
  if ( CToolManager::GetActiveToolID(this: v46) == TOOL_OVERLAY )
  {
    iFace = 0;
    m_vecAxes = v2->m_Basis.m_vecAxes;
LABEL_65:
    v48 = 0;
    p_x = &m_vecAxes->x;
    while ( *p_x != -99999.898 )
    {
      ++v48;
      ++p_x;
      if ( v48 >= 3 )
      {
        ++m_vecAxes;
        if ( ++iFace < 3 )
          goto LABEL_65;
        if ( v2->GetSelectionState(this: v2) == SELECT_NORMAL )
          CMapOverlay::Handles_Render3D(this: v2, pRender);
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136680
// Name: private: bool CMapOverlay::EntityOnSurfFromListToBaseFacePlane(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapOverlay::EntityOnSurfFromListToBaseFacePlane(
        CMapOverlay *this,
        const Vector *vecWorldPoint,
        Vector *vecBasePoint)
{
  int m_Size; // edx
  int v4; // edi
  CMapFace *v5; // eax
  int m_DispHandle; // eax
  int v7; // esi
  CEditDispMgr *v8; // eax
  int v9; // eax
  int nFaceCount; // [esp+Ch] [ebp-8h]
  CMapOverlay *v12; // [esp+10h] [ebp-4h]

  m_Size = this->m_Faces.m_Size;
  v4 = 0;
  v12 = this;
  nFaceCount = m_Size;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = this->m_Faces.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      m_DispHandle = v5->m_DispHandle;
      if ( (_WORD)m_DispHandle == 0xFFFF )
        goto LABEL_6;
      v7 = m_DispHandle;
      v8 = EditDispMgr();
      v9 = (int)v8->GetDisp(this: v8, a2: v7);
      if ( CCoreDispInfo::SurfToBaseFacePlane(
             this: (CCoreDispInfo *)(v9 + 24),
             surfPt: vecWorldPoint,
             planePt: vecBasePoint) != 0 )
        return 1;
      this = v12;
      m_Size = nFaceCount;
    }
LABEL_6:
    if ( ++v4 >= m_Size )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101368F0
// Name: private: void CMapOverlay::Basis_UpdateOrigin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Basis_UpdateOrigin(CMapOverlay *this)
{
  CMapClass *v2; // eax
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  Vector vecEntityOrigin; // [esp+4h] [ebp-18h] BYREF
  Vector vecPoint; // [esp+10h] [ebp-Ch] BYREF

  v2 = this->GetParent(this);
  if ( v2 != nullptr )
  {
    v2->GetOrigin(this: v2, a2: &vecEntityOrigin);
    memset(&vecPoint, 0, sizeof(vecPoint));
    if ( CMapOverlay::EntityOnSurfFromListToBaseFacePlane(
           this,
           vecWorldPoint: &vecEntityOrigin,
           vecBasePoint: &vecPoint) != 0 )
    {
      z = vecPoint.z;
      y = vecPoint.y;
      x = vecPoint.x;
    }
    else
    {
      x = vecEntityOrigin.x;
      y = vecEntityOrigin.y;
      z = vecEntityOrigin.z;
    }
    this->m_Basis.m_vecOrigin.x = x;
    this->m_Basis.m_vecOrigin.y = y;
    this->m_Basis.m_vecOrigin.z = z;
  }
  CMapOverlay::Basis_UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x10136980
// Name: private: void CMapOverlay::ClipFace_PreClipDisp(struct CMapOverlay::ClipFace_t __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::ClipFace_PreClipDisp(
        CMapOverlay *this,
        CMapOverlay::ClipFace_t *pClipFace,
        CMapDisp *pDisp)
{
  int v3; // ebx
  int v4; // edi
  float x; // xmm0_4
  float y; // xmm0_4
  int v7; // edi
  int v8; // ebx
  Vector *m_pMemory; // edx
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  Vector2D vecVertsUV[3]; // [esp+4h] [ebp-44h] BYREF
  int iTris[3]; // [esp+1Ch] [ebp-2Ch] BYREF
  float flCoefs[4]; // [esp+28h] [ebp-20h] BYREF
  float v17; // [esp+38h] [ebp-10h]
  Vector2D vecDispUV; // [esp+3Ch] [ebp-Ch] BYREF
  CMapOverlay *v19; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  v19 = this;
  if ( pClipFace != nullptr && pDisp != nullptr )
  {
    v3 = 0;
    if ( pClipFace->m_nPointCount > 0 )
    {
      v4 = 0;
      do
      {
        CCoreDispInfo::BaseFacePlaneToDispUV(
          this: &pDisp->m_CoreDispInfo,
          planePt: &pClipFace->m_aPoints.m_Memory.m_pMemory[v4],
          dispUV: &vecDispUV);
        x = vecDispUV.x;
        if ( vecDispUV.x >= 0.0 )
        {
          if ( vecDispUV.x > 1.0 )
            x = 1.0;
        }
        else
        {
          x = 0.0;
        }
        pClipFace->m_aDispPointUVs.m_Memory.m_pMemory[v4].x = x;
        y = vecDispUV.y;
        if ( vecDispUV.y >= 0.0 )
        {
          if ( vecDispUV.y > 1.0 )
            y = 1.0;
        }
        else
        {
          y = 0.0;
        }
        pClipFace->m_aDispPointUVs.m_Memory.m_pMemory[v4].y = y;
        pClipFace->m_aDispPointUVs.m_Memory.m_pMemory[v4].z = 0.0;
        ++v3;
        ++v4;
      }
      while ( v3 < pClipFace->m_nPointCount );
    }
    v7 = 0;
    if ( pClipFace->m_nPointCount > 0 )
    {
      v8 = 0;
      do
      {
        m_pMemory = pClipFace->m_aDispPointUVs.m_Memory.m_pMemory;
        v11 = m_pMemory[v8].y;
        vecDispUV.x = m_pMemory[v8].x;
        v10 = vecDispUV.x;
        vecDispUV.y = v11;
        CMapOverlay::GetTriVerts(this: v19, pDisp, vecSurfUV: &vecDispUV, pTris: iTris, pVertsUV: vecVertsUV);
        v12 = (float)((1 << pDisp->m_CoreDispInfo.m_Power) + 1) - 1.000001;
        flCoefs[0] = (float)((float)((float)((float)(vecVertsUV[2].x - (float)(v12 * v10))
                                           * (float)(vecVertsUV[1].y - (float)(v12 * v11)))
                                   - (float)((float)(vecVertsUV[1].x - (float)(v12 * v10))
                                           * (float)(vecVertsUV[2].y - (float)(v12 * v11))))
                           * 0.5)
                   * 2.0;
        v13 = (float)(v12 * v10) - vecVertsUV[0].x;
        v17 = vecVertsUV[2].y - vecVertsUV[0].y;
        flCoefs[1] = (float)((float)((float)((float)(vecVertsUV[2].x - vecVertsUV[0].x)
                                           * (float)((float)(v12 * v11) - vecVertsUV[0].y))
                                   - (float)(v13 * (float)(vecVertsUV[2].y - vecVertsUV[0].y)))
                           * 0.5)
                   * 2.0;
        flCoefs[2] = (float)((float)((float)(v13 * (float)(vecVertsUV[1].y - vecVertsUV[0].y))
                                   - (float)((float)((float)(v12 * v11) - vecVertsUV[0].y)
                                           * (float)(vecVertsUV[1].x - vecVertsUV[0].x)))
                           * 0.5)
                   * 2.0;
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(1.0 - (float)((float)(flCoefs[1] + flCoefs[0]) + flCoefs[2])) & _mask__AbsFloat_) < 0.0000099999997 )
          CMapOverlay::ClipFace_ResolveBarycentricClip(
            this: v19,
            a2: (int)&savedregs,
            pDisp,
            pClipFace,
            iClipFacePoint: v7,
            vecPointUV: &vecDispUV,
            pCoefs: flCoefs,
            pTris: iTris,
            pVertsUV: vecVertsUV);
        ++v7;
        ++v8;
      }
      while ( v7 < pClipFace->m_nPointCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136C90
// Name: public: void CMapOverlay::Basis_Init(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Basis_Init(CMapOverlay *this, CMapFace *pFace)
{
  if ( pFace != nullptr )
  {
    this->m_Basis.m_pFace = pFace;
    CMapOverlay::Basis_UpdateOrigin(this);
    CMapOverlay::Basis_BuildAxes(this);
    CMapOverlay::Material_TexCoordInit(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136CC0
// Name: public: CMapOverlay::CMapOverlay(void)
// Source: json
//------------------------------------------------------------------------------
CMapOverlay *__thiscall CMapOverlay::CMapOverlay(CMapOverlay *this)
{
  CMapOverlay::ClipFace_t **m_pMemory; // ecx
  IEditorTexture *v3; // edx

  CMapSideList::CMapSideList(this, pszKeyName: "sides");
  this->__vftable = (CMapOverlay_vtbl *)&CMapOverlay::`vftable';
  this->m_aRenderFaces.m_Memory.m_pMemory = nullptr;
  this->m_aRenderFaces.m_Memory.m_nAllocationCount = 0;
  this->m_aRenderFaces.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_aRenderFaces.m_Memory.m_pMemory;
  this->m_aRenderFaces.m_Size = 0;
  this->m_aRenderFaces.m_pElements = m_pMemory;
  this->m_Basis.m_pFace = nullptr;
  this->m_Basis.m_vecOrigin.x = 0.0;
  this->m_Basis.m_vecOrigin.y = 0.0;
  this->m_Basis.m_vecOrigin.z = 0.0;
  this->m_Basis.m_vecAxes[0].x = -99999.898;
  this->m_Basis.m_vecAxes[0].y = -99999.898;
  this->m_Basis.m_vecAxes[0].z = -99999.898;
  this->m_Basis.m_nAxesFlip[0] = 0;
  this->m_Basis.m_vecAxes[1].x = -99999.898;
  this->m_Basis.m_vecAxes[1].y = -99999.898;
  this->m_Basis.m_vecAxes[1].z = -99999.898;
  this->m_Basis.m_nAxesFlip[1] = 0;
  this->m_Basis.m_vecAxes[2].x = -99999.898;
  this->m_Basis.m_vecAxes[2].y = -99999.898;
  this->m_Basis.m_vecAxes[2].z = -99999.898;
  this->m_Basis.m_nAxesFlip[2] = 0;
  CMapOverlay::Handles_Clear(this);
  this->m_Material.m_pTexture = v3;
  this->m_Material.m_vecTextureU.x = 0.0;
  this->m_Material.m_vecTextureU.y = 1.0;
  this->m_Material.m_vecTextureV.x = 0.0;
  this->m_Material.m_vecTextureV.y = 1.0;
  this->m_bLoaded = (char)v3;
  this->m_pOverlayFace = (CMapOverlay::ClipFace_t *)v3;
  this->m_uiFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10136E00
// Name: public: virtual char const __near * CMapOverlay::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapOverlay::GetDescription(CMapOverlay *this)
{
  return "Overlay";
}

//------------------------------------------------------------------------------
// Address: 0x10136E10
// Name: public: virtual class CMapClass __near * CMapOverlay::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapOverlay *__thiscall CMapOverlay::Copy(CMapOverlay *this, BOOL bUpdateDependencies)
{
  CMapOverlay *v3; // eax
  CMapOverlay *v4; // esi

  v3 = (CMapOverlay *)operator new(nSize: 0x214u);
  if ( v3 != nullptr )
    v4 = CMapOverlay::CMapOverlay(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10136E90
// Name: public: CMapOverlay::ClipFace_t::ClipFace_t(void)
// Source: json
//------------------------------------------------------------------------------
CMapOverlay::ClipFace_t *__thiscall CMapOverlay::ClipFace_t::ClipFace_t(CMapOverlay::ClipFace_t *this)
{
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_aPoints; // eax
  Vector *m_pMemory; // ecx
  Vector *v4; // ecx
  Vector *v5; // ecx
  CMapOverlay::BlendData_t *v6; // ecx

  p_m_aPoints = &this->m_aPoints;
  this->m_aPoints.m_Memory.m_pMemory = nullptr;
  this->m_aPoints.m_Memory.m_nAllocationCount = 0;
  this->m_aPoints.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_aPoints.m_Memory.m_pMemory;
  p_m_aPoints->m_Size = 0;
  p_m_aPoints->m_pElements = m_pMemory;
  this->m_aDispPointUVs.m_Memory.m_pMemory = nullptr;
  this->m_aDispPointUVs.m_Memory.m_nAllocationCount = 0;
  this->m_aDispPointUVs.m_Memory.m_nGrowSize = 0;
  v4 = this->m_aDispPointUVs.m_Memory.m_pMemory;
  this->m_aDispPointUVs.m_Size = 0;
  this->m_aDispPointUVs.m_pElements = v4;
  this->m_aNormals.m_Memory.m_pMemory = nullptr;
  this->m_aNormals.m_Memory.m_nAllocationCount = 0;
  this->m_aNormals.m_Memory.m_nGrowSize = 0;
  v5 = this->m_aNormals.m_Memory.m_pMemory;
  this->m_aNormals.m_Size = 0;
  this->m_aNormals.m_pElements = v5;
  `eh vector constructor iterator'(
    ptr: this->m_aTexCoords,
    size: 0x14u,
    count: 2,
    pCtor: (void (__thiscall *)(void *))CUtlVector<char,CUtlMemory<char,int>>::`default constructor closure',
    pDtor: (void (__thiscall *)(void *))CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>);
  this->m_aBlends.m_Memory.m_pMemory = nullptr;
  this->m_aBlends.m_Memory.m_nAllocationCount = 0;
  this->m_aBlends.m_Memory.m_nGrowSize = 0;
  v6 = this->m_aBlends.m_Memory.m_pMemory;
  this->m_aBlends.m_Size = 0;
  this->m_aBlends.m_pElements = v6;
  this->m_pBuildFace = nullptr;
  this->m_nPointCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10136F70
// Name: public: CMapOverlay::ClipFace_t::~ClipFace_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::ClipFace_t::~ClipFace_t(CMapOverlay::ClipFace_t *this)
{
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_aPoints; // edi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_aDispPointUVs; // edi
  CUtlVector<CMapOverlay::BlendData_t,CUtlMemory<CMapOverlay::BlendData_t,int> > *p_m_aBlends; // ecx
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_aNormals; // edi
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *m_aTexCoords; // esi
  CUtlVector<CMapOverlay::BlendData_t,CUtlMemory<CMapOverlay::BlendData_t,int> > *v7; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v8; // [esp+10h] [ebp-20h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v9; // [esp+14h] [ebp-1Ch]
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *ptr; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  CUtlVector<CMapOverlay::BlendData_t,CUtlMemory<CMapOverlay::BlendData_t,int> > *v12; // [esp+20h] [ebp-10h]

  p_m_aPoints = &this->m_aPoints;
  v8 = &this->m_aPoints;
  this->m_aPoints.m_Size = 0;
  if ( this->m_aPoints.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aPoints->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aPoints->m_Memory.m_pMemory);
      p_m_aPoints->m_Memory.m_pMemory = nullptr;
    }
    p_m_aPoints->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aPoints->m_pElements = p_m_aPoints->m_Memory.m_pMemory;
  p_m_aDispPointUVs = &this->m_aDispPointUVs;
  v9 = &this->m_aDispPointUVs;
  this->m_aDispPointUVs.m_Size = 0;
  if ( this->m_aDispPointUVs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aDispPointUVs->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aDispPointUVs->m_Memory.m_pMemory);
      p_m_aDispPointUVs->m_Memory.m_pMemory = nullptr;
    }
    this->m_aDispPointUVs.m_Memory.m_nAllocationCount = 0;
  }
  p_m_aBlends = &this->m_aBlends;
  this->m_aDispPointUVs.m_pElements = this->m_aDispPointUVs.m_Memory.m_pMemory;
  v12 = &this->m_aBlends;
  this->m_aBlends.m_Size = 0;
  if ( this->m_aBlends.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aBlends->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aBlends->m_Memory.m_pMemory);
      v12->m_Memory.m_pMemory = nullptr;
      p_m_aBlends = &this->m_aBlends;
    }
    p_m_aBlends->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aNormals = &this->m_aNormals;
  p_m_aBlends->m_pElements = p_m_aBlends->m_Memory.m_pMemory;
  this->m_aNormals.m_Size = 0;
  if ( this->m_aNormals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aNormals->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aNormals->m_Memory.m_pMemory);
      p_m_aBlends = &this->m_aBlends;
      p_m_aNormals->m_Memory.m_pMemory = nullptr;
    }
    this->m_aNormals.m_Memory.m_nAllocationCount = 0;
  }
  m_aTexCoords = this->m_aTexCoords;
  p_m_aNormals->m_pElements = p_m_aNormals->m_Memory.m_pMemory;
  ptr = m_aTexCoords;
  for ( i = 2; i != 0; --i )
  {
    m_aTexCoords->m_Size = 0;
    if ( m_aTexCoords->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_aTexCoords->m_Memory.m_pMemory != nullptr )
      {
        free(pMem: m_aTexCoords->m_Memory.m_pMemory);
        p_m_aBlends = v12;
        m_aTexCoords->m_Memory.m_pMemory = nullptr;
      }
      m_aTexCoords->m_Memory.m_nAllocationCount = 0;
    }
    m_aTexCoords->m_pElements = m_aTexCoords->m_Memory.m_pMemory;
    ++m_aTexCoords;
  }
  v7 = p_m_aBlends;
  p_m_aBlends->m_Size = 0;
  if ( p_m_aBlends->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aBlends->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aBlends->m_Memory.m_pMemory);
      v7->m_Memory.m_pMemory = nullptr;
    }
    v7->m_Memory.m_nAllocationCount = 0;
  }
  v7->m_pElements = v7->m_Memory.m_pMemory;
  if ( v7->m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: v7->m_Memory.m_pMemory);
      v7->m_Memory.m_pMemory = nullptr;
    }
    v7->m_Memory.m_nAllocationCount = 0;
  }
  `eh vector destructor iterator'(
    ptr,
    size: 0x14u,
    count: 2,
    pDtor: (void (__thiscall *)(void *))CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>);
  p_m_aNormals->m_Size = 0;
  if ( p_m_aNormals->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aNormals->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aNormals->m_Memory.m_pMemory);
      p_m_aNormals->m_Memory.m_pMemory = nullptr;
    }
    p_m_aNormals->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aNormals->m_pElements = p_m_aNormals->m_Memory.m_pMemory;
  if ( p_m_aNormals->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aNormals->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aNormals->m_Memory.m_pMemory);
      p_m_aNormals->m_Memory.m_pMemory = nullptr;
    }
    p_m_aNormals->m_Memory.m_nAllocationCount = 0;
  }
  v9->m_Size = 0;
  if ( v9->m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: v9->m_Memory.m_pMemory);
      v9->m_Memory.m_pMemory = nullptr;
    }
    v9->m_Memory.m_nAllocationCount = 0;
  }
  v9->m_pElements = v9->m_Memory.m_pMemory;
  if ( v9->m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: v9->m_Memory.m_pMemory);
      v9->m_Memory.m_pMemory = nullptr;
    }
    v9->m_Memory.m_nAllocationCount = 0;
  }
  v8->m_Size = 0;
  if ( v8->m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: v8->m_Memory.m_pMemory);
      v8->m_Memory.m_pMemory = nullptr;
    }
    v8->m_Memory.m_nAllocationCount = 0;
  }
  v8->m_pElements = v8->m_Memory.m_pMemory;
  if ( v8->m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: v8->m_Memory.m_pMemory);
      v8->m_Memory.m_pMemory = nullptr;
    }
    v8->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101371E0
// Name: public: static class CMapClass __near * CMapOverlay::CreateMapOverlay(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapOverlay *__cdecl CMapOverlay::CreateMapOverlay()
{
  CMapOverlay *v0; // eax

  v0 = (CMapOverlay *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return CMapOverlay::CMapOverlay(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101372B0
// Name: public: virtual CMapOverlay::~CMapOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::~CMapOverlay(CMapOverlay *this)
{
  CMapOverlay::ClipFace_t *m_pOverlayFace; // esi
  CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int> > *p_m_aRenderFaces; // esi

  this->__vftable = (CMapOverlay_vtbl *)&CMapOverlay::`vftable';
  m_pOverlayFace = this->m_pOverlayFace;
  if ( m_pOverlayFace != nullptr )
  {
    CMapOverlay::ClipFace_t::~ClipFace_t(this: this->m_pOverlayFace);
    operator delete(p: m_pOverlayFace);
    this->m_pOverlayFace = nullptr;
  }
  p_m_aRenderFaces = &this->m_aRenderFaces;
  CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int>>::PurgeAndDeleteElements(this: &this->m_aRenderFaces);
  this->m_aRenderFaces.m_Size = 0;
  if ( this->m_aRenderFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aRenderFaces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aRenderFaces->m_Memory.m_pMemory);
      p_m_aRenderFaces->m_Memory.m_pMemory = nullptr;
    }
    this->m_aRenderFaces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aRenderFaces.m_pElements = this->m_aRenderFaces.m_Memory.m_pMemory;
  if ( this->m_aRenderFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aRenderFaces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aRenderFaces->m_Memory.m_pMemory);
      p_m_aRenderFaces->m_Memory.m_pMemory = nullptr;
    }
    this->m_aRenderFaces.m_Memory.m_nAllocationCount = 0;
  }
  CMapSideList::~CMapSideList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10137380
// Name: private: void CMapOverlay::OverlayPlaneToSurfFromList(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::OverlayPlaneToSurfFromList(
        CMapOverlay *this,
        const Vector *vecOverlayPoint,
        Vector *vecSurfPoint)
{
  Vector *v4; // eax
  int m_Size; // edi
  cplane_t *v6; // edx
  int v7; // ecx
  CMapFace *v8; // edi
  int v9; // edx
  float *p_z; // ecx
  unsigned int v11; // ebx
  float y; // xmm6_4
  char *v13; // eax
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  int v19; // eax
  float *v20; // ecx
  float *p_x; // eax
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm2_4
  float v27; // xmm5_4
  float v28; // xmm7_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  int m_DispHandle; // edi
  CEditDispMgr *v35; // eax
  CCoreDispInfo *p_m_CoreDispInfo; // edi
  Vector *m_pMemory; // esi
  int m_nGrowSize; // edi
  cplane_t *v39; // eax
  int nPoints; // [esp-4h] [ebp-6Ch]
  int v41; // [esp-4h] [ebp-6Ch]
  Vector vec; // [esp+Ch] [ebp-5Ch] BYREF
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > aPlanes; // [esp+20h] [ebp-48h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > aPoints; // [esp+34h] [ebp-34h] BYREF
  Vector2D dispUV; // [esp+48h] [ebp-20h] BYREF
  float z; // [esp+50h] [ebp-18h]
  float x; // [esp+54h] [ebp-14h]
  int iFace; // [esp+58h] [ebp-10h]
  int v49; // [esp+64h] [ebp-4h]
  float vecOverlayPointa; // [esp+70h] [ebp+8h]

  *vecSurfPoint = *vecOverlayPoint;
  v4 = nullptr;
  m_Size = this->m_Faces.m_Size;
  memset(&aPoints, 0, sizeof(aPoints));
  LODWORD(dispUV.y) = m_Size;
  v49 = 3;
  v6 = nullptr;
  memset(&aPlanes, 0, sizeof(aPlanes));
  v7 = 0;
  *(float *)&iFace = 0.0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = this->m_Faces.m_Memory.m_pMemory[v7];
      if ( v8 != nullptr )
      {
        aPoints.m_Size = 0;
        if ( aPoints.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4 != nullptr )
          {
            free(pMem: v4);
            aPoints.m_Memory.m_pMemory = nullptr;
            v4 = nullptr;
          }
          aPoints.m_Memory.m_nAllocationCount = 0;
        }
        aPoints.m_pElements = v4;
        nPoints = v8->nPoints;
        aPoints.m_Size = 0;
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(this: &aPoints, elem: 0, num: nPoints);
        aPlanes.m_Size = 0;
        if ( aPlanes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( aPlanes.m_Memory.m_pMemory != nullptr )
          {
            free(pMem: aPlanes.m_Memory.m_pMemory);
            aPlanes.m_Memory.m_pMemory = nullptr;
          }
          aPlanes.m_Memory.m_nAllocationCount = 0;
        }
        aPlanes.m_pElements = aPlanes.m_Memory.m_pMemory;
        v41 = v8->nPoints;
        aPlanes.m_Size = 0;
        CUtlVector<cplane_t,CUtlMemory<cplane_t,int>>::InsertMultipleBefore(this: &aPlanes, elem: 0, num: v41);
        v9 = 0;
        if ( v8->nPoints > 0 )
        {
          p_z = &aPoints.m_Memory.m_pMemory->z;
          v11 = -8 - (unsigned int)aPoints.m_Memory.m_pMemory;
          do
          {
            y = this->m_Basis.m_vecAxes[2].y;
            v13 = (char *)v8->Points + v11;
            v14 = *(float *)((char *)p_z + (_DWORD)v13);
            v15 = *(float *)((char *)p_z + (_DWORD)v13 + 4);
            v16 = *(float *)((char *)p_z + (_DWORD)v13 + 8);
            x = this->m_Basis.m_vecAxes[2].x;
            z = this->m_Basis.m_vecAxes[2].z;
            v17 = (float)((float)((float)(v15 - this->m_Basis.m_vecOrigin.y) * y)
                        + (float)((float)(v14 - this->m_Basis.m_vecOrigin.x) * x))
                + (float)((float)(v16 - this->m_Basis.m_vecOrigin.z) * z);
            v18 = v16 - (float)(z * v17);
            *(p_z - 2) = v14 - (float)(x * v17);
            *(p_z - 1) = v15 - (float)(y * v17);
            *p_z = v18;
            ++v9;
            p_z += 3;
          }
          while ( v9 < v8->nPoints );
        }
        CMapOverlay::BuildEdgePlanes(
          this,
          pPoints: aPoints.m_Memory.m_pMemory,
          nPointCount: aPoints.m_Size,
          pEdgePlanes: aPlanes.m_Memory.m_pMemory,
          nEdgePlaneCount: aPlanes.m_Size);
        v19 = 0;
        if ( aPlanes.m_Size > 0 )
        {
          v20 = &aPlanes.m_Memory.m_pMemory->normal.z;
          do
          {
            if ( (float)((float)((float)((float)(*(v20 - 1) * vecOverlayPoint->y)
                                       + (float)(*(v20 - 2) * vecOverlayPoint->x))
                               + (float)(vecOverlayPoint->z * *v20))
                       - v20[1]) >= 0.0 )
              break;
            ++v19;
            v20 += 5;
          }
          while ( v19 < aPlanes.m_Size );
        }
        if ( v19 == aPlanes.m_Size )
        {
          vec = v8->plane.normal;
          VectorNormalize(&vec);
          p_x = &v8->Points->x;
          v22 = *p_x;
          v23 = p_x[1];
          v24 = p_x[2];
          v25 = vecOverlayPoint->x;
          iFace = SLODWORD(vecOverlayPoint->z);
          v26 = (float)((float)(v22 * vec.x) + (float)(v23 * vec.y)) + (float)(v24 * vec.z);
          v27 = vecOverlayPoint->y;
          vecOverlayPointa = this->m_Basis.m_vecAxes[2].y;
          v28 = this->m_Basis.m_vecAxes[2].x;
          v29 = this->m_Basis.m_vecAxes[2].z;
          v30 = (float)((float)(vec.y * vecOverlayPointa) + (float)(vec.x * v28)) + (float)(vec.z * v29);
          v31 = (float)((float)((float)(v27 * vec.y) + (float)(v25 * vec.x)) + (float)(*(float *)&iFace * vec.z)) - v26;
          v32 = v31;
          if ( v30 != 0.0 )
            v32 = (float)(1.0 / v30) * v31;
          v33 = *(float *)&iFace - (float)(v32 * v29);
          vecSurfPoint->x = v25 - (float)(v32 * v28);
          vecSurfPoint->y = v27 - (float)(v32 * vecOverlayPointa);
          vecSurfPoint->z = v33;
          if ( v8->m_DispHandle != 0xFFFF )
          {
            m_DispHandle = v8->m_DispHandle;
            v35 = EditDispMgr();
            p_m_CoreDispInfo = &v35->GetDisp(this: v35, a2: m_DispHandle)->m_CoreDispInfo;
            CCoreDispInfo::BaseFacePlaneToDispUV(this: p_m_CoreDispInfo, planePt: vecSurfPoint, &dispUV);
            CCoreDispInfo::DispUVToSurf(
              this: p_m_CoreDispInfo,
              &dispUV,
              vecPoint: vecSurfPoint,
              pNormal: nullptr,
              pAlpha: nullptr);
          }
          m_pMemory = aPoints.m_Memory.m_pMemory;
          aPoints.m_Size = 0;
          if ( aPoints.m_Memory.m_nGrowSize >= 0 )
          {
            if ( aPoints.m_Memory.m_pMemory != nullptr )
            {
              free(pMem: aPoints.m_Memory.m_pMemory);
              aPoints.m_Memory.m_pMemory = nullptr;
              m_pMemory = nullptr;
            }
            aPoints.m_Memory.m_nAllocationCount = 0;
          }
          m_nGrowSize = aPlanes.m_Memory.m_nGrowSize;
          v39 = aPlanes.m_Memory.m_pMemory;
          aPoints.m_pElements = m_pMemory;
          aPlanes.m_Size = 0;
          if ( aPlanes.m_Memory.m_nGrowSize >= 0 )
          {
            if ( aPlanes.m_Memory.m_pMemory != nullptr )
            {
              free(pMem: aPlanes.m_Memory.m_pMemory);
              aPlanes.m_Memory.m_pMemory = nullptr;
              v39 = nullptr;
            }
            aPlanes.m_Memory.m_nAllocationCount = 0;
          }
          aPlanes.m_pElements = v39;
          LOBYTE(v49) = 4;
          aPlanes.m_Size = 0;
          if ( m_nGrowSize >= 0 )
          {
            if ( v39 != nullptr )
            {
              free(pMem: v39);
              aPlanes.m_Memory.m_pMemory = nullptr;
              v39 = nullptr;
            }
            aPlanes.m_Memory.m_nAllocationCount = 0;
          }
          aPlanes.m_pElements = v39;
          LOBYTE(v49) = 1;
          if ( m_nGrowSize >= 0 )
          {
            if ( v39 != nullptr )
            {
              free(pMem: v39);
              aPlanes.m_Memory.m_pMemory = nullptr;
            }
            aPlanes.m_Memory.m_nAllocationCount = 0;
          }
          v49 = 5;
          aPoints.m_Size = 0;
          if ( aPoints.m_Memory.m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              free(pMem: m_pMemory);
              aPoints.m_Memory.m_pMemory = nullptr;
              m_pMemory = nullptr;
            }
            aPoints.m_Memory.m_nAllocationCount = 0;
          }
          aPoints.m_pElements = m_pMemory;
          v49 = -1;
          if ( aPoints.m_Memory.m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              free(pMem: m_pMemory);
LABEL_44:
              aPoints.m_Memory.m_pMemory = nullptr;
            }
            goto LABEL_45;
          }
          return;
        }
        v6 = aPlanes.m_Memory.m_pMemory;
        v7 = iFace;
        v4 = aPoints.m_Memory.m_pMemory;
      }
      iFace = ++v7;
    }
    while ( v7 < SLODWORD(dispUV.y) );
  }
  aPoints.m_Size = 0;
  if ( aPoints.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      free(pMem: v4);
      v6 = aPlanes.m_Memory.m_pMemory;
      aPoints.m_Memory.m_pMemory = nullptr;
      v4 = nullptr;
    }
    aPoints.m_Memory.m_nAllocationCount = 0;
  }
  aPoints.m_pElements = v4;
  aPlanes.m_Size = 0;
  if ( aPlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      free(pMem: v6);
      v4 = aPoints.m_Memory.m_pMemory;
      aPlanes.m_Memory.m_pMemory = nullptr;
      v6 = nullptr;
    }
    aPlanes.m_Memory.m_nAllocationCount = 0;
  }
  aPlanes.m_pElements = v6;
  LOBYTE(v49) = 6;
  aPlanes.m_Size = 0;
  if ( aPlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      free(pMem: v6);
      v4 = aPoints.m_Memory.m_pMemory;
      aPlanes.m_Memory.m_pMemory = nullptr;
      v6 = nullptr;
    }
    aPlanes.m_Memory.m_nAllocationCount = 0;
  }
  aPlanes.m_pElements = v6;
  LOBYTE(v49) = 1;
  if ( aPlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      free(pMem: v6);
      v4 = aPoints.m_Memory.m_pMemory;
      aPlanes.m_Memory.m_pMemory = nullptr;
    }
    aPlanes.m_Memory.m_nAllocationCount = 0;
  }
  v49 = 7;
  aPoints.m_Size = 0;
  if ( aPoints.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      free(pMem: v4);
      aPoints.m_Memory.m_pMemory = nullptr;
      v4 = nullptr;
    }
    aPoints.m_Memory.m_nAllocationCount = 0;
  }
  aPoints.m_pElements = v4;
  v49 = -1;
  if ( aPoints.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      free(pMem: v4);
      goto LABEL_44;
    }
LABEL_45:
    aPoints.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137900
// Name: private: void CMapOverlay::Handles_Build3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Handles_Build3D(CMapOverlay *this)
{
  int v2; // ebx
  Vector *m_vecAxes; // edi
  int v4; // ecx
  float *p_x; // edx
  Vector *m_vec3D; // ebx
  Vector2D *m_vecBasisCoords; // edi
  float y; // xmm0_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  Vector vecHandle; // [esp+0h] [ebp-10h] BYREF
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  m_vecAxes = this->m_Basis.m_vecAxes;
LABEL_2:
  v4 = 0;
  p_x = &m_vecAxes->x;
  while ( *p_x != -99999.898 )
  {
    ++v4;
    ++p_x;
    if ( v4 >= 3 )
    {
      ++v2;
      ++m_vecAxes;
      if ( v2 < 3 )
        goto LABEL_2;
      m_vec3D = this->m_Handles.m_vec3D;
      m_vecBasisCoords = this->m_Handles.m_vecBasisCoords;
      for ( i = 4; i != 0; --i )
      {
        y = m_vecBasisCoords->y;
        v9 = this->m_Basis.m_vecAxes[1].y * y;
        v10 = this->m_Basis.m_vecAxes[1].z * y;
        v11 = this->m_Basis.m_vecOrigin.x
            + (float)((float)(this->m_Basis.m_vecAxes[0].x * m_vecBasisCoords->x)
                    + (float)(this->m_Basis.m_vecAxes[1].x * y));
        v12 = m_vecBasisCoords->x * this->m_Basis.m_vecAxes[0].z;
        vecHandle.y = this->m_Basis.m_vecOrigin.y
                    + (float)((float)(m_vecBasisCoords->x * this->m_Basis.m_vecAxes[0].y) + v9);
        v13 = this->m_Basis.m_vecOrigin.z + (float)(v12 + v10);
        vecHandle.x = v11;
        vecHandle.z = v13;
        CMapOverlay::OverlayPlaneToSurfFromList(this, vecOverlayPoint: &vecHandle, vecSurfPoint: m_vec3D);
        ++m_vecBasisCoords;
        ++m_vec3D;
      }
      CMapOverlay::Handles_FixOrder(this);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137A20
// Name: private: struct CMapOverlay::ClipFace_t __near * CMapOverlay::ClipFace_Create(int)
// Source: json
//------------------------------------------------------------------------------
CMapOverlay::ClipFace_t *__thiscall CMapOverlay::ClipFace_Create(CMapOverlay *this, int nSize)
{
  CMapOverlay::ClipFace_t *v2; // eax
  CMapOverlay::ClipFace_t *v3; // edi
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *m_aTexCoords; // esi
  int v6; // edx
  int v7; // ecx
  Vector *m_pMemory; // eax
  Vector *v9; // eax
  Vector *v10; // eax
  CMapOverlay::BlendData_t *v11; // eax
  Vector2D *v12; // eax
  int v13; // edi
  Vector2D *v14; // eax
  CMapOverlay::ClipFace_t *v16; // [esp+Ch] [ebp-10h]
  int nSizea; // [esp+24h] [ebp+8h]
  int nSizeb; // [esp+24h] [ebp+8h]

  v2 = (CMapOverlay::ClipFace_t *)operator new(nSize: 0x80u);
  if ( v2 != nullptr )
  {
    v3 = CMapOverlay::ClipFace_t::ClipFace_t(this: v2);
    v16 = v3;
  }
  else
  {
    v16 = nullptr;
    v3 = nullptr;
  }
  if ( v3 == nullptr )
    return nullptr;
  v3->m_nPointCount = nSize;
  if ( nSize <= 0 )
    return v3;
  v3->m_aPoints.m_Size = 0;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(this: &v3->m_aPoints, elem: 0, num: nSize);
  v3->m_aNormals.m_Size = 0;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(this: &v3->m_aNormals, elem: 0, num: nSize);
  v3->m_aDispPointUVs.m_Size = 0;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(this: &v3->m_aDispPointUVs, elem: 0, num: nSize);
  m_aTexCoords = v3->m_aTexCoords;
  for ( nSizea = 2; nSizea != 0; --nSizea )
  {
    m_aTexCoords->m_Size = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(this: m_aTexCoords++, elem: 0, num: nSize);
  }
  v3->m_aBlends.m_Size = 0;
  CUtlVector<CMapOverlay::BlendData_t,CUtlMemory<CMapOverlay::BlendData_t,int>>::InsertMultipleBefore(
    this: &v3->m_aBlends,
    elem: 0,
    num: nSize);
  v6 = 0;
  if ( nSize <= 0 )
    return v3;
  nSizeb = 0;
  v7 = 0;
  while ( 1 )
  {
    m_pMemory = v3->m_aPoints.m_Memory.m_pMemory;
    m_pMemory[v7].x = 0.0;
    m_pMemory[v7].y = 0.0;
    m_pMemory[v7].z = 0.0;
    v9 = v3->m_aNormals.m_Memory.m_pMemory;
    v9[v7].x = 0.0;
    v9[v7].y = 0.0;
    v9[v7].z = 1.0;
    v10 = v3->m_aDispPointUVs.m_Memory.m_pMemory;
    v10[v7].x = 0.0;
    v10[v7].y = 0.0;
    v10[v7].z = 0.0;
    v11 = &v3->m_aBlends.m_Memory.m_pMemory[nSizeb++];
    v11->m_nType = 0;
    *(_DWORD *)v11->m_iPoints = 0;
    v11->m_iPoints[2] = 0;
    *(_QWORD *)v11->m_flBlends = 0;
    v11->m_flBlends[2] = 0.0;
    v12 = v16->m_aTexCoords[0].m_Memory.m_pMemory;
    v13 = v6;
    v12[v13].x = 0.0;
    v12[v13].y = 0.0;
    v14 = v16->m_aTexCoords[1].m_Memory.m_pMemory;
    ++v6;
    ++v7;
    v14[v13].x = 0.0;
    v14[v13].y = 0.0;
    if ( v6 >= nSize )
      break;
    v3 = v16;
  }
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x10137BE0
// Name: private: struct CMapOverlay::ClipFace_t __near * CMapOverlay::ClipFace_Copy(struct CMapOverlay::ClipFace_t __near *)
// Source: json
//------------------------------------------------------------------------------
CMapOverlay::ClipFace_t *__thiscall CMapOverlay::ClipFace_Copy(CMapOverlay *this, CMapOverlay::ClipFace_t *pSrc)
{
  CMapOverlay::ClipFace_t *result; // eax
  int v4; // ebx
  int v5; // ecx
  Vector *m_pMemory; // edx
  Vector *v7; // edi
  Vector *v8; // edx
  Vector *v9; // edi
  Vector *v10; // edx
  Vector *v11; // edi
  double z; // st7
  int v13; // edx
  Vector2D *v14; // ebx
  Vector2D *v15; // edi
  double y; // st7
  Vector2D *v17; // edi
  Vector2D *v18; // ebx
  int v19; // edx
  CMapOverlay::BlendData_t *v20; // edi
  CMapOverlay::BlendData_t *v21; // edi
  double v22; // st7
  int iPoint; // [esp+8h] [ebp-10h]
  int v24; // [esp+Ch] [ebp-Ch]
  int v25; // [esp+10h] [ebp-8h]
  unsigned int pSrca; // [esp+20h] [ebp+8h]

  result = CMapOverlay::ClipFace_Create(this, nSize: pSrc->m_nPointCount);
  v4 = 0;
  if ( result != nullptr )
  {
    iPoint = 0;
    if ( pSrc->m_nPointCount > 0 )
    {
      v5 = 0;
      v25 = 0;
      pSrca = 16;
      v24 = 6;
      do
      {
        m_pMemory = pSrc->m_aPoints.m_Memory.m_pMemory;
        v7 = result->m_aPoints.m_Memory.m_pMemory;
        v7[v5].x = m_pMemory[v5].x;
        ++v5;
        v7[v5 - 1].y = m_pMemory[v5 - 1].y;
        v7[v5 - 1].z = m_pMemory[v5 - 1].z;
        v8 = pSrc->m_aNormals.m_Memory.m_pMemory;
        v9 = result->m_aNormals.m_Memory.m_pMemory;
        v9[v5 - 1].x = v8[v5 - 1].x;
        v9[v5 - 1].y = v8[v5 - 1].y;
        v9[v5 - 1].z = v8[v5 - 1].z;
        v10 = pSrc->m_aDispPointUVs.m_Memory.m_pMemory;
        v11 = result->m_aDispPointUVs.m_Memory.m_pMemory;
        v11[v5 - 1].x = v10[v5 - 1].x;
        v11[v5 - 1].y = v10[v5 - 1].y;
        z = v10[v5 - 1].z;
        v13 = v4;
        v14 = result->m_aTexCoords[0].m_Memory.m_pMemory;
        v11[v5 - 1].z = z;
        v15 = pSrc->m_aTexCoords[0].m_Memory.m_pMemory;
        v14[v13].x = v15[v13].x;
        y = v15[v13].y;
        v17 = pSrc->m_aTexCoords[1].m_Memory.m_pMemory;
        v14[v13].y = y;
        v18 = result->m_aTexCoords[1].m_Memory.m_pMemory;
        v18[v13].x = v17[v13].x;
        v18[v13].y = v17[v13].y;
        result->m_aBlends.m_Memory.m_pMemory[v25].m_nType = pSrc->m_aBlends.m_Memory.m_pMemory[v25].m_nType;
        v19 = v24;
        *(_WORD *)((char *)result->m_aBlends.m_Memory.m_pMemory + v24 - 2) = *(_WORD *)((char *)pSrc->m_aBlends.m_Memory.m_pMemory
                                                                                      + v24
                                                                                      - 2);
        v20 = result->m_aBlends.m_Memory.m_pMemory;
        *(float *)((char *)v20 + pSrca - 4) = *(float *)((char *)pSrc->m_aBlends.m_Memory.m_pMemory + pSrca - 4);
        *(_WORD *)((char *)&v20->m_nType + v24) = *(_WORD *)((char *)&pSrc->m_aBlends.m_Memory.m_pMemory->m_nType + v24);
        ++v25;
        v24 += 24;
        v21 = result->m_aBlends.m_Memory.m_pMemory;
        *(int *)((char *)&v21->m_nType + pSrca) = *(int *)((char *)&pSrc->m_aBlends.m_Memory.m_pMemory->m_nType + pSrca);
        *(_WORD *)((char *)&v21->m_nType + v19 + 2) = *(_WORD *)((char *)&pSrc->m_aBlends.m_Memory.m_pMemory->m_nType
                                                               + v19
                                                               + 2);
        v22 = *(float *)&pSrc->m_aBlends.m_Memory.m_pMemory->m_iPoints[pSrca / 2];
        pSrca += 24;
        *(float *)((char *)result->m_aBlends.m_Memory.m_pMemory + pSrca - 20) = v22;
        v4 = iPoint + 1;
        iPoint = v4;
      }
      while ( v4 < pSrc->m_nPointCount );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10137D40
// Name: private: void CMapOverlay::ClipFace_Clip(struct CMapOverlay::ClipFace_t __near *,struct cplane_t __near *,float,struct CMapOverlay::ClipFace_t __near * __near *,struct CMapOverlay::ClipFace_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::ClipFace_Clip(
        CMapOverlay *this,
        CMapOverlay::ClipFace_t *pClipFace,
        cplane_t *pClipPlane,
        float flEpsilon,
        CMapOverlay::ClipFace_t **ppFront,
        CMapOverlay::ClipFace_t **ppBack)
{
  int m_nPointCount; // edx
  int v9; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float dist; // xmm5_4
  Vector *m_pMemory; // esi
  float v15; // xmm0_4
  float v16; // xmm0_4
  CMapOverlay::ClipFace_t *v17; // esi
  CMapOverlay::ClipFace_t *v18; // eax
  float *v19; // ecx
  CMapOverlay::ClipFace_t *v20; // edi
  int v21; // eax
  Vector *v22; // edx
  float *p_x; // edx
  float *v24; // eax
  Vector *v25; // edx
  float *v26; // edx
  float *v27; // eax
  double v28; // st7
  Vector2D *v29; // eax
  Vector2D *v30; // edx
  float *v31; // eax
  Vector2D *v32; // edx
  double v33; // st7
  Vector2D *v34; // edx
  float *v35; // eax
  Vector2D *v36; // edx
  Vector *v37; // edx
  float *v38; // edx
  float *v39; // eax
  Vector *v40; // edx
  float *v41; // edx
  float *v42; // eax
  double v43; // st7
  Vector2D *v44; // eax
  Vector2D *v45; // edx
  float *v46; // eax
  Vector2D *v47; // edx
  double v48; // st7
  Vector2D *v49; // edx
  float *v50; // eax
  Vector2D *v51; // edx
  Vector *v52; // edx
  float *v53; // edx
  Vector2D *v54; // eax
  Vector *v55; // edx
  float *v56; // edx
  Vector2D *v57; // eax
  double v58; // st7
  Vector2D *v59; // eax
  Vector2D *v60; // edx
  float *v61; // edx
  double v62; // st7
  Vector2D *v63; // eax
  Vector2D *v64; // edx
  float *v65; // edx
  float *v66; // edx
  Vector2D *v67; // eax
  float *v68; // edx
  Vector2D *v69; // eax
  double v70; // st7
  Vector2D *v71; // eax
  int v72; // edx
  float *v73; // edx
  double v74; // st7
  Vector2D *v75; // eax
  int v76; // edx
  float *v77; // edx
  int v78; // eax
  int v79; // edx
  Vector *v80; // eax
  float v81; // xmm4_4
  float v82; // xmm4_4
  float v83; // xmm3_4
  float v84; // xmm1_4
  Vector *v85; // eax
  float v86; // xmm2_4
  float v87; // xmm1_4
  float v88; // xmm3_4
  float v89; // xmm0_4
  int v90; // edx
  Vector2D *v91; // ecx
  float v92; // xmm3_4
  float v93; // xmm1_4
  float v94; // xmm2_4
  float v95; // xmm0_4
  float *v96; // eax
  float v97; // xmm0_4
  float *v98; // eax
  int v99; // edx
  Vector2D *v100; // eax
  float v101; // xmm2_4
  int v102; // ecx
  float v103; // xmm0_4
  float v104; // xmm1_4
  Vector2D *v105; // edx
  int v106; // eax
  Vector2D *v107; // ecx
  float v108; // xmm0_4
  float v109; // xmm2_4
  int v110; // edx
  Vector *v111; // eax
  Vector *v112; // edx
  int v113; // eax
  float flDists[128]; // [esp+8h] [ebp-424h]
  int nSides[128]; // [esp+208h] [ebp-224h]
  float fraction; // [esp+408h] [ebp-24h]
  Vector vecPoint; // [esp+40Ch] [ebp-20h]
  Vector vecNormal; // [esp+418h] [ebp-14h] BYREF
  float *v119; // [esp+424h] [ebp-8h]
  Vector2D *v120; // [esp+428h] [ebp-4h]
  CMapOverlay::ClipFace_t *pClipFacea; // [esp+434h] [ebp+8h]
  cplane_t *pClipPlanea; // [esp+438h] [ebp+Ch]
  int flEpsilona; // [esp+43Ch] [ebp+10h]

  if ( pClipFace != nullptr )
  {
    *ppBack = nullptr;
    *ppFront = nullptr;
    m_nPointCount = pClipFace->m_nPointCount;
    v9 = 0;
    memset(&vecNormal, 0, sizeof(vecNormal));
    if ( m_nPointCount > 0 )
    {
      y = pClipPlane->normal.y;
      x = pClipPlane->normal.x;
      z = pClipPlane->normal.z;
      dist = pClipPlane->dist;
      m_pMemory = pClipFace->m_aPoints.m_Memory.m_pMemory;
      do
      {
        v15 = (float)((float)((float)(m_pMemory->y * y) + (float)(m_pMemory->x * x)) + (float)(m_pMemory->z * z)) - dist;
        flDists[v9] = v15;
        if ( v15 <= flEpsilon )
        {
          if ( (float)-flEpsilon <= v15 )
            nSides[v9] = 2;
          else
            nSides[v9] = 1;
        }
        else
        {
          nSides[v9] = 0;
        }
        ++*((_DWORD *)&vecNormal.x + nSides[v9++]);
        ++m_pMemory;
      }
      while ( v9 < m_nPointCount );
    }
    v16 = flDists[0];
    nSides[v9] = nSides[0];
    flDists[v9] = v16;
    if ( LODWORD(vecNormal.x) != 0 )
    {
      if ( LODWORD(vecNormal.y) != 0 )
      {
        v17 = CMapOverlay::ClipFace_Create(this, nSize: m_nPointCount + 2);
        v18 = CMapOverlay::ClipFace_Create(this, nSize: pClipFace->m_nPointCount + 2);
        v19 = nullptr;
        v20 = v18;
        if ( v17 != nullptr )
        {
          if ( v18 != nullptr )
          {
            v17->m_nPointCount = 0;
            v18->m_nPointCount = 0;
            if ( pClipFace->m_nPointCount > 0 )
            {
              pClipFacea = nullptr;
              flEpsilona = 1;
              v119 = nullptr;
              pClipPlanea = nullptr;
              do
              {
                v21 = *(int *)((char *)nSides + (_DWORD)pClipPlanea);
                if ( v21 == 2 )
                {
                  v22 = v17->m_aPoints.m_Memory.m_pMemory;
                  v119 = (float *)((char *)v19 + (unsigned int)pClipFace->m_aPoints.m_Memory.m_pMemory);
                  p_x = &v22[v17->m_nPointCount].x;
                  v24 = v119;
                  *p_x = *v119;
                  p_x[1] = v24[1];
                  p_x[2] = v24[2];
                  v25 = v17->m_aNormals.m_Memory.m_pMemory;
                  v119 = (float *)((char *)v19 + (unsigned int)pClipFace->m_aNormals.m_Memory.m_pMemory);
                  v26 = &v25[v17->m_nPointCount].x;
                  v27 = v119;
                  *v26 = *v119;
                  v26[1] = v27[1];
                  v28 = v27[2];
                  v29 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[0].m_Memory.m_pMemory);
                  v26[2] = v28;
                  v30 = v17->m_aTexCoords[0].m_Memory.m_pMemory;
                  v120 = v29;
                  v31 = &v30[v17->m_nPointCount].x;
                  v32 = v120;
                  *v31 = v120->x;
                  v33 = v32->y;
                  v34 = v17->m_aTexCoords[1].m_Memory.m_pMemory;
                  v31[1] = v33;
                  v120 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[1].m_Memory.m_pMemory);
                  v35 = &v34[v17->m_nPointCount].x;
                  v36 = v120;
                  *v35 = v120->x;
                  v35[1] = v36->y;
                  ++v17->m_nPointCount;
                  v37 = v20->m_aPoints.m_Memory.m_pMemory;
                  v119 = (float *)((char *)v19 + (unsigned int)pClipFace->m_aPoints.m_Memory.m_pMemory);
                  v38 = &v37[v20->m_nPointCount].x;
                  v39 = v119;
                  *v38 = *v119;
                  v38[1] = v39[1];
                  v38[2] = v39[2];
                  v40 = v20->m_aNormals.m_Memory.m_pMemory;
                  v119 = (float *)((char *)v19 + (unsigned int)pClipFace->m_aNormals.m_Memory.m_pMemory);
                  v41 = &v40[v20->m_nPointCount].x;
                  v42 = v119;
                  *v41 = *v119;
                  v41[1] = v42[1];
                  v43 = v42[2];
                  v44 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[0].m_Memory.m_pMemory);
                  v41[2] = v43;
                  v45 = v20->m_aTexCoords[0].m_Memory.m_pMemory;
                  v120 = v44;
                  v46 = &v45[v20->m_nPointCount].x;
                  v47 = v120;
                  *v46 = v120->x;
                  v48 = v47->y;
                  v49 = v20->m_aTexCoords[1].m_Memory.m_pMemory;
                  v46[1] = v48;
                  v120 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[1].m_Memory.m_pMemory);
                  v50 = &v49[v20->m_nPointCount].x;
                  v51 = v120;
                  *v50 = v120->x;
                  v50[1] = v51->y;
                  ++v20->m_nPointCount;
                }
                else
                {
                  if ( v21 == 1 )
                  {
                    v52 = v20->m_aPoints.m_Memory.m_pMemory;
                    v120 = (Vector2D *)((char *)v19 + (unsigned int)pClipFace->m_aPoints.m_Memory.m_pMemory);
                    v53 = &v52[v20->m_nPointCount].x;
                    v54 = v120;
                    *v53 = v120->x;
                    v53[1] = v54->y;
                    v53[2] = v54[1].x;
                    v55 = v20->m_aNormals.m_Memory.m_pMemory;
                    v120 = (Vector2D *)((char *)v19 + (unsigned int)pClipFace->m_aNormals.m_Memory.m_pMemory);
                    v56 = &v55[v20->m_nPointCount].x;
                    v57 = v120;
                    *v56 = v120->x;
                    v56[1] = v57->y;
                    v58 = v57[1].x;
                    v59 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[0].m_Memory.m_pMemory);
                    v56[2] = v58;
                    v60 = v20->m_aTexCoords[0].m_Memory.m_pMemory;
                    v120 = v59;
                    v61 = &v60[v20->m_nPointCount].x;
                    *v61 = v59->x;
                    v62 = v59->y;
                    v63 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[1].m_Memory.m_pMemory);
                    v61[1] = v62;
                    v64 = v20->m_aTexCoords[1].m_Memory.m_pMemory;
                    v120 = v63;
                    v65 = &v64[v20->m_nPointCount].x;
                    *v65 = v63->x;
                    v65[1] = v63->y;
                    ++v20->m_nPointCount;
                  }
                  if ( *(int *)((char *)nSides + (_DWORD)pClipPlanea) == 0 )
                  {
                    v120 = (Vector2D *)((char *)v19 + (unsigned int)pClipFace->m_aPoints.m_Memory.m_pMemory);
                    v66 = &v17->m_aPoints.m_Memory.m_pMemory[v17->m_nPointCount].x;
                    v67 = v120;
                    *v66 = v120->x;
                    v66[1] = v67->y;
                    v66[2] = v67[1].x;
                    v120 = (Vector2D *)((char *)v19 + (unsigned int)pClipFace->m_aNormals.m_Memory.m_pMemory);
                    v68 = &v17->m_aNormals.m_Memory.m_pMemory[v17->m_nPointCount].x;
                    v69 = v120;
                    *v68 = v120->x;
                    v68[1] = v69->y;
                    v70 = v69[1].x;
                    v71 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[0].m_Memory.m_pMemory);
                    v68[2] = v70;
                    v72 = v17->m_nPointCount;
                    v120 = v71;
                    v73 = &v17->m_aTexCoords[0].m_Memory.m_pMemory[v72].x;
                    *v73 = v71->x;
                    v74 = v71->y;
                    v75 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[1].m_Memory.m_pMemory);
                    v73[1] = v74;
                    v76 = v17->m_nPointCount;
                    v120 = v75;
                    v77 = &v17->m_aTexCoords[1].m_Memory.m_pMemory[v76].x;
                    *v77 = v75->x;
                    v77[1] = v75->y;
                    ++v17->m_nPointCount;
                  }
                  v78 = *(int *)((char *)&nSides[1] + (_DWORD)pClipPlanea);
                  if ( v78 != 2 && v78 != *(int *)((char *)nSides + (_DWORD)pClipPlanea) )
                  {
                    v79 = flEpsilona % pClipFace->m_nPointCount;
                    v80 = pClipFace->m_aPoints.m_Memory.m_pMemory;
                    v81 = *(float *)((char *)v19 + (_DWORD)v80);
                    fraction = *(float *)((char *)flDists + (_DWORD)pClipPlanea)
                             / (float)(*(float *)((char *)flDists + (_DWORD)pClipPlanea)
                                     - *(float *)((char *)&flDists[1] + (_DWORD)pClipPlanea));
                    v79 *= 12;
                    v82 = v81
                        + (float)((float)(*(float *)((char *)&v80->x + v79) - *(float *)((char *)v19 + (_DWORD)v80))
                                * fraction);
                    v83 = (float)(*(float *)((char *)&v80->z + v79) - *(float *)((char *)v19 + (_DWORD)v80 + 8))
                        * fraction;
                    vecPoint.y = *(float *)((char *)v19 + (_DWORD)v80 + 4)
                               + (float)((float)(*(float *)((char *)&v80->y + v79)
                                               - *(float *)((char *)v19 + (_DWORD)v80 + 4))
                                       * fraction);
                    v84 = *(float *)((char *)v19 + (_DWORD)v80 + 8);
                    v85 = pClipFace->m_aNormals.m_Memory.m_pMemory;
                    v86 = *(float *)((char *)&v85->y + v79) - *(float *)((char *)v19 + (_DWORD)v85 + 4);
                    v87 = v84 + v83;
                    v88 = *(float *)((char *)&v85->z + v79) - *(float *)((char *)v19 + (_DWORD)v85 + 8);
                    vecPoint.z = v87;
                    vecNormal.x = (float)((float)(*(float *)((char *)&v85->x + v79)
                                                - *(float *)((char *)v19 + (_DWORD)v85))
                                        * fraction)
                                + *(float *)((char *)v19 + (_DWORD)v85);
                    vecNormal.y = *(float *)((char *)v19 + (_DWORD)v85 + 4) + (float)(v86 * fraction);
                    v89 = *(float *)((char *)v19 + (_DWORD)v85 + 8) + (float)(v88 * fraction);
                    vecPoint.x = v82;
                    vecNormal.z = v89;
                    VectorNormalize(vec: &vecNormal);
                    v90 = flEpsilona % pClipFace->m_nPointCount;
                    v91 = pClipFace->m_aTexCoords[0].m_Memory.m_pMemory;
                    v92 = fraction;
                    v93 = v91[v90].y - *(float *)((char *)&pClipFacea->m_nPointCount + (_DWORD)v91);
                    v94 = *(float *)((char *)&pClipFacea->m_pBuildFace + (_DWORD)v91)
                        + (float)((float)(v91[v90].x - *(float *)((char *)&pClipFacea->m_pBuildFace + (_DWORD)v91))
                                * fraction);
                    v95 = *(float *)((char *)&pClipFacea->m_nPointCount + (_DWORD)v91);
                    v96 = &v17->m_aTexCoords[0].m_Memory.m_pMemory[v17->m_nPointCount].x;
                    *v96 = v94;
                    v97 = v95 + (float)(v93 * v92);
                    v96[1] = v97;
                    v98 = &v20->m_aTexCoords[0].m_Memory.m_pMemory[v20->m_nPointCount].x;
                    *v98 = v94;
                    v98[1] = v97;
                    v99 = flEpsilona % pClipFace->m_nPointCount;
                    v100 = pClipFace->m_aTexCoords[1].m_Memory.m_pMemory;
                    v101 = *(float *)((char *)&v100->x + (_DWORD)pClipFacea)
                         + (float)((float)(v100[v99].x - *(float *)((char *)&v100->x + (_DWORD)pClipFacea)) * v92);
                    v102 = v17->m_nPointCount;
                    v103 = *(float *)((char *)&v100->y + (_DWORD)pClipFacea)
                         + (float)((float)(v100[v99].y - *(float *)((char *)&v100->y + (_DWORD)pClipFacea)) * v92);
                    v104 = vecPoint.y;
                    v105 = v17->m_aTexCoords[1].m_Memory.m_pMemory;
                    v105[v102].x = v101;
                    v105[v102].y = v103;
                    v106 = v20->m_nPointCount;
                    v107 = v20->m_aTexCoords[1].m_Memory.m_pMemory;
                    v107[v106].x = v101;
                    v107[v106].y = v103;
                    v108 = vecPoint.x;
                    v109 = vecPoint.z;
                    v110 = v17->m_nPointCount;
                    v111 = v17->m_aPoints.m_Memory.m_pMemory;
                    v111[v110].x = vecPoint.x;
                    v111[v110].y = v104;
                    v111[v110].z = v109;
                    v17->m_aNormals.m_Memory.m_pMemory[v17->m_nPointCount++] = vecNormal;
                    v112 = v20->m_aPoints.m_Memory.m_pMemory;
                    v113 = v20->m_nPointCount;
                    v112[v113].x = v108;
                    v112[v113].y = v104;
                    v112[v113].z = v109;
                    v20->m_aNormals.m_Memory.m_pMemory[v20->m_nPointCount++] = vecNormal;
                    v19 = v119;
                  }
                }
                pClipPlanea = (cplane_t *)((char *)pClipPlanea + 4);
                pClipFacea = (CMapOverlay::ClipFace_t *)((char *)pClipFacea + 8);
                ++flEpsilona;
                v19 += 3;
                v119 = v19;
              }
              while ( flEpsilona - 1 < pClipFace->m_nPointCount );
            }
            *ppFront = v17;
            *ppBack = v20;
          }
          else
          {
            CMapOverlay::ClipFace_t::~ClipFace_t(this: v17);
            operator delete(p: v17);
          }
        }
        else if ( v18 != nullptr )
        {
          CMapOverlay::ClipFace_t::~ClipFace_t(this: v18);
          operator delete(p: v20);
        }
      }
      else
      {
        *ppFront = CMapOverlay::ClipFace_Copy(this, pSrc: pClipFace);
      }
    }
    else
    {
      *ppBack = CMapOverlay::ClipFace_Copy(this, pSrc: pClipFace);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138430
// Name: private: void CMapOverlay::ClipFace_ClipBarycentric(struct CMapOverlay::ClipFace_t __near *,struct cplane_t __near *,float,int,class CMapDisp __near *,struct CMapOverlay::ClipFace_t __near * __near *,struct CMapOverlay::ClipFace_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::ClipFace_ClipBarycentric(
        CMapOverlay *this,
        CMapOverlay::ClipFace_t *pClipFace,
        cplane_t *pClipPlane,
        float flEpsilon,
        __int16 iClip,
        CMapDisp *pDisp,
        CMapOverlay::ClipFace_t **ppFront,
        CMapOverlay::ClipFace_t **ppBack)
{
  int m_nPointCount; // edx
  int v10; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float dist; // xmm5_4
  Vector *m_pMemory; // esi
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // edx
  int v19; // esi
  CMapOverlay::ClipFace_t *v20; // edi
  CMapOverlay::ClipFace_t *v21; // esi
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  Vector *v25; // edx
  float *p_x; // eax
  int v27; // edx
  Vector *v28; // edx
  float *v29; // eax
  int v30; // edx
  Vector *v31; // eax
  double v32; // st7
  Vector *v33; // edx
  float *v34; // eax
  int v35; // ecx
  Vector *v36; // ecx
  Vector2D *v37; // edx
  double v38; // st7
  Vector2D *v39; // eax
  float *v40; // ecx
  Vector2D *v41; // edx
  double v42; // st7
  Vector2D *v43; // eax
  float *v44; // ecx
  float *v45; // eax
  Vector *v46; // edx
  int v47; // ecx
  Vector *v48; // ecx
  float *v49; // eax
  int v50; // ecx
  Vector *v51; // edx
  Vector *v52; // ecx
  float *v53; // eax
  Vector *v54; // edx
  int v55; // ecx
  Vector *v56; // ecx
  Vector2D *v57; // edx
  double v58; // st7
  Vector2D *v59; // eax
  float *v60; // ecx
  Vector2D *v61; // edx
  double v62; // st7
  Vector2D *v63; // eax
  float *v64; // ecx
  int v65; // ecx
  CMapOverlay::BlendData_t *v66; // edx
  int v67; // ecx
  int v68; // ecx
  float *v69; // eax
  int v70; // edx
  float *v71; // eax
  int v72; // edx
  Vector *v73; // eax
  double v74; // st7
  Vector *v75; // edx
  float *v76; // eax
  int v77; // ecx
  Vector *v78; // ecx
  Vector2D *v79; // edx
  double v80; // st7
  Vector2D *v81; // eax
  float *v82; // ecx
  Vector2D *v83; // edx
  double v84; // st7
  Vector2D *v85; // eax
  float *v86; // ecx
  float *v87; // edx
  int v88; // eax
  float *v89; // edx
  int v90; // eax
  Vector *v91; // eax
  double v92; // st7
  Vector *v93; // edx
  float *v94; // eax
  int v95; // ecx
  Vector *v96; // ecx
  Vector2D *v97; // edx
  double v98; // st7
  Vector2D *v99; // eax
  float *v100; // ecx
  Vector2D *v101; // edx
  double v102; // st7
  Vector2D *v103; // eax
  float *v104; // ecx
  int v105; // ecx
  CMapOverlay::BlendData_t *v106; // edx
  int v107; // ecx
  int v108; // ecx
  int v109; // edx
  float v110; // xmm0_4
  float v111; // xmm1_4
  int v112; // edx
  Vector *v113; // eax
  float v114; // xmm4_4
  float v115; // xmm2_4
  float v116; // xmm3_4
  float v117; // xmm1_4
  Vector *v118; // eax
  float v119; // xmm2_4
  float v120; // xmm3_4
  Vector *v121; // ecx
  float v122; // xmm1_4
  float v123; // xmm2_4
  Vector *v124; // eax
  float v125; // xmm1_4
  float v126; // xmm0_4
  const Vector2D *v127; // eax
  int *v128; // eax
  int v129; // edx
  Vector *v130; // ecx
  int v131; // eax
  Vector *v132; // eax
  float v133; // xmm5_4
  float v134; // xmm6_4
  float v135; // xmm7_4
  float *v136; // eax
  float *v137; // eax
  float flDists[128]; // [esp+8h] [ebp-454h]
  int nSides[128]; // [esp+208h] [ebp-254h]
  float fraction; // [esp+408h] [ebp-54h]
  int v141; // [esp+40Ch] [ebp-50h]
  int nMaxPointCount; // [esp+410h] [ebp-4Ch]
  Vector2D vecTexCoord; // [esp+414h] [ebp-48h] BYREF
  Vector2D vecUV; // [esp+41Ch] [ebp-40h] BYREF
  Vector vecNormal; // [esp+424h] [ebp-38h] BYREF
  Vector vecPoint; // [esp+430h] [ebp-2Ch] BYREF
  Vector vecDispPointUV; // [esp+43Ch] [ebp-20h] BYREF
  int v148; // [esp+448h] [ebp-14h]
  int v149; // [esp+44Ch] [ebp-10h]
  unsigned int v150; // [esp+450h] [ebp-Ch]
  CMapOverlay *v151; // [esp+454h] [ebp-8h]
  int v152; // [esp+458h] [ebp-4h]
  CMapOverlay::ClipFace_t *pClipFacea; // [esp+464h] [ebp+8h]
  int flEpsilona; // [esp+46Ch] [ebp+10h]

  v151 = this;
  if ( pClipFace != nullptr )
  {
    m_nPointCount = pClipFace->m_nPointCount;
    v10 = 0;
    memset(&vecDispPointUV, 0, sizeof(vecDispPointUV));
    if ( m_nPointCount > 0 )
    {
      y = pClipPlane->normal.y;
      x = pClipPlane->normal.x;
      z = pClipPlane->normal.z;
      dist = pClipPlane->dist;
      m_pMemory = pClipFace->m_aDispPointUVs.m_Memory.m_pMemory;
      do
      {
        v16 = (float)((float)((float)(m_pMemory->y * y) + (float)(m_pMemory->x * x)) + (float)(m_pMemory->z * z)) - dist;
        flDists[v10] = v16;
        if ( v16 <= flEpsilon )
        {
          if ( (float)-flEpsilon <= v16 )
            nSides[v10] = 2;
          else
            nSides[v10] = 1;
        }
        else
        {
          nSides[v10] = 0;
        }
        ++*((_DWORD *)&vecDispPointUV.x + nSides[v10++]);
        ++m_pMemory;
      }
      while ( v10 < m_nPointCount );
    }
    v17 = flDists[0];
    nSides[v10] = nSides[0];
    flDists[v10] = v17;
    if ( LODWORD(vecDispPointUV.x) == 0 )
    {
      *ppBack = CMapOverlay::ClipFace_Copy(this, pSrc: pClipFace);
      return;
    }
    if ( LODWORD(vecDispPointUV.y) == 0 )
    {
      *ppFront = CMapOverlay::ClipFace_Copy(this, pSrc: pClipFace);
      return;
    }
    v18 = m_nPointCount + 1;
    v19 = v18 + 2;
    nMaxPointCount = v18;
    v20 = CMapOverlay::ClipFace_Create(this, nSize: v18 + 2);
    v21 = CMapOverlay::ClipFace_Create(this: v151, nSize: v19);
    v22 = 0;
    if ( v20 != nullptr )
    {
      if ( v21 != nullptr )
      {
        v20->m_nPointCount = 0;
        v21->m_nPointCount = 0;
        if ( pClipFace->m_nPointCount > 0 )
        {
          v23 = 0;
          flEpsilona = 0;
          v148 = 1;
          v150 = 0;
          pClipFacea = nullptr;
          v149 = 0;
          do
          {
            v24 = *(int *)((char *)nSides + v22);
            if ( v24 == 2 )
            {
              v25 = v20->m_aPoints.m_Memory.m_pMemory;
              v152 = (int)pClipFace->m_aPoints.m_Memory.m_pMemory + v23;
              p_x = &v25[v20->m_nPointCount].x;
              v27 = v152;
              *p_x = *(float *)v152;
              p_x[1] = *(float *)(v27 + 4);
              p_x[2] = *(float *)(v27 + 8);
              v28 = v20->m_aNormals.m_Memory.m_pMemory;
              v152 = (int)pClipFace->m_aNormals.m_Memory.m_pMemory + v23;
              v29 = &v28[v20->m_nPointCount].x;
              v30 = v152;
              *v29 = *(float *)v152;
              v29[1] = *(float *)(v30 + 4);
              v29[2] = *(float *)(v30 + 8);
              v31 = pClipFace->m_aDispPointUVs.m_Memory.m_pMemory;
              v32 = *(float *)((char *)&v31->x + v23);
              v33 = v20->m_aDispPointUVs.m_Memory.m_pMemory;
              v34 = (float *)((char *)&v31->x + v23);
              v35 = v20->m_nPointCount;
              v33[v35].x = v32;
              v36 = &v33[v35];
              v37 = v20->m_aTexCoords[0].m_Memory.m_pMemory;
              v36->y = v34[1];
              v38 = v34[2];
              v39 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[0].m_Memory.m_pMemory);
              v36->z = v38;
              v40 = &v37[v20->m_nPointCount].x;
              v41 = v20->m_aTexCoords[1].m_Memory.m_pMemory;
              *v40 = v39->x;
              v42 = v39->y;
              v43 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[1].m_Memory.m_pMemory);
              v40[1] = v42;
              v44 = &v41[v20->m_nPointCount].x;
              *v44 = v43->x;
              v44[1] = v43->y;
              CMapOverlay::ClipFace_CopyBlendFrom(
                this: v151,
                pClipFace: v20,
                pBlendFrom: &pClipFace->m_aBlends.m_Memory.m_pMemory[v150 / 0x18]);
              ++v20->m_nPointCount;
              v45 = (float *)((char *)&pClipFace->m_aPoints.m_Memory.m_pMemory->x + flEpsilona);
              v46 = v21->m_aPoints.m_Memory.m_pMemory;
              v47 = v21->m_nPointCount;
              v46[v47].x = *v45;
              v48 = &v46[v47];
              v48->y = v45[1];
              v48->z = v45[2];
              v49 = (float *)((char *)&pClipFace->m_aNormals.m_Memory.m_pMemory->x + flEpsilona);
              v50 = v21->m_nPointCount;
              v51 = v21->m_aNormals.m_Memory.m_pMemory;
              v51[v50].x = *v49;
              v52 = &v51[v50];
              v52->y = v49[1];
              v52->z = v49[2];
              v53 = (float *)((char *)&pClipFace->m_aDispPointUVs.m_Memory.m_pMemory->x + flEpsilona);
              v54 = v21->m_aDispPointUVs.m_Memory.m_pMemory;
              v55 = v21->m_nPointCount;
              v54[v55].x = *v53;
              v56 = &v54[v55];
              v57 = v21->m_aTexCoords[0].m_Memory.m_pMemory;
              v56->y = v53[1];
              v58 = v53[2];
              v59 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[0].m_Memory.m_pMemory);
              v56->z = v58;
              v60 = &v57[v21->m_nPointCount].x;
              *v60 = v59->x;
              v61 = v21->m_aTexCoords[1].m_Memory.m_pMemory;
              v62 = v59->y;
              v63 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[1].m_Memory.m_pMemory);
              v60[1] = v62;
              v64 = &v61[v21->m_nPointCount].x;
              *v64 = v63->x;
              v64[1] = v63->y;
              v65 = v21->m_nPointCount;
              v66 = v21->m_aBlends.m_Memory.m_pMemory;
              v152 = (int)&pClipFace->m_aBlends.m_Memory.m_pMemory[v150 / 0x18];
              v66[v65].m_nType = *(_DWORD *)v152;
              v21->m_aBlends.m_Memory.m_pMemory[v21->m_nPointCount].m_iPoints[0] = *(_WORD *)(v152 + 4);
              v67 = v152;
              v21->m_aBlends.m_Memory.m_pMemory[v21->m_nPointCount].m_flBlends[0] = *(float *)(v152 + 12);
              v21->m_aBlends.m_Memory.m_pMemory[v21->m_nPointCount].m_iPoints[1] = *(_WORD *)(v67 + 6);
              v68 = v152;
              v21->m_aBlends.m_Memory.m_pMemory[v21->m_nPointCount].m_flBlends[1] = *(float *)(v152 + 16);
              v21->m_aBlends.m_Memory.m_pMemory[v21->m_nPointCount].m_iPoints[2] = *(_WORD *)(v68 + 8);
              v21->m_aBlends.m_Memory.m_pMemory[v21->m_nPointCount].m_flBlends[2] = *(float *)(v152 + 20);
            }
            else
            {
              if ( v24 == 1 )
              {
                v152 = (int)pClipFace->m_aPoints.m_Memory.m_pMemory + v23;
                v69 = &v21->m_aPoints.m_Memory.m_pMemory[v21->m_nPointCount].x;
                v70 = v152;
                *v69 = *(float *)v152;
                v69[1] = *(float *)(v70 + 4);
                v69[2] = *(float *)(v70 + 8);
                v152 = (int)pClipFace->m_aNormals.m_Memory.m_pMemory + v23;
                v71 = &v21->m_aNormals.m_Memory.m_pMemory[v21->m_nPointCount].x;
                v72 = v152;
                *v71 = *(float *)v152;
                v71[1] = *(float *)(v72 + 4);
                v71[2] = *(float *)(v72 + 8);
                v73 = pClipFace->m_aDispPointUVs.m_Memory.m_pMemory;
                v74 = *(float *)((char *)&v73->x + v23);
                v75 = v21->m_aDispPointUVs.m_Memory.m_pMemory;
                v76 = (float *)((char *)&v73->x + v23);
                v77 = v21->m_nPointCount;
                v75[v77].x = v74;
                v78 = &v75[v77];
                v79 = v21->m_aTexCoords[0].m_Memory.m_pMemory;
                v78->y = v76[1];
                v80 = v76[2];
                v81 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[0].m_Memory.m_pMemory);
                v78->z = v80;
                v82 = &v79[v21->m_nPointCount].x;
                v83 = v21->m_aTexCoords[1].m_Memory.m_pMemory;
                *v82 = v81->x;
                v84 = v81->y;
                v85 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[1].m_Memory.m_pMemory);
                v82[1] = v84;
                v86 = &v83[v21->m_nPointCount].x;
                *v86 = v85->x;
                v86[1] = v85->y;
                CMapOverlay::ClipFace_CopyBlendFrom(
                  this: v151,
                  pClipFace: v21,
                  pBlendFrom: &pClipFace->m_aBlends.m_Memory.m_pMemory[v150 / 0x18]);
                ++v21->m_nPointCount;
                v22 = v149;
                v23 = flEpsilona;
              }
              if ( *(int *)((char *)nSides + v22) == 0 )
              {
                v152 = (int)pClipFace->m_aPoints.m_Memory.m_pMemory + v23;
                v87 = &v20->m_aPoints.m_Memory.m_pMemory[v20->m_nPointCount].x;
                v88 = v152;
                *v87 = *(float *)v152;
                v87[1] = *(float *)(v88 + 4);
                v87[2] = *(float *)(v88 + 8);
                v152 = (int)pClipFace->m_aNormals.m_Memory.m_pMemory + v23;
                v89 = &v20->m_aNormals.m_Memory.m_pMemory[v20->m_nPointCount].x;
                v90 = v152;
                *v89 = *(float *)v152;
                v89[1] = *(float *)(v90 + 4);
                v89[2] = *(float *)(v90 + 8);
                v91 = pClipFace->m_aDispPointUVs.m_Memory.m_pMemory;
                v92 = *(float *)((char *)&v91->x + v23);
                v93 = v20->m_aDispPointUVs.m_Memory.m_pMemory;
                v94 = (float *)((char *)&v91->x + v23);
                v95 = v20->m_nPointCount;
                v93[v95].x = v92;
                v96 = &v93[v95];
                v97 = v20->m_aTexCoords[0].m_Memory.m_pMemory;
                v96->y = v94[1];
                v98 = v94[2];
                v99 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[0].m_Memory.m_pMemory);
                v96->z = v98;
                v100 = &v97[v20->m_nPointCount].x;
                v101 = v20->m_aTexCoords[1].m_Memory.m_pMemory;
                *v100 = v99->x;
                v102 = v99->y;
                v103 = (Vector2D *)((char *)pClipFacea + (unsigned int)pClipFace->m_aTexCoords[1].m_Memory.m_pMemory);
                v100[1] = v102;
                v104 = &v101[v20->m_nPointCount].x;
                *v104 = v103->x;
                v104[1] = v103->y;
                v105 = v20->m_nPointCount;
                v106 = v20->m_aBlends.m_Memory.m_pMemory;
                v152 = (int)&pClipFace->m_aBlends.m_Memory.m_pMemory[v150 / 0x18];
                v106[v105].m_nType = *(_DWORD *)v152;
                v20->m_aBlends.m_Memory.m_pMemory[v20->m_nPointCount].m_iPoints[0] = *(_WORD *)(v152 + 4);
                v107 = v152;
                v20->m_aBlends.m_Memory.m_pMemory[v20->m_nPointCount].m_flBlends[0] = *(float *)(v152 + 12);
                v20->m_aBlends.m_Memory.m_pMemory[v20->m_nPointCount].m_iPoints[1] = *(_WORD *)(v107 + 6);
                v108 = v152;
                v20->m_aBlends.m_Memory.m_pMemory[v20->m_nPointCount].m_flBlends[1] = *(float *)(v152 + 16);
                v20->m_aBlends.m_Memory.m_pMemory[v20->m_nPointCount].m_iPoints[2] = *(_WORD *)(v108 + 8);
                v23 = flEpsilona;
                v20->m_aBlends.m_Memory.m_pMemory[v20->m_nPointCount++].m_flBlends[2] = *(float *)(v152 + 20);
                v22 = v149;
              }
              v109 = *(int *)((char *)&nSides[1] + v22);
              if ( v109 == 2 || v109 == *(int *)((char *)nSides + v22) )
                goto LABEL_38;
              v110 = *(float *)((char *)flDists + v22);
              v111 = v110 - *(float *)((char *)&flDists[1] + v22);
              v112 = v148 % pClipFace->m_nPointCount;
              v113 = pClipFace->m_aPoints.m_Memory.m_pMemory;
              v114 = *(float *)((char *)&v113->x + v23);
              fraction = v110 / v111;
              v112 *= 12;
              v115 = *(float *)((char *)&v113->y + v112) - *(float *)((char *)&v113->y + v23);
              v116 = *(float *)((char *)&v113->z + v112) - *(float *)((char *)&v113->z + v23);
              vecPoint.x = v114
                         + (float)((float)(*(float *)((char *)&v113->x + v112) - *(float *)((char *)&v113->x + v23))
                                 * (float)(v110 / v111));
              vecPoint.y = *(float *)((char *)&v113->y + v23) + (float)(v115 * (float)(v110 / v111));
              v117 = *(float *)((char *)&v113->z + v23);
              v118 = pClipFace->m_aNormals.m_Memory.m_pMemory;
              vecPoint.z = v117 + (float)(v116 * fraction);
              v119 = (float)(*(float *)((char *)&v118->y + v112) - *(float *)((char *)&v118->y + v23)) * fraction;
              v120 = (float)(*(float *)((char *)&v118->z + v112) - *(float *)((char *)&v118->z + v23)) * fraction;
              vecNormal.x = (float)((float)(*(float *)((char *)&v118->x + v112) - *(float *)((char *)&v118->x + v23))
                                  * fraction)
                          + *(float *)((char *)&v118->x + v23);
              vecNormal.y = *(float *)((char *)&v118->y + v23) + v119;
              vecNormal.z = *(float *)((char *)&v118->z + v23) + v120;
              VectorNormalize(vec: &vecNormal);
              v121 = pClipFace->m_aDispPointUVs.m_Memory.m_pMemory;
              v122 = v121[v148 % pClipFace->m_nPointCount].y - *(float *)((char *)&v121->y + flEpsilona);
              v123 = v121[v148 % pClipFace->m_nPointCount].z - *(float *)((char *)&v121->z + flEpsilona);
              vecDispPointUV.x = (float)((float)(v121[v148 % pClipFace->m_nPointCount].x
                                               - *(float *)((char *)&v121->x + flEpsilona))
                                       * fraction)
                               + *(float *)((char *)&v121->x + flEpsilona);
              vecDispPointUV.y = *(float *)((char *)&v121->y + flEpsilona) + (float)(v122 * fraction);
              v124 = v151->m_pOverlayFace->m_aPoints.m_Memory.m_pMemory;
              vecDispPointUV.z = *(float *)((char *)&v121->z + flEpsilona) + (float)(v123 * fraction);
              PointInQuadToBarycentric(v1: v124, v2: v124 + 3, v3: v124 + 2, v4: v124 + 1, point: &vecPoint, uv: &vecUV);
              v125 = vecUV.x;
              v126 = 0.0;
              if ( vecUV.x >= 0.0 )
              {
                if ( vecUV.x > 1.0 )
                  v125 = 1.0;
              }
              else
              {
                v125 = 0.0;
              }
              vecUV.x = v125;
              if ( vecUV.y >= 0.0 )
              {
                if ( vecUV.y <= 1.0 )
                  v126 = vecUV.y;
                else
                  v126 = 1.0;
              }
              vecUV.y = v126;
              v152 = 0;
              v141 = (char *)v20 - (char *)v21;
              do
              {
                v127 = *(Vector2D **)((char *)&v151->m_pOverlayFace->m_aTexCoords[0].m_Memory.m_pMemory + v152);
                TexCoordInQuadFromBarycentric(
                  v1: v127,
                  v2: v127 + 3,
                  v3: v127 + 2,
                  v4: v127 + 1,
                  uv: &vecUV,
                  texCoord: &vecTexCoord);
                v128 = (int *)((char *)v21->m_aTexCoords + v152);
                v129 = *v128;
                *(Vector2D *)(*(int *)((char *)v128 + v141) + 8 * v20->m_nPointCount) = vecTexCoord;
                *(Vector2D *)(v129 + 8 * v21->m_nPointCount) = vecTexCoord;
                v152 += 20;
              }
              while ( v152 < 40 );
              v130 = v20->m_aPoints.m_Memory.m_pMemory;
              v131 = v20->m_nPointCount;
              v130[v131].x = vecPoint.x;
              v132 = &v130[v131];
              v132->y = vecPoint.y;
              v132->z = vecPoint.z;
              v133 = vecDispPointUV.x;
              v134 = vecDispPointUV.y;
              v135 = vecDispPointUV.z;
              v20->m_aNormals.m_Memory.m_pMemory[v20->m_nPointCount] = vecNormal;
              v136 = &v20->m_aDispPointUVs.m_Memory.m_pMemory[v20->m_nPointCount].x;
              *v136 = v133;
              v136[1] = v134;
              v136[2] = v135;
              CMapOverlay::ClipFace_BuildBlend(
                this: v151,
                pClipFace: v20,
                pDisp,
                pClipPlane,
                iClip,
                vecUV: &vecDispPointUV,
                &vecPoint);
              ++v20->m_nPointCount;
              v21->m_aPoints.m_Memory.m_pMemory[v21->m_nPointCount] = vecPoint;
              v21->m_aNormals.m_Memory.m_pMemory[v21->m_nPointCount] = vecNormal;
              v137 = &v21->m_aDispPointUVs.m_Memory.m_pMemory[v21->m_nPointCount].x;
              *v137 = v133;
              v137[1] = v134;
              v137[2] = v135;
              CMapOverlay::ClipFace_BuildBlend(
                this: v151,
                pClipFace: v21,
                pDisp,
                pClipPlane,
                iClip,
                vecUV: &vecDispPointUV,
                &vecPoint);
            }
            v23 = flEpsilona;
            v22 = v149;
            ++v21->m_nPointCount;
LABEL_38:
            pClipFacea = (CMapOverlay::ClipFace_t *)((char *)pClipFacea + 8);
            v150 += 24;
            ++v148;
            v22 += 4;
            v23 += 12;
            v149 = v22;
            flEpsilona = v23;
          }
          while ( v148 - 1 < pClipFace->m_nPointCount );
        }
        if ( v20->m_nPointCount <= nMaxPointCount && v21->m_nPointCount <= nMaxPointCount )
        {
          *ppFront = v20;
          *ppBack = v21;
        }
      }
      else
      {
        CMapOverlay::ClipFace_t::~ClipFace_t(this: v20);
        operator delete(p: v20);
      }
    }
    else if ( v21 != nullptr )
    {
      CMapOverlay::ClipFace_t::~ClipFace_t(this: v21);
      operator delete(p: v21);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138E10
// Name: private: void CMapOverlay::PreClip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::PreClip(CMapOverlay *this)
{
  CMapOverlay::ClipFace_t *v2; // eax
  int i; // ebx
  float x; // xmm2_4
  float y; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  int v10; // edi
  Vector *v11; // eax
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  CEditDispMgr *v17; // eax
  int v18; // eax
  Vector2D *m_pMemory; // eax
  Vector2D *v20; // eax
  Vector2D *v21; // eax
  Vector2D *v22; // eax
  Vector2D vecTmp; // [esp+4h] [ebp-14h] BYREF
  Vector2D vTexCoord; // [esp+Ch] [ebp-Ch]
  int handle; // [esp+14h] [ebp-4h]

  v2 = CMapOverlay::ClipFace_Create(this, nSize: 4);
  this->m_pOverlayFace = v2;
  if ( v2 != nullptr )
  {
    for ( i = 0; i < 4; ++i )
    {
      x = this->m_Basis.m_vecAxes[0].x;
      y = this->m_Basis.m_vecAxes[0].y;
      v6 = this->m_Handles.m_vecBasisCoords[i].y;
      v7 = this->m_Handles.m_vecBasisCoords[i].x;
      v8 = this->m_Basis.m_vecAxes[1].x * v6;
      v9 = v6 * this->m_Basis.m_vecAxes[1].y;
      v10 = i;
      v11 = &this->m_pOverlayFace->m_aPoints.m_Memory.m_pMemory[i];
      v12 = (float)(this->m_Basis.m_vecAxes[0].z * v7) + (float)(v6 * this->m_Basis.m_vecAxes[1].z);
      v11->z = v12;
      v13 = (float)(x * v7) + v8;
      v11->x = v13;
      v14 = v9 + (float)(y * v7);
      v11->y = v14;
      v11->x = this->m_Basis.m_vecOrigin.x + v13;
      v11->y = this->m_Basis.m_vecOrigin.y + v14;
      v11->z = v12 + this->m_Basis.m_vecOrigin.z;
      switch ( i )
      {
        case 0:
          v15 = this->m_Material.m_vecTextureU.x;
          goto LABEL_8;
        case 1:
          v15 = this->m_Material.m_vecTextureU.x;
          v16 = this->m_Material.m_vecTextureV.y;
          goto LABEL_9;
        case 2:
          v15 = this->m_Material.m_vecTextureU.y;
          v16 = this->m_Material.m_vecTextureV.y;
          goto LABEL_9;
        case 3:
          v15 = this->m_Material.m_vecTextureU.y;
LABEL_8:
          v16 = this->m_Material.m_vecTextureV.x;
LABEL_9:
          vTexCoord.y = v16;
          vTexCoord.x = v15;
          break;
        default:
          break;
      }
      this->m_pOverlayFace->m_aTexCoords[0].m_Memory.m_pMemory[i] = vTexCoord;
      if ( this->m_Basis.m_pFace->m_DispHandle != 0xFFFF )
      {
        handle = this->m_Basis.m_pFace->m_DispHandle;
        v17 = EditDispMgr();
        v18 = (int)v17->GetDisp(this: v17, a2: handle);
        if ( v18 != 0 )
        {
          CCoreDispInfo::BaseFacePlaneToDispUV(
            this: (CCoreDispInfo *)(v18 + 24),
            planePt: &this->m_pOverlayFace->m_aPoints.m_Memory.m_pMemory[v10],
            dispUV: &vecTmp);
          *(Vector2D *)&this->m_pOverlayFace->m_aDispPointUVs.m_Memory.m_pMemory[v10].x = vecTmp;
          this->m_pOverlayFace->m_aDispPointUVs.m_Memory.m_pMemory[v10].z = 0.0;
        }
      }
    }
    m_pMemory = this->m_pOverlayFace->m_aTexCoords[1].m_Memory.m_pMemory;
    m_pMemory->x = 0.0;
    m_pMemory->y = 0.0;
    v20 = this->m_pOverlayFace->m_aTexCoords[1].m_Memory.m_pMemory;
    v20[1].x = 0.0;
    v20[1].y = 1.0;
    v21 = this->m_pOverlayFace->m_aTexCoords[1].m_Memory.m_pMemory;
    v21[2].x = 1.0;
    v21[2].y = 1.0;
    v22 = this->m_pOverlayFace->m_aTexCoords[1].m_Memory.m_pMemory;
    v22[3].x = 1.0;
    v22[3].y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139070
// Name: private: void CMapOverlay::Disp_DoClip(class CMapDisp __near *,class CUtlVector<struct CMapOverlay::ClipFace_t __near *,class CUtlMemory<struct CMapOverlay::ClipFace_t __near *,int>> __near &,struct cplane_t __near &,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapOverlay::Disp_DoClip(
        CMapOverlay *this,
        CMapDisp *pDisp,
        CUtlMemory<CCullTreeNode *,int> *aDispFragments,
        cplane_t *clipPlane,
        float clipDistStart,
        CMapOverlay::ClipFace_t *nInterval,
        CMapOverlay::ClipFace_t *nLoopStart,
        int nLoopEnd,
        int nLoopInc)
{
  CCullTreeNode **v9; // edx
  int v10; // ecx
  int m_nGrowSize; // esi
  CUtlMemory<CCullTreeNode *,int> *v12; // esi
  int m_pMemory; // edi
  CCullTreeNode **v14; // ebx
  CCullTreeNode **v15; // eax
  bool v16; // sf
  int v17; // eax
  CMapOverlay::ClipFace_t *v18; // edi
  cplane_t *v19; // eax
  CMapOverlay *v20; // ecx
  CMapOverlay::ClipFace_t *v21; // ebx
  CCullTreeNode **v22; // edi
  int m_nAllocationCount; // eax
  CCullTreeNode **v24; // ecx
  int v25; // eax
  CMapOverlay::ClipFace_t **v26; // eax
  CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int> > *v27; // ebx
  CCullTreeNode **v28; // edi
  int v29; // eax
  CCullTreeNode **v30; // ecx
  int v31; // eax
  CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int> > **v32; // eax
  __int16 v33; // [esp-1Ch] [ebp-48h]
  CUtlMemory<CCullTreeNode *,int> flEpsilon; // [esp+0h] [ebp-2Ch] BYREF
  int v35; // [esp+Ch] [ebp-20h]
  CCullTreeNode **v36; // [esp+10h] [ebp-1Ch]
  CMapOverlay *v37; // [esp+14h] [ebp-18h]
  float v38; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int aClippedFragments_8; // [esp+28h] [ebp-4h] OVERLAPPED

  v37 = this;
  v9 = nullptr;
  v10 = 0;
  memset(&flEpsilon, 0, sizeof(flEpsilon));
  m_nGrowSize = 0;
  v38 = 1.0 / (float)(int)nInterval;
  v35 = 0;
  v36 = nullptr;
  aClippedFragments_8 = 1;
  nInterval = nLoopStart;
  if ( (int)nLoopStart < nLoopEnd )
  {
    v12 = aDispFragments;
    while ( 1 )
    {
      m_pMemory = (int)v12[1].m_pMemory;
      v14 = v12->m_pMemory;
      v35 = 0;
      if ( m_pMemory == 0 )
        goto LABEL_13;
      if ( m_pMemory > v10 )
      {
        CUtlMemory<CVisGroup *,int>::Grow(this: &flEpsilon, num: m_pMemory - v10);
        v9 = flEpsilon.m_pMemory;
      }
      v35 += m_pMemory;
      v36 = v9;
      if ( v35 - m_pMemory > 0 )
      {
        if ( m_pMemory <= 0 )
          goto LABEL_13;
        _V_memmove(dest: &v9[m_pMemory], src: v9, count: 4 * (v35 - m_pMemory));
        v9 = flEpsilon.m_pMemory;
      }
      if ( m_pMemory > 0 )
      {
        v15 = v9;
        do
        {
          *v15 = *(CCullTreeNode **)((char *)v15 + (char *)v14 - (char *)v9);
          ++v15;
          --m_pMemory;
        }
        while ( m_pMemory != 0 );
      }
LABEL_13:
      v16 = v12->m_nGrowSize < 0;
      v12[1].m_pMemory = nullptr;
      if ( !v16 )
      {
        if ( v12->m_pMemory != nullptr )
        {
          free(pMem: v12->m_pMemory);
          v9 = flEpsilon.m_pMemory;
          v12->m_pMemory = nullptr;
        }
        v12->m_nAllocationCount = 0;
      }
      v12[1].m_nAllocationCount = (int)v12->m_pMemory;
      v17 = 0;
      for ( i = 0; v17 < v35; i = v17 )
      {
        v18 = (CMapOverlay::ClipFace_t *)v9[v17];
        if ( v18 != nullptr )
        {
          v19 = clipPlane;
          nLoopStart = nullptr;
          aDispFragments = nullptr;
          v33 = (__int16)nInterval;
          v20 = v37;
          clipPlane->dist = (float)((float)(int)nInterval * v38) * clipDistStart;
          CMapOverlay::ClipFace_ClipBarycentric(
            this: v20,
            pClipFace: v18,
            pClipPlane: v19,
            flEpsilon: 0.000001,
            iClip: v33,
            pDisp,
            ppFront: &nLoopStart,
            ppBack: (CMapOverlay::ClipFace_t **)&aDispFragments);
          CMapOverlay::ClipFace_t::~ClipFace_t(this: v18);
          operator delete(p: v18);
          v21 = nLoopStart;
          if ( nLoopStart != nullptr )
          {
            v22 = v12[1].m_pMemory;
            m_nAllocationCount = v12->m_nAllocationCount;
            if ( (int)v22 + 1 > m_nAllocationCount )
              CUtlMemory<CVisGroup *,int>::Grow(this: v12, num: (int)v22 - m_nAllocationCount + 1);
            ++v12[1].m_pMemory;
            v24 = v12->m_pMemory;
            v25 = (char *)v12[1].m_pMemory - (char *)v22 - 1;
            v12[1].m_nAllocationCount = (int)v12->m_pMemory;
            if ( v25 > 0 )
              _V_memmove(dest: &v24[(_DWORD)v22 + 1], src: &v24[(_DWORD)v22], count: 4 * v25);
            v26 = (CMapOverlay::ClipFace_t **)&v12->m_pMemory[(_DWORD)v22];
            if ( v26 != nullptr )
              *v26 = v21;
          }
          v27 = (CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int> > *)aDispFragments;
          if ( aDispFragments != nullptr )
          {
            v28 = v12[1].m_pMemory;
            v29 = v12->m_nAllocationCount;
            if ( (int)v28 + 1 > v29 )
              CUtlMemory<CVisGroup *,int>::Grow(this: v12, num: (int)v28 - v29 + 1);
            ++v12[1].m_pMemory;
            v30 = v12->m_pMemory;
            v31 = (char *)v12[1].m_pMemory - (char *)v28 - 1;
            v12[1].m_nAllocationCount = (int)v12->m_pMemory;
            if ( v31 > 0 )
              _V_memmove(dest: &v30[(_DWORD)v28 + 1], src: &v30[(_DWORD)v28], count: 4 * v31);
            v32 = (CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int> > **)&v12->m_pMemory[(_DWORD)v28];
            if ( v32 != nullptr )
              *v32 = v27;
          }
          v9 = flEpsilon.m_pMemory;
        }
        v17 = i + 1;
      }
      nInterval = (CMapOverlay::ClipFace_t *)((char *)nInterval + nLoopInc);
      if ( (int)nInterval >= nLoopEnd )
      {
        m_nGrowSize = flEpsilon.m_nGrowSize;
        break;
      }
      v10 = flEpsilon.m_nAllocationCount;
    }
  }
  v35 = 0;
  if ( m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      free(pMem: v9);
      flEpsilon.m_pMemory = nullptr;
      v9 = nullptr;
    }
    flEpsilon.m_nAllocationCount = 0;
  }
  v36 = v9;
  aClippedFragments_8 = 2;
  v35 = 0;
  if ( m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      free(pMem: v9);
      flEpsilon.m_pMemory = nullptr;
      v9 = nullptr;
    }
    flEpsilon.m_nAllocationCount = 0;
  }
  v36 = v9;
  aClippedFragments_8 = -1;
  if ( m_nGrowSize >= 0 && v9 != nullptr )
    free(pMem: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10139360
// Name: public: void CMapOverlay::CenterEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::CenterEntity(CMapOverlay *this)
{
  float y; // xmm1_4
  float x; // xmm2_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  float z; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm6_4
  float v13; // xmm6_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  int (*GetParent)(void); // edx
  float v32; // xmm1_4
  float v33; // xmm0_4
  int v34; // edi
  Vector vecSurfPoint; // [esp+4h] [ebp-38h] BYREF
  float v36; // [esp+10h] [ebp-2Ch]
  float v37; // [esp+14h] [ebp-28h]
  float v38; // [esp+18h] [ebp-24h]
  Vector vecTotal; // [esp+1Ch] [ebp-20h] BYREF
  Vector vecHandle; // [esp+28h] [ebp-14h]
  float v41; // [esp+34h] [ebp-8h]
  float v42; // [esp+38h] [ebp-4h]

  y = this->m_Handles.m_vecBasisCoords[0].y;
  x = this->m_Basis.m_vecAxes[1].x;
  v4 = this->m_Handles.m_vecBasisCoords[0].x;
  vecSurfPoint.x = x * y;
  v5 = this->m_Basis.m_vecAxes[1].y;
  vecSurfPoint.y = v5 * y;
  z = this->m_Basis.m_vecAxes[1].z;
  vecSurfPoint.z = z * y;
  v7 = this->m_Basis.m_vecAxes[0].x;
  v36 = v7 * v4;
  v8 = this->m_Basis.m_vecAxes[0].y;
  v37 = v8 * v4;
  v9 = this->m_Basis.m_vecAxes[0].z;
  v10 = v9 * v4;
  v41 = (float)(v7 * v4) + vecSurfPoint.x;
  v42 = (float)(v8 * v4) + vecSurfPoint.y;
  vecHandle.z = (float)(v9 * v4) + vecSurfPoint.z;
  v11 = this->m_Basis.m_vecOrigin.x + v41;
  v38 = v10;
  vecHandle.y = v37 + vecSurfPoint.y;
  vecHandle.x = v11;
  v12 = this->m_Basis.m_vecOrigin.y + (float)(v37 + vecSurfPoint.y);
  vecTotal.x = vecHandle.x;
  vecHandle.y = v12;
  v13 = this->m_Basis.m_vecOrigin.z + (float)(v10 + vecSurfPoint.z);
  vecTotal.y = vecHandle.y;
  vecTotal.z = v13;
  v14 = this->m_Handles.m_vecBasisCoords[1].y;
  vecSurfPoint.x = x * v14;
  vecSurfPoint.y = v5 * v14;
  v15 = z * v14;
  v16 = this->m_Handles.m_vecBasisCoords[1].x;
  vecSurfPoint.z = v15;
  v36 = v7 * v16;
  v37 = v8 * v16;
  v41 = (float)(v7 * v16) + vecSurfPoint.x;
  v42 = (float)(v8 * v16) + vecSurfPoint.y;
  v38 = v9 * v16;
  vecHandle.z = (float)(v9 * v16) + v15;
  vecHandle.x = this->m_Basis.m_vecOrigin.x + v41;
  vecHandle.y = this->m_Basis.m_vecOrigin.y + v42;
  vecHandle.z = this->m_Basis.m_vecOrigin.z + vecHandle.z;
  vecTotal.x = vecHandle.x + vecTotal.x;
  vecTotal.y = vecHandle.y + vecTotal.y;
  vecTotal.z = vecHandle.z + vecTotal.z;
  v17 = this->m_Handles.m_vecBasisCoords[2].y;
  vecSurfPoint.x = x * v17;
  vecSurfPoint.y = v5 * v17;
  v18 = z * v17;
  v19 = this->m_Handles.m_vecBasisCoords[2].x;
  vecSurfPoint.z = v18;
  v36 = v7 * v19;
  v37 = v8 * v19;
  v20 = v9 * v19;
  v41 = (float)(v7 * v19) + vecSurfPoint.x;
  v42 = (float)(v8 * v19) + vecSurfPoint.y;
  vecHandle.z = (float)(v9 * v19) + vecSurfPoint.z;
  vecHandle.x = this->m_Basis.m_vecOrigin.x + v41;
  v21 = this->m_Basis.m_vecOrigin.y;
  v38 = v20;
  vecHandle.y = v21 + v42;
  vecHandle.z = this->m_Basis.m_vecOrigin.z + vecHandle.z;
  vecTotal.x = vecHandle.x + vecTotal.x;
  vecTotal.y = (float)(v21 + v42) + vecTotal.y;
  vecTotal.z = vecHandle.z + vecTotal.z;
  v22 = this->m_Handles.m_vecBasisCoords[3].y;
  vecSurfPoint.x = x * v22;
  vecSurfPoint.y = v5 * v22;
  v23 = z * v22;
  v24 = this->m_Handles.m_vecBasisCoords[3].x;
  vecSurfPoint.z = v23;
  v36 = v7 * v24;
  v37 = v8 * v24;
  v25 = v9 * v24;
  v41 = (float)(v7 * v24) + vecSurfPoint.x;
  v42 = (float)(v8 * v24) + vecSurfPoint.y;
  vecHandle.z = (float)(v9 * v24) + vecSurfPoint.z;
  vecHandle.x = this->m_Basis.m_vecOrigin.x + v41;
  v26 = this->m_Basis.m_vecOrigin.y;
  v38 = v25;
  vecHandle.y = v26 + v42;
  vecHandle.z = this->m_Basis.m_vecOrigin.z + vecHandle.z;
  vecTotal.x = (float)(vecHandle.x + vecTotal.x) * 0.25;
  vecTotal.y = (float)((float)(v26 + v42) + vecTotal.y) * 0.25;
  vecTotal.z = (float)(vecHandle.z + vecTotal.z) * 0.25;
  vecSurfPoint.x = vecTotal.x - this->m_Basis.m_vecOrigin.x;
  vecSurfPoint.y = vecTotal.y - this->m_Basis.m_vecOrigin.y;
  v27 = vecTotal.z - this->m_Basis.m_vecOrigin.z;
  v28 = (float)(v5 * vecSurfPoint.y) + (float)(x * vecSurfPoint.x);
  v29 = (float)((float)(v8 * vecSurfPoint.y) + (float)(v7 * vecSurfPoint.x)) + (float)(v9 * v27);
  this->m_Handles.m_vecBasisCoords[0].x = this->m_Handles.m_vecBasisCoords[0].x - v29;
  v30 = v28 + (float)(z * v27);
  this->m_Handles.m_vecBasisCoords[0].y = this->m_Handles.m_vecBasisCoords[0].y - v30;
  this->m_Handles.m_vecBasisCoords[1].x = this->m_Handles.m_vecBasisCoords[1].x - v29;
  this->m_Handles.m_vecBasisCoords[1].y = this->m_Handles.m_vecBasisCoords[1].y - v30;
  this->m_Handles.m_vecBasisCoords[2].x = this->m_Handles.m_vecBasisCoords[2].x - v29;
  GetParent = (int (*)(void))this->GetParent;
  this->m_Handles.m_vecBasisCoords[2].y = this->m_Handles.m_vecBasisCoords[2].y - v30;
  this->m_Handles.m_vecBasisCoords[3].x = this->m_Handles.m_vecBasisCoords[3].x - v29;
  v32 = this->m_Handles.m_vecBasisCoords[3].y - v30;
  v33 = vecTotal.x;
  this->m_Handles.m_vecBasisCoords[3].y = v32;
  this->m_Basis.m_vecOrigin.x = v33;
  this->m_Basis.m_vecOrigin.y = vecTotal.y;
  this->m_Basis.m_vecOrigin.z = vecTotal.z;
  v34 = GetParent();
  if ( v34 != 0 )
  {
    CMapOverlay::OverlayPlaneToSurfFromList(this, vecOverlayPoint: &vecTotal, &vecSurfPoint);
    (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v34 + 84))(a1: v34, a2: &vecSurfPoint);
  }
  CMapOverlay::Basis_UpdateParentKey(this);
  CMapOverlay::Handles_UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x101398D0
// Name: public: void CMapOverlay::Handles_Init(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Handles_Init(CMapOverlay *this, CMapFace *pFace)
{
  char *DefaultTextureName; // eax
  IEditorTexture *ActiveTexture; // edi
  int v5; // kr00_4
  int v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4

  DefaultTextureName = GetDefaultTextureName();
  ActiveTexture = CTextureSystem::FindActiveTexture(
                    this: &g_Textures,
                    pszInputName: DefaultTextureName,
                    piIndex: nullptr,
                    bDummy: 1);
  v5 = ActiveTexture->GetMappingWidth(this: ActiveTexture);
  v6 = ActiveTexture->GetMappingHeight(this: ActiveTexture) / 8;
  v7 = (float)(v5 / -8);
  this->m_Handles.m_vecBasisCoords[0].x = v7;
  v8 = (float)-v6;
  this->m_Handles.m_vecBasisCoords[0].y = v8;
  this->m_Handles.m_vecBasisCoords[1].x = v7;
  this->m_Handles.m_vecBasisCoords[1].y = (float)v6;
  this->m_Handles.m_vecBasisCoords[2].x = (float)(v5 / 8);
  this->m_Handles.m_vecBasisCoords[2].y = (float)v6;
  this->m_Handles.m_vecBasisCoords[3].x = (float)(v5 / 8);
  this->m_Handles.m_vecBasisCoords[3].y = v8;
  CMapOverlay::Handles_Build3D(this);
  CMapOverlay::Handles_UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x10139990
// Name: private: void CMapOverlay::Disp_ClipFragments(class CMapDisp __near *,class CUtlVector<struct CMapOverlay::ClipFace_t __near *,class CUtlMemory<struct CMapOverlay::ClipFace_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::Disp_ClipFragments(
        CMapOverlay *this,
        CMapDisp *pDisp,
        CUtlMemory<CCullTreeNode *,int> *aDispFragments)
{
  int v4; // esi
  cplane_t clipDistStart; // [esp+0h] [ebp-14h] BYREF

  v4 = 1 << pDisp->m_CoreDispInfo.m_Power;
  clipDistStart.normal.x = 1.0;
  clipDistStart.normal.y = 0.0;
  clipDistStart.normal.z = 0.0;
  CMapOverlay::Disp_DoClip(
    this,
    pDisp,
    aDispFragments,
    clipPlane: &clipDistStart,
    clipDistStart: 1.0,
    nInterval: (CMapOverlay::ClipFace_t *)v4,
    nLoopStart: (CMapOverlay::ClipFace_t *)1,
    nLoopEnd: v4,
    nLoopInc: 1);
  clipDistStart.normal.x = 0.0;
  clipDistStart.normal.y = 1.0;
  clipDistStart.normal.z = 0.0;
  CMapOverlay::Disp_DoClip(
    this,
    pDisp,
    aDispFragments,
    clipPlane: &clipDistStart,
    clipDistStart: 1.0,
    nInterval: (CMapOverlay::ClipFace_t *)v4,
    nLoopStart: (CMapOverlay::ClipFace_t *)1,
    nLoopEnd: v4,
    nLoopInc: 1);
  clipDistStart.normal.x = 0.70700002;
  clipDistStart.normal.y = 0.70700002;
  clipDistStart.normal.z = 0.0;
  CMapOverlay::Disp_DoClip(
    this,
    pDisp,
    aDispFragments,
    clipPlane: &clipDistStart,
    clipDistStart: 0.70700002,
    nInterval: (CMapOverlay::ClipFace_t *)v4,
    nLoopStart: (CMapOverlay::ClipFace_t *)2,
    nLoopEnd: 2 * v4 - 1,
    nLoopInc: 2);
  clipDistStart.normal.x = -0.70700002;
  clipDistStart.normal.y = 0.70700002;
  clipDistStart.normal.z = 0.0;
  CMapOverlay::Disp_DoClip(
    this,
    pDisp,
    aDispFragments,
    clipPlane: &clipDistStart,
    clipDistStart: 0.70700002,
    nInterval: (CMapOverlay::ClipFace_t *)v4,
    nLoopStart: (CMapOverlay::ClipFace_t *)(2 - v4),
    nLoopEnd: v4 - 1,
    nLoopInc: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10139AA0
// Name: private: void CMapOverlay::DoClipDisp(class CMapFace __near *,struct CMapOverlay::ClipFace_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::DoClipDisp(CMapOverlay *this, CMapFace *pFace, CMapOverlay::ClipFace_t *pClippedFace)
{
  int m_DispHandle; // esi
  CEditDispMgr *v5; // eax
  CMapDisp *v6; // esi
  CMapOverlay::ClipFace_t **m_pMemory; // edi
  int v8; // ecx
  CMapOverlay::ClipFace_t **v9; // eax
  CMapOverlay::ClipFace_t *v10; // edx
  CMapOverlay *v11; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CMapOverlay::ClipFace_t **v14; // ecx
  int v15; // eax
  CMapOverlay::ClipFace_t **v16; // eax
  int m_nGrowSize; // esi
  CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int> > aCurrentFaces; // [esp+Ch] [ebp-28h] BYREF
  CMapOverlay::ClipFace_t *pClipFace; // [esp+20h] [ebp-14h]
  CMapOverlay *v20; // [esp+24h] [ebp-10h]
  int v21; // [esp+30h] [ebp-4h]
  int iFace; // [esp+40h] [ebp+Ch]

  m_DispHandle = pFace->m_DispHandle;
  v20 = this;
  v5 = EditDispMgr();
  v6 = v5->GetDisp(this: v5, a2: m_DispHandle);
  CMapOverlay::ClipFace_PreClipDisp(this, pClipFace: pClippedFace, pDisp: v6);
  memset(&aCurrentFaces, 0, sizeof(aCurrentFaces));
  v21 = 1;
  CUtlMemory<CVisGroup *,int>::Grow(this: (CUtlMemory<CCullTreeNode *,int> *)&aCurrentFaces, num: 1);
  ++aCurrentFaces.m_Size;
  m_pMemory = aCurrentFaces.m_Memory.m_pMemory;
  aCurrentFaces.m_pElements = aCurrentFaces.m_Memory.m_pMemory;
  if ( aCurrentFaces.m_Size - 1 > 0 )
    _V_memmove(
      dest: aCurrentFaces.m_Memory.m_pMemory + 1,
      src: aCurrentFaces.m_Memory.m_pMemory,
      count: 4 * (aCurrentFaces.m_Size - 1));
  if ( m_pMemory != nullptr )
    *m_pMemory = pClippedFace;
  CMapOverlay::Disp_ClipFragments(
    this: v20,
    pDisp: v6,
    aDispFragments: (CUtlMemory<CCullTreeNode *,int> *)&aCurrentFaces);
  v8 = 0;
  iFace = 0;
  if ( aCurrentFaces.m_Size <= 0 )
  {
    v9 = aCurrentFaces.m_Memory.m_pMemory;
  }
  else
  {
    do
    {
      v9 = aCurrentFaces.m_Memory.m_pMemory;
      v10 = aCurrentFaces.m_Memory.m_pMemory[v8];
      pClipFace = v10;
      if ( v10 != nullptr )
      {
        v11 = v20;
        v10->m_pBuildFace = pFace;
        m_Size = v11->m_aRenderFaces.m_Size;
        m_nAllocationCount = v11->m_aRenderFaces.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&v11->m_aRenderFaces,
            num: m_Size - m_nAllocationCount + 1);
          v10 = pClipFace;
        }
        ++v11->m_aRenderFaces.m_Size;
        v14 = v11->m_aRenderFaces.m_Memory.m_pMemory;
        v15 = v11->m_aRenderFaces.m_Size - m_Size - 1;
        v11->m_aRenderFaces.m_pElements = v14;
        if ( v15 > 0 )
        {
          _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
          v10 = pClipFace;
        }
        v16 = &v11->m_aRenderFaces.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = aCurrentFaces.m_Memory.m_pMemory[iFace];
        CMapOverlay::ClipFace_BuildFacesFromBlendedData(this: v20, pClipFace: (CMapDisp *)v10);
        v8 = iFace;
        v9 = aCurrentFaces.m_Memory.m_pMemory;
      }
      iFace = ++v8;
    }
    while ( v8 < aCurrentFaces.m_Size );
  }
  m_nGrowSize = aCurrentFaces.m_Memory.m_nGrowSize;
  aCurrentFaces.m_Size = 0;
  if ( aCurrentFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      free(pMem: v9);
      aCurrentFaces.m_Memory.m_pMemory = nullptr;
      v9 = nullptr;
    }
    aCurrentFaces.m_Memory.m_nAllocationCount = 0;
  }
  aCurrentFaces.m_pElements = v9;
  v21 = 2;
  aCurrentFaces.m_Size = 0;
  if ( m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      free(pMem: v9);
      aCurrentFaces.m_Memory.m_pMemory = nullptr;
      v9 = nullptr;
    }
    aCurrentFaces.m_Memory.m_nAllocationCount = 0;
  }
  aCurrentFaces.m_pElements = v9;
  v21 = -1;
  if ( m_nGrowSize >= 0 && v9 != nullptr )
    free(pMem: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10139C90
// Name: private: void CMapOverlay::UpdateDispBarycentric(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::UpdateDispBarycentric(CMapOverlay *this)
{
  int m_Size; // ebx
  int i; // esi
  CMapOverlay::ClipFace_t *v4; // eax

  m_Size = this->m_aRenderFaces.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_aRenderFaces.m_Memory.m_pMemory[i];
    if ( v4 != nullptr && v4->m_pBuildFace->m_DispHandle != 0xFFFF )
      CMapOverlay::ClipFace_BuildFacesFromBlendedData(
        this,
        pClipFace: (CMapDisp *)this->m_aRenderFaces.m_Memory.m_pMemory[i]);
  }
  CMapOverlay::CenterEntity(this);
  CMapOverlay::Handles_Build3D(this);
}

//------------------------------------------------------------------------------
// Address: 0x10139CE0
// Name: private: void CMapOverlay::DoClipFace(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::DoClipFace(CMapOverlay *this, CMapFace *pFace)
{
  int z_low; // ebx
  int v5; // eax
  int v6; // ecx
  CMapOverlay::ClipFace_t *v7; // eax
  float x; // edx
  cplane_t *v9; // eax
  int v10; // ecx
  unsigned int v11; // ebx
  float *v12; // eax
  float y; // xmm4_4
  float v14; // xmm5_4
  char *v15; // edx
  Vector *Points; // ecx
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  Vector *v21; // ecx
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  char *v28; // ecx
  float v29; // xmm4_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm6_4
  float v34; // xmm7_4
  float v35; // xmm5_4
  float v36; // xmm0_4
  char *v37; // ecx
  float v38; // xmm4_4
  float v39; // xmm3_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm5_4
  float v43; // xmm0_4
  float *v44; // ecx
  int v45; // edx
  float v46; // xmm4_4
  float v47; // xmm5_4
  char *v48; // eax
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // ebx
  CMapOverlay::ClipFace_t *v54; // ebx
  float *v55; // ebx
  float v56; // xmm3_4
  float v57; // xmm4_4
  float v58; // xmm5_4
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // xmm1_4
  float v62; // xmm0_4
  float v63; // xmm2_4
  float *v64; // eax
  float v65; // xmm3_4
  int i; // ebx
  Vector2D *m_pMemory; // eax
  int v68; // eax
  int v69; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CMapOverlay::ClipFace_t **v72; // ecx
  int v73; // eax
  CMapOverlay::ClipFace_t **v74; // eax
  Vector normal; // [esp+18h] [ebp-48h] BYREF
  float v76; // [esp+24h] [ebp-3Ch]
  Vector vec; // [esp+28h] [ebp-38h] BYREF
  float v78; // [esp+34h] [ebp-2Ch]
  CMapOverlay::ClipFace_t *ppFront; // [esp+38h] [ebp-28h] BYREF
  Vector2D texCoord; // [esp+3Ch] [ebp-24h] BYREF
  cplane_t *pClipPlane; // [esp+44h] [ebp-1Ch]
  CMapOverlay::ClipFace_t *pFront; // [esp+48h] [ebp-18h]
  Vector2D uv; // [esp+4Ch] [ebp-14h]
  Vector *pPoints; // [esp+5Ch] [ebp-4h]
  float z; // [esp+68h] [ebp+8h]
  float v86; // [esp+68h] [ebp+8h]
  float v87; // [esp+68h] [ebp+8h]
  float v88; // [esp+68h] [ebp+8h]
  float v89; // [esp+68h] [ebp+8h]
  CMapFace *v90; // [esp+68h] [ebp+8h]

  if ( pFace != nullptr )
  {
    LODWORD(uv.y) = CMapOverlay::ClipFace_Copy(this, pSrc: this->m_pOverlayFace);
    if ( LODWORD(uv.y) != 0 )
    {
      v5 = 12 * pFace->nPoints;
      v6 = (12 * (unsigned __int64)(unsigned int)pFace->nPoints) >> 32 != 0;
      LODWORD(vec.z) = pFace->nPoints;
      z_low = SLODWORD(vec.z);
      LODWORD(uv.x) = operator new[](nSize: v5 | -v6);
      v7 = (CMapOverlay::ClipFace_t *)operator new[](nSize: 20 * LODWORD(vec.z));
      pFront = v7;
      pPoints = (Vector *)-1;
      x = uv.x;
      if ( LODWORD(uv.x) != 0 && v7 != nullptr )
      {
        v9 = nullptr;
        pClipPlane = nullptr;
        if ( SLODWORD(vec.z) >= 4 )
        {
          ppFront = (CMapOverlay::ClipFace_t *)(4 - LODWORD(uv.x));
          LODWORD(texCoord.y) = 16 - LODWORD(uv.x);
          v10 = -20 - LODWORD(uv.x);
          v11 = ((unsigned int)(LODWORD(vec.z) - 4) >> 2) + 1;
          v12 = (float *)(LODWORD(uv.x) + 20);
          LODWORD(v78) = -20 - LODWORD(uv.x);
          pClipPlane = (cplane_t *)(4 * v11);
          while ( 1 )
          {
            y = this->m_Basis.m_vecAxes[2].y;
            v14 = this->m_Basis.m_vecAxes[2].x;
            v15 = (char *)v12 + v10;
            Points = pFace->Points;
            v17 = *(float *)&v15[(_DWORD)Points + 8];
            v18 = *(float *)&v15[(_DWORD)Points + 4];
            v19 = *(float *)&v15[(_DWORD)Points];
            vec.x = v17 - this->m_Basis.m_vecOrigin.z;
            z = this->m_Basis.m_vecAxes[2].z;
            v20 = (float)((float)(y * (float)(v18 - this->m_Basis.m_vecOrigin.y))
                        + (float)(v14 * (float)(v19 - this->m_Basis.m_vecOrigin.x)))
                + (float)(z * vec.x);
            *(v12 - 5) = v19 - (float)(v14 * v20);
            *(v12 - 4) = v18 - (float)(y * v20);
            *(v12 - 3) = v17 - (float)(z * v20);
            v21 = pFace->Points;
            v22 = *(float *)&v15[(_DWORD)v21 + 20];
            v23 = *(float *)&v15[(_DWORD)v21 + 16];
            v24 = *(float *)&v15[(_DWORD)v21 + 12];
            v25 = this->m_Basis.m_vecAxes[2].y;
            v26 = this->m_Basis.m_vecAxes[2].x;
            vec.x = v22 - this->m_Basis.m_vecOrigin.z;
            v86 = this->m_Basis.m_vecAxes[2].z;
            v27 = (float)((float)(v25 * (float)(v23 - this->m_Basis.m_vecOrigin.y))
                        + (float)(v26 * (float)(v24 - this->m_Basis.m_vecOrigin.x)))
                + (float)(v86 * vec.x);
            *(v12 - 2) = v24 - (float)(v26 * v27);
            *(v12 - 1) = v23 - (float)(v25 * v27);
            *v12 = v22 - (float)(v86 * v27);
            v28 = (char *)ppFront + (unsigned int)pFace->Points;
            v29 = this->m_Basis.m_vecAxes[2].y;
            v30 = *(float *)((char *)v12 + (_DWORD)v28 + 8);
            v31 = *(float *)((char *)v12 + (_DWORD)v28);
            v32 = *(float *)((char *)v12 + (_DWORD)v28 + 4);
            v33 = v31 - this->m_Basis.m_vecOrigin.x;
            v34 = v32 - this->m_Basis.m_vecOrigin.y;
            vec.x = v30 - this->m_Basis.m_vecOrigin.z;
            v35 = this->m_Basis.m_vecAxes[2].x;
            v87 = this->m_Basis.m_vecAxes[2].z;
            v36 = (float)((float)(v29 * v34) + (float)(v35 * v33)) + (float)(v87 * vec.x);
            v12[1] = v31 - (float)(v35 * v36);
            v12[2] = v32 - (float)(v29 * v36);
            v12[3] = v30 - (float)(v87 * v36);
            v37 = (char *)pFace->Points + LODWORD(texCoord.y);
            v38 = this->m_Basis.m_vecAxes[2].y;
            v39 = *(float *)((char *)v12 + (_DWORD)v37 + 8);
            v40 = *(float *)((char *)v12 + (_DWORD)v37 + 4);
            v41 = *(float *)((char *)v12 + (_DWORD)v37);
            v42 = this->m_Basis.m_vecAxes[2].x;
            vec.x = v39 - this->m_Basis.m_vecOrigin.z;
            v88 = this->m_Basis.m_vecAxes[2].z;
            v43 = (float)((float)(v38 * (float)(v40 - this->m_Basis.m_vecOrigin.y))
                        + (float)(v42 * (float)(v41 - this->m_Basis.m_vecOrigin.x)))
                + (float)(v88 * vec.x);
            v12[4] = v41 - (float)(v42 * v43);
            v12[5] = v40 - (float)(v38 * v43);
            v12[6] = v39 - (float)(v88 * v43);
            v12 += 12;
            if ( --v11 == 0 )
              break;
            v10 = LODWORD(v78);
          }
          v9 = pClipPlane;
          z_low = SLODWORD(vec.z);
          x = uv.x;
        }
        if ( (int)v9 < z_low )
        {
          v44 = (float *)(LODWORD(x) + 12 * (_DWORD)v9 + 8);
          LODWORD(vec.z) = -8 - LODWORD(x);
          v45 = -8 - LODWORD(x);
          pClipPlane = (cplane_t *)(z_low - (_DWORD)pClipPlane);
          do
          {
            v46 = this->m_Basis.m_vecAxes[2].y;
            v47 = this->m_Basis.m_vecAxes[2].x;
            v48 = (char *)pFace->Points + v45;
            v49 = *(float *)((char *)v44 + (_DWORD)v48 + 8);
            v50 = *(float *)((char *)v44 + (_DWORD)v48 + 4);
            v51 = *(float *)((char *)v44 + (_DWORD)v48);
            vec.x = v49 - this->m_Basis.m_vecOrigin.z;
            v89 = this->m_Basis.m_vecAxes[2].z;
            v52 = (float)((float)(v46 * (float)(v50 - this->m_Basis.m_vecOrigin.y))
                        + (float)(v47 * (float)(v51 - this->m_Basis.m_vecOrigin.x)))
                + (float)(v89 * vec.x);
            *(v44 - 2) = v51 - (float)(v47 * v52);
            *(v44 - 1) = v50 - (float)(v46 * v52);
            *v44 = v49 - (float)(v89 * v52);
            v44 += 3;
            pClipPlane = (cplane_t *)((char *)pClipPlane - 1);
          }
          while ( pClipPlane != nullptr );
          x = uv.x;
        }
        CMapOverlay::BuildEdgePlanes(
          this,
          pPoints: (const Vector *)LODWORD(x),
          nPointCount: z_low,
          pEdgePlanes: (cplane_t *)pFront,
          nEdgePlaneCount: z_low);
        if ( z_low <= 0 )
        {
          v53 = uv.y;
        }
        else
        {
          pClipPlane = (cplane_t *)pFront;
          v78 = *(float *)&z_low;
          do
          {
            v53 = uv.y;
            *(float *)&ppFront = 0.0;
            texCoord.y = 0.0;
            if ( LODWORD(uv.y) != 0 )
            {
              CMapOverlay::ClipFace_Clip(
                this,
                pClipFace: (CMapOverlay::ClipFace_t *)LODWORD(uv.y),
                pClipPlane,
                flEpsilon: 0.03125,
                &ppFront,
                ppBack: (CMapOverlay::ClipFace_t **)&texCoord.y);
              CMapOverlay::ClipFace_t::~ClipFace_t(this: (CMapOverlay::ClipFace_t *)LODWORD(v53));
              operator delete(p: (void *)LODWORD(v53));
              uv.y = 0.0;
              if ( LODWORD(texCoord.y) != 0 )
                uv.y = texCoord.y;
              v54 = ppFront;
              if ( *(float *)&ppFront != 0.0 )
              {
                CMapOverlay::ClipFace_t::~ClipFace_t(this: ppFront);
                operator delete(p: v54);
              }
              v53 = uv.y;
            }
            ++pClipPlane;
            --LODWORD(v78);
          }
          while ( v78 != 0.0 );
        }
        operator delete(p: (void *)LODWORD(uv.x));
        operator delete(p: pFront);
        if ( v53 != 0.0 )
        {
          pClipPlane = nullptr;
          if ( *(int *)(LODWORD(v53) + 4) > 0 )
          {
            uv.x = 0.0;
            do
            {
              PointInQuadToBarycentric(
                v1: this->m_pOverlayFace->m_aPoints.m_Memory.m_pMemory,
                v2: (const Vector *)this->m_pOverlayFace->m_aPoints.m_Memory.m_pMemory + 3,
                v3: (const Vector *)this->m_pOverlayFace->m_aPoints.m_Memory.m_pMemory + 2,
                v4: (const Vector *)this->m_pOverlayFace->m_aPoints.m_Memory.m_pMemory + 1,
                point: (const Vector *)(LODWORD(uv.x) + *(_DWORD *)(LODWORD(v53) + 8)),
                uv: &texCoord);
              v55 = (float *)(LODWORD(uv.x) + *(_DWORD *)(LODWORD(v53) + 8));
              normal = pFace->plane.normal;
              VectorNormalize(vec: &normal);
              v56 = v55[1];
              v57 = *v55;
              v58 = v55[2];
              v59 = (float)((float)(pFace->Points->y * normal.y) + (float)(pFace->Points->x * normal.x))
                  + (float)(pFace->Points->z * normal.z);
              ppFront = (CMapOverlay::ClipFace_t *)LODWORD(this->m_Basis.m_vecAxes[2].y);
              v78 = this->m_Basis.m_vecAxes[2].x;
              v60 = this->m_Basis.m_vecAxes[2].z;
              v76 = v59;
              *(float *)&v90 = v60;
              v61 = (float)((float)(*(float *)&ppFront * normal.y) + (float)(v78 * normal.x)) + (float)(v60 * normal.z);
              v62 = (float)((float)((float)(v56 * normal.y) + (float)(v57 * normal.x)) + (float)(v58 * normal.z)) - v59;
              v63 = v62;
              if ( v61 != 0.0 )
                v63 = (float)(1.0 / v61) * v62;
              v64 = (float *)(LODWORD(uv.x) + *(_DWORD *)(LODWORD(uv.y) + 8));
              v65 = v56 - (float)(*(float *)&ppFront * v63);
              *v64 = v57 - (float)(v78 * v63);
              v64[1] = v65;
              v64[2] = v58 - (float)(*(float *)&v90 * v63);
              for ( i = 0; i < 2; ++i )
              {
                m_pMemory = this->m_pOverlayFace->m_aTexCoords[i].m_Memory.m_pMemory;
                TexCoordInQuadFromBarycentric(
                  v1: m_pMemory,
                  v2: m_pMemory + 3,
                  v3: m_pMemory + 2,
                  v4: m_pMemory + 1,
                  uv: &texCoord,
                  texCoord: (Vector2D *)&vec.y);
                v68 = *(_DWORD *)(LODWORD(uv.y) + i * 20 + 68);
                v69 = 8 * (_DWORD)pClipPlane;
                *(float *)(v68 + v69) = vec.y;
                *(float *)(v68 + v69 + 4) = vec.z;
              }
              LODWORD(uv.x) += 12;
              pClipPlane = (cplane_t *)((char *)pClipPlane + 1);
              v53 = uv.y;
            }
            while ( (int)pClipPlane < *(_DWORD *)(LODWORD(uv.y) + 4) );
          }
          if ( pFace->m_DispHandle == 0xFFFF )
          {
            *(_DWORD *)LODWORD(v53) = pFace;
            m_Size = this->m_aRenderFaces.m_Size;
            m_nAllocationCount = this->m_aRenderFaces.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CVisGroup *,int>::Grow(
                this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_aRenderFaces,
                num: m_Size - m_nAllocationCount + 1);
            ++this->m_aRenderFaces.m_Size;
            v72 = this->m_aRenderFaces.m_Memory.m_pMemory;
            v73 = this->m_aRenderFaces.m_Size - m_Size - 1;
            this->m_aRenderFaces.m_pElements = v72;
            if ( v73 > 0 )
              _V_memmove(dest: &v72[m_Size + 1], src: &v72[m_Size], count: 4 * v73);
            v74 = &this->m_aRenderFaces.m_Memory.m_pMemory[m_Size];
            if ( v74 != nullptr )
              *(float *)v74 = v53;
          }
          else
          {
            CMapOverlay::DoClipDisp(this, pFace, pClippedFace: (CMapOverlay::ClipFace_t *)LODWORD(v53));
          }
        }
      }
      else
      {
        operator delete(p: (void *)LODWORD(uv.x));
        operator delete(p: pFront);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A510
// Name: public: void CMapOverlay::DoClip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::DoClip(CMapOverlay *this)
{
  int m_Size; // edi
  int v3; // ebx
  CMapFace *v4; // edi
  CMapOverlay::ClipFace_t *m_pOverlayFace; // edi
  int nFaceCount; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Faces.m_Size;
  v3 = 0;
  nFaceCount = m_Size;
  if ( m_Size != 0 )
  {
    this->m_aRenderFaces.m_Size = 0;
    if ( this->m_aRenderFaces.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_aRenderFaces.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: this->m_aRenderFaces.m_Memory.m_pMemory);
        this->m_aRenderFaces.m_Memory.m_pMemory = nullptr;
      }
      this->m_aRenderFaces.m_Memory.m_nAllocationCount = 0;
    }
    this->m_aRenderFaces.m_pElements = this->m_aRenderFaces.m_Memory.m_pMemory;
    if ( m_Size > 0 )
    {
      do
      {
        v4 = this->m_Faces.m_Memory.m_pMemory[v3];
        if ( v4 != nullptr )
        {
          CMapOverlay::PreClip(this);
          CMapOverlay::DoClipFace(this, pFace: v4);
          m_pOverlayFace = this->m_pOverlayFace;
          if ( m_pOverlayFace != nullptr )
          {
            CMapOverlay::ClipFace_t::~ClipFace_t(this: this->m_pOverlayFace);
            operator delete(p: m_pOverlayFace);
            this->m_pOverlayFace = nullptr;
          }
        }
        ++v3;
      }
      while ( v3 < nFaceCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A5C0
// Name: public: virtual void CMapOverlay::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::PostloadWorld(CMapOverlay *this, CMapWorld *pWorld)
{
  int v3; // ebx
  Vector *m_vecAxes; // edi
  int v5; // ecx
  float *p_x; // edx
  CMapFace *v7; // eax

  CMapClass::PostloadWorld(this, pWorld);
  v3 = 0;
  m_vecAxes = this->m_Basis.m_vecAxes;
  while ( 2 )
  {
    v5 = 0;
    p_x = &m_vecAxes->x;
    do
    {
      if ( *p_x == -99999.898 )
      {
        if ( this->m_Faces.m_Size <= 0 )
        {
          this->m_Basis.m_pFace = nullptr;
        }
        else
        {
          v7 = *this->m_Faces.m_Memory.m_pMemory;
          if ( v7 != nullptr )
          {
            this->m_Basis.m_pFace = v7;
            CMapOverlay::Basis_UpdateOrigin(this);
            CMapOverlay::Basis_BuildAxes(this);
            CMapOverlay::Material_TexCoordInit(this);
          }
        }
        goto LABEL_11;
      }
      ++v5;
      ++p_x;
    }
    while ( v5 < 3 );
    ++v3;
    ++m_vecAxes;
    if ( v3 < 3 )
      continue;
    break;
  }
LABEL_11:
  CMapOverlay::Handles_Build3D(this);
  CMapOverlay::DoClip(this);
  this->CalcBounds(this, a2: 0);
  this->m_bLoaded = true;
}

//------------------------------------------------------------------------------
// Address: 0x1013A670
// Name: public: virtual void CMapOverlay::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::OnParentKeyChanged(CMapOverlay *this, const char *szKey, const char *szValue)
{
  const char *v3; // edi
  CMapFace *v5; // eax
  IEditorTexture *ActiveTexture; // eax

  v3 = szValue;
  CMapSideList::OnParentKeyChanged(this, pszKey: szKey, pszValue: szValue);
  if ( _V_stricmp(s1: szKey, s2: "sides") == 0 && this->m_Faces.m_Size > 0 )
  {
    v5 = *this->m_Faces.m_Memory.m_pMemory;
    if ( v5 != nullptr )
      this->m_Basis.m_pFace = v5;
  }
  if ( _V_stricmp(s1: szKey, s2: "uv0") == 0 )
  {
    sscanf(
      string: v3,
      format: "%f %f %f",
      this->m_Handles.m_vecBasisCoords,
      &this->m_Handles.m_vecBasisCoords[0].y,
      &szValue);
    this->m_Basis.m_nAxesFlip[0] = (int)*(float *)&szValue;
  }
  if ( _V_stricmp(s1: szKey, s2: "uv1") == 0 )
  {
    sscanf(
      string: v3,
      format: "%f %f %f",
      &this->m_Handles.m_vecBasisCoords[1],
      &this->m_Handles.m_vecBasisCoords[1].y,
      &szValue);
    this->m_Basis.m_nAxesFlip[1] = (int)*(float *)&szValue;
  }
  if ( _V_stricmp(s1: szKey, s2: "uv2") == 0 )
  {
    sscanf(
      string: v3,
      format: "%f %f %f",
      &this->m_Handles.m_vecBasisCoords[2],
      &this->m_Handles.m_vecBasisCoords[2].y,
      &szValue);
    this->m_Basis.m_nAxesFlip[2] = (int)*(float *)&szValue;
  }
  if ( _V_stricmp(s1: szKey, s2: "uv3") == 0 )
    sscanf(
      string: v3,
      format: "%f %f %f",
      &this->m_Handles.m_vecBasisCoords[3],
      &this->m_Handles.m_vecBasisCoords[3].y,
      &szValue);
  if ( _V_stricmp(s1: szKey, s2: "BasisOrigin") == 0 )
    sscanf(
      string: v3,
      format: "%f %f %f",
      &this->m_Basis.m_vecOrigin,
      &this->m_Basis.m_vecOrigin.y,
      &this->m_Basis.m_vecOrigin.z);
  if ( _V_stricmp(s1: szKey, s2: "BasisU") == 0 )
    sscanf(
      string: v3,
      format: "%f %f %f",
      this->m_Basis.m_vecAxes,
      &this->m_Basis.m_vecAxes[0].y,
      &this->m_Basis.m_vecAxes[0].z);
  if ( _V_stricmp(s1: szKey, s2: "BasisV") == 0 )
    sscanf(
      string: v3,
      format: "%f %f %f",
      &this->m_Basis.m_vecAxes[1],
      &this->m_Basis.m_vecAxes[1].y,
      &this->m_Basis.m_vecAxes[1].z);
  if ( _V_stricmp(s1: szKey, s2: "BasisNormal") == 0 )
    sscanf(
      string: v3,
      format: "%f %f %f",
      &this->m_Basis.m_vecAxes[2],
      &this->m_Basis.m_vecAxes[2].y,
      &this->m_Basis.m_vecAxes[2].z);
  if ( _V_stricmp(s1: szKey, s2: "material") == 0 )
  {
    ActiveTexture = CTextureSystem::FindActiveTexture(this: &g_Textures, pszInputName: v3, piIndex: nullptr, bDummy: 1);
    if ( ActiveTexture == nullptr )
      return;
    this->m_Material.m_pTexture = ActiveTexture;
  }
  if ( _V_stricmp(s1: szKey, s2: "StartU") == 0 )
    this->m_Material.m_vecTextureU.x = atof(nptr: v3);
  if ( _V_stricmp(s1: szKey, s2: "EndU") == 0 )
    this->m_Material.m_vecTextureU.y = atof(nptr: v3);
  if ( _V_stricmp(s1: szKey, s2: "StartV") == 0 )
    this->m_Material.m_vecTextureV.x = atof(nptr: v3);
  if ( _V_stricmp(s1: szKey, s2: "EndV") == 0 )
    this->m_Material.m_vecTextureV.y = atof(nptr: v3);
  if ( this->m_bLoaded )
  {
    CMapOverlay::DoClip(this);
    this->PostUpdate(this, a2: Notify_Changed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013A950
// Name: public: virtual void CMapOverlay::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CMapOverlay::DoTransform(CMapOverlay *this@<ecx>, float a2@<ebp>, const VMatrix *matrix)
{
  bool IsIdentity; // al
  float x; // esi
  float *v5; // edi
  float v6; // xmm1_4
  float v7; // eax
  float v8; // xmm5_4
  float v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // edx
  float v15; // xmm5_4
  __int128 v16; // xmm7
  bool v17; // cl
  float v18; // xmm6_4
  float v19; // xmm6_4
  float v20; // xmm6_4
  bool v21; // al
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // xmm3_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm2_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  float v43; // xmm2_4
  float v44; // xmm5_4
  float v45; // xmm4_4
  float v46; // xmm7_4
  float v47; // xmm6_4
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  float v51; // xmm4_4
  float v52; // xmm5_4
  float v53; // xmm2_4
  float v54; // xmm7_4
  float v55; // xmm6_4
  float v56; // xmm3_4
  float v57; // xmm4_4
  float v58; // xmm7_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm1_4
  float v62; // xmm3_4
  _DWORD *v63; // ecx
  int v64; // eax
  float v65; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v68; // [esp-2Ch] [ebp-ACh]
  float v69; // [esp-1Ch] [ebp-9Ch]
  _BYTE v70[76]; // [esp-Ch] [ebp-8Ch] OVERLAPPED BYREF
  float v71; // [esp+40h] [ebp-40h]
  _QWORD v72[2]; // [esp+44h] [ebp-3Ch] BYREF
  __int64 v73; // [esp+58h] [ebp-28h]
  float v74; // [esp+60h] [ebp-20h]
  Vector vecPos; // [esp+64h] [ebp-1Ch] BYREF
  Vector vecV; // [esp+70h] [ebp-10h]
  float retaddr; // [esp+80h] [ebp+0h]

  vecV.y = a2;
  vecV.z = retaddr;
  LODWORD(vecV.x) = this;
  CMapClass::DoTransform(this, matrix);
  *(VMatrix *)v70 = *matrix;
  *(float *)&v70[12] = vec3_origin.x;
  *(float *)&v70[28] = vec3_origin.y;
  *(float *)&v70[44] = vec3_origin.z;
  IsIdentity = VMatrix::IsIdentity(this: (VMatrix *)v70);
  x = vecV.x;
  if ( !IsIdentity )
  {
    v5 = (float *)(LODWORD(vecV.x) + 352);
    VectorNormalize(vec: (Vector *)(LODWORD(vecV.x) + 352));
    VectorNormalize(vec: (Vector *)(LODWORD(x) + 364));
    v6 = *(float *)&v70[48];
    v7 = *(float *)(LODWORD(x) + 360);
    *(_QWORD *)&vecPos.x = *(_QWORD *)(LODWORD(x) + 352);
    vecPos.z = v7;
    v8 = 1.0
       / (float)((float)((float)((float)(vecPos.y * *(float *)&v70[52]) + (float)(*(float *)&v70[48] * vecPos.x))
                       + (float)(v7 * *(float *)&v70[56]))
               + *(float *)&v70[60]);
    v9 = *(float *)(LODWORD(x) + 372);
    v10 = *(float *)&v70[16];
    v11 = (float)((float)((float)((float)(*(float *)v70 * vecPos.x) + (float)(*(float *)&v70[4] * vecPos.y))
                        + (float)(*(float *)&v70[8] * v7))
                + *(float *)&v70[12])
        * v8;
    v12 = (float)((float)((float)((float)(*(float *)&v70[16] * vecPos.x) + (float)(*(float *)&v70[20] * vecPos.y))
                        + (float)(*(float *)&v70[24] * v7))
                + *(float *)&v70[28])
        * v8;
    v13 = (float)((float)((float)((float)(*(float *)&v70[32] * vecPos.x) + (float)(*(float *)&v70[36] * vecPos.y))
                        + (float)(*(float *)&v70[40] * v7))
                + *(float *)&v70[44])
        * v8;
    *(_QWORD *)((char *)v72 + 4) = *(_QWORD *)(LODWORD(x) + 364);
    *((float *)&v72[1] + 1) = v9;
    vecV.x = 1.0
           / (float)((float)((float)((float)(*(float *)&v70[48] * *((float *)v72 + 1))
                                   + (float)(*(float *)&v72[1] * *(float *)&v70[52]))
                           + (float)(v9 * *(float *)&v70[56]))
                   + *(float *)&v70[60]);
    vecPos.x = (float)((float)((float)((float)(*((float *)v72 + 1) * *(float *)v70)
                                     + (float)(*(float *)&v72[1] * *(float *)&v70[4]))
                             + (float)(v9 * *(float *)&v70[8]))
                     + *(float *)&v70[12])
             * vecV.x;
    v14 = *(float *)(LODWORD(x) + 384);
    vecPos.y = (float)((float)((float)((float)(*(float *)&v70[16] * *((float *)v72 + 1))
                                     + (float)(*(float *)&v72[1] * *(float *)&v70[20]))
                             + (float)(v9 * *(float *)&v70[24]))
                     + *(float *)&v70[28])
             * vecV.x;
    vecPos.z = (float)((float)((float)((float)(*(float *)&v70[32] * *((float *)v72 + 1))
                                     + (float)(*(float *)&v72[1] * *(float *)&v70[36]))
                             + (float)(v9 * *(float *)&v70[40]))
                     + *(float *)&v70[44])
             * vecV.x;
    *(_QWORD *)((char *)v72 + 4) = *(_QWORD *)(LODWORD(x) + 376);
    vecV.x = 1.0
           / (float)((float)((float)((float)(*(float *)&v70[48] * *((float *)v72 + 1))
                                   + (float)(*(float *)&v72[1] * *(float *)&v70[52]))
                           + (float)(v14 * *(float *)&v70[56]))
                   + *(float *)&v70[60]);
    *(float *)&v73 = (float)((float)((float)((float)(*((float *)v72 + 1) * *(float *)v70)
                                           + (float)(*(float *)&v72[1] * *(float *)&v70[4]))
                                   + (float)(v14 * *(float *)&v70[8]))
                           + *(float *)&v70[12])
                   * vecV.x;
    *((float *)&v73 + 1) = (float)((float)((float)((float)(*(float *)&v70[16] * *((float *)v72 + 1))
                                                 + (float)(*(float *)&v72[1] * *(float *)&v70[20]))
                                         + (float)(v14 * *(float *)&v70[24]))
                                 + *(float *)&v70[28])
                         * vecV.x;
    v74 = (float)((float)((float)((float)(*(float *)&v70[32] * *((float *)v72 + 1))
                                + (float)(*(float *)&v72[1] * *(float *)&v70[36]))
                        + (float)(v14 * *(float *)&v70[40]))
                + *(float *)&v70[44])
        * vecV.x;
    v69 = fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13));
    v68 = fsqrt((float)((float)(vecPos.x * vecPos.x) + (float)(vecPos.y * vecPos.y)) + (float)(vecPos.z * vecPos.z));
    vecV.x = *(float *)&v73 * *(float *)&v73;
    v15 = v74;
    v16 = 0;
    *(float *)&v16 = fsqrt(
                       (float)((float)(*(float *)&v73 * *(float *)&v73)
                             + (float)(*((float *)&v73 + 1) * *((float *)&v73 + 1)))
                     + (float)(v15 * v15));
    *(_OWORD *)v72 = v16;
    v17 = v69 < 1.0001
       && v69 > 0.99989998
       && v68 < 1.0001
       && v68 > 0.99989998
       && *(float *)v72 < 1.0001
       && *(float *)v72 > 0.99989998;
    v18 = (float)((float)(vecPos.x * v11) + (float)(vecPos.y * v12)) + (float)(vecPos.z * v13);
    v21 = false;
    if ( v18 < 0.0024999999 && v18 > -0.0024999999 )
    {
      v19 = (float)((float)(*(float *)&v73 * v11) + (float)(*((float *)&v73 + 1) * v12)) + (float)(v74 * v13);
      if ( v19 < 0.0024999999 && v19 > -0.0024999999 )
      {
        vecV.x = (float)(*(float *)&v73 * vecPos.x) + (float)(*((float *)&v73 + 1) * vecPos.y);
        v20 = vecV.x + (float)(v74 * vecPos.z);
        if ( v20 < 0.0024999999 && v20 > -0.0024999999 )
          v21 = true;
      }
    }
    if ( v17 && v21 )
    {
      v22 = vecPos.x;
      *v5 = v11;
      *(float *)(LODWORD(x) + 356) = v12;
      *(float *)(LODWORD(x) + 360) = v13;
      *(float *)(LODWORD(x) + 364) = v22;
      *(float *)(LODWORD(x) + 368) = vecPos.y;
      *(float *)(LODWORD(x) + 372) = vecPos.z;
      *(_QWORD *)(LODWORD(x) + 376) = v73;
      *(float *)(LODWORD(x) + 384) = v15;
    }
    else
    {
      v23 = *(float *)(LODWORD(x) + 408);
      v24 = *(float *)(LODWORD(x) + 368);
      v25 = *(float *)(LODWORD(x) + 360);
      v26 = *(float *)(LODWORD(x) + 404);
      v27 = *(float *)(LODWORD(x) + 356);
      *(_DWORD *)&v70[64] = *(_DWORD *)(LODWORD(x) + 364);
      vecPos.x = *(float *)&v70[64] * v23;
      *(float *)&v70[72] = v25;
      vecPos.y = v24 * v23;
      vecV.x = *(float *)(LODWORD(x) + 372);
      *(float *)&v70[68] = *v5;
      vecPos.z = vecV.x * v23;
      *(float *)&v73 = (float)(*(float *)&v70[68] * v26) + (float)(*(float *)&v70[64] * v23);
      v74 = (float)(v25 * v26) + (float)(vecV.x * v23);
      *((float *)&v73 + 1) = (float)(v27 * v26) + (float)(v24 * v23);
      *(_QWORD *)((char *)v72 + 4) = v73;
      v28 = 1.0
          / (float)((float)((float)((float)(*(float *)&v70[48] * *(float *)&v73)
                                  + (float)(*((float *)&v73 + 1) * *(float *)&v70[52]))
                          + (float)(v74 * *(float *)&v70[56]))
                  + *(float *)&v70[60]);
      *(float *)&v73 = (float)((float)((float)((float)(*(float *)&v73 * *(float *)v70)
                                             + (float)(*((float *)&v73 + 1) * *(float *)&v70[4]))
                                     + (float)(v74 * *(float *)&v70[8]))
                             + *(float *)&v70[12])
                     * v28;
      v71 = v28;
      *((float *)&v72[1] + 1) = v74;
      v29 = (float)((float)((float)((float)(*(float *)&v70[16] * *((float *)v72 + 1))
                                  + (float)(*((float *)&v73 + 1) * *(float *)&v70[20]))
                          + (float)(v74 * *(float *)&v70[24]))
                  + *(float *)&v70[28])
          * v28;
      v30 = (float)((float)((float)((float)(*((float *)&v73 + 1) * *(float *)&v70[36])
                                  + (float)(*(float *)&v70[32] * *((float *)v72 + 1)))
                          + (float)(v74 * *(float *)&v70[40]))
                  + *(float *)&v70[44])
          * v71;
      v31 = (float)((float)(v24 * v29) + (float)(*(float *)&v70[64] * *(float *)&v73)) + (float)(vecV.x * v30);
      *(float *)(LODWORD(x) + 404) = (float)((float)(v27 * v29) + (float)(*(float *)&v70[68] * *(float *)&v73))
                                   + (float)(*(float *)&v70[72] * v30);
      *(float *)(LODWORD(x) + 408) = v31;
      v32 = *(float *)(LODWORD(x) + 416);
      v33 = *(float *)(LODWORD(x) + 368);
      v34 = *(float *)(LODWORD(x) + 360);
      v35 = *(float *)(LODWORD(x) + 412);
      v36 = *(float *)(LODWORD(x) + 356);
      *(_DWORD *)&v70[64] = *(_DWORD *)(LODWORD(x) + 364);
      vecPos.x = *(float *)&v70[64] * v32;
      *(float *)&v70[72] = v34;
      vecPos.y = v33 * v32;
      vecV.x = *(float *)(LODWORD(x) + 372);
      v37 = vecV.x * v32;
      v38 = *v5;
      vecPos.z = v37;
      *(float *)&v70[68] = v38;
      v74 = (float)(v34 * v35) + v37;
      *(float *)&v73 = (float)(v38 * v35) + vecPos.x;
      *((float *)&v73 + 1) = (float)(v36 * v35) + vecPos.y;
      *(_QWORD *)((char *)v72 + 4) = v73;
      v39 = 1.0
          / (float)((float)((float)((float)(v6 * *(float *)&v73) + (float)(*((float *)&v73 + 1) * *(float *)&v70[52]))
                          + (float)(v74 * *(float *)&v70[56]))
                  + *(float *)&v70[60]);
      *(float *)&v73 = (float)((float)((float)((float)(*(float *)&v73 * *(float *)v70)
                                             + (float)(*((float *)&v73 + 1) * *(float *)&v70[4]))
                                     + (float)(v74 * *(float *)&v70[8]))
                             + *(float *)&v70[12])
                     * v39;
      v71 = v39;
      *((float *)&v72[1] + 1) = v74;
      v40 = (float)((float)((float)((float)(v10 * *((float *)v72 + 1))
                                  + (float)(*((float *)&v73 + 1) * *(float *)&v70[20]))
                          + (float)(v74 * *(float *)&v70[24]))
                  + *(float *)&v70[28])
          * v39;
      v41 = (float)((float)((float)((float)(*((float *)&v73 + 1) * *(float *)&v70[36])
                                  + (float)(*(float *)&v70[32] * *((float *)v72 + 1)))
                          + (float)(v74 * *(float *)&v70[40]))
                  + *(float *)&v70[44])
          * v71;
      v42 = (float)((float)(v33 * v40) + (float)(*(float *)&v70[64] * *(float *)&v73)) + (float)(vecV.x * v41);
      *(float *)(LODWORD(x) + 412) = (float)((float)(v36 * v40) + (float)(v38 * *(float *)&v73))
                                   + (float)(*(float *)&v70[72] * v41);
      *(float *)(LODWORD(x) + 416) = v42;
      v43 = *(float *)(LODWORD(x) + 424);
      v44 = *(float *)(LODWORD(x) + 368);
      v45 = *(float *)(LODWORD(x) + 360);
      v46 = *(float *)(LODWORD(x) + 420);
      v47 = *(float *)(LODWORD(x) + 356);
      *(_DWORD *)&v70[64] = *(_DWORD *)(LODWORD(x) + 364);
      vecPos.x = *(float *)&v70[64] * v43;
      *(float *)&v70[72] = v45;
      vecPos.y = v44 * v43;
      vecV.x = *(float *)(LODWORD(x) + 372);
      v48 = vecV.x * v43;
      v49 = *v5;
      vecPos.z = v48;
      *(float *)&v70[68] = v49;
      v74 = (float)(v45 * v46) + v48;
      *(float *)&v73 = (float)(v49 * v46) + vecPos.x;
      *((float *)&v73 + 1) = (float)(v47 * v46) + vecPos.y;
      *(_QWORD *)((char *)v72 + 4) = v73;
      v71 = 1.0
          / (float)((float)((float)((float)(v6 * *(float *)&v73) + (float)(*((float *)&v73 + 1) * *(float *)&v70[52]))
                          + (float)(v74 * *(float *)&v70[56]))
                  + *(float *)&v70[60]);
      *(float *)&v73 = (float)((float)((float)((float)(*(float *)&v73 * *(float *)v70)
                                             + (float)(*((float *)&v73 + 1) * *(float *)&v70[4]))
                                     + (float)(v74 * *(float *)&v70[8]))
                             + *(float *)&v70[12])
                     * v71;
      *((float *)&v72[1] + 1) = v74;
      v50 = (float)((float)((float)((float)(v10 * *((float *)v72 + 1))
                                  + (float)(*((float *)&v73 + 1) * *(float *)&v70[20]))
                          + (float)(v74 * *(float *)&v70[24]))
                  + *(float *)&v70[28])
          * v71;
      v51 = (float)((float)((float)((float)(*((float *)&v73 + 1) * *(float *)&v70[36])
                                  + (float)(*(float *)&v70[32] * *((float *)v72 + 1)))
                          + (float)(v74 * *(float *)&v70[40]))
                  + *(float *)&v70[44])
          * v71;
      v52 = (float)((float)(v44 * v50) + (float)(*(float *)&v70[64] * *(float *)&v73)) + (float)(vecV.x * v51);
      *(float *)(LODWORD(x) + 420) = (float)((float)(v47 * v50) + (float)(v49 * *(float *)&v73))
                                   + (float)(*(float *)&v70[72] * v51);
      *(float *)(LODWORD(x) + 424) = v52;
      v53 = *(float *)(LODWORD(x) + 432);
      v54 = *(float *)(LODWORD(x) + 428);
      v55 = *(float *)(LODWORD(x) + 360);
      *(_DWORD *)&v70[64] = *(_DWORD *)(LODWORD(x) + 364);
      vecPos.x = *(float *)&v70[64] * v53;
      v56 = *(float *)(LODWORD(x) + 368);
      vecPos.y = v56 * v53;
      vecV.x = *(float *)(LODWORD(x) + 372);
      *(float *)&v70[68] = *v5;
      vecPos.z = vecV.x * v53;
      v57 = *(float *)(LODWORD(x) + 356);
      *(float *)&v73 = (float)(*(float *)&v70[68] * v54) + (float)(*(float *)&v70[64] * v53);
      *(float *)&v70[72] = v55;
      *((float *)&v73 + 1) = (float)(v57 * v54) + (float)(v56 * v53);
      *(_QWORD *)((char *)v72 + 4) = v73;
      v74 = (float)(v55 * v54) + (float)(vecV.x * v53);
      v58 = 1.0
          / (float)((float)((float)((float)(v6 * *(float *)&v73) + (float)(*((float *)&v73 + 1) * *(float *)&v70[52]))
                          + (float)(v74 * *(float *)&v70[56]))
                  + *(float *)&v70[60]);
      *((float *)&v72[1] + 1) = v74;
      v59 = (float)((float)((float)((float)(*(float *)&v73 * *(float *)v70)
                                  + (float)(*((float *)&v73 + 1) * *(float *)&v70[4]))
                          + (float)(v74 * *(float *)&v70[8]))
                  + *(float *)&v70[12])
          * v58;
      v60 = (float)((float)((float)(*((float *)&v73 + 1) * *(float *)&v70[36])
                          + (float)(*(float *)&v70[32] * *(float *)&v73))
                  + (float)(v74 * *(float *)&v70[40]))
          + *(float *)&v70[44];
      *((float *)&v73 + 1) = (float)((float)((float)((float)(v10 * *(float *)&v73)
                                                   + (float)(*((float *)&v73 + 1) * *(float *)&v70[20]))
                                           + (float)(v74 * *(float *)&v70[24]))
                                   + *(float *)&v70[28])
                           * v58;
      v61 = v60 * v58;
      v62 = (float)((float)(v56 * *((float *)&v73 + 1)) + (float)(*(float *)&v70[64] * v59)) + (float)(vecV.x * v61);
      *(float *)(LODWORD(x) + 428) = (float)((float)(v57 * *((float *)&v73 + 1)) + (float)(*(float *)&v70[68] * v59))
                                   + (float)(v55 * v61);
      *(float *)(LODWORD(x) + 432) = v62;
      if ( vgui::Image::GetWide(this: (vgui::Image *)&Options) == 0 )
      {
        *(float *)(LODWORD(x) + 488) = *(float *)(LODWORD(x) + 488) * v69;
        *(float *)(LODWORD(x) + 492) = *(float *)(LODWORD(x) + 492) * v69;
        *(float *)(LODWORD(x) + 496) = v68 * *(float *)(LODWORD(x) + 496);
        *(float *)(LODWORD(x) + 500) = *(float *)(LODWORD(x) + 500) * v68;
        CMapOverlay::Material_UpdateParentKey(this: (CMapOverlay *)LODWORD(x));
      }
    }
  }
  if ( *(int *)(LODWORD(x) + 308) <= 0 )
  {
    *(_DWORD *)(LODWORD(x) + 336) = 0;
  }
  else
  {
    v63 = *(_DWORD **)(LODWORD(x) + 296);
    if ( *v63 != 0 )
      *(_DWORD *)(LODWORD(x) + 336) = *v63;
    v64 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(x) + 124))(a1: COERCE_FLOAT(LODWORD(x)));
    if ( v64 != 0 )
    {
      (*(void (__thiscall **)(int, char *))(*(_DWORD *)v64 + 80))(a1: v64, a2: (char *)v72 + 4);
      memset(&vecPos, 0, sizeof(vecPos));
      if ( CMapOverlay::EntityOnSurfFromListToBaseFacePlane(
             this: (CMapOverlay *)LODWORD(x),
             vecWorldPoint: (const Vector *)((char *)v72 + 4),
             vecBasePoint: &vecPos) != 0 )
      {
        z = vecPos.z;
        y = vecPos.y;
        v65 = vecPos.x;
      }
      else
      {
        v65 = *((float *)v72 + 1);
        y = *(float *)&v72[1];
        z = *((float *)&v72[1] + 1);
      }
      *(float *)(LODWORD(x) + 340) = v65;
      *(float *)(LODWORD(x) + 344) = y;
      *(float *)(LODWORD(x) + 348) = z;
    }
    CMapOverlay::Basis_UpdateParentKey(this: (CMapOverlay *)LODWORD(x));
  }
  CMapOverlay::Handles_Build3D(this: (CMapOverlay *)LODWORD(x));
  CMapOverlay::DoClip(this: (CMapOverlay *)LODWORD(x));
  CMapOverlay::Handles_UpdateParentKey(this: (CMapOverlay *)LODWORD(x));
}

//------------------------------------------------------------------------------
// Address: 0x1013B6C0
// Name: public: virtual void CMapOverlay::OnPaste(class CMapClass __near *,class CMapWorld __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::OnPaste(
        CMapOverlay *this,
        CMapClass *pCopy,
        CMapWorld *pSourceWorld,
        CMapWorld *pDestWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  CMapOverlay *v6; // eax
  CMapOverlay *v7; // esi
  CMapFace *v8; // eax

  CMapSideList::OnPaste(this, pCopyObject: pCopy, pSourceWorld, pDestWorld, OriginalList, NewList);
  v6 = (CMapOverlay *)__RTDynamicCast(
                        inptr: pCopy,
                        VfDelta: 0,
                        SrcType: &CMapClass `RTTI Type Descriptor',
                        TargetType: &CMapOverlay `RTTI Type Descriptor',
                        isReference: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    if ( v6->m_Faces.m_Size <= 0 )
    {
      v6->m_Basis.m_pFace = nullptr;
      CMapOverlay::Handles_Build3D(this: v6);
      CMapOverlay::DoClip(this: v7);
    }
    else
    {
      v8 = *v6->m_Faces.m_Memory.m_pMemory;
      if ( v8 != nullptr )
        v7->m_Basis.m_pFace = v8;
      CMapOverlay::Basis_UpdateOrigin(this: v7);
      CMapOverlay::Handles_Build3D(this: v7);
      CMapOverlay::DoClip(this: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B750
// Name: public: virtual void CMapOverlay::OnClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::OnClone(
        CMapOverlay *this,
        CMapClass *pClone,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  CMapOverlay *v6; // eax
  CMapOverlay *v7; // esi
  int m_Size; // ebx
  int i; // edi
  CMapFace *v10; // ecx
  CMapClass *v11; // eax
  CMapFace **m_pMemory; // ecx
  int v13; // eax
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  Vector vecWorldPoint; // [esp+8h] [ebp-18h] BYREF
  Vector vecBasePoint; // [esp+14h] [ebp-Ch] BYREF

  CMapSideList::OnClone(this, pCloneObject: pClone, pWorld, OriginalList, NewList);
  v6 = (CMapOverlay *)__RTDynamicCast(
                        inptr: pClone,
                        VfDelta: 0,
                        SrcType: &CMapClass `RTTI Type Descriptor',
                        TargetType: &CMapOverlay `RTTI Type Descriptor',
                        isReference: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    if ( this->m_uiFlags == 0 )
    {
      m_Size = v6->m_Faces.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v10 = v7->m_Faces.m_Memory.m_pMemory[i];
        v11 = (CMapClass *)v10->GetParent(this: v10);
        CMapClass::UpdateDependency(this: v7, pOldAttached: nullptr, pNewAttached: v11);
      }
    }
    if ( v7->m_Faces.m_Size <= 0 )
    {
      v7->m_Basis.m_pFace = nullptr;
    }
    else
    {
      m_pMemory = v7->m_Faces.m_Memory.m_pMemory;
      if ( *m_pMemory != nullptr )
        v7->m_Basis.m_pFace = *m_pMemory;
      v13 = (int)v7->GetParent(this: v7);
      if ( v13 != 0 )
      {
        (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v13 + 80))(a1: v13, a2: &vecWorldPoint);
        memset(&vecBasePoint, 0, sizeof(vecBasePoint));
        if ( CMapOverlay::EntityOnSurfFromListToBaseFacePlane(this: v7, &vecWorldPoint, &vecBasePoint) != 0 )
        {
          z = vecBasePoint.z;
          y = vecBasePoint.y;
          x = vecBasePoint.x;
        }
        else
        {
          x = vecWorldPoint.x;
          y = vecWorldPoint.y;
          z = vecWorldPoint.z;
        }
        v7->m_Basis.m_vecOrigin.x = x;
        v7->m_Basis.m_vecOrigin.y = y;
        v7->m_Basis.m_vecOrigin.z = z;
      }
      CMapOverlay::Basis_UpdateParentKey(this: v7);
    }
    CMapOverlay::Handles_Build3D(this: v7);
    CMapOverlay::DoClip(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B890
// Name: public: virtual void CMapOverlay::OnNotifyDependent(class CMapClass __near *,enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::OnNotifyDependent(CMapOverlay *this, CMapClass *pObject, Notify_Dependent_t eNotifyType)
{
  CMapSideList::OnNotifyDependent(this, pObject, eNotifyType);
  switch ( eNotifyType )
  {
    case Notify_Changed:
    case Notify_Undo:
    case Notify_Transform:
      CMapOverlay::PostModified(this);
      break;
    case Notify_Removed:
    case Notify_Clipped:
      CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int>>::Purge(this: (CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *)&this->m_aRenderFaces);
      CMapOverlay::PostModified(this);
      break;
    case Notify_Rebuild:
      CMapOverlay::UpdateDispBarycentric(this);
      break;
    case Notify_Rebuild_Full:
      CMapOverlay::DoClip(this);
      CMapOverlay::CenterEntity(this);
      CMapOverlay::Handles_Build3D(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B920
// Name: public: void CMapOverlay::SideList_Init(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::SideList_Init(CMapOverlay *this, CMapFace *pFace)
{
  bool v3; // sf
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CMapFace **m_pMemory; // ecx
  int v7; // eax
  CMapFace **v8; // edi
  CMapClass *v9; // eax
  CMapFace *v10; // eax

  if ( pFace != nullptr )
  {
    v3 = this->m_Faces.m_Memory.m_nGrowSize < 0;
    this->m_Faces.m_Size = 0;
    if ( !v3 )
    {
      if ( this->m_Faces.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: this->m_Faces.m_Memory.m_pMemory);
        this->m_Faces.m_Memory.m_pMemory = nullptr;
      }
      this->m_Faces.m_Memory.m_nAllocationCount = 0;
    }
    this->m_Faces.m_pElements = this->m_Faces.m_Memory.m_pMemory;
    m_nAllocationCount = this->m_Faces.m_Memory.m_nAllocationCount;
    m_Size = this->m_Faces.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_Faces,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Faces.m_Size;
    m_pMemory = this->m_Faces.m_Memory.m_pMemory;
    v7 = this->m_Faces.m_Size - m_Size - 1;
    this->m_Faces.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_Faces.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = pFace;
    if ( this->m_uiFlags == 0 )
    {
      v9 = (CMapClass *)pFace->GetParent(this: pFace);
      CMapClass::UpdateDependency(this, pOldAttached: nullptr, pNewAttached: v9);
      CMapSideList::UpdateParentKey(this);
    }
    this->m_Basis.m_pFace = pFace;
    CMapOverlay::Basis_UpdateOrigin(this);
    CMapOverlay::Basis_BuildAxes(this);
    CMapOverlay::Material_TexCoordInit(this);
    if ( this->m_Faces.m_Size <= 0 )
    {
      this->m_Basis.m_pFace = nullptr;
      CMapOverlay::Handles_Build3D(this);
      CMapOverlay::DoClip(this);
    }
    else
    {
      v10 = *this->m_Faces.m_Memory.m_pMemory;
      if ( v10 != nullptr )
        this->m_Basis.m_pFace = v10;
      CMapOverlay::Basis_UpdateOrigin(this);
      CMapOverlay::Handles_Build3D(this);
      CMapOverlay::DoClip(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BA80
// Name: public: void CMapOverlay::SideList_AddFace(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::SideList_AddFace(CMapOverlay *this, CMapFace *pFace)
{
  CMapFace *v2; // edx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CMapFace **m_pMemory; // ecx
  int v7; // eax
  CMapFace **v8; // edi
  CMapClass *v9; // eax
  CMapFace *v10; // eax

  v2 = pFace;
  if ( pFace != nullptr )
  {
    m_nAllocationCount = this->m_Faces.m_Memory.m_nAllocationCount;
    m_Size = this->m_Faces.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
    {
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_Faces,
        num: m_Size - m_nAllocationCount + 1);
      v2 = pFace;
    }
    ++this->m_Faces.m_Size;
    m_pMemory = this->m_Faces.m_Memory.m_pMemory;
    v7 = this->m_Faces.m_Size - m_Size - 1;
    this->m_Faces.m_pElements = m_pMemory;
    if ( v7 > 0 )
    {
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
      v2 = pFace;
    }
    v8 = &this->m_Faces.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = v2;
    if ( this->m_uiFlags == 0 )
    {
      v9 = (CMapClass *)v2->GetParent(this: v2);
      CMapClass::UpdateDependency(this, pOldAttached: nullptr, pNewAttached: v9);
      CMapSideList::UpdateParentKey(this);
    }
    if ( this->m_Faces.m_Size <= 0 )
    {
      this->m_Basis.m_pFace = nullptr;
    }
    else
    {
      v10 = *this->m_Faces.m_Memory.m_pMemory;
      if ( v10 != nullptr )
        this->m_Basis.m_pFace = v10;
      CMapOverlay::Basis_UpdateOrigin(this);
    }
    CMapOverlay::Handles_Build3D(this);
    CMapOverlay::DoClip(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BB70
// Name: private: void CMapOverlay::PostModified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlay::PostModified(CMapOverlay *this)
{
  CMapFace *v2; // eax

  if ( this->m_Faces.m_Size <= 0 )
  {
    this->m_Basis.m_pFace = nullptr;
    CMapOverlay::Handles_Build3D(this);
    CMapOverlay::DoClip(this);
  }
  else
  {
    v2 = *this->m_Faces.m_Memory.m_pMemory;
    if ( v2 != nullptr )
      this->m_Basis.m_pFace = v2;
    CMapOverlay::Basis_UpdateOrigin(this);
    CMapOverlay::Handles_Build3D(this);
    CMapOverlay::DoClip(this);
  }
}
