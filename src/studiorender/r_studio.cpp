// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/r_studio.cpp
// Functions: 4
// ============================================================

#include "studiorender\r_studio.h"

//------------------------------------------------------------------------------
// Address: 0x10001950
// Name: private: class IMaterial __near * CStudioRender::R_StudioSetupSkinAndLighting(class IMatRenderContext __near *,int,class IMaterial __near * __near *,int,void __near *,struct ColorMeshInfo_t __near *,enum StudioModelLighting_t __near &)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CStudioRender::R_StudioSetupSkinAndLighting(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        int index,
        IMaterial **ppMaterials,
        int materialFlags,
        void *pClientRenderable,
        ColorMeshInfo_t *pColorMeshes,
        StudioModelLighting_t *lighting)
{
  StudioRenderContext_t *m_pRC; // eax
  bool v10; // zf
  IMaterial *v11; // ecx
  IMaterialVar *(__thiscall *FindVarFast)(IMaterial *, const char *, unsigned int *); // eax
  int v13; // eax
  int (__thiscall ***v14)(_DWORD); // esi
  IMaterial ***v15; // edi
  int (__thiscall *v16)(_DWORD); // eax
  int v17; // eax
  IMaterial *m_pForcedMaterial; // ecx
  OverrideType_t m_nForcedMaterialType; // edx
  int v21; // eax
  IMaterial *v22; // esi
  int v23; // edi
  char v24; // al
  IMaterial **v25; // esi
  int v26; // edi
  IMaterial *v27; // esi
  char v28; // cl
  StudioModelLighting_t v29; // eax
  StudioRenderContext_t *v30; // eax
  IMaterial *pMaterial; // [esp+20h] [ebp-8h] BYREF
  bool bCheckForConVarDrawTranslucentSubModels; // [esp+26h] [ebp-2h]
  bool translucent; // [esp+27h] [ebp-1h]

  m_pRC = this->m_pRC;
  pMaterial = nullptr;
  v10 = *((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) >= 0;
  bCheckForConVarDrawTranslucentSubModels = false;
  if ( v10 || m_pRC->m_pForcedMaterial != nullptr )
  {
    if ( (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 37) & 0x10) != 0 )
    {
      pMaterial = this->m_pMaterialModelEnvCubemap;
      translucent = false;
      goto LABEL_30;
    }
    m_pForcedMaterial = m_pRC->m_pForcedMaterial;
    if ( m_pForcedMaterial != nullptr || m_pRC->m_nForcedMaterialType == OVERRIDE_DEPTH_WRITE )
    {
      pMaterial = m_pRC->m_pForcedMaterial;
      m_nForcedMaterialType = m_pRC->m_nForcedMaterialType;
      materialFlags = 0;
      if ( m_nForcedMaterialType == OVERRIDE_BUILD_SHADOWS )
      {
        v21 = (int)m_pForcedMaterial->FindVarFast(
                     this: m_pForcedMaterial,
                     a2: "$translucent_material",
                     a3: &translucentCache);
        v22 = ppMaterials[index];
        v23 = v21;
        if ( v22 != nullptr
          && ((pRenderContext->Bind(this: pRenderContext, a2: v22, a3: pClientRenderable),
               ((unsigned __int8 (__thiscall *)(IMaterial *, int))v22->IsTranslucentUnderModulation)(
                 a1: v22,
                 a2: 1065353216) != 0)
           || v22->IsAlphaTested(this: v22)) )
        {
          (*(void (__thiscall **)(int, IMaterial *))(*(_DWORD *)v23 + 68))(a1: v23, a2: v22);
        }
        else
        {
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v23 + 68))(a1: v23, a2: 0);
        }
        v24 = ((int (__stdcall *)(_DWORD))pMaterial->IsTranslucentUnderModulation)(a1: LODWORD(this->m_pRC->m_AlphaMod));
        goto LABEL_28;
      }
      if ( m_nForcedMaterialType == OVERRIDE_DEPTH_WRITE )
      {
        v25 = ppMaterials;
        v26 = index;
        if ( ((unsigned __int8 (__stdcall *)(int))ppMaterials[index]->IsTranslucentUnderModulation)(a1: 1065353216) != 0 )
          return nullptr;
        HIBYTE(ppMaterials) = 0;
        HIBYTE(index) = 0;
        CStudioRender::GetDepthWriteMaterial(
          this,
          ppDepthMaterial: &pMaterial,
          pIsAlphaTested: (bool *)&ppMaterials + 3,
          pUsesTreeSway: (bool *)&index + 3,
          pSrcMaterial: v25[v26]);
        if ( HIBYTE(ppMaterials) != 0 )
          CStudioRender::SetupAlphaTestedDepthWrite(this, pDepthMaterial: pMaterial, pSrcMaterial: v25[v26]);
        if ( HIBYTE(index) != 0 )
          CStudioRender::SetupTreeSwayDepthWrite(this, pDepthMaterial: pMaterial, pSrcMaterial: v25[v26]);
        translucent = false;
        goto LABEL_29;
      }
    }
    else
    {
      m_pForcedMaterial = ppMaterials[index];
      pMaterial = m_pForcedMaterial;
      if ( m_pForcedMaterial == nullptr )
        return nullptr;
    }
    v24 = ((int (__stdcall *)(_DWORD))m_pForcedMaterial->IsTranslucentUnderModulation)(a1: LODWORD(m_pRC->m_AlphaMod));
LABEL_28:
    translucent = v24;
LABEL_29:
    bCheckForConVarDrawTranslucentSubModels = true;
    goto LABEL_30;
  }
  pMaterial = this->m_pMaterialWireframe[(*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 37) & 4) != 0][0];
  v11 = ppMaterials[index];
  FindVarFast = v11->FindVarFast;
  translucent = false;
  v13 = (int)FindVarFast(this: v11, a2: "$displacementmap", a3: &originalDisplacementMap);
  v14 = (int (__thiscall ***)(_DWORD))v13;
  if ( v13 != 0 && (*(_BYTE *)(v13 + 28) & 0xF) == 3 )
  {
    pMaterial = this->m_pMaterialWireframe[(*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 37) & 4) != 0][1];
    v15 = (IMaterial ***)pMaterial->FindVarFast(this: pMaterial, a2: "$displacementmap", a3: &newDisplacementMap);
    if ( v15 != nullptr )
    {
      v16 = **v14;
      ppMaterials = *v15;
      v17 = v16(a1: v14);
      ((void (__thiscall *)(IMaterial ***, int))ppMaterials[15])(a1: v15, a2: v17);
    }
  }
LABEL_30:
  v27 = pMaterial;
  if ( materialFlags != 0 && this->m_pStudioHdr->nummouths >= 1 )
  {
    HIBYTE(ppMaterials) = 1;
LABEL_33:
    v28 = 1;
    goto LABEL_34;
  }
  HIBYTE(ppMaterials) = 0;
  if ( pMaterial != nullptr
    && ((unsigned __int8 (*)(void))pMaterial->IsVertexLit)() != 0
    && v27->NeedsSoftwareLighting(this: v27) )
  {
    goto LABEL_33;
  }
  v28 = 0;
LABEL_34:
  if ( HIBYTE(ppMaterials) != 0 )
    v29 = LIGHTING_MOUTH;
  else
    v29 = v28 != 0;
  *lighting = v29;
  if ( v29 == LIGHTING_MOUTH )
  {
    v30 = this->m_pRC;
    if ( (*((_BYTE *)&v30->m_Config.StudioRenderConfig_t + 36) & 0x10) != 0 )
    {
      if ( (*((_BYTE *)&v30->m_Config + 56) & 1) != 0 )
        CStudioRender::R_MouthSetupVertexShader(this, pMaterial);
      goto LABEL_45;
    }
    return nullptr;
  }
LABEL_45:
  pRenderContext->Bind(this: pRenderContext, a2: pMaterial, a3: pClientRenderable);
  if ( !bCheckForConVarDrawTranslucentSubModels
    || ((*((_BYTE *)this + 3685872) & 2) == 0 || translucent) && ((*((_BYTE *)this + 3685872) & 2) != 0 || !translucent) )
  {
    return pMaterial;
  }
  *((_BYTE *)this + 3685872) |= 1u;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001C80
// Name: int R_StudioSetupModel(int,int,struct mstudiomodel_t __near * __near *,struct studiohdr_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_StudioSetupModel(
        int bodypart,
        int entity_body,
        mstudiomodel_t **ppSubModel,
        const studiohdr_t *pStudioHdr)
{
  int v4; // eax
  _DWORD *v5; // ecx
  int result; // eax

  v4 = bodypart;
  if ( bodypart > pStudioHdr->numbodyparts )
  {
    _ConDMsg(a1: "R_StudioSetupModel: no such bodypart %d\n", bodypart);
    v4 = 0;
  }
  v5 = (int *)((char *)&pStudioHdr->id + 16 * v4 + pStudioHdr->bodypartindex);
  result = entity_body / v5[2] % v5[1];
  *ppSubModel = (mstudiomodel_t *)((char *)&v5[37 * result] + v5[3]);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001CD0
// Name: void ComputePoseToWorld(struct matrix3x4_t __near *,struct studiohdr_t __near *,int,class Vector const __near &,struct matrix3x4_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputePoseToWorld(
        matrix3x4_t *pPoseToWorld,
        studiohdr_t *pStudioHdr,
        int boneMask,
        const Vector *vecViewOrigin,
        const matrix3x4_t *pBoneToWorld)
{
  int studiohdr2index; // eax
  int v6; // ebx
  int v7; // ecx
  char *v8; // eax
  const matrix3x4_t *v9; // edi
  int v10; // ecx
  const matrix3x4_t *v11; // eax
  int v12; // ecx
  mstudiolinearbone_t *v13; // eax
  const matrix3x4_t *v14; // edi
  int i; // [esp+4h] [ebp-8h]
  int ia; // [esp+4h] [ebp-8h]
  mstudiolinearbone_t *pLinearBones; // [esp+8h] [ebp-4h]

  if ( (pStudioHdr->flags & 0x10) != 0 )
  {
    MatrixCopy(in: pBoneToWorld, out: pPoseToWorld);
  }
  else
  {
    studiohdr2index = pStudioHdr->studiohdr2index;
    v6 = 0;
    if ( studiohdr2index != 0
      && (v7 = *(_DWORD *)&pStudioHdr->name[studiohdr2index + 4], v8 = (char *)pStudioHdr + studiohdr2index, v7 != 0)
      && &v8[v7] != nullptr )
    {
      v12 = *((_DWORD *)v8 + 4);
      if ( v12 != 0 )
      {
        v13 = (mstudiolinearbone_t *)&v8[v12];
        pLinearBones = v13;
      }
      else
      {
        pLinearBones = nullptr;
        v13 = nullptr;
      }
      if ( pStudioHdr->numbones > 0 )
      {
        v14 = pBoneToWorld;
        ia = 0;
        do
        {
          if ( (boneMask & *(int *)((_BYTE *)&v13->numbones + 4 * v6 + v13->flagsindex)) != 0 )
          {
            ConcatTransforms(
              in1: v14,
              in2: (const matrix3x4_t *)((char *)v13 + ia + v13->posetoboneindex),
              out: (const matrix3x4_t *)((char *)v14 + (char *)pPoseToWorld - (char *)pBoneToWorld));
            v13 = pLinearBones;
          }
          ia += 48;
          ++v6;
          ++v14;
        }
        while ( v6 < pStudioHdr->numbones );
      }
    }
    else
    {
      i = 0;
      if ( pStudioHdr->numbones > 0 )
      {
        v9 = pBoneToWorld;
        v10 = (char *)pPoseToWorld - (char *)pBoneToWorld;
        do
        {
          v11 = (const matrix3x4_t *)((char *)pStudioHdr + v6 + pStudioHdr->boneindex);
          if ( (boneMask & LODWORD(v11[3].m_flMatVal[1][0])) != 0 )
          {
            ConcatTransforms(in1: v9, in2: v11 + 2, out: (const matrix3x4_t *)((char *)v9 + v10));
            v10 = (char *)pPoseToWorld - (char *)pBoneToWorld;
          }
          v6 += 216;
          ++v9;
          ++i;
        }
        while ( i < pStudioHdr->numbones );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001DF0
// Name: enum MaterialPrimitiveType_t GetPrimitiveTypeForStripHeaderFlags(unsigned char)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetPrimitiveTypeForStripHeaderFlags(unsigned __int8 Flags)
{
  if ( (Flags & 4) != 0 )
    return 8;
  else
    return (Flags & 2) != 0 ? 9 : 2;
}
