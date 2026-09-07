// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: unittests/avitest/avitest.cpp
// Functions: 163
// ============================================================

#include "unittests\avitest\avitest.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
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
// Address: 0x00401070
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
// Address: 0x004010F0
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
// Address: 0x004011C0
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
// Address: 0x00401230
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  return AppMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x00401260
// Name: public: virtual bool CAVITestApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAVITestApp::Create(CAVITestApp *this)
{
  bool result; // al
  AppSystemInfo_t appSystems[3]; // [esp+4h] [ebp-18h] BYREF

  result = CVguiMatSysApp::Create(this);
  if ( result )
  {
    appSystems[0].m_pModuleName = "valve_avi.dll";
    appSystems[1].m_pModuleName = "valve_avi.dll";
    appSystems[2].m_pModuleName = defaultValue;
    appSystems[2].m_pInterfaceName = defaultValue;
    appSystems[0].m_pInterfaceName = "VAvi001";
    appSystems[1].m_pInterfaceName = "VBik001";
    return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004012B0
// Name: public: virtual bool CAVITestApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAVITestApp::PreInit(CAVITestApp *this)
{
  IAvi_vtbl *v2; // esi
  int ItemCount; // eax

  if ( !CVguiMatSysApp::PreInit(this)
    || g_pFullFileSystem == nullptr
    || g_pMaterialSystem == nullptr
    || g_pVGui == nullptr
    || g_pVGuiSurface == nullptr
    || g_pAVI == nullptr
    || g_pBIK == nullptr )
  {
    return 0;
  }
  v2 = g_pAVI->__vftable;
  ItemCount = vgui::TreeView::GetItemCount((vgui::CTreeViewListControl *)this);
  v2->SetMainWindow(this: g_pAVI, a2: (void *)ItemCount);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401320
// Name: public: virtual void CAVITestApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAVITestApp::PostShutdown(CAVITestApp *this)
{
  g_pAVI->SetMainWindow(this: g_pAVI, a2: nullptr);
  CVguiMatSysApp::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00401340
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x004013C0
// Name: private: void CAVITestApp::DrawStuff(unsigned short)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CAVITestApp::DrawStuff(CAVITestApp *this, IMaterial *hMaterial)
{
  int WindowWidth; // edi
  IAvi_vtbl *v4; // ebx
  IMatRenderContext *v5; // eax
  IMatRenderContext *v6; // esi
  void (__thiscall *Ortho)(IMatRenderContext *, long double, long double, long double, long double, long double, long double); // eax
  IMesh *v8; // edi
  float *m_pCurrPosition; // eax
  float v10; // xmm0_4
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm1_4
  double v15; // xmm0_8
  float *v16; // eax
  float *v17; // eax
  float *v18; // eax
  float *v19; // eax
  int m_nVertexCount; // eax
  float v21; // [esp+48h] [ebp-210h]
  CMeshBuilder meshBuilder; // [esp+58h] [ebp-200h] BYREF
  double v23; // [esp+240h] [ebp-18h]
  float flMaxU; // [esp+248h] [ebp-10h] BYREF
  float flMaxV; // [esp+24Ch] [ebp-Ch] BYREF
  double v26; // [esp+250h] [ebp-8h] OVERLAPPED
  IMaterial *pMaterial; // [esp+260h] [ebp+8h]
  IMaterial *pMateriala; // [esp+260h] [ebp+8h]

  WindowWidth = CMatSysApp::GetWindowWidth(this);
  HIDWORD(v26) = vgui::ScrollBarSlider::GetValue((vgui::ScrollBarSlider *)this);
  v4 = g_pAVI->__vftable;
  v21 = _Plat_FloatTime() - this->m_flStartTime;
  ((void (__thiscall *)(IAvi *, IMaterial *, _DWORD))v4->SetTime)(a1: g_pAVI, a2: hMaterial, a3: LODWORD(v21));
  g_pAVI->GetTexCoordRange(this: g_pAVI, a2: (unsigned __int16)hMaterial, a3: &flMaxU, a4: &flMaxV);
  pMaterial = g_pAVI->GetMaterial(this: g_pAVI, a2: hMaterial);
  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v6 = v5;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v6->MatrixMode(this: v6, a2: MATERIAL_PROJECTION);
  v6->LoadIdentity(this: v6);
  Ortho = v6->Ortho;
  v26 = (double)SHIDWORD(v26);
  v23 = (double)WindowWidth;
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))Ortho)(
    a1: v6,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0,
    a6: COERCE_UNSIGNED_INT64((double)WindowWidth),
    a7: HIDWORD(COERCE_UNSIGNED_INT64((double)WindowWidth)),
    a8: LODWORD(v26),
    a9: HIDWORD(v26),
    a10: 0,
    a11: 0,
    a12: 0,
    a13: 1072693248);
  v6->Bind(this: v6, a2: pMaterial, a3: nullptr);
  v8 = v6->GetDynamicMesh(this: v6, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v8;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v8->SetPrimitiveType(this: v8, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v8, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -0.5;
  v10 = v26 + 0.5;
  m_pCurrPosition[1] = v10;
  *((float *)&v26 + 1) = v10;
  m_pCurrPosition[2] = 0.0;
  v11 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v11[1] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v12 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -0.5;
  v12[1] = 0.5;
  v12[2] = 0.0;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = flMaxV;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v13[1] = v14;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v15 = v23 - 0.5;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *(float *)&v15 = v15;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)&v15;
  pMateriala = (IMaterial *)LODWORD(v15);
  v16[1] = 0.5;
  v16[2] = 0.0;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *(float *)&v15 = flMaxV;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = flMaxU;
  v17[1] = *(float *)&v15;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v18 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrPosition = pMateriala;
  v18[1] = *((float *)&v26 + 1);
  v18[2] = 0.0;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = flMaxU;
  v19[1] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
  v8->Draw_2(this: v8, a2: -1, a3: 0);
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
  v6->EndRender(this: v6);
  v6->Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004017F0
// Name: public: virtual int CAVITestApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CAVITestApp::Main@<eax>(CAVITestApp *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  IMatRenderContext *v5; // esi
  unsigned int v6; // eax
  vgui::ISurface_vtbl *v7; // edx
  void (__thiscall *ReadPixelsAndStretch)(IMatRenderContext *, Rect_t *, Rect_t *, unsigned __int8 *, ImageFormat, int); // edx
  AVIParams_t params; // [esp+4h] [ebp-240h] BYREF
  Rect_t rect; // [esp+224h] [ebp-20h] BYREF
  unsigned int root; // [esp+234h] [ebp-10h]
  int h; // [esp+238h] [ebp-Ch]
  IMaterial *hAVIMaterial; // [esp+23Ch] [ebp-8h]
  BGR888_t *hp; // [esp+240h] [ebp-4h]

  if ( !CMatSysApp::SetVideoMode(this) )
    return 0;
  ((void (__thiscall *)(vgui::ISchemeManager *, const char *, const char *, int, int))g_pVGuiSchemeManager->LoadSchemeFromFile)(
    a1: g_pVGuiSchemeManager,
    a2: "resource/BoxRocket.res",
    a3: "ElementViewer",
    a4: a3,
    a5: a2);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/boxrocket_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/valve_%language%.txt", a3: nullptr, a4: false);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/vgui_%language%.txt", a3: nullptr, a4: false);
  g_pVGui->Start(this: g_pVGui);
  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  params.m_nFrameRate = 0;
  params.m_nFrameScale = 1;
  memset(&params.m_nWidth, 0, 20);
  params.m_bGetCodecFromUser = true;
  params.m_pFileName[0] = 0;
  _V_strcpy(dest: params.m_pFileName, src: "c:\\temp\\out.avi");
  _V_strcpy(dest: params.m_pPathID, src: "MOD");
  v5->GetWindowSize(this: v5, a2: &params.m_nWidth, a3: &params.m_nHeight);
  params.m_nFrameRate = 24;
  params.m_nFrameScale = 1;
  params.m_nNumChannels = 0;
  h = g_pAVI->StartAVI(this: g_pAVI, a2: &params);
  hAVIMaterial = (IMaterial *)g_pAVI->CreateAVIMaterial(
                                this: g_pAVI,
                                a2: "avitest",
                                a3: "c:\\temp\\test.avi",
                                a4: "MOD");
  v6 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  v7 = g_pVGuiSurface->__vftable;
  root = v6;
  v7->Invalidate(this: g_pVGuiSurface, a2: v6);
  hp = (BGR888_t *)operator new(nSize: 3 * params.m_nWidth * params.m_nHeight);
  this->m_flStartTime = _Plat_FloatTime();
  this->m_pMaterial = g_pMaterialSystem->FindMaterial(
                        this: g_pMaterialSystem,
                        a2: "debug/debugempty",
                        a3: "app",
                        a4: 1,
                        a5: 0);
  while ( g_pVGui->IsRunning(this: g_pVGui) )
  {
    CMatSysApp::AppPumpMessages(this);
    v5->ClearColor4ub(this: v5, a2: 76u, a3: 88u, a4: 68u, a5: 255u);
    v5->ClearBuffers(this: v5, a2: true, a3: true, a4: false);
    CAVITestApp::DrawStuff(this, hMaterial: hAVIMaterial);
    g_pVGui->RunFrame(this: g_pVGui);
    g_pVGuiSurface->PaintTraverse(this: g_pVGuiSurface, a2: root);
    ReadPixelsAndStretch = v5->ReadPixelsAndStretch;
    rect.width = params.m_nWidth;
    rect.height = params.m_nHeight;
    rect.y = 0;
    rect.x = 0;
    ReadPixelsAndStretch(this: v5, a2: &rect, a3: &rect, a4: &hp->b, a5: IMAGE_FORMAT_BGR888, a6: 3 * params.m_nWidth);
    g_pAVI->AppendMovieFrame(this: g_pAVI, a2: h, a3: hp);
    g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
  }
  free(pMem: (void *)hp);
  g_pAVI->FinishAVI(this: g_pAVI, a2: h);
  g_pAVI->DestroyAVIMaterial(this: g_pAVI, a2: (unsigned __int16)hAVIMaterial);
  v5->EndRender(this: v5);
  v5->Release(this: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401AF0
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
    dword_4B7324 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_4B7324;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00401B50
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
    dword_4B7324 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00401BB0
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
    dword_4B7324 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00401C10
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
// Address: 0x00401CC0
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
      dword_4B7324 = 0x1FFFF;
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
      dword_4B7324 = 0x1FFFF;
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
// Address: 0x00401D90
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
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
// Address: 0x00401F80
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
// Address: 0x00401FF0
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
// Address: 0x00402050
// Name: public: virtual char const __near * CAVITestApp::GetAppName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAVITestApp::GetAppName(CAVITestApp *this)
{
  return "AVITest";
}

//------------------------------------------------------------------------------
// Address: 0x004028E0
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004029D0
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
// Address: 0x00402AD0
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
// Address: 0x00402BC0
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
// Address: 0x00402EA0
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
// Address: 0x00402F10
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00403010
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
// Address: 0x004030D0
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
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
        dword_4B7324 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4B7324 = 0x1FFFF;
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
          dword_4B7324 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4B7324 = 0x1FFFF;
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
          dword_4B7324 = 0x1FFFF;
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
          dword_4B7324 = 0x1FFFF;
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
            dword_4B7324 = 0x1FFFF;
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
            dword_4B7324 = 0x1FFFF;
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
          dword_4B7324 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4B7324 = 0x1FFFF;
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
          dword_4B7324 = 0x1FFFF;
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
          dword_4B7324 = 0x1FFFF;
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
            dword_4B7324 = 0x1FFFF;
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
            dword_4B7324 = 0x1FFFF;
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
// Address: 0x004036C0
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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00403710
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
// Address: 0x00403C10
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
// Address: 0x00408300
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<void *,unsigned short> *v12; // edx

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
// Address: 0x00408400
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
    dword_4B7A34 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_4B7A34;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00408580
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
    dword_4B7A34 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004085E0
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
    dword_4B7A34 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00408650
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
        dword_4B7A34 = 0x1FFFF;
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
        dword_4B7A34 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408740
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
// Address: 0x00408840
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
// Address: 0x00408980
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
        dword_4B7A34 = 0x1FFFF;
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
        dword_4B7A34 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00408A80
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
// Address: 0x00408B40
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
      dword_4B7A34 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4B7A34 = 0x1FFFF;
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
      dword_4B7A34 = 0x1FFFF;
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
      dword_4B7A34 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4B7A34 = 0x1FFFF;
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
      dword_4B7A34 = 0x1FFFF;
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
        dword_4B7A34 = 0x1FFFF;
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
        dword_4B7A34 = 0x1FFFF;
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
          dword_4B7A34 = 0x1FFFF;
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
          dword_4B7A34 = 0x1FFFF;
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
        dword_4B7A34 = 0x1FFFF;
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
        dword_4B7A34 = 0x1FFFF;
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
          dword_4B7A34 = 0x1FFFF;
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
          dword_4B7A34 = 0x1FFFF;
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
// Address: 0x004091D0
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
// Address: 0x004092D0
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
// Address: 0x00409360
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
  v3 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::NewNode((CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)this);
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
// Address: 0x00410340
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004103B0
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041B840
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( i == -1 )
    return dword_4BBCCC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0041D350
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( i == -1 )
    return dword_4BBCC8;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041D3B0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D4A0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( i == -1 )
    return dword_4BBCE0;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0041D500
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( i == -1 )
    return dword_4BBCDC;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041D560
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4BBCDC == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041D610
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D700
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( i == -1 )
    return dword_4BBCF4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0041D760
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( i == -1 )
    return dword_4BBCF0;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041D7C0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4BBCF0 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041D870
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D960
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCC8 = -1;
      dword_4BBCCC = -1;
      dword_4BBCD0 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCC8 = -1;
      dword_4BBCCC = -1;
      dword_4BBCD0 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041DA00
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4BBCC8 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041DAB0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041DB60
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCC8 = -1;
      dword_4BBCCC = -1;
      dword_4BBCD0 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041DD10
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041DE80
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041DF30
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCDC = -1;
      dword_4BBCE0 = -1;
      dword_4BBCE4 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041E0E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041E250
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041E300
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCF0 = -1;
      dword_4BBCF4 = -1;
      dword_4BBCF8 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041E4B0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041E6E0
// Name: public: int CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::Find(struct CKeyBindingsMgr::KBContext_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Find(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this,
        const CKeyBindingsMgr::KBContext_t *search)
{
  int m_Root; // ebx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCB4 = -1;
        dword_4BBCB8 = -1;
        dword_4BBCBC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCB4 = -1;
        dword_4BBCB8 = -1;
        dword_4BBCBC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041E7D0
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  vgui::BoundKey_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041E840
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041E8D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041E9C0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041EAB0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCDC = -1;
            dword_4BBCE0 = -1;
            dword_4BBCE4 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EB70
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCDC = -1;
      dword_4BBCE0 = -1;
      dword_4BBCE4 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCDC = -1;
      dword_4BBCE0 = -1;
      dword_4BBCE4 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041EC10
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCDC = -1;
    dword_4BBCE0 = -1;
    dword_4BBCE4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCDC = -1;
          dword_4BBCE0 = -1;
          dword_4BBCE4 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041ED80
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041EE70
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCF0 = -1;
            dword_4BBCF4 = -1;
            dword_4BBCF8 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EF30
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCF0 = -1;
      dword_4BBCF4 = -1;
      dword_4BBCF8 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BBCF0 = -1;
      dword_4BBCF4 = -1;
      dword_4BBCF8 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041EFE0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCF0 = -1;
    dword_4BBCF4 = -1;
    dword_4BBCF8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCF0 = -1;
          dword_4BBCF4 = -1;
          dword_4BBCF8 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F150
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCC8 = -1;
            dword_4BBCCC = -1;
            dword_4BBCD0 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F210
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BBCC8 = -1;
    dword_4BBCCC = -1;
    dword_4BBCD0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCC8 = -1;
          dword_4BBCCC = -1;
          dword_4BBCD0 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F380
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCC8 = -1;
        dword_4BBCCC = -1;
        dword_4BBCD0 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCC8 = -1;
          dword_4BBCCC = -1;
          dword_4BBCD0 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCC8 = -1;
          dword_4BBCCC = -1;
          dword_4BBCD0 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCC8 = -1;
            dword_4BBCCC = -1;
            dword_4BBCD0 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCC8 = -1;
            dword_4BBCCC = -1;
            dword_4BBCD0 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCC8 = -1;
          dword_4BBCCC = -1;
          dword_4BBCD0 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCC8 = -1;
          dword_4BBCCC = -1;
          dword_4BBCD0 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCC8 = -1;
            dword_4BBCCC = -1;
            dword_4BBCD0 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCC8 = -1;
            dword_4BBCCC = -1;
            dword_4BBCD0 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F7E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCDC = -1;
        dword_4BBCE0 = -1;
        dword_4BBCE4 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCDC = -1;
          dword_4BBCE0 = -1;
          dword_4BBCE4 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCDC = -1;
          dword_4BBCE0 = -1;
          dword_4BBCE4 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCDC = -1;
            dword_4BBCE0 = -1;
            dword_4BBCE4 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCDC = -1;
            dword_4BBCE0 = -1;
            dword_4BBCE4 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCDC = -1;
          dword_4BBCE0 = -1;
          dword_4BBCE4 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCDC = -1;
          dword_4BBCE0 = -1;
          dword_4BBCE4 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCDC = -1;
            dword_4BBCE0 = -1;
            dword_4BBCE4 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCDC = -1;
            dword_4BBCE0 = -1;
            dword_4BBCE4 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041FC40
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BBCF0 = -1;
        dword_4BBCF4 = -1;
        dword_4BBCF8 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCF0 = -1;
          dword_4BBCF4 = -1;
          dword_4BBCF8 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCF0 = -1;
          dword_4BBCF4 = -1;
          dword_4BBCF8 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCF0 = -1;
            dword_4BBCF4 = -1;
            dword_4BBCF8 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCF0 = -1;
            dword_4BBCF4 = -1;
            dword_4BBCF8 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCF0 = -1;
          dword_4BBCF4 = -1;
          dword_4BBCF8 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BBCF0 = -1;
          dword_4BBCF4 = -1;
          dword_4BBCF8 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCF0 = -1;
            dword_4BBCF4 = -1;
            dword_4BBCF8 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCF0 = -1;
            dword_4BBCF4 = -1;
            dword_4BBCF8 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00420420
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(this);
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
// Address: 0x00420480
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(this);
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
// Address: 0x004204E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420550
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004205C0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422990
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RemoveAll(this);
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
// Address: 0x00422FA0
// Name: public: void CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::RemoveAll(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi
  int v5; // edi

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0 && v4 < this->m_Elements.m_nAllocationCount && v4 <= index )
        {
          if ( (`CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BBCB4 = -1;
            dword_4BBCB8 = -1;
            dword_4BBCBC = 1;
          }
          if ( this->m_Elements.m_pMemory[v4].m_Left != v4 )
          {
            v5 = v4;
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Elements.m_pMemory[v4].m_Data.m_Panels);
            this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v5].m_Left = v4;
            this->m_FirstFree = v4;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423270
// Name: public: CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this)
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::RemoveAll(this);
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
// Address: 0x0042A650
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

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
// Address: 0x0042B670
// Name: protected: enum CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::NodeColor_t CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::Color(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Color(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( i == -1 )
    return dword_4BC8FC;
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x0042D200
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::Find(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::Find(CUtlVector<int,CUtlMemory<int,int> > *this, const int *src)
{
  int m_Size; // edx
  int result; // eax
  int *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042D230
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( i == -1 )
    return dword_4BC8F8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0042D290
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0042D2F0
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( i == -1 )
    return dword_4BC8F4;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0042D350
// Name: public: bool CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( m_Parent == -1 )
    return dword_4BC8F4 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0042D400
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::FindInsertionPosition(struct vgui::ListPanel::IndexItem_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        const vgui::ListPanel::IndexItem_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D4F0
// Name: public: bool CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0042D5A0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042D8F0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v9; // eax

  v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BC8F4 = -1;
      dword_4BC8F8 = -1;
      dword_4BC8FC = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0042DAA0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v6; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v7; // eax

  v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0042DC20
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::InsertRebalance(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v7; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v18; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v19; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v20; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v23; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042ED60
// Name: public: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EE20
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::FirstInorder(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BC8F4 = -1;
      dword_4BC8F8 = -1;
      dword_4BC8FC = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BC8F4 = -1;
      dword_4BC8F8 = -1;
      dword_4BC8FC = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042EED0
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::NextInorder(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BC8F4 = -1;
    dword_4BC8F8 = -1;
    dword_4BC8FC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F040
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::LastInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LastInorder(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BC8F4 = -1;
      dword_4BC8F8 = -1;
      dword_4BC8FC = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( v3[1] == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BC8F4 = -1;
      dword_4BC8F8 = -1;
      dword_4BC8FC = 1;
    }
    if ( result == -1 )
      result = dword_4BC8F4;
    else
      result = this->m_Elements.m_pMemory[result].m_Right;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F0E0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v5; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v6; // ecx
  int m_Parent; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v9; // ecx
  int m_Right; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v11; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v12; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v13; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v14; // edx
  int m_Left; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v16; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v17; // edx
  int v18; // edx
  int *v19; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v20; // edx
  int v21; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v22; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v23; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v24; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v25; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v26; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v27; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v28; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v29; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v30; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v31; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v32; // edx
  int v33; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v34; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v35; // edx
  int v36; // edx
  int *v37; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v38; // edx
  int v39; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v40; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v41; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v42; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v43; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v44; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v45; // ecx

  v2 = elem;
  if ( elem != this->m_Root )
  {
    v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
    do
    {
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      if ( v5->m_Tag != 1 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      if ( v2 == -1 )
        v6 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v6 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v6->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BC8F4 = -1;
        dword_4BC8F8 = -1;
        dword_4BC8FC = 1;
      }
      if ( m_Parent == -1 )
      {
        v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      }
      else
      {
        v8 = &this->m_Elements.m_pMemory[m_Parent];
        v2 = elem;
      }
      if ( v2 == v8->m_Left )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Parent == -1 )
          v9 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v9 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v9->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v11 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v11 = &this->m_Elements.m_pMemory[m_Right];
        if ( v11->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( elem == -1 )
            v12 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v12 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v12->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Parent == -1 )
            v13 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v13 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v13->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v14 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_Right];
        m_Left = v14->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Left == -1 )
          v16 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Left];
        if ( v16->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Right == -1 )
            v17 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v17 = &this->m_Elements.m_pMemory[m_Right];
          v18 = v17->m_Right;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          v19 = v18 == -1
              ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v18];
          if ( v19[3] == 1 )
            goto LABEL_146;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v20 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_Right];
        v21 = v20->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( v21 == -1 )
          v22 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v22 = &this->m_Elements.m_pMemory[v21];
        if ( v22->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Right == -1 )
            v23 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v23->m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( elem == -1 )
            v24 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Parent == -1 )
            v25 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v25 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v25->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Parent == -1 )
          v26 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v26->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v27 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v27 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v27->m_Right].m_Tag = 1;
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
          this,
          elem: m_Parent);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Parent == -1 )
          v28 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v28->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v29 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v29 = &this->m_Elements.m_pMemory[m_Right];
        if ( v29->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( elem == -1 )
            v30 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v30->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Parent == -1 )
            v31 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v31->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v32 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v32 = &this->m_Elements.m_pMemory[m_Right];
        v33 = v32->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( v33 == -1 )
          v34 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v34 = &this->m_Elements.m_pMemory[v33];
        if ( v34->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Right == -1 )
            v35 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v35 = &this->m_Elements.m_pMemory[m_Right];
          v36 = v35->m_Left;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          v37 = v36 == -1
              ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v36];
          if ( v37[3] == 1 )
          {
LABEL_146:
            if ( m_Right != -1 )
            {
              this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
              v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
            }
            elem = m_Parent;
            goto LABEL_188;
          }
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v38 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v38 = &this->m_Elements.m_pMemory[m_Right];
        v39 = v38->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( v39 == -1 )
          v40 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v40 = &this->m_Elements.m_pMemory[v39];
        if ( v40->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Right == -1 )
            v41 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v41 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v41->m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( elem == -1 )
            v42 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v42 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v42->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Parent == -1 )
            v43 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v43 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v43->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Parent == -1 )
          v44 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v44 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v44->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BC8F4 = -1;
          dword_4BC8F8 = -1;
          dword_4BC8FC = 1;
        }
        if ( m_Right == -1 )
          v45 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v45 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v45->m_Left].m_Tag = 1;
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
          this,
          elem: m_Parent);
      }
      v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      elem = this->m_Root;
LABEL_188:
      v2 = elem;
    }
    while ( elem != this->m_Root );
  }
  this->m_Elements.m_pMemory[v2].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FE10
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0042FE60
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Unlink(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int m_Left; // edi
  int v4; // ecx
  int v5; // eax
  int *v6; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v7; // eax
  int v8; // ebx
  int v9; // ebx
  CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> >::NodeColor_t ycolor; // [esp+Ch] [ebp-8h]
  int x; // [esp+10h] [ebp-4h]

  m_Left = elem;
  if ( elem != -1 )
  {
    v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BC8F4 = -1;
      dword_4BC8F8 = -1;
      dword_4BC8FC = 1;
    }
    if ( this->m_Elements.m_pMemory[elem].m_Left != -1 )
    {
      if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
             this,
             i: elem) == -1 )
      {
        v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      }
      else
      {
        v5 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
               this,
               i: elem);
        v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
        m_Left = v5;
        while ( 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          v6 = m_Left == -1
             ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
             : (int *)&this->m_Elements.m_pMemory[m_Left];
          if ( *v6 == -1 )
            break;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BC8F4 = -1;
            dword_4BC8F8 = -1;
            dword_4BC8FC = 1;
          }
          if ( m_Left == -1 )
            m_Left = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            m_Left = this->m_Elements.m_pMemory[m_Left].m_Left;
        }
      }
    }
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BC8F4 = -1;
      dword_4BC8F8 = -1;
      dword_4BC8FC = 1;
    }
    if ( m_Left == -1 )
      v7 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v7 = &this->m_Elements.m_pMemory[m_Left];
    if ( v7->m_Left == -1 )
    {
      x = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
            this,
            i: m_Left);
      v8 = x;
    }
    else
    {
      v8 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
             this,
             i: m_Left);
      x = v8;
    }
    if ( v8 != -1 )
      this->m_Elements.m_pMemory[v8].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                  this,
                                                  i: m_Left);
    if ( m_Left == this->m_Root )
    {
      this->m_Root = v8;
    }
    else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
                this,
                i: m_Left) )
    {
      this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Left = v8;
    }
    else
    {
      this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Right = v8;
    }
    ycolor = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Color(
               this,
               i: m_Left);
    if ( m_Left != elem )
    {
      v9 = m_Left;
      this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                      this,
                                                      i: elem);
      this->m_Elements.m_pMemory[v9].m_Right = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
                                                 this,
                                                 i: elem);
      this->m_Elements.m_pMemory[v9].m_Left = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
                                                this,
                                                i: elem);
      if ( elem == this->m_Root )
      {
        this->m_Root = m_Left;
      }
      else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
                  this,
                  i: elem) )
      {
        this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Left = m_Left;
      }
      else
      {
        this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Right = m_Left;
      }
      if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      this->m_Elements.m_pMemory[v9].m_Tag = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Color(
                                               this,
                                               i: elem);
      v8 = x;
    }
    if ( v8 != -1 && ycolor == BLACK )
      CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(
        this,
        elem: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DDC0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x0043E970
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EC50
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00447020
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0044CC40
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044F210
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0044FD70
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( i == -1 )
    return dword_4BE80C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0044FE70
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE7FC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_4BE7FC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0044FEE0
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE7FC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0044FF40
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE7FC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0044FFB0
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::FindInsertionPosition(void __near * const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        void *const *insert,
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
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE7FC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE7FC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004500A0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( i == -1 )
    return dword_4BE808;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00450100
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004501F0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE808 = -1;
      dword_4BE80C = -1;
      dword_4BE810 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE808 = -1;
      dword_4BE80C = -1;
      dword_4BE810 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00450290
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4BE808 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00450340
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00450440
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00450540
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x004505F0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE808 = -1;
      dword_4BE80C = -1;
      dword_4BE810 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004507A0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004509C0
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00450A40
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::Find(void __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        void *const *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE7FC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE7FC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00450B40
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00450C30
// Name: public: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x00450CF0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BE808 = -1;
            dword_4BE80C = -1;
            dword_4BE810 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450DB0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BE808 = -1;
    dword_4BE80C = -1;
    dword_4BE810 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE808 = -1;
          dword_4BE80C = -1;
          dword_4BE810 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00450F20
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
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
    v4 = `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE7FC = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE7FC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE7FC = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE7FC = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE7FC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4BE7FC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE7FC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE7FC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE7FC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE7FC = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
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
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE7FC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE7FC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE7FC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE7FC = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x004514D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BE808 = -1;
        dword_4BE80C = -1;
        dword_4BE810 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE808 = -1;
          dword_4BE80C = -1;
          dword_4BE810 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE808 = -1;
          dword_4BE80C = -1;
          dword_4BE810 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BE808 = -1;
            dword_4BE80C = -1;
            dword_4BE810 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BE808 = -1;
            dword_4BE80C = -1;
            dword_4BE810 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE808 = -1;
          dword_4BE80C = -1;
          dword_4BE810 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BE808 = -1;
          dword_4BE80C = -1;
          dword_4BE810 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BE808 = -1;
            dword_4BE80C = -1;
            dword_4BE810 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BE808 = -1;
            dword_4BE80C = -1;
            dword_4BE810 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00451930
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451A40
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(this);
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
// Address: 0x00451C50
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451F50
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
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
// Address: 0x00452620
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x00453D20
// Name: public: int CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00454300
// Name: public: bool CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::FindAndRemove(class vgui::PHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00454370
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00456BC0
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( i == -1 )
    return dword_4BEA04;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00456C20
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( i == -1 )
    return dword_4BEA00;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00456C80
// Name: public: bool CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4BEA00 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00456D30
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::FindInsertionPosition(char const __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        const char *const *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BEA00 = -1;
        dword_4BEA04 = -1;
        dword_4BEA08 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BEA00 = -1;
        dword_4BEA04 = -1;
        dword_4BEA08 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456E20
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<char const *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<char const *,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456EE0
// Name: public: bool CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00456F90
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<char const *,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<char const *,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<char const *,int> *v8; // ecx
  UtlRBTreeNode_t<char const *,int> *v9; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BEA00 = -1;
      dword_4BEA04 = -1;
      dword_4BEA08 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00457140
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<char const *,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<char const *,int> *v6; // eax
  UtlRBTreeNode_t<char const *,int> *v7; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00457330
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FirstInorder(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BEA00 = -1;
      dword_4BEA04 = -1;
      dword_4BEA08 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4BEA00 = -1;
      dword_4BEA04 = -1;
      dword_4BEA08 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004573D0
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4BEA00 = -1;
    dword_4BEA04 = -1;
    dword_4BEA08 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BEA00 = -1;
          dword_4BEA04 = -1;
          dword_4BEA08 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BEA00 = -1;
        dword_4BEA04 = -1;
        dword_4BEA08 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BEA00 = -1;
        dword_4BEA04 = -1;
        dword_4BEA08 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457540
// Name: public: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RemoveAll(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BEA00 = -1;
            dword_4BEA04 = -1;
            dword_4BEA08 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457600
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<char const *,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<char const *,int> *v7; // ecx
  UtlRBTreeNode_t<char const *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<char const *,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<char const *,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<char const *,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<char const *,int> *v18; // ecx
  UtlRBTreeNode_t<char const *,int> *v19; // eax
  UtlRBTreeNode_t<char const *,int> *v20; // eax
  UtlRBTreeNode_t<char const *,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<char const *,int> *v23; // ecx
  UtlRBTreeNode_t<char const *,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BEA00 = -1;
        dword_4BEA04 = -1;
        dword_4BEA08 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BEA00 = -1;
        dword_4BEA04 = -1;
        dword_4BEA08 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BEA00 = -1;
        dword_4BEA04 = -1;
        dword_4BEA08 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4BEA00 = -1;
        dword_4BEA04 = -1;
        dword_4BEA08 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BEA00 = -1;
          dword_4BEA04 = -1;
          dword_4BEA08 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BEA00 = -1;
          dword_4BEA04 = -1;
          dword_4BEA08 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BEA00 = -1;
            dword_4BEA04 = -1;
            dword_4BEA08 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BEA00 = -1;
            dword_4BEA04 = -1;
            dword_4BEA08 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BEA00 = -1;
          dword_4BEA04 = -1;
          dword_4BEA08 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4BEA00 = -1;
          dword_4BEA04 = -1;
          dword_4BEA08 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BEA00 = -1;
            dword_4BEA04 = -1;
            dword_4BEA08 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4BEA00 = -1;
            dword_4BEA04 = -1;
            dword_4BEA08 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047DE90
// Name: public: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<0>,0>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C00CC = -1;
            dword_4C00D0 = -1;
            dword_4C00D4 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DF50
// Name: public: CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<0>,0>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::~CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<0>,0>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this)
{
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this);
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
