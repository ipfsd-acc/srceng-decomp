// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmatpaintmaps.cpp
// Functions: 16
// ============================================================

#include "materialsystem\cmatpaintmaps.h"

//------------------------------------------------------------------------------
// Address: 0x1003BD40
// Name: public: bool CMatPaintmaps::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMatPaintmaps::IsEnabled(CMatPaintmaps *this)
{
  return this->m_pDataManager != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003BD50
// Name: public: void CMatPaintmaps::RegisterPaintmapDataManager(class IPaintmapDataManager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::RegisterPaintmapDataManager(CMaterial *this, int id)
{
  this->m_iEnumerationID = id;
}

//------------------------------------------------------------------------------
// Address: 0x1003BD80
// Name: private: void CMatPaintmaps::FillRect(int,struct Rect_t restrict __near *,unsigned char restrict __near *)restrict
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::FillRect(CMatPaintmaps *this, int paintmap, Rect_t *pRect, unsigned __int8 *pPaintData)
{
  int x; // edx
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  unsigned __int8 *v9; // eax
  unsigned __int8 v10; // cl
  double v11; // xmm0_8
  Color *v12; // eax
  int v13; // edi
  int v14; // edx
  int v15; // ecx
  unsigned __int8 m_Size; // al
  float v17; // xmm0_4
  bool v18; // cf
  unsigned int m_RMask; // eax
  int v20; // eax
  __int16 m_BShift; // cx
  unsigned int v22; // eax
  unsigned int v23; // edx
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned __int64 v26; // kr00_8
  unsigned __int64 v27; // rax
  __int16 v28; // cx
  int v29; // ebx
  int v30; // edi
  __int64 v31; // rax
  __int64 v32; // rax
  unsigned __int64 v33; // rax
  int v34; // ebx
  int v35; // edi
  bool v36; // zf
  __int64 v37; // [esp+Ch] [ebp-34h]
  int v38; // [esp+14h] [ebp-2Ch]
  unsigned __int8 *v39; // [esp+20h] [ebp-20h]
  int v40; // [esp+24h] [ebp-1Ch]
  int y; // [esp+28h] [ebp-18h]
  int v42; // [esp+2Ch] [ebp-14h]
  int width; // [esp+34h] [ebp-Ch] BYREF
  int s; // [esp+38h] [ebp-8h]
  int height; // [esp+3Ch] [ebp-4h] BYREF
  unsigned __int8 *paintmapa; // [esp+48h] [ebp+8h]
  Rect_t *pRecta; // [esp+4Ch] [ebp+Ch]

  this->m_pDataManager->GetPaintmapSize(this: this->m_pDataManager, a2: paintmap, a3: &width, a4: &height);
  x = pRect->x;
  v38 = pRect->x;
  if ( pRect->x < 0
    || (v6 = pRect->y) < 0
    || x >= width
    || v6 >= height
    || (v7 = pRect->width, v42 = v7, v7 < 0)
    || (v8 = pRect->height) < 0
    || v7 > width
    || v8 > height
    || v7 + x > width
    || v8 + v6 > height )
  {
    DevWarning(a1: "Corrupted paint rect\n");
  }
  else if ( v8 > 0 )
  {
    y = pRect->y;
    v40 = pRect->height;
    do
    {
      v9 = &this->m_PaintmapPixelWriter.m_pBase[x * this->m_PaintmapPixelWriter.m_Size
                                              + v6 * this->m_PaintmapPixelWriter.m_BytesPerRow];
      s = 0;
      this->m_PaintmapPixelWriter.m_pBits = v9;
      if ( v7 > 0 )
      {
        v39 = &pPaintData[width * v6 + x];
        pRecta = (Rect_t *)this->m_PaintmapPixelWriter.m_Size;
        paintmapa = this->m_PaintmapPixelWriter.m_pBits;
        do
        {
          v10 = v39[s];
          v11 = (double)(v10 & 0x1F) * 0.03225806451612903;
          v12 = &g_PaintColors[v10 >> 5];
          if ( v11 >= 0.0 )
          {
            if ( v11 > 1.0 )
              v11 = 1.0;
          }
          else
          {
            v11 = 0.0;
          }
          v13 = v12->_color[2];
          v14 = v12->_color[1];
          v15 = v12->_color[0];
          m_Size = this->m_PaintmapPixelWriter.m_Size;
          v17 = (float)v11 * 255.0;
          if ( m_Size != 0 )
          {
            v18 = m_Size < 5u;
            m_RMask = this->m_PaintmapPixelWriter.m_RMask;
            if ( v18 )
            {
              v20 = (v15 & m_RMask) << LOBYTE(this->m_PaintmapPixelWriter.m_RShift);
              m_BShift = this->m_PaintmapPixelWriter.m_BShift;
              v22 = ((v14 & this->m_PaintmapPixelWriter.m_GMask) << LOBYTE(this->m_PaintmapPixelWriter.m_GShift)) | v20;
              v23 = v13 & this->m_PaintmapPixelWriter.m_BMask;
              if ( m_BShift <= 0 )
                v24 = v23 >> -(char)m_BShift;
              else
                v24 = v23 << m_BShift;
              v25 = v24
                  | (((int)v17 & this->m_PaintmapPixelWriter.m_AMask) << LOBYTE(this->m_PaintmapPixelWriter.m_AShift))
                  | v22;
              switch ( (unsigned int)pRecta )
              {
                case 1u:
                  *paintmapa = v25;
                  break;
                case 2u:
                  *(_WORD *)paintmapa = v25;
                  break;
                case 3u:
                  *(_WORD *)paintmapa = v25;
                  paintmapa[2] = BYTE2(v25);
                  break;
                case 4u:
                  *(_DWORD *)paintmapa = v25;
                  break;
                default:
                  break;
              }
            }
            else
            {
              v26 = (unsigned __int64)(v15 & m_RMask) << this->m_PaintmapPixelWriter.m_RShift;
              v27 = (unsigned __int64)(v14 & this->m_PaintmapPixelWriter.m_GMask) << this->m_PaintmapPixelWriter.m_GShift;
              v28 = this->m_PaintmapPixelWriter.m_BShift;
              v29 = v27 | v26;
              LODWORD(v31) = v13 & this->m_PaintmapPixelWriter.m_BMask;
              v30 = HIDWORD(v27) | HIDWORD(v26);
              HIDWORD(v31) = 0;
              if ( v28 <= 0 )
                v32 = v31 >> -(char)v28;
              else
                v32 = v31 << v28;
              v37 = v32;
              v33 = (unsigned __int64)((int)v17 & this->m_PaintmapPixelWriter.m_AMask) << this->m_PaintmapPixelWriter.m_AShift;
              v34 = v37 | v33 | v29;
              v35 = HIDWORD(v37) | HIDWORD(v33) | v30;
              if ( pRecta == (Rect_t *)6 )
              {
                *(_DWORD *)paintmapa = v34;
                *((_WORD *)paintmapa + 2) = v35;
              }
              else if ( pRecta == (Rect_t *)8 )
              {
                *(_DWORD *)paintmapa = v34;
                *((_DWORD *)paintmapa + 1) = v35;
              }
            }
          }
          paintmapa = &paintmapa[(_DWORD)pRecta];
          ++s;
        }
        while ( s < v42 );
        x = v38;
        v7 = v42;
        this->m_PaintmapPixelWriter.m_pBits = paintmapa;
        v6 = y;
      }
      ++v6;
      v36 = v40-- == 1;
      y = v6;
    }
    while ( !v36 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C070
// Name: public: int CMatPaintmaps::GetPaintmapPageTextureHandle(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatPaintmaps::GetPaintmapPageTextureHandle(CMatPaintmaps *this, int paintmap)
{
  if ( paintmap < 0 || paintmap >= this->m_PaintmapTextureHandles.m_Size )
    return 0;
  else
    return this->m_PaintmapTextureHandles.m_Memory.m_pMemory[paintmap];
}

//------------------------------------------------------------------------------
// Address: 0x1003C090
// Name: private: void CMatPaintmaps::InitPaintmapBits(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::InitPaintmapBits(CMatPaintmaps *this, int paintmap)
{
  int v2; // edi
  CPixelWriter writer; // [esp+8h] [ebp-28h] BYREF
  int height; // [esp+2Ch] [ebp-4h] BYREF

  v2 = paintmap;
  this->m_pDataManager->GetPaintmapSize(this: this->m_pDataManager, a2: paintmap, a3: &paintmap, a4: &height);
  g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: this->m_PaintmapTextureHandles.m_Memory.m_pMemory[v2]);
  if ( g_pShaderAPI->TexLock(this: g_pShaderAPI, a2: 0, a3: 0, a4: 0, a5: 0, a6: paintmap, a7: height, a8: &writer) )
  {
    memset(dst: writer.m_pBase, value: 0, count: height * paintmap * writer.m_Size);
    g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C130
// Name: private: bool CMatPaintmaps::LockPaintmap(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatPaintmaps::LockPaintmap(CMatPaintmaps *this, int paintmap)
{
  bool result; // al
  int width; // [esp+8h] [ebp-8h] BYREF
  int height; // [esp+Ch] [ebp-4h] BYREF

  if ( this->m_nLockedPaintmap != -1 )
    g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
  g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: this->m_PaintmapTextureHandles.m_Memory.m_pMemory[paintmap]);
  this->m_pDataManager->GetPaintmapSize(this: this->m_pDataManager, a2: paintmap, a3: &width, a4: &height);
  result = g_pShaderAPI->TexLock(
             this: g_pShaderAPI,
             a2: 0,
             a3: 0,
             a4: 0,
             a5: 0,
             a6: width,
             a7: height,
             a8: &this->m_PaintmapPixelWriter);
  if ( result )
  {
    this->m_nLockedPaintmap = paintmap;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003C1C0
// Name: public: void CMatPaintmaps::ReleasePaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::ReleasePaintmaps(CMatPaintmaps *this)
{
  int v2; // esi

  v2 = 0;
  if ( this->m_PaintmapTextureHandles.m_Size <= 0 )
  {
    this->m_PaintmapTextureHandles.m_Size = 0;
  }
  else
  {
    do
      g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_PaintmapTextureHandles.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_PaintmapTextureHandles.m_Size );
    this->m_PaintmapTextureHandles.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C200
// Name: public: void CMatPaintmaps::CleanupPaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::CleanupPaintmaps(CMatPaintmaps *this)
{
  int i; // edi

  for ( i = 0; i < this->m_PaintmapTextureHandles.m_Size; ++i )
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_PaintmapTextureHandles.m_Memory.m_pMemory[i]);
  this->m_PaintmapTextureHandles.m_Size = 0;
  if ( this->m_pDataManager != nullptr )
    this->m_pDataManager->DestroyPaintmapsData(this: this->m_pDataManager);
}

//------------------------------------------------------------------------------
// Address: 0x1003C250
// Name: public: virtual void CMatPaintmaps::UpdatePaintmap(int,unsigned char __near *,int,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::UpdatePaintmap(
        CMatPaintmaps *this,
        int paintmap,
        unsigned __int8 *pPaintData,
        int numRects,
        Rect_t *pRects)
{
  CMatPaintmaps *v5; // ebx
  int (__thiscall *v6)(char *); // edx
  int v7; // edi
  int v8; // esi
  int v9; // edx
  int v10; // edi
  int v11; // ebx
  int *p_y; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // ecx
  int v17; // ebx
  IPaintmapDataManager *m_pDataManager; // ecx
  Rect_t *v19; // esi
  int v20; // edi
  Rect_t rect; // [esp+Ch] [ebp-20h] BYREF
  CMatPaintmaps *v22; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int minY; // [esp+24h] [ebp-8h]
  int minX; // [esp+28h] [ebp-4h]

  v5 = this;
  v6 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 2247) + 548);
  v22 = this;
  v7 = paintmap;
  if ( paintmap >= v6(a1: (char *)this - 8988) || (v8 = 0, paintmap < 0) )
  {
    _Error(a1: "CMatPaintmaps::UpdatePaintmap paintmap=%d out of range\n", paintmap);
  }
  else
  {
    if ( pRects != nullptr )
    {
      v9 = 512;
      v10 = 512;
      v11 = 0;
      minX = 512;
      minY = 512;
      if ( numRects > 0 )
      {
        p_y = &pRects->y;
        for ( i = numRects; i != 0; --i )
        {
          v13 = *(p_y - 1);
          if ( v13 < v9 )
            minX = *(p_y - 1);
          v14 = *p_y;
          if ( *p_y < v10 )
            minY = *p_y;
          v15 = p_y[1] + v13;
          v10 = minY;
          if ( v15 > v8 )
            v8 = v15;
          v16 = v14 + p_y[2];
          v9 = minX;
          if ( v16 > v11 )
            v11 = v16;
          p_y += 4;
        }
      }
      v17 = v11 - v10;
      rect.y = v10;
      v7 = paintmap;
      rect.height = v17;
      v5 = v22;
      rect.x = v9;
      rect.width = v8 - v9;
    }
    else
    {
      m_pDataManager = v5->m_pDataManager;
      rect.y = 0;
      rect.x = 0;
      m_pDataManager->GetPaintmapSize(this: m_pDataManager, a2: paintmap, a3: &rect.width, a4: &rect.height);
    }
    if ( CMatPaintmaps::LockPaintmap(this: v5, paintmap: v7) )
    {
      v19 = pRects;
      if ( pRects != nullptr )
      {
        v20 = numRects;
        if ( numRects > 0 )
        {
          do
          {
            CMatPaintmaps::FillRect(this: v22, paintmap, pRect: v19++, pPaintData);
            --v20;
          }
          while ( v20 != 0 );
        }
      }
      else
      {
        CMatPaintmaps::FillRect(this: v5, paintmap: v7, pRect: &rect, pPaintData);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C400
// Name: public: CMatPaintmaps::CMatPaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
CMatPaintmaps *__thiscall CMatPaintmaps::CMatPaintmaps(CMatPaintmaps *this)
{
  this->__vftable = (CMatPaintmaps_vtbl *)&CMatPaintmaps::`vftable';
  this->m_PaintmapTextureHandles.m_Memory.m_pMemory = nullptr;
  this->m_PaintmapTextureHandles.m_Memory.m_nAllocationCount = 0;
  this->m_PaintmapTextureHandles.m_Memory.m_nGrowSize = 0;
  this->m_PaintmapTextureHandles.m_Size = 0;
  this->m_PaintmapTextureHandles.m_pElements = nullptr;
  this->m_pDataManager = nullptr;
  this->m_nUpdatingPaintmapsStackDepth = 0;
  this->m_nLockedPaintmap = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003C430
// Name: public: void CMatPaintmaps::BeginPaintTextureAllocation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::BeginPaintTextureAllocation(CMatPaintmaps *this, int iPaintmapCount)
{
  CMatPaintmaps::CleanupPaintmaps(this);
  this->m_pDataManager->BeginPaintmapsDataAllocation(this: this->m_pDataManager, a2: iPaintmapCount);
}

//------------------------------------------------------------------------------
// Address: 0x1003C4E0
// Name: public: virtual void CMatPaintmaps::BeginUpdatePaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::BeginUpdatePaintmaps(CMatPaintmaps *this)
{
  CMatPaintmaps *v2; // ecx
  CMatCallQueue *v3; // eax

  v2 = (CMatPaintmaps *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( v2 == nullptr )
    v2 = this + 1;
  v3 = (CMatCallQueue *)((int (__thiscall *)(CMatPaintmaps *))v2->__vftable[76].BeginUpdatePaintmaps)(a1: v2);
  if ( v3 != nullptr )
    CMatCallQueue::QueueCall<CMatPaintmaps *,CMatPaintmaps,void>(
      this: v3,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall CMatPaintmaps::`vcall'{0,{flat}});
  else
    ++this->m_nUpdatingPaintmapsStackDepth;
}

//------------------------------------------------------------------------------
// Address: 0x1003C560
// Name: public: virtual void CMatPaintmaps::EndUpdatePaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::EndUpdatePaintmaps(CMatPaintmaps *this)
{
  CMatPaintmaps *v2; // ecx
  CMatCallQueue *v3; // eax

  v2 = (CMatPaintmaps *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( v2 == nullptr )
    v2 = this + 1;
  v3 = (CMatCallQueue *)((int (__thiscall *)(CMatPaintmaps *))v2->__vftable[76].BeginUpdatePaintmaps)(a1: v2);
  if ( v3 != nullptr )
  {
    CMatCallQueue::QueueCall<CMatPaintmaps *,CMatPaintmaps,void>(
      this: v3,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall CMatPaintmaps::`vcall'{8,{flat}});
  }
  else if ( --this->m_nUpdatingPaintmapsStackDepth <= 0 && this->m_nLockedPaintmap != -1 )
  {
    g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
    this->m_nLockedPaintmap = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C600
// Name: private: void CMatPaintmaps::AllocatePaintmapTexture(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::AllocatePaintmapTexture(CMatPaintmaps *this, int paintmap, int iWidth, int iHeight)
{
  int *v5; // esi
  char debugName[260]; // [esp+Ch] [ebp-108h] BYREF
  int flags; // [esp+110h] [ebp-4h]

  if ( g_pHWConfig->PreferDynamicTextures(this: g_pHWConfig)
    && mat_dynamicPaintmaps.m_pParent != nullptr
    && mat_dynamicPaintmaps.m_pParent->m_Value.m_nValue != 0 )
  {
    flags = 16;
  }
  else
  {
    flags = 4;
  }
  if ( this->m_PaintmapTextureHandles.m_Size < paintmap + 1 )
    CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_PaintmapTextureHandles,
      elem: this->m_PaintmapTextureHandles.m_Size,
      num: paintmap + 1 - this->m_PaintmapTextureHandles.m_Size);
  V_snprintf(pDest: debugName, maxLen: 256, pFormat: "[paintmap %d]", paintmap);
  v5 = &this->m_PaintmapTextureHandles.m_Memory.m_pMemory[paintmap];
  *v5 = g_pShaderAPI->CreateTexture(
          this: g_pShaderAPI,
          a2: iWidth,
          a3: iHeight,
          a4: 1,
          a5: IMAGE_FORMAT_RGBA8888,
          a6: 1,
          a7: 1,
          a8: flags,
          a9: debugName,
          a10: "Lightmaps");
  g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: this->m_PaintmapTextureHandles.m_Memory.m_pMemory[paintmap]);
  g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
  g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
  CMatPaintmaps::InitPaintmapBits(this, paintmap);
}

//------------------------------------------------------------------------------
// Address: 0x1003C700
// Name: public: void CMatPaintmaps::AllocatePaintmap(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::AllocatePaintmap(CMatPaintmaps *this, int paintmap, int iWidth, int iHeight)
{
  if ( this->m_pDataManager != nullptr )
  {
    this->m_pDataManager->AllocatePaintmapData(this: this->m_pDataManager, a2: paintmap, a3: iWidth, a4: iHeight);
    CMatPaintmaps::AllocatePaintmapTexture(this, paintmap, iWidth, iHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C740
// Name: public: void CMatPaintmaps::RestorePaintmaps(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatPaintmaps::RestorePaintmaps(
        CMatPaintmaps *this@<ecx>,
        const char *a2@<ebx>,
        char *a3@<edi>,
        int nNumLightmaps)
{
  int v4; // esi
  CUtlMemory<S3RGBA,int> *p_m_PaintmapTextureHandles; // edi
  IHardwareConfigInternal_vtbl *v6; // eax
  S3RGBA *m_pMemory; // eax
  int v8; // ebx
  S3RGBA *v9; // ecx
  int m_nAllocationCount; // edx
  S3RGBA *v11; // edx
  int v12; // eax
  S3RGBA *v13; // ebx
  char pDest[256]; // [esp+4h] [ebp-124h] BYREF
  int height; // [esp+104h] [ebp-24h] BYREF
  int v18; // [esp+108h] [ebp-20h]
  int v19; // [esp+10Ch] [ebp-1Ch]
  int v20; // [esp+110h] [ebp-18h]
  int width; // [esp+114h] [ebp-14h] BYREF
  int v22; // [esp+118h] [ebp-10h]
  S3RGBA *v23; // [esp+11Ch] [ebp-Ch]
  int v24; // [esp+120h] [ebp-8h]
  CMatPaintmaps *v25; // [esp+124h] [ebp-4h]

  v4 = 0;
  v25 = this;
  if ( nNumLightmaps > 0 )
  {
    p_m_PaintmapTextureHandles = (CUtlMemory<S3RGBA,int> *)&this->m_PaintmapTextureHandles;
    do
    {
      ((void (__thiscall *)(IPaintmapDataManager *, int, int *, int *, char *, const char *))this->m_pDataManager->GetPaintmapSize)(
        a1: this->m_pDataManager,
        a2: v4,
        a3: &width,
        a4: &height,
        a5: a3,
        a6: a2);
      v22 = height;
      v6 = g_pHWConfig->__vftable;
      v20 = width;
      if ( v6->PreferDynamicTextures(this: g_pHWConfig)
        && mat_dynamicPaintmaps.m_pParent != nullptr
        && mat_dynamicPaintmaps.m_pParent->m_Value.m_nValue != 0 )
      {
        v24 = 16;
      }
      else
      {
        v24 = 4;
      }
      m_pMemory = p_m_PaintmapTextureHandles[1].m_pMemory;
      v18 = v4 + 1;
      if ( (int)m_pMemory < v4 + 1 )
      {
        v8 = v4 + 1 - (_DWORD)m_pMemory;
        v9 = m_pMemory;
        v23 = m_pMemory;
        if ( v8 != 0 )
        {
          m_nAllocationCount = p_m_PaintmapTextureHandles->m_nAllocationCount;
          v19 = v4 + 1;
          if ( v4 + 1 > m_nAllocationCount )
          {
            CUtlMemory<IMaterialVar *,int>::Grow(this: p_m_PaintmapTextureHandles, num: v4 + 1 - m_nAllocationCount);
            v9 = v23;
          }
          p_m_PaintmapTextureHandles[1].m_pMemory = (S3RGBA *)((char *)p_m_PaintmapTextureHandles[1].m_pMemory + v8);
          v11 = p_m_PaintmapTextureHandles->m_pMemory;
          v12 = (char *)p_m_PaintmapTextureHandles[1].m_pMemory - (char *)v9 - v8;
          p_m_PaintmapTextureHandles[1].m_nAllocationCount = (int)p_m_PaintmapTextureHandles->m_pMemory;
          if ( v12 > 0 && v8 > 0 )
            _V_memmove(dest: &v11[v19], src: &v11[(_DWORD)v9], count: 4 * v12);
        }
      }
      V_snprintf(pDest, maxLen: 256, pFormat: "[paintmap %d]", v4);
      a2 = "Lightmaps";
      a3 = pDest;
      v13 = &p_m_PaintmapTextureHandles->m_pMemory[v4];
      *v13 = (S3RGBA)((int (__thiscall *)(IShaderAPI *, int, int, int, _DWORD, int, int, int))g_pShaderAPI->CreateTexture)(
                       a1: g_pShaderAPI,
                       a2: v20,
                       a3: v22,
                       a4: 1,
                       a5: 0,
                       a6: 1,
                       a7: 1,
                       a8: v24);
      g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: *(_DWORD *)&p_m_PaintmapTextureHandles->m_pMemory[v4]);
      g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
      g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
      CMatPaintmaps::InitPaintmapBits(this: v25, paintmap: v4);
      v4 = v18;
      this = v25;
    }
    while ( v18 < nNumLightmaps );
  }
  this->m_pDataManager->OnRestorePaintmaps(this: this->m_pDataManager);
}
