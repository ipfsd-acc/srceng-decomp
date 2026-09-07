// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_surfacelib/fontamalgam.cpp
// Functions: 8
// ============================================================

#include "vgui2\vgui_surfacelib\fontamalgam.h"

//------------------------------------------------------------------------------
// Address: 0x10022A30
// Name: public: class CWin32Font __near * CFontAmalgam::GetFontForChar(int)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontAmalgam::GetFontForChar(CFontAmalgam *this, int ch)
{
  int m_Size; // edx
  int v3; // eax
  CFontAmalgam::TFontRange *m_pMemory; // edi
  CFontAmalgam::TFontRange *i; // ecx

  m_Size = this->m_Fonts.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Fonts.m_Memory.m_pMemory;
  for ( i = this->m_Fonts.m_Memory.m_pMemory; ch < i->lowRange || ch > i->highRange; ++i )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  return m_pMemory[v3].pWin32Font;
}

//------------------------------------------------------------------------------
// Address: 0x10022A70
// Name: public: int CFontAmalgam::GetFontHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontAmalgam::GetFontHeight(CFontAmalgam *this)
{
  if ( this->m_Fonts.m_Size != 0 )
    return this->m_Fonts.m_Memory.m_pMemory->pWin32Font->GetHeight(this: this->m_Fonts.m_Memory.m_pMemory->pWin32Font);
  else
    return this->m_iMaxHeight;
}

//------------------------------------------------------------------------------
// Address: 0x10022A90
// Name: public: char const __near * CFontAmalgam::GetFontName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFontAmalgam::GetFontName(CFontAmalgam *this, int i)
{
  CWin32Font *pWin32Font; // ecx

  if ( this->m_Fonts.m_Size != 0
    && (pWin32Font = this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font) != nullptr
    && pWin32Font->IsValid(this: pWin32Font) )
  {
    return CUtlSymbol::String(this: &this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font->m_szName);
  }
  else
  {
    return (char *)pHelpString;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022AE0
// Name: public: int CFontAmalgam::GetFlags(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontAmalgam::GetFlags(CFontAmalgam *this, int i)
{
  CWin32Font *pWin32Font; // ecx

  if ( this->m_Fonts.m_Size != 0 && (pWin32Font = this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font) != nullptr )
    return pWin32Font->GetFlags(this: pWin32Font);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10022B10
// Name: public: void CFontAmalgam::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontAmalgam::RemoveAll(CFontAmalgam *this)
{
  this->m_Fonts.m_Size = 0;
  this->m_iMaxHeight = 0;
  this->m_iMaxWidth = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10022B20
// Name: public: CFontAmalgam::CFontAmalgam(void)
// Source: json
//------------------------------------------------------------------------------
CFontAmalgam *__thiscall CFontAmalgam::CFontAmalgam(CFontAmalgam *this)
{
  CFontAmalgam::TFontRange *v2; // eax

  this->m_Fonts.m_Memory.m_pMemory = nullptr;
  this->m_Fonts.m_Memory.m_nGrowSize = 0;
  this->m_Fonts.m_Size = 0;
  this->m_Fonts.m_pElements = nullptr;
  this->m_Fonts.m_Memory.m_nAllocationCount = 4;
  v2 = (CFontAmalgam::TFontRange *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 48);
  this->m_iMaxHeight = 0;
  this->m_iMaxWidth = 0;
  this->m_Fonts.m_Memory.m_pMemory = v2;
  this->m_Fonts.m_pElements = v2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10022B60
// Name: public: CFontAmalgam::~CFontAmalgam(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFontAmalgam::~CFontAmalgam(CFontAmalgam *this)
{
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>((CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10022B70
// Name: public: void CFontAmalgam::AddFont(class CWin32Font __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontAmalgam::AddFont(CFontAmalgam *this, CWin32Font *pFont, int lowRange, int highRange)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CFontAmalgam::TFontRange *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax
  int m_iMaxHeight; // ebx
  int v11; // eax
  int m_iMaxWidth; // ebx

  m_nAllocationCount = this->m_Fonts.m_Memory.m_nAllocationCount;
  m_Size = this->m_Fonts.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CScheme::SchemeBorder_t,int>::Grow(this: &this->m_Fonts.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Fonts.m_Size;
  m_pMemory = this->m_Fonts.m_Memory.m_pMemory;
  v8 = this->m_Fonts.m_Size - m_Size - 1;
  this->m_Fonts.m_pElements = this->m_Fonts.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v8);
  v9 = m_Size;
  this->m_Fonts.m_Memory.m_pMemory[v9].pWin32Font = pFont;
  this->m_Fonts.m_Memory.m_pMemory[v9].lowRange = lowRange;
  this->m_Fonts.m_Memory.m_pMemory[v9].highRange = highRange;
  m_iMaxHeight = this->m_iMaxHeight;
  if ( pFont->GetHeight(this: pFont) <= m_iMaxHeight )
    v11 = m_iMaxHeight;
  else
    v11 = pFont->GetHeight(this: pFont);
  m_iMaxWidth = this->m_iMaxWidth;
  this->m_iMaxHeight = v11;
  if ( pFont->GetMaxCharWidth(this: pFont) <= m_iMaxWidth )
    this->m_iMaxWidth = m_iMaxWidth;
  else
    this->m_iMaxWidth = pFont->GetMaxCharWidth(this: pFont);
}

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10018BE0
// Name: public: class CWin32Font __near * CFontAmalgam::GetFontForChar(int)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontAmalgam::GetFontForChar(CFontAmalgam *this, int ch)
{
  int m_Size; // edx
  int v3; // eax
  CFontAmalgam::TFontRange *m_pMemory; // edi
  CFontAmalgam::TFontRange *i; // ecx

  m_Size = this->m_Fonts.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Fonts.m_Memory.m_pMemory;
  for ( i = this->m_Fonts.m_Memory.m_pMemory; ch < i->lowRange || ch > i->highRange; ++i )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  return m_pMemory[v3].pWin32Font;
}

//------------------------------------------------------------------------------
// Address: 0x10018C20
// Name: public: int CFontAmalgam::GetFontHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontAmalgam::GetFontHeight(CFontAmalgam *this)
{
  if ( this->m_Fonts.m_Size != 0 )
    return this->m_Fonts.m_Memory.m_pMemory->pWin32Font->GetHeight(this: this->m_Fonts.m_Memory.m_pMemory->pWin32Font);
  else
    return this->m_iMaxHeight;
}

//------------------------------------------------------------------------------
// Address: 0x10018C40
// Name: public: char const __near * CFontAmalgam::GetFontName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFontAmalgam::GetFontName(CFontAmalgam *this, int i)
{
  CWin32Font *pWin32Font; // ecx

  if ( this->m_Fonts.m_Size != 0
    && (pWin32Font = this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font) != nullptr
    && pWin32Font->IsValid(this: pWin32Font) )
  {
    return CUtlSymbol::String(this: &this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font->m_szName);
  }
  else
  {
    return defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018C90
// Name: public: int CFontAmalgam::GetFlags(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontAmalgam::GetFlags(CFontAmalgam *this, int i)
{
  CWin32Font *pWin32Font; // ecx

  if ( this->m_Fonts.m_Size != 0 && (pWin32Font = this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font) != nullptr )
    return pWin32Font->GetFlags(this: pWin32Font);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018CC0
// Name: public: bool CFontAmalgam::GetUnderlined(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontAmalgam::GetUnderlined(CFontAmalgam *this)
{
  return this->m_Fonts.m_Size != 0 && (*((_DWORD *)this->m_Fonts.m_Memory.m_pMemory->pWin32Font + 9) & 0x20000000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018CE0
// Name: public: void CFontAmalgam::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontAmalgam::RemoveAll(CFontAmalgam *this)
{
  this->m_Fonts.m_Size = 0;
  this->m_iMaxHeight = 0;
  this->m_iMaxWidth = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018CF0
// Name: public: void CFontAmalgam::SetFontScale(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontAmalgam::SetFontScale(CFontAmalgam *this, float sx, float sy)
{
  CWin32Font *pWin32Font; // ecx
  __int16 v5; // ax
  const char *v6; // eax

  if ( this->m_Fonts.m_Size != 0 )
  {
    pWin32Font = this->m_Fonts.m_Memory.m_pMemory->pWin32Font;
    if ( pWin32Font != nullptr )
      v5 = pWin32Font->GetFlags(this: pWin32Font);
    else
      v5 = 0;
    if ( (v5 & 0x800) != 0 )
    {
      CBitmapFont::SetScale(this: (CBitmapFont *)this->m_Fonts.m_Memory.m_pMemory->pWin32Font, sx, sy);
    }
    else
    {
      v6 = CUtlSymbol::String(this: &this->m_Fonts.m_Memory.m_pMemory->pWin32Font->m_szName);
      _Warning(a1: "%s: Can't set font scale on a non-bitmap font!\n", v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018D60
// Name: public: CFontAmalgam::CFontAmalgam(void)
// Source: json
//------------------------------------------------------------------------------
CFontAmalgam *__thiscall CFontAmalgam::CFontAmalgam(CFontAmalgam *this)
{
  CFontAmalgam::TFontRange *v2; // eax

  this->m_Fonts.m_Memory.m_pMemory = nullptr;
  this->m_Fonts.m_Memory.m_nGrowSize = 0;
  this->m_Fonts.m_Size = 0;
  this->m_Fonts.m_pElements = nullptr;
  this->m_Fonts.m_Memory.m_nAllocationCount = 4;
  v2 = (CFontAmalgam::TFontRange *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 48);
  this->m_iMaxHeight = 0;
  this->m_iMaxWidth = 0;
  this->m_Fonts.m_Memory.m_pMemory = v2;
  this->m_Fonts.m_pElements = v2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018DA0
// Name: public: CFontAmalgam::~CFontAmalgam(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFontAmalgam::~CFontAmalgam(CFontAmalgam *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10018DB0
// Name: public: void CFontAmalgam::AddFont(class CWin32Font __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontAmalgam::AddFont(CFontAmalgam *this, CWin32Font *pFont, int lowRange, int highRange)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CFontAmalgam::TFontRange *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax
  int m_iMaxHeight; // ebx
  int v11; // eax
  int m_iMaxWidth; // ebx

  m_nAllocationCount = this->m_Fonts.m_Memory.m_nAllocationCount;
  m_Size = this->m_Fonts.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Fonts.m_Size;
  m_pMemory = this->m_Fonts.m_Memory.m_pMemory;
  v8 = this->m_Fonts.m_Size - m_Size - 1;
  this->m_Fonts.m_pElements = this->m_Fonts.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v8);
  v9 = m_Size;
  this->m_Fonts.m_Memory.m_pMemory[v9].pWin32Font = pFont;
  this->m_Fonts.m_Memory.m_pMemory[v9].lowRange = lowRange;
  this->m_Fonts.m_Memory.m_pMemory[v9].highRange = highRange;
  m_iMaxHeight = this->m_iMaxHeight;
  if ( pFont->GetHeight(this: pFont) <= m_iMaxHeight )
    v11 = m_iMaxHeight;
  else
    v11 = pFont->GetHeight(this: pFont);
  m_iMaxWidth = this->m_iMaxWidth;
  this->m_iMaxHeight = v11;
  if ( pFont->GetMaxCharWidth(this: pFont) <= m_iMaxWidth )
    this->m_iMaxWidth = m_iMaxWidth;
  else
    this->m_iMaxWidth = pFont->GetMaxCharWidth(this: pFont);
}

//------------------------------------------------------------------------------
// Address: 0x100467A0
// Name: public: int CFontAmalgam::GetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontAmalgam::GetCount(vgui::Image *this)
{
  return this->_size[0];
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004626F0
// Name: public: int CFontAmalgam::GetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontAmalgam::GetCount(CVTFTexture *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x004C0E90
// Name: public: class CWin32Font __near * CFontAmalgam::GetFontForChar(int)
// Source: json
//------------------------------------------------------------------------------
CWin32Font *__thiscall CFontAmalgam::GetFontForChar(CFontAmalgam *this, int ch)
{
  int m_Size; // edx
  int v3; // eax
  CFontAmalgam::TFontRange *m_pMemory; // edi
  CFontAmalgam::TFontRange *i; // ecx

  m_Size = this->m_Fonts.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Fonts.m_Memory.m_pMemory;
  for ( i = this->m_Fonts.m_Memory.m_pMemory; ch < i->lowRange || ch > i->highRange; ++i )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  return m_pMemory[v3].pWin32Font;
}

//------------------------------------------------------------------------------
// Address: 0x004C0ED0
// Name: public: int CFontAmalgam::GetFontHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontAmalgam::GetFontHeight(CFontAmalgam *this)
{
  if ( this->m_Fonts.m_Size != 0 )
    return this->m_Fonts.m_Memory.m_pMemory->pWin32Font->GetHeight(this: this->m_Fonts.m_Memory.m_pMemory->pWin32Font);
  else
    return this->m_iMaxHeight;
}

//------------------------------------------------------------------------------
// Address: 0x004C0EF0
// Name: public: char const __near * CFontAmalgam::GetFontName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFontAmalgam::GetFontName(CFontAmalgam *this, int i)
{
  CWin32Font *pWin32Font; // ecx

  if ( this->m_Fonts.m_Size != 0
    && (pWin32Font = this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font) != nullptr
    && pWin32Font->IsValid(this: pWin32Font) )
  {
    return CUtlSymbol::String(this: &this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font->m_szName);
  }
  else
  {
    return (char *)defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0F40
// Name: public: int CFontAmalgam::GetFlags(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFontAmalgam::GetFlags(CFontAmalgam *this, int i)
{
  CWin32Font *pWin32Font; // ecx

  if ( this->m_Fonts.m_Size != 0 && (pWin32Font = this->m_Fonts.m_Memory.m_pMemory[i].pWin32Font) != nullptr )
    return pWin32Font->GetFlags(this: pWin32Font);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C0F70
// Name: public: bool CFontAmalgam::GetUnderlined(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFontAmalgam::GetUnderlined(CFontAmalgam *this)
{
  return this->m_Fonts.m_Size != 0 && (*((_DWORD *)this->m_Fonts.m_Memory.m_pMemory->pWin32Font + 9) & 0x20000000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C0F90
// Name: public: void CFontAmalgam::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontAmalgam::RemoveAll(CFontAmalgam *this)
{
  this->m_Fonts.m_Size = 0;
  this->m_iMaxHeight = 0;
  this->m_iMaxWidth = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C0FA0
// Name: public: CFontAmalgam::CFontAmalgam(void)
// Source: json
//------------------------------------------------------------------------------
CFontAmalgam *__thiscall CFontAmalgam::CFontAmalgam(CFontAmalgam *this)
{
  this->m_Fonts.m_Memory.m_pMemory = nullptr;
  this->m_Fonts.m_Memory.m_nAllocationCount = 0;
  this->m_Fonts.m_Memory.m_nGrowSize = 0;
  this->m_Fonts.m_Size = 0;
  this->m_Fonts.m_pElements = nullptr;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
    (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this,
    num: 4);
  this->m_iMaxHeight = 0;
  this->m_iMaxWidth = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C0FD0
// Name: public: CFontAmalgam::~CFontAmalgam(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFontAmalgam::~CFontAmalgam(CFontAmalgam *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004C0FE0
// Name: public: void CFontAmalgam::AddFont(class CWin32Font __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontAmalgam::AddFont(CFontAmalgam *this, CWin32Font *pFont, int lowRange, int highRange)
{
  int v5; // eax
  int m_iMaxHeight; // ebx
  int v7; // eax
  int m_iMaxWidth; // ebx

  v5 = CUtlVector<CTGARenderer::Layer,CUtlMemory<CTGARenderer::Layer,int>>::InsertBefore(
         this: &this->m_Fonts,
         elem: this->m_Fonts.m_Size);
  this->m_Fonts.m_Memory.m_pMemory[v5].pWin32Font = pFont;
  this->m_Fonts.m_Memory.m_pMemory[v5].lowRange = lowRange;
  this->m_Fonts.m_Memory.m_pMemory[v5].highRange = highRange;
  m_iMaxHeight = this->m_iMaxHeight;
  if ( pFont->GetHeight(this: pFont) <= m_iMaxHeight )
    v7 = m_iMaxHeight;
  else
    v7 = pFont->GetHeight(this: pFont);
  m_iMaxWidth = this->m_iMaxWidth;
  this->m_iMaxHeight = v7;
  if ( pFont->GetMaxCharWidth(this: pFont) <= m_iMaxWidth )
    this->m_iMaxWidth = m_iMaxWidth;
  else
    this->m_iMaxWidth = pFont->GetMaxCharWidth(this: pFont);
}

} // namespace vgui_perftest
