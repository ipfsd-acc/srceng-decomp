// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/viewdebug.cpp
// Functions: 12
// ============================================================

#include "game\client\viewdebug.h"

//------------------------------------------------------------------------------
// Address: 0x10193CF0
// Name: public: static void CDebugViewRender::Draw3DDebuggingInfo(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugViewRender::Draw3DDebuggingInfo()
{
  FoundryHelpers_DrawAll();
  render->Draw3DDebugOverlays(this: render);
  render->DrawLineFile(this: render);
}

//------------------------------------------------------------------------------
// Address: 0x10193D10
// Name: r_screenoverlay
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_screenoverlay(const CCommand *args)
{
  const char *v1; // eax
  IMaterial *v2; // eax
  IMaterial *v3; // esi
  IMaterial *v4; // eax
  const char *v5; // eax

  if ( args->m_nArgc == 2 )
  {
    if ( _V_stricmp(s1: "off", s2: args->m_ppArgv[1]) == 0 )
      goto LABEL_3;
    v1 = prType;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = materials->FindMaterial(this: materials, a2: v1, a3: "Other textures", a4: 0, a5: 0);
    v3 = v2;
    if ( v2 != nullptr && !v2->IsErrorMaterial(this: v2) )
      view->SetScreenOverlayMaterial(this: view, a2: v3);
    else
LABEL_3:
      view->SetScreenOverlayMaterial(this: view, a2: nullptr);
  }
  else
  {
    v4 = view->GetScreenOverlayMaterial(this: view);
    if ( v4 != nullptr )
    {
      v5 = (const char *)v4->GetName(this: v4);
      _Warning(a1: "r_screenoverlay: %s\n", v5);
    }
    else
    {
      _Warning(a1: "r_screenoverlay: %s\n", "off");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193DF0
// Name: public: static void CDebugViewRender::GenerateOverdrawForTesting(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDebugViewRender::GenerateOverdrawForTesting(int a1@<ebx>, int a2@<edi>)
{
  int i; // esi

  if ( cl_overdraw_test.m_pParent != nullptr && cl_overdraw_test.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = 40; i != 0; --i )
    {
      g_SmokeFogOverlayAlpha = 0.078431375;
      g_SmokeFogOverlayColor.x = 0.33000001;
      g_SmokeFogOverlayColor.y = 0.33000001;
      g_SmokeFogOverlayColor.z = 0.33000001;
      DrawSmokeFogOverlay(a1, a2, a3: i);
    }
    g_SmokeFogOverlayAlpha = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193E60
// Name: void DrawScreenEffectMaterial(class IMaterial __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawScreenEffectMaterial(IMaterial *pMaterial, int x, int y, int w, int h)
{
  ITexture *FullFrameFrameBufferTexture; // edi
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // esi
  IMatRenderContext_vtbl *v8; // ebx
  int v9; // eax
  int v10; // eax
  Rect_t actualRect; // [esp+30h] [ebp-10h] BYREF

  UpdateScreenEffectTexture(textureIndex: 0, x, y, w, h, bDestFullScreen: false, pActualRect: &actualRect);
  FullFrameFrameBufferTexture = GetFullFrameFrameBufferTexture(textureIndex: 0);
  v6 = materials->GetRenderContext(this: materials);
  v7 = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v8 = v7->__vftable;
  v9 = ((int (__thiscall *)(ITexture *, _DWORD, int, int))FullFrameFrameBufferTexture->GetActualHeight)(
         a1: FullFrameFrameBufferTexture,
         a2: 0,
         a3: 1,
         a4: 1);
  v10 = ((int (__thiscall *)(ITexture *, int))FullFrameFrameBufferTexture->GetActualWidth)(
          a1: FullFrameFrameBufferTexture,
          a2: v9);
  ((void (__thiscall *)(IMatRenderContext *, IMaterial *, int, int, int, int, float, float, float, float, int))v8->DrawScreenSpaceRectangle)(
    a1: v7,
    a2: pMaterial,
    a3: x,
    a4: y,
    a5: w,
    a6: h,
    a7: (float)actualRect.x,
    a8: (float)actualRect.y,
    a9: (float)(actualRect.width + actualRect.x - 1),
    a10: (float)(actualRect.height + actualRect.y - 1),
    a11: v10);
  v7->EndRender(this: v7);
  v7->Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10193F50
// Name: public: virtual void CLightmapDebugView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLightmapDebugView::Draw(CLightmapDebugView *this@<ecx>, int a2@<ebx>)
{
  IMatRenderContext *v3; // esi
  CViewSetup *v4; // eax
  int m_nValue; // eax
  VPlane frustum[6]; // [esp+8h] [ebp-60h] BYREF

  AllowCurrentViewAccess(allow: true);
  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( this != nullptr )
    v4 = &this->CViewSetup;
  else
    v4 = nullptr;
  ((void (__thiscall *)(IVRenderView *, IMatRenderContext *, CViewSetup *, _DWORD, _DWORD, VPlane *, int))render->Push3DView_2)(
    a1: render,
    a2: v3,
    a3: v4,
    a4: 0,
    a5: 0,
    a6: frustum,
    a7: a2);
  CRendering3dView::BuildWorldRenderLists(
    this,
    bDrawEntities: true,
    iForceViewLeaf: -1,
    bUseCacheIfEnabled: true,
    bShadowDepth: true,
    pReflectionWaterHeight: nullptr);
  render->PopView(this: render, a2: v3, a3: frustum);
  AllowCurrentViewAccess(allow: false);
  if ( mat_showlightmappage.m_pParent != nullptr )
    m_nValue = mat_showlightmappage.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  render->DrawLightmaps(this: render, a2: this->m_pWorldRenderList, a3: m_nValue);
  if ( v3 != nullptr )
  {
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194020
// Name: RenderMaterial
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderMaterial(const char *pMaterialName@<edx>, int a2@<ebx>, int a3@<edi>)
{
  IMaterial *v3; // eax
  IMaterial *v4; // esi
  int v5; // eax
  int v6; // ebx
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  float *v9; // eax
  float v10; // xmm0_4
  float *v11; // eax
  float *v12; // eax
  float v13; // xmm0_4
  int (__thiscall *GetMappingHeight)(IMaterial *); // eax
  float v15; // xmm0_4
  float *v16; // eax
  float *v17; // eax
  float v18; // xmm0_4
  float *v19; // eax
  float *v20; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1ECh] BYREF
  float v23; // [esp+1ECh] [ebp-4h]

  v3 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: "Other textures", a4: 0, a5: 0);
  v4 = v3;
  if ( v3 != nullptr && !v3->IsErrorMaterial(this: v3) )
  {
    v5 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
    v6 = v5;
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(a1: v6, a2: v4, a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    m_pCurrPosition[1] = 100.0;
    m_pCurrPosition[2] = 0.0;
    v9 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v9[1] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = (float)v4->GetMappingWidth(this: v4);
    v11 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v10 + 100.0;
    v11[1] = 100.0;
    v11[2] = 0.0;
    v12 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v12[1] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v13 = (float)v4->GetMappingWidth(this: v4) + 100.0;
    GetMappingHeight = v4->GetMappingHeight;
    v23 = v13;
    v15 = (float)GetMappingHeight(this: v4);
    v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
    v16[1] = v15 + 100.0;
    v16[2] = 0.0;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v17[1] = 1.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v18 = (float)v4->GetMappingHeight(this: v4);
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 100.0;
    v19[1] = v18 + 100.0;
    v19[2] = 0.0;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v20[1] = 1.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
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
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101943B0
// Name: OverlayWaterTexture
// Source: json
//------------------------------------------------------------------------------
void __usercall OverlayWaterTexture(IMaterial *pMaterial@<eax>, int a2@<edi>, int xOffset, int yOffset, bool bFlip)
{
  int v6; // xmm0_4
  int v7; // edi
  IMesh *v8; // esi
  float *m_pCurrPosition; // eax
  float v10; // xmm0_4
  float v11; // xmm0_4
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  float *v15; // eax
  float *v16; // eax
  float v17; // xmm0_4
  float *v18; // eax
  float *v19; // eax
  float *v20; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1FCh] BYREF
  float v23; // [esp+1F0h] [ebp-14h]
  float h; // [esp+1F4h] [ebp-10h]
  float fFlip0; // [esp+1F8h] [ebp-Ch]
  float v26; // [esp+1FCh] [ebp-8h]
  float w; // [esp+200h] [ebp-4h]
  float fFlip1; // [esp+214h] [ebp+10h]
  float fFlip1a; // [esp+214h] [ebp+10h]

  if ( bFlip )
  {
    fFlip0 = 1.0;
    *(float *)&v6 = 0.0;
  }
  else
  {
    fFlip0 = 0.0;
    *(float *)&v6 = 1.0;
  }
  fFlip1 = *(float *)&v6;
  if ( pMaterial != nullptr && !pMaterial->IsErrorMaterial(this: pMaterial) )
  {
    v7 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v7 + 36))(a1: v7, a2: pMaterial, a3: 0);
    v8 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 228))(
                    a1: v7,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    w = mat_wateroverlaysize.m_pParent->m_Value.m_fValue;
    h = w;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v8;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v8->SetPrimitiveType(this: v8, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v8, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v10 = (float)xOffset * w;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    v23 = v10;
    v11 = (float)yOffset * h;
    m_pCurrPosition[1] = v11;
    v26 = v11;
    m_pCurrPosition[2] = 0.0;
    v12 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.001953125;
    fFlip1a = fFlip1 + 0.001953125;
    v12[1] = fFlip1a;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v14 = (float)(xOffset + 1) * w;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    w = v14;
    v13[1] = v26;
    v13[2] = 0.0;
    v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0019531;
    v15[1] = fFlip1a;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = w;
    v17 = (float)(yOffset + 1) * h;
    v16[1] = v17;
    v16[2] = 0.0;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0019531;
    v26 = fFlip0 + 0.001953125;
    v18[1] = fFlip0 + 0.001953125;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
    v19[1] = v17;
    v19[2] = 0.0;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.001953125;
    v20[1] = v26;
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
    ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v8->Draw_2(this: v8, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194750
// Name: OverlayWaterTextures
// Source: json
//------------------------------------------------------------------------------
void __usercall OverlayWaterTextures(int a1@<edi>)
{
  IMaterial *v1; // eax
  IMaterial *v2; // eax

  v1 = materials->FindMaterial(this: materials, a2: "debug/debugreflect", a3: 0, a4: 1, a5: 0);
  OverlayWaterTexture(pMaterial: v1, a2: a1, xOffset: 0, yOffset: 0, bFlip: false);
  v2 = materials->FindMaterial(this: materials, a2: "debug/debugrefract", a3: 0, a4: 1, a5: 0);
  OverlayWaterTexture(pMaterial: v2, a2: a1, xOffset: 0, yOffset: 1, bFlip: true);
}

//------------------------------------------------------------------------------
// Address: 0x101947B0
// Name: void OverlayCameraRenderTarget(char const __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall OverlayCameraRenderTarget(
        int a1@<edi>,
        const char *pszMaterialName,
        float flX,
        float flY,
        float w,
        float h)
{
  IMaterial *v6; // eax
  IMaterial *v7; // esi
  int v8; // eax
  int v9; // edi
  IMesh *v10; // esi
  float *m_pCurrPosition; // eax
  float *v12; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  float *v16; // eax
  float *v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  float v21; // [esp+1F0h] [ebp-4h]

  v6 = materials->FindMaterial(this: materials, a2: pszMaterialName, a3: "Other textures", a4: 1, a5: 0);
  v7 = v6;
  if ( v6 != nullptr && !v6->IsErrorMaterial(this: v6) )
  {
    v8 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: a1);
    v9 = v8;
    if ( v8 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v9 + 36))(a1: v9, a2: v7, a3: 0);
    v10 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 228))(
                     a1: v9,
                     a2: 1,
                     a3: 0,
                     a4: 0,
                     a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v10;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v10->SetPrimitiveType(this: v10, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v10->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v10, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = flX;
    m_pCurrPosition[1] = flY;
    m_pCurrPosition[2] = 0.0;
    v12 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.001953125;
    v12[1] = 0.001953125;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = flX + w;
    v21 = flX + w;
    v13[1] = flY;
    v13[2] = 0.0;
    v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0019531;
    v14[1] = 0.001953125;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v15 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v21;
    v15[1] = flY + h;
    v21 = flY + h;
    v15[2] = 0.0;
    v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0019531;
    v16[1] = 1.0019531;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = flX;
    v17[1] = v21;
    v17[2] = 0.0;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.001953125;
    v18[1] = 1.0019531;
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
    ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v10->Draw_2(this: v10, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194AF0
// Name: OverlayFrameBufferTexture
// Source: json
//------------------------------------------------------------------------------
void __usercall OverlayFrameBufferTexture(int a1@<edi>, int nFrameBufferIndex)
{
  IMaterial *v2; // esi
  int v3; // edi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax
  int m_nVertexCount; // eax
  char buf[260]; // [esp+8h] [ebp-2F8h] BYREF
  CMeshBuilder meshBuilder; // [esp+10Ch] [ebp-1F4h] BYREF
  float v17; // [esp+2F4h] [ebp-Ch]
  float h; // [esp+2F8h] [ebp-8h]
  float w; // [esp+2FCh] [ebp-4h]

  V_snprintf(pDest: buf, maxLen: 0x104u, pFormat: "debug/debugfbtexture%d", nFrameBufferIndex);
  v2 = materials->FindMaterial(this: materials, a2: buf, a3: "Other textures", a4: 1, a5: 0);
  if ( v2 != nullptr && !v2->IsErrorMaterial(this: v2) )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: a1);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v3 + 36))(a1: v3, a2: v2, a3: 0);
    v4 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 228))(
                    a1: v3,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    w = mat_framebuffercopyoverlaysize.m_pParent->m_Value.m_fValue;
    h = w;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v4;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v6 = (float)nFrameBufferIndex * w;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v6;
    v17 = v6;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.001953125;
    v7[1] = 0.001953125;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    w = (float)(nFrameBufferIndex + 1) * w;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = w;
    v8[1] = 0.0;
    v8[2] = 0.0;
    v9 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0019531;
    v9[1] = 0.001953125;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = w;
    v10[1] = h;
    v10[2] = 0.0;
    v11 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0019531;
    v11[1] = 1.0019531;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v12 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
    v12[1] = h;
    v12[2] = 0.0;
    v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.001953125;
    v13[1] = 1.0019531;
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
    ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v4->Draw_2(this: v4, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194E60
// Name: OverlayShowTexture
// Source: json
//------------------------------------------------------------------------------
void __usercall OverlayShowTexture(int a1@<esi>, const char *textureName, float scale)
{
  IMaterial *v3; // edi
  int v4; // esi
  ITexture *v5; // eax
  int v6; // edx
  float v7; // xmm0_4
  int (__thiscall *v8)(_DWORD); // eax
  float v9; // xmm0_4
  void (__thiscall *v10)(int, int *, int *, int *, int *); // edx
  void (__thiscall *v11)(int, IMaterial *, _DWORD); // edx
  IMesh *v12; // edi
  float *m_pCurrPosition; // eax
  float *v14; // eax
  float *v15; // eax
  float v16; // xmm0_4
  float *v17; // eax
  float *v18; // eax
  float v19; // xmm0_4
  float *v20; // eax
  float *v21; // eax
  float *v22; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-20Ch] BYREF
  int nViewportX; // [esp+1F0h] [ebp-24h] BYREF
  int nViewportY; // [esp+1F4h] [ebp-20h] BYREF
  int nViewportWidth; // [esp+1F8h] [ebp-1Ch] BYREF
  int nViewportHeight; // [esp+1FCh] [ebp-18h] BYREF
  float y; // [esp+200h] [ebp-14h]
  float w; // [esp+204h] [ebp-10h]
  float x; // [esp+208h] [ebp-Ch]
  float h; // [esp+20Ch] [ebp-8h]
  bool foundVar; // [esp+213h] [ebp-1h] BYREF

  v3 = materials->FindMaterial(this: materials, a2: "___error", a3: "Other textures", a4: 1, a5: 0);
  h = COERCE_FLOAT((int)v3->FindVar(this: v3, a2: "$basetexture", a3: &foundVar, a4: false));
  if ( foundVar )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: a1);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    if ( textureName != nullptr && *textureName != 0 )
    {
      v5 = materials->FindTexture(this: materials, a2: textureName, a3: "Other textures", a4: 0, a5: 0);
      v6 = *(_DWORD *)LODWORD(h);
      x = *(float *)&v5;
      (*(void (__thiscall **)(float, ITexture *))(v6 + 60))(a1: COERCE_FLOAT(LODWORD(h)), a2: v5);
      v7 = (float)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(x) + 12))(a1: COERCE_FLOAT(LODWORD(x))) * scale;
      v8 = *(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(x) + 16);
      w = v7;
      v9 = (float)v8(a1: LODWORD(x)) * scale;
    }
    else
    {
      v9 = scale * 64.0;
      w = scale * 64.0;
    }
    v10 = *(void (__thiscall **)(int, int *, int *, int *, int *))(*(_DWORD *)v4 + 156);
    h = v9;
    v10(a1: v4, a2: &nViewportX, a3: &nViewportY, a4: &nViewportWidth, a5: &nViewportHeight);
    v11 = *(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36);
    x = (float)((float)nViewportWidth - w) * 0.5;
    y = (float)((float)nViewportHeight - h) * 0.5;
    v11(a1: v4, a2: v3, a3: 0);
    v12 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 228))(
                     a1: v4,
                     a2: 1,
                     a3: 0,
                     a4: 0,
                     a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v12;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v12->SetPrimitiveType(this: v12, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v12->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v12, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
    m_pCurrPosition[1] = y;
    m_pCurrPosition[2] = 0.0;
    v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v14[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v15 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v16 = x + w;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = x + w;
    w = v16;
    v15[1] = y;
    v15[2] = 0.0;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v17[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v18 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = w;
    v19 = y + h;
    v18[1] = y + h;
    h = v19;
    v18[2] = 0.0;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v20[1] = 1.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v21 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
    v21[1] = h;
    v21[2] = 0.0;
    v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v22[1] = 1.0;
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
    ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v12->Draw_2(this: v12, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195260
// Name: public: static void CDebugViewRender::Draw2DDebuggingInfo(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDebugViewRender::Draw2DDebuggingInfo(int a1@<ebx>, IMaterial *a2@<esi>, const CViewSetup *view)
{
  IMaterial *v3; // eax
  int m_nValue; // eax
  char *v5; // edx
  char *m_pszString; // eax
  char *v7; // eax
  CLightmapDebugView clientView; // [esp+40h] [ebp-120h] BYREF

  if ( mat_yuv.m_pParent != nullptr && mat_yuv.m_pParent->m_Value.m_nValue != 0 )
  {
    a2 = materials->FindMaterial(this: materials, a2: "debug/yuv", a3: "Other textures", a4: 1, a5: 0);
    if ( a2 != nullptr && !a2->IsErrorMaterial(this: a2) )
      DrawScreenEffectMaterial(pMaterial: a2, x: view->x, y: view->y, w: view->width, h: view->height);
  }
  if ( mat_hsv.m_pParent != nullptr && mat_hsv.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = materials->FindMaterial(this: materials, a2: "debug/hsv", a3: "Other textures", a4: 1, a5: 0);
    a2 = v3;
    if ( v3 != nullptr && !v3->IsErrorMaterial(this: v3) )
      DrawScreenEffectMaterial(pMaterial: a2, x: view->x, y: view->y, w: view->width, h: view->height);
  }
  if ( mat_showlightmappage.m_pParent == nullptr || mat_showlightmappage.m_pParent->m_Value.m_nValue != -1 )
  {
    CRendering3dView::CRendering3dView(this: &clientView, pMainView: (CViewRender *)::view);
    clientView.__vftable = (CLightmapDebugView_vtbl *)&CLightmapDebugView::`vftable';
    CRendering3dView::Setup(this: &clientView, setup: view);
    CLightmapDebugView::Draw(this: &clientView);
    clientView.__vftable = (CLightmapDebugView_vtbl *)&CRendering3dView::`vftable';
    CRendering3dView::ReleaseLists(this: &clientView);
  }
  if ( cl_drawshadowtexture.m_pParent != nullptr && cl_drawshadowtexture.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( cl_shadowtextureoverlaysize.m_pParent != nullptr )
      m_nValue = cl_shadowtextureoverlaysize.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    g_pClientShadowMgr->RenderShadowTexture(this: g_pClientShadowMgr, a2: m_nValue, a3: m_nValue);
  }
  if ( (cl_drawmaterial.m_nFlags & 0x1000) != 0 )
  {
    v5 = "FCVAR_NEVER_AS_STRING";
LABEL_24:
    RenderMaterial(pMaterialName: v5, a2: a1, a3: 4096);
    goto LABEL_25;
  }
  m_pszString = cl_drawmaterial.m_pParent->m_Value.m_pszString;
  if ( m_pszString != nullptr )
  {
    v5 = cl_drawmaterial.m_pParent->m_Value.m_pszString;
    if ( *m_pszString != 0 )
      goto LABEL_24;
  }
LABEL_25:
  if ( mat_showwatertextures.m_pParent != nullptr && mat_showwatertextures.m_pParent->m_Value.m_nValue != 0 )
    OverlayWaterTextures(a1: 4096);
  if ( mat_showcamerarendertarget.m_pParent != nullptr && mat_showcamerarendertarget.m_pParent->m_Value.m_nValue != 0 )
    OverlayCameraRenderTarget(
      a1: 4096,
      pszMaterialName: "debug/debugcamerarendertarget",
      flX: 0.0,
      flY: 0.0,
      w: mat_wateroverlaysize.m_pParent->m_Value.m_fValue,
      h: mat_wateroverlaysize.m_pParent->m_Value.m_fValue);
  if ( mat_showframebuffertexture.m_pParent != nullptr && mat_showframebuffertexture.m_pParent->m_Value.m_nValue != 0 )
  {
    a2 = (IMaterial *)materials->GetRenderContext(this: materials);
    if ( a2 != nullptr )
      ((void (__thiscall *)(IMaterial *))a2->GetPreviewImageProperties)(a1: a2);
    ((void (__thiscall *)(IMaterial *, _DWORD))a2->__vftable[1].WasReloadedFromWhitelist)(a1: a2, a2: 0);
    OverlayFrameBufferTexture(a1: 4096, nFrameBufferIndex: 0);
    OverlayFrameBufferTexture(a1: 4096, nFrameBufferIndex: 1);
    a2->__vftable[2].GetTextureGroupName(this: a2);
    ((void (__thiscall *)(IMaterial *))a2->GetPreviewImage)(a1: a2);
    a2->GetTextureGroupName(this: a2);
  }
  if ( (mat_drawTexture.m_nFlags & 0x1000) != 0 )
  {
    v7 = "FCVAR_NEVER_AS_STRING";
LABEL_40:
    OverlayShowTexture(a1: (int)a2, textureName: v7, scale: mat_drawTextureScale.m_pParent->m_Value.m_fValue);
    goto LABEL_41;
  }
  v7 = mat_drawTexture.m_pParent->m_Value.m_pszString;
  if ( v7 != nullptr && *v7 != 0 )
    goto LABEL_40;
LABEL_41:
  if ( r_flashlightdrawdepth.m_pParent != nullptr && r_flashlightdrawdepth.m_pParent->m_Value.m_nValue != 0 )
    shadowmgr->DrawFlashlightDepthTexture(this: shadowmgr);
}
