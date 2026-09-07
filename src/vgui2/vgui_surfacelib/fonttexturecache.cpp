// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_surfacelib/fonttexturecache.cpp
// Functions: 13
// ============================================================

#include "vgui2\vgui_surfacelib\fonttexturecache.h"

//------------------------------------------------------------------------------
// Address: 0x10013BE0
// Name: public: void CFontTextureCache::SetPrefix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureCache::SetPrefix(CFontTextureCache *this, const char *pTexturePagePrefix)
{
  CUtlString::operator=(this: &this->m_TexturePagePrefix, src: pTexturePagePrefix);
}

//------------------------------------------------------------------------------
// Address: 0x10013BF0
// Name: private: static bool CFontTextureCache::CacheEntryLessFunc(struct CFontTextureCache::CacheEntry_t const __near &,struct CFontTextureCache::CacheEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CFontTextureCache::CacheEntryLessFunc(
        const CFontTextureCache::CacheEntry_t *lhs,
        const CFontTextureCache::CacheEntry_t *rhs)
{
  return lhs->font <= rhs->font && (lhs->font < rhs->font || lhs->wch < (unsigned int)rhs->wch);
}

//------------------------------------------------------------------------------
// Address: 0x10013C40
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10013C50
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10013CC0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: m_pMemory,
                                                                                             a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100148A0
// Name: private: void CFontTextureCache::CreateFontMaterials(struct CFontTextureCache::Page_t __near &,class ITexture __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureCache::CreateFontMaterials(
        CFontTextureCache *this,
        CFontTextureCache::Page_t *page,
        ITexture *pFontTexture,
        bool bitmapFont)
{
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  const char *v8; // eax
  const char *v9; // eax
  int v10; // esi
  CTextureDictionary *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  const char *v14; // eax
  const char *v15; // eax
  IMaterial *v16; // esi
  CTextureDictionary *v17; // eax
  CTextureDictionary_vtbl *v18; // edx
  CUtlString materialName; // [esp+Ch] [ebp-20h] BYREF
  CUtlString addmaterialName; // [esp+1Ch] [ebp-10h] BYREF
  ITexture *pFontTexturea; // [esp+38h] [ebp+Ch]

  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "UnlitGeneric");
  else
    v6 = nullptr;
  KeyValues::SetInt(this: v6, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v6, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v6, keyName: "$ignorez", value: 1);
  KeyValues::SetInt(this: v6, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v6, keyName: "$translucent", value: 1);
  v8 = (const char *)pFontTexture->GetName(this: pFontTexture);
  KeyValues::SetString(this: v6, keyName: "$basetexture", value: v8);
  CUtlString::operator+(this: &this->m_TexturePagePrefix, result: &materialName, pOther: "__fontpage");
  pFontTexturea = (ITexture *)g_pMaterialSystem->__vftable;
  v9 = CUtlString::operator char const *(this: &materialName);
  v10 = ((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *))pFontTexturea[80].__vftable)(
          a1: g_pMaterialSystem,
          a2: v9,
          a3: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 148))(a1: v10);
  v11 = TextureDictionary();
  v11->BindTextureToMaterial(this: v11, a2: page->textureID[0], a3: (IMaterial *)v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 52))(a1: v10);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "UnlitGeneric");
  else
    v13 = nullptr;
  KeyValues::SetInt(this: v13, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v13, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v13, keyName: "$ignorez", value: 1);
  KeyValues::SetInt(this: v13, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v13, keyName: "$translucent", value: 1);
  KeyValues::SetInt(this: v13, keyName: "$additive", value: 1);
  v14 = (const char *)pFontTexture->GetName(this: pFontTexture);
  KeyValues::SetString(this: v13, keyName: "$basetexture", value: v14);
  CUtlString::operator+(this: &this->m_TexturePagePrefix, result: &addmaterialName, pOther: "__fontpage_additive");
  v15 = CUtlString::operator char const *(this: &addmaterialName);
  v16 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: v15, a3: v13);
  v16->Refresh(this: v16);
  v17 = TextureDictionary();
  v18 = v17->__vftable;
  if ( bitmapFont )
    ((void (__thiscall *)(CTextureDictionary *, _DWORD))v18->BindTextureToMaterial)(a1: v17, a2: page->textureID[1]);
  else
    ((void (__thiscall *)(CTextureDictionary *, _DWORD, _DWORD))v18->BindTextureToMaterialReference)(
      a1: v17,
      a2: page->textureID[1],
      a3: page->textureID[0]);
  ((void (__thiscall *)(IMaterial *, IMaterial *))v16->DecrementReferenceCount)(a1: v16, a2: v16);
  addmaterialName.m_Storage.m_nActualLength = 0;
  if ( addmaterialName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( addmaterialName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: addmaterialName.m_Storage.m_Memory.m_pMemory);
      addmaterialName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    addmaterialName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  materialName.m_Storage.m_nActualLength = 0;
  if ( materialName.m_Storage.m_Memory.m_nGrowSize >= 0 && materialName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: materialName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10015C10
// Name: public: void CFontTextureCache::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureCache::Clear(CFontTextureCache *this)
{
  int i; // edi
  CFontTextureCache::Page_t *m_pMemory; // eax
  CTexturePacker *pPackedFontTextureCache; // ebx
  unsigned int j; // edi

  CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_CharCache);
  for ( i = 0; i < this->m_PageList.m_Size; ++i )
  {
    m_pMemory = this->m_PageList.m_Memory.m_pMemory;
    pPackedFontTextureCache = m_pMemory[i].pPackedFontTextureCache;
    if ( pPackedFontTextureCache != nullptr )
    {
      CTexturePacker::~CTexturePacker(this: m_pMemory[i].pPackedFontTextureCache);
      free(pMem: pPackedFontTextureCache);
    }
  }
  this->m_PageList.m_Size = 0;
  this->m_CurrPage = -1;
  CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_FontPages.m_Tree);
  if ( this->m_FontPages.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_FontPages.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<void *>::LessFunc;
  for ( j = 0; j < 0x180; ++j )
  {
    free(pMem: this->m_CommonCharCache[j]);
    this->m_CommonCharCache[j] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015CB0
// Name: private: bool CFontTextureCache::AllocatePageForChar(int,int,int __near &,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CFontTextureCache::AllocatePageForChar@<al>(
        CFontTextureCache *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int charWide,
        int charTall,
        int *pageIndex,
        int *drawX,
        int *drawY,
        int *twide,
        int *ttall)
{
  int m_CurrPage; // eax
  int v13; // edi
  CUtlVector<CFontTextureCache::Page_t,CUtlMemory<CFontTextureCache::Page_t,int> > *p_m_PageList; // ebx
  int inserted; // eax
  int v16; // eax
  CFontTextureCache::Page_t *v17; // ebx
  CTextureDictionary *v18; // eax
  CTexturePacker *v19; // eax
  CTexturePacker *v20; // eax
  const char *v21; // eax
  ITexture *v22; // edi
  char *v23; // esi
  _BYTE *v24; // eax
  int i; // ecx
  CTextureDictionary *v26; // eax
  int *p_x; // eax
  char pTextureName[64]; // [esp+4h] [ebp-50h] BYREF
  Rect_t glpyhRect; // [esp+44h] [ebp-10h] BYREF
  __int16 nodeIndex; // [esp+5Ch] [ebp+8h]
  CUtlVector<CFontTextureCache::Page_t,CUtlMemory<CFontTextureCache::Page_t,int> > *charTalla; // [esp+60h] [ebp+Ch]

  if ( charTall > 256 )
    return 0;
  m_CurrPage = this->m_CurrPage;
  v13 = 0;
  *pageIndex = m_CurrPage;
  glpyhRect.x = 0;
  glpyhRect.y = 0;
  glpyhRect.width = charWide;
  glpyhRect.height = charTall;
  if ( m_CurrPage <= -1
    || (p_m_PageList = &this->m_PageList,
        (inserted = CTexturePacker::InsertRect(
                      this: this->m_PageList.m_Memory.m_pMemory[m_CurrPage].pPackedFontTextureCache,
                      texRect: &glpyhRect,
                      nodeIndex: -1)) == -1) )
  {
    charTalla = &this->m_PageList;
    v16 = CUtlVector<CFontTextureCache::Page_t,CUtlMemory<CFontTextureCache::Page_t,int>>::InsertBefore(
            this: &this->m_PageList,
            elem: this->m_PageList.m_Size);
    *pageIndex = v16;
    v17 = &this->m_PageList.m_Memory.m_pMemory[v16];
    this->m_CurrPage = v16;
    do
    {
      v18 = TextureDictionary();
      v17->textureID[v13++] = v18->CreateTexture(this: v18, a2: true);
    }
    while ( v13 < 2 );
    v19 = (CTexturePacker *)operator new(nSize: 0x24u);
    if ( v19 != nullptr )
      v20 = CTexturePacker::CTexturePacker(this: v19, texWidth: 256, texHeight: 256, pixelGap: 1);
    else
      v20 = nullptr;
    v17->pPackedFontTextureCache = v20;
    nodeIndex = CTexturePacker::InsertRect(this: v20, texRect: &glpyhRect, nodeIndex: -1);
    v21 = CUtlString::operator char const *(this: &this->m_TexturePagePrefix);
    V_snprintf(pDest: pTextureName, maxLen: 64, pFormat: "%s__font_page_%d", v21, nFontPageId);
    ++nFontPageId;
    if ( g_pMaterialSystem != nullptr )
    {
      v22 = g_pMaterialSystem->CreateProceduralTexture(
              this: g_pMaterialSystem,
              a2: pTextureName,
              a3: "VGUI textures",
              a4: 256,
              a5: 256,
              a6: 0,
              a7: 264972);
      CFontTextureCache::CreateFontMaterials(this, page: v17, pFontTexture: v22, bitmapFont: false);
      v22->DecrementReferenceCount(this: v22);
    }
    v23 = (char *)((int (__thiscall *)(IMemAlloc *, int, int, int))_g_pMemAlloc->Alloc_2)(
                    a1: _g_pMemAlloc,
                    a2: 0x40000,
                    a3,
                    a4: a2);
    v24 = v23 + 1;
    for ( i = 0x10000; i != 0; --i )
    {
      v24[1] = -1;
      *v24 = -1;
      *(v24 - 1) = -1;
      v24[2] = 0;
      v24 += 4;
    }
    v26 = TextureDictionary();
    ((void (__thiscall *)(CTextureDictionary *, _DWORD, char *, int, int))v26->SetTextureRGBAEx)(
      a1: v26,
      a2: v17->textureID[0],
      a3: v23,
      a4: 256,
      a5: 256);
    if ( g_pMaterialSystem == nullptr )
      v17->textureID[1] = v17->textureID[0];
    if ( v23 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
    LOWORD(inserted) = nodeIndex;
    p_m_PageList = charTalla;
  }
  p_x = &p_m_PageList->m_Memory.m_pMemory[*pageIndex].pPackedFontTextureCache->m_Tree.m_Memory.m_pMemory[(unsigned __int16)inserted].m_Element.rc.x;
  *drawX = *p_x;
  *drawY = p_x[1];
  *twide = 256;
  *ttall = 256;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015ED0
// Name: public: CFontTextureCache::CFontTextureCache(void)
// Source: json
//------------------------------------------------------------------------------
CFontTextureCache *__thiscall CFontTextureCache::CFontTextureCache(CFontTextureCache *this)
{
  UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *m_pMemory; // edx

  this->m_CharCache.m_LessFunc = (bool (__cdecl *)(const CFontTextureCache::CacheEntry_t *, const CFontTextureCache::CacheEntry_t *))CFontTextureCache::CacheEntryLessFunc;
  this->m_CharCache.m_Elements.m_pMemory = nullptr;
  this->m_CharCache.m_Elements.m_nAllocationCount = 256;
  this->m_CharCache.m_Elements.m_nGrowSize = 0;
  this->m_CharCache.m_Elements.m_pMemory = (UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 9216);
  m_pMemory = this->m_CharCache.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_CharCache.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_CharCache.m_FirstFree = -1;
  this->m_CharCache.m_pElements = m_pMemory;
  this->m_PageList.m_Memory.m_pMemory = nullptr;
  this->m_PageList.m_Memory.m_nAllocationCount = 0;
  this->m_PageList.m_Memory.m_nGrowSize = 0;
  this->m_PageList.m_Size = 0;
  this->m_PageList.m_pElements = nullptr;
  this->m_FontPages.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_FontPages.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_FontPages.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_FontPages.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_FontPages.m_Tree.m_pElements = this->m_FontPages.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_FontPages.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_FontPages.m_Tree.m_FirstFree = -1;
  CUtlString::CUtlString(this: &this->m_TexturePagePrefix);
  _V_memset(dest: this, fill: 0, count: 1536);
  CFontTextureCache::Clear(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10015FB0
// Name: public: CFontTextureCache::~CFontTextureCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureCache::~CFontTextureCache(CFontTextureCache *this)
{
  bool v2; // sf

  CFontTextureCache::Clear(this);
  v2 = this->m_TexturePagePrefix.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_TexturePagePrefix.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_TexturePagePrefix.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TexturePagePrefix.m_Storage.m_Memory.m_pMemory);
      this->m_TexturePagePrefix.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_TexturePagePrefix.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_FontPages.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PageList);
  CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::~CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>(this: &this->m_CharCache);
}

//------------------------------------------------------------------------------
// Address: 0x10016130
// Name: public: bool CFontTextureCache::GetTextureForChars(unsigned long,enum FontDrawType_t,wchar_t __near *,int __near *,float __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontTextureCache::GetTextureForChars(
        CFontTextureCache *this,
        unsigned __int8 *hFont,
        int type,
        wchar_t *wch,
        char *textureID,
        CFontTextureCache::Page_t *texCoords,
        int numChars)
{
  FontDrawType_t v7; // eax
  unsigned int v8; // ebx
  int v9; // esi
  CFontManager *v10; // eax
  int v11; // eax
  CFontManager *v12; // eax
  float *v14; // edi
  CFontManager *v15; // eax
  CBitmapFont *FontForChar; // eax
  CFontTextureCache *v17; // ecx
  int v18; // esi
  CTextureDictionary *v19; // eax
  __int16 v20; // ax
  ITexture *TexturePage; // eax
  char *v22; // ecx
  CFontManager *v23; // eax
  void *v24; // esp
  void *v25; // esp
  float **v26; // eax
  int v27; // edi
  unsigned __int16 v28; // ax
  unsigned __int16 v29; // si
  CFontManager *v30; // eax
  CWin32Font *v31; // eax
  CWin32Font *v32; // ebx
  float v33; // ecx
  float v34; // xmm1_4
  int v35; // esi
  int v36; // edi
  CWin32Font *v37; // ebx
  int v38; // ebx
  float **v39; // eax
  char *v40; // edx
  int v41; // ecx
  int *v42; // ecx
  int v43; // edx
  char *v44; // eax
  int v45; // edx
  double v46; // xmm0_8
  int v47; // ecx
  double v48; // xmm2_8
  float v49; // xmm1_4
  double v50; // xmm1_8
  double v51; // xmm0_8
  float v52; // eax
  int v53; // ecx
  int v54; // edi
  void *v55; // esp
  char *v56; // esi
  newChar_t *v57; // edi
  wchar_t v58; // bx
  const char *v59; // ebx
  CUtlSymbol *p_m_szName; // ecx
  const char *v61; // eax
  CFmtStrN<256> *v62; // eax
  int v63; // ebx
  void *v64; // esp
  CFontTextureCache::GetTextureForChars::__l26::newPageEntry_t *v65; // edi
  newChar_t *v66; // esi
  _WORD *v67; // eax
  unsigned int v68; // ecx
  CTextureDictionary *v69; // eax
  wchar_t v70; // [esp-4h] [ebp-1A4h]
  wchar_t v71; // [esp-4h] [ebp-1A4h]
  char v72; // [esp+0h] [ebp-1A0h] BYREF
  _BYTE v73[3]; // [esp+1h] [ebp-19Fh] BYREF
  int v74; // [esp+8h] [ebp-198h] BYREF
  CFmtStrN<256> v75; // [esp+Ch] [ebp-194h] BYREF
  CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t insert; // [esp+118h] [ebp-88h] BYREF
  CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t search; // [esp+124h] [ebp-7Ch] BYREF
  CFontTextureCache::CacheEntry_t cacheItem; // [esp+130h] [ebp-70h] BYREF
  int ttall; // [esp+14Ch] [ebp-54h] BYREF
  int twide; // [esp+150h] [ebp-50h] BYREF
  int a; // [esp+154h] [ebp-4Ch] BYREF
  int wideChar; // [esp+158h] [ebp-48h]
  CFontTextureCache::GetTextureForChars::__l26::newPageEntry_t *newEntries; // [esp+15Ch] [ebp-44h]
  int b; // [esp+160h] [ebp-40h] BYREF
  char *v85; // [esp+164h] [ebp-3Ch]
  int c; // [esp+168h] [ebp-38h] BYREF
  int totalNewCharTexels; // [esp+16Ch] [ebp-34h]
  int maxNewCharTexels; // [esp+170h] [ebp-30h]
  CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl*)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short> > *p_m_CharCache; // [esp+174h] [ebp-2Ch]
  int i; // [esp+178h] [ebp-28h]
  float right; // [esp+17Ch] [ebp-24h] BYREF
  float **top; // [esp+180h] [ebp-20h] BYREF
  int page; // [esp+184h] [ebp-1Ch] BYREF
  int v94; // [esp+188h] [ebp-18h]
  int drawY; // [esp+18Ch] [ebp-14h] BYREF
  newChar_t *newChars; // [esp+190h] [ebp-10h] BYREF
  int v97; // [esp+194h] [ebp-Ch]
  CWin32Font *v98; // [esp+198h] [ebp-8h]
  CFontTextureCache *v99; // [esp+19Ch] [ebp-4h]
  int numNewChars; // [esp+1ACh] [ebp+Ch]
  int numNewCharsa; // [esp+1ACh] [ebp+Ch]
  wchar_t *wcha; // [esp+1B0h] [ebp+10h]
  wchar_t *wchb; // [esp+1B0h] [ebp+10h]

  v7 = type;
  v8 = (unsigned int)hFont;
  v9 = 0;
  v99 = this;
  if ( type == 0 )
  {
    v10 = FontManager();
    v7 = CFontManager::IsFontAdditive(this: v10, font: (unsigned int)hFont) + 1;
  }
  v11 = v7 - 1;
  if ( v11 >= 0 )
  {
    v97 = 1;
    if ( v11 <= 1 )
      v97 = v11;
  }
  else
  {
    v97 = 0;
  }
  v12 = FontManager();
  if ( CFontManager::IsBitmapFont(this: v12, font: (unsigned int)hFont) )
  {
    if ( numChars > 256 )
      return 0;
    numNewChars = 0;
    if ( numChars > 0 )
    {
      v14 = &sTexCoords[2];
      v94 = (char *)texCoords - textureID;
      while ( 1 )
      {
        v70 = wch[v9];
        v15 = FontManager();
        FontForChar = (CBitmapFont *)CFontManager::GetFontForChar(this: v15, font: v8, wch: v70);
        drawY = (int)FontForChar;
        if ( FontForChar == nullptr )
          break;
        CBitmapFont::GetCharCoords(
          this: FontForChar,
          ch: wch[v9],
          left: (float *)&newChars,
          (float *)&top,
          &right,
          bottom: (float *)&page);
        v17 = v99;
        *((_DWORD *)v14 - 2) = newChars;
        *((_DWORD *)v14 - 1) = top;
        *v14 = right;
        *((_DWORD *)v14 + 1) = page;
        search.elem.pPackedFontTextureCache = nullptr;
        search.key = v8;
        LOWORD(v8) = CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                       this: &v17->m_FontPages.m_Tree,
                       &search);
        if ( (unsigned __int16)v8 == 0xFFFF )
        {
          insert.key = (unsigned int)hFont;
          v18 = 0;
          insert.elem.pPackedFontTextureCache = nullptr;
          v8 = CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                 this: &v99->m_FontPages.m_Tree,
                 &insert);
          texCoords = &v99->m_FontPages.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
          do
          {
            v19 = TextureDictionary();
            v20 = v19->CreateTexture(this: v19, a2: false);
            texCoords->textureID[v18++] = v20;
          }
          while ( v18 < 2 );
          TexturePage = CBitmapFont::GetTexturePage(this: (CBitmapFont *)drawY);
          CFontTextureCache::CreateFontMaterials(
            this: v99,
            page: texCoords,
            pFontTexture: TexturePage,
            bitmapFont: true);
          v9 = numNewChars;
        }
        v22 = textureID;
        *(_DWORD *)&textureID[v94] = v14 - 2;
        ++v9;
        *(_DWORD *)v22 = v99->m_FontPages.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem.textureID[v97];
        v14 += 4;
        numNewChars = v9;
        textureID = v22 + 4;
        if ( v9 >= numChars )
          return 1;
        v8 = (unsigned int)hFont;
      }
      return 0;
    }
  }
  else
  {
    v71 = *wch;
    v23 = FontManager();
    v98 = CFontManager::GetFontForChar(this: v23, font: (unsigned int)hFont, wch: v71);
    if ( v98 == nullptr )
      return 0;
    v24 = alloca(16 * numChars);
    newChars = (newChar_t *)&v72;
    v25 = alloca(12 * numChars);
    newEntries = (CFontTextureCache::GetTextureForChars::__l26::newPageEntry_t *)&v72;
    numNewCharsa = 0;
    maxNewCharTexels = 0;
    totalNewCharTexels = 0;
    i = 0;
    if ( numChars > 0 )
    {
      p_m_CharCache = &v99->m_CharCache;
      v26 = (float **)texCoords;
      texCoords = (CFontTextureCache::Page_t *)&v74;
      top = v26;
      v94 = (int)&v74;
      v85 = (char *)(textureID - (char *)v26);
      while ( 1 )
      {
        v27 = wch[i];
        wideChar = v27;
        cacheItem.font = v8;
        cacheItem.wch = v27;
        v28 = CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Find(
                this: p_m_CharCache,
                search: &cacheItem);
        v29 = v28;
        if ( v28 >= p_m_CharCache->m_Elements.m_nAllocationCount
          || v28 > p_m_CharCache->m_LastAlloc.index
          || CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::LeftChild(
               this: p_m_CharCache,
               i: v28) == v28 )
        {
          v30 = FontManager();
          v31 = CFontManager::GetFontForChar(this: v30, font: v8, wch: v27);
          v32 = v98;
          if ( v98 != v31 )
            return 0;
          memset(cacheItem.texCoords, 0, sizeof(cacheItem.texCoords));
          v29 = CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Insert(
                  this: p_m_CharCache,
                  insert: &cacheItem);
        }
        else
        {
          v32 = v98;
        }
        LODWORD(v33) = &v99->m_CharCache.m_Elements.m_pMemory[v29];
        v34 = *(float *)(LODWORD(v33) + 28);
        v35 = LODWORD(v33) + 20;
        right = v33;
        if ( v34 == 0.0 && *(float *)(LODWORD(v33) + 32) == 0.0 )
        {
          v32->GetCharABCWidths(this: v32, a2: (unsigned __int16)v27, a3: &a, a4: &b, a5: &c);
          v36 = b;
          if ( b <= 1 )
            v36 = 1;
          v37 = v98;
          if ( v98->GetHeight(this: v98) <= 1 )
            v38 = 1;
          else
            v38 = v37->GetHeight(this: v37);
          if ( (*((_DWORD *)v98 + 9) & 0x20000000) != 0 )
            v36 += c + a;
          if ( CFontTextureCache::AllocatePageForChar(
                 this: v99,
                 a2: v38,
                 a3: v36,
                 charWide: v36,
                 charTall: v38,
                 pageIndex: &page,
                 drawX: (int *)&textureID,
                 &drawY,
                 &twide,
                 &ttall) == 0 )
            return 0;
          v39 = (float **)texCoords;
          v40 = textureID;
          *(_DWORD *)texCoords[-1].textureID = page;
          v41 = drawY;
          *(v39 - 1) = (float *)v40;
          LOWORD(v40) = wideChar;
          *v39 = (float *)v41;
          v42 = (int *)v94;
          *(_WORD *)(v94 - 8) = (_WORD)v40;
          v43 = totalNewCharTexels;
          v42[1] = 4 * totalNewCharTexels;
          *(v42 - 1) = v36;
          *v42 = v38;
          totalNewCharTexels = v36 * v38 + v43;
          if ( maxNewCharTexels <= v36 * v38 )
            maxNewCharTexels = v36 * v38;
          v44 = textureID;
          ++numNewCharsa;
          texCoords = (CFontTextureCache::Page_t *)((char *)texCoords + 12);
          v45 = page;
          v46 = (double)twide;
          v94 = (int)(v42 + 4);
          v47 = drawY;
          v48 = (double)drawY;
          v49 = (double)(int)textureID / (double)twide;
          *(float *)v35 = v49;
          v50 = (double)ttall;
          *(float *)&v48 = v48 / (double)ttall;
          *(_DWORD *)(v35 + 4) = LODWORD(v48);
          *(float *)&v46 = (double)(int)&v44[v36] / v46;
          *(_DWORD *)(v35 + 8) = LODWORD(v46);
          v51 = (double)(v38 + v47);
          v33 = right;
          *(float *)(v35 + 12) = v51 / v50;
          *(_DWORD *)(LODWORD(v33) + 16) = v45;
        }
        v52 = *(float *)&top;
        *(float **)((char *)top + (_DWORD)v85) = (float *)v99->m_PageList.m_Memory.m_pMemory[*(_DWORD *)(LODWORD(v33) + 16)].textureID[v97];
        v53 = i + 1;
        *(_DWORD *)LODWORD(v52) = v35;
        i = v53;
        top = (float **)(LODWORD(v52) + 4);
        if ( v53 >= numChars )
          break;
        v8 = (unsigned int)hFont;
      }
      v54 = numNewCharsa;
      if ( numNewCharsa > 0 )
      {
        if ( vgui_show_glyph_miss.m_pParent != nullptr && vgui_show_glyph_miss.m_pParent->m_Value.m_nValue != 0 )
        {
          v55 = alloca(numNewCharsa);
          numChars = (int)&v72;
          v56 = &v72;
          v57 = newChars;
          for ( wcha = (wchar_t *)numNewCharsa; wcha != nullptr; wcha = (wchar_t *)((char *)wcha - 1) )
          {
            v58 = v57->wch;
            if ( isprint(c: v57->wch) != 0 )
              *v56 = v58;
            else
              *v56 = 63;
            ++v56;
            ++v57;
          }
          v54 = numNewCharsa;
          v59 = (const char *)numChars;
          p_m_szName = &v98->m_szName;
          *v56 = 0;
          v61 = CUtlSymbol::String(this: p_m_szName);
          v62 = CFmtStrN<256>::CFmtStrN<256>(
                  this: &v75,
                  pszFormat: "Glyph Miss: FontHandle_t:0x%8.8x (%s), %s (0x%x)\n",
                  hFont,
                  v61,
                  v59,
                  *v59);
          _Plat_DebugString(a1: v62->m_szBuf);
        }
        v63 = 4 * maxNewCharTexels;
        numChars = 4 * maxNewCharTexels;
        v64 = alloca(4 * maxNewCharTexels);
        if ( v54 > 0 )
        {
          v65 = newEntries;
          v66 = newChars;
          wchb = (wchar_t *)numNewCharsa;
          while ( 1 )
          {
            _V_memset(dest: &v72, fill: 0, count: v63);
            ((void (__stdcall *)(_DWORD, int, int, char *))v98->GetCharRGBA)(
              a1: v66->wch,
              a2: v66->fontWide,
              a3: v66->fontTall,
              a4: &v72);
            if ( g_pMaterialSystem == nullptr && v63 > 0 )
            {
              v67 = v73;
              v68 = ((unsigned int)(v63 - 1) >> 2) + 1;
              do
              {
                *v67 = -1;
                *((_BYTE *)v67 - 1) = -1;
                v67 += 2;
                --v68;
              }
              while ( v68 != 0 );
            }
            v69 = TextureDictionary();
            v69->SetSubTextureRGBA(
              this: v69,
              a2: v99->m_PageList.m_Memory.m_pMemory[v65->page].textureID[v97],
              a3: v65->drawX,
              a4: v65->drawY,
              a5: (const unsigned __int8 *)&v72,
              a6: v66->fontWide,
              a7: v66->fontTall);
            ++v66;
            ++v65;
            wchb = (wchar_t *)((char *)wchb - 1);
            if ( wchb == nullptr )
              break;
            v63 = numChars;
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10016770
// Name: public: bool CFontTextureCache::GetTextureForChar(unsigned long,enum FontDrawType_t,wchar_t,int __near *,float __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontTextureCache::GetTextureForChar(
        CFontTextureCache *this,
        unsigned __int8 *font,
        FontDrawType_t type,
        wchar_t wch,
        int *textureID,
        float **texCoords)
{
  return CFontTextureCache::GetTextureForChars(
           this,
           hFont: font,
           type,
           &wch,
           (char *)textureID,
           (CFontTextureCache::Page_t *)texCoords,
           numChars: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1008F760
// Name: public: void CUtlMemory<struct CFontTextureCache::Page_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFontTextureCache::Page_t,int>::Grow(
        CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004BA8D0
// Name: public: void CFontTextureCache::SetPrefix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureCache::SetPrefix(CFontTextureCache *this, char *pTexturePagePrefix)
{
  CUtlString::operator=(this: &this->m_TexturePagePrefix, src: pTexturePagePrefix);
}

//------------------------------------------------------------------------------
// Address: 0x004BA8E0
// Name: private: static bool CFontTextureCache::CacheEntryLessFunc(struct CFontTextureCache::CacheEntry_t const __near &,struct CFontTextureCache::CacheEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CFontTextureCache::CacheEntryLessFunc(
        const CFontTextureCache::CacheEntry_t *lhs,
        const CFontTextureCache::CacheEntry_t *rhs)
{
  return lhs->font <= rhs->font && (lhs->font < rhs->font || lhs->wch < (unsigned int)rhs->wch);
}

//------------------------------------------------------------------------------
// Address: 0x004BA9E0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: m_pMemory,
                                                                                             a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB390
// Name: private: void CFontTextureCache::CreateFontMaterials(struct CFontTextureCache::Page_t __near &,class ITexture __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFontTextureCache::CreateFontMaterials(
        CFontTextureCache *this@<ecx>,
        CFontTextureCache::Page_t *page,
        ITexture *pFontTexture,
        bool bitmapFont,
        char a5)
{
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  char *v8; // eax
  CUtlString *p_m_TexturePagePrefix; // ebp
  IMaterialSystem_vtbl *v10; // ebx
  const char *v11; // eax
  int v12; // esi
  CTextureDictionary *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  char *v16; // eax
  const char *v17; // eax
  IMaterial *v18; // esi
  CTextureDictionary *v19; // eax
  CTextureDictionary_vtbl *v20; // edx
  CUtlString addmaterialName; // [esp+24h] [ebp-24h] BYREF
  CUtlString materialName; // [esp+34h] [ebp-14h] BYREF
  int v23; // [esp+44h] [ebp-4h]

  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "UnlitGeneric");
  else
    v7 = nullptr;
  KeyValues::SetInt(this: v7, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$ignorez", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$translucent", value: 1);
  v8 = (char *)pFontTexture->GetName(this: pFontTexture);
  KeyValues::SetString(this: v7, keyName: "$basetexture", value: v8);
  p_m_TexturePagePrefix = &this->m_TexturePagePrefix;
  CUtlString::operator+(
    this: p_m_TexturePagePrefix,
    result: (CUtlString *)&materialName.m_Storage.m_Memory.m_nAllocationCount,
    pOther: "__fontpage");
  v10 = g_pMaterialSystem->__vftable;
  v11 = CUtlString::operator char const *(this: (CUtlString *)&materialName.m_Storage.m_Memory.m_nAllocationCount);
  v12 = (int)v10->CreateMaterial(this: g_pMaterialSystem, a2: v11, a3: v7);
  (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 148))(a1: v12);
  v13 = TextureDictionary();
  v13->BindTextureToMaterial(this: v13, a2: page->textureID[0], a3: (IMaterial *)v12);
  (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 52))(a1: v12);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "UnlitGeneric");
  else
    v15 = nullptr;
  KeyValues::SetInt(this: v15, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$ignorez", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$translucent", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$additive", value: 1);
  v16 = (char *)pFontTexture->GetName(this: pFontTexture);
  KeyValues::SetString(this: v15, keyName: "$basetexture", value: v16);
  CUtlString::operator+(
    this: p_m_TexturePagePrefix,
    result: (CUtlString *)&addmaterialName.m_Storage.m_Memory.m_nGrowSize,
    pOther: "__fontpage_additive");
  v17 = CUtlString::operator char const *(this: (CUtlString *)&addmaterialName.m_Storage.m_Memory.m_nGrowSize);
  v18 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: v17, a3: v15);
  v18->Refresh(this: v18);
  v19 = TextureDictionary();
  v20 = v19->__vftable;
  if ( a5 != 0 )
    ((void (__thiscall *)(CTextureDictionary *, _DWORD))v20->BindTextureToMaterial)(a1: v19, a2: page->textureID[1]);
  else
    ((void (__thiscall *)(CTextureDictionary *, _DWORD, _DWORD))v20->BindTextureToMaterialReference)(
      a1: v19,
      a2: page->textureID[1],
      a3: page->textureID[0]);
  ((void (__thiscall *)(IMaterial *, IMaterial *))v18->DecrementReferenceCount)(a1: v18, a2: v18);
  materialName.m_Storage.m_Memory.m_pMemory = nullptr;
  if ( addmaterialName.m_Storage.m_nActualLength >= 0 )
  {
    if ( addmaterialName.m_Storage.m_Memory.m_nAllocationCount != 0 )
      ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
    addmaterialName.m_Storage.m_Memory.m_nGrowSize = 0;
  }
  v23 = 0;
  if ( materialName.m_Storage.m_nActualLength >= 0 && materialName.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)materialName.m_Storage.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x004BC660
// Name: public: void CFontTextureCache::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureCache::Clear(CFontTextureCache *this)
{
  int i; // edi
  CFontTextureCache::Page_t *m_pMemory; // eax
  CTexturePacker *pPackedFontTextureCache; // ebx
  unsigned int j; // edi

  CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_CharCache);
  for ( i = 0; i < this->m_PageList.m_Size; ++i )
  {
    m_pMemory = this->m_PageList.m_Memory.m_pMemory;
    pPackedFontTextureCache = m_pMemory[i].pPackedFontTextureCache;
    if ( pPackedFontTextureCache != nullptr )
    {
      CTexturePacker::~CTexturePacker(this: m_pMemory[i].pPackedFontTextureCache);
      free(pMem: pPackedFontTextureCache);
    }
  }
  this->m_PageList.m_Size = 0;
  this->m_CurrPage = -1;
  CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_FontPages.m_Tree);
  if ( this->m_FontPages.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_FontPages.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<CDmAttribute *>::LessFunc;
  for ( j = 0; j < 0x180; ++j )
  {
    free(pMem: this->m_CommonCharCache[j]);
    this->m_CommonCharCache[j] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BC710
// Name: private: bool CFontTextureCache::AllocatePageForChar(int,int,int __near &,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CFontTextureCache::AllocatePageForChar@<al>(
        CFontTextureCache *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int charWide,
        int charTall,
        int *pageIndex,
        int *drawX,
        int *drawY,
        int *twide,
        int *ttall)
{
  int m_CurrPage; // eax
  int v14; // edi
  CUtlVector<CFontTextureCache::Page_t,CUtlMemory<CFontTextureCache::Page_t,int> > *p_m_PageList; // ebx
  int inserted; // eax
  int v17; // eax
  CFontTextureCache::Page_t *v18; // ebp
  CTextureDictionary *v19; // eax
  CTexturePacker *v20; // eax
  CTexturePacker *v21; // eax
  const char *v22; // eax
  ITexture *v23; // edi
  char *v24; // esi
  _BYTE *v25; // eax
  int i; // ecx
  CTextureDictionary *v27; // eax
  int *p_x; // eax
  int v29; // [esp-Ch] [ebp-60h]
  Rect_t glpyhRect; // [esp+0h] [ebp-54h] BYREF
  char pTextureName[64]; // [esp+10h] [ebp-44h] BYREF
  __int16 nodeIndex; // [esp+5Ch] [ebp+8h]

  if ( charTall > 256 )
    return 0;
  m_CurrPage = this->m_CurrPage;
  v29 = a4;
  v14 = 0;
  *pageIndex = m_CurrPage;
  glpyhRect.y = 0;
  glpyhRect.width = 0;
  glpyhRect.height = charWide;
  *(_DWORD *)pTextureName = charTall;
  if ( m_CurrPage <= -1
    || (p_m_PageList = &this->m_PageList,
        (inserted = CTexturePacker::InsertRect(
                      this: this->m_PageList.m_Memory.m_pMemory[m_CurrPage].pPackedFontTextureCache,
                      texRect: (const Rect_t *)&glpyhRect.y,
                      nodeIndex: -1)) == -1) )
  {
    p_m_PageList = &this->m_PageList;
    v17 = CUtlVector<CFontTextureCache::Page_t,CUtlMemory<CFontTextureCache::Page_t,int>>::InsertBefore(
            this: &this->m_PageList,
            elem: this->m_PageList.m_Size);
    *pageIndex = v17;
    v18 = &this->m_PageList.m_Memory.m_pMemory[v17];
    this->m_CurrPage = v17;
    do
    {
      v19 = TextureDictionary();
      v18->textureID[v14++] = v19->CreateTexture(this: v19, a2: true);
    }
    while ( v14 < 2 );
    v20 = (CTexturePacker *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v20 != nullptr )
      v21 = CTexturePacker::CTexturePacker(this: v20, texWidth: 256, texHeight: 256, pixelGap: 1);
    else
      v21 = nullptr;
    v18->pPackedFontTextureCache = v21;
    nodeIndex = CTexturePacker::InsertRect(this: v21, texRect: (const Rect_t *)&glpyhRect.y, nodeIndex: -1);
    v22 = CUtlString::operator char const *(this: &this->m_TexturePagePrefix);
    V_snprintf(pDest: &pTextureName[4], maxLen: 0x40u, pFormat: "%s__font_page_%d", v22, nFontPageId);
    ++nFontPageId;
    if ( g_pMaterialSystem != nullptr )
    {
      v23 = g_pMaterialSystem->CreateProceduralTexture(
              this: g_pMaterialSystem,
              a2: &pTextureName[4],
              a3: "VGUI textures",
              a4: 256,
              a5: 256,
              a6: 0,
              a7: 264972);
      CFontTextureCache::CreateFontMaterials(this, page: v18, pFontTexture: v23, bitmapFont: false, a5: v29);
      v23->DecrementReferenceCount(this: v23);
    }
    v24 = (char *)((int (__thiscall *)(IMemAlloc *, int, int, int, int))_g_pMemAlloc->Alloc_2)(
                    a1: _g_pMemAlloc,
                    a2: 0x40000,
                    a3: v29,
                    a4: a3,
                    a5: a2);
    v25 = v24 + 1;
    for ( i = 0x10000; i != 0; --i )
    {
      v25[1] = -1;
      *v25 = -1;
      *(v25 - 1) = -1;
      v25[2] = 0;
      v25 += 4;
    }
    v27 = TextureDictionary();
    ((void (__thiscall *)(CTextureDictionary *, _DWORD, char *))v27->SetTextureRGBAEx)(
      a1: v27,
      a2: v18->textureID[0],
      a3: v24);
    if ( g_pMaterialSystem == nullptr )
      v18->textureID[1] = v18->textureID[0];
    if ( v24 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
    LOWORD(inserted) = nodeIndex;
  }
  p_x = &p_m_PageList->m_Memory.m_pMemory[*pageIndex].pPackedFontTextureCache->m_Tree.m_Memory.m_pMemory[(unsigned __int16)inserted].m_Element.rc.x;
  *drawX = *p_x;
  *drawY = p_x[1];
  *twide = 256;
  *ttall = 256;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004BC940
// Name: public: CFontTextureCache::CFontTextureCache(void)
// Source: json
//------------------------------------------------------------------------------
CFontTextureCache *__thiscall CFontTextureCache::CFontTextureCache(CFontTextureCache *this)
{
  this->m_CharCache.m_LessFunc = (bool (__cdecl *)(const CFontTextureCache::CacheEntry_t *, const CFontTextureCache::CacheEntry_t *))CFontTextureCache::CacheEntryLessFunc;
  this->m_CharCache.m_Elements.m_pMemory = nullptr;
  this->m_CharCache.m_Elements.m_nAllocationCount = 256;
  this->m_CharCache.m_Elements.m_nGrowSize = 0;
  this->m_CharCache.m_Elements.m_pMemory = (UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 9216);
  this->m_CharCache.m_NumElements = 0;
  this->m_CharCache.m_Root = -1;
  this->m_CharCache.m_FirstFree = -1;
  this->m_CharCache.m_LastAlloc.index = -1;
  this->m_CharCache.m_pElements = this->m_CharCache.m_Elements.m_pMemory;
  this->m_PageList.m_Memory.m_pMemory = nullptr;
  this->m_PageList.m_Memory.m_nAllocationCount = 0;
  this->m_PageList.m_Memory.m_nGrowSize = 0;
  this->m_PageList.m_Size = 0;
  this->m_PageList.m_pElements = nullptr;
  this->m_FontPages.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_FontPages.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_FontPages.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_FontPages.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_FontPages.m_Tree.m_Root = -1;
  this->m_FontPages.m_Tree.m_NumElements = 0;
  this->m_FontPages.m_Tree.m_FirstFree = -1;
  this->m_FontPages.m_Tree.m_LastAlloc.index = -1;
  this->m_FontPages.m_Tree.m_pElements = this->m_FontPages.m_Tree.m_Elements.m_pMemory;
  CUtlString::CUtlString(this: &this->m_TexturePagePrefix);
  _V_memset(dest: this, fill: nullptr, count: 0x600u);
  CFontTextureCache::Clear(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BCA30
// Name: public: CFontTextureCache::~CFontTextureCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureCache::~CFontTextureCache(CFontTextureCache *this)
{
  bool v2; // sf

  CFontTextureCache::Clear(this);
  v2 = this->m_TexturePagePrefix.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_TexturePagePrefix.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_TexturePagePrefix.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TexturePagePrefix.m_Storage.m_Memory.m_pMemory);
      this->m_TexturePagePrefix.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_TexturePagePrefix.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_FontPages.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_PageList);
  CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::~CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>(this: &this->m_CharCache);
}

//------------------------------------------------------------------------------
// Address: 0x004BCBB0
// Name: public: bool CFontTextureCache::GetTextureForChars(unsigned long,enum FontDrawType_t,wchar_t __near *,int __near *,float __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontTextureCache::GetTextureForChars(
        CFontTextureCache *this,
        unsigned __int8 *hFont,
        int type,
        wchar_t *wch,
        char *textureID,
        CFontTextureCache::Page_t *texCoords,
        int numChars)
{
  FontDrawType_t v7; // eax
  unsigned int v8; // ebx
  CFontManager *v9; // eax
  int v10; // eax
  CFontManager *v11; // eax
  int v13; // esi
  float *v14; // edi
  CFontManager *v15; // eax
  CBitmapFont *FontForChar; // eax
  CFontTextureCache *v17; // ecx
  int v18; // esi
  CTextureDictionary *v19; // eax
  __int16 v20; // ax
  ITexture *TexturePage; // eax
  char *v22; // ecx
  CFontManager *v23; // eax
  void *v24; // esp
  void *v25; // esp
  float **v26; // eax
  int v27; // edi
  unsigned __int16 v28; // ax
  unsigned __int16 v29; // si
  CFontManager *v30; // eax
  CWin32Font *v31; // eax
  CWin32Font *v32; // ebx
  float v33; // ecx
  float v34; // xmm1_4
  int v35; // esi
  int v36; // edi
  CWin32Font *v37; // ebx
  int v38; // ebx
  float **v39; // eax
  char *v40; // edx
  int v41; // ecx
  int *v42; // ecx
  int v43; // edx
  bool v44; // cc
  double v45; // xmm0_8
  char *v46; // eax
  int v47; // edx
  int v48; // ecx
  float v49; // xmm1_4
  double v50; // xmm1_8
  float v51; // xmm2_4
  double v52; // xmm0_8
  float v53; // eax
  int v54; // ecx
  int v55; // edi
  void *v56; // esp
  char *v57; // esi
  newChar_t *v58; // edi
  wchar_t v59; // bx
  const char *v60; // ebx
  CUtlSymbol *p_m_szName; // ecx
  char *v62; // eax
  CFmtStrN<256> *v63; // eax
  signed int v64; // ebx
  void *v65; // esp
  CFontTextureCache::GetTextureForChars::__l26::newPageEntry_t *v66; // edi
  newChar_t *v67; // esi
  _BYTE *v68; // eax
  unsigned int v69; // ecx
  CTextureDictionary *v70; // eax
  wchar_t v71; // [esp-4h] [ebp-144h]
  wchar_t v72; // [esp-4h] [ebp-144h]
  char v73; // [esp+0h] [ebp-140h] BYREF
  _BYTE v74[3]; // [esp+1h] [ebp-13Fh] BYREF
  int v75; // [esp+8h] [ebp-138h] BYREF
  CFmtStrN<256> v76; // [esp+Ch] [ebp-134h] BYREF
  CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t insert; // [esp+118h] [ebp-28h] BYREF
  CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t search; // [esp+124h] [ebp-1Ch] BYREF
  CFontTextureCache::CacheEntry_t cacheItem; // [esp+130h] [ebp-10h] BYREF
  int ttall; // [esp+14Ch] [ebp+Ch] BYREF
  int twide; // [esp+150h] [ebp+10h] BYREF
  int a; // [esp+154h] [ebp+14h] BYREF
  int wideChar; // [esp+158h] [ebp+18h]
  CFontTextureCache::GetTextureForChars::__l26::newPageEntry_t *newEntries; // [esp+15Ch] [ebp+1Ch]
  int c; // [esp+160h] [ebp+20h] BYREF
  char *v86; // [esp+164h] [ebp+24h]
  int b; // [esp+168h] [ebp+28h] BYREF
  int totalNewCharTexels; // [esp+16Ch] [ebp+2Ch]
  CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl*)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short> > *p_m_CharCache; // [esp+170h] [ebp+30h]
  int maxNewCharTexels; // [esp+174h] [ebp+34h]
  int i; // [esp+178h] [ebp+38h]
  float **top; // [esp+17Ch] [ebp+3Ch] BYREF
  int typePage; // [esp+180h] [ebp+40h]
  float right; // [esp+184h] [ebp+44h] BYREF
  int page; // [esp+188h] [ebp+48h] BYREF
  int drawY; // [esp+18Ch] [ebp+4Ch] BYREF
  int v97; // [esp+190h] [ebp+50h]
  newChar_t *newChars; // [esp+194h] [ebp+54h] BYREF
  CWin32Font *v99; // [esp+198h] [ebp+58h]
  CFontTextureCache *v100; // [esp+19Ch] [ebp+5Ch]
  int numNewChars; // [esp+1ACh] [ebp+6Ch]
  int numNewCharsa; // [esp+1ACh] [ebp+6Ch]
  wchar_t *wcha; // [esp+1B0h] [ebp+70h]
  wchar_t *wchb; // [esp+1B0h] [ebp+70h]

  v7 = type;
  v8 = (unsigned int)hFont;
  v100 = this;
  if ( type == 0 )
  {
    v9 = FontManager();
    v7 = CFontManager::IsFontAdditive(this: v9, font: (unsigned int)hFont) + 1;
  }
  v10 = v7 - 1;
  if ( v10 <= 1 )
    typePage = v10 < 0 ? 0 : v10;
  else
    typePage = 1;
  v11 = FontManager();
  if ( CFontManager::IsBitmapFont(this: v11, font: (unsigned int)hFont) )
  {
    if ( numChars > 256 )
      return 0;
    v13 = 0;
    numNewChars = 0;
    if ( numChars > 0 )
    {
      v14 = &sTexCoords[2];
      v97 = (char *)texCoords - textureID;
      while ( 1 )
      {
        v71 = wch[v13];
        v15 = FontManager();
        FontForChar = (CBitmapFont *)CFontManager::GetFontForChar(this: v15, font: v8, wch: v71);
        drawY = (int)FontForChar;
        if ( FontForChar == nullptr )
          break;
        CBitmapFont::GetCharCoords(
          this: FontForChar,
          ch: wch[v13],
          left: (float *)&newChars,
          (float *)&top,
          &right,
          bottom: (float *)&page);
        v17 = v100;
        *((_DWORD *)v14 - 2) = newChars;
        *((_DWORD *)v14 - 1) = top;
        *v14 = right;
        *((_DWORD *)v14 + 1) = page;
        search.elem.pPackedFontTextureCache = nullptr;
        search.key = v8;
        LOWORD(v8) = CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                       this: &v17->m_FontPages.m_Tree,
                       &search);
        if ( (unsigned __int16)v8 == 0xFFFF )
        {
          insert.key = (unsigned int)hFont;
          v18 = 0;
          insert.elem.pPackedFontTextureCache = nullptr;
          v8 = CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                 this: &v100->m_FontPages.m_Tree,
                 &insert);
          texCoords = &v100->m_FontPages.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
          do
          {
            v19 = TextureDictionary();
            v20 = v19->CreateTexture(this: v19, a2: false);
            texCoords->textureID[v18++] = v20;
          }
          while ( v18 < 2 );
          TexturePage = CBitmapFont::GetTexturePage(this: (CBitmapFont *)drawY);
          CFontTextureCache::CreateFontMaterials(
            this: v100,
            page: texCoords,
            pFontTexture: TexturePage,
            bitmapFont: true,
            a5: v73);
          v13 = numNewChars;
        }
        v22 = textureID;
        *(_DWORD *)&textureID[v97] = v14 - 2;
        ++v13;
        *(_DWORD *)v22 = v100->m_FontPages.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem.textureID[typePage];
        v14 += 4;
        numNewChars = v13;
        textureID = v22 + 4;
        if ( v13 >= numChars )
          return 1;
        v8 = (unsigned int)hFont;
      }
      return 0;
    }
  }
  else
  {
    v72 = *wch;
    v23 = FontManager();
    v99 = CFontManager::GetFontForChar(this: v23, font: (unsigned int)hFont, wch: v72);
    if ( v99 == nullptr )
      return 0;
    v24 = alloca(16 * numChars);
    newChars = (newChar_t *)&v73;
    v25 = alloca(12 * numChars);
    newEntries = (CFontTextureCache::GetTextureForChars::__l26::newPageEntry_t *)&v73;
    numNewCharsa = 0;
    maxNewCharTexels = 0;
    totalNewCharTexels = 0;
    i = 0;
    if ( numChars > 0 )
    {
      p_m_CharCache = &v100->m_CharCache;
      v26 = (float **)texCoords;
      texCoords = (CFontTextureCache::Page_t *)&v75;
      top = v26;
      v97 = (int)&v75;
      v86 = (char *)(textureID - (char *)v26);
      while ( 1 )
      {
        v27 = wch[i];
        wideChar = v27;
        cacheItem.font = v8;
        cacheItem.wch = v27;
        v28 = CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Find(
                this: p_m_CharCache,
                search: &cacheItem);
        v29 = v28;
        if ( v28 >= p_m_CharCache->m_Elements.m_nAllocationCount
          || v28 > p_m_CharCache->m_LastAlloc.index
          || CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links(
               this: p_m_CharCache,
               i: v28)->m_Left == v28 )
        {
          v30 = FontManager();
          v31 = CFontManager::GetFontForChar(this: v30, font: v8, wch: v27);
          v32 = v99;
          if ( v99 != v31 )
            return 0;
          memset(cacheItem.texCoords, 0, sizeof(cacheItem.texCoords));
          v29 = CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Insert(
                  this: p_m_CharCache,
                  insert: &cacheItem);
        }
        else
        {
          v32 = v99;
        }
        LODWORD(v33) = &v100->m_CharCache.m_Elements.m_pMemory[v29];
        v34 = *(float *)(LODWORD(v33) + 28);
        v35 = LODWORD(v33) + 20;
        right = v33;
        if ( v34 == 0.0 && *(float *)(LODWORD(v33) + 32) == 0.0 )
        {
          v32->GetCharABCWidths(this: v32, a2: (unsigned __int16)v27, a3: &a, a4: &b, a5: &c);
          v36 = b;
          if ( b <= 1 )
            v36 = 1;
          v37 = v99;
          if ( v99->GetHeight(this: v99) <= 1 )
            v38 = 1;
          else
            v38 = v37->GetHeight(this: v37);
          if ( (*((_DWORD *)v99 + 9) & 0x20000000) != 0 )
            v36 += c + a;
          if ( CFontTextureCache::AllocatePageForChar(
                 this: v100,
                 a2: v38,
                 a3: (int)&cacheItem.texCoords[1],
                 a4: v36,
                 charWide: v36,
                 charTall: v38,
                 pageIndex: &page,
                 drawX: (int *)&textureID,
                 &drawY,
                 &twide,
                 &ttall) == 0 )
            return 0;
          v39 = (float **)texCoords;
          v40 = textureID;
          *(_DWORD *)texCoords[-1].textureID = page;
          v41 = drawY;
          *(v39 - 1) = (float *)v40;
          LOWORD(v40) = wideChar;
          *v39 = (float *)v41;
          v42 = (int *)v97;
          *(_WORD *)(v97 - 8) = (_WORD)v40;
          v43 = totalNewCharTexels;
          v42[1] = 4 * totalNewCharTexels;
          v44 = maxNewCharTexels <= v36 * v38;
          *(v42 - 1) = v36;
          *v42 = v38;
          totalNewCharTexels = v36 * v38 + v43;
          if ( v44 )
            maxNewCharTexels = v36 * v38;
          v45 = (double)twide;
          v46 = textureID;
          ++numNewCharsa;
          texCoords = (CFontTextureCache::Page_t *)((char *)texCoords + 12);
          v47 = page;
          v97 = (int)(v42 + 4);
          v48 = drawY;
          v49 = (double)(int)textureID / (double)twide;
          *(float *)v35 = v49;
          v50 = (double)ttall;
          v51 = (double)v48 / (double)ttall;
          *(float *)(v35 + 4) = v51;
          *(float *)&v45 = (double)(int)&v46[v36] / v45;
          *(_DWORD *)(v35 + 8) = LODWORD(v45);
          v52 = (double)(v38 + v48);
          v33 = right;
          *(float *)&v52 = v52 / v50;
          *(_DWORD *)(v35 + 12) = LODWORD(v52);
          *(_DWORD *)(LODWORD(v33) + 16) = v47;
        }
        v53 = *(float *)&top;
        *(float **)((char *)top + (_DWORD)v86) = (float *)v100->m_PageList.m_Memory.m_pMemory[*(_DWORD *)(LODWORD(v33) + 16)].textureID[typePage];
        v54 = i + 1;
        *(_DWORD *)LODWORD(v53) = v35;
        i = v54;
        top = (float **)(LODWORD(v53) + 4);
        if ( v54 >= numChars )
          break;
        v8 = (unsigned int)hFont;
      }
      v55 = numNewCharsa;
      if ( numNewCharsa > 0 )
      {
        if ( vgui_show_glyph_miss.m_pParent->m_Value.m_nValue != 0 )
        {
          v56 = alloca(numNewCharsa);
          numChars = (int)&v73;
          v57 = &v73;
          v58 = newChars;
          for ( wcha = (wchar_t *)numNewCharsa; wcha != nullptr; wcha = (wchar_t *)((char *)wcha - 1) )
          {
            v59 = v58->wch;
            if ( isprint(c: v58->wch) != 0 )
              *v57 = v59;
            else
              *v57 = 63;
            ++v57;
            ++v58;
          }
          v55 = numNewCharsa;
          v60 = (const char *)numChars;
          p_m_szName = &v99->m_szName;
          *v57 = 0;
          v62 = CUtlSymbol::String(this: p_m_szName);
          v63 = CFmtStrN<256>::CFmtStrN<256>(
                  this: &v76,
                  pszFormat: "Glyph Miss: FontHandle_t:0x%8.8x (%s), %s\n",
                  hFont,
                  v62,
                  v60);
          _Plat_DebugString(a1: v63->m_szBuf);
        }
        v64 = 4 * maxNewCharTexels;
        numChars = 4 * maxNewCharTexels;
        v65 = alloca(4 * maxNewCharTexels);
        if ( v55 > 0 )
        {
          v66 = newEntries;
          v67 = newChars;
          wchb = (wchar_t *)numNewCharsa;
          while ( 1 )
          {
            _V_memset(dest: &v73, fill: nullptr, count: v64);
            ((void (__stdcall *)(_DWORD, int, int, char *))v99->GetCharRGBA)(
              a1: v67->wch,
              a2: v67->fontWide,
              a3: v67->fontTall,
              a4: &v73);
            if ( g_pMaterialSystem == nullptr && v64 > 0 )
            {
              v68 = v74;
              v69 = ((unsigned int)(v64 - 1) >> 2) + 1;
              do
              {
                v68[1] = -1;
                *v68 = -1;
                *(v68 - 1) = -1;
                v68 += 4;
                --v69;
              }
              while ( v69 != 0 );
            }
            v70 = TextureDictionary();
            v70->SetSubTextureRGBA(
              this: v70,
              a2: v100->m_PageList.m_Memory.m_pMemory[v66->page].textureID[typePage],
              a3: v66->drawX,
              a4: v66->drawY,
              a5: (const unsigned __int8 *)&v73,
              a6: v67->fontWide,
              a7: v67->fontTall);
            ++v67;
            ++v66;
            wchb = (wchar_t *)((char *)wchb - 1);
            if ( wchb == nullptr )
              break;
            v64 = numChars;
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD200
// Name: public: bool CFontTextureCache::GetTextureForChar(unsigned long,enum FontDrawType_t,wchar_t,int __near *,float __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontTextureCache::GetTextureForChar(
        CFontTextureCache *this,
        unsigned __int8 *font,
        FontDrawType_t type,
        wchar_t wch,
        int *textureID,
        float **texCoords)
{
  return CFontTextureCache::GetTextureForChars(
           this,
           hFont: font,
           type,
           &wch,
           (char *)textureID,
           (CFontTextureCache::Page_t *)texCoords,
           numChars: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004BD230
// Name: public: bool CFontTextureCache::GetTextureAndCoordsForChar(unsigned long,enum FontDrawType_t,wchar_t,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFontTextureCache::GetTextureAndCoordsForChar(
        CFontTextureCache *this,
        unsigned __int8 *font,
        FontDrawType_t type,
        wchar_t wch,
        int *textureID,
        float *texCoords)
{
  char result; // al
  float *v7; // ecx
  float *v8; // edx
  float *v9; // [esp+4h] [ebp-4h] BYREF

  v9 = nullptr;
  result = CFontTextureCache::GetTextureForChars(
             this,
             hFont: font,
             type,
             &wch,
             (char *)textureID,
             texCoords: (CFontTextureCache::Page_t *)&v9,
             numChars: 1);
  v7 = v9;
  if ( v9 != nullptr )
  {
    v8 = texCoords;
    *texCoords = *v9;
    v8[1] = v7[1];
    v8[2] = v7[2];
    v8[3] = v7[3];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BA920
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CFontTextureCache::CacheEntry_t,unsigned short,bool (*)(struct CFontTextureCache::CacheEntry_t const __near &,struct CFontTextureCache::CacheEntry_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *__thiscall CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl*)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short> *)&`CUtlRBTree<CFontTextureCache::CacheEntry_t,unsigned short,bool (__cdecl *)(CFontTextureCache::CacheEntry_t const &,CFontTextureCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CFontTextureCache::CacheEntry_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x004BA980
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<unsigned long,struct CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned long,struct CFontTextureCache::Page_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned long,struct CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,CFontTextureCache::Page_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

} // namespace vgui_perftest
