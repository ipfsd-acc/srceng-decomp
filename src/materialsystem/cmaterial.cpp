// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmaterial.cpp
// Functions: 146
// ============================================================

#include "materialsystem\cmaterial.h"

//------------------------------------------------------------------------------
// Address: 0x10019010
// Name: public: static void CMaterial::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMaterial::operator delete(void *p)
{
  CUtlMemoryPool::Free(this: &CMaterial::s_Allocator, memBlock: p);
}

//------------------------------------------------------------------------------
// Address: 0x10019030
// Name: public: static void IMaterialInternal::DestroyMaterial(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IMaterialInternal::DestroyMaterial(IMaterialInternal *pMaterial)
{
  MaterialLock_t__ *v1; // esi

  v1 = g_pInternalMaterialSystem->Lock(this: g_pInternalMaterialSystem);
  if ( pMaterial != nullptr )
    ((void (__thiscall *)(IMaterialInternal *, int))pMaterial->__vftable[1].GetName)(a1: pMaterial, a2: 1);
  g_pInternalMaterialSystem->Unlock(this: g_pInternalMaterialSystem, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10019070
// Name: public: virtual void CMaterial::ClearContextData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ClearContextData(CMaterial *this)
{
  char v1; // al
  int v2; // eax
  RenderPassList_t *v3; // edi
  int v4; // ebx
  CBasePerMaterialContextData **m_pContextData; // esi
  int i; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  v1 = g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem);
  if ( (v1 & 2) != 0 )
    v2 = 64;
  else
    v2 = 8 * ((v1 & 1) != 0) + 8;
  if ( v2 > 0 )
  {
    v8 = 0;
    for ( i = v2; i != 0; --i )
    {
      v3 = &this->m_ShaderRenderState.m_pSnapshots[v8];
      v4 = 0;
      if ( v3->m_nPassCount > 0 )
      {
        m_pContextData = v3->m_pContextData;
        do
        {
          if ( *m_pContextData != nullptr )
          {
            ((void (__thiscall *)(CBasePerMaterialContextData *, int))(*m_pContextData)->dtr_CBasePerMaterialContextData)(
              a1: *m_pContextData,
              a2: 1);
            *m_pContextData = nullptr;
          }
          ++v4;
          ++m_pContextData;
        }
        while ( v4 < v3->m_nPassCount );
      }
      ++v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019100
// Name: private: struct RenderPassList_t __near * CMaterial::CreateRenderPassList(void)
// Source: json
//------------------------------------------------------------------------------
RenderPassList_t *__thiscall CMaterial::CreateRenderPassList(CMaterial *this)
{
  unsigned __int8 *v1; // eax
  unsigned __int8 *v2; // esi
  char v3; // al
  int v4; // eax

  if ( (g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem) & 3) != 0 )
    v1 = (unsigned __int8 *)CUtlMemoryPool::Alloc(this: &EditorRenderStateList_t::s_Allocator, amount: 0x900u);
  else
    v1 = (unsigned __int8 *)CUtlMemoryPool::Alloc(this: &StandardRenderStateList_t::s_Allocator, amount: 0x120u);
  v2 = v1;
  v3 = g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem);
  if ( (v3 & 2) != 0 )
    v4 = 64;
  else
    v4 = 8 * ((v3 & 1) != 0) + 8;
  memset(dst: v2, value: 0, count: 36 * v4);
  return (RenderPassList_t *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10019180
// Name: private: void CMaterial::DestroyRenderPassList(struct RenderPassList_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::DestroyRenderPassList(CMaterial *this, RenderPassList_t *pPassList)
{
  RenderPassList_t *v2; // esi
  char v3; // al
  int v4; // eax
  RenderPassList_t *v5; // ebx
  int v6; // edi
  CBasePerInstanceContextData **m_pInstanceData; // esi
  void (__thiscall ***v8)(_DWORD, int); // ecx
  char v9; // al
  CUtlMemoryPool *v10; // ecx
  int i; // [esp+4h] [ebp-4h]

  v2 = pPassList;
  if ( pPassList != nullptr )
  {
    v3 = g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem);
    if ( (v3 & 2) != 0 )
      v4 = 64;
    else
      v4 = 8 * ((v3 & 1) != 0) + 8;
    if ( v4 > 0 )
    {
      v5 = pPassList;
      for ( i = v4; i != 0; --i )
      {
        v6 = 0;
        if ( v5->m_nPassCount > 0 )
        {
          m_pInstanceData = v5->m_pInstanceData;
          do
          {
            v8 = (void (__thiscall ***)(_DWORD, int))*(m_pInstanceData - 3);
            if ( v8 != nullptr )
            {
              (**v8)(a1: v8, a2: 1);
              *(m_pInstanceData - 3) = nullptr;
            }
            if ( *m_pInstanceData != nullptr )
            {
              ((void (__thiscall *)(CBasePerInstanceContextData *, int))(*m_pInstanceData)->dtr_CBasePerInstanceContextData)(
                a1: *m_pInstanceData,
                a2: 1);
              *m_pInstanceData = nullptr;
            }
            ++v6;
            ++m_pInstanceData;
          }
          while ( v6 < v5->m_nPassCount );
          v2 = pPassList;
        }
        ++v5;
      }
    }
    v9 = g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem);
    v10 = &StandardRenderStateList_t::s_Allocator;
    if ( (v9 & 3) != 0 )
      v10 = &EditorRenderStateList_t::s_Allocator;
    CUtlMemoryPool::Free(this: v10, memBlock: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019240
// Name: private: void CMaterial::CleanUpShaderParams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::CleanUpShaderParams(CMaterial *this)
{
  int v2; // edi

  if ( this->m_pShaderParams != nullptr )
  {
    v2 = 0;
    if ( this->m_VarCount != 0 )
    {
      do
        IMaterialVar::Destroy(pVar: this->m_pShaderParams[v2++]);
      while ( v2 < this->m_VarCount );
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pShaderParams);
    this->m_pShaderParams = nullptr;
  }
  this->m_VarCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019290
// Name: private: void CMaterial::InitializeMaterialProxy(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::InitializeMaterialProxy(CMaterial *this, KeyValues *pFallbackKeyValues)
{
  IMaterialProxyFactory *v3; // edi
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  IMaterialProxy *v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  IMaterialInternal *(__thiscall *GetQueueFriendlyVersion)(struct CMaterial *); // eax
  int v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  IMaterialProxy **v15; // eax
  const char *v16; // [esp-8h] [ebp-418h]
  const char *v17; // [esp-8h] [ebp-418h]
  int v18; // [esp-8h] [ebp-418h]
  IMaterialProxy *ppProxies[256]; // [esp+8h] [ebp-408h] BYREF
  IMaterialProxyFactory *pMaterialProxyFactory; // [esp+408h] [ebp-8h]
  int (__thiscall **v21)(IMaterialProxyFactory *, const char *); // [esp+40Ch] [ebp-4h]
  unsigned int proxyCount; // [esp+418h] [ebp+8h]

  v3 = g_pInternalMaterialSystem->GetMaterialProxyFactory(this: g_pInternalMaterialSystem);
  pMaterialProxyFactory = v3;
  if ( v3 != nullptr )
  {
    Key = KeyValues::FindKey(this: pFallbackKeyValues, keyName: "Proxies", bCreate: false);
    if ( Key != nullptr )
    {
      proxyCount = 0;
      FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          v21 = (int (__thiscall **)(IMaterialProxyFactory *, const char *))v3->__vftable;
          Name = KeyValues::GetName(this: FirstSubKey);
          v7 = (IMaterialProxy *)(*v21)(a1: v3, a2: Name);
          if ( v7 != nullptr )
          {
            GetQueueFriendlyVersion = this->GetQueueFriendlyVersion;
            v21 = (int (__thiscall **)(IMaterialProxyFactory *, const char *))v7->__vftable;
            v11 = ((int (__thiscall *)(CMaterial *, KeyValues *))GetQueueFriendlyVersion)(a1: this, a2: FirstSubKey);
            if ( (unsigned __int8)(*v21)(a1: (IMaterialProxyFactory *)v7, a2: (const char *)v11) != 0 )
            {
              ppProxies[proxyCount++] = v7;
              if ( proxyCount >= 0x100 )
              {
                v14 = (const char *)((int (__thiscall *)(CMaterial *, int))this->GetName)(a1: this, a2: 256);
                _Warning(a1: "Error: Material \"%s\" has more than %d proxies!\n", v14, v18);
                break;
              }
            }
            else
            {
              pMaterialProxyFactory->DeleteProxy(this: pMaterialProxyFactory, a2: v7);
              v12 = KeyValues::GetName(this: FirstSubKey);
              v13 = (const char *)((int (__thiscall *)(CMaterial *, const char *))this->GetName)(a1: this, a2: v12);
              _Warning(a1: "Error: Material \"%s\" : proxy \"%s\" unable to initialize!\n", v13, v17);
            }
          }
          else
          {
            v8 = KeyValues::GetName(this: FirstSubKey);
            v9 = (const char *)((int (__thiscall *)(CMaterial *, const char *))this->GetName)(a1: this, a2: v8);
            _Warning(a1: "Error: Material \"%s\" : proxy \"%s\" not found!\n", v9, v16);
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          if ( FirstSubKey == nullptr )
            break;
          v3 = pMaterialProxyFactory;
        }
      }
      this->m_ProxyCount = proxyCount;
      if ( proxyCount != 0 )
      {
        v15 = (IMaterialProxy **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * proxyCount);
        this->m_ppProxies = v15;
        memcpy(dst: (unsigned __int8 *)v15, src: (unsigned __int8 *)ppProxies, count: 4 * proxyCount);
      }
      else
      {
        this->m_ppProxies = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019410
// Name: private: void CMaterial::CleanUpMaterialProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::CleanUpMaterialProxy(CMaterial *this)
{
  IMaterialProxyFactory *v2; // ebx
  int v3; // esi

  if ( this->m_ProxyCount != 0 )
  {
    v2 = g_pInternalMaterialSystem->GetMaterialProxyFactory(this: g_pInternalMaterialSystem);
    if ( v2 != nullptr )
    {
      v3 = this->m_ProxyCount - 1;
      if ( this->m_ProxyCount != 0 )
      {
        do
          v2->DeleteProxy(this: v2, a2: this->m_ppProxies[v3--]);
        while ( v3 >= 0 );
      }
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ppProxies);
      this->m_ppProxies = nullptr;
      this->m_ProxyCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019470
// Name: FindMaterialVar
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindMaterialVar(IShader *pShader, char *pVarName)
{
  IShader *v2; // esi
  int v3; // eax
  const char *v4; // ebx
  int v5; // eax
  const char *m_pName; // edi
  const char *v8; // esi
  const char *j; // esi
  char v10; // al
  int i; // [esp+18h] [ebp+Ch]

  strspn(string: (unsigned __int8 *)pVarName, control: " \t");
  v2 = pShader;
  v4 = &pVarName[v3];
  v5 = pShader->GetParamCount(this: pShader) - 1;
  i = v5;
  if ( v5 < 0 )
    return -1;
  while ( 1 )
  {
    m_pName = v2->GetParamInfo(this: v2, a2: v5)->m_pName;
    v8 = V_stristr(pStr: v4, pSearch: m_pName);
    if ( v8 == v4 )
      break;
LABEL_10:
    if ( --i < 0 )
      return -1;
    v5 = i;
    v2 = pShader;
  }
  for ( j = &v8[_V_strlen(str: m_pName)]; ; ++j )
  {
    v10 = *j;
    if ( *j == 0 )
      break;
    if ( v10 != 32 && v10 != 9 )
      goto LABEL_10;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10019950
// Name: private: int CMaterial::FindMaterialVarFlag(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::FindMaterialVarFlag(CMaterial *this, const char *pFlagName)
{
  const char *v2; // esi
  char v3; // al
  int v4; // ebx
  const char *v6; // edi
  const char *v7; // esi
  const char *i; // esi
  char v9; // al

  v2 = pFlagName;
  v3 = *pFlagName;
  if ( *pFlagName != 0 )
  {
    do
    {
      if ( v3 != 32 && v3 != 9 )
        break;
      v3 = *++v2;
    }
    while ( v3 != 0 );
    pFlagName = v2;
  }
  v4 = 0;
  if ( *g_pShaderSystem->ShaderStateString(this: g_pShaderSystem, a2: 0) == 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pShaderSystem->ShaderStateString(this: g_pShaderSystem, a2: v4);
    v7 = V_stristr(pStr: v2, pSearch: v6);
    if ( v7 == pFlagName )
      break;
LABEL_15:
    if ( *g_pShaderSystem->ShaderStateString(this: g_pShaderSystem, a2: ++v4) == 0 )
      return 0;
    v2 = pFlagName;
  }
  for ( i = &v7[_V_strlen(str: v6)]; ; ++i )
  {
    v9 = *i;
    if ( *i == 0 )
      break;
    if ( v9 != 32 && v9 != 9 )
      goto LABEL_15;
  }
  return 1 << v4;
}

//------------------------------------------------------------------------------
// Address: 0x10019A00
// Name: private: bool CMaterial::ParseMaterialFlag(class KeyValues __near *,class IMaterialVar __near *,class IMaterialVar __near *,bool,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CMaterial::ParseMaterialFlag@<al>(
        CMaterial *this@<ecx>,
        int a2@<ebx>,
        KeyValues *pParseValue,
        IMaterialVar *pFlagVar,
        IMaterialVar *pFlagDefinedVar,
        bool parsingOverrides,
        int *flagMask,
        int *overrideMask)
{
  unsigned __int8 *Name; // esi
  int v10; // eax
  int MaterialVarFlag; // esi
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  const char *v18; // [esp-8h] [ebp-10h]

  Name = (unsigned __int8 *)KeyValues::GetName(this: pParseValue);
  strchr(string: Name, chr: 0x3Fu);
  if ( v10 != 0 )
    Name = (unsigned __int8 *)(v10 + 1);
  MaterialVarFlag = CMaterial::FindMaterialVarFlag(this, pFlagName: (const char *)Name);
  if ( MaterialVarFlag == 0 )
    return 0;
  if ( parsingOverrides )
    v13 = *overrideMask;
  else
    v13 = *flagMask;
  if ( (v13 & MaterialVarFlag) != 0 )
  {
    v18 = (const char *)this->GetName(this);
    v14 = KeyValues::GetName(this: pParseValue);
    _Warning(a1: "Error! Flag \"%s\" is multiply defined in material \"%s\"!\n", v14, v18);
    return 1;
  }
  else
  {
    if ( (*overrideMask & MaterialVarFlag) == 0 )
    {
      if ( parsingOverrides )
        *overrideMask |= MaterialVarFlag;
      else
        *flagMask |= MaterialVarFlag;
      if ( KeyValues::GetInt(this: pParseValue, keyName: nullptr, defaultValue: 0) != 0 )
      {
        v15 = ((int (__thiscall *)(IMaterialVar *, int))pFlagVar->GetIntValueInternal)(a1: pFlagVar, a2);
        pFlagVar->SetIntValue(this: pFlagVar, a2: MaterialVarFlag | v15);
      }
      else
      {
        v16 = ((int (__thiscall *)(IMaterialVar *, int))pFlagVar->GetIntValueInternal)(a1: pFlagVar, a2);
        pFlagVar->SetIntValue(this: pFlagVar, a2: v16 & ~MaterialVarFlag);
      }
      v17 = pFlagDefinedVar->GetIntValueInternal(this: pFlagDefinedVar);
      pFlagDefinedVar->SetIntValue(this: pFlagDefinedVar, a2: MaterialVarFlag | v17);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019AF0
// Name: CheckConditionalFakeShaderName
// Source: json
//------------------------------------------------------------------------------
KeyValues *__usercall CheckConditionalFakeShaderName@<eax>(
        const char *pSuffixName@<edi>,
        KeyValues *pKeyValues@<esi>,
        const char *pShaderName)
{
  KeyValues *result; // eax
  char nameBuf[256]; // [esp+0h] [ebp-100h] BYREF

  result = KeyValues::FindKey(this: pKeyValues, keyName: pSuffixName, bCreate: false);
  if ( result == nullptr )
  {
    V_snprintf(pDest: nameBuf, maxLen: 256, pFormat: "%s_%s", pShaderName, pSuffixName);
    return KeyValues::FindKey(this: pKeyValues, keyName: nameBuf, bCreate: false);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019B40
// Name: FindBuiltinFallbackBlock
// Source: json
//------------------------------------------------------------------------------
KeyValues *__usercall FindBuiltinFallbackBlock@<eax>(KeyValues *pKeyValues@<eax>, const char *pShaderName)
{
  int m_nValue; // edi
  KeyValues *result; // eax
  char pDest[256]; // [esp+Ch] [ebp-100h] BYREF

  if ( gpu_level.m_pParent == nullptr )
  {
    m_nValue = 0;
    goto LABEL_3;
  }
  m_nValue = gpu_level.m_pParent->m_Value.m_nValue;
  if ( m_nValue < 1 )
  {
LABEL_3:
    result = KeyValues::FindKey(this: pKeyValues, keyName: "GPU<1", bCreate: false);
    if ( result != nullptr )
      return result;
    V_snprintf(pDest, maxLen: 256, pFormat: "%s_%s", pShaderName, "GPU<1");
    result = KeyValues::FindKey(this: pKeyValues, keyName: pDest, bCreate: false);
    if ( result != nullptr )
      return result;
  }
  if ( m_nValue >= 2
    || (result = KeyValues::FindKey(this: pKeyValues, keyName: "GPU<2", bCreate: false)) == nullptr
    && (V_snprintf(pDest, maxLen: 256, pFormat: "%s_%s", pShaderName, "GPU<2"),
        (result = KeyValues::FindKey(this: pKeyValues, keyName: pDest, bCreate: false)) == nullptr) )
  {
    if ( m_nValue < 1
      || (result = KeyValues::FindKey(this: pKeyValues, keyName: "GPU>=1", bCreate: false)) == nullptr
      && (V_snprintf(pDest, maxLen: 256, pFormat: "%s_%s", pShaderName, "GPU>=1"),
          (result = KeyValues::FindKey(this: pKeyValues, keyName: pDest, bCreate: false)) == nullptr) )
    {
      if ( m_nValue < 2
        || (result = KeyValues::FindKey(this: pKeyValues, keyName: "GPU>=2", bCreate: false)) == nullptr
        && (V_snprintf(pDest, maxLen: 256, pFormat: "%s_%s", pShaderName, "GPU>=2"),
            (result = KeyValues::FindKey(this: pKeyValues, keyName: pDest, bCreate: false)) == nullptr) )
      {
        if ( (g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig) >= 90
           || (result = CheckConditionalFakeShaderName(pSuffixName: "<DX90", pKeyValues, pShaderName)) == nullptr)
          && (g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig) >= 95
           || (result = CheckConditionalFakeShaderName(pSuffixName: "<DX95", pKeyValues, pShaderName)) == nullptr)
          && (g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig) >= 92
           || (result = CheckConditionalFakeShaderName(pSuffixName: "<DX90_20b", pKeyValues, pShaderName)) == nullptr)
          && (g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig) < 92
           || (result = CheckConditionalFakeShaderName(pSuffixName: ">=DX90_20b", pKeyValues, pShaderName)) == nullptr)
          && (g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig) > 90
           || (result = CheckConditionalFakeShaderName(pSuffixName: "<=DX90", pKeyValues, pShaderName)) == nullptr)
          && (g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig) < 90
           || (result = CheckConditionalFakeShaderName(pSuffixName: ">=DX90", pKeyValues, pShaderName)) == nullptr)
          && (g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig) <= 90
           || (result = CheckConditionalFakeShaderName(pSuffixName: ">DX90", pKeyValues, pShaderName)) == nullptr) )
        {
          if ( g_pHWConfig->GetHDRType(this: g_pHWConfig) != HDR_TYPE_NONE )
          {
            result = CheckConditionalFakeShaderName(pSuffixName: "hdr_dx9", pKeyValues, pShaderName);
            if ( result != nullptr )
              return result;
            result = CheckConditionalFakeShaderName(pSuffixName: "hdr", pKeyValues, pShaderName);
            if ( result != nullptr )
              return result;
          }
          else
          {
            result = CheckConditionalFakeShaderName(pSuffixName: "ldr", pKeyValues, pShaderName);
            if ( result != nullptr )
              return result;
          }
          if ( !g_pHWConfig->UsesSRGBCorrectBlending(this: g_pHWConfig)
            || (result = CheckConditionalFakeShaderName(pSuffixName: "srgb", pKeyValues, pShaderName)) == nullptr )
          {
            if ( g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig) < 90 )
              return nullptr;
            result = CheckConditionalFakeShaderName(pSuffixName: "dx9", pKeyValues, pShaderName);
            if ( result == nullptr )
              return nullptr;
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019E70
// Name: private: virtual void CMaterial::PrecacheMappingDimensions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::PrecacheMappingDimensions(CMaterial *this)
{
  IMaterialVar *v2; // ebx
  IMaterialVar *v3; // edi
  ITextureInternal *m_representativeTexture; // ecx
  unsigned __int16 v5; // ax
  ITextureInternal *v6; // ecx
  bool bFound; // [esp+Fh] [ebp-1h] BYREF

  v2 = this->FindVar(this, a2: "$mappingwidth", a3: &bFound, a4: 0);
  if ( bFound
    && v2->GetIntValueInternal(this: v2) > 0
    && (v3 = this->FindVar(this, a2: "$mappingheight", a3: &bFound, a4: 0), bFound)
    && v3->GetIntValueInternal(this: v3) > 0 )
  {
    this->m_MappingWidth = v2->GetIntValueInternal(this: v2);
    this->m_MappingHeight = v3->GetIntValueInternal(this: v3);
  }
  else
  {
    m_representativeTexture = this->m_representativeTexture;
    if ( m_representativeTexture != nullptr )
    {
      v5 = m_representativeTexture->GetMappingWidth(this: m_representativeTexture);
      v6 = this->m_representativeTexture;
      this->m_MappingWidth = v5;
      this->m_MappingHeight = v6->GetMappingHeight(this: v6);
    }
    else
    {
      *(_DWORD *)&this->m_MappingWidth = 4194368;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019F30
// Name: private: void CMaterial::SetMaterialVarFlags(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::SetMaterialVarFlags(CMaterial *this, int flags, bool on)
{
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // eax
  int v6; // edi
  int v7; // eax

  m_pShaderParams = this->m_pShaderParams;
  if ( on )
  {
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      m_intVal = (*m_pShaderParams)->m_intVal;
    else
      m_intVal = 0;
    v6 = flags;
    (*(void (__thiscall **)(IMaterialVar *, int))(**(_DWORD **)this->m_pShaderParams + 20))(
      a1: *this->m_pShaderParams,
      a2: flags | m_intVal);
  }
  else
  {
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      v7 = (*m_pShaderParams)->m_intVal;
    else
      v7 = 0;
    v6 = flags;
    (*(void (__thiscall **)(IMaterialVar *, int))(**(_DWORD **)this->m_pShaderParams + 20))(
      a1: *this->m_pShaderParams,
      a2: v7 & ~flags);
  }
  (*(void (__stdcall **)(int))(**((_DWORD **)this->m_pShaderParams + 1) + 20))(a1: v6 | *(_DWORD *)(*((_DWORD *)this->m_pShaderParams + 1)
                                                                                                  + 8));
}

//------------------------------------------------------------------------------
// Address: 0x10019FB0
// Name: public: virtual unsigned __int64 CMaterial::GetVertexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMaterial::GetVertexFormat(CMaterial *this)
{
  return this->m_ShaderRenderState.m_VertexFormat;
}

//------------------------------------------------------------------------------
// Address: 0x10019FC0
// Name: public: virtual unsigned __int64 CMaterial::GetVertexUsage(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMaterial::GetVertexUsage(CMaterial *this)
{
  return this->m_ShaderRenderState.m_VertexUsage;
}

//------------------------------------------------------------------------------
// Address: 0x10019FD0
// Name: public: virtual bool CMaterial::PerformDebugTrace(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::PerformDebugTrace(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // eax
  BOOL result; // eax

  result = false;
  if ( (this->m_Flags & 8) != 0 )
  {
    m_pShaderParams = this->m_pShaderParams;
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      m_intVal = (*m_pShaderParams)->m_intVal;
    else
      LOBYTE(m_intVal) = 0;
    if ( (m_intVal & 1) != 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A000
// Name: public: virtual bool CMaterial::IsSuppressed(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::IsSuppressed(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax

  if ( (this->m_Flags & 8) == 0 )
    return true;
  m_pShaderParams = this->m_pShaderParams;
  return m_pShaderParams != nullptr && *m_pShaderParams != nullptr && ((*m_pShaderParams)->m_intVal & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A030
// Name: public: virtual void CMaterial::ToggleSuppression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ToggleSuppression(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // edx

  if ( (this->m_Flags & 8) != 0 )
  {
    m_pShaderParams = this->m_pShaderParams;
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      m_intVal = (*m_pShaderParams)->m_intVal;
    else
      LOBYTE(m_intVal) = 0;
    if ( (m_intVal & 2) == 0 )
    {
      if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
        CMaterial::SetMaterialVarFlags(this, flags: 4, on: ((*m_pShaderParams)->m_intVal & 4) == 0);
      else
        CMaterial::SetMaterialVarFlags(this, flags: 4, on: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A090
// Name: public: virtual void CMaterial::ToggleDebugTrace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ToggleDebugTrace(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax

  if ( (this->m_Flags & 8) != 0 )
  {
    m_pShaderParams = this->m_pShaderParams;
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      CMaterial::SetMaterialVarFlags(this, flags: 1, on: ((*m_pShaderParams)->m_intVal & 1) == 0);
    else
      CMaterial::SetMaterialVarFlags(this, flags: 1, on: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A0D0
// Name: public: virtual bool CMaterial::NoDebugOverride(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::NoDebugOverride(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // eax
  BOOL result; // eax

  result = false;
  if ( (this->m_Flags & 8) != 0 )
  {
    m_pShaderParams = this->m_pShaderParams;
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      m_intVal = (*m_pShaderParams)->m_intVal;
    else
      LOBYTE(m_intVal) = 0;
    if ( (m_intVal & 2) != 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A100
// Name: public: virtual bool CMaterial::GetMaterialVarFlag(enum MaterialVarFlags_t)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::GetMaterialVarFlag(CMaterial *this, MaterialVarFlags_t flag)
{
  IMaterialVar **m_pShaderParams; // eax

  m_pShaderParams = this->m_pShaderParams;
  return m_pShaderParams != nullptr && *m_pShaderParams != nullptr && (flag & (*m_pShaderParams)->m_intVal) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A130
// Name: public: virtual bool CMaterial::UseFog(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::UseFog(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // eax
  BOOL result; // eax

  result = false;
  if ( (this->m_Flags & 8) != 0 )
  {
    m_pShaderParams = this->m_pShaderParams;
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      m_intVal = (*m_pShaderParams)->m_intVal;
    else
      LOWORD(m_intVal) = 0;
    if ( (m_intVal & 0x4000) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A160
// Name: public: virtual bool CMaterial::IsManuallyCreated(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::IsManuallyCreated(CMaterial *this)
{
  return (this->m_Flags & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A170
// Name: public: virtual bool CMaterial::WasReloadedFromWhitelist(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::WasReloadedFromWhitelist(CMaterial *this)
{
  return this->m_bShouldReloadFromWhitelist;
}

//------------------------------------------------------------------------------
// Address: 0x1001A180
// Name: private: void CMaterial::Precache_Internal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::Precache_Internal(CMaterial *this)
{
  MaterialLock_t__ *v2; // eax
  IShaderSystemInternal *v3; // edi
  IShaderSystemInternal_vtbl *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  MaterialLock_t__ *hMaterialLock; // [esp+4h] [ebp-4h]

  v2 = g_pInternalMaterialSystem->Lock(this: g_pInternalMaterialSystem);
  this->m_Flags |= 2u;
  hMaterialLock = v2;
  if ( this->m_pShader != nullptr )
  {
    v3 = g_pShaderSystem;
    v4 = g_pShaderSystem->IShaderInit::__vftable;
    v5 = this->GetTextureGroupName(this);
    v6 = ((int (__thiscall *)(CMaterial *, const char *))this->GetName)(a1: this, a2: v5);
    ((void (__thiscall *)(IShaderSystemInternal *, IShader *, IMaterialVar **, int))v4->InitShaderInstance)(
      a1: v3,
      a2: this->m_pShader,
      a3: this->m_pShaderParams,
      a4: v6);
  }
  this->RecomputeStateSnapshots(this);
  this->FindRepresentativeTexture(this);
  this->PrecacheMappingDimensions(this);
  g_pInternalMaterialSystem->Unlock(this: g_pInternalMaterialSystem, a2: hMaterialLock);
}

//------------------------------------------------------------------------------
// Address: 0x1001A210
// Name: public: virtual void CMaterial::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::Refresh(CMaterial *this)
{
  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
  {
    this->Uncache(this, a2: false);
    this->Precache(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A250
// Name: public: virtual void CMaterial::RefreshPreservingMaterialVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::RefreshPreservingMaterialVars(CMaterial *this)
{
  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
  {
    this->Uncache(this, a2: true);
    this->Precache(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A290
// Name: public: virtual char const __near * CMaterial::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterial::GetName(CMaterial *this)
{
  return CUtlSymbol::String(this: &this->m_Name);
}

//------------------------------------------------------------------------------
// Address: 0x1001A2A0
// Name: public: virtual char const __near * CMaterial::GetTextureGroupName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterial::GetTextureGroupName(CMaterial *this)
{
  return CUtlSymbol::String(this: &this->m_TextureGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x1001A2B0
// Name: public: virtual void CMaterial::SetShader(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::SetShader(CMaterial *this, const char *pShaderName)
{
  IShader *v3; // esi
  const char *v4; // eax
  int v5; // ebx
  const char **v6; // eax
  int v7; // ebx
  int i; // esi
  int v9; // eax
  unsigned int v10; // esi
  IMaterialVar **v11; // eax
  IShaderSystemInternal *v12; // ebx
  IShaderSystemInternal_vtbl *v13; // esi
  const char *v14; // eax
  int v15; // eax
  IMaterialVar *ppVars[256]; // [esp+Ch] [ebp-404h] BYREF
  int iVarCount; // [esp+40Ch] [ebp-4h]

  this->Uncache(this, a2: false);
  while ( 1 )
  {
    v3 = g_pShaderSystem->FindShader(this: g_pShaderSystem, a2: pShaderName);
    if ( v3 == nullptr )
    {
      v4 = (const char *)this->GetName(this);
      _Warning(a1: "SetShader: Couldn't find shader %s for material %s!\n", pShaderName, v4);
      pShaderName = "Wireframe_DX9";
      v3 = g_pShaderSystem->FindShader(this: g_pShaderSystem, a2: "Wireframe_DX9");
    }
    v5 = 0;
    iVarCount = v3->GetParamCount(this: v3);
    if ( iVarCount > 0 )
    {
      do
      {
        v6 = (const char **)v3->GetParamInfo(this: v3, a2: v5);
        ppVars[v5++] = IMaterialVar::Create(pMaterial: this, pKey: *v6);
      }
      while ( v5 < iVarCount );
    }
    g_pShaderSystem->InitShaderParameters(this: g_pShaderSystem, a2: v3, a3: ppVars, a4: pShaderName);
    if ( !g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
      break;
    pShaderName = v3->GetFallbackShader(this: v3, a2: ppVars);
    if ( pShaderName == nullptr )
      break;
    v7 = iVarCount;
    for ( i = 0; i < v7; ++i )
      IMaterialVar::Destroy(pVar: ppVars[i]);
  }
  v9 = iVarCount;
  this->m_pShader = v3;
  this->m_VarCount = v9;
  v10 = 4 * v9;
  v11 = (IMaterialVar **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v9);
  this->m_pShaderParams = v11;
  memcpy(dst: (unsigned __int8 *)v11, src: (unsigned __int8 *)ppVars, count: v10);
  v12 = g_pShaderSystem;
  v13 = g_pShaderSystem->IShaderInit::__vftable;
  v14 = this->GetTextureGroupName(this);
  v15 = ((int (__thiscall *)(CMaterial *, const char *))this->GetName)(a1: this, a2: v14);
  ((void (__thiscall *)(IShaderSystemInternal *, IShader *, IMaterialVar **, int))v13->InitShaderInstance)(
    a1: v12,
    a2: this->m_pShader,
    a3: this->m_pShaderParams,
    a4: v15);
  this->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x1001A430
// Name: public: virtual char const __near * CMaterial::GetShaderName(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *__thiscall CMaterial::GetShaderName(
        CMaterial *this)
{
  if ( this->m_pShader != nullptr )
    return (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)this->m_pShader->GetName(this: this->m_pShader);
  else
    return &pMem;
}

//------------------------------------------------------------------------------
// Address: 0x1001A450
// Name: public: virtual bool CMaterial::IsTranslucentInternal(float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::IsTranslucentInternal(CMaterial *this, float fAlphaModulation)
{
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // edx

  if ( this->m_pShader == nullptr || (this->m_Flags & 8) == 0 )
    return false;
  m_pShaderParams = this->m_pShaderParams;
  if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
    m_intVal = (*m_pShaderParams)->m_intVal;
  else
    m_intVal = 0;
  if ( (m_intVal & 0x40000000) != 0 )
    return true;
  return (this->m_ShaderRenderState.m_Flags & 0x40) != 0
      || fAlphaModulation < 1.0
      || this->m_pShader->IsTranslucent(this: this->m_pShader, a2: m_pShaderParams);
}

//------------------------------------------------------------------------------
// Address: 0x1001A4D0
// Name: public: virtual void CMaterial::CallBindProxy(void __near *,class ICallQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::CallBindProxy(CMaterial *this, void *proxyData, ICallQueue *pCallQueue)
{
  bool v4; // cl
  IClientMaterialSystem *v5; // ebx
  int v6; // esi
  IMaterialProxy *v7; // ecx
  float value; // [esp+18h] [ebp+8h]
  float valuea; // [esp+18h] [ebp+8h]
  bool bIsThreaded_3; // [esp+1Fh] [ebp+Fh]

  v4 = pCallQueue != nullptr;
  bIsThreaded_3 = pCallQueue != nullptr;
  if ( g_config.proxiesTestMode != 0 )
  {
    if ( g_config.proxiesTestMode == 2 )
    {
      valuea = sin(_Plat_FloatTime() * 6.283185307179586 * 0.1) * 0.5 + 0.5;
      (*(void (__stdcall **)(_DWORD))(**((_DWORD **)this->m_pShaderParams + 5) + 16))(a1: LODWORD(valuea));
    }
    else if ( g_config.proxiesTestMode == 3 )
    {
      value = sin(_Plat_FloatTime() * 6.283185307179586 * 0.1) * 0.5 + 0.5;
      (*(void (__thiscall **)(_DWORD, _DWORD, int, int))(**((_DWORD **)this->m_pShaderParams + 4) + 44))(
        a1: *((_DWORD *)this->m_pShaderParams + 4),
        a2: LODWORD(value),
        a3: 1065353216,
        a4: 1065353216);
    }
  }
  else if ( this->m_ProxyCount != 0 )
  {
    if ( v4 )
      EnableThreadedMaterialVarAccess(bEnable: true, ppParams: this->m_pShaderParams, nVarCount: this->m_VarCount);
    v5 = g_pInternalMaterialSystem->GetClientMaterialSystemInterface(this: g_pInternalMaterialSystem);
    if ( v5 != nullptr )
      v5->SetMaterialProxyData(this: v5, a2: proxyData);
    v6 = 0;
    if ( this->m_ProxyCount != 0 )
    {
      do
      {
        v7 = this->m_ppProxies[v6];
        v7->OnBind(this: v7, a2: proxyData);
        ++v6;
      }
      while ( v6 < this->m_ProxyCount );
    }
    if ( v5 != nullptr )
      v5->SetMaterialProxyData(this: v5, a2: nullptr);
    if ( bIsThreaded_3 )
      EnableThreadedMaterialVarAccess(bEnable: false, ppParams: this->m_pShaderParams, nVarCount: this->m_VarCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A630
// Name: public: virtual void CMaterial::DrawMesh(enum VertexCompressionType_t,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::DrawMesh(
        CMaterial *this,
        VertexCompressionType_t vertexCompression,
        bool bIsAlphaModulating,
        BOOL bRenderingPreTessPatchMesh)
{
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // eax

  if ( this->m_pShader != nullptr )
  {
    m_pShaderParams = this->m_pShaderParams;
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      m_intVal = (*m_pShaderParams)->m_intVal;
    else
      LOBYTE(m_intVal) = 0;
    if ( (m_intVal & 4) == 0 )
    {
      this->m_pShader->GetName(this: this->m_pShader);
      g_pShaderSystem->DrawElements(
        this: g_pShaderSystem,
        a2: this->m_pShader,
        a3: this->m_pShaderParams,
        a4: &this->m_ShaderRenderState,
        a5: vertexCompression,
        a6: g_nDebugVarsSignature ^ this->m_ChangeID,
        a7: bIsAlphaModulating,
        a8: bRenderingPreTessPatchMesh);
    }
  }
  else
  {
    _Warning(a1: "CMaterial::DrawElements: No bound shader\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A6B0
// Name: public: virtual void CMaterial::AddMaterialVar(class IMaterialVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::AddMaterialVar(CMaterial *this, IMaterialVar *pMaterialVar)
{
  IMaterialVar **v3; // eax
  int m_VarCount; // ecx

  v3 = (IMaterialVar **)_g_pMemAlloc->Realloc_2(
                          this: _g_pMemAlloc,
                          a2: this->m_pShaderParams,
                          a3: 4 * ++this->m_VarCount);
  m_VarCount = this->m_VarCount;
  this->m_pShaderParams = v3;
  v3[m_VarCount - 1] = pMaterialVar;
}

//------------------------------------------------------------------------------
// Address: 0x1001A6F0
// Name: public: virtual bool CMaterial::IsErrorMaterial(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::IsErrorMaterial(CMaterial *this)
{
  return g_pErrorMaterial == this;
}

//------------------------------------------------------------------------------
// Address: 0x1001A700
// Name: public: virtual void CMaterial::GetLowResColorSample(float,float,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::GetLowResColorSample(CMaterial *this, float s, float t, float *color)
{
  if ( this->m_representativeTexture != nullptr )
    ((void (__thiscall *)(ITextureInternal *, _DWORD, _DWORD, float *))this->m_representativeTexture->GetLowResColorSample)(
      a1: this->m_representativeTexture,
      a2: LODWORD(s),
      a3: LODWORD(t),
      a4: color);
}

//------------------------------------------------------------------------------
// Address: 0x1001A750
// Name: public: virtual void CMaterial::SetNeedsWhiteLightmap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::SetNeedsWhiteLightmap(CMaterial *this, bool val)
{
  if ( val )
    this->m_Flags |= 1u;
  else
    this->m_Flags &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x1001A770
// Name: public: virtual bool CMaterial::GetNeedsWhiteLightmap(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::GetNeedsWhiteLightmap(CMaterial *this)
{
  return this->m_Flags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A780
// Name: public: virtual void CMaterial::MarkAsPreloaded(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::MarkAsPreloaded(CMaterial *this, bool bSet)
{
  if ( bSet )
    this->m_Flags |= 0x40u;
  else
    this->m_Flags &= ~0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x1001A7A0
// Name: public: virtual bool CMaterial::IsPreloaded(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::IsPreloaded(CMaterial *this)
{
  return (this->m_Flags & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A7C0
// Name: public: virtual int CMaterial::ShaderParamCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::ShaderParamCount(CMaterial *this)
{
  return this->m_VarCount;
}

//------------------------------------------------------------------------------
// Address: 0x1001A7D0
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: (const char *)&pMem);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A930
// Name: ApplyPatchKeyValues
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyPatchKeyValues(KeyValues *patchKeyValues@<eax>, KeyValues *keyValues)
{
  KeyValues *Key; // esi
  KeyValues *v4; // edi

  Key = KeyValues::FindKey(this: patchKeyValues, keyName: "insert", bCreate: false);
  v4 = KeyValues::FindKey(this: patchKeyValues, keyName: "replace", bCreate: false);
  if ( Key != nullptr )
    InsertKeyValues(dst: keyValues, src: Key, bCheckForExistence: false);
  if ( v4 != nullptr )
    InsertKeyValues(dst: keyValues, src: v4, bCheckForExistence: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001A980
// Name: void MergeKeyValues(class KeyValues __near &,class KeyValues __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MergeKeyValues(KeyValues *srcKeys, KeyValues *destKeys)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *defaultValue; // [esp+0h] [ebp-Ch]
  int defaultValuea; // [esp+0h] [ebp-Ch]
  float defaultValueb; // [esp+0h] [ebp-Ch]
  void *defaultValuec; // [esp+0h] [ebp-Ch]

  for ( i = KeyValues::GetFirstValue(this: srcKeys); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: (const char *)&pMem);
        Name = KeyValues::GetName(this: i);
        KeyValues::SetString(this: destKeys, keyName: Name, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v4 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: destKeys, keyName: v4, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: destKeys, keyName: v5, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: destKeys, keyName: v6, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AA60
// Name: void AccumulatePatchKeyValues(class KeyValues __near &,class KeyValues __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AccumulatePatchKeyValues(KeyValues *srcKeyValues, KeyValues *patchKeyValues)
{
  KeyValues *Key; // ebx
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  Key = KeyValues::FindKey(this: patchKeyValues, keyName: "insert", bCreate: false);
  if ( Key == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "insert");
    else
      v4 = nullptr;
    Key = v4;
    KeyValues::AddSubKey(this: patchKeyValues, pSubkey: v4);
  }
  v5 = KeyValues::FindKey(this: patchKeyValues, keyName: "replace", bCreate: false);
  if ( v5 == nullptr )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "replace");
    else
      v7 = nullptr;
    v5 = v7;
    KeyValues::AddSubKey(this: patchKeyValues, pSubkey: v7);
  }
  v8 = KeyValues::FindKey(this: srcKeyValues, keyName: "insert", bCreate: false);
  if ( v8 != nullptr )
    MergeKeyValues(srcKeys: v8, destKeys: Key);
  v9 = KeyValues::FindKey(this: srcKeyValues, keyName: "replace", bCreate: false);
  if ( v9 != nullptr )
    MergeKeyValues(srcKeys: v9, destKeys: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1001AB70
// Name: public: virtual bool CMaterial::NeedsFixedFunctionFlashlight(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::NeedsFixedFunctionFlashlight(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // eax

  m_pShaderParams = this->m_pShaderParams;
  if ( m_pShaderParams != nullptr && m_pShaderParams[2] != nullptr )
    m_intVal = m_pShaderParams[2]->m_intVal;
  else
    LOWORD(m_intVal) = 0;
  return (m_intVal & 0x1000) != 0 && g_pInternalMaterialSystem->InFlashlightMode(this: g_pInternalMaterialSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1001ABB0
// Name: public: virtual bool CMaterial::IsUsingVertexID(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::IsUsingVertexID(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax

  m_pShaderParams = this->m_pShaderParams;
  return m_pShaderParams != nullptr && m_pShaderParams[2] != nullptr && (m_pShaderParams[2]->m_intVal & 0x20000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001ABE0
// Name: public: virtual void CMaterial::CompactMaterialVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::CompactMaterialVars(CMaterial *this)
{
  void *(__cdecl **v2)(const char *, int *); // eax
  int v3; // [esp-4h] [ebp-8h]

  if ( this->m_ProxyCount == 0 )
  {
    v3 = this->ShaderParamCount(this);
    v2 = (void *(__cdecl **)(const char *, int *))this->GetShaderParams(this);
    CDummyMaterialSystem::EndBatch(pFactoryList: v2, nFactoryCount: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AC10
// Name: public: virtual int CMaterial_QueueFriendly::GetReferenceCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial_QueueFriendly::GetReferenceCount(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetReferenceCount(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AC20
// Name: public: virtual void CMaterial_QueueFriendly::SetEnumerationID(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::SetEnumerationID(CMaterial_QueueFriendly *this, int id)
{
  this->m_pRealTimeVersion->SetEnumerationID(this: this->m_pRealTimeVersion, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x1001AC40
// Name: public: virtual bool CMaterial_QueueFriendly::GetNeedsWhiteLightmap(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::GetNeedsWhiteLightmap(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetNeedsWhiteLightmap(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AC50
// Name: public: virtual void CMaterial_QueueFriendly::Uncache(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::Uncache(CMaterial_QueueFriendly *this, BOOL bPreserveVars)
{
  this->m_pRealTimeVersion->Uncache(this: this->m_pRealTimeVersion, a2: bPreserveVars);
}

//------------------------------------------------------------------------------
// Address: 0x1001AC70
// Name: public: virtual void CMaterial_QueueFriendly::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::Precache(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->Precache(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AC80
// Name: public: virtual bool CMaterial_QueueFriendly::PrecacheVars(class KeyValues __near *,class KeyValues __near *,class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::PrecacheVars(
        CMaterial_QueueFriendly *this,
        KeyValues *pKeyValues,
        KeyValues *pPatchKeyValues,
        CUtlVector<void *,CUtlMemory<void *,int> > *pIncludes)
{
  return this->m_pRealTimeVersion->PrecacheVars(
           this: this->m_pRealTimeVersion,
           a2: pKeyValues,
           a3: pPatchKeyValues,
           a4: pIncludes);
}

//------------------------------------------------------------------------------
// Address: 0x1001ACA0
// Name: public: virtual void CMaterial_QueueFriendly::SetMinLightmapPageID(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::SetMinLightmapPageID(CMaterial_QueueFriendly *this, int pageID)
{
  this->m_pRealTimeVersion->SetMinLightmapPageID(this: this->m_pRealTimeVersion, a2: pageID);
}

//------------------------------------------------------------------------------
// Address: 0x1001ACE0
// Name: public: virtual int CMaterial_QueueFriendly::GetMaxLightmapPageID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial_QueueFriendly::GetMaxLightmapPageID(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetMaxLightmapPageID(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD00
// Name: public: virtual bool CMaterial_QueueFriendly::IsPrecached(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::IsPrecached(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsPrecached(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD10
// Name: public: virtual bool CMaterial_QueueFriendly::IsPrecachedVars(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::IsPrecachedVars(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsPrecachedVars(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD50
// Name: public: virtual bool CMaterial_QueueFriendly::UseFog(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::UseFog(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->UseFog(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD60
// Name: public: virtual void CMaterial_QueueFriendly::AddMaterialVar(class IMaterialVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::AddMaterialVar(CMaterial_QueueFriendly *this, IMaterialVar *pMaterialVar)
{
  this->m_pRealTimeVersion->AddMaterialVar(this: this->m_pRealTimeVersion, a2: pMaterialVar);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD80
// Name: public: virtual bool CMaterial_QueueFriendly::IsManuallyCreated(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::IsManuallyCreated(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsManuallyCreated(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001ADA0
// Name: public: virtual void CMaterial_QueueFriendly::MarkAsPreloaded(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::MarkAsPreloaded(CMaterial_QueueFriendly *this, BOOL bSet)
{
  this->m_pRealTimeVersion->MarkAsPreloaded(this: this->m_pRealTimeVersion, a2: bSet);
}

//------------------------------------------------------------------------------
// Address: 0x1001ADC0
// Name: public: virtual bool CMaterial_QueueFriendly::IsPreloaded(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::IsPreloaded(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsPreloaded(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001ADD0
// Name: public: virtual void CMaterial_QueueFriendly::ArtificialAddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::ArtificialAddRef(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->ArtificialAddRef(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001ADE0
// Name: public: virtual void CMaterial_QueueFriendly::ArtificialRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::ArtificialRelease(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->ArtificialRelease(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AE20
// Name: public: virtual void CMaterial_QueueFriendly::DecideShouldReloadFromWhitelist(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::DecideShouldReloadFromWhitelist(
        CMaterial_QueueFriendly *this,
        IFileList *pFileList)
{
  this->m_pRealTimeVersion->DecideShouldReloadFromWhitelist(this: this->m_pRealTimeVersion, a2: pFileList);
}

//------------------------------------------------------------------------------
// Address: 0x1001AE40
// Name: public: virtual void CMaterial_QueueFriendly::ReloadFromWhitelistIfMarked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::ReloadFromWhitelistIfMarked(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->ReloadFromWhitelistIfMarked(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AE60
// Name: private: bool CMaterial::ShouldSkipVar(class KeyValues __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterial::ShouldSkipVar(CMaterial *this, KeyValues *pVar, bool *pWasConditional)
{
  unsigned __int8 *Name; // edi
  unsigned __int8 *v4; // eax
  char *v5; // esi
  const char *v7; // eax
  char pszConditionName[256]; // [esp+4h] [ebp-104h] BYREF
  CMaterial *v9; // [esp+104h] [ebp-4h]
  char bToggle_3; // [esp+117h] [ebp+Fh]

  v9 = this;
  Name = (unsigned __int8 *)KeyValues::GetName(this: pVar);
  strchr(string: Name, chr: 0x3Fu);
  if ( v4 == nullptr || v4 == Name )
  {
    *pWasConditional = false;
    return 0;
  }
  else
  {
    *pWasConditional = true;
    V_strncpy(pDest: pszConditionName, pSrc: (const char *)Name, maxLen: v4 - Name + 1);
    v5 = pszConditionName;
    bToggle_3 = 0;
    if ( pszConditionName[0] == 33 )
    {
      v5 = &pszConditionName[1];
      bToggle_3 = 1;
    }
    if ( _V_stricmp(s1: v5, s2: "lowfill") != 0 )
    {
      if ( _V_stricmp(s1: v5, s2: "hdr") == 0 )
        return (g_pHWConfig->GetHDRType(this: g_pHWConfig) == HDR_TYPE_NONE) ^ bToggle_3;
      if ( _V_stricmp(s1: v5, s2: "srgb") == 0 )
        return !g_pHWConfig->UsesSRGBCorrectBlending(this: g_pHWConfig) ^ bToggle_3;
      if ( _V_stricmp(s1: v5, s2: "srgb_gameconsole") == 0 )
      {
        g_pHWConfig->UsesSRGBCorrectBlending(this: g_pHWConfig);
        return bToggle_3 ^ 1;
      }
      if ( _V_stricmp(s1: v5, s2: "srgb_pc") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "ldr") != 0 )
        {
          if ( _V_stricmp(s1: v5, s2: "GPU>=3") != 0 )
          {
            if ( _V_stricmp(s1: v5, s2: "GPU>=2") != 0 )
            {
              if ( _V_stricmp(s1: v5, s2: "GPU>=1") != 0 )
              {
                if ( _V_stricmp(s1: v5, s2: "GPU<2") != 0 )
                {
                  if ( _V_stricmp(s1: v5, s2: "GPU<3") != 0 )
                  {
                    if ( _V_stricmp(s1: v5, s2: "GPU<1") != 0 )
                    {
                      if ( _V_stricmp(s1: v5, s2: "360") != 0
                        && _V_stricmp(s1: v5, s2: "SonyPS3") != 0
                        && _V_stricmp(s1: v5, s2: "gameconsole") != 0 )
                      {
                        v7 = (const char *)v9->GetName(this: v9);
                        _Warning(a1: "unrecognized conditional test %s in %s\n", (const char *)Name, v7);
                      }
                      return bToggle_3 ^ 1;
                    }
                    else if ( gpu_level.m_pParent != nullptr )
                    {
                      return (gpu_level.m_pParent->m_Value.m_nValue >= 1) ^ bToggle_3;
                    }
                    else
                    {
                      return bToggle_3;
                    }
                  }
                  else if ( gpu_level.m_pParent != nullptr )
                  {
                    return (gpu_level.m_pParent->m_Value.m_nValue >= 3) ^ bToggle_3;
                  }
                  else
                  {
                    return bToggle_3;
                  }
                }
                else if ( gpu_level.m_pParent != nullptr )
                {
                  return (gpu_level.m_pParent->m_Value.m_nValue >= 2) ^ bToggle_3;
                }
                else
                {
                  return bToggle_3;
                }
              }
              else if ( gpu_level.m_pParent != nullptr )
              {
                return (gpu_level.m_pParent->m_Value.m_nValue < 1) ^ bToggle_3;
              }
              else
              {
                return bToggle_3 ^ 1;
              }
            }
            else if ( gpu_level.m_pParent != nullptr )
            {
              return (gpu_level.m_pParent->m_Value.m_nValue < 2) ^ bToggle_3;
            }
            else
            {
              return bToggle_3 ^ 1;
            }
          }
          else if ( gpu_level.m_pParent != nullptr )
          {
            return (gpu_level.m_pParent->m_Value.m_nValue < 3) ^ bToggle_3;
          }
          else
          {
            return bToggle_3 ^ 1;
          }
        }
        else
        {
          return (g_pHWConfig->GetHDRType(this: g_pHWConfig) != HDR_TYPE_NONE) ^ bToggle_3;
        }
      }
      else
      {
        return !g_pHWConfig->UsesSRGBCorrectBlending(this: g_pHWConfig) ^ bToggle_3;
      }
    }
    else if ( mat_reduceparticles.m_pParent != nullptr )
    {
      return (mat_reduceparticles.m_pParent->m_Value.m_nValue == 0) ^ bToggle_3;
    }
    else
    {
      return bToggle_3 ^ 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B260
// Name: private: int CMaterial::ParseMaterialVars(class IShader __near *,class KeyValues __near &,class KeyValues __near *,bool,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::ParseMaterialVars(
        CMaterial *this,
        IShader *pShader,
        KeyValues *keyValues,
        KeyValues *pOverrideKeyValues,
        int modelDefault,
        IMaterialVar **ppVars)
{
  IMaterialVar **v8; // edi
  int v9; // eax
  KeyValues *v10; // ecx
  int v11; // esi
  KeyValues *FirstSubKey; // ebx
  char v13; // si
  unsigned __int8 *Name; // esi
  int v15; // eax
  int MaterialVar; // eax
  const char *v17; // eax
  int i; // esi
  const char *v19; // eax
  IMaterialVar *MaterialVarFromKeyValue; // eax
  int v21; // esi
  bool v22; // zf
  int j; // ebx
  const ShaderParamInfo_t *v24; // eax
  const char *v25; // [esp-8h] [ebp-228h]
  const char *v26; // [esp-8h] [ebp-228h]
  bool pOverride[256]; // [esp+108h] [ebp-118h] BYREF
  int flagMask; // [esp+208h] [ebp-18h] BYREF
  int overrideMask; // [esp+20Ch] [ebp-14h] BYREF
  IMaterialVar *pNewVar; // [esp+210h] [ebp-10h]
  int numParams; // [esp+214h] [ebp-Ch]
  int varCount; // [esp+218h] [ebp-8h]
  CMaterial *v33; // [esp+21Ch] [ebp-4h]
  int varIdx; // [esp+230h] [ebp+10h]

  v33 = this;
  if ( pShader == nullptr )
    return 0;
  v8 = ppVars;
  overrideMask = 0;
  flagMask = 0;
  memset(dst: (unsigned __int8 *)ppVars, value: 0, count: 0x400u);
  memset(dst: (unsigned __int8 *)pOverride, value: 0, count: sizeof(pOverride));
  *v8 = IMaterialVar::Create(pMaterial: this, pKey: "$flags", val: (unsigned __int8)modelDefault != 0 ? 0x800 : 0);
  v8[1] = IMaterialVar::Create(
            pMaterial: this,
            pKey: "$flags_defined",
            val: (unsigned __int8)modelDefault != 0 ? 0x800 : 0);
  v8[2] = IMaterialVar::Create(pMaterial: this, pKey: "$flags2", val: 0);
  v8[3] = IMaterialVar::Create(pMaterial: this, pKey: "$flags_defined2", val: 0);
  v9 = pShader->GetParamCount(this: pShader);
  v10 = pOverrideKeyValues;
  v11 = v9;
  LOBYTE(ppVars) = pOverrideKeyValues != nullptr;
  numParams = v9;
  varCount = v9;
  if ( pOverrideKeyValues == nullptr )
    v10 = keyValues;
  FirstSubKey = KeyValues::GetFirstSubKey(this: v10);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      if ( CMaterial::ShouldSkipVar(this: v33, pVar: FirstSubKey, pWasConditional: (bool *)&modelDefault + 3) != 0
        || *KeyValues::GetName(this: FirstSubKey) == 37
        && g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice)
        && !g_pInternalMaterialSystem->CanUseEditorMaterials(this: g_pInternalMaterialSystem)
        && (mat_processtoolvars.m_pParent == nullptr || mat_processtoolvars.m_pParent->m_Value.m_nValue == 0) )
      {
        goto nextVar;
      }
      v13 = (char)ppVars;
      if ( CMaterial::ParseMaterialFlag(
             this: v33,
             a2: (int)FirstSubKey,
             pParseValue: FirstSubKey,
             pFlagVar: *v8,
             pFlagDefinedVar: v8[1],
             parsingOverrides: (bool)ppVars,
             &flagMask,
             &overrideMask) != 0
        || CMaterial::ParseMaterialFlag(
             this: v33,
             a2: (int)FirstSubKey,
             pParseValue: FirstSubKey,
             pFlagVar: v8[2],
             pFlagDefinedVar: v8[3],
             parsingOverrides: v13,
             &flagMask,
             &overrideMask) != 0 )
      {
        goto nextVar;
      }
      Name = (unsigned __int8 *)KeyValues::GetName(this: FirstSubKey);
      strchr(string: Name, chr: 0x3Fu);
      if ( v15 != 0 )
        Name = (unsigned __int8 *)(v15 + 1);
      MaterialVar = FindMaterialVar(pShader, pVarName: (char *)Name);
      varIdx = MaterialVar;
      if ( MaterialVar < 0 )
      {
        for ( i = numParams; i < varCount; ++i )
        {
          pNewVar = v8[i];
          v26 = KeyValues::GetName(this: FirstSubKey);
          v19 = pNewVar->GetName(this: pNewVar);
          if ( _V_stricmp(s1: v19, s2: v26) == 0 )
            break;
        }
        if ( i == varCount )
        {
LABEL_29:
          MaterialVarFromKeyValue = CreateMaterialVarFromKeyValue(pMaterial: v33, pKeyValue: FirstSubKey);
          pNewVar = MaterialVarFromKeyValue;
          if ( MaterialVarFromKeyValue != nullptr )
          {
            v21 = varIdx;
            if ( varIdx < 0 )
              v21 = varCount++;
            if ( v8[v21] != nullptr )
            {
              IMaterialVar::Destroy(pVar: v8[v21]);
              MaterialVarFromKeyValue = pNewVar;
            }
            v22 = (_BYTE)ppVars == 0;
            v8[v21] = MaterialVarFromKeyValue;
            if ( !v22 )
              pOverride[v21] = true;
          }
          goto nextVar;
        }
        if ( !pOverride[i] || (_BYTE)ppVars != 0 )
        {
LABEL_21:
          v25 = (const char *)v33->GetName(this: v33);
          v17 = KeyValues::GetName(this: FirstSubKey);
          _Warning(a1: "Error! Variable \"%s\" is multiply defined in material \"%s\"!\n", v17, v25);
        }
      }
      else
      {
        if ( v8[MaterialVar] == nullptr || HIBYTE(modelDefault) != 0 )
          goto LABEL_29;
        if ( !pOverride[MaterialVar] || (_BYTE)ppVars != 0 )
          goto LABEL_21;
      }
nextVar:
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
      {
        if ( (_BYTE)ppVars == 0
          || (FirstSubKey = KeyValues::GetFirstSubKey(this: keyValues), LOBYTE(ppVars) = 0, FirstSubKey == nullptr) )
        {
          v11 = numParams;
          break;
        }
      }
    }
  }
  for ( j = 0; j < v11; ++j )
  {
    if ( v8[j] == nullptr )
    {
      v24 = pShader->GetParamInfo(this: pShader, a2: j);
      v8[j] = IMaterialVar::Create(pMaterial: v33, pKey: v24->m_pName);
    }
  }
  return varCount;
}

//------------------------------------------------------------------------------
// Address: 0x1001B570
// Name: public: virtual void CMaterial::Uncache(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::Uncache(CMaterial *this, bool bPreserveVars)
{
  MaterialLock_t__ *v3; // edi

  v3 = g_pInternalMaterialSystem->Lock(this: g_pInternalMaterialSystem);
  if ( this->IsPrecached(this) )
  {
    if ( (this->m_Flags & 8) != 0 )
    {
      g_pShaderSystem->CleanupRenderState(this: g_pShaderSystem, a2: &this->m_ShaderRenderState);
      this->m_Flags &= ~8u;
    }
    this->m_Flags &= ~2u;
  }
  if ( !bPreserveVars && this->IsPrecachedVars(this) )
  {
    CMaterial::CleanUpShaderParams(this);
    this->m_pShader = nullptr;
    CMaterial::CleanUpMaterialProxy(this);
    this->m_Flags &= ~4u;
  }
  g_pInternalMaterialSystem->Unlock(this: g_pInternalMaterialSystem, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001B620
// Name: public: virtual void CMaterial::IncrementReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::IncrementReferenceCount(CMaterial *this)
{
  _InterlockedExchangeAdd(&this->m_RefCount.m_value, 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1001B630
// Name: public: virtual void CMaterial::ArtificialAddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ArtificialAddRef(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 0x80u) == 0 )
  {
    this->m_Flags = m_Flags | 0x80;
    _InterlockedExchangeAdd(&this->m_RefCount.m_value, 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B650
// Name: public: virtual void CMaterial::ArtificialRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ArtificialRelease(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 0x80u) != 0 )
  {
    this->m_Flags = m_Flags & 0xFF7F;
    _InterlockedExchangeAdd(&this->m_RefCount.m_value, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B670
// Name: public: virtual void CMaterial::DeleteIfUnreferenced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::DeleteIfUnreferenced(CMaterial *this)
{
  if ( this->m_RefCount.m_value <= 0 )
  {
    IMaterialVar::DeleteUnreferencedTextures(enable: true);
    g_pInternalMaterialSystem->RemoveMaterial(this: g_pInternalMaterialSystem, a2: this);
    IMaterialVar::DeleteUnreferencedTextures(enable: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B6C0
// Name: private: bool CMaterial::InitializeStateSnapshots(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterial::InitializeStateSnapshots(CMaterial *this)
{
  IShaderSystemInternal *v2; // edi
  IShaderSystemInternal_vtbl *v3; // ebx
  int v4; // eax
  char result; // al

  if ( !this->IsPrecached(this) )
    return 1;
  if ( (this->m_Flags & 8) != 0 )
  {
    g_pShaderSystem->CleanupRenderState(this: g_pShaderSystem, a2: &this->m_ShaderRenderState);
    this->m_Flags &= ~8u;
  }
  if ( this->m_pShader == nullptr
    || (v2 = g_pShaderSystem,
        v3 = g_pShaderSystem->IShaderInit::__vftable,
        v4 = this->GetName(this),
        (result = v3->InitRenderState(
                    this: v2,
                    a2: this->m_pShader,
                    a3: this->m_VarCount,
                    a4: this->m_pShaderParams,
                    a5: &this->m_ShaderRenderState,
                    a6: (const char *)v4)) != 0) )
  {
    this->m_Flags |= 8u;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B740
// Name: private: void CMaterial::SetupErrorShader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::SetupErrorShader(CMaterial *this)
{
  IMaterialVar **m_pShaderParams; // eax
  int v3; // ebx
  IShader *v4; // eax
  unsigned __int8 v5; // al
  IMaterialVar **v6; // eax
  int v7; // edi
  bool v8; // zf
  const ShaderParamInfo_t *v9; // eax
  IMaterialVar **v10; // ecx
  int m_intVal; // eax
  IShaderSystemInternal *v12; // ebx
  IShaderSystemInternal_vtbl *v13; // edi
  const char *v14; // eax

  m_pShaderParams = this->m_pShaderParams;
  v3 = 0;
  if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
    v3 = (*m_pShaderParams)->GetIntValueInternal(this: *m_pShaderParams) & 0x800;
  CMaterial::CleanUpShaderParams(this);
  CMaterial::CleanUpMaterialProxy(this);
  v4 = g_pShaderSystem->FindShader(this: g_pShaderSystem, a2: "Wireframe_DX9");
  this->m_pShader = v4;
  v5 = v4->GetParamCount(this: v4);
  this->m_VarCount = v5;
  v6 = (IMaterialVar **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v5);
  v7 = 0;
  v8 = this->m_VarCount == 0;
  this->m_pShaderParams = v6;
  if ( !v8 )
  {
    do
    {
      v9 = this->m_pShader->GetParamInfo(this: this->m_pShader, a2: v7);
      this->m_pShaderParams[v7++] = IMaterialVar::Create(pMaterial: this, pKey: v9->m_pName);
    }
    while ( v7 < this->m_VarCount );
  }
  v10 = this->m_pShaderParams;
  if ( v10 != nullptr && *v10 != nullptr )
    m_intVal = (*v10)->m_intVal;
  else
    m_intVal = 0;
  (*v10)->SetIntValue(this: *v10, a2: v3 | m_intVal);
  (*(void (__stdcall **)(int))(**((_DWORD **)this->m_pShaderParams + 1) + 20))(a1: v3 | *(_DWORD *)(*((_DWORD *)this->m_pShaderParams + 1)
                                                                                                  + 8));
  g_pShaderSystem->InitShaderParameters(
    this: g_pShaderSystem,
    a2: this->m_pShader,
    a3: this->m_pShaderParams,
    a4: "Error");
  v12 = g_pShaderSystem;
  v13 = g_pShaderSystem->IShaderInit::__vftable;
  v14 = this->GetTextureGroupName(this);
  v13->InitShaderInstance(this: v12, a2: this->m_pShader, a3: this->m_pShaderParams, a4: "Error", a5: v14);
  CMaterial::InitializeStateSnapshots(this);
  CMaterial_QueueFriendly::UpdateToRealTime(this: &this->m_QueueFriendlyVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001B870
// Name: public: virtual void CMaterial::DecideShouldReloadFromWhitelist(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::DecideShouldReloadFromWhitelist(CMaterial *this, IFileList *pFilesToReload)
{
  unsigned __int8 (*IsManuallyCreated)(void); // edx
  const char *v4; // eax
  const char *v5; // eax
  char v6; // al
  int i; // ebx
  char vmtFilename[260]; // [esp+4h] [ebp-104h] BYREF

  IsManuallyCreated = (unsigned __int8 (*)(void))this->IsManuallyCreated;
  this->m_bShouldReloadFromWhitelist = false;
  if ( IsManuallyCreated() == 0 && this->IsPrecached(this) )
  {
    v4 = (const char *)this->GetName(this);
    if ( !V_IsAbsolutePath(pStr: v4) )
    {
      v5 = (const char *)this->GetName(this);
      V_ComposeFileName(path: "materials", filename: v5, dest: vmtFilename, destSize: 260);
      V_strncat(pDest: vmtFilename, pSrc: ".vmt", destBufferSize: 0x104u, max_chars_to_copy: -1);
      v6 = pFilesToReload->IsFileInList(this: pFilesToReload, a2: vmtFilename);
      if ( v6 == 0 )
      {
        for ( i = 0; i < this->m_VMTIncludes.m_Size; ++i )
        {
          ((void (__stdcall *)(void **, char *, int))g_pFullFileSystem->String)(
            a1: &this->m_VMTIncludes.m_Memory.m_pMemory[i],
            a2: vmtFilename,
            a3: 260);
          v6 = pFilesToReload->IsFileInList(this: pFilesToReload, a2: vmtFilename);
          if ( v6 != 0 )
            break;
        }
      }
      this->m_bShouldReloadFromWhitelist = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B9C0
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BC90
// Name: public: CMaterial::CMaterial(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterial *__thiscall CMaterial::CMaterial(
        CMaterial *this,
        const char *materialName,
        const char *pTextureGroupName,
        KeyValues *pKeyValues)
{
  void *v5; // esp
  char v7[12]; // [esp+0h] [ebp-24h] BYREF
  CMaterial *v8; // [esp+Ch] [ebp-18h]
  int len; // [esp+10h] [ebp-14h]
  CUtlSymbol v10; // [esp+14h] [ebp-10h] BYREF
  CUtlSymbol v11; // [esp+16h] [ebp-Eh] BYREF
  int v12; // [esp+20h] [ebp-4h]

  this->__vftable = (CMaterial_vtbl *)&CMaterial::`vftable';
  *(_DWORD *)&this->m_Name.m_Id = -1;
  this->m_RefCount.m_value = 0;
  v8 = this;
  this->m_VMTIncludes.m_Memory.m_pMemory = nullptr;
  this->m_VMTIncludes.m_Memory.m_nAllocationCount = 0;
  this->m_VMTIncludes.m_Memory.m_nGrowSize = 0;
  this->m_VMTIncludes.m_Size = 0;
  this->m_VMTIncludes.m_pElements = nullptr;
  v12 = 0;
  this->m_QueueFriendlyVersion.__vftable = (CMaterial_QueueFriendly_vtbl *)&CMaterial_QueueFriendly::`vftable';
  this->m_Reflectivity.x = 0.2;
  this->m_Reflectivity.y = 0.2;
  this->m_Reflectivity.z = 0.2;
  len = _V_strlen(str: materialName);
  v5 = alloca(len + 1);
  V_StripExtension(in: materialName, out: v7, outSize: len + 1);
  _V_strlower(start: v7);
  CUtlSymbol::CUtlSymbol(this: &v11, pStr: v7);
  this->m_Name = v11;
  this->m_bShouldReloadFromWhitelist = false;
  this->m_Flags = 0;
  this->m_pShader = nullptr;
  this->m_pShaderParams = nullptr;
  _InterlockedExchange(&this->m_RefCount.m_value, 0);
  *(_DWORD *)&this->m_MappingWidth = 0;
  this->m_representativeTexture = nullptr;
  this->m_ppProxies = nullptr;
  *(_WORD *)&this->m_VarCount = 0;
  this->m_iEnumerationID = 0;
  this->m_maxLightmapPageID = 0;
  this->m_minLightmapPageID = 0;
  CUtlSymbol::CUtlSymbol(this: &v10, pStr: pTextureGroupName);
  this->m_TextureGroupName = v10;
  this->m_pVMTKeyValues = pKeyValues;
  if ( pKeyValues != nullptr )
    this->m_Flags |= 0x10u;
  if ( v7[0] == 47 && v7[1] == 47 && v7[2] != 47 )
    this->m_Flags |= 0x20u;
  this->m_ShaderRenderState.m_Flags = 0;
  LODWORD(this->m_ShaderRenderState.m_VertexUsage) = 0;
  HIDWORD(this->m_ShaderRenderState.m_VertexUsage) = 0;
  LODWORD(this->m_ShaderRenderState.m_VertexFormat) = 0;
  HIDWORD(this->m_ShaderRenderState.m_VertexFormat) = 0;
  this->m_ShaderRenderState.m_pSnapshots = CMaterial::CreateRenderPassList(this);
  this->m_ChangeID = 0;
  this->m_QueueFriendlyVersion.m_pRealTimeVersion = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDE0
// Name: public: virtual bool CMaterial::IsPrecached(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::IsPrecached(CMaterial *this)
{
  return (this->m_Flags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDF0
// Name: public: virtual bool CMaterial::IsPrecachedVars(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::IsPrecachedVars(CMaterial *this)
{
  return (this->m_Flags & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BE00
// Name: public: virtual void CMaterial::ReportVarChanged(class IMaterialVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ReportVarChanged(CMaterial *this, IMaterialVar *pVar)
{
  ++this->m_ChangeID;
}

//------------------------------------------------------------------------------
// Address: 0x1001BE20
// Name: public: virtual class IMaterialInternal __near * CMaterial::GetRealTimeVersion(void)
// Source: json
//------------------------------------------------------------------------------
CMaterial *__thiscall CMaterial::GetRealTimeVersion(CMaterial *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001BE30
// Name: public: virtual class IMaterialInternal __near * CMaterial::GetQueueFriendlyVersion(void)
// Source: json
//------------------------------------------------------------------------------
CMaterial_QueueFriendly *__thiscall CMaterial::GetQueueFriendlyVersion(CMaterial *this)
{
  return &this->m_QueueFriendlyVersion;
}

//------------------------------------------------------------------------------
// Address: 0x1001BE40
// Name: public: virtual CMaterial::~CMaterial(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::~CMaterial(CMaterial *this)
{
  const char *v2; // eax
  KeyValues *m_pVMTKeyValues; // ecx
  CUtlVector<void *,CUtlMemory<void *,int> > *p_m_VMTIncludes; // esi
  void **m_pMemory; // eax
  volatile int m_value; // [esp-4h] [ebp-1Ch]

  this->__vftable = (CMaterial_vtbl *)&CMaterial::`vftable';
  g_pInternalMaterialSystem->UnbindMaterial(this: g_pInternalMaterialSystem, a2: this);
  CMaterial::Uncache(this, bPreserveVars: false);
  if ( this->m_RefCount.m_value != 0 )
  {
    m_value = this->m_RefCount.m_value;
    v2 = CUtlSymbol::String(this: &this->m_Name);
    _Warning(a1: "Reference Count for Material %s (%d) != 0\n", v2, m_value);
  }
  m_pVMTKeyValues = this->m_pVMTKeyValues;
  if ( m_pVMTKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pVMTKeyValues);
    this->m_pVMTKeyValues = nullptr;
  }
  CMaterial::DestroyRenderPassList(this, pPassList: this->m_ShaderRenderState.m_pSnapshots);
  this->m_QueueFriendlyVersion.m_pRealTimeVersion = nullptr;
  this->m_representativeTexture = nullptr;
  this->__vftable = (CMaterial_vtbl *)-1059136595;
  p_m_VMTIncludes = &this->m_VMTIncludes;
  p_m_VMTIncludes->m_Size = 0;
  if ( p_m_VMTIncludes->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_VMTIncludes->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VMTIncludes->m_Memory.m_pMemory);
      p_m_VMTIncludes->m_Memory.m_pMemory = nullptr;
    }
    p_m_VMTIncludes->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_VMTIncludes->m_Memory.m_pMemory;
  p_m_VMTIncludes->m_pElements = p_m_VMTIncludes->m_Memory.m_pMemory;
  if ( p_m_VMTIncludes->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_VMTIncludes->m_Memory.m_pMemory = nullptr;
    }
    p_m_VMTIncludes->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BF40
// Name: public: virtual void CMaterial::RecomputeStateSnapshots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::RecomputeStateSnapshots(CMaterial *this)
{
  CMatCallQueue *v2; // eax

  v2 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  if ( v2 != nullptr )
  {
    CMatCallQueue::QueueCall<CMaterial *,CMaterial,void>(
      this: v2,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall IMaterial::`vcall'{64,{flat}});
  }
  else if ( CMaterial::InitializeStateSnapshots(this) == 0 )
  {
    CMaterial::SetupErrorShader(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BFB0
// Name: public: virtual void CMaterial::SetMaterialVarFlag(enum MaterialVarFlags_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::SetMaterialVarFlag(CMaterial *this, MaterialVarFlags_t flag, bool on)
{
  CMatCallQueue *v4; // eax
  IMaterialVar **m_pShaderParams; // eax
  int m_intVal; // eax

  v4 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  if ( v4 != nullptr )
  {
    CMatCallQueue::QueueCall<CMaterial *,CMaterial,void,enum MaterialVarFlags_t,bool,enum MaterialVarFlags_t,bool>(
      this: v4,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall IMaterial::`vcall'{116,{flat}},
      arg1: &flag,
      arg2: &on);
  }
  else
  {
    m_pShaderParams = this->m_pShaderParams;
    if ( m_pShaderParams != nullptr && *m_pShaderParams != nullptr )
      m_intVal = (*m_pShaderParams)->m_intVal;
    else
      m_intVal = 0;
    if ( ((m_intVal & flag) != 0) != on )
    {
      CMaterial::SetMaterialVarFlags(this, flags: flag, on);
      this->RecomputeStateSnapshots(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C050
// Name: AccumulateRecursiveVmtPatches
// Source: json
//------------------------------------------------------------------------------
char __usercall AccumulateRecursiveVmtPatches@<al>(
        KeyValues *keyValues@<ecx>,
        CUtlMemory<S3RGBA,int> *pIncludes@<esi>,
        KeyValues *patchKeyValuesOut,
        KeyValues **ppBaseKeyValuesOut,
        const char *pPathID)
{
  const char *Name; // eax
  KeyValues *Copy; // ebx
  const char *v9; // eax
  const char *String; // eax
  const char *v11; // edi
  IBaseFileSystem *v12; // ebx
  const char *v13; // eax
  KeyValues *v14; // ebx
  IFileSystem_vtbl *v15; // edi
  const char *v16; // eax
  int v17; // eax
  int m_pMemory; // edi
  void *v19; // ebx
  int m_nAllocationCount; // eax
  void **v21; // ecx
  int v22; // eax
  void **v23; // eax
  IBaseFileSystem *v24; // [esp-10h] [ebp-3Ch]
  CUtlString includeFileName; // [esp+8h] [ebp-24h] BYREF
  KeyValues *pCurrentKeyValues; // [esp+18h] [ebp-14h]
  int nCount; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+28h] [ebp-4h]

  if ( pIncludes != nullptr )
  {
    pIncludes[1].m_pMemory = nullptr;
    if ( pIncludes->m_nGrowSize >= 0 )
    {
      if ( pIncludes->m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pIncludes->m_pMemory);
        pIncludes->m_pMemory = nullptr;
      }
      pIncludes->m_nAllocationCount = 0;
    }
    pIncludes[1].m_nAllocationCount = (int)pIncludes->m_pMemory;
  }
  KeyValues::Clear(this: patchKeyValuesOut);
  Name = KeyValues::GetName(this: keyValues);
  if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
  {
    if ( ppBaseKeyValuesOut != nullptr )
    {
      *ppBaseKeyValuesOut = nullptr;
      return 1;
    }
  }
  else
  {
    Copy = KeyValues::MakeCopy(this: keyValues);
    pCurrentKeyValues = Copy;
    nCount = 0;
    do
    {
      v9 = KeyValues::GetName(this: Copy);
      if ( _V_stricmp(s1: v9, s2: "patch") != 0 )
        break;
      AccumulatePatchKeyValues(srcKeyValues: Copy, patchKeyValues: patchKeyValuesOut);
      String = KeyValues::GetString(this: Copy, keyName: "include", defaultValue: (const char *)&pMem);
      v11 = String;
      if ( String == nullptr )
      {
        _Warning(a1: "VMT patch file has no $include key - invalid!\n");
        break;
      }
      CUtlString::CUtlString(this: &includeFileName, pString: String);
      v28 = 0;
      KeyValues::Clear(this: Copy);
      if ( g_pFullFileSystem != nullptr )
        v12 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v12 = nullptr;
      v13 = CUtlString::operator char const *(this: &includeFileName);
      v24 = v12;
      v14 = pCurrentKeyValues;
      if ( !KeyValues::LoadFromFile(
              this: pCurrentKeyValues,
              filesystem: v24,
              resourceName: v13,
              pathID: pPathID,
              pfnEvaluateSymbolProc: nullptr) )
      {
        KeyValues::deleteThis(this: v14);
        _Warning(a1: "Failed to load $include VMT file (%s)\n", v11);
        v28 = -1;
        CUtlString::~CUtlString(this: &includeFileName);
        return 0;
      }
      if ( pIncludes != nullptr )
      {
        v15 = g_pFullFileSystem->IAppSystem::__vftable;
        v16 = CUtlString::operator char const *(this: &includeFileName);
        v17 = (int)v15->FindOrAddFileName(this: g_pFullFileSystem, a2: v16);
        m_pMemory = (int)pIncludes[1].m_pMemory;
        v19 = (void *)v17;
        m_nAllocationCount = pIncludes->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IMaterialVar *,int>::Grow(this: pIncludes, num: m_pMemory - m_nAllocationCount + 1);
        ++pIncludes[1].m_pMemory;
        v21 = (void **)pIncludes->m_pMemory;
        v22 = (int)pIncludes[1].m_pMemory - m_pMemory - 1;
        pIncludes[1].m_nAllocationCount = (int)pIncludes->m_pMemory;
        if ( v22 > 0 )
          _V_memmove(dest: &v21[m_pMemory + 1], src: &v21[m_pMemory], count: 4 * v22);
        v23 = (void **)&pIncludes->m_pMemory[m_pMemory];
        if ( v23 != nullptr )
          *v23 = v19;
      }
      ++nCount;
      v28 = -1;
      includeFileName.m_Storage.m_nActualLength = 0;
      if ( includeFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( includeFileName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: includeFileName.m_Storage.m_Memory.m_pMemory);
          includeFileName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        includeFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      Copy = pCurrentKeyValues;
    }
    while ( nCount < 10 );
    if ( ppBaseKeyValuesOut != nullptr )
      *ppBaseKeyValuesOut = Copy;
    else
      KeyValues::deleteThis(this: Copy);
    if ( nCount >= 10 )
      _Warning(a1: "Infinite recursion in patch file?\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001C2B0
// Name: bool LoadVMTFile(class KeyValues __near &,class KeyValues __near &,char const __near *,bool,class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LoadVMTFile(
        KeyValues *vmtKeyValues,
        KeyValues *patchKeyValues,
        const char *pMaterialName,
        KeyValues *bAbsolutePath,
        CUtlVector<void *,CUtlMemory<void *,int> > *pIncludes)
{
  const char *v5; // ebx
  IBaseFileSystem *v6; // eax
  bool result; // al
  KeyValues *v8; // esi
  char pFileName[260]; // [esp+Ch] [ebp-104h] BYREF

  v5 = "GAME";
  if ( (_BYTE)bAbsolutePath != 0 )
  {
    V_snprintf(pDest: pFileName, maxLen: 260, pFormat: "%s.vmt", pMaterialName);
    if ( *pMaterialName == 47 && pMaterialName[1] == 47 && pMaterialName[2] != 47 )
      v5 = nullptr;
  }
  else
  {
    V_snprintf(pDest: pFileName, maxLen: 260, pFormat: "materials/%s.vmt", pMaterialName);
  }
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  result = KeyValues::LoadFromFile(
             this: vmtKeyValues,
             filesystem: v6,
             resourceName: pFileName,
             pathID: v5,
             pfnEvaluateSymbolProc: nullptr);
  if ( result )
  {
    bAbsolutePath = nullptr;
    if ( AccumulateRecursiveVmtPatches(
           keyValues: vmtKeyValues,
           (CUtlMemory<S3RGBA,int> *)pIncludes,
           patchKeyValuesOut: patchKeyValues,
           ppBaseKeyValuesOut: &bAbsolutePath,
           pPathID: v5) != 0 )
    {
      v8 = bAbsolutePath;
      if ( bAbsolutePath != nullptr )
      {
        ApplyPatchKeyValues(patchKeyValues, keyValues: bAbsolutePath);
        KeyValues::operator=(this: vmtKeyValues, src: v8);
        KeyValues::deleteThis(this: v8);
      }
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C390
// Name: public: static class IMaterialInternal __near * IMaterialInternal::CreateMaterial(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterial *__cdecl IMaterialInternal::CreateMaterial(
        const char *pMaterialName,
        const char *pTextureGroupName,
        KeyValues *pVMTKeyValues)
{
  MaterialLock_t__ *v3; // edi
  CMaterial *v4; // eax
  CMaterial *v5; // esi

  v3 = g_pInternalMaterialSystem->Lock(this: g_pInternalMaterialSystem);
  v4 = (CMaterial *)CUtlMemoryPool::Alloc(this: &CMaterial::s_Allocator, amount: 0x98u);
  v5 = nullptr;
  if ( v4 != nullptr )
    v5 = CMaterial::CMaterial(this: v4, materialName: pMaterialName, pTextureGroupName, pKeyValues: pVMTKeyValues);
  g_pInternalMaterialSystem->Unlock(this: g_pInternalMaterialSystem, a2: v3);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001C450
// Name: public: virtual void CMaterial::SetShaderAndParams(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::SetShaderAndParams(CMaterial *this, KeyValues *pKeyValues)
{
  KeyValues *v3; // edi
  KeyValues *m_pVMTKeyValues; // ecx
  KeyValues *Copy; // eax
  int v6; // esi
  char v7; // al
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  IBaseFileSystem *v10; // eax
  const char *Name; // eax
  KeyValues *v12; // eax
  char pFileName[260]; // [esp+8h] [ebp-118h] BYREF
  void *pMem; // [esp+10Ch] [ebp-14h]
  const char *pPathID; // [esp+110h] [ebp-10h]
  int v16; // [esp+11Ch] [ebp-4h]
  KeyValues *pKeyValuesa; // [esp+128h] [ebp+8h]

  v3 = nullptr;
  this->Uncache(this, a2: false);
  m_pVMTKeyValues = this->m_pVMTKeyValues;
  if ( m_pVMTKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pVMTKeyValues);
    this->m_pVMTKeyValues = nullptr;
  }
  if ( pKeyValues != nullptr )
    Copy = KeyValues::MakeCopy(this: pKeyValues);
  else
    Copy = nullptr;
  this->m_pVMTKeyValues = Copy;
  if ( Copy != nullptr )
    this->m_Flags |= 0x10u;
  v6 = this->GetName(this);
  v7 = LOBYTE(this->m_Flags) >> 5;
  pPathID = "GAME";
  if ( (v7 & 1) != 0 )
  {
    V_snprintf(pDest: pFileName, maxLen: 260, pFormat: "%s.vmt", (const char *)v6);
    if ( *(_BYTE *)v6 == 47 && *(_BYTE *)(v6 + 1) == 47 && *(_BYTE *)(v6 + 2) != 47 )
      pPathID = nullptr;
  }
  else
  {
    V_snprintf(pDest: pFileName, maxLen: 260, pFormat: "materials/%s.vmt", (const char *)v6);
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v16 = 0;
  if ( v8 != nullptr )
  {
    v9 = KeyValues::KeyValues(this: v8, setName: "vmt");
    pKeyValuesa = v9;
  }
  else
  {
    pKeyValuesa = nullptr;
    v9 = nullptr;
  }
  v16 = -1;
  if ( g_pFullFileSystem != nullptr )
    v10 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v10 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v9,
         filesystem: v10,
         resourceName: pFileName,
         pathID: pPathID,
         pfnEvaluateSymbolProc: nullptr) )
  {
    Name = KeyValues::GetName(this: v9);
    if ( _V_stricmp(s1: Name, s2: "patch") == 0 )
    {
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      pMem = v12;
      v16 = 1;
      if ( v12 != nullptr )
        v3 = KeyValues::KeyValues(this: v12, setName: "vmt_patch");
      v16 = -1;
      if ( AccumulateRecursiveVmtPatches(
             keyValues: pKeyValuesa,
             pIncludes: nullptr,
             patchKeyValuesOut: v3,
             ppBaseKeyValuesOut: nullptr,
             pPathID) != 0 )
        ApplyPatchKeyValues(patchKeyValues: v3, keyValues: this->m_pVMTKeyValues);
      KeyValues::deleteThis(this: v3);
      v9 = pKeyValuesa;
    }
  }
  KeyValues::deleteThis(this: v9);
  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
    this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001C620
// Name: private: class KeyValues __near * CMaterial::InitializeShader(class KeyValues __near &,class KeyValues __near &)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMaterial::InitializeShader(CMaterial *this, KeyValues *keyValues, KeyValues *patchKeyValues)
{
  const char *Name; // eax
  const char *v5; // eax
  char *v6; // ebx
  IShader *v7; // edi
  const char *v8; // eax
  KeyValues *v9; // ebx
  KeyValues *BuiltinFallbackBlock; // eax
  int v11; // eax
  CMaterial_vtbl *v12; // edx
  IShaderSystemInternal_vtbl *v13; // ebx
  int v14; // eax
  const char *v15; // eax
  KeyValues *Key; // eax
  KeyValues *v17; // edi
  int i; // edi
  const char *String; // edi
  const char *v20; // eax
  KeyValues *v21; // edi
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  int v26; // eax
  unsigned int v27; // edi
  IMaterialVar **v28; // eax
  const char *v29; // [esp-4h] [ebp-B34h]
  const char *v30; // [esp-4h] [ebp-B34h]
  const char *v31; // [esp-4h] [ebp-B34h]
  char warningtext[1024]; // [esp+Ch] [ebp-B24h] BYREF
  IMaterialVar *ppVars[256]; // [esp+40Ch] [ebp-724h] BYREF
  char szShaderName[260]; // [esp+80Ch] [ebp-324h] BYREF
  char pFallbackShaderNameBuf[256]; // [esp+910h] [ebp-220h] BYREF
  char pFallbackMaterialNameBuf[256]; // [esp+A10h] [ebp-120h] BYREF
  bool bAbsolutePath[4]; // [esp+B10h] [ebp-20h]
  IShaderSystemInternal *v38; // [esp+B14h] [ebp-1Ch]
  MaterialLock_t__ *hMaterialLock; // [esp+B18h] [ebp-18h]
  int modelDefault; // [esp+B1Ch] [ebp-14h]
  int varCount; // [esp+B20h] [ebp-10h]
  KeyValues *pCurrentFallback; // [esp+B24h] [ebp-Ch]
  KeyValues *pFallbackSection; // [esp+B28h] [ebp-8h]
  bool bHasBuiltinFallbackBlock; // [esp+B2Fh] [ebp-1h]

  hMaterialLock = g_pInternalMaterialSystem->Lock(this: g_pInternalMaterialSystem);
  pCurrentFallback = keyValues;
  pFallbackSection = nullptr;
  Name = KeyValues::GetName(this: keyValues);
  if ( Name != nullptr )
  {
    V_strncpy(pDest: szShaderName, pSrc: Name, maxLen: 260);
    v6 = szShaderName;
  }
  else
  {
    v5 = (const char *)this->GetName(this);
    _Warning(a1: "Shader not specified in material %s\nUsing wireframe instead...\n", v5);
    v6 = "Wireframe_DX9";
  }
  LOBYTE(modelDefault) = 0;
  while ( 1 )
  {
    v7 = g_pShaderSystem->FindShader(this: g_pShaderSystem, a2: v6);
    if ( v7 == nullptr )
    {
      if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
      {
        v8 = (const char *)((int (__thiscall *)(CMaterial *, char *))this->GetName)(a1: this, a2: v6);
        V_snprintf(
          pDest: warningtext,
          maxLen: 1024,
          pFormat: "Error: Material \"%s\" uses unknown shader \"%s\"\n",
          v8,
          v29);
        _Warning(a1: warningtext);
      }
      v6 = "Wireframe_DX9";
      v7 = g_pShaderSystem->FindShader(this: g_pShaderSystem, a2: "Wireframe_DX9");
      if ( v7 == nullptr )
      {
        g_pInternalMaterialSystem->Unlock(this: g_pInternalMaterialSystem, a2: hMaterialLock);
        return nullptr;
      }
    }
    bHasBuiltinFallbackBlock = false;
    if ( pFallbackSection != nullptr )
    {
      v9 = keyValues;
    }
    else
    {
      v30 = v6;
      v9 = keyValues;
      BuiltinFallbackBlock = FindBuiltinFallbackBlock(pKeyValues: keyValues, pShaderName: v30);
      pFallbackSection = BuiltinFallbackBlock;
      if ( BuiltinFallbackBlock != nullptr )
      {
        bHasBuiltinFallbackBlock = true;
        KeyValues::ChainKeyValue(this: BuiltinFallbackBlock, pChain: keyValues);
        pCurrentFallback = pFallbackSection;
      }
    }
    v11 = CMaterial::ParseMaterialVars(
            this,
            pShader: v7,
            keyValues: v9,
            pOverrideKeyValues: pFallbackSection,
            modelDefault,
            ppVars);
    v12 = this->__vftable;
    varCount = v11;
    v13 = g_pShaderSystem->IShaderInit::__vftable;
    v38 = g_pShaderSystem;
    v14 = (int)v12->GetName(this);
    v13->InitShaderParameters(this: v38, a2: v7, a3: ppVars, a4: (const char *)v14);
    v15 = v7->GetFallbackShader(this: v7, a2: ppVars);
    if ( v15 == nullptr )
      break;
    V_strncpy(pDest: pFallbackShaderNameBuf, pSrc: v15, maxLen: 256);
    v6 = pFallbackShaderNameBuf;
    LOBYTE(modelDefault) = (ppVars[0]->GetIntValueInternal(this: ppVars[0]) & 0x800) != 0;
    if ( !bHasBuiltinFallbackBlock )
    {
      Key = KeyValues::FindKey(this: keyValues, keyName: pFallbackShaderNameBuf, bCreate: false);
      v17 = Key;
      pFallbackSection = Key;
      if ( Key != nullptr )
      {
        KeyValues::ChainKeyValue(this: Key, pChain: keyValues);
        pCurrentFallback = v17;
      }
    }
    for ( i = 0; i < varCount; ++i )
      IMaterialVar::Destroy(pVar: ppVars[i]);
    String = KeyValues::GetString(
               this: pCurrentFallback,
               keyName: "$fallbackmaterial",
               defaultValue: (const char *)&pMem);
    if ( *String != 0 )
    {
      v20 = (const char *)this->GetName(this);
      if ( _V_stricmp(s1: v20, s2: String) != 0 )
      {
        V_strncpy(pDest: pFallbackMaterialNameBuf, pSrc: String, maxLen: 256);
        v21 = keyValues;
        KeyValues::Clear(this: keyValues);
        bAbsolutePath[0] = (this->m_Flags & 0x20) != 0;
        if ( !LoadVMTFile(
                vmtKeyValues: keyValues,
                patchKeyValues,
                pMaterialName: pFallbackMaterialNameBuf,
                bAbsolutePath: *(KeyValues **)bAbsolutePath,
                pIncludes: nullptr) )
        {
          v22 = (const char *)this->GetName(this);
          _Warning(a1: "CMaterial::PrecacheVars: error loading vmt file %s for %s\n", pFallbackMaterialNameBuf, v22);
          KeyValues::operator=(this: keyValues, src: (KeyValues *)g_pErrorMaterial[31].__vftable);
        }
      }
      else
      {
        v23 = (const char *)this->GetName(this);
        _Warning(a1: "CMaterial::PrecacheVars: fallback material for vmt file %s is itself!\n", v23);
        KeyValues::operator=(this: keyValues, src: (KeyValues *)g_pErrorMaterial[31].__vftable);
        v21 = keyValues;
      }
      pCurrentFallback = v21;
      pFallbackSection = nullptr;
      v6 = (char *)KeyValues::GetName(this: v21);
      if ( v6 == nullptr )
      {
        v24 = (const char *)((int (__thiscall *)(CMaterial *, char *))this->GetName)(
                              a1: this,
                              a2: pFallbackMaterialNameBuf);
        _Warning(a1: "Shader not specified in material %s (fallback %s)\nUsing wireframe instead...\n", v24, v31);
        v6 = "Wireframe_DX9";
      }
    }
  }
  v26 = varCount;
  this->m_pShader = v7;
  this->m_VarCount = v26;
  v27 = 4 * v26;
  v28 = (IMaterialVar **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v26);
  this->m_pShaderParams = v28;
  memcpy(dst: (unsigned __int8 *)v28, src: (unsigned __int8 *)ppVars, count: v27);
  g_pInternalMaterialSystem->Unlock(this: g_pInternalMaterialSystem, a2: hMaterialLock);
  return pCurrentFallback;
}

//------------------------------------------------------------------------------
// Address: 0x1001C9A0
// Name: private: bool CMaterial::PrecacheVars_Internal(class KeyValues __near *,class KeyValues __near *,class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterial::PrecacheVars_Internal(
        CMaterial *this,
        KeyValues *pVMTKeyValues,
        KeyValues *pPatchKeyValues,
        CUtlVector<void *,CUtlMemory<void *,int> > *pIncludes)
{
  CUtlVector<void *,CUtlMemory<void *,int> > *p_m_VMTIncludes; // esi
  int m_Size; // ebx
  int i; // eax
  KeyValues *v8; // ebx
  KeyValues *m_pVMTKeyValues; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  KeyValues *v15; // eax
  MaterialLock_t__ *hMaterialLock; // [esp+Ch] [ebp-1Ch]
  KeyValues *bAbsolutePath; // [esp+10h] [ebp-18h]
  KeyValues *v19; // [esp+14h] [ebp-14h]
  char bOk_3; // [esp+3Bh] [ebp+13h]

  p_m_VMTIncludes = &this->m_VMTIncludes;
  if ( pIncludes != nullptr )
  {
    m_Size = pIncludes->m_Size;
    this->m_VMTIncludes.m_Size = 0;
    CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_VMTIncludes,
      elem: 0,
      num: m_Size);
    for ( i = 0; i < m_Size; ++i )
      p_m_VMTIncludes->m_Memory.m_pMemory[i] = pIncludes->m_Memory.m_pMemory[i];
  }
  else
  {
    this->m_VMTIncludes.m_Size = 0;
    if ( this->m_VMTIncludes.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_VMTIncludes->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VMTIncludes->m_Memory.m_pMemory);
        p_m_VMTIncludes->m_Memory.m_pMemory = nullptr;
      }
      this->m_VMTIncludes.m_Memory.m_nAllocationCount = 0;
    }
    this->m_VMTIncludes.m_pElements = this->m_VMTIncludes.m_Memory.m_pMemory;
  }
  hMaterialLock = g_pInternalMaterialSystem->Lock(this: g_pInternalMaterialSystem);
  v8 = nullptr;
  bOk_3 = 0;
  if ( this->m_pVMTKeyValues != nullptr )
  {
    m_pVMTKeyValues = this->m_pVMTKeyValues;
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v8 = KeyValues::KeyValues(this: v10, setName: "vmt_patches");
    else
      v8 = nullptr;
  }
  else if ( pVMTKeyValues != nullptr )
  {
    v8 = pPatchKeyValues;
    m_pVMTKeyValues = pVMTKeyValues;
  }
  else
  {
    CUtlVector<void *,CUtlMemory<void *,int>>::Purge(this: &this->m_VMTIncludes);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v19 = KeyValues::KeyValues(this: v11, setName: "vmt");
    else
      v19 = nullptr;
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    bAbsolutePath = v12;
    if ( v12 != nullptr )
      v8 = KeyValues::KeyValues(this: v12, setName: "vmt_patches");
    LOBYTE(bAbsolutePath) = (this->m_Flags & 0x20) != 0;
    v13 = (const char *)this->GetName(this);
    if ( !LoadVMTFile(
            vmtKeyValues: v19,
            patchKeyValues: v8,
            pMaterialName: v13,
            bAbsolutePath,
            pIncludes: &this->m_VMTIncludes) )
    {
      v14 = (const char *)this->GetName(this);
      _Warning(a1: "CMaterial::PrecacheVars: error loading vmt file for %s\n", v14);
      m_pVMTKeyValues = v19;
      goto LABEL_26;
    }
    m_pVMTKeyValues = v19;
  }
  this->m_Flags |= 4u;
  v15 = CMaterial::InitializeShader(this, keyValues: m_pVMTKeyValues, patchKeyValues: v8);
  if ( v15 != nullptr )
  {
    CMaterial::InitializeMaterialProxy(this, pFallbackKeyValues: v15);
    bOk_3 = 1;
  }
LABEL_26:
  if ( m_pVMTKeyValues != this->m_pVMTKeyValues && m_pVMTKeyValues != pVMTKeyValues )
    KeyValues::deleteThis(this: m_pVMTKeyValues);
  if ( v8 != pPatchKeyValues )
    KeyValues::deleteThis(this: v8);
  if ( this->m_pShaderParams != nullptr )
    CMaterial_QueueFriendly::UpdateToRealTime(this: &this->m_QueueFriendlyVersion);
  g_pInternalMaterialSystem->Unlock(this: g_pInternalMaterialSystem, a2: hMaterialLock);
  return bOk_3;
}

//------------------------------------------------------------------------------
// Address: 0x1001CBD0
// Name: public: virtual void CMaterial::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::Precache(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CC10
// Name: public: virtual bool CMaterial::PrecacheVars(class KeyValues __near *,class KeyValues __near *,class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterial::PrecacheVars(
        CMaterial *this,
        KeyValues *pKeyValues,
        KeyValues *pPatchKeyValues,
        CUtlVector<void *,CUtlMemory<void *,int> > *pIncludes)
{
  if ( (this->m_Flags & 4) != 0 )
    return 1;
  else
    return CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: pKeyValues, pPatchKeyValues, pIncludes);
}

//------------------------------------------------------------------------------
// Address: 0x1001CC30
// Name: private: virtual struct ShaderRenderState_t __near * CMaterial::GetRenderState(void)
// Source: json
//------------------------------------------------------------------------------
ShaderRenderState_t *__thiscall CMaterial::GetRenderState(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return &this->m_ShaderRenderState;
}

//------------------------------------------------------------------------------
// Address: 0x1001CC70
// Name: public: virtual bool CMaterial::UsesEnvCubemap(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::UsesEnvCubemap(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return this->m_pShader != nullptr && (*(_DWORD *)(*((_DWORD *)this->m_pShaderParams + 2) + 8) & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CCC0
// Name: public: virtual bool CMaterial::NeedsTangentSpace(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::NeedsTangentSpace(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return this->m_pShader != nullptr && (*(_DWORD *)(*((_DWORD *)this->m_pShaderParams + 2) + 8) & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CD10
// Name: public: virtual bool CMaterial::NeedsPowerOfTwoFrameBufferTexture(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::NeedsPowerOfTwoFrameBufferTexture(CMaterial *this, BOOL bCheckSpecificToThisFrame)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return this->m_pShader != nullptr
      && this->m_pShader->NeedsPowerOfTwoFrameBufferTexture(
           this: this->m_pShader,
           a2: this->m_pShaderParams,
           a3: bCheckSpecificToThisFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1001CD70
// Name: public: virtual bool CMaterial::NeedsFullFrameBufferTexture(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::NeedsFullFrameBufferTexture(CMaterial *this, BOOL bCheckSpecificToThisFrame)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return this->m_pShader != nullptr
      && this->m_pShader->NeedsFullFrameBufferTexture(
           this: this->m_pShader,
           a2: this->m_pShaderParams,
           a3: bCheckSpecificToThisFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1001CDD0
// Name: public: virtual bool CMaterial::NeedsLightmapBlendAlpha(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::NeedsLightmapBlendAlpha(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax
  IMaterialVar **m_pShaderParams; // esi

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  m_pShaderParams = this->m_pShaderParams;
  return m_pShaderParams != nullptr && m_pShaderParams[2] != nullptr && (m_pShaderParams[2]->m_intVal & 0x100) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CE30
// Name: public: virtual bool CMaterial::NeedsSoftwareSkinning(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::NeedsSoftwareSkinning(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return this->m_pShader != nullptr && ((*this->m_pShaderParams)->m_intVal & 0x800000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CE80
// Name: public: virtual bool CMaterial::NeedsSoftwareLighting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::NeedsSoftwareLighting(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return this->m_pShader != nullptr && (*(_DWORD *)(*((_DWORD *)this->m_pShaderParams + 2) + 8) & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CED0
// Name: public: virtual void CMaterial::AlphaModulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::AlphaModulate(CMaterial *this, float alpha)
{
  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  (*(void (__stdcall **)(_DWORD))(**((_DWORD **)this->m_pShaderParams + 5) + 16))(a1: LODWORD(alpha));
}

//------------------------------------------------------------------------------
// Address: 0x1001CF10
// Name: public: virtual void CMaterial::ColorModulate(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ColorModulate(CMaterial *this, float r, float g, float b)
{
  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(**((_DWORD **)this->m_pShaderParams + 4) + 44))(
    a1: *((_DWORD *)this->m_pShaderParams + 4),
    a2: LODWORD(r),
    a3: LODWORD(g),
    a4: LODWORD(b));
}

//------------------------------------------------------------------------------
// Address: 0x1001CF60
// Name: public: virtual float CMaterial::GetAlphaModulation(void)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CMaterial::GetAlphaModulation(CMaterial *this)
{
  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  return (*(float (__thiscall **)(_DWORD))(**((_DWORD **)this->m_pShaderParams + 5) + 112))(a1: *((_DWORD *)this->m_pShaderParams
                                                                                                + 5));
}

//------------------------------------------------------------------------------
// Address: 0x1001CF90
// Name: public: virtual void CMaterial::GetColorModulation(float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::GetColorModulation(CMaterial *this, float *r, float *g, float *b)
{
  float pColor[3]; // [esp+4h] [ebp-Ch] BYREF

  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  (*(void (__thiscall **)(_DWORD, float *, int))(**((_DWORD **)this->m_pShaderParams + 4) + 116))(
    a1: *((_DWORD *)this->m_pShaderParams + 4),
    a2: pColor,
    a3: 3);
  *r = pColor[0];
  *g = pColor[1];
  *b = pColor[2];
}

//------------------------------------------------------------------------------
// Address: 0x1001CFF0
// Name: public: virtual void CMaterial::ReloadFromWhitelistIfMarked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ReloadFromWhitelistIfMarked(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  if ( this->m_bShouldReloadFromWhitelist )
  {
    this->Uncache(this, a2: false);
    m_Flags = this->m_Flags;
    if ( (m_Flags & 2) == 0
      && ((m_Flags & 4) != 0
       || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
    {
      CMaterial::Precache_Internal(this);
    }
    if ( this->GetShader(this) == nullptr )
    {
      this->m_Flags |= 6u;
      CMaterial::SetupErrorShader(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D050
// Name: public: virtual void CMaterial::ReloadTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::ReloadTextures(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax
  int v3; // ebx
  IMaterialVar **v4; // eax
  int v5; // esi
  IMaterialVar **i; // edi
  IMaterialVar *v7; // eax
  int v8; // eax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  v3 = this->ShaderParamCount(this);
  v4 = this->GetShaderParams(this);
  v5 = 0;
  for ( i = v4; v5 < v3; ++v5 )
  {
    v7 = i[v5];
    if ( v7 != nullptr && (*((_BYTE *)v7 + 28) & 0xF) == 3 )
    {
      v8 = ((int (*)(void))v7->GetTextureValue)();
      if ( v8 != -1 )
        (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v8 + 52))(a1: v8, a2: 0, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D0E0
// Name: public: virtual int CMaterial::GetMappingWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::GetMappingWidth(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return this->m_MappingWidth;
}

//------------------------------------------------------------------------------
// Address: 0x1001D120
// Name: public: virtual int CMaterial::GetMappingHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::GetMappingHeight(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return this->m_MappingHeight;
}

//------------------------------------------------------------------------------
// Address: 0x1001D160
// Name: public: virtual int CMaterial::GetNumAnimationFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::GetNumAnimationFrames(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax
  const char *v4; // eax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  if ( this->m_representativeTexture != nullptr )
    return this->m_representativeTexture->GetNumAnimationFrames(this: this->m_representativeTexture);
  v4 = (const char *)this->GetName(this);
  _Warning(a1: "CMaterial::GetNumAnimationFrames:\nno representative texture for material %s\n", v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001D1C0
// Name: private: char const __near * CMaterial::GetPreviewImageName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterial::GetPreviewImageName(CMaterial *this)
{
  IMaterialVar *v3; // eax
  IMaterialVar *v4; // ecx
  char v5; // dl
  const char *(__thiscall ***v6)(_DWORD); // eax
  IMaterialVar *v7; // eax
  char v8; // dl
  bool found; // [esp+7h] [ebp-1h] BYREF

  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  this->FindVar(this, a2: "%noToolTexture", a3: &found, a4: false);
  if ( found )
    return nullptr;
  v3 = this->FindVar(this, a2: "%toolTexture", a3: &found, a4: 0);
  v4 = v3;
  if ( !found )
    goto LABEL_12;
  v5 = *((_BYTE *)v3 + 28) & 0xF;
  if ( v5 == 1 )
    return v4->GetStringValue(this: v4);
  if ( v5 != 3 )
  {
LABEL_12:
    v7 = this->FindVar(this, a2: "$baseTexture", a3: &found, a4: 0);
    v4 = v7;
    if ( !found )
      return this->GetName(this);
    v8 = *((_BYTE *)v7 + 28) & 0xF;
    if ( v8 == 1 )
      return v4->GetStringValue(this: v4);
    if ( v8 != 3 )
      return this->GetName(this);
  }
  v6 = (const char *(__thiscall ***)(_DWORD))v4->GetTextureValue(this: v4);
  return (**v6)(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1001D290
// Name: private: char const __near * CMaterial::GetPreviewImageFileName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMaterial::GetPreviewImageFileName(CMaterial *this)
{
  const char *PreviewImageName; // eax
  const char *v3; // esi

  PreviewImageName = CMaterial::GetPreviewImageName(this);
  v3 = PreviewImageName;
  if ( PreviewImageName == nullptr )
    return nullptr;
  if ( _V_strlen(str: PreviewImageName) >= 251 )
  {
    _Warning(a1: "MATERIAL_MAX_PATH to short for %s.vtf\n", v3);
    return nullptr;
  }
  if ( (this->m_Flags & 0x20) != 0 )
    V_snprintf(pDest: vtfFilename, maxLen: 256, pFormat: "%s.vtf", v3);
  else
    V_snprintf(pDest: vtfFilename, maxLen: 256, pFormat: "materials/%s.vtf", v3);
  return vtfFilename;
}

//------------------------------------------------------------------------------
// Address: 0x1001D300
// Name: public: virtual enum PreviewImageRetVal_t CMaterial::GetPreviewImageProperties(int __near *,int __near *,enum ImageFormat __near *,bool __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::GetPreviewImageProperties(
        CMaterial *this,
        int *width,
        int *height,
        ImageFormat *imageFormat,
        bool *isTranslucent)
{
  char *PreviewImageFileName; // edi
  int v8; // esi
  void *v9; // esp
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // edx
  const char *v11; // eax
  IVTFTexture *VTFTexture; // esi
  const char *v13; // [esp-4h] [ebp-4Ch]
  int v14; // [esp+0h] [ebp-48h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-3Ch] BYREF
  int v16; // [esp+44h] [ebp-4h]

  PreviewImageFileName = CMaterial::GetPreviewImageFileName(this);
  if ( PreviewImageFileName != nullptr )
  {
    v8 = VTFFileHeaderSize(nMajorVersion: 7, nMinorVersion: -1);
    v9 = alloca(v8);
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: &v14, nSize: v8, nFlags: 0);
    ReadFile = g_pFullFileSystem->ReadFile;
    v16 = 0;
    if ( ReadFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: PreviewImageFileName,
           a3: nullptr,
           a4: &buf,
           a5: v8,
           a6: 0,
           a7: nullptr) )
    {
      VTFTexture = CreateVTFTexture();
      if ( VTFTexture->Unserialize(this: VTFTexture, a2: &buf, a3: true, a4: 0) )
      {
        *width = VTFTexture->Width(this: VTFTexture);
        *height = VTFTexture->Height(this: VTFTexture);
        *imageFormat = VTFTexture->Format(this: VTFTexture);
        *isTranslucent = (VTFTexture->Flags(this: VTFTexture) & 0x3000) != 0;
        DestroyVTFTexture(pTexture: VTFTexture);
        v16 = -1;
        CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>::~CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>(this: &buf);
        return 1;
      }
      else
      {
        _Warning(a1: "Error reading material \"%s\"\n", PreviewImageFileName);
        DestroyVTFTexture(pTexture: VTFTexture);
        v16 = -1;
        CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>::~CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>(this: &buf);
        return 0;
      }
    }
    else
    {
      v11 = (const char *)((int (__thiscall *)(CMaterial *, char *))this->GetName)(a1: this, a2: PreviewImageFileName);
      _Warning(a1: "\"%s\" - \"%s\": cached version doesn't exist\n", v11, v13);
      v16 = -1;
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    *height = 0;
    *width = 0;
    *imageFormat = IMAGE_FORMAT_RGBA8888;
    *isTranslucent = false;
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D4A0
// Name: public: virtual enum PreviewImageRetVal_t CMaterial::GetPreviewImage(unsigned char __near *,int,int,enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMaterial::GetPreviewImage@<eax>(
        CMaterial *this@<ecx>,
        int a2@<edi>,
        unsigned __int8 *pData,
        int width,
        int height,
        ImageFormat imageFormat)
{
  char *PreviewImageFileName; // ebx
  IVTFTexture *VTFTexture; // esi
  void *v10; // edi
  int v11; // ebx
  int v12; // eax
  unsigned int MemRequired; // eax
  unsigned __int8 *m_pMemory; // edi
  ImageFormat v15; // eax
  CUtlBuffer buf; // [esp+8h] [ebp-48h] BYREF
  int nImageOffset; // [esp+38h] [ebp-18h] BYREF
  const char *pFileName; // [esp+3Ch] [ebp-14h]
  int nImageSize; // [esp+40h] [ebp-10h]
  int v21; // [esp+4Ch] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v21 = 0;
  PreviewImageFileName = CMaterial::GetPreviewImageFileName(this);
  pFileName = PreviewImageFileName;
  if ( PreviewImageFileName != nullptr )
  {
    VTFTexture = CreateVTFTexture();
    v10 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: PreviewImageFileName, a3: "rb", a4: 0);
    if ( v10 != nullptr )
    {
      v11 = VTFFileHeaderSize(nMajorVersion: 7, nMinorVersion: -1);
      CUtlBuffer::EnsureCapacity(this: &buf, num: v11);
      v12 = ((int (__thiscall *)(IBaseFileSystem *, unsigned __int8 *, int, void *, int))g_pFullFileSystem->Read)(
              a1: &g_pFullFileSystem->IBaseFileSystem,
              a2: buf.m_Memory.m_pMemory,
              a3: v11,
              a4: v10,
              a5: a2);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v12);
      if ( VTFTexture->Unserialize(this: VTFTexture, a2: &buf, a3: true, a4: 0) )
      {
        ((void (__thiscall *)(IVTFTexture *, _DWORD, _DWORD, _DWORD, int *))VTFTexture->ImageFileInfo)(
          a1: VTFTexture,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: &nImageOffset);
        CUtlBuffer::EnsureCapacity(this: &buf, num: nImageSize);
        CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
        g_pFullFileSystem->Seek(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: v10,
          a3: nImageOffset,
          a4: FILESYSTEM_SEEK_HEAD);
        g_pFullFileSystem->Read(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: buf.m_Memory.m_pMemory,
          a3: nImageSize,
          a4: v10);
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v10);
        m_pMemory = buf.m_Memory.m_pMemory;
        v15 = VTFTexture->Format(this: VTFTexture);
        ImageLoader::ConvertImageFormat(
          src: m_pMemory,
          srcImageFormat: v15,
          dst: pData,
          dstImageFormat: imageFormat,
          width,
          height,
          srcStride: 0,
          dstStride: 0);
        DestroyVTFTexture(pTexture: VTFTexture);
        v21 = -1;
        CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>::~CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>(this: &buf);
        return 1;
      }
      _Warning(a1: "Error reading material \"%s\"\n", pFileName);
      ((void (__thiscall *)(IBaseFileSystem *))g_pFullFileSystem->Close)(a1: &g_pFullFileSystem->IBaseFileSystem);
    }
    else
    {
      _Warning(a1: "\"%s\": cached version doesn't exist\n", PreviewImageFileName);
    }
    MemRequired = ImageLoader::GetMemRequired(
                    width,
                    height,
                    depth: 1,
                    imageFormat,
                    mipmap: false,
                    pAdjustedHeight: nullptr);
    memset(dst: pData, value: 0xFFu, count: MemRequired);
    DestroyVTFTexture(pTexture: VTFTexture);
    v21 = -1;
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
  else
  {
    v21 = -1;
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D700
// Name: public: virtual class IMaterialVar __near * CMaterial::FindVar(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterialVar *__thiscall CMaterial::FindVar(CMaterial *this, const char *pVarName, bool *pFound, bool complain)
{
  unsigned __int16 Symbol; // bx
  int v6; // edi
  IMaterialVar *v7; // ecx
  const char *v8; // eax
  IMaterialVar *result; // eax

  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  Symbol = IMaterialVar::FindSymbol(pName: pVarName);
  if ( Symbol == 0xFFFF || (v6 = this->m_VarCount - 1, this->m_VarCount == 0) )
  {
LABEL_7:
    if ( pFound != nullptr )
      *pFound = false;
    if ( complain && complainCount < 100 )
    {
      v8 = (const char *)this->GetName(this);
      _Warning(a1: "No such variable \"%s\" for material \"%s\"\n", pVarName, v8);
      ++complainCount;
    }
    result = (IMaterialVar *)val;
    if ( val == nullptr )
    {
      result = IMaterialVar::Create(pMaterial: nullptr, pKey: "$dummyVar", val: 0);
      val = (IMaterial *)result;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = this->m_pShaderParams[v6];
      if ( v7->GetNameAsSymbol(this: v7) == Symbol )
        break;
      if ( --v6 < 0 )
        goto LABEL_7;
    }
    if ( pFound != nullptr )
      *pFound = true;
    return this->m_pShaderParams[v6];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D7D0
// Name: public: virtual class IMaterialVar __near * CMaterial::FindVarFast(char const __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialVar *__thiscall CMaterial::FindVarFast(CMaterial *this, const char *pVarName, unsigned int *pCacheData)
{
  char v4; // al
  unsigned __int8 v5; // al
  IMaterialVar *v6; // ecx
  unsigned __int16 Symbol; // ax
  int v9; // ebx
  IMaterialVar *v10; // ecx

  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  v4 = *((_BYTE *)pCacheData + 3);
  if ( (v4 & 1) == 0 )
  {
    *((_BYTE *)pCacheData + 3) = v4 | 1;
    Symbol = IMaterialVar::FindSymbol(pName: pVarName);
    goto LABEL_11;
  }
  if ( (v4 & 2) == 0 )
  {
    v5 = *((_BYTE *)pCacheData + 2);
    if ( v5 < this->m_VarCount )
    {
      v6 = this->m_pShaderParams[v5];
      if ( v6->GetNameAsSymbol(this: v6) == *(_WORD *)pCacheData )
        return this->m_pShaderParams[*((unsigned __int8 *)pCacheData + 2)];
    }
  }
  if ( !IMaterialVar::SymbolMatches(pName: pVarName, symbol: *(_WORD *)pCacheData) )
  {
    Symbol = IMaterialVar::FindSymbol(pName: pVarName);
LABEL_11:
    *(_WORD *)pCacheData = Symbol;
  }
  if ( *(_WORD *)pCacheData == 0xFFFF )
    return nullptr;
  v9 = this->m_VarCount - 1;
  if ( this->m_VarCount == 0 )
    return nullptr;
  while ( 1 )
  {
    v10 = this->m_pShaderParams[v9];
    if ( v10->GetNameAsSymbol(this: v10) == *(_WORD *)pCacheData )
      break;
    if ( --v9 < 0 )
      return nullptr;
  }
  *((_BYTE *)pCacheData + 3) &= ~2u;
  *((_BYTE *)pCacheData + 2) = v9;
  return this->m_pShaderParams[v9];
}

//------------------------------------------------------------------------------
// Address: 0x1001D8A0
// Name: public: virtual void CMaterial::GetReflectivity(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::GetReflectivity(CMaterial *this, Vector *reflect)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  *reflect = this->m_Reflectivity;
}

//------------------------------------------------------------------------------
// Address: 0x1001D8F0
// Name: public: virtual bool CMaterial::GetPropertyFlag(enum MaterialPropertyTypes_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::GetPropertyFlag(CMaterial *this, MaterialPropertyTypes_t type)
{
  unsigned __int16 m_Flags; // ax
  IMaterialVar **m_pShaderParams; // esi
  IMaterialVar **v6; // esi

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  if ( (this->m_Flags & 8) == 0 )
    return false;
  if ( type != MATERIAL_PROPERTY_NEEDS_LIGHTMAP )
  {
    if ( type != MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS )
      return false;
    m_pShaderParams = this->m_pShaderParams;
    return m_pShaderParams != nullptr && m_pShaderParams[2] != nullptr && (m_pShaderParams[2]->m_intVal & 8) != 0;
  }
  else
  {
    v6 = this->m_pShaderParams;
    return v6 != nullptr && v6[2] != nullptr && (v6[2]->m_intVal & 4) != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D9A0
// Name: public: virtual bool CMaterial::IsTwoSided(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::IsTwoSided(CMaterial *this)
{
  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  return this->GetMaterialVarFlag(this, a2: MATERIAL_VAR_NOCULL);
}

//------------------------------------------------------------------------------
// Address: 0x1001D9D0
// Name: public: virtual bool CMaterial::IsTranslucent(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::IsTranslucent(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax
  IMaterialVar **m_pShaderParams; // eax
  double v4; // xmm0_8

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  m_pShaderParams = this->m_pShaderParams;
  if ( m_pShaderParams != nullptr )
    v4 = ((double (__thiscall *)(IMaterialVar *))m_pShaderParams[5]->GetFloatValueInternal)(a1: m_pShaderParams[5]);
  else
    v4 = 0.0;
  return ((bool (__thiscall *)(CMaterial *, _DWORD))this->IsTranslucentInternal)(a1: this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1001DA40
// Name: public: virtual bool CMaterial::IsTranslucentUnderModulation(float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::IsTranslucentUnderModulation(CMaterial *this, float fAlphaModulation)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  return ((bool (__thiscall *)(CMaterial *, _DWORD))this->IsTranslucentInternal)(
           a1: this,
           a2: LODWORD(fAlphaModulation));
}

//------------------------------------------------------------------------------
// Address: 0x1001DA90
// Name: public: virtual bool CMaterial::IsAlphaTested(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::IsAlphaTested(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  if ( this->m_pShader == nullptr || (this->m_Flags & 8) == 0 )
    return false;
  return (this->m_ShaderRenderState.m_Flags & 0x10) != 0 || this->GetMaterialVarFlag(this, a2: MATERIAL_VAR_ALPHATEST);
}

//------------------------------------------------------------------------------
// Address: 0x1001DB00
// Name: public: virtual bool CMaterial::IsVertexLit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::IsVertexLit(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax
  IMaterialVar **m_pShaderParams; // esi

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  if ( (this->m_Flags & 8) == 0 )
    return false;
  m_pShaderParams = this->m_pShaderParams;
  return m_pShaderParams != nullptr && m_pShaderParams[2] != nullptr && (m_pShaderParams[2]->m_intVal & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DB70
// Name: public: virtual bool CMaterial::IsSpriteCard(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial::IsSpriteCard(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax
  IMaterialVar **m_pShaderParams; // esi

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  if ( (this->m_Flags & 8) == 0 )
    return false;
  m_pShaderParams = this->m_pShaderParams;
  return m_pShaderParams != nullptr && m_pShaderParams[2] != nullptr && (m_pShaderParams[2]->m_intVal & 0x10000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DBE0
// Name: public: virtual bool CMaterial::HasProxy(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterial::HasProxy(CMaterial *this)
{
  if ( (this->m_Flags & 4) == 0 )
    CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr);
  return this->m_ProxyCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC10
// Name: private: virtual void CMaterial::FindRepresentativeTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::FindRepresentativeTexture(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax
  IMaterialVar *v3; // eax
  IMaterialVar *v4; // esi
  int v5; // eax
  IMaterialVar *v6; // eax
  IMaterialVar *v7; // eax
  IMaterialVar *v8; // eax
  IMaterialVar *v9; // eax
  IMaterialVar *v10; // eax
  ITextureInternal *v11; // eax
  bool found; // [esp+Bh] [ebp-1h] BYREF

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  v3 = this->FindVar(this, a2: "$baseTexture", a3: &found, a4: 0);
  v4 = v3;
  if ( !found )
    goto LABEL_20;
  if ( (*((_BYTE *)v3 + 28) & 0xF) == 3 )
  {
    v5 = v3->GetTextureValue(this: v3);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v5 + 140))(a1: v5, a2: &this->m_Reflectivity);
  }
  if ( !found || (*((_BYTE *)v4 + 28) & 0xF) != 3 )
  {
LABEL_20:
    v6 = this->FindVar(this, a2: "$flowmap", a3: &found, a4: 0);
    v4 = v6;
    if ( !found || (*((_BYTE *)v6 + 28) & 0xF) != 3 )
    {
      v7 = this->FindVar(this, a2: "$envmapmask", a3: &found, a4: 0);
      v4 = v7;
      if ( !found || (*((_BYTE *)v7 + 28) & 0xF) != 3 )
      {
        v8 = this->FindVar(this, a2: "$bumpmap", a3: &found, a4: 0);
        v4 = v8;
        if ( !found || (*((_BYTE *)v8 + 28) & 0xF) != 3 )
        {
          v9 = this->FindVar(this, a2: "$dudvmap", a3: &found, a4: 0);
          v4 = v9;
          if ( !found || (*((_BYTE *)v9 + 28) & 0xF) != 3 )
          {
            v10 = this->FindVar(this, a2: "$normalmap", a3: &found, a4: 0);
            v4 = v10;
            if ( !found || (*((_BYTE *)v10 + 28) & 0xF) != 3 )
              goto LABEL_23;
          }
        }
      }
    }
  }
  v11 = (ITextureInternal *)v4->GetTextureValue(this: v4);
  this->m_representativeTexture = v11;
  if ( v11 != nullptr )
    v11->Precache(this: v11);
  else
LABEL_23:
    this->m_representativeTexture = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
}

//------------------------------------------------------------------------------
// Address: 0x1001DD90
// Name: public: virtual int CMaterial::GetNumPasses(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::GetNumPasses(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) != 0 )
    return this->m_ShaderRenderState.m_pSnapshots->m_nPassCount;
  if ( (m_Flags & 4) == 0
    && CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) == 0 )
  {
    return this->m_ShaderRenderState.m_pSnapshots->m_nPassCount;
  }
  CMaterial::Precache_Internal(this);
  return this->m_ShaderRenderState.m_pSnapshots->m_nPassCount;
}

//------------------------------------------------------------------------------
// Address: 0x1001DDE0
// Name: public: virtual int CMaterial::GetTextureMemoryBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterial::GetTextureMemoryBytes(CMaterial *this)
{
  unsigned __int16 m_Flags; // ax
  int v3; // ebx
  int v4; // edi
  IMaterialVar *v5; // ecx
  int v6; // eax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0
    && ((m_Flags & 4) != 0
     || CMaterial::PrecacheVars_Internal(this, pVMTKeyValues: nullptr, pPatchKeyValues: nullptr, pIncludes: nullptr) != 0) )
  {
    CMaterial::Precache_Internal(this);
  }
  v3 = 0;
  v4 = 0;
  if ( this->m_VarCount != 0 )
  {
    do
    {
      v5 = this->m_pShaderParams[v4];
      if ( (*((_BYTE *)v5 + 28) & 0xF) == 3 )
      {
        v6 = v5->GetTextureValue(this: v5);
        if ( v6 != 0 && v6 != -1 )
          v3 += (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 56))(a1: v6);
      }
      ++v4;
    }
    while ( v4 < this->m_VarCount );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100212F0
// Name: public: virtual void CMaterial_QueueFriendly::ReloadTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::ReloadTextures(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->ReloadTextures(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10021360
// Name: public: virtual bool CMaterial_QueueFriendly::NoDebugOverride(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::NoDebugOverride(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->NoDebugOverride(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10021390
// Name: public: virtual void CMaterial_QueueFriendly::ToggleSuppression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::ToggleSuppression(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->ToggleSuppression(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x100213A0
// Name: public: virtual void CMaterial_QueueFriendly::ToggleDebugTrace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::ToggleDebugTrace(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->ToggleDebugTrace(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x100213D0
// Name: public: virtual bool CMaterial_QueueFriendly::WasReloadedFromWhitelist(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterial_QueueFriendly::WasReloadedFromWhitelist(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->WasReloadedFromWhitelist(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x100213E0
// Name: public: virtual void CMaterial_QueueFriendly::ReportVarChanged(class IMaterialVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial_QueueFriendly::ReportVarChanged(CMaterial_QueueFriendly *this, IMaterialVar *pVar)
{
  this->m_pRealTimeVersion->ReportVarChanged(this: this->m_pRealTimeVersion, a2: pVar);
}

//------------------------------------------------------------------------------
// Address: 0x1004FB10
// Name: public: virtual void CMaterial::GetMaterialScale(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterial::GetMaterialScale(CMaterial *this, float *pScale)
{
  *pScale = 1.0;
  pScale[1] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1028A490
// Name: _dynamic_initializer_for__CMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CMaterial::s_Allocator,
    blockSize: 152,
    numElements: 256,
    growMode: 1,
    pszAllocOwner: "CMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C1A0
// Name: _dynamic_atexit_destructor_for__CMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x1028A4C0
// Name: _dynamic_initializer_for__mat_reduceparticles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_reduceparticles__()
{
  ConVar::ConVar(this: &mat_reduceparticles, pName: "mat_reduceparticles", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_reduceparticles__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A4F0
// Name: _dynamic_initializer_for__r_emulategl__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_emulategl__()
{
  ConVar::ConVar(this: &r_emulategl, pName: "r_emulategl", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_emulategl__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C1B0
// Name: _dynamic_atexit_destructor_for__mat_reduceparticles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_reduceparticles__()
{
  ConVar::~ConVar(this: &mat_reduceparticles);
}

//------------------------------------------------------------------------------
// Address: 0x1028C1C0
// Name: _dynamic_atexit_destructor_for__r_emulategl__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_emulategl__()
{
  ConVar::~ConVar(this: &r_emulategl);
}
