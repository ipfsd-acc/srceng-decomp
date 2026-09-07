// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_surfacelib/fontmanager.cpp
// Functions: 18
// ============================================================

#include "vgui2\vgui_surfacelib\fontmanager.h"

//------------------------------------------------------------------------------
// Address: 0x100200E0
// Name: class CFontManager __near & FontManager(void)
// Source: json
//------------------------------------------------------------------------------
CFontManager *__cdecl FontManager()
{
  return &s_FontManager;
}

//------------------------------------------------------------------------------
// Address: 0x100200F0
// Name: public: void CFontManager::SetLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::SetLanguage(CFontManager *this, char *pLanguage)
{
  V_strncpy(pDest: this->m_szLanguage, pSrc: pLanguage, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10020110
// Name: public: char const __near * CFontManager::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFontManager::GetLanguage(CFontManager *this)
{
  return this->m_szLanguage;
}

//------------------------------------------------------------------------------
// Address: 0x10020120
// Name: private: char const __near * CFontManager::GetForeignFallbackFontName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFontManager::GetForeignFallbackFontName(CFontManager *this)
{
  int v2; // esi
  char *m_szLanguage; // edi
  Win98ForeignFallbackFont_t *v4; // eax

  if ( s_bSupportsUnicode )
    return "Tahoma";
  v2 = 0;
  if ( g_Win98ForeignFallbackFonts[0].language != nullptr )
  {
    m_szLanguage = this->m_szLanguage;
    v4 = g_Win98ForeignFallbackFonts;
    do
    {
      if ( _V_stricmp(s1: v4->language, s2: m_szLanguage) == 0 )
        break;
      v4 = &g_Win98ForeignFallbackFonts[++v2];
    }
    while ( v4->language != nullptr );
  }
  return off_1004EE84[2 * v2];
}

//------------------------------------------------------------------------------
// Address: 0x10020290
// Name: public: char const __near * CFontManager::GetFontName(unsigned long)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFontManager::GetFontName(CFontManager *this, unsigned int font)
{
  return CFontAmalgam::GetFontName(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], i: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100202B0
// Name: public: class CWin32Font __near * CFontManager::GetFontForChar(unsigned long,wchar_t)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontManager::GetFontForChar(CFontManager *this, unsigned int font, wchar_t wch)
{
  return CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch: wch);
}

//------------------------------------------------------------------------------
// Address: 0x100202E0
// Name: public: void CFontManager::GetCharABCwide(unsigned long,int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::GetCharABCwide(CFontManager *this, unsigned int font, int ch, int *a, int *b, int *c)
{
  CWin32Font *FontForChar; // eax

  FontForChar = CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch);
  if ( FontForChar != nullptr )
  {
    FontForChar->GetCharABCWidths(this: FontForChar, a2: ch, a3: a, a4: b, a5: c);
  }
  else
  {
    *c = 0;
    *a = 0;
    *b = ConCommandBase::GetFlags(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020350
// Name: public: int CFontManager::GetFontTall(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::GetFontTall(CFontManager *this, unsigned int font)
{
  return CFontAmalgam::GetFontHeight(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
}

//------------------------------------------------------------------------------
// Address: 0x10020370
// Name: public: int CFontManager::GetFontAscent(unsigned long,wchar_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::GetFontAscent(CFontManager *this, unsigned int font, wchar_t wch)
{
  CWin32Font *FontForChar; // eax

  FontForChar = CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch: wch);
  if ( FontForChar != nullptr )
    return FontForChar->GetAscent(this: FontForChar);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100203B0
// Name: public: bool CFontManager::IsFontAdditive(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontManager::IsFontAdditive(CFontManager *this, unsigned int font)
{
  return ((unsigned __int16)CFontAmalgam::GetFlags(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], i: 0) >> 8) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100203E0
// Name: public: int CFontManager::GetCharacterWidth(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::GetCharacterWidth(CFontManager *this, int font, int ch)
{
  int v3; // ebx
  unsigned int v5; // esi
  CWin32Font *FontForChar; // eax
  int Flags; // eax
  int b; // [esp+8h] [ebp-4h] BYREF

  v3 = ch;
  if ( iswcntrl(c: ch) != 0 )
    return 0;
  v5 = font;
  FontForChar = CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch: v3);
  if ( FontForChar != nullptr )
  {
    FontForChar->GetCharABCWidths(this: FontForChar, a2: v3, a3: &ch, a4: &b, a5: &font);
    return font + ch + b;
  }
  else
  {
    font = 0;
    ch = 0;
    Flags = ConCommandBase::GetFlags(this: &this->m_FontAmalgams.m_Memory.m_pMemory[v5]);
    return font + ch + Flags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020470
// Name: public: void CFontManager::GetKernedCharWidth(unsigned long,wchar_t,wchar_t,wchar_t,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::GetKernedCharWidth(
        CFontManager *this,
        unsigned int font,
        int ch,
        int chBefore,
        int chAfter,
        float *wide,
        float *flabcA,
        float *flabcC)
{
  CWin32Font *FontForChar; // edi
  CFontAmalgam *v10; // ecx
  int v11; // esi

  *wide = 0.0;
  *flabcA = 0.0;
  if ( font != 0 )
  {
    FontForChar = CFontAmalgam::GetFontForChar(
                    this: &this->m_FontAmalgams.m_Memory.m_pMemory[font],
                    (unsigned __int16)ch);
    v10 = &this->m_FontAmalgams.m_Memory.m_pMemory[font];
    if ( FontForChar != nullptr )
    {
      if ( CFontAmalgam::GetFontForChar(this: v10, ch: (unsigned __int16)chBefore) != FontForChar )
        chBefore = 0;
      v11 = chAfter;
      if ( CFontAmalgam::GetFontForChar(
             this: &this->m_FontAmalgams.m_Memory.m_pMemory[font],
             ch: (unsigned __int16)chAfter) != FontForChar )
        v11 = 0;
      FontForChar->GetKernedCharWidth(
        this: FontForChar,
        a2: ch,
        a3: chBefore,
        a4: v11,
        a5: wide,
        a6: flabcA,
        a7: flabcC);
    }
    else
    {
      *flabcA = 0.0;
      *wide = (float)ConCommandBase::GetFlags(this: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100205A0
// Name: public: void CFontManager::ClearAllFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::ClearAllFonts(CFontManager *this)
{
  int i; // edi
  CWin32Font **m_pMemory; // eax
  CWin32Font *v4; // ebx
  int v5; // edi
  int v6; // ebx

  for ( i = 0; i < this->m_Win32Fonts.m_Size; ++i )
  {
    m_pMemory = this->m_Win32Fonts.m_Memory.m_pMemory;
    v4 = m_pMemory[i];
    if ( v4 != nullptr )
    {
      CWin32Font::~CWin32Font(this: m_pMemory[i]);
      free(pMem: v4);
    }
  }
  this->m_Win32Fonts.m_Size = 0;
  v5 = this->m_FontAmalgams.m_Size - 1;
  if ( v5 < 0 )
  {
    this->m_FontAmalgams.m_Size = 0;
  }
  else
  {
    v6 = v5;
    do
    {
      CFontAmalgam::~CFontAmalgam(this: &this->m_FontAmalgams.m_Memory.m_pMemory[v6--]);
      --v5;
    }
    while ( v5 >= 0 );
    this->m_FontAmalgams.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020620
// Name: public: void CFontManager::GetTextSize(unsigned long,wchar_t const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::GetTextSize(
        CFontManager *this,
        unsigned int font,
        const wchar_t *text,
        int *wide,
        int *tall)
{
  int v6; // esi
  int v7; // ecx
  const wchar_t *v8; // eax
  int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float flabcA; // [esp+14h] [ebp-14h] BYREF
  float flabcC; // [esp+18h] [ebp-10h] BYREF
  float flWide; // [esp+1Ch] [ebp-Ch] BYREF
  int i; // [esp+20h] [ebp-8h]
  float xx; // [esp+24h] [ebp-4h]

  *wide = 0;
  *tall = 0;
  if ( text != nullptr )
  {
    *tall = CFontAmalgam::GetFontHeight(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
    v6 = *text;
    v7 = 0;
    xx = 0.0;
    i = 0;
    if ( (_WORD)v6 != 0 )
    {
      v8 = text;
      do
      {
        v9 = v8[1];
        if ( (_WORD)v6 == 10 )
        {
          *tall += CFontAmalgam::GetFontHeight(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
          xx = 0.0;
        }
        else if ( (_WORD)v6 != 38 )
        {
          CFontManager::GetKernedCharWidth(
            this,
            font,
            ch: v6,
            chBefore: v7,
            chAfter: v9,
            wide: &flWide,
            &flabcA,
            &flabcC);
          v10 = flWide + xx;
          v11 = (float)*wide;
          xx = flWide + xx;
          if ( xx > v11 )
            *wide = (int)ceil(X: v10);
        }
        v8 = &text[++i];
        v7 = (unsigned __int16)v6;
        v6 = *v8;
      }
      while ( (_WORD)v6 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020820
// Name: public: CFontManager::CFontManager(void)
// Source: json
//------------------------------------------------------------------------------
CFontManager *__thiscall CFontManager::CFontManager(CFontManager *this)
{
  CFontAmalgam *v2; // eax
  int m_Size; // edx
  CWin32Font **m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  CWin32Font **v6; // eax

  this->m_FontAmalgams.m_Memory.m_nAllocationCount = 128;
  this->m_FontAmalgams.m_Memory.m_nGrowSize = 64;
  this->m_FontAmalgams.m_Memory.m_pMemory = nullptr;
  v2 = (CFontAmalgam *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3584);
  this->m_FontAmalgams.m_Memory.m_pMemory = v2;
  this->m_FontAmalgams.m_Size = 0;
  this->m_FontAmalgams.m_pElements = v2;
  this->m_Win32Fonts.m_Memory.m_pMemory = nullptr;
  this->m_Win32Fonts.m_Memory.m_nAllocationCount = 0;
  this->m_Win32Fonts.m_Memory.m_nGrowSize = 0;
  this->m_Win32Fonts.m_Size = 0;
  this->m_Win32Fonts.m_pElements = nullptr;
  CUtlMemory<CFontAmalgam,int>::EnsureCapacity(this: &this->m_FontAmalgams.m_Memory, num: 100);
  m_Size = this->m_FontAmalgams.m_Size;
  this->m_FontAmalgams.m_pElements = this->m_FontAmalgams.m_Memory.m_pMemory;
  CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::InsertBefore(this: &this->m_FontAmalgams, elem: m_Size);
  if ( this->m_Win32Fonts.m_Memory.m_nAllocationCount < 100 && this->m_Win32Fonts.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Win32Fonts.m_Memory.m_pMemory;
    this->m_Win32Fonts.m_Memory.m_nAllocationCount = 100;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (CWin32Font **)((int (__stdcall *)(CWin32Font **, int))v5->Realloc_2)(a1: m_pMemory, a2: 400);
    else
      v6 = (CWin32Font **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 400);
    this->m_Win32Fonts.m_Memory.m_pMemory = v6;
  }
  this->m_Win32Fonts.m_pElements = this->m_Win32Fonts.m_Memory.m_pMemory;
  setlocale(_category: 2, _locale: pHelpString);
  setlocale(_category: 5, _locale: pHelpString);
  setlocale(_category: 1, _locale: pHelpString);
  setlocale(_category: 3, _locale: pHelpString);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100208F0
// Name: public: unsigned long CFontManager::CreateFont(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::CreateFont(CFontManager *this)
{
  return CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::InsertBefore(
           this: &this->m_FontAmalgams,
           elem: this->m_FontAmalgams.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x10020900
// Name: private: class CWin32Font __near * CFontManager::CreateOrFindWin32Font(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontManager::CreateOrFindWin32Font(
        CFontManager *this,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags)
{
  int v8; // edi
  CWin32Font *v9; // ecx
  CWin32Font *v10; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWin32Font **m_pMemory; // ecx
  int v14; // eax
  CWin32Font *v15; // eax
  CWin32Font *v16; // eax
  CWin32Font *v17; // ecx
  CWin32Font **v19; // edx
  CWin32Font *v20; // ebx

  v8 = 0;
  if ( this->m_Win32Fonts.m_Size > 0 )
  {
    while ( 1 )
    {
      v9 = this->m_Win32Fonts.m_Memory.m_pMemory[v8];
      if ( v9->IsEqualTo(this: v9, a2: windowsFontName, a3: tall, a4: weight, a5: blur, a6: scanlines, a7: flags) )
        break;
      if ( ++v8 >= this->m_Win32Fonts.m_Size )
        goto LABEL_6;
    }
    v10 = this->m_Win32Fonts.m_Memory.m_pMemory[v8];
    if ( v10 != nullptr )
      return v10;
  }
LABEL_6:
  m_Size = this->m_Win32Fonts.m_Size;
  m_nAllocationCount = this->m_Win32Fonts.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: &this->m_Win32Fonts.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Win32Fonts.m_Size;
  m_pMemory = this->m_Win32Fonts.m_Memory.m_pMemory;
  v14 = this->m_Win32Fonts.m_Size - m_Size - 1;
  this->m_Win32Fonts.m_pElements = m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
  v15 = (CWin32Font *)operator new(nSize: 0x44u);
  if ( v15 != nullptr )
    v16 = CWin32Font::CWin32Font(this: v15);
  else
    v16 = nullptr;
  this->m_Win32Fonts.m_Memory.m_pMemory[m_Size] = v16;
  v17 = this->m_Win32Fonts.m_Memory.m_pMemory[m_Size];
  if ( v17->Create(this: v17, a2: windowsFontName, a3: tall, a4: weight, a5: blur, a6: scanlines, a7: flags) != 0 )
    return this->m_Win32Fonts.m_Memory.m_pMemory[m_Size];
  v19 = this->m_Win32Fonts.m_Memory.m_pMemory;
  v20 = v19[m_Size];
  if ( v20 != nullptr )
  {
    CWin32Font::~CWin32Font(this: v19[m_Size]);
    free(pMem: v20);
  }
  if ( this->m_Win32Fonts.m_Size - m_Size - 1 > 0 )
    _V_memmove(
      dest: &this->m_Win32Fonts.m_Memory.m_pMemory[m_Size],
      src: &this->m_Win32Fonts.m_Memory.m_pMemory[m_Size + 1],
      count: 4 * (this->m_Win32Fonts.m_Size - m_Size - 1));
  --this->m_Win32Fonts.m_Size;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10020A30
// Name: public: bool CFontManager::SetFontGlyphSet(unsigned long,char const __near *,int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontManager::SetFontGlyphSet(
        CFontManager *this,
        unsigned int font,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags,
        int nRangeMin,
        int nRangeMax)
{
  unsigned int v11; // esi
  CFontAmalgam *v12; // ecx
  CWin32Font *Win32Font; // ebx
  int v14; // esi
  const char **v15; // eax
  const char *ForeignFallbackFontName; // esi
  CWin32Font *v17; // eax
  CWin32Font *v18; // esi
  int v19; // ebx
  int v20; // edi
  int v22; // esi
  FallbackFont_t *v23; // eax
  CWin32Font *winFont; // [esp+Ch] [ebp-8h]
  CFontManager *v25; // [esp+10h] [ebp-4h]
  unsigned int fonta; // [esp+1Ch] [ebp+8h]

  v11 = font;
  v12 = &this->m_FontAmalgams.m_Memory.m_pMemory[font];
  v25 = this;
  fonta = font;
  if ( vgui::Bitmap::GetName(this: v12) > 0 )
    CFontAmalgam::RemoveAll(this: &this->m_FontAmalgams.m_Memory.m_pMemory[v11]);
  if ( _V_stricmp(s1: this->m_szLanguage, s2: "russian") == 0 || _V_stricmp(s1: this->m_szLanguage, s2: "polish") == 0 )
  {
    if ( _V_stricmp(s1: windowsFontName, s2: "universltstd-cn") != 0
      && _V_stricmp(s1: windowsFontName, s2: "universltstd-lightcn") != 0 )
    {
      if ( _V_stricmp(s1: windowsFontName, s2: "universltstd-boldcn") == 0 )
        windowsFontName = "UniversLTCYR-67BoldCond";
    }
    else
    {
      windowsFontName = "UniversLTCYR-57Condensed";
    }
  }
  Win32Font = CFontManager::CreateOrFindWin32Font(this, windowsFontName, tall, weight, blur, scanlines, flags);
  winFont = Win32Font;
  while ( 1 )
  {
    v14 = 0;
    if ( g_szValidAsianFonts[0] != nullptr )
    {
      v15 = g_szValidAsianFonts;
      while ( _V_stricmp(s1: *v15, s2: windowsFontName) != 0 )
      {
        v15 = &g_szValidAsianFonts[++v14];
        if ( *v15 == nullptr )
          goto LABEL_15;
      }
      if ( Win32Font != nullptr )
      {
LABEL_39:
        CFontAmalgam::AddFont(
          this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
          pFont: Win32Font,
          lowRange: 0,
          highRange: 0xFFFF);
        return 1;
      }
      goto LABEL_31;
    }
LABEL_15:
    ForeignFallbackFontName = CFontManager::GetForeignFallbackFontName(this);
    if ( Win32Font != nullptr && _V_stricmp(s1: ForeignFallbackFontName, s2: windowsFontName) == 0 )
      goto LABEL_39;
    v17 = CFontManager::CreateOrFindWin32Font(
            this,
            windowsFontName: ForeignFallbackFontName,
            tall,
            weight,
            blur,
            scanlines,
            flags);
    v18 = v17;
    if ( Win32Font == nullptr )
    {
      if ( v17 != nullptr )
      {
        CFontAmalgam::AddFont(
          this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
          pFont: v17,
          lowRange: 0,
          highRange: 0xFFFF);
        return 1;
      }
      goto LABEL_31;
    }
    if ( v17 != nullptr )
      break;
LABEL_31:
    v22 = 0;
    if ( g_FallbackFonts[0].font != nullptr )
    {
      v23 = g_FallbackFonts;
      while ( _V_stricmp(s1: v23->font, s2: windowsFontName) != 0 )
      {
        v23 = &g_FallbackFonts[++v22];
        if ( v23->font == nullptr )
          goto LABEL_35;
      }
      windowsFontName = off_1004EE54[2 * v22];
    }
    else
    {
LABEL_35:
      windowsFontName = off_1004EE54[2 * v22];
    }
    if ( windowsFontName == nullptr )
      return 0;
  }
  v19 = 0;
  v20 = 255;
  if ( nRangeMin > 0 || nRangeMax > 0 )
  {
    v19 = nRangeMin;
    v20 = nRangeMax;
    if ( nRangeMin > nRangeMax )
    {
      v19 = nRangeMax;
      v20 = nRangeMin;
    }
    if ( v19 > 0 )
      CFontAmalgam::AddFont(
        this: &v25->m_FontAmalgams.m_Memory.m_pMemory[fonta],
        pFont: v17,
        lowRange: 0,
        highRange: v19 - 1);
  }
  CFontAmalgam::AddFont(
    this: &v25->m_FontAmalgams.m_Memory.m_pMemory[fonta],
    pFont: winFont,
    lowRange: v19,
    highRange: v20);
  if ( v20 < 0xFFFF )
    CFontAmalgam::AddFont(
      this: &v25->m_FontAmalgams.m_Memory.m_pMemory[fonta],
      pFont: v18,
      lowRange: v20 + 1,
      highRange: 0xFFFF);
  return 1;
}

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10012E40
// Name: class CFontManager __near & FontManager(void)
// Source: json
//------------------------------------------------------------------------------
CFontManager *__cdecl FontManager()
{
  return &s_FontManager;
}

//------------------------------------------------------------------------------
// Address: 0x10012E50
// Name: public: void CFontManager::SetLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::SetLanguage(CFontManager *this, const char *pLanguage)
{
  V_strncpy(pDest: this->m_szLanguage, pSrc: pLanguage, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10012E70
// Name: public: char const __near * CFontManager::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFontManager::GetLanguage(CFontManager *this)
{
  return this->m_szLanguage;
}

//------------------------------------------------------------------------------
// Address: 0x10012E80
// Name: private: char const __near * CFontManager::GetForeignFallbackFontName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFontManager::GetForeignFallbackFontName(CFontManager *this)
{
  int v2; // esi
  char *m_szLanguage; // edi
  Win98ForeignFallbackFont_t *v4; // eax

  if ( s_bSupportsUnicode )
    return "Tahoma";
  v2 = 0;
  if ( g_Win98ForeignFallbackFonts[0].language != nullptr )
  {
    m_szLanguage = this->m_szLanguage;
    v4 = g_Win98ForeignFallbackFonts;
    do
    {
      if ( _V_stricmp(s1: v4->language, s2: m_szLanguage) == 0 )
        break;
      v4 = &g_Win98ForeignFallbackFonts[++v2];
    }
    while ( v4->language != nullptr );
  }
  return off_1012E4EC[2 * v2];
}

//------------------------------------------------------------------------------
// Address: 0x10012FF0
// Name: public: void CFontManager::SetFontScale(unsigned long,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::SetFontScale(CFontManager *this, unsigned int font, float sx, float sy)
{
  CFontAmalgam::SetFontScale(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], sx, sy);
}

//------------------------------------------------------------------------------
// Address: 0x10013030
// Name: public: char const __near * CFontManager::GetFontName(unsigned long)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFontManager::GetFontName(CFontManager *this, unsigned int font)
{
  return CFontAmalgam::GetFontName(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], i: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10013050
// Name: public: class CWin32Font __near * CFontManager::GetFontForChar(unsigned long,wchar_t)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontManager::GetFontForChar(CFontManager *this, unsigned int font, wchar_t wch)
{
  return CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch: wch);
}

//------------------------------------------------------------------------------
// Address: 0x10013080
// Name: public: void CFontManager::GetCharABCwide(unsigned long,int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::GetCharABCwide(CFontManager *this, unsigned int font, int ch, int *a, int *b, int *c)
{
  CWin32Font *FontForChar; // eax

  FontForChar = CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch);
  if ( FontForChar != nullptr )
  {
    FontForChar->GetCharABCWidths(this: FontForChar, a2: ch, a3: a, a4: b, a5: c);
  }
  else
  {
    *c = 0;
    *a = 0;
    *b = ConCommandBase::GetFlags(this: (ConCommandBase *)&this->m_FontAmalgams.m_Memory.m_pMemory[font]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100130F0
// Name: public: int CFontManager::GetFontTall(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::GetFontTall(CFontManager *this, unsigned int font)
{
  return CFontAmalgam::GetFontHeight(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
}

//------------------------------------------------------------------------------
// Address: 0x10013110
// Name: public: int CFontManager::GetFontAscent(unsigned long,wchar_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::GetFontAscent(CFontManager *this, unsigned int font, wchar_t wch)
{
  CWin32Font *FontForChar; // eax

  FontForChar = CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch: wch);
  if ( FontForChar != nullptr )
    return FontForChar->GetAscent(this: FontForChar);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013150
// Name: public: bool CFontManager::IsFontAdditive(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontManager::IsFontAdditive(CFontManager *this, unsigned int font)
{
  return ((unsigned __int16)CFontAmalgam::GetFlags(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], i: 0) >> 8) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013180
// Name: public: bool CFontManager::IsBitmapFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontManager::IsBitmapFont(CFontManager *this, unsigned int font)
{
  return (CFontAmalgam::GetFlags(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], i: 0) & 0x800) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100131B0
// Name: public: int CFontManager::GetCharacterWidth(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::GetCharacterWidth(CFontManager *this, int font, int ch)
{
  int v3; // ebx
  unsigned int v5; // esi
  CWin32Font *FontForChar; // eax
  int Flags; // eax
  int b; // [esp+8h] [ebp-4h] BYREF

  v3 = ch;
  if ( iswcntrl(c: ch) != 0 )
    return 0;
  v5 = font;
  FontForChar = CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch: v3);
  if ( FontForChar != nullptr )
  {
    FontForChar->GetCharABCWidths(this: FontForChar, a2: v3, a3: &ch, a4: &b, a5: &font);
    return font + ch + b;
  }
  else
  {
    font = 0;
    ch = 0;
    Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)&this->m_FontAmalgams.m_Memory.m_pMemory[v5]);
    return font + ch + Flags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013240
// Name: public: bool CFontManager::GetFontUnderlined(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontManager::GetFontUnderlined(CFontManager *this, unsigned int font)
{
  return CFontAmalgam::GetUnderlined(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
}

//------------------------------------------------------------------------------
// Address: 0x10013260
// Name: public: void CFontManager::GetKernedCharWidth(unsigned long,wchar_t,wchar_t,wchar_t,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::GetKernedCharWidth(
        CFontManager *this,
        unsigned int font,
        int ch,
        int chBefore,
        int chAfter,
        float *wide,
        float *flabcA,
        float *flabcC)
{
  CWin32Font *FontForChar; // edi
  CFontAmalgam *v10; // ecx
  int v11; // esi

  *wide = 0.0;
  *flabcA = 0.0;
  if ( font != 0 )
  {
    FontForChar = CFontAmalgam::GetFontForChar(
                    this: &this->m_FontAmalgams.m_Memory.m_pMemory[font],
                    (unsigned __int16)ch);
    v10 = &this->m_FontAmalgams.m_Memory.m_pMemory[font];
    if ( FontForChar != nullptr )
    {
      if ( CFontAmalgam::GetFontForChar(this: v10, ch: (unsigned __int16)chBefore) != FontForChar )
        chBefore = 0;
      v11 = chAfter;
      if ( CFontAmalgam::GetFontForChar(
             this: &this->m_FontAmalgams.m_Memory.m_pMemory[font],
             ch: (unsigned __int16)chAfter) != FontForChar )
        v11 = 0;
      FontForChar->GetKernedCharWidth(
        this: FontForChar,
        a2: ch,
        a3: chBefore,
        a4: v11,
        a5: wide,
        a6: flabcA,
        a7: flabcC);
    }
    else
    {
      *flabcA = 0.0;
      *wide = (float)ConCommandBase::GetFlags(this: (ConCommandBase *)v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013390
// Name: public: void CFontManager::ClearAllFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::ClearAllFonts(CFontManager *this)
{
  int i; // edi
  CWin32Font **m_pMemory; // eax
  CWin32Font *v4; // ebx
  int v5; // edi
  int v6; // ebx

  for ( i = 0; i < this->m_Win32Fonts.m_Size; ++i )
  {
    m_pMemory = this->m_Win32Fonts.m_Memory.m_pMemory;
    v4 = m_pMemory[i];
    if ( v4 != nullptr )
    {
      CWin32Font::~CWin32Font(this: m_pMemory[i]);
      free(pMem: v4);
    }
  }
  this->m_Win32Fonts.m_Size = 0;
  v5 = this->m_FontAmalgams.m_Size - 1;
  if ( v5 < 0 )
  {
    this->m_FontAmalgams.m_Size = 0;
  }
  else
  {
    v6 = v5;
    do
    {
      CFontAmalgam::~CFontAmalgam(this: &this->m_FontAmalgams.m_Memory.m_pMemory[v6--]);
      --v5;
    }
    while ( v5 >= 0 );
    this->m_FontAmalgams.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013410
// Name: public: void CFontManager::GetTextSize(unsigned long,wchar_t const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::GetTextSize(
        CFontManager *this,
        unsigned int font,
        const wchar_t *text,
        int *wide,
        int *tall)
{
  int v6; // esi
  int v7; // ecx
  const wchar_t *v8; // eax
  int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float flabcA; // [esp+14h] [ebp-14h] BYREF
  float flabcC; // [esp+18h] [ebp-10h] BYREF
  float flWide; // [esp+1Ch] [ebp-Ch] BYREF
  int i; // [esp+20h] [ebp-8h]
  float xx; // [esp+24h] [ebp-4h]

  *wide = 0;
  *tall = 0;
  if ( text != nullptr )
  {
    *tall = CFontAmalgam::GetFontHeight(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
    v6 = *text;
    v7 = 0;
    xx = 0.0;
    i = 0;
    if ( (_WORD)v6 != 0 )
    {
      v8 = text;
      do
      {
        v9 = v8[1];
        if ( (_WORD)v6 == 10 )
        {
          *tall += CFontAmalgam::GetFontHeight(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
          xx = 0.0;
        }
        else if ( (_WORD)v6 != 38 )
        {
          CFontManager::GetKernedCharWidth(
            this,
            font,
            ch: v6,
            chBefore: v7,
            chAfter: v9,
            wide: &flWide,
            &flabcA,
            &flabcC);
          v10 = flWide + xx;
          v11 = (float)*wide;
          xx = flWide + xx;
          if ( xx > v11 )
            *wide = (int)ceil(X: v10);
        }
        v8 = &text[++i];
        v7 = (unsigned __int16)v6;
        v6 = *v8;
      }
      while ( (_WORD)v6 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100135A0
// Name: public: CFontManager::CFontManager(void)
// Source: json
//------------------------------------------------------------------------------
CFontManager *__thiscall CFontManager::CFontManager(CFontManager *this)
{
  CFontAmalgam *v2; // eax
  int m_Size; // edx
  CWin32Font **m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  CWin32Font **v6; // eax

  this->m_FontAmalgams.m_Memory.m_nAllocationCount = 128;
  this->m_FontAmalgams.m_Memory.m_nGrowSize = 64;
  this->m_FontAmalgams.m_Memory.m_pMemory = nullptr;
  v2 = (CFontAmalgam *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3584);
  this->m_FontAmalgams.m_Memory.m_pMemory = v2;
  this->m_FontAmalgams.m_Size = 0;
  this->m_FontAmalgams.m_pElements = v2;
  this->m_Win32Fonts.m_Memory.m_pMemory = nullptr;
  this->m_Win32Fonts.m_Memory.m_nAllocationCount = 0;
  this->m_Win32Fonts.m_Memory.m_nGrowSize = 0;
  this->m_Win32Fonts.m_Size = 0;
  this->m_Win32Fonts.m_pElements = nullptr;
  CUtlMemory<CFontAmalgam,int>::EnsureCapacity(this: &this->m_FontAmalgams.m_Memory, num: 100);
  m_Size = this->m_FontAmalgams.m_Size;
  this->m_FontAmalgams.m_pElements = this->m_FontAmalgams.m_Memory.m_pMemory;
  CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::InsertBefore(this: &this->m_FontAmalgams, elem: m_Size);
  if ( this->m_Win32Fonts.m_Memory.m_nAllocationCount < 100 && this->m_Win32Fonts.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Win32Fonts.m_Memory.m_pMemory;
    this->m_Win32Fonts.m_Memory.m_nAllocationCount = 100;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (CWin32Font **)((int (__stdcall *)(CWin32Font **, int))v5->Realloc_2)(a1: m_pMemory, a2: 400);
    else
      v6 = (CWin32Font **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 400);
    this->m_Win32Fonts.m_Memory.m_pMemory = v6;
  }
  this->m_Win32Fonts.m_pElements = this->m_Win32Fonts.m_Memory.m_pMemory;
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013670
// Name: public: unsigned long CFontManager::CreateFont(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::CreateFont(CFontManager *this)
{
  return CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::InsertBefore(
           this: &this->m_FontAmalgams,
           elem: this->m_FontAmalgams.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x10013680
// Name: private: class CWin32Font __near * CFontManager::CreateOrFindWin32Font(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontManager::CreateOrFindWin32Font(
        CFontManager *this,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags)
{
  int v8; // edi
  CWin32Font *v9; // ecx
  CWin32Font *v10; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWin32Font **m_pMemory; // ecx
  int v14; // eax
  CWin32Font *v15; // eax
  CWin32Font *v16; // eax
  CWin32Font *v17; // ecx
  CWin32Font **v19; // edx
  CWin32Font *v20; // ebx

  v8 = 0;
  if ( this->m_Win32Fonts.m_Size > 0 )
  {
    while ( 1 )
    {
      v9 = this->m_Win32Fonts.m_Memory.m_pMemory[v8];
      if ( v9->IsEqualTo(this: v9, a2: windowsFontName, a3: tall, a4: weight, a5: blur, a6: scanlines, a7: flags) )
        break;
      if ( ++v8 >= this->m_Win32Fonts.m_Size )
        goto LABEL_6;
    }
    v10 = this->m_Win32Fonts.m_Memory.m_pMemory[v8];
    if ( v10 != nullptr )
      return v10;
  }
LABEL_6:
  m_Size = this->m_Win32Fonts.m_Size;
  m_nAllocationCount = this->m_Win32Fonts.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Win32Fonts,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Win32Fonts.m_Size;
  m_pMemory = this->m_Win32Fonts.m_Memory.m_pMemory;
  v14 = this->m_Win32Fonts.m_Size - m_Size - 1;
  this->m_Win32Fonts.m_pElements = m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
  v15 = (CWin32Font *)operator new(nSize: 0x44u);
  if ( v15 != nullptr )
    v16 = CWin32Font::CWin32Font(this: v15);
  else
    v16 = nullptr;
  this->m_Win32Fonts.m_Memory.m_pMemory[m_Size] = v16;
  v17 = this->m_Win32Fonts.m_Memory.m_pMemory[m_Size];
  if ( v17->Create(this: v17, a2: windowsFontName, a3: tall, a4: weight, a5: blur, a6: scanlines, a7: flags) != 0 )
    return this->m_Win32Fonts.m_Memory.m_pMemory[m_Size];
  v19 = this->m_Win32Fonts.m_Memory.m_pMemory;
  v20 = v19[m_Size];
  if ( v20 != nullptr )
  {
    CWin32Font::~CWin32Font(this: v19[m_Size]);
    free(pMem: v20);
  }
  if ( this->m_Win32Fonts.m_Size - m_Size - 1 > 0 )
    _V_memmove(
      dest: &this->m_Win32Fonts.m_Memory.m_pMemory[m_Size],
      src: &this->m_Win32Fonts.m_Memory.m_pMemory[m_Size + 1],
      count: 4 * (this->m_Win32Fonts.m_Size - m_Size - 1));
  --this->m_Win32Fonts.m_Size;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100137B0
// Name: private: class CBitmapFont __near * CFontManager::CreateOrFindBitmapFont(char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
CBitmapFont *__thiscall CFontManager::CreateOrFindBitmapFont(
        CFontManager *this,
        const char *windowsFontName,
        float scalex,
        float scaley,
        int flags)
{
  int v6; // ebx
  CWin32Font *v7; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Win32Fonts; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v12; // eax
  CBitmapFont *v13; // eax
  CBitmapFont *v14; // ebx

  v6 = 0;
  if ( this->m_Win32Fonts.m_Size <= 0 )
  {
LABEL_5:
    m_nAllocationCount = this->m_Win32Fonts.m_Memory.m_nAllocationCount;
    p_m_Win32Fonts = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Win32Fonts;
    m_Size = this->m_Win32Fonts.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: p_m_Win32Fonts, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Win32Fonts[1].m_pMemory;
    m_pMemory = p_m_Win32Fonts->m_pMemory;
    v12 = (int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1;
    p_m_Win32Fonts[1].m_nAllocationCount = (int)p_m_Win32Fonts->m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = (CBitmapFont *)operator new(nSize: 0x50u);
    if ( v13 != nullptr )
      v14 = CBitmapFont::CBitmapFont(this: v13);
    else
      v14 = nullptr;
    if ( ((unsigned __int8 (__thiscall *)(CBitmapFont *, const char *, _DWORD, _DWORD, int))v14->Create_2)(
           a1: v14,
           a2: windowsFontName,
           a3: LODWORD(scalex),
           a4: LODWORD(scaley),
           a5: flags) != 0 )
    {
      p_m_Win32Fonts->m_pMemory[m_Size] = (vgui::TreeNode *)v14;
      return v14;
    }
    else
    {
      CBitmapFont::~CBitmapFont(this: v14);
      free(pMem: v14);
      if ( (int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1 > 0 )
        _V_memmove(
          dest: &p_m_Win32Fonts->m_pMemory[m_Size],
          src: &p_m_Win32Fonts->m_pMemory[m_Size + 1],
          count: 4 * ((int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1));
      --p_m_Win32Fonts[1].m_pMemory;
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = this->m_Win32Fonts.m_Memory.m_pMemory[v6];
      if ( (v7->GetFlags(this: v7) & 0x800) != 0
        && ((unsigned __int8 (__thiscall *)(CWin32Font *, const char *, _DWORD, _DWORD, int))v7->__vftable[1].GetCharRGBA)(
             a1: v7,
             a2: windowsFontName,
             a3: LODWORD(scalex),
             a4: LODWORD(scaley),
             a5: flags) != 0 )
      {
        return (CBitmapFont *)v7;
      }
      if ( ++v6 >= this->m_Win32Fonts.m_Size )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100138F0
// Name: public: bool CFontManager::SetFontGlyphSet(unsigned long,char const __near *,int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontManager::SetFontGlyphSet(
        CFontManager *this,
        unsigned int font,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags,
        int nRangeMin,
        int nRangeMax)
{
  unsigned int v11; // esi
  vgui::Image *v12; // ecx
  CWin32Font *Win32Font; // ebx
  int v14; // esi
  const char **v15; // eax
  const char *ForeignFallbackFontName; // esi
  CWin32Font *v17; // eax
  CWin32Font *v18; // esi
  int v19; // ebx
  int v20; // edi
  int v22; // esi
  FallbackFont_t *v23; // eax
  CWin32Font *winFont; // [esp+Ch] [ebp-8h]
  CFontManager *v25; // [esp+10h] [ebp-4h]
  unsigned int fonta; // [esp+1Ch] [ebp+8h]

  v11 = font;
  v12 = (vgui::Image *)&this->m_FontAmalgams.m_Memory.m_pMemory[font];
  v25 = this;
  fonta = font;
  if ( CFontAmalgam::GetCount(this: v12) > 0 )
    CFontAmalgam::RemoveAll(this: &this->m_FontAmalgams.m_Memory.m_pMemory[v11]);
  if ( _V_stricmp(s1: this->m_szLanguage, s2: "russian") == 0 || _V_stricmp(s1: this->m_szLanguage, s2: "polish") == 0 )
  {
    if ( _V_stricmp(s1: windowsFontName, s2: "universltstd-cn") != 0
      && _V_stricmp(s1: windowsFontName, s2: "universltstd-lightcn") != 0 )
    {
      if ( _V_stricmp(s1: windowsFontName, s2: "universltstd-boldcn") == 0 )
        windowsFontName = "UniversLTCYR-67BoldCond";
    }
    else
    {
      windowsFontName = "UniversLTCYR-57Condensed";
    }
  }
  Win32Font = CFontManager::CreateOrFindWin32Font(this, windowsFontName, tall, weight, blur, scanlines, flags);
  winFont = Win32Font;
  while ( 1 )
  {
    v14 = 0;
    if ( g_szValidAsianFonts[0] != nullptr )
    {
      v15 = g_szValidAsianFonts;
      while ( _V_stricmp(s1: *v15, s2: windowsFontName) != 0 )
      {
        v15 = &g_szValidAsianFonts[++v14];
        if ( *v15 == nullptr )
          goto LABEL_15;
      }
      if ( Win32Font != nullptr )
      {
LABEL_39:
        CFontAmalgam::AddFont(
          this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
          pFont: Win32Font,
          lowRange: 0,
          highRange: 0xFFFF);
        return 1;
      }
      goto LABEL_31;
    }
LABEL_15:
    ForeignFallbackFontName = CFontManager::GetForeignFallbackFontName(this);
    if ( Win32Font != nullptr && _V_stricmp(s1: ForeignFallbackFontName, s2: windowsFontName) == 0 )
      goto LABEL_39;
    v17 = CFontManager::CreateOrFindWin32Font(
            this,
            windowsFontName: ForeignFallbackFontName,
            tall,
            weight,
            blur,
            scanlines,
            flags);
    v18 = v17;
    if ( Win32Font == nullptr )
    {
      if ( v17 != nullptr )
      {
        CFontAmalgam::AddFont(
          this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
          pFont: v17,
          lowRange: 0,
          highRange: 0xFFFF);
        return 1;
      }
      goto LABEL_31;
    }
    if ( v17 != nullptr )
      break;
LABEL_31:
    v22 = 0;
    if ( g_FallbackFonts[0].font != nullptr )
    {
      v23 = g_FallbackFonts;
      while ( _V_stricmp(s1: v23->font, s2: windowsFontName) != 0 )
      {
        v23 = &g_FallbackFonts[++v22];
        if ( v23->font == nullptr )
          goto LABEL_35;
      }
      windowsFontName = off_1012E4BC[2 * v22];
    }
    else
    {
LABEL_35:
      windowsFontName = off_1012E4BC[2 * v22];
    }
    if ( windowsFontName == nullptr )
      return 0;
  }
  v19 = 0;
  v20 = 255;
  if ( nRangeMin > 0 || nRangeMax > 0 )
  {
    v19 = nRangeMin;
    v20 = nRangeMax;
    if ( nRangeMin > nRangeMax )
    {
      v19 = nRangeMax;
      v20 = nRangeMin;
    }
    if ( v19 > 0 )
      CFontAmalgam::AddFont(
        this: &v25->m_FontAmalgams.m_Memory.m_pMemory[fonta],
        pFont: v17,
        lowRange: 0,
        highRange: v19 - 1);
  }
  CFontAmalgam::AddFont(
    this: &v25->m_FontAmalgams.m_Memory.m_pMemory[fonta],
    pFont: winFont,
    lowRange: v19,
    highRange: v20);
  if ( v20 < 0xFFFF )
    CFontAmalgam::AddFont(
      this: &v25->m_FontAmalgams.m_Memory.m_pMemory[fonta],
      pFont: v18,
      lowRange: v20 + 1,
      highRange: 0xFFFF);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013B60
// Name: public: bool CFontManager::SetBitmapFontGlyphSet(unsigned long,char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontManager::SetBitmapFontGlyphSet(
        CFontManager *this,
        unsigned int font,
        const char *windowsFontName,
        float scalex,
        float scaley,
        int flags)
{
  unsigned int v7; // esi
  CBitmapFont *BitmapFont; // eax

  v7 = font;
  if ( CFontAmalgam::GetCount(this: (vgui::Image *)&this->m_FontAmalgams.m_Memory.m_pMemory[font]) > 0 )
    CFontAmalgam::RemoveAll(this: &this->m_FontAmalgams.m_Memory.m_pMemory[v7]);
  BitmapFont = CFontManager::CreateOrFindBitmapFont(this, windowsFontName, scalex, scaley, flags);
  if ( BitmapFont == nullptr )
    return 0;
  CFontAmalgam::AddFont(
    this: &this->m_FontAmalgams.m_Memory.m_pMemory[v7],
    pFont: BitmapFont,
    lowRange: 0,
    highRange: 255);
  return 1;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004B9E00
// Name: class CFontManager __near & FontManager(void)
// Source: json
//------------------------------------------------------------------------------
CFontManager *__cdecl FontManager()
{
  return &s_FontManager;
}

//------------------------------------------------------------------------------
// Address: 0x004B9E10
// Name: public: void CFontManager::SetLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::SetLanguage(CFontManager *this, char *pLanguage)
{
  V_strncpy(pDest: this->m_szLanguage, pSrc: pLanguage, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x004B9E30
// Name: public: char const __near * CFontManager::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFontManager::GetLanguage(CFontManager *this)
{
  return this->m_szLanguage;
}

//------------------------------------------------------------------------------
// Address: 0x004B9E40
// Name: private: bool CFontManager::IsFontForeignLanguageCapable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontManager::IsFontForeignLanguageCapable(CFontManager *this, const char *windowsFontName)
{
  int v2; // esi
  const char **v3; // eax

  v2 = 0;
  if ( g_szValidAsianFonts[0] == nullptr )
    return 0;
  v3 = g_szValidAsianFonts;
  while ( _V_stricmp(s1: *v3, s2: windowsFontName) != 0 )
  {
    ++v2;
    v3 = (const char **)(4 * v2 + 6024072);
    if ( g_szValidAsianFonts[v2] == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9E90
// Name: private: char const __near * CFontManager::GetForeignFallbackFontName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFontManager::GetForeignFallbackFontName(CFontManager *this)
{
  int v2; // esi
  char *m_szLanguage; // edi
  Win98ForeignFallbackFont_t *v4; // eax

  if ( s_bSupportsUnicode )
    return "Tahoma";
  v2 = 0;
  if ( g_Win98ForeignFallbackFonts[0].language != nullptr )
  {
    m_szLanguage = this->m_szLanguage;
    v4 = g_Win98ForeignFallbackFonts;
    do
    {
      if ( _V_stricmp(s1: v4->language, s2: m_szLanguage) == 0 )
        break;
      ++v2;
      v4 = (Win98ForeignFallbackFont_t *)(8 * v2 + 6024128);
    }
    while ( g_Win98ForeignFallbackFonts[v2].language != nullptr );
  }
  return off_5BEBC4[2 * v2];
}

//------------------------------------------------------------------------------
// Address: 0x004BA010
// Name: public: char const __near * CFontManager::GetFontName(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFontManager::GetFontName(CFontManager *this, unsigned int font)
{
  return CFontAmalgam::GetFontName(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], i: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004BA030
// Name: public: class CWin32Font __near * CFontManager::GetFontForChar(unsigned long,wchar_t)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontManager::GetFontForChar(CFontManager *this, unsigned int font, wchar_t wch)
{
  return CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch: wch);
}

//------------------------------------------------------------------------------
// Address: 0x004BA050
// Name: public: void CFontManager::GetCharABCwide(unsigned long,int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::GetCharABCwide(CFontManager *this, unsigned int font, int ch, int *a, int *b, int *c)
{
  CWin32Font *FontForChar; // eax

  FontForChar = CFontAmalgam::GetFontForChar(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], ch);
  if ( FontForChar != nullptr )
  {
    FontForChar->GetCharABCWidths(this: FontForChar, a2: ch, a3: a, a4: b, a5: c);
  }
  else
  {
    *c = 0;
    *a = 0;
    *b = ConCommandBase::GetFlags(this: (CVTFTexture *)&this->m_FontAmalgams.m_Memory.m_pMemory[font]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA0C0
// Name: public: int CFontManager::GetFontTall(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::GetFontTall(CFontManager *this, unsigned int font)
{
  return CFontAmalgam::GetFontHeight(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
}

//------------------------------------------------------------------------------
// Address: 0x004BA0E0
// Name: public: bool CFontManager::IsFontAdditive(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontManager::IsFontAdditive(CFontManager *this, unsigned int font)
{
  return ((unsigned __int16)CFontAmalgam::GetFlags(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], i: 0) >> 8) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA110
// Name: public: bool CFontManager::IsBitmapFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontManager::IsBitmapFont(CFontManager *this, unsigned int font)
{
  return (CFontAmalgam::GetFlags(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font], i: 0) & 0x800) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA140
// Name: public: int CFontManager::GetCharacterWidth(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFontManager::GetCharacterWidth(CFontManager *this, unsigned int font, int ch)
{
  int v3; // edi
  int v6; // [esp+8h] [ebp-4h] BYREF

  v3 = ch;
  if ( iswcntrl(c: ch) != 0 )
    return 0;
  CFontManager::GetCharABCwide(this, font, ch: v3, a: (int *)&font, b: &ch, c: &v6);
  return v6 + font + ch;
}

//------------------------------------------------------------------------------
// Address: 0x004BA190
// Name: public: bool CFontManager::GetFontUnderlined(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontManager::GetFontUnderlined(CFontManager *this, unsigned int font)
{
  return CFontAmalgam::GetUnderlined(this: &this->m_FontAmalgams.m_Memory.m_pMemory[font]);
}

//------------------------------------------------------------------------------
// Address: 0x004BA1F0
// Name: public: void CFontManager::ClearAllFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontManager::ClearAllFonts(CFontManager *this)
{
  int i; // edi
  CWin32Font **m_pMemory; // eax
  CWin32Font *v4; // ebx
  int v5; // edi
  int v6; // ebx

  for ( i = 0; i < this->m_Win32Fonts.m_Size; ++i )
  {
    m_pMemory = this->m_Win32Fonts.m_Memory.m_pMemory;
    v4 = m_pMemory[i];
    if ( v4 != nullptr )
    {
      CWin32Font::~CWin32Font(this: m_pMemory[i]);
      free(pMem: v4);
    }
  }
  this->m_Win32Fonts.m_Size = 0;
  v5 = this->m_FontAmalgams.m_Size - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      CFontAmalgam::~CFontAmalgam(this: &this->m_FontAmalgams.m_Memory.m_pMemory[v6]);
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
  }
  this->m_FontAmalgams.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA340
// Name: public: CFontManager::CFontManager(void)
// Source: json
//------------------------------------------------------------------------------
CFontManager *__thiscall CFontManager::CFontManager(CFontManager *this)
{
  CFontAmalgam *v2; // eax
  int m_Size; // edx

  this->m_FontAmalgams.m_Memory.m_nAllocationCount = 128;
  this->m_FontAmalgams.m_Memory.m_nGrowSize = 64;
  this->m_FontAmalgams.m_Memory.m_pMemory = nullptr;
  v2 = (CFontAmalgam *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3584);
  this->m_FontAmalgams.m_Memory.m_pMemory = v2;
  this->m_FontAmalgams.m_Size = 0;
  this->m_FontAmalgams.m_pElements = v2;
  this->m_Win32Fonts.m_Memory.m_pMemory = nullptr;
  this->m_Win32Fonts.m_Memory.m_nAllocationCount = 0;
  this->m_Win32Fonts.m_Memory.m_nGrowSize = 0;
  this->m_Win32Fonts.m_Size = 0;
  this->m_Win32Fonts.m_pElements = nullptr;
  CUtlMemory<CFontAmalgam,int>::EnsureCapacity(this: &this->m_FontAmalgams.m_Memory, num: 100);
  m_Size = this->m_FontAmalgams.m_Size;
  this->m_FontAmalgams.m_pElements = this->m_FontAmalgams.m_Memory.m_pMemory;
  CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::InsertBefore(this: &this->m_FontAmalgams, elem: m_Size);
  CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: &this->m_Win32Fonts, num: 100);
  setlocale(_category: 2u, _locale: (char *)defaultValue);
  setlocale(_category: 5u, _locale: (char *)defaultValue);
  setlocale(_category: 1u, _locale: (char *)defaultValue);
  setlocale(_category: 3u, _locale: (char *)defaultValue);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BA3E0
// Name: public: unsigned long CFontManager::CreateFont(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontManager::CreateFont(CFontManager *this)
{
  return CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::InsertBefore(
           this: &this->m_FontAmalgams,
           elem: this->m_FontAmalgams.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x004BA3F0
// Name: private: class CWin32Font __near * CFontManager::CreateOrFindWin32Font(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontManager::CreateOrFindWin32Font(
        CFontManager *this,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags)
{
  int v8; // edi
  CWin32Font *v9; // ecx
  CWin32Font *v10; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Win32Fonts; // esi
  S3RGBA *m_pMemory; // ecx
  int v15; // eax
  bool v16; // zf
  CWin32Font *v17; // eax
  CWin32Font *v18; // eax
  void *v20; // ebx

  v8 = 0;
  if ( this->m_Win32Fonts.m_Size > 0 )
  {
    while ( 1 )
    {
      v9 = this->m_Win32Fonts.m_Memory.m_pMemory[v8];
      if ( v9->IsEqualTo(this: v9, a2: windowsFontName, a3: tall, a4: weight, a5: blur, a6: scanlines, a7: flags) )
        break;
      if ( ++v8 >= this->m_Win32Fonts.m_Size )
        goto LABEL_6;
    }
    v10 = this->m_Win32Fonts.m_Memory.m_pMemory[v8];
    if ( v10 != nullptr )
      return v10;
  }
LABEL_6:
  m_Size = this->m_Win32Fonts.m_Size;
  m_nAllocationCount = this->m_Win32Fonts.m_Memory.m_nAllocationCount;
  p_m_Win32Fonts = (CUtlMemory<S3RGBA,int> *)&this->m_Win32Fonts;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Win32Fonts, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Win32Fonts[1].m_pMemory;
  m_pMemory = p_m_Win32Fonts->m_pMemory;
  v15 = (int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1;
  v16 = (S3RGBA *)((char *)p_m_Win32Fonts[1].m_pMemory - m_Size) == (S3RGBA *)1;
  p_m_Win32Fonts[1].m_nAllocationCount = (int)p_m_Win32Fonts->m_pMemory;
  if ( v15 >= 0 && !v16 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v15);
  v17 = (CWin32Font *)MemAlloc_Alloc(nSize: 0x44u);
  if ( v17 != nullptr )
    v18 = CWin32Font::CWin32Font(this: v17);
  else
    v18 = nullptr;
  p_m_Win32Fonts->m_pMemory[m_Size] = (S3RGBA)v18;
  if ( (***(unsigned int (__thiscall ****)(_DWORD, const char *, int, int, int, int, int))&p_m_Win32Fonts->m_pMemory[m_Size])(
         a1: *(_DWORD *)&p_m_Win32Fonts->m_pMemory[m_Size],
         a2: windowsFontName,
         a3: tall,
         a4: weight,
         a5: blur,
         a6: scanlines,
         a7: flags) != 0 )
    return (CWin32Font *)p_m_Win32Fonts->m_pMemory[m_Size];
  v20 = (void *)p_m_Win32Fonts->m_pMemory[m_Size];
  if ( v20 != nullptr )
  {
    CWin32Font::~CWin32Font(this: *(CWin32Font **)&p_m_Win32Fonts->m_pMemory[m_Size]);
    free(pMem: v20);
  }
  if ( (int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&p_m_Win32Fonts->m_pMemory[m_Size],
      src: (unsigned __int8 *)&p_m_Win32Fonts->m_pMemory[m_Size + 1],
      count: 4 * ((int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1));
  --p_m_Win32Fonts[1].m_pMemory;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BA530
// Name: private: class CBitmapFont __near * CFontManager::CreateOrFindBitmapFont(char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
CBitmapFont *__thiscall CFontManager::CreateOrFindBitmapFont(
        CFontManager *this,
        const char *windowsFontName,
        float scalex,
        float scaley,
        int flags)
{
  int v6; // ebx
  CWin32Font *v7; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Win32Fonts; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v12; // eax
  bool v13; // zf
  CBitmapFont *v14; // eax
  CBitmapFont *v15; // ebx

  v6 = 0;
  if ( this->m_Win32Fonts.m_Size <= 0 )
  {
LABEL_5:
    m_nAllocationCount = this->m_Win32Fonts.m_Memory.m_nAllocationCount;
    p_m_Win32Fonts = (CUtlMemory<S3RGBA,int> *)&this->m_Win32Fonts;
    m_Size = this->m_Win32Fonts.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Win32Fonts, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Win32Fonts[1].m_pMemory;
    m_pMemory = p_m_Win32Fonts->m_pMemory;
    v12 = (int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1;
    v13 = (S3RGBA *)((char *)p_m_Win32Fonts[1].m_pMemory - m_Size) == (S3RGBA *)1;
    p_m_Win32Fonts[1].m_nAllocationCount = (int)p_m_Win32Fonts->m_pMemory;
    if ( v12 >= 0 && !v13 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v12);
    v14 = (CBitmapFont *)MemAlloc_Alloc(nSize: 0x50u);
    if ( v14 != nullptr )
      v15 = CBitmapFont::CBitmapFont(this: v14);
    else
      v15 = nullptr;
    if ( ((unsigned __int8 (__thiscall *)(CBitmapFont *, const char *, _DWORD, _DWORD, int))v15->Create_2)(
           a1: v15,
           a2: windowsFontName,
           a3: LODWORD(scalex),
           a4: LODWORD(scaley),
           a5: flags) != 0 )
    {
      p_m_Win32Fonts->m_pMemory[m_Size] = (S3RGBA)v15;
      return v15;
    }
    else
    {
      CBitmapFont::~CBitmapFont(this: v15);
      free(pMem: v15);
      if ( (int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&p_m_Win32Fonts->m_pMemory[m_Size],
          src: (unsigned __int8 *)&p_m_Win32Fonts->m_pMemory[m_Size + 1],
          count: 4 * ((int)p_m_Win32Fonts[1].m_pMemory - m_Size - 1));
      --p_m_Win32Fonts[1].m_pMemory;
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = this->m_Win32Fonts.m_Memory.m_pMemory[v6];
      if ( (v7->GetFlags(this: v7) & 0x800) != 0
        && ((unsigned __int8 (__thiscall *)(CWin32Font *, const char *, _DWORD, _DWORD, int))v7->__vftable[1].GetCharRGBA)(
             a1: v7,
             a2: windowsFontName,
             a3: LODWORD(scalex),
             a4: LODWORD(scaley),
             a5: flags) != 0 )
      {
        return (CBitmapFont *)v7;
      }
      if ( ++v6 >= this->m_Win32Fonts.m_Size )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA670
// Name: public: bool CFontManager::SetFontGlyphSet(unsigned long,char const __near *,int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontManager::SetFontGlyphSet(
        CFontManager *this,
        unsigned int font,
        CWin32Font *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags,
        int nRangeMin,
        int nRangeMax)
{
  int v11; // edi
  CVTFTexture *v12; // ecx
  const char *v13; // ebp
  CWin32Font *Win32Font; // ebx
  const char *ForeignFallbackFontName; // eax
  const char *v16; // edi
  CWin32Font *v17; // eax
  CWin32Font *v18; // edi
  int v19; // ebp
  int v20; // ebx
  int v22; // edi
  FallbackFont_t *v23; // eax
  unsigned int fonta; // [esp+14h] [ebp+4h]
  CWin32Font *winFont; // [esp+18h] [ebp+8h]

  v11 = 28 * font;
  v12 = (CVTFTexture *)&this->m_FontAmalgams.m_Memory.m_pMemory[font];
  fonta = font;
  if ( CFontAmalgam::GetCount(this: v12) > 0 )
    CFontAmalgam::RemoveAll(this: (CFontAmalgam *)((char *)this->m_FontAmalgams.m_Memory.m_pMemory + v11));
  v13 = (const char *)windowsFontName;
  Win32Font = CFontManager::CreateOrFindWin32Font(
                this,
                (const char *)windowsFontName,
                tall,
                weight,
                blur,
                scanlines,
                flags);
  winFont = Win32Font;
  while ( CFontManager::IsFontForeignLanguageCapable(this, windowsFontName: v13) != 0 )
  {
    if ( Win32Font != nullptr )
    {
      CFontAmalgam::AddFont(
        this: (CFontAmalgam *)((char *)this->m_FontAmalgams.m_Memory.m_pMemory + v11),
        pFont: Win32Font,
        lowRange: 0,
        highRange: 0xFFFF);
      return 1;
    }
LABEL_21:
    v22 = 0;
    if ( g_FallbackFonts[0].font != nullptr )
    {
      v23 = g_FallbackFonts;
      do
      {
        if ( _V_stricmp(s1: v23->font, s2: v13) == 0 )
          break;
        ++v22;
        v23 = (FallbackFont_t *)(8 * v22 + 6024080);
      }
      while ( g_FallbackFonts[v22].font != nullptr );
    }
    v13 = off_5BEB94[2 * v22];
    if ( v13 == nullptr )
      return 0;
    v11 = fonta * 28;
  }
  ForeignFallbackFontName = CFontManager::GetForeignFallbackFontName(this);
  v16 = ForeignFallbackFontName;
  if ( Win32Font != nullptr && _V_stricmp(s1: ForeignFallbackFontName, s2: v13) == 0 )
  {
    CFontAmalgam::AddFont(
      this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
      pFont: Win32Font,
      lowRange: 0,
      highRange: 0xFFFF);
    return 1;
  }
  v17 = CFontManager::CreateOrFindWin32Font(this, windowsFontName: v16, tall, weight, blur, scanlines, flags);
  v18 = v17;
  if ( Win32Font == nullptr )
  {
    if ( v17 != nullptr )
    {
      CFontAmalgam::AddFont(
        this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
        pFont: v17,
        lowRange: 0,
        highRange: 0xFFFF);
      return 1;
    }
    goto LABEL_21;
  }
  if ( v17 == nullptr )
    goto LABEL_21;
  v19 = 0;
  v20 = 255;
  if ( nRangeMin > 0 || nRangeMax > 0 )
  {
    v19 = nRangeMin;
    v20 = nRangeMax;
    if ( nRangeMin > nRangeMax )
    {
      v19 = nRangeMax;
      v20 = nRangeMin;
    }
    if ( v19 > 0 )
      CFontAmalgam::AddFont(
        this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
        pFont: v17,
        lowRange: 0,
        highRange: v19 - 1);
  }
  CFontAmalgam::AddFont(
    this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
    pFont: winFont,
    lowRange: v19,
    highRange: v20);
  if ( v20 < 0xFFFF )
    CFontAmalgam::AddFont(
      this: &this->m_FontAmalgams.m_Memory.m_pMemory[fonta],
      pFont: v18,
      lowRange: v20 + 1,
      highRange: 0xFFFF);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA850
// Name: public: bool CFontManager::SetBitmapFontGlyphSet(unsigned long,char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontManager::SetBitmapFontGlyphSet(
        CFontManager *this,
        unsigned int font,
        const char *windowsFontName,
        float scalex,
        float scaley,
        int flags)
{
  unsigned int v7; // esi
  CBitmapFont *BitmapFont; // eax

  v7 = font;
  if ( CFontAmalgam::GetCount(this: (CVTFTexture *)&this->m_FontAmalgams.m_Memory.m_pMemory[font]) > 0 )
    CFontAmalgam::RemoveAll(this: &this->m_FontAmalgams.m_Memory.m_pMemory[v7]);
  BitmapFont = CFontManager::CreateOrFindBitmapFont(this, windowsFontName, scalex, scaley, flags);
  if ( BitmapFont == nullptr )
    return 0;
  CFontAmalgam::AddFont(
    this: &this->m_FontAmalgams.m_Memory.m_pMemory[v7],
    pFont: BitmapFont,
    lowRange: 0,
    highRange: 255);
  return 1;
}

} // namespace vgui_perftest
