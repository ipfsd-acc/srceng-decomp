// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_surfacelib/bitmapfont.cpp
// Functions: 6
// ============================================================

#include "vgui2\vgui_surfacelib\bitmapfont.h"

//------------------------------------------------------------------------------
// Address: 0x10022810
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    free(pMem: this->m_Names.m_Memory.m_pMemory[i]);
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022890
// Name: struct datamap_t __near * DataMapInit<struct BitmapGlyph_s>(struct BitmapGlyph_s __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<BitmapGlyph_s>()
{
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    nameHolder.m_pszBase = "BitmapGlyph_t";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = 13;
    atexit(func: DataMapInit_BitmapGlyph_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  BitmapGlyph_s::m_DataMap.baseMap = nullptr;
  BitmapGlyph_s::m_DataMap.dataNumFields = 7;
  BitmapGlyph_s::m_DataMap.dataDesc = &dataDesc[1];
  return &BitmapGlyph_s::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10022910
// Name: struct datamap_t __near * DataMapInit<struct BitmapFont_s>(struct BitmapFont_s __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<BitmapFont_s>()
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    nameHolder_0.m_pszBase = "BitmapFont_t";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = 12;
    atexit(func: DataMapInit_BitmapFont_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  BitmapFont_s::m_DataMap.baseMap = nullptr;
  BitmapFont_s::m_DataMap.dataNumFields = 10;
  BitmapFont_s::m_DataMap.dataDesc = &dataDesc_0[1];
  return &BitmapFont_s::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1003B330
// Name: BitmapGlyph_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *BitmapGlyph_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<BitmapGlyph_s>();
  BitmapGlyph_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B340
// Name: BitmapFont_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *BitmapFont_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<BitmapFont_s>();
  BitmapFont_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B350
// Name: _dynamic_initializer_for__vtMissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vtMissing__()
{
  return atexit(func: dynamic_atexit_destructor_for__vtMissing__);
}

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100182B0
// Name: public: CBitmapFont::~CBitmapFont(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::~CBitmapFont(CBitmapFont *this)
{
  this->__vftable = (CBitmapFont_vtbl *)&CBitmapFont::`vftable';
  CWin32Font::~CWin32Font(this);
}

//------------------------------------------------------------------------------
// Address: 0x100182C0
// Name: public: virtual bool CBitmapFont::IsEqualTo(char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitmapFont::IsEqualTo(
        CBitmapFont *this,
        const char *windowsFontName,
        float scalex,
        float scaley,
        unsigned __int16 flags)
{
  const char *v6; // eax
  char fontname[260]; // [esp+4h] [ebp-104h] BYREF

  V_FileBase(in: windowsFontName, out: fontname, maxlen: 260);
  v6 = CUtlSymbol::String(this: &this->m_szName);
  return _V_stricmp(s1: fontname, s2: v6) == 0
      && this->m_scalex == scalex
      && this->m_scaley == scaley
      && (this->m_iFlags & 0x100 & flags) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018340
// Name: public: void CBitmapFont::SetScale(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::SetScale(CBitmapFont *this, float sx, float sy)
{
  this->m_scalex = sx;
  this->m_scaley = sy;
}

//------------------------------------------------------------------------------
// Address: 0x10018360
// Name: public: virtual void CBitmapFont::GetKernedCharWidth(wchar_t,wchar_t,wchar_t,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::GetKernedCharWidth(
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
// Address: 0x100183C0
// Name: public: CBitmapFont::CBitmapFont(void)
// Source: json
//------------------------------------------------------------------------------
CBitmapFont *__thiscall CBitmapFont::CBitmapFont(CBitmapFont *this)
{
  CWin32Font::CWin32Font(this);
  this->__vftable = (CBitmapFont_vtbl *)&CBitmapFont::`vftable';
  this->m_scalex = 1.0;
  this->m_scaley = 1.0;
  this->m_bitmapFontHandle = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018490
// Name: public: virtual void CBitmapFont::GetCharABCWidths(int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::GetCharABCWidths(CBitmapFont *this, int ch, int *a, int *b, int *c)
{
  BitmapFontTable_t *v5; // edx
  int v6; // eax

  v5 = &g_BitmapFontTable.m_Memory.m_pMemory[this->m_bitmapFontHandle];
  v6 = v5->m_pBitmapFont->m_TranslateTable[ch];
  *a = (int)(float)((float)v5->m_pBitmapGlyphs[v6].a * this->m_scalex);
  *b = (int)(float)((float)v5->m_pBitmapGlyphs[v6].b * this->m_scalex);
  *c = (int)(float)((float)v5->m_pBitmapGlyphs[v6].c * this->m_scalex);
}

//------------------------------------------------------------------------------
// Address: 0x10018520
// Name: public: void CBitmapFont::GetCharCoords(int,float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::GetCharCoords(
        CBitmapFont *this,
        int ch,
        float *left,
        float *top,
        float *right,
        float *bottom)
{
  BitmapFontTable_t *v6; // eax
  BitmapFont_s *m_pBitmapFont; // ecx
  BitmapGlyph_s *m_pBitmapGlyphs; // eax
  int x; // edx
  __int16 *p_x; // eax

  v6 = &g_BitmapFontTable.m_Memory.m_pMemory[this->m_bitmapFontHandle];
  m_pBitmapFont = v6->m_pBitmapFont;
  m_pBitmapGlyphs = v6->m_pBitmapGlyphs;
  x = m_pBitmapGlyphs[m_pBitmapFont->m_TranslateTable[ch]].x;
  p_x = &m_pBitmapGlyphs[m_pBitmapFont->m_TranslateTable[ch]].x;
  *left = (float)x / (float)m_pBitmapFont->m_PageWidth;
  *top = (float)p_x[1] / (float)m_pBitmapFont->m_PageHeight;
  *right = (float)(*p_x + p_x[2]) / (float)m_pBitmapFont->m_PageWidth;
  *bottom = (float)(p_x[1] + p_x[3]) / (float)m_pBitmapFont->m_PageHeight;
}

//------------------------------------------------------------------------------
// Address: 0x100185F0
// Name: public: class ITexture __near * CBitmapFont::GetTexturePage(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CBitmapFont::GetTexturePage(CBitmapFont *this)
{
  if ( g_pMaterialSystem != nullptr )
    return g_BitmapFontTable.m_Memory.m_pMemory[this->m_bitmapFontHandle].m_pTexture;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10018610
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    free(pMem: this->m_Names.m_Memory.m_pMemory[i]);
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018710
// Name: struct datamap_t __near * DataMapInit<struct BitmapGlyph_s>(struct BitmapGlyph_s __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<BitmapGlyph_s>()
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    nameHolder.m_pszBase = "BitmapGlyph_t";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = 13;
    atexit(func: DataMapInit_BitmapGlyph_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  BitmapGlyph_s::m_DataMap.baseMap = nullptr;
  BitmapGlyph_s::m_DataMap.dataNumFields = 7;
  BitmapGlyph_s::m_DataMap.dataDesc = &dataDesc[1];
  return &BitmapGlyph_s::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10018790
// Name: struct datamap_t __near * DataMapInit<struct BitmapFont_s>(struct BitmapFont_s __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<BitmapFont_s>()
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    nameHolder_0.m_pszBase = "BitmapFont_t";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = 12;
    atexit(func: DataMapInit_BitmapFont_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  BitmapFont_s::m_DataMap.baseMap = nullptr;
  BitmapFont_s::m_DataMap.dataNumFields = 10;
  BitmapFont_s::m_DataMap.dataDesc = &dataDesc_0[1];
  return &BitmapFont_s::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10018850
// Name: public: virtual bool CBitmapFont::Create(char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBitmapFont::Create(
        CBitmapFont *this,
        const char *pFontFilename,
        float scalex,
        float scaley,
        __int16 flags)
{
  const char *v5; // edi
  CBitmapFont *v6; // esi
  int v7; // eax
  BitmapFontTable_t *m_pMemory; // ecx
  BitmapFontTable_t *v9; // ebx
  int v10; // eax
  BitmapFont_s *v11; // eax
  _WORD *v12; // esi
  unsigned __int8 *v13; // eax
  BitmapFont_s *m_pBitmapFont; // ecx
  ITexture *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm0_4
  __int16 m_Flags; // ax
  char textureName[260]; // [esp+8h] [ebp-210h] BYREF
  char fontName[260]; // [esp+10Ch] [ebp-10Ch] BYREF
  CBitmapFont *v22; // [esp+210h] [ebp-8h]
  void *pBuf; // [esp+214h] [ebp-4h] BYREF

  v5 = pFontFilename;
  v6 = this;
  v22 = this;
  if ( pFontFilename == nullptr || *pFontFilename == 0 )
    return 0;
  V_FileBase(in: pFontFilename, out: fontName, maxlen: 260);
  _V_strlower(start: fontName);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pFontFilename + 1, pStr: fontName);
  v7 = 0;
  if ( g_BitmapFontTable.m_Size <= 0 )
    goto LABEL_9;
  m_pMemory = g_BitmapFontTable.m_Memory.m_pMemory;
  while ( HIWORD(pFontFilename) != m_pMemory->m_szName.m_Id )
  {
    ++v7;
    ++m_pMemory;
    if ( v7 >= g_BitmapFontTable.m_Size )
      goto LABEL_9;
  }
  v6->m_bitmapFontHandle = v7;
  v9 = &g_BitmapFontTable.m_Memory.m_pMemory[v7];
  if ( v9 == nullptr )
  {
LABEL_9:
    pBuf = nullptr;
    FontManager();
    if ( g_pFullFileSystem->ReadFileEx(
           this: g_pFullFileSystem,
           a2: v5,
           a3: "GAME",
           a4: &pBuf,
           a5: false,
           a6: false,
           a7: 0,
           a8: 0,
           a9: nullptr) <= 0
      || pBuf == nullptr
      || *(_DWORD *)pBuf != 1414415958
      || *((_DWORD *)pBuf + 1) != 3 )
    {
      return 0;
    }
    v10 = CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::InsertBefore(
            this: &g_BitmapFontTable,
            elem: g_BitmapFontTable.m_Size);
    v6->m_bitmapFontHandle = v10;
    v9 = &g_BitmapFontTable.m_Memory.m_pMemory[v10];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pFontFilename + 1, pStr: fontName);
    v9->m_szName.m_Id = HIWORD(pFontFilename);
    v11 = (BitmapFont_s *)operator new(nSize: 0x116u);
    v9->m_pBitmapFont = v11;
    v12 = pBuf;
    qmemcpy(v11, pBuf, 0x114u);
    *(_WORD *)&v11->m_TranslateTable[254] = v12[138];
    v13 = (unsigned __int8 *)operator new(nSize: 14 * v9->m_pBitmapFont->m_NumGlyphs);
    m_pBitmapFont = v9->m_pBitmapFont;
    v9->m_pBitmapGlyphs = (BitmapGlyph_s *)v13;
    memcpy(dst: v13, src: (unsigned __int8 *)pBuf + 278, count: 14 * m_pBitmapFont->m_NumGlyphs);
    FontManager();
    g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: pBuf);
    V_snprintf(pDest: textureName, maxLen: 260, pFormat: "vgui/fonts/%s", fontName);
    if ( g_pMaterialSystem != nullptr )
    {
      FontManager();
      v15 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: textureName, a3: "VGUI textures", a4: 1, a5: 0);
      v9->m_pTexture = v15;
      v15->IncrementReferenceCount(this: v15);
    }
    v6 = v22;
  }
  v16 = scalex;
  v17 = scaley;
  v6->m_scalex = scalex;
  v6->m_scaley = v17;
  v6->m_iFlags = 2048;
  m_Flags = v9->m_pBitmapFont->m_Flags;
  if ( (m_Flags & 0x40) != 0 )
    v6->m_iFlags = 2064;
  if ( (m_Flags & 2) != 0 )
    v6->m_iFlags |= 1u;
  if ( (m_Flags & 0x10) != 0 )
  {
    v6->m_iFlags |= 0x20u;
    v6->m_iBlur = 1;
  }
  if ( (m_Flags & 0x20) != 0 )
    v6->m_iScanLines = 1;
  if ( (m_Flags & 4) != 0 )
  {
    v6->m_iFlags |= 0x200u;
    *((_DWORD *)&v6->CWin32Font + 9) |= 0x2000000u;
  }
  if ( (m_Flags & 8) != 0 )
  {
    v6->m_iFlags |= 0x80u;
    *((_DWORD *)&v6->CWin32Font + 9) |= 0x1000000u;
  }
  if ( (flags & 0x100) != 0 )
  {
    *((_DWORD *)&v6->CWin32Font + 9) |= 0x10000000u;
    v6->m_iFlags |= 0x100u;
  }
  *((_BYTE *)&v6->CWin32Font + 37) = (int)(float)((float)v9->m_pBitmapFont->m_MaxCharWidth * v16);
  *((_BYTE *)&v6->CWin32Font + 36) = (int)(float)((float)v9->m_pBitmapFont->m_MaxCharHeight * v17);
  *((_BYTE *)&v6->CWin32Font + 38) = (int)(float)((float)v9->m_pBitmapFont->m_Ascent * v17);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pFontFilename + 1, pStr: fontName);
  v6->m_szName.m_Id = HIWORD(pFontFilename);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BAC90
// Name: BitmapGlyph_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *BitmapGlyph_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<BitmapGlyph_s>();
  BitmapGlyph_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BACA0
// Name: BitmapFont_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *BitmapFont_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<BitmapFont_s>();
  BitmapFont_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BACB0
// Name: sub_100BACB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_100BACB0()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_10145728 = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x100BACD0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CTextureReference::CTextureReference(this: (CTextureReference *)&g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x100BACF0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BAD00
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BAD60
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BAD90
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100BADB0
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004C0640
// Name: public: CBitmapFont::~CBitmapFont(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::~CBitmapFont(CBitmapFont *this)
{
  this->__vftable = (CBitmapFont_vtbl *)&CBitmapFont::`vftable';
  CWin32Font::~CWin32Font(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C0650
// Name: public: virtual bool CBitmapFont::IsEqualTo(char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitmapFont::IsEqualTo(
        CBitmapFont *this,
        const char *windowsFontName,
        float scalex,
        float scaley,
        unsigned __int16 flags)
{
  char *v6; // eax
  char fontname[264]; // [esp+0h] [ebp-108h] BYREF

  V_FileBase(in: windowsFontName, out: &fontname[4], maxlen: 260);
  v6 = CUtlSymbol::String(this: &this->m_szName);
  return _V_stricmp(s1: &fontname[4], s2: v6) == 0
      && this->m_scalex == scalex
      && this->m_scaley == scaley
      && (this->m_iFlags & 0x100 & flags) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C06E0
// Name: public: virtual void CBitmapFont::GetKernedCharWidth(wchar_t,wchar_t,wchar_t,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::GetKernedCharWidth(
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
  int c; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  this->GetCharABCWidths(this, a2: (unsigned __int16)ch, a3: &ch, a4: &c, a5: &v10);
  v7 = ch;
  v8 = v10;
  *wide = (float)(v10 + ch + c);
  *abcA = (float)v7;
  *abcC = (float)v8;
}

//------------------------------------------------------------------------------
// Address: 0x004C0740
// Name: public: CBitmapFont::CBitmapFont(void)
// Source: json
//------------------------------------------------------------------------------
CBitmapFont *__thiscall CBitmapFont::CBitmapFont(CBitmapFont *this)
{
  CWin32Font::CWin32Font(this);
  this->__vftable = (CBitmapFont_vtbl *)&CBitmapFont::`vftable';
  this->m_scalex = 1.0;
  this->m_scaley = 1.0;
  this->m_bitmapFontHandle = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C0770
// Name: public: virtual void CBitmapFont::GetCharABCWidths(int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::GetCharABCWidths(CBitmapFont *this, int ch, int *a, int *b, int *c)
{
  BitmapFontTable_t *v5; // edx
  int v6; // eax

  v5 = &g_BitmapFontTable.m_Memory.m_pMemory[this->m_bitmapFontHandle];
  v6 = v5->m_pBitmapFont->m_TranslateTable[ch];
  *a = (int)(float)((float)v5->m_pBitmapGlyphs[v6].a * this->m_scalex);
  *b = (int)(float)((float)v5->m_pBitmapGlyphs[v6].b * this->m_scalex);
  *c = (int)(float)((float)v5->m_pBitmapGlyphs[v6].c * this->m_scalex);
}

//------------------------------------------------------------------------------
// Address: 0x004C07F0
// Name: public: void CBitmapFont::GetCharCoords(int,float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapFont::GetCharCoords(
        CBitmapFont *this,
        int ch,
        float *left,
        float *top,
        float *right,
        float *bottom)
{
  BitmapFontTable_t *v6; // eax
  BitmapFont_s *m_pBitmapFont; // ecx
  BitmapGlyph_s *m_pBitmapGlyphs; // eax
  int x; // edx
  __int16 *p_x; // eax

  v6 = &g_BitmapFontTable.m_Memory.m_pMemory[this->m_bitmapFontHandle];
  m_pBitmapFont = v6->m_pBitmapFont;
  m_pBitmapGlyphs = v6->m_pBitmapGlyphs;
  x = m_pBitmapGlyphs[m_pBitmapFont->m_TranslateTable[ch]].x;
  p_x = &m_pBitmapGlyphs[m_pBitmapFont->m_TranslateTable[ch]].x;
  *left = (float)x / (float)m_pBitmapFont->m_PageWidth;
  *top = (float)p_x[1] / (float)m_pBitmapFont->m_PageHeight;
  *right = (float)(*p_x + p_x[2]) / (float)m_pBitmapFont->m_PageWidth;
  *bottom = (float)(p_x[1] + p_x[3]) / (float)m_pBitmapFont->m_PageHeight;
}

//------------------------------------------------------------------------------
// Address: 0x004C08A0
// Name: public: class ITexture __near * CBitmapFont::GetTexturePage(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CBitmapFont::GetTexturePage(CBitmapFont *this)
{
  if ( g_pMaterialSystem != nullptr )
    return g_BitmapFontTable.m_Memory.m_pMemory[this->m_bitmapFontHandle].m_pTexture;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004C08C0
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    free(pMem: this->m_Names.m_Memory.m_pMemory[i]);
  v3 = this->m_Names.m_Memory.m_nGrowSize < 0;
  this->m_Names.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_Names.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( !v3 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0B10
// Name: public: virtual bool CBitmapFont::Create(char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBitmapFont::Create(
        CBitmapFont *this,
        const char *pFontFilename,
        float scalex,
        float scaley,
        __int16 flags)
{
  int v6; // eax
  BitmapFontTable_t *m_pMemory; // ecx
  BitmapFontTable_t *v8; // ebp
  int v9; // eax
  BitmapFont_s *v10; // eax
  int v11; // esi
  unsigned __int8 *v12; // eax
  BitmapFont_s *m_pBitmapFont; // ecx
  ITexture *v14; // eax
  __int16 m_Flags; // ax
  void *pBuf; // [esp+1Eh] [ebp-210h] BYREF
  char fontName[260]; // [esp+22h] [ebp-20Ch] BYREF
  char textureName[264]; // [esp+126h] [ebp-108h] BYREF

  if ( pFontFilename == nullptr || *pFontFilename == 0 )
    return 0;
  V_FileBase(in: pFontFilename, out: &fontName[4], maxlen: 260);
  _V_strlower(start: &fontName[4]);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pBuf + 1, pStr: &fontName[4]);
  v6 = 0;
  if ( g_BitmapFontTable.m_Size <= 0 )
    goto LABEL_9;
  m_pMemory = g_BitmapFontTable.m_Memory.m_pMemory;
  while ( HIWORD(pBuf) != m_pMemory->m_szName.m_Id )
  {
    ++v6;
    ++m_pMemory;
    if ( v6 >= g_BitmapFontTable.m_Size )
      goto LABEL_9;
  }
  this->m_bitmapFontHandle = v6;
  v8 = &g_BitmapFontTable.m_Memory.m_pMemory[v6];
  if ( v8 == nullptr )
  {
LABEL_9:
    *(_DWORD *)fontName = 0;
    FontManager();
    if ( g_pFullFileSystem->ReadFileEx(
           this: g_pFullFileSystem,
           a2: pFontFilename,
           a3: "GAME",
           a4: (void **)fontName,
           a5: false,
           a6: false,
           a7: 0,
           a8: 0,
           a9: nullptr) <= 0
      || *(_DWORD *)fontName == 0
      || **(_DWORD **)fontName != 1414415958
      || *(_DWORD *)(*(_DWORD *)fontName + 4) != 3 )
    {
      return 0;
    }
    v9 = CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::InsertBefore(
           this: &g_BitmapFontTable,
           elem: g_BitmapFontTable.m_Size);
    this->m_bitmapFontHandle = v9;
    v8 = &g_BitmapFontTable.m_Memory.m_pMemory[v9];
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pBuf + 1, pStr: &fontName[4]);
    v8->m_szName.m_Id = HIWORD(pBuf);
    v10 = (BitmapFont_s *)MemAlloc_Alloc(nSize: 0x116u);
    v8->m_pBitmapFont = v10;
    v11 = *(_DWORD *)fontName;
    qmemcpy(v10, *(const void **)fontName, 0x114u);
    *(_WORD *)&v10->m_TranslateTable[254] = *(_WORD *)(v11 + 276);
    v12 = (unsigned __int8 *)MemAlloc_Alloc(
                               nSize: (14 * (unsigned __int64)(unsigned int)v8->m_pBitmapFont->m_NumGlyphs) >> 32 != 0
                             ? -1
                             : 14 * v8->m_pBitmapFont->m_NumGlyphs);
    m_pBitmapFont = v8->m_pBitmapFont;
    v8->m_pBitmapGlyphs = (BitmapGlyph_s *)v12;
    memcpy(dst: v12, src: (unsigned __int8 *)(*(_DWORD *)fontName + 278), count: 14 * m_pBitmapFont->m_NumGlyphs);
    FontManager();
    g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: *(void **)fontName);
    V_snprintf(pDest: &textureName[4], maxLen: 0x104u, pFormat: "vgui/fonts/%s", &fontName[4]);
    if ( g_pMaterialSystem != nullptr )
    {
      FontManager();
      v14 = g_pMaterialSystem->FindTexture(
              this: g_pMaterialSystem,
              a2: &textureName[4],
              a3: "VGUI textures",
              a4: 1,
              a5: 0);
      v8->m_pTexture = v14;
      v14->IncrementReferenceCount(this: v14);
    }
  }
  this->m_scalex = scalex;
  this->m_scaley = scaley;
  this->m_iFlags = 2048;
  m_Flags = v8->m_pBitmapFont->m_Flags;
  if ( (m_Flags & 0x40) != 0 )
    this->m_iFlags = 2064;
  if ( (m_Flags & 2) != 0 )
    this->m_iFlags |= 1u;
  if ( (m_Flags & 0x10) != 0 )
  {
    this->m_iFlags |= 0x20u;
    this->m_iBlur = 1;
  }
  if ( (m_Flags & 0x20) != 0 )
    this->m_iScanLines = 1;
  if ( (m_Flags & 4) != 0 )
  {
    this->m_iFlags |= 0x200u;
    *((_DWORD *)&this->CWin32Font + 9) |= 0x2000000u;
  }
  if ( (m_Flags & 8) != 0 )
  {
    this->m_iFlags |= 0x80u;
    *((_DWORD *)&this->CWin32Font + 9) |= 0x1000000u;
  }
  if ( (flags & 0x100) != 0 )
  {
    *((_DWORD *)&this->CWin32Font + 9) |= 0x10000000u;
    this->m_iFlags |= 0x100u;
  }
  *((_BYTE *)&this->CWin32Font + 37) = (int)(float)((float)v8->m_pBitmapFont->m_MaxCharWidth * scalex);
  *((_BYTE *)&this->CWin32Font + 36) = (int)(float)((float)v8->m_pBitmapFont->m_MaxCharHeight * scaley);
  *((_BYTE *)&this->CWin32Font + 38) = (int)(float)((float)v8->m_pBitmapFont->m_Ascent * scaley);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pBuf + 1, pStr: &fontName[4]);
  this->m_szName.m_Id = HIWORD(pBuf);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00534430
// Name: BitmapGlyph_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *BitmapGlyph_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<BitmapGlyph_s>();
  BitmapGlyph_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00534440
// Name: BitmapFont_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *BitmapFont_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<BitmapFont_s>();
  BitmapFont_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

} // namespace vgui_perftest
