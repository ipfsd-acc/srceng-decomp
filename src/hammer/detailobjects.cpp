// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/detailobjects.cpp
// Functions: 55
// ============================================================

#include "hammer\detailobjects.h"

//------------------------------------------------------------------------------
// Address: 0x1000F990
// Name: public: class CUtlReference<class CMapEntity> __near & CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>::Element(int)
// Source: json
//------------------------------------------------------------------------------
const CUtlReference<CMapClass> *__thiscall CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::Element(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this,
        int i)
{
  return &this->m_Memory.m_pMemory[i >> (*((int *)&this->m_Memory + 2) >> 27)][i
                                                                             & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
}

//------------------------------------------------------------------------------
// Address: 0x10010620
// Name: public: CUtlReference<class CMapClass>::~CUtlReference<class CMapClass>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReference<CMapClass>::~CUtlReference<CMapClass>(CUtlReference<CMapClass> *this)
{
  CMapClass *m_pObject; // eax

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CMapClass>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
      which: (CUtlReference<CSheet> *)this);
    this->m_pObject = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018550
// Name: public: void CMapFace::GetPoint(class Vector __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::GetPoint(CMapFace *this, Vector *Point, int nPoint)
{
  *Point = this->Points[nPoint];
}

//------------------------------------------------------------------------------
// Address: 0x10018580
// Name: protected: float DetailObjects::ComputeDisplacementFaceArea(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall DetailObjects::ComputeDisplacementFaceArea(DetailObjects *this, CMapFace *pMapFace)
{
  Vector *Points; // eax
  float v3; // xmm5_4
  float v4; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  float v10; // [esp-Ch] [ebp-5Ch]
  float v11; // [esp-8h] [ebp-58h]
  float edge_12; // [esp+Ch] [ebp-44h]
  float edge_16; // [esp+10h] [ebp-40h]
  float edge_20; // [esp+14h] [ebp-3Ch]
  float edge_32; // [esp+20h] [ebp-30h]

  Points = pMapFace->Points;
  v3 = Points[2].z - Points[1].z;
  v4 = Points[2].x - Points[1].x;
  v5 = Points->x - Points[3].x;
  v10 = Points[1].x - Points->x;
  v6 = Points[2].y - Points[1].y;
  v7 = Points[1].z - Points->z;
  edge_16 = Points[3].y - Points[2].y;
  edge_20 = Points[3].z - Points[2].z;
  v11 = Points[1].y - Points->y;
  edge_32 = Points->z - Points[3].z;
  edge_12 = Points[3].x - Points[2].x;
  v8 = Points->y - Points[3].y;
  return (fsqrt(
            (float)((float)((float)((float)(v5 * edge_20) - (float)(edge_32 * edge_12))
                          * (float)((float)(v5 * edge_20) - (float)(edge_32 * edge_12)))
                  + (float)((float)((float)(v8 * edge_12) - (float)(v5 * edge_16))
                          * (float)((float)(v8 * edge_12) - (float)(v5 * edge_16))))
          + (float)((float)((float)(edge_32 * edge_16) - (float)(v8 * edge_20))
                  * (float)((float)(edge_32 * edge_16) - (float)(v8 * edge_20))))
        + fsqrt(
            (float)((float)((float)((float)(v4 * v7) - (float)(v3 * v10)) * (float)((float)(v4 * v7) - (float)(v3 * v10)))
                  + (float)((float)((float)(v6 * v10) - (float)(v4 * v11))
                          * (float)((float)(v6 * v10) - (float)(v4 * v11))))
          + (float)((float)((float)(v3 * v11) - (float)(v6 * v7)) * (float)((float)(v3 * v11) - (float)(v6 * v7)))))
       * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x10018710
// Name: public: static void DetailObjects::EnableBuildDetailObjects(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DetailObjects::EnableBuildDetailObjects(bool bEnable)
{
  DetailObjects::s_bBuildDetailObjects = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100187C0
// Name: protected: int DetailObjects::SelectGroup(struct DetailObjects::DetailObject_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall DetailObjects::SelectGroup(
        DetailObjects *this,
        const DetailObjects::DetailObject_t *detail,
        float alpha)
{
  int m_Size; // ebx
  int v5; // eax
  int v6; // esi
  DetailObjects::DetailObjectGroup_t *v7; // ecx
  DetailObjects::DetailObjectGroup_t *v8; // ecx
  int v9; // edi
  int result; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float dist; // [esp+8h] [ebp+8h]

  m_Size = detail->m_Groups.m_Size;
  v5 = m_Size - 1;
  v6 = 0;
  if ( m_Size - 1 < 4 )
  {
LABEL_8:
    if ( v6 < v5 )
    {
      v8 = &detail->m_Groups.m_Memory.m_pMemory[v6 + 1];
      do
      {
        if ( v8->m_Alpha > alpha )
          break;
        ++v6;
        ++v8;
      }
      while ( v6 < v5 );
    }
  }
  else
  {
    v7 = detail->m_Groups.m_Memory.m_pMemory + 2;
    while ( v7[-1].m_Alpha <= alpha )
    {
      if ( v7->m_Alpha > alpha )
      {
        ++v6;
        break;
      }
      if ( v7[1].m_Alpha > alpha )
      {
        v6 += 2;
        break;
      }
      if ( v7[2].m_Alpha > alpha )
      {
        v6 += 3;
        break;
      }
      v6 += 4;
      v7 += 4;
      if ( v6 >= m_Size - 4 )
        goto LABEL_8;
    }
  }
  v9 = v6 + 1;
  if ( v6 + 1 >= m_Size )
    v9 = v6;
  if ( v6 == v9 )
    return v6;
  v11 = detail->m_Groups.m_Memory.m_pMemory[v9].m_Alpha - detail->m_Groups.m_Memory.m_pMemory[v6].m_Alpha;
  dist = 0.0;
  if ( v11 != 0.0 )
    dist = (float)(alpha - detail->m_Groups.m_Memory.m_pMemory[v6].m_Alpha) / v11;
  v12 = (float)rand() * 0.000030518509;
  result = v6;
  if ( v12 <= dist )
    return v9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100188C0
// Name: public: virtual void DetailObjects::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall DetailObjects::Render3D(DetailObjects *this, int pRender)
{
  CRender3D *v2; // ebx
  DetailObjects *v3; // esi
  CCamera *Camera; // eax
  int i; // edi
  CCamera *v6; // esi
  int v7; // edi
  int v8; // esi
  CSpriteModel *v9; // edi
  Vector flAlpha; // [esp+0h] [ebp-30h] BYREF
  Vector ViewRight; // [esp+Ch] [ebp-24h] BYREF
  Vector boxMax; // [esp+18h] [ebp-18h] BYREF
  float nDetailDistance; // [esp+24h] [ebp-Ch]
  int m_Size; // [esp+28h] [ebp-8h]
  DetailObjects *Maxs; // [esp+2Ch] [ebp-4h] OVERLAPPED

  v2 = (CRender3D *)pRender;
  v3 = this;
  Maxs = this;
  nDetailDistance = (float)Options.view3d.nDetailDistance;
  Camera = CRender::GetCamera(this: (CRender *)pRender);
  CCamera::GetViewPoint(this: Camera, ViewPoint: &flAlpha);
  m_Size = v3->m_DetailModels.m_Size;
  if ( m_Size != 0 )
  {
    CRender::PushRenderMode(this: v2, eRenderMode: RENDER_MODE_DEFAULT);
    for ( i = 0; i < m_Size; ++i )
    {
      v6 = (CCamera *)v3->m_DetailModels.m_Memory.m_pMemory[i];
      CCamera::GetViewRight(this: v6, &ViewRight);
      CCamera::GetViewRight(this: v6, ViewRight: &boxMax);
      ViewRight.x = ViewRight.x - nDetailDistance;
      boxMax.x = boxMax.x + nDetailDistance;
      ViewRight.y = ViewRight.y - nDetailDistance;
      boxMax.y = boxMax.y + nDetailDistance;
      ViewRight.z = ViewRight.z - nDetailDistance;
      boxMax.z = boxMax.z + nDetailDistance;
      if ( IsPointInBox(pt: &flAlpha, boxMin: &ViewRight, &boxMax) )
      {
        pRender = -1;
        StudioModel::DrawModel3D(
          this: (StudioModel *)v6,
          pRender: v2,
          color: (const Color *)&pRender,
          flAlpha: 1.0,
          bWireframe: false);
      }
      v3 = Maxs;
    }
    CRender::PopRenderMode(this: v2);
  }
  v7 = v3->m_DetailSprites.m_Size;
  m_Size = v7;
  if ( v7 != 0 )
  {
    LOWORD(pRender) = -1;
    BYTE2(pRender) = -1;
    CRender::PushRenderMode(this: v2, eRenderMode: RENDER_MODE_DEFAULT);
    v8 = 0;
    if ( v7 > 0 )
    {
      do
      {
        v9 = Maxs->m_DetailSprites.m_Memory.m_pMemory[v8];
        CSpriteModel::GetOrigin(this: v9, v: &ViewRight);
        CSpriteModel::GetOrigin(this: v9, v: &boxMax);
        ViewRight.x = ViewRight.x - nDetailDistance;
        boxMax.x = boxMax.x + nDetailDistance;
        ViewRight.y = ViewRight.y - nDetailDistance;
        boxMax.y = boxMax.y + nDetailDistance;
        ViewRight.z = ViewRight.z - nDetailDistance;
        boxMax.z = boxMax.z + nDetailDistance;
        if ( IsPointInBox(pt: &flAlpha, boxMin: &ViewRight, &boxMax) )
          CSpriteModel::DrawSprite3D(this: v9, pRender: v2, color: (unsigned __int8 *)&pRender);
        ++v8;
      }
      while ( v8 < m_Size );
    }
    CRender::PopRenderMode(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018CA0
// Name: public: DetailObjects::DetailObjects(void)
// Source: json
//------------------------------------------------------------------------------
DetailObjects *__thiscall DetailObjects::DetailObjects(DetailObjects *this)
{
  CSpriteModel **m_pMemory; // edx

  CMapPoint::CMapPoint(this);
  this->__vftable = (CMapPoint_vtbl *)&DetailObjects::`vftable';
  this->m_DetailSprites.m_Memory.m_pMemory = nullptr;
  this->m_DetailSprites.m_Memory.m_nAllocationCount = 0;
  this->m_DetailSprites.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_DetailSprites.m_Memory.m_pMemory;
  this->m_DetailSprites.m_Size = 0;
  this->m_DetailSprites.m_pElements = m_pMemory;
  this->m_DetailModels.m_Memory.m_pMemory = nullptr;
  this->m_DetailModels.m_Memory.m_nAllocationCount = 0;
  this->m_DetailModels.m_Memory.m_nGrowSize = 0;
  this->m_DetailModels.m_Size = 0;
  this->m_DetailModels.m_pElements = this->m_DetailModels.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018D20
// Name: public: virtual enum SelectionState_t CMapAtom::SetSelectionState(enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
SelectionState_t __thiscall CMapAtom::SetSelectionState(CMapAtom *this, SelectionState_t eSelectionState)
{
  SelectionState_t result; // eax

  result = this->m_eSelectionState;
  this->m_eSelectionState = eSelectionState;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018D30
// Name: public: virtual void CMapAtom::SetRenderColor(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAtom::SetRenderColor(
        CMapAtom *this,
        unsigned __int8 red,
        unsigned __int8 green,
        unsigned __int8 blue)
{
  this->r = red;
  this->g = green;
  this->b = blue;
}

//------------------------------------------------------------------------------
// Address: 0x10018D50
// Name: public: virtual void CMapAtom::SetRenderColor(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAtom::SetRenderColor(CMapAtom *this, color32_s rgbColor)
{
  this->r = rgbColor.r;
  this->g = rgbColor.g;
  this->b = rgbColor.b;
}

//------------------------------------------------------------------------------
// Address: 0x10018D70
// Name: public: virtual bool CMapAtom::GetTransformMatrix(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapAtom::GetTransformMatrix(CMapAtom *this, VMatrix *matrix)
{
  CMapAtom *v2; // eax

  v2 = this->GetParent(this);
  return v2 != nullptr && v2->GetTransformMatrix(this: v2, a2: matrix);
}

//------------------------------------------------------------------------------
// Address: 0x10018D90
// Name: public: DetailObjects::~DetailObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DetailObjects::~DetailObjects(DetailObjects *this)
{
  CUtlVector<StudioModel *,CUtlMemory<StudioModel *,int> > *p_m_DetailModels; // edi
  CUtlVector<CSpriteModel *,CUtlMemory<CSpriteModel *,int> > *p_m_DetailSprites; // esi

  this->__vftable = (CMapPoint_vtbl *)&DetailObjects::`vftable';
  p_m_DetailModels = &this->m_DetailModels;
  CUtlVector<StudioModel *,CUtlMemory<StudioModel *,int>>::PurgeAndDeleteElements(this: &this->m_DetailModels);
  p_m_DetailSprites = &this->m_DetailSprites;
  CUtlVector<CSpriteModel *,CUtlMemory<CSpriteModel *,int>>::PurgeAndDeleteElements(this: p_m_DetailSprites);
  p_m_DetailModels->m_Size = 0;
  if ( p_m_DetailModels->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DetailModels->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_DetailModels->m_Memory.m_pMemory);
      p_m_DetailModels->m_Memory.m_pMemory = nullptr;
    }
    p_m_DetailModels->m_Memory.m_nAllocationCount = 0;
  }
  p_m_DetailModels->m_pElements = p_m_DetailModels->m_Memory.m_pMemory;
  if ( p_m_DetailModels->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DetailModels->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_DetailModels->m_Memory.m_pMemory);
      p_m_DetailModels->m_Memory.m_pMemory = nullptr;
    }
    p_m_DetailModels->m_Memory.m_nAllocationCount = 0;
  }
  p_m_DetailSprites->m_Size = 0;
  if ( p_m_DetailSprites->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DetailSprites->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_DetailSprites->m_Memory.m_pMemory);
      p_m_DetailSprites->m_Memory.m_pMemory = nullptr;
    }
    p_m_DetailSprites->m_Memory.m_nAllocationCount = 0;
  }
  p_m_DetailSprites->m_pElements = p_m_DetailSprites->m_Memory.m_pMemory;
  if ( p_m_DetailSprites->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DetailSprites->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_DetailSprites->m_Memory.m_pMemory);
      p_m_DetailSprites->m_Memory.m_pMemory = nullptr;
    }
    p_m_DetailSprites->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018E80
// Name: public: CUtlReference<class CMapEntity>::~CUtlReference<class CMapEntity>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReference<CMapEntity>::~CUtlReference<CMapEntity>(CUtlReference<CMapEntity> *this)
{
  CMapEntity *m_pObject; // eax

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CMapClass>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
      which: (CUtlReference<CSheet> *)this);
    this->m_pObject = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018EA0
// Name: protected: void DetailObjects::AddDetailModelToFace(char const __near *,class Vector const __near &,class QAngle const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DetailObjects::AddDetailModelToFace(
        DetailObjects *this,
        char *pModelName,
        const Vector *pt,
        const QAngle *angles,
        const char *nOrientation)
{
  StudioModel *v6; // eax
  StudioModel *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  StudioModel **m_pMemory; // ecx
  int v11; // eax
  StudioModel **v12; // eax
  float v13; // eax
  QAngle z; // [esp+8h] [ebp-1Ch] BYREF
  QAngle modelangle; // [esp+14h] [ebp-10h]
  int v16; // [esp+20h] [ebp-4h]

  v6 = (StudioModel *)operator new(nSize: 0xA8u);
  LODWORD(modelangle.x) = v6;
  v7 = nullptr;
  v16 = 0;
  if ( v6 != nullptr )
    v7 = StudioModel::StudioModel(this: v6);
  v16 = -1;
  m_Size = this->m_DetailModels.m_Size;
  m_nAllocationCount = this->m_DetailModels.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_DetailModels,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_DetailModels.m_Size;
  m_pMemory = this->m_DetailModels.m_Memory.m_pMemory;
  v11 = this->m_DetailModels.m_Size - m_Size - 1;
  this->m_DetailModels.m_pElements = m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &this->m_DetailModels.m_Memory.m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = v7;
  StudioModel::LoadModel(this: v7, modelname: pModelName);
  StudioModel::SetOrigin(this: v7, x: pt->x, y: pt->y, z: pt->z);
  v13 = angles->z;
  *(_QWORD *)&z.x = *(_QWORD *)&angles->x;
  z.z = v13;
  StudioModel::SetAngles(this: v7, pfAngles: &z);
}

//------------------------------------------------------------------------------
// Address: 0x10018FA0
// Name: protected: void DetailObjects::AddDetailSpriteToFace(class Vector const __near &,class QAngle const __near &,class DetailObjects::DetailModel_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall DetailObjects::AddDetailSpriteToFace(
        DetailObjects *this,
        const Vector *vecOrigin,
        const Vector *vecAngles,
        const QAngle *model,
        float flScale)
{
  CSpriteModel *v6; // eax
  CSpriteModel *v7; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CSpriteModel **m_pMemory; // ecx
  int v11; // eax
  CSpriteModel **v12; // ebx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  _BYTE pszSpritePath[264]; // [esp+Ch] [ebp-114h] OVERLAPPED BYREF
  int v20; // [esp+11Ch] [ebp-4h]

  v6 = (CSpriteModel *)operator new(nSize: 0x6Cu);
  *(_DWORD *)&pszSpritePath[260] = v6;
  v7 = nullptr;
  v20 = 0;
  if ( v6 != nullptr )
    v7 = CSpriteModel::CSpriteModel(this: v6);
  v20 = -1;
  m_Size = this->m_DetailSprites.m_Size;
  m_nAllocationCount = this->m_DetailSprites.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_DetailSprites,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_DetailSprites.m_Size;
  m_pMemory = this->m_DetailSprites.m_Memory.m_pMemory;
  v11 = this->m_DetailSprites.m_Size - m_Size - 1;
  this->m_DetailSprites.m_pElements = m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &this->m_DetailSprites.m_Memory.m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = v7;
  strcpy(pszSpritePath, "detail/detailsprites");
  memset(dst: &pszSpritePath[21], value: 0, count: 0xEFu);
  CSpriteModel::LoadSprite(this: v7, pszSpritePath);
  CSpriteModel::SetRenderMode(this: v7, mode: 0);
  CSpriteModel::SetMaterialPrimitiveType(this: v7, type: MATERIAL_POLYGON);
  CSpriteModel::SetOrigin(this: v7, v: vecOrigin);
  CSpriteModel::SetAngles(this: v7, pfAngles: (const QAngle *)vecAngles);
  CSpriteModel::SetScale(this: v7, fScale: flScale);
  CSpriteModel::SetInvert(this: v7, b: true);
  x = model[3].x;
  y = model[3].y;
  z = model[2].z;
  v7->m_UL.x = model[2].y;
  v7->m_UL.y = z;
  v7->m_LR.x = x;
  v7->m_LR.y = y;
  v16 = model[4].y;
  v17 = model[4].z;
  v18 = model[4].x;
  v7->m_TexUL.x = model[3].z;
  v7->m_TexUL.y = v18;
  v7->m_TexLR.x = v16;
  v7->m_TexLR.y = v17;
}

//------------------------------------------------------------------------------
// Address: 0x10019140
// Name: protected: void DetailObjects::PlaceDetail(class DetailObjects::DetailModel_t const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DetailObjects::PlaceDetail(
        DetailObjects *this,
        const QAngle *model,
        const Vector *pt,
        const Vector *normal)
{
  float z; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  const VMatrix *v11; // eax
  float v12; // xmm2_4
  char *v13; // eax
  const char *z_low; // [esp+4h] [ebp-10Ch]
  VMatrix result; // [esp+14h] [ebp-FCh] BYREF
  VMatrix vm; // [esp+54h] [ebp-BCh] BYREF
  VMatrix src; // [esp+94h] [ebp-7Ch] BYREF
  Vector v18; // [esp+D4h] [ebp-3Ch] BYREF
  Vector vAxis; // [esp+E0h] [ebp-30h] BYREF
  QAngle angles; // [esp+ECh] [ebp-24h] BYREF
  Vector yaxis; // [esp+F8h] [ebp-18h] BYREF
  Vector xaxis; // [esp+104h] [ebp-Ch] BYREF
  float v23; // [esp+120h] [ebp+10h]
  float v24; // [esp+120h] [ebp+10h]

  z = normal->z;
  if ( model[1].x <= z )
  {
    v7 = model->z;
    if ( v7 <= z
      || (v23 = (float)(z - model[1].x) / (float)(v7 - model[1].x), (float)((float)rand() * 0.000030518509) <= v23) )
    {
      if ( (LOBYTE(model[1].y) & 1) != 0 )
      {
        vAxis.x = 0.0;
        vAxis.y = (float)((float)rand() * 360.0) * 0.000030518509;
        vAxis.z = 0.0;
      }
      else
      {
        xaxis = *normal;
        VectorNormalize(vec: &xaxis);
        v8 = 1.0;
        v9 = 0.0;
        yaxis.x = 1.0;
        yaxis.y = 0.0;
        yaxis.z = 0.0;
        if ( (float)(COERCE_FLOAT(
                       COERCE_UNSIGNED_INT((float)((float)(xaxis.y * 0.0) + xaxis.x) + (float)(xaxis.z * 0.0))
                     & _mask__AbsFloat_)
                   - 1.0) > -0.001 )
        {
          v8 = 0.0;
          v9 = 1.0;
          yaxis.x = 0.0;
          yaxis.y = 1.0;
          yaxis.z = 0.0;
        }
        angles.x = (float)(xaxis.y * 0.0) - (float)(v9 * xaxis.z);
        angles.y = (float)(xaxis.z * v8) - (float)(xaxis.x * 0.0);
        angles.z = (float)(v9 * xaxis.x) - (float)(xaxis.y * v8);
        VectorNormalize(vec: (Vector *)&angles);
        yaxis.x = (float)(angles.y * xaxis.z) - (float)(angles.z * xaxis.y);
        yaxis.y = (float)(angles.z * xaxis.x) - (float)(xaxis.z * angles.x);
        yaxis.z = (float)(xaxis.y * angles.x) - (float)(angles.y * xaxis.x);
        VectorNormalize(vec: &yaxis);
        *(_QWORD *)&src.m[0][0] = __PAIR64__(LODWORD(angles.x), LODWORD(yaxis.x));
        *(_QWORD *)&src.m[1][0] = __PAIR64__(LODWORD(angles.y), LODWORD(yaxis.y));
        *(_QWORD *)&src.m[2][0] = __PAIR64__(LODWORD(angles.z), LODWORD(yaxis.z));
        *(_QWORD *)&src.m[0][2] = __PAIR64__(LODWORD(vec3_origin.x), LODWORD(xaxis.x));
        *(_QWORD *)&src.m[1][2] = __PAIR64__(LODWORD(vec3_origin.y), LODWORD(xaxis.y));
        *(_QWORD *)&src.m[2][2] = __PAIR64__(LODWORD(vec3_origin.z), LODWORD(xaxis.z));
        v10 = (float)((float)rand() * 360.0) * 0.000030518509;
        v18.x = 0.0;
        v18.y = 0.0;
        v18.z = 1.0;
        SetupMatrixAxisRot(result: &vm, vAxis: &v18, fDegrees: v10);
        v11 = VMatrix::operator*(this: &src, &result, &vm);
        VMatrix::operator=(this: &src, mOther: v11);
        MatrixAngles(&src, vAngles: (QAngle *)&vAxis);
      }
      if ( LODWORD(model[2].x) != 0 )
      {
        v12 = 1.0;
        if ( model[5].x != 0.0 )
        {
          v24 = fabs(_RandomGaussianFloat(a1: 1065353216, a2: LODWORD(model[5].x)));
          v12 = v24;
        }
        DetailObjects::AddDetailSpriteToFace(this, vecOrigin: pt, vecAngles: &vAxis, model, flScale: v12);
      }
      else
      {
        z_low = (const char *)LODWORD(model[1].z);
        v13 = (char *)CUtlSymbol::String(this: (CUtlSymbol *)model);
        DetailObjects::AddDetailModelToFace(
          this,
          pModelName: v13,
          pt,
          angles: (const QAngle *)&vAxis,
          nOrientation: z_low);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100196D0
// Name: protected: static void DetailObjects::ParseDetailGroup(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DetailObjects::ParseDetailGroup(int detailId, KeyValues *pGroupKeyValues)
{
  KeyValues *v2; // edi
  int v3; // esi
  int v4; // eax
  DetailObjects::DetailObjectGroup_t *v5; // ecx
  DetailObjects::DetailObjectGroup_t *v6; // ecx
  DetailObjects::DetailObjectGroup_t *v7; // esi
  KeyValues *FirstSubKey; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  DetailObjects::DetailModel_t *m_pMemory; // ecx
  int v12; // eax
  DetailObjects::DetailModel_t *v13; // eax
  bool v14; // zf
  DetailObjects::DetailModel_t *v15; // eax
  DetailObjects::DetailModel_t *v16; // esi
  const char *String; // eax
  __int16 v18; // ax
  const char *v19; // eax
  const char *v20; // ebx
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  const char *v25; // eax
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  double v29; // st7
  float v30; // xmm0_4
  double v31; // st7
  float v32; // xmm0_4
  double v33; // st7
  double v34; // st7
  int Int; // eax
  float m_MaxCosAngle; // xmm0_4
  bool v37; // cc
  int v38; // ecx
  int v39; // edx
  const char *v40; // [esp+4h] [ebp-2Ch]
  float v41; // [esp+4h] [ebp-2Ch]
  float v42; // [esp+4h] [ebp-2Ch]
  float v43; // [esp+4h] [ebp-2Ch]
  DetailObjects::DetailObjectGroup_t *v44; // [esp+8h] [ebp-28h]
  float Float; // [esp+Ch] [ebp-24h]
  float v46; // [esp+Ch] [ebp-24h]
  vgui::ToolWindow *v47; // [esp+10h] [ebp-20h] BYREF
  const char *pSpriteData; // [esp+14h] [ebp-1Ch] BYREF
  DetailObjects::DetailObjectGroup_t *group; // [esp+18h] [ebp-18h] BYREF
  float alpha; // [esp+1Ch] [ebp-14h] BYREF
  float flTextureSize; // [esp+20h] [ebp-10h] BYREF
  float x; // [esp+2Ch] [ebp-4h]

  v2 = pGroupKeyValues;
  Float = KeyValues::GetFloat(this: pGroupKeyValues, keyName: "alpha", defaultValue: 1.0);
  v3 = detailId;
  v4 = DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[detailId].m_Groups.m_Size - 1;
  if ( v4 >= 0 )
  {
    if ( DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[detailId].m_Groups.m_Size < 4 )
    {
LABEL_9:
      if ( v4 >= 0 )
      {
        v6 = &DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[v3].m_Groups.m_Memory.m_pMemory[v4];
        do
        {
          if ( Float > v6->m_Alpha )
            break;
          --v6;
          --v4;
        }
        while ( v4 >= 0 );
      }
    }
    else
    {
      v5 = &DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[v3].m_Groups.m_Memory.m_pMemory[v4 - 2];
      while ( Float <= v5[2].m_Alpha )
      {
        if ( Float > v5[1].m_Alpha )
        {
          --v4;
          break;
        }
        if ( Float > v5->m_Alpha )
        {
          v4 -= 2;
          break;
        }
        if ( Float > v5[-1].m_Alpha )
        {
          v4 -= 3;
          break;
        }
        v4 -= 4;
        v5 -= 4;
        if ( v4 < 3 )
          goto LABEL_9;
      }
    }
  }
  v7 = &DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[v3].m_Groups.m_Memory.m_pMemory[CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>::InsertBefore(
                                                                                               this: &DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[v3].m_Groups,
                                                                                               elem: v4 + 1)];
  v44 = v7;
  v7->m_Alpha = Float;
  FirstSubKey = KeyValues::GetFirstSubKey(this: v2);
  v46 = 0.0;
  if ( FirstSubKey != nullptr )
  {
    do
    {
      if ( KeyValues::GetFirstSubKey(this: FirstSubKey) != nullptr )
      {
        m_Size = v7->m_Models.m_Size;
        m_nAllocationCount = v7->m_Models.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<DetailObjects::DetailModel_t,int>::Grow(
            this: &v7->m_Models.m_Memory,
            num: m_Size - m_nAllocationCount + 1);
        ++v7->m_Models.m_Size;
        m_pMemory = v7->m_Models.m_Memory.m_pMemory;
        v12 = v7->m_Models.m_Size - m_Size - 1;
        v7->m_Models.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 68 * v12);
        v13 = v7->m_Models.m_Memory.m_pMemory;
        v14 = &v13[m_Size] == nullptr;
        v15 = &v13[m_Size];
        x = 0.0;
        if ( !v14 )
        {
          v15->m_MinCosAngle = -1.0;
          v15->m_MaxCosAngle = -1.0;
          v15->m_Amount = 0.0;
          v15->m_Flags = 0;
          v15->m_Orientation = 0;
          v15->m_Type = 1;
          v15->m_ModelName.m_Id = -1;
          v15->m_Pos[0].x = -10.0;
          v15->m_Pos[0].y = 20.0;
          v15->m_Pos[1].x = 10.0;
          v15->m_Pos[1].y = 0.0;
          v15->m_Tex[0].x = 0.0009765625;
          v15->m_Tex[0].y = 0.0009765625;
          v15->m_Tex[1].x = 0.12402344;
          v15->m_Tex[1].y = 0.12402344;
          v15->m_flRandomScaleStdDev = 0.0;
          *(_WORD *)&v15->m_ShapeSize = 0;
          v15->m_SwayAmount = 0;
        }
        x = NAN;
        v16 = &v7->m_Models.m_Memory.m_pMemory[m_Size];
        String = KeyValues::GetString(this: FirstSubKey, keyName: "model", defaultValue: nullptr);
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&detailId + 1, pStr: String);
        v18 = HIWORD(detailId);
        v16->m_ModelName.m_Id = HIWORD(detailId);
        if ( v18 == -1 )
        {
          v40 = KeyValues::GetString(this: FirstSubKey, keyName: "sprite", defaultValue: nullptr);
          if ( v40 != nullptr )
          {
            v19 = KeyValues::GetString(this: FirstSubKey, keyName: "sprite_shape", defaultValue: nullptr);
            v20 = v19;
            if ( v19 != nullptr )
            {
              if ( _V_stricmp(s1: v19, s2: "cross") != 0 )
                v16->m_Type = _V_stricmp(s1: v20, s2: "tri") != 0 ? 1 : 3;
              else
                v16->m_Type = 2;
            }
            else
            {
              v16->m_Type = 1;
            }
            v16->m_Tex[0].x = 0.0;
            v16->m_Tex[0].y = 0.0;
            v16->m_Tex[1].x = 0.0;
            v16->m_Tex[1].y = 0.0;
            alpha = 0.0;
            *(float *)&pSpriteData = 0.0;
            flTextureSize = 64.0;
            *(float *)&group = 64.0;
            *(float *)&v47 = 512.0;
            if ( sscanf(string: v40, format: "%f %f %f %f %f", &alpha, &pSpriteData, &flTextureSize, &group, &v47) != 5
              || *(float *)&v47 == 0.0 )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105D8AC4, a2: (const char *)v16->m_ModelName.m_Id);
            }
            v21 = 1.0 / *(float *)&v47;
            v22 = *(float *)&group + *(float *)&pSpriteData;
            v23 = alpha;
            v16->m_Tex[0].y = (float)(*(float *)&pSpriteData + 0.5) * (float)(1.0 / *(float *)&v47);
            v24 = flTextureSize + alpha;
            v16->m_Tex[0].x = (float)(v23 + 0.5) * v21;
            v16->m_Tex[1].x = (float)(v24 - 0.5) * v21;
            v16->m_Tex[1].y = (float)(v22 - 0.5) * v21;
            v16->m_Pos[0].x = -10.0;
            v16->m_Pos[0].y = 20.0;
            v16->m_Pos[1].x = 10.0;
            v16->m_Pos[1].y = 0.0;
            v25 = KeyValues::GetString(this: FirstSubKey, keyName: "spritesize", defaultValue: nullptr);
            if ( v25 != nullptr )
            {
              sscanf(string: v25, format: "%f %f %f %f", &alpha, &pSpriteData, &flTextureSize, &group);
              v26 = *(float *)&group * *(float *)&pSpriteData;
              v27 = *(float *)&group - (float)(*(float *)&group * *(float *)&pSpriteData);
              v28 = flTextureSize - (float)(flTextureSize * alpha);
              v16->m_Pos[0].x = -(float)(flTextureSize * alpha);
              v16->m_Pos[0].y = v27;
              v16->m_Pos[1].x = v28;
              v16->m_Pos[1].y = -v26;
            }
            v16->m_flRandomScaleStdDev = KeyValues::GetFloat(
                                           this: FirstSubKey,
                                           keyName: "spriterandomscale",
                                           defaultValue: 0.0);
            v29 = KeyValues::GetFloat(this: FirstSubKey, keyName: "sway", defaultValue: 0.0);
            if ( v29 >= 0.0 )
            {
              v30 = v29;
              v41 = v29;
              if ( v41 > 1.0 )
                v30 = 1.0;
            }
            else
            {
              v30 = 0.0;
            }
            v16->m_SwayAmount = (int)(v30 * 255.0);
            v16->m_ShapeAngle = KeyValues::GetInt(this: FirstSubKey, keyName: "shape_angle", defaultValue: 0);
            v31 = KeyValues::GetFloat(this: FirstSubKey, keyName: "shape_size", defaultValue: 0.0);
            if ( v31 >= 0.0 )
            {
              v32 = v31;
              v42 = v31;
              if ( v42 > 1.0 )
                v32 = 1.0;
            }
            else
            {
              v32 = 0.0;
            }
            v16->m_ShapeSize = (int)(v32 * 255.0);
          }
        }
        else
        {
          v16->m_Type = 0;
        }
        v33 = KeyValues::GetFloat(this: FirstSubKey, keyName: "amount", defaultValue: 1.0) + v46;
        v16->m_Amount = v33;
        v46 = v33;
        v16->m_Flags = 0;
        if ( KeyValues::GetInt(this: FirstSubKey, keyName: "upright", defaultValue: 0) != 0 )
          v16->m_Flags |= 1u;
        v43 = KeyValues::GetFloat(this: FirstSubKey, keyName: "minAngle", defaultValue: 180.0);
        v34 = KeyValues::GetFloat(this: FirstSubKey, keyName: "maxAngle", defaultValue: 180.0);
        v16->m_MinCosAngle = cos(v43 * 3.141592653589793 * 0.005555555555555556);
        v16->m_MaxCosAngle = cos(v34 * 3.141592653589793 * 0.005555555555555556);
        Int = KeyValues::GetInt(this: FirstSubKey, keyName: "detailOrientation", defaultValue: 0);
        m_MaxCosAngle = v16->m_MaxCosAngle;
        v37 = m_MaxCosAngle <= v16->m_MinCosAngle;
        v16->m_Orientation = Int;
        if ( !v37 )
          v16->m_MinCosAngle = m_MaxCosAngle;
        v7 = v44;
      }
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    }
    while ( FirstSubKey != nullptr );
    if ( v46 > 1.0 )
    {
      v38 = 0;
      if ( v7->m_Models.m_Size > 0 )
      {
        v39 = 0;
        do
        {
          ++v38;
          v7->m_Models.m_Memory.m_pMemory[v39].m_Amount = (float)(1.0 / v46)
                                                        * v7->m_Models.m_Memory.m_pMemory[v39].m_Amount;
          ++v39;
        }
        while ( v38 < v7->m_Models.m_Size );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019DF0
// Name: public: DetailObjects::DetailObject_t::~DetailObject_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DetailObjects::DetailObject_t::~DetailObject_t(DetailObjects::DetailObject_t *this)
{
  CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>::~CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>(this: &this->m_Groups);
}

//------------------------------------------------------------------------------
// Address: 0x1001A090
// Name: protected: void DetailObjects::EmitDetailObjectsOnDisplacementFace(class CMapFace __near *,struct DetailObjects::DetailObject_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DetailObjects::EmitDetailObjectsOnDisplacementFace(
        DetailObjects *this,
        float pMapFace,
        DetailObjects::DetailObject_t *detail)
{
  CMapDoc *v3; // esi
  DetailObjects::DetailObject_t *v5; // ebx
  int v6; // edx
  int v7; // edi
  DetailObjects::DetailObject_t *v8; // esi
  IEditDispMgr *v9; // eax
  int v10; // eax
  float v11; // xmm0_4
  int v12; // esi
  int v13; // eax
  DetailObjects::DetailObjectGroup_t *m_pMemory; // esi
  int v15; // edi
  int v16; // eax
  int m_Size; // ecx
  float v18; // xmm0_4
  int v19; // eax
  float *p_m_Amount; // esi
  int i; // esi
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > v22; // [esp+20h] [ebp-44h] BYREF
  Vector pNormal; // [esp+34h] [ebp-30h] BYREF
  Vector v24; // [esp+40h] [ebp-24h] BYREF
  Vector normal; // [esp+4Ch] [ebp-18h]
  Vector pt; // [esp+58h] [ebp-Ch]

  v3 = CMapDoc::m_pMapDoc;
  LODWORD(normal.z) = this;
  memset(&v22, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&v22,
    nGrowSize: 0,
    nInitSize: 0);
  v22.m_Size = 0;
  v22.m_pElements = nullptr;
  LODWORD(pt.z) = 3;
  CMapDoc::FindEntitiesByClassName(
    this: v3,
    Found: (CUtlReferenceVector<CMapEntity> *)&v22,
    pszClassName: "func_detail_blocker",
    bVisiblesOnly: false);
  pMapFace = DetailObjects::ComputeDisplacementFaceArea(this, pMapFace: (CMapFace *)LODWORD(pMapFace));
  v5 = detail;
  v7 = *(unsigned __int16 *)(v6 + 420);
  v8 = (DetailObjects::DetailObject_t *)(int)((float)(detail->m_Density * pMapFace) * 0.000001);
  v9 = EditDispMgr();
  LODWORD(normal.x) = &v9->GetDisp(this: v9, a2: v7)->m_CoreDispInfo;
  if ( (int)v8 > 0 )
  {
    for ( detail = v8; detail != nullptr; detail = (DetailObjects::DetailObject_t *)((char *)detail - 1) )
    {
      normal.y = (float)rand() * 0.000030518509;
      v10 = rand();
      CCoreDispInfo::GetPositionOnSurface(
        this: (CCoreDispInfo *)LODWORD(normal.x),
        u: normal.y,
        v: (float)v10 * 0.000030518509,
        vPos: &v24,
        &pNormal,
        pAlpha: &pMapFace);
      v11 = pMapFace * 0.0039215689;
      v12 = 0;
      pMapFace = pMapFace * 0.0039215689;
      if ( v22.m_Size <= 0 )
      {
LABEL_7:
        v13 = DetailObjects::SelectGroup(this: (DetailObjects *)LODWORD(normal.z), detail: v5, alpha: v11);
        m_pMemory = v5->m_Groups.m_Memory.m_pMemory;
        v15 = v13;
        v16 = rand();
        m_Size = m_pMemory[v15].m_Models.m_Size;
        v18 = (float)v16 * 0.000030518509;
        v19 = 0;
        if ( m_Size > 0 )
        {
          p_m_Amount = &m_pMemory[v15].m_Models.m_Memory.m_pMemory->m_Amount;
          while ( *p_m_Amount < v18 )
          {
            ++v19;
            p_m_Amount += 17;
            if ( v19 >= m_Size )
              goto LABEL_14;
          }
          if ( v19 >= 0 )
            DetailObjects::PlaceDetail(
              this: (DetailObjects *)LODWORD(normal.z),
              model: (const QAngle *)&v5->m_Groups.m_Memory.m_pMemory[v15].m_Models.m_Memory.m_pMemory[v19],
              pt: &v24,
              normal: &pNormal);
        }
      }
      else
      {
        while ( !BoundBox::ContainsPoint(
                   this: &v22.m_Memory.m_pMemory[v12 >> ((unsigned __int64)*((int *)&v22.m_Memory + 2) >> 27)][v12 & ((32 * *((_DWORD *)&v22.m_Memory + 2)) >> 5)].m_pObject->m_Render2DBox,
                   pt: &v24) )
        {
          if ( ++v12 >= v22.m_Size )
          {
            v11 = pMapFace;
            goto LABEL_7;
          }
        }
      }
LABEL_14:
      ;
    }
  }
  LODWORD(pt.z) = 6;
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(this: &v22);
  if ( v22.m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < v22.m_Memory.m_nBlocks; ++i )
      free(pMem: v22.m_Memory.m_pMemory[i]);
    v22.m_Memory.m_nBlocks = 0;
    free(pMem: v22.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A3F0
// Name: protected: static void DetailObjects::ParseDetailObjectFile(class KeyValues __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DetailObjects::ParseDetailObjectFile(KeyValues *keyValues)
{
  KeyValues *i; // edi
  int v2; // ebx
  const char *Name; // eax
  DetailObjects::DetailObject_t *v4; // esi
  KeyValues *j; // esi
  CUtlSymbol v6; // [esp+6h] [ebp-2h] BYREF

  for ( i = KeyValues::GetFirstSubKey(this: keyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetFirstSubKey(this: i) != nullptr )
    {
      v2 = CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>::InsertBefore(
             this: &DetailObjects::s_DetailObjectDict,
             elem: DetailObjects::s_DetailObjectDict.m_Size);
      Name = KeyValues::GetName(this: i);
      CUtlSymbol::CUtlSymbol(this: &v6, pStr: Name);
      DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[v2].m_Name = v6;
      v4 = &DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[v2];
      v4->m_Density = KeyValues::GetFloat(this: i, keyName: "density", defaultValue: 0.0);
      for ( j = KeyValues::GetFirstSubKey(this: i); j != nullptr; j = KeyValues::GetNextKey(this: j) )
      {
        if ( KeyValues::GetFirstSubKey(this: j) != nullptr )
          DetailObjects::ParseDetailGroup(detailId: v2, pGroupKeyValues: j);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A4D0
// Name: public: static void DetailObjects::LoadEmitDetailObjectDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DetailObjects::LoadEmitDetailObjectDictionary()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi

  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr )
    v1 = KeyValues::KeyValues(this: v0, setName: "detail.vbsp");
  else
    v1 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v1,
         filesystem: g_pFileSystem,
         resourceName: "detail.vbsp",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    DetailObjects::ParseDetailObjectFile(keyValues: v1);
  }
  KeyValues::deleteThis(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1001A560
// Name: protected: void DetailObjects::EmitDetailObjectsOnFace(class CMapFace __near *,struct DetailObjects::DetailObject_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge DetailObjects::EmitDetailObjectsOnFace(
        DetailObjects *this@<ecx>,
        int a2@<ebp>,
        CMapFace *pMapFace,
        DetailObjects::DetailObject_t *detail)
{
  int nPoints; // edi
  CMapDoc *v5; // esi
  Vector *Points; // ecx
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  DetailObjects::DetailObject_t *v11; // esi
  float v12; // xmm6_4
  double v13; // xmm0_8
  __int64 v14; // xmm1_8
  float v15; // xmm1_4
  int v16; // eax
  DetailObjects::DetailObjectGroup_t *m_pMemory; // esi
  DetailObjects::DetailObjectGroup_t *v18; // esi
  float v19; // xmm0_4
  int m_Size; // eax
  float v21; // xmm0_4
  int v22; // edi
  float *p_m_Amount; // esi
  int v24; // esi
  int i; // esi
  float v26; // [esp+14h] [ebp-ACh]
  Vector v27; // [esp+2Ch] [ebp-94h] BYREF
  Vector alpha; // [esp+38h] [ebp-88h] BYREF
  unsigned int v29; // [esp+44h] [ebp-7Ch]
  float v30; // [esp+48h] [ebp-78h]
  float v31; // [esp+4Ch] [ebp-74h]
  float v32; // [esp+50h] [ebp-70h]
  float v33; // [esp+54h] [ebp-6Ch]
  float v34; // [esp+58h] [ebp-68h]
  float v35; // [esp+5Ch] [ebp-64h]
  float v36; // [esp+60h] [ebp-60h]
  float v37; // [esp+64h] [ebp-5Ch]
  float v38; // [esp+68h] [ebp-58h]
  int v39; // [esp+6Ch] [ebp-54h]
  Vector normal; // [esp+70h] [ebp-50h]
  Vector pt; // [esp+7Ch] [ebp-44h]
  float v42; // [esp+88h] [ebp-38h]
  Vector e1; // [esp+8Ch] [ebp-34h] BYREF
  Vector areaVec; // [esp+98h] [ebp-28h]
  Vector e2; // [esp+A4h] [ebp-1Ch]
  int v46; // [esp+B0h] [ebp-10h]
  int v47; // [esp+B4h] [ebp-Ch]
  float v; // [esp+B8h] [ebp-8h]
  int v49; // [esp+BCh] [ebp-4h] BYREF
  float p0; // [esp+C0h] [ebp+0h]

  v47 = a2;
  v = p0;
  v46 = -1;
  LODWORD(e2.z) = &_ehhandler__EmitDetailObjectsOnFace_DetailObjects__IAEXPAVCMapFace__AAUDetailObject_t_1__Z;
  LODWORD(e2.y) = NtCurrentTeb()->NtTib.ExceptionList;
  LODWORD(e2.x) = &v49;
  nPoints = pMapFace->nPoints;
  LODWORD(normal.x) = this;
  if ( nPoints >= 3 )
  {
    v5 = CMapDoc::m_pMapDoc;
    areaVec.x = 0.0;
    e1.y = 0.0;
    e1.z = 0.0;
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&e1.y,
      nGrowSize: 0,
      nInitSize: 0);
    areaVec.y = 0.0;
    areaVec.z = 0.0;
    v46 = 3;
    CMapDoc::FindEntitiesByClassName(
      this: v5,
      Found: (CUtlReferenceVector<CMapEntity> *)&e1.y,
      pszClassName: "func_detail_blocker",
      bVisiblesOnly: false);
    pt = *pMapFace->Points;
    LODWORD(e1.x) = 12;
    LODWORD(normal.z) = nPoints - 2;
    do
    {
      Points = pMapFace->Points;
      v7 = *(float *)((char *)&Points->y + LODWORD(e1.x)) - pt.y;
      v8 = *(float *)((char *)&Points[1].y + LODWORD(e1.x)) - pt.y;
      v9 = *(float *)((char *)&Points[1].z + LODWORD(e1.x)) - pt.z;
      v10 = *(float *)((char *)&Points[1].x + LODWORD(e1.x)) - pt.x;
      v11 = detail;
      v12 = *(float *)((char *)&Points->x + LODWORD(e1.x)) - pt.x;
      v32 = *(float *)((char *)&Points->z + LODWORD(e1.x)) - pt.z;
      v33 = (float)(v9 * v7) - (float)(v8 * v32);
      v31 = v7;
      v38 = v9;
      v34 = (float)(v32 * v10) - (float)(v9 * v12);
      v35 = (float)(v8 * v12) - (float)(v7 * v10);
      v26 = fsqrt((float)((float)(v34 * v34) + (float)(v35 * v35)) + (float)(v33 * v33));
      v13 = (float)(detail->m_Density * (float)(v26 * 0.5)) * 0.000001;
      *(double *)&v14 = 0.0;
      v30 = v12;
      v36 = v10;
      v37 = v8;
      if ( v13 < 0.0 || (*(double *)&v14 = 65535.0, v13 > 65535.0) )
        v13 = *(double *)&v14;
      if ( (int)v13 > 0 )
      {
        v39 = (int)v13;
        while ( 1 )
        {
          v42 = (float)rand() * 0.000030518509;
          v15 = (float)rand() * 0.000030518509;
          normal.y = v15;
          if ( v15 > (float)(1.0 - v42) )
          {
            v42 = 1.0 - v42;
            normal.y = 1.0 - v15;
          }
          v16 = DetailObjects::SelectGroup(this: (DetailObjects *)LODWORD(normal.x), detail: v11, alpha: 1.0);
          m_pMemory = v11->m_Groups.m_Memory.m_pMemory;
          v29 = 24 * v16;
          v18 = &m_pMemory[v16];
          v19 = (float)rand();
          m_Size = v18->m_Models.m_Size;
          v21 = v19 * 0.000030518509;
          v22 = 0;
          if ( m_Size > 0 )
          {
            p_m_Amount = &v18->m_Models.m_Memory.m_pMemory->m_Amount;
            while ( *p_m_Amount < v21 )
            {
              ++v22;
              p_m_Amount += 17;
              if ( v22 >= m_Size )
                goto LABEL_21;
            }
            if ( v22 >= 0 )
            {
              alpha.y = (float)(v37 * normal.y) + (float)((float)(v31 * v42) + pt.y);
              alpha.z = (float)(v38 * normal.y) + (float)((float)(v32 * v42) + pt.z);
              v27.x = (float)(-1.0 / v26) * v33;
              v27.y = v34 * (float)(-1.0 / v26);
              v24 = 0;
              alpha.x = (float)(v36 * normal.y) + (float)((float)(v30 * v42) + pt.x);
              v27.z = v35 * (float)(-1.0 / v26);
              if ( SLODWORD(areaVec.y) <= 0 )
              {
LABEL_20:
                DetailObjects::PlaceDetail(
                  this: (DetailObjects *)LODWORD(normal.x),
                  model: (const QAngle *)&detail->m_Groups.m_Memory.m_pMemory[v29 / 0x18].m_Models.m_Memory.m_pMemory[v22],
                  pt: &alpha,
                  normal: &v27);
              }
              else
              {
                while ( !BoundBox::ContainsPoint(
                           this: (BoundBox *)(*(_DWORD *)(*(_DWORD *)(LODWORD(e1.y)
                                                              + 4
                                                              * (v24 >> ((unsigned __int64)SLODWORD(areaVec.x) >> 27)))
                                                  + 12 * (v24 & ((32 * LODWORD(areaVec.x)) >> 5))
                                                  + 8)
                                      + 96),
                           pt: &alpha) )
                {
                  if ( ++v24 >= SLODWORD(areaVec.y) )
                    goto LABEL_20;
                }
              }
            }
          }
LABEL_21:
          if ( --v39 == 0 )
            break;
          v11 = detail;
        }
      }
      LODWORD(e1.x) += 12;
      --LODWORD(normal.z);
    }
    while ( LODWORD(normal.z) != 0 );
    v46 = 6;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(this: (CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *)&e1.y);
    if ( LODWORD(e1.y) != 0 )
    {
      for ( i = 0; i < SLODWORD(e1.z); ++i )
        free(pMem: *(void **)(LODWORD(e1.y) + 4 * i));
      e1.z = 0.0;
      free(pMem: (void *)LODWORD(e1.y));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A9D0
// Name: public: static void DetailObjects::BuildAnyDetailObjects(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DetailObjects::BuildAnyDetailObjects(CMapFace *pMapFace)
{
  IEditorTexture *m_pTexture; // ecx
  int v2; // edi
  int v3; // eax
  int v4; // eax
  const char *v5; // eax
  DetailObjects *m_pDetailObjects; // ebx
  DetailObjects::DetailObject_t *v7; // eax
  DetailObjects::DetailObject_t *v8; // eax
  float v9; // xmm1_4
  int nPoints; // eax
  float v11; // xmm2_4
  float v12; // xmm3_4
  void (__thiscall *SetOrigin)(CMapPoint *, Vector *); // edx
  float v14; // xmm0_4
  int v15; // eax
  unsigned int m_nFaceID; // edi
  char szTextureName[260]; // [esp+0h] [ebp-150h] BYREF
  Vector faceCorner; // [esp+104h] [ebp-4Ch] BYREF
  DetailObjects::DetailObject_t search; // [esp+110h] [ebp-40h] BYREF
  const char *pDetailType; // [esp+12Ch] [ebp-24h]
  Vector faceCenter; // [esp+130h] [ebp-20h] BYREF
  bool found; // [esp+13Fh] [ebp-11h] BYREF
  DetailObjects::DetailObject_t *detail; // [esp+140h] [ebp-10h] BYREF
  int v24; // [esp+14Ch] [ebp-4h]
  int savedregs; // [esp+150h] [ebp+0h] BYREF

  if ( DetailObjects::s_bBuildDetailObjects && (*((_BYTE *)pMapFace + 432) & 1) == 0 )
  {
    m_pTexture = pMapFace->m_pTexture;
    v2 = 0;
    if ( m_pTexture != nullptr )
    {
      v3 = (int)m_pTexture->GetMaterial(this: m_pTexture, a2: true);
      if ( v3 != 0 )
      {
        v4 = (*(int (__thiscall **)(int, const char *, bool *, _DWORD))(*(_DWORD *)v3 + 44))(
               a1: v3,
               a2: "%detailtype",
               a3: &found,
               a4: 0);
        if ( found && v4 != 0 )
        {
          v5 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 28))(a1: v4);
          pDetailType = v5;
          if ( v5 != nullptr )
          {
            search.m_Name.m_Id = -1;
            detail = (DetailObjects::DetailObject_t *)&search.m_Groups;
            memset(&search.m_Groups, 0, sizeof(search.m_Groups));
            v24 = 2;
            CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&detail + 1, pStr: v5);
            m_pDetailObjects = pMapFace->m_pDetailObjects;
            search.m_Name.m_Id = HIWORD(detail);
            if ( m_pDetailObjects != nullptr )
            {
              CUtlVector<StudioModel *,CUtlMemory<StudioModel *,int>>::PurgeAndDeleteElements(this: &m_pDetailObjects->m_DetailModels);
              CUtlVector<CSpriteModel *,CUtlMemory<CSpriteModel *,int>>::PurgeAndDeleteElements(this: &m_pDetailObjects->m_DetailSprites);
            }
            else
            {
              v7 = (DetailObjects::DetailObject_t *)operator new(nSize: 0x48u);
              detail = v7;
              LOBYTE(v24) = 3;
              if ( v7 != nullptr )
                v8 = (DetailObjects::DetailObject_t *)DetailObjects::DetailObjects(this: (DetailObjects *)v7);
              else
                v8 = nullptr;
              LOBYTE(v24) = 2;
              detail = v8;
              pMapFace->m_pDetailObjects = (DetailObjects *)v8;
              m_pDetailObjects = (DetailObjects *)v8;
            }
            if ( m_pDetailObjects != nullptr )
            {
              v9 = 0.0;
              nPoints = pMapFace->nPoints;
              v11 = 0.0;
              v12 = 0.0;
              memset(&faceCenter, 0, sizeof(faceCenter));
              if ( nPoints > 0 )
              {
                do
                {
                  CMapFace::GetPoint(this: pMapFace, Point: &faceCorner, nPoint: v2);
                  v9 = faceCenter.x + faceCorner.x;
                  v11 = faceCorner.y + faceCenter.y;
                  v12 = faceCorner.z + faceCenter.z;
                  ++v2;
                  faceCenter.x = faceCenter.x + faceCorner.x;
                  faceCenter.y = faceCorner.y + faceCenter.y;
                  faceCenter.z = faceCorner.z + faceCenter.z;
                }
                while ( v2 < pMapFace->nPoints );
              }
              SetOrigin = m_pDetailObjects->SetOrigin;
              v14 = 1.0 / (float)pMapFace->nPoints;
              faceCenter.x = v9 * v14;
              faceCenter.y = v11 * v14;
              faceCenter.z = v12 * v14;
              SetOrigin(this: m_pDetailObjects, a2: &faceCenter);
              v15 = CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>::Find(
                      this: &DetailObjects::s_DetailObjectDict,
                      src: &search);
              if ( v15 >= 0 )
              {
                m_nFaceID = pMapFace->m_nFaceID;
                detail = &DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory[v15];
                srand(seed: m_nFaceID);
                _RandomSeed(a1: m_nFaceID);
                if ( pMapFace->m_DispHandle == 0xFFFF )
                  DetailObjects::EmitDetailObjectsOnFace(this: m_pDetailObjects, a2: (int)&savedregs, pMapFace, detail);
                else
                  DetailObjects::EmitDetailObjectsOnDisplacementFace(
                    this: m_pDetailObjects,
                    pMapFace: *(float *)&pMapFace,
                    detail);
              }
              else
              {
                CMapFace::GetTextureName(this: pMapFace, pszName: szTextureName);
                _Warning(a1: "Material %s uses unknown detail object type %s!\n", szTextureName, pDetailType);
              }
            }
            else
            {
              _Warning(a1: "Could not allocate DetailObject for CMapFace!\n");
            }
            v24 = -1;
            CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>::~CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>(this: &search.m_Groups);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C580
// Name: public: virtual void CMapAtom::SetParent(class CMapAtom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAtom::SetParent(CMapAtom *this, CMapAtom *pParent)
{
  this->m_pParent = pParent;
}

//------------------------------------------------------------------------------
// Address: 0x10150CE0
// Name: public: void CUtlMemory<class DetailObjects::DetailModel_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DetailObjects::DetailModel_t,int>::Grow(
        CUtlMemory<DetailObjects::DetailModel_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailObjects::DetailModel_t *m_pMemory; // ecx

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
      this->m_pMemory = (DetailObjects::DetailModel_t *)_realloc_crt(ptr: m_pMemory, size: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (DetailObjects::DetailModel_t *)MemAlloc_Alloc(nSize: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B8A0
// Name: public: void CUtlIntrusiveDList<class CUtlReference<class CMapClass>>::RemoveNode(class CUtlReference<class CMapClass> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlIntrusiveDList<CUtlReference<CMapClass>>::RemoveNode(
        CUtlIntrusiveDList<CUtlReference<CSheet> > *this,
        CUtlReference<CSheet> *which)
{
  CUtlReference<CSheet> *m_pPrev; // edx
  CUtlReference<CSheet> *m_pNext; // edx

  m_pPrev = which->m_pPrev;
  if ( m_pPrev != nullptr )
  {
    m_pPrev->m_pNext = which->m_pNext;
    if ( which->m_pNext != nullptr )
    {
      which->m_pNext->m_pPrev = which->m_pPrev;
      which->m_pPrev = nullptr;
      which->m_pNext = nullptr;
      return;
    }
  }
  else if ( this->m_pHead == which )
  {
    m_pNext = which->m_pNext;
    this->m_pHead = which->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = nullptr;
  }
  which->m_pPrev = nullptr;
  which->m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x105C0000
// Name: _dynamic_initializer_for__DetailObjects::s_DetailObjectDict__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__DetailObjects::s_DetailObjectDict__()
{
  DetailObjects::s_DetailObjectDict.m_Size = 0;
  DetailObjects::s_DetailObjectDict.m_pElements = DetailObjects::s_DetailObjectDict.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__DetailObjects::s_DetailObjectDict__);
}

//------------------------------------------------------------------------------
// Address: 0x105CA0C0
// Name: _dynamic_atexit_destructor_for__DetailObjects::s_DetailObjectDict__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DetailObjects::s_DetailObjectDict__()
{
  CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>::~CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>(this: &DetailObjects::s_DetailObjectDict);
}

//------------------------------------------------------------------------------
// Address: 0x105C0050
// Name: _dynamic_initializer_for__g_TesselateVerts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TesselateVerts__()
{
  g_TesselateVerts[0].m_Index = (CVertIndex)-65535;
  dword_1072B64A = -65536;
  dword_1072B650 = -1;
  dword_1072B656 = 0xFFFF;
  dword_1072B65C = 0x1FFFF;
  dword_1072B662 = 0x10000;
  dword_1072B668 = 65537;
  dword_1072B66E = 1;
  dword_1072B674 = -65535;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x105C0110
// Name: _dynamic_initializer_for__g_VertInfo_5x5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_5x5__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_5x5;
  for ( i = 24; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0130
// Name: _dynamic_initializer_for__g_VertInfo_9x9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_9x9__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_9x9;
  for ( i = 80; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0150
// Name: _dynamic_initializer_for__g_VertInfo_17x17__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_17x17__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_17x17;
  for ( i = 288; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C0170
// Name: _dynamic_initializer_for__g_PowerInfoInitializer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_PowerInfoInitializer__()
{
  int i; // esi
  CPowerInfo *v1; // eax

  for ( i = 0; i <= 4; ++i )
  {
    v1 = g_PowerInfos[i];
    if ( v1 != nullptr )
      InitPowerInfo(pInfo: v1, iMaxPower: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x105C0190
// Name: _dynamic_initializer_for__s_EdgeData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EdgeData__()
{
  s_EdgeData.m_Size = 0;
  s_EdgeData.m_pElements = s_EdgeData.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_EdgeData__);
}

//------------------------------------------------------------------------------
// Address: 0x105C01E0
// Name: _dynamic_initializer_for__s_CornerData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_CornerData__()
{
  s_CornerData.m_Size = 0;
  s_CornerData.m_pElements = s_CornerData.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_CornerData__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0230
// Name: _dynamic_initializer_for__s_TJData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TJData__()
{
  s_TJData.m_Size = 0;
  s_TJData.m_pElements = s_TJData.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_TJData__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0280
// Name: _dynamic_initializer_for__m_aCoreDispInfos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__m_aCoreDispInfos__()
{
  m_aCoreDispInfos.m_Size = 0;
  m_aCoreDispInfos.m_pElements = m_aCoreDispInfos.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__m_aCoreDispInfos__);
}

//------------------------------------------------------------------------------
// Address: 0x105C02D0
// Name: _dynamic_initializer_for__mcm_CMapOverlayTransition__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapOverlayTransition__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapOverlayTransition,
    Type: CMapOverlayTransition::__Type,
    pfnNew: CMapOverlayTransition::Create);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapOverlayTransition__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0300
// Name: _dynamic_initializer_for__s_DispShoreManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DispShoreManager__()
{
  CDispShoreManager::CDispShoreManager(this: &s_DispShoreManager);
  return atexit(func: dynamic_atexit_destructor_for__s_DispShoreManager__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0320
// Name: _dynamic_initializer_for__g_DefaultGameConfig__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DefaultGameConfig__()
{
  CGameConfig::CGameConfig(this: &g_DefaultGameConfig);
  return atexit(func: dynamic_atexit_destructor_for__g_DefaultGameConfig__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0340
// Name: _dynamic_initializer_for__theApp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__theApp__()
{
  CWinApp::CWinApp(this: &theApp, lpszAppName: nullptr);
  theApp.CWinApp::CWinThread::CCmdTarget::CObject::__vftable = (CHammer_vtbl *)&CHammer::`vftable'{for `CWinApp'};
  theApp.CTier3AppSystem<IHammer,0>::CTier2AppSystem<IHammer,0>::CTier1AppSystem<IHammer,0>::CTier0AppSystem<IHammer>::CBaseAppSystem<IHammer>::IHammer::IAppSystem::__vftable = (CTier3AppSystem<IHammer,0>_vtbl *)&CHammer::`vftable'{for `CTier3AppSystem<IHammer,0>'};
  CPtrArray::CPtrArray(this: &theApp.m_CmdSequences);
  theApp.m_CmdSequences.__vftable = (CTypedPtrArray<CPtrArray,CCommandSequence *>_vtbl *)&CTypedPtrArray<CPtrArray,CCommandSequence *>::`vftable';
  *(_WORD *)&theApp.m_bActiveApp = 1;
  theApp.m_bForceRenderNextFrame = false;
  theApp.m_bClosing = false;
  theApp.m_bFoundryMode = false;
  theApp.m_CustomAcceleratorWindow = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__theApp__);
}

//------------------------------------------------------------------------------
// Address: 0x105CA0D0
// Name: _EditDispMgr_::_2_::_dynamic_atexit_destructor_for__s_EditDispMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl EditDispMgr_::_2_::_dynamic_atexit_destructor_for__s_EditDispMgr__()
{
  CEditDispMgr::~CEditDispMgr(this: &s_EditDispMgr);
}

//------------------------------------------------------------------------------
// Address: 0x105CA0E0
// Name: _dynamic_atexit_destructor_for__m_aCoreDispInfos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_aCoreDispInfos__()
{
  CCoreDispInfo **m_pMemory; // eax

  m_pMemory = m_aCoreDispInfos.m_Memory.m_pMemory;
  m_aCoreDispInfos.m_Size = 0;
  if ( m_aCoreDispInfos.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_aCoreDispInfos.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: m_aCoreDispInfos.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      m_aCoreDispInfos.m_Memory.m_pMemory = nullptr;
    }
    m_aCoreDispInfos.m_Memory.m_nAllocationCount = 0;
  }
  m_aCoreDispInfos.m_pElements = m_pMemory;
  if ( m_aCoreDispInfos.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_aCoreDispInfos.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: m_aCoreDispInfos.m_Memory.m_pMemory);
      m_aCoreDispInfos.m_Memory.m_pMemory = nullptr;
    }
    m_aCoreDispInfos.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CA170
// Name: _dynamic_atexit_destructor_for__s_EdgeData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EdgeData__()
{
  SewEdgeData_t **m_pMemory; // eax

  m_pMemory = s_EdgeData.m_Memory.m_pMemory;
  s_EdgeData.m_Size = 0;
  if ( s_EdgeData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_EdgeData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_EdgeData.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      s_EdgeData.m_Memory.m_pMemory = nullptr;
    }
    s_EdgeData.m_Memory.m_nAllocationCount = 0;
  }
  s_EdgeData.m_pElements = m_pMemory;
  if ( s_EdgeData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_EdgeData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_EdgeData.m_Memory.m_pMemory);
      s_EdgeData.m_Memory.m_pMemory = nullptr;
    }
    s_EdgeData.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CA200
// Name: _dynamic_atexit_destructor_for__s_CornerData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_CornerData__()
{
  SewCornerData_t **m_pMemory; // eax

  m_pMemory = s_CornerData.m_Memory.m_pMemory;
  s_CornerData.m_Size = 0;
  if ( s_CornerData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_CornerData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_CornerData.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      s_CornerData.m_Memory.m_pMemory = nullptr;
    }
    s_CornerData.m_Memory.m_nAllocationCount = 0;
  }
  s_CornerData.m_pElements = m_pMemory;
  if ( s_CornerData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_CornerData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_CornerData.m_Memory.m_pMemory);
      s_CornerData.m_Memory.m_pMemory = nullptr;
    }
    s_CornerData.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CA290
// Name: _dynamic_atexit_destructor_for__s_TJData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TJData__()
{
  SewTJuncData_t **m_pMemory; // eax

  m_pMemory = s_TJData.m_Memory.m_pMemory;
  s_TJData.m_Size = 0;
  if ( s_TJData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_TJData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_TJData.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      s_TJData.m_Memory.m_pMemory = nullptr;
    }
    s_TJData.m_Memory.m_nAllocationCount = 0;
  }
  s_TJData.m_pElements = m_pMemory;
  if ( s_TJData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_TJData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_TJData.m_Memory.m_pMemory);
      s_TJData.m_Memory.m_pMemory = nullptr;
    }
    s_TJData.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CA320
// Name: _dynamic_atexit_destructor_for__mcm_CMapOverlayTransition__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapOverlayTransition__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapOverlayTransition);
}

//------------------------------------------------------------------------------
// Address: 0x105CA330
// Name: _dynamic_atexit_destructor_for__s_DispShoreManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DispShoreManager__()
{
  CDispShoreManager::~CDispShoreManager(this: &s_DispShoreManager);
}

//------------------------------------------------------------------------------
// Address: 0x105CA340
// Name: _dynamic_atexit_destructor_for__g_DefaultGameConfig__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DefaultGameConfig__()
{
  CGameConfig::~CGameConfig(this: &g_DefaultGameConfig);
}

//------------------------------------------------------------------------------
// Address: 0x105CA350
// Name: _dynamic_atexit_destructor_for__g_Shell__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Shell__()
{
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&g_Shell);
}

//------------------------------------------------------------------------------
// Address: 0x105CA360
// Name: _dynamic_atexit_destructor_for__theApp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__theApp__()
{
  theApp.CWinApp::CWinThread::CCmdTarget::CObject::__vftable = (CHammer_vtbl *)&CHammer::`vftable'{for `CWinApp'};
  theApp.CTier3AppSystem<IHammer,0>::CTier2AppSystem<IHammer,0>::CTier1AppSystem<IHammer,0>::CTier0AppSystem<IHammer>::CBaseAppSystem<IHammer>::IHammer::IAppSystem::__vftable = (CTier3AppSystem<IHammer,0>_vtbl *)&CHammer::`vftable'{for `CTier3AppSystem<IHammer,0>'};
  CPtrArray::~CPtrArray(this: &theApp.m_CmdSequences);
  CWinApp::~CWinApp(this: &theApp);
}

//------------------------------------------------------------------------------
// Address: 0x105CA3D0
// Name: _dynamic_atexit_destructor_for__g_ShellMessageWnd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ShellMessageWnd__()
{
  CWnd::~CWnd(this: &g_ShellMessageWnd);
}

//------------------------------------------------------------------------------
// Address: 0x105CA410
// Name: _dynamic_atexit_destructor_for__g_HammerToLPreviewMsgQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_HammerToLPreviewMsgQueue__()
{
  CThreadMutex::~CThreadMutex(this: &g_HammerToLPreviewMsgQueue.QueueAccessMutex);
  CThreadEvent::~CThreadEvent(this: &g_HammerToLPreviewMsgQueue.SignalEvent);
}

//------------------------------------------------------------------------------
// Address: 0x105CA460
// Name: _dynamic_atexit_destructor_for__g_LPreviewToHammerMsgQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_LPreviewToHammerMsgQueue__()
{
  CThreadMutex::~CThreadMutex(this: &g_LPreviewToHammerMsgQueue.QueueAccessMutex);
  CThreadEvent::~CThreadEvent(this: &g_LPreviewToHammerMsgQueue.SignalEvent);
}
