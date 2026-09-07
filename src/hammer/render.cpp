// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/render.cpp
// Functions: 56
// ============================================================

#include "hammer\render.h"

//------------------------------------------------------------------------------
// Address: 0x10090380
// Name: public: void CRender::TransformInstanceVector(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::TransformInstanceVector(CRender *this, Vector *In, Vector *Out)
{
  float v3; // xmm0_4

  v3 = 1.0
     / (float)((float)((float)((float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[3][0] * In->x)
                             + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[3][1] * In->y))
                     + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[3][2] * In->z))
             + this->m_CurrentInstanceState.m_InstanceMatrix.m[3][3]);
  Out->x = (float)((float)((float)((float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[0][1] * In->y)
                                 + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[0][0] * In->x))
                         + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[0][2] * In->z))
                 + this->m_CurrentInstanceState.m_InstanceMatrix.m[0][3])
         * v3;
  Out->y = (float)((float)((float)((float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[1][0] * In->x)
                                 + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[1][1] * In->y))
                         + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[1][2] * In->z))
                 + this->m_CurrentInstanceState.m_InstanceMatrix.m[1][3])
         * v3;
  Out->z = (float)((float)((float)((float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[2][0] * In->x)
                                 + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[2][1] * In->y))
                         + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[2][2] * In->z))
                 + this->m_CurrentInstanceState.m_InstanceMatrix.m[2][3])
         * v3;
}

//------------------------------------------------------------------------------
// Address: 0x10090490
// Name: public: struct SInstanceState __near & SInstanceState::operator=(struct SInstanceState const __near &)
// Source: json
//------------------------------------------------------------------------------
SInstanceState *__thiscall SInstanceState::operator=(SInstanceState *this, const SInstanceState *__that)
{
  this->m_pInstanceClass = __that->m_pInstanceClass;
  this->m_InstanceOrigin = __that->m_InstanceOrigin;
  this->m_InstanceAngles = __that->m_InstanceAngles;
  VMatrix::operator=(this: &this->m_InstanceMatrix, mOther: &__that->m_InstanceMatrix);
  VMatrix::operator=(this: &this->m_InstanceRenderMatrix, mOther: &__that->m_InstanceRenderMatrix);
  this->m_bIsEditable = __that->m_bIsEditable;
  this->m_pTopInstanceClass = __that->m_pTopInstanceClass;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090500
// Name: public: void CRender::SetTextColor(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::SetTextColor(
        CRender *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a)
{
  this->m_TextColor._color[0] = r;
  this->m_TextColor._color[1] = g;
  this->m_TextColor._color[2] = b;
  this->m_TextColor._color[3] = a;
  if ( this->m_bIsRenderingIntoVGUI )
    ((void (__thiscall *)(IMatSystemSurface *, _DWORD))g_pMatSystemSurface->DrawSetTextColor)(
      a1: g_pMatSystemSurface,
      a2: *(_DWORD *)&this->m_TextColor);
}

//------------------------------------------------------------------------------
// Address: 0x10090550
// Name: public: void CRender::SetHandleColor(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::SetHandleColor(CRender *this, unsigned __int8 r, unsigned __int8 g, unsigned __int8 b)
{
  this->m_HandleColor._color[0] = r;
  this->m_HandleColor._color[1] = g;
  this->m_HandleColor._color[2] = b;
  this->m_HandleColor._color[3] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10090580
// Name: protected: void CRender::UpdateStudioRenderConfig(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::UpdateStudioRenderConfig(CRender *this, bool bFlat, bool bWireframe)
{
  StudioRenderConfig_t config; // [esp+0h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&config, value: 0, count: sizeof(config));
  config.fullbright = g_materialSystemConfig.nFullbright;
  *((_BYTE *)&config + 36) = (bWireframe << 7) | *((_BYTE *)&config + 36) & 0x61 | (2 * bWireframe) | 0x61;
  *((_BYTE *)&config + 37) = *((_BYTE *)&config + 37) & 0xE6 | 8;
  memset((void *)&config, 0, 16);
  config.drawEntities = 1;
  config.skin = 0;
  g_pStudioRender->UpdateConfig(this: g_pStudioRender, a2: &config);
}

//------------------------------------------------------------------------------
// Address: 0x10090610
// Name: public: class CCamera __near * CRender::GetCamera(void)
// Source: json
//------------------------------------------------------------------------------
CCamera *__thiscall CRender::GetCamera(CRender *this)
{
  return this->m_pView->m_pCamera;
}

//------------------------------------------------------------------------------
// Address: 0x10090620
// Name: public: bool CRender::IsActiveView(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRender::IsActiveView(CRender *this)
{
  return this->m_pView->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x10090630
// Name: public: void CRender::SetDrawColor(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::SetDrawColor(CRender *this, const Color *color)
{
  this->m_DrawColor = *color;
  if ( this->m_bIsRenderingIntoVGUI )
    ((void (__thiscall *)(IMatSystemSurface *, _DWORD))g_pMatSystemSurface->DrawSetColor)(
      a1: g_pMatSystemSurface,
      a2: *(_DWORD *)&this->m_DrawColor);
}

//------------------------------------------------------------------------------
// Address: 0x10090670
// Name: public: void CRender::GetDrawColor(class Color __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::GetDrawColor(CRender *this, Color *color)
{
  *color = this->m_DrawColor;
}

//------------------------------------------------------------------------------
// Address: 0x10090690
// Name: public: void CRender::SetDrawColor(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::SetDrawColor(CRender *this, unsigned __int8 r, unsigned __int8 g, unsigned __int8 b)
{
  unsigned __int8 v5; // cl

  v5 = this->m_DrawColor._color[3];
  this->m_DrawColor._color[0] = r;
  this->m_DrawColor._color[1] = g;
  this->m_DrawColor._color[2] = b;
  this->m_DrawColor._color[3] = v5;
  if ( this->m_bIsRenderingIntoVGUI )
    ((void (__thiscall *)(IMatSystemSurface *, _DWORD))g_pMatSystemSurface->DrawSetColor)(
      a1: g_pMatSystemSurface,
      a2: *(_DWORD *)&this->m_DrawColor);
}

//------------------------------------------------------------------------------
// Address: 0x100906E0
// Name: public: void CRender::SetHandleStyle(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::SetHandleStyle(CRender *this, int size, int type)
{
  this->m_nHandleType = type;
  this->m_nHandleSize = size;
}

//------------------------------------------------------------------------------
// Address: 0x10090700
// Name: public: void CRender::DrawModel(struct DrawModelInfo_t __near *,struct matrix3x4_t __near *,class Vector const __near &,float,bool,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRender::DrawModel(
        CRender *this@<ecx>,
        int a2@<edi>,
        DrawModelInfo_t *pInfo,
        matrix3x4_t *pBoneToWorld,
        const Vector *vOrigin,
        float fAlpha,
        bool bWireFrame,
        const Color *color)
{
  int v9; // edx
  int v10; // eax
  IMaterial *v11; // eax
  int v12; // [esp+8h] [ebp-54h]
  _BYTE v13[56]; // [esp+Ch] [ebp-50h] BYREF
  Vector ViewPoint; // [esp+44h] [ebp-18h] BYREF
  float v15; // [esp+50h] [ebp-Ch] BYREF
  float v16; // [esp+54h] [ebp-8h]
  float v17; // [esp+58h] [ebp-4h]

  if ( !this->m_bRenderingOverEngine
    || g_pFoundryTool == nullptr
    || g_pFoundryTool->ShouldRender3DModels(this: g_pFoundryTool) )
  {
    if ( LOBYTE(AfxGetModuleState()->m_pCurrentWinApp[4].m_dwRef) != 0 )
      g_pStudioRender->GetCurrentConfig(this: g_pStudioRender, a2: (StudioRenderConfig_t *)v13);
    CRender::UpdateStudioRenderConfig(this, bFlat: true, bWireframe: bWireFrame);
    ((void (__stdcall *)(_DWORD, int, int))g_pStudioRender->SetAlphaModulation)(a1: LODWORD(fAlpha), a2, a3: v12);
    v9 = color->_color[1];
    v10 = color->_color[2];
    v15 = (float)color->_color[0] * 0.0039215689;
    v16 = (float)v9 * 0.0039215689;
    v17 = (float)v10 * 0.0039215689;
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: &v15);
    CCamera::GetViewPoint(this: this->m_pView->m_pCamera, &ViewPoint);
    g_pStudioRender->SetEyeViewTarget(this: g_pStudioRender, a2: pInfo->m_pStudioHdr, a3: pInfo->m_Body, a4: &ViewPoint);
    if ( this->m_bRenderingOverEngine )
    {
      v11 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, const char *, int))materials->FindMaterial)(
                           a1: materials,
                           a2: "models/editor/white_model_outline",
                           a3: "Other textures",
                           a4: 1);
      g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: v11, a3: OVERRIDE_NORMAL);
      ((void (__stdcall *)(int))g_pStudioRender->SetAlphaModulation)(a1: 1050253722);
      g_pStudioRender->DrawModel(
        this: g_pStudioRender,
        a2: nullptr,
        a3: pInfo,
        a4: pBoneToWorld,
        a5: nullptr,
        a6: nullptr,
        a7: vOrigin,
        a8: 0);
      ((void (__stdcall *)(int))g_pStudioRender->SetAlphaModulation)(a1: 1065353216);
      g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: nullptr, a3: OVERRIDE_NORMAL);
    }
    else
    {
      ((void (__thiscall *)(IStudioRender *, _DWORD, DrawModelInfo_t *, matrix3x4_t *, _DWORD, _DWORD, const Vector *))g_pStudioRender->DrawModel)(
        a1: g_pStudioRender,
        a2: 0,
        a3: pInfo,
        a4: pBoneToWorld,
        a5: 0,
        a6: 0,
        a7: vOrigin);
    }
    ((void (__cdecl *)(int, _DWORD))g_pStudioRender->SetAlphaModulation)(a1: 1065353216, a2: 0);
    v17 = 1.0;
    v16 = 1.0;
    v15 = 1.0;
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: &v15);
    this->SetRenderMode(this, a2: RENDER_MODE_CURRENT, a3: true);
    if ( LOBYTE(AfxGetModuleState()->m_pCurrentWinApp[4].m_dwRef) != 0 )
      g_pStudioRender->UpdateConfig(this: g_pStudioRender, a2: (const StudioRenderConfig_t *)v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090930
// Name: protected: bool CRender::GetRequiredMaterial(char const __near *,class IMaterial __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRender::GetRequiredMaterial(CRender *this, const char *pName, IMaterial **pMaterial)
{
  IEditorTexture *ActiveTexture; // eax
  char str[512]; // [esp+8h] [ebp-200h] BYREF

  *pMaterial = nullptr;
  ActiveTexture = CTextureSystem::FindActiveTexture(this: &g_Textures, pszInputName: pName, piIndex: nullptr, bDummy: 1);
  if ( ActiveTexture != nullptr )
    *pMaterial = ActiveTexture->GetMaterial(this: ActiveTexture, a2: true);
  if ( *pMaterial != nullptr )
    return 1;
  V_snprintf(
    pDest: str,
    maxLen: 512,
    pFormat: "Missing material '%s'. Go to Tools | Options | Game Configurations and verify that your game directory is correct.",
    pName);
  MessageBoxA(hWnd: nullptr, lpText: str, lpCaption: "FATAL ERROR", uType: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100909B0
// Name: public: void CRender::SetDefaultRenderMode(enum EditorRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::SetDefaultRenderMode(CRender *this, EditorRenderMode_t eRenderMode)
{
  this->m_eDefaultRenderMode = eRenderMode;
}

//------------------------------------------------------------------------------
// Address: 0x100909C0
// Name: public: void CRender::GetViewForward(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::GetViewForward(CRender *this, Vector *ViewForward)
{
  ViewForward->x = -this->m_CurrentMatrix.m[2][0];
  ViewForward->y = -this->m_CurrentMatrix.m[2][1];
  ViewForward->z = -this->m_CurrentMatrix.m[2][2];
}

//------------------------------------------------------------------------------
// Address: 0x10090A10
// Name: public: void CRender::GetViewUp(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::GetViewUp(CRender *this, Vector *ViewUp)
{
  *ViewUp = *(Vector *)&this->m_CurrentMatrix.m[1][0];
}

//------------------------------------------------------------------------------
// Address: 0x10090A40
// Name: public: void CRender::GetViewRight(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::GetViewRight(CRender *this, Vector *ViewRight)
{
  ViewRight->x = this->m_CurrentMatrix.m[0][0];
  ViewRight->y = this->m_CurrentMatrix.m[0][1];
  ViewRight->z = this->m_CurrentMatrix.m[0][2];
}

//------------------------------------------------------------------------------
// Address: 0x10090A70
// Name: public: void CRender::DrawLine(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRender::DrawLine(
        CRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *vStart,
        const Vector *vEnd)
{
  IMesh *m_pMesh; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  unsigned int m_nIndexSize; // edx
  float *v10; // eax
  float *v11; // eax
  int v12; // eax
  int v14; // [esp-28h] [ebp-34h]
  int v15; // [esp-24h] [ebp-30h]
  int v16; // [esp-10h] [ebp-1Ch]
  int v17; // [esp-Ch] [ebp-18h]
  int v18; // [esp-8h] [ebp-14h]
  IMesh *v19; // [esp-4h] [ebp-10h]

  m_pMesh = this->m_pMesh;
  v7 = s_fOneUnitLength * 16.0;
  v8 = fsqrt(
         (float)((float)((float)(vEnd->y - vStart->y) * (float)(vEnd->y - vStart->y))
               + (float)((float)(vEnd->z - vStart->z) * (float)(vEnd->z - vStart->z)))
       + (float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)));
  this->meshBuilder.m_bGenerateIndices = true;
  this->meshBuilder.m_Type = MATERIAL_LINES;
  this->meshBuilder.m_pMesh = m_pMesh;
  ((void (__stdcall *)(int, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, IMesh *))m_pMesh->SetPrimitiveType)(
    a1: 1,
    a2,
    a3,
    a4: v14,
    a5: v15,
    a6: LODWORD(v8),
    a7: 0,
    a8: 0,
    a9: 0,
    a10: v16,
    a11: v17,
    a12: v8 / v7,
    a13: m_pMesh);
  this->meshBuilder.m_pMesh->LockMesh(
    this: this->meshBuilder.m_pMesh,
    a2: 2,
    a3: 2,
    a4: &this->meshBuilder,
    a5: nullptr);
  this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v19->IIndexBuffer;
  this->meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  this->meshBuilder.m_IndexBuilder.m_bModify = false;
  this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
  this->meshBuilder.m_IndexBuilder.m_nIndexOffset = this->meshBuilder.m_nFirstVertex;
  this->meshBuilder.m_IndexBuilder.m_pIndices = this->meshBuilder.m_pIndices;
  m_nIndexSize = this->meshBuilder.m_nIndexSize;
  this->meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  this->meshBuilder.m_IndexBuilder.m_nIndexSize = m_nIndexSize;
  CVertexBuilder::AttachBegin(
    this: &this->meshBuilder.m_VertexBuilder,
    pMesh: v19,
    nMaxVertexCount: 2,
    desc: &this->meshBuilder);
  this->meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->meshBuilder.m_VertexBuilder);
  *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = *vStart;
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                            | ((this->m_DrawColor._color[1]
                                                              | ((this->m_DrawColor._color[0]
                                                                | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
  v10 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *v10 = 0.0;
  v10[1] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = *vEnd;
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                            | ((this->m_DrawColor._color[1]
                                                              | ((this->m_DrawColor._color[0]
                                                                | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
  v11 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *(_DWORD *)v11 = v18;
  *((_DWORD *)v11 + 1) = v18;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  if ( this->meshBuilder.m_bGenerateIndices )
  {
    v12 = CMeshBuilder::IndicesFromVertices(
            this: &this->meshBuilder,
            type: this->meshBuilder.m_Type,
            nVertexCount: this->meshBuilder.m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(
      this: &this->meshBuilder.m_IndexBuilder,
      primitiveType: this->meshBuilder.m_Type,
      nIndexCount: v12);
  }
  this->meshBuilder.m_pMesh->UnlockMesh(
    this: this->meshBuilder.m_pMesh,
    a2: this->meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: this->meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &this->meshBuilder);
  this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  this->meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  this->meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  this->meshBuilder.m_pMesh = nullptr;
  this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10090D10
// Name: public: void CRender::DrawCircle(class Vector const __near &,class Vector const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRender::DrawCircle(
        CRender *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        const Vector *vCenter,
        const Vector *vNormal,
        float flRadius,
        int nSegments)
{
  IMesh *m_pMesh; // eax
  int v9; // ebx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float x; // xmm6_4
  float *m_pCurrPosition; // eax
  MaterialPrimitiveType_t m_Type; // ecx
  int m_nVertexCount; // eax
  long double v21; // [esp-8h] [ebp-28h]
  long double v22; // [esp-8h] [ebp-28h]
  Vector vx; // [esp+4h] [ebp-1Ch] BYREF
  Vector vy; // [esp+10h] [ebp-10h] BYREF
  float ca; // [esp+1Ch] [ebp-4h]
  float invDelta; // [esp+2Ch] [ebp+Ch]

  if ( BuildAxesFromNormal(vNormal, vHorz: &vx, vVert: &vy) != 0 )
  {
    m_pMesh = this->m_pMesh;
    vx.x = vx.x * flRadius;
    vx.y = vx.y * flRadius;
    vx.z = vx.z * flRadius;
    v21 = COERCE_DOUBLE(__PAIR64__(a2, a3));
    vy.x = vy.x * flRadius;
    vy.y = vy.y * flRadius;
    vy.z = vy.z * flRadius;
    CMeshBuilder::Begin(this: &this->meshBuilder, pMesh: m_pMesh, type: MATERIAL_LINE_LOOP, numPrimitives: nSegments);
    v9 = 0;
    for ( invDelta = 6.283185307179586 / (double)nSegments; v9 < nSegments; ++v9 )
    {
      __libm_sse2_cos(x: v21);
      ca = (float)v9 * invDelta;
      __libm_sse2_sin(x: v22);
      v10 = (float)v9 * invDelta;
      v11 = vy.x * v10;
      v12 = vy.z * v10;
      v13 = vy.y * v10;
      v14 = (float)(vx.y * ca) + vCenter->y;
      v15 = (float)(vx.z * ca) + vCenter->z;
      v16 = vx.x * ca;
      x = vCenter->x;
      *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                                | ((this->m_DrawColor._color[1]
                                                                  | ((this->m_DrawColor._color[0]
                                                                    | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
      m_pCurrPosition = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *m_pCurrPosition = v11 + (float)(x + v16);
      m_pCurrPosition[1] = v14 + v13;
      m_pCurrPosition[2] = v15 + v12;
      CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    }
    if ( this->meshBuilder.m_bGenerateIndices )
    {
      m_Type = this->meshBuilder.m_Type;
      m_nVertexCount = this->meshBuilder.m_VertexBuilder.m_nVertexCount;
      switch ( m_Type )
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
        this: &this->meshBuilder.m_IndexBuilder,
        primitiveType: m_Type,
        nIndexCount: m_nVertexCount);
    }
    this->meshBuilder.m_pMesh->UnlockMesh(
      this: this->meshBuilder.m_pMesh,
      a2: this->meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: this->meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &this->meshBuilder);
    this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    this->meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    this->meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    this->meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    this->meshBuilder.m_pMesh = nullptr;
    this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090F90
// Name: protected: void CRender::DrawCircle(class Vector2D __near &,float,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawCircle(
        CRender *this,
        Vector2D *vCenter,
        float fRadius,
        int nSegments,
        unsigned __int8 *pColor)
{
  CMeshBuilder *p_meshBuilder; // edi
  int v6; // ebx
  float v7; // xmm0_4
  float *m_pCurrPosition; // eax
  MaterialPrimitiveType_t m_Type; // esi
  int m_nVertexCount; // eax
  long double v11; // [esp+0h] [ebp-18h]
  long double v12; // [esp+0h] [ebp-18h]
  float x; // [esp+Ch] [ebp-Ch]
  float invDelta; // [esp+10h] [ebp-8h]

  p_meshBuilder = &this->meshBuilder;
  CMeshBuilder::Begin(
    this: &this->meshBuilder,
    pMesh: this->m_pMesh,
    type: MATERIAL_LINE_LOOP,
    numPrimitives: nSegments);
  v6 = 0;
  for ( invDelta = 6.283185307179586 / (double)nSegments; v6 < nSegments; ++v6 )
  {
    __libm_sse2_cos(x: v11);
    x = (float)((float)((float)v6 * invDelta) * fRadius) + vCenter->x;
    __libm_sse2_sin(x: v12);
    v7 = (float)((float)((float)v6 * invDelta) * fRadius) + vCenter->y;
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                              | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    m_pCurrPosition = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *m_pCurrPosition = x;
    m_pCurrPosition[1] = v7;
    m_pCurrPosition[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  }
  if ( p_meshBuilder->m_bGenerateIndices )
  {
    m_Type = p_meshBuilder->m_Type;
    m_nVertexCount = p_meshBuilder->m_VertexBuilder.m_nVertexCount;
    switch ( m_Type )
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
      this: &p_meshBuilder->m_IndexBuilder,
      primitiveType: m_Type,
      nIndexCount: m_nVertexCount);
  }
  p_meshBuilder->m_pMesh->UnlockMesh(
    this: p_meshBuilder->m_pMesh,
    a2: p_meshBuilder->m_VertexBuilder.m_nVertexCount,
    a3: p_meshBuilder->m_IndexBuilder.m_nIndexCount,
    a4: p_meshBuilder);
  p_meshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
  p_meshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
  p_meshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
  p_meshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
  p_meshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  p_meshBuilder->m_pMesh = nullptr;
  this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10091160
// Name: protected: void CRender::DrawCross(class Vector2D __near &,class Vector2D __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawCross(CRender *this, Vector2D *ul, Vector2D *lr, unsigned __int8 *pColor)
{
  IMesh *m_pMesh; // edi
  CMeshBuilder *p_meshBuilder; // esi
  float y; // xmm0_4
  float *m_pCurrPosition; // eax
  float v9; // xmm0_4
  float *v10; // eax
  float *v11; // eax
  float v12; // xmm0_4
  float *v13; // eax
  float v14; // xmm0_4
  MaterialPrimitiveType_t m_Type; // edi
  int v16; // eax

  m_pMesh = this->m_pMesh;
  p_meshBuilder = &this->meshBuilder;
  this->meshBuilder.m_bGenerateIndices = true;
  this->meshBuilder.m_Type = MATERIAL_LINES;
  this->meshBuilder.m_pMesh = m_pMesh;
  m_pMesh->SetPrimitiveType(this: m_pMesh, a2: MATERIAL_LINES);
  p_meshBuilder->m_pMesh->LockMesh(this: p_meshBuilder->m_pMesh, a2: 4, a3: 4, a4: p_meshBuilder, a5: nullptr);
  p_meshBuilder->m_IndexBuilder.m_pIndexBuffer = &m_pMesh->IIndexBuffer;
  p_meshBuilder->m_IndexBuilder.m_nIndexCount = 0;
  p_meshBuilder->m_IndexBuilder.m_nMaxIndexCount = 4;
  p_meshBuilder->m_IndexBuilder.m_bModify = false;
  p_meshBuilder->m_IndexBuilder.m_nIndexOffset = p_meshBuilder->m_nFirstVertex;
  p_meshBuilder->m_IndexBuilder.m_pIndices = p_meshBuilder->m_pIndices;
  p_meshBuilder->m_IndexBuilder.m_nIndexSize = p_meshBuilder->m_nIndexSize;
  p_meshBuilder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(
    this: &p_meshBuilder->m_VertexBuilder,
    pMesh: m_pMesh,
    nMaxVertexCount: 4,
    desc: p_meshBuilder);
  p_meshBuilder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &p_meshBuilder->m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  y = ul->y;
  m_pCurrPosition = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = ul->x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v9 = lr->y;
  v10 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *v10 = lr->x;
  v10[1] = v9;
  v10[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v11 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v12 = lr->y - 1.0;
  *v11 = ul->x;
  v11[1] = v12;
  v11[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v13 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v14 = ul->y - 1.0;
  *v13 = lr->x;
  v13[1] = v14;
  v13[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  if ( p_meshBuilder->m_bGenerateIndices )
  {
    m_Type = p_meshBuilder->m_Type;
    v16 = CMeshBuilder::IndicesFromVertices(
            this: p_meshBuilder,
            type: m_Type,
            nVertexCount: p_meshBuilder->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &p_meshBuilder->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v16);
  }
  p_meshBuilder->m_pMesh->UnlockMesh(
    this: p_meshBuilder->m_pMesh,
    a2: p_meshBuilder->m_VertexBuilder.m_nVertexCount,
    a3: p_meshBuilder->m_IndexBuilder.m_nIndexCount,
    a4: p_meshBuilder);
  p_meshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
  p_meshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
  p_meshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
  p_meshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
  p_meshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  p_meshBuilder->m_pMesh = nullptr;
  this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10091400
// Name: protected: void CRender::DrawRect(class Vector2D __near &,class Vector2D __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawRect(CRender *this, Vector2D *ul, Vector2D *lr, unsigned __int8 *pColor)
{
  CMeshBuilder *p_meshBuilder; // ebx
  float y; // xmm0_4
  float *m_pCurrPosition; // eax
  float *v8; // eax
  float *v9; // eax
  float v10; // xmm2_4
  float *v11; // eax
  float v12; // xmm2_4
  float *v13; // eax
  float *v14; // eax
  float v15; // xmm2_4
  float *v16; // eax
  float *v17; // eax
  MaterialPrimitiveType_t m_Type; // edi
  int v19; // eax
  float vScale; // [esp+0h] [ebp-10h]
  float vScale_4; // [esp+4h] [ebp-Ch]

  p_meshBuilder = &this->meshBuilder;
  vScale = (float)(lr->x - ul->x) * 0.0625;
  vScale_4 = (float)(lr->y - ul->y) * 0.0625;
  CMeshBuilder::Begin(this: &this->meshBuilder, pMesh: this->m_pMesh, type: MATERIAL_LINE_LOOP, numPrimitives: 4);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  y = ul->y;
  m_pCurrPosition = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = ul->x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = 0.0;
  v8 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *v8 = 0.0;
  v8[1] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v9 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v10 = ul->y;
  *v9 = lr->x;
  v9[1] = v10;
  v9[2] = 0.0;
  v11 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *v11 = vScale;
  v11[1] = vScale;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v12 = lr->y;
  v13 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *v13 = lr->x;
  v13[1] = v12;
  v13[2] = 0.0;
  v14 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *v14 = vScale_4 + vScale;
  v14[1] = vScale - vScale_4;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v15 = lr->y;
  v16 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *v16 = ul->x;
  v16[1] = v15;
  v16[2] = 0.0;
  v17 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *v17 = (float)(vScale_4 + vScale) - vScale;
  v17[1] = (float)(vScale - vScale_4) - vScale;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  if ( p_meshBuilder->m_bGenerateIndices )
  {
    m_Type = p_meshBuilder->m_Type;
    v19 = CMeshBuilder::IndicesFromVertices(
            this: p_meshBuilder,
            type: m_Type,
            nVertexCount: p_meshBuilder->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &p_meshBuilder->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v19);
  }
  p_meshBuilder->m_pMesh->UnlockMesh(
    this: p_meshBuilder->m_pMesh,
    a2: p_meshBuilder->m_VertexBuilder.m_nVertexCount,
    a3: p_meshBuilder->m_IndexBuilder.m_nIndexCount,
    a4: p_meshBuilder);
  p_meshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
  p_meshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
  p_meshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
  p_meshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
  p_meshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  p_meshBuilder->m_pMesh = nullptr;
  this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100916B0
// Name: public: void CRender::DrawFilledRect(class Vector2D __near &,class Vector2D __near &,unsigned char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawFilledRect(
        CRender *this,
        Vector2D *ul,
        Vector2D *lr,
        unsigned __int8 *pColor,
        bool bBorder)
{
  IMesh *m_pMesh; // ebx
  BOOL v7; // eax
  unsigned int m_nIndexSize; // edx
  float y; // xmm0_4
  float *m_pCurrPosition; // eax
  float v11; // xmm0_4
  float *v12; // eax
  float v13; // xmm0_4
  float *v14; // eax
  float v15; // xmm0_4
  float *v16; // eax
  float v17; // xmm0_4
  float *v18; // eax
  float *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm0_4
  float *v22; // eax
  float v23; // xmm0_4
  float *v24; // eax
  MaterialPrimitiveType_t m_Type; // ebx
  int v26; // eax
  int nMaxVertexCount; // [esp+Ch] [ebp-14h]
  int v28; // [esp+10h] [ebp-10h]

  if ( (_S2_2 & 1) == 0 )
  {
    _S2_2 |= 1u;
    black = (Color)-16777216;
  }
  m_pMesh = this->m_pMesh;
  v7 = bBorder;
  this->meshBuilder.m_bGenerateIndices = true;
  this->meshBuilder.m_pMesh = m_pMesh;
  this->meshBuilder.m_Type = MATERIAL_QUADS;
  nMaxVertexCount = 4 * v7 + 4;
  v28 = 2 * (3 * v7 + 3);
  m_pMesh->SetPrimitiveType(this: m_pMesh, a2: MATERIAL_TRIANGLES);
  this->meshBuilder.m_pMesh->LockMesh(
    this: this->meshBuilder.m_pMesh,
    a2: nMaxVertexCount,
    a3: v28,
    a4: &this->meshBuilder,
    a5: nullptr);
  this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = &m_pMesh->IIndexBuffer;
  this->meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v28;
  this->meshBuilder.m_IndexBuilder.m_bModify = false;
  this->meshBuilder.m_IndexBuilder.m_nIndexOffset = this->meshBuilder.m_nFirstVertex;
  this->meshBuilder.m_IndexBuilder.m_pIndices = this->meshBuilder.m_pIndices;
  m_nIndexSize = this->meshBuilder.m_nIndexSize;
  this->meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  this->meshBuilder.m_IndexBuilder.m_nIndexSize = m_nIndexSize;
  CVertexBuilder::AttachBegin(
    this: &this->meshBuilder.m_VertexBuilder,
    pMesh: m_pMesh,
    nMaxVertexCount,
    desc: &this->meshBuilder);
  this->meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->meshBuilder.m_VertexBuilder);
  if ( bBorder )
  {
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = black._color[2]
                                                              | ((black._color[1]
                                                                | ((black._color[0] | (black._color[3] << 8)) << 8)) << 8);
    y = ul->y;
    m_pCurrPosition = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *m_pCurrPosition = ul->x;
    m_pCurrPosition[1] = y;
    m_pCurrPosition[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = black._color[2]
                                                              | ((black._color[1]
                                                                | ((black._color[0] | (black._color[3] << 8)) << 8)) << 8);
    v11 = ul->y;
    v12 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *v12 = lr->x;
    v12[1] = v11;
    v12[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = black._color[2]
                                                              | ((black._color[1]
                                                                | ((black._color[0] | (black._color[3] << 8)) << 8)) << 8);
    v13 = lr->y;
    v14 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *v14 = lr->x;
    v14[1] = v13;
    v14[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = black._color[2]
                                                              | ((black._color[1]
                                                                | ((black._color[0] | (black._color[3] << 8)) << 8)) << 8);
    v15 = lr->y;
    v16 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *v16 = ul->x;
    v16[1] = v15;
    v16[2] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    ul->x = ul->x + 1.0;
    ul->y = ul->y + 1.0;
    lr->x = lr->x - 1.0;
    lr->y = lr->y - 1.0;
  }
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v17 = ul->y;
  v18 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *v18 = ul->x;
  v18[1] = v17;
  v18[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v19 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v20 = ul->y;
  *v19 = lr->x;
  v19[1] = v20;
  v19[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v21 = lr->y;
  v22 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *v22 = lr->x;
  v22[1] = v21;
  v22[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = pColor[2]
                                                            | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
  v23 = lr->y;
  v24 = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *v24 = ul->x;
  v24[1] = v23;
  v24[2] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  if ( this->meshBuilder.m_bGenerateIndices )
  {
    m_Type = this->meshBuilder.m_Type;
    v26 = CMeshBuilder::IndicesFromVertices(
            this: &this->meshBuilder,
            type: m_Type,
            nVertexCount: this->meshBuilder.m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &this->meshBuilder.m_IndexBuilder, primitiveType: m_Type, nIndexCount: v26);
  }
  this->meshBuilder.m_pMesh->UnlockMesh(
    this: this->meshBuilder.m_pMesh,
    a2: this->meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: this->meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &this->meshBuilder);
  this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  this->meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  this->meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  this->meshBuilder.m_pMesh = nullptr;
  this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10091B60
// Name: public: virtual bool CRender::SetView(class CMapView __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRender::SetView(CRender *this, CMapView *pView)
{
  IMaterial *v3; // eax
  IMaterial *v4; // ecx
  IMaterial *v5; // edx

  this->m_pView = pView;
  if ( CRender::GetRequiredMaterial(this, pName: "editor/wireframe", pMaterial: this->m_pWireframe) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/flat", pMaterial: this->m_pFlat) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/flatdecal", pMaterial: &this->m_pFlat[1]) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/translucentflat", pMaterial: this->m_pTranslucentFlat) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/translucentflatdecal", pMaterial: &this->m_pTranslucentFlat[1]) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/lightmapgrid", pMaterial: this->m_pLightmapGrid) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/lightmapgriddecal", pMaterial: &this->m_pLightmapGrid[1]) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/selectionoverlay", pMaterial: this->m_pSelectionOverlay) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/flatignorez", pMaterial: this->m_pFlatNoZ) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/flatnocull", pMaterial: this->m_pFlatNoCull) == 0
    || CRender::GetRequiredMaterial(this, pName: "editor/dotted", pMaterial: this->m_pDotted) == 0 )
  {
    return 0;
  }
  v3 = this->m_pFlatNoCull[0];
  v4 = this->m_pDotted[0];
  this->m_pFlatNoZ[1] = this->m_pFlatNoZ[0];
  v5 = this->m_pSelectionOverlay[0];
  this->m_pFlatNoCull[1] = v3;
  this->m_pWireframe[1] = v4;
  this->m_pSelectionOverlay[1] = v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091CD0
// Name: public: void CRender::DrawPolyLine(int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawPolyLine(CRender *this, int nPoints, const Vector *Points)
{
  CMeshBuilder *p_meshBuilder; // ebx
  float *p_y; // edi
  float *m_pCurrPosition; // eax
  MaterialPrimitiveType_t m_Type; // edi
  int m_nVertexCount; // eax

  p_meshBuilder = &this->meshBuilder;
  CMeshBuilder::Begin(this: &this->meshBuilder, pMesh: this->m_pMesh, type: MATERIAL_LINE_LOOP, numPrimitives: nPoints);
  if ( nPoints > 0 )
  {
    p_y = &Points->y;
    do
    {
      m_pCurrPosition = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *m_pCurrPosition = *(p_y - 1);
      m_pCurrPosition[1] = *p_y;
      m_pCurrPosition[2] = p_y[1];
      *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                                | ((this->m_DrawColor._color[1]
                                                                  | ((this->m_DrawColor._color[0]
                                                                    | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
      CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
      p_y += 3;
      --nPoints;
    }
    while ( nPoints != 0 );
  }
  if ( p_meshBuilder->m_bGenerateIndices )
  {
    m_Type = p_meshBuilder->m_Type;
    m_nVertexCount = p_meshBuilder->m_VertexBuilder.m_nVertexCount;
    switch ( m_Type )
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
      this: &p_meshBuilder->m_IndexBuilder,
      primitiveType: m_Type,
      nIndexCount: m_nVertexCount);
  }
  p_meshBuilder->m_pMesh->UnlockMesh(
    this: p_meshBuilder->m_pMesh,
    a2: p_meshBuilder->m_VertexBuilder.m_nVertexCount,
    a3: p_meshBuilder->m_IndexBuilder.m_nIndexCount,
    a4: p_meshBuilder);
  p_meshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
  p_meshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
  p_meshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
  p_meshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
  p_meshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  p_meshBuilder->m_pMesh = nullptr;
  this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10091E30
// Name: public: void CRender::DrawDisplacement(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawDisplacement(CRender *this, CCoreDispInfo *pMapDisp)
{
  int v3; // esi
  Color m_DrawColor; // eax
  int v5; // ecx
  float *p_z; // esi
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // eax
  float *v9; // eax
  float *v10; // eax
  float *v11; // eax
  float *v12; // eax
  unsigned __int16 *m_RenderIndices; // ebx
  int i; // eax
  int m_nCurrentIndex; // ecx
  MaterialPrimitiveType_t m_Type; // ebx
  int m_nVertexCount; // eax
  int v18; // [esp+Ch] [ebp-18h]
  int numIndices; // [esp+10h] [ebp-14h]
  int numVerts; // [esp+14h] [ebp-10h]
  int v21; // [esp+18h] [ebp-Ch]
  __int16 color_2; // [esp+1Eh] [ebp-6h]
  bool bWireFrame; // [esp+23h] [ebp-1h]

  numIndices = pMapDisp->m_RenderIndexCount;
  v3 = ((1 << pMapDisp->m_Power) + 1) * ((1 << pMapDisp->m_Power) + 1);
  numVerts = v3;
  bWireFrame = this->m_eCurrentRenderMode == RENDER_MODE_WIREFRAME;
  CMeshBuilder::Begin(
    this: &this->meshBuilder,
    pMesh: this->m_pMesh,
    type: MATERIAL_TRIANGLES,
    nVertexCount: v3,
    nIndexCount: numIndices,
    pMeshSettings: nullptr);
  m_DrawColor = this->m_DrawColor;
  color_2 = *(_WORD *)&m_DrawColor._color[2];
  if ( v3 > 0 )
  {
    v5 = m_DrawColor._color[0];
    p_z = &pMapDisp->m_pVerts->m_Vert.z;
    v18 = m_DrawColor._color[0];
    v21 = m_DrawColor._color[1];
    while ( 1 )
    {
      m_pCurrPosition = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *m_pCurrPosition = *(p_z - 2);
      m_pCurrPosition[1] = *(p_z - 1);
      m_pCurrPosition[2] = *p_z;
      if ( bWireFrame )
      {
        *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)color_2
                                                                  | ((v21 | ((v5 | (HIBYTE(color_2) << 8)) << 8)) << 8);
      }
      else
      {
        *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)color_2
                                                                  | ((v21
                                                                    | ((v5 | ((unsigned __int8)(-1 - (int)p_z[23]) << 8)) << 8)) << 8);
        m_pCurrNormal = this->meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *m_pCurrNormal = p_z[4];
        m_pCurrNormal[1] = p_z[5];
        m_pCurrNormal[2] = p_z[6];
        v9 = (float *)((char *)this->meshBuilder.m_VertexBuilder.m_pTangentS
                     + this->meshBuilder.m_VertexBuilder.m_nCurrentVertex
                     * this->meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
        *v9 = p_z[7];
        v9[1] = p_z[8];
        v9[2] = p_z[9];
        v10 = (float *)((char *)this->meshBuilder.m_VertexBuilder.m_pTangentT
                      + this->meshBuilder.m_VertexBuilder.m_nCurrentVertex
                      * this->meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
        *v10 = p_z[10];
        v10[1] = p_z[11];
        v10[2] = p_z[12];
      }
      v11 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *v11 = p_z[13];
      v11[1] = p_z[14];
      v12 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *v12 = p_z[15];
      v12[1] = p_z[16];
      CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
      p_z += 56;
      if ( --numVerts == 0 )
        break;
      v5 = v18;
    }
  }
  m_RenderIndices = pMapDisp->m_RenderIndices;
  for ( i = 0; i < numIndices; ++i )
  {
    this->meshBuilder.m_IndexBuilder.m_pIndices[this->meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(this->meshBuilder.m_IndexBuilder.m_nIndexOffset) + m_RenderIndices[i];
    this->meshBuilder.m_IndexBuilder.m_nCurrentIndex += this->meshBuilder.m_IndexBuilder.m_nIndexSize;
    m_nCurrentIndex = this->meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    if ( m_nCurrentIndex > this->meshBuilder.m_IndexBuilder.m_nIndexCount )
      this->meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
  }
  if ( this->meshBuilder.m_bGenerateIndices )
  {
    m_Type = this->meshBuilder.m_Type;
    m_nVertexCount = this->meshBuilder.m_VertexBuilder.m_nVertexCount;
    switch ( m_Type )
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
      this: &this->meshBuilder.m_IndexBuilder,
      primitiveType: m_Type,
      nIndexCount: m_nVertexCount);
  }
  this->meshBuilder.m_pMesh->UnlockMesh(
    this: this->meshBuilder.m_pMesh,
    a2: this->meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: this->meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &this->meshBuilder);
  this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  this->meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  this->meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  this->meshBuilder.m_pMesh = nullptr;
  this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100920E0
// Name: public: virtual void CRender::DrawBox(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRender::DrawBox(
        CRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const Vector *vMins,
        const Vector *vMaxs,
        bool bFill)
{
  int v7; // eax
  IMesh *m_pMesh; // ecx
  unsigned int m_nIndexSize; // edx
  MaterialPrimitiveType_t m_Type; // ebx
  int v11; // eax
  Vector points[8]; // [esp+4h] [ebp-60h] BYREF
  IMesh *bFilla; // [esp+74h] [ebp+10h]

  PointsFromBox(mins: vMins, maxs: vMaxs, points);
  if ( !bFill )
  {
    CMeshBuilder::Begin(this: &this->meshBuilder, pMesh: this->m_pMesh, type: MATERIAL_LINE_STRIP, numPrimitives: 9);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[0];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[1];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[3];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[2];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[6];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[7];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[5];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[4];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[0];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[2];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    if ( this->meshBuilder.m_bGenerateIndices )
    {
      v7 = CMeshBuilder::IndicesFromVertices(
             this: &this->meshBuilder,
             type: this->meshBuilder.m_Type,
             nVertexCount: this->meshBuilder.m_VertexBuilder.m_nVertexCount);
      CIndexBuilder::GenerateIndices(
        this: &this->meshBuilder.m_IndexBuilder,
        primitiveType: this->meshBuilder.m_Type,
        nIndexCount: v7);
    }
    ((void (__thiscall *)(IMesh *, int, int, CMeshBuilder *, int, int))this->meshBuilder.m_pMesh->UnlockMesh)(
      a1: this->meshBuilder.m_pMesh,
      a2: this->meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: this->meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &this->meshBuilder,
      a5: a3,
      a6: a2);
    this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    this->meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    this->meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    this->meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    this->meshBuilder.m_pMesh = nullptr;
    this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
    m_pMesh = this->m_pMesh;
    this->meshBuilder.m_bGenerateIndices = true;
    this->meshBuilder.m_Type = MATERIAL_LINES;
    this->meshBuilder.m_pMesh = m_pMesh;
    bFilla = m_pMesh;
    ((void (__stdcall *)(int))m_pMesh->SetPrimitiveType)(a1: 1);
    this->meshBuilder.m_pMesh->LockMesh(
      this: this->meshBuilder.m_pMesh,
      a2: 6,
      a3: 6,
      a4: &this->meshBuilder,
      a5: nullptr);
    this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = &bFilla->IIndexBuffer;
    this->meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    this->meshBuilder.m_IndexBuilder.m_bModify = false;
    this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    this->meshBuilder.m_IndexBuilder.m_nIndexOffset = this->meshBuilder.m_nFirstVertex;
    this->meshBuilder.m_IndexBuilder.m_pIndices = this->meshBuilder.m_pIndices;
    m_nIndexSize = this->meshBuilder.m_nIndexSize;
    this->meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    this->meshBuilder.m_IndexBuilder.m_nIndexSize = m_nIndexSize;
    CVertexBuilder::AttachBegin(
      this: &this->meshBuilder.m_VertexBuilder,
      pMesh: bFilla,
      nMaxVertexCount: 6,
      desc: &this->meshBuilder);
    this->meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[4];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[6];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[1];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[5];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[3];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[7];
    *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                              | ((this->m_DrawColor._color[1]
                                                                | ((this->m_DrawColor._color[0]
                                                                  | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
    if ( this->meshBuilder.m_bGenerateIndices )
    {
      m_Type = this->meshBuilder.m_Type;
      v11 = CMeshBuilder::IndicesFromVertices(
              this: &this->meshBuilder,
              type: m_Type,
              nVertexCount: this->meshBuilder.m_VertexBuilder.m_nVertexCount);
      CIndexBuilder::GenerateIndices(this: &this->meshBuilder.m_IndexBuilder, primitiveType: m_Type, nIndexCount: v11);
    }
    ((void (__thiscall *)(IMesh *, int))this->meshBuilder.m_pMesh->UnlockMesh)(
      a1: this->meshBuilder.m_pMesh,
      a2: this->meshBuilder.m_VertexBuilder.m_nVertexCount);
    this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    this->meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    this->meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    this->meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    this->meshBuilder.m_pMesh = nullptr;
    this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100928F0
// Name: public: void CRender::BindTexture(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::BindTexture(CRender *this, IEditorTexture *pTexture)
{
  IMaterial *v3; // eax

  v3 = pTexture->GetMaterial(this: pTexture, a2: 1);
  if ( this->m_pBoundMaterial != v3 )
  {
    this->m_pBoundMaterial = v3;
    this->SetRenderMode(this, a2: RENDER_MODE_CURRENT, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092A50
// Name: public: void CRender::PrepareInstanceStencil(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::PrepareInstanceStencil(CRender *this)
{
  IMatRenderContext *v2; // edi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  this->m_ShaderStencilState.m_bEnable = true;
  this->m_ShaderStencilState.m_FailOp = SHADER_STENCILOP_KEEP;
  this->m_ShaderStencilState.m_ZFailOp = SHADER_STENCILOP_KEEP;
  this->m_ShaderStencilState.m_nReferenceValue = 1;
  this->m_ShaderStencilState.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
  this->m_ShaderStencilState.m_nWriteMask = 255;
  this->m_ShaderStencilState.m_nTestMask = 255;
  this->m_ShaderStencilState.m_PassOp = SHADER_STENCILOP_ZERO;
  v2->SetStencilState(this: v2, a2: &this->m_ShaderStencilState);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10092B20
// Name: public: void CRender::SetInstanceRendering(enum InstanceRenderingState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::SetInstanceRendering(CRender *this, InstanceRenderingState_t State)
{
  IMatRenderContext *v3; // esi

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( State != INSTANCE_STATE_OFF )
  {
    if ( State == INSTANCE_STATE_ON )
    {
      this->m_ShaderStencilState.m_PassOp = SHADER_STENCILOP_SET_TO_REFERENCE;
      this->m_ShaderStencilState.m_nReferenceValue = 1;
    }
    else if ( State == INSTANCE_STACE_SELECTED )
    {
      this->m_ShaderStencilState.m_PassOp = SHADER_STENCILOP_SET_TO_REFERENCE;
      this->m_ShaderStencilState.m_nReferenceValue = 2;
    }
  }
  else
  {
    this->m_ShaderStencilState.m_PassOp = SHADER_STENCILOP_ZERO;
  }
  v3->SetStencilState(this: v3, a2: &this->m_ShaderStencilState);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10092C00
// Name: public: virtual void CRender::EndRenderFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::EndRenderFrame(CRender *this)
{
  IMatRenderContext *v2; // esi

  if ( g_pStudioRender != nullptr )
    g_pStudioRender->BeginFrame(this: g_pStudioRender);
  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v2->SetIntRenderingParameter(this: v2, a2: 0, a3: 0);
  ++this->m_nFrameCount;
  *(_WORD *)&this->m_bIsRendering = 0;
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10092CB0
// Name: public: void CRender::GetLocalTranform(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::GetLocalTranform(CRender *this, VMatrix *matrix)
{
  VMatrix::operator=(this: matrix, mOther: this->m_LocalMatrix.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10092CD0
// Name: public: bool CRender::BeginClientSpace(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CRender::BeginClientSpace@<al>(CRender *this@<ecx>, int a2@<esi>)
{
  int v4; // esi

  if ( this->m_bIsClientSpace )
    return 0;
  v4 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v4 + 96))(a1: v4, a2: &this->m_OrthoMatrix);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 80))(a1: v4, a2: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v4 + 144))(a1: v4, a2: -1090519040, a3: 1056964608, a4: 0);
  if ( this->m_bIsLocalTransform )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
  }
  this->m_bIsClientSpace = true;
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10092E00
// Name: public: void CRender::EndClientSpace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::EndClientSpace(CRender *this)
{
  IMatRenderContext *v2; // esi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v2->MatrixMode(this: v2, a2: MATERIAL_VIEW);
  v2->PopMatrix(this: v2);
  v2->MatrixMode(this: v2, a2: MATERIAL_PROJECTION);
  v2->PopMatrix(this: v2);
  if ( this->m_bIsLocalTransform )
  {
    v2->MatrixMode(this: v2, a2: MATERIAL_MODEL);
    v2->PopMatrix(this: v2);
  }
  this->m_bIsClientSpace = false;
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10092ED0
// Name: public: void CRender::TransformPoint(class Vector2D __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::TransformPoint(CRender *this, Vector2D *vClient, const Vector *vWorld)
{
  float *m_pMemory; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float v7; // xmm0_4
  Vector vecActualPos; // [esp+0h] [ebp-Ch] BYREF

  if ( this->m_bIsLocalTransform )
  {
    m_pMemory = (float *)this->m_LocalMatrix.m_Memory.m_pMemory;
    y = vWorld->y;
    x = vWorld->x;
    z = vWorld->z;
    v7 = 1.0
       / (float)((float)((float)((float)(m_pMemory[13] * y) + (float)(m_pMemory[12] * vWorld->x))
                       + (float)(m_pMemory[14] * z))
               + m_pMemory[15]);
    vecActualPos.x = (float)((float)((float)((float)(m_pMemory[1] * y) + (float)(*m_pMemory * vWorld->x))
                                   + (float)(m_pMemory[2] * z))
                           + m_pMemory[3])
                   * v7;
    vecActualPos.y = (float)((float)((float)((float)(m_pMemory[5] * y) + (float)(m_pMemory[4] * x))
                                   + (float)(m_pMemory[6] * z))
                           + m_pMemory[7])
                   * v7;
    vecActualPos.z = (float)((float)((float)((float)(m_pMemory[9] * y) + (float)(m_pMemory[8] * x))
                                   + (float)(m_pMemory[10] * z))
                           + m_pMemory[11])
                   * v7;
  }
  else
  {
    vecActualPos = *vWorld;
  }
  this->m_pView->WorldToClient(this: this->m_pView, a2: vClient, a3: &vecActualPos);
}

//------------------------------------------------------------------------------
// Address: 0x10093000
// Name: public: void CRender::TransformNormal(class Vector2D __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::TransformNormal(CRender *this, Vector2D *vClient, const Vector *vWorld)
{
  float *m_pMemory; // eax
  float v5; // xmm0_4
  float *v6; // eax
  float y; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  Vector v12; // [esp+4h] [ebp-1Ch] BYREF
  Vector2D originClient; // [esp+10h] [ebp-10h] BYREF
  Vector2D normalClient; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_bIsLocalTransform )
  {
    m_pMemory = (float *)this->m_LocalMatrix.m_Memory.m_pMemory;
    v5 = 1.0
       / (float)((float)((float)((float)(m_pMemory[13] * vec3_origin.y) + (float)(m_pMemory[12] * vec3_origin.x))
                       + (float)(m_pMemory[14] * vec3_origin.z))
               + m_pMemory[15]);
    v12.x = (float)((float)((float)((float)(m_pMemory[1] * vec3_origin.y) + (float)(*m_pMemory * vec3_origin.x))
                          + (float)(m_pMemory[2] * vec3_origin.z))
                  + m_pMemory[3])
          * v5;
    v12.y = (float)((float)((float)((float)(m_pMemory[5] * vec3_origin.y) + (float)(m_pMemory[4] * vec3_origin.x))
                          + (float)(m_pMemory[6] * vec3_origin.z))
                  + m_pMemory[7])
          * v5;
    v12.z = (float)((float)((float)((float)(m_pMemory[9] * vec3_origin.y) + (float)(m_pMemory[8] * vec3_origin.x))
                          + (float)(m_pMemory[10] * vec3_origin.z))
                  + m_pMemory[11])
          * v5;
  }
  else
  {
    v12 = vec3_origin;
  }
  this->m_pView->WorldToClient(this: this->m_pView, a2: &originClient, a3: &v12);
  if ( this->m_bIsLocalTransform )
  {
    v6 = (float *)this->m_LocalMatrix.m_Memory.m_pMemory;
    y = vWorld->y;
    x = vWorld->x;
    z = vWorld->z;
    v10 = 1.0
        / (float)((float)((float)((float)(v6[13] * y) + (float)(v6[12] * vWorld->x)) + (float)(v6[14] * z)) + v6[15]);
    v12.x = (float)((float)((float)((float)(v6[1] * y) + (float)(vWorld->x * *v6)) + (float)(v6[2] * z)) + v6[3]) * v10;
    v12.y = (float)((float)((float)((float)(v6[5] * y) + (float)(v6[4] * x)) + (float)(v6[6] * z)) + v6[7]) * v10;
    v12.z = (float)((float)((float)((float)(v6[9] * y) + (float)(v6[8] * x)) + (float)(v6[10] * z)) + v6[11]) * v10;
  }
  else
  {
    v12 = *vWorld;
  }
  this->m_pView->WorldToClient(this: this->m_pView, a2: &normalClient, a3: &v12);
  v11 = normalClient.y - originClient.y;
  vClient->x = normalClient.x - originClient.x;
  vClient->y = v11;
}

//------------------------------------------------------------------------------
// Address: 0x10093270
// Name: public: void CRender::DrawHandle(class Vector const __near &,class Vector2D const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawHandle(CRender *this, const Vector *vCenter, const Vector2D *vOffset)
{
  int m_nHandleSize; // edi
  char v5; // bl
  float *m_pMemory; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float v10; // xmm0_4
  int m_nHandleType; // eax
  int v12; // eax
  int v13; // eax
  Vector v14; // [esp+18h] [ebp-1Ch] BYREF
  Vector2D v15; // [esp+24h] [ebp-10h] BYREF
  Vector2D v; // [esp+2Ch] [ebp-8h] BYREF

  if ( this->m_CurrentInstanceState.m_bIsEditable )
  {
    m_nHandleSize = this->m_nHandleSize;
    v5 = CRender::BeginClientSpace(this, a2: (int)this);
    if ( this->m_bIsLocalTransform )
    {
      m_pMemory = (float *)this->m_LocalMatrix.m_Memory.m_pMemory;
      y = vCenter->y;
      x = vCenter->x;
      z = vCenter->z;
      v10 = 1.0
          / (float)((float)((float)((float)(m_pMemory[13] * y) + (float)(m_pMemory[12] * vCenter->x))
                          + (float)(m_pMemory[14] * z))
                  + m_pMemory[15]);
      v14.x = (float)((float)((float)((float)(m_pMemory[1] * y) + (float)(vCenter->x * *m_pMemory))
                            + (float)(m_pMemory[2] * z))
                    + m_pMemory[3])
            * v10;
      v14.y = (float)((float)((float)((float)(m_pMemory[5] * y) + (float)(m_pMemory[4] * x)) + (float)(m_pMemory[6] * z))
                    + m_pMemory[7])
            * v10;
      v14.z = (float)((float)((float)((float)(m_pMemory[9] * y) + (float)(m_pMemory[8] * x)) + (float)(m_pMemory[10] * z))
                    + m_pMemory[11])
            * v10;
    }
    else
    {
      v14 = *vCenter;
    }
    this->m_pView->WorldToClient(this: this->m_pView, a2: &v, a3: &v14);
    if ( vOffset != nullptr )
    {
      v.x = vOffset->x + v.x;
      v.y = vOffset->y + v.y;
    }
    RoundVector(&v);
    m_nHandleType = this->m_nHandleType;
    if ( m_nHandleType == 4 )
      --m_nHandleSize;
    v12 = m_nHandleType - 1;
    v14.z = v.y - (float)m_nHandleSize;
    v15.x = (float)((float)m_nHandleSize + v.x) + 1.0;
    v14.y = v.x - (float)m_nHandleSize;
    v15.y = (float)((float)m_nHandleSize + v.y) + 1.0;
    if ( v12 != 0 )
    {
      v13 = v12 - 1;
      if ( v13 != 0 )
      {
        if ( v13 == 2 )
          CRender::DrawCross(this, ul: (Vector2D *)&v14.y, lr: &v15, pColor: (unsigned __int8 *)&this->m_HandleColor);
      }
      else
      {
        CRender::DrawCircle(
          this,
          vCenter: &v,
          fRadius: (float)m_nHandleSize,
          nSegments: 16,
          pColor: (unsigned __int8 *)&this->m_HandleColor);
      }
    }
    else
    {
      CRender::DrawFilledRect(
        this,
        ul: (Vector2D *)&v14.y,
        lr: &v15,
        pColor: (unsigned __int8 *)&this->m_HandleColor,
        bBorder: true);
    }
    if ( v5 != 0 )
      CRender::EndClientSpace(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100934A0
// Name: public: virtual void CRender::SetRenderMode(enum EditorRenderMode_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::SetRenderMode(CRender *this, EditorRenderMode_t eRenderMode, bool bForce)
{
  EditorRenderMode_t m_eDefaultRenderMode; // ebx
  IMatRenderContext *v5; // esi
  IMaterial *v6; // edx
  IMaterial *m_pBoundMaterial; // ecx
  bool v8; // zf
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // edx

  m_eDefaultRenderMode = eRenderMode;
  if ( eRenderMode == RENDER_MODE_DEFAULT )
    m_eDefaultRenderMode = this->m_eDefaultRenderMode;
  if ( m_eDefaultRenderMode == RENDER_MODE_CURRENT )
    m_eDefaultRenderMode = this->m_eCurrentRenderMode;
  if ( this->m_eCurrentRenderMode != m_eDefaultRenderMode || bForce )
  {
    v5 = materials->GetRenderContext(this: materials);
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    switch ( m_eDefaultRenderMode )
    {
      case RENDER_MODE_WIREFRAME:
        v6 = this->m_pWireframe[this->m_nDecalMode];
        goto LABEL_25;
      case RENDER_MODE_FLAT:
        this->m_pCurrentMaterial = this->m_pFlat[this->m_nDecalMode];
        goto LABEL_26;
      case RENDER_MODE_FLAT_NOZ:
        this->m_pCurrentMaterial = this->m_pFlatNoZ[this->m_nDecalMode];
        goto LABEL_26;
      case RENDER_MODE_FLAT_NOCULL:
        this->m_pCurrentMaterial = this->m_pFlatNoCull[this->m_nDecalMode];
        goto LABEL_26;
      case RENDER_MODE_DOTTED:
        this->m_pCurrentMaterial = this->m_pDotted[this->m_nDecalMode];
        goto LABEL_26;
      case RENDER_MODE_TRANSLUCENT_FLAT:
        v6 = this->m_pTranslucentFlat[this->m_nDecalMode];
        goto LABEL_25;
      case RENDER_MODE_TEXTURED:
      case RENDER_MODE_TEXTURED_SHADED:
      case RENDER_MODE_LIGHT_PREVIEW2:
      case RENDER_MODE_LIGHT_PREVIEW_RAYTRACED:
        m_pBoundMaterial = this->m_pBoundMaterial;
        if ( m_pBoundMaterial != nullptr )
        {
          v8 = !m_pBoundMaterial->GetPropertyFlag(this: m_pBoundMaterial, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
          BindLightmapPage = v5->BindLightmapPage;
          if ( v8 )
            BindLightmapPage(this: v5, a2: -1);
          else
            BindLightmapPage(this: v5, a2: -2);
          this->m_pCurrentMaterial = this->m_pBoundMaterial;
        }
        else
        {
          v6 = this->m_pFlat[this->m_nDecalMode];
LABEL_25:
          this->m_pCurrentMaterial = v6;
        }
LABEL_26:
        v5->Bind(this: v5, a2: this->m_pCurrentMaterial, a3: nullptr);
        v5->SetIntRenderingParameter(this: v5, a2: 0, a3: 0);
        if ( m_eDefaultRenderMode == RENDER_MODE_TEXTURED_SHADED )
        {
          v5->SetIntRenderingParameter(this: v5, a2: 0, a3: 1);
        }
        else if ( m_eDefaultRenderMode == RENDER_MODE_LIGHT_PREVIEW2
               || m_eDefaultRenderMode == RENDER_MODE_LIGHT_PREVIEW_RAYTRACED )
        {
          v5->SetIntRenderingParameter(this: v5, a2: 0, a3: 2);
        }
        this->m_pMesh = v5->GetDynamicMesh(this: v5, a2: true, a3: nullptr, a4: nullptr, a5: this->m_pCurrentMaterial);
        this->m_eCurrentRenderMode = m_eDefaultRenderMode;
        v5->EndRender(this: v5);
        v5->Release(this: v5);
        break;
      case RENDER_MODE_LIGHTMAP_GRID:
        this->m_pCurrentMaterial = this->m_pLightmapGrid[this->m_nDecalMode];
        goto LABEL_26;
      case RENDER_MODE_SELECTION_OVERLAY:
      case RENDER_MODE_INSTANCE_OVERLAY:
        v6 = this->m_pSelectionOverlay[this->m_nDecalMode];
        goto LABEL_25;
      case RENDER_MODE_SMOOTHING_GROUP:
        this->m_pCurrentMaterial = this->m_pFlat[this->m_nDecalMode];
        goto LABEL_26;
      default:
        goto LABEL_26;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093720
// Name: public: void CRender::PopInstanceRendering(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRender::PopInstanceRendering(CRender *this@<ecx>, int a2@<esi>)
{
  int v3; // eax
  int v4; // esi

  if ( this->m_InstanceRenderingState.m_Size - 1 > 0 )
    _V_memmove(
      dest: this->m_InstanceRenderingState.m_Memory.m_pMemory,
      src: this->m_InstanceRenderingState.m_Memory.m_pMemory + 1,
      count: 4 * (this->m_InstanceRenderingState.m_Size - 1));
  if ( --this->m_InstanceRenderingState.m_Size <= 0 )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    v4 = v3;
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    this->m_ShaderStencilState.m_PassOp = SHADER_STENCILOP_ZERO;
    (*(void (__thiscall **)(int, ShaderStencilState_t *))(*(_DWORD *)v4 + 472))(a1: v4, a2: &this->m_ShaderStencilState);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
  else
  {
    CRender::SetInstanceRendering(this, State: *this->m_InstanceRenderingState.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093810
// Name: public: virtual void CRender::StartRenderFrame(bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CRender::StartRenderFrame(CRender *this, bool bRenderingOverEngine)
{
  bool v3; // al
  CCamera *m_pCamera; // ebx
  IMatRenderContext *v5; // eax
  IMatRenderContext *v6; // edi
  CMapView *m_pView; // [esp+1Ch] [ebp-A8h]
  VMatrix Matrix; // [esp+3Ch] [ebp-88h] BYREF
  Vector ViewPoint; // [esp+7Ch] [ebp-48h] BYREF
  Vector ViewRight; // [esp+88h] [ebp-3Ch] BYREF
  Vector ViewUp; // [esp+94h] [ebp-30h] BYREF
  Vector ViewForward; // [esp+A0h] [ebp-24h] BYREF
  IMatRenderContext *v13; // [esp+ACh] [ebp-18h]
  _BYTE matrix[20]; // [esp+B0h] [ebp-14h] OVERLAPPED BYREF

  this->m_bRenderingOverEngine = bRenderingOverEngine;
  m_pView = this->m_pView;
  this->m_nNumInstancesRendered = 0;
  v3 = __RTDynamicCast(
         inptr: m_pView,
         VfDelta: 0,
         SrcType: &CMapView `RTTI Type Descriptor',
         TargetType: &CVGuiWnd `RTTI Type Descriptor',
         isReference: 0) != nullptr;
  this->m_bIsRenderingIntoVGUI = v3;
  if ( v3 )
  {
    g_pMatSystemSurface->DrawSetTextFont(this: g_pMatSystemSurface, a2: this->m_DefaultFont);
    ((void (__thiscall *)(IMatSystemSurface *, _DWORD))g_pMatSystemSurface->DrawSetTextColor)(
      a1: g_pMatSystemSurface,
      a2: *(_DWORD *)&this->m_TextColor);
    ((void (__thiscall *)(IMatSystemSurface *, _DWORD))g_pMatSystemSurface->DrawSetColor)(
      a1: g_pMatSystemSurface,
      a2: *(_DWORD *)&this->m_DrawColor);
  }
  m_pCamera = this->m_pView->m_pCamera;
  v5 = materials->GetRenderContext(this: materials);
  v6 = v5;
  v13 = v5;
  *(_DWORD *)&matrix[16] = 0;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  *(_DWORD *)&matrix[16] = 1;
  if ( !bRenderingOverEngine )
  {
    CCamera::GetViewPort(this: m_pCamera, width: (int *)matrix, height: (int *)&matrix[4]);
    v6->MatrixMode(this: v6, a2: MATERIAL_PROJECTION);
    v6->LoadIdentity(this: v6);
    ((void (__thiscall *)(IMatRenderContext *, int, int, int))v6->Scale)(
      a1: v6,
      a2: 1065353216,
      a3: -1082130432,
      a4: 1065353216);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))v6->Ortho)(
      a1: v6,
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: COERCE_UNSIGNED_INT64((double)*(int *)matrix),
      a7: HIDWORD(COERCE_UNSIGNED_INT64((double)*(int *)matrix)),
      a8: COERCE_UNSIGNED_INT64((double)*(int *)&matrix[4]),
      a9: HIDWORD(COERCE_UNSIGNED_INT64((double)*(int *)&matrix[4])),
      a10: 0,
      a11: -1057461776,
      a12: 0,
      a13: 1090021872);
    v6->GetMatrix_2(this: v6, a2: MATERIAL_PROJECTION, a3: &this->m_OrthoMatrix);
    CCamera::GetProjMatrix(this: m_pCamera, &Matrix);
    v6->MatrixMode(this: v6, a2: MATERIAL_PROJECTION);
    v6->LoadMatrix_2(this: v6, a2: &Matrix);
    CCamera::GetViewMatrix(this: m_pCamera, &Matrix);
    v6->MatrixMode(this: v6, a2: MATERIAL_VIEW);
    v6->LoadMatrix_2(this: v6, a2: &Matrix);
    v6->MatrixMode(this: v6, a2: MATERIAL_MODEL);
    v6->LoadIdentity(this: v6);
    ViewForward.x = 0.0;
    ViewForward.y = 0.0;
    ViewForward.z = -1.0;
    v6->SetVectorRenderingParameter(this: v6, a2: 0, a3: &ViewForward);
    ((void (__thiscall *)(IMatRenderContext *, int, int))v6->SetFloatRenderingParameter)(a1: v6, a2: 1, a3: 1090519040);
  }
  CCamera::GetViewMatrix(this: m_pCamera, Matrix: &this->m_CurrentMatrix);
  v6->DisableAllLocalLights(this: v6);
  this->m_bIsClientSpace = false;
  this->m_RenderModeStack.m_Size = 0;
  this->SetRenderMode(this, a2: this->m_eDefaultRenderMode, a3: true);
  this->m_DrawColor = (Color)-1;
  this->m_TextColor = (Color)-1;
  this->m_HandleColor = (Color)-1;
  s_fOneUnitLength = 1.0 / CCamera::GetZoom(this: m_pCamera);
  if ( !bRenderingOverEngine && g_pStudioRender != nullptr )
  {
    g_pStudioRender->BeginFrame(this: g_pStudioRender);
    CCamera::GetViewPoint(this: m_pCamera, &ViewPoint);
    CCamera::GetViewRight(this: m_pCamera, &ViewRight);
    CMapPoint::GetOrigin(this: m_pCamera, &ViewUp);
    CCamera::GetViewForward(this: m_pCamera, &ViewForward);
    g_pStudioRender->SetViewState(this: g_pStudioRender, a2: &ViewPoint, a3: &ViewRight, a4: &ViewUp, a5: &ViewForward);
    if ( (_S1_8 & 1) == 0 )
    {
      _S1_8 |= 1u;
      white[0].x = 1.0;
      dword_10792184 = 1065353216;
      dword_10792188 = 1065353216;
      dword_1079218C = 1065353216;
      dword_10792190 = 1065353216;
      dword_10792194 = 1065353216;
      dword_10792198 = 1065353216;
      dword_1079219C = 1065353216;
      dword_107921A0 = 1065353216;
      dword_107921A4 = 1065353216;
      dword_107921A8 = 1065353216;
      dword_107921AC = 1065353216;
      dword_107921B0 = 1065353216;
      dword_107921B4 = 1065353216;
      dword_107921B8 = 1065353216;
      dword_107921BC = 1065353216;
      dword_107921C0 = 1065353216;
      dword_107921C4 = 1065353216;
      matrix[16] = 1;
    }
    g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: white);
  }
  this->m_bIsRendering = true;
  *(_DWORD *)&matrix[16] = 3;
  v6->EndRender(this: v6);
  *(_DWORD *)&matrix[16] = -1;
  v6->Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10093C20
// Name: public: void CRender::EndLocalTransfrom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::EndLocalTransfrom(CRender *this)
{
  IMatRenderContext *v2; // edi
  const VMatrix *v3; // eax
  VMatrix result; // [esp+Ch] [ebp-50h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+4Ch] [ebp-10h]
  int v6; // [esp+58h] [ebp-4h]

  v2 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v2;
  v6 = 0;
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v6 = 1;
  v2->MatrixMode(this: v2, a2: MATERIAL_MODEL);
  v2->PopMatrix(this: v2);
  if ( this->m_LocalMatrix.m_Size - 1 > 0 )
    _V_memmove(
      dest: this->m_LocalMatrix.m_Memory.m_pMemory,
      src: &this->m_LocalMatrix.m_Memory.m_pMemory[1],
      count: (this->m_LocalMatrix.m_Size - 1) << 6);
  --this->m_LocalMatrix.m_Size;
  CCamera::GetViewMatrix(this: this->m_pView->m_pCamera, Matrix: &this->m_CurrentMatrix);
  if ( this->m_LocalMatrix.m_Size <= 1 )
  {
    this->m_bIsLocalTransform = false;
  }
  else
  {
    v3 = VMatrix::operator*(this: &this->m_CurrentMatrix, &result, vm: this->m_LocalMatrix.m_Memory.m_pMemory);
    VMatrix::operator=(this: &this->m_CurrentMatrix, mOther: v3);
    this->m_bIsLocalTransform = true;
  }
  v6 = 2;
  v2->EndRender(this: v2);
  v6 = -1;
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10093D10
// Name: public: void CRender::PopRenderMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::PopRenderMode(CRender *this)
{
  this->SetRenderMode(
    this,
    a2: this->m_RenderModeStack.m_Memory.m_pMemory[this->m_RenderModeStack.m_Size - 1],
    a3: false);
  --this->m_RenderModeStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10093EA0
// Name: public: virtual CRender::~CRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::~CRender(CRender *this)
{
  CUtlVector<enum InstanceRenderingState_t,CUtlMemory<enum InstanceRenderingState_t,int> > *p_m_InstanceRenderingState; // esi
  CUtlVector<SInstanceState,CUtlMemory<SInstanceState,int> > *p_m_InstanceState; // esi
  CUtlStack<enum EditorRenderMode_t,CUtlMemory<enum EditorRenderMode_t,int> > *p_m_RenderModeStack; // esi
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *p_m_LocalMatrix; // esi

  this->__vftable = (CRender_vtbl *)&CRender::`vftable';
  p_m_InstanceRenderingState = &this->m_InstanceRenderingState;
  this->m_InstanceRenderingState.m_Size = 0;
  if ( this->m_InstanceRenderingState.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_InstanceRenderingState->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_InstanceRenderingState->m_Memory.m_pMemory);
      p_m_InstanceRenderingState->m_Memory.m_pMemory = nullptr;
    }
    p_m_InstanceRenderingState->m_Memory.m_nAllocationCount = 0;
  }
  p_m_InstanceRenderingState->m_pElements = p_m_InstanceRenderingState->m_Memory.m_pMemory;
  if ( p_m_InstanceRenderingState->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_InstanceRenderingState->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_InstanceRenderingState->m_Memory.m_pMemory);
      p_m_InstanceRenderingState->m_Memory.m_pMemory = nullptr;
    }
    p_m_InstanceRenderingState->m_Memory.m_nAllocationCount = 0;
  }
  p_m_InstanceState = &this->m_InstanceState;
  this->m_InstanceState.m_Size = 0;
  if ( this->m_InstanceState.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_InstanceState->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_InstanceState->m_Memory.m_pMemory);
      p_m_InstanceState->m_Memory.m_pMemory = nullptr;
    }
    this->m_InstanceState.m_Memory.m_nAllocationCount = 0;
  }
  this->m_InstanceState.m_pElements = this->m_InstanceState.m_Memory.m_pMemory;
  if ( this->m_InstanceState.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_InstanceState->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_InstanceState->m_Memory.m_pMemory);
      p_m_InstanceState->m_Memory.m_pMemory = nullptr;
    }
    this->m_InstanceState.m_Memory.m_nAllocationCount = 0;
  }
  p_m_RenderModeStack = &this->m_RenderModeStack;
  this->m_RenderModeStack.m_Size = 0;
  if ( this->m_RenderModeStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_RenderModeStack->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_RenderModeStack->m_Memory.m_pMemory);
      p_m_RenderModeStack->m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderModeStack.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RenderModeStack.m_pElements = this->m_RenderModeStack.m_Memory.m_pMemory;
  if ( this->m_RenderModeStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_RenderModeStack->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_RenderModeStack->m_Memory.m_pMemory);
      p_m_RenderModeStack->m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderModeStack.m_Memory.m_nAllocationCount = 0;
  }
  CMeshBuilder::~CMeshBuilder(this: &this->meshBuilder);
  p_m_LocalMatrix = &this->m_LocalMatrix;
  this->m_LocalMatrix.m_Size = 0;
  if ( this->m_LocalMatrix.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_LocalMatrix->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_LocalMatrix->m_Memory.m_pMemory);
      p_m_LocalMatrix->m_Memory.m_pMemory = nullptr;
    }
    this->m_LocalMatrix.m_Memory.m_nAllocationCount = 0;
  }
  this->m_LocalMatrix.m_pElements = this->m_LocalMatrix.m_Memory.m_pMemory;
  if ( this->m_LocalMatrix.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_LocalMatrix->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_LocalMatrix->m_Memory.m_pMemory);
      p_m_LocalMatrix->m_Memory.m_pMemory = nullptr;
    }
    this->m_LocalMatrix.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094030
// Name: public: virtual void CRender::PopInstanceData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::PopInstanceData(CRender *this)
{
  int m_InstanceSelectionDepth; // eax

  if ( this->m_CurrentInstanceState.m_pInstanceClass != nullptr )
    CRender::PopInstanceRendering(this, a2: (int)this);
  if ( this->m_InstanceState.m_Size - 1 > 0 )
    _V_memmove(
      dest: this->m_InstanceState.m_Memory.m_pMemory,
      src: &this->m_InstanceState.m_Memory.m_pMemory[1],
      count: 164 * (this->m_InstanceState.m_Size - 1));
  --this->m_InstanceState.m_Size;
  SInstanceState::operator=(this: &this->m_CurrentInstanceState, __that: this->m_InstanceState.m_Memory.m_pMemory);
  m_InstanceSelectionDepth = this->m_InstanceSelectionDepth;
  this->m_bInstanceRendering = this->m_InstanceState.m_Size > 1;
  if ( m_InstanceSelectionDepth > 0 )
    this->m_InstanceSelectionDepth = m_InstanceSelectionDepth - 1;
  CRender::EndLocalTransfrom(this);
}

//------------------------------------------------------------------------------
// Address: 0x100940B0
// Name: public: void CRender::PushRenderMode(enum EditorRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::PushRenderMode(CRender *this, EditorRenderMode_t eRenderMode)
{
  EditorRenderMode_t *m_pMemory; // eax
  int m_Size; // ecx
  EditorRenderMode_t *v5; // eax

  if ( this->m_RenderModeStack.m_Size >= this->m_RenderModeStack.m_Memory.m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_RenderModeStack, num: 1);
  ++this->m_RenderModeStack.m_Size;
  m_pMemory = this->m_RenderModeStack.m_Memory.m_pMemory;
  m_Size = this->m_RenderModeStack.m_Size;
  this->m_RenderModeStack.m_pElements = m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = this->m_eCurrentRenderMode;
  this->SetRenderMode(this, a2: eRenderMode, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10094140
// Name: public: void CRender::DrawInstanceStencil(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawInstanceStencil(CRender *this)
{
  IMatRenderContext *v2; // edi
  CCamera *m_pCamera; // ecx
  void (__thiscall *SetStencilState)(IMatRenderContext *, const ShaderStencilState_t *); // eax
  void (__thiscall *v5)(IMatRenderContext *, const ShaderStencilState_t *); // eax
  ShaderStencilState_t *p_m_ShaderStencilState; // esi
  Vector2D ul; // [esp+Ch] [ebp-2Ch] BYREF
  Vector2D lr; // [esp+14h] [ebp-24h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1Ch] [ebp-1Ch]
  int height; // [esp+20h] [ebp-18h] BYREF
  int width; // [esp+24h] [ebp-14h] BYREF
  Color InstanceColoring; // [esp+28h] [ebp-10h] BYREF
  int v13; // [esp+34h] [ebp-4h]

  v2 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v2;
  v13 = 0;
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v13 = 1;
  m_pCamera = this->m_pView->m_pCamera;
  if ( this->m_nNumInstancesRendered > 0 )
  {
    this->m_ShaderStencilState.m_PassOp = SHADER_STENCILOP_KEEP;
    this->m_ShaderStencilState.m_CompareFunc = SHADER_STENCILFUNC_EQUAL;
    InstanceColoring = 0;
    CCamera::GetViewPort(this: m_pCamera, &width, &height);
    CRender::PushRenderMode(this, eRenderMode: RENDER_MODE_INSTANCE_OVERLAY);
    CRender::BeginClientSpace(this, a2: (int)this);
    this->m_ShaderStencilState.m_nReferenceValue = 1;
    SetStencilState = v2->SetStencilState;
    InstanceColoring = (Color)-1073708928;
    SetStencilState(this: v2, a2: &this->m_ShaderStencilState);
    lr.x = (float)width;
    lr.y = (float)height;
    ul.x = 0.0;
    ul.y = 0.0;
    CRender::DrawFilledRect(this, &ul, &lr, pColor: (unsigned __int8 *)&InstanceColoring, bBorder: false);
    this->m_ShaderStencilState.m_nReferenceValue = 2;
    v5 = v2->SetStencilState;
    InstanceColoring = (Color)-1073708864;
    v5(this: v2, a2: &this->m_ShaderStencilState);
    ul.x = (float)width;
    ul.y = (float)height;
    lr.x = 0.0;
    lr.y = 0.0;
    CRender::DrawFilledRect(this, ul: &lr, lr: &ul, pColor: (unsigned __int8 *)&InstanceColoring, bBorder: false);
    CRender::EndClientSpace(this);
    this->SetRenderMode(
      this,
      a2: this->m_RenderModeStack.m_Memory.m_pMemory[this->m_RenderModeStack.m_Size - 1],
      a3: false);
    --this->m_RenderModeStack.m_Size;
  }
  p_m_ShaderStencilState = &this->m_ShaderStencilState;
  p_m_ShaderStencilState->m_bEnable = false;
  v2->SetStencilState(this: v2, a2: p_m_ShaderStencilState);
  v13 = 2;
  v2->EndRender(this: v2);
  v13 = -1;
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10094300
// Name: public: void CRender::PushInstanceRendering(enum InstanceRenderingState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::PushInstanceRendering(CRender *this, InstanceRenderingState_t State)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  InstanceRenderingState_t *m_pMemory; // eax
  int v6; // ecx
  InstanceRenderingState_t *v7; // esi

  CRender::SetInstanceRendering(this, State);
  m_Size = this->m_InstanceRenderingState.m_Size;
  m_nAllocationCount = this->m_InstanceRenderingState.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_InstanceRenderingState,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_InstanceRenderingState.m_Size;
  m_pMemory = this->m_InstanceRenderingState.m_Memory.m_pMemory;
  v6 = this->m_InstanceRenderingState.m_Size - 1;
  this->m_InstanceRenderingState.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_InstanceRenderingState.m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = State;
  if ( State != INSTANCE_STATE_OFF )
    ++this->m_nNumInstancesRendered;
}

//------------------------------------------------------------------------------
// Address: 0x10094380
// Name: public: void CRender::DrawTextA(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawTextA(CRender *this, wchar_t *text, int x, int y, int nFlags)
{
  wchar_t *v5; // esi
  char v7; // bl
  unsigned int m_DefaultFont; // eax
  EditorRenderMode_t *m_pMemory; // eax
  int m_Size; // ecx
  EditorRenderMode_t *v11; // eax
  char v12; // bl
  wchar_t unicode[128]; // [esp+8h] [ebp-104h] BYREF
  int tall; // [esp+108h] [ebp-4h] BYREF
  unsigned int len; // [esp+114h] [ebp+8h]

  v5 = text;
  mbstowcs(pwcs: unicode, s: (const char *)text, n: 0x100u);
  if ( (int)std::char_traits<char>::length(str: (const char *)text) <= 127 )
    len = std::char_traits<char>::length(str: (const char *)text);
  else
    len = 127;
  v7 = nFlags;
  if ( (nFlags & 0xE8) != 0 )
  {
    m_DefaultFont = this->m_DefaultFont;
    if ( m_DefaultFont != 0 )
    {
      v5 = unicode;
      g_pMatSystemSurface->GetTextSize(
        this: g_pMatSystemSurface,
        a2: m_DefaultFont,
        a3: unicode,
        a4: &nFlags,
        a5: &tall);
      if ( (v7 & 0x20) != 0 )
        x -= nFlags;
      if ( (v7 & 8) != 0 )
        y -= tall;
      if ( (v7 & 0x40) != 0 )
        x += nFlags / -2;
      if ( v7 < 0 )
        y += tall / -2;
    }
  }
  if ( this->m_RenderModeStack.m_Size >= this->m_RenderModeStack.m_Memory.m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_RenderModeStack, num: 1);
  ++this->m_RenderModeStack.m_Size;
  m_pMemory = this->m_RenderModeStack.m_Memory.m_pMemory;
  m_Size = this->m_RenderModeStack.m_Size;
  this->m_RenderModeStack.m_pElements = m_pMemory;
  v11 = &m_pMemory[m_Size - 1];
  if ( v11 != nullptr )
    *v11 = this->m_eCurrentRenderMode;
  this->SetRenderMode(this, a2: RENDER_MODE_EXTERN, a3: false);
  v12 = CRender::BeginClientSpace(this, a2: (int)v5);
  g_pMatSystemSurface->DrawSetTextPos(this: g_pMatSystemSurface, a2: x, a3: y);
  g_pMatSystemSurface->DrawPrintText(this: g_pMatSystemSurface, a2: unicode, a3: len, a4: FONT_DRAW_DEFAULT);
  if ( v12 != 0 )
    CRender::EndClientSpace(this);
  this->SetRenderMode(
    this,
    a2: this->m_RenderModeStack.m_Memory.m_pMemory[this->m_RenderModeStack.m_Size - 1],
    a3: false);
  --this->m_RenderModeStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100944F0
// Name: public: void CRender::DrawTextA(char const __near *,class Vector2D const __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::DrawTextA(
        CRender *this,
        wchar_t *text,
        const Vector2D *vPos,
        int nOffsetX,
        int nOffsetY,
        int nFlags)
{
  bool v7; // zf
  float x; // xmm0_4
  float y; // xmm1_4
  VMatrix matrix; // [esp+0h] [ebp-54h] BYREF
  Vector vecActualPos; // [esp+40h] [ebp-14h] BYREF
  Vector2D pt; // [esp+4Ch] [ebp-8h] BYREF

  vecActualPos.x = vPos->x;
  v7 = !this->m_bIsLocalTransform;
  vecActualPos.y = vPos->y;
  vecActualPos.z = 0.0;
  if ( !v7 )
  {
    VMatrix::operator=(this: &matrix, mOther: this->m_LocalMatrix.m_Memory.m_pMemory);
    x = vecActualPos.x;
    y = vecActualPos.y;
    vecActualPos.x = (float)((float)((float)(matrix.m[0][0] * vecActualPos.x) + (float)(matrix.m[0][1] * vecActualPos.y))
                           + (float)(matrix.m[0][2] * vecActualPos.z))
                   + matrix.m[0][3];
    vecActualPos.y = (float)((float)((float)(matrix.m[1][0] * x) + (float)(matrix.m[1][1] * vecActualPos.y))
                           + (float)(matrix.m[1][2] * vecActualPos.z))
                   + matrix.m[1][3];
    vecActualPos.z = (float)((float)((float)(matrix.m[2][1] * y) + (float)(matrix.m[2][0] * x))
                           + (float)(matrix.m[2][2] * vecActualPos.z))
                   + matrix.m[2][3];
  }
  this->m_pView->WorldToClient(this: this->m_pView, a2: &pt, a3: &vecActualPos);
  CRender::DrawTextA(this, text, x: nOffsetX + (int)pt.x, y: nOffsetY + (int)pt.y, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10094600
// Name: public: void CRender::BeginLocalTransfrom(class VMatrix const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::BeginLocalTransfrom(CRender *this, const VMatrix *matrix, bool MultiplyCurrent)
{
  const VMatrix *v4; // eax
  IMatRenderContext *v5; // eax
  IMatRenderContext *v6; // esi
  const VMatrix *v7; // eax
  VMatrix result; // [esp+Ch] [ebp-8Ch] BYREF
  VMatrix LocalCopy; // [esp+4Ch] [ebp-4Ch] BYREF
  int v10; // [esp+94h] [ebp-4h]

  LocalCopy = *matrix;
  if ( MultiplyCurrent )
  {
    v4 = VMatrix::operator*(this: this->m_LocalMatrix.m_Memory.m_pMemory, &result, vm: &LocalCopy);
    VMatrix::operator=(this: &LocalCopy, mOther: v4);
  }
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &this->m_LocalMatrix,
    elem: 0,
    src: &LocalCopy);
  v5 = materials->GetRenderContext(this: materials);
  v6 = v5;
  v10 = 0;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v10 = 1;
  v6->MatrixMode(this: v6, a2: MATERIAL_MODEL);
  v6->PushMatrix(this: v6);
  v6->LoadMatrix_2(this: v6, a2: this->m_LocalMatrix.m_Memory.m_pMemory);
  CCamera::GetViewMatrix(this: this->m_pView->m_pCamera, Matrix: &this->m_CurrentMatrix);
  v7 = VMatrix::operator*(this: &this->m_CurrentMatrix, &result, vm: &LocalCopy);
  VMatrix::operator=(this: &this->m_CurrentMatrix, mOther: v7);
  this->m_bIsLocalTransform = true;
  v10 = 2;
  v6->EndRender(this: v6);
  v10 = -1;
  v6->Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10094720
// Name: public: void CRender::DrawCollisionModel(unsigned short,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRender::DrawCollisionModel(
        CRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        int mdlHandle,
        const VMatrix *mViewMatrix)
{
  vcollide_t *v6; // eax
  int v7; // esi
  unsigned int v8; // edx
  IMesh *m_pMesh; // esi
  unsigned int m_nIndexSize; // edx
  int v12; // ecx
  float *m_pCurrPosition; // eax
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float *v17; // eax
  int v18; // eax
  Vector *outVerts; // [esp+4h] [ebp-8h] BYREF
  int vertCount; // [esp+8h] [ebp-4h]
  int mdlHandleb; // [esp+14h] [ebp+8h]
  int mdlHandlea; // [esp+14h] [ebp+8h]
  const VMatrix *mViewMatrixa; // [esp+18h] [ebp+Ch]

  v6 = g_pMDLCache->GetVCollide(this: g_pMDLCache, a2: mdlHandle);
  if ( v6 != nullptr && (*(_WORD *)v6 & 0x7FFF) != 0 )
  {
    v7 = ((int (__thiscall *)(IPhysicsCollision *, struct CPhysCollide *, Vector **, int))g_pPhysicsCollision->CreateDebugMesh)(
           a1: g_pPhysicsCollision,
           a2: *v6->solids,
           a3: &outVerts,
           a4: a3);
    vertCount = v7;
    if ( v7 != 0 )
    {
      CRender::PushRenderMode(this, eRenderMode: RENDER_MODE_WIREFRAME);
      v8 = (unsigned __int64)(1431655766LL * v7) >> 32;
      m_pMesh = this->m_pMesh;
      this->meshBuilder.m_pMesh = m_pMesh;
      this->meshBuilder.m_bGenerateIndices = true;
      this->meshBuilder.m_Type = MATERIAL_TRIANGLES;
      mdlHandleb = 3 * (v8 + (v8 >> 31));
      ((void (__thiscall *)(IMesh *, int, int))m_pMesh->SetPrimitiveType)(a1: m_pMesh, a2: 2, a3: a2);
      this->meshBuilder.m_pMesh->LockMesh(
        this: this->meshBuilder.m_pMesh,
        a2: mdlHandleb,
        a3: mdlHandleb,
        a4: &this->meshBuilder,
        a5: nullptr);
      this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = &m_pMesh->IIndexBuffer;
      this->meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      this->meshBuilder.m_IndexBuilder.m_bModify = false;
      this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = mdlHandleb;
      this->meshBuilder.m_IndexBuilder.m_nIndexOffset = this->meshBuilder.m_nFirstVertex;
      this->meshBuilder.m_IndexBuilder.m_pIndices = this->meshBuilder.m_pIndices;
      m_nIndexSize = this->meshBuilder.m_nIndexSize;
      this->meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      this->meshBuilder.m_IndexBuilder.m_nIndexSize = m_nIndexSize;
      CVertexBuilder::AttachBegin(
        this: &this->meshBuilder.m_VertexBuilder,
        pMesh: m_pMesh,
        nMaxVertexCount: mdlHandleb,
        desc: &this->meshBuilder);
      this->meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &this->meshBuilder.m_VertexBuilder);
      if ( vertCount > 0 )
      {
        v12 = 0;
        mdlHandlea = 0;
        mViewMatrixa = (const VMatrix *)vertCount;
        while ( 1 )
        {
          m_pCurrPosition = this->meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v14 = 1.0
              / (float)((float)((float)((float)(*(float *)((char *)&outVerts->x + v12) * mViewMatrix->m[3][0])
                                      + (float)(*(float *)((char *)&outVerts->y + v12) * mViewMatrix->m[3][1]))
                              + (float)(*(float *)((char *)&outVerts->z + v12) * mViewMatrix->m[3][2]))
                      + mViewMatrix->m[3][3]);
          v15 = (float)((float)((float)(*(float *)((char *)&outVerts->x + v12) * mViewMatrix->m[1][0])
                              + (float)(*(float *)((char *)&outVerts->y + v12) * mViewMatrix->m[1][1]))
                      + (float)(*(float *)((char *)&outVerts->z + v12) * mViewMatrix->m[1][2]))
              + mViewMatrix->m[1][3];
          v16 = (float)((float)((float)(*(float *)((char *)&outVerts->x + v12) * mViewMatrix->m[2][0])
                              + (float)(*(float *)((char *)&outVerts->y + v12) * mViewMatrix->m[2][1]))
                      + (float)(*(float *)((char *)&outVerts->z + v12) * mViewMatrix->m[2][2]))
              + mViewMatrix->m[2][3];
          *m_pCurrPosition = (float)((float)((float)((float)(*(float *)((char *)&outVerts->x + v12)
                                                           * mViewMatrix->m[0][0])
                                                   + (float)(*(float *)((char *)&outVerts->y + v12)
                                                           * mViewMatrix->m[0][1]))
                                           + (float)(*(float *)((char *)&outVerts->z + v12) * mViewMatrix->m[0][2]))
                                   + mViewMatrix->m[0][3])
                           * v14;
          m_pCurrPosition[1] = v15 * v14;
          m_pCurrPosition[2] = v16 * v14;
          *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                                    | ((this->m_DrawColor._color[1]
                                                                      | ((this->m_DrawColor._color[0]
                                                                        | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
          v17 = this->meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *v17 = 0.0;
          v17[1] = 0.0;
          CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
          mdlHandlea += 12;
          mViewMatrixa = (const VMatrix *)((char *)mViewMatrixa - 1);
          if ( mViewMatrixa == nullptr )
            break;
          v12 = mdlHandlea;
        }
      }
      if ( this->meshBuilder.m_bGenerateIndices )
      {
        v18 = CMeshBuilder::IndicesFromVertices(
                this: &this->meshBuilder,
                type: this->meshBuilder.m_Type,
                nVertexCount: this->meshBuilder.m_VertexBuilder.m_nVertexCount);
        CIndexBuilder::GenerateIndices(
          this: &this->meshBuilder.m_IndexBuilder,
          primitiveType: this->meshBuilder.m_Type,
          nIndexCount: v18);
      }
      ((void (__thiscall *)(IMesh *, int, int))this->meshBuilder.m_pMesh->UnlockMesh)(
        a1: this->meshBuilder.m_pMesh,
        a2: this->meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: this->meshBuilder.m_IndexBuilder.m_nIndexCount);
      this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      this->meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      this->meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      this->meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      this->meshBuilder.m_pMesh = nullptr;
      this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
      this->SetRenderMode(
        this,
        a2: this->m_RenderModeStack.m_Memory.m_pMemory[this->m_RenderModeStack.m_Size - 1],
        a3: false);
      --this->m_RenderModeStack.m_Size;
      v7 = vertCount;
    }
    ((void (__thiscall *)(IPhysicsCollision *, int))g_pPhysicsCollision->DestroyDebugMesh)(
      a1: g_pPhysicsCollision,
      a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094A50
// Name: public: virtual void CRender::PushInstanceData(class CMapInstance __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender::PushInstanceData(
        CRender *this,
        CMapInstance *pInstanceClass,
        Vector *InstanceOrigin,
        QAngle *InstanceAngles)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  const VMatrix *v10; // eax
  InstanceRenderingState_t v11; // [esp-10h] [ebp-1ECh]
  VMatrix result; // [esp+0h] [ebp-1DCh] BYREF
  matrix3x4_t TransRotMatrix; // [esp+40h] [ebp-19Ch] BYREF
  matrix3x4_t RotMatrix; // [esp+70h] [ebp-16Ch] BYREF
  matrix3x4_t TransMatrix; // [esp+A0h] [ebp-13Ch] BYREF
  matrix3x4_t Instance3x4Matrix; // [esp+D0h] [ebp-10Ch] BYREF
  Vector vOut; // [esp+100h] [ebp-DCh] BYREF
  SInstanceState InstanceState; // [esp+10Ch] [ebp-D0h] BYREF
  Vector vLocalOrigin; // [esp+1B0h] [ebp-2Ch] BYREF
  CUtlReferenceVector<CMapEntity> entityList; // [esp+1BCh] [ebp-20h] BYREF
  int v21; // [esp+1D8h] [ebp-4h]

  InstanceState.m_InstanceOrigin = *InstanceOrigin;
  InstanceState.m_InstanceAngles = *InstanceAngles;
  InstanceState.m_pInstanceClass = pInstanceClass;
  InstanceState.m_pTopInstanceClass = nullptr;
  AngleMatrix(angles: &InstanceState.m_InstanceAngles, matrix: &RotMatrix);
  SetIdentityMatrix(matrix: &TransMatrix);
  MatrixSetColumn(in: &InstanceState.m_InstanceOrigin, column: 3, out: &TransMatrix);
  ConcatTransforms(in1: &TransMatrix, in2: &RotMatrix, out: &TransRotMatrix);
  vLocalOrigin = vec3_origin;
  if ( pInstanceClass != nullptr && pInstanceClass->m_pInstancedMap != nullptr )
  {
    memset(&entityList, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&entityList,
      nGrowSize: 0,
      nInitSize: 0);
    entityList.m_Size = 0;
    entityList.m_pElements = nullptr;
    v21 = 3;
    CMapDoc::FindEntitiesByClassName(
      this: pInstanceClass->m_pInstancedMap,
      Found: &entityList,
      pszClassName: "func_instance_origin",
      bVisiblesOnly: false);
    if ( entityList.m_Size == 1 )
      (*entityList.m_Memory.m_pMemory)->m_pObject->GetOrigin(
        this: (*entityList.m_Memory.m_pMemory)->m_pObject,
        a2: &vLocalOrigin);
    v21 = -1;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &entityList);
  }
  *((float *)&entityList.m_Memory + 2) = -vLocalOrigin.x;
  *(float *)&entityList.m_Size = -vLocalOrigin.y;
  *(float *)&entityList.m_pElements = -vLocalOrigin.z;
  VectorRotate(in1: (const float *)&entityList.m_Memory + 2, in2: &RotMatrix, out: &vOut.x);
  SetIdentityMatrix(matrix: &TransMatrix);
  MatrixSetColumn(in: &vOut, column: 3, out: &TransMatrix);
  ConcatTransforms(in1: &TransMatrix, in2: &TransRotMatrix, out: &Instance3x4Matrix);
  v5 = this->m_CurrentInstanceState.m_InstanceMatrix.m[3][1];
  v6 = this->m_CurrentInstanceState.m_InstanceMatrix.m[3][0];
  *(matrix3x4_t *)&InstanceState.m_InstanceMatrix.m[0][0] = Instance3x4Matrix;
  *(_QWORD *)&InstanceState.m_InstanceMatrix.m[3][0] = 0;
  *(_QWORD *)&InstanceState.m_InstanceMatrix.m[3][2] = 0x3F80000000000000LL;
  v7 = 1.0
     / (float)((float)((float)((float)(v5 * InstanceState.m_InstanceOrigin.y)
                             + (float)(v6 * InstanceState.m_InstanceOrigin.x))
                     + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[3][2] * InstanceState.m_InstanceOrigin.z))
             + this->m_CurrentInstanceState.m_InstanceMatrix.m[3][3]);
  v8 = (float)((float)((float)((float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[1][1]
                                     * InstanceState.m_InstanceOrigin.y)
                             + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[1][0]
                                     * InstanceState.m_InstanceOrigin.x))
                     + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[1][2] * InstanceState.m_InstanceOrigin.z))
             + this->m_CurrentInstanceState.m_InstanceMatrix.m[1][3])
     * v7;
  v9 = (float)((float)((float)((float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[2][1]
                                     * InstanceState.m_InstanceOrigin.y)
                             + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[2][0]
                                     * InstanceState.m_InstanceOrigin.x))
                     + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[2][2] * InstanceState.m_InstanceOrigin.z))
             + this->m_CurrentInstanceState.m_InstanceMatrix.m[2][3])
     * v7;
  this->m_CurrentInstanceState.m_InstanceOrigin.x = (float)((float)((float)((float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[0][1]
                                                                                  * InstanceState.m_InstanceOrigin.y)
                                                                          + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[0][0]
                                                                                  * InstanceState.m_InstanceOrigin.x))
                                                                  + (float)(this->m_CurrentInstanceState.m_InstanceMatrix.m[0][2]
                                                                          * InstanceState.m_InstanceOrigin.z))
                                                          + this->m_CurrentInstanceState.m_InstanceMatrix.m[0][3])
                                                  * v7;
  this->m_CurrentInstanceState.m_InstanceOrigin.y = v8;
  this->m_CurrentInstanceState.m_InstanceOrigin.z = v9;
  if ( this->m_InstanceState.m_Size <= 0 )
  {
    this->m_bInstanceRendering = false;
    InstanceState.m_bIsEditable = true;
  }
  else
  {
    this->m_bInstanceRendering = true;
    CRender::BeginLocalTransfrom(this, matrix: &InstanceState.m_InstanceMatrix, MultiplyCurrent: true);
    if ( this->m_CurrentInstanceState.m_pTopInstanceClass != nullptr )
    {
      InstanceState.m_pTopInstanceClass = this->m_CurrentInstanceState.m_pTopInstanceClass;
    }
    else if ( !pInstanceClass->IsEditable(this: pInstanceClass) )
    {
      InstanceState.m_pTopInstanceClass = pInstanceClass;
    }
    if ( pInstanceClass->IsSelected(this: pInstanceClass) || this->m_InstanceSelectionDepth != 0 )
      ++this->m_InstanceSelectionDepth;
    v10 = VMatrix::operator*(
            this: &this->m_CurrentInstanceState.m_InstanceMatrix,
            &result,
            vm: &InstanceState.m_InstanceMatrix);
    VMatrix::operator=(this: &InstanceState.m_InstanceMatrix, mOther: v10);
    InstanceState.m_bIsEditable = pInstanceClass->IsEditable(this: pInstanceClass);
  }
  VMatrix::operator=(this: &InstanceState.m_InstanceRenderMatrix, mOther: this->m_LocalMatrix.m_Memory.m_pMemory);
  CUtlVector<SInstanceState,CUtlMemory<SInstanceState,int>>::InsertBefore(
    this: &this->m_InstanceState,
    elem: 0,
    src: &InstanceState);
  SInstanceState::operator=(this: &this->m_CurrentInstanceState, __that: &InstanceState);
  if ( pInstanceClass != nullptr )
  {
    if ( this->m_InstanceSelectionDepth <= 0 )
    {
      if ( pInstanceClass->IsEditable(this: pInstanceClass)
        || CMapDoc::m_pMapDoc->m_tShowInstance == INSTANCES_SHOW_NORMAL )
      {
        CRender::PushInstanceRendering(this, State: INSTANCE_STATE_OFF);
      }
      else
      {
        v11 = this->m_CurrentInstanceState.m_pInstanceClass->IsSelected(this: this->m_CurrentInstanceState.m_pInstanceClass)
            + 1;
        CRender::PushInstanceRendering(this, State: v11);
      }
    }
    else
    {
      CRender::PushInstanceRendering(this, State: INSTANCE_STACE_SELECTED);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094F10
// Name: public: CRender::CRender(void)
// Source: json
//------------------------------------------------------------------------------
CRender *__thiscall CRender::CRender(CRender *this)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *p_m_LocalMatrix; // eax
  VMatrix *m_pMemory; // ecx
  EditorRenderMode_t *v4; // ecx
  SInstanceState *v5; // ecx
  InstanceRenderingState_t *v6; // ecx
  vgui::ISchemeManager_vtbl *v7; // edi
  unsigned int v8; // eax
  int v9; // eax
  bool v10; // zf
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *v13; // ecx
  int v14; // eax
  VMatrix *v15; // edi
  VMatrix IdentityMatrix; // [esp+Ch] [ebp-A4h] BYREF
  unsigned __int8 dst[56]; // [esp+4Ch] [ebp-64h] BYREF
  CRender *v19; // [esp+84h] [ebp-2Ch]
  Vector InstanceOrigin; // [esp+88h] [ebp-28h] BYREF
  QAngle InstanceAngles; // [esp+94h] [ebp-1Ch] BYREF
  vgui::ISchemeManager *p_m_RenderModeStack; // [esp+A0h] [ebp-10h]
  int v23; // [esp+ACh] [ebp-4h]

  p_m_LocalMatrix = &this->m_LocalMatrix;
  this->__vftable = (CRender_vtbl *)&CRender::`vftable';
  v19 = this;
  p_m_RenderModeStack = (vgui::ISchemeManager *)&this->m_LocalMatrix;
  this->m_LocalMatrix.m_Memory.m_pMemory = nullptr;
  this->m_LocalMatrix.m_Memory.m_nAllocationCount = 0;
  this->m_LocalMatrix.m_Memory.m_nGrowSize = 0;
  v23 = 0;
  m_pMemory = this->m_LocalMatrix.m_Memory.m_pMemory;
  p_m_LocalMatrix->m_Size = 0;
  p_m_LocalMatrix->m_pElements = m_pMemory;
  v23 = 1;
  CMeshBuilder::CMeshBuilder(this: &this->meshBuilder);
  this->m_DrawColor = 0;
  this->m_TextColor = 0;
  this->m_HandleColor = 0;
  p_m_RenderModeStack = (vgui::ISchemeManager *)&this->m_RenderModeStack;
  this->m_RenderModeStack.m_Memory.m_pMemory = nullptr;
  this->m_RenderModeStack.m_Memory.m_nAllocationCount = 0;
  this->m_RenderModeStack.m_Memory.m_nGrowSize = 0;
  LOBYTE(v23) = 3;
  v4 = this->m_RenderModeStack.m_Memory.m_pMemory;
  this->m_RenderModeStack.m_Size = 0;
  this->m_RenderModeStack.m_pElements = v4;
  p_m_RenderModeStack = (vgui::ISchemeManager *)&this->m_InstanceState;
  this->m_InstanceState.m_Memory.m_pMemory = nullptr;
  this->m_InstanceState.m_Memory.m_nAllocationCount = 0;
  this->m_InstanceState.m_Memory.m_nGrowSize = 0;
  LOBYTE(v23) = 5;
  v5 = this->m_InstanceState.m_Memory.m_pMemory;
  this->m_InstanceState.m_Size = 0;
  this->m_InstanceState.m_pElements = v5;
  this->m_ShaderStencilState.m_nWriteMask = -1;
  this->m_ShaderStencilState.m_nTestMask = -1;
  this->m_ShaderStencilState.m_bEnable = false;
  this->m_ShaderStencilState.m_ZFailOp = SHADER_STENCILOP_KEEP;
  this->m_ShaderStencilState.m_FailOp = SHADER_STENCILOP_KEEP;
  this->m_ShaderStencilState.m_PassOp = SHADER_STENCILOP_KEEP;
  this->m_ShaderStencilState.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
  this->m_ShaderStencilState.m_nReferenceValue = 0;
  p_m_RenderModeStack = (vgui::ISchemeManager *)&this->m_InstanceRenderingState;
  this->m_InstanceRenderingState.m_Memory.m_pMemory = nullptr;
  this->m_InstanceRenderingState.m_Memory.m_nAllocationCount = 0;
  this->m_InstanceRenderingState.m_Memory.m_nGrowSize = 0;
  LOBYTE(v23) = 7;
  v6 = this->m_InstanceRenderingState.m_Memory.m_pMemory;
  this->m_InstanceRenderingState.m_Size = 0;
  this->m_InstanceRenderingState.m_pElements = v6;
  LOBYTE(v23) = 8;
  this->m_pView = nullptr;
  v7 = g_pVGuiSchemeManager->__vftable;
  p_m_RenderModeStack = g_pVGuiSchemeManager;
  v8 = g_pVGuiSchemeManager->GetDefaultScheme(this: g_pVGuiSchemeManager);
  v9 = (int)v7->GetIScheme(this: p_m_RenderModeStack, a2: v8);
  if ( v9 != 0 )
  {
    this->m_DefaultFont = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 12))(
                            a1: v9,
                            a2: aDefa_0,
                            a3: 0);
  }
  else
  {
    v10 = !s_bOnce;
    this->m_DefaultFont = 0;
    if ( v10 )
    {
      s_bOnce = true;
      MessageBoxA(
        hWnd: nullptr,
        lpText: "Failed to load the default scheme file. The map views may be missing some visual elements.",
        lpCaption: "Error",
        uType: 0x30u);
    }
  }
  this->m_pFlat[0] = nullptr;
  this->m_pWireframe[0] = nullptr;
  this->m_pTranslucentFlat[0] = nullptr;
  this->m_pLightmapGrid[0] = nullptr;
  this->m_pSelectionOverlay[0] = nullptr;
  this->m_pDotted[0] = nullptr;
  this->m_pFlatNoZ[0] = nullptr;
  this->m_pFlatNoCull[0] = nullptr;
  this->m_pFlat[1] = nullptr;
  this->m_pWireframe[1] = nullptr;
  this->m_pTranslucentFlat[1] = nullptr;
  this->m_pLightmapGrid[1] = nullptr;
  this->m_pSelectionOverlay[1] = nullptr;
  this->m_pDotted[1] = nullptr;
  this->m_pFlatNoZ[1] = nullptr;
  this->m_pFlatNoCull[1] = nullptr;
  this->m_pCurrentMaterial = nullptr;
  this->m_pBoundMaterial = nullptr;
  this->m_nDecalMode = 0;
  *(_WORD *)&this->m_bIsClientSpace = 0;
  *(_WORD *)&this->m_bIsRendering = 0;
  MatrixSetIdentity(dst: &IdentityMatrix);
  m_Size = this->m_LocalMatrix.m_Size;
  m_nAllocationCount = this->m_LocalMatrix.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(
      this: &this->m_LocalMatrix.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_LocalMatrix.m_Size;
  v13 = this->m_LocalMatrix.m_Memory.m_pMemory;
  v14 = this->m_LocalMatrix.m_Size - 1;
  this->m_LocalMatrix.m_pElements = v13;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[1], src: v13, count: v14 << 6);
  v15 = this->m_LocalMatrix.m_Memory.m_pMemory;
  if ( v15 != nullptr )
    *v15 = IdentityMatrix;
  MatrixSetIdentity(dst: &this->m_OrthoMatrix);
  this->m_eDefaultRenderMode = RENDER_MODE_FLAT;
  this->m_eCurrentRenderMode = RENDER_MODE_FLAT;
  this->m_bInstanceRendering = false;
  this->m_nInstanceCount = 0;
  this->m_InstanceSelectionDepth = 0;
  memset(&InstanceAngles, 0, sizeof(InstanceAngles));
  memset(&InstanceOrigin, 0, sizeof(InstanceOrigin));
  CRender::PushInstanceData(this, pInstanceClass: nullptr, &InstanceOrigin, &InstanceAngles);
  if ( LOBYTE(AfxGetModuleState()->m_pCurrentWinApp[4].m_dwRef) == 0 )
  {
    memset(dst, value: 0, count: sizeof(dst));
    *(_DWORD *)&dst[32] = g_materialSystemConfig.nFullbright;
    dst[37] = dst[37] & 0xE6 | 8;
    dst[36] = 97;
    memset(dst, 0, 16);
    *(_DWORD *)&dst[24] = 1;
    *(_DWORD *)&dst[28] = 0;
    g_pStudioRender->UpdateConfig(this: g_pStudioRender, a2: (const StudioRenderConfig_t *)dst);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011AB80
// Name: public: bool CRender::IsInLocalTransformMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRender::IsInLocalTransformMode(CRender *this)
{
  return this->m_bIsLocalTransform;
}

//------------------------------------------------------------------------------
// Address: 0x103B8DFA
// Name: public: void CDrawingManager::DrawRect(class CRect const __near &,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawingManager::DrawRect(CDrawingManager *this, int rect, unsigned int clrFill, unsigned int clrLine)
{
  int v5; // esi
  int v6; // edi
  CDC *m_dc; // eax
  HDC CompatibleDC; // eax
  HBITMAP CompatibleBitmap; // eax
  HBITMAP__ *v10; // eax
  CRect *v11; // esi
  int cx; // edx
  int v13; // ecx
  unsigned int v14; // ebx
  int v15; // edi
  bool v16; // cc
  bool v17; // zf
  int v18; // ebx
  unsigned int v19; // edi
  int v20; // ebx
  void *m_hObject; // eax
  CDC *v22; // [esp-10h] [ebp-80h]
  HDC__ *m_hDC; // [esp-Ch] [ebp-7Ch]
  CRect rectSrc; // [esp+10h] [ebp-60h] BYREF
  CRect rt; // [esp+20h] [ebp-50h] BYREF
  CDC dcMem; // [esp+30h] [ebp-40h] BYREF
  CBitmap bmpMem; // [esp+40h] [ebp-30h] BYREF
  CSize size; // [esp+48h] [ebp-28h] BYREF
  HBITMAP__ *hmbpDib; // [esp+50h] [ebp-20h]
  CBitmap *pOldBmp; // [esp+54h] [ebp-1Ch]
  CDrawingManager *v31; // [esp+58h] [ebp-18h]
  int yE; // [esp+5Ch] [ebp-14h]
  int xB; // [esp+60h] [ebp-10h]
  int v34; // [esp+6Ch] [ebp-4h]

  v31 = this;
  if ( clrFill != -1 || clrLine != -1 )
  {
    rt = *(CRect *)rect;
    CRect::NormalizeRect(this: &rt);
    v5 = rt.bottom - rt.top;
    v6 = rt.right - rt.left;
    size.cy = rt.bottom - rt.top;
    size.cx = rt.right - rt.left;
    if ( rt.right != rt.left && v5 != 0 )
    {
      CDC::CDC(this: &dcMem);
      m_dc = this->m_dc;
      v34 = 0;
      if ( m_dc != nullptr )
        m_dc = (CDC *)m_dc->m_hDC;
      CompatibleDC = CreateCompatibleDC(hdc: (HDC)m_dc);
      if ( CDC::Attach(this: &dcMem, hDC: CompatibleDC) != 0 )
      {
        bmpMem.m_hObject = nullptr;
        bmpMem.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
        m_hDC = v31->m_dc->m_hDC;
        LOBYTE(v34) = 1;
        CompatibleBitmap = CreateCompatibleBitmap(hdc: m_hDC, cx: v6, cy: v5);
        if ( CGdiObject::Attach(this: &bmpMem, hObject: CompatibleBitmap) == 0 )
          goto LABEL_37;
        pOldBmp = (CBitmap *)CDC::SelectGdiObject(hDC: dcMem.m_hDC, h: bmpMem.m_hObject);
        if ( pOldBmp == nullptr )
          AfxThrowInvalidArgException();
        v10 = CDrawingManager::CreateBitmap_32(&size, pBits: (void **)&rect);
        hmbpDib = v10;
        if ( v10 != nullptr && (v11 = (CRect *)rect, rect != 0) )
        {
          SelectObject(hdc: dcMem.m_hDC, h: v10);
          xB = 0;
          cx = size.cx;
          v13 = size.cx;
          rect = 1;
          yE = size.cy;
          if ( clrLine != -1 )
          {
            v14 = BYTE2(clrLine) | ((BYTE1(clrLine) | ((clrLine | 0xFFFFFF00) << 8)) << 8);
            if ( size.cx > 0 )
            {
              memset32(v11, v14, size.cx);
              v11 = (CRect *)((char *)v11 + 4 * cx);
            }
            if ( size.cy > 1 )
            {
              v15 = 4 * cx;
              memcpy(
                dst: (unsigned __int8 *)&v11->left + 4 * cx * (size.cy - 2),
                src: (unsigned __int8 *)v11 - 4 * cx,
                count: 4 * cx);
              if ( size.cy > 2 )
              {
                v16 = size.cx < 2;
                v11->left = v14;
                if ( !v16 )
                  *(_DWORD *)((char *)v11 + v15 - 4) = v14;
                v11 = (CRect *)((char *)v11 + 4);
              }
              cx = size.cx;
            }
            xB = 1;
            v13 = cx - 1;
            rect = 2;
            yE = size.cy - 1;
          }
          if ( rect <= yE && xB < v13 )
          {
            v17 = clrLine == -1;
            v18 = v13 - xB;
            memset32(
              v11,
              clrFill != -1 ? BYTE2(clrFill) | ((BYTE1(clrFill) | ((clrFill | 0xFFFFFF00) << 8)) << 8) : 0,
              v13 - xB);
            v11 = (CRect *)((char *)v11 + 4 * v18);
            if ( !v17 )
              v11 = (CRect *)((char *)v11 + 4);
          }
          if ( rect < yE )
          {
            v19 = 4 * cx;
            v20 = yE - rect;
            do
            {
              memcpy(dst: (unsigned __int8 *)v11, src: (unsigned __int8 *)v11 - v19, count: v19);
              v11 = (CRect *)((char *)v11 + v19);
              --v20;
            }
            while ( v20 != 0 );
            cx = size.cx;
          }
          if ( clrFill == -1 )
          {
            rectSrc.left = 0;
            rectSrc.top = 0;
            rectSrc.bottom = size.cy;
            v22 = v31->m_dc;
            rectSrc.right = cx;
            CDrawingManager::DrawAlpha(this: v31, pDstDC: v22, rectDst: &rt, pSrcDC: &dcMem, &rectSrc);
          }
          else
          {
            BitBlt(
              hdc: v31->m_dc->m_hDC,
              x: rt.left,
              y: rt.top,
              cx,
              cy: size.cy,
              hdcSrc: dcMem.m_hDC,
              x1: 0,
              y1: 0,
              rop: 0xCC0020u);
          }
          m_hObject = pOldBmp;
          if ( pOldBmp != nullptr )
            m_hObject = pOldBmp->m_hObject;
          CDC::SelectGdiObject(hDC: dcMem.m_hDC, h: m_hObject);
          DeleteObject(ho: hmbpDib);
          bmpMem.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
        }
        else
        {
LABEL_37:
          bmpMem.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
        }
        LOBYTE(v34) = 0;
        CGdiObject::~CGdiObject(this: &bmpMem);
      }
      v34 = -1;
      CDC::~CDC(this: &dcMem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059DEC0
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}
