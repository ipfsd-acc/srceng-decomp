// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/buildmodelforworld.cpp
// Functions: 30
// ============================================================

#include "engine\buildmodelforworld.h"

//------------------------------------------------------------------------------
// Address: 0x10063F00
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int,int,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(
        CMeshBuilder *this,
        IMesh *pMesh,
        MaterialPrimitiveType_t type,
        int nVertexCount,
        int nIndexCount,
        MeshBuffersAllocationSettings_t *pMeshSettings)
{
  this->m_Type = type;
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->SetPrimitiveType(this: pMesh, a2: type);
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: nVertexCount, a3: nIndexCount, a4: this, a5: pMeshSettings);
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: nVertexCount, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1006AC30
// Name: void Vector2DAdd(class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DAdd(const Vector2D *a, const Vector2D *b, Vector2D *c)
{
  c->x = a->x + b->x;
  c->y = a->y + b->y;
}

//------------------------------------------------------------------------------
// Address: 0x1006AC60
// Name: void Vector2DMultiply(class Vector2D const __near &,float,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DMultiply(const Vector2D *a, float b, Vector2D *c)
{
  c->x = a->x * b;
  c->y = a->y * b;
}

//------------------------------------------------------------------------------
// Address: 0x1006AC90
// Name: LoadBSPPackInterface
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *LoadBSPPackInterface()
{
  struct CSysModule *result; // eax

  result = FileSystem_LoadModule(path: "bsppack");
  s_pBSPPackModule = result;
  if ( result != nullptr )
  {
    result = (struct CSysModule *)Sys_GetFactory(pModule: result);
    if ( result != nullptr )
    {
      result = (struct CSysModule *)((int (__cdecl *)(const char *, _DWORD))result)(a1: "IBSPPACK003", a2: 0);
      s_pBSPPack = (IBSPPack *)result;
    }
  }
  if ( s_pBSPPack == nullptr )
    return (struct CSysModule *)_Error(a1: "can't get bsppack interface\n");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006ACE0
// Name: ComputeMapName
// Source: json
//------------------------------------------------------------------------------
char __usercall ComputeMapName@<al>(char *pMapName@<edi>, int nMapNameSize@<ebx>)
{
  IClientEntity *v2; // eax
  IClientRenderable *v3; // esi
  const model_t *v4; // eax
  const char *v5; // esi

  v2 = entitylist->GetClientEntity(this: entitylist, a2: 0);
  if ( v2 == nullptr )
    return 0;
  v3 = &v2->IClientRenderable;
  if ( v2->GetModel(this: &v2->IClientRenderable) == nullptr )
    return 0;
  v4 = v3->GetModel(this: v3);
  v5 = modelloader->GetName(this: modelloader, a2: v4);
  if ( V_stristr(pStr: v5, pSearch: "maps/") == v5 || V_stristr(pStr: v5, pSearch: "maps\\") == v5 )
  {
    V_strncpy(pDest: pMapName, pSrc: v5 + 5, maxLen: nMapNameSize);
    V_StripExtension(in: pMapName, out: pMapName, outSize: nMapNameSize);
    return 1;
  }
  else
  {
    V_FileBase(in: v5, out: pMapName, maxlen: nMapNameSize);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AD70
// Name: ComputeAndMakeDirectories
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeAndMakeDirectories(
        const char *pMapName@<esi>,
        int nMatDirSize@<eax>,
        char *pModelDir@<ebx>,
        char *pModelSrcDir@<edi>,
        char *pMatDir,
        char *pMaterialSrcDir,
        unsigned int nMaterialSrcDirSize,
        unsigned int nModelDirSize,
        unsigned int nModelSrcDirSize)
{
  const char *v9; // [esp+0h] [ebp-108h]
  char pTemp[260]; // [esp+4h] [ebp-104h] BYREF

  V_snprintf(pDest: pMatDir, maxLen: nMatDirSize, pFormat: "materials/models/maps/%s", v9);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pMatDir, a3: "DEFAULT_WRITE_PATH");
  V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "materialsrc/models/maps/%s", pMapName);
  GetModContentSubdirectory(pSubDir: pTemp, pBuf: pMaterialSrcDir, nBufLen: nMaterialSrcDirSize);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pMaterialSrcDir, a3: nullptr);
  V_snprintf(pDest: pModelDir, maxLen: nModelDirSize, pFormat: "models/maps//%s", pMapName);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pModelDir, a3: "DEFAULT_WRITE_PATH");
  V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "models/maps/%s", pMapName);
  GetModContentSubdirectory(pSubDir: pTemp, pBuf: pModelSrcDir, nBufLen: nModelSrcDirSize);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pModelSrcDir, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1006AE50
// Name: CreateSimpleWorldModelVMT
// Source: json
//------------------------------------------------------------------------------
char __usercall CreateSimpleWorldModelVMT@<al>(const char *pMaterialDir@<eax>, const char *mapName@<edi>)
{
  void *v2; // eax
  void *v3; // esi
  char vmtPath[260]; // [esp+4h] [ebp-104h] BYREF

  V_strncpy(pDest: vmtPath, pSrc: pMaterialDir, maxLen: 260);
  V_strncat(pDest: vmtPath, pSrc: "/simpleworldmodel.vmt", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v2 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: vmtPath, a3: "w", a4: 0);
  v3 = v2;
  if ( v2 != nullptr )
  {
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v2, a3: "\"patch\"\n");
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "{\n");
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: v3,
      a3: "\t\"include\" \"materials/engine/simpleworldmodel.vmt\"\n");
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "\t\"insert\"\n");
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "\t{\n");
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: v3,
      a3: "\t\t\"$basetexture\" \"models/maps/%s/simpleworldmodel\"\n",
      mapName);
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: v3,
      a3: "\t\t\"$albedo\" \"models/maps/%s/simpleworldmodel_albedo\"\n",
      mapName);
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: v3,
      a3: "\t\t\"$lightmap\" \"models/maps/%s/simpleworldmodel_lightmap\"\n",
      mapName);
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "\t}\n");
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "}\n");
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3);
    return 1;
  }
  else
  {
    _Warning(a1: "can't create %s\n", vmtPath);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AFB0
// Name: CompileQC
// Source: json
//------------------------------------------------------------------------------
void __usercall CompileQC(const char *pFileName@<esi>)
{
  const char *v1; // [esp+0h] [ebp-30Ch]
  char cmdline[776]; // [esp+4h] [ebp-308h] BYREF

  V_snprintf(pDest: cmdline, maxLen: 776, pFormat: "studiomdl.exe -nop4 %s", v1);
  if ( g_pProcessUtils->SimpleRunProcess(this: g_pProcessUtils, a2: cmdline, a3: nullptr, a4: nullptr) == -1 )
    _Msg(a1: "Failed compiling %s\n", pFileName);
  else
    _Msg(a1: "Compilation of \"%s\" succeeded\n", pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1006B020
// Name: CreateAndCompileQCFile
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateAndCompileQCFile(
        const char *mapName@<edi>,
        bool bWater@<bl>,
        int a3@<esi>,
        const char *pModelSrcDir)
{
  const char *v4; // eax
  void *v5; // esi
  const char *v6; // ecx
  const char *v7; // ecx
  const char *v8; // ecx
  char qcPath[260]; // [esp+0h] [ebp-104h] BYREF

  v4 = "_water";
  if ( !bWater )
    v4 = defaultValue;
  V_snprintf(pDest: qcPath, maxLen: 260, pFormat: "%s/simpleworldmodel%s.qc", pModelSrcDir, v4);
  v5 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, _DWORD, int))g_pFileSystem->Open)(
                 a1: &g_pFileSystem->IBaseFileSystem,
                 a2: qcPath,
                 a3: "w",
                 a4: 0,
                 a5: a3);
  if ( v5 != nullptr )
  {
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "// -- generated by buildmodelforworld --\n", mapName);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$cdmaterials \"models/maps/%s\"\n", mapName);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$scale 1.0\n");
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$surfaceprop \"default\"\n");
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$staticprop\n");
    v6 = "_water";
    if ( !bWater )
      v6 = defaultValue;
    g_pFileSystem->FPrintf(
      this: g_pFileSystem,
      a2: v5,
      a3: "$modelname \"maps/%s/simpleworldmodel%s.mdl\"\n",
      mapName,
      v6);
    v7 = "_water";
    if ( !bWater )
      v7 = defaultValue;
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$body \"Body\" \"simpleworldmodel%s.smd\"\n", v7);
    v8 = "_water";
    if ( !bWater )
      v8 = defaultValue;
    g_pFileSystem->FPrintf(
      this: g_pFileSystem,
      a2: v5,
      a3: "$sequence \"idle\" \"simpleworldmodel%s.smd\" fps 30\n",
      v8);
    ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: &g_pFileSystem->IBaseFileSystem);
    CompileQC(pFileName: qcPath);
  }
  else
  {
    _Warning(a1: "can't create qc file %s\n", qcPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B190
// Name: AddFileToPackAndDeleteFile
// Source: json
//------------------------------------------------------------------------------
void __usercall AddFileToPackAndDeleteFile(
        const char *mapName@<eax>,
        const char *pFormatString@<ecx>,
        const char *gameDir)
{
  char fullPath[260]; // [esp+0h] [ebp-208h] BYREF
  char relativePath[260]; // [esp+104h] [ebp-104h] BYREF

  V_snprintf(pDest: relativePath, maxLen: 260, pFormat: pFormatString, mapName);
  V_snprintf(pDest: fullPath, maxLen: 260, pFormat: "%s/%s", gameDir, relativePath);
  s_pBSPPack->AddFileToPack(this: s_pBSPPack, a2: relativePath, a3: fullPath);
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: fullPath, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1006B210
// Name: RemoveFileFromPack
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveFileFromPack(const char *mapName@<eax>, const char *pFormatString@<ecx>, const char *gameDir)
{
  char fullPath[260]; // [esp+0h] [ebp-208h] BYREF
  char relativePath[260]; // [esp+104h] [ebp-104h] BYREF

  V_snprintf(pDest: relativePath, maxLen: 260, pFormat: pFormatString, mapName);
  V_snprintf(pDest: fullPath, maxLen: 260, pFormat: "%s/%s", gameDir, relativePath);
  s_pBSPPack->RemoveFileFromPack(this: s_pBSPPack, a2: relativePath);
}

//------------------------------------------------------------------------------
// Address: 0x1006B270
// Name: RemoveContentFile
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveContentFile(const char *mapName@<eax>, const char *pFormatString@<ecx>)
{
  char absolutePath[260]; // [esp+0h] [ebp-208h] BYREF
  char pTemp[260]; // [esp+104h] [ebp-104h] BYREF

  V_snprintf(pDest: pTemp, maxLen: 260, pFormat: pFormatString, mapName);
  GetModContentSubdirectory(pSubDir: pTemp, pBuf: absolutePath, nBufLen: 260);
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: absolutePath, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1006B2D0
// Name: WriteSMDHeader
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteSMDHeader(void *smdfp@<esi>)
{
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "version 1\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "nodes\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "0 \"polymsh_extracted2\" -1\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "end\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "skeleton\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "time 0\n");
  g_pFullFileSystem->FPrintf(
    this: g_pFullFileSystem,
    a2: smdfp,
    a3: "0 0.000000 0.000000 0.000000 1.570796 0.000000 0.000000\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "end\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "triangles\n");
}

//------------------------------------------------------------------------------
// Address: 0x1006B390
// Name: Push2DRenderingSetup
// Source: json
//------------------------------------------------------------------------------
void __usercall Push2DRenderingSetup(
        IMatRenderContext *pRenderContext@<esi>,
        ITexture *pRenderTarget@<ecx>,
        int nAtlasedTextureWidth,
        int nAtlasedTextureHeight)
{
  double v4; // [esp+20h] [ebp-28h]
  double v5; // [esp+28h] [ebp-20h]
  float v6; // [esp+50h] [ebp+8h]
  float v7; // [esp+54h] [ebp+Ch]

  pRenderContext->PushRenderTargetAndViewport_3(this: pRenderContext, a2: pRenderTarget);
  pRenderContext->ClearColor4ub(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 255u);
  materials->ClearBuffers(this: materials, a2: true, a3: false, a4: false);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_PROJECTION);
  pRenderContext->PushMatrix(this: pRenderContext);
  pRenderContext->LoadIdentity(this: pRenderContext);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))pRenderContext->Scale)(
    a1: pRenderContext,
    a2: 1.0,
    a3: -1.0,
    a4: 1.0);
  v7 = (float)nAtlasedTextureHeight;
  v6 = (float)nAtlasedTextureWidth;
  v5 = (v7 + 0.5) * (float)(1.0 / v7);
  v4 = (v6 + 0.5) * (float)(1.0 / v6);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pRenderContext->Ortho)(
    a1: pRenderContext,
    a2: COERCE_UNSIGNED_INT64((float)(1.0 / v6) * 0.5),
    a3: HIDWORD(COERCE_UNSIGNED_INT64((float)(1.0 / v6) * 0.5)),
    a4: COERCE_UNSIGNED_INT64((float)(1.0 / v7) * 0.5),
    a5: HIDWORD(COERCE_UNSIGNED_INT64((float)(1.0 / v7) * 0.5)),
    a6: LODWORD(v4),
    a7: HIDWORD(v4),
    a8: LODWORD(v5),
    a9: HIDWORD(v5),
    a10: COERCE_UNSIGNED_INT64(-99999.0),
    a11: HIDWORD(COERCE_UNSIGNED_INT64(-99999.0)),
    a12: COERCE_UNSIGNED_INT64(99999.0),
    a13: HIDWORD(COERCE_UNSIGNED_INT64(99999.0)));
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_VIEW);
  pRenderContext->PushMatrix(this: pRenderContext);
  pRenderContext->LoadIdentity(this: pRenderContext);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PushMatrix(this: pRenderContext);
  pRenderContext->LoadIdentity(this: pRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x1006B4E0
// Name: private: void CMeshBuilder::ComputeNumVertsAndIndices(int __near *,int __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::ComputeNumVertsAndIndices(
        CMeshBuilder *this,
        int *pMaxVertices,
        int *pMaxIndices,
        MaterialPrimitiveType_t type,
        int nPrimitiveCount)
{
  switch ( type )
  {
    case MATERIAL_POINTS:
      *pMaxIndices = nPrimitiveCount;
      *pMaxVertices = nPrimitiveCount;
      break;
    case MATERIAL_LINES:
      *pMaxIndices = 2 * nPrimitiveCount;
      *pMaxVertices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLES:
      *pMaxIndices = 3 * nPrimitiveCount;
      *pMaxVertices = 3 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLE_STRIP:
      *pMaxIndices = nPrimitiveCount + 2;
      *pMaxVertices = nPrimitiveCount + 2;
      break;
    case MATERIAL_LINE_STRIP:
      *pMaxVertices = nPrimitiveCount + 1;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_LINE_LOOP:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_POLYGON:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 3 * nPrimitiveCount - 6;
      break;
    case MATERIAL_QUADS:
      *pMaxVertices = 4 * nPrimitiveCount;
      *pMaxIndices = 6 * nPrimitiveCount;
      break;
    case MATERIAL_INSTANCED_QUADS:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 0;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B5E0
// Name: SurfComputeAtlasedTextureCoordinate
// Source: json
//------------------------------------------------------------------------------
void __usercall SurfComputeAtlasedTextureCoordinate(
        msurface2_t *surfID@<edx>,
        const Vector *vec@<esi>,
        Vector2D *uv@<eax>,
        const SurfaceCtx_t *ctx)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float v6; // xmm0_4
  float *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm0_4

  if ( (surfID->flags & 1) != 0 )
  {
    uv->y = 0.5;
    uv->x = 0.5;
LABEL_3:
    x = uv->x;
    goto LABEL_4;
  }
  if ( *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) != 0 )
  {
    v7 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
    v8 = (float)((float)((float)(v7[9] * vec->y) + (float)(v7[8] * vec->x)) + (float)(v7[10] * vec->z)) + v7[11];
    uv->x = v8;
    uv->x = (float)(v8
                  - (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
          + 0.5;
    v9 = (float)((float)((float)(v7[13] * vec->y) + (float)(vec->x * v7[12])) + (float)(v7[14] * vec->z)) + v7[15];
    uv->y = v9;
    uv->y = (float)(v9
                  - (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
          + 0.5;
    uv->x = ctx->m_Scale.x * uv->x;
    uv->y = ctx->m_Scale.y * uv->y;
    uv->x = ctx->m_Offset.x + uv->x;
    v6 = ctx->m_Offset.y + uv->y;
  }
  else
  {
    v6 = ctx->m_Offset.y + (float)(ctx->m_Scale.y * 0.5);
    uv->x = ctx->m_Offset.x + (float)(ctx->m_Scale.x * 0.5);
  }
  uv->y = v6;
  if ( uv->x >= 0.0 )
  {
    if ( uv->x <= 1.0 )
      goto LABEL_3;
    x = 1.0;
  }
  else
  {
    x = 0.0;
  }
LABEL_4:
  uv->x = x;
  y = uv->y;
  if ( y >= 0.0 )
  {
    if ( y > 1.0 )
      y = 1.0;
    uv->y = y;
  }
  else
  {
    uv->y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B7C0
// Name: CalculateLuxelToWorldTransform
// Source: json
//------------------------------------------------------------------------------
void __usercall CalculateLuxelToWorldTransform(
        const Vector *vFaceNormal@<esi>,
        Vector *pLuxelOrigin@<edx>,
        Vector *pS@<ebx>,
        Vector *pT@<edi>,
        const mtexinfo_t *pTexInfo,
        float flFaceDistance)
{
  float v6; // xmm0_4
  float x; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm0_4

  v6 = (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].y)
     - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].z);
  x = pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].x;
  v8 = (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].y)
     - (float)(x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].y);
  v9 = (float)(x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].z)
     - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].z);
  v10 = -(float)((float)((float)(vFaceNormal->y * v9) + (float)(vFaceNormal->x * v6)) + (float)(vFaceNormal->z * v8));
  if ( fabs(v10) >= 0.000001 )
  {
    pS->x = (float)((float)(vFaceNormal->z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].y)
                  - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].z * vFaceNormal->y))
          * (float)(1.0 / v10);
    pT->x = (float)((float)(vFaceNormal->y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].z)
                  - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].y * vFaceNormal->z))
          * (float)(1.0 / v10);
    pLuxelOrigin->x = -(float)((float)(v6 * flFaceDistance) * (float)(1.0 / v10));
    pS->y = (float)((float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].z)
                  - (float)(vFaceNormal->z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].x))
          * (float)(1.0 / v10);
    pT->y = (float)((float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].x * vFaceNormal->z)
                  - (float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].z))
          * (float)(1.0 / v10);
    pLuxelOrigin->y = -(float)((float)(v9 * flFaceDistance) * (float)(1.0 / v10));
    pS->z = (float)((float)(vFaceNormal->y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].x)
                  - (float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].y))
          * (float)(1.0 / v10);
    pT->z = (float)((float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].y)
                  - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].x * vFaceNormal->y))
          * (float)(1.0 / v10);
    pLuxelOrigin->z = -(float)((float)(v8 * flFaceDistance) * (float)(1.0 / v10));
    v11 = -pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].w;
    pLuxelOrigin->x = (float)(pS->x * v11) + pLuxelOrigin->x;
    pLuxelOrigin->y = (float)(pS->y * v11) + pLuxelOrigin->y;
    pLuxelOrigin->z = (float)(pS->z * v11) + pLuxelOrigin->z;
    v12 = -pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].w;
    pLuxelOrigin->x = (float)(v12 * pT->x) + pLuxelOrigin->x;
    pLuxelOrigin->y = (float)(pT->y * v12) + pLuxelOrigin->y;
    pLuxelOrigin->z = (float)(v12 * pT->z) + pLuxelOrigin->z;
  }
  else
  {
    *pLuxelOrigin = vec3_origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BAE0
// Name: LuxelSpaceToWorld
// Source: json
//------------------------------------------------------------------------------
void __usercall LuxelSpaceToWorld(msurface2_t *surfID@<eax>, Vector *worldPosition@<esi>, float u, float v)
{
  float y; // xmm6_4
  float x; // xmm4_4
  float z; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  int v21; // edx
  Vector tVect; // [esp+4h] [ebp-24h] BYREF
  Vector sVect; // [esp+10h] [ebp-18h] BYREF
  Vector luxelBasePosition; // [esp+1Ch] [ebp-Ch] BYREF

  R_ComputeSurfaceBasis(surfID, &luxelBasePosition, &tVect, &sVect);
  y = luxelBasePosition.y;
  x = luxelBasePosition.x;
  z = luxelBasePosition.z;
  v8 = sVect.x;
  v9 = sVect.y;
  v10 = sVect.z;
  worldPosition->y = luxelBasePosition.y;
  worldPosition->x = x;
  worldPosition->z = z;
  v11 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v12 = (float)((float)(v9 * u) * v11) + y;
  v13 = (float)((float)(v8 * u) * v11) + x;
  v14 = v11 * (float)(v10 * u);
  v15 = tVect.z;
  v16 = v13;
  v17 = tVect.x;
  v18 = v12;
  v19 = tVect.y;
  worldPosition->x = v16;
  worldPosition->y = v18;
  v20 = v14 + z;
  worldPosition->z = v20;
  v21 = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                   + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  worldPosition->x = v16 + (float)((float)(v17 * v) * (float)v21);
  worldPosition->y = v18 + (float)((float)(v19 * v) * (float)v21);
  worldPosition->z = v20 + (float)((float)(v15 * v) * (float)v21);
}

//------------------------------------------------------------------------------
// Address: 0x1006BBF0
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(CMeshBuilder *this, IMesh *pMesh, int type, int numPrimitives)
{
  MaterialPrimitiveType_t v4; // ebx
  IMesh *v5; // edi
  MaterialPrimitiveType_t v7; // ebx
  IMesh *v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]

  v4 = type;
  v5 = pMesh;
  pMesh = nullptr;
  type = 0;
  v9 = numPrimitives;
  this->m_pMesh = v5;
  this->m_bGenerateIndices = true;
  this->m_Type = v4;
  CMeshBuilder::ComputeNumVertsAndIndices(
    this,
    pMaxVertices: (int *)&pMesh,
    pMaxIndices: &type,
    type: v4,
    nPrimitiveCount: v9);
  switch ( v4 )
  {
    case MATERIAL_LINE_STRIP:
    case MATERIAL_LINE_LOOP:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
      break;
    case MATERIAL_POLYGON:
    case MATERIAL_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
      break;
    case MATERIAL_INSTANCED_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_INSTANCED_QUADS);
      break;
    default:
      v5->SetPrimitiveType(this: v5, a2: v4);
      break;
  }
  v7 = type;
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: (int)pMesh, a3: type, a4: this, a5: nullptr);
  this->m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = v7;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  v8 = pMesh;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh: v5, nMaxVertexCount: (int)v8, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1006BD00
// Name: void DrawTexturedQuad(class IMaterial __near *,class IMatRenderContext __near *,struct msurface2_t __near *,struct surfacerect_t const __near &,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawTexturedQuad(
        IMaterial *pMaterial,
        IMatRenderContext *pRenderContext,
        msurface2_t *surfID,
        const surfacerect_t *rect,
        const Vector4D *vColor)
{
  IMesh *v5; // esi
  const surfacerect_t *v6; // ecx
  Vector2D *m_LMCoords; // ebx
  float *p_y; // esi
  float *m_pCurrPosition; // eax
  float *v10; // eax
  float *v11; // eax
  float *m_pCurrNormal; // eax
  int m_nVertexCount; // eax
  CMeshBuilder builder; // [esp+Ch] [ebp-200h] BYREF
  Vector2D texCoord; // [esp+1F4h] [ebp-18h] BYREF
  float v16; // [esp+1FCh] [ebp-10h]
  float v17; // [esp+200h] [ebp-Ch]
  float v18; // [esp+204h] [ebp-8h]
  float v19; // [esp+208h] [ebp-4h]
  int vertID; // [esp+218h] [ebp+Ch]

  v5 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: pMaterial);
  CMeshBuilder::CMeshBuilder(this: &builder);
  builder.m_pMesh = v5;
  builder.m_bGenerateIndices = true;
  builder.m_Type = MATERIAL_POLYGON;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
  builder.m_pMesh->LockMesh(this: builder.m_pMesh, a2: 4, a3: 6, a4: &builder, a5: nullptr);
  builder.m_IndexBuilder.m_nIndexOffset = builder.m_nFirstVertex;
  builder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  builder.m_IndexBuilder.m_nIndexCount = 0;
  builder.m_IndexBuilder.m_nMaxIndexCount = 6;
  builder.m_IndexBuilder.m_bModify = false;
  builder.m_IndexBuilder.m_pIndices = builder.m_pIndices;
  builder.m_IndexBuilder.m_nIndexSize = builder.m_nIndexSize;
  builder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &builder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 4, desc: &builder);
  builder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &builder.m_VertexBuilder);
  v6 = rect;
  vertID = 0;
  m_LMCoords = rect->m_LMCoords;
  p_y = &rect->m_vPos[0].y;
  while ( 1 )
  {
    SurfComputeTextureCoordinate(
      surfID,
      vec: &v6->m_vPosWorld[(vertID + v6->m_nTexCoordIndexOffset) % 4],
      pUV: &texCoord.x);
    m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
    *builder.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
    m_pCurrPosition[1] = *p_y;
    m_pCurrPosition[2] = p_y[1];
    v18 = (float)(vColor->z * 255.0) + 8388608.0;
    v19 = (float)(vColor->y * 255.0) + 8388608.0;
    v17 = (float)(vColor->x * 255.0) + 8388608.0;
    v16 = (float)(vColor->w * 255.0) + 8388608.0;
    *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = LOBYTE(v18)
                                                    | ((LOBYTE(v19) | ((LOBYTE(v17) | (LOBYTE(v16) << 8)) << 8)) << 8);
    *(Vector2D *)builder.m_VertexBuilder.m_pCurrTexCoord[0] = texCoord;
    v10 = builder.m_VertexBuilder.m_pCurrTexCoord[1];
    *builder.m_VertexBuilder.m_pCurrTexCoord[1] = m_LMCoords->x;
    v10[1] = m_LMCoords->y;
    v11 = builder.m_VertexBuilder.m_pCurrTexCoord[2];
    if ( (surfID->flags & 8) != 0 )
      *builder.m_VertexBuilder.m_pCurrTexCoord[2] = rect->m_flBumpSTexCoordOffset;
    else
      *builder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
    v11[1] = 0.0;
    m_pCurrNormal = builder.m_VertexBuilder.m_pCurrNormal;
    *builder.m_VertexBuilder.m_pCurrNormal = 0.0;
    m_pCurrNormal[1] = 0.0;
    m_pCurrNormal[2] = 1.0;
    CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
    ++m_LMCoords;
    p_y += 3;
    if ( ++vertID >= 4 )
      break;
    v6 = rect;
  }
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  builder.m_pMesh->UnlockMesh(
    this: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount,
    a4: &builder);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
  builder.m_pMesh = nullptr;
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C050
// Name: void WriteDisplacementSurfaceToSMD(struct msurface2_t __near *,class CDispInfo __near *,struct SurfaceCtx_t const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteDisplacementSurfaceToSMD(
        msurface2_t *surfID,
        CDispInfo *pDispInfo,
        const SurfaceCtx_t *ctxAtlased,
        void *smdfp)
{
  IMaterialSystem_vtbl *v4; // edi
  int v5; // eax
  msurfacelighting_t *surfacelighting; // eax
  unsigned int v8; // esi
  bool v9; // cc
  float v10; // xmm0_4
  int v11; // ebx
  CDispRenderVert *v12; // eax
  float v13; // [esp+6Ch] [ebp-1Ch]
  int v14; // [esp+74h] [ebp-14h] BYREF
  int v15; // [esp+78h] [ebp-10h] BYREF
  float v16; // [esp+7Ch] [ebp-Ch]
  float v17; // [esp+80h] [ebp-8h]
  int v18; // [esp+84h] [ebp-4h]
  int v19; // [esp+90h] [ebp+8h]
  int v20; // [esp+94h] [ebp+Ch]

  v4 = materials->__vftable;
  v5 = SortInfoToLightmapPage(sortID: surfID->materialSortID);
  v4->GetLightmapPageSize(this: materials, a2: v5, a3: &v14, a4: &v15);
  surfacelighting = host_state.worldbrush->surfacelighting;
  v8 = ((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
  v9 = pDispInfo->m_nIndices <= 0;
  v13 = (float)*(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v8) / (float)v14;
  v10 = (float)*(__int16 *)((char *)&surfacelighting->m_OffsetIntoLightmapPage[1] + v8) / (float)v15;
  v17 = (float)v14;
  v16 = (float)v15;
  v18 = 0;
  if ( !v9 )
  {
    v20 = 4;
    do
    {
      g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "simpleworldmodel.tga\n");
      v11 = 2;
      v19 = v20;
      do
      {
        v12 = &pDispInfo->m_Verts.m_Memory.m_pMemory[*(unsigned __int16 *)((char *)pDispInfo->m_Indices.m_Memory.m_pMemory
                                                                         + v19)
                                                   - pDispInfo->m_iVertOffset];
        g_pFullFileSystem->FPrintf(
          this: g_pFullFileSystem,
          a2: smdfp,
          a3: "%d %f %f %f %f %f %f %f %f\n",
          0,
          v12->m_vPos.x,
          v12->m_vPos.y,
          v12->m_vPos.z,
          v12->m_vNormal.x,
          v12->m_vNormal.y,
          v12->m_vNormal.z,
          (float)((float)(ctxAtlased->m_Scale.x * (float)((float)(v12->m_LMCoords.x - v13) * v17))
                + ctxAtlased->m_Offset.x),
          1.0
        - (float)((float)((float)((float)(v12->m_LMCoords.y - v10) * v16) * ctxAtlased->m_Scale.y)
                + ctxAtlased->m_Offset.y));
        v19 -= 2;
        --v11;
      }
      while ( v11 >= 0 );
      v20 += 6;
      v18 += 3;
    }
    while ( v18 < pDispInfo->m_nIndices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C230
// Name: void WriteSurfaceToSMD(struct worldbrushdata_t __near *,struct msurface2_t __near *,int,int,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteSurfaceToSMD(
        worldbrushdata_t *pBrushData,
        msurface2_t *surfID,
        int x,
        int y,
        void *smdfp,
        int nAtlasedTextureWidth,
        int nAtlasedTextureHeight)
{
  char *v8; // eax
  int v9; // esi
  int v10; // eax
  CDispInfo *pDispInfo; // eax
  int v12; // esi
  int v13; // esi
  mvertex_t *v14; // esi
  Vector *v15; // eax
  SurfaceCtx_t ctx; // [esp+0h] [ebp-2Ch] BYREF
  Vector2D uv; // [esp+24h] [ebp-8h] BYREF
  int surfIDa; // [esp+38h] [ebp+Ch]
  int v19; // [esp+3Ch] [ebp+10h]
  int v20; // [esp+48h] [ebp+1Ch]
  int ctxAtlased; // [esp+4Ch] [ebp+20h]

  v8 = (char *)host_state.worldbrush->surfacelighting
     + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
  v9 = *((__int16 *)v8 + 2);
  v10 = *((__int16 *)v8 + 3) + 1;
  ctx.m_Scale.x = 1.0 / (float)nAtlasedTextureWidth;
  ctx.m_LightmapSize[1] = v10;
  pDispInfo = (CDispInfo *)surfID->pDispInfo;
  ctx.m_Scale.y = 1.0 / (float)nAtlasedTextureHeight;
  ctx.m_LightmapPageSize[0] = nAtlasedTextureWidth;
  ctx.m_LightmapPageSize[1] = nAtlasedTextureHeight;
  ctx.m_LightmapSize[0] = v9 + 1;
  ctx.m_Offset.x = (float)x * ctx.m_Scale.x;
  ctx.m_Offset.y = (float)y * ctx.m_Scale.y;
  ctx.m_BumpSTexCoordOffset = 0.0;
  if ( pDispInfo != nullptr )
  {
    WriteDisplacementSurfaceToSMD(surfID, pDispInfo, ctxAtlased: &ctx, smdfp);
  }
  else
  {
    v12 = 0;
    ctxAtlased = 0;
    v19 = HIBYTE(surfID->flags) - 2;
    if ( v19 > 0 )
    {
      while ( 1 )
      {
        g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "simpleworldmodel.tga\n");
        surfIDa = 2;
        while ( 1 )
        {
          if ( surfIDa != 0 )
          {
            v13 = surfIDa == 1 ? v12 + 1 : v12 + 2;
            v20 = v13;
          }
          else
          {
            v20 = 0;
          }
          v14 = &pBrushData->vertexes[pBrushData->vertindices[v20 + surfID->firstvertindex]];
          SurfComputeAtlasedTextureCoordinate(surfID, vec: &v14->position, &uv, &ctx);
          v15 = &pBrushData->vertnormals[pBrushData->vertnormalindices[v20
                                                                     + host_state.worldbrush->surfacenormals[surfID - host_state.worldbrush->surfaces2].firstvertnormal]];
          g_pFullFileSystem->FPrintf(
            this: g_pFullFileSystem,
            a2: smdfp,
            a3: "%d %f %f %f %f %f %f %f %f\n",
            0,
            v14->position.x,
            v14->position.y,
            v14->position.z,
            v15->x,
            v15->y,
            v15->z,
            uv.x,
            1.0 - uv.y);
          if ( --surfIDa < 0 )
            break;
          v12 = ctxAtlased;
        }
        if ( ++ctxAtlased >= v19 )
          break;
        v12 = ctxAtlased;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C410
// Name: void DrawSurfaceRectToAtlasedTexture(float,float,float,float,int,int,struct msurface2_t __near *,enum RenderToAtlasedTextureRenderMode_t,class CDisplacementData const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawSurfaceRectToAtlasedTexture(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        float left,
        float top,
        float right,
        float bottom,
        int nRenderTargetWidth,
        int nRenderTargetHeight,
        msurface2_t *surfID,
        RenderToAtlasedTextureRenderMode_t renderMode,
        const CDisplacementData *dispData)
{
  float v12; // xmm0_4
  float v13; // xmm0_4
  msurfacelighting_t *surfacelighting; // edx
  int v16; // ecx
  char *v17; // eax
  int v18; // edx
  bool v19; // zf
  IMatRenderContext *v20; // ebx
  IMatRenderContext_vtbl *v21; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm3_4
  float v28; // xmm3_4
  IDispInfo *pDispInfo; // esi
  int v30; // eax
  char *v31; // eax
  int v32; // ecx
  int v33; // edx
  IMatRenderContext v34; // eax
  float v35; // xmm0_4
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  IMesh *v37; // ebx
  char *v38; // eax
  float v39; // xmm0_4
  int v40; // eax
  int v41; // eax
  int v42; // ebx
  float *v43; // eax
  float *m_pCurrPosition; // ecx
  float v45; // xmm2_4
  float y; // xmm3_4
  float v47; // xmm0_4
  float v48; // xmm4_4
  float v49; // xmm1_4
  float v50; // xmm3_4
  float x; // xmm4_4
  float v52; // xmm3_4
  float v53; // xmm4_4
  float *v54; // ecx
  float *v55; // ecx
  float *v56; // ecx
  float *v57; // ecx
  float *v58; // eax
  float *v59; // eax
  float *m_pCurrNormal; // eax
  int v61; // eax
  unsigned int m_nCurrentIndex; // ecx
  unsigned __int16 v63; // dx
  int m_nVertexCount; // eax
  Vector v66; // [esp+8h] [ebp-39Ch] BYREF
  CMeshBuilder v67; // [esp+14h] [ebp-390h] BYREF
  float v68; // [esp+1FCh] [ebp-1A8h]
  float v69; // [esp+200h] [ebp-1A4h]
  int v70; // [esp+204h] [ebp-1A0h]
  int v71; // [esp+208h] [ebp-19Ch]
  int v72; // [esp+20Ch] [ebp-198h]
  int v73; // [esp+210h] [ebp-194h]
  int v74; // [esp+214h] [ebp-190h]
  float v75; // [esp+218h] [ebp-18Ch]
  Vector2D vLuxel; // [esp+21Ch] [ebp-188h]
  SurfaceCtx_t ctxAtlased; // [esp+224h] [ebp-180h] BYREF
  Vector vPos; // [esp+248h] [ebp-15Ch]
  surfacerect_t surfaceRect; // [esp+254h] [ebp-150h] BYREF
  Vector v80; // [esp+2DCh] [ebp-C8h] BYREF
  Vector sVect; // [esp+2E8h] [ebp-BCh] BYREF
  Vector v82; // [esp+2F4h] [ebp-B0h] BYREF
  Vector v83; // [esp+300h] [ebp-A4h] BYREF
  Vector v84; // [esp+30Ch] [ebp-98h] BYREF
  Vector v85; // [esp+318h] [ebp-8Ch] BYREF
  Vector vec; // [esp+324h] [ebp-80h] BYREF
  Vector v87; // [esp+330h] [ebp-74h]
  Vector luxelBasePosition; // [esp+33Ch] [ebp-68h] BYREF
  Vector4D vColor; // [esp+348h] [ebp-5Ch] BYREF
  Vector2D vOffset; // [esp+358h] [ebp-4Ch]
  int nLightmapPageSize[2]; // [esp+360h] [ebp-44h]
  float v92; // [esp+368h] [ebp-3Ch]
  float v93; // [esp+36Ch] [ebp-38h]
  SurfaceCtx_t ctx; // [esp+370h] [ebp-34h] BYREF
  Vector2D testUV; // [esp+394h] [ebp-10h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+39Ch] [ebp-8h]
  float flLeft; // [esp+3A0h] [ebp-4h]
  float flPageSizeV; // [esp+3ACh] [ebp+8h]
  float flLightmapSizeV; // [esp+3B0h] [ebp+Ch]
  float flPageSizeU; // [esp+3B4h] [ebp+10h]
  int flPageSizeUa; // [esp+3B4h] [ebp+10h]
  float worldPosition; // [esp+3B8h] [ebp+14h]
  float worldPositiona; // [esp+3B8h] [ebp+14h]
  IMaterial *worldPosition_4; // [esp+3BCh] [ebp+18h]
  float worldPosition_4a; // [esp+3BCh] [ebp+18h]
  float worldPosition_4b; // [esp+3BCh] [ebp+18h]
  float worldPosition_8; // [esp+3C0h] [ebp+1Ch]
  float v108; // [esp+3C4h] [ebp+20h]
  void (__thiscall **p_GetLightmapPageSize)(IMaterialSystem *, int, int *, int *); // [esp+3C8h] [ebp+24h]
  int v110; // [esp+3C8h] [ebp+24h]
  int v111; // [esp+3C8h] [ebp+24h]

  v12 = 1.0 / (float)nRenderTargetWidth;
  flPageSizeV = left * v12;
  flPageSizeU = right * v12;
  v13 = 1.0 / (float)nRenderTargetHeight;
  flLightmapSizeV = top * v13;
  worldPosition = bottom * v13;
  SurfSetupSurfaceContext(ctx: (SurfaceCtx_t *)&vColor.z, surfID);
  surfacelighting = host_state.worldbrush->surfacelighting;
  v16 = (char *)surfID - (char *)host_state.worldbrush->surfaces2;
  vLuxel.y = 1.0 / (float)nRenderTargetWidth;
  v17 = (char *)surfacelighting + (v16 & 0xFFFFFFE0);
  v18 = *((__int16 *)v17 + 3);
  v70 = *((__int16 *)v17 + 2) + 1;
  v19 = (surfID->flags & 0x100) == 0;
  vLuxel.x = (float)(int)flLightmapSizeV * v13;
  v72 = nRenderTargetWidth;
  v73 = nRenderTargetHeight;
  v71 = v18 + 1;
  *(float *)ctxAtlased.m_LightmapSize = v13;
  v75 = (float)(int)flPageSizeV * vLuxel.y;
  v74 = 0;
  if ( !v19 )
    TangentSpaceSurfaceSetup(surfID, tVect: &v66);
  v20 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
                               a1: materials,
                               a2,
                               a3,
                               a4: a1);
  ctx.m_LightmapPageSize[1] = (int)v20;
  if ( v20 != nullptr )
    v20->BeginRender(this: v20);
  worldPosition_4 = materialSortInfoArray[surfID->materialSortID].material;
  v20->Bind(this: v20, a2: worldPosition_4, a3: nullptr);
  v21 = v20->__vftable;
  if ( renderMode == RENDER_TO_ATLASED_TEXTURE_NO_LIGHTING )
  {
    BindLightmapPage = v21->BindLightmapPage;
    if ( (surfID->flags & 8) != 0 )
      BindLightmapPage(this: v20, a2: -2);
    else
      BindLightmapPage(this: v20, a2: -1);
  }
  else
  {
    v21->BindLightmapPage(this: v20, a2: materialSortInfoArray[surfID->materialSortID].lightmapPageID);
  }
  ctx.m_Offset.y = (float)((float)SLODWORD(vColor.z) * v93) + *(float *)&nLightmapPageSize[1];
  worldPosition_8 = *(float *)&nLightmapPageSize[1];
  v108 = v92;
  ctx.m_Offset.x = (float)((float)SLODWORD(vColor.w) * *(float *)ctx.m_LightmapSize) + v92;
  R_ComputeSurfaceBasis(
    surfID,
    luxelBasePosition: (Vector *)&v85.y,
    tVect: (Vector *)&v80.y,
    sVect: (Vector *)&surfaceRect.m_LMCoords[2].y);
  testUV.y = v85.y;
  pRenderContext.m_pObject = (IMatRenderContext *)LODWORD(v85.z);
  flLeft = vec.x;
  v23 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  testUV.y = (float)((float)(surfaceRect.m_LMCoords[2].y * 0.0) * v23) + v85.y;
  *(float *)&pRenderContext.m_pObject = (float)((float)(surfaceRect.m_LMCoords[3].x * 0.0) * v23) + v85.z;
  flLeft = (float)((float)(surfaceRect.m_LMCoords[3].y * 0.0) * v23) + vec.x;
  v24 = (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  testUV.y = (float)((float)(v80.y * 0.0) * v24) + testUV.y;
  *(float *)&pRenderContext.m_pObject = (float)((float)(v80.z * 0.0) * v24) + *(float *)&pRenderContext.m_pObject;
  flLeft = (float)((float)(sVect.x * 0.0) * v24) + flLeft;
  SurfComputeLightmapCoordinate(
    ctx: (const SurfaceCtx_t *)&vColor.z,
    surfID,
    vec: (const Vector *)&testUV.y,
    uv: (Vector2D *)&ctx.m_LightmapSize[1]);
  ctx.m_BumpSTexCoordOffset = *(float *)&ctx.m_LightmapSize[1] - (float)(v93 * 0.5);
  ctx.m_Scale.x = *(float *)ctx.m_LightmapPageSize - (float)(*(float *)ctx.m_LightmapSize * 0.5);
  R_ComputeSurfaceBasis(
    surfID,
    luxelBasePosition: (Vector *)&surfaceRect.m_LMCoords[1],
    tVect: (Vector *)&surfaceRect.m_flBumpSTexCoordOffset,
    sVect: (Vector *)&sVect.y);
  testUV.y = surfaceRect.m_LMCoords[1].x;
  pRenderContext.m_pObject = (IMatRenderContext *)LODWORD(surfaceRect.m_LMCoords[1].y);
  flLeft = surfaceRect.m_LMCoords[2].x;
  v25 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  testUV.y = (float)(sVect.y * v25) + surfaceRect.m_LMCoords[1].x;
  *(float *)&pRenderContext.m_pObject = (float)(sVect.z * v25) + surfaceRect.m_LMCoords[1].y;
  flLeft = (float)(v82.x * v25) + surfaceRect.m_LMCoords[2].x;
  v26 = (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  testUV.y = (float)(surfaceRect.m_flBumpSTexCoordOffset * v26) + testUV.y;
  *(float *)&pRenderContext.m_pObject = (float)(*(float *)&surfaceRect.m_nTexCoordIndexOffset * v26)
                                      + *(float *)&pRenderContext.m_pObject;
  flLeft = (float)(v80.x * v26) + flLeft;
  SurfComputeLightmapCoordinate(
    ctx: (const SurfaceCtx_t *)&vColor.z,
    surfID,
    vec: (const Vector *)&testUV.y,
    uv: (Vector2D *)&ctx.m_LightmapSize[1]);
  ctx.m_Scale.y = (float)(v93 * 0.5) + *(float *)&ctx.m_LightmapSize[1];
  testUV.x = (float)(*(float *)ctx.m_LightmapSize * 0.5) + *(float *)ctx.m_LightmapPageSize;
  LODWORD(surfaceRect.m_LMCoords[0].x) = nLightmapPageSize[0];
  ctxAtlased.m_BumpSTexCoordOffset = flPageSizeV;
  ctxAtlased.m_Scale.x = flPageSizeV;
  surfaceRect.m_LMCoords[0].y = 0.0;
  ctxAtlased.m_Offset.x = worldPosition;
  ctxAtlased.m_Offset.y = 0.5;
  ctxAtlased.m_Scale.y = flLightmapSizeV;
  vPos.x = 0.5;
  vPos.y = flPageSizeU;
  vPos.z = flLightmapSizeV;
  surfaceRect.m_vPos[0].x = 0.5;
  surfaceRect.m_vPos[0].y = flPageSizeU;
  surfaceRect.m_vPos[0].z = worldPosition;
  surfaceRect.m_vPos[1].x = 0.5;
  vec.y = (float)rand() * 0.000030518509;
  vec.z = (float)rand() * 0.000030518509;
  v87.x = (float)rand() * 0.000030518509;
  VectorNormalize(vec: (Vector *)&vec.y);
  v87.y = 0.0;
  R_ComputeSurfaceBasis(surfID, luxelBasePosition: (Vector *)&v83.y, tVect: (Vector *)&v84.y, sVect: (Vector *)&v82.y);
  surfaceRect.m_vPos[1].y = v83.y;
  surfaceRect.m_vPos[1].z = v83.z;
  surfaceRect.m_vPos[2].x = v84.x;
  v27 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  surfaceRect.m_vPos[1].y = v83.y + (float)((float)(v82.y * 0.0) * v27);
  surfaceRect.m_vPos[1].z = v83.z + (float)((float)(v82.z * 0.0) * v27);
  surfaceRect.m_vPos[2].x = v84.x + (float)((float)(v83.x * 0.0) * v27);
  v28 = (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  surfaceRect.m_vPos[1].y = (float)(v84.y * v28) + surfaceRect.m_vPos[1].y;
  surfaceRect.m_vPos[1].z = (float)(v84.z * v28) + surfaceRect.m_vPos[1].z;
  surfaceRect.m_vPos[2].x = (float)(v85.x * v28) + surfaceRect.m_vPos[2].x;
  LuxelSpaceToWorld(surfID, worldPosition: (Vector *)&surfaceRect.m_vPos[2].y, u: 0.0, v: 0.0);
  LuxelSpaceToWorld(surfID, worldPosition: (Vector *)&surfaceRect.m_vPos[3].y, u: 1.0, v: 0.0);
  LuxelSpaceToWorld(surfID, worldPosition: (Vector *)&surfaceRect.m_vPosWorld[0].y, u: 1.0, v: 1.0);
  surfaceRect.m_vPosWorld[1].y = (float)(int)(float)((float)(ctx.m_BumpSTexCoordOffset * (float)SLODWORD(vOffset.x))
                                                   + 0.5)
                               * v93;
  surfaceRect.m_vPosWorld[1].z = (float)(int)(float)((float)(testUV.x * (float)SLODWORD(vOffset.y)) + 0.5)
                               * *(float *)ctx.m_LightmapSize;
  surfaceRect.m_vPosWorld[2].x = surfaceRect.m_vPosWorld[1].y;
  surfaceRect.m_vPosWorld[2].y = (float)(int)(float)((float)(ctx.m_Scale.x * (float)SLODWORD(vOffset.y)) + 0.5)
                               * *(float *)ctx.m_LightmapSize;
  surfaceRect.m_vPosWorld[2].z = (float)(int)(float)((float)(ctx.m_Scale.y * (float)SLODWORD(vOffset.x)) + 0.5) * v93;
  surfaceRect.m_vPosWorld[3].x = surfaceRect.m_vPosWorld[2].y;
  surfaceRect.m_vPosWorld[3].y = surfaceRect.m_vPosWorld[2].z;
  surfaceRect.m_vPosWorld[3].z = surfaceRect.m_vPosWorld[1].z;
  DrawTexturedQuad(
    pMaterial: worldPosition_4,
    pRenderContext: v20,
    surfID,
    rect: (const surfacerect_t *)&ctxAtlased.m_BumpSTexCoordOffset,
    vColor: (const Vector4D *)&vec.y);
  pDispInfo = surfID->pDispInfo;
  if ( pDispInfo != nullptr && renderMode != RENDER_TO_ATLASED_TEXTURE_LIGHTING_ONLY )
  {
    p_GetLightmapPageSize = &materials->GetLightmapPageSize;
    v30 = SortInfoToLightmapPage(sortID: surfID->materialSortID);
    (*p_GetLightmapPageSize)(this: materials, a2: v30, a3: (int *)&luxelBasePosition.y, a4: (int *)&luxelBasePosition.z);
    v31 = (char *)host_state.worldbrush->surfacelighting
        + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
    v32 = *((__int16 *)v31 + 4);
    v33 = *((__int16 *)v31 + 5);
    v34.__vftable = v20->__vftable;
    v87.z = (float)v32 / (float)SLODWORD(luxelBasePosition.y);
    v35 = (float)v33;
    Bind = v34.Bind;
    testUV.x = (float)SLODWORD(luxelBasePosition.y);
    ctx.m_Scale.x = (float)SLODWORD(luxelBasePosition.z);
    luxelBasePosition.x = v35 / (float)SLODWORD(luxelBasePosition.z);
    Bind(this: v20, a2: worldPosition_4, a3: nullptr);
    v37 = v20->GetDynamicMesh(this: v20, a2: true, a3: nullptr, a4: nullptr, a5: worldPosition_4);
    v38 = (char *)host_state.worldbrush->surfacelighting
        + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
    worldPosition_4a = (float)(*((__int16 *)v38 + 2) + 1);
    v39 = (float)(*((__int16 *)v38 + 3) + 1);
    v40 = (int)pDispInfo[8].__vftable / 3;
    ctx.m_Scale.y = v39;
    v110 = v40;
    CMeshBuilder::CMeshBuilder(this: &v67);
    v67.m_pMesh = v37;
    v67.m_bGenerateIndices = true;
    v67.m_Type = MATERIAL_TRIANGLES;
    v110 *= 6;
    v37->SetPrimitiveType(this: v37, a2: MATERIAL_TRIANGLES);
    v67.m_pMesh->LockMesh(this: v67.m_pMesh, a2: v110, a3: v110, a4: &v67, a5: nullptr);
    v67.m_IndexBuilder.m_nIndexCount = 0;
    v67.m_IndexBuilder.m_bModify = false;
    v67.m_IndexBuilder.m_nCurrentIndex = 0;
    v67.m_IndexBuilder.m_nIndexOffset = v67.m_nFirstVertex;
    v67.m_IndexBuilder.m_pIndexBuffer = &v37->IIndexBuffer;
    v67.m_IndexBuilder.m_pIndices = v67.m_pIndices;
    v67.m_IndexBuilder.m_nMaxIndexCount = v110;
    v67.m_IndexBuilder.m_nIndexSize = v67.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &v67.m_VertexBuilder, pMesh: v37, nMaxVertexCount: v110, desc: &v67);
    v67.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &v67.m_VertexBuilder);
    v41 = dispData->m_nDispStartVert.m_Memory.m_pMemory[DispInfo_ComputeIndex(
                                                          hArray: host_state.worldbrush->hDispInfos,
                                                          pInfo: surfID->pDispInfo)];
    v111 = 0;
    if ( (int)pDispInfo[68].__vftable > 0 )
    {
      worldPosition_4b = testUV.x / worldPosition_4a;
      testUV.x = ctx.m_Scale.x / ctx.m_Scale.y;
      ctx.m_Scale.x = flPageSizeU - flPageSizeV;
      worldPositiona = worldPosition - flLightmapSizeV;
      ctxAtlased.m_LightmapPageSize[1] = 1056964608;
      flPageSizeUa = 0;
      ctx.m_Offset.y = ctx.m_Offset.y - worldPosition_8;
      ctx.m_Offset.x = ctx.m_Offset.x - v108;
      v42 = v41;
      do
      {
        v43 = (float *)((char *)pDispInfo[66].__vftable + flPageSizeUa);
        m_pCurrPosition = v67.m_VertexBuilder.m_pCurrPosition;
        v45 = (float)(v43[15] - luxelBasePosition.x) * testUV.x;
        y = ctx.m_Offset.y;
        v47 = (float)((float)(dispData->m_dispVerts.m_Memory.m_pMemory[v42].m_flAlpha * 0.0039215689) * 255.0)
            + 8388608.0;
        v48 = (float)(v43[14] - v87.z) * worldPosition_4b;
        v49 = (float)(v48 * ctx.m_Scale.x) + flPageSizeV;
        *v67.m_VertexBuilder.m_pCurrPosition = v49;
        v50 = y * v48;
        x = ctx.m_Offset.x;
        v52 = v50 + worldPosition_8;
        *(float *)&ctxAtlased.m_LightmapSize[1] = v49;
        m_pCurrPosition[1] = (float)(worldPositiona * v45) + flLightmapSizeV;
        m_pCurrPosition[2] = 0.5;
        *(float *)ctxAtlased.m_LightmapPageSize = (float)(worldPositiona * v45) + flLightmapSizeV;
        v68 = v52;
        v53 = (float)(x * v45) + v108;
        v69 = v53;
        vColor.x = 8388863.0;
        vColor.y = 8388863.0;
        ctx.m_BumpSTexCoordOffset = 8388863.0;
        ctx.m_Scale.y = v47;
        *(_DWORD *)v67.m_VertexBuilder.m_pCurrColor = (((((LOBYTE(v47) << 8) | 0xFF) << 8) | 0xFF) << 8) | 0xFF;
        v54 = v67.m_VertexBuilder.m_pCurrTexCoord[0];
        *v67.m_VertexBuilder.m_pCurrTexCoord[0] = v43[12];
        v54[1] = v43[13];
        v55 = v67.m_VertexBuilder.m_pCurrTexCoord[1];
        *v67.m_VertexBuilder.m_pCurrTexCoord[1] = v52;
        v55[1] = v53;
        v56 = (float *)((char *)v67.m_VertexBuilder.m_pTangentS
                      + v67.m_VertexBuilder.m_nCurrentVertex * v67.m_VertexBuilder.m_VertexSize_TangentS);
        *v56 = v43[6];
        v56[1] = v43[7];
        v56[2] = v43[8];
        v57 = v43 + 9;
        v58 = (float *)((char *)v67.m_VertexBuilder.m_pTangentT
                      + v67.m_VertexBuilder.m_nCurrentVertex * v67.m_VertexBuilder.m_VertexSize_TangentT);
        *v58 = *v57;
        v58[1] = v57[1];
        v58[2] = v57[2];
        v59 = v67.m_VertexBuilder.m_pCurrTexCoord[2];
        if ( (surfID->flags & 8) != 0 )
          *(_DWORD *)v67.m_VertexBuilder.m_pCurrTexCoord[2] = nLightmapPageSize[0];
        else
          *v67.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
        v59[1] = 0.0;
        m_pCurrNormal = v67.m_VertexBuilder.m_pCurrNormal;
        *v67.m_VertexBuilder.m_pCurrNormal = 0.0;
        m_pCurrNormal[1] = 0.0;
        m_pCurrNormal[2] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &v67.m_VertexBuilder);
        flPageSizeUa += 64;
        ++v42;
        ++v111;
      }
      while ( v111 < (int)pDispInfo[68].__vftable );
    }
    v61 = 0;
    if ( (int)pDispInfo[8].__vftable > 0 )
    {
      m_nCurrentIndex = v67.m_IndexBuilder.m_nCurrentIndex;
      do
      {
        v63 = LOWORD(v67.m_IndexBuilder.m_nIndexOffset)
            + *((_WORD *)&pDispInfo[61].dtr_IDispInfo + v61)
            - LOWORD(pDispInfo[11].__vftable);
        v61 += 3;
        v67.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v63;
        v67.m_IndexBuilder.m_nCurrentIndex += v67.m_IndexBuilder.m_nIndexSize;
        v67.m_IndexBuilder.m_nIndexCount = v67.m_IndexBuilder.m_nCurrentIndex;
        v67.m_IndexBuilder.m_pIndices[v67.m_IndexBuilder.m_nCurrentIndex] = LOWORD(v67.m_IndexBuilder.m_nIndexOffset)
                                                                          + *((_WORD *)pDispInfo[61].__vftable + v61 - 2)
                                                                          - LOWORD(pDispInfo[11].__vftable);
        v67.m_IndexBuilder.m_nCurrentIndex += v67.m_IndexBuilder.m_nIndexSize;
        v67.m_IndexBuilder.m_nIndexCount = v67.m_IndexBuilder.m_nCurrentIndex;
        v67.m_IndexBuilder.m_pIndices[v67.m_IndexBuilder.m_nCurrentIndex] = LOWORD(v67.m_IndexBuilder.m_nIndexOffset)
                                                                          + *((_WORD *)pDispInfo[61].__vftable + v61 - 1)
                                                                          - LOWORD(pDispInfo[11].__vftable);
        v67.m_IndexBuilder.m_nCurrentIndex += v67.m_IndexBuilder.m_nIndexSize;
        v67.m_IndexBuilder.m_nIndexCount = v67.m_IndexBuilder.m_nCurrentIndex;
        v67.m_IndexBuilder.m_pIndices[v67.m_IndexBuilder.m_nCurrentIndex] = LOWORD(v67.m_IndexBuilder.m_nIndexOffset)
                                                                          + *((_WORD *)pDispInfo[61].__vftable + v61 - 1)
                                                                          - LOWORD(pDispInfo[11].__vftable);
        v67.m_IndexBuilder.m_nCurrentIndex += v67.m_IndexBuilder.m_nIndexSize;
        v67.m_IndexBuilder.m_nIndexCount = v67.m_IndexBuilder.m_nCurrentIndex;
        v67.m_IndexBuilder.m_pIndices[v67.m_IndexBuilder.m_nCurrentIndex] = LOWORD(v67.m_IndexBuilder.m_nIndexOffset)
                                                                          + *((_WORD *)pDispInfo[61].__vftable + v61 - 2)
                                                                          - LOWORD(pDispInfo[11].__vftable);
        v67.m_IndexBuilder.m_nCurrentIndex += v67.m_IndexBuilder.m_nIndexSize;
        v67.m_IndexBuilder.m_nIndexCount = v67.m_IndexBuilder.m_nCurrentIndex;
        v67.m_IndexBuilder.m_pIndices[v67.m_IndexBuilder.m_nCurrentIndex] = LOWORD(v67.m_IndexBuilder.m_nIndexOffset)
                                                                          + *((_WORD *)pDispInfo[61].__vftable + v61 - 3)
                                                                          - LOWORD(pDispInfo[11].__vftable);
        m_nCurrentIndex = v67.m_IndexBuilder.m_nIndexSize + v67.m_IndexBuilder.m_nCurrentIndex;
        v67.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        v67.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      while ( v61 < (int)pDispInfo[8].__vftable );
    }
    if ( v67.m_bGenerateIndices )
    {
      switch ( v67.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * v67.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * v67.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * v67.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * v67.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = v67.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(this: &v67.m_IndexBuilder, primitiveType: v67.m_Type, nIndexCount: m_nVertexCount);
    }
    v67.m_pMesh->UnlockMesh(
      this: v67.m_pMesh,
      a2: v67.m_VertexBuilder.m_nVertexCount,
      a3: v67.m_IndexBuilder.m_nIndexCount,
      a4: &v67);
    v67.m_IndexBuilder.m_pIndexBuffer = nullptr;
    v67.m_IndexBuilder.m_nMaxIndexCount = 0;
    v67.m_VertexBuilder.m_nMaxVertexCount = 0;
    v67.m_VertexBuilder.m_pVertexBuffer = nullptr;
    v67.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v67.m_pMesh->Draw_2(this: v67.m_pMesh, a2: -1, a3: 0);
    v67.m_pMesh = nullptr;
    if ( v67.m_VertexBuilder.m_pVertexBuffer != nullptr
      && v67.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v67.m_VertexBuilder.m_pVertexBuffer) )
    {
      v67.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v67.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( v67.m_IndexBuilder.m_pIndexBuffer != nullptr
      && v67.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v67.m_IndexBuilder.m_pIndexBuffer) )
    {
      v67.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v67.m_IndexBuilder.m_pIndexBuffer);
    }
    v20 = (IMatRenderContext *)ctx.m_LightmapPageSize[1];
  }
  v20->EndRender(this: v20);
  v20->Release(this: v20);
}

//------------------------------------------------------------------------------
// Address: 0x1006D2D0
// Name: RenderToAtlasedTexture
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall RenderToAtlasedTexture(
        IMatRenderContext *pRenderContext@<ecx>,
        int nAtlasedTextureWidth@<eax>,
        const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *packedSurfaces,
        ITexture *pRenderTarget,
        int nAtlasedTextureHeight,
        const char *pMaterialSrcDir,
        const char *pTextureBaseName,
        RenderToAtlasedTextureRenderMode_t renderMode,
        const CDisplacementData *dispData,
        float flToneMapScale)
{
  const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *v10; // ebx
  int m_nValue; // eax
  void (__thiscall *SetToneMappingScaleLinear)(IMatRenderContext *, const Vector *); // edx
  CPackedSurfaceInfo *v15; // eax
  msurface2_t *m_SurfID; // ecx
  int v17; // ebx
  int v18; // eax
  int v19; // edx
  msurfacelighting_t *surfacelighting; // ecx
  unsigned __int8 *v21; // ebx
  void *v22; // edi
  int v23; // [esp+40h] [ebp-538h]
  int v24; // [esp+44h] [ebp-534h]
  char v25[16]; // [esp+4Ch] [ebp-52Ch] BYREF
  char v26[64]; // [esp+354h] [ebp-224h] BYREF
  char txtPath[260]; // [esp+394h] [ebp-1E4h] BYREF
  _BYTE tgaPath_196[28]; // [esp+55Ch] [ebp-1Ch] OVERLAPPED BYREF
  int v29; // [esp+59Ch] [ebp+24h]

  v10 = packedSurfaces;
  if ( mat_fastspecular.m_pParent != nullptr )
    m_nValue = mat_fastspecular.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  tgaPath_196[27] = m_nValue != 0;
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "0", a2: v23);
  if ( renderMode == RENDER_TO_ATLASED_TEXTURE_LIGHTING_ONLY )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fullbright.IConVar, value: "2", a2: v24);
  else
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fullbright.IConVar, value: "0", a2: v24);
  UpdateMaterialSystemConfig();
  materials->EndFrame(this: materials);
  ((void (__cdecl *)(_DWORD))materials->BeginFrame)(a1: LODWORD(host_frametime));
  SetToneMappingScaleLinear = pRenderContext->SetToneMappingScaleLinear;
  *(float *)tgaPath_196 = flToneMapScale;
  *(float *)&tgaPath_196[4] = flToneMapScale;
  *(float *)&tgaPath_196[8] = flToneMapScale;
  SetToneMappingScaleLinear(this: pRenderContext, a2: (const Vector *)tgaPath_196);
  Push2DRenderingSetup(pRenderContext, pRenderTarget, nAtlasedTextureWidth, nAtlasedTextureHeight);
  *(_DWORD *)&tgaPath_196[20] = 0;
  if ( packedSurfaces->m_Size > 0 )
  {
    v29 = 0;
    do
    {
      v15 = &v10->m_Memory.m_pMemory[v29];
      m_SurfID = v15->m_SurfID;
      v17 = v15->m_nMins[1];
      v18 = v15->m_nMins[0];
      *(_DWORD *)&tgaPath_196[12] = m_SurfID;
      v19 = (char *)m_SurfID - (char *)host_state.worldbrush->surfaces2;
      surfacelighting = host_state.worldbrush->surfacelighting;
      *(_DWORD *)&tgaPath_196[16] = v18;
      DrawSurfaceRectToAtlasedTexture(
        a1: v17,
        a2: nAtlasedTextureWidth,
        a3: (int)pRenderContext,
        left: (float)v18,
        top: (float)v17,
        right: (float)(v18 + *(__int16 *)((char *)surfacelighting->m_LightmapExtents + (v19 & 0xFFFFFFE0)) + 1),
        bottom: (float)(v17 + *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + (v19 & 0xFFFFFFE0)) + 1),
        nRenderTargetWidth: nAtlasedTextureWidth,
        nRenderTargetHeight: nAtlasedTextureHeight,
        surfID: *(msurface2_t **)&tgaPath_196[12],
        renderMode,
        dispData);
      v10 = packedSurfaces;
      ++v29;
      ++*(_DWORD *)&tgaPath_196[20];
    }
    while ( *(int *)&tgaPath_196[20] < packedSurfaces->m_Size );
  }
  v21 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 4 * nAtlasedTextureHeight * nAtlasedTextureWidth);
  pRenderContext->ReadPixels(
    this: pRenderContext,
    a2: 0,
    a3: 0,
    a4: nAtlasedTextureWidth,
    a5: nAtlasedTextureHeight,
    a6: v21,
    a7: IMAGE_FORMAT_RGBA8888);
  V_snprintf(pDest: &txtPath[196], maxLen: 260, pFormat: "%s/%s.tga", pMaterialSrcDir, pTextureBaseName);
  TGAWriter::WriteTGAFile(
    fileName: &txtPath[196],
    width: nAtlasedTextureWidth,
    height: nAtlasedTextureHeight,
    srcFormat: IMAGE_FORMAT_RGBA8888,
    srcData: (float16 *)v21,
    nStride: 4 * nAtlasedTextureWidth);
  free(pMem: v21);
  V_snprintf(pDest: v26, maxLen: 260, pFormat: "%s/%s.txt", pMaterialSrcDir, pTextureBaseName);
  v22 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v26, a3: "w", a4: 0);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v22, a3: "\"nocompress\" \"1\"\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v22, a3: "\"nomip\" \"1\"\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v22, a3: "\"nolod\" \"1\"\n");
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v22);
  V_snprintf(pDest: v25, maxLen: 776, pFormat: "vtex.exe -nop4 %s", &txtPath[196]);
  if ( g_pProcessUtils->SimpleRunProcess(this: g_pProcessUtils, a2: v25, a3: nullptr, a4: nullptr) == -1 )
    _Msg(a1: "Failed compiling %s\n", &txtPath[196]);
  else
    _Msg(a1: "Compilation of \"%s\" succeeded\n", &txtPath[196]);
  g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: v26, a3: nullptr);
  ((void (__thiscall *)(IFileSystem *))g_pFullFileSystem->RemoveFile)(a1: g_pFullFileSystem);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_VIEW);
  pRenderContext->PopMatrix(this: pRenderContext);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_PROJECTION);
  pRenderContext->PopMatrix(this: pRenderContext);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PopMatrix(this: pRenderContext);
  pRenderContext->PopRenderTargetAndViewport(this: pRenderContext);
  if ( tgaPath_196[27] != 0 )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "1", a2: (int)&txtPath[196]);
  else
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "0", a2: (int)&txtPath[196]);
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fullbright.IConVar, value: "0", a2: 0);
  UpdateMaterialSystemConfig();
  materials->EndFrame(this: materials);
  ((void (__cdecl *)(_DWORD))materials->BeginFrame)(a1: LODWORD(host_frametime));
}

//------------------------------------------------------------------------------
// Address: 0x1006D670
// Name: WriteSMD
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __usercall WriteSMD@<eax>(
        const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *packedSurfaces@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        int nAtlasedTextureWidth,
        int nAtlasedTextureHeight,
        const char *pModelSrcDir,
        bool bWater)
{
  const char *v7; // eax
  void *v8; // esi
  CPackedSurfaceInfo *v9; // edi
  IMaterial *material; // ecx
  const char *v11; // eax
  int v12; // ecx
  char smdPath[260]; // [esp+0h] [ebp-114h] BYREF
  worldbrushdata_t *pBrushData; // [esp+104h] [ebp-10h]
  int packedSurfaceIndex; // [esp+108h] [ebp-Ch]
  int nSurfaces; // [esp+10Ch] [ebp-8h]
  unsigned int v18; // [esp+110h] [ebp-4h]

  v7 = "_water";
  if ( !bWater )
    v7 = defaultValue;
  V_snprintf(pDest: smdPath, maxLen: 260, pFormat: "%s/simpleworldmodel%s.smd", pModelSrcDir, v7);
  v8 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, _DWORD, int, int))g_pFullFileSystem->Open)(
                 a1: &g_pFullFileSystem->IBaseFileSystem,
                 a2: smdPath,
                 a3: "w",
                 a4: 0,
                 a5: a2,
                 a6: a3);
  WriteSMDHeader(smdfp: v8);
  nSurfaces = 0;
  pBrushData = host_state.worldbrush;
  packedSurfaceIndex = 0;
  if ( packedSurfaces->m_Size > 0 )
  {
    v18 = 0;
    do
    {
      v9 = &packedSurfaces->m_Memory.m_pMemory[v18 / 0xC];
      material = materialSortInfoArray[v9->m_SurfID->materialSortID].material;
      v11 = material->GetShaderName(this: material);
      if ( (V_stristr(pStr: v11, pSearch: "water") != nullptr) == bWater )
      {
        v12 = v9->m_nMins[1];
        ++nSurfaces;
        WriteSurfaceToSMD(
          pBrushData,
          surfID: v9->m_SurfID,
          x: v9->m_nMins[0],
          y: v12,
          smdfp: v8,
          nAtlasedTextureWidth,
          nAtlasedTextureHeight);
      }
      v18 += 12;
      ++packedSurfaceIndex;
    }
    while ( packedSurfaceIndex < packedSurfaces->m_Size );
  }
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v8, a3: "end\n");
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
  return nSurfaces;
}

//------------------------------------------------------------------------------
// Address: 0x1006D780
// Name: PackSurfacesAndBuildSurfaceList
// Source: json
//------------------------------------------------------------------------------
void __usercall PackSurfacesAndBuildSurfaceList(
        CUtlMemory<CVTFTexture::ResourceMemorySection,int> *packedSurfaces@<esi>,
        int *nWidth,
        int *nHeight)
{
  int nWorldFaceCount; // edi
  msurface2_t *v4; // ebx
  char *v5; // eax
  int v6; // ecx
  int materialSortID; // eax
  IMaterial *material; // edi
  int v9; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CPackedSurfaceInfo *v12; // ecx
  int v13; // eax
  int v14; // edi
  CPackedSurfaceInfo *v15; // eax
  int v16; // edx
  CPackedSurfaceInfo *v17; // eax
  int v18; // edx
  CImagePacker v19; // [esp+4h] [ebp-2034h] BYREF
  int pReturnHeight; // [esp+2020h] [ebp-18h] BYREF
  int width; // [esp+2024h] [ebp-14h]
  int height; // [esp+2028h] [ebp-10h]
  int pReturnWidth; // [esp+202Ch] [ebp-Ch] BYREF
  int i; // [esp+2030h] [ebp-8h]
  unsigned int v25; // [esp+2034h] [ebp-4h]

  nWorldFaceCount = host_state.worldbrush->nWorldFaceCount;
  CImagePacker::Reset(this: &v19, nSortId: 0, maxLightmapWidth: 1024, maxLightmapHeight: 1024);
  if ( nWorldFaceCount > 0 )
  {
    v25 = 0;
    for ( i = nWorldFaceCount; i != 0; --i )
    {
      v4 = &host_state.worldbrush->surfaces2[v25 / 0x20];
      v5 = (char *)host_state.worldbrush->surfacelighting + (v25 & 0xFFFFFFE0);
      v6 = *((__int16 *)v5 + 2) + 1;
      height = *((__int16 *)v5 + 3) + 1;
      materialSortID = v4->materialSortID;
      width = v6;
      material = materialSortInfoArray[materialSortID].material;
      if ( !material->IsTranslucent(this: material)
        || (v9 = (int)material->FindVarFast(this: material, a2: "$worldimposter", a3: &dword_104DE64C)) != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 108))(a1: v9) != 0 )
      {
        m_pMemory = (int)packedSurfaces[1].m_pMemory;
        m_nAllocationCount = packedSurfaces->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
            this: packedSurfaces,
            num: m_pMemory - m_nAllocationCount + 1);
        ++packedSurfaces[1].m_pMemory;
        v12 = (CPackedSurfaceInfo *)packedSurfaces->m_pMemory;
        v13 = (int)packedSurfaces[1].m_pMemory - m_pMemory - 1;
        packedSurfaces[1].m_nAllocationCount = (int)packedSurfaces->m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 12 * v13);
        v14 = m_pMemory;
        v15 = (CPackedSurfaceInfo *)&packedSurfaces->m_pMemory[v14];
        if ( v15 != nullptr )
        {
          v15->m_SurfID = nullptr;
          v15->m_nMins[0] = -1;
          v15->m_nMins[1] = -1;
        }
        v16 = height;
        v17 = (CPackedSurfaceInfo *)&packedSurfaces->m_pMemory[v14];
        v17->m_SurfID = v4;
        if ( CImagePacker::AddBlock(this: &v19, width, height: v16, returnX: v17->m_nMins, returnY: &v17->m_nMins[1]) == 0 )
          _Warning(a1: "failed allocating an atlased texture block in buildmodelforworld\n");
      }
      v25 += 32;
    }
  }
  CImagePacker::GetMinimumDimensions(this: &v19, &pReturnWidth, &pReturnHeight);
  v18 = pReturnHeight;
  *nWidth = pReturnWidth;
  *nHeight = v18;
}

//------------------------------------------------------------------------------
// Address: 0x1006D910
// Name: public: CDisplacementData::CDisplacementData(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDisplacementData *__thiscall CDisplacementData::CDisplacementData(
        CDisplacementData *this,
        void *hDispInfo,
        int nDispInfo)
{
  int v4; // esi
  IDispInfo *v5; // eax
  int v6; // ecx
  int m_nAllocationCount; // eax
  CDispVert *m_pMemory; // ecx
  int v9; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  int i; // [esp+134h] [ebp-4h]

  v4 = 0;
  this->m_nDispStartVert.m_Memory.m_pMemory = nullptr;
  this->m_nDispStartVert.m_Memory.m_nAllocationCount = 0;
  this->m_nDispStartVert.m_Memory.m_nGrowSize = 0;
  this->m_nDispStartVert.m_pElements = nullptr;
  this->m_dispVerts.m_Memory.m_pMemory = nullptr;
  this->m_dispVerts.m_Memory.m_nAllocationCount = 0;
  this->m_dispVerts.m_Memory.m_nGrowSize = 0;
  this->m_dispVerts.m_Size = 0;
  this->m_dispVerts.m_pElements = nullptr;
  this->m_nDispStartVert.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: nDispInfo);
  i = 0;
  if ( nDispInfo > 0 )
  {
    do
    {
      v5 = DispInfo_IndexArray(hArray: hDispInfo, iElement: i);
      v6 = i;
      this->m_nDispStartVert.m_Memory.m_pMemory[i] = v4;
      v4 += (int)v5[119].ComputeShadowFragments;
      i = v6 + 1;
    }
    while ( v6 + 1 < nDispInfo );
  }
  this->m_dispVerts.m_Size = 0;
  if ( v4 != 0 )
  {
    m_nAllocationCount = this->m_dispVerts.m_Memory.m_nAllocationCount;
    if ( v4 > m_nAllocationCount )
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_dispVerts,
        num: v4 - m_nAllocationCount);
    this->m_dispVerts.m_Size += v4;
    m_pMemory = this->m_dispVerts.m_Memory.m_pMemory;
    v9 = this->m_dispVerts.m_Size - v4;
    this->m_dispVerts.m_pElements = m_pMemory;
    if ( v9 > 0 && v4 > 0 )
      _V_memmove(dest: &m_pMemory[v4], src: m_pMemory, count: 20 * v9);
  }
  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 33, bUncompress: true);
  CMapLoadHelper::LoadLumpData(this: &lh, offset: 0, size: 20 * v4, pData: this->m_dispVerts.m_Memory.m_pMemory);
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006DA30
// Name: buildmodelforworld
// Source: json
//------------------------------------------------------------------------------
void __usercall buildmodelforworld(int a1@<ebx>, unsigned int a2@<edi>)
{
  IBaseFileSystem_vtbl *v2; // esi
  CClientState *BaseLocalClient; // eax
  int v4; // eax
  IMatRenderContext *v5; // ebx
  CDispVert *m_pElements; // esi
  int m_nGrowSize; // edi
  int v8; // esi
  CDispVert *v9; // edi
  int m_nAllocationCount; // esi
  IFileSystem *v11; // [esp-4h] [ebp-790h]
  char *m_szLevelName; // [esp+20h] [ebp-76Ch]
  unsigned int flToneMapScale[9]; // [esp+24h] [ebp-768h] BYREF
  char modelDir[260]; // [esp+48h] [ebp-744h] BYREF
  char matDir[260]; // [esp+14Ch] [ebp-640h] BYREF
  char mapPath[260]; // [esp+250h] [ebp-53Ch] BYREF
  char materialSrcDir[260]; // [esp+354h] [ebp-438h] BYREF
  char modelSrcDir[260]; // [esp+458h] [ebp-334h] BYREF
  char gameDir[260]; // [esp+55Ch] [ebp-230h] BYREF
  char mapName[260]; // [esp+660h] [ebp-12Ch] BYREF
  CDisplacementData dispData; // [esp+764h] [ebp-28h] BYREF

  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&r_buildingmapforworld.IConVar,
    value: 1,
    a2: flToneMapScale[0],
    a3: flToneMapScale[1]);
  if ( g_LostVideoMemory )
  {
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&r_buildingmapforworld.IConVar,
      value: 0,
      a2: flToneMapScale[2],
      a3: flToneMapScale[3]);
    return;
  }
  v2 = g_pFileSystem->IBaseFileSystem::__vftable;
  flToneMapScale[0] = (unsigned int)"GAME";
  m_szLevelName = GetBaseLocalClient()->m_szLevelName;
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *))v2->IsFileWritable)(a1: &g_pFileSystem->IBaseFileSystem) == 0 )
  {
    BaseLocalClient = GetBaseLocalClient();
    _Warning(
      a1: "%s is not writable!!!  Check it out before running buildmodelforworld.\n",
      BaseLocalClient->m_szLevelName);
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&r_buildingmapforworld.IConVar,
      value: 0,
      a2: (unsigned int)m_szLevelName,
      a3: flToneMapScale[0]);
    return;
  }
  if ( ComputeMapName(pMapName: &gameDir[224], nMapNameSize: 260) == 0 )
  {
    _Warning(a1: "can't buildmodelforworld.  Map not loaded.\n");
LABEL_7:
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_buildingmapforworld.IConVar, value: 0, a2, a3: a1);
    return;
  }
  ComputeAndMakeDirectories(
    pMapName: &gameDir[224],
    nMatDirSize: 260,
    pModelDir: (char *)flToneMapScale,
    pModelSrcDir: &materialSrcDir[224],
    pMatDir: &modelDir[224],
    pMaterialSrcDir: &mapPath[224],
    nMaterialSrcDirSize: 0x104u,
    nModelDirSize: 0x104u,
    nModelSrcDirSize: 0x104u);
  COM_GetGameDir(szGameDir: &modelSrcDir[224], maxlen: 260);
  if ( CreateSimpleWorldModelVMT(pMaterialDir: &modelDir[224], mapName: &gameDir[224]) == 0 )
    goto LABEL_7;
  LOBYTE(dispData.m_nDispStartVert.m_Size) = Host_AllowQueuedMaterialSystem(bAllow: false);
  V_RenderVGuiOnly();
  CMapLoadHelper::Init(
    a1: (int)flToneMapScale,
    a2: 0,
    p_lumpHeader: (lumpfileheader_t *)&gameDir[224],
    pMapModel: host_state.worldmodel,
    pPathName: host_state.worldmodel->szPathName);
  CDisplacementData::CDisplacementData(
    this: (CDisplacementData *)&mapName[224],
    hDispInfo: host_state.worldbrush->hDispInfos,
    nDispInfo: host_state.worldbrush->numDispInfos);
  CMapLoadHelper::Shutdown();
  v4 = ((int (__thiscall *)(IMaterialSystem *, unsigned int, int))materials->GetRenderContext)(
         a1: materials,
         a2,
         a3: a1);
  v5 = (IMatRenderContext *)v4;
  dispData.m_nDispStartVert.m_Memory.m_nAllocationCount = v4;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  memset(&dispData.m_nDispStartVert.m_pElements, 0, 20);
  PackSurfacesAndBuildSurfaceList(
    packedSurfaces: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&dispData.m_nDispStartVert.m_pElements,
    nWidth: &dispData.m_nDispStartVert.m_Memory.m_nGrowSize,
    nHeight: (int *)&dispData.m_dispVerts.m_pElements);
  materials->ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(this: materials);
  materials->BeginRenderTargetAllocation(this: materials);
  m_pElements = dispData.m_dispVerts.m_pElements;
  m_nGrowSize = dispData.m_nDispStartVert.m_Memory.m_nGrowSize;
  dispData.m_dispVerts.m_pElements = (CDispVert *)materials->CreateRenderTargetTexture(
                                                    this: materials,
                                                    a2: dispData.m_nDispStartVert.m_Memory.m_nGrowSize,
                                                    a3: dispData.m_dispVerts.m_pElements,
                                                    a4: 0,
                                                    a5: 0,
                                                    a6: 2);
  materials->EndRenderTargetAllocation(this: materials);
  RenderToAtlasedTexture(
    pRenderContext: v5,
    nAtlasedTextureWidth: m_nGrowSize,
    packedSurfaces: (const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *)&dispData.m_nDispStartVert.m_pElements,
    pRenderTarget: (ITexture *)dispData.m_dispVerts.m_pElements,
    nAtlasedTextureHeight: (int)m_pElements,
    pMaterialSrcDir: &mapPath[224],
    pTextureBaseName: "simpleworldmodel",
    renderMode: RENDER_TO_ATLASED_TEXTURE_FULL_RENDERING,
    dispData: (const CDisplacementData *)&mapName[224],
    flToneMapScale: 4.0);
  RenderToAtlasedTexture(
    pRenderContext: v5,
    nAtlasedTextureWidth: m_nGrowSize,
    packedSurfaces: (const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *)&dispData.m_nDispStartVert.m_pElements,
    pRenderTarget: (ITexture *)dispData.m_dispVerts.m_pElements,
    nAtlasedTextureHeight: (int)m_pElements,
    pMaterialSrcDir: &mapPath[224],
    pTextureBaseName: "simpleworldmodel_lightmap",
    renderMode: RENDER_TO_ATLASED_TEXTURE_LIGHTING_ONLY,
    dispData: (const CDisplacementData *)&mapName[224],
    flToneMapScale: 1.0);
  RenderToAtlasedTexture(
    pRenderContext: v5,
    nAtlasedTextureWidth: m_nGrowSize,
    packedSurfaces: (const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *)&dispData.m_nDispStartVert.m_pElements,
    pRenderTarget: (ITexture *)dispData.m_dispVerts.m_pElements,
    nAtlasedTextureHeight: (int)m_pElements,
    pMaterialSrcDir: &mapPath[224],
    pTextureBaseName: "simpleworldmodel_albedo",
    renderMode: RENDER_TO_ATLASED_TEXTURE_NO_LIGHTING,
    dispData: (const CDisplacementData *)&mapName[224],
    flToneMapScale: 1.0);
  dispData.m_dispVerts.m_pElements = (CDispVert *)WriteSMD(
                                                    packedSurfaces: (const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *)&dispData.m_nDispStartVert.m_pElements,
                                                    a2: m_nGrowSize,
                                                    a3: (int)m_pElements,
                                                    nAtlasedTextureWidth: m_nGrowSize,
                                                    nAtlasedTextureHeight: (int)m_pElements,
                                                    pModelSrcDir: &materialSrcDir[224],
                                                    bWater: true);
  v8 = WriteSMD(
         packedSurfaces: (const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *)&dispData.m_nDispStartVert.m_pElements,
         a2: m_nGrowSize,
         a3: (int)m_pElements,
         nAtlasedTextureWidth: m_nGrowSize,
         nAtlasedTextureHeight: (int)m_pElements,
         pModelSrcDir: &materialSrcDir[224],
         bWater: false);
  Host_AllowQueuedMaterialSystem(bAllow: dispData.m_nDispStartVert.m_Size);
  if ( (int)dispData.m_dispVerts.m_pElements > 0 )
    CreateAndCompileQCFile(mapName: &gameDir[224], bWater: true, a3: v8, pModelSrcDir: &materialSrcDir[224]);
  if ( v8 > 0 )
    CreateAndCompileQCFile(mapName: &gameDir[224], bWater: false, a3: v8, pModelSrcDir: &materialSrcDir[224]);
  LoadBSPPackInterface();
  V_snprintf(pDest: &matDir[224], maxLen: 260, pFormat: "maps/%s.bsp", &gameDir[224]);
  v11 = g_pFileSystem;
  ((void (__thiscall *)(IBSPPack *))s_pBSPPack->LoadBSPFile)(a1: s_pBSPPack);
  if ( v8 <= 0 )
  {
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel.mdl",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel.dx90.vtx",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel.vvd",
      gameDir: &modelSrcDir[224]);
  }
  else
  {
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel.mdl",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel.dx90.vtx",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel.vvd",
      gameDir: &modelSrcDir[224]);
  }
  v9 = dispData.m_dispVerts.m_pElements;
  if ( (int)dispData.m_dispVerts.m_pElements <= 0 )
  {
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel_water.mdl",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel_water.dx90.vtx",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel_water.vvd",
      gameDir: &modelSrcDir[224]);
  }
  else
  {
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel_water.mdl",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel_water.dx90.vtx",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "models/maps/%s/simpleworldmodel_water.vvd",
      gameDir: &modelSrcDir[224]);
  }
  if ( (int)v9 > 0 || v8 > 0 )
  {
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel.vmt",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel.pwl.vtf",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel.vtf",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel_albedo.pwl.vtf",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel_albedo.vtf",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel_lightmap.pwl.vtf",
      gameDir: &modelSrcDir[224]);
    AddFileToPackAndDeleteFile(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel_lightmap.vtf",
      gameDir: &modelSrcDir[224]);
  }
  else
  {
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel.vmt",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel.pwl.vtf",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel.vtf",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel_albedo.pwl.vtf",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel_albedo.vtf",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel_lightmap.pwl.vtf",
      gameDir: &modelSrcDir[224]);
    RemoveFileFromPack(
      mapName: &gameDir[224],
      pFormatString: "materials/models/maps/%s/simpleworldmodel_lightmap.vtf",
      gameDir: &modelSrcDir[224]);
  }
  ((void (__thiscall *)(IBSPPack *))s_pBSPPack->WriteBSPFile)(a1: s_pBSPPack);
  RemoveContentFile(mapName: &gameDir[224], pFormatString: "models/maps/%s/simpleworldmodel.qc");
  RemoveContentFile(mapName: &gameDir[224], pFormatString: "models/maps/%s/simpleworldmodel.smd");
  RemoveContentFile(mapName: &gameDir[224], pFormatString: "models/maps/%s/simpleworldmodel_water.qc");
  RemoveContentFile(mapName: &gameDir[224], pFormatString: "models/maps/%s/simpleworldmodel_water.smd");
  FileSystem_UnloadModule(pModule: s_pBSPPackModule);
  s_pBSPPack = nullptr;
  s_pBSPPackModule = nullptr;
  _Warning(
    a1: "*****************It is recommended to quit the game after running buildmodelforworld!  Leaks rendertargets!****************\n");
  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&r_buildingmapforworld.IConVar,
    value: 0,
    a2: (unsigned int)&matDir[224],
    a3: (int)v11);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dispData.m_nDispStartVert.m_pElements);
  m_nAllocationCount = dispData.m_nDispStartVert.m_Memory.m_nAllocationCount;
  if ( dispData.m_nDispStartVert.m_Memory.m_nAllocationCount != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)dispData.m_nDispStartVert.m_Memory.m_nAllocationCount + 12))(a1: dispData.m_nDispStartVert.m_Memory.m_nAllocationCount);
    (*(void (__thiscall **)(int))(*(_DWORD *)m_nAllocationCount + 4))(a1: m_nAllocationCount);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&mapName[244]);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&mapName[224]);
}

//------------------------------------------------------------------------------
// Address: 0x10312960
// Name: _dynamic_initializer_for__buildmodelforworld_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__buildmodelforworld_command__()
{
  ConCommand::ConCommand(
    this: &buildmodelforworld_command,
    pName: "buildmodelforworld",
    callback: (void (__cdecl *)())buildmodelforworld,
    pHelpString: "buildmodelforworld",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__buildmodelforworld_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103222F0
// Name: _dynamic_atexit_destructor_for__buildmodelforworld_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__buildmodelforworld_command__()
{
  ConCommand::~ConCommand(this: &buildmodelforworld_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10063CB0
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int,int,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(
        CMeshBuilder *this,
        IMesh *pMesh,
        MaterialPrimitiveType_t type,
        int nVertexCount,
        int nIndexCount,
        MeshBuffersAllocationSettings_t *pMeshSettings)
{
  this->m_Type = type;
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->SetPrimitiveType(this: pMesh, a2: type);
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: nVertexCount, a3: nIndexCount, a4: this, a5: pMeshSettings);
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: nVertexCount, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1006A8D0
// Name: void Vector2DAdd(class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DAdd(const Vector2D *a, const Vector2D *b, Vector2D *c)
{
  c->x = a->x + b->x;
  c->y = a->y + b->y;
}

//------------------------------------------------------------------------------
// Address: 0x1006A900
// Name: void Vector2DMultiply(class Vector2D const __near &,float,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DMultiply(const Vector2D *a, float b, Vector2D *c)
{
  c->x = a->x * b;
  c->y = a->y * b;
}

//------------------------------------------------------------------------------
// Address: 0x1006A930
// Name: LoadBSPPackInterface
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *LoadBSPPackInterface()
{
  struct CSysModule *result; // eax

  result = FileSystem_LoadModule(path: "bsppack");
  s_pBSPPackModule = result;
  if ( result != nullptr )
  {
    result = (struct CSysModule *)Sys_GetFactory(pModule: result);
    if ( result != nullptr )
    {
      result = (struct CSysModule *)((int (__cdecl *)(const char *, _DWORD))result)(a1: "IBSPPACK003", a2: 0);
      s_pBSPPack = (IBSPPack *)result;
    }
  }
  if ( s_pBSPPack == nullptr )
    return (struct CSysModule *)_Error(a1: "can't get bsppack interface\n");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006A980
// Name: ComputeMapName
// Source: json
//------------------------------------------------------------------------------
char __usercall ComputeMapName@<al>(char *pMapName@<edi>, int nMapNameSize@<ebx>)
{
  IClientEntity *v2; // eax
  IClientRenderable *v3; // esi
  const model_t *v4; // eax
  const char *v5; // esi

  v2 = entitylist->GetClientEntity(this: entitylist, a2: 0);
  if ( v2 == nullptr )
    return 0;
  v3 = &v2->IClientRenderable;
  if ( v2->GetModel(this: &v2->IClientRenderable) == nullptr )
    return 0;
  v4 = v3->GetModel(this: v3);
  v5 = modelloader->GetName(this: modelloader, a2: v4);
  if ( V_stristr(pStr: v5, pSearch: "maps/") == v5 || V_stristr(pStr: v5, pSearch: "maps\\") == v5 )
  {
    V_strncpy(pDest: pMapName, pSrc: v5 + 5, maxLen: nMapNameSize);
    V_StripExtension(in: pMapName, out: pMapName, outSize: nMapNameSize);
    return 1;
  }
  else
  {
    V_FileBase(in: v5, out: pMapName, maxlen: nMapNameSize);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AA10
// Name: ComputeAndMakeDirectories
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeAndMakeDirectories(
        const char *pMapName@<esi>,
        int nMatDirSize@<eax>,
        char *pModelDir@<ebx>,
        char *pModelSrcDir@<edi>,
        char *pMatDir,
        char *pMaterialSrcDir,
        unsigned int nMaterialSrcDirSize,
        unsigned int nModelDirSize,
        unsigned int nModelSrcDirSize)
{
  const char *v9; // [esp+0h] [ebp-108h]
  char pTemp[260]; // [esp+4h] [ebp-104h] BYREF

  V_snprintf(pDest: pMatDir, maxLen: nMatDirSize, pFormat: "materials/models/maps/%s", v9);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pMatDir, a3: "DEFAULT_WRITE_PATH");
  V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "materialsrc/models/maps/%s", pMapName);
  GetModContentSubdirectory(pSubDir: pTemp, pBuf: pMaterialSrcDir, nBufLen: nMaterialSrcDirSize);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pMaterialSrcDir, a3: nullptr);
  V_snprintf(pDest: pModelDir, maxLen: nModelDirSize, pFormat: "models/maps//%s", pMapName);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pModelDir, a3: "DEFAULT_WRITE_PATH");
  V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "models/maps/%s", pMapName);
  GetModContentSubdirectory(pSubDir: pTemp, pBuf: pModelSrcDir, nBufLen: nModelSrcDirSize);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pModelSrcDir, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1006AAF0
// Name: CreateSimpleWorldModelVMT
// Source: json
//------------------------------------------------------------------------------
char __usercall CreateSimpleWorldModelVMT@<al>(const char *pMaterialDir@<eax>, const char *mapName@<edi>)
{
  void *v2; // eax
  void *v3; // esi
  char vmtPath[260]; // [esp+4h] [ebp-104h] BYREF

  V_strncpy(pDest: vmtPath, pSrc: pMaterialDir, maxLen: 260);
  V_strncat(pDest: vmtPath, pSrc: "/simpleworldmodel.vmt", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v2 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: vmtPath, a3: "w", a4: 0);
  v3 = v2;
  if ( v2 != nullptr )
  {
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v2, a3: "\"patch\"\n");
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "{\n");
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: v3,
      a3: "\t\"include\" \"materials/engine/simpleworldmodel.vmt\"\n");
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "\t\"insert\"\n");
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "\t{\n");
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: v3,
      a3: "\t\t\"$basetexture\" \"models/maps/%s/simpleworldmodel\"\n",
      mapName);
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: v3,
      a3: "\t\t\"$albedo\" \"models/maps/%s/simpleworldmodel_albedo\"\n",
      mapName);
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: v3,
      a3: "\t\t\"$lightmap\" \"models/maps/%s/simpleworldmodel_lightmap\"\n",
      mapName);
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "\t}\n");
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v3, a3: "}\n");
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3);
    return 1;
  }
  else
  {
    _Warning(a1: "can't create %s\n", vmtPath);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AC50
// Name: CompileQC
// Source: json
//------------------------------------------------------------------------------
void __usercall CompileQC(const char *pFileName@<esi>)
{
  const char *v1; // [esp+0h] [ebp-30Ch]
  char cmdline[776]; // [esp+4h] [ebp-308h] BYREF

  V_snprintf(pDest: cmdline, maxLen: 776, pFormat: "studiomdl.exe -nop4 %s", v1);
  if ( g_pProcessUtils->SimpleRunProcess(this: g_pProcessUtils, a2: cmdline, a3: nullptr, a4: nullptr) == -1 )
    _Msg(a1: "Failed compiling %s\n", pFileName);
  else
    _Msg(a1: "Compilation of \"%s\" succeeded\n", pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1006ACC0
// Name: CreateAndCompileQCFile
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateAndCompileQCFile(
        const char *mapName@<edi>,
        bool bWater@<bl>,
        int a3@<esi>,
        const char *pModelSrcDir)
{
  const char *v4; // eax
  void *v5; // esi
  const char *v6; // ecx
  const char *v7; // ecx
  const char *v8; // ecx
  char qcPath[260]; // [esp+0h] [ebp-104h] BYREF

  v4 = "_water";
  if ( !bWater )
    v4 = defaultValue;
  V_snprintf(pDest: qcPath, maxLen: 260, pFormat: "%s/simpleworldmodel%s.qc", pModelSrcDir, v4);
  v5 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, _DWORD, int))g_pFileSystem->Open)(
                 a1: &g_pFileSystem->IBaseFileSystem,
                 a2: qcPath,
                 a3: "w",
                 a4: 0,
                 a5: a3);
  if ( v5 != nullptr )
  {
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "// -- generated by buildmodelforworld --\n", mapName);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$cdmaterials \"models/maps/%s\"\n", mapName);
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$scale 1.0\n");
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$surfaceprop \"default\"\n");
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$staticprop\n");
    v6 = "_water";
    if ( !bWater )
      v6 = defaultValue;
    g_pFileSystem->FPrintf(
      this: g_pFileSystem,
      a2: v5,
      a3: "$modelname \"maps/%s/simpleworldmodel%s.mdl\"\n",
      mapName,
      v6);
    v7 = "_water";
    if ( !bWater )
      v7 = defaultValue;
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "$body \"Body\" \"simpleworldmodel%s.smd\"\n", v7);
    v8 = "_water";
    if ( !bWater )
      v8 = defaultValue;
    g_pFileSystem->FPrintf(
      this: g_pFileSystem,
      a2: v5,
      a3: "$sequence \"idle\" \"simpleworldmodel%s.smd\" fps 30\n",
      v8);
    ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: &g_pFileSystem->IBaseFileSystem);
    CompileQC(pFileName: qcPath);
  }
  else
  {
    _Warning(a1: "can't create qc file %s\n", qcPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AE30
// Name: AddFileToPackAndDeleteFile
// Source: json
//------------------------------------------------------------------------------
void __usercall AddFileToPackAndDeleteFile(
        const char *mapName@<eax>,
        const char *pFormatString@<ecx>,
        const char *gameDir)
{
  char fullPath[260]; // [esp+0h] [ebp-208h] BYREF
  char relativePath[260]; // [esp+104h] [ebp-104h] BYREF

  V_snprintf(pDest: relativePath, maxLen: 260, pFormat: pFormatString, mapName);
  V_snprintf(pDest: fullPath, maxLen: 260, pFormat: "%s/%s", gameDir, relativePath);
  s_pBSPPack->AddFileToPack(this: s_pBSPPack, a2: relativePath, a3: fullPath);
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: fullPath, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1006AEB0
// Name: RemoveFileFromPack
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveFileFromPack(const char *mapName@<eax>, const char *pFormatString@<ecx>, const char *gameDir)
{
  char fullPath[260]; // [esp+0h] [ebp-208h] BYREF
  char relativePath[260]; // [esp+104h] [ebp-104h] BYREF

  V_snprintf(pDest: relativePath, maxLen: 260, pFormat: pFormatString, mapName);
  V_snprintf(pDest: fullPath, maxLen: 260, pFormat: "%s/%s", gameDir, relativePath);
  s_pBSPPack->RemoveFileFromPack(this: s_pBSPPack, a2: relativePath);
}

//------------------------------------------------------------------------------
// Address: 0x1006AF10
// Name: RemoveContentFile
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveContentFile(const char *mapName@<eax>, const char *pFormatString@<ecx>)
{
  char absolutePath[260]; // [esp+0h] [ebp-208h] BYREF
  char pTemp[260]; // [esp+104h] [ebp-104h] BYREF

  V_snprintf(pDest: pTemp, maxLen: 260, pFormat: pFormatString, mapName);
  GetModContentSubdirectory(pSubDir: pTemp, pBuf: absolutePath, nBufLen: 260);
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: absolutePath, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1006AF70
// Name: WriteSMDHeader
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteSMDHeader(void *smdfp@<esi>)
{
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "version 1\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "nodes\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "0 \"polymsh_extracted2\" -1\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "end\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "skeleton\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "time 0\n");
  g_pFullFileSystem->FPrintf(
    this: g_pFullFileSystem,
    a2: smdfp,
    a3: "0 0.000000 0.000000 0.000000 1.570796 0.000000 0.000000\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "end\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "triangles\n");
}

//------------------------------------------------------------------------------
// Address: 0x1006B030
// Name: Push2DRenderingSetup
// Source: json
//------------------------------------------------------------------------------
void __usercall Push2DRenderingSetup(
        IMatRenderContext *pRenderContext@<esi>,
        ITexture *pRenderTarget@<ecx>,
        int nAtlasedTextureWidth,
        int nAtlasedTextureHeight)
{
  double v4; // [esp+40h] [ebp-28h]
  double v5; // [esp+48h] [ebp-20h]
  float nAtlasedTextureWidtha; // [esp+70h] [ebp+8h]
  float nAtlasedTextureHeighta; // [esp+74h] [ebp+Ch]

  pRenderContext->PushRenderTargetAndViewport_3(this: pRenderContext, a2: pRenderTarget);
  pRenderContext->ClearColor4ub(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 255u);
  materials->ClearBuffers(this: materials, a2: true, a3: false, a4: false);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_PROJECTION);
  pRenderContext->PushMatrix(this: pRenderContext);
  pRenderContext->LoadIdentity(this: pRenderContext);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))pRenderContext->Scale)(
    a1: pRenderContext,
    a2: 1.0,
    a3: -1.0,
    a4: 1.0);
  nAtlasedTextureHeighta = (float)nAtlasedTextureHeight;
  nAtlasedTextureWidtha = (float)nAtlasedTextureWidth;
  v5 = (nAtlasedTextureHeighta + 0.5) * (float)(1.0 / nAtlasedTextureHeighta);
  v4 = (nAtlasedTextureWidtha + 0.5) * (float)(1.0 / nAtlasedTextureWidtha);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pRenderContext->Ortho)(
    a1: pRenderContext,
    a2: COERCE_UNSIGNED_INT64((float)(1.0 / nAtlasedTextureWidtha) * 0.5),
    a3: HIDWORD(COERCE_UNSIGNED_INT64((float)(1.0 / nAtlasedTextureWidtha) * 0.5)),
    a4: COERCE_UNSIGNED_INT64((float)(1.0 / nAtlasedTextureHeighta) * 0.5),
    a5: HIDWORD(COERCE_UNSIGNED_INT64((float)(1.0 / nAtlasedTextureHeighta) * 0.5)),
    a6: LODWORD(v4),
    a7: HIDWORD(v4),
    a8: LODWORD(v5),
    a9: HIDWORD(v5),
    a10: COERCE_UNSIGNED_INT64(-99999.0),
    a11: HIDWORD(COERCE_UNSIGNED_INT64(-99999.0)),
    a12: COERCE_UNSIGNED_INT64(99999.0),
    a13: HIDWORD(COERCE_UNSIGNED_INT64(99999.0)));
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_VIEW);
  pRenderContext->PushMatrix(this: pRenderContext);
  pRenderContext->LoadIdentity(this: pRenderContext);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PushMatrix(this: pRenderContext);
  pRenderContext->LoadIdentity(this: pRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x1006B180
// Name: private: void CMeshBuilder::ComputeNumVertsAndIndices(int __near *,int __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::ComputeNumVertsAndIndices(
        CMeshBuilder *this,
        int *pMaxVertices,
        int *pMaxIndices,
        MaterialPrimitiveType_t type,
        int nPrimitiveCount)
{
  switch ( type )
  {
    case MATERIAL_POINTS:
      *pMaxIndices = nPrimitiveCount;
      *pMaxVertices = nPrimitiveCount;
      break;
    case MATERIAL_LINES:
      *pMaxIndices = 2 * nPrimitiveCount;
      *pMaxVertices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLES:
      *pMaxIndices = 3 * nPrimitiveCount;
      *pMaxVertices = 3 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLE_STRIP:
      *pMaxIndices = nPrimitiveCount + 2;
      *pMaxVertices = nPrimitiveCount + 2;
      break;
    case MATERIAL_LINE_STRIP:
      *pMaxVertices = nPrimitiveCount + 1;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_LINE_LOOP:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_POLYGON:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 3 * nPrimitiveCount - 6;
      break;
    case MATERIAL_QUADS:
      *pMaxVertices = 4 * nPrimitiveCount;
      *pMaxIndices = 6 * nPrimitiveCount;
      break;
    case MATERIAL_INSTANCED_QUADS:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 0;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B280
// Name: SurfComputeAtlasedTextureCoordinate
// Source: json
//------------------------------------------------------------------------------
void __usercall SurfComputeAtlasedTextureCoordinate(
        msurface2_t *surfID@<edx>,
        const Vector *vec@<esi>,
        Vector2D *uv@<eax>,
        const SurfaceCtx_t *ctx)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float v6; // xmm0_4
  float *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm0_4

  if ( (surfID->flags & 1) != 0 )
  {
    uv->y = 0.5;
    uv->x = 0.5;
LABEL_3:
    x = uv->x;
    goto LABEL_4;
  }
  if ( *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) != 0 )
  {
    v7 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
    v8 = (float)((float)((float)(v7[9] * vec->y) + (float)(v7[8] * vec->x)) + (float)(v7[10] * vec->z)) + v7[11];
    uv->x = v8;
    uv->x = (float)(v8
                  - (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
          + 0.5;
    v9 = (float)((float)((float)(v7[13] * vec->y) + (float)(vec->x * v7[12])) + (float)(v7[14] * vec->z)) + v7[15];
    uv->y = v9;
    uv->y = (float)(v9
                  - (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
          + 0.5;
    uv->x = ctx->m_Scale.x * uv->x;
    uv->y = ctx->m_Scale.y * uv->y;
    uv->x = ctx->m_Offset.x + uv->x;
    v6 = ctx->m_Offset.y + uv->y;
  }
  else
  {
    v6 = ctx->m_Offset.y + (float)(ctx->m_Scale.y * 0.5);
    uv->x = ctx->m_Offset.x + (float)(ctx->m_Scale.x * 0.5);
  }
  uv->y = v6;
  if ( uv->x >= 0.0 )
  {
    if ( uv->x <= 1.0 )
      goto LABEL_3;
    x = 1.0;
  }
  else
  {
    x = 0.0;
  }
LABEL_4:
  uv->x = x;
  y = uv->y;
  if ( y >= 0.0 )
  {
    if ( y > 1.0 )
      y = 1.0;
    uv->y = y;
  }
  else
  {
    uv->y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B460
// Name: CalculateLuxelToWorldTransform
// Source: json
//------------------------------------------------------------------------------
void __usercall CalculateLuxelToWorldTransform(
        const Vector *vFaceNormal@<esi>,
        Vector *pLuxelOrigin@<edx>,
        Vector *pS@<ebx>,
        Vector *pT@<edi>,
        const mtexinfo_t *pTexInfo,
        float flFaceDistance)
{
  float v6; // xmm0_4
  float x; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm0_4

  v6 = (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].y)
     - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].z);
  x = pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].x;
  v8 = (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].y)
     - (float)(x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].y);
  v9 = (float)(x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].z)
     - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].z);
  v10 = -(float)((float)((float)(vFaceNormal->y * v9) + (float)(vFaceNormal->x * v6)) + (float)(vFaceNormal->z * v8));
  if ( fabs(v10) >= 0.000001 )
  {
    pS->x = (float)((float)(vFaceNormal->z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].y)
                  - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].z * vFaceNormal->y))
          * (float)(1.0 / v10);
    pT->x = (float)((float)(vFaceNormal->y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].z)
                  - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].y * vFaceNormal->z))
          * (float)(1.0 / v10);
    pLuxelOrigin->x = -(float)((float)(v6 * flFaceDistance) * (float)(1.0 / v10));
    pS->y = (float)((float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].z)
                  - (float)(vFaceNormal->z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].x))
          * (float)(1.0 / v10);
    pT->y = (float)((float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].x * vFaceNormal->z)
                  - (float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].z))
          * (float)(1.0 / v10);
    pLuxelOrigin->y = -(float)((float)(v9 * flFaceDistance) * (float)(1.0 / v10));
    pS->z = (float)((float)(vFaceNormal->y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].x)
                  - (float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].y))
          * (float)(1.0 / v10);
    pT->z = (float)((float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].y)
                  - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].x * vFaceNormal->y))
          * (float)(1.0 / v10);
    pLuxelOrigin->z = -(float)((float)(v8 * flFaceDistance) * (float)(1.0 / v10));
    v11 = -pTexInfo->lightmapVecsLuxelsPerWorldUnits[0].w;
    pLuxelOrigin->x = (float)(pS->x * v11) + pLuxelOrigin->x;
    pLuxelOrigin->y = (float)(pS->y * v11) + pLuxelOrigin->y;
    pLuxelOrigin->z = (float)(pS->z * v11) + pLuxelOrigin->z;
    v12 = -pTexInfo->lightmapVecsLuxelsPerWorldUnits[1].w;
    pLuxelOrigin->x = (float)(v12 * pT->x) + pLuxelOrigin->x;
    pLuxelOrigin->y = (float)(pT->y * v12) + pLuxelOrigin->y;
    pLuxelOrigin->z = (float)(v12 * pT->z) + pLuxelOrigin->z;
  }
  else
  {
    *pLuxelOrigin = vec3_origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B780
// Name: LuxelSpaceToWorld
// Source: json
//------------------------------------------------------------------------------
void __usercall LuxelSpaceToWorld(msurface2_t *surfID@<eax>, Vector *worldPosition@<esi>, float u, float v)
{
  float y; // xmm6_4
  float x; // xmm4_4
  float z; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  int v21; // edx
  Vector tVect; // [esp+4h] [ebp-24h] BYREF
  Vector sVect; // [esp+10h] [ebp-18h] BYREF
  Vector luxelBasePosition; // [esp+1Ch] [ebp-Ch] BYREF

  R_ComputeSurfaceBasis(surfID, &luxelBasePosition, &sVect, &tVect);
  y = luxelBasePosition.y;
  x = luxelBasePosition.x;
  z = luxelBasePosition.z;
  v8 = sVect.x;
  v9 = sVect.y;
  v10 = sVect.z;
  worldPosition->y = luxelBasePosition.y;
  worldPosition->x = x;
  worldPosition->z = z;
  v11 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v12 = (float)((float)(v9 * u) * v11) + y;
  v13 = (float)((float)(v8 * u) * v11) + x;
  v14 = v11 * (float)(v10 * u);
  v15 = tVect.z;
  v16 = v13;
  v17 = tVect.x;
  v18 = v12;
  v19 = tVect.y;
  worldPosition->x = v16;
  worldPosition->y = v18;
  v20 = v14 + z;
  worldPosition->z = v20;
  v21 = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                   + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  worldPosition->x = v16 + (float)((float)(v17 * v) * (float)v21);
  worldPosition->y = v18 + (float)((float)(v19 * v) * (float)v21);
  worldPosition->z = v20 + (float)((float)(v15 * v) * (float)v21);
}

//------------------------------------------------------------------------------
// Address: 0x1006B890
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(CMeshBuilder *this, IMesh *pMesh, int type, int numPrimitives)
{
  MaterialPrimitiveType_t v4; // ebx
  IMesh *v5; // edi
  MaterialPrimitiveType_t v7; // ebx
  IMesh *v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]

  v4 = type;
  v5 = pMesh;
  pMesh = nullptr;
  type = 0;
  v9 = numPrimitives;
  this->m_pMesh = v5;
  this->m_bGenerateIndices = true;
  this->m_Type = v4;
  CMeshBuilder::ComputeNumVertsAndIndices(
    this,
    pMaxVertices: (int *)&pMesh,
    pMaxIndices: &type,
    type: v4,
    nPrimitiveCount: v9);
  switch ( v4 )
  {
    case MATERIAL_LINE_STRIP:
    case MATERIAL_LINE_LOOP:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
      break;
    case MATERIAL_POLYGON:
    case MATERIAL_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
      break;
    case MATERIAL_INSTANCED_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_INSTANCED_QUADS);
      break;
    default:
      v5->SetPrimitiveType(this: v5, a2: v4);
      break;
  }
  v7 = type;
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: (int)pMesh, a3: type, a4: this, a5: nullptr);
  this->m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = v7;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  v8 = pMesh;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh: v5, nMaxVertexCount: (int)v8, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1006B9A0
// Name: void DrawTexturedQuad(class IMaterial __near *,class IMatRenderContext __near *,struct msurface2_t __near *,struct surfacerect_t const __near &,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawTexturedQuad(
        IMaterial *pMaterial,
        IMatRenderContext *pRenderContext,
        msurface2_t *surfID,
        const surfacerect_t *rect,
        const Vector4D *vColor)
{
  IMesh *v5; // esi
  const surfacerect_t *v6; // ecx
  Vector2D *m_LMCoords; // ebx
  float *p_y; // esi
  float *m_pCurrPosition; // eax
  float *v10; // eax
  float *v11; // eax
  float *m_pCurrNormal; // eax
  int m_nVertexCount; // eax
  CMeshBuilder builder; // [esp+Ch] [ebp-200h] BYREF
  Vector2D texCoord; // [esp+1F4h] [ebp-18h] BYREF
  float v16; // [esp+1FCh] [ebp-10h]
  float v17; // [esp+200h] [ebp-Ch]
  float v18; // [esp+204h] [ebp-8h]
  float v19; // [esp+208h] [ebp-4h]
  int vertID; // [esp+218h] [ebp+Ch]

  v5 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: pMaterial);
  CMeshBuilder::CMeshBuilder(this: &builder);
  builder.m_pMesh = v5;
  builder.m_bGenerateIndices = true;
  builder.m_Type = MATERIAL_POLYGON;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
  builder.m_pMesh->LockMesh(this: builder.m_pMesh, a2: 4, a3: 6, a4: &builder, a5: nullptr);
  builder.m_IndexBuilder.m_nIndexOffset = builder.m_nFirstVertex;
  builder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  builder.m_IndexBuilder.m_nIndexCount = 0;
  builder.m_IndexBuilder.m_nMaxIndexCount = 6;
  builder.m_IndexBuilder.m_bModify = false;
  builder.m_IndexBuilder.m_pIndices = builder.m_pIndices;
  builder.m_IndexBuilder.m_nIndexSize = builder.m_nIndexSize;
  builder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &builder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 4, desc: &builder);
  builder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &builder.m_VertexBuilder);
  v6 = rect;
  vertID = 0;
  m_LMCoords = rect->m_LMCoords;
  p_y = &rect->m_vPos[0].y;
  while ( 1 )
  {
    SurfComputeTextureCoordinate(
      surfID,
      vec: &v6->m_vPosWorld[(vertID + v6->m_nTexCoordIndexOffset) % 4],
      pUV: &texCoord.x);
    m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
    *builder.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
    m_pCurrPosition[1] = *p_y;
    m_pCurrPosition[2] = p_y[1];
    v18 = (float)(vColor->z * 255.0) + 8388608.0;
    v19 = (float)(vColor->y * 255.0) + 8388608.0;
    v17 = (float)(vColor->x * 255.0) + 8388608.0;
    v16 = (float)(vColor->w * 255.0) + 8388608.0;
    *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = LOBYTE(v18)
                                                    | ((LOBYTE(v19) | ((LOBYTE(v17) | (LOBYTE(v16) << 8)) << 8)) << 8);
    *(Vector2D *)builder.m_VertexBuilder.m_pCurrTexCoord[0] = texCoord;
    v10 = builder.m_VertexBuilder.m_pCurrTexCoord[1];
    *builder.m_VertexBuilder.m_pCurrTexCoord[1] = m_LMCoords->x;
    v10[1] = m_LMCoords->y;
    v11 = builder.m_VertexBuilder.m_pCurrTexCoord[2];
    if ( (surfID->flags & 8) != 0 )
      *builder.m_VertexBuilder.m_pCurrTexCoord[2] = rect->m_flBumpSTexCoordOffset;
    else
      *builder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
    v11[1] = 0.0;
    m_pCurrNormal = builder.m_VertexBuilder.m_pCurrNormal;
    *builder.m_VertexBuilder.m_pCurrNormal = 0.0;
    m_pCurrNormal[1] = 0.0;
    m_pCurrNormal[2] = 1.0;
    CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
    ++m_LMCoords;
    p_y += 3;
    if ( ++vertID >= 4 )
      break;
    v6 = rect;
  }
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  builder.m_pMesh->UnlockMesh(
    this: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount,
    a4: &builder);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
  builder.m_pMesh = nullptr;
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BCF0
// Name: void WriteDisplacementSurfaceToSMD(struct msurface2_t __near *,class CDispInfo __near *,struct SurfaceCtx_t const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteDisplacementSurfaceToSMD(
        msurface2_t *surfID,
        CDispInfo *pDispInfo,
        const SurfaceCtx_t *ctxAtlased,
        void *smdfp)
{
  IMaterialSystem_vtbl *v4; // edi
  int v5; // eax
  msurfacelighting_t *surfacelighting; // eax
  unsigned int v8; // esi
  bool v9; // cc
  float v10; // xmm0_4
  int v11; // ebx
  CDispRenderVert *v12; // eax
  float vOffset; // [esp+78h] [ebp-1Ch]
  int nLightmapPageSize[2]; // [esp+80h] [ebp-14h] BYREF
  float flPageSizeV; // [esp+88h] [ebp-Ch]
  float flPageSizeU; // [esp+8Ch] [ebp-8h]
  int i; // [esp+90h] [ebp-4h]
  msurface2_t *surfIDa; // [esp+9Ch] [ebp+8h]
  int pDispInfoa; // [esp+A0h] [ebp+Ch]

  v4 = materials->__vftable;
  v5 = SortInfoToLightmapPage(sortID: surfID->materialSortID);
  v4->GetLightmapPageSize(this: materials, a2: v5, a3: nLightmapPageSize, a4: &nLightmapPageSize[1]);
  surfacelighting = host_state.worldbrush->surfacelighting;
  v8 = ((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
  v9 = pDispInfo->m_nIndices <= 0;
  vOffset = (float)*(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v8) / (float)nLightmapPageSize[0];
  v10 = (float)*(__int16 *)((char *)&surfacelighting->m_OffsetIntoLightmapPage[1] + v8) / (float)nLightmapPageSize[1];
  flPageSizeU = (float)nLightmapPageSize[0];
  flPageSizeV = (float)nLightmapPageSize[1];
  i = 0;
  if ( !v9 )
  {
    pDispInfoa = 4;
    do
    {
      g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "simpleworldmodel.tga\n");
      v11 = 2;
      surfIDa = (msurface2_t *)pDispInfoa;
      do
      {
        v12 = &pDispInfo->m_Verts.m_Memory.m_pMemory[*(unsigned __int16 *)((char *)pDispInfo->m_Indices.m_Memory.m_pMemory
                                                                         + (unsigned int)surfIDa)
                                                   - pDispInfo->m_iVertOffset];
        g_pFullFileSystem->FPrintf(
          this: g_pFullFileSystem,
          a2: smdfp,
          a3: "%d %f %f %f %f %f %f %f %f\n",
          0,
          v12->m_vPos.x,
          v12->m_vPos.y,
          v12->m_vPos.z,
          v12->m_vNormal.x,
          v12->m_vNormal.y,
          v12->m_vNormal.z,
          (float)((float)(ctxAtlased->m_Scale.x * (float)((float)(v12->m_LMCoords.x - vOffset) * flPageSizeU))
                + ctxAtlased->m_Offset.x),
          1.0
        - (float)((float)((float)((float)(v12->m_LMCoords.y - v10) * flPageSizeV) * ctxAtlased->m_Scale.y)
                + ctxAtlased->m_Offset.y));
        surfIDa = (msurface2_t *)((char *)surfIDa - 2);
        --v11;
      }
      while ( v11 >= 0 );
      pDispInfoa += 6;
      i += 3;
    }
    while ( i < pDispInfo->m_nIndices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BED0
// Name: void WriteSurfaceToSMD(struct worldbrushdata_t __near *,struct msurface2_t __near *,int,int,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteSurfaceToSMD(
        worldbrushdata_t *pBrushData,
        int surfID,
        int x,
        int y,
        void *smdfp,
        int nAtlasedTextureWidth,
        int nAtlasedTextureHeight)
{
  char *v8; // eax
  int v9; // esi
  int v10; // eax
  CDispInfo *v11; // eax
  int v12; // esi
  int v13; // esi
  mvertex_t *v14; // esi
  Vector *v15; // eax
  SurfaceCtx_t ctxAtlased; // [esp+4Ch] [ebp-2Ch] BYREF
  Vector2D pos; // [esp+70h] [ebp-8h] BYREF
  int triVertID; // [esp+84h] [ebp+Ch]
  int xa; // [esp+88h] [ebp+10h]
  int i; // [esp+94h] [ebp+1Ch]
  int triID; // [esp+98h] [ebp+20h]

  v8 = (char *)host_state.worldbrush->surfacelighting
     + ((surfID - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
  v9 = *((__int16 *)v8 + 2);
  v10 = *((__int16 *)v8 + 3) + 1;
  ctxAtlased.m_Scale.x = 1.0 / (float)nAtlasedTextureWidth;
  ctxAtlased.m_LightmapSize[1] = v10;
  v11 = *(CDispInfo **)(surfID + 24);
  ctxAtlased.m_Scale.y = 1.0 / (float)nAtlasedTextureHeight;
  ctxAtlased.m_LightmapPageSize[0] = nAtlasedTextureWidth;
  ctxAtlased.m_LightmapPageSize[1] = nAtlasedTextureHeight;
  ctxAtlased.m_LightmapSize[0] = v9 + 1;
  ctxAtlased.m_Offset.x = (float)x * ctxAtlased.m_Scale.x;
  ctxAtlased.m_Offset.y = (float)y * ctxAtlased.m_Scale.y;
  ctxAtlased.m_BumpSTexCoordOffset = 0.0;
  if ( v11 != nullptr )
  {
    WriteDisplacementSurfaceToSMD((msurface2_t *)surfID, pDispInfo: v11, &ctxAtlased, smdfp);
  }
  else
  {
    v12 = 0;
    triID = 0;
    xa = *(unsigned __int8 *)(surfID + 3) - 2;
    if ( xa > 0 )
    {
      while ( 1 )
      {
        g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: smdfp, a3: "simpleworldmodel.tga\n");
        triVertID = 2;
        while ( 1 )
        {
          if ( triVertID != 0 )
          {
            v13 = triVertID == 1 ? v12 + 1 : v12 + 2;
            i = v13;
          }
          else
          {
            i = 0;
          }
          v14 = &pBrushData->vertexes[pBrushData->vertindices[i + *(_DWORD *)(surfID + 8)]];
          SurfComputeAtlasedTextureCoordinate((msurface2_t *)surfID, vec: &v14->position, uv: &pos, ctx: &ctxAtlased);
          v15 = &pBrushData->vertnormals[pBrushData->vertnormalindices[i
                                                                     + host_state.worldbrush->surfacenormals[(signed int)(surfID - (unsigned int)host_state.worldbrush->surfaces2) >> 5].firstvertnormal]];
          g_pFullFileSystem->FPrintf(
            this: g_pFullFileSystem,
            a2: smdfp,
            a3: "%d %f %f %f %f %f %f %f %f\n",
            0,
            v14->position.x,
            v14->position.y,
            v14->position.z,
            v15->x,
            v15->y,
            v15->z,
            pos.x,
            1.0 - pos.y);
          if ( --triVertID < 0 )
            break;
          v12 = triID;
        }
        if ( ++triID >= xa )
          break;
        v12 = triID;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C0B0
// Name: void DrawSurfaceRectToAtlasedTexture(float,float,float,float,int,int,struct msurface2_t __near *,enum RenderToAtlasedTextureRenderMode_t,class CDisplacementData const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawSurfaceRectToAtlasedTexture(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        float left,
        float top,
        float right,
        float bottom,
        int nRenderTargetWidth,
        int nRenderTargetHeight,
        msurface2_t *surfID,
        int renderMode,
        const CDisplacementData *dispData)
{
  float v12; // xmm0_4
  float v13; // xmm0_4
  msurfacelighting_t *surfacelighting; // edx
  int v16; // ecx
  char *v17; // eax
  int v18; // edx
  bool v19; // zf
  IMatRenderContext *m_pObject; // ebx
  IMatRenderContext v21; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm3_4
  float v28; // xmm3_4
  IDispInfo *pDispInfo; // esi
  int v30; // eax
  char *v31; // eax
  int v32; // ecx
  int v33; // edx
  IMatRenderContext v34; // eax
  float v35; // xmm0_4
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  IMesh *v37; // ebx
  char *v38; // eax
  float v39; // xmm0_4
  int v40; // eax
  int v41; // eax
  int v42; // ebx
  float *v43; // eax
  float *m_pCurrPosition; // ecx
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm0_4
  float v48; // xmm4_4
  float v49; // xmm1_4
  float v50; // xmm3_4
  float v51; // xmm4_4
  float v52; // xmm3_4
  float v53; // xmm4_4
  float *v54; // ecx
  float *v55; // ecx
  float *v56; // ecx
  float *v57; // ecx
  float *v58; // eax
  float *v59; // eax
  float *m_pCurrNormal; // eax
  int v61; // eax
  unsigned int m_nCurrentIndex; // ecx
  unsigned __int16 v63; // dx
  int m_nVertexCount; // eax
  Vector tVect; // [esp+20h] [ebp-39Ch] BYREF
  CMeshBuilder builder; // [esp+2Ch] [ebp-390h] BYREF
  Vector2D vLuxel; // [esp+214h] [ebp-1A8h]
  SurfaceCtx_t ctxAtlased; // [esp+21Ch] [ebp-1A0h]
  Vector vPos; // [esp+240h] [ebp-17Ch]
  surfacerect_t surfaceRect; // [esp+24Ch] [ebp-170h] BYREF
  Vector v72; // [esp+2D4h] [ebp-E8h] BYREF
  Vector sVect; // [esp+2E0h] [ebp-DCh] BYREF
  Vector v74; // [esp+2ECh] [ebp-D0h] BYREF
  Vector v75; // [esp+2F8h] [ebp-C4h] BYREF
  Vector v76; // [esp+304h] [ebp-B8h] BYREF
  Vector v77; // [esp+310h] [ebp-ACh] BYREF
  Vector v78; // [esp+31Ch] [ebp-A0h] BYREF
  Vector v79; // [esp+328h] [ebp-94h] BYREF
  Vector luxelBasePosition; // [esp+334h] [ebp-88h] BYREF
  Vector4D vColor; // [esp+340h] [ebp-7Ch] BYREF
  Vector2D vOffset; // [esp+350h] [ebp-6Ch]
  int nLightmapPageSize[2]; // [esp+358h] [ebp-64h] BYREF
  int v84; // [esp+360h] [ebp-5Ch]
  int v85; // [esp+364h] [ebp-58h]
  SurfaceCtx_t ctx; // [esp+368h] [ebp-54h] BYREF
  Vector2D testUV; // [esp+38Ch] [ebp-30h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+394h] [ebp-28h]
  float flLeft; // [esp+398h] [ebp-24h]
  float lightmapBottom; // [esp+39Ch] [ebp-20h]
  float lightmapRight; // [esp+3A0h] [ebp-1Ch]
  float flPageSizeV; // [esp+3A4h] [ebp-18h]
  float flLightmapSizeV; // [esp+3A8h] [ebp-14h]
  float flPageSizeU; // [esp+3ACh] [ebp-10h]
  Vector worldPosition; // [esp+3B0h] [ebp-Ch] BYREF
  float lefta; // [esp+3C4h] [ebp+8h]
  float topa; // [esp+3C8h] [ebp+Ch]
  float righta; // [esp+3CCh] [ebp+10h]
  int rightb; // [esp+3CCh] [ebp+10h]
  float bottoma; // [esp+3D0h] [ebp+14h]
  float bottomb; // [esp+3D0h] [ebp+14h]
  IMaterial *flLightmapSizeU; // [esp+3D4h] [ebp+18h]
  float flLightmapSizeUa; // [esp+3D4h] [ebp+18h]
  float flLightmapSizeUb; // [esp+3D4h] [ebp+18h]
  void (__thiscall **ia)(IMaterialSystem *, int, int *, int *); // [esp+3E0h] [ebp+24h]
  int ib; // [esp+3E0h] [ebp+24h]
  int i; // [esp+3E0h] [ebp+24h]
  Vector2D lightmapLeft; // 0:^3E8.8

  v12 = 1.0 / (float)nRenderTargetWidth;
  lefta = left * v12;
  righta = right * v12;
  v13 = 1.0 / (float)nRenderTargetHeight;
  topa = top * v13;
  bottoma = bottom * v13;
  SurfSetupSurfaceContext(&ctx, surfID);
  surfacelighting = host_state.worldbrush->surfacelighting;
  v16 = (char *)surfID - (char *)host_state.worldbrush->surfaces2;
  ctxAtlased.m_Scale.x = 1.0 / (float)nRenderTargetWidth;
  v17 = (char *)surfacelighting + (v16 & 0xFFFFFFE0);
  v18 = *((__int16 *)v17 + 3);
  ctxAtlased.m_LightmapSize[0] = *((__int16 *)v17 + 2) + 1;
  v19 = (surfID->flags & 0x100) == 0;
  ctxAtlased.m_Offset.y = (float)(int)topa * v13;
  ctxAtlased.m_LightmapPageSize[0] = nRenderTargetWidth;
  ctxAtlased.m_LightmapPageSize[1] = nRenderTargetHeight;
  ctxAtlased.m_LightmapSize[1] = v18 + 1;
  ctxAtlased.m_Scale.y = v13;
  ctxAtlased.m_Offset.x = (float)(int)lefta * ctxAtlased.m_Scale.x;
  ctxAtlased.m_BumpSTexCoordOffset = 0.0;
  if ( !v19 )
    TangentSpaceSurfaceSetup(surfID, &tVect);
  m_pObject = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
                                     a1: materials,
                                     a2,
                                     a3,
                                     a4: a1);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  flLightmapSizeU = materialSortInfoArray[surfID->materialSortID].material;
  m_pObject->Bind(this: m_pObject, a2: flLightmapSizeU, a3: nullptr);
  v21.__vftable = m_pObject->__vftable;
  if ( renderMode == 1 )
  {
    BindLightmapPage = v21.BindLightmapPage;
    if ( (surfID->flags & 8) != 0 )
      BindLightmapPage(this: m_pObject, a2: -2);
    else
      BindLightmapPage(this: m_pObject, a2: -1);
  }
  else
  {
    v21.BindLightmapPage(this: m_pObject, a2: materialSortInfoArray[surfID->materialSortID].lightmapPageID);
  }
  lightmapRight = (float)((float)ctx.m_LightmapSize[0] * ctx.m_Scale.x) + ctx.m_Offset.x;
  lightmapLeft = ctx.m_Offset;
  lightmapBottom = (float)((float)ctx.m_LightmapSize[1] * ctx.m_Scale.y) + ctx.m_Offset.y;
  R_ComputeSurfaceBasis(surfID, &luxelBasePosition, &sVect, tVect: &v75);
  worldPosition = luxelBasePosition;
  v23 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  worldPosition.x = (float)((float)(sVect.x * 0.0) * v23) + luxelBasePosition.x;
  worldPosition.y = (float)((float)(sVect.y * 0.0) * v23) + luxelBasePosition.y;
  worldPosition.z = (float)((float)(sVect.z * 0.0) * v23) + luxelBasePosition.z;
  v24 = (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  worldPosition.x = (float)((float)(v75.x * 0.0) * v24) + worldPosition.x;
  worldPosition.y = (float)((float)(v75.y * 0.0) * v24) + worldPosition.y;
  worldPosition.z = (float)((float)(v75.z * 0.0) * v24) + worldPosition.z;
  SurfComputeLightmapCoordinate(&ctx, surfID, vec: &worldPosition, uv: &testUV);
  flLeft = testUV.x - (float)(ctx.m_Scale.x * 0.5);
  flPageSizeV = testUV.y - (float)(ctx.m_Scale.y * 0.5);
  R_ComputeSurfaceBasis(surfID, luxelBasePosition: &v72, sVect: &v76, tVect: &v74);
  worldPosition = v72;
  v25 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  worldPosition.x = (float)(v76.x * v25) + v72.x;
  worldPosition.y = (float)(v76.y * v25) + v72.y;
  worldPosition.z = (float)(v76.z * v25) + v72.z;
  v26 = (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  worldPosition.x = (float)(v74.x * v26) + worldPosition.x;
  worldPosition.y = (float)(v74.y * v26) + worldPosition.y;
  worldPosition.z = (float)(v74.z * v26) + worldPosition.z;
  SurfComputeLightmapCoordinate(&ctx, surfID, vec: &worldPosition, uv: &testUV);
  flLightmapSizeV = (float)(ctx.m_Scale.x * 0.5) + testUV.x;
  flPageSizeU = (float)(ctx.m_Scale.y * 0.5) + testUV.y;
  surfaceRect.m_flBumpSTexCoordOffset = ctx.m_BumpSTexCoordOffset;
  surfaceRect.m_vPos[0].x = lefta;
  surfaceRect.m_vPos[1].x = lefta;
  surfaceRect.m_nTexCoordIndexOffset = 0;
  surfaceRect.m_vPos[0].y = bottoma;
  surfaceRect.m_vPos[0].z = 0.5;
  surfaceRect.m_vPos[1].y = topa;
  surfaceRect.m_vPos[1].z = 0.5;
  surfaceRect.m_vPos[2].x = righta;
  surfaceRect.m_vPos[2].y = topa;
  surfaceRect.m_vPos[2].z = 0.5;
  surfaceRect.m_vPos[3].x = righta;
  surfaceRect.m_vPos[3].y = bottoma;
  surfaceRect.m_vPos[3].z = 0.5;
  vColor.x = (float)rand() * 0.000030518509;
  vColor.y = (float)rand() * 0.000030518509;
  vColor.z = (float)rand() * 0.000030518509;
  VectorNormalize(vec: (Vector *)&vColor);
  vColor.w = 0.0;
  R_ComputeSurfaceBasis(surfID, luxelBasePosition: &v78, sVect: &v77, tVect: &v79);
  surfaceRect.m_vPosWorld[0] = v78;
  v27 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  surfaceRect.m_vPosWorld[0].x = v78.x + (float)((float)(v77.x * 0.0) * v27);
  surfaceRect.m_vPosWorld[0].y = v78.y + (float)((float)(v77.y * 0.0) * v27);
  surfaceRect.m_vPosWorld[0].z = v78.z + (float)((float)(v77.z * 0.0) * v27);
  v28 = (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                          + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  surfaceRect.m_vPosWorld[0].x = (float)(v79.x * v28) + surfaceRect.m_vPosWorld[0].x;
  surfaceRect.m_vPosWorld[0].y = (float)(v79.y * v28) + surfaceRect.m_vPosWorld[0].y;
  surfaceRect.m_vPosWorld[0].z = (float)(v79.z * v28) + surfaceRect.m_vPosWorld[0].z;
  LuxelSpaceToWorld(surfID, worldPosition: &surfaceRect.m_vPosWorld[1], u: 0.0, v: 0.0);
  LuxelSpaceToWorld(surfID, worldPosition: &surfaceRect.m_vPosWorld[2], u: 1.0, v: 0.0);
  LuxelSpaceToWorld(surfID, worldPosition: &surfaceRect.m_vPosWorld[3], u: 1.0, v: 1.0);
  surfaceRect.m_LMCoords[0].x = (float)(int)(float)((float)(flLeft * (float)ctx.m_LightmapPageSize[0]) + 0.5)
                              * ctx.m_Scale.x;
  surfaceRect.m_LMCoords[0].y = (float)(int)(float)((float)(flPageSizeU * (float)ctx.m_LightmapPageSize[1]) + 0.5)
                              * ctx.m_Scale.y;
  surfaceRect.m_LMCoords[1].x = surfaceRect.m_LMCoords[0].x;
  surfaceRect.m_LMCoords[1].y = (float)(int)(float)((float)(flPageSizeV * (float)ctx.m_LightmapPageSize[1]) + 0.5)
                              * ctx.m_Scale.y;
  surfaceRect.m_LMCoords[2].x = (float)(int)(float)((float)(flLightmapSizeV * (float)ctx.m_LightmapPageSize[0]) + 0.5)
                              * ctx.m_Scale.x;
  surfaceRect.m_LMCoords[2].y = surfaceRect.m_LMCoords[1].y;
  surfaceRect.m_LMCoords[3].x = surfaceRect.m_LMCoords[2].x;
  surfaceRect.m_LMCoords[3].y = surfaceRect.m_LMCoords[0].y;
  DrawTexturedQuad(pMaterial: flLightmapSizeU, pRenderContext: m_pObject, surfID, rect: &surfaceRect, &vColor);
  pDispInfo = surfID->pDispInfo;
  if ( pDispInfo != nullptr && renderMode != 2 )
  {
    ia = &materials->GetLightmapPageSize;
    v30 = SortInfoToLightmapPage(sortID: surfID->materialSortID);
    (*ia)(this: materials, a2: v30, a3: nLightmapPageSize, a4: &nLightmapPageSize[1]);
    v31 = (char *)host_state.worldbrush->surfacelighting
        + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
    v32 = *((__int16 *)v31 + 4);
    v33 = *((__int16 *)v31 + 5);
    v34.__vftable = m_pObject->__vftable;
    vOffset.x = (float)v32 / (float)nLightmapPageSize[0];
    v35 = (float)v33;
    Bind = v34.Bind;
    flPageSizeU = (float)nLightmapPageSize[0];
    flPageSizeV = (float)nLightmapPageSize[1];
    vOffset.y = v35 / (float)nLightmapPageSize[1];
    Bind(this: m_pObject, a2: flLightmapSizeU, a3: nullptr);
    v37 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: flLightmapSizeU);
    v38 = (char *)host_state.worldbrush->surfacelighting
        + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
    flLightmapSizeUa = (float)(*((__int16 *)v38 + 2) + 1);
    v39 = (float)(*((__int16 *)v38 + 3) + 1);
    v40 = (int)pDispInfo[8].__vftable / 3;
    flLightmapSizeV = v39;
    ib = v40;
    CMeshBuilder::CMeshBuilder(this: &builder);
    builder.m_pMesh = v37;
    builder.m_bGenerateIndices = true;
    builder.m_Type = MATERIAL_TRIANGLES;
    ib *= 6;
    v37->SetPrimitiveType(this: v37, a2: MATERIAL_TRIANGLES);
    builder.m_pMesh->LockMesh(this: builder.m_pMesh, a2: ib, a3: ib, a4: &builder, a5: nullptr);
    builder.m_IndexBuilder.m_nIndexCount = 0;
    builder.m_IndexBuilder.m_bModify = false;
    builder.m_IndexBuilder.m_nCurrentIndex = 0;
    builder.m_IndexBuilder.m_nIndexOffset = builder.m_nFirstVertex;
    builder.m_IndexBuilder.m_pIndexBuffer = &v37->IIndexBuffer;
    builder.m_IndexBuilder.m_pIndices = builder.m_pIndices;
    builder.m_IndexBuilder.m_nMaxIndexCount = ib;
    builder.m_IndexBuilder.m_nIndexSize = builder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &builder.m_VertexBuilder, pMesh: v37, nMaxVertexCount: ib, desc: &builder);
    builder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &builder.m_VertexBuilder);
    v41 = dispData->m_nDispStartVert.m_Memory.m_pMemory[DispInfo_ComputeIndex(
                                                          hArray: host_state.worldbrush->hDispInfos,
                                                          pInfo: surfID->pDispInfo)];
    i = 0;
    if ( (int)pDispInfo[68].__vftable > 0 )
    {
      flLightmapSizeUb = flPageSizeU / flLightmapSizeUa;
      flPageSizeU = flPageSizeV / flLightmapSizeV;
      flPageSizeV = righta - lefta;
      bottomb = bottoma - topa;
      vPos.z = 0.5;
      rightb = 0;
      lightmapRight = lightmapRight - lightmapLeft.x;
      lightmapBottom = lightmapBottom - lightmapLeft.y;
      v42 = v41;
      do
      {
        v43 = (float *)((char *)pDispInfo[66].__vftable + rightb);
        m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
        v45 = (float)(v43[15] - vOffset.y) * flPageSizeU;
        v46 = lightmapRight;
        v47 = (float)((float)(dispData->m_dispVerts.m_Memory.m_pMemory[v42].m_flAlpha * 0.0039215689) * 255.0)
            + 8388608.0;
        v48 = (float)(v43[14] - vOffset.x) * flLightmapSizeUb;
        v49 = (float)(v48 * flPageSizeV) + lefta;
        *builder.m_VertexBuilder.m_pCurrPosition = v49;
        v50 = v46 * v48;
        v51 = lightmapBottom;
        v52 = v50 + lightmapLeft.x;
        vPos.x = v49;
        m_pCurrPosition[1] = (float)(bottomb * v45) + topa;
        m_pCurrPosition[2] = 0.5;
        vPos.y = (float)(bottomb * v45) + topa;
        vLuxel.x = v52;
        v53 = (float)(v51 * v45) + lightmapLeft.y;
        vLuxel.y = v53;
        v84 = 1258291455;
        v85 = 1258291455;
        flLeft = 8388863.0;
        flLightmapSizeV = v47;
        *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = (((((LOBYTE(v47) << 8) | 0xFF) << 8) | 0xFF) << 8) | 0xFF;
        v54 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
        *builder.m_VertexBuilder.m_pCurrTexCoord[0] = v43[12];
        v54[1] = v43[13];
        v55 = builder.m_VertexBuilder.m_pCurrTexCoord[1];
        *builder.m_VertexBuilder.m_pCurrTexCoord[1] = v52;
        v55[1] = v53;
        v56 = (float *)((char *)builder.m_VertexBuilder.m_pTangentS
                      + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentS);
        *v56 = v43[6];
        v56[1] = v43[7];
        v56[2] = v43[8];
        v57 = v43 + 9;
        v58 = (float *)((char *)builder.m_VertexBuilder.m_pTangentT
                      + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentT);
        *v58 = *v57;
        v58[1] = v57[1];
        v58[2] = v57[2];
        v59 = builder.m_VertexBuilder.m_pCurrTexCoord[2];
        if ( (surfID->flags & 8) != 0 )
          *builder.m_VertexBuilder.m_pCurrTexCoord[2] = ctx.m_BumpSTexCoordOffset;
        else
          *builder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
        v59[1] = 0.0;
        m_pCurrNormal = builder.m_VertexBuilder.m_pCurrNormal;
        *builder.m_VertexBuilder.m_pCurrNormal = 0.0;
        m_pCurrNormal[1] = 0.0;
        m_pCurrNormal[2] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
        rightb += 64;
        ++v42;
        ++i;
      }
      while ( i < (int)pDispInfo[68].__vftable );
    }
    v61 = 0;
    if ( (int)pDispInfo[8].__vftable > 0 )
    {
      m_nCurrentIndex = builder.m_IndexBuilder.m_nCurrentIndex;
      do
      {
        v63 = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
            + *((_WORD *)&pDispInfo[61].dtr_IDispInfo + v61)
            - LOWORD(pDispInfo[11].__vftable);
        v61 += 3;
        builder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v63;
        builder.m_IndexBuilder.m_nCurrentIndex += builder.m_IndexBuilder.m_nIndexSize;
        builder.m_IndexBuilder.m_nIndexCount = builder.m_IndexBuilder.m_nCurrentIndex;
        builder.m_IndexBuilder.m_pIndices[builder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                                                  + *((_WORD *)pDispInfo[61].__vftable
                                                                                    + v61
                                                                                    - 2)
                                                                                  - LOWORD(pDispInfo[11].__vftable);
        builder.m_IndexBuilder.m_nCurrentIndex += builder.m_IndexBuilder.m_nIndexSize;
        builder.m_IndexBuilder.m_nIndexCount = builder.m_IndexBuilder.m_nCurrentIndex;
        builder.m_IndexBuilder.m_pIndices[builder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                                                  + *((_WORD *)pDispInfo[61].__vftable
                                                                                    + v61
                                                                                    - 1)
                                                                                  - LOWORD(pDispInfo[11].__vftable);
        builder.m_IndexBuilder.m_nCurrentIndex += builder.m_IndexBuilder.m_nIndexSize;
        builder.m_IndexBuilder.m_nIndexCount = builder.m_IndexBuilder.m_nCurrentIndex;
        builder.m_IndexBuilder.m_pIndices[builder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                                                  + *((_WORD *)pDispInfo[61].__vftable
                                                                                    + v61
                                                                                    - 1)
                                                                                  - LOWORD(pDispInfo[11].__vftable);
        builder.m_IndexBuilder.m_nCurrentIndex += builder.m_IndexBuilder.m_nIndexSize;
        builder.m_IndexBuilder.m_nIndexCount = builder.m_IndexBuilder.m_nCurrentIndex;
        builder.m_IndexBuilder.m_pIndices[builder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                                                  + *((_WORD *)pDispInfo[61].__vftable
                                                                                    + v61
                                                                                    - 2)
                                                                                  - LOWORD(pDispInfo[11].__vftable);
        builder.m_IndexBuilder.m_nCurrentIndex += builder.m_IndexBuilder.m_nIndexSize;
        builder.m_IndexBuilder.m_nIndexCount = builder.m_IndexBuilder.m_nCurrentIndex;
        builder.m_IndexBuilder.m_pIndices[builder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(builder.m_IndexBuilder.m_nIndexOffset)
                                                                                  + *((_WORD *)pDispInfo[61].__vftable
                                                                                    + v61
                                                                                    - 3)
                                                                                  - LOWORD(pDispInfo[11].__vftable);
        m_nCurrentIndex = builder.m_IndexBuilder.m_nIndexSize + builder.m_IndexBuilder.m_nCurrentIndex;
        builder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        builder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      while ( v61 < (int)pDispInfo[8].__vftable );
    }
    if ( builder.m_bGenerateIndices )
    {
      switch ( builder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &builder.m_IndexBuilder,
        primitiveType: builder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    builder.m_pMesh->UnlockMesh(
      this: builder.m_pMesh,
      a2: builder.m_VertexBuilder.m_nVertexCount,
      a3: builder.m_IndexBuilder.m_nIndexCount,
      a4: &builder);
    builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    builder.m_IndexBuilder.m_nMaxIndexCount = 0;
    builder.m_VertexBuilder.m_nMaxVertexCount = 0;
    builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
    builder.m_pMesh = nullptr;
    if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
    {
      builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
    {
      builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
    }
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1006CF70
// Name: RenderToAtlasedTexture
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderToAtlasedTexture(
        IMatRenderContext *pRenderContext@<ecx>,
        int nAtlasedTextureWidth@<eax>,
        const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *packedSurfaces,
        ITexture *pRenderTarget,
        int nAtlasedTextureHeight,
        const char *pMaterialSrcDir,
        const char *pTextureBaseName,
        RenderToAtlasedTextureRenderMode_t renderMode,
        const CDisplacementData *dispData,
        float flToneMapScale)
{
  const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *v10; // ebx
  int m_nValue; // eax
  void (__thiscall *SetToneMappingScaleLinear)(IMatRenderContext *, const Vector *); // edx
  CPackedSurfaceInfo *v15; // eax
  msurface2_t *m_SurfID; // ecx
  int v17; // ebx
  int v18; // eax
  int v19; // edx
  msurfacelighting_t *surfacelighting; // ecx
  unsigned __int8 *v21; // ebx
  void *v22; // edi
  char pDest[776]; // [esp+4Ch] [ebp-52Ch] BYREF
  char txtPath[260]; // [esp+354h] [ebp-224h] BYREF
  char tgaPath[260]; // [esp+458h] [ebp-120h] BYREF
  _DWORD v26[3]; // [esp+55Ch] [ebp-1Ch] BYREF
  msurface2_t *surfID; // [esp+568h] [ebp-10h]
  int v28; // [esp+56Ch] [ebp-Ch]
  int packedSurfaceIndex; // [esp+570h] [ebp-8h]
  bool bSaveMatSpecular; // [esp+577h] [ebp-1h]
  int flToneMapScalea; // [esp+59Ch] [ebp+24h]

  v10 = packedSurfaces;
  if ( mat_fastspecular.m_pParent != nullptr )
    m_nValue = mat_fastspecular.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bSaveMatSpecular = m_nValue != 0;
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "0");
  if ( renderMode == RENDER_TO_ATLASED_TEXTURE_LIGHTING_ONLY )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fullbright.IConVar, value: "2");
  else
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fullbright.IConVar, value: "0");
  UpdateMaterialSystemConfig();
  materials->EndFrame(this: materials);
  ((void (__cdecl *)(_DWORD))materials->BeginFrame)(a1: LODWORD(host_frametime));
  SetToneMappingScaleLinear = pRenderContext->SetToneMappingScaleLinear;
  *(float *)v26 = flToneMapScale;
  *(float *)&v26[1] = flToneMapScale;
  *(float *)&v26[2] = flToneMapScale;
  SetToneMappingScaleLinear(this: pRenderContext, a2: (const Vector *)v26);
  Push2DRenderingSetup(pRenderContext, pRenderTarget, nAtlasedTextureWidth, nAtlasedTextureHeight);
  packedSurfaceIndex = 0;
  if ( packedSurfaces->m_Size > 0 )
  {
    flToneMapScalea = 0;
    do
    {
      v15 = &v10->m_Memory.m_pMemory[flToneMapScalea];
      m_SurfID = v15->m_SurfID;
      v17 = v15->m_nMins[1];
      v18 = v15->m_nMins[0];
      surfID = m_SurfID;
      v19 = (char *)m_SurfID - (char *)host_state.worldbrush->surfaces2;
      surfacelighting = host_state.worldbrush->surfacelighting;
      v28 = v18;
      DrawSurfaceRectToAtlasedTexture(
        a1: v17,
        a2: nAtlasedTextureWidth,
        a3: (int)pRenderContext,
        left: (float)v18,
        top: (float)v17,
        right: (float)(v18 + *(__int16 *)((char *)surfacelighting->m_LightmapExtents + (v19 & 0xFFFFFFE0)) + 1),
        bottom: (float)(v17 + *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + (v19 & 0xFFFFFFE0)) + 1),
        nRenderTargetWidth: nAtlasedTextureWidth,
        nRenderTargetHeight: nAtlasedTextureHeight,
        surfID,
        renderMode,
        dispData);
      v10 = packedSurfaces;
      ++flToneMapScalea;
      ++packedSurfaceIndex;
    }
    while ( packedSurfaceIndex < packedSurfaces->m_Size );
  }
  v21 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 4 * nAtlasedTextureHeight * nAtlasedTextureWidth);
  pRenderContext->ReadPixels(
    this: pRenderContext,
    a2: 0,
    a3: 0,
    a4: nAtlasedTextureWidth,
    a5: nAtlasedTextureHeight,
    a6: v21,
    a7: IMAGE_FORMAT_RGBA8888);
  V_snprintf(pDest: tgaPath, maxLen: 260, pFormat: "%s/%s.tga", pMaterialSrcDir, pTextureBaseName);
  TGAWriter::WriteTGAFile(
    fileName: tgaPath,
    width: nAtlasedTextureWidth,
    height: nAtlasedTextureHeight,
    srcFormat: IMAGE_FORMAT_RGBA8888,
    srcData: v21,
    nStride: 4 * nAtlasedTextureWidth);
  free(pMem: v21);
  V_snprintf(pDest: txtPath, maxLen: 260, pFormat: "%s/%s.txt", pMaterialSrcDir, pTextureBaseName);
  v22 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: txtPath, a3: "w", a4: 0);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v22, a3: "\"nocompress\" \"1\"\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v22, a3: "\"nomip\" \"1\"\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v22, a3: "\"nolod\" \"1\"\n");
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v22);
  V_snprintf(pDest, maxLen: 776, pFormat: "vtex.exe -nop4 %s", tgaPath);
  if ( g_pProcessUtils->SimpleRunProcess(this: g_pProcessUtils, a2: pDest, a3: nullptr, a4: nullptr) == -1 )
    _Msg(a1: "Failed compiling %s\n", tgaPath);
  else
    _Msg(a1: "Compilation of \"%s\" succeeded\n", tgaPath);
  g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: txtPath, a3: nullptr);
  g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: tgaPath, a3: nullptr);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_VIEW);
  pRenderContext->PopMatrix(this: pRenderContext);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_PROJECTION);
  pRenderContext->PopMatrix(this: pRenderContext);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PopMatrix(this: pRenderContext);
  pRenderContext->PopRenderTargetAndViewport(this: pRenderContext);
  if ( bSaveMatSpecular )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "1");
  else
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "0");
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fullbright.IConVar, value: "0");
  UpdateMaterialSystemConfig();
  materials->EndFrame(this: materials);
  ((void (__cdecl *)(_DWORD))materials->BeginFrame)(a1: LODWORD(host_frametime));
}

//------------------------------------------------------------------------------
// Address: 0x1006D310
// Name: WriteSMD
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __usercall WriteSMD@<eax>(
        const CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > *packedSurfaces@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        int nAtlasedTextureWidth,
        int nAtlasedTextureHeight,
        const char *pModelSrcDir,
        bool bWater)
{
  const char *v7; // eax
  void *v8; // esi
  int *v9; // edi
  IMaterial *material; // ecx
  const char *v11; // eax
  int v12; // ecx
  char smdPath[260]; // [esp+0h] [ebp-114h] BYREF
  worldbrushdata_t *pBrushData; // [esp+104h] [ebp-10h]
  int packedSurfaceIndex; // [esp+108h] [ebp-Ch]
  int nSurfaces; // [esp+10Ch] [ebp-8h]
  unsigned int v18; // [esp+110h] [ebp-4h]

  v7 = "_water";
  if ( !bWater )
    v7 = defaultValue;
  V_snprintf(pDest: smdPath, maxLen: 260, pFormat: "%s/simpleworldmodel%s.smd", pModelSrcDir, v7);
  v8 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, _DWORD, int, int))g_pFullFileSystem->Open)(
                 a1: &g_pFullFileSystem->IBaseFileSystem,
                 a2: smdPath,
                 a3: "w",
                 a4: 0,
                 a5: a2,
                 a6: a3);
  WriteSMDHeader(smdfp: v8);
  nSurfaces = 0;
  pBrushData = host_state.worldbrush;
  packedSurfaceIndex = 0;
  if ( packedSurfaces->m_Size > 0 )
  {
    v18 = 0;
    do
    {
      v9 = (int *)&packedSurfaces->m_Memory.m_pMemory[v18 / 0xC];
      material = materialSortInfoArray[*(__int16 *)(*v9 + 18)].material;
      v11 = material->GetShaderName(this: material);
      if ( (V_stristr(pStr: v11, pSearch: "water") != nullptr) == bWater )
      {
        v12 = v9[2];
        ++nSurfaces;
        WriteSurfaceToSMD(
          pBrushData,
          surfID: *v9,
          x: v9[1],
          y: v12,
          smdfp: v8,
          nAtlasedTextureWidth,
          nAtlasedTextureHeight);
      }
      v18 += 12;
      ++packedSurfaceIndex;
    }
    while ( packedSurfaceIndex < packedSurfaces->m_Size );
  }
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v8, a3: "end\n");
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
  return nSurfaces;
}

//------------------------------------------------------------------------------
// Address: 0x1006D420
// Name: PackSurfacesAndBuildSurfaceList
// Source: json
//------------------------------------------------------------------------------
void __usercall PackSurfacesAndBuildSurfaceList(
        CUtlMemory<CVTFTexture::ResourceMemorySection,int> *packedSurfaces@<esi>,
        int *nWidth,
        int *nHeight)
{
  int nWorldFaceCount; // edi
  msurface2_t *v4; // ebx
  char *v5; // eax
  int v6; // ecx
  int materialSortID; // eax
  IMaterial *material; // edi
  int v9; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CPackedSurfaceInfo *v12; // ecx
  int v13; // eax
  int v14; // edi
  CPackedSurfaceInfo *v15; // eax
  int v16; // edx
  CPackedSurfaceInfo *v17; // eax
  int v18; // edx
  CImagePacker v19; // [esp+4h] [ebp-2034h] BYREF
  int pReturnHeight; // [esp+2020h] [ebp-18h] BYREF
  int width; // [esp+2024h] [ebp-14h]
  int height; // [esp+2028h] [ebp-10h]
  int pReturnWidth; // [esp+202Ch] [ebp-Ch] BYREF
  int i; // [esp+2030h] [ebp-8h]
  unsigned int v25; // [esp+2034h] [ebp-4h]

  nWorldFaceCount = host_state.worldbrush->nWorldFaceCount;
  CImagePacker::Reset(this: &v19, nSortId: 0, maxLightmapWidth: 1024, maxLightmapHeight: 1024);
  if ( nWorldFaceCount > 0 )
  {
    v25 = 0;
    for ( i = nWorldFaceCount; i != 0; --i )
    {
      v4 = &host_state.worldbrush->surfaces2[v25 / 0x20];
      v5 = (char *)host_state.worldbrush->surfacelighting + (v25 & 0xFFFFFFE0);
      v6 = *((__int16 *)v5 + 2) + 1;
      height = *((__int16 *)v5 + 3) + 1;
      materialSortID = v4->materialSortID;
      width = v6;
      material = materialSortInfoArray[materialSortID].material;
      if ( !material->IsTranslucent(this: material)
        || (v9 = (int)material->FindVarFast(this: material, a2: "$worldimposter", a3: &dword_104DE64C)) != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 108))(a1: v9) != 0 )
      {
        m_pMemory = (int)packedSurfaces[1].m_pMemory;
        m_nAllocationCount = packedSurfaces->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
            this: packedSurfaces,
            num: m_pMemory - m_nAllocationCount + 1);
        ++packedSurfaces[1].m_pMemory;
        v12 = (CPackedSurfaceInfo *)packedSurfaces->m_pMemory;
        v13 = (int)packedSurfaces[1].m_pMemory - m_pMemory - 1;
        packedSurfaces[1].m_nAllocationCount = (int)packedSurfaces->m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &v12[m_pMemory + 1], src: &v12[m_pMemory], count: 12 * v13);
        v14 = m_pMemory;
        v15 = (CPackedSurfaceInfo *)&packedSurfaces->m_pMemory[v14];
        if ( v15 != nullptr )
        {
          v15->m_SurfID = nullptr;
          v15->m_nMins[0] = -1;
          v15->m_nMins[1] = -1;
        }
        v16 = height;
        v17 = (CPackedSurfaceInfo *)&packedSurfaces->m_pMemory[v14];
        v17->m_SurfID = v4;
        if ( !CImagePacker::AddBlock(this: &v19, width, height: v16, returnX: v17->m_nMins, returnY: &v17->m_nMins[1]) )
          _Warning(a1: "failed allocating an atlased texture block in buildmodelforworld\n");
      }
      v25 += 32;
    }
  }
  CImagePacker::GetMinimumDimensions(this: &v19, &pReturnWidth, &pReturnHeight);
  v18 = pReturnHeight;
  *nWidth = pReturnWidth;
  *nHeight = v18;
}

//------------------------------------------------------------------------------
// Address: 0x1006D5B0
// Name: public: CDisplacementData::CDisplacementData(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDisplacementData *__thiscall CDisplacementData::CDisplacementData(
        CDisplacementData *this,
        void *hDispInfo,
        int nDispInfo)
{
  int v4; // esi
  IDispInfo *v5; // eax
  int v6; // ecx
  int m_nAllocationCount; // eax
  CDispVert *m_pMemory; // ecx
  int v9; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  int i; // [esp+134h] [ebp-4h]

  v4 = 0;
  this->m_nDispStartVert.m_Memory.m_pMemory = nullptr;
  this->m_nDispStartVert.m_Memory.m_nAllocationCount = 0;
  this->m_nDispStartVert.m_Memory.m_nGrowSize = 0;
  this->m_nDispStartVert.m_pElements = nullptr;
  this->m_dispVerts.m_Memory.m_pMemory = nullptr;
  this->m_dispVerts.m_Memory.m_nAllocationCount = 0;
  this->m_dispVerts.m_Memory.m_nGrowSize = 0;
  this->m_dispVerts.m_Size = 0;
  this->m_dispVerts.m_pElements = nullptr;
  this->m_nDispStartVert.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: nDispInfo);
  i = 0;
  if ( nDispInfo > 0 )
  {
    do
    {
      v5 = DispInfo_IndexArray(hArray: hDispInfo, iElement: i);
      v6 = i;
      this->m_nDispStartVert.m_Memory.m_pMemory[i] = v4;
      v4 += (int)v5[119].ComputeShadowFragments;
      i = v6 + 1;
    }
    while ( v6 + 1 < nDispInfo );
  }
  this->m_dispVerts.m_Size = 0;
  if ( v4 != 0 )
  {
    m_nAllocationCount = this->m_dispVerts.m_Memory.m_nAllocationCount;
    if ( v4 > m_nAllocationCount )
      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_dispVerts,
        num: v4 - m_nAllocationCount);
    this->m_dispVerts.m_Size += v4;
    m_pMemory = this->m_dispVerts.m_Memory.m_pMemory;
    v9 = this->m_dispVerts.m_Size - v4;
    this->m_dispVerts.m_pElements = m_pMemory;
    if ( v9 > 0 && v4 > 0 )
      _V_memmove(dest: &m_pMemory[v4], src: m_pMemory, count: 20 * v9);
  }
  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 33, bUncompress: true);
  CMapLoadHelper::LoadLumpData(this: &lh, offset: 0, size: 20 * v4, pData: this->m_dispVerts.m_Memory.m_pMemory);
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006D6B0
// Name: buildmodelforworld
// Source: json
//------------------------------------------------------------------------------
void __usercall buildmodelforworld(int a1@<ebx>, int a2@<edi>)
{
  IBaseFileSystem_vtbl *v2; // esi
  CClientState *BaseLocalClient; // eax
  CClientState *v4; // eax
  IMatRenderContext *v5; // eax
  IMatRenderContext *v6; // ebx
  ITexture *v7; // esi
  int v8; // edi
  int v9; // esi
  ITexture *v10; // edi
  IMatRenderContext *m_pObject; // esi
  char modelDir[260]; // [esp+24h] [ebp-768h] BYREF
  char matDir[260]; // [esp+128h] [ebp-664h] BYREF
  char mapPath[260]; // [esp+22Ch] [ebp-560h] BYREF
  char materialSrcDir[260]; // [esp+330h] [ebp-45Ch] BYREF
  char modelSrcDir[260]; // [esp+434h] [ebp-358h] BYREF
  char gameDir[260]; // [esp+538h] [ebp-254h] BYREF
  char mapName[260]; // [esp+63Ch] [ebp-150h] BYREF
  CDisplacementData dispData; // [esp+740h] [ebp-4Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+768h] [ebp-24h]
  int nAtlasedTextureWidth; // [esp+76Ch] [ebp-20h] BYREF
  BOOL bAllow; // [esp+770h] [ebp-1Ch]
  CUtlVector<CPackedSurfaceInfo,CUtlMemory<CPackedSurfaceInfo,int> > packedSurfaces; // [esp+774h] [ebp-18h] BYREF
  ITexture *pRenderTarget; // [esp+788h] [ebp-4h] BYREF

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_buildingmapforworld.IConVar, value: 1);
  if ( g_LostVideoMemory )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_buildingmapforworld.IConVar, value: 0);
    return;
  }
  v2 = g_pFileSystem->IBaseFileSystem::__vftable;
  *(_DWORD *)modelDir = "GAME";
  BaseLocalClient = GetBaseLocalClient();
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))v2->IsFileWritable)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: BaseLocalClient->m_szLevelName) == 0 )
  {
    v4 = GetBaseLocalClient();
    _Warning(a1: "%s is not writable!!!  Check it out before running buildmodelforworld.\n", v4->m_szLevelName);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_buildingmapforworld.IConVar, value: 0);
    return;
  }
  if ( ComputeMapName(pMapName: mapName, nMapNameSize: 260) == 0 )
  {
    _Warning(a1: "can't buildmodelforworld.  Map not loaded.\n");
LABEL_7:
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_buildingmapforworld.IConVar, value: 0);
    return;
  }
  ComputeAndMakeDirectories(
    pMapName: mapName,
    nMatDirSize: 260,
    pModelDir: modelDir,
    pModelSrcDir: modelSrcDir,
    pMatDir: matDir,
    pMaterialSrcDir: materialSrcDir,
    nMaterialSrcDirSize: 0x104u,
    nModelDirSize: 0x104u,
    nModelSrcDirSize: 0x104u);
  COM_GetGameDir(szGameDir: gameDir, maxlen: 260);
  if ( CreateSimpleWorldModelVMT(pMaterialDir: matDir, mapName) == 0 )
    goto LABEL_7;
  LOBYTE(bAllow) = Host_AllowQueuedMaterialSystem(bAllow: false);
  V_RenderVGuiOnly();
  CMapLoadHelper::Init(pMapModel: host_state.worldmodel, pPathName: host_state.worldmodel->szPathName);
  CDisplacementData::CDisplacementData(
    this: &dispData,
    hDispInfo: host_state.worldbrush->hDispInfos,
    nDispInfo: host_state.worldbrush->numDispInfos);
  CMapLoadHelper::Shutdown();
  v5 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                              a1: materials,
                              a2,
                              a3: a1);
  v6 = v5;
  pRenderContext.m_pObject = v5;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  memset(&packedSurfaces, 0, sizeof(packedSurfaces));
  PackSurfacesAndBuildSurfaceList(
    (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&packedSurfaces,
    nWidth: &nAtlasedTextureWidth,
    nHeight: (int *)&pRenderTarget);
  materials->ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(this: materials);
  materials->BeginRenderTargetAllocation(this: materials);
  v7 = pRenderTarget;
  v8 = nAtlasedTextureWidth;
  pRenderTarget = materials->CreateRenderTargetTexture(
                    this: materials,
                    a2: nAtlasedTextureWidth,
                    a3: pRenderTarget,
                    a4: 0,
                    a5: 0,
                    a6: 2);
  materials->EndRenderTargetAllocation(this: materials);
  RenderToAtlasedTexture(
    pRenderContext: v6,
    nAtlasedTextureWidth: v8,
    &packedSurfaces,
    pRenderTarget,
    nAtlasedTextureHeight: (int)v7,
    pMaterialSrcDir: materialSrcDir,
    pTextureBaseName: "simpleworldmodel",
    renderMode: RENDER_TO_ATLASED_TEXTURE_FULL_RENDERING,
    &dispData,
    flToneMapScale: 4.0);
  RenderToAtlasedTexture(
    pRenderContext: v6,
    nAtlasedTextureWidth: v8,
    &packedSurfaces,
    pRenderTarget,
    nAtlasedTextureHeight: (int)v7,
    pMaterialSrcDir: materialSrcDir,
    pTextureBaseName: "simpleworldmodel_lightmap",
    renderMode: RENDER_TO_ATLASED_TEXTURE_LIGHTING_ONLY,
    &dispData,
    flToneMapScale: 1.0);
  RenderToAtlasedTexture(
    pRenderContext: v6,
    nAtlasedTextureWidth: v8,
    &packedSurfaces,
    pRenderTarget,
    nAtlasedTextureHeight: (int)v7,
    pMaterialSrcDir: materialSrcDir,
    pTextureBaseName: "simpleworldmodel_albedo",
    renderMode: RENDER_TO_ATLASED_TEXTURE_NO_LIGHTING,
    &dispData,
    flToneMapScale: 1.0);
  pRenderTarget = (ITexture *)WriteSMD(
                                &packedSurfaces,
                                a2: v8,
                                a3: (int)v7,
                                nAtlasedTextureWidth: v8,
                                nAtlasedTextureHeight: (int)v7,
                                pModelSrcDir: modelSrcDir,
                                bWater: true);
  v9 = WriteSMD(
         &packedSurfaces,
         a2: v8,
         a3: (int)v7,
         nAtlasedTextureWidth: v8,
         nAtlasedTextureHeight: (int)v7,
         pModelSrcDir: modelSrcDir,
         bWater: false);
  Host_AllowQueuedMaterialSystem(bAllow);
  if ( (int)pRenderTarget > 0 )
    CreateAndCompileQCFile(mapName, bWater: true, a3: v9, pModelSrcDir: modelSrcDir);
  if ( v9 > 0 )
    CreateAndCompileQCFile(mapName, bWater: false, a3: v9, pModelSrcDir: modelSrcDir);
  LoadBSPPackInterface();
  V_snprintf(pDest: mapPath, maxLen: 260, pFormat: "maps/%s.bsp", mapName);
  s_pBSPPack->LoadBSPFile(this: s_pBSPPack, a2: g_pFileSystem, a3: mapPath);
  if ( v9 <= 0 )
  {
    RemoveFileFromPack(mapName, pFormatString: "models/maps/%s/simpleworldmodel.mdl", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "models/maps/%s/simpleworldmodel.dx90.vtx", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "models/maps/%s/simpleworldmodel.vvd", gameDir);
  }
  else
  {
    AddFileToPackAndDeleteFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel.mdl", gameDir);
    AddFileToPackAndDeleteFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel.dx90.vtx", gameDir);
    AddFileToPackAndDeleteFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel.vvd", gameDir);
  }
  v10 = pRenderTarget;
  if ( (int)pRenderTarget <= 0 )
  {
    RemoveFileFromPack(mapName, pFormatString: "models/maps/%s/simpleworldmodel_water.mdl", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "models/maps/%s/simpleworldmodel_water.dx90.vtx", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "models/maps/%s/simpleworldmodel_water.vvd", gameDir);
  }
  else
  {
    AddFileToPackAndDeleteFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel_water.mdl", gameDir);
    AddFileToPackAndDeleteFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel_water.dx90.vtx", gameDir);
    AddFileToPackAndDeleteFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel_water.vvd", gameDir);
  }
  if ( (int)v10 > 0 || v9 > 0 )
  {
    AddFileToPackAndDeleteFile(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel.vmt", gameDir);
    AddFileToPackAndDeleteFile(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel.pwl.vtf", gameDir);
    AddFileToPackAndDeleteFile(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel.vtf", gameDir);
    AddFileToPackAndDeleteFile(
      mapName,
      pFormatString: "materials/models/maps/%s/simpleworldmodel_albedo.pwl.vtf",
      gameDir);
    AddFileToPackAndDeleteFile(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel_albedo.vtf", gameDir);
    AddFileToPackAndDeleteFile(
      mapName,
      pFormatString: "materials/models/maps/%s/simpleworldmodel_lightmap.pwl.vtf",
      gameDir);
    AddFileToPackAndDeleteFile(
      mapName,
      pFormatString: "materials/models/maps/%s/simpleworldmodel_lightmap.vtf",
      gameDir);
  }
  else
  {
    RemoveFileFromPack(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel.vmt", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel.pwl.vtf", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel.vtf", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel_albedo.pwl.vtf", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel_albedo.vtf", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel_lightmap.pwl.vtf", gameDir);
    RemoveFileFromPack(mapName, pFormatString: "materials/models/maps/%s/simpleworldmodel_lightmap.vtf", gameDir);
  }
  s_pBSPPack->WriteBSPFile(this: s_pBSPPack, a2: mapPath);
  RemoveContentFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel.qc");
  RemoveContentFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel.smd");
  RemoveContentFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel_water.qc");
  RemoveContentFile(mapName, pFormatString: "models/maps/%s/simpleworldmodel_water.smd");
  FileSystem_UnloadModule(pModule: s_pBSPPackModule);
  s_pBSPPack = nullptr;
  s_pBSPPackModule = nullptr;
  _Warning(
    a1: "*****************It is recommended to quit the game after running buildmodelforworld!  Leaks rendertargets!****************\n");
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_buildingmapforworld.IConVar, value: 0);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&packedSurfaces);
  m_pObject = pRenderContext.m_pObject;
  if ( pRenderContext.m_pObject != nullptr )
  {
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dispData.m_dispVerts);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dispData);
}

//------------------------------------------------------------------------------
// Address: 0x10312B40
// Name: _dynamic_initializer_for__buildmodelforworld_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__buildmodelforworld_command__()
{
  ConCommand::ConCommand(
    this: &buildmodelforworld_command,
    pName: "buildmodelforworld",
    callback: (void (__cdecl *)(const CCommand *))buildmodelforworld,
    pHelpString: "buildmodelforworld",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__buildmodelforworld_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103224C0
// Name: _dynamic_atexit_destructor_for__buildmodelforworld_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__buildmodelforworld_command__()
{
  ConCommand::~ConCommand(this: &buildmodelforworld_command);
}

} // namespace engine_xlsp
