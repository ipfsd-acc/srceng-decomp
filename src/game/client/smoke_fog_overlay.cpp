// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/smoke_fog_overlay.cpp
// Functions: 16
// ============================================================

#include "game\client\smoke_fog_overlay.h"

//------------------------------------------------------------------------------
// Address: 0x1026D7C0
// Name: public: virtual void PrecacheSmokeFogOverlayPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheSmokeFogOverlayPrecache::CResourcePrecacher::Cache(
        PrecacheSmokeFogOverlayPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "particle/screenspace_fog",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1026D7F0
// Name: void TermSmokeFogOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TermSmokeFogOverlay()
{
  if ( g_pSmokeFogMaterial != nullptr )
  {
    g_pSmokeFogMaterial->DecrementReferenceCount(this: g_pSmokeFogMaterial);
    g_pSmokeFogMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D810
// Name: void InitSmokeFogOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitSmokeFogOverlay()
{
  IMaterial *v0; // eax

  if ( g_pSmokeFogMaterial != nullptr )
  {
    g_pSmokeFogMaterial->DecrementReferenceCount(this: g_pSmokeFogMaterial);
    g_pSmokeFogMaterial = nullptr;
  }
  g_SmokeFogOverlayAlpha = 0.0;
  g_SmokeFogOverlayColor.x = 0.0;
  g_SmokeFogOverlayColor.y = 0.0;
  g_SmokeFogOverlayColor.z = 0.0;
  if ( materials != nullptr )
  {
    v0 = materials->FindMaterial(
           this: materials,
           a2: "particle/screenspace_fog",
           a3: "ClientEffect textures",
           a4: 1,
           a5: 0);
    g_pSmokeFogMaterial = v0;
    if ( v0 != nullptr )
      v0->IncrementReferenceCount(this: v0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D890
// Name: void DrawSmokeFogOverlay(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawSmokeFogOverlay(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  int v3; // edi
  IMesh *v4; // esi
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float *m_pCurrPosition; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  float *v16; // eax
  float v17; // xmm1_4
  float *v18; // eax
  int m_nVertexCount; // eax
  void (__thiscall *UnlockMesh)(IMesh *, int, int, MeshDesc_t *); // eax
  CMeshBuilder meshBuilder; // [esp+40h] [ebp-214h] BYREF
  float v22; // [esp+228h] [ebp-2Ch]
  Vector vColor; // [esp+22Ch] [ebp-28h]
  float v24; // [esp+238h] [ebp-1Ch]
  float v25; // [esp+23Ch] [ebp-18h]
  float v26; // [esp+240h] [ebp-14h]
  float v27; // [esp+244h] [ebp-10h]
  float alpha; // [esp+248h] [ebp-Ch]
  float v29; // [esp+24Ch] [ebp-8h]
  float v30; // [esp+250h] [ebp-4h]

  if ( g_SmokeFogOverlayAlpha != 0.0 && g_pSmokeFogMaterial != nullptr && materials != nullptr )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, VertexCompressionType_t, int, float *, float *, unsigned __int8 *, float *, unsigned __int8 *))materials->GetRenderContext)(
           a1: materials,
           a2,
           a3,
           a4: a1,
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
           a19: meshBuilder.m_VertexSize_TangentS,
           a20: meshBuilder.m_VertexSize_TangentT,
           a21: meshBuilder.m_VertexSize_Wrinkle,
           a22: meshBuilder.m_VertexSize_UserData,
           a23: meshBuilder.m_ActualVertexSize,
           a24: meshBuilder.m_CompressionType,
           a25: meshBuilder.m_NumBoneWeights,
           a26: meshBuilder.m_pPosition,
           a27: meshBuilder.m_pBoneWeight,
           a28: meshBuilder.m_pBoneMatrixIndex,
           a29: meshBuilder.m_pNormal,
           a30: meshBuilder.m_pColor);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int, _DWORD, int, _DWORD, int))(*(_DWORD *)v3 + 128))(
      a1: v3,
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: 1072693248,
      a8: 0,
      a9: 1072693248,
      a10: 0,
      a11: -1057461776,
      a12: 0,
      a13: 1090021872);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    v4 = (IMesh *)(*(int (__thiscall **)(int, _DWORD, _DWORD, _DWORD, IMaterial *))(*(_DWORD *)v3 + 228))(
                    a1: v3,
                    a2: 0,
                    a3: 0,
                    a4: 0,
                    a5: g_pSmokeFogMaterial);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v5 = g_SmokeFogOverlayColor.x * (float)(1.0 / g_SmokeFogOverlayAlpha);
    v6 = g_SmokeFogOverlayColor.y * (float)(1.0 / g_SmokeFogOverlayAlpha);
    v7 = g_SmokeFogOverlayColor.z * (float)(1.0 / g_SmokeFogOverlayAlpha);
    vColor.x = v5;
    vColor.y = v6;
    vColor.z = v7;
    if ( v5 <= 0.0 )
    {
      vColor.x = 0.0;
    }
    else if ( v5 >= 1.0 )
    {
      vColor.x = 1.0;
    }
    if ( v6 <= 0.0 )
    {
      vColor.y = 0.0;
    }
    else if ( v6 >= 1.0 )
    {
      vColor.y = 1.0;
    }
    if ( v7 <= 0.0 )
    {
      vColor.z = 0.0;
    }
    else if ( v7 >= 1.0 )
    {
      vColor.z = 1.0;
    }
    if ( g_SmokeFogOverlayAlpha <= 0.0 )
    {
      alpha = 0.0;
    }
    else if ( g_SmokeFogOverlayAlpha >= 1.0 )
    {
      alpha = 1.0;
    }
    else
    {
      alpha = g_SmokeFogOverlayAlpha;
    }
    meshBuilder.m_pMesh = v4;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v9 = dist;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = v9;
    v27 = (float)(vColor.z * 255.0) + 8388608.0;
    v25 = v27;
    v26 = (float)(vColor.y * 255.0) + 8388608.0;
    v24 = v26;
    v29 = (float)(vColor.x * 255.0) + 8388608.0;
    v22 = v29;
    v10 = (float)(alpha * 255.0) + 8388608.0;
    v30 = v10;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                        | ((LOBYTE(v26) | ((LOBYTE(v29) | (LOBYTE(v30) << 8)) << 8)) << 8);
    v11 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    alpha = v10;
    v11[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v12 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v12[1] = 1.0;
    v12[2] = dist;
    v30 = v25;
    v29 = v24;
    v26 = v22;
    v27 = alpha;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                        | ((LOBYTE(v24) | ((LOBYTE(v22) | (LOBYTE(alpha) << 8)) << 8)) << 8);
    v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v13[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 1.0;
    v14[1] = 1.0;
    v14[2] = dist;
    v30 = v25;
    v29 = v24;
    v26 = v22;
    v27 = alpha;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                        | ((LOBYTE(v24) | ((LOBYTE(v22) | (LOBYTE(alpha) << 8)) << 8)) << 8);
    v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v15[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v17 = dist;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 1.0;
    v16[1] = 0.0;
    v16[2] = v17;
    v30 = v25;
    v29 = v24;
    v26 = v22;
    v27 = alpha;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                        | ((LOBYTE(v24) | ((LOBYTE(v22) | (LOBYTE(alpha) << 8)) << 8)) << 8);
    v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v18[1] = 0.0;
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
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v4->Draw_2(this: v4, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042D1A0
// Name: PrecacheSmokeFogOverlayPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheSmokeFogOverlayPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheSmokeFogOverlayPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheSmokeFogOverlayPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D1C0
// Name: _dynamic_initializer_for__s_ClientTools__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ClientTools__()
{
  CClientTools::CClientTools(this: &s_ClientTools);
  return atexit(func: dynamic_atexit_destructor_for__s_ClientTools__);
}

//------------------------------------------------------------------------------
// Address: 0x1042D1E0
// Name: _dynamic_initializer_for____g_CreateCClientToolsIClientTools_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCClientToolsIClientTools_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCClientToolsIClientTools_reg,
           fn: (void *(__cdecl *)())_CreateCClientToolsIClientTools_interface,
           pName: "VCLIENTTOOLS001");
}

//------------------------------------------------------------------------------
// Address: 0x1042D200
// Name: _dynamic_initializer_for__g_ToolFrameworkClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ToolFrameworkClient__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ToolFrameworkClient__);
}

//------------------------------------------------------------------------------
// Address: 0x1042D210
// Name: sub_1042D210
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_1042D210()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_10676164 = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x1042D230
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1042D260
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1042D290
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1042D2C0
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x1042D300
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x1042D330
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x1042D360
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}
