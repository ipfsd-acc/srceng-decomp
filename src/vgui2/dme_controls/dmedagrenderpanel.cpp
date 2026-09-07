// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmedagrenderpanel.cpp
// Functions: 54
// ============================================================

#include "vgui2\dme_controls\dmedagrenderpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00478760
// Name: public: static char const __near * CDmeDagRenderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeDagRenderPanel::GetPanelClassName()
{
  return "CDmeDagRenderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00478770
// Name: public: void CVertexBuilder::AttachBegin(class IMesh __near *,int,struct MeshDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AttachBegin(
        CVertexBuilder *this,
        IMesh *pMesh,
        int nMaxVertexCount,
        const MeshDesc_t *desc)
{
  bool v4; // zf

  this->m_pVertexBuffer = pMesh;
  this->VertexDesc_t = desc->VertexDesc_t;
  this->m_nMaxVertexCount = nMaxVertexCount;
  this->m_NumBoneWeights = this->m_NumBoneWeights != 0 ? 2 : 0;
  v4 = this->m_nBufferOffset == -1;
  this->m_nVertexCount = 0;
  this->m_bModify = false;
  if ( v4 )
  {
    this->m_nTotalVertexCount = 0;
    this->m_nBufferOffset = desc->VertexDesc_t::m_nOffset;
    this->m_nBufferFirstVertex = desc->m_nFirstVertex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004787E0
// Name: public: void CVertexBuilder::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::Reset(CVertexBuilder *this)
{
  float *m_pNormal; // edx
  float *v2; // edx
  float *v3; // eax
  float *v4; // edx
  float *v5; // eax
  float *v6; // edx
  float *v7; // eax
  float *v8; // edx

  m_pNormal = this->m_pNormal;
  this->m_pCurrPosition = this->m_pPosition;
  this->m_nCurrentVertex = 0;
  this->m_pCurrNormal = m_pNormal;
  v2 = this->m_pTexCoord[1];
  this->m_pCurrTexCoord[0] = this->m_pTexCoord[0];
  v3 = this->m_pTexCoord[2];
  this->m_pCurrTexCoord[1] = v2;
  v4 = this->m_pTexCoord[3];
  this->m_pCurrTexCoord[2] = v3;
  v5 = this->m_pTexCoord[4];
  this->m_pCurrTexCoord[3] = v4;
  v6 = this->m_pTexCoord[5];
  this->m_pCurrTexCoord[4] = v5;
  v7 = this->m_pTexCoord[6];
  this->m_pCurrTexCoord[5] = v6;
  v8 = this->m_pTexCoord[7];
  this->m_pCurrTexCoord[6] = v7;
  this->m_pCurrTexCoord[7] = v8;
  this->m_pCurrColor = this->m_pColor;
}

//------------------------------------------------------------------------------
// Address: 0x00478860
// Name: public: void CIndexBuilder::GenerateIndices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::GenerateIndices(
        CIndexBuilder *this,
        MaterialPrimitiveType_t primitiveType,
        int nIndexCount)
{
  int v4; // edi
  unsigned __int16 *v5; // eax
  int m_nCurrentIndex; // eax

  if ( this->m_nIndexSize != 0 )
  {
    v4 = nIndexCount;
    if ( this->m_nMaxIndexCount - this->m_nCurrentIndex < nIndexCount )
      v4 = this->m_nMaxIndexCount - this->m_nCurrentIndex;
    if ( v4 != 0 )
    {
      v5 = &this->m_pIndices[this->m_nCurrentIndex];
      switch ( primitiveType )
      {
        case MATERIAL_POINTS:
        case MATERIAL_INSTANCED_QUADS:
          break;
        case MATERIAL_LINE_STRIP:
          GenerateLineStripIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_LINE_LOOP:
          GenerateLineLoopIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_POLYGON:
          GeneratePolygonIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_QUADS:
          GenerateQuadIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        default:
          GenerateSequentialIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
      }
      this->m_nCurrentIndex += v4 * this->m_nIndexSize;
      m_nCurrentIndex = this->m_nCurrentIndex;
      if ( m_nCurrentIndex > this->m_nIndexCount )
        this->m_nIndexCount = m_nCurrentIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478930
// Name: public: CMeshBuilder::~CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::~CMeshBuilder(CMeshBuilder *this)
{
  if ( this->m_VertexBuilder.m_pVertexBuffer != nullptr
    && this->m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: this->m_VertexBuilder.m_pVertexBuffer) )
  {
    this->m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: this->m_VertexBuilder.m_pVertexBuffer);
  }
  if ( this->m_IndexBuilder.m_pIndexBuffer != nullptr
    && this->m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: this->m_IndexBuilder.m_pIndexBuffer) )
  {
    this->m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: this->m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478990
// Name: public: CMeshBuilder::CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBuilder *__thiscall CMeshBuilder::CMeshBuilder(CMeshBuilder *this)
{
  this->m_pMesh = nullptr;
  this->m_bGenerateIndices = false;
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_IndexBuilder.m_nTotalIndexCount = 0;
  this->m_IndexBuilder.m_nBufferFirstIndex = 0;
  this->m_IndexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_nBufferFirstVertex = 0;
  this->m_VertexBuilder.m_nVertexCount = 0;
  this->m_VertexBuilder.m_nCurrentVertex = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_nTotalVertexCount = 0;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00478A00
// Name: private: int CMeshBuilder::IndicesFromVertices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshBuilder::IndicesFromVertices(CMeshBuilder *this, MaterialPrimitiveType_t type, int nVertexCount)
{
  int result; // eax

  switch ( type )
  {
    case MATERIAL_LINE_STRIP:
      result = 2 * nVertexCount - 2;
      break;
    case MATERIAL_LINE_LOOP:
      result = 2 * nVertexCount;
      break;
    case MATERIAL_POLYGON:
      result = 3 * nVertexCount - 6;
      break;
    case MATERIAL_QUADS:
      result = 6 * nVertexCount / 4;
      break;
    case MATERIAL_INSTANCED_QUADS:
      result = 0;
      break;
    default:
      result = nVertexCount;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00478A80
// Name: public: void CMeshBuilder::End(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::End(CMeshBuilder *this, bool bSpewData, bool bDraw)
{
  MaterialPrimitiveType_t m_Type; // edi
  int v5; // eax

  if ( this->m_bGenerateIndices )
  {
    m_Type = this->m_Type;
    v5 = CMeshBuilder::IndicesFromVertices(this, type: m_Type, nVertexCount: this->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &this->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v5);
  }
  if ( bSpewData )
    this->m_pMesh->Spew_2(
      this: this->m_pMesh,
      a2: this->m_VertexBuilder.m_nVertexCount,
      a3: this->m_IndexBuilder.m_nIndexCount,
      a4: this);
  this->m_pMesh->UnlockMesh(
    this: this->m_pMesh,
    a2: this->m_VertexBuilder.m_nVertexCount,
    a3: this->m_IndexBuilder.m_nIndexCount,
    a4: this);
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  if ( bDraw )
    this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
  this->m_pMesh = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00478B40
// Name: public: virtual void CDmeDagRenderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::ApplySchemeSettings(CDmeDagRenderPanel *this, vgui::IScheme *pScheme)
{
  CDmeDagRenderPanel_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  vgui::IScheme_vtbl *v5; // ebx
  bool v6; // al

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "MenuBorder");
  v3->SetBorder(this, a2: v4);
  v5 = pScheme->__vftable;
  v6 = this->IsProportional(this);
  this->m_hFont = v5->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00478BA0
// Name: public: virtual void CDmeDagRenderPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::PerformLayout(CDmeDagRenderPanel *this)
{
  int iMenuWidth; // [esp+4h] [ebp-10h] BYREF
  int iHeight; // [esp+8h] [ebp-Ch] BYREF
  int iWidth; // [esp+Ch] [ebp-8h] BYREF
  int iMenuHeight; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  if ( this->m_pMenuBar->IsVisible(this: this->m_pMenuBar) )
  {
    vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
    vgui::Panel::GetSize(this: this->m_pMenuBar, wide: &iMenuWidth, tall: &iMenuHeight);
    vgui::Panel::SetSize(this: this->m_pMenuBar, wide: iWidth, tall: iMenuHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478C00
// Name: private: virtual void CDmeDagRenderPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnMouseDoublePressed(CDmeDagRenderPanel *this, ButtonCode_t code)
{
  this->OnFrame(this);
  CPotteryWheelPanel::OnMouseDoublePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00478C20
// Name: private: virtual void CDmeDagRenderPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnKeyCodePressed(CDmeDagRenderPanel *this, ButtonCode_t code)
{
  CPotteryWheelPanel::OnKeyCodePressed(this, code);
  if ( code == KEY_F )
    this->OnFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x00478E60
// Name: private: void CDmeDagRenderPanel::DrawJointNames(class CDmeDag __near *,class CDmeDag __near *,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::DrawJointNames(
        CDmeDagRenderPanel *this,
        CDmeModel *pRoot,
        CDmeModel *pDag,
        const matrix3x4_t *parentToWorld)
{
  int JointIndex; // esi
  CDmeTransform *Transform; // eax
  CPotteryWheelPanel *v6; // ebx
  const char *m_pAsString; // eax
  int Phase; // ebx
  int i; // esi
  CDmeDag *Child; // eax
  char pJointName[512]; // [esp+Ch] [ebp-278h] BYREF
  matrix3x4_t jointToParent; // [esp+20Ch] [ebp-78h] BYREF
  matrix3x4_t jointToWorld; // [esp+23Ch] [ebp-48h] BYREF
  Vector vecJointOrigin; // [esp+26Ch] [ebp-18h] BYREF
  Vector2D vecPanelPos; // [esp+278h] [ebp-Ch] BYREF
  CPotteryWheelPanel *v16; // [esp+280h] [ebp-4h]

  JointIndex = -1;
  v16 = this;
  if ( pRoot == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(a1: pRoot, a2: (CUtlSymbolLarge)CDmeModel::m_classType.u.m_Id)
    || (JointIndex = CDmeModel::GetJointIndex(this: pRoot, pJoint: pDag)) >= 0
    || pRoot == pDag )
  {
    Transform = CDmeDag::GetTransform(this: pDag);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pDag != nullptr
      && ((int (__thiscall *)(_DWORD, _DWORD))pDag->IsA)(a1: pDag, a2: (CUtlSymbolLarge)CDmeJoint::m_classType.u.m_Id) )
    {
      MatrixGetColumn(in: &jointToWorld, column: 3, out: &vecJointOrigin);
      v6 = v16;
      CPotteryWheelPanel::ComputePanelPosition(this: v16, vecPosition: &vecJointOrigin, pPanelPos: &vecPanelPos);
      m_pAsString = pDag->m_Name.m_Storage.u.m_pAsString;
      if ( JointIndex < 0 )
      {
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        V_snprintf(pDest: pJointName, maxLen: 512, pFormat: "%s", m_pAsString);
      }
      else
      {
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        V_snprintf(pDest: pJointName, maxLen: 512, pFormat: "%d : %s", JointIndex, m_pAsString);
      }
      g_pMatSystemSurface->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: *(_DWORD *)&v6[1].m_InternalCursorMoved_register,
        a3: (int)(float)(vecPanelPos.x + 5.0),
        a4: (int)vecPanelPos.y,
        a5: 255,
        a6: 255,
        a7: 255,
        a8: 255,
        a9: pJointName);
    }
    Phase = CDmElementFramework::GetPhase(this: pDag);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pDag, i);
      if ( Child != nullptr )
        CDmeDagRenderPanel::DrawJointNames(
          this: (CDmeDagRenderPanel *)v16,
          pRoot,
          pDag: Child,
          parentToWorld: &jointToWorld);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479000
// Name: private: void CDmeDagRenderPanel::DrawHighlightPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::DrawHighlightPoints(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  CDmeDrawSettings *v4; // esi
  int v5; // edi
  Color m_Storage; // [esp-8h] [ebp-1Ch]
  Vector2D vecPanelPos; // [esp+4h] [ebp-10h] BYREF
  float flPointRadius; // [esp+Ch] [ebp-8h]
  int m_Size; // [esp+10h] [ebp-4h]

  if ( this->m_pDrawSettings != nullptr )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    DrawSetColor = g_pMatSystemSurface->DrawSetColor;
    m_Storage = m_pDrawSettings->m_cHighlightColor.m_Storage;
    flPointRadius = m_pDrawSettings->m_flHighlightSize.m_Storage;
    ((void (__thiscall *)(_DWORD, _DWORD))DrawSetColor)(a1: g_pMatSystemSurface, a2: m_Storage);
    v4 = this->m_pDrawSettings;
    if ( v4->m_vHighlightPoints.m_Size > 0 )
    {
      v5 = 0;
      m_Size = v4->m_vHighlightPoints.m_Size;
      do
      {
        CPotteryWheelPanel::ComputePanelPosition(
          this,
          vecPosition: &v4->m_vHighlightPoints.m_Memory.m_pMemory[v5],
          pPanelPos: &vecPanelPos);
        g_pMatSystemSurface->DrawFilledRect(
          this: g_pMatSystemSurface,
          a2: (int)(float)(vecPanelPos.x - flPointRadius),
          a3: (int)(float)(vecPanelPos.y - flPointRadius),
          a4: (int)(float)(vecPanelPos.x + flPointRadius),
          a5: (int)(float)(vecPanelPos.y + flPointRadius));
        ++v5;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004790C0
// Name: private: virtual void CDmeDagRenderPanel::OnFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnFrame(CDmeDagRenderPanel *this)
{
  CDmeDag *v2; // edi
  char v3; // al
  matrix3x4_t dmeToEngine; // [esp+10h] [ebp-7Ch] BYREF
  matrix3x4_t matrix; // [esp+40h] [ebp-4Ch] BYREF
  Vector vecWorldCenter; // [esp+70h] [ebp-1Ch] BYREF
  Vector vecCenter; // [esp+7Ch] [ebp-10h] BYREF
  float flRadius; // [esp+88h] [ebp-4h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle) != nullptr )
  {
    v2 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
    SetIdentityMatrix(&matrix);
    CDmeDag::GetBoundingSphere(this: v2, c0: &vecCenter, r0: &flRadius, pMat: (int)&matrix);
    v3 = *((_BYTE *)this + 1216);
    if ( (v3 & 0x10) == 0 )
      CDmeDag::DmeToEngineMatrix(&dmeToEngine, bZUp: (v3 & 0x20) != 0);
    VectorTransform(in1: &vecCenter.x, in2: &dmeToEngine, out: &vecWorldCenter.x);
    CPotteryWheelPanel::LookAt(this, vecCenter: &vecWorldCenter, flRadius);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479170
// Name: private: void CDmeDagRenderPanel::DrawAxis(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeDagRenderPanel::DrawAxis(CDmeDagRenderPanel *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  int v4; // esi
  IMesh *v5; // edi
  float *m_pCurrPosition; // eax
  int v7; // eax
  float *v8; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int m_nVertexCount; // eax
  int v18; // ecx
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a2);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
      a1: v4,
      a2: this->m_axisMaterial.m_pMaterial,
      a3: 0);
    v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                    a1: v4,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v7 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v7;
    if ( v7 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v7;
    v8 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                 + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v8;
    *v8 = 10.0;
    v8[1] = 0.0;
    v8[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 0.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 10.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 10.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v18 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v18;
    if ( v18 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v18;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v18;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh, a2: m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479500
// Name: private: void CDmeDagRenderPanel::UpdateMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::UpdateMenu(CDmeDagRenderPanel *this)
{
  switch ( this->m_pDrawSettings->m_DrawType.m_Storage <= 3u ? this->m_pDrawSettings->m_DrawType.m_Storage : 0 )
  {
    case 1:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: true);
      goto LABEL_8;
    case 2:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: true);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: false);
      break;
    case 3:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: true);
      break;
    default:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: true);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
LABEL_8:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: false);
      break;
  }
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuNormals,
    state: this->m_pDrawSettings->m_bNormals.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuWireframeOnShaded,
    state: this->m_pDrawSettings->m_bWireframeOnShaded.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuBackfaceCulling,
    state: this->m_pDrawSettings->m_bBackfaceCulling.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuXRay,
    state: this->m_pDrawSettings->m_bXRay.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuGrayShade,
    state: this->m_pDrawSettings->m_bGrayShade.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00479740
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeDag *pScene)
{
  DmElementHandle_t BufferType; // eax
  CDmeDag *v4; // eax
  int v5; // eax
  CDmeModel *v6; // esi
  DmElementHandle_t m_handle; // [esp-8h] [ebp-10h]

  if ( pScene != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pScene);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
  m_handle = this->m_hDag.m_handle;
  v4 = (CDmeDag *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
  ComputeDefaultTangentData(pDag: v4, bSmoothTangents: m_handle);
  v5 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
         a1: g_pDataModel,
         a2: this->m_hDag.m_handle,
         a3: 0);
  v6 = (CDmeModel *)v5;
  if ( v5 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeModel::m_classType.u) != 0 )
  {
    *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v6))) & 0x20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004797E0
// Name: private: virtual void CDmeDagRenderPanel::OnSmoothShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnSmoothShade(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 0;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479830
// Name: private: virtual void CDmeDagRenderPanel::OnFlatShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnFlatShade(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 1;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479880
// Name: private: virtual void CDmeDagRenderPanel::OnWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnWireframe(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 2;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x004798D0
// Name: private: virtual void CDmeDagRenderPanel::OnBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnBoundingBox(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 3;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479920
// Name: private: virtual void CDmeDagRenderPanel::OnNormals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnNormals(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuNormals);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bNormals.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479960
// Name: private: virtual void CDmeDagRenderPanel::OnWireframeOnShaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnWireframeOnShaded(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframeOnShaded);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bWireframeOnShaded.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x004799A0
// Name: private: virtual void CDmeDagRenderPanel::OnBackfaceCulling(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnBackfaceCulling(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBackfaceCulling);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bBackfaceCulling.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x004799E0
// Name: private: virtual void CDmeDagRenderPanel::OnXRay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnXRay(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuXRay);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bXRay.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479A20
// Name: private: virtual void CDmeDagRenderPanel::OnGrayShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnGrayShade(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuGrayShade);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bGrayShade.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479A60
// Name: public: virtual void CDmeDagRenderPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeDagRenderPanel::Paint(CDmeDagRenderPanel *this)
{
  int v2; // edi
  CDmeClip *v3; // eax
  CDmeClip *v4; // eax
  int v5; // edi
  CDmeClip *v6; // eax
  DmeTime_t v7; // edi
  CDmeClip *v8; // eax
  int v9; // ebx
  CDmElement *v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  CDmeChannel *v13; // edi
  int v14; // edi
  CDmeClip *v15; // eax
  int m_tms; // ebx
  CDmeClip *v17; // eax
  int v18; // edi
  CDmeClip *v19; // eax
  int v20; // ebx
  CDmElement *v21; // eax
  CDmElement *v22; // eax
  CDmElement *v23; // edi
  CDmeChannel *v24; // ecx
  char v25; // al
  CDmeModel *v26; // eax
  CDmeModel *sec_4; // [esp+20h] [ebp-54h]
  const matrix3x4_t *v28; // [esp+24h] [ebp-50h]
  matrix3x4_t modelToWorld; // [esp+34h] [ebp-40h] BYREF
  unsigned __int64 sec; // [esp+64h] [ebp-10h] OVERLAPPED BYREF
  unsigned __int64 v31; // [esp+6Ch] [ebp-8h] OVERLAPPED BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle) != nullptr )
  {
    *(double *)&sec = _Plat_FloatTime() - this->m_flStartTime;
    v2 = DmeTime_t::RoundSecondsToTMS(sec);
    v3 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
    if ( CDmeClip::GetDuration(this: v3, result: (DmeTime_t *)&sec + 1)->m_tms != 0 )
    {
      v4 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
      v5 = v2 % CDmeClip::GetDuration(this: v4, result: (DmeTime_t *)&sec + 1)->m_tms;
    }
    else
    {
      v5 = 0;
    }
    v6 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
    v7.m_tms = CDmeClip::GetStartTime(this: v6, result: (DmeTime_t *)&sec + 1)->m_tms + v5;
    v8 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
    CDmeClip::ToChildMediaTime(this: v8, result: (DmeTime_t *)&v31 + 1, t: v7, bClamp: 1);
    v9 = 0;
    for ( HIDWORD(sec) = *(_DWORD *)&g_pDataModel->GetElement(
                                       this: g_pDataModel,
                                       a2: this->m_hCurrentAnimation.m_handle)[2].m_Id.m_Value[12]; v9 < SHIDWORD(sec); ++v9 )
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v10[2].m_Id.m_Value + 4 * v9));
      v12 = v11;
      if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeChannel::m_classType) )
        v13 = (CDmeChannel *)((char *)&v12[-1] + 64);
      else
        v13 = nullptr;
      CDmeChannel::SetCurrentTime(this: v13, time: *(DmeTime_t *)((char *)&v31 + 4));
    }
  }
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle) != nullptr )
  {
    *(double *)&v31 = _Plat_FloatTime() - this->m_flStartTime;
    v14 = DmeTime_t::RoundSecondsToTMS(sec: v31);
    v15 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
    m_tms = CDmeClip::GetDuration(this: v15, result: (DmeTime_t *)&v31 + 1)->m_tms;
    v17 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
    v18 = CDmeClip::GetStartTime(this: v17, result: (DmeTime_t *)&v31 + 1)->m_tms + v14 % m_tms;
    v19 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
    CDmeClip::ToChildMediaTime(this: v19, result: (DmeTime_t *)&sec + 1, t: (DmeTime_t)v18, bClamp: 1);
    v20 = 0;
    for ( HIDWORD(v31) = *(_DWORD *)&g_pDataModel->GetElement(
                                       this: g_pDataModel,
                                       a2: this->m_hCurrentVertexAnimation.m_handle)[2].m_Id.m_Value[12];
          v20 < SHIDWORD(v31);
          ++v20 )
    {
      v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
      v22 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v21[2].m_Id.m_Value + 4 * v20));
      v23 = v22;
      if ( v22 != nullptr && v22->IsA(this: v22, a2: CDmeChannel::m_classType) )
        v24 = (CDmeChannel *)((char *)&v23[-1] + 64);
      else
        v24 = nullptr;
      CDmeChannel::SetCurrentTime(this: v24, time: *(DmeTime_t *)((char *)&sec + 4));
    }
  }
  BYTE4(sec) = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: &this->m_operators);
  g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: HIDWORD(sec));
  g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
  CPotteryWheelPanel::Paint(this);
  if ( (*((_BYTE *)this + 1216) & 1) != 0
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle) != nullptr )
  {
    v25 = *((_BYTE *)this + 1216);
    if ( (v25 & 0x10) == 0 )
      CDmeDag::DmeToEngineMatrix(dmeToEngine: &modelToWorld, bZUp: (v25 & 0x20) != 0);
    v28 = (const matrix3x4_t *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
    sec_4 = (CDmeModel *)this->m_hDag.m_handle;
    v26 = (CDmeModel *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
    CDmeDagRenderPanel::DrawJointNames(this, pRoot: v26, pDag: sec_4, parentToWorld: v28);
  }
  CDmeDagRenderPanel::DrawHighlightPoints(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479E00
// Name: private: virtual void CDmeDagRenderPanel::OnPaint3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnPaint3D(CDmeDagRenderPanel *this)
{
  IMatRenderContext *v2; // esi
  int v3; // ebx
  ITexture *m_pTexture; // ecx
  CDmeDag *v5; // eax

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = (int)v2->GetLocalCubemap(this: v2);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
    m_pTexture = this->m_DefaultHDREnvCubemap.m_pTexture;
  else
    m_pTexture = this->m_DefaultEnvCubemap.m_pTexture;
  v2->BindLocalCubemap(this: v2, a2: m_pTexture);
  if ( (*((_BYTE *)this + 1216) & 4) != 0 )
    CPotteryWheelPanel::DrawGrid(this);
  if ( (*((_BYTE *)this + 1216) & 2) != 0 )
    CDmeJoint::DrawJointHierarchy(bDrawJoints: true);
  v2->CullMode(this: v2, a2: MATERIAL_CULLMODE_CW);
  CDmeDag::DrawUsingEngineCoordinates(bEnable: (*((_BYTE *)this + 1216) & 0x10) == 0);
  CDmeDag::DrawZUp(bZUp: (*((_BYTE *)this + 1216) & 0x20) != 0);
  v5 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
  CDmeDrawSettings::DrawDag(this: this->m_pDrawSettings, pDag: v5);
  CDmeDag::DrawUsingEngineCoordinates(bEnable: false);
  CDmeDag::DrawZUp(bZUp: false);
  if ( (*((_BYTE *)this + 1216) & 8) != 0 )
    CDmeDagRenderPanel::DrawAxis(this, a2: v3, a3: (int)v2);
  v2->Flush(this: v2, a2: false);
  v2->BindLocalCubemap(this: v2, a2: (ITexture *)v3);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00479F50
// Name: public: virtual CDmeDagRenderPanel::~CDmeDagRenderPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::~CDmeDagRenderPanel(CDmeDagRenderPanel *this)
{
  this->__vftable = (CDmeDagRenderPanel_vtbl *)&CDmeDagRenderPanel::`vftable';
  if ( g_pMaterialSystem != nullptr )
    CMaterialReference::Shutdown(this: &this->m_axisMaterial, bDeleteIfUnreferenced: false);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hDrawSettings,
      hElement: this->m_hDrawSettings.m_handle,
      handleType: HT_STRONG);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hDag, hElement: this->m_hDag.m_handle, handleType: HT_WEAK);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_operators);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hCurrentVertexAnimation,
      hElement: this->m_hCurrentVertexAnimation.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hCurrentAnimation,
      hElement: this->m_hCurrentAnimation.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hVertexAnimationList,
      hElement: this->m_hVertexAnimationList.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hAnimationList,
      hElement: this->m_hAnimationList.m_handle,
      handleType: HT_WEAK);
  CMaterialReference::~CMaterialReference(this: &this->m_axisMaterial);
  CTextureReference::~CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047A040
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeDagRenderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeDagRenderPanel::GetMessageMap(CDmeDagRenderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeDagRenderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagRenderPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeDagRenderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
  `CDmeDagRenderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047A070
// Name: public: virtual struct PanelAnimationMap __near * CDmeDagRenderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeDagRenderPanel::GetAnimMap(CDmeDagRenderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeDagRenderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0047A080
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeDagRenderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeDagRenderPanel::GetKBMap(CDmeDagRenderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeDagRenderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagRenderPanel::GetKBMap'::`2'::s_pMap;
  `CDmeDagRenderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagRenderPanel");
  `CDmeDagRenderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047A1D0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SmoothShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A260
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FlatShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A2F0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Wireframe";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A380
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BoundingBox";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A410
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Normals";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A4A0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "WireframeOnShaded";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A530
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BackfaceCulling";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A5C0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "XRay";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A650
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "GrayShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A6E0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Frame";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A770
// Name: public: CDmeDagRenderPanel::CDmeDagRenderPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmeDagRenderPanel::CDmeDagRenderPanel(
        CDmeDagRenderPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IDataModel_vtbl *v7; // edx
  bool v8; // al
  IDataModel_vtbl *v9; // edx
  ITexture *v10; // eax
  ITexture *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  DmFileId_t v14; // eax
  DmElementHandle_t v15; // eax
  CDmElement *v16; // eax
  CDmeDrawSettings *v17; // edi
  DmElementHandle_t BufferType; // eax
  vgui::MenuBar *v19; // eax
  vgui::MenuBar *v20; // eax
  vgui::Menu *v21; // eax
  vgui::Menu *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  int v29; // eax
  vgui::Menu *m_pShadingMenu; // ecx
  KeyValues *v31; // eax
  KeyValues *v32; // eax
  int v33; // eax
  vgui::Menu *v34; // ecx
  KeyValues *v35; // eax
  KeyValues *v36; // eax
  KeyValues *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // eax
  KeyValues *v40; // eax
  KeyValues *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // eax
  KeyValues *v44; // eax
  int v45; // eax
  vgui::Menu *v46; // ecx
  CDisableUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CPotteryWheelPanel::CPotteryWheelPanel(this, pParent, pName);
  this->__vftable = (CDmeDagRenderPanel_vtbl *)&CDmeDagRenderPanel::`vftable';
  if ( `CDmeDagRenderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v4->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  }
  if ( `CDmeDagRenderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeDagRenderPanel");
    v5->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
  }
  if ( `CDmeDagRenderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagRenderPanel");
    v6->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  }
  CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(a1: (int)&savedregs);
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CMaterialReference::CMaterialReference(
    this: &this->m_axisMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_hAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hVertexAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hCurrentAnimation.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hCurrentVertexAnimation.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  this->m_hDag.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hDrawSettings.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = g_pDataModel->__vftable;
  *(_WORD *)&sg.m_bReleased = 0;
  sg.m_pNotify = nullptr;
  v8 = v7->IsUndoEnabled(this: g_pDataModel);
  v9 = g_pDataModel->__vftable;
  sg.m_bOldValue = v8;
  v9->SetUndoEnabled(this: g_pDataModel, a2: false);
  *((_BYTE *)this + 1216) = *((_BYTE *)this + 1216) & 0xC0 | 0xC;
  v10 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "editor/cubemap", a3: 0, a4: 1, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v10);
  v11 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "editor/cubemap.hdr", a3: 0, a4: 1, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultHDREnvCubemap, pTexture: v11);
  if ( g_pMaterialSystem != nullptr )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v13 = KeyValues::KeyValues(this: v12, setName: "wireframe");
    else
      v13 = nullptr;
    KeyValues::SetInt(this: v13, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v13, keyName: "$ignorez", value: 1);
    CMaterialReference::Init(this: &this->m_axisMaterial, pMaterialName: "__DmeDagRenderPanelAxis", pVMTKeyValues: v13);
  }
  v14 = g_pDataModel->FindOrCreateFileId(this: g_pDataModel, a2: "DagRenderPanelDrawSettings");
  v15 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeDrawSettings::m_classType.u.m_Id,
          a3: "drawSettings",
          a4: v14,
          a5: nullptr);
  v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: v15);
  v17 = (CDmeDrawSettings *)v16;
  if ( v16 == nullptr || !v16->IsA(this: v16, a2: CDmeDrawSettings::m_classType) )
    v17 = nullptr;
  this->m_pDrawSettings = v17;
  if ( v17 != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDrawSettings,1>::Set(this: &this->m_hDrawSettings, h: BufferType);
  v19 = (vgui::MenuBar *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v19 != nullptr )
    v20 = vgui::MenuBar::MenuBar(this: v19, parent: this, panelName: "Dag Render Panel Menu Bar");
  else
    v20 = nullptr;
  this->m_pMenuBar = v20;
  v21 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v21 != nullptr )
    v22 = vgui::Menu::Menu(this: v21, parent: nullptr, panelName: "Shading Menu");
  else
    v22 = nullptr;
  this->m_pShadingMenu = v22;
  v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v23 != nullptr )
    v24 = KeyValues::KeyValues(this: v23, setName: "SmoothShade");
  else
    v24 = nullptr;
  this->m_nMenuSmoothShade = this->m_pShadingMenu->AddCheckableMenuItem(
                               this: this->m_pShadingMenu,
                               a2: "&Smooth Shade",
                               a3: v24,
                               a4: this,
                               a5: nullptr);
  v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v25 != nullptr )
    v26 = KeyValues::KeyValues(this: v25, setName: "FlatShade");
  else
    v26 = nullptr;
  this->m_nMenuFlatShade = this->m_pShadingMenu->AddCheckableMenuItem(
                             this: this->m_pShadingMenu,
                             a2: "&Flat Shade",
                             a3: v26,
                             a4: this,
                             a5: nullptr);
  v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v27 != nullptr )
    v28 = KeyValues::KeyValues(this: v27, setName: "Wireframe");
  else
    v28 = nullptr;
  v29 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Wireframe",
          a3: v28,
          a4: this,
          a5: nullptr);
  m_pShadingMenu = this->m_pShadingMenu;
  this->m_nMenuWireframe = v29;
  m_pShadingMenu->AddSeparator(this: m_pShadingMenu);
  v31 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v31 != nullptr )
    v32 = KeyValues::KeyValues(this: v31, setName: "BoundingBox");
  else
    v32 = nullptr;
  v33 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Bounding Box",
          a3: v32,
          a4: this,
          a5: nullptr);
  v34 = this->m_pShadingMenu;
  this->m_nMenuBoundingBox = v33;
  v34->AddSeparator(this: v34);
  v35 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v35 != nullptr )
    v36 = KeyValues::KeyValues(this: v35, setName: "Normals");
  else
    v36 = nullptr;
  this->m_nMenuNormals = this->m_pShadingMenu->AddCheckableMenuItem(
                           this: this->m_pShadingMenu,
                           a2: "&Normals",
                           a3: v36,
                           a4: this,
                           a5: nullptr);
  v37 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v37 != nullptr )
    v38 = KeyValues::KeyValues(this: v37, setName: "WireframeOnShaded");
  else
    v38 = nullptr;
  this->m_nMenuWireframeOnShaded = this->m_pShadingMenu->AddCheckableMenuItem(
                                     this: this->m_pShadingMenu,
                                     a2: "WireFrame &On Shaded",
                                     a3: v38,
                                     a4: this,
                                     a5: nullptr);
  v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v39 != nullptr )
    v40 = KeyValues::KeyValues(this: v39, setName: "BackfaceCulling");
  else
    v40 = nullptr;
  this->m_nMenuBackfaceCulling = this->m_pShadingMenu->AddCheckableMenuItem(
                                   this: this->m_pShadingMenu,
                                   a2: "&Backface Culling",
                                   a3: v40,
                                   a4: this,
                                   a5: nullptr);
  v41 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v41 != nullptr )
    v42 = KeyValues::KeyValues(this: v41, setName: "XRay");
  else
    v42 = nullptr;
  this->m_nMenuXRay = this->m_pShadingMenu->AddCheckableMenuItem(
                        this: this->m_pShadingMenu,
                        a2: "&X-Ray",
                        a3: v42,
                        a4: this,
                        a5: nullptr);
  v43 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v43 != nullptr )
    v44 = KeyValues::KeyValues(this: v43, setName: "GrayShade");
  else
    v44 = nullptr;
  v45 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Gray Shade",
          a3: v44,
          a4: this,
          a5: nullptr);
  v46 = this->m_pShadingMenu;
  this->m_nMenuGrayShade = v45;
  v46->SetItemVisible(this: v46, a2: this->m_nMenuFlatShade, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuFlatShade, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuBoundingBox, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuBoundingBox, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuBackfaceCulling, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuBackfaceCulling, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuXRay, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuXRay, a3: false);
  this->m_pMenuBar->AddMenu(this: this->m_pMenuBar, a2: "&Shading", a3: this->m_pShadingMenu);
  CDmeDagRenderPanel::UpdateMenu(this);
  CChangeUndoScopeGuard::Release(this: &sg);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047ADF0
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeSourceSkin __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeSourceSkin *pSkin)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax
  CDmeModel *v5; // ebx
  CExpressionCalculator *Value; // eax
  DmElementHandle_t BufferType; // eax
  CDmeDag *v8; // eax
  int v9; // eax
  CDmeModel *v10; // edi
  CDmeModel *v11; // ecx
  DmElementHandle_t m_handle; // [esp-8h] [ebp-14h]

  DependentMakefile = CDmeSource::GetDependentMakefile(this: pSkin);
  if ( DependentMakefile == nullptr
    || (OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true),
        v5 = (CDmeModel *)OutputElement,
        OutputElement == nullptr) )
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
    return;
  }
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
  if ( Value != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: Value);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
  m_handle = this->m_hDag.m_handle;
  v8 = (CDmeDag *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
  ComputeDefaultTangentData(pDag: v8, bSmoothTangents: m_handle);
  *((_BYTE *)this + 1216) &= 0xFCu;
  v9 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
         a1: g_pDataModel,
         a2: this->m_hDag.m_handle,
         a3: 0);
  v10 = (CDmeModel *)v9;
  if ( v9 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
         a1: v9,
         a2: CDmeModel::m_classType.u) != 0 )
  {
    v11 = v10;
  }
  else
  {
    if ( !v5->IsA(this: v5, a2: CDmeModel::m_classType) )
      return;
    v11 = v5;
  }
  *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v11))) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x0047AEF0
// Name: private: void CDmeDagRenderPanel::RebuildOperatorList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::RebuildOperatorList(CDmeDagRenderPanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // edi
  CDmeChannel *v5; // ecx
  CDmElement *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v12; // eax
  IDmeOperator **v13; // eax
  CDmElement *v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmeChannel *v17; // ecx
  CDmElement *v18; // eax
  CDmElement *v19; // eax
  CDmElement *v20; // edi
  int v21; // edi
  int v22; // eax
  IDmeOperator **v23; // ecx
  int v24; // eax
  IDmeOperator **v25; // eax
  int nChannelCount; // [esp+Ch] [ebp-Ch]
  int nChannelCounta; // [esp+Ch] [ebp-Ch]
  IDmeOperator *v28; // [esp+10h] [ebp-8h]
  IDmeOperator *v29; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int ia; // [esp+14h] [ebp-4h]

  this->m_operators.m_Size = 0;
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle) != nullptr )
  {
    nChannelCount = *(_DWORD *)&g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle)[2].m_Id.m_Value[12];
    for ( i = 0; i < nChannelCount; ++i )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v2[2].m_Id.m_Value + 4 * i));
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeChannel::m_classType) )
        v5 = (CDmeChannel *)((char *)&v4[-1] + 64);
      else
        v5 = nullptr;
      CDmeChannel::SetMode(this: v5, mode: CM_PLAY);
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v6[2].m_Id.m_Value + 4 * i));
      v8 = v7;
      if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeChannel::m_classType) )
        v28 = (IDmeOperator *)((char *)&v8[-1] + 64);
      else
        v28 = nullptr;
      m_Size = this->m_operators.m_Size;
      m_nAllocationCount = this->m_operators.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_operators,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_operators.m_Size;
      m_pMemory = this->m_operators.m_Memory.m_pMemory;
      v12 = this->m_operators.m_Size - m_Size - 1;
      this->m_operators.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &this->m_operators.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = v28;
    }
  }
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle) != nullptr )
  {
    nChannelCounta = *(_DWORD *)&g_pDataModel->GetElement(
                                   this: g_pDataModel,
                                   a2: this->m_hCurrentVertexAnimation.m_handle)[2].m_Id.m_Value[12];
    for ( ia = 0; ia < nChannelCounta; ++ia )
    {
      v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v14[2].m_Id.m_Value + 4 * ia));
      v16 = v15;
      if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeChannel::m_classType) )
        v17 = (CDmeChannel *)((char *)&v16[-1] + 64);
      else
        v17 = nullptr;
      CDmeChannel::SetMode(this: v17, mode: CM_PLAY);
      v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
      v19 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v18[2].m_Id.m_Value + 4 * ia));
      v20 = v19;
      if ( v19 != nullptr && v19->IsA(this: v19, a2: CDmeChannel::m_classType) )
        v29 = (IDmeOperator *)((char *)&v20[-1] + 64);
      else
        v29 = nullptr;
      v21 = this->m_operators.m_Size;
      v22 = this->m_operators.m_Memory.m_nAllocationCount;
      if ( v21 + 1 > v22 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_operators,
          num: v21 - v22 + 1);
      ++this->m_operators.m_Size;
      v23 = this->m_operators.m_Memory.m_pMemory;
      v24 = this->m_operators.m_Size - v21 - 1;
      this->m_operators.m_pElements = v23;
      if ( v24 > 0 )
        _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 4 * v24);
      v25 = &this->m_operators.m_Memory.m_pMemory[v21];
      if ( v25 != nullptr )
        *v25 = v29;
    }
  }
  this->m_flStartTime = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x0047B220
// Name: private: void CDmeDagRenderPanel::SelectAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectAnimation(CDmeDagRenderPanel *this, int nIndex)
{
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CExpressionCalculator *v6; // ecx
  DmElementHandle_t BufferType; // eax

  CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle) != nullptr && nIndex >= 0 )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle);
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v3[1].OnAttributeChanged + nIndex));
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
      v6 = (CExpressionCalculator *)v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: BufferType);
  }
  CDmeDagRenderPanel::RebuildOperatorList(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047B2D0
// Name: private: void CDmeDagRenderPanel::SelectVertexAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectVertexAnimation(CDmeDagRenderPanel *this, int nIndex)
{
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CExpressionCalculator *v6; // ecx
  DmElementHandle_t BufferType; // eax

  CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle) != nullptr && nIndex >= 0 )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle);
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v3[1].OnAttributeChanged + nIndex));
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
      v6 = (CExpressionCalculator *)v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: BufferType);
  }
  CDmeDagRenderPanel::RebuildOperatorList(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047B380
// Name: public: void CDmeDagRenderPanel::SelectAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectAnimation(CDmeDagRenderPanel *this, const char *pAnimName)
{
  CDmeAnimationList *v3; // eax
  int Animation; // eax

  if ( *pAnimName != 0 )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle) != nullptr )
    {
      v3 = (CDmeAnimationList *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle);
      Animation = CDmeAnimationList::FindAnimation(this: v3, pAnimName);
      if ( Animation >= 0 )
        CDmeDagRenderPanel::SelectAnimation(this, nIndex: Animation);
    }
  }
  else
  {
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
    g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle);
    CDmeDagRenderPanel::RebuildOperatorList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B410
// Name: public: void CDmeDagRenderPanel::SelectVertexAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectVertexAnimation(CDmeDagRenderPanel *this, const char *pAnimName)
{
  CDmeAnimationList *v3; // eax
  int Animation; // eax

  if ( *pAnimName != 0 )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle) != nullptr )
    {
      v3 = (CDmeAnimationList *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle);
      Animation = CDmeAnimationList::FindAnimation(this: v3, pAnimName);
      if ( Animation >= 0 )
        CDmeDagRenderPanel::SelectVertexAnimation(this, nIndex: Animation);
    }
  }
  else
  {
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
    g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle);
    CDmeDagRenderPanel::RebuildOperatorList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B4A0
// Name: public: void CDmeDagRenderPanel::SetAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetAnimationList(CDmeDagRenderPanel *this, CExpressionCalculator *pAnimationList)
{
  DmElementHandle_t BufferType; // eax

  if ( pAnimationList != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pAnimationList);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hAnimationList, h: BufferType);
  if ( pAnimationList != nullptr && pAnimationList[1].m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    CDmeDagRenderPanel::SelectAnimation(this, nIndex: 0);
  else
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x0047B500
// Name: public: void CDmeDagRenderPanel::SetVertexAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetVertexAnimationList(
        CDmeDagRenderPanel *this,
        CExpressionCalculator *pAnimationList)
{
  DmElementHandle_t BufferType; // eax

  if ( pAnimationList != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pAnimationList);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hVertexAnimationList, h: BufferType);
  if ( pAnimationList != nullptr && pAnimationList[1].m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    CDmeDagRenderPanel::SelectVertexAnimation(this, nIndex: 0);
  else
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x0047B660
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeSourceAnimation __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeDagRenderPanel::SetDmeElement(
        CDmeDagRenderPanel *this@<ecx>,
        bool a2@<bl>,
        CDmeSourceAnimation *pAnimation)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax
  CDmElement *v6; // edi
  CDmeDag *Value; // ebx
  CDmeAnimationList *v8; // eax
  const char *m_pAsString; // edx
  CDmeDag *v10; // eax
  const char *v11; // eax
  CDmElement *v12; // eax
  CDmeModel *v13; // eax
  CDmeAnimationList *pAnimationList; // [esp+8h] [ebp-4h]

  DependentMakefile = CDmeSource::GetDependentMakefile(this: pAnimation);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    v6 = OutputElement;
    if ( OutputElement != nullptr )
    {
      Value = CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
      if ( Value != nullptr
        || (Value = CDmElement::GetValueElement<CDmeDag>(this: v6, pAttributeName: "skeleton")) != nullptr )
      {
        v8 = CDmElement::GetValueElement<CDmeAnimationList>(this: v6, pAttributeName: "animationList");
        pAnimationList = v8;
        if ( v8 != nullptr )
        {
          m_pAsString = pAnimation->m_SourceAnimationName.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          if ( CDmeAnimationList::FindAnimation(this: v8, pAnimName: m_pAsString) >= 0 )
          {
            CDmeHandle<CDmeDag,0>::operator=(this: &this->m_hDag, pObject: Value);
            v10 = (CDmeDag *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                               a1: g_pDataModel,
                               a2: this->m_hDag.m_handle,
                               a3: 0);
            ComputeDefaultTangentData(pDag: v10, bSmoothTangents: a2);
            CDmeHandle<CDmeAnimationList,0>::operator=(this: &this->m_hAnimationList, pObject: pAnimationList);
            v11 = pAnimation->m_SourceAnimationName.m_Storage.u.m_pAsString;
            if ( v11 == (const char *)-1 )
              v11 = defaultValue;
            CDmeDagRenderPanel::SelectAnimation(this, pAnimName: v11);
            *((_BYTE *)this + 1216) |= 3u;
            v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
            v13 = CastElement<CDmeModel>(pElement: v12);
            if ( v13 != nullptr || (v13 = CastElement<CDmeModel>(pElement: v6)) != nullptr )
              *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v13))) & 0x20;
          }
        }
      }
    }
    else
    {
      CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
    }
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B7C0
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeDCCMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeDag *pDCCMakefile)
{
  CDmElement *OutputElement; // eax
  CDmElement *v4; // edi
  CExpressionCalculator *Value; // ebx
  DmElementHandle_t BufferType; // eax
  CDmeDag *v7; // eax
  DmElementHandle_t v8; // eax
  DmElementHandle_t m_handle; // edx
  CDmElement *v10; // eax
  CDmeModel *v11; // edi
  CDmElement *pOutputElement; // [esp+Ch] [ebp-4h]
  CDmeDag *pDag; // [esp+18h] [ebp+8h]

  OutputElement = CDmeMakefile::GetOutputElement(this: (CDmeMakefile *)pDCCMakefile, bCreateIfNecessary: true);
  v4 = OutputElement;
  pOutputElement = OutputElement;
  if ( OutputElement != nullptr )
  {
    pDag = CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
    if ( pDag != nullptr
      || (pDag = CDmElement::GetValueElement<CDmeDag>(this: v4, pAttributeName: "skeleton")) != nullptr )
    {
      Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmeAnimationList>(
                                         this: v4,
                                         pAttributeName: "animationList");
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDag);
      CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
      v7 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
      ComputeDefaultTangentData(pDag: v7, bSmoothTangents: false);
      v8 = Value != nullptr ? CCodecBuffer_Block::GetBufferType(this: Value) : DMELEMENT_HANDLE_INVALID;
      if ( (CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hAnimationList, h: v8),
            CDmeDagRenderPanel::SelectAnimation(this, nIndex: 0),
            m_handle = this->m_hDag.m_handle,
            *((_BYTE *)this + 1216) = (Value != nullptr) | *((_BYTE *)this + 1216) & 0xFC | (2 * (Value != nullptr)),
            v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle),
            v11 = (CDmeModel *)v10,
            v10 != nullptr)
        && v10->IsA(this: v10, a2: CDmeModel::m_classType)
        || (v11 = (CDmeModel *)pOutputElement, pOutputElement->IsA(this: pOutputElement, a2: CDmeModel::m_classType)) )
      {
        *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v11))) & 0x20;
      }
    }
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
  }
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1047E4C0
// Name: public: static char const __near * CDmeDagRenderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeDagRenderPanel::GetPanelClassName()
{
  return "CDmeDagRenderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1047E4D0
// Name: public: virtual void CDmeDagRenderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::ApplySchemeSettings(CDmeDagRenderPanel *this, vgui::IScheme *pScheme)
{
  CDmeDagRenderPanel_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  vgui::IScheme_vtbl *v5; // ebx
  bool v6; // al

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "MenuBorder");
  v3->SetBorder(this, a2: v4);
  v5 = pScheme->__vftable;
  v6 = this->IsProportional(this);
  this->m_hFont = v5->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1047E530
// Name: public: virtual void CDmeDagRenderPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::PerformLayout(CDmeDagRenderPanel *this)
{
  int iMenuWidth; // [esp+4h] [ebp-10h] BYREF
  int iHeight; // [esp+8h] [ebp-Ch] BYREF
  int iWidth; // [esp+Ch] [ebp-8h] BYREF
  int iMenuHeight; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  if ( this->m_pMenuBar->IsVisible(this: this->m_pMenuBar) )
  {
    vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
    vgui::Panel::GetSize(this: this->m_pMenuBar, wide: &iMenuWidth, tall: &iMenuHeight);
    vgui::Panel::SetSize(this: this->m_pMenuBar, wide: iWidth, tall: iMenuHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047E590
// Name: private: virtual void CDmeDagRenderPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnMouseDoublePressed(CDmeDagRenderPanel *this, ButtonCode_t code)
{
  this->OnFrame(this);
  CPotteryWheelPanel::OnMouseDoublePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1047E5B0
// Name: private: virtual void CDmeDagRenderPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnKeyCodePressed(CDmeDagRenderPanel *this, ButtonCode_t code)
{
  CPotteryWheelPanel::OnKeyCodePressed(this, code);
  if ( code == KEY_F )
    this->OnFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047E7E0
// Name: private: void CDmeDagRenderPanel::DrawJointNames(class CDmeDag __near *,class CDmeDag __near *,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::DrawJointNames(
        CDmeDagRenderPanel *this,
        CDmeModel *pRoot,
        CDmeModel *pDag,
        const matrix3x4_t *parentToWorld)
{
  int JointIndex; // esi
  CDmeTransform *Transform; // eax
  CPotteryWheelPanel *v6; // ebx
  const char *m_pAsString; // eax
  int Phase; // ebx
  int i; // esi
  CDmeDag *Child; // eax
  char pJointName[512]; // [esp+Ch] [ebp-278h] BYREF
  matrix3x4_t jointToParent; // [esp+20Ch] [ebp-78h] BYREF
  matrix3x4_t jointToWorld; // [esp+23Ch] [ebp-48h] BYREF
  Vector vecJointOrigin; // [esp+26Ch] [ebp-18h] BYREF
  Vector2D vecPanelPos; // [esp+278h] [ebp-Ch] BYREF
  CPotteryWheelPanel *v16; // [esp+280h] [ebp-4h]

  JointIndex = -1;
  v16 = this;
  if ( pRoot == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(a1: pRoot, a2: (CUtlSymbolLarge)CDmeModel::m_classType.u.m_Id)
    || (JointIndex = CDmeModel::GetJointIndex(this: pRoot, pJoint: pDag)) >= 0
    || pRoot == pDag )
  {
    Transform = CDmeDag::GetTransform(this: pDag);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pDag != nullptr
      && ((int (__thiscall *)(_DWORD, _DWORD))pDag->IsA)(a1: pDag, a2: (CUtlSymbolLarge)CDmeJoint::m_classType.u.m_Id) )
    {
      MatrixGetColumn(in: &jointToWorld, column: 3, out: &vecJointOrigin);
      v6 = v16;
      CPotteryWheelPanel::ComputePanelPosition(this: v16, vecPosition: &vecJointOrigin, pPanelPos: &vecPanelPos);
      m_pAsString = pDag->m_Name.m_Storage.u.m_pAsString;
      if ( JointIndex < 0 )
      {
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        V_snprintf(pDest: pJointName, maxLen: 0x200u, pFormat: "%s", m_pAsString);
      }
      else
      {
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        V_snprintf(pDest: pJointName, maxLen: 0x200u, pFormat: "%d : %s", JointIndex, m_pAsString);
      }
      g_pMatSystemSurface->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: *(_DWORD *)&v6[1].m_InternalCursorMoved_register,
        a3: (int)(float)(vecPanelPos.x + 5.0),
        a4: (int)vecPanelPos.y,
        a5: 255,
        a6: 255,
        a7: 255,
        a8: 255,
        a9: pJointName);
    }
    Phase = CDmElementFramework::GetPhase(this: pDag);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pDag, i);
      if ( Child != nullptr )
        CDmeDagRenderPanel::DrawJointNames(
          this: (CDmeDagRenderPanel *)v16,
          pRoot,
          pDag: Child,
          parentToWorld: &jointToWorld);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047E980
// Name: private: void CDmeDagRenderPanel::DrawHighlightPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::DrawHighlightPoints(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  CDmeDrawSettings *v4; // esi
  int v5; // edi
  Color m_Storage; // [esp-8h] [ebp-1Ch]
  Vector2D vecPanelPos; // [esp+4h] [ebp-10h] BYREF
  float flPointRadius; // [esp+Ch] [ebp-8h]
  int m_Size; // [esp+10h] [ebp-4h]

  if ( this->m_pDrawSettings != nullptr )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    DrawSetColor = g_pMatSystemSurface->DrawSetColor;
    m_Storage = m_pDrawSettings->m_cHighlightColor.m_Storage;
    flPointRadius = m_pDrawSettings->m_flHighlightSize.m_Storage;
    ((void (__thiscall *)(_DWORD, _DWORD))DrawSetColor)(a1: g_pMatSystemSurface, a2: m_Storage);
    v4 = this->m_pDrawSettings;
    if ( v4->m_vHighlightPoints.m_Size > 0 )
    {
      v5 = 0;
      m_Size = v4->m_vHighlightPoints.m_Size;
      do
      {
        CPotteryWheelPanel::ComputePanelPosition(
          this,
          vecPosition: &v4->m_vHighlightPoints.m_Memory.m_pMemory[v5],
          pPanelPos: &vecPanelPos);
        g_pMatSystemSurface->DrawFilledRect(
          this: g_pMatSystemSurface,
          a2: (int)(float)(vecPanelPos.x - flPointRadius),
          a3: (int)(float)(vecPanelPos.y - flPointRadius),
          a4: (int)(float)(vecPanelPos.x + flPointRadius),
          a5: (int)(float)(vecPanelPos.y + flPointRadius));
        ++v5;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047EA40
// Name: private: virtual void CDmeDagRenderPanel::OnFrame(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CDmeDagRenderPanel::OnFrame(CDmeDagRenderPanel *this@<ecx>, int a2@<edi>)
{
  CDmeDag *v3; // edi
  char v4; // al
  int v5; // edi
  matrix3x4_t dmeToEngine; // [esp+8h] [ebp-7Ch] BYREF
  _BYTE v8[12]; // [esp+38h] [ebp-4Ch] BYREF
  matrix3x4_t matrix; // [esp+44h] [ebp-40h] BYREF
  Vector vecWorldCenter; // [esp+74h] [ebp-10h] BYREF
  float vecCenter; // [esp+80h] [ebp-4h] OVERLAPPED BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle) != nullptr )
  {
    v3 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
    SetIdentityMatrix(matrix: (matrix3x4_t *)v8);
    CDmeDag::GetBoundingSphere(this: v3, c0: &vecWorldCenter, r0: &vecCenter, pMat: (const matrix3x4_t *)v8);
    v4 = *((_BYTE *)this + 1216);
    v5 = a2;
    if ( (v4 & 0x10) == 0 )
      CDmeDag::DmeToEngineMatrix(&dmeToEngine, bZUp: (v4 & 0x20) != 0);
    VectorTransform(in1: &vecWorldCenter.x, in2: &dmeToEngine, out: &matrix.m_flMatVal[2][1]);
    CPotteryWheelPanel::LookAt(this, a2: v5, vecCenter: (const Vector *)&matrix.m_flMatVal[2][1], flRadius: vecCenter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047EAF0
// Name: private: void CDmeDagRenderPanel::DrawAxis(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeDagRenderPanel::DrawAxis(CDmeDagRenderPanel *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  int v4; // esi
  IMesh *v5; // edi
  float *m_pCurrPosition; // eax
  int v7; // eax
  float *v8; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int m_nVertexCount; // eax
  int v18; // ecx
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a2);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
      a1: v4,
      a2: this->m_axisMaterial.m_pMaterial,
      a3: 0);
    v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                    a1: v4,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v7 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v7;
    if ( v7 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v7;
    v8 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                 + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v8;
    *v8 = 10.0;
    v8[1] = 0.0;
    v8[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 0.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 10.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 10.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v18 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v18;
    if ( v18 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v18;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v18;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh, a2: m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047EE80
// Name: private: void CDmeDagRenderPanel::UpdateMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::UpdateMenu(CDmeDagRenderPanel *this)
{
  switch ( this->m_pDrawSettings->m_DrawType.m_Storage <= 3u ? this->m_pDrawSettings->m_DrawType.m_Storage : 0 )
  {
    case 1:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: true);
      goto LABEL_8;
    case 2:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: true);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: false);
      break;
    case 3:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: true);
      break;
    default:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: true);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
LABEL_8:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: false);
      break;
  }
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuNormals,
    state: this->m_pDrawSettings->m_bNormals.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuWireframeOnShaded,
    state: this->m_pDrawSettings->m_bWireframeOnShaded.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuBackfaceCulling,
    state: this->m_pDrawSettings->m_bBackfaceCulling.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuXRay,
    state: this->m_pDrawSettings->m_bXRay.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuGrayShade,
    state: this->m_pDrawSettings->m_bGrayShade.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x1047F0C0
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeDag *pScene)
{
  DmElementHandle_t BufferType; // eax
  CDmeDag *v4; // eax
  int v5; // eax
  CDmeModel *v6; // esi
  DmElementHandle_t m_handle; // [esp-8h] [ebp-10h]

  if ( pScene != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pScene);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
  m_handle = this->m_hDag.m_handle;
  v4 = (CDmeDag *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
  ComputeDefaultTangentData(pDag: v4, bSmoothTangents: m_handle);
  v5 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
         a1: g_pDataModel,
         a2: this->m_hDag.m_handle,
         a3: 0);
  v6 = (CDmeModel *)v5;
  if ( v5 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeModel::m_classType.u) != 0 )
  {
    *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v6))) & 0x20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047F160
// Name: private: virtual void CDmeDagRenderPanel::OnSmoothShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnSmoothShade(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 0;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F1B0
// Name: private: virtual void CDmeDagRenderPanel::OnFlatShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnFlatShade(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 1;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F200
// Name: private: virtual void CDmeDagRenderPanel::OnWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnWireframe(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 2;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F250
// Name: private: virtual void CDmeDagRenderPanel::OnBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnBoundingBox(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 3;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F2A0
// Name: private: virtual void CDmeDagRenderPanel::OnNormals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnNormals(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuNormals);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bNormals.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F2E0
// Name: private: virtual void CDmeDagRenderPanel::OnWireframeOnShaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnWireframeOnShaded(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframeOnShaded);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bWireframeOnShaded.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F320
// Name: private: virtual void CDmeDagRenderPanel::OnBackfaceCulling(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnBackfaceCulling(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBackfaceCulling);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bBackfaceCulling.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F360
// Name: private: virtual void CDmeDagRenderPanel::OnXRay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnXRay(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuXRay);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bXRay.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F3A0
// Name: private: virtual void CDmeDagRenderPanel::OnGrayShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnGrayShade(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuGrayShade);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bGrayShade.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F3E0
// Name: public: virtual void CDmeDagRenderPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::Paint(CDmeDagRenderPanel *this)
{
  int v2; // edi
  CDmeClip *v3; // eax
  CDmeClip *v4; // eax
  int v5; // edi
  CDmeClip *v6; // eax
  DmeTime_t v7; // edi
  CDmeClip *v8; // eax
  int v9; // ebx
  CDmElement *v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  CDmeChannel *v13; // edi
  int v14; // edi
  CDmeClip *v15; // eax
  int m_tms; // ebx
  CDmeClip *v17; // eax
  int v18; // edi
  CDmeClip *v19; // eax
  int v20; // ebx
  CDmElement *v21; // eax
  CDmElement *v22; // eax
  CDmElement *v23; // edi
  CDmeChannel *v24; // ecx
  char v25; // al
  CDmeModel *v26; // eax
  CDmeModel *m_handle; // [esp+0h] [ebp-54h]
  const matrix3x4_t *v28; // [esp+4h] [ebp-50h]
  int v29; // [esp+8h] [ebp-4Ch]
  int v30; // [esp+Ch] [ebp-48h]
  int v31; // [esp+10h] [ebp-44h]
  matrix3x4_t dmeToEngine; // [esp+14h] [ebp-40h] BYREF
  unsigned __int64 v33; // [esp+44h] [ebp-10h] BYREF
  unsigned __int64 v34; // [esp+4Ch] [ebp-8h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle) != nullptr )
  {
    *(double *)&v33 = _Plat_FloatTime(
                        a1: v29,
                        a2: v30,
                        a3: v31,
                        a4: LODWORD(dmeToEngine.m_flMatVal[0][0]),
                        a5: LODWORD(dmeToEngine.m_flMatVal[0][1]))
                    - this->m_flStartTime;
    v2 = DmeTime_t::RoundSecondsToTMS(sec: v33);
    v3 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
    if ( CDmeClip::GetDuration(this: v3, result: (DmeTime_t *)&v33 + 1)->m_tms != 0 )
    {
      v4 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
      v5 = v2 % CDmeClip::GetDuration(this: v4, result: (DmeTime_t *)&v33 + 1)->m_tms;
    }
    else
    {
      v5 = 0;
    }
    v6 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
    v7.m_tms = CDmeClip::GetStartTime(this: v6, result: (DmeTime_t *)&v33 + 1)->m_tms + v5;
    v8 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
    CDmeClip::ToChildMediaTime(this: v8, result: (DmeTime_t *)&v34 + 1, t: v7, bClamp: (DmeTime_t *)1);
    v9 = 0;
    for ( HIDWORD(v33) = *(_DWORD *)&g_pDataModel->GetElement(
                                       this: g_pDataModel,
                                       a2: this->m_hCurrentAnimation.m_handle)[2].m_Id.m_Value[12]; v9 < SHIDWORD(v33); ++v9 )
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v10[2].m_Id.m_Value + 4 * v9));
      v12 = v11;
      if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeChannel::m_classType) )
        v13 = (CDmeChannel *)((char *)&v12[-1] + 64);
      else
        v13 = nullptr;
      CDmeChannel::SetCurrentTime(this: v13, time: *(DmeTime_t *)((char *)&v34 + 4));
    }
  }
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle) != nullptr )
  {
    *(double *)&v34 = _Plat_FloatTime(
                        a1: v29,
                        a2: v30,
                        a3: v31,
                        a4: LODWORD(dmeToEngine.m_flMatVal[0][0]),
                        a5: LODWORD(dmeToEngine.m_flMatVal[0][1]))
                    - this->m_flStartTime;
    v14 = DmeTime_t::RoundSecondsToTMS(sec: v34);
    v15 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
    m_tms = CDmeClip::GetDuration(this: v15, result: (DmeTime_t *)&v34 + 1)->m_tms;
    v17 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
    v18 = CDmeClip::GetStartTime(this: v17, result: (DmeTime_t *)&v34 + 1)->m_tms + v14 % m_tms;
    v19 = (CDmeClip *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
    CDmeClip::ToChildMediaTime(this: v19, result: (DmeTime_t *)&v33 + 1, t: (DmeTime_t)v18, bClamp: (DmeTime_t *)1);
    v20 = 0;
    for ( HIDWORD(v34) = *(_DWORD *)&g_pDataModel->GetElement(
                                       this: g_pDataModel,
                                       a2: this->m_hCurrentVertexAnimation.m_handle)[2].m_Id.m_Value[12];
          v20 < SHIDWORD(v34);
          ++v20 )
    {
      v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
      v22 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v21[2].m_Id.m_Value + 4 * v20));
      v23 = v22;
      if ( v22 != nullptr && v22->IsA(this: v22, a2: CDmeChannel::m_classType) )
        v24 = (CDmeChannel *)((char *)&v23[-1] + 64);
      else
        v24 = nullptr;
      CDmeChannel::SetCurrentTime(this: v24, time: *(DmeTime_t *)((char *)&v33 + 4));
    }
  }
  BYTE4(v33) = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: &this->m_operators);
  g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: HIDWORD(v33));
  g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
  CPotteryWheelPanel::Paint(this);
  if ( (*((_BYTE *)this + 1216) & 1) != 0
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle) != nullptr )
  {
    v25 = *((_BYTE *)this + 1216);
    if ( (v25 & 0x10) == 0 )
      CDmeDag::DmeToEngineMatrix(&dmeToEngine, bZUp: (v25 & 0x20) != 0);
    v28 = (const matrix3x4_t *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
                                 a1: g_pDataModel,
                                 a2: this->m_hDag.m_handle,
                                 a3: v29);
    m_handle = (CDmeModel *)this->m_hDag.m_handle;
    v26 = (CDmeModel *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
    CDmeDagRenderPanel::DrawJointNames(this, pRoot: v26, pDag: m_handle, parentToWorld: v28);
  }
  CDmeDagRenderPanel::DrawHighlightPoints(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F780
// Name: private: virtual void CDmeDagRenderPanel::OnPaint3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnPaint3D(CDmeDagRenderPanel *this)
{
  IMatRenderContext *v2; // esi
  int v3; // ebx
  ITexture *m_pTexture; // ecx
  CDmeDag *v5; // eax

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = (int)v2->GetLocalCubemap(this: v2);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
    m_pTexture = this->m_DefaultHDREnvCubemap.m_pTexture;
  else
    m_pTexture = this->m_DefaultEnvCubemap.m_pTexture;
  v2->BindLocalCubemap(this: v2, a2: m_pTexture);
  if ( (*((_BYTE *)this + 1216) & 4) != 0 )
    CPotteryWheelPanel::DrawGrid(this);
  if ( (*((_BYTE *)this + 1216) & 2) != 0 )
    CDmeJoint::DrawJointHierarchy(bDrawJoints: true);
  v2->CullMode(this: v2, a2: MATERIAL_CULLMODE_CW);
  CDmeDag::DrawUsingEngineCoordinates(bEnable: (*((_BYTE *)this + 1216) & 0x10) == 0);
  CDmeDag::DrawZUp(bZUp: (*((_BYTE *)this + 1216) & 0x20) != 0);
  v5 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
  CDmeDrawSettings::DrawDag(this: this->m_pDrawSettings, pDag: v5);
  CDmeDag::DrawUsingEngineCoordinates(bEnable: false);
  CDmeDag::DrawZUp(bZUp: false);
  if ( (*((_BYTE *)this + 1216) & 8) != 0 )
    CDmeDagRenderPanel::DrawAxis(this, a2: v3, a3: (int)v2);
  v2->Flush(this: v2, a2: false);
  v2->BindLocalCubemap(this: v2, a2: (ITexture *)v3);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1047F8D0
// Name: public: virtual CDmeDagRenderPanel::~CDmeDagRenderPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::~CDmeDagRenderPanel(CDmeDagRenderPanel *this)
{
  this->__vftable = (CDmeDagRenderPanel_vtbl *)&CDmeDagRenderPanel::`vftable';
  if ( g_pMaterialSystem != nullptr )
    CMaterialReference::Shutdown(this: &this->m_axisMaterial, bDeleteIfUnreferenced: false);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hDrawSettings,
      hElement: this->m_hDrawSettings.m_handle,
      handleType: HT_STRONG);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hDag, hElement: this->m_hDag.m_handle, handleType: HT_WEAK);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_operators);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hCurrentVertexAnimation,
      hElement: this->m_hCurrentVertexAnimation.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hCurrentAnimation,
      hElement: this->m_hCurrentAnimation.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hVertexAnimationList,
      hElement: this->m_hVertexAnimationList.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hAnimationList,
      hElement: this->m_hAnimationList.m_handle,
      handleType: HT_WEAK);
  CMaterialReference::~CMaterialReference(this: &this->m_axisMaterial);
  CTextureReference::~CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047F9C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeDagRenderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeDagRenderPanel::GetMessageMap(CDmeDagRenderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeDagRenderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagRenderPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeDagRenderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
  `CDmeDagRenderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1047F9F0
// Name: public: virtual struct PanelAnimationMap __near * CDmeDagRenderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeDagRenderPanel::GetAnimMap(CDmeDagRenderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeDagRenderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1047FA00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeDagRenderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeDagRenderPanel::GetKBMap(CDmeDagRenderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeDagRenderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagRenderPanel::GetKBMap'::`2'::s_pMap;
  `CDmeDagRenderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagRenderPanel");
  `CDmeDagRenderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1047FB50
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SmoothShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047FBE0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FlatShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047FC70
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Wireframe";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047FD00
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BoundingBox";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047FD90
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Normals";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047FE20
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "WireframeOnShaded";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047FEB0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BackfaceCulling";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047FF40
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "XRay";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047FFD0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "GrayShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10480060
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Frame";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104800F0
// Name: public: CDmeDagRenderPanel::CDmeDagRenderPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmeDagRenderPanel::CDmeDagRenderPanel(
        CDmeDagRenderPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IDataModel_vtbl *v7; // edx
  bool v8; // al
  IDataModel_vtbl *v9; // edx
  ITexture *v10; // eax
  ITexture *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  DmFileId_t v14; // eax
  DmElementHandle_t v15; // eax
  CDmElement *v16; // eax
  CDmeDrawSettings *v17; // edi
  DmElementHandle_t BufferType; // eax
  vgui::MenuBar *v19; // eax
  vgui::MenuBar *v20; // eax
  vgui::Menu *v21; // eax
  vgui::Menu *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  int v29; // eax
  vgui::Menu *m_pShadingMenu; // ecx
  KeyValues *v31; // eax
  KeyValues *v32; // eax
  int v33; // eax
  vgui::Menu *v34; // ecx
  KeyValues *v35; // eax
  KeyValues *v36; // eax
  KeyValues *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // eax
  KeyValues *v40; // eax
  KeyValues *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // eax
  KeyValues *v44; // eax
  int v45; // eax
  vgui::Menu *v46; // ecx
  CDisableUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CPotteryWheelPanel::CPotteryWheelPanel(this, pParent, pName);
  this->__vftable = (CDmeDagRenderPanel_vtbl *)&CDmeDagRenderPanel::`vftable';
  if ( `CDmeDagRenderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v4->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  }
  if ( `CDmeDagRenderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeDagRenderPanel");
    v5->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
  }
  if ( `CDmeDagRenderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagRenderPanel");
    v6->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  }
  CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(a1: (int)&savedregs);
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CMaterialReference::CMaterialReference(
    this: &this->m_axisMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_hAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hVertexAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hCurrentAnimation.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hCurrentVertexAnimation.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  this->m_hDag.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hDrawSettings.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = g_pDataModel->__vftable;
  *(_WORD *)&sg.m_bReleased = 0;
  sg.m_pNotify = nullptr;
  v8 = v7->IsUndoEnabled(this: g_pDataModel);
  v9 = g_pDataModel->__vftable;
  sg.m_bOldValue = v8;
  v9->SetUndoEnabled(this: g_pDataModel, a2: false);
  *((_BYTE *)this + 1216) = *((_BYTE *)this + 1216) & 0xC0 | 0xC;
  v10 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "editor/cubemap", a3: 0, a4: 1, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v10);
  v11 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "editor/cubemap.hdr", a3: 0, a4: 1, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultHDREnvCubemap, pTexture: v11);
  if ( g_pMaterialSystem != nullptr )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v13 = KeyValues::KeyValues(this: v12, setName: "wireframe");
    else
      v13 = nullptr;
    KeyValues::SetInt(this: v13, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v13, keyName: "$ignorez", value: 1);
    CMaterialReference::Init(this: &this->m_axisMaterial, pMaterialName: "__DmeDagRenderPanelAxis", pVMTKeyValues: v13);
  }
  v14 = g_pDataModel->FindOrCreateFileId(this: g_pDataModel, a2: "DagRenderPanelDrawSettings");
  v15 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeDrawSettings::m_classType.u.m_Id,
          a3: "drawSettings",
          a4: v14,
          a5: nullptr);
  v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: v15);
  v17 = (CDmeDrawSettings *)v16;
  if ( v16 == nullptr || !v16->IsA(this: v16, a2: CDmeDrawSettings::m_classType) )
    v17 = nullptr;
  this->m_pDrawSettings = v17;
  if ( v17 != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDrawSettings,1>::Set(this: &this->m_hDrawSettings, h: BufferType);
  v19 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v19 != nullptr )
    v20 = vgui::MenuBar::MenuBar(this: v19, parent: this, panelName: "Dag Render Panel Menu Bar");
  else
    v20 = nullptr;
  this->m_pMenuBar = v20;
  v21 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v21 != nullptr )
    v22 = vgui::Menu::Menu(this: v21, parent: nullptr, panelName: "Shading Menu");
  else
    v22 = nullptr;
  this->m_pShadingMenu = v22;
  v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v23 != nullptr )
    v24 = KeyValues::KeyValues(this: v23, setName: "SmoothShade");
  else
    v24 = nullptr;
  this->m_nMenuSmoothShade = this->m_pShadingMenu->AddCheckableMenuItem(
                               this: this->m_pShadingMenu,
                               a2: "&Smooth Shade",
                               a3: v24,
                               a4: this,
                               a5: nullptr);
  v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v25 != nullptr )
    v26 = KeyValues::KeyValues(this: v25, setName: "FlatShade");
  else
    v26 = nullptr;
  this->m_nMenuFlatShade = this->m_pShadingMenu->AddCheckableMenuItem(
                             this: this->m_pShadingMenu,
                             a2: "&Flat Shade",
                             a3: v26,
                             a4: this,
                             a5: nullptr);
  v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v27 != nullptr )
    v28 = KeyValues::KeyValues(this: v27, setName: "Wireframe");
  else
    v28 = nullptr;
  v29 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Wireframe",
          a3: v28,
          a4: this,
          a5: nullptr);
  m_pShadingMenu = this->m_pShadingMenu;
  this->m_nMenuWireframe = v29;
  m_pShadingMenu->AddSeparator(this: m_pShadingMenu);
  v31 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v31 != nullptr )
    v32 = KeyValues::KeyValues(this: v31, setName: "BoundingBox");
  else
    v32 = nullptr;
  v33 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Bounding Box",
          a3: v32,
          a4: this,
          a5: nullptr);
  v34 = this->m_pShadingMenu;
  this->m_nMenuBoundingBox = v33;
  v34->AddSeparator(this: v34);
  v35 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v35 != nullptr )
    v36 = KeyValues::KeyValues(this: v35, setName: "Normals");
  else
    v36 = nullptr;
  this->m_nMenuNormals = this->m_pShadingMenu->AddCheckableMenuItem(
                           this: this->m_pShadingMenu,
                           a2: "&Normals",
                           a3: v36,
                           a4: this,
                           a5: nullptr);
  v37 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v37 != nullptr )
    v38 = KeyValues::KeyValues(this: v37, setName: "WireframeOnShaded");
  else
    v38 = nullptr;
  this->m_nMenuWireframeOnShaded = this->m_pShadingMenu->AddCheckableMenuItem(
                                     this: this->m_pShadingMenu,
                                     a2: "WireFrame &On Shaded",
                                     a3: v38,
                                     a4: this,
                                     a5: nullptr);
  v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v39 != nullptr )
    v40 = KeyValues::KeyValues(this: v39, setName: "BackfaceCulling");
  else
    v40 = nullptr;
  this->m_nMenuBackfaceCulling = this->m_pShadingMenu->AddCheckableMenuItem(
                                   this: this->m_pShadingMenu,
                                   a2: "&Backface Culling",
                                   a3: v40,
                                   a4: this,
                                   a5: nullptr);
  v41 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v41 != nullptr )
    v42 = KeyValues::KeyValues(this: v41, setName: "XRay");
  else
    v42 = nullptr;
  this->m_nMenuXRay = this->m_pShadingMenu->AddCheckableMenuItem(
                        this: this->m_pShadingMenu,
                        a2: "&X-Ray",
                        a3: v42,
                        a4: this,
                        a5: nullptr);
  v43 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v43 != nullptr )
    v44 = KeyValues::KeyValues(this: v43, setName: "GrayShade");
  else
    v44 = nullptr;
  v45 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Gray Shade",
          a3: v44,
          a4: this,
          a5: nullptr);
  v46 = this->m_pShadingMenu;
  this->m_nMenuGrayShade = v45;
  v46->SetItemVisible(this: v46, a2: this->m_nMenuFlatShade, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuFlatShade, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuBoundingBox, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuBoundingBox, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuBackfaceCulling, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuBackfaceCulling, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuXRay, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuXRay, a3: false);
  this->m_pMenuBar->AddMenu(this: this->m_pMenuBar, a2: "&Shading", a3: this->m_pShadingMenu);
  CDmeDagRenderPanel::UpdateMenu(this);
  CChangeUndoScopeGuard::Release(this: &sg);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10480770
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeSourceSkin __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeSourceSkin *pSkin)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax
  CDmeModel *v5; // ebx
  CExpressionCalculator *Value; // eax
  DmElementHandle_t BufferType; // eax
  CDmeDag *v8; // eax
  int v9; // eax
  CDmeModel *v10; // edi
  CDmeModel *v11; // ecx
  DmElementHandle_t m_handle; // [esp-8h] [ebp-14h]

  DependentMakefile = CDmeSource::GetDependentMakefile(this: pSkin);
  if ( DependentMakefile == nullptr
    || (OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true),
        v5 = (CDmeModel *)OutputElement,
        OutputElement == nullptr) )
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
    return;
  }
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
  if ( Value != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: Value);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
  m_handle = this->m_hDag.m_handle;
  v8 = (CDmeDag *)((int (__thiscall *)(IDataModel *))g_pDataModel->GetElement)(a1: g_pDataModel);
  ComputeDefaultTangentData(pDag: v8, bSmoothTangents: m_handle);
  *((_BYTE *)this + 1216) &= 0xFCu;
  v9 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
         a1: g_pDataModel,
         a2: this->m_hDag.m_handle,
         a3: 0);
  v10 = (CDmeModel *)v9;
  if ( v9 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
         a1: v9,
         a2: CDmeModel::m_classType.u) != 0 )
  {
    v11 = v10;
  }
  else
  {
    if ( !v5->IsA(this: v5, a2: CDmeModel::m_classType) )
      return;
    v11 = v5;
  }
  *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v11))) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x10480870
// Name: private: void CDmeDagRenderPanel::RebuildOperatorList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::RebuildOperatorList(CDmeDagRenderPanel *this)
{
  CDmElement *v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // edi
  CDmeChannel *v5; // ecx
  CDmElement *v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v12; // eax
  IDmeOperator **v13; // eax
  CDmElement *v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmeChannel *v17; // ecx
  CDmElement *v18; // eax
  CDmElement *v19; // eax
  CDmElement *v20; // edi
  int v21; // edi
  int v22; // eax
  IDmeOperator **v23; // ecx
  int v24; // eax
  IDmeOperator **v25; // eax
  int v26; // [esp+0h] [ebp-18h]
  int v27; // [esp+4h] [ebp-14h]
  int v28; // [esp+8h] [ebp-10h]
  int nChannelCount; // [esp+Ch] [ebp-Ch]
  IDmeOperator *v30; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int ia; // [esp+14h] [ebp-4h]

  this->m_operators.m_Size = 0;
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle) != nullptr )
  {
    nChannelCount = *(_DWORD *)&g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle)[2].m_Id.m_Value[12];
    for ( i = 0; i < nChannelCount; ++i )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v2[2].m_Id.m_Value + 4 * i));
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeChannel::m_classType) )
        v5 = (CDmeChannel *)((char *)&v4[-1] + 64);
      else
        v5 = nullptr;
      CDmeChannel::SetMode(this: v5, mode: CM_PLAY);
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentAnimation.m_handle);
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v6[2].m_Id.m_Value + 4 * i));
      v8 = v7;
      if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeChannel::m_classType) )
        v30 = (IDmeOperator *)((char *)&v8[-1] + 64);
      else
        v30 = nullptr;
      m_Size = this->m_operators.m_Size;
      m_nAllocationCount = this->m_operators.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_operators,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_operators.m_Size;
      m_pMemory = this->m_operators.m_Memory.m_pMemory;
      v12 = this->m_operators.m_Size - m_Size - 1;
      this->m_operators.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v12);
      v13 = &this->m_operators.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = v30;
    }
  }
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle) != nullptr )
  {
    nChannelCount = *(_DWORD *)&g_pDataModel->GetElement(
                                  this: g_pDataModel,
                                  a2: this->m_hCurrentVertexAnimation.m_handle)[2].m_Id.m_Value[12];
    for ( ia = 0; ia < nChannelCount; ++ia )
    {
      v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v14[2].m_Id.m_Value + 4 * ia));
      v16 = v15;
      if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeChannel::m_classType) )
        v17 = (CDmeChannel *)((char *)&v16[-1] + 64);
      else
        v17 = nullptr;
      CDmeChannel::SetMode(this: v17, mode: CM_PLAY);
      v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hCurrentVertexAnimation.m_handle);
      v19 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)v18[2].m_Id.m_Value + 4 * ia));
      v20 = v19;
      if ( v19 != nullptr && v19->IsA(this: v19, a2: CDmeChannel::m_classType) )
        v30 = (IDmeOperator *)((char *)&v20[-1] + 64);
      else
        v30 = nullptr;
      v21 = this->m_operators.m_Size;
      v22 = this->m_operators.m_Memory.m_nAllocationCount;
      if ( v21 + 1 > v22 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_operators,
          num: v21 - v22 + 1);
      ++this->m_operators.m_Size;
      v23 = this->m_operators.m_Memory.m_pMemory;
      v24 = this->m_operators.m_Size - v21 - 1;
      this->m_operators.m_pElements = v23;
      if ( v24 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v23[v21 + 1], src: (unsigned __int8 *)&v23[v21], count: 4 * v24);
      v25 = &this->m_operators.m_Memory.m_pMemory[v21];
      if ( v25 != nullptr )
        *v25 = v30;
    }
  }
  this->m_flStartTime = _Plat_FloatTime(a1: v26, a2: v27, a3: v28, a4: nChannelCount, a5: v30);
}

//------------------------------------------------------------------------------
// Address: 0x10480BA0
// Name: private: void CDmeDagRenderPanel::SelectAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectAnimation(CDmeDagRenderPanel *this, int nIndex)
{
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CExpressionCalculator *v6; // ecx
  DmElementHandle_t BufferType; // eax

  CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle) != nullptr && nIndex >= 0 )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle);
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v3[1].OnAttributeChanged + nIndex));
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
      v6 = (CExpressionCalculator *)v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: BufferType);
  }
  CDmeDagRenderPanel::RebuildOperatorList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10480C50
// Name: private: void CDmeDagRenderPanel::SelectVertexAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectVertexAnimation(CDmeDagRenderPanel *this, int nIndex)
{
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CExpressionCalculator *v6; // ecx
  DmElementHandle_t BufferType; // eax

  CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle) != nullptr && nIndex >= 0 )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle);
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v3[1].OnAttributeChanged + nIndex));
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
      v6 = (CExpressionCalculator *)v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: BufferType);
  }
  CDmeDagRenderPanel::RebuildOperatorList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10480D00
// Name: public: void CDmeDagRenderPanel::SelectAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectAnimation(CDmeDagRenderPanel *this, const char *pAnimName)
{
  CDmeAnimationList *v3; // eax
  int Animation; // eax

  if ( *pAnimName != 0 )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle) != nullptr )
    {
      v3 = (CDmeAnimationList *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle);
      Animation = CDmeAnimationList::FindAnimation(this: v3, pAnimName);
      if ( Animation >= 0 )
        CDmeDagRenderPanel::SelectAnimation(this, nIndex: Animation);
    }
  }
  else
  {
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
    g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hAnimationList.m_handle);
    CDmeDagRenderPanel::RebuildOperatorList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10480D90
// Name: public: void CDmeDagRenderPanel::SelectVertexAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectVertexAnimation(CDmeDagRenderPanel *this, const char *pAnimName)
{
  CDmeAnimationList *v3; // eax
  int Animation; // eax

  if ( *pAnimName != 0 )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle) != nullptr )
    {
      v3 = (CDmeAnimationList *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle);
      Animation = CDmeAnimationList::FindAnimation(this: v3, pAnimName);
      if ( Animation >= 0 )
        CDmeDagRenderPanel::SelectVertexAnimation(this, nIndex: Animation);
    }
  }
  else
  {
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
    g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hVertexAnimationList.m_handle);
    CDmeDagRenderPanel::RebuildOperatorList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10480E20
// Name: public: void CDmeDagRenderPanel::SetAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetAnimationList(CDmeDagRenderPanel *this, CDmeAnimationList *pAnimationList)
{
  DmElementHandle_t BufferType; // eax

  if ( pAnimationList != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimationList);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hAnimationList, h: BufferType);
  if ( pAnimationList != nullptr && pAnimationList->m_Animations.m_Storage.m_Size != 0 )
    CDmeDagRenderPanel::SelectAnimation(this, nIndex: 0);
  else
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x10480E80
// Name: public: void CDmeDagRenderPanel::SetVertexAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetVertexAnimationList(CDmeDagRenderPanel *this, CDmeAnimationList *pAnimationList)
{
  DmElementHandle_t BufferType; // eax

  if ( pAnimationList != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pAnimationList);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hVertexAnimationList, h: BufferType);
  if ( pAnimationList != nullptr && pAnimationList->m_Animations.m_Storage.m_Size != 0 )
    CDmeDagRenderPanel::SelectVertexAnimation(this, nIndex: 0);
  else
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x10480FE0
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeSourceAnimation __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeDagRenderPanel::SetDmeElement(
        CDmeDagRenderPanel *this@<ecx>,
        bool a2@<bl>,
        CDmeSourceAnimation *pAnimation)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax
  CDmElement *v6; // edi
  CDmeDag *Value; // ebx
  CDmeAnimationList *v8; // eax
  const char *m_pAsString; // edx
  CDmeDag *v10; // eax
  const char *v11; // eax
  CDmElement *v12; // eax
  CDmeModel *v13; // eax
  CDmeAnimationList *pAnimationList; // [esp+8h] [ebp-4h]

  DependentMakefile = CDmeSource::GetDependentMakefile(this: pAnimation);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    v6 = OutputElement;
    if ( OutputElement != nullptr )
    {
      Value = CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
      if ( Value != nullptr
        || (Value = CDmElement::GetValueElement<CDmeDag>(this: v6, pAttributeName: "skeleton")) != nullptr )
      {
        v8 = CDmElement::GetValueElement<CDmeAnimationList>(this: v6, pAttributeName: "animationList");
        pAnimationList = v8;
        if ( v8 != nullptr )
        {
          m_pAsString = pAnimation->m_SourceAnimationName.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = &var;
          if ( CDmeAnimationList::FindAnimation(this: v8, pAnimName: m_pAsString) >= 0 )
          {
            CDmeHandle<CDmeDag,0>::operator=(this: &this->m_hDag, pObject: Value);
            v10 = (CDmeDag *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                               a1: g_pDataModel,
                               a2: this->m_hDag.m_handle,
                               a3: 0);
            ComputeDefaultTangentData(pDag: v10, bSmoothTangents: a2);
            CDmeHandle<CDmeAnimationList,0>::operator=(this: &this->m_hAnimationList, pObject: pAnimationList);
            v11 = pAnimation->m_SourceAnimationName.m_Storage.u.m_pAsString;
            if ( v11 == (const char *)-1 )
              v11 = &var;
            CDmeDagRenderPanel::SelectAnimation(this, pAnimName: v11);
            *((_BYTE *)this + 1216) |= 3u;
            v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
            v13 = CastElement<CDmeModel>(pElement: v12);
            if ( v13 != nullptr || (v13 = CastElement<CDmeModel>(pElement: v6)) != nullptr )
              *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v13))) & 0x20;
          }
        }
      }
    }
    else
    {
      CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
    }
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10481140
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeDCCMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeDCCMakefile *pDCCMakefile)
{
  CDmElement *OutputElement; // eax
  CDmElement *v4; // edi
  CExpressionCalculator *Value; // ebx
  DmElementHandle_t BufferType; // eax
  CDmeDag *v7; // eax
  DmElementHandle_t v8; // eax
  DmElementHandle_t m_handle; // edx
  CDmElement *v10; // eax
  CDmeModel *v11; // edi
  CDmElement *pOutputElement; // [esp+Ch] [ebp-4h]
  CDmeDag *pDag; // [esp+18h] [ebp+8h]

  OutputElement = CDmeMakefile::GetOutputElement(this: pDCCMakefile, bCreateIfNecessary: true);
  v4 = OutputElement;
  pOutputElement = OutputElement;
  if ( OutputElement != nullptr )
  {
    pDag = CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
    if ( pDag != nullptr
      || (pDag = CDmElement::GetValueElement<CDmeDag>(this: v4, pAttributeName: "skeleton")) != nullptr )
    {
      Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmeAnimationList>(
                                         this: v4,
                                         pAttributeName: "animationList");
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDag);
      CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
      v7 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hDag.m_handle);
      ComputeDefaultTangentData(pDag: v7, bSmoothTangents: false);
      v8 = Value != nullptr ? CCodecBuffer_Block::GetBufferType(this: Value) : DMELEMENT_HANDLE_INVALID;
      if ( (CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hAnimationList, h: v8),
            CDmeDagRenderPanel::SelectAnimation(this, nIndex: 0),
            m_handle = this->m_hDag.m_handle,
            *((_BYTE *)this + 1216) = (Value != nullptr) | *((_BYTE *)this + 1216) & 0xFC | (2 * (Value != nullptr)),
            v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle),
            v11 = (CDmeModel *)v10,
            v10 != nullptr)
        && v10->IsA(this: v10, a2: CDmeModel::m_classType)
        || (v11 = (CDmeModel *)pOutputElement, pOutputElement->IsA(this: pOutputElement, a2: CDmeModel::m_classType)) )
      {
        *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v11))) & 0x20;
      }
    }
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0047D640
// Name: public: static char const __near * CDmeDagRenderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeDagRenderPanel::GetPanelClassName()
{
  return "CDmeDagRenderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0047D650
// Name: public: void CVertexBuilder::AttachBegin(class IMesh __near *,int,struct MeshDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AttachBegin(
        CVertexBuilder *this,
        IMesh *pMesh,
        int nMaxVertexCount,
        const MeshDesc_t *desc)
{
  bool v4; // zf

  this->m_pVertexBuffer = pMesh;
  this->VertexDesc_t = desc->VertexDesc_t;
  this->m_nMaxVertexCount = nMaxVertexCount;
  this->m_NumBoneWeights = this->m_NumBoneWeights != 0 ? 2 : 0;
  v4 = this->m_nBufferOffset == -1;
  this->m_nVertexCount = 0;
  this->m_bModify = false;
  if ( v4 )
  {
    this->m_nTotalVertexCount = 0;
    this->m_nBufferOffset = desc->VertexDesc_t::m_nOffset;
    this->m_nBufferFirstVertex = desc->m_nFirstVertex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D6C0
// Name: public: void CVertexBuilder::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::Reset(CVertexBuilder *this)
{
  float *m_pNormal; // edx
  float *v2; // edx
  float *v3; // eax
  float *v4; // edx
  float *v5; // eax
  float *v6; // edx
  float *v7; // eax
  float *v8; // edx

  m_pNormal = this->m_pNormal;
  this->m_pCurrPosition = this->m_pPosition;
  this->m_nCurrentVertex = 0;
  this->m_pCurrNormal = m_pNormal;
  v2 = this->m_pTexCoord[1];
  this->m_pCurrTexCoord[0] = this->m_pTexCoord[0];
  v3 = this->m_pTexCoord[2];
  this->m_pCurrTexCoord[1] = v2;
  v4 = this->m_pTexCoord[3];
  this->m_pCurrTexCoord[2] = v3;
  v5 = this->m_pTexCoord[4];
  this->m_pCurrTexCoord[3] = v4;
  v6 = this->m_pTexCoord[5];
  this->m_pCurrTexCoord[4] = v5;
  v7 = this->m_pTexCoord[6];
  this->m_pCurrTexCoord[5] = v6;
  v8 = this->m_pTexCoord[7];
  this->m_pCurrTexCoord[6] = v7;
  this->m_pCurrTexCoord[7] = v8;
  this->m_pCurrColor = this->m_pColor;
}

//------------------------------------------------------------------------------
// Address: 0x0047D740
// Name: public: void CIndexBuilder::GenerateIndices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::GenerateIndices(
        CIndexBuilder *this,
        MaterialPrimitiveType_t primitiveType,
        int nIndexCount)
{
  int v4; // edi
  unsigned __int16 *v5; // eax
  int m_nCurrentIndex; // eax

  if ( this->m_nIndexSize != 0 )
  {
    v4 = nIndexCount;
    if ( this->m_nMaxIndexCount - this->m_nCurrentIndex < nIndexCount )
      v4 = this->m_nMaxIndexCount - this->m_nCurrentIndex;
    if ( v4 != 0 )
    {
      v5 = &this->m_pIndices[this->m_nCurrentIndex];
      switch ( primitiveType )
      {
        case MATERIAL_POINTS:
        case MATERIAL_INSTANCED_QUADS:
          break;
        case MATERIAL_LINE_STRIP:
          GenerateLineStripIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_LINE_LOOP:
          GenerateLineLoopIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_POLYGON:
          GeneratePolygonIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_QUADS:
          GenerateQuadIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        default:
          GenerateSequentialIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
      }
      this->m_nCurrentIndex += v4 * this->m_nIndexSize;
      m_nCurrentIndex = this->m_nCurrentIndex;
      if ( m_nCurrentIndex > this->m_nIndexCount )
        this->m_nIndexCount = m_nCurrentIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D810
// Name: public: CMeshBuilder::~CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::~CMeshBuilder(CMeshBuilder *this)
{
  if ( this->m_VertexBuilder.m_pVertexBuffer != nullptr
    && this->m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: this->m_VertexBuilder.m_pVertexBuffer) )
  {
    this->m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: this->m_VertexBuilder.m_pVertexBuffer);
  }
  if ( this->m_IndexBuilder.m_pIndexBuffer != nullptr
    && this->m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: this->m_IndexBuilder.m_pIndexBuffer) )
  {
    this->m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: this->m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D870
// Name: public: CMeshBuilder::CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBuilder *__thiscall CMeshBuilder::CMeshBuilder(CMeshBuilder *this)
{
  this->m_pMesh = nullptr;
  this->m_bGenerateIndices = false;
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_IndexBuilder.m_nTotalIndexCount = 0;
  this->m_IndexBuilder.m_nBufferFirstIndex = 0;
  this->m_IndexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_nBufferFirstVertex = 0;
  this->m_VertexBuilder.m_nVertexCount = 0;
  this->m_VertexBuilder.m_nCurrentVertex = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_nTotalVertexCount = 0;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047D8E0
// Name: private: int CMeshBuilder::IndicesFromVertices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshBuilder::IndicesFromVertices(CMeshBuilder *this, MaterialPrimitiveType_t type, int nVertexCount)
{
  int result; // eax

  switch ( type )
  {
    case MATERIAL_LINE_STRIP:
      result = 2 * nVertexCount - 2;
      break;
    case MATERIAL_LINE_LOOP:
      result = 2 * nVertexCount;
      break;
    case MATERIAL_POLYGON:
      result = 3 * nVertexCount - 6;
      break;
    case MATERIAL_QUADS:
      result = 6 * nVertexCount / 4;
      break;
    case MATERIAL_INSTANCED_QUADS:
      result = 0;
      break;
    default:
      result = nVertexCount;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047D960
// Name: public: void CMeshBuilder::End(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::End(CMeshBuilder *this, bool bSpewData, bool bDraw)
{
  MaterialPrimitiveType_t m_Type; // edi
  int v5; // eax

  if ( this->m_bGenerateIndices )
  {
    m_Type = this->m_Type;
    v5 = CMeshBuilder::IndicesFromVertices(this, type: m_Type, nVertexCount: this->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &this->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v5);
  }
  if ( bSpewData )
    this->m_pMesh->Spew_2(
      this: this->m_pMesh,
      a2: this->m_VertexBuilder.m_nVertexCount,
      a3: this->m_IndexBuilder.m_nIndexCount,
      a4: this);
  this->m_pMesh->UnlockMesh(
    this: this->m_pMesh,
    a2: this->m_VertexBuilder.m_nVertexCount,
    a3: this->m_IndexBuilder.m_nIndexCount,
    a4: this);
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  if ( bDraw )
    this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
  this->m_pMesh = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047DA20
// Name: public: virtual void CDmeDagRenderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::ApplySchemeSettings(CDmeDagRenderPanel *this, vgui::IScheme *pScheme)
{
  CDmeDagRenderPanel_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax
  vgui::IScheme_vtbl *v5; // ebx
  bool v6; // al

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "MenuBorder");
  v3->SetBorder(this, a2: v4);
  v5 = pScheme->__vftable;
  v6 = this->IsProportional(this);
  this->m_hFont = v5->GetFont(this: pScheme, a2: "DmePropertyVerySmall", a3: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0047DA80
// Name: public: virtual void CDmeDagRenderPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::PerformLayout(CDmeDagRenderPanel *this)
{
  int iMenuWidth; // [esp+4h] [ebp-10h] BYREF
  int iHeight; // [esp+8h] [ebp-Ch] BYREF
  int iWidth; // [esp+Ch] [ebp-8h] BYREF
  int iMenuHeight; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  if ( this->m_pMenuBar->IsVisible(this: this->m_pMenuBar) )
  {
    vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
    vgui::Panel::GetSize(this: this->m_pMenuBar, wide: &iMenuWidth, tall: &iMenuHeight);
    vgui::Panel::SetSize(this: this->m_pMenuBar, wide: iWidth, tall: iMenuHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DAE0
// Name: private: virtual void CDmeDagRenderPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnMouseDoublePressed(CDmeDagRenderPanel *this, ButtonCode_t code)
{
  this->OnFrame(this);
  CPotteryWheelPanel::OnMouseDoublePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x0047DB00
// Name: private: virtual void CDmeDagRenderPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnKeyCodePressed(CDmeDagRenderPanel *this, ButtonCode_t code)
{
  CPotteryWheelPanel::OnKeyCodePressed(this, code);
  if ( code == KEY_F )
    this->OnFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047DC40
// Name: public: class CDmeDag __near * CDmeDagRenderPanel::GetDmeElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDagRenderPanel::GetDmeElement(CDmeDagRenderPanel *this)
{
  return (*(CDmeDag *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hDag.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x0047DC60
// Name: private: void CDmeDagRenderPanel::DrawJointNames(class CDmeDag __near *,class CDmeDag __near *,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::DrawJointNames(
        CDmeDagRenderPanel *this,
        CDmeModel *pRoot,
        CDmeModel *pDag,
        const matrix3x4_t *parentToWorld)
{
  int JointIndex; // esi
  CDmeTransform *Transform; // eax
  CPotteryWheelPanel *v6; // ebx
  const char *m_pAsString; // eax
  int Phase; // ebx
  int i; // esi
  CDmeDag *Child; // eax
  char pJointName[512]; // [esp+Ch] [ebp-278h] BYREF
  matrix3x4_t jointToParent; // [esp+20Ch] [ebp-78h] BYREF
  matrix3x4_t jointToWorld; // [esp+23Ch] [ebp-48h] BYREF
  Vector vecJointOrigin; // [esp+26Ch] [ebp-18h] BYREF
  Vector2D vecPanelPos; // [esp+278h] [ebp-Ch] BYREF
  CPotteryWheelPanel *v16; // [esp+280h] [ebp-4h]

  JointIndex = -1;
  v16 = this;
  if ( pRoot == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(a1: pRoot, a2: (CUtlSymbolLarge)CDmeModel::m_classType.u.m_Id)
    || (JointIndex = CDmeModel::GetJointIndex(this: pRoot, pJoint: pDag)) >= 0
    || pRoot == pDag )
  {
    Transform = CDmeDag::GetTransform(this: pDag);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pDag != nullptr
      && ((int (__thiscall *)(_DWORD, _DWORD))pDag->IsA)(a1: pDag, a2: (CUtlSymbolLarge)CDmeJoint::m_classType.u.m_Id) )
    {
      MatrixGetColumn(in: &jointToWorld, column: 3, out: &vecJointOrigin);
      v6 = v16;
      CPotteryWheelPanel::ComputePanelPosition(this: v16, vecPosition: &vecJointOrigin, pPanelPos: &vecPanelPos);
      m_pAsString = pDag->m_Name.m_Storage.u.m_pAsString;
      if ( JointIndex < 0 )
      {
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        V_snprintf(pDest: pJointName, maxLen: 512, pFormat: "%s", m_pAsString);
      }
      else
      {
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        V_snprintf(pDest: pJointName, maxLen: 512, pFormat: "%d : %s", JointIndex, m_pAsString);
      }
      g_pMatSystemSurface->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: *(_DWORD *)&v6[1].m_InternalCursorMoved_register,
        a3: (int)(float)(vecPanelPos.x + 5.0),
        a4: (int)vecPanelPos.y,
        a5: 255,
        a6: 255,
        a7: 255,
        a8: 255,
        a9: pJointName);
    }
    Phase = CDmElementFramework::GetPhase(this: pDag);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pDag, i);
      if ( Child != nullptr )
        CDmeDagRenderPanel::DrawJointNames(
          this: (CDmeDagRenderPanel *)v16,
          pRoot,
          pDag: Child,
          parentToWorld: &jointToWorld);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DE00
// Name: private: void CDmeDagRenderPanel::DrawHighlightPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::DrawHighlightPoints(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  CDmeDrawSettings *v4; // esi
  int v5; // edi
  Color m_Storage; // [esp-8h] [ebp-1Ch]
  Vector2D vecPanelPos; // [esp+4h] [ebp-10h] BYREF
  float flPointRadius; // [esp+Ch] [ebp-8h]
  int m_Size; // [esp+10h] [ebp-4h]

  if ( this->m_pDrawSettings != nullptr )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    DrawSetColor = g_pMatSystemSurface->DrawSetColor;
    m_Storage = m_pDrawSettings->m_cHighlightColor.m_Storage;
    flPointRadius = m_pDrawSettings->m_flHighlightSize.m_Storage;
    ((void (__thiscall *)(_DWORD, _DWORD))DrawSetColor)(a1: g_pMatSystemSurface, a2: m_Storage);
    v4 = this->m_pDrawSettings;
    if ( v4->m_vHighlightPoints.m_Size > 0 )
    {
      v5 = 0;
      m_Size = v4->m_vHighlightPoints.m_Size;
      do
      {
        CPotteryWheelPanel::ComputePanelPosition(
          this,
          vecPosition: &v4->m_vHighlightPoints.m_Memory.m_pMemory[v5],
          pPanelPos: &vecPanelPos);
        g_pMatSystemSurface->DrawFilledRect(
          this: g_pMatSystemSurface,
          a2: (int)(float)(vecPanelPos.x - flPointRadius),
          a3: (int)(float)(vecPanelPos.y - flPointRadius),
          a4: (int)(float)(vecPanelPos.x + flPointRadius),
          a5: (int)(float)(vecPanelPos.y + flPointRadius));
        ++v5;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DEC0
// Name: private: virtual void CDmeDagRenderPanel::OnFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnFrame(CDmeDagRenderPanel *this)
{
  CDmeDag *v2; // edi
  char v3; // al
  matrix3x4_t dmeToEngine; // [esp+10h] [ebp-7Ch] BYREF
  matrix3x4_t matrix; // [esp+40h] [ebp-4Ch] BYREF
  Vector vecWorldCenter; // [esp+70h] [ebp-1Ch] BYREF
  Vector vecCenter; // [esp+7Ch] [ebp-10h] BYREF
  float flRadius; // [esp+88h] [ebp-4h] BYREF

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hDag.m_handle) != 0 )
  {
    v2 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_hDag.m_handle);
    SetIdentityMatrix(&matrix);
    CDmeDag::GetBoundingSphere(this: v2, c0: &vecCenter, r0: &flRadius, pMat: &matrix);
    v3 = *((_BYTE *)this + 1216);
    if ( (v3 & 0x10) == 0 )
      CDmeDag::DmeToEngineMatrix(&dmeToEngine, bZUp: (v3 & 0x20) != 0);
    VectorTransform(in1: &vecCenter.x, in2: &dmeToEngine, out: &vecWorldCenter.x);
    CPotteryWheelPanel::LookAt(this, vecCenter: &vecWorldCenter, flRadius);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DF70
// Name: private: void CDmeDagRenderPanel::DrawAxis(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeDagRenderPanel::DrawAxis(CDmeDagRenderPanel *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  int v4; // esi
  IMesh *v5; // edi
  float *m_pCurrPosition; // eax
  int v7; // eax
  float *v8; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int m_nVertexCount; // eax
  int v18; // ecx
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a2);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
      a1: v4,
      a2: this->m_axisMaterial.m_pMaterial,
      a3: 0);
    v5 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                    a1: v4,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v7 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v7;
    if ( v7 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v7;
    v8 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                 + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v8;
    *v8 = 10.0;
    v8[1] = 0.0;
    v8[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 0.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 10.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 10.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v18 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v18;
    if ( v18 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v18;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v18;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh, a2: m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E300
// Name: private: void CDmeDagRenderPanel::UpdateMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::UpdateMenu(CDmeDagRenderPanel *this)
{
  switch ( this->m_pDrawSettings->m_DrawType.m_Storage <= 3u ? this->m_pDrawSettings->m_DrawType.m_Storage : 0 )
  {
    case 1:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: true);
      goto LABEL_8;
    case 2:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: true);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: false);
      break;
    case 3:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: true);
      break;
    default:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade, state: true);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade, state: false);
LABEL_8:
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe, state: false);
      vgui::Menu::SetMenuItemChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox, state: false);
      break;
  }
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuNormals,
    state: this->m_pDrawSettings->m_bNormals.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuWireframeOnShaded,
    state: this->m_pDrawSettings->m_bWireframeOnShaded.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuBackfaceCulling,
    state: this->m_pDrawSettings->m_bBackfaceCulling.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuXRay,
    state: this->m_pDrawSettings->m_bXRay.m_Storage);
  vgui::Menu::SetMenuItemChecked(
    this: this->m_pShadingMenu,
    itemID: this->m_nMenuGrayShade,
    state: this->m_pDrawSettings->m_bGrayShade.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0047E4C0
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeDag *pScene)
{
  DmElementHandle_t BufferType; // eax
  CDmeDag *v4; // eax
  int v5; // eax
  CDmeModel *v6; // esi
  DmElementHandle_t m_handle; // [esp-8h] [ebp-10h]

  if ( pScene != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pScene);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
  m_handle = this->m_hDag.m_handle;
  v4 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
  ComputeDefaultTangentData(pDag: v4, bSmoothTangents: m_handle);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hDag.m_handle,
         a3: 0);
  v6 = (CDmeModel *)v5;
  if ( v5 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeModel::m_classType.u) != 0 )
  {
    *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v6))) & 0x20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E560
// Name: private: virtual void CDmeDagRenderPanel::OnSmoothShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnSmoothShade(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuSmoothShade) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 0;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E5B0
// Name: private: virtual void CDmeDagRenderPanel::OnFlatShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnFlatShade(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuFlatShade) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 1;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E600
// Name: private: virtual void CDmeDagRenderPanel::OnWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnWireframe(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframe) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 2;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E650
// Name: private: virtual void CDmeDagRenderPanel::OnBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnBoundingBox(CDmeDagRenderPanel *this)
{
  CDmeDrawSettings *m_pDrawSettings; // eax
  int value; // [esp+4h] [ebp-4h] BYREF

  if ( vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBoundingBox) )
  {
    m_pDrawSettings = this->m_pDrawSettings;
    value = 3;
    CDmAttribute::SetValue<int>(this: m_pDrawSettings->m_DrawType.m_pAttribute, &value);
  }
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E6A0
// Name: private: virtual void CDmeDagRenderPanel::OnNormals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnNormals(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuNormals);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bNormals.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E6E0
// Name: private: virtual void CDmeDagRenderPanel::OnWireframeOnShaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnWireframeOnShaded(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuWireframeOnShaded);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bWireframeOnShaded.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E720
// Name: private: virtual void CDmeDagRenderPanel::OnBackfaceCulling(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnBackfaceCulling(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuBackfaceCulling);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bBackfaceCulling.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E760
// Name: private: virtual void CDmeDagRenderPanel::OnXRay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnXRay(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuXRay);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bXRay.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E7A0
// Name: private: virtual void CDmeDagRenderPanel::OnGrayShade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnGrayShade(CDmeDagRenderPanel *this)
{
  bool IsChecked; // al
  CDmeDrawSettings *m_pDrawSettings; // edx
  bool value; // [esp+4h] [ebp-4h] BYREF

  IsChecked = vgui::Menu::IsChecked(this: this->m_pShadingMenu, itemID: this->m_nMenuGrayShade);
  m_pDrawSettings = this->m_pDrawSettings;
  value = IsChecked;
  CDmAttribute::SetValue<bool>(this: m_pDrawSettings->m_bGrayShade.m_pAttribute, &value);
  CDmeDagRenderPanel::UpdateMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E7E0
// Name: public: virtual void CDmeDagRenderPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDmeDagRenderPanel::Paint(CDmeDagRenderPanel *this)
{
  int v2; // edi
  CDmeClip *v3; // eax
  CDmeClip *v4; // eax
  int v5; // edi
  CDmeClip *v6; // eax
  DmeTime_t v7; // edi
  CDmeClip *v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edi
  CDmeChannel *v13; // edi
  int v14; // edi
  CDmeClip *v15; // eax
  int m_tms; // ebx
  CDmeClip *v17; // eax
  int v18; // edi
  CDmeClip *v19; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  int v23; // edi
  CDmeChannel *v24; // ecx
  char v25; // al
  CDmeModel *v26; // eax
  CDmeModel *sec_4; // [esp+20h] [ebp-54h]
  const matrix3x4_t *v28; // [esp+24h] [ebp-50h]
  matrix3x4_t modelToWorld; // [esp+34h] [ebp-40h] BYREF
  unsigned __int64 sec; // [esp+64h] [ebp-10h] OVERLAPPED BYREF
  unsigned __int64 v31; // [esp+6Ch] [ebp-8h] OVERLAPPED BYREF

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCurrentAnimation.m_handle) != 0 )
  {
    *(double *)&sec = _Plat_FloatTime() - this->m_flStartTime;
    v2 = DmeTime_t::RoundSecondsToTMS(sec);
    v3 = (CDmeClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hCurrentAnimation.m_handle);
    if ( CDmeClip::GetDuration(this: v3, result: (DmeTime_t *)&sec + 1)->m_tms != 0 )
    {
      v4 = (CDmeClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hCurrentAnimation.m_handle);
      v5 = v2 % CDmeClip::GetDuration(this: v4, result: (DmeTime_t *)&sec + 1)->m_tms;
    }
    else
    {
      v5 = 0;
    }
    v6 = (CDmeClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hCurrentAnimation.m_handle);
    v7.m_tms = CDmeClip::GetStartTime(this: v6, result: (DmeTime_t *)&sec + 1)->m_tms + v5;
    v8 = (CDmeClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hCurrentAnimation.m_handle);
    CDmeClip::ToChildMediaTime(this: v8, result: (DmeTime_t *)&v31 + 1, t: v7, bClamp: 1);
    v9 = 0;
    for ( HIDWORD(sec) = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                       a1: g_pDataModel.u,
                                       a2: this->m_hCurrentAnimation.m_handle)
                                   + 152); v9 < SHIDWORD(sec); ++v9 )
    {
      v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_hCurrentAnimation.m_handle);
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: *(_DWORD *)(*(_DWORD *)(v10 + 140) + 4 * v9));
      v12 = v11;
      if ( v11 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
             a1: v11,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v13 = (CDmeChannel *)(v12 - 4);
      }
      else
      {
        v13 = nullptr;
      }
      CDmeChannel::SetCurrentTime(this: v13, time: *(DmeTime_t *)((char *)&v31 + 4));
    }
  }
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCurrentVertexAnimation.m_handle) != 0 )
  {
    *(double *)&v31 = _Plat_FloatTime() - this->m_flStartTime;
    v14 = DmeTime_t::RoundSecondsToTMS(sec: v31);
    v15 = (CDmeClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: this->m_hCurrentVertexAnimation.m_handle);
    m_tms = CDmeClip::GetDuration(this: v15, result: (DmeTime_t *)&v31 + 1)->m_tms;
    v17 = (CDmeClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: this->m_hCurrentVertexAnimation.m_handle);
    v18 = CDmeClip::GetStartTime(this: v17, result: (DmeTime_t *)&v31 + 1)->m_tms + v14 % m_tms;
    v19 = (CDmeClip *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: this->m_hCurrentVertexAnimation.m_handle);
    CDmeClip::ToChildMediaTime(this: v19, result: (DmeTime_t *)&sec + 1, t: (DmeTime_t)v18, bClamp: 1);
    v20 = 0;
    for ( HIDWORD(v31) = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                       a1: g_pDataModel.u,
                                       a2: this->m_hCurrentVertexAnimation.m_handle)
                                   + 152); v20 < SHIDWORD(v31); ++v20 )
    {
      v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_hCurrentVertexAnimation.m_handle);
      v22 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: *(_DWORD *)(*(_DWORD *)(v21 + 140) + 4 * v20));
      v23 = v22;
      if ( v22 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
             a1: v22,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v24 = (CDmeChannel *)(v23 - 4);
      }
      else
      {
        v24 = nullptr;
      }
      CDmeChannel::SetCurrentTime(this: v24, time: *(DmeTime_t *)((char *)&sec + 4));
    }
  }
  BYTE4(sec) = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: &this->m_operators);
  g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: HIDWORD(sec));
  g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
  CPotteryWheelPanel::Paint(this);
  if ( (*((_BYTE *)this + 1216) & 1) != 0
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hDag.m_handle) != 0 )
  {
    v25 = *((_BYTE *)this + 1216);
    if ( (v25 & 0x10) == 0 )
      CDmeDag::DmeToEngineMatrix(dmeToEngine: &modelToWorld, bZUp: (v25 & 0x20) != 0);
    v28 = (const matrix3x4_t *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                 a1: g_pDataModel.u,
                                 a2: this->m_hDag.m_handle);
    sec_4 = (CDmeModel *)this->m_hDag.m_handle;
    v26 = (CDmeModel *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
    CDmeDagRenderPanel::DrawJointNames(this, pRoot: v26, pDag: sec_4, parentToWorld: v28);
  }
  CDmeDagRenderPanel::DrawHighlightPoints(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047EB80
// Name: private: virtual void CDmeDagRenderPanel::OnPaint3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::OnPaint3D(CDmeDagRenderPanel *this)
{
  IMatRenderContext *v2; // esi
  int v3; // ebx
  ITexture *m_pTexture; // ecx
  CDmeDag *v5; // eax

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = (int)v2->GetLocalCubemap(this: v2);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
    m_pTexture = this->m_DefaultHDREnvCubemap.m_pTexture;
  else
    m_pTexture = this->m_DefaultEnvCubemap.m_pTexture;
  v2->BindLocalCubemap(this: v2, a2: m_pTexture);
  if ( (*((_BYTE *)this + 1216) & 4) != 0 )
    CPotteryWheelPanel::DrawGrid(this);
  if ( (*((_BYTE *)this + 1216) & 2) != 0 )
    CDmeJoint::DrawJointHierarchy(bDrawJoints: true);
  v2->CullMode(this: v2, a2: MATERIAL_CULLMODE_CW);
  CDmeDag::DrawUsingEngineCoordinates(bEnable: (*((_BYTE *)this + 1216) & 0x10) == 0);
  CDmeDag::DrawZUp(bZUp: (*((_BYTE *)this + 1216) & 0x20) != 0);
  v5 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hDag.m_handle);
  CDmeDrawSettings::DrawDag(this: this->m_pDrawSettings, pDag: v5);
  CDmeDag::DrawUsingEngineCoordinates(bEnable: false);
  CDmeDag::DrawZUp(bZUp: false);
  if ( (*((_BYTE *)this + 1216) & 8) != 0 )
    CDmeDagRenderPanel::DrawAxis(this, a2: v3, a3: (int)v2);
  v2->Flush(this: v2, a2: false);
  v2->BindLocalCubemap(this: v2, a2: (ITexture *)v3);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0047ECD0
// Name: public: virtual CDmeDagRenderPanel::~CDmeDagRenderPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::~CDmeDagRenderPanel(CDmeDagRenderPanel *this)
{
  this->__vftable = (CDmeDagRenderPanel_vtbl *)&CDmeDagRenderPanel::`vftable';
  if ( g_pMaterialSystem != nullptr )
    CMaterialReference::Shutdown(this: &this->m_axisMaterial, bDeleteIfUnreferenced: false);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hDrawSettings,
      hElement: this->m_hDrawSettings.m_handle,
      handleType: HT_STRONG);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(this: &this->m_hDag, hElement: this->m_hDag.m_handle, handleType: HT_WEAK);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_operators);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hCurrentVertexAnimation,
      hElement: this->m_hCurrentVertexAnimation.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hCurrentAnimation,
      hElement: this->m_hCurrentAnimation.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hVertexAnimationList,
      hElement: this->m_hVertexAnimationList.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hAnimationList,
      hElement: this->m_hAnimationList.m_handle,
      handleType: HT_WEAK);
  CMaterialReference::~CMaterialReference(this: &this->m_axisMaterial);
  CTextureReference::~CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047EDC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeDagRenderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeDagRenderPanel::GetMessageMap(CDmeDagRenderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeDagRenderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagRenderPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeDagRenderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
  `CDmeDagRenderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047EDF0
// Name: public: virtual struct PanelAnimationMap __near * CDmeDagRenderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeDagRenderPanel::GetAnimMap(CDmeDagRenderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeDagRenderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0047EE00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeDagRenderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeDagRenderPanel::GetKBMap(CDmeDagRenderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeDagRenderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeDagRenderPanel::GetKBMap'::`2'::s_pMap;
  `CDmeDagRenderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagRenderPanel");
  `CDmeDagRenderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047EE30
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SmoothShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EEC0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FlatShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EF50
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Wireframe";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EFF0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BoundingBox";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F080
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Normals";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F110
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "WireframeOnShaded";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F1A0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "BackfaceCulling";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F230
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "XRay";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F2C0
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "GrayShade";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F350
// Name: public: static void CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar'::`2'::bAdded )
  {
    `CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Frame";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F3E0
// Name: public: CDmeDagRenderPanel::CDmeDagRenderPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDagRenderPanel *__thiscall CDmeDagRenderPanel::CDmeDagRenderPanel(
        CDmeDagRenderPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int v7; // edx
  char v8; // al
  int v9; // edx
  ITexture *v10; // eax
  ITexture *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  CDmeDrawSettings *v17; // edi
  DmElementHandle_t BufferType; // eax
  vgui::MenuBar *v19; // eax
  vgui::MenuBar *v20; // eax
  vgui::Menu *v21; // eax
  vgui::Menu *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  int v29; // eax
  vgui::Menu *m_pShadingMenu; // ecx
  KeyValues *v31; // eax
  KeyValues *v32; // eax
  int v33; // eax
  vgui::Menu *v34; // ecx
  KeyValues *v35; // eax
  KeyValues *v36; // eax
  KeyValues *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // eax
  KeyValues *v40; // eax
  KeyValues *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // eax
  KeyValues *v44; // eax
  int v45; // eax
  vgui::Menu *v46; // ecx
  CDisableUndoScopeGuard sg; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CPotteryWheelPanel::CPotteryWheelPanel(this, pParent, pName);
  this->__vftable = (CDmeDagRenderPanel_vtbl *)&CDmeDagRenderPanel::`vftable';
  if ( `CDmeDagRenderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeDagRenderPanel");
    v4->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  }
  if ( `CDmeDagRenderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeDagRenderPanel");
    v5->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
  }
  if ( `CDmeDagRenderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeDagRenderPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagRenderPanel");
    v6->pfnClassName = CDmeDagRenderPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  }
  CDmeDagRenderPanel::PanelMessageFunc_OnSmoothShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnFlatShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnWireframe::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnBoundingBox::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnNormals::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnWireframeOnShaded::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnBackfaceCulling::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnXRay::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnGrayShade::InitVar(a1: (int)&savedregs);
  CDmeDagRenderPanel::PanelMessageFunc_OnFrame::InitVar(a1: (int)&savedregs);
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::CTextureReference(this: &this->m_DefaultHDREnvCubemap);
  CMaterialReference::CMaterialReference(
    this: &this->m_axisMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_hAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hVertexAnimationList.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hCurrentAnimation.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hCurrentVertexAnimation.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  this->m_hDag.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hDrawSettings.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = *(_DWORD *)g_pDataModel.u.m_Id;
  *(_WORD *)&sg.m_bReleased = 0;
  sg.m_pNotify = nullptr;
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(v7 + 236))(a1: g_pDataModel.u);
  v9 = *(_DWORD *)g_pDataModel.u.m_Id;
  sg.m_bOldValue = v8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v9 + 232))(a1: g_pDataModel.u, a2: 0);
  *((_BYTE *)this + 1216) = *((_BYTE *)this + 1216) & 0xC0 | 0xC;
  v10 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "editor/cubemap", a3: 0, a4: 1, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v10);
  v11 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "editor/cubemap.hdr", a3: 0, a4: 1, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultHDREnvCubemap, pTexture: v11);
  if ( g_pMaterialSystem != nullptr )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v13 = KeyValues::KeyValues(this: v12, setName: "wireframe");
    else
      v13 = nullptr;
    KeyValues::SetInt(this: v13, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v13, keyName: "$ignorez", value: 1);
    CMaterialReference::Init(this: &this->m_axisMaterial, pMaterialName: "__DmeDagRenderPanelAxis", pVMTKeyValues: v13);
  }
  v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 356))(
          a1: g_pDataModel.u,
          a2: "DagRenderPanelDrawSettings");
  v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
          a1: g_pDataModel.u,
          a2: CDmeDrawSettings::m_classType.u,
          a3: "drawSettings",
          a4: v14,
          a5: 0);
  v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: v15);
  v17 = (CDmeDrawSettings *)v16;
  if ( v16 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v16 + 16))(
         a1: v16,
         a2: CDmeDrawSettings::m_classType.u) == 0 )
  {
    v17 = nullptr;
  }
  this->m_pDrawSettings = v17;
  if ( v17 != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v17);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDrawSettings,1>::Set(this: &this->m_hDrawSettings, h: BufferType);
  v19 = (vgui::MenuBar *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v19 != nullptr )
    v20 = vgui::MenuBar::MenuBar(this: v19, parent: this, panelName: "Dag Render Panel Menu Bar");
  else
    v20 = nullptr;
  this->m_pMenuBar = v20;
  v21 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v21 != nullptr )
    v22 = vgui::Menu::Menu(this: v21, parent: nullptr, panelName: "Shading Menu");
  else
    v22 = nullptr;
  this->m_pShadingMenu = v22;
  v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v23 != nullptr )
    v24 = KeyValues::KeyValues(this: v23, setName: "SmoothShade");
  else
    v24 = nullptr;
  this->m_nMenuSmoothShade = this->m_pShadingMenu->AddCheckableMenuItem(
                               this: this->m_pShadingMenu,
                               a2: "&Smooth Shade",
                               a3: v24,
                               a4: this,
                               a5: nullptr);
  v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v25 != nullptr )
    v26 = KeyValues::KeyValues(this: v25, setName: "FlatShade");
  else
    v26 = nullptr;
  this->m_nMenuFlatShade = this->m_pShadingMenu->AddCheckableMenuItem(
                             this: this->m_pShadingMenu,
                             a2: "&Flat Shade",
                             a3: v26,
                             a4: this,
                             a5: nullptr);
  v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v27 != nullptr )
    v28 = KeyValues::KeyValues(this: v27, setName: "Wireframe");
  else
    v28 = nullptr;
  v29 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Wireframe",
          a3: v28,
          a4: this,
          a5: nullptr);
  m_pShadingMenu = this->m_pShadingMenu;
  this->m_nMenuWireframe = v29;
  m_pShadingMenu->AddSeparator(this: m_pShadingMenu);
  v31 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v31 != nullptr )
    v32 = KeyValues::KeyValues(this: v31, setName: "BoundingBox");
  else
    v32 = nullptr;
  v33 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Bounding Box",
          a3: v32,
          a4: this,
          a5: nullptr);
  v34 = this->m_pShadingMenu;
  this->m_nMenuBoundingBox = v33;
  v34->AddSeparator(this: v34);
  v35 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v35 != nullptr )
    v36 = KeyValues::KeyValues(this: v35, setName: "Normals");
  else
    v36 = nullptr;
  this->m_nMenuNormals = this->m_pShadingMenu->AddCheckableMenuItem(
                           this: this->m_pShadingMenu,
                           a2: "&Normals",
                           a3: v36,
                           a4: this,
                           a5: nullptr);
  v37 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v37 != nullptr )
    v38 = KeyValues::KeyValues(this: v37, setName: "WireframeOnShaded");
  else
    v38 = nullptr;
  this->m_nMenuWireframeOnShaded = this->m_pShadingMenu->AddCheckableMenuItem(
                                     this: this->m_pShadingMenu,
                                     a2: "WireFrame &On Shaded",
                                     a3: v38,
                                     a4: this,
                                     a5: nullptr);
  v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v39 != nullptr )
    v40 = KeyValues::KeyValues(this: v39, setName: "BackfaceCulling");
  else
    v40 = nullptr;
  this->m_nMenuBackfaceCulling = this->m_pShadingMenu->AddCheckableMenuItem(
                                   this: this->m_pShadingMenu,
                                   a2: "&Backface Culling",
                                   a3: v40,
                                   a4: this,
                                   a5: nullptr);
  v41 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v41 != nullptr )
    v42 = KeyValues::KeyValues(this: v41, setName: "XRay");
  else
    v42 = nullptr;
  this->m_nMenuXRay = this->m_pShadingMenu->AddCheckableMenuItem(
                        this: this->m_pShadingMenu,
                        a2: "&X-Ray",
                        a3: v42,
                        a4: this,
                        a5: nullptr);
  v43 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v43 != nullptr )
    v44 = KeyValues::KeyValues(this: v43, setName: "GrayShade");
  else
    v44 = nullptr;
  v45 = this->m_pShadingMenu->AddCheckableMenuItem(
          this: this->m_pShadingMenu,
          a2: "&Gray Shade",
          a3: v44,
          a4: this,
          a5: nullptr);
  v46 = this->m_pShadingMenu;
  this->m_nMenuGrayShade = v45;
  v46->SetItemVisible(this: v46, a2: this->m_nMenuFlatShade, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuFlatShade, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuBoundingBox, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuBoundingBox, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuBackfaceCulling, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuBackfaceCulling, a3: false);
  this->m_pShadingMenu->SetItemVisible(this: this->m_pShadingMenu, a2: this->m_nMenuXRay, a3: false);
  this->m_pShadingMenu->SetItemEnabled(this: this->m_pShadingMenu, a2: this->m_nMenuXRay, a3: false);
  this->m_pMenuBar->AddMenu(this: this->m_pMenuBar, a2: "&Shading", a3: this->m_pShadingMenu);
  CDmeDagRenderPanel::UpdateMenu(this);
  CChangeUndoScopeGuard::Release(this: &sg);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047FA60
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeSourceSkin __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeSourceSkin *pSkin)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax
  CDmeModel *v5; // ebx
  CExpressionCalculator *Value; // eax
  DmElementHandle_t BufferType; // eax
  CDmeDag *v8; // eax
  int v9; // eax
  CDmeModel *v10; // edi
  CDmeModel *v11; // ecx
  DmElementHandle_t m_handle; // [esp-8h] [ebp-14h]

  DependentMakefile = CDmeSource::GetDependentMakefile(this: pSkin);
  if ( DependentMakefile == nullptr
    || (OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true),
        v5 = (CDmeModel *)OutputElement,
        OutputElement == nullptr) )
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
    return;
  }
  Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
  if ( Value != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: Value);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
  m_handle = this->m_hDag.m_handle;
  v8 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
  ComputeDefaultTangentData(pDag: v8, bSmoothTangents: m_handle);
  *((_BYTE *)this + 1216) &= 0xFCu;
  v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hDag.m_handle,
         a3: 0);
  v10 = (CDmeModel *)v9;
  if ( v9 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
         a1: v9,
         a2: CDmeModel::m_classType.u) != 0 )
  {
    v11 = v10;
  }
  else
  {
    if ( !v5->IsA(this: v5, a2: CDmeModel::m_classType) )
      return;
    v11 = v5;
  }
  *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v11))) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x0047FB60
// Name: private: void CDmeDagRenderPanel::RebuildOperatorList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::RebuildOperatorList(CDmeDagRenderPanel *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // edi
  CDmeChannel *v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v12; // eax
  IDmeOperator **v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // edi
  CDmeChannel *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // edi
  int v22; // eax
  IDmeOperator **v23; // ecx
  int v24; // eax
  IDmeOperator **v25; // eax
  int nChannelCount; // [esp+Ch] [ebp-Ch]
  int nChannelCounta; // [esp+Ch] [ebp-Ch]
  IDmeOperator *v28; // [esp+10h] [ebp-8h]
  IDmeOperator *v29; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int ia; // [esp+14h] [ebp-4h]

  this->m_operators.m_Size = 0;
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCurrentAnimation.m_handle) != 0 )
  {
    nChannelCount = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hCurrentAnimation.m_handle)
                              + 152);
    for ( i = 0; i < nChannelCount; ++i )
    {
      v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hCurrentAnimation.m_handle);
      v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v2 + 140) + 4 * i));
      v4 = v3;
      if ( v3 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
             a1: v3,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v5 = (CDmeChannel *)(v4 - 4);
      }
      else
      {
        v5 = nullptr;
      }
      CDmeChannel::SetMode(this: v5, mode: CM_PLAY);
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hCurrentAnimation.m_handle);
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v6 + 140) + 4 * i));
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v28 = (IDmeOperator *)(v8 - 4);
      }
      else
      {
        v28 = nullptr;
      }
      m_Size = this->m_operators.m_Size;
      m_nAllocationCount = this->m_operators.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_operators,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_operators.m_Size;
      m_pMemory = this->m_operators.m_Memory.m_pMemory;
      v12 = this->m_operators.m_Size - m_Size - 1;
      this->m_operators.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &this->m_operators.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = v28;
    }
  }
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCurrentVertexAnimation.m_handle) != 0 )
  {
    nChannelCounta = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_hCurrentVertexAnimation.m_handle)
                               + 152);
    for ( ia = 0; ia < nChannelCounta; ++ia )
    {
      v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_hCurrentVertexAnimation.m_handle);
      v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: *(_DWORD *)(*(_DWORD *)(v14 + 140) + 4 * ia));
      v16 = v15;
      if ( v15 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
             a1: v15,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v17 = (CDmeChannel *)(v16 - 4);
      }
      else
      {
        v17 = nullptr;
      }
      CDmeChannel::SetMode(this: v17, mode: CM_PLAY);
      v18 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_hCurrentVertexAnimation.m_handle);
      v19 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: *(_DWORD *)(*(_DWORD *)(v18 + 140) + 4 * ia));
      v20 = v19;
      if ( v19 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v19 + 16))(
             a1: v19,
             a2: CDmeChannel::m_classType.u) != 0 )
      {
        v29 = (IDmeOperator *)(v20 - 4);
      }
      else
      {
        v29 = nullptr;
      }
      v21 = this->m_operators.m_Size;
      v22 = this->m_operators.m_Memory.m_nAllocationCount;
      if ( v21 + 1 > v22 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_operators,
          num: v21 - v22 + 1);
      ++this->m_operators.m_Size;
      v23 = this->m_operators.m_Memory.m_pMemory;
      v24 = this->m_operators.m_Size - v21 - 1;
      this->m_operators.m_pElements = v23;
      if ( v24 > 0 )
        _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 4 * v24);
      v25 = &this->m_operators.m_Memory.m_pMemory[v21];
      if ( v25 != nullptr )
        *v25 = v29;
    }
  }
  this->m_flStartTime = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x0047FE90
// Name: private: void CDmeDagRenderPanel::SelectAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectAnimation(CDmeDagRenderPanel *this, int nIndex)
{
  int v3; // eax
  int v4; // eax
  CExpressionCalculator *v5; // esi
  CExpressionCalculator *v6; // ecx
  DmElementHandle_t BufferType; // eax

  CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hAnimationList.m_handle) != 0
    && nIndex >= 0 )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hAnimationList.m_handle);
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)(*(_DWORD *)(v3 + 68) + 4 * nIndex));
    v5 = (CExpressionCalculator *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeChannelsClip::m_classType.u) != 0 )
    {
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    if ( v6 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: BufferType);
  }
  CDmeDagRenderPanel::RebuildOperatorList(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047FF40
// Name: private: void CDmeDagRenderPanel::SelectVertexAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectVertexAnimation(CDmeDagRenderPanel *this, int nIndex)
{
  int v3; // eax
  int v4; // eax
  CExpressionCalculator *v5; // esi
  CExpressionCalculator *v6; // ecx
  DmElementHandle_t BufferType; // eax

  CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hVertexAnimationList.m_handle) != 0
    && nIndex >= 0 )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hVertexAnimationList.m_handle);
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)(*(_DWORD *)(v3 + 68) + 4 * nIndex));
    v5 = (CExpressionCalculator *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeChannelsClip::m_classType.u) != 0 )
    {
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    if ( v6 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: v6);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: BufferType);
  }
  CDmeDagRenderPanel::RebuildOperatorList(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047FFF0
// Name: public: void CDmeDagRenderPanel::SelectAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectAnimation(CDmeDagRenderPanel *this, const char *pAnimName)
{
  CDmeAnimationList *v3; // eax
  int Animation; // eax

  if ( *pAnimName != 0 )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hAnimationList.m_handle) != 0 )
    {
      v3 = (CDmeAnimationList *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hAnimationList.m_handle);
      Animation = CDmeAnimationList::FindAnimation(this: v3, pAnimName);
      if ( Animation >= 0 )
        CDmeDagRenderPanel::SelectAnimation(this, nIndex: Animation);
    }
  }
  else
  {
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
      a1: g_pDataModel.u,
      a2: this->m_hAnimationList.m_handle);
    CDmeDagRenderPanel::RebuildOperatorList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480080
// Name: public: void CDmeDagRenderPanel::SelectVertexAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SelectVertexAnimation(CDmeDagRenderPanel *this, const char *pAnimName)
{
  CDmeAnimationList *v3; // eax
  int Animation; // eax

  if ( *pAnimName != 0 )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hVertexAnimationList.m_handle) != 0 )
    {
      v3 = (CDmeAnimationList *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hVertexAnimationList.m_handle);
      Animation = CDmeAnimationList::FindAnimation(this: v3, pAnimName);
      if ( Animation >= 0 )
        CDmeDagRenderPanel::SelectVertexAnimation(this, nIndex: Animation);
    }
  }
  else
  {
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
      a1: g_pDataModel.u,
      a2: this->m_hVertexAnimationList.m_handle);
    CDmeDagRenderPanel::RebuildOperatorList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480110
// Name: public: void CDmeDagRenderPanel::SetAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetAnimationList(CDmeDagRenderPanel *this, CExpressionCalculator *pAnimationList)
{
  DmElementHandle_t BufferType; // eax

  if ( pAnimationList != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pAnimationList);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hAnimationList, h: BufferType);
  if ( pAnimationList != nullptr && pAnimationList[1].m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    CDmeDagRenderPanel::SelectAnimation(this, nIndex: 0);
  else
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentAnimation, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00480170
// Name: public: void CDmeDagRenderPanel::SetVertexAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetVertexAnimationList(
        CDmeDagRenderPanel *this,
        CExpressionCalculator *pAnimationList)
{
  DmElementHandle_t BufferType; // eax

  if ( pAnimationList != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pAnimationList);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hVertexAnimationList, h: BufferType);
  if ( pAnimationList != nullptr && pAnimationList[1].m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    CDmeDagRenderPanel::SelectVertexAnimation(this, nIndex: 0);
  else
    CDmeHandle<CDmeChannelsClip,0>::Set(this: &this->m_hCurrentVertexAnimation, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x004802D0
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeSourceAnimation __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeDagRenderPanel::SetDmeElement(
        CDmeDagRenderPanel *this@<ecx>,
        bool a2@<bl>,
        CDmeSourceAnimation *pAnimation)
{
  CDmeMakefile *DependentMakefile; // eax
  CDmElement *OutputElement; // eax
  CDmElement *v6; // edi
  CDmeDag *Value; // ebx
  CDmeAnimationList *v8; // eax
  const char *m_pAsString; // edx
  CDmeDag *v10; // eax
  const char *v11; // eax
  CDmElement *v12; // eax
  CDmeModel *v13; // eax
  CDmeAnimationList *pAnimationList; // [esp+8h] [ebp-4h]

  DependentMakefile = CDmeSource::GetDependentMakefile(this: pAnimation);
  if ( DependentMakefile != nullptr )
  {
    OutputElement = CDmeMakefile::GetOutputElement(this: DependentMakefile, bCreateIfNecessary: true);
    v6 = OutputElement;
    if ( OutputElement != nullptr )
    {
      Value = CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
      if ( Value != nullptr
        || (Value = CDmElement::GetValueElement<CDmeDag>(this: v6, pAttributeName: "skeleton")) != nullptr )
      {
        v8 = CDmElement::GetValueElement<CDmeAnimationList>(this: v6, pAttributeName: "animationList");
        pAnimationList = v8;
        if ( v8 != nullptr )
        {
          m_pAsString = pAnimation->m_SourceAnimationName.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          if ( CDmeAnimationList::FindAnimation(this: v8, pAnimName: m_pAsString) >= 0 )
          {
            CDmeHandle<CDmeDag,0>::operator=(this: &this->m_hDag, pObject: Value);
            v10 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                               a1: g_pDataModel.u,
                               a2: this->m_hDag.m_handle,
                               a3: 0);
            ComputeDefaultTangentData(pDag: v10, bSmoothTangents: a2);
            CDmeHandle<CDmeAnimationList,0>::operator=(this: &this->m_hAnimationList, pObject: pAnimationList);
            v11 = pAnimation->m_SourceAnimationName.m_Storage.u.m_pAsString;
            if ( v11 == (const char *)-1 )
              v11 = defaultValue;
            CDmeDagRenderPanel::SelectAnimation(this, pAnimName: v11);
            *((_BYTE *)this + 1216) |= 3u;
            v12 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hDag.m_handle);
            v13 = CastElement<CDmeModel>(pElement: v12);
            if ( v13 != nullptr || (v13 = CastElement<CDmeModel>(pElement: v6)) != nullptr )
              *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v13))) & 0x20;
          }
        }
      }
    }
    else
    {
      CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
    }
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480430
// Name: public: void CDmeDagRenderPanel::SetDmeElement(class CDmeDCCMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDagRenderPanel::SetDmeElement(CDmeDagRenderPanel *this, CDmeDag *pDCCMakefile)
{
  CDmElement *OutputElement; // eax
  CDmElement *v4; // edi
  CExpressionCalculator *Value; // ebx
  DmElementHandle_t BufferType; // eax
  CDmeDag *v7; // eax
  DmElementHandle_t v8; // eax
  DmElementHandle_t m_handle; // edx
  int v10; // eax
  CDmeModel *v11; // edi
  CDmElement *pOutputElement; // [esp+Ch] [ebp-4h]
  CDmeDag *pDag; // [esp+18h] [ebp+8h]

  OutputElement = CDmeMakefile::GetOutputElement(this: (CDmeMakefile *)pDCCMakefile, bCreateIfNecessary: true);
  v4 = OutputElement;
  pOutputElement = OutputElement;
  if ( OutputElement != nullptr )
  {
    pDag = CDmElement::GetValueElement<CDmeDag>(this: OutputElement, pAttributeName: "model");
    if ( pDag != nullptr
      || (pDag = CDmElement::GetValueElement<CDmeDag>(this: v4, pAttributeName: "skeleton")) != nullptr )
    {
      Value = (CExpressionCalculator *)CDmElement::GetValueElement<CDmeAnimationList>(
                                         this: v4,
                                         pAttributeName: "animationList");
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDag);
      CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: BufferType);
      v7 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: this->m_hDag.m_handle);
      ComputeDefaultTangentData(pDag: v7, bSmoothTangents: false);
      v8 = Value != nullptr ? CCodecBuffer_Block::GetBufferType(this: Value) : DMELEMENT_HANDLE_INVALID;
      if ( (CDmeHandle<CDmeAnimationList,0>::Set(this: &this->m_hAnimationList, h: v8),
            CDmeDagRenderPanel::SelectAnimation(this, nIndex: 0),
            m_handle = this->m_hDag.m_handle,
            *((_BYTE *)this + 1216) = (Value != nullptr) | *((_BYTE *)this + 1216) & 0xFC | (2 * (Value != nullptr)),
            v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: m_handle),
            v11 = (CDmeModel *)v10,
            v10 != 0)
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
             a1: v10,
             a2: CDmeModel::m_classType.u) != 0
        || (v11 = (CDmeModel *)pOutputElement, pOutputElement->IsA(this: pOutputElement, a2: CDmeModel::m_classType)) )
      {
        *((_BYTE *)this + 1216) ^= (*((_BYTE *)this + 1216) ^ (32 * CDmeModel::IsZUp(this: v11))) & 0x20;
      }
    }
  }
  else
  {
    CDmeHandle<CDmeDag,0>::Set(this: &this->m_hDag, h: DMELEMENT_HANDLE_INVALID);
  }
}

} // namespace sceneviewer
