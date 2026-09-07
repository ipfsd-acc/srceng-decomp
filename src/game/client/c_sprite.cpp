// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_sprite.cpp
// Functions: 12
// ============================================================

#include "game\client\c_sprite.h"

//------------------------------------------------------------------------------
// Address: 0x1008E570
// Name: float StandardGlowBlend(struct pixelvis_queryparams_t const __near &,int __near *,int,int,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl StandardGlowBlend(
        const pixelvis_queryparams_t *params,
        int *queryHandle,
        int rendermode,
        int renderfx,
        int alpha,
        float *pscale)
{
  double v6; // st7
  bool v7; // cf
  double result; // st7
  double v9; // st7
  float v10; // xmm1_4
  float v11; // xmm0_4
  float brightness; // [esp+4h] [ebp-8h]
  float dist; // [esp+8h] [ebp-4h]
  float dista; // [esp+8h] [ebp-4h]

  v6 = PixelVisibility_FractionVisible(params, queryHandle);
  brightness = v6;
  v7 = v6 > 0.0;
  result = 0.0;
  if ( v7 )
  {
    v9 = GlowSightDistance(glowOrigin: &params->position, bShouldTrace: false);
    dist = v9;
    v7 = v9 > 0.0;
    result = 0.0;
    if ( v7 )
    {
      if ( renderfx == 14 )
      {
        return (double)alpha * 0.0039215689 * brightness;
      }
      else
      {
        v10 = dist;
        v11 = 1440000.0 / (float)(v10 * v10);
        if ( v11 >= 0.0 )
        {
          if ( v11 <= 1.0 )
            dista = 1440000.0 / (float)(dist * dist);
          else
            dista = 1.0;
        }
        else
        {
          dista = 0.0;
        }
        if ( rendermode != 9 )
        {
          if ( *pscale == 0.0 )
            *pscale = 1.0;
          *pscale = (float)(v10 * 0.0049999999) * *pscale;
        }
        return dista * brightness;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E640
// Name: public: virtual float C_SpriteRenderer::GlowBlend(class CEngineSprite __near *,class Vector const __near &,int,int,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_SpriteRenderer::GlowBlend(
        C_SpriteRenderer *this,
        CEngineSprite *psprite,
        const Vector *entorigin,
        int rendermode,
        int renderfx,
        int alpha,
        float *pscale)
{
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  pixelvis_queryparams_t params; // [esp+0h] [ebp-1Ch] BYREF

  if ( psprite == nullptr
    || (LODWORD(v7) = COERCE_UNSIGNED_INT(psprite->down - psprite->up) & _mask__AbsFloat_,
        LODWORD(v8) = COERCE_UNSIGNED_INT(psprite->right - psprite->left) & _mask__AbsFloat_,
        v7 == 0.0)
    || v8 == 0.0 )
  {
    v9 = 1.0;
  }
  else
  {
    v9 = v8 / v7;
  }
  params.position = *entorigin;
  params.proxyAspect = v9;
  params.proxySize = 2.0;
  params.fadeTime = 0.0625;
  *(_WORD *)&params.bSetup = 1;
  return StandardGlowBlend(&params, queryHandle: &this->m_queryHandle, rendermode, renderfx, alpha, pscale);
}

//------------------------------------------------------------------------------
// Address: 0x1008E700
// Name: public: virtual float C_Sprite::GlowBlend(class CEngineSprite __near *,class Vector const __near &,int,int,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_Sprite::GlowBlend(
        C_Sprite *this,
        CEngineSprite *psprite,
        const Vector *entorigin,
        int rendermode,
        int renderfx,
        int alpha,
        float *pscale)
{
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float m_lastInterpolationTime; // xmm1_4
  pixelvis_queryparams_t params; // [esp+0h] [ebp-1Ch] BYREF

  if ( psprite == nullptr
    || (LODWORD(v7) = COERCE_UNSIGNED_INT(psprite->down - psprite->up) & _mask__AbsFloat_,
        LODWORD(v8) = COERCE_UNSIGNED_INT(psprite->right - psprite->left) & _mask__AbsFloat_,
        v7 == 0.0)
    || v8 == 0.0 )
  {
    v9 = 1.0;
  }
  else
  {
    v9 = v8 / v7;
  }
  params.position = *entorigin;
  m_lastInterpolationTime = this->m_VarMap.m_lastInterpolationTime;
  params.proxyAspect = v9;
  params.proxySize = m_lastInterpolationTime;
  params.fadeTime = 0.0625;
  *(_WORD *)&params.bSetup = 1;
  return StandardGlowBlend(&params, queryHandle: (int *)&this->IClientRenderable, rendermode, renderfx, alpha, pscale);
}

//------------------------------------------------------------------------------
// Address: 0x1008E7C0
// Name: public: static void C_SpriteRenderer::GetSpriteAxes(enum C_SpriteRenderer::SPRITETYPE,class Vector const __near &,class QAngle const __near &,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_SpriteRenderer::GetSpriteAxes(
        C_SpriteRenderer::SPRITETYPE type,
        const Vector *origin,
        float angles,
        Vector *forward,
        Vector *right,
        Vector *up)
{
  float v6; // xmm0_4
  C_SpriteRenderer::SPRITETYPE v7; // eax
  Vector *v8; // eax
  Vector *v9; // esi
  float y; // xmm1_4
  Vector *v11; // eax
  Vector *v12; // edi
  int v13; // esi
  int v14; // ebx
  float *v15; // edi
  double v16; // st7
  float z; // xmm0_4
  Vector *v18; // eax
  const Vector *v19; // eax
  Vector *v20; // edi
  int v21; // esi
  int v22; // ebx
  float *v23; // edi
  float v24; // xmm1_4
  Vector tvec; // [esp+0h] [ebp-18h] BYREF
  float angle; // [esp+Ch] [ebp-Ch]
  float v27; // [esp+10h] [ebp-8h]
  int v28; // [esp+14h] [ebp-4h]
  float sr; // [esp+20h] [ebp+8h]

  v6 = *(float *)(LODWORD(angles) + 8);
  v7 = type;
  if ( v6 != 0.0 && type == SPR_VP_PARALLEL )
    v7 = SPR_VP_PARALLEL_ORIENTED;
  switch ( v7 )
  {
    case SPR_VP_PARALLEL_UPRIGHT:
      z = CurrentViewForward()->z;
      if ( z <= 0.99984801 && z >= -0.99984801 )
      {
        v18 = up;
        up->x = 0.0;
        v18->y = 0.0;
        v18->z = 1.0;
        v19 = CurrentViewForward();
        v9 = right;
        right->x = v19->y;
        LODWORD(v9->y) = LODWORD(CurrentViewForward()->x) ^ _mask__NegFloat_;
        goto LABEL_8;
      }
      break;
    case SPR_FACING_UPRIGHT:
      tvec.x = -origin->x;
      tvec.y = -origin->y;
      tvec.z = -origin->z;
      VectorNormalize(vec: &tvec);
      if ( tvec.z <= 0.99984801 && tvec.z >= -0.99984801 )
      {
        v8 = up;
        v9 = right;
        up->z = 1.0;
        y = tvec.y;
        v8->x = 0.0;
        v8->y = 0.0;
        v9->x = y;
        LODWORD(v9->y) = LODWORD(tvec.x) ^ _mask__NegFloat_;
LABEL_8:
        v9->z = 0.0;
        VectorNormalize(vec: v9);
        v11 = forward;
        LODWORD(forward->x) = LODWORD(v9->y) ^ _mask__NegFloat_;
        v11->y = v9->x;
        v11->z = 0.0;
      }
      break;
    case SPR_VP_PARALLEL:
      v12 = right;
      v13 = 0;
      v14 = (char *)up - (char *)right;
      v28 = (char *)forward - (char *)right;
      while ( 1 )
      {
        v15 = (float *)((char *)&v12->x + v13);
        *(float *)((char *)v15 + v14) = *(float *)((char *)&CurrentViewUp()->x + v13);
        *v15 = *(float *)((char *)&CurrentViewRight()->x + v13);
        v16 = *(float *)((char *)&CurrentViewForward()->x + v13);
        v13 += 4;
        *(float *)((char *)v15 + v28) = v16;
        if ( v13 >= 12 )
          break;
        v12 = right;
      }
      break;
    case SPR_ORIENTED:
      AngleVectors(angles: (const QAngle *)LODWORD(angles), forward, right, up);
      break;
    case SPR_VP_PARALLEL_ORIENTED:
      angle = v6 * 0.0174532925199433;
      v27 = COERCE_FLOAT(&angles);
      angles = cos(angle);
      sr = sin(angle);
      v20 = right;
      v21 = 0;
      v22 = (char *)forward - (char *)right;
      v28 = (char *)up - (char *)right;
      while ( 1 )
      {
        v23 = (float *)((char *)&v20->x + v21);
        *(float *)((char *)v23 + v22) = *(float *)((char *)&CurrentViewForward()->x + v21);
        angle = *(float *)((char *)&CurrentViewRight()->x + v21);
        *v23 = (float)(*(float *)((char *)&CurrentViewUp()->x + v21) * sr) + (float)(angle * angles);
        v27 = *(float *)((char *)&CurrentViewRight()->x + v21);
        v24 = *(float *)((char *)&CurrentViewUp()->x + v21);
        v21 += 4;
        *(float *)((char *)v23 + v28) = (float)(v24 * angles) - (float)(v27 * sr);
        if ( v21 >= 12 )
          break;
        v20 = right;
      }
      break;
    default:
      _Warning(a1: "GetSpriteAxes: Bad sprite type %d\n", v7);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EAD0
// Name: public: virtual void C_Sprite::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall C_Sprite::GetToolRecordingState(C_Sprite *this, KeyValues *msg)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *v10; // ecx
  C_BaseEntity *v11; // edi
  float *Ptr; // ebx
  const Vector *v13; // eax
  double z; // st7
  bool (__thiscall *GetAttachment_2)(IClientRenderable *, int, Vector *, QAngle *); // eax
  C_BaseViewModel *v16; // eax
  IVModelInfoClient_vtbl *v17; // edi
  const struct model_t *v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  float v22; // xmm0_4
  unsigned __int8 b; // dl
  unsigned __int8 r; // bl
  unsigned __int8 RenderBrightness; // al
  QAngle temp; // [esp+4h] [ebp-10h] BYREF
  float c; // [esp+10h] [ebp-4h] OVERLAPPED

  if ( ToolsEnabled() )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CSprite::GetToolRecordingState",
      a3: 0,
      a4: "Tools",
      a5: false,
      a6: 4);
    C_BaseEntity::GetToolRecordingState(this, msg);
    m_Index = this->m_hAttachedToEntity.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v4 = (unsigned __int16)m_Index;
      v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v6 = HIWORD(m_Index);
      if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
      {
        v7 = v4;
        v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
        v9 = &g_pEntityList->m_EntPtrArray[v7];
        v10 = v8 ? v9->m_pEntity : nullptr;
        v11 = (C_BaseEntity *)((int (__thiscall *)(IHandleEntity *))v10->__vftable[2].SetRefEHandle)(a1: v10);
        if ( v11 != nullptr )
        {
          Ptr = (float *)KeyValues::GetPtr(this: msg, keyName: "baseentity", defaultValue: nullptr);
          v13 = this->GetAbsOrigin(this);
          Ptr[5] = v13->x;
          Ptr[6] = v13->y;
          z = v13->z;
          GetAttachment_2 = v11->GetAttachment_2;
          Ptr[7] = z;
          GetAttachment_2(
            this: &v11->IClientRenderable,
            a2: this->m_nAttachment.m_Value,
            a3: (Vector *)(Ptr + 5),
            a4: &temp);
          v16 = ToBaseViewModel(pEntity: v11);
          KeyValues::SetInt(this: msg, keyName: "viewmodel", value: v16 != nullptr);
        }
      }
    }
    c = C_Sprite::GetRenderScale(this);
    if ( this->m_bWorldSpaceScale.m_Value )
    {
      v17 = modelinfo->__vftable;
      v18 = this->GetModel(this: &this->IClientRenderable);
      v19 = (int)v17->GetModelExtraData(this: modelinfo, a2: v18);
      v20 = *(_DWORD *)(v19 + 8);
      v21 = *(_DWORD *)(v19 + 4);
      if ( v21 >= v20 )
        v21 = v20;
      v22 = c / (float)v21;
    }
    else
    {
      v22 = c;
    }
    b = this->m_clrRender.m_Value.b;
    r = this->m_clrRender.m_Value.r;
    BYTE1(c) = this->m_clrRender.m_Value.g;
    BYTE2(c) = b;
    if ( (_S6_21 & 1) == 0 )
    {
      _S6_21 |= 1u;
      state_4.m_Color = 0;
    }
    state_4.m_flRenderScale = v22;
    state_4.m_flFrame = this->m_flFrame.m_Value;
    state_4.m_flProxyRadius = this->m_flGlowProxySize.m_Value;
    state_4.m_nRenderMode = this->m_nRenderMode;
    state_4.m_nRenderFX = this->m_nRenderFX != 0;
    RenderBrightness = C_Sprite::GetRenderBrightness(this);
    state_4.m_Color._color[0] = r;
    *(_WORD *)&state_4.m_Color._color[1] = *(_WORD *)((char *)&c + 1);
    state_4.m_Color._color[3] = RenderBrightness;
    KeyValues::SetPtr(this: msg, keyName: "sprite", value: &state_4);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008ECE0
// Name: public: static void C_Sprite::DestroyAllClientside(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_Sprite::DestroyAllClientside()
{
  while ( g_ClientsideSprites.m_Size > 0 )
    (*g_ClientsideSprites.m_Memory.m_pMemory)->Release(this: &(*g_ClientsideSprites.m_Memory.m_pMemory)->IClientNetworkable);
}

//------------------------------------------------------------------------------
// Address: 0x1008ED10
// Name: void DrawSpriteModel(class IClientEntity __near *,class CEngineSprite __near *,class Vector const __near &,float,float,int,int,int,int,int,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawSpriteModel(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IClientEntity *baseentity,
        CEngineSprite *psprite,
        const Vector *origin,
        float fscale,
        float frame,
        RenderMode_t rendermode,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a,
        const Vector *forward,
        const Vector *right,
        const Vector *up,
        float flHDRColorScale)
{
  RenderMode_t v17; // esi
  IMaterial *Material; // edi
  int v19; // eax
  int v20; // ebx
  IMaterial *v21; // eax
  int v22; // eax
  IMesh *v23; // edi
  float x; // xmm1_4
  float v25; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm7_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm2_4
  int v40; // esi
  float *v41; // eax
  float v42; // xmm0_4
  float v43; // xmm1_4
  float *m_pCurrPosition; // eax
  float v45; // xmm2_4
  float *v46; // eax
  float v47; // xmm0_4
  float v48; // xmm1_4
  float *v49; // eax
  float v50; // xmm2_4
  float *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm1_4
  float *v54; // eax
  float v55; // xmm2_4
  float *v56; // eax
  float v57; // xmm0_4
  float v58; // xmm1_4
  float *v59; // eax
  int m_nVertexCount; // eax
  void (__thiscall *UnlockMesh)(IMesh *, int, int, MeshDesc_t *); // edx
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-224h] BYREF
  float flMaxU; // [esp+224h] [ebp-3Ch] BYREF
  Vector vec_a; // [esp+228h] [ebp-38h]
  float flMinV; // [esp+234h] [ebp-2Ch] BYREF
  Vector vec_d; // [esp+238h] [ebp-28h]
  float flMaxV; // [esp+244h] [ebp-1Ch] BYREF
  Vector vec_c; // [esp+248h] [ebp-18h]
  Vector vec_b; // [esp+254h] [ebp-Ch]

  if ( fscale <= 0.0 )
    fscale = 1.0;
  v17 = rendermode;
  if ( rendermode == kRenderNormal )
    ((void (__stdcall *)(int))render->SetBlend)(a1: 1065353216);
  Material = CEngineSprite::GetMaterial(this: psprite, nRenderMode: v17, nFrame: (int)frame);
  if ( Material != nullptr )
  {
    v19 = ((int (__thiscall *)(IMaterialSystem *, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int))materials->GetRenderContext)(
            a1: materials,
            a2: a1,
            a3: a2,
            a4: a3,
            a5: meshBuilder.m_VertexSize_Position,
            a6: meshBuilder.m_VertexSize_BoneWeight,
            a7: meshBuilder.m_VertexSize_BoneMatrixIndex,
            a8: meshBuilder.m_VertexSize_Normal,
            a9: meshBuilder.m_VertexSize_Color,
            a10: meshBuilder.m_VertexSize_Specular,
            a11: meshBuilder.m_VertexSize_TexCoord[0],
            a12: meshBuilder.m_VertexSize_TexCoord[1],
            a13: meshBuilder.m_VertexSize_TexCoord[2],
            a14: meshBuilder.m_VertexSize_TexCoord[3],
            a15: meshBuilder.m_VertexSize_TexCoord[4],
            a16: meshBuilder.m_VertexSize_TexCoord[5],
            a17: meshBuilder.m_VertexSize_TexCoord[6],
            a18: meshBuilder.m_VertexSize_TexCoord[7],
            a19: meshBuilder.m_VertexSize_TangentS);
    v20 = v19;
    if ( v19 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 8))(a1: v19);
    if ( ShouldDrawInWireFrameMode()
      || r_drawsprites.m_pParent != nullptr && r_drawsprites.m_pParent->m_Value.m_nValue == 2 )
    {
      v21 = materials->FindMaterial(
              this: materials,
              a2: "debug/debugspritewireframe",
              a3: "Other textures",
              a4: 1,
              a5: 0);
      meshBuilder.m_VertexSize_TangentS = 0;
      meshBuilder.m_VertexSize_TexCoord[7] = (int)v21;
    }
    else
    {
      if ( baseentity != nullptr )
        meshBuilder.m_VertexSize_TangentS = (int)&baseentity->IClientRenderable;
      else
        meshBuilder.m_VertexSize_TangentS = 0;
      meshBuilder.m_VertexSize_TexCoord[7] = (int)Material;
    }
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v20 + 36))(
      a1: v20,
      a2: meshBuilder.m_VertexSize_TexCoord[7],
      a3: meshBuilder.m_VertexSize_TangentS);
    v22 = (int)Material->FindVarFast(this: Material, a2: "$HDRCOLORSCALE", a3: &s_nHDRColorScaleCache);
    if ( v22 != 0 )
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v22 + 44))(
        a1: v22,
        a2: LODWORD(flHDRColorScale),
        a3: LODWORD(flHDRColorScale),
        a4: LODWORD(flHDRColorScale));
    v23 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v20 + 228))(
                     a1: v20,
                     a2: 1,
                     a3: 0,
                     a4: 0,
                     a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v23;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v23->SetPrimitiveType(this: v23, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v23->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v23, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    x = up->x;
    v25 = psprite->down * fscale;
    vec_a.x = (float)(up->x * v25) + origin->x;
    y = up->y;
    vec_a.y = (float)(y * v25) + origin->y;
    z = up->z;
    v28 = (float)(z * v25) + origin->z;
    v29 = psprite->left * fscale;
    vec_a.z = v28;
    v30 = right->x;
    vec_b.x = right->x * v29;
    v31 = right->y;
    vec_b.y = v31 * v29;
    v32 = right->z * v29;
    v33 = psprite->up * fscale;
    v34 = (float)(x * v33) + origin->x;
    v35 = (float)(y * v33) + origin->y;
    v36 = (float)(z * v33) + origin->z;
    v37 = psprite->right * fscale;
    v38 = right->z * v37;
    vec_b.z = v32;
    vec_c.x = v34;
    vec_c.y = v35;
    vec_c.z = v36;
    vec_d.x = v30 * v37;
    vec_d.y = v31 * v37;
    vec_d.z = v38;
    CEngineSprite::GetTexCoordRange(
      this: psprite,
      pMinU: (float *)&rendermode,
      pMinV: &flMinV,
      pMaxU: &flMaxU,
      pMaxV: &flMaxV);
    v39 = vec_b.z + vec_a.z;
    v40 = b | ((g | ((r | (a << 8)) << 8)) << 8);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v40;
    v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v42 = flMaxV;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = rendermode;
    v43 = vec_b.y + vec_a.y;
    v41[1] = v42;
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vec_b.x + vec_a.x;
    m_pCurrPosition[1] = v43;
    m_pCurrPosition[2] = v39;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v45 = vec_c.z + vec_b.z;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v40;
    v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v47 = flMinV;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = rendermode;
    v48 = vec_c.y + vec_b.y;
    v46[1] = v47;
    v49 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vec_c.x + vec_b.x;
    v49[1] = v48;
    v49[2] = v45;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v50 = vec_d.z + vec_c.z;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v40;
    v51 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v52 = flMinV;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = flMaxU;
    v53 = vec_d.y + vec_c.y;
    v51[1] = v52;
    v54 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vec_d.x + vec_c.x;
    v54[1] = v53;
    v54[2] = v50;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v55 = vec_d.z + vec_a.z;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v40;
    v56 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v57 = flMaxV;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = flMaxU;
    v58 = vec_d.y + vec_a.y;
    v56[1] = v57;
    v59 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vec_d.x + vec_a.x;
    v59[1] = v58;
    v59[2] = v55;
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
    UnlockMesh = meshBuilder.m_pMesh->UnlockMesh;
    meshBuilder.m_VertexSize_BoneWeight = (int)&meshBuilder;
    ((void (__thiscall *)(IMesh *, int, int))UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v23->Draw_2(this: v23, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v20 + 12))(a1: v20);
    (*(void (__thiscall **)(int))(*(_DWORD *)v20 + 4))(a1: v20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F260
// Name: public: int C_SpriteRenderer::DrawSprite(class IClientEntity __near *,struct model_t const __near *,class Vector const __near &,class QAngle const __near &,float,class IClientEntity __near *,int,int,int,int,int,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_SpriteRenderer::DrawSprite@<eax>(
        C_SpriteRenderer *this@<ecx>,
        int a2@<ebx>,
        IClientEntity *entity,
        const struct model_t *model,
        const Vector *origin,
        const QAngle *angles,
        float frame,
        IClientEntity *attachedto,
        int attachmentindex,
        RenderMode_t rendermode,
        int renderfx,
        int alpha,
        int r,
        int g,
        int b,
        float scale,
        float flHDRColorScale)
{
  C_PhysPropClientside *v17; // edi
  C_BaseEntity *v18; // esi
  IClientLeafSystem_vtbl *v19; // ebx
  unsigned __int16 *v20; // eax
  float v21; // xmm0_4
  C_SpriteRenderer::SPRITETYPE BreakableCount; // eax
  QAngle temp; // [esp+64h] [ebp-40h] BYREF
  Vector forward; // [esp+70h] [ebp-34h] BYREF
  Vector right; // [esp+7Ch] [ebp-28h] BYREF
  Vector up; // [esp+88h] [ebp-1Ch] BYREF
  Vector effect_origin; // [esp+94h] [ebp-10h] BYREF
  C_SpriteRenderer *v30; // [esp+A0h] [ebp-4h]
  float blend; // [esp+B0h] [ebp+Ch]

  v30 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_SpriteRenderer::DrawSprite",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  if ( r_drawsprites.m_pParent != nullptr
    && r_drawsprites.m_pParent->m_Value.m_nValue != 0
    && model != nullptr
    && modelinfo->GetModelType(this: modelinfo, a2: model) == 2
    && (v17 = (C_PhysPropClientside *)modelinfo->GetModelExtraData(this: modelinfo, a2: model)) != nullptr )
  {
    effect_origin = *origin;
    if ( attachedto != nullptr )
    {
      v18 = attachedto->GetBaseEntity(this: attachedto);
      if ( v18 != nullptr )
      {
        if ( CurrentViewID() == VIEW_REFLECTION )
        {
          v19 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
          v20 = v18->RenderHandle(this: &v18->IClientRenderable);
          if ( v19->IsRenderingWithViewModels(this: g_pClientLeafSystem, a2: *v20) )
          {
LABEL_17:
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            return 0;
          }
        }
        v18->GetAttachment_2(this: &v18->IClientRenderable, a2: attachmentindex, a3: &effect_origin, a4: &temp);
      }
    }
    if ( rendermode != kRenderNormal )
    {
      blend = ((double (__thiscall *)(IVRenderView *, int))render->GetBlend)(a1: render, a2);
      if ( rendermode == kRenderGlow || rendermode == kRenderWorldGlow )
      {
        blend = ((double (__thiscall *)(C_SpriteRenderer *, C_PhysPropClientside *, Vector *, RenderMode_t, int, int, float *))v30->GlowBlend)(
                  a1: v30,
                  a2: v17,
                  a3: &effect_origin,
                  a4: rendermode,
                  a5: renderfx,
                  a6: alpha,
                  a7: &scale)
              * blend;
        v21 = blend;
        r = (int)(float)((float)r * blend);
        g = (int)(float)((float)g * blend);
        b = (int)(float)((float)b * blend);
      }
      else
      {
        v21 = blend;
      }
      ((void (__cdecl *)(_DWORD))render->SetBlend)(a1: LODWORD(v21));
      if ( blend <= 0.0 )
        goto LABEL_17;
    }
    BreakableCount = C_PhysPropClientside::GetBreakableCount(this: v17);
    C_SpriteRenderer::GetSpriteAxes(type: BreakableCount, origin, angles: *(float *)&angles, &forward, &right, &up);
    DrawSpriteModel(
      a1: alpha,
      a2: (int)v17,
      a3: rendermode,
      baseentity: entity,
      psprite: (CEngineSprite *)v17,
      origin: &effect_origin,
      fscale: scale,
      frame,
      rendermode,
      r,
      g,
      b,
      a: alpha,
      &forward,
      &right,
      &up,
      flHDRColorScale);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F4D0
// Name: public: virtual bool C_Sprite::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_Sprite::KeyValue(C_Sprite *this, char *szKeyName, const char *szValue)
{
  long double v4; // st7
  long double v6; // st7
  long double v7; // st7
  long double v8; // st7
  long double v9; // st7
  RenderMode_t v10; // eax
  const char *v11; // eax
  float szValuea; // [esp+14h] [ebp+Ch]
  float szValueb; // [esp+14h] [ebp+Ch]
  float szValuec; // [esp+14h] [ebp+Ch]
  float szValued; // [esp+14h] [ebp+Ch]
  float szValuee; // [esp+14h] [ebp+Ch]

  if ( _V_stricmp(s1: szKeyName, s2: "scale") == 0 )
  {
    v4 = atof(nptr: szValue);
    if ( this->m_flSpriteScale.m_Value != v4 )
    {
      szValuea = v4;
      this->m_flSpriteScale.m_Value = szValuea;
      return true;
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "framerate") == 0 )
  {
    v6 = atof(nptr: szValue);
    if ( this->m_flSpriteFramerate.m_Value != v6 )
    {
      szValueb = v6;
      this->m_flSpriteFramerate.m_Value = szValueb;
      return true;
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "GlowProxySize") == 0 )
  {
    v7 = atof(nptr: szValue);
    if ( this->m_flGlowProxySize.m_Value != v7 )
    {
      szValuec = v7;
      this->m_flGlowProxySize.m_Value = szValuec;
      return true;
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "frame") == 0 )
  {
    v8 = atof(nptr: szValue);
    if ( this->m_flFrame.m_Value != v8 )
    {
      szValued = v8;
      this->m_flFrame.m_Value = szValued;
      return true;
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "HDRColorScale") == 0 )
  {
    v9 = atof(nptr: szValue);
    if ( this->m_flHDRColorScale.m_Value != v9 )
    {
      szValuee = v9;
      this->m_flHDRColorScale.m_Value = szValuee;
      return true;
    }
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "rendermode") == 0 )
  {
    v10 = atoi(nptr: szValue);
    C_BaseEntity::SetRenderMode(this, nRenderMode: v10, bForceUpdate: false);
    return true;
  }
  if ( _V_stricmp(s1: szKeyName, s2: "model") == 0 )
  {
    v11 = AllocPooledString(pszValue: szValue);
    C_BaseEntity::SetModelName(this, name: v11);
    return true;
  }
  return C_BaseEntity::KeyValue(this, szKeyName, szValue);
}

//------------------------------------------------------------------------------
// Address: 0x1008F6C0
// Name: public: bool C_Sprite::InitializeClientside(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_Sprite::InitializeClientside(C_Sprite *this)
{
  C_Sprite_vtbl *v2; // edi
  const char *ModelName; // eax
  char result; // al
  int m_Size; // eax
  int v6; // edi
  C_Sprite **m_pMemory; // ecx
  int v8; // eax
  C_Sprite **v9; // eax
  const struct model_t *v10; // eax
  Vector mins; // [esp+20h] [ebp-18h] BYREF
  Vector maxs; // [esp+2Ch] [ebp-Ch] BYREF

  v2 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  ModelName = C_BaseEntity::GetModelName(this);
  result = v2->InitializeAsClientEntity(this, a2: ModelName, a3: false);
  if ( result != 0 )
  {
    this->m_bClientOnly = true;
    m_Size = g_ClientsideSprites.m_Size;
    v6 = g_ClientsideSprites.m_Size;
    if ( g_ClientsideSprites.m_Size + 1 > g_ClientsideSprites.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_ClientsideSprites,
        num: g_ClientsideSprites.m_Size - g_ClientsideSprites.m_Memory.m_nAllocationCount + 1);
      m_Size = g_ClientsideSprites.m_Size;
    }
    m_pMemory = g_ClientsideSprites.m_Memory.m_pMemory;
    g_ClientsideSprites.m_Size = m_Size + 1;
    v8 = m_Size - v6;
    g_ClientsideSprites.m_pElements = g_ClientsideSprites.m_Memory.m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(
        dest: &g_ClientsideSprites.m_Memory.m_pMemory[v6 + 1],
        src: &g_ClientsideSprites.m_Memory.m_pMemory[v6],
        count: 4 * v8);
      m_pMemory = g_ClientsideSprites.m_Memory.m_pMemory;
    }
    v9 = &m_pMemory[v6];
    if ( v9 != nullptr )
      *v9 = this;
    this->Spawn(this);
    v10 = this->GetModel(this: &this->IClientRenderable);
    if ( v10 != nullptr )
    {
      modelinfo->GetModelBounds(this: modelinfo, a2: v10, a3: &mins, a4: &maxs);
      CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, &mins, &maxs);
    }
    C_BaseEntity::SetBlocksLOS(this, bBlocksLOS: false);
    ((void (__thiscall *)(C_Sprite *, int))this->SetNextClientThink)(a1: this, a2: -1082130432);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008F7D0
// Name: public: static void C_Sprite::ParseAllClientsideEntities(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_Sprite::ParseAllClientsideEntities(const char *a1@<edi>, char *pMapData)
{
  char *v2; // esi
  IMDLCache *v3; // edi
  C_Sprite *v4; // eax
  C_Sprite *v5; // eax
  C_Sprite *v6; // esi
  const char *Entity; // eax
  const char *v8; // [esp-8h] [ebp-2818h]
  char pWorkBuffer[2048]; // [esp+4h] [ebp-280Ch] BYREF
  char v10[2048]; // [esp+804h] [ebp-200Ch] BYREF
  char keyName[2048]; // [esp+1004h] [ebp-180Ch] BYREF
  char value[2048]; // [esp+1804h] [ebp-100Ch] BYREF
  char newToken[2048]; // [esp+2004h] [ebp-80Ch] BYREF
  CEntityMapData mapData; // [esp+2804h] [ebp-Ch] BYREF

  v2 = (char *)MapEntity_ParseToken(data: pMapData, newToken);
  if ( v2 != nullptr )
  {
    v8 = a1;
    do
    {
      if ( newToken[0] == 123 )
      {
        v3 = mdlcache;
        mapData.m_pEntData = v2;
        mapData.m_nEntDataSize = -1;
        mapData.m_pCurrentKey = v2;
        mdlcache->BeginLock(this: mdlcache);
        if ( !CEntityMapData::ExtractValue(this: &mapData, keyName: "classname", value) )
          _Error(this: (ISceneTokenProcessor *)&stru_10469AA0, a2: v8);
        if ( _V_strcmp(s1: value, s2: "env_sprite_clientside") == 0
          && (v4 = (C_Sprite *)C_BaseEntity::operator new(stAllocateBlock: 0x9E8u)) != nullptr
          && (v5 = C_Sprite::C_Sprite(this: v4), v6 = v5, v5 != nullptr) )
        {
          C_BaseEntity::ParseMapData(this: v5, &mapData);
          if ( C_Sprite::InitializeClientside(this: v6) == 0 )
            v6->Release(this: &v6->IClientNetworkable);
        }
        else if ( CEntityMapData::GetFirstKey(this: &mapData, keyName, value: v10) )
        {
          while ( CEntityMapData::GetNextKey(this: &mapData, keyName, value: v10) )
            ;
        }
        v2 = (char *)CEntityMapData::CurrentBufferPosition(this: (CBaseAchievement *)&mapData);
        v3->EndLock(this: v3);
      }
      else
      {
        _Error(this: (ISceneTokenProcessor *)&stru_10469ACC, a2: newToken);
      }
      Entity = MapEntity_SkipToNextEntity(pMapData: v2, pWorkBuffer);
      v2 = (char *)MapEntity_ParseToken(data: Entity, newToken);
    }
    while ( v2 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F950
// Name: public: static void C_Sprite::RecreateAllClientside(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall C_Sprite::RecreateAllClientside(const char *a1@<edi>)
{
  char *v1; // eax

  while ( g_ClientsideSprites.m_Size > 0 )
    (*g_ClientsideSprites.m_Memory.m_pMemory)->Release(this: &(*g_ClientsideSprites.m_Memory.m_pMemory)->IClientNetworkable);
  v1 = (char *)engine->GetMapEntitiesString(this: engine);
  C_Sprite::ParseAllClientsideEntities(a1, pMapData: v1);
}
