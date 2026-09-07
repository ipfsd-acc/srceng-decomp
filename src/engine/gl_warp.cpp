// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_warp.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100D9B10
// Name: void R_UnloadSkys(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_UnloadSkys()
{
  IMaterial **v0; // esi

  v0 = skyboxMaterials;
  do
  {
    if ( *v0 != nullptr )
    {
      (*v0)->DecrementReferenceCount(this: *v0);
      *v0 = nullptr;
    }
    ++v0;
  }
  while ( (int)v0 < (int)currentloadedsky );
  currentloadedsky[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D9B40
// Name: bool R_LoadNamedSkys(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl R_LoadNamedSkys(const char *skyname)
{
  int i; // esi
  IMaterial *v2; // eax
  int j; // esi
  IMaterial *v4; // ecx
  IMaterial *v5; // ecx
  char name[260]; // [esp+8h] [ebp-134h] BYREF
  IMaterial *skies[6]; // [esp+10Ch] [ebp-30h]
  char *skyboxsuffix[6]; // [esp+124h] [ebp-18h]

  skyboxsuffix[0] = "rt";
  skyboxsuffix[1] = "bk";
  skyboxsuffix[2] = "lf";
  skyboxsuffix[3] = "ft";
  skyboxsuffix[4] = "up";
  skyboxsuffix[5] = "dn";
  for ( i = 0; i < 6; ++i )
  {
    V_snprintf(pDest: name, maxLen: 260, pFormat: "skybox/%s%s", skyname, skyboxsuffix[i]);
    v2 = materials->FindMaterial(this: materials, a2: name, a3: "SkyBox textures", a4: 1, a5: 0);
    skies[i] = v2;
    if ( v2 == nullptr || v2->IsErrorMaterial(this: v2) )
      return 0;
  }
  for ( j = 0; j < 6; ++j )
  {
    v4 = skyboxMaterials[j];
    if ( v4 != nullptr )
    {
      v4->DecrementReferenceCount(this: v4);
      skyboxMaterials[j] = nullptr;
    }
    v5 = skies[j];
    skyboxMaterials[j] = v5;
    v5->IncrementReferenceCount(this: v5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D9C30
// Name: void R_LoadSkys(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LoadSkys()
{
  char v0; // bl

  v0 = 1;
  if ( (_S1_9 & 1) == 0 )
  {
    _S1_9 |= 1u;
    ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname");
  }
  if ( ConVarRef::IsValid(this: &skyname) )
  {
    if ( _V_stricmp(s1: skyname.m_pConVarState->m_Value.m_pszString, s2: currentloadedsky) != 0 )
    {
      if ( R_LoadNamedSkys(skyname: skyname.m_pConVarState->m_Value.m_pszString) == 0 )
      {
        v0 = 0;
        if ( _V_stricmp(s1: skyname.m_pConVarState->m_Value.m_pszString, s2: "sky_urb01") != 0
          && R_LoadNamedSkys(skyname: "sky_urb01") != 0 )
        {
          _ConDMsg(
            a1: "Unable to load sky %s, but successfully loaded %s\n",
            skyname.m_pConVarState->m_Value.m_pszString,
            "sky_urb01");
          skyname.m_pConVar->SetValue_4(this: skyname.m_pConVar, a2: "sky_urb01");
          v0 = 1;
        }
      }
      V_strncpy(pDest: currentloadedsky, pSrc: skyname.m_pConVarState->m_Value.m_pszString, maxLen: 128);
      if ( v0 == 0 )
        _ConDMsg(a1: "Unable to load sky %s\n", skyname.m_pConVarState->m_Value.m_pszString);
    }
  }
  else
  {
    _ConDMsg(a1: "Unable to find skyname ConVar!!!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9D40
// Name: void MakeSkyVec(float,float,int,float,class Vector __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeSkyVec(float s, float t, int axis, float zFar, Vector *position, Vector *texCoord)
{
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  int v9; // ecx
  float v10; // xmm3_4
  int v11; // ecx
  float v12; // xmm6_4
  float v13; // xmm3_4
  int v14; // eax
  float v15; // xmm5_4
  float v16; // xmm4_4
  float z; // xmm3_4
  int v18; // [esp+0h] [ebp-10h]
  float v19; // [esp+4h] [ebp-Ch]
  Vector b; // [esp+8h] [ebp-8h]

  v6 = s;
  v7 = flScale * zFar;
  if ( s >= -1.0 )
  {
    if ( s > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = -1.0;
  }
  v8 = t;
  if ( t >= -1.0 )
  {
    if ( t > 1.0 )
      v8 = 1.0;
  }
  else
  {
    v8 = -1.0;
  }
  v9 = st_to_vec[axis][0];
  v19 = v7 * v6;
  b.x = v7 * v8;
  b.y = flScale * zFar;
  if ( v9 >= 0 )
    v10 = *((float *)&v18 + v9);
  else
    v10 = -*(&v19 - v9 - 1);
  v11 = dword_104162AC[3 * axis];
  v12 = g_CurrentViewOrigin.x + v10;
  if ( v11 >= 0 )
    v13 = *((float *)&v18 + v11);
  else
    v13 = -*(&v19 - v11 - 1);
  v14 = dword_104162B0[3 * axis];
  v15 = g_CurrentViewOrigin.y + v13;
  if ( v14 >= 0 )
    v16 = *((float *)&v18 + v14);
  else
    v16 = -*(&v19 - v14 - 1);
  z = g_CurrentViewOrigin.z;
  position->x = v12;
  position->y = v15;
  position->z = z + v16;
  texCoord->x = (float)(v6 + 1.0) * 0.5;
  texCoord->y = 1.0 - (float)((float)(v8 + 1.0) * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x100D9EA0
// Name: void R_DrawSkyBox(float,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall R_DrawSkyBox(CMeshBuilder *a1@<ebx>, int m_nIndexCount@<edi>, float zFar, int nDrawFlags)
{
  int v4; // esi
  float z; // ebx
  int v6; // edi
  IMaterial *v7; // eax
  IMesh *v8; // ebx
  float *p_y; // edi
  float *m_pCurrPosition; // eax
  float *v11; // eax
  int m_nVertexCount; // eax
  CMeshBuilder v15; // [esp+1Ch] [ebp-244h] BYREF
  Vector v16; // [esp+204h] [ebp-5Ch] BYREF
  Vector v17; // [esp+210h] [ebp-50h] BYREF
  Vector v18; // [esp+21Ch] [ebp-44h] BYREF
  int v19; // [esp+228h] [ebp-38h] BYREF
  Vector positionArray[4]; // [esp+22Ch] [ebp-34h] BYREF
  int texCoordArray; // [esp+25Ch] [ebp-4h] OVERLAPPED

  v4 = 0;
  if ( r_drawskybox.m_pParent != nullptr
    && r_drawskybox.m_pParent->m_Value.m_nValue != 0
    && mat_loadtextures.m_pParent != nullptr
    && mat_loadtextures.m_pParent->m_Value.m_nValue != 0 )
  {
    R_LoadSkys();
    z = COERCE_FLOAT((int)materials->GetRenderContext(this: materials));
    positionArray[3].z = z;
    if ( z != 0.0 )
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(z) + 8))(a1: COERCE_FLOAT(LODWORD(z)));
    v6 = 0;
    texCoordArray = 0;
    do
    {
      if ( (nDrawFlags & 1) != 0 )
      {
        v7 = skyboxMaterials[skytexorder[v6]];
        if ( v7 != nullptr )
        {
          (*(void (__thiscall **)(float, IMaterial *, _DWORD, int, CMeshBuilder *))(*(_DWORD *)LODWORD(z) + 36))(
            a1: COERCE_FLOAT(LODWORD(z)),
            a2: v7,
            a3: 0,
            a4: m_nIndexCount,
            a5: a1);
          MakeSkyVec(s: -1.0, t: -1.0, axis: v6, zFar, position: &v16, texCoord: (Vector *)&positionArray[0].z);
          MakeSkyVec(s: -1.0, t: 1.0, axis: v6, zFar, position: &v17, texCoord: (Vector *)&positionArray[1].y);
          MakeSkyVec(s: 1.0, t: 1.0, axis: v6, zFar, position: &v18, texCoord: &positionArray[2]);
          MakeSkyVec(s: 1.0, t: -1.0, axis: v6, zFar, position: (Vector *)&v19, texCoord: (Vector *)&positionArray[2].z);
          v8 = (IMesh *)(*(int (__thiscall **)(float, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(z) + 228))(
                          a1: COERCE_FLOAT(LODWORD(z)),
                          a2: 1,
                          a3: 0,
                          a4: 0,
                          a5: 0);
          CMeshBuilder::CMeshBuilder(this: &v15);
          v15.m_pMesh = v8;
          v15.m_bGenerateIndices = true;
          v15.m_Type = MATERIAL_QUADS;
          v8->SetPrimitiveType(this: v8, a2: MATERIAL_TRIANGLES);
          v15.m_pMesh->LockMesh(this: v15.m_pMesh, a2: 4, a3: 6, a4: &v15, a5: nullptr);
          v15.m_IndexBuilder.m_nIndexOffset = v15.m_nFirstVertex;
          v15.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
          v15.m_IndexBuilder.m_nIndexSize = v15.m_nIndexSize;
          v15.m_IndexBuilder.m_nIndexCount = 0;
          v15.m_IndexBuilder.m_nMaxIndexCount = 6;
          v15.m_IndexBuilder.m_bModify = false;
          v15.m_IndexBuilder.m_pIndices = v15.m_pIndices;
          v15.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::AttachBegin(this: &v15.m_VertexBuilder, pMesh: v8, nMaxVertexCount: 4, desc: &v15);
          v15.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::Reset(this: &v15.m_VertexBuilder);
          p_y = &v16.y;
          do
          {
            m_pCurrPosition = v15.m_VertexBuilder.m_pCurrPosition;
            *v15.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
            m_pCurrPosition[1] = *p_y;
            m_pCurrPosition[2] = p_y[1];
            v11 = v15.m_VertexBuilder.m_pCurrTexCoord[0];
            *v15.m_VertexBuilder.m_pCurrTexCoord[0] = *(&positionArray[0].z + 2 * v4);
            v11[1] = *(&positionArray[1].x + 2 * v4);
            CVertexBuilder::AdvanceVertex(this: &v15.m_VertexBuilder);
            ++v4;
            p_y += 3;
          }
          while ( v4 < 4 );
          if ( v15.m_bGenerateIndices )
          {
            switch ( v15.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * v15.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * v15.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * v15.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * v15.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = v15.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &v15.m_IndexBuilder,
              primitiveType: v15.m_Type,
              nIndexCount: m_nVertexCount);
          }
          a1 = &v15;
          m_nIndexCount = v15.m_IndexBuilder.m_nIndexCount;
          ((void (__thiscall *)(IMesh *, int))v15.m_pMesh->UnlockMesh)(
            a1: v15.m_pMesh,
            a2: v15.m_VertexBuilder.m_nVertexCount);
          v15.m_IndexBuilder.m_pIndexBuffer = nullptr;
          v15.m_IndexBuilder.m_nMaxIndexCount = 0;
          v15.m_VertexBuilder.m_nMaxVertexCount = 0;
          v15.m_VertexBuilder.m_pVertexBuffer = nullptr;
          v15.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          v15.m_pMesh = nullptr;
          v8->Draw_2(this: v8, a2: -1, a3: 0);
          if ( v15.m_VertexBuilder.m_pVertexBuffer != nullptr
            && v15.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v15.m_VertexBuilder.m_pVertexBuffer) )
          {
            v15.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v15.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( v15.m_IndexBuilder.m_pIndexBuffer != nullptr
            && v15.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v15.m_IndexBuilder.m_pIndexBuffer) )
          {
            v15.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v15.m_IndexBuilder.m_pIndexBuffer);
          }
          z = positionArray[3].z;
          v6 = texCoordArray;
          v4 = 0;
        }
      }
      nDrawFlags >>= 1;
      texCoordArray = ++v6;
    }
    while ( v6 < 6 );
    if ( z != 0.0 )
    {
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(z) + 12))(a1: COERCE_FLOAT(LODWORD(z)));
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(z) + 4))(a1: COERCE_FLOAT(LODWORD(z)));
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100D9700
// Name: void R_UnloadSkys(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_UnloadSkys()
{
  IMaterial **v0; // esi

  v0 = skyboxMaterials;
  do
  {
    if ( *v0 != nullptr )
    {
      (*v0)->DecrementReferenceCount(this: *v0);
      *v0 = nullptr;
    }
    ++v0;
  }
  while ( (int)v0 < (int)currentloadedsky );
  currentloadedsky[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D9730
// Name: bool R_LoadNamedSkys(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl R_LoadNamedSkys(const char *skyname)
{
  int i; // esi
  IMaterial *v2; // eax
  int j; // esi
  IMaterial *v4; // ecx
  IMaterial *v5; // ecx
  char name[260]; // [esp+8h] [ebp-134h] BYREF
  IMaterial *skies[6]; // [esp+10Ch] [ebp-30h]
  char *skyboxsuffix[6]; // [esp+124h] [ebp-18h]

  skyboxsuffix[0] = "rt";
  skyboxsuffix[1] = "bk";
  skyboxsuffix[2] = "lf";
  skyboxsuffix[3] = "ft";
  skyboxsuffix[4] = "up";
  skyboxsuffix[5] = "dn";
  for ( i = 0; i < 6; ++i )
  {
    V_snprintf(pDest: name, maxLen: 260, pFormat: "skybox/%s%s", skyname, skyboxsuffix[i]);
    v2 = materials->FindMaterial(this: materials, a2: name, a3: "SkyBox textures", a4: 1, a5: 0);
    skies[i] = v2;
    if ( v2 == nullptr || v2->IsErrorMaterial(this: v2) )
      return 0;
  }
  for ( j = 0; j < 6; ++j )
  {
    v4 = skyboxMaterials[j];
    if ( v4 != nullptr )
    {
      v4->DecrementReferenceCount(this: v4);
      skyboxMaterials[j] = nullptr;
    }
    v5 = skies[j];
    skyboxMaterials[j] = v5;
    v5->IncrementReferenceCount(this: v5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D9820
// Name: void R_LoadSkys(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LoadSkys()
{
  char v0; // bl

  v0 = 1;
  if ( (_S1_9 & 1) == 0 )
  {
    _S1_9 |= 1u;
    ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname");
  }
  if ( ConVarRef::IsValid(this: &skyname) )
  {
    if ( _V_stricmp(s1: skyname.m_pConVarState->m_Value.m_pszString, s2: currentloadedsky) != 0 )
    {
      if ( R_LoadNamedSkys(skyname: skyname.m_pConVarState->m_Value.m_pszString) == 0 )
      {
        v0 = 0;
        if ( _V_stricmp(s1: skyname.m_pConVarState->m_Value.m_pszString, s2: "sky_urb01") != 0
          && R_LoadNamedSkys(skyname: "sky_urb01") != 0 )
        {
          _ConDMsg(
            a1: "Unable to load sky %s, but successfully loaded %s\n",
            skyname.m_pConVarState->m_Value.m_pszString,
            "sky_urb01");
          skyname.m_pConVar->SetValue_4(this: skyname.m_pConVar, a2: "sky_urb01");
          v0 = 1;
        }
      }
      V_strncpy(pDest: currentloadedsky, pSrc: skyname.m_pConVarState->m_Value.m_pszString, maxLen: 128);
      if ( v0 == 0 )
        _ConDMsg(a1: "Unable to load sky %s\n", skyname.m_pConVarState->m_Value.m_pszString);
    }
  }
  else
  {
    _ConDMsg(a1: "Unable to find skyname ConVar!!!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9930
// Name: void MakeSkyVec(float,float,int,float,class Vector __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeSkyVec(float s, float t, int axis, float zFar, Vector *position, Vector2D *texCoord)
{
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  int v9; // ecx
  float v10; // xmm3_4
  int v11; // ecx
  float v12; // xmm6_4
  float v13; // xmm3_4
  int v14; // eax
  float v15; // xmm5_4
  float v16; // xmm4_4
  float z; // xmm3_4
  int v18; // [esp+0h] [ebp-10h]
  Vector b; // [esp+4h] [ebp-Ch]

  v6 = s;
  v7 = flScale * zFar;
  if ( s >= -1.0 )
  {
    if ( s > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = -1.0;
  }
  v8 = t;
  if ( t >= -1.0 )
  {
    if ( t > 1.0 )
      v8 = 1.0;
  }
  else
  {
    v8 = -1.0;
  }
  v9 = st_to_vec[axis][0];
  b.x = v7 * v6;
  b.y = v7 * v8;
  b.z = flScale * zFar;
  if ( v9 >= 0 )
    v10 = *((float *)&v18 + v9);
  else
    v10 = -*((float *)&b - v9 - 1);
  v11 = dword_104162AC[3 * axis];
  v12 = g_CurrentViewOrigin.x + v10;
  if ( v11 >= 0 )
    v13 = *((float *)&v18 + v11);
  else
    v13 = -*((float *)&b - v11 - 1);
  v14 = dword_104162B0[3 * axis];
  v15 = g_CurrentViewOrigin.y + v13;
  if ( v14 >= 0 )
    v16 = *((float *)&v18 + v14);
  else
    v16 = -*((float *)&b - v14 - 1);
  z = g_CurrentViewOrigin.z;
  position->x = v12;
  position->y = v15;
  position->z = z + v16;
  texCoord->x = (float)(v6 + 1.0) * 0.5;
  texCoord->y = 1.0 - (float)((float)(v8 + 1.0) * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x100D9A90
// Name: void R_DrawSkyBox(float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawSkyBox(CMeshBuilder *p_meshBuilder@<ebx>, int m_nIndexCount@<edi>, float zFar, int nDrawFlags)
{
  int v4; // esi
  IMatRenderContext *m_pObject; // ebx
  int v6; // edi
  IMaterial *v7; // eax
  IMesh *v8; // ebx
  float *p_y; // edi
  float *m_pCurrPosition; // eax
  float *v11; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+2Ch] [ebp-244h] BYREF
  Vector positionArray[4]; // [esp+214h] [ebp-5Ch] BYREF
  Vector2D texCoordArray[4]; // [esp+244h] [ebp-2Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+268h] [ebp-8h]
  int i; // [esp+26Ch] [ebp-4h]

  v4 = 0;
  if ( r_drawskybox.m_pParent != nullptr
    && r_drawskybox.m_pParent->m_Value.m_nValue != 0
    && mat_loadtextures.m_pParent != nullptr
    && mat_loadtextures.m_pParent->m_Value.m_nValue != 0 )
  {
    R_LoadSkys();
    m_pObject = materials->GetRenderContext(this: materials);
    pRenderContext.m_pObject = m_pObject;
    if ( m_pObject != nullptr )
      m_pObject->BeginRender(this: m_pObject);
    v6 = 0;
    i = 0;
    do
    {
      if ( (nDrawFlags & 1) != 0 )
      {
        v7 = skyboxMaterials[skytexorder[v6]];
        if ( v7 != nullptr )
        {
          ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, CMeshBuilder *))m_pObject->Bind)(
            a1: m_pObject,
            a2: v7,
            a3: 0,
            a4: m_nIndexCount,
            a5: p_meshBuilder);
          MakeSkyVec(s: -1.0, t: -1.0, axis: v6, zFar, position: positionArray, texCoord: texCoordArray);
          MakeSkyVec(s: -1.0, t: 1.0, axis: v6, zFar, position: &positionArray[1], texCoord: &texCoordArray[1]);
          MakeSkyVec(s: 1.0, t: 1.0, axis: v6, zFar, position: &positionArray[2], texCoord: &texCoordArray[2]);
          MakeSkyVec(s: 1.0, t: -1.0, axis: v6, zFar, position: &positionArray[3], texCoord: &texCoordArray[3]);
          v8 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
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
          CVertexBuilder::AttachBegin(
            this: &meshBuilder.m_VertexBuilder,
            pMesh: v8,
            nMaxVertexCount: 4,
            desc: &meshBuilder);
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
          p_y = &positionArray[0].y;
          do
          {
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
            m_pCurrPosition[1] = *p_y;
            m_pCurrPosition[2] = p_y[1];
            v11 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = texCoordArray[v4].x;
            v11[1] = texCoordArray[v4].y;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v4;
            p_y += 3;
          }
          while ( v4 < 4 );
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
          p_meshBuilder = &meshBuilder;
          m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
          ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
            a1: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
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
          m_pObject = pRenderContext.m_pObject;
          v6 = i;
          v4 = 0;
        }
      }
      nDrawFlags >>= 1;
      i = ++v6;
    }
    while ( v6 < 6 );
    if ( m_pObject != nullptr )
    {
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
  }
}

} // namespace engine_xlsp
