// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gamerect.cpp
// Functions: 11
// ============================================================

#include "vgui2\game_controls\gamerect.h"

//------------------------------------------------------------------------------
// Address: 0x00428470
// Name: public: virtual void CGameRect::UpdateGeometry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRect::UpdateGeometry(CGameRect *this)
{
  CAnimData **v2; // eax
  int m_tms; // ecx
  DmeTime_t result; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_CurrentState != -1 )
  {
    CGameGraphic::GetAnimationTimePassed(this, &result);
    v2 = &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState];
    this->m_Geometry.m_SheetSequenceNumber = (*v2)->m_TextureAnimSheetSeqNumber;
    m_tms = result.m_tms;
    this->m_Geometry.m_AnimationRate = (*v2)->m_AnimationRate;
    CTypedLog<color32_s>::GetValue(
      this: &(*v2)->m_ColorAnim,
      time: (DmeTime_t)m_tms,
      pOutValue: &this->m_Geometry.m_Color);
    CTypedLog<Vector2D>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_CenterPosAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Center);
    CTypedLog<Vector2D>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_ScaleAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Scale);
    CTypedLog<float>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_RotationAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Rotation);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428530
// Name: public: virtual bool CGameRect::HitTest(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameRect::HitTest(CGameRect *this, int x, int y)
{
  int v4; // ebx
  int i; // edi
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  float *p_x; // eax
  Vector2D v10; // [esp-20h] [ebp-2Ch]
  Vector2D v11; // [esp-10h] [ebp-1Ch]
  float xa; // [esp+10h] [ebp+4h]
  float ya; // [esp+14h] [ebp+8h]

  if ( !this->m_Geometry.m_bVisible )
    return 0;
  if ( this->m_ScreenPositions.m_Size == 0 )
    return 0;
  v4 = 0;
  if ( this->m_Geometry.m_Triangles.m_Size <= 0 )
    return 0;
  xa = (float)x;
  ya = (float)y;
  for ( i = 0; ; ++i )
  {
    m_pMemory = this->m_ScreenPositions.m_Memory.m_pMemory;
    v7 = this->m_Geometry.m_Triangles.m_Memory.m_pMemory[i].m_PointIndex[2];
    v11.x = m_pMemory[v7].x;
    v11.y = m_pMemory[v7].y;
    p_x = &m_pMemory[this->m_Geometry.m_Triangles.m_Memory.m_pMemory[i].m_PointIndex[0]].x;
    v10.x = *p_x;
    v10.y = p_x[1];
    if ( PointTriangleHitTest(
           tringleVert0: v10,
           tringleVert1: m_pMemory[this->m_Geometry.m_Triangles.m_Memory.m_pMemory[i].m_PointIndex[1]],
           tringleVert2: v11,
           point: (Vector2D)__PAIR64__(LODWORD(ya), LODWORD(xa))) )
    {
      break;
    }
    if ( ++v4 >= this->m_Geometry.m_Triangles.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428620
// Name: public: virtual CGameRect::~CGameRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRect::~CGameRect(CGameRect *this)
{
  this->__vftable = (CGameRect_vtbl *)&CGameRect::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ScreenPositions);
  CGameGraphic::~CGameGraphic(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428680
// Name: public: virtual void CGameRect::UpdateRenderData(struct color32_s,class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRect::UpdateRenderData(
        CGameRect *this,
        color32_s parentColor,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex)
{
  bool v5; // zf
  CGeometry *p_m_Geometry; // ebx
  int m_Size; // ebp
  int v8; // esi
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *p_m_ScreenPositions; // edi
  float x; // xmm1_4
  int v11; // eax
  Vector2D src; // [esp+4h] [ebp-20h] BYREF
  float v13[2]; // [esp+Ch] [ebp-18h] BYREF
  Vector screenpos; // [esp+14h] [ebp-10h] BYREF
  const matrix3x4_t *parentColora; // [esp+28h] [ebp+4h]

  v5 = !this->m_Geometry.m_bVisible;
  LODWORD(src.x) = this;
  if ( !v5 )
  {
    p_m_Geometry = &this->m_Geometry;
    CGeometry::SetResultantColor(this: &this->m_Geometry, parentColor);
    CGeometry::UpdateRenderData(this: &this->m_Geometry, renderGeometryLists, firstListIndex);
    m_Size = this->m_Geometry.m_RelativePositions.m_Size;
    v8 = 0;
    p_m_ScreenPositions = &this->m_ScreenPositions;
    p_m_ScreenPositions->m_Size = 0;
    if ( m_Size > 0 )
    {
      parentColora = (const matrix3x4_t *)(LODWORD(src.x) + 168);
      do
      {
        x = p_m_Geometry->m_RelativePositions.m_Memory.m_pMemory[v8].x;
        v13[1] = p_m_Geometry->m_RelativePositions.m_Memory.m_pMemory[v8].y;
        v13[0] = x;
        screenpos.x = 0.0;
        VectorTransform(in1: v13, in2: parentColora, out: &screenpos.y);
        v11 = p_m_ScreenPositions->m_Size;
        src = *(Vector2D *)&screenpos.y;
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(this: p_m_ScreenPositions, elem: v11, &src);
        ++v8;
      }
      while ( v8 < m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428760
// Name: protected: void CGameRect::SetupVertexColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameRect::SetupVertexColors(CGameRect *this)
{
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *p_m_VertexColors; // esi
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  p_m_VertexColors = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Geometry.m_VertexColors;
  src = (vgui::TreeNode *)-1;
  this->m_Geometry.m_VertexColors.m_Size = 0;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Geometry.m_VertexColors,
    elem: this->m_Geometry.m_VertexColors.m_Size,
    &src);
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: p_m_VertexColors,
    elem: p_m_VertexColors->m_Size,
    &src);
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: p_m_VertexColors,
    elem: p_m_VertexColors->m_Size,
    &src);
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: p_m_VertexColors,
    elem: p_m_VertexColors->m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x004287D0
// Name: public: CGameRect::CGameRect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameRect *__thiscall CGameRect::CGameRect(CGameRect *this, const char *pName)
{
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  int m_Size; // [esp-8h] [ebp-20h]
  int v9; // [esp-8h] [ebp-20h]
  int v10; // [esp-8h] [ebp-20h]
  int v11; // [esp-8h] [ebp-20h]
  int v12; // [esp-8h] [ebp-20h]
  int v13; // [esp-8h] [ebp-20h]
  CTriangle triangle; // [esp+8h] [ebp-10h] BYREF
  int v15; // [esp+14h] [ebp-4h]

  CGameGraphic::CGameGraphic(this);
  this->__vftable = (CGameRect_vtbl *)&CGameRect::`vftable';
  this->m_ScreenPositions.m_Memory.m_pMemory = nullptr;
  this->m_ScreenPositions.m_Memory.m_nAllocationCount = 0;
  this->m_ScreenPositions.m_Memory.m_nGrowSize = 0;
  this->m_ScreenPositions.m_Size = 0;
  this->m_ScreenPositions.m_pElements = nullptr;
  this->m_Geometry.m_SheetSequenceNumber = 0;
  this->m_bCanAcceptInput = false;
  CUtlString::operator=(this: &this->m_pName, src: pName);
  this->m_Geometry.m_Center.x = 0.0;
  this->m_Geometry.m_Center.y = 0.0;
  this->m_Geometry.m_Scale.x = 0.0;
  this->m_Geometry.m_Scale.y = 0.0;
  this->m_Geometry.m_Rotation = 0.0;
  this->m_Geometry.m_bMaintainAspectRatio = false;
  this->m_Geometry.m_Sublayer = 0;
  this->m_Geometry.m_bVisible = true;
  this->m_CurrentState = -1;
  this->m_Geometry.m_bHorizontalGradient = false;
  this->m_Geometry.m_Color.r = -1;
  this->m_Geometry.m_Color.g = -1;
  this->m_Geometry.m_Color.b = -1;
  this->m_Geometry.m_Color.a = -1;
  this->m_Geometry.m_TopColor.r = -1;
  this->m_Geometry.m_TopColor.g = -1;
  this->m_Geometry.m_TopColor.b = -1;
  this->m_Geometry.m_TopColor.a = -1;
  this->m_Geometry.m_BottomColor.r = -1;
  this->m_Geometry.m_BottomColor.g = -1;
  this->m_Geometry.m_BottomColor.b = -1;
  this->m_Geometry.m_BottomColor.a = -1;
  m_Size = this->m_Geometry.m_RelativePositions.m_Size;
  triangle.m_PointIndex[1] = -1090519040;
  triangle.m_PointIndex[2] = -1090519040;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_RelativePositions,
    elem: m_Size,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v3 = this->m_Geometry.m_RelativePositions.m_Size;
  triangle.m_PointIndex[1] = 1056964608;
  triangle.m_PointIndex[2] = -1090519040;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_RelativePositions,
    elem: v3,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v9 = this->m_Geometry.m_RelativePositions.m_Size;
  triangle.m_PointIndex[1] = 1056964608;
  triangle.m_PointIndex[2] = 1056964608;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_RelativePositions,
    elem: v9,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v4 = this->m_Geometry.m_RelativePositions.m_Size;
  triangle.m_PointIndex[1] = -1090519040;
  triangle.m_PointIndex[2] = 1056964608;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_RelativePositions,
    elem: v4,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v10 = this->m_Geometry.m_TextureCoords.m_Size;
  triangle.m_PointIndex[1] = 0;
  triangle.m_PointIndex[2] = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_TextureCoords,
    elem: v10,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v5 = this->m_Geometry.m_TextureCoords.m_Size;
  triangle.m_PointIndex[1] = 1065353216;
  triangle.m_PointIndex[2] = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_TextureCoords,
    elem: v5,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v11 = this->m_Geometry.m_TextureCoords.m_Size;
  triangle.m_PointIndex[1] = 1065353216;
  triangle.m_PointIndex[2] = 1065353216;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_TextureCoords,
    elem: v11,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v6 = this->m_Geometry.m_TextureCoords.m_Size;
  triangle.m_PointIndex[1] = 0;
  triangle.m_PointIndex[2] = 1065353216;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_TextureCoords,
    elem: v6,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  CGameRect::SetupVertexColors(this);
  v12 = this->m_Geometry.m_Triangles.m_Size;
  triangle.m_PointIndex[1] = 0;
  triangle.m_PointIndex[2] = 1;
  v15 = 2;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Geometry.m_Triangles,
    elem: v12,
    src: (const CVTFTexture::ResourceMemorySection *)&triangle.m_PointIndex[1]);
  v13 = this->m_Geometry.m_Triangles.m_Size;
  triangle.m_PointIndex[1] = 0;
  triangle.m_PointIndex[2] = 2;
  v15 = 3;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Geometry.m_Triangles,
    elem: v13,
    src: (const CVTFTexture::ResourceMemorySection *)&triangle.m_PointIndex[1]);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428A40
// Name: public: bool CGameRect::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameRect::Unserialize(CGameRect *this, CDmxElement *pGraphic)
{
  CDmxElement *v2; // esi
  CDmxAttribute *Attribute; // eax
  int v5; // esi
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v6; // ebx
  int m_Size; // ebp
  CGeometry *p_m_Geometry; // edi
  int *v9; // eax
  CDmxAttribute *v10; // eax
  int v11; // esi
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v12; // ebx
  int v13; // ebp
  int *v14; // eax
  CDmxAttribute *v15; // eax
  int v16; // esi
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v17; // ebx
  int v18; // ebp
  const CDmxAttribute *v19; // eax
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *m_pData; // eax
  int *p_m_nDataAllocSize; // eax
  int v22; // ecx
  int v23; // edx
  CDmxAttribute *v24; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v25; // ebp
  int v26; // ebx
  int v27; // esi
  CAnimData *v28; // eax
  CDmxElement *v29; // edi
  int v31; // [esp-10h] [ebp-28h]
  int v32; // [esp-10h] [ebp-28h]
  int v33; // [esp-10h] [ebp-28h]
  CDmxElement *v34; // [esp-Ch] [ebp-24h]
  CTriangle triangle; // [esp+8h] [ebp-10h] BYREF
  int v36; // [esp+14h] [ebp-4h]

  v2 = pGraphic;
  triangle.m_PointIndex[0] = (int)this;
  CDmxElement::UnpackIntoStructure(this: pGraphic, pData: (char *)this, pUnpack: s_GameRectUnpack);
  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: v2, pAttributeName: "relativepositions");
  v5 = 0;
  if ( Attribute == nullptr || Attribute->m_Type != AT_VECTOR2_ARRAY )
    return 0;
  v6 = CDmxAttribute::GetArray<Vector2D>(this: Attribute);
  m_Size = v6->m_Size;
  p_m_Geometry = &this->m_Geometry;
  p_m_Geometry->m_RelativePositions.m_Size = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v9 = (int *)&v6->m_Memory.m_pMemory[v5];
      triangle.m_PointIndex[1] = *v9;
      v31 = p_m_Geometry->m_RelativePositions.m_Size;
      triangle.m_PointIndex[2] = v9[1];
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        this: &p_m_Geometry->m_RelativePositions,
        elem: v31,
        src: (const Vector2D *)&triangle.m_PointIndex[1]);
      ++v5;
    }
    while ( v5 < m_Size );
  }
  v10 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pGraphic, pAttributeName: "texcoords");
  v11 = 0;
  if ( v10 != nullptr && v10->m_Type == AT_VECTOR2_ARRAY )
  {
    v12 = CDmxAttribute::GetArray<Vector2D>(this: v10);
    v13 = v12->m_Size;
    *(_DWORD *)(triangle.m_PointIndex[0] + 60) = 0;
    if ( v13 > 0 )
    {
      do
      {
        v14 = (int *)&v12->m_Memory.m_pMemory[v11];
        triangle.m_PointIndex[1] = *v14;
        v32 = *(_DWORD *)(triangle.m_PointIndex[0] + 60);
        triangle.m_PointIndex[2] = v14[1];
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)(triangle.m_PointIndex[0] + 48),
          elem: v32,
          src: (const Vector2D *)&triangle.m_PointIndex[1]);
        ++v11;
      }
      while ( v11 < v13 );
    }
    CGameRect::SetupVertexColors(this: (CGameRect *)triangle.m_PointIndex[0]);
    v15 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pGraphic, pAttributeName: "triangles");
    v16 = 0;
    if ( v15 != nullptr && v15->m_Type == AT_FIRST_ARRAY_TYPE )
    {
      v17 = CDmxAttribute::GetArray<CDmxElement *>(this: v15);
      v18 = v17->m_Size;
      *(_DWORD *)(triangle.m_PointIndex[0] + 100) = 0;
      if ( v18 > 0 )
      {
        do
        {
          v19 = CDmxElement::GetAttribute(this: v17->m_Memory.m_pMemory[v16], pAttributeName: "positionindexes");
          if ( v19->m_Type == AT_INT_ARRAY )
          {
            m_pData = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)v19->m_pData;
          }
          else
          {
            if ( (`CDmxAttribute::GetArray<int>'::`4'::`local static guard' & 1) == 0 )
            {
              `CDmxAttribute::GetArray<int>'::`4'::`local static guard' |= 1u;
              `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
              `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
              `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
              `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_Size = 0;
              `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_pElements = nullptr;
              atexit(func: `CDmxAttribute::GetArray<int>'::`4'::`dynamic atexit destructor for 'defaultArray'');
            }
            m_pData = &`CDmxAttribute::GetArray<int>'::`4'::defaultArray;
          }
          p_m_nDataAllocSize = &m_pData->m_Memory.m_pMemory->m_nDataAllocSize;
          v22 = p_m_nDataAllocSize[1];
          triangle.m_PointIndex[1] = *p_m_nDataAllocSize;
          v23 = p_m_nDataAllocSize[2];
          triangle.m_PointIndex[2] = v22;
          v33 = *(_DWORD *)(triangle.m_PointIndex[0] + 100);
          v36 = v23;
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)(triangle.m_PointIndex[0] + 88),
            elem: v33,
            src: (const CVTFTexture::ResourceMemorySection *)&triangle.m_PointIndex[1]);
          ++v16;
        }
        while ( v16 < v18 );
      }
      v24 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pGraphic, pAttributeName: "imageanims");
      if ( v24 != nullptr && v24->m_Type == AT_FIRST_ARRAY_TYPE )
      {
        v25 = CDmxAttribute::GetArray<CDmxElement *>(this: v24);
        v26 = v25->m_Size;
        v27 = 0;
        if ( v26 <= 0 )
        {
LABEL_26:
          (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)triangle.m_PointIndex[0] + 24))(
            a1: triangle.m_PointIndex[0],
            a2: "default",
            a3: 1);
          return 1;
        }
        while ( 1 )
        {
          v28 = (CAnimData *)MemAlloc_Alloc(nSize: 0x140u);
          v29 = v28 != nullptr ? (CDmxElement *)CAnimData::CAnimData(this: v28) : nullptr;
          v34 = v25->m_Memory.m_pMemory[v27];
          pGraphic = v29;
          if ( CAnimData::Unserialize(this: (CAnimData *)v29, pElement: v34) == 0 )
            break;
          CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
            this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)(triangle.m_PointIndex[0] + 332),
            elem: *(_DWORD *)(triangle.m_PointIndex[0] + 344),
            src: (vgui::TreeNode **)&pGraphic);
          if ( ++v27 >= v26 )
            goto LABEL_26;
        }
        if ( v29 != nullptr )
        {
          CAnimData::~CAnimData(this: (CAnimData *)v29);
          free(pMem: v29);
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005336F0
// Name: CGameRect_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CGameRect_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CGameRect>();
  s_pUnpack_7 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533700
// Name: _dynamic_initializer_for__s_GameRectUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_GameRectUnpack__()
{
  s_GameRectUnpack = s_pUnpack_7;
  return s_pUnpack_7;
}

//------------------------------------------------------------------------------
// Address: 0x00533710
// Name: _dynamic_initializer_for__g_CGameUIScriptInterface_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CGameUIScriptInterface_ScriptDesc__()
{
  InitCGameUIScriptInterfaceScriptDesc();
  g_CGameUIScriptInterface_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CGameUIScriptInterface_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CGameUIScriptInterface_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x00533740
// Name: _dynamic_initializer_for__ui_script_spew_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ui_script_spew_level__()
{
  ConVar::ConVar(this: &ui_script_spew_level, pName: "ui_script_spew_level", pDefaultValue: nullptr, flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__ui_script_spew_level__);
}
