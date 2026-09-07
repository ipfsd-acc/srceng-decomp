// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/buildermaterial.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401B30
// Name: struct TextureData_t __near * UniqueTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
TextureData_t *__cdecl UniqueTexture(const char *pTextureName)
{
  unsigned __int16 m_Id; // ax
  unsigned __int16 v2; // di
  int v3; // eax
  TextureData_t *v4; // eax
  TextureData_t *v5; // esi
  CUtlSymbol v7; // [esp+Ah] [ebp-6h] BYREF
  CUtlSymbol v8; // [esp+Ch] [ebp-4h] BYREF

  m_Id = CUtlSymbolTable::Find(this: &g_globalTextureDict.m_SymbolTable, result: &v7, pString: pTextureName)->m_Id;
  if ( m_Id != 0xFFFF )
    return g_globalTextureDict.m_Vector.m_Memory.m_pMemory[m_Id];
  CUtlSymbolTable::AddString(this: &g_globalTextureDict.m_SymbolTable, result: &v8, pString: pTextureName);
  v2 = v8.m_Id;
  if ( g_globalTextureDict.m_Vector.m_Size <= v8.m_Id )
  {
    v3 = v8.m_Id + 1;
    if ( g_globalTextureDict.m_Vector.m_Size < v3 )
    {
      CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&g_globalTextureDict,
        elem: g_globalTextureDict.m_Vector.m_Size,
        num: v3 - g_globalTextureDict.m_Vector.m_Size);
      v2 = v8.m_Id;
    }
  }
  v4 = (TextureData_t *)MemAlloc_Alloc(nSize: 0x154u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pHWTexture = nullptr;
    v4->m_XRes = 0;
    v4->m_YRes = 0;
    v4->m_Mips = 0;
    v4->m_Format = IMAGE_FORMAT_DXT1;
    v4->m_SizeBytes = 0;
    v4->m_vMinUsedBounds.x = 0.0;
    v4->m_vMinUsedBounds.y = 0.0;
    v4->m_vMaxUsedBounds.x = 0.0;
    v4->m_vMaxUsedBounds.y = 0.0;
    v4->m_vMaxTextureSize.x = 0.0;
    v4->m_vMaxTextureSize.y = 0.0;
    v4->m_vMaxWorldPerUV.x = 0.0;
    v4->m_vMaxWorldPerUV.y = 0.0;
    v4->m_vAtlasMin.x = 0.0;
    v4->m_vAtlasMin.y = 0.0;
    v4->m_vAtlasMax.x = 0.0;
    v4->m_vAtlasMax.y = 0.0;
    *(_WORD *)&v4->m_bUsed = 0;
    v4->m_pAtlas = nullptr;
    memset(dst: (unsigned __int8 *)v4->m_szFileName, value: 0, count: sizeof(v4->m_szFileName));
  }
  else
  {
    v5 = nullptr;
  }
  g_globalTextureDict.m_Vector.m_Memory.m_pMemory[v2] = v5;
  _V_memset(dest: g_globalTextureDict.m_Vector.m_Memory.m_pMemory[v2], fill: 0, count: 340);
  V_strncpy(pDest: g_globalTextureDict.m_Vector.m_Memory.m_pMemory[v2]->m_szFileName, pSrc: pTextureName, maxLen: 128);
  return g_globalTextureDict.m_Vector.m_Memory.m_pMemory[v2];
}

//------------------------------------------------------------------------------
// Address: 0x00401C90
// Name: bool CreateMaterialFromVMT(struct BuilderMaterial_t __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateMaterialFromVMT(BuilderMaterial_t *pMaterialOut, char *pVMTName)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  int v6; // eax
  const char *String; // eax
  IBaseFileSystem *v8; // ecx
  const char *v9; // ebx
  TextureData_t *v10; // eax
  int v11; // ebx
  const char *v12; // ecx
  const char *v13; // eax
  const char *v14; // [esp-8h] [ebp-138h]
  const char *v15; // [esp-8h] [ebp-138h]
  char szPath[260]; // [esp+8h] [ebp-128h] BYREF
  const char *palpha; // [esp+10Ch] [ebp-24h]
  const char *palphatest; // [esp+110h] [ebp-20h]
  const char *pbasetex; // [esp+114h] [ebp-1Ch]
  const char *pphongboost; // [esp+118h] [ebp-18h]
  const char *pbumpmap; // [esp+11Ch] [ebp-14h]
  const char *pphongexp; // [esp+120h] [ebp-10h]
  const char *pphong; // [esp+124h] [ebp-Ch]
  const char *pphongexptexture; // [esp+128h] [ebp-8h]
  bool bSSBump; // [esp+12Eh] [ebp-2h]
  bool bAlpha; // [esp+12Fh] [ebp-1h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SomeMaterial");
  else
    v3 = nullptr;
  V_snprintf(pDest: szPath, maxLen: 260, pFormat: "materials\\%s.vmt", pVMTName);
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v3,
          filesystem: v4,
          resourceName: szPath,
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Msg(a1: "Failed to load %s\n", szPath);
LABEL_9:
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
    return 0;
  }
  strstr(str1: (unsigned __int8 *)pVMTName, str2: "maps");
  if ( v6 != 0 )
  {
    String = KeyValues::GetString(this: v3, keyName: "include", defaultValue: var);
    v8 = g_pFullFileSystem != nullptr ? &g_pFullFileSystem->IBaseFileSystem : nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v3,
            filesystem: v8,
            resourceName: String,
            pathID: "GAME",
            pfnEvaluateSymbolProc: nullptr) )
      goto LABEL_9;
  }
  pbasetex = KeyValues::GetString(this: v3, keyName: "$basetexture", defaultValue: var);
  pbumpmap = KeyValues::GetString(this: v3, keyName: "$bumpmap", defaultValue: var);
  pphong = KeyValues::GetString(this: v3, keyName: "$phong", defaultValue: var);
  pphongexptexture = KeyValues::GetString(this: v3, keyName: "$phongexponenttexture", defaultValue: var);
  pphongexp = KeyValues::GetString(this: v3, keyName: "$phongexponent", defaultValue: var);
  pphongboost = KeyValues::GetString(this: v3, keyName: "$phongboost", defaultValue: var);
  palphatest = KeyValues::GetString(this: v3, keyName: "$alphatest", defaultValue: var);
  v9 = KeyValues::GetString(this: v3, keyName: "$ssbump", defaultValue: var);
  palpha = KeyValues::GetString(this: v3, keyName: "$alpha", defaultValue: var);
  _V_memset(dest: pMaterialOut, fill: 0, count: 248);
  bSSBump = false;
  if ( v9 != nullptr )
    bSSBump = *v9 != 0;
  bAlpha = false;
  if ( palpha != nullptr && *palpha != 0 )
    bAlpha = atoi(nptr: palpha) == 1;
  if ( pbasetex != nullptr && *pbasetex != 0 )
  {
    v14 = pbasetex;
    *(_WORD *)&pMaterialOut->m_Material.m_Binds[0].m_cBindStage = 4;
    pMaterialOut->m_Material.m_Binds[0].m_cBindSampler = 0;
    v10 = UniqueTexture(pTextureName: v14);
  }
  else
  {
    _Msg(a1: "No base texture!!!\n");
    *(_WORD *)&pMaterialOut->m_Material.m_Binds[0].m_cBindStage = 4;
    pMaterialOut->m_Material.m_Binds[0].m_cBindSampler = 0;
    v10 = UniqueTexture(pTextureName: "Lights/White");
  }
  pMaterialOut->m_ppTextures[0] = v10;
  v11 = 1;
  if ( pbumpmap != nullptr && *pbumpmap != 0 && !bSSBump )
  {
    v15 = pbumpmap;
    *(_WORD *)&pMaterialOut->m_Material.m_Binds[1].m_cBindStage = 260;
    pMaterialOut->m_Material.m_Binds[1].m_cBindSampler = 0;
    pMaterialOut->m_ppTextures[1] = UniqueTexture(pTextureName: v15);
    v11 = 2;
    pMaterialOut->m_Material.m_bNormalMap = true;
    _Msg(a1: "%s has normal map\n", pVMTName);
  }
  v12 = pphongexptexture;
  if ( pphongexptexture != nullptr && *pphongexptexture != 0 )
  {
    *(_WORD *)(&pMaterialOut->m_Material.m_Binds[0].m_cBindStage + 2 * v11 + v11) = 516;
    *(&pMaterialOut->m_Material.m_Binds[0].m_cBindSampler + 2 * v11 + v11) = 0;
    pMaterialOut->m_ppTextures[v11++] = UniqueTexture(pTextureName: v12);
    pMaterialOut->m_Material.m_bPhongTexture = true;
    _Msg(a1: "%s has phong map\n", pVMTName);
  }
  v13 = pphong;
  pMaterialOut->m_Material.m_nBinds = v11;
  pMaterialOut->m_nTextures = v11;
  if ( v13 != nullptr && atoi(nptr: v13) == 1 )
  {
    pMaterialOut->m_Material.m_bPhong = true;
    if ( pphongexp != nullptr && *pphongexp != 0 )
      pMaterialOut->m_Material.m_flPhongExp = atof(nptr: pphongexp);
    if ( pphongboost != nullptr && *pphongboost != 0 )
      pMaterialOut->m_Material.m_flPhongBoost = atof(nptr: pphongboost);
    else
      pMaterialOut->m_Material.m_flPhongBoost = 0.0;
  }
  if ( palphatest != nullptr && atoi(nptr: palphatest) == 1 || bAlpha )
  {
    pMaterialOut->m_Material.m_bAlphaTest = true;
    _Msg(a1: "%s has alphatest\n", pVMTName);
    if ( bAlpha )
      _Msg(a1: "%s has alpha\n", pVMTName);
  }
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
  return 1;
}
