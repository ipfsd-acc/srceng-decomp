// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/textimage.cpp
// Functions: 25
// ============================================================

#include "vgui2\vgui_controls\textimage.h"

//------------------------------------------------------------------------------
// Address: 0x102D2D60
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D2E00
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x102D2E20
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2E70
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  int i; // esi
  unsigned __int16 v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2EC0
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  const char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2F10
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x102D2F30
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x102D2F40
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x102D2F70
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102D2F80
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102D2FB0
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D31A0
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3230
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D3250
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D3280
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x102D32A0
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x102D32C0
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x102D32E0
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &wszText;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v6 >> 31 != 0 ? -1 : 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x102D3380
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D3410
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ColorChangeStream);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_LineXIndent);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D3450
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<CEventInfo *,CUtlMemory<CEventInfo *,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<CEventInfo *,CUtlMemory<CEventInfo *,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: &v13[m_Size + 1], src: &v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3620
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D3700
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: &v15[m_Size + 1], src: &v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D3920
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::Paint(vgui::TextImage *this)
{
  char v2; // al
  vgui::TextImage_vtbl *v3; // edi
  Color *v4; // eax
  unsigned int v5; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v7; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v9; // ax
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  unsigned __int16 v13; // bx
  int v14; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v18; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v2 = *((_BYTE *)this + 52);
    if ( (v2 & 1) != 0 )
    {
      if ( (v2 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this);
    }
    v3 = this->__vftable;
    v4 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v3->DrawSetTextColor_2)(a1: this, a2: *v4);
    v5 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v5;
    DrawSetTextFont(this, a2: v5);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v5);
    y = 0;
    iIndent = 0;
    v7 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v7 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v9 = *utext;
    wsz = utext;
    if ( v9 != 0 )
    {
      while ( 1 )
      {
        v10 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v9;
        if ( !v10 )
        {
          v9 = towupper(c: v9);
          utext = wsz;
          v18 = v9;
        }
        if ( v9 == 13 )
          goto LABEL_32;
        if ( v9 == 10 )
        {
          v11 = iIndent + 1;
          iIndent = v11;
          if ( v11 >= this->m_LineXIndent.m_Size )
            v7 = 0;
          else
            v7 = this->m_LineXIndent.m_Memory.m_pMemory[v11];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v9 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v7 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v5 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v7 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v7 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v5, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v12 = iIndent + 1;
        iIndent = v12;
        if ( v12 >= this->m_LineXIndent.m_Size )
          v7 = 0;
        else
          v7 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v7 + px, a3: y + py);
      v13 = v18;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v18, a3: FONT_DRAW_DEFAULT);
      v14 = v13;
      v5 = font;
      v7 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v14);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3B90
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x100668C0
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068EF0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10068F90
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x10068FB0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069000
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069050
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100690A0
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x100690B0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x100690D0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x100690E0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x10069110
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10069120
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10069150
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 2) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 4) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 4) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069340
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x10069360
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  this->m_bWrapCenter = bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x10069370
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x10069390
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x100693B0
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_1009B474;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10069450
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100694E0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x10069520
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_18;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 )
          goto LABEL_13;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_13:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_17:
          iCurLineW = v6;
        }
LABEL_18:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_19;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_17;
    }
LABEL_19:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100696E0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100697C0
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edx
  unsigned __int16 i; // ax
  unsigned __int16 v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // eax
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+21h] [ebp-3h]
  bool justStartedNewLine; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  for ( i = *wsz; *wsz != 0; x = v8 )
  {
    v7 = i;
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
      v7 = towupper(c: i);
    if ( iswspace(c: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    i = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x100699B0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069C20
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v19; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v19 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v19, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v19 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          *wide += c + b + a;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = text + 1;
        v14 = v19 == (vgui::ISurface *)1;
        v19 = (vgui::ISurface *)((char *)v19 - 1);
        ++text;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0045A4E0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045A580
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x0045A5A0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A5F0
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  unsigned __int16 v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A640
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A690
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x0045A6A0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x0045A6C0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x0045A6D0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x0045A700
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0045A710
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0045A740
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 2) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 4) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 4) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A930
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x0045A950
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  this->m_bWrapCenter = bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x0045A960
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x0045A980
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x0045A9A0
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_484AE8;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x0045AA40
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045AAD0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045AB10
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_18;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 )
          goto LABEL_13;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_13:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_17:
          iCurLineW = v6;
        }
LABEL_18:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_19;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_17;
    }
LABEL_19:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045ACD0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045ADB0
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edx
  unsigned __int16 i; // ax
  unsigned __int16 v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // eax
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+21h] [ebp-3h]
  bool justStartedNewLine; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  for ( i = *wsz; *wsz != 0; x = v8 )
  {
    v7 = i;
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
      v7 = towupper(c: i);
    if ( iswspace(c: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    i = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045AFA0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B210
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v19; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v19 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v19, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v19 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          *wide += c + b + a;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = text + 1;
        v14 = v19 == (vgui::ISurface *)1;
        v19 = (vgui::ISurface *)((char *)v19 - 1);
        ++text;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10082AA0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10082B40
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x10082B60
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082BB0
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082C00
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082C50
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x10082C60
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x10082C80
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x10082C90
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x10082CC0
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10082CD0
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10082D00
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082EF0
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082F80
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x10082FA0
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x10082FD0
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x10082FF0
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10083010
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x10083030
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_100BA41C;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x100830D0
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10083160
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x100831A0
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPackedStore *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083370
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10083450
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<CPackedStore *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<CPackedStore *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x10083670
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100838E0
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x006356D0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00635770
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x00635790
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006357E0
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00635830
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00635880
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x00635890
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x006358B0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x006358C0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x006358F0
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00635900
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00635930
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 2) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 4) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 4) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00635B20
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00635B40
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  this->m_bWrapCenter = bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x00635B50
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00635B70
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00635B90
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_6FA60C;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v6 >> 31 != 0 ? -1 : 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x00635C30
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00635CC0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x00635D00
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_18;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 )
          goto LABEL_13;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_13:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_17:
          iCurLineW = v6;
        }
LABEL_18:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_19;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_17;
    }
LABEL_19:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00635EC0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00635FA0
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edx
  unsigned __int16 i; // ax
  unsigned __int16 v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // eax
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+21h] [ebp-3h]
  bool justStartedNewLine; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  for ( i = *wsz; *wsz != 0; x = v8 )
  {
    v7 = i;
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
      v7 = towupper(c: i);
    if ( iswspace(c: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    i = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x00636190
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00636400
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v19; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v19 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v19, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v19 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          *wide += c + b + a;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = text + 1;
        v14 = v19 == (vgui::ISurface *)1;
        v19 = (vgui::ISurface *)((char *)v19 - 1);
        ++text;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102D2DF0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D2E90
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x102D2EB0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2F00
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2F50
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  const char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2FA0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x102D2FC0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x102D2FD0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x102D3000
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102D3010
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102D3040
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3310
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x102D3330
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x102D3350
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x102D3370
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &wszText;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v6 >> 31 != 0 ? -1 : 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x102D34A0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ColorChangeStream);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_LineXIndent);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D34E0
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<CEventInfo *,CUtlMemory<CEventInfo *,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<CEventInfo *,CUtlMemory<CEventInfo *,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: &v13[m_Size + 1], src: &v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D36B0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D3790
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: &v15[m_Size + 1], src: &v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D39B0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3C20
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1032E7E0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = &var;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1032E880
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x1032E8A0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = std::char_traits<char>::length(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032E8F0
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032E940
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032E990
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x1032E9A0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x1032E9C0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x1032E9D0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x1032EA00
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1032EA10
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1032EA40
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032EC30
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032ECC0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x1032ECE0
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x1032ED10
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x1032ED30
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x1032ED50
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x1032ED70
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &byte_105EEA78;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    operator delete(p: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x1032EE10
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1032EEA0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  operator delete(p: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x1032EEE0
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032F0B0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1032F190
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x1032F3B0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032F620
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CFD83
// Name: protected: virtual class CSize CMFCCaptionBar::GetTextSize(class CDC __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CSize *__thiscall CMFCCaptionBar::GetTextSize(CMFCCaptionBar *this, CSize *result, CDC *pDC, CFont *strText)
{
  int m_nSize; // eax
  int v7; // ebx
  int v8; // edi
  int cy; // ecx
  CSize sizePart; // [esp+4h] [ebp-14h] BYREF
  CSize sizeText; // [esp+Ch] [ebp-Ch]
  int bIsBold; // [esp+14h] [ebp-4h]
  CFont *pOldFont; // [esp+28h] [ebp+10h]

  m_nSize = this->m_arTextParts.m_nSize;
  if ( m_nSize == 1 )
  {
    CDC::GetTextExtent(
      this: pDC,
      result,
      str: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)strText);
    return result;
  }
  else
  {
    v7 = 0;
    v8 = 0;
    sizeText.cy = 0;
    bIsBold = 0;
    if ( m_nSize > 0 )
    {
      while ( v8 >= 0 && v8 < this->m_arTextParts.m_nSize )
      {
        if ( *((_DWORD *)this->m_arTextParts.m_pData[v8].m_pszData - 3) != 0 )
        {
          pOldFont = nullptr;
          if ( bIsBold != 0 )
            pOldFont = pDC->SelectObject(this: pDC, a2: &afxGlobalData.fontBold);
          if ( v8 >= this->m_arTextParts.m_nSize )
            break;
          CDC::GetTextExtent(this: pDC, result: &sizePart, str: &this->m_arTextParts.m_pData[v8]);
          v7 += sizePart.cx;
          if ( sizeText.cy <= sizePart.cy )
            sizeText.cy = sizePart.cy;
          if ( pOldFont != nullptr )
            pDC->SelectObject(this: pDC, a2: pOldFont);
        }
        ++v8;
        bIsBold = bIsBold == 0;
        if ( v8 >= this->m_arTextParts.m_nSize )
          goto LABEL_15;
      }
      AfxThrowInvalidArgException();
    }
LABEL_15:
    cy = sizeText.cy;
    result->cx = v7;
    result->cy = cy;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DA2A7
// Name: public: virtual class CSize CMFCAutoHideButton::GetTextSize(void)const
// Source: json
//------------------------------------------------------------------------------
CSize *__thiscall CMFCAutoHideButton::GetTextSize(CMFCAutoHideButton *this, CSize *result)
{
  CSize *v3; // esi
  CAfxStringMgr *StringManager; // eax
  CDockablePane *m_pAutoHideWindow; // ecx
  bool v6; // zf
  CFont *p_fontRegular; // eax
  CFont *v8; // ebx
  CSize *TextExtent; // eax
  int cx; // ecx
  int v11; // eax
  int cy; // eax
  CWindowDC dc; // [esp+10h] [ebp-28h] BYREF
  CSize v15; // [esp+24h] [ebp-14h] BYREF
  int v16; // [esp+34h] [ebp-4h]

  v3 = result;
  result->cx = 0;
  v3->cy = 0;
  if ( this->m_pAutoHideWindow != nullptr && this->m_pParentBar != nullptr )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
      this: (ATL::CSimpleStringT<char,0> *)&result,
      pStringMgr: StringManager);
    m_pAutoHideWindow = this->m_pAutoHideWindow;
    v16 = 0;
    CWnd::GetWindowTextA(
      this: &m_pAutoHideWindow->CPane,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&result);
    if ( result[-2].cy != 0 )
    {
      CWindowDC::CWindowDC(this: &dc, pWnd: this->m_pParentBar);
      LOBYTE(v16) = 1;
      v6 = !CMFCAutoHideButton::IsHorizontal(this);
      p_fontRegular = &afxGlobalData.fontRegular;
      if ( v6 )
        p_fontRegular = &afxGlobalData.fontVert;
      v8 = CDC::SelectObject(this: &dc, pFont: p_fontRegular);
      if ( v8 == nullptr )
        AfxThrowInvalidArgException();
      TextExtent = CDC::GetTextExtent(
                     this: &dc,
                     result: &v15,
                     str: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&result);
      cx = TextExtent->cx;
      v3->cy = TextExtent->cy;
      v11 = CMFCAutoHideButton::m_nMarginSize;
      v3->cy += CMFCAutoHideButton::m_nMarginSize;
      v3->cx = cx;
      v3->cx += v11;
      CDC::SelectObject(this: &dc, pFont: v8);
      if ( !CMFCAutoHideButton::IsHorizontal(this) )
      {
        cy = v3->cy;
        v3->cy = v3->cx;
        v3->cx = cy;
      }
      LOBYTE(v16) = 0;
      CWindowDC::~CWindowDC(this: &dc);
    }
    if ( this->m_pParentBar->m_bActiveInGroup == 0 && CMFCAutoHideButton::m_bOverlappingTabs != 0 )
    {
      if ( CMFCAutoHideButton::IsHorizontal(this) )
        v3->cx = 0;
      else
        v3->cy = 0;
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)&result[-2]);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103CFE72
// Name: public: static class CObject __near * CMFCCaptionBar::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionBar *__stdcall CMFCCaptionBar::CreateObject()
{
  CMFCCaptionBar *v0; // ecx
  CMFCCaptionBar *result; // eax

  v0 = (CMFCCaptionBar *)operator new(nSize: 0x49Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCCaptionBar::CMFCCaptionBar(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CFEC3
// Name: protected: virtual void CMFCCaptionBar::RecalcLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::RecalcLayout(CMFCCaptionBar *this)
{
  HFONT__ *m_hFont; // eax
  CFont *p_fontRegular; // eax
  int cy; // esi
  int m_nDefaultHeight; // eax
  int m_nMargin; // edi
  int v7; // esi
  int bottom; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int m_nHorzElementOffset; // ecx
  int v14; // eax
  char *m_pszData; // ecx
  int v16; // esi
  int m_bIsMessageBarMode; // eax
  int v18; // eax
  int left; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // eax
  CSize *v26; // eax
  int cx; // esi
  int v28; // ecx
  int v29; // eax
  __int32 v30; // eax
  __int32 v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // esi
  int v39; // eax
  int v40; // ecx
  char *v41; // eax
  int v42; // esi
  BOOL v43; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-ECh]
  int v45; // [esp-8h] [ebp-ECh]
  int v46; // [esp-8h] [ebp-ECh]
  int v47; // [esp+14h] [ebp-D0h]
  int v48; // [esp+18h] [ebp-CCh] BYREF
  int v49; // [esp+1Ch] [ebp-C8h]
  CClientDC v50; // [esp+20h] [ebp-C4h] BYREF
  int v51; // [esp+34h] [ebp-B0h]
  CSize v52; // [esp+38h] [ebp-ACh] BYREF
  CFont *pFont; // [esp+40h] [ebp-A4h]
  int v54; // [esp+44h] [ebp-A0h]
  int v55; // [esp+48h] [ebp-9Ch]
  int bLeftOf; // [esp+4Ch] [ebp-98h]
  int v57; // [esp+50h] [ebp-94h]
  int v58; // [esp+54h] [ebp-90h]
  int v59; // [esp+58h] [ebp-8Ch]
  int v60; // [esp+5Ch] [ebp-88h]
  CSize v61; // [esp+60h] [ebp-84h] BYREF
  CSize result; // [esp+68h] [ebp-7Ch] BYREF
  int v63; // [esp+70h] [ebp-74h]
  int v64; // [esp+74h] [ebp-70h]
  int v65; // [esp+78h] [ebp-6Ch]
  tagRECT Rect; // [esp+7Ch] [ebp-68h] BYREF
  tagTEXTMETRICA tm; // [esp+8Ch] [ebp-58h] BYREF
  CRect rectSrc; // [esp+C4h] [ebp-20h] BYREF
  int v69; // [esp+E0h] [ebp-4h]

  CClientDC::CClientDC(this: &v50, pWnd: nullptr);
  m_hFont = this->m_hFont;
  v69 = 0;
  if ( m_hFont != nullptr )
    p_fontRegular = (CFont *)CGdiObject::FromHandle(h: m_hFont);
  else
    p_fontRegular = &afxGlobalData.fontRegular;
  pFont = CDC::SelectObject(this: &v50, pFont: p_fontRegular);
  GetTextMetricsA(hdc: v50.m_hAttribDC, lptm: &tm);
  cy = tm.tmHeight + 2;
  CMFCCaptionBar::GetImageSize(this, &result);
  m_nDefaultHeight = this->m_nDefaultHeight;
  if ( m_nDefaultHeight == -1 )
  {
    if ( *((_DWORD *)this->m_strBtnText.m_pszData - 3) != 0 && this->m_bIsMessageBarMode != 0 )
      cy += 10;
    if ( cy <= result.cy )
      cy = result.cy;
    m_nDefaultHeight = cy + this->m_nBorderSize + 2 * this->m_nMargin;
  }
  this->m_nCurrentHeight = m_nDefaultHeight;
  if ( this->m_bIsMessageBarMode != 0 )
    this->m_nCurrentHeight += 8;
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  if ( IsRectEmpty(lprc: &Rect) )
    goto LABEL_92;
  if ( this->m_bIsMessageBarMode != 0 )
  {
    CMenuImages::Size(result: &v61);
    v61.cx += 8;
    v61.cy += 8;
    v47 = Rect.top + 4;
    v48 = v61.cx + Rect.right - result.cx;
    v49 = v61.cy + Rect.top + 4;
    this->m_rectClose.left = Rect.right - result.cx;
    this->m_rectClose.top = v47;
    this->m_rectClose.right = v48;
    this->m_rectClose.bottom = v49;
    InflateRect(lprc: &Rect, dx: -4, dy: -4);
    Rect.right += this->m_rectClose.left - this->m_rectClose.right;
  }
  bLeftOf = 0;
  v59 = 0;
  v58 = 0;
  v55 = 0;
  v51 = 0;
  v57 = 0;
  v61.cy = 0;
  m_nMargin = this->m_nMargin;
  v54 = (Rect.bottom + Rect.top) / 2;
  v64 = m_nMargin + Rect.left;
  v7 = (Rect.left + Rect.right) / 2;
  v63 = Rect.right - m_nMargin;
  v65 = v7;
  if ( CMFCCaptionBar::IsImageSet(this) != 0 )
  {
    bottom = Rect.bottom;
    if ( result.cy >= Rect.bottom - Rect.top )
      this->m_rectImage.top = m_nMargin + Rect.top;
    else
      this->m_rectImage.top = v54 - result.cy / 2;
    if ( this->m_bStretchImage != 0 )
      this->m_rectImage.bottom = bottom - m_nMargin;
    else
      this->m_rectImage.bottom = result.cy + this->m_rectImage.top;
    switch ( this->m_iconAlignment )
    {
      case ALIGN_LEFT:
        v12 = v64;
        m_nHorzElementOffset = this->m_nHorzElementOffset;
        this->m_rectImage.left = v64;
        v14 = result.cx + v12;
        this->m_rectImage.right = v14;
        v64 = v14 + m_nHorzElementOffset;
        break;
      case ALIGN_RIGHT:
        v9 = v63 - result.cx;
        v10 = v63;
        this->m_rectImage.left = v63 - result.cx;
        v11 = v9 - this->m_nHorzElementOffset;
        this->m_rectImage.right = v10;
        v63 = v11;
        bLeftOf = 1;
        v58 = 1;
        break;
      case ALIGN_CENTER:
        v55 = 1;
        v65 = v7 - result.cx / 2;
        if ( this->m_btnAlignnment == ALIGN_LEFT )
          bLeftOf = 1;
        if ( this->m_textAlignment == ALIGN_LEFT )
          v58 = 1;
        break;
      default:
        break;
    }
  }
  m_pszData = this->m_strBtnText.m_pszData;
  v16 = 0;
  v60 = 0;
  if ( *((_DWORD *)m_pszData - 3) != 0 )
  {
    v16 = CDC::GetTextExtent(this: &v50, result: &v52, str: &this->m_strBtnText)->cx + 2 * this->m_nHorzElementOffset;
    m_bIsMessageBarMode = this->m_bIsMessageBarMode;
    v60 = v16;
    if ( m_bIsMessageBarMode != 0 )
    {
      v16 += 20;
      v60 = v16;
    }
    if ( this->m_uiBtnID != 0 && this->m_bBtnEnabled != 0 && this->m_bBtnHasDropDownArrow != 0 )
    {
      v16 += 10;
      v60 = v16;
    }
    this->m_rectButton.top = Rect.top;
    this->m_rectButton.bottom = Rect.bottom;
    if ( m_bIsMessageBarMode != 0 )
      InflateRect(lprc: &this->m_rectButton, dx: 0, dy: -5);
    if ( this->m_btnAlignnment == ALIGN_LEFT )
    {
      if ( this->m_bIsMessageBarMode != 0 && this->m_textAlignment == ALIGN_LEFT )
      {
        v57 = 1;
      }
      else
      {
        v22 = v64;
        v23 = Rect.left + this->m_nMargin;
        this->m_rectButton.left = v64;
        if ( v22 == v23 )
          this->m_rectButton.left = v23;
        v24 = this->m_nHorzElementOffset;
        v25 = v16 + this->m_rectButton.left;
        this->m_rectButton.right = v25;
        v64 = v25 + v24;
      }
    }
    else
    {
      if ( this->m_btnAlignnment == ALIGN_RIGHT )
      {
        this->m_rectButton.left = v63 - v16;
        v18 = Rect.right - this->m_nMargin;
        if ( v63 == v18 )
          this->m_rectButton.left = v18 - v16;
        left = this->m_rectButton.left;
        v20 = left + v16;
        v21 = left - this->m_nHorzElementOffset;
        this->m_rectButton.right = v20;
        v63 = v21;
      }
      else
      {
        if ( this->m_btnAlignnment != ALIGN_CENTER )
          goto LABEL_92;
        v65 += v16 / -2;
        v51 = 1;
        if ( this->m_textAlignment != ALIGN_LEFT )
          goto LABEL_56;
      }
      v59 = 1;
    }
  }
LABEL_56:
  v52.cx = 0;
  if ( *((_DWORD *)this->m_strText.m_pszData - 3) != 0 )
  {
    v26 = this->GetTextSize(this, result: &v48, a3: &v50, a4: &this->m_strText);
    cx = v26->cx;
    v28 = v26->cy;
    v29 = v54 - v28 / 2;
    this->m_rectText.top = v29;
    this->m_rectText.bottom = v28 + v29;
    v30 = this->m_textAlignment - 1;
    v52.cx = cx;
    if ( v30 != 0 )
    {
      v31 = v30 - 1;
      if ( v31 != 0 )
      {
        if ( v31 != 1 )
          goto LABEL_92;
        v65 += cx / -2;
        v61.cy = 1;
      }
      else
      {
        this->m_rectText.left = v63 - cx;
      }
    }
    else
    {
      this->m_rectText.left = v64;
      v64 += cx + 2 * this->m_nMargin;
    }
    v45 = this->m_nMargin;
    this->m_rectText.right = v52.cx + this->m_rectText.left;
    CMFCCaptionBar::AdjustRectToMargin(
      this,
      rectSrc: &this->m_rectText,
      rectClient: (const CRect *)&Rect,
      nMargin: v45,
      bRetainSize: 0);
    this->m_rectDrawText.left = this->m_rectText.left;
    this->m_rectDrawText.top = this->m_rectText.top;
    this->m_rectDrawText.right = this->m_rectText.right;
    this->m_rectDrawText.bottom = this->m_rectText.bottom;
    v16 = v60;
  }
  v32 = v65;
  if ( v55 != 0 )
  {
    this->m_rectImage.left = v65;
    v33 = result.cx + v32;
    this->m_rectImage.right = v33;
    v32 = this->m_nHorzElementOffset + v33;
    v65 = v32;
  }
  if ( v57 != 0 )
  {
    v34 = v64;
    v35 = this->m_nMargin;
    this->m_rectButton.left = v64;
    v36 = v16 + v34;
    this->m_rectButton.right = v36;
    if ( v36 + v35 > Rect.right )
    {
      v37 = Rect.right - v35;
      this->m_rectButton.right = Rect.right - v35;
      this->m_rectButton.left = v37 - v16;
    }
  }
  else if ( v51 != 0 )
  {
    v38 = v32 + v16;
    this->m_rectButton.left = v32;
    v39 = this->m_nHorzElementOffset;
    this->m_rectButton.right = v38;
    v65 = v38 + v39;
  }
  if ( v61.cy != 0 )
  {
    v46 = this->m_nMargin;
    v40 = v65 + v52.cx;
    this->m_rectText.left = v65;
    this->m_rectText.right = v40;
    CMFCCaptionBar::AdjustRectToMargin(
      this,
      rectSrc: &this->m_rectText,
      rectClient: (const CRect *)&Rect,
      nMargin: v46,
      bRetainSize: 0);
    this->m_rectDrawText.left = this->m_rectText.left;
    this->m_rectDrawText.top = this->m_rectText.top;
    this->m_rectDrawText.right = this->m_rectText.right;
    this->m_rectDrawText.bottom = this->m_rectText.bottom;
  }
  if ( CMFCCaptionBar::IsImageSet(this) != 0 )
  {
    CMFCCaptionBar::AdjustRectToMargin(
      this,
      rectSrc: &this->m_rectImage,
      rectClient: (const CRect *)&Rect,
      nMargin: this->m_nMargin,
      bRetainSize: this->m_bStretchImage == 0);
    if ( this->m_rectImage.left < Rect.left || this->m_rectImage.right > Rect.right )
      SetRectEmpty(lprc: &this->m_rectImage);
  }
  v41 = this->m_strBtnText.m_pszData;
  rectSrc = this->m_rectButton;
  if ( *((_DWORD *)v41 - 3) != 0 && CMFCCaptionBar::IsImageSet(this) != 0 )
    CMFCCaptionBar::CheckRectangle(this, &rectSrc, rectOther: &this->m_rectImage, bLeftOf);
  if ( *((_DWORD *)this->m_strBtnText.m_pszData - 3) != 0 )
  {
    v42 = this->m_nMargin;
    CMFCCaptionBar::AdjustRectToMargin(this, &rectSrc, rectClient: (const CRect *)&Rect, nMargin: v42, bRetainSize: 0);
    if ( this->m_rectImage.right + this->m_rectButton.right + 2 * v42 - this->m_rectButton.left - this->m_rectImage.left > Rect.right - Rect.left )
      SetRectEmpty(lprc: &this->m_rectButton);
  }
  if ( *((_DWORD *)this->m_strText.m_pszData - 3) != 0 )
  {
    CMFCCaptionBar::CheckRectangle(this, rectSrc: &this->m_rectDrawText, rectOther: &this->m_rectImage, bLeftOf: v58);
    v43 = v59 != 0 || v57 != 0;
    CMFCCaptionBar::CheckRectangle(this, rectSrc: &this->m_rectDrawText, rectOther: &rectSrc, bLeftOf: v43);
  }
  if ( pFont != nullptr )
    CDC::SelectObject(this: &v50, pFont);
  this->m_bTextIsTruncated = this->m_rectDrawText.right - this->m_rectDrawText.left < v52.cx;
  CMFCCaptionBar::UpdateTooltips(this);
LABEL_92:
  v69 = -1;
  CClientDC::~CClientDC(this: &v50);
}

//------------------------------------------------------------------------------
// Address: 0x103D05E2
// Name: protected: virtual void CMFCCaptionBar::OnDrawButton(class CDC __near *,class CRect,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::OnDrawButton(
        CMFCCaptionBar *this,
        CDC *pDC,
        CRect rect,
        CFont *strButton,
        int bEnabled)
{
  BOOL v6; // edi
  CMFCVisualManager *Instance; // eax
  int v8; // eax
  int m_nHorzElementOffset; // eax
  int v10; // ecx
  int v11; // esi
  int top; // ecx
  int v13; // edx
  int v14; // esi
  int v15; // edi
  int v16; // eax
  int v17; // eax
  POINT *v18; // edx
  bool v19; // sf
  CDC *v20; // esi
  COLORREF TextColor; // eax
  CDC_vtbl *v22; // eax
  CFont *v23; // edi
  BOOL v24; // edi
  CMFCVisualManager *v25; // eax
  HDC__ *m_hAttribDC; // [esp-4h] [ebp-74h]
  CBrush v27; // [esp+10h] [ebp-60h] BYREF
  CFont *pFont; // [esp+18h] [ebp-58h]
  CDC *v29; // [esp+1Ch] [ebp-54h]
  POINT *p_apt; // [esp+20h] [ebp-50h]
  unsigned int v31; // [esp+24h] [ebp-4Ch]
  tagRECT rc; // [esp+28h] [ebp-48h] BYREF
  tagRECT v33; // [esp+38h] [ebp-38h] BYREF
  POINT apt; // [esp+48h] [ebp-28h] BYREF
  int v35; // [esp+50h] [ebp-20h]
  int v36; // [esp+54h] [ebp-1Ch]
  int v37; // [esp+58h] [ebp-18h]
  int v38; // [esp+5Ch] [ebp-14h]
  int v39; // [esp+6Ch] [ebp-4h]

  v29 = pDC;
  pFont = strButton;
  v6 = this->m_bIsBtnPressed != 0 || this->m_bIsBtnForcePressed != 0;
  Instance = CMFCVisualManager::GetInstance();
  v8 = ((int (__thiscall *)(CMFCVisualManager *, CDC *, CMFCCaptionBar *, int, int, int, int, BOOL, int, bool, int, _DWORD))Instance->OnFillCaptionBarButton)(
         a1: Instance,
         a2: v29,
         a3: this,
         a4: rect.left,
         a5: rect.top,
         a6: rect.right,
         a7: rect.bottom,
         a8: v6,
         a9: this->m_bIsBtnHighlighted,
         a10: this->m_bBtnEnabled == 0,
         a11: this->m_bBtnHasDropDownArrow,
         a12: 0);
  rc.left = rect.left;
  rc.top = rect.top;
  rc.right = rect.right;
  p_apt = (POINT *)v8;
  m_nHorzElementOffset = this->m_nHorzElementOffset;
  rc.bottom = rect.bottom;
  InflateRect(lprc: &rc, dx: -m_nHorzElementOffset, dy: 0);
  if ( this->m_bIsMessageBarMode != 0 )
    InflateRect(lprc: &rc, dx: -10, dy: 0);
  if ( this->m_uiBtnID != 0 && bEnabled != 0 && this->m_bBtnHasDropDownArrow != 0 )
    rc.right -= 10;
  v31 = -1;
  if ( p_apt != (POINT *)-1 )
    v31 = v29->SetTextColor(this: v29, a2: (unsigned int)p_apt);
  v29->DrawTextA(
    this: v29,
    a2: (const char *)pFont->__vftable,
    a3: (int)pFont->__vftable[-1].GetRuntimeClass,
    a4: &rc,
    a5: 32804u);
  if ( v31 != -1 )
    v29->SetTextColor(this: v29, a2: v31);
  if ( this->m_uiBtnID != 0 && bEnabled != 0 )
  {
    if ( this->m_bBtnHasDropDownArrow != 0 )
    {
      v10 = rect.bottom - this->m_nMargin;
      v33.right = rect.right;
      v33.top = v10 - 10;
      v33.bottom = v10;
      v33.left = rc.right;
      v11 = rc.right + (rect.right - rc.right) / 2;
      InflateRect(lprc: &v33, dx: 0, dy: -3);
      InflateRect(lprc: &v33, dx: (v33.bottom - v33.top) / -3, dy: (v33.bottom - v33.top) / -3);
      top = v33.top;
      v13 = v11 - v33.bottom;
      v14 = v11 - v33.top + v33.bottom + 1;
      v15 = v13 + v33.top - 1;
      v16 = v14 - v15;
      v33.left = v15;
      v33.right = v14;
      if ( (v14 - v15) % 2 != 0 )
        --v16;
      v17 = v16 / 2;
      p_apt = &apt;
      v31 = 2;
      do
      {
        v18 = p_apt;
        p_apt->x = 0;
        v18->y = 0;
        v19 = (--v31 & 0x80000000) != 0;
        p_apt = v18 + 1;
      }
      while ( !v19 );
      v37 = v15 + v17;
      v35 = v14;
      v20 = v29;
      m_hAttribDC = v29->m_hAttribDC;
      apt.x = v15;
      apt.y = top;
      v36 = top;
      v38 = v33.bottom + 1;
      TextColor = GetTextColor(hdc: m_hAttribDC);
      CBrush::CBrush(this: &v27, crColor: TextColor);
      v22 = v20->__vftable;
      v39 = 0;
      v23 = (CFont *)v22->SelectStockObject(this: v20, a2: 8);
      pFont = CDC::SelectObject(this: v20, pFont: (CFont *)&v27);
      CDC::SetPolyFillMode(this: v20, nPolyFillMode: 2);
      Polygon(hdc: v20->m_hDC, &apt, cpt: 3);
      CDC::SelectObject(this: v20, pFont);
      CDC::SelectObject(this: v20, pFont: v23);
      v39 = -1;
      v27.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
      CGdiObject::~CGdiObject(this: &v27);
    }
    v24 = this->m_bIsBtnPressed != 0 || this->m_bIsBtnForcePressed != 0;
    v25 = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCCaptionBar *, int, int, int, int, BOOL, int, bool, int, _DWORD))v25->OnDrawCaptionBarButtonBorder)(
      a1: v25,
      a2: v29,
      a3: this,
      a4: rect.left,
      a5: rect.top,
      a6: rect.right,
      a7: rect.bottom,
      a8: v24,
      a9: this->m_bIsBtnHighlighted,
      a10: this->m_bBtnEnabled == 0,
      a11: this->m_bBtnHasDropDownArrow,
      a12: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D08A2
// Name: protected: int CMFCCaptionBar::OnNeedTipText(unsigned int,struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCCaptionBar::OnNeedTipText(
        CMFCCaptionBar *this,
        unsigned int __formal,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pNMH,
        int *a4)
{
  CAfxStringMgr *StringManager; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v6; // edi
  CToolTipCtrl *m_pToolTip; // eax
  CAfxStringMgr *v8; // eax
  unsigned int m_pszData; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strImageDescription; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  ATL::CStringData *v15; // ecx
  CObject *v17; // eax
  char *v18; // esi
  CObject *v19; // ebx
  ATL::CStringData *v20; // eax
  _DWORD v21[6]; // [esp-4h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDescr; // [esp+14h] [ebp-10h] BYREF
  int v23; // [esp+20h] [ebp-4h]

  if ( (_S1_41 & 1) == 0 )
  {
    _S1_41 |= 1u;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTipText_2, pStringMgr: StringManager);
    atexit(func: CMFCCaptionBar::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__);
  }
  v6 = pNMH;
  if ( pNMH == nullptr )
LABEL_4:
    AfxThrowInvalidArgException();
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip == nullptr
    || m_pToolTip->m_hWnd == nullptr
    || pNMH->m_pszData != (char *)m_pToolTip->m_hWnd
    || CMFCPopupMenu::m_pActivePopupMenu != nullptr )
  {
    return 0;
  }
  v8 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDescr, pStringMgr: v8);
  m_pszData = (unsigned int)pNMH[1].m_pszData;
  v23 = 0;
  v10 = m_pszData - 1;
  if ( v10 == 0 )
  {
    StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3EA0u);
    if ( StringResourceHandle == nullptr
      || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: &strTipText_2,
           hInstance: StringResourceHandle,
           nID: 0x3EA0u) == 0 )
    {
      goto LABEL_4;
    }
    v6 = pNMH;
    goto LABEL_20;
  }
  v11 = v10 - 1;
  if ( v11 == 0 )
  {
    ATL::CSimpleStringT<char,0>::operator=(this: &strTipText_2, strSrc: (ATL::CStringData *)&this->m_strText);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(this: &strTipText_2, chRemove: 8);
    goto LABEL_20;
  }
  v12 = v11 - 1;
  if ( v12 == 0 )
  {
    ATL::CSimpleStringT<char,0>::operator=(this: &strTipText_2, strSrc: (ATL::CStringData *)&this->m_strImageToolTip);
    p_m_strImageDescription = &this->m_strImageDescription;
    goto LABEL_15;
  }
  if ( v12 == 1 )
  {
    ATL::CSimpleStringT<char,0>::operator=(this: &strTipText_2, strSrc: (ATL::CStringData *)&this->m_strButtonToolTip);
    p_m_strImageDescription = &this->m_strButtonDescription;
LABEL_15:
    ATL::CSimpleStringT<char,0>::operator=(this: &strDescr, strSrc: (ATL::CStringData *)p_m_strImageDescription);
  }
LABEL_20:
  if ( *((_DWORD *)strTipText_2.m_pszData - 3) != 0 )
  {
    v17 = AfxDynamicDownCast(pClass: &CMFCToolTipCtrl::classCMFCToolTipCtrl, pObject: this->m_pToolTip);
    v18 = strDescr.m_pszData;
    v19 = v17;
    if ( v17 != nullptr && *((_DWORD *)strDescr.m_pszData - 3) != 0 )
    {
      v21[5] = v21;
      v20 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strDescr.m_pszData - 1);
      ((void (__thiscall *)(CObject *, ATL::CStringData *))v19->__vftable[30].dtr_CObject)(a1: v19, a2: v20 + 1);
      v6 = pNMH;
    }
    v6[3].m_pszData = strTipText_2.m_pszData;
    v15 = (ATL::CStringData *)(v18 - 16);
  }
  else
  {
    v15 = (ATL::CStringData *)(strDescr.m_pszData - 16);
  }
  ATL::CStringData::Release(this: v15);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D0A2F
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCCaptionBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCCaptionBar::GetMessageMap(CMFCCaptionBar *this)
{
  return (const AFX_MSGMAP *)&off_1068448C;
}

//------------------------------------------------------------------------------
// Address: 0x103D0A35
// Name: public: virtual struct CRuntimeClass __near * CMFCOutlookBarPane::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCOutlookBarPane::GetRuntimeClass(CMFCOutlookBarPane *this)
{
  return &CMFCOutlookBarPane::classCMFCOutlookBarPane;
}

//------------------------------------------------------------------------------
// Address: 0x103D0A3B
// Name: public: CMFCOutlookBarPane::CMFCOutlookBarPane(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarPane *__thiscall CMFCOutlookBarPane::CMFCOutlookBarPane(CMFCOutlookBarPane *this)
{
  CMFCToolBar::CMFCToolBar(this);
  this->__vftable = (CMFCOutlookBarPane_vtbl *)&CMFCOutlookBarPane::`vftable';
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_bmpBack);
  CMFCButton::CMFCButton(this: &this->m_btnUp);
  CMFCButton::CMFCButton(this: &this->m_btnDown);
  this->m_nSize = -1;
  this->m_clrRegText = -1;
  this->m_iScrollOffset = 0;
  this->m_iFirstVisibleButton = 0;
  this->m_bScrollDown = 0;
  this->m_clrBackColor = afxGlobalData.clrBtnShadow;
  this->m_clrTransparentColor = 16711935;
  CMFCToolBarImages::SetTransparentColor(this: &CMFCOutlookBarPane::m_Images, clrTransparent: 0xFF00FFu);
  this->m_uiBackImageId = 0;
  this->m_btnUp.m_nFlatStyle = BUTTONSTYLE_3D;
  this->m_btnUp.m_bDrawFocus = 0;
  this->m_btnDown.m_nFlatStyle = BUTTONSTYLE_3D;
  this->m_btnDown.m_bDrawFocus = 0;
  this->m_bDrawShadedHighlight = 0;
  this->m_bDisableControlsIfNoHandler = 0;
  this->m_nExtraSpace = 0;
  this->m_hRecentOutlookWnd = nullptr;
  this->m_bPageScrollMode = 0;
  this->m_bDontAdjustLayout = 0;
  this->m_bLocked = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103D0B1E
// Name: public: virtual int CMFCOutlookBarPane::CanBeRestored(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCOutlookBarPane::CanBeRestored(CMFCOutlookBarPane *this)
{
  return this->m_OrigButtons.m_nCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103D0B2A
// Name: protected: virtual unsigned long CMFCOutlookBarPane::GetCurrentAlignment(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCOutlookBarPane::GetCurrentAlignment(CMFCOutlookBarPane *this)
{
  return this->m_dwStyle & 0x5000;
}

//------------------------------------------------------------------------------
// Address: 0x103D0B36
// Name: public: virtual CMFCOutlookBarPane::~CMFCOutlookBarPane(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::~CMFCOutlookBarPane(CMFCOutlookBarPane *this)
{
  this->__vftable = (CMFCOutlookBarPane_vtbl *)&CMFCOutlookBarPane::`vftable';
  CMFCButton::~CMFCButton(this: &this->m_btnDown);
  CMFCButton::~CMFCButton(this: &this->m_btnUp);
  CMFCToolBarImages::~CMFCToolBarImages(this: &this->m_bmpBack);
  CMFCToolBar::~CMFCToolBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D0B8E
// Name: public: virtual int CMFCOutlookBarPane::Create(class CWnd __near *,unsigned long,unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCOutlookBarPane::Create(
        CMFCOutlookBarPane *this,
        CWnd *pParentWnd,
        unsigned int dwStyle,
        unsigned int uiID,
        unsigned int dwControlBarStyle)
{
  BOOL result; // eax

  result = CMFCToolBar::Create(this, pParentWnd, dwStyle, nID: uiID);
  if ( result )
  {
    this->m_dwControlBarStyle = dwControlBarStyle;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D0BB9
// Name: protected: int CMFCOutlookBarPane::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarPane::OnCreate(CMFCOutlookBarPane *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  CMFCOutlookBarPane_vtbl *v4; // eax
  CSize *v5; // eax
  int cx; // ecx
  CSize v7; // [esp+4h] [ebp-1Ch] BYREF
  CRect rectDummy; // [esp+Ch] [ebp-14h] BYREF

  result = CMFCToolBar::OnCreate(this, lpCreateStruct);
  if ( result != -1 )
  {
    this->SetPaneStyle(this, a2: this->m_dwStyle & 0xFFBFF0FF);
    v4 = this->__vftable;
    this->m_cxRightBorder = 0;
    this->m_cxLeftBorder = 0;
    this->m_cyBottomBorder = 0;
    this->m_cyTopBorder = 0;
    v4->SetWindowPos(this, a2: &CWnd::wndBottom, a3: 0, a4: 0, a5: 0, a6: 0, a7: 19u, a8: nullptr);
    v5 = CMenuImages::Size(result: &v7);
    cx = v5->cx;
    rectDummy.bottom = v5->cy;
    rectDummy.left = 0;
    rectDummy.right = cx;
    rectDummy.top = 0;
    InflateRect(lprc: &rectDummy, dx: 3, dy: 3);
    this->m_btnUp.Create_2(this: &this->m_btnUp, a2: &var, a3: 0x40000000u, a4: &rectDummy, a5: this, a6: -1u);
    CMFCButton::SetStdImage(this: &this->m_btnUp, id: IdArrowUpLarge, state: ImageBlack, idDisabled: IdArrowDown);
    this->m_btnDown.Create_2(this: &this->m_btnDown, a2: &var, a3: 0x40000000u, a4: &rectDummy, a5: this, a6: -1u);
    CMFCButton::SetStdImage(this: &this->m_btnDown, id: IdArrowDownLarge, state: ImageBlack, idDisabled: IdArrowDown);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D0CCB
// Name: protected: void CMFCOutlookBarPane::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::OnNcCalcSize(CMFCOutlookBarPane *this, int __formal, tagNCCALCSIZE_PARAMS *lpncsp)
{
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  CPane::CalcInsideRect(this, &rect, bHorz: 0);
  lpncsp->rgrc[0].left += rect.left;
  lpncsp->rgrc[0].top += rect.top;
  lpncsp->rgrc[0].right += rect.right;
  lpncsp->rgrc[0].bottom += rect.bottom;
}

//------------------------------------------------------------------------------
// Address: 0x103D0D31
// Name: protected: virtual class CMFCToolBarButton __near * CMFCOutlookBarPane::CreateDroppedButton(class COleDataObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarButton *__thiscall CMFCOutlookBarPane::CreateDroppedButton(
        CMFCOutlookBarPane *this,
        COleDataObject *pDataObject)
{
  CMFCToolBarButton *DroppedButton; // eax
  CMFCToolBarButton *v3; // esi

  DroppedButton = CMFCToolBar::CreateDroppedButton(this, pDataObject);
  v3 = DroppedButton;
  if ( DroppedButton == nullptr )
    AfxThrowInvalidArgException();
  if ( AfxDynamicDownCast(pClass: &CMFCOutlookBarPaneButton::classCMFCOutlookBarPaneButton, pObject: DroppedButton) != nullptr )
    return v3;
  ((void (__thiscall *)(CMFCToolBarButton *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D0D6F
// Name: public: virtual enum AFX_CS_STATUS CMFCOutlookBarPane::IsChangeState(int,class CBasePane __near * __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarPane::IsChangeState(CMFCOutlookBarPane *this, int __formal, CBasePane **ppTargetBar)
{
  CBasePane *v3; // ecx
  CBasePane *v4; // eax
  CBasePane *v5; // eax
  CPoint v7; // [esp-18h] [ebp-2Ch]
  CPoint ptMousePos; // [esp+8h] [ebp-Ch] BYREF
  CBasePane *v9; // [esp+10h] [ebp-4h]

  v9 = this;
  if ( ppTargetBar == nullptr )
    AfxThrowInvalidArgException();
  ptMousePos.x = 0;
  ptMousePos.y = 0;
  GetCursorPos(lpPoint: &ptMousePos);
  v3 = v9;
  v7.y = ptMousePos.y;
  *ppTargetBar = nullptr;
  v7.x = ptMousePos.x;
  v4 = CBasePane::PaneFromPoint(
         this: v3,
         point: v7,
         nSensitivity: 0,
         bExactBar: 0,
         pRTCBarType: &CMFCOutlookBar::classCMFCOutlookBar);
  v5 = (CBasePane *)AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: v4);
  if ( v5 == nullptr )
    return 0;
  *ppTargetBar = v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D0DD0
// Name: protected: void CMFCOutlookBarPane::OnSetFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::OnSetFocus(CMFCOutlookBarPane *this, CWnd *pOldWnd)
{
  CWnd::OnSetFocus(this, __formal: pOldWnd);
}

//------------------------------------------------------------------------------
// Address: 0x103D0DDB
// Name: protected: void CMFCOutlookBarPane::OnNcDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMFCOutlookBarPane::OnNcDestroy(CMFCOutlookBarPane *this)
{
  CPane::OnNcDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D0DE0
// Name: public: virtual int CMFCOutlookBarPane::SmartUpdate(class CObList const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarPane::SmartUpdate(CMFCOutlookBarPane *this, const CObList *lstPrevButtons)
{
  CObList::CNode *m_pNodeHead; // esi
  CObList::CNode *v5; // edi
  CObject *v6; // eax
  CObject *v7; // eax
  CObject *v8; // [esp-18h] [ebp-20h]
  CObject *data; // [esp-10h] [ebp-18h]
  CMFCOutlookBarPane *v10; // [esp+0h] [ebp-8h]
  CMFCToolBarButton *pButtonCurr; // [esp+4h] [ebp-4h]
  int bIsModified; // [esp+10h] [ebp+8h]

  v10 = this;
  if ( lstPrevButtons->m_nCount == 0 )
    return 0;
  this->m_bResourceWasChanged = 0;
  bIsModified = 0;
  if ( lstPrevButtons->m_nCount != this->m_OrigButtons.m_nCount )
    goto LABEL_11;
  m_pNodeHead = this->m_OrigButtons.m_pNodeHead;
  v5 = lstPrevButtons->m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      if ( v5 == nullptr )
        AfxThrowInvalidArgException();
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      v6 = AfxDynamicDownCast(pClass: &CMFCToolBarButton::classCMFCToolBarButton, pObject: data);
      v8 = v5->data;
      v5 = v5->pNext;
      pButtonCurr = (CMFCToolBarButton *)v6;
      v7 = AfxDynamicDownCast(pClass: &CMFCToolBarButton::classCMFCToolBarButton, pObject: v8);
      if ( pButtonCurr->CompareWith(this: pButtonCurr, a2: (const CMFCToolBarButton *)v7) == 0 )
        break;
      if ( m_pNodeHead == nullptr )
        return bIsModified;
    }
    this = v10;
LABEL_11:
    bIsModified = 1;
    this->RestoreOriginalstate(this);
  }
  return bIsModified;
}

//------------------------------------------------------------------------------
// Address: 0x103D0E81
// Name: protected: void CMFCOutlookBarPane::CopyButtonsList(class CObList const __near &,class CObList __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::CopyButtonsList(CMFCOutlookBarPane *this, const CObList *lstSrc, CObList *lstDst)
{
  CObject *v3; // eax
  CObList::CNode *m_pNodeHead; // edi
  CObject *data; // ebx
  CRuntimeClass *v6; // eax
  CObject *Object; // esi

  while ( lstDst->m_nCount != 0 )
  {
    v3 = CObList::RemoveHead(this: lstDst);
    if ( v3 != nullptr )
      ((void (__thiscall *)(CObject *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  }
  m_pNodeHead = lstSrc->m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v6 = (CRuntimeClass *)data->GetRuntimeClass(this: data);
    if ( v6 == nullptr )
      AfxThrowInvalidArgException();
    Object = CRuntimeClass::CreateObject(this: v6);
    Object->__vftable[1].Serialize(this: Object, a2: (CArchive *)data);
    ((void (__thiscall *)(CObject *, CMFCOutlookBarPane *))Object->__vftable[3].dtr_CObject)(a1: Object, a2: this);
    CPtrList::AddTail(this: lstDst, newElement: Object);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D0F00
// Name: public: static class CObject __near * CMFCOutlookBarPane::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarPane *__stdcall CMFCOutlookBarPane::CreateObject()
{
  CMFCOutlookBarPane *v0; // ecx
  CMFCOutlookBarPane *result; // eax

  v0 = (CMFCOutlookBarPane *)operator new(nSize: 0x1CA8u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCOutlookBarPane::CMFCOutlookBarPane(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D0F51
// Name: protected: void CMFCOutlookBarPane::ScrollUp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::ScrollUp(CMFCOutlookBarPane *this)
{
  __POSITION *Button; // eax

  if ( this->m_iScrollOffset <= 0 || this->m_iFirstVisibleButton <= 0 )
  {
    this->m_iScrollOffset = 0;
    this->m_iFirstVisibleButton = 0;
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
  }
  else
  {
    Button = CMFCToolBar::GetButton(this, nIndex: this->m_iFirstVisibleButton);
    if ( Button != nullptr )
    {
      --this->m_iFirstVisibleButton;
      this->m_iScrollOffset += *(_DWORD *)&Button[88] - *(_DWORD *)&Button[96];
      if ( this->m_iFirstVisibleButton == 0 )
        this->m_iScrollOffset = 0;
      this->AdjustLocations(this);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
    else
    {
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D0FD4
// Name: protected: void CMFCOutlookBarPane::ScrollDown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::ScrollDown(CMFCOutlookBarPane *this)
{
  int m_iFirstVisibleButton; // edi
  __POSITION *Button; // eax
  int v4; // ecx
  CMFCOutlookBarPane_vtbl *v5; // eax

  if ( this->m_bScrollDown != 0
    && (m_iFirstVisibleButton = this->m_iFirstVisibleButton) + 1 < CMFCToolBar::GetCount(this)
    && (Button = CMFCToolBar::GetButton(this, nIndex: m_iFirstVisibleButton)) != nullptr )
  {
    ++this->m_iFirstVisibleButton;
    v4 = *(_DWORD *)&Button[96] - *(_DWORD *)&Button[88];
    v5 = this->__vftable;
    this->m_iScrollOffset += v4;
    v5->AdjustLocations(this);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  else
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D1043
// Name: protected: virtual class CSize CMFCOutlookBarPane::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCOutlookBarPane::CalcFixedLayout(CMFCOutlookBarPane *this, CSize *result, int __formal, int a4)
{
  CRect rect; // [esp+4h] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  result->cx = rect.right - rect.left;
  result->cy = rect.bottom - rect.top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D1098
// Name: public: void CMFCOutlookBarPane::SetBackImage(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::SetBackImage(CMFCOutlookBarPane *this, HBITMAP__ *uiImageID)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HBITMAP__ *ImageW; // eax
  int bmWidth; // eax
  HWND__ *m_hWnd; // eax
  tagBITMAP bitmap; // [esp+8h] [ebp-18h] BYREF
  HBITMAP__ *hbmp; // [esp+28h] [ebp+8h]

  if ( (HBITMAP__ *)this->m_uiBackImageId != uiImageID )
  {
    this->m_bDrawShadedHighlight = 0;
    if ( this->m_bmpBack.m_iCount > 0 )
      CMFCToolBarImages::Clear(this: &this->m_bmpBack);
    this->m_uiBackImageId = 0;
    if ( uiImageID != nullptr )
    {
      ModuleState = AfxGetModuleState();
      ImageW = (HBITMAP__ *)LoadImageW(
                              hInst: ModuleState->m_hCurrentResourceHandle,
                              name: (LPCWSTR)(unsigned __int16)uiImageID,
                              type: 0,
                              cx: 0,
                              cy: 0,
                              fuLoad: 0x3000u);
      hbmp = ImageW;
      if ( ImageW != nullptr )
      {
        GetObjectA(h: ImageW, c: 24, pv: &bitmap);
        bmWidth = bitmap.bmWidth;
        this->m_bmpBack.m_sizeImage.cy = bitmap.bmHeight;
        this->m_bmpBack.m_sizeImage.cx = bmWidth;
        CMFCToolBarImages::AddImage(this: &this->m_bmpBack, hbmp, bSetBitPerPixel: 0);
        this->m_uiBackImageId = (unsigned int)uiImageID;
      }
      this->m_bDrawShadedHighlight = afxGlobalData.m_nBitsPerPixel > 8;
    }
    m_hWnd = this->m_hWnd;
    if ( m_hWnd != nullptr )
    {
      InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D1162
// Name: protected: void CMFCOutlookBarPane::OnSysColorChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::OnSysColorChange(CMFCOutlookBarPane *this)
{
  HBITMAP__ *m_uiBackImageId; // ecx

  CMFCToolBar::OnSysColorChange(this);
  m_uiBackImageId = (HBITMAP__ *)this->m_uiBackImageId;
  this->m_clrBackColor = afxGlobalData.clrBtnShadow;
  if ( m_uiBackImageId != nullptr )
  {
    this->m_uiBackImageId = -1;
    CMFCOutlookBarPane::SetBackImage(this, uiImageID: m_uiBackImageId);
  }
  else
  {
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D11A1
// Name: protected: virtual void CMFCOutlookBarPane::AdjustLocations(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::AdjustLocations(CMFCOutlookBarPane *this)
{
  CSize *v2; // eax
  int cy; // ecx
  int cx; // eax
  CMFCVisualManager *Instance; // eax
  CSize *v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  CObList::CNode *m_pNodeHead; // eax
  int bottom; // eax
  BOOL v12; // ecx
  CObject *data; // esi
  int *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int m_nExtraSpace; // ecx
  int v19; // eax
  CObject *v20; // ecx
  CObject_vtbl *v21; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-90h]
  char v23[8]; // [esp+10h] [ebp-78h] BYREF
  CClientDC v24; // [esp+18h] [ebp-70h] BYREF
  int v25; // [esp+2Ch] [ebp-5Ch]
  int v26; // [esp+30h] [ebp-58h]
  CObject_vtbl *v27; // [esp+34h] [ebp-54h]
  int v28; // [esp+38h] [ebp-50h]
  CObject *v29; // [esp+3Ch] [ebp-4Ch]
  CFont *pFont; // [esp+40h] [ebp-48h]
  CSize result; // [esp+44h] [ebp-44h] BYREF
  int v32; // [esp+4Ch] [ebp-3Ch]
  int v33; // [esp+54h] [ebp-34h]
  CObList::CNode *pNext; // [esp+58h] [ebp-30h]
  int v35; // [esp+5Ch] [ebp-2Ch] BYREF
  int v36; // [esp+60h] [ebp-28h]
  int v37; // [esp+64h] [ebp-24h]
  tagRECT Rect; // [esp+68h] [ebp-20h] BYREF
  int v39; // [esp+84h] [ebp-4h]

  if ( this != nullptr && this->m_hWnd != nullptr )
  {
    v2 = CMenuImages::Size(&result);
    cy = v2->cy;
    cx = v2->cx;
    v37 = cy + 6;
    v32 = cx + 6;
    CClientDC::CClientDC(this: &v24, pWnd: this);
    v39 = 0;
    pFont = CDC::SelectObject(this: &v24, pFont: &afxGlobalData.fontRegular);
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    v35 = Rect.right - Rect.left - 2;
    v36 = CMFCOutlookBarPane::m_csImage.cy;
    if ( this->IsButtonExtraSizeAvailable(this) != 0 )
    {
      Instance = CMFCVisualManager::GetInstance();
      v6 = Instance->GetButtonExtraBorder(this: Instance, &result);
      v7 = v6->cx;
      v8 = v6->cy;
      v35 += v7;
      v36 += v8;
    }
    v9 = this->m_nExtraSpace + Rect.top - this->m_iScrollOffset;
    if ( this->m_iFirstVisibleButton <= 0 || v32 > Rect.right - Rect.left - 5 || v37 > Rect.bottom - Rect.top - 5 )
    {
      CWnd::ShowWindow(this: &this->m_btnUp, nCmdShow: 0);
    }
    else
    {
      CWnd::SetWindowPos(
        this: &this->m_btnUp,
        pWndInsertAfter: nullptr,
        x: Rect.right - v32 - 5,
        y: Rect.top + 5,
        cx: -1,
        cy: -1,
        nFlags: 0x15u);
      CWnd::ShowWindow(this: &this->m_btnUp, nCmdShow: 4);
    }
    m_pNodeHead = this->m_Buttons.m_pNodeHead;
    if ( m_pNodeHead != nullptr )
    {
      while ( 1 )
      {
        data = m_pNodeHead->data;
        pNext = m_pNodeHead->pNext;
        v29 = data;
        if ( data == nullptr )
          AfxThrowInvalidArgException();
        data[6].__vftable = (CObject_vtbl *)this->m_bTextLabels;
        *(CSize *)&data[29].__vftable = CMFCOutlookBarPane::m_csImage;
        v14 = (int *)((int (__thiscall *)(CObject *, char *, CClientDC *, int *, _DWORD))data->__vftable[2].dtr_CObject)(
                       a1: data,
                       a2: v23,
                       a3: &v24,
                       a4: &v35,
                       a5: 0);
        v15 = *v14;
        result.cy = v14[1];
        v16 = Rect.right - Rect.left - 1;
        if ( v16 < v15 )
          v15 = Rect.right - Rect.left - 1;
        v26 = v9;
        v25 = Rect.left + (v16 - v15) / 2;
        v17 = v15 + v25;
        m_nExtraSpace = this->m_nExtraSpace;
        v27 = (CObject_vtbl *)v17;
        v19 = v9 + result.cy;
        v28 = v9 + result.cy;
        data[21].__vftable = (CObject_vtbl *)v25;
        data[22].__vftable = (CObject_vtbl *)v26;
        data[23].__vftable = v27;
        v33 = v19 + m_nExtraSpace;
        v20 = v29;
        v21 = v29->__vftable;
        data[24].__vftable = (CObject_vtbl *)v28;
        v21[4].GetRuntimeClass(this: v20);
        v9 = v33;
        if ( pNext == nullptr )
          break;
        m_pNodeHead = pNext;
      }
    }
    bottom = Rect.bottom;
    v12 = v9 > Rect.bottom;
    this->m_bScrollDown = v12;
    if ( v12 && v32 <= Rect.right - Rect.left - 5 && v37 <= bottom - Rect.top - 5 )
    {
      CWnd::SetWindowPos(
        this: &this->m_btnDown,
        pWndInsertAfter: &CWnd::wndTop,
        x: Rect.right - v32 - 5,
        y: bottom - v37 - 5,
        cx: -1,
        cy: -1,
        nFlags: 0x11u);
      CWnd::ShowWindow(this: &this->m_btnDown, nCmdShow: 4);
    }
    else
    {
      CWnd::ShowWindow(this: &this->m_btnDown, nCmdShow: 0);
    }
    CDC::SelectObject(this: &v24, pFont);
    RedrawWindow(hWnd: this->m_btnUp.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    RedrawWindow(hWnd: this->m_btnDown.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    CMFCToolBar::OnMouseLeave(this, __formal: 0, a3: 0);
    CMFCToolBar::UpdateTooltips(this);
    v39 = -1;
    CClientDC::~CClientDC(this: &v24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D143F
// Name: protected: virtual void CMFCOutlookBarPane::DoPaint(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::DoPaint(CMFCOutlookBarPane *this, CDC *pDCPaint)
{
  CDC *p_m_dcMem; // eax
  CMFCVisualManager *Instance; // eax
  CMFCToolBar *v5; // esi
  CDC *v6; // edi
  CDC *m_pNodeHead; // eax
  int v8; // ecx
  __POSITION *Button; // eax
  CDC_vtbl *v10; // eax
  CDC *v11; // edx
  int *m_hAttribDC; // eax
  int m_iButtonCapture; // eax
  BOOL v14; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-C8h]
  HWND__ *v16; // [esp-8h] [ebp-C8h]
  tagAFXDrawState v17; // [esp+10h] [ebp-B0h] BYREF
  int *v18; // [esp+1Ch] [ebp-A4h]
  int v19; // [esp+20h] [ebp-A0h]
  int v20; // [esp+24h] [ebp-9Ch]
  CMFCToolBar *v21; // [esp+28h] [ebp-98h]
  CDC *v22; // [esp+2Ch] [ebp-94h]
  CDC *dc; // [esp+30h] [ebp-90h]
  CMemDC v24; // [esp+34h] [ebp-8Ch] BYREF
  tagRECT rcDst; // [esp+70h] [ebp-50h] BYREF
  tagRECT Rect; // [esp+80h] [ebp-40h] BYREF
  tagRECT rc; // [esp+90h] [ebp-30h] BYREF
  tagRECT v28; // [esp+A0h] [ebp-20h] BYREF
  int v29; // [esp+BCh] [ebp-4h]

  dc = pDCPaint;
  m_hWnd = this->m_hWnd;
  v21 = this;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  v16 = this->m_hWnd;
  memset(&v28, 0, sizeof(v28));
  GetClientRect(hWnd: v16, lpRect: &v28);
  CMemDC::CMemDC(this: &v24, dc: pDCPaint, pWnd: (HDC__ *)this);
  v29 = 0;
  p_m_dcMem = &v24.m_dcMem;
  if ( v24.m_bMemDC == 0 )
    p_m_dcMem = v24.m_dc;
  v22 = p_m_dcMem;
  Instance = CMFCVisualManager::GetInstance();
  v5 = v21;
  v6 = v22;
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCToolBar *, int, int, int, int, int, int, int, int, _DWORD))Instance->OnFillBarBackground)(
    a1: Instance,
    a2: v22,
    a3: v21,
    a4: v28.left,
    a5: v28.top,
    a6: v28.right,
    a7: v28.bottom,
    a8: v28.left,
    a9: v28.top,
    a10: v28.right,
    a11: v28.bottom,
    a12: 0);
  if ( v21->m_Buttons.m_nCount != 0 )
  {
    v22->SetTextColor(this: v22, a2: afxGlobalData.clrBtnText);
    CDC::SetBkMode(this: v22, nBkMode: 1);
    if ( CMFCToolBarImages::PrepareDrawImage(
           this: &CMFCOutlookBarPane::m_Images,
           ds: &v17,
           sizeImageDest: 0,
           bFadeInactive: 0) != 0 )
    {
      v19 = (int)v6->SelectObject(this: v6, a2: &afxGlobalData.fontRegular);
      m_pNodeHead = (CDC *)v5->m_Buttons.m_pNodeHead;
      v8 = 0;
      v20 = 0;
      if ( m_pNodeHead != nullptr )
      {
        while ( 1 )
        {
          v11 = (CDC *)m_pNodeHead->__vftable;
          m_hAttribDC = (int *)m_pNodeHead->m_hAttribDC;
          rc.left = m_hAttribDC[21];
          rc.top = m_hAttribDC[22];
          rc.right = m_hAttribDC[23];
          v18 = m_hAttribDC;
          dc = v11;
          rc.bottom = m_hAttribDC[24];
          v14 = false;
          if ( (CMFCToolBar::m_bCustomizeMode == 0 || v21->m_bLocked != 0)
            && (v8 == v21->m_iHighlighted || v8 == v21->m_iButtonCapture) )
          {
            m_iButtonCapture = v21->m_iButtonCapture;
            if ( m_iButtonCapture == -1 || v8 == m_iButtonCapture )
              v14 = true;
          }
          memset(&rcDst, 0, sizeof(rcDst));
          if ( IntersectRect(lprcDst: &rcDst, lprcSrc1: &rc, lprcSrc2: &Rect) )
            (*(void (__thiscall **)(int *, CDC *, tagRECT *, CMFCToolBarImages *, _DWORD, int, BOOL, int, int))(*v18 + 24))(
              a1: v18,
              a2: v22,
              a3: &rc,
              a4: &CMFCOutlookBarPane::m_Images,
              a5: 0,
              a6: CMFCToolBar::m_bCustomizeMode,
              a7: v14,
              a8: 1,
              a9: 1);
          ++v20;
          if ( dc == nullptr )
            break;
          v8 = v20;
          m_pNodeHead = dc;
        }
        v6 = v22;
        v5 = v21;
      }
      if ( v5->m_iSelected >= v5->m_Buttons.m_nCount )
        v5->m_iSelected = -1;
      if ( CMFCToolBar::m_bCustomizeMode != 0 )
      {
        if ( v5->m_iSelected >= 0 && v5->m_bLocked == 0 )
        {
          Button = CMFCToolBar::GetButton(this: v5, nIndex: v5->m_iSelected);
          dc = (CDC *)Button;
          if ( Button == nullptr )
            AfxThrowInvalidArgException();
          if ( (*(int (__thiscall **)(__POSITION *))(*(_DWORD *)Button + 80))(a1: Button) != 0 )
          {
            v10 = dc->__vftable;
            rc = *(tagRECT *)((char *)dc + 84);
            if ( ((int (*)(void))v10->SetViewportOrg)() != 0 )
              InflateRect(lprc: &rc, dx: 0, dy: 1);
            CDC::DrawDragRect(
              this: v22,
              lpRect: &rc,
              size: (tagSIZE)0x200000002LL,
              lpRectLast: nullptr,
              sizeLast: (tagSIZE)0x200000002LL,
              pBrush: nullptr,
              pBrushLast: nullptr);
            v6 = v22;
            v5 = v21;
          }
        }
        if ( CMFCToolBar::m_bCustomizeMode != 0 && v5->m_iDragIndex >= 0 && v5->m_bLocked == 0 )
          v5->DrawDragCursor(this: v5, a2: v6);
      }
      CDC::SelectClipRgn(this: v6, pRgn: nullptr);
      v6->SelectObject(this: v6, a2: (CFont *)v19);
      CMFCToolBarImages::EndDrawImage(this: &CMFCOutlookBarPane::m_Images, ds: &v17);
    }
  }
  v29 = -1;
  CMemDC::~CMemDC(this: &v24);
}

//------------------------------------------------------------------------------
// Address: 0x103D1752
// Name: protected: virtual unsigned long CMFCOutlookBarPane::OnDragOver(class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCOutlookBarPane::OnDragOver(
        CMFCOutlookBarPane *this,
        COleDataObject *pDataObject,
        char dwKeyState,
        CPoint point)
{
  CMFCToolBarButton *v5; // eax
  CMFCToolBarButton *v6; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-40h]
  int bAllowDrop; // [esp+Ch] [ebp-2Ch]
  CRect rectUp; // [esp+14h] [ebp-24h] BYREF
  CRect rectDown; // [esp+24h] [ebp-14h] BYREF

  v5 = CMFCToolBarButton::CreateFromOleData(pDataObject);
  v6 = v5;
  if ( v5 == nullptr )
    return 0;
  bAllowDrop = CObject::IsKindOf(this: v5, pClass: &CMFCOutlookBarPaneButton::classCMFCOutlookBarPaneButton);
  ((void (__thiscall *)(CMFCToolBarButton *, int))v6->dtr_CObject)(a1: v6, a2: 1);
  if ( bAllowDrop == 0 )
    return 0;
  m_hWnd = this->m_btnUp.m_hWnd;
  memset(&rectUp, 0, sizeof(rectUp));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectUp);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectUp);
  if ( PtInRect(lprc: &rectUp, pt: point.tagPOINT) )
  {
    CMFCOutlookBarPane::ScrollUp(this);
    return 0;
  }
  memset(&rectDown, 0, sizeof(rectDown));
  GetWindowRect(hWnd: this->m_btnDown.m_hWnd, lpRect: &rectDown);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectDown);
  if ( PtInRect(lprc: &rectDown, pt: point.tagPOINT) )
  {
    CMFCOutlookBarPane::ScrollDown(this);
    return 0;
  }
  return CMFCToolBar::OnDragOver(this, pDataObject, dwKeyState, point);
}

//------------------------------------------------------------------------------
// Address: 0x103D184C
// Name: protected: virtual int CMFCOutlookBarPane::EnableContextMenuItems(class CMFCToolBarButton __near *,class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarPane::EnableContextMenuItems(
        CMFCOutlookBarPane *this,
        CMFCToolBarButton *pButton,
        CMenu *pPopup)
{
  if ( CMFCToolBar::m_bCustomizeMode != 0 )
  {
    EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4212u, uEnable: 1u);
    EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4213u, uEnable: 1u);
    EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4214u, uEnable: 1u);
    EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4211u, uEnable: 1u);
    EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x4215u, uEnable: 1u);
    EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x420Eu, uEnable: 1u);
    EnableMenuItem(hMenu: pPopup->m_hMenu, uIDEnableItem: 0x420Fu, uEnable: 1u);
  }
  CMFCToolBar::EnableContextMenuItems(this, pButton, pPopup);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D18CF
// Name: protected: void CMFCOutlookBarPane::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::OnLButtonUp(CMFCOutlookBarPane *this, WPARAM nFlags, CPoint point)
{
  HWND__ *m_hWnd; // edi

  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  CMFCToolBar::OnLButtonUp(this, nFlags, point);
  if ( IsWindow(hWnd: m_hWnd) )
    CMFCToolBar::OnMouseLeave(this, __formal: 0, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103D190D
// Name: public: virtual void CMFCOutlookBarPane::RemoveAllButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::RemoveAllButtons(CMFCOutlookBarPane *this)
{
  CMFCOutlookBarPane_vtbl *v2; // eax

  CMFCToolBar::RemoveAllButtons(this);
  v2 = this->__vftable;
  this->m_iFirstVisibleButton = 0;
  this->m_iScrollOffset = 0;
  v2->AdjustLocations(this);
  if ( this->m_hWnd != nullptr )
  {
    UpdateWindow(hWnd: this->m_hWnd);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D194C
// Name: public: virtual int CMFCOutlookBarPane::OnBeforeFloat(class CRect __near &,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCOutlookBarPane::OnBeforeFloat(
        CMFCOutlookBarPane *this,
        CRect *__formal,
        AFX_DOCK_METHOD dockMethod)
{
  BOOL result; // eax
  HWND Parent; // eax
  CWnd *v6; // edi
  BOOL v7; // eax
  BOOL v8; // esi
  HWND v9; // eax
  CWnd *v10; // eax
  CPoint ptMouse; // [esp+4h] [ebp-20h] BYREF
  CMFCOutlookBarPane *v12; // [esp+Ch] [ebp-18h]
  CRect rect; // [esp+10h] [ebp-14h] BYREF

  result = true;
  v12 = this;
  if ( dockMethod == DM_MOUSE )
  {
    ptMouse = 0;
    GetCursorPos(lpPoint: &ptMouse);
    Parent = GetParent(hWnd: this->m_hWnd);
    v6 = CWnd::FromHandle(hWnd: Parent);
    memset(&rect, 0, sizeof(rect));
    GetWindowRect(hWnd: v6->m_hWnd, lpRect: &rect);
    v7 = PtInRect(lprc: &rect, pt: ptMouse.tagPOINT);
    v8 = !v7;
    if ( !v7 )
    {
      if ( CObject::IsKindOf(this: v6, pClass: &CMFCOutlookBar::classCMFCOutlookBar) != 0 )
      {
        v12->m_hRecentOutlookWnd = v6->m_hWnd;
      }
      else
      {
        v9 = GetParent(hWnd: v6->m_hWnd);
        v10 = CWnd::FromHandle(hWnd: v9);
        if ( v10 != nullptr )
          v10 = (CWnd *)v10->m_hWnd;
        v12->m_hRecentOutlookWnd = (HWND__ *)v10;
      }
    }
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D1A15
// Name: public: virtual int CMFCOutlookBarPane::RestoreOriginalstate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarPane::RestoreOriginalstate(CMFCOutlookBarPane *this)
{
  if ( this->m_OrigButtons.m_nCount == 0 )
    return 0;
  CMFCOutlookBarPane::CopyButtonsList(this, lstSrc: &this->m_OrigButtons, lstDst: &this->m_Buttons);
  this->AdjustLayout(this);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D1A5B
// Name: protected: void CMFCOutlookBarPane::ScrollPageUp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::ScrollPageUp(CMFCOutlookBarPane *this)
{
  __POSITION *Button; // edi
  int v3; // ecx
  int v4; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-28h]
  CRect rcArea; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_iScrollOffset <= 0 || this->m_iFirstVisibleButton <= 0 )
  {
    this->m_iScrollOffset = 0;
    this->m_iFirstVisibleButton = 0;
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
  }
  else
  {
    Button = CMFCToolBar::GetButton(this, nIndex: this->m_iFirstVisibleButton);
    if ( Button != nullptr )
    {
      m_hWnd = this->m_hWnd;
      memset(&rcArea, 0, sizeof(rcArea));
      GetClientRect(hWnd: m_hWnd, lpRect: &rcArea);
      v3 = *(_DWORD *)&Button[96] + this->m_nExtraSpace - *(_DWORD *)&Button[88];
      if ( (rcArea.bottom - rcArea.top) / v3 > 0 )
      {
        v4 = (rcArea.bottom - rcArea.top) / v3;
        do
        {
          CMFCOutlookBarPane::ScrollUp(this);
          --v4;
        }
        while ( v4 != 0 );
      }
    }
    else
    {
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D1AFC
// Name: protected: void CMFCOutlookBarPane::ScrollPageDown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::ScrollPageDown(CMFCOutlookBarPane *this)
{
  int m_iFirstVisibleButton; // edi
  __POSITION *Button; // edi
  int v4; // ecx
  int v5; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-28h]
  CRect rcArea; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_bScrollDown != 0
    && (m_iFirstVisibleButton = this->m_iFirstVisibleButton) + 1 < CMFCToolBar::GetCount(this)
    && (Button = CMFCToolBar::GetButton(this, nIndex: m_iFirstVisibleButton)) != nullptr )
  {
    m_hWnd = this->m_hWnd;
    memset(&rcArea, 0, sizeof(rcArea));
    GetClientRect(hWnd: m_hWnd, lpRect: &rcArea);
    v4 = *(_DWORD *)&Button[96] + this->m_nExtraSpace - *(_DWORD *)&Button[88];
    if ( (rcArea.bottom - rcArea.top) / v4 > 0 )
    {
      v5 = (rcArea.bottom - rcArea.top) / v4;
      do
      {
        CMFCOutlookBarPane::ScrollDown(this);
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  else
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D1B97
// Name: protected: void CMFCOutlookBarPane::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::OnSize(CMFCOutlookBarPane *this, unsigned int nType, unsigned int cx, int cy)
{
  CMFCOutlookBarPane_vtbl *v5; // eax
  int m_nCount; // eax
  __POSITION *Index; // eax
  int v8; // ebx

  CMFCToolBar::OnSize(this, nType, cx, cy);
  v5 = this->__vftable;
  if ( this->m_bDontAdjustLayout != 0 )
    v5->AdjustLocations(this);
  else
    v5->AdjustLayout(this);
  m_nCount = this->m_Buttons.m_nCount;
  if ( m_nCount > 0 )
  {
    Index = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_Buttons, nIndex: m_nCount - 1);
    if ( Index == nullptr || (v8 = *(_DWORD *)&Index[8]) == 0 )
      AfxThrowInvalidArgException();
    while ( this->m_iScrollOffset > 0 && *(_DWORD *)(v8 + 96) < cy )
      CMFCOutlookBarPane::ScrollUp(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D1C12
// Name: protected: virtual int CMFCOutlookBarPane::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarPane::PreTranslateMessage(CMFCOutlookBarPane *this, tagMSG *pMsg)
{
  unsigned int message; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-30h]
  CPoint ptCursor; // [esp+8h] [ebp-1Ch] BYREF
  CRect rect; // [esp+10h] [ebp-14h] BYREF

  message = pMsg->message;
  if ( message >= 0x200 )
  {
    if ( message > 0x201 )
    {
      if ( message != 514 )
        return CMFCToolBar::PreTranslateMessage(this, pMsg);
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
    }
    ptCursor = 0;
    GetCursorPos(lpPoint: &ptCursor);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
    m_hWnd = this->m_btnDown.m_hWnd;
    memset(&rect, 0, sizeof(rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &rect);
    MapWindowPoints(hWndFrom: this->m_btnDown.m_hWnd, hWndTo: this->m_hWnd, lpPoints: (LPPOINT)&rect, cPoints: 2u);
    if ( PtInRect(lprc: &rect, pt: ptCursor.tagPOINT) )
    {
      SendMessageA(hWnd: this->m_btnDown.m_hWnd, Msg: pMsg->message, wParam: pMsg->wParam, lParam: pMsg->wParam);
      if ( pMsg->message == 513 )
      {
        SetTimer(hWnd: this->m_hWnd, nIDEvent: 2u, uElapse: 0xC8u, lpTimerFunc: nullptr);
        if ( this->m_bPageScrollMode != 0 )
          CMFCOutlookBarPane::ScrollPageDown(this);
        else
          CMFCOutlookBarPane::ScrollDown(this);
      }
    }
    GetClientRect(hWnd: this->m_btnUp.m_hWnd, lpRect: &rect);
    MapWindowPoints(hWndFrom: this->m_btnUp.m_hWnd, hWndTo: this->m_hWnd, lpPoints: (LPPOINT)&rect, cPoints: 2u);
    if ( PtInRect(lprc: &rect, pt: ptCursor.tagPOINT) )
    {
      SendMessageA(hWnd: this->m_btnUp.m_hWnd, Msg: pMsg->message, wParam: pMsg->wParam, lParam: pMsg->wParam);
      if ( pMsg->message == 513 )
      {
        SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0xC8u, lpTimerFunc: nullptr);
        if ( this->m_bPageScrollMode != 0 )
          CMFCOutlookBarPane::ScrollPageUp(this);
        else
          CMFCOutlookBarPane::ScrollUp(this);
      }
    }
  }
  return CMFCToolBar::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103D1DA0
// Name: protected: void CMFCOutlookBarPane::OnTimer(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::OnTimer(CMFCOutlookBarPane *this, unsigned int nIDEvent)
{
  if ( nIDEvent == 1 )
  {
    if ( CMFCButton::IsPressed(this: &this->m_btnUp) )
    {
      if ( this->m_bPageScrollMode != 0 )
        CMFCOutlookBarPane::ScrollPageUp(this);
      else
        CMFCOutlookBarPane::ScrollUp(this);
    }
  }
  else if ( nIDEvent == 2 )
  {
    if ( CMFCButton::IsPressed(this: &this->m_btnDown) )
    {
      if ( this->m_bPageScrollMode != 0 )
        CMFCOutlookBarPane::ScrollPageDown(this);
      else
        CMFCOutlookBarPane::ScrollDown(this);
    }
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D1E0B
// Name: public: virtual int CMFCOutlookBarPane::Dock(class CBasePane __near *,struct tagRECT const __near *,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarPane::Dock(
        CMFCOutlookBarPane *this,
        CBasePane *pDockBar,
        const tagRECT *__formal,
        AFX_DOCK_METHOD dockMethod)
{
  CAfxStringMgr *StringManager; // eax
  int v6; // ebx
  CObject *v7; // eax
  CObject *v8; // esi
  int v10; // esi
  int v11; // edi
  CWnd *v12; // [esp-4h] [ebp-28h]
  CPaneFrameWnd *pParentMiniFrame; // [esp+10h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+14h] [ebp-10h] BYREF
  int v15; // [esp+20h] [ebp-4h]

  pParentMiniFrame = this->GetParentMiniFrame(this, a2: 0);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strText, pStringMgr: StringManager);
  v15 = 0;
  CWnd::GetWindowTextA(this, rString: &strText);
  v6 = 1;
  if ( dockMethod == DM_DBL_CLICK )
  {
    v12 = CWnd::FromHandlePermanent(hWnd: (CDocument *)this->m_hRecentOutlookWnd);
    v7 = AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: v12);
  }
  else
  {
    if ( dockMethod != DM_MOUSE )
    {
LABEL_6:
      v6 = 0;
      goto LABEL_7;
    }
    v7 = AfxDynamicDownCast(pClass: &CMFCOutlookBar::classCMFCOutlookBar, pObject: pDockBar);
  }
  v8 = v7;
  if ( v7 == nullptr )
    goto LABEL_6;
  if ( pParentMiniFrame != nullptr )
    pParentMiniFrame->RemovePane(this: pParentMiniFrame, a2: this, a3: 0, a4: 0);
  ((void (__thiscall *)(CObject *, CMFCOutlookBarPane *, int, int, int))v8->__vftable[79].dtr_CObject)(
    a1: v8,
    a2: this,
    a3: 1,
    a4: 1,
    a5: 1);
  v10 = ((int (__thiscall *)(CObject *))v8->__vftable[77].Serialize)(a1: v8);
  v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 424))(a1: v10) - 1;
  (*(void (__thiscall **)(int, int, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))(*(_DWORD *)v10 + 444))(
    a1: v10,
    a2: v11,
    a3: &strText);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 528))(a1: v10, a2: v11);
LABEL_7:
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x103D1EE2
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCOutlookBarPane::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCOutlookBarPane::GetMessageMap(CMFCOutlookBarPane *this)
{
  return (const AFX_MSGMAP *)&off_10684A9C;
}

//------------------------------------------------------------------------------
// Address: 0x103D1EE8
// Name: protected: virtual void CMFCOutlookBarPane::OnEraseWorkArea(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPane::OnEraseWorkArea(CMFCOutlookBarPane *this, CDC *pDC, CRect rectWorkArea)
{
  CMFCToolBarImages *p_m_bmpBack; // ebx
  int cx; // ecx
  int cy; // esi
  int left; // eax
  int top; // eax
  tagAFXDrawState v9; // [esp+Ch] [ebp-24h] BYREF
  CSize sizeBack; // [esp+18h] [ebp-18h]
  CBrush br; // [esp+20h] [ebp-10h] BYREF
  int x; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  br.m_hObject = pDC;
  if ( this->m_bmpBack.m_iCount != 0 )
  {
    p_m_bmpBack = &this->m_bmpBack;
    CMFCToolBarImages::PrepareDrawImage(this: &this->m_bmpBack, ds: &v9, sizeImageDest: 0, bFadeInactive: 0);
    cx = this->m_bmpBack.m_sizeImage.cx;
    cy = this->m_bmpBack.m_sizeImage.cy;
    left = rectWorkArea.left;
    for ( sizeBack.cx = cx; ; left = sizeBack.cx + x )
    {
      x = left;
      if ( left >= rectWorkArea.right )
        break;
      top = rectWorkArea.top;
      y = rectWorkArea.top;
      while ( top < rectWorkArea.bottom )
      {
        CMFCToolBarImages::Draw(
          this: p_m_bmpBack,
          pDCDest: (CDC *)br.m_hObject,
          xDest: (CDC_vtbl *)x,
          yDest: y,
          iImage: 0,
          bHilite: 0,
          bDisabled: 0,
          bIndeterminate: 0,
          bShadow: 0,
          bInactive: 0,
          alphaSrc: 0xFFu);
        y += cy;
        top = y;
      }
    }
    CMFCToolBarImages::EndDrawImage(this: p_m_bmpBack, ds: &v9);
  }
  else
  {
    CBrush::CBrush(this: &br, crColor: this->m_clrBackColor);
    FillRect(hDC: pDC->m_hDC, lprc: &rectWorkArea, hbr: (HBRUSH)br.m_hObject);
    br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    CGdiObject::~CGdiObject(this: &br);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D1FAC
// Name: public: virtual struct CRuntimeClass __near * CMFCRibbonDefaultPanelButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCRibbonDefaultPanelButton::GetRuntimeClass(CMFCRibbonDefaultPanelButton *this)
{
  return &CMFCRibbonDefaultPanelButton::classCMFCRibbonDefaultPanelButton;
}

//------------------------------------------------------------------------------
// Address: 0x103D1FB2
// Name: public: CMFCRibbonDefaultPanelButton::CMFCRibbonDefaultPanelButton(class CMFCRibbonPanel __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonDefaultPanelButton::CMFCRibbonDefaultPanelButton(
        CMFCRibbonDefaultPanelButton *this,
        CMFCRibbonPanel *pPanel)
{
  CMFCRibbonButton::CMFCRibbonButton(this);
  this->m_hIcon = nullptr;
  this->m_pPanel = pPanel;
  this->__vftable = (CMFCRibbonDefaultPanelButton_vtbl *)&CMFCRibbonDefaultPanelButton::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103D1FDC
// Name: public: virtual void CMFCRibbonDefaultPanelButton::OnClick(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonDefaultPanelButton::OnClick(CMFCRibbonDefaultPanelButton *this, CPoint __formal)
{
  this->OnShowPopupMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D1FE7
// Name: public: virtual CRibbonCategoryScroll::~CRibbonCategoryScroll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRibbonCategoryScroll::~CRibbonCategoryScroll(CRibbonCategoryScroll *this)
{
  CMFCRibbonButton::~CMFCRibbonButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D1FEC
// Name: public: virtual void CMFCRibbonDefaultPanelButton::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonDefaultPanelButton::OnDraw(CMFCRibbonDefaultPanelButton *this, CDC *pDC)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  Instance->OnDrawRibbonDefaultPaneButton(this: Instance, a2: pDC, a3: this);
}

//------------------------------------------------------------------------------
// Address: 0x103D200C
// Name: public: virtual void CMFCRibbonDefaultPanelButton::OnLButtonDown(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonDefaultPanelButton::OnLButtonDown(CMFCRibbonDefaultPanelButton *this, CPoint point)
{
  CMFCRibbonBaseElement::OnLButtonDown(this, __formal: point);
  this->OnShowPopupMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D202E
// Name: public: virtual struct CRuntimeClass __near * CMFCRibbonPanel::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCRibbonPanel::GetRuntimeClass(CMFCRibbonPanel *this)
{
  return &CMFCRibbonPanel::classCMFCRibbonPanel;
}

//------------------------------------------------------------------------------
// Address: 0x103D2034
// Name: protected: int CMFCRibbonPanel::GetMinWidth(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonPanel::GetMinWidth(CMFCRibbonPanel *this, CDC *pDC)
{
  CMFCRibbonDefaultPanelButton *p_m_btnDefault; // esi
  CSize v4; // [esp+4h] [ebp-8h] BYREF

  p_m_btnDefault = &this->m_btnDefault;
  this->m_btnDefault.OnCalcTextSize(this: &this->m_btnDefault, a2: pDC);
  return p_m_btnDefault->GetRegularSize(this: p_m_btnDefault, result: &v4, a3: pDC)->cx;
}

//------------------------------------------------------------------------------
// Address: 0x103D2064
// Name: public: int CMFCRibbonPanel::IsCollapsed(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonPanel::IsCollapsed(CMFCRibbonPanel *this)
{
  RECT rc; // [esp+8h] [ebp-14h] BYREF

  rc = (RECT)this->m_btnDefault.m_rect;
  return !IsRectEmpty(lprc: &rc);
}

//------------------------------------------------------------------------------
// Address: 0x103DA3C3
// Name: public: virtual CMFCTabDropTarget::~CMFCTabDropTarget(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMFCTabDropTarget::~CMFCTabDropTarget(CMFCTabDropTarget *this)
{
  COleDropTarget::~COleDropTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x103DA3C8
// Name: public: virtual unsigned long CMFCTabDropTarget::OnDragEnter(class CWnd __near *,class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCTabDropTarget::OnDragEnter(
        CMFCTabDropTarget *this,
        CWnd *__formal,
        COleDataObject *pDataObject,
        unsigned int dwKeyState,
        CPoint point)
{
  if ( this->m_pOwner == nullptr )
    AfxThrowInvalidArgException();
  if ( CMFCToolBar::m_bCustomizeMode != 0
    && COleDataObject::IsDataAvailable(this: pDataObject, cfFormat: CMFCToolBarButton::m_cFormat, lpFormatEtc: nullptr) )
  {
    return ((unsigned int (__thiscall *)(CMFCBaseTabCtrl *, COleDataObject *, unsigned int, int, int))this->m_pOwner->OnDragEnter)(
             a1: this->m_pOwner,
             a2: pDataObject,
             a3: dwKeyState,
             a4: point.x,
             a5: point.y);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DA419
// Name: public: virtual void CMFCTabDropTarget::OnDragLeave(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabDropTarget::OnDragLeave(CMFCTabDropTarget *this, CWnd *__formal)
{
  if ( this->m_pOwner == nullptr )
    AfxThrowInvalidArgException();
  this->m_pOwner->OnDragLeave(this: this->m_pOwner);
}

//------------------------------------------------------------------------------
// Address: 0x103DA432
// Name: public: virtual unsigned long CMFCTabDropTarget::OnDragOver(class CWnd __near *,class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCTabDropTarget::OnDragOver(
        CMFCTabDropTarget *this,
        CWnd *__formal,
        COleDataObject *pDataObject,
        unsigned int dwKeyState,
        CPoint point)
{
  CMFCBaseTabCtrl *m_pOwner; // ecx
  int v8; // edi

  if ( this->m_pOwner == nullptr )
    AfxThrowInvalidArgException();
  if ( CMFCToolBar::m_bCustomizeMode != 0
    && COleDataObject::IsDataAvailable(this: pDataObject, cfFormat: CMFCToolBarButton::m_cFormat, lpFormatEtc: nullptr) )
  {
    return ((unsigned int (__thiscall *)(CMFCBaseTabCtrl *, COleDataObject *, unsigned int, int, int))this->m_pOwner->OnDragOver)(
             a1: this->m_pOwner,
             a2: pDataObject,
             a3: dwKeyState,
             a4: point.x,
             a5: point.y);
  }
  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr )
  {
    v8 = m_pOwner->GetTabFromPoint(this: m_pOwner, a2: &point);
    if ( v8 != -1 && v8 != this->m_pOwner->GetActiveTab(this: this->m_pOwner) )
      this->m_pOwner->SetActiveTab(this: this->m_pOwner, a2: v8);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103DA4BA
// Name: public: virtual unsigned long CMFCTabDropTarget::OnDropEx(class CWnd __near *,class COleDataObject __near *,unsigned long,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCTabDropTarget::OnDropEx(
        CMFCTabDropTarget *this,
        CWnd *__formal,
        COleDataObject *pDataObject,
        unsigned int dropEffect,
        unsigned int a5,
        CPoint point)
{
  if ( this->m_pOwner == nullptr )
    AfxThrowInvalidArgException();
  if ( CMFCToolBar::m_bCustomizeMode != 0
    && COleDataObject::IsDataAvailable(this: pDataObject, cfFormat: CMFCToolBarButton::m_cFormat, lpFormatEtc: nullptr) )
  {
    return ((int (__thiscall *)(CMFCBaseTabCtrl *, COleDataObject *, unsigned int, int, int))this->m_pOwner->OnDrop)(
             a1: this->m_pOwner,
             a2: pDataObject,
             a3: dropEffect,
             a4: point.x,
             a5: point.y) != 0
         ? dropEffect
         : 0;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DA512
// Name: public: virtual struct CRuntimeClass __near * CMFCBaseTabCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCBaseTabCtrl::GetRuntimeClass(CMFCBaseTabCtrl *this)
{
  return &CMFCBaseTabCtrl::classCMFCBaseTabCtrl;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100CEFE0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = szDescription;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100CF080
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x100CF0A0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF0F0
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF140
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF190
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x100CF1A0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x100CF1C0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x100CF1D0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x100CF200
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x100CF210
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x100CF240
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF430
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF4C0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CF4E0
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CF510
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x100CF530
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x100CF550
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x100CF570
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_1010DB00;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x100CF610
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CF6A0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CF6E0
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF8B0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CF990
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CFBB0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFE20
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00479450
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004794F0
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x00479510
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479560
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004795B0
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479600
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x00479610
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x00479630
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x00479640
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x00479670
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00479680
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x004796B0
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 2) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 4) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 4) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004798A0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x004798C0
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  this->m_bWrapCenter = bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x004798D0
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x004798F0
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00479910
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_4BF7C4;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x004799B0
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00479A40
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479A80
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_18;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 )
          goto LABEL_13;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_13:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_17:
          iCurLineW = v6;
        }
LABEL_18:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_19;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_17;
    }
LABEL_19:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479C40
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00479D20
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edx
  unsigned __int16 i; // ax
  unsigned __int16 v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // eax
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+21h] [ebp-3h]
  bool justStartedNewLine; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  for ( i = *wsz; *wsz != 0; x = v8 )
  {
    v7 = i;
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
      v7 = towupper(c: i);
    if ( iswspace(c: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    i = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x00479F10
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A180
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v19; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v19 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v19, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v19 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          *wide += c + b + a;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = text + 1;
        v14 = v19 == (vgui::ISurface *)1;
        v19 = (vgui::ISurface *)((char *)v19 - 1);
        ++text;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0045A310
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-804h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: &unicode[2], a4: 2048);
    this->SetText(this, a2: &unicode[2], a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045A3B0
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x0045A3C0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A410
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A460
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A4B0
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x0045A4C0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x0045A4D0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x0045A500
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0045A510
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+8h] [ebp-8h] BYREF
  int v3; // [esp+Ch] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &v3, a3: &wide);
  this->SetSize(this, a2: v3, a3: wide);
}

//------------------------------------------------------------------------------
// Address: 0x0045A550
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  char v4; // al
  int v5; // esi
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // ebx
  unsigned __int16 v9; // ax
  int v10; // eax
  unsigned int v11; // ecx
  bool v12; // cc
  _WORD *v13; // esi
  int v14; // edi
  wchar_t v15; // ax
  unsigned int font; // [esp+20h] [ebp-14h]
  int ellipsesWidth; // [esp+28h] [ebp-Ch]
  int h; // [esp+2Ch] [ebp-8h]
  int ha; // [esp+2Ch] [ebp-8h]
  unsigned int v22; // [esp+30h] [ebp-4h] BYREF

  *((_BYTE *)this + 52) &= ~1u;
  v4 = *((_BYTE *)this + 52);
  this->m_pwszEllipsesPosition = nullptr;
  if ( (v4 & 2) == 0 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: (int *)&v22);
    v5 = 0;
    ellipsesWidth = 0;
    if ( ((*((_BYTE *)this + 52) & 4) != 0) != -1 )
    {
      while ( 1 )
      {
        h = ((int (__thiscall *)(vgui::TextImage *, int, int))this->GetFont)(a1: this, a2, a3);
        if ( v5 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            h = fallbackFont;
          }
        }
        a3 = 46;
        a2 = h;
        v7 = ((int (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->GetCharacterWidth)(a1: g_pVGuiSurface);
        utext = this->_utext;
        ha = 3 * v7;
        v9 = *utext;
        font = 0;
        if ( *utext != 0 )
          break;
LABEL_28:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v5 = ellipsesWidth + 1;
          ellipsesWidth = v5;
          if ( v5 < ((*((_BYTE *)this + 52) & 4) != 0) + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 == 13 )
          goto LABEL_25;
        if ( v9 == 38 )
        {
          if ( utext[1] != 38 )
            goto LABEL_25;
          ++utext;
        }
        v10 = ((int (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->GetCharacterWidth)(a1: g_pVGuiSurface);
        if ( utext == this->_utext )
        {
          font += v10;
        }
        else
        {
          v11 = v10 + font;
          v12 = (int)(v10 + font + ha) <= this->_drawWidth;
          v22 = v10 + font;
          if ( !v12 )
          {
            v13 = utext + 1;
            v14 = v10;
            v15 = utext[1];
            if ( v15 != 0 )
            {
              do
              {
                ++v13;
                v14 += ((int (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->GetCharacterWidth)(a1: g_pVGuiSurface);
              }
              while ( *v13 != 0 );
              v11 = v22;
            }
            if ( (signed int)(font + v14) > this->_drawWidth )
            {
              this->m_pwszEllipsesPosition = utext;
              goto LABEL_28;
            }
          }
          font = v11;
        }
LABEL_25:
        v9 = utext[1];
        ++utext;
        if ( v9 == 0 )
          goto LABEL_28;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A720
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x0045A750
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x0045A770
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x0045A790
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  bool v6; // cc
  __int16 v7; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v9; // ecx
  unsigned __int16 v10; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_48C00C;
  v5 = wcslen(v4);
  v6 = v5 < this->_textBufferLen;
  this->_textLen = v5;
  if ( !v6 )
  {
    free(pMem: this->_utext);
    v7 = this->_textLen + 1;
    this->_textBufferLen = v7;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v7);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v9 = v4;
  do
  {
    v10 = *v9;
    *utext++ = *v9++;
  }
  while ( v10 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x0045A830
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  this->_textBufferLen = 0;
  this->_textLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045A8C0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045A900
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  int v2; // ebp
  CUtlVector<int,CUtlMemory<int,int> > *p_m_LineXIndent; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // bx
  unsigned __int16 v7; // ax
  int v8; // eax
  double v9; // xmm0_8
  int currentLineBreak; // [esp+10h] [ebp-14h]
  unsigned int font; // [esp+14h] [ebp-10h]
  unsigned int py; // [esp+18h] [ebp-Ch]
  int px; // [esp+1Ch] [ebp-8h] BYREF
  char v14[4]; // [esp+20h] [ebp-4h] BYREF

  v2 = 0;
  p_m_LineXIndent = &this->m_LineXIndent;
  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    py = this->GetFont(this);
    this->GetPos(this, a2: (int *)v14, a3: &px);
    utext = this->_utext;
    v5 = *utext;
    font = 0;
    currentLineBreak = (int)utext;
    if ( *utext != 0 )
    {
      while ( 1 )
      {
        v6 = v5;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
        {
          v7 = towupper(c: v5);
          utext = (wchar_t *)currentLineBreak;
          v6 = v7;
        }
        if ( v6 == 13 )
          goto LABEL_18;
        if ( v6 == 10 )
          break;
        if ( v6 != 38 )
          goto LABEL_13;
        if ( utext[1] == 38 )
        {
          currentLineBreak = (int)++utext;
LABEL_13:
          if ( font != this->m_LineBreaks.m_Size && utext == this->m_LineBreaks.m_Memory.m_pMemory[font] )
          {
            v8 = CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(this: p_m_LineXIndent, elem: p_m_LineXIndent->m_Size);
            v9 = (double)(this->_drawWidth - v2) * 0.5;
            v2 = 0;
            ++font;
            p_m_LineXIndent->m_Memory.m_pMemory[v8] = (int)v9;
          }
          v2 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: py, a3: v6);
LABEL_17:
          utext = (wchar_t *)currentLineBreak;
        }
LABEL_18:
        v5 = utext[1];
        currentLineBreak = (int)++utext;
        if ( v5 == 0 )
          goto LABEL_19;
      }
      p_m_LineXIndent->m_Memory.m_pMemory[CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
                                            this: p_m_LineXIndent,
                                            elem: p_m_LineXIndent->m_Size)] = (int)((double)(this->_drawWidth - v2) * 0.5);
      v2 = 0;
      goto LABEL_17;
    }
LABEL_19:
    p_m_LineXIndent->m_Memory.m_pMemory[CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
                                          this: p_m_LineXIndent,
                                          elem: p_m_LineXIndent->m_Size)] = (int)((double)(this->_drawWidth - v2) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AA80
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  this->_textBufferLen = 0;
  this->_textLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045AB60
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  wchar_t v4; // cx
  char v5; // bl
  int v6; // edx
  wchar_t *v7; // ebp
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // di
  int v10; // ebp
  __int16 wsz_2; // [esp+12h] [ebp-12h]
  wchar_t *wordStartIndex; // [esp+14h] [ebp-10h] BYREF
  int x; // [esp+18h] [ebp-Ch] BYREF
  unsigned int font; // [esp+1Ch] [ebp-8h]
  unsigned int v15; // [esp+20h] [ebp-4h]

  v15 = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  x = (int)utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  v6 = 0;
  font = 0;
  wsz_2 = 257;
  if ( v4 == 13 || v4 == 10 )
    v6 = 1;
  v7 = &v3[v6];
  v8 = *v7;
  wordStartIndex = v7;
  if ( v8 != 0 )
  {
    while ( 1 )
    {
      v9 = v8;
      if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
        v9 = towupper(c: v8);
      if ( iswspace(c: v9) != 0 )
      {
        v5 = 0;
      }
      else if ( v5 == 0 )
      {
        x = (int)v7;
        v5 = 1;
        HIBYTE(wsz_2) = wsz_2;
      }
      v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v15, a3: v9);
      if ( iswcntrl(c: v9) == 0 )
        LOBYTE(wsz_2) = 0;
      if ( (signed int)(v10 + font) > this->_drawWidth || v9 == 13 || v9 == 10 )
      {
        v5 = 0;
        LOBYTE(wsz_2) = 1;
        if ( v9 != 13 && v9 != 10 )
        {
          if ( HIBYTE(wsz_2) != 0 )
          {
            CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
              this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_LineBreaks,
              elem: this->m_LineBreaks.m_Size,
              src: (vgui::TreeNode **)&wordStartIndex);
          }
          else
          {
            CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
              this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_LineBreaks,
              elem: this->m_LineBreaks.m_Size,
              src: (vgui::TreeNode **)&x);
            wordStartIndex = (wchar_t *)(x - 2);
          }
        }
        font = 0;
      }
      else
      {
        font += v10;
      }
      v8 = *++wordStartIndex;
      if ( *wordStartIndex == 0 )
        break;
      v7 = wordStartIndex;
    }
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045ACC0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<ebx>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  bool v9; // zf
  wchar_t *utext; // ecx
  unsigned __int16 v11; // ax
  int v12; // ebp
  unsigned __int16 v13; // ax
  int v14; // eax
  int v15; // eax
  int i; // esi
  wchar_t *wsz; // [esp+34h] [ebp-28h]
  int iIndent; // [esp+38h] [ebp-24h]
  int py; // [esp+3Ch] [ebp-20h]
  int px; // [esp+40h] [ebp-1Ch] BYREF
  int lineHeight; // [esp+44h] [ebp-18h] BYREF
  int currentLineBreak; // [esp+48h] [ebp-14h]
  unsigned int font; // [esp+4Ch] [ebp-10h]
  int tall; // [esp+50h] [ebp-Ch] BYREF
  int wide; // [esp+54h] [ebp-8h] BYREF
  _BYTE v26[4]; // [esp+58h] [ebp-4h] BYREF

  this->GetSize(this, a2: (int *)v26, a3: &wide);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2, a3: (int)this);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &tall);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    tall = v6;
    DrawSetTextFont(this, a2: v6);
    currentLineBreak = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    v8 = 0;
    wsz = nullptr;
    py = 0;
    this->GetPos(this, a2: &lineHeight, a3: &px);
    v9 = this->m_LineXIndent.m_Size == 0;
    font = 0;
    if ( !v9 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v11 = *utext;
    iIndent = (int)utext;
    if ( *utext != 0 )
    {
      while ( 1 )
      {
        v12 = v11;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
        {
          v13 = towupper(c: v11);
          utext = (wchar_t *)iIndent;
          v12 = v13;
        }
        if ( (_WORD)v12 == 13 )
          goto LABEL_32;
        if ( (_WORD)v12 == 10 )
        {
          v14 = ++py;
          if ( py >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v14];
          wsz = (wchar_t *)((char *)wsz + currentLineBreak);
          goto LABEL_32;
        }
        if ( (_WORD)v12 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + lineHeight, a3: (int)wsz + px);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
LABEL_31:
        utext = (wchar_t *)iIndent;
LABEL_32:
        v11 = utext[1];
        iIndent = (int)++utext;
        if ( v11 == 0 )
          return;
      }
      iIndent = (int)++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( i = 3; i != 0; --i )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + lineHeight, a3: (int)wsz + px);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( font != this->m_LineBreaks.m_Size && utext == this->m_LineBreaks.m_Memory.m_pMemory[font] )
      {
        v15 = ++py;
        if ( py >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v15];
        wsz = (wchar_t *)((char *)wsz + currentLineBreak);
        ++font;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + lineHeight, a3: (int)wsz + px);
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v12, a3: FONT_DRAW_DEFAULT);
      v6 = tall;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: tall, a3: (unsigned __int16)v12);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AF60
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  vgui::ISurface *v5; // ebx
  int (__thiscall **p_GetFontTall)(vgui::ISurface *, unsigned int); // esi
  unsigned int v7; // eax
  int v8; // eax
  unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int text; // [esp+18h] [ebp-18h]
  wchar_t *font; // [esp+1Ch] [ebp-14h]
  unsigned int fonta; // [esp+1Ch] [ebp-14h]
  int b; // [esp+20h] [ebp-10h]
  int a; // [esp+24h] [ebp-Ch] BYREF
  int c; // [esp+28h] [ebp-8h] BYREF
  int v21; // [esp+2Ch] [ebp-4h] BYREF
  int maxWide; // [esp+34h] [ebp+4h]
  wchar_t *talla; // [esp+38h] [ebp+8h]

  *wide = 0;
  *tall = 0;
  maxWide = 0;
  font = this->_utext;
  b = this->_font;
  if ( b != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v5 = g_pVGuiSurface;
    p_GetFontTall = &g_pVGuiSurface->GetFontTall;
    v7 = this->GetFont(this);
    v8 = (*p_GetFontTall)(this: v5, a2: v7);
    v10 = font;
    text = v8;
    *tall = v8;
    v11 = wcslen(font);
    if ( v11 > 0 )
    {
      talla = font;
      fonta = v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || talla[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: b, a3: v12, a4: &c, a5: &a, a6: &v21);
          *wide += v21 + a + c;
          if ( v12 == 10 )
          {
            *tall += text;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( talla == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += text;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = talla + 1;
        v14 = fonta-- == 1;
        ++talla;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00665390
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00665430
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x00665450
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006654A0
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006654F0
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00665540
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x00665550
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x00665570
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x00665580
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x006655B0
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x006655C0
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x006655F0
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 2) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 4) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 4) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006657E0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00665800
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  this->m_bWrapCenter = bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x00665810
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00665830
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00665850
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_736BA4;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v6 >> 31 != 0 ? -1 : 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x006658F0
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00665980
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x006659C0
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_18;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 )
          goto LABEL_13;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_13:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_17:
          iCurLineW = v6;
        }
LABEL_18:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_19;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_17;
    }
LABEL_19:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00665B80
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00665C60
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edx
  unsigned __int16 i; // ax
  unsigned __int16 v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // eax
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+21h] [ebp-3h]
  bool justStartedNewLine; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  for ( i = *wsz; *wsz != 0; x = v8 )
  {
    v7 = i;
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
      v7 = towupper(c: i);
    if ( iswspace(c: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    i = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x00665E50
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006660C0
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v19; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v19 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v19, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v19 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          *wide += c + b + a;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = text + 1;
        v14 = v19 == (vgui::ISurface *)1;
        v19 = (vgui::ISurface *)((char *)v19 - 1);
        ++text;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10074810
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100748B0
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x100748D0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074920
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074970
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100749C0
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x100749D0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x100749F0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x10074A00
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x10074A30
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10074A40
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10074A70
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074C60
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074CF0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x10074D10
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x10074D40
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x10074D60
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10074D80
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x10074DA0
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_100A7A7C;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10074E40
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10074ED0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x10074F10
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100750E0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100751C0
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x100753E0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075650
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10096900
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100969A0
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x100969C0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096A10
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096A60
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096AB0
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x10096AC0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x10096AE0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x10096AF0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x10096B20
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10096B30
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10096B60
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096D50
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096DE0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x10096E00
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x10096E30
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x10096E50
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10096E70
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x10096E90
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_100FF8DC;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10096F30
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10096FC0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x10097000
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100971D0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100972B0
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x100974D0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097740
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00470EE0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = &defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00470F80
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x00470FA0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470FF0
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471040
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471090
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x004710A0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x004710C0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x004710D0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x00471100
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00471110
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00471140
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 2) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 4) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 4) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471330
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00471350
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  this->m_bWrapCenter = bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x00471360
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00471380
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004713A0
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_49AE50;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x00471440
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004714D0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x00471510
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_18;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 )
          goto LABEL_13;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_13:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_17:
          iCurLineW = v6;
        }
LABEL_18:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_19;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_17;
    }
LABEL_19:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004716D0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004717B0
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edx
  unsigned __int16 i; // ax
  unsigned __int16 v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // eax
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+21h] [ebp-3h]
  bool justStartedNewLine; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  for ( i = *wsz; *wsz != 0; x = v8 )
  {
    v7 = i;
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
      v7 = towupper(c: i);
    if ( iswspace(c: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    i = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x004719A0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471C10
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v19; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v19 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v19, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v19 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          *wide += c + b + a;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = text + 1;
        v14 = v19 == (vgui::ISurface *)1;
        v19 = (vgui::ISurface *)((char *)v19 - 1);
        ++text;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004B1F90
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-804h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: &unicode[2], a4: 2048);
    this->SetText(this, a2: &unicode[2], a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004B2030
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x004B2040
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2090
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B20E0
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2140
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x004B2150
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x004B2160
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x004B2180
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x004B2190
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+8h] [ebp-8h] BYREF
  int v3; // [esp+Ch] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &v3, a3: &wide);
  this->SetSize(this, a2: v3, a3: wide);
}

//------------------------------------------------------------------------------
// Address: 0x004B21D0
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  char v4; // al
  int v5; // esi
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // ebx
  unsigned __int16 v9; // ax
  int v10; // esi
  int v11; // eax
  bool v12; // zf
  float v13; // xmm1_4
  float v14; // xmm0_4
  wchar_t v15; // ax
  _WORD *v16; // esi
  int v17; // edi
  int check; // [esp+20h] [ebp-14h]
  int ellipsesWidth; // [esp+24h] [ebp-10h]
  int v22; // [esp+28h] [ebp-Ch]
  float len; // [esp+2Ch] [ebp-8h]
  float v24; // [esp+30h] [ebp-4h] BYREF

  *((_BYTE *)this + 52) &= ~1u;
  v4 = *((_BYTE *)this + 52);
  this->m_pwszEllipsesPosition = nullptr;
  if ( (v4 & 2) == 0 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: (int *)&v24);
    v5 = 0;
    if ( ((*((_BYTE *)this + 52) & 4) != 0) != -1 )
    {
      while ( 1 )
      {
        ellipsesWidth = ((int (__thiscall *)(vgui::TextImage *, int, int))this->GetFont)(a1: this, a2, a3);
        if ( v5 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            ellipsesWidth = fallbackFont;
          }
        }
        a3 = 46;
        a2 = ellipsesWidth;
        v7 = ((int (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->GetCharacterWidth)(a1: g_pVGuiSurface);
        utext = this->_utext;
        v22 = 3 * v7;
        v9 = *utext;
        v10 = 0;
        check = 0;
        if ( *utext != 0 )
          break;
LABEL_30:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v5 = ellipsesWidth + 1;
          if ( ellipsesWidth + 1 < ((*((_BYTE *)this + 52) & 4) != 0) + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 )
          {
            if ( utext[1] != 38 )
              goto LABEL_27;
            ++utext;
          }
          v11 = ((int (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->GetCharacterWidth)(a1: g_pVGuiSurface);
          v12 = utext == this->_utext;
          v13 = (float)v11;
          v24 = (float)v11;
          v14 = (float)v10;
          if ( v12 )
          {
            check = (int)(float)(v14 + v13);
          }
          else
          {
            len = (float)v10;
            if ( (float)((float)((float)v22 + v14) + v13) > (float)this->_drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v13;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += ((int (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->GetCharacterWidth)(a1: g_pVGuiSurface);
                }
                while ( *v16 != 0 );
                v14 = len;
                v13 = v24;
              }
              if ( check + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = utext;
                goto LABEL_30;
              }
            }
            check = (int)(float)(v14 + v13);
          }
        }
LABEL_27:
        v9 = utext[1];
        ++utext;
        if ( v9 == 0 )
          goto LABEL_30;
        v10 = check;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B23E0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x004B2400
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  this->m_bWrapCenter = bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x004B2410
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x004B2430
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004B2450
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  bool v6; // cc
  __int16 v7; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v9; // ecx
  unsigned __int16 v10; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &firstValue;
  v5 = wcslen(v4);
  v6 = v5 < this->_textBufferLen;
  this->_textLen = v5;
  if ( !v6 )
  {
    free(pMem: this->_utext);
    v7 = this->_textLen + 1;
    this->_textBufferLen = v7;
    this->_utext = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v7 >> 31 != 0 ? -1 : 2 * v7);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v9 = v4;
  do
  {
    v10 = *v9;
    *utext++ = *v9++;
  }
  while ( v10 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x004B24F0
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  this->_textBufferLen = 0;
  this->_textLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B2580
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B25C0
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_LineXIndent; // edi
  wchar_t *utext; // ebx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bp
  float v6; // xmm0_4
  float currentLineBreak; // [esp+10h] [ebp-14h]
  unsigned int font; // [esp+14h] [ebp-10h]
  unsigned int py; // [esp+18h] [ebp-Ch]
  int px; // [esp+1Ch] [ebp-8h] BYREF
  _BYTE v11[4]; // [esp+20h] [ebp-4h] BYREF

  p_m_LineXIndent = &this->m_LineXIndent;
  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    py = this->GetFont(this);
    this->GetPos(this, a2: (int *)v11, a3: &px);
    utext = this->_utext;
    v4 = *utext;
    font = 0;
    currentLineBreak = 0.0;
    if ( *utext != 0 )
    {
      while ( 1 )
      {
        v5 = v4;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v5 = towupper(c: v4);
        if ( v5 != 13 )
        {
          if ( v5 == 10 )
            break;
          if ( v5 != 38 )
            goto LABEL_13;
          if ( utext[1] == 38 )
          {
            ++utext;
LABEL_13:
            if ( font != this->m_LineBreaks.m_Size && utext == this->m_LineBreaks.m_Memory.m_pMemory[font] )
            {
              ++font;
              p_m_LineXIndent->m_Memory.m_pMemory[CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
                                                    this: p_m_LineXIndent,
                                                    elem: p_m_LineXIndent->m_Size)] = (int)(float)((float)((float)this->_drawWidth - currentLineBreak)
                                                                                           * 0.5);
              currentLineBreak = 0.0;
            }
            v6 = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: py, a3: v5) + currentLineBreak;
LABEL_17:
            currentLineBreak = v6;
          }
        }
        v4 = utext[1];
        ++utext;
        if ( v4 == 0 )
          goto LABEL_19;
      }
      v6 = 0.0;
      p_m_LineXIndent->m_Memory.m_pMemory[CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
                                            this: p_m_LineXIndent,
                                            elem: p_m_LineXIndent->m_Size)] = (int)(float)((float)((float)this->_drawWidth
                                                                                           - currentLineBreak)
                                                                                   * 0.5);
      goto LABEL_17;
    }
LABEL_19:
    p_m_LineXIndent->m_Memory.m_pMemory[CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
                                          this: p_m_LineXIndent,
                                          elem: p_m_LineXIndent->m_Size)] = (int)(float)((float)((float)this->_drawWidth
                                                                                         - currentLineBreak)
                                                                                 * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2750
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  this->_textBufferLen = 0;
  this->_textLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B2830
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  wchar_t v4; // cx
  char v5; // bl
  int v6; // edx
  wchar_t *v7; // ebp
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // di
  float v10; // xmm0_4
  int m_Size; // edx
  CUtlVector<wchar_t *,CUtlMemory<wchar_t *,int> > *p_m_LineBreaks; // ecx
  __int16 wordStartIndex_2; // [esp+12h] [ebp-16h]
  vgui::TreeNode *x; // [esp+14h] [ebp-14h] BYREF
  wchar_t *wsz; // [esp+18h] [ebp-10h]
  unsigned int font; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int charWidth; // [esp+20h] [ebp-8h]
  float v18; // [esp+24h] [ebp-4h]

  charWidth = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  x = (vgui::TreeNode *)utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  v6 = 0;
  *(float *)&wsz = 0.0;
  wordStartIndex_2 = 257;
  if ( v4 == 13 || v4 == 10 )
    v6 = 1;
  v7 = &v3[v6];
  v8 = *v7;
  for ( font = (unsigned int)v7; v8 != 0; font = (unsigned int)v7 )
  {
    v9 = v8;
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
      v9 = towupper(c: v8);
    if ( iswspace(c: v9) != 0 )
    {
      v5 = 0;
    }
    else if ( v5 == 0 )
    {
      x = (vgui::TreeNode *)v7;
      v5 = 1;
      HIBYTE(wordStartIndex_2) = wordStartIndex_2;
    }
    v18 = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: charWidth, a3: v9);
    if ( iswcntrl(c: v9) == 0 )
      LOBYTE(wordStartIndex_2) = 0;
    v10 = v18 + *(float *)&wsz;
    if ( (float)(v18 + *(float *)&wsz) > (float)this->_drawWidth || v9 == 13 || v9 == 10 )
    {
      v5 = 0;
      LOBYTE(wordStartIndex_2) = 1;
      if ( v9 != 13 && v9 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        p_m_LineBreaks = &this->m_LineBreaks;
        if ( HIBYTE(wordStartIndex_2) != 0 )
        {
          CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
            this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)p_m_LineBreaks,
            elem: m_Size,
            src: (vgui::TreeNode **)&font);
        }
        else
        {
          CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
            this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)p_m_LineBreaks,
            elem: m_Size,
            src: &x);
          v7 = (wchar_t *)((char *)&x[-1] + 406);
        }
      }
      v10 = 0.0;
    }
    v8 = v7[1];
    ++v7;
    *(float *)&wsz = v10;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B29A0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  bool v9; // zf
  wchar_t *utext; // ecx
  unsigned __int16 v11; // ax
  int v12; // ebp
  unsigned __int16 v13; // ax
  int v14; // eax
  int v15; // eax
  int i; // esi
  wchar_t *wsz; // [esp+34h] [ebp-28h]
  int iIndent; // [esp+38h] [ebp-24h]
  int py; // [esp+3Ch] [ebp-20h]
  int px; // [esp+40h] [ebp-1Ch] BYREF
  int lineHeight; // [esp+44h] [ebp-18h] BYREF
  int currentLineBreak; // [esp+48h] [ebp-14h]
  unsigned int font; // [esp+4Ch] [ebp-10h]
  int tall; // [esp+50h] [ebp-Ch] BYREF
  int wide; // [esp+54h] [ebp-8h] BYREF
  _BYTE v26[4]; // [esp+58h] [ebp-4h] BYREF

  this->GetSize(this, a2: (int *)v26, a3: &wide);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2, a3: (int)this);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &tall);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    tall = v6;
    DrawSetTextFont(this, a2: v6);
    currentLineBreak = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    v8 = 0;
    wsz = nullptr;
    py = 0;
    this->GetPos(this, a2: &lineHeight, a3: &px);
    v9 = this->m_LineXIndent.m_Size == 0;
    font = 0;
    if ( !v9 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v11 = *utext;
    iIndent = (int)utext;
    if ( *utext != 0 )
    {
      while ( 1 )
      {
        v12 = v11;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
        {
          v13 = towupper(c: v11);
          utext = (wchar_t *)iIndent;
          v12 = v13;
        }
        if ( (_WORD)v12 == 13 )
          goto LABEL_32;
        if ( (_WORD)v12 == 10 )
        {
          v14 = ++py;
          if ( py >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v14];
          wsz = (wchar_t *)((char *)wsz + currentLineBreak);
          goto LABEL_32;
        }
        if ( (_WORD)v12 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + lineHeight, a3: (int)wsz + px);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
LABEL_31:
        utext = (wchar_t *)iIndent;
LABEL_32:
        v11 = utext[1];
        iIndent = (int)++utext;
        if ( v11 == 0 )
          return;
      }
      iIndent = (int)++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( i = 3; i != 0; --i )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + lineHeight, a3: (int)wsz + px);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( font != this->m_LineBreaks.m_Size && utext == this->m_LineBreaks.m_Memory.m_pMemory[font] )
      {
        v15 = ++py;
        if ( py >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v15];
        wsz = (wchar_t *)((char *)wsz + currentLineBreak);
        ++font;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + lineHeight, a3: (int)wsz + px);
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v12, a3: FONT_DRAW_DEFAULT);
      v6 = tall;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: tall, a3: (unsigned __int16)v12);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2C40
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  vgui::ISurface *v5; // ebx
  int (__thiscall **p_GetFontTall)(vgui::ISurface *, unsigned int); // esi
  unsigned int v7; // eax
  int v8; // eax
  unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int text; // [esp+18h] [ebp-18h]
  wchar_t *font; // [esp+1Ch] [ebp-14h]
  unsigned int fonta; // [esp+1Ch] [ebp-14h]
  int b; // [esp+20h] [ebp-10h]
  int a; // [esp+24h] [ebp-Ch] BYREF
  int c; // [esp+28h] [ebp-8h] BYREF
  int v21; // [esp+2Ch] [ebp-4h] BYREF
  int maxWide; // [esp+34h] [ebp+4h]
  wchar_t *talla; // [esp+38h] [ebp+8h]

  *wide = 0;
  *tall = 0;
  maxWide = 0;
  font = this->_utext;
  b = this->_font;
  if ( b != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v5 = g_pVGuiSurface;
    p_GetFontTall = &g_pVGuiSurface->GetFontTall;
    v7 = this->GetFont(this);
    v8 = (*p_GetFontTall)(this: v5, a2: v7);
    v10 = font;
    text = v8;
    *tall = v8;
    v11 = wcslen(font);
    if ( v11 > 0 )
    {
      talla = font;
      fonta = v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || talla[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: b, a3: v12, a4: &c, a5: &a, a6: &v21);
          *wide += v21 + a + c;
          if ( v12 == 10 )
          {
            *tall += text;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( talla == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += text;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = talla + 1;
        v14 = fonta-- == 1;
        ++talla;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00466460
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00466500
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x00466520
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466570
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004665C0
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466610
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x00466620
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x00466640
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 8) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x00466650
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x00466680
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00466690
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x004666C0
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 2) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && !this->m_bWrapCenter && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 4) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 8u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 4) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004668B0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x004668D0
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  this->m_bWrapCenter = bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x004668E0
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (4 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00466900
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (16 * bAllCaps)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00466920
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_489260;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x004669C0
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00466A50
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x00466A90
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( this->m_bWrapCenter && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_18;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 )
          goto LABEL_13;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_13:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_17:
          iCurLineW = v6;
        }
LABEL_18:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_19;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_17;
    }
LABEL_19:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: &v13[m_Size + 1], src: &v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466C50
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= ~2u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->m_bWrapCenter = false;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) &= 0xE3u;
  this->m_pwszEllipsesPosition = nullptr;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00466D30
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edx
  unsigned __int16 i; // ax
  unsigned __int16 v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // eax
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+21h] [ebp-3h]
  bool justStartedNewLine; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  for ( i = *wsz; *wsz != 0; x = v8 )
  {
    v7 = i;
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
      v7 = towupper(c: i);
    if ( iswspace(c: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: &v15[m_Size + 1], src: &v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    i = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x00466F20
// Name: public: void vgui::TextImage::ResizeImageToContentMaxWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::TextImage::ResizeImageToContentMaxWidth(
        vgui::TextImage *this@<ecx>,
        int a2@<edi>,
        int nMaxWidth)
{
  char v4; // al
  int v5; // [esp+4h] [ebp-4h] BYREF

  this->_drawWidth = nMaxWidth;
  v4 = *((_BYTE *)this + 52);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    vgui::TextImage::RecalculateEllipsesPosition(this, a2);
  }
  this->GetContentSize(this, a2: &v5, a3: &nMaxWidth);
  this->SetSize(this, a2: v5, a3: nMaxWidth);
}

//------------------------------------------------------------------------------
// Address: 0x00466F80
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 2) != 0 || this->m_bWrapCenter )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x10) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004671F0
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int i; // ecx
  bool v14; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v19; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v19 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v19, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v19 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          *wide += c + b + a;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 2) != 0 || this->m_bWrapCenter )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = 0;
              }
            }
          }
        }
        v10 = text + 1;
        v14 = v19 == (vgui::ISurface *)1;
        v19 = (vgui::ISurface *)((char *)v19 - 1);
        ++text;
      }
      while ( !v14 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00466EE0
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = defaultValue;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00466FA0
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466FF0
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467040
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467090
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x004670A0
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x004670C0
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x004670D0
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x00467100
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00467110
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00467140
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467330
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004673C0
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x004673E0
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x00467410
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x00467430
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x00467450
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x00467470
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_48D270;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x00467510
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004675A0
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x004675E0
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004677B0
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00467890
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x00467AB0
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467D20
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039F750
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D4B50
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = prType;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103D4BF0
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x103D4C10
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D4C60
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D4CB0
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D4D00
// Name: public: virtual unsigned int vgui::TextImage::GetUnlocalizedTextSymbol(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetUnlocalizedTextSymbol(vgui::TextImage *this)
{
  return this->_unlocalizedTextSymbol;
}

//------------------------------------------------------------------------------
// Address: 0x103D4D10
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x103D4D30
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x103D4D40
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x103D4D70
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103D4D80
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103D4DB0
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D4FA0
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage_0
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage_0 = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage_0 << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage_0 = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D5030
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D5050
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D5080
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x103D50A0
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x103D50C0
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x103D50E0
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &szFunFact;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    C_BaseEntity::operator delete(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v6 >> 31 != 0 ? -1 : 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x103D5180
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103D5210
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  C_BaseEntity::operator delete(pMem: utext);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D5250
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D5420
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103D5500
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D5720
// Name: public: void vgui::TextImage::ResizeImageToContentMaxWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::TextImage::ResizeImageToContentMaxWidth(
        vgui::TextImage *this@<ecx>,
        int a2@<edi>,
        int nMaxWidth)
{
  char v4; // al
  int v5; // [esp+4h] [ebp-4h] BYREF

  this->_drawWidth = nMaxWidth;
  v4 = *((_BYTE *)this + 52);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    vgui::TextImage::RecalculateEllipsesPosition(this, a2);
  }
  this->GetContentSize(this, a2: &v5, a3: &nMaxWidth);
  this->SetSize(this, a2: v5, a3: nMaxWidth);
}

//------------------------------------------------------------------------------
// Address: 0x103D5770
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D59E0
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103CA540
// Name: public: virtual void vgui::TextImage::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const char *text)
{
  const char *v2; // edi
  unsigned int v4; // eax
  const wchar_t *v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = text;
  if ( text == nullptr )
  {
    v2 = locale;
LABEL_3:
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: unicode, a4: 2048);
    this->SetText(this, a2: unicode, a3: false);
    return;
  }
  if ( *text != 35 )
    goto LABEL_3;
  v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
  this->_unlocalizedTextSymbol = v4;
  if ( v4 == -1 )
    goto LABEL_3;
  v5 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  this->SetText(this, a2: v5, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103CA5E0
// Name: public: void vgui::TextImage::SetDrawWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetDrawWidth(vgui::TextImage *this, int width)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = width;
}

//------------------------------------------------------------------------------
// Address: 0x103CA600
// Name: public: virtual void vgui::TextImage::GetText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  signed int i; // esi
  char v5; // al

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: this->_utext, a3: buffer, a4: bufferSize);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_strlen(str: buffer); i >= 0; buffer[i + 1] = v5 )
      v5 = toupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA650
// Name: public: virtual void vgui::TextImage::GetText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetText(vgui::TextImage *this, wchar_t *buffer, unsigned int bufLenInBytes)
{
  signed int i; // esi
  wchar_t v5; // ax

  wcsncpy(dest: buffer, source: this->_utext, count: bufLenInBytes >> 1);
  if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
  {
    for ( i = _V_wcslen(pwch: buffer) - 1; i >= 0; buffer[i + 1] = v5 )
      v5 = towupper(c: buffer[i--]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA6A0
// Name: public: virtual void vgui::TextImage::GetUnlocalizedText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetUnlocalizedText(vgui::TextImage *this, char *buffer, int bufferSize)
{
  unsigned int unlocalizedTextSymbol; // eax
  char *v4; // eax

  unlocalizedTextSymbol = this->_unlocalizedTextSymbol;
  if ( unlocalizedTextSymbol == -1 )
  {
    this->GetText_2(this, a2: buffer, a3: bufferSize);
  }
  else
  {
    v4 = (char *)g_pVGuiLocalize->GetNameByIndex(this: g_pVGuiLocalize, a2: unlocalizedTextSymbol);
    *buffer = 35;
    V_strncpy(pDest: buffer + 1, pSrc: v4, maxLen: bufferSize - 1);
    buffer[bufferSize - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA700
// Name: public: virtual void vgui::TextImage::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetFont(vgui::TextImage *this, unsigned int font)
{
  *((_BYTE *)this + 52) |= 1u;
  this->_font = font;
}

//------------------------------------------------------------------------------
// Address: 0x103CA720
// Name: public: virtual unsigned long vgui::TextImage::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextImage::GetFont(vgui::TextImage *this)
{
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    return this->_fallbackFont;
  else
    return this->_font;
}

//------------------------------------------------------------------------------
// Address: 0x103CA730
// Name: public: virtual void vgui::TextImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetSize(vgui::TextImage *this, int wide, int tall)
{
  vgui::Image::SetSize(this, wide, tall);
  *((_BYTE *)this + 52) |= 1u;
  this->_drawWidth = wide;
}

//------------------------------------------------------------------------------
// Address: 0x103CA760
// Name: public: virtual void vgui::TextImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetContentSize(vgui::TextImage *this, int *wide, int *tall)
{
  this->GetTextSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103CA770
// Name: public: void vgui::TextImage::ResizeImageToContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::ResizeImageToContent(vgui::TextImage *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  this->SetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103CA7A0
// Name: private: void vgui::TextImage::RecalculateEllipsesPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::RecalculateEllipsesPosition(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  int v3; // esi
  bool v4; // zf
  BOOL v5; // eax
  unsigned int fallbackFont; // eax
  int v7; // eax
  wchar_t *utext; // esi
  unsigned __int16 v9; // ax
  int v10; // edi
  int v11; // eax
  float v12; // xmm1_4
  int v13; // xmm0_4
  float drawWidth; // xmm3_4
  wchar_t v15; // ax
  wchar_t *v16; // esi
  int v17; // edi
  BOOL v18; // eax
  int h; // [esp+8h] [ebp-18h] BYREF
  int ellipsesWidth; // [esp+Ch] [ebp-14h]
  int check; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  unsigned int font; // [esp+18h] [ebp-8h]
  wchar_t *wsz; // [esp+1Ch] [ebp-4h]

  *((_BYTE *)this + 52) &= ~1u;
  v3 = 0;
  v4 = (*((_BYTE *)this + 52) & 6) == 0;
  this->m_pwszEllipsesPosition = nullptr;
  if ( v4 && wcschr(string: this->_utext, ch: 0xAu) == nullptr )
  {
    if ( this->_drawWidth == 0 )
      this->GetSize(this, a2: &this->_drawWidth, a3: &h);
    v5 = (*((_BYTE *)this + 52) & 8) != 0;
    check = 0;
    if ( v5 + 1 > 0 )
    {
      while ( 1 )
      {
        font = ((int (__thiscall *)(vgui::TextImage *, int))this->GetFont)(a1: this, a2);
        if ( v3 == 1 )
        {
          fallbackFont = this->_fallbackFont;
          if ( fallbackFont != 0 )
          {
            *((_BYTE *)this + 52) |= 0x10u;
            this->m_pwszEllipsesPosition = nullptr;
            font = fallbackFont;
          }
        }
        a2 = 46;
        v7 = ((int (__thiscall *)(vgui::ISurface *, unsigned int))g_pVGuiSurface->GetCharacterWidth)(
               a1: g_pVGuiSurface,
               a2: font);
        utext = this->_utext;
        ellipsesWidth = 3 * v7;
        v9 = *utext;
        v10 = 0;
        x = 0;
        wsz = utext;
        if ( v9 != 0 )
          break;
LABEL_31:
        if ( this->m_pwszEllipsesPosition != nullptr )
        {
          v3 = check + 1;
          v18 = (*((_BYTE *)this + 52) & 8) != 0;
          check = v3;
          if ( v3 < v18 + 1 )
            continue;
        }
        return;
      }
      while ( 1 )
      {
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v9 = towupper(c: v9);
        if ( v9 != 13 )
        {
          if ( v9 == 38 && (*((_BYTE *)this + 52) & 0x40) == 0 )
          {
            if ( utext[1] != 38 )
              goto LABEL_28;
            wsz = ++utext;
          }
          v11 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v9);
          v12 = (float)v11;
          *(float *)&v13 = (float)v10 + (float)v11;
          if ( utext == this->_utext )
          {
            x = (int)*(float *)&v13;
          }
          else
          {
            drawWidth = (float)this->_drawWidth;
            *(float *)&h = (float)v10 + (float)v11;
            if ( (float)((float)ellipsesWidth + *(float *)&v13) > drawWidth )
            {
              v15 = utext[1];
              v16 = utext + 1;
              v17 = (int)v12;
              if ( v15 != 0 )
              {
                do
                {
                  ++v16;
                  v17 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
                  v15 = *v16;
                }
                while ( *v16 != 0 );
                v13 = h;
              }
              if ( x + v17 > this->_drawWidth )
              {
                this->m_pwszEllipsesPosition = wsz;
                goto LABEL_31;
              }
              utext = wsz;
            }
            x = (int)*(float *)&v13;
          }
        }
LABEL_28:
        v9 = utext[1];
        wsz = ++utext;
        if ( v9 == 0 )
          goto LABEL_31;
        v10 = x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA990
// Name: private: void vgui::TextImage::SetUseAsianWordWrapping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseAsianWordWrapping(vgui::TextImage *this)
{
  const char *(__thiscall *GetLanguage)(vgui::ISchemeManager *); // edx
  const char *v3; // eax
  const char *v4; // esi
  char v5; // cl

  if ( bCheckForAsianLanguage
    || (GetLanguage = g_pVGuiSchemeManager->GetLanguage,
        bCheckForAsianLanguage = true,
        v3 = GetLanguage(this: g_pVGuiSchemeManager),
        v4 = v3,
        v3 == nullptr)
    || _V_stricmp(s1: v3, s2: "japanese") != 0
    && _V_stricmp(s1: v4, s2: "schinese") != 0
    && _V_stricmp(s1: v4, s2: "tchinese") != 0 )
  {
    *((_BYTE *)this + 52) = (bIsAsianLanguage << 7) | *((_BYTE *)this + 52) & 0x7F;
  }
  else
  {
    v5 = *((_BYTE *)this + 52);
    bIsAsianLanguage = true;
    *((_BYTE *)this + 52) = v5 & 0x7F | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CAA20
// Name: public: void vgui::TextImage::SetWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (2 * bWrap)) & 2;
  if ( (*((_BYTE *)this + 52) & 2) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CAA40
// Name: public: void vgui::TextImage::SetCenterWrap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetCenterWrap(vgui::TextImage *this, bool bWrap)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (4 * bWrap)) & 4;
  if ( (*((_BYTE *)this + 52) & 4) != 0 )
    vgui::TextImage::SetUseAsianWordWrapping(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CAA70
// Name: public: void vgui::TextImage::SetNoShortcutSyntax(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetNoShortcutSyntax(vgui::TextImage *this, bool bNoShortcutSyntax)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (bNoShortcutSyntax << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x103CAA90
// Name: public: void vgui::TextImage::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetUseFallbackFont(vgui::TextImage *this, bool bState, unsigned int hFallback)
{
  char v3; // al

  v3 = *((_BYTE *)this + 52) ^ (8 * bState);
  this->_fallbackFont = hFallback;
  *((_BYTE *)this + 52) ^= v3 & 8;
}

//------------------------------------------------------------------------------
// Address: 0x103CAAB0
// Name: public: void vgui::TextImage::SetAllCaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetAllCaps(vgui::TextImage *this, bool bAllCaps)
{
  *((_BYTE *)this + 52) ^= (*((_BYTE *)this + 52) ^ (32 * bAllCaps)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x103CAAD0
// Name: public: virtual void vgui::TextImage::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::SetText(vgui::TextImage *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // edi
  __int16 v5; // ax
  __int16 v6; // ax
  wchar_t *utext; // edx
  const unsigned __int16 *v8; // ecx
  unsigned __int16 v9; // ax

  if ( bClearUnlocalizedSymbol )
    this->_unlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &word_1050BF20;
  v5 = wcslen(v4);
  this->_textLen = v5;
  if ( v5 >= this->_textBufferLen )
  {
    free(pMem: this->_utext);
    v6 = this->_textLen + 1;
    this->_textBufferLen = v6;
    this->_utext = (wchar_t *)operator new(nSize: 2 * v6);
  }
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  utext = this->_utext;
  v8 = v4;
  do
  {
    v9 = *v8;
    *utext++ = *v8++;
  }
  while ( v9 != 0 );
  *((_BYTE *)this + 52) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x103CAB70
// Name: public: vgui::TextImage::TextImage(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const wchar_t *wszText)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_unlocalizedTextSymbol = -1;
  this->_drawWidth = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, unicode: wszText, bClearUnlocalizedSymbol: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CAC00
// Name: public: virtual vgui::TextImage::~TextImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::~TextImage(vgui::TextImage *this)
{
  wchar_t *utext; // [esp-4h] [ebp-8h]

  utext = this->_utext;
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  free(pMem: utext);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ColorChangeStream);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineXIndent);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LineBreaks);
  vgui::Image::~Image(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CAC40
// Name: public: void vgui::TextImage::RecalculateCenterWrapIndents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateCenterWrapIndents(vgui::TextImage *this)
{
  wchar_t *utext; // ebx
  unsigned __int16 v3; // ax
  bool v4; // zf
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  __m128i v8; // xmm0
  int *m_pMemory; // edx
  int v10; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int px; // [esp+Ch] [ebp-18h] BYREF
  int py; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int currentLineBreak; // [esp+1Ch] [ebp-8h]
  float iCurLineW; // [esp+20h] [ebp-4h]

  this->m_LineXIndent.m_Size = 0;
  if ( (*((_BYTE *)this + 52) & 4) != 0 && this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    font = this->GetFont(this);
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    utext = this->_utext;
    v3 = *utext;
    iCurLineW = 0.0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v4 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v18 = v3;
        if ( !v4 )
        {
          v3 = towupper(c: v3);
          v18 = v3;
        }
        if ( v3 == 13 )
          goto LABEL_19;
        if ( v3 == 10 )
          break;
        if ( v3 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_14;
        if ( utext[1] == 38 )
        {
          ++utext;
LABEL_14:
          if ( currentLineBreak != this->m_LineBreaks.m_Size
            && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
          {
            v7 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
            v8 = _mm_cvtsi32_si128(this->_drawWidth);
            m_pMemory = this->m_LineXIndent.m_Memory.m_pMemory;
            ++currentLineBreak;
            m_pMemory[v7] = (int)(float)((float)(_mm_cvtepi32_ps(v8).m128_f32[0] - iCurLineW) * 0.5);
            v3 = v18;
            iCurLineW = 0.0;
          }
          v10 = g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v3);
          v6 = (float)v10 + iCurLineW;
LABEL_18:
          iCurLineW = v6;
        }
LABEL_19:
        v3 = utext[1];
        ++utext;
        if ( v3 == 0 )
          goto LABEL_20;
      }
      v5 = CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: &this->m_LineXIndent);
      v6 = 0.0;
      this->m_LineXIndent.m_Memory.m_pMemory[v5] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
      goto LABEL_18;
    }
LABEL_20:
    m_Size = this->m_LineXIndent.m_Size;
    m_nAllocationCount = this->m_LineXIndent.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineXIndent,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_LineXIndent.m_Size;
    v13 = this->m_LineXIndent.m_Memory.m_pMemory;
    v14 = this->m_LineXIndent.m_Size - m_Size - 1;
    this->m_LineXIndent.m_pElements = v13;
    if ( v14 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 4 * v14);
    this->m_LineXIndent.m_Memory.m_pMemory[m_Size] = (int)(float)((float)((float)this->_drawWidth - iCurLineW) * 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CAE10
// Name: public: vgui::TextImage::TextImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TextImage *__thiscall vgui::TextImage::TextImage(vgui::TextImage *this, const char *text)
{
  vgui::Image::Image(this);
  this->__vftable = (vgui::TextImage_vtbl *)&vgui::TextImage::`vftable';
  this->m_LineBreaks.m_Memory.m_pMemory = nullptr;
  this->m_LineBreaks.m_Memory.m_nAllocationCount = 0;
  this->m_LineBreaks.m_Memory.m_nGrowSize = 0;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineBreaks.m_pElements = nullptr;
  this->m_LineXIndent.m_Memory.m_pMemory = nullptr;
  this->m_LineXIndent.m_Memory.m_nAllocationCount = 0;
  this->m_LineXIndent.m_Memory.m_nGrowSize = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_LineXIndent.m_pElements = nullptr;
  this->m_ColorChangeStream.m_Memory.m_pMemory = nullptr;
  this->m_ColorChangeStream.m_Memory.m_nAllocationCount = 0;
  this->m_ColorChangeStream.m_Memory.m_nGrowSize = 0;
  this->m_ColorChangeStream.m_Size = 0;
  this->m_ColorChangeStream.m_pElements = nullptr;
  this->m_ColorChangeStream.m_pLessContext = nullptr;
  this->m_ColorChangeStream.m_bNeedsSort = false;
  *((_BYTE *)this + 52) &= 0xB9u;
  this->_utext = nullptr;
  this->_font = 0;
  this->_fallbackFont = 0;
  this->_drawWidth = 0;
  *(_DWORD *)&this->_textBufferLen = 0;
  this->_unlocalizedTextSymbol = -1;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  this->m_pwszEllipsesPosition = nullptr;
  *((_BYTE *)this + 52) = *((_BYTE *)this + 52) & 0x46 | 1;
  vgui::TextImage::SetText(this, text);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CAEF0
// Name: public: void vgui::TextImage::RecalculateNewLinePositions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::RecalculateNewLinePositions(vgui::TextImage *this)
{
  wchar_t *utext; // eax
  wchar_t *v3; // eax
  int v4; // ecx
  int v5; // edi
  unsigned __int16 v6; // ax
  wchar_t v7; // di
  float v8; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v11; // ecx
  wchar_t **m_pMemory; // ecx
  int v13; // eax
  wchar_t **v14; // edi
  wchar_t **v15; // ecx
  int v16; // eax
  wchar_t **v17; // edi
  float charWidth; // [esp+Ch] [ebp-18h]
  unsigned int font; // [esp+10h] [ebp-14h]
  float x; // [esp+14h] [ebp-10h]
  wchar_t *wordStartIndex; // [esp+18h] [ebp-Ch]
  wchar_t *wsz; // [esp+1Ch] [ebp-8h]
  bool wordStartedOnNewLine; // [esp+20h] [ebp-4h]
  bool justStartedNewLine; // [esp+21h] [ebp-3h]
  char bStartAsianWordHere; // [esp+22h] [ebp-2h]
  bool hasWord; // [esp+23h] [ebp-1h]

  font = this->GetFont(this);
  utext = this->_utext;
  this->m_LineBreaks.m_Size = 0;
  this->m_LineXIndent.m_Size = 0;
  wordStartIndex = utext;
  v3 = this->_utext;
  v4 = *v3;
  v5 = 0;
  x = 0.0;
  hasWord = false;
  justStartedNewLine = true;
  wordStartedOnNewLine = true;
  if ( v4 == 13 || v4 == 10 )
    v5 = 1;
  wsz = &v3[v5];
  v6 = *wsz;
  for ( bStartAsianWordHere = *((_BYTE *)this + 52) >> 7; *wsz != 0; x = v8 )
  {
    v7 = v6;
    if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
      v7 = towupper(c: v6);
    if ( isbreakablewspace(ch: v7) != 0 )
    {
      hasWord = false;
    }
    else if ( !hasWord || bStartAsianWordHere != 0 )
    {
      wordStartIndex = wsz;
      hasWord = true;
      wordStartedOnNewLine = justStartedNewLine;
    }
    if ( *((char *)this + 52) >= 0 || (bStartAsianWordHere = 1, !AsianWordWrap::CanBreakAfter(wsz)) )
      bStartAsianWordHere = 0;
    charWidth = (float)g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v7);
    if ( iswcntrl(c: v7) == 0 )
      justStartedNewLine = false;
    v8 = charWidth + x;
    if ( (float)(charWidth + x) > (float)this->_drawWidth || v7 == 13 || v7 == 10 )
    {
      justStartedNewLine = true;
      hasWord = false;
      if ( v7 != 13 && v7 != 10 )
      {
        m_Size = this->m_LineBreaks.m_Size;
        m_nAllocationCount = this->m_LineBreaks.m_Memory.m_nAllocationCount;
        v11 = m_Size + 1;
        if ( wordStartedOnNewLine )
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          m_pMemory = this->m_LineBreaks.m_Memory.m_pMemory;
          v13 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v13);
          v14 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = wsz;
        }
        else
        {
          if ( v11 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LineBreaks,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_LineBreaks.m_Size;
          v15 = this->m_LineBreaks.m_Memory.m_pMemory;
          v16 = this->m_LineBreaks.m_Size - m_Size - 1;
          this->m_LineBreaks.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v15[m_Size + 1], src: (unsigned __int8 *)&v15[m_Size], count: 4 * v16);
          v17 = &this->m_LineBreaks.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = wordStartIndex;
          wsz = wordStartIndex - 1;
        }
      }
      v8 = 0.0;
    }
    v6 = *++wsz;
  }
  vgui::TextImage::RecalculateCenterWrapIndents(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CB110
// Name: public: virtual void vgui::TextImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::TextImage::Paint(vgui::TextImage *this@<ecx>, int a2@<edi>)
{
  char v3; // al
  vgui::TextImage_vtbl *v4; // edi
  Color *v5; // eax
  unsigned int v6; // ebx
  void (__thiscall *DrawSetTextFont)(struct vgui::TextImage *, unsigned int); // edx
  int v8; // edi
  wchar_t *utext; // ecx
  unsigned __int16 v10; // ax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  unsigned __int16 v14; // bx
  int v15; // edx
  int wide; // [esp+4h] [ebp-2Ch] BYREF
  int tall; // [esp+8h] [ebp-28h] BYREF
  unsigned int font; // [esp+Ch] [ebp-24h] BYREF
  int v19; // [esp+10h] [ebp-20h]
  int currentLineBreak; // [esp+14h] [ebp-1Ch]
  int lineHeight; // [esp+18h] [ebp-18h]
  int px; // [esp+1Ch] [ebp-14h] BYREF
  int py; // [esp+20h] [ebp-10h] BYREF
  int iIndent; // [esp+24h] [ebp-Ch]
  wchar_t *wsz; // [esp+28h] [ebp-8h]
  int y; // [esp+2Ch] [ebp-4h]

  this->GetSize(this, a2: &wide, a3: &tall);
  if ( this->_utext != nullptr && this->GetFont(this) != 0 )
  {
    v3 = *((_BYTE *)this + 52);
    if ( (v3 & 1) != 0 )
    {
      if ( (v3 & 6) != 0 )
        vgui::TextImage::RecalculateNewLinePositions(this);
      vgui::TextImage::RecalculateEllipsesPosition(this, a2);
    }
    v4 = this->__vftable;
    v5 = this->GetColor(this, result: &font);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
    v6 = this->GetFont(this);
    DrawSetTextFont = this->DrawSetTextFont;
    font = v6;
    DrawSetTextFont(this, a2: v6);
    lineHeight = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6);
    y = 0;
    iIndent = 0;
    v8 = 0;
    this->GetPos(this, a2: &px, a3: &py);
    currentLineBreak = 0;
    if ( this->m_LineXIndent.m_Size != 0 )
      v8 = *this->m_LineXIndent.m_Memory.m_pMemory;
    utext = this->_utext;
    v10 = *utext;
    wsz = utext;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v11 = (*((_BYTE *)this + 52) & 0x20) == 0;
        v19 = v10;
        if ( !v11 )
        {
          v10 = towupper(c: v10);
          utext = wsz;
          v19 = v10;
        }
        if ( v10 == 13 )
          goto LABEL_32;
        if ( v10 == 10 )
        {
          v12 = iIndent + 1;
          iIndent = v12;
          if ( v12 >= this->m_LineXIndent.m_Size )
            v8 = 0;
          else
            v8 = this->m_LineXIndent.m_Memory.m_pMemory[v12];
          y += lineHeight;
          goto LABEL_32;
        }
        if ( v10 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 )
          goto LABEL_22;
        if ( utext[1] == 38 )
          break;
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 95, a3: FONT_DRAW_DEFAULT);
        v6 = font;
LABEL_31:
        utext = wsz;
LABEL_32:
        v10 = utext[1];
        wsz = ++utext;
        if ( v10 == 0 )
          return;
      }
      wsz = ++utext;
LABEL_22:
      if ( utext == this->m_pwszEllipsesPosition )
      {
        for ( font = 3; font != 0; --font )
        {
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
          g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: 46, a3: FONT_DRAW_DEFAULT);
          v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: v6, a3: 46);
        }
        return;
      }
      if ( currentLineBreak != this->m_LineBreaks.m_Size
        && utext == this->m_LineBreaks.m_Memory.m_pMemory[currentLineBreak] )
      {
        v13 = iIndent + 1;
        iIndent = v13;
        if ( v13 >= this->m_LineXIndent.m_Size )
          v8 = 0;
        else
          v8 = this->m_LineXIndent.m_Memory.m_pMemory[v13];
        y += lineHeight;
        ++currentLineBreak;
      }
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v8 + px, a3: y + py);
      v14 = v19;
      g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: v19, a3: FONT_DRAW_DEFAULT);
      v15 = v14;
      v6 = font;
      v8 += g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: font, a3: v15);
      goto LABEL_31;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CB380
// Name: protected: virtual void vgui::TextImage::GetTextSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextImage::GetTextSize(vgui::TextImage *this, int *wide, int *tall)
{
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  const unsigned __int16 *v10; // esi
  int v11; // eax
  unsigned __int16 v12; // si
  int v13; // ecx
  int i; // edx
  bool v15; // zf
  int c; // [esp+8h] [ebp-1Ch] BYREF
  int a; // [esp+Ch] [ebp-18h] BYREF
  int b; // [esp+10h] [ebp-14h] BYREF
  unsigned int font; // [esp+14h] [ebp-10h]
  vgui::ISurface *v20; // [esp+18h] [ebp-Ch]
  int fontHeight; // [esp+1Ch] [ebp-8h]
  const wchar_t *text; // [esp+20h] [ebp-4h]
  int maxWide; // [esp+2Ch] [ebp+8h]

  *wide = 0;
  *tall = 0;
  v5 = this->_font;
  maxWide = 0;
  text = this->_utext;
  font = v5;
  if ( v5 != 0 )
  {
    if ( (*((_BYTE *)this + 52) & 6) != 0 )
      vgui::TextImage::RecalculateNewLinePositions(this);
    v6 = this->__vftable;
    v7 = g_pVGuiSurface->__vftable;
    v20 = g_pVGuiSurface;
    v8 = v6->GetFont(this);
    v9 = v7->GetFontTall(this: v20, a2: v8);
    v10 = text;
    fontHeight = v9;
    *tall = v9;
    v11 = wcslen(v10);
    if ( v11 > 0 )
    {
      text = v10;
      v20 = (vgui::ISurface *)v11;
      do
      {
        v12 = *v10;
        if ( (*((_BYTE *)this + 52) & 0x20) != 0 )
          v12 = towupper(c: v12);
        if ( v12 != 38 || (*((_BYTE *)this + 52) & 0x40) != 0 || text[1] == 0 )
        {
          g_pVGuiSurface->GetCharABCwide(this: g_pVGuiSurface, a2: font, a3: v12, a4: &a, a5: &b, a6: &c);
          v13 = c + a + b;
          *wide += v13;
          if ( v12 == 10 )
          {
            *tall += fontHeight;
            if ( *wide > maxWide )
              maxWide = *wide;
            *wide = 0;
          }
          if ( (*((_BYTE *)this + 52) & 6) != 0 )
          {
            for ( i = 0; i < this->m_LineBreaks.m_Size; ++i )
            {
              if ( text == this->m_LineBreaks.m_Memory.m_pMemory[i] )
              {
                *tall += fontHeight;
                if ( *wide > maxWide )
                  maxWide = *wide;
                *wide = v13;
              }
            }
          }
        }
        v10 = text + 1;
        v15 = v20 == (vgui::ISurface *)1;
        v20 = (vgui::ISurface *)((char *)v20 - 1);
        ++text;
      }
      while ( !v15 );
    }
    if ( *wide < maxWide )
      *wide = maxWide;
  }
}

} // namespace server
