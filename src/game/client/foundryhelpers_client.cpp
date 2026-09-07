// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/foundryhelpers_client.cpp
// Functions: 15
// ============================================================

#include "game\client\foundryhelpers_client.h"

//------------------------------------------------------------------------------
// Address: 0x100D4A40
// Name: public: virtual class ClientClass __near * C_TEFoundryHelpers::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEFoundryHelpers::GetClientClass(C_TEFoundryHelpers *this)
{
  return &__g_C_TEFoundryHelpersClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100D4AE0
// Name: void AddCoolLine(class Vector const __near &,class Vector const __near &,unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall AddCoolLine(
        IMatRenderContext *a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *v1,
        const Vector *v2,
        unsigned int iExtraFadeOffset,
        bool bNegateMovementDir)
{
  double v7; // st7
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  __int128 v11; // xmm4
  float v12; // esi
  IMesh *v13; // esi
  int v14; // eax
  void (__thiscall *v15)(_DWORD, _DWORD, _DWORD); // edx
  float z; // ecx
  __int64 v17; // xmm0_8
  float y; // xmm3_4
  int v19; // esi
  float v20; // xmm3_4
  float v21; // xmm0_4
  unsigned int v22; // ecx
  float v23; // xmm1_4
  int v24; // eax
  double v25; // st7
  float v26; // esi
  _DWORD v27[3]; // [esp+70h] [ebp-4CCh] BYREF
  CBeamSegDraw beamDraw; // [esp+7Ch] [ebp-4C0h] BYREF
  _BYTE meshBuilder_144[348]; // [esp+364h] [ebp-1D8h] OVERLAPPED BYREF
  Vector v30; // [esp+4C0h] [ebp-7Ch] BYREF
  BeamSeg_t beamSeg; // [esp+4CCh] [ebp-70h]
  float v32; // [esp+4ECh] [ebp-50h]
  float v33; // [esp+4F0h] [ebp-4Ch]
  float v34; // [esp+4F4h] [ebp-48h]
  Vector vDelta; // [esp+4F8h] [ebp-44h]
  Vector v36; // [esp+504h] [ebp-38h] OVERLAPPED
  Vector vStartPos; // [esp+510h] [ebp-2Ch]
  Vector vEndPos; // [esp+51Ch] [ebp-20h]
  int nMaxLines; // [esp+528h] [ebp-14h]
  float flEndDist; // [esp+52Ch] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+530h] [ebp-Ch]
  unsigned int iLineFadeOffset; // [esp+534h] [ebp-8h]
  unsigned int retaddr; // [esp+53Ch] [ebp+0h]

  pRenderContext.m_pObject = a1;
  iLineFadeOffset = retaddr;
  v7 = *(float *)(gpGlobals.m_Index + 12) * 5.0;
  LODWORD(vEndPos.z) = HIWORD(nMaxLines) | 0xC00;
  *(_QWORD *)&vDelta.x = (__int64)v7;
  nMaxLines = iExtraFadeOffset + (__int64)v7;
  if ( bNegateMovementDir )
    nMaxLines = -1 - (iExtraFadeOffset + (__int64)v7);
  v8 = v2->y - v1->y;
  v9 = v2->x - v1->x;
  v10 = v2->z - v1->z;
  v11 = 0;
  *(float *)&v11 = fsqrt((float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v10 * v10));
  *(_OWORD *)&meshBuilder_144[332] = v11;
  v33 = v8 * (float)(1.0 / *(float *)&v11);
  v32 = (float)(1.0 / *(float *)&v11) * v9;
  v34 = v10 * (float)(1.0 / *(float *)&v11);
  LODWORD(vEndPos.x) = 1 - (int)(float)(*(float *)&v11 * -0.33333334);
  if ( pWireframeMaterial == nullptr )
    pWireframeMaterial = materials->FindMaterial(
                           this: materials,
                           a2: "debug/debugwireframevertexcolor",
                           a3: "Other textures",
                           a4: 1,
                           a5: 0);
  if ( pBeamMaterial == nullptr )
    pBeamMaterial = materials->FindMaterial(this: materials, a2: "effects/laser1", a3: "Other textures", a4: 1, a5: 0);
  v12 = COERCE_FLOAT(((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2, a3));
  vEndPos.z = v12;
  if ( v12 != 0.0 )
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v12) + 8))(a1: COERCE_FLOAT(LODWORD(v12)));
  v13 = (IMesh *)(*(int (__thiscall **)(float, int, _DWORD, _DWORD, IMaterial *))(*(_DWORD *)LODWORD(v12) + 228))(
                   a1: COERCE_FLOAT(LODWORD(v12)),
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: pWireframeMaterial);
  CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)((char *)&beamDraw.m_vecCameraPos + 20));
  meshBuilder_144[32] = 1;
  *(_DWORD *)&meshBuilder_144[28] = 1;
  *(_DWORD *)&meshBuilder_144[24] = v13;
  v13->SetPrimitiveType(this: v13, a2: MATERIAL_LINES);
  (*(void (__thiscall **)(_DWORD, int, int, char *, _DWORD))(**(_DWORD **)&meshBuilder_144[24] + 68))(
    a1: *(_DWORD *)&meshBuilder_144[24],
    a2: 2,
    a3: 2,
    a4: (char *)&beamDraw.m_vecCameraPos + 20,
    a5: 0);
  *(_DWORD *)&meshBuilder_144[36] = *(_DWORD *)&meshBuilder_144[8];
  *(_DWORD *)&meshBuilder_144[64] = *(_DWORD *)meshBuilder_144;
  *(_DWORD *)&meshBuilder_144[52] = &v13->IIndexBuffer;
  *(_DWORD *)&meshBuilder_144[48] = *(_DWORD *)&meshBuilder_144[20];
  *(_DWORD *)&meshBuilder_144[60] = 0;
  *(_DWORD *)&meshBuilder_144[56] = 2;
  meshBuilder_144[84] = 0;
  CVertexBuilder::AttachBegin(
    this: (CVertexBuilder *)&meshBuilder_144[88],
    pMesh: v13,
    nMaxVertexCount: 2,
    desc: (const MeshDesc_t *)((char *)&beamDraw.m_vecCameraPos + 20));
  *(_DWORD *)&meshBuilder_144[68] = 0;
  CVertexBuilder::Reset(this: (CVertexBuilder *)&meshBuilder_144[88]);
  **(Vector **)&meshBuilder_144[272] = *v1;
  **(_DWORD **)&meshBuilder_144[280] = -2574525;
  CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder_144[88]);
  **(Vector **)&meshBuilder_144[272] = *v2;
  **(_DWORD **)&meshBuilder_144[280] = -2574525;
  CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder_144[88]);
  if ( meshBuilder_144[32] != 0 )
  {
    switch ( *(_DWORD *)&meshBuilder_144[28] )
    {
      case 4:
        v14 = 2 * *(_DWORD *)&meshBuilder_144[264] - 2;
        break;
      case 5:
        v14 = 2 * *(_DWORD *)&meshBuilder_144[264];
        break;
      case 6:
        v14 = 3 * *(_DWORD *)&meshBuilder_144[264] - 6;
        break;
      case 7:
        v14 = 6 * *(_DWORD *)&meshBuilder_144[264] / 4;
        break;
      case 0xA:
        v14 = 0;
        break;
      default:
        v14 = *(_DWORD *)&meshBuilder_144[264];
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: (CIndexBuilder *)&meshBuilder_144[36],
      primitiveType: *(MaterialPrimitiveType_t *)&meshBuilder_144[28],
      nIndexCount: v14);
  }
  v15 = *(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)&meshBuilder_144[24] + 80);
  flEndDist = COERCE_FLOAT((CBeamSegDraw *)((char *)&beamDraw.m_vecCameraPos + 20));
  v15(a1: *(_DWORD *)&meshBuilder_144[24], a2: *(_DWORD *)&meshBuilder_144[264], a3: *(_DWORD *)&meshBuilder_144[60]);
  *(_DWORD *)&meshBuilder_144[52] = 0;
  *(_DWORD *)&meshBuilder_144[56] = 0;
  *(_DWORD *)&meshBuilder_144[260] = 0;
  *(_DWORD *)&meshBuilder_144[252] = 0;
  *(_DWORD *)&meshBuilder_144[164] = -1;
  (*(void (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)&meshBuilder_144[24] + 48))(
    a1: *(_DWORD *)&meshBuilder_144[24],
    a2: -1,
    a3: 0);
  z = v1->z;
  v17 = *(_QWORD *)&v1->x;
  y = 0.0;
  v19 = 0;
  *(_DWORD *)&meshBuilder_144[24] = 0;
  *(_QWORD *)&v36.x = v17;
  v36.z = z;
  if ( SLODWORD(vEndPos.x) > 0 )
  {
    while ( 1 )
    {
      v20 = y + 3.0;
      if ( *(float *)&meshBuilder_144[332] <= v20 )
        v20 = *(float *)&meshBuilder_144[332];
      v21 = (float)(v34 * v20) + v1->z;
      vEndPos.y = v20;
      v22 = ((_BYTE)v19 + (_BYTE)nMaxLines) & 3;
      v23 = v1->y + (float)(v33 * v20);
      vStartPos.x = v1->x + (float)(v32 * v20);
      vStartPos.y = v23;
      vStartPos.z = v21;
      if ( v22 >= 2 )
        v24 = 4 - v22;
      else
        v24 = ((_BYTE)v19 + (_BYTE)nMaxLines) & 3;
      flEndDist = Bias(x: (float)(255 * v24 / 2) * 0.0039215689, biasAmt: 0.60000002);
      beamDraw.m_Mesh.m_nOffset = 0;
      LOBYTE(beamDraw.m_Mesh.m_nIndexSize) = 0;
      memset(&beamDraw.m_Mesh.m_IndexBuilder.m_nOffset, 0, 12);
      beamDraw.m_Mesh.m_IndexBuilder.m_nMaxIndexCount = 0;
      beamDraw.m_Mesh.m_IndexBuilder.m_nIndexCount = 0;
      beamDraw.m_Mesh.m_IndexBuilder.m_nCurrentIndex = 0;
      beamDraw.m_Mesh.m_VertexBuilder.m_pUserData = nullptr;
      beamDraw.m_Mesh.m_VertexBuilder.m_pCurrTexCoord[7] = nullptr;
      memset(&beamDraw.m_Mesh.m_VertexBuilder.m_nOffset, 0, 12);
      beamDraw.m_Mesh.m_VertexBuilder.m_pCurrTexCoord[5] = nullptr;
      beamDraw.m_vNormalLast.x = 0.0;
      beamDraw.m_Mesh.m_IndexBuilder.m_nIndexOffset = -1;
      beamDraw.m_Mesh.m_VertexBuilder.m_pCurrTexCoord[6] = (float *)-1;
      beamDraw.m_Mesh.m_VertexBuilder.m_VertexSize_Wrinkle = -1;
      v27[0] = &CBeamSegDraw::`vftable';
      CBeamSegDraw::Start(
        this: (CBeamSegDraw *)v27,
        pRenderContext: nullptr,
        nSegs: 2,
        pMaterial: pBeamMaterial,
        pMeshBuilder: nullptr,
        nMeshVertCount: 0);
      v25 = flEndDist;
      flEndDist = 216.0 * flEndDist * 0.0039215689 * 255.0 + 8388608.0;
      LOBYTE(beamSeg.m_vPos.y) = LOBYTE(flEndDist);
      flEndDist = v25 * 183.0 * 0.0039215689 * 255.0 + 8388608.0;
      BYTE1(beamSeg.m_vPos.y) = LOBYTE(flEndDist);
      flEndDist = 255.0 * (0.0039215689 * (v25 * 67.0)) + 8388608.0;
      BYTE2(beamSeg.m_vPos.y) = LOBYTE(flEndDist);
      *((_DWORD *)&beamSeg.m_flWidth + 1) = 1258291455;
      beamSeg.m_vPos.z = 0.0;
      HIBYTE(beamSeg.m_vPos.y) = -1;
      beamSeg.m_vPos.w = 6.0;
      CBeamSegDraw::NextSeg(this: (CBeamSegDraw *)v27, pSeg: (BeamSeg_t *)&v30);
      v30 = vStartPos;
      CBeamSegDraw::NextSeg(this: (CBeamSegDraw *)v27, pSeg: (BeamSeg_t *)&v30);
      CBeamSegDraw::End(this: (CBeamSegDraw *)v27);
      vDelta.y = vEndPos.y;
      v36 = vStartPos;
      if ( beamDraw.m_Mesh.m_VertexBuilder.m_pUserData != nullptr
        && (*(unsigned __int8 (__thiscall **)(float *))(*(_DWORD *)beamDraw.m_Mesh.m_VertexBuilder.m_pUserData + 8))(a1: beamDraw.m_Mesh.m_VertexBuilder.m_pUserData) != 0 )
      {
        (*(void (__thiscall **)(float *))(*(_DWORD *)beamDraw.m_Mesh.m_VertexBuilder.m_pUserData + 16))(a1: beamDraw.m_Mesh.m_VertexBuilder.m_pUserData);
      }
      if ( beamDraw.m_Mesh.m_IndexBuilder.m_nOffset != 0
        && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)beamDraw.m_Mesh.m_IndexBuilder.m_nOffset + 8))(a1: beamDraw.m_Mesh.m_IndexBuilder.m_nOffset) != 0 )
      {
        (*(void (__thiscall **)(unsigned int))(*(_DWORD *)beamDraw.m_Mesh.m_IndexBuilder.m_nOffset + 16))(a1: beamDraw.m_Mesh.m_IndexBuilder.m_nOffset);
      }
      if ( ++v19 >= SLODWORD(vEndPos.x) )
        break;
      y = vDelta.y;
    }
  }
  if ( *(_DWORD *)&meshBuilder_144[252] != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[252] + 8))(a1: *(_DWORD *)&meshBuilder_144[252]) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[252] + 16))(a1: *(_DWORD *)&meshBuilder_144[252]);
  }
  if ( *(_DWORD *)&meshBuilder_144[52] != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[52] + 8))(a1: *(_DWORD *)&meshBuilder_144[52]) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[52] + 16))(a1: *(_DWORD *)&meshBuilder_144[52]);
  }
  v26 = vEndPos.z;
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(vEndPos.z) + 12))(a1: LODWORD(vEndPos.z));
  (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v26) + 4))(a1: COERCE_FLOAT(LODWORD(v26)));
}

//------------------------------------------------------------------------------
// Address: 0x100D51A0
// Name: void FoundryHelpers_DrawEntityHighlightEffect(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FoundryHelpers_DrawEntityHighlightEffect(C_BaseEntity *pEnt)
{
  C_BaseEntity::NetworkVar_m_Collision *p_m_Collision; // edi
  const Vector *v2; // esi
  int v3; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float *p_z; // esi
  int i; // ebx
  unsigned __int8 m_Value; // al
  float *v23; // eax
  const matrix3x4_t *v24; // eax
  float v25; // xmm2_4
  float v26; // xmm1_4
  float x; // xmm0_4
  float *v28; // eax
  float v29; // xmm1_4
  Vector *v30; // edi
  int v31; // esi
  unsigned int v32; // esi
  bool v33; // zf
  Vector vPoints[8]; // [esp+Ch] [ebp-74h] BYREF
  Vector vTmp; // [esp+6Ch] [ebp-14h] BYREF
  int v36; // [esp+78h] [ebp-8h]
  unsigned int iExtraFadeOffset; // [esp+7Ch] [ebp-4h]
  IMatRenderContext savedregs; // [esp+80h] [ebp+0h] BYREF
  int pEnta; // [esp+88h] [ebp+8h]

  p_m_Collision = &pEnt->m_Collision;
  v2 = pEnt->m_Collision.OBBMins(this: &pEnt->m_Collision);
  v3 = (int)p_m_Collision->OBBMaxs(this: p_m_Collision);
  y = v2->y;
  z = v2->z;
  vPoints[0].x = v2->x;
  vPoints[0].y = y;
  vPoints[0].z = z;
  v6 = v2->y;
  v7 = v2->z;
  vPoints[1].x = *(float *)v3;
  vPoints[1].y = v6;
  vPoints[1].z = v7;
  v8 = v2->z;
  v9 = *(float *)(v3 + 4);
  vPoints[2].x = *(float *)v3;
  vPoints[2].y = v9;
  vPoints[2].z = v8;
  v10 = v2->z;
  v11 = *(float *)(v3 + 4);
  vPoints[3].x = v2->x;
  vPoints[3].y = v11;
  vPoints[3].z = v10;
  v12 = v2->y;
  v13 = *(float *)(v3 + 8);
  vPoints[4].x = v2->x;
  vPoints[4].y = v12;
  vPoints[4].z = v13;
  v14 = v2->y;
  v15 = *(float *)(v3 + 8);
  vPoints[5].x = *(float *)v3;
  vPoints[5].y = v14;
  vPoints[5].z = v15;
  v16 = *(float *)(v3 + 4);
  v17 = *(float *)(v3 + 8);
  vPoints[6].x = *(float *)v3;
  vPoints[6].y = v16;
  vPoints[6].z = v17;
  v18 = *(float *)(v3 + 4);
  v19 = *(float *)(v3 + 8);
  vPoints[7].x = v2->x;
  vPoints[7].y = v18;
  vPoints[7].z = v19;
  p_z = &vPoints[0].z;
  for ( i = 8; i != 0; --i )
  {
    if ( (pEnt->m_Collision.m_usSolidFlags.m_Value & 0x40) != 0
      || (m_Value = pEnt->m_Collision.m_nSolidType.m_Value) == 2
      || m_Value == 0
      || (v23 = (float *)p_m_Collision->GetCollisionAngles(this: p_m_Collision), vec3_angle.x == *v23)
      && vec3_angle.y == v23[1]
      && vec3_angle.z == v23[2] )
    {
      v28 = (float *)p_m_Collision->GetCollisionOrigin(this: p_m_Collision);
      x = *v28 + *(p_z - 2);
      v29 = *(p_z - 1);
      vTmp.x = x;
      v26 = v29 + v28[1];
      vTmp.y = v26;
      v25 = v28[2] + *p_z;
      vTmp.z = v25;
    }
    else
    {
      v24 = p_m_Collision->CollisionToWorldTransform(this: p_m_Collision);
      VectorTransform(in1: p_z - 2, in2: v24, out: &vTmp.x);
      v25 = vTmp.z;
      v26 = vTmp.y;
      x = vTmp.x;
    }
    *(p_z - 2) = x;
    *(p_z - 1) = v26;
    *p_z = v25;
    p_z += 3;
  }
  pEnta = 1;
  v30 = vPoints;
  iExtraFadeOffset = 4;
  v36 = 4;
  do
  {
    v31 = pEnta % 4;
    AddCoolLine(
      a1: &savedregs,
      a2: (int)v30,
      a3: v31 * 12,
      v1: v30,
      v2: &vPoints[v31],
      iExtraFadeOffset: 0,
      bNegateMovementDir: false);
    AddCoolLine(
      a1: &savedregs,
      a2: (int)v30,
      a3: v31 * 12,
      v1: v30 + 4,
      v2: &vPoints[v31 + 4],
      iExtraFadeOffset: 4u,
      bNegateMovementDir: true);
    v32 = iExtraFadeOffset;
    AddCoolLine(
      a1: &savedregs,
      a2: (int)v30,
      a3: iExtraFadeOffset,
      v1: v30,
      v2: v30 + 4,
      iExtraFadeOffset,
      bNegateMovementDir: true);
    ++pEnta;
    ++v30;
    v33 = v36-- == 1;
    iExtraFadeOffset = v32 + 2;
  }
  while ( !v33 );
}

//------------------------------------------------------------------------------
// Address: 0x100D5410
// Name: void FoundryHelpers_DrawAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FoundryHelpers_DrawAll()
{
  int i; // esi
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax

  if ( cl_foundry_ShowEntityHighlights.m_pParent != nullptr
    && cl_foundry_ShowEntityHighlights.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = 0; i < g_EntityHighlightEffects.m_Size; ++i )
    {
      m_Index = g_EntityHighlightEffects.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
          FoundryHelpers_DrawEntityHighlightEffect(pEnt: m_pEntity);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5480
// Name: void FoundryHelpers_ClearEntityHighlightEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FoundryHelpers_ClearEntityHighlightEffects()
{
  CHandle<C_BaseEntity> *m_pMemory; // eax

  g_EntityHighlightEffects.m_Size = 0;
  if ( g_EntityHighlightEffects.m_Memory.m_nGrowSize < 0 )
  {
    g_EntityHighlightEffects.m_pElements = g_EntityHighlightEffects.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = g_EntityHighlightEffects.m_Memory.m_pMemory;
    if ( g_EntityHighlightEffects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)g_EntityHighlightEffects.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_EntityHighlightEffects.m_Memory.m_pMemory = nullptr;
    }
    g_EntityHighlightEffects.m_Memory.m_nAllocationCount = 0;
    g_EntityHighlightEffects.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D54D0
// Name: void FoundryHelpers_AddEntityHighlightEffect(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FoundryHelpers_AddEntityHighlightEffect(int iEntity)
{
  C_BaseEntity *BaseEntity; // eax
  unsigned int m_Index; // edi
  int m_Size; // eax
  int v4; // esi
  CHandle<C_BaseEntity> *m_pMemory; // ecx
  int v6; // eax
  CHandle<C_BaseEntity> *v7; // eax

  BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: iEntity);
  if ( BaseEntity != nullptr )
  {
    m_Index = BaseEntity->GetRefEHandle(this: BaseEntity)->m_Index;
    if ( m_Index != -1 )
    {
      m_Size = g_EntityHighlightEffects.m_Size;
      v4 = g_EntityHighlightEffects.m_Size;
      if ( g_EntityHighlightEffects.m_Size + 1 > g_EntityHighlightEffects.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&g_EntityHighlightEffects,
          num: g_EntityHighlightEffects.m_Size - g_EntityHighlightEffects.m_Memory.m_nAllocationCount + 1);
        m_Size = g_EntityHighlightEffects.m_Size;
      }
      m_pMemory = g_EntityHighlightEffects.m_Memory.m_pMemory;
      g_EntityHighlightEffects.m_Size = m_Size + 1;
      v6 = m_Size - v4;
      g_EntityHighlightEffects.m_pElements = g_EntityHighlightEffects.m_Memory.m_pMemory;
      if ( v6 > 0 )
      {
        _V_memmove(
          dest: (void *)&g_EntityHighlightEffects.m_Memory.m_pMemory[v4 + 1],
          src: &g_EntityHighlightEffects.m_Memory.m_pMemory[v4],
          count: 4 * v6);
        m_pMemory = g_EntityHighlightEffects.m_Memory.m_pMemory;
      }
      v7 = &m_pMemory[v4];
      if ( v7 != nullptr )
        v7->m_Index = m_Index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5560
// Name: public: virtual void C_TEFoundryHelpers::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEFoundryHelpers::PostDataUpdate(C_TEFoundryHelpers *this, DataUpdateType_t updateType)
{
  if ( this->m_pNextDynamic == (C_BaseTempEntity *)-1 )
    FoundryHelpers_ClearEntityHighlightEffects();
  else
    FoundryHelpers_AddEntityHighlightEffect(iEntity: (int)this->m_pNextDynamic);
}

//------------------------------------------------------------------------------
// Address: 0x10415AE0
// Name: DT_TEFoundryHelpers::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFoundryHelpers::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEFoundryHelpers::g_RecvTable);
  return atexit(func: DT_TEFoundryHelpers::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415B00
// Name: DT_TEFoundryHelpers::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFoundryHelpers::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEFoundryHelpers::ignored>();
  DT_TEFoundryHelpers::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431720
// Name: DT_TEFoundryHelpers::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEFoundryHelpers::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEFoundryHelpers::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100D4A50
// Name: _C_TEFoundryHelpers_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEFoundryHelpers_CreateObject()
{
  return &_g_C_TEFoundryHelpers.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10415B10
// Name: _dynamic_initializer_for__C_FuncLadder::s_Ladders__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__C_FuncLadder::s_Ladders__()
{
  return atexit(func: dynamic_atexit_destructor_for__C_FuncLadder::s_Ladders__);
}

//------------------------------------------------------------------------------
// Address: 0x10415B20
// Name: _dynamic_initializer_for____g_C_FuncLadderClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncLadderClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncLadderClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncLadderClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431730
// Name: _dynamic_atexit_destructor_for____g_C_TEFoundryHelpers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEFoundryHelpers__()
{
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEFoundryHelpers);
}

//------------------------------------------------------------------------------
// Address: 0x10431740
// Name: _dynamic_atexit_destructor_for__g_EntityHighlightEffects__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntityHighlightEffects__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_EntityHighlightEffects);
}
