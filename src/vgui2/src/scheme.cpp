// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/scheme.cpp
// Functions: 52
// ============================================================

#include "vgui2\src\scheme.h"

//------------------------------------------------------------------------------
// Address: 0x10007120
// Name: private: static bool CSchemeManager::BitmapHandleSearchFunc(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSchemeManager::BitmapHandleSearchFunc(
        const CSchemeManager::CachedBitmapHandle_t *lhs,
        const CSchemeManager::CachedBitmapHandle_t *rhs)
{
  const char *v2; // eax
  const char *v4; // eax
  const char *Name; // [esp-4h] [ebp-8h]

  if ( lhs->pBitmap != nullptr )
  {
    if ( rhs->pBitmap != nullptr )
      Name = (const char *)vgui::Bitmap::GetName(this: (CFontAmalgam *)rhs->pBitmap);
    else
      Name = CSchemeManager::s_pszSearchString;
    v2 = (const char *)vgui::Bitmap::GetName(this: (CFontAmalgam *)lhs->pBitmap);
    return _V_stricmp(s1: v2, s2: Name) > 0;
  }
  else
  {
    v4 = (const char *)vgui::Bitmap::GetName(this: (CFontAmalgam *)rhs->pBitmap);
    return _V_stricmp(s1: CSchemeManager::s_pszSearchString, s2: v4) > 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100071B0
// Name: public: virtual unsigned long CSchemeManager::LoadSchemeFromFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSchemeManager::LoadSchemeFromFile(CSchemeManager *this, const char *fileName, const char *tag)
{
  return this->LoadSchemeFromFileEx(this, a2: 0, a3: fileName, a4: tag);
}

//------------------------------------------------------------------------------
// Address: 0x100071D0
// Name: public: virtual unsigned long CSchemeManager::GetDefaultScheme(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSchemeManager::GetDefaultScheme(CSchemeManager *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100071E0
// Name: public: virtual int CSchemeManager::GetProportionalScaledValue(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemeManager::GetProportionalScaledValue(CSchemeManager *this, int normalizedValue)
{
  ISchemeSurface *v3; // eax
  int v4; // edi
  ISchemeSurface *v5; // eax
  int v7; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v3 = this->GetSurface(this);
  v3->GetScreenSize(this: v3, a2: &wide, a3: &tall);
  v4 = tall;
  v5 = this->GetSurface(this);
  v5->GetProportionalBase(this: v5, a2: &v7, a3: &v9);
  return (int)((double)v4 / (double)v9 * (double)normalizedValue);
}

//------------------------------------------------------------------------------
// Address: 0x10007250
// Name: public: virtual int CSchemeManager::GetProportionalNormalizedValue(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemeManager::GetProportionalNormalizedValue(CSchemeManager *this, int scaledValue)
{
  ISchemeSurface *v3; // eax
  int v4; // edi
  ISchemeSurface *v5; // eax
  int v7; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  v3 = this->GetSurface(this);
  v3->GetScreenSize(this: v3, a2: &wide, a3: &tall);
  v4 = tall;
  v5 = this->GetSurface(this);
  v5->GetProportionalBase(this: v5, a2: &v7, a3: &v9);
  return (int)(float)((float)scaledValue / (float)((float)v4 / (float)v9));
}

//------------------------------------------------------------------------------
// Address: 0x100072C0
// Name: public: int CSchemeManager::GetProportionalScaledValueEx(class CScheme __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemeManager::GetProportionalScaledValueEx(
        CSchemeManager *this,
        CScheme *pScheme,
        int normalizedValue)
{
  unsigned int m_SizingPanel; // eax
  CScheme *v6; // edi
  ISchemeSurface *v7; // eax
  int v8; // [esp+4h] [ebp-Ch] BYREF
  int w; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h] BYREF

  m_SizingPanel = pScheme->m_SizingPanel;
  if ( m_SizingPanel == 0 )
    return this->GetProportionalScaledValue(this, a2: normalizedValue);
  vgui::g_pIPanel->GetSize(this: vgui::g_pIPanel, a2: m_SizingPanel, a3: &w, a4: (int *)&pScheme);
  v6 = pScheme;
  v7 = this->GetSurface(this);
  v7->GetProportionalBase(this: v7, a2: &v8, a3: &v10);
  return (int)((double)(int)v6 / (double)v10 * (double)normalizedValue);
}

//------------------------------------------------------------------------------
// Address: 0x10007350
// Name: public: int CSchemeManager::GetProportionalNormalizedValueEx(class CScheme __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemeManager::GetProportionalNormalizedValueEx(
        CSchemeManager *this,
        CScheme *pScheme,
        int scaledValue)
{
  unsigned int m_SizingPanel; // eax
  CScheme *v6; // edi
  ISchemeSurface *v7; // eax
  int v8; // [esp+4h] [ebp-Ch] BYREF
  int w; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h] BYREF

  m_SizingPanel = pScheme->m_SizingPanel;
  if ( m_SizingPanel == 0 )
    return this->GetProportionalNormalizedValue(this, a2: scaledValue);
  vgui::g_pIPanel->GetSize(this: vgui::g_pIPanel, a2: m_SizingPanel, a3: &w, a4: (int *)&pScheme);
  v6 = pScheme;
  v7 = this->GetSurface(this);
  v7->GetProportionalBase(this: v7, a2: &v8, a3: &v10);
  return (int)(float)((float)scaledValue / (float)((float)(int)v6 / (float)v10));
}

//------------------------------------------------------------------------------
// Address: 0x100073E0
// Name: public: virtual int CSchemeManager::GetProportionalScaledValueEx(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemeManager::GetProportionalScaledValueEx(
        CSchemeManager *this,
        unsigned int scheme,
        int normalizedValue)
{
  CScheme *v4; // eax

  v4 = (CScheme *)this->GetIScheme(this, a2: scheme);
  if ( v4 != nullptr )
    return CSchemeManager::GetProportionalScaledValueEx(this, pScheme: v4, normalizedValue);
  else
    return this->GetProportionalScaledValue(this, a2: normalizedValue);
}

//------------------------------------------------------------------------------
// Address: 0x10007420
// Name: public: virtual int CSchemeManager::GetProportionalNormalizedValueEx(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemeManager::GetProportionalNormalizedValueEx(
        CSchemeManager *this,
        unsigned int scheme,
        int scaledValue)
{
  CScheme *v4; // eax

  v4 = (CScheme *)this->GetIScheme(this, a2: scheme);
  if ( v4 != nullptr )
    return CSchemeManager::GetProportionalNormalizedValueEx(this, pScheme: v4, scaledValue);
  else
    return this->GetProportionalNormalizedValue(this, a2: scaledValue);
}

//------------------------------------------------------------------------------
// Address: 0x10007460
// Name: public: virtual unsigned long CSchemeManager::GetImageID(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSchemeManager::GetImageID(CSchemeManager *this, const char *imageName, BOOL hardwareFiltered)
{
  vgui::IImage *v3; // eax

  v3 = this->GetImage(this, a2: imageName, a3: hardwareFiltered);
  return v3->GetID(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10007480
// Name: public: virtual class ISchemeSurface __near * CSchemeManager::GetSurface(void)
// Source: json
//------------------------------------------------------------------------------
ISchemeSurface *__thiscall CSchemeManager::GetSurface(CSchemeManager *this)
{
  return g_pSchemeSurface;
}

//------------------------------------------------------------------------------
// Address: 0x10007490
// Name: public: virtual void CSchemeManager::SetLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchemeManager::SetLanguage(CSchemeManager *this, const char *pLanguage)
{
  ISchemeSurface *v2; // eax

  v2 = this->GetSurface(this);
  v2->SetLanguage(this: v2, a2: pLanguage);
}

//------------------------------------------------------------------------------
// Address: 0x100074B0
// Name: public: virtual char const __near * CSchemeManager::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSchemeManager::GetLanguage(CSchemeManager *this)
{
  ISchemeSurface *v1; // eax

  v1 = this->GetSurface(this);
  return v1->GetLanguage(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100074C0
// Name: public: virtual char const __near * CScheme::GetResourceString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CScheme::GetResourceString(CScheme *this, const char *stringName)
{
  return KeyValues::GetString(this: this->m_pkvBaseSettings, keyName: stringName, defaultValue: pHelpString);
}

//------------------------------------------------------------------------------
// Address: 0x100074E0
// Name: private: char const __near * CScheme::GetMungedFontName(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScheme::GetMungedFontName(CScheme *this, const char *fontName, const char *scheme, bool proportional)
{
  const char *v4; // eax

  v4 = "p";
  if ( scheme != nullptr )
  {
    if ( !proportional )
      v4 = "no";
    V_snprintf(pDest: mungeBuffer, maxLen: 64, pFormat: "%s%s-%s", fontName, scheme, v4);
    return mungeBuffer;
  }
  else
  {
    if ( !proportional )
      v4 = "no";
    V_snprintf(pDest: mungeBuffer, maxLen: 64, pFormat: "%s-%s", fontName, v4);
    return mungeBuffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007550
// Name: private: char const __near * CScheme::LookupSchemeSetting(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CScheme::LookupSchemeSetting(CScheme *this, const char *pchSetting)
{
  const char *v2; // edi
  const char *result; // eax
  const char *String; // eax
  int r; // [esp+8h] [ebp-Ch] BYREF
  int g; // [esp+Ch] [ebp-8h] BYREF
  int a; // [esp+10h] [ebp-4h] BYREF

  v2 = pchSetting;
  a = 0;
  if ( sscanf(string: pchSetting, format: "%d %d %d %d", &r, &g, &pchSetting, &a) >= 3 )
    return v2;
  result = KeyValues::GetString(this: this->m_pkvColors, keyName: v2, defaultValue: nullptr);
  if ( result != nullptr )
    return result;
  String = KeyValues::GetString(this: this->m_pkvBaseSettings, keyName: v2, defaultValue: nullptr);
  if ( String != nullptr )
    return CScheme::LookupSchemeSetting(this, pchSetting: String);
  else
    return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100075C0
// Name: private: int CScheme::GetMinimumFontHeightForCurrentLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScheme::GetMinimumFontHeightForCurrentLanguage(CScheme *this, const char *pLanguage)
{
  char language[64]; // [esp+0h] [ebp-40h] BYREF

  if ( pLanguage != nullptr )
  {
    V_strncpy(pDest: language, pSrc: pLanguage, maxLen: 64);
  }
  else if ( !vgui::g_pSystem->GetRegistryString(
               this: vgui::g_pSystem,
               a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
               a3: language,
               a4: 63) )
  {
    return 0;
  }
  if ( _V_stricmp(s1: language, s2: "korean") == 0
    || _V_stricmp(s1: language, s2: "koreana") == 0
    || _V_stricmp(s1: language, s2: "tchinese") == 0
    || _V_stricmp(s1: language, s2: "schinese") == 0
    || _V_stricmp(s1: language, s2: "japanese") == 0 )
  {
    return 13;
  }
  if ( _V_stricmp(s1: language, s2: "thai") == 0 )
    return 18;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100076A0
// Name: public: virtual class Color CScheme::GetColor(char const __near *,class Color)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CScheme::GetColor(CScheme *this, Color *result, const char *colorName, Color defaultColor)
{
  const char *v4; // eax
  Color *v5; // eax
  bool v6; // cc
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  int b; // [esp+0h] [ebp-Ch] BYREF
  int g; // [esp+4h] [ebp-8h] BYREF
  int r; // [esp+8h] [ebp-4h] BYREF

  v4 = CScheme::LookupSchemeSetting(this, pchSetting: colorName);
  if ( v4 != nullptr )
  {
    colorName = nullptr;
    v6 = sscanf(string: v4, format: "%d %d %d %d", &r, &g, &b, &colorName) < 3;
    v5 = result;
    if ( v6 )
    {
      *result = defaultColor;
    }
    else
    {
      v7 = g;
      result->_color[0] = r;
      v8 = b;
      result->_color[1] = v7;
      v9 = (unsigned __int8)colorName;
      result->_color[2] = v8;
      result->_color[3] = v9;
    }
  }
  else
  {
    *result = defaultColor;
    return result;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10007780
// Name: public: void CUtlMemory<struct vgui::IScheme::fontalias_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::IScheme::fontalias_t,int>::Grow(
        CUtlMemory<vgui::IScheme::fontalias_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::IScheme::fontalias_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 6;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 6 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::IScheme::fontalias_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::IScheme::fontalias_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007820
// Name: public: void CUtlMemory<struct CScheme::SchemeBorder_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CScheme::SchemeBorder_t,int>::Grow(CUtlMemory<CFontAmalgam::TFontRange,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CFontAmalgam::TFontRange *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CFontAmalgam::TFontRange *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CFontAmalgam::TFontRange *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100078C0
// Name: public: void CUtlMemory<struct CScheme::CriticalFont_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CScheme::CriticalFont_t,int>::Grow(CUtlMemory<CScheme::CriticalFont_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CScheme::CriticalFont_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CScheme::CriticalFont_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CScheme::CriticalFont_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007950
// Name: public: virtual void CSchemeManager::ReloadSchemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchemeManager::ReloadSchemes(CSchemeManager *this)
{
  int m_Size; // esi
  CScheme *v3; // esi
  CSchemeManager_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  int count; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Schemes.m_Size;
  count = m_Size;
  this->Shutdown(this, a2: false);
  i = 1;
  if ( m_Size > 1 )
  {
    do
    {
      v3 = this->m_Schemes.m_Memory.m_pMemory[i];
      v4 = this->__vftable;
      v5 = (int)v3->GetName(this: v3);
      v6 = ((int (__thiscall *)(CScheme *, int))v3->GetFileName)(a1: v3, a2: v5);
      ((void (__thiscall *)(CSchemeManager *, int))v4->LoadSchemeFromFile)(a1: this, a2: v6);
      ++i;
    }
    while ( i < count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100079B0
// Name: public: virtual void CSchemeManager::ReloadFonts(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchemeManager::ReloadFonts(CSchemeManager *this, int inScreenTall)
{
  int i; // esi
  CScheme *v4; // ecx

  for ( i = 1; i < this->m_Schemes.m_Size; ++i )
  {
    v4 = this->m_Schemes.m_Memory.m_pMemory[i];
    v4->ReloadFontGlyphs(this: v4, a2: inScreenTall);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100079E0
// Name: public: virtual class vgui::IScheme __near * CSchemeManager::GetIScheme(unsigned long)
// Source: json
//------------------------------------------------------------------------------
CScheme *__thiscall CSchemeManager::GetIScheme(CSchemeManager *this, unsigned int scheme)
{
  if ( scheme < this->m_Schemes.m_Size )
    return this->m_Schemes.m_Memory.m_pMemory[scheme];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10007A00
// Name: private: unsigned long CSchemeManager::FindLoadedScheme(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemeManager::FindLoadedScheme(CSchemeManager *this, const char *pFilename)
{
  int v3; // esi
  CScheme *v4; // ecx
  const char *v5; // eax
  char fileName[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: fileName, pSrc: pFilename, maxLen: 260);
  V_FixSlashes(pname: fileName, separator: 92);
  v3 = 1;
  if ( this->m_Schemes.m_Size <= 1 )
    return 0;
  while ( 1 )
  {
    v4 = this->m_Schemes.m_Memory.m_pMemory[v3];
    v5 = v4->GetFileName(this: v4);
    if ( _V_stricmp(s1: v5, s2: fileName) == 0 )
      break;
    if ( ++v3 >= this->m_Schemes.m_Size )
      return 0;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10007A80
// Name: public: virtual unsigned long CSchemeManager::GetScheme(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchemeManager::GetScheme(CSchemeManager *this, const char *tag)
{
  int v3; // esi
  CScheme *v4; // ecx
  const char *v5; // eax

  v3 = 1;
  if ( this->m_Schemes.m_Size <= 1 )
    return 1;
  while ( 1 )
  {
    v4 = this->m_Schemes.m_Memory.m_pMemory[v3];
    v5 = v4->GetName(this: v4);
    if ( _V_stricmp(s1: tag, s2: v5) == 0 )
      break;
    if ( ++v3 >= this->m_Schemes.m_Size )
      return 1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10007AD0
// Name: public: bool CScheme::GetFontRange(char const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScheme::GetFontRange(CScheme *this, const char *fontname, int *nMin, int *nMax)
{
  int v5; // edi
  int i; // ebx
  const char *v7; // eax

  v5 = 0;
  if ( this->m_FontRanges.m_Size <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v7 = CUtlSymbol::String(this: &this->m_FontRanges.m_Memory.m_pMemory[i]._fontName);
    if ( _V_stricmp(s1: v7, s2: fontname) == 0 )
      break;
    if ( ++v5 >= this->m_FontRanges.m_Size )
      return 0;
  }
  *nMin = this->m_FontRanges.m_Memory.m_pMemory[v5]._min;
  *nMax = this->m_FontRanges.m_Memory.m_pMemory[v5]._max;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007B40
// Name: public: virtual void CScheme::ReloadFontGlyphs(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheme::ReloadFontGlyphs(CScheme *this, int inScreenTall)
{
  CScheme *v2; // edi
  const char *v3; // eax
  unsigned int m_SizingPanel; // eax
  ISchemeSurface *v5; // eax
  ISchemeSurface *v6; // eax
  const char *v7; // esi
  unsigned int v8; // eax
  int v9; // edx
  int MinimumFontHeightForCurrentLanguage; // eax
  KeyValues *m_pData; // ecx
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  int v14; // eax
  const char *String; // eax
  int v16; // edx
  int m_nScreenTall; // ecx
  ISchemeSurface *v18; // eax
  ISchemeSurface *v19; // eax
  ISchemeSurface *v20; // eax
  int Int; // ebx
  int ProportionalScaledValue; // eax
  ISchemeSurface *v23; // eax
  vgui::ISchemeManager_vtbl *v24; // edx
  int v25; // eax
  vgui::IScheme::fontalias_t *v26; // ebx
  const char *v27; // eax
  int v28; // eax
  const char *v29; // eax
  bool v30; // zf
  int (*GetSurface)(void); // eax
  const char *v32; // eax
  vgui::IScheme::fontalias_t *v33; // ebx
  const char *v34; // eax
  const char *v35; // eax
  int v36; // ebx
  vgui::IScheme::fontalias_t *v37; // edi
  const char *v38; // eax
  int v39; // [esp+Ch] [ebp-70h]
  int v40; // [esp+Ch] [ebp-70h]
  int v41; // [esp+10h] [ebp-6Ch]
  int v42; // [esp+10h] [ebp-6Ch]
  int v43; // [esp+14h] [ebp-68h]
  int v44; // [esp+14h] [ebp-68h]
  int v45; // [esp+18h] [ebp-64h]
  int v46; // [esp+18h] [ebp-64h]
  unsigned __int64 v47; // [esp+1Ch] [ebp-60h]
  int v48; // [esp+1Ch] [ebp-60h]
  __int64 v49; // [esp+1Ch] [ebp-60h]
  int v50; // [esp+20h] [ebp-5Ch]
  int defaultValue; // [esp+24h] [ebp-58h]
  int defaultValuea; // [esp+24h] [ebp-58h]
  int nRangeMin; // [esp+38h] [ebp-44h] BYREF
  int nRangeMax; // [esp+3Ch] [ebp-40h] BYREF
  const char *pTrueFontName; // [esp+40h] [ebp-3Ch]
  int minimumFontHeight; // [esp+44h] [ebp-38h]
  KeyValues *fonts; // [esp+48h] [ebp-34h]
  int i; // [esp+4Ch] [ebp-30h]
  int nScreenTall; // [esp+50h] [ebp-2Ch] BYREF
  int nScreenWide; // [esp+54h] [ebp-28h] BYREF
  int scalex; // [esp+58h] [ebp-24h]
  unsigned int scaley; // [esp+5Ch] [ebp-20h]
  int fontYResMin; // [esp+60h] [ebp-1Ch] BYREF
  int blur; // [esp+64h] [ebp-18h]
  int scanlines; // [esp+68h] [ebp-14h]
  int fontYResMax; // [esp+6Ch] [ebp-10h] BYREF
  unsigned int v68; // [esp+70h] [ebp-Ch]
  int tall; // [esp+74h] [ebp-8h]
  int flags; // [esp+78h] [ebp-4h]

  v2 = this;
  v3 = (const char *)((int (__fastcall *)(CScheme *))this->GetFileName)(a1: this);
  _COM_TimestampedLog(a1: "ReloadFontGlyphs(): Start [%s]", v3);
  m_SizingPanel = v2->m_SizingPanel;
  if ( m_SizingPanel != 0 )
  {
    vgui::g_pIPanel->GetSize(this: vgui::g_pIPanel, a2: m_SizingPanel, a3: &nScreenWide, a4: &nScreenTall);
  }
  else
  {
    v5 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
    v5->GetScreenSize(this: v5, a2: &nScreenWide, a3: &nScreenTall);
  }
  v6 = g_Scheme.GetSurface(this: &g_Scheme);
  v7 = v6->GetLanguage(this: v6);
  v8 = HashString(pszKey: v7);
  v9 = nScreenTall;
  if ( nScreenWide != v2->m_nScreenWide || nScreenTall != v2->m_nScreenTall || v8 != v2->m_nLastLoadedLanguage )
  {
    v2->m_nScreenWide = nScreenWide;
    v2->m_nScreenTall = v9;
    v2->m_nLastLoadedLanguage = v8;
    MinimumFontHeightForCurrentLanguage = CScheme::GetMinimumFontHeightForCurrentLanguage(this: v2, pLanguage: v7);
    m_pData = v2->m_pData;
    minimumFontHeight = MinimumFontHeightForCurrentLanguage;
    fonts = KeyValues::FindKey(this: m_pData, keyName: "Fonts", bCreate: true);
    i = 0;
    if ( v2->m_FontAliases.m_Size > 0 )
    {
      v68 = 0;
      do
      {
        pTrueFontName = CUtlSymbol::String(this: &v2->m_FontAliases.m_Memory.m_pMemory[v68 / 6]._trueFontName);
        Key = KeyValues::FindKey(this: fonts, keyName: pTrueFontName, bCreate: true);
        FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
        if ( FirstSubKey != nullptr )
        {
          while ( 1 )
          {
            if ( (_S1 & 1) == 0 )
            {
              _S1 |= 1u;
              v14 = _KeyValuesSystem();
              nIsProportional = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v14 + 12))(
                                  a1: v14,
                                  a2: "isproportional",
                                  a3: 1);
            }
            if ( KeyValues::GetNameSymbol(this: FirstSubKey) != nIsProportional )
            {
              fontYResMin = 0;
              fontYResMax = 0;
              String = KeyValues::GetString(this: FirstSubKey, keyName: "yres", defaultValue: pHelpString);
              sscanf(string: String, format: "%d %d", &fontYResMin, &fontYResMax);
              if ( fontYResMin == 0 )
                break;
              v16 = fontYResMax;
              if ( fontYResMax == 0 )
              {
                v16 = fontYResMin;
                fontYResMax = fontYResMin;
              }
              m_nScreenTall = v2->m_nScreenTall;
              if ( m_nScreenTall >= fontYResMin && m_nScreenTall <= v16 )
                break;
            }
            FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
            if ( FirstSubKey == nullptr )
              goto LABEL_58;
          }
          flags = KeyValues::GetInt(this: FirstSubKey, keyName: "italic", defaultValue: 0) != 0;
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "underline", defaultValue: 0) != 0 )
            flags |= 2u;
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "strikeout", defaultValue: 0) != 0 )
            flags |= 4u;
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "symbol", defaultValue: 0) != 0 )
            flags |= 8u;
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "antialias", defaultValue: 0) != 0 )
          {
            v18 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
            if ( v18->SupportsFontFeature(this: v18, a2: FONT_FEATURE_ANTIALIASED_FONTS) )
              flags |= 0x10u;
          }
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "dropshadow", defaultValue: 0) != 0 )
          {
            v19 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
            if ( v19->SupportsFontFeature(this: v19, a2: FONT_FEATURE_DROPSHADOW_FONTS) )
              flags |= 0x80u;
          }
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "outline", defaultValue: 0) != 0 )
          {
            v20 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
            if ( v20->SupportsFontFeature(this: v20, a2: FONT_FEATURE_OUTLINE_FONTS) )
              flags |= 0x200u;
          }
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "custom", defaultValue: 0) != 0 )
            flags |= 0x400u;
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "bitmap", defaultValue: 0) != 0 )
            flags |= 0x800u;
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "rotary", defaultValue: 0) != 0 )
            flags |= 0x40u;
          if ( KeyValues::GetInt(this: FirstSubKey, keyName: "additive", defaultValue: 0) != 0 )
            flags |= 0x100u;
          Int = KeyValues::GetInt(this: FirstSubKey, keyName: "tall", defaultValue: 0);
          tall = Int;
          blur = KeyValues::GetInt(this: FirstSubKey, keyName: "blur", defaultValue: 0);
          scanlines = KeyValues::GetInt(this: FirstSubKey, keyName: "scanlines", defaultValue: 0);
          *(float *)&scalex = KeyValues::GetFloat(this: FirstSubKey, keyName: "scalex", defaultValue: 1.0);
          *(float *)&scaley = KeyValues::GetFloat(this: FirstSubKey, keyName: "scaley", defaultValue: 1.0);
          if ( fontYResMin == 0
            && fontYResMax == 0
            && *((__int16 *)&v2->m_FontAliases.m_Memory.m_pMemory[v68 / 6] + 2) < 0 )
          {
            tall = CSchemeManager::GetProportionalScaledValueEx(this: &g_Scheme, pScheme: v2, normalizedValue: Int);
            blur = CSchemeManager::GetProportionalScaledValueEx(this: &g_Scheme, pScheme: v2, normalizedValue: blur);
            scanlines = CSchemeManager::GetProportionalScaledValueEx(
                          this: &g_Scheme,
                          pScheme: v2,
                          normalizedValue: scanlines);
            *(float *)&scalex = (float)CSchemeManager::GetProportionalScaledValueEx(
                                         this: &g_Scheme,
                                         pScheme: v2,
                                         normalizedValue: (int)(float)(*(float *)&scalex * 10000.0))
                              * 0.000099999997;
            ProportionalScaledValue = CSchemeManager::GetProportionalScaledValueEx(
                                        this: &g_Scheme,
                                        pScheme: v2,
                                        normalizedValue: (int)(float)(*(float *)&scaley * 10000.0));
            Int = tall;
            *(float *)&scaley = (float)ProportionalScaledValue * 0.000099999997;
          }
          if ( Int > 127 )
          {
            tall = 127;
            Int = 127;
          }
          if ( Int < minimumFontHeight )
          {
            tall = minimumFontHeight;
            Int = minimumFontHeight;
          }
          if ( (flags & 0x800) != 0 )
          {
            v23 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
            v24 = vgui::g_pSchemeManager->__vftable;
            blur = (int)v23;
            v25 = (int)v24->GetSurface(this: vgui::g_pSchemeManager);
            v26 = &v2->m_FontAliases.m_Memory.m_pMemory[v68 / 6];
            tall = v25;
            defaultValue = flags;
            pTrueFontName = (const char *)(*(_DWORD *)v25 + 72);
            v47 = __PAIR64__(scaley, scalex);
            scanlines = *(_DWORD *)blur + 68;
            v27 = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: pHelpString);
            v28 = (*(int (__thiscall **)(int, const char *, _DWORD, _DWORD, int))scanlines)(
                    a1: blur,
                    a2: v27,
                    a3: v47,
                    a4: HIDWORD(v47),
                    a5: defaultValue);
            (*(void (__thiscall **)(int, int, int))pTrueFontName)(a1: tall, a2: *((_WORD *)v26 + 2) & 0x7FFF, a3: v28);
          }
          else
          {
            if ( Int == 0 )
              _Warning(a1: "Bad Tall value for %s\n", pTrueFontName);
            v29 = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: pHelpString);
            v30 = CScheme::GetFontRange(this: v2, fontname: v29, nMin: &nRangeMin, nMax: &nRangeMax) == 0;
            GetSurface = (int (*)(void))vgui::g_pSchemeManager->GetSurface;
            if ( v30 )
            {
              v35 = (const char *)GetSurface();
              v36 = *(_DWORD *)v35;
              v37 = &v2->m_FontAliases.m_Memory.m_pMemory[v68 / 6];
              v49 = (unsigned int)flags;
              v46 = scanlines;
              pTrueFontName = v35;
              v44 = blur;
              v42 = KeyValues::GetInt(this: FirstSubKey, keyName: "weight", defaultValue: 0);
              v40 = tall;
              v38 = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: pHelpString);
              (*(void (__thiscall **)(const char *, int, const char *, int, int, int, int, _DWORD, _DWORD, _DWORD))(v36 + 36))(
                a1: pTrueFontName,
                a2: *((_WORD *)v37 + 2) & 0x7FFF,
                a3: v38,
                a4: v40,
                a5: v42,
                a6: v44,
                a7: v46,
                a8: v49,
                a9: HIDWORD(v49),
                a10: 0);
              v2 = this;
            }
            else
            {
              v32 = (const char *)GetSurface();
              v33 = &v2->m_FontAliases.m_Memory.m_pMemory[v68 / 6];
              defaultValuea = nRangeMax;
              pTrueFontName = v32;
              v50 = nRangeMin;
              scalex = *(_DWORD *)v32 + 36;
              v48 = flags;
              v45 = scanlines;
              v43 = blur;
              v41 = KeyValues::GetInt(this: FirstSubKey, keyName: "weight", defaultValue: 0);
              v39 = tall;
              v34 = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: pHelpString);
              (*(void (__thiscall **)(const char *, int, const char *, int, int, int, int, int, int, int))scalex)(
                a1: pTrueFontName,
                a2: *((_WORD *)v33 + 2) & 0x7FFF,
                a3: v34,
                a4: v39,
                a5: v41,
                a6: v43,
                a7: v45,
                a8: v48,
                a9: v50,
                a10: defaultValuea);
            }
          }
        }
LABEL_58:
        v68 += 6;
        ++i;
      }
      while ( i < v2->m_FontAliases.m_Size );
    }
    _COM_TimestampedLog(a1: "ReloadFontGlyphs(): End");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008140
// Name: public: virtual class vgui::IBorder __near * CScheme::GetBorder(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall CScheme::GetBorder(CScheme *this, const char *borderName)
{
  int v3; // eax
  int v4; // eax
  int m_Size; // edx
  int v6; // ecx
  CScheme::SchemeBorder_t *m_pMemory; // ebx
  int *i; // esi

  v3 = _KeyValuesSystem();
  v4 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v3 + 12))(a1: v3, a2: borderName, a3: 1);
  m_Size = this->m_BorderList.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
    return this->m_pBaseBorder;
  m_pMemory = this->m_BorderList.m_Memory.m_pMemory;
  for ( i = &m_pMemory->borderSymbol; *i != v4; i += 3 )
  {
    if ( ++v6 >= m_Size )
      return this->m_pBaseBorder;
  }
  return m_pMemory[v6].border;
}

//------------------------------------------------------------------------------
// Address: 0x100081A0
// Name: private: unsigned long CScheme::FindFontInAliasList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScheme::FindFontInAliasList(CScheme *this, const char *pFontName)
{
  int v3; // esi
  int i; // edi
  const char *v5; // eax

  v3 = this->m_FontAliases.m_Size - 1;
  if ( v3 < 0 )
    return 0;
  for ( i = v3; ; --i )
  {
    v5 = CUtlSymbol::String(this: &this->m_FontAliases.m_Memory.m_pMemory[i]._fontName);
    if ( V_strncasecmp(s1: pFontName, s2: v5, n: 64) == 0 )
      break;
    if ( --v3 < 0 )
      return 0;
  }
  return *((_WORD *)&this->m_FontAliases.m_Memory.m_pMemory[v3] + 2) & 0x7FFF;
}

//------------------------------------------------------------------------------
// Address: 0x10008200
// Name: public: virtual char const __near * CScheme::GetFontName(unsigned long const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CScheme::GetFontName(CScheme *this, const unsigned int *font)
{
  int v2; // eax
  vgui::IScheme::fontalias_t *m_pMemory; // esi
  vgui::IScheme::fontalias_t *i; // ecx

  v2 = this->m_FontAliases.m_Size - 1;
  if ( v2 < 0 )
    return "<Unknown font>";
  m_pMemory = this->m_FontAliases.m_Memory.m_pMemory;
  for ( i = (vgui::IScheme::fontalias_t *)((char *)&m_pMemory[v2] + 4); (i->_fontName.m_Id & 0x7FFF) != *font; --i )
  {
    if ( --v2 < 0 )
      return "<Unknown font>";
  }
  return CUtlSymbol::String(this: &m_pMemory[v2]._trueFontName);
}

//------------------------------------------------------------------------------
// Address: 0x10008260
// Name: public: virtual unsigned long CScheme::GetFont(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScheme::GetFont(CScheme *this, const char *fontName, bool proportional)
{
  const char *v4; // eax
  char *MungedFontName; // eax

  v4 = CUtlString::Get(this: &this->m_tag);
  MungedFontName = CScheme::GetMungedFontName(this, fontName, scheme: v4, proportional);
  return CScheme::FindFontInAliasList(this, pFontName: MungedFontName);
}

//------------------------------------------------------------------------------
// Address: 0x10008870
// Name: public: void CSchemeManager::SpewFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSchemeManager::SpewFonts(CSchemeManager *this@<ecx>, int a2@<edi>)
{
  int v2; // esi
  CScheme *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  ISchemeSurface *v7; // eax
  CUtlSymbol *p_fontName; // esi
  ISchemeSurface *v10; // [esp+4h] [ebp-14h]
  int v11; // [esp+8h] [ebp-10h]
  CSchemeManager *v12; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  v2 = 1;
  v12 = this;
  for ( i = 1; v2 < v12->m_Schemes.m_Size; i = v2 )
  {
    v3 = this->m_Schemes.m_Memory.m_pMemory[v2];
    v4 = (int)v3->GetFileName(this: v3);
    v5 = ((int (__thiscall *)(CScheme *, int))v3->GetName)(a1: v3, a2: v4);
    _Msg(a1: "Scheme: %s (%s)\n", a2: v5);
    v6 = 0;
    if ( v3->m_FontAliases.m_Size > 0 )
    {
      v14 = 0;
      do
      {
        v11 = ((int (__thiscall *)(vgui::ISchemeManager *, int))vgui::g_pSchemeManager->GetSurface)(
                a1: vgui::g_pSchemeManager,
                a2);
        v7 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
        p_fontName = &v3->m_FontAliases.m_Memory.m_pMemory[v14]._fontName;
        v10 = v7;
        a2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v11 + 44))(a1: v11, a2: p_fontName[2].m_Id & 0x7FFF);
        v10->GetFontName(this: v10, a2: p_fontName[2].m_Id & 0x7FFF);
        CUtlSymbol::String(this: p_fontName);
        CUtlSymbol::String(this: p_fontName + 1);
        _Msg(a1: "  %2d: HFont:0x%8.8x, %s, %s, font:%s, tall:%d\n", a2: v6);
        ++v14;
        ++v6;
      }
      while ( v6 < v3->m_FontAliases.m_Size );
      v2 = i;
    }
    this = v12;
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009170
// Name: vgui_spew_fonts
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui_spew_fonts(int a1@<edi>)
{
  CSchemeManager::SpewFonts(this: &g_Scheme, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10009180
// Name: public: virtual void CSchemeManager::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchemeManager::Shutdown(CSchemeManager *this, bool full)
{
  int v2; // eax
  CScheme *v3; // esi
  int v4; // edi
  int v5; // ebx
  CScheme::SchemeBorder_t *m_pMemory; // eax
  KeyValues *m_pData; // ecx
  CSchemeManager *v8; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v8 = this;
  v2 = !full;
  i = v2;
  if ( v2 < this->m_Schemes.m_Size )
  {
    do
    {
      v3 = this->m_Schemes.m_Memory.m_pMemory[v2];
      v4 = 0;
      v3->m_bActive = false;
      if ( v3->m_BorderList.m_Size > 0 )
      {
        v5 = 0;
        do
        {
          m_pMemory = v3->m_BorderList.m_Memory.m_pMemory;
          if ( !m_pMemory[v5].bSharedBorder )
            free(pMem: m_pMemory[v5].border);
          ++v4;
          ++v5;
        }
        while ( v4 < v3->m_BorderList.m_Size );
      }
      v3->m_pBaseBorder = nullptr;
      v3->m_BorderList.m_Size = 0;
      v3->m_pkvBorders = nullptr;
      v3->m_FontRanges.m_Size = 0;
      m_pData = v3->m_pData;
      if ( m_pData != nullptr )
      {
        KeyValues::deleteThis(this: m_pData);
        v3->m_pData = nullptr;
      }
      if ( full )
        ((void (__thiscall *)(CScheme *, int))v3->dtr_IBaseInterface)(a1: v3, a2: 1);
      this = v8;
      v2 = i + 1;
      i = v2;
    }
    while ( v2 < v8->m_Schemes.m_Size );
  }
  if ( full )
    this->m_Schemes.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009D50
// Name: public: virtual CSchemeManager::~CSchemeManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchemeManager::~CSchemeManager(CSchemeManager *this)
{
  int v2; // esi
  CScheme *v3; // ecx
  int v4; // esi
  vgui::Bitmap *pBitmap; // ecx
  int v6; // eax
  CScheme *v7; // esi
  int v8; // ebx
  int v9; // eax
  CScheme::SchemeBorder_t *m_pMemory; // ecx
  KeyValues *m_pData; // ecx
  bool v12; // sf
  CScheme **v13; // eax
  int i; // [esp+8h] [ebp-8h]
  int v15; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( this->__vftable = (CSchemeManager_vtbl *)&CSchemeManager::`vftable'; v2 < this->m_Schemes.m_Size; ++v2 )
  {
    v3 = this->m_Schemes.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CScheme *, int))v3->dtr_IBaseInterface)(a1: v3, a2: 1);
  }
  v4 = 0;
  for ( this->m_Schemes.m_Size = 0; v4 < this->m_Bitmaps.m_Elements.m_nAllocationCount; ++v4 )
  {
    if ( v4 >= 0 && v4 < this->m_Bitmaps.m_Elements.m_nAllocationCount && v4 <= this->m_Bitmaps.m_LastAlloc.index )
    {
      if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      if ( this->m_Bitmaps.m_Elements.m_pMemory[v4].m_Left != v4 )
      {
        pBitmap = this->m_Bitmaps.m_Elements.m_pMemory[v4].m_Data.pBitmap;
        if ( pBitmap != nullptr )
          ((void (__thiscall *)(vgui::Bitmap *, int))pBitmap->dtr_IImage)(a1: pBitmap, a2: 1);
      }
    }
  }
  CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RemoveAll(this: &this->m_Bitmaps);
  v6 = 1;
  for ( i = 1; v6 < this->m_Schemes.m_Size; i = v6 )
  {
    v7 = this->m_Schemes.m_Memory.m_pMemory[v6];
    v8 = 0;
    v7->m_bActive = false;
    if ( v7->m_BorderList.m_Size > 0 )
    {
      v9 = 0;
      v15 = 0;
      do
      {
        m_pMemory = v7->m_BorderList.m_Memory.m_pMemory;
        if ( !*(&m_pMemory->bSharedBorder + v9) )
          free(pMem: *(void **)((char *)&m_pMemory->border + v9));
        ++v8;
        v9 = v15 + 12;
        v15 += 12;
      }
      while ( v8 < v7->m_BorderList.m_Size );
    }
    v7->m_pBaseBorder = nullptr;
    v7->m_BorderList.m_Size = 0;
    v7->m_pkvBorders = nullptr;
    v7->m_FontRanges.m_Size = 0;
    m_pData = v7->m_pData;
    if ( m_pData != nullptr )
    {
      KeyValues::deleteThis(this: m_pData);
      v7->m_pData = nullptr;
    }
    v6 = i + 1;
  }
  CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RemoveAll(this: &this->m_Bitmaps);
  this->m_Bitmaps.m_FirstFree = -1;
  if ( this->m_Bitmaps.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Bitmaps.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Bitmaps.m_Elements.m_pMemory);
      this->m_Bitmaps.m_Elements.m_pMemory = nullptr;
    }
    this->m_Bitmaps.m_Elements.m_nAllocationCount = 0;
  }
  this->m_Bitmaps.m_LastAlloc.index = -1;
  if ( this->m_Bitmaps.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Bitmaps.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Bitmaps.m_Elements.m_pMemory);
      this->m_Bitmaps.m_Elements.m_pMemory = nullptr;
    }
    this->m_Bitmaps.m_Elements.m_nAllocationCount = 0;
  }
  v12 = this->m_Schemes.m_Memory.m_nGrowSize < 0;
  this->m_Schemes.m_Size = 0;
  if ( !v12 )
  {
    if ( this->m_Schemes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Schemes.m_Memory.m_pMemory);
      this->m_Schemes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Schemes.m_Memory.m_nAllocationCount = 0;
  }
  v12 = this->m_Schemes.m_Memory.m_nGrowSize < 0;
  v13 = this->m_Schemes.m_Memory.m_pMemory;
  this->m_Schemes.m_pElements = v13;
  if ( !v12 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      this->m_Schemes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Schemes.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CSchemeManager_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10009F70
// Name: public: void CScheme::SetFontRange(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheme::SetFontRange(CScheme *this, const char *fontname, int nMin, int nMax)
{
  int v5; // edi
  int v6; // ebx
  const char *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::IScheme::fontrange_t *m_pMemory; // ecx
  int v11; // eax
  int v12; // edi
  vgui::IScheme::fontrange_t *v13; // eax
  int v14; // eax
  const char *v15; // [esp-4h] [ebp-10h]

  v5 = 0;
  if ( this->m_FontRanges.m_Size <= 0 )
  {
LABEL_5:
    m_Size = this->m_FontRanges.m_Size;
    m_nAllocationCount = this->m_FontRanges.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CScheme::SchemeBorder_t,int>::Grow(
        this: (CUtlMemory<CFontAmalgam::TFontRange,int> *)&this->m_FontRanges,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_FontRanges.m_Size;
    m_pMemory = this->m_FontRanges.m_Memory.m_pMemory;
    v11 = this->m_FontRanges.m_Size - m_Size - 1;
    this->m_FontRanges.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v11);
    v12 = m_Size;
    v13 = &this->m_FontRanges.m_Memory.m_pMemory[v12];
    if ( v13 != nullptr )
      v13->_fontName.m_Id = -1;
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&fontname + 1, pStr: fontname);
    this->m_FontRanges.m_Memory.m_pMemory[v12]._fontName.m_Id = HIWORD(fontname);
    this->m_FontRanges.m_Memory.m_pMemory[v12]._min = nMin;
    this->m_FontRanges.m_Memory.m_pMemory[v12]._max = nMax;
  }
  else
  {
    v6 = 0;
    while ( 1 )
    {
      v15 = fontname;
      v7 = CUtlSymbol::String(this: &this->m_FontRanges.m_Memory.m_pMemory[v6]._fontName);
      if ( _V_stricmp(s1: v7, s2: v15) == 0 )
        break;
      ++v5;
      ++v6;
      if ( v5 >= this->m_FontRanges.m_Size )
        goto LABEL_5;
    }
    v14 = v5;
    this->m_FontRanges.m_Memory.m_pMemory[v14]._min = nMin;
    this->m_FontRanges.m_Memory.m_pMemory[v14]._max = nMax;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A070
// Name: private: void CScheme::AddFontHelper(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheme::AddFontHelper(CScheme *this, const char *kvfontname, const char *proportional)
{
  const char *v4; // eax
  unsigned __int8 v5; // bl
  char *MungedFontName; // eax
  vgui::ISchemeManager_vtbl *v7; // edx
  int v8; // eax
  int v9; // edi
  const char *v10; // edx
  __int16 font; // [esp+Ch] [ebp-4h]

  v4 = CUtlString::Get(this: &this->m_tag);
  v5 = (unsigned __int8)proportional;
  MungedFontName = CScheme::GetMungedFontName(this, fontName: kvfontname, scheme: v4, (bool)proportional);
  v7 = vgui::g_pSchemeManager->__vftable;
  proportional = MungedFontName;
  v8 = (int)v7->GetSurface(this: vgui::g_pSchemeManager);
  font = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 32))(a1: v8);
  v9 = CUtlVector<vgui::IScheme::fontalias_t,CUtlMemory<vgui::IScheme::fontalias_t,int>>::InsertBefore(
         this: &this->m_FontAliases,
         elem: this->m_FontAliases.m_Size);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&proportional + 1, pStr: proportional);
  v10 = kvfontname;
  v9 *= 6;
  *(unsigned __int16 *)((char *)&this->m_FontAliases.m_Memory.m_pMemory->_fontName.m_Id + v9) = HIWORD(proportional);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&kvfontname + 1, pStr: v10);
  *(unsigned __int16 *)((char *)&this->m_FontAliases.m_Memory.m_pMemory->_trueFontName.m_Id + v9) = HIWORD(kvfontname);
  *(_WORD *)((char *)this->m_FontAliases.m_Memory.m_pMemory + v9 + 4) ^= (font
                                                                        ^ *(_WORD *)((char *)this->m_FontAliases.m_Memory.m_pMemory
                                                                                   + v9
                                                                                   + 4))
                                                                       & 0x7FFF;
  *(_WORD *)((char *)this->m_FontAliases.m_Memory.m_pMemory + v9 + 4) = *(_WORD *)((char *)this->m_FontAliases.m_Memory.m_pMemory
                                                                                 + v9
                                                                                 + 4)
                                                                      & 0x7FFF
                                                                      | (v5 << 15);
}

//------------------------------------------------------------------------------
// Address: 0x1000A140
// Name: private: void CScheme::LoadBorders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheme::LoadBorders(CScheme *this)
{
  CScheme *v1; // ebx
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<CScheme::SchemeBorder_t,CUtlMemory<CScheme::SchemeBorder_t,int> > *p_m_BorderList; // esi
  CScheme::SchemeBorder_t *m_pMemory; // ecx
  int v8; // eax
  const char *String; // eax
  const char *v10; // ebx
  ImageBorder *v11; // eax
  ImageBorder *v12; // edi
  ScalableImageBorder *v13; // eax
  vgui::Border *v14; // eax
  ImageBorder_vtbl *v15; // ebx
  const char *Name; // eax
  int v17; // eax
  int v18; // esi
  KeyValues *v19; // edi
  CScheme_vtbl *v20; // esi
  const char *v21; // eax
  int v22; // eax
  int v23; // edi
  int v24; // eax
  CScheme::SchemeBorder_t *v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // esi
  int border; // [esp+Ch] [ebp-Ch]
  vgui::Border *bordera; // [esp+Ch] [ebp-Ch]
  KeyValues *kv; // [esp+14h] [ebp-4h]
  KeyValues *kva; // [esp+14h] [ebp-4h]

  v1 = this;
  Key = KeyValues::FindKey(this: this->m_pData, keyName: "Borders", bCreate: true);
  v1->m_pkvBorders = Key;
  FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
  kv = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      if ( KeyValues::GetDataType(this: FirstSubKey, keyName: nullptr) == TYPE_STRING )
        goto LABEL_23;
      m_Size = v1->m_BorderList.m_Size;
      m_nAllocationCount = v1->m_BorderList.m_Memory.m_nAllocationCount;
      p_m_BorderList = &v1->m_BorderList;
      border = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CScheme::SchemeBorder_t,int>::Grow(
          this: (CUtlMemory<CFontAmalgam::TFontRange,int> *)&v1->m_BorderList,
          num: m_Size - m_nAllocationCount + 1);
      ++v1->m_BorderList.m_Size;
      m_pMemory = p_m_BorderList->m_Memory.m_pMemory;
      v8 = v1->m_BorderList.m_Size - m_Size - 1;
      v1->m_BorderList.m_pElements = v1->m_BorderList.m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v8);
      String = KeyValues::GetString(this: kv, keyName: "bordertype", defaultValue: nullptr);
      v10 = String;
      if ( String == nullptr || *String == 0 )
      {
LABEL_19:
        v14 = (vgui::Border *)operator new(nSize: 0x3Cu);
        if ( v14 != nullptr )
          v12 = (ImageBorder *)vgui::Border::Border(this: v14);
        else
          v12 = nullptr;
        goto LABEL_22;
      }
      if ( _V_stricmp(s1: String, s2: "image") != 0 )
      {
        if ( _V_stricmp(s1: v10, s2: "scalable_image") != 0 )
          goto LABEL_19;
        v13 = (ScalableImageBorder *)operator new(nSize: 0x44u);
        if ( v13 != nullptr )
        {
          v12 = (ImageBorder *)ScalableImageBorder::ScalableImageBorder(this: v13);
          goto LABEL_18;
        }
      }
      else
      {
        v11 = (ImageBorder *)operator new(nSize: 0x2Cu);
        if ( v11 != nullptr )
        {
          v12 = ImageBorder::ImageBorder(this: v11);
          goto LABEL_18;
        }
      }
      v12 = nullptr;
LABEL_18:
      if ( *v10 == 0 )
        goto LABEL_19;
LABEL_22:
      v15 = v12->__vftable;
      Name = KeyValues::GetName(this: kv);
      v15->SetName(this: v12, a2: Name);
      v12->ApplySchemeSettings(this: v12, a2: this, a3: kv);
      v17 = border;
      p_m_BorderList->m_Memory.m_pMemory[v17].border = v12;
      p_m_BorderList->m_Memory.m_pMemory[v17].bSharedBorder = false;
      v18 = (int)&p_m_BorderList->m_Memory.m_pMemory[border];
      v1 = this;
      *(_DWORD *)(v18 + 4) = KeyValues::GetNameSymbol(this: kv);
      FirstSubKey = kv;
LABEL_23:
      kv = KeyValues::GetNextKey(this: FirstSubKey);
      if ( kv == nullptr )
        break;
      FirstSubKey = kv;
    }
  }
  v19 = KeyValues::GetFirstSubKey(this: v1->m_pkvBorders);
  kva = v19;
  if ( v19 != nullptr )
  {
    while ( 1 )
    {
      if ( KeyValues::GetDataType(this: v19, keyName: nullptr) == TYPE_STRING )
      {
        v20 = v1->__vftable;
        v21 = KeyValues::GetString(this: v19, keyName: nullptr, defaultValue: pHelpString);
        v22 = (int)v20->GetBorder(this: v1, a2: v21);
        v23 = v1->m_BorderList.m_Size;
        bordera = (vgui::Border *)v22;
        v24 = v1->m_BorderList.m_Memory.m_nAllocationCount;
        if ( v23 + 1 > v24 )
          CUtlMemory<CScheme::SchemeBorder_t,int>::Grow(
            this: (CUtlMemory<CFontAmalgam::TFontRange,int> *)&v1->m_BorderList,
            num: v23 - v24 + 1);
        ++v1->m_BorderList.m_Size;
        v25 = v1->m_BorderList.m_Memory.m_pMemory;
        v26 = v1->m_BorderList.m_Size - v23 - 1;
        v1->m_BorderList.m_pElements = v25;
        if ( v26 > 0 )
          _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 12 * v26);
        v27 = v23;
        v1->m_BorderList.m_Memory.m_pMemory[v27].border = bordera;
        v1->m_BorderList.m_Memory.m_pMemory[v27].bSharedBorder = true;
        v28 = (int)&v1->m_BorderList.m_Memory.m_pMemory[v23];
        v19 = kva;
        *(_DWORD *)(v28 + 4) = KeyValues::GetNameSymbol(this: kva);
      }
      kva = KeyValues::GetNextKey(this: v19);
      if ( kva == nullptr )
        break;
      v19 = kva;
    }
  }
  v1->m_pBaseBorder = v1->GetBorder(this: v1, a2: "BaseBorder");
}

//------------------------------------------------------------------------------
// Address: 0x1000A6A0
// Name: private: void CScheme::AddCriticalFont(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheme::AddCriticalFont(CScheme *this, const char *pFontName, KeyValues *pKV)
{
  int v4; // esi
  int v5; // ebx
  const char *v6; // eax
  int v7; // esi
  const char *String; // eax
  CScheme::CriticalFont_t *m_pMemory; // edi
  CScheme::CriticalFont_t *pFontNamea; // [esp+14h] [ebp+8h]

  v4 = this->m_CriticalFonts.m_Size - 1;
  if ( v4 >= 0 )
  {
    v5 = v4;
    do
    {
      v6 = CUtlString::Get(this: &this->m_CriticalFonts.m_Memory.m_pMemory[v5].m_FontName);
      if ( _V_stricmp(s1: v6, s2: pFontName) == 0 )
        break;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  if ( v4 == -1 )
    v4 = CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int>>::InsertBefore(
           this: &this->m_CriticalFonts,
           elem: this->m_CriticalFonts.m_Size);
  v7 = v4;
  CUtlString::operator=(this: &this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_FontName, src: pFontName);
  this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_bCommonChars = KeyValues::GetInt(
                                                                  this: pKV,
                                                                  keyName: "commonchars",
                                                                  defaultValue: 0) != 0;
  this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_bUppercase = KeyValues::GetInt(
                                                                this: pKV,
                                                                keyName: "uppercase",
                                                                defaultValue: 0) != 0;
  this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_bLowercase = KeyValues::GetInt(
                                                                this: pKV,
                                                                keyName: "lowercase",
                                                                defaultValue: 0) != 0;
  this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_bNumbers = KeyValues::GetInt(
                                                              this: pKV,
                                                              keyName: "numbers",
                                                              defaultValue: 0) != 0;
  this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_bPunctuation = KeyValues::GetInt(
                                                                  this: pKV,
                                                                  keyName: "punctuation",
                                                                  defaultValue: 0) != 0;
  this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_bExtendedChars = KeyValues::GetInt(
                                                                    this: pKV,
                                                                    keyName: "extendedchars",
                                                                    defaultValue: 0) != 0;
  this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_bAsianChars = KeyValues::GetInt(
                                                                 this: pKV,
                                                                 keyName: "asianchars",
                                                                 defaultValue: 0) != 0;
  this->m_CriticalFonts.m_Memory.m_pMemory[v7].m_bSkipIfAsian = KeyValues::GetInt(
                                                                  this: pKV,
                                                                  keyName: "skipifasian",
                                                                  defaultValue: 1) != 0;
  pFontNamea = &this->m_CriticalFonts.m_Memory.m_pMemory[v7];
  String = KeyValues::GetString(this: pKV, keyName: "explicit", defaultValue: pHelpString);
  CUtlString::operator=(this: &pFontNamea->m_ExplicitChars, src: String);
  m_pMemory = this->m_CriticalFonts.m_Memory.m_pMemory;
  m_pMemory[v7].m_bRussianChars = KeyValues::GetString(this: pKV, keyName: "russianchars", defaultValue: pHelpString) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000A960
// Name: public: virtual class vgui::IImage __near * CSchemeManager::GetImage(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Bitmap *__thiscall CSchemeManager::GetImage(CSchemeManager *this, const char *imageName, bool hardwareFiltered)
{
  const char *v3; // esi
  int v5; // eax
  int v6; // esi
  vgui::Bitmap *v8; // eax
  char szFileName[256]; // [esp+8h] [ebp-104h] BYREF
  CSchemeManager::CachedBitmapHandle_t searchBitmap; // [esp+108h] [ebp-4h] BYREF

  v3 = imageName;
  if ( imageName == nullptr || strlen(imageName) == 0 )
    return nullptr;
  searchBitmap.pBitmap = nullptr;
  if ( V_stristr(pStr: imageName, pSearch: ".pic") != nullptr )
    V_snprintf(pDest: szFileName, maxLen: 256, pFormat: "%s", v3);
  else
    V_snprintf(pDest: szFileName, maxLen: 256, pFormat: "vgui/%s", v3);
  CSchemeManager::s_pszSearchString = szFileName;
  v5 = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Find(
         this: &this->m_Bitmaps,
         search: &searchBitmap);
  v6 = v5;
  if ( v5 >= 0
    && v5 < this->m_Bitmaps.m_Elements.m_nAllocationCount
    && v5 <= this->m_Bitmaps.m_LastAlloc.index
    && CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LeftChild(
         this: &this->m_Bitmaps,
         i: v5) != v5 )
  {
    return this->m_Bitmaps.m_Elements.m_pMemory[v6].m_Data.pBitmap;
  }
  v8 = (vgui::Bitmap *)operator new(nSize: 0x34u);
  if ( v8 != nullptr )
    imageName = (const char *)vgui::Bitmap::Bitmap(this: v8, filename: szFileName, hardwareFiltered);
  else
    imageName = nullptr;
  CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Insert(
    this: &this->m_Bitmaps,
    insert: (const CSchemeManager::CachedBitmapHandle_t *)&imageName);
  return (vgui::Bitmap *)imageName;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA90
// Name: public: virtual bool CSchemeManager::DeleteImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSchemeManager::DeleteImage(CSchemeManager *this, const char *pImageName)
{
  const char *v2; // esi
  CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *p_m_Bitmaps; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // edi
  vgui::Bitmap *pBitmap; // ecx
  vgui::Bitmap *v10; // ecx
  const char *v11; // [esp-8h] [ebp-114h]
  char szFileName[256]; // [esp+8h] [ebp-104h] BYREF
  CSchemeManager *v13; // [esp+108h] [ebp-4h]

  v2 = pImageName;
  v13 = this;
  if ( pImageName == nullptr )
    return 0;
  v11 = pImageName;
  pImageName = nullptr;
  if ( V_stristr(pStr: v11, pSearch: ".pic") != nullptr )
    V_snprintf(pDest: szFileName, maxLen: 256, pFormat: "%s", v2);
  else
    V_snprintf(pDest: szFileName, maxLen: 256, pFormat: "vgui/%s", v2);
  p_m_Bitmaps = &this->m_Bitmaps;
  CSchemeManager::s_pszSearchString = szFileName;
  v6 = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Find(
         this: p_m_Bitmaps,
         search: (const CSchemeManager::CachedBitmapHandle_t *)&pImageName);
  v7 = v6;
  if ( v6 < 0
    || v6 >= p_m_Bitmaps->m_Elements.m_nAllocationCount
    || v6 > p_m_Bitmaps->m_LastAlloc.index
    || CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LeftChild(
         this: p_m_Bitmaps,
         i: v6) == v6 )
  {
    return 0;
  }
  v8 = v7;
  pBitmap = v13->m_Bitmaps.m_Elements.m_pMemory[v7].m_Data.pBitmap;
  pBitmap->Evict(this: pBitmap);
  v10 = v13->m_Bitmaps.m_Elements.m_pMemory[v7].m_Data.pBitmap;
  if ( v10 != nullptr )
    ((void (__thiscall *)(vgui::Bitmap *, int))v10->dtr_IImage)(a1: v10, a2: 1);
  if ( v7 != -1 )
  {
    CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Unlink(
      this: p_m_Bitmaps,
      elem: v7);
    p_m_Bitmaps->m_Elements.m_pMemory[v8].m_Left = v7;
    p_m_Bitmaps->m_Elements.m_pMemory[v8].m_Right = p_m_Bitmaps->m_FirstFree;
    --p_m_Bitmaps->m_NumElements;
    p_m_Bitmaps->m_FirstFree = v7;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000ABA0
// Name: private: void CScheme::LoadFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheme::LoadFonts(CScheme *this)
{
  CScheme *v1; // ebx
  bool (__thiscall *GetRegistryString)(vgui::ISystem *, const char *, char *, int); // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  const char *String; // edi
  ISchemeSurface *v6; // eax
  char v7; // bl
  KeyValues *NextKey; // esi
  const char *Name; // edi
  KeyValues *v10; // eax
  const char *v11; // eax
  int v12; // eax
  ISchemeSurface *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  const char *v16; // eax
  const char *v17; // edi
  ISchemeSurface *v18; // eax
  ISchemeSurface *v19; // ebx
  ISchemeSurface_vtbl *v20; // esi
  const char *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // esi
  const char *v24; // eax
  const char *v25; // edi
  const char *v26; // eax
  int j; // edi
  const char *v28; // eax
  int i; // edi
  const char *v30; // eax
  KeyValues *v31; // eax
  KeyValues *k; // esi
  const char *v33; // eax
  int v34; // [esp-8h] [ebp-68h]
  char language[64]; // [esp+8h] [ebp-58h] BYREF
  const char *pszName; // [esp+48h] [ebp-18h]
  const char *fontFile; // [esp+4Ch] [ebp-14h]
  KeyValues *kv; // [esp+50h] [ebp-10h]
  int nRangeMin; // [esp+54h] [ebp-Ch] BYREF
  int nRangeMax; // [esp+58h] [ebp-8h] BYREF
  CScheme *v41; // [esp+5Ch] [ebp-4h]

  v1 = this;
  GetRegistryString = vgui::g_pSystem->GetRegistryString;
  v41 = this;
  if ( !GetRegistryString(
          this: vgui::g_pSystem,
          a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
          a3: language,
          a4: 63) )
    V_strncpy(pDest: language, pSrc: "english", maxLen: 64);
  Key = KeyValues::FindKey(this: v1->m_pData, keyName: "CustomFontFiles", bCreate: true);
  FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
  kv = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: pHelpString);
      fontFile = String;
      if ( String != nullptr && *String != 0 )
      {
        v6 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
        v6->AddCustomFontFile(this: v6, a2: String);
      }
      else
      {
        nRangeMin = 0;
        nRangeMax = 0;
        pszName = nullptr;
        v7 = 0;
        NextKey = KeyValues::GetFirstSubKey(this: FirstSubKey);
        if ( NextKey != nullptr )
        {
          do
          {
            Name = KeyValues::GetName(this: NextKey);
            if ( _V_stricmp(s1: Name, s2: "font") != 0 )
            {
              if ( _V_stricmp(s1: Name, s2: "name") != 0 )
              {
                if ( _V_stricmp(s1: language, s2: Name) == 0 )
                {
                  v10 = KeyValues::FindKey(this: NextKey, keyName: "range", bCreate: false);
                  if ( v10 != nullptr )
                  {
                    v7 = 1;
                    v11 = KeyValues::GetString(this: v10, keyName: nullptr, defaultValue: pHelpString);
                    sscanf(string: v11, format: "%x %x", &nRangeMin, &nRangeMax);
                    v12 = nRangeMin;
                    if ( nRangeMin > nRangeMax )
                    {
                      nRangeMin = nRangeMax;
                      nRangeMax = v12;
                    }
                  }
                }
              }
              else
              {
                pszName = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: pHelpString);
              }
            }
            else
            {
              fontFile = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: pHelpString);
            }
            NextKey = KeyValues::GetNextKey(this: NextKey);
          }
          while ( NextKey != nullptr );
          String = fontFile;
        }
        if ( String != nullptr && *String != 0 )
        {
          v13 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
          v13->AddCustomFontFile(this: v13, a2: String);
          if ( v7 != 0 )
            CScheme::SetFontRange(this: v41, fontname: pszName, nMin: nRangeMin, nMax: nRangeMax);
        }
        v1 = v41;
        FirstSubKey = kv;
      }
      kv = KeyValues::GetNextKey(this: FirstSubKey);
      if ( kv == nullptr )
        break;
      FirstSubKey = kv;
    }
  }
  v14 = KeyValues::FindKey(this: v1->m_pData, keyName: "BitmapFontFiles", bCreate: true);
  v15 = KeyValues::GetFirstSubKey(this: v14);
  kv = v15;
  if ( v15 != nullptr )
  {
    while ( 1 )
    {
      v16 = KeyValues::GetString(this: v15, keyName: nullptr, defaultValue: pHelpString);
      v17 = v16;
      if ( v16 != nullptr && *v16 != 0 )
      {
        v18 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
        if ( v18->AddBitmapFontFile(this: v18, a2: v17) )
        {
          v19 = vgui::g_pSchemeManager->GetSurface(this: vgui::g_pSchemeManager);
          v20 = v19->__vftable;
          v21 = KeyValues::GetName(this: kv);
          v20->SetBitmapFontName(this: v19, a2: v21, a3: v17);
          v15 = kv;
        }
      }
      kv = KeyValues::GetNextKey(this: v15);
      if ( kv == nullptr )
        break;
      v15 = kv;
    }
    v1 = v41;
  }
  v22 = KeyValues::FindKey(this: v1->m_pData, keyName: "Fonts", bCreate: true);
  v23 = KeyValues::GetFirstSubKey(this: v22);
  if ( v23 != nullptr )
  {
    while ( 1 )
    {
      v24 = KeyValues::GetString(this: v23, keyName: "isproportional", defaultValue: pHelpString);
      v25 = v24;
      if ( v24 == nullptr || *v24 == 0 )
      {
        for ( i = 0; i < 2; ++i )
        {
          v30 = KeyValues::GetName(this: v23);
          CScheme::AddFontHelper(this: v41, kvfontname: v30, proportional: (const char *)(i != 0));
        }
        goto LABEL_48;
      }
      if ( _V_strcmp(s1: v24, s2: "only") != 0 )
      {
        if ( _V_strcmp(s1: v25, s2: "no") != 0 )
        {
          for ( j = 0; j < 2; ++j )
          {
            v28 = KeyValues::GetName(this: v23);
            CScheme::AddFontHelper(this: v41, kvfontname: v28, proportional: (const char *)(j != 0));
          }
          goto LABEL_48;
        }
        v34 = 0;
      }
      else
      {
        v34 = 1;
      }
      v26 = KeyValues::GetName(this: v23);
      CScheme::AddFontHelper(this: v41, kvfontname: v26, proportional: (const char *)v34);
LABEL_48:
      v23 = KeyValues::GetNextKey(this: v23);
      if ( v23 == nullptr )
      {
        v1 = v41;
        break;
      }
    }
  }
  v31 = KeyValues::FindKey(this: v1->m_pData, keyName: "CriticalFonts", bCreate: true);
  for ( k = KeyValues::GetFirstSubKey(this: v31); k != nullptr; k = KeyValues::GetNextKey(this: k) )
  {
    v33 = KeyValues::GetName(this: k);
    if ( v33 != nullptr && *v33 != 0 )
      CScheme::AddCriticalFont(this: v1, pFontName: v33, pKV: k);
  }
  v1->ReloadFontGlyphs(this: v1, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1000AF30
// Name: public: void CScheme::LoadFromFile(unsigned int,char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheme::LoadFromFile(
        CScheme *this,
        unsigned int sizingPanel,
        const char *pFilename,
        const char *inTag,
        KeyValues *inKeys)
{
  const char *v5; // ebx
  char *v7; // eax
  KeyValues *v8; // ecx
  KeyValues *Key; // eax
  KeyValues *m_pData; // ecx
  KeyValues *v11; // eax
  KeyValues *v12; // ecx
  KeyValues *v13; // eax
  const char *v14; // ebx
  const char *v15; // eax
  unsigned int i; // ebx
  const char *v17; // edi
  const char *String; // eax
  const char *v19; // eax

  v5 = pFilename;
  _COM_TimestampedLog(a1: "CScheme::LoadFromFile( %s )", pFilename);
  CUtlString::operator=(this: &this->m_fileName, src: v5);
  v7 = CUtlString::Get(this: &this->m_fileName);
  V_FixSlashes(pname: v7, separator: 92);
  v8 = inKeys;
  this->m_SizingPanel = sizingPanel;
  this->m_pData = v8;
  Key = KeyValues::FindKey(this: v8, keyName: "BaseSettings", bCreate: true);
  m_pData = this->m_pData;
  this->m_pkvBaseSettings = Key;
  v11 = KeyValues::FindKey(this: m_pData, keyName: "Colors", bCreate: true);
  v12 = this->m_pData;
  this->m_pkvColors = v11;
  v13 = KeyValues::FindKey(this: v12, keyName: "Name", bCreate: true);
  v14 = inTag;
  KeyValues::SetString(this: v13, keyName: "Name", value: inTag);
  if ( v14 != nullptr )
  {
    CUtlString::operator=(this: &this->m_tag, src: v14);
  }
  else
  {
    v15 = CUtlString::Get(this: &this->m_fileName);
    _Error(a1: "You need to name the scheme (%s)!", v15);
    CUtlString::operator=(this: &this->m_tag, src: "default");
  }
  for ( i = 0; i < 0x57C; i += 12 )
  {
    if ( KeyValues::FindKey(
           this: this->m_pkvBaseSettings,
           keyName: g_SchemeTranslation[i / 0xC].pchNewEntry,
           bCreate: false) != nullptr )
      continue;
    v17 = off_1004D0CC[i / 4];
    if ( v17 == nullptr )
    {
      String = off_1004D0D0[i / 4];
      goto LABEL_13;
    }
    pFilename = nullptr;
    if ( sscanf(string: v17, format: "%d %d %d %d", &inTag, &inKeys, &sizingPanel, &pFilename) < 3 )
    {
      String = KeyValues::GetString(this: this->m_pkvColors, keyName: v17, defaultValue: nullptr);
      if ( String != nullptr )
        goto LABEL_13;
      v19 = KeyValues::GetString(this: this->m_pkvBaseSettings, keyName: v17, defaultValue: nullptr);
      if ( v19 != nullptr )
      {
        String = CScheme::LookupSchemeSetting(this, pchSetting: v19);
        goto LABEL_13;
      }
    }
    String = v17;
LABEL_13:
    KeyValues::SetString(
      this: this->m_pkvBaseSettings,
      keyName: g_SchemeTranslation[i / 0xC].pchNewEntry,
      value: String);
  }
  CScheme::LoadFonts(this);
  CScheme::LoadBorders(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000B0F0
// Name: public: CScheme::CScheme(void)
// Source: json
//------------------------------------------------------------------------------
CScheme *__thiscall CScheme::CScheme(CScheme *this)
{
  this->__vftable = (CScheme_vtbl *)&CScheme::`vftable';
  CUtlString::CUtlString(this: &this->m_fileName);
  CUtlString::CUtlString(this: &this->m_tag);
  this->m_BorderList.m_Memory.m_pMemory = nullptr;
  this->m_BorderList.m_Memory.m_nAllocationCount = 0;
  this->m_BorderList.m_Memory.m_nGrowSize = 0;
  this->m_BorderList.m_Size = 0;
  this->m_BorderList.m_pElements = nullptr;
  this->m_FontAliases.m_Memory.m_pMemory = nullptr;
  this->m_FontAliases.m_Memory.m_nAllocationCount = 0;
  this->m_FontAliases.m_Memory.m_nGrowSize = 0;
  this->m_FontAliases.m_Size = 0;
  this->m_FontAliases.m_pElements = nullptr;
  this->m_FontRanges.m_Memory.m_pMemory = nullptr;
  this->m_FontRanges.m_Memory.m_nAllocationCount = 0;
  this->m_FontRanges.m_Memory.m_nGrowSize = 0;
  this->m_FontRanges.m_Size = 0;
  this->m_FontRanges.m_pElements = nullptr;
  this->m_CriticalFonts.m_Memory.m_pMemory = nullptr;
  this->m_CriticalFonts.m_Memory.m_nAllocationCount = 0;
  this->m_CriticalFonts.m_Memory.m_nGrowSize = 0;
  this->m_CriticalFonts.m_Size = 0;
  this->m_CriticalFonts.m_pElements = nullptr;
  this->m_pData = nullptr;
  this->m_pkvBaseSettings = nullptr;
  this->m_pkvColors = nullptr;
  this->m_pBaseBorder = nullptr;
  this->m_pkvBorders = nullptr;
  this->m_SizingPanel = 0;
  this->m_nLastLoadedLanguage = 0;
  this->m_bActive = false;
  this->m_nScreenWide = -1;
  this->m_nScreenTall = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000B190
// Name: public: virtual char const __near * CScheme::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CScheme::GetName(CScheme *this)
{
  return CUtlString::Get(this: &this->m_tag);
}

//------------------------------------------------------------------------------
// Address: 0x1000B1A0
// Name: public: virtual char const __near * CScheme::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CScheme::GetFileName(CScheme *this)
{
  return CUtlString::Get(this: &this->m_fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1000B1B0
// Name: public: virtual CScheme::~CScheme(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheme::~CScheme(CScheme *this)
{
  CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int>>::~CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int>>(this: &this->m_CriticalFonts);
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&this->m_FontRanges);
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&this->m_FontAliases);
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&this->m_BorderList);
  this->m_tag.m_Storage.m_nActualLength = 0;
  if ( this->m_tag.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_tag.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_tag.m_Storage.m_Memory.m_pMemory);
      this->m_tag.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_tag.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_fileName.m_Storage.m_nActualLength = 0;
  if ( this->m_fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_fileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_fileName.m_Storage.m_Memory.m_pMemory);
      this->m_fileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CScheme_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1000B230
// Name: public: CSchemeManager::CSchemeManager(void)
// Source: json
//------------------------------------------------------------------------------
CSchemeManager *__thiscall CSchemeManager::CSchemeManager(CSchemeManager *this)
{
  CScheme *v2; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CScheme **m_pMemory; // ecx
  int v6; // eax
  CScheme **v7; // ebx
  CSchemeManager *result; // eax
  CScheme *nullScheme; // [esp+Ch] [ebp-4h]

  this->__vftable = (CSchemeManager_vtbl *)&CSchemeManager::`vftable';
  this->m_Schemes.m_Memory.m_pMemory = nullptr;
  this->m_Schemes.m_Memory.m_nAllocationCount = 0;
  this->m_Schemes.m_Memory.m_nGrowSize = 0;
  this->m_Schemes.m_Size = 0;
  this->m_Schemes.m_pElements = nullptr;
  this->m_Bitmaps.m_LessFunc = nullptr;
  this->m_Bitmaps.m_Elements.m_pMemory = nullptr;
  this->m_Bitmaps.m_Elements.m_nAllocationCount = 0;
  this->m_Bitmaps.m_Elements.m_nGrowSize = 0;
  this->m_Bitmaps.m_Root = -1;
  this->m_Bitmaps.m_FirstFree = -1;
  this->m_Bitmaps.m_NumElements = 0;
  this->m_Bitmaps.m_LastAlloc.index = -1;
  this->m_Bitmaps.m_pElements = this->m_Bitmaps.m_Elements.m_pMemory;
  v2 = (CScheme *)operator new(nSize: 0x9Cu);
  if ( v2 != nullptr )
    nullScheme = CScheme::CScheme(this: v2);
  else
    nullScheme = nullptr;
  m_Size = this->m_Schemes.m_Size;
  m_nAllocationCount = this->m_Schemes.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CWin32Font *,int> *)&this->m_Schemes,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Schemes.m_Size;
  m_pMemory = this->m_Schemes.m_Memory.m_pMemory;
  v6 = this->m_Schemes.m_Size - m_Size - 1;
  this->m_Schemes.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Schemes.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = nullScheme;
  result = this;
  if ( this->m_Bitmaps.m_LessFunc == nullptr )
    this->m_Bitmaps.m_LessFunc = CSchemeManager::BitmapHandleSearchFunc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B300
// Name: public: virtual unsigned long CSchemeManager::LoadSchemeFromFileEx(unsigned int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSchemeManager::LoadSchemeFromFileEx(
        CSchemeManager *this,
        unsigned int sizingPanel,
        const char *pFilename,
        const char *tag)
{
  const char *v4; // esi
  int LoadedScheme; // eax
  const char *m_pszHelpString; // edi
  CScheme *v8; // eax
  bool v9; // zf
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  IBaseFileSystem *v13; // eax
  IBaseFileSystem *v14; // eax
  IBaseFileSystem *v15; // eax
  CScheme *v16; // eax
  ConVar *m_pConVarState; // esi
  int v18; // eax
  ConCommandBase *m_pNext; // ecx
  int v20; // eax
  CScheme **v21; // eax
  CScheme *v22; // ecx
  ConVarRef cl_hud_minmode; // [esp+Ch] [ebp-Ch] BYREF
  CScheme *pScheme; // [esp+14h] [ebp-4h]

  v4 = pFilename;
  cl_hud_minmode.m_pConVarState = (ConVar *)this;
  LoadedScheme = CSchemeManager::FindLoadedScheme(this, pFilename);
  m_pszHelpString = (const char *)LoadedScheme;
  pScheme = nullptr;
  if ( LoadedScheme == 0
    || (v8 = this->m_Schemes.m_Memory.m_pMemory[LoadedScheme],
        v9 = !v8->m_bActive,
        pScheme = this->m_Schemes.m_Memory.m_pMemory[(_DWORD)m_pszHelpString],
        v9) )
  {
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "Scheme");
    else
      v12 = nullptr;
    KeyValues::UsesEscapeSequences(this: v12, state: true);
    if ( g_pFullFileSystem != nullptr )
      v13 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v13 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v12,
           filesystem: v13,
           resourceName: pFilename,
           pathID: "SKIN",
           pfnEvaluateSymbolProc: nullptr)
      || (g_pFullFileSystem == nullptr ? (v14 = nullptr) : (v14 = &g_pFullFileSystem->IBaseFileSystem),
          KeyValues::LoadFromFile(
            this: v12,
            filesystem: v14,
            resourceName: pFilename,
            pathID: "GAME",
            pfnEvaluateSymbolProc: nullptr)
       || (g_pFullFileSystem == nullptr ? (v15 = nullptr) : (v15 = &g_pFullFileSystem->IBaseFileSystem),
           KeyValues::LoadFromFile(
             this: v12,
             filesystem: v15,
             resourceName: pFilename,
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr))) )
    {
      if ( m_pszHelpString == nullptr )
      {
        v16 = (CScheme *)operator new(nSize: 0x9Cu);
        if ( v16 != nullptr )
          pScheme = CScheme::CScheme(this: v16);
        else
          pScheme = nullptr;
        m_pConVarState = cl_hud_minmode.m_pConVarState;
        m_pszHelpString = cl_hud_minmode.m_pConVarState->m_pszHelpString;
        v18 = *(_DWORD *)&cl_hud_minmode.m_pConVarState->m_bRegistered;
        if ( (int)(m_pszHelpString + 1) > v18 )
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CWin32Font *,int> *)&cl_hud_minmode.m_pConVarState->m_pNext,
            num: (int)&m_pszHelpString[-v18 + 1]);
        ++cl_hud_minmode.m_pConVarState->m_pszHelpString;
        m_pNext = m_pConVarState->m_pNext;
        v20 = m_pConVarState->m_pszHelpString - m_pszHelpString - 1;
        m_pConVarState->m_nFlags = (int)m_pNext;
        if ( v20 > 0 )
          _V_memmove(
            dest: &m_pNext->m_pNext + (_DWORD)m_pszHelpString,
            src: &m_pNext->__vftable + (_DWORD)m_pszHelpString,
            count: 4 * v20);
        v21 = (CScheme **)(&m_pConVarState->m_pNext->ConCommandBase::__vftable + (_DWORD)m_pszHelpString);
        if ( v21 != nullptr )
          *v21 = pScheme;
        v4 = pFilename;
      }
      ConVarRef::ConVarRef(this: &cl_hud_minmode, pName: "cl_hud_minmode", bIgnoreMissing: true);
      if ( ConVarRef::IsValid(this: &cl_hud_minmode) && cl_hud_minmode.m_pConVarState->m_Value.m_nValue != 0 )
        KeyValues::ProcessResolutionKeys(this: v12, pResString: "_minmode");
      v22 = pScheme;
      pScheme->m_bActive = true;
      CScheme::LoadFromFile(this: v22, sizingPanel, pFilename: v4, inTag: tag, inKeys: v12);
      return m_pszHelpString;
    }
    else
    {
      KeyValues::deleteThis(this: v12);
      return nullptr;
    }
  }
  else
  {
    v8->ReloadFontGlyphs(this: v8, a2: -1);
    return m_pszHelpString;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100155B0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                       this: _g_pMemAlloc,
                                                                                       a2: m_pMemory,
                                                                                       a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                       this: _g_pMemAlloc,
                                                                                       a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100071A0
// Name: __CreateCSchemeManagerISchemeManager_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSchemeManager *__cdecl _CreateCSchemeManagerISchemeManager_interface()
{
  return &g_Scheme;
}
