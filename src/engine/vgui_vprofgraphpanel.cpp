// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_vprofgraphpanel.cpp
// Functions: 140
// ============================================================

#include "engine\vgui_vprofgraphpanel.h"

//------------------------------------------------------------------------------
// Address: 0x100843C0
// Name: public: virtual void CVProfGraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfGraphPanel::ApplySchemeSettings(CEntityReportPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102054D0
// Name: public: virtual void CVProfGraphPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfGraphPanel::OnTick(CBasePanel *this)
{
  CBasePanel_vtbl *v2; // edi
  bool v3; // al

  v2 = this->__vftable;
  v3 = this->ShouldDraw(this);
  v2->SetVisible(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1020D630
// Name: void IN_VProfPrevSibling(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_VProfPrevSibling()
{
  CVProfNode *PrevSibling; // eax

  PrevSibling = CVProfNode::GetPrevSibling(this: CVProfGraphPanel::m_CurrentNode);
  if ( PrevSibling != nullptr )
    CVProfGraphPanel::m_CurrentNode = PrevSibling;
}

//------------------------------------------------------------------------------
// Address: 0x1020D650
// Name: void IN_VProfNextSibling(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_VProfNextSibling()
{
  CVProfNode *Sibling; // eax

  Sibling = CVProfNode::GetSibling(this: CVProfGraphPanel::m_CurrentNode);
  if ( Sibling != nullptr )
    CVProfGraphPanel::m_CurrentNode = Sibling;
}

//------------------------------------------------------------------------------
// Address: 0x1020D670
// Name: void IN_VProfParent(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_VProfParent()
{
  CVProfNode *Parent; // eax

  Parent = CVProfNode::GetParent(this: CVProfGraphPanel::m_CurrentNode);
  if ( Parent != nullptr )
    CVProfGraphPanel::m_CurrentNode = Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1020D690
// Name: void IN_VProfChild(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_VProfChild()
{
  CVProfNode *Child; // eax
  CVProfNode *Sibling; // esi
  double PrevTime; // st6

  Child = CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode);
  Sibling = Child;
  if ( Child != nullptr )
  {
    CVProfGraphPanel::m_CurrentNode = Child;
    do
    {
      PrevTime = CVProfNode::GetPrevTime(this: Sibling);
      if ( PrevTime > CVProfNode::GetPrevTime(this: CVProfGraphPanel::m_CurrentNode) )
        CVProfGraphPanel::m_CurrentNode = Sibling;
      Sibling = CVProfNode::GetSibling(this: Sibling);
    }
    while ( Sibling != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D6F0
// Name: private: void CVProfGraphPanel::GetNextSample(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfGraphPanel::GetNextSample(CVProfGraphPanel *this)
{
  struct CVProfNode *Parent; // eax
  CVProfNode *v3; // ecx
  CVProfNode *Root; // eax

  this->m_CurrentSample = (this->m_CurrentSample + 1) % 256;
  this->m_Samples[this->m_CurrentSample][0] = CVProfNode::GetPrevTime(this: CVProfGraphPanel::m_CurrentNode);
  Parent = CVProfNode::GetParent(this: CVProfGraphPanel::m_CurrentNode);
  v3 = CVProfGraphPanel::m_CurrentNode;
  if ( Parent != nullptr )
    v3 = CVProfNode::GetParent(this: CVProfGraphPanel::m_CurrentNode);
  this->m_Samples[this->m_CurrentSample][1] = CVProfNode::GetPrevTime(this: v3);
  Root = CVProfile::GetRoot(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  this->m_Samples[this->m_CurrentSample][2] = CVProfNode::GetPrevTime(this: Root);
}

//------------------------------------------------------------------------------
// Address: 0x1020D790
// Name: void DestroyVProfGraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyVProfGraphPanel()
{
  if ( s_pVProfGraphPanel != nullptr )
  {
    s_pVProfGraphPanel->SetParent_2(this: s_pVProfGraphPanel, a2: nullptr);
    if ( s_pVProfGraphPanel != nullptr )
      ((void (__thiscall *)(CVProfGraphPanel *, int))s_pVProfGraphPanel->dtr_Panel)(a1: s_pVProfGraphPanel, a2: 1);
    s_pVProfGraphPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D7D0
// Name: void HideVProfGraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HideVProfGraphPanel()
{
  if ( s_pVProfGraphPanel != nullptr )
    s_pVProfGraphPanel->SetVisible(this: s_pVProfGraphPanel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020D7F0
// Name: public: CVProfGraphPanel::CVProfGraphPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CVProfGraphPanel *__thiscall CVProfGraphPanel::CVProfGraphPanel(CVProfGraphPanel *this, unsigned int parent)
{
  int v3; // eax
  int v5; // [esp-4h] [ebp-10h]

  vgui::Panel::Panel(this, parent: nullptr, panelName: "CVProfGraphPanel");
  this->__vftable = (CVProfGraphPanel_vtbl *)&CVProfGraphPanel::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_WhiteMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  vgui::Panel::SetParent(this, newParent: parent);
  v5 = videomode->GetModeHeight(this: videomode);
  v3 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetSize(this, wide: v3, tall: v5);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Panel::SetCursor(this, cursor: 0);
  this->m_hFont = 0;
  CBaseDemoAction::SetTimingType(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  memset(dst: (unsigned __int8 *)this->m_Samples, value: 0, count: sizeof(this->m_Samples));
  this->m_CurrentSample = 0;
  CVProfGraphPanel::m_CurrentNode = CVProfile::GetRoot(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  if ( CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode) != nullptr )
  {
    CVProfGraphPanel::m_CurrentNode = CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode);
    if ( CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode) != nullptr )
      CVProfGraphPanel::m_CurrentNode = CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode);
  }
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  CMaterialReference::Init(
    this: &this->m_WhiteMaterial,
    pMaterialName: "vgui/white",
    pTextureGroupName: "Other textures",
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020D960
// Name: void CreateVProfGraphPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateVProfGraphPanel(vgui::Panel *pParent)
{
  CVProfGraphPanel *v1; // esi
  unsigned int v2; // eax

  v1 = (CVProfGraphPanel *)MemAlloc_Alloc(nSize: 0xD5Cu);
  if ( v1 != nullptr )
  {
    v2 = pParent->GetVPanel(this: pParent);
    s_pVProfGraphPanel = CVProfGraphPanel::CVProfGraphPanel(this: v1, parent: v2);
  }
  else
  {
    s_pVProfGraphPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D9A0
// Name: public: virtual bool CVProfGraphPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVProfGraphPanel::ShouldDraw(CVProfGraphPanel *this)
{
  return vprof_graph.m_pParent != nullptr && vprof_graph.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020D9C0
// Name: private: void CVProfGraphPanel::PaintLineArt(int,int,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CVProfGraphPanel::PaintLineArt(
        CVProfGraphPanel *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        int x,
        int y,
        int w)
{
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  IMesh *v9; // edi
  int v11; // esi
  int v12; // esi
  int v13; // edi
  float v14; // xmm1_4
  float *v15; // ecx
  float *m_pCurrPosition; // ecx
  float *v17; // eax
  float *v18; // eax
  float v19; // xmm0_4
  unsigned __int8 *v20; // ecx
  int m_CurrentSample; // eax
  int v22; // edi
  int v23; // esi
  int v24; // ecx
  __m128i v25; // xmm1
  float v26; // xmm1_4
  int v27; // eax
  float *v28; // ecx
  float *v29; // ecx
  float v30; // xmm1_4
  float v31; // xmm1_4
  float *v32; // eax
  float *v33; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-220h] BYREF
  IMesh *m_pMesh; // [esp+1E8h] [ebp-38h]
  float v39; // [esp+1ECh] [ebp-34h]
  float v40; // [esp+1F0h] [ebp-30h]
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-2Ch]
  float flMsToPixel; // [esp+1F8h] [ebp-28h]
  CVProfGraphPanel *v43; // [esp+1FCh] [ebp-24h]
  float v44; // [esp+200h] [ebp-20h]
  unsigned __int8 *v45; // [esp+204h] [ebp-1Ch]
  float flDxDSample; // [esp+208h] [ebp-18h]
  int i; // [esp+20Ch] [ebp-14h]
  unsigned __int8 color[3][4]; // [esp+210h] [ebp-10h] BYREF
  int nPanelHeight; // [esp+21Ch] [ebp-4h]
  unsigned int xa; // [esp+228h] [ebp+8h]
  float sample; // [esp+230h] [ebp+10h]
  int samplea; // [esp+230h] [ebp+10h]

  nPanelHeight = (int)(float)((float)(vprof_graphheight.m_pParent->m_Value.m_fValue - 24.0) - 2.0);
  v43 = this;
  CVProfGraphPanel::GetNextSample(this);
  v7 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                              a1: materials,
                              a2,
                              a3);
  v8 = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v9 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: this->m_WhiteMaterial.m_pMaterial);
  m_pMesh = v9;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v9;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v11 = 2 * (3 * w + 4);
  v9->SetPrimitiveType(this: v9, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v11, a3: v11, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v9, nMaxVertexCount: v11, desc: &meshBuilder);
  v12 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v13 = nPanelHeight / 3;
  v44 = (float)x;
  sample = (float)(w + x);
  do
  {
    v14 = v44;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12 != 0 ? -8355712 : -1;
    v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v15[1] = 0.0;
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    m_pCurrPosition[1] = (float)(y - v12 * v13);
    m_pCurrPosition[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12 != 0 ? -8355712 : -1;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v17[1] = 0.0;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = sample;
    v18[1] = (float)(y - v12 * v13);
    v18[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v12;
  }
  while ( v12 < 4 );
  *(_DWORD *)&color[0][0] = -16776961;
  *(_DWORD *)&color[1][0] = -65536;
  *(_DWORD *)&color[2][0] = -1;
  flMsToPixel = (float)nPanelHeight * 0.02;
  if ( w > 256 )
    v19 = (float)w * 0.00390625;
  else
    v19 = 1.0;
  v20 = &color[2][1];
  flDxDSample = v19;
  i = 2;
  v45 = &color[2][1];
  do
  {
    m_CurrentSample = v43->m_CurrentSample;
    samplea = m_CurrentSample;
    v22 = w;
    if ( w >= 0 )
    {
      v23 = v20[1] | ((*v20 | ((*(v20 - 1) | (v20[2] << 8)) << 8)) << 8);
      xa = -1;
      while ( 1 )
      {
        v24 = (int)(float)((float)(v43->m_Samples[0][2 * m_CurrentSample + m_CurrentSample + i] * flMsToPixel) + 0.5);
        v25 = _mm_cvtsi32_si128(xa);
        if ( v24 > nPanelHeight )
          v24 = nPanelHeight;
        v26 = (float)(_mm_cvtepi32_ps(v25).m128_f32[0] * flDxDSample) + v44;
        v27 = y - v24;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v28[1] = 0.0;
        v29 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v30 = (float)(int)(float)(v26 + 0.5);
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v30;
        v39 = v30;
        v29[1] = (float)v27;
        v29[2] = 0.0;
        v40 = (float)v27;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( v22 != w && v22 != 0 )
        {
          v31 = v39;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
          v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
          v32[1] = 0.0;
          v33 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v31;
          v33[1] = v40;
          v33[2] = 0.0;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        }
        if ( --samplea < 0 )
          samplea = 255;
        ++xa;
        if ( --v22 < 0 )
          break;
        m_CurrentSample = samplea;
      }
      v20 = v45;
    }
    v20 -= 4;
    --i;
    v45 = v20;
  }
  while ( i >= 0 );
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
  m_pMesh->Draw_2(this: m_pMesh, a2: -1, a3: 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1020DEC0
// Name: public: virtual void CVProfGraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfGraphPanel::Paint(CVProfGraphPanel *this)
{
  int v2; // esi
  int v3; // eax
  int m_nValue; // edi
  int v5; // esi
  int v6; // eax
  CVProfNode *Root; // eax
  const char *Name; // eax
  int v9; // esi
  unsigned __int8 *v10; // edi
  double v11; // [esp+4h] [ebp-138h]
  char pDest[20]; // [esp+18h] [ebp-124h] BYREF
  char sz[256]; // [esp+2Ch] [ebp-110h]
  const char *pTitles[3]; // [esp+12Ch] [ebp-10h] BYREF
  int v15; // [esp+138h] [ebp-4h]

  if ( this->ShouldDraw(this) )
  {
    v2 = videomode->GetModeWidth(this: videomode);
    v3 = videomode->GetModeHeight(this: videomode);
    if ( vprof_graphwidth.m_pParent != nullptr )
      m_nValue = vprof_graphwidth.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( v2 < m_nValue + 10 )
      m_nValue = v2 - 10;
    v5 = v2 - m_nValue - 5;
    v15 = v3 - 29;
    CVProfGraphPanel::PaintLineArt(this, x: v5, y: v3 - 29, w: m_nValue);
    if ( vprof_graphheight.m_pParent != nullptr )
      v6 = vprof_graphheight.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    v15 -= v6;
    Root = CVProfile::GetRoot(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    *(double *)&sz[248] = CVProfNode::GetPrevTime(this: Root);
    if ( g_ClientGlobalVariables.absoluteframetime > 0.0 )
    {
      v11 = CVProfNode::GetPrevTime(this: CVProfGraphPanel::m_CurrentNode) / *(double *)&sz[248] * 100.0;
      Name = CVProfNode::GetName(this: CVProfGraphPanel::m_CurrentNode);
      V_snprintf(pDest, maxLen: 256, pFormat: "%s - %0.1f%%%%", Name, v11);
      g_pMatSystemSurface->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: this->m_hFont,
        a3: v5,
        a4: v15,
        a5: 229,
        a6: 229,
        a7: 178,
        a8: 255,
        a9: pDest);
    }
    pTitles[0] = (const char *)255;
    pTitles[1] = (const char *)-256;
    LOBYTE(pTitles[2]) = -1;
    *(_DWORD *)&sz[236] = CVProfNode::GetName(this: CVProfGraphPanel::m_CurrentNode);
    *(_DWORD *)&sz[252] = m_nValue / 2 + v5;
    *(_DWORD *)&sz[240] = "Parent";
    *(_DWORD *)&sz[244] = "Total";
    v9 = 2;
    v10 = (unsigned __int8 *)&pTitles[1] + 3;
    do
    {
      V_snprintf(
        pDest,
        maxLen: 256,
        pFormat: "%07.3f ms (%s)",
        this->m_Samples[0][2 * this->m_CurrentSample + this->m_CurrentSample + v9],
        *(const char **)&sz[4 * v9 + 236]);
      v15 -= 10;
      g_pMatSystemSurface->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: this->m_hFont,
        a3: *(_DWORD *)&sz[252],
        a4: v15,
        a5: *(v10 - 1),
        a6: *v10,
        a7: v10[1],
        a8: 180,
        a9: pDest);
      v10 -= 3;
      --v9;
    }
    while ( v9 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313AA0
// Name: _dynamic_initializer_for__vprof_remote_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_remote_start_command__()
{
  ConCommand::ConCommand(
    this: &vprof_remote_start_command,
    pName: "vprof_remote_start",
    callback: (void (__cdecl *)())CColorBalanceUIPanel::Init,
    pHelpString: "Request a VProf data stream from the remote server (requires authentication)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_remote_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313AD0
// Name: _dynamic_initializer_for__vprof_remote_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_remote_stop_command__()
{
  ConCommand::ConCommand(
    this: &vprof_remote_stop_command,
    pName: "vprof_remote_stop",
    callback: (void (__cdecl *)())CColorBalanceUIPanel::Init,
    pHelpString: "Stop an existing remote VProf data request",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_remote_stop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A860
// Name: _dynamic_initializer_for__vprof_server_spike_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_server_spike_threshold__()
{
  ConVar::ConVar(
    this: &vprof_server_spike_threshold,
    pName: "vprof_server_spike_threshold",
    pDefaultValue: "999.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_server_spike_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A890
// Name: _dynamic_initializer_for__vprof_server_thread__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_server_thread__()
{
  ConVar::ConVar(this: &vprof_server_thread, pName: "vprof_server_thread", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_server_thread__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E4E0
// Name: _dynamic_initializer_for__vprof_dump_spikes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes,
    pName: "vprof_dump_spikes",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Framerate at which vprof will begin to dump spikes to the console. 0 = disabled, negative to reset after dump");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E510
// Name: _dynamic_initializer_for__vprof_dump_spikes_terse__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes_terse__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes_terse,
    pName: "vprof_dump_spikes_terse",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Whether to use most terse output");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes_terse__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E540
// Name: _dynamic_initializer_for__vprof_dump_spikes_hierarchy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes_hierarchy__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes_hierarchy,
    pName: "vprof_dump_spikes_hiearchy",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to 1 to get a hierarchy report whith vprof_dump_spikes");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes_hierarchy__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E570
// Name: _dynamic_initializer_for__vprof_dump_spikes_node__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes_node__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes_node,
    pName: "vprof_dump_spikes_node",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Node to start report from when doing a dump spikes");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes_node__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E5A0
// Name: _dynamic_initializer_for__vprof_dump_spikes_budget_group__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes_budget_group__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes_budget_group,
    pName: "vprof_dump_spikes_budget_group",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Budget gtNode to start report from when doing a dump spikes");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes_budget_group__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E5D0
// Name: _dynamic_initializer_for__vprof_dump_oninterval__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_oninterval__()
{
  ConVar::ConVar(
    this: &vprof_dump_oninterval,
    pName: "vprof_dump_oninterval",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Interval (in seconds) at which vprof will batch up data and dump it to the console.");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_oninterval__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E610
// Name: _dynamic_initializer_for__vprof_counters__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_counters__()
{
  ConVar::ConVar(this: &vprof_counters, pName: "vprof_counters", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_counters__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E640
// Name: _dynamic_initializer_for__vprof_counters_show_minmax__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_counters_show_minmax__()
{
  ConVar::ConVar(this: &vprof_counters_show_minmax, pName: "vprof_counters_show_minmax", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_counters_show_minmax__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E670
// Name: _dynamic_initializer_for__vprof_dump_counters_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_counters_command__()
{
  ConCommand::ConCommand(
    this: &vprof_dump_counters_command,
    pName: "vprof_dump_counters",
    callback: vprof_dump_counters,
    pHelpString: "Dump vprof counters to the console",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_counters_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E6D0
// Name: _dynamic_initializer_for__vprof_vtune_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_vtune_group_command__()
{
  ConCommand::ConCommand(
    this: &vprof_vtune_group_command,
    pName: "vprof_vtune_group",
    callback: (void (__cdecl *)())vprof_vtune_group,
    pHelpString: "enable vtune for a particular vprof group (\"disable\" to disable)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_vtune_group_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E700
// Name: _dynamic_initializer_for__vprof_dump_groupnames_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_groupnames_command__()
{
  ConCommand::ConCommand(
    this: &vprof_dump_groupnames_command,
    pName: "vprof_dump_groupnames",
    callback: vprof_dump_groupnames,
    pHelpString: "Write the names of all of the vprof groups to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_groupnames_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E730
// Name: _dynamic_initializer_for__vprof_cachemiss_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_cachemiss_command__()
{
  ConCommand::ConCommand(
    this: &vprof_cachemiss_command,
    pName: "vprof_cachemiss",
    callback: (void (__cdecl *)())vprof_cachemiss,
    pHelpString: "Toggle VProf cache miss checking",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_cachemiss_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E760
// Name: _dynamic_initializer_for__vprof_cachemiss_on_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_cachemiss_on_command__()
{
  ConCommand::ConCommand(
    this: &vprof_cachemiss_on_command,
    pName: "vprof_cachemiss_on",
    callback: (void (__cdecl *)())vprof_cachemiss_on,
    pHelpString: "Turn on VProf cache miss checking",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_cachemiss_on_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E790
// Name: _dynamic_initializer_for__vprof_cachemiss_off_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_cachemiss_off_command__()
{
  ConCommand::ConCommand(
    this: &vprof_cachemiss_off_command,
    pName: "vprof_cachemiss_off",
    callback: (void (__cdecl *)())vprof_cachemiss_off,
    pHelpString: "Turn off VProf cache miss checking",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_cachemiss_off_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E7C0
// Name: _dynamic_initializer_for__vprof_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_command__()
{
  ConCommand::ConCommand(
    this: &vprof_command,
    pName: "vprof",
    callback: (void (__cdecl *)())vprof,
    pHelpString: "Toggle VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E7F0
// Name: _dynamic_initializer_for__vprof_on_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_on_command__()
{
  ConCommand::ConCommand(
    this: &vprof_on_command,
    pName: "vprof_on",
    callback: (void (__cdecl *)())vprof_on,
    pHelpString: "Turn on VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_on_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E850
// Name: _dynamic_initializer_for__vprof_off_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_off_command__()
{
  ConCommand::ConCommand(
    this: &vprof_off_command,
    pName: "vprof_off",
    callback: (void (__cdecl *)())vprof_off,
    pHelpString: "Turn off VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_off_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E880
// Name: _dynamic_initializer_for__vprof_reset_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_reset_command__()
{
  ConCommand::ConCommand(
    this: &vprof_reset_command,
    pName: "vprof_reset",
    callback: (void (__cdecl *)())vprof_reset,
    pHelpString: "Reset the stats in VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_reset_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E8B0
// Name: _dynamic_initializer_for__vprof_reset_peaks_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_reset_peaks_command__()
{
  ConCommand::ConCommand(
    this: &vprof_reset_peaks_command,
    pName: "vprof_reset_peaks",
    callback: (void (__cdecl *)())vprof_reset_peaks,
    pHelpString: "Reset just the peak time in VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_reset_peaks_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E8E0
// Name: _dynamic_initializer_for__vprof_generate_report_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_command,
    pName: "vprof_generate_report",
    callback: (void (__cdecl *)())vprof_generate_report,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E910
// Name: _dynamic_initializer_for__vprof_generate_report_budget_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_budget_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_budget_command,
    pName: "vprof_generate_report_budget",
    callback: (void (__cdecl *)())vprof_generate_report_budget,
    pHelpString: "Generate a report to the console based on budget group.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_budget_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E940
// Name: _dynamic_initializer_for__vprof_generate_report_hierarchy_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_hierarchy_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_hierarchy_command,
    pName: "vprof_generate_report_hierarchy",
    callback: (void (__cdecl *)())vprof_generate_report_hierarchy,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E970
// Name: _dynamic_initializer_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_hierarchy_per_frame_and_count_only_command,
    pName: "vprof_generate_report_hierarchy_per_frame_and_count_only",
    callback: (void (__cdecl *)())vprof_generate_report_hierarchy_per_frame_and_count_only,
    pHelpString: "Generate a minimal hiearchical report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E9A0
// Name: _dynamic_initializer_for__vprof_generate_report_AI_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_AI_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_AI_command,
    pName: "vprof_generate_report_AI",
    callback: (void (__cdecl *)())vprof_generate_report_AI,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_AI_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E9D0
// Name: _dynamic_initializer_for__vprof_generate_report_AI_only_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_AI_only_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_AI_only_command,
    pName: "vprof_generate_report_AI_only",
    callback: (void (__cdecl *)())vprof_generate_report_AI_only,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_AI_only_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA00
// Name: _dynamic_initializer_for__vprof_generate_report_map_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_map_load_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_map_load_command,
    pName: "vprof_generate_report_map_load",
    callback: (void (__cdecl *)())vprof_generate_report_map_load,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_map_load_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EAD0
// Name: _dynamic_initializer_for__vprof_record_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_record_start_command__()
{
  ConCommand::ConCommand(
    this: &vprof_record_start_command,
    pName: "vprof_record_start",
    callback: (void (__cdecl *)())vprof_record_start,
    pHelpString: "Start recording vprof data for playback later.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_record_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB00
// Name: _dynamic_initializer_for__vprof_record_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_record_stop_command__()
{
  ConCommand::ConCommand(
    this: &vprof_record_stop_command,
    pName: "vprof_record_stop",
    callback: vprof_record_stop,
    pHelpString: "Stop recording vprof data",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_record_stop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB30
// Name: _dynamic_initializer_for__vprof_to_csv_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_to_csv_command__()
{
  ConCommand::ConCommand(
    this: &vprof_to_csv_command,
    pName: "vprof_to_csv",
    callback: (void (__cdecl *)())vprof_to_csv,
    pHelpString: "Convert a recorded .vprof file to .csv.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_to_csv_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB60
// Name: _dynamic_initializer_for__vprof_playback_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_start_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_start_command,
    pName: "vprof_playback_start",
    callback: (void (__cdecl *)())vprof_playback_start,
    pHelpString: "Start playing back a recorded .vprof file.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB90
// Name: _dynamic_initializer_for__vprof_playback_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_stop_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_stop_command,
    pName: "vprof_playback_stop",
    callback: vprof_playback_stop,
    pHelpString: "Stop playing back a recorded .vprof file.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_stop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EBC0
// Name: _dynamic_initializer_for__vprof_playback_step_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_step_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_step_command,
    pName: "vprof_playback_step",
    callback: VProfPlayback_Step,
    pHelpString: "While playing back a .vprof file, step to the next tick.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_step_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EBF0
// Name: _dynamic_initializer_for__vprof_playback_stepback_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_stepback_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_stepback_command,
    pName: "vprof_playback_stepback",
    callback: VProfPlayback_StepBack,
    pHelpString: "While playing back a .vprof file, step to the previous tick.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_stepback_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EC20
// Name: _dynamic_initializer_for__vprof_playback_average_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_average_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_average_command,
    pName: "vprof_playback_average",
    callback: (void (__cdecl *)())vprof_playback_average,
    pHelpString: "Average the next N frames.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_average_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F430
// Name: _dynamic_initializer_for__vprof_adddebuggroup1_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_adddebuggroup1_command__()
{
  ConCommand::ConCommand(
    this: &vprof_adddebuggroup1_command,
    pName: "vprof_adddebuggroup1",
    callback: vprof_adddebuggroup1,
    pHelpString: "add a new budget group dynamically for debugging",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_adddebuggroup1_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FD70
// Name: _dynamic_initializer_for__vprof_graph__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_graph__()
{
  ConVar::ConVar(
    this: &vprof_graph,
    pName: "vprof_graph",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw the vprof graph.");
  return atexit(func: dynamic_atexit_destructor_for__vprof_graph__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FDA0
// Name: _dynamic_initializer_for__vprof_graphwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_graphwidth__()
{
  ConVar::ConVar(this: &vprof_graphwidth, pName: "vprof_graphwidth", pDefaultValue: "512", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__vprof_graphwidth__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FDD0
// Name: _dynamic_initializer_for__vprof_graphheight__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_graphheight__()
{
  ConVar::ConVar(this: &vprof_graphheight, pName: "vprof_graphheight", pDefaultValue: "256", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__vprof_graphheight__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FE00
// Name: _dynamic_initializer_for__vprof_siblingprev__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_siblingprev__()
{
  ConCommand::ConCommand(
    this: &vprof_siblingprev,
    pName: "vprof_prevsibling",
    callback: IN_VProfPrevSibling,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_siblingprev__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FE30
// Name: _dynamic_initializer_for__vprof_siblingnext__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_siblingnext__()
{
  ConCommand::ConCommand(
    this: &vprof_siblingnext,
    pName: "vprof_nextsibling",
    callback: IN_VProfNextSibling,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_siblingnext__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FE60
// Name: _dynamic_initializer_for__vprof_parent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_parent__()
{
  ConCommand::ConCommand(
    this: &vprof_parent,
    pName: "vprof_parent",
    callback: IN_VProfParent,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_parent__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FE90
// Name: _dynamic_initializer_for__vprof_child__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_child__()
{
  ConCommand::ConCommand(
    this: &vprof_child,
    pName: "vprof_child",
    callback: IN_VProfChild,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_child__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FEC0
// Name: _dynamic_initializer_for__vprof_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_verbose__()
{
  ConVar::ConVar(
    this: &vprof_verbose,
    pName: "vprof_verbose",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Set to one to show average and peak times");
  return atexit(func: dynamic_atexit_destructor_for__vprof_verbose__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FEF0
// Name: _dynamic_initializer_for__vprof_unaccounted_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_unaccounted_limit__()
{
  ConVar::ConVar(
    this: &vprof_unaccounted_limit,
    pName: "vprof_unaccounted_limit",
    pDefaultValue: "0.3",
    flags: 128,
    pHelpString: "number of milliseconds that a node must exceed to turn red in the vprof panel");
  return atexit(func: dynamic_atexit_destructor_for__vprof_unaccounted_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FF20
// Name: _dynamic_initializer_for__vprof_warningmsec__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_warningmsec__()
{
  ConVar::ConVar(
    this: &vprof_warningmsec,
    pName: "vprof_warningmsec",
    pDefaultValue: "10",
    flags: 128,
    pHelpString: "Above this many milliseconds render the label red to indicate slow code.");
  return atexit(func: dynamic_atexit_destructor_for__vprof_warningmsec__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FF50
// Name: _dynamic_initializer_for__vprof_expand_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_expand_all_command__()
{
  ConCommand::ConCommand(
    this: &vprof_expand_all_command,
    pName: "vprof_expand_all",
    callback: vprof_expand_all,
    pHelpString: "Expand the whole vprof tree",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_expand_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FF80
// Name: _dynamic_initializer_for__vprof_collapse_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_collapse_all_command__()
{
  ConCommand::ConCommand(
    this: &vprof_collapse_all_command,
    pName: "vprof_collapse_all",
    callback: vprof_collapse_all,
    pHelpString: "Collapse the whole vprof tree",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_collapse_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FFB0
// Name: _dynamic_initializer_for__vprof_expand_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_expand_group_command__()
{
  ConCommand::ConCommand(
    this: &vprof_expand_group_command,
    pName: "vprof_expand_group",
    callback: (void (__cdecl *)())vprof_expand_group,
    pHelpString: "Expand a budget group in the vprof tree by name",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_expand_group_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10320040
// Name: _dynamic_initializer_for__vprof_scope__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_scope__()
{
  ConVar::ConVar(
    this: &vprof_scope,
    pName: "vprof_scope",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Set a specific scope to start showing vprof tree",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))ChangeVProfScopeCallback);
  return atexit(func: dynamic_atexit_destructor_for__vprof_scope__);
}

//------------------------------------------------------------------------------
// Address: 0x10322900
// Name: _dynamic_atexit_destructor_for__vprof_remote_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_remote_start_command__()
{
  ConCommand::~ConCommand(this: &vprof_remote_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322910
// Name: _dynamic_atexit_destructor_for__vprof_remote_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_remote_stop_command__()
{
  ConCommand::~ConCommand(this: &vprof_remote_stop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325590
// Name: _dynamic_atexit_destructor_for__vprof_server_spike_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_server_spike_threshold__()
{
  ConVar::~ConVar(this: &vprof_server_spike_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x103255A0
// Name: _dynamic_atexit_destructor_for__vprof_server_thread__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_server_thread__()
{
  ConVar::~ConVar(this: &vprof_server_thread);
}

//------------------------------------------------------------------------------
// Address: 0x10326D80
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes);
}

//------------------------------------------------------------------------------
// Address: 0x10326D90
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes_terse__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes_terse__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes_terse);
}

//------------------------------------------------------------------------------
// Address: 0x10326DA0
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes_hierarchy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes_hierarchy__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes_hierarchy);
}

//------------------------------------------------------------------------------
// Address: 0x10326DB0
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes_node__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes_node__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes_node);
}

//------------------------------------------------------------------------------
// Address: 0x10326DC0
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes_budget_group__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes_budget_group__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes_budget_group);
}

//------------------------------------------------------------------------------
// Address: 0x10326DD0
// Name: _dynamic_atexit_destructor_for__vprof_dump_oninterval__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_oninterval__()
{
  ConVar::~ConVar(this: &vprof_dump_oninterval);
}

//------------------------------------------------------------------------------
// Address: 0x10326DE0
// Name: _dynamic_atexit_destructor_for__vprof_counters__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_counters__()
{
  ConVar::~ConVar(this: &vprof_counters);
}

//------------------------------------------------------------------------------
// Address: 0x10326DF0
// Name: _dynamic_atexit_destructor_for__vprof_counters_show_minmax__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_counters_show_minmax__()
{
  ConVar::~ConVar(this: &vprof_counters_show_minmax);
}

//------------------------------------------------------------------------------
// Address: 0x10326E00
// Name: _dynamic_atexit_destructor_for__vprof_dump_counters_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_counters_command__()
{
  ConCommand::~ConCommand(this: &vprof_dump_counters_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326E20
// Name: _dynamic_atexit_destructor_for__vprof_vtune_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_vtune_group_command__()
{
  ConCommand::~ConCommand(this: &vprof_vtune_group_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326E30
// Name: _dynamic_atexit_destructor_for__vprof_dump_groupnames_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_groupnames_command__()
{
  ConCommand::~ConCommand(this: &vprof_dump_groupnames_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326E40
// Name: _dynamic_atexit_destructor_for__vprof_cachemiss_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_cachemiss_command__()
{
  ConCommand::~ConCommand(this: &vprof_cachemiss_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326E50
// Name: _dynamic_atexit_destructor_for__vprof_cachemiss_on_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_cachemiss_on_command__()
{
  ConCommand::~ConCommand(this: &vprof_cachemiss_on_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326E60
// Name: _dynamic_atexit_destructor_for__vprof_cachemiss_off_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_cachemiss_off_command__()
{
  ConCommand::~ConCommand(this: &vprof_cachemiss_off_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326E70
// Name: _dynamic_atexit_destructor_for__vprof_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_command__()
{
  ConCommand::~ConCommand(this: &vprof_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326E80
// Name: _dynamic_atexit_destructor_for__vprof_on_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_on_command__()
{
  ConCommand::~ConCommand(this: &vprof_on_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EA0
// Name: _dynamic_atexit_destructor_for__vprof_off_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_off_command__()
{
  ConCommand::~ConCommand(this: &vprof_off_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EB0
// Name: _dynamic_atexit_destructor_for__vprof_reset_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_reset_command__()
{
  ConCommand::~ConCommand(this: &vprof_reset_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EC0
// Name: _dynamic_atexit_destructor_for__vprof_reset_peaks_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_reset_peaks_command__()
{
  ConCommand::~ConCommand(this: &vprof_reset_peaks_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326ED0
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EE0
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_budget_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_budget_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_budget_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EF0
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_hierarchy_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F00
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_hierarchy_per_frame_and_count_only_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F10
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_AI_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_AI_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_AI_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F20
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_AI_only_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_AI_only_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_AI_only_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F30
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_map_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_map_load_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_map_load_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326FD0
// Name: _dynamic_atexit_destructor_for__vprof_record_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_record_start_command__()
{
  ConCommand::~ConCommand(this: &vprof_record_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326FE0
// Name: _dynamic_atexit_destructor_for__vprof_record_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_record_stop_command__()
{
  ConCommand::~ConCommand(this: &vprof_record_stop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326FF0
// Name: _dynamic_atexit_destructor_for__vprof_to_csv_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_to_csv_command__()
{
  ConCommand::~ConCommand(this: &vprof_to_csv_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327000
// Name: _dynamic_atexit_destructor_for__vprof_playback_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_start_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327010
// Name: _dynamic_atexit_destructor_for__vprof_playback_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_stop_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_stop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327020
// Name: _dynamic_atexit_destructor_for__vprof_playback_step_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_step_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_step_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327030
// Name: _dynamic_atexit_destructor_for__vprof_playback_stepback_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_stepback_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_stepback_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327040
// Name: _dynamic_atexit_destructor_for__vprof_playback_average_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_average_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_average_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327370
// Name: _dynamic_atexit_destructor_for__vprof_adddebuggroup1_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_adddebuggroup1_command__()
{
  ConCommand::~ConCommand(this: &vprof_adddebuggroup1_command);
}

//------------------------------------------------------------------------------
// Address: 0x103275E0
// Name: _dynamic_atexit_destructor_for__vprof_graph__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_graph__()
{
  ConVar::~ConVar(this: &vprof_graph);
}

//------------------------------------------------------------------------------
// Address: 0x103275F0
// Name: _dynamic_atexit_destructor_for__vprof_graphwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_graphwidth__()
{
  ConVar::~ConVar(this: &vprof_graphwidth);
}

//------------------------------------------------------------------------------
// Address: 0x10327600
// Name: _dynamic_atexit_destructor_for__vprof_graphheight__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_graphheight__()
{
  ConVar::~ConVar(this: &vprof_graphheight);
}

//------------------------------------------------------------------------------
// Address: 0x10327610
// Name: _dynamic_atexit_destructor_for__vprof_siblingprev__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_siblingprev__()
{
  ConCommand::~ConCommand(this: &vprof_siblingprev);
}

//------------------------------------------------------------------------------
// Address: 0x10327620
// Name: _dynamic_atexit_destructor_for__vprof_siblingnext__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_siblingnext__()
{
  ConCommand::~ConCommand(this: &vprof_siblingnext);
}

//------------------------------------------------------------------------------
// Address: 0x10327630
// Name: _dynamic_atexit_destructor_for__vprof_parent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_parent__()
{
  ConCommand::~ConCommand(this: &vprof_parent);
}

//------------------------------------------------------------------------------
// Address: 0x10327640
// Name: _dynamic_atexit_destructor_for__vprof_child__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_child__()
{
  ConCommand::~ConCommand(this: &vprof_child);
}

//------------------------------------------------------------------------------
// Address: 0x10327650
// Name: _dynamic_atexit_destructor_for__vprof_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_verbose__()
{
  ConVar::~ConVar(this: &vprof_verbose);
}

//------------------------------------------------------------------------------
// Address: 0x10327660
// Name: _dynamic_atexit_destructor_for__vprof_unaccounted_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_unaccounted_limit__()
{
  ConVar::~ConVar(this: &vprof_unaccounted_limit);
}

//------------------------------------------------------------------------------
// Address: 0x10327670
// Name: _dynamic_atexit_destructor_for__vprof_warningmsec__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_warningmsec__()
{
  ConVar::~ConVar(this: &vprof_warningmsec);
}

//------------------------------------------------------------------------------
// Address: 0x10327680
// Name: _dynamic_atexit_destructor_for__vprof_expand_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_expand_all_command__()
{
  ConCommand::~ConCommand(this: &vprof_expand_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327690
// Name: _dynamic_atexit_destructor_for__vprof_collapse_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_collapse_all_command__()
{
  ConCommand::~ConCommand(this: &vprof_collapse_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x103276A0
// Name: _dynamic_atexit_destructor_for__vprof_expand_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_expand_group_command__()
{
  ConCommand::~ConCommand(this: &vprof_expand_group_command);
}

//------------------------------------------------------------------------------
// Address: 0x103276D0
// Name: _dynamic_atexit_destructor_for__vprof_scope__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_scope__()
{
  ConVar::~ConVar(this: &vprof_scope);
}

//------------------------------------------------------------------------------
// Address: 0x10313B00
// Name: _dynamic_initializer_for__rpt_screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rpt_screenshot_command__()
{
  ConCommand::ConCommand(
    this: &rpt_screenshot_command,
    pName: "rpt_screenshot",
    callback: rpt_screenshot,
    pHelpString: defaultValue,
    flags: 131088,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rpt_screenshot_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313B30
// Name: _dynamic_initializer_for__rpt_download_log_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rpt_download_log_command__()
{
  ConCommand::ConCommand(
    this: &rpt_download_log_command,
    pName: "rpt_download_log",
    callback: rpt_download_log,
    pHelpString: defaultValue,
    flags: 131088,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rpt_download_log_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A8C0
// Name: _dynamic_initializer_for__g_MainThreadId__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD dynamic_initializer_for__g_MainThreadId__()
{
  DWORD result; // eax

  result = GetCurrentThreadId();
  g_MainThreadId = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031E600
// Name: _dynamic_initializer_for__g_VProfTargetThread__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD dynamic_initializer_for__g_VProfTargetThread__()
{
  DWORD result; // eax

  result = GetCurrentThreadId();
  g_VProfTargetThread = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031E6A0
// Name: _dynamic_initializer_for__spike_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__spike_command__()
{
  ConCommand::ConCommand(
    this: &spike_command,
    pName: "spike",
    callback: spike,
    pHelpString: "generates a fake spike",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__spike_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA30
// Name: _dynamic_initializer_for__g_VProfExport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VProfExport__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VProfExport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA40
// Name: _dynamic_initializer_for____g_CreateCVProfExportIVProfExport_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVProfExportIVProfExport_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVProfExportIVProfExport_reg,
           fn: (void *(__cdecl *)())_CreateCVProfExportIVProfExport_interface,
           pName: "VProfExport001");
}

//------------------------------------------------------------------------------
// Address: 0x1031F460
// Name: _dynamic_initializer_for__startshowbudget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startshowbudget__()
{
  ConCommand::ConCommand(
    this: &startshowbudget,
    pName: "+showbudget",
    callback: (void (__cdecl *)())IN_BudgetDown,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startshowbudget__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F490
// Name: _dynamic_initializer_for__endshowbudget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endshowbudget__()
{
  ConCommand::ConCommand(
    this: &endshowbudget,
    pName: "-showbudget",
    callback: (void (__cdecl *)())IN_BudgetUp,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endshowbudget__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FFE0
// Name: _dynamic_initializer_for__startshowvprof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startshowvprof__()
{
  ConCommand::ConCommand(
    this: &startshowvprof,
    pName: "+showvprof",
    callback: IN_VProfDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startshowvprof__);
}

//------------------------------------------------------------------------------
// Address: 0x10320010
// Name: _dynamic_initializer_for__endshowvprof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endshowvprof__()
{
  ConCommand::ConCommand(
    this: &endshowvprof,
    pName: "-showvprof",
    callback: IN_VProfUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endshowvprof__);
}

//------------------------------------------------------------------------------
// Address: 0x10322920
// Name: _dynamic_atexit_destructor_for__rpt_screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rpt_screenshot_command__()
{
  ConCommand::~ConCommand(this: &rpt_screenshot_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322930
// Name: _dynamic_atexit_destructor_for__rpt_download_log_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rpt_download_log_command__()
{
  ConCommand::~ConCommand(this: &rpt_download_log_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326E10
// Name: _dynamic_atexit_destructor_for__spike_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spike_command__()
{
  ConCommand::~ConCommand(this: &spike_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F40
// Name: _dynamic_atexit_destructor_for__rpt_vprof_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rpt_vprof_time__()
{
  ConVar::~ConVar(this: &rpt_vprof_time);
}

//------------------------------------------------------------------------------
// Address: 0x10327050
// Name: _dynamic_atexit_destructor_for__g_VProfRecorder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VProfRecorder__()
{
  CUtlDict<int,int>::RemoveAll(this: &g_VProfRecorder.m_PooledStrings);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &g_VProfRecorder.m_PooledStrings.m_Elements.m_Tree);
  CVProfile::~CVProfile(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x10327380
// Name: _dynamic_atexit_destructor_for__startshowbudget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startshowbudget__()
{
  ConCommand::~ConCommand(this: &startshowbudget);
}

//------------------------------------------------------------------------------
// Address: 0x10327390
// Name: _dynamic_atexit_destructor_for__endshowbudget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endshowbudget__()
{
  ConCommand::~ConCommand(this: &endshowbudget);
}

//------------------------------------------------------------------------------
// Address: 0x103276B0
// Name: _dynamic_atexit_destructor_for__startshowvprof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startshowvprof__()
{
  ConCommand::~ConCommand(this: &startshowvprof);
}

//------------------------------------------------------------------------------
// Address: 0x103276C0
// Name: _dynamic_atexit_destructor_for__endshowvprof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endshowvprof__()
{
  ConCommand::~ConCommand(this: &endshowvprof);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10084100
// Name: public: virtual void CVProfGraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfGraphPanel::ApplySchemeSettings(CEntityReportPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020D7B0
// Name: void IN_VProfNextSibling(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_VProfNextSibling()
{
  CVProfNode *Sibling; // eax

  Sibling = CVProfNode::GetSibling(this: CVProfGraphPanel::m_CurrentNode);
  if ( Sibling != nullptr )
    CVProfGraphPanel::m_CurrentNode = Sibling;
}

//------------------------------------------------------------------------------
// Address: 0x1020D850
// Name: public: virtual void CVProfGraphPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfGraphPanel::OnTick(CBasePanel *this)
{
  CBasePanel_vtbl *v2; // edi
  bool v3; // al

  v2 = this->__vftable;
  v3 = this->ShouldDraw(this);
  v2->SetVisible(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1020D870
// Name: private: void CVProfGraphPanel::GetNextSample(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfGraphPanel::GetNextSample(CVProfGraphPanel *this)
{
  struct CVProfNode *Parent; // eax
  CVProfNode *v3; // ecx
  CVProfNode *Root; // eax

  this->m_CurrentSample = (this->m_CurrentSample + 1) % 256;
  this->m_Samples[this->m_CurrentSample][0] = CVProfNode::GetPrevTime(this: CVProfGraphPanel::m_CurrentNode);
  Parent = CVProfNode::GetParent(this: CVProfGraphPanel::m_CurrentNode);
  v3 = CVProfGraphPanel::m_CurrentNode;
  if ( Parent != nullptr )
    v3 = CVProfNode::GetParent(this: CVProfGraphPanel::m_CurrentNode);
  this->m_Samples[this->m_CurrentSample][1] = CVProfNode::GetPrevTime(this: v3);
  Root = CVProfile::GetRoot(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  this->m_Samples[this->m_CurrentSample][2] = CVProfNode::GetPrevTime(this: Root);
}

//------------------------------------------------------------------------------
// Address: 0x1020D910
// Name: void DestroyVProfGraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyVProfGraphPanel()
{
  if ( s_pVProfGraphPanel != nullptr )
  {
    s_pVProfGraphPanel->SetParent_2(this: s_pVProfGraphPanel, a2: nullptr);
    if ( s_pVProfGraphPanel != nullptr )
      ((void (__thiscall *)(CVProfGraphPanel *, int))s_pVProfGraphPanel->dtr_Panel)(a1: s_pVProfGraphPanel, a2: 1);
    s_pVProfGraphPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D950
// Name: void HideVProfGraphPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HideVProfGraphPanel()
{
  if ( s_pVProfGraphPanel != nullptr )
    s_pVProfGraphPanel->SetVisible(this: s_pVProfGraphPanel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020D970
// Name: public: CVProfGraphPanel::CVProfGraphPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CVProfGraphPanel *__thiscall CVProfGraphPanel::CVProfGraphPanel(CVProfGraphPanel *this, unsigned int parent)
{
  int v3; // eax
  int v5; // [esp-4h] [ebp-10h]

  vgui::Panel::Panel(this, parent: nullptr, panelName: "CVProfGraphPanel");
  this->__vftable = (CVProfGraphPanel_vtbl *)&CVProfGraphPanel::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_WhiteMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  vgui::Panel::SetParent(this, newParent: parent);
  v5 = videomode->GetModeHeight(this: videomode);
  v3 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetSize(this, wide: v3, tall: v5);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Panel::SetCursor(this, cursor: 0);
  this->m_hFont = 0;
  CBaseDemoAction::SetTimingType(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  memset(dst: (unsigned __int8 *)this->m_Samples, value: 0, count: sizeof(this->m_Samples));
  this->m_CurrentSample = 0;
  CVProfGraphPanel::m_CurrentNode = CVProfile::GetRoot(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  if ( CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode) != nullptr )
  {
    CVProfGraphPanel::m_CurrentNode = CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode);
    if ( CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode) != nullptr )
      CVProfGraphPanel::m_CurrentNode = CVProfNode::GetChild(this: CVProfGraphPanel::m_CurrentNode);
  }
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  CMaterialReference::Init(
    this: &this->m_WhiteMaterial,
    pMaterialName: "vgui/white",
    pTextureGroupName: "Other textures",
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020DAE0
// Name: void CreateVProfGraphPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateVProfGraphPanel(vgui::Panel *pParent)
{
  CVProfGraphPanel *v1; // esi
  unsigned int v2; // eax

  v1 = (CVProfGraphPanel *)MemAlloc_Alloc(nSize: 0xD5Cu);
  if ( v1 != nullptr )
  {
    v2 = pParent->GetVPanel(this: pParent);
    s_pVProfGraphPanel = CVProfGraphPanel::CVProfGraphPanel(this: v1, parent: v2);
  }
  else
  {
    s_pVProfGraphPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020DB20
// Name: public: virtual bool CVProfGraphPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVProfGraphPanel::ShouldDraw(CVProfGraphPanel *this)
{
  return vprof_graph.m_pParent != nullptr && vprof_graph.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020DB40
// Name: private: void CVProfGraphPanel::PaintLineArt(int,int,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CVProfGraphPanel::PaintLineArt(
        CVProfGraphPanel *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        int x,
        int y,
        int w)
{
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  IMesh *v9; // edi
  int v11; // esi
  int v12; // esi
  int v13; // edi
  float v14; // xmm1_4
  float *v15; // ecx
  float *m_pCurrPosition; // ecx
  float *v17; // eax
  float *v18; // eax
  float v19; // xmm0_4
  unsigned __int8 *v20; // ecx
  int m_CurrentSample; // eax
  int v22; // edi
  int v23; // esi
  int v24; // ecx
  __m128i v25; // xmm1
  float v26; // xmm1_4
  int v27; // eax
  float *v28; // ecx
  float *v29; // ecx
  float v30; // xmm1_4
  float v31; // xmm1_4
  float *v32; // eax
  float *v33; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-220h] BYREF
  IMesh *m_pMesh; // [esp+1E8h] [ebp-38h]
  float v39; // [esp+1ECh] [ebp-34h]
  float v40; // [esp+1F0h] [ebp-30h]
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-2Ch]
  float flMsToPixel; // [esp+1F8h] [ebp-28h]
  CVProfGraphPanel *v43; // [esp+1FCh] [ebp-24h]
  float v44; // [esp+200h] [ebp-20h]
  unsigned __int8 *v45; // [esp+204h] [ebp-1Ch]
  float flDxDSample; // [esp+208h] [ebp-18h]
  int i; // [esp+20Ch] [ebp-14h]
  unsigned __int8 color[3][4]; // [esp+210h] [ebp-10h] BYREF
  int nPanelHeight; // [esp+21Ch] [ebp-4h]
  unsigned int xa; // [esp+228h] [ebp+8h]
  float sample; // [esp+230h] [ebp+10h]
  int samplea; // [esp+230h] [ebp+10h]

  nPanelHeight = (int)(float)((float)(vprof_graphheight.m_pParent->m_Value.m_fValue - 24.0) - 2.0);
  v43 = this;
  CVProfGraphPanel::GetNextSample(this);
  v7 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                              a1: materials,
                              a2,
                              a3);
  v8 = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v9 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: this->m_WhiteMaterial.m_pMaterial);
  m_pMesh = v9;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v9;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v11 = 2 * (3 * w + 4);
  v9->SetPrimitiveType(this: v9, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v11, a3: v11, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v9, nMaxVertexCount: v11, desc: &meshBuilder);
  v12 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v13 = nPanelHeight / 3;
  v44 = (float)x;
  sample = (float)(w + x);
  do
  {
    v14 = v44;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12 != 0 ? -8355712 : -1;
    v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v15[1] = 0.0;
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    m_pCurrPosition[1] = (float)(y - v12 * v13);
    m_pCurrPosition[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12 != 0 ? -8355712 : -1;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v17[1] = 0.0;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = sample;
    v18[1] = (float)(y - v12 * v13);
    v18[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v12;
  }
  while ( v12 < 4 );
  *(_DWORD *)&color[0][0] = -16776961;
  *(_DWORD *)&color[1][0] = -65536;
  *(_DWORD *)&color[2][0] = -1;
  flMsToPixel = (float)nPanelHeight * 0.02;
  if ( w > 256 )
    v19 = (float)w * 0.00390625;
  else
    v19 = 1.0;
  v20 = &color[2][1];
  flDxDSample = v19;
  i = 2;
  v45 = &color[2][1];
  do
  {
    m_CurrentSample = v43->m_CurrentSample;
    samplea = m_CurrentSample;
    v22 = w;
    if ( w >= 0 )
    {
      v23 = v20[1] | ((*v20 | ((*(v20 - 1) | (v20[2] << 8)) << 8)) << 8);
      xa = -1;
      while ( 1 )
      {
        v24 = (int)(float)((float)(v43->m_Samples[0][2 * m_CurrentSample + m_CurrentSample + i] * flMsToPixel) + 0.5);
        v25 = _mm_cvtsi32_si128(xa);
        if ( v24 > nPanelHeight )
          v24 = nPanelHeight;
        v26 = (float)(_mm_cvtepi32_ps(v25).m128_f32[0] * flDxDSample) + v44;
        v27 = y - v24;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v28[1] = 0.0;
        v29 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v30 = (float)(int)(float)(v26 + 0.5);
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v30;
        v39 = v30;
        v29[1] = (float)v27;
        v29[2] = 0.0;
        v40 = (float)v27;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( v22 != w && v22 != 0 )
        {
          v31 = v39;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
          v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
          v32[1] = 0.0;
          v33 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v31;
          v33[1] = v40;
          v33[2] = 0.0;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        }
        if ( --samplea < 0 )
          samplea = 255;
        ++xa;
        if ( --v22 < 0 )
          break;
        m_CurrentSample = samplea;
      }
      v20 = v45;
    }
    v20 -= 4;
    --i;
    v45 = v20;
  }
  while ( i >= 0 );
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
  m_pMesh->Draw_2(this: m_pMesh, a2: -1, a3: 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1020E030
// Name: public: virtual void CVProfGraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CVProfGraphPanel::Paint(CVProfGraphPanel *this)
{
  int v2; // esi
  int v3; // eax
  int m_nValue; // edi
  int v5; // esi
  int v6; // eax
  CVProfNode *Root; // eax
  const char *Name; // eax
  int v9; // esi
  unsigned __int8 *v10; // edi
  double v11; // [esp+4h] [ebp-138h]
  char sz[256]; // [esp+18h] [ebp-124h] BYREF
  const char *pTitles[3]; // [esp+118h] [ebp-24h]
  double PrevTime; // [esp+124h] [ebp-18h] OVERLAPPED
  unsigned __int8 color[3][3]; // [esp+12Ch] [ebp-10h] BYREF
  int y; // [esp+138h] [ebp-4h]

  if ( this->ShouldDraw(this) )
  {
    v2 = videomode->GetModeWidth(this: videomode);
    v3 = videomode->GetModeHeight(this: videomode);
    if ( vprof_graphwidth.m_pParent != nullptr )
      m_nValue = vprof_graphwidth.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( v2 < m_nValue + 10 )
      m_nValue = v2 - 10;
    v5 = v2 - m_nValue - 5;
    y = v3 - 29;
    CVProfGraphPanel::PaintLineArt(this, a2: m_nValue, a3: v5, x: v5, y: v3 - 29, w: m_nValue);
    if ( vprof_graphheight.m_pParent != nullptr )
      v6 = vprof_graphheight.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    y -= v6;
    Root = CVProfile::GetRoot(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    PrevTime = CVProfNode::GetPrevTime(this: Root);
    if ( g_ClientGlobalVariables.absoluteframetime > 0.0 )
    {
      v11 = CVProfNode::GetPrevTime(this: CVProfGraphPanel::m_CurrentNode) / PrevTime * 100.0;
      Name = CVProfNode::GetName(this: CVProfGraphPanel::m_CurrentNode);
      V_snprintf(pDest: sz, maxLen: 256, pFormat: "%s - %0.1f%%%%", Name, v11);
      g_pMatSystemSurface->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: this->m_hFont,
        a3: v5,
        a4: y,
        a5: 229,
        a6: 229,
        a7: 178,
        a8: 255,
        a9: sz);
    }
    *(_QWORD *)&color[0][0] = 0xFFFFFF00000000FFuLL;
    color[2][2] = -1;
    pTitles[0] = CVProfNode::GetName(this: CVProfGraphPanel::m_CurrentNode);
    HIDWORD(PrevTime) = m_nValue / 2 + v5;
    pTitles[1] = "Parent";
    pTitles[2] = "Total";
    v9 = 2;
    v10 = &color[2][1];
    do
    {
      V_snprintf(
        pDest: sz,
        maxLen: 256,
        pFormat: "%07.3f ms (%s)",
        this->m_Samples[0][2 * this->m_CurrentSample + this->m_CurrentSample + v9],
        pTitles[v9]);
      y -= 10;
      g_pMatSystemSurface->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: this->m_hFont,
        a3: HIDWORD(PrevTime),
        a4: y,
        a5: *(v10 - 1),
        a6: *v10,
        a7: v10[1],
        a8: 180,
        a9: sz);
      v10 -= 3;
      --v9;
    }
    while ( v9 >= 0 );
  }
}

} // namespace engine_xlsp
