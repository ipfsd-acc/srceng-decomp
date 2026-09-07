// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuidynamictextures.cpp
// Functions: 540
// ============================================================

#include "vgui2\game_controls\gameuidynamictextures.h"

//------------------------------------------------------------------------------
// Address: 0x00401540
// Name: public: virtual bool CGameControlsProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameControlsProxy::Init(CGameControlsProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  this->m_BaseTextureVar = pMaterial->FindVar(this: pMaterial, a2: "$basetexture", a3: &pMaterial, a4: 0);
  return (char)pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x00401590
// Name: public: virtual void __near * (*CMaterialProxyFactory::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void *(__cdecl *__thiscall CMaterialProxyFactory::GetFactory(CMaterialProxyFactory *this))(const char *, int *)
{
  return Sys_GetFactoryThis();
}

//------------------------------------------------------------------------------
// Address: 0x0040E5C0
// Name: public: class ImageAliasData_t __near & ImageAliasData_t::operator=(class ImageAliasData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
ImageAliasData_t *__thiscall ImageAliasData_t::operator=(ImageAliasData_t *this, const ImageAliasData_t *__that)
{
  this->m_XPos = __that->m_XPos;
  this->m_YPos = __that->m_YPos;
  this->m_Width = __that->m_Width;
  this->m_Height = __that->m_Height;
  CUtlString::operator=(this: &this->m_szBaseTextureName, src: &__that->m_szBaseTextureName);
  CMaterialReference::operator=(this: &this->m_Material, ref: &__that->m_Material);
  this->m_bIsInSheet = __that->m_bIsInSheet;
  this->m_nNodeIndex = __that->m_nNodeIndex;
  this->m_nRefCount = __that->m_nRefCount;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040E610
// Name: public: void CGameUIDynamicTextures::GetDynamicSheetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::GetDynamicSheetSize(CGameUIDynamicTextures *this, int *nWidth, int *nHeight)
{
  *nWidth = this->m_TexturePage.m_pTexture->GetActualWidth(this: this->m_TexturePage.m_pTexture);
  *nHeight = this->m_TexturePage.m_pTexture->GetActualHeight(this: this->m_TexturePage.m_pTexture);
}

//------------------------------------------------------------------------------
// Address: 0x0040E640
// Name: public: void CGameUIDynamicTextures::OnRestore(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::OnRestore(CGameUIDynamicTextures *this, int nChangeFlags)
{
  this->m_bRegenerate = true;
}

//------------------------------------------------------------------------------
// Address: 0x0040E6F0
// Name: public: virtual class IMaterialProxy __near * CMaterialProxyFactory::CreateProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CMaterialProxyFactory::CreateProxy(CGameUIDynamicTextures *this, const char *proxyName)
{
  IMaterialProxy *result; // eax

  if ( _V_strcmp(s1: proxyName, s2: "GameControlsProxy") != 0 )
    return nullptr;
  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CGameControlsProxy::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E730
// Name: public: void CGameUIDynamicTextures::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::Shutdown(CGameUIDynamicTextures *this)
{
  CMaterialReference *p_m_RenderMaterial; // edi
  CTexturePacker *m_pDynamicTexturePacker; // ebp
  CMaterialReference ref; // [esp+Ch] [ebp-4h] BYREF

  p_m_RenderMaterial = &this->m_RenderMaterial;
  CMaterialReference::Shutdown(this: &this->m_RenderMaterial, bDeleteIfUnreferenced: false);
  CTextureReference::Shutdown(this: &this->m_TexturePage, bDeleteIfUnReferenced: false);
  m_pDynamicTexturePacker = this->m_pDynamicTexturePacker;
  if ( m_pDynamicTexturePacker != nullptr )
  {
    CTexturePacker::~CTexturePacker(this: this->m_pDynamicTexturePacker);
    free(pMem: m_pDynamicTexturePacker);
  }
  this->m_pDynamicTexturePacker = nullptr;
  CMaterialReference::CMaterialReference(
    this: &ref,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::operator=(this: p_m_RenderMaterial, &ref);
  CMaterialReference::~CMaterialReference(this: &ref);
  this->m_bRegenerate = false;
}

//------------------------------------------------------------------------------
// Address: 0x0040E7A0
// Name: public: char const __near * CFmtStrN<256>::sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<256>::sprintf(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+14h] [ebp+Ch] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  LOBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 255, pFormat: pszFormat, params, pbTruncated: (bool *)&this);
  v3 = (_BYTE)this == 0;
  v2->m_szBuf[255] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<256>::sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x0040E9B0
// Name: public: CGameUIDynamicTextures::~CGameUIDynamicTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::~CGameUIDynamicTextures(CGameUIDynamicTextures *this)
{
  CGameUIDynamicTextures::Shutdown(this);
  CMaterialReference::~CMaterialReference(this: &this->m_RenderMaterial);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_ImageAliasMap.m_SymbolTable);
  CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::~CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>(this: &this->m_ImageAliasMap.m_Vector);
  CTextureReference::~CTextureReference(this: &this->m_TexturePage);
}

//------------------------------------------------------------------------------
// Address: 0x0040E9E0
// Name: public: CGameUIDynamicTextures::CGameUIDynamicTextures(void)
// Source: json
//------------------------------------------------------------------------------
CGameUIDynamicTextures *__thiscall CGameUIDynamicTextures::CGameUIDynamicTextures(CGameUIDynamicTextures *this)
{
  CMaterialReference ref; // [esp+Ch] [ebp-4h] BYREF

  CTextureReference::CTextureReference(this: &this->m_TexturePage);
  this->m_ImageAliasMap.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_ImageAliasMap.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_ImageAliasMap.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_ImageAliasMap.m_Vector.m_Size = 0;
  this->m_ImageAliasMap.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_ImageAliasMap.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_RenderMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_pDynamicTexturePacker = nullptr;
  CMaterialReference::CMaterialReference(
    this: &ref,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::operator=(this: &this->m_RenderMaterial, &ref);
  CMaterialReference::~CMaterialReference(this: &ref);
  this->m_bRegenerate = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040EA50
// Name: public: void CGameUIDynamicTextures::InitRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::InitRenderTargets(CGameUIDynamicTextures *this)
{
  ITexture *m_pTexture; // ecx
  int v3; // edi
  unsigned __int8 *v4; // ebp
  CTexturePacker *v5; // eax
  CTexturePacker *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  CUtlStringMap<ImageAliasData_t> *p_m_ImageAliasMap; // esi
  int m_pMaterial_low; // edi
  int m_Size; // eax
  int v12; // edi
  int v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // esi
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  CMaterialReference material; // [esp+4h] [ebp-148h] BYREF
  CTextureReference pErrorTexture; // [esp+8h] [ebp-144h] BYREF
  ImageAliasData_t imageData; // [esp+Ch] [ebp-140h] BYREF
  CFmtStrN<256> materialName; // [esp+3Ch] [ebp-110h] BYREF
  int v24; // [esp+148h] [ebp-4h]

  m_pTexture = this->m_TexturePage.m_pTexture;
  if ( m_pTexture != nullptr
    || (CTextureReference::InitRenderTarget(
          this: &this->m_TexturePage,
          w: 2048,
          h: 2048,
          sizeMode: RT_SIZE_NO_CHANGE,
          fmt: IMAGE_FORMAT_ARGB8888,
          depth: MATERIAL_RT_DEPTH_NONE,
          bHDR: false,
          pStrOptionalName: "_rt_DynamicUI"),
        m_pTexture = this->m_TexturePage.m_pTexture,
        this->m_TexturePage.m_pTexture != nullptr) )
  {
    v3 = m_pTexture->GetActualWidth(this: m_pTexture);
    v4 = (unsigned __int8 *)this->m_TexturePage.m_pTexture->GetActualHeight(this: this->m_TexturePage.m_pTexture);
    v5 = (CTexturePacker *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v5 != nullptr )
      v6 = CTexturePacker::CTexturePacker(this: v5, texWidth: v3, texHeight: (int)v4, pixelGap: 1);
    else
      v6 = nullptr;
    this->m_pDynamicTexturePacker = v6;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "GameControls");
    else
      v8 = nullptr;
    KeyValues::SetString(this: v8, keyName: "$basetexture", value: "_rt_DynamicUI");
    CMaterialReference::CMaterialReference(
      this: (CMaterialReference *)&pErrorTexture,
      pMaterialName: nullptr,
      pTextureGroupName: nullptr,
      bComplain: true);
    *(_DWORD *)&materialName.m_bQuietTruncation = &CFmtStrN<256>::`vftable';
    materialName.m_szBuf[3] = 1;
    materialName.m_szBuf[4] = 0;
    v24 = 0;
    CFmtStrN<256>::sprintf(
      this: (CFmtStrN<256> *)&materialName.m_bQuietTruncation,
      pszFormat: "dynamictx_%s",
      "_rt_DynamicUI");
    CMaterialReference::Init(
      this: (CMaterialReference *)&pErrorTexture,
      pMaterialName: &materialName.m_szBuf[4],
      pTextureGroupName: "Other textures",
      pVMTKeyValues: v8);
    pErrorTexture.m_pTexture->__vftable[1].GetNumAnimationFrames(this: pErrorTexture.m_pTexture);
    CUtlString::CUtlString(this: (CUtlString *)&imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount);
    CMaterialReference::CMaterialReference(
      this: (CMaterialReference *)&imageData.m_bIsInSheet,
      pMaterialName: nullptr,
      pTextureGroupName: nullptr,
      bComplain: true);
    ImageAliasData_t::Init(this: (ImageAliasData_t *)&imageData.m_YPos);
    imageData.m_Height = v3;
    imageData.m_szBaseTextureName.m_Storage.m_Memory.m_pMemory = v4;
    CMaterialReference::operator=(
      this: (CMaterialReference *)&imageData.m_bIsInSheet,
      ref: (const CMaterialReference *)&pErrorTexture);
    p_m_ImageAliasMap = &this->m_ImageAliasMap;
    CUtlSymbolTable::AddString(
      this: &this->m_ImageAliasMap.m_SymbolTable,
      result: (CUtlSymbol *)&material,
      pString: "_rt_DynamicUI");
    m_pMaterial_low = LOWORD(material.m_pMaterial);
    m_Size = this->m_ImageAliasMap.m_Vector.m_Size;
    if ( m_Size <= LOWORD(material.m_pMaterial) && m_Size < LOWORD(material.m_pMaterial) + 1 )
      CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::InsertMultipleBefore(
        this: &this->m_ImageAliasMap.m_Vector,
        elem: m_Size,
        num: LOWORD(material.m_pMaterial) + 1 - m_Size);
    ImageAliasData_t::operator=(
      this: &p_m_ImageAliasMap->m_Vector.m_Memory.m_pMemory[m_pMaterial_low],
      __that: (const ImageAliasData_t *)&imageData.m_YPos);
    CMaterialReference::~CMaterialReference(this: (CMaterialReference *)&imageData.m_bIsInSheet);
    imageData.m_Material.m_pMaterial = nullptr;
    if ( imageData.m_szBaseTextureName.m_Storage.m_nActualLength >= 0
      && imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount);
    }
    CTextureReference::CTextureReference(this: (CTextureReference *)&imageData);
    CTextureReference::Init(
      this: (CTextureReference *)&imageData,
      pTextureName: "error",
      pTextureGroupName: "Other textures",
      bComplain: true,
      nAdditionalCreationFlags: 0);
    CUtlString::CUtlString(this: (CUtlString *)&imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount);
    CMaterialReference::CMaterialReference(
      this: (CMaterialReference *)&imageData.m_bIsInSheet,
      pMaterialName: nullptr,
      pTextureGroupName: nullptr,
      bComplain: true);
    ImageAliasData_t::Init(this: (ImageAliasData_t *)&imageData.m_YPos);
    imageData.m_Height = (*(int (__thiscall **)(int))(*(_DWORD *)imageData.m_XPos + 12))(a1: imageData.m_XPos);
    imageData.m_szBaseTextureName.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(*(int (__thiscall **)(int))(*(_DWORD *)imageData.m_XPos + 16))(a1: imageData.m_XPos);
    CUtlString::operator=(
      this: (CUtlString *)&imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount,
      src: "error");
    CMaterialReference::CMaterialReference(
      this: &material,
      pMaterialName: nullptr,
      pTextureGroupName: nullptr,
      bComplain: true);
    CMaterialReference::operator=(this: (CMaterialReference *)&imageData.m_bIsInSheet, ref: &material);
    CMaterialReference::~CMaterialReference(this: &material);
    CUtlSymbolTable::AddString(
      this: &this->m_ImageAliasMap.m_SymbolTable,
      result: (CUtlSymbol *)&material,
      pString: "errorImageAlias");
    v12 = LOWORD(material.m_pMaterial);
    v13 = this->m_ImageAliasMap.m_Vector.m_Size;
    if ( v13 <= LOWORD(material.m_pMaterial) && v13 < LOWORD(material.m_pMaterial) + 1 )
      CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::InsertMultipleBefore(
        this: &this->m_ImageAliasMap.m_Vector,
        elem: v13,
        num: LOWORD(material.m_pMaterial) + 1 - v13);
    ImageAliasData_t::operator=(
      this: &p_m_ImageAliasMap->m_Vector.m_Memory.m_pMemory[v12],
      __that: (const ImageAliasData_t *)&imageData.m_YPos);
    CMaterialReference::~CMaterialReference(this: (CMaterialReference *)&imageData.m_bIsInSheet);
    imageData.m_Material.m_pMaterial = nullptr;
    if ( imageData.m_szBaseTextureName.m_Storage.m_nActualLength >= 0 )
    {
      if ( imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: (void *)imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount);
        imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nGrowSize = 0;
    }
    CTextureReference::~CTextureReference(this: (CTextureReference *)&imageData);
    v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v14 != nullptr )
      v15 = KeyValues::KeyValues(this: v14, setName: "GameControls");
    else
      v15 = nullptr;
    KeyValues::SetInt(this: v15, keyName: "$ignorez", value: 1);
    v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v16 != nullptr )
      v17 = KeyValues::KeyValues(this: v16, setName: "Proxies");
    else
      v17 = nullptr;
    v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v18 != nullptr )
      v19 = KeyValues::KeyValues(this: v18, setName: "GameControlsProxy");
    else
      v19 = nullptr;
    KeyValues::AddSubKey(this: v17, pSubkey: v19);
    KeyValues::AddSubKey(this: v15, pSubkey: v17);
    CMaterialReference::Init(
      this: &this->m_RenderMaterial,
      pMaterialName: "dynamic_render_texture",
      pTextureGroupName: "Other textures",
      pVMTKeyValues: v15);
    this->m_RenderMaterial.m_pMaterial->Refresh(this: this->m_RenderMaterial.m_pMaterial);
    CGameUISystemMgr::InitImageAlias(this: g_pGameUISystemMgrImpl, pAlias: "defaultImageAlias");
    CGameUISystemMgr::LoadImageAliasTexture(
      this: g_pGameUISystemMgrImpl,
      pAlias: "defaultImageAlias",
      pBaseTextureName: "vguiedit/pixel");
    CMaterialReference::~CMaterialReference(this: (CMaterialReference *)&pErrorTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EDE0
// Name: public: void CGameUIDynamicTextures::SetImageEntry(char const __near *,class ImageAliasData_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::SetImageEntry(
        CGameUIDynamicTextures *this,
        const char *pEntryName,
        ImageAliasData_t *imageData)
{
  CUtlStringMap<ImageAliasData_t> *p_m_ImageAliasMap; // esi
  int v4; // edi
  int m_Size; // ecx

  p_m_ImageAliasMap = &this->m_ImageAliasMap;
  CUtlSymbolTable::AddString(
    this: &this->m_ImageAliasMap.m_SymbolTable,
    result: (CUtlSymbol *)&pEntryName,
    pString: pEntryName);
  v4 = (unsigned __int16)pEntryName;
  m_Size = p_m_ImageAliasMap->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pEntryName && m_Size < (unsigned __int16)pEntryName + 1 )
    CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::InsertMultipleBefore(
      this: &p_m_ImageAliasMap->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pEntryName + 1 - m_Size);
  ImageAliasData_t::operator=(this: &p_m_ImageAliasMap->m_Vector.m_Memory.m_pMemory[v4], __that: imageData);
}

//------------------------------------------------------------------------------
// Address: 0x0040EE30
// Name: public: class IMaterial __near * CGameUIDynamicTextures::GetImageAliasMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CGameUIDynamicTextures::GetImageAliasMaterial(CGameUIDynamicTextures *this, const char *pAlias)
{
  const char *v2; // edi
  CUtlStringMap<ImageAliasData_t> *p_m_ImageAliasMap; // esi
  int v4; // edi
  int m_Size; // ecx

  v2 = pAlias;
  p_m_ImageAliasMap = &this->m_ImageAliasMap;
  if ( CUtlSymbolTable::Find(this: &this->m_ImageAliasMap.m_SymbolTable, result: (CUtlSymbol *)&pAlias, pString: pAlias)->m_Id == 0xFFFF )
    CUtlSymbolTable::AddString(
      this: &p_m_ImageAliasMap->m_SymbolTable,
      result: (CUtlSymbol *)&pAlias,
      pString: "errorImageAlias");
  else
    CUtlSymbolTable::AddString(this: &p_m_ImageAliasMap->m_SymbolTable, result: (CUtlSymbol *)&pAlias, pString: v2);
  v4 = (unsigned __int16)pAlias;
  m_Size = p_m_ImageAliasMap->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pAlias && m_Size < (unsigned __int16)pAlias + 1 )
    CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::InsertMultipleBefore(
      this: &p_m_ImageAliasMap->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pAlias + 1 - m_Size);
  return p_m_ImageAliasMap->m_Vector.m_Memory.m_pMemory[v4].m_Material.m_pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x0040EEA0
// Name: public: class ImageAliasData_t __near * CGameUIDynamicTextures::GetImageAliasData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ImageAliasData_t *__thiscall CGameUIDynamicTextures::GetImageAliasData(
        CGameUIDynamicTextures *this,
        const char *pAlias)
{
  const char *v2; // edi
  CUtlStringMap<ImageAliasData_t> *p_m_ImageAliasMap; // esi
  int v4; // edi
  int m_Size; // ecx

  v2 = pAlias;
  p_m_ImageAliasMap = &this->m_ImageAliasMap;
  if ( CUtlSymbolTable::Find(this: &this->m_ImageAliasMap.m_SymbolTable, result: (CUtlSymbol *)&pAlias, pString: pAlias)->m_Id == 0xFFFF )
    CUtlSymbolTable::AddString(
      this: &p_m_ImageAliasMap->m_SymbolTable,
      result: (CUtlSymbol *)&pAlias,
      pString: "errorImageAlias");
  else
    CUtlSymbolTable::AddString(this: &p_m_ImageAliasMap->m_SymbolTable, result: (CUtlSymbol *)&pAlias, pString: v2);
  v4 = (unsigned __int16)pAlias;
  m_Size = p_m_ImageAliasMap->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pAlias && m_Size < (unsigned __int16)pAlias + 1 )
    CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::InsertMultipleBefore(
      this: &p_m_ImageAliasMap->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pAlias + 1 - m_Size);
  return &p_m_ImageAliasMap->m_Vector.m_Memory.m_pMemory[v4];
}

//------------------------------------------------------------------------------
// Address: 0x0040EF10
// Name: public: bool CGameUIDynamicTextures::IsErrorImageAliasData(class ImageAliasData_t __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameUIDynamicTextures::IsErrorImageAliasData(CGameUIDynamicTextures *this, ImageAliasData_t *pData)
{
  CUtlStringMap<ImageAliasData_t> *p_m_ImageAliasMap; // esi
  int m_Id; // edi
  int m_Size; // ecx
  CUtlSymbol v6; // [esp+8h] [ebp-4h] BYREF

  p_m_ImageAliasMap = &this->m_ImageAliasMap;
  CUtlSymbolTable::AddString(this: &this->m_ImageAliasMap.m_SymbolTable, result: &v6, pString: "errorImageAlias");
  m_Id = v6.m_Id;
  m_Size = p_m_ImageAliasMap->m_Vector.m_Size;
  if ( m_Size <= v6.m_Id && m_Size < v6.m_Id + 1 )
    CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::InsertMultipleBefore(
      this: &p_m_ImageAliasMap->m_Vector,
      elem: m_Size,
      num: v6.m_Id + 1 - m_Size);
  return &p_m_ImageAliasMap->m_Vector.m_Memory.m_pMemory[m_Id] == pData;
}

//------------------------------------------------------------------------------
// Address: 0x0040EF60
// Name: public: void CGameUIDynamicTextures::ReleaseImageAlias(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::ReleaseImageAlias(CGameUIDynamicTextures *this, const char *pAlias)
{
  ImageAliasData_t *ImageAliasData; // eax
  ImageAliasData_t *v4; // esi

  if ( _V_strcmp(s1: pAlias, s2: "_rt_DynamicUI") != 0
    && _V_strcmp(s1: pAlias, s2: "errorImageAlias") != 0
    && _V_strcmp(s1: pAlias, s2: "defaultImageAlias") != 0 )
  {
    ImageAliasData = CGameUIDynamicTextures::GetImageAliasData(this, pAlias);
    v4 = ImageAliasData;
    if ( ImageAliasData != nullptr && ImageAliasData->m_nRefCount-- == 1 )
    {
      if ( ImageAliasData->m_bIsInSheet )
      {
        _Msg(a1: "Releasing Alias %s\n", pAlias);
        CTexturePacker::RemoveRect(this: this->m_pDynamicTexturePacker, nodeIndex: v4->m_nNodeIndex);
      }
      ImageAliasData_t::Init(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EFF0
// Name: private: void CGameUIDynamicTextures::LoadImageAliasTexture(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::LoadImageAliasTexture(
        CGameUIDynamicTextures *this,
        const char *pAlias,
        const char *pBaseTextureName)
{
  ImageAliasData_t *ImageAliasData; // eax
  ImageAliasData_t *v5; // edi
  const char *v6; // eax
  KeyValues *v7; // ebx
  KeyValues *v8; // eax
  const char *v9; // eax
  IMaterial *ImageAliasMaterial; // eax
  int m_nNodeIndex_low; // eax
  CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t *v12; // eax
  IMatRenderContext *m_pObject; // esi
  IMaterial *m_pMaterial; // eax
  IMatRenderContext_vtbl *v15; // ebx
  char *v16; // eax
  IMatRenderContext_vtbl *v17; // edx
  int m_Width; // ebx
  IMesh *v19; // edi
  float *m_pCurrPosition; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float *v24; // eax
  int v25; // eax
  float *v26; // eax
  float v27; // xmm2_4
  float *v28; // eax
  int v29; // eax
  float *v30; // eax
  float *v31; // eax
  int v32; // eax
  double v33; // [esp+50h] [ebp-260h]
  double v34; // [esp+58h] [ebp-258h]
  CMatRenderContextPtr pRenderContext; // [esp+A8h] [ebp-208h] BYREF
  int tall; // [esp+ACh] [ebp-204h]
  CTextureReference pTexture; // [esp+B0h] [ebp-200h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > words; // [esp+B4h] [ebp-1FCh] BYREF
  CMeshBuilder meshBuilder; // [esp+C8h] [ebp-1E8h] BYREF

  if ( pBaseTextureName != nullptr && *pBaseTextureName != 0 )
  {
    CTextureReference::CTextureReference(this: &pTexture);
    CTextureReference::Init(
      this: &pTexture,
      pTextureName: pBaseTextureName,
      pTextureGroupName: "Other textures",
      bComplain: true,
      nAdditionalCreationFlags: 0);
    ImageAliasData = CGameUIDynamicTextures::GetImageAliasData(this, pAlias);
    v5 = ImageAliasData;
    if ( ImageAliasData->m_nNodeIndex == -1 )
    {
      memset(&words, 0, sizeof(words));
      v6 = CUtlString::operator char const *(this: &ImageAliasData->m_szBaseTextureName);
      V_SplitString(pString: v6, pSeparator: "/", outStrings: &words);
      v7 = nullptr;
      meshBuilder.m_VertexSize_Position = (int)&CFmtStrN<256>::`vftable';
      LOWORD(meshBuilder.m_VertexSize_BoneWeight) = 1;
      meshBuilder.m_VertexBuilder.m_VertexSize_Specular = 0;
      CFmtStrN<256>::sprintf(
        this: (CFmtStrN<256> *)&meshBuilder,
        pszFormat: "dynamictx_%s",
        words.m_Memory.m_pMemory[words.m_Size - 1]);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v7 = KeyValues::KeyValues(this: v8, setName: "GameControls");
      v9 = CUtlString::operator char const *(this: &v5->m_szBaseTextureName);
      KeyValues::SetString(this: v7, keyName: "$basetexture", value: v9);
      CMaterialReference::CMaterialReference(
        this: (CMaterialReference *)&pRenderContext,
        pMaterialName: nullptr,
        pTextureGroupName: nullptr,
        bComplain: true);
      CMaterialReference::Init(
        this: (CMaterialReference *)&pRenderContext,
        pMaterialName: (const char *)&meshBuilder.m_VertexSize_BoneWeight + 1,
        pTextureGroupName: "Other textures",
        pVMTKeyValues: v7);
      ((void (__thiscall *)(IMatRenderContext *))pRenderContext.m_pObject->Scale)(a1: pRenderContext.m_pObject);
      CMaterialReference::operator=(this: &v5->m_Material, ref: (const CMaterialReference *)&pRenderContext);
      v5->m_bIsInSheet = false;
      CMaterialReference::~CMaterialReference(this: (CMaterialReference *)&pRenderContext);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&words);
      CTextureReference::~CTextureReference(this: &pTexture);
    }
    else
    {
      if ( this->m_RenderMaterial.m_pMaterial != nullptr )
      {
        ImageAliasMaterial = CGameUIDynamicTextures::GetImageAliasMaterial(this, pAlias: "_rt_DynamicUI");
        CMaterialReference::Init(this: &v5->m_Material, pMaterial: ImageAliasMaterial);
        m_nNodeIndex_low = LOWORD(v5->m_nNodeIndex);
        v5->m_bIsInSheet = true;
        v12 = &this->m_pDynamicTexturePacker->m_Tree.m_Memory.m_pMemory[m_nNodeIndex_low];
        v5->m_XPos = v12->m_Element.rc.x;
        v5->m_YPos = v12->m_Element.rc.y;
        CMatRenderContextPtr::CMatRenderContextPtr(this: &pRenderContext, pFrom: g_pMaterialSystem);
        m_pObject = pRenderContext.m_pObject;
        pRenderContext.m_pObject->PushRenderTargetAndViewport(
          this: pRenderContext.m_pObject,
          a2: this->m_TexturePage.m_pTexture,
          a3: nullptr,
          a4: v5->m_XPos,
          a5: v5->m_YPos,
          a6: v5->m_Width,
          a7: v5->m_Height);
        m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_PROJECTION);
        m_pObject->PushMatrix(this: m_pObject);
        m_pObject->LoadIdentity(this: m_pObject);
        ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))m_pObject->Scale)(
          a1: m_pObject,
          a2: 1.0,
          a3: -1.0,
          a4: 1.0);
        v34 = (float)((float)v5->m_Height + 0.5);
        v33 = (float)((float)v5->m_Width + 0.5);
        ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))m_pObject->Ortho)(
          a1: m_pObject,
          a2: COERCE_UNSIGNED_INT64(0.5),
          a3: HIDWORD(COERCE_UNSIGNED_INT64(0.5)),
          a4: COERCE_UNSIGNED_INT64(0.5),
          a5: HIDWORD(COERCE_UNSIGNED_INT64(0.5)),
          a6: LODWORD(v33),
          a7: HIDWORD(v33),
          a8: LODWORD(v34),
          a9: HIDWORD(v34),
          a10: COERCE_UNSIGNED_INT64(-1.0),
          a11: HIDWORD(COERCE_UNSIGNED_INT64(-1.0)),
          a12: COERCE_UNSIGNED_INT64(1.0),
          a13: HIDWORD(COERCE_UNSIGNED_INT64(1.0)));
        m_pObject->ClearColor4ub(this: m_pObject, a2: 0, a3: 0, a4: 0, a5: 255u);
        m_pObject->ClearBuffers(this: m_pObject, a2: true, a3: false, a4: false);
        m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
        m_pObject->PushMatrix(this: m_pObject);
        m_pObject->LoadIdentity(this: m_pObject);
        m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_VIEW);
        m_pObject->PushMatrix(this: m_pObject);
        m_pObject->LoadIdentity(this: m_pObject);
        m_pMaterial = this->m_RenderMaterial.m_pMaterial;
        v15 = m_pObject->__vftable;
        tall = (int)m_pMaterial;
        v16 = CUtlString::Get(this: &v5->m_szBaseTextureName);
        v15->Bind(this: m_pObject, a2: (IMaterial *)tall, a3: v16);
        v17 = m_pObject->__vftable;
        m_Width = v5->m_Width;
        tall = v5->m_Height;
        v19 = v17->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
        if ( v19 != nullptr )
        {
          CMeshBuilder::CMeshBuilder(this: &meshBuilder);
          CMeshBuilder::Begin(this: &meshBuilder, pMesh: v19, type: 7, numPrimitives: 1);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
          m_pCurrPosition[1] = 0.0;
          m_pCurrPosition[2] = 0.0;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
          v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
          v21[1] = 0.0;
          v22 = ++meshBuilder.m_VertexBuilder.m_nCurrentVertex;
          if ( meshBuilder.m_VertexBuilder.m_nCurrentVertex > meshBuilder.m_VertexBuilder.m_nVertexCount )
            meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
          meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
          meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                   + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
          meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
          v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition + 1;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)m_Width;
          *v23 = 0.0;
          v23[1] = 0.0;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
          v24 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
          v24[1] = 0.0;
          v25 = ++meshBuilder.m_VertexBuilder.m_nCurrentVertex;
          if ( meshBuilder.m_VertexBuilder.m_nCurrentVertex > meshBuilder.m_VertexBuilder.m_nVertexCount )
            meshBuilder.m_VertexBuilder.m_nVertexCount = v25;
          v26 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
          meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
          meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                   + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
          meshBuilder.m_VertexBuilder.m_pCurrPosition = v26;
          *v26 = (float)m_Width;
          v27 = (float)tall;
          v26[1] = (float)tall;
          v26[2] = 0.0;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
          v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
          v28[1] = 1.0;
          v29 = ++meshBuilder.m_VertexBuilder.m_nCurrentVertex;
          if ( meshBuilder.m_VertexBuilder.m_nCurrentVertex > meshBuilder.m_VertexBuilder.m_nVertexCount )
            meshBuilder.m_VertexBuilder.m_nVertexCount = v29;
          v30 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
          meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
          meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                   + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
          meshBuilder.m_VertexBuilder.m_pCurrPosition = v30;
          *v30 = 0.0;
          v30[1] = v27;
          v30[2] = 0.0;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
          v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
          v31[1] = 1.0;
          v32 = ++meshBuilder.m_VertexBuilder.m_nCurrentVertex;
          if ( meshBuilder.m_VertexBuilder.m_nCurrentVertex > meshBuilder.m_VertexBuilder.m_nVertexCount )
            meshBuilder.m_VertexBuilder.m_nVertexCount = v32;
          meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
          meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
          meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                   + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
          CMeshBuilder::End(this: &meshBuilder, bSpewData: false, bDraw: false);
          v19->Draw_2(this: v19, a2: -1, a3: 0);
          CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
        }
        m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_PROJECTION);
        m_pObject->PopMatrix(this: m_pObject);
        m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
        m_pObject->PopMatrix(this: m_pObject);
        m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_VIEW);
        m_pObject->PopMatrix(this: m_pObject);
        m_pObject->PopRenderTargetAndViewport(this: m_pObject);
        CMatRenderContextPtr::~CMatRenderContextPtr(this: &pRenderContext);
      }
      CTextureReference::~CTextureReference(this: &pTexture);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F5B0
// Name: public: void CGameUIDynamicTextures::RegenerateTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::RegenerateTexture(CGameUIDynamicTextures *this, int nChangeFlags)
{
  int m_NumElements; // eax
  const char *v4; // edi
  int v5; // esi
  int m_Size; // eax
  int v7; // ebx
  CUtlString *v8; // ebx
  ITexture *(__thiscall **p_FindTexture)(IMaterialSystem *, const char *, const char *, bool, int); // esi
  char *v10; // eax
  int v11; // eax
  const char *v12; // eax
  int i; // [esp+14h] [ebp-14h] BYREF
  int v14; // [esp+18h] [ebp-10h]
  ImageAliasData_t *pImageData; // [esp+1Ch] [ebp-Ch]
  int numEntries; // [esp+20h] [ebp-8h]
  int v17; // [esp+24h] [ebp-4h]

  if ( this->m_bRegenerate )
  {
    m_NumElements = this->m_ImageAliasMap.m_SymbolTable.m_Lookup.m_NumElements;
    v17 = m_NumElements;
    v14 = 0;
    if ( m_NumElements != 0 )
    {
      pImageData = (ImageAliasData_t *)&this->m_ImageAliasMap.m_SymbolTable;
      do
      {
        v4 = CUtlSymbolTable::String(this: &this->m_ImageAliasMap.m_SymbolTable, id: (CUtlSymbol)v14);
        numEntries = (int)CGameUIDynamicTextures::GetImageAliasData(this, pAlias: v4);
        CUtlSymbolTable::AddString(
          this: (CUtlSymbolTable *)pImageData,
          result: (CUtlSymbol *)&i,
          pString: "errorImageAlias");
        v5 = (unsigned __int16)i;
        m_Size = this->m_ImageAliasMap.m_Vector.m_Size;
        if ( m_Size <= (unsigned __int16)i && m_Size < (unsigned __int16)i + 1 )
          CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::InsertMultipleBefore(
            this: &this->m_ImageAliasMap.m_Vector,
            elem: m_Size,
            num: (unsigned __int16)i + 1 - m_Size);
        v7 = numEntries;
        if ( &this->m_ImageAliasMap.m_Vector.m_Memory.m_pMemory[v5] != (ImageAliasData_t *)numEntries
          && _V_strcmp(s1: v4, s2: "_rt_DynamicUI") != 0 )
        {
          v8 = (CUtlString *)(v7 + 16);
          if ( CUtlString::operator char const *(this: v8) != nullptr
            && *CUtlString::operator char const *(this: v8) != 0 )
          {
            p_FindTexture = &g_pMaterialSystem->FindTexture;
            v10 = CUtlString::Get(this: v8);
            v11 = (int)(*p_FindTexture)(this: g_pMaterialSystem, a2: v10, a3: "Other textures", a4: true, a5: 0);
            (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v11 + 52))(a1: v11, a2: 0, a3: 0);
            v12 = CUtlString::operator char const *(this: v8);
            CGameUIDynamicTextures::LoadImageAliasTexture(this, pAlias: v4, pBaseTextureName: v12);
          }
        }
        ++v14;
      }
      while ( v14 < v17 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F6E0
// Name: public: void CGameUIDynamicTextures::LoadImageAlias(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDynamicTextures::LoadImageAlias(
        CGameUIDynamicTextures *this,
        const char *pAlias,
        const char *pBaseTextureName)
{
  ImageAliasData_t *v4; // edi
  ImageAliasData_t *ImageAliasData; // eax
  bool v6; // zf
  ImageAliasData_t *v7; // edi
  int v8; // eax
  int v9; // eax
  CFmtStrN<256>_vtbl *v10; // eax
  CTexturePacker *m_pDynamicTexturePacker; // ecx
  int nodeIndex; // [esp+8h] [ebp-15Ch] BYREF
  int nSheetWidth; // [esp+Ch] [ebp-158h]
  int nSheetHeight; // [esp+10h] [ebp-154h] BYREF
  ImageAliasData_t imageData; // [esp+14h] [ebp-150h] BYREF
  Rect_t texRect; // [esp+44h] [ebp-120h] BYREF
  CFmtStrN<256> texturePath; // [esp+54h] [ebp-110h] BYREF
  int v18; // [esp+160h] [ebp-4h]

  if ( pAlias != nullptr && *pAlias != 0 && pBaseTextureName != nullptr && *pBaseTextureName != 0 )
  {
    *(_DWORD *)&texturePath.m_bQuietTruncation = &CFmtStrN<256>::`vftable';
    texturePath.m_szBuf[3] = 1;
    texturePath.m_szBuf[4] = 0;
    v18 = 0;
    CFmtStrN<256>::sprintf(
      this: (CFmtStrN<256> *)&texturePath.m_bQuietTruncation,
      pszFormat: "materials\\%s.vtf",
      pBaseTextureName);
    if ( !g_pFullFileSystem->FileExists(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: &texturePath.m_szBuf[4],
            a3: "GAME") )
      _Warning(a1: "Unable to find game ui dynamic texture \"%s\"\n", &texturePath.m_szBuf[4]);
    if ( _V_strcmp(s1: pBaseTextureName, s2: defaultValue) != 0 )
    {
      _Msg(a1: "Loading Alias %s Texture %s\n", pAlias, pBaseTextureName);
      CTextureReference::CTextureReference(this: (CTextureReference *)&nodeIndex);
      CTextureReference::Init(
        this: (CTextureReference *)&nodeIndex,
        pTextureName: pBaseTextureName,
        pTextureGroupName: "Other textures",
        bComplain: true,
        nAdditionalCreationFlags: 0);
      ImageAliasData = CGameUIDynamicTextures::GetImageAliasData(this, pAlias);
      v6 = this->m_pDynamicTexturePacker == nullptr;
      v7 = ImageAliasData;
      nSheetWidth = -1;
      if ( !v6 )
      {
        if ( CGameUIDynamicTextures::IsErrorImageAliasData(this, pData: ImageAliasData) )
        {
          ImageAliasData_t::ImageAliasData_t(this: (ImageAliasData_t *)&imageData.m_YPos);
          imageData.m_Height = (*(int (__thiscall **)(int))(*(_DWORD *)nodeIndex + 12))(a1: nodeIndex);
          imageData.m_szBaseTextureName.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)(*(int (__thiscall **)(int))(*(_DWORD *)nodeIndex + 16))(a1: nodeIndex);
          CUtlString::operator=(
            this: (CUtlString *)&imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount,
            src: pBaseTextureName);
          texRect.x = v7->m_nRefCount;
          CGameUIDynamicTextures::SetImageEntry(
            this,
            pEntryName: pAlias,
            imageData: (ImageAliasData_t *)&imageData.m_YPos);
          v7 = CGameUIDynamicTextures::GetImageAliasData(this, pAlias);
          ImageAliasData_t::~ImageAliasData_t(this: (ImageAliasData_t *)&imageData.m_YPos);
        }
        else
        {
          if ( v7->m_nNodeIndex != -1 )
            CTexturePacker::RemoveRect(this: this->m_pDynamicTexturePacker, nodeIndex: v7->m_nNodeIndex);
          v7->m_Width = (*(int (__thiscall **)(int))(*(_DWORD *)nodeIndex + 12))(a1: nodeIndex);
          v7->m_Height = (*(int (__thiscall **)(int))(*(_DWORD *)nodeIndex + 16))(a1: nodeIndex);
          CUtlString::operator=(this: &v7->m_szBaseTextureName, src: pBaseTextureName);
        }
        nSheetHeight = 0;
        imageData.m_XPos = 0;
        CGameUIDynamicTextures::GetDynamicSheetSize(this, nWidth: &nSheetHeight, nHeight: &imageData.m_XPos);
        v8 = (*(int (__thiscall **)(int))(*(_DWORD *)nodeIndex + 12))(a1: nodeIndex);
        if ( 2 * v8 < nSheetHeight
          || (v9 = (*(int (__thiscall **)(int))(*(_DWORD *)nodeIndex + 16))(a1: nodeIndex), 2 * v9 < imageData.m_XPos) )
        {
          texRect.y = 0;
          texRect.width = 0;
          texRect.height = (*(int (__thiscall **)(int))(*(_DWORD *)nodeIndex + 12))(a1: nodeIndex);
          v10 = (CFmtStrN<256>_vtbl *)(*(int (__thiscall **)(int))(*(_DWORD *)nodeIndex + 16))(a1: nodeIndex);
          m_pDynamicTexturePacker = this->m_pDynamicTexturePacker;
          texturePath.__vftable = v10;
          nSheetWidth = CTexturePacker::InsertRect(
                          this: m_pDynamicTexturePacker,
                          texRect: (const Rect_t *)&texRect.y,
                          nodeIndex: -1);
        }
      }
      v7->m_nNodeIndex = nSheetWidth;
      CGameUIDynamicTextures::LoadImageAliasTexture(this, pAlias, pBaseTextureName);
      CTextureReference::~CTextureReference(this: (CTextureReference *)&nodeIndex);
    }
    else
    {
      v4 = CGameUIDynamicTextures::GetImageAliasData(this, pAlias: "errorImageAlias");
      ImageAliasData_t::ImageAliasData_t(this: (ImageAliasData_t *)&imageData.m_YPos);
      ImageAliasData_t::Init(this: (ImageAliasData_t *)&imageData.m_YPos);
      imageData.m_YPos = v4->m_XPos;
      imageData.m_Width = v4->m_YPos;
      imageData.m_Height = v4->m_Width;
      imageData.m_szBaseTextureName.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v4->m_Height;
      CUtlString::operator=(
        this: (CUtlString *)&imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount,
        src: &v4->m_szBaseTextureName);
      CMaterialReference::operator=(this: (CMaterialReference *)&imageData.m_bIsInSheet, ref: &v4->m_Material);
      LOBYTE(imageData.m_nNodeIndex) = v4->m_bIsInSheet;
      imageData.m_nRefCount = v4->m_nNodeIndex;
      CGameUIDynamicTextures::SetImageEntry(this, pEntryName: pAlias, imageData: (ImageAliasData_t *)&imageData.m_YPos);
      ImageAliasData_t::~ImageAliasData_t(this: (ImageAliasData_t *)&imageData.m_YPos);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6D48
// Name: _sprintf
// Source: json
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  va_list argptr; // [esp+34h] [ebp+10h] BYREF

  va_start(argptr, format);
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6DC3
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C6E45
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(char *nptr, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v2; // esi
  long double result; // st7
  int v4; // eax
  int v5; // eax
  _flt fltstruct; // [esp+8h] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+20h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v2 = (unsigned __int8 *)nptr;
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*v2] & 8
         : _isctype_l(c: *v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    strlen(buf: v2);
    result = _fltin2(
               flt: &fltstruct,
               str: (const char *)v2,
               len_ignore: v5,
               scale_ignore: 0,
               radix_ignore: 0,
               _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C6EEE
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C6EFC
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x004C6F0D
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C6F20
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x004C6F4B
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: &v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: &v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C6FFA
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x004C7010
// Name: ___libm_sse2_sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_sin@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return sin(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C71D0
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x100 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C724A
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  if ( format != nullptr )
  {
    if ( count == 0 || string != nullptr )
    {
      str._cnt = 0x7FFFFFFF;
      if ( count <= 0x7FFFFFFF )
        str._cnt = count;
      str._flag = 66;
      str._base = string;
      str._ptr = string;
      result = _output_l(stream: &str, format, plocinfo, argptr: ap);
      v6 = result;
      if ( string != nullptr )
      {
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr = 0;
        return v6;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C72FB
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x004C7320
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:ByteCopyDown+4[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x100
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:CopyUnwindUp+4[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 004C737C case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7690
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _alloca_probe_16@<eax>(int a1@<eax>, int a2@<ecx>)
{
  char v2; // sp
  int v3; // ecx

  v3 = (v2 + 8 - (_BYTE)a1) & 0xF;
  return _chkstk(a1: __CFADD__(v3, a1) ? -1 : v3 + a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004C77E0
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C7870
// Name: fast_error_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn fast_error_exit(int rterrnum)
{
  if ( __error_mode == 1 )
    _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  __crtExitProcess(status: 255);
}

//------------------------------------------------------------------------------
// Address: 0x004C7894
// Name: check_managed_app
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl check_managed_app()
{
  return (_WORD)MEMORY[0x400000] == 23117
      && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
      && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267
      && *(_DWORD *)(MEMORY[0x40003C] + 4194420) > 0xEu
      && *(_DWORD *)(MEMORY[0x40003C] + 4194536) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C78D5
// Name: __tmainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tmainCRTStartup()
{
  HANDLE ProcessHeap; // eax
  _OSVERSIONINFOA *v1; // eax
  _OSVERSIONINFOA *v2; // esi
  HANDLE v3; // eax
  int v4; // edi
  HANDLE v5; // eax
  int v6; // eax
  char *v7; // eax
  int wShowWindow; // ecx
  int v9; // eax
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-70h] BYREF
  unsigned int winminor; // [esp+58h] [ebp-28h]
  unsigned int winmajor; // [esp+5Ch] [ebp-24h]
  int managedapp; // [esp+60h] [ebp-20h]
  int mainret; // [esp+64h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+68h] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  GetStartupInfoA(lpStartupInfo: &StartupInfo);
  ms_exc.registration.TryLevel = -2;
  ProcessHeap = GetProcessHeap();
  v1 = (_OSVERSIONINFOA *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 0, dwBytes: 0x94u);
  v2 = v1;
  if ( v1 == nullptr )
    fast_error_exit(rterrnum: 18);
  v1->dwOSVersionInfoSize = 148;
  if ( GetVersionExA(lpVersionInformation: v1) )
  {
    managedapp = v2->dwPlatformId;
    winmajor = v2->dwMajorVersion;
    winminor = v2->dwMinorVersion;
    v4 = v2->dwBuildNumber & 0x7FFF;
    v5 = GetProcessHeap();
    HeapFree(hHeap: v5, dwFlags: 0, lpMem: v2);
    if ( managedapp != 2 )
      v4 |= 0x8000u;
    _osplatform = managedapp;
    _winver = winminor + (winmajor << 8);
    _winmajor = winmajor;
    _winminor = winminor;
    _osver = v4;
    managedapp = check_managed_app();
    if ( !_heap_init() )
      fast_error_exit(rterrnum: 28);
    if ( _mtinit() == 0 )
      fast_error_exit(rterrnum: 16);
    _RTC_Initialize();
    ms_exc.registration.TryLevel = 1;
    if ( _ioinit() < 0 )
      _amsg_exit(rterrnum: 27);
    _acmdln = GetCommandLineA();
    _aenvptr = (char *)__crtGetEnvironmentStringsA();
    if ( _setargv() < 0 )
      _amsg_exit(rterrnum: 8);
    if ( _setenvp() < 0 )
      _amsg_exit(rterrnum: 9);
    v6 = _cinit(initFloatingPrecision: 1);
    if ( v6 != 0 )
      _amsg_exit(rterrnum: v6);
    v7 = (char *)_wincmdln();
    if ( (StartupInfo.dwFlags & 1) != 0 )
      wShowWindow = StartupInfo.wShowWindow;
    else
      wShowWindow = 10;
    v9 = WinMain(hInstance: (HINSTANCE__ *)0x400000, hPrevInstance: nullptr, lpCmdLine: v7, nCmdShow: wShowWindow);
    mainret = v9;
    if ( managedapp == 0 )
      exit(code: v9);
    _cexit();
    return mainret;
  }
  else
  {
    v3 = GetProcessHeap();
    HeapFree(hHeap: v3, dwFlags: 0, lpMem: v2);
    return 255;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C7AB5
// Name: _WinMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl WinMainCRTStartup()
{
  __security_init_cookie();
  return _tmainCRTStartup();
}

//------------------------------------------------------------------------------
// Address: 0x004C7ABF
// Name: __snprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snprintf(char *string, unsigned int count, const char *format, ...)
{
  int result; // eax
  int v4; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+14h] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    if ( count == 0 || string != nullptr )
    {
      str._cnt = 0x7FFFFFFF;
      if ( count <= 0x7FFFFFFF )
        str._cnt = count;
      str._flag = 66;
      str._base = string;
      str._ptr = string;
      result = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
      v4 = result;
      if ( string != nullptr )
      {
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr = 0;
        return v4;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C7B6C
// Name: _putenv_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl putenv_helper(char *name, const char *value)
{
  const CHAR *v3; // ebx
  const unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned int v6; // edi
  char *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  char *v11; // eax
  int v12; // ebx
  int v13; // eax
  unsigned __int16 *v14; // eax
  unsigned int v15; // eax
  char *newoption; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 *woption; // [esp+8h] [ebp-4h] BYREF

  newoption = nullptr;
  if ( __env_initialized == 0 )
    return -1;
  v3 = name;
  if ( name == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  if ( value != nullptr )
  {
    v8 = strnlen(str: name, maxsize: 0x7FFFu);
    v9 = strnlen(str: value, maxsize: 0x7FFFu);
    if ( v8 < 0x7FFF && v9 < 0x7FFF )
    {
      v10 = v9 + v8 + 2;
      v11 = (char *)calloc(count: v10, size: 1u);
      newoption = v11;
      if ( v11 != nullptr )
      {
        strcpy_s(_Dst: v11, _SizeInBytes: v10, _Src: name);
        newoption[v8] = 61;
        strcpy_s(_Dst: &newoption[v8 + 1], _SizeInBytes: v10 - (v8 + 1), _Src: value);
        v3 = name;
        goto LABEL_16;
      }
      return -1;
    }
LABEL_13:
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  v4 = _mbschr(string: (const unsigned __int8 *)name, c: 0x3Du);
  if ( v4 != nullptr
    && (v4 - (const unsigned __int8 *)name >= 0x7FFF || strnlen(str: (const char *)v4 + 1, maxsize: 0x7FFFu) >= 0x7FFF) )
  {
    goto LABEL_13;
  }
  strlen(buf: (unsigned __int8 *)name);
  v6 = v5 + 1;
  v7 = (char *)calloc(count: v5 + 1, size: 1u);
  newoption = v7;
  if ( v7 == nullptr )
    return -1;
  strcpy_s(_Dst: v7, _SizeInBytes: v6, _Src: name);
LABEL_16:
  if ( __crtsetenv(poption: &newoption, primary: 1) != 0 )
  {
    if ( newoption != nullptr )
      free(pMem: newoption);
    return -1;
  }
  if ( _wenviron == nullptr )
    return 0;
  woption = nullptr;
  v12 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v3,
          cbMultiByte: -1,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  if ( v12 == 0 )
    goto LABEL_29;
  if ( value != nullptr )
  {
    v13 = MultiByteToWideChar(
            CodePage: 0,
            dwFlags: 0,
            lpMultiByteStr: value,
            cbMultiByte: -1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    if ( v13 == 0 )
    {
LABEL_29:
      *_errno() = 42;
      return -1;
    }
    v12 += v13 + 1;
  }
  v14 = (unsigned __int16 *)calloc(count: v12, size: 2u);
  woption = v14;
  if ( v14 == nullptr )
    return -1;
  if ( MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: name,
         cbMultiByte: -1,
         lpWideCharStr: v14,
         cchWideChar: v12) == 0
    || value != nullptr
    && (v15 = wcslen(wcs: woption),
        woption[v15] = 61,
        MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: value,
          cbMultiByte: -1,
          lpWideCharStr: &woption[v15 + 1],
          cchWideChar: v12 - (v15 + 1)) == 0) )
  {
    free(pMem: woption);
    goto LABEL_29;
  }
  if ( __crtwsetenv(poption: &woption, primary: 0) != 0 )
  {
    if ( woption != nullptr )
      free(pMem: woption);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C7D7B
// Name: __putenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _putenv(char *option)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = putenv_helper(name: option, value: nullptr);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004C7DC0
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax

  result = true;
  if ( drive != 0 )
  {
    LOBYTE(drive) = drive + 64;
    strcpy((char *)&drive + 1, ":\\");
    if ( GetDriveTypeA(lpRootPathName: (LPCSTR)&drive) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C7DF7
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  int v4; // eax
  char *v5; // edi
  signed int FullPathNameA; // eax
  char *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  char drvstr[4]; // [esp+8h] [ebp-4h] BYREF
  signed int count; // [esp+14h] [ebp+8h]

  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    v4 = drive;
  }
  else
  {
    v4 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v4 != 0 )
  {
    drvstr[0] = v4 + 64;
    strcpy(&drvstr[1], ":.");
  }
  else
  {
    strcpy(drvstr, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: drvstr, nBufferLength: count, lpBuffer: pnbuf, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_25;
  if ( pnbuf == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = (char *)calloc(count: maxlen, size: 1u);
    v5 = v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: drvstr, nBufferLength: maxlen, lpBuffer: v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_25:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *pnbuf = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004C7F2C
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004C7F75
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C7FFC
// Name: __access
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access(const char *path, int amode)
{
  return -(_access_s(path, amode) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C8010
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl _getenv_helper_nolock(char *option)
{
  unsigned __int8 **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = (unsigned __int8 **)_environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr
    || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = (unsigned __int8 **)_environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: (unsigned __int8 *)option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4 && (*v1)[v4] == 61 && _mbsnbicoll(s1: *v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
          return (const char *)&(*v1)[v4 + 1];
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004C8091
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = (char *)_getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8114
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dupenv_s(char **pBuffer, unsigned int *pBufferSizeInTChars, char *varname)
{
  unsigned __int8 *v3; // eax
  int v4; // eax
  unsigned int v5; // edi
  char *v6; // eax
  char *_Src; // [esp+10h] [ebp-20h]
  int retval; // [esp+14h] [ebp-1Ch]

  _lock(locknum: 7);
  if ( pBuffer != nullptr )
  {
    *pBuffer = nullptr;
    if ( pBufferSizeInTChars != nullptr )
      *pBufferSizeInTChars = 0;
    if ( varname != nullptr )
    {
      v3 = (unsigned __int8 *)_getenv_helper_nolock(option: varname);
      _Src = (char *)v3;
      if ( v3 != nullptr )
      {
        strlen(buf: v3);
        v5 = v4 + 1;
        v6 = (char *)calloc(count: v4 + 1, size: 1u);
        *pBuffer = v6;
        if ( v6 == nullptr )
        {
          *_errno() = 12;
          retval = *_errno();
          goto LABEL_14;
        }
        if ( strcpy_s(_Dst: v6, _SizeInBytes: v5, _Src) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        if ( pBufferSizeInTChars != nullptr )
          *pBufferSizeInTChars = v5;
      }
      retval = 0;
      goto LABEL_14;
    }
  }
  *_errno() = 22;
  _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  retval = 22;
LABEL_14:
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004C81FA
// Name: __spawnv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnv(int modeflag, const char *pathname, const char *const *argv)
{
  if ( pathname != nullptr && *pathname != 0 && argv != nullptr && *argv != nullptr && **(_BYTE **)argv != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C8250
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:ByteCopyDown_0+4[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x100
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:CopyUnwindUp_0+4[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 004C82AC case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C85B5
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // ebx
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8627
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C86A3
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  char *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_12;
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_12:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_46;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 <= dataSize )
            {
              memcpy_s(dst: data, sizeInBytes: dataSize, src: stream->_ptr, count: v9);
              stream->_cnt -= v9;
              stream->_ptr += v9;
              data += v9;
              v7 -= v9;
              dataSize -= v9;
              v6 = num * elementSize;
              goto LABEL_38;
            }
            if ( bufferSize != -1 )
              memset(dst: (int)buffer, value: nullptr, count: bufferSize);
LABEL_42:
            *_errno() = 34;
            _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
            return 0;
          }
        }
        if ( v7 < streambufsize )
        {
          v15 = _filbuf(str: stream);
          if ( v15 == -1 )
            return (v6 - v7) / elementSize;
          if ( dataSize != 0 )
          {
            v16 = data++;
            *v16 = v15;
            --v7;
            --dataSize;
            streambufsize = stream->_bufsiz;
            goto LABEL_38;
          }
LABEL_43:
          if ( bufferSize != -1 )
            memset(dst: (int)buffer, value: nullptr, count: bufferSize);
          goto LABEL_42;
        }
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_43;
        v17 = v12;
        v13 = _fileno(stream);
        v14 = _read(fh: v13, buf: data, cnt: v17);
        if ( v14 == 0 )
          break;
        if ( v14 == -1 )
        {
LABEL_46:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_38:
        if ( v7 == 0 )
          return num;
      }
      stream->_flag |= 0x10u;
      return (v6 - v7) / elementSize;
    }
  }
  *_errno() = 22;
  _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C88A9
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004C893F
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(char *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x004C895A
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v8; // edx
  int cnt; // edx
  int v10; // esi
  char *v11; // eax
  char *v12; // ecx
  bool v13; // zf
  int bufsiz; // eax
  int v15; // ecx
  char *offset; // [esp+8h] [ebp-Ch]
  int filepos; // [esp+Ch] [ebp-8h]
  int fd; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  v3 = _fileno(stream: str);
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v4 = _lseek(fh: v3, pos: 0, mthd: 1);
  filepos = v4;
  if ( v4 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v4 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  offset = (char *)(str->_ptr - base);
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[fd >> 5][fd & 0x1F].osfile < 0 )
    {
      v8 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v8 == 10 )
            ++offset;
          ++v8;
        }
        while ( v8 < ptr );
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)offset;
  if ( (str->_flag & 1) == 0 )
    return (int)&offset[filepos];
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v10 = fd & 0x1F;
    rdcnt = cnt + ptr - base;
    if ( __pioinfo[fd >> 5][v10].osfile >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return (int)&offset[filepos];
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2) == filepos )
    {
      v11 = str->_base;
      v12 = &v11[rdcnt];
      while ( v11 < v12 )
      {
        if ( *v11 == 10 )
          ++rdcnt;
        ++v11;
      }
      v13 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v13 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( _lseek(fh: fd, pos: filepos, mthd: 0) >= 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v15 = str->_flag) & 8) == 0 || (v15 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v13 = (__pioinfo[fd >> 5][v10].osfile & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = nullptr;
  return (int)&offset[filepos];
}

//------------------------------------------------------------------------------
// Address: 0x004C8AF2
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8B60
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, int offset, int whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = _fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8BE7
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, int offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C8C6C
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: &ms_exc.registration, a3: -2);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004C8D30
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x004C8D43
// Name: __chdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chdir(const char *path)
{
  char *v1; // esi
  signed int CurrentDirectoryA; // eax
  DWORD v4; // edi
  char *v5; // eax
  char v6; // al
  DWORD LastError; // eax
  int memfree; // [esp+8h] [ebp-80h]
  int retval; // [esp+Ch] [ebp-7Ch]
  char env_var[4]; // [esp+10h] [ebp-78h] BYREF
  char abspath[264]; // [esp+14h] [ebp-74h] BYREF

  retval = -1;
  v1 = abspath;
  memfree = 0;
  if ( path == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  if ( !SetCurrentDirectoryA(lpPathName: path) )
    goto LABEL_14;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: abspath);
  v4 = CurrentDirectoryA;
  if ( CurrentDirectoryA > 260 )
  {
    v5 = (char *)calloc(count: CurrentDirectoryA + 1, size: 1u);
    v1 = v5;
    if ( v5 == nullptr || (memfree = 1, v4 == 0) )
    {
LABEL_14:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      goto LABEL_15;
    }
    v4 = GetCurrentDirectoryA(nBufferLength: v4 + 1, lpBuffer: v5);
  }
  if ( v4 == 0 )
    goto LABEL_14;
  if ( (v6 = *v1, *v1 != 92) && v6 != 47 || v6 != v1[1] )
  {
    env_var[0] = 61;
    env_var[1] = _mbctoupper(c: (unsigned __int8)*v1);
    strcpy(&env_var[2], ":");
    if ( !SetEnvironmentVariableA(lpName: env_var, lpValue: v1) )
      goto LABEL_14;
  }
  retval = 0;
LABEL_15:
  if ( memfree != 0 )
    free(pMem: v1);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004C8E66
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  char v7; // bl
  const char *i; // edi
  int v9; // eax
  _BYTE *v10; // edi
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // eax
  unsigned __int16 v13; // cx
  unsigned int v14; // ecx
  int v15; // ecx
  const char *v16; // edi
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-14h] BYREF
  unsigned int number; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  number = 0;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[(unsigned __int8)v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: (unsigned __int8)v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v10 = i + 1;
    v7 = *v10;
    i = v10 + 1;
  }
LABEL_32:
  pctype = locinfo->pctype;
  v12 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v13 = pctype[(unsigned __int8)v7];
    if ( (v13 & 4) != 0 )
    {
      v14 = v7 - 48;
    }
    else
    {
      if ( (v13 & 0x103) == 0 )
        break;
      v15 = v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v15 = v7 - 32;
      v14 = v15 - 55;
    }
    if ( v14 >= ibase )
      break;
    flags |= 8u;
    if ( number < v12 || number == v12 && v14 <= 0xFFFFFFFF % ibase )
    {
      number = v14 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v16 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v16 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v16;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x004C9091
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C90BA
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004C90E4
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // esi
  int v5; // eax
  int v6; // eax
  _flt *v7; // eax
  _flt *v8; // ecx
  int flags; // eax
  long double v10; // st7
  _flt answerstruct; // [esp+Ch] [ebp-30h] BYREF
  _LocaleUpdate _loc_update; // [esp+24h] [ebp-18h] BYREF
  long double tmp; // [esp+34h] [ebp-8h]

  v3 = (unsigned __int8 *)nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*v3] & 8
       : _isctype_l(c: *v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  strlen(buf: v3);
  v7 = _fltin2(
         flt: &answerstruct,
         str: (const char *)v3,
         len_ignore: v6,
         scale_ignore: 0,
         radix_ignore: 0,
         _Locale: &_loc_update.localeinfo);
  v8 = v7;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v7->nbytes];
  flags = v7->flags;
  if ( (v8->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v10 = *(double *)&_HUGE;
    if ( *v3 == 45 )
      v10 = -*(double *)&_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v10 = 0.0, 0.0 != v8->dval) )
  {
    tmp = v8->dval;
    goto LABEL_24;
  }
  tmp = v10;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x004C91FF
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C9212
// Name: _rand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl rand()
{
  _tiddata *v0; // eax
  unsigned int v1; // ecx

  v0 = _getptd();
  v1 = 214013 * v0->_holdrand + 2531011;
  v0->_holdrand = v1;
  return HIWORD(v1) & 0x7FFF;
}

//------------------------------------------------------------------------------
// Address: 0x004C9234
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v5; // eax
  unsigned __int8 *v7; // [esp+0h] [ebp-28h]
  _iobuf str; // [esp+8h] [ebp-20h] BYREF

  strlen(buf: v7);
  if ( string != nullptr && format != nullptr )
  {
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v5 <= 0x7FFFFFFF )
      str._cnt = v5;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C929C
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+10h] [ebp+Ch] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _input_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x004C92BB
// Name: _sscanf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf_s(char *string, const char *format, ...)
{
  va_list arglist; // [esp+10h] [ebp+Ch] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _input_s_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x004C92DA
// Name: __snwprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snwprintf(unsigned __int16 *string, unsigned int count, const wchar_t *format, ...)
{
  int result; // eax
  int v4; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+14h] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    if ( count == 0 || string != nullptr )
    {
      str._flag = 66;
      str._base = (char *)string;
      str._ptr = (char *)string;
      if ( count <= 0x3FFFFFFF )
        str._cnt = 2 * count;
      else
        str._cnt = 0x7FFFFFFF;
      result = _woutput_l(stream: &str, format, plocinfo: nullptr, argptr);
      v4 = result;
      if ( string != nullptr )
      {
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr++ = 0;
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr = 0;
        return v4;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C93AB
// Name: _wcsncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsncpy(unsigned __int16 *dest, const wchar_t *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned __int16 *v4; // edi
  __int16 v6; // ax
  unsigned int v7; // ecx
  char v8; // cf
  unsigned int v9; // ecx
  unsigned __int16 *v10; // edi
  int i; // ecx

  v3 = count;
  v4 = dest;
  if ( count != 0 )
  {
    do
    {
      v6 = *source;
      *v4++ = *source++;
      if ( v6 == 0 )
        break;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v7 = v3 - 1;
      if ( v7 != 0 )
      {
        v8 = v7 & 1;
        v9 = v7 >> 1;
        memset(v4, 0, 4 * v9);
        v10 = &v4[2 * v9];
        for ( i = v8; i != 0; --i )
          *v10++ = 0;
      }
    }
  }
  return dest;
}

//------------------------------------------------------------------------------
// Address: 0x004C93F0
// Name: _floor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl floor(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _floor_default(x: X);
  v1 = _mm_getcsr() & 0x1F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _floor_pentium4(X);
  else
    return _floor_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x004C9430
// Name: __floor_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _floor_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd(v2, *(__m128d *)&S));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmplt_pd(v9, v8).m128d_f64[0];
    if ( v3 < 3071 )
    {
      a1.m128i_i64[0] = (*(_QWORD *)&_mm_cmplt_pd(v9, *(__m128d *)&NegZero).m128d_f64[0] | NegZero) & NegOne;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 3122 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] - COERCE_DOUBLE(*(_QWORD *)&v10 & One);
      return *(double *)a1.m128i_i64;
    }
  }
  else
  {
    if ( v3 >= 1023 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 1074 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C9511
// Name: __towupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _towupper_l(unsigned __int16 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v3; // ecx
  bool v4; // zf
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 widechar; // [esp+10h] [ebp-4h] BYREF

  result = 0xFFFF;
  if ( c != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    v3 = _loc_update.localeinfo.locinfo->lc_handle[2];
    if ( v3 != 0 )
    {
      if ( c >= 0x100u )
      {
        v4 = __crtLCMapStringW(
               plocinfo: &_loc_update.localeinfo,
               Locale: v3,
               dwMapFlags: 0x200u,
               lpSrcStr: &c,
               cchSrc: 1,
               lpDestStr: &widechar,
               cchDest: 1,
               code_page: _loc_update.localeinfo.locinfo->lc_codepage) == 0;
        result = c;
        if ( !v4 )
          result = widechar;
        goto LABEL_11;
      }
      v4 = _iswctype_l(c, mask: 2u, plocinfo: &_loc_update.localeinfo) == 0;
      result = c;
      if ( v4 )
      {
LABEL_11:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return result;
      }
      LOWORD(result) = _loc_update.localeinfo.locinfo->pcumap[c];
    }
    else
    {
      LOWORD(result) = c;
      if ( (unsigned __int16)(c - 97) <= 0x19u )
        LOWORD(result) = c - 32;
    }
    result = (unsigned __int16)result;
    goto LABEL_11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C95BF
// Name: _towupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl towupper(unsigned __int16 c)
{
  return _towupper_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C95D0
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x4D7DB8);
  }
  JUMPOUT(0x4C965F);
}

//------------------------------------------------------------------------------
// Address: 0x004C9610
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIacos_pentium4(a1);
  else
__CIacos:
    _CIacos_default(a1, a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x004C964B
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004C9720
// Name: _asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl asin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x4D86D8);
  }
  JUMPOUT(0x4C97AF);
}

//------------------------------------------------------------------------------
// Address: 0x004C9760
// Name: __CIasin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIasin(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIasin;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIasin_pentium4(a1);
  else
__CIasin:
    _CIasin_default(a1, a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x004C979B
// Name: __CIasin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004C9870
// Name: _fmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl fmod(double X, double Y)
{
  double result; // st7

  _ctrandisp2(parm1: *(unsigned __int64 *)&X, parm2: *(unsigned __int64 *)&Y);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C987A
// Name: __CIfmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __thiscall _CIfmod(int this)
{
  return _cintrindisp2(a1: this, a2: &_OP_FMODjmptab);
}

//------------------------------------------------------------------------------
// Address: 0x004C98B0
// Name: _pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl pow(double X, double Y)
{
  int v2; // eax
  bool v3; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v2 = _mm_getcsr() & 0x1F80;
    v3 = v2 == 8064;
    if ( v2 == 8064 )
      v3 = (v5 & 0x7F) == 127;
    if ( v3 )
      JUMPOUT(0x4D9C69);
  }
  JUMPOUT(0x4C9944);
}

//------------------------------------------------------------------------------
// Address: 0x004C98F0
// Name: __CIpow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIpow(__int64 a1, __int64 a2)
{
  int v4; // eax
  bool v5; // zf
  char v6; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIpow;
  v4 = _mm_getcsr() & 0x1F80;
  v5 = v4 == 8064;
  if ( v4 == 8064 )
    v5 = (v6 & 0x7F) == 127;
  if ( v5 )
    _CIpow_pentium4(a1, a2);
  else
__CIpow:
    _CIpow_default(a1, a2: HIDWORD(a1), a3: a2, a4: HIDWORD(a2));
}

//------------------------------------------------------------------------------
// Address: 0x004C992B
// Name: __CIpow_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_default()
{
  JUMPOUT(0x4C994D);
}

//------------------------------------------------------------------------------
// Address: 0x004C9B3A
// Name: ___libm_sse2_atan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan2()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004CA050
// Name: ___libm_sse2_cos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_cos@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return cos(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CA1FB
// Name: ___libm_sse2_tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_tan@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 14368) > 2216
    && COERCE_DOUBLE(*(_QWORD *)sign_mask & X.m128i_i64[0] ^ X.m128i_i64[0]) != *(double *)INF_0 )
  {
    return tan(X: *(double *)X.m128i_i64);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CA450
// Name: ___libm_sse2_pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_pow()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004CAEC8
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CAF56
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CAFF6
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v5; // ax
  __int16 v6; // bx
  unsigned int v7; // edx
  int v8; // eax
  __int16 v9; // ax
  int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  __int16 v16; // ax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  __int16 v22; // [esp+14h] [ebp-Ch]
  unsigned int v23; // [esp+1Ch] [ebp-4h]
  unsigned int maska; // [esp+28h] [ebp+8h]

  v2 = 0;
  if ( (v22 & 1) != 0 )
    v2 = 16;
  if ( (v22 & 4) != 0 )
    v2 |= 8u;
  if ( (v22 & 8) != 0 )
    v2 |= 4u;
  if ( (v22 & 0x10) != 0 )
    v2 |= 2u;
  if ( (v22 & 0x20) != 0 )
    v2 |= 1u;
  if ( (v22 & 2) != 0 )
    v2 |= 0x80000u;
  v3 = v22 & 0xC00;
  if ( v3 != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (v22 & 0x300) != 0 )
  {
    if ( (v22 & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (v22 & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  v23 = result;
  if ( result != v2 )
  {
    v5 = hw_cw(abstr: mask & newctrl | v2 & ~mask);
    v6 = v5;
    v7 = 0;
    if ( (v5 & 1) != 0 )
      v7 = 16;
    if ( (v5 & 4) != 0 )
      v7 |= 8u;
    if ( (v5 & 8) != 0 )
      v7 |= 4u;
    if ( (v5 & 0x10) != 0 )
      v7 |= 2u;
    if ( (v5 & 0x20) != 0 )
      v7 |= 1u;
    if ( (v5 & 2) != 0 )
      v7 |= 0x80000u;
    v8 = v5 & 0xC00;
    if ( (v6 & 0xC00) != 0 )
    {
      switch ( v8 )
      {
        case 1024:
          v7 |= 0x100u;
          break;
        case 2048:
          v7 |= 0x200u;
          break;
        case 3072:
          v7 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v6 & 0x300) != 0 )
    {
      if ( (v6 & 0x300) == 0x200 )
        v7 |= 0x10000u;
    }
    else
    {
      v7 |= 0x20000u;
    }
    if ( (v6 & 0x1000) != 0 )
      v7 |= 0x40000u;
    result = v7;
    v23 = v7;
  }
  if ( __sse2_available != 0 )
  {
    v9 = _mm_getcsr();
    v10 = 0;
    if ( (v9 & 0x80u) != 0 )
      v10 = 16;
    if ( (v9 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v9 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v9 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v9 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v9 & 0x100) != 0 )
      v10 |= 0x80000u;
    v11 = v9 & 0x6000;
    if ( (v9 & 0x6000) != 0 )
    {
      switch ( v11 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v12 = (v9 & 0x8040) - 64;
    if ( v12 != 0 )
    {
      v13 = v12 - 32704;
      if ( v13 != 0 )
      {
        if ( v13 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v14 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v14 == v10 )
    {
      v15 = v10;
    }
    else
    {
      maska = _hw_cw_sse2(a1: v11, abstr: v14);
      __set_fpsr_sse2(newMXCSR: maska);
      v16 = _mm_getcsr();
      v17 = 0;
      if ( (v16 & 0x80u) != 0 )
        v17 = 16;
      if ( (v16 & 0x200) != 0 )
        v17 |= 8u;
      if ( (v16 & 0x400) != 0 )
        v17 |= 4u;
      if ( (v16 & 0x800) != 0 )
        v17 |= 2u;
      if ( (v16 & 0x1000) != 0 )
        v17 |= 1u;
      if ( (v16 & 0x100) != 0 )
        v17 |= 0x80000u;
      v18 = v16 & 0x6000;
      if ( (v16 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v17 |= 0x100u;
            break;
          case 16384:
            v17 |= 0x200u;
            break;
          case 24576:
            v17 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v16 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v17 |= 0x1000000u;
        }
        else
        {
          v17 |= 0x3000000u;
        }
      }
      else
      {
        v17 |= 0x2000000u;
      }
      v15 = v17;
    }
    v21 = v23 ^ v15;
    result = v23 | v15;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CB2F9
// Name: __controlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _controlfp(unsigned int newctrl, unsigned int mask)
{
  unsigned int v2; // esi
  int v3; // edx
  int v4; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  __int16 v10; // ax
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  int v18; // edx
  int v19; // ecx
  int v20; // ecx
  int v21; // edx
  __int16 v22; // [esp+10h] [ebp-10h]
  unsigned int v23; // [esp+14h] [ebp-Ch]
  unsigned int v24; // [esp+1Ch] [ebp-4h]

  v2 = mask & 0xFFF7FFFF;
  v3 = 0;
  if ( (v22 & 1) != 0 )
    v3 = 16;
  if ( (v22 & 4) != 0 )
    v3 |= 8u;
  if ( (v22 & 8) != 0 )
    v3 |= 4u;
  if ( (v22 & 0x10) != 0 )
    v3 |= 2u;
  if ( (v22 & 0x20) != 0 )
    v3 |= 1u;
  if ( (v22 & 2) != 0 )
    v3 |= 0x80000u;
  v4 = v22 & 0xC00;
  if ( v4 != 0 )
  {
    switch ( v4 )
    {
      case 1024:
        v3 |= 0x100u;
        break;
      case 2048:
        v3 |= 0x200u;
        break;
      case 3072:
        v3 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (v22 & 0x300) != 0 )
  {
    if ( (v22 & 0x300) == 0x200 )
      v3 |= 0x10000u;
  }
  else
  {
    v3 |= 0x20000u;
  }
  if ( (v22 & 0x1000) != 0 )
    v3 |= 0x40000u;
  result = newctrl & v2 | v3 & ~v2;
  v24 = result;
  if ( result != v3 )
  {
    v6 = hw_cw(abstr: newctrl & v2 | v3 & ~v2);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    result = v8;
    v24 = v8;
  }
  if ( __sse2_available != 0 )
  {
    v10 = _mm_getcsr();
    v11 = 0;
    if ( (v10 & 0x80u) != 0 )
      v11 = 16;
    if ( (v10 & 0x200) != 0 )
      v11 |= 8u;
    if ( (v10 & 0x400) != 0 )
      v11 |= 4u;
    if ( (v10 & 0x800) != 0 )
      v11 |= 2u;
    if ( (v10 & 0x1000) != 0 )
      v11 |= 1u;
    if ( (v10 & 0x100) != 0 )
      v11 |= 0x80000u;
    v12 = v10 & 0x6000;
    if ( (v10 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v11 |= 0x100u;
          break;
        case 16384:
          v11 |= 0x200u;
          break;
        case 24576:
          v11 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v10 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v11 |= 0x1000000u;
      }
      else
      {
        v11 |= 0x3000000u;
      }
    }
    else
    {
      v11 |= 0x2000000u;
    }
    v15 = newctrl & mask & 0x300031F | v11 & ~(mask & 0x300031F);
    if ( v15 == v11 )
    {
      v16 = v11;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v16 = 0;
      if ( (v17 & 0x80u) != 0 )
        v16 = 16;
      if ( (v17 & 0x200) != 0 )
        v16 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v16 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v16 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v16 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v16 |= 0x80000u;
      v18 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v16 |= 0x100u;
            break;
          case 16384:
            v16 |= 0x200u;
            break;
          case 24576:
            v16 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v17 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v16 |= 0x1000000u;
        }
        else
        {
          v16 |= 0x3000000u;
        }
      }
      else
      {
        v16 |= 0x2000000u;
      }
    }
    v21 = v24 ^ v16;
    result = v24 | v16;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CB602
// Name: void __ArrayUnwind(void __near *,unsigned int,int,void (*)(void __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __ArrayUnwind(char *ptr, unsigned int size, int count, void (*pDtor)(void))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    pDtor();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CB8EC
// Name: TranslatorGuardHandler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext)
{
  void *pContinue; // [esp+4h] [ebp-4h] BYREF

  if ( (pExcept->ExceptionFlags & 0x66) != 0 )
  {
    pRN[3].pNext = (EHRegistrationNode *)1;
    return ExceptionContinueSearch;
  }
  else
  {
    __InternalCxxFrameHandler(
      pExcept,
      pRN: (EHRegistrationNode *)pRN[1].frameHandler,
      pContext,
      pDC: nullptr,
      pFuncInfo: (const _s_FuncInfo *)pRN[1].pNext,
      CatchDepth: pRN[1].state,
      pMarkerRN: pRN[2].pNext,
      recursive: 1u);
    if ( pRN[3].pNext == nullptr )
      _UnwindNestedFrames(pRN, pExcept);
    _CallSETranslator(
      pExcept: (EHExceptionRecord *)0x123,
      pRN: (EHRegistrationNode *)&pContinue,
      pContext: nullptr,
      pDC: nullptr,
      pFuncInfo: nullptr,
      CatchDepth: 0,
      pMarkerRN: nullptr);
    return ((_EXCEPTION_DISPOSITION (*)(void))pContinue)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CB9FC
// Name: __CreateFrameInfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FrameInfo *__cdecl _CreateFrameInfo(FrameInfo *pFrameInfo, void *pExceptionObject)
{
  pFrameInfo->pExceptionObject = pExceptionObject;
  pFrameInfo->pNext = (FrameInfo *)_getptd()->_pFrameInfoChain;
  _getptd()->_pFrameInfoChain = pFrameInfo;
  return pFrameInfo;
}

//------------------------------------------------------------------------------
// Address: 0x004CBA24
// Name: __IsExceptionObjectToBeDestroyed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _IsExceptionObjectToBeDestroyed(void *pExceptionObject)
{
  void **i; // eax

  for ( i = (void **)_getptd()->_pFrameInfoChain; ; i = (void **)i[1] )
  {
    if ( i == nullptr )
      return 1;
    if ( *i == pExceptionObject )
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CBA45
// Name: __FindAndUnlinkFrame
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _FindAndUnlinkFrame(FrameInfo *pFrameInfo)
{
  _DWORD *i; // eax

  if ( pFrameInfo == _getptd()->_pFrameInfoChain )
  {
    _getptd()->_pFrameInfoChain = pFrameInfo->pNext;
  }
  else
  {
    for ( i = _getptd()->_pFrameInfoChain; ; i = (_DWORD *)i[1] )
    {
      if ( i[1] == 0 )
        _inconsistency();
      if ( pFrameInfo == (FrameInfo *)i[1] )
        break;
    }
    i[1] = pFrameInfo->pNext;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBA91
// Name: void __near * _CallCatchBlock2(struct EHRegistrationNode __near *,struct _s_FuncInfo const __near *,void __near *,int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CallCatchBlock2(
        EHRegistrationNode *pRN,
        const _s_FuncInfo *pFuncInfo,
        void *handlerAddress,
        int CatchDepth,
        unsigned int NLGCode)
{
  _CallSettingFrame(funclet: (unsigned int)handlerAddress, (unsigned int)pRN, dwInCode: NLGCode);
}

//------------------------------------------------------------------------------
// Address: 0x004CBAEF
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(unsigned int cookie)
{
  if ( cookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x004CBB00
// Name: __ftol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __usercall _ftol@<edx:eax>(double a1@<st0>)
{
  return (__int64)a1;
}

//------------------------------------------------------------------------------
// Address: 0x004CBB30
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x1F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x004CBB70
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd(v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One_0;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBC50
// Name: __CIsqrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004CBD0A
// Name: __mbscmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp_l(unsigned __int8 *s1, unsigned __int8 *s2, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // esi
  __int16 v4; // cx
  const unsigned __int8 *v5; // eax
  unsigned __int8 v6; // al
  __int16 v7; // dx
  __int16 v8; // ax
  __int16 v9; // dx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-14h] BYREF
  unsigned __int8 v11; // [esp+17h] [ebp-1h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( s1 != nullptr )
  {
    v3 = s2;
    if ( s2 != nullptr )
    {
      if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
      {
        while ( 1 )
        {
          v4 = *s1;
          v5 = ++s1;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v4 + 1] & 4) != 0 )
          {
            v6 = *v5;
            if ( v6 != 0 )
            {
              ++s1;
              HIBYTE(v7) = v4;
              LOBYTE(v7) = v6;
              v4 = v7;
            }
            else
            {
              v4 = 0;
            }
          }
          v8 = *v3++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v8 + 1] & 4) != 0 )
          {
            v11 = *v3;
            if ( v11 != 0 )
            {
              HIBYTE(v9) = v8;
              ++v3;
              LOBYTE(v9) = v11;
              v8 = v9;
            }
            else
            {
              v8 = 0;
            }
          }
          if ( v8 != v4 )
            break;
          if ( v4 == 0 )
          {
            if ( _loc_update.updated )
              _loc_update.ptd->_ownlocale &= ~2u;
            return;
          }
        }
      }
      else
      {
        strcmp(str1: s1, str2: s2);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBE26
// Name: __mbscmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp(unsigned __int8 *s1, unsigned __int8 *s2)
{
  _mbscmp_l(s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CBE40
// Name: swap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall swap(char *a@<eax>, char *b@<ecx>, unsigned int width@<edx>)
{
  unsigned int v3; // esi
  char v4; // dl

  v3 = width;
  if ( a != b && width != 0 )
  {
    do
    {
      v4 = *a;
      *a = *b;
      --v3;
      *b = v4;
      ++a;
      ++b;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBE70
// Name: shortsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl shortsort(char *lo, char *hi, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // ecx
  char *v5; // ebp
  unsigned int v6; // ebx
  char *v7; // esi
  char *v8; // edi
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ecx
  char v12; // dl

  v4 = lo;
  v5 = hi;
  if ( hi > lo )
  {
    v6 = width;
    do
    {
      v7 = &lo[width];
      v8 = v4;
      if ( &lo[width] <= v5 )
      {
        do
        {
          if ( comp(a1: v7, a2: v8) > 0 )
            v8 = v7;
          v7 += v6;
        }
        while ( v7 <= v5 );
        v4 = lo;
      }
      v9 = v6;
      v10 = v5;
      if ( v8 != v5 && v6 != 0 )
      {
        v11 = v8 - v5;
        do
        {
          v12 = v10[v11];
          v10[v11] = *v10;
          --v9;
          *v10++ = v12;
        }
        while ( v9 != 0 );
        v6 = width;
        v4 = lo;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CBF00
// Name: _qsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort(char *base, unsigned int num, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // ebx
  unsigned int v5; // ebp
  char *v6; // esi
  unsigned int v7; // eax
  char *v8; // eax
  char *v9; // edi
  unsigned int v10; // ecx
  char *v11; // eax
  int v12; // ebp
  char *v13; // eax
  char *hi; // [esp+8h] [ebp-100h]
  char *v15; // [esp+Ch] [ebp-FCh]
  char stkptr_3; // [esp+13h] [ebp-F5h]
  char *lostk[30]; // [esp+14h] [ebp-F4h]
  char *histk[30]; // [esp+8Ch] [ebp-7Ch]

  v4 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return;
  }
  v5 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return;
  }
  if ( num >= 2 )
  {
    v6 = &base[width * (num - 1)];
    lostk[0] = nullptr;
    hi = base;
    v15 = v6;
    while ( 1 )
    {
      while ( 1 )
      {
        v7 = (v6 - v4) / v5 + 1;
        if ( v7 <= 8 )
        {
          shortsort(lo: v4, hi: v6, width: v5, comp);
          goto LABEL_11;
        }
        v9 = &v4[v5 * (v7 >> 1)];
        if ( comp(a1: v4, a2: v9) > 0 )
          swap(a: v4, b: v9, width: v5);
        if ( comp(a1: v4, a2: v6) > 0 )
          swap(a: v4, b: v6, width: v5);
        if ( comp(a1: v9, a2: v6) > 0 )
          swap(a: v9, b: v6, width: v5);
        while ( 1 )
        {
          if ( v9 > v4 )
          {
            while ( 1 )
            {
              v4 += v5;
              if ( v4 >= v9 )
                break;
              if ( comp(a1: v4, a2: v9) > 0 )
              {
                if ( v9 > v4 )
                  goto LABEL_25;
                goto LABEL_23;
              }
            }
          }
          do
LABEL_23:
            v4 += v5;
          while ( v4 <= v15 && comp(a1: v4, a2: v9) <= 0 );
          do
LABEL_25:
            v6 -= v5;
          while ( v6 > v9 && comp(a1: v6, a2: v9) > 0 );
          if ( v4 > v6 )
            break;
          v10 = v5;
          v11 = v6;
          if ( v4 != v6 )
          {
            v12 = v4 - v6;
            do
            {
              stkptr_3 = v11[v12];
              v11[v12] = *v11;
              --v10;
              *v11++ = stkptr_3;
            }
            while ( v10 != 0 );
            v5 = width;
          }
          if ( v9 == v6 )
            v9 = v4;
        }
        v6 += v5;
        if ( v9 >= v6 )
          goto LABEL_38;
        do
        {
          v6 -= v5;
          if ( v6 <= v9 )
            goto LABEL_38;
        }
        while ( comp(a1: v6, a2: v9) == 0 );
        if ( v9 < v6 )
        {
LABEL_40:
          v13 = hi;
        }
        else
        {
LABEL_38:
          while ( 1 )
          {
            v13 = hi;
            v6 -= v5;
            if ( v6 <= hi )
              break;
            if ( comp(a1: v6, a2: v9) != 0 )
              goto LABEL_40;
          }
        }
        if ( v6 - v13 >= v15 - v4 )
          break;
        if ( v4 < v15 )
        {
          lostk[(int)lostk[0] + 1] = v4;
          histk[(int)lostk[0]++ + 1] = v15;
        }
        if ( v13 >= v6 )
        {
LABEL_11:
          v8 = --lostk[0];
          if ( (int)lostk[0] < 0 )
            return;
          hi = lostk[(_DWORD)v8 + 1];
          v15 = histk[(_DWORD)v8 + 1];
          v6 = v15;
          v4 = hi;
        }
        else
        {
          v4 = hi;
          v15 = v6;
        }
      }
      if ( v13 < v6 )
      {
        lostk[(int)lostk[0] + 1] = v13;
        histk[(int)lostk[0]++ + 1] = v6;
      }
      if ( v4 >= v15 )
        goto LABEL_11;
      v6 = v15;
      hi = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC1B0
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x4C68F6);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC236
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x004CC251
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = (unsigned __int8)outbuffer[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = outbuffer[0];
        result = (unsigned __int8)outbuffer[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_18:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x004CC368
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CC390
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x004CC3D0
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance;
tail_loop_start:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start;
  while ( 1 )
  {
main_loop_entrance:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x004CC510
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance_0;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start_0:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance_0:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start_0;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x004CC634
// Name: __vsnwprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnwprintf_l(
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  if ( format != nullptr )
  {
    if ( count == 0 || string != nullptr )
    {
      str._flag = 66;
      str._base = (char *)string;
      str._ptr = (char *)string;
      if ( count <= 0x3FFFFFFF )
        str._cnt = 2 * count;
      else
        str._cnt = 0x7FFFFFFF;
      result = _woutput_l(stream: &str, format, plocinfo, argptr: ap);
      v6 = result;
      if ( string != nullptr )
      {
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr++ = 0;
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr = 0;
        return v6;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CC706
// Name: __vsnwprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnwprintf(unsigned __int16 *string, unsigned int count, const wchar_t *format, char *ap)
{
  return _vsnwprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x004CC730
// Name: __allrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allrem(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // eax
  int v9; // ecx
  bool v10; // cf
  unsigned __int64 v11; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 == 0 )
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    result = v4 % (unsigned int)a2;
    if ( v2 - 1 < 0 )
      return result;
    return -(__int64)result;
  }
  v6 = __PAIR64__(v3, a2);
  v7 = a1;
  do
  {
    v6 >>= 1;
    v7 >>= 1;
  }
  while ( HIDWORD(v6) != 0 );
  v8 = v7 / (unsigned int)v6;
  v9 = HIDWORD(a2) * v8;
  v11 = (unsigned int)a2 * (unsigned __int64)v8;
  v10 = __CFADD__(v9, HIDWORD(v11));
  HIDWORD(v11) += v9;
  if ( v10 || v11 > a1 )
    v11 -= a2;
  result = v11 - a1;
  if ( v2 - 1 < 0 )
    return -(__int64)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CC7F0
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004CC89A
// Name: strtoxq
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl strtoxq(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        int ibase,
        int flags)
{
  const char *v5; // edi
  threadlocaleinfostruct *locinfo; // esi
  char v8; // al
  bool v9; // cc
  int v10; // eax
  char v11; // al
  const char *v12; // edi
  const unsigned __int16 *pctype; // ebx
  unsigned __int16 v14; // ax
  unsigned int v15; // esi
  int v16; // eax
  char v17; // al
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-38h] BYREF
  int v19; // [esp+1Ch] [ebp-24h]
  unsigned __int64 v20; // [esp+20h] [ebp-20h]
  unsigned __int64 maxval; // [esp+28h] [ebp-18h]
  unsigned __int64 number; // [esp+30h] [ebp-10h]
  const char *p; // [esp+38h] [ebp-8h]
  char c; // [esp+3Fh] [ebp-1h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v5 = nptr;
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && (ibase < 2 || ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  number = 0;
  do
  {
    v8 = *v5++;
    v9 = locinfo->mb_cur_max <= 1;
    c = v8;
    if ( v9 )
    {
      v10 = locinfo->pctype[(unsigned __int8)c] & 8;
    }
    else
    {
      v10 = _isctype_l((unsigned __int8)c, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
  }
  while ( v10 != 0 );
  p = v5;
  if ( c == 45 )
  {
    flags |= 2u;
  }
  else if ( c != 43 )
  {
    goto LABEL_19;
  }
  v11 = *v5++;
  p = v5;
  c = v11;
LABEL_19:
  if ( ibase == 0 )
  {
    if ( c != 48 )
    {
      ibase = 10;
      goto LABEL_31;
    }
    if ( *v5 != 120 && *v5 != 88 )
    {
      ibase = 8;
      goto LABEL_31;
    }
    ibase = 16;
  }
  if ( ibase == 16 && c == 48 && (*v5 == 120 || *v5 == 88) )
  {
    v12 = v5 + 1;
    c = *v12;
    p = v12 + 1;
  }
LABEL_31:
  v19 = ibase >> 31;
  pctype = locinfo->pctype;
  v20 = 0xFFFFFFFFFFFFFFFFuLL % ibase;
  maxval = 0xFFFFFFFFFFFFFFFFuLL / ibase;
  while ( 1 )
  {
    v14 = pctype[(unsigned __int8)c];
    if ( (v14 & 4) != 0 )
    {
      v15 = c - 48;
    }
    else
    {
      if ( (v14 & 0x103) == 0 )
        break;
      v16 = c;
      if ( (unsigned __int8)(c - 97) <= 0x19u )
        v16 = c - 32;
      v15 = v16 - 55;
    }
    if ( v15 >= ibase )
      break;
    flags |= 8u;
    if ( number < maxval || number == maxval && v15 <= v20 )
    {
      number = v15 + __PAIR64__(v19, ibase) * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v17 = *p++;
    c = v17;
  }
  --p;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0
      && ((flags & 2) != 0 && number > 0x8000000000000000uLL
       || (flags & 2) == 0 && (number & 0x8000000000000000uLL) != 0LL) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
      {
        number = -1;
      }
      else if ( (flags & 2) != 0 )
      {
        number = 0x8000000000000000uLL;
      }
      else
      {
        number = 0x7FFFFFFFFFFFFFFFLL;
      }
    }
  }
  else
  {
    if ( endptr != nullptr )
      p = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = p;
  if ( (flags & 2) != 0 )
    number = -(__int64)number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x004CCB2E
// Name: __strtoi64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl _strtoi64(const char *nptr, char **endptr, int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxq(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxq(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004CCB57
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = (unsigned __int8)outbuffer[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = outbuffer[0];
        result = (unsigned __int8)outbuffer[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_18:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x004CCC6F
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CCC96
// Name: FindCompleteObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__thiscall FindCompleteObject(void **inptr)
{
  int v1; // edx
  _BYTE *result; // eax
  int v3; // edx

  v1 = *((_DWORD *)*inptr - 1);
  result = (char *)inptr - *(_DWORD *)(v1 + 4);
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    result -= *(unsigned int *)((char *)inptr - v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CCCAC
// Name: FindSITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindSITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        TypeDescriptor *pSrcTypeID,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  int v5; // esi
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  int v7; // eax
  const _s_RTTIBaseClassDescriptor *v9; // eax
  TypeDescriptor *pTypeDescriptor; // eax
  int v11; // eax
  const _s_RTTIBaseClassDescriptor *pBCD; // [esp+Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v5 = 0;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  if ( numBaseClasses != 0 )
  {
    while ( 1 )
    {
      pBCD = pBaseClassArray->arrayOfBaseClassDescriptors[v5];
      if ( pBCD->pTypeDescriptor == pTargetTypeID )
        break;
      strcmp(str1: (unsigned __int8 *)pBCD->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name);
      if ( v7 == 0 )
        break;
      if ( ++v5 >= numBaseClasses )
        return nullptr;
    }
    while ( ++v5 < numBaseClasses )
    {
      v9 = pBaseClassArray->arrayOfBaseClassDescriptors[v5];
      if ( (v9->attributes & 4) != 0 )
        break;
      pTypeDescriptor = v9->pTypeDescriptor;
      if ( pTypeDescriptor != pSrcTypeID )
      {
        strcmp(str1: (unsigned __int8 *)pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name);
        if ( v11 != 0 )
          continue;
      }
      return pBCD;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004CCD21
// Name: PMDtoOffset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall PMDtoOffset@<eax>(const PMD *pmd@<eax>, char *pThis)
{
  int pdisp; // edx
  int v3; // ecx

  pdisp = pmd->pdisp;
  v3 = 0;
  if ( pdisp >= 0 )
    v3 = *(_DWORD *)(*(_DWORD *)&pThis[pdisp] + pmd->vdisp) + pmd->pdisp;
  return v3 + pmd->mdisp;
}

//------------------------------------------------------------------------------
// Address: 0x004CCD40
// Name: FindMITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindMITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  const _s_RTTIBaseClassDescriptor *result; // eax
  const _s_RTTIBaseClassDescriptor *pSourceBCD; // [esp+Ch] [ebp-14h]
  const _s_RTTIBaseClassDescriptor *pTargetBCD; // [esp+10h] [ebp-10h]
  unsigned int nTargetBases; // [esp+14h] [ebp-Ch]
  unsigned int iTarget; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  pTargetBCD = nullptr;
  pSourceBCD = nullptr;
  nTargetBases = 0;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  while ( 1 )
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( pSourceBCD != nullptr )
        {
          if ( (v8->attributes & 3) == 0 && (pSourceBCD->attributes & 1) == 0 )
            return v8;
          return nullptr;
        }
        iTarget = i;
        pTargetBCD = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
        break;
    }
LABEL_12:
    if ( ++i >= numBaseClasses )
      return nullptr;
  }
  result = pTargetBCD;
  if ( pTargetBCD == nullptr )
  {
    pSourceBCD = v8;
    goto LABEL_12;
  }
  if ( i - iTarget > nTargetBases )
  {
    if ( (pTargetBCD->attributes & 3) != 0 )
      return nullptr;
  }
  else
  {
    if ( (pTargetBCD->attributes & 0x40) != 0 )
      return (pTargetBCD->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) == 0
           ? pTargetBCD
           : nullptr;
    if ( iTarget != 0 )
      return result;
  }
  if ( (v8->attributes & 1) != 0 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CCE42
// Name: FindVITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindVITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassDescriptor *v7; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  bool v11; // al
  int v12; // eax
  const _s_RTTIBaseClassDescriptor *result; // eax
  const _s_RTTIBaseClassArray *pBaseClassArray; // [esp+Ch] [ebp-24h]
  const _s_RTTIBaseClassDescriptor *pCrossCastTargetBCD; // [esp+10h] [ebp-20h]
  const _s_RTTIBaseClassDescriptor *pCrossCastSourceBCD; // [esp+14h] [ebp-1Ch]
  int offsetDownCastResult; // [esp+18h] [ebp-18h]
  const _s_RTTIBaseClassDescriptor *pDownCastResultBCD; // [esp+1Ch] [ebp-14h]
  unsigned int nTargetBases; // [esp+20h] [ebp-10h]
  unsigned int iTarget; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-8h]
  bool fDownCastAllowed; // [esp+2Fh] [ebp-1h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  offsetDownCastResult = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v7 = nullptr;
  pDownCastResultBCD = nullptr;
  pCrossCastSourceBCD = nullptr;
  pCrossCastTargetBCD = nullptr;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  nTargetBases = 0;
  fDownCastAllowed = true;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  do
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( (v8->attributes & 3) == 0 )
          pCrossCastTargetBCD = v8;
        iTarget = i;
        v7 = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
      {
        if ( i - iTarget > nTargetBases )
        {
          if ( (v8->attributes & 5) == 0 )
            pCrossCastSourceBCD = v8;
        }
        else if ( fDownCastAllowed )
        {
          if ( (v7->attributes & 0x40) != 0 )
          {
            if ( (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 4) == 0;
          }
          else
          {
            if ( iTarget == 0 && (v8->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = true;
          }
          if ( fDownCastAllowed && v11 )
          {
            v12 = PMDtoOffset(pmd: &v7->where, pThis: pCompleteObject);
            if ( pDownCastResultBCD != nullptr && offsetDownCastResult != v12 )
              return nullptr;
            pDownCastResultBCD = v7;
            offsetDownCastResult = v12;
          }
        }
      }
    }
    ++i;
  }
  while ( i < numBaseClasses );
  if ( !fDownCastAllowed || (result = pDownCastResultBCD, pDownCastResultBCD == nullptr) )
  {
    if ( pCrossCastSourceBCD == nullptr )
      return nullptr;
    result = pCrossCastTargetBCD;
    if ( pCrossCastTargetBCD == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD06B
// Name: __vswprintf_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vswprintf_helper(
        int (__cdecl *woutfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *),
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  bool v7; // sf
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  int retval; // [esp+38h] [ebp+14h]

  if ( format == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  if ( count != 0 && string == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  str._flag = 66;
  str._base = (char *)string;
  str._ptr = (char *)string;
  if ( count <= 0x3FFFFFFF )
    str._cnt = 2 * count;
  else
    str._cnt = 0x7FFFFFFF;
  result = woutfn(a1: &str, a2: format, a3: plocinfo, a4: ap);
  retval = result;
  if ( string != nullptr )
  {
    if ( result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr++ = 0;
LABEL_14:
        if ( --str._cnt >= 0 )
        {
          *str._ptr = 0;
          return retval;
        }
        if ( _flsbuf(ch: 0, &str) != -1 )
          return retval;
        goto LABEL_18;
      }
      if ( _flsbuf(ch: 0, &str) != -1 )
        goto LABEL_14;
    }
LABEL_18:
    v7 = str._cnt < 0;
    string[count - 1] = 0;
    return !v7 - 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD161
// Name: __vswprintf_c_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vswprintf_c_l(
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax

  result = _vswprintf_helper(woutfn: _woutput_l, string, count, format, plocinfo, ap);
  if ( result < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD189
// Name: __wtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtol(const wchar_t *nptr)
{
  return wcstol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x004CD19A
// Name: __wtoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl _wtoi(const wchar_t *nptr)
{
  return _wtol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CD19F
// Name: vscan_fn_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn_0@<eax>(
        wchar_t *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *),
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v5; // eax
  const wchar_t *v7; // [esp+0h] [ebp-28h]
  _iobuf str; // [esp+8h] [ebp-20h] BYREF

  v5 = wcslen(wcs: v7);
  if ( string != nullptr && format != nullptr )
  {
    str._flag = 73;
    str._base = (char *)string;
    str._ptr = (char *)string;
    if ( v5 <= 0x3FFFFFFF )
      str._cnt = 2 * v5;
    else
      str._cnt = 0x7FFFFFFF;
    return inputfn(a1: &str, a2: format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD20D
// Name: _swscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int swscanf(wchar_t *string, const wchar_t *format, ...)
{
  va_list arglist; // [esp+10h] [ebp+Ch] BYREF

  va_start(arglist, format);
  return vscan_fn_0(string, inputfn: _winput_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x004CD22C
// Name: __wtof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _wtof_l(wchar_t *nptr, localeinfo_struct *plocinfo)
{
  unsigned __int16 *v2; // esi
  long double result; // st7
  int v4; // eax
  _flt fltstruct; // [esp+8h] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+20h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v2 = nptr;
  if ( nptr != nullptr )
  {
    while ( _iswctype_l(c: *v2, mask: 8u, plocinfo: &_loc_update.localeinfo) != 0 )
      ++v2;
    v4 = wcslen(wcs: v2);
    result = _wfltin2(
               flt: &fltstruct,
               str: v2,
               len_ignore: v4,
               scale_ignore: 0,
               radix_ignore: 0,
               _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD2B6
// Name: __wtof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _wtof(wchar_t *nptr)
{
  return _wtof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CD2D0
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004CD2D9
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x004CD2EC
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004CD306
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD37B
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD3CA
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x004CD3F3
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD447
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x004CD472
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD4C1
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x004CD4EA
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalnum_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x107;
  else
    result = _isctype_l(c, mask: 263, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD53E
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalnum(int c)
{
  if ( __locale_changed != 0 )
    return _isalnum_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x107;
}

//------------------------------------------------------------------------------
// Address: 0x004CD569
// Name: __isprint_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isprint_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x157;
  else
    result = _isctype_l(c, mask: 343, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD5BD
// Name: _isprint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isprint(int c)
{
  if ( __locale_changed != 0 )
    return _isprint_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x157;
}

//------------------------------------------------------------------------------
// Address: 0x004CD5E8
// Name: __towlower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _towlower_l(unsigned __int16 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v3; // edx
  bool v4; // zf
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 widechar; // [esp+10h] [ebp-4h] BYREF

  result = 0xFFFF;
  if ( c != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    v3 = _loc_update.localeinfo.locinfo->lc_handle[2];
    if ( v3 != 0 )
    {
      if ( c >= 0x100u )
      {
        v4 = __crtLCMapStringW(
               plocinfo: &_loc_update.localeinfo,
               Locale: v3,
               dwMapFlags: 0x100u,
               lpSrcStr: &c,
               cchSrc: 1,
               lpDestStr: &widechar,
               cchDest: 1,
               code_page: _loc_update.localeinfo.locinfo->lc_codepage) == 0;
        result = c;
        if ( !v4 )
          result = widechar;
        goto LABEL_11;
      }
      v4 = _iswctype_l(c, mask: 1u, plocinfo: &_loc_update.localeinfo) == 0;
      result = c;
      if ( v4 )
      {
LABEL_11:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return result;
      }
      LOWORD(result) = _loc_update.localeinfo.locinfo->pclmap[c];
    }
    else
    {
      LOWORD(result) = c;
      if ( (unsigned __int16)(c - 65) <= 0x19u )
        LOWORD(result) = c + 32;
    }
    result = (unsigned __int16)result;
    goto LABEL_11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD695
// Name: _towlower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl towlower(unsigned __int16 c)
{
  return _towlower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CD6A3
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD6D9
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CD6E7
// Name: _iswdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswdigit(unsigned __int16 c)
{
  return iswctype(c, mask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x004CD6F5
// Name: _iswspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswspace(unsigned __int16 c)
{
  return iswctype(c, mask: 8u);
}

//------------------------------------------------------------------------------
// Address: 0x004CD703
// Name: _iswalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswalnum(unsigned __int16 c)
{
  return iswctype(c, mask: 0x107u);
}

//------------------------------------------------------------------------------
// Address: 0x004CD714
// Name: _iswcntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswcntrl(unsigned __int16 c)
{
  return iswctype(c, mask: 0x20u);
}

//------------------------------------------------------------------------------
// Address: 0x004CD722
// Name: _wcsncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsncat(unsigned __int16 *front, const wchar_t *back, unsigned int count)
{
  unsigned __int16 *v3; // ecx
  unsigned __int16 *result; // eax
  __int16 v5; // dx
  unsigned __int16 *v6; // ecx
  __int16 v8; // dx

  v3 = front;
  result = front;
  do
    v5 = *v3++;
  while ( v5 != 0 );
  v6 = v3 - 1;
  if ( count != 0 )
  {
    while ( 1 )
    {
      v8 = *back;
      --count;
      *v6++ = *back++;
      if ( v8 == 0 )
        break;
      if ( count == 0 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    *v6 = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CD75F
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // eax
  int *lconv_intl_refcount; // eax
  int *lconv_mon_refcount; // eax
  int *lconv_num_refcount; // eax
  int *ctype1_refcount; // eax
  __lc_time_data *lc_time_curr; // eax
  void **p_refcount; // edi
  int i; // ebx
  _DWORD *v9; // eax

  lconv = ptloci->lconv;
  if ( lconv != nullptr && lconv != &__lconv_c )
  {
    lconv_intl_refcount = ptloci->lconv_intl_refcount;
    if ( lconv_intl_refcount != nullptr && *lconv_intl_refcount == 0 )
    {
      lconv_mon_refcount = ptloci->lconv_mon_refcount;
      if ( lconv_mon_refcount != nullptr && *lconv_mon_refcount == 0 )
      {
        free(pMem: ptloci->lconv_mon_refcount);
        __free_lconv_mon(l: ptloci->lconv);
      }
      lconv_num_refcount = ptloci->lconv_num_refcount;
      if ( lconv_num_refcount != nullptr && *lconv_num_refcount == 0 )
      {
        free(pMem: ptloci->lconv_num_refcount);
        __free_lconv_num(l: ptloci->lconv);
      }
      free(pMem: ptloci->lconv_intl_refcount);
      free(pMem: ptloci->lconv);
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount != nullptr && *ctype1_refcount == 0 )
  {
    free(pMem: ptloci->ctype1 - 127);
    free(pMem: (void *)(ptloci->pclmap - 128));
    free(pMem: (void *)(ptloci->pcumap - 128));
    free(pMem: ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c && lc_time_curr->refcount == 0 )
  {
    __free_lc_time(lc_time: ptloci->lc_time_curr);
    free(pMem: ptloci->lc_time_curr);
  }
  p_refcount = (void **)&ptloci->lc_category[0].refcount;
  for ( i = 6; i != 0; --i )
  {
    if ( *(p_refcount - 2) != __clocalestr && *p_refcount != nullptr && *(_DWORD *)*p_refcount == 0 )
      free(pMem: *p_refcount);
    if ( *(p_refcount - 1) != nullptr )
    {
      v9 = p_refcount[1];
      if ( v9 != nullptr && *v9 == 0 )
        free(pMem: p_refcount[1]);
    }
    p_refcount += 4;
  }
  free(pMem: ptloci);
}

//------------------------------------------------------------------------------
// Address: 0x004CD89F
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int i; // ebp

  InterlockedIncrement(lpAddend: &ptloci->refcount);
  if ( ptloci->lconv_intl_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_intl_refcount);
  if ( ptloci->lconv_mon_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_mon_refcount);
  if ( ptloci->lconv_num_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_num_refcount);
  if ( ptloci->ctype1_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->ctype1_refcount);
  p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
  for ( i = 6; i != 0; --i )
  {
    if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
      InterlockedIncrement(lpAddend: *p_refcount);
    if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
      InterlockedIncrement(lpAddend: p_refcount[1]);
    p_refcount += 4;
  }
  InterlockedIncrement(lpAddend: &ptloci->lc_time_curr->refcount);
}

//------------------------------------------------------------------------------
// Address: 0x004CD925
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int i; // ebp

  if ( ptloci != nullptr )
  {
    InterlockedDecrement(lpAddend: &ptloci->refcount);
    if ( ptloci->lconv_intl_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_intl_refcount);
    if ( ptloci->lconv_mon_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_mon_refcount);
    if ( ptloci->lconv_num_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_num_refcount);
    if ( ptloci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->ctype1_refcount);
    p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
    for ( i = 6; i != 0; --i )
    {
      if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
        InterlockedDecrement(lpAddend: *p_refcount);
      if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
        InterlockedDecrement(lpAddend: p_refcount[1]);
      p_refcount += 4;
    }
    InterlockedDecrement(lpAddend: &ptloci->lc_time_curr->refcount);
  }
  return ptloci;
}

//------------------------------------------------------------------------------
// Address: 0x004CD9B1
// Name: _copytlocinfo_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall copytlocinfo_nolock(threadlocaleinfostruct *ptlocid@<eax>, threadlocaleinfostruct *ptlocis@<ecx>)
{
  if ( ptlocis != nullptr && ptlocid != nullptr && ptlocid != ptlocis )
  {
    *ptlocid = *ptlocis;
    ptlocid->refcount = 0;
    __addlocaleref(ptloci: ptlocid);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD9D5
// Name: _updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__usercall updatetlocinfoEx_nolock@<eax>(
        threadlocaleinfostruct **pptlocid@<eax>,
        threadlocaleinfostruct *ptlocis@<edi>)
{
  threadlocaleinfostruct *v2; // esi

  if ( ptlocis == nullptr || pptlocid == nullptr )
    return nullptr;
  v2 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    __addlocaleref(ptloci: ptlocis);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: v2);
      if ( v2->refcount == 0 && v2 != &__initiallocinfo )
        __freetlocinfo(ptloci: v2);
    }
  }
  return ptlocis;
}

//------------------------------------------------------------------------------
// Address: 0x004CDA13
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __updatetlocinfo()
{
  _tiddata *v0; // esi
  threadlocaleinfostruct *ptlocinfo; // esi
  threadlocaleinfostruct *ptloci; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptlocinfo = _getptd()->ptlocinfo;
  }
  else
  {
    _lock(locknum: 12);
    ptloci = updatetlocinfoEx_nolock(pptlocid: &v0->ptlocinfo, ptlocis: __ptlocinfo);
    _unlock(locknum: 12);
    ptlocinfo = ptloci;
  }
  if ( ptlocinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptlocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x004CDA89
// Name: sync_legacy_variables_lk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sync_legacy_variables_lk()
{
  int result; // eax

  __lc_codepage = __ptlocinfo->lc_codepage;
  __lc_collate_cp = __ptlocinfo->lc_collate_cp;
  __lc_clike = __ptlocinfo->lc_clike;
  __lc_time_curr = __ptlocinfo->lc_time_curr;
  __lconv = __ptlocinfo->lconv;
  _pctype = __ptlocinfo->pctype;
  result = __ptlocinfo->mb_cur_max;
  __mb_cur_max = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CDADC
// Name: __strcats
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _strcats(char *outstr, unsigned int sizeInBytes, int n, ...)
{
  int v3; // edi
  const char **p_n; // esi

  v3 = n;
  if ( n > 0 )
  {
    p_n = (const char **)&n;
    do
    {
      if ( strcat_s(_Dst: outstr, _SizeInBytes: sizeInBytes, _Src: *++p_n) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CDB1A
// Name: ___lc_strtolc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __lc_strtolc(tagLC_STRINGS *names, char *locale)
{
  const char *v2; // esi
  unsigned int v4; // eax
  bool j; // zf
  const char *v6; // edi
  char v7; // bl
  int v8; // eax
  char *szCountry; // eax
  unsigned int v10; // [esp-Ch] [ebp-18h]
  const char *v12; // [esp-8h] [ebp-14h]
  unsigned int v13; // [esp-4h] [ebp-10h]
  int i; // [esp+18h] [ebp+Ch]

  memset(dst: (int)names, value: nullptr, count: sizeof(tagLC_STRINGS));
  v2 = locale;
  if ( *locale == 0 )
    return 0;
  if ( *locale == 46 && locale[1] != 0 )
  {
    if ( strncpy_s(_Dst: names->szCodePage, _SizeInBytes: 0x10u, _Src: locale + 1, _Count: 0xFu) != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    names->szCodePage[15] = 0;
    return 0;
  }
  i = 0;
  strcspn(string: (unsigned __int8 *)locale, control: "_.,");
  for ( j = v4 == 0; !j; j = v4 == 0 )
  {
    v6 = &v2[v4];
    v7 = v2[v4];
    if ( i != 0 )
    {
      if ( i == 1 )
      {
        if ( v4 >= 0x40 || v7 == 95 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 64;
        szCountry = names->szCountry;
      }
      else
      {
        if ( i != 2 || v4 >= 0x10 || v7 != 0 && v7 != 44 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 16;
        szCountry = names->szCodePage;
      }
      v8 = strncpy_s(_Dst: szCountry, _SizeInBytes: v10, _Src: v12, _Count: v13);
    }
    else
    {
      if ( v4 >= 0x40 || v7 == 46 )
        return -1;
      v8 = strncpy_s(_Dst: names->szLanguage, _SizeInBytes: 0x40u, _Src: v2, _Count: v4);
    }
    if ( v8 != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( v7 == 44 || v7 == 0 )
      return 0;
    ++i;
    v2 = v6 + 1;
    strcspn(string: (unsigned __int8 *)v6 + 1, control: "_.,");
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004CDC43
// Name: ___lc_lctostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __lc_lctostr(char *locale, unsigned int sizeInBytes, const tagLC_STRINGS *names)
{
  if ( strcpy_s(_Dst: locale, _SizeInBytes: sizeInBytes, _Src: names->szLanguage) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( names->szCountry[0] != 0 )
    _strcats(outstr: locale, sizeInBytes, n: 2, "_", names->szCountry);
  if ( names->szCodePage[0] != 0 )
    _strcats(outstr: locale, sizeInBytes, n: 2, ".", names->szCodePage);
}

//------------------------------------------------------------------------------
// Address: 0x004CDCAE
// Name: _setlocale_get_all
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall setlocale_get_all@<eax>(threadlocaleinfostruct *ploci@<esi>)
{
  char *result; // eax
  char *v2; // edi
  unsigned int *v3; // ebp
  threadlocaleinfostruct::<unnamed_tag> *v4; // ebx
  int v5; // eax
  const $FAA2ED44176E8AD2BA02CFC02FF7315D *i; // [esp+4h] [ebp-10h]
  int same; // [esp+8h] [ebp-Ch]
  int refcount; // [esp+Ch] [ebp-8h]
  char *pMem; // [esp+10h] [ebp-4h]

  refcount = 1;
  result = (char *)MemAlloc_Alloc(nSize: 0x355u);
  pMem = result;
  if ( result != nullptr )
  {
    v2 = result + 4;
    result[4] = 0;
    *(_DWORD *)result = 1;
    v3 = &ploci->lc_handle[1];
    same = 1;
    v4 = &ploci->lc_category[1];
    _strcats(outstr: result + 4, sizeInBytes: 0x351u, n: 3, "LC_COLLATE", "=", ploci->lc_category[1].locale);
    i = &__lc_category[1];
    do
    {
      if ( strcat_s(_Dst: v2, _SizeInBytes: 0x351u, _Src: ";") != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      strcmp(str1: (unsigned __int8 *)v4->locale, str2: (unsigned __int8 *)v3[22]);
      if ( v5 != 0 )
        refcount = 0;
      ++same;
      ++i;
      v3 = (unsigned int *)((char *)ploci + 16 * same);
      v4 = (threadlocaleinfostruct::<unnamed_tag> *)(v3 + 18);
      _strcats(outstr: v2, sizeInBytes: 0x351u, n: 3, i->catname, "=", v3[18]);
    }
    while ( (int)i < (int)&__lc_category[5] );
    if ( refcount != 0 )
    {
      free(pMem);
      if ( ploci->lc_category[0].refcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].refcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].refcount);
      }
      if ( ploci->lc_category[0].wrefcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].wrefcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].wrefcount);
      }
      result = ploci->lc_category[2].locale;
      ploci->lc_category[0].refcount = nullptr;
      ploci->lc_category[0].locale = nullptr;
    }
    else
    {
      if ( ploci->lc_category[0].refcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].refcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].refcount);
      }
      if ( ploci->lc_category[0].wrefcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].wrefcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].wrefcount);
      }
      ploci->lc_category[0].refcount = (int *)pMem;
      ploci->lc_category[0].locale = v2;
      result = v2;
    }
    ploci->lc_category[0].wlocale = nullptr;
    ploci->lc_category[0].wrefcount = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CDE1F
// Name: __expandlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _expandlocale(char *expr, char *output, unsigned int sizeInChars, tagLC_ID *id, unsigned int *cp)
{
  const char *v5; // esi
  setloc_struct *p_setloc_data; // eax
  tagLC_ID *p_cacheid; // ebx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  unsigned int charactersInExpression; // [esp+10h] [ebp-50h]
  unsigned int *pcachecp; // [esp+14h] [ebp-4Ch]
  char *cachein; // [esp+18h] [ebp-48h]
  char *cacheout; // [esp+28h] [ebp-38h]
  tagLC_STRINGS names; // [esp+2Ch] [ebp-34h] BYREF

  v5 = expr;
  p_setloc_data = &_getptd()->_setloc_data;
  pcachecp = &p_setloc_data->_cachecp;
  p_cacheid = &p_setloc_data->_cacheid;
  cachein = p_setloc_data->_cachein;
  cacheout = p_setloc_data->_cacheout;
  if ( expr == nullptr || output == nullptr || sizeInChars == 0 )
    return nullptr;
  if ( *expr == 67 && expr[1] == 0 )
  {
    if ( strcpy_s(_Dst: output, _SizeInBytes: sizeInChars, _Src: "C") != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( id != nullptr )
    {
      id->wLanguage = 0;
      id->wCountry = 0;
      id->wCodePage = 0;
    }
    if ( cp != nullptr )
      *cp = 0;
    return output;
  }
  strlen(buf: (unsigned __int8 *)expr);
  charactersInExpression = v9;
  if ( v9 >= 0x83
    || (strcmp(str1: (unsigned __int8 *)cacheout, str2: (unsigned __int8 *)expr), v10 != 0)
    && (strcmp(str1: (unsigned __int8 *)cachein, str2: (unsigned __int8 *)expr), v11 != 0) )
  {
    if ( __lc_strtolc(&names, locale: expr) == 0
      && __get_qualified_locale(lpInStr: &names, lpOutId: p_cacheid, lpOutStr: &names) != 0 )
    {
      *pcachecp = p_cacheid->wCodePage;
      __lc_lctostr(locale: cacheout, sizeInBytes: 0x83u, &names);
      if ( *expr == 0 || (v12 = charactersInExpression, charactersInExpression >= 0x83) )
      {
        v12 = 0;
        v5 = defaultValue;
      }
      if ( strncpy_s(_Dst: cachein, _SizeInBytes: 0x83u, _Src: v5, _Count: v12 + 1) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      goto LABEL_23;
    }
    return nullptr;
  }
LABEL_23:
  if ( id != nullptr )
    *id = *p_cacheid;
  if ( cp != nullptr )
    *cp = *pcachecp;
  if ( strcpy_s(_Dst: output, _SizeInBytes: sizeInChars, _Src: cacheout) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return cacheout;
}

//------------------------------------------------------------------------------
// Address: 0x004CDFF3
// Name: _setlocale_set_cat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall setlocale_set_cat@<eax>(threadlocaleinfostruct *ploci@<esi>, char *locale@<ecx>, int category)
{
  _is_ctype_compatible *Lcid_c; // edi
  char *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int *v9; // ecx
  unsigned int id; // ecx
  _is_ctype_compatible *v11; // eax
  unsigned int v12; // edx
  int is_clike; // edx
  _is_ctype_compatible *v14; // eax
  unsigned int j; // eax
  void **p_refcount; // edi
  int *v17; // eax
  char *v18; // [esp-4h] [ebp-15Ch]
  unsigned int buf2; // [esp+10h] [ebp-148h]
  unsigned int oldcodepage; // [esp+18h] [ebp-140h]
  tagLC_ID idtemp; // [esp+1Ch] [ebp-13Ch] BYREF
  unsigned int oldhandle; // [esp+24h] [ebp-134h]
  char *oldlocale; // [esp+28h] [ebp-130h]
  _is_ctype_compatible buf1; // [esp+2Ch] [ebp-12Ch]
  unsigned int cptemp; // [esp+34h] [ebp-124h] BYREF
  unsigned int *v26; // [esp+38h] [ebp-120h]
  char *pch; // [esp+3Ch] [ebp-11Ch]
  int i; // [esp+40h] [ebp-118h]
  unsigned __int16 out[128]; // [esp+44h] [ebp-114h] BYREF
  char lctemp[132]; // [esp+144h] [ebp-14h] BYREF

  Lcid_c = _getptd()->_setloc_data._Lcid_c;
  if ( _expandlocale(expr: locale, output: lctemp, sizeInChars: 0x83u, id: &idtemp, cp: &cptemp) == nullptr )
    return nullptr;
  v6 = (char *)ploci + 16 * category;
  strcmp(str1: (unsigned __int8 *)lctemp, str2: *((unsigned __int8 **)v6 + 18));
  if ( v7 != 0 )
  {
    strlen(buf: (unsigned __int8 *)lctemp);
    i = v8 + 5;
    pch = (char *)MemAlloc_Alloc(nSize: v8 + 5);
    if ( pch == nullptr )
      return nullptr;
    oldlocale = *((char **)v6 + 18);
    v26 = &ploci->lc_handle[category];
    oldhandle = *v26;
    buf1.is_clike = (int)&ploci->lc_id[category];
    oldcodepage = ploci->lc_codepage;
    if ( strcpy_s(_Dst: pch + 4, _SizeInBytes: i - 4, _Src: lctemp) != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    v9 = v26;
    *((_DWORD *)v6 + 18) = pch + 4;
    *v9 = idtemp.wLanguage;
    *(tagLC_ID *)buf1.is_clike = idtemp;
    if ( category == 2 )
    {
      i = 0;
      ploci->lc_codepage = cptemp;
      id = Lcid_c[4].id;
      buf1.is_clike = Lcid_c[4].is_clike;
      v11 = Lcid_c;
      while ( ploci->lc_codepage != v11->id )
      {
        v12 = v11->id;
        ++i;
        v11->id = id;
        buf2 = v12;
        is_clike = v11->is_clike;
        v11->is_clike = buf1.is_clike;
        id = buf2;
        ++v11;
        buf1.is_clike = is_clike;
        if ( i >= 5 )
          goto LABEL_14;
      }
      if ( i != 0 )
      {
        v14 = &Lcid_c[i];
        Lcid_c->id = v14->id;
        Lcid_c->is_clike = v14->is_clike;
        v14->id = id;
        v14->is_clike = buf1.is_clike;
      }
LABEL_14:
      if ( i == 5 )
      {
        if ( __crtGetStringTypeA(
               plocinfo: nullptr,
               dwInfoType: 1u,
               lpSrcStr: first_127char,
               cchSrc: 127,
               lpCharType: out,
               code_page: ploci->lc_codepage,
               lcid: ploci->lc_handle[2],
               bError: 1) != 0 )
        {
          for ( j = 0; j < 0x7F; ++j )
            out[j] &= 0x1FFu;
          Lcid_c->is_clike = memcmp(lhs: out, rhs: ctype_loc_style, siz: 0xFEu) == 0;
        }
        else
        {
          Lcid_c->is_clike = 0;
        }
        Lcid_c->id = ploci->lc_codepage;
      }
      ploci->lc_clike = Lcid_c->is_clike;
    }
    if ( category == 1 )
      ploci->lc_collate_cp = cptemp;
    if ( __lc_category[category].init(a1: ploci) != 0 )
    {
      v18 = pch;
      *((_DWORD *)v6 + 18) = oldlocale;
      free(pMem: v18);
      *v26 = oldhandle;
      ploci->lc_codepage = oldcodepage;
      return nullptr;
    }
    if ( oldlocale != __clocalestr )
    {
      p_refcount = (void **)&ploci->lc_category[category].refcount;
      if ( InterlockedDecrement(lpAddend: (volatile LONG *)*p_refcount) == 0 )
      {
        free(pMem: *p_refcount);
        free(pMem: *((void **)v6 + 21));
        *((_DWORD *)v6 + 19) = 0;
      }
    }
    v17 = (int *)pch;
    *(_DWORD *)pch = 1;
    ploci->lc_category[category].refcount = v17;
  }
  return *((char **)v6 + 18);
}

//------------------------------------------------------------------------------
// Address: 0x004CE2E9
// Name: _setlocale_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall setlocale_nolock(char *_locale, threadlocaleinfostruct *ploci, int _category)
{
  int v3; // ebx
  threadlocaleinfostruct *v4; // esi
  char *result; // eax
  unsigned __int8 *v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ebx
  unsigned int v9; // eax
  const $FAA2ED44176E8AD2BA02CFC02FF7315D *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned __int8 *v15; // edi
  unsigned __int8 **lc_category; // edi
  int v17; // eax
  int i; // [esp+10h] [ebp-20h]
  unsigned int len; // [esp+14h] [ebp-1Ch]
  unsigned int lena; // [esp+14h] [ebp-1Ch]
  int fLocaleSet; // [esp+18h] [ebp-18h]
  char lctemp[132]; // [esp+1Ch] [ebp-14h] BYREF

  v3 = 0;
  v4 = ploci;
  if ( _category != 0 )
  {
    if ( _locale != nullptr )
      return setlocale_set_cat(ploci, locale: _locale, category: _category);
    else
      return ploci->lc_category[_category].locale;
  }
  len = 1;
  fLocaleSet = 0;
  if ( _locale == nullptr )
    return setlocale_get_all(ploci: v4);
  if ( *_locale == 76 && _locale[1] == 67 && _locale[2] == 95 )
  {
    v6 = (unsigned __int8 *)_locale;
    do
    {
      strpbrk(string: v6, control: "=;");
      v8 = v7;
      if ( v7 == nullptr )
        return nullptr;
      v9 = v7 - v6;
      lena = v9;
      if ( v9 == 0 || *v8 == 59 )
        return nullptr;
      i = 1;
      v10 = &__lc_category[1];
      while ( 1 )
      {
        if ( strncmp(first: v10->catname, last: (const char *)v6, count: v9) == 0 )
        {
          strlen(buf: (unsigned __int8 *)v10->catname);
          if ( lena == v11 )
            break;
        }
        ++i;
        if ( (int)++v10 > (int)&__lc_category[5] )
          break;
        v9 = lena;
      }
      v12 = v8 + 1;
      strcspn(string: v12, control: ";");
      v14 = v13;
      if ( v13 == 0 && *v12 != 59 )
        return nullptr;
      if ( i <= 5 )
      {
        if ( strncpy_s(_Dst: lctemp, _SizeInBytes: 0x83u, _Src: (const char *)v12, _Count: v13) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        lctemp[v14] = 0;
        if ( setlocale_set_cat(ploci, locale: lctemp, category: i) != nullptr )
          ++fLocaleSet;
      }
      v15 = &v12[v14];
      if ( *v15 == 0 )
        break;
      v6 = v15 + 1;
    }
    while ( *v6 != 0 );
    result = nullptr;
    if ( fLocaleSet == 0 )
      return result;
    v4 = ploci;
    return setlocale_get_all(ploci: v4);
  }
  result = _expandlocale(expr: _locale, output: lctemp, sizeInChars: 0x83u, id: nullptr, cp: nullptr);
  if ( result != nullptr )
  {
    lc_category = (unsigned __int8 **)v4->lc_category;
    do
    {
      if ( v3 != 0 )
      {
        strcmp(str1: (unsigned __int8 *)lctemp, str2: *lc_category);
        if ( v17 == 0 || setlocale_set_cat(ploci: v4, locale: lctemp, category: v3) != nullptr )
          ++fLocaleSet;
        else
          len = 0;
      }
      ++v3;
      lc_category += 4;
    }
    while ( v3 <= 5 );
    result = nullptr;
    if ( len != 0 || fLocaleSet != 0 )
      return setlocale_get_all(ploci: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CE4B7
// Name: _setlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl setlocale(unsigned int _category, char *_locale)
{
  _tiddata *v3; // esi
  threadlocaleinfostruct *v4; // edi
  int v5; // eax
  char *retval; // [esp+14h] [ebp-20h]

  retval = nullptr;
  if ( _category <= 5 )
  {
    v3 = _getptd();
    __updatetlocinfo();
    v3->_ownlocale |= 0x10u;
    v4 = (threadlocaleinfostruct *)calloc(count: 0xD8u, size: 1u);
    if ( v4 != nullptr )
    {
      _lock(locknum: 12);
      copytlocinfo_nolock(ptlocid: v4, ptlocis: v3->ptlocinfo);
      _unlock(locknum: 12);
      retval = setlocale_nolock(_locale, ploci: v4, _category);
      if ( retval != nullptr )
      {
        if ( _locale != nullptr )
        {
          strcmp(str1: (unsigned __int8 *)_locale, str2: (unsigned __int8 *)__clocalestr);
          if ( v5 != 0 )
            __locale_changed = 1;
        }
        _lock(locknum: 12);
        updatetlocinfoEx_nolock(pptlocid: &v3->ptlocinfo, ptlocis: v4);
        __removelocaleref(ptloci: v4);
        if ( (v3->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
        {
          updatetlocinfoEx_nolock(pptlocid: &__ptlocinfo, ptlocis: v3->ptlocinfo);
          memcpy(dst: (unsigned __int8 *)__lc_handle, src: (unsigned __int8 *)__ptlocinfo->lc_handle, count: 0x18u);
          sync_legacy_variables_lk();
        }
        _unlock(locknum: 12);
      }
      else
      {
        __removelocaleref(ptloci: v4);
        __freetlocinfo(ptloci: v4);
      }
    }
    v3->_ownlocale &= ~0x10u;
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE627
// Name: _wcschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcschr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  for ( result = (unsigned __int16 *)string; *result != 0; ++result )
  {
    if ( *result == ch )
      return result;
  }
  if ( *result != ch )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CE650
// Name: __allshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _allshr@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> 31;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> (a2 & 0x1F);
  }
  else
  {
    a1 >>= a2 & 0x1F;
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x004CE680
// Name: __allshl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _allshl@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  __int64 v2; // rax

  if ( a2 >= 0x40u )
  {
    LODWORD(v2) = 0;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(v2) = 0;
  }
  else
  {
    return a1 << (a2 & 0x1F);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004CE69F
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x004CE710
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x004CE790
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004CE7A6
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE7E6
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CE7FD
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: (unsigned __int8 *)s);
    memmove(dst: (unsigned __int8 *)&s[dist], src: (unsigned __int8 *)s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE81A
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CE828
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CE836
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v9; // edi
  int v11; // eax
  char *v12; // esi
  char *v13; // esi
  unsigned int v14; // ebx
  unsigned __int8 *v15; // ecx
  _BYTE *v16; // esi
  int v17; // eax
  _BYTE *v18; // esi
  _BYTE *v19; // esi
  int v20; // [esp-4h] [ebp-20h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v20 = 22;
LABEL_3:
    v9 = v20;
    *v8 = v20;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v9;
  }
  if ( ndec <= 0 )
    v11 = 0;
  else
    v11 = ndec;
  if ( sizeInBytes <= v11 + 9 )
  {
    v8 = _errno();
    v20 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v12 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v12 = buf + 1;
  }
  if ( ndec > 0 )
  {
    *v12 = v12[1];
    *++v12 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  }
  v13 = &v12[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v14 = -1;
  else
    v14 = sizeInBytes + buf - v13;
  if ( strcpy_s(_Dst: v13, _SizeInBytes: v14, _Src: "e+000") != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  v15 = (unsigned __int8 *)(v13 + 2);
  if ( caps != 0 )
    *v13 = 69;
  v16 = v13 + 1;
  if ( *pflt->mantissa != 48 )
  {
    v17 = pflt->decpt - 1;
    if ( v17 < 0 )
    {
      v17 = 1 - pflt->decpt;
      *v16 = 45;
    }
    v18 = v16 + 1;
    if ( v17 >= 100 )
    {
      *v18 += v17 / 100;
      v17 %= 100;
    }
    v19 = v18 + 1;
    if ( v17 >= 10 )
    {
      *v19 += v17 / 10;
      LOBYTE(v17) = v17 % 10;
    }
    v19[1] += v17;
  }
  if ( (_outputformat & 1) != 0 && *v15 == 48 )
    memmove(dst: v15, src: v15 + 1, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CE9A3
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( sizeInBytes == -1 )
      v7 = -1;
    else
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CEA71
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CEA8F
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoa_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v6; // esi
  int *v7; // eax
  int v8; // esi
  int result; // eax
  unsigned int v10; // eax
  bool v11; // zf
  _BYTE *v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  char *v16; // esi
  char *v17; // eax
  char *v18; // esi
  int x_low; // eax
  unsigned __int16 v20; // ax
  unsigned int v21; // ecx
  char *i; // eax
  _BYTE *v23; // esi
  __int64 v24; // rax
  __int64 v25; // rcx
  _BYTE *v26; // esi
  _BYTE *v27; // edi
  __int64 v28; // rax
  __int64 v29; // rcx
  __int64 v30; // rax
  __int64 v31; // rcx
  __int64 v32; // rcx
  __int64 v33; // [esp-Ch] [ebp-38h]
  int v34; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v6 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = _errno();
    v34 = 22;
LABEL_5:
    v8 = v34;
    *v7 = v34;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v8;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v7 = _errno();
    v34 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v10 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v10 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v10, ndec, caps: 0);
    if ( result != 0 )
    {
      v11 = !_loc_update.updated;
      *buf = 0;
      if ( !v11 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v12 = v6 + 1;
    *v12 = caps == 0 ? 120 : 88;
    strrchr(string: v12 + 1, chr: 0x65u);
    if ( v13 != nullptr )
    {
      *v13 = caps == 0 ? 112 : 80;
      v13[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v14 = v6 + 1;
    *v14 = caps == 0 ? 120 : 88;
    v15 = v14 + 1;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      *v15 = 49;
      v16 = v15 + 1;
    }
    else
    {
      *v15 = 48;
      v16 = v15 + 1;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v17 = v16;
    v18 = v16 + 1;
    pos = v17;
    if ( ndec != 0 )
      *v17 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v17 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v20 = ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        if ( v20 > 0x39u )
          LOBYTE(v20) = (caps != 0 ? 7 : 39) + v20;
        v21 = HIDWORD(mask);
        maskpos -= 4;
        *v18++ = v20;
        --ndec;
        mask = __PAIR64__(v21, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v18 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: (int)v18, value: (unsigned __int8 *)0x30, count: ndec);
      v18 += ndec;
    }
    if ( *pos == 0 )
      v18 = pos;
    *v18 = caps == 0 ? 112 : 80;
    v23 = v18 + 1;
    HIDWORD(v25) = 0;
    v24 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v24 < 0 )
    {
      *v23 = 45;
      v26 = v23 + 1;
      v24 = -v24;
    }
    else
    {
      *v23 = 43;
      v26 = v23 + 1;
    }
    v27 = v26;
    *v26 = 48;
    if ( v24 >= 0 )
    {
      LODWORD(v25) = 1000;
      if ( v24 >= 1000 )
      {
        v33 = v25;
        v29 = v24 % v25;
        v28 = v24 / v33;
        *v26++ = v28 + 48;
        HIDWORD(exponent) = HIDWORD(v28);
        v24 = v29;
        if ( v26 != v27 )
          goto LABEL_60;
      }
    }
    if ( v24 >= 100 )
    {
LABEL_60:
      v31 = v24 % 100;
      v30 = v24 / 100;
      *v26 = v30 + 48;
      HIDWORD(exponent) = HIDWORD(v30);
      ++v26;
      v24 = v31;
    }
    if ( v26 != v27 || v24 >= 10 )
    {
      v32 = v24 % 10;
      *v26++ = v24 / 10 + 48;
      LOBYTE(v24) = v24 % 10;
      HIDWORD(exponent) = HIDWORD(v32);
    }
    *v26 = v24 + 48;
    v26[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CEE00
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // eax
  char *v11; // esi
  int decpt; // eax
  char *v13; // esi
  int v14; // ebx
  char *v15; // esi
  int v16; // ebx
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
    {
      v10 = &buf[v8 + (pflt->sign == 45)];
      *v10 = 48;
      v10[1] = 0;
    }
    v11 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v11 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = &v11[decpt];
    }
    else
    {
      shift(s: v11, dist: 1);
      *v11 = 48;
      v13 = v11 + 1;
    }
    if ( ndec > 0 )
    {
      shift(s: v13, dist: 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v14 = pflt->decpt;
      v15 = v13 + 1;
      if ( v14 < 0 )
      {
        v16 = -v14;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: v15, dist: ndec);
        memset(dst: (int)v15, value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CEEF5
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v6 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CEFAE
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  BOOL v8; // eax
  char *v9; // edi
  _strflt retstrflt; // [esp+Ch] [ebp-30h] BYREF
  int g_magnitude; // [esp+1Ch] [ebp-20h]
  char resstr[24]; // [esp+20h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    g_magnitude = retstrflt.decpt - 1;
    v8 = retstrflt.sign == 45;
    v9 = &buf[v8];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v8;
    result = _fptostr(buf: v9, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( g_magnitude < retstrflt.decpt - 1 )
        v9[strlen(v9) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CF16C
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _setdefaultprecision()
{
  int result; // eax

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CF195
// Name: __ms_p5_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ms_p5_test_fdiv()
{
  return 4195835.0 - 4195835.0 / 3145727.0 * 3145727.0 > 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004CF1D1
// Name: __ms_p5_mp_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ms_p5_mp_test_fdiv()
{
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *IsProcessorFeaturePresent)(DWORD); // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32");
  if ( ModuleHandleA != nullptr
    && (IsProcessorFeaturePresent = (BOOL (__stdcall *)(DWORD))GetProcAddress(
                                                                 hModule: ModuleHandleA,
                                                                 lpProcName: "IsProcessorFeaturePresent")) != nullptr )
  {
    return IsProcessorFeaturePresent(ProcessorFeature: 0);
  }
  else
  {
    return _ms_p5_test_fdiv();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF1FA
// Name: _use_encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl use_encode_pointer()
{
  unsigned int v0; // ebx
  HMODULE ModuleHandleA; // eax
  char *v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // eax
  int bEncode; // [esp+8h] [ebp-8h]
  int winmajor; // [esp+Ch] [ebp-4h] BYREF

  v0 = 0;
  bEncode = 1;
  winmajor = 0;
  _get_winmajor(pValue: (unsigned int *)&winmajor);
  if ( winmajor > 5 )
    return 1;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v3 = (char *)ModuleHandleA + *((_DWORD *)ModuleHandleA + 15);
  v4 = (unsigned __int8 *)&v3[*((unsigned __int16 *)v3 + 10) + 24];
  if ( *((_WORD *)v3 + 3) != 0 )
  {
    while ( 1 )
    {
      strcmp(str1: ".mixcrt", str2: v4);
      if ( v5 == 0 )
        break;
      ++v0;
      v4 += 40;
      if ( v0 >= *((unsigned __int16 *)v3 + 3) )
        return bEncode;
    }
    return 0;
  }
  return bEncode;
}

//------------------------------------------------------------------------------
// Address: 0x004CF266
// Name: __encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _encode_pointer(void *ptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v2; // eax
  PVOID (__stdcall *EncodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  unsigned int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr
    && __flsindex != -1
    && (v6 = __flsindex,
        Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex),
        (v2 = Value(a1: v6)) != 0) )
  {
    EncodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 504);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || use_encode_pointer() == 0 )
      return ptr;
    EncodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "EncodePointer");
  }
  if ( EncodePointer != nullptr )
    return EncodePointer(Ptr: ptr);
  return ptr;
}

//------------------------------------------------------------------------------
// Address: 0x004CF2D4
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _encoded_null()
{
  return _encode_pointer(ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CF2DD
// Name: __decode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _decode_pointer(void *codedptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v2; // eax
  PVOID (__stdcall *DecodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  unsigned int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr
    && __flsindex != -1
    && (v6 = __flsindex,
        Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex),
        (v2 = Value(a1: v6)) != 0) )
  {
    DecodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 508);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || use_encode_pointer() == 0 )
      return codedptr;
    DecodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "DecodePointer");
  }
  if ( DecodePointer != nullptr )
    return DecodePointer(Ptr: codedptr);
  return codedptr;
}

//------------------------------------------------------------------------------
// Address: 0x004CF34B
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}

//------------------------------------------------------------------------------
// Address: 0x004CF354
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *(__stdcall *__cdecl __set_flsgetvalue())(unsigned int)
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: __getvalueindex);
  if ( Value == nullptr )
  {
    Value = _decode_pointer(codedptr: gpFlsGetValue);
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: Value);
  }
  return (void *(__stdcall *)(unsigned int))Value;
}

//------------------------------------------------------------------------------
// Address: 0x004CF386
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _mtterm()
{
  void (__stdcall *v0)(unsigned int); // eax
  unsigned int v2; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v2 = __flsindex;
    v0 = (void (__stdcall *)(unsigned int))_decode_pointer(codedptr: gpFlsFree);
    v0(a1: v2);
    __flsindex = -1;
  }
  if ( __getvalueindex != -1 )
  {
    TlsFree(dwTlsIndex: __getvalueindex);
    __getvalueindex = -1;
  }
  return _mtdeletelocks();
}

//------------------------------------------------------------------------------
// Address: 0x004CF3C3
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  HINSTANCE__ *hKernel32; // [esp+10h] [ebp-1Ch]

  hKernel32 = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  ptd->_pxcptacttab = _XcptActTab;
  ptd->_holdrand = 1;
  if ( hKernel32 != nullptr && use_encode_pointer() != 0 )
  {
    ptd->_encode_ptr = GetProcAddress(hModule: hKernel32, lpProcName: "EncodePointer");
    ptd->_decode_ptr = GetProcAddress(hModule: hKernel32, lpProcName: "DecodePointer");
  }
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  InterlockedIncrement(lpAddend: &__initialmbcinfo.refcount);
  _lock(locknum: 12);
  ptd->ptlocinfo = ptloci;
  if ( ptloci == nullptr )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptloci: ptd->ptlocinfo);
  _unlock(locknum: 12);
}

//------------------------------------------------------------------------------
// Address: 0x004CF482
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  void *(__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  _tiddata *v4; // eax
  int (__stdcall *v5)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  _tiddata *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = __set_flsgetvalue();
  v3 = (_tiddata *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = (_tiddata *)calloc(count: 1u, size: 0x214u);
    v3 = v4;
    if ( v4 != nullptr )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(codedptr: gpFlsSetValue);
      if ( v5(a1: v8, a2: v10) != 0 )
      {
        _initptd(ptd: v3, ptloci: nullptr);
        CurrentThreadId = GetCurrentThreadId();
        v3->_thandle = -1;
        v3->_tid = CurrentThreadId;
      }
      else
      {
        free(pMem: v3);
        v3 = nullptr;
      }
    }
  }
  SetLastError(dwErrCode: v1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004CF4F9
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd()
{
  _tiddata *v0; // esi

  v0 = _getptd_noexit();
  if ( v0 == nullptr )
    _amsg_exit(rterrnum: 16);
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x004CF511
// Name: _freefls(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _freefls(void *data)
{
  threadmbcinfostruct *v1; // edi
  threadlocaleinfostruct *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( data != nullptr )
  {
    if ( *((_DWORD *)data + 9) != 0 )
      free(pMem: *((void **)data + 9));
    if ( *((_DWORD *)data + 11) != 0 )
      free(pMem: *((void **)data + 11));
    if ( *((_DWORD *)data + 13) != 0 )
      free(pMem: *((void **)data + 13));
    if ( *((_DWORD *)data + 15) != 0 )
      free(pMem: *((void **)data + 15));
    if ( *((_DWORD *)data + 17) != 0 )
      free(pMem: *((void **)data + 17));
    if ( *((_DWORD *)data + 18) != 0 )
      free(pMem: *((void **)data + 18));
    if ( *((_XCPT_ACTION **)data + 23) != _XcptActTab )
      free(pMem: *((void **)data + 23));
    _lock(locknum: 13);
    v1 = *((threadmbcinfostruct **)data + 26);
    if ( v1 != nullptr && InterlockedDecrement(lpAddend: *((volatile LONG **)data + 26)) == 0 && v1 != &__initialmbcinfo )
      free(pMem: v1);
    _unlock(locknum: 13);
    _lock(locknum: 12);
    v2 = *((threadlocaleinfostruct **)data + 27);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: *((threadlocaleinfostruct **)data + 27));
      if ( v2 != __ptlocinfo && v2 != &__initiallocinfo && v2->refcount == 0 )
        __freetlocinfo(ptloci: v2);
    }
    savedregs = 5043723;
    _unlock(locknum: 12);
    free(pMem: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF632
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinit()
{
  HMODULE ModuleHandleA; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-Ch] [ebp-10h]
  _tiddata *v11; // [esp-8h] [ebp-Ch]

  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  v1 = ModuleHandleA;
  if ( ModuleHandleA == nullptr )
  {
    _mtterm();
    return 0;
  }
  gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))GetProcAddress(
                                                                         hModule: ModuleHandleA,
                                                                         lpProcName: "FlsAlloc");
  gpFlsGetValue = (void *(__stdcall *)(unsigned int))GetProcAddress(hModule: v1, lpProcName: "FlsGetValue");
  gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))GetProcAddress(hModule: v1, lpProcName: "FlsSetValue");
  FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(hModule: v1, lpProcName: "FlsFree");
  gpFlsFree = FlsFree;
  if ( gpFlsAlloc == nullptr || gpFlsGetValue == nullptr || gpFlsSetValue == nullptr || FlsFree == nullptr )
  {
    gpFlsGetValue = TlsGetValue;
    gpFlsAlloc = __crtTlsAlloc;
    gpFlsSetValue = TlsSetValue;
    gpFlsFree = TlsFree;
  }
  v4 = TlsAlloc();
  __getvalueindex = v4;
  if ( v4 != -1 && TlsSetValue(dwTlsIndex: v4, lpTlsValue: gpFlsGetValue) )
  {
    _init_pointers();
    gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))_encode_pointer(ptr: gpFlsAlloc);
    gpFlsGetValue = (void *(__stdcall *)(unsigned int))_encode_pointer(ptr: gpFlsGetValue);
    gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))_encode_pointer(ptr: gpFlsSetValue);
    gpFlsFree = (int (__stdcall *)(unsigned int))_encode_pointer(ptr: gpFlsFree);
    if ( _mtinitlocks() != 0 )
    {
      v5 = (int (__stdcall *)(_DWORD))_decode_pointer(codedptr: gpFlsAlloc);
      __flsindex = v5(a1: _freefls);
      if ( __flsindex != -1 )
      {
        v6 = (_tiddata *)calloc(count: 1u, size: 0x214u);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          v10 = __flsindex;
          v8 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(codedptr: gpFlsSetValue);
          if ( v8(a1: v10, a2: v11) != 0 )
          {
            _initptd(ptd: v7, ptloci: nullptr);
            CurrentThreadId = GetCurrentThreadId();
            v7->_thandle = -1;
            v7->_tid = CurrentThreadId;
            return 1;
          }
        }
      }
    }
    _mtterm();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CF7B6
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  unsigned int i; // edi
  int v2; // eax
  int v3; // eax
  HANDLE StdHandle; // eax
  void *v5; // ebp
  DWORD v6; // eax
  unsigned int NumberOfBytesWritten; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < 0x17; ++i )
  {
    if ( rterrnum == rterrs[i].rterrno )
      break;
  }
  if ( i < 0x17 )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v5 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        strlen(buf: (unsigned __int8 *)rterrs[i].rterrtxt);
        WriteFile(
          hFile: v5,
          lpBuffer: rterrs[i].rterrtxt,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &NumberOfBytesWritten,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( strcpy_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: "Runtime Error!\n\nProgram: ") != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      outmsg[285] = 0;
      if ( GetModuleFileNameA(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0
        && strcpy_s(_Dst: &outmsg[25], _SizeInBytes: 0x2FBu, _Src: "<program name unknown>") != 0 )
      {
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      strlen(buf: (unsigned __int8 *)&outmsg[25]);
      if ( (unsigned int)(v2 + 1) > 0x3C )
      {
        strlen(buf: (unsigned __int8 *)&outmsg[25]);
        if ( strncpy_s(
               _Dst: &outmsg[v3 - 34],
               _SizeInBytes: &unk_5EA68C - (_UNKNOWN *)&outmsg[v3 - 34],
               _Src: "...",
               _Count: 3u) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      if ( strcat_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: "\n\n") != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      if ( strcat_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: rterrs[i].rterrtxt) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      __crtMessageBoxA(lpText: outmsg, lpCaption: "Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF956
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF98F
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      *(&locktable + 2 * v0) = v1++;
      if ( __crtInitCritSecAndSpinCount(lpCriticalSection: *(&locktable + 2 * v0), dwSpinCount: 0xFA0u) == 0 )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CF9D8
// Name: __mtdeletelocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &locktable;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(lpCriticalSection: *v0);
      free(pMem: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)errtable );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)errtable );
}

//------------------------------------------------------------------------------
// Address: 0x004CFA2D
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x004CFA42
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  if ( *(&locktable + 2 * locknum) != nullptr )
    return 1;
  v2 = (_RTL_CRITICAL_SECTION *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v2 != nullptr )
  {
    _lock(locknum: 10);
    if ( *(&locktable + 2 * locknum) != nullptr )
    {
      free(pMem: v2);
    }
    else if ( __crtInitCritSecAndSpinCount(lpCriticalSection: v2, dwSpinCount: 0xFA0u) != 0 )
    {
      *(&locktable + 2 * locknum) = v2;
    }
    else
    {
      free(pMem: v2);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(locknum: 10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFB05
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  if ( *(&locktable + 2 * locknum) == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x004CFB36
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(
        void (__cdecl *enull)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x004CFB40
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(
        unsigned int a1@<eax>,
        unsigned int a2@<edx>,
        unsigned int a3@<ecx>,
        unsigned int a4@<ebx>,
        unsigned int a5@<edi>,
        unsigned int a6@<esi>)
{
  unsigned int v6; // kr00_4
  BOOL v7; // esi
  HANDLE CurrentProcess; // eax
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-80h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-30h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-28h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  ContextRecord.Eax = a1;
  ContextRecord.Ecx = a3;
  ContextRecord.Edx = a2;
  ContextRecord.Ebx = a4;
  ContextRecord.Esi = a6;
  ContextRecord.Edi = a5;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  ContextRecord.EFlags = v6;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  memset(dst: (int)&ExceptionRecord, value: nullptr, count: sizeof(ExceptionRecord));
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionRecord.ExceptionCode = -1073741811;
  ExceptionRecord.ExceptionAddress = retaddr;
  ExceptionPointers.ContextRecord = &ContextRecord;
  v7 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v7 )
    _crt_debugger_hook(_Reserved: 2);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC000000D);
}

//------------------------------------------------------------------------------
// Address: 0x004CFC3C
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int a3@<esi>)
{
  void (*v3)(void); // eax
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // [esp-4h] [ebp-4h]

  v3 = (void (*)(void))_decode_pointer(codedptr: __pInvalidArgHandler);
  if ( v3 == nullptr )
  {
    _crt_debugger_hook(_Reserved: 2);
    _invoke_watson(a1: v4, a2: v5, a3: v6, a4: a1, a5: a2, a6: a3);
  }
  v3();
}

//------------------------------------------------------------------------------
// Address: 0x004CFC60
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x004CFC9B
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x004CFCAE
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x004CFCC1
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x004CFCDF
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004CFD03
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Terminate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004CFD30
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  return *(_WORD *)pImageBase == 23117
      && *(_DWORD *)(v2 = &pImageBase[*((_DWORD *)pImageBase + 15)]) == 17744
      && *((_WORD *)v2 + 12) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x004CFD60
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( *((_WORD *)v2 + 3) == 0 )
    return nullptr;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CFDB0
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x400000)
      && (PESection = _FindPESection(pImageBase: (unsigned __int8 *)0x400000, rva: (unsigned int)(pTarget - 0x400000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CFEB1
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x004D0066
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_terminate;
  if ( v0 != nullptr )
    v0();
  abort();
}

//------------------------------------------------------------------------------
// Address: 0x004D009F
// Name: void unexpected(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn unexpected()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_unexpected;
  if ( v0 != nullptr )
    v0();
  terminate();
}

//------------------------------------------------------------------------------
// Address: 0x004D00B2
// Name: void _inconsistency(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _inconsistency()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_decode_pointer(codedptr: __pInconsistency);
  if ( v0 != nullptr )
    v0();
  terminate();
}

//------------------------------------------------------------------------------
// Address: 0x004D00E9
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_eh_hooks()
{
  __pInconsistency = (void (__cdecl *)())_encode_pointer(ptr: terminate);
}

//------------------------------------------------------------------------------
// Address: 0x004D00FA
// Name: __initp_misc_winxfltr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winxfltr()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004D00FB
// Name: __XcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _XcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  int result; // eax
  _DWORD *v3; // esi
  int *v4; // edx
  int *v5; // ecx
  int *v6; // eax
  void (__cdecl *v7)(int); // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  void *oldpxcptinfoptrs; // [esp+4h] [ebp-8h]

  result = (int)_getptd_noexit();
  v3 = (_DWORD *)result;
  if ( result != 0 )
  {
    v4 = *(int **)(result + 92);
    v5 = v4;
    do
    {
      if ( *v5 == xcptnum )
        break;
      v5 += 3;
    }
    while ( v5 < &v4[3 * _XcptActTabCount] );
    if ( v5 < &v4[3 * _XcptActTabCount] && *v5 == xcptnum )
      v6 = v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr && (v7 = (void (__cdecl *)(int))v6[2]) != nullptr )
    {
      if ( v7 == (void (__cdecl *)(int))5 )
      {
        v6[2] = 0;
        return 1;
      }
      else
      {
        if ( v7 != (void (__cdecl *)(int))1 )
        {
          oldpxcptinfoptrs = (void *)v3[24];
          v3[24] = pxcptinfoptrs;
          v8 = v6[1];
          if ( v8 == 8 )
          {
            v9 = _First_FPE_Indx;
            if ( _First_FPE_Indx < _First_FPE_Indx + _Num_FPE )
            {
              v10 = 12 * _First_FPE_Indx;
              do
              {
                *(_DWORD *)(v10 + v3[23] + 8) = 0;
                ++v9;
                v10 += 12;
              }
              while ( v9 < _First_FPE_Indx + _Num_FPE );
            }
            v11 = *v6;
            v12 = v3[25];
            switch ( v11 )
            {
              case -1073741682:
                v3[25] = 131;
                break;
              case -1073741680:
                v3[25] = 129;
                break;
              case -1073741679:
                v3[25] = 132;
                break;
              case -1073741677:
                v3[25] = 133;
                break;
              case -1073741683:
                v3[25] = 130;
                break;
              case -1073741681:
                v3[25] = 134;
                break;
              case -1073741678:
                v3[25] = 138;
                break;
              default:
                break;
            }
            v7(a1: 8);
            v3[25] = v12;
          }
          else
          {
            v6[2] = 0;
            v7(a1: v8);
          }
          v3[24] = oldpxcptinfoptrs;
        }
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D0259
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void (__cdecl *enull)(int))
{
  ctrlc_action = enull;
  ctrlbreak_action = enull;
  abort_action = enull;
  term_action = enull;
}

//------------------------------------------------------------------------------
// Address: 0x004D0272
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_XCPT_ACTION *__usercall siglookup@<eax>(int signum@<edx>, _XCPT_ACTION *pxcptacttab)
{
  _XCPT_ACTION *result; // eax

  result = pxcptacttab;
  do
  {
    if ( result->SigNum == signum )
      break;
    ++result;
  }
  while ( result < &pxcptacttab[_XcptActTabCount] );
  if ( result >= &pxcptacttab[_XcptActTabCount] || result->SigNum != signum )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D02A6
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl __get_sigabrt())(int)
{
  return (void (__cdecl *)(int))_decode_pointer(codedptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x004D02B3
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall raise@<eax>(unsigned int a1@<esi>, int signum)
{
  _tiddata *v2; // edi
  _tiddata *v3; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v6)(int); // eax
  void (__cdecl *v7)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v2 = nullptr;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v6 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v6 = ctrlbreak_action;
      goto LABEL_18;
    }
    if ( signum != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( signum != 11 )
  {
    if ( signum == 2 )
    {
      p_XcptAction = &ctrlc_action;
      v6 = ctrlc_action;
LABEL_18:
      siglock = 1;
      v7 = (void (__cdecl *)(int))_decode_pointer(codedptr: v6);
      goto LABEL_19;
    }
    if ( signum != 4 )
    {
      if ( signum != 6 )
      {
        if ( signum == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter(a1: signum, a2: 0, a3: a1);
        return -1;
      }
LABEL_15:
      p_XcptAction = &abort_action;
      v6 = abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v3 = _getptd_noexit();
  v2 = v3;
  if ( v3 == nullptr )
    return -1;
  p_XcptAction = &siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v3->_pxcptacttab)->XcptAction;
  v7 = *p_XcptAction;
LABEL_19:
  sigact = v7;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( sigact == nullptr )
    _exit(code: 3);
  if ( siglock != 0 )
    _lock(locknum: 0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v2->_tpxcptinfoptrs;
    v2->_tpxcptinfoptrs = nullptr;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v2->_tfpecode;
    v2->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = _First_FPE_Indx; indx < _First_FPE_Indx + _Num_FPE; ++indx )
      *((_DWORD *)v2->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37_2;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null();
$LN37_2:
  if ( siglock != 0 )
    _unlock(locknum: 0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(a1: 8, a2: v2->_tfpecode);
  else
    sigact(a1: signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v2->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v2->_tfpecode = oldfpecode;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D0463
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(int (__stdcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

//------------------------------------------------------------------------------
// Address: 0x004D046D
// Name: ___getlocaleinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __getlocaleinfo(
        localeinfo_struct *plocinfo,
        int lc_type,
        unsigned int localehandle,
        unsigned int fieldtype,
        _BYTE *address)
{
  unsigned __int8 *v5; // edi
  unsigned int LocaleInfoA; // esi
  unsigned int v7; // eax
  char *v8; // eax
  char *v9; // eax
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ecx
  wchar_t *v14; // edi
  char v15; // bl
  int buffersize; // [esp+10h] [ebp-2Ch]
  int bufferused; // [esp+18h] [ebp-24h]
  unsigned __int8 cbuffer[128]; // [esp+1Ch] [ebp-20h] BYREF

  if ( lc_type != 1 )
  {
    if ( lc_type != 0 )
      return -1;
    v14 = wcbuffer;
    if ( __crtGetLocaleInfoW(
           plocinfo,
           Locale: localehandle,
           LCType: fieldtype,
           lpLCData: wcbuffer,
           cchData: 4,
           code_page: 0) == 0 )
      return -1;
    *address = 0;
    do
    {
      v15 = *(_BYTE *)v14;
      if ( isdigit(c: *(unsigned __int8 *)v14) == 0 )
        break;
      ++v14;
      *address = v15 + 10 * *address - 48;
    }
    while ( (int)v14 < (int)&__pPurecall );
    return 0;
  }
  v5 = cbuffer;
  bufferused = 0;
  LocaleInfoA = __crtGetLocaleInfoA(
                  plocinfo,
                  Locale: localehandle,
                  LCType: fieldtype,
                  lpLCData: (char *)cbuffer,
                  cchData: 128,
                  code_page: 0);
  if ( LocaleInfoA == 0 )
  {
    if ( GetLastError() != 122 )
      return -1;
    v7 = __crtGetLocaleInfoA(
           plocinfo,
           Locale: localehandle,
           LCType: fieldtype,
           lpLCData: nullptr,
           cchData: 0,
           code_page: 0);
    buffersize = v7;
    if ( v7 == 0 )
      return -1;
    v8 = (char *)calloc(count: v7, size: 1u);
    v5 = (unsigned __int8 *)v8;
    if ( v8 == nullptr )
      return -1;
    bufferused = 1;
    LocaleInfoA = __crtGetLocaleInfoA(
                    plocinfo,
                    Locale: localehandle,
                    LCType: fieldtype,
                    lpLCData: v8,
                    cchData: buffersize,
                    code_page: 0);
    if ( LocaleInfoA == 0 )
      goto LABEL_9;
  }
  v9 = (char *)calloc(count: LocaleInfoA, size: 1u);
  *(_DWORD *)address = v9;
  if ( v9 != nullptr )
  {
    v11 = strncpy_s(_Dst: v9, _SizeInBytes: LocaleInfoA, _Src: (const char *)v5, _Count: LocaleInfoA - 1);
    if ( v11 != 0 )
      _invoke_watson(a1: v11, a2: v12, a3: v13, a4: 0, a5: (unsigned int)v5, a6: LocaleInfoA);
    if ( bufferused != 0 )
      free(pMem: v5);
    return 0;
  }
  if ( bufferused != 0 )
LABEL_9:
    free(pMem: v5);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D05C7
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void (__cdecl *enull)())
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x004D05D1
// Name: __initp_misc_initcrit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_initcrit(int (__stdcall *enull)(_RTL_CRITICAL_SECTION *, unsigned int))
{
  _pfnInitCritSecAndSpinCount = enull;
}

//------------------------------------------------------------------------------
// Address: 0x004D05DB
// Name: __crtInitCritSecNoSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _crtInitCritSecNoSpinCount(_RTL_CRITICAL_SECTION *lpCriticalSection, unsigned int dwSpinCount)
{
  InitializeCriticalSection(lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D05EB
// Name: ___crtInitCritSecAndSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall __crtInitCritSecAndSpinCount@<eax>(
        unsigned int a1@<ebx>,
        _RTL_CRITICAL_SECTION *lpCriticalSection,
        DWORD dwSpinCount)
{
  BOOL (__stdcall *InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION, DWORD); // esi
  unsigned int v4; // eax
  unsigned int v5; // edx
  HMODULE ModuleHandleA; // eax
  unsigned int v8; // [esp-4h] [ebp-38h]
  unsigned int osplatform; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  osplatform = 0;
  InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))_decode_pointer(codedptr: _pfnInitCritSecAndSpinCount);
  if ( InitializeCriticalSectionAndSpinCount == nullptr )
  {
    v4 = _get_osplatform(pValue: &osplatform);
    if ( v4 != 0 )
      _invoke_watson(a1: v4, a2: v5, a3: v8, a4: a1, a5: 0, a6: 0);
    if ( osplatform == 1
      || (ModuleHandleA = GetModuleHandleA(lpModuleName: aKernel32_0)) == nullptr
      || (InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))GetProcAddress(
                                                                                                   hModule: ModuleHandleA,
                                                                                                   lpProcName: "InitializeCriticalSec"
                                                                                                   "tionAndSpinCount")) == nullptr )
    {
      InitializeCriticalSectionAndSpinCount = _crtInitCritSecNoSpinCount;
    }
    _pfnInitCritSecAndSpinCount = (int (__stdcall *)(_RTL_CRITICAL_SECTION *, unsigned int))_encode_pointer(ptr: InitializeCriticalSectionAndSpinCount);
  }
  ms_exc.registration.TryLevel = 0;
  return InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}

//------------------------------------------------------------------------------
// Address: 0x004D06B0
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(int (__cdecl *enull)(unsigned int))
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x004D06BA
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  bool v5; // zf
  char *base; // eax
  char *ptr; // edi
  signed int v8; // edi
  ioinfo *v9; // eax
  __int64 v10; // rax
  int written; // [esp+4h] [ebp-4h]

  v2 = (_iobuf *)str;
  str = _fileno(stream: (_iobuf *)str);
  flag = v2->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v2->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v2->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v2->_flag = flag | 0x20;
      return -1;
    }
    v2->_ptr = v2->_base;
    v2->_flag = flag & 0xFFFFFFFE;
  }
  v5 = (v2->_flag & 0x10C) == 0;
  v2->_flag = v2->_flag & 0xFFFFFFED | 2;
  v2->_cnt = 0;
  written = 0;
  if ( v5 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
    _getbuf(str: v2);
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    ptr = v2->_ptr;
    v2->_ptr = base + 1;
    v8 = ptr - base;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v8 <= 0 )
    {
      if ( str == -1 || str == -2 )
        v9 = &__badioinfo;
      else
        v9 = &__pioinfo[str >> 5][str & 0x1F];
      if ( (v9->osfile & 0x20) != 0 )
      {
        v10 = _lseeki64(fh: str, pos: 0, mthd: 2);
        if ( (HIDWORD(v10) & (unsigned int)v10) == 0xFFFFFFFF )
          goto LABEL_27;
      }
    }
    else
    {
      written = _write(fh: str, buf: base, cnt: v8);
    }
    *v2->_base = ch;
  }
  else
  {
    v8 = 1;
    written = _write(fh: str, buf: &ch, cnt: 1u);
  }
  if ( written != v8 )
  {
LABEL_27:
    v2->_flag |= 0x20u;
    return -1;
  }
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x004D081A
// Name: write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>)
{
  bool v3; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr)
    && ((v3 = f->_cnt - 1 < 0, --f->_cnt, v3)
      ? (ch = _flsbuf(ch, str: (int)f))
      : (*f->_ptr = ch, ++f->_ptr, ch = (unsigned __int8)ch),
        ch == -1) )
  {
    *pnumwritten = -1;
  }
  else
  {
    ++*pnumwritten;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D084D
// Name: write_multi_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_multi_char(int *pnumwritten@<eax>, char ch, int num, _iobuf *f)
{
  int *v4; // esi

  v4 = pnumwritten;
  do
  {
    if ( num <= 0 )
      break;
    LOBYTE(pnumwritten) = ch;
    --num;
    write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
  }
  while ( *v4 != -1 );
}

//------------------------------------------------------------------------------
// Address: 0x004D0871
// Name: write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(char *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  int *v4; // esi
  int *v6; // eax

  v4 = pnumwritten;
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      LOBYTE(pnumwritten) = *string;
      --len;
      write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
      ++string;
      if ( *v4 == -1 )
      {
        v6 = _errno();
        if ( *v6 != 42 )
          return;
        LOBYTE(v6) = 63;
        write_char(ch: (int)v6, f, pnumwritten: v4);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D08BB
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  const char *v4; // ebx
  int *p_charsout; // esi
  int *v6; // edi
  _DWORD *v8; // esi
  ioinfo *v9; // eax
  _DWORD *v10; // esi
  ioinfo *v11; // eax
  char v12; // dl
  STATE v13; // ecx
  bool v14; // zf
  int v15; // eax
  char v16; // al
  int v17; // eax
  _output_l::__l2::<unnamed_tag> *p_buffer; // ebx
  int v19; // ecx
  char *v20; // edi
  char *v21; // eax
  char *v22; // edi
  __int16 *v23; // eax
  char *v24; // ecx
  int v25; // eax
  __int64 v26; // rax
  int *v27; // edi
  int v28; // esi
  char *v29; // eax
  int v30; // eax
  char *v31; // edi
  void (__cdecl *v32)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *); // eax
  int v33; // edi
  void (__cdecl *v34)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  void (__cdecl *v35)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  unsigned int v36; // ebx
  unsigned int v37; // edi
  char *j; // esi
  int v39; // eax
  unsigned __int64 v40; // rcx
  int v41; // ecx
  char *v42; // eax
  char *v43; // esi
  char *i; // eax
  int v45; // ebx
  _iobuf *v46; // edi
  char *v47; // esi
  wchar_t v48; // ax
  char v49; // al
  int v50; // [esp-14h] [ebp-A0h]
  int v51; // [esp-10h] [ebp-9Ch]
  unsigned __int64 v52; // [esp-10h] [ebp-9Ch]
  int v53; // [esp-Ch] [ebp-98h]
  int v54; // [esp-8h] [ebp-94h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-80h] BYREF
  int capexp; // [esp+14h] [ebp-78h]
  STATE state; // [esp+18h] [ebp-74h]
  int retval; // [esp+1Ch] [ebp-70h] BYREF
  int count; // [esp+24h] [ebp-68h]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-64h] BYREF
  char *heapbuf; // [esp+38h] [ebp-54h]
  int no_output; // [esp+3Ch] [ebp-50h]
  int hexadd; // [esp+40h] [ebp-4Ch]
  char *v64; // [esp+44h] [ebp-48h]
  int bufferiswide; // [esp+48h] [ebp-44h]
  int fldwidth; // [esp+4Ch] [ebp-40h]
  int prefixlen; // [esp+50h] [ebp-3Ch]
  char prefix[4]; // [esp+54h] [ebp-38h] BYREF
  int charsout; // [esp+58h] [ebp-34h] BYREF
  _iobuf *f; // [esp+5Ch] [ebp-30h]
  char *v71; // [esp+60h] [ebp-2Ch]
  int radix; // [esp+64h] [ebp-28h] BYREF
  char *string; // [esp+68h] [ebp-24h]
  int precision; // [esp+6Ch] [ebp-20h]
  char v75; // [esp+73h] [ebp-19h]
  int flags; // [esp+74h] [ebp-18h]
  _output_l::__l2::<unnamed_tag> buffer; // [esp+78h] [ebp-14h] BYREF
  char L_buffer[8]; // [esp+278h] [ebp+1ECh] BYREF

  v4 = format;
  p_charsout = nullptr;
  v6 = (int *)argptr;
  f = stream;
  v71 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( f == nullptr
    || (f->_flag & 0x40) == 0
    && (_fileno(stream: f) == -1 || _fileno(stream: f) == -2
      ? (v9 = &__badioinfo)
      : (ioinfo *)(v8 = (_DWORD *)(4 * (_fileno(stream: f) >> 5) + 6326944),
                   v9 = (ioinfo *)(*v8 + 56 * (_fileno(stream: f) & 0x1F)),
                   p_charsout = nullptr),
        (*((_BYTE *)v9 + 36) & 0x7F) != 0
     || (_fileno(stream: f) == -1 || _fileno(stream: f) == -2
       ? (v11 = &__badioinfo)
       : (ioinfo *)(v10 = (_DWORD *)(4 * (_fileno(stream: f) >> 5) + 6326944),
                    v11 = (ioinfo *)(*v10 + 56 * (_fileno(stream: f) & 0x1F)),
                    p_charsout = nullptr),
         *((char *)v11 + 36) < 0))
    || format == nullptr )
  {
    *_errno() = 22;
    goto LABEL_3;
  }
  v12 = *format;
  v13 = ST_NORMAL;
  v14 = *format == 0;
  charsout = 0;
  radix = 0;
  heapbuf = nullptr;
  v75 = v12;
  if ( v14 )
  {
LABEL_222:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 1 )
  {
    v64 = (char *)++v4;
    if ( charsout < 0 )
      goto LABEL_222;
    if ( (unsigned __int8)(v12 - 32) > 0x58u )
      v15 = 0;
    else
      v15 = byte_59EFE8[v12] & 0xF;
    state = __lookuptable[8 * v15 + v13] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_219;
      case ST_FLAG:
        switch ( v12 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_219;
      case ST_WIDTH:
        if ( v12 == 42 )
        {
          v71 = (char *)(v6 + 1);
          fldwidth = *v6;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + v12 - 48;
        }
        goto LABEL_219;
      case ST_DOT:
        precision = 0;
        goto LABEL_219;
      case ST_PRECIS:
        if ( v12 == 42 )
        {
          v71 = (char *)(v6 + 1);
          precision = *v6;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + v12 - 48;
        }
        goto LABEL_219;
      case ST_SIZE:
        if ( v12 != 73 )
        {
          switch ( v12 )
          {
            case 'h':
              flags |= 0x20u;
              break;
            case 'l':
              if ( *v4 == 108 )
              {
                flags |= 0x1000u;
                v64 = (char *)(v4 + 1);
              }
              else
              {
                flags |= 0x10u;
              }
              break;
            case 'w':
              flags |= 0x800u;
              break;
            default:
              break;
          }
          goto LABEL_219;
        }
        v16 = *v4;
        if ( *v4 == 54 && v4[1] == 52 )
        {
          flags |= 0x8000u;
          v64 = (char *)(v4 + 2);
          goto LABEL_219;
        }
        if ( v16 == 51 && v4[1] == 50 )
        {
          flags &= ~0x8000u;
          v64 = (char *)(v4 + 2);
          goto LABEL_219;
        }
        if ( v16 == 100 || v16 == 105 || v16 == 111 || v16 == 117 || v16 == 120 || v16 == 88 )
          goto LABEL_219;
        state = ST_NORMAL;
NORMAL_STATE:
        bufferiswide = 0;
        v17 = _isleadbyte_l(c: v12, plocinfo: &_loc_update.localeinfo);
        v14 = v17 == 0;
        LOBYTE(v17) = v75;
        if ( v14
          || (p_charsout = &charsout,
              write_char(ch: v17, f, pnumwritten: &charsout),
              LOBYTE(v17) = *v4,
              ++v4,
              v64 = (char *)v4,
              (_BYTE)v17 != 0) )
        {
          write_char(ch: v17, f, pnumwritten: &charsout);
          goto LABEL_219;
        }
LABEL_221:
        *_errno() = 22;
LABEL_3:
        _invalid_parameter(a1: (unsigned int)v4, a2: (unsigned int)v6, a3: (unsigned int)p_charsout);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      case ST_TYPE:
        if ( v12 <= 100 )
        {
          if ( v12 == 100 )
          {
LABEL_119:
            flags |= 0x40u;
            goto LABEL_120;
          }
          if ( v12 > 83 )
          {
            if ( v12 == 88 )
              goto LABEL_141;
            if ( v12 == 90 )
            {
              v23 = (__int16 *)*v6;
              v71 = (char *)(v6 + 1);
              if ( v23 != nullptr && (v24 = *((char **)v23 + 1)) != nullptr )
              {
                v25 = *v23;
                string = v24;
                if ( (flags & 0x800) != 0 )
                {
                  v25 /= 2;
                  bufferiswide = 1;
                }
                else
                {
                  bufferiswide = 0;
                }
              }
              else
              {
                string = __nullstring;
                strlen(buf: (unsigned __int8 *)__nullstring);
              }
              goto LABEL_190;
            }
            if ( v12 != 97 )
            {
              if ( v12 != 99 )
                goto LABEL_191;
              goto LABEL_94;
            }
          }
          else
          {
            if ( v12 == 83 )
            {
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
              goto LABEL_84;
            }
            if ( v12 != 65 )
            {
              if ( v12 != 67 )
              {
                if ( v12 != 69 && v12 != 71 )
                  goto LABEL_191;
                goto LABEL_77;
              }
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
LABEL_94:
              v22 = (char *)(v6 + 1);
              v71 = v22;
              if ( (flags & 0x810) != 0 )
              {
                if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v22 - 2)) != 0 )
                  no_output = 1;
              }
              else
              {
                buffer.sz[0] = *(v22 - 4);
                radix = 1;
              }
              string = (char *)&buffer;
              goto LABEL_191;
            }
LABEL_77:
            v12 += 32;
            capexp = 1;
            v75 = v12;
          }
LABEL_78:
          flags |= 0x40u;
          p_buffer = &buffer;
          string = (char *)&buffer;
          count = 512;
          if ( precision >= 0 )
          {
            if ( precision != 0 )
            {
              if ( precision > 512 )
                precision = 512;
              if ( precision > 163 )
              {
                v28 = precision + 349;
                v29 = (char *)MemAlloc_Alloc(nSize: precision + 349);
                v12 = v75;
                heapbuf = v29;
                if ( v29 != nullptr )
                {
                  string = v29;
                  count = v28;
                  p_buffer = (_output_l::__l2::<unnamed_tag> *)v29;
                }
                else
                {
                  precision = 163;
                }
              }
            }
            else
            {
              precision = v12 == 103;
            }
          }
          else
          {
            precision = 6;
          }
          v30 = *v6;
          v31 = (char *)(v6 + 2);
          LODWORD(tmp.x) = v30;
          HIDWORD(tmp.x) = *((_DWORD *)v31 - 1);
          v54 = capexp;
          v53 = precision;
          v71 = v31;
          v51 = v12;
          v50 = count;
          v32 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr: codedptr);
          v32(a1: &tmp, a2: p_buffer, a3: v50, a4: v51, a5: v53, a6: v54, a7: &_loc_update);
          v33 = flags & 0x80;
          if ( (flags & 0x80) != 0 && precision == 0 )
          {
            v34 = (void (__cdecl *)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(codedptr: off_5C03C4);
            v34(a1: p_buffer, a2: &_loc_update);
          }
          if ( v75 == 103 && v33 == 0 )
          {
            v35 = (void (__cdecl *)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(codedptr: off_5C03C0);
            v35(a1: p_buffer, a2: &_loc_update);
          }
          if ( p_buffer->sz[0] == 45 )
          {
            flags |= 0x100u;
            p_buffer = (_output_l::__l2::<unnamed_tag> *)((char *)p_buffer + 1);
            string = (char *)p_buffer;
          }
          strlen(buf: (unsigned __int8 *)p_buffer);
          goto LABEL_190;
        }
        if ( v12 > 112 )
        {
          if ( v12 != 115 )
          {
            if ( v12 != 117 )
            {
              if ( v12 != 120 )
                goto LABEL_191;
              hexadd = 39;
              goto COMMON_HEX;
            }
LABEL_120:
            radix = 10;
            goto COMMON_INT;
          }
LABEL_84:
          v19 = precision;
          if ( precision == -1 )
            v19 = 0x7FFFFFFF;
          v71 = (char *)(v6 + 1);
          v20 = (char *)*v6;
          string = v20;
          if ( (flags & 0x810) != 0 )
          {
            if ( v20 == nullptr )
              string = (char *)__wnullstring;
            v21 = string;
            bufferiswide = 1;
            while ( v19 != 0 )
            {
              --v19;
              if ( *(_WORD *)v21 == 0 )
                break;
              v21 += 2;
            }
            v25 = (v21 - string) >> 1;
          }
          else
          {
            if ( v20 == nullptr )
              string = __nullstring;
            for ( i = string; v19 != 0; ++i )
            {
              --v19;
              if ( *i == 0 )
                break;
            }
            v25 = i - string;
          }
LABEL_190:
          radix = v25;
          goto LABEL_191;
        }
        if ( v12 == 112 )
        {
          precision = 8;
LABEL_141:
          hexadd = 7;
COMMON_HEX:
          radix = 16;
          if ( (flags & 0x80u) != 0 )
          {
            prefix[0] = 48;
            prefix[1] = hexadd + 81;
            prefixlen = 2;
          }
          goto COMMON_INT;
        }
        if ( v12 < 101 )
          goto LABEL_191;
        if ( v12 <= 103 )
          goto LABEL_78;
        if ( v12 == 105 )
          goto LABEL_119;
        if ( v12 != 110 )
        {
          if ( v12 != 111 )
            goto LABEL_191;
          radix = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
COMMON_INT:
          if ( (flags & 0x8000u) != 0 || (flags & 0x1000) != 0 )
          {
            v26 = *(_QWORD *)v6;
            v27 = v6 + 2;
          }
          else
          {
            v27 = v6 + 1;
            if ( (flags & 0x20) != 0 )
            {
              v71 = (char *)v27;
              if ( (flags & 0x40) != 0 )
                LODWORD(v26) = *((__int16 *)v27 - 2);
              else
                LODWORD(v26) = *((unsigned __int16 *)v27 - 2);
              v26 = (int)v26;
LABEL_158:
              if ( (flags & 0x40) != 0 && v26 < 0 )
              {
                v26 = -v26;
                flags |= 0x100u;
              }
              v36 = HIDWORD(v26);
              v37 = v26;
              if ( (flags & 0x9000) == 0 )
                v36 = 0;
              if ( precision >= 0 )
              {
                flags &= ~8u;
                if ( precision > 512 )
                  precision = 512;
              }
              else
              {
                precision = 1;
              }
              if ( (v36 | (unsigned int)v26) == 0 )
                prefixlen = 0;
              for ( j = &buffer.sz[511]; ; --j )
              {
                v39 = precision--;
                if ( v39 <= 0 && (v36 | v37) == 0 )
                  break;
                v52 = __PAIR64__(v36, v37);
                v40 = __PAIR64__(v36, v37) % radix;
                v41 = v40 + 48;
                count = HIDWORD(v40);
                v36 = (v52 / radix) >> 32;
                v37 = v52 / radix;
                if ( v41 > 57 )
                  LOBYTE(v41) = hexadd + v41;
                *j = v41;
              }
              v42 = (char *)(&buffer.sz[511] - j);
              v43 = j + 1;
              radix = (int)v42;
              string = v43;
              if ( (flags & 0x200) != 0 && (v42 == nullptr || *v43 != 48) )
              {
                *--string = 48;
                v25 = (int)(v42 + 1);
                goto LABEL_190;
              }
LABEL_191:
              if ( no_output != 0 )
                goto LABEL_217;
              if ( (flags & 0x40) != 0 )
              {
                if ( (flags & 0x100) != 0 )
                {
                  prefix[0] = 45;
                  goto LABEL_199;
                }
                if ( (flags & 1) != 0 )
                {
                  prefix[0] = 43;
                  goto LABEL_199;
                }
                if ( (flags & 2) != 0 )
                {
                  prefix[0] = 32;
LABEL_199:
                  prefixlen = 1;
                }
              }
              v45 = fldwidth - radix - prefixlen;
              if ( (flags & 0xC) == 0 )
                write_multi_char(pnumwritten: &charsout, ch: 32, num: fldwidth - radix - prefixlen, f);
              v46 = f;
              write_string(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
              if ( (flags & 8) != 0 && (flags & 4) == 0 )
                write_multi_char(pnumwritten: &charsout, ch: 48, num: v45, f: v46);
              if ( bufferiswide != 0 && radix > 0 )
              {
                v47 = string;
                count = radix;
                while ( 1 )
                {
                  v48 = *(_WORD *)v47;
                  --count;
                  v47 += 2;
                  if ( wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v48) != 0 || retval == 0 )
                    break;
                  write_string(string: L_buffer, f: v46, pnumwritten: &charsout, len: retval);
                  if ( count == 0 )
                    goto LABEL_214;
                }
                charsout = -1;
              }
              else
              {
                write_string(string, f: v46, pnumwritten: &charsout, len: radix);
              }
LABEL_214:
              if ( charsout >= 0 && (flags & 4) != 0 )
                write_multi_char(pnumwritten: &charsout, ch: 32, num: v45, f: v46);
              goto LABEL_217;
            }
            LODWORD(v26) = *(v27 - 1);
            if ( (flags & 0x40) != 0 )
              v26 = (int)v26;
            else
              HIDWORD(v26) = 0;
          }
          v71 = (char *)v27;
          goto LABEL_158;
        }
        p_charsout = (int *)*v6++;
        v71 = (char *)v6;
        if ( !_get_printf_count_output() )
          goto LABEL_221;
        if ( (flags & 0x20) != 0 )
          *(_WORD *)p_charsout = charsout;
        else
          *p_charsout = charsout;
        no_output = 1;
LABEL_217:
        if ( heapbuf != nullptr )
        {
          free(pMem: heapbuf);
          heapbuf = nullptr;
        }
LABEL_219:
        v4 = v64;
        v49 = *v64;
        v75 = *v64;
        if ( v75 == 0 )
          goto LABEL_222;
        v13 = state;
        v6 = (int *)v71;
        v12 = v49;
        break;
      default:
        goto LABEL_219;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D124F
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CPtoLCID@<eax>(int codepage@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  v1 = codepage - 932;
  if ( v1 == 0 )
    return 1041;
  v2 = v1 - 4;
  if ( v2 == 0 )
    return 2052;
  v3 = v2 - 13;
  if ( v3 == 0 )
    return 1042;
  if ( v3 == 1 )
    return 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D127E
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  int v1; // ebp
  unsigned __int8 *mbctype; // ebx
  int v4; // eax
  unsigned __int8 *mbcasemap; // ecx
  int i; // esi

  v1 = 257;
  mbctype = ptmbci->mbctype;
  memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  v4 = (char *)&__initialmbcinfo - (char *)ptmbci;
  do
  {
    *mbctype = mbctype[v4];
    ++mbctype;
    --v1;
  }
  while ( v1 != 0 );
  mbcasemap = ptmbci->mbcasemap;
  for ( i = 256; i != 0; --i )
  {
    *mbcasemap = mbcasemap[v4];
    ++mbcasemap;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D12D3
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBUpLow(threadmbcinfostruct *ptmbci@<esi>)
{
  unsigned int i; // eax
  unsigned __int8 v2; // al
  unsigned __int8 *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned __int8 *v6; // ebx
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int8 v9; // cl
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // dl
  int v13; // [esp+8h] [ebp-80h]
  _cpinfo cpinfo; // [esp+Ch] [ebp-7Ch] BYREF
  unsigned __int16 wVector[256]; // [esp+20h] [ebp-68h] BYREF
  unsigned __int8 upVector[256]; // [esp+220h] [ebp+198h] BYREF
  unsigned __int8 lowVector[256]; // [esp+320h] [ebp+298h] BYREF
  unsigned __int8 sbVector[256]; // [esp+420h] [ebp+398h] BYREF

  if ( GetCPInfo(CodePage: ptmbci->mbcodepage, lpCPInfo: &cpinfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      sbVector[i] = i;
    v2 = cpinfo.LeadByte[0];
    sbVector[0] = 32;
    if ( cpinfo.LeadByte[0] != 0 )
    {
      v3 = &cpinfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset(dst: (int)&sbVector[v4], value: (unsigned __int8 *)0x20, count: v5 - v4 + 1);
        v6 = v3 + 1;
        v2 = *v6;
        v3 = v6 + 1;
      }
      while ( v2 != 0 );
    }
    __crtGetStringTypeA(
      plocinfo: nullptr,
      dwInfoType: 1u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpCharType: wVector,
      code_page: ptmbci->mbcodepage,
      lcid: ptmbci->mblcid,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x100u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)lowVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x200u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)upVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    v7 = 0;
    while ( 1 )
    {
      v8 = wVector[v7];
      if ( (v8 & 1) != 0 )
      {
        ptmbci->mbctype[v7 + 1] |= 0x10u;
        v9 = lowVector[v7];
      }
      else
      {
        if ( (v8 & 2) == 0 )
        {
          ptmbci->mbcasemap[v7] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v7 + 1] |= 0x20u;
        v9 = upVector[v7];
      }
      ptmbci->mbcasemap[v7] = v9;
LABEL_16:
      if ( (unsigned int)++v7 >= 0x100 )
        return;
    }
  }
  v10 = 0;
  v13 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v11 = &ptmbci->mbcasemap[v10];
    if ( (unsigned int)&v11[v13 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x10u;
      v12 = v10 + 32;
LABEL_23:
      *v11 = v12;
      goto LABEL_25;
    }
    if ( (unsigned int)&v11[v13] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x20u;
      v12 = v10 - 32;
      goto LABEL_23;
    }
    *v11 = 0;
LABEL_25:
    ++v10;
  }
  while ( v10 < 0x100 );
}

//------------------------------------------------------------------------------
// Address: 0x004D145D
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadmbcinfostruct *__cdecl __updatetmbcinfo()
{
  _tiddata *v0; // edi
  threadmbcinfostruct *ptmbcinfo; // esi

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    _lock(locknum: 13);
    ptmbcinfo = v0->ptmbcinfo;
    if ( ptmbcinfo != __ptmbcinfo )
    {
      if ( ptmbcinfo != nullptr
        && InterlockedDecrement(lpAddend: &ptmbcinfo->refcount) == 0
        && ptmbcinfo != &__initialmbcinfo )
      {
        free(pMem: ptmbcinfo);
      }
      v0->ptmbcinfo = __ptmbcinfo;
      ptmbcinfo = __ptmbcinfo;
      InterlockedIncrement(lpAddend: &__ptmbcinfo->refcount);
    }
    _unlock(locknum: 13);
  }
  if ( ptmbcinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptmbcinfo;
}

//------------------------------------------------------------------------------
// Address: 0x004D1501
// Name: getSystemCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __usercall getSystemCP@<eax>(int codepage@<esi>)
{
  UINT result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: nullptr);
  fSystemSet = 0;
  switch ( codepage )
  {
    case -2:
      fSystemSet = 1;
      result = GetOEMCP();
      goto LABEL_3;
    case -3:
      fSystemSet = 1;
      result = GetACP();
      goto LABEL_3;
    case -4:
      result = _loc_update.localeinfo.locinfo->lc_codepage;
      fSystemSet = 1;
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    default:
      break;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return codepage;
}

//------------------------------------------------------------------------------
// Address: 0x004D157B
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  bool v5; // cc
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // cl
  unsigned int k; // eax
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned __int16 *mbulinfo; // eax
  int v13; // ecx
  unsigned __int16 *v14; // ecx
  int j; // edx
  unsigned __int8 *v16; // eax
  int m; // ecx
  int v18; // edx
  unsigned int irg; // [esp+Ch] [ebp-20h]
  unsigned int icp; // [esp+10h] [ebp-1Ch]
  unsigned int icpa; // [esp+10h] [ebp-1Ch]
  _cpinfo cpinfo; // [esp+14h] [ebp-18h] BYREF
  int codepagea; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(codepage);
  codepagea = SystemCP;
  if ( SystemCP != 0 )
  {
    icp = 0;
    for ( i = 0; i < 5; ++i )
    {
      if ( _rgcode_page_info[i].code_page == SystemCP )
      {
        memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
        irg = 0;
        v9 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v9;
        do
        {
          while ( *v9 != 0 )
          {
            LOBYTE(v10) = v9[1];
            if ( (_BYTE)v10 == 0 )
              break;
            v11 = *v9;
            v10 = (unsigned __int8)v10;
            while ( v11 <= v10 )
            {
              ptmbci->mbctype[v11 + 1] |= _rgctypeflag[irg];
              v10 = v9[1];
              ++v11;
            }
            SystemCP = codepagea;
            v9 += 2;
          }
          ++irg;
          v9 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(codepage: SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v14 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v13);
        for ( j = 6; j != 0; --j )
          *mbulinfo++ = *v14++;
LABEL_26:
        setSBUpLow(ptmbci);
        return 0;
      }
      ++icp;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage(CodePage: (unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(CodePage: SystemCP, lpCPInfo: &cpinfo) )
    {
      memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
      v5 = cpinfo.MaxCharSize <= 1;
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( v5 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] != 0 )
        {
          v6 = &cpinfo.LeadByte[1];
          do
          {
            v7 = *v6;
            if ( *v6 == 0 )
              break;
            for ( k = *(v6 - 1); k <= v7; ++k )
              ptmbci->mbctype[k + 1] |= 4u;
            v6 += 2;
          }
          while ( *(v6 - 1) != 0 );
        }
        v16 = &ptmbci->mbctype[2];
        for ( m = 254; m != 0; --m )
          *v16++ |= 8u;
        ptmbci->mblcid = CPtoLCID(codepage: ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v18;
      }
      *(_DWORD *)ptmbci->mbulinfo = 0;
      *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
      *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
      goto LABEL_26;
    }
    if ( fSystemSet == 0 )
      return -1;
  }
  setSBCS(ptmbci);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D1754
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp(int codepage)
{
  _tiddata *v1; // edi
  threadmbcinfostruct *ptmbcinfo; // ebx
  threadmbcinfostruct *v3; // eax
  threadmbcinfostruct *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int retcode; // [esp+14h] [ebp-20h]
  UINT codepagea; // [esp+3Ch] [ebp+8h]

  retcode = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  ptmbcinfo = v1->ptmbcinfo;
  codepagea = getSystemCP(codepage);
  if ( codepagea == ptmbcinfo->mbcodepage )
    return 0;
  v3 = (threadmbcinfostruct *)MemAlloc_Alloc(nSize: 0x220u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    qmemcpy(v3, v1->ptmbcinfo, sizeof(threadmbcinfostruct));
    v3->refcount = 0;
    v5 = _setmbcp_nolock(codepage: codepagea, ptmbci: v3);
    retcode = v5;
    if ( v5 != 0 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != &__initialmbcinfo )
          free(pMem: v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( InterlockedDecrement(lpAddend: &v1->ptmbcinfo->refcount) == 0 && v1->ptmbcinfo != &__initialmbcinfo )
        free(pMem: v1->ptmbcinfo);
      v1->ptmbcinfo = v4;
      InterlockedIncrement(lpAddend: &v4->refcount);
      if ( (v1->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
      {
        _lock(locknum: 13);
        __mbcodepage = v4->mbcodepage;
        __ismbcodepage = v4->ismbcodepage;
        __mblcid = v4->mblcid;
        for ( i = 0; i < 5; ++i )
          __mbulinfo[i] = v4->mbulinfo[i];
        for ( j = 0; j < 257; ++j )
          _mbctype[j] = v4->mbctype[j];
        for ( k = 0; k < 256; ++k )
          _mbcasemap[k] = v4->mbcasemap[k];
        if ( InterlockedDecrement(lpAddend: &__ptmbcinfo->refcount) == 0 && __ptmbcinfo != &__initialmbcinfo )
          free(pMem: __ptmbcinfo);
        __ptmbcinfo = v4;
        InterlockedIncrement(lpAddend: &v4->refcount);
        _unlock(locknum: 13);
      }
    }
  }
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x004D18EE
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initmbctable()
{
  if ( __mbctype_initialized == 0 )
  {
    _setmbcp(codepage: -3);
    __mbctype_initialized = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D190C
// Name: __fltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _fltin2(
        _flt *flt,
        const char *str,
        int len_ignore,
        int scale_ignore,
        int radix_ignore,
        localeinfo_struct *_Locale)
{
  int v6; // ebx
  INTRNCVT_STATUS v7; // eax
  const char *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const char *v10; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v10 = str;
  v6 = 0;
  flags = __strgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v6 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v7 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v7 == INTRNCVT_OVERFLOW )
      v6 = 128;
    if ( (flags & 1) != 0 || v7 == INTRNCVT_UNDERFLOW )
      v6 |= 0x100u;
  }
  flt->nbytes = EndPtr - v10;
  flt->dval = x.x;
  flt->flags = v6;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x004D19C0
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_2;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_2:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1A4B
// Name: __isctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_l(int c, int mask, localeinfo_struct *plocinfo)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char buffer[4]; // [esp+14h] [ebp-8h] BYREF
  unsigned __int16 chartype; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = c;
  if ( (unsigned int)(c + 1) <= 0x100 )
  {
    v4 = _loc_update.localeinfo.locinfo->pctype[c];
    goto LABEL_11;
  }
  ca = c >> 8;
  if ( _isleadbyte_l(c: HIBYTE(v3), plocinfo: &_loc_update.localeinfo) != 0 )
  {
    buffer[0] = ca;
    buffer[1] = v3;
    buffer[2] = 0;
    v5 = 2;
  }
  else
  {
    buffer[0] = v3;
    buffer[1] = 0;
    v5 = 1;
  }
  if ( __crtGetStringTypeA(
         plocinfo: &_loc_update.localeinfo,
         dwInfoType: 1u,
         lpSrcStr: buffer,
         cchSrc: v5,
         lpCharType: &chartype,
         code_page: _loc_update.localeinfo.locinfo->lc_codepage,
         lcid: _loc_update.localeinfo.locinfo->lc_handle[2],
         bError: 1) != 0 )
  {
    v4 = chartype;
LABEL_11:
    result = mask & v4;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D1B01
// Name: ___strgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __strgtold12_l(
        _LDBL12 *pld12,
        const char **p_end_ptr,
        const char *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  char *v9; // edi
  const char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  const char *v16; // edx
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  _LDBL12 *v24; // esi
  char v25; // al
  int v26; // eax
  _LDBL12 *v27; // eax
  _LDBL12 *v28; // ebx
  __int16 v29; // dx
  __int16 v30; // ax
  unsigned __int16 v31; // dx
  __int16 v32; // ax
  unsigned __int16 v33; // di
  int v34; // eax
  _WORD *v35; // esi
  unsigned int v36; // ecx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  __int16 v39; // di
  unsigned int v40; // ecx
  int v41; // esi
  int v42; // ecx
  int v43; // esi
  unsigned int v44; // ecx
  int v45; // ebx
  int v46; // ecx
  __int16 v47; // cx
  int v48; // esi
  unsigned int v49; // edx
  __int16 v50; // ax
  int v51; // [esp-4h] [ebp-8Ch]
  int v52; // [esp-4h] [ebp-8Ch]
  int v53; // [esp+10h] [ebp-78h]
  __int16 man_sign; // [esp+14h] [ebp-74h]
  _LDBL12 *v55; // [esp+18h] [ebp-70h]
  unsigned int result_flags; // [esp+1Ch] [ebp-6Ch]
  int exp_sign; // [esp+20h] [ebp-68h]
  int exp_signa; // [esp+20h] [ebp-68h]
  int pow; // [esp+24h] [ebp-64h]
  int powa; // [esp+24h] [ebp-64h]
  int found_exponent; // [esp+28h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+28h] [ebp-60h]
  int found_decpoint; // [esp+2Ch] [ebp-5Ch]
  unsigned __int8 *found_decpointa; // [esp+2Ch] [ebp-5Ch]
  int found_digit; // [esp+30h] [ebp-58h]
  int found_digita; // [esp+30h] [ebp-58h]
  const char *savedp; // [esp+34h] [ebp-54h]
  int savedpa; // [esp+34h] [ebp-54h]
  int exp_adj; // [esp+38h] [ebp-50h]
  int exp_adja; // [esp+38h] [ebp-50h]
  unsigned int manlen; // [esp+3Ch] [ebp-4Ch]
  unsigned int manlena; // [esp+3Ch] [ebp-4Ch]
  __int64 v73; // [esp+40h] [ebp-48h] BYREF
  int v74; // [esp+48h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+4Ch] [ebp-3Ch] BYREF
  _BYTE v76[12]; // [esp+5Ch] [ebp-2Ch] BYREF
  char buf[28]; // [esp+68h] [ebp-20h] BYREF

  v8 = 0;
  v9 = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)buf, a3: 1u);
    return 0;
  }
  v11 = str;
  savedp = str;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( v14 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( v15 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_75;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_33;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (v13 <= 99 || v13 > 101) )
          goto LABEL_75;
        v52 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v51 = 3;
LABEL_12:
          v8 = v51;
          --v11;
        }
        else
        {
          if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v52 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_37:
            v16 = savedp;
            goto LABEL_82;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            ++manlen;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_46;
LABEL_24:
        v52 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( v13 == 48 )
          {
            --exp_adj;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            *v9++ = v13 - 48;
            --exp_adj;
          }
          v13 = *v11++;
        }
LABEL_46:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_33:
        --v11;
        v52 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_37;
        v51 = 4;
        goto LABEL_12;
      case 6:
        savedp = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v17 = v13 - 43;
        if ( v17 == 0 )
          goto LABEL_70;
        v18 = v17 - 2;
        if ( v18 == 0 )
          goto LABEL_69;
        v19 = v18 == 3;
LABEL_67:
        if ( !v19 )
          goto LABEL_37;
        v52 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v19 = v13 == 48;
        goto LABEL_67;
      case 8:
        found_exponent = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_75;
LABEL_63:
        v51 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v21 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v21 = 10 * v21 + v13 - 48;
            if ( v21 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v21 = 5201;
          }
          break;
        }
        pow = v21;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_75:
        v16 = v11 - 1;
        goto LABEL_82;
      case 11:
        if ( implicit_E != 0 )
        {
          v20 = v13 - 43;
          savedp = v11 - 1;
          if ( v20 != 0 )
          {
            if ( v20 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_82;
            }
LABEL_69:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_70:
            v52 = 7;
LABEL_15:
            v8 = v52;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_82:
        *p_end_ptr = v16;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_174:
          v47 = 0;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_175;
        }
        if ( manlen > 0x18 )
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          --v9;
          ++exp_adj;
          manlen = 24;
        }
        if ( manlen == 0 )
          goto LABEL_174;
        while ( *--v9 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v22 = pow;
        if ( exp_sign < 0 )
          v22 = -pow;
        v23 = exp_adj + v22;
        if ( found_exponent == 0 )
          v23 += scale;
        if ( found_decpoint == 0 )
          v23 -= decpt;
        if ( v23 > 5200 )
        {
          v48 = 0;
          v50 = 0x7FFF;
          v49 = 0x80000000;
          v47 = 0;
          result_flags = 2;
          goto LABEL_175;
        }
        if ( v23 < -5200 )
        {
          result_flags = 1;
          goto LABEL_174;
        }
        v24 = &_pow10pos[-8];
        savedpa = v23;
        if ( v23 != 0 )
        {
          if ( v23 < 0 )
          {
            savedpa = -v23;
            v24 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          while ( savedpa != 0 )
          {
            v25 = savedpa;
            savedpa >>= 3;
            v24 += 7;
            v26 = v25 & 7;
            manlena = (unsigned int)v24;
            if ( v26 != 0 )
            {
              v27 = &v24[v26];
              v28 = v27;
              v55 = v27;
              if ( *(_WORD *)v27->ld12 >= 0x8000u )
              {
                v73 = *(_QWORD *)v27->ld12;
                v74 = *(_DWORD *)&v27->ld12[8];
                --*(_DWORD *)((char *)&v73 + 2);
                v28 = (_LDBL12 *)&v73;
                v55 = (_LDBL12 *)&v73;
              }
              v29 = *(_WORD *)&v28->ld12[10];
              exp_adja = 0;
              memset(v76, 0, sizeof(v76));
              v30 = *(_WORD *)&tmpld12.ld12[10] ^ v29;
              v31 = v29 & 0x7FFF;
              v32 = v30 & 0x8000;
              v33 = v31 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF || v31 >= 0x7FFFu || v33 > 0xBFFDu )
              {
LABEL_167:
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                v34 = v32 != 0 ? -32768 : 2147450880;
                *(_DWORD *)tmpld12.ld12 = 0;
                goto LABEL_168;
              }
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_168:
                *(_DWORD *)&tmpld12.ld12[8] = v34;
                continue;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v33, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v31 != 0
                  || (++v33, (*(_DWORD *)&v28->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v28->ld12[4] != 0
                  || *(_DWORD *)v28->ld12 != 0 )
                {
                  exp_signa = 0;
                  v35 = &v76[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v28->ld12[8];
                    do
                    {
                      v53 = 0;
                      v36 = *(unsigned __int16 *)found_decpointa * *(unsigned __int16 *)found_exponenta;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        v53 = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( v53 != 0 )
                        ++*v35;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    v28 = v55;
                    ++v35;
                    ++exp_signa;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_178;
                  do
                  {
                    if ( *(int *)&v76[8] < 0 )
                      break;
                    v40 = *(_DWORD *)v76;
                    *(_DWORD *)v76 *= 2;
                    v41 = (v40 >> 31) | (2 * *(_DWORD *)&v76[4]);
                    v42 = *(__int64 *)&v76[4] >> 31;
                    --v39;
                    *(_DWORD *)&v76[4] = v41;
                    *(_DWORD *)&v76[8] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_178:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v76[0] & 1) != 0 )
                          ++exp_adja;
                        v44 = *(_DWORD *)&v76[8];
                        *(_DWORD *)&v76[8] >>= 1;
                        v45 = __SPAIR64__(v44, *(unsigned int *)&v76[4]) >> 1;
                        v46 = *(__int64 *)v76 >> 1;
                        --v43;
                        *(_DWORD *)&v76[4] = v45;
                        *(_DWORD *)v76 = v46;
                      }
                      while ( v43 != 0 );
                      if ( exp_adja != 0 )
                        *(_WORD *)v76 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v76 > 0x8000u || (*(_DWORD *)v76 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v76[2] == -1 )
                    {
                      *(_DWORD *)&v76[2] = 0;
                      if ( *(_DWORD *)&v76[6] == -1 )
                      {
                        *(_DWORD *)&v76[6] = 0;
                        if ( *(_WORD *)&v76[10] == 0xFFFF )
                        {
                          *(_WORD *)&v76[10] = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++*(_WORD *)&v76[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v76[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v76[2];
                    }
                  }
                  v24 = (_LDBL12 *)manlena;
                  if ( (unsigned __int16)v39 >= 0x7FFFu )
                    goto LABEL_167;
                  *(_WORD *)tmpld12.ld12 = *(_WORD *)&v76[2];
                  *(_QWORD *)&tmpld12.ld12[2] = *(_QWORD *)&v76[4];
                  *(_WORD *)&tmpld12.ld12[10] = v32 | v39;
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
            }
          }
        }
        v47 = *(_WORD *)tmpld12.ld12;
        v48 = *(_DWORD *)&tmpld12.ld12[2];
        v49 = *(_DWORD *)&tmpld12.ld12[6];
        v50 = *(_WORD *)&tmpld12.ld12[10];
LABEL_175:
        *(_WORD *)pld12->ld12 = v47;
        *(_WORD *)&pld12->ld12[10] = man_sign | v50;
        *(_DWORD *)&pld12->ld12[2] = v48;
        *(_DWORD *)&pld12->ld12[6] = v49;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D21C1
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x004D21C7
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&NAME__2 )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_5C0DD0;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_5C0E30 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D2278
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x004D2298
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_5C1020 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D22D4
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2302
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_5C1020 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2338
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2362
// Name: __stbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stbuf(_iobuf *str)
{
  int v1; // eax
  int v2; // eax
  char **v3; // edi
  char *v4; // eax
  char *v5; // edi

  v1 = _fileno(stream: str);
  if ( _isatty(fh: v1) == 0 )
    return 0;
  if ( str == &__iob_func()[1] )
  {
    v2 = 0;
  }
  else
  {
    if ( str != &__iob_func()[2] )
      return 0;
    v2 = 1;
  }
  ++_cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0;
  v3 = (char **)(4 * v2 + 6203476);
  if ( _stdbuf[v2] != nullptr || (v4 = (char *)MemAlloc_Alloc(nSize: 0x1000u), *v3 = v4, v4 != nullptr) )
  {
    v5 = *v3;
    str->_base = v5;
    str->_ptr = v5;
    str->_bufsiz = 4096;
    str->_cnt = 4096;
  }
  else
  {
    str->_base = (char *)&str->_charbuf;
    str->_ptr = (char *)&str->_charbuf;
    str->_bufsiz = 2;
    str->_cnt = 2;
  }
  str->_flag |= 0x1102u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D23F8
// Name: __ftbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ftbuf(int flag, _iobuf *str)
{
  if ( flag != 0 && (str->_flag & 0x1000) != 0 )
  {
    _flush(str);
    str->_flag &= 0xFFFFEEFF;
    str->_bufsiz = 0;
    str->_ptr = nullptr;
    str->_base = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D2430
// Name: _sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x4E2E78);
  }
  JUMPOUT(0x4D24BF);
}

//------------------------------------------------------------------------------
// Address: 0x004D2470
// Name: __CIsin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIsin(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIsin;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIsin_pentium4(a1);
  else
__CIsin:
    _CIsin_default(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004D24AB
// Name: __CIsin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004D2559
// Name: fastzero_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastzero_I(_OWORD *dst, unsigned int len)
{
  unsigned int v3; // ecx

  v3 = len >> 7;
  do
  {
    *dst = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 0;
    dst[6] = 0;
    dst[7] = 0;
    dst += 8;
    --v3;
  }
  while ( v3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004D25B0
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _VEC_memzero(int dst, int val, int len)
{
  char *result; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // [esp+4h] [ebp-Ch]

  result = (char *)dst;
  v4 = dst % 16;
  if ( dst % 16 != 0 )
  {
    memset((void *)dst, 0, 16 - v4);
    _VEC_memzero(dst: (void *)(16 - v4 + dst), val: 0, len: len - (16 - v4));
    return (char *)dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastzero_I((_OWORD *)dst, len: len - v5);
      result = (char *)dst;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      memset(&result[len - v5], 0, v6);
      return (char *)dst;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D263F
// Name: __sse2_mathfcns_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sse2_mathfcns_init()
{
  __use_sse2_mathfcns = 0;
  __use_sse2_mathfcns = _get_sse2_info();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D2653
// Name: fastcopy_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastcopy_I(__m128i *dst, const __m128i *src, unsigned int len)
{
  unsigned int v5; // ecx
  __m128i si128; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm3
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  __m128i v11; // xmm7

  v5 = len >> 7;
  do
  {
    si128 = _mm_load_si128(src + 1);
    v7 = _mm_load_si128(src + 2);
    v8 = _mm_load_si128(src + 3);
    *dst = _mm_load_si128(src);
    dst[1] = si128;
    dst[2] = v7;
    dst[3] = v8;
    v9 = _mm_load_si128(src + 5);
    v10 = _mm_load_si128(src + 6);
    v11 = _mm_load_si128(src + 7);
    dst[4] = _mm_load_si128(src + 4);
    dst[5] = v9;
    dst[6] = v10;
    dst[7] = v11;
    src += 8;
    dst += 8;
    --v5;
  }
  while ( v5 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004D26DA
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__m128i *__cdecl _VEC_memcpy(__m128i *dst, const __m128i *src, unsigned int len)
{
  int v3; // ecx
  __m128i *result; // eax
  int v5; // ecx
  unsigned int v6; // [esp+4h] [ebp-18h]

  v3 = (int)src % 16;
  result = dst;
  if ( (((int)dst % 16) | ((int)src % 16)) != 0 )
  {
    if ( v3 == (int)dst % 16 )
    {
      qmemcpy(dst, src, 16 - v3);
      _VEC_memcpy(dst: &dst->m128i_i8[16 - v3], src: &src->m128i_i8[16 - v3], len: len - (16 - v3));
    }
    else
    {
      qmemcpy(dst, src, len);
    }
    return dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastcopy_I(dst, src, len: len - v5);
      result = dst;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      qmemcpy(&result->m128i_i8[len - v5], &src->m128i_i8[len - v5], v6);
      return dst;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D2930
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004D29B8
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  unsigned int v0; // esi
  void (__cdecl *sigabrt)(int); // eax
  unsigned int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // kr00_4
  unsigned int v5; // [esp-4h] [ebp-88h]
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-80h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-30h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-28h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  if ( (__abort_behavior & 1) != 0 )
    _NMSG_WRITE(rterrnum: 10);
  sigabrt = __get_sigabrt();
  if ( sigabrt != nullptr )
  {
    sigabrt = (void (__cdecl *)(int))raise(a1: v0, signum: 22);
    v3 = v5;
  }
  if ( (__abort_behavior & 2) != 0 )
  {
    ContextRecord.Eax = (unsigned int)sigabrt;
    ContextRecord.Ecx = v3;
    ContextRecord.Edx = v2;
    ContextRecord.Esi = v0;
    LOWORD(ContextRecord.SegSs) = __SS__;
    LOWORD(ContextRecord.SegCs) = __CS__;
    LOWORD(ContextRecord.SegDs) = __DS__;
    LOWORD(ContextRecord.SegEs) = __ES__;
    LOWORD(ContextRecord.SegFs) = __FS__;
    LOWORD(ContextRecord.SegGs) = __GS__;
    v4 = __readeflags();
    ContextRecord.EFlags = v4;
    ContextRecord.Esp = (unsigned int)&retaddr;
    ContextRecord.ContextFlags = 65537;
    ContextRecord.Eip = (unsigned int)retaddr;
    ContextRecord.Ebp = savedregs;
    memset(dst: (int)&ExceptionRecord, value: nullptr, count: sizeof(ExceptionRecord));
    ExceptionPointers.ExceptionRecord = &ExceptionRecord;
    ExceptionRecord.ExceptionCode = 1073741845;
    ExceptionRecord.ExceptionAddress = retaddr;
    ExceptionPointers.ContextRecord = &ContextRecord;
    SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
    UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers);
  }
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x004D2AAB
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D2AC9
// Name: long __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *pPtrs)
{
  _EXCEPTION_RECORD *ExceptionRecord; // eax
  unsigned int v2; // eax

  ExceptionRecord = pPtrs->ExceptionRecord;
  if ( pPtrs->ExceptionRecord->ExceptionCode == -529697949 && ExceptionRecord->NumberParameters == 3 )
  {
    v2 = ExceptionRecord->ExceptionInformation[0];
    if ( v2 == 429065504 || v2 == 429065505 || v2 == 429065506 || v2 == 26820608 )
      terminate();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D2B06
// Name: ___CxxSetUnhandledExceptionFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __CxxSetUnhandledExceptionFilter()
{
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: __CxxUnhandledExceptionFilter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D2B14
// Name: __wincmdln
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl _wincmdln()
{
  BOOL v0; // edi
  const char *v1; // esi
  unsigned __int8 v2; // al

  v0 = false;
  if ( __mbctype_initialized == 0 )
    __initmbctable();
  v1 = _acmdln;
  if ( _acmdln == nullptr )
    v1 = defaultValue;
  while ( 1 )
  {
    v2 = *v1;
    if ( *v1 <= 0x20u )
    {
      if ( v2 == 0 )
        return v1;
      if ( !v0 )
        break;
    }
    if ( v2 == 34 )
      v0 = !v0;
    if ( _ismbblead(tst: v2) != 0 )
      ++v1;
    ++v1;
  }
  while ( *v1 != 0 && *v1 <= 0x20u )
    ++v1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x004D2B71
// Name: __setenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setenvp()
{
  char *v0; // esi
  int v1; // edi
  int v3; // eax
  char **v4; // edi
  char *i; // esi
  int v6; // eax
  unsigned int v7; // ebp
  char *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  v0 = _aenvptr;
  v1 = 0;
  if ( _aenvptr != nullptr )
  {
    while ( *v0 != 0 )
    {
      if ( *v0 != 61 )
        ++v1;
      strlen(buf: v0);
      v0 += v3 + 1;
    }
    v4 = (char **)calloc(count: v1 + 1, size: 4u);
    _environ = v4;
    if ( v4 != nullptr )
    {
      for ( i = _aenvptr; ; i += v7 )
      {
        if ( *i == 0 )
        {
          free(pMem: _aenvptr);
          _aenvptr = nullptr;
          *v4 = nullptr;
          __env_initialized = 1;
          return 0;
        }
        strlen(buf: i);
        v7 = v6 + 1;
        if ( *i != 61 )
          break;
LABEL_16:
        ;
      }
      v8 = (char *)calloc(count: v6 + 1, size: 1u);
      *v4 = v8;
      if ( v8 != nullptr )
      {
        v9 = strcpy_s(_Dst: v8, _SizeInBytes: v7, _Src: i);
        if ( v9 != 0 )
          _invoke_watson(a1: v9, a2: v10, a3: v11, a4: 0, a5: (unsigned int)v4, a6: (unsigned int)i);
        ++v4;
        goto LABEL_16;
      }
      free(pMem: _environ);
      _environ = nullptr;
      return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D2C4C
// Name: parse_cmdline
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall parse_cmdline(char *cmdstart@<edx>, int *numchars@<edi>, char **argv, char *args, int *numargs)
{
  int *v5; // ecx
  char *v7; // edx
  char **v8; // ebx
  char v9; // bl
  char *v10; // ecx
  char **v11; // eax
  int v12; // ebx
  unsigned int v13; // ecx
  char v14; // al
  char *v15; // ecx
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-10h]
  BOOL inquote; // [esp+8h] [ebp-4h]
  BOOL inquotea; // [esp+8h] [ebp-4h]

  v5 = numargs;
  *numchars = 0;
  v7 = args;
  *numargs = 1;
  if ( argv != nullptr )
  {
    v8 = argv++;
    *v8 = args;
  }
  inquote = false;
  do
  {
    if ( *cmdstart == 34 )
    {
      v9 = 34;
      ++cmdstart;
      inquote = !inquote;
    }
    else
    {
      ++*numchars;
      if ( v7 != nullptr )
      {
        *v7 = *cmdstart;
        args = v7 + 1;
      }
      v9 = *cmdstart;
      v17 = (unsigned __int8)*cmdstart++;
      if ( _ismbblead(tst: v17) != 0 )
      {
        ++*numchars;
        if ( args != nullptr )
        {
          v10 = args++;
          *v10 = *cmdstart;
        }
        ++cmdstart;
      }
      v7 = args;
      v5 = numargs;
      if ( v9 == 0 )
      {
        --cmdstart;
        goto LABEL_18;
      }
    }
  }
  while ( inquote || v9 != 32 && v9 != 9 );
  if ( v7 != nullptr )
    *(v7 - 1) = 0;
LABEL_18:
  inquotea = false;
  while ( *cmdstart != 0 )
  {
    while ( *cmdstart == 32 || *cmdstart == 9 )
      ++cmdstart;
    if ( *cmdstart == 0 )
      break;
    if ( argv != nullptr )
    {
      v11 = argv++;
      *v11 = v7;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *cmdstart == 92 )
      {
        ++cmdstart;
        ++v13;
      }
      if ( *cmdstart == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( inquotea && cmdstart[1] == 34 )
          {
            ++cmdstart;
          }
          else
          {
            v12 = 0;
            inquotea = !inquotea;
          }
        }
        v13 >>= 1;
      }
      if ( v13 != 0 )
      {
        do
        {
          --v13;
          if ( v7 != nullptr )
            *v7++ = 92;
          ++*numchars;
        }
        while ( v13 != 0 );
        args = v7;
      }
      v14 = *cmdstart;
      if ( *cmdstart == 0 || !inquotea && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 != 0 )
      {
        if ( v7 != nullptr )
        {
          if ( _ismbblead(tst: v14) != 0 )
          {
            v15 = args++;
            *v15 = *cmdstart++;
            ++*numchars;
          }
          v16 = args++;
          *v16 = *cmdstart;
        }
        else if ( _ismbblead(tst: v14) != 0 )
        {
          ++cmdstart;
          ++*numchars;
        }
        ++*numchars;
        v7 = args;
      }
      ++cmdstart;
    }
    if ( v7 != nullptr )
    {
      *v7++ = 0;
      args = v7;
    }
    ++*numchars;
    v5 = numargs;
  }
  if ( argv != nullptr )
    *argv = nullptr;
  ++*v5;
}

//------------------------------------------------------------------------------
// Address: 0x004D2DE4
// Name: __setargv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setargv()
{
  bool v0; // zf
  int v1; // edi
  unsigned int v2; // eax
  char **v3; // esi
  int numchars; // [esp+Ch] [ebp-Ch] BYREF
  int numargs; // [esp+10h] [ebp-8h] BYREF
  char *cmdstart; // [esp+14h] [ebp-4h]

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(hModule: nullptr, lpFilename: pgmname, nSize: 0x104u);
  _pgmptr = pgmname;
  if ( _acmdln == nullptr || (v0 = *_acmdln == 0, cmdstart = _acmdln, v0) )
    cmdstart = pgmname;
  parse_cmdline(cmdstart, &numchars, argv: nullptr, args: nullptr, &numargs);
  if ( (unsigned int)numargs >= 0x3FFFFFFF )
    return -1;
  if ( numchars == -1 )
    return -1;
  v1 = numargs;
  v2 = 4 * numargs + numchars;
  if ( v2 < numchars )
    return -1;
  v3 = (char **)MemAlloc_Alloc(nSize: v2);
  if ( v3 == nullptr )
    return -1;
  parse_cmdline(cmdstart, &numchars, argv: v3, args: (char *)&v3[v1], &numargs);
  __argc = numargs - 1;
  __argv = v3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D2E9D
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsA()
{
  int v0; // eax
  char *v1; // ebx
  WCHAR *EnvironmentStringsW; // esi
  WCHAR *i; // eax
  unsigned int v5; // eax
  int v6; // ebp
  char *v7; // eax
  LPCH EnvironmentStrings; // eax
  char *v9; // esi
  unsigned int v10; // ebp
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // edi
  char *nSizeW; // [esp+10h] [ebp-8h]
  int cchWideChar; // [esp+14h] [ebp-4h]

  v0 = f_use_0;
  v1 = nullptr;
  EnvironmentStringsW = nullptr;
  if ( f_use_0 == 0 )
  {
    EnvironmentStringsW = GetEnvironmentStringsW();
    if ( EnvironmentStringsW != nullptr )
    {
      f_use_0 = 1;
      goto LABEL_8;
    }
    if ( GetLastError() == 120 )
    {
      v0 = 2;
      f_use_0 = 2;
    }
    else
    {
      v0 = f_use_0;
    }
  }
  if ( v0 == 1 )
  {
LABEL_8:
    if ( EnvironmentStringsW == nullptr )
    {
      EnvironmentStringsW = GetEnvironmentStringsW();
      if ( EnvironmentStringsW == nullptr )
        return nullptr;
    }
    for ( i = EnvironmentStringsW; *i != 0; ++i )
    {
      do
        ++i;
      while ( *i != 0 );
    }
    cchWideChar = i - EnvironmentStringsW + 1;
    v5 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: EnvironmentStringsW,
           cchWideChar,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    v6 = v5;
    if ( v5 != 0 )
    {
      v7 = (char *)MemAlloc_Alloc(nSize: v5);
      nSizeW = v7;
      if ( v7 != nullptr )
      {
        if ( WideCharToMultiByte(
               CodePage: 0,
               dwFlags: 0,
               lpWideCharStr: EnvironmentStringsW,
               cchWideChar,
               lpMultiByteStr: v7,
               cbMultiByte: v6,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: nullptr) == 0 )
        {
          free(pMem: nSizeW);
          nSizeW = nullptr;
        }
        v1 = nSizeW;
      }
    }
    FreeEnvironmentStringsW(penv: EnvironmentStringsW);
    return (unsigned __int8 *)v1;
  }
  if ( v0 != 2 && v0 != 0 )
    return nullptr;
  EnvironmentStrings = GetEnvironmentStrings();
  v9 = EnvironmentStrings;
  if ( EnvironmentStrings == nullptr )
    return nullptr;
  for ( ; *EnvironmentStrings != 0; ++EnvironmentStrings )
  {
    do
      ++EnvironmentStrings;
    while ( *EnvironmentStrings != 0 );
  }
  v10 = EnvironmentStrings - v9 + 1;
  v11 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10);
  v12 = v11;
  if ( v11 == nullptr )
  {
    FreeEnvironmentStringsA(penv: v9);
    return nullptr;
  }
  memcpy(dst: v11, src: (unsigned __int8 *)v9, count: v10);
  FreeEnvironmentStringsA(penv: v9);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x004D2FD2
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  ioinfo *v0; // eax
  ioinfo *i; // ecx
  int v2; // edi
  unsigned __int8 *v3; // ebx
  int v4; // esi
  ioinfo *v5; // eax
  ioinfo *j; // edx
  ioinfo *v7; // esi
  signed int k; // ebx
  ioinfo *v9; // esi
  DWORD v10; // eax
  HANDLE StdHandle; // eax
  int v12; // edi
  DWORD FileType; // eax
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-64h] BYREF
  int fh; // [esp+54h] [ebp-20h]
  int *posfhnd; // [esp+58h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+5Ch] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  GetStartupInfoA(lpStartupInfo: &StartupInfo);
  ms_exc.registration.TryLevel = -2;
  v0 = (ioinfo *)calloc(count: 0x20u, size: 0x38u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = v0;
  _nhandle = 32;
  for ( i = v0 + 32; v0 < i; i = __pioinfo[0] + 32 )
  {
    v0->osfile = 0;
    v0->osfhnd = -1;
    v0->pipech = 10;
    v0->lockinitflag = 0;
    *((_BYTE *)v0 + 36) = 0;
    v0->pipech2[0] = 10;
    v0->pipech2[1] = 10;
    ++v0;
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v2 = *(_DWORD *)StartupInfo.lpReserved2;
    v3 = StartupInfo.lpReserved2 + 4;
    posfhnd = (int *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( v2 >= 2048 )
      v2 = 2048;
    v4 = 1;
    while ( (int)_nhandle < v2 )
    {
      v5 = (ioinfo *)calloc(count: 0x20u, size: 0x38u);
      if ( v5 == nullptr )
      {
        v2 = _nhandle;
        break;
      }
      __pioinfo[v4] = v5;
      _nhandle += 32;
      for ( j = v5 + 32; v5 < j; j = __pioinfo[v4] + 32 )
      {
        v5->osfile = 0;
        v5->osfhnd = -1;
        v5->pipech = 10;
        v5->lockinitflag = 0;
        *((_BYTE *)v5 + 36) &= 0x80u;
        v5->pipech2[0] = 10;
        v5->pipech2[1] = 10;
        ++v5;
      }
      ++v4;
    }
    for ( fh = 0; fh < v2; ++posfhnd )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*v3 & 1) != 0
        && ((*v3 & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v7 = &__pioinfo[fh >> 5][fh & 0x1F];
        v7->osfhnd = *posfhnd;
        v7->osfile = *v3;
        if ( !__crtInitCritSecAndSpinCount(a1: (unsigned int)v3, lpCriticalSection: &v7->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v7->lockinitflag;
      }
      ++fh;
      ++v3;
    }
  }
  for ( k = 0; k < 3; ++k )
  {
    v9 = &__pioinfo[0][k];
    if ( v9->osfhnd == -1 || v9->osfhnd == -2 )
    {
      v9->osfile = -127;
      if ( k != 0 )
        v10 = -(k != 1) - 11;
      else
        v10 = -10;
      StdHandle = GetStdHandle(nStdHandle: v10);
      v12 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v9->osfhnd = v12;
        if ( (unsigned __int8)FileType == 2 )
        {
          v9->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v9->osfile |= 8u;
        }
        if ( !__crtInitCritSecAndSpinCount(a1: k, lpCriticalSection: &v9->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v9->lockinitflag;
      }
      else
      {
        v9->osfile |= 0x40u;
        v9->osfhnd = -2;
      }
    }
    else
    {
      v9->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D3212
// Name: ___security_init_cookie
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __security_init_cookie()
{
  unsigned int v0; // esi
  DWORD v1; // esi
  DWORD v2; // esi
  DWORD v3; // esi
  unsigned int v4; // esi
  _LARGE_INTEGER perfctr; // [esp+8h] [ebp-10h] BYREF
  FT systime; // [esp+10h] [ebp-8h] BYREF

  systime.ft_scalar = 0;
  if ( __security_cookie == -1153374642 || (__security_cookie & 0xFFFF0000) == 0 )
  {
    GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&systime);
    v0 = systime.ft_struct.dwLowDateTime ^ systime.ft_struct.dwHighDateTime;
    v1 = GetCurrentProcessId() ^ v0;
    v2 = GetCurrentThreadId() ^ v1;
    v3 = GetTickCount() ^ v2;
    QueryPerformanceCounter(lpPerformanceCount: &perfctr);
    v4 = perfctr.LowPart ^ perfctr.HighPart ^ v3;
    if ( v4 == -1153374642 )
    {
      v4 = -1153374641;
    }
    else if ( (v4 & 0xFFFF0000) == 0 )
    {
      v4 |= v4 << 16;
    }
    __security_cookie = v4;
    __security_cookie_complement = ~v4;
  }
  else
  {
    __security_cookie_complement = ~__security_cookie;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D32A6
// Name: wfindenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall wfindenv@<eax>(unsigned int len@<edi>, const wchar_t *name)
{
  const wchar_t **i; // esi
  wchar_t v3; // ax

  for ( i = (const wchar_t **)_wenviron; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_wenviron) >> 2);
    if ( _wcsnicoll(_string1: name, _string2: *i, count: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_wenviron) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x004D32F7
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 **__usercall copy_environ@<eax>(unsigned __int16 **oldenviron@<edi>)
{
  unsigned __int16 **result; // eax
  unsigned __int16 **v2; // ecx
  unsigned __int16 **v3; // esi
  vgui::CTreeViewListControl *v4; // ecx
  unsigned __int16 *v5; // eax
  unsigned __int16 **v6; // ebx
  vgui::CTreeViewListControl *v7; // [esp-Ch] [ebp-10h]
  vgui::CTreeViewListControl *v8; // [esp-Ch] [ebp-10h]
  vgui::CTreeViewListControl *v9; // [esp-Ch] [ebp-10h]
  unsigned __int16 **newenviron; // [esp+0h] [ebp-4h]

  result = nullptr;
  v2 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v2;
        result = (unsigned __int16 **)((char *)result + 1);
      }
      while ( *v2 != nullptr );
    }
    v3 = (unsigned __int16 **)calloc(count: (unsigned int)result + 1, size: 4u);
    v4 = v7;
    newenviron = v3;
    if ( v3 == nullptr )
    {
      _amsg_exit(rterrnum: 9);
      v4 = v8;
    }
    v5 = *oldenviron;
    v6 = oldenviron;
    while ( v5 != nullptr )
    {
      v9 = (vgui::CTreeViewListControl *)v5;
      *v3++ = (unsigned __int16 *)CBaseAppSystem<IDataModel>::GetDependencies(this: v4);
      v5 = *++v6;
      v4 = v9;
    }
    *v3 = nullptr;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D3354
// Name: ___crtwsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtwsetenv@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        unsigned __int16 **poption,
        int primary)
{
  const wchar_t *v5; // edi
  unsigned __int16 *v6; // eax
  unsigned __int16 *v7; // ebx
  unsigned __int16 **v8; // eax
  char **v9; // eax
  unsigned __int16 **v10; // eax
  int v11; // eax
  unsigned int v12; // ebx
  char *v13; // edi
  unsigned __int16 **v14; // eax
  unsigned int v15; // eax
  unsigned __int16 *v16; // edi
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned __int16 *v21; // ebx
  const wchar_t *v22; // ebx
  unsigned int v23; // eax
  char *v24; // eax
  unsigned int v25; // eax
  char *v26; // eax
  char *c_name; // [esp+8h] [ebp-18h]
  char *c_namea; // [esp+8h] [ebp-18h]
  unsigned int c_value; // [esp+Ch] [ebp-14h]
  char *c_valuea; // [esp+Ch] [ebp-14h]
  int size; // [esp+10h] [ebp-10h]
  int sizea; // [esp+10h] [ebp-10h]
  BOOL remove; // [esp+14h] [ebp-Ch]
  unsigned __int16 *option; // [esp+18h] [ebp-8h]
  int retval; // [esp+1Ch] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  v5 = *poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_13;
  v6 = wcschr(string: v5, ch: 0x3Du);
  v7 = v6;
  if ( v6 == nullptr || v5 == v6 )
    goto LABEL_13;
  remove = v6[1] == 0;
  v8 = _wenviron;
  if ( _wenviron == __winitenv )
  {
    v8 = copy_environ(oldenviron: _wenviron);
    v5 = option;
    _wenviron = v8;
  }
  if ( v8 == nullptr )
  {
    if ( primary != 0 && _environ != nullptr )
    {
      _wenvptr = (wchar_t *)__crtGetEnvironmentStringsW();
      if ( _wsetenvp() < 0 && __mbtow_environ() != 0 )
      {
LABEL_13:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove )
        return 0;
      if ( _environ != nullptr )
        goto LABEL_19;
      v9 = (char **)MemAlloc_Alloc(nSize: 4u);
      _environ = v9;
      if ( v9 == nullptr )
        return -1;
      *v9 = nullptr;
      if ( _wenviron == nullptr )
      {
LABEL_19:
        v10 = (unsigned __int16 **)MemAlloc_Alloc(nSize: 4u);
        _wenviron = v10;
        if ( v10 == nullptr )
          return -1;
        *v10 = nullptr;
      }
    }
  }
  c_name = (char *)_wenviron;
  if ( _wenviron == nullptr )
    return -1;
  c_value = v7 - v5;
  v11 = wfindenv(len: c_value, name: v5);
  v12 = v11;
  if ( v11 < 0 || *(_DWORD *)c_name == 0 )
  {
    if ( !remove )
    {
      if ( v11 < 0 )
        v12 = -v11;
      if ( (int)(v12 + 2) <= (int)v12 )
        return -1;
      if ( v12 + 2 >= 0x3FFFFFFF )
        return -1;
      v14 = (unsigned __int16 **)_recalloc_crt(ptr: _wenviron, count: 4u, size: v12 + 2);
      if ( v14 == nullptr )
        return -1;
      v12 = (unsigned int)&v14[v12];
      *(_DWORD *)v12 = option;
      *(_DWORD *)(v12 + 4) = 0;
      *poption = nullptr;
      goto LABEL_38;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v13 = &c_name[4 * v11];
  free(pMem: *(void **)v13);
  if ( !remove )
  {
    *(_DWORD *)v13 = option;
    *poption = nullptr;
    goto LABEL_39;
  }
  while ( *(_DWORD *)v13 != 0 )
  {
    *(_DWORD *)v13 = *((_DWORD *)v13 + 1);
    ++v12;
    v13 = &c_name[4 * v12];
  }
  if ( v12 < 0x3FFFFFFF )
  {
    v14 = (unsigned __int16 **)_recalloc_crt(ptr: _wenviron, count: v12, size: 4u);
    if ( v14 != nullptr )
LABEL_38:
      _wenviron = v14;
  }
LABEL_39:
  if ( primary != 0 )
  {
    v15 = wcslen(wcs: option);
    v16 = (unsigned __int16 *)calloc(count: v15 + 2, size: 2u);
    if ( v16 != nullptr )
    {
      v17 = wcslen(wcs: option);
      v18 = wcscpy_s(_Dst: v16, _SizeInWords: v17 + 2, _Src: option);
      if ( v18 != 0 )
        _invoke_watson(a1: v18, a2: v19, a3: v20, a4: v12, a5: (unsigned int)v16, a6: 0);
      v21 = &v16[c_value];
      *v21 = 0;
      v22 = v21 + 1;
      if ( f_use == 1 && !SetEnvironmentVariableW(lpName: v16, lpValue: !remove ? v22 : nullptr) )
      {
        if ( GetLastError() == 120 )
        {
          f_use = 0;
          goto LABEL_49;
        }
        retval = -1;
      }
      if ( f_use != 0 )
      {
LABEL_61:
        if ( retval == -1 )
          *_errno() = 42;
        free(pMem: v16);
        goto LABEL_64;
      }
LABEL_49:
      c_namea = nullptr;
      c_valuea = nullptr;
      v23 = WideCharToMultiByte(
              CodePage: 0,
              dwFlags: 0,
              lpWideCharStr: v16,
              cchWideChar: -1,
              lpMultiByteStr: nullptr,
              cbMultiByte: 0,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
      size = v23;
      if ( v23 != 0 )
      {
        v24 = (char *)calloc(count: v23, size: 1u);
        c_namea = v24;
        if ( v24 != nullptr
          && WideCharToMultiByte(
               CodePage: 0,
               dwFlags: 0,
               lpWideCharStr: v16,
               cchWideChar: -1,
               lpMultiByteStr: v24,
               cbMultiByte: size,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: nullptr) != 0 )
        {
          if ( remove )
            goto LABEL_57;
          v25 = WideCharToMultiByte(
                  CodePage: 0,
                  dwFlags: 0,
                  lpWideCharStr: v22,
                  cchWideChar: -1,
                  lpMultiByteStr: nullptr,
                  cbMultiByte: 0,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          sizea = v25;
          if ( v25 != 0 )
          {
            v26 = (char *)calloc(count: v25, size: 1u);
            c_valuea = v26;
            if ( v26 != nullptr )
            {
              if ( WideCharToMultiByte(
                     CodePage: 0,
                     dwFlags: 0,
                     lpWideCharStr: v22,
                     cchWideChar: -1,
                     lpMultiByteStr: v26,
                     cbMultiByte: sizea,
                     lpDefaultChar: nullptr,
                     lpUsedDefaultChar: nullptr) == 0 )
                retval = -1;
LABEL_57:
              if ( retval == -1 || SetEnvironmentVariableA(lpName: c_namea, lpValue: !remove ? c_valuea : nullptr) )
                goto LABEL_60;
            }
          }
        }
      }
      retval = -1;
LABEL_60:
      free(pMem: c_valuea);
      free(pMem: c_namea);
      goto LABEL_61;
    }
  }
LABEL_64:
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004D36BA
// Name: _wcslen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // eax
  __int16 v2; // cx

  v1 = wcs;
  do
    v2 = *v1++;
  while ( v2 != 0 );
  return v1 - wcs - 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D36D0
// Name: findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall findenv@<eax>(unsigned int len@<edi>, const char *name)
{
  const unsigned __int8 **i; // esi
  unsigned __int8 v3; // al

  for ( i = (const unsigned __int8 **)_environ; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_environ) >> 2);
    if ( _mbsnbicoll(s1: (const unsigned __int8 *)name, s2: *i, n: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_environ) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x004D371D
// Name: copy_environ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall copy_environ_0@<eax>(char **oldenviron@<edi>)
{
  char **result; // eax
  char **v2; // ecx
  char **v3; // esi
  char *v4; // eax
  char **v5; // ebx
  char **newenviron; // [esp+0h] [ebp-4h]

  result = nullptr;
  v2 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v2;
        result = (char **)((char *)result + 1);
      }
      while ( *v2 != nullptr );
    }
    v3 = (char **)calloc(count: (unsigned int)result + 1, size: 4u);
    newenviron = v3;
    if ( v3 == nullptr )
      _amsg_exit(rterrnum: 9);
    v4 = *oldenviron;
    v5 = oldenviron;
    while ( v4 != nullptr )
    {
      *v3++ = _strdup(string: v4);
      v4 = *++v5;
    }
    *v3 = nullptr;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D377A
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtsetenv@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, char **poption, int primary)
{
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // eax
  bool v7; // zf
  char **v8; // eax
  char **v9; // eax
  unsigned __int16 **v10; // eax
  char **v11; // esi
  int v12; // eax
  unsigned int v13; // edi
  char **v14; // esi
  char **v15; // eax
  char **v16; // ecx
  int v17; // eax
  char *v18; // edi
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // edx
  unsigned int v22; // ecx
  const char *v23; // eax
  char **env; // [esp+8h] [ebp-14h]
  int retval; // [esp+Ch] [ebp-10h]
  const char *equal; // [esp+10h] [ebp-Ch]
  int remove; // [esp+14h] [ebp-8h]
  char *option; // [esp+18h] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    return -1;
  }
  v5 = (const unsigned __int8 *)*poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_12;
  v6 = _mbschr(string: v5, c: 0x3Du);
  equal = (const char *)v6;
  if ( v6 == nullptr || v5 == v6 )
    goto LABEL_12;
  v7 = v6[1] == 0;
  v8 = _environ;
  remove = v7;
  if ( _environ == __initenv )
  {
    v8 = copy_environ_0(oldenviron: _environ);
    _environ = v8;
  }
  if ( v8 == nullptr )
  {
    if ( primary != 0 && _wenviron != nullptr )
    {
      if ( __wtomb_environ() != 0 )
      {
LABEL_12:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove != 0 )
        return 0;
      v9 = (char **)MemAlloc_Alloc(nSize: 4u);
      _environ = v9;
      if ( v9 == nullptr )
        return -1;
      *v9 = nullptr;
      if ( _wenviron == nullptr )
      {
        v10 = (unsigned __int16 **)MemAlloc_Alloc(nSize: 4u);
        _wenviron = v10;
        if ( v10 == nullptr )
          return -1;
        *v10 = nullptr;
      }
    }
  }
  v11 = _environ;
  env = _environ;
  if ( _environ == nullptr )
    return -1;
  v12 = findenv(len: equal - option, name: option);
  v13 = v12;
  if ( v12 < 0 || *v11 == nullptr )
  {
    if ( remove == 0 )
    {
      if ( v12 < 0 )
        v13 = -v12;
      if ( (int)(v13 + 2) <= (int)v13 )
        return -1;
      if ( v13 + 2 >= 0x3FFFFFFF )
        return -1;
      v15 = (char **)_recalloc_crt(ptr: _environ, count: 4u, size: v13 + 2);
      if ( v15 == nullptr )
        return -1;
      v16 = &v15[v13];
      *v16 = option;
      v16[1] = nullptr;
      *poption = nullptr;
      goto LABEL_36;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v14 = &v11[v12];
  free(pMem: *v14);
  if ( remove == 0 )
  {
    *v14 = option;
    *poption = nullptr;
    goto LABEL_37;
  }
  while ( *v14 != nullptr )
  {
    *v14 = v14[1];
    v14 = &env[++v13];
  }
  if ( v13 < 0x3FFFFFFF )
  {
    v15 = (char **)_recalloc_crt(ptr: _environ, count: v13, size: 4u);
    if ( v15 == nullptr )
      goto LABEL_37;
LABEL_36:
    _environ = v15;
  }
LABEL_37:
  if ( primary != 0 )
  {
    strlen(buf: option);
    v18 = (char *)calloc(count: v17 + 2, size: 1u);
    if ( v18 != nullptr )
    {
      strlen(buf: option);
      v20 = strcpy_s(_Dst: v18, _SizeInBytes: v19 + 2, _Src: option);
      if ( v20 != 0 )
        _invoke_watson(a1: v20, a2: v21, a3: v22, a4: 0, a5: (unsigned int)v18, a6: (unsigned int)option);
      v23 = &equal[v18 - option];
      *v23 = 0;
      if ( !SetEnvironmentVariableA(lpName: v18, lpValue: remove == 0 ? v23 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pMem: v18);
    }
  }
  if ( remove != 0 )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004D39C6
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strcpy_s@<eax>(unsigned int a1@<edi>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // al

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(a1: 0, a2: a1, a3: v4);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --a1;
  }
  while ( a1 != 0 );
  if ( a1 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D3A2B
// Name: _strnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strnlen(const char *str, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++str )
  {
    if ( *str == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D3A45
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbschr_l(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        unsigned __int8 *string,
        unsigned int c,
        localeinfo_struct *plocinfo)
{
  unsigned __int8 *v5; // eax
  unsigned __int16 v6; // cx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v5 = string;
  if ( string != nullptr )
  {
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      while ( 1 )
      {
        v6 = *v5;
        if ( *v5 == 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) != 0 )
        {
          if ( *++v5 == 0 )
            goto LABEL_17;
          if ( c == (*v5 | (v6 << 8)) )
            goto LABEL_15;
        }
        else if ( c == *v5 )
        {
          break;
        }
        ++v5;
      }
      if ( c == *v5 )
        goto LABEL_15;
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      strchr(string, chr: c);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3AFF
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbschr(unsigned int a1@<edi>, unsigned int a2@<esi>, unsigned __int8 *string, unsigned int c)
{
  _mbschr_l(a1, a2, string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D3B12
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _getdrive()
{
  unsigned __int8 *v0; // ebx
  signed int CurrentDirectoryA; // esi
  char *v2; // eax
  unsigned int v3; // edi
  int memfree; // [esp+10h] [ebp-7Ch]
  char curdirstr[264]; // [esp+14h] [ebp-78h] BYREF

  memfree = 0;
  v0 = (unsigned __int8 *)curdirstr;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryA > 260 )
  {
    v2 = (char *)calloc(count: CurrentDirectoryA + 1, size: 1u);
    v0 = (unsigned __int8 *)v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: CurrentDirectoryA + 1, lpBuffer: v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryA = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryA != 0 )
  {
    if ( v0[1] == 58 )
      v3 = toupper(c: *v0) - 64;
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004D3BD8
// Name: __mbsnbicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbicoll_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  int v7; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( s1 != nullptr && s2 != nullptr )
  {
    if ( n > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: 0x7FFFFFFFu);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      v7 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: _loc_update.localeinfo.mbcinfo->mblcid,
             dwCmpFlags: 0x1001u,
             lpString1: (const char *)s1,
             cchCount1: n,
             lpString2: (const char *)s2,
             cchCount2: n,
             code_page: _loc_update.localeinfo.mbcinfo->mbcodepage);
      if ( v7 == 0 )
        goto LABEL_15;
      result = v7 - 2;
    }
    else
    {
      result = _strnicoll_l(_string1: (const char *)s1, _string2: (const char *)s2, count: n, plocinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D3CC4
// Name: __mbsnbicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbicoll@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n)
{
  return _mbsnbicoll_l(a1, a2, s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D3CDB
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const WCHAR *v1; // eax
  unsigned int v2; // eax
  char *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  char *envp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCWCH *)_wenviron;
  envp = nullptr;
  v1 = *_wenviron;
  if ( *_wenviron == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: v1,
           cchWideChar: -1,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    size = v2;
    if ( v2 == 0 )
      break;
    v3 = (char *)calloc(count: v2, size: 1u);
    envp = v3;
    if ( v3 == nullptr )
      break;
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: *v0,
           cchWideChar: -1,
           lpMultiByteStr: v3,
           cbMultiByte: size,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(pMem: envp);
      return -1;
    }
    if ( __crtsetenv(a1: (unsigned int)v0, a2: 0, poption: &envp, primary: 0) < 0 && envp != nullptr )
    {
      free(pMem: envp);
      envp = nullptr;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D3D70
// Name: comexecmd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall comexecmd@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        int mode,
        const char *name,
        const char *const *argv,
        const char *const *envp)
{
  int v7; // esi
  char *envblk; // [esp+4h] [ebp-8h] BYREF
  char *argblk; // [esp+8h] [ebp-4h] BYREF

  if ( name == nullptr || argv == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  if ( _cenvarg(argv, envp, &argblk, &envblk, name) == -1 )
    return -1;
  v7 = _dospawn(mode, name, cmdblk: argblk, envblk);
  free(pMem: argblk);
  free(pMem: envblk);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004D3DE8
// Name: __spawnve
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _spawnve@<eax>(
        unsigned int a1@<esi>,
        int mode,
        char *name,
        const char *const *argv,
        const char *const *envp)
{
  const char *v5; // edi
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // eax
  const unsigned __int8 *v9; // eax
  int v10; // eax
  unsigned int v11; // esi
  char *v12; // eax
  char *v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // edx
  unsigned int v19; // ecx
  int v20; // eax
  unsigned int v21; // esi
  char *v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // ecx
  int v26; // eax
  char *v27; // edi
  unsigned int v28; // esi
  unsigned int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // ecx
  int save_errno; // [esp+8h] [ebp-14h]
  int rc; // [esp+Ch] [ebp-10h]
  const char **v34; // [esp+10h] [ebp-Ch]
  char *p; // [esp+14h] [ebp-8h]
  char *pathname; // [esp+18h] [ebp-4h]

  v5 = name;
  pathname = name;
  if ( name == nullptr || *name == 0 || argv == nullptr || *argv == nullptr || **(_BYTE **)argv == 0 )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)name, a3: a1);
    return -1;
  }
  v7 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x5Cu);
  v8 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Fu);
  if ( v8 != nullptr )
  {
    if ( v7 == nullptr || v8 > v7 )
      v7 = v8;
  }
  else if ( v7 == nullptr )
  {
    _mbschr(a1: (unsigned int)name, a2: 0, string: (unsigned __int8 *)name, c: 0x3Au);
    v7 = v9;
    if ( v9 == nullptr )
    {
      strlen(buf: name);
      v11 = v10 + 3;
      v12 = (char *)calloc(count: v10 + 3, size: 1u);
      v13 = v12;
      pathname = v12;
      if ( v12 == nullptr )
        return -1;
      v14 = strcpy_s(a1: (unsigned int)v12, _Dst: v12, _SizeInBytes: v11, _Src: ".\\");
      if ( v14 != 0 )
        _invoke_watson(a1: v14, a2: v15, a3: v16, a4: 0, a5: (unsigned int)v13, a6: v11);
      v17 = strcat_s(_Dst: v13, _SizeInBytes: v11, _Src: name);
      if ( v17 != 0 )
        _invoke_watson(a1: v17, a2: v18, a3: v19, a4: 0, a5: (unsigned int)v13, a6: v11);
      v7 = (const unsigned __int8 *)(v13 + 2);
      v5 = name;
    }
  }
  rc = -1;
  if ( _mbsrchr(str: v7, c: 0x2Eu) == nullptr )
  {
    strlen(buf: pathname);
    v21 = v20 + 5;
    v22 = (char *)calloc(count: v20 + 5, size: 1u);
    p = v22;
    if ( v22 != nullptr )
    {
      v23 = strcpy_s(a1: (unsigned int)v5, _Dst: v22, _SizeInBytes: v21, _Src: pathname);
      if ( v23 != 0 )
        _invoke_watson(a1: v23, a2: v24, a3: v25, a4: 0, a5: (unsigned int)v5, a6: v21);
      strlen(buf: pathname);
      v27 = &p[v26];
      save_errno = *_errno();
      v28 = (unsigned int)&p[v21 - (_DWORD)v27];
      v34 = (const char **)(ext_strings + 12);
      while ( 1 )
      {
        v29 = strcpy_s(a1: (unsigned int)v27, _Dst: v27, _SizeInBytes: v28, _Src: *v34);
        if ( v29 != 0 )
          _invoke_watson(a1: v29, a2: v30, a3: v31, a4: 0, a5: (unsigned int)v27, a6: v28);
        if ( _access_s(path: p, amode: 0) == 0 )
          break;
        if ( (int)--v34 < (int)ext_strings )
          goto LABEL_33;
      }
      *_errno() = save_errno;
      rc = comexecmd(a1: 0, a2: (unsigned int)v27, mode, name: p, argv, envp);
LABEL_33:
      free(pMem: p);
      v5 = name;
      goto LABEL_34;
    }
    return -1;
  }
  if ( _access_s(path: pathname, amode: 0) == 0 )
    rc = comexecmd(a1: 0, a2: (unsigned int)v5, mode, name: pathname, argv, envp);
LABEL_34:
  if ( pathname != v5 )
    free(pMem: pathname);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x004D4007
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D409B
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _close@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 6326944, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x004D4168
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fileno@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D4195
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pMem: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D41C1
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = _fileno(a1: 0, a2: (unsigned int)v4, stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004D4223
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fflush_nolock@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *str)
{
  int v4; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v4 = _fileno(a1, a2, stream: str);
  return -(_commit(filedes: v4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x004D4265
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall flsall@<eax>(unsigned int a1@<ebx>, int flushflag)
{
  int i; // esi
  char **v3; // eax
  char *v4; // eax
  int v5; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v3 = (char **)&__piob[i];
    if ( *v3 != nullptr )
    {
      v4 = *v3;
      if ( (v4[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v4);
        v5 = *((_DWORD *)__piob[i] + 3);
        if ( (v5 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(a1, a2: 0, str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v5 & 2) != 0 && _fflush_nolock(a1, a2: 0, str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D433F
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _flushall@<eax>(unsigned int a1@<ebx>)
{
  return flsall(a1, flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004D4348
// Name: __filbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _filbuf@<eax>(unsigned int a1@<ebx>, _iobuf *str)
{
  int flag; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  _DWORD *v6; // edi
  ioinfo *v7; // eax
  int v8; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-10h]
  unsigned int bufsiz; // [esp-4h] [ebp-Ch]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0, a3: 0);
    return -1;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return -1;
  }
  v3 = flag | 1;
  str->_flag = v3;
  if ( (v3 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v4 = _fileno(a1, a2: 0, stream: str);
  v5 = _read(fh: v4, buf: base, cnt: bufsiz);
  str->_cnt = v5;
  if ( v5 == 0 || v5 == -1 )
  {
    str->_flag |= v5 != 0 ? 32 : 16;
    str->_cnt = 0;
    return -1;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( _fileno(a1, a2: 0, stream: str) == -1 || _fileno(a1, a2: 0, stream: str) == -2 )
    {
      v7 = &__badioinfo;
    }
    else
    {
      v6 = (_DWORD *)(4 * (_fileno(a1, a2: 0, stream: str) >> 5) + 6326944);
      v7 = (ioinfo *)(*v6 + 56 * (_fileno(a1, a2: (unsigned int)v6, stream: str) & 0x1F));
    }
    if ( (v7->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v8 = str->_flag;
    if ( (v8 & 8) != 0 && (v8 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  --str->_cnt;
  result = (unsigned __int8)*ptr;
  str->_ptr = ptr + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D4468
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _read_nolock@<eax>(unsigned int a1@<edi>, int fh, _BYTE *inputbuf, unsigned int cnt)
{
  unsigned int v4; // edx
  int result; // eax
  int v6; // esi
  ioinfo *v7; // eax
  char osfile; // cl
  _BYTE *v9; // eax
  __int64 v10; // rax
  ioinfo *v11; // ecx
  ioinfo *v12; // ecx
  char pipech; // cl
  ioinfo *v14; // ecx
  bool v15; // zf
  char v16; // cl
  ioinfo *v17; // ecx
  char v18; // cl
  ioinfo *v19; // ecx
  ioinfo *v20; // eax
  char *p_osfile; // eax
  char *v22; // ebx
  bool v23; // cf
  char v24; // al
  char *v25; // eax
  char *v26; // ebx
  int v27; // ecx
  int v28; // eax
  char v29; // dl
  ioinfo *v30; // ecx
  char *v31; // ebx
  int v32; // ebx
  DWORD LastError; // eax
  ioinfo *v34; // edx
  BOOL v35; // ecx
  char *v36; // ebx
  __int16 v37; // cx
  char *v38; // esi
  unsigned int inputsize; // [esp+4h] [ebp-1Ch]
  int os_read; // [esp+8h] [ebp-18h] BYREF
  int retval; // [esp+Ch] [ebp-14h]
  int bytes_read; // [esp+10h] [ebp-10h]
  void *buf; // [esp+14h] [ebp-Ch]
  wchar_t wpeekchr; // [esp+18h] [ebp-8h] BYREF
  char tmode; // [esp+1Eh] [ebp-2h]
  char peekchr; // [esp+1Fh] [ebp-1h] BYREF
  char *p; // [esp+30h] [ebp+10h]
  char *pa; // [esp+30h] [ebp+10h]

  v4 = cnt;
  retval = -2;
  inputsize = cnt;
  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1: 0, a2: a1, a3: fh);
    return -1;
  }
  v6 = fh & 0x1F;
  v7 = &__pioinfo[fh >> 5][v6];
  osfile = v7->osfile;
  if ( (osfile & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter(a1: 0, a2: 4 * (fh >> 5) + 6326944, a3: v6 * 56);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  bytes_read = 0;
  if ( cnt == 0 || (osfile & 2) != 0 )
    return 0;
  if ( inputbuf == nullptr )
    goto LABEL_18;
  tmode = (char)(2 * *((_BYTE *)v7 + 36)) >> 1;
  if ( tmode != 1 )
  {
    if ( tmode != 2 )
    {
LABEL_16:
      v9 = inputbuf;
      buf = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v4 >> 1 >= 4 )
    cnt = v4 >> 1;
  buf = MemAlloc_Alloc(nSize: cnt);
  if ( buf == nullptr )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v10 = _lseeki64_nolock(fh, pos: 0, mthd: 1);
  v11 = __pioinfo[fh >> 5];
  LODWORD(v11[v6].startpos) = v10;
  v9 = buf;
  HIDWORD(v11[v6].startpos) = HIDWORD(v10);
LABEL_26:
  v12 = &__pioinfo[fh >> 5][v6];
  if ( (v12->osfile & 0x48) != 0 )
  {
    pipech = v12->pipech;
    if ( pipech != 10 && cnt != 0 )
    {
      *v9 = pipech;
      v14 = __pioinfo[fh >> 5];
      ++v9;
      --cnt;
      v15 = tmode == 0;
      bytes_read = 1;
      v14[v6].pipech = 10;
      if ( !v15 )
      {
        v16 = __pioinfo[fh >> 5][v6].pipech2[0];
        if ( v16 != 10 && cnt != 0 )
        {
          *v9 = v16;
          v17 = __pioinfo[fh >> 5];
          ++v9;
          --cnt;
          v15 = tmode == 1;
          bytes_read = 2;
          v17[v6].pipech2[0] = 10;
          if ( v15 )
          {
            v18 = __pioinfo[fh >> 5][v6].pipech2[1];
            if ( v18 != 10 && cnt != 0 )
            {
              *v9 = v18;
              v19 = __pioinfo[fh >> 5];
              ++v9;
              --cnt;
              bytes_read = 3;
              v19[v6].pipech2[1] = 10;
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(
          hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
          lpBuffer: v9,
          nNumberOfBytesToRead: cnt,
          lpNumberOfBytesRead: (LPDWORD)&os_read,
          lpOverlapped: nullptr)
    || os_read < 0
    || os_read > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      retval = 0;
      goto error_return;
    }
    goto LABEL_92;
  }
  v20 = __pioinfo[fh >> 5];
  bytes_read += os_read;
  p_osfile = &v20[v6].osfile;
  if ( *p_osfile < 0 )
  {
    if ( tmode != 2 )
    {
      if ( os_read != 0 && *(_BYTE *)buf == 10 )
        *p_osfile |= 4u;
      else
        *p_osfile &= ~4u;
      v22 = (char *)buf;
      v23 = buf < (char *)buf + bytes_read;
      p = (char *)buf;
      bytes_read += (int)buf;
      if ( v23 )
      {
        do
        {
          v24 = *p;
          if ( *p == 26 )
          {
            v25 = &__pioinfo[fh >> 5][v6].osfile;
            if ( (*v25 & 0x40) != 0 )
              *v22++ = *p;
            else
              *v25 |= 2u;
            break;
          }
          if ( v24 == 13 )
          {
            if ( (unsigned int)p < bytes_read - 1 )
            {
              if ( p[1] == 10 )
              {
                p += 2;
                goto LABEL_52;
              }
              ++p;
LABEL_63:
              *v22 = 13;
LABEL_64:
              ++v22;
              continue;
            }
            ++p;
            if ( !ReadFile(
                    hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                    lpBuffer: &peekchr,
                    nNumberOfBytesToRead: 1u,
                    lpNumberOfBytesRead: (LPDWORD)&os_read,
                    lpOverlapped: nullptr)
              && GetLastError() != 0
              || os_read == 0 )
            {
              goto LABEL_63;
            }
            if ( (__pioinfo[fh >> 5][v6].osfile & 0x48) != 0 )
            {
              if ( peekchr != 10 )
              {
                *v22 = 13;
                __pioinfo[fh >> 5][v6].pipech = peekchr;
                goto LABEL_64;
              }
LABEL_52:
              *v22 = 10;
              goto LABEL_64;
            }
            if ( v22 == buf && peekchr == 10 )
              goto LABEL_52;
            _lseeki64_nolock(fh, pos: -1, mthd: 1);
            if ( peekchr != 10 )
              goto LABEL_63;
          }
          else
          {
            *v22++ = v24;
            ++p;
          }
        }
        while ( (unsigned int)p < bytes_read );
      }
      bytes_read = v22 - (_BYTE *)buf;
      if ( tmode != 1 || v22 == buf )
        goto error_return;
      v26 = v22 - 1;
      LOBYTE(v27) = *v26;
      if ( *v26 < 0 )
      {
        v28 = 1;
        v27 = (unsigned __int8)v27;
        while ( _lookuptrailbytes[v27] == 0 && v28 <= 4 && v26 >= buf )
        {
          v27 = (unsigned __int8)*--v26;
          ++v28;
        }
        v29 = *v26;
        if ( _lookuptrailbytes[(unsigned __int8)*v26] == 0 )
        {
          *_errno() = 42;
LABEL_93:
          retval = -1;
          goto error_return;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v26] + 1 == v28 )
        {
          v26 += v28;
        }
        else
        {
          v30 = &__pioinfo[fh >> 5][v6];
          if ( (v30->osfile & 0x48) != 0 )
          {
            v31 = v26 + 1;
            v30->pipech = v29;
            if ( v28 >= 2 )
              __pioinfo[fh >> 5][v6].pipech2[0] = *v31++;
            if ( v28 == 3 )
              __pioinfo[fh >> 5][v6].pipech2[1] = *v31++;
            v26 = &v31[-v28];
          }
          else
          {
            _lseeki64_nolock(fh, pos: -v28, mthd: 1);
          }
        }
      }
      else
      {
        ++v26;
      }
      v32 = v26 - (_BYTE *)buf;
      bytes_read = MultiByteToWideChar(
                     CodePage: 0xFDE9u,
                     dwFlags: 0,
                     lpMultiByteStr: (LPCCH)buf,
                     cbMultiByte: v32,
                     lpWideCharStr: (LPWSTR)inputbuf,
                     cchWideChar: inputsize >> 1);
      if ( bytes_read != 0 )
      {
        v34 = __pioinfo[fh >> 5];
        v35 = bytes_read != v32;
        bytes_read *= 2;
        v34[v6].utf8translations = v35;
        goto error_return;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(oserrno: LastError);
      goto LABEL_93;
    }
    if ( os_read != 0 && *(_WORD *)buf == 10 )
      *p_osfile |= 4u;
    else
      *p_osfile &= ~4u;
    v36 = (char *)buf;
    v23 = buf < (char *)buf + bytes_read;
    pa = (char *)buf;
    bytes_read += (int)buf;
    if ( !v23 )
    {
LABEL_128:
      bytes_read = v36 - (_BYTE *)buf;
      goto error_return;
    }
    while ( 1 )
    {
      v37 = *(_WORD *)pa;
      if ( *(_WORD *)pa == 26 )
      {
        v38 = &__pioinfo[fh >> 5][v6].osfile;
        if ( (*v38 & 0x40) != 0 )
        {
          *(_WORD *)v36 = *(_WORD *)pa;
          v36 += 2;
        }
        else
        {
          *v38 |= 2u;
        }
        goto LABEL_128;
      }
      if ( v37 == 13 )
      {
        if ( (unsigned int)pa < bytes_read - 2 )
        {
          if ( *((_WORD *)pa + 1) == 10 )
          {
            pa += 4;
            goto LABEL_110;
          }
          pa += 2;
LABEL_121:
          *(_WORD *)v36 = 13;
LABEL_122:
          v36 += 2;
          goto LABEL_123;
        }
        pa += 2;
        if ( !ReadFile(
                hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                lpBuffer: &wpeekchr,
                nNumberOfBytesToRead: 2u,
                lpNumberOfBytesRead: (LPDWORD)&os_read,
                lpOverlapped: nullptr)
          && GetLastError() != 0
          || os_read == 0 )
        {
          goto LABEL_121;
        }
        if ( (__pioinfo[fh >> 5][v6].osfile & 0x48) != 0 )
        {
          if ( wpeekchr != 10 )
          {
            *(_WORD *)v36 = 13;
            __pioinfo[fh >> 5][v6].pipech = wpeekchr;
            __pioinfo[fh >> 5][v6].pipech2[0] = HIBYTE(wpeekchr);
            __pioinfo[fh >> 5][v6].pipech2[1] = 10;
            goto LABEL_122;
          }
LABEL_110:
          *(_WORD *)v36 = 10;
          goto LABEL_122;
        }
        if ( v36 == buf && wpeekchr == 10 )
          goto LABEL_110;
        _lseeki64_nolock(fh, pos: -2, mthd: 1);
        if ( wpeekchr != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v36 = v37;
        v36 += 2;
        pa += 2;
      }
LABEL_123:
      if ( (unsigned int)pa >= bytes_read )
        goto LABEL_128;
    }
  }
error_return:
  if ( buf != inputbuf )
    free(pMem: buf);
  result = retval;
  if ( retval == -2 )
    return bytes_read;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D4A29
// Name: __read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _read@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh, _BYTE *buf, unsigned int cnt)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 6326944, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_7:
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_7;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _read_nolock(a1: 0, fh, inputbuf: buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x004D4B26
// Name: _memcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall memcpy_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int8 *dst,
        unsigned int sizeInBytes,
        unsigned __int8 *src,
        unsigned int count)
{
  unsigned int v6; // esi

  if ( count == 0 )
    return 0;
  if ( dst != nullptr )
  {
    if ( src != nullptr && sizeInBytes >= count )
    {
      memcpy(dst, src, count);
      return 0;
    }
    memset((int)dst, value: nullptr, count: sizeInBytes);
    if ( src != nullptr )
    {
      if ( sizeInBytes < count )
      {
        *_errno() = 34;
        v6 = 34;
        goto LABEL_5;
      }
      return 22;
    }
  }
  v6 = 22;
  *_errno() = 22;
LABEL_5:
  _invalid_parameter(a1, a2: 0, a3: v6);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004D4BA1
// Name: __lseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _lseek_nolock(int fh, LONG pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD v5; // edi
  DWORD LastError; // eax
  char *p_osfile; // eax

  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  else
  {
    v5 = SetFilePointer(hFile: osfhandle, lDistanceToMove: pos, lpDistanceToMoveHigh: nullptr, dwMoveMethod: mthd);
    if ( v5 == -1 )
      LastError = GetLastError();
    else
      LastError = 0;
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return -1;
    }
    else
    {
      p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
      *p_osfile &= ~2u;
      return v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D4C13
// Name: __lseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __usercall _lseek@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh, LONG pos, DWORD mthd)
{
  DWORD r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 6326944, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _lseek_nolock(fh, pos, mthd);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x004D4CEF
// Name: __openfile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__usercall _openfile@<eax>(
        unsigned int a1@<edi>,
        const char *filename,
        const char *mode,
        int shflag,
        _iobuf *str)
{
  char v6; // al
  int v8; // ecx
  const unsigned __int8 *v9; // esi
  signed __int8 v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int filedes; // [esp+8h] [ebp-10h] BYREF
  int commodeset; // [esp+Ch] [ebp-Ch]
  int scanset; // [esp+10h] [ebp-8h]
  int streamflag; // [esp+14h] [ebp-4h]
  unsigned int modeflag; // [esp+24h] [ebp+Ch]

  streamflag = _commode;
  commodeset = 0;
  scanset = 0;
  filedes = 0;
  while ( *mode == 32 )
    ++mode;
  v6 = *mode;
  if ( *mode == 97 )
  {
    modeflag = 265;
LABEL_11:
    streamflag |= 2u;
    goto LABEL_12;
  }
  if ( v6 != 114 )
  {
    if ( v6 != 119 )
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: (unsigned int)mode);
      return nullptr;
    }
    modeflag = 769;
    goto LABEL_11;
  }
  streamflag |= 1u;
  modeflag = 0;
LABEL_12:
  v8 = 1;
  v9 = (const unsigned __int8 *)(mode + 1);
  v10 = *v9;
  if ( *v9 == 0 )
    goto LABEL_62;
  a1 = 0x4000;
  while ( v8 != 0 )
  {
    if ( v10 > 83 )
    {
      v16 = v10 - 84;
      if ( v16 == 0 )
      {
        if ( (modeflag & 0x1000) == 0 )
        {
          modeflag |= 0x1000u;
          goto LABEL_49;
        }
        goto LABEL_47;
      }
      v17 = v16 - 14;
      if ( v17 != 0 )
      {
        v18 = v17 - 1;
        if ( v18 != 0 )
        {
          v19 = v18 - 11;
          if ( v19 != 0 )
          {
            if ( v19 != 6 )
              goto LABEL_64;
            if ( (modeflag & 0xC000) != 0 )
              goto LABEL_47;
            modeflag |= 0x4000u;
          }
          else
          {
            if ( commodeset != 0 )
              goto LABEL_47;
            streamflag &= ~0x4000u;
            commodeset = 1;
          }
        }
        else
        {
          if ( commodeset != 0 )
            goto LABEL_47;
          streamflag |= 0x4000u;
          commodeset = 1;
        }
      }
      else
      {
        if ( (modeflag & 0xC000) != 0 )
          goto LABEL_47;
        modeflag |= 0x8000u;
      }
    }
    else if ( v10 == 83 )
    {
      if ( scanset != 0 )
        goto LABEL_47;
      modeflag |= 0x20u;
      scanset = 1;
    }
    else
    {
      v11 = v10 - 32;
      if ( v11 != 0 )
      {
        v12 = v11 - 11;
        if ( v12 != 0 )
        {
          v13 = v12 - 1;
          if ( v13 == 0 )
          {
            filedes = 1;
LABEL_47:
            v8 = 0;
            goto LABEL_49;
          }
          v14 = v13 - 24;
          if ( v14 != 0 )
          {
            v15 = v14 - 10;
            if ( v15 != 0 )
            {
              if ( v15 != 4 )
                goto LABEL_64;
              if ( scanset != 0 )
                goto LABEL_47;
              modeflag |= 0x10u;
              scanset = 1;
            }
            else
            {
              modeflag |= 0x80u;
            }
          }
          else
          {
            if ( (modeflag & 0x40) != 0 )
              goto LABEL_47;
            modeflag |= 0x40u;
          }
        }
        else
        {
          if ( (modeflag & 2) != 0 )
            goto LABEL_47;
          modeflag = modeflag & 0xFFFFFFFC | 2;
          streamflag = streamflag & 0xFFFFFF7C | 0x80;
        }
      }
    }
LABEL_49:
    v10 = *++v9;
    if ( *v9 == 0 )
      break;
  }
  if ( filedes == 0 )
    goto LABEL_62;
  while ( *v9 == 32 )
    ++v9;
  if ( _mbsnbcmp(s1: "ccs=", s2: v9, n: 4u) != 0 )
    goto LABEL_64;
  v9 += 4;
  if ( _mbsicmp(s1: v9, s2: "UTF-8") == 0 )
  {
    v9 += 5;
    modeflag |= 0x40000u;
    goto LABEL_62;
  }
  if ( _mbsicmp(s1: v9, s2: "UTF-16LE") == 0 )
  {
    v9 += 8;
    modeflag |= 0x20000u;
    goto LABEL_62;
  }
  if ( _mbsicmp(s1: v9, s2: "UNICODE") != 0 )
    goto LABEL_64;
  v9 += 7;
  modeflag |= 0x10000u;
LABEL_62:
  while ( *v9 == 32 )
    ++v9;
  if ( *v9 != 0 )
  {
LABEL_64:
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: (unsigned int)v9);
    return nullptr;
  }
  if ( _sopen_s(pfh: &filedes, path: filename, oflag: modeflag, shflag, pmode: 384) != 0 )
    return nullptr;
  ++_cflush;
  str->_flag = streamflag;
  v20 = filedes;
  str->_cnt = 0;
  str->_ptr = nullptr;
  str->_base = nullptr;
  str->_tmpfname = nullptr;
  str->_file = v20;
  return str;
}

//------------------------------------------------------------------------------
// Address: 0x004D4F8F
// Name: __getstream
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _getstream()
{
  _DWORD *v0; // edi
  int i; // esi
  void **v2; // eax
  int v3; // eax
  int v4; // esi

  v0 = nullptr;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
    if ( *v2 == nullptr )
    {
      v4 = i;
      __piob[v4] = MemAlloc_Alloc(nSize: 0x38u);
      if ( __piob[v4] != nullptr )
      {
        if ( __crtInitCritSecAndSpinCount(
               a1: 0,
               lpCriticalSection: (_RTL_CRITICAL_SECTION *)((char *)__piob[v4] + 32),
               dwSpinCount: 0xFA0u) )
        {
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[v4] + 32));
          v0 = __piob[v4];
        }
        else
        {
          free(pMem: __piob[v4]);
          __piob[v4] = nullptr;
        }
      }
      break;
    }
    v3 = *((_DWORD *)*v2 + 3);
    if ( (v3 & 0x83) == 0 && (v3 & 0x8000u) == 0 )
    {
      if ( (unsigned int)(i - 3) <= 0x10 && _mtinitlocknum(locknum: i + 16) == 0 )
        break;
      _lock_file2(i, s: (char *)__piob[i]);
      if ( (*((_BYTE *)__piob[i] + 12) & 0x83) == 0 )
      {
        v0 = __piob[i];
        break;
      }
      _unlock_file2(i, s: (char *)__piob[i]);
    }
  }
  if ( v0 != nullptr )
  {
    v0[3] &= 0x8000u;
    v0[1] = 0;
    v0[2] = 0;
    *v0 = 0;
    v0[7] = 0;
    v0[4] = -1;
  }
  _unlock(locknum: 1);
  return (_iobuf *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x004D50C0
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-8h] [ebp-28h]
  int (__cdecl *v8)(int, int, int, int); // [esp-4h] [ebp-24h]

  v8 = unwind_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 == -2 || a3 != -2 && v4 <= a3 )
      break;
    v5 = 3 * v4;
    v6 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 0x10);
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: 1, a2: ExceptionList, a3: v8);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D5150
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind4(a1: *(_DWORD **)(a2 + 20), a2: *(_DWORD *)(a2 + 16), a3: *(_DWORD *)(a2 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D5196
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x004D51B2
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x004D51C9
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004D51E2
// Name: _EH4_GlobalUnwind(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _EH4_GlobalUnwind(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint_0, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D51FC
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x004D5213
// Name: __mbctoupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctoupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x20) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         plocinfo: &_loc_update.localeinfo,
         Locale: _loc_update.localeinfo.mbcinfo->mblcid,
         dwMapFlags: 0x200u,
         lpSrcStr: val,
         cchSrc: 2,
         lpDestStr: (char *)ret,
         cchDest: 2,
         code_page: _loc_update.localeinfo.mbcinfo->mbcodepage,
         bError: 1) != 0 )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x004D52B7
// Name: __mbctoupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctoupper(unsigned int c)
{
  return _mbctoupper_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D52D0
// Name: _inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall inc@<eax>(_iobuf *fileptr@<edx>, unsigned int a2@<ebx>)
{
  if ( --fileptr->_cnt < 0 )
    return _filbuf(a1: a2, str: fileptr);
  return *(unsigned __int8 *)fileptr->_ptr++;
}

//------------------------------------------------------------------------------
// Address: 0x004D52E6
// Name: _whiteout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall whiteout@<eax>(int *counter@<esi>, unsigned int a2@<ebx>, _iobuf *fileptr)
{
  do
  {
    ++*counter;
    a2 = inc(fileptr, a2);
  }
  while ( a2 != -1 && isspace(c: (unsigned __int8)a2) != 0 );
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x004D530B
// Name: __input_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_l(_iobuf *stream, const unsigned __int8 *format, localeinfo_struct *plocinfo, char *arglist)
{
  int v4; // ebx
  const unsigned __int8 *v5; // edi
  int result; // eax
  ioinfo *v7; // eax
  ioinfo *v8; // eax
  unsigned __int8 v9; // al
  const unsigned __int8 *v10; // edi
  unsigned int v11; // eax
  _WORD *v12; // esi
  int v13; // ebx
  unsigned __int8 v14; // cl
  unsigned __int8 *v15; // eax
  unsigned __int8 v16; // al
  int v17; // eax
  int v18; // edi
  int i; // eax
  int v20; // eax
  int v21; // eax
  int j; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int k; // eax
  int v27; // eax
  void (__cdecl *v28)(int, void *, char *, _LocaleUpdate *); // eax
  _WORD *v29; // edi
  int v30; // eax
  int v31; // eax
  const unsigned __int8 *v32; // edi
  const unsigned __int8 *v33; // esi
  unsigned __int8 v34; // dl
  unsigned __int8 v35; // cl
  unsigned __int8 v36; // al
  unsigned int v37; // edi
  int v38; // edx
  unsigned __int8 v39; // al
  int v40; // eax
  unsigned int v41; // esi
  int v42; // edi
  int v43; // eax
  int v44; // eax
  int v45; // ecx
  bool v46; // zf
  int v47; // [esp-10h] [ebp-8Ch]
  void *v48; // [esp-Ch] [ebp-88h]
  char *v49; // [esp-8h] [ebp-84h]
  char *arglistsave; // [esp+Ch] [ebp-70h]
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-6Ch] BYREF
  int wctemp; // [esp+20h] [ebp-5Ch] BYREF
  char *v53; // [esp+24h] [ebp-58h]
  unsigned int number; // [esp+28h] [ebp-54h]
  char temp[4]; // [esp+2Ch] [ebp-50h] BYREF
  unsigned int nFloatStrSz; // [esp+30h] [ebp-4Ch] BYREF
  int integer64; // [esp+34h] [ebp-48h]
  int malloc_FloatStrFlag; // [esp+38h] [ebp-44h] BYREF
  unsigned __int8 prevchar; // [esp+3Fh] [ebp-3Dh]
  int count; // [esp+40h] [ebp-3Ch]
  void *pointer; // [esp+44h] [ebp-38h]
  unsigned __int64 num64; // [esp+48h] [ebp-34h]
  int widthset; // [esp+50h] [ebp-2Ch]
  const unsigned __int8 *v64; // [esp+54h] [ebp-28h]
  char *pFloatStr; // [esp+58h] [ebp-24h] BYREF
  int comchr; // [esp+5Ch] [ebp-20h]
  int started; // [esp+60h] [ebp-1Ch]
  char decimal; // [esp+64h] [ebp-18h]
  char negative; // [esp+65h] [ebp-17h]
  char fl_wchar_arg; // [esp+66h] [ebp-16h]
  char match; // [esp+67h] [ebp-15h]
  _iobuf *fileptr; // [esp+68h] [ebp-14h]
  char longone; // [esp+6Eh] [ebp-Eh]
  char suppress; // [esp+6Fh] [ebp-Dh]
  int width; // [esp+70h] [ebp-Ch]
  char widechar; // [esp+77h] [ebp-5h]
  int v77; // [esp+78h] [ebp-4h]
  char done_flag; // [esp+7Fh] [ebp+3h]
  int charcount; // [esp+80h] [ebp+4h] BYREF
  char floatstring[352]; // [esp+84h] [ebp+8h] BYREF
  char AsciiTable[32]; // [esp+1E4h] [ebp+168h] BYREF

  v4 = 0;
  v5 = format;
  v53 = arglist;
  fileptr = stream;
  v64 = format;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  v77 = 0;
  if ( format != nullptr && stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
      goto LABEL_16;
    if ( _fileno(a1: 0, a2: (unsigned int)format, stream) == -1
      || _fileno(a1: 0, a2: (unsigned int)format, stream) == -2 )
    {
      v7 = &__badioinfo;
    }
    else
    {
      v5 = (const unsigned __int8 *)(4 * (_fileno(a1: 0, a2: (unsigned int)format, stream) >> 5) + 6326944);
      v7 = (ioinfo *)(*(_DWORD *)v5 + 56 * (_fileno(a1: 0, a2: (unsigned int)v5, stream) & 0x1F));
    }
    if ( (*((_BYTE *)v7 + 36) & 0x7F) == 0 )
    {
      if ( _fileno(a1: 0, a2: (unsigned int)v5, stream) == -1 || _fileno(a1: 0, a2: (unsigned int)v5, stream) == -2 )
      {
        v8 = &__badioinfo;
      }
      else
      {
        v5 = (const unsigned __int8 *)(4 * (_fileno(a1: 0, a2: (unsigned int)v5, stream) >> 5) + 6326944);
        v8 = (ioinfo *)(*(_DWORD *)v5 + 56 * (_fileno(a1: 0, a2: (unsigned int)v5, stream) & 0x1F));
      }
      if ( *((char *)v8 + 36) >= 0 )
      {
        v5 = v64;
LABEL_16:
        _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
        v9 = *v5;
        v46 = *v5 == 0;
        match = 0;
        charcount = 0;
        count = 0;
        if ( v46 )
          goto LABEL_289;
        v10 = v64;
        while ( 2 )
        {
          if ( isspace(c: v9) != 0 )
          {
            --charcount;
            v11 = whiteout(counter: &charcount, a2: v4, fileptr);
            if ( v11 != -1 )
              _ungetc_nolock(ch: v11, str: fileptr);
            do
              ++v10;
            while ( isspace(c: *v10) != 0 );
            goto LABEL_273;
          }
          if ( *v10 != 37 )
          {
            ++charcount;
            v4 = inc(fileptr, a2: v4);
            v43 = *v10++;
            v77 = v4;
            v64 = v10;
            if ( v43 == v4 )
            {
              if ( isleadbyte(c: v4) == 0 )
                goto LABEL_269;
              ++charcount;
              v44 = inc(fileptr, a2: v4);
              v45 = *v10++;
              v64 = v10;
              if ( v45 == v44 )
              {
                --charcount;
                goto LABEL_269;
              }
              if ( v44 != -1 )
                _ungetc_nolock(ch: v44, str: fileptr);
            }
            v46 = v4 == -1;
            goto LABEL_279;
          }
          number = 0;
          prevchar = 0;
          started = 0;
          widthset = 0;
          width = 0;
          decimal = 0;
          negative = 0;
          suppress = 0;
          done_flag = 0;
          fl_wchar_arg = 0;
          widechar = 0;
          longone = 1;
          integer64 = 0;
          v12 = nullptr;
          do
          {
            v13 = *++v10;
            if ( isdigit(c: (unsigned __int8)v13) != 0 )
            {
              ++widthset;
              width = 10 * width + v13 - 48;
              continue;
            }
            if ( v13 > 78 )
            {
              if ( v13 == 104 )
              {
                --longone;
                --widechar;
              }
              else
              {
                if ( v13 == 108 )
                {
                  v15 = (unsigned __int8 *)(v10 + 1);
                  if ( v10[1] == 108 )
                    goto LABEL_36;
                  ++longone;
                }
                else if ( v13 != 119 )
                {
                  goto DEFAULT_LABEL;
                }
                ++widechar;
              }
            }
            else
            {
              switch ( v13 )
              {
                case 'N':
                  continue;
                case '*':
                  ++suppress;
                  continue;
                case 'F':
                  continue;
                default:
                  break;
              }
              if ( v13 != 73 )
              {
                if ( v13 == 76 )
                {
                  ++longone;
                  continue;
                }
DEFAULT_LABEL:
                ++done_flag;
                continue;
              }
              v14 = v10[1];
              if ( v14 == 54 )
              {
                v15 = (unsigned __int8 *)(v10 + 2);
                if ( v10[2] == 52 )
                {
LABEL_36:
                  ++integer64;
                  v10 = v15;
                  num64 = 0;
                  continue;
                }
              }
              if ( v14 == 51 && v10[2] == 50 )
              {
                v10 += 2;
                continue;
              }
              if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 120 && v14 != 88 )
                goto DEFAULT_LABEL;
            }
          }
          while ( done_flag == 0 );
          v64 = v10;
          if ( suppress == 0 )
          {
            v12 = *(_WORD **)v53;
            arglistsave = v53;
            v53 += 4;
          }
          pointer = v12;
          done_flag = 0;
          if ( widechar == 0 )
          {
            v16 = *v10;
            if ( *v10 == 83 || (widechar = -1, v16 == 67) )
              widechar = 1;
          }
          comchr = *v10 | 0x20;
          v4 = comchr;
          if ( comchr != 110 )
          {
            if ( comchr == 99 || comchr == 123 )
            {
              ++charcount;
              v17 = inc(fileptr, a2: comchr);
            }
            else
            {
              v17 = whiteout(counter: &charcount, a2: comchr, fileptr);
            }
            v77 = v17;
            if ( v17 == -1 )
              goto error_return_0;
            v12 = pointer;
            v10 = v64;
          }
          if ( widthset != 0 && width == 0 )
            goto LABEL_275;
          if ( v4 > 111 )
          {
            switch ( v4 )
            {
              case 'p':
                longone = 1;
                break;
              case 's':
LABEL_127:
                if ( widechar > 0 )
                  fl_wchar_arg = 1;
                goto scanit;
              case 'u':
                break;
              case 'x':
                goto LABEL_82;
              case '{':
                if ( widechar > 0 )
                  fl_wchar_arg = 1;
                v32 = v10 + 1;
                v33 = v32;
                if ( *v32 == 94 )
                {
                  v33 = v32 + 1;
                  decimal = -1;
                }
                memset(dst: (int)AsciiTable, value: nullptr, count: sizeof(AsciiTable));
                if ( *v33 == 93 )
                {
                  v34 = 93;
                  ++v33;
                  AsciiTable[11] = 32;
                }
                else
                {
                  v34 = prevchar;
                }
                while ( 1 )
                {
                  v39 = *v33;
                  if ( *v33 == 93 )
                    break;
                  ++v33;
                  if ( v39 == 45 && v34 != 0 && (v35 = *v33, *v33 != 93) )
                  {
                    ++v33;
                    if ( v34 >= v35 )
                    {
                      v36 = v34;
                      v34 = v35;
                    }
                    else
                    {
                      v36 = v35;
                    }
                    if ( v34 <= v36 )
                    {
                      v37 = v34;
                      v38 = (unsigned __int8)(v36 - v34 + 1);
                      do
                      {
                        AsciiTable[v37 >> 3] |= 1 << (v37 & 7);
                        ++v37;
                        --v38;
                      }
                      while ( v38 != 0 );
                      v4 = comchr;
                    }
                    v34 = 0;
                  }
                  else
                  {
                    v34 = v39;
                    AsciiTable[v39 >> 3] |= 1 << (v39 & 7);
                    v4 = comchr;
                  }
                }
                v64 = v33;
                v12 = pointer;
scanit:
                --charcount;
                v29 = v12;
                if ( v77 != -1 )
                  _ungetc_nolock(ch: v77, str: fileptr);
                while ( 1 )
                {
                  if ( widthset != 0 )
                  {
                    v30 = width--;
                    if ( v30 == 0 )
                      goto LABEL_200;
                  }
                  ++charcount;
                  v31 = inc(fileptr, a2: v4);
                  v77 = v31;
                  if ( v31 == -1 )
                    goto LABEL_198;
                  if ( v4 != 99 )
                  {
                    if ( v4 != 115 )
                      goto LABEL_294;
                    if ( v31 >= 9 && v31 <= 13 )
                    {
LABEL_198:
                      --charcount;
                      if ( v31 != -1 )
                        _ungetc_nolock(ch: v31, str: fileptr);
LABEL_200:
                      if ( v29 != v12 )
                      {
                        if ( suppress == 0 )
                        {
                          ++count;
                          if ( v4 != 99 )
                          {
                            if ( fl_wchar_arg != 0 )
                              *(_WORD *)pointer = 0;
                            else
                              *(_BYTE *)pointer = 0;
                          }
                        }
                        goto LABEL_264;
                      }
                      goto error_return_0;
                    }
                    if ( v31 == 32 )
                    {
LABEL_294:
                      if ( v4 != 123 )
                        goto LABEL_198;
                      v4 = comchr;
                      if ( ((1 << (v31 & 7)) & (decimal ^ AsciiTable[v31 >> 3])) == 0 )
                        goto LABEL_198;
                    }
                  }
                  if ( suppress != 0 )
                  {
                    v29 = (_WORD *)((char *)v29 + 1);
                  }
                  else
                  {
                    if ( fl_wchar_arg != 0 )
                    {
                      temp[0] = v31;
                      if ( isleadbyte(c: v31) != 0 )
                      {
                        ++charcount;
                        temp[1] = inc(fileptr, a2: v4);
                      }
                      wctemp = 63;
                      _mbtowc_l(
                        pwc: (wchar_t *)&wctemp,
                        s: temp,
                        n: _loc_update.localeinfo.locinfo->mb_cur_max,
                        plocinfo: &_loc_update.localeinfo);
                      *v12++ = wctemp;
                    }
                    else
                    {
                      *(_BYTE *)v12 = v31;
                      v12 = (_WORD *)((char *)v12 + 1);
                    }
                    pointer = v12;
                  }
                }
              default:
                goto LABEL_151;
            }
LABEL_207:
            v4 = v77;
            if ( v77 == 45 )
            {
              negative = 1;
            }
            else if ( v77 != 43 )
            {
              goto getnum;
            }
            if ( --width == 0 && widthset != 0 )
            {
              done_flag = 1;
              goto getnum;
            }
            ++charcount;
            v4 = inc(fileptr, a2: v77);
            goto LABEL_214;
          }
          switch ( v4 )
          {
            case 'o':
              goto LABEL_207;
            case 'c':
              if ( widthset == 0 )
              {
                ++width;
                widthset = 1;
              }
              goto LABEL_127;
            case 'd':
              goto LABEL_207;
            default:
              break;
          }
          if ( v4 <= 100 )
            goto LABEL_151;
          if ( v4 <= 103 )
          {
            v4 = 0;
            if ( v77 == 45 )
            {
              *pFloatStr = 45;
              v4 = 1;
              goto f_incwidth;
            }
            if ( v77 == 43 )
            {
f_incwidth:
              --width;
              ++charcount;
              v77 = inc(fileptr, a2: v4);
            }
            if ( widthset == 0 )
              width = -1;
            for ( i = (unsigned __int8)v77; isdigit(c: i) != 0; i = (unsigned __int8)v77 )
            {
              v20 = width--;
              if ( v20 == 0 )
                break;
              ++started;
              pFloatStr[v4] = v77;
              if ( _check_float_string(
                     nFloatStrUsed: ++v4,
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_0;
              ++charcount;
              v77 = inc(fileptr, a2: v4);
            }
            decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
            if ( decimal == (_BYTE)v77 )
            {
              v21 = width--;
              if ( v21 != 0 )
              {
                ++charcount;
                v77 = inc(fileptr, a2: v4);
                pFloatStr[v4] = decimal;
                if ( _check_float_string(
                       nFloatStrUsed: ++v4,
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return_0;
                for ( j = (unsigned __int8)v77; isdigit(c: j) != 0; j = (unsigned __int8)v77 )
                {
                  v23 = width--;
                  if ( v23 == 0 )
                    break;
                  ++started;
                  pFloatStr[v4] = v77;
                  if ( _check_float_string(
                         nFloatStrUsed: ++v4,
                         pnFloatStrSz: &nFloatStrSz,
                         &pFloatStr,
                         floatstring,
                         pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                    goto error_return_0;
                  ++charcount;
                  v77 = inc(fileptr, a2: v4);
                }
              }
            }
            if ( started != 0 && (v77 == 101 || v77 == 69) )
            {
              v24 = width--;
              if ( v24 != 0 )
              {
                pFloatStr[v4] = 101;
                if ( _check_float_string(
                       nFloatStrUsed: ++v4,
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return_0;
                ++charcount;
                v77 = inc(fileptr, a2: v4);
                if ( v77 == 45 )
                {
                  pFloatStr[v4] = 45;
                  if ( _check_float_string(
                         nFloatStrUsed: ++v4,
                         pnFloatStrSz: &nFloatStrSz,
                         &pFloatStr,
                         floatstring,
                         pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                    goto error_return_0;
f_incwidth2:
                  v25 = width--;
                  if ( v25 != 0 )
                  {
                    ++charcount;
                    v77 = inc(fileptr, a2: v4);
                  }
                  else
                  {
                    width = 0;
                  }
                }
                else if ( v77 == 43 )
                {
                  goto f_incwidth2;
                }
                for ( k = (unsigned __int8)v77; isdigit(c: k) != 0; k = (unsigned __int8)v77 )
                {
                  v27 = width--;
                  if ( v27 == 0 )
                    break;
                  ++started;
                  pFloatStr[v4] = v77;
                  if ( _check_float_string(
                         nFloatStrUsed: ++v4,
                         pnFloatStrSz: &nFloatStrSz,
                         &pFloatStr,
                         floatstring,
                         pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                    goto error_return_0;
                  ++charcount;
                  v77 = inc(fileptr, a2: v4);
                }
              }
            }
            --charcount;
            if ( v77 != -1 )
              _ungetc_nolock(ch: v77, str: fileptr);
            if ( started != 0 )
            {
              if ( suppress == 0 )
              {
                ++count;
                v49 = pFloatStr;
                v48 = pointer;
                pFloatStr[v4] = 0;
                v47 = longone - 1;
                v28 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))_decode_pointer(codedptr: off_5C03BC);
                v28(a1: v47, a2: v48, a3: v49, a4: &_loc_update);
              }
              goto LABEL_264;
            }
            goto error_return_0;
          }
          if ( v4 != 105 )
          {
            if ( v4 == 110 )
            {
              v18 = charcount;
              if ( suppress == 0 )
              {
assign_num:
                if ( integer64 != 0 )
                {
                  *(_QWORD *)v12 = num64;
                }
                else if ( longone != 0 )
                {
                  *(_DWORD *)v12 = v18;
                }
                else
                {
                  *v12 = v18;
                }
              }
              goto LABEL_264;
            }
LABEL_151:
            if ( *v10 == v77 )
            {
              --match;
              if ( suppress == 0 )
                v53 = arglistsave;
              goto LABEL_264;
            }
LABEL_275:
            v46 = v77 == -1;
LABEL_279:
            if ( !v46 )
              _ungetc_nolock(ch: v77, str: fileptr);
            goto error_return_0;
          }
          comchr = 100;
LABEL_82:
          v4 = v77;
          if ( v77 == 45 )
          {
            negative = 1;
            goto x_incwidth;
          }
          if ( v77 == 43 )
          {
x_incwidth:
            if ( --width != 0 || widthset == 0 )
            {
              ++charcount;
              v4 = inc(fileptr, a2: v77);
              v77 = v4;
            }
            else
            {
              done_flag = 1;
            }
          }
          if ( v4 == 48 )
          {
            ++charcount;
            v40 = inc(fileptr, a2: 0x30u);
            v4 = v40;
            v77 = v40;
            if ( (_BYTE)v40 != 120 && (_BYTE)v40 != 88 )
            {
              started = 1;
              if ( comchr != 120 )
              {
                if ( widthset != 0 && --width == 0 )
                  ++done_flag;
                comchr = 111;
                goto getnum;
              }
              --charcount;
              if ( v40 != -1 )
                _ungetc_nolock(ch: v40, str: fileptr);
              v4 = 48;
LABEL_214:
              v77 = v4;
              goto getnum;
            }
            ++charcount;
            v4 = inc(fileptr, a2: v40);
            v77 = v4;
            if ( widthset != 0 )
            {
              width -= 2;
              if ( width < 1 )
                ++done_flag;
            }
            comchr = 120;
          }
getnum:
          if ( integer64 == 0 )
          {
            v18 = number;
            if ( done_flag == 0 )
            {
              while ( 1 )
              {
                if ( comchr == 120 || comchr == 112 )
                {
                  if ( isxdigit(c: (unsigned __int8)v4) == 0 )
                  {
LABEL_250:
                    --charcount;
                    if ( v4 != -1 )
                      _ungetc_nolock(ch: v4, str: fileptr);
                    break;
                  }
                  v42 = 16 * v18;
                  v4 = (char)v4;
                  if ( isdigit(c: (unsigned __int8)v4) == 0 )
                    v4 = ((char)v4 & 0xFFFFFFDF) - 7;
                  v77 = v4;
                }
                else
                {
                  if ( isdigit(c: (unsigned __int8)v4) == 0 )
                    goto LABEL_250;
                  if ( comchr == 111 )
                  {
                    if ( v4 >= 56 )
                      goto LABEL_250;
                    v42 = 8 * v18;
                  }
                  else
                  {
                    v42 = 10 * v18;
                  }
                }
                ++started;
                v18 = v42 + v4 - 48;
                if ( widthset != 0 && --width == 0 )
                  break;
                ++charcount;
                v4 = inc(fileptr, a2: v4);
                v77 = v4;
              }
            }
            if ( negative != 0 )
              v18 = -v18;
            goto LABEL_254;
          }
          if ( done_flag != 0 )
            goto LABEL_233;
          while ( 2 )
          {
            if ( comchr != 120 && comchr != 112 )
            {
              if ( isdigit(c: (unsigned __int8)v4) == 0 )
                break;
              if ( comchr == 111 )
              {
                if ( v4 >= 56 )
                  break;
                v41 = 8 * num64;
                HIDWORD(num64) = num64 >> 29;
              }
              else
              {
                HIDWORD(num64) = (10 * num64) >> 32;
                v41 = 10 * num64;
              }
              goto LABEL_228;
            }
            if ( isxdigit(c: (unsigned __int8)v4) != 0 )
            {
              v41 = 16 * num64;
              HIDWORD(num64) = num64 >> 28;
              v4 = (char)v4;
              if ( isdigit(c: (unsigned __int8)v4) == 0 )
                v4 = ((char)v4 & 0xFFFFFFDF) - 7;
              v77 = v4;
LABEL_228:
              ++started;
              num64 = v4 - 48 + __PAIR64__(HIDWORD(num64), v41);
              if ( widthset != 0 && --width == 0 )
                goto LABEL_233;
              ++charcount;
              v4 = inc(fileptr, a2: v4);
              v77 = v4;
              continue;
            }
            break;
          }
          --charcount;
          if ( v4 != -1 )
            _ungetc_nolock(ch: v4, str: fileptr);
LABEL_233:
          v18 = number;
          if ( negative != 0 )
            num64 = -(__int64)num64;
LABEL_254:
          if ( comchr == 70 )
            started = 0;
          if ( started == 0 )
            goto error_return_0;
          if ( suppress == 0 )
          {
            ++count;
            v12 = pointer;
            goto assign_num;
          }
LABEL_264:
          ++match;
          v10 = ++v64;
LABEL_269:
          if ( v77 != -1 )
          {
LABEL_273:
            v9 = *v10;
            if ( *v10 == 0 )
              goto error_return_0;
            continue;
          }
          break;
        }
        if ( *v10 == 37 && v64[1] == 110 )
        {
          v10 = v64;
          goto LABEL_273;
        }
error_return_0:
        if ( malloc_FloatStrFlag == 1 )
          free(pMem: pFloatStr);
        if ( v77 == -1 )
        {
          result = count;
          if ( count == 0 && match == 0 )
            result = -1;
          if ( _loc_update.updated )
            _loc_update.ptd->_ownlocale &= ~2u;
          return result;
        }
LABEL_289:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return count;
      }
    }
  }
  *_errno() = 22;
  _invalid_parameter(a1: 0, a2: (unsigned int)v5, a3: (unsigned int)stream);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004D5F58
// Name: __check_float_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _check_float_string@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        char **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        char *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  char *v6; // eax
  char *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = (char *)calloc(count: v5, size: 2u);
      *pFloatStr = v6;
      if ( v6 == nullptr )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy(dst: (unsigned __int8 *)*pFloatStr, src: (unsigned __int8 *)floatstring, count: *pnFloatStrSz);
    }
    else
    {
      v8 = (char *)_recalloc_crt(ptr: *pFloatStr, count: v5, size: 2u);
      if ( v8 == nullptr )
        return 0;
      *pFloatStr = v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D5FAC
// Name: __input_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_s_l(_iobuf *stream, const unsigned __int8 *format, localeinfo_struct *plocinfo, char *arglist)
{
  signed int v4; // ebx
  signed int p_pFloatStr; // edi
  int result; // eax
  ioinfo *v7; // eax
  ioinfo *v8; // eax
  unsigned __int8 v9; // al
  unsigned int v10; // eax
  unsigned int p_charcount; // esi
  int v12; // ebx
  char v13; // cl
  unsigned int v14; // eax
  unsigned __int8 v15; // al
  int v16; // eax
  unsigned int v17; // eax
  bool v18; // cf
  unsigned int v19; // eax
  int i; // eax
  int v21; // eax
  int v22; // eax
  int j; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int k; // eax
  int v28; // eax
  void (__cdecl *v29)(int, void *, char *, _LocaleUpdate *); // eax
  int v30; // eax
  int v31; // eax
  const unsigned __int8 *v32; // esi
  unsigned __int8 v33; // dl
  unsigned __int8 v34; // cl
  unsigned __int8 v35; // al
  unsigned int v36; // edi
  int v37; // edx
  unsigned __int8 v38; // al
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // ecx
  bool v43; // zf
  int *v44; // eax
  int v45; // [esp-10h] [ebp-8Ch]
  void *v46; // [esp-Ch] [ebp-88h]
  char *v47; // [esp-8h] [ebp-84h]
  int v48; // [esp-4h] [ebp-80h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-70h] BYREF
  int format_error; // [esp+1Ch] [ebp-60h]
  int wctemp; // [esp+20h] [ebp-5Ch] BYREF
  char *arglistsave; // [esp+24h] [ebp-58h]
  int comchr; // [esp+28h] [ebp-54h]
  char *v54; // [esp+2Ch] [ebp-50h]
  char temp[4]; // [esp+30h] [ebp-4Ch] BYREF
  int integer64; // [esp+34h] [ebp-48h]
  unsigned int nFloatStrSz; // [esp+38h] [ebp-44h] BYREF
  unsigned __int8 prevchar; // [esp+3Fh] [ebp-3Dh]
  int malloc_FloatStrFlag; // [esp+40h] [ebp-3Ch] BYREF
  unsigned int array_width; // [esp+44h] [ebp-38h]
  int count; // [esp+48h] [ebp-34h]
  int widthset; // [esp+4Ch] [ebp-30h]
  void *pointer; // [esp+50h] [ebp-2Ch]
  unsigned int number; // [esp+54h] [ebp-28h]
  unsigned __int64 num64; // [esp+58h] [ebp-24h]
  const unsigned __int8 *v66; // [esp+60h] [ebp-1Ch]
  int started; // [esp+64h] [ebp-18h]
  char *pFloatStr; // [esp+68h] [ebp-14h] BYREF
  char negative; // [esp+6Ch] [ebp-10h]
  char decimal; // [esp+6Dh] [ebp-Fh]
  char match; // [esp+6Eh] [ebp-Eh]
  char fl_wchar_arg; // [esp+6Fh] [ebp-Dh]
  _iobuf *fileptr; // [esp+70h] [ebp-Ch]
  char longone; // [esp+77h] [ebp-5h]
  int width; // [esp+78h] [ebp-4h]
  char suppress; // [esp+7Eh] [ebp+2h]
  char widechar; // [esp+7Fh] [ebp+3h]
  int v78; // [esp+80h] [ebp+4h]
  char done_flag; // [esp+87h] [ebp+Bh]
  int charcount; // [esp+88h] [ebp+Ch] BYREF
  char floatstring[352]; // [esp+8Ch] [ebp+10h] BYREF
  char AsciiTable[32]; // [esp+1ECh] [ebp+170h] BYREF

  v4 = 0;
  p_pFloatStr = (signed int)format;
  v54 = arglist;
  fileptr = stream;
  v66 = format;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  v78 = 0;
  format_error = 0;
  if ( format == nullptr || stream == nullptr )
    goto LABEL_2;
  if ( (stream->_flag & 0x40) == 0 )
  {
    if ( _fileno(a1: 0, a2: (unsigned int)format, stream) == -1
      || _fileno(a1: 0, a2: (unsigned int)format, stream) == -2 )
    {
      v7 = &__badioinfo;
    }
    else
    {
      p_pFloatStr = 4 * (_fileno(a1: 0, a2: (unsigned int)format, stream) >> 5) + 6326944;
      v7 = (ioinfo *)(*(_DWORD *)p_pFloatStr + 56 * (_fileno(a1: 0, a2: p_pFloatStr, stream) & 0x1F));
    }
    if ( (*((_BYTE *)v7 + 36) & 0x7F) == 0 )
    {
      if ( _fileno(a1: 0, a2: p_pFloatStr, stream) == -1 || _fileno(a1: 0, a2: p_pFloatStr, stream) == -2 )
      {
        v8 = &__badioinfo;
      }
      else
      {
        p_pFloatStr = 4 * (_fileno(a1: 0, a2: p_pFloatStr, stream) >> 5) + 6326944;
        v8 = (ioinfo *)(*(_DWORD *)p_pFloatStr + 56 * (_fileno(a1: 0, a2: p_pFloatStr, stream) & 0x1F));
      }
      if ( *((char *)v8 + 36) >= 0 )
      {
        p_pFloatStr = (signed int)v66;
        goto LABEL_16;
      }
    }
LABEL_2:
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: p_pFloatStr, a3: (unsigned int)stream);
    return -1;
  }
LABEL_16:
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v9 = *(_BYTE *)p_pFloatStr;
  v43 = *(_BYTE *)p_pFloatStr == 0;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v43 )
    goto LABEL_309;
  while ( 2 )
  {
    if ( isspace(c: v9) != 0 )
    {
      --charcount;
      v10 = whiteout(counter: &charcount, a2: v4, fileptr);
      if ( v10 != -1 )
        _ungetc_nolock(ch: v10, str: fileptr);
      p_charcount = (unsigned int)v66;
      do
        ++p_charcount;
      while ( isspace(c: *(unsigned __int8 *)p_charcount) != 0 );
      v66 = (const unsigned __int8 *)p_charcount;
      goto LABEL_281;
    }
    p_charcount = (unsigned int)v66;
    if ( *v66 != 37 )
    {
      ++charcount;
      v4 = inc(fileptr, a2: v4);
      v40 = *(unsigned __int8 *)p_charcount++;
      v78 = v4;
      v66 = (const unsigned __int8 *)p_charcount;
      if ( v40 == v4 )
      {
        if ( isleadbyte(c: v4) == 0 )
          goto LABEL_277;
        ++charcount;
        v41 = inc(fileptr, a2: v4);
        v42 = *(unsigned __int8 *)p_charcount++;
        v66 = (const unsigned __int8 *)p_charcount;
        if ( v42 == v41 )
        {
          --charcount;
          goto LABEL_277;
        }
        if ( v41 != -1 )
          _ungetc_nolock(ch: v41, str: fileptr);
      }
      v43 = v4 == -1;
      goto LABEL_297;
    }
    number = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    array_width = 0;
    decimal = 0;
    negative = 0;
    suppress = 0;
    done_flag = 0;
    fl_wchar_arg = 0;
    widechar = 0;
    longone = 1;
    integer64 = 0;
    do
    {
      v12 = *(unsigned __int8 *)++p_charcount;
      if ( isdigit(c: (unsigned __int8)v12) != 0 )
      {
        ++widthset;
        width = 10 * width + v12 - 48;
        continue;
      }
      if ( v12 > 78 )
      {
        if ( v12 == 104 )
        {
          --longone;
          --widechar;
        }
        else
        {
          if ( v12 == 108 )
          {
            v14 = p_charcount + 1;
            if ( *(_BYTE *)(p_charcount + 1) == 108 )
              goto LABEL_36;
            ++longone;
          }
          else if ( v12 != 119 )
          {
            goto DEFAULT_LABEL_0;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v12 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
          default:
            break;
        }
        if ( v12 != 73 )
        {
          if ( v12 == 76 )
          {
            ++longone;
            continue;
          }
DEFAULT_LABEL_0:
          ++done_flag;
          continue;
        }
        v13 = *(_BYTE *)(p_charcount + 1);
        if ( v13 == 54 )
        {
          v14 = p_charcount + 2;
          if ( *(_BYTE *)(p_charcount + 2) == 52 )
          {
LABEL_36:
            ++integer64;
            p_charcount = v14;
            num64 = 0;
            continue;
          }
        }
        if ( v13 == 51 && *(_BYTE *)(p_charcount + 2) == 50 )
        {
          p_charcount += 2;
          continue;
        }
        if ( v13 != 100 && v13 != 105 && v13 != 111 && v13 != 120 && v13 != 88 )
          goto DEFAULT_LABEL_0;
      }
    }
    while ( done_flag == 0 );
    v66 = (const unsigned __int8 *)p_charcount;
    if ( suppress != 0 )
    {
      v4 = 0;
    }
    else
    {
      v4 = *(_DWORD *)v54;
      arglistsave = v54;
      v54 += 4;
    }
    pointer = (void *)v4;
    done_flag = 0;
    if ( widechar == 0 )
    {
      v15 = *(_BYTE *)p_charcount;
      if ( *(_BYTE *)p_charcount == 83 || (widechar = -1, v15 == 67) )
        widechar = 1;
    }
    comchr = *(unsigned __int8 *)p_charcount | 0x20;
    p_pFloatStr = comchr;
    if ( comchr != 110 )
    {
      if ( comchr == 99 || comchr == 123 )
      {
        ++charcount;
        v16 = inc(fileptr, a2: v4);
      }
      else
      {
        p_charcount = (unsigned int)&charcount;
        v16 = whiteout(counter: &charcount, a2: v4, fileptr);
      }
      v78 = v16;
      if ( v16 == -1 )
        goto error_return_1;
      v4 = (signed int)pointer;
      p_charcount = (unsigned int)v66;
      p_pFloatStr = comchr;
    }
    if ( widthset != 0 && width == 0 )
    {
      v43 = v78 == -1;
LABEL_297:
      if ( !v43 )
        _ungetc_nolock(ch: v78, str: fileptr);
      goto error_return_1;
    }
    if ( suppress == 0 && (p_pFloatStr == 99 || p_pFloatStr == 115 || p_pFloatStr == 123) )
    {
      v4 = *(_DWORD *)arglistsave;
      arglistsave += 4;
      v54 = arglistsave + 4;
      v17 = *(_DWORD *)arglistsave;
      v18 = *(_DWORD *)arglistsave == 0;
      pointer = (void *)v4;
      array_width = v17;
      if ( v18 )
      {
        if ( widechar <= 0 )
          *(_BYTE *)v4 = 0;
        else
          *(_WORD *)v4 = 0;
        *_errno() = 12;
        goto error_return_1;
      }
    }
    if ( p_pFloatStr > 111 )
    {
      if ( p_pFloatStr == 112 )
      {
        longone = 1;
        goto LABEL_217;
      }
      if ( p_pFloatStr != 115 )
      {
        if ( p_pFloatStr == 117 )
          goto LABEL_217;
        if ( p_pFloatStr == 120 )
          goto LABEL_88;
        if ( p_pFloatStr != 123 )
          goto LABEL_161;
        if ( widechar > 0 )
          fl_wchar_arg = 1;
        v32 = (const unsigned __int8 *)(p_charcount + 1);
        if ( *v32 == 94 )
        {
          ++v32;
          decimal = -1;
        }
        memset(dst: (int)AsciiTable, value: nullptr, count: sizeof(AsciiTable));
        if ( *v32 == 93 )
        {
          v33 = 93;
          ++v32;
          AsciiTable[11] = 32;
        }
        else
        {
          v33 = prevchar;
        }
        while ( 1 )
        {
          v38 = *v32;
          if ( *v32 == 93 )
            break;
          ++v32;
          if ( v38 == 45 && v33 != 0 && (v34 = *v32, *v32 != 93) )
          {
            ++v32;
            if ( v33 >= v34 )
            {
              v35 = v33;
              v33 = v34;
            }
            else
            {
              v35 = v34;
            }
            if ( v33 <= v35 )
            {
              v36 = v33;
              v37 = (unsigned __int8)(v35 - v33 + 1);
              do
              {
                AsciiTable[v36 >> 3] |= 1 << (v36 & 7);
                ++v36;
                --v37;
              }
              while ( v37 != 0 );
            }
            v33 = 0;
          }
          else
          {
            v33 = v38;
            AsciiTable[v38 >> 3] |= 1 << (v38 & 7);
          }
        }
        v4 = (signed int)pointer;
        p_pFloatStr = comchr;
        v66 = v32;
scanit_0:
        --charcount;
        p_charcount = v4;
        if ( v78 != -1 )
          _ungetc_nolock(ch: v78, str: fileptr);
        if ( p_pFloatStr == 99 )
        {
          while ( 1 )
          {
LABEL_139:
            if ( widthset != 0 )
            {
              v30 = width--;
              if ( v30 == 0 )
                goto LABEL_210;
            }
            ++charcount;
            v31 = inc(fileptr, a2: v4);
            v78 = v31;
            if ( v31 == -1 )
              goto LABEL_208;
            if ( p_pFloatStr != 99 )
            {
              if ( p_pFloatStr != 115 )
                goto LABEL_314;
              if ( v31 >= 9 && v31 <= 13 )
              {
LABEL_208:
                --charcount;
                if ( v31 != -1 )
                  _ungetc_nolock(ch: v31, str: fileptr);
LABEL_210:
                if ( p_charcount != v4 )
                {
                  if ( suppress == 0 )
                  {
                    ++count;
                    if ( comchr != 99 )
                    {
                      if ( fl_wchar_arg != 0 )
                        *(_WORD *)pointer = 0;
                      else
                        *(_BYTE *)pointer = 0;
                    }
                  }
                  goto LABEL_272;
                }
                goto error_return_1;
              }
              if ( v31 == 32 )
              {
LABEL_314:
                if ( p_pFloatStr != 123 )
                  goto LABEL_208;
                p_pFloatStr = decimal;
                if ( ((1 << (v31 & 7)) & (decimal ^ AsciiTable[v31 >> 3])) == 0 )
                  goto LABEL_208;
                p_pFloatStr = comchr;
              }
            }
            if ( suppress == 0 )
              break;
            ++p_charcount;
          }
          if ( array_width == 0 )
          {
            v44 = _errno();
            v43 = fl_wchar_arg == 0;
            *v44 = 12;
            if ( v43 )
              *(_BYTE *)p_charcount = 0;
            else
              *(_WORD *)p_charcount = 0;
            goto error_return_1;
          }
          if ( fl_wchar_arg != 0 )
          {
            temp[0] = v31;
            if ( isleadbyte(c: v31) != 0 )
            {
              ++charcount;
              temp[1] = inc(fileptr, a2: v4);
            }
            wctemp = 63;
            _mbtowc_l(
              pwc: (wchar_t *)&wctemp,
              s: temp,
              n: _loc_update.localeinfo.locinfo->mb_cur_max,
              plocinfo: &_loc_update.localeinfo);
            *(_WORD *)v4 = wctemp;
            v4 += 2;
          }
          else
          {
            *(_BYTE *)v4++ = v31;
          }
          pointer = (void *)v4;
        }
        --array_width;
        goto LABEL_139;
      }
LABEL_133:
      if ( widechar > 0 )
        fl_wchar_arg = 1;
      goto scanit_0;
    }
    if ( p_pFloatStr == 111 )
      goto LABEL_217;
    if ( p_pFloatStr == 99 )
    {
      if ( widthset == 0 )
      {
        ++width;
        widthset = 1;
      }
      goto LABEL_133;
    }
    if ( p_pFloatStr != 100 )
    {
      if ( p_pFloatStr > 100 )
      {
        if ( p_pFloatStr > 103 )
        {
          if ( p_pFloatStr != 105 )
          {
            if ( p_pFloatStr == 110 )
            {
              v19 = charcount;
              if ( suppress == 0 )
              {
assign_num_0:
                if ( integer64 != 0 )
                {
                  *(_QWORD *)v4 = num64;
                }
                else if ( longone != 0 )
                {
                  *(_DWORD *)v4 = v19;
                }
                else
                {
                  *(_WORD *)v4 = v19;
                }
              }
              goto LABEL_272;
            }
            goto LABEL_161;
          }
          p_pFloatStr = 100;
LABEL_88:
          v4 = v78;
          if ( v78 == 45 )
          {
            negative = 1;
            goto x_incwidth_0;
          }
          if ( v78 == 43 )
          {
x_incwidth_0:
            if ( --width != 0 || widthset == 0 )
            {
              ++charcount;
              v4 = inc(fileptr, a2: v78);
              v78 = v4;
            }
            else
            {
              done_flag = 1;
            }
          }
          if ( v4 == 48 )
          {
            ++charcount;
            v39 = inc(fileptr, a2: 0x30u);
            v4 = v39;
            v78 = v39;
            if ( (_BYTE)v39 == 120 || (_BYTE)v39 == 88 )
            {
              ++charcount;
              v4 = inc(fileptr, a2: v39);
              v78 = v4;
              if ( widthset != 0 )
              {
                width -= 2;
                if ( width < 1 )
                  ++done_flag;
              }
              v48 = 120;
LABEL_204:
              p_pFloatStr = v48;
            }
            else
            {
              started = 1;
              if ( p_pFloatStr != 120 )
              {
                if ( widthset != 0 && --width == 0 )
                  ++done_flag;
                v48 = 111;
                goto LABEL_204;
              }
              --charcount;
              if ( v39 != -1 )
                _ungetc_nolock(ch: v39, str: fileptr);
              v4 = 48;
LABEL_224:
              v78 = v4;
            }
          }
          goto getnum_0;
        }
        v4 = 0;
        if ( v78 == 45 )
        {
          *pFloatStr = 45;
          v4 = 1;
          goto f_incwidth_0;
        }
        if ( v78 == 43 )
        {
f_incwidth_0:
          --width;
          ++charcount;
          v78 = inc(fileptr, a2: v4);
        }
        if ( widthset == 0 )
          width = -1;
        for ( i = (unsigned __int8)v78; isdigit(c: i) != 0; i = (unsigned __int8)v78 )
        {
          v21 = width--;
          if ( v21 == 0 )
            break;
          ++started;
          pFloatStr[v4++] = v78;
          p_pFloatStr = (signed int)&pFloatStr;
          p_charcount = (unsigned int)&nFloatStrSz;
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: v4,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return_1;
          ++charcount;
          v78 = inc(fileptr, a2: v4);
        }
        decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
        if ( decimal == (_BYTE)v78 )
        {
          v22 = width--;
          if ( v22 != 0 )
          {
            ++charcount;
            v78 = inc(fileptr, a2: v4);
            pFloatStr[v4++] = decimal;
            p_pFloatStr = (signed int)&pFloatStr;
            p_charcount = (unsigned int)&nFloatStrSz;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: v4,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_1;
            for ( j = (unsigned __int8)v78; isdigit(c: j) != 0; j = (unsigned __int8)v78 )
            {
              v24 = width--;
              if ( v24 == 0 )
                break;
              ++started;
              pFloatStr[v4++] = v78;
              p_pFloatStr = (signed int)&pFloatStr;
              p_charcount = (unsigned int)&nFloatStrSz;
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: v4,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
              ++charcount;
              v78 = inc(fileptr, a2: v4);
            }
          }
        }
        if ( started != 0 && (v78 == 101 || v78 == 69) )
        {
          v25 = width--;
          if ( v25 != 0 )
          {
            pFloatStr[v4++] = 101;
            p_pFloatStr = (signed int)&pFloatStr;
            p_charcount = (unsigned int)&nFloatStrSz;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: v4,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_1;
            ++charcount;
            v78 = inc(fileptr, a2: v4);
            if ( v78 == 45 )
            {
              pFloatStr[v4] = 45;
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: ++v4,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
f_incwidth2_0:
              v26 = width--;
              if ( v26 != 0 )
              {
                ++charcount;
                v78 = inc(fileptr, a2: v4);
              }
              else
              {
                width = 0;
              }
            }
            else if ( v78 == 43 )
            {
              goto f_incwidth2_0;
            }
            for ( k = (unsigned __int8)v78; isdigit(c: k) != 0; k = (unsigned __int8)v78 )
            {
              v28 = width--;
              if ( v28 == 0 )
                break;
              ++started;
              pFloatStr[v4++] = v78;
              p_pFloatStr = (signed int)&pFloatStr;
              p_charcount = (unsigned int)&nFloatStrSz;
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: v4,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_1;
              ++charcount;
              v78 = inc(fileptr, a2: v4);
            }
          }
        }
        --charcount;
        if ( v78 != -1 )
          _ungetc_nolock(ch: v78, str: fileptr);
        if ( started != 0 )
        {
          if ( suppress == 0 )
          {
            ++count;
            v47 = pFloatStr;
            v46 = pointer;
            pFloatStr[v4] = 0;
            v45 = longone - 1;
            v29 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))_decode_pointer(codedptr: off_5C03BC);
            v29(a1: v45, a2: v46, a3: v47, a4: &_loc_update);
          }
          goto LABEL_272;
        }
        goto error_return_1;
      }
LABEL_161:
      if ( *(unsigned __int8 *)p_charcount == v78 )
      {
        --match;
        if ( suppress == 0 )
          v54 = arglistsave;
        goto LABEL_272;
      }
      if ( v78 != -1 )
        _ungetc_nolock(ch: v78, str: fileptr);
      format_error = 1;
      goto error_return_1;
    }
LABEL_217:
    v4 = v78;
    if ( v78 == 45 )
    {
      negative = 1;
    }
    else if ( v78 != 43 )
    {
      goto getnum_0;
    }
    if ( --width != 0 || widthset == 0 )
    {
      ++charcount;
      v4 = inc(fileptr, a2: v78);
      goto LABEL_224;
    }
    done_flag = 1;
getnum_0:
    if ( integer64 == 0 )
    {
      if ( done_flag == 0 )
      {
        while ( 1 )
        {
          if ( p_pFloatStr == 120 || p_pFloatStr == 112 )
          {
            p_charcount = (unsigned __int8)v4;
            if ( isxdigit(c: (unsigned __int8)v4) == 0 )
            {
LABEL_260:
              --charcount;
              if ( v4 != -1 )
                _ungetc_nolock(ch: v4, str: fileptr);
              break;
            }
            number *= 16;
            v4 = (char)v4;
            if ( isdigit(c: (unsigned __int8)v4) == 0 )
              v4 = ((char)v4 & 0xFFFFFFDF) - 7;
            v78 = v4;
          }
          else
          {
            if ( isdigit(c: (unsigned __int8)v4) == 0 )
              goto LABEL_260;
            if ( p_pFloatStr == 111 )
            {
              if ( v4 >= 56 )
                goto LABEL_260;
              number *= 8;
            }
            else
            {
              number *= 10;
            }
          }
          ++started;
          number = number + v4 - 48;
          if ( widthset != 0 && --width == 0 )
            break;
          ++charcount;
          v4 = inc(fileptr, a2: v4);
          v78 = v4;
        }
      }
      if ( negative != 0 )
        number = -number;
      goto LABEL_264;
    }
    if ( done_flag != 0 )
      goto LABEL_243;
    while ( 2 )
    {
      if ( p_pFloatStr != 120 && p_pFloatStr != 112 )
      {
        if ( isdigit(c: (unsigned __int8)v4) == 0 )
          break;
        if ( p_pFloatStr == 111 )
        {
          if ( v4 >= 56 )
            break;
          num64 *= 8LL;
        }
        else
        {
          num64 *= 10LL;
        }
        goto LABEL_238;
      }
      p_charcount = (unsigned __int8)v4;
      if ( isxdigit(c: (unsigned __int8)v4) != 0 )
      {
        num64 *= 16LL;
        v4 = (char)v4;
        if ( isdigit(c: (unsigned __int8)v4) == 0 )
          v4 = ((char)v4 & 0xFFFFFFDF) - 7;
        v78 = v4;
LABEL_238:
        ++started;
        num64 += v4 - 48;
        if ( widthset != 0 && --width == 0 )
          goto LABEL_243;
        ++charcount;
        v4 = inc(fileptr, a2: v4);
        v78 = v4;
        continue;
      }
      break;
    }
    --charcount;
    if ( v4 != -1 )
      _ungetc_nolock(ch: v4, str: fileptr);
LABEL_243:
    if ( negative != 0 )
      num64 = -(__int64)num64;
LABEL_264:
    if ( started == 0 )
      goto error_return_1;
    if ( suppress == 0 )
    {
      ++count;
      v4 = (signed int)pointer;
      v19 = number;
      goto assign_num_0;
    }
LABEL_272:
    ++match;
    p_charcount = (unsigned int)++v66;
LABEL_277:
    if ( v78 != -1 )
    {
LABEL_281:
      v9 = *(_BYTE *)p_charcount;
      if ( *(_BYTE *)p_charcount == 0 )
        goto error_return_1;
      continue;
    }
    break;
  }
  if ( *(_BYTE *)p_charcount == 37 && v66[1] == 110 )
  {
    p_charcount = (unsigned int)v66;
    goto LABEL_281;
  }
error_return_1:
  if ( malloc_FloatStrFlag == 1 )
    free(pMem: pFloatStr);
  if ( v78 == -1 )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( format_error == 1 )
  {
    *_errno() = 22;
    _invalid_parameter(a1: v4, a2: p_pFloatStr, a3: p_charcount);
  }
LABEL_309:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x004D6CD7
// Name: write_char_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char_0(_iobuf *f@<eax>, int *pnumwritten@<esi>, wchar_t ch)
{
  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr) && _fputwc_nolock(ch, str: f) == 0xFFFF )
    *pnumwritten = -1;
  else
    ++*pnumwritten;
}

//------------------------------------------------------------------------------
// Address: 0x004D6CFC
// Name: write_multi_char_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_multi_char_0(int *pnumwritten@<eax>, wchar_t ch, int num, _iobuf *f)
{
  do
  {
    if ( num <= 0 )
      break;
    --num;
    write_char_0(f, pnumwritten, ch);
  }
  while ( *pnumwritten != -1 );
}

//------------------------------------------------------------------------------
// Address: 0x004D6D21
// Name: write_string_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string_0(wchar_t *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      --len;
      write_char_0(f, pnumwritten, ch: *string++);
      if ( *pnumwritten == -1 )
      {
        if ( *_errno() != 42 )
          return;
        write_char_0(f, pnumwritten, ch: 0x3Fu);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D6D70
// Name: __woutput_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _woutput_l(_iobuf *stream, wchar_t *format, localeinfo_struct *plocinfo, char *argptr)
{
  int *v4; // ebx
  wchar_t *v5; // esi
  unsigned int v6; // edi
  int v8; // edx
  STATE v9; // ecx
  wchar_t *v10; // esi
  int v11; // eax
  wchar_t v12; // ax
  _woutput_l::__l2::<unnamed_tag> *p_buffer; // esi
  int v14; // edi
  char *v15; // ebx
  unsigned __int8 *j; // esi
  int v17; // eax
  __int16 *v18; // eax
  char *v19; // ecx
  int v20; // eax
  int v21; // eax
  __int64 v22; // rax
  int *v23; // ebx
  int v24; // edi
  char *v25; // eax
  int v26; // eax
  char *v27; // ebx
  void (__cdecl *v28)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *); // eax
  int v29; // ebx
  void (__cdecl *v30)(_woutput_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  void (__cdecl *v31)(_woutput_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  unsigned int v32; // ebx
  unsigned int v33; // edi
  char *i; // esi
  int v35; // eax
  int v36; // ecx
  unsigned __int64 v37; // kr08_8
  char *v38; // eax
  char *v39; // esi
  char *v40; // eax
  int v41; // esi
  int v42; // ebx
  _iobuf *v43; // edi
  char *v44; // edi
  int v45; // eax
  int v46; // [esp-14h] [ebp-A0h]
  int v47; // [esp-10h] [ebp-9Ch]
  int v48; // [esp-Ch] [ebp-98h]
  int v49; // [esp-8h] [ebp-94h]
  int retval; // [esp+10h] [ebp-7Ch]
  _CRT_DOUBLE tmp; // [esp+14h] [ebp-78h] BYREF
  int wchar; // [esp+1Ch] [ebp-70h] BYREF
  int capexp; // [esp+20h] [ebp-6Ch]
  STATE state; // [esp+24h] [ebp-68h]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-64h] BYREF
  int hexadd; // [esp+38h] [ebp-54h]
  char *heapbuf; // [esp+3Ch] [ebp-50h]
  wchar_t *v58; // [esp+40h] [ebp-4Ch]
  int no_output; // [esp+44h] [ebp-48h]
  wchar_t prefix[2]; // [esp+48h] [ebp-44h] BYREF
  char tempchar[4]; // [esp+4Ch] [ebp-40h] BYREF
  _iobuf *f; // [esp+50h] [ebp-3Ch]
  int fldwidth; // [esp+54h] [ebp-38h]
  int bufferiswide; // [esp+58h] [ebp-34h]
  int prefixlen; // [esp+5Ch] [ebp-30h]
  int charsout; // [esp+60h] [ebp-2Ch] BYREF
  char *v67; // [esp+64h] [ebp-28h]
  int count; // [esp+68h] [ebp-24h]
  int textlen; // [esp+6Ch] [ebp-20h]
  char *s; // [esp+70h] [ebp-1Ch]
  int precision; // [esp+74h] [ebp-18h]
  int flags; // [esp+78h] [ebp-14h]
  _woutput_l::__l2::<unnamed_tag> buffer; // [esp+7Ch] [ebp-10h] BYREF

  v4 = (int *)argptr;
  v5 = format;
  v6 = 0;
  f = stream;
  v67 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( f == nullptr || format == nullptr )
  {
    *_errno() = 22;
    goto LABEL_3;
  }
  v8 = *format;
  v9 = ST_NORMAL;
  charsout = 0;
  textlen = 0;
  heapbuf = nullptr;
  count = v8;
  if ( (_WORD)v8 == 0 )
  {
LABEL_210:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 2 )
  {
    v6 = 2;
    v10 = v5 + 1;
    v58 = v10;
    if ( charsout < 0 )
      goto LABEL_210;
    if ( (unsigned __int16)(v8 - 32) > 0x58u )
      v11 = 0;
    else
      v11 = byte_59EFE8[(unsigned __int16)v8] & 0xF;
    state = __lookuptable[8 * v11 + v9] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE_0;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_207;
      case ST_FLAG:
        switch ( (unsigned __int16)v8 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_207;
      case ST_WIDTH:
        if ( (_WORD)v8 == 42 )
        {
          v67 = (char *)(v4 + 1);
          fldwidth = *v4;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + (unsigned __int16)v8 - 48;
        }
        goto LABEL_207;
      case ST_DOT:
        precision = 0;
        goto LABEL_207;
      case ST_PRECIS:
        if ( (_WORD)v8 == 42 )
        {
          v67 = (char *)(v4 + 1);
          precision = *v4;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + (unsigned __int16)v8 - 48;
        }
        goto LABEL_207;
      case ST_SIZE:
        switch ( (unsigned __int16)v8 )
        {
          case 'I':
            v12 = *v10;
            if ( *v10 == 54 && v10[1] == 52 )
            {
              flags |= 0x8000u;
              v58 = v10 + 2;
            }
            else if ( v12 == 51 && v10[1] == 50 )
            {
              flags &= ~0x8000u;
              v58 = v10 + 2;
            }
            else if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 117 && v12 != 120 && v12 != 88 )
            {
              state = ST_NORMAL;
NORMAL_STATE_0:
              bufferiswide = 1;
              write_char_0(f, pnumwritten: &charsout, ch: v8);
            }
            break;
          case 'h':
            flags |= 0x20u;
            break;
          case 'l':
            if ( *v10 == 108 )
            {
              flags |= 0x1000u;
              v58 = v10 + 1;
            }
            else
            {
              flags |= 0x10u;
            }
            break;
          case 'w':
            flags |= 0x800u;
            break;
          default:
            break;
        }
        goto LABEL_207;
      case ST_TYPE:
        if ( (unsigned __int16)v8 <= 0x64u )
        {
          if ( (unsigned __int16)v8 == 100 )
            goto LABEL_111;
          if ( (unsigned __int16)v8 > 0x53u )
          {
            if ( (unsigned __int16)v8 != 88 )
            {
              if ( (unsigned __int16)v8 == 90 )
              {
                v18 = (__int16 *)*v4;
                v67 = (char *)(v4 + 1);
                if ( v18 != nullptr && (v19 = *((char **)v18 + 1)) != nullptr )
                {
                  v20 = *v18;
                  s = v19;
                  if ( (flags & 0x800) != 0 )
                  {
                    v21 = v20 - (v20 >> 31);
                    bufferiswide = 1;
LABEL_178:
                    v20 = v21 >> 1;
                    goto LABEL_179;
                  }
                  bufferiswide = 0;
                }
                else
                {
                  s = __nullstring;
                  strlen(buf: __nullstring);
                }
LABEL_179:
                textlen = v20;
                goto LABEL_180;
              }
              if ( (unsigned __int16)v8 == 97 )
                goto LABEL_65;
              if ( (unsigned __int16)v8 != 99 )
                goto LABEL_180;
              goto LABEL_86;
            }
LABEL_133:
            hexadd = 7;
COMMON_HEX_0:
            count = 16;
            if ( (flags & 0x80u) != 0 )
            {
              prefix[0] = 48;
              prefix[1] = hexadd + 81;
              prefixlen = 2;
            }
COMMON_INT_0:
            if ( (flags & 0x8000u) != 0 || (flags & 0x1000) != 0 )
            {
              v22 = *(_QWORD *)v4;
              v23 = v4 + 2;
            }
            else
            {
              v23 = v4 + 1;
              if ( (flags & 0x20) != 0 )
              {
                v67 = (char *)v23;
                if ( (flags & 0x40) != 0 )
                  LODWORD(v22) = *((__int16 *)v23 - 2);
                else
                  LODWORD(v22) = *((unsigned __int16 *)v23 - 2);
                v22 = (int)v22;
LABEL_150:
                if ( (flags & 0x40) != 0 && v22 < 0 )
                {
                  v22 = -v22;
                  flags |= 0x100u;
                }
                v32 = HIDWORD(v22);
                v33 = v22;
                if ( (flags & 0x9000) == 0 )
                  v32 = 0;
                if ( precision >= 0 )
                {
                  flags &= ~8u;
                  if ( precision > 512 )
                    precision = 512;
                }
                else
                {
                  precision = 1;
                }
                if ( (v32 | (unsigned int)v22) == 0 )
                  prefixlen = 0;
                for ( i = &buffer.sz[511]; ; --i )
                {
                  v35 = precision--;
                  if ( v35 <= 0 && (v32 | v33) == 0 )
                    break;
                  v36 = __PAIR64__(v32, v33) % count + 48;
                  v37 = __PAIR64__(v32, v33) / count;
                  v32 = HIDWORD(v37);
                  v33 = v37;
                  if ( v36 > 57 )
                    LOBYTE(v36) = hexadd + v36;
                  *i = v36;
                }
                v38 = (char *)((char *)&buffer.wz[255] + 1 - i);
                v39 = i + 1;
                textlen = (int)v38;
                s = v39;
                if ( (flags & 0x200) != 0 && (v38 == nullptr || *v39 != 48) )
                {
                  *--s = 48;
                  v20 = (int)(v38 + 1);
                  goto LABEL_179;
                }
                goto LABEL_180;
              }
              LODWORD(v22) = *(v23 - 1);
              if ( (flags & 0x40) != 0 )
                v22 = (int)v22;
              else
                HIDWORD(v22) = 0;
            }
            v67 = (char *)v23;
            goto LABEL_150;
          }
          switch ( (unsigned __int16)v8 )
          {
            case 'S':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_71:
              v14 = precision;
              if ( precision == -1 )
                v14 = 0x7FFFFFFF;
              v67 = (char *)(v4 + 1);
              v15 = (char *)*v4;
              s = v15;
              if ( (flags & 0x20) == 0 )
              {
                if ( v15 == nullptr )
                  s = (char *)__wnullstring;
                v40 = s;
                bufferiswide = 1;
                while ( v14 != 0 )
                {
                  --v14;
                  if ( *(_WORD *)v40 == 0 )
                    break;
                  v40 += 2;
                }
                v21 = v40 - s;
                goto LABEL_178;
              }
              if ( v15 == nullptr )
                s = __nullstring;
              textlen = 0;
              for ( j = (unsigned __int8 *)s; textlen < v14; ++textlen )
              {
                if ( *j == 0 )
                  break;
                if ( _isleadbyte_l(c: *j, plocinfo: &_loc_update.localeinfo) != 0 )
                  ++j;
                ++j;
              }
              break;
            case 'A':
              goto LABEL_64;
            case 'C':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_86:
              v17 = *(unsigned __int16 *)v4;
              bufferiswide = 1;
              v67 = (char *)(v4 + 1);
              wchar = v17;
              if ( (flags & 0x20) != 0 )
              {
                tempchar[0] = v17;
                tempchar[1] = 0;
                if ( _mbtowc_l(
                       pwc: (wchar_t *)&buffer,
                       s: tempchar,
                       n: _loc_update.localeinfo.locinfo->mb_cur_max,
                       plocinfo: &_loc_update.localeinfo) < 0 )
                  no_output = 1;
              }
              else
              {
                buffer.wz[0] = v17;
              }
              s = (char *)&buffer;
              textlen = 1;
              break;
            case 'E':
            case 'G':
LABEL_64:
              v8 += 32;
              capexp = 1;
              count = v8;
LABEL_65:
              flags |= 0x40u;
              p_buffer = &buffer;
              s = (char *)&buffer;
              textlen = 512;
              if ( precision >= 0 )
              {
                if ( precision != 0 )
                {
                  if ( precision > 512 )
                    precision = 512;
                  if ( precision > 163 )
                  {
                    v24 = precision + 349;
                    v25 = (char *)MemAlloc_Alloc(nSize: precision + 349);
                    LOBYTE(v8) = count;
                    heapbuf = v25;
                    if ( v25 != nullptr )
                    {
                      s = v25;
                      textlen = v24;
                      p_buffer = (_woutput_l::__l2::<unnamed_tag> *)v25;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = (_WORD)v8 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v26 = *v4;
              v27 = (char *)(v4 + 2);
              LODWORD(tmp.x) = v26;
              HIDWORD(tmp.x) = *((_DWORD *)v27 - 1);
              v49 = capexp;
              v48 = precision;
              v67 = v27;
              v47 = (char)v8;
              v46 = textlen;
              v28 = (void (__cdecl *)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr: codedptr);
              v28(a1: &tmp, a2: p_buffer, a3: v46, a4: v47, a5: v48, a6: v49, a7: &_loc_update);
              v29 = flags & 0x80;
              if ( (flags & 0x80) != 0 && precision == 0 )
              {
                v30 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(codedptr: off_5C03C4);
                v30(a1: p_buffer, a2: &_loc_update);
              }
              if ( (_WORD)count == 103 && v29 == 0 )
              {
                v31 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(codedptr: off_5C03C0);
                v31(a1: p_buffer, a2: &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_woutput_l::__l2::<unnamed_tag> *)((char *)p_buffer + 1);
                s = (char *)p_buffer;
              }
              strlen(buf: p_buffer->sz);
              goto LABEL_179;
            default:
              break;
          }
LABEL_180:
          if ( no_output != 0 )
            goto LABEL_205;
          if ( (flags & 0x40) != 0 )
          {
            if ( (flags & 0x100) != 0 )
            {
              prefix[0] = 45;
LABEL_188:
              prefixlen = 1;
              goto LABEL_189;
            }
            if ( (flags & 1) != 0 )
            {
              prefix[0] = 43;
              goto LABEL_188;
            }
            if ( (flags & 2) != 0 )
            {
              prefix[0] = 32;
              goto LABEL_188;
            }
          }
LABEL_189:
          v41 = textlen;
          v42 = fldwidth - textlen - prefixlen;
          if ( (flags & 0xC) == 0 )
            write_multi_char_0(pnumwritten: &charsout, ch: 0x20u, num: fldwidth - textlen - prefixlen, f);
          v43 = f;
          write_string_0(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
          if ( (flags & 8) != 0 && (flags & 4) == 0 )
            write_multi_char_0(pnumwritten: &charsout, ch: 0x30u, num: v42, f: v43);
          if ( bufferiswide != 0 || v41 <= 0 )
          {
            write_string_0(string: (wchar_t *)s, f: v43, pnumwritten: &charsout, len: v41);
          }
          else
          {
            v44 = s;
            count = v41;
            while ( 1 )
            {
              --count;
              retval = _mbtowc_l(
                         pwc: (wchar_t *)&wchar,
                         s: v44,
                         n: _loc_update.localeinfo.locinfo->mb_cur_max,
                         plocinfo: &_loc_update.localeinfo);
              if ( retval <= 0 )
                break;
              write_char_0(f, pnumwritten: &charsout, ch: wchar);
              v44 += retval;
              if ( count <= 0 )
                goto LABEL_202;
            }
            charsout = -1;
          }
LABEL_202:
          if ( charsout >= 0 && (flags & 4) != 0 )
            write_multi_char_0(pnumwritten: &charsout, ch: 0x20u, num: v42, f);
LABEL_205:
          if ( heapbuf != nullptr )
          {
            free(pMem: heapbuf);
            heapbuf = nullptr;
          }
LABEL_207:
          v5 = v58;
          v45 = *v58;
          count = v45;
          if ( (_WORD)v45 == 0 )
            goto LABEL_210;
          v9 = state;
          v4 = (int *)v67;
          v8 = v45;
          continue;
        }
        if ( (unsigned __int16)v8 > 0x70u )
        {
          if ( (unsigned __int16)v8 != 115 )
          {
            if ( (unsigned __int16)v8 != 117 )
            {
              if ( (unsigned __int16)v8 != 120 )
                goto LABEL_180;
              hexadd = 39;
              goto COMMON_HEX_0;
            }
            goto LABEL_112;
          }
          goto LABEL_71;
        }
        if ( (unsigned __int16)v8 == 112 )
        {
          precision = 8;
          goto LABEL_133;
        }
        if ( (unsigned __int16)v8 < 0x65u )
          goto LABEL_180;
        if ( (unsigned __int16)v8 <= 0x67u )
          goto LABEL_65;
        if ( (unsigned __int16)v8 == 105 )
        {
LABEL_111:
          flags |= 0x40u;
LABEL_112:
          count = 10;
          goto COMMON_INT_0;
        }
        if ( (unsigned __int16)v8 != 110 )
        {
          if ( (unsigned __int16)v8 != 111 )
            goto LABEL_180;
          count = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
          goto COMMON_INT_0;
        }
        v5 = (wchar_t *)*v4++;
        v67 = (char *)v4;
        if ( _get_printf_count_output() )
        {
          if ( (flags & 0x20) != 0 )
            *v5 = charsout;
          else
            *(_DWORD *)v5 = charsout;
          no_output = 1;
          goto LABEL_205;
        }
        *_errno() = 22;
LABEL_3:
        _invalid_parameter(a1: (unsigned int)v4, a2: v6, a3: (unsigned int)v5);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      default:
        goto LABEL_207;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D7680
// Name: ___libm_error_support
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_error_support(long double *arg1, long double *arg2, long double *retval, error_types input_tag)
{
  int (__cdecl *v4)(threadlocaleinfostruct *); // eax
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  _exception exc; // [esp+Ch] [ebp-28h] BYREF
  char double_zero[8]; // [esp+2Ch] [ebp-8h]

  double_zero[0] = 0;
  double_zero[1] = 0;
  double_zero[2] = 0;
  double_zero[3] = 0;
  double_zero[4] = 0;
  double_zero[5] = 0;
  double_zero[6] = 0;
  double_zero[7] = 0;
  if ( pmatherr_set != 0 )
    v4 = (int (__cdecl *)(threadlocaleinfostruct *))_decode_pointer(codedptr: _pmatherr);
  else
    v4 = __init_collate;
  if ( input_tag > exp10_overflow )
  {
    switch ( input_tag )
    {
      case log_nan:
        exc.name = "log";
        goto LABEL_37;
      case log10_nan:
        exc.name = "log10";
        goto LABEL_37;
      case exp_nan:
        exc.name = "exp";
        goto LABEL_37;
      case atan_nan:
        exc.name = "atan";
        goto LABEL_37;
      case ceil_nan:
        exc.name = "ceil";
        goto LABEL_37;
      case floor_nan:
        exc.name = "floor";
        goto LABEL_37;
      case pow_nan:
        goto $LN36_3;
      case modf_nan:
        exc.name = "modf";
        goto LABEL_37;
      case acos_nan:
        goto $LN30_1;
      case asin_nan:
        goto $LN8_28;
      case sin_naninf:
        exc.name = "sin";
        goto LABEL_53;
      case cos_naninf:
        exc.name = "cos";
        goto LABEL_53;
      case tan_naninf:
        exc.name = "tan";
LABEL_53:
        v6 = *arg1 * *(double *)double_zero;
        *retval = v6;
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        goto LABEL_54;
      default:
        return;
    }
  }
  if ( input_tag == exp10_overflow )
  {
    exc.type = 3;
    exc.name = "exp10";
    goto LABEL_17;
  }
  if ( input_tag <= pow_underflow )
  {
    switch ( input_tag )
    {
      case pow_underflow:
        exc.name = "pow";
        goto LABEL_20;
      case log_zero:
        exc.type = 2;
        exc.name = "log";
        goto LABEL_17;
      case log_negative:
        exc.name = "log";
        break;
      case log10_zero:
        exc.type = 2;
        exc.name = "log10";
        goto LABEL_17;
      case log10_negative:
        exc.name = "log10";
        break;
      case exp_overflow:
        exc.type = 3;
        exc.name = "exp";
LABEL_17:
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        exc.retval = *retval;
        if ( v4(ploci: (threadlocaleinfostruct *)&exc) == 0 )
          *_errno() = 34;
        goto LABEL_56;
      case exp_underflow:
        exc.name = "exp";
LABEL_20:
        exc.arg1 = *arg1;
        v5 = *arg2;
        exc.type = 4;
        exc.arg2 = v5;
        exc.retval = *retval;
        v4(ploci: (threadlocaleinfostruct *)&exc);
LABEL_56:
        v7 = exc.retval;
        goto LABEL_57;
      case pow_overflow:
        exc.type = 3;
        goto LABEL_16;
      default:
        return;
    }
LABEL_23:
    exc.arg1 = *arg1;
    exc.arg2 = *arg2;
    v6 = *retval;
LABEL_54:
    exc.retval = v6;
    exc.type = 1;
    if ( v4(ploci: (threadlocaleinfostruct *)&exc) == 0 )
      *_errno() = 33;
    goto LABEL_56;
  }
  if ( input_tag != pow_zero_to_zero )
  {
    switch ( input_tag )
    {
      case pow_zero_to_negative:
        exc.type = 2;
LABEL_16:
        exc.name = "pow";
        goto LABEL_17;
      case pow_neg_to_non_integer:
$LN36_3:
        exc.name = "pow";
        break;
      case pow_nan_to_zero:
        exc.name = "pow";
LABEL_37:
        *retval = *arg1;
        break;
      case acos_gt_one:
$LN30_1:
        exc.name = "acos";
        break;
      case asin_gt_one:
$LN8_28:
        exc.name = "asin";
        break;
      default:
        return;
    }
    goto LABEL_23;
  }
  v7 = 1.0;
LABEL_57:
  *retval = v7;
}

//------------------------------------------------------------------------------
// Address: 0x004D7930
// Name: __floor_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _floor_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]

  v1 = _ctrlfp(newctrl: newcw, _mask: 0xFFFFu);
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xBu, x, savedcw: v1);
    }
    return _except1(flags: 8, opcode: 11, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
      return v4;
    }
    else
    {
      return _except1(flags: 16, opcode: 11, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D7A01
// Name: __crtLCMapStringW_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringW_stat(
        unsigned int Locale,
        DWORD dwMapFlags,
        const wchar_t *lpSrcStr,
        int cchSrc,
        wchar_t *lpDestStr,
        int cchDest,
        UINT code_page)
{
  localeinfo_struct *plocinfo; // ecx
  char *v8; // ebx
  localeinfo_struct *v9; // edi
  int v10; // ecx
  const wchar_t *v11; // eax
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  void *v17; // esp
  unsigned __int8 *v18; // eax
  int v19; // eax
  int v20; // esi
  int v21; // eax
  void *v22; // esp
  char *v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // edx
  unsigned int v26; // ecx
  int v27; // eax
  _DWORD v28[3]; // [esp+0h] [ebp-1Ch] BYREF
  int inbuff_size; // [esp+Ch] [ebp-10h]
  int retval; // [esp+10h] [ebp-Ch]
  unsigned __int8 *inbuffer; // [esp+14h] [ebp-8h]

  v8 = nullptr;
  v9 = plocinfo;
  if ( f_use_1 == 0 )
  {
    if ( LCMapStringW(Locale: 0, dwMapFlags: 0x100u, lpSrcStr: &FLOAT_0_0, cchSrc: 1, lpDestStr: nullptr, cchDest: 0) != 0 )
    {
      f_use_1 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_1 = 2;
    }
  }
  if ( cchSrc > 0 )
  {
    v10 = cchSrc;
    v11 = lpSrcStr;
    while ( 1 )
    {
      --v10;
      if ( *v11 == 0 )
        break;
      ++v11;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    cchSrc += -1 - v10;
  }
  if ( f_use_1 == 1 )
    return LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest);
  if ( f_use_1 != 2 && f_use_1 != 0 )
    return 0;
  retval = 0;
  if ( Locale == 0 )
    Locale = v9->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v9->locinfo->lc_codepage;
  v13 = __ansicp(lcid: Locale);
  if ( code_page != v13 && v13 != -1 )
    code_page = v13;
  v14 = WideCharToMultiByte(
          CodePage: code_page,
          dwFlags: 0,
          lpWideCharStr: lpSrcStr,
          cchWideChar: cchSrc,
          lpMultiByteStr: nullptr,
          cbMultiByte: 0,
          lpDefaultChar: nullptr,
          lpUsedDefaultChar: nullptr);
  v15 = v14;
  inbuff_size = v14;
  if ( v14 == 0 )
    return 0;
  if ( v14 > 0 && 0xFFFFFFE0 / v14 != 0 )
  {
    v16 = v14 + 8;
    if ( (unsigned int)(v15 + 8) > 0x400 )
    {
      v18 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v15 + 8);
      if ( v18 != nullptr )
      {
        *(_DWORD *)v18 = 56797;
        goto LABEL_32;
      }
    }
    else
    {
      v17 = alloca(v16);
      v18 = (unsigned __int8 *)v28;
      if ( v28 != nullptr )
      {
        v28[0] = 52428;
LABEL_32:
        v18 += 8;
      }
    }
    inbuffer = v18;
    goto LABEL_35;
  }
  inbuffer = nullptr;
LABEL_35:
  if ( inbuffer == nullptr )
    return 0;
  if ( WideCharToMultiByte(
         CodePage: code_page,
         dwFlags: 0,
         lpWideCharStr: lpSrcStr,
         cchWideChar: cchSrc,
         lpMultiByteStr: (LPSTR)inbuffer,
         cbMultiByte: v15,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: nullptr) != 0 )
  {
    v19 = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)inbuffer, cchSrc: v15, lpDestStr: nullptr, cchDest: 0);
    v20 = v19;
    if ( v19 != 0 )
    {
      if ( v19 <= 0 || 0xFFFFFFE0 / v19 == 0 )
      {
LABEL_47:
        if ( v8 != nullptr )
        {
          if ( LCMapStringA(
                 Locale,
                 dwMapFlags,
                 lpSrcStr: (LPCSTR)inbuffer,
                 cchSrc: inbuff_size,
                 lpDestStr: v8,
                 cchDest: v20) != 0 )
          {
            if ( (dwMapFlags & 0x400) != 0 )
            {
              retval = v20;
              if ( cchDest != 0 )
              {
                if ( cchDest <= v20 )
                  v20 = cchDest - 1;
                v24 = strncpy_s(_Dst: (char *)lpDestStr, _SizeInBytes: cchDest, _Src: v8, _Count: v20);
                if ( v24 != 0 )
                  _invoke_watson(a1: v24, a2: v25, a3: v26, a4: (unsigned int)v8, a5: 0, a6: v20);
              }
            }
            else
            {
              if ( cchDest != 0 )
                v27 = MultiByteToWideChar(
                        CodePage: code_page,
                        dwFlags: 1u,
                        lpMultiByteStr: v8,
                        cbMultiByte: v20,
                        lpWideCharStr: lpDestStr,
                        cchWideChar: cchDest);
              else
                v27 = MultiByteToWideChar(
                        CodePage: code_page,
                        dwFlags: 1u,
                        lpMultiByteStr: v8,
                        cbMultiByte: v20,
                        lpWideCharStr: nullptr,
                        cchWideChar: 0);
              retval = v27;
            }
          }
          _freea(_Memory: v8);
        }
        goto LABEL_60;
      }
      v21 = v19 + 8;
      if ( (unsigned int)(v20 + 8) > 0x400 )
      {
        v23 = (char *)MemAlloc_Alloc(nSize: v20 + 8);
        if ( v23 != nullptr )
        {
          *(_DWORD *)v23 = 56797;
          goto LABEL_45;
        }
      }
      else
      {
        v22 = alloca(v21);
        v23 = (char *)v28;
        if ( v28 != nullptr )
        {
          v28[0] = 52428;
LABEL_45:
          v23 += 8;
        }
      }
      v8 = v23;
      goto LABEL_47;
    }
  }
LABEL_60:
  _freea(_Memory: inbuffer);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004D7C62
// Name: ___crtLCMapStringW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringW(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwMapFlags,
        const wchar_t *lpSrcStr,
        int cchSrc,
        wchar_t *lpDestStr,
        int cchDest,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringW_stat(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D7CA2
// Name: __iswctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _iswctype_l(unsigned __int16 c, unsigned __int16 mask, localeinfo_struct *plocinfo)
{
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  int d; // [esp+10h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
  {
    d = 0;
  }
  else if ( c >= 0x100u )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( __crtGetStringTypeW(
           plocinfo: &_loc_update.localeinfo,
           dwInfoType: 1u,
           lpSrcStr: &c,
           cchSrc: 1,
           lpCharType: (unsigned __int16 *)&d,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           lcid: _loc_update.localeinfo.locinfo->lc_handle[2]) == 0 )
      d = 0;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    d = (unsigned __int16)(mask & _pwctype[c]);
  }
  return mask & (unsigned __int16)d;
}

//------------------------------------------------------------------------------
// Address: 0x004D7D24
// Name: _iswctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswctype(unsigned __int16 c, unsigned __int16 mask)
{
  unsigned __int16 d; // [esp+0h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
    return 0;
  if ( c < 0x100u )
    return mask & _pwctype[c];
  if ( __locale_changed == 0 )
    __crtGetStringTypeW(
      plocinfo: &__initiallocalestructinfo,
      dwInfoType: 1u,
      lpSrcStr: &c,
      cchSrc: 1,
      lpCharType: &d,
      code_page: __initiallocinfo.lc_codepage,
      lcid: __initiallocinfo.lc_handle[2]);
  return _iswctype_l(c, mask, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D7DA0
// Name: __CIacos_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIacos_pentium4()
{
  JUMPOUT(0x4D7DBE);
}

//------------------------------------------------------------------------------
// Address: 0x004D8300
// Name: __trandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp1@<eax>(int a1@<edx>, __int16 a2@<cx>, int a3@<ebp>, __int16 a4@<fpstat>, double _ST7@<st0>)
{
  __int16 v5; // bx

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a3 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a3 - 162) = v5;
  _EBX = &XAMtoTagTab;
  __asm { fxam }
  *(_DWORD *)(a3 - 148) = a1;
  *(_WORD *)(a3 - 160) = a4;
  *(_BYTE *)(a3 - 144) = 0;
  LOBYTE(a2) = __ROL1__((char)(2 * *(_BYTE *)(a3 - 159)) >> 1, 1);
  _AL = a2 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))(_AL + a1 + 16))(a1: a2 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x004D8367
// Name: __trandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp2@<eax>(int a1@<edx>, int a2@<ebp>, __int16 a3@<fpstat>, double _ST6@<st1>, double a5@<st0>)
{
  __int16 v5; // bx
  __int16 v7; // fps
  char v9; // cl
  __int16 v10; // cx
  char v13; // ah

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a2 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a2 - 162) = v5;
  _EBX = &XAMtoTagTab;
  __asm { fxam }
  *(_DWORD *)(a2 - 148) = a1;
  *(_WORD *)(a2 - 160) = a3;
  *(_BYTE *)(a2 - 144) = 0;
  _ST6 = a5;
  v9 = *(_BYTE *)(a2 - 159);
  __asm { fxam }
  *(_WORD *)(a2 - 160) = v7;
  HIBYTE(v10) = __ROL1__((char)(2 * *(_BYTE *)(a2 - 159)) >> 1, 1);
  _AL = HIBYTE(v10) & 0xF;
  __asm { xlat }
  v13 = _AL;
  LOBYTE(v10) = __ROL1__((char)(2 * v9) >> 1, 1);
  _AL = v10 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))((char)((4 * v13) | _AL) + a1 + 16))(a1: v10 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x004D83F3
// Name: __rttospopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int _rttospopde()
{
  _rttosnpopde();
  return _rttospop();
}

//------------------------------------------------------------------------------
// Address: 0x004D83F8
// Name: __rttospop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _rttospop()
{
  return _rtnospop();
}

//------------------------------------------------------------------------------
// Address: 0x004D83FA
// Name: __rtnospop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtnospop()
{
  JUMPOUT(0x4D83FC);
}

//------------------------------------------------------------------------------
// Address: 0x004D83FD
// Name: __rtnospopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtnospopde()
{
  _rttosnpopde();
  _rtnospop();
}

//------------------------------------------------------------------------------
// Address: 0x004D8404
// Name: __rtzeropop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtzeropop@<eax>(double a1@<st0>)
{
  return _rtzeronpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004D8406
// Name: __rtzeronpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtzeronpop()
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004D840B
// Name: __rtonepop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtonepop@<eax>(double a1@<st0>)
{
  return _rtonenpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004D840D
// Name: __rtonenpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtonenpop()
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004D8412
// Name: __tosnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan1@<st0>(int a1@<ebp>, double a2@<st0>)
{
  double result; // st7

  *(double *)(a1 - 158) = a2;
  result = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
    return result + *(double *)&One_2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D843D
// Name: __nosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _nosnan2()
{
  return _tosnan2();
}

//------------------------------------------------------------------------------
// Address: 0x004D843F
// Name: __tosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan2@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  double v3; // st6

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
    *(_BYTE *)(a1 - 144) = 7;
  else
    *(_BYTE *)(a1 - 144) = 1;
  return a3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x004D8467
// Name: __nan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _nan2@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  double v3; // st6
  double v4; // rt0
  double v5; // st6

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0
    && (v4 = v3,
        v5 = a3,
        a3 = v4,
        *(double *)(a1 - 158) = v5,
        v3 = *(double *)(a1 - 158),
        (*(_BYTE *)(a1 - 151) & 0x40) != 0) )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
  }
  return a3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x004D84A6
// Name: __rtindfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtindfpop@<eax>(double a1@<st0>)
{
  return _rtindfnpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004D84A8
// Name: __rtindfnpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtindfnpop@<eax>(int a1@<ebp>)
{
  if ( *(char *)(a1 - 144) > 0 )
    JUMPOUT(0x4D84C0);
  return _rttosnpopde();
}

//------------------------------------------------------------------------------
// Address: 0x004D84B9
// Name: __rttosnpopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _rttosnpopde(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 144) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D84C3
// Name: __rtchsifneg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtchsifneg@<st0>(char a1@<cl>, double result@<st0>)
{
  if ( a1 != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D84D0
// Name: __startTwoArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _startTwoArgErrorHandling()
{
  JUMPOUT(0x4D84F0);
}

//------------------------------------------------------------------------------
// Address: 0x004D84E7
// Name: __startOneArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _startOneArgErrorHandling(
        int a1@<eax>,
        int a2@<edx>,
        char *a3@<ecx>,
        __int16 savCW,
        unsigned int ret_addr,
        unsigned __int64 param1)
{
  _exception exc; // [esp+0h] [ebp-20h] BYREF

  exc.type = a1;
  __asm { fstp    [ebp+exc.retval] }
  exc.name = a3;
  *(_QWORD *)&exc.arg1 = param1;
  _87except(opcode: a2, &exc, pcw16: (unsigned __int16 *)&savCW);
  __asm { fld     [ebp+exc.retval] }
  if ( savCW != 639 )
    __asm { fldcw   word ptr [ebp+savCW] }
}

//------------------------------------------------------------------------------
// Address: 0x004D8530
// Name: __twoToTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _twoToTOS@<st0>(long double a1@<st0>)
{
  long double v1; // rt0

  v1 = rint(a1);
  return __FSCALE__(__F2XM1__(-(v1 - a1)) + 1.0, v1);
}

//------------------------------------------------------------------------------
// Address: 0x004D8545
// Name: __load_CW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _load_CW()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004D855C
// Name: __convertTOStoQNaN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _convertTOStoQNaN@<st0>(int a1@<eax>, double result@<st0>)
{
  if ( (a1 & 0x80000) == 0 )
    return result + 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D8575
// Name: __fload_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __fastcall _fload_withFB(int a1, _DWORD *a2)
{
  double result; // st7

  if ( (a2[1] & 0x7FF00000) != 0x7FF00000 )
    return *(double *)a2;
  *(_QWORD *)&result = *(_QWORD *)a2 << 11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D85B8
// Name: __checkTOS_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _checkTOS_withFB(int a1, int a2)
{
  int result; // eax

  result = a2 & 0x7FF00000;
  if ( (a2 & 0x7FF00000) == 0x7FF00000 )
    return a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D85CE
// Name: __fast_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _fast_exit()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004D85DB
// Name: __math_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004D8605
// Name: __check_overflow_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _check_overflow_exit()
{
  JUMPOUT(0x4D862D);
}

//------------------------------------------------------------------------------
// Address: 0x004D8619
// Name: __check_range_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004D86C0
// Name: __CIasin_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIasin_pentium4()
{
  JUMPOUT(0x4D86DE);
}

//------------------------------------------------------------------------------
// Address: 0x004D8C40
// Name: __cintrindisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cintrindisp2@<eax>(int a1@<edx>, __int16 a2@<fpstat>, double a3@<st1>, double a4@<st0>)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _trandisp2(a1, a2: (int)&savedregs, a3: a2, _ST6: a3, a5: a4);
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x004D8C7E
// Name: __cintrindisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cintrindisp1@<eax>(int a1@<edx>, __int16 a2@<cx>, __int16 a3@<fpstat>, double a4@<st0>)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _trandisp1(a1, a2, a3: (int)&savedregs, a4: a3, _ST7: a4);
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x004D8CBB
// Name: __ctrandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrandisp2(double a1@<st1>, double a2@<st0>, unsigned __int64 parm1, unsigned __int64 parm2)
{
  int v4; // edx
  __int16 v5; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm: parm1);
  _fload(parm: parm2);
  _trandisp2(a1: v4, a2: (int)&savedregs, a3: v5, _ST6: a1, a5: a2);
  ctranexit();
}

//------------------------------------------------------------------------------
// Address: 0x004D8D03
// Name: ctranexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ctranexit@<eax>(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 712) &= ~1u;
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x004D8D0A
// Name: cintrinexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall cintrinexit@<st0>(long double *a1@<ebp>, long double result@<st0>)
{
  char v2; // fps
  char v3; // al
  __int16 v4; // ax
  int v5; // ebx

  if ( __fastflag != 0 )
    return result;
  *(a1 - 90) = result;
  v3 = *((_BYTE *)a1 - 144);
  switch ( v3 )
  {
    case 0:
      goto checkinexact;
    case -1:
      if ( (*((_WORD *)a1 - 357) & 0x7FF0) != 0x7FF0 )
        goto checkinexact;
      goto haveoverflow_0;
    case -2:
      v4 = *((_WORD *)a1 - 357) & 0x7FF0;
      if ( v4 == 0 )
      {
        *(_DWORD *)((char *)a1 - 142) = 4;
        result = __FSCALE__(result, 1536.0);
        if ( fabs(result) < 2.225073858507201e-308 )
          result = result * 0.0;
        goto haveerror;
      }
      if ( v4 != 32752 )
      {
checkinexact:
        if ( (*((_WORD *)a1 - 82) & 0x20) != 0 || (v2 & 0x20) == 0 )
          return result;
        *(_DWORD *)((char *)a1 - 142) = 8;
        goto haveerror;
      }
haveoverflow_0:
      *(_DWORD *)((char *)a1 - 142) = 3;
      result = __FSCALE__(result, -1536.0);
      if ( fabs(result) > 1.797693134862316e308 )
        result = result * INFINITY;
      goto haveerror;
    default:
      break;
  }
  *(_DWORD *)((char *)a1 - 142) = v3;
haveerror:
  v5 = *((_DWORD *)a1 - 37) + 1;
  *(_DWORD *)((char *)a1 - 138) = v5;
  if ( (*(_BYTE *)(a1 - 89) & 1) == 0 )
  {
    *(_DWORD *)((char *)a1 - 134) = *((_DWORD *)a1 + 2);
    *(_DWORD *)((char *)a1 - 130) = *((_DWORD *)a1 + 3);
    if ( *(_BYTE *)(v5 + 12) != 1 )
    {
      *(_DWORD *)((char *)a1 - 126) = *((_DWORD *)a1 + 4);
      *(_DWORD *)((char *)a1 - 122) = *((_DWORD *)a1 + 5);
    }
  }
  *(long double *)((char *)a1 - 118) = result;
  _87except(
    opcode: *(char *)(*((_DWORD *)a1 - 37) + 14),
    exc: (_exception *)((char *)a1 - 142),
    pcw16: (unsigned __int16 *)a1 - 82);
  return *(long double *)((char *)a1 - 118);
}

//------------------------------------------------------------------------------
// Address: 0x004D8E51
// Name: __ctrandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrandisp1(double a1@<st0>, unsigned __int64 parm1)
{
  int v2; // edx
  __int16 v3; // cx
  __int16 v4; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm: parm1);
  _trandisp1(a1: v2, a2: v3, a3: (int)&savedregs, a4: v4, _ST7: a1);
  ctranexit(a1: (int)&savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x004D8E84
// Name: __fload
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _fload(double parm)
{
  double tmp; // [esp+6h] [ebp-Ah]

  if ( (HIWORD(parm) & 0x7FF0) != 0x7FF0 )
    return parm;
  HIDWORD(tmp) = *(_QWORD *)&parm >> 21;
  LODWORD(tmp) = LODWORD(parm);
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x004D8EC0
// Name: _fdiv_main_routine
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl fdiv_main_routine(_TBYTE a1, _TBYTE a2)
{
  double v2; // st7
  double v3; // st6
  unsigned int v4; // eax

  v2 = *(double *)&a2;
  v3 = *(double *)&a1;
  while ( !__CFADD__(DWORD1(a1), DWORD1(a1)) )
  {
    if ( *(_QWORD *)&a1 == 0 || (HIWORD(a1) & 0x7FFF) != 0 )
      return v2 / v3;
    if ( (HIWORD(a2) & 0x7FFF) != 0 )
    {
      if ( (HIWORD(a2) & 0x7FFF) == 0x7FFF || !__CFADD__(DWORD1(a2), DWORD1(a2)) )
        return v2 / v3;
    }
    else if ( __CFADD__(DWORD1(a2), DWORD1(a2)) )
    {
      return v2 / v3;
    }
    *(double *)&a1 = v3 * *(float *)&one_shl_63;
    v2 = *(double *)&a2;
  }
  v4 = (2 * DWORD1(a1)) ^ 0xE000000;
  if ( (v4 & 0xE000000) != 0 )
    return v2 / v3;
  if ( fdiv_risc_table[v4 >> 28] == 0 )
    return v2 / v3;
  if ( (HIWORD(a1) & 0x7FFF) == 0 || (HIWORD(a1) & 0x7FFF) == 0x7FFF )
    return v2 / v3;
  if ( (HIWORD(a2) & 0x7FFF) == 1 )
    return v2 * *(float *)&fdiv_scale_2 / (v3 * *(float *)&fdiv_scale_2);
  else
    return v2 * *(float *)&fdiv_scale_1 / (v3 * *(float *)&fdiv_scale_1);
}

//------------------------------------------------------------------------------
// Address: 0x004D8FD7
// Name: __adj_fdiv_r
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _adj_fdiv_r(char a1@<al>)
{
  _TBYTE v1; // [esp-2Ch] [ebp-58h]
  _TBYTE v2; // [esp-20h] [ebp-4Ch]
  _TBYTE v17; // [esp+0h] [ebp-2Ch]
  _TBYTE v18; // [esp+Ch] [ebp-20h]

  switch ( a1 & 0x3F )
  {
    case 0:
      __asm { fdiv    st, st; jumptable 004D8FDD case 0 }
      return;
    case 1:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label2;
    case 2:
label2:
      __asm { fdivr   st, st; jumptable 004D8FDD case 2 }
      return;
    case 3:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label4;
    case 4:
label4:
      __asm { fdiv    st, st; jumptable 004D8FDD case 4 }
      return;
    case 5:
      __asm { fdivp   st, st; jumptable 004D8FDD case 5 }
      return;
    case 6:
      __asm { fdivr   st, st; jumptable 004D8FDD case 6 }
      return;
    case 7:
      __asm { fdivrp  st, st; jumptable 004D8FDD case 7 }
      return;
    case 8:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 8
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fld     [esp+2Ch+var_C]
        fxch    st(1)
      }
      return;
    case 9:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label10;
    case 0xA:
label10:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 004D8FDD case 10
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fld     [esp+arg_8]
        fxch    st(1)
      }
      return;
    case 0xB:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label12;
    case 0xC:
label12:
      __asm
      {
        fxch    st(1); jumptable 004D8FDD case 12
        fstp    [esp+arg_8]; _TBYTE
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm { fld     [esp+arg_1C] }
      return;
    case 0xD:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 004D8FDD case 13
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      return;
    case 0xE:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 14
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fld     [esp+2Ch+var_20] }
      return;
    case 0xF:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 15
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      return;
    case 0x10:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 16
        fxch    st(1)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_C]
        fxch    st(2)
      }
      return;
    case 0x11:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label18;
    case 0x12:
label18:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 004D8FDD case 18
        fxch    st(1)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_8]
        fxch    st(2)
      }
      return;
    case 0x13:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label20;
    case 0x14:
label20:
      __asm
      {
        fxch    st(2); jumptable 004D8FDD case 20
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(1)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_1C]
      }
      return;
    case 0x15:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 004D8FDD case 21
        fxch    st(1)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(1) }
      return;
    case 0x16:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 22
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x17:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 23
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(1) }
      return;
    case 0x18:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 24
        fxch    st(2)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_C]
        fxch    st(3)
      }
      return;
    case 0x19:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label26;
    case 0x1A:
label26:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 004D8FDD case 26
        fxch    st(2)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_8]
        fxch    st(3)
      }
      return;
    case 0x1B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label28;
    case 0x1C:
label28:
      __asm
      {
        fxch    st(3); jumptable 004D8FDD case 28
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(2)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_1C]
      }
      return;
    case 0x1D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 004D8FDD case 29
        fxch    st(2)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(2) }
      return;
    case 0x1E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 30
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x1F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 31
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(2) }
      return;
    case 0x20:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 32
        fxch    st(3)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_C]
        fxch    st(4)
      }
      return;
    case 0x21:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label34;
    case 0x22:
label34:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 004D8FDD case 34
        fxch    st(3)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_8]
        fxch    st(4)
      }
      return;
    case 0x23:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label36;
    case 0x24:
label36:
      __asm
      {
        fxch    st(4); jumptable 004D8FDD case 36
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(3)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_1C]
      }
      return;
    case 0x25:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 004D8FDD case 37
        fxch    st(3)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(3) }
      return;
    case 0x26:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 38
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x27:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 39
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(3) }
      return;
    case 0x28:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 40
        fxch    st(4)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_C]
        fxch    st(5)
      }
      return;
    case 0x29:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label42;
    case 0x2A:
label42:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 004D8FDD case 42
        fxch    st(4)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_8]
        fxch    st(5)
      }
      return;
    case 0x2B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label44;
    case 0x2C:
label44:
      __asm
      {
        fxch    st(5); jumptable 004D8FDD case 44
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(4)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_1C]
      }
      return;
    case 0x2D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 004D8FDD case 45
        fxch    st(4)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(4) }
      return;
    case 0x2E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 46
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x2F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 47
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(4) }
      return;
    case 0x30:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 48
        fxch    st(5)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_C]
        fxch    st(6)
      }
      return;
    case 0x31:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label50;
    case 0x32:
label50:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 004D8FDD case 50
        fxch    st(5)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_8]
        fxch    st(6)
      }
      return;
    case 0x33:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label52;
    case 0x34:
label52:
      __asm
      {
        fxch    st(6); jumptable 004D8FDD case 52
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(5)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_1C]
      }
      return;
    case 0x35:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 004D8FDD case 53
        fxch    st(5)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(5) }
      return;
    case 0x36:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 54
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x37:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 55
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(5) }
      return;
    case 0x38:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 56
        fxch    st(6)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_C]
        fxch    st(7)
      }
      return;
    case 0x39:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label58;
    case 0x3A:
label58:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 004D8FDD case 58
        fxch    st(6)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_8]
        fxch    st(7)
      }
      return;
    case 0x3B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label60;
    case 0x3C:
label60:
      __asm
      {
        fxch    st(7); jumptable 004D8FDD case 60
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(6)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_1C]
      }
      break;
    case 0x3D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 004D8FDD case 61
        fxch    st(6)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(6) }
      break;
    case 0x3E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 62
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_20]
      }
      break;
    case 0x3F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 004D8FDD case 63
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(6) }
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D9476
// Name: __fdivp_sti_st
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fdivp_sti_st(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-2Ch]
  _TBYTE v3; // [esp+Ch] [ebp-20h]

  *(double *)&v2 = a1;
  *(double *)&v3 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004D9489
// Name: __fdivrp_sti_st
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fdivrp_sti_st(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-2Ch]
  _TBYTE v3; // [esp+Ch] [ebp-20h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004D949C
// Name: __adj_fdiv_m32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m32(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, float a4)
{
  if ( (LODWORD(a4) & 0x7F800000) != 0x7F800000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivp_sti_st(a1: a2, a2: a3);
    else
      _fdivp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D94E8
// Name: __adj_fdiv_m64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m64(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, double a4)
{
  if ( (HIDWORD(a4) & 0x7FF00000) != 0x7FF00000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivp_sti_st(a1: a2, a2: a3);
    else
      _fdivp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D9534
// Name: __adj_fdiv_m16i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m16i(
        __int16 a1@<fpstat>,
        double a2@<st1>,
        double a3@<st0>,
        __int16 a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivp_sti_st(a1: a2, a2: a3);
  else
    _fdivp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004D9568
// Name: __adj_fdiv_m32i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m32i(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, int a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivp_sti_st(a1: a2, a2: a3);
  else
    _fdivp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004D959C
// Name: __adj_fdivr_m32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m32(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, float a4)
{
  if ( (LODWORD(a4) & 0x7F800000) != 0x7F800000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivrp_sti_st(a1: a2, a2: a3);
    else
      _fdivrp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D95E8
// Name: __adj_fdivr_m64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m64(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, double a4)
{
  if ( (HIDWORD(a4) & 0x7FF00000) != 0x7FF00000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivrp_sti_st(a1: a2, a2: a3);
    else
      _fdivrp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D9634
// Name: __adj_fdivr_m16i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m16i(
        __int16 a1@<fpstat>,
        double a2@<st1>,
        double a3@<st0>,
        __int16 a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivrp_sti_st(a1: a2, a2: a3);
  else
    _fdivrp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004D9668
// Name: __adj_fdivr_m32i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m32i(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, int a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivrp_sti_st(a1: a2, a2: a3);
  else
    _fdivrp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004D969C
// Name: __safe_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __spoils<edx,ecx,st0> _safe_fdiv(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v2 = a1;
  *(double *)&v3 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004D96B1
// Name: __safe_fdivr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __spoils<edx,ecx,st0> _safe_fdivr(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004D96C6
// Name: __fprem_common
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _fprem_common@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  int v6; // ecx
  double v7; // st7
  __int16 v8; // fps
  double v9; // st6
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( fprem_risc_table[result] != 0 )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( 2 * DWORD1(a5) == 0 )
          {
            result = 2 * DWORD1(a2);
            if ( 2 * DWORD1(a2) == 0 )
            {
              if ( (WORD4(a5) & 0x7FFFu) > (WORD4(a2) & 0x7FFFu) + 63 )
              {
                v6 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v7 = fabs(*(long double *)&a2);
                v9 = fabs(*(long double *)&a5);
                do
                {
                  v10 = v9 < v7;
                  v11 = 0;
                  v12 = v9 == v7;
                  result = v8 & 0x100;
                  if ( (v8 & 0x100) == 0 )
                    v9 = v9 - v7;
                  v7 = v7 * *(double *)&half;
                  --v6;
                }
                while ( v6 != 0 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
    return v13 & 0x4300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D98CC
// Name: __adj_fprem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __spoils<ecx,st0> _adj_fprem@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return _fprem_common(a1: 0, a2: *(__int128 *)v4, a3: *(int *)&v4[16], a4: v5, a5: v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * *(double *)&one_shl_64;
    }
    *(double *)v4 = a2 * *(double *)&one_shl_64;
    return _fprem_common(a1: v3, a2: *(__int128 *)v4, a3: HIDWORD(*(unsigned __int64 *)&a2), a4: v5, a5: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D997E
// Name: __fprem1_common
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _fprem1_common@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  int v6; // ecx
  double v7; // st7
  __int16 v8; // fps
  double v9; // st6
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( fprem_risc_table[result] != 0 )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( 2 * DWORD1(a5) == 0 )
          {
            result = 2 * DWORD1(a2);
            if ( 2 * DWORD1(a2) == 0 )
            {
              if ( (WORD4(a5) & 0x7FFFu) > (WORD4(a2) & 0x7FFFu) + 63 )
              {
                v6 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v7 = fabs(*(long double *)&a2);
                v9 = fabs(*(long double *)&a5);
                do
                {
                  v10 = v9 < v7;
                  v11 = 0;
                  v12 = v9 == v7;
                  result = v8 & 0x100;
                  if ( (v8 & 0x100) == 0 )
                    v9 = v9 - v7;
                  v7 = v7 * *(double *)&half;
                  --v6;
                }
                while ( v6 != 0 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
    return v13 & 0x4300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9B84
// Name: __adj_fprem1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __spoils<ecx,st0> _adj_fprem1@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return _fprem1_common(a1: 0, a2: *(__int128 *)v4, a3: *(int *)&v4[16], a4: v5, a5: v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * *(double *)&one_shl_64;
    }
    *(double *)v4 = a2 * *(double *)&one_shl_64;
    return _fprem1_common(a1: v3, a2: *(__int128 *)v4, a3: HIDWORD(*(unsigned __int64 *)&a2), a4: v5, a5: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9C39
// Name: __safe_fprem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __usercall _safe_fprem@<eax>(double a1@<st1>, double a2@<st0>)
{
  return _adj_fprem(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004D9C3F
// Name: __safe_fprem1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __usercall _safe_fprem1@<eax>(double a1@<st1>, double a2@<st0>)
{
  return _adj_fprem1(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004D9C45
// Name: __adj_fpatan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _adj_fpatan@<st0>(long double a1@<st1>, long double a2@<st0>)
{
  return atan2(a2, a1);
}

//------------------------------------------------------------------------------
// Address: 0x004D9C48
// Name: __adj_fptan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _adj_fptan()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004D9C50
// Name: __CIpow_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_pentium4()
{
  JUMPOUT(0x4D9C69);
}

//------------------------------------------------------------------------------
// Address: 0x004DA7C1
// Name: __fFEXP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fFEXP@<eax>(__int16 a1@<cx>, int a2@<ebp>, double a3@<st0>)
{
  double v3; // st7

  *(_BYTE *)(a2 - 144) = -2;
  HIBYTE(a1) = 0;
  v3 = a3 * 1.442695040888963407;
  _ffexpm1(a1);
  if ( (*(_BYTE *)(a2 - 159) & 1) != 0 && _adjust_fdiv == 1 )
    _safe_fdivr(a1: 1.442695040888963407 + 1.0, a2: v3);
  return _rttospop();
}

//------------------------------------------------------------------------------
// Address: 0x004DA828
// Name: __rtinfpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtinfpopse@<eax>(double a1@<st0>)
{
  return _rtinfnpopse(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004DA82A
// Name: __rtinfnpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtinfnpopse@<st0>(int a1@<ebp>)
{
  double result; // st7

  result = *(double *)&_infinity;
  *(_BYTE *)(a1 - 144) = 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DA83A
// Name: __fFLN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _fFLN@<st0>(int a1@<ebp>, long double a2@<st0>)
{
  __int16 v2; // fps
  bool v3; // c0
  char v4; // c2
  bool v5; // c3
  long double result; // st7

  v3 = a2 < 0.0;
  v4 = 0;
  v5 = a2 == 0.0;
  *(_WORD *)(a1 - 160) = v2;
  if ( (*(_BYTE *)(a1 - 159) & 0x41) == 0 )
    return __FYL2X__(a2, 0.6931471805599453094);
  _rtindfpop(a1: 0.6931471805599453094);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DA897
// Name: zerotoxdone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void zerotoxdone()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004DA8EF
// Name: __rtinfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtinfpop@<eax>(double a1@<st0>)
{
  return _rtinfnpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004DA8F1
// Name: __rtinfnpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtinfnpop@<st0>(int a1@<ebp>)
{
  double result; // st7

  result = *(double *)&_infinity;
  *(_BYTE *)(a1 - 144) = 3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DA90E
// Name: __ffexpm1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __usercall _ffexpm1@<st0>(char a1@<ch>, int _EBP@<ebp>)
{
  double result; // st7

  __asm
  {
    fld     st
    fabs
    fld     _log2max
    fcompp
    fstsw   word ptr [ebp-0A0h]
  }
  if ( (*(_BYTE *)(_EBP - 159) & 0x41) != 0 )
  {
    __asm
    {
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    if ( (*(_BYTE *)(_EBP - 159) & 1) != 0 )
    {
      *(_BYTE *)(_EBP - 144) = 4;
      return _rtzeronpop();
    }
    else
    {
      __asm
      {
        fstp    st
        fld     __infinity
      }
      if ( a1 != 0 )
        __asm { fchs }
    }
  }
  else
  {
    __asm
    {
      fld     st
      frndint
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    __asm
    {
      fxch    st(1)
      fsub    st, st(1)
      ftst
      fstsw   word ptr [ebp-0A0h]
      fabs
      f2xm1
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DA951
// Name: _isintTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isintTOS@<eax>(long double a1@<st0>)
{
  if ( rint(a1) != a1 )
    return notanint();
  if ( rint(a1 * *(double *)&half) == a1 * *(double *)&half )
    return evenint();
  return isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x004DA976
// Name: _isintTOSret
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void isintTOSret()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004DA977
// Name: notanint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void notanint()
{
  isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x004DA97E
// Name: evenint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void evenint()
{
  isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x004DA985
// Name: _usepowhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall usepowhlp@<st0>(int a1@<ebp>, long double y@<st1>, long double x@<st0>)
{
  int v4; // eax
  long double result; // st7
  long double *v6; // [esp+10h] [ebp-7Ch]
  long double v7[15]; // [esp+14h] [ebp-78h] BYREF

  _ESI = v7;
  v6 = v7;
  __asm { fsave   byte ptr [esi+8] }
  v4 = _powhlp(x, y, result: v7);
  __asm { frstor  byte ptr [esi+8] }
  result = v7[0];
  if ( v4 != 0 )
    _rttosnpopde(a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DA9B7
// Name: __d_inttype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _d_inttype(long double y)
{
  if ( (_fpclass(x: y) & 0x90) != 0 || _frnd(x: y) != y )
    return 0;
  if ( _frnd(x: y * 0.5) == y * 0.5 )
    return 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004DAA1B
// Name: __powhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _powhlp(double x, long double y, long double *result)
{
  long double dbl; // st7
  int v4; // esi
  long double v5; // st6
  double *v6; // eax
  int v7; // eax

  dbl = 0.0;
  v4 = 0;
  v5 = x;
  if ( x < 0.0 )
    v5 = -x;
  if ( HIDWORD(y) == 2146435072 )
  {
    if ( LODWORD(y) == 0 )
    {
      if ( v5 <= 1.0 )
      {
        v6 = result;
        if ( v5 >= 1.0 )
          dbl = 1.0;
        goto LABEL_28;
      }
      goto LABEL_6;
    }
  }
  else if ( y == -INFINITY )
  {
    if ( v5 > 1.0 )
      goto LABEL_27;
    v6 = result;
    if ( v5 < 1.0 )
    {
      dbl = _d_inf.dbl;
LABEL_28:
      *v6 = dbl;
      return v4;
    }
    *result = _d_ind.dbl;
    return 1;
  }
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
    {
      if ( y <= 0.0 )
      {
        v6 = result;
        if ( y >= 0.0 )
          dbl = 1.0;
        goto LABEL_28;
      }
LABEL_6:
      dbl = _d_inf.dbl;
LABEL_27:
      v6 = result;
      goto LABEL_28;
    }
  }
  else if ( x == -INFINITY )
  {
    v7 = _d_inttype(y);
    dbl = 0.0;
    if ( y <= 0.0 )
    {
      if ( y >= 0.0 )
      {
        dbl = 1.0;
      }
      else if ( v7 == 1 )
      {
        dbl = _d_mzero.dbl;
      }
    }
    else
    {
      dbl = _d_inf.dbl;
      if ( v7 == 1 )
        dbl = -_d_inf.dbl;
    }
    goto LABEL_27;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004DAB60
// Name: _cos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl cos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x4EB508);
  }
  JUMPOUT(0x4DABEF);
}

//------------------------------------------------------------------------------
// Address: 0x004DABA0
// Name: __CIcos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIcos(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIcos;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIcos_pentium4(a1);
  else
__CIcos:
    _CIcos_default(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004DABDB
// Name: __CIcos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004DAC90
// Name: _tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl tan(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x4EB6B8);
  }
  JUMPOUT(0x4DAD1F);
}

//------------------------------------------------------------------------------
// Address: 0x004DACD0
// Name: __CItan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CItan(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CItan;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CItan_pentium4(a1);
  else
__CItan:
    _CItan_default(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004DAD0B
// Name: __CItan_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004DADBD
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _controlfp_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned int *_CurrentState,
        unsigned int newctrl,
        unsigned int mask)
{
  unsigned int v5; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl: 0, mask: 0);
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0x16u, a3: 0);
    return 22;
  }
  else
  {
    v5 = mask & 0xFFF7FFFF;
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl, mask: v5);
    else
      _control87(newctrl, mask: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DAE27
// Name: __statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _statfp@<eax>(__int16 a1@<fpstat>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x004DAE32
// Name: __clrfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _clrfp@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x004DAE3E
// Name: __ctrlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _ctrlfp()
{
  __int16 oldCw; // [esp+0h] [ebp-4h]

  return oldCw;
}

//------------------------------------------------------------------------------
// Address: 0x004DAE65
// Name: __set_statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_statfp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004DAEBB
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __set_fpsr_sse2(unsigned int newMXCSR)
{
  if ( __sse2_available != 0 )
  {
    if ( (newMXCSR & 0x40) != 0 && _DAZ_ENABLED != 0 )
      _mm_setcsr(newMXCSR);
    else
      _mm_setcsr(newMXCSR & 0xFFFFFFBF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DAF5A
// Name: ___TypeMatch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl __TypeMatch(const _s_HandlerType *pCatch, const _s_CatchableType *pCatchable, const _s_ThrowInfo *pThrow)
{
  TypeDescriptor *pType; // eax
  TypeDescriptor *v4; // ecx
  int v5; // eax
  BOOL result; // eax

  pType = pCatch->pType;
  result = true;
  if ( pType != nullptr && pType->name[0] != 0 )
  {
    v4 = pCatchable->pType;
    if ( pType != v4 )
    {
      strcmp(str1: (unsigned __int8 *)pType->name, str2: (unsigned __int8 *)v4->name);
      if ( v5 != 0 )
        return false;
    }
    if ( (pCatchable->properties & 2) != 0 && (pCatch->adjectives & 8) == 0
      || (pThrow->attributes & 1) != 0 && (pCatch->adjectives & 1) == 0
      || (pThrow->attributes & 2) != 0 && (pCatch->adjectives & 2) == 0 )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DAFB6
// Name: ___FrameUnwindFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __FrameUnwindFilter(_EXCEPTION_POINTERS *pExPtrs)
{
  unsigned int ExceptionCode; // eax
  _tiddata *v2; // eax

  ExceptionCode = pExPtrs->ExceptionRecord->ExceptionCode;
  if ( ExceptionCode == -532459699 )
  {
    if ( _getptd()->_ProcessingThrow > 0 )
    {
      v2 = _getptd();
      --v2->_ProcessingThrow;
    }
  }
  else if ( ExceptionCode == -529697949 )
  {
    _getptd()->_ProcessingThrow = 0;
    terminate();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DAFFA
// Name: ___FrameUnwindToState
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __FrameUnwindToState(EHRegistrationNode *pRN, void *pDC, const _s_FuncInfo *pFuncInfo, int targetState)
{
  int state; // esi
  _tiddata *v5; // eax
  int v6; // eax
  const _s_UnwindMapEntry *v7; // ecx
  _tiddata *v8; // eax

  if ( pFuncInfo->maxState > 128 )
    state = pRN->state;
  else
    state = SLOBYTE(pRN->state);
  v5 = _getptd();
  ++v5->_ProcessingThrow;
  while ( state != targetState )
  {
    if ( state <= -1 || state >= pFuncInfo->maxState )
      _inconsistency();
    v6 = state;
    v7 = &pFuncInfo->pUnwindMap[state];
    state = v7->toState;
    if ( v7->action != nullptr )
    {
      pRN->state = state;
      _CallSettingFrame(funclet: (unsigned int)pFuncInfo->pUnwindMap[v6].action, (unsigned int)pRN, dwInCode: 0x103u);
    }
  }
  if ( _getptd()->_ProcessingThrow > 0 )
  {
    v8 = _getptd();
    --v8->_ProcessingThrow;
  }
  if ( state != targetState )
    _inconsistency();
  pRN->state = state;
}

//------------------------------------------------------------------------------
// Address: 0x004DB0DB
// Name: ExFilterRethrow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ExFilterRethrow@<eax>(_EXCEPTION_POINTERS *pExPtrs@<eax>)
{
  _EXCEPTION_RECORD *ExceptionRecord; // eax
  unsigned int v2; // ecx

  ExceptionRecord = pExPtrs->ExceptionRecord;
  if ( ExceptionRecord->ExceptionCode != -529697949 )
    return 0;
  if ( ExceptionRecord->NumberParameters != 3 )
    return 0;
  v2 = ExceptionRecord->ExceptionInformation[0];
  if ( v2 != 429065504 && v2 != 429065505 && v2 != 429065506 )
    return 0;
  if ( ExceptionRecord->ExceptionInformation[2] != 0 )
    return 0;
  _getptd()->_cxxReThrow = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004DB120
// Name: ___DestructExceptionObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __DestructExceptionObject(EHExceptionRecord *pExcept)
{
  const _s_ThrowInfo *pThrowInfo; // eax
  void (__cdecl *pmfnUnwind)(); // eax
  void *v3; // [esp+0h] [ebp-28h]
  int v4; // [esp+4h] [ebp-24h]

  if ( pExcept != nullptr && pExcept->ExceptionCode == -529697949 )
  {
    pThrowInfo = pExcept->params.pThrowInfo;
    if ( pThrowInfo != nullptr )
    {
      pmfnUnwind = pThrowInfo->pmfnUnwind;
      if ( pmfnUnwind != nullptr )
        _CallMemberFunction1(pthis: pExcept->params.pExceptionObject, pmfn: pmfnUnwind, pthat: v3, val2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB174
// Name: ___AdjustPointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __AdjustPointer(char *pThis, const PMD *pmd)
{
  char *result; // eax

  result = &pThis[pmd->mdisp];
  if ( pmd->pdisp >= 0 )
    result += pmd->pdisp + *(_DWORD *)(*(_DWORD *)&pThis[pmd->pdisp] + pmd->vdisp);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DB199
// Name: IsInExceptionSpec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __usercall IsInExceptionSpec@<al>(const _s_ESTypeList *pESTypeList@<edi>, EHExceptionRecord *pExcept)
{
  const _s_CatchableTypeArray *pCatchableTypeArray; // eax
  int nCatchableTypes; // ebx
  const _s_CatchableType **arrayOfCatchableTypes; // esi
  int i; // [esp+4h] [ebp-8h]
  unsigned __int8 bFoundMatchingTypeInES; // [esp+Bh] [ebp-1h]

  if ( pESTypeList == nullptr )
    _inconsistency();
  i = 0;
  for ( bFoundMatchingTypeInES = 0; i < pESTypeList->nCount; ++i )
  {
    pCatchableTypeArray = pExcept->params.pThrowInfo->pCatchableTypeArray;
    nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
    arrayOfCatchableTypes = pCatchableTypeArray->arrayOfCatchableTypes;
    if ( pCatchableTypeArray->nCatchableTypes > 0 )
    {
      while ( !__TypeMatch(
                 pCatch: &pESTypeList->pTypeArray[i],
                 pCatchable: *arrayOfCatchableTypes,
                 pThrow: pExcept->params.pThrowInfo) )
      {
        --nCatchableTypes;
        ++arrayOfCatchableTypes;
        if ( nCatchableTypes <= 0 )
          goto LABEL_9;
      }
      bFoundMatchingTypeInES = 1;
    }
LABEL_9:
    ;
  }
  return bFoundMatchingTypeInES;
}

//------------------------------------------------------------------------------
// Address: 0x004DB25B
// Name: CallCatchBlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl CallCatchBlock(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        const _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        unsigned int NLGCode)
{
  void *handlerAddress; // ecx
  void *v7; // ebx
  void *v8; // eax
  unsigned int magicNumber; // eax
  FrameInfo FrameInfo; // [esp+10h] [ebp-3Ch] BYREF
  int ExceptionObjectDestroyed; // [esp+18h] [ebp-34h]
  _CONTEXT *pSaveExContext; // [esp+1Ch] [ebp-30h]
  EHExceptionRecord *pSaveException; // [esp+20h] [ebp-2Ch]
  FrameInfo *pFrameInfo; // [esp+24h] [ebp-28h]
  void *saveESP; // [esp+28h] [ebp-24h]
  void *continuationAddress; // [esp+30h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  v7 = handlerAddress;
  continuationAddress = handlerAddress;
  ExceptionObjectDestroyed = 0;
  saveESP = (void *)pRN[-1].state;
  pFrameInfo = _CreateFrameInfo(pFrameInfo: &FrameInfo, pExceptionObject: pExcept->params.pExceptionObject);
  pSaveException = (EHExceptionRecord *)_getptd()->_curexception;
  pSaveExContext = (_CONTEXT *)_getptd()->_curcontext;
  _getptd()->_curexception = pExcept;
  _getptd()->_curcontext = pContext;
  ms_exc.registration.TryLevel = 1;
  _CallCatchBlock2(pRN, pFuncInfo, handlerAddress: v7, CatchDepth, NLGCode);
  continuationAddress = v8;
  ms_exc.registration.TryLevel = -2;
  pRN[-1].state = (int)saveESP;
  _FindAndUnlinkFrame(pFrameInfo);
  _getptd()->_curexception = pSaveException;
  _getptd()->_curcontext = pSaveExContext;
  if ( pExcept->ExceptionCode == -529697949 && pExcept->NumberParameters == 3 )
  {
    magicNumber = pExcept->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505 || magicNumber == 429065506)
      && ExceptionObjectDestroyed == 0
      && continuationAddress != nullptr
      && _IsExceptionObjectToBeDestroyed(pExceptionObject: pExcept->params.pExceptionObject) != 0 )
    {
      __DestructExceptionObject(pExcept);
    }
  }
  return continuationAddress;
}

//------------------------------------------------------------------------------
// Address: 0x004DB3F7
// Name: ___BuildCatchObjectHelper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __BuildCatchObjectHelper(
        EHExceptionRecord *pExcept,
        int (__stdcall *pRN)(),
        const _s_HandlerType *pCatch,
        const _s_CatchableType *pConv)
{
  TypeDescriptor *pType; // ecx
  int dispCatchObj; // ecx
  int (__stdcall *v6)(); // esi
  char *pExceptionObject; // eax
  char *v8; // eax
  unsigned __int8 *v9; // eax
  int (__stdcall *v11)(); // [esp-8h] [ebp-34h]
  unsigned int sizeOrOffset; // [esp-4h] [ebp-30h]
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  pType = pCatch->pType;
  if ( pType != nullptr && pType->name[0] != 0 )
  {
    dispCatchObj = pCatch->dispCatchObj;
    if ( dispCatchObj != 0 || (pCatch->adjectives & 0x80000000) != 0 )
    {
      v6 = pRN;
      if ( (pCatch->adjectives & 0x80000000) == 0 )
        v6 = (int (__stdcall *)())((char *)pRN + dispCatchObj + 12);
      if ( (pCatch->adjectives & 8) != 0 )
      {
        if ( _ValidateRead(code: (int (__stdcall *)())pExcept->params.pExceptionObject) != 0
          && _ValidateRead(code: v6) != 0 )
        {
          pExceptionObject = (char *)pExcept->params.pExceptionObject;
          *(_DWORD *)v6 = pExceptionObject;
          v8 = __AdjustPointer(pThis: pExceptionObject, pmd: &pConv->thisDisplacement);
LABEL_11:
          *(_DWORD *)v6 = v8;
          return retval;
        }
      }
      else
      {
        v11 = (int (__stdcall *)())pExcept->params.pExceptionObject;
        if ( (pConv->properties & 1) != 0 )
        {
          if ( _ValidateRead(code: v11) != 0 && _ValidateRead(code: v6) != 0 )
          {
            memmove(
              dst: (unsigned __int8 *)v6,
              src: (unsigned __int8 *)pExcept->params.pExceptionObject,
              count: pConv->sizeOrOffset);
            if ( pConv->sizeOrOffset != 4 || *(_DWORD *)v6 == 0 )
              return retval;
            v8 = __AdjustPointer(pThis: *(char **)v6, pmd: &pConv->thisDisplacement);
            goto LABEL_11;
          }
        }
        else if ( pConv->copyFunction != nullptr )
        {
          if ( _ValidateRead(code: v11) != 0
            && _ValidateRead(code: v6) != 0
            && _ValidateRead(code: (int (__stdcall *)())pConv->copyFunction) != 0 )
          {
            return ((pConv->properties & 4) != 0) + 1;
          }
        }
        else if ( _ValidateRead(code: v11) != 0 && _ValidateRead(code: v6) != 0 )
        {
          sizeOrOffset = pConv->sizeOrOffset;
          v9 = (unsigned __int8 *)__AdjustPointer(
                                    pThis: (char *)pExcept->params.pExceptionObject,
                                    pmd: &pConv->thisDisplacement);
          memmove(dst: (unsigned __int8 *)v6, src: v9, count: sizeOrOffset);
          return retval;
        }
      }
      _inconsistency();
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DB576
// Name: ___BuildCatchObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __BuildCatchObject(
        EHExceptionRecord *pExcept,
        int (__stdcall *pRN)(),
        const _s_HandlerType *pCatch,
        const _s_CatchableType *pConv)
{
  int (__stdcall *v4)(); // ebx
  int v5; // eax
  char *v6; // eax
  char *v7; // eax
  int v8; // [esp+0h] [ebp-28h]

  if ( (pCatch->adjectives & 0x80000000) == 0 )
    v4 = (int (__stdcall *)())((char *)pRN + pCatch->dispCatchObj + 12);
  else
    v4 = pRN;
  v5 = __BuildCatchObjectHelper(pExcept, pRN, pCatch, pConv) - 1;
  if ( v5 != 0 )
  {
    if ( v5 == 1 )
    {
      v6 = __AdjustPointer(pThis: (char *)pExcept->params.pExceptionObject, pmd: &pConv->thisDisplacement);
      _CallMemberFunction1(pthis: v4, pmfn: pConv->copyFunction, pthat: v6, val2: 1);
    }
  }
  else
  {
    v7 = __AdjustPointer(pThis: (char *)pExcept->params.pExceptionObject, pmd: &pConv->thisDisplacement);
    _CallMemberFunction1(pthis: v4, pmfn: pConv->copyFunction, pthat: v7, val2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB607
// Name: CatchIt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CatchIt(
        EHRegistrationNode *pRN@<esi>,
        const _s_HandlerType *pCatch@<ebx>,
        const _s_TryBlockMapEntry *pEntry@<edi>,
        EHExceptionRecord *pExcept,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        const _s_CatchableType *pConv,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  void *v10; // eax

  if ( pConv != nullptr )
    __BuildCatchObject(pExcept, (int (__stdcall *)())pRN, pCatch, pConv);
  if ( pMarkerRN != nullptr )
    _UnwindNestedFrames(pRN: pMarkerRN, pExcept);
  else
    _UnwindNestedFrames(pRN, pExcept);
  __FrameUnwindToState(pRN, pDC, pFuncInfo, targetState: pEntry->tryLow);
  pRN->state = pEntry->tryHigh + 1;
  v10 = CallCatchBlock(pExcept, pRN, pContext, pFuncInfo, CatchDepth, NLGCode: 0x100u);
  if ( v10 != nullptr )
    _JumpToContinuation(target: v10, pRN);
}

//------------------------------------------------------------------------------
// Address: 0x004DB673
// Name: FindHandlerForForeignException
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl FindHandlerForForeignException(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        int curState,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  void **p_translator; // edi
  int v9; // esi
  const _s_TryBlockMapEntry *i; // edi
  int v11; // eax
  int v12; // ecx
  unsigned int end; // [esp+4h] [ebp-8h] BYREF
  unsigned int curTry; // [esp+8h] [ebp-4h] BYREF

  if ( pExcept->ExceptionCode != -2147483645
    && (_getptd()->_translator == nullptr
     || *(p_translator = &_getptd()->_translator) == _encoded_null()
     || pExcept->ExceptionCode == -532459699
     || _CallSETranslator(pExcept, pRN, pContext, pDC, pFuncInfo, CatchDepth, pMarkerRN) == 0) )
  {
    if ( pFuncInfo->nTryBlocks == 0 )
      _inconsistency();
    v9 = curState;
    for ( i = _GetRangeOfTrysToCheck(pFuncInfo, CatchDepth, curState, pStart: &curTry, pEnd: &end); curTry < end; ++i )
    {
      if ( v9 >= i->tryLow && v9 <= i->tryHigh )
      {
        v11 = (int)&i->pHandlerArray[i->nCatches];
        v12 = *(_DWORD *)(v11 - 12);
        if ( (v12 == 0 || *(_BYTE *)(v12 + 8) == 0) && (*(_BYTE *)(v11 - 16) & 0x40) == 0 )
        {
          CatchIt(
            pRN,
            pCatch: (const _s_HandlerType *)(v11 - 16),
            pEntry: i,
            pExcept,
            pContext,
            pDC,
            pFuncInfo,
            pConv: nullptr,
            CatchDepth,
            pMarkerRN);
          v9 = curState;
        }
      }
      ++curTry;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB765
// Name: FindHandler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl FindHandler(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        unsigned __int8 recursive,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  const _s_FuncInfo *v8; // ebx
  int maxState; // eax
  int state; // ecx
  EHExceptionRecord *curexception; // esi
  unsigned int magicNumber; // eax
  unsigned int v13; // eax
  const _s_ESTypeList *curexcspec; // edi
  _tiddata *v15; // eax
  int v16; // esi
  int v17; // ebx
  unsigned int v18; // eax
  const _s_FuncInfo *v19; // edi
  const _s_TryBlockMapEntry *v20; // edi
  int *p_nCatchableTypes; // eax
  const _s_CatchableType **v22; // ebx
  const _s_ESTypeList *pESTypeList; // edi
  _tiddata *v24; // eax
  bool v25; // zf
  const _s_FuncInfo *v26; // esi
  EHExceptionRecord *v27; // [esp-4h] [ebp-3Ch]
  const _s_ThrowInfo *pThrowInfo; // [esp-4h] [ebp-3Ch]
  std::exception pExceptionObject; // [esp+Ch] [ebp-2Ch] BYREF
  const _s_CatchableType *pCatchable; // [esp+18h] [ebp-20h]
  unsigned int end; // [esp+1Ch] [ebp-1Ch] BYREF
  int catches; // [esp+20h] [ebp-18h]
  int catchables; // [esp+24h] [ebp-14h]
  unsigned int curTry; // [esp+28h] [ebp-10h] BYREF
  const _s_HandlerType *pCatch; // [esp+2Ch] [ebp-Ch]
  int curState; // [esp+30h] [ebp-8h]
  unsigned __int8 gotMatch; // [esp+37h] [ebp-1h]

  v8 = pFuncInfo;
  maxState = pFuncInfo->maxState;
  gotMatch = 0;
  if ( maxState > 128 )
    state = pRN->state;
  else
    state = SLOBYTE(pRN->state);
  curState = state;
  if ( state < -1 || state >= maxState )
    _inconsistency();
  curexception = pExcept;
  if ( pExcept->ExceptionCode != -529697949 )
  {
LABEL_61:
    if ( v8->nTryBlocks != 0 )
    {
      if ( recursive != 0 )
        goto LABEL_28;
      FindHandlerForForeignException(
        pExcept: curexception,
        pRN,
        pContext,
        pDC,
        pFuncInfo: v8,
        curState,
        CatchDepth,
        pMarkerRN);
    }
    goto LABEL_64;
  }
  if ( pExcept->NumberParameters == 3 )
  {
    magicNumber = pExcept->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505 || magicNumber == 429065506)
      && pExcept->params.pThrowInfo == nullptr )
    {
      if ( _getptd()->_curexception == nullptr )
        return;
      curexception = (EHExceptionRecord *)_getptd()->_curexception;
      pExcept = curexception;
      pContext = (_CONTEXT *)_getptd()->_curcontext;
      if ( _ValidateRead(code: (int (__stdcall *)())curexception) == 0 )
        _inconsistency();
      if ( curexception->ExceptionCode == -529697949 && curexception->NumberParameters == 3 )
      {
        v13 = curexception->params.magicNumber;
        if ( (v13 == 429065504 || v13 == 429065505 || v13 == 429065506) && curexception->params.pThrowInfo == nullptr )
          _inconsistency();
      }
      if ( _getptd()->_curexcspec != nullptr )
      {
        curexcspec = (const _s_ESTypeList *)_getptd()->_curexcspec;
        v15 = _getptd();
        v27 = pExcept;
        v16 = 0;
        v15->_curexcspec = nullptr;
        if ( IsInExceptionSpec(pESTypeList: curexcspec, pExcept: v27) == 0 )
        {
          v17 = 0;
          if ( curexcspec->nCount > 0 )
          {
            do
            {
              if ( type_info::operator==(
                     this: (type_info *)curexcspec->pTypeArray[v17].pType,
                     rhs: &std::bad_exception `RTTI Type Descriptor') )
              {
                __DestructExceptionObject(pExcept);
                pExcept = (EHExceptionRecord *)"bad exception";
                std::exception::exception(this: &pExceptionObject, what: (const char *const *)&pExcept);
                pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_exception::`vftable';
                _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_exception_std__);
              }
              ++v16;
              ++v17;
            }
            while ( v16 < curexcspec->nCount );
          }
LABEL_28:
          terminate();
        }
        curexception = pExcept;
      }
    }
  }
  if ( curexception->ExceptionCode != -529697949
    || curexception->NumberParameters != 3
    || (v18 = curexception->params.magicNumber) != 429065504 && v18 != 429065505 && v18 != 429065506 )
  {
    v8 = pFuncInfo;
    goto LABEL_61;
  }
  v19 = pFuncInfo;
  if ( pFuncInfo->nTryBlocks != 0 )
  {
    v20 = _GetRangeOfTrysToCheck(pFuncInfo, CatchDepth, curState, pStart: &curTry, pEnd: &end);
    while ( curTry < end )
    {
      if ( v20->tryLow <= curState && curState <= v20->tryHigh )
      {
        pCatch = v20->pHandlerArray;
        catches = v20->nCatches;
        if ( catches > 0 )
        {
          while ( 1 )
          {
            p_nCatchableTypes = &curexception->params.pThrowInfo->pCatchableTypeArray->nCatchableTypes;
            v22 = (const _s_CatchableType **)(p_nCatchableTypes + 1);
            catchables = *p_nCatchableTypes;
            if ( catchables > 0 )
              break;
LABEL_45:
            --catches;
            ++pCatch;
            if ( catches <= 0 )
              goto NextTryBlock;
          }
          while ( 1 )
          {
            pThrowInfo = curexception->params.pThrowInfo;
            pCatchable = *v22;
            if ( __TypeMatch(pCatch, pCatchable, pThrow: pThrowInfo) )
              break;
            --catchables;
            ++v22;
            if ( catchables <= 0 )
              goto LABEL_45;
          }
          gotMatch = 1;
          CatchIt(
            pRN,
            pCatch,
            pEntry: v20,
            pExcept: curexception,
            pContext,
            pDC,
            pFuncInfo,
            pConv: pCatchable,
            CatchDepth,
            pMarkerRN);
          curexception = pExcept;
        }
      }
NextTryBlock:
      ++curTry;
      ++v20;
    }
    v19 = pFuncInfo;
  }
  if ( recursive != 0 )
    __DestructExceptionObject(pExcept: curexception);
  if ( gotMatch == 0 && (*(_DWORD *)v19 & 0x1FFFFFFFu) >= 0x19930521 )
  {
    pESTypeList = v19->pESTypeList;
    if ( pESTypeList != nullptr && IsInExceptionSpec(pESTypeList, pExcept: curexception) == 0 )
    {
      _getptd();
      _getptd();
      _getptd()->_curexception = curexception;
      v24 = _getptd();
      v25 = pMarkerRN == nullptr;
      v24->_curcontext = pContext;
      if ( v25 )
        _UnwindNestedFrames(pRN, pExcept: curexception);
      else
        _UnwindNestedFrames(pRN: pMarkerRN, pExcept: curexception);
      v26 = pFuncInfo;
      __FrameUnwindToState(pRN, pDC, pFuncInfo, targetState: -1);
      CallUnexpected(pESTypeList: v26->pESTypeList);
    }
  }
LABEL_64:
  if ( _getptd()->_curexcspec != nullptr )
    _inconsistency();
}

//------------------------------------------------------------------------------
// Address: 0x004DBBC0
// Name: _CallSettingFrame(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _CallSettingFrame(unsigned int funclet, unsigned int pRN, unsigned int dwInCode)
{
  void (*v3)(void); // eax
  unsigned int v4; // ecx

  v3 = (void (*)(void))_NLG_Notify1(a1: dwInCode);
  v3();
  v4 = dwInCode;
  if ( dwInCode == 256 )
    v4 = 2;
  _NLG_Notify1(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004DBC0C
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __report_gsfailure()
{
  unsigned int v0; // eax
  unsigned int v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  unsigned int vars0; // [esp+328h] [ebp+0h]
  void *retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  GS_ContextRecord.Eax = v0;
  GS_ContextRecord.Ecx = v2;
  GS_ContextRecord.Edx = v1;
  GS_ContextRecord.Ebx = v3;
  GS_ContextRecord.Esi = v5;
  GS_ContextRecord.Edi = v4;
  LOWORD(GS_ContextRecord.SegSs) = __SS__;
  LOWORD(GS_ContextRecord.SegCs) = __CS__;
  LOWORD(GS_ContextRecord.SegDs) = __DS__;
  LOWORD(GS_ContextRecord.SegEs) = __ES__;
  LOWORD(GS_ContextRecord.SegFs) = __FS__;
  LOWORD(GS_ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  GS_ContextRecord.EFlags = v6;
  GS_ContextRecord.Ebp = vars0;
  GS_ContextRecord.Eip = (unsigned int)retaddr;
  GS_ContextRecord.Esp = (unsigned int)&v10;
  GS_ContextRecord.ContextFlags = 65537;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook(_Reserved: 1);
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  UnhandledExceptionFilter(ExceptionInfo: &GS_ExceptionPointers);
  if ( DebuggerWasPresent == 0 )
    _crt_debugger_hook(_Reserved: 1);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000409);
}

//------------------------------------------------------------------------------
// Address: 0x004DBD10
// Name: __ceil_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _ceil_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp();
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xCu, x, savedcw: v1);
    }
    return _except1(flags: 8, opcode: 12, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return v4;
    }
    else
    {
      return _except1(flags: 16, opcode: 12, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DBDE1
// Name: _wcscpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall wcscpy_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int16 *_Dst,
        unsigned int _SizeInWords,
        const wchar_t *_Src)
{
  unsigned int v4; // esi
  const wchar_t *v6; // esi
  unsigned __int16 *v7; // edx
  wchar_t v8; // ax

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(a1, a2: 0, a3: v4);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --a1;
  }
  while ( a1 != 0 );
  if ( a1 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DBE4D
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringA_stat(
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  localeinfo_struct *plocinfo; // ecx
  localeinfo_struct *v9; // esi
  int v10; // ecx
  const char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // eax
  void *v21; // esp
  WCHAR *v22; // esi
  WCHAR *v23; // eax
  int v24; // eax
  int v26; // eax
  wchar_t *v27; // eax
  int v28; // eax
  int v29; // esi
  unsigned int v30; // eax
  void *v31; // esp
  char *v32; // edi
  char *v33; // eax
  _DWORD v34[2]; // [esp+0h] [ebp-20h] BYREF
  int v35; // [esp+8h] [ebp-18h] BYREF
  int AnsiCP; // [esp+Ch] [ebp-14h]
  char *cbuffer2; // [esp+10h] [ebp-10h]
  wchar_t *inwbuffer; // [esp+14h] [ebp-Ch]
  int retval; // [esp+18h] [ebp-8h] BYREF

  v9 = plocinfo;
  if ( f_use_2 == 0 )
  {
    if ( LCMapStringW(Locale: 0, dwMapFlags: 0x100u, lpSrcStr: &FLOAT_0_0, cchSrc: 1, lpDestStr: nullptr, cchDest: 0) != 0 )
    {
      f_use_2 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_2 = 2;
    }
  }
  if ( cchSrc > 0 )
  {
    v10 = cchSrc;
    v11 = lpSrcStr;
    while ( 1 )
    {
      --v10;
      if ( *v11 == 0 )
        break;
      ++v11;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    v12 = cchSrc - v10 - 1;
    if ( v12 < cchSrc )
      v12 = cchSrc - v10;
    cchSrc = v12;
  }
  if ( f_use_2 != 2 && f_use_2 != 0 )
  {
    if ( f_use_2 == 1 )
    {
      retval = 0;
      if ( code_page == 0 )
        code_page = v9->locinfo->lc_codepage;
      v13 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 8 * (bError != 0) + 1,
              lpMultiByteStr: lpSrcStr,
              cbMultiByte: cchSrc,
              lpWideCharStr: nullptr,
              cchWideChar: 0);
      v14 = v13;
      if ( v13 != 0 )
      {
        if ( v13 <= 0 || 0xFFFFFFE0 / v13 < 2 )
        {
          inwbuffer = nullptr;
LABEL_30:
          if ( inwbuffer != nullptr )
          {
            if ( MultiByteToWideChar(
                   CodePage: code_page,
                   dwFlags: 1u,
                   lpMultiByteStr: lpSrcStr,
                   cbMultiByte: cchSrc,
                   lpWideCharStr: inwbuffer,
                   cchWideChar: v14) != 0 )
            {
              v18 = LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v14, lpDestStr: nullptr, cchDest: 0);
              v19 = v18;
              retval = v18;
              if ( v18 != 0 )
              {
                if ( (dwMapFlags & 0x400) != 0 )
                {
                  if ( cchDest != 0 && v18 <= cchDest )
                    LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v14, (LPWSTR)lpDestStr, cchDest);
                  goto LABEL_53;
                }
                if ( v18 <= 0 || 0xFFFFFFE0 / v18 < 2 )
                {
                  v22 = nullptr;
LABEL_46:
                  if ( v22 != nullptr )
                  {
                    if ( LCMapStringW(
                           Locale,
                           dwMapFlags,
                           lpSrcStr: inwbuffer,
                           cchSrc: v14,
                           lpDestStr: v22,
                           cchDest: retval) != 0 )
                    {
                      if ( cchDest != 0 )
                        v24 = WideCharToMultiByte(
                                CodePage: code_page,
                                dwFlags: 0,
                                lpWideCharStr: v22,
                                cchWideChar: retval,
                                lpMultiByteStr: lpDestStr,
                                cbMultiByte: cchDest,
                                lpDefaultChar: nullptr,
                                lpUsedDefaultChar: nullptr);
                      else
                        v24 = WideCharToMultiByte(
                                CodePage: code_page,
                                dwFlags: 0,
                                lpWideCharStr: v22,
                                cchWideChar: retval,
                                lpMultiByteStr: nullptr,
                                cbMultiByte: 0,
                                lpDefaultChar: nullptr,
                                lpUsedDefaultChar: nullptr);
                      retval = v24;
                    }
                    _freea(_Memory: v22);
                  }
                  goto LABEL_53;
                }
                v20 = 2 * v18 + 8;
                if ( v20 > 0x400 )
                {
                  v23 = (WCHAR *)MemAlloc_Alloc(nSize: 2 * v19 + 8);
                  if ( v23 != nullptr )
                  {
                    *(_DWORD *)v23 = 56797;
                    v23 += 4;
                  }
                  v22 = v23;
                  goto LABEL_46;
                }
                v21 = alloca(v20);
                if ( v34 != nullptr )
                {
                  v34[0] = 52428;
                  v22 = (WCHAR *)&v35;
                  goto LABEL_46;
                }
              }
            }
LABEL_53:
            _freea(_Memory: inwbuffer);
            return retval;
          }
          return 0;
        }
        v15 = 2 * v13 + 8;
        if ( v15 > 0x400 )
        {
          v17 = (wchar_t *)MemAlloc_Alloc(nSize: 2 * v14 + 8);
          if ( v17 != nullptr )
          {
            *(_DWORD *)v17 = 56797;
            goto LABEL_27;
          }
        }
        else
        {
          v16 = alloca(v15);
          v17 = (wchar_t *)v34;
          if ( v34 != nullptr )
          {
            v34[0] = 52428;
LABEL_27:
            v17 += 4;
          }
        }
        inwbuffer = v17;
        goto LABEL_30;
      }
    }
    return 0;
  }
  inwbuffer = nullptr;
  cbuffer2 = nullptr;
  if ( Locale == 0 )
    Locale = v9->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v9->locinfo->lc_codepage;
  v26 = __ansicp(lcid: Locale);
  AnsiCP = v26;
  if ( v26 == -1 )
    return 0;
  if ( v26 == code_page )
  {
    v29 = LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest);
    goto LABEL_78;
  }
  v27 = (wchar_t *)__convertcp(fromCP: code_page, toCP: v26, lpSrcStr, pcchSrc: &cchSrc, lpDestStr: nullptr, cchDest: 0);
  inwbuffer = v27;
  if ( v27 == nullptr )
    return 0;
  v28 = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)v27, cchSrc, lpDestStr: nullptr, cchDest: 0);
  retval = v28;
  if ( v28 != 0 )
  {
    if ( v28 <= 0 )
    {
      v32 = nullptr;
    }
    else
    {
      v30 = v28 + 8;
      if ( v30 > 0x400 )
      {
        v33 = (char *)MemAlloc_Alloc(nSize: v30);
        if ( v33 != nullptr )
        {
          *(_DWORD *)v33 = 56797;
          v33 += 8;
        }
        v32 = v33;
      }
      else
      {
        v31 = alloca(v30);
        if ( v34 == nullptr )
          goto LABEL_63;
        v34[0] = 52428;
        v32 = (char *)&v35;
      }
    }
    if ( v32 != nullptr )
    {
      memset(dst: (int)v32, value: nullptr, count: retval);
      retval = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)inwbuffer, cchSrc, lpDestStr: v32, cchDest: retval);
      if ( retval != 0 )
      {
        cbuffer2 = __convertcp(fromCP: AnsiCP, toCP: code_page, lpSrcStr: v32, pcchSrc: &retval, lpDestStr, cchDest);
        v29 = cbuffer2 != nullptr ? retval : 0;
      }
      else
      {
        v29 = 0;
      }
      _freea(_Memory: v32);
      goto LABEL_78;
    }
  }
LABEL_63:
  v29 = 0;
LABEL_78:
  if ( inwbuffer != nullptr )
    free(pMem: inwbuffer);
  if ( cbuffer2 != nullptr && lpDestStr != cbuffer2 )
    free(pMem: cbuffer2);
  return v29;
}

//------------------------------------------------------------------------------
// Address: 0x004DC1EF
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, code_page, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DC240
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004DC40B
// Name: public: std::__non_rtti_object::__non_rtti_object(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::__non_rtti_object *__thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const char *_Message)
{
  std::bad_typeid::bad_typeid(this, _Message);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DC423
// Name: public: std::__non_rtti_object::__non_rtti_object(class std::__non_rtti_object const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::__non_rtti_object *__thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const std::__non_rtti_object *that)
{
  std::bad_typeid::bad_typeid(this, that);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DC43B
// Name: public: virtual std::__non_rtti_object::~__non_rtti_object(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::__non_rtti_object::~__non_rtti_object(std::__non_rtti_object *this)
{
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::bad_typeid::`vftable';
  std::exception::~exception(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DC4F0
// Name: wcstoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall wcstoxl@<eax>(
        unsigned int a1@<esi>,
        localeinfo_struct *plocinfo,
        const wchar_t *nptr,
        const wchar_t **endptr,
        unsigned int ibase,
        int flags)
{
  unsigned __int16 v7; // si
  unsigned __int16 *v8; // edi
  unsigned __int16 *v9; // edi
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  const wchar_t *v13; // edi
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)nptr, a3: a1);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  v7 = *nptr;
  number = 0;
  v8 = (unsigned __int16 *)(nptr + 1);
  while ( _iswctype_l(c: v7, mask: 8u, plocinfo: &_loc_update.localeinfo) != 0 )
    v7 = *v8++;
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_17;
  }
  v7 = *v8++;
LABEL_17:
  if ( ibase != 0 )
    goto LABEL_24;
  if ( _wchartodigit(ch: v7) == 0 )
  {
    if ( *v8 != 120 && *v8 != 88 )
    {
      ibase = 8;
      goto LABEL_29;
    }
    ibase = 16;
LABEL_24:
    if ( ibase == 16 && _wchartodigit(ch: v7) == 0 && (*v8 == 120 || *v8 == 88) )
    {
      v9 = v8 + 1;
      v7 = *v9;
      v8 = v9 + 1;
    }
    goto LABEL_29;
  }
  ibase = 10;
LABEL_29:
  v15 = 0xFFFFFFFF % ibase;
  v10 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v11 = _wchartodigit(ch: v7);
    if ( v11 == -1 )
    {
      if ( (v7 < 0x41u || v7 > 0x5Au) && (unsigned __int16)(v7 - 97) > 0x19u )
        break;
      v12 = v7;
      if ( (unsigned __int16)(v7 - 97) <= 0x19u )
        v12 = v7 - 32;
      v11 = v12 - 55;
    }
    if ( v11 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v11 <= v15 )
    {
      number = v11 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *v8++;
  }
  v13 = v8 - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v13 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v13;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x004DC6E7
// Name: _wcstol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall wcstol@<eax>(unsigned int a1@<esi>, const wchar_t *nptr, wchar_t **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return wcstoxl(a1, plocinfo: nullptr, nptr, (const wchar_t **)endptr, ibase, flags: 0);
  else
    return wcstoxl(a1, plocinfo: &__initiallocalestructinfo, nptr, (const wchar_t **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004DC710
// Name: __check_float_string_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _check_float_string_0@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        wchar_t **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        wchar_t *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  wchar_t *v6; // eax
  wchar_t *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = (wchar_t *)calloc(count: v5, size: 4u);
      *pFloatStr = v6;
      if ( v6 == nullptr )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy(dst: (unsigned __int8 *)*pFloatStr, src: (unsigned __int8 *)floatstring, count: 2 * *pnFloatStrSz);
    }
    else
    {
      v8 = (wchar_t *)_recalloc_crt(ptr: *pFloatStr, count: v5, size: 4u);
      if ( v8 == nullptr )
        return 0;
      *pFloatStr = v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004DC767
// Name: _hextodec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hextodec@<eax>(wchar_t chr@<di>)
{
  if ( (chr & 0xFF00) != 0 || isdigit(c: (unsigned __int8)chr) == 0 )
    return (chr & 0xFFDF) - 7;
  else
    return chr;
}

//------------------------------------------------------------------------------
// Address: 0x004DC793
// Name: _un_inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl un_inc(unsigned __int16 chr, _iobuf *fileptr)
{
  if ( chr != 0xFFFF )
    _ungetwc_nolock(ch: chr, str: fileptr);
}

//------------------------------------------------------------------------------
// Address: 0x004DC7A2
// Name: _whiteout_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __usercall whiteout_0@<ax>(int *counter@<esi>, _iobuf *fileptr)
{
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // di

  do
  {
    ++*counter;
    v2 = _fgetwc_nolock(stream: fileptr);
    v3 = v2;
  }
  while ( v2 != 0xFFFF && iswctype(c: v2, mask: 8u) != 0 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004DC7CC
// Name: __winput_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _winput_l@<eax>(
        unsigned int a1@<ebx>,
        _iobuf *stream,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  const wchar_t *v5; // edi
  int result; // eax
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // ax
  int v9; // ebx
  wchar_t v10; // cx
  const wchar_t *v11; // eax
  _QWORD *v12; // ebx
  unsigned __int16 v13; // ax
  signed int v14; // esi
  unsigned __int16 v15; // ax
  int v16; // esi
  int v17; // ebx
  unsigned int v18; // ebx
  int v19; // eax
  unsigned __int16 v20; // ax
  int v21; // eax
  int v22; // eax
  unsigned __int16 v23; // ax
  int v24; // eax
  unsigned __int16 v25; // ax
  int v26; // eax
  int v27; // eax
  unsigned __int16 v28; // ax
  unsigned int v29; // esi
  unsigned int v30; // esi
  char *v31; // edi
  unsigned int v32; // eax
  unsigned int v33; // edx
  unsigned int v34; // ecx
  void (__cdecl *v35)(int, void *, char *, _LocaleUpdate *); // eax
  int v36; // eax
  unsigned __int16 v37; // dx
  unsigned __int16 *v38; // edi
  char *v39; // ebx
  unsigned __int16 v40; // si
  unsigned __int16 v41; // cx
  unsigned __int16 v42; // ax
  unsigned int v43; // edx
  int v44; // esi
  unsigned __int16 v45; // ax
  unsigned __int16 v46; // ax
  unsigned int v47; // eax
  unsigned int v48; // edx
  unsigned int v49; // ecx
  int v50; // esi
  unsigned __int16 v51; // ax
  unsigned __int16 v52; // cx
  int v53; // [esp-14h] [ebp-8Ch]
  void *v54; // [esp-10h] [ebp-88h]
  _iobuf *v55; // [esp-8h] [ebp-80h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-6Ch] BYREF
  char *arglistsave; // [esp+1Ch] [ebp-5Ch]
  int malloc_flag; // [esp+20h] [ebp-58h]
  char *v59; // [esp+24h] [ebp-54h]
  int decimal; // [esp+28h] [ebp-50h] BYREF
  unsigned int nFloatStrSz; // [esp+2Ch] [ebp-4Ch] BYREF
  char *table; // [esp+30h] [ebp-48h]
  int malloc_FloatStrFlag; // [esp+34h] [ebp-44h] BYREF
  int count; // [esp+38h] [ebp-40h]
  void *start; // [esp+3Ch] [ebp-3Ch]
  const wchar_t *v66; // [esp+40h] [ebp-38h]
  void *pointer; // [esp+44h] [ebp-34h]
  int temp; // [esp+48h] [ebp-30h] BYREF
  int widthset; // [esp+4Ch] [ebp-2Ch]
  char reject; // [esp+53h] [ebp-25h]
  unsigned __int64 num64; // [esp+54h] [ebp-24h]
  int comchr; // [esp+5Ch] [ebp-1Ch]
  int started; // [esp+60h] [ebp-18h]
  wchar_t *pFloatStr; // [esp+64h] [ebp-14h] BYREF
  char negative; // [esp+69h] [ebp-Fh]
  char match; // [esp+6Ah] [ebp-Eh]
  char fl_wchar_arg; // [esp+6Bh] [ebp-Dh]
  _iobuf *fileptr; // [esp+6Ch] [ebp-Ch]
  char suppress; // [esp+71h] [ebp-7h]
  char longone; // [esp+72h] [ebp-6h]
  char widechar; // [esp+73h] [ebp-5h]
  int width; // [esp+74h] [ebp-4h]
  unsigned __int16 chr[2]; // [esp+78h] [ebp+0h]
  int charcount; // [esp+7Ch] [ebp+4h] BYREF
  char done_flag; // [esp+83h] [ebp+Bh]
  wchar_t floatstring[350]; // [esp+84h] [ebp+Ch] BYREF

  v5 = format;
  v59 = arglist;
  fileptr = stream;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  table = nullptr;
  malloc_flag = 0;
  *(_DWORD *)chr = 0;
  if ( format == nullptr || stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2: (unsigned int)format, a3: 0);
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v7 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v7 == 0 )
    goto LABEL_273;
LABEL_5:
  if ( iswctype(c: v7, mask: 8u) != 0 )
  {
    v55 = fileptr;
    --charcount;
    v8 = whiteout_0(counter: &charcount, fileptr);
    un_inc(chr: v8, fileptr: v55);
    do
      ++v5;
    while ( iswctype(c: *v5, mask: 8u) != 0 );
    goto LABEL_260;
  }
  if ( *v5 != 37 )
  {
    ++charcount;
    v51 = _fgetwc_nolock(stream: fileptr);
    v52 = *v5++;
    *(_DWORD *)chr = v51;
    v66 = v5;
    if ( v52 == v51 )
      goto LABEL_256;
    goto LABEL_262;
  }
  start = nullptr;
  started = 0;
  widthset = 0;
  width = 0;
  reject = 0;
  negative = 0;
  suppress = 0;
  done_flag = 0;
  fl_wchar_arg = 0;
  widechar = 0;
  longone = 1;
  temp = 0;
  do
  {
    v9 = *++v5;
    if ( (v9 & 0xFF00) == 0 && isdigit(c: (unsigned __int8)v9) != 0 )
    {
      ++widthset;
      width = 10 * width + v9 - 48;
      continue;
    }
    if ( v9 > 78 )
    {
      if ( v9 == 104 )
      {
        --longone;
        --widechar;
      }
      else
      {
        if ( v9 == 108 )
        {
          v11 = v5 + 1;
          if ( v5[1] == 108 )
            goto LABEL_23;
          ++longone;
        }
        else if ( v9 != 119 )
        {
          goto DEFAULT_LABEL_1;
        }
        ++widechar;
      }
    }
    else
    {
      switch ( v9 )
      {
        case 'N':
          continue;
        case '*':
          ++suppress;
          continue;
        case 'F':
          continue;
        default:
          break;
      }
      if ( v9 != 73 )
      {
        if ( v9 == 76 )
        {
          ++longone;
          continue;
        }
DEFAULT_LABEL_1:
        ++done_flag;
        continue;
      }
      v10 = v5[1];
      if ( v10 == 54 )
      {
        v11 = v5 + 2;
        if ( v5[2] == 52 )
        {
LABEL_23:
          ++temp;
          v5 = v11;
          num64 = 0;
          continue;
        }
      }
      if ( v10 == 51 && v5[2] == 50 )
      {
        v5 += 2;
        continue;
      }
      if ( v10 != 100 && v10 != 105 && v10 != 111 && v10 != 120 && v10 != 88 )
        goto DEFAULT_LABEL_1;
    }
  }
  while ( done_flag == 0 );
  v66 = v5;
  if ( suppress != 0 )
  {
    v12 = nullptr;
  }
  else
  {
    v12 = *(_QWORD **)v59;
    arglistsave = v59;
    v59 += 4;
  }
  pointer = v12;
  done_flag = 0;
  if ( widechar == 0 )
  {
    v13 = *v5;
    if ( *v5 == 83 || (widechar = 1, v13 == 67) )
      widechar = -1;
  }
  comchr = *v5 | 0x20;
  v14 = comchr;
  if ( comchr != 110 )
  {
    if ( comchr == 99 || comchr == 123 )
    {
      ++charcount;
      v15 = _fgetwc_nolock(stream: fileptr);
    }
    else
    {
      v15 = whiteout_0(counter: &charcount, fileptr);
      v14 = comchr;
    }
    *(_DWORD *)chr = v15;
    if ( v15 == 0xFFFF )
      goto error_return_2;
    v12 = pointer;
    v5 = v66;
  }
  if ( widthset != 0 && width == 0 )
    goto LABEL_262;
  if ( v14 <= 111 )
  {
    if ( v14 == 111 )
      goto LABEL_199;
    if ( v14 != 99 )
    {
      if ( v14 != 100 )
      {
        if ( v14 <= 100 )
          goto LABEL_139;
        if ( v14 > 103 )
        {
          if ( v14 != 105 )
          {
            if ( v14 == 110 )
            {
              v16 = charcount;
              if ( suppress != 0 )
                goto LABEL_254;
              goto assign_num_1;
            }
LABEL_139:
            if ( *v5 == chr[0] )
            {
              --match;
              if ( suppress == 0 )
                v59 = arglistsave;
              goto LABEL_254;
            }
LABEL_262:
            un_inc(chr: chr[0], fileptr);
            goto error_return_2;
          }
          comchr = 100;
LABEL_70:
          LOWORD(v17) = chr[0];
          if ( chr[0] == 45 )
          {
            negative = 1;
            goto x_incwidth_1;
          }
          if ( chr[0] == 43 )
          {
x_incwidth_1:
            if ( --width != 0 || widthset == 0 )
            {
              ++charcount;
              LOWORD(v17) = _fgetwc_nolock(stream: fileptr);
              *(_DWORD *)chr = (unsigned __int16)v17;
            }
            else
            {
              done_flag = 1;
            }
          }
          if ( (_WORD)v17 == 48 )
          {
            ++charcount;
            v46 = _fgetwc_nolock(stream: fileptr);
            LOWORD(v17) = v46;
            *(_DWORD *)chr = v46;
            if ( v46 == 120 || v46 == 88 )
            {
              ++charcount;
              LOWORD(v17) = _fgetwc_nolock(stream: fileptr);
              *(_DWORD *)chr = (unsigned __int16)v17;
              if ( widthset != 0 )
              {
                width -= 2;
                if ( width < 1 )
                  ++done_flag;
              }
              comchr = 120;
              goto getnum_1;
            }
            started = 1;
            if ( comchr != 120 )
            {
              if ( widthset != 0 && --width == 0 )
                ++done_flag;
              comchr = 111;
              goto getnum_1;
            }
            --charcount;
            un_inc(chr: v46, fileptr);
            v17 = 48;
LABEL_206:
            *(_DWORD *)chr = v17;
          }
          goto getnum_1;
        }
        v18 = 0;
        if ( chr[0] == 45 )
        {
          *pFloatStr = 45;
          v18 = 1;
          goto f_incwidth_1;
        }
        if ( chr[0] == 43 )
        {
f_incwidth_1:
          --width;
          ++charcount;
          *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr);
        }
        if ( widthset == 0 )
          width = -1;
        if ( (chr[0] & 0xFF00) == 0 )
        {
          do
          {
            if ( isdigit(c: LOBYTE(chr[0])) == 0 )
              break;
            v19 = width--;
            if ( v19 == 0 )
              break;
            ++started;
            pFloatStr[v18++] = SLOBYTE(chr[0]);
            if ( _check_float_string_0(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: v18,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_2;
            ++charcount;
            v20 = _fgetwc_nolock(stream: fileptr);
            *(_DWORD *)chr = v20;
          }
          while ( (v20 & 0xFF00) == 0 );
        }
        decimal = 46;
        _mbtowc_l(
          pwc: (wchar_t *)&decimal,
          s: _loc_update.localeinfo.locinfo->lconv->decimal_point,
          n: _loc_update.localeinfo.locinfo->mb_cur_max,
          plocinfo: &_loc_update.localeinfo);
        if ( (unsigned __int16)decimal == SLOBYTE(chr[0]) )
        {
          v21 = width--;
          if ( v21 != 0 )
          {
            ++charcount;
            *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr);
            pFloatStr[v18++] = decimal;
            if ( _check_float_string_0(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: v18,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_2;
            if ( (chr[0] & 0xFF00) == 0 )
            {
              do
              {
                if ( isdigit(c: LOBYTE(chr[0])) == 0 )
                  break;
                v22 = width--;
                if ( v22 == 0 )
                  break;
                ++started;
                pFloatStr[v18++] = chr[0];
                if ( _check_float_string_0(
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       nFloatStrUsed: v18,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return_2;
                ++charcount;
                v23 = _fgetwc_nolock(stream: fileptr);
                *(_DWORD *)chr = v23;
              }
              while ( (v23 & 0xFF00) == 0 );
            }
          }
        }
        if ( started != 0 && (chr[0] == 101 || chr[0] == 69) )
        {
          v24 = width--;
          if ( v24 != 0 )
          {
            pFloatStr[v18++] = 101;
            if ( _check_float_string_0(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: v18,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return_2;
            ++charcount;
            v25 = _fgetwc_nolock(stream: fileptr);
            *(_DWORD *)chr = v25;
            if ( v25 == 45 )
            {
              pFloatStr[v18++] = 45;
              if ( _check_float_string_0(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: v18,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return_2;
f_incwidth2_1:
              v26 = width--;
              if ( v26 != 0 )
              {
                ++charcount;
                *(_DWORD *)chr = _fgetwc_nolock(stream: fileptr);
              }
              else
              {
                width = 0;
              }
            }
            else if ( chr[0] == 43 )
            {
              goto f_incwidth2_1;
            }
            if ( (chr[0] & 0xFF00) == 0 )
            {
              do
              {
                if ( isdigit(c: LOBYTE(chr[0])) == 0 )
                  break;
                v27 = width--;
                if ( v27 == 0 )
                  break;
                ++started;
                pFloatStr[v18++] = chr[0];
                if ( _check_float_string_0(
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       nFloatStrUsed: v18,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return_2;
                ++charcount;
                v28 = _fgetwc_nolock(stream: fileptr);
                *(_DWORD *)chr = v28;
              }
              while ( (v28 & 0xFF00) == 0 );
            }
          }
        }
        --charcount;
        un_inc(chr: chr[0], fileptr);
        if ( started != 0 )
        {
          if ( suppress != 0 )
            goto LABEL_254;
          v29 = nFloatStrSz;
          ++count;
          pFloatStr[v18] = 0;
          v30 = 2 * v29 + 2;
          v31 = (char *)MemAlloc_Alloc(nSize: v30);
          if ( v31 != nullptr )
          {
            v32 = wcstombs_s(pConvertedChars: nullptr, dst: v31, sizeInBytes: v30, src: pFloatStr, n: v30 - 1);
            if ( v32 != 0 && (v32 == 22 || v32 == 34) )
              _invoke_watson(a1: v32, a2: v33, a3: v34, a4: v18, a5: (unsigned int)v31, a6: 0);
            v54 = pointer;
            v53 = longone - 1;
            v35 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))_decode_pointer(codedptr: off_5C03BC);
            v35(a1: v53, a2: v54, a3: v31, a4: &_loc_update);
            free(pMem: v31);
            goto LABEL_254;
          }
        }
        goto error_return_2;
      }
LABEL_199:
      LOWORD(v17) = chr[0];
      if ( chr[0] == 45 )
      {
        negative = 1;
      }
      else if ( chr[0] != 43 )
      {
        goto getnum_1;
      }
      if ( --width != 0 || widthset == 0 )
      {
        ++charcount;
        v17 = _fgetwc_nolock(stream: fileptr);
        goto LABEL_206;
      }
      done_flag = 1;
getnum_1:
      if ( temp != 0 )
      {
        if ( done_flag == 0 )
        {
          while ( 1 )
          {
            if ( comchr == 120 || comchr == 112 )
            {
              if ( (v17 & 0xFF00) != 0 || isxdigit(c: (unsigned __int8)v17) == 0 )
              {
LABEL_223:
                --charcount;
                un_inc(chr: v17, fileptr);
                break;
              }
              num64 *= 16LL;
              LOWORD(v17) = hextodec(chr: v17);
              *(_DWORD *)chr = (unsigned __int16)v17;
            }
            else
            {
              if ( (v17 & 0xFF00) != 0 || isdigit(c: (unsigned __int8)v17) == 0 )
                goto LABEL_223;
              if ( comchr == 111 )
              {
                if ( (unsigned __int16)v17 >= 0x38u )
                  goto LABEL_223;
                num64 *= 8LL;
              }
              else
              {
                num64 *= 10LL;
              }
            }
            ++started;
            num64 += (unsigned __int16)v17 - 48;
            if ( widthset != 0 && --width == 0 )
              break;
            ++charcount;
            LOWORD(v17) = _fgetwc_nolock(stream: fileptr);
            *(_DWORD *)chr = (unsigned __int16)v17;
          }
        }
        v16 = (int)start;
        if ( negative != 0 )
          num64 = -(__int64)num64;
      }
      else
      {
        v16 = (int)start;
        if ( done_flag == 0 )
        {
          while ( 1 )
          {
            if ( comchr == 120 || comchr == 112 )
            {
              if ( (v17 & 0xFF00) != 0 || isxdigit(c: (unsigned __int8)v17) == 0 )
              {
LABEL_241:
                --charcount;
                un_inc(chr: v17, fileptr);
                break;
              }
              v50 = 16 * v16;
              LOWORD(v17) = hextodec(chr: v17);
              *(_DWORD *)chr = (unsigned __int16)v17;
            }
            else
            {
              if ( (v17 & 0xFF00) != 0 || isdigit(c: (unsigned __int8)v17) == 0 )
                goto LABEL_241;
              if ( comchr == 111 )
              {
                if ( (unsigned __int16)v17 >= 0x38u )
                  goto LABEL_241;
                v50 = 8 * v16;
              }
              else
              {
                v50 = 10 * v16;
              }
            }
            ++started;
            v16 = v50 + (unsigned __int16)v17 - 48;
            if ( widthset != 0 && --width == 0 )
              break;
            ++charcount;
            LOWORD(v17) = _fgetwc_nolock(stream: fileptr);
            *(_DWORD *)chr = (unsigned __int16)v17;
          }
        }
        if ( negative != 0 )
          v16 = -v16;
      }
      if ( comchr == 70 )
        started = 0;
      if ( started == 0 )
        goto error_return_2;
      if ( suppress != 0 )
        goto LABEL_254;
      ++count;
      v12 = pointer;
assign_num_1:
      if ( temp != 0 )
      {
        *v12 = num64;
      }
      else if ( longone != 0 )
      {
        *(_DWORD *)v12 = v16;
      }
      else
      {
        *(_WORD *)v12 = v16;
      }
      goto LABEL_254;
    }
    if ( widthset == 0 )
    {
      ++width;
      widthset = 1;
    }
LABEL_118:
    if ( widechar > 0 )
      fl_wchar_arg = 1;
scanit_1:
    --charcount;
    start = v12;
    un_inc(chr: chr[0], fileptr);
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_121:
        if ( widthset != 0 )
        {
          v36 = width--;
          if ( v36 == 0 )
          {
LABEL_192:
            if ( start == v12 )
              goto error_return_2;
            if ( suppress == 0 )
            {
              ++count;
              if ( v14 != 99 )
              {
                if ( fl_wchar_arg != 0 )
                  *(_WORD *)pointer = 0;
                else
                  *(_BYTE *)pointer = 0;
              }
            }
LABEL_254:
            ++match;
            v5 = ++v66;
LABEL_256:
            if ( chr[0] == 0xFFFF )
            {
              if ( *v5 == 37 && v66[1] == 110 )
              {
                v5 = v66;
                goto LABEL_260;
              }
              goto error_return_2;
            }
LABEL_260:
            v7 = *v5;
            if ( *v5 == 0 )
              goto error_return_2;
            goto LABEL_5;
          }
        }
        ++charcount;
        v37 = _fgetwc_nolock(stream: fileptr);
        *(_DWORD *)chr = v37;
        if ( v37 == 0xFFFF )
          goto LABEL_191;
        if ( v14 != 99 )
        {
          if ( v14 != 115 )
            goto LABEL_130;
          if ( v37 >= 9u && v37 <= 0xDu )
          {
LABEL_191:
            --charcount;
            un_inc(chr: v37, fileptr);
            goto LABEL_192;
          }
          if ( v37 == 32 )
          {
LABEL_130:
            if ( v14 != 123 || ((1 << (v37 & 7)) & (reject ^ table[v37 >> 3])) == 0 )
              goto LABEL_191;
          }
        }
        if ( suppress == 0 )
          break;
        start = (char *)start + 2;
      }
      if ( fl_wchar_arg != 0 )
        break;
      temp = 0;
      v47 = wctomb_s(pRetValue: &temp, dst: (char *)v12, sizeInBytes: 5u, wchar: v37);
      if ( v47 == 0 )
      {
        v12 = (_QWORD *)((char *)v12 + temp);
        goto LABEL_189;
      }
      if ( v47 == 22 || v47 == 34 )
        _invoke_watson(a1: v47, a2: v48, a3: v49, a4: (unsigned int)v12, a5: 0, a6: v14);
    }
    *(_WORD *)v12 = v37;
    v12 = (_QWORD *)((char *)v12 + 2);
LABEL_189:
    pointer = v12;
    goto LABEL_121;
  }
  switch ( v14 )
  {
    case 'p':
      longone = 1;
      goto LABEL_199;
    case 's':
      goto LABEL_118;
    case 'u':
      goto LABEL_199;
    case 'x':
      goto LABEL_70;
    default:
      break;
  }
  if ( v14 != 123 )
    goto LABEL_139;
  if ( widechar > 0 )
    fl_wchar_arg = 1;
  v38 = (unsigned __int16 *)(v5 + 1);
  if ( *v38 == 94 )
  {
    ++v38;
    reject = -1;
  }
  if ( table == nullptr )
  {
    table = (char *)MemAlloc_Alloc(nSize: 0x2000u);
    if ( table == nullptr )
      goto error_return_2;
    malloc_flag = 1;
  }
  v39 = table;
  memset(dst: (int)table, value: nullptr, count: 0x2000u);
  if ( *v38 == 93 )
  {
    v40 = 93;
    ++v38;
    v39[11] = 32;
  }
  else
  {
    v40 = 0;
  }
  while ( 1 )
  {
    v45 = *v38;
    if ( *v38 == 93 )
      break;
    ++v38;
    if ( v45 == 45 && v40 != 0 && (v41 = *v38, *v38 != 93) )
    {
      ++v38;
      if ( v40 >= v41 )
      {
        v42 = v40;
        v40 = v41;
      }
      else
      {
        v42 = v41;
      }
      if ( v40 <= v42 )
      {
        v43 = v40;
        v44 = (unsigned __int16)(v42 - v40 + 1);
        do
        {
          table[v43 >> 3] |= 1 << (v43 & 7);
          ++v43;
          --v44;
        }
        while ( v44 != 0 );
      }
      v39 = table;
      v40 = 0;
    }
    else
    {
      v40 = v45;
      v39[v45 >> 3] |= 1 << (v45 & 7);
    }
  }
  if ( *v38 != 0 )
  {
    v12 = pointer;
    v14 = comchr;
    v66 = v38;
    goto scanit_1;
  }
error_return_2:
  if ( malloc_flag == 1 )
    free(pMem: table);
  if ( malloc_FloatStrFlag == 1 )
    free(pMem: pFloatStr);
  if ( chr[0] == 0xFFFF )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
LABEL_273:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x004DD47C
// Name: __wfltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _wfltin2(
        _flt *flt,
        const wchar_t *str,
        int len_ignore,
        int scale_ignore,
        int radix_ignore,
        localeinfo_struct *_Locale)
{
  int v6; // ebx
  INTRNCVT_STATUS v7; // eax
  const wchar_t *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const wchar_t *v10; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v10 = str;
  v6 = 0;
  flags = __wstrgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v6 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v7 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v7 == INTRNCVT_OVERFLOW )
      v6 = 128;
    if ( (flags & 1) != 0 || v7 == INTRNCVT_UNDERFLOW )
      v6 |= 0x100u;
  }
  flt->nbytes = EndPtr - v10;
  flt->dval = x.x;
  flt->flags = v6;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x004DD523
// Name: ___wstrgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall __wstrgtold12_l@<eax>(
        unsigned int a1@<ebx>,
        _LDBL12 *pld12,
        const wchar_t **p_end_ptr,
        const wchar_t *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v9; // ecx
  const wchar_t *v11; // edx
  wchar_t v12; // ax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  const wchar_t *v16; // edx
  char *v17; // ecx
  char *v18; // ecx
  int v19; // eax
  int v20; // eax
  bool v21; // zf
  int v22; // eax
  char *v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  _LDBL12 *v27; // esi
  char v28; // al
  int v29; // eax
  _LDBL12 *v30; // eax
  _LDBL12 *v31; // ebx
  __int16 v32; // dx
  __int16 v33; // ax
  unsigned __int16 v34; // dx
  __int16 v35; // ax
  unsigned __int16 v36; // di
  int v37; // eax
  _WORD *v38; // esi
  unsigned int v39; // ecx
  unsigned int v40; // edx
  unsigned int v41; // ebx
  __int16 v42; // di
  unsigned int v43; // ecx
  int v44; // esi
  int v45; // ecx
  int v46; // esi
  unsigned int v47; // ecx
  int v48; // ebx
  int v49; // ecx
  __int16 v50; // cx
  int v51; // esi
  unsigned int v52; // edx
  __int16 v53; // ax
  int v54; // [esp-8h] [ebp-8Ch]
  int v55; // [esp-8h] [ebp-8Ch]
  __int16 man_sign; // [esp+Ch] [ebp-78h]
  unsigned int result_flags; // [esp+10h] [ebp-74h]
  _LDBL12 *v58; // [esp+14h] [ebp-70h]
  int found_decpoint; // [esp+18h] [ebp-6Ch]
  unsigned __int8 *found_decpointa; // [esp+18h] [ebp-6Ch]
  int pow; // [esp+1Ch] [ebp-68h]
  int powa; // [esp+1Ch] [ebp-68h]
  int exp_sign; // [esp+20h] [ebp-64h]
  int exp_signa; // [esp+20h] [ebp-64h]
  int found_exponent; // [esp+24h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+24h] [ebp-60h]
  int found_digit; // [esp+28h] [ebp-5Ch]
  int found_digita; // [esp+28h] [ebp-5Ch]
  char *manp; // [esp+2Ch] [ebp-58h]
  char *manpa; // [esp+2Ch] [ebp-58h]
  const wchar_t *savedp; // [esp+30h] [ebp-54h]
  int savedpa; // [esp+30h] [ebp-54h]
  int exp_adj; // [esp+34h] [ebp-50h]
  int exp_adja; // [esp+34h] [ebp-50h]
  unsigned int manlen; // [esp+38h] [ebp-4Ch]
  unsigned int manlena; // [esp+38h] [ebp-4Ch]
  __int64 v77; // [esp+3Ch] [ebp-48h] BYREF
  int v78; // [esp+44h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+48h] [ebp-3Ch] BYREF
  _BYTE v80[12]; // [esp+58h] [ebp-2Ch] BYREF
  char buf[28]; // [esp+64h] [ebp-20h] BYREF

  v9 = 0;
  manp = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2: 1u, a3: 0);
    return 0;
  }
  v11 = str;
  savedp = str;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    LOWORD(v13) = *v11++;
    switch ( v9 )
    {
      case 0:
        if ( (unsigned __int16)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( (unsigned __int16)v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v14 = (unsigned __int16)v13 - 43;
        if ( v14 == 0 )
        {
          man_sign = 0;
          v9 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( v15 == 0 )
        {
          v9 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int16)(v13 - 49) <= 8u )
          goto LABEL_11;
        v13 = (unsigned __int16)v13;
        if ( (unsigned __int16)v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( (unsigned __int16)v13 == 43 || (unsigned __int16)v13 == 45 )
          goto LABEL_32;
        if ( (unsigned __int16)v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (unsigned int)(v13 - 100) > 1 )
          goto LABEL_74;
        v55 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int16)(v13 - 49) <= 8u )
        {
LABEL_11:
          v54 = 3;
LABEL_12:
          v9 = v54;
          --v11;
        }
        else
        {
          if ( (unsigned __int16)v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v55 = 5;
            goto LABEL_15;
          }
          if ( (unsigned __int16)v13 != 48 )
          {
LABEL_36:
            v16 = savedp;
            goto LABEL_81;
          }
LABEL_19:
          v9 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( (unsigned __int16)v13 >= 0x30u && (unsigned __int16)v13 <= 0x39u )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            v17 = manp;
            ++manlen;
            ++manp;
            *v17 = v13 - 48;
          }
          LOWORD(v13) = *v11++;
        }
        v13 = (unsigned __int16)v13;
        if ( (unsigned __int16)v13 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_45;
LABEL_24:
        v55 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( (_WORD)v13 == 48 )
          {
            --exp_adj;
            LOWORD(v13) = *v11++;
          }
        }
        while ( (unsigned __int16)v13 >= 0x30u && (unsigned __int16)v13 <= 0x39u )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            v18 = manp++;
            --exp_adj;
            *v18 = v13 - 48;
          }
          LOWORD(v13) = *v11++;
        }
        v13 = (unsigned __int16)v13;
LABEL_45:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_32:
        --v11;
        v55 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int16)(v13 - 48) > 9u )
          goto LABEL_36;
        v54 = 4;
        goto LABEL_12;
      case 6:
        savedp = v11 - 2;
        if ( (unsigned __int16)(v13 - 49) <= 8u )
          goto LABEL_62;
        v19 = (unsigned __int16)v13 - 43;
        if ( v19 == 0 )
          goto LABEL_69;
        v20 = v19 - 2;
        if ( v20 == 0 )
          goto LABEL_68;
        v21 = v20 == 3;
LABEL_66:
        if ( !v21 )
          goto LABEL_36;
        v55 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int16)(v13 - 49) <= 8u )
          goto LABEL_62;
        v21 = (_WORD)v13 == 48;
        goto LABEL_66;
      case 8:
        found_exponent = 1;
        while ( (_WORD)v13 == 48 )
          LOWORD(v13) = *v11++;
        if ( (unsigned __int16)(v13 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v54 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v24 = 0;
        while ( 2 )
        {
          if ( (unsigned __int16)v13 >= 0x30u && (unsigned __int16)v13 <= 0x39u )
          {
            v24 = 10 * v24 + (unsigned __int16)v13 - 48;
            if ( v24 <= 5200 )
            {
              LOWORD(v13) = *v11++;
              continue;
            }
            v24 = 5201;
          }
          break;
        }
        pow = v24;
        while ( (unsigned __int16)v13 >= 0x30u && (unsigned __int16)v13 <= 0x39u )
          LOWORD(v13) = *v11++;
LABEL_74:
        v16 = v11 - 1;
        goto LABEL_81;
      case 11:
        if ( implicit_E != 0 )
        {
          v22 = (unsigned __int16)v13 - 43;
          savedp = v11 - 1;
          if ( v22 != 0 )
          {
            if ( v22 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_81;
            }
LABEL_68:
            exp_sign = -1;
            v9 = 7;
          }
          else
          {
LABEL_69:
            v55 = 7;
LABEL_15:
            v9 = v55;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_81:
        *p_end_ptr = v16;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_174:
          v50 = 0;
          v53 = 0;
          v52 = 0;
          v51 = 0;
          goto LABEL_175;
        }
        if ( manlen <= 0x18 )
        {
          v23 = manp;
        }
        else
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          manlen = 24;
          v23 = manp - 1;
          ++exp_adj;
        }
        if ( manlen == 0 )
          goto LABEL_174;
        while ( *--v23 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v25 = pow;
        if ( exp_sign < 0 )
          v25 = -pow;
        v26 = exp_adj + v25;
        if ( found_exponent == 0 )
          v26 += scale;
        if ( found_decpoint == 0 )
          v26 -= decpt;
        if ( v26 > 5200 )
        {
          v51 = 0;
          v53 = 0x7FFF;
          v52 = 0x80000000;
          v50 = 0;
          result_flags = 2;
          goto LABEL_175;
        }
        if ( v26 < -5200 )
        {
          result_flags = 1;
          goto LABEL_174;
        }
        v27 = &_pow10pos[-8];
        savedpa = v26;
        if ( v26 != 0 )
        {
          if ( v26 < 0 )
          {
            savedpa = -v26;
            v27 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          while ( savedpa != 0 )
          {
            v28 = savedpa;
            savedpa >>= 3;
            v27 += 7;
            v29 = v28 & 7;
            exp_adja = (int)v27;
            if ( v29 != 0 )
            {
              v30 = &v27[v29];
              v31 = v30;
              v58 = v30;
              if ( *(_WORD *)v30->ld12 >= 0x8000u )
              {
                v77 = *(_QWORD *)v30->ld12;
                v78 = *(_DWORD *)&v30->ld12[8];
                --*(_DWORD *)((char *)&v77 + 2);
                v31 = (_LDBL12 *)&v77;
                v58 = (_LDBL12 *)&v77;
              }
              v32 = *(_WORD *)&v31->ld12[10];
              manpa = nullptr;
              memset(v80, 0, sizeof(v80));
              v33 = *(_WORD *)&tmpld12.ld12[10] ^ v32;
              v34 = v32 & 0x7FFF;
              v35 = v33 & 0x8000;
              v36 = v34 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF || v34 >= 0x7FFFu || v36 > 0xBFFDu )
              {
LABEL_167:
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                v37 = v35 != 0 ? -32768 : 2147450880;
                *(_DWORD *)tmpld12.ld12 = 0;
                goto LABEL_168;
              }
              if ( v36 <= 0x3FBFu )
              {
                v37 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_168:
                *(_DWORD *)&tmpld12.ld12[8] = v37;
                continue;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v36, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v34 != 0
                  || (++v36, (*(_DWORD *)&v31->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v31->ld12[4] != 0
                  || *(_DWORD *)v31->ld12 != 0 )
                {
                  exp_signa = 0;
                  v38 = &v80[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v31->ld12[8];
                    do
                    {
                      manlena = 0;
                      v39 = *(unsigned __int16 *)found_exponenta * *(unsigned __int16 *)found_decpointa;
                      v40 = *((_DWORD *)v38 - 1);
                      v41 = v40 + v39;
                      if ( v40 + v39 < v40 || v41 < v39 )
                        manlena = 1;
                      *((_DWORD *)v38 - 1) = v41;
                      if ( manlena != 0 )
                        ++*v38;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    v31 = v58;
                    ++v38;
                    ++exp_signa;
                  }
                  v42 = v36 - 16382;
                  if ( v42 <= 0 )
                    goto LABEL_178;
                  do
                  {
                    if ( *(int *)&v80[8] < 0 )
                      break;
                    v43 = *(_DWORD *)v80;
                    *(_DWORD *)v80 *= 2;
                    v44 = (v43 >> 31) | (2 * *(_DWORD *)&v80[4]);
                    v45 = *(__int64 *)&v80[4] >> 31;
                    --v42;
                    *(_DWORD *)&v80[4] = v44;
                    *(_DWORD *)&v80[8] = v45;
                  }
                  while ( v42 > 0 );
                  if ( v42 <= 0 )
                  {
LABEL_178:
                    if ( --v42 < 0 )
                    {
                      v46 = (unsigned __int16)-v42;
                      v42 = 0;
                      do
                      {
                        if ( (v80[0] & 1) != 0 )
                          ++manpa;
                        v47 = *(_DWORD *)&v80[8];
                        *(_DWORD *)&v80[8] >>= 1;
                        v48 = __SPAIR64__(v47, *(unsigned int *)&v80[4]) >> 1;
                        v49 = *(__int64 *)v80 >> 1;
                        --v46;
                        *(_DWORD *)&v80[4] = v48;
                        *(_DWORD *)v80 = v49;
                      }
                      while ( v46 != 0 );
                      if ( manpa != nullptr )
                        *(_WORD *)v80 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v80 > 0x8000u || (*(_DWORD *)v80 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v80[2] == -1 )
                    {
                      *(_DWORD *)&v80[2] = 0;
                      if ( *(_DWORD *)&v80[6] == -1 )
                      {
                        *(_DWORD *)&v80[6] = 0;
                        if ( *(_WORD *)&v80[10] == 0xFFFF )
                        {
                          *(_WORD *)&v80[10] = 0x8000;
                          ++v42;
                        }
                        else
                        {
                          ++*(_WORD *)&v80[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v80[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v80[2];
                    }
                  }
                  v27 = (_LDBL12 *)exp_adja;
                  if ( (unsigned __int16)v42 >= 0x7FFFu )
                    goto LABEL_167;
                  *(_WORD *)tmpld12.ld12 = *(_WORD *)&v80[2];
                  *(_QWORD *)&tmpld12.ld12[2] = *(_QWORD *)&v80[4];
                  *(_WORD *)&tmpld12.ld12[10] = v35 | v42;
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
            }
          }
        }
        v50 = *(_WORD *)tmpld12.ld12;
        v51 = *(_DWORD *)&tmpld12.ld12[2];
        v52 = *(_DWORD *)&tmpld12.ld12[6];
        v53 = *(_WORD *)&tmpld12.ld12[10];
LABEL_175:
        *(_WORD *)pld12->ld12 = v50;
        *(_WORD *)&pld12->ld12[10] = man_sign | v53;
        *(_DWORD *)&pld12->ld12[2] = v51;
        *(_DWORD *)&pld12->ld12[6] = v52;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DDC47
// Name: _get_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall get_lc_time@<eax>(__lc_time_data *lc_time@<esi>, threadlocaleinfostruct *ploci@<eax>)
{
  unsigned int wLanguage; // ecx
  unsigned int wCountry; // edx
  int result; // eax
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // edi
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // edi
  int v28; // edi
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  int v33; // edi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  int v37; // edi
  int v38; // edi
  int v39; // edi
  int v40; // edi
  int v41; // edi
  int v42; // edi
  int v43; // edi
  int v44; // edi
  int v45; // edi
  int v46; // edi
  int v47; // edi
  unsigned int v48; // ebx
  localeinfo_struct locinfo; // [esp+0h] [ebp-10h] BYREF
  unsigned int ctryid; // [esp+8h] [ebp-8h]
  unsigned int langid; // [esp+Ch] [ebp-4h]

  wLanguage = ploci->lc_id[5].wLanguage;
  wCountry = ploci->lc_id[5].wCountry;
  langid = wLanguage;
  ctryid = wCountry;
  if ( lc_time == nullptr )
    return -1;
  locinfo.mbcinfo = nullptr;
  locinfo.locinfo = ploci;
  v5 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: wLanguage,
         fieldtype: 0x31u,
         address: &lc_time->wday_abbr[1]);
  v6 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: langid,
         fieldtype: 0x32u,
         address: &lc_time->wday_abbr[2])
     | v5;
  v7 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: langid,
         fieldtype: 0x33u,
         address: &lc_time->wday_abbr[3])
     | v6;
  v8 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: langid,
         fieldtype: 0x34u,
         address: &lc_time->wday_abbr[4])
     | v7;
  v9 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: langid,
         fieldtype: 0x35u,
         address: &lc_time->wday_abbr[5])
     | v8;
  v10 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x36u,
          address: &lc_time->wday_abbr[6])
      | v9;
  v11 = __getlocaleinfo(plocinfo: &locinfo, lc_type: 1, localehandle: langid, fieldtype: 0x37u, address: lc_time) | v10;
  v12 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x2Au,
          address: &lc_time->wday[1])
      | v11;
  v13 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x2Bu,
          address: &lc_time->wday[2])
      | v12;
  v14 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x2Cu,
          address: &lc_time->wday[3])
      | v13;
  v15 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x2Du,
          address: &lc_time->wday[4])
      | v14;
  v16 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x2Eu,
          address: &lc_time->wday[5])
      | v15;
  v17 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x2Fu,
          address: &lc_time->wday[6])
      | v16;
  v18 = __getlocaleinfo(plocinfo: &locinfo, lc_type: 1, localehandle: langid, fieldtype: 0x30u, address: lc_time->wday)
      | v17;
  v19 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x44u,
          address: lc_time->month_abbr)
      | v18;
  v20 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x45u,
          address: &lc_time->month_abbr[1])
      | v19;
  v21 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x46u,
          address: &lc_time->month_abbr[2])
      | v20;
  v22 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x47u,
          address: &lc_time->month_abbr[3])
      | v21;
  v23 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x48u,
          address: &lc_time->month_abbr[4])
      | v22;
  v24 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x49u,
          address: &lc_time->month_abbr[5])
      | v23;
  v25 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x4Au,
          address: &lc_time->month_abbr[6])
      | v24;
  v26 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x4Bu,
          address: &lc_time->month_abbr[7])
      | v25;
  v27 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x4Cu,
          address: &lc_time->month_abbr[8])
      | v26;
  v28 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x4Du,
          address: &lc_time->month_abbr[9])
      | v27;
  v29 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x4Eu,
          address: &lc_time->month_abbr[10])
      | v28;
  v30 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x4Fu,
          address: &lc_time->month_abbr[11])
      | v29;
  v31 = __getlocaleinfo(plocinfo: &locinfo, lc_type: 1, localehandle: langid, fieldtype: 0x38u, address: lc_time->month)
      | v30;
  v32 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x39u,
          address: &lc_time->month[1])
      | v31;
  v33 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x3Au,
          address: &lc_time->month[2])
      | v32;
  v34 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x3Bu,
          address: &lc_time->month[3])
      | v33;
  v35 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x3Cu,
          address: &lc_time->month[4])
      | v34;
  v36 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x3Du,
          address: &lc_time->month[5])
      | v35;
  v37 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x3Eu,
          address: &lc_time->month[6])
      | v36;
  v38 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x3Fu,
          address: &lc_time->month[7])
      | v37;
  v39 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x40u,
          address: &lc_time->month[8])
      | v38;
  v40 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x41u,
          address: &lc_time->month[9])
      | v39;
  v41 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x42u,
          address: &lc_time->month[10])
      | v40;
  v42 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x43u,
          address: &lc_time->month[11])
      | v41;
  v43 = __getlocaleinfo(plocinfo: &locinfo, lc_type: 1, localehandle: langid, fieldtype: 0x28u, address: lc_time->ampm)
      | v42;
  v44 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: langid,
          fieldtype: 0x29u,
          address: &lc_time->ampm[1])
      | v43;
  v45 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: ctryid,
          fieldtype: 0x1Fu,
          address: &lc_time->ww_sdatefmt)
      | v44;
  v46 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: ctryid,
          fieldtype: 0x20u,
          address: &lc_time->ww_ldatefmt)
      | v45;
  v47 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: ctryid,
          fieldtype: 0x1003u,
          address: &lc_time->ww_timefmt)
      | v46;
  v48 = ctryid;
  result = __getlocaleinfo(
             plocinfo: &locinfo,
             lc_type: 0,
             localehandle: ctryid,
             fieldtype: 0x1009u,
             address: &lc_time->ww_caltype)
         | v47;
  lc_time->ww_lcid = v48;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DE060
// Name: ___free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lc_time(__lc_time_data *lc_time)
{
  if ( lc_time != nullptr )
  {
    free(pMem: lc_time->wday_abbr[1]);
    free(pMem: lc_time->wday_abbr[2]);
    free(pMem: lc_time->wday_abbr[3]);
    free(pMem: lc_time->wday_abbr[4]);
    free(pMem: lc_time->wday_abbr[5]);
    free(pMem: lc_time->wday_abbr[6]);
    free(pMem: lc_time->wday_abbr[0]);
    free(pMem: lc_time->wday[1]);
    free(pMem: lc_time->wday[2]);
    free(pMem: lc_time->wday[3]);
    free(pMem: lc_time->wday[4]);
    free(pMem: lc_time->wday[5]);
    free(pMem: lc_time->wday[6]);
    free(pMem: lc_time->wday[0]);
    free(pMem: lc_time->month_abbr[0]);
    free(pMem: lc_time->month_abbr[1]);
    free(pMem: lc_time->month_abbr[2]);
    free(pMem: lc_time->month_abbr[3]);
    free(pMem: lc_time->month_abbr[4]);
    free(pMem: lc_time->month_abbr[5]);
    free(pMem: lc_time->month_abbr[6]);
    free(pMem: lc_time->month_abbr[7]);
    free(pMem: lc_time->month_abbr[8]);
    free(pMem: lc_time->month_abbr[9]);
    free(pMem: lc_time->month_abbr[10]);
    free(pMem: lc_time->month_abbr[11]);
    free(pMem: lc_time->month[0]);
    free(pMem: lc_time->month[1]);
    free(pMem: lc_time->month[2]);
    free(pMem: lc_time->month[3]);
    free(pMem: lc_time->month[4]);
    free(pMem: lc_time->month[5]);
    free(pMem: lc_time->month[6]);
    free(pMem: lc_time->month[7]);
    free(pMem: lc_time->month[8]);
    free(pMem: lc_time->month[9]);
    free(pMem: lc_time->month[10]);
    free(pMem: lc_time->month[11]);
    free(pMem: lc_time->ampm[0]);
    free(pMem: lc_time->ampm[1]);
    free(pMem: lc_time->ww_sdatefmt);
    free(pMem: lc_time->ww_ldatefmt);
    free(pMem: lc_time->ww_timefmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DE1F0
// Name: ___init_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_time(threadlocaleinfostruct *ploci)
{
  __lc_time_data *v1; // esi
  __lc_time_data **p_lc_time_curr; // edi

  if ( ploci->lc_handle[5] != 0 )
  {
    v1 = (__lc_time_data *)calloc(count: 1u, size: 0xB8u);
    if ( v1 == nullptr )
      return 1;
    if ( get_lc_time(lc_time: v1, ploci) != 0 )
    {
      __free_lc_time(lc_time: v1);
      free(pMem: v1);
      return 1;
    }
    v1->refcount = 1;
  }
  else
  {
    v1 = &__lc_time_c;
  }
  p_lc_time_curr = &ploci->lc_time_curr;
  if ( ploci->lc_time_curr != &__lc_time_c )
    InterlockedDecrement(lpAddend: &(*p_lc_time_curr)->refcount);
  *p_lc_time_curr = v1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DE263
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_num(lconv *l)
{
  char *grouping; // esi

  if ( l != nullptr )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(pMem: l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(pMem: l->thousands_sep);
    grouping = l->grouping;
    if ( grouping != __lconv_c.grouping )
      free(pMem: grouping);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DE2A3
// Name: ___init_numeric
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_numeric(lconv *ploci)
{
  bool v2; // zf
  lconv *v3; // eax
  int *v5; // eax
  int *v6; // eax
  int v7; // esi
  unsigned int int_curr_symbol_high; // edi
  int v9; // eax
  int v10; // eax
  char *v11; // eax
  char v12; // cl
  char *v13; // esi
  localeinfo_struct locinfo; // [esp+Ch] [ebp-18h] BYREF
  char **p_grouping; // [esp+14h] [ebp-10h]
  int ret; // [esp+18h] [ebp-Ch]
  int *lc_refcount; // [esp+1Ch] [ebp-8h]
  int *lconv_num_refcount; // [esp+20h] [ebp-4h]
  lconv *lc; // [esp+2Ch] [ebp+8h]

  v2 = ploci->mon_grouping == nullptr;
  locinfo.locinfo = (threadlocaleinfostruct *)ploci;
  locinfo.mbcinfo = nullptr;
  if ( !v2 || ploci->mon_thousands_sep != nullptr )
  {
    v3 = (lconv *)calloc(count: 1u, size: 0x30u);
    lc = v3;
    if ( v3 == nullptr )
      return 1;
    qmemcpy(v3, *(const void **)&ploci[3].n_cs_precedes, sizeof(lconv));
    v5 = (int *)MemAlloc_Alloc(nSize: 4u);
    lc_refcount = v5;
    if ( v5 == nullptr )
    {
      free(pMem: lc);
      return 1;
    }
    *v5 = 0;
    if ( ploci->mon_grouping == nullptr )
    {
      lc->decimal_point = __lconv_c.decimal_point;
      lc->thousands_sep = __lconv_c.thousands_sep;
      lconv_num_refcount = nullptr;
      lc->grouping = __lconv_c.grouping;
LABEL_26:
      *lc_refcount = 1;
      if ( lconv_num_refcount != nullptr )
        *lconv_num_refcount = 1;
      goto LABEL_28;
    }
    v6 = (int *)MemAlloc_Alloc(nSize: 4u);
    lconv_num_refcount = v6;
    if ( v6 == nullptr )
    {
      v7 = 1;
LABEL_11:
      free(pMem: lc);
      free(pMem: lc_refcount);
      return v7;
    }
    *v6 = 0;
    int_curr_symbol_high = HIWORD(ploci[1].int_curr_symbol);
    ret = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: int_curr_symbol_high,
            fieldtype: 0xEu,
            address: lc);
    v9 = __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 1,
           localehandle: int_curr_symbol_high,
           fieldtype: 0xFu,
           address: &lc->thousands_sep);
    ret |= v9;
    p_grouping = &lc->grouping;
    v10 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: int_curr_symbol_high,
            fieldtype: 0x10u,
            address: &lc->grouping);
    if ( (ret | v10) != 0 )
    {
      __free_lconv_num(l: lc);
      v7 = -1;
      goto LABEL_11;
    }
    v11 = *p_grouping;
    while ( 1 )
    {
      if ( *v11 == 0 )
        goto LABEL_26;
      v12 = *v11;
      if ( *v11 >= 48 && v12 <= 57 )
        break;
      if ( v12 == 59 )
      {
        v13 = v11;
        do
        {
          *v13 = v13[1];
          ++v13;
        }
        while ( *v13 != 0 );
      }
      else
      {
LABEL_18:
        ++v11;
      }
    }
    *v11 = v12 - 48;
    goto LABEL_18;
  }
  lconv_num_refcount = nullptr;
  lc_refcount = nullptr;
  lc = &__lconv_c;
LABEL_28:
  if ( ploci[3].negative_sign != nullptr )
    InterlockedDecrement(lpAddend: (volatile LONG *)ploci[3].negative_sign);
  if ( ploci[3].positive_sign != nullptr && InterlockedDecrement(lpAddend: (volatile LONG *)ploci[3].positive_sign) == 0 )
  {
    free(pMem: ploci[3].positive_sign);
    free(pMem: *(void **)&ploci[3].n_cs_precedes);
  }
  ploci[3].negative_sign = (char *)lconv_num_refcount;
  ploci[3].positive_sign = (char *)lc_refcount;
  *(_DWORD *)&ploci[3].n_cs_precedes = lc;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DE46B
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_mon(lconv *l)
{
  char *negative_sign; // esi

  if ( l != nullptr )
  {
    if ( l->int_curr_symbol != __lconv_c.int_curr_symbol )
      free(pMem: l->int_curr_symbol);
    if ( l->currency_symbol != __lconv_c.currency_symbol )
      free(pMem: l->currency_symbol);
    if ( l->mon_decimal_point != __lconv_c.mon_decimal_point )
      free(pMem: l->mon_decimal_point);
    if ( l->mon_thousands_sep != __lconv_c.mon_thousands_sep )
      free(pMem: l->mon_thousands_sep);
    if ( l->mon_grouping != __lconv_c.mon_grouping )
      free(pMem: l->mon_grouping);
    if ( l->positive_sign != __lconv_c.positive_sign )
      free(pMem: l->positive_sign);
    negative_sign = l->negative_sign;
    if ( negative_sign != __lconv_c.negative_sign )
      free(pMem: negative_sign);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DE4F4
// Name: ___init_monetary
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_monetary(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // esi
  bool v2; // zf
  lconv *v3; // ebx
  int *v5; // eax
  int *v6; // eax
  unsigned int wCountry; // esi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  char *mon_grouping; // eax
  char v23; // cl
  char *v24; // esi
  int *v25; // ecx
  localeinfo_struct locinfo; // [esp+Ch] [ebp-10h] BYREF
  int *lc_refcount; // [esp+14h] [ebp-8h]
  int *lconv_mon_refcount; // [esp+18h] [ebp-4h]

  v1 = ploci;
  v2 = ploci->lc_handle[3] == 0;
  lconv_mon_refcount = nullptr;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = nullptr;
  if ( !v2 || ploci->lc_handle[4] != 0 )
  {
    v3 = (lconv *)calloc(count: 1u, size: 0x30u);
    if ( v3 == nullptr )
      return 1;
    v5 = (int *)MemAlloc_Alloc(nSize: 4u);
    lc_refcount = v5;
    if ( v5 == nullptr )
    {
      free(pMem: v3);
      return 1;
    }
    *v5 = 0;
    if ( ploci->lc_handle[3] == 0 )
    {
      qmemcpy(v3, &__lconv_c, sizeof(lconv));
LABEL_25:
      v1 = ploci;
      v3->decimal_point = ploci->lconv->decimal_point;
      v3->thousands_sep = ploci->lconv->thousands_sep;
      v25 = lc_refcount;
      v3->grouping = ploci->lconv->grouping;
      v2 = lconv_mon_refcount == nullptr;
      *v25 = 1;
      if ( !v2 )
        *lconv_mon_refcount = 1;
      goto LABEL_27;
    }
    v6 = (int *)MemAlloc_Alloc(nSize: 4u);
    lconv_mon_refcount = v6;
    if ( v6 == nullptr )
    {
      free(pMem: v3);
      free(pMem: lc_refcount);
      return 1;
    }
    *v6 = 0;
    wCountry = ploci->lc_id[3].wCountry;
    v8 = __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 1,
           localehandle: wCountry,
           fieldtype: 0x15u,
           address: &v3->int_curr_symbol);
    v9 = __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 1,
           localehandle: wCountry,
           fieldtype: 0x14u,
           address: &v3->currency_symbol)
       | v8;
    v10 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x16u,
            address: &v3->mon_decimal_point)
        | v9;
    v11 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x17u,
            address: &v3->mon_thousands_sep)
        | v10;
    v12 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x18u,
            address: &v3->mon_grouping)
        | v11;
    v13 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x50u,
            address: &v3->positive_sign)
        | v12;
    v14 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x51u,
            address: &v3->negative_sign)
        | v13;
    v15 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x1Au,
            address: &v3->int_frac_digits)
        | v14;
    v16 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x19u,
            address: &v3->frac_digits)
        | v15;
    v17 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x54u,
            address: &v3->p_cs_precedes)
        | v16;
    v18 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x55u,
            address: &v3->p_sep_by_space)
        | v17;
    v19 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x56u,
            address: &v3->n_cs_precedes)
        | v18;
    v20 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x57u,
            address: &v3->n_sep_by_space)
        | v19;
    v21 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x52u,
            address: &v3->p_sign_posn)
        | v20;
    if ( (v21
        | __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x53u,
            address: &v3->n_sign_posn)) != 0 )
    {
      __free_lconv_mon(l: v3);
      free(pMem: v3);
      free(pMem: lc_refcount);
      free(pMem: lconv_mon_refcount);
      return 1;
    }
    mon_grouping = v3->mon_grouping;
    while ( 1 )
    {
      if ( *mon_grouping == 0 )
        goto LABEL_25;
      v23 = *mon_grouping;
      if ( *mon_grouping >= 48 && v23 <= 57 )
        break;
      if ( v23 == 59 )
      {
        v24 = mon_grouping;
        do
        {
          *v24 = v24[1];
          ++v24;
        }
        while ( *v24 != 0 );
      }
      else
      {
LABEL_17:
        ++mon_grouping;
      }
    }
    *mon_grouping = v23 - 48;
    goto LABEL_17;
  }
  lconv_mon_refcount = nullptr;
  lc_refcount = nullptr;
  v3 = &__lconv_c;
LABEL_27:
  if ( v1->lconv_mon_refcount != nullptr )
    InterlockedDecrement(lpAddend: v1->lconv_mon_refcount);
  if ( v1->lconv_intl_refcount != nullptr && InterlockedDecrement(lpAddend: v1->lconv_intl_refcount) == 0 )
  {
    free(pMem: v1->lconv);
    free(pMem: v1->lconv_intl_refcount);
  }
  v1->lconv_mon_refcount = lconv_mon_refcount;
  v1->lconv_intl_refcount = lc_refcount;
  v1->lconv = v3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DE7B8
// Name: ___init_ctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_ctype(threadlocaleinfostruct *ploci)
{
  int v1; // ebx
  bool v2; // zf
  unsigned __int8 *v3; // eax
  int i; // eax
  unsigned __int8 *v5; // eax
  int v6; // ecx
  int v7; // edi
  bool v8; // cc
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // edx
  unsigned __int16 *v12; // ecx
  unsigned __int8 *v13; // ecx
  unsigned __int8 v14; // dl
  int v15; // ecx
  unsigned __int16 *j; // edx
  int *v17; // eax
  unsigned int lc_codepage; // [esp-Ch] [ebp-60h]
  localeinfo_struct locinfo; // [esp+Ch] [ebp-48h] BYREF
  const unsigned __int8 *v21; // [esp+14h] [ebp-40h]
  const unsigned __int16 *v22; // [esp+18h] [ebp-3Ch]
  unsigned __int16 *v23; // [esp+1Ch] [ebp-38h]
  const unsigned __int8 *v24; // [esp+20h] [ebp-34h]
  int mb_cur_max; // [esp+24h] [ebp-30h]
  int *refcount; // [esp+28h] [ebp-2Ch]
  unsigned __int8 *newcumap; // [esp+2Ch] [ebp-28h]
  unsigned __int16 *newctype1; // [esp+30h] [ebp-24h]
  unsigned __int8 *cbuffer; // [esp+34h] [ebp-20h]
  unsigned __int8 *newclmap; // [esp+38h] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+3Ch] [ebp-18h] BYREF

  v1 = 0;
  v2 = ploci->lc_handle[2] == 0;
  refcount = nullptr;
  newctype1 = nullptr;
  newclmap = nullptr;
  newcumap = nullptr;
  cbuffer = nullptr;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = nullptr;
  if ( v2 )
  {
    if ( ploci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ploci->ctype1_refcount);
    ploci->ctype1_refcount = nullptr;
    ploci->ctype1 = nullptr;
    ploci->pctype = asc_5A5CC0;
    ploci->pclmap = &__newclmap[128];
    ploci->pcumap = &__newcumap[128];
    ploci->mb_cur_max = 1;
    return 0;
  }
  else
  {
    if ( ploci->lc_codepage == 0
      && __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 0,
           localehandle: ploci->lc_id[2].wLanguage,
           fieldtype: 0x1004u,
           address: &ploci->lc_codepage) != 0 )
    {
      goto error_cleanup_1;
    }
    refcount = (int *)MemAlloc_Alloc(nSize: 4u);
    newctype1 = (unsigned __int16 *)calloc(count: 0x180u, size: 2u);
    newclmap = (unsigned __int8 *)calloc(count: 0x180u, size: 1u);
    newcumap = (unsigned __int8 *)calloc(count: 0x180u, size: 1u);
    v3 = (unsigned __int8 *)calloc(count: 0x101u, size: 1u);
    cbuffer = v3;
    if ( refcount == nullptr )
      goto error_cleanup_1;
    if ( newctype1 == nullptr )
      goto error_cleanup_1;
    if ( v3 == nullptr )
      goto error_cleanup_1;
    if ( newclmap == nullptr )
      goto error_cleanup_1;
    if ( newcumap == nullptr )
      goto error_cleanup_1;
    *refcount = 0;
    for ( i = 0; i < 256; ++i )
      cbuffer[i] = i;
    if ( !GetCPInfo(CodePage: ploci->lc_codepage, &lpCPInfo) || lpCPInfo.MaxCharSize > 5 )
      goto error_cleanup_1;
    mb_cur_max = LOWORD(lpCPInfo.MaxCharSize);
    if ( LOWORD(lpCPInfo.MaxCharSize) > 1u && lpCPInfo.LeadByte[0] != 0 )
    {
      v5 = &lpCPInfo.LeadByte[1];
      do
      {
        LOBYTE(v6) = *v5;
        if ( *v5 == 0 )
          break;
        v7 = *(v5 - 1);
        v6 = (unsigned __int8)v6;
        while ( v7 <= v6 )
        {
          cbuffer[v7] = 32;
          v6 = *v5;
          ++v7;
        }
        v5 += 2;
      }
      while ( *(v5 - 1) != 0 );
    }
    lc_codepage = ploci->lc_codepage;
    v22 = newctype1 + 128;
    if ( __crtGetStringTypeA(
           plocinfo: nullptr,
           dwInfoType: 1u,
           lpSrcStr: (const char *)cbuffer,
           cchSrc: 256,
           lpCharType: newctype1 + 128,
           code_page: lc_codepage,
           lcid: 0,
           bError: 0) != 0
      && __crtLCMapStringA(
           plocinfo: nullptr,
           Locale: ploci->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: (const char *)cbuffer + 1,
           cchSrc: 255,
           lpDestStr: (char *)newclmap + 129,
           cchDest: 255,
           code_page: ploci->lc_codepage,
           bError: 0) != 0
      && __crtLCMapStringA(
           plocinfo: nullptr,
           Locale: ploci->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: (const char *)cbuffer + 1,
           cchSrc: 255,
           lpDestStr: (char *)newcumap + 129,
           cchDest: 255,
           code_page: ploci->lc_codepage,
           bError: 0) != 0 )
    {
      v8 = mb_cur_max <= 1;
      v9 = (unsigned __int8 *)newctype1;
      v10 = newclmap;
      v11 = newcumap;
      v12 = newctype1 + 127;
      newctype1[127] = 0;
      v23 = v12;
      v10[127] = 0;
      v11[127] = 0;
      v10[128] = 0;
      v21 = v10 + 128;
      v24 = v11 + 128;
      v11[128] = 0;
      if ( !v8 && lpCPInfo.LeadByte[0] != 0 )
      {
        v13 = &lpCPInfo.LeadByte[1];
        newclmap = &lpCPInfo.LeadByte[1];
        do
        {
          v14 = *v13;
          if ( *v13 == 0 )
            break;
          v15 = *(v13 - 1);
          if ( v15 <= (unsigned int)v14 )
          {
            for ( j = (unsigned __int16 *)&v9[2 * v15 + 256]; ; j = newctype1 )
            {
              *j = 0x8000;
              ++v15;
              newctype1 = j + 1;
              if ( v15 > *newclmap )
                break;
            }
          }
          v13 = newclmap + 2;
          v2 = newclmap[1] == 0;
          newclmap += 2;
        }
        while ( !v2 );
      }
      memcpy(dst: v9, src: v9 + 512, count: 0xFEu);
      memcpy(dst: v10, src: v10 + 256, count: 0x7Fu);
      memcpy(dst: newcumap, src: newcumap + 256, count: 0x7Fu);
      if ( ploci->ctype1_refcount != nullptr && InterlockedDecrement(lpAddend: ploci->ctype1_refcount) == 0 )
      {
        free(pMem: ploci->ctype1 - 127);
        free(pMem: (void *)(ploci->pclmap - 128));
        free(pMem: (void *)(ploci->pcumap - 128));
        free(pMem: ploci->ctype1_refcount);
      }
      v17 = refcount;
      *refcount = 1;
      ploci->ctype1_refcount = v17;
      ploci->pctype = v22;
      ploci->ctype1 = v23;
      ploci->pclmap = v21;
      ploci->pcumap = v24;
      ploci->mb_cur_max = mb_cur_max;
    }
    else
    {
error_cleanup_1:
      free(pMem: refcount);
      free(pMem: newctype1);
      free(pMem: newclmap);
      free(pMem: newcumap);
      v1 = 1;
    }
    free(pMem: cbuffer);
    return v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DEB4D
// Name: _strcat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strcat_s@<eax>(unsigned int a1@<edi>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src != nullptr )
  {
    v7 = _Dst;
    do
    {
      if ( *v7 == 0 )
        break;
      ++v7;
      --a1;
    }
    while ( a1 != 0 );
    if ( a1 != 0 )
    {
      do
      {
        v8 = *v6;
        *v7++ = *v6++;
        if ( v8 == 0 )
          break;
        --a1;
      }
      while ( a1 != 0 );
      if ( a1 == 0 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return 0;
    }
  }
  *_Dst = 0;
LABEL_3:
  v4 = 22;
  *_errno() = 22;
LABEL_4:
  _invalid_parameter(a1: 0, a2: a1, a3: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004DEBC0
// Name: _strcspn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcspn(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  int v5; // ecx
  signed __int32 v6[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v6, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v6, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v6, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x004DEC06
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strncpy_s@<eax>(
        unsigned int a1@<edi>,
        char *_Dst,
        unsigned int _SizeInBytes,
        const char *_Src,
        unsigned int _Count)
{
  unsigned int v6; // esi
  const char *v7; // edx
  char *v8; // eax
  char v9; // cl
  char v10; // cl

  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter(a1: 0, a2: a1, a3: v6);
      return v6;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v8 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v9 = *v7;
      *v8++ = *v7++;
      if ( v9 == 0 )
        break;
      --a1;
    }
    while ( a1 != 0 );
  }
  else
  {
    do
    {
      v10 = *v7;
      *v8++ = *v7++;
      if ( v10 == 0 )
        break;
      if ( --a1 == 0 )
        break;
      --_Count;
    }
    while ( _Count != 0 );
    if ( _Count == 0 )
      *v8 = 0;
  }
  if ( a1 != 0 )
    return 0;
  if ( _Count != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInBytes - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x004DECB9
// Name: TranslateName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl TranslateName(const tagLOCALETAB *lpTable, int high, const char **ppchName)
{
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  const tagLOCALETAB *v6; // edi

  v3 = 0;
  v4 = 1;
  while ( v3 <= high )
  {
    if ( v4 == 0 )
      break;
    v5 = (v3 + high) / 2;
    v6 = &lpTable[v5];
    v4 = _stricmp(dst: *ppchName, src: v6->szName);
    if ( v4 != 0 )
    {
      if ( v4 >= 0 )
        v3 = v5 + 1;
      else
        high = v5 - 1;
    }
    else
    {
      *ppchName = v6->chAbbrev;
    }
  }
  return v4 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DED19
// Name: ProcessCodePage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ProcessCodePage@<eax>(char *lpCodePageStr@<ecx>, setloc_struct *_psetloc_data@<edi>)
{
  char *v2; // esi
  int v3; // eax
  int v4; // eax
  int result; // eax
  char chCodePage[8]; // [esp+4h] [ebp-Ch] BYREF

  v2 = lpCodePageStr;
  if ( lpCodePageStr != nullptr
    && *lpCodePageStr != 0
    && (strcmp(str1: (unsigned __int8 *)lpCodePageStr, str2: "ACP"), v3 != 0) )
  {
    strcmp(str1: (unsigned __int8 *)v2, str2: "OCP");
    if ( v4 != 0 )
      return atol(nptr: v2);
    result = GetLocaleInfoA(Locale: _psetloc_data->lcidCountry, LCType: 0xBu, lpLCData: chCodePage, cchData: 8);
  }
  else
  {
    result = GetLocaleInfoA(Locale: _psetloc_data->lcidCountry, LCType: 0x1004u, lpLCData: chCodePage, cchData: 8);
  }
  if ( result == 0 )
    return result;
  v2 = chCodePage;
  return atol(nptr: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004DED90
// Name: TestDefaultCountry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl TestDefaultCountry(__int16 lcid)
{
  int v1; // eax

  v1 = 0;
  while ( lcid != __rglangidNotDefault[v1] )
  {
    if ( (unsigned int)++v1 >= 10 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DEDAE
// Name: LcidFromHexString
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall LcidFromHexString(int a1, char *lpHexString)
{
  int i; // esi
  char v3; // cl

  for ( i = 0; ; i = 16 * i + v3 - 48 )
  {
    v3 = *lpHexString;
    if ( *lpHexString == 0 )
      break;
    ++lpHexString;
    if ( (unsigned __int8)(v3 - 97) > 5u )
    {
      if ( (unsigned __int8)(v3 - 65) <= 5u )
        v3 -= 7;
    }
    else
    {
      v3 -= 39;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x004DEDE0
// Name: GetPrimaryLen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall GetPrimaryLen(int a1, char *pchLanguage)
{
  int result; // eax
  char v3; // cl

  for ( result = 0; ; ++result )
  {
    v3 = *pchLanguage++;
    if ( (v3 < 65 || v3 > 90) && (unsigned __int8)(v3 - 97) > 0x19u )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DEDFB
// Name: CountryEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CountryEnumProc(char *lpLcidString)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  int v3; // edi
  char rgcInfo[120]; // [esp+8h] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = LcidFromHexString(a1: v2, lpHexString: lpLcidString);
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: p_setloc_data->bAbbrevCountry != 0 ? 7 : 4098,
         lpLCData: rgcInfo,
         cchData: 120) != 0 )
  {
    if ( _stricmp(dst: p_setloc_data->pchCountry, src: rgcInfo) == 0 && TestDefaultCountry(lcid: v3) != 0 )
    {
      p_setloc_data->iLcidState |= 4u;
      p_setloc_data->lcidCountry = v3;
      p_setloc_data->lcidLanguage = v3;
    }
    return (p_setloc_data->iLcidState & 4) == 0;
  }
  else
  {
    p_setloc_data->iLcidState = 0;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DEE91
// Name: TestDefaultLanguage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl TestDefaultLanguage(unsigned int lcid, int bTestPrimary)
{
  setloc_struct *_psetloc_data; // ecx
  setloc_struct *v3; // esi
  int v4; // ecx
  BOOL result; // eax
  int v6; // ecx
  char *pchLanguage; // esi
  int PrimaryLen; // edi
  int v9; // eax
  char rgcInfo[120]; // [esp+4h] [ebp-7Ch] BYREF

  v3 = _psetloc_data;
  result = false;
  if ( GetLocaleInfoA(Locale: lcid & 0x3FF | 0x400, LCType: 1u, lpLCData: rgcInfo, cchData: 120) != 0 )
  {
    if ( lcid == LcidFromHexString(a1: v4, lpHexString: rgcInfo) )
      return true;
    if ( bTestPrimary == 0 )
      return true;
    pchLanguage = v3->pchLanguage;
    PrimaryLen = GetPrimaryLen(a1: v6, pchLanguage);
    strlen(buf: pchLanguage);
    if ( PrimaryLen != v9 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DEF03
// Name: LangCountryEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall LangCountryEnumProc(char *lpLcidString)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  int v3; // edi
  int v5; // eax
  int v6; // edx
  int v7; // eax
  BOOL v8; // eax
  char *pchLanguage; // [esp-4h] [ebp-8Ch]
  char rgcInfo[120]; // [esp+Ch] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = LcidFromHexString(a1: v2, lpHexString: lpLcidString);
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: p_setloc_data->bAbbrevCountry != 0 ? 7 : 4098,
         lpLCData: rgcInfo,
         cchData: 120) == 0 )
    goto LABEL_2;
  if ( _stricmp(dst: p_setloc_data->pchCountry, src: rgcInfo) == 0 )
  {
    if ( GetLocaleInfoA(
           Locale: v3,
           LCType: p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097,
           lpLCData: rgcInfo,
           cchData: 120) == 0 )
      goto LABEL_2;
    if ( _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) == 0 )
    {
      p_setloc_data->iLcidState |= 0x304u;
      p_setloc_data->lcidLanguage = v3;
LABEL_15:
      p_setloc_data->lcidCountry = v3;
      goto LABEL_16;
    }
    if ( (p_setloc_data->iLcidState & 2) != 0 )
      goto LABEL_16;
    if ( p_setloc_data->iPrimaryLen != 0
      && _strnicmp(dst: p_setloc_data->pchLanguage, src: rgcInfo, count: p_setloc_data->iPrimaryLen) == 0 )
    {
      pchLanguage = p_setloc_data->pchLanguage;
      p_setloc_data->iLcidState |= 2u;
      p_setloc_data->lcidCountry = v3;
      strlen(buf: pchLanguage);
      if ( v5 == p_setloc_data->iPrimaryLen )
        p_setloc_data->lcidLanguage = v3;
    }
    else if ( (p_setloc_data->iLcidState & 1) == 0 && TestDefaultCountry(lcid: v3) != 0 )
    {
      p_setloc_data->iLcidState = v6 | 1;
      goto LABEL_15;
    }
  }
LABEL_16:
  if ( (p_setloc_data->iLcidState & 0x300) == 0x300 )
    return (p_setloc_data->iLcidState & 4) == 0;
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097,
         lpLCData: rgcInfo,
         cchData: 120) == 0 )
  {
LABEL_2:
    p_setloc_data->iLcidState = 0;
    return 1;
  }
  if ( _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) == 0 )
  {
    p_setloc_data->iLcidState |= 0x200u;
    if ( p_setloc_data->bAbbrevLanguage != 0 )
    {
      p_setloc_data->iLcidState |= 0x100u;
      goto LABEL_30;
    }
    if ( p_setloc_data->iPrimaryLen == 0 || (strlen(buf: p_setloc_data->pchLanguage), v7 != p_setloc_data->iPrimaryLen) )
    {
LABEL_29:
      p_setloc_data->iLcidState |= 0x100u;
LABEL_30:
      if ( p_setloc_data->lcidLanguage == 0 )
        p_setloc_data->lcidLanguage = v3;
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v8 = TestDefaultLanguage(lcid: v3, bTestPrimary: 1);
  }
  else
  {
    if ( p_setloc_data->bAbbrevLanguage != 0
      || p_setloc_data->iPrimaryLen == 0
      || _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) != 0 )
    {
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v8 = TestDefaultLanguage(lcid: v3, bTestPrimary: 0);
  }
  if ( v8 )
    goto LABEL_29;
  return (p_setloc_data->iLcidState & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DF0D3
// Name: LanguageEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall LanguageEnumProc(char *lpLcidString)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  LCID v3; // edi
  BOOL v5; // eax
  char rgcInfo[120]; // [esp+8h] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = LcidFromHexString(a1: v2, lpHexString: lpLcidString);
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097,
         lpLCData: rgcInfo,
         cchData: 120) == 0 )
  {
    p_setloc_data->iLcidState = 0;
    return 1;
  }
  if ( _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) == 0 )
  {
    if ( p_setloc_data->bAbbrevLanguage != 0 )
    {
LABEL_11:
      p_setloc_data->iLcidState |= 4u;
      p_setloc_data->lcidLanguage = v3;
      p_setloc_data->lcidCountry = v3;
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v5 = TestDefaultLanguage(lcid: v3, bTestPrimary: 1);
  }
  else
  {
    if ( p_setloc_data->bAbbrevLanguage != 0
      || p_setloc_data->iPrimaryLen == 0
      || _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) != 0 )
    {
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v5 = TestDefaultLanguage(lcid: v3, bTestPrimary: 0);
  }
  if ( v5 )
    goto LABEL_11;
  return (p_setloc_data->iLcidState & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DF192
// Name: GetLcidFromLangCountry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall GetLcidFromLangCountry(setloc_struct *_psetloc_data@<esi>)
{
  int v1; // eax
  int v2; // eax
  bool v3; // zf
  int PrimaryLen; // eax
  int iLcidState; // eax
  char *pchCountry; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  strlen(buf: _psetloc_data->pchLanguage);
  pchCountry = _psetloc_data->pchCountry;
  _psetloc_data->bAbbrevLanguage = v1 == 3;
  strlen(buf: pchCountry);
  _psetloc_data->lcidLanguage = 0;
  v3 = _psetloc_data->bAbbrevLanguage == 0;
  _psetloc_data->bAbbrevCountry = v2 == 3;
  if ( v3 )
    PrimaryLen = GetPrimaryLen(a1: v7, pchLanguage: _psetloc_data->pchLanguage);
  else
    PrimaryLen = 2;
  _psetloc_data->iPrimaryLen = PrimaryLen;
  EnumSystemLocalesA(lpLocaleEnumProc: LangCountryEnumProc, dwFlags: 1u);
  iLcidState = _psetloc_data->iLcidState;
  if ( (iLcidState & 0x100) == 0 || (iLcidState & 0x200) == 0 || (iLcidState & 7) == 0 )
    _psetloc_data->iLcidState = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DF1F7
// Name: GetLcidFromLanguage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall GetLcidFromLanguage(setloc_struct *_psetloc_data@<esi>)
{
  int v1; // eax
  BOOL v2; // eax
  int PrimaryLen; // eax
  int v4; // [esp-4h] [ebp-4h]

  strlen(buf: _psetloc_data->pchLanguage);
  v2 = v1 == 3;
  _psetloc_data->bAbbrevLanguage = v2;
  if ( v2 )
    PrimaryLen = 2;
  else
    PrimaryLen = GetPrimaryLen(a1: v4, pchLanguage: _psetloc_data->pchLanguage);
  _psetloc_data->iPrimaryLen = PrimaryLen;
  EnumSystemLocalesA(lpLocaleEnumProc: LanguageEnumProc, dwFlags: 1u);
  if ( (_psetloc_data->iLcidState & 4) == 0 )
    _psetloc_data->iLcidState = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DF233
// Name: ___get_qualified_locale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __get_qualified_locale(tagLC_STRINGS *const lpInStr, tagLC_ID *lpOutId, tagLC_STRINGS *lpOutStr)
{
  _tiddata *v3; // eax
  unsigned int p_setloc_data; // esi
  char **p_pchCountry; // edi
  _BYTE *v6; // eax
  bool v7; // zf
  char *v8; // edi
  char *v9; // edi
  int v10; // eax
  LCID UserDefaultLCID; // eax
  int v12; // eax
  unsigned int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // ecx

  v3 = _getptd();
  p_setloc_data = (unsigned int)&v3->_setloc_data;
  if ( lpInStr == nullptr )
  {
    v3->_setloc_data.iLcidState |= 0x104u;
LABEL_23:
    UserDefaultLCID = GetUserDefaultLCID();
    *(_DWORD *)(p_setloc_data + 24) = UserDefaultLCID;
    *(_DWORD *)(p_setloc_data + 28) = UserDefaultLCID;
    goto LABEL_24;
  }
  p_pchCountry = &v3->_setloc_data.pchCountry;
  *(_DWORD *)p_setloc_data = lpInStr;
  v3->_setloc_data.pchCountry = lpInStr->szCountry;
  if ( lpInStr != (tagLC_STRINGS *const)-64 && lpInStr->szCountry[0] != 0 )
    TranslateName(lpTable: __rg_country, high: 22, ppchName: (const char **)&v3->_setloc_data.pchCountry);
  v6 = *(_BYTE **)p_setloc_data;
  v7 = *(_DWORD *)p_setloc_data == 0;
  *(_DWORD *)(p_setloc_data + 8) = 0;
  if ( v7 || *v6 == 0 )
  {
    v9 = *p_pchCountry;
    if ( v9 == nullptr || *v9 == 0 )
    {
      *(_DWORD *)(p_setloc_data + 8) = 260;
      goto LABEL_23;
    }
    strlen(buf: v9);
    *(_DWORD *)(p_setloc_data + 20) = v10 == 3;
    EnumSystemLocalesA(lpLocaleEnumProc: CountryEnumProc, dwFlags: 1u);
    if ( (*(_BYTE *)(p_setloc_data + 8) & 4) == 0 )
      *(_DWORD *)(p_setloc_data + 8) = 0;
LABEL_24:
    if ( *(_DWORD *)(p_setloc_data + 8) == 0 )
      return 0;
    goto LABEL_25;
  }
  if ( *p_pchCountry != nullptr && **p_pchCountry != 0 )
    GetLcidFromLangCountry(_psetloc_data: (setloc_struct *)p_setloc_data);
  else
    GetLcidFromLanguage(_psetloc_data: (setloc_struct *)p_setloc_data);
  if ( *(_DWORD *)(p_setloc_data + 8) == 0 )
  {
    if ( TranslateName(lpTable: __rg_language, high: 64, ppchName: (const char **)p_setloc_data) )
    {
      v8 = *p_pchCountry;
      if ( v8 != nullptr && *v8 != 0 )
        GetLcidFromLangCountry(_psetloc_data: (setloc_struct *)p_setloc_data);
      else
        GetLcidFromLanguage(_psetloc_data: (setloc_struct *)p_setloc_data);
    }
    goto LABEL_24;
  }
LABEL_25:
  v12 = ProcessCodePage(
          lpCodePageStr: lpInStr != nullptr ? lpInStr->szCodePage : nullptr,
          _psetloc_data: (setloc_struct *)p_setloc_data);
  v13 = v12;
  if ( v12 == 0
    || v12 == 65000
    || v12 == 65001
    || !IsValidCodePage(CodePage: (unsigned __int16)v12)
    || !IsValidLocale(Locale: *(_DWORD *)(p_setloc_data + 24), dwFlags: 1u) )
  {
    return 0;
  }
  if ( lpOutId != nullptr )
  {
    lpOutId->wLanguage = *(_WORD *)(p_setloc_data + 24);
    lpOutId->wCountry = *(_WORD *)(p_setloc_data + 28);
    lpOutId->wCodePage = v13;
  }
  if ( lpOutStr == nullptr )
    return 1;
  if ( lpOutId->wLanguage == 2068 )
  {
    if ( strcpy_s(
           a1: (unsigned int)lpOutStr,
           _Dst: lpOutStr->szLanguage,
           _SizeInBytes: 0x40u,
           _Src: "Norwegian-Nynorsk") != 0 )
      _invoke_watson(a1: 0, a2: v14, a3: v15, a4: v13, a5: (unsigned int)lpOutStr, a6: p_setloc_data);
  }
  else if ( GetLocaleInfoA(
              Locale: *(_DWORD *)(p_setloc_data + 24),
              LCType: 0x1001u,
              lpLCData: lpOutStr->szLanguage,
              cchData: 64) == 0 )
  {
    return 0;
  }
  if ( GetLocaleInfoA(
         Locale: *(_DWORD *)(p_setloc_data + 28),
         LCType: 0x1002u,
         lpLCData: lpOutStr->szCountry,
         cchData: 64) != 0 )
  {
    _itoa_s(val: v13, buf: lpOutStr->szCodePage, sizeInTChars: 0x10u, radix: 10);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DF416
// Name: _memcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl memcmp(unsigned __int8 *lhs, unsigned __int8 *rhs, unsigned int siz)
{
  unsigned int v3; // edi
  unsigned __int8 *v4; // ecx
  unsigned __int8 *v5; // eax
  int v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // kr00_4
  unsigned __int8 *v9; // kr04_4
  unsigned __int8 *v10; // ecx
  int result; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // edx
  int v18; // esi
  int v19; // edx
  int v20; // edx
  int v21; // edx
  int v22; // edx
  int v23; // edx
  int v24; // edx
  int v25; // edx
  int v26; // edx
  int v27; // edx
  int v28; // edx
  int v29; // edx
  int v30; // edx
  int v31; // edx
  int v32; // edx
  int v33; // edx
  int v34; // edx
  int v35; // edx
  int v36; // edx
  int v37; // edx
  int v38; // eax
  int v39; // ecx

  v3 = siz;
  switch ( siz )
  {
    case 0u:
      return 0;
    case 1u:
      v38 = *lhs;
      v39 = *rhs;
LABEL_425:
      result = v38 - v39;
      if ( result != 0 )
        return 2 * (result > 0) - 1;
      return result;
    case 2u:
      if ( *lhs != *rhs )
      {
        result = 2 * (*lhs > (unsigned int)*rhs) - 1;
        if ( 2 * (*lhs > (unsigned int)*rhs) != 1 )
          return result;
      }
      v38 = lhs[1];
      v39 = rhs[1];
      goto LABEL_425;
    case 3u:
      if ( *lhs != *rhs )
      {
        result = 2 * (*lhs > (unsigned int)*rhs) - 1;
        if ( 2 * (*lhs > (unsigned int)*rhs) != 1 )
          return result;
      }
      if ( lhs[1] != rhs[1] )
      {
        result = 2 * (lhs[1] > (unsigned int)rhs[1]) - 1;
        if ( 2 * (lhs[1] > (unsigned int)rhs[1]) != 1 )
          return result;
      }
      v38 = lhs[2];
      v39 = rhs[2];
      goto LABEL_425;
    case 4u:
      if ( *lhs != *rhs )
      {
        result = 2 * (*lhs > (unsigned int)*rhs) - 1;
        if ( 2 * (*lhs > (unsigned int)*rhs) != 1 )
          return result;
      }
      if ( lhs[1] != rhs[1] )
      {
        result = 2 * (lhs[1] > (unsigned int)rhs[1]) - 1;
        if ( 2 * (lhs[1] > (unsigned int)rhs[1]) != 1 )
          return result;
      }
      if ( lhs[2] != rhs[2] )
      {
        result = 2 * (lhs[2] > (unsigned int)rhs[2]) - 1;
        if ( 2 * (lhs[2] > (unsigned int)rhs[2]) != 1 )
          return result;
      }
      v38 = lhs[3];
      v39 = rhs[3];
      goto LABEL_425;
    default:
      break;
  }
  v4 = rhs;
  v5 = lhs;
  while ( 2 )
  {
    v8 = v5;
    v9 = v4;
    v7 = &v5[v3];
    v10 = &v4[v3];
    switch ( v3 )
    {
      case 0u:
        return 0;
      case 1u:
        goto $LN103;
      case 2u:
        goto $LN88_1;
      case 3u:
        goto $LN73_0;
      case 4u:
        goto $LN120;
      case 5u:
        goto $LN105;
      case 6u:
        goto $LN90;
      case 7u:
        goto $LN75_2;
      case 8u:
        goto $LN122_0;
      case 9u:
        goto $LN107;
      case 0xAu:
        goto $LN92;
      case 0xBu:
        goto $LN77;
      case 0xCu:
        goto $LN124;
      case 0xDu:
        goto $LN109;
      case 0xEu:
        goto $LN94;
      case 0xFu:
        goto $LN79;
      case 0x10u:
        goto $LN126;
      case 0x11u:
        goto $LN111;
      case 0x12u:
        goto $LN96_0;
      case 0x13u:
        goto $LN81;
      case 0x14u:
        goto $LN128;
      case 0x15u:
        goto $LN113_0;
      case 0x16u:
        goto $LN98;
      case 0x17u:
        goto $LN83_0;
      case 0x18u:
        goto $LN130_1;
      case 0x19u:
        goto $LN115;
      case 0x1Au:
        goto $LN100;
      case 0x1Bu:
        goto $LN85;
      case 0x1Cu:
        v12 = *((_DWORD *)v7 - 7);
        if ( v12 == *((_DWORD *)v10 - 7) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v12 != *(v10 - 28) )
          {
            v6 = 2 * ((unsigned __int8)v12 > (unsigned int)*(v10 - 28)) - 1;
            if ( 2 * ((unsigned __int8)v12 > (unsigned int)*(v10 - 28)) != 1 )
              return v6;
          }
          if ( *(v7 - 27) != *(v10 - 27) )
          {
            v6 = 2 * (*(v7 - 27) > (unsigned int)*(v10 - 27)) - 1;
            if ( 2 * (*(v7 - 27) > (unsigned int)*(v10 - 27)) != 1 )
              return v6;
          }
          if ( *(v7 - 26) != *(v10 - 26) )
          {
            v6 = 2 * (*(v7 - 26) > (unsigned int)*(v10 - 26)) - 1;
            if ( 2 * (*(v7 - 26) > (unsigned int)*(v10 - 26)) != 1 )
              return v6;
          }
          v6 = *(v7 - 25) - *(v10 - 25);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 25) > (unsigned int)*(v10 - 25)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN130_1:
        v13 = *((_DWORD *)v7 - 6);
        if ( v13 == *((_DWORD *)v10 - 6) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v13 != *(v10 - 24) )
          {
            v6 = 2 * ((unsigned __int8)v13 > (unsigned int)*(v10 - 24)) - 1;
            if ( 2 * ((unsigned __int8)v13 > (unsigned int)*(v10 - 24)) != 1 )
              return v6;
          }
          if ( *(v7 - 23) != *(v10 - 23) )
          {
            v6 = 2 * (*(v7 - 23) > (unsigned int)*(v10 - 23)) - 1;
            if ( 2 * (*(v7 - 23) > (unsigned int)*(v10 - 23)) != 1 )
              return v6;
          }
          if ( *(v7 - 22) != *(v10 - 22) )
          {
            v6 = 2 * (*(v7 - 22) > (unsigned int)*(v10 - 22)) - 1;
            if ( 2 * (*(v7 - 22) > (unsigned int)*(v10 - 22)) != 1 )
              return v6;
          }
          v6 = *(v7 - 21) - *(v10 - 21);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 21) > (unsigned int)*(v10 - 21)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN128:
        v14 = *((_DWORD *)v7 - 5);
        if ( v14 == *((_DWORD *)v10 - 5) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v14 != *(v10 - 20) )
          {
            v6 = 2 * ((unsigned __int8)v14 > (unsigned int)*(v10 - 20)) - 1;
            if ( 2 * ((unsigned __int8)v14 > (unsigned int)*(v10 - 20)) != 1 )
              return v6;
          }
          if ( *(v7 - 19) != *(v10 - 19) )
          {
            v6 = 2 * (*(v7 - 19) > (unsigned int)*(v10 - 19)) - 1;
            if ( 2 * (*(v7 - 19) > (unsigned int)*(v10 - 19)) != 1 )
              return v6;
          }
          if ( *(v7 - 18) != *(v10 - 18) )
          {
            v6 = 2 * (*(v7 - 18) > (unsigned int)*(v10 - 18)) - 1;
            if ( 2 * (*(v7 - 18) > (unsigned int)*(v10 - 18)) != 1 )
              return v6;
          }
          v6 = *(v7 - 17) - *(v10 - 17);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 17) > (unsigned int)*(v10 - 17)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN126:
        v15 = *((_DWORD *)v7 - 4);
        if ( v15 == *((_DWORD *)v10 - 4) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v15 != *(v10 - 16) )
          {
            v6 = 2 * ((unsigned __int8)v15 > (unsigned int)*(v10 - 16)) - 1;
            if ( 2 * ((unsigned __int8)v15 > (unsigned int)*(v10 - 16)) != 1 )
              return v6;
          }
          if ( *(v7 - 15) != *(v10 - 15) )
          {
            v6 = 2 * (*(v7 - 15) > (unsigned int)*(v10 - 15)) - 1;
            if ( 2 * (*(v7 - 15) > (unsigned int)*(v10 - 15)) != 1 )
              return v6;
          }
          if ( *(v7 - 14) != *(v10 - 14) )
          {
            v6 = 2 * (*(v7 - 14) > (unsigned int)*(v10 - 14)) - 1;
            if ( 2 * (*(v7 - 14) > (unsigned int)*(v10 - 14)) != 1 )
              return v6;
          }
          v6 = *(v7 - 13) - *(v10 - 13);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 13) > (unsigned int)*(v10 - 13)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN124:
        if ( *((_DWORD *)v7 - 3) == *((_DWORD *)v10 - 3) )
        {
          v6 = 0;
        }
        else
        {
          if ( *(v7 - 12) != *(v10 - 12) )
          {
            v6 = 2 * (*(v7 - 12) > (unsigned int)*(v10 - 12)) - 1;
            if ( 2 * (*(v7 - 12) > (unsigned int)*(v10 - 12)) != 1 )
              return v6;
          }
          if ( *(v7 - 11) != *(v10 - 11) )
          {
            v6 = 2 * (*(v7 - 11) > (unsigned int)*(v10 - 11)) - 1;
            if ( 2 * (*(v7 - 11) > (unsigned int)*(v10 - 11)) != 1 )
              return v6;
          }
          if ( *(v7 - 10) != *(v10 - 10) )
          {
            v6 = 2 * (*(v7 - 10) > (unsigned int)*(v10 - 10)) - 1;
            if ( 2 * (*(v7 - 10) > (unsigned int)*(v10 - 10)) != 1 )
              return v6;
          }
          v6 = *(v7 - 9) - *(v10 - 9);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 9) > (unsigned int)*(v10 - 9)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN122_0:
        v16 = *((_DWORD *)v7 - 2);
        if ( v16 == *((_DWORD *)v10 - 2) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v16 != *(v10 - 8) )
          {
            v6 = 2 * ((unsigned __int8)v16 > (unsigned int)*(v10 - 8)) - 1;
            if ( 2 * ((unsigned __int8)v16 > (unsigned int)*(v10 - 8)) != 1 )
              return v6;
          }
          if ( *(v7 - 7) != *(v10 - 7) )
          {
            v6 = 2 * (*(v7 - 7) > (unsigned int)*(v10 - 7)) - 1;
            if ( 2 * (*(v7 - 7) > (unsigned int)*(v10 - 7)) != 1 )
              return v6;
          }
          if ( *(v7 - 6) != *(v10 - 6) )
          {
            v6 = 2 * (*(v7 - 6) > (unsigned int)*(v10 - 6)) - 1;
            if ( 2 * (*(v7 - 6) > (unsigned int)*(v10 - 6)) != 1 )
              return v6;
          }
          v6 = *(v7 - 5) - *(v10 - 5);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 5) > (unsigned int)*(v10 - 5)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN120:
        v17 = *((_DWORD *)v7 - 1);
        if ( v17 == *((_DWORD *)v10 - 1) )
        {
          result = 0;
        }
        else
        {
          v18 = (unsigned __int8)v17 - *(v10 - 4);
          if ( (v18 == 0 || (v19 = 2 * ((unsigned __int8)v17 > (unsigned int)*(v10 - 4)) - 1, 2 * (v18 > 0) == 1))
            && (*(v7 - 3) == *(v10 - 3)
             || (v19 = 2 * (*(v7 - 3) > (unsigned int)*(v10 - 3)) - 1, 2 * (*(v7 - 3) > (unsigned int)*(v10 - 3)) == 1))
            && (*(v7 - 2) == *(v10 - 2)
             || (v19 = 2 * (*(v7 - 2) > (unsigned int)*(v10 - 2)) - 1, 2 * (*(v7 - 2) > (unsigned int)*(v10 - 2)) == 1)) )
          {
            result = *(v7 - 1) - *(v10 - 1);
            if ( result != 0 )
              result = 2 * (result > 0) - 1;
          }
          else
          {
            result = v19;
          }
        }
        if ( result == 0 )
          return 0;
        return result;
      case 0x1Du:
        v20 = *(_DWORD *)(v7 - 29);
        if ( v20 == *(_DWORD *)(v10 - 29) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v20 != *(v10 - 29) )
          {
            v6 = 2 * ((unsigned __int8)v20 > (unsigned int)*(v10 - 29)) - 1;
            if ( 2 * ((unsigned __int8)v20 > (unsigned int)*(v10 - 29)) != 1 )
              return v6;
          }
          if ( *(v7 - 28) != *(v10 - 28) )
          {
            v6 = 2 * (*(v7 - 28) > (unsigned int)*(v10 - 28)) - 1;
            if ( 2 * (*(v7 - 28) > (unsigned int)*(v10 - 28)) != 1 )
              return v6;
          }
          if ( *(v7 - 27) != *(v10 - 27) )
          {
            v6 = 2 * (*(v7 - 27) > (unsigned int)*(v10 - 27)) - 1;
            if ( 2 * (*(v7 - 27) > (unsigned int)*(v10 - 27)) != 1 )
              return v6;
          }
          v6 = *(v7 - 26) - *(v10 - 26);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 26) > (unsigned int)*(v10 - 26)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN115:
        v21 = *(_DWORD *)(v7 - 25);
        if ( v21 == *(_DWORD *)(v10 - 25) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v21 != *(v10 - 25) )
          {
            v6 = 2 * ((unsigned __int8)v21 > (unsigned int)*(v10 - 25)) - 1;
            if ( 2 * ((unsigned __int8)v21 > (unsigned int)*(v10 - 25)) != 1 )
              return v6;
          }
          if ( *(v7 - 24) != *(v10 - 24) )
          {
            v6 = 2 * (*(v7 - 24) > (unsigned int)*(v10 - 24)) - 1;
            if ( 2 * (*(v7 - 24) > (unsigned int)*(v10 - 24)) != 1 )
              return v6;
          }
          if ( *(v7 - 23) != *(v10 - 23) )
          {
            v6 = 2 * (*(v7 - 23) > (unsigned int)*(v10 - 23)) - 1;
            if ( 2 * (*(v7 - 23) > (unsigned int)*(v10 - 23)) != 1 )
              return v6;
          }
          v6 = *(v7 - 22) - *(v10 - 22);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 22) > (unsigned int)*(v10 - 22)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN113_0:
        v22 = *(_DWORD *)(v7 - 21);
        if ( v22 == *(_DWORD *)(v10 - 21) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v22 != *(v10 - 21) )
          {
            v6 = 2 * ((unsigned __int8)v22 > (unsigned int)*(v10 - 21)) - 1;
            if ( 2 * ((unsigned __int8)v22 > (unsigned int)*(v10 - 21)) != 1 )
              return v6;
          }
          if ( *(v7 - 20) != *(v10 - 20) )
          {
            v6 = 2 * (*(v7 - 20) > (unsigned int)*(v10 - 20)) - 1;
            if ( 2 * (*(v7 - 20) > (unsigned int)*(v10 - 20)) != 1 )
              return v6;
          }
          if ( *(v7 - 19) != *(v10 - 19) )
          {
            v6 = 2 * (*(v7 - 19) > (unsigned int)*(v10 - 19)) - 1;
            if ( 2 * (*(v7 - 19) > (unsigned int)*(v10 - 19)) != 1 )
              return v6;
          }
          v6 = *(v7 - 18) - *(v10 - 18);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 18) > (unsigned int)*(v10 - 18)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN111:
        v23 = *(_DWORD *)(v7 - 17);
        if ( v23 == *(_DWORD *)(v10 - 17) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v23 != *(v10 - 17) )
          {
            v6 = 2 * ((unsigned __int8)v23 > (unsigned int)*(v10 - 17)) - 1;
            if ( 2 * ((unsigned __int8)v23 > (unsigned int)*(v10 - 17)) != 1 )
              return v6;
          }
          if ( *(v7 - 16) != *(v10 - 16) )
          {
            v6 = 2 * (*(v7 - 16) > (unsigned int)*(v10 - 16)) - 1;
            if ( 2 * (*(v7 - 16) > (unsigned int)*(v10 - 16)) != 1 )
              return v6;
          }
          if ( *(v7 - 15) != *(v10 - 15) )
          {
            v6 = 2 * (*(v7 - 15) > (unsigned int)*(v10 - 15)) - 1;
            if ( 2 * (*(v7 - 15) > (unsigned int)*(v10 - 15)) != 1 )
              return v6;
          }
          v6 = *(v7 - 14) - *(v10 - 14);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 14) > (unsigned int)*(v10 - 14)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN109:
        v24 = *(_DWORD *)(v7 - 13);
        if ( v24 == *(_DWORD *)(v10 - 13) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v24 != *(v10 - 13) )
          {
            v6 = 2 * ((unsigned __int8)v24 > (unsigned int)*(v10 - 13)) - 1;
            if ( 2 * ((unsigned __int8)v24 > (unsigned int)*(v10 - 13)) != 1 )
              return v6;
          }
          if ( *(v7 - 12) != *(v10 - 12) )
          {
            v6 = 2 * (*(v7 - 12) > (unsigned int)*(v10 - 12)) - 1;
            if ( 2 * (*(v7 - 12) > (unsigned int)*(v10 - 12)) != 1 )
              return v6;
          }
          if ( *(v7 - 11) != *(v10 - 11) )
          {
            v6 = 2 * (*(v7 - 11) > (unsigned int)*(v10 - 11)) - 1;
            if ( 2 * (*(v7 - 11) > (unsigned int)*(v10 - 11)) != 1 )
              return v6;
          }
          v6 = *(v7 - 10) - *(v10 - 10);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 10) > (unsigned int)*(v10 - 10)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN107:
        if ( *(_DWORD *)(v7 - 9) == *(_DWORD *)(v10 - 9) )
        {
          v6 = 0;
        }
        else
        {
          if ( *(v7 - 9) != *(v10 - 9) )
          {
            v6 = 2 * (*(v7 - 9) > (unsigned int)*(v10 - 9)) - 1;
            if ( 2 * (*(v7 - 9) > (unsigned int)*(v10 - 9)) != 1 )
              return v6;
          }
          if ( *(v7 - 8) != *(v10 - 8) )
          {
            v6 = 2 * (*(v7 - 8) > (unsigned int)*(v10 - 8)) - 1;
            if ( 2 * (*(v7 - 8) > (unsigned int)*(v10 - 8)) != 1 )
              return v6;
          }
          if ( *(v7 - 7) != *(v10 - 7) )
          {
            v6 = 2 * (*(v7 - 7) > (unsigned int)*(v10 - 7)) - 1;
            if ( 2 * (*(v7 - 7) > (unsigned int)*(v10 - 7)) != 1 )
              return v6;
          }
          v6 = *(v7 - 6) - *(v10 - 6);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 6) > (unsigned int)*(v10 - 6)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN105:
        v25 = *(_DWORD *)(v7 - 5);
        if ( v25 == *(_DWORD *)(v10 - 5) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v25 != *(v10 - 5) )
          {
            v6 = 2 * ((unsigned __int8)v25 > (unsigned int)*(v10 - 5)) - 1;
            if ( 2 * ((unsigned __int8)v25 > (unsigned int)*(v10 - 5)) != 1 )
              return v6;
          }
          if ( *(v7 - 4) != *(v10 - 4) )
          {
            v6 = 2 * (*(v7 - 4) > (unsigned int)*(v10 - 4)) - 1;
            if ( 2 * (*(v7 - 4) > (unsigned int)*(v10 - 4)) != 1 )
              return v6;
          }
          if ( *(v7 - 3) != *(v10 - 3) )
          {
            v6 = 2 * (*(v7 - 3) > (unsigned int)*(v10 - 3)) - 1;
            if ( 2 * (*(v7 - 3) > (unsigned int)*(v10 - 3)) != 1 )
              return v6;
          }
          v6 = *(v7 - 2) - *(v10 - 2);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 2) > (unsigned int)*(v10 - 2)) - 1;
        }
        if ( v6 != 0 )
          return v6;
        goto $LN103;
      case 0x1Eu:
        v26 = *(_DWORD *)(v7 - 30);
        if ( v26 == *(_DWORD *)(v10 - 30) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v26 != *(v10 - 30) )
          {
            v6 = 2 * ((unsigned __int8)v26 > (unsigned int)*(v10 - 30)) - 1;
            if ( 2 * ((unsigned __int8)v26 > (unsigned int)*(v10 - 30)) != 1 )
              return v6;
          }
          if ( *(v7 - 29) != *(v10 - 29) )
          {
            v6 = 2 * (*(v7 - 29) > (unsigned int)*(v10 - 29)) - 1;
            if ( 2 * (*(v7 - 29) > (unsigned int)*(v10 - 29)) != 1 )
              return v6;
          }
          if ( *(v7 - 28) != *(v10 - 28) )
          {
            v6 = 2 * (*(v7 - 28) > (unsigned int)*(v10 - 28)) - 1;
            if ( 2 * (*(v7 - 28) > (unsigned int)*(v10 - 28)) != 1 )
              return v6;
          }
          v6 = *(v7 - 27) - *(v10 - 27);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 27) > (unsigned int)*(v10 - 27)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN100:
        v27 = *(_DWORD *)(v7 - 26);
        if ( v27 == *(_DWORD *)(v10 - 26) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v27 != *(v10 - 26) )
          {
            v6 = 2 * ((unsigned __int8)v27 > (unsigned int)*(v10 - 26)) - 1;
            if ( 2 * ((unsigned __int8)v27 > (unsigned int)*(v10 - 26)) != 1 )
              return v6;
          }
          if ( *(v7 - 25) != *(v10 - 25) )
          {
            v6 = 2 * (*(v7 - 25) > (unsigned int)*(v10 - 25)) - 1;
            if ( 2 * (*(v7 - 25) > (unsigned int)*(v10 - 25)) != 1 )
              return v6;
          }
          if ( *(v7 - 24) != *(v10 - 24) )
          {
            v6 = 2 * (*(v7 - 24) > (unsigned int)*(v10 - 24)) - 1;
            if ( 2 * (*(v7 - 24) > (unsigned int)*(v10 - 24)) != 1 )
              return v6;
          }
          v6 = *(v7 - 23) - *(v10 - 23);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 23) > (unsigned int)*(v10 - 23)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN98:
        v28 = *(_DWORD *)(v7 - 22);
        if ( v28 == *(_DWORD *)(v10 - 22) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v28 != *(v10 - 22) )
          {
            v6 = 2 * ((unsigned __int8)v28 > (unsigned int)*(v10 - 22)) - 1;
            if ( 2 * ((unsigned __int8)v28 > (unsigned int)*(v10 - 22)) != 1 )
              return v6;
          }
          if ( *(v7 - 21) != *(v10 - 21) )
          {
            v6 = 2 * (*(v7 - 21) > (unsigned int)*(v10 - 21)) - 1;
            if ( 2 * (*(v7 - 21) > (unsigned int)*(v10 - 21)) != 1 )
              return v6;
          }
          if ( *(v7 - 20) != *(v10 - 20) )
          {
            v6 = 2 * (*(v7 - 20) > (unsigned int)*(v10 - 20)) - 1;
            if ( 2 * (*(v7 - 20) > (unsigned int)*(v10 - 20)) != 1 )
              return v6;
          }
          v6 = *(v7 - 19) - *(v10 - 19);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 19) > (unsigned int)*(v10 - 19)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN96_0:
        v29 = *(_DWORD *)(v7 - 18);
        if ( v29 == *(_DWORD *)(v10 - 18) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v29 != *(v10 - 18) )
          {
            v6 = 2 * ((unsigned __int8)v29 > (unsigned int)*(v10 - 18)) - 1;
            if ( 2 * ((unsigned __int8)v29 > (unsigned int)*(v10 - 18)) != 1 )
              return v6;
          }
          if ( *(v7 - 17) != *(v10 - 17) )
          {
            v6 = 2 * (*(v7 - 17) > (unsigned int)*(v10 - 17)) - 1;
            if ( 2 * (*(v7 - 17) > (unsigned int)*(v10 - 17)) != 1 )
              return v6;
          }
          if ( *(v7 - 16) != *(v10 - 16) )
          {
            v6 = 2 * (*(v7 - 16) > (unsigned int)*(v10 - 16)) - 1;
            if ( 2 * (*(v7 - 16) > (unsigned int)*(v10 - 16)) != 1 )
              return v6;
          }
          v6 = *(v7 - 15) - *(v10 - 15);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 15) > (unsigned int)*(v10 - 15)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN94:
        v30 = *(_DWORD *)(v7 - 14);
        if ( v30 == *(_DWORD *)(v10 - 14) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v30 != *(v10 - 14) )
          {
            v6 = 2 * ((unsigned __int8)v30 > (unsigned int)*(v10 - 14)) - 1;
            if ( 2 * ((unsigned __int8)v30 > (unsigned int)*(v10 - 14)) != 1 )
              return v6;
          }
          if ( *(v7 - 13) != *(v10 - 13) )
          {
            v6 = 2 * (*(v7 - 13) > (unsigned int)*(v10 - 13)) - 1;
            if ( 2 * (*(v7 - 13) > (unsigned int)*(v10 - 13)) != 1 )
              return v6;
          }
          if ( *(v7 - 12) != *(v10 - 12) )
          {
            v6 = 2 * (*(v7 - 12) > (unsigned int)*(v10 - 12)) - 1;
            if ( 2 * (*(v7 - 12) > (unsigned int)*(v10 - 12)) != 1 )
              return v6;
          }
          v6 = *(v7 - 11) - *(v10 - 11);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 11) > (unsigned int)*(v10 - 11)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN92:
        if ( *(_DWORD *)(v7 - 10) == *(_DWORD *)(v10 - 10) )
        {
          v6 = 0;
        }
        else
        {
          if ( *(v7 - 10) != *(v10 - 10) )
          {
            v6 = 2 * (*(v7 - 10) > (unsigned int)*(v10 - 10)) - 1;
            if ( 2 * (*(v7 - 10) > (unsigned int)*(v10 - 10)) != 1 )
              return v6;
          }
          if ( *(v7 - 9) != *(v10 - 9) )
          {
            v6 = 2 * (*(v7 - 9) > (unsigned int)*(v10 - 9)) - 1;
            if ( 2 * (*(v7 - 9) > (unsigned int)*(v10 - 9)) != 1 )
              return v6;
          }
          if ( *(v7 - 8) != *(v10 - 8) )
          {
            v6 = 2 * (*(v7 - 8) > (unsigned int)*(v10 - 8)) - 1;
            if ( 2 * (*(v7 - 8) > (unsigned int)*(v10 - 8)) != 1 )
              return v6;
          }
          v6 = *(v7 - 7) - *(v10 - 7);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 7) > (unsigned int)*(v10 - 7)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN90:
        v31 = *(_DWORD *)(v7 - 6);
        if ( v31 == *(_DWORD *)(v10 - 6) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v31 != *(v10 - 6) )
          {
            v6 = 2 * ((unsigned __int8)v31 > (unsigned int)*(v10 - 6)) - 1;
            if ( 2 * ((unsigned __int8)v31 > (unsigned int)*(v10 - 6)) != 1 )
              return v6;
          }
          if ( *(v7 - 5) != *(v10 - 5) )
          {
            v6 = 2 * (*(v7 - 5) > (unsigned int)*(v10 - 5)) - 1;
            if ( 2 * (*(v7 - 5) > (unsigned int)*(v10 - 5)) != 1 )
              return v6;
          }
          if ( *(v7 - 4) != *(v10 - 4) )
          {
            v6 = 2 * (*(v7 - 4) > (unsigned int)*(v10 - 4)) - 1;
            if ( 2 * (*(v7 - 4) > (unsigned int)*(v10 - 4)) != 1 )
              return v6;
          }
          v6 = *(v7 - 3) - *(v10 - 3);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 3) > (unsigned int)*(v10 - 3)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN88_1:
        if ( *((_WORD *)v7 - 1) == *((_WORD *)v10 - 1) )
          return 0;
        goto LABEL_335;
      case 0x1Fu:
        if ( *(_DWORD *)(v7 - 31) == *(_DWORD *)(v10 - 31) )
        {
          v6 = 0;
        }
        else
        {
          if ( *(v7 - 31) != *(v10 - 31) )
          {
            v6 = 2 * (*(v7 - 31) > (unsigned int)*(v10 - 31)) - 1;
            if ( 2 * (*(v7 - 31) > (unsigned int)*(v10 - 31)) != 1 )
              return v6;
          }
          if ( *(v7 - 30) != *(v10 - 30) )
          {
            v6 = 2 * (*(v7 - 30) > (unsigned int)*(v10 - 30)) - 1;
            if ( 2 * (*(v7 - 30) > (unsigned int)*(v10 - 30)) != 1 )
              return v6;
          }
          if ( *(v7 - 29) != *(v10 - 29) )
          {
            v6 = 2 * (*(v7 - 29) > (unsigned int)*(v10 - 29)) - 1;
            if ( 2 * (*(v7 - 29) > (unsigned int)*(v10 - 29)) != 1 )
              return v6;
          }
          v6 = *(v7 - 28) - *(v10 - 28);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 28) > (unsigned int)*(v10 - 28)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN85:
        v33 = *(_DWORD *)(v7 - 27);
        if ( v33 == *(_DWORD *)(v10 - 27) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v33 != *(v10 - 27) )
          {
            v6 = 2 * ((unsigned __int8)v33 > (unsigned int)*(v10 - 27)) - 1;
            if ( 2 * ((unsigned __int8)v33 > (unsigned int)*(v10 - 27)) != 1 )
              return v6;
          }
          if ( *(v7 - 26) != *(v10 - 26) )
          {
            v6 = 2 * (*(v7 - 26) > (unsigned int)*(v10 - 26)) - 1;
            if ( 2 * (*(v7 - 26) > (unsigned int)*(v10 - 26)) != 1 )
              return v6;
          }
          if ( *(v7 - 25) != *(v10 - 25) )
          {
            v6 = 2 * (*(v7 - 25) > (unsigned int)*(v10 - 25)) - 1;
            if ( 2 * (*(v7 - 25) > (unsigned int)*(v10 - 25)) != 1 )
              return v6;
          }
          v6 = *(v7 - 24) - *(v10 - 24);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 24) > (unsigned int)*(v10 - 24)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN83_0:
        v34 = *(_DWORD *)(v7 - 23);
        if ( v34 == *(_DWORD *)(v10 - 23) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v34 != *(v10 - 23) )
          {
            v6 = 2 * ((unsigned __int8)v34 > (unsigned int)*(v10 - 23)) - 1;
            if ( 2 * ((unsigned __int8)v34 > (unsigned int)*(v10 - 23)) != 1 )
              return v6;
          }
          if ( *(v7 - 22) != *(v10 - 22) )
          {
            v6 = 2 * (*(v7 - 22) > (unsigned int)*(v10 - 22)) - 1;
            if ( 2 * (*(v7 - 22) > (unsigned int)*(v10 - 22)) != 1 )
              return v6;
          }
          if ( *(v7 - 21) != *(v10 - 21) )
          {
            v6 = 2 * (*(v7 - 21) > (unsigned int)*(v10 - 21)) - 1;
            if ( 2 * (*(v7 - 21) > (unsigned int)*(v10 - 21)) != 1 )
              return v6;
          }
          v6 = *(v7 - 20) - *(v10 - 20);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 20) > (unsigned int)*(v10 - 20)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN81:
        v35 = *(_DWORD *)(v7 - 19);
        if ( v35 == *(_DWORD *)(v10 - 19) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v35 != *(v10 - 19) )
          {
            v6 = 2 * ((unsigned __int8)v35 > (unsigned int)*(v10 - 19)) - 1;
            if ( 2 * ((unsigned __int8)v35 > (unsigned int)*(v10 - 19)) != 1 )
              return v6;
          }
          if ( *(v7 - 18) != *(v10 - 18) )
          {
            v6 = 2 * (*(v7 - 18) > (unsigned int)*(v10 - 18)) - 1;
            if ( 2 * (*(v7 - 18) > (unsigned int)*(v10 - 18)) != 1 )
              return v6;
          }
          if ( *(v7 - 17) != *(v10 - 17) )
          {
            v6 = 2 * (*(v7 - 17) > (unsigned int)*(v10 - 17)) - 1;
            if ( 2 * (*(v7 - 17) > (unsigned int)*(v10 - 17)) != 1 )
              return v6;
          }
          v6 = *(v7 - 16) - *(v10 - 16);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 16) > (unsigned int)*(v10 - 16)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN79:
        if ( *(_DWORD *)(v7 - 15) == *(_DWORD *)(v10 - 15) )
        {
          v6 = 0;
        }
        else
        {
          if ( *(v7 - 15) != *(v10 - 15) )
          {
            v6 = 2 * (*(v7 - 15) > (unsigned int)*(v10 - 15)) - 1;
            if ( 2 * (*(v7 - 15) > (unsigned int)*(v10 - 15)) != 1 )
              return v6;
          }
          if ( *(v7 - 14) != *(v10 - 14) )
          {
            v6 = 2 * (*(v7 - 14) > (unsigned int)*(v10 - 14)) - 1;
            if ( 2 * (*(v7 - 14) > (unsigned int)*(v10 - 14)) != 1 )
              return v6;
          }
          if ( *(v7 - 13) != *(v10 - 13) )
          {
            v6 = 2 * (*(v7 - 13) > (unsigned int)*(v10 - 13)) - 1;
            if ( 2 * (*(v7 - 13) > (unsigned int)*(v10 - 13)) != 1 )
              return v6;
          }
          v6 = *(v7 - 12) - *(v10 - 12);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 12) > (unsigned int)*(v10 - 12)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN77:
        v36 = *(_DWORD *)(v7 - 11);
        if ( v36 == *(_DWORD *)(v10 - 11) )
        {
          v6 = 0;
        }
        else
        {
          if ( (unsigned __int8)v36 != *(v10 - 11) )
          {
            v6 = 2 * ((unsigned __int8)v36 > (unsigned int)*(v10 - 11)) - 1;
            if ( 2 * ((unsigned __int8)v36 > (unsigned int)*(v10 - 11)) != 1 )
              return v6;
          }
          if ( *(v7 - 10) != *(v10 - 10) )
          {
            v6 = 2 * (*(v7 - 10) > (unsigned int)*(v10 - 10)) - 1;
            if ( 2 * (*(v7 - 10) > (unsigned int)*(v10 - 10)) != 1 )
              return v6;
          }
          if ( *(v7 - 9) != *(v10 - 9) )
          {
            v6 = 2 * (*(v7 - 9) > (unsigned int)*(v10 - 9)) - 1;
            if ( 2 * (*(v7 - 9) > (unsigned int)*(v10 - 9)) != 1 )
              return v6;
          }
          v6 = *(v7 - 8) - *(v10 - 8);
          if ( v6 != 0 )
            v6 = 2 * (*(v7 - 8) > (unsigned int)*(v10 - 8)) - 1;
        }
        if ( v6 != 0 )
          return v6;
$LN75_2:
        v37 = *(_DWORD *)(v7 - 7);
        if ( v37 != *(_DWORD *)(v10 - 7) )
        {
          if ( (unsigned __int8)v37 == *(v10 - 7)
            || (v6 = 2 * ((unsigned __int8)v37 > (unsigned int)*(v10 - 7)) - 1,
                2 * ((unsigned __int8)v37 > (unsigned int)*(v10 - 7)) == 1) )
          {
            if ( *(v7 - 6) == *(v10 - 6)
              || (v6 = 2 * (*(v7 - 6) > (unsigned int)*(v10 - 6)) - 1, 2 * (*(v7 - 6) > (unsigned int)*(v10 - 6)) == 1) )
            {
              if ( *(v7 - 5) == *(v10 - 5)
                || (v6 = 2 * (*(v7 - 5) > (unsigned int)*(v10 - 5)) - 1, 2 * (*(v7 - 5) > (unsigned int)*(v10 - 5)) == 1) )
              {
                v6 = *(v7 - 4) - *(v10 - 4);
                if ( v6 != 0 )
                  v6 = 2 * (*(v7 - 4) > (unsigned int)*(v10 - 4)) - 1;
                goto LABEL_414;
              }
            }
          }
          return v6;
        }
        v6 = 0;
LABEL_414:
        if ( v6 != 0 )
          return v6;
$LN73_0:
        if ( *(v7 - 3) != *(v10 - 3) )
        {
          v32 = 2 * (*(v7 - 3) > (unsigned int)*(v10 - 3)) - 1;
          if ( 2 * (*(v7 - 3) > (unsigned int)*(v10 - 3)) != 1 )
            return v32;
        }
LABEL_335:
        if ( *(v7 - 2) != *(v10 - 2) )
        {
          v32 = 2 * (*(v7 - 2) > (unsigned int)*(v10 - 2)) - 1;
          if ( 2 * (*(v7 - 2) > (unsigned int)*(v10 - 2)) != 1 )
            return v32;
        }
$LN103:
        result = *(v7 - 1) - *(v10 - 1);
        if ( result != 0 )
          return 2 * (result > 0) - 1;
        return result;
      default:
        if ( *(_DWORD *)v8 == *(_DWORD *)v9 )
        {
          v6 = 0;
        }
        else
        {
          if ( *v8 != *v9 )
          {
            v6 = 2 * (*v8 > (unsigned int)*v9) - 1;
            if ( 2 * (*v8 > (unsigned int)*v9) != 1 )
              return v6;
          }
          if ( v8[1] != v9[1] )
          {
            v6 = 2 * (v8[1] > (unsigned int)v9[1]) - 1;
            if ( 2 * (v8[1] > (unsigned int)v9[1]) != 1 )
              return v6;
          }
          if ( v8[2] != v9[2] )
          {
            v6 = 2 * (v8[2] > (unsigned int)v9[2]) - 1;
            if ( 2 * (v8[2] > (unsigned int)v9[2]) != 1 )
              return v6;
          }
          v6 = v8[3] - v9[3];
          if ( v6 != 0 )
            v6 = 2 * (v8[3] > (unsigned int)v9[3]) - 1;
        }
        if ( v6 != 0 )
          return v6;
        if ( *((_DWORD *)v8 + 1) == *((_DWORD *)v9 + 1) )
        {
          v6 = 0;
        }
        else
        {
          if ( v8[4] != v9[4] )
          {
            v6 = 2 * (v8[4] > (unsigned int)v9[4]) - 1;
            if ( 2 * (v8[4] > (unsigned int)v9[4]) != 1 )
              return v6;
          }
          if ( v8[5] != v9[5] )
          {
            v6 = 2 * (v8[5] > (unsigned int)v9[5]) - 1;
            if ( 2 * (v8[5] > (unsigned int)v9[5]) != 1 )
              return v6;
          }
          if ( v8[6] != v9[6] )
          {
            v6 = 2 * (v8[6] > (unsigned int)v9[6]) - 1;
            if ( 2 * (v8[6] > (unsigned int)v9[6]) != 1 )
              return v6;
          }
          v6 = v8[7] - v9[7];
          if ( v6 != 0 )
            v6 = 2 * (v8[7] > (unsigned int)v9[7]) - 1;
        }
        if ( v6 != 0 )
          return v6;
        if ( *((_DWORD *)v8 + 2) == *((_DWORD *)v9 + 2) )
        {
          v6 = 0;
        }
        else
        {
          if ( v8[8] != v9[8] )
          {
            v6 = 2 * (v8[8] > (unsigned int)v9[8]) - 1;
            if ( 2 * (v8[8] > (unsigned int)v9[8]) != 1 )
              return v6;
          }
          if ( v8[9] != v9[9] )
          {
            v6 = 2 * (v8[9] > (unsigned int)v9[9]) - 1;
            if ( 2 * (v8[9] > (unsigned int)v9[9]) != 1 )
              return v6;
          }
          if ( v8[10] != v9[10] )
          {
            v6 = 2 * (v8[10] > (unsigned int)v9[10]) - 1;
            if ( 2 * (v8[10] > (unsigned int)v9[10]) != 1 )
              return v6;
          }
          v6 = v8[11] - v9[11];
          if ( v6 != 0 )
            v6 = 2 * (v8[11] > (unsigned int)v9[11]) - 1;
        }
        if ( v6 != 0 )
          return v6;
        if ( *((_DWORD *)v8 + 3) == *((_DWORD *)v9 + 3) )
        {
          v6 = 0;
        }
        else
        {
          if ( v8[12] != v9[12] )
          {
            v6 = 2 * (v8[12] > (unsigned int)v9[12]) - 1;
            if ( 2 * (v8[12] > (unsigned int)v9[12]) != 1 )
              return v6;
          }
          if ( v8[13] != v9[13] )
          {
            v6 = 2 * (v8[13] > (unsigned int)v9[13]) - 1;
            if ( 2 * (v8[13] > (unsigned int)v9[13]) != 1 )
              return v6;
          }
          if ( v8[14] != v9[14] )
          {
            v6 = 2 * (v8[14] > (unsigned int)v9[14]) - 1;
            if ( 2 * (v8[14] > (unsigned int)v9[14]) != 1 )
              return v6;
          }
          v6 = v8[15] - v9[15];
          if ( v6 != 0 )
            v6 = 2 * (v8[15] > (unsigned int)v9[15]) - 1;
        }
        if ( v6 != 0 )
          return v6;
        if ( *((_DWORD *)v8 + 4) == *((_DWORD *)v9 + 4) )
        {
          v6 = 0;
        }
        else
        {
          if ( v8[16] != v9[16] )
          {
            v6 = 2 * (v8[16] > (unsigned int)v9[16]) - 1;
            if ( 2 * (v8[16] > (unsigned int)v9[16]) != 1 )
              return v6;
          }
          if ( v8[17] != v9[17] )
          {
            v6 = 2 * (v8[17] > (unsigned int)v9[17]) - 1;
            if ( 2 * (v8[17] > (unsigned int)v9[17]) != 1 )
              return v6;
          }
          if ( v8[18] != v9[18] )
          {
            v6 = 2 * (v8[18] > (unsigned int)v9[18]) - 1;
            if ( 2 * (v8[18] > (unsigned int)v9[18]) != 1 )
              return v6;
          }
          v6 = v8[19] - v9[19];
          if ( v6 != 0 )
            v6 = 2 * (v8[19] > (unsigned int)v9[19]) - 1;
        }
        if ( v6 != 0 )
          return v6;
        if ( *((_DWORD *)v8 + 5) == *((_DWORD *)v9 + 5) )
        {
          v6 = 0;
        }
        else
        {
          if ( v8[20] != v9[20] )
          {
            v6 = 2 * (v8[20] > (unsigned int)v9[20]) - 1;
            if ( 2 * (v8[20] > (unsigned int)v9[20]) != 1 )
              return v6;
          }
          if ( v8[21] != v9[21] )
          {
            v6 = 2 * (v8[21] > (unsigned int)v9[21]) - 1;
            if ( 2 * (v8[21] > (unsigned int)v9[21]) != 1 )
              return v6;
          }
          if ( v8[22] != v9[22] )
          {
            v6 = 2 * (v8[22] > (unsigned int)v9[22]) - 1;
            if ( 2 * (v8[22] > (unsigned int)v9[22]) != 1 )
              return v6;
          }
          v6 = v8[23] - v9[23];
          if ( v6 != 0 )
            v6 = 2 * (v8[23] > (unsigned int)v9[23]) - 1;
        }
        if ( v6 != 0 )
          return v6;
        if ( *((_DWORD *)v8 + 6) == *((_DWORD *)v9 + 6) )
        {
          v6 = 0;
        }
        else
        {
          if ( v8[24] != v9[24] )
          {
            v6 = 2 * (v8[24] > (unsigned int)v9[24]) - 1;
            if ( 2 * (v8[24] > (unsigned int)v9[24]) != 1 )
              return v6;
          }
          if ( v8[25] != v9[25] )
          {
            v6 = 2 * (v8[25] > (unsigned int)v9[25]) - 1;
            if ( 2 * (v8[25] > (unsigned int)v9[25]) != 1 )
              return v6;
          }
          if ( v8[26] != v9[26] )
          {
            v6 = 2 * (v8[26] > (unsigned int)v9[26]) - 1;
            if ( 2 * (v8[26] > (unsigned int)v9[26]) != 1 )
              return v6;
          }
          v6 = v8[27] - v9[27];
          if ( v6 != 0 )
            v6 = 2 * (v8[27] > (unsigned int)v9[27]) - 1;
        }
        if ( v6 != 0 )
          return v6;
        if ( *((_DWORD *)v8 + 7) == *((_DWORD *)v9 + 7) )
        {
          v6 = 0;
        }
        else
        {
          if ( v8[28] != v9[28] )
          {
            v6 = 2 * (v8[28] > (unsigned int)v9[28]) - 1;
            if ( 2 * (v8[28] > (unsigned int)v9[28]) != 1 )
              return v6;
          }
          if ( v8[29] != v9[29] )
          {
            v6 = 2 * (v8[29] > (unsigned int)v9[29]) - 1;
            if ( 2 * (v8[29] > (unsigned int)v9[29]) != 1 )
              return v6;
          }
          if ( v8[30] != v9[30] )
          {
            v6 = 2 * (v8[30] > (unsigned int)v9[30]) - 1;
            if ( 2 * (v8[30] > (unsigned int)v9[30]) != 1 )
              return v6;
          }
          v6 = v8[31] - v9[31];
          if ( v6 != 0 )
            v6 = 2 * (v8[31] > (unsigned int)v9[31]) - 1;
        }
        if ( v6 != 0 )
          return v6;
        v5 = v8 + 32;
        v4 = v9 + 32;
        v3 -= 32;
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E0A96
// Name: __crtGetStringTypeA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetStringTypeA_stat(
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  localeinfo_struct *plocinfo; // ecx
  int v8; // eax
  wchar_t *v9; // ebx
  localeinfo_struct *v10; // edi
  int v11; // eax
  int v12; // edi
  unsigned int v13; // eax
  void *v14; // esp
  wchar_t *v15; // eax
  int v16; // eax
  char *v18; // esi
  int v19; // eax
  const char *v20; // eax
  BOOL StringTypeA; // edi
  _DWORD v22[3]; // [esp+0h] [ebp-14h] BYREF
  int retval2; // [esp+Ch] [ebp-8h] BYREF

  v8 = f_use_3;
  v9 = nullptr;
  v10 = plocinfo;
  if ( f_use_3 == 0 )
  {
    if ( GetStringTypeW(dwInfoType: 1u, lpSrcStr: &FLOAT_0_0, cchSrc: 1, lpCharType: (LPWORD)&retval2) )
    {
      f_use_3 = 1;
      goto LABEL_10;
    }
    if ( GetLastError() == 120 )
    {
      v8 = 2;
      f_use_3 = 2;
    }
    else
    {
      v8 = f_use_3;
    }
  }
  if ( v8 != 2 && v8 != 0 )
  {
    if ( v8 != 1 )
      return 0;
LABEL_10:
    retval2 = 0;
    if ( code_page == 0 )
      code_page = v10->locinfo->lc_codepage;
    v11 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 8 * (bError != 0) + 1,
            lpMultiByteStr: lpSrcStr,
            cbMultiByte: cchSrc,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v12 = v11;
    if ( v11 == 0 )
      return 0;
    if ( v11 > 0 && (unsigned int)v11 <= 0x7FFFFFF0 )
    {
      v13 = 2 * v11 + 8;
      if ( v13 > 0x400 )
      {
        v15 = (wchar_t *)MemAlloc_Alloc(nSize: 2 * v12 + 8);
        if ( v15 != nullptr )
        {
          *(_DWORD *)v15 = 56797;
          goto LABEL_20;
        }
      }
      else
      {
        v14 = alloca(v13);
        v15 = (wchar_t *)v22;
        if ( v22 != nullptr )
        {
          v22[0] = 52428;
LABEL_20:
          v15 += 4;
        }
      }
      v9 = v15;
    }
    if ( v9 != nullptr )
    {
      memset(dst: (int)v9, value: nullptr, count: 2 * v12);
      v16 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 1u,
              lpMultiByteStr: lpSrcStr,
              cbMultiByte: cchSrc,
              lpWideCharStr: v9,
              cchWideChar: v12);
      if ( v16 != 0 )
        retval2 = GetStringTypeW(dwInfoType, lpSrcStr: v9, cchSrc: v16, lpCharType);
      _freea(_Memory: v9);
      return retval2;
    }
    return 0;
  }
  v18 = nullptr;
  if ( lcid == 0 )
    lcid = v10->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v10->locinfo->lc_codepage;
  v19 = __ansicp(lcid);
  if ( v19 == -1 )
    return 0;
  if ( v19 != code_page )
  {
    v20 = __convertcp(fromCP: code_page, toCP: v19, lpSrcStr, pcchSrc: &cchSrc, lpDestStr: nullptr, cchDest: 0);
    v18 = (char *)v20;
    if ( v20 == nullptr )
      return 0;
    lpSrcStr = v20;
  }
  StringTypeA = GetStringTypeA(Locale: lcid, dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( v18 != nullptr )
    free(pMem: v18);
  return StringTypeA;
}

//------------------------------------------------------------------------------
// Address: 0x004E0C4E
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(dwInfoType, lpSrcStr, cchSrc, lpCharType, code_page, lcid, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E0C8E
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( count == 0 )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
    goto LABEL_23;
  }
  v4 = last;
  v5 = first;
  do
  {
    v6 = *v5;
    v5 += 4;
    v4 += 4;
    if ( v6 == 0 || v6 != *(v4 - 4) )
    {
      v10 = *((unsigned __int8 *)v5 - 4);
      v11 = *((unsigned __int8 *)v4 - 4);
      return v10 - v11;
    }
    v7 = *(v5 - 3);
    if ( v7 == 0 || v7 != *(v4 - 3) )
    {
      v10 = *((unsigned __int8 *)v5 - 3);
      v11 = *((unsigned __int8 *)v4 - 3);
      return v10 - v11;
    }
    v8 = *(v5 - 2);
    if ( v8 == 0 || v8 != *(v4 - 2) )
    {
      v10 = *((unsigned __int8 *)v5 - 2);
      v11 = *((unsigned __int8 *)v4 - 2);
      return v10 - v11;
    }
    v9 = *(v5 - 1);
    if ( v9 == 0 || v9 != *(v4 - 1) )
    {
      v10 = *((unsigned __int8 *)v5 - 1);
      v11 = *((unsigned __int8 *)v4 - 1);
      return v10 - v11;
    }
    n += 4;
  }
  while ( n < count - 4 );
  while ( 1 )
  {
LABEL_23:
    if ( n >= count )
      return 0;
    if ( *v5 == 0 || *v5 != *v4 )
      break;
    ++v5;
    ++v4;
    ++n;
  }
  v10 = *(unsigned __int8 *)v5;
  v11 = *(unsigned __int8 *)v4;
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x004E0D50
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x004E0D90
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x004E0DBD
// Name: __atodbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atodbl_l(_CRT_DOUBLE *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tod(pld12: &ld12, d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E0E63
// Name: __atoflt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atoflt_l(_CRT_FLOAT *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tof(pld12: &ld12, f: d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E0F09
// Name: __fptostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fptostr(char *buf, unsigned int sizeInBytes, int digits, _strflt *pflt)
{
  _strflt *v4; // ecx
  char *mantissa; // edi
  unsigned int v6; // esi
  int v8; // edx
  int v9; // eax
  char *v10; // eax
  char v11; // cl
  int v12; // eax

  v4 = pflt;
  mantissa = pflt->mantissa;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v6 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter(a1: 0, a2: (unsigned int)mantissa, a3: v6);
    return v6;
  }
  v8 = digits;
  *buf = 0;
  if ( digits <= 0 )
    v9 = 0;
  else
    v9 = digits;
  if ( sizeInBytes <= v9 + 1 )
  {
    *_errno() = 34;
    v6 = 34;
    goto LABEL_3;
  }
  *buf = 48;
  v10 = buf + 1;
  if ( digits > 0 )
  {
    do
    {
      v11 = *mantissa;
      if ( *mantissa != 0 )
        ++mantissa;
      else
        v11 = 48;
      *v10++ = v11;
      --v8;
    }
    while ( v8 > 0 );
    v4 = pflt;
  }
  *v10 = 0;
  if ( v8 >= 0 && *mantissa >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *buf == 49 )
  {
    ++v4->decpt;
  }
  else
  {
    strlen(buf: buf + 1);
    memmove(dst: (unsigned __int8 *)buf, src: (unsigned __int8 *)buf + 1, count: v12 + 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E0FC6
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __dtold(_LDOUBLE *pld, long double *px)
{
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax
  __int16 v7; // cx
  __int16 v8; // di
  _LDOUBLE *v9; // eax
  __int16 v10; // cx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  unsigned int msb; // [esp+Ch] [ebp-4h]
  __int16 sign; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)px + 3) >> 4) & 0x7FF;
  sign = *((_WORD *)px + 3) & 0x8000;
  v4 = *((_DWORD *)px + 1);
  v5 = *(_DWORD *)px;
  v6 = v4 & 0xFFFFF;
  msb = 0x80000000;
  if ( (_WORD)v3 == 0 )
  {
    if ( v6 == 0 && v5 == 0 )
    {
      v9 = pld;
      v10 = sign;
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_13;
    }
    v7 = 15361;
    msb = 0;
    goto LABEL_9;
  }
  if ( (unsigned __int16)v3 != 2047 )
  {
    v7 = v3 + 15360;
LABEL_9:
    v8 = v7;
    goto LABEL_10;
  }
  v8 = 0x7FFF;
LABEL_10:
  v11 = msb | (v6 << 11) | (v5 >> 21);
  v9 = pld;
  *(_DWORD *)&pld->ld[4] = v11;
  *(_DWORD *)pld->ld = v5 << 11;
  if ( (v11 & 0x80000000) == 0 )
  {
    do
    {
      v12 = *(__int64 *)pld->ld >> 31;
      v13 = 2 * *(_DWORD *)pld->ld;
      --v8;
      *(_DWORD *)&pld->ld[4] = v12;
      *(_DWORD *)pld->ld = v13;
    }
    while ( (v12 & 0x80000000) == 0 );
  }
  v10 = v8 | sign;
LABEL_13:
  *(_WORD *)&v9->ld[8] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x004E1081
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  int v5; // eax
  char *v6; // esi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  _BYTE v10[26]; // [esp-Eh] [ebp-4Ah] BYREF
  char *_Dst; // [esp+Ch] [ebp-30h]
  _FloatOutStruct autofos; // [esp+10h] [ebp-2Ch] BYREF
  _LDOUBLE ld; // [esp+2Ch] [ebp-10h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(pld: &ld, px: &x.x);
  v5 = _I10_OUTPUT(ld, ndigits: 17, output_flags: 0, fos: &autofos);
  v6 = _Dst;
  v4->flag = v5;
  v4->sign = autofos.sign;
  v4->decpt = autofos.exp;
  if ( strcpy_s(a1: (unsigned int)v10, _Dst: v6, _SizeInBytes: resultsize, _Src: autofos.man) != 0 )
  {
    memset(v10, 0, 14);
    _invoke_watson(a1: 0, a2: v7, a3: v8, a4: (unsigned int)v4, a5: (unsigned int)v10, a6: (unsigned int)v6);
  }
  v4->mantissa = v6;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004E1110
// Name: __alldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldvrm(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  int v5; // esi
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  int result; // eax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v5 = v7 / (unsigned int)v6;
    v8 = (unsigned int)v5 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v5, HIDWORD(v8))
      || (HIDWORD(v8) = (a2 * (unsigned __int64)(unsigned int)v5) >> 32, v8 > a1) )
    {
      --v5;
    }
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    v5 = v4 / (unsigned int)a2;
  }
  result = v5;
  if ( v2 == 1 )
    return -v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E11F0
// Name: __aullshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __usercall _aullshr@<edx:eax>(unsigned __int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
    return 0;
  else
    return a1 >> a2;
}

//------------------------------------------------------------------------------
// Address: 0x004E120F
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _fptrap()
{
  _amsg_exit(rterrnum: 2);
}

//------------------------------------------------------------------------------
// Address: 0x004E1218
// Name: ___crtMessageBoxA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtMessageBoxA(const char *lpText, const char *lpCaption, unsigned int uType)
{
  HMODULE LibraryA; // eax
  HMODULE v4; // edi
  int (__stdcall *MessageBoxA)(HWND, LPCSTR, LPCSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  unsigned int v8; // eax
  unsigned int v9; // edx
  BOOL (__stdcall *GetUserObjectInformationA)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v12)(void); // esi
  int (__stdcall *v13)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // eax
  int (__stdcall *v14)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // edi
  int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // edx
  int (*v18)(void); // eax
  int (__stdcall *v19)(HWND__ *); // eax
  int (__stdcall *v20)(HWND__ *, const char *, const char *, unsigned int); // eax
  LPCSTR lpProcName; // [esp+0h] [ebp-30h]
  LPCSTR lpProcNamea; // [esp+0h] [ebp-30h]
  tagUSEROBJECTFLAGS uof; // [esp+10h] [ebp-20h] BYREF
  unsigned int nDummy; // [esp+1Ch] [ebp-14h] BYREF
  unsigned int winmajor; // [esp+20h] [ebp-10h] BYREF
  unsigned int osplatform; // [esp+24h] [ebp-Ch] BYREF
  void *enull; // [esp+28h] [ebp-8h]
  HWND__ *hWndParent; // [esp+2Ch] [ebp-4h]

  enull = _encoded_null();
  hWndParent = nullptr;
  osplatform = 0;
  winmajor = 0;
  if ( pfnMessageBox == nullptr )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "USER32.DLL");
    v4 = LibraryA;
    if ( LibraryA == nullptr )
      return 0;
    MessageBoxA = (int (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))GetProcAddress(
                                                                   hModule: LibraryA,
                                                                   lpProcName: "MessageBoxA");
    if ( MessageBoxA == nullptr )
      return 0;
    pfnMessageBox = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_encode_pointer(ptr: MessageBoxA);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: v4, lpProcName: "GetActiveWindow");
    pfnGetActiveWindow = (HWND__ *(__stdcall *)())_encode_pointer(ptr: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: v4, lpProcName: "GetLastActivePopup");
    pfnGetLastActivePopup = (HWND__ *(__stdcall *)(HWND__ *))_encode_pointer(ptr: GetLastActivePopup);
    v8 = _get_osplatform(pValue: &osplatform);
    if ( v8 != 0 )
      _invoke_watson(
        a1: v8,
        a2: v9,
        a3: (unsigned int)lpProcName,
        a4: 0,
        a5: (unsigned int)v4,
        a6: (unsigned int)GetProcAddress);
    if ( osplatform == 2 )
    {
      GetUserObjectInformationA = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                            hModule: v4,
                                                                                            lpProcName: "GetUserObjectInformationA");
      pfnGetUserObjectInformation = (int (__stdcall *)(void *, int, void *, unsigned int, unsigned int *))_encode_pointer(ptr: GetUserObjectInformationA);
      if ( pfnGetUserObjectInformation != nullptr )
      {
        GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                             hModule: v4,
                                                             lpProcName: "GetProcessWindowStation");
        pfnGetProcessWindowStation = (HWINSTA__ *(__stdcall *)())_encode_pointer(ptr: GetProcessWindowStation);
      }
    }
  }
  if ( pfnGetProcessWindowStation == enull
    || pfnGetUserObjectInformation == enull
    || (v12 = (int (*)(void))_decode_pointer(codedptr: pfnGetProcessWindowStation),
        v13 = (int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))_decode_pointer(codedptr: pfnGetUserObjectInformation),
        v14 = v13,
        v12 == nullptr)
    || v13 == nullptr
    || (v15 = v12()) != 0 && v14(a1: v15, a2: 1, a3: &uof, a4: 12, a5: &nDummy) != 0 && (uof.dwFlags & 1) != 0 )
  {
    if ( pfnGetActiveWindow != enull )
    {
      v18 = (int (*)(void))_decode_pointer(codedptr: pfnGetActiveWindow);
      if ( v18 != nullptr )
      {
        hWndParent = (HWND__ *)v18();
        if ( hWndParent != nullptr && pfnGetLastActivePopup != enull )
        {
          v19 = (int (__stdcall *)(HWND__ *))_decode_pointer(codedptr: pfnGetLastActivePopup);
          if ( v19 != nullptr )
            hWndParent = (HWND__ *)v19(a1: hWndParent);
        }
      }
    }
  }
  else
  {
    v16 = _get_winmajor(pValue: &winmajor);
    if ( v16 != 0 )
      _invoke_watson(
        a1: v16,
        a2: v17,
        a3: (unsigned int)lpProcNamea,
        a4: 0,
        a5: (unsigned int)v14,
        a6: (unsigned int)v12);
    if ( winmajor < 4 )
      uType |= 0x40000u;
    else
      uType |= 0x200000u;
  }
  v20 = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_decode_pointer(codedptr: pfnMessageBox);
  if ( v20 != nullptr )
    return v20(a1: hWndParent, a2: lpText, a3: lpCaption, a4: uType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E13D5
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _set_error_mode@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int em)
{
  int result; // eax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = __error_mode;
      __error_mode = em;
      return result;
    }
    if ( em == 3 )
      return __error_mode;
  }
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E141B
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _crt_debugger_hook()
{
  _debugger_hook_dummy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E1423
// Name: __crtGetLocaleInfoW_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetLocaleInfoW_stat(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        wchar_t *lpLCData,
        int cchData,
        UINT code_page)
{
  int v6; // eax
  int LocaleInfoA; // eax
  int v9; // ebx
  int v10; // eax
  void *v11; // esp
  CHAR *v12; // esi
  CHAR *v13; // eax
  int v14; // eax
  int v15; // [esp+0h] [ebp-14h] BYREF
  int v16; // [esp+8h] [ebp-Ch] BYREF
  int retval; // [esp+Ch] [ebp-8h]

  v6 = f_use_4;
  if ( f_use_4 == 0 )
  {
    if ( GetLocaleInfoW(Locale: 0, LCType: 1u, lpLCData: nullptr, cchData: 0) != 0 )
    {
      f_use_4 = 1;
      return GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
    }
    if ( GetLastError() == 120 )
    {
      v6 = 2;
      f_use_4 = 2;
    }
    else
    {
      v6 = f_use_4;
    }
  }
  if ( v6 == 1 )
    return GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
  if ( v6 != 2 && v6 != 0 )
    return 0;
  retval = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  LocaleInfoA = GetLocaleInfoA(Locale, LCType, lpLCData: nullptr, cchData: 0);
  v9 = LocaleInfoA;
  if ( LocaleInfoA == 0 )
    return 0;
  if ( LocaleInfoA > 0 && 0xFFFFFFE0 / LocaleInfoA != 0 )
  {
    v10 = LocaleInfoA + 8;
    if ( (unsigned int)(v9 + 8) > 0x400 )
    {
      v13 = (CHAR *)MemAlloc_Alloc(nSize: v9 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        v13 += 8;
      }
      v12 = v13;
    }
    else
    {
      v11 = alloca(v10);
      if ( &v15 == nullptr )
        return 0;
      v15 = 52428;
      v12 = (CHAR *)&v16;
    }
  }
  else
  {
    v12 = nullptr;
  }
  if ( v12 == nullptr )
    return 0;
  if ( GetLocaleInfoA(Locale, LCType, lpLCData: v12, cchData: v9) != 0 )
  {
    if ( cchData != 0 )
      v14 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 1u,
              lpMultiByteStr: v12,
              cbMultiByte: -1,
              lpWideCharStr: lpLCData,
              cchWideChar: cchData);
    else
      v14 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 1u,
              lpMultiByteStr: v12,
              cbMultiByte: -1,
              lpWideCharStr: nullptr,
              cchWideChar: 0);
    retval = v14;
  }
  _freea(_Memory: v12);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004E155E
// Name: ___crtGetLocaleInfoW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetLocaleInfoW(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        wchar_t *lpLCData,
        int cchData,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetLocaleInfoW_stat(plocinfo: &_loc_update.localeinfo, Locale, LCType, lpLCData, cchData, code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E1599
// Name: __crtGetLocaleInfoA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetLocaleInfoA_stat(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        char *lpLCData,
        int cchData,
        UINT code_page)
{
  int v6; // eax
  int v7; // esi
  int LocaleInfoW; // eax
  int v9; // ecx
  unsigned int v11; // eax
  void *v12; // esp
  WCHAR *v13; // edi
  WCHAR *v14; // eax
  int v15; // eax
  int v16; // [esp+0h] [ebp-14h] BYREF
  int v17; // [esp+8h] [ebp-Ch] BYREF
  int buff_size; // [esp+Ch] [ebp-8h]

  v6 = f_use_5;
  v7 = 0;
  if ( f_use_5 == 0 )
  {
    if ( GetLocaleInfoW(Locale: 0, LCType: 1u, lpLCData: nullptr, cchData: 0) != 0 )
    {
      f_use_5 = 1;
      goto LABEL_10;
    }
    if ( GetLastError() == 120 )
    {
      v6 = 2;
      f_use_5 = 2;
    }
    else
    {
      v6 = f_use_5;
    }
  }
  if ( v6 == 2 || v6 == 0 )
    return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
  if ( v6 != 1 )
    return 0;
LABEL_10:
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  LocaleInfoW = GetLocaleInfoW(Locale, LCType, lpLCData: nullptr, cchData: 0);
  v9 = LocaleInfoW;
  buff_size = LocaleInfoW;
  if ( LocaleInfoW == 0 )
    return 0;
  if ( LocaleInfoW <= 0 || 0xFFFFFFE0 / LocaleInfoW < 2 )
  {
    v13 = nullptr;
  }
  else
  {
    v11 = 2 * LocaleInfoW + 8;
    if ( v11 <= 0x400 )
    {
      v12 = alloca(v11);
      if ( &v16 != nullptr )
      {
        v16 = 52428;
        v13 = (WCHAR *)&v17;
        goto LABEL_23;
      }
      return 0;
    }
    v14 = (WCHAR *)MemAlloc_Alloc(nSize: 2 * v9 + 8);
    if ( v14 != nullptr )
    {
      *(_DWORD *)v14 = 56797;
      v14 += 4;
    }
    v13 = v14;
  }
LABEL_23:
  if ( v13 == nullptr )
    return 0;
  if ( GetLocaleInfoW(Locale, LCType, lpLCData: v13, cchData: buff_size) != 0 )
  {
    if ( cchData != 0 )
      v15 = WideCharToMultiByte(
              CodePage: code_page,
              dwFlags: 0,
              lpWideCharStr: v13,
              cchWideChar: -1,
              lpMultiByteStr: lpLCData,
              cbMultiByte: cchData,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
    else
      v15 = WideCharToMultiByte(
              CodePage: code_page,
              dwFlags: 0,
              lpWideCharStr: v13,
              cchWideChar: -1,
              lpMultiByteStr: nullptr,
              cbMultiByte: 0,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
    v7 = v15;
  }
  _freea(_Memory: v13);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004E16D6
// Name: ___crtGetLocaleInfoA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetLocaleInfoA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        char *lpLCData,
        int cchData,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetLocaleInfoA_stat(plocinfo: &_loc_update.localeinfo, Locale, LCType, lpLCData, cchData, code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E1711
// Name: __lseeki64_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
doubleint __cdecl _lseeki64_nolock(int fh, __int64 pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD LastError; // eax
  char *p_osfile; // eax
  doubleint newpos; // [esp+8h] [ebp-8h] BYREF

  newpos.bigint = pos;
  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return (doubleint)-1LL;
  }
  newpos.twoints.lowerhalf = SetFilePointer(
                               hFile: osfhandle,
                               lDistanceToMove: newpos.twoints.lowerhalf,
                               lpDistanceToMoveHigh: &newpos.twoints.upperhalf,
                               dwMoveMethod: mthd);
  if ( newpos.twoints.lowerhalf == -1 )
  {
    LastError = GetLastError();
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return (doubleint)-1LL;
    }
  }
  p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
  *p_osfile &= ~2u;
  return newpos;
}

//------------------------------------------------------------------------------
// Address: 0x004E1794
// Name: __lseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _lseeki64@<eax>(unsigned int a1@<ebx>, int fh, __int64 pos, DWORD mthd)
{
  int v5; // esi
  unsigned int r; // [esp+10h] [ebp-24h]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: 0xFFFFFFFF);
    return -1;
  }
  v5 = fh & 0x1F;
  if ( (__pioinfo[fh >> 5][v5].osfile & 1) != 0 )
  {
    __lock_fhandle(fh);
    if ( (__pioinfo[fh >> 5][v5].osfile & 1) != 0 )
    {
      r = _lseeki64_nolock(fh, pos, mthd).twoints.lowerhalf;
    }
    else
    {
      *_errno() = 9;
      *__doserrno() = 0;
      r = -1;
    }
    _unlock_fhandle(fh);
    return r;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1: 4 * (fh >> 5) + 6326944, a2: 0, a3: v5 * 56);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E18AD
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write_nolock@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh, char *buf, DWORD cnt)
{
  int v6; // ebx
  _DWORD *v7; // edi
  ioinfo *v8; // eax
  char v9; // cl
  BOOL v10; // esi
  UINT v11; // eax
  char *v12; // esi
  DWORD v13; // eax
  int v14; // esi
  ioinfo *v15; // eax
  DWORD v16; // ecx
  ioinfo *v17; // eax
  unsigned int v18; // ecx
  char *v19; // eax
  unsigned __int16 *v20; // edx
  char v21; // dl
  int v22; // esi
  unsigned int v23; // esi
  unsigned int v24; // ecx
  char *v25; // eax
  unsigned __int16 *v26; // edx
  unsigned __int16 v27; // dx
  int v28; // esi
  DWORD v29; // ecx
  wchar_t *v30; // eax
  wchar_t v31; // dx
  int v32; // esi
  int v33; // edi
  unsigned int v34; // esi
  unsigned __int8 v35; // [esp-Ch] [ebp-8Ch]
  unsigned int consoleCP; // [esp+4h] [ebp-7Ch] BYREF
  int bCR; // [esp+8h] [ebp-78h]
  char *pch; // [esp+Ch] [ebp-74h]
  _DWORD *v39; // [esp+10h] [ebp-70h]
  int written; // [esp+14h] [ebp-6Ch] BYREF
  int lfcount; // [esp+18h] [ebp-68h]
  char *s; // [esp+1Ch] [ebp-64h]
  int charcount; // [esp+20h] [ebp-60h]
  char *v44; // [esp+24h] [ebp-5Ch]
  char tmode; // [esp+2Bh] [ebp-55h]
  DWORD tmpchar; // [esp+2Ch] [ebp-54h] BYREF
  unsigned __int16 *pu; // [esp+30h] [ebp-50h] BYREF
  char utf8_buf[1028]; // [esp+34h] [ebp-4Ch] BYREF
  wchar_t utf16_buf[170]; // [esp+438h] [ebp+3B8h] BYREF
  char mboutbuf[8]; // [esp+58Ch] [ebp+50Ch] BYREF

  s = buf;
  charcount = 0;
  lfcount = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  v6 = fh & 0x1F;
  v7 = (_DWORD *)(4 * (fh >> 5) + 6326944);
  v8 = &__pioinfo[fh >> 5][v6];
  v9 = (char)(2 * *((_BYTE *)v8 + 36)) >> 1;
  v39 = v7;
  tmode = v9;
  if ( (v9 == 2 || v9 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1: v6 * 56, a2: (unsigned int)v7, a3: 0);
    return -1;
  }
  if ( (v8->osfile & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2u);
  if ( _isatty(fh) != 0 && __pioinfo[fh >> 5][v6].osfile < 0 )
  {
    v10 = _getptd()->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd, lpMode: &consoleCP)
      && (!v10 || tmode != 0) )
    {
      v11 = GetConsoleCP();
      pu = nullptr;
      v12 = s;
      consoleCP = v11;
      pch = s;
      v44 = nullptr;
      while ( 1 )
      {
        if ( tmode != 0 )
        {
          if ( tmode == 1 || tmode == 2 )
          {
            v16 = *(unsigned __int16 *)v12;
            v44 += 2;
            tmpchar = v16;
            pch = v12 + 2;
            bCR = (_WORD)v16 == 10;
          }
          if ( tmode == 1 || tmode == 2 )
          {
            if ( _putwch_nolock(ch: tmpchar) != (_WORD)tmpchar )
              goto LABEL_82;
            ++charcount;
            if ( bCR != 0 )
            {
              tmpchar = 13;
              if ( _putwch_nolock(ch: 0xDu) != 13 )
                goto LABEL_82;
              ++charcount;
              ++lfcount;
            }
          }
        }
        else
        {
          v35 = *v12;
          bCR = *v12 == 10;
          if ( isleadbyte(c: v35) != 0 )
          {
            if ( cnt + s - v12 <= 1 || mbtowc(pwc: (wchar_t *)&tmpchar, s: v12, n: 2u) == -1 )
              goto LABEL_83;
            ++v12;
            ++v44;
          }
          else if ( mbtowc(pwc: (wchar_t *)&tmpchar, s: v12, n: 1u) == -1 )
          {
            goto LABEL_83;
          }
          ++v44;
          pch = v12 + 1;
          v13 = WideCharToMultiByte(
                  CodePage: consoleCP,
                  dwFlags: 0,
                  lpWideCharStr: (LPCWCH)&tmpchar,
                  cchWideChar: 1,
                  lpMultiByteStr: mboutbuf,
                  cbMultiByte: 5,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          v14 = v13;
          if ( v13 == 0 )
            goto LABEL_83;
          if ( !WriteFile(
                  hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                  lpBuffer: mboutbuf,
                  nNumberOfBytesToWrite: v13,
                  lpNumberOfBytesWritten: (LPDWORD)&pu,
                  lpOverlapped: nullptr) )
            goto LABEL_82;
          charcount += (int)pu;
          if ( (int)pu < v14 )
            goto LABEL_83;
          if ( bCR != 0 )
          {
            v15 = __pioinfo[fh >> 5];
            mboutbuf[0] = 13;
            if ( !WriteFile(
                    hFile: (HANDLE)v15[v6].osfhnd,
                    lpBuffer: mboutbuf,
                    nNumberOfBytesToWrite: 1u,
                    lpNumberOfBytesWritten: (LPDWORD)&pu,
                    lpOverlapped: nullptr) )
              goto LABEL_82;
            if ( (int)pu < 1 )
              goto LABEL_83;
            ++lfcount;
            ++charcount;
          }
        }
        if ( (unsigned int)v44 >= cnt )
          goto LABEL_83;
        v12 = pch;
      }
    }
  }
  v17 = &__pioinfo[fh >> 5][v6];
  if ( v17->osfile >= 0 )
  {
    if ( WriteFile(
           hFile: (HANDLE)v17->osfhnd,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: (LPDWORD)&written,
           lpOverlapped: nullptr) )
    {
      tmpchar = 0;
      charcount = written;
      goto LABEL_83;
    }
  }
  else
  {
    tmpchar = 0;
    if ( tmode != 0 )
    {
      if ( tmode == 2 )
      {
        pu = (unsigned __int16 *)s;
        while ( 1 )
        {
          v23 = 0;
          v24 = (char *)pu - s;
          v25 = utf8_buf;
          do
          {
            if ( v24 >= cnt )
              break;
            v26 = pu++;
            v27 = *v26;
            v24 += 2;
            if ( v27 == 10 )
            {
              lfcount += 2;
              *(_WORD *)v25 = 13;
              v25 += 2;
              v23 += 2;
            }
            v7 = v39;
            *(_WORD *)v25 = v27;
            v25 += 2;
            v23 += 2;
          }
          while ( v23 < 0x3FF );
          v28 = v25 - utf8_buf;
          if ( !WriteFile(
                  hFile: *(HANDLE *)(v6 * 56 + *v7),
                  lpBuffer: utf8_buf,
                  nNumberOfBytesToWrite: v25 - utf8_buf,
                  lpNumberOfBytesWritten: (LPDWORD)&written,
                  lpOverlapped: nullptr) )
            break;
          charcount += written;
          if ( written < v28 || (char *)pu - s >= cnt )
            goto LABEL_83;
        }
      }
      else
      {
        v44 = s;
        while ( 1 )
        {
          pu = nullptr;
          v29 = v44 - s;
          v30 = utf16_buf;
          do
          {
            if ( v29 >= cnt )
              break;
            v31 = *(_WORD *)v44;
            v44 += 2;
            v29 += 2;
            if ( v31 == 10 )
            {
              *v30++ = 13;
              ++pu;
            }
            ++pu;
            *v30++ = v31;
          }
          while ( (unsigned int)pu < 0x152 );
          v32 = 0;
          v33 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: utf16_buf,
                  cchWideChar: v30 - utf16_buf,
                  lpMultiByteStr: &utf8_buf[340],
                  cbMultiByte: 683,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v33 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)(v6 * 56 + *v39),
                    lpBuffer: &utf8_buf[v32 + 340],
                    nNumberOfBytesToWrite: v33 - v32,
                    lpNumberOfBytesWritten: (LPDWORD)&written,
                    lpOverlapped: nullptr) )
          {
            v32 += written;
            if ( v33 <= v32 )
              goto LABEL_77;
          }
          tmpchar = GetLastError();
LABEL_77:
          if ( v33 <= v32 )
          {
            charcount = v44 - s;
            if ( v44 - s < cnt )
              continue;
          }
          goto LABEL_83;
        }
      }
    }
    else
    {
      pu = (unsigned __int16 *)s;
      while ( 1 )
      {
        v44 = nullptr;
        v18 = (char *)pu - s;
        v19 = utf8_buf;
        do
        {
          if ( v18 >= cnt )
            break;
          v20 = pu;
          pu = (unsigned __int16 *)((char *)pu + 1);
          v21 = *(_BYTE *)v20;
          ++v18;
          if ( v21 == 10 )
          {
            ++lfcount;
            *v19++ = 13;
            ++v44;
          }
          *v19++ = v21;
          ++v44;
        }
        while ( (unsigned int)v44 < 0x400 );
        v22 = v19 - utf8_buf;
        if ( !WriteFile(
                hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                lpBuffer: utf8_buf,
                nNumberOfBytesToWrite: v19 - utf8_buf,
                lpNumberOfBytesWritten: (LPDWORD)&written,
                lpOverlapped: nullptr) )
          break;
        charcount += written;
        if ( written < v22 || (char *)pu - s >= cnt )
          goto LABEL_83;
      }
    }
  }
LABEL_82:
  tmpchar = GetLastError();
LABEL_83:
  if ( charcount == 0 )
  {
    v34 = 0;
    if ( tmpchar != 0 )
    {
      v34 = 5;
      if ( tmpchar != 5 )
      {
        _dosmaperr(oserrno: tmpchar);
        return -1;
      }
      *_errno() = 9;
    }
    else
    {
      if ( (*(_BYTE *)(v6 * 56 + *v39 + 4) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
    }
    *__doserrno() = v34;
    return -1;
  }
  return charcount - lfcount;
}

//------------------------------------------------------------------------------
// Address: 0x004E1E73
// Name: __write
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh, char *buf, DWORD cnt)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 6326944, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _write_nolock(a1, a2: 0, fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x004E1F4F
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)MemAlloc_Alloc(nSize: 0x1000u);
  str->_base = v1;
  if ( v1 != nullptr )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_base = (char *)&str->_charbuf;
    str->_bufsiz = 2;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

//------------------------------------------------------------------------------
// Address: 0x004E1F93
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _isatty@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  else if ( fh >= 0 && fh < _nhandle )
  {
    return __pioinfo[fh >> 5][fh & 0x1F].osfile & 0x40;
  }
  else
  {
    *_errno() = 9;
    _invalid_parameter(a1, a2, a3: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E1FF1
// Name: __wctomb_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wctomb_s_l(
        int *pRetValue,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  char *v5; // esi
  unsigned int v6; // edi
  int result; // eax
  int v8; // esi
  int v9; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v5 = dst;
  v6 = sizeInBytes;
  if ( dst == nullptr && sizeInBytes != 0 )
  {
    if ( pRetValue != nullptr )
      *pRetValue = 0;
    return 0;
  }
  if ( pRetValue != nullptr )
    *pRetValue = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: v6, a3: 0x16u);
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( wchar > 0xFFu )
    {
      if ( v5 != nullptr && v6 != 0 )
        memset(dst: (int)v5, value: nullptr, count: v6);
      goto LABEL_16;
    }
    if ( v5 != nullptr )
    {
      if ( v6 == 0 )
      {
LABEL_21:
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter(a1: 0, a2: v6, a3: 0x22u);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = wchar;
    }
    if ( pRetValue != nullptr )
      *pRetValue = 1;
LABEL_26:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  dst = nullptr;
  v9 = WideCharToMultiByte(
         CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
         dwFlags: 0,
         lpWideCharStr: &wchar,
         cchWideChar: 1,
         lpMultiByteStr: v5,
         cbMultiByte: v6,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: (LPBOOL)&dst);
  if ( v9 != 0 )
  {
    if ( dst == nullptr )
    {
      if ( pRetValue != nullptr )
        *pRetValue = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 != nullptr && v6 != 0 )
      memset(dst: (int)v5, value: nullptr, count: v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno() = 42;
  result = *_errno();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E2150
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_s(int *pRetValue, char *dst, unsigned int sizeInBytes, wchar_t wchar)
{
  return _wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004E216B
// Name: __ld12tod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  unsigned int v55; // ebx
  int v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  int v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  int v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(_DWORD *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = nullptr;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = DoubleFormat.precision - 1;
    v64 = v3;
    v65 = DoubleFormat.precision / 32;
    v9 = &v60 + DoubleFormat.precision / 32;
    v66 = 31 - DoubleFormat.precision % 32;
    if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a != nullptr )
      ++v3;
    if ( v3 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v3 > DoubleFormat.min_exp )
      {
        if ( v3 < DoubleFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = DoubleFormat.bias + v3;
          v50 = DoubleFormat.exp_width / 32;
          v51 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12g = nullptr;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = DoubleFormat.exp_width / 32;
          v44 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12f = nullptr;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = DoubleFormat.bias + DoubleFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (DoubleFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (DoubleFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = nullptr;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = DoubleFormat.precision - 1;
      v25 = DoubleFormat.precision / 32;
      v65 = DoubleFormat.precision / 32;
      v26 = &v60 + DoubleFormat.precision / 32;
      v64 = 31 - DoubleFormat.precision % 32;
      if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (DoubleFormat.exp_width + 1) / 32;
      v37 = (DoubleFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = nullptr;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  v55 = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v56 = v61;
    HIDWORD(d->x) = v55;
    LODWORD(d->x) = v56;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E26AD
// Name: __ld12tof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tof(_LDBL12 *pld12, _CRT_FLOAT *f)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  float v55; // ebx
  float v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  float v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  float v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(float *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = nullptr;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = FloatFormat.precision - 1;
    v64 = v3;
    v65 = FloatFormat.precision / 32;
    v9 = &v60 + FloatFormat.precision / 32;
    v66 = 31 - FloatFormat.precision % 32;
    if ( ((1 << (31 - FloatFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a != nullptr )
      ++v3;
    if ( v3 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v3 > FloatFormat.min_exp )
      {
        if ( v3 < FloatFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = FloatFormat.bias + v3;
          v50 = FloatFormat.exp_width / 32;
          v51 = FloatFormat.exp_width % 32;
          v65 = 0;
          pld12g = nullptr;
          v67 = 32 - FloatFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0.0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = FloatFormat.exp_width / 32;
          v44 = FloatFormat.exp_width % 32;
          v65 = 0;
          pld12f = nullptr;
          v67 = 32 - FloatFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = FloatFormat.bias + FloatFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (FloatFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (FloatFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = nullptr;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = FloatFormat.precision - 1;
      v25 = FloatFormat.precision / 32;
      v65 = FloatFormat.precision / 32;
      v26 = &v60 + FloatFormat.precision / 32;
      v64 = 31 - FloatFormat.precision % 32;
      if ( ((1 << (31 - FloatFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (FloatFormat.exp_width + 1) / 32;
      v37 = (FloatFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = nullptr;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0.0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0.0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  LODWORD(v55) = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v56 = v61;
    f[1].f = v55;
    f->f = v56;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E2BEF
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // edi
  int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  int v10; // esi
  unsigned int v11; // ecx
  unsigned int v12; // edi
  int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // esi
  int v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // edi
  int v20; // ecx
  __int16 expn; // [esp+Ch] [ebp-18h]
  int v22; // [esp+10h] [ebp-14h]
  int v23; // [esp+10h] [ebp-14h]
  unsigned int tmp_4; // [esp+18h] [ebp-Ch]
  int tmp_8; // [esp+1Ch] [ebp-8h]

  expn = 16462;
  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  for ( *(_DWORD *)&ld12->ld12[8] = 0; manlen != 0; ++manptr )
  {
    tmp_4 = *(_DWORD *)&ld12->ld12[4];
    tmp_8 = *(_DWORD *)&ld12->ld12[8];
    v22 = 0;
    v3 = __SPAIR64__(*(_QWORD *)&ld12->ld12[4] >> 31, *(__int64 *)ld12->ld12 >> 31) >> 31;
    v4 = *(_DWORD *)ld12->ld12;
    v5 = (2LL * *(_QWORD *)ld12->ld12) >> 31;
    v6 = 5 * *(_DWORD *)ld12->ld12;
    *(_DWORD *)ld12->ld12 *= 4;
    *(_DWORD *)&ld12->ld12[4] = v5;
    *(_DWORD *)&ld12->ld12[8] = v3;
    if ( 5 * v4 < 4 * v4 || v6 < v4 )
      v22 = 1;
    v7 = 0;
    *(_DWORD *)ld12->ld12 = v6;
    if ( v22 != 0 )
    {
      if ( v5 + 1 < v5 || v5 == -1 )
        v7 = 1;
      *(_DWORD *)&ld12->ld12[4] = v5 + 1;
      if ( v7 != 0 )
        *(_DWORD *)&ld12->ld12[8] = v3 + 1;
    }
    v8 = *(_DWORD *)&ld12->ld12[4];
    v9 = v8 + tmp_4;
    v10 = 0;
    if ( v8 + tmp_4 < v8 || v9 < tmp_4 )
      v10 = 1;
    *(_DWORD *)&ld12->ld12[4] = v9;
    if ( v10 != 0 )
      ++*(_DWORD *)&ld12->ld12[8];
    *(_DWORD *)&ld12->ld12[8] += tmp_8;
    v23 = 0;
    v11 = 2 * v6;
    v12 = (v6 >> 31) | (2 * v9);
    v13 = (v9 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
    *(_DWORD *)ld12->ld12 = v11;
    *(_DWORD *)&ld12->ld12[4] = v12;
    *(_DWORD *)&ld12->ld12[8] = v13;
    v14 = *manptr;
    v15 = v11 + v14;
    if ( v11 + v14 < v11 || v15 < v14 )
      v23 = 1;
    *(_DWORD *)ld12->ld12 = v15;
    if ( v23 != 0 )
    {
      v16 = 0;
      if ( v12 + 1 < v12 || v12 == -1 )
        v16 = 1;
      *(_DWORD *)&ld12->ld12[4] = v12 + 1;
      if ( v16 != 0 )
        *(_DWORD *)&ld12->ld12[8] = v13 + 1;
    }
    --manlen;
  }
  while ( *(_DWORD *)&ld12->ld12[8] == 0 )
  {
    v17 = *(_DWORD *)&ld12->ld12[4];
    *(_DWORD *)&ld12->ld12[8] = HIWORD(v17);
    expn -= 16;
    *(_QWORD *)ld12->ld12 = __PAIR64__(v17, *(_DWORD *)ld12->ld12) << 16;
  }
  if ( (*(_DWORD *)&ld12->ld12[8] & 0x8000) == 0 )
  {
    do
    {
      v18 = *(_DWORD *)ld12->ld12;
      v19 = *(_DWORD *)&ld12->ld12[4];
      --expn;
      *(_DWORD *)ld12->ld12 *= 2;
      v20 = (v19 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
      *(_DWORD *)&ld12->ld12[4] = (v18 >> 31) | (2 * v19);
      *(_DWORD *)&ld12->ld12[8] = v20;
    }
    while ( (v20 & 0x8000) == 0 );
  }
  *(_WORD *)&ld12->ld12[10] = expn;
}

//------------------------------------------------------------------------------
// Address: 0x004E2DBB
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  int v1; // esi
  void **v2; // eax
  _iobuf *v3; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    v1 = i;
    v2 = &__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = (_iobuf *)*v2;
      if ( (v3->_flag & 0x83) != 0 && fclose(stream: v3) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[v1] + 32));
        free(pMem: __piob[v1]);
        __piob[v1] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x004E2E60
// Name: __CIsin_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004E3028
// Name: has_osfxsr_set
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl has_osfxsr_set()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3078
// Name: __get_sse2_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _get_sse2_info()
{
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4
  int cpu_feature; // [esp+18h] [ebp-4h]

  cpu_feature = 0;
  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
  if ( v1 != v0 )
  {
    __writeeflags(v0);
    _EAX = 0;
    __asm { cpuid }
    _EAX = 1;
    __asm { cpuid }
    cpu_feature = _EDX;
  }
  return (cpu_feature & 0x4000000) != 0 && has_osfxsr_set() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E30D8
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __sse2_available_init()
{
  __sse2_available = _get_sse2_info();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E30E5
// Name: public: void HeapManager::Destructor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall HeapManager::Destructor(HeapManager *this)
{
  HeapManager::Block *head; // eax
  HeapManager::Block *tail; // [esp-4h] [ebp-8h]

  if ( this->pOpDelete != nullptr )
  {
    while ( 1 )
    {
      head = this->head;
      this->tail = head;
      if ( head == nullptr )
        break;
      tail = this->tail;
      this->head = tail->next;
      this->pOpDelete(a1: tail);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E310B
// Name: private: static int UnDecorator::getNumberOfDimensions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl UnDecorator::getNumberOfDimensions()
{
  const char *v0; // ecx
  char v1; // dl
  int result; // eax
  char v3; // dl

  v0 = UnDecorator::gName;
  v1 = *UnDecorator::gName;
  if ( *UnDecorator::gName == 0 )
    return 0;
  if ( v1 < 48 || v1 > 57 )
  {
    result = 0;
    while ( v1 != 64 )
    {
      if ( v1 == 0 )
        return 0;
      if ( v1 < 65 || v1 > 80 )
        return -1;
      ++v0;
      result = 16 * result + v1 - 65;
      UnDecorator::gName = v0;
      v1 = *v0;
    }
    v3 = *v0;
    UnDecorator::gName = v0 + 1;
    if ( v3 == 64 )
      return result;
    return -1;
  }
  else
  {
    ++UnDecorator::gName;
    return v1 - 47;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E316E
// Name: private: static int UnDecorator::getTypeEncoding(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl UnDecorator::getTypeEncoding()
{
  const char *v0; // ecx
  int result; // eax
  char v2; // dl
  char v3; // bl
  const char *v4; // ecx
  int v5; // edx
  int v6; // edx
  int v7; // eax
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  char v13; // al
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // eax
  char v18; // dl
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // edx
  int v23; // edx
  char v24; // dl
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax

  v0 = UnDecorator::gName;
  while ( 2 )
  {
    result = 0;
    if ( *v0 == 95 )
    {
      ++v0;
      result = 0x4000;
      UnDecorator::gName = v0;
    }
    v2 = *v0;
    if ( *v0 >= 65 && v2 <= 90 )
    {
      v6 = *v0 - 65;
      v7 = result | 0x8000;
      UnDecorator::gName = v0 + 1;
      if ( (v6 & 1) != 0 )
        result = v7 | 0x2000;
      else
        result = v7 & 0xFFFFDFFF;
      if ( v6 < 24 )
      {
        if ( (result & 0x8000) != 0 )
          v8 = result & 0xFFFFE7FF | 0x800;
        else
          v8 = result & 0xFFFF9FFF;
        v9 = v6 & 0x18;
        if ( (v6 & 0x18) != 0 )
        {
          if ( v9 == 8 )
          {
            if ( (v8 & 0x8000) != 0 )
              result = v8 & 0xFFFFFF3F | 0x80;
            else
              result = v8 & 0xFFFFE7FF | 0x1000;
          }
          else
          {
            if ( v9 != 16 )
              return 0xFFFF;
            if ( (v8 & 0x8000) != 0 )
              result = v8 & 0xFFFFFF3F;
            else
              result = v8 & 0xFFFFE7FF;
          }
        }
        else if ( (v8 & 0x8000) != 0 )
        {
          result = v8 & 0xFFFFFF3F | 0x40;
        }
        else
        {
          result = v8 & 0xFFFFE7FF | 0x800;
        }
        v10 = v6 & 6;
        if ( v10 == 0 )
          return result;
        v11 = v10 - 2;
        if ( v11 != 0 )
        {
          v12 = v11 - 2;
          if ( v12 == 0 )
            return result & 0xFFFFF8FF | 0x100;
          if ( v12 == 2 )
            return result & 0xFFFFF8FF | 0x400;
          return 0xFFFF;
        }
        if ( (result & 0x8000) != 0 )
          return result & 0xFFFFF8FF | 0x200;
        else
          return result & 0xFFFF9FFF;
      }
    }
    else
    {
      if ( v2 == 36 )
      {
        v3 = 0;
        v4 = v0 + 1;
        UnDecorator::gName = v4;
        v5 = *v4;
        if ( v5 > 66 )
        {
          v14 = v5 - 67;
          if ( v14 == 0 )
          {
            result |= 0x7C00u;
            goto LABEL_83;
          }
          v15 = v14 - 1;
          if ( v15 == 0 )
          {
            result = result & 0xFFFF64FF | 0x9100;
            goto LABEL_83;
          }
          v16 = v15 - 1;
          if ( v16 == 0 )
          {
            result = result & 0xFFFF64FF | 0x9200;
            goto LABEL_83;
          }
          if ( v16 != 13 )
            return 0xFFFF;
          UnDecorator::gName = ++v4;
          v3 = 1;
        }
        else
        {
          if ( v5 == 66 )
          {
            result |= 0x9800u;
            goto LABEL_83;
          }
          if ( *v4 == 0 )
          {
            result = 65534;
            goto LABEL_83;
          }
          if ( v5 == 36 )
          {
            if ( v4[1] == 80 )
              ++v4;
            UnDecorator::gName = ++v4;
            switch ( *v4 )
            {
              case 'F':
              case 'H':
              case 'L':
              case 'M':
              case 'Q':
                v0 = v4 + 1;
                UnDecorator::gName = v0;
                continue;
              case 'J':
              case 'N':
              case 'O':
                UnDecorator::gName = ++v4;
                v13 = *v4;
                if ( *v4 >= 48 && v13 <= 57 )
                {
                  UnDecorator::gName = &v4[v13 - 47];
                  return UnDecorator::getTypeEncoding() | 0x10000;
                }
                result = 0xFFFF;
                break;
              default:
                goto LABEL_83;
            }
            goto LABEL_83;
          }
          if ( v5 <= 47 )
            return 0xFFFF;
          if ( v5 > 53 )
          {
            if ( v5 == 65 )
            {
              result = result & 0xFFFF64FF | 0x9000;
LABEL_83:
              UnDecorator::gName = v4 + 1;
              return result;
            }
            return 0xFFFF;
          }
        }
        v17 = result | 0x8000;
        v18 = *v4 - 48;
        if ( (v17 & 0x8000) != 0 )
          v19 = v17 & 0xFFFFE7FF | 0x800;
        else
          v19 = v17 & 0xFFFF9FFF;
        if ( v3 != 0 )
          v20 = v19 & 0xFFFFF8FF | 0x600;
        else
          v20 = v19 & 0xFFFFF8FF | 0x500;
        if ( (v18 & 1) != 0 )
          v21 = v20 | 0x2000;
        else
          v21 = v20 & 0xFFFFDFFF;
        v22 = v18 & 6;
        if ( v22 == 0 )
        {
          if ( (v21 & 0x8000) != 0 )
            result = v21 & 0xFFFFFF3F | 0x40;
          else
            result = v21 & 0xFFFFE7FF | 0x800;
          goto LABEL_83;
        }
        v23 = v22 - 2;
        if ( v23 == 0 )
        {
          if ( (v21 & 0x8000) != 0 )
            result = v21 & 0xFFFFFF3F | 0x80;
          else
            result = v21 & 0xFFFFE7FF | 0x1000;
          goto LABEL_83;
        }
        if ( v23 == 2 )
        {
          if ( (v21 & 0x8000) != 0 )
            result = v21 & 0xFFFFFF3F;
          else
            result = v21 & 0xFFFFE7FF;
          goto LABEL_83;
        }
        return 0xFFFF;
      }
      v24 = *v0;
      if ( *v0 < 48 || v24 > 56 )
      {
        if ( v24 == 57 )
        {
          UnDecorator::gName = v0 + 1;
          return 65533;
        }
        else
        {
          return (v24 != 0) + 65534;
        }
      }
      else
      {
        UnDecorator::gName = v0 + 1;
        v25 = result & 0xFFFF7FFF;
        switch ( v24 )
        {
          case '0':
            if ( (v25 & 0x8000) != 0 )
              v26 = v25 & 0xFFFFF8FF | 0x200;
            else
              v26 = v25 & 0xFFFF9FFF;
            if ( (v26 & 0x8000) != 0 )
              result = v26 & 0xFFFFFF3F | 0x40;
            else
              result = v26 & 0xFFFFE7FF | 0x800;
            break;
          case '1':
            if ( (v25 & 0x8000) != 0 )
              v27 = v25 & 0xFFFFF8FF | 0x200;
            else
              v27 = v25 & 0xFFFF9FFF;
            if ( (v27 & 0x8000) != 0 )
              result = v27 & 0xFFFFFF3F | 0x80;
            else
              result = v27 & 0xFFFFE7FF | 0x1000;
            break;
          case '2':
            if ( (v25 & 0x8000) != 0 )
              v28 = v25 & 0xFFFFF8FF | 0x200;
            else
              v28 = v25 & 0xFFFF9FFF;
            if ( (v28 & 0x8000) != 0 )
              result = v28 & 0xFFFFFF3F;
            else
              result = v28 & 0xFFFFE7FF;
            break;
          case '3':
            result = v25 & 0xFFFF9FFF | 0x4000;
            break;
          case '4':
            result = v25 & 0xFFFF9FFF | 0x2000;
            break;
          case '5':
            result = v25 & 0xFFFF83FF | 0x6000;
            break;
          case '6':
            result = v25 & 0xFFFF83FF | 0x6800;
            break;
          case '7':
            result = v25 & 0xFFFF83FF | 0x7000;
            break;
          case '8':
            result = v25 & 0xFFFF83FF | 0x7800;
            break;
          default:
            return 0xFFFF;
        }
      }
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E35E2
// Name: public: static char const __near * UnDecorator::UScore(enum Tokens)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl UnDecorator::UScore(Tokens tok)
{
  const char *result; // eax

  result = tokenTable[tok];
  if ( (UnDecorator::disableFlags & 1) != 0 )
    result += 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E35FB
// Name: public: void __near * HeapManager::getMemory(unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall HeapManager::getMemory(HeapManager *this, unsigned int sz, int noBuffer)
{
  unsigned int v3; // edi
  unsigned int blockLeft; // eax
  HeapManager::Block *Memory; // eax
  HeapManager::Block *tail; // ecx

  v3 = (sz + 7) & 0xFFFFFFF8;
  if ( noBuffer != 0 )
    return (char *)this->pOpNew(a1: (sz + 7) & 0xFFFFFFF8);
  if ( v3 == 0 )
    v3 = 8;
  blockLeft = this->blockLeft;
  if ( blockLeft >= v3 )
  {
    this->blockLeft = blockLeft - v3;
  }
  else
  {
    if ( v3 > 0x1000 )
      return nullptr;
    Memory = (HeapManager::Block *)HeapManager::getMemory(this: &heap, sz: 0x1004u, noBuffer: 1);
    if ( Memory != nullptr )
      Memory->next = nullptr;
    else
      Memory = nullptr;
    if ( Memory == nullptr )
      return nullptr;
    tail = this->tail;
    if ( tail != nullptr )
      tail->next = Memory;
    else
      this->head = Memory;
    this->tail = Memory;
    this->blockLeft = 4096 - v3;
  }
  return &this->tail->memBlock[this->blockLeft];
}

//------------------------------------------------------------------------------
// Address: 0x004E367F
// Name: public: DName::DName(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, const DName *rd)
{
  DName *result; // eax
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // esi

  result = this;
  *((_DWORD *)this + 1) ^= (*((_DWORD *)this + 1) ^ ((int)(*((_DWORD *)rd + 1) << 28) >> 28)) & 0xF;
  v3 = *((_DWORD *)result + 1)
     ^ ((unsigned __int8)*((_DWORD *)result + 1)
      ^ (unsigned __int8)*((_DWORD *)rd + 1))
     & 0x10;
  *((_DWORD *)this + 1) = v3;
  v4 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x20;
  *((_DWORD *)this + 1) = v4;
  v5 = v4 ^ ((unsigned __int8)v4 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x40;
  *((_DWORD *)this + 1) = v5;
  v6 = v5 ^ ((unsigned __int8)v5 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x80;
  *((_DWORD *)this + 1) = v6;
  this->node = rd->node;
  *((_DWORD *)this + 1) ^= (*((_DWORD *)rd + 1) ^ v6) & 0x100;
  v7 = *((_DWORD *)result + 1)
     ^ ((unsigned __int16)*((_DWORD *)result + 1)
      ^ (unsigned __int16)*((_DWORD *)rd + 1))
     & 0x200;
  *((_DWORD *)this + 1) = v7;
  v8 = v7 ^ ((unsigned __int16)v7 ^ (unsigned __int16)*((_DWORD *)rd + 1)) & 0x400;
  *((_DWORD *)this + 1) = v8;
  *((_DWORD *)this + 1) = v8 ^ ((unsigned __int16)v8 ^ (unsigned __int16)*((_DWORD *)rd + 1)) & 0x800;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E371B
// Name: public: class DName __near & DName::operator=(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator=(DName *this, const DName *rd)
{
  DName *result; // eax
  int v3; // esi
  int v4; // ecx
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // esi
  int v9; // edx

  result = this;
  v3 = *((_DWORD *)this + 1);
  v4 = v3 << 28 >> 28;
  if ( v4 == 0 || v4 == 2 )
  {
    v5 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)((int)(*((_DWORD *)rd + 1) << 28) >> 28)) & 0xF;
    *((_DWORD *)result + 1) = v5;
    v6 = v5 ^ ((unsigned __int8)v5 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x10;
    *((_DWORD *)result + 1) = v6;
    v7 = v6 ^ ((unsigned __int8)v6 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x20;
    *((_DWORD *)result + 1) = v7;
    v8 = v7 ^ ((unsigned __int8)v7 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x40;
    *((_DWORD *)result + 1) = v8;
    v9 = v8 ^ ((unsigned __int8)v8 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x80;
    *((_DWORD *)result + 1) = v9;
    *((_DWORD *)result + 1) = v9 ^ ((unsigned __int16)v9 ^ (unsigned __int16)*((_DWORD *)rd + 1)) & 0x800;
    result->node = rd->node;
  }
  return result;
}
