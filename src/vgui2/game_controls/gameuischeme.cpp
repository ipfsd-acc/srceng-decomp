// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuischeme.cpp
// Functions: 27
// ============================================================

#include "vgui2\game_controls\gameuischeme.h"

//------------------------------------------------------------------------------
// Address: 0x00411E30
// Name: public: virtual void CGameUISchemeManager::SetLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISchemeManager::SetLanguage(CGameUISchemeManager *this, const char *pLanguage)
{
  g_pGameUISystemSurface->SetLanguage(this: g_pGameUISystemSurface, a2: pLanguage);
}

//------------------------------------------------------------------------------
// Address: 0x00411E40
// Name: public: virtual char const __near * CGameUISchemeManager::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUISchemeManager::GetLanguage(CGameUISchemeManager *this)
{
  return g_pGameUISystemSurface->GetLanguage(this: g_pGameUISystemSurface);
}

//------------------------------------------------------------------------------
// Address: 0x00411E50
// Name: private: char const __near * CGameUIScheme::GetMungedFontName(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CGameUIScheme::GetMungedFontName(
        CGameUIScheme *this,
        const char *fontName,
        const char *scheme,
        bool proportional)
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
// Address: 0x00411EC0
// Name: private: int CGameUIScheme::GetMinimumFontHeightForCurrentLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameUIScheme::GetMinimumFontHeightForCurrentLanguage(CGameUIScheme *this, const char *pLanguage)
{
  char language[68]; // [esp+8h] [ebp-44h] BYREF

  if ( pLanguage != nullptr )
  {
    V_strncpy(pDest: &language[4], pSrc: pLanguage, maxLen: 63);
  }
  else if ( !g_pVGuiSystem->GetRegistryString(
               this: g_pVGuiSystem,
               a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
               a3: &language[4],
               a4: 63) )
  {
    return 0;
  }
  if ( _V_stricmp(s1: &language[4], s2: "korean") == 0
    || _V_stricmp(s1: &language[4], s2: "koreana") == 0
    || _V_stricmp(s1: &language[4], s2: "tchinese") == 0
    || _V_stricmp(s1: &language[4], s2: "schinese") == 0
    || _V_stricmp(s1: &language[4], s2: "japanese") == 0 )
  {
    return 13;
  }
  if ( _V_stricmp(s1: &language[4], s2: "thai") == 0 )
    return 18;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00411FA0
// Name: public: void CUtlMemory<struct CGameUIScheme::fontalias_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CGameUIScheme::fontalias_t,int>::Grow(
        CUtlMemory<CGameUIScheme::fontalias_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CGameUIScheme::fontalias_t *m_pMemory; // edx
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
      this->m_pMemory = (CGameUIScheme::fontalias_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CGameUIScheme::fontalias_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412030
// Name: private: class IGameUIScheme __near * CGameUISchemeManager::FindLoadedScheme(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameUIScheme *__thiscall CGameUISchemeManager::FindLoadedScheme(CGameUISchemeManager *this, const char *pFilename)
{
  int v3; // esi
  CGameUIScheme *v4; // ecx
  const char *v5; // eax

  v3 = 1;
  if ( this->m_Schemes.m_Size <= 1 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_Schemes.m_Memory.m_pMemory[v3];
    v5 = v4->GetFileName(this: v4);
    if ( _V_stricmp(s1: v5, s2: pFilename) == 0 )
      break;
    if ( ++v3 >= this->m_Schemes.m_Size )
      return nullptr;
  }
  return this->m_Schemes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x00412080
// Name: public: virtual class IGameUIScheme __near * CGameUISchemeManager::GetDefaultScheme(void)
// Source: json
//------------------------------------------------------------------------------
CGameUIScheme *__thiscall CGameUISchemeManager::GetDefaultScheme(CGameUISchemeManager *this)
{
  int m_Size; // eax

  m_Size = this->m_Schemes.m_Size;
  if ( m_Size >= 2 )
    return this->m_Schemes.m_Memory.m_pMemory[1];
  if ( m_Size <= 0 )
    return nullptr;
  return *this->m_Schemes.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x004120A0
// Name: public: virtual class IGameUIScheme __near * CGameUISchemeManager::GetScheme(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameUIScheme *__thiscall CGameUISchemeManager::GetScheme(CGameUISchemeManager *this, const char *tag)
{
  int v3; // esi
  CGameUIScheme *v4; // ecx
  const char *v5; // eax

  v3 = 1;
  if ( this->m_Schemes.m_Size <= 1 )
    return (CGameUIScheme *)this->GetDefaultScheme(this);
  while ( 1 )
  {
    v4 = this->m_Schemes.m_Memory.m_pMemory[v3];
    v5 = (const char *)v4->GetName(this: v4);
    if ( _V_stricmp(s1: tag, s2: v5) == 0 )
      break;
    if ( ++v3 >= this->m_Schemes.m_Size )
      return (CGameUIScheme *)this->GetDefaultScheme(this);
  }
  return this->m_Schemes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x004120F0
// Name: public: bool CGameUIScheme::GetFontRange(char const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIScheme::GetFontRange(CGameUIScheme *this, const char *fontname, int *nMin, int *nMax)
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
// Address: 0x00412160
// Name: public: void CGameUIScheme::ReloadFontGlyphs(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameUIScheme::ReloadFontGlyphs(CGameUIScheme *this@<ecx>, int a2@<esi>, int inScreenTall)
{
  CGameUIScheme *v3; // ebx
  const char *v4; // eax
  int MinimumFontHeightForCurrentLanguage; // eax
  KeyValues *m_pData; // ecx
  KeyValues *Key; // eax
  bool v8; // cc
  const char *v9; // eax
  KeyValues *v10; // eax
  KeyValues *FirstSubKey; // esi
  char *String; // eax
  int v13; // ecx
  int Int; // ebp
  int v15; // edi
  CGameUISystemSurface_vtbl *v16; // ebp
  CGameUIScheme::fontalias_t *v17; // edi
  const char *v18; // eax
  int v19; // eax
  const char *v20; // eax
  char FontRange; // al
  CGameUIScheme::fontalias_t *v22; // edi
  CGameUISystemSurface_vtbl *v23; // ebx
  const char *v24; // eax
  int v25; // [esp+8h] [ebp-74h]
  int v26; // [esp+Ch] [ebp-70h]
  int v27; // [esp+10h] [ebp-6Ch]
  int v28; // [esp+14h] [ebp-68h]
  float v29; // [esp+18h] [ebp-64h]
  int v30; // [esp+18h] [ebp-64h]
  int defaultValue; // [esp+1Ch] [ebp-60h]
  int fontYResMax; // [esp+30h] [ebp-4Ch]
  int scanlines; // [esp+34h] [ebp-48h] BYREF
  int fontYResMin; // [esp+38h] [ebp-44h]
  int screenTall; // [esp+3Ch] [ebp-40h] BYREF
  int scaley; // [esp+40h] [ebp-3Ch] BYREF
  float scalex; // [esp+44h] [ebp-38h]
  int blur; // [esp+48h] [ebp-34h]
  int v39; // [esp+4Ch] [ebp-30h]
  int nTall; // [esp+50h] [ebp-2Ch] BYREF
  int i; // [esp+54h] [ebp-28h]
  KeyValues *fonts; // [esp+58h] [ebp-24h]
  KeyValues *v43; // [esp+5Ch] [ebp-20h]
  int v44; // [esp+60h] [ebp-1Ch] BYREF
  int v45; // [esp+64h] [ebp-18h] BYREF
  int v46; // [esp+68h] [ebp-14h] BYREF
  int minimumFontHeight; // [esp+6Ch] [ebp-10h] BYREF
  int nRangeMax; // [esp+70h] [ebp-Ch]
  int nRangeMin; // [esp+74h] [ebp-8h] BYREF
  int nMin; // [esp+78h] [ebp-4h] BYREF
  int flags; // [esp+80h] [ebp+4h]

  v3 = this;
  i = (int)this;
  if ( inScreenTall == -1 )
    CGameUISystemMgr::GetScreenHeightForFontLoading(this: g_pGameUISystemMgrImpl, a2, nTall: &scaley);
  else
    scaley = inScreenTall;
  v4 = g_pGameUISystemSurface->GetLanguage(this: g_pGameUISystemSurface);
  MinimumFontHeightForCurrentLanguage = CGameUIScheme::GetMinimumFontHeightForCurrentLanguage(this: v3, pLanguage: v4);
  m_pData = v3->m_pData;
  nRangeMax = MinimumFontHeightForCurrentLanguage;
  Key = KeyValues::FindKey(this: m_pData, keyName: "Fonts", bCreate: true);
  v8 = v3->m_FontAliases.m_Size <= 0;
  v43 = Key;
  fonts = nullptr;
  if ( !v8 )
  {
    fontYResMax = 0;
    do
    {
      v9 = CUtlSymbol::String(this: &v3->m_FontAliases.m_Memory.m_pMemory[fontYResMax]._trueFontName);
      v10 = KeyValues::FindKey(this: v43, keyName: v9, bCreate: true);
      FirstSubKey = KeyValues::GetFirstSubKey(this: v10);
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          screenTall = 0;
          scanlines = 0;
          String = (char *)KeyValues::GetString(this: FirstSubKey, keyName: "yres", defaultValue: ::defaultValue);
          sscanf(string: String, format: "%d %d", &screenTall, &scanlines);
          if ( screenTall == 0 )
            break;
          v13 = scanlines;
          if ( scanlines == 0 )
          {
            v13 = screenTall;
            scanlines = screenTall;
          }
          if ( scaley >= screenTall && scaley <= v13 )
            break;
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          if ( FirstSubKey == nullptr )
            goto LABEL_54;
        }
        flags = KeyValues::GetInt(this: FirstSubKey, keyName: "italic", defaultValue: 0) != 0;
        if ( KeyValues::GetInt(this: FirstSubKey, keyName: "underline", defaultValue: 0) != 0 )
          flags |= 2u;
        if ( KeyValues::GetInt(this: FirstSubKey, keyName: "strikeout", defaultValue: 0) != 0 )
          flags |= 4u;
        if ( KeyValues::GetInt(this: FirstSubKey, keyName: "symbol", defaultValue: 0) != 0 )
          flags |= 8u;
        if ( KeyValues::GetInt(this: FirstSubKey, keyName: "antialias", defaultValue: 0) != 0
          && g_pGameUISystemSurface->SupportsFontFeature(
               this: g_pGameUISystemSurface,
               a2: FONT_FEATURE_ANTIALIASED_FONTS) )
        {
          flags |= 0x10u;
        }
        if ( KeyValues::GetInt(this: FirstSubKey, keyName: "dropshadow", defaultValue: 0) != 0
          && g_pGameUISystemSurface->SupportsFontFeature(
               this: g_pGameUISystemSurface,
               a2: FONT_FEATURE_DROPSHADOW_FONTS) )
        {
          flags |= 0x80u;
        }
        if ( KeyValues::GetInt(this: FirstSubKey, keyName: "outline", defaultValue: 0) != 0
          && g_pGameUISystemSurface->SupportsFontFeature(this: g_pGameUISystemSurface, a2: FONT_FEATURE_OUTLINE_FONTS) )
        {
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
        v15 = KeyValues::GetInt(this: FirstSubKey, keyName: "blur", defaultValue: 0);
        v39 = v15;
        fontYResMin = KeyValues::GetInt(this: FirstSubKey, keyName: "scanlines", defaultValue: 0);
        *(float *)&blur = KeyValues::GetFloat(this: FirstSubKey, keyName: "scalex", defaultValue: 1.0);
        scalex = KeyValues::GetFloat(this: FirstSubKey, keyName: "scaley", defaultValue: 1.0);
        if ( screenTall == 0
          && scanlines == 0
          && *((__int16 *)&v3->m_FontAliases.m_Memory.m_pMemory[fontYResMax] + 2) < 0 )
        {
          if ( scaley == -1 )
            CGameUISystemMgr::GetScreenHeightForFontLoading(this: g_pGameUISystemMgrImpl, a2: (int)FirstSubKey, &nTall);
          else
            nTall = scaley;
          Int = (int)((double)nTall * 0.002083333333333333 * (double)Int);
          CGameUISystemMgr::GetScreenHeightForFontLoading(
            this: g_pGameUISystemMgrImpl,
            a2: (int)FirstSubKey,
            nTall: &v44);
          v39 = (int)((double)v44 * 0.002083333333333333 * (double)v15);
          CGameUISystemMgr::GetScreenHeightForFontLoading(
            this: g_pGameUISystemMgrImpl,
            a2: (int)FirstSubKey,
            nTall: &v45);
          fontYResMin = (int)((double)v45 * 0.002083333333333333 * (double)fontYResMin);
          CGameUISystemMgr::GetScreenHeightForFontLoading(
            this: g_pGameUISystemMgrImpl,
            a2: (int)FirstSubKey,
            nTall: &v46);
          *(float *)&blur = (float)(int)((double)v46
                                       * 0.002083333333333333
                                       * (double)(int)(float)(*(float *)&blur * 10000.0))
                          * 0.000099999997;
          CGameUISystemMgr::GetScreenHeightForFontLoading(
            this: g_pGameUISystemMgrImpl,
            a2: (int)FirstSubKey,
            nTall: &minimumFontHeight);
          scalex = (float)(int)((double)minimumFontHeight * 0.002083333333333333 * (double)(int)(float)(scalex * 10000.0))
                 * 0.000099999997;
        }
        if ( Int > 127 )
          Int = 127;
        if ( Int < nRangeMax )
          Int = nRangeMax;
        if ( (flags & 0x800) != 0 )
        {
          v16 = g_pGameUISystemSurface->__vftable;
          v17 = &v3->m_FontAliases.m_Memory.m_pMemory[fontYResMax];
          v29 = scalex;
          v28 = blur;
          v18 = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: ::defaultValue);
          v19 = ((int (__thiscall *)(CGameUISystemSurface *, const char *, int, _DWORD, int))v16->GetBitmapFontName)(
                  a1: g_pGameUISystemSurface,
                  a2: v18,
                  a3: v28,
                  a4: LODWORD(v29),
                  a5: flags);
          ((void (__thiscall *)(CGameUISystemSurface *, int, int))v16->SetBitmapFontGlyphSet)(
            a1: g_pGameUISystemSurface,
            a2: *((_WORD *)v17 + 2) & 0x7FFF,
            a3: v19);
        }
        else
        {
          v20 = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: ::defaultValue);
          FontRange = CGameUIScheme::GetFontRange(this: v3, fontname: v20, &nMin, nMax: &nRangeMin);
          v22 = &v3->m_FontAliases.m_Memory.m_pMemory[fontYResMax];
          v23 = g_pGameUISystemSurface->__vftable;
          if ( FontRange != 0 )
          {
            defaultValue = nRangeMin;
            v30 = nMin;
          }
          else
          {
            defaultValue = 0;
            v30 = 0;
          }
          v27 = fontYResMin;
          v26 = v39;
          v25 = KeyValues::GetInt(this: FirstSubKey, keyName: "weight", defaultValue: 0);
          v24 = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: ::defaultValue);
          v23->SetFontGlyphSet(
            this: g_pGameUISystemSurface,
            a2: *((_WORD *)v22 + 2) & 0x7FFF,
            a3: v24,
            a4: Int,
            a5: v25,
            a6: v26,
            a7: v27,
            a8: flags,
            a9: v30,
            a10: defaultValue);
          v3 = (CGameUIScheme *)i;
        }
      }
LABEL_54:
      ++fontYResMax;
      v8 = (int)fonts + 1 < v3->m_FontAliases.m_Size;
      fonts = (KeyValues *)((char *)fonts + 1);
    }
    while ( v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004126A0
// Name: private: unsigned long CGameUIScheme::FindFontInAliasList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameUIScheme::FindFontInAliasList(CGameUIScheme *this, const char *fontName)
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
    if ( V_strncasecmp(s1: fontName, s2: v5, n: 64) == 0 )
      break;
    if ( --v3 < 0 )
      return 0;
  }
  return *((_WORD *)&this->m_FontAliases.m_Memory.m_pMemory[v3] + 2) & 0x7FFF;
}

//------------------------------------------------------------------------------
// Address: 0x00412700
// Name: public: virtual char const __near * CGameUIScheme::GetFontName(unsigned long const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUIScheme::GetFontName(CGameUIScheme *this, const unsigned int *font)
{
  int v2; // eax
  CGameUIScheme::fontalias_t *m_pMemory; // esi
  CGameUIScheme::fontalias_t *i; // ecx

  v2 = this->m_FontAliases.m_Size - 1;
  if ( v2 < 0 )
    return "<Unknown font>";
  m_pMemory = this->m_FontAliases.m_Memory.m_pMemory;
  for ( i = (CGameUIScheme::fontalias_t *)((char *)&m_pMemory[v2] + 4); (i->_fontName.m_Id & 0x7FFF) != *font; --i )
  {
    if ( --v2 < 0 )
      return "<Unknown font>";
  }
  return CUtlSymbol::String(this: &m_pMemory[v2]._trueFontName);
}

//------------------------------------------------------------------------------
// Address: 0x00412760
// Name: public: virtual unsigned long CGameUIScheme::GetFont(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameUIScheme::GetFont(CGameUIScheme *this, const char *fontName, bool proportional)
{
  const char *v4; // eax
  char *MungedFontName; // eax

  v4 = CUtlString::Get(this: &this->m_pTag);
  MungedFontName = CGameUIScheme::GetMungedFontName(this, fontName, scheme: v4, proportional);
  return CGameUIScheme::FindFontInAliasList(this, fontName: MungedFontName);
}

//------------------------------------------------------------------------------
// Address: 0x00412790
// Name: public: virtual unsigned long CGameUIScheme::GetFontNextSize(bool,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUIScheme::GetFontNextSize(
        CGameUIScheme *this,
        bool bUp,
        const char *fontName,
        int proportional)
{
  CGameUIScheme *v4; // esi
  const char *result; // eax
  unsigned int v6; // ebp
  const char *v7; // eax
  int v8; // edi
  int v9; // ebx
  unsigned __int16 v10; // ax
  unsigned int v11; // esi
  const char *v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // [esp+18h] [ebp-10h]
  const char *pCurrentFontName; // [esp+20h] [ebp-8h]
  char *s1; // [esp+24h] [ebp-4h]
  int currentFontTall; // [esp+30h] [ebp+8h]

  v4 = this;
  result = (const char *)((int (__stdcall *)(const char *, int))this->GetFont)(a1: fontName, a2: proportional);
  v6 = (unsigned int)result;
  if ( result != nullptr )
  {
    currentFontTall = g_pGameUISystemSurface->GetFontTall(this: g_pGameUISystemSurface, a2: (unsigned int)result);
    v7 = g_pGameUISystemSurface->GetFontName(this: g_pGameUISystemSurface, a2: v6);
    v8 = v4->m_FontAliases.m_Size - 1;
    s1 = (char *)v7;
    v15 = 0x7FFFFFFF;
    pCurrentFontName = nullptr;
    if ( v8 <= 0 )
      return (const char *)v6;
    v9 = v8;
    do
    {
      v10 = *((_WORD *)&v4->m_FontAliases.m_Memory.m_pMemory[v9] + 2);
      if ( (unsigned __int8)proportional == v10 >> 15 )
      {
        v11 = v10 & 0x7FFF;
        v12 = g_pGameUISystemSurface->GetFontName(this: g_pGameUISystemSurface, a2: v11);
        if ( v6 != v11 && _V_stricmp(s1, s2: v12) == 0 )
        {
          v13 = g_pGameUISystemSurface->GetFontTall(this: g_pGameUISystemSurface, a2: v11);
          if ( bUp )
            v14 = v13 - currentFontTall;
          else
            v14 = currentFontTall - v13;
          if ( v14 > 0 && v14 < v15 )
          {
            v15 = v14;
            pCurrentFontName = (const char *)v11;
          }
        }
        v4 = this;
      }
      --v8;
      --v9;
    }
    while ( v8 > 0 );
    result = pCurrentFontName;
    if ( pCurrentFontName == nullptr )
      return (const char *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004128B0
// Name: public: virtual void CGameUISchemeManager::ReloadFonts(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISchemeManager::ReloadFonts(CGameUISchemeManager *this, int inScreenTall)
{
  int i; // esi

  for ( i = 1; i < this->m_Schemes.m_Size; ++i )
    CGameUIScheme::ReloadFontGlyphs(this: this->m_Schemes.m_Memory.m_pMemory[i], a2: i, inScreenTall);
}

//------------------------------------------------------------------------------
// Address: 0x00412950
// Name: public: CGameUIScheme::CGameUIScheme(void)
// Source: json
//------------------------------------------------------------------------------
CGameUIScheme *__thiscall CGameUIScheme::CGameUIScheme(CGameUIScheme *this)
{
  CUtlString *p_m_pFileName; // edi

  p_m_pFileName = &this->m_pFileName;
  this->__vftable = (CGameUIScheme_vtbl *)&CGameUIScheme::`vftable';
  CUtlString::CUtlString(this: &this->m_pFileName);
  CUtlString::CUtlString(this: &this->m_pTag);
  this->m_FontRanges.m_Memory.m_pMemory = nullptr;
  this->m_FontRanges.m_Memory.m_nAllocationCount = 0;
  this->m_FontRanges.m_Memory.m_nGrowSize = 0;
  this->m_FontRanges.m_Size = 0;
  this->m_FontRanges.m_pElements = nullptr;
  this->m_FontAliases.m_Memory.m_pMemory = nullptr;
  this->m_FontAliases.m_Memory.m_nAllocationCount = 0;
  this->m_FontAliases.m_Memory.m_nGrowSize = 0;
  this->m_FontAliases.m_Size = 0;
  this->m_FontAliases.m_pElements = nullptr;
  CUtlString::operator=(this: p_m_pFileName, src: defaultValue);
  CUtlString::operator=(this: &this->m_pTag, src: defaultValue);
  this->m_pData = nullptr;
  this->m_bActive = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004129C0
// Name: public: virtual char const __near * CGameUIScheme::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUIScheme::GetName(CGameUIScheme *this)
{
  return CUtlString::operator char const *(this: &this->m_pTag);
}

//------------------------------------------------------------------------------
// Address: 0x004129D0
// Name: public: virtual char const __near * CGameUIScheme::GetFileName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUIScheme::GetFileName(CGameUIScheme *this)
{
  return CUtlString::operator char const *(this: &this->m_pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x004129E0
// Name: public: CGameUIScheme::~CGameUIScheme(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIScheme::~CGameUIScheme(CGameUIScheme *this)
{
  bool v2; // sf

  this->__vftable = (CGameUIScheme_vtbl *)&CGameUIScheme::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_FontAliases);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_FontRanges);
  v2 = this->m_pTag.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_pTag.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_pTag.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pTag.m_Storage.m_Memory.m_pMemory);
      this->m_pTag.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pTag.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_pFileName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_pFileName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_pFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pFileName.m_Storage.m_Memory.m_pMemory);
      this->m_pFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412A50
// Name: public: CGameUISchemeManager::CGameUISchemeManager(void)
// Source: json
//------------------------------------------------------------------------------
CGameUISchemeManager *__thiscall CGameUISchemeManager::CGameUISchemeManager(CGameUISchemeManager *this)
{
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *p_m_Schemes; // esi
  CGameUIScheme *v3; // eax
  vgui::TreeNode *src; // [esp+Ch] [ebp-4h] BYREF

  this->__vftable = (CGameUISchemeManager_vtbl *)&CGameUISchemeManager::`vftable';
  p_m_Schemes = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Schemes;
  this->m_Schemes.m_Memory.m_pMemory = nullptr;
  this->m_Schemes.m_Memory.m_nAllocationCount = 0;
  this->m_Schemes.m_Memory.m_nGrowSize = 0;
  this->m_Schemes.m_Size = 0;
  this->m_Schemes.m_pElements = nullptr;
  v3 = (CGameUIScheme *)MemAlloc_Alloc(nSize: 0x54u);
  if ( v3 != nullptr )
    src = (vgui::TreeNode *)CGameUIScheme::CGameUIScheme(this: v3);
  else
    src = nullptr;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: p_m_Schemes,
    elem: p_m_Schemes->m_Size,
    &src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412AB0
// Name: public: void CGameUIScheme::SetFontRange(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIScheme::SetFontRange(CGameUIScheme *this, const char *fontname, int nMin, int nMax)
{
  const char *v4; // ebp
  int v6; // edi
  int v7; // ebx
  const char *v8; // eax
  int m_Size; // eax
  CUtlVector<CGameUIScheme::fontrange_t,CUtlMemory<CGameUIScheme::fontrange_t,int> > *p_m_FontRanges; // esi
  int v11; // edi
  int v12; // eax
  int v13; // eax

  v4 = fontname;
  v6 = 0;
  if ( this->m_FontRanges.m_Size <= 0 )
  {
LABEL_5:
    m_Size = this->m_FontRanges.m_Size;
    p_m_FontRanges = &this->m_FontRanges;
    v11 = CUtlVector<CGameUIScheme::fontrange_t,CUtlMemory<CGameUIScheme::fontrange_t,int>>::InsertBefore(
            this: p_m_FontRanges,
            elem: m_Size);
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&fontname, pStr: v4);
    v12 = v11;
    p_m_FontRanges->m_Memory.m_pMemory[v12]._fontName.m_Id = (unsigned __int16)fontname;
    p_m_FontRanges->m_Memory.m_pMemory[v12]._min = nMin;
    p_m_FontRanges->m_Memory.m_pMemory[v12]._max = nMax;
  }
  else
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = CUtlSymbol::String(this: &this->m_FontRanges.m_Memory.m_pMemory[v7]._fontName);
      if ( _V_stricmp(s1: v8, s2: v4) == 0 )
        break;
      ++v6;
      ++v7;
      if ( v6 >= this->m_FontRanges.m_Size )
        goto LABEL_5;
    }
    v13 = v6;
    this->m_FontRanges.m_Memory.m_pMemory[v13]._min = nMin;
    this->m_FontRanges.m_Memory.m_pMemory[v13]._max = nMax;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412B60
// Name: private: void CGameUIScheme::LoadFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIScheme::LoadFonts(CGameUIScheme *this)
{
  char *v1; // ebx
  const char *(__thiscall *GetLanguage)(struct CGameUISystemSurface *); // edx
  char *v3; // eax
  KeyValues *v4; // ecx
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // edi
  CUtlMemory<CGameUIScheme::fontalias_t,int> *v7; // esi
  const char *String; // eax
  const char *v9; // ebp
  char v10; // bl
  KeyValues *NextKey; // esi
  const char *Name; // edi
  KeyValues *v13; // eax
  char *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *i; // ebp
  const char *v18; // eax
  const char *v19; // edi
  void (__thiscall **p_SetBitmapFontName)(struct CGameUISystemSurface *, const char *, const char *); // esi
  const char *v21; // eax
  KeyValues *v22; // eax
  int j; // ebp
  const char *v24; // edi
  const char *v25; // eax
  const char *v26; // ecx
  __int16 v27; // ax
  int m_pMemory; // edi
  __int16 v29; // bx
  int m_nAllocationCount; // eax
  CGameUIScheme::fontalias_t *v31; // ecx
  int v32; // eax
  bool v33; // zf
  int v34; // edi
  CGameUIScheme::fontalias_t *v35; // eax
  const char *v36; // eax
  bool nRangeMin_3; // [esp+13h] [ebp-19h]
  int nRangeMax; // [esp+14h] [ebp-18h] BYREF
  KeyValues *kv; // [esp+18h] [ebp-14h] BYREF
  KeyValues *v40; // [esp+1Ch] [ebp-10h]
  const char *pszName; // [esp+20h] [ebp-Ch]
  const char *pLanguage; // [esp+24h] [ebp-8h]
  char *s1; // [esp+28h] [ebp-4h]

  v1 = (char *)this;
  GetLanguage = g_pGameUISystemSurface->GetLanguage;
  pszName = (const char *)this;
  v3 = (char *)GetLanguage(this: g_pGameUISystemSurface);
  v4 = *((KeyValues **)v1 + 10);
  s1 = v3;
  Key = KeyValues::FindKey(this: v4, keyName: "CustomFontFiles", bCreate: true);
  FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
  v7 = nullptr;
  v40 = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
      v9 = String;
      if ( String != nullptr && *String != 0 )
      {
        g_pGameUISystemSurface->AddCustomFontFile(this: g_pGameUISystemSurface, a2: String);
      }
      else
      {
        nRangeMax = 0;
        kv = nullptr;
        pLanguage = nullptr;
        v10 = 0;
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
                if ( _V_stricmp(s1, s2: Name) == 0 )
                {
                  v13 = KeyValues::FindKey(this: NextKey, keyName: "range", bCreate: false);
                  if ( v13 != nullptr )
                  {
                    v10 = 1;
                    v14 = (char *)KeyValues::GetString(this: v13, keyName: nullptr, defaultValue: defaultValue);
                    sscanf(string: v14, format: "%x %x", &nRangeMax, &kv);
                    v15 = (KeyValues *)nRangeMax;
                    if ( nRangeMax > (int)kv )
                    {
                      nRangeMax = (int)kv;
                      kv = v15;
                    }
                  }
                }
              }
              else
              {
                pLanguage = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: defaultValue);
              }
            }
            else
            {
              v9 = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: defaultValue);
            }
            NextKey = KeyValues::GetNextKey(this: NextKey);
          }
          while ( NextKey != nullptr );
          FirstSubKey = v40;
        }
        if ( v9 != nullptr && *v9 != 0 )
        {
          g_pGameUISystemSurface->AddCustomFontFile(this: g_pGameUISystemSurface, a2: v9);
          if ( v10 != 0 )
            CGameUIScheme::SetFontRange(
              this: (CGameUIScheme *)pszName,
              fontname: pLanguage,
              nMin: nRangeMax,
              nMax: (int)kv);
        }
      }
      v7 = nullptr;
      v40 = KeyValues::GetNextKey(this: FirstSubKey);
      if ( v40 == nullptr )
        break;
      FirstSubKey = v40;
    }
    v1 = (char *)pszName;
  }
  v16 = KeyValues::FindKey(this: *((KeyValues **)v1 + 10), keyName: "BitmapFontFiles", bCreate: true);
  for ( i = KeyValues::GetFirstSubKey(this: v16); i != nullptr; v7 = nullptr )
  {
    v18 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v19 = v18;
    if ( v18 != nullptr && *v18 != 0 && g_pGameUISystemSurface->AddBitmapFontFile(this: g_pGameUISystemSurface, a2: v18) )
    {
      p_SetBitmapFontName = &g_pGameUISystemSurface->SetBitmapFontName;
      v21 = KeyValues::GetName(this: i);
      (*p_SetBitmapFontName)(this: g_pGameUISystemSurface, a2: v21, a3: v19);
    }
    i = KeyValues::GetNextKey(this: i);
  }
  v22 = KeyValues::FindKey(this: *((KeyValues **)v1 + 10), keyName: "Fonts", bCreate: true);
  v40 = KeyValues::GetFirstSubKey(this: v22);
  if ( v40 != nullptr )
  {
    v7 = (CUtlMemory<CGameUIScheme::fontalias_t,int> *)(v1 + 64);
    do
    {
      for ( j = 0; j < 2; ++j )
      {
        nRangeMin_3 = j != 0;
        v24 = CUtlString::Get(this: (CUtlString *)(pszName + 24));
        v25 = KeyValues::GetName(this: v40);
        v26 = "p";
        if ( v24 != nullptr )
        {
          if ( j == 0 )
            v26 = "no";
          V_snprintf(pDest: mungeBuffer, maxLen: 64, pFormat: "%s%s-%s", v25, v24, v26);
        }
        else
        {
          if ( j == 0 )
            v26 = "no";
          V_snprintf(pDest: mungeBuffer, maxLen: 64, pFormat: "%s-%s", v25, v26);
        }
        v27 = g_pGameUISystemSurface->CreateFont(this: g_pGameUISystemSurface);
        m_pMemory = (int)v7[1].m_pMemory;
        v29 = v27;
        m_nAllocationCount = v7->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CGameUIScheme::fontalias_t,int>::Grow(this: v7, num: m_pMemory - m_nAllocationCount + 1);
        ++v7[1].m_pMemory;
        v31 = v7->m_pMemory;
        v32 = (int)v7[1].m_pMemory - m_pMemory - 1;
        v33 = (CGameUIScheme::fontalias_t *)((char *)v7[1].m_pMemory - m_pMemory) == (CGameUIScheme::fontalias_t *)1;
        v7[1].m_nAllocationCount = (int)v7->m_pMemory;
        if ( v32 >= 0 && !v33 )
          _V_memmove(dest: &v31[m_pMemory + 1], src: &v31[m_pMemory], count: 6 * v32);
        v34 = m_pMemory;
        v35 = &v7->m_pMemory[v34];
        if ( v35 != nullptr )
        {
          v35->_fontName.m_Id = -1;
          v35->_trueFontName.m_Id = -1;
        }
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&nRangeMax, pStr: mungeBuffer);
        v7->m_pMemory[v34]._fontName.m_Id = nRangeMax;
        v36 = KeyValues::GetName(this: v40);
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&kv, pStr: v36);
        v7->m_pMemory[v34]._trueFontName.m_Id = (unsigned __int16)kv;
        *((_WORD *)&v7->m_pMemory[v34] + 2) ^= (v29 ^ *((_WORD *)&v7->m_pMemory[v34] + 2)) & 0x7FFF;
        *((_WORD *)&v7->m_pMemory[v34] + 2) = *((_WORD *)&v7->m_pMemory[v34] + 2) & 0x7FFF | (nRangeMin_3 << 15);
      }
      v40 = KeyValues::GetNextKey(this: v40);
    }
    while ( v40 != nullptr );
  }
  CGameUIScheme::ReloadFontGlyphs(this: (CGameUIScheme *)pszName, a2: (int)v7, inScreenTall: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00412F20
// Name: public: void CGameUIScheme::LoadFromFile(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIScheme::LoadFromFile(
        CGameUIScheme *this,
        const char *pFilename,
        const char *inTag,
        KeyValues *inKeys)
{
  KeyValues *Key; // eax
  const char *v6; // eax

  _COM_TimestampedLog(a1: "CScheme::LoadFromFile( %s )", pFilename);
  CUtlString::operator=(this: &this->m_pFileName, src: pFilename);
  this->m_pData = inKeys;
  Key = KeyValues::FindKey(this: inKeys, keyName: "Name", bCreate: true);
  KeyValues::SetString(this: Key, keyName: "Name", value: inTag);
  if ( inTag != nullptr )
  {
    CUtlString::operator=(this: &this->m_pTag, src: inTag);
  }
  else
  {
    v6 = CUtlString::Get(this: &this->m_pFileName);
    _Error(a1: "You need to name the scheme (%s)!", v6);
    CUtlString::operator=(this: &this->m_pTag, src: "default");
  }
  CGameUIScheme::LoadFonts(this);
}

//------------------------------------------------------------------------------
// Address: 0x00412FA0
// Name: public: CGameUISchemeManager::~CGameUISchemeManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISchemeManager::~CGameUISchemeManager(CGameUISchemeManager *this)
{
  int v2; // edi
  bool v3; // cc
  CGameUIScheme **m_pMemory; // eax
  CGameUIScheme *v5; // ebp
  bool v6; // sf
  CGameUIScheme **v7; // eax

  v2 = 0;
  v3 = this->m_Schemes.m_Size <= 0;
  this->__vftable = (CGameUISchemeManager_vtbl *)&CGameUISchemeManager::`vftable';
  if ( !v3 )
  {
    do
    {
      m_pMemory = this->m_Schemes.m_Memory.m_pMemory;
      v5 = m_pMemory[v2];
      if ( v5 != nullptr )
      {
        CGameUIScheme::~CGameUIScheme(this: m_pMemory[v2]);
        free(pMem: v5);
      }
      this->m_Schemes.m_Memory.m_pMemory[v2++] = nullptr;
    }
    while ( v2 < this->m_Schemes.m_Size );
  }
  this->m_Schemes.m_Size = 0;
  v6 = this->m_Schemes.m_Memory.m_nGrowSize < 0;
  this->m_Schemes.m_Size = 0;
  if ( !v6 )
  {
    if ( this->m_Schemes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Schemes.m_Memory.m_pMemory);
      this->m_Schemes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Schemes.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_Schemes.m_Memory.m_nGrowSize < 0;
  v7 = this->m_Schemes.m_Memory.m_pMemory;
  this->m_Schemes.m_pElements = v7;
  if ( !v6 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_Schemes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Schemes.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413070
// Name: public: virtual void CGameUISchemeManager::ReloadSchemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISchemeManager::ReloadSchemes(CGameUISchemeManager *this)
{
  int m_Size; // eax
  int v3; // ebp
  CGameUIScheme *v4; // esi
  KeyValues *m_pData; // ecx
  int v6; // ebx
  CGameUIScheme *v7; // esi
  CGameUISchemeManager_vtbl *v8; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // [esp+10h] [ebp-4h]

  m_Size = this->m_Schemes.m_Size;
  v3 = 1;
  v11 = m_Size;
  if ( m_Size > 1 )
  {
    do
    {
      v4 = this->m_Schemes.m_Memory.m_pMemory[v3];
      v4->m_bActive = false;
      v4->m_FontRanges.m_Size = 0;
      m_pData = v4->m_pData;
      if ( m_pData != nullptr )
      {
        KeyValues::deleteThis(this: m_pData);
        v4->m_pData = nullptr;
      }
      ++v3;
    }
    while ( v3 < this->m_Schemes.m_Size );
    m_Size = v11;
  }
  v6 = 1;
  if ( m_Size > 1 )
  {
    do
    {
      v7 = this->m_Schemes.m_Memory.m_pMemory[v6];
      v8 = this->__vftable;
      v9 = v7->GetName(this: v7);
      v10 = ((int (__thiscall *)(CGameUIScheme *, int))v7->GetFileName)(a1: v7, a2: v9);
      ((void (__thiscall *)(CGameUISchemeManager *, int))v8->LoadSchemeFromFile)(a1: this, a2: v10);
      ++v6;
    }
    while ( v6 < v11 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413100
// Name: public: class IGameUIScheme __near * CGameUISchemeManager::LoadSchemeFromFileEx(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameUIScheme *__thiscall CGameUISchemeManager::LoadSchemeFromFileEx(
        CGameUISchemeManager *this,
        CGameUIScheme *pFilename,
        const char *tag)
{
  const char *v3; // ebx
  CGameUIScheme *LoadedScheme; // eax
  CGameUIScheme *v6; // edi
  CGameUIScheme *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  IBaseFileSystem *v11; // eax
  IBaseFileSystem *v12; // eax
  IBaseFileSystem *v13; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  const char *v15; // [esp-8h] [ebp-1Ch]
  ConVarRef cl_hud_minmode; // [esp+8h] [ebp-Ch] BYREF
  int v17; // [esp+10h] [ebp-4h]

  v3 = (const char *)pFilename;
  LoadedScheme = CGameUISchemeManager::FindLoadedScheme(this, (const char *)pFilename);
  v6 = LoadedScheme;
  if ( LoadedScheme != nullptr )
  {
    if ( LoadedScheme->m_bActive )
    {
      CGameUIScheme::ReloadFontGlyphs(this: LoadedScheme, a2: (int)this, inScreenTall: -1);
      return v6;
    }
  }
  else
  {
    v8 = (CGameUIScheme *)MemAlloc_Alloc(nSize: 0x54u);
    if ( v8 != nullptr )
      v6 = CGameUIScheme::CGameUIScheme(this: v8);
    else
      v6 = nullptr;
    m_Size = this->m_Schemes.m_Size;
    pFilename = v6;
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Schemes,
      elem: m_Size,
      src: (vgui::TreeNode **)&pFilename);
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "Scheme");
  else
    v10 = nullptr;
  KeyValues::UsesEscapeSequences(this: v10, state: true);
  if ( g_pFullFileSystem != nullptr )
    v11 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v11 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v10,
         filesystem: v11,
         resourceName: v3,
         pathID: "SKIN",
         pfnEvaluateSymbolProc: nullptr)
    || (g_pFullFileSystem == nullptr ? (v12 = nullptr) : (v12 = &g_pFullFileSystem->IBaseFileSystem),
        KeyValues::LoadFromFile(
          this: v10,
          filesystem: v12,
          resourceName: v3,
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr)
     || (g_pFullFileSystem == nullptr ? (v13 = nullptr) : (v13 = &g_pFullFileSystem->IBaseFileSystem),
         KeyValues::LoadFromFile(
           this: v10,
           filesystem: v13,
           resourceName: v3,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr))) )
  {
    ConVarRef::ConVarRef(
      this: (ConVarRef *)&cl_hud_minmode.m_pConVarState,
      pName: "cl_hud_minmode",
      bIgnoreMissing: true);
    if ( ConVarRef::IsValid(this: (ConVarRef *)&cl_hud_minmode.m_pConVarState) && *(_DWORD *)(v17 + 48) != 0 )
      KeyValues::ProcessResolutionKeys(this: v10, pResString: "_minmode");
    v15 = tag;
    v6->m_bActive = true;
    CGameUIScheme::LoadFromFile(this: v6, pFilename: v3, inTag: v15, inKeys: v10);
    return v6;
  }
  else
  {
    KeyValues::deleteThis(this: v10);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413260
// Name: public: virtual class IGameUIScheme __near * CGameUISchemeManager::LoadSchemeFromFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
CGameUIScheme *__thiscall CGameUISchemeManager::LoadSchemeFromFile(
        CGameUISchemeManager *this,
        CGameUIScheme *fileName,
        const char *tag)
{
  return CGameUISchemeManager::LoadSchemeFromFileEx(this, pFilename: fileName, tag);
}
