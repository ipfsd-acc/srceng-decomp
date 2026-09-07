// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/buildcubemaps.cpp
// Functions: 35
// ============================================================

#include "engine\buildcubemaps.h"

//------------------------------------------------------------------------------
// Address: 0x10067F40
// Name: public: void FloatBitMap_t::Init(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::Init(
        FloatBitMap_t *this,
        unsigned __int8 *nXSize,
        unsigned __int8 *nYSize,
        int nZSize,
        char nAttributeMask)
{
  int _8; // [esp+8h] [ebp+0h] BYREF

  CSOAContainer::PurgeData(this);
  CSOAContainer::SetAttributeType(this, nAttrIdx: 0, nDataType: ATTRDATATYPE_FLOAT, bAllocateMemory: nAttributeMask & 1);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 1,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 2) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 2,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 4) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 3,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 8) != 0);
  CSOAContainer::AllocateData(this, nNCols: nXSize, nNRows: nYSize, nSlices: nZSize);
  if ( (nAttributeMask & 8) == 0 )
    CSOAContainer::FillAttr(this, a2: (int)&_8, nAttr: 3, flValue: COERCE_UNSIGNED_INT(1.0));
}

//------------------------------------------------------------------------------
// Address: 0x10067FE0
// Name: VTex_Load
// Source: json
//------------------------------------------------------------------------------
IVTex *__cdecl VTex_Load(struct CSysModule **pModule)
{
  IVTex *v1; // esi
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IVTex *result; // eax

  v1 = nullptr;
  Module = FileSystem_LoadModule(path: "vtex_dll");
  *pModule = Module;
  if ( Module == nullptr
    || (Factory = Sys_GetFactory(pModule: Module)) == nullptr
    || (result = (IVTex *)Factory(a1: "VTEX_003", a2: nullptr), v1 = result, result == nullptr) )
  {
    ConMsg(a1: "Can't load vtex_dll.dll\n");
    return v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068030
// Name: void __near * CubemapsFSFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl CubemapsFSFactory(const char *pName)
{
  return _V_stricmp(s1: pName, s2: "VFileSystem017") == 0 ? g_pFileSystem : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10068060
// Name: AddSampleToBSPFile
// Source: json
//------------------------------------------------------------------------------
void __usercall AddSampleToBSPFile(
        mcubemapsample_t *pSample@<esi>,
        const char *matDir@<edi>,
        bool bHDR,
        IBSPPack *iBSPPack,
        CCubemapCollection *pCC)
{
  CCubemapCollection *v5; // ebx
  const char *v6; // eax
  const char *v7; // eax
  char localPath[1024]; // [esp+4h] [ebp-804h] BYREF
  char outputTextureName[512]; // [esp+404h] [ebp-404h] BYREF
  char inputTextureName[514]; // [esp+604h] [ebp-204h] BYREF
  CUtlSymbol result; // [esp+806h] [ebp-2h] BYREF

  v5 = pCC;
  v6 = "_hdr";
  if ( !bHDR )
    v6 = defaultValue;
  V_snprintf(
    pDest: inputTextureName,
    maxLen: 512,
    pFormat: "%s/c%d_%d_%d%s.vtf",
    matDir,
    (int)pSample->origin.x,
    (int)pSample->origin.y,
    (int)pSample->origin.z,
    v6);
  if ( v5 != nullptr )
  {
    if ( CUtlSymbolTable::Find(this: &v5->m_arrEntries, result: (CUtlSymbol *)&pCC + 1, pString: inputTextureName)->m_Id != 0xFFFF )
      return;
    CUtlSymbolTable::AddString(this: &v5->m_arrEntries, &result, pString: inputTextureName);
  }
  if ( g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: inputTextureName, a3: localPath, a4: 1024) != nullptr )
  {
    v7 = ".hdr";
    if ( !bHDR )
      v7 = defaultValue;
    V_snprintf(
      pDest: outputTextureName,
      maxLen: 512,
      pFormat: "%s/c%d_%d_%d%s.vtf",
      matDir,
      (int)pSample->origin.x,
      (int)pSample->origin.y,
      (int)pSample->origin.z,
      v7);
    V_FixSlashes(pname: localPath, separator: 92);
    iBSPPack->AddFileToPack(this: iBSPPack, a2: outputTextureName, a3: localPath);
  }
  else
  {
    _Warning(a1: "vtex failed to compile cubemap '%s'!\n", inputTextureName);
  }
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: inputTextureName, a3: "DEFAULT_WRITE_PATH");
}

//------------------------------------------------------------------------------
// Address: 0x100681A0
// Name: public: FloatCubeMap_t::FloatCubeMap_t(int,int)
// Source: json
//------------------------------------------------------------------------------
FloatCubeMap_t *__thiscall FloatCubeMap_t::FloatCubeMap_t(
        FloatCubeMap_t *this,
        unsigned __int8 *xfsize,
        unsigned __int8 *yfsize)
{
  int v3; // ebx
  unsigned __int8 **m_pSeparateDataMemory; // esi
  FloatCubeMap_t *v5; // esi
  int i; // ebx

  v3 = 5;
  m_pSeparateDataMemory = this->face_maps[0].m_pSeparateDataMemory;
  do
  {
    memset(dst: (unsigned __int8 *)m_pSeparateDataMemory - 520, value: 0xFFu, count: 0x80u);
    memset(dst: (unsigned __int8 *)m_pSeparateDataMemory, value: 0, count: 0x80u);
    *(m_pSeparateDataMemory - 1) = nullptr;
    *(m_pSeparateDataMemory - 163) = nullptr;
    *(m_pSeparateDataMemory - 164) = nullptr;
    *(m_pSeparateDataMemory - 166) = nullptr;
    *(m_pSeparateDataMemory - 167) = nullptr;
    *(m_pSeparateDataMemory - 165) = nullptr;
    *(m_pSeparateDataMemory - 168) = nullptr;
    *(m_pSeparateDataMemory - 2) = nullptr;
    m_pSeparateDataMemory[32] = nullptr;
    m_pSeparateDataMemory += 201;
    --v3;
  }
  while ( v3 >= 0 );
  v5 = this;
  for ( i = 6; i != 0; --i )
  {
    CSOAContainer::PurgeData(this: (CSOAContainer *)v5);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 0,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 1,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 2,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 3,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::AllocateData(this: (CSOAContainer *)v5, nNCols: xfsize, nNRows: yfsize, nSlices: 1);
    v5 = (FloatCubeMap_t *)((char *)v5 + 804);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068290
// Name: void R_BuildCubemapSamples_PostBuild(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildCubemapSamples_PostBuild()
{
  unsigned int v0; // [esp-18h] [ebp-58h]
  int v1; // [esp-14h] [ebp-54h]
  unsigned int v2; // [esp-14h] [ebp-54h]
  int v3; // [esp-10h] [ebp-50h]
  int v4; // [esp-Ch] [ebp-4Ch]
  ConVarRef drawMRMModelsCVar; // [esp+0h] [ebp-40h] BYREF
  ConVarRef mat_disable_bloom; // [esp+8h] [ebp-38h] BYREF
  ConVarRef r_occlusion; // [esp+10h] [ebp-30h] BYREF
  ConVarRef r_portalsopenall; // [esp+18h] [ebp-28h] BYREF
  ConVarRef r_lightstyle; // [esp+20h] [ebp-20h] BYREF
  ConVarRef mat_drawwater; // [esp+28h] [ebp-18h] BYREF
  ConVarRef r_shadows; // [esp+30h] [ebp-10h] BYREF
  ConVarRef cl_mouseenable; // [esp+38h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &cl_mouseenable, pName: "cl_mouseenable");
  if ( ConVarRef::IsValid(this: &cl_mouseenable) )
    cl_mouseenable.m_pConVar->SetValue_2(this: cl_mouseenable.m_pConVar, a2: 1);
  ConVarRef::ConVarRef(this: &r_shadows, pName: "r_shadows");
  if ( ConVarRef::IsValid(this: &r_shadows) )
    r_shadows.m_pConVar->SetValue_2(this: r_shadows.m_pConVar, a2: saveShadows);
  ConVarRef::ConVarRef(this: &mat_drawwater, pName: "mat_drawwater");
  if ( ConVarRef::IsValid(this: &mat_drawwater) )
  {
    v4 = bDrawWater;
    ((void (__thiscall *)(IConVar *))mat_drawwater.m_pConVar->SetValue_2)(a1: mat_drawwater.m_pConVar);
  }
  if ( bSaveMatSpecular )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "1", a2: v4);
  else
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "0", a2: v4);
  ConVarRef::ConVarRef(this: &r_lightstyle, pName: "r_lightstyle");
  if ( ConVarRef::IsValid(this: &r_lightstyle) )
  {
    r_lightstyle.m_pConVar->SetValue_2(this: r_lightstyle.m_pConVar, a2: nSaveLightStyle);
    R_RedownloadAllLightmaps();
  }
  ConVarRef::ConVarRef(this: &r_portalsopenall, pName: "r_portalsopenall");
  if ( ConVarRef::IsValid(this: &r_portalsopenall) )
  {
    v3 = 0;
    ((void (__thiscall *)(IConVar *))r_portalsopenall.m_pConVar->SetValue_2)(a1: r_portalsopenall.m_pConVar);
  }
  ConVarRef::ConVarRef(this: &r_occlusion, pName: "r_occlusion");
  if ( ConVarRef::IsValid(this: &r_occlusion) )
  {
    v1 = nOldOcclusionVal;
    ((void (__thiscall *)(IConVar *))r_occlusion.m_pConVar->SetValue_2)(a1: r_occlusion.m_pConVar);
  }
  ConVarRef::ConVarRef(this: &mat_disable_bloom, pName: "mat_disable_bloom");
  if ( ConVarRef::IsValid(this: &mat_disable_bloom) )
  {
    v0 = nOldBloomDisable;
    ((void (__thiscall *)(IConVar *))mat_disable_bloom.m_pConVar->SetValue_2)(a1: mat_disable_bloom.m_pConVar);
  }
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_DrawBeams.IConVar, value: bSaveDrawBeams, a2: v0, a3: v1);
  ConVarRef::ConVarRef(this: &drawMRMModelsCVar, pName: "r_drawothermodels");
  if ( ConVarRef::IsValid(this: &drawMRMModelsCVar) )
  {
    v2 = originaldrawMRMModelsVal;
    ((void (__thiscall *)(IConVar *))drawMRMModelsCVar.m_pConVar->SetValue_2)(a1: drawMRMModelsCVar.m_pConVar);
  }
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&building_cubemaps.IConVar, value: 0, a2: v2, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100684C0
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100684E0
// Name: void R_BuildCubemapSamples_PreBuild(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildCubemapSamples_PreBuild()
{
  IBaseFileSystem_vtbl *v0; // esi
  CClientState *BaseLocalClient; // eax
  CClientState *v2; // eax
  IConVar_vtbl *v3; // eax
  int m_nValue; // eax
  IConVar_vtbl *v5; // eax
  unsigned int v6; // [esp-18h] [ebp-5Ch]
  int v7; // [esp-14h] [ebp-58h]
  unsigned int v8; // [esp-10h] [ebp-54h]
  int v9; // [esp-Ch] [ebp-50h]
  ConVarRef drawMRMModelsCVar; // [esp+4h] [ebp-40h] BYREF
  ConVarRef r_portalsopenall; // [esp+Ch] [ebp-38h] BYREF
  ConVarRef cl_mouseenable; // [esp+14h] [ebp-30h] BYREF
  ConVarRef mat_disable_bloom; // [esp+1Ch] [ebp-28h] BYREF
  ConVarRef r_occlusion; // [esp+24h] [ebp-20h] BYREF
  ConVarRef r_lightstyle; // [esp+2Ch] [ebp-18h] BYREF
  ConVarRef mat_drawwater; // [esp+34h] [ebp-10h] BYREF
  ConVarRef r_shadows; // [esp+3Ch] [ebp-8h] BYREF

  v0 = g_pFileSystem->IBaseFileSystem::__vftable;
  BaseLocalClient = GetBaseLocalClient();
  if ( v0->IsFileWritable(this: &g_pFileSystem->IBaseFileSystem, a2: BaseLocalClient->m_szLevelName, a3: "GAME") )
  {
    ConVarRef::ConVarRef(this: &cl_mouseenable, pName: "cl_mouseenable");
    if ( ConVarRef::IsValid(this: &cl_mouseenable) )
    {
      v9 = 0;
      ((void (__thiscall *)(IConVar *))cl_mouseenable.m_pConVar->SetValue_2)(a1: cl_mouseenable.m_pConVar);
    }
    ConVarRef::ConVarRef(this: &r_shadows, pName: "r_shadows");
    saveShadows = true;
    if ( ConVarRef::IsValid(this: &r_shadows) )
    {
      v8 = 0;
      saveShadows = r_shadows.m_pConVarState->m_Value.m_nValue != 0;
      ((void (__thiscall *)(IConVar *))r_shadows.m_pConVar->SetValue_2)(a1: r_shadows.m_pConVar);
    }
    ConVarRef::ConVarRef(this: &mat_drawwater, pName: "mat_drawwater");
    bDrawWater = true;
    if ( ConVarRef::IsValid(this: &mat_drawwater) )
    {
      v3 = mat_drawwater.m_pConVar->__vftable;
      bDrawWater = mat_drawwater.m_pConVarState->m_Value.m_nValue != 0;
      v7 = 0;
      ((void (__thiscall *)(IConVar *))v3->SetValue_2)(a1: mat_drawwater.m_pConVar);
    }
    nSaveLightStyle = -1;
    ConVarRef::ConVarRef(this: &r_lightstyle, pName: "r_lightstyle");
    if ( ConVarRef::IsValid(this: &r_lightstyle) )
    {
      nSaveLightStyle = r_lightstyle.m_pConVarState->m_Value.m_nValue;
      v6 = 0;
      ((void (__thiscall *)(IConVar *))r_lightstyle.m_pConVar->SetValue_2)(a1: r_lightstyle.m_pConVar);
      R_RedownloadAllLightmaps();
    }
    if ( r_DrawBeams.m_pParent != nullptr )
      bSaveDrawBeams = r_DrawBeams.m_pParent->m_Value.m_nValue;
    else
      bSaveDrawBeams = 0;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_DrawBeams.IConVar, value: 0, a2: v6, a3: v7);
    if ( mat_fastspecular.m_pParent != nullptr )
      m_nValue = mat_fastspecular.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    bSaveMatSpecular = m_nValue != 0;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&building_cubemaps.IConVar, value: 1, a2: v8, a3: v9);
    ConVarRef::ConVarRef(this: &r_portalsopenall, pName: "r_portalsopenall");
    if ( ConVarRef::IsValid(this: &r_portalsopenall) )
      r_portalsopenall.m_pConVar->SetValue_2(this: r_portalsopenall.m_pConVar, a2: 1);
    nOldOcclusionVal = 1;
    ConVarRef::ConVarRef(this: &r_occlusion, pName: "r_occlusion");
    if ( ConVarRef::IsValid(this: &r_occlusion) )
    {
      nOldOcclusionVal = r_occlusion.m_pConVarState->m_Value.m_nValue;
      r_occlusion.m_pConVar->SetValue_2(this: r_occlusion.m_pConVar, a2: 0);
    }
    ConVarRef::ConVarRef(this: &mat_disable_bloom, pName: "mat_disable_bloom");
    nOldBloomDisable = 0;
    if ( ConVarRef::IsValid(this: &mat_disable_bloom) )
    {
      v5 = mat_disable_bloom.m_pConVar->__vftable;
      nOldBloomDisable = mat_disable_bloom.m_pConVarState->m_Value.m_nValue;
      v5->SetValue_2(this: mat_disable_bloom.m_pConVar, a2: 1);
    }
    ConVarRef::ConVarRef(this: &drawMRMModelsCVar, pName: "r_drawothermodels");
    if ( ConVarRef::IsValid(this: &drawMRMModelsCVar) )
      originaldrawMRMModelsVal = drawMRMModelsCVar.m_pConVarState->m_Value.m_nValue;
  }
  else
  {
    v2 = GetBaseLocalClient();
    _Warning(a1: "%s is not writable!!!  Check it out before running buildcubemaps.\n", v2->m_szLevelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068720
// Name: TakeCubemapSnapshot
// Source: json
//------------------------------------------------------------------------------
void __usercall TakeCubemapSnapshot(
        int a1@<ebx>,
        const Vector *origin,
        const char *pFileNameBase,
        int screenBufSize,
        BOOL tgaSize)
{
  double v5; // rdi
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v7; // esi
  vgui::PropertyPage *v8; // ecx
  const Vector *v9; // ebx
  float x; // xmm0_4
  int v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // xmm1_4
  float y; // xmm0_4
  float z; // xmm0_4
  unsigned __int8 *v16; // eax
  void (__thiscall *v17)(int, _DWORD, _DWORD, int, int, unsigned __int8 *, _DWORD); // edx
  unsigned __int8 *v18; // ebx
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  unsigned __int8 *v22; // esi
  int v23; // esi
  unsigned int v24; // ebx
  unsigned __int8 *v25; // edx
  int v26; // edx
  float v27; // xmm2_4
  int i; // ecx
  unsigned __int8 *v29; // eax
  double v30; // st6
  int v31; // eax
  int v32; // ebx
  float v33; // xmm0_4
  unsigned __int8 *v34; // eax
  double v35; // st6
  int v36; // eax
  int v37; // ebx
  float v38; // xmm0_4
  unsigned __int8 *v39; // eax
  double v40; // st6
  int v41; // eax
  int v42; // ebx
  float v43; // xmm0_4
  void (__thiscall *SwapBuffers)(IMaterialSystem *); // eax
  char *v45; // esi
  int j; // edi
  int v47; // esi
  int k; // esi
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  FloatCubeMap_t v55; // [esp+18h] [ebp-1B88h] BYREF
  char basename[100]; // [esp+12F0h] [ebp-8B0h] BYREF
  FloatBitMap_t v57; // [esp+16F0h] [ebp-4B0h] BYREF
  _DWORD v58[61]; // [esp+1A14h] [ebp-18Ch] BYREF
  ImageLoader::ResampleInfo_t v59; // [esp+1B08h] [ebp-98h] BYREF
  int v60; // [esp+1B5Ch] [ebp-44h]
  int v61; // [esp+1B60h] [ebp-40h]
  unsigned __int8 *v62; // [esp+1B64h] [ebp-3Ch]
  int v63; // [esp+1B68h] [ebp-38h]
  int v64; // [esp+1B6Ch] [ebp-34h]
  unsigned __int8 *v65; // [esp+1B70h] [ebp-30h]
  unsigned __int8 *v66; // [esp+1B74h] [ebp-2Ch]
  unsigned __int8 *v67; // [esp+1B78h] [ebp-28h]
  unsigned __int8 *v68; // [esp+1B7Ch] [ebp-24h] BYREF
  float v69; // [esp+1B80h] [ebp-20h]
  const char *v70; // [esp+1B84h] [ebp-1Ch]
  unsigned __int8 *v71; // [esp+1B88h] [ebp-18h]
  int v72; // [esp+1B8Ch] [ebp-14h] BYREF
  int v73; // [esp+1B90h] [ebp-10h]
  unsigned __int8 *v74; // [esp+1B94h] [ebp-Ch]
  char v75; // [esp+1B9Bh] [ebp-5h]
  int v76; // [esp+1B9Ch] [ebp-4h]

  LODWORD(v5) = screenBufSize;
  if ( !g_LostVideoMemory )
  {
    GetRenderContext = materials->GetRenderContext;
    v61 = 0;
    v7 = (int)GetRenderContext(this: materials);
    v63 = v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    if ( tgaSize )
    {
      v61 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 28))(a1: v7);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 24))(a1: v7, a2: 0);
    }
    memset(dst: (unsigned __int8 *)v58, value: 0, count: sizeof(v58));
    v9 = origin;
    x = origin->x;
    LOBYTE(v58[60]) |= 2u;
    *(float *)&v58[24] = x;
    v58[25] = LODWORD(origin->y);
    v58[26] = LODWORD(origin->z);
    v58[34] = 1065353216;
    v58[0] = 0;
    v58[1] = 0;
    v58[30] = 1090519040;
    v58[31] = 1188945920;
    v58[2] = 512;
    v58[3] = 512;
    v70 = ".tga";
    if ( tgaSize )
      v70 = ".pfm";
    CColorBalanceUIPanel::Init(this: v8);
    if ( tgaSize )
    {
      ((void (__thiscall *)(IMaterialSystem *, int *, unsigned __int8 **, int))materials->GetBackBufferDimensions)(
        a1: materials,
        a2: &v72,
        a3: &v68,
        a4: a1);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, int, unsigned __int8 *))(*(_DWORD *)v7 + 152))(
        a1: v7,
        a2: 0,
        a3: 0,
        a4: v72,
        a5: v68);
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v7 + 292))(a1: v7, a2: 128, a3: 128, a4: 128);
      (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v7 + 48))(a1: v7, a2: 1, a3: 1, a4: 0);
      FloatCubeMap_t::FloatCubeMap_t(
        this: &v55,
        xfsize: (unsigned __int8 *)screenBufSize,
        yfsize: (unsigned __int8 *)screenBufSize);
      HIDWORD(v5) = 0;
      v72 = 0;
      do
      {
        v11 = *(_DWORD *)((char *)angle0 + HIDWORD(v5));
        v58[22] = 1119092736;
        v58[23] = 1119092736;
        v12 = v9->x;
        v58[27] = v11;
        v13 = *(_DWORD *)((char *)angle1 + HIDWORD(v5));
        *(float *)&v58[24] = v12;
        y = v9->y;
        v58[28] = v13;
        *(float *)&v58[25] = y;
        z = v9->z;
        v58[29] = 0;
        *(float *)&v58[26] = z;
        if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_INTEGER )
        {
          HIDWORD(v5) = (char *)&v55 + 804 * *(int *)((char *)engine_cubemap_idx_to_fbm_idx + HIDWORD(v5));
          v60 = HIDWORD(v5);
          FloatBitMap_t::Clear(this: (FloatBitMap_t *)HIDWORD(v5), r: 0.0, g: 0.0, b: 0.0, a: 1.0);
          v69 = 16.0;
          do
          {
            if ( v69 <= 0.05 )
              break;
            ConVar::SetValue(this: (ConVar *)&mat_force_tonemap_scale.IConVar, value: v69);
            g_ClientDLL->RenderView(this: g_ClientDLL, a2: (const CViewSetup *)v58, a3: 7, a4: 0);
            v67 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x100000u);
            v16 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 4 * LODWORD(v5) * LODWORD(v5));
            v17 = *(void (__thiscall **)(int, _DWORD, _DWORD, int, int, unsigned __int8 *, _DWORD))(*(_DWORD *)v63 + 52);
            v18 = v16;
            v62 = v16;
            v17(a1: v63, a2: 0, a3: 0, a4: 512, a5: 512, a6: v67, a7: 0);
            v59.m_nSrcDepth = 1;
            v59.m_nDestDepth = 1;
            v59.m_pSrc = v67;
            v59.m_flAlphaThreshhold = 0.40000001;
            v59.m_flAlphaHiFreqThreshhold = 0.40000001;
            v59.m_nFlags = 0;
            v59.m_flColorScale[0] = 1.0;
            v59.m_flColorScale[1] = 1.0;
            v59.m_flColorScale[2] = 1.0;
            v59.m_flColorScale[3] = 1.0;
            memset(v59.m_flColorGoal, 0, sizeof(v59.m_flColorGoal));
            v59.m_pDest = v18;
            v59.m_nSrcWidth = 512;
            v59.m_nSrcHeight = 512;
            v59.m_nDestWidth = LODWORD(v5);
            v59.m_nDestHeight = LODWORD(v5);
            v59.m_flSrcGamma = 1.0;
            v59.m_flDestGamma = 1.0;
            if ( ImageLoader::ResampleRGBA8888(a1: v5, info: &v59) == 0 )
              Sys_Error(error: "Can't resample\n");
            FloatBitMap_t::FloatBitMap_t(
              this: &v57,
              nWidth: (unsigned __int8 *)LODWORD(v5),
              nHeight: (unsigned __int8 *)LODWORD(v5),
              nDepth: 1,
              nAttributeMask: 15);
            v19 = 0;
            if ( SLODWORD(v5) > 0 )
            {
              v65 = v18 + 2;
              v66 = &v18[4 * LODWORD(v5) + 2];
              do
              {
                v20 = 0;
                if ( SLODWORD(v5) >= 4 )
                {
                  v74 = &v62[8 * LODWORD(v5) + 2 + 4 * LODWORD(v5) + 4 * v19];
                  v73 = 16 * LODWORD(v5);
                  HIDWORD(v5) = v65;
                  v64 = (int)&v62[8 * screenBufSize + 2 + 4 * v19];
                  v21 = 2;
                  v68 = v65;
                  v71 = v66;
                  do
                  {
                    v76 = *(unsigned __int8 *)(HIDWORD(v5) - 2);
                    *(float *)&v57.m_pAttributePtrs[0][v20 * v57.m_nRowStrideInBytes[0] + v19 * v57.m_nStrideInBytes[0]] = (double)v76 * 0.00392156862745098;
                    v76 = *(unsigned __int8 *)(HIDWORD(v5) - 1);
                    *(float *)&v57.m_pAttributePtrs[1][v20 * v57.m_nRowStrideInBytes[1] + v19 * v57.m_nStrideInBytes[1]] = (double)v76 * 0.00392156862745098;
                    v76 = (unsigned __int8)*(_BYTE *)HIDWORD(v5);
                    *(float *)&v57.m_pAttributePtrs[2][v20 * v57.m_nRowStrideInBytes[2] + v19 * v57.m_nStrideInBytes[2]] = (double)v76 * 0.00392156862745098;
                    v76 = *(v71 - 2);
                    *(float *)&v57.m_pAttributePtrs[0][v19 * v57.m_nStrideInBytes[0]
                                                     + v57.m_nRowStrideInBytes[0] * (v21 - 1)] = (double)v76
                                                                                               * 0.00392156862745098;
                    v76 = *(v71 - 1);
                    *(float *)&v57.m_pAttributePtrs[1][v19 * v57.m_nStrideInBytes[1]
                                                     + v57.m_nRowStrideInBytes[1] * (v21 - 1)] = (double)v76
                                                                                               * 0.00392156862745098;
                    v76 = *v71;
                    *(float *)&v57.m_pAttributePtrs[2][v19 * v57.m_nStrideInBytes[2]
                                                     + v57.m_nRowStrideInBytes[2] * (v21 - 1)] = (double)v76
                                                                                               * 0.00392156862745098;
                    v22 = (unsigned __int8 *)v64;
                    v76 = *(unsigned __int8 *)(v64 - 2);
                    *(float *)&v57.m_pAttributePtrs[0][v19 * v57.m_nStrideInBytes[0] + v57.m_nRowStrideInBytes[0] * v21] = (double)v76 * 0.00392156862745098;
                    v76 = *(v22 - 1);
                    v20 += 4;
                    *(float *)&v57.m_pAttributePtrs[1][v19 * v57.m_nStrideInBytes[1] + v57.m_nRowStrideInBytes[1] * v21] = (double)v76 * 0.00392156862745098;
                    v76 = *v22;
                    *(float *)&v57.m_pAttributePtrs[2][v19 * v57.m_nStrideInBytes[2] + v57.m_nRowStrideInBytes[2] * v21] = (double)v76 * 0.00392156862745098;
                    v76 = *(v74 - 2);
                    v23 = v21 + 1;
                    v24 = v57.m_nRowStrideInBytes[0] * (v21 + 1);
                    v21 += 4;
                    *(float *)&v57.m_pAttributePtrs[0][v19 * v57.m_nStrideInBytes[0] + v24] = (double)v76
                                                                                            * 0.00392156862745098;
                    v76 = *(v74 - 1);
                    *(float *)&v57.m_pAttributePtrs[1][v19 * v57.m_nStrideInBytes[1] + v57.m_nRowStrideInBytes[1] * v23] = (double)v76 * 0.00392156862745098;
                    v76 = *v74;
                    *(float *)&v57.m_pAttributePtrs[2][v19 * v57.m_nStrideInBytes[2] + v57.m_nRowStrideInBytes[2] * v23] = (double)v76 * 0.00392156862745098;
                    v71 += v73;
                    v64 += v73;
                    v74 += v73;
                    HIDWORD(v5) = &v68[v73];
                    LODWORD(v5) = screenBufSize;
                    v68 += v73;
                  }
                  while ( v20 < screenBufSize - 3 );
                  HIDWORD(v5) = v60;
                  v18 = v62;
                }
                if ( v20 < SLODWORD(v5) )
                {
                  v74 = &v18[4 * v19 + 2 + 4 * LODWORD(v5) * v20];
                  do
                  {
                    v73 = *(v74 - 2);
                    *(float *)&v57.m_pAttributePtrs[0][v20 * v57.m_nRowStrideInBytes[0] + v19 * v57.m_nStrideInBytes[0]] = (double)v73 * 0.00392156862745098;
                    v73 = *(v74 - 1);
                    *(float *)&v57.m_pAttributePtrs[1][v20 * v57.m_nRowStrideInBytes[1] + v19 * v57.m_nStrideInBytes[1]] = (double)v73 * 0.00392156862745098;
                    v73 = *v74;
                    v25 = &v57.m_pAttributePtrs[2][v20 * v57.m_nRowStrideInBytes[2]];
                    ++v20;
                    *(float *)&v25[v19 * v57.m_nStrideInBytes[2]] = (double)v73 * 0.00392156862745098;
                    v74 += 4 * LODWORD(v5);
                  }
                  while ( v20 < SLODWORD(v5) );
                  v18 = v62;
                }
                v65 += 4;
                v66 += 4;
                ++v19;
              }
              while ( v19 < SLODWORD(v5) );
            }
            free(pMem: v67);
            free(pMem: v18);
            FloatBitMap_t::RaiseToPower(this: &v57, a2: (int)v18, a3: v5, power: 2.2);
            v26 = 0;
            v75 = 0;
            *(float *)&v73 = 1.0 / v69;
            if ( (int)*(_DWORD *)HIDWORD(v5) > 0 )
            {
              v27 = *(float *)&v73;
              do
              {
                for ( i = 0; i < *(_DWORD *)(HIDWORD(v5) + 4); *(float *)(v41 + v42) = v43 )
                {
                  v29 = &v57.m_pAttributePtrs[0][i * v57.m_nRowStrideInBytes[0]];
                  v30 = *(float *)&v29[v26 * v57.m_nStrideInBytes[0]];
                  v74 = *(unsigned __int8 **)&v29[v26 * v57.m_nStrideInBytes[0]];
                  if ( v30 > 0.98 )
                    v75 = 1;
                  v31 = i * *(_DWORD *)(HIDWORD(v5) + 408) + v26 * *(_DWORD *)(HIDWORD(v5) + 280);
                  v32 = *(_DWORD *)(HIDWORD(v5) + 24);
                  v33 = *(float *)&v74 * v27;
                  if ( *(float *)(v31 + v32) > (float)(*(float *)&v74 * v27) )
                    v33 = *(float *)(v31 + v32);
                  *(float *)(v31 + v32) = v33;
                  v34 = &v57.m_pAttributePtrs[1][i * v57.m_nRowStrideInBytes[1]];
                  v35 = *(float *)&v34[v26 * v57.m_nStrideInBytes[1]];
                  v74 = *(unsigned __int8 **)&v34[v26 * v57.m_nStrideInBytes[1]];
                  if ( v35 > 0.98 )
                    v75 = 1;
                  v36 = v26 * *(_DWORD *)(HIDWORD(v5) + 284) + i * *(_DWORD *)(HIDWORD(v5) + 412);
                  v37 = *(_DWORD *)(HIDWORD(v5) + 28);
                  v38 = *(float *)&v74 * v27;
                  if ( *(float *)(v36 + v37) > (float)(*(float *)&v74 * v27) )
                    v38 = *(float *)(v36 + v37);
                  *(float *)(v36 + v37) = v38;
                  v39 = &v57.m_pAttributePtrs[2][i * v57.m_nRowStrideInBytes[2]];
                  v40 = *(float *)&v39[v26 * v57.m_nStrideInBytes[2]];
                  v74 = *(unsigned __int8 **)&v39[v26 * v57.m_nStrideInBytes[2]];
                  if ( v40 > 0.98 )
                    v75 = 1;
                  v41 = v26 * *(_DWORD *)(HIDWORD(v5) + 288) + i * *(_DWORD *)(HIDWORD(v5) + 416);
                  v42 = *(_DWORD *)(HIDWORD(v5) + 32);
                  v43 = *(float *)&v74 * v27;
                  if ( *(float *)(v41 + v42) > (float)(*(float *)&v74 * v27) )
                    v43 = *(float *)(v41 + v42);
                  ++i;
                }
                ++v26;
              }
              while ( v26 < *(_DWORD *)HIDWORD(v5) );
            }
            SwapBuffers = materials->SwapBuffers;
            v69 = v69 * 0.75;
            SwapBuffers(this: materials);
            CSOAContainer::~CSOAContainer(this: &v57);
            v9 = origin;
          }
          while ( v75 != 0 );
          ConVar::SetValue(this: (ConVar *)&mat_force_tonemap_scale.IConVar, value: 0.0);
          V_snprintf(
            pDest: basename,
            maxLen: 1024,
            pFormat: "%s%s%s",
            pFileNameBase,
            *(const char **)((char *)facingName + v72),
            v70);
          HIDWORD(v5) = v72;
        }
        else
        {
          g_ClientDLL->RenderView(this: g_ClientDLL, a2: (const CViewSetup *)v58, a3: 7, a4: 0);
          V_snprintf(
            pDest: basename,
            maxLen: 1024,
            pFormat: "%s%s%s",
            pFileNameBase,
            *(const char **)((char *)facingName + HIDWORD(v5)),
            v70);
          videomode->TakeSnapshotTGARect(
            this: videomode,
            a2: basename,
            a3: 0,
            a4: 0,
            a5: 512,
            a6: 512,
            a7: LODWORD(v5),
            a8: LODWORD(v5),
            a9: tgaSize,
            a10: *(CubeMapFaceIndex_t *)((char *)face_idx + HIDWORD(v5)));
        }
        HIDWORD(v5) += 4;
        v72 = HIDWORD(v5);
      }
      while ( SHIDWORD(v5) < 24 );
      if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_INTEGER )
      {
        V_snprintf(pDest: basename, maxLen: 1024, pFormat: "%s", pFileNameBase);
        FloatCubeMap_t::WritePFMs(this: &v55, basename);
      }
      v45 = basename;
      for ( j = 5; j >= 0; --j )
      {
        v45 -= 804;
        CSOAContainer::~CSOAContainer(this: (CSOAContainer *)v45);
      }
      materials->SwapBuffers(this: materials);
      v47 = v63;
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v63 + 24))(a1: v63, a2: v61);
    }
    else
    {
      for ( k = 0; k < 6; ++k )
      {
        v49 = angle0[k];
        v58[22] = 1119092736;
        v58[23] = 1119092736;
        v50 = origin->x;
        *(float *)&v58[27] = v49;
        v51 = angle1[k];
        *(float *)&v58[24] = v50;
        v52 = origin->y;
        *(float *)&v58[28] = v51;
        *(float *)&v58[25] = v52;
        v53 = origin->z;
        v58[29] = 0;
        *(float *)&v58[26] = v53;
        g_ClientDLL->RenderView(this: g_ClientDLL, a2: (const CViewSetup *)v58, a3: 7, a4: 0);
        V_snprintf(pDest: basename, maxLen: 1024, pFormat: "%s%s%s", pFileNameBase, facingName[k], v70);
        videomode->TakeSnapshotTGARect(
          this: videomode,
          a2: basename,
          a3: 0,
          a4: 0,
          a5: 512,
          a6: 512,
          a7: screenBufSize,
          a8: screenBufSize,
          a9: false,
          a10: face_idx[k]);
      }
      v47 = v63;
    }
    if ( v47 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v47 + 12))(a1: v47);
      (*(void (__thiscall **)(int))(*(_DWORD *)v47 + 4))(a1: v47);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100691E0
// Name: BuildSingleCubemap
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildSingleCubemap(
        char *pVTFName@<edi>,
        CCubemapCollection *pCC@<eax>,
        const Vector *vecOrigin,
        int nSize,
        int bHDR,
        const char *pGameDir,
        IVTex *ivt)
{
  void *v8; // esi
  int (__thiscall *VTex)(IVTex *, void *(__cdecl *)(const char *, int *), const char *, int, char **); // edx
  const char *v10; // ebx
  const char **v11; // esi
  char pTXTName[260]; // [esp+8h] [ebp-20Ch] BYREF
  char pDest[4]; // [esp+10Ch] [ebp-108h] BYREF
  char *argv[64]; // [esp+110h] [ebp-104h] BYREF
  CUtlSymbol result; // [esp+210h] [ebp-4h] BYREF
  CUtlSymbol v16; // [esp+212h] [ebp-2h] BYREF

  if ( pCC != nullptr )
  {
    if ( CUtlSymbolTable::Find(this: &pCC->m_arrEntries, &result, pString: pVTFName)->m_Id != 0xFFFF )
      return;
    CUtlSymbolTable::AddString(this: &pCC->m_arrEntries, result: &v16, pString: pVTFName);
  }
  TakeCubemapSnapshot(a1: bHDR, origin: vecOrigin, pFileNameBase: pVTFName, screenBufSize: nSize, tgaSize: bHDR);
  V_strncpy(pDest: pTXTName, pSrc: pVTFName, maxLen: 260);
  V_SetExtension(path: pTXTName, extension: ".txt", pathStringLength: 260);
  v8 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pTXTName, a3: "w", a4: 0);
  if ( (_BYTE)bHDR != 0 )
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "\"pfm\" \"1\"\n");
  g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "\"stripalphachannel\" \"1\"\n");
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v8);
  if ( ivt != nullptr )
  {
    VTex = ivt->VTex;
    argv[5] = pTXTName;
    argv[0] = (char *)defaultValue;
    argv[1] = "-oldcubepath";
    argv[2] = "-quiet";
    argv[3] = "-UseStandardError";
    argv[4] = "-WarningsAsErrors";
    VTex(this: ivt, a2: (void *(__cdecl *)(const char *, int *))CubemapsFSFactory, a3: pGameDir, a4: 6, a5: argv);
  }
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: pTXTName, a3: nullptr);
  v10 = ".pfm";
  if ( (_BYTE)bHDR == 0 )
    v10 = ".tga";
  v11 = facingName;
  do
  {
    V_snprintf(pDest, maxLen: 260, pFormat: "%s%s", pVTFName, *v11);
    V_SetExtension(path: pDest, extension: v10, pathStringLength: 260);
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: pDest, a3: nullptr);
    ++v11;
  }
  while ( (int)v11 < (int)&saveShadows );
}

//------------------------------------------------------------------------------
// Address: 0x100693A0
// Name: envmap
// Source: json
//------------------------------------------------------------------------------
void __usercall envmap(int a1@<ebx>)
{
  IClientEntity *v1; // eax
  IClientRenderable *v2; // esi
  IModelLoader_vtbl *v3; // edi
  int v4; // eax
  const char *v5; // eax
  unsigned int v6; // kr00_4
  void *v7; // esp
  int m_nValue; // esi
  HDRType_t v9; // eax
  char v10[8]; // [esp+0h] [ebp-108h] BYREF
  char base[256]; // [esp+8h] [ebp-100h] BYREF

  v1 = entitylist->GetClientEntity(this: entitylist, a2: 0);
  if ( v1 != nullptr && (v2 = &v1->IClientRenderable, v1->GetModel(this: &v1->IClientRenderable) != nullptr) )
  {
    v3 = modelloader->__vftable;
    v4 = (int)v2->GetModel(this: v2);
    v5 = v3->GetName(this: modelloader, a2: (const model_t *)v4);
    V_FileBase(in: v5, out: base, maxlen: 256);
  }
  else
  {
    V_strncpy(pDest: base, pSrc: "Env", maxLen: 256);
  }
  v6 = strlen(base);
  v7 = alloca(v6 + 21);
  V_snprintf(pDest: v10, maxLen: v6 + 21, pFormat: "cubemap_screenshots/%s", base);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "cubemap_screenshots", a3: "DEFAULT_WRITE_PATH");
  if ( mat_envmaptgasize.m_pParent != nullptr )
    m_nValue = mat_envmaptgasize.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig);
  TakeCubemapSnapshot(
    a1,
    origin: g_MainViewOrigin,
    pFileNameBase: v10,
    screenBufSize: m_nValue,
    tgaSize: v9 != HDR_TYPE_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x100694B0
// Name: LoadSrcVTFFiles
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadSrcVTFFiles(IVTFTexture **pSrcVTFTextures, const char *pSkyboxBaseName)
{
  int v2; // eax
  IVTFTexture **v3; // esi
  IVTFTexture *VTFTexture; // eax
  IVTFTexture *v5; // edi
  int v6; // eax
  int (__thiscall *Width)(IVTFTexture *); // edx
  int v8; // eax
  IVTFTexture *v9; // edi
  int v10; // eax
  int (__thiscall *Height)(IVTFTexture *); // edx
  int v12; // eax
  IVTFTexture *v13; // edi
  int v14; // eax
  int (__thiscall *v15)(IVTFTexture *); // edx
  int v16; // eax
  IVTFTexture *v17; // edi
  int v18; // eax
  int (__thiscall *Flags)(IVTFTexture *); // edx
  int v20; // eax
  char srcVTFFileName[1024]; // [esp+Ch] [ebp-43Ch] BYREF
  CUtlBuffer buf; // [esp+40Ch] [ebp-3Ch] BYREF
  int j; // [esp+43Ch] [ebp-Ch]
  int i; // [esp+440h] [ebp-8h]
  int v26; // [esp+444h] [ebp-4h]

  v2 = (char *)facingName - (char *)pSrcVTFTextures;
  i = 0;
  v3 = pSrcVTFTextures;
  for ( j = (char *)facingName - (char *)pSrcVTFTextures; ; v2 = j )
  {
    V_snprintf(
      pDest: srcVTFFileName,
      maxLen: 1024,
      pFormat: "materials/skybox/%s%s.vtf",
      pSkyboxBaseName,
      *(const char **)((char *)v3 + v2));
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    if ( !g_pFileSystem->ReadFile(
            this: &g_pFileSystem->IBaseFileSystem,
            a2: srcVTFFileName,
            a3: nullptr,
            a4: &buf,
            a5: 0,
            a6: 0,
            a7: nullptr) )
      break;
    VTFTexture = CreateVTFTexture();
    *v3 = VTFTexture;
    if ( !VTFTexture->Unserialize(this: VTFTexture, a2: &buf, a3: false, a4: 0) )
    {
      _Warning(a1: "*** Error unserializing skybox texture: %s\n", pSkyboxBaseName);
      break;
    }
    v5 = *v3;
    v6 = (*pSrcVTFTextures)->Width(this: *pSrcVTFTextures);
    Width = v5->Width;
    v26 = v6;
    v8 = Width(this: v5);
    if ( v8 != v26 && (*v3)->Width(this: *v3) != 4 )
      goto LABEL_21;
    v9 = *v3;
    v10 = (*pSrcVTFTextures)->Height(this: *pSrcVTFTextures);
    Height = v9->Height;
    v26 = v10;
    v12 = Height(this: v9);
    if ( v12 != v26 )
    {
      v13 = *v3;
      v14 = (*pSrcVTFTextures)->Height(this: *pSrcVTFTextures);
      v15 = v13->Height;
      v26 = 2 * v14;
      v16 = v15(this: v13);
      if ( v16 != v26 && (*v3)->Height(this: *v3) != 4 )
        goto LABEL_21;
    }
    v17 = *v3;
    v18 = (*pSrcVTFTextures)->Flags(this: *pSrcVTFTextures);
    Flags = v17->Flags;
    v26 = v18;
    v20 = Flags(this: v17);
    if ( v20 != v26 )
    {
LABEL_21:
      _Warning(
        a1: "*** Error: Skybox vtf files for %s weren't compiled with the same size texture and/or same flags!\n",
        pSkyboxBaseName);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 0;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    ++v3;
    if ( ++i >= 6 )
      return 1;
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10069690
// Name: void Cubemap_CreateDefaultCubemap(char const __near *,class IBSPPack __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall Cubemap_CreateDefaultCubemap(int a1@<ebx>, int a2@<edi>, const char *pMapName, IBSPPack *iBSPPack)
{
  char *m_pszString; // esi
  IVTFTexture *v5; // edi
  int (__thiscall *Width)(IVTFTexture *); // eax
  int v7; // esi
  int v8; // eax
  IVTFTexture *VTFTexture; // esi
  IVTFTexture_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int (__thiscall *FrameCount)(IVTFTexture *); // edx
  int v15; // ebx
  int v16; // edi
  IVTFTexture *v17; // ebx
  unsigned __int8 *v18; // eax
  IVTFTexture_vtbl *v19; // edx
  int v20; // eax
  int (__thiscall *ComputeMipSize)(IVTFTexture *, int); // edx
  int (__thiscall *v22)(IVTFTexture *); // eax
  int v23; // edi
  __int16 v24; // bx
  int i; // edi
  __int16 v26; // ax
  unsigned int v27; // edi
  unsigned int j; // eax
  int k; // edi
  char dstVTFFileName[1024]; // [esp+4h] [ebp-464h] BYREF
  CUtlBuffer outputBuf; // [esp+404h] [ebp-64h] BYREF
  IVTFTexture *pSrcVTFTextures[6]; // [esp+434h] [ebp-34h] BYREF
  ConVarRef skyboxBaseNameConVar; // [esp+44Ch] [ebp-1Ch] BYREF
  int iSize; // [esp+454h] [ebp-14h]
  unsigned __int8 *pDstBits; // [esp+458h] [ebp-10h]
  int iFace; // [esp+45Ch] [ebp-Ch]
  int iMipLevelOffset; // [esp+460h] [ebp-8h]
  int iFrame; // [esp+464h] [ebp-4h]

  ConVarRef::ConVarRef(this: &skyboxBaseNameConVar, pName: "sv_skyname");
  if ( ConVarRef::IsValid(this: &skyboxBaseNameConVar)
    && (m_pszString = skyboxBaseNameConVar.m_pConVarState->m_Value.m_pszString) != nullptr )
  {
    if ( LoadSrcVTFFiles(pSrcVTFTextures, pSkyboxBaseName: skyboxBaseNameConVar.m_pConVarState->m_Value.m_pszString) != 0 )
    {
      _Msg(a1: "Creating default cubemaps for env_cubemap using skybox %s...\n", m_pszString);
      v5 = pSrcVTFTextures[0];
      Width = pSrcVTFTextures[0]->Width;
      v7 = 0;
      iMipLevelOffset = 0;
      v8 = ((int (__thiscall *)(IVTFTexture *, int))Width)(a1: pSrcVTFTextures[0], a2);
      if ( v8 > 32 )
      {
        do
        {
          v8 >>= 1;
          ++v7;
        }
        while ( v8 > 32 );
        iMipLevelOffset = v7;
      }
      VTFTexture = CreateVTFTexture();
      v10 = VTFTexture->__vftable;
      v11 = ((int (__thiscall *)(IVTFTexture *, int, int))v5->FrameCount)(a1: v5, a2: -1, a3: a1);
      v12 = ((int (__thiscall *)(IVTFTexture *, int))v5->Flags)(a1: v5, a2: v11);
      v13 = ((int (__thiscall *)(IVTFTexture *, int))v5->Format)(a1: v5, a2: v12 | 0x4000);
      ((void (__thiscall *)(IVTFTexture *, int, int, int, int))v10->Init)(
        a1: VTFTexture,
        a2: 32,
        a3: 32,
        a4: 1,
        a5: v13);
      FrameCount = VTFTexture->FrameCount;
      iFrame = 0;
      if ( FrameCount(this: VTFTexture) > 0 )
      {
        do
        {
          v15 = 0;
          iFace = 0;
          do
          {
            v16 = 0;
            if ( VTFTexture->MipCount(this: VTFTexture) > 0 )
            {
              v17 = pSrcVTFTextures[v15];
              do
              {
                v17->ImageData_2(this: v17, a2: iFrame, a3: 0, a4: v16 + iMipLevelOffset);
                v18 = VTFTexture->ImageData_2(this: VTFTexture, a2: iFrame, a3: iFace, a4: v16);
                v19 = VTFTexture->__vftable;
                pDstBits = v18;
                v20 = v19->ComputeMipSize(this: VTFTexture, a2: v16);
                ComputeMipSize = v17->ComputeMipSize;
                iSize = v20;
                ComputeMipSize(this: v17, a2: v16 + iMipLevelOffset);
                memset(dst: pDstBits, value: 0, count: iSize);
                ++v16;
              }
              while ( v16 < VTFTexture->MipCount(this: VTFTexture) );
              v15 = iFace;
            }
            iFace = ++v15;
          }
          while ( v15 < 6 );
          v22 = VTFTexture->FrameCount;
          v23 = ++iFrame;
        }
        while ( v23 < v22(this: VTFTexture) );
      }
      v24 = 0;
      for ( i = 0; i < 6; ++i )
      {
        v26 = pSrcVTFTextures[i]->Flags(this: pSrcVTFTextures[i]);
        v24 |= v26;
      }
      ((void (__thiscall *)(IVTFTexture *, int, _DWORD))VTFTexture->ConvertImageFormat)(a1: VTFTexture, a2: -2, a3: 0);
      if ( (v24 & 0x3000) == 0 )
      {
        v27 = (unsigned int)VTFTexture->ImageData_3(this: VTFTexture);
        for ( j = v27 + VTFTexture->ComputeTotalSize(this: VTFTexture); v27 < j; v27 += 4 )
          *(_BYTE *)(v27 + 3) = 0;
      }
      VTFTexture->FixCubemapFaceOrientation(this: VTFTexture);
      VTFTexture->GenerateSpheremap(this: VTFTexture, a2: LOOK_DOWN_Z);
      VTFTexture->ConvertImageFormat(this: VTFTexture, a2: IMAGE_FORMAT_DXT5, a3: false, a4: false);
      V_snprintf(pDest: dstVTFFileName, maxLen: 1024, pFormat: "materials/maps/%s/cubemapdefault.vtf", pMapName);
      CUtlBuffer::CUtlBuffer(this: &outputBuf, growSize: 0, initSize: 0, nFlags: 0);
      if ( VTFTexture->Serialize(this: VTFTexture, a2: &outputBuf) )
      {
        iBSPPack->AddBufferToPack(
          this: iBSPPack,
          a2: dstVTFFileName,
          a3: outputBuf.m_Memory.m_pMemory,
          a4: outputBuf.m_Put,
          a5: false);
        for ( k = 0; k < 6; ++k )
          DestroyVTFTexture(pTexture: pSrcVTFTextures[k]);
        DestroyVTFTexture(pTexture: VTFTexture);
      }
      else
      {
        _Warning(a1: "Error serializing default cubemap %s\n", dstVTFFileName);
      }
      if ( outputBuf.m_Memory.m_nGrowSize >= 0 && outputBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputBuf.m_Memory.m_pMemory);
    }
    else
    {
      _Warning(a1: "Can't load skybox file %s to build the default cubemap!\n", m_pszString);
    }
  }
  else
  {
    _Warning(a1: "Couldn't create default cubemap\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069990
// Name: void R_BuildCubemapSamples(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_BuildCubemapSamples(int a1@<ebx>, char *a2@<edi>, int numIterations)
{
  IBaseFileSystem_vtbl *v3; // esi
  CClientState *BaseLocalClient; // eax
  CClientState *v5; // eax
  int v6; // eax
  int v7; // esi
  const model_t *v8; // eax
  const char *v9; // ebx
  model_t *v10; // esi
  worldbrushdata_t *pShared; // eax
  int v12; // edi
  unsigned __int8 size; // al
  int v14; // eax
  int v15; // ebx
  int v16; // ecx
  int *p_m_nCubemapSamples; // eax
  int v18; // ebx
  int v19; // esi
  const char *v20; // eax
  char v21; // al
  int m_nValue; // eax
  worldbrushdata_t *v23; // eax
  struct CSysModule *Module; // eax
  struct CSysModule *v25; // edi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IBSPPack *v27; // ebx
  worldbrushdata_t *v28; // eax
  vgui::CTreeViewListControl *v29; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v31; // [esp-18h] [ebp-A90h]
  char mapPath[1024]; // [esp+4h] [ebp-A74h] BYREF
  char pTemp[260]; // [esp+404h] [ebp-674h] BYREF
  char pVTFName[260]; // [esp+508h] [ebp-570h] BYREF
  char gameDir[260]; // [esp+60Ch] [ebp-46Ch] BYREF
  char pMaterialSrcDir[260]; // [esp+710h] [ebp-368h] BYREF
  char matDir[260]; // [esp+814h] [ebp-264h] BYREF
  char mapName[256]; // [esp+918h] [ebp-160h] BYREF
  CCubemapCollection uniqueCubemaps; // [esp+A18h] [ebp-60h] BYREF
  ConVarRef drawMRMModelsCVar; // [esp+A50h] [ebp-28h] BYREF
  BOOL bOldLightSpritesActive; // [esp+A58h] [ebp-20h]
  IVTex *ivt; // [esp+A5Ch] [ebp-1Ch]
  struct CSysModule *pModule; // [esp+A60h] [ebp-18h] BYREF
  model_t *pWorldModel; // [esp+A64h] [ebp-14h]
  int i; // [esp+A68h] [ebp-10h]
  int bSupportsHDR; // [esp+A6Ch] [ebp-Ch]
  int bounce; // [esp+A70h] [ebp-8h]
  unsigned int v50; // [esp+A74h] [ebp-4h]

  v3 = g_pFileSystem->IBaseFileSystem::__vftable;
  BaseLocalClient = GetBaseLocalClient();
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))v3->IsFileWritable)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: BaseLocalClient->m_szLevelName) != 0 )
  {
    R_BuildCubemapSamples_PreBuild();
    bounce = 0;
    if ( numIterations <= 0 )
    {
LABEL_47:
      R_BuildCubemapSamples_PostBuild();
      UpdateMaterialSystemConfig();
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&reload_materials.IConVar, value: 1, (unsigned int)a2, a3: a1);
    }
    else
    {
      while ( 1 )
      {
        if ( bounce != 0 )
          CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "1", (int)a2);
        else
          CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "0", (int)a2);
        UpdateMaterialSystemConfig();
        v6 = ((int (__thiscall *)(IClientEntityList *, _DWORD, int))entitylist->GetClientEntity)(
               a1: entitylist,
               a2: 0,
               a3: a1);
        if ( v6 == 0 || (v7 = v6 + 4, (*(int (__thiscall **)(int))(*(_DWORD *)(v6 + 4) + 32))(a1: v6 + 4) == 0) )
        {
          _ConDMsg(a1: "R_BuildCubemapSamples: No map loaded!\n");
          R_BuildCubemapSamples_PostBuild();
          return;
        }
        v8 = (const model_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 32))(a1: v7);
        v9 = modelloader->GetName(this: modelloader, a2: v8);
        if ( V_stristr(pStr: v9, pSearch: "maps/") == v9 || V_stristr(pStr: v9, pSearch: "maps\\") == v9 )
        {
          V_strncpy(pDest: mapName, pSrc: v9 + 5, maxLen: 256);
          V_StripExtension(in: mapName, out: mapName, outSize: 256);
        }
        else
        {
          V_FileBase(in: v9, out: mapName, maxlen: 256);
        }
        ConVarRef::ConVarRef(this: &drawMRMModelsCVar, pName: "r_drawothermodels");
        if ( ConVarRef::IsValid(this: &drawMRMModelsCVar) )
          drawMRMModelsCVar.m_pConVar->SetValue_2(this: drawMRMModelsCVar.m_pConVar, a2: 0);
        LOBYTE(bOldLightSpritesActive) = ActivateLightSprites(bActive: true);
        ivt = VTex_Load(&pModule);
        if ( ivt == nullptr )
          return;
        V_snprintf(pDest: matDir, maxLen: 260, pFormat: "materials/maps/%s", mapName);
        g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: matDir, a3: "DEFAULT_WRITE_PATH");
        V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "materialsrc/maps/%s", mapName);
        GetModContentSubdirectory(pSubDir: pTemp, pBuf: pMaterialSrcDir, nBufLen: 260);
        g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pMaterialSrcDir, a3: nullptr);
        COM_GetGameDir(szGameDir: gameDir, maxlen: 260);
        v10 = (model_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 32))(a1: v7);
        pShared = v10->brush.pShared;
        v12 = 0;
        pWorldModel = v10;
        if ( pShared->m_nCubemapSamples > 0 )
          break;
LABEL_26:
        LOBYTE(bSupportsHDR) = g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE;
        CUtlSymbolTable::CUtlSymbolTable(
          this: &uniqueCubemaps.m_arrEntries,
          growSize: 0,
          initSize: 16,
          caseInsensitive: false);
        v16 = 0;
        p_m_nCubemapSamples = (int *)(v10->sprite.numframes + 232);
        if ( *p_m_nCubemapSamples > 0 )
        {
          i = bounce + 1;
          v50 = 0;
          do
          {
            v18 = v16 + 1;
            _Warning(a1: "bounce: %d/%d sample: %d/%d\n", i, numIterations, v16 + 1, *p_m_nCubemapSamples);
            v19 = v50 + *(_DWORD *)(v10->sprite.numframes + 228);
            v20 = "_hdr";
            if ( (_BYTE)bSupportsHDR == 0 )
              v20 = defaultValue;
            V_snprintf(
              pDest: pVTFName,
              maxLen: 260,
              pFormat: "%s/c%d_%d_%d%s",
              pMaterialSrcDir,
              (int)*(float *)v19,
              (int)*(float *)(v19 + 4),
              (int)*(float *)(v19 + 8),
              v20);
            v21 = *(_BYTE *)(v19 + 16);
            if ( v21 != 0 )
            {
              m_nValue = 1 << (v21 - 1);
            }
            else if ( mat_envmaptgasize.m_pParent != nullptr )
            {
              m_nValue = mat_envmaptgasize.m_pParent->m_Value.m_nValue;
            }
            else
            {
              m_nValue = 0;
            }
            BuildSingleCubemap(
              pVTFName,
              pCC: &uniqueCubemaps,
              vecOrigin: (const Vector *)v19,
              nSize: m_nValue,
              bHDR: bSupportsHDR,
              pGameDir: gameDir,
              ivt);
            v23 = pWorldModel->brush.pShared;
            v50 += 20;
            v16 = v18;
            p_m_nCubemapSamples = &v23->m_nCubemapSamples;
            v10 = pWorldModel;
          }
          while ( v18 < *p_m_nCubemapSamples );
        }
        CUtlSymbolTable::RemoveAll(this: &uniqueCubemaps.m_arrEntries);
        ActivateLightSprites(bActive: bOldLightSpritesActive);
        FileSystem_UnloadModule(pModule);
        Module = FileSystem_LoadModule(path: "bsppack");
        v25 = Module;
        pModule = Module;
        if ( Module == nullptr
          || (Factory = Sys_GetFactory(pModule: Module)) == nullptr
          || (v27 = (IBSPPack *)Factory(a1: "IBSPPACK003", a2: nullptr)) == nullptr )
        {
          ConMsg(a1: "Can't load bsppack.dll\n");
          R_BuildCubemapSamples_PostBuild();
          CUtlSymbolTable::~CUtlSymbolTable(this: &uniqueCubemaps.m_arrEntries);
          return;
        }
        a1 = bSupportsHDR;
        ((void (__thiscall *)(IBSPPack *))v27->SetHDRMode)(a1: v27);
        V_snprintf(pDest: mapPath, maxLen: 1024, pFormat: "maps/%s.bsp", mapName);
        v27->LoadBSPFile(this: v27, a2: g_pFileSystem, a3: mapPath);
        V_snprintf(pDest: matDir, maxLen: 260, pFormat: "materials/maps/%s", mapName);
        v28 = v10->brush.pShared;
        i = 0;
        if ( v28->m_nCubemapSamples > 0 )
        {
          v50 = 0;
          do
          {
            AddSampleToBSPFile(
              pSample: &v28->m_pCubemapSamples[v50 / 0x14],
              matDir,
              bHDR: bSupportsHDR,
              iBSPPack: v27,
              pCC: &uniqueCubemaps);
            v28 = pWorldModel->brush.pShared;
            v50 += 20;
            ++i;
          }
          while ( i < v28->m_nCubemapSamples );
          v25 = pModule;
        }
        CUtlSymbolTable::RemoveAll(this: &uniqueCubemaps.m_arrEntries);
        Cubemap_CreateDefaultCubemap(a1: (int)v27, a2: (int)v25, pMapName: mapName, iBSPPack: v27);
        a2 = mapPath;
        ((void (__thiscall *)(IBSPPack *))v27->WriteBSPFile)(a1: v27);
        v27->ClearPackFile(this: v27);
        FileSystem_UnloadModule(pModule: v25);
        if ( Host_IsSinglePlayerGame() )
          v31 = "restart setpos\n";
        else
          v31 = va(format: "map %s\n", mapName);
        TraceType = CTraceFilter::GetTraceType(this: v29);
        Cbuf_AddText(eTarget: TraceType, pText: v31, nTickDelay: 0);
        CUtlSymbolTable::~CUtlSymbolTable(this: &uniqueCubemaps.m_arrEntries);
        if ( ++bounce >= numIterations )
          goto LABEL_47;
      }
      v50 = 0;
      while ( 1 )
      {
        size = pShared->m_pCubemapSamples[v50 / 0x14].size;
        if ( size != 0 )
          v14 = 1 << (size - 1);
        else
          v14 = mat_envmaptgasize.m_pParent != nullptr ? mat_envmaptgasize.m_pParent->m_Value.m_nValue : 0;
        v15 = 4 * v14;
        if ( 4 * v14 > videomode->GetModeWidth(this: videomode) || v15 > videomode->GetModeHeight(this: videomode) )
          break;
        pShared = v10->brush.pShared;
        v50 += 20;
        if ( ++v12 >= pShared->m_nCubemapSamples )
          goto LABEL_26;
      }
      _Warning(
        a1: "Cube map buffer size %d x %d is bigger than screen!\n"
        "Run at a higher resolution! or reduce your cubemap resolution (needs 4X)\n",
        v15,
        v15);
      R_BuildCubemapSamples_PostBuild();
    }
  }
  else
  {
    v5 = GetBaseLocalClient();
    _Warning(a1: "%s is not writable!!!  Check it out before running buildcubemaps.\n", v5->m_szLevelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069F70
// Name: buildcubemaps
// Source: json
//------------------------------------------------------------------------------
void __usercall buildcubemaps(int a1@<ebx>, char *a2@<edi>, const CCommand *args)
{
  int v3; // eax
  bool bAllow; // [esp+0h] [ebp-4h]

  bAllow = Host_AllowQueuedMaterialSystem(bAllow: false);
  V_RenderVGuiOnly();
  if ( args->m_nArgc == 1 )
  {
    R_BuildCubemapSamples(a1, a2, numIterations: 1);
    Host_AllowQueuedMaterialSystem(bAllow);
  }
  else
  {
    if ( args->m_nArgc == 2 )
    {
      v3 = atoi(nptr: args->m_ppArgv[1]);
      R_BuildCubemapSamples(a1, a2, numIterations: v3);
    }
    else
    {
      ConMsg(a1: "Usage: buildcubemaps [numBounces]\n");
    }
    Host_AllowQueuedMaterialSystem(bAllow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A050
// Name: WriteLightProbe
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteLightProbe(const char *pBasePath@<eax>, const LightingState_t *state, bool bHDR)
{
  CDmxElement *DmxElement; // ebx
  const char *v5; // esi
  CDmxAttribute *v6; // eax
  CDmxAttribute *v7; // eax
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // eax
  CDmxAttribute *v10; // esi
  _DWORD *m_pData; // eax
  const LightingState_t *v12; // edx
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v13; // esi
  CVTFTexture::ResourceMemorySection *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CVTFTexture::ResourceMemorySection *v16; // ecx
  int v17; // eax
  CVTFTexture::ResourceMemorySection *v18; // eax
  bool v19; // zf
  CDmxAttribute *v20; // eax
  CDmxAttribute *v21; // esi
  _DWORD *v22; // eax
  CDmxElement *v23; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v24; // ebx
  int m_Size; // edi
  CDmxElement *v26; // esi
  int v27; // eax
  CDmxElement **v28; // ecx
  int v29; // eax
  CDmxElement **v30; // edi
  dworldlight_t *v31; // ebx
  CDmxAttribute *v32; // edi
  _DWORD *v33; // edi
  CDmxAttribute *v34; // eax
  CDmxAttribute *v35; // edi
  _DWORD *v36; // edi
  CDmxAttribute *v37; // edi
  float *v38; // edi
  float v39; // ecx
  float v40; // edx
  CDmxAttribute *v41; // edi
  float *v42; // edi
  CDmxAttribute *v43; // eax
  CDmxAttribute *v44; // edi
  _DWORD *v45; // edi
  CDmxAttribute *v46; // edi
  _DWORD *v47; // edi
  CDmxAttribute *v48; // edi
  float *v49; // edi
  float v50; // ecx
  float v51; // edx
  CDmxAttribute *v52; // edi
  float *v53; // edi
  long double v54; // st7
  CDmxAttribute *v55; // edi
  float *v56; // edi
  long double v57; // st7
  float exponent; // xmm0_4
  CDmxAttribute *v59; // edi
  float *v60; // edi
  CDmxAttribute *v61; // eax
  CDmxAttribute *v62; // edi
  _DWORD *v63; // edi
  CDmxAttribute *v64; // edi
  _DWORD *v65; // edi
  CDmxAttribute *v66; // edi
  _DWORD *v67; // edi
  int v68; // ecx
  int v69; // edx
  CDmxAttribute *v70; // edi
  _DWORD *v71; // edi
  CDmxAttribute *v72; // edi
  _DWORD *v73; // edi
  CDmxAttribute *v74; // edi
  _DWORD *v75; // edi
  CDmxAttribute *v76; // eax
  CDmxAttribute *v77; // edi
  _DWORD *v78; // edi
  CDmxElement *v79; // esi
  char pTemp[260]; // [esp+Ch] [ebp-278h] BYREF
  char pFullPath[260]; // [esp+110h] [ebp-174h] BYREF
  CUtlBuffer buf; // [esp+214h] [ebp-70h] BYREF
  float constant_attn; // [esp+244h] [ebp-40h]
  float linear_attn; // [esp+248h] [ebp-3Ch]
  float quadratic_attn; // [esp+24Ch] [ebp-38h]
  float stopdot2; // [esp+250h] [ebp-34h]
  float stopdot; // [esp+254h] [ebp-30h]
  int v88; // [esp+258h] [ebp-2Ch]
  int v89; // [esp+25Ch] [ebp-28h]
  int v90; // [esp+260h] [ebp-24h]
  float v91; // [esp+264h] [ebp-20h]
  float v92; // [esp+268h] [ebp-1Ch]
  float v93; // [esp+26Ch] [ebp-18h]
  CDmxElement *pLightProbe; // [esp+270h] [ebp-14h]
  CDmxElementModifyScope modify; // [esp+274h] [ebp-10h]
  int i; // [esp+278h] [ebp-Ch]
  float v97; // [esp+27Ch] [ebp-8h]
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *lights; // [esp+280h] [ebp-4h]
  const LightingState_t *bHDRa; // [esp+290h] [ebp+Ch]
  dworldlight_t **bHDRb; // [esp+290h] [ebp+Ch]

  V_strncpy(pDest: pFullPath, pSrc: pBasePath, maxLen: 260);
  V_SetExtension(path: pFullPath, extension: ".prb", pathStringLength: 260);
  BeginDMXContext();
  DmxElement = CreateDmxElement(pType: "DmeElement");
  pLightProbe = DmxElement;
  v5 = &pBasePath[_V_strlen(str: "materials/")];
  modify.m_pElement = DmxElement;
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  v6 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: (CDmxAttribute *)"name");
  CDmxAttribute::SetValue(this: v6, pString: "lightprobe");
  if ( DmxElement != nullptr )
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: (CDmxAttribute *)"cubemap");
  CDmxAttribute::SetValue(this: v7, pString: v5);
  if ( DmxElement != nullptr )
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
  if ( bHDR )
  {
    V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "%s_hdr", v5);
    CDmxElement::LockForChanges(this: DmxElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: (CDmxAttribute *)"cubemapHdr");
    CDmxAttribute::SetValue(this: v8, pString: pTemp);
    if ( DmxElement != nullptr )
      CDmxElement::LockForChanges(this: DmxElement, bLock: false);
  }
  v9 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: (CDmxAttribute *)"ambientCube");
  v10 = v9;
  if ( v9->m_Type != AT_VECTOR3_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v9, type: AT_VECTOR3_ARRAY);
    m_pData = v10->m_pData;
    if ( m_pData != nullptr )
    {
      *m_pData = 0;
      m_pData[1] = 0;
      m_pData[2] = 0;
      m_pData[3] = 0;
      m_pData[4] = 0;
    }
  }
  v12 = state;
  v13 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)v10->m_pData;
  bHDRa = state;
  lights = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)6;
  do
  {
    m_pMemory = v13[1].m_pMemory;
    m_nAllocationCount = v13->m_nAllocationCount;
    if ( (int)&m_pMemory->m_nDataAllocSize + 1 > m_nAllocationCount )
    {
      CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
        this: v13,
        num: (int)&m_pMemory->m_nDataAllocSize - m_nAllocationCount + 1);
      v12 = bHDRa;
    }
    ++v13[1].m_pMemory;
    v16 = v13->m_pMemory;
    v17 = (char *)v13[1].m_pMemory - (char *)m_pMemory - 1;
    v13[1].m_nAllocationCount = (int)v13->m_pMemory;
    if ( v17 > 0 )
    {
      _V_memmove(dest: &v16[(int)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 12 * v17);
      v12 = bHDRa;
    }
    v18 = &v13->m_pMemory[(_DWORD)m_pMemory];
    if ( v18 != nullptr )
    {
      v18->m_nDataAllocSize = LODWORD(v12->r_boxcolor[0].x);
      v18->m_nDataLength = LODWORD(v12->r_boxcolor[0].y);
      v18->m_pData = (unsigned __int8 *)LODWORD(v12->r_boxcolor[0].z);
    }
    v12 = (const LightingState_t *)((char *)v12 + 12);
    v19 = lights == (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)1;
    lights = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)((char *)lights - 1);
    bHDRa = v12;
  }
  while ( !v19 );
  v20 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: (CDmxAttribute *)"localLights");
  v21 = v20;
  if ( v20->m_Type == AT_FIRST_ARRAY_TYPE )
  {
    lights = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v20->m_pData;
  }
  else
  {
    CDmxAttribute::AllocateDataMemory(this: v20, type: AT_FIRST_ARRAY_TYPE);
    v22 = v21->m_pData;
    if ( v22 != nullptr )
    {
      *v22 = 0;
      v22[1] = 0;
      v22[2] = 0;
      v22[3] = 0;
      v22[4] = 0;
    }
    lights = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v21->m_pData;
  }
  if ( DmxElement != nullptr )
  {
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
    modify.m_pElement = nullptr;
  }
  i = 0;
  if ( state->numlights > 0 )
  {
    bHDRb = state->locallight;
    while ( 2 )
    {
      v23 = CreateDmxElement(pType: "DmeElement");
      v24 = lights;
      m_Size = lights->m_Size;
      v26 = v23;
      v27 = lights->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > v27 )
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)lights, num: m_Size - v27 + 1);
      ++v24->m_Size;
      v28 = v24->m_Memory.m_pMemory;
      v29 = v24->m_Size - m_Size - 1;
      v24->m_pElements = v24->m_Memory.m_pMemory;
      if ( v29 > 0 )
        _V_memmove(dest: &v28[m_Size + 1], src: &v28[m_Size], count: 4 * v29);
      v30 = &v24->m_Memory.m_pMemory[m_Size];
      if ( v30 != nullptr )
        *v30 = v26;
      CDmxElement::LockForChanges(this: v26, bLock: true);
      v31 = *bHDRb;
      CDmxElement::LockForChanges(this: v26, bLock: true);
      v32 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"color");
      CDmxAttribute::AllocateDataMemory(this: v32, type: AT_VECTOR3);
      v33 = v32->m_pData;
      if ( v33 != nullptr )
      {
        *v33 = LODWORD(v31->intensity.x);
        v33[1] = LODWORD(v31->intensity.y);
        v33[2] = LODWORD(v31->intensity.z);
      }
      if ( v26 != nullptr )
        CDmxElement::LockForChanges(this: v26, bLock: false);
      switch ( v31->type )
      {
        case emit_surface:
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v61 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"name");
          CDmxAttribute::SetValue(this: v61, pString: "Spot");
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v62 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"origin");
          CDmxAttribute::AllocateDataMemory(this: v62, type: AT_VECTOR3);
          v63 = v62->m_pData;
          if ( v63 != nullptr )
          {
            *v63 = LODWORD(v31->origin.x);
            v63[1] = LODWORD(v31->origin.y);
            v63[2] = LODWORD(v31->origin.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v64 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"direction");
          CDmxAttribute::AllocateDataMemory(this: v64, type: AT_VECTOR3);
          v65 = v64->m_pData;
          if ( v65 != nullptr )
          {
            *v65 = LODWORD(v31->normal.x);
            v65[1] = LODWORD(v31->normal.y);
            v65[2] = LODWORD(v31->normal.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          v88 = 0;
          v89 = 0;
          v90 = 1065353216;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v66 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"attenuation");
          CDmxAttribute::AllocateDataMemory(this: v66, type: AT_VECTOR3);
          v67 = v66->m_pData;
          if ( v67 != nullptr )
          {
            v68 = v89;
            v69 = v90;
            *v67 = v88;
            v67[1] = v68;
            v67[2] = v69;
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v70 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"theta");
          CDmxAttribute::AllocateDataMemory(this: v70, type: AT_FLOAT);
          v71 = v70->m_pData;
          if ( v71 != nullptr )
            *v71 = 0;
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v72 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"phi");
          CDmxAttribute::AllocateDataMemory(this: v72, type: AT_FLOAT);
          v73 = v72->m_pData;
          if ( v73 != nullptr )
            *v73 = 0;
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v74 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"exponent");
          CDmxAttribute::AllocateDataMemory(this: v74, type: AT_FLOAT);
          v75 = v74->m_pData;
          if ( v75 != nullptr )
            *v75 = 1065353216;
          goto LABEL_47;
        case emit_point:
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v34 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"name");
          CDmxAttribute::SetValue(this: v34, pString: "Point");
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v35 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"origin");
          CDmxAttribute::AllocateDataMemory(this: v35, type: AT_VECTOR3);
          v36 = v35->m_pData;
          if ( v36 != nullptr )
          {
            *v36 = LODWORD(v31->origin.x);
            v36[1] = LODWORD(v31->origin.y);
            v36[2] = LODWORD(v31->origin.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          constant_attn = v31->constant_attn;
          linear_attn = v31->linear_attn;
          quadratic_attn = v31->quadratic_attn;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v37 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"attenuation");
          CDmxAttribute::AllocateDataMemory(this: v37, type: AT_VECTOR3);
          v38 = (float *)v37->m_pData;
          if ( v38 != nullptr )
          {
            v39 = linear_attn;
            v40 = quadratic_attn;
            *v38 = constant_attn;
            v38[1] = v39;
            v38[2] = v40;
          }
          goto LABEL_47;
        case emit_spotlight:
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v43 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"name");
          CDmxAttribute::SetValue(this: v43, pString: "Spot");
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v44 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"origin");
          CDmxAttribute::AllocateDataMemory(this: v44, type: AT_VECTOR3);
          v45 = v44->m_pData;
          if ( v45 != nullptr )
          {
            *v45 = LODWORD(v31->origin.x);
            v45[1] = LODWORD(v31->origin.y);
            v45[2] = LODWORD(v31->origin.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v46 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"direction");
          CDmxAttribute::AllocateDataMemory(this: v46, type: AT_VECTOR3);
          v47 = v46->m_pData;
          if ( v47 != nullptr )
          {
            *v47 = LODWORD(v31->normal.x);
            v47[1] = LODWORD(v31->normal.y);
            v47[2] = LODWORD(v31->normal.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          v91 = v31->constant_attn;
          v92 = v31->linear_attn;
          v93 = v31->quadratic_attn;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v48 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"attenuation");
          CDmxAttribute::AllocateDataMemory(this: v48, type: AT_VECTOR3);
          v49 = (float *)v48->m_pData;
          if ( v49 != nullptr )
          {
            v50 = v92;
            v51 = v93;
            *v49 = v91;
            v49[1] = v50;
            v49[2] = v51;
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          stopdot = v31->stopdot;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v52 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"theta");
          CDmxAttribute::AllocateDataMemory(this: v52, type: AT_FLOAT);
          v53 = (float *)v52->m_pData;
          if ( v53 != nullptr )
          {
            v54 = acos(stopdot);
            *v53 = v54 + v54;
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          stopdot2 = v31->stopdot2;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v55 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"phi");
          CDmxAttribute::AllocateDataMemory(this: v55, type: AT_FLOAT);
          v56 = (float *)v55->m_pData;
          if ( v56 != nullptr )
          {
            v57 = acos(stopdot2);
            *v56 = v57 + v57;
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          exponent = v31->exponent;
          if ( exponent == 0.0 )
            exponent = 1.0;
          v97 = exponent;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v59 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"exponent");
          CDmxAttribute::AllocateDataMemory(this: v59, type: AT_FLOAT);
          v60 = (float *)v59->m_pData;
          if ( v60 != nullptr )
            *v60 = v97;
LABEL_47:
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v41 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"maxDistance");
          CDmxAttribute::AllocateDataMemory(this: v41, type: AT_FLOAT);
          v42 = (float *)v41->m_pData;
          if ( v42 != nullptr )
            *v42 = v31->radius;
          goto LABEL_105;
        case emit_skylight:
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v76 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"name");
          CDmxAttribute::SetValue(this: v76, pString: "Directional");
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v77 = CDmxElement::AddAttribute(this: v26, pAttributeName: (CDmxAttribute *)"direction");
          CDmxAttribute::AllocateDataMemory(this: v77, type: AT_VECTOR3);
          v78 = v77->m_pData;
          if ( v78 != nullptr )
          {
            *v78 = LODWORD(v31->normal.x);
            v78[1] = LODWORD(v31->normal.y);
            v78[2] = LODWORD(v31->normal.z);
          }
LABEL_105:
          if ( v26 != nullptr )
          {
            CDmxElement::LockForChanges(this: v26, bLock: false);
LABEL_107:
            if ( v26 != nullptr )
              CDmxElement::LockForChanges(this: v26, bLock: false);
          }
          ++bHDRb;
          if ( ++i >= state->numlights )
            break;
          continue;
        default:
          goto LABEL_107;
      }
      break;
    }
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
  v79 = pLightProbe;
  if ( SerializeDMX(&buf, pRoot: pLightProbe, pFileName: pFullPath) )
    g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFullPath, a3: "MOD", a4: &buf);
  CleanupDMX(pRoot: v79);
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( modify.m_pElement != nullptr )
    CDmxElement::LockForChanges(this: modify.m_pElement, bLock: false);
  EndDMXContext(bDecommitMemory: true);
}

//------------------------------------------------------------------------------
// Address: 0x1006A960
// Name: lightprobe
// Source: json
//------------------------------------------------------------------------------
void __usercall lightprobe(int a1@<ebx>, const CCommand *args)
{
  int m_nArgc; // eax
  bool v4; // cc
  const char *v5; // eax
  IVTex *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  HDRType_t v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  char pTemp2[260]; // [esp+4h] [ebp-57Ch] BYREF
  char pGameDir[260]; // [esp+108h] [ebp-478h] BYREF
  char pTemp[260]; // [esp+20Ch] [ebp-374h] BYREF
  char pBasePath[260]; // [esp+310h] [ebp-270h] BYREF
  char pMaterialSrcPath[260]; // [esp+414h] [ebp-16Ch] BYREF
  LightingState_t lightingState; // [esp+518h] [ebp-68h] BYREF
  LightcacheGetDynamic_Stats stats; // [esp+574h] [ebp-Ch] BYREF
  struct CSysModule *pModule; // [esp+578h] [ebp-8h] BYREF
  BOOL bHDR; // [esp+57Ch] [ebp-4h]
  int nTGASize; // [esp+588h] [ebp+8h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    if ( mat_envmaptgasize.m_pParent != nullptr )
      nTGASize = mat_envmaptgasize.m_pParent->m_Value.m_nValue;
    else
      nTGASize = 0;
    if ( m_nArgc >= 3 )
    {
      v4 = m_nArgc <= 2;
      v5 = defaultValue;
      if ( !v4 )
        v5 = args->m_ppArgv[2];
      nTGASize = atoi(nptr: v5);
    }
    v6 = VTex_Load(&pModule);
    if ( v6 != nullptr )
    {
      v7 = defaultValue;
      if ( args->m_nArgc > 1 )
        v7 = args->m_ppArgv[1];
      V_snprintf(pDest: pBasePath, maxLen: 260, pFormat: "materials/lightprobes/%s", v7);
      V_StripFilename(path: pBasePath);
      ((void (__thiscall *)(IFileSystem *, char *, const char *, int))g_pFileSystem->CreateDirHierarchy)(
        a1: g_pFileSystem,
        a2: pBasePath,
        a3: "DEFAULT_WRITE_PATH",
        a4: a1);
      v8 = defaultValue;
      if ( args->m_nArgc > 1 )
        v8 = args->m_ppArgv[1];
      V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "materialsrc/lightprobes/%s", v8);
      GetModContentSubdirectory(pSubDir: pTemp, pBuf: pMaterialSrcPath, nBufLen: 260);
      V_StripFilename(path: pMaterialSrcPath);
      ((void (__thiscall *)(IFileSystem *, char *))g_pFileSystem->CreateDirHierarchy)(
        a1: g_pFileSystem,
        a2: pMaterialSrcPath);
      COM_GetGameDir(szGameDir: pGameDir, maxlen: 260);
      v9 = g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig);
      LOBYTE(bHDR) = v9 != HDR_TYPE_NONE;
      if ( v9 != HDR_TYPE_NONE )
      {
        v10 = defaultValue;
        if ( args->m_nArgc > 1 )
          v10 = args->m_ppArgv[1];
        V_snprintf(pDest: pTemp2, maxLen: 260, pFormat: "materialsrc/lightprobes/%s_hdr", v10);
        GetModContentSubdirectory(pSubDir: pTemp2, pBuf: pMaterialSrcPath, nBufLen: 260);
        BuildSingleCubemap(
          pVTFName: pMaterialSrcPath,
          pCC: nullptr,
          vecOrigin: g_MainViewOrigin,
          nSize: nTGASize,
          bHDR: 1,
          pGameDir,
          ivt: v6);
      }
      GetModContentSubdirectory(pSubDir: pTemp, pBuf: pMaterialSrcPath, nBufLen: 260);
      BuildSingleCubemap(
        pVTFName: pMaterialSrcPath,
        pCC: nullptr,
        vecOrigin: g_MainViewOrigin,
        nSize: nTGASize,
        bHDR: 0,
        pGameDir,
        ivt: v6);
      FileSystem_UnloadModule(pModule);
      memset(&lightingState, 0, 76);
      LightcacheGetDynamic(
        origin: g_MainViewOrigin,
        &lightingState,
        &stats,
        pRenderable: nullptr,
        flags: 7u,
        bDebugModel: false);
      if ( args->m_nArgc > 1 )
        v11 = args->m_ppArgv[1];
      else
        v11 = defaultValue;
      V_snprintf(pDest: pBasePath, maxLen: 260, pFormat: "materials/lightprobes/%s", v11);
      WriteLightProbe(pBasePath, state: &lightingState, bHDR);
    }
  }
  else
  {
    ConMsg(a1: "sample_lighting usage: lightprobe <base file name> [cubemap dimension]\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10312900
// Name: _dynamic_initializer_for__buildcubemaps_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__buildcubemaps_command__()
{
  ConCommand::ConCommand(
    this: &buildcubemaps_command,
    pName: "buildcubemaps",
    callback: (void (__cdecl *)())buildcubemaps,
    pHelpString: "Rebuild cubemaps.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__buildcubemaps_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B730
// Name: _dynamic_initializer_for__maps__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__maps__()
{
  ConCommand::ConCommand(
    this: &maps,
    pName: "maps",
    callback: (void (__cdecl *)())Host_Maps_f,
    pHelpString: "Displays list of maps.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__maps__);
}

//------------------------------------------------------------------------------
// Address: 0x103222D0
// Name: _dynamic_atexit_destructor_for__buildcubemaps_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__buildcubemaps_command__()
{
  ConCommand::~ConCommand(this: &buildcubemaps_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A80
// Name: _dynamic_atexit_destructor_for__maps__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__maps__()
{
  ConCommand::~ConCommand(this: &maps);
}

//------------------------------------------------------------------------------
// Address: 0x1031B760
// Name: _dynamic_initializer_for__map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map__()
{
  ConCommand::ConCommand(
    this: &map,
    pName: "map",
    callback: (void (__cdecl *)())Host_Map_f,
    pHelpString: "Start playing on specified map.",
    flags: 0x20000,
    completionFunc: Host_Map_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__map__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B790
// Name: _dynamic_initializer_for__ss_map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_map__()
{
  ConCommand::ConCommand(
    this: &ss_map,
    pName: "ss_map",
    callback: (void (__cdecl *)())Host_SplitScreen_Map_f,
    pHelpString: "Start playing on specified map with max allowed splitscreen players.",
    flags: 0x20000,
    completionFunc: Host_SSMap_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__ss_map__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B7C0
// Name: _dynamic_initializer_for__map_background__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_background__()
{
  ConCommand::ConCommand(
    this: &map_background,
    pName: "map_background",
    callback: (void (__cdecl *)())Host_Map_Background_f,
    pHelpString: "Runs a map as the background to the main menu.",
    flags: 0x20000,
    completionFunc: Host_Background_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__map_background__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B7F0
// Name: _dynamic_initializer_for__map_commentary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_commentary__()
{
  ConCommand::ConCommand(
    this: &map_commentary,
    pName: "map_commentary",
    callback: (void (__cdecl *)())Host_Map_Commentary_f,
    pHelpString: "Start playing, with commentary, on a specified map.",
    flags: 0x20000,
    completionFunc: Host_Map_Commentary_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__map_commentary__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B820
// Name: _dynamic_initializer_for__changelevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__changelevel__()
{
  ConCommand::ConCommand(
    this: &changelevel,
    pName: "changelevel",
    callback: (void (__cdecl *)())Host_Changelevel_f,
    pHelpString: "Change server to the specified map",
    flags: 0x20000,
    completionFunc: Host_Changelevel_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__changelevel__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B850
// Name: _dynamic_initializer_for__changelevel2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__changelevel2__()
{
  ConCommand::ConCommand(
    this: &changelevel2,
    pName: "changelevel2",
    callback: (void (__cdecl *)())Host_Changelevel2_f,
    pHelpString: "Transition to the specified map in single player",
    flags: 0x20000,
    completionFunc: Host_Changelevel2_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__changelevel2__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B880
// Name: _dynamic_initializer_for__g_PhoneHome__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_PhoneHome__()
{
  netadr_s::SetIP(this: &g_PhoneHome.m_cserIP, unIP: 0);
  netadr_s::SetPort(this: &g_PhoneHome.m_cserIP, newport: 0);
  netadr_s::SetType(this: &g_PhoneHome.m_cserIP, newtype: NA_IP);
  g_PhoneHome.m_uSessionID = 0;
  g_PhoneHome.m_pSocket = nullptr;
  _V_memset(dest: (unsigned __int8 *)&g_PhoneHome.m_cserIP, fill: 0, count: 0xCu);
  _V_memset(dest: (unsigned __int8 *)g_PhoneHome.m_szBuildIdentifier, fill: 0, count: 0x20u);
}

//------------------------------------------------------------------------------
// Address: 0x10325A90
// Name: _dynamic_atexit_destructor_for__map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map__()
{
  ConCommand::~ConCommand(this: &map);
}

//------------------------------------------------------------------------------
// Address: 0x10325AA0
// Name: _dynamic_atexit_destructor_for__ss_map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_map__()
{
  ConCommand::~ConCommand(this: &ss_map);
}

//------------------------------------------------------------------------------
// Address: 0x10325AB0
// Name: _dynamic_atexit_destructor_for__map_background__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_background__()
{
  ConCommand::~ConCommand(this: &map_background);
}

//------------------------------------------------------------------------------
// Address: 0x10325AC0
// Name: _dynamic_atexit_destructor_for__map_commentary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_commentary__()
{
  ConCommand::~ConCommand(this: &map_commentary);
}

//------------------------------------------------------------------------------
// Address: 0x10325AD0
// Name: _dynamic_atexit_destructor_for__changelevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__changelevel__()
{
  ConCommand::~ConCommand(this: &changelevel);
}

//------------------------------------------------------------------------------
// Address: 0x10325AE0
// Name: _dynamic_atexit_destructor_for__changelevel2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__changelevel2__()
{
  ConCommand::~ConCommand(this: &changelevel2);
}

//------------------------------------------------------------------------------
// Address: 0x10325AF0
// Name: _dynamic_atexit_destructor_for__g_MapListMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MapListMgr__()
{
  CUtlDict<CMapListItem,int>::RemoveAll(this: &g_MapListMgr.m_Items);
  g_MapListMgr.m_bDirty = false;
  CUtlDict<CMapListItem,int>::RemoveAll(this: &g_MapListMgr.m_Items);
  CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>(this: &g_MapListMgr.m_Items.m_Elements.m_Tree);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10067C60
// Name: public: void FloatBitMap_t::Init(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::Init(FloatBitMap_t *this, int nXSize, int nYSize, int nZSize, char nAttributeMask)
{
  CSOAContainer::PurgeData(this);
  CSOAContainer::SetAttributeType(this, nAttrIdx: 0, nDataType: ATTRDATATYPE_FLOAT, bAllocateMemory: nAttributeMask & 1);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 1,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 2) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 2,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 4) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 3,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 8) != 0);
  CSOAContainer::AllocateData(this, nNCols: nXSize, nNRows: nYSize, nSlices: nZSize);
  if ( (nAttributeMask & 8) == 0 )
    CSOAContainer::FillAttr(this, nAttr: 3, flValue: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10067D00
// Name: VTex_Load
// Source: json
//------------------------------------------------------------------------------
IVTex *__cdecl VTex_Load(struct CSysModule **pModule)
{
  IVTex *v1; // esi
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IVTex *result; // eax

  v1 = nullptr;
  Module = FileSystem_LoadModule(path: "vtex_dll");
  *pModule = Module;
  if ( Module == nullptr
    || (Factory = Sys_GetFactory(pModule: Module)) == nullptr
    || (result = (IVTex *)Factory(a1: "VTEX_003", a2: nullptr), v1 = result, result == nullptr) )
  {
    ConMsg(a1: "Can't load vtex_dll.dll\n");
    return v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067D50
// Name: void __near * CubemapsFSFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl CubemapsFSFactory(const char *pName)
{
  return _V_stricmp(s1: pName, s2: "VFileSystem017") == 0 ? g_pFileSystem : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10067D80
// Name: AddSampleToBSPFile
// Source: json
//------------------------------------------------------------------------------
void __usercall AddSampleToBSPFile(
        mcubemapsample_t *pSample@<esi>,
        const char *matDir@<edi>,
        bool bHDR,
        IBSPPack *iBSPPack,
        CCubemapCollection *pCC)
{
  CCubemapCollection *v5; // ebx
  const char *v6; // eax
  const char *v7; // eax
  char localPath[1024]; // [esp+4h] [ebp-804h] BYREF
  char outputTextureName[512]; // [esp+404h] [ebp-404h] BYREF
  char inputTextureName[514]; // [esp+604h] [ebp-204h] BYREF
  CUtlSymbol result; // [esp+806h] [ebp-2h] BYREF

  v5 = pCC;
  v6 = "_hdr";
  if ( !bHDR )
    v6 = defaultValue;
  V_snprintf(
    pDest: inputTextureName,
    maxLen: 512,
    pFormat: "%s/c%d_%d_%d%s.vtf",
    matDir,
    (int)pSample->origin.x,
    (int)pSample->origin.y,
    (int)pSample->origin.z,
    v6);
  if ( v5 != nullptr )
  {
    if ( CUtlSymbolTable::Find(this: &v5->m_arrEntries, result: (CUtlSymbol *)&pCC + 1, pString: inputTextureName)->m_Id != 0xFFFF )
      return;
    CUtlSymbolTable::AddString(this: &v5->m_arrEntries, &result, pString: inputTextureName);
  }
  if ( g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: inputTextureName, a3: localPath, a4: 1024) != nullptr )
  {
    v7 = ".hdr";
    if ( !bHDR )
      v7 = defaultValue;
    V_snprintf(
      pDest: outputTextureName,
      maxLen: 512,
      pFormat: "%s/c%d_%d_%d%s.vtf",
      matDir,
      (int)pSample->origin.x,
      (int)pSample->origin.y,
      (int)pSample->origin.z,
      v7);
    V_FixSlashes(pname: localPath, separator: 92);
    iBSPPack->AddFileToPack(this: iBSPPack, a2: outputTextureName, a3: localPath);
  }
  else
  {
    _Warning(a1: "vtex failed to compile cubemap '%s'!\n", inputTextureName);
  }
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: inputTextureName, a3: "DEFAULT_WRITE_PATH");
}

//------------------------------------------------------------------------------
// Address: 0x10067EC0
// Name: public: FloatCubeMap_t::FloatCubeMap_t(int,int)
// Source: json
//------------------------------------------------------------------------------
FloatCubeMap_t *__thiscall FloatCubeMap_t::FloatCubeMap_t(FloatCubeMap_t *this, int xfsize, int yfsize)
{
  int v3; // ebx
  unsigned __int8 **m_pSeparateDataMemory; // esi
  FloatCubeMap_t *v5; // esi
  int i; // ebx

  v3 = 5;
  m_pSeparateDataMemory = this->face_maps[0].m_pSeparateDataMemory;
  do
  {
    memset(dst: (unsigned __int8 *)m_pSeparateDataMemory - 520, value: 0xFFu, count: 0x80u);
    memset(dst: (unsigned __int8 *)m_pSeparateDataMemory, value: 0, count: 0x80u);
    *(m_pSeparateDataMemory - 1) = nullptr;
    *(m_pSeparateDataMemory - 163) = nullptr;
    *(m_pSeparateDataMemory - 164) = nullptr;
    *(m_pSeparateDataMemory - 166) = nullptr;
    *(m_pSeparateDataMemory - 167) = nullptr;
    *(m_pSeparateDataMemory - 165) = nullptr;
    *(m_pSeparateDataMemory - 168) = nullptr;
    *(m_pSeparateDataMemory - 2) = nullptr;
    m_pSeparateDataMemory[32] = nullptr;
    m_pSeparateDataMemory += 201;
    --v3;
  }
  while ( v3 >= 0 );
  v5 = this;
  for ( i = 6; i != 0; --i )
  {
    CSOAContainer::PurgeData(this: (CSOAContainer *)v5);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 0,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 1,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 2,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 3,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::AllocateData(this: (CSOAContainer *)v5, nNCols: xfsize, nNRows: yfsize, nSlices: 1);
    v5 = (FloatCubeMap_t *)((char *)v5 + 804);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067FB0
// Name: void R_BuildCubemapSamples_PostBuild(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildCubemapSamples_PostBuild()
{
  ConVarRef drawMRMModelsCVar; // [esp+0h] [ebp-40h] BYREF
  ConVarRef mat_disable_bloom; // [esp+8h] [ebp-38h] BYREF
  ConVarRef r_occlusion; // [esp+10h] [ebp-30h] BYREF
  ConVarRef r_portalsopenall; // [esp+18h] [ebp-28h] BYREF
  ConVarRef r_lightstyle; // [esp+20h] [ebp-20h] BYREF
  ConVarRef mat_drawwater; // [esp+28h] [ebp-18h] BYREF
  ConVarRef r_shadows; // [esp+30h] [ebp-10h] BYREF
  ConVarRef cl_mouseenable; // [esp+38h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &cl_mouseenable, pName: "cl_mouseenable");
  if ( ConVarRef::IsValid(this: &cl_mouseenable) )
    cl_mouseenable.m_pConVar->SetValue_2(this: cl_mouseenable.m_pConVar, a2: 1);
  ConVarRef::ConVarRef(this: &r_shadows, pName: "r_shadows");
  if ( ConVarRef::IsValid(this: &r_shadows) )
    r_shadows.m_pConVar->SetValue_2(this: r_shadows.m_pConVar, a2: saveShadows);
  ConVarRef::ConVarRef(this: &mat_drawwater, pName: "mat_drawwater");
  if ( ConVarRef::IsValid(this: &mat_drawwater) )
    mat_drawwater.m_pConVar->SetValue_2(this: mat_drawwater.m_pConVar, a2: bDrawWater);
  if ( bSaveMatSpecular )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "1");
  else
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "0");
  ConVarRef::ConVarRef(this: &r_lightstyle, pName: "r_lightstyle");
  if ( ConVarRef::IsValid(this: &r_lightstyle) )
  {
    r_lightstyle.m_pConVar->SetValue_2(this: r_lightstyle.m_pConVar, a2: nSaveLightStyle);
    R_RedownloadAllLightmaps();
  }
  ConVarRef::ConVarRef(this: &r_portalsopenall, pName: "r_portalsopenall");
  if ( ConVarRef::IsValid(this: &r_portalsopenall) )
    r_portalsopenall.m_pConVar->SetValue_2(this: r_portalsopenall.m_pConVar, a2: 0);
  ConVarRef::ConVarRef(this: &r_occlusion, pName: "r_occlusion");
  if ( ConVarRef::IsValid(this: &r_occlusion) )
    r_occlusion.m_pConVar->SetValue_2(this: r_occlusion.m_pConVar, a2: nOldOcclusionVal);
  ConVarRef::ConVarRef(this: &mat_disable_bloom, pName: "mat_disable_bloom");
  if ( ConVarRef::IsValid(this: &mat_disable_bloom) )
    mat_disable_bloom.m_pConVar->SetValue_2(this: mat_disable_bloom.m_pConVar, a2: nOldBloomDisable);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_DrawBeams.IConVar, value: bSaveDrawBeams);
  ConVarRef::ConVarRef(this: &drawMRMModelsCVar, pName: "r_drawothermodels");
  if ( ConVarRef::IsValid(this: &drawMRMModelsCVar) )
    drawMRMModelsCVar.m_pConVar->SetValue_2(this: drawMRMModelsCVar.m_pConVar, a2: originaldrawMRMModelsVal);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&building_cubemaps.IConVar, value: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10068150
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068170
// Name: void R_BuildCubemapSamples_PreBuild(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildCubemapSamples_PreBuild()
{
  IBaseFileSystem_vtbl *v0; // esi
  CClientState *BaseLocalClient; // eax
  CClientState *v2; // eax
  IConVar_vtbl *v3; // eax
  int m_nValue; // eax
  IConVar_vtbl *v5; // eax
  ConVarRef drawMRMModelsCVar; // [esp+4h] [ebp-40h] BYREF
  ConVarRef r_portalsopenall; // [esp+Ch] [ebp-38h] BYREF
  ConVarRef cl_mouseenable; // [esp+14h] [ebp-30h] BYREF
  ConVarRef mat_disable_bloom; // [esp+1Ch] [ebp-28h] BYREF
  ConVarRef r_occlusion; // [esp+24h] [ebp-20h] BYREF
  ConVarRef r_lightstyle; // [esp+2Ch] [ebp-18h] BYREF
  ConVarRef mat_drawwater; // [esp+34h] [ebp-10h] BYREF
  ConVarRef r_shadows; // [esp+3Ch] [ebp-8h] BYREF

  v0 = g_pFileSystem->IBaseFileSystem::__vftable;
  BaseLocalClient = GetBaseLocalClient();
  if ( v0->IsFileWritable(this: &g_pFileSystem->IBaseFileSystem, a2: BaseLocalClient->m_szLevelName, a3: "GAME") )
  {
    ConVarRef::ConVarRef(this: &cl_mouseenable, pName: "cl_mouseenable");
    if ( ConVarRef::IsValid(this: &cl_mouseenable) )
      cl_mouseenable.m_pConVar->SetValue_2(this: cl_mouseenable.m_pConVar, a2: 0);
    ConVarRef::ConVarRef(this: &r_shadows, pName: "r_shadows");
    saveShadows = true;
    if ( ConVarRef::IsValid(this: &r_shadows) )
    {
      saveShadows = r_shadows.m_pConVarState->m_Value.m_nValue != 0;
      r_shadows.m_pConVar->SetValue_2(this: r_shadows.m_pConVar, a2: 0);
    }
    ConVarRef::ConVarRef(this: &mat_drawwater, pName: "mat_drawwater");
    bDrawWater = true;
    if ( ConVarRef::IsValid(this: &mat_drawwater) )
    {
      v3 = mat_drawwater.m_pConVar->__vftable;
      bDrawWater = mat_drawwater.m_pConVarState->m_Value.m_nValue != 0;
      v3->SetValue_2(this: mat_drawwater.m_pConVar, a2: 0);
    }
    nSaveLightStyle = -1;
    ConVarRef::ConVarRef(this: &r_lightstyle, pName: "r_lightstyle");
    if ( ConVarRef::IsValid(this: &r_lightstyle) )
    {
      nSaveLightStyle = r_lightstyle.m_pConVarState->m_Value.m_nValue;
      r_lightstyle.m_pConVar->SetValue_2(this: r_lightstyle.m_pConVar, a2: 0);
      R_RedownloadAllLightmaps();
    }
    if ( r_DrawBeams.m_pParent != nullptr )
      bSaveDrawBeams = r_DrawBeams.m_pParent->m_Value.m_nValue;
    else
      bSaveDrawBeams = 0;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_DrawBeams.IConVar, value: 0);
    if ( mat_fastspecular.m_pParent != nullptr )
      m_nValue = mat_fastspecular.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    bSaveMatSpecular = m_nValue != 0;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&building_cubemaps.IConVar, value: 1);
    ConVarRef::ConVarRef(this: &r_portalsopenall, pName: "r_portalsopenall");
    if ( ConVarRef::IsValid(this: &r_portalsopenall) )
      r_portalsopenall.m_pConVar->SetValue_2(this: r_portalsopenall.m_pConVar, a2: 1);
    nOldOcclusionVal = 1;
    ConVarRef::ConVarRef(this: &r_occlusion, pName: "r_occlusion");
    if ( ConVarRef::IsValid(this: &r_occlusion) )
    {
      nOldOcclusionVal = r_occlusion.m_pConVarState->m_Value.m_nValue;
      r_occlusion.m_pConVar->SetValue_2(this: r_occlusion.m_pConVar, a2: 0);
    }
    ConVarRef::ConVarRef(this: &mat_disable_bloom, pName: "mat_disable_bloom");
    nOldBloomDisable = 0;
    if ( ConVarRef::IsValid(this: &mat_disable_bloom) )
    {
      v5 = mat_disable_bloom.m_pConVar->__vftable;
      nOldBloomDisable = mat_disable_bloom.m_pConVarState->m_Value.m_nValue;
      v5->SetValue_2(this: mat_disable_bloom.m_pConVar, a2: 1);
    }
    ConVarRef::ConVarRef(this: &drawMRMModelsCVar, pName: "r_drawothermodels");
    if ( ConVarRef::IsValid(this: &drawMRMModelsCVar) )
      originaldrawMRMModelsVal = drawMRMModelsCVar.m_pConVarState->m_Value.m_nValue;
  }
  else
  {
    v2 = GetBaseLocalClient();
    _Warning(a1: "%s is not writable!!!  Check it out before running buildcubemaps.\n", v2->m_szLevelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100683B0
// Name: TakeCubemapSnapshot
// Source: json
//------------------------------------------------------------------------------
void __usercall TakeCubemapSnapshot(
        int a1@<ebx>,
        const Vector *origin,
        const char *pFileNameBase,
        int screenBufSize,
        BOOL tgaSize)
{
  int v5; // edi
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v7; // esi
  vgui::PropertyPage *v8; // ecx
  const Vector *v9; // ebx
  float x; // xmm0_4
  int v11; // esi
  int v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // xmm1_4
  float y; // xmm0_4
  float z; // xmm0_4
  FloatBitMap_t *v17; // esi
  unsigned __int8 *v18; // eax
  void (__thiscall *v19)(int, _DWORD, _DWORD, int, int, void *, _DWORD); // edx
  unsigned __int8 *v20; // ebx
  int v21; // eax
  int v22; // ecx
  unsigned __int8 *v23; // esi
  int v24; // edx
  unsigned __int8 *v25; // esi
  int v26; // esi
  unsigned int v27; // ebx
  unsigned __int8 *v28; // edx
  int v29; // edx
  float v30; // xmm2_4
  int i; // ecx
  unsigned __int8 *v32; // eax
  double v33; // st6
  int v34; // eax
  unsigned __int8 *v35; // ebx
  float v36; // xmm0_4
  unsigned __int8 *v37; // eax
  double v38; // st6
  int v39; // eax
  unsigned __int8 *v40; // ebx
  float v41; // xmm0_4
  unsigned __int8 *v42; // eax
  double v43; // st6
  int v44; // eax
  unsigned __int8 *v45; // ebx
  float v46; // xmm0_4
  void (__thiscall *SwapBuffers)(IMaterialSystem *); // eax
  char *v48; // esi
  int j; // edi
  int v50; // esi
  int k; // esi
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm0_4
  FloatCubeMap_t v58; // [esp+68h] [ebp-1B88h] BYREF
  char pDest[1024]; // [esp+1340h] [ebp-8B0h] BYREF
  FloatBitMap_t v60; // [esp+1740h] [ebp-4B0h] BYREF
  unsigned __int8 dst[244]; // [esp+1A64h] [ebp-18Ch] BYREF
  ImageLoader::ResampleInfo_t info; // [esp+1B58h] [ebp-98h] BYREF
  FloatBitMap_t *v63; // [esp+1BACh] [ebp-44h]
  int v64; // [esp+1BB0h] [ebp-40h]
  unsigned __int8 *v65; // [esp+1BB4h] [ebp-3Ch]
  int v66; // [esp+1BB8h] [ebp-38h]
  int v67; // [esp+1BBCh] [ebp-34h]
  unsigned __int8 *v68; // [esp+1BC0h] [ebp-30h]
  int v69; // [esp+1BC4h] [ebp-2Ch]
  void *pMem; // [esp+1BC8h] [ebp-28h]
  unsigned __int8 *v71; // [esp+1BCCh] [ebp-24h] BYREF
  float v72; // [esp+1BD0h] [ebp-20h]
  const char *v73; // [esp+1BD4h] [ebp-1Ch]
  unsigned __int8 *v74; // [esp+1BD8h] [ebp-18h]
  int v75; // [esp+1BDCh] [ebp-14h] BYREF
  int v76; // [esp+1BE0h] [ebp-10h]
  int v77; // [esp+1BE4h] [ebp-Ch]
  char v78; // [esp+1BEBh] [ebp-5h]
  int v79; // [esp+1BECh] [ebp-4h]

  v5 = screenBufSize;
  if ( !g_LostVideoMemory )
  {
    GetRenderContext = materials->GetRenderContext;
    v64 = 0;
    v7 = (int)GetRenderContext(this: materials);
    v66 = v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    if ( tgaSize )
    {
      v64 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 28))(a1: v7);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 24))(a1: v7, a2: 0);
    }
    memset(dst, value: 0, count: sizeof(dst));
    v9 = origin;
    x = origin->x;
    dst[240] |= 2u;
    *(float *)&dst[96] = x;
    *(float *)&dst[100] = origin->y;
    *(float *)&dst[104] = origin->z;
    *(_DWORD *)&dst[136] = 1065353216;
    *(_DWORD *)dst = 0;
    *(_DWORD *)&dst[4] = 0;
    *(_DWORD *)&dst[120] = 1090519040;
    *(_DWORD *)&dst[124] = 1188945920;
    *(_DWORD *)&dst[8] = 512;
    *(_DWORD *)&dst[12] = 512;
    v73 = ".tga";
    if ( tgaSize )
      v73 = ".pfm";
    CColorBalanceUIPanel::Init(this: v8);
    if ( tgaSize )
    {
      ((void (__thiscall *)(IMaterialSystem *, int *, unsigned __int8 **, int))materials->GetBackBufferDimensions)(
        a1: materials,
        a2: &v75,
        a3: &v71,
        a4: a1);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, int, unsigned __int8 *))(*(_DWORD *)v7 + 152))(
        a1: v7,
        a2: 0,
        a3: 0,
        a4: v75,
        a5: v71);
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v7 + 292))(a1: v7, a2: 128, a3: 128, a4: 128);
      (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v7 + 48))(a1: v7, a2: 1, a3: 1, a4: 0);
      FloatCubeMap_t::FloatCubeMap_t(this: &v58, xfsize: screenBufSize, yfsize: screenBufSize);
      v11 = 0;
      v75 = 0;
      do
      {
        v12 = *(_DWORD *)((char *)angle0 + v11);
        *(_DWORD *)&dst[88] = 1119092736;
        *(_DWORD *)&dst[92] = 1119092736;
        v13 = v9->x;
        *(_DWORD *)&dst[108] = v12;
        v14 = *(_DWORD *)((char *)angle1 + v11);
        *(float *)&dst[96] = v13;
        y = v9->y;
        *(_DWORD *)&dst[112] = v14;
        *(float *)&dst[100] = y;
        z = v9->z;
        *(_DWORD *)&dst[116] = 0;
        *(float *)&dst[104] = z;
        if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_INTEGER )
        {
          v17 = &v58.face_maps[*(int *)((char *)engine_cubemap_idx_to_fbm_idx + v11)];
          v63 = v17;
          FloatBitMap_t::Clear(this: v17, r: 0.0, g: 0.0, b: 0.0, a: 1.0);
          v72 = 16.0;
          do
          {
            if ( v72 <= 0.05 )
              break;
            ConVar::SetValue(this: (ConVar *)&mat_force_tonemap_scale.IConVar, value: v72);
            g_ClientDLL->RenderView(this: g_ClientDLL, a2: (const CViewSetup *)dst, a3: 7, a4: 0);
            pMem = MemAlloc_Alloc(nSize: 0x100000u);
            v18 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 4 * v5 * v5);
            v19 = *(void (__thiscall **)(int, _DWORD, _DWORD, int, int, void *, _DWORD))(*(_DWORD *)v66 + 52);
            v20 = v18;
            v65 = v18;
            v19(a1: v66, a2: 0, a3: 0, a4: 512, a5: 512, a6: pMem, a7: 0);
            info.m_nSrcDepth = 1;
            info.m_nDestDepth = 1;
            info.m_pSrc = (unsigned __int8 *)pMem;
            info.m_flAlphaThreshhold = 0.40000001;
            info.m_flAlphaHiFreqThreshhold = 0.40000001;
            info.m_nFlags = 0;
            info.m_flColorScale[0] = 1.0;
            info.m_flColorScale[1] = 1.0;
            info.m_flColorScale[2] = 1.0;
            info.m_flColorScale[3] = 1.0;
            memset(info.m_flColorGoal, 0, sizeof(info.m_flColorGoal));
            info.m_pDest = v20;
            info.m_nSrcWidth = 512;
            info.m_nSrcHeight = 512;
            info.m_nDestWidth = v5;
            info.m_nDestHeight = v5;
            info.m_flSrcGamma = 1.0;
            info.m_flDestGamma = 1.0;
            if ( !ImageLoader::ResampleRGBA8888(&info) )
              Sys_Error(error: "Can't resample\n");
            FloatBitMap_t::FloatBitMap_t(this: &v60, nWidth: v5, nHeight: v5, nDepth: 1, nAttributeMask: 15);
            v21 = 0;
            if ( v5 > 0 )
            {
              v68 = v20 + 2;
              v69 = (int)&v20[4 * v5 + 2];
              do
              {
                v22 = 0;
                if ( v5 >= 4 )
                {
                  v77 = (int)&v65[8 * v5 + 2 + 4 * v5 + 4 * v21];
                  v76 = 16 * v5;
                  v23 = v68;
                  v67 = (int)&v65[8 * screenBufSize + 2 + 4 * v21];
                  v24 = 2;
                  v71 = v68;
                  v74 = (unsigned __int8 *)v69;
                  do
                  {
                    v79 = *(v23 - 2);
                    *(float *)&v60.m_pAttributePtrs[0][v22 * v60.m_nRowStrideInBytes[0] + v21 * v60.m_nStrideInBytes[0]] = (double)v79 * 0.00392156862745098;
                    v79 = *(v23 - 1);
                    *(float *)&v60.m_pAttributePtrs[1][v22 * v60.m_nRowStrideInBytes[1] + v21 * v60.m_nStrideInBytes[1]] = (double)v79 * 0.00392156862745098;
                    v79 = *v23;
                    *(float *)&v60.m_pAttributePtrs[2][v22 * v60.m_nRowStrideInBytes[2] + v21 * v60.m_nStrideInBytes[2]] = (double)v79 * 0.00392156862745098;
                    v79 = *(v74 - 2);
                    *(float *)&v60.m_pAttributePtrs[0][v21 * v60.m_nStrideInBytes[0]
                                                     + v60.m_nRowStrideInBytes[0] * (v24 - 1)] = (double)v79
                                                                                               * 0.00392156862745098;
                    v79 = *(v74 - 1);
                    *(float *)&v60.m_pAttributePtrs[1][v21 * v60.m_nStrideInBytes[1]
                                                     + v60.m_nRowStrideInBytes[1] * (v24 - 1)] = (double)v79
                                                                                               * 0.00392156862745098;
                    v79 = *v74;
                    *(float *)&v60.m_pAttributePtrs[2][v21 * v60.m_nStrideInBytes[2]
                                                     + v60.m_nRowStrideInBytes[2] * (v24 - 1)] = (double)v79
                                                                                               * 0.00392156862745098;
                    v25 = (unsigned __int8 *)v67;
                    v79 = *(unsigned __int8 *)(v67 - 2);
                    *(float *)&v60.m_pAttributePtrs[0][v21 * v60.m_nStrideInBytes[0] + v60.m_nRowStrideInBytes[0] * v24] = (double)v79 * 0.00392156862745098;
                    v79 = *(v25 - 1);
                    v22 += 4;
                    *(float *)&v60.m_pAttributePtrs[1][v21 * v60.m_nStrideInBytes[1] + v60.m_nRowStrideInBytes[1] * v24] = (double)v79 * 0.00392156862745098;
                    v79 = *v25;
                    *(float *)&v60.m_pAttributePtrs[2][v21 * v60.m_nStrideInBytes[2] + v60.m_nRowStrideInBytes[2] * v24] = (double)v79 * 0.00392156862745098;
                    v79 = *(unsigned __int8 *)(v77 - 2);
                    v26 = v24 + 1;
                    v27 = v60.m_nRowStrideInBytes[0] * (v24 + 1);
                    v24 += 4;
                    *(float *)&v60.m_pAttributePtrs[0][v21 * v60.m_nStrideInBytes[0] + v27] = (double)v79
                                                                                            * 0.00392156862745098;
                    v79 = *(unsigned __int8 *)(v77 - 1);
                    *(float *)&v60.m_pAttributePtrs[1][v21 * v60.m_nStrideInBytes[1] + v60.m_nRowStrideInBytes[1] * v26] = (double)v79 * 0.00392156862745098;
                    v79 = *(unsigned __int8 *)v77;
                    *(float *)&v60.m_pAttributePtrs[2][v21 * v60.m_nStrideInBytes[2] + v60.m_nRowStrideInBytes[2] * v26] = (double)v79 * 0.00392156862745098;
                    v74 += v76;
                    v67 += v76;
                    v77 += v76;
                    v23 = &v71[v76];
                    v5 = screenBufSize;
                    v71 += v76;
                  }
                  while ( v22 < screenBufSize - 3 );
                  v17 = v63;
                  v20 = v65;
                }
                if ( v22 < v5 )
                {
                  v77 = (int)&v20[4 * v21 + 2 + 4 * v5 * v22];
                  do
                  {
                    v76 = *(unsigned __int8 *)(v77 - 2);
                    *(float *)&v60.m_pAttributePtrs[0][v22 * v60.m_nRowStrideInBytes[0] + v21 * v60.m_nStrideInBytes[0]] = (double)v76 * 0.00392156862745098;
                    v76 = *(unsigned __int8 *)(v77 - 1);
                    *(float *)&v60.m_pAttributePtrs[1][v22 * v60.m_nRowStrideInBytes[1] + v21 * v60.m_nStrideInBytes[1]] = (double)v76 * 0.00392156862745098;
                    v76 = *(unsigned __int8 *)v77;
                    v28 = &v60.m_pAttributePtrs[2][v22 * v60.m_nRowStrideInBytes[2]];
                    ++v22;
                    *(float *)&v28[v21 * v60.m_nStrideInBytes[2]] = (double)v76 * 0.00392156862745098;
                    v77 += 4 * v5;
                  }
                  while ( v22 < v5 );
                  v20 = v65;
                }
                v68 += 4;
                v69 += 4;
                ++v21;
              }
              while ( v21 < v5 );
            }
            free(pMem);
            free(pMem: v20);
            FloatBitMap_t::RaiseToPower(this: &v60, power: 2.2);
            v29 = 0;
            v78 = 0;
            *(float *)&v76 = 1.0 / v72;
            if ( v17->m_nColumns > 0 )
            {
              v30 = *(float *)&v76;
              do
              {
                for ( i = 0; i < v17->m_nRows; *(float *)&v45[v44] = v46 )
                {
                  v32 = &v60.m_pAttributePtrs[0][i * v60.m_nRowStrideInBytes[0]];
                  v33 = *(float *)&v32[v29 * v60.m_nStrideInBytes[0]];
                  v77 = *(int *)&v32[v29 * v60.m_nStrideInBytes[0]];
                  if ( v33 > 0.98 )
                    v78 = 1;
                  v34 = i * v17->m_nRowStrideInBytes[0] + v29 * v17->m_nStrideInBytes[0];
                  v35 = v17->m_pAttributePtrs[0];
                  v36 = *(float *)&v77 * v30;
                  if ( *(float *)&v35[v34] > (float)(*(float *)&v77 * v30) )
                    v36 = *(float *)&v35[v34];
                  *(float *)&v35[v34] = v36;
                  v37 = &v60.m_pAttributePtrs[1][i * v60.m_nRowStrideInBytes[1]];
                  v38 = *(float *)&v37[v29 * v60.m_nStrideInBytes[1]];
                  v77 = *(int *)&v37[v29 * v60.m_nStrideInBytes[1]];
                  if ( v38 > 0.98 )
                    v78 = 1;
                  v39 = v29 * v17->m_nStrideInBytes[1] + i * v17->m_nRowStrideInBytes[1];
                  v40 = v17->m_pAttributePtrs[1];
                  v41 = *(float *)&v77 * v30;
                  if ( *(float *)&v40[v39] > (float)(*(float *)&v77 * v30) )
                    v41 = *(float *)&v40[v39];
                  *(float *)&v40[v39] = v41;
                  v42 = &v60.m_pAttributePtrs[2][i * v60.m_nRowStrideInBytes[2]];
                  v43 = *(float *)&v42[v29 * v60.m_nStrideInBytes[2]];
                  v77 = *(int *)&v42[v29 * v60.m_nStrideInBytes[2]];
                  if ( v43 > 0.98 )
                    v78 = 1;
                  v44 = v29 * v17->m_nStrideInBytes[2] + i * v17->m_nRowStrideInBytes[2];
                  v45 = v17->m_pAttributePtrs[2];
                  v46 = *(float *)&v77 * v30;
                  if ( *(float *)&v45[v44] > (float)(*(float *)&v77 * v30) )
                    v46 = *(float *)&v45[v44];
                  ++i;
                }
                ++v29;
              }
              while ( v29 < v17->m_nColumns );
            }
            SwapBuffers = materials->SwapBuffers;
            v72 = v72 * 0.75;
            SwapBuffers(this: materials);
            CSOAContainer::~CSOAContainer(this: &v60);
            v9 = origin;
          }
          while ( v78 != 0 );
          ConVar::SetValue(this: (ConVar *)&mat_force_tonemap_scale.IConVar, value: 0.0);
          V_snprintf(
            pDest,
            maxLen: 1024,
            pFormat: "%s%s%s",
            pFileNameBase,
            *(const char **)((char *)facingName + v75),
            v73);
          v11 = v75;
        }
        else
        {
          g_ClientDLL->RenderView(this: g_ClientDLL, a2: (const CViewSetup *)dst, a3: 7, a4: 0);
          V_snprintf(
            pDest,
            maxLen: 1024,
            pFormat: "%s%s%s",
            pFileNameBase,
            *(const char **)((char *)facingName + v11),
            v73);
          videomode->TakeSnapshotTGARect(
            this: videomode,
            a2: pDest,
            a3: 0,
            a4: 0,
            a5: 512,
            a6: 512,
            a7: v5,
            a8: v5,
            a9: tgaSize,
            a10: *(CubeMapFaceIndex_t *)((char *)face_idx + v11));
        }
        v11 += 4;
        v75 = v11;
      }
      while ( v11 < 24 );
      if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_INTEGER )
      {
        V_snprintf(pDest, maxLen: 1024, pFormat: "%s", pFileNameBase);
        FloatCubeMap_t::WritePFMs(this: &v58, basename: pDest);
      }
      v48 = pDest;
      for ( j = 5; j >= 0; --j )
      {
        v48 -= 804;
        CSOAContainer::~CSOAContainer(this: (CSOAContainer *)v48);
      }
      materials->SwapBuffers(this: materials);
      v50 = v66;
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v66 + 24))(a1: v66, a2: v64);
    }
    else
    {
      for ( k = 0; k < 6; ++k )
      {
        v52 = angle0[k];
        *(_DWORD *)&dst[88] = 1119092736;
        *(_DWORD *)&dst[92] = 1119092736;
        v53 = origin->x;
        *(float *)&dst[108] = v52;
        v54 = angle1[k];
        *(float *)&dst[96] = v53;
        v55 = origin->y;
        *(float *)&dst[112] = v54;
        *(float *)&dst[100] = v55;
        v56 = origin->z;
        *(_DWORD *)&dst[116] = 0;
        *(float *)&dst[104] = v56;
        g_ClientDLL->RenderView(this: g_ClientDLL, a2: (const CViewSetup *)dst, a3: 7, a4: 0);
        V_snprintf(pDest, maxLen: 1024, pFormat: "%s%s%s", pFileNameBase, facingName[k], v73);
        videomode->TakeSnapshotTGARect(
          this: videomode,
          a2: pDest,
          a3: 0,
          a4: 0,
          a5: 512,
          a6: 512,
          a7: screenBufSize,
          a8: screenBufSize,
          a9: false,
          a10: face_idx[k]);
      }
      v50 = v66;
    }
    if ( v50 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v50 + 12))(a1: v50);
      (*(void (__thiscall **)(int))(*(_DWORD *)v50 + 4))(a1: v50);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068E80
// Name: BuildSingleCubemap
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildSingleCubemap(
        const char *pVTFName@<edi>,
        CCubemapCollection *pCC@<eax>,
        const Vector *vecOrigin,
        int nSize,
        int bHDR,
        const char *pGameDir,
        IVTex *ivt)
{
  void *v8; // esi
  int (__thiscall *VTex)(IVTex *, void *(__cdecl *)(const char *, int *), const char *, int, char **); // edx
  const char *v10; // ebx
  const char **v11; // esi
  char pTXTName[260]; // [esp+8h] [ebp-20Ch] BYREF
  char pDest[4]; // [esp+10Ch] [ebp-108h] BYREF
  char *argv[64]; // [esp+110h] [ebp-104h] BYREF
  CUtlSymbol result; // [esp+210h] [ebp-4h] BYREF
  CUtlSymbol v16; // [esp+212h] [ebp-2h] BYREF

  if ( pCC != nullptr )
  {
    if ( CUtlSymbolTable::Find(this: &pCC->m_arrEntries, &result, pString: pVTFName)->m_Id != 0xFFFF )
      return;
    CUtlSymbolTable::AddString(this: &pCC->m_arrEntries, result: &v16, pString: pVTFName);
  }
  TakeCubemapSnapshot(a1: bHDR, origin: vecOrigin, pFileNameBase: pVTFName, screenBufSize: nSize, tgaSize: bHDR);
  V_strncpy(pDest: pTXTName, pSrc: pVTFName, maxLen: 260);
  V_SetExtension(path: pTXTName, extension: ".txt", pathStringLength: 260);
  v8 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pTXTName, a3: "w", a4: 0);
  if ( (_BYTE)bHDR != 0 )
    g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "\"pfm\" \"1\"\n");
  g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v8, a3: "\"stripalphachannel\" \"1\"\n");
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v8);
  if ( ivt != nullptr )
  {
    VTex = ivt->VTex;
    argv[5] = pTXTName;
    argv[0] = (char *)defaultValue;
    argv[1] = "-oldcubepath";
    argv[2] = "-quiet";
    argv[3] = "-UseStandardError";
    argv[4] = "-WarningsAsErrors";
    VTex(this: ivt, a2: (void *(__cdecl *)(const char *, int *))CubemapsFSFactory, a3: pGameDir, a4: 6, a5: argv);
  }
  g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: pTXTName, a3: nullptr);
  v10 = ".pfm";
  if ( (_BYTE)bHDR == 0 )
    v10 = ".tga";
  v11 = facingName;
  do
  {
    V_snprintf(pDest, maxLen: 260, pFormat: "%s%s", pVTFName, *v11);
    V_SetExtension(path: pDest, extension: v10, pathStringLength: 260);
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: pDest, a3: nullptr);
    ++v11;
  }
  while ( (int)v11 < (int)&saveShadows );
}

//------------------------------------------------------------------------------
// Address: 0x10069040
// Name: envmap
// Source: json
//------------------------------------------------------------------------------
void __usercall envmap(int a1@<ebx>)
{
  IClientEntity *v1; // eax
  IClientRenderable *v2; // esi
  IModelLoader_vtbl *v3; // edi
  int v4; // eax
  const char *v5; // eax
  unsigned int v6; // kr00_4
  void *v7; // esp
  int m_nValue; // esi
  HDRType_t v9; // eax
  char v10[8]; // [esp+0h] [ebp-108h] BYREF
  char base[256]; // [esp+8h] [ebp-100h] BYREF

  v1 = entitylist->GetClientEntity(this: entitylist, a2: 0);
  if ( v1 != nullptr && (v2 = &v1->IClientRenderable, v1->GetModel(this: &v1->IClientRenderable) != nullptr) )
  {
    v3 = modelloader->__vftable;
    v4 = (int)v2->GetModel(this: v2);
    v5 = v3->GetName(this: modelloader, a2: (const model_t *)v4);
    V_FileBase(in: v5, out: base, maxlen: 256);
  }
  else
  {
    V_strncpy(pDest: base, pSrc: "Env", maxLen: 256);
  }
  v6 = strlen(base);
  v7 = alloca(v6 + 21);
  V_snprintf(pDest: v10, maxLen: v6 + 21, pFormat: "cubemap_screenshots/%s", base);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "cubemap_screenshots", a3: "DEFAULT_WRITE_PATH");
  if ( mat_envmaptgasize.m_pParent != nullptr )
    m_nValue = mat_envmaptgasize.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v9 = g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig);
  TakeCubemapSnapshot(
    a1,
    origin: g_MainViewOrigin,
    pFileNameBase: v10,
    screenBufSize: m_nValue,
    tgaSize: v9 != HDR_TYPE_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x10069150
// Name: LoadSrcVTFFiles
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadSrcVTFFiles(IVTFTexture **pSrcVTFTextures, const char *pSkyboxBaseName)
{
  int v2; // eax
  IVTFTexture **v3; // esi
  IVTFTexture *VTFTexture; // eax
  IVTFTexture *v5; // edi
  int v6; // eax
  int (__thiscall *Width)(IVTFTexture *); // edx
  int v8; // eax
  IVTFTexture *v9; // edi
  int v10; // eax
  int (__thiscall *Height)(IVTFTexture *); // edx
  int v12; // eax
  IVTFTexture *v13; // edi
  int v14; // eax
  int (__thiscall *v15)(IVTFTexture *); // edx
  int v16; // eax
  IVTFTexture *v17; // edi
  int v18; // eax
  int (__thiscall *Flags)(IVTFTexture *); // edx
  int v20; // eax
  char srcVTFFileName[1024]; // [esp+Ch] [ebp-43Ch] BYREF
  CUtlBuffer buf; // [esp+40Ch] [ebp-3Ch] BYREF
  int j; // [esp+43Ch] [ebp-Ch]
  int i; // [esp+440h] [ebp-8h]
  int v26; // [esp+444h] [ebp-4h]

  v2 = (char *)facingName - (char *)pSrcVTFTextures;
  i = 0;
  v3 = pSrcVTFTextures;
  for ( j = (char *)facingName - (char *)pSrcVTFTextures; ; v2 = j )
  {
    V_snprintf(
      pDest: srcVTFFileName,
      maxLen: 1024,
      pFormat: "materials/skybox/%s%s.vtf",
      pSkyboxBaseName,
      *(const char **)((char *)v3 + v2));
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    if ( !g_pFileSystem->ReadFile(
            this: &g_pFileSystem->IBaseFileSystem,
            a2: srcVTFFileName,
            a3: nullptr,
            a4: &buf,
            a5: 0,
            a6: 0,
            a7: nullptr) )
      break;
    VTFTexture = CreateVTFTexture();
    *v3 = VTFTexture;
    if ( !VTFTexture->Unserialize(this: VTFTexture, a2: &buf, a3: false, a4: 0) )
    {
      _Warning(a1: "*** Error unserializing skybox texture: %s\n", pSkyboxBaseName);
      break;
    }
    v5 = *v3;
    v6 = (*pSrcVTFTextures)->Width(this: *pSrcVTFTextures);
    Width = v5->Width;
    v26 = v6;
    v8 = Width(this: v5);
    if ( v8 != v26 && (*v3)->Width(this: *v3) != 4 )
      goto LABEL_21;
    v9 = *v3;
    v10 = (*pSrcVTFTextures)->Height(this: *pSrcVTFTextures);
    Height = v9->Height;
    v26 = v10;
    v12 = Height(this: v9);
    if ( v12 != v26 )
    {
      v13 = *v3;
      v14 = (*pSrcVTFTextures)->Height(this: *pSrcVTFTextures);
      v15 = v13->Height;
      v26 = 2 * v14;
      v16 = v15(this: v13);
      if ( v16 != v26 && (*v3)->Height(this: *v3) != 4 )
        goto LABEL_21;
    }
    v17 = *v3;
    v18 = (*pSrcVTFTextures)->Flags(this: *pSrcVTFTextures);
    Flags = v17->Flags;
    v26 = v18;
    v20 = Flags(this: v17);
    if ( v20 != v26 )
    {
LABEL_21:
      _Warning(
        a1: "*** Error: Skybox vtf files for %s weren't compiled with the same size texture and/or same flags!\n",
        pSkyboxBaseName);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 0;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    ++v3;
    if ( ++i >= 6 )
      return 1;
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10069330
// Name: void Cubemap_CreateDefaultCubemap(char const __near *,class IBSPPack __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall Cubemap_CreateDefaultCubemap(int a1@<ebx>, int a2@<edi>, const char *pMapName, IBSPPack *iBSPPack)
{
  char *m_pszString; // esi
  IVTFTexture *v5; // edi
  int (__thiscall *Width)(IVTFTexture *); // eax
  int v7; // esi
  int v8; // eax
  IVTFTexture *VTFTexture; // esi
  IVTFTexture_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int (__thiscall *FrameCount)(IVTFTexture *); // edx
  int v15; // ebx
  int v16; // edi
  IVTFTexture *v17; // ebx
  unsigned __int8 *v18; // eax
  IVTFTexture_vtbl *v19; // edx
  int v20; // eax
  int (__thiscall *ComputeMipSize)(IVTFTexture *, int); // edx
  int (__thiscall *v22)(IVTFTexture *); // eax
  int v23; // edi
  __int16 v24; // bx
  int i; // edi
  __int16 v26; // ax
  unsigned int v27; // edi
  unsigned int j; // eax
  int k; // edi
  char dstVTFFileName[1024]; // [esp+4h] [ebp-464h] BYREF
  CUtlBuffer outputBuf; // [esp+404h] [ebp-64h] BYREF
  IVTFTexture *pSrcVTFTextures[6]; // [esp+434h] [ebp-34h] BYREF
  ConVarRef skyboxBaseNameConVar; // [esp+44Ch] [ebp-1Ch] BYREF
  int iSize; // [esp+454h] [ebp-14h]
  unsigned __int8 *pDstBits; // [esp+458h] [ebp-10h]
  int iFace; // [esp+45Ch] [ebp-Ch]
  int iMipLevelOffset; // [esp+460h] [ebp-8h]
  int iFrame; // [esp+464h] [ebp-4h]

  ConVarRef::ConVarRef(this: &skyboxBaseNameConVar, pName: "sv_skyname");
  if ( ConVarRef::IsValid(this: &skyboxBaseNameConVar)
    && (m_pszString = skyboxBaseNameConVar.m_pConVarState->m_Value.m_pszString) != nullptr )
  {
    if ( LoadSrcVTFFiles(pSrcVTFTextures, pSkyboxBaseName: skyboxBaseNameConVar.m_pConVarState->m_Value.m_pszString) != 0 )
    {
      _Msg(a1: "Creating default cubemaps for env_cubemap using skybox %s...\n", m_pszString);
      v5 = pSrcVTFTextures[0];
      Width = pSrcVTFTextures[0]->Width;
      v7 = 0;
      iMipLevelOffset = 0;
      v8 = ((int (__thiscall *)(IVTFTexture *, int))Width)(a1: pSrcVTFTextures[0], a2);
      if ( v8 > 32 )
      {
        do
        {
          v8 >>= 1;
          ++v7;
        }
        while ( v8 > 32 );
        iMipLevelOffset = v7;
      }
      VTFTexture = CreateVTFTexture();
      v10 = VTFTexture->__vftable;
      v11 = ((int (__thiscall *)(IVTFTexture *, int, int))v5->FrameCount)(a1: v5, a2: -1, a3: a1);
      v12 = ((int (__thiscall *)(IVTFTexture *, int))v5->Flags)(a1: v5, a2: v11);
      v13 = ((int (__thiscall *)(IVTFTexture *, int))v5->Format)(a1: v5, a2: v12 | 0x4000);
      ((void (__thiscall *)(IVTFTexture *, int, int, int, int))v10->Init)(
        a1: VTFTexture,
        a2: 32,
        a3: 32,
        a4: 1,
        a5: v13);
      FrameCount = VTFTexture->FrameCount;
      iFrame = 0;
      if ( FrameCount(this: VTFTexture) > 0 )
      {
        do
        {
          v15 = 0;
          iFace = 0;
          do
          {
            v16 = 0;
            if ( VTFTexture->MipCount(this: VTFTexture) > 0 )
            {
              v17 = pSrcVTFTextures[v15];
              do
              {
                v17->ImageData_2(this: v17, a2: iFrame, a3: 0, a4: v16 + iMipLevelOffset);
                v18 = VTFTexture->ImageData_2(this: VTFTexture, a2: iFrame, a3: iFace, a4: v16);
                v19 = VTFTexture->__vftable;
                pDstBits = v18;
                v20 = v19->ComputeMipSize(this: VTFTexture, a2: v16);
                ComputeMipSize = v17->ComputeMipSize;
                iSize = v20;
                ComputeMipSize(this: v17, a2: v16 + iMipLevelOffset);
                memset(dst: pDstBits, value: 0, count: iSize);
                ++v16;
              }
              while ( v16 < VTFTexture->MipCount(this: VTFTexture) );
              v15 = iFace;
            }
            iFace = ++v15;
          }
          while ( v15 < 6 );
          v22 = VTFTexture->FrameCount;
          v23 = ++iFrame;
        }
        while ( v23 < v22(this: VTFTexture) );
      }
      v24 = 0;
      for ( i = 0; i < 6; ++i )
      {
        v26 = pSrcVTFTextures[i]->Flags(this: pSrcVTFTextures[i]);
        v24 |= v26;
      }
      ((void (__thiscall *)(IVTFTexture *, int, _DWORD))VTFTexture->ConvertImageFormat)(a1: VTFTexture, a2: -2, a3: 0);
      if ( (v24 & 0x3000) == 0 )
      {
        v27 = (unsigned int)VTFTexture->ImageData_3(this: VTFTexture);
        for ( j = v27 + VTFTexture->ComputeTotalSize(this: VTFTexture); v27 < j; v27 += 4 )
          *(_BYTE *)(v27 + 3) = 0;
      }
      VTFTexture->FixCubemapFaceOrientation(this: VTFTexture);
      VTFTexture->GenerateSpheremap(this: VTFTexture, a2: LOOK_DOWN_Z);
      VTFTexture->ConvertImageFormat(this: VTFTexture, a2: IMAGE_FORMAT_DXT5, a3: false, a4: false);
      V_snprintf(pDest: dstVTFFileName, maxLen: 1024, pFormat: "materials/maps/%s/cubemapdefault.vtf", pMapName);
      CUtlBuffer::CUtlBuffer(this: &outputBuf, growSize: 0, initSize: 0, nFlags: 0);
      if ( VTFTexture->Serialize(this: VTFTexture, a2: &outputBuf) )
      {
        iBSPPack->AddBufferToPack(
          this: iBSPPack,
          a2: dstVTFFileName,
          a3: outputBuf.m_Memory.m_pMemory,
          a4: outputBuf.m_Put,
          a5: false);
        for ( k = 0; k < 6; ++k )
          DestroyVTFTexture(pTexture: pSrcVTFTextures[k]);
        DestroyVTFTexture(pTexture: VTFTexture);
      }
      else
      {
        _Warning(a1: "Error serializing default cubemap %s\n", dstVTFFileName);
      }
      if ( outputBuf.m_Memory.m_nGrowSize >= 0 && outputBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputBuf.m_Memory.m_pMemory);
    }
    else
    {
      _Warning(a1: "Can't load skybox file %s to build the default cubemap!\n", m_pszString);
    }
  }
  else
  {
    _Warning(a1: "Couldn't create default cubemap\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069630
// Name: void R_BuildCubemapSamples(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_BuildCubemapSamples(int a1@<ebx>, int numIterations)
{
  IBaseFileSystem_vtbl *v2; // esi
  CClientState *BaseLocalClient; // eax
  CClientState *v4; // eax
  int v5; // eax
  int v6; // esi
  const model_t *v7; // eax
  const char *v8; // ebx
  model_t *v9; // esi
  worldbrushdata_t *pShared; // eax
  int v11; // edi
  unsigned __int8 size; // al
  int v13; // eax
  int v14; // ebx
  int v15; // ecx
  int *p_m_nCubemapSamples; // eax
  int v17; // ebx
  int v18; // esi
  const char *v19; // eax
  char v20; // al
  int m_nValue; // eax
  worldbrushdata_t *v22; // eax
  struct CSysModule *Module; // eax
  struct CSysModule *v24; // edi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IBSPPack *v26; // ebx
  worldbrushdata_t *v27; // eax
  vgui::CTreeViewListControl *v28; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v30; // [esp-18h] [ebp-A90h]
  char mapPath[1024]; // [esp+4h] [ebp-A74h] BYREF
  char pTemp[260]; // [esp+404h] [ebp-674h] BYREF
  char pVTFName[260]; // [esp+508h] [ebp-570h] BYREF
  char gameDir[260]; // [esp+60Ch] [ebp-46Ch] BYREF
  char pMaterialSrcDir[260]; // [esp+710h] [ebp-368h] BYREF
  char matDir[260]; // [esp+814h] [ebp-264h] BYREF
  char mapName[256]; // [esp+918h] [ebp-160h] BYREF
  CCubemapCollection uniqueCubemaps; // [esp+A18h] [ebp-60h] BYREF
  ConVarRef drawMRMModelsCVar; // [esp+A50h] [ebp-28h] BYREF
  BOOL bOldLightSpritesActive; // [esp+A58h] [ebp-20h]
  IVTex *ivt; // [esp+A5Ch] [ebp-1Ch]
  struct CSysModule *pModule; // [esp+A60h] [ebp-18h] BYREF
  model_t *pWorldModel; // [esp+A64h] [ebp-14h]
  int i; // [esp+A68h] [ebp-10h]
  int bSupportsHDR; // [esp+A6Ch] [ebp-Ch]
  int bounce; // [esp+A70h] [ebp-8h]
  unsigned int v48; // [esp+A74h] [ebp-4h]

  v2 = g_pFileSystem->IBaseFileSystem::__vftable;
  BaseLocalClient = GetBaseLocalClient();
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))v2->IsFileWritable)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: BaseLocalClient->m_szLevelName) != 0 )
  {
    R_BuildCubemapSamples_PreBuild();
    bounce = 0;
    if ( numIterations <= 0 )
    {
LABEL_47:
      R_BuildCubemapSamples_PostBuild();
      UpdateMaterialSystemConfig();
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&reload_materials.IConVar, value: 1);
    }
    else
    {
      while ( 1 )
      {
        if ( bounce != 0 )
          CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "1");
        else
          CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&mat_fastspecular.IConVar, value: "0");
        UpdateMaterialSystemConfig();
        v5 = ((int (__thiscall *)(IClientEntityList *, _DWORD, int))entitylist->GetClientEntity)(
               a1: entitylist,
               a2: 0,
               a3: a1);
        if ( v5 == 0 || (v6 = v5 + 4, (*(int (__thiscall **)(int))(*(_DWORD *)(v5 + 4) + 32))(a1: v5 + 4) == 0) )
        {
          _ConDMsg(a1: "R_BuildCubemapSamples: No map loaded!\n");
          R_BuildCubemapSamples_PostBuild();
          return;
        }
        v7 = (const model_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 32))(a1: v6);
        v8 = modelloader->GetName(this: modelloader, a2: v7);
        if ( V_stristr(pStr: v8, pSearch: "maps/") == v8 || V_stristr(pStr: v8, pSearch: "maps\\") == v8 )
        {
          V_strncpy(pDest: mapName, pSrc: v8 + 5, maxLen: 256);
          V_StripExtension(in: mapName, out: mapName, outSize: 256);
        }
        else
        {
          V_FileBase(in: v8, out: mapName, maxlen: 256);
        }
        ConVarRef::ConVarRef(this: &drawMRMModelsCVar, pName: "r_drawothermodels");
        if ( ConVarRef::IsValid(this: &drawMRMModelsCVar) )
          drawMRMModelsCVar.m_pConVar->SetValue_2(this: drawMRMModelsCVar.m_pConVar, a2: 0);
        LOBYTE(bOldLightSpritesActive) = ActivateLightSprites(bActive: true);
        ivt = VTex_Load(&pModule);
        if ( ivt == nullptr )
          return;
        V_snprintf(pDest: matDir, maxLen: 260, pFormat: "materials/maps/%s", mapName);
        g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: matDir, a3: "DEFAULT_WRITE_PATH");
        V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "materialsrc/maps/%s", mapName);
        GetModContentSubdirectory(pSubDir: pTemp, pBuf: pMaterialSrcDir, nBufLen: 260);
        g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: pMaterialSrcDir, a3: nullptr);
        COM_GetGameDir(szGameDir: gameDir, maxlen: 260);
        v9 = (model_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 32))(a1: v6);
        pShared = v9->brush.pShared;
        v11 = 0;
        pWorldModel = v9;
        if ( pShared->m_nCubemapSamples > 0 )
          break;
LABEL_26:
        LOBYTE(bSupportsHDR) = g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE;
        CUtlSymbolTable::CUtlSymbolTable(
          this: &uniqueCubemaps.m_arrEntries,
          growSize: 0,
          initSize: 16,
          caseInsensitive: false);
        v15 = 0;
        p_m_nCubemapSamples = (int *)(v9->sprite.numframes + 232);
        if ( *p_m_nCubemapSamples > 0 )
        {
          i = bounce + 1;
          v48 = 0;
          do
          {
            v17 = v15 + 1;
            _Warning(a1: "bounce: %d/%d sample: %d/%d\n", i, numIterations, v15 + 1, *p_m_nCubemapSamples);
            v18 = v48 + *(_DWORD *)(v9->sprite.numframes + 228);
            v19 = "_hdr";
            if ( (_BYTE)bSupportsHDR == 0 )
              v19 = defaultValue;
            V_snprintf(
              pDest: pVTFName,
              maxLen: 260,
              pFormat: "%s/c%d_%d_%d%s",
              pMaterialSrcDir,
              (int)*(float *)v18,
              (int)*(float *)(v18 + 4),
              (int)*(float *)(v18 + 8),
              v19);
            v20 = *(_BYTE *)(v18 + 16);
            if ( v20 != 0 )
            {
              m_nValue = 1 << (v20 - 1);
            }
            else if ( mat_envmaptgasize.m_pParent != nullptr )
            {
              m_nValue = mat_envmaptgasize.m_pParent->m_Value.m_nValue;
            }
            else
            {
              m_nValue = 0;
            }
            BuildSingleCubemap(
              pVTFName,
              pCC: &uniqueCubemaps,
              vecOrigin: (const Vector *)v18,
              nSize: m_nValue,
              bHDR: bSupportsHDR,
              pGameDir: gameDir,
              ivt);
            v22 = pWorldModel->brush.pShared;
            v48 += 20;
            v15 = v17;
            p_m_nCubemapSamples = &v22->m_nCubemapSamples;
            v9 = pWorldModel;
          }
          while ( v17 < *p_m_nCubemapSamples );
        }
        CUtlSymbolTable::RemoveAll(this: &uniqueCubemaps.m_arrEntries);
        ActivateLightSprites(bActive: bOldLightSpritesActive);
        FileSystem_UnloadModule(pModule);
        Module = FileSystem_LoadModule(path: "bsppack");
        v24 = Module;
        pModule = Module;
        if ( Module == nullptr
          || (Factory = Sys_GetFactory(pModule: Module)) == nullptr
          || (v26 = (IBSPPack *)Factory(a1: "IBSPPACK003", a2: nullptr)) == nullptr )
        {
          ConMsg(a1: "Can't load bsppack.dll\n");
          R_BuildCubemapSamples_PostBuild();
          CUtlSymbolTable::~CUtlSymbolTable(this: &uniqueCubemaps.m_arrEntries);
          return;
        }
        a1 = bSupportsHDR;
        ((void (__thiscall *)(IBSPPack *))v26->SetHDRMode)(a1: v26);
        V_snprintf(pDest: mapPath, maxLen: 1024, pFormat: "maps/%s.bsp", mapName);
        v26->LoadBSPFile(this: v26, a2: g_pFileSystem, a3: mapPath);
        V_snprintf(pDest: matDir, maxLen: 260, pFormat: "materials/maps/%s", mapName);
        v27 = v9->brush.pShared;
        i = 0;
        if ( v27->m_nCubemapSamples > 0 )
        {
          v48 = 0;
          do
          {
            AddSampleToBSPFile(
              pSample: &v27->m_pCubemapSamples[v48 / 0x14],
              matDir,
              bHDR: bSupportsHDR,
              iBSPPack: v26,
              pCC: &uniqueCubemaps);
            v27 = pWorldModel->brush.pShared;
            v48 += 20;
            ++i;
          }
          while ( i < v27->m_nCubemapSamples );
          v24 = pModule;
        }
        CUtlSymbolTable::RemoveAll(this: &uniqueCubemaps.m_arrEntries);
        Cubemap_CreateDefaultCubemap(a1: (int)v26, a2: (int)v24, pMapName: mapName, iBSPPack: v26);
        v26->WriteBSPFile(this: v26, a2: mapPath);
        v26->ClearPackFile(this: v26);
        FileSystem_UnloadModule(pModule: v24);
        if ( Host_IsSinglePlayerGame() )
          v30 = "restart setpos\n";
        else
          v30 = va(format: "map %s\n", mapName);
        TraceType = CTraceFilter::GetTraceType(this: v28);
        Cbuf_AddText(eTarget: TraceType, pText: v30, nTickDelay: 0);
        CUtlSymbolTable::~CUtlSymbolTable(this: &uniqueCubemaps.m_arrEntries);
        if ( ++bounce >= numIterations )
          goto LABEL_47;
      }
      v48 = 0;
      while ( 1 )
      {
        size = pShared->m_pCubemapSamples[v48 / 0x14].size;
        if ( size != 0 )
          v13 = 1 << (size - 1);
        else
          v13 = mat_envmaptgasize.m_pParent != nullptr ? mat_envmaptgasize.m_pParent->m_Value.m_nValue : 0;
        v14 = 4 * v13;
        if ( 4 * v13 > videomode->GetModeWidth(this: videomode) || v14 > videomode->GetModeHeight(this: videomode) )
          break;
        pShared = v9->brush.pShared;
        v48 += 20;
        if ( ++v11 >= pShared->m_nCubemapSamples )
          goto LABEL_26;
      }
      _Warning(
        a1: "Cube map buffer size %d x %d is bigger than screen!\n"
        "Run at a higher resolution! or reduce your cubemap resolution (needs 4X)\n",
        v14,
        v14);
      R_BuildCubemapSamples_PostBuild();
    }
  }
  else
  {
    v4 = GetBaseLocalClient();
    _Warning(a1: "%s is not writable!!!  Check it out before running buildcubemaps.\n", v4->m_szLevelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069C10
// Name: buildcubemaps
// Source: json
//------------------------------------------------------------------------------
void __usercall buildcubemaps(int a1@<ebx>, const CCommand *args)
{
  int v2; // eax
  BOOL bAllow; // [esp+0h] [ebp-4h]

  LOBYTE(bAllow) = Host_AllowQueuedMaterialSystem(bAllow: false);
  V_RenderVGuiOnly();
  if ( args->m_nArgc == 1 )
  {
    R_BuildCubemapSamples(a1, numIterations: 1);
    Host_AllowQueuedMaterialSystem(bAllow);
  }
  else
  {
    if ( args->m_nArgc == 2 )
    {
      v2 = atoi(nptr: args->m_ppArgv[1]);
      R_BuildCubemapSamples(a1, numIterations: v2);
    }
    else
    {
      ConMsg(a1: "Usage: buildcubemaps [numBounces]\n");
    }
    Host_AllowQueuedMaterialSystem(bAllow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069CF0
// Name: WriteLightProbe
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteLightProbe(const char *pBasePath@<eax>, const LightingState_t *state, bool bHDR)
{
  CDmxElement *DmxElement; // ebx
  const char *v5; // esi
  CDmxAttribute *v6; // eax
  CDmxAttribute *v7; // eax
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // eax
  CDmxAttribute *v10; // esi
  _DWORD *m_pData; // eax
  const LightingState_t *v12; // edx
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v13; // esi
  CVTFTexture::ResourceMemorySection *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CVTFTexture::ResourceMemorySection *v16; // ecx
  int v17; // eax
  CVTFTexture::ResourceMemorySection *v18; // eax
  bool v19; // zf
  CDmxAttribute *v20; // eax
  CDmxAttribute *v21; // esi
  _DWORD *v22; // eax
  CDmxElement *v23; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v24; // ebx
  int m_Size; // edi
  CDmxElement *v26; // esi
  int v27; // eax
  CDmxElement **v28; // ecx
  int v29; // eax
  CDmxElement **v30; // edi
  dworldlight_t *v31; // ebx
  CDmxAttribute *v32; // edi
  _DWORD *v33; // edi
  CDmxAttribute *v34; // eax
  CDmxAttribute *v35; // edi
  _DWORD *v36; // edi
  CDmxAttribute *v37; // edi
  float *v38; // edi
  float v39; // ecx
  float v40; // edx
  CDmxAttribute *v41; // edi
  float *v42; // edi
  CDmxAttribute *v43; // eax
  CDmxAttribute *v44; // edi
  _DWORD *v45; // edi
  CDmxAttribute *v46; // edi
  _DWORD *v47; // edi
  CDmxAttribute *v48; // edi
  float *v49; // edi
  float v50; // ecx
  float v51; // edx
  CDmxAttribute *v52; // edi
  float *v53; // edi
  long double v54; // st7
  CDmxAttribute *v55; // edi
  float *v56; // edi
  long double v57; // st7
  float exponent; // xmm0_4
  CDmxAttribute *v59; // edi
  float *v60; // edi
  CDmxAttribute *v61; // eax
  CDmxAttribute *v62; // edi
  _DWORD *v63; // edi
  CDmxAttribute *v64; // edi
  _DWORD *v65; // edi
  CDmxAttribute *v66; // edi
  _DWORD *v67; // edi
  int v68; // ecx
  int v69; // edx
  CDmxAttribute *v70; // edi
  _DWORD *v71; // edi
  CDmxAttribute *v72; // edi
  _DWORD *v73; // edi
  CDmxAttribute *v74; // edi
  _DWORD *v75; // edi
  CDmxAttribute *v76; // eax
  CDmxAttribute *v77; // edi
  _DWORD *v78; // edi
  CDmxElement *v79; // esi
  char pTemp[260]; // [esp+Ch] [ebp-278h] BYREF
  char pFullPath[260]; // [esp+110h] [ebp-174h] BYREF
  CUtlBuffer buf; // [esp+214h] [ebp-70h] BYREF
  float constant_attn; // [esp+244h] [ebp-40h]
  float linear_attn; // [esp+248h] [ebp-3Ch]
  float quadratic_attn; // [esp+24Ch] [ebp-38h]
  float stopdot2; // [esp+250h] [ebp-34h]
  float stopdot; // [esp+254h] [ebp-30h]
  int v88; // [esp+258h] [ebp-2Ch]
  int v89; // [esp+25Ch] [ebp-28h]
  int v90; // [esp+260h] [ebp-24h]
  float v91; // [esp+264h] [ebp-20h]
  float v92; // [esp+268h] [ebp-1Ch]
  float v93; // [esp+26Ch] [ebp-18h]
  CDmxElement *pLightProbe; // [esp+270h] [ebp-14h]
  CDmxElementModifyScope modify; // [esp+274h] [ebp-10h]
  int i; // [esp+278h] [ebp-Ch]
  float v97; // [esp+27Ch] [ebp-8h]
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *lights; // [esp+280h] [ebp-4h]
  const LightingState_t *bHDRa; // [esp+290h] [ebp+Ch]
  dworldlight_t **bHDRb; // [esp+290h] [ebp+Ch]

  V_strncpy(pDest: pFullPath, pSrc: pBasePath, maxLen: 260);
  V_SetExtension(path: pFullPath, extension: ".prb", pathStringLength: 260);
  BeginDMXContext();
  DmxElement = CreateDmxElement(pType: "DmeElement");
  pLightProbe = DmxElement;
  v5 = &pBasePath[_V_strlen(str: "materials/")];
  modify.m_pElement = DmxElement;
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  v6 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: "name");
  CDmxAttribute::SetValue(this: v6, pString: "lightprobe");
  if ( DmxElement != nullptr )
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: "cubemap");
  CDmxAttribute::SetValue(this: v7, pString: v5);
  if ( DmxElement != nullptr )
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
  if ( bHDR )
  {
    V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "%s_hdr", v5);
    CDmxElement::LockForChanges(this: DmxElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: "cubemapHdr");
    CDmxAttribute::SetValue(this: v8, pString: pTemp);
    if ( DmxElement != nullptr )
      CDmxElement::LockForChanges(this: DmxElement, bLock: false);
  }
  v9 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: "ambientCube");
  v10 = v9;
  if ( v9->m_Type != AT_VECTOR3_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v9, type: AT_VECTOR3_ARRAY);
    m_pData = v10->m_pData;
    if ( m_pData != nullptr )
    {
      *m_pData = 0;
      m_pData[1] = 0;
      m_pData[2] = 0;
      m_pData[3] = 0;
      m_pData[4] = 0;
    }
  }
  v12 = state;
  v13 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)v10->m_pData;
  bHDRa = state;
  lights = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)6;
  do
  {
    m_pMemory = v13[1].m_pMemory;
    m_nAllocationCount = v13->m_nAllocationCount;
    if ( (int)&m_pMemory->m_nDataAllocSize + 1 > m_nAllocationCount )
    {
      CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
        this: v13,
        num: (int)&m_pMemory->m_nDataAllocSize - m_nAllocationCount + 1);
      v12 = bHDRa;
    }
    ++v13[1].m_pMemory;
    v16 = v13->m_pMemory;
    v17 = (char *)v13[1].m_pMemory - (char *)m_pMemory - 1;
    v13[1].m_nAllocationCount = (int)v13->m_pMemory;
    if ( v17 > 0 )
    {
      _V_memmove(dest: &v16[(int)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 12 * v17);
      v12 = bHDRa;
    }
    v18 = &v13->m_pMemory[(_DWORD)m_pMemory];
    if ( v18 != nullptr )
    {
      v18->m_nDataAllocSize = LODWORD(v12->r_boxcolor[0].x);
      v18->m_nDataLength = LODWORD(v12->r_boxcolor[0].y);
      v18->m_pData = (unsigned __int8 *)LODWORD(v12->r_boxcolor[0].z);
    }
    v12 = (const LightingState_t *)((char *)v12 + 12);
    v19 = lights == (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)1;
    lights = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)((char *)lights - 1);
    bHDRa = v12;
  }
  while ( !v19 );
  v20 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: "localLights");
  v21 = v20;
  if ( v20->m_Type == AT_FIRST_ARRAY_TYPE )
  {
    lights = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v20->m_pData;
  }
  else
  {
    CDmxAttribute::AllocateDataMemory(this: v20, type: AT_FIRST_ARRAY_TYPE);
    v22 = v21->m_pData;
    if ( v22 != nullptr )
    {
      *v22 = 0;
      v22[1] = 0;
      v22[2] = 0;
      v22[3] = 0;
      v22[4] = 0;
    }
    lights = (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v21->m_pData;
  }
  if ( DmxElement != nullptr )
  {
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
    modify.m_pElement = nullptr;
  }
  i = 0;
  if ( state->numlights > 0 )
  {
    bHDRb = state->locallight;
    while ( 2 )
    {
      v23 = CreateDmxElement(pType: "DmeElement");
      v24 = lights;
      m_Size = lights->m_Size;
      v26 = v23;
      v27 = lights->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > v27 )
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)lights, num: m_Size - v27 + 1);
      ++v24->m_Size;
      v28 = v24->m_Memory.m_pMemory;
      v29 = v24->m_Size - m_Size - 1;
      v24->m_pElements = v24->m_Memory.m_pMemory;
      if ( v29 > 0 )
        _V_memmove(dest: &v28[m_Size + 1], src: &v28[m_Size], count: 4 * v29);
      v30 = &v24->m_Memory.m_pMemory[m_Size];
      if ( v30 != nullptr )
        *v30 = v26;
      CDmxElement::LockForChanges(this: v26, bLock: true);
      v31 = *bHDRb;
      CDmxElement::LockForChanges(this: v26, bLock: true);
      v32 = CDmxElement::AddAttribute(this: v26, pAttributeName: "color");
      CDmxAttribute::AllocateDataMemory(this: v32, type: AT_VECTOR3);
      v33 = v32->m_pData;
      if ( v33 != nullptr )
      {
        *v33 = LODWORD(v31->intensity.x);
        v33[1] = LODWORD(v31->intensity.y);
        v33[2] = LODWORD(v31->intensity.z);
      }
      if ( v26 != nullptr )
        CDmxElement::LockForChanges(this: v26, bLock: false);
      switch ( v31->type )
      {
        case emit_surface:
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v61 = CDmxElement::AddAttribute(this: v26, pAttributeName: "name");
          CDmxAttribute::SetValue(this: v61, pString: "Spot");
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v62 = CDmxElement::AddAttribute(this: v26, pAttributeName: "origin");
          CDmxAttribute::AllocateDataMemory(this: v62, type: AT_VECTOR3);
          v63 = v62->m_pData;
          if ( v63 != nullptr )
          {
            *v63 = LODWORD(v31->origin.x);
            v63[1] = LODWORD(v31->origin.y);
            v63[2] = LODWORD(v31->origin.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v64 = CDmxElement::AddAttribute(this: v26, pAttributeName: "direction");
          CDmxAttribute::AllocateDataMemory(this: v64, type: AT_VECTOR3);
          v65 = v64->m_pData;
          if ( v65 != nullptr )
          {
            *v65 = LODWORD(v31->normal.x);
            v65[1] = LODWORD(v31->normal.y);
            v65[2] = LODWORD(v31->normal.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          v88 = 0;
          v89 = 0;
          v90 = 1065353216;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v66 = CDmxElement::AddAttribute(this: v26, pAttributeName: "attenuation");
          CDmxAttribute::AllocateDataMemory(this: v66, type: AT_VECTOR3);
          v67 = v66->m_pData;
          if ( v67 != nullptr )
          {
            v68 = v89;
            v69 = v90;
            *v67 = v88;
            v67[1] = v68;
            v67[2] = v69;
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v70 = CDmxElement::AddAttribute(this: v26, pAttributeName: "theta");
          CDmxAttribute::AllocateDataMemory(this: v70, type: AT_FLOAT);
          v71 = v70->m_pData;
          if ( v71 != nullptr )
            *v71 = 0;
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v72 = CDmxElement::AddAttribute(this: v26, pAttributeName: "phi");
          CDmxAttribute::AllocateDataMemory(this: v72, type: AT_FLOAT);
          v73 = v72->m_pData;
          if ( v73 != nullptr )
            *v73 = 0;
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v74 = CDmxElement::AddAttribute(this: v26, pAttributeName: "exponent");
          CDmxAttribute::AllocateDataMemory(this: v74, type: AT_FLOAT);
          v75 = v74->m_pData;
          if ( v75 != nullptr )
            *v75 = 1065353216;
          goto LABEL_47;
        case emit_point:
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v34 = CDmxElement::AddAttribute(this: v26, pAttributeName: "name");
          CDmxAttribute::SetValue(this: v34, pString: "Point");
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v35 = CDmxElement::AddAttribute(this: v26, pAttributeName: "origin");
          CDmxAttribute::AllocateDataMemory(this: v35, type: AT_VECTOR3);
          v36 = v35->m_pData;
          if ( v36 != nullptr )
          {
            *v36 = LODWORD(v31->origin.x);
            v36[1] = LODWORD(v31->origin.y);
            v36[2] = LODWORD(v31->origin.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          constant_attn = v31->constant_attn;
          linear_attn = v31->linear_attn;
          quadratic_attn = v31->quadratic_attn;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v37 = CDmxElement::AddAttribute(this: v26, pAttributeName: "attenuation");
          CDmxAttribute::AllocateDataMemory(this: v37, type: AT_VECTOR3);
          v38 = (float *)v37->m_pData;
          if ( v38 != nullptr )
          {
            v39 = linear_attn;
            v40 = quadratic_attn;
            *v38 = constant_attn;
            v38[1] = v39;
            v38[2] = v40;
          }
          goto LABEL_47;
        case emit_spotlight:
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v43 = CDmxElement::AddAttribute(this: v26, pAttributeName: "name");
          CDmxAttribute::SetValue(this: v43, pString: "Spot");
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v44 = CDmxElement::AddAttribute(this: v26, pAttributeName: "origin");
          CDmxAttribute::AllocateDataMemory(this: v44, type: AT_VECTOR3);
          v45 = v44->m_pData;
          if ( v45 != nullptr )
          {
            *v45 = LODWORD(v31->origin.x);
            v45[1] = LODWORD(v31->origin.y);
            v45[2] = LODWORD(v31->origin.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v46 = CDmxElement::AddAttribute(this: v26, pAttributeName: "direction");
          CDmxAttribute::AllocateDataMemory(this: v46, type: AT_VECTOR3);
          v47 = v46->m_pData;
          if ( v47 != nullptr )
          {
            *v47 = LODWORD(v31->normal.x);
            v47[1] = LODWORD(v31->normal.y);
            v47[2] = LODWORD(v31->normal.z);
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          v91 = v31->constant_attn;
          v92 = v31->linear_attn;
          v93 = v31->quadratic_attn;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v48 = CDmxElement::AddAttribute(this: v26, pAttributeName: "attenuation");
          CDmxAttribute::AllocateDataMemory(this: v48, type: AT_VECTOR3);
          v49 = (float *)v48->m_pData;
          if ( v49 != nullptr )
          {
            v50 = v92;
            v51 = v93;
            *v49 = v91;
            v49[1] = v50;
            v49[2] = v51;
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          stopdot = v31->stopdot;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v52 = CDmxElement::AddAttribute(this: v26, pAttributeName: "theta");
          CDmxAttribute::AllocateDataMemory(this: v52, type: AT_FLOAT);
          v53 = (float *)v52->m_pData;
          if ( v53 != nullptr )
          {
            v54 = acos(stopdot);
            *v53 = v54 + v54;
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          stopdot2 = v31->stopdot2;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v55 = CDmxElement::AddAttribute(this: v26, pAttributeName: "phi");
          CDmxAttribute::AllocateDataMemory(this: v55, type: AT_FLOAT);
          v56 = (float *)v55->m_pData;
          if ( v56 != nullptr )
          {
            v57 = acos(stopdot2);
            *v56 = v57 + v57;
          }
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          exponent = v31->exponent;
          if ( exponent == 0.0 )
            exponent = 1.0;
          v97 = exponent;
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v59 = CDmxElement::AddAttribute(this: v26, pAttributeName: "exponent");
          CDmxAttribute::AllocateDataMemory(this: v59, type: AT_FLOAT);
          v60 = (float *)v59->m_pData;
          if ( v60 != nullptr )
            *v60 = v97;
LABEL_47:
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v41 = CDmxElement::AddAttribute(this: v26, pAttributeName: "maxDistance");
          CDmxAttribute::AllocateDataMemory(this: v41, type: AT_FLOAT);
          v42 = (float *)v41->m_pData;
          if ( v42 != nullptr )
            *v42 = v31->radius;
          goto LABEL_105;
        case emit_skylight:
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v76 = CDmxElement::AddAttribute(this: v26, pAttributeName: "name");
          CDmxAttribute::SetValue(this: v76, pString: "Directional");
          if ( v26 != nullptr )
            CDmxElement::LockForChanges(this: v26, bLock: false);
          CDmxElement::LockForChanges(this: v26, bLock: true);
          v77 = CDmxElement::AddAttribute(this: v26, pAttributeName: "direction");
          CDmxAttribute::AllocateDataMemory(this: v77, type: AT_VECTOR3);
          v78 = v77->m_pData;
          if ( v78 != nullptr )
          {
            *v78 = LODWORD(v31->normal.x);
            v78[1] = LODWORD(v31->normal.y);
            v78[2] = LODWORD(v31->normal.z);
          }
LABEL_105:
          if ( v26 != nullptr )
          {
            CDmxElement::LockForChanges(this: v26, bLock: false);
LABEL_107:
            if ( v26 != nullptr )
              CDmxElement::LockForChanges(this: v26, bLock: false);
          }
          ++bHDRb;
          if ( ++i >= state->numlights )
            break;
          continue;
        default:
          goto LABEL_107;
      }
      break;
    }
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  v79 = pLightProbe;
  if ( SerializeDMX(&buf, pRoot: pLightProbe, pFileName: pFullPath) )
    g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFullPath, a3: "MOD", a4: &buf);
  CleanupDMX(pRoot: v79);
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( modify.m_pElement != nullptr )
    CDmxElement::LockForChanges(this: modify.m_pElement, bLock: false);
  EndDMXContext(bDecommitMemory: true);
}

//------------------------------------------------------------------------------
// Address: 0x1006A600
// Name: lightprobe
// Source: json
//------------------------------------------------------------------------------
void __usercall lightprobe(int a1@<ebx>, const CCommand *args)
{
  int m_nArgc; // eax
  bool v4; // cc
  const char *v5; // eax
  IVTex *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  HDRType_t v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  char pTemp2[260]; // [esp+4h] [ebp-57Ch] BYREF
  char pGameDir[260]; // [esp+108h] [ebp-478h] BYREF
  char pTemp[260]; // [esp+20Ch] [ebp-374h] BYREF
  char pBasePath[260]; // [esp+310h] [ebp-270h] BYREF
  char pMaterialSrcPath[260]; // [esp+414h] [ebp-16Ch] BYREF
  LightingState_t lightingState; // [esp+518h] [ebp-68h] BYREF
  LightcacheGetDynamic_Stats stats; // [esp+574h] [ebp-Ch] BYREF
  struct CSysModule *pModule; // [esp+578h] [ebp-8h] BYREF
  BOOL bHDR; // [esp+57Ch] [ebp-4h]
  int nTGASize; // [esp+588h] [ebp+8h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    if ( mat_envmaptgasize.m_pParent != nullptr )
      nTGASize = mat_envmaptgasize.m_pParent->m_Value.m_nValue;
    else
      nTGASize = 0;
    if ( m_nArgc >= 3 )
    {
      v4 = m_nArgc <= 2;
      v5 = defaultValue;
      if ( !v4 )
        v5 = args->m_ppArgv[2];
      nTGASize = atoi(nptr: v5);
    }
    v6 = VTex_Load(&pModule);
    if ( v6 != nullptr )
    {
      v7 = defaultValue;
      if ( args->m_nArgc > 1 )
        v7 = args->m_ppArgv[1];
      V_snprintf(pDest: pBasePath, maxLen: 260, pFormat: "materials/lightprobes/%s", v7);
      V_StripFilename(path: pBasePath);
      ((void (__thiscall *)(IFileSystem *, char *, const char *, int))g_pFileSystem->CreateDirHierarchy)(
        a1: g_pFileSystem,
        a2: pBasePath,
        a3: "DEFAULT_WRITE_PATH",
        a4: a1);
      v8 = defaultValue;
      if ( args->m_nArgc > 1 )
        v8 = args->m_ppArgv[1];
      V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "materialsrc/lightprobes/%s", v8);
      GetModContentSubdirectory(pSubDir: pTemp, pBuf: pMaterialSrcPath, nBufLen: 260);
      V_StripFilename(path: pMaterialSrcPath);
      ((void (__thiscall *)(IFileSystem *, char *))g_pFileSystem->CreateDirHierarchy)(
        a1: g_pFileSystem,
        a2: pMaterialSrcPath);
      COM_GetGameDir(szGameDir: pGameDir, maxlen: 260);
      v9 = g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig);
      LOBYTE(bHDR) = v9 != HDR_TYPE_NONE;
      if ( v9 != HDR_TYPE_NONE )
      {
        v10 = defaultValue;
        if ( args->m_nArgc > 1 )
          v10 = args->m_ppArgv[1];
        V_snprintf(pDest: pTemp2, maxLen: 260, pFormat: "materialsrc/lightprobes/%s_hdr", v10);
        GetModContentSubdirectory(pSubDir: pTemp2, pBuf: pMaterialSrcPath, nBufLen: 260);
        BuildSingleCubemap(
          pVTFName: pMaterialSrcPath,
          pCC: nullptr,
          vecOrigin: g_MainViewOrigin,
          nSize: nTGASize,
          bHDR: 1,
          pGameDir,
          ivt: v6);
      }
      GetModContentSubdirectory(pSubDir: pTemp, pBuf: pMaterialSrcPath, nBufLen: 260);
      BuildSingleCubemap(
        pVTFName: pMaterialSrcPath,
        pCC: nullptr,
        vecOrigin: g_MainViewOrigin,
        nSize: nTGASize,
        bHDR: 0,
        pGameDir,
        ivt: v6);
      FileSystem_UnloadModule(pModule);
      memset(&lightingState, 0, 76);
      LightcacheGetDynamic(
        a1: 0.0,
        origin: g_MainViewOrigin,
        &lightingState,
        &stats,
        pRenderable: nullptr,
        flags: 7,
        bDebugModel: false);
      if ( args->m_nArgc > 1 )
        v11 = args->m_ppArgv[1];
      else
        v11 = defaultValue;
      V_snprintf(pDest: pBasePath, maxLen: 260, pFormat: "materials/lightprobes/%s", v11);
      WriteLightProbe(pBasePath, state: &lightingState, bHDR);
    }
  }
  else
  {
    ConMsg(a1: "sample_lighting usage: lightprobe <base file name> [cubemap dimension]\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10312AE0
// Name: _dynamic_initializer_for__buildcubemaps_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__buildcubemaps_command__()
{
  ConCommand::ConCommand(
    this: &buildcubemaps_command,
    pName: "buildcubemaps",
    callback: (void (__cdecl *)(const CCommand *))buildcubemaps,
    pHelpString: "Rebuild cubemaps.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__buildcubemaps_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103224A0
// Name: _dynamic_atexit_destructor_for__buildcubemaps_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__buildcubemaps_command__()
{
  ConCommand::~ConCommand(this: &buildcubemaps_command);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1031B920
// Name: _dynamic_initializer_for__maps__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__maps__()
{
  ConCommand::ConCommand(
    this: &maps,
    pName: "maps",
    callback: Host_Maps_f,
    pHelpString: "Displays list of maps.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__maps__);
}

//------------------------------------------------------------------------------
// Address: 0x10325C70
// Name: _dynamic_atexit_destructor_for__maps__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__maps__()
{
  ConCommand::~ConCommand(this: &maps);
}

//------------------------------------------------------------------------------
// Address: 0x1031B950
// Name: _dynamic_initializer_for__map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map__()
{
  ConCommand::ConCommand(
    this: &map,
    pName: "map",
    callback: Host_Map_f,
    pHelpString: "Start playing on specified map.",
    flags: 0x20000,
    completionFunc: Host_Map_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__map__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B980
// Name: _dynamic_initializer_for__ss_map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_map__()
{
  ConCommand::ConCommand(
    this: &ss_map,
    pName: "ss_map",
    callback: Host_SplitScreen_Map_f,
    pHelpString: "Start playing on specified map with max allowed splitscreen players.",
    flags: 0x20000,
    completionFunc: Host_SSMap_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__ss_map__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B9B0
// Name: _dynamic_initializer_for__map_background__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_background__()
{
  ConCommand::ConCommand(
    this: &map_background,
    pName: "map_background",
    callback: Host_Map_Background_f,
    pHelpString: "Runs a map as the background to the main menu.",
    flags: 0x20000,
    completionFunc: Host_Background_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__map_background__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B9E0
// Name: _dynamic_initializer_for__map_commentary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_commentary__()
{
  ConCommand::ConCommand(
    this: &map_commentary,
    pName: "map_commentary",
    callback: Host_Map_Commentary_f,
    pHelpString: "Start playing, with commentary, on a specified map.",
    flags: 0x20000,
    completionFunc: Host_Map_Commentary_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__map_commentary__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BA10
// Name: _dynamic_initializer_for__changelevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__changelevel__()
{
  ConCommand::ConCommand(
    this: &changelevel,
    pName: "changelevel",
    callback: Host_Changelevel_f,
    pHelpString: "Change server to the specified map",
    flags: 0x20000,
    completionFunc: Host_Changelevel_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__changelevel__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BA40
// Name: _dynamic_initializer_for__changelevel2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__changelevel2__()
{
  ConCommand::ConCommand(
    this: &changelevel2,
    pName: "changelevel2",
    callback: Host_Changelevel2_f,
    pHelpString: "Transition to the specified map in single player",
    flags: 0x20000,
    completionFunc: Host_Changelevel2_f_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__changelevel2__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BA70
// Name: _dynamic_initializer_for__g_PhoneHome__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_PhoneHome__()
{
  netadr_s::SetIP(this: &g_PhoneHome.m_cserIP, unIP: 0);
  netadr_s::SetPort(this: &g_PhoneHome.m_cserIP, newport: 0);
  netadr_s::SetType(this: &g_PhoneHome.m_cserIP, newtype: NA_IP);
  g_PhoneHome.m_uSessionID = 0;
  g_PhoneHome.m_pSocket = nullptr;
  _V_memset(dest: &g_PhoneHome.m_cserIP, fill: 0, count: 12);
  _V_memset(dest: g_PhoneHome.m_szBuildIdentifier, fill: 0, count: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10325C80
// Name: _dynamic_atexit_destructor_for__map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map__()
{
  ConCommand::~ConCommand(this: &map);
}

//------------------------------------------------------------------------------
// Address: 0x10325C90
// Name: _dynamic_atexit_destructor_for__ss_map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_map__()
{
  ConCommand::~ConCommand(this: &ss_map);
}

//------------------------------------------------------------------------------
// Address: 0x10325CA0
// Name: _dynamic_atexit_destructor_for__map_background__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_background__()
{
  ConCommand::~ConCommand(this: &map_background);
}

//------------------------------------------------------------------------------
// Address: 0x10325CB0
// Name: _dynamic_atexit_destructor_for__map_commentary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_commentary__()
{
  ConCommand::~ConCommand(this: &map_commentary);
}

//------------------------------------------------------------------------------
// Address: 0x10325CC0
// Name: _dynamic_atexit_destructor_for__changelevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__changelevel__()
{
  ConCommand::~ConCommand(this: &changelevel);
}

//------------------------------------------------------------------------------
// Address: 0x10325CD0
// Name: _dynamic_atexit_destructor_for__changelevel2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__changelevel2__()
{
  ConCommand::~ConCommand(this: &changelevel2);
}

//------------------------------------------------------------------------------
// Address: 0x10325CE0
// Name: _dynamic_atexit_destructor_for__g_MapListMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MapListMgr__()
{
  CUtlDict<CMapListItem,int>::RemoveAll(this: &g_MapListMgr.m_Items);
  g_MapListMgr.m_bDirty = false;
  CUtlDict<CMapListItem,int>::RemoveAll(this: &g_MapListMgr.m_Items);
  CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CMapListItem,int>::Node_t,int,CUtlMap<char const *,CMapListItem,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapListItem,int>::Node_t,int>,int>>(this: &g_MapListMgr.m_Items.m_Elements.m_Tree);
}

} // namespace engine_xlsp
