// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuisystemsurface.cpp
// Functions: 37
// ============================================================

#include "vgui2\game_controls\gameuisystemsurface.h"

//------------------------------------------------------------------------------
// Address: 0x0040F9B0
// Name: void SimpleCodec::DecodeBuffer(unsigned char __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SimpleCodec::DecodeBuffer(unsigned __int8 *pvBuffer, int *numBytes)
{
  unsigned __int8 *v2; // ecx
  unsigned __int8 v3; // al
  int v4; // esi
  bool v5; // zf
  char v6; // al
  int v7; // edi
  char v8; // dl
  unsigned __int8 *v9; // esi
  int i; // esi
  unsigned __int8 v11; // al

  v2 = pvBuffer;
  v3 = pvBuffer[*numBytes - 1];
  v4 = *numBytes - v3;
  v5 = v3 == 1;
  v6 = v3 - 1;
  *numBytes = v4;
  v7 = v4;
  v8 = -89;
  v9 = &pvBuffer[v4];
  if ( !v5 )
  {
    do
    {
      --v6;
      v8 ^= *v9++ - 89;
    }
    while ( v6 != 0 );
  }
  for ( i = v7; i > 0; ++v2 )
  {
    v11 = v8 ^ *v2;
    --i;
    v8 = *v2 - 89;
    *v2 = v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FA30
// Name: public: virtual enum InitReturnVal_t CGameUISystemSurface::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameUISystemSurface::Init(CGameUISystemSurface *this)
{
  CFontManager *v3; // eax
  char language[68]; // [esp+8h] [ebp-44h] BYREF

  if ( this->m_bIsInitialized )
    return 1;
  if ( !g_pVGuiSystem->GetRegistryString(
          this: g_pVGuiSystem,
          a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
          a3: &language[4],
          a4: 63) )
    V_strncpy(pDest: &language[4], pSrc: "english", maxLen: 64);
  v3 = FontManager();
  CFontManager::SetLanguage(this: v3, pLanguage: &language[4]);
  this->m_bIsInitialized = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FAA0
// Name: public: virtual void CGameUISystemSurface::ClearTemporaryFontCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemSurface::ClearTemporaryFontCache(CGameUISystemSurface *this)
{
  CFontManager *v1; // eax

  v1 = FontManager();
  CSteamApplication::PostShutdown(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0040FAB0
// Name: public: virtual char const __near * CGameUISystemSurface::GetFontName(unsigned long)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUISystemSurface::GetFontName(CGameUISystemSurface *this, unsigned int font)
{
  CFontManager *v2; // eax

  v2 = FontManager();
  return CFontManager::GetFontName(this: v2, font);
}

//------------------------------------------------------------------------------
// Address: 0x0040FAD0
// Name: public: virtual void CGameUISystemSurface::ResetFontCaches(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemSurface::ResetFontCaches(CGameUISystemSurface *this)
{
  CFontTextureCache::Clear(this: &g_FontTextureCache);
  g_pGameUISchemeManager->ReloadFonts(this: g_pGameUISchemeManager, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x0040FAF0
// Name: public: virtual bool CGameUISystemSurface::SupportsFontFeature(enum FontFeature_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUISystemSurface::SupportsFontFeature(CGameUISystemSurface *this, FontFeature_t feature)
{
  return feature > 0 && (feature <= FONT_FEATURE_DROPSHADOW_FONTS || feature == FONT_FEATURE_OUTLINE_FONTS);
}

//------------------------------------------------------------------------------
// Address: 0x0040FB10
// Name: public: virtual void CGameUISystemSurface::PrecacheFontCharacters(unsigned long,wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemSurface::PrecacheFontCharacters(
        CGameUISystemSurface *this,
        unsigned int font,
        wchar_t *pCharacterString)
{
  wchar_t *v3; // edi
  int v4; // esi
  void *v5; // esp
  void *v6; // esp
  float *v7[3]; // [esp+0h] [ebp-Ch] BYREF

  v3 = pCharacterString;
  if ( pCharacterString == nullptr || *pCharacterString == 0 )
    v3 = L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.!:-/%";
  v4 = 0;
  if ( *v3 != 0 )
  {
    do
      ++v4;
    while ( v3[v4] != 0 );
  }
  v5 = alloca(4 * v4);
  v6 = alloca(4 * v4);
  CFontTextureCache::GetTextureForChars(
    this: &g_FontTextureCache,
    hFont: font,
    type: FONT_DRAW_DEFAULT,
    wch: v3,
    textureID: (int *)v7,
    texCoords: v7,
    numChars: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0040FB80
// Name: public: virtual class IMaterial __near * CGameUISystemSurface::GetTextureForChar(struct FontCharRenderInfo __near &,float __near * __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CGameUISystemSurface::GetTextureForChar(
        CGameUISystemSurface *this,
        FontCharRenderInfo *info,
        float **texCoords)
{
  ITextureDictionary *v4; // eax

  if ( !CFontTextureCache::GetTextureForChar(
          this: &g_FontTextureCache,
          font: info->currentFont,
          type: info->drawType,
          wch: info->ch,
          textureID: &info->textureId,
          texCoords) )
    return nullptr;
  v4 = TextureDictionary();
  return v4->GetTextureMaterial(this: v4, a2: info->textureId);
}

//------------------------------------------------------------------------------
// Address: 0x0040FBD0
// Name: public: virtual class IMaterial __near * CGameUISystemSurface::GetTextureAndCoordsForChar(struct FontCharRenderInfo __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CGameUISystemSurface::GetTextureAndCoordsForChar(
        CGameUISystemSurface *this,
        FontCharRenderInfo *info,
        float *texCoords)
{
  ITextureDictionary *v4; // eax

  if ( !CFontTextureCache::GetTextureAndCoordsForChar(
          this: &g_FontTextureCache,
          font: info->currentFont,
          type: info->drawType,
          wch: info->ch,
          textureID: &info->textureId,
          texCoords) )
    return nullptr;
  v4 = TextureDictionary();
  return v4->GetTextureMaterial(this: v4, a2: info->textureId);
}

//------------------------------------------------------------------------------
// Address: 0x0040FC20
// Name: public: virtual bool CGameUISystemSurface::GetUnicodeCharRenderPositions(struct FontCharRenderInfo __near &,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUISystemSurface::GetUnicodeCharRenderPositions(
        CGameUISystemSurface *this,
        FontCharRenderInfo *info,
        Vector2D *pPositions)
{
  unsigned int currentFont; // eax
  bool result; // al
  int v7; // eax
  unsigned int v8; // ecx
  int *p_abcB; // ebx
  int *p_abcA; // ebp
  CFontManager *v11; // eax
  FontDrawType_t drawType; // ecx
  unsigned int v13; // edx
  int v14; // ebx
  int v15; // ebp
  wchar_t ch; // [esp-4h] [ebp-20h]
  unsigned int v17; // [esp+4h] [ebp-18h]
  float *v18; // [esp+18h] [ebp-4h] BYREF
  bool bUnderlined; // [esp+20h] [ebp+4h]

  currentFont = info->currentFont;
  info->valid = false;
  if ( currentFont == 0 )
    return false;
  info->valid = true;
  v7 = this->GetFontTall(this, a2: currentFont);
  v8 = info->currentFont;
  info->fontTall = v7;
  p_abcB = &info->abcB;
  p_abcA = &info->abcA;
  this->GetCharABCwide(this, a2: v8, a3: info->ch, a4: &info->abcA, a5: &info->abcB, a6: &info->abcC);
  v17 = info->currentFont;
  v11 = FontManager();
  bUnderlined = CFontManager::GetFontUnderlined(this: v11, font: v17);
  if ( !bUnderlined )
    info->x += *p_abcA;
  drawType = info->drawType;
  v13 = info->currentFont;
  info->textureId = 0;
  ch = info->ch;
  v18 = nullptr;
  result = CFontTextureCache::GetTextureForChar(
             this: &g_FontTextureCache,
             font: v13,
             type: drawType,
             wch: ch,
             textureID: &info->textureId,
             texCoords: &v18);
  if ( result )
  {
    v14 = *p_abcB;
    if ( bUnderlined )
    {
      v15 = *p_abcA;
      v14 += v15 + info->abcC;
      info->x -= v15;
    }
    pPositions->x = (float)info->x;
    pPositions->y = (float)info->y;
    pPositions[1].x = (float)(v14 + info->x);
    pPositions[1].y = (float)info->y;
    pPositions[2].x = (float)(v14 + info->x);
    pPositions[2].y = (float)(info->fontTall + info->y);
    pPositions[3].x = (float)info->x;
    pPositions[3].y = (float)(info->fontTall + info->y);
    return info->valid;
  }
  else
  {
    info->valid = false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FD50
// Name: public: virtual bool CGameUISystemSurface::SetBitmapFontGlyphSet(unsigned long,char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUISystemSurface::SetBitmapFontGlyphSet(
        CGameUISystemSurface *this,
        unsigned int font,
        const char *windowsFontName,
        float scalex,
        float scaley,
        int flags)
{
  CFontManager *v6; // eax

  v6 = FontManager();
  return CFontManager::SetBitmapFontGlyphSet(this: v6, font, windowsFontName, scalex, scaley, flags);
}

//------------------------------------------------------------------------------
// Address: 0x0040FD80
// Name: public: virtual unsigned long CGameUISystemSurface::CreateFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CGameUISystemSurface::CreateFont(CGameUISystemSurface *this)
{
  CFontManager *v1; // eax

  v1 = FontManager();
  return CFontManager::CreateFont(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0040FD90
// Name: public: virtual bool CGameUISystemSurface::SetFontGlyphSet(unsigned long,char const __near *,int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUISystemSurface::SetFontGlyphSet(
        CGameUISystemSurface *this,
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
  CFontManager *v10; // eax

  v10 = FontManager();
  return CFontManager::SetFontGlyphSet(
           this: v10,
           font,
           windowsFontName,
           tall,
           weight,
           blur,
           scanlines,
           flags,
           nRangeMin,
           nRangeMax);
}

//------------------------------------------------------------------------------
// Address: 0x0040FDD0
// Name: public: virtual int CGameUISystemSurface::GetFontTall(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameUISystemSurface::GetFontTall(CGameUISystemSurface *this, unsigned int font)
{
  CFontManager *v2; // eax

  v2 = FontManager();
  return CFontManager::GetFontTall(this: v2, font);
}

//------------------------------------------------------------------------------
// Address: 0x0040FDF0
// Name: public: virtual void CGameUISystemSurface::GetCharABCwide(unsigned long,int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemSurface::GetCharABCwide(
        CGameUISystemSurface *this,
        unsigned int font,
        int ch,
        int *a,
        int *b,
        int *c)
{
  CFontManager *v6; // eax

  v6 = FontManager();
  CFontManager::GetCharABCwide(this: v6, font, ch, a, b, c);
}

//------------------------------------------------------------------------------
// Address: 0x0040FE20
// Name: public: virtual int CGameUISystemSurface::GetCharacterWidth(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameUISystemSurface::GetCharacterWidth(CGameUISystemSurface *this, unsigned int font, int ch)
{
  CFontManager *v3; // eax

  v3 = FontManager();
  return CFontManager::GetCharacterWidth(this: v3, font, ch);
}

//------------------------------------------------------------------------------
// Address: 0x0040FE40
// Name: public: virtual class IMaterial __near * CGameUISystemSurface::GetMaterial(int)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CGameUISystemSurface::GetMaterial(CGameUISystemSurface *this, int textureId)
{
  ITextureDictionary *v2; // eax

  v2 = TextureDictionary();
  return v2->GetTextureMaterial(this: v2, a2: textureId);
}

//------------------------------------------------------------------------------
// Address: 0x0040FE50
// Name: public: virtual struct ResourceBinding_t<class CTextureBits> const __near * CGameUISystemSurface::GetTextureHandle(int)
// Source: rtti_class
//------------------------------------------------------------------------------
const ResourceBinding_t<CTextureBits> *__thiscall CGameUISystemSurface::GetTextureHandle(
        CGameUISystemSurface *this,
        int textureId)
{
  ITextureDictionary *v2; // eax

  v2 = TextureDictionary();
  return v2->GetTextureHandle(this: v2, a2: textureId);
}

//------------------------------------------------------------------------------
// Address: 0x0040FE60
// Name: public: virtual void CGameUISystemSurface::SetLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemSurface::SetLanguage(CGameUISystemSurface *this, const char *pLanguage)
{
  CFontManager *v2; // eax

  v2 = FontManager();
  CFontManager::SetLanguage(this: v2, pLanguage);
}

//------------------------------------------------------------------------------
// Address: 0x0040FE80
// Name: public: virtual char const __near * CGameUISystemSurface::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUISystemSurface::GetLanguage(CGameUISystemSurface *this)
{
  CFontManager *v1; // eax

  v1 = FontManager();
  return CFontManager::GetLanguage(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0040FE90
// Name: public: struct GameUIVertex_t __near & GameUIVertex_t::operator=(struct GameUIVertex_t const __near &)
// Source: json
//------------------------------------------------------------------------------
GameUIVertex_t *__thiscall GameUIVertex_t::operator=(GameUIVertex_t *this, const GameUIVertex_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040FEC0
// Name: bool ValveFont::DecodeFont(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ValveFont::DecodeFont(CUtlBuffer *buffer)
{
  int v1; // eax
  unsigned int v2; // edi
  unsigned __int8 *m_pMemory; // ebx
  unsigned __int8 *v5; // eax
  unsigned int v6; // ecx
  const char *v7; // edx
  int v8; // esi
  unsigned int v9; // ecx
  unsigned __int8 *v10; // edx
  unsigned __int8 *v11; // eax
  unsigned int v12; // ecx
  unsigned __int8 *v13; // edx
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // edx
  unsigned __int8 *v16; // eax
  int v17; // eax
  int numBytes; // [esp+Ch] [ebp-4h] BYREF

  numBytes = buffer->m_Put;
  v1 = strlen("VFONT1");
  v2 = v1;
  if ( numBytes <= v1 )
    return 0;
  m_pMemory = buffer->m_Memory.m_pMemory;
  v5 = &buffer->m_Memory.m_pMemory[numBytes - v1];
  v6 = v2;
  v7 = "VFONT1";
  if ( v2 < 4 )
  {
LABEL_6:
    if ( v6 == 0 )
    {
LABEL_16:
      v17 = 0;
      goto LABEL_17;
    }
  }
  else
  {
    while ( *(_DWORD *)v5 == *(_DWORD *)v7 )
    {
      v6 -= 4;
      v7 += 4;
      v5 += 4;
      if ( v6 < 4 )
        goto LABEL_6;
    }
  }
  v8 = *v5 - *(unsigned __int8 *)v7;
  if ( v8 == 0 )
  {
    v9 = v6 - 1;
    v10 = (unsigned __int8 *)(v7 + 1);
    v11 = v5 + 1;
    if ( v9 == 0 )
      goto LABEL_16;
    v8 = *v11 - *v10;
    if ( v8 == 0 )
    {
      v12 = v9 - 1;
      v13 = v10 + 1;
      v14 = v11 + 1;
      if ( v12 == 0 )
        goto LABEL_16;
      v8 = *v14 - *v13;
      if ( v8 == 0 )
      {
        v15 = v13 + 1;
        v16 = v14 + 1;
        if ( v12 == 1 )
          goto LABEL_16;
        v8 = *v16 - *v15;
        if ( v8 == 0 )
          goto LABEL_16;
      }
    }
  }
  v17 = 1;
  if ( v8 <= 0 )
    v17 = -1;
LABEL_17:
  if ( v17 != 0 )
    return 0;
  numBytes -= v2;
  SimpleCodec::DecodeBuffer(pvBuffer: m_pMemory, &numBytes);
  CUtlBuffer::SeekPut(this: buffer, type: SEEK_HEAD, offset: numBytes);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FFB0
// Name: public: bool CDynamicVertexData<struct GameUIVertex_t>::Lock(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDynamicVertexData<GameUIVertex_t>::Lock(CDynamicVertexData<GameUIVertex_t> *this)
{
  int v2; // edi
  int result; // eax
  GameUIVertex_t *v4; // [esp+Ch] [ebp-4h] BYREF

  v2 = (2 * *((_DWORD *)&this->CVertexData<GameUIVertex_t> + 12)) >> 1;
  result = ((int (__thiscall *)(IRenderContext *, const ResourceBinding_t<CRenderBufferBits> *, int, GameUIVertex_t **))this->m_pRenderContext->LockVertexBuffer)(
             a1: this->m_pRenderContext,
             a2: this->m_hVertexBuffer,
             a3: 24 * v2,
             a4: &v4);
  this->m_nVertexCount = 0;
  this->m_nVertexIncrement = (_BYTE)result != 0;
  this->m_nMaxVertexCount = v2 * ((_BYTE)result != 0);
  this->m_pMemory = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410000
// Name: private: void CDynamicIndexData<unsigned short>::Init(class IRenderContext __near *,int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicIndexData<unsigned short>::Init(
        CDynamicIndexData<unsigned short> *this,
        IRenderContext *pRenderContext,
        int nIndexCount,
        int nMaxInstanceCount,
        const char *pDebugName,
        const char *pBudgetGroup)
{
  const ResourceBinding_t<CRenderBufferBits> *(__thiscall *CreateDynamicIndexBuffer)(IRenderContext *, const BufferDesc_t *, int); // edx
  const ResourceBinding_t<CRenderBufferBits> *v8; // eax
  BufferDesc_t indexDesc; // [esp+4h] [ebp-14h] BYREF
  const char *v10; // [esp+14h] [ebp-4h]

  indexDesc.m_pBudgetGroupName = pDebugName;
  v10 = pBudgetGroup;
  CreateDynamicIndexBuffer = pRenderContext->CreateDynamicIndexBuffer;
  indexDesc.m_pDebugName = (const char *)2;
  indexDesc.m_nElementSizeInBytes = nIndexCount;
  v8 = CreateDynamicIndexBuffer(
         this: pRenderContext,
         a2: (const BufferDesc_t *)&indexDesc.m_nElementSizeInBytes,
         a3: nMaxInstanceCount);
  *((_DWORD *)&this->CIndexData<unsigned short> + 6) ^= (nIndexCount
                                                       ^ *((_DWORD *)&this->CIndexData<unsigned short> + 6))
                                                      & 0x7FFFFFFF;
  this->m_hIndexBuffer = v8;
  _InterlockedExchangeAdd(&v8->m_nRefCount.m_value, 1u);
}

//------------------------------------------------------------------------------
// Address: 0x00410100
// Name: public: virtual void CGameUISystemSurface::DrawFontTexture(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameUISystemSurface::DrawFontTexture(
        CGameUISystemSurface *this@<ecx>,
        int a2@<esi>,
        int textureId,
        int xPos,
        int yPos,
        int a6)
{
  IMaterial *v6; // ebp
  int v7; // esi
  IMesh *v8; // ebp
  ITextureDictionary *v9; // eax
  unsigned __int8 *v10; // eax
  float *v11; // eax
  float *v12; // eax
  unsigned __int8 *v13; // eax
  float *v14; // eax
  float *v15; // eax
  float v16; // xmm2_4
  unsigned __int8 *v17; // eax
  float *v18; // eax
  float *v19; // eax
  unsigned __int8 *v20; // eax
  int m_VertexSize_Position; // ecx
  float *v22; // eax
  float *m_pCurrPosition; // edx
  float *v24; // eax
  unsigned __int16 *m_pIndices; // edi
  int v26; // eax
  IMaterial *v27; // [esp+1Ch] [ebp-200h]
  int wide; // [esp+2Ch] [ebp-1F0h] BYREF
  CMeshBuilder meshBuilder; // [esp+30h] [ebp-1ECh] BYREF

  v6 = this->GetMaterial(this, a2: textureId);
  if ( v6 != nullptr )
  {
    v7 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    v27 = v6;
    v8 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v7 + 228))(a1: v7, a2: 1, a3: 0, a4: 0);
    if ( v8 != nullptr )
    {
      v9 = TextureDictionary();
      ((void (__thiscall *)(ITextureDictionary *, int, CMeshBuilder *, int *, IMaterial *))v9->GetTextureSize)(
        a1: v9,
        a2: textureId,
        a3: &meshBuilder,
        a4: &wide,
        a5: v27);
      CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneMatrixIndex);
      CMeshBuilder::Begin(
        this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneMatrixIndex,
        pMesh: v8,
        type: 7,
        numPrimitives: 1);
      v10 = meshBuilder.m_VertexBuilder.m_pCurrColor + 4;
      *(float *)meshBuilder.m_VertexBuilder.m_pCurrColor = (float)yPos;
      *(float *)v10 = (float)a6;
      *((_DWORD *)v10 + 1) = 0;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = NAN;
      v11 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
      v11[1] = 0.0;
      v12 = ++meshBuilder.m_VertexBuilder.m_pCurrNormal;
      if ( (int)meshBuilder.m_VertexBuilder.m_pCurrNormal > (int)meshBuilder.m_VertexBuilder.m_pCurrPosition )
        meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
      meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex;
      v13 = meshBuilder.m_VertexBuilder.m_pCurrColor + 4;
      *(float *)meshBuilder.m_VertexBuilder.m_pCurrColor = (float)(yPos + meshBuilder.m_VertexSize_BoneWeight);
      *(float *)v13 = (float)a6;
      *((_DWORD *)v13 + 1) = 0;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = NAN;
      v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 1.0;
      v14[1] = 0.0;
      v15 = ++meshBuilder.m_VertexBuilder.m_pCurrNormal;
      if ( (int)meshBuilder.m_VertexBuilder.m_pCurrNormal > (int)meshBuilder.m_VertexBuilder.m_pCurrPosition )
        meshBuilder.m_VertexBuilder.m_pCurrPosition = v15;
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
      meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex;
      v16 = (float)(a6 + meshBuilder.m_VertexSize_Position);
      v17 = meshBuilder.m_VertexBuilder.m_pCurrColor + 4;
      *(float *)meshBuilder.m_VertexBuilder.m_pCurrColor = (float)(yPos + meshBuilder.m_VertexSize_BoneWeight);
      *(float *)v17 = v16;
      *((_DWORD *)v17 + 1) = 0;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = NAN;
      v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 1.0;
      v18[1] = 1.0;
      v19 = ++meshBuilder.m_VertexBuilder.m_pCurrNormal;
      if ( (int)meshBuilder.m_VertexBuilder.m_pCurrNormal > (int)meshBuilder.m_VertexBuilder.m_pCurrPosition )
        meshBuilder.m_VertexBuilder.m_pCurrPosition = v19;
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      v20 = &meshBuilder.m_VertexBuilder.m_pCurrColor[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex];
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
      m_VertexSize_Position = meshBuilder.m_VertexSize_Position;
      meshBuilder.m_VertexBuilder.m_pCurrColor = v20;
      *(float *)v20 = (float)yPos;
      v20 += 4;
      *(float *)v20 = (float)(a6 + m_VertexSize_Position);
      *((_DWORD *)v20 + 1) = 0;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = NAN;
      v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
      v22[1] = 1.0;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v24 = ++meshBuilder.m_VertexBuilder.m_pCurrNormal;
      if ( (int)meshBuilder.m_VertexBuilder.m_pCurrNormal > (int)meshBuilder.m_VertexBuilder.m_pCurrPosition )
      {
        m_pCurrPosition = v24;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
      }
      meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex;
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
      if ( LOBYTE(meshBuilder.m_IndexBuilder.m_nOffset) != 0 )
      {
        m_pIndices = meshBuilder.m_IndexBuilder.m_pIndices;
        v26 = CMeshBuilder::IndicesFromVertices(
                this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneMatrixIndex,
                type: (MaterialPrimitiveType_t)meshBuilder.m_IndexBuilder.m_pIndices,
                nVertexCount: (int)m_pCurrPosition);
        CIndexBuilder::GenerateIndices(
          this: (CIndexBuilder *)&meshBuilder.m_IndexBuilder.m_nFirstIndex,
          primitiveType: (MaterialPrimitiveType_t)m_pIndices,
          nIndexCount: v26);
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      }
      (*(void (__thiscall **)(_DWORD, float *, int))(**(_DWORD **)&meshBuilder.m_bGenerateIndices + 80))(
        a1: *(_DWORD *)&meshBuilder.m_bGenerateIndices,
        a2: m_pCurrPosition,
        a3: meshBuilder.m_IndexBuilder.m_nCurrentIndex);
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify = 0;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = -1;
      meshBuilder.m_Type = MATERIAL_POINTS;
      v8->Draw_2(this: v8, a2: -1, a3: 0);
      CMeshBuilder::~CMeshBuilder(this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight);
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410910
// Name: public: CDynamicVertexData<struct GameUIVertex_t>::CDynamicVertexData<struct GameUIVertex_t>(class IRenderContext __near *,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDynamicVertexData<GameUIVertex_t> *__thiscall CDynamicVertexData<GameUIVertex_t>::CDynamicVertexData<GameUIVertex_t>(
        CDynamicVertexData<GameUIVertex_t> *this,
        IRenderContext *pRenderContext,
        int nVertexCount,
        const char *pDebugName,
        const char *pBudgetGroup)
{
  IRenderDevice *v6; // eax
  IRenderContext_vtbl *v7; // eax
  const ResourceBinding_t<CRenderBufferBits> *(__thiscall *CreateDynamicVertexBuffer)(IRenderContext *, const BufferDesc_t *); // edx
  const ResourceBinding_t<CRenderBufferBits> *v9; // eax
  BufferDesc_t vertexDesc; // [esp+8h] [ebp-24h] BYREF
  const char *v12; // [esp+18h] [ebp-14h]
  BufferDesc_t v13; // [esp+1Ch] [ebp-10h] BYREF

  *((_DWORD *)&this->CVertexData<GameUIVertex_t> + 12) &= ~0x80000000;
  this->m_pRenderContext = pRenderContext;
  this->m_hVertexBuffer = nullptr;
  v6 = pRenderContext->GetDevice(this: pRenderContext);
  v6->GetVertexBufferDesc(this: v6, a2: nullptr, a3: &v13);
  *((_DWORD *)&this->CVertexData<GameUIVertex_t> + 12) ^= (v13.m_nElementCount
                                                         ^ *((_DWORD *)&this->CVertexData<GameUIVertex_t> + 12))
                                                        & 0x7FFFFFFF;
  v7 = pRenderContext->__vftable;
  vertexDesc.m_pBudgetGroupName = pDebugName;
  v12 = pBudgetGroup;
  CreateDynamicVertexBuffer = v7->CreateDynamicVertexBuffer;
  vertexDesc.m_pDebugName = (const char *)24;
  vertexDesc.m_nElementSizeInBytes = nVertexCount;
  v9 = CreateDynamicVertexBuffer(this: pRenderContext, a2: (const BufferDesc_t *)&vertexDesc.m_nElementSizeInBytes);
  *((_DWORD *)&this->CVertexData<GameUIVertex_t> + 12) ^= (nVertexCount
                                                         ^ *((_DWORD *)&this->CVertexData<GameUIVertex_t> + 12))
                                                        & 0x7FFFFFFF;
  this->m_hVertexBuffer = v9;
  _InterlockedExchangeAdd(&v9->m_nRefCount.m_value, 1u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004109C0
// Name: public: CDynamicVertexData<struct GameUIVertex_t>::~CDynamicVertexData<struct GameUIVertex_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicVertexData<GameUIVertex_t>::~CDynamicVertexData<GameUIVertex_t>(
        CDynamicVertexData<GameUIVertex_t> *this)
{
  const ResourceBinding_t<CRenderBufferBits> *m_hVertexBuffer; // eax
  const ResourceBinding_t<CRenderBufferBits> *v3; // eax
  IRenderDevice *v4; // eax

  m_hVertexBuffer = this->m_hVertexBuffer;
  if ( m_hVertexBuffer != nullptr )
  {
    this->m_pRenderContext->DestroyDynamicVertexBuffer(this: this->m_pRenderContext, a2: m_hVertexBuffer);
    _InterlockedExchangeAdd(&this->m_hVertexBuffer->m_nRefCount.m_value, 0xFFFFFFFF);
    this->m_hVertexBuffer = nullptr;
  }
  if ( *((int *)&this->CVertexData<GameUIVertex_t> + 12) < 0 )
  {
    v3 = this->m_hVertexBuffer;
    if ( v3 != nullptr )
    {
      _InterlockedExchangeAdd(&v3->m_nRefCount.m_value, 0xFFFFFFFF);
      v4 = this->m_pRenderContext->GetDevice(this: this->m_pRenderContext);
      v4->DestroyVertexBuffer(this: v4, a2: this->m_hVertexBuffer);
      *((_DWORD *)&this->CVertexData<GameUIVertex_t> + 12) &= ~0x80000000;
      this->m_hVertexBuffer = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410A30
// Name: public: CDynamicIndexData<unsigned short>::CDynamicIndexData<unsigned short>(class IRenderContext __near *,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDynamicIndexData<unsigned short> *__thiscall CDynamicIndexData<unsigned short>::CDynamicIndexData<unsigned short>(
        CDynamicIndexData<unsigned short> *this,
        IRenderContext *pRenderContext,
        int nIndexCount,
        const char *pDebugName,
        const char *pBudgetGroup)
{
  IRenderDevice *v6; // eax
  BufferDesc_t v8; // [esp+8h] [ebp-10h] BYREF

  *((_DWORD *)&this->CIndexData<unsigned short> + 6) &= ~0x80000000;
  this->m_pRenderContext = pRenderContext;
  this->m_hIndexBuffer = nullptr;
  v6 = pRenderContext->GetDevice(this: pRenderContext);
  v6->GetIndexBufferDesc(this: v6, a2: nullptr, a3: &v8);
  *((_DWORD *)&this->CIndexData<unsigned short> + 6) ^= (v8.m_nElementCount
                                                       ^ *((_DWORD *)&this->CIndexData<unsigned short> + 6))
                                                      & 0x7FFFFFFF;
  CDynamicIndexData<unsigned short>::Init(
    this,
    pRenderContext,
    nIndexCount,
    nMaxInstanceCount: 0,
    pDebugName,
    pBudgetGroup);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410AA0
// Name: public: CDynamicIndexData<unsigned short>::~CDynamicIndexData<unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicIndexData<unsigned short>::~CDynamicIndexData<unsigned short>(
        CDynamicIndexData<unsigned short> *this)
{
  const ResourceBinding_t<CRenderBufferBits> *m_hIndexBuffer; // eax
  const ResourceBinding_t<CRenderBufferBits> *v3; // eax
  IRenderDevice *v4; // eax

  m_hIndexBuffer = this->m_hIndexBuffer;
  if ( m_hIndexBuffer != nullptr )
  {
    this->m_pRenderContext->DestroyDynamicIndexBuffer(this: this->m_pRenderContext, a2: m_hIndexBuffer);
    _InterlockedExchangeAdd(&this->m_hIndexBuffer->m_nRefCount.m_value, 0xFFFFFFFF);
    this->m_hIndexBuffer = nullptr;
  }
  if ( *((int *)&this->CIndexData<unsigned short> + 6) < 0 )
  {
    v3 = this->m_hIndexBuffer;
    if ( v3 != nullptr )
    {
      _InterlockedExchangeAdd(&v3->m_nRefCount.m_value, 0xFFFFFFFF);
      v4 = this->m_pRenderContext->GetDevice(this: this->m_pRenderContext);
      v4->DestroyIndexBuffer(this: v4, a2: this->m_hIndexBuffer);
      *((_DWORD *)&this->CIndexData<unsigned short> + 6) &= ~0x80000000;
      this->m_hIndexBuffer = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411470
// Name: public: virtual void CGameUISystemSurface::DrawFontTexture(class IRenderContext __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemSurface::DrawFontTexture(
        CGameUISystemSurface *this,
        IRenderContext *pRenderContext,
        int textureId,
        int xPos,
        int yPos)
{
  const ResourceBinding_t<CTextureBits> *v5; // eax
  ITextureDictionary *v6; // eax
  int v7; // edi
  bool v8; // al
  GameUIVertex_t *v9; // ecx
  int v10; // edx
  int v11; // edx
  IRenderContext *m_pRenderContext; // edi
  int v13; // ebx
  bool v14; // al
  unsigned __int16 *v15; // edx
  BOOL v16; // ecx
  int v17; // eax
  const ResourceBinding_t<CRenderBufferBits> *m_hIndexBuffer; // ebx
  void (__thiscall *UnlockIndexBuffer)(IRenderContext *, const ResourceBinding_t<CRenderBufferBits> *, int, LockDesc_t *); // edx
  int v20; // [esp+1F4h] [ebp-6Ch] BYREF
  int v21; // [esp+1F8h] [ebp-68h] BYREF
  GameUIVertex_t *v22; // [esp+1FCh] [ebp-64h] BYREF
  float v23; // [esp+200h] [ebp-60h] BYREF
  CDynamicIndexData<unsigned short> v24; // [esp+204h] [ebp-5Ch] BYREF
  CDynamicVertexData<GameUIVertex_t> v25; // [esp+220h] [ebp-40h] BYREF

  v5 = g_pGameUISystemSurface->GetTextureHandle(this: g_pGameUISystemSurface, a2: textureId);
  pRenderContext->BindTexture(this: pRenderContext, a2: 0, a3: v5, a4: RENDER_PIXEL_SHADER);
  v6 = TextureDictionary();
  v6->GetTextureSize(this: v6, a2: textureId, a3: &v20, a4: &v21);
  CDynamicVertexData<GameUIVertex_t>::CDynamicVertexData<GameUIVertex_t>(
    this: &v25,
    pRenderContext,
    nVertexCount: 4,
    pDebugName: "gamelayer2",
    pBudgetGroup: "game_controls2");
  v7 = (2 * *((_DWORD *)&v25.CVertexData<GameUIVertex_t> + 12)) >> 1;
  v8 = v25.m_pRenderContext->LockVertexBuffer(
         this: v25.m_pRenderContext,
         a2: v25.m_hVertexBuffer,
         a3: 24 * v7,
         a4: (LockDesc_t *)&v22);
  v9 = v22;
  v23 = (float)xPos;
  v25.m_Scratch.m_vecPosition.x = (float)xPos;
  *(float *)&v22 = (float)yPos;
  v25.m_nVertexIncrement = v8;
  v25.m_Scratch.m_vecPosition.y = (float)yPos;
  v25.m_nMaxVertexCount = v7 * v25.m_nVertexIncrement;
  v25.m_nVertexCount = 0;
  v25.m_pMemory = v9;
  v25.m_Scratch.m_vecPosition.z = 0.0;
  v25.m_Scratch.m_color = (VertexColor_t)-1;
  v25.m_Scratch.m_vecTexCoord.x = 0.0;
  v25.m_Scratch.m_vecTexCoord.y = 0.0;
  GameUIVertex_t::operator=(this: v9, __that: &v25.m_Scratch);
  v10 = v25.m_nVertexIncrement + v25.m_nVertexCount;
  v25.m_nVertexCount += v25.m_nVertexIncrement;
  v25.m_Scratch.m_vecPosition.x = (float)(xPos + v20);
  LODWORD(v25.m_Scratch.m_vecPosition.y) = v22;
  v25.m_Scratch.m_vecPosition.z = 0.0;
  v25.m_Scratch.m_color = (VertexColor_t)-1;
  v25.m_Scratch.m_vecTexCoord.x = 1.0;
  v25.m_Scratch.m_vecTexCoord.y = 0.0;
  GameUIVertex_t::operator=(this: &v25.m_pMemory[v10], __that: &v25.m_Scratch);
  v25.m_Scratch.m_vecPosition.x = (float)(xPos + v20);
  v25.m_Scratch.m_vecPosition.y = (float)(yPos + v21);
  v25.m_nVertexCount += v25.m_nVertexIncrement;
  v25.m_Scratch.m_vecPosition.z = 0.0;
  v25.m_Scratch.m_color = (VertexColor_t)-1;
  v25.m_Scratch.m_vecTexCoord.x = 1.0;
  v25.m_Scratch.m_vecTexCoord.y = 1.0;
  GameUIVertex_t::operator=(this: &v25.m_pMemory[v25.m_nVertexCount], __that: &v25.m_Scratch);
  v11 = v25.m_nVertexIncrement + v25.m_nVertexCount;
  v25.m_Scratch.m_vecPosition.x = v23;
  v25.m_nVertexCount += v25.m_nVertexIncrement;
  v25.m_Scratch.m_vecPosition.y = (float)(yPos + v21);
  v25.m_Scratch.m_vecPosition.z = 0.0;
  v25.m_Scratch.m_vecTexCoord.x = 0.0;
  v25.m_Scratch.m_color = (VertexColor_t)-1;
  v25.m_Scratch.m_vecTexCoord.y = 1.0;
  GameUIVertex_t::operator=(this: &v25.m_pMemory[v11], __that: &v25.m_Scratch);
  v25.m_nVertexCount += v25.m_nVertexIncrement;
  v23 = *(float *)&v25.m_pMemory;
  v25.m_pRenderContext->UnlockVertexBuffer(
    this: v25.m_pRenderContext,
    a2: v25.m_hVertexBuffer,
    a3: 24 * v25.m_nVertexCount,
    a4: (LockDesc_t *)&v23);
  v25.m_pRenderContext->BindVertexBuffer(this: v25.m_pRenderContext, a2: 0, a3: v25.m_hVertexBuffer, a4: 0, a5: 24);
  CDynamicIndexData<unsigned short>::CDynamicIndexData<unsigned short>(
    this: &v24,
    pRenderContext,
    nIndexCount: 6,
    pDebugName: "gamelayer",
    pBudgetGroup: "game_controls");
  m_pRenderContext = v24.m_pRenderContext;
  v13 = (2 * *((_DWORD *)&v24.CIndexData<unsigned short> + 6)) >> 1;
  v14 = v24.m_pRenderContext->LockIndexBuffer(
          this: v24.m_pRenderContext,
          a2: v24.m_hIndexBuffer,
          a3: 2 * v13,
          a4: (LockDesc_t *)&v23);
  v15 = (unsigned __int16 *)LODWORD(v23);
  *(_WORD *)LODWORD(v23) = 0;
  v24.m_pMemory = v15;
  v23 = *(float *)&v15;
  v16 = v14;
  v17 = v13 * v16;
  m_hIndexBuffer = v24.m_hIndexBuffer;
  v24.m_nMaxIndexCount = v17;
  v15[v16] = 1;
  v15[2 * v16] = 2;
  v15[3 * v16] = 0;
  v15[4 * v16] = 2;
  v15[5 * v16] = 3;
  UnlockIndexBuffer = m_pRenderContext->UnlockIndexBuffer;
  v24.m_nIndexIncrement = v16;
  v24.m_nIndexCount = 6 * v16;
  UnlockIndexBuffer(this: m_pRenderContext, a2: m_hIndexBuffer, a3: 12 * v16, a4: (LockDesc_t *)&v23);
  m_pRenderContext->BindIndexBuffer(this: m_pRenderContext, a2: m_hIndexBuffer, a3: 0);
  pRenderContext->DrawIndexed(this: pRenderContext, a2: RENDER_PRIM_TRIANGLES, a3: 0, a4: 6, a5: 0);
  CDynamicIndexData<unsigned short>::~CDynamicIndexData<unsigned short>(this: &v24);
  CDynamicVertexData<GameUIVertex_t>::~CDynamicVertexData<GameUIVertex_t>(this: &v25);
}

//------------------------------------------------------------------------------
// Address: 0x00411890
// Name: public: virtual bool CGameUISystemSurface::AddCustomFontFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUISystemSurface::AddCustomFontFile(CGameUISystemSurface *this, const char *fontFileName)
{
  int m_Size; // ecx
  int v5; // eax
  CUtlSymbol *m_pMemory; // edx
  CUtlSymbol v7; // [esp+1Ch] [ebp-140h] BYREF
  unsigned int dwNumFontsRegistered; // [esp+20h] [ebp-13Ch] BYREF
  CUtlBuffer buf; // [esp+24h] [ebp-138h] BYREF
  char fullPath[264]; // [esp+54h] [ebp-108h] BYREF

  if ( g_pFullFileSystem->GetLocalPath(this: g_pFullFileSystem, a2: fontFileName, a3: &fullPath[4], a4: 260) == nullptr )
  {
    _Warning(a1: "Couldn't find custom font file '%s'\n", fontFileName);
    return 0;
  }
  _V_strlower(start: &fullPath[4]);
  CUtlSymbol::CUtlSymbol(this: &v7, pStr: &fullPath[4]);
  m_Size = this->m_CustomFontFileNames.m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_CustomFontFileNames.m_Memory.m_pMemory;
    do
    {
      if ( m_pMemory->m_Id == v7.m_Id )
        break;
      ++v5;
      ++m_pMemory;
    }
    while ( v5 < m_Size );
    if ( v5 < 0 )
      goto LABEL_9;
  }
  if ( v5 >= m_Size )
  {
LABEL_9:
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&dwNumFontsRegistered + 1, pStr: &fullPath[4]);
    CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
      this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&this->m_CustomFontFileNames,
      elem: this->m_CustomFontFileNames.m_Size,
      src: (wchar_t *)&dwNumFontsRegistered + 1);
  }
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 0);
  if ( !g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: fontFileName,
          a3: nullptr,
          a4: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
          a5: 0,
          a6: 0,
          a7: nullptr) )
  {
    _Msg(a1: "Failed to load custom font file '%s'\n", fontFileName);
    if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
    return 0;
  }
  if ( ValveFont::DecodeFont(buffer: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount) != 0 )
  {
    buf.m_Memory.m_pMemory = nullptr;
    if ( AddFontMemResourceEx(
           pFileView: (PVOID)buf.m_Memory.m_nAllocationCount,
           cjSize: *(DWORD *)&buf.m_Error,
           pvResrved: nullptr,
           pNumFonts: (DWORD *)&buf) != nullptr )
    {
      if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
      return 1;
    }
    else
    {
      _Msg(a1: "Failed to register custom font file '%s'\n", fontFileName);
      if ( buf.m_Get < 0 || buf.m_Memory.m_nAllocationCount == 0 )
        return 0;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
      return 0;
    }
  }
  else
  {
    _Msg(a1: "Failed to parse custom font file '%s'\n", fontFileName);
    if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411AA0
// Name: public: virtual bool CGameUISystemSurface::AddBitmapFontFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUISystemSurface::AddBitmapFontFile(CGameUISystemSurface *this, const char *fontFileName)
{
  int m_Size; // ecx
  int v5; // eax
  CUtlSymbol *m_pMemory; // edx
  CUtlSymbol v7; // [esp+Ah] [ebp-10Ah] BYREF
  char path[260]; // [esp+Ch] [ebp-108h] BYREF

  if ( g_pFullFileSystem->GetDVDMode(this: g_pFullFileSystem) == DVDMODE_STRICT
    || g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: fontFileName, a3: nullptr) )
  {
    V_strncpy(pDest: &path[4], pSrc: fontFileName, maxLen: 260);
    _V_strlower(start: &path[4]);
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)path, pStr: &path[4]);
    m_Size = this->m_BitmapFontFileNames.m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_BitmapFontFileNames.m_Memory.m_pMemory;
      do
      {
        if ( m_pMemory->m_Id == *(_WORD *)path )
          break;
        ++v5;
        ++m_pMemory;
      }
      while ( v5 < m_Size );
      if ( v5 < 0 )
        goto LABEL_10;
    }
    if ( v5 >= m_Size )
    {
LABEL_10:
      CUtlSymbol::CUtlSymbol(this: &v7, pStr: &path[4]);
      CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
        this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&this->m_BitmapFontFileNames,
        elem: this->m_BitmapFontFileNames.m_Size,
        src: &v7.m_Id);
      g_pFullFileSystem->GetLocalCopy(this: g_pFullFileSystem, a2: &path[4]);
    }
    return 1;
  }
  else
  {
    _Msg(a1: "Couldn't find bitmap font file '%s'\n", fontFileName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411B90
// Name: public: void CUtlDict<int,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,int>::RemoveAll(CUtlDict<int,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00411BE0
// Name: public: virtual void CGameUISystemSurface::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemSurface::Shutdown(CGameUISystemSurface *this)
{
  ITextureDictionary *v2; // eax

  v2 = TextureDictionary();
  v2->DestroyAllTextures(this: v2);
  this->m_CustomFontFileNames.m_Size = 0;
  this->m_BitmapFontFileNames.m_Size = 0;
  CUtlDict<int,int>::RemoveAll(this: &this->m_BitmapFontFileMapping);
}

//------------------------------------------------------------------------------
// Address: 0x00411C10
// Name: public: virtual char const __near * CGameUISystemSurface::GetBitmapFontName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUISystemSurface::GetBitmapFontName(CGameUISystemSurface *this, const char *pName)
{
  int v3; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pName != nullptr
    && (search.key = pName,
        (v3 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: &this->m_BitmapFontFileMapping.m_Elements.m_Tree,
                &search)) != -1) )
  {
    return CUtlSymbol::String(this: &this->m_BitmapFontFileNames.m_Memory.m_pMemory[this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem]);
  }
  else
  {
    return defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411CD0
// Name: public: CGameUISystemSurface::CGameUISystemSurface(void)
// Source: json
//------------------------------------------------------------------------------
CGameUISystemSurface *__thiscall CGameUISystemSurface::CGameUISystemSurface(CGameUISystemSurface *this)
{
  bool v2; // zf

  this->__vftable = (CGameUISystemSurface_vtbl *)&CGameUISystemSurface::`vftable';
  this->m_CustomFontFileNames.m_Memory.m_pMemory = nullptr;
  this->m_CustomFontFileNames.m_Memory.m_nAllocationCount = 0;
  this->m_CustomFontFileNames.m_Memory.m_nGrowSize = 0;
  this->m_CustomFontFileNames.m_Size = 0;
  this->m_CustomFontFileNames.m_pElements = nullptr;
  this->m_BitmapFontFileNames.m_Memory.m_pMemory = nullptr;
  this->m_BitmapFontFileNames.m_Memory.m_nAllocationCount = 0;
  this->m_BitmapFontFileNames.m_Memory.m_nGrowSize = 0;
  this->m_BitmapFontFileNames.m_Size = 0;
  this->m_BitmapFontFileNames.m_pElements = nullptr;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_Root = -1;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_NumElements = 0;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_LastAlloc.index = -1;
  v2 = this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr;
  this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_pElements = this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( v2 )
    this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_bIsInitialized = false;
  CFontTextureCache::SetPrefix(this: &g_FontTextureCache, pTexturePagePrefix: "ingameui");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00411D40
// Name: public: virtual void CGameUISystemSurface::SetBitmapFontName(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemSurface::SetBitmapFontName(
        CGameUISystemSurface *this,
        const char *pName,
        const char *pFontFilename)
{
  int m_Size; // ecx
  int v5; // ebx
  CUtlSymbol *i; // eax
  int v7; // esi
  CUtlSymbol v8; // [esp+8h] [ebp-118h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-114h] BYREF
  CUtlMap<char const *,int,int>::Node_t insert; // [esp+14h] [ebp-10Ch] BYREF
  char v11[260]; // [esp+1Ch] [ebp-104h] BYREF

  V_strncpy(pDest: v11, pSrc: pFontFilename, maxLen: 260);
  _V_strlower(start: v11);
  CUtlSymbol::CUtlSymbol(this: &v8, pStr: v11);
  m_Size = this->m_BitmapFontFileNames.m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_BitmapFontFileNames.m_Memory.m_pMemory; i->m_Id != v8.m_Id; ++i )
    {
      if ( ++v5 >= m_Size )
        return;
    }
    if ( pName != nullptr )
    {
      search.key = pName;
      v7 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
             this: &this->m_BitmapFontFileMapping.m_Elements.m_Tree,
             &search);
    }
    else
    {
      v7 = -1;
    }
    if ( v7 < 0
      || v7 >= this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount
      || v7 > this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_LastAlloc.index
      || CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LeftChild(
           this: &this->m_BitmapFontFileMapping.m_Elements.m_Tree,
           i: v7) == v7 )
    {
      insert.key = MemAlloc_StrDup(pString: pName);
      v7 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Insert(
             this: &this->m_BitmapFontFileMapping.m_Elements.m_Tree,
             &insert);
    }
    this->m_BitmapFontFileMapping.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem = v5;
  }
}
