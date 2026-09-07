// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_surfacelib/win32font.cpp
// Functions: 17
// ============================================================

#include "vgui2\vgui_surfacelib\win32font.h"

//------------------------------------------------------------------------------
// Address: 0x10020CA0
// Name: public: virtual bool CWin32Font::Create(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Font::Create(
        CWin32Font *this,
        char *windowsFontName,
        int tall,
        int weight,
        unsigned __int16 blur,
        unsigned __int16 scanlines,
        unsigned int flags)
{
  unsigned int v8; // edi
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // dx
  DWORD v11; // ebx
  HFONT__ *FontA; // eax
  __int16 tmHeight; // bx
  __int16 tmMaxCharWidth; // dx
  char tmAscent; // al
  __int16 v17; // cx
  unsigned __int16 v18; // dx
  unsigned __int16 v19; // ax
  HDC__ *m_hDC; // ecx
  HBITMAP__ *DIBSection; // eax
  HDC__ *v22; // [esp-8h] [ebp-78h]
  tagTEXTMETRICA tm; // [esp+Ch] [ebp-64h] BYREF
  tagBITMAPINFOHEADER header; // [esp+44h] [ebp-2Ch] BYREF
  CUtlSymbol v25; // [esp+6Eh] [ebp-2h] BYREF

  CUtlSymbol::CUtlSymbol(this: &v25, pStr: windowsFontName);
  v8 = flags;
  this->m_szName = v25;
  v9 = blur;
  this->m_iWeight = weight;
  this->m_iTall = tall;
  v10 = scanlines;
  this->m_iBlur = v9;
  this->m_iScanLines = v10;
  *((_DWORD *)this + 9) = *((_DWORD *)this + 9) & 0xC0FFFFFF
                        | ((v8 & 0x200
                          | (2
                           * (v8 & 0x80 | (8 * (v8 & 0x100 | (2 * (v8 & 0x40 | (2 * (v8 & 0x10 | ((v8 & 2) << 6)))))))))) << 16);
  this->m_iFlags = v8;
  v11 = (v8 >> 2) & 2;
  if ( _V_stricmp(s1: windowsFontName, s2: "win98japanese") == 0 )
  {
    v11 = 128;
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&weight + 1, pStr: "Tahoma");
    this->m_szName.m_Id = HIWORD(weight);
  }
  this->m_hDC = CreateCompatibleDC(hdc: nullptr);
  FontA = CreateFontA(
            cHeight: tall,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: this->m_iWeight,
            bItalic: v8 & 1,
            bUnderline: v8 & 2,
            bStrikeOut: v8 & 4,
            iCharSet: v11,
            iOutPrecision: 0,
            iClipPrecision: 0,
            iQuality: ((*((_DWORD *)this + 9) & 0x4000000) != 0) + 3,
            iPitchAndFamily: 0,
            pszFaceName: windowsFontName);
  this->m_hFont = FontA;
  if ( FontA != nullptr )
  {
    SetMapMode(hdc: this->m_hDC, iMode: 1);
    SelectObject(hdc: this->m_hDC, h: this->m_hFont);
    SetTextAlign(hdc: this->m_hDC, align: 1u);
    memset(dst: (unsigned __int8 *)&tm, value: 0, count: sizeof(tm));
    if ( GetTextMetricsA(hdc: this->m_hDC, lptm: &tm) )
    {
      tmHeight = tm.tmHeight;
      tmMaxCharWidth = tm.tmMaxCharWidth;
      tmAscent = tm.tmAscent;
      *((_BYTE *)this + 36) = LOBYTE(tm.tmHeight)
                            + (HIBYTE(*((_DWORD *)this + 9)) & 1)
                            + 2 * ((*((_DWORD *)this + 9) & 0x2000000) != 0);
      *((_BYTE *)this + 38) = tmAscent;
      *((_BYTE *)this + 37) = tmMaxCharWidth;
      v17 = 2 * ((*((_DWORD *)this + 9) & 0x2000000) != 0);
      v18 = v17 + tmMaxCharWidth;
      v19 = tmHeight + v17 + ((*((_DWORD *)this + 9) & 0x1000000) != 0);
      this->m_rgiBitmapSize[0] = v18;
      *(_DWORD *)&header.biPlanes = 0;
      header.biHeight = -v19;
      this->m_rgiBitmapSize[1] = v19;
      header.biSize = 0;
      header.biWidth = v18;
      m_hDC = this->m_hDC;
      header.biSize = 40;
      *(_DWORD *)&header.biPlanes = 2097153;
      memset(&header.biCompression, 0, 24);
      DIBSection = CreateDIBSection(
                     hdc: m_hDC,
                     pbmi: (const BITMAPINFO *)&header,
                     usage: 0,
                     ppvBits: (void **)&this->m_pBuf,
                     hSection: nullptr,
                     offset: 0);
      v22 = this->m_hDC;
      this->m_hDIB = DIBSection;
      SelectObject(hdc: v22, h: DIBSection);
      return 1;
    }
    else
    {
      this->m_szName.m_Id = -1;
      return 0;
    }
  }
  else
  {
    _Error(a1: "Couldn't create windows font '%s'\n", windowsFontName);
    this->m_szName.m_Id = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020F00
// Name: public: virtual void CWin32Font::GetCharRGBA(wchar_t,int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::GetCharRGBA(
        CWin32Font *this,
        wchar_t ch,
        int rgbaWide,
        int rgbaTall,
        unsigned __int8 *rgba)
{
  void (__thiscall *GetCharABCWidths)(CWin32Font *, int, int *, int *, int *); // edx
  int v7; // ecx
  bool v8; // al
  int v9; // ebx
  DWORD GlyphOutlineA; // eax
  void *v11; // esp
  HDC__ *m_hDC; // ecx
  unsigned int gmBlackBoxX; // edx
  signed int v14; // eax
  int v15; // edi
  unsigned int v16; // ebx
  unsigned int v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  unsigned __int8 v20; // dl
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // ebx
  int v27; // edi
  int v28; // eax
  int v29; // ecx
  int v30; // edx
  unsigned __int8 *v31; // eax
  unsigned __int8 *v32; // edi
  unsigned __int8 v33; // al
  unsigned __int8 v34; // bl
  unsigned __int8 v35; // dl
  int v36; // ecx
  int v37; // ecx
  unsigned __int8 *v38; // eax
  HDC__ *v39; // [esp-20h] [ebp-88h]
  _BYTE v40[12]; // [esp+0h] [ebp-68h] BYREF
  _GLYPHMETRICS glyphMetrics; // [esp+Ch] [ebp-5Ch] BYREF
  tagRECT rect; // [esp+20h] [ebp-48h] BYREF
  _MAT2 mat2; // [esp+30h] [ebp-38h] BYREF
  char mbcs[8]; // [esp+40h] [ebp-28h] BYREF
  int c; // [esp+48h] [ebp-20h] BYREF
  int j; // [esp+4Ch] [ebp-1Ch]
  int a; // [esp+50h] [ebp-18h] BYREF
  unsigned int wch; // [esp+54h] [ebp-14h] BYREF
  int b; // [esp+58h] [ebp-10h] BYREF
  int v50; // [esp+5Ch] [ebp-Ch]
  int xstart; // [esp+60h] [ebp-8h]
  int wide; // [esp+64h] [ebp-4h]

  GetCharABCWidths = this->GetCharABCWidths;
  j = ch;
  GetCharABCWidths(this, a2: ch, a3: &a, a4: &b, a5: &c);
  SelectObject(hdc: this->m_hDC, h: this->m_hFont);
  v7 = *((_DWORD *)this + 9);
  wide = b;
  if ( (v7 & 0x20000000) != 0 )
    wide = c + a + b;
  mat2.eM11.fract = 0;
  mat2.eM11.value = 1;
  memset(&mat2.eM12, 0, 10);
  v8 = (v7 & 0x4000000) != 0;
  mat2.eM22.value = 1;
  v9 = (unsigned __int8)v7;
  xstart = (unsigned __int8)v7;
  if ( ch > 0xFFu && (this->m_iFlags & 0x400) == 0 )
    v8 = false;
  if ( !s_bSupportsUnicode )
  {
    if ( ch == 73 || ch == 49 )
      v8 = false;
    if ( (unsigned __int8)v7 >= 0xDu )
      goto LABEL_37;
  }
  if ( v8
    && (SelectObject(hdc: this->m_hDC, h: this->m_hFont),
        (int)(GlyphOutlineA = GetGlyphOutlineA(
                                hdc: this->m_hDC,
                                uChar: j,
                                fuFormat: 6u,
                                lpgm: &glyphMetrics,
                                cjBuffer: 0,
                                pvBuffer: nullptr,
                                lpmat2: &mat2)) > 0) )
  {
    v11 = alloca(GlyphOutlineA);
    m_hDC = this->m_hDC;
    j = (int)v40;
    GetGlyphOutlineA(
      hdc: m_hDC,
      uChar: ch,
      fuFormat: 6u,
      lpgm: &glyphMetrics,
      cjBuffer: GlyphOutlineA,
      pvBuffer: v40,
      lpmat2: &mat2);
    gmBlackBoxX = glyphMetrics.gmBlackBoxX;
    v14 = glyphMetrics.gmBlackBoxX;
    wide = glyphMetrics.gmBlackBoxX;
    if ( (signed int)glyphMetrics.gmBlackBoxX % 4 != 0 )
    {
      do
        ++v14;
      while ( v14 % 4 != 0 );
      wide = v14;
    }
    v15 = *((unsigned __int8 *)this + 38) - glyphMetrics.gmptGlyphOrigin.y;
    v16 = 0;
    *(_DWORD *)mbcs = v15;
    xstart = 0;
    if ( (int)glyphMetrics.gmBlackBoxX >= b + 2 )
    {
      v16 = (glyphMetrics.gmBlackBoxX - b) >> 1;
      xstart = v16;
    }
    v17 = 0;
    wch = 0;
    if ( glyphMetrics.gmBlackBoxY != 0 )
    {
      v50 = j;
      do
      {
        v18 = v16;
        if ( v16 < gmBlackBoxX )
        {
          j = v15 + v17;
          do
          {
            v19 = v18 + this->m_iBlur + ((*((_DWORD *)this + 9) & 0x2000000) != 0) - v16;
            if ( v19 < rgbaWide )
            {
              if ( j < rgbaTall )
              {
                v20 = *(_BYTE *)(v50 + v18);
                if ( v20 != 0 )
                {
                  v21 = (float)v20 * 0.015625;
                  v22 = 1.0;
                  v23 = 1.0;
                  v24 = 1.0;
                  if ( v21 > 1.0 )
                    v21 = 1.0;
                }
                else
                {
                  v21 = 0.0;
                  v22 = 0.0;
                  v23 = 0.0;
                  v24 = 0.0;
                }
                if ( ch == 9 )
                {
                  v22 = 0.0;
                  v23 = 0.0;
                  v24 = 0.0;
                }
                v25 = &rgba[4 * v19 + 4 * rgbaWide * j];
                *v25 = (int)(float)(v24 * 255.0);
                v25[1] = (int)(float)(v23 * 255.0);
                v25[2] = (int)(float)(v22 * 255.0);
                v25[3] = (int)(float)(v21 * 255.0);
                gmBlackBoxX = glyphMetrics.gmBlackBoxX;
              }
              v16 = xstart;
            }
            ++v18;
          }
          while ( v18 < gmBlackBoxX );
          v17 = wch;
          v15 = *(_DWORD *)mbcs;
        }
        v50 += wide;
        wch = ++v17;
      }
      while ( v17 < glyphMetrics.gmBlackBoxY );
    }
    v26 = rgba;
    v27 = rgbaWide;
  }
  else
  {
LABEL_37:
    SetBkColor(hdc: this->m_hDC, color: 0);
    SetTextColor(hdc: this->m_hDC, color: 0xFFFFFFu);
    SetBkMode(hdc: this->m_hDC, mode: 2);
    if ( (*((_DWORD *)this + 9) & 0x20000000) != 0 )
      MoveToEx(hdc: this->m_hDC, x: 0, y: 0, lppt: nullptr);
    else
      MoveToEx(hdc: this->m_hDC, x: -a, y: 0, lppt: nullptr);
    wch = ch;
    rect.left = 0;
    rect.top = 0;
    rect.bottom = v9;
    v39 = this->m_hDC;
    rect.right = wide;
    if ( s_bSupportsUnicode )
    {
      ExtTextOutW(hdc: v39, x: 0, y: 0, options: 2u, lprect: &rect, lpString: nullptr, c: 0, lpDx: nullptr);
      ExtTextOutW(
        hdc: this->m_hDC,
        x: 0,
        y: 0,
        options: 0,
        lprect: nullptr,
        lpString: (LPCWSTR)&wch,
        c: 1u,
        lpDx: nullptr);
    }
    else
    {
      ExtTextOutA(hdc: v39, x: 0, y: 0, options: 2u, lprect: &rect, lpString: nullptr, c: 0, lpDx: nullptr);
      memset(mbcs, 0, 6);
      WideCharToMultiByte(
        CodePage: 0,
        dwFlags: 0,
        lpWideCharStr: (LPCWCH)&wch,
        cchWideChar: 1,
        lpMultiByteStr: mbcs,
        cbMultiByte: 6,
        lpDefaultChar: nullptr,
        lpUsedDefaultChar: nullptr);
      ExtTextOutA(
        hdc: this->m_hDC,
        x: 0,
        y: 0,
        options: 0,
        lprect: nullptr,
        lpString: mbcs,
        c: strlen(mbcs),
        lpDx: nullptr);
    }
    SetBkMode(hdc: this->m_hDC, mode: 1);
    if ( wide > this->m_rgiBitmapSize[0] )
      wide = this->m_rgiBitmapSize[0];
    v28 = this->m_rgiBitmapSize[1];
    if ( v9 > v28 )
    {
      xstart = this->m_rgiBitmapSize[1];
      v9 = v28;
    }
    v29 = (*((_DWORD *)this + 9) & 0x2000000) != 0;
    v30 = v29;
    j = v29;
    if ( v29 >= v9 - v29 )
    {
      v27 = rgbaWide;
    }
    else
    {
      v50 = rgbaWide * v29;
      do
      {
        for ( ; v29 < wide - ((*((_DWORD *)this + 9) & 0x2000000) != 0) - ((*((_DWORD *)this + 9) & 0x1000000) != 0); ++v29 )
        {
          if ( v29 < rgbaWide && v30 < rgbaTall )
          {
            v31 = &this->m_pBuf[4 * v29 + 4 * v30 * this->m_rgiBitmapSize[0]];
            v32 = &rgba[4 * v29 + 4 * v50];
            if ( ch == 9 )
            {
              v33 = 0;
              v34 = 0;
              v35 = 0;
            }
            else
            {
              v35 = *v31;
              v34 = v31[1];
              v33 = v31[2];
            }
            *v32 = v35;
            v32[1] = v34;
            v32[2] = v33;
            v32[3] = (int)(float)((float)((float)((float)v34 * 0.55000001) + (float)((float)v35 * 0.34))
                                + (float)((float)v33 * 0.11));
            v30 = j;
          }
        }
        v36 = *((_DWORD *)this + 9);
        v27 = rgbaWide;
        v50 += rgbaWide;
        v29 = (v36 & 0x2000000) != 0;
        j = ++v30;
      }
      while ( v30 < xstart - v29 );
    }
    v26 = rgba;
    if ( (*((_DWORD *)this + 9) & 0x1000000) != 0 )
    {
      v37 = wide;
      v38 = &rgba[4 * v27 * ((unsigned __int8)*((_DWORD *)this + 9) - 1)];
      if ( wide > 0 )
      {
        do
        {
          *(_DWORD *)v38 = 0;
          v38 += 4;
          --v37;
        }
        while ( v37 != 0 );
      }
    }
  }
  ApplyDropShadowToTexture(rgbaWide: v27, rgbaTall, rgba: v26, iDropShadowOffset: *((_BYTE *)this + 39) & 1);
  ApplyOutlineToTexture(rgbaWide: v27, rgbaTall, rgba: v26, iOutlineSize: (*((_DWORD *)this + 9) & 0x2000000) != 0);
  ApplyGaussianBlurToTexture(rgbaWide: v27, rgbaTall, rgba: v26, iBlur: this->m_iBlur);
  ApplyScanlineEffectToTexture(rgbaWide: v27, rgbaTall, rgba: v26, iScanLines: this->m_iScanLines);
  ApplyRotaryEffectToTexture(rgbaWide: v27, rgbaTall, rgba: v26, bRotary: (*((_DWORD *)this + 9) & 0x8000000) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10021490
// Name: public: virtual bool CWin32Font::IsEqualTo(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Font::IsEqualTo(
        CWin32Font *this,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags)
{
  char *v8; // eax

  v8 = CUtlSymbol::String(this: &this->m_szName);
  return _V_stricmp(s1: windowsFontName, s2: v8) == 0
      && this->m_iTall == tall
      && this->m_iWeight == weight
      && this->m_iBlur == blur
      && this->m_iFlags == flags;
}

//------------------------------------------------------------------------------
// Address: 0x100214F0
// Name: public: virtual bool CWin32Font::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Font::IsValid(CWin32Font *this)
{
  CUtlSymbol *p_m_szName; // ecx

  p_m_szName = &this->m_szName;
  return p_m_szName->m_Id != 0xFFFF && *CUtlSymbol::String(this: p_m_szName) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10021510
// Name: public: virtual void CWin32Font::SetAsActiveFont(struct HDC__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::SetAsActiveFont(CWin32Font *this, HDC__ *hdc)
{
  SelectObject(hdc, h: this->m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x10021530
// Name: public: virtual int CWin32Font::GetHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetHeight(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 36);
}

//------------------------------------------------------------------------------
// Address: 0x10021540
// Name: public: virtual int CWin32Font::GetAscent(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetAscent(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 38);
}

//------------------------------------------------------------------------------
// Address: 0x10021550
// Name: public: virtual int CWin32Font::GetMaxCharWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetMaxCharWidth(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 37);
}

//------------------------------------------------------------------------------
// Address: 0x10021560
// Name: public: virtual int CWin32Font::GetFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetFlags(CWin32Font *this)
{
  return this->m_iFlags;
}

//------------------------------------------------------------------------------
// Address: 0x10021570
// Name: private: static bool CWin32Font::ExtendedABCWidthsCacheLessFunc(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CWin32Font::ExtendedABCWidthsCacheLessFunc(
        const CWin32Font::abc_cache_t *lhs,
        const CWin32Font::abc_cache_t *rhs)
{
  return lhs->wch < rhs->wch;
}

//------------------------------------------------------------------------------
// Address: 0x10021590
// Name: public: virtual void CWin32Font::GetKernedCharWidth(wchar_t,wchar_t,wchar_t,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::GetKernedCharWidth(
        CWin32Font *this,
        int ch,
        wchar_t chBefore,
        wchar_t chAfter,
        float *wide,
        float *abcA,
        float *abcC)
{
  int v7; // eax
  int v8; // ecx
  int c; // [esp+0h] [ebp-8h] BYREF
  int b; // [esp+4h] [ebp-4h] BYREF

  this->GetCharABCWidths(this, a2: (unsigned __int16)ch, a3: &ch, a4: &b, a5: &c);
  v7 = ch;
  v8 = c;
  *wide = (float)(c + ch + b);
  *abcA = (float)v7;
  *abcC = (float)v8;
}

//------------------------------------------------------------------------------
// Address: 0x100215F0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx

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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: m_pMemory,
                                                                                     a3: 14 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: 14 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100216B0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(
        CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *this,
        int num)
{
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: m_pMemory,
                                                                                     a3: 14 * num);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: 14 * num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021830
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *__thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x100224D0
// Name: public: CWin32Font::CWin32Font(void)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CWin32Font::CWin32Font(CWin32Font *this)
{
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx

  this->__vftable = (CWin32Font_vtbl *)&CWin32Font::`vftable';
  this->m_szName.m_Id = -1;
  this->m_ExtendedABCWidthsCache.m_LessFunc = (bool (__cdecl *)(const CWin32Font::abc_cache_t *, const CWin32Font::abc_cache_t *))CWin32Font::ExtendedABCWidthsCacheLessFunc;
  this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory = nullptr;
  this->m_ExtendedABCWidthsCache.m_Elements.m_nAllocationCount = 0;
  this->m_ExtendedABCWidthsCache.m_Elements.m_nGrowSize = 256;
  m_pMemory = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_ExtendedABCWidthsCache.m_Root = 0xFFFF;
  this->m_ExtendedABCWidthsCache.m_pElements = m_pMemory;
  *(_DWORD *)&this->m_ExtendedABCWidthsCache.m_FirstFree = -1;
  *(_DWORD *)&this->m_szName.m_Id = 0xFFFF;
  *(_DWORD *)&this->m_iScanLines = 0;
  *((_BYTE *)this + 36) = 0;
  *(_WORD *)((char *)this + 37) = 0;
  *((_DWORD *)this + 9) &= 0xC3FFFFFF;
  *(_DWORD *)&this->m_iWeight = 0;
  this->m_hFont = nullptr;
  this->m_hDC = nullptr;
  this->m_hDIB = nullptr;
  *(_DWORD *)this->m_rgiBitmapSize = 0;
  CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(
    this: &this->m_ExtendedABCWidthsCache.m_Elements,
    num: 128);
  if ( !s_bOsVersionInitialized )
  {
    s_bOsVersionInitialized = true;
    memset(dst: (unsigned __int8 *)&s_OsVersionInfo, value: 0, count: sizeof(s_OsVersionInfo));
    s_OsVersionInfo.dwOSVersionInfoSize = 148;
    GetVersionExA(lpVersionInformation: &s_OsVersionInfo);
    s_bSupportsUnicode = s_OsVersionInfo.dwMajorVersion >= 5;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10022590
// Name: public: CWin32Font::~CWin32Font(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::~CWin32Font(CWin32Font *this)
{
  HFONT__ *m_hFont; // eax

  m_hFont = this->m_hFont;
  this->__vftable = (CWin32Font_vtbl *)&CWin32Font::`vftable';
  if ( m_hFont != nullptr )
    DeleteObject(ho: m_hFont);
  if ( this->m_hDC != nullptr )
    DeleteDC(hdc: this->m_hDC);
  if ( this->m_hDIB != nullptr )
    DeleteObject(ho: this->m_hDIB);
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::~CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>(this: &this->m_ExtendedABCWidthsCache);
}

//------------------------------------------------------------------------------
// Address: 0x10022650
// Name: public: virtual void CWin32Font::GetCharABCWidths(int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::GetCharABCWidths(CWin32Font *this, UINT ch, int *a, int *b, int *c)
{
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *p_m_ExtendedABCWidthsCache; // ebx
  unsigned __int16 v7; // ax
  int v8; // edi
  UINT v9; // edi
  bool v10; // zf
  int *v11; // eax
  int abcC; // edx
  int *v13; // ecx
  int *v14; // edx
  unsigned int abcB; // edx
  int v16; // edi
  char m_iBlur; // bl
  __int16 v18; // cx
  bool v19; // dl
  _ABC abc; // [esp+Ch] [ebp-28h] BYREF
  tagSIZE size; // [esp+18h] [ebp-1Ch] BYREF
  CWin32Font::abc_cache_t finder; // [esp+20h] [ebp-14h] BYREF
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *v23; // [esp+28h] [ebp-Ch]
  char mbcs[8]; // [esp+2Ch] [ebp-8h] BYREF

  p_m_ExtendedABCWidthsCache = &this->m_ExtendedABCWidthsCache;
  finder.wch = ch;
  finder.abc = 0;
  v23 = &this->m_ExtendedABCWidthsCache;
  v7 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_ExtendedABCWidthsCache,
         search: &finder);
  v8 = v7;
  if ( v7 < p_m_ExtendedABCWidthsCache->m_Elements.m_nAllocationCount
    && v7 <= p_m_ExtendedABCWidthsCache->m_LastAlloc.index
    && CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
         this: p_m_ExtendedABCWidthsCache,
         i: v7)->m_Left != v7 )
  {
    *a = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[v8].m_Data.abc.a;
    *b = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[v8].m_Data.abc.b;
    *c = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[v8].m_Data.abc.c;
    return;
  }
  v9 = ch;
  if ( GetCharABCWidthsW(hdc: this->m_hDC, wFirst: ch, wLast: ch, lpABC: &abc)
    || GetCharABCWidthsA(hdc: this->m_hDC, wFirst: v9, wLast: v9, lpABC: &abc) )
  {
    v11 = a;
    abcB = abc.abcB;
    *a = abc.abcA;
    *b = abcB;
    abcC = abc.abcC;
    v13 = c;
    goto LABEL_11;
  }
  memset(mbcs, 0, 6);
  ch = (unsigned __int16)v9;
  WideCharToMultiByte(
    CodePage: 0,
    dwFlags: 0,
    lpWideCharStr: (LPCWCH)&ch,
    cchWideChar: 1,
    lpMultiByteStr: mbcs,
    cbMultiByte: 6,
    lpDefaultChar: nullptr,
    lpUsedDefaultChar: nullptr);
  v10 = !GetTextExtentPoint32A(hdc: this->m_hDC, lpString: mbcs, c: strlen(mbcs), psizl: &size);
  v11 = a;
  if ( !v10 )
  {
    abcC = size.cx;
    *c = 0;
    v13 = b;
    *v11 = 0;
LABEL_11:
    *v13 = abcC;
    goto LABEL_12;
  }
  *c = 0;
  v14 = b;
  *v11 = 0;
  *v14 = *((unsigned __int8 *)this + 37);
LABEL_12:
  v16 = *((_DWORD *)this + 9);
  m_iBlur = this->m_iBlur;
  v18 = this->m_iBlur + ((v16 & 0x2000000) != 0);
  v19 = (v16 & 0x2000000) != 0;
  finder.abc.a = *(_BYTE *)v11 - m_iBlur - v19;
  finder.abc.b = *(_WORD *)b + (HIBYTE(v16) & 1) + 2 * v18;
  finder.abc.c = *(_BYTE *)c - (HIBYTE(v16) & 1) - m_iBlur - v19;
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Insert(
    this: v23,
    insert: &finder);
}

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100167A0
// Name: public: virtual bool CWin32Font::Create(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Font::Create(
        CWin32Font *this,
        const char *windowsFontName,
        int tall,
        int weight,
        unsigned __int16 blur,
        unsigned __int16 scanlines,
        unsigned int flags)
{
  unsigned int v8; // edi
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // dx
  DWORD v11; // ebx
  HFONT__ *FontA; // eax
  __int16 tmHeight; // bx
  __int16 tmMaxCharWidth; // dx
  char tmAscent; // al
  __int16 v17; // cx
  unsigned __int16 v18; // dx
  unsigned __int16 v19; // ax
  HDC__ *m_hDC; // ecx
  HBITMAP__ *DIBSection; // eax
  HDC__ *v22; // [esp-8h] [ebp-78h]
  tagTEXTMETRICA tm; // [esp+Ch] [ebp-64h] BYREF
  tagBITMAPINFOHEADER header; // [esp+44h] [ebp-2Ch] BYREF
  CUtlSymbol v25; // [esp+6Eh] [ebp-2h] BYREF

  CUtlSymbol::CUtlSymbol(this: &v25, pStr: windowsFontName);
  v8 = flags;
  this->m_szName = v25;
  v9 = blur;
  this->m_iWeight = weight;
  this->m_iTall = tall;
  v10 = scanlines;
  this->m_iBlur = v9;
  this->m_iScanLines = v10;
  *((_DWORD *)this + 9) = *((_DWORD *)this + 9) & 0xC0FFFFFF
                        | ((v8 & 0x200
                          | (2
                           * (v8 & 0x80 | (8 * (v8 & 0x100 | (2 * (v8 & 0x40 | (2 * (v8 & 0x10 | ((v8 & 2) << 6)))))))))) << 16);
  this->m_iFlags = v8;
  v11 = (v8 >> 2) & 2;
  if ( _V_stricmp(s1: windowsFontName, s2: "win98japanese") == 0 )
  {
    v11 = 128;
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&weight + 1, pStr: "Tahoma");
    this->m_szName.m_Id = HIWORD(weight);
  }
  this->m_hDC = CreateCompatibleDC(hdc: nullptr);
  FontA = CreateFontA(
            cHeight: tall,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: this->m_iWeight,
            bItalic: v8 & 1,
            bUnderline: v8 & 2,
            bStrikeOut: v8 & 4,
            iCharSet: v11,
            iOutPrecision: 0,
            iClipPrecision: 0,
            iQuality: ((*((_DWORD *)this + 9) & 0x4000000) != 0) + 3,
            iPitchAndFamily: 0,
            pszFaceName: windowsFontName);
  this->m_hFont = FontA;
  if ( FontA != nullptr )
  {
    SetMapMode(hdc: this->m_hDC, iMode: 1);
    SelectObject(hdc: this->m_hDC, h: this->m_hFont);
    SetTextAlign(hdc: this->m_hDC, align: 1u);
    memset(dst: (int)&tm, value: nullptr, count: sizeof(tm));
    if ( GetTextMetricsA(hdc: this->m_hDC, lptm: &tm) )
    {
      tmHeight = tm.tmHeight;
      tmMaxCharWidth = tm.tmMaxCharWidth;
      tmAscent = tm.tmAscent;
      *((_BYTE *)this + 36) = LOBYTE(tm.tmHeight)
                            + (HIBYTE(*((_DWORD *)this + 9)) & 1)
                            + 2 * ((*((_DWORD *)this + 9) & 0x2000000) != 0);
      *((_BYTE *)this + 38) = tmAscent;
      *((_BYTE *)this + 37) = tmMaxCharWidth;
      v17 = 2 * ((*((_DWORD *)this + 9) & 0x2000000) != 0);
      v18 = v17 + tmMaxCharWidth;
      v19 = tmHeight + v17 + ((*((_DWORD *)this + 9) & 0x1000000) != 0);
      this->m_rgiBitmapSize[0] = v18;
      *(_DWORD *)&header.biPlanes = 0;
      header.biHeight = -v19;
      this->m_rgiBitmapSize[1] = v19;
      header.biSize = 0;
      header.biWidth = v18;
      m_hDC = this->m_hDC;
      header.biSize = 40;
      *(_DWORD *)&header.biPlanes = 2097153;
      memset(&header.biCompression, 0, 24);
      DIBSection = CreateDIBSection(
                     hdc: m_hDC,
                     pbmi: (const BITMAPINFO *)&header,
                     usage: 0,
                     ppvBits: (void **)&this->m_pBuf,
                     hSection: nullptr,
                     offset: 0);
      v22 = this->m_hDC;
      this->m_hDIB = DIBSection;
      SelectObject(hdc: v22, h: DIBSection);
      return 1;
    }
    else
    {
      this->m_szName.m_Id = -1;
      return 0;
    }
  }
  else
  {
    _Error(a1: "Couldn't create windows font '%s'\n", windowsFontName);
    this->m_szName.m_Id = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016A00
// Name: public: virtual void CWin32Font::GetCharRGBA(wchar_t,int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::GetCharRGBA(
        CWin32Font *this,
        wchar_t ch,
        int rgbaWide,
        int rgbaTall,
        unsigned __int8 *rgba)
{
  void (__thiscall *GetCharABCWidths)(CWin32Font *, int, int *, int *, int *); // edx
  int v7; // ecx
  bool v8; // al
  int v9; // ebx
  DWORD GlyphOutlineA; // eax
  void *v11; // esp
  HDC__ *m_hDC; // ecx
  unsigned int gmBlackBoxX; // edx
  signed int v14; // eax
  int v15; // edi
  unsigned int v16; // ebx
  unsigned int v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  unsigned __int8 v20; // dl
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // ebx
  int v27; // edi
  int v28; // eax
  int v29; // ecx
  int v30; // edx
  unsigned __int8 *v31; // eax
  unsigned __int8 *v32; // edi
  unsigned __int8 v33; // al
  unsigned __int8 v34; // bl
  unsigned __int8 v35; // dl
  int v36; // ecx
  int v37; // ecx
  unsigned __int8 *v38; // eax
  HDC__ *v39; // [esp-20h] [ebp-88h]
  _BYTE v40[12]; // [esp+0h] [ebp-68h] BYREF
  _GLYPHMETRICS glyphMetrics; // [esp+Ch] [ebp-5Ch] BYREF
  tagRECT rect; // [esp+20h] [ebp-48h] BYREF
  _MAT2 mat2; // [esp+30h] [ebp-38h] BYREF
  char mbcs[8]; // [esp+40h] [ebp-28h] BYREF
  int c; // [esp+48h] [ebp-20h] BYREF
  int j; // [esp+4Ch] [ebp-1Ch]
  int a; // [esp+50h] [ebp-18h] BYREF
  unsigned int wch; // [esp+54h] [ebp-14h] BYREF
  int b; // [esp+58h] [ebp-10h] BYREF
  int v50; // [esp+5Ch] [ebp-Ch]
  int xstart; // [esp+60h] [ebp-8h]
  int wide; // [esp+64h] [ebp-4h]

  GetCharABCWidths = this->GetCharABCWidths;
  j = ch;
  GetCharABCWidths(this, a2: ch, a3: &a, a4: &b, a5: &c);
  SelectObject(hdc: this->m_hDC, h: this->m_hFont);
  v7 = *((_DWORD *)this + 9);
  wide = b;
  if ( (v7 & 0x20000000) != 0 )
    wide = c + a + b;
  mat2.eM11.fract = 0;
  mat2.eM11.value = 1;
  memset(&mat2.eM12, 0, 10);
  v8 = (v7 & 0x4000000) != 0;
  mat2.eM22.value = 1;
  v9 = (unsigned __int8)v7;
  xstart = (unsigned __int8)v7;
  if ( ch > 0xFFu && (this->m_iFlags & 0x400) == 0 )
    v8 = false;
  if ( !s_bSupportsUnicode )
  {
    if ( ch == 73 || ch == 49 )
      v8 = false;
    if ( (unsigned __int8)v7 >= 0xDu )
      goto LABEL_37;
  }
  if ( v8
    && (SelectObject(hdc: this->m_hDC, h: this->m_hFont),
        (int)(GlyphOutlineA = GetGlyphOutlineA(
                                hdc: this->m_hDC,
                                uChar: j,
                                fuFormat: 6u,
                                lpgm: &glyphMetrics,
                                cjBuffer: 0,
                                pvBuffer: nullptr,
                                lpmat2: &mat2)) > 0) )
  {
    v11 = alloca(GlyphOutlineA);
    m_hDC = this->m_hDC;
    j = (int)v40;
    GetGlyphOutlineA(
      hdc: m_hDC,
      uChar: ch,
      fuFormat: 6u,
      lpgm: &glyphMetrics,
      cjBuffer: GlyphOutlineA,
      pvBuffer: v40,
      lpmat2: &mat2);
    gmBlackBoxX = glyphMetrics.gmBlackBoxX;
    v14 = glyphMetrics.gmBlackBoxX;
    wide = glyphMetrics.gmBlackBoxX;
    if ( (signed int)glyphMetrics.gmBlackBoxX % 4 != 0 )
    {
      do
        ++v14;
      while ( v14 % 4 != 0 );
      wide = v14;
    }
    v15 = *((unsigned __int8 *)this + 38) - glyphMetrics.gmptGlyphOrigin.y;
    v16 = 0;
    *(_DWORD *)mbcs = v15;
    xstart = 0;
    if ( (int)glyphMetrics.gmBlackBoxX >= b + 2 )
    {
      v16 = (glyphMetrics.gmBlackBoxX - b) >> 1;
      xstart = v16;
    }
    v17 = 0;
    wch = 0;
    if ( glyphMetrics.gmBlackBoxY != 0 )
    {
      v50 = j;
      do
      {
        v18 = v16;
        if ( v16 < gmBlackBoxX )
        {
          j = v15 + v17;
          do
          {
            v19 = v18 + this->m_iBlur + ((*((_DWORD *)this + 9) & 0x2000000) != 0) - v16;
            if ( v19 < rgbaWide )
            {
              if ( j < rgbaTall )
              {
                v20 = *(_BYTE *)(v50 + v18);
                if ( v20 != 0 )
                {
                  v21 = (float)v20 * 0.015625;
                  v22 = 1.0;
                  v23 = 1.0;
                  v24 = 1.0;
                  if ( v21 > 1.0 )
                    v21 = 1.0;
                }
                else
                {
                  v21 = 0.0;
                  v22 = 0.0;
                  v23 = 0.0;
                  v24 = 0.0;
                }
                if ( ch == 9 )
                {
                  v22 = 0.0;
                  v23 = 0.0;
                  v24 = 0.0;
                }
                v25 = &rgba[4 * v19 + 4 * rgbaWide * j];
                *v25 = (int)(float)(v24 * 255.0);
                v25[1] = (int)(float)(v23 * 255.0);
                v25[2] = (int)(float)(v22 * 255.0);
                v25[3] = (int)(float)(v21 * 255.0);
                gmBlackBoxX = glyphMetrics.gmBlackBoxX;
              }
              v16 = xstart;
            }
            ++v18;
          }
          while ( v18 < gmBlackBoxX );
          v17 = wch;
          v15 = *(_DWORD *)mbcs;
        }
        v50 += wide;
        wch = ++v17;
      }
      while ( v17 < glyphMetrics.gmBlackBoxY );
    }
    v26 = rgba;
    v27 = rgbaWide;
  }
  else
  {
LABEL_37:
    SetBkColor(hdc: this->m_hDC, color: 0);
    SetTextColor(hdc: this->m_hDC, color: 0xFFFFFFu);
    SetBkMode(hdc: this->m_hDC, mode: 2);
    if ( (*((_DWORD *)this + 9) & 0x20000000) != 0 )
      MoveToEx(hdc: this->m_hDC, x: 0, y: 0, lppt: nullptr);
    else
      MoveToEx(hdc: this->m_hDC, x: -a, y: 0, lppt: nullptr);
    wch = ch;
    rect.left = 0;
    rect.top = 0;
    rect.bottom = v9;
    v39 = this->m_hDC;
    rect.right = wide;
    if ( s_bSupportsUnicode )
    {
      ExtTextOutW(hdc: v39, x: 0, y: 0, options: 2u, lprect: &rect, lpString: nullptr, c: 0, lpDx: nullptr);
      ExtTextOutW(
        hdc: this->m_hDC,
        x: 0,
        y: 0,
        options: 0,
        lprect: nullptr,
        lpString: (LPCWSTR)&wch,
        c: 1u,
        lpDx: nullptr);
    }
    else
    {
      ExtTextOutA(hdc: v39, x: 0, y: 0, options: 2u, lprect: &rect, lpString: nullptr, c: 0, lpDx: nullptr);
      memset(mbcs, 0, 6);
      WideCharToMultiByte(
        CodePage: 0,
        dwFlags: 0,
        lpWideCharStr: (LPCWCH)&wch,
        cchWideChar: 1,
        lpMultiByteStr: mbcs,
        cbMultiByte: 6,
        lpDefaultChar: nullptr,
        lpUsedDefaultChar: nullptr);
      ExtTextOutA(
        hdc: this->m_hDC,
        x: 0,
        y: 0,
        options: 0,
        lprect: nullptr,
        lpString: mbcs,
        c: strlen(mbcs),
        lpDx: nullptr);
    }
    SetBkMode(hdc: this->m_hDC, mode: 1);
    if ( wide > this->m_rgiBitmapSize[0] )
      wide = this->m_rgiBitmapSize[0];
    v28 = this->m_rgiBitmapSize[1];
    if ( v9 > v28 )
    {
      xstart = this->m_rgiBitmapSize[1];
      v9 = v28;
    }
    v29 = (*((_DWORD *)this + 9) & 0x2000000) != 0;
    v30 = v29;
    j = v29;
    if ( v29 >= v9 - v29 )
    {
      v27 = rgbaWide;
    }
    else
    {
      v50 = rgbaWide * v29;
      do
      {
        for ( ; v29 < wide - ((*((_DWORD *)this + 9) & 0x2000000) != 0) - ((*((_DWORD *)this + 9) & 0x1000000) != 0); ++v29 )
        {
          if ( v29 < rgbaWide && v30 < rgbaTall )
          {
            v31 = &this->m_pBuf[4 * v29 + 4 * v30 * this->m_rgiBitmapSize[0]];
            v32 = &rgba[4 * v29 + 4 * v50];
            if ( ch == 9 )
            {
              v33 = 0;
              v34 = 0;
              v35 = 0;
            }
            else
            {
              v35 = *v31;
              v34 = v31[1];
              v33 = v31[2];
            }
            *v32 = v35;
            v32[1] = v34;
            v32[2] = v33;
            v32[3] = (int)(float)((float)((float)((float)v34 * 0.55000001) + (float)((float)v35 * 0.34))
                                + (float)((float)v33 * 0.11));
            v30 = j;
          }
        }
        v36 = *((_DWORD *)this + 9);
        v27 = rgbaWide;
        v50 += rgbaWide;
        v29 = (v36 & 0x2000000) != 0;
        j = ++v30;
      }
      while ( v30 < xstart - v29 );
    }
    v26 = rgba;
    if ( (*((_DWORD *)this + 9) & 0x1000000) != 0 )
    {
      v37 = wide;
      v38 = &rgba[4 * v27 * ((unsigned __int8)*((_DWORD *)this + 9) - 1)];
      if ( wide > 0 )
      {
        do
        {
          *(_DWORD *)v38 = 0;
          v38 += 4;
          --v37;
        }
        while ( v37 != 0 );
      }
    }
  }
  ApplyDropShadowToTexture(rgbaWide: v27, rgbaTall, rgba: v26, iDropShadowOffset: *((_BYTE *)this + 39) & 1);
  ApplyOutlineToTexture(rgbaWide: v27, rgbaTall, rgba: v26, iOutlineSize: (*((_DWORD *)this + 9) & 0x2000000) != 0);
  ApplyGaussianBlurToTexture(rgbaWide: v27, rgbaTall, rgba: v26, iBlur: this->m_iBlur);
  ApplyScanlineEffectToTexture(rgbaWide: v27, rgbaTall, rgba: v26, iScanLines: this->m_iScanLines);
  ApplyRotaryEffectToTexture(rgbaWide: v27, rgbaTall, rgba: v26, bRotary: (*((_DWORD *)this + 9) & 0x8000000) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016F90
// Name: public: virtual bool CWin32Font::IsEqualTo(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Font::IsEqualTo(
        CWin32Font *this,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags)
{
  const char *v8; // eax

  v8 = CUtlSymbol::String(this: &this->m_szName);
  return _V_stricmp(s1: windowsFontName, s2: v8) == 0
      && this->m_iTall == tall
      && this->m_iWeight == weight
      && this->m_iBlur == blur
      && this->m_iFlags == flags;
}

//------------------------------------------------------------------------------
// Address: 0x10016FF0
// Name: public: virtual bool CWin32Font::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Font::IsValid(CWin32Font *this)
{
  CUtlSymbol *p_m_szName; // ecx

  p_m_szName = &this->m_szName;
  return p_m_szName->m_Id != 0xFFFF && *CUtlSymbol::String(this: p_m_szName) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10017010
// Name: public: virtual void CWin32Font::SetAsActiveFont(struct HDC__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::SetAsActiveFont(CWin32Font *this, HDC__ *hdc)
{
  SelectObject(hdc, h: this->m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x10017030
// Name: public: virtual int CWin32Font::GetHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetHeight(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 36);
}

//------------------------------------------------------------------------------
// Address: 0x10017040
// Name: public: virtual int CWin32Font::GetAscent(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetAscent(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 38);
}

//------------------------------------------------------------------------------
// Address: 0x10017050
// Name: public: virtual int CWin32Font::GetMaxCharWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetMaxCharWidth(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 37);
}

//------------------------------------------------------------------------------
// Address: 0x10017060
// Name: public: virtual int CWin32Font::GetFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetFlags(CWin32Font *this)
{
  return this->m_iFlags;
}

//------------------------------------------------------------------------------
// Address: 0x10017070
// Name: private: static bool CWin32Font::ExtendedABCWidthsCacheLessFunc(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CWin32Font::ExtendedABCWidthsCacheLessFunc(
        const CWin32Font::abc_cache_t *lhs,
        const CWin32Font::abc_cache_t *rhs)
{
  return lhs->wch < rhs->wch;
}

//------------------------------------------------------------------------------
// Address: 0x10017090
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx

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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: m_pMemory,
                                                                                     a3: 14 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: 14 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017150
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(
        CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *this,
        int num)
{
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: m_pMemory,
                                                                                     a3: 14 * num);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: 14 * num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100172D0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *__thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10017F70
// Name: public: CWin32Font::CWin32Font(void)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CWin32Font::CWin32Font(CWin32Font *this)
{
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx

  this->__vftable = (CWin32Font_vtbl *)&CWin32Font::`vftable';
  this->m_szName.m_Id = -1;
  this->m_ExtendedABCWidthsCache.m_LessFunc = (bool (__cdecl *)(const CWin32Font::abc_cache_t *, const CWin32Font::abc_cache_t *))CWin32Font::ExtendedABCWidthsCacheLessFunc;
  this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory = nullptr;
  this->m_ExtendedABCWidthsCache.m_Elements.m_nAllocationCount = 0;
  this->m_ExtendedABCWidthsCache.m_Elements.m_nGrowSize = 256;
  m_pMemory = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_ExtendedABCWidthsCache.m_Root = 0xFFFF;
  this->m_ExtendedABCWidthsCache.m_pElements = m_pMemory;
  *(_DWORD *)&this->m_ExtendedABCWidthsCache.m_FirstFree = -1;
  *(_DWORD *)&this->m_szName.m_Id = 0xFFFF;
  *(_DWORD *)&this->m_iScanLines = 0;
  *((_BYTE *)this + 36) = 0;
  *(_WORD *)((char *)this + 37) = 0;
  *((_DWORD *)this + 9) &= 0xC3FFFFFF;
  *(_DWORD *)&this->m_iWeight = 0;
  this->m_hFont = nullptr;
  this->m_hDC = nullptr;
  this->m_hDIB = nullptr;
  *(_DWORD *)this->m_rgiBitmapSize = 0;
  CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(
    this: &this->m_ExtendedABCWidthsCache.m_Elements,
    num: 128);
  if ( !s_bOsVersionInitialized )
  {
    s_bOsVersionInitialized = true;
    memset(dst: (int)&s_OsVersionInfo, value: nullptr, count: sizeof(s_OsVersionInfo));
    s_OsVersionInfo.dwOSVersionInfoSize = 148;
    GetVersionExA(lpVersionInformation: &s_OsVersionInfo);
    s_bSupportsUnicode = s_OsVersionInfo.dwMajorVersion >= 5;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018030
// Name: public: CWin32Font::~CWin32Font(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::~CWin32Font(CWin32Font *this)
{
  HFONT__ *m_hFont; // eax

  m_hFont = this->m_hFont;
  this->__vftable = (CWin32Font_vtbl *)&CWin32Font::`vftable';
  if ( m_hFont != nullptr )
    DeleteObject(ho: m_hFont);
  if ( this->m_hDC != nullptr )
    DeleteDC(hdc: this->m_hDC);
  if ( this->m_hDIB != nullptr )
    DeleteObject(ho: this->m_hDIB);
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::~CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>(this: &this->m_ExtendedABCWidthsCache);
}

//------------------------------------------------------------------------------
// Address: 0x100180F0
// Name: public: virtual void CWin32Font::GetCharABCWidths(int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::GetCharABCWidths(CWin32Font *this, UINT ch, int *a, int *b, int *c)
{
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *p_m_ExtendedABCWidthsCache; // ebx
  unsigned __int16 v7; // ax
  int v8; // edi
  UINT v9; // edi
  bool v10; // zf
  int *v11; // eax
  int abcC; // edx
  int *v13; // ecx
  int *v14; // edx
  unsigned int abcB; // edx
  int v16; // edi
  char m_iBlur; // bl
  __int16 v18; // cx
  bool v19; // dl
  _ABC abc; // [esp+Ch] [ebp-28h] BYREF
  tagSIZE size; // [esp+18h] [ebp-1Ch] BYREF
  CWin32Font::abc_cache_t finder; // [esp+20h] [ebp-14h] BYREF
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *v23; // [esp+28h] [ebp-Ch]
  char mbcs[8]; // [esp+2Ch] [ebp-8h] BYREF

  p_m_ExtendedABCWidthsCache = &this->m_ExtendedABCWidthsCache;
  finder.wch = ch;
  finder.abc = 0;
  v23 = &this->m_ExtendedABCWidthsCache;
  v7 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_ExtendedABCWidthsCache,
         search: &finder);
  v8 = v7;
  if ( v7 < p_m_ExtendedABCWidthsCache->m_Elements.m_nAllocationCount
    && v7 <= p_m_ExtendedABCWidthsCache->m_LastAlloc.index
    && CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
         this: p_m_ExtendedABCWidthsCache,
         i: v7)->m_Left != v7 )
  {
    *a = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[v8].m_Data.abc.a;
    *b = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[v8].m_Data.abc.b;
    *c = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[v8].m_Data.abc.c;
    return;
  }
  v9 = ch;
  if ( GetCharABCWidthsW(hdc: this->m_hDC, wFirst: ch, wLast: ch, lpABC: &abc)
    || GetCharABCWidthsA(hdc: this->m_hDC, wFirst: v9, wLast: v9, lpABC: &abc) )
  {
    v11 = a;
    abcB = abc.abcB;
    *a = abc.abcA;
    *b = abcB;
    abcC = abc.abcC;
    v13 = c;
    goto LABEL_11;
  }
  memset(mbcs, 0, 6);
  ch = (unsigned __int16)v9;
  WideCharToMultiByte(
    CodePage: 0,
    dwFlags: 0,
    lpWideCharStr: (LPCWCH)&ch,
    cchWideChar: 1,
    lpMultiByteStr: mbcs,
    cbMultiByte: 6,
    lpDefaultChar: nullptr,
    lpUsedDefaultChar: nullptr);
  v10 = !GetTextExtentPoint32A(hdc: this->m_hDC, lpString: mbcs, c: strlen(mbcs), psizl: &size);
  v11 = a;
  if ( !v10 )
  {
    abcC = size.cx;
    *c = 0;
    v13 = b;
    *v11 = 0;
LABEL_11:
    *v13 = abcC;
    goto LABEL_12;
  }
  *c = 0;
  v14 = b;
  *v11 = 0;
  *v14 = *((unsigned __int8 *)this + 37);
LABEL_12:
  v16 = *((_DWORD *)this + 9);
  m_iBlur = this->m_iBlur;
  v18 = this->m_iBlur + ((v16 & 0x2000000) != 0);
  v19 = (v16 & 0x2000000) != 0;
  finder.abc.a = *(_BYTE *)v11 - m_iBlur - v19;
  finder.abc.b = *(_WORD *)b + (HIBYTE(v16) & 1) + 2 * v18;
  finder.abc.c = *(_BYTE *)c - (HIBYTE(v16) & 1) - m_iBlur - v19;
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Insert(
    this: v23,
    insert: &finder);
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004BEB20
// Name: public: virtual bool CWin32Font::Create(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CWin32Font::Create(
        CWin32Font *this,
        char *windowsFontName,
        int tall,
        unsigned __int16 weight,
        unsigned __int16 blur,
        unsigned __int16 scanlines,
        unsigned int flags)
{
  const char *v7; // ebp
  unsigned int v9; // edi
  unsigned __int16 v10; // dx
  __int16 v11; // cx
  unsigned __int16 v12; // ax
  unsigned __int16 v13; // cx
  unsigned int v14; // edx
  DWORD v15; // ebx
  HFONT__ *FontA; // eax
  __int16 v18; // bx
  __int16 v19; // dx
  char v20; // al
  __int16 v21; // cx
  unsigned __int16 v22; // dx
  unsigned __int16 v23; // ax
  HDC__ *m_hDC; // edx
  HBITMAP__ *DIBSection; // eax
  _BYTE header_4[96]; // [esp+10h] [ebp-60h] OVERLAPPED BYREF

  v7 = windowsFontName;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&windowsFontName, pStr: windowsFontName);
  v9 = flags;
  v10 = weight;
  v11 = tall;
  this->m_szName.m_Id = (unsigned __int16)windowsFontName;
  v12 = blur;
  this->m_iWeight = v10;
  this->m_iTall = v11;
  v13 = scanlines;
  this->m_iBlur = v12;
  this->m_iScanLines = v13;
  v14 = *((_DWORD *)this + 9) & 0xC0FFFFFF
      | ((v9 & 0x200 | (2 * (v9 & 0x80 | (8 * (v9 & 0x100 | (2 * (v9 & 0x40 | (2 * (v9 & 0x10 | ((v9 & 2) << 6)))))))))) << 16);
  this->m_iFlags = v9;
  *((_DWORD *)this + 9) = v14;
  v15 = (v9 >> 2) & 2;
  if ( _V_stricmp(s1: v7, s2: "win98japanese") == 0 )
  {
    v15 = 128;
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&windowsFontName, pStr: "Tahoma");
    this->m_szName.m_Id = (unsigned __int16)windowsFontName;
  }
  this->m_hDC = CreateCompatibleDC(hdc: nullptr);
  FontA = CreateFontA(
            cHeight: tall,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: this->m_iWeight,
            bItalic: v9 & 1,
            bUnderline: v9 & 2,
            bStrikeOut: v9 & 4,
            iCharSet: v15,
            iOutPrecision: 0,
            iClipPrecision: 0,
            iQuality: ((*((_DWORD *)this + 9) & 0x4000000) != 0) + 3,
            iPitchAndFamily: 0,
            pszFaceName: v7);
  this->m_hFont = FontA;
  if ( FontA == nullptr )
  {
    _Error(a1: "Couldn't create windows font '%s'\n", v7);
LABEL_5:
    this->m_szName.m_Id = -1;
    return 0;
  }
  SetMapMode(hdc: this->m_hDC, iMode: 1);
  SelectObject(hdc: this->m_hDC, h: this->m_hFont);
  SetTextAlign(hdc: this->m_hDC, align: 1u);
  memset(dst: (int)&header_4[40], value: nullptr, count: 0x38u);
  if ( !GetTextMetricsA(hdc: this->m_hDC, lptm: (LPTEXTMETRICA)&header_4[40]) )
    goto LABEL_5;
  v18 = *(_WORD *)&header_4[40];
  v19 = *(_WORD *)&header_4[64];
  v20 = header_4[44];
  *((_BYTE *)this + 36) = header_4[40]
                        + (HIBYTE(*((_DWORD *)this + 9)) & 1)
                        + 2 * ((*((_DWORD *)this + 9) & 0x2000000) != 0);
  *((_BYTE *)this + 38) = v20;
  *((_BYTE *)this + 37) = v19;
  v21 = 2 * ((*((_DWORD *)this + 9) & 0x2000000) != 0);
  v22 = v21 + v19;
  v23 = v18 + v21 + ((*((_DWORD *)this + 9) & 0x1000000) != 0);
  this->m_rgiBitmapSize[0] = v22;
  this->m_rgiBitmapSize[1] = v23;
  *(_DWORD *)header_4 = 0;
  memset(&header_4[12], 0, 28);
  *(_DWORD *)&header_4[4] = v22;
  *(_DWORD *)&header_4[8] = -v23;
  m_hDC = this->m_hDC;
  *(_DWORD *)header_4 = 40;
  *(_DWORD *)&header_4[12] = 2097153;
  DIBSection = CreateDIBSection(
                 hdc: m_hDC,
                 pbmi: (const BITMAPINFO *)header_4,
                 usage: 0,
                 ppvBits: (void **)&this->m_pBuf,
                 hSection: nullptr,
                 offset: 0);
  this->m_hDIB = DIBSection;
  SelectObject(hdc: this->m_hDC, h: DIBSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004BED90
// Name: public: virtual void CWin32Font::GetCharRGBA(wchar_t,int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::GetCharRGBA(
        CWin32Font *this,
        wchar_t ch,
        int rgbaWide,
        int rgbaTall,
        unsigned __int8 *rgba)
{
  void (__thiscall *GetCharABCWidths)(CWin32Font *, int, int *, int *, int *); // edx
  bool v7; // zf
  int v8; // edi
  bool v9; // al
  int v10; // ebx
  int GlyphOutlineA; // eax
  void *v12; // esp
  signed int gmBlackBoxX; // ecx
  int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // eax
  int v17; // edi
  unsigned int v18; // ecx
  int v19; // eax
  unsigned __int8 v20; // dl
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  unsigned __int8 *v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  unsigned __int8 *v30; // eax
  unsigned __int8 *v31; // edi
  unsigned __int8 v32; // al
  unsigned __int8 v33; // bl
  unsigned __int8 v34; // dl
  float v35; // xmm4_4
  unsigned __int8 *v36; // ebx
  unsigned __int8 *v37; // eax
  _BYTE v38[12]; // [esp+0h] [ebp-68h] BYREF
  _GLYPHMETRICS glyphMetrics; // [esp+Ch] [ebp-5Ch] BYREF
  tagRECT rect; // [esp+20h] [ebp-48h] BYREF
  _MAT2 mat2; // [esp+30h] [ebp-38h] BYREF
  char mbcs[6]; // [esp+40h] [ebp-28h] BYREF
  int c; // [esp+48h] [ebp-20h] BYREF
  int j; // [esp+4Ch] [ebp-1Ch]
  int a; // [esp+50h] [ebp-18h] BYREF
  unsigned int wch; // [esp+54h] [ebp-14h] BYREF
  int v47; // [esp+58h] [ebp-10h]
  int xstart; // [esp+5Ch] [ebp-Ch]
  int b; // [esp+60h] [ebp-8h] BYREF
  int wide; // [esp+64h] [ebp-4h]
  int rgbaWidea; // [esp+74h] [ebp+Ch]

  GetCharABCWidths = this->GetCharABCWidths;
  j = ch;
  GetCharABCWidths(this, a2: ch, a3: &a, a4: &b, a5: &c);
  SelectObject(hdc: this->m_hDC, h: this->m_hFont);
  v7 = (*((_DWORD *)this + 9) & 0x20000000) == 0;
  v8 = b;
  wide = b;
  if ( !v7 )
  {
    wide = c + a + b;
    v8 = wide;
  }
  LOBYTE(v10) = *((_DWORD *)this + 9);
  v9 = (*((_DWORD *)this + 9) & 0x4000000) != 0;
  mat2.eM11.value = 1;
  mat2.eM22.value = 1;
  v10 = (unsigned __int8)v10;
  xstart = (unsigned __int8)v10;
  mat2.eM11.fract = 0;
  memset(&mat2.eM12, 0, 10);
  if ( ch > 0xFFu && (this->m_iFlags & 0x400) == 0 )
    v9 = false;
  if ( s_bSupportsUnicode )
    goto LABEL_11;
  if ( ch == 73 || ch == 49 )
    v9 = false;
  if ( *((unsigned __int8 *)this + 36) < 0xDu )
  {
LABEL_11:
    if ( v9 )
    {
      SelectObject(hdc: this->m_hDC, h: this->m_hFont);
      GlyphOutlineA = GetGlyphOutlineA(
                        hdc: this->m_hDC,
                        uChar: j,
                        fuFormat: 6u,
                        lpgm: &glyphMetrics,
                        cjBuffer: 0,
                        pvBuffer: nullptr,
                        lpmat2: &mat2);
      if ( GlyphOutlineA > 0 )
      {
        v12 = alloca(GlyphOutlineA);
        GetGlyphOutlineA(
          hdc: this->m_hDC,
          uChar: ch,
          fuFormat: 6u,
          lpgm: &glyphMetrics,
          cjBuffer: GlyphOutlineA,
          pvBuffer: v38,
          lpmat2: &mat2);
        gmBlackBoxX = glyphMetrics.gmBlackBoxX;
        wide = glyphMetrics.gmBlackBoxX;
        if ( (signed int)glyphMetrics.gmBlackBoxX % 4 != 0 )
        {
          do
            ++gmBlackBoxX;
          while ( gmBlackBoxX % 4 != 0 );
          wide = gmBlackBoxX;
        }
        v14 = *((unsigned __int8 *)this + 38) - glyphMetrics.gmptGlyphOrigin.y;
        v15 = 0;
        j = v14;
        xstart = 0;
        if ( (int)glyphMetrics.gmBlackBoxX >= b + 2 )
        {
          xstart = (glyphMetrics.gmBlackBoxX - b) >> 1;
          v15 = xstart;
        }
        v16 = 0;
        wch = 0;
        if ( glyphMetrics.gmBlackBoxY != 0 )
        {
          v17 = rgbaWide;
          v47 = (int)v38;
          rgbaWidea = rgbaWide * v14;
          do
          {
            v18 = v15;
            if ( v15 < glyphMetrics.gmBlackBoxX )
            {
              *(_DWORD *)mbcs = j + v16;
              do
              {
                v19 = v18 + this->m_iBlur + ((*((_DWORD *)this + 9) & 0x2000000) != 0) - v15;
                if ( v19 < v17 && *(int *)mbcs < rgbaTall )
                {
                  v20 = *(_BYTE *)(v18 + v47);
                  if ( v20 != 0 )
                  {
                    v21 = (float)v20 * 0.015625;
                    v22 = 1.0;
                    v23 = 1.0;
                    v24 = 1.0;
                    if ( v21 > 1.0 )
                      v21 = 1.0;
                  }
                  else
                  {
                    v21 = 0.0;
                    v22 = 0.0;
                    v23 = 0.0;
                    v24 = 0.0;
                  }
                  if ( ch == 9 )
                  {
                    v22 = 0.0;
                    v23 = 0.0;
                    v24 = 0.0;
                  }
                  v25 = &rgba[4 * rgbaWidea + 4 * v19];
                  *v25 = (int)(float)(v24 * 255.0);
                  v25[1] = (int)(float)(v23 * 255.0);
                  v25[2] = (int)(float)(v22 * 255.0);
                  v25[3] = (int)(float)(v21 * 255.0);
                  v15 = xstart;
                }
                ++v18;
              }
              while ( v18 < glyphMetrics.gmBlackBoxX );
              v16 = wch;
            }
            rgbaWidea += v17;
            v47 += wide;
            wch = ++v16;
          }
          while ( v16 < glyphMetrics.gmBlackBoxY );
          goto LABEL_62;
        }
LABEL_61:
        v17 = rgbaWide;
LABEL_62:
        v36 = rgba;
        goto LABEL_63;
      }
      v8 = wide;
    }
  }
  SetBkColor(hdc: this->m_hDC, color: 0);
  SetTextColor(hdc: this->m_hDC, color: 0xFFFFFFu);
  SetBkMode(hdc: this->m_hDC, mode: 2);
  if ( (*((_DWORD *)this + 9) & 0x20000000) != 0 )
    MoveToEx(hdc: this->m_hDC, x: 0, y: 0, lppt: nullptr);
  else
    MoveToEx(hdc: this->m_hDC, x: -a, y: 0, lppt: nullptr);
  wch = ch;
  rect.right = v8;
  rect.bottom = (unsigned __int8)v10;
  rect.left = 0;
  rect.top = 0;
  if ( s_bSupportsUnicode )
  {
    ExtTextOutW(hdc: this->m_hDC, x: 0, y: 0, options: 2u, lprect: &rect, lpString: nullptr, c: 0, lpDx: nullptr);
    ExtTextOutW(
      hdc: this->m_hDC,
      x: 0,
      y: 0,
      options: 0,
      lprect: nullptr,
      lpString: (LPCWSTR)&wch,
      c: 1u,
      lpDx: nullptr);
  }
  else
  {
    ExtTextOutA(hdc: this->m_hDC, x: 0, y: 0, options: 2u, lprect: &rect, lpString: nullptr, c: 0, lpDx: nullptr);
    memset(mbcs, 0, sizeof(mbcs));
    WideCharToMultiByte(
      CodePage: 0,
      dwFlags: 0,
      lpWideCharStr: (LPCWCH)&wch,
      cchWideChar: 1,
      lpMultiByteStr: mbcs,
      cbMultiByte: 6,
      lpDefaultChar: nullptr,
      lpUsedDefaultChar: nullptr);
    ExtTextOutA(
      hdc: this->m_hDC,
      x: 0,
      y: 0,
      options: 0,
      lprect: nullptr,
      lpString: mbcs,
      c: strlen(mbcs),
      lpDx: nullptr);
  }
  SetBkMode(hdc: this->m_hDC, mode: 1);
  v26 = this->m_rgiBitmapSize[0];
  if ( v8 > v26 )
  {
    wide = this->m_rgiBitmapSize[0];
    v8 = v26;
  }
  v27 = this->m_rgiBitmapSize[1];
  if ( (unsigned __int8)v10 > v27 )
  {
    xstart = this->m_rgiBitmapSize[1];
    v10 = v27;
  }
  v28 = (*((_DWORD *)this + 9) & 0x2000000) != 0;
  v29 = v28;
  j = v28;
  if ( v28 < v10 - v28 )
  {
    v47 = rgbaWide * v28;
    do
    {
      if ( v28 < v8 - ((*((_DWORD *)this + 9) & 0x2000000) != 0) - ((*((_DWORD *)this + 9) & 0x1000000) != 0) )
      {
        do
        {
          if ( v28 < rgbaWide && v29 < rgbaTall )
          {
            v30 = &this->m_pBuf[4 * v28 + 4 * v29 * this->m_rgiBitmapSize[0]];
            v31 = &rgba[4 * v28 + 4 * v47];
            if ( ch == 9 )
            {
              v32 = 0;
              v33 = 0;
              v34 = 0;
            }
            else
            {
              v34 = *v30;
              v33 = v30[1];
              v32 = v30[2];
            }
            v31[2] = v32;
            *v31 = v34;
            v35 = (float)v34;
            v29 = j;
            v31[1] = v33;
            v31[3] = (int)(float)((float)((float)((float)v32 * 0.11) + (float)((float)v33 * 0.55000001))
                                + (float)(v35 * 0.34));
          }
          ++v28;
        }
        while ( v28 < wide - ((*((_DWORD *)this + 9) & 0x2000000) != 0) - ((*((_DWORD *)this + 9) & 0x1000000) != 0) );
      }
      v47 += rgbaWide;
      v8 = wide;
      v28 = (*((_DWORD *)this + 9) & 0x2000000) != 0;
      j = ++v29;
    }
    while ( v29 < xstart - v28 );
  }
  if ( (*((_DWORD *)this + 9) & 0x1000000) == 0 )
    goto LABEL_61;
  v36 = rgba;
  v37 = &rgba[4 * rgbaWide * ((unsigned __int8)*((_DWORD *)this + 9) - 1)];
  if ( v8 > 0 )
  {
    do
    {
      *v37 = 0;
      v37[1] = 0;
      v37[2] = 0;
      v37[3] = 0;
      v37 += 4;
      --v8;
    }
    while ( v8 != 0 );
  }
  v17 = rgbaWide;
LABEL_63:
  ApplyDropShadowToTexture(rgbaWide: v17, rgbaTall, rgba: v36, iDropShadowOffset: *((_BYTE *)this + 39) & 1);
  ApplyOutlineToTexture(rgbaWide: v17, rgbaTall, rgba: v36, iOutlineSize: (*((_DWORD *)this + 9) & 0x2000000) != 0);
  ApplyGaussianBlurToTexture(rgbaWide: v17, rgbaTall, rgba: v36, iBlur: this->m_iBlur);
  ApplyScanlineEffectToTexture(rgbaWide: v17, rgbaTall, rgba: v36, iScanLines: this->m_iScanLines);
  ApplyRotaryEffectToTexture(rgbaWide: v17, rgbaTall, rgba: v36, bRotary: (*((_DWORD *)this + 9) & 0x8000000) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x004BF320
// Name: public: virtual bool CWin32Font::IsEqualTo(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Font::IsEqualTo(
        CWin32Font *this,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags)
{
  char *v8; // eax

  v8 = CUtlSymbol::String(this: &this->m_szName);
  return _V_stricmp(s1: windowsFontName, s2: v8) == 0
      && this->m_iTall == tall
      && this->m_iWeight == weight
      && this->m_iBlur == blur
      && this->m_iFlags == flags;
}

//------------------------------------------------------------------------------
// Address: 0x004BF380
// Name: public: virtual bool CWin32Font::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Font::IsValid(CWin32Font *this)
{
  CUtlSymbol *p_m_szName; // ecx

  p_m_szName = &this->m_szName;
  return p_m_szName->m_Id != 0xFFFF && *CUtlSymbol::String(this: p_m_szName) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BF3A0
// Name: public: virtual void CWin32Font::SetAsActiveFont(struct HDC__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::SetAsActiveFont(CWin32Font *this, HDC__ *hdc)
{
  SelectObject(hdc, h: this->m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x004BF3C0
// Name: public: virtual int CWin32Font::GetHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetHeight(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 36);
}

//------------------------------------------------------------------------------
// Address: 0x004BF3D0
// Name: public: virtual int CWin32Font::GetAscent(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetAscent(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 38);
}

//------------------------------------------------------------------------------
// Address: 0x004BF3E0
// Name: public: virtual int CWin32Font::GetMaxCharWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetMaxCharWidth(CWin32Font *this)
{
  return *((unsigned __int8 *)this + 37);
}

//------------------------------------------------------------------------------
// Address: 0x004BF3F0
// Name: public: virtual int CWin32Font::GetFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Font::GetFlags(CWin32Font *this)
{
  return this->m_iFlags;
}

//------------------------------------------------------------------------------
// Address: 0x004BF400
// Name: private: static bool CWin32Font::ExtendedABCWidthsCacheLessFunc(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CWin32Font::ExtendedABCWidthsCacheLessFunc(
        const CWin32Font::abc_cache_t *lhs,
        const CWin32Font::abc_cache_t *rhs)
{
  return lhs->wch < rhs->wch;
}

//------------------------------------------------------------------------------
// Address: 0x004BF420
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx
  bool v7; // zf

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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: 14 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: m_pMemory,
                                                                                     a3: 14 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BF4E0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(
        CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *this,
        int num)
{
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx
  bool v3; // zf

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    v3 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = num;
    if ( v3 )
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: 14 * num);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: m_pMemory,
                                                                                     a3: 14 * num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C02C0
// Name: public: CWin32Font::CWin32Font(void)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CWin32Font::CWin32Font(CWin32Font *this)
{
  this->__vftable = (CWin32Font_vtbl *)&CWin32Font::`vftable';
  this->m_szName.m_Id = -1;
  this->m_ExtendedABCWidthsCache.m_LessFunc = (bool (__cdecl *)(const CWin32Font::abc_cache_t *, const CWin32Font::abc_cache_t *))CWin32Font::ExtendedABCWidthsCacheLessFunc;
  this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory = nullptr;
  this->m_ExtendedABCWidthsCache.m_Elements.m_nAllocationCount = 0;
  this->m_ExtendedABCWidthsCache.m_Elements.m_nGrowSize = 256;
  this->m_ExtendedABCWidthsCache.m_Root = -1;
  this->m_ExtendedABCWidthsCache.m_NumElements = 0;
  this->m_ExtendedABCWidthsCache.m_FirstFree = -1;
  this->m_ExtendedABCWidthsCache.m_LastAlloc.index = -1;
  this->m_ExtendedABCWidthsCache.m_pElements = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory;
  this->m_szName.m_Id = -1;
  *((_BYTE *)this + 36) = 0;
  *((_BYTE *)this + 38) = 0;
  *((_BYTE *)this + 37) = 0;
  *((_DWORD *)this + 9) &= 0xC3FFFFFF;
  this->m_iTall = 0;
  this->m_iWeight = 0;
  this->m_iFlags = 0;
  this->m_hFont = nullptr;
  this->m_hDC = nullptr;
  this->m_hDIB = nullptr;
  this->m_iBlur = 0;
  this->m_iScanLines = 0;
  this->m_rgiBitmapSize[1] = 0;
  this->m_rgiBitmapSize[0] = 0;
  CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::EnsureCapacity(
    this: &this->m_ExtendedABCWidthsCache.m_Elements,
    num: 128);
  if ( !s_bOsVersionInitialized )
  {
    s_bOsVersionInitialized = true;
    memset(dst: (int)&s_OsVersionInfo, value: nullptr, count: sizeof(s_OsVersionInfo));
    s_OsVersionInfo.dwOSVersionInfoSize = 148;
    GetVersionExA(lpVersionInformation: &s_OsVersionInfo);
    s_bSupportsUnicode = s_OsVersionInfo.dwMajorVersion >= 5;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C03A0
// Name: public: CWin32Font::~CWin32Font(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Font::~CWin32Font(CWin32Font *this)
{
  HFONT__ *m_hFont; // eax

  m_hFont = this->m_hFont;
  this->__vftable = (CWin32Font_vtbl *)&CWin32Font::`vftable';
  if ( m_hFont != nullptr )
    DeleteObject(ho: m_hFont);
  if ( this->m_hDC != nullptr )
    DeleteDC(hdc: this->m_hDC);
  if ( this->m_hDIB != nullptr )
    DeleteObject(ho: this->m_hDIB);
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::~CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>(this: &this->m_ExtendedABCWidthsCache);
}

//------------------------------------------------------------------------------
// Address: 0x004C0460
// Name: public: virtual void CWin32Font::GetCharABCWidths(int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CWin32Font::GetCharABCWidths(CWin32Font *this, UINT ch, int *a, int *b, int *c)
{
  UINT v5; // ebx
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *p_m_ExtendedABCWidthsCache; // ebp
  unsigned __int16 v8; // ax
  int v9; // eax
  BOOL TextExtentPoint32A; // eax
  int *v11; // ebp
  int *v12; // ecx
  int abcC; // eax
  int *v14; // ecx
  int v15; // edx
  int v16; // edi
  char v17; // bl
  __int16 v18; // ax
  bool v19; // dl
  CWin32Font::abc_cache_t finder; // [esp+10h] [ebp-28h] BYREF
  _BYTE v21[18]; // [esp+16h] [ebp-22h] OVERLAPPED BYREF
  _ABC abc; // [esp+28h] [ebp-10h] BYREF
  int v23; // [esp+34h] [ebp-4h]

  v5 = ch;
  p_m_ExtendedABCWidthsCache = &this->m_ExtendedABCWidthsCache;
  *(_WORD *)&finder.abc.a = ch;
  *(_DWORD *)v21 = 0;
  *(_DWORD *)&finder.wch = &this->m_ExtendedABCWidthsCache;
  v8 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_ExtendedABCWidthsCache,
         search: (const CWin32Font::abc_cache_t *)&finder.abc.a);
  ch = v8;
  if ( v8 >= p_m_ExtendedABCWidthsCache->m_Elements.m_nAllocationCount
    || v8 > p_m_ExtendedABCWidthsCache->m_LastAlloc.index
    || CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
         this: p_m_ExtendedABCWidthsCache,
         i: v8)->m_Left == v8 )
  {
    if ( GetCharABCWidthsW(hdc: this->m_hDC, wFirst: v5, wLast: v5, lpABC: (LPABC)&abc.abcB)
      || GetCharABCWidthsA(hdc: this->m_hDC, wFirst: v5, wLast: v5, lpABC: (LPABC)&abc.abcB) )
    {
      v11 = a;
      abcC = abc.abcC;
      v14 = b;
      *a = abc.abcB;
      v15 = v23;
      *v14 = abcC;
      *c = v15;
    }
    else
    {
      v21[6] = 0;
      *(_DWORD *)&v21[7] = 0;
      v21[11] = 0;
      ch = (unsigned __int16)v5;
      WideCharToMultiByte(
        CodePage: 0,
        dwFlags: 0,
        lpWideCharStr: (LPCWCH)&ch,
        cchWideChar: 1,
        lpMultiByteStr: &v21[6],
        cbMultiByte: 6,
        lpDefaultChar: nullptr,
        lpUsedDefaultChar: nullptr);
      TextExtentPoint32A = GetTextExtentPoint32A(
                             hdc: this->m_hDC,
                             lpString: &v21[6],
                             c: strlen(&v21[6]),
                             psizl: (LPSIZE)&v21[14]);
      v11 = a;
      v12 = b;
      *c = 0;
      *v11 = 0;
      if ( TextExtentPoint32A )
        *v12 = *(_DWORD *)&v21[14];
      else
        *v12 = *((unsigned __int8 *)this + 37);
    }
    v16 = *((_DWORD *)this + 9);
    v17 = *(_BYTE *)v11 - LOBYTE(this->m_iBlur);
    LOBYTE(a) = this->m_iBlur;
    v18 = this->m_iBlur + ((v16 & 0x2000000) != 0);
    v19 = (v16 & 0x2000000) != 0;
    v21[2] = v17 - v19;
    *(_WORD *)v21 = *(_WORD *)b + (HIBYTE(v16) & 1) + 2 * v18;
    v21[3] = *(_BYTE *)c - (HIBYTE(v16) & 1) - (_BYTE)a - v19;
    CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Insert(
      this: *(CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > **)&finder.wch,
      insert: (const CWin32Font::abc_cache_t *)&finder.abc.a);
  }
  else
  {
    v9 = ch;
    *a = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[ch].m_Data.abc.a;
    *b = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[v9].m_Data.abc.b;
    *c = this->m_ExtendedABCWidthsCache.m_Elements.m_pMemory[v9].m_Data.abc.c;
  }
}

} // namespace vgui_perftest
